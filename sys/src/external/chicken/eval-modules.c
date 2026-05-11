/* Generated from eval-modules.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: eval-modules.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file eval-modules.c
   unit: eval-modules
   uses: eval
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[101];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,6),40,97,52,54,54,41,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,6),40,97,52,54,48,41,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,6),40,97,52,57,52,41,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,6),40,97,52,56,56,41,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,6),40,97,53,49,54,41,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,6),40,97,53,50,56,41,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,6),40,97,53,50,50,41,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,6),40,97,53,53,54,41,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,6),40,97,53,53,48,41,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,6),40,97,53,56,52,41,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,6),40,97,53,55,56,41,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,6),40,97,54,49,50,41,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,6),40,97,54,48,54,41,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,6),40,97,54,52,48,41,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,6),40,97,54,51,52,41,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,6),40,97,54,54,50,41,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,6),40,97,54,55,52,41,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,6),40,97,54,54,56,41,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,6),40,97,55,48,50,41,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,6),40,97,54,57,54,41,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,6),40,97,55,51,48,41,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,6),40,97,55,50,52,41,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,6),40,97,55,53,56,41,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,6),40,97,55,53,50,41,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,6),40,97,55,56,54,41,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,6),40,97,55,56,48,41,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,6),40,97,56,48,56,41,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,6),40,97,56,50,48,41,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,6),40,97,56,49,52,41,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,6),40,97,56,52,56,41,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,6),40,97,56,52,50,41,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,6),40,97,56,55,54,41,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,6),40,97,56,55,48,41,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,6),40,97,57,48,52,41,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,6),40,97,56,57,56,41,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,6),40,97,57,51,50,41,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,6),40,97,57,50,54,41,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,6),40,97,57,54,48,41,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,6),40,97,57,53,52,41,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,6),40,97,57,56,56,41,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,6),40,97,57,56,50,41,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,7),40,97,49,48,49,54,41,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,7),40,97,49,48,49,48,41,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,7),40,97,49,48,52,52,41,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,7),40,97,49,48,51,56,41,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,7),40,97,49,48,55,50,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,7),40,97,49,48,54,54,41,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,7),40,97,49,49,48,48,41,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,7),40,97,49,48,57,52,41,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,7),40,97,49,49,50,56,41,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,7),40,97,49,49,50,50,41,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,7),40,97,49,49,53,54,41,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,7),40,97,49,49,53,48,41,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,7),40,97,49,49,56,52,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,7),40,97,49,49,55,56,41,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,7),40,97,49,50,49,50,41,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,7),40,97,49,50,48,54,41,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,7),40,97,49,50,52,48,41,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,7),40,97,49,50,51,52,41,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,7),40,97,49,50,54,56,41,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,7),40,97,49,50,54,50,41,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,7),40,97,49,50,57,54,41,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,7),40,97,49,50,57,48,41,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,7),40,97,49,51,50,52,41,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,7),40,97,49,51,49,56,41,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,7),40,97,49,51,53,50,41,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,7),40,97,49,51,52,54,41,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,7),40,97,49,51,56,48,41,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,7),40,97,49,51,55,52,41,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,7),40,97,49,52,48,56,41,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,7),40,97,49,52,48,50,41,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,7),40,97,49,52,51,54,41,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,7),40,97,49,52,51,48,41,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,7),40,97,49,52,54,52,41,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,7),40,97,49,52,53,56,41,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,33),40,35,35,115,121,115,35,105,109,112,111,114,116,45,108,105,98,114,97,114,121,45,104,111,111,107,32,109,110,97,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1011)
static void C_ccall f_1011(C_word c,C_word *av) C_noret;
C_noret_decl(f_1017)
static void C_ccall f_1017(C_word c,C_word *av) C_noret;
C_noret_decl(f_1039)
static void C_ccall f_1039(C_word c,C_word *av) C_noret;
C_noret_decl(f_1045)
static void C_ccall f_1045(C_word c,C_word *av) C_noret;
C_noret_decl(f_1067)
static void C_ccall f_1067(C_word c,C_word *av) C_noret;
C_noret_decl(f_1073)
static void C_ccall f_1073(C_word c,C_word *av) C_noret;
C_noret_decl(f_1095)
static void C_ccall f_1095(C_word c,C_word *av) C_noret;
C_noret_decl(f_1101)
static void C_ccall f_1101(C_word c,C_word *av) C_noret;
C_noret_decl(f_1123)
static void C_ccall f_1123(C_word c,C_word *av) C_noret;
C_noret_decl(f_1129)
static void C_ccall f_1129(C_word c,C_word *av) C_noret;
C_noret_decl(f_1151)
static void C_ccall f_1151(C_word c,C_word *av) C_noret;
C_noret_decl(f_1157)
static void C_ccall f_1157(C_word c,C_word *av) C_noret;
C_noret_decl(f_1179)
static void C_ccall f_1179(C_word c,C_word *av) C_noret;
C_noret_decl(f_1185)
static void C_ccall f_1185(C_word c,C_word *av) C_noret;
C_noret_decl(f_1207)
static void C_ccall f_1207(C_word c,C_word *av) C_noret;
C_noret_decl(f_1213)
static void C_ccall f_1213(C_word c,C_word *av) C_noret;
C_noret_decl(f_1235)
static void C_ccall f_1235(C_word c,C_word *av) C_noret;
C_noret_decl(f_1241)
static void C_ccall f_1241(C_word c,C_word *av) C_noret;
C_noret_decl(f_1263)
static void C_ccall f_1263(C_word c,C_word *av) C_noret;
C_noret_decl(f_1269)
static void C_ccall f_1269(C_word c,C_word *av) C_noret;
C_noret_decl(f_1291)
static void C_ccall f_1291(C_word c,C_word *av) C_noret;
C_noret_decl(f_1297)
static void C_ccall f_1297(C_word c,C_word *av) C_noret;
C_noret_decl(f_1319)
static void C_ccall f_1319(C_word c,C_word *av) C_noret;
C_noret_decl(f_1325)
static void C_ccall f_1325(C_word c,C_word *av) C_noret;
C_noret_decl(f_1347)
static void C_ccall f_1347(C_word c,C_word *av) C_noret;
C_noret_decl(f_1353)
static void C_ccall f_1353(C_word c,C_word *av) C_noret;
C_noret_decl(f_1375)
static void C_ccall f_1375(C_word c,C_word *av) C_noret;
C_noret_decl(f_1381)
static void C_ccall f_1381(C_word c,C_word *av) C_noret;
C_noret_decl(f_1403)
static void C_ccall f_1403(C_word c,C_word *av) C_noret;
C_noret_decl(f_1409)
static void C_ccall f_1409(C_word c,C_word *av) C_noret;
C_noret_decl(f_1431)
static void C_ccall f_1431(C_word c,C_word *av) C_noret;
C_noret_decl(f_1437)
static void C_ccall f_1437(C_word c,C_word *av) C_noret;
C_noret_decl(f_1459)
static void C_ccall f_1459(C_word c,C_word *av) C_noret;
C_noret_decl(f_1465)
static void C_ccall f_1465(C_word c,C_word *av) C_noret;
C_noret_decl(f_1487)
static void C_ccall f_1487(C_word c,C_word *av) C_noret;
C_noret_decl(f_459)
static void C_ccall f_459(C_word c,C_word *av) C_noret;
C_noret_decl(f_461)
static void C_ccall f_461(C_word c,C_word *av) C_noret;
C_noret_decl(f_467)
static void C_ccall f_467(C_word c,C_word *av) C_noret;
C_noret_decl(f_489)
static void C_ccall f_489(C_word c,C_word *av) C_noret;
C_noret_decl(f_495)
static void C_ccall f_495(C_word c,C_word *av) C_noret;
C_noret_decl(f_517)
static void C_ccall f_517(C_word c,C_word *av) C_noret;
C_noret_decl(f_523)
static void C_ccall f_523(C_word c,C_word *av) C_noret;
C_noret_decl(f_529)
static void C_ccall f_529(C_word c,C_word *av) C_noret;
C_noret_decl(f_551)
static void C_ccall f_551(C_word c,C_word *av) C_noret;
C_noret_decl(f_557)
static void C_ccall f_557(C_word c,C_word *av) C_noret;
C_noret_decl(f_579)
static void C_ccall f_579(C_word c,C_word *av) C_noret;
C_noret_decl(f_585)
static void C_ccall f_585(C_word c,C_word *av) C_noret;
C_noret_decl(f_607)
static void C_ccall f_607(C_word c,C_word *av) C_noret;
C_noret_decl(f_613)
static void C_ccall f_613(C_word c,C_word *av) C_noret;
C_noret_decl(f_635)
static void C_ccall f_635(C_word c,C_word *av) C_noret;
C_noret_decl(f_641)
static void C_ccall f_641(C_word c,C_word *av) C_noret;
C_noret_decl(f_663)
static void C_ccall f_663(C_word c,C_word *av) C_noret;
C_noret_decl(f_669)
static void C_ccall f_669(C_word c,C_word *av) C_noret;
C_noret_decl(f_675)
static void C_ccall f_675(C_word c,C_word *av) C_noret;
C_noret_decl(f_697)
static void C_ccall f_697(C_word c,C_word *av) C_noret;
C_noret_decl(f_703)
static void C_ccall f_703(C_word c,C_word *av) C_noret;
C_noret_decl(f_725)
static void C_ccall f_725(C_word c,C_word *av) C_noret;
C_noret_decl(f_731)
static void C_ccall f_731(C_word c,C_word *av) C_noret;
C_noret_decl(f_753)
static void C_ccall f_753(C_word c,C_word *av) C_noret;
C_noret_decl(f_759)
static void C_ccall f_759(C_word c,C_word *av) C_noret;
C_noret_decl(f_781)
static void C_ccall f_781(C_word c,C_word *av) C_noret;
C_noret_decl(f_787)
static void C_ccall f_787(C_word c,C_word *av) C_noret;
C_noret_decl(f_809)
static void C_ccall f_809(C_word c,C_word *av) C_noret;
C_noret_decl(f_815)
static void C_ccall f_815(C_word c,C_word *av) C_noret;
C_noret_decl(f_821)
static void C_ccall f_821(C_word c,C_word *av) C_noret;
C_noret_decl(f_843)
static void C_ccall f_843(C_word c,C_word *av) C_noret;
C_noret_decl(f_849)
static void C_ccall f_849(C_word c,C_word *av) C_noret;
C_noret_decl(f_871)
static void C_ccall f_871(C_word c,C_word *av) C_noret;
C_noret_decl(f_877)
static void C_ccall f_877(C_word c,C_word *av) C_noret;
C_noret_decl(f_899)
static void C_ccall f_899(C_word c,C_word *av) C_noret;
C_noret_decl(f_905)
static void C_ccall f_905(C_word c,C_word *av) C_noret;
C_noret_decl(f_927)
static void C_ccall f_927(C_word c,C_word *av) C_noret;
C_noret_decl(f_933)
static void C_ccall f_933(C_word c,C_word *av) C_noret;
C_noret_decl(f_955)
static void C_ccall f_955(C_word c,C_word *av) C_noret;
C_noret_decl(f_961)
static void C_ccall f_961(C_word c,C_word *av) C_noret;
C_noret_decl(f_983)
static void C_ccall f_983(C_word c,C_word *av) C_noret;
C_noret_decl(f_989)
static void C_ccall f_989(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_2dmodules_toplevel)
C_externexport void C_ccall C_eval_2dmodules_toplevel(C_word c,C_word *av) C_noret;

/* a1010 in k457 */
static void C_ccall f_1011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1011,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1017,a[2]=((C_word)li41),tmp=(C_word)a,a+=3,tmp);
/* chicken.locative.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1016 in a1010 in k457 */
static void C_ccall f_1017(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1017,c,av);}
/* chicken.locative.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[61];
av2[3]=lf[46];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[62];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1038 in k457 */
static void C_ccall f_1039(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1039,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1045,a[2]=((C_word)li43),tmp=(C_word)a,a+=3,tmp);
/* chicken.memory.representation.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1044 in a1038 in k457 */
static void C_ccall f_1045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1045,c,av);}
/* chicken.memory.representation.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[63];
av2[3]=lf[46];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[64];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1066 in k457 */
static void C_ccall f_1067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1067,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1073,a[2]=((C_word)li45),tmp=(C_word)a,a+=3,tmp);
/* chicken.plist.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1072 in a1066 in k457 */
static void C_ccall f_1073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1073,c,av);}
/* chicken.plist.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[65];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[66];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1094 in k457 */
static void C_ccall f_1095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1095,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1101,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp);
/* chicken.pretty-print.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1100 in a1094 in k457 */
static void C_ccall f_1101(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1101,c,av);}
/* chicken.pretty-print.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[67];
av2[3]=lf[37];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[68];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1122 in k457 */
static void C_ccall f_1123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1123,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1129,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp);
/* chicken.process.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1128 in a1122 in k457 */
static void C_ccall f_1129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1129,c,av);}
/* chicken.process.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[69];
av2[3]=lf[22];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[70];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1150 in k457 */
static void C_ccall f_1151(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1151,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1157,a[2]=((C_word)li51),tmp=(C_word)a,a+=3,tmp);
/* chicken.process.signal.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1156 in a1150 in k457 */
static void C_ccall f_1157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1157,c,av);}
/* chicken.process.signal.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[71];
av2[3]=lf[22];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[72];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1178 in k457 */
static void C_ccall f_1179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1179,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1185,a[2]=((C_word)li53),tmp=(C_word)a,a+=3,tmp);
/* chicken.process-context.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1184 in a1178 in k457 */
static void C_ccall f_1185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1185,c,av);}
/* chicken.process-context.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[73];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[74];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1206 in k457 */
static void C_ccall f_1207(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1207,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1213,a[2]=((C_word)li55),tmp=(C_word)a,a+=3,tmp);
/* chicken.process-context.posix.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1212 in a1206 in k457 */
static void C_ccall f_1213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1213,c,av);}
/* chicken.process-context.posix.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[75];
av2[3]=lf[22];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[76];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1234 in k457 */
static void C_ccall f_1235(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1235,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1241,a[2]=((C_word)li57),tmp=(C_word)a,a+=3,tmp);
/* chicken.random.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1240 in a1234 in k457 */
static void C_ccall f_1241(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1241,c,av);}
/* chicken.random.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[77];
av2[3]=lf[37];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[78];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1262 in k457 */
static void C_ccall f_1263(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1263,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1269,a[2]=((C_word)li59),tmp=(C_word)a,a+=3,tmp);
/* chicken.sort.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1268 in a1262 in k457 */
static void C_ccall f_1269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1269,c,av);}
/* chicken.sort.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[79];
av2[3]=lf[28];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[80];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1290 in k457 */
static void C_ccall f_1291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1291,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1297,a[2]=((C_word)li61),tmp=(C_word)a,a+=3,tmp);
/* chicken.time.posix.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1296 in a1290 in k457 */
static void C_ccall f_1297(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1297,c,av);}
/* chicken.time.posix.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[81];
av2[3]=lf[22];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[82];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1318 in k457 */
static void C_ccall f_1319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1319,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1325,a[2]=((C_word)li63),tmp=(C_word)a,a+=3,tmp);
/* chicken.continuation.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1324 in a1318 in k457 */
static void C_ccall f_1325(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1325,c,av);}
/* chicken.continuation.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[83];
av2[3]=lf[84];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[85];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1346 in k457 */
static void C_ccall f_1347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1347,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1353,a[2]=((C_word)li65),tmp=(C_word)a,a+=3,tmp);
/* chicken.file.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1352 in a1346 in k457 */
static void C_ccall f_1353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1353,c,av);}
/* chicken.file.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[86];
av2[3]=lf[87];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[88];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1374 in k457 */
static void C_ccall f_1375(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1375,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1381,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp);
/* chicken.read-syntax.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1380 in a1374 in k457 */
static void C_ccall f_1381(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1381,c,av);}
/* chicken.read-syntax.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[89];
av2[3]=lf[90];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[91];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1402 in k457 */
static void C_ccall f_1403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1403,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1409,a[2]=((C_word)li69),tmp=(C_word)a,a+=3,tmp);
/* chicken.repl.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1408 in a1402 in k457 */
static void C_ccall f_1409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1409,c,av);}
/* chicken.repl.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[92];
av2[3]=lf[93];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[94];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1430 in k457 */
static void C_ccall f_1431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1431,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1437,a[2]=((C_word)li71),tmp=(C_word)a,a+=3,tmp);
/* chicken.tcp.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1436 in a1430 in k457 */
static void C_ccall f_1437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1437,c,av);}
/* chicken.tcp.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[95];
av2[3]=lf[96];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[97];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a1458 in k457 */
static void C_ccall f_1459(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1459,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1465,a[2]=((C_word)li73),tmp=(C_word)a,a+=3,tmp);
/* srfi-4.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a1464 in a1458 in k457 */
static void C_ccall f_1465(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_1465,c,av);}
/* srfi-4.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[98];
av2[3]=lf[98];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[99];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* ##sys#import-library-hook in k457 */
static void C_ccall f_1487(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1487,c,av);}
t3=C_i_getprop(t2,lf[6],C_SCHEME_FALSE);
if(C_truep(t3)){
/* eval-modules.scm:100: il */
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}
else{
/* eval-modules.scm:101: hook */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}}

/* k457 */
static void C_ccall f_459(C_word c,C_word *av){
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
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word t27;
C_word t28;
C_word t29;
C_word t30;
C_word t31;
C_word t32;
C_word t33;
C_word t34;
C_word t35;
C_word t36;
C_word t37;
C_word t38;
C_word t39;
C_word t40;
C_word t41;
C_word t42;
C_word t43;
C_word t44;
C_word t45;
C_word t46;
C_word t47;
C_word t48;
C_word t49;
C_word t50;
C_word t51;
C_word t52;
C_word t53;
C_word t54;
C_word t55;
C_word t56;
C_word t57;
C_word t58;
C_word t59;
C_word t60;
C_word t61;
C_word t62;
C_word t63;
C_word t64;
C_word t65;
C_word t66;
C_word t67;
C_word t68;
C_word t69;
C_word t70;
C_word t71;
C_word t72;
C_word t73;
C_word t74;
C_word t75;
C_word t76;
C_word t77;
C_word t78;
C_word t79;
C_word t80;
C_word t81;
C_word t82;
C_word t83;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(441,c,3)))){
C_save_and_reclaim((void *)f_459,c,av);}
a=C_alloc(441);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_461,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_putprop(&a,3,lf[2],lf[6],t3);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_489,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_putprop(&a,3,lf[7],lf[6],t5);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_517,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp);
t8=C_a_i_putprop(&a,3,lf[10],lf[6],t7);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_523,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp);
t10=C_a_i_putprop(&a,3,lf[12],lf[6],t9);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_551,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp);
t12=C_a_i_putprop(&a,3,lf[14],lf[6],t11);
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_579,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp);
t14=C_a_i_putprop(&a,3,lf[16],lf[6],t13);
t15=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_607,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp);
t16=C_a_i_putprop(&a,3,lf[19],lf[6],t15);
t17=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_635,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp);
t18=C_a_i_putprop(&a,3,lf[21],lf[6],t17);
t19=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_663,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp);
t20=C_a_i_putprop(&a,3,lf[24],lf[6],t19);
t21=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_669,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp);
t22=C_a_i_putprop(&a,3,lf[27],lf[6],t21);
t23=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_697,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp);
t24=C_a_i_putprop(&a,3,lf[30],lf[6],t23);
t25=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_725,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp);
t26=C_a_i_putprop(&a,3,lf[33],lf[6],t25);
t27=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_753,a[2]=((C_word)li23),tmp=(C_word)a,a+=3,tmp);
t28=C_a_i_putprop(&a,3,lf[36],lf[6],t27);
t29=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_781,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp);
t30=C_a_i_putprop(&a,3,lf[39],lf[6],t29);
t31=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_809,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp);
t32=C_a_i_putprop(&a,3,lf[42],lf[6],t31);
t33=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_815,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp);
t34=C_a_i_putprop(&a,3,lf[45],lf[6],t33);
t35=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_843,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp);
t36=C_a_i_putprop(&a,3,lf[48],lf[6],t35);
t37=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_871,a[2]=((C_word)li32),tmp=(C_word)a,a+=3,tmp);
t38=C_a_i_putprop(&a,3,lf[50],lf[6],t37);
t39=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_899,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp);
t40=C_a_i_putprop(&a,3,lf[52],lf[6],t39);
t41=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_927,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp);
t42=C_a_i_putprop(&a,3,lf[54],lf[6],t41);
t43=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_955,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp);
t44=C_a_i_putprop(&a,3,lf[56],lf[6],t43);
t45=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_983,a[2]=((C_word)li40),tmp=(C_word)a,a+=3,tmp);
t46=C_a_i_putprop(&a,3,lf[59],lf[6],t45);
t47=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1011,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp);
t48=C_a_i_putprop(&a,3,lf[61],lf[6],t47);
t49=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1039,a[2]=((C_word)li44),tmp=(C_word)a,a+=3,tmp);
t50=C_a_i_putprop(&a,3,lf[63],lf[6],t49);
t51=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1067,a[2]=((C_word)li46),tmp=(C_word)a,a+=3,tmp);
t52=C_a_i_putprop(&a,3,lf[65],lf[6],t51);
t53=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1095,a[2]=((C_word)li48),tmp=(C_word)a,a+=3,tmp);
t54=C_a_i_putprop(&a,3,lf[67],lf[6],t53);
t55=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1123,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp);
t56=C_a_i_putprop(&a,3,lf[69],lf[6],t55);
t57=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1151,a[2]=((C_word)li52),tmp=(C_word)a,a+=3,tmp);
t58=C_a_i_putprop(&a,3,lf[71],lf[6],t57);
t59=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1179,a[2]=((C_word)li54),tmp=(C_word)a,a+=3,tmp);
t60=C_a_i_putprop(&a,3,lf[73],lf[6],t59);
t61=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1207,a[2]=((C_word)li56),tmp=(C_word)a,a+=3,tmp);
t62=C_a_i_putprop(&a,3,lf[75],lf[6],t61);
t63=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1235,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp);
t64=C_a_i_putprop(&a,3,lf[77],lf[6],t63);
t65=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1263,a[2]=((C_word)li60),tmp=(C_word)a,a+=3,tmp);
t66=C_a_i_putprop(&a,3,lf[79],lf[6],t65);
t67=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1291,a[2]=((C_word)li62),tmp=(C_word)a,a+=3,tmp);
t68=C_a_i_putprop(&a,3,lf[81],lf[6],t67);
t69=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1319,a[2]=((C_word)li64),tmp=(C_word)a,a+=3,tmp);
t70=C_a_i_putprop(&a,3,lf[83],lf[6],t69);
t71=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1347,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp);
t72=C_a_i_putprop(&a,3,lf[86],lf[6],t71);
t73=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1375,a[2]=((C_word)li68),tmp=(C_word)a,a+=3,tmp);
t74=C_a_i_putprop(&a,3,lf[89],lf[6],t73);
t75=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1403,a[2]=((C_word)li70),tmp=(C_word)a,a+=3,tmp);
t76=C_a_i_putprop(&a,3,lf[92],lf[6],t75);
t77=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1431,a[2]=((C_word)li72),tmp=(C_word)a,a+=3,tmp);
t78=C_a_i_putprop(&a,3,lf[95],lf[6],t77);
t79=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1459,a[2]=((C_word)li74),tmp=(C_word)a,a+=3,tmp);
t80=C_a_i_putprop(&a,3,lf[98],lf[6],t79);
t81=*((C_word*)lf[100]+1);
t82=C_mutate((C_word*)lf[100]+1 /* (set! ##sys#import-library-hook ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1487,a[2]=t81,a[3]=((C_word)li75),tmp=(C_word)a,a+=4,tmp));
t83=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t83;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t83+1)))(2,av2);}}

/* a460 in k457 */
static void C_ccall f_461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_461,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_467,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp);
/* chicken.bitwise.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a466 in a460 in k457 */
static void C_ccall f_467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_467,c,av);}
/* chicken.bitwise.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[2];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[4];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a488 in k457 */
static void C_ccall f_489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_489,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_495,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp);
/* chicken.blob.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a494 in a488 in k457 */
static void C_ccall f_495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_495,c,av);}
/* chicken.blob.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[7];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[8];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a516 in k457 */
static void C_ccall f_517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_517,c,av);}
/* chicken.foreign.import.scm:27: ##sys#register-core-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t1;
av2[2]=lf[10];
av2[3]=lf[10];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=*((C_word*)lf[11]+1);
tp(6,av2);}}

/* a522 in k457 */
static void C_ccall f_523(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_523,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_529,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp);
/* chicken.fixnum.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a528 in a522 in k457 */
static void C_ccall f_529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_529,c,av);}
/* chicken.fixnum.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[12];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[13];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a550 in k457 */
static void C_ccall f_551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_551,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_557,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp);
/* chicken.keyword.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a556 in a550 in k457 */
static void C_ccall f_557(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_557,c,av);}
/* chicken.keyword.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[14];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[15];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a578 in k457 */
static void C_ccall f_579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_579,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_585,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp);
/* chicken.internal.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a584 in a578 in k457 */
static void C_ccall f_585(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_585,c,av);}
/* chicken.internal.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[16];
av2[3]=lf[17];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[18];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a606 in k457 */
static void C_ccall f_607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_607,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_613,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp);
/* chicken.platform.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a612 in a606 in k457 */
static void C_ccall f_613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_613,c,av);}
/* chicken.platform.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[19];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[20];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a634 in k457 */
static void C_ccall f_635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_635,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_641,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp);
/* chicken.errno.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a640 in a634 in k457 */
static void C_ccall f_641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_641,c,av);}
/* chicken.errno.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[21];
av2[3]=lf[22];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[23];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a662 in k457 */
static void C_ccall f_663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_663,c,av);}
/* chicken.condition.import.scm:26: ##sys#register-core-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t1;
av2[2]=lf[24];
av2[3]=lf[24];
av2[4]=lf[25];
av2[5]=*((C_word*)lf[26]+1);
tp(6,av2);}}

/* a668 in k457 */
static void C_ccall f_669(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_669,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_675,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp);
/* chicken.string.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a674 in a668 in k457 */
static void C_ccall f_675(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_675,c,av);}
/* chicken.string.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[27];
av2[3]=lf[28];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[29];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a696 in k457 */
static void C_ccall f_697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_697,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_703,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp);
/* chicken.irregex.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a702 in a696 in k457 */
static void C_ccall f_703(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_703,c,av);}
/* chicken.irregex.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[30];
av2[3]=lf[31];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[32];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a724 in k457 */
static void C_ccall f_725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_725,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_731,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp);
/* chicken.pathname.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a730 in a724 in k457 */
static void C_ccall f_731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_731,c,av);}
/* chicken.pathname.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[33];
av2[3]=lf[34];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[35];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a752 in k457 */
static void C_ccall f_753(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_753,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_759,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp);
/* chicken.io.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a758 in a752 in k457 */
static void C_ccall f_759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_759,c,av);}
/* chicken.io.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[36];
av2[3]=lf[37];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[38];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a780 in k457 */
static void C_ccall f_781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_781,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_787,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp);
/* chicken.port.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a786 in a780 in k457 */
static void C_ccall f_787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_787,c,av);}
/* chicken.port.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[39];
av2[3]=lf[40];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[41];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a808 in k457 */
static void C_ccall f_809(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_809,c,av);}
/* chicken.time.import.scm:26: ##sys#register-core-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t1;
av2[2]=lf[42];
av2[3]=lf[3];
av2[4]=lf[43];
av2[5]=*((C_word*)lf[44]+1);
tp(6,av2);}}

/* a814 in k457 */
static void C_ccall f_815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_815,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_821,a[2]=((C_word)li27),tmp=(C_word)a,a+=3,tmp);
/* chicken.memory.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a820 in a814 in k457 */
static void C_ccall f_821(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_821,c,av);}
/* chicken.memory.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[45];
av2[3]=lf[46];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[47];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a842 in k457 */
static void C_ccall f_843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_843,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_849,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp);
/* chicken.file.posix.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a848 in a842 in k457 */
static void C_ccall f_849(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_849,c,av);}
/* chicken.file.posix.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[48];
av2[3]=lf[22];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[49];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a870 in k457 */
static void C_ccall f_871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_871,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_877,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp);
/* chicken.flonum.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a876 in a870 in k457 */
static void C_ccall f_877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_877,c,av);}
/* chicken.flonum.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[50];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[51];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a898 in k457 */
static void C_ccall f_899(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_899,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_905,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp);
/* chicken.format.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a904 in a898 in k457 */
static void C_ccall f_905(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_905,c,av);}
/* chicken.format.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[52];
av2[3]=lf[37];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[53];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a926 in k457 */
static void C_ccall f_927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_927,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_933,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp);
/* chicken.gc.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a932 in a926 in k457 */
static void C_ccall f_933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_933,c,av);}
/* chicken.gc.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[54];
av2[3]=lf[3];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[55];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a954 in k457 */
static void C_ccall f_955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_955,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_961,a[2]=((C_word)li37),tmp=(C_word)a,a+=3,tmp);
/* chicken.eval.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a960 in a954 in k457 */
static void C_ccall f_961(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_961,c,av);}
/* chicken.eval.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[56];
av2[3]=lf[57];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[58];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* a982 in k457 */
static void C_ccall f_983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_983,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_989,a[2]=((C_word)li39),tmp=(C_word)a,a+=3,tmp);
/* chicken.load.import.scm:3: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* a988 in a982 in k457 */
static void C_ccall f_989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_989,c,av);}
/* chicken.load.import.scm:5: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[1]+1));
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t1;
av2[2]=lf[59];
av2[3]=lf[57];
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[60];
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_eval_2dmodules_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("eval-modules"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_eval_2dmodules_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(15681))){
C_save(t1);
C_rereclaim2(15681*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,101);
lf[0]=C_h_intern(&lf[0],12, C_text("eval-modules"));
lf[1]=C_h_intern(&lf[1],30, C_text("##sys#register-compiled-module"));
lf[2]=C_h_intern(&lf[2],15, C_text("chicken.bitwise"));
lf[3]=C_h_intern(&lf[3],7, C_text("library"));
lf[4]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001arithmetic-shift\376\001\000\000 \001chicken.bitwise#arithmetic-shift\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\016\001integer-length\376\001\000\000\036\001chicken.bitwise#integer-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001bit->boo"
"lean\376\001\000\000\034\001chicken.bitwise#bit->boolean\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001bitwise-not\376\001\000\000\033\001chicken.b"
"itwise#bitwise-not\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001bitwise-xor\376\001\000\000\033\001chicken.bitwise#bitwise-xor\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\013\001bitwise-ior\376\001\000\000\033\001chicken.bitwise#bitwise-ior\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001bitwis"
"e-and\376\001\000\000\033\001chicken.bitwise#bitwise-and\376\377\016"));
lf[5]=C_h_intern(&lf[5],22, C_text("##sys#with-environment"));
lf[6]=C_h_intern(&lf[6],12, C_text("##sys#import"));
lf[7]=C_h_intern(&lf[7],12, C_text("chicken.blob"));
lf[8]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001blob->string\376\001\000\000\031\001chicken.blob#blob->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001strin"
"g->blob\376\001\000\000\031\001chicken.blob#string->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001blob\077\376\001\000\000\022\001chicken.blob#bl"
"ob\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001blob=\077\376\001\000\000\023\001chicken.blob#blob=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001blob-size\376\001\000\000\026"
"\001chicken.blob#blob-size\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001make-blob\376\001\000\000\026\001chicken.blob#make-blob\376\377\016"));
lf[9]=C_h_intern(&lf[9],26, C_text("##sys#register-core-module"));
lf[10]=C_h_intern(&lf[10],15, C_text("chicken.foreign"));
lf[11]=C_h_intern(&lf[11],35, C_text("##sys#chicken-ffi-macro-environment"));
lf[12]=C_h_intern(&lf[12],14, C_text("chicken.fixnum"));
lf[13]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fx/\077\376\001\000\000\023\001chicken.fixnum#fx/\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fx\052\077\376\001\000\000\023\001chicken.f"
"ixnum#fx\052\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fx-\077\376\001\000\000\023\001chicken.fixnum#fx-\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fx+\077\376\001\000\000\023"
"\001chicken.fixnum#fx+\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxrem\376\001\000\000\024\001chicken.fixnum#fxrem\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\005\001fxmod\376\001\000\000\024\001chicken.fixnum#fxmod\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxgcd\376\001\000\000\024\001chicken.fixnum#fxgc"
"d\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fx/\376\001\000\000\022\001chicken.fixnum#fx/\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxlen\376\001\000\000\024\001chicken.f"
"ixnum#fxlen\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fxeven\077\376\001\000\000\026\001chicken.fixnum#fxeven\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fx"
"odd\077\376\001\000\000\025\001chicken.fixnum#fxodd\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxshr\376\001\000\000\024\001chicken.fixnum#fxshr\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxshl\376\001\000\000\024\001chicken.fixnum#fxshl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxnot\376\001\000\000\024\001chicken."
"fixnum#fxnot\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxxor\376\001\000\000\024\001chicken.fixnum#fxxor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxior"
"\376\001\000\000\024\001chicken.fixnum#fxior\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxand\376\001\000\000\024\001chicken.fixnum#fxand\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\005\001fxneg\376\001\000\000\024\001chicken.fixnum#fxneg\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxmax\376\001\000\000\024\001chicken.fixnu"
"m#fxmax\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fxmin\376\001\000\000\024\001chicken.fixnum#fxmin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fx<=\376\001\000\000\023\001"
"chicken.fixnum#fx<=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fx>=\376\001\000\000\023\001chicken.fixnum#fx>=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001"
"fx<\376\001\000\000\022\001chicken.fixnum#fx<\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fx>\376\001\000\000\022\001chicken.fixnum#fx>\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\003\001fx=\376\001\000\000\022\001chicken.fixnum#fx=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fx\052\376\001\000\000\022\001chicken.fixnum#fx\052\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\003\001fx-\376\001\000\000\022\001chicken.fixnum#fx-\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fx+\376\001\000\000\022\001chicken.fixnum#f"
"x+\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001fixnum-precision\376\001\000\000\037\001chicken.fixnum#fixnum-precision\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\013\001fixnum-bits\376\001\000\000\032\001chicken.fixnum#fixnum-bits\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001most-negative-"
"fixnum\376\001\000\000#\001chicken.fixnum#most-negative-fixnum\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001most-positive-fix"
"num\376\001\000\000#\001chicken.fixnum#most-positive-fixnum\376\377\016"));
lf[14]=C_h_intern(&lf[14],15, C_text("chicken.keyword"));
lf[15]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001keyword\077\376\001\000\000\030\001chicken.keyword#keyword\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001get-keywor"
"d\376\001\000\000\033\001chicken.keyword#get-keyword\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001keyword->string\376\001\000\000\037\001chicken.k"
"eyword#keyword->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001string->keyword\376\001\000\000\037\001chicken.keyword#strin"
"g->keyword\376\377\016"));
lf[16]=C_h_intern(&lf[16],16, C_text("chicken.internal"));
lf[17]=C_h_intern(&lf[17],8, C_text("internal"));
lf[18]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001string->c-identifier\376\001\000\000%\001chicken.internal#string->c-identifier\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001library-id\376\001\000\000\033\001chicken.internal#library-id\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001valid-"
"library-specifier\077\376\001\000\000)\001chicken.internal#valid-library-specifier\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022"
"\001module-requirement\376\001\000\000#\001chicken.internal#module-requirement\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001chec"
"k-for-multiple-bindings\376\001\000\000,\001chicken.internal#check-for-multiple-bindings\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\014\001macro-subset\376\001\000\000\035\001chicken.internal#macro-subset\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001fixup-ma"
"cro-environment\376\001\000\000(\001chicken.internal#fixup-macro-environment\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001mak"
"e-hash-table\376\001\000\000 \001chicken.internal#make-hash-table\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001hash-table-ref"
"\376\001\000\000\037\001chicken.internal#hash-table-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001hash-table-set!\376\001\000\000 \001chicke"
"n.internal#hash-table-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001hash-table-update!\376\001\000\000#\001chicken.intern"
"al#hash-table-update!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001hash-table-for-each\376\001\000\000$\001chicken.internal#h"
"ash-table-for-each\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001hash-table-size\376\001\000\000 \001chicken.internal#hash-tab"
"le-size\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001default-imports\376\001\000\000 \001chicken.internal#default-imports\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\026\001default-syntax-imports\376\001\000\000\047\001chicken.internal#default-syntax-imports\376"
"\377\016"));
lf[19]=C_h_intern(&lf[19],16, C_text("chicken.platform"));
lf[20]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001build-platform\376\001\000\000\037\001chicken.platform#build-platform\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\017\001chicken-version\376\001\000\000 \001chicken.platform#chicken-version\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001chicken-"
"home\376\001\000\000\035\001chicken.platform#chicken-home\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001include-path\376\001\000\000\035\001chicken"
".platform#include-path\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001feature\077\376\001\000\000\031\001chicken.platform#feature\077\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\010\001features\376\001\000\000\031\001chicken.platform#features\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001machine-byte"
"-order\376\001\000\000#\001chicken.platform#machine-byte-order\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001machine-type\376\001\000\000\035"
"\001chicken.platform#machine-type\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001repository-path\376\001\000\000 \001chicken.platf"
"orm#repository-path\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001installation-repository\376\001\000\000(\001chicken.platform"
"#installation-repository\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001register-feature!\376\001\000\000\042\001chicken.platform#"
"register-feature!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001unregister-feature!\376\001\000\000$\001chicken.platform#unreg"
"ister-feature!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001software-type\376\001\000\000\036\001chicken.platform#software-type\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001software-version\376\001\000\000!\001chicken.platform#software-version\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\016\001return-to-host\376\001\000\000\037\001chicken.platform#return-to-host\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001system-"
"config-directory\376\001\000\000(\001chicken.platform#system-config-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001sy"
"stem-cache-directory\376\001\000\000\047\001chicken.platform#system-cache-directory\376\377\016"));
lf[21]=C_h_intern(&lf[21],13, C_text("chicken.errno"));
lf[22]=C_h_intern(&lf[22],5, C_text("posix"));
lf[23]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/xdev\376\001\000\000\030\001chicken.errno#errno/xdev\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001errno/wo"
"uldblock\376\001\000\000\036\001chicken.errno#errno/wouldblock\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/srch\376\001\000\000\030\001chic"
"ken.errno#errno/srch\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/spipe\376\001\000\000\031\001chicken.errno#errno/spipe\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/rofs\376\001\000\000\030\001chicken.errno#errno/rofs\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/rang"
"e\376\001\000\000\031\001chicken.errno#errno/range\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/pipe\376\001\000\000\030\001chicken.errno#er"
"rno/pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/perm\376\001\000\000\030\001chicken.errno#errno/perm\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001"
"errno/nxio\376\001\000\000\030\001chicken.errno#errno/nxio\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/notty\376\001\000\000\031\001chicken"
".errno#errno/notty\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001errno/notempty\376\001\000\000\034\001chicken.errno#errno/notemp"
"ty\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001errno/notdir\376\001\000\000\032\001chicken.errno#errno/notdir\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001er"
"rno/nosys\376\001\000\000\031\001chicken.errno#errno/nosys\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/nospc\376\001\000\000\031\001chicken"
".errno#errno/nospc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/nomem\376\001\000\000\031\001chicken.errno#errno/nomem\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\013\001errno/nolck\376\001\000\000\031\001chicken.errno#errno/nolck\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001errno/noex"
"ec\376\001\000\000\032\001chicken.errno#errno/noexec\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/noent\376\001\000\000\031\001chicken.errno"
"#errno/noent\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/nodev\376\001\000\000\031\001chicken.errno#errno/nodev\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\013\001errno/nfile\376\001\000\000\031\001chicken.errno#errno/nfile\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001errno/nametoolon"
"g\376\001\000\000\037\001chicken.errno#errno/nametoolong\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/mlink\376\001\000\000\031\001chicken.e"
"rrno#errno/mlink\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/mfile\376\001\000\000\031\001chicken.errno#errno/mfile\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\013\001errno/isdir\376\001\000\000\031\001chicken.errno#errno/isdir\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001errno/io\376\001\000\000"
"\026\001chicken.errno#errno/io\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/inval\376\001\000\000\031\001chicken.errno#errno/inv"
"al\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/intr\376\001\000\000\030\001chicken.errno#errno/intr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/"
"ilseq\376\001\000\000\031\001chicken.errno#errno/ilseq\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/fbig\376\001\000\000\030\001chicken.errn"
"o#errno/fbig\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/fault\376\001\000\000\031\001chicken.errno#errno/fault\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\013\001errno/exist\376\001\000\000\031\001chicken.errno#errno/exist\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001errno/dom\376\001\000\000\027\001c"
"hicken.errno#errno/dom\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001errno/deadlk\376\001\000\000\032\001chicken.errno#errno/dead"
"lk\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/child\376\001\000\000\031\001chicken.errno#errno/child\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errn"
"o/busy\376\001\000\000\030\001chicken.errno#errno/busy\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/badf\376\001\000\000\030\001chicken.errn"
"o#errno/badf\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001errno/again\376\001\000\000\031\001chicken.errno#errno/again\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\013\001errno/acces\376\001\000\000\031\001chicken.errno#errno/acces\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001errno/2big\376\001\000\000\030\001"
"chicken.errno#errno/2big\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001errno\376\001\000\000\023\001chicken.errno#errno\376\377\016"));
lf[24]=C_h_intern(&lf[24],17, C_text("chicken.condition"));
lf[25]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001abort\376\001\000\000\027\001chicken.condition#abort\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001signal\376\001\000\000\030\001ch"
"icken.condition#signal\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001current-exception-handler\376\001\000\000+\001chicken.con"
"dition#current-exception-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001print-error-message\376\001\000\000%\001chicken"
".condition#print-error-message\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001with-exception-handler\376\001\000\000(\001chicke"
"n.condition#with-exception-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001make-property-condition\376\001\000\000)\001c"
"hicken.condition#make-property-condition\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001make-composite-condition"
"\376\001\000\000\052\001chicken.condition#make-composite-condition\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001condition\376\001\000\000\033\001c"
"hicken.condition#condition\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001condition\077\376\001\000\000\034\001chicken.condition#cond"
"ition\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001condition->list\376\001\000\000!\001chicken.condition#condition->list\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\023\001condition-predicate\376\001\000\000%\001chicken.condition#condition-predicate\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\033\001condition-property-accessor\376\001\000\000-\001chicken.condition#condition-property-"
"accessor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001get-condition-property\376\001\000\000(\001chicken.condition#get-condit"
"ion-property\376\377\016"));
lf[26]=C_h_intern(&lf[26],41, C_text("##sys#chicken.condition-macro-environment"));
lf[27]=C_h_intern(&lf[27],14, C_text("chicken.string"));
lf[28]=C_h_intern(&lf[28],15, C_text("data-structures"));
lf[29]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001conc\376\001\000\000\023\001chicken.string#conc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001->string\376\001\000\000\027\001chick"
"en.string#->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string-chop\376\001\000\000\032\001chicken.string#string-chop\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\014\001string-chomp\376\001\000\000\033\001chicken.string#string-chomp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001string"
"-compare3\376\001\000\000\036\001chicken.string#string-compare3\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001string-compare3-ci\376"
"\001\000\000!\001chicken.string#string-compare3-ci\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001reverse-list->string\376\001\000\000#\001"
"chicken.string#reverse-list->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001reverse-string-append\376\001\000\000$\001ch"
"icken.string#reverse-string-append\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001string-intersperse\376\001\000\000!\001chicke"
"n.string#string-intersperse\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001string-split\376\001\000\000\033\001chicken.string#stri"
"ng-split\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001string-translate\376\001\000\000\037\001chicken.string#string-translate\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\021\001string-translate\052\376\001\000\000 \001chicken.string#string-translate\052\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\013\001substring=\077\376\001\000\000\032\001chicken.string#substring=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001substring-ci=\077\376\001\000"
"\000\035\001chicken.string#substring-ci=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001substring-index\376\001\000\000\036\001chicken.str"
"ing#substring-index\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001substring-index-ci\376\001\000\000!\001chicken.string#substr"
"ing-index-ci\376\377\016"));
lf[30]=C_h_intern(&lf[30],15, C_text("chicken.irregex"));
lf[31]=C_h_intern(&lf[31],7, C_text("irregex"));
lf[32]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001irregex\376\001\000\000\027\001chicken.irregex#irregex\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001irregex\077\376\001\000\000"
"\030\001chicken.irregex#irregex\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001string->sre\376\001\000\000\033\001chicken.irregex#strin"
"g->sre\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001maybe-string->sre\376\001\000\000!\001chicken.irregex#maybe-string->sre\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\014\001sre->irregex\376\001\000\000\034\001chicken.irregex#sre->irregex\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001irre"
"gex-names\376\001\000\000\035\001chicken.irregex#irregex-names\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001irregex-num-submatch"
"es\376\001\000\000&\001chicken.irregex#irregex-num-submatches\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001string->irregex\376\001\000"
"\000\037\001chicken.irregex#string->irregex\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001make-irregex-chunker\376\001\000\000$\001chic"
"ken.irregex#make-irregex-chunker\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001irregex-extract\376\001\000\000\037\001chicken.irr"
"egex#irregex-extract\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001irregex-fold\376\001\000\000\034\001chicken.irregex#irregex-fo"
"ld\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001irregex-match\376\001\000\000\035\001chicken.irregex#irregex-match\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\016\001irregex-match\077\376\001\000\000\036\001chicken.irregex#irregex-match\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001irregex-sear"
"ch\376\001\000\000\036\001chicken.irregex#irregex-search\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001irregex-split\376\001\000\000\035\001chicken"
".irregex#irregex-split\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001irregex-replace\376\001\000\000\037\001chicken.irregex#irreg"
"ex-replace\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001irregex-replace/all\376\001\000\000#\001chicken.irregex#irregex-repla"
"ce/all\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001irregex-fold/chunked\376\001\000\000$\001chicken.irregex#irregex-fold/chu"
"nked\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001irregex-match/chunked\376\001\000\000%\001chicken.irregex#irregex-match/chu"
"nked\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001irregex-search/chunked\376\001\000\000&\001chicken.irregex#irregex-search/c"
"hunked\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001irregex-match-data\077\376\001\000\000#\001chicken.irregex#irregex-match-dat"
"a\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001irregex-match-names\376\001\000\000#\001chicken.irregex#irregex-match-names\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\031\001irregex-match-start-index\376\001\000\000)\001chicken.irregex#irregex-match-start"
"-index\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001irregex-match-end-index\376\001\000\000\047\001chicken.irregex#irregex-match"
"-end-index\376\003\000\000\002\376\003\000\000\002\376\001\000\000\034\001irregex-match-num-submatches\376\001\000\000,\001chicken.irregex#irre"
"gex-match-num-submatches\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001irregex-match-substring\376\001\000\000\047\001chicken.irr"
"egex#irregex-match-substring\376\003\000\000\002\376\003\000\000\002\376\001\000\000\032\001irregex-match-valid-index\077\376\001\000\000\052\001chic"
"ken.irregex#irregex-match-valid-index\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001irregex-match-start-chunk\376"
"\001\000\000)\001chicken.irregex#irregex-match-start-chunk\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001irregex-match-end-"
"chunk\376\001\000\000\047\001chicken.irregex#irregex-match-end-chunk\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001irregex-match-"
"subchunk\376\001\000\000&\001chicken.irregex#irregex-match-subchunk\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001glob->sre\376\001\000"
"\000\031\001chicken.irregex#glob->sre\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001sre->string\376\001\000\000\033\001chicken.irregex#sre"
"->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001irregex-opt\376\001\000\000\033\001chicken.irregex#irregex-opt\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\015\001irregex-quote\376\001\000\000\035\001chicken.irregex#irregex-quote\376\377\016"));
lf[33]=C_h_intern(&lf[33],16, C_text("chicken.pathname"));
lf[34]=C_h_intern(&lf[34],8, C_text("pathname"));
lf[35]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001absolute-pathname\077\376\001\000\000#\001chicken.pathname#absolute-pathname\077\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\023\001decompose-directory\376\001\000\000$\001chicken.pathname#decompose-directory\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\022\001decompose-pathname\376\001\000\000#\001chicken.pathname#decompose-pathname\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\017\001directory-null\077\376\001\000\000 \001chicken.pathname#directory-null\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001make-abs"
"olute-pathname\376\001\000\000\047\001chicken.pathname#make-absolute-pathname\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001make-"
"pathname\376\001\000\000\036\001chicken.pathname#make-pathname\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001normalize-pathname\376\001"
"\000\000#\001chicken.pathname#normalize-pathname\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001pathname-directory\376\001\000\000#\001c"
"hicken.pathname#pathname-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001pathname-extension\376\001\000\000#\001chicke"
"n.pathname#pathname-extension\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001pathname-file\376\001\000\000\036\001chicken.pathname"
"#pathname-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\032\001pathname-replace-directory\376\001\000\000+\001chicken.pathname#p"
"athname-replace-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\032\001pathname-replace-extension\376\001\000\000+\001chicken"
".pathname#pathname-replace-extension\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001pathname-replace-file\376\001\000\000&\001c"
"hicken.pathname#pathname-replace-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001pathname-strip-directory\376\001\000"
"\000)\001chicken.pathname#pathname-strip-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001pathname-strip-exten"
"sion\376\001\000\000)\001chicken.pathname#pathname-strip-extension\376\377\016"));
lf[36]=C_h_intern(&lf[36],10, C_text("chicken.io"));
lf[37]=C_h_intern(&lf[37],6, C_text("extras"));
lf[38]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001read-list\376\001\000\000\024\001chicken.io#read-list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001read-buffered"
"\376\001\000\000\030\001chicken.io#read-buffered\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001read-byte\376\001\000\000\024\001chicken.io#read-byt"
"e\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001read-line\376\001\000\000\024\001chicken.io#read-line\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001read-lines\376\001"
"\000\000\025\001chicken.io#read-lines\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001read-string\376\001\000\000\026\001chicken.io#read-string"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001read-string!\376\001\000\000\027\001chicken.io#read-string!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001read-to"
"ken\376\001\000\000\025\001chicken.io#read-token\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001write-byte\376\001\000\000\025\001chicken.io#write-b"
"yte\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001write-line\376\001\000\000\025\001chicken.io#write-line\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001write-st"
"ring\376\001\000\000\027\001chicken.io#write-string\376\377\016"));
lf[39]=C_h_intern(&lf[39],12, C_text("chicken.port"));
lf[40]=C_h_intern(&lf[40],4, C_text("port"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001call-with-input-string\376\001\000\000#\001chicken.port#call-with-input-string\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001call-with-output-string\376\001\000\000$\001chicken.port#call-with-output-string"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001copy-port\376\001\000\000\026\001chicken.port#copy-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001make-input-"
"port\376\001\000\000\034\001chicken.port#make-input-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001make-output-port\376\001\000\000\035\001chic"
"ken.port#make-output-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001port-fold\376\001\000\000\026\001chicken.port#port-fold\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\015\001port-for-each\376\001\000\000\032\001chicken.port#port-for-each\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001port-"
"map\376\001\000\000\025\001chicken.port#port-map\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001port-name\376\001\000\000\026\001chicken.port#port-n"
"ame\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001port-position\376\001\000\000\032\001chicken.port#port-position\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001"
"make-bidirectional-port\376\001\000\000$\001chicken.port#make-bidirectional-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023"
"\001make-broadcast-port\376\001\000\000 \001chicken.port#make-broadcast-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001make-c"
"oncatenated-port\376\001\000\000#\001chicken.port#make-concatenated-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001set-buf"
"fering-mode!\376\001\000\000 \001chicken.port#set-buffering-mode!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001set-port-name!"
"\376\001\000\000\033\001chicken.port#set-port-name!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001terminal-name\376\001\000\000\032\001chicken.port"
"#terminal-name\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001terminal-port\077\376\001\000\000\033\001chicken.port#terminal-port\077\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\015\001terminal-size\376\001\000\000\032\001chicken.port#terminal-size\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001with-e"
"rror-output-to-port\376\001\000\000&\001chicken.port#with-error-output-to-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001w"
"ith-input-from-port\376\001\000\000!\001chicken.port#with-input-from-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001with-i"
"nput-from-string\376\001\000\000#\001chicken.port#with-input-from-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001with-ou"
"tput-to-port\376\001\000\000 \001chicken.port#with-output-to-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001with-output-to"
"-string\376\001\000\000\042\001chicken.port#with-output-to-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001with-error-output"
"-to-string\376\001\000\000(\001chicken.port#with-error-output-to-string\376\377\016"));
lf[42]=C_h_intern(&lf[42],12, C_text("chicken.time"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001cpu-time\376\001\000\000\025\001chicken.time#cpu-time\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001current-milli"
"seconds\376\001\000\000!\001chicken.time#current-milliseconds\376\003\000\000\002\376\003\000\000\002\376\001\000\000\034\001current-process-mi"
"lliseconds\376\001\000\000)\001chicken.time#current-process-milliseconds\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001current"
"-seconds\376\001\000\000\034\001chicken.time#current-seconds\376\377\016"));
lf[44]=C_h_intern(&lf[44],36, C_text("##sys#chicken.time-macro-environment"));
lf[45]=C_h_intern(&lf[45],14, C_text("chicken.memory"));
lf[46]=C_h_intern(&lf[46],7, C_text("lolevel"));
lf[47]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001address->pointer\376\001\000\000\037\001chicken.memory#address->pointer\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\015\001align-to-word\376\001\000\000\034\001chicken.memory#align-to-word\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001allocate\376\001\000\000"
"\027\001chicken.memory#allocate\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001free\376\001\000\000\023\001chicken.memory#free\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\023\001make-pointer-vector\376\001\000\000\042\001chicken.memory#make-pointer-vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014"
"\001move-memory!\376\001\000\000\033\001chicken.memory#move-memory!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001object->pointer\376\001\000"
"\000\036\001chicken.memory#object->pointer\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001pointer+\376\001\000\000\027\001chicken.memory#po"
"inter+\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer->address\376\001\000\000\037\001chicken.memory#pointer->address\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\017\001pointer->object\376\001\000\000\036\001chicken.memory#pointer->object\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001po"
"inter-f32-ref\376\001\000\000\036\001chicken.memory#pointer-f32-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-f32-set"
"!\376\001\000\000\037\001chicken.memory#pointer-f32-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-f64-ref\376\001\000\000\036\001chick"
"en.memory#pointer-f64-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-f64-set!\376\001\000\000\037\001chicken.memory#po"
"inter-f64-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001pointer-like\077\376\001\000\000\034\001chicken.memory#pointer-like\077\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-s16-ref\376\001\000\000\036\001chicken.memory#pointer-s16-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001"
"pointer-s16-set!\376\001\000\000\037\001chicken.memory#pointer-s16-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-s32"
"-ref\376\001\000\000\036\001chicken.memory#pointer-s32-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-s32-set!\376\001\000\000\037\001ch"
"icken.memory#pointer-s32-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-s64-ref\376\001\000\000\036\001chicken.memory"
"#pointer-s64-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-s64-set!\376\001\000\000\037\001chicken.memory#pointer-s64"
"-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001pointer-s8-ref\376\001\000\000\035\001chicken.memory#pointer-s8-ref\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\017\001pointer-s8-set!\376\001\000\000\036\001chicken.memory#pointer-s8-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001pointer"
"-tag\376\001\000\000\032\001chicken.memory#pointer-tag\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-u16-ref\376\001\000\000\036\001chicken"
".memory#pointer-u16-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-u16-set!\376\001\000\000\037\001chicken.memory#poin"
"ter-u16-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-u32-ref\376\001\000\000\036\001chicken.memory#pointer-u32-ref\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-u32-set!\376\001\000\000\037\001chicken.memory#pointer-u32-set!\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\017\001pointer-u64-ref\376\001\000\000\036\001chicken.memory#pointer-u64-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001pointer-u"
"64-set!\376\001\000\000\037\001chicken.memory#pointer-u64-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001pointer-u8-ref\376\001\000\000\035\001"
"chicken.memory#pointer-u8-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001pointer-u8-set!\376\001\000\000\036\001chicken.memory"
"#pointer-u8-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001pointer-vector\376\001\000\000\035\001chicken.memory#pointer-vecto"
"r\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001pointer-vector-fill!\376\001\000\000#\001chicken.memory#pointer-vector-fill!\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\025\001pointer-vector-length\376\001\000\000$\001chicken.memory#pointer-vector-length\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\022\001pointer-vector-ref\376\001\000\000!\001chicken.memory#pointer-vector-ref\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\023\001pointer-vector-set!\376\001\000\000\042\001chicken.memory#pointer-vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017"
"\001pointer-vector\077\376\001\000\000\036\001chicken.memory#pointer-vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001pointer=\077\376\001\000"
"\000\030\001chicken.memory#pointer=\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001pointer\077\376\001\000\000\027\001chicken.memory#pointer\077"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001tag-pointer\376\001\000\000\032\001chicken.memory#tag-pointer\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001tagge"
"d-pointer\077\376\001\000\000\036\001chicken.memory#tagged-pointer\077\376\377\016"));
lf[48]=C_h_intern(&lf[48],18, C_text("chicken.file.posix"));
lf[49]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001create-fifo\376\001\000\000\036\001chicken.file.posix#create-fifo\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001c"
"reate-symbolic-link\376\001\000\000\047\001chicken.file.posix#create-symbolic-link\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001"
"read-symbolic-link\376\001\000\000%\001chicken.file.posix#read-symbolic-link\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001dup"
"licate-fileno\376\001\000\000#\001chicken.file.posix#duplicate-fileno\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001fcntl/dupf"
"d\376\001\000\000\036\001chicken.file.posix#fcntl/dupfd\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001fcntl/getfd\376\001\000\000\036\001chicken.fi"
"le.posix#fcntl/getfd\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001fcntl/getfl\376\001\000\000\036\001chicken.file.posix#fcntl/ge"
"tfl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001fcntl/setfd\376\001\000\000\036\001chicken.file.posix#fcntl/setfd\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\013\001fcntl/setfl\376\001\000\000\036\001chicken.file.posix#fcntl/setfl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001file-access-tim"
"e\376\001\000\000#\001chicken.file.posix#file-access-time\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001file-change-time\376\001\000\000#\001"
"chicken.file.posix#file-change-time\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001file-modification-time\376\001\000\000)\001c"
"hicken.file.posix#file-modification-time\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001file-close\376\001\000\000\035\001chicken."
"file.posix#file-close\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001file-control\376\001\000\000\037\001chicken.file.posix#file-c"
"ontrol\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001file-creation-mode\376\001\000\000%\001chicken.file.posix#file-creation-m"
"ode\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001file-group\376\001\000\000\035\001chicken.file.posix#file-group\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001"
"file-link\376\001\000\000\034\001chicken.file.posix#file-link\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001file-lock\376\001\000\000\034\001chicke"
"n.file.posix#file-lock\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001file-lock/blocking\376\001\000\000%\001chicken.file.posix"
"#file-lock/blocking\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001file-mkstemp\376\001\000\000\037\001chicken.file.posix#file-mks"
"temp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001file-open\376\001\000\000\034\001chicken.file.posix#file-open\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001f"
"ile-owner\376\001\000\000\035\001chicken.file.posix#file-owner\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001file-permissions\376\001\000\000"
"#\001chicken.file.posix#file-permissions\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001file-position\376\001\000\000 \001chicken."
"file.posix#file-position\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001file-read\376\001\000\000\034\001chicken.file.posix#file-r"
"ead\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001file-select\376\001\000\000\036\001chicken.file.posix#file-select\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\011\001file-size\376\001\000\000\034\001chicken.file.posix#file-size\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001file-stat\376\001\000\000\034\001chic"
"ken.file.posix#file-stat\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001file-test-lock\376\001\000\000!\001chicken.file.posix#f"
"ile-test-lock\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001file-truncate\376\001\000\000 \001chicken.file.posix#file-truncate"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001file-unlock\376\001\000\000\036\001chicken.file.posix#file-unlock\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001f"
"ile-write\376\001\000\000\035\001chicken.file.posix#file-write\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001file-type\376\001\000\000\034\001chick"
"en.file.posix#file-type\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001block-device\077\376\001\000\000 \001chicken.file.posix#blo"
"ck-device\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001character-device\077\376\001\000\000$\001chicken.file.posix#character-de"
"vice\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001directory\077\376\001\000\000\035\001chicken.file.posix#directory\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\005\001fifo\077\376\001\000\000\030\001chicken.file.posix#fifo\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001regular-file\077\376\001\000\000 \001chicken."
"file.posix#regular-file\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001socket\077\376\001\000\000\032\001chicken.file.posix#socket\077\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001symbolic-link\077\376\001\000\000!\001chicken.file.posix#symbolic-link\077\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\015\001fileno/stderr\376\001\000\000 \001chicken.file.posix#fileno/stderr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001fileno/st"
"din\376\001\000\000\037\001chicken.file.posix#fileno/stdin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001fileno/stdout\376\001\000\000 \001chick"
"en.file.posix#fileno/stdout\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001open-input-file\052\376\001\000\000#\001chicken.file.po"
"six#open-input-file\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001open-output-file\052\376\001\000\000$\001chicken.file.posix#op"
"en-output-file\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001open/append\376\001\000\000\036\001chicken.file.posix#open/append\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\013\001open/binary\376\001\000\000\036\001chicken.file.posix#open/binary\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001ope"
"n/creat\376\001\000\000\035\001chicken.file.posix#open/creat\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001open/excl\376\001\000\000\034\001chicken"
".file.posix#open/excl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001open/fsync\376\001\000\000\035\001chicken.file.posix#open/fsy"
"nc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001open/noctty\376\001\000\000\036\001chicken.file.posix#open/noctty\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016"
"\001open/noinherit\376\001\000\000!\001chicken.file.posix#open/noinherit\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001open/nonbl"
"ock\376\001\000\000 \001chicken.file.posix#open/nonblock\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001open/rdonly\376\001\000\000\036\001chicke"
"n.file.posix#open/rdonly\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001open/rdwr\376\001\000\000\034\001chicken.file.posix#open/r"
"dwr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001open/read\376\001\000\000\034\001chicken.file.posix#open/read\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001op"
"en/sync\376\001\000\000\034\001chicken.file.posix#open/sync\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001open/text\376\001\000\000\034\001chicken."
"file.posix#open/text\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001open/trunc\376\001\000\000\035\001chicken.file.posix#open/trun"
"c\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001open/write\376\001\000\000\035\001chicken.file.posix#open/write\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001op"
"en/wronly\376\001\000\000\036\001chicken.file.posix#open/wronly\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/irgrp\376\001\000\000\035\001chi"
"cken.file.posix#perm/irgrp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/iroth\376\001\000\000\035\001chicken.file.posix#per"
"m/iroth\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/irusr\376\001\000\000\035\001chicken.file.posix#perm/irusr\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\012\001perm/irwxg\376\001\000\000\035\001chicken.file.posix#perm/irwxg\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/irwxo\376\001\000\000\035"
"\001chicken.file.posix#perm/irwxo\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/irwxu\376\001\000\000\035\001chicken.file.posix"
"#perm/irwxu\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/isgid\376\001\000\000\035\001chicken.file.posix#perm/isgid\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\012\001perm/isuid\376\001\000\000\035\001chicken.file.posix#perm/isuid\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/isvtx\376"
"\001\000\000\035\001chicken.file.posix#perm/isvtx\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/iwgrp\376\001\000\000\035\001chicken.file.p"
"osix#perm/iwgrp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/iwoth\376\001\000\000\035\001chicken.file.posix#perm/iwoth\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\012\001perm/iwusr\376\001\000\000\035\001chicken.file.posix#perm/iwusr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/ix"
"grp\376\001\000\000\035\001chicken.file.posix#perm/ixgrp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/ixoth\376\001\000\000\035\001chicken.fi"
"le.posix#perm/ixoth\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001perm/ixusr\376\001\000\000\035\001chicken.file.posix#perm/ixusr"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001port->fileno\376\001\000\000\037\001chicken.file.posix#port->fileno\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017"
"\001set-file-group!\376\001\000\000\042\001chicken.file.posix#set-file-group!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001set-file"
"-owner!\376\001\000\000\042\001chicken.file.posix#set-file-owner!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001set-file-permissi"
"ons!\376\001\000\000(\001chicken.file.posix#set-file-permissions!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001set-file-posit"
"ion!\376\001\000\000%\001chicken.file.posix#set-file-position!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001set-file-times!\376\001"
"\000\000\042\001chicken.file.posix#set-file-times!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001seek/cur\376\001\000\000\033\001chicken.file"
".posix#seek/cur\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001seek/set\376\001\000\000\033\001chicken.file.posix#seek/set\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\010\001seek/end\376\001\000\000\033\001chicken.file.posix#seek/end\376\377\016"));
lf[50]=C_h_intern(&lf[50],14, C_text("chicken.flonum"));
lf[51]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001flonum-print-precision\376\001\000\000%\001chicken.flonum#flonum-print-precisio"
"n\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001fpinteger\077\376\001\000\000\031\001chicken.flonum#fpinteger\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpabs\376"
"\001\000\000\024\001chicken.flonum#fpabs\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fpsqrt\376\001\000\000\025\001chicken.flonum#fpsqrt\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\005\001fplog\376\001\000\000\024\001chicken.flonum#fplog\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fpexpt\376\001\000\000\025\001chicken.flo"
"num#fpexpt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpexp\376\001\000\000\024\001chicken.flonum#fpexp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fpatanh"
"\376\001\000\000\026\001chicken.flonum#fpatanh\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fpacosh\376\001\000\000\026\001chicken.flonum#fpacosh\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fpasinh\376\001\000\000\026\001chicken.flonum#fpasinh\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fptanh\376\001\000\000\025\001ch"
"icken.flonum#fptanh\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fpcosh\376\001\000\000\025\001chicken.flonum#fpcosh\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\006\001fpsinh\376\001\000\000\025\001chicken.flonum#fpsinh\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fpatan2\376\001\000\000\026\001chicken.flonum"
"#fpatan2\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fpatan\376\001\000\000\025\001chicken.flonum#fpatan\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fpacos\376"
"\001\000\000\025\001chicken.flonum#fpacos\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001fpasin\376\001\000\000\025\001chicken.flonum#fpasin\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\005\001fptan\376\001\000\000\024\001chicken.flonum#fptan\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpcos\376\001\000\000\024\001chicken.flo"
"num#fpcos\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpsin\376\001\000\000\024\001chicken.flonum#fpsin\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001fpceilin"
"g\376\001\000\000\030\001chicken.flonum#fpceiling\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fpround\376\001\000\000\026\001chicken.flonum#fprou"
"nd\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001fptruncate\376\001\000\000\031\001chicken.flonum#fptruncate\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fpflo"
"or\376\001\000\000\026\001chicken.flonum#fpfloor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpmin\376\001\000\000\024\001chicken.flonum#fpmin\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\005\001fpmax\376\001\000\000\024\001chicken.flonum#fpmax\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpneg\376\001\000\000\024\001chicken.f"
"lonum#fpneg\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fp<=\376\001\000\000\023\001chicken.flonum#fp<=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fp>=\376\001\000\000"
"\023\001chicken.flonum#fp>=\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fp<\376\001\000\000\022\001chicken.flonum#fp<\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001"
"fp>\376\001\000\000\022\001chicken.flonum#fp>\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fp=\376\001\000\000\022\001chicken.flonum#fp=\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\004\001fp/\077\376\001\000\000\023\001chicken.flonum#fp/\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001fpgcd\376\001\000\000\024\001chicken.flonum#fpg"
"cd\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001fp\052+\376\001\000\000\023\001chicken.flonum#fp\052+\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fp/\376\001\000\000\022\001chicken."
"flonum#fp/\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fp\052\376\001\000\000\022\001chicken.flonum#fp\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fp-\376\001\000\000\022\001ch"
"icken.flonum#fp-\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001fp+\376\001\000\000\022\001chicken.flonum#fp+\376\003\000\000\002\376\003\000\000\002\376\001\000\000\037\001flonu"
"m-minimum-decimal-exponent\376\001\000\000.\001chicken.flonum#flonum-minimum-decimal-exponent\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\037\001flonum-maximum-decimal-exponent\376\001\000\000.\001chicken.flonum#flonum-maximum"
"-decimal-exponent\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001flonum-minimum-exponent\376\001\000\000&\001chicken.flonum#flo"
"num-minimum-exponent\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001flonum-maximum-exponent\376\001\000\000&\001chicken.flonum#"
"flonum-maximum-exponent\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001flonum-decimal-precision\376\001\000\000\047\001chicken.flo"
"num#flonum-decimal-precision\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001flonum-precision\376\001\000\000\037\001chicken.flonum"
"#flonum-precision\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001flonum-epsilon\376\001\000\000\035\001chicken.flonum#flonum-epsil"
"on\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001flonum-radix\376\001\000\000\033\001chicken.flonum#flonum-radix\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001m"
"inimum-flonum\376\001\000\000\035\001chicken.flonum#minimum-flonum\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001maximum-flonum\376\001"
"\000\000\035\001chicken.flonum#maximum-flonum\376\377\016"));
lf[52]=C_h_intern(&lf[52],14, C_text("chicken.format"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001format\376\001\000\000\025\001chicken.format#format\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001fprintf\376\001\000\000\026\001ch"
"icken.format#fprintf\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001printf\376\001\000\000\025\001chicken.format#printf\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\007\001sprintf\376\001\000\000\026\001chicken.format#sprintf\376\377\016"));
lf[54]=C_h_intern(&lf[54],10, C_text("chicken.gc"));
lf[55]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001current-gc-milliseconds\376\001\000\000\042\001chicken.gc#current-gc-milliseconds\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001gc\376\001\000\000\015\001chicken.gc#gc\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001memory-statistics\376\001\000\000\034\001chick"
"en.gc#memory-statistics\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001set-finalizer!\376\001\000\000\031\001chicken.gc#set-finali"
"zer!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-finalizer\376\001\000\000\031\001chicken.gc#make-finalizer\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020"
"\001add-to-finalizer\376\001\000\000\033\001chicken.gc#add-to-finalizer\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001set-gc-report!"
"\376\001\000\000\031\001chicken.gc#set-gc-report!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001force-finalizers\376\001\000\000\033\001chicken.gc#"
"force-finalizers\376\377\016"));
lf[56]=C_h_intern(&lf[56],12, C_text("chicken.eval"));
lf[57]=C_h_intern(&lf[57],4, C_text("eval"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001eval-handler\376\001\000\000\031\001chicken.eval#eval-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001modul"
"e-environment\376\001\000\000\037\001chicken.eval#module-environment\376\377\016"));
lf[59]=C_h_intern(&lf[59],12, C_text("chicken.load"));
lf[60]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001dynamic-load-libraries\376\001\000\000#\001chicken.load#dynamic-load-libraries\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001set-dynamic-load-mode!\376\001\000\000#\001chicken.load#set-dynamic-load-mode!\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\014\001load-library\376\001\000\000\031\001chicken.load#load-library\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001load-no"
"isily\376\001\000\000\031\001chicken.load#load-noisily\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001load-relative\376\001\000\000\032\001chicken.l"
"oad#load-relative\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001load-verbose\376\001\000\000\031\001chicken.load#load-verbose\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\007\001provide\376\001\000\000\024\001chicken.load#provide\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001provided\077\376\001\000\000\026\001chic"
"ken.load#provided\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001require\376\001\000\000\024\001chicken.load#require\376\377\016"));
lf[61]=C_h_intern(&lf[61],16, C_text("chicken.locative"));
lf[62]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001locative\077\376\001\000\000\032\001chicken.locative#locative\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001make-lo"
"cative\376\001\000\000\036\001chicken.locative#make-locative\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001make-weak-locative\376\001\000\000"
"#\001chicken.locative#make-weak-locative\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001locative-ref\376\001\000\000\035\001chicken.l"
"ocative#locative-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001locative-set!\376\001\000\000\036\001chicken.locative#locative"
"-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001locative->object\376\001\000\000!\001chicken.locative#locative->object\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\016\001locative-index\376\001\000\000\037\001chicken.locative#locative-index\376\377\016"));
lf[63]=C_h_intern(&lf[63],29, C_text("chicken.memory.representation"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001block-ref\376\001\000\000\047\001chicken.memory.representation#block-ref\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\012\001block-set!\376\001\000\000(\001chicken.memory.representation#block-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001ex"
"tend-procedure\376\001\000\000.\001chicken.memory.representation#extend-procedure\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\023\001extended-procedure\077\376\001\000\0001\001chicken.memory.representation#extended-procedure\077\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\024\001make-record-instance\376\001\000\0002\001chicken.memory.representation#make-record-"
"instance\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001mutate-procedure!\376\001\000\000/\001chicken.memory.representation#mut"
"ate-procedure!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001number-of-bytes\376\001\000\000-\001chicken.memory.representation"
"#number-of-bytes\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001number-of-slots\376\001\000\000-\001chicken.memory.representati"
"on#number-of-slots\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001object-become!\376\001\000\000,\001chicken.memory.representat"
"ion#object-become!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001object-copy\376\001\000\000)\001chicken.memory.representation"
"#object-copy\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001procedure-data\376\001\000\000,\001chicken.memory.representation#pr"
"ocedure-data\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001record->vector\376\001\000\000,\001chicken.memory.representation#re"
"cord->vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001record-instance-length\376\001\000\0004\001chicken.memory.represent"
"ation#record-instance-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001record-instance-slot\376\001\000\0002\001chicken.me"
"mory.representation#record-instance-slot\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001record-instance-slot-set"
"!\376\001\000\0007\001chicken.memory.representation#record-instance-slot-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001re"
"cord-instance-type\376\001\000\0002\001chicken.memory.representation#record-instance-type\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\020\001record-instance\077\376\001\000\000.\001chicken.memory.representation#record-instance\077\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\023\001set-procedure-data!\376\001\000\0001\001chicken.memory.representation#set-procedu"
"re-data!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001vector-like\077\376\001\000\000\052\001chicken.memory.representation#vector-l"
"ike\077\376\377\016"));
lf[65]=C_h_intern(&lf[65],13, C_text("chicken.plist"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\003\001get\376\001\000\000\021\001chicken.plist#get\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001get-properties\376\001\000\000\034\001ch"
"icken.plist#get-properties\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001put!\376\001\000\000\022\001chicken.plist#put!\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\010\001remprop!\376\001\000\000\026\001chicken.plist#remprop!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001symbol-plist\376\001\000\000\032\001chic"
"ken.plist#symbol-plist\376\377\016"));
lf[67]=C_h_intern(&lf[67],20, C_text("chicken.pretty-print"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001pp\376\001\000\000\027\001chicken.pretty-print#pp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001pretty-print\376\001\000\000!"
"\001chicken.pretty-print#pretty-print\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001pretty-print-width\376\001\000\000\047\001chicke"
"n.pretty-print#pretty-print-width\376\377\016"));
lf[69]=C_h_intern(&lf[69],15, C_text("chicken.process"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001qs\376\001\000\000\022\001chicken.process#qs\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001system\376\001\000\000\026\001chicken.pr"
"ocess#system\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001system\052\376\001\000\000\027\001chicken.process#system\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001"
"process-execute\376\001\000\000\037\001chicken.process#process-execute\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001process-fork"
"\376\001\000\000\034\001chicken.process#process-fork\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001process-run\376\001\000\000\033\001chicken.proce"
"ss#process-run\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001process-signal\376\001\000\000\036\001chicken.process#process-signal"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001process-spawn\376\001\000\000\035\001chicken.process#process-spawn\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001"
"process-wait\376\001\000\000\034\001chicken.process#process-wait\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001call-with-input-pi"
"pe\376\001\000\000$\001chicken.process#call-with-input-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001call-with-output-pip"
"e\376\001\000\000%\001chicken.process#call-with-output-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001close-input-pipe\376\001\000\000"
" \001chicken.process#close-input-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001close-output-pipe\376\001\000\000!\001chicken"
".process#close-output-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001create-pipe\376\001\000\000\033\001chicken.process#creat"
"e-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001open-input-pipe\376\001\000\000\037\001chicken.process#open-input-pipe\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\020\001open-output-pipe\376\001\000\000 \001chicken.process#open-output-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001"
"with-input-from-pipe\376\001\000\000$\001chicken.process#with-input-from-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001wi"
"th-output-to-pipe\376\001\000\000#\001chicken.process#with-output-to-pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001proces"
"s\376\001\000\000\027\001chicken.process#process\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001process\052\376\001\000\000\030\001chicken.process#proc"
"ess\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001process-sleep\376\001\000\000\035\001chicken.process#process-sleep\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\010\001pipe/buf\376\001\000\000\030\001chicken.process#pipe/buf\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001spawn/overlay\376\001\000\000\035\001chi"
"cken.process#spawn/overlay\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001spawn/wait\376\001\000\000\032\001chicken.process#spawn/"
"wait\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001spawn/nowait\376\001\000\000\034\001chicken.process#spawn/nowait\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\015\001spawn/nowaito\376\001\000\000\035\001chicken.process#spawn/nowaito\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001spawn/detach\376\001"
"\000\000\034\001chicken.process#spawn/detach\376\377\016"));
lf[71]=C_h_intern(&lf[71],22, C_text("chicken.process.signal"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001set-alarm!\376\001\000\000!\001chicken.process.signal#set-alarm!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020"
"\001set-signal-mask!\376\001\000\000\047\001chicken.process.signal#set-signal-mask!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001ma"
"ke-signal-handler\376\001\000\000\052\001chicken.process.signal#make-signal-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015"
"\001signal-ignore\376\001\000\000$\001chicken.process.signal#signal-ignore\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001signal-d"
"efault\376\001\000\000%\001chicken.process.signal#signal-default\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001set-signal-hand"
"ler!\376\001\000\000\052\001chicken.process.signal#set-signal-handler!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001signal-handl"
"er\376\001\000\000%\001chicken.process.signal#signal-handler\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal-mask\376\001\000\000\042\001ch"
"icken.process.signal#signal-mask\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001signal-mask!\376\001\000\000#\001chicken.proces"
"s.signal#signal-mask!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001signal-masked\077\376\001\000\000%\001chicken.process.signal#"
"signal-masked\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001signal-unmask!\376\001\000\000%\001chicken.process.signal#signal-"
"unmask!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/abrt\376\001\000\000\042\001chicken.process.signal#signal/abrt\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\013\001signal/alrm\376\001\000\000\042\001chicken.process.signal#signal/alrm\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001sig"
"nal/break\376\001\000\000#\001chicken.process.signal#signal/break\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001signal/bus\376\001\000\000"
"!\001chicken.process.signal#signal/bus\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/chld\376\001\000\000\042\001chicken.proc"
"ess.signal#signal/chld\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/cont\376\001\000\000\042\001chicken.process.signal#si"
"gnal/cont\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001signal/fpe\376\001\000\000!\001chicken.process.signal#signal/fpe\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\012\001signal/hup\376\001\000\000!\001chicken.process.signal#signal/hup\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001signa"
"l/ill\376\001\000\000!\001chicken.process.signal#signal/ill\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001signal/int\376\001\000\000!\001chic"
"ken.process.signal#signal/int\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001signal/io\376\001\000\000 \001chicken.process.sign"
"al#signal/io\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/kill\376\001\000\000\042\001chicken.process.signal#signal/kill\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/pipe\376\001\000\000\042\001chicken.process.signal#signal/pipe\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\013\001signal/prof\376\001\000\000\042\001chicken.process.signal#signal/prof\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/quit"
"\376\001\000\000\042\001chicken.process.signal#signal/quit\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/segv\376\001\000\000\042\001chicken"
".process.signal#signal/segv\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/stop\376\001\000\000\042\001chicken.process.sign"
"al#signal/stop\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/term\376\001\000\000\042\001chicken.process.signal#signal/ter"
"m\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/trap\376\001\000\000\042\001chicken.process.signal#signal/trap\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\013\001signal/tstp\376\001\000\000\042\001chicken.process.signal#signal/tstp\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001signal/ur"
"g\376\001\000\000!\001chicken.process.signal#signal/urg\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/usr1\376\001\000\000\042\001chicken"
".process.signal#signal/usr1\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001signal/usr2\376\001\000\000\042\001chicken.process.sign"
"al#signal/usr2\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001signal/vtalrm\376\001\000\000$\001chicken.process.signal#signal/v"
"talrm\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001signal/winch\376\001\000\000#\001chicken.process.signal#signal/winch\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\013\001signal/xcpu\376\001\000\000\042\001chicken.process.signal#signal/xcpu\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001sig"
"nal/xfsz\376\001\000\000\042\001chicken.process.signal#signal/xfsz\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001signals-list\376\001\000\000"
"#\001chicken.process.signal#signals-list\376\377\016"));
lf[73]=C_h_intern(&lf[73],23, C_text("chicken.process-context"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001argv\376\001\000\000\034\001chicken.process-context#argv\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001argc+argv\376"
"\001\000\000!\001chicken.process-context#argc+argv\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001command-line-arguments\376\001\000\000"
".\001chicken.process-context#command-line-arguments\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001program-name\376\001\000\000"
"$\001chicken.process-context#program-name\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001executable-pathname\376\001\000\000+\001c"
"hicken.process-context#executable-pathname\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001change-directory\376\001\000\000(\001"
"chicken.process-context#change-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001current-directory\376\001\000\000)\001c"
"hicken.process-context#current-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\030\001get-environment-variable"
"\376\001\000\0000\001chicken.process-context#get-environment-variable\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001get-enviro"
"nment-variables\376\001\000\0001\001chicken.process-context#get-environment-variables\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\031\001set-environment-variable!\376\001\000\0001\001chicken.process-context#set-environment-var"
"iable!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001unset-environment-variable!\376\001\000\0003\001chicken.process-context#u"
"nset-environment-variable!\376\377\016"));
lf[75]=C_h_intern(&lf[75],29, C_text("chicken.process-context.posix"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001change-directory\052\376\001\000\000/\001chicken.process-context.posix#change-dire"
"ctory\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001set-root-directory!\376\001\000\0001\001chicken.process-context.posix#set"
"-root-directory!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\032\001current-effective-group-id\376\001\000\0008\001chicken.process-"
"context.posix#current-effective-group-id\376\003\000\000\002\376\003\000\000\002\376\001\000\000\031\001current-effective-user-i"
"d\376\001\000\0007\001chicken.process-context.posix#current-effective-user-id\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001cu"
"rrent-process-id\376\001\000\0000\001chicken.process-context.posix#current-process-id\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\020\001current-group-id\376\001\000\000.\001chicken.process-context.posix#current-group-id\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\017\001current-user-id\376\001\000\000-\001chicken.process-context.posix#current-user-id\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\021\001parent-process-id\376\001\000\000/\001chicken.process-context.posix#parent-process-"
"id\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001current-user-name\376\001\000\000/\001chicken.process-context.posix#current-u"
"ser-name\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001current-effective-user-name\376\001\000\0009\001chicken.process-context"
".posix#current-effective-user-name\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001create-session\376\001\000\000,\001chicken.pr"
"ocess-context.posix#create-session\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001process-group-id\376\001\000\000.\001chicken."
"process-context.posix#process-group-id\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001user-information\376\001\000\000.\001chic"
"ken.process-context.posix#user-information\376\377\016"));
lf[77]=C_h_intern(&lf[77],14, C_text("chicken.random"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\027\001set-pseudo-random-seed!\376\001\000\000&\001chicken.random#set-pseudo-random-se"
"ed!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001pseudo-random-integer\376\001\000\000$\001chicken.random#pseudo-random-integ"
"er\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001pseudo-random-real\376\001\000\000!\001chicken.random#pseudo-random-real\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\014\001random-bytes\376\001\000\000\033\001chicken.random#random-bytes\376\377\016"));
lf[79]=C_h_intern(&lf[79],12, C_text("chicken.sort"));
lf[80]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001merge\376\001\000\000\022\001chicken.sort#merge\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001merge!\376\001\000\000\023\001chicken"
".sort#merge!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001sort\376\001\000\000\021\001chicken.sort#sort\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001sort!\376\001\000\000"
"\022\001chicken.sort#sort!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001sorted\077\376\001\000\000\024\001chicken.sort#sorted\077\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\020\001topological-sort\376\001\000\000\035\001chicken.sort#topological-sort\376\377\016"));
lf[81]=C_h_intern(&lf[81],18, C_text("chicken.time.posix"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001seconds->utc-time\376\001\000\000$\001chicken.time.posix#seconds->utc-time\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\021\001utc-time->seconds\376\001\000\000$\001chicken.time.posix#utc-time->seconds\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\023\001seconds->local-time\376\001\000\000&\001chicken.time.posix#seconds->local-time\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\017\001seconds->string\376\001\000\000\042\001chicken.time.posix#seconds->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001loca"
"l-time->seconds\376\001\000\000&\001chicken.time.posix#local-time->seconds\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001strin"
"g->time\376\001\000\000\037\001chicken.time.posix#string->time\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001time->string\376\001\000\000\037\001ch"
"icken.time.posix#time->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\033\001local-timezone-abbreviation\376\001\000\000.\001ch"
"icken.time.posix#local-timezone-abbreviation\376\377\016"));
lf[83]=C_h_intern(&lf[83],20, C_text("chicken.continuation"));
lf[84]=C_h_intern(&lf[84],12, C_text("continuation"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001continuation\077\376\001\000\000\042\001chicken.continuation#continuation\077\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\024\001continuation-capture\376\001\000\000)\001chicken.continuation#continuation-capture\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\022\001continuation-graft\376\001\000\000\047\001chicken.continuation#continuation-graft\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\023\001continuation-return\376\001\000\000(\001chicken.continuation#continuation-return\376\377\016"));
lf[86]=C_h_intern(&lf[86],12, C_text("chicken.file"));
lf[87]=C_h_intern(&lf[87],4, C_text("file"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001create-directory\376\001\000\000\035\001chicken.file#create-directory\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\020\001delete-directory\376\001\000\000\035\001chicken.file#delete-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001create-tem"
"porary-file\376\001\000\000\042\001chicken.file#create-temporary-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\032\001create-tempor"
"ary-directory\376\001\000\000\047\001chicken.file#create-temporary-directory\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001delete"
"-file\376\001\000\000\030\001chicken.file#delete-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001delete-file\052\376\001\000\000\031\001chicken.fil"
"e#delete-file\052\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001copy-file\376\001\000\000\026\001chicken.file#copy-file\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\011\001move-file\376\001\000\000\026\001chicken.file#move-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001rename-file\376\001\000\000\030\001chicken"
".file#rename-file\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001file-exists\077\376\001\000\000\031\001chicken.file#file-exists\077\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\021\001directory-exists\077\376\001\000\000\036\001chicken.file#directory-exists\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016"
"\001file-readable\077\376\001\000\000\033\001chicken.file#file-readable\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001file-writable\077\376\001"
"\000\000\033\001chicken.file#file-writable\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001file-executable\077\376\001\000\000\035\001chicken.fil"
"e#file-executable\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001directory\376\001\000\000\026\001chicken.file#directory\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\012\001find-files\376\001\000\000\027\001chicken.file#find-files\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001glob\376\001\000\000\021\001chicken."
"file#glob\376\377\016"));
lf[89]=C_h_intern(&lf[89],19, C_text("chicken.read-syntax"));
lf[90]=C_h_intern(&lf[90],11, C_text("read-syntax"));
lf[91]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001copy-read-table\376\001\000\000#\001chicken.read-syntax#copy-read-table\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\022\001current-read-table\376\001\000\000&\001chicken.read-syntax#current-read-table\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\022\001define-reader-ctor\376\001\000\000&\001chicken.read-syntax#define-reader-ctor\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\020\001set-read-syntax!\376\001\000\000$\001chicken.read-syntax#set-read-syntax!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001se"
"t-sharp-read-syntax!\376\001\000\000\052\001chicken.read-syntax#set-sharp-read-syntax!\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\036\001set-parameterized-read-syntax!\376\001\000\0002\001chicken.read-syntax#set-parameterized-re"
"ad-syntax!\376\377\016"));
lf[92]=C_h_intern(&lf[92],12, C_text("chicken.repl"));
lf[93]=C_h_intern(&lf[93],4, C_text("repl"));
lf[94]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001quit\376\001\000\000\021\001chicken.repl#quit\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001repl\376\001\000\000\021\001chicken.rep"
"l#repl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001repl-prompt\376\001\000\000\030\001chicken.repl#repl-prompt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001r"
"eset\376\001\000\000\022\001chicken.repl#reset\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001reset-handler\376\001\000\000\032\001chicken.repl#rese"
"t-handler\376\377\016"));
lf[95]=C_h_intern(&lf[95],11, C_text("chicken.tcp"));
lf[96]=C_h_intern(&lf[96],3, C_text("tcp"));
lf[97]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001tcp-close\376\001\000\000\025\001chicken.tcp#tcp-close\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001tcp-listen\376\001"
"\000\000\026\001chicken.tcp#tcp-listen\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001tcp-connect\376\001\000\000\027\001chicken.tcp#tcp-conne"
"ct\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001tcp-accept\376\001\000\000\026\001chicken.tcp#tcp-accept\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001tcp-acce"
"pt-ready\077\376\001\000\000\035\001chicken.tcp#tcp-accept-ready\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001tcp-listener\077\376\001\000\000\031\001c"
"hicken.tcp#tcp-listener\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001tcp-addresses\376\001\000\000\031\001chicken.tcp#tcp-addre"
"sses\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001tcp-abandon-port\376\001\000\000\034\001chicken.tcp#tcp-abandon-port\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\021\001tcp-listener-port\376\001\000\000\035\001chicken.tcp#tcp-listener-port\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001tcp-li"
"stener-fileno\376\001\000\000\037\001chicken.tcp#tcp-listener-fileno\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001tcp-port-numbe"
"rs\376\001\000\000\034\001chicken.tcp#tcp-port-numbers\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001tcp-buffer-size\376\001\000\000\033\001chicken"
".tcp#tcp-buffer-size\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001tcp-read-timeout\376\001\000\000\034\001chicken.tcp#tcp-read-t"
"imeout\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001tcp-write-timeout\376\001\000\000\035\001chicken.tcp#tcp-write-timeout\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\022\001tcp-accept-timeout\376\001\000\000\036\001chicken.tcp#tcp-accept-timeout\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001"
"tcp-connect-timeout\376\001\000\000\037\001chicken.tcp#tcp-connect-timeout\376\377\016"));
lf[98]=C_h_intern(&lf[98],6, C_text("srfi-4"));
lf[99]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->f32vector\376\001\000\000\026\001srfi-4#blob->f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob-"
">f32vector/shared\376\001\000\000\035\001srfi-4#blob->f32vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->f64vec"
"tor\376\001\000\000\026\001srfi-4#blob->f64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->f64vector/shared\376\001\000\000\035\001srfi-"
"4#blob->f64vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->s16vector\376\001\000\000\026\001srfi-4#blob->s16vec"
"tor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->s16vector/shared\376\001\000\000\035\001srfi-4#blob->s16vector/shared\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\017\001blob->s32vector\376\001\000\000\026\001srfi-4#blob->s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->s32"
"vector/shared\376\001\000\000\035\001srfi-4#blob->s32vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->s64vector\376"
"\001\000\000\026\001srfi-4#blob->s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->s64vector/shared\376\001\000\000\035\001srfi-4#bl"
"ob->s64vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001blob->s8vector\376\001\000\000\025\001srfi-4#blob->s8vector\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\025\001blob->s8vector/shared\376\001\000\000\034\001srfi-4#blob->s8vector/shared\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\017\001blob->u16vector\376\001\000\000\026\001srfi-4#blob->u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->u16vector/s"
"hared\376\001\000\000\035\001srfi-4#blob->u16vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->u32vector\376\001\000\000\026\001srf"
"i-4#blob->u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001blob->u32vector/shared\376\001\000\000\035\001srfi-4#blob->u32v"
"ector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001blob->u64vector\376\001\000\000\026\001srfi-4#blob->u64vector\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\026\001blob->u64vector/shared\376\001\000\000\035\001srfi-4#blob->u64vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001"
"blob->u8vector\376\001\000\000\025\001srfi-4#blob->u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001blob->u8vector/shared\376\001"
"\000\000\034\001srfi-4#blob->u8vector/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001f32vector\376\001\000\000\020\001srfi-4#f32vector\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f32vector->blob\376\001\000\000\026\001srfi-4#f32vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001f32vec"
"tor->blob/shared\376\001\000\000\035\001srfi-4#f32vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f32vector->li"
"st\376\001\000\000\026\001srfi-4#f32vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001f32vector-length\376\001\000\000\027\001srfi-4#f32ve"
"ctor-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001f32vector-ref\376\001\000\000\024\001srfi-4#f32vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\016\001f32vector-set!\376\001\000\000\025\001srfi-4#f32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001f32vector\077\376\001\000\000\021\001srfi-"
"4#f32vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001f64vector\376\001\000\000\020\001srfi-4#f64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f64ve"
"ctor->blob\376\001\000\000\026\001srfi-4#f64vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001f64vector->blob/shared\376\001\000\000"
"\035\001srfi-4#f64vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001f64vector->list\376\001\000\000\026\001srfi-4#f64ve"
"ctor->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001f64vector-length\376\001\000\000\027\001srfi-4#f64vector-length\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\015\001f64vector-ref\376\001\000\000\024\001srfi-4#f64vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001f64vector-set!\376\001\000\000"
"\025\001srfi-4#f64vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001f64vector\077\376\001\000\000\021\001srfi-4#f64vector\077\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\010\001s8vector\376\001\000\000\017\001srfi-4#s8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s8vector->blob\376\001\000\000\025\001srfi-4#"
"s8vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001s8vector->blob/shared\376\001\000\000\034\001srfi-4#s8vector->blob/s"
"hared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s8vector->list\376\001\000\000\025\001srfi-4#s8vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s8"
"vector-length\376\001\000\000\026\001srfi-4#s8vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001s8vector-ref\376\001\000\000\023\001srfi-"
"4#s8vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001s8vector-set!\376\001\000\000\024\001srfi-4#s8vector-set!\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\011\001s8vector\077\376\001\000\000\020\001srfi-4#s8vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s16vector\376\001\000\000\020\001srfi-4#s16vec"
"tor\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s16vector->blob\376\001\000\000\026\001srfi-4#s16vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001s1"
"6vector->blob/shared\376\001\000\000\035\001srfi-4#s16vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s16vector"
"->list\376\001\000\000\026\001srfi-4#s16vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001s16vector-length\376\001\000\000\027\001srfi-4#s"
"16vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001s16vector-ref\376\001\000\000\024\001srfi-4#s16vector-ref\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\016\001s16vector-set!\376\001\000\000\025\001srfi-4#s16vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001s16vector\077\376\001\000\000\021\001s"
"rfi-4#s16vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s32vector\376\001\000\000\020\001srfi-4#s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s"
"32vector->blob\376\001\000\000\026\001srfi-4#s32vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001s32vector->blob/shared"
"\376\001\000\000\035\001srfi-4#s32vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s32vector->list\376\001\000\000\026\001srfi-4#s"
"32vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001s32vector-length\376\001\000\000\027\001srfi-4#s32vector-length\376\003\000\000\002"
"\376\003\000\000\002\376\001\000\000\015\001s32vector-ref\376\001\000\000\024\001srfi-4#s32vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s32vector-set!"
"\376\001\000\000\025\001srfi-4#s32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001s32vector\077\376\001\000\000\021\001srfi-4#s32vector\077\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\011\001s64vector\376\001\000\000\020\001srfi-4#s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s64vector->blob\376\001\000\000\026\001"
"srfi-4#s64vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001s64vector->blob/shared\376\001\000\000\035\001srfi-4#s64vect"
"or->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001s64vector->list\376\001\000\000\026\001srfi-4#s64vector->list\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\020\001s64vector-length\376\001\000\000\027\001srfi-4#s64vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001s64vector"
"-ref\376\001\000\000\024\001srfi-4#s64vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001s64vector-set!\376\001\000\000\025\001srfi-4#s64vect"
"or-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001s64vector\077\376\001\000\000\021\001srfi-4#s64vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001u8vector"
"\376\001\000\000\017\001srfi-4#u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u8vector->blob\376\001\000\000\025\001srfi-4#u8vector->blob\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\025\001u8vector->blob/shared\376\001\000\000\034\001srfi-4#u8vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376"
"\001\000\000\016\001u8vector->list\376\001\000\000\025\001srfi-4#u8vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u8vector-length\376\001\000"
"\000\026\001srfi-4#u8vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001u8vector-ref\376\001\000\000\023\001srfi-4#u8vector-ref\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\015\001u8vector-set!\376\001\000\000\024\001srfi-4#u8vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u8vector\077\376\001"
"\000\000\020\001srfi-4#u8vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u16vector\376\001\000\000\020\001srfi-4#u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\017\001u16vector->blob\376\001\000\000\026\001srfi-4#u16vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001u16vector->blob/sh"
"ared\376\001\000\000\035\001srfi-4#u16vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u16vector->list\376\001\000\000\026\001srfi"
"-4#u16vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001u16vector-length\376\001\000\000\027\001srfi-4#u16vector-length\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001u16vector-ref\376\001\000\000\024\001srfi-4#u16vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u16vector-"
"set!\376\001\000\000\025\001srfi-4#u16vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001u16vector\077\376\001\000\000\021\001srfi-4#u16vector\077"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u32vector\376\001\000\000\020\001srfi-4#u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u32vector->blob\376\001"
"\000\000\026\001srfi-4#u32vector->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001u32vector->blob/shared\376\001\000\000\035\001srfi-4#u32"
"vector->blob/shared\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u32vector->list\376\001\000\000\026\001srfi-4#u32vector->list\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\020\001u32vector-length\376\001\000\000\027\001srfi-4#u32vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001u32ve"
"ctor-ref\376\001\000\000\024\001srfi-4#u32vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u32vector-set!\376\001\000\000\025\001srfi-4#u32"
"vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001u32vector\077\376\001\000\000\021\001srfi-4#u32vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u64v"
"ector\376\001\000\000\020\001srfi-4#u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u64vector->blob\376\001\000\000\026\001srfi-4#u64vector"
"->blob\376\003\000\000\002\376\003\000\000\002\376\001\000\000\026\001u64vector->blob/shared\376\001\000\000\035\001srfi-4#u64vector->blob/shared\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001u64vector->list\376\001\000\000\026\001srfi-4#u64vector->list\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001u64vec"
"tor-length\376\001\000\000\027\001srfi-4#u64vector-length\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001u64vector-ref\376\001\000\000\024\001srfi-4"
"#u64vector-ref\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001u64vector-set!\376\001\000\000\025\001srfi-4#u64vector-set!\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\012\001u64vector\077\376\001\000\000\021\001srfi-4#u64vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->f32vector\376\001\000\000\026\001srf"
"i-4#list->f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->f64vector\376\001\000\000\026\001srfi-4#list->f64vector\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->s16vector\376\001\000\000\026\001srfi-4#list->s16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->s"
"32vector\376\001\000\000\026\001srfi-4#list->s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->s64vector\376\001\000\000\026\001srfi-4#"
"list->s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001list->s8vector\376\001\000\000\025\001srfi-4#list->s8vector\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\017\001list->u16vector\376\001\000\000\026\001srfi-4#list->u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->u32vect"
"or\376\001\000\000\026\001srfi-4#list->u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001list->u8vector\376\001\000\000\025\001srfi-4#list->u"
"8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\017\001list->u64vector\376\001\000\000\026\001srfi-4#list->u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\016\001make-f32vector\376\001\000\000\025\001srfi-4#make-f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-f64vector\376\001\000\000\025\001s"
"rfi-4#make-f64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-s16vector\376\001\000\000\025\001srfi-4#make-s16vector\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\016\001make-s32vector\376\001\000\000\025\001srfi-4#make-s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-s64ve"
"ctor\376\001\000\000\025\001srfi-4#make-s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001make-s8vector\376\001\000\000\024\001srfi-4#make-s8"
"vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-u16vector\376\001\000\000\025\001srfi-4#make-u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001m"
"ake-u32vector\376\001\000\000\025\001srfi-4#make-u32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001make-u64vector\376\001\000\000\025\001srfi"
"-4#make-u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001make-u8vector\376\001\000\000\024\001srfi-4#make-u8vector\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\016\001number-vector\077\376\001\000\000\025\001srfi-4#number-vector\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001read-u8vector\376\001"
"\000\000\024\001srfi-4#read-u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001read-u8vector!\376\001\000\000\025\001srfi-4#read-u8vector"
"!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001release-number-vector\376\001\000\000\034\001srfi-4#release-number-vector\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\014\001subf32vector\376\001\000\000\023\001srfi-4#subf32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subf64vector\376\001\000\000\023\001s"
"rfi-4#subf64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subs16vector\376\001\000\000\023\001srfi-4#subs16vector\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\014\001subs32vector\376\001\000\000\023\001srfi-4#subs32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subs64vector\376\001\000\000\023\001sr"
"fi-4#subs64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001subs8vector\376\001\000\000\022\001srfi-4#subs8vector\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\014\001subu16vector\376\001\000\000\023\001srfi-4#subu16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001subu8vector\376\001\000\000\022\001srfi-4"
"#subu8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001subu32vector\376\001\000\000\023\001srfi-4#subu32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014"
"\001subu64vector\376\001\000\000\023\001srfi-4#subu64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001write-u8vector\376\001\000\000\025\001srfi-4"
"#write-u8vector\376\377\016"));
lf[100]=C_h_intern(&lf[100],25, C_text("##sys#import-library-hook"));
C_register_lf2(lf,101,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_459,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[79] = {
{C_text("f_1011:eval_2dmodules_2escm"),(void*)f_1011},
{C_text("f_1017:eval_2dmodules_2escm"),(void*)f_1017},
{C_text("f_1039:eval_2dmodules_2escm"),(void*)f_1039},
{C_text("f_1045:eval_2dmodules_2escm"),(void*)f_1045},
{C_text("f_1067:eval_2dmodules_2escm"),(void*)f_1067},
{C_text("f_1073:eval_2dmodules_2escm"),(void*)f_1073},
{C_text("f_1095:eval_2dmodules_2escm"),(void*)f_1095},
{C_text("f_1101:eval_2dmodules_2escm"),(void*)f_1101},
{C_text("f_1123:eval_2dmodules_2escm"),(void*)f_1123},
{C_text("f_1129:eval_2dmodules_2escm"),(void*)f_1129},
{C_text("f_1151:eval_2dmodules_2escm"),(void*)f_1151},
{C_text("f_1157:eval_2dmodules_2escm"),(void*)f_1157},
{C_text("f_1179:eval_2dmodules_2escm"),(void*)f_1179},
{C_text("f_1185:eval_2dmodules_2escm"),(void*)f_1185},
{C_text("f_1207:eval_2dmodules_2escm"),(void*)f_1207},
{C_text("f_1213:eval_2dmodules_2escm"),(void*)f_1213},
{C_text("f_1235:eval_2dmodules_2escm"),(void*)f_1235},
{C_text("f_1241:eval_2dmodules_2escm"),(void*)f_1241},
{C_text("f_1263:eval_2dmodules_2escm"),(void*)f_1263},
{C_text("f_1269:eval_2dmodules_2escm"),(void*)f_1269},
{C_text("f_1291:eval_2dmodules_2escm"),(void*)f_1291},
{C_text("f_1297:eval_2dmodules_2escm"),(void*)f_1297},
{C_text("f_1319:eval_2dmodules_2escm"),(void*)f_1319},
{C_text("f_1325:eval_2dmodules_2escm"),(void*)f_1325},
{C_text("f_1347:eval_2dmodules_2escm"),(void*)f_1347},
{C_text("f_1353:eval_2dmodules_2escm"),(void*)f_1353},
{C_text("f_1375:eval_2dmodules_2escm"),(void*)f_1375},
{C_text("f_1381:eval_2dmodules_2escm"),(void*)f_1381},
{C_text("f_1403:eval_2dmodules_2escm"),(void*)f_1403},
{C_text("f_1409:eval_2dmodules_2escm"),(void*)f_1409},
{C_text("f_1431:eval_2dmodules_2escm"),(void*)f_1431},
{C_text("f_1437:eval_2dmodules_2escm"),(void*)f_1437},
{C_text("f_1459:eval_2dmodules_2escm"),(void*)f_1459},
{C_text("f_1465:eval_2dmodules_2escm"),(void*)f_1465},
{C_text("f_1487:eval_2dmodules_2escm"),(void*)f_1487},
{C_text("f_459:eval_2dmodules_2escm"),(void*)f_459},
{C_text("f_461:eval_2dmodules_2escm"),(void*)f_461},
{C_text("f_467:eval_2dmodules_2escm"),(void*)f_467},
{C_text("f_489:eval_2dmodules_2escm"),(void*)f_489},
{C_text("f_495:eval_2dmodules_2escm"),(void*)f_495},
{C_text("f_517:eval_2dmodules_2escm"),(void*)f_517},
{C_text("f_523:eval_2dmodules_2escm"),(void*)f_523},
{C_text("f_529:eval_2dmodules_2escm"),(void*)f_529},
{C_text("f_551:eval_2dmodules_2escm"),(void*)f_551},
{C_text("f_557:eval_2dmodules_2escm"),(void*)f_557},
{C_text("f_579:eval_2dmodules_2escm"),(void*)f_579},
{C_text("f_585:eval_2dmodules_2escm"),(void*)f_585},
{C_text("f_607:eval_2dmodules_2escm"),(void*)f_607},
{C_text("f_613:eval_2dmodules_2escm"),(void*)f_613},
{C_text("f_635:eval_2dmodules_2escm"),(void*)f_635},
{C_text("f_641:eval_2dmodules_2escm"),(void*)f_641},
{C_text("f_663:eval_2dmodules_2escm"),(void*)f_663},
{C_text("f_669:eval_2dmodules_2escm"),(void*)f_669},
{C_text("f_675:eval_2dmodules_2escm"),(void*)f_675},
{C_text("f_697:eval_2dmodules_2escm"),(void*)f_697},
{C_text("f_703:eval_2dmodules_2escm"),(void*)f_703},
{C_text("f_725:eval_2dmodules_2escm"),(void*)f_725},
{C_text("f_731:eval_2dmodules_2escm"),(void*)f_731},
{C_text("f_753:eval_2dmodules_2escm"),(void*)f_753},
{C_text("f_759:eval_2dmodules_2escm"),(void*)f_759},
{C_text("f_781:eval_2dmodules_2escm"),(void*)f_781},
{C_text("f_787:eval_2dmodules_2escm"),(void*)f_787},
{C_text("f_809:eval_2dmodules_2escm"),(void*)f_809},
{C_text("f_815:eval_2dmodules_2escm"),(void*)f_815},
{C_text("f_821:eval_2dmodules_2escm"),(void*)f_821},
{C_text("f_843:eval_2dmodules_2escm"),(void*)f_843},
{C_text("f_849:eval_2dmodules_2escm"),(void*)f_849},
{C_text("f_871:eval_2dmodules_2escm"),(void*)f_871},
{C_text("f_877:eval_2dmodules_2escm"),(void*)f_877},
{C_text("f_899:eval_2dmodules_2escm"),(void*)f_899},
{C_text("f_905:eval_2dmodules_2escm"),(void*)f_905},
{C_text("f_927:eval_2dmodules_2escm"),(void*)f_927},
{C_text("f_933:eval_2dmodules_2escm"),(void*)f_933},
{C_text("f_955:eval_2dmodules_2escm"),(void*)f_955},
{C_text("f_961:eval_2dmodules_2escm"),(void*)f_961},
{C_text("f_983:eval_2dmodules_2escm"),(void*)f_983},
{C_text("f_989:eval_2dmodules_2escm"),(void*)f_989},
{C_text("toplevel:eval_2dmodules_2escm"),(void*)C_eval_2dmodules_toplevel},
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
(o e)|safe calls: 145 
o|inlining procedure: k1489 
o|contracted procedure: "(eval-modules.scm:100) g307308" 
o|inlining procedure: k1489 
o|replaced variables: 222 
o|removed binding forms: 3 
o|replaced variables: 2 
o|removed binding forms: 223 
o|removed binding forms: 2 
o|simplifications: ((##core#call . 144)) 
o|  call simplifications:
o|    scheme#list	144
o|contracted procedure: k473 
o|contracted procedure: k477 
o|contracted procedure: k481 
o|contracted procedure: k485 
o|contracted procedure: k501 
o|contracted procedure: k505 
o|contracted procedure: k509 
o|contracted procedure: k513 
o|contracted procedure: k535 
o|contracted procedure: k539 
o|contracted procedure: k543 
o|contracted procedure: k547 
o|contracted procedure: k563 
o|contracted procedure: k567 
o|contracted procedure: k571 
o|contracted procedure: k575 
o|contracted procedure: k591 
o|contracted procedure: k595 
o|contracted procedure: k599 
o|contracted procedure: k603 
o|contracted procedure: k619 
o|contracted procedure: k623 
o|contracted procedure: k627 
o|contracted procedure: k631 
o|contracted procedure: k647 
o|contracted procedure: k651 
o|contracted procedure: k655 
o|contracted procedure: k659 
o|contracted procedure: k681 
o|contracted procedure: k685 
o|contracted procedure: k689 
o|contracted procedure: k693 
o|contracted procedure: k709 
o|contracted procedure: k713 
o|contracted procedure: k717 
o|contracted procedure: k721 
o|contracted procedure: k737 
o|contracted procedure: k741 
o|contracted procedure: k745 
o|contracted procedure: k749 
o|contracted procedure: k765 
o|contracted procedure: k769 
o|contracted procedure: k773 
o|contracted procedure: k777 
o|contracted procedure: k793 
o|contracted procedure: k797 
o|contracted procedure: k801 
o|contracted procedure: k805 
o|contracted procedure: k827 
o|contracted procedure: k831 
o|contracted procedure: k835 
o|contracted procedure: k839 
o|contracted procedure: k855 
o|contracted procedure: k859 
o|contracted procedure: k863 
o|contracted procedure: k867 
o|contracted procedure: k883 
o|contracted procedure: k887 
o|contracted procedure: k891 
o|contracted procedure: k895 
o|contracted procedure: k911 
o|contracted procedure: k915 
o|contracted procedure: k919 
o|contracted procedure: k923 
o|contracted procedure: k939 
o|contracted procedure: k943 
o|contracted procedure: k947 
o|contracted procedure: k951 
o|contracted procedure: k967 
o|contracted procedure: k971 
o|contracted procedure: k975 
o|contracted procedure: k979 
o|contracted procedure: k995 
o|contracted procedure: k999 
o|contracted procedure: k1003 
o|contracted procedure: k1007 
o|contracted procedure: k1023 
o|contracted procedure: k1027 
o|contracted procedure: k1031 
o|contracted procedure: k1035 
o|contracted procedure: k1051 
o|contracted procedure: k1055 
o|contracted procedure: k1059 
o|contracted procedure: k1063 
o|contracted procedure: k1079 
o|contracted procedure: k1083 
o|contracted procedure: k1087 
o|contracted procedure: k1091 
o|contracted procedure: k1107 
o|contracted procedure: k1111 
o|contracted procedure: k1115 
o|contracted procedure: k1119 
o|contracted procedure: k1135 
o|contracted procedure: k1139 
o|contracted procedure: k1143 
o|contracted procedure: k1147 
o|contracted procedure: k1163 
o|contracted procedure: k1167 
o|contracted procedure: k1171 
o|contracted procedure: k1175 
o|contracted procedure: k1191 
o|contracted procedure: k1195 
o|contracted procedure: k1199 
o|contracted procedure: k1203 
o|contracted procedure: k1219 
o|contracted procedure: k1223 
o|contracted procedure: k1227 
o|contracted procedure: k1231 
o|contracted procedure: k1247 
o|contracted procedure: k1251 
o|contracted procedure: k1255 
o|contracted procedure: k1259 
o|contracted procedure: k1275 
o|contracted procedure: k1279 
o|contracted procedure: k1283 
o|contracted procedure: k1287 
o|contracted procedure: k1303 
o|contracted procedure: k1307 
o|contracted procedure: k1311 
o|contracted procedure: k1315 
o|contracted procedure: k1331 
o|contracted procedure: k1335 
o|contracted procedure: k1339 
o|contracted procedure: k1343 
o|contracted procedure: k1359 
o|contracted procedure: k1363 
o|contracted procedure: k1367 
o|contracted procedure: k1371 
o|contracted procedure: k1387 
o|contracted procedure: k1391 
o|contracted procedure: k1395 
o|contracted procedure: k1399 
o|contracted procedure: k1415 
o|contracted procedure: k1419 
o|contracted procedure: k1423 
o|contracted procedure: k1427 
o|contracted procedure: k1443 
o|contracted procedure: k1447 
o|contracted procedure: k1451 
o|contracted procedure: k1455 
o|contracted procedure: k1471 
o|contracted procedure: k1475 
o|contracted procedure: k1479 
o|contracted procedure: k1483 
o|removed binding forms: 144 
o|substituted constant variable: r474 
o|substituted constant variable: r478 
o|substituted constant variable: r482 
o|substituted constant variable: r486 
o|substituted constant variable: r502 
o|substituted constant variable: r506 
o|substituted constant variable: r510 
o|substituted constant variable: r514 
o|substituted constant variable: r536 
o|substituted constant variable: r540 
o|substituted constant variable: r544 
o|substituted constant variable: r548 
o|substituted constant variable: r564 
o|substituted constant variable: r568 
o|substituted constant variable: r572 
o|substituted constant variable: r576 
o|substituted constant variable: r592 
o|substituted constant variable: r596 
o|substituted constant variable: r600 
o|substituted constant variable: r604 
o|substituted constant variable: r620 
o|substituted constant variable: r624 
o|substituted constant variable: r628 
o|substituted constant variable: r632 
o|substituted constant variable: r648 
o|substituted constant variable: r652 
o|substituted constant variable: r656 
o|substituted constant variable: r660 
o|substituted constant variable: r682 
o|substituted constant variable: r686 
o|substituted constant variable: r690 
o|substituted constant variable: r694 
o|substituted constant variable: r710 
o|substituted constant variable: r714 
o|substituted constant variable: r718 
o|substituted constant variable: r722 
o|substituted constant variable: r738 
o|substituted constant variable: r742 
o|substituted constant variable: r746 
o|substituted constant variable: r750 
o|substituted constant variable: r766 
o|substituted constant variable: r770 
o|substituted constant variable: r774 
o|substituted constant variable: r778 
o|substituted constant variable: r794 
o|substituted constant variable: r798 
o|substituted constant variable: r802 
o|substituted constant variable: r806 
o|substituted constant variable: r828 
o|substituted constant variable: r832 
o|substituted constant variable: r836 
o|substituted constant variable: r840 
o|substituted constant variable: r856 
o|substituted constant variable: r860 
o|substituted constant variable: r864 
o|substituted constant variable: r868 
o|substituted constant variable: r884 
o|substituted constant variable: r888 
o|substituted constant variable: r892 
o|substituted constant variable: r896 
o|substituted constant variable: r912 
o|substituted constant variable: r916 
o|substituted constant variable: r920 
o|substituted constant variable: r924 
o|substituted constant variable: r940 
o|substituted constant variable: r944 
o|substituted constant variable: r948 
o|substituted constant variable: r952 
o|substituted constant variable: r968 
o|substituted constant variable: r972 
o|substituted constant variable: r976 
o|substituted constant variable: r980 
o|substituted constant variable: r996 
o|substituted constant variable: r1000 
o|substituted constant variable: r1004 
o|substituted constant variable: r1008 
o|substituted constant variable: r1024 
o|substituted constant variable: r1028 
o|substituted constant variable: r1032 
o|substituted constant variable: r1036 
o|substituted constant variable: r1052 
o|substituted constant variable: r1056 
o|substituted constant variable: r1060 
o|substituted constant variable: r1064 
o|substituted constant variable: r1080 
o|substituted constant variable: r1084 
o|substituted constant variable: r1088 
o|substituted constant variable: r1092 
o|substituted constant variable: r1108 
o|substituted constant variable: r1112 
o|substituted constant variable: r1116 
o|substituted constant variable: r1120 
o|substituted constant variable: r1136 
o|substituted constant variable: r1140 
o|substituted constant variable: r1144 
o|substituted constant variable: r1148 
o|substituted constant variable: r1164 
o|substituted constant variable: r1168 
o|substituted constant variable: r1172 
o|substituted constant variable: r1176 
o|substituted constant variable: r1192 
o|substituted constant variable: r1196 
o|substituted constant variable: r1200 
o|substituted constant variable: r1204 
o|substituted constant variable: r1220 
o|substituted constant variable: r1224 
o|substituted constant variable: r1228 
o|substituted constant variable: r1232 
o|substituted constant variable: r1248 
o|substituted constant variable: r1252 
o|substituted constant variable: r1256 
o|substituted constant variable: r1260 
o|substituted constant variable: r1276 
o|substituted constant variable: r1280 
o|substituted constant variable: r1284 
o|substituted constant variable: r1288 
o|substituted constant variable: r1304 
o|substituted constant variable: r1308 
o|substituted constant variable: r1312 
o|substituted constant variable: r1316 
o|substituted constant variable: r1332 
o|substituted constant variable: r1336 
o|substituted constant variable: r1340 
o|substituted constant variable: r1344 
o|substituted constant variable: r1360 
o|substituted constant variable: r1364 
o|substituted constant variable: r1368 
o|substituted constant variable: r1372 
o|substituted constant variable: r1388 
o|substituted constant variable: r1392 
o|substituted constant variable: r1396 
o|substituted constant variable: r1400 
o|substituted constant variable: r1416 
o|substituted constant variable: r1420 
o|substituted constant variable: r1424 
o|substituted constant variable: r1428 
o|substituted constant variable: r1444 
o|substituted constant variable: r1448 
o|substituted constant variable: r1452 
o|substituted constant variable: r1456 
o|substituted constant variable: r1472 
o|substituted constant variable: r1476 
o|substituted constant variable: r1480 
o|substituted constant variable: r1484 
o|removed binding forms: 144 
*/
/* end of file */
