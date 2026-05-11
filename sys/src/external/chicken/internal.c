/* Generated from internal.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: internal.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file internal.c -emit-import-library chicken.internal
   unit: internal
   uses: library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[44];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,53,54,55,32,105,41,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,115,116,114,105,110,103,45,62,99,45,105,100,101,110,116,105,102,105,101,114,32,115,116,114,41,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,118,97,108,105,100,45,108,105,98,114,97,114,121,45,115,112,101,99,105,102,105,101,114,63,32,120,41,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,6),40,102,97,105,108,41,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,24),40,108,105,98,114,97,114,121,45,112,97,114,116,45,62,115,116,114,105,110,103,32,120,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,19),40,100,111,108,111,111,112,54,48,57,32,108,115,116,32,115,116,114,41,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,108,105,98,114,97,114,121,45,105,100,32,108,105,98,41,0,0,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,109,111,100,117,108,101,45,114,101,113,117,105,114,101,109,101,110,116,32,105,100,41};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,21),40,108,111,111,112,32,98,115,32,115,101,101,110,32,119,97,114,110,101,100,41,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,64),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,99,104,101,99,107,45,102,111,114,45,109,117,108,116,105,112,108,101,45,98,105,110,100,105,110,103,115,32,98,105,110,100,105,110,103,115,32,102,111,114,109,32,108,111,99,41};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,109,97,99,114,111,45,115,117,98,115,101,116,32,109,101,48,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,11),40,103,54,55,50,32,115,100,101,102,41,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,54,55,49,32,103,54,55,56,41,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,102,105,120,117,112,45,109,97,99,114,111,45,101,110,118,105,114,111,110,109,101,110,116,32,115,101,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,104,97,115,104,45,115,121,109,98,111,108,32,110,41};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,109,97,107,101,45,104,97,115,104,45,116,97,98,108,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,104,97,115,104,45,116,97,98,108,101,45,114,101,102,32,104,116,32,107,101,121,41};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,13),40,108,111,111,112,32,98,117,99,107,101,116,41,0,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,104,97,115,104,45,116,97,98,108,101,45,115,101,116,33,32,104,116,32,107,101,121,32,118,97,108,41,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,62),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,104,97,115,104,45,116,97,98,108,101,45,117,112,100,97,116,101,33,32,104,116,32,107,101,121,32,117,112,100,116,102,117,110,99,32,118,97,108,117,102,117,110,99,41,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,13),40,103,55,52,49,32,98,117,99,107,101,116,41,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,55,52,48,32,103,55,52,55,41,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,55,51,53,32,105,41,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,104,97,115,104,45,116,97,98,108,101,45,102,111,114,45,101,97,99,104,32,112,32,104,116,41,0,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,19),40,108,111,111,112,32,108,101,110,32,98,107,116,32,115,105,122,101,41,0,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,35,104,97,115,104,45,116,97,98,108,101,45,115,105,122,101,32,104,116,41,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1014)
static void C_ccall f_1014(C_word c,C_word *av) C_noret;
C_noret_decl(f_1391)
static C_word C_fcall f_1391(C_word t0);
C_noret_decl(f_2294)
static void C_ccall f_2294(C_word c,C_word *av) C_noret;
C_noret_decl(f_2298)
static void C_ccall f_2298(C_word c,C_word *av) C_noret;
C_noret_decl(f_2306)
static void C_fcall f_2306(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2322)
static void C_ccall f_2322(C_word c,C_word *av) C_noret;
C_noret_decl(f_2332)
static void C_fcall f_2332(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2338)
static void C_ccall f_2338(C_word c,C_word *av) C_noret;
C_noret_decl(f_2341)
static void C_ccall f_2341(C_word c,C_word *av) C_noret;
C_noret_decl(f_2348)
static void C_ccall f_2348(C_word c,C_word *av) C_noret;
C_noret_decl(f_2381)
static void C_ccall f_2381(C_word c,C_word *av) C_noret;
C_noret_decl(f_2421)
static void C_ccall f_2421(C_word c,C_word *av) C_noret;
C_noret_decl(f_2424)
static void C_fcall f_2424(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2467)
static void C_fcall f_2467(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2519)
static void C_fcall f_2519(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2526)
static void C_ccall f_2526(C_word c,C_word *av) C_noret;
C_noret_decl(f_2530)
static void C_ccall f_2530(C_word c,C_word *av) C_noret;
C_noret_decl(f_2545)
static void C_ccall f_2545(C_word c,C_word *av) C_noret;
C_noret_decl(f_2547)
static void C_fcall f_2547(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2568)
static void C_ccall f_2568(C_word c,C_word *av) C_noret;
C_noret_decl(f_2572)
static void C_ccall f_2572(C_word c,C_word *av) C_noret;
C_noret_decl(f_2582)
static void C_ccall f_2582(C_word c,C_word *av) C_noret;
C_noret_decl(f_2590)
static void C_ccall f_2590(C_word c,C_word *av) C_noret;
C_noret_decl(f_2596)
static void C_ccall f_2596(C_word c,C_word *av) C_noret;
C_noret_decl(f_2602)
static void C_fcall f_2602(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2615)
static void C_fcall f_2615(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2618)
static void C_ccall f_2618(C_word c,C_word *av) C_noret;
C_noret_decl(f_2635)
static void C_ccall f_2635(C_word c,C_word *av) C_noret;
C_noret_decl(f_2670)
static void C_ccall f_2670(C_word c,C_word *av) C_noret;
C_noret_decl(f_2677)
static void C_ccall f_2677(C_word c,C_word *av) C_noret;
C_noret_decl(f_2684)
static void C_ccall f_2684(C_word c,C_word *av) C_noret;
C_noret_decl(f_2686)
static void C_fcall f_2686(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2707)
static void C_ccall f_2707(C_word c,C_word *av) C_noret;
C_noret_decl(f_2720)
static void C_ccall f_2720(C_word c,C_word *av) C_noret;
C_noret_decl(f_2727)
static void C_ccall f_2727(C_word c,C_word *av) C_noret;
C_noret_decl(f_2728)
static void C_fcall f_2728(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2744)
static void C_ccall f_2744(C_word c,C_word *av) C_noret;
C_noret_decl(f_2767)
static void C_ccall f_2767(C_word c,C_word *av) C_noret;
C_noret_decl(f_2769)
static void C_fcall f_2769(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2779)
static void C_ccall f_2779(C_word c,C_word *av) C_noret;
C_noret_decl(f_2801)
static C_word C_fcall f_2801(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_2816)
static void C_ccall f_2816(C_word c,C_word *av) C_noret;
C_noret_decl(f_2831)
static void C_ccall f_2831(C_word c,C_word *av) C_noret;
C_noret_decl(f_2841)
static C_word C_fcall f_2841(C_word t0,C_word t1);
C_noret_decl(f_2887)
static void C_ccall f_2887(C_word c,C_word *av) C_noret;
C_noret_decl(f_2899)
static void C_fcall f_2899(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2948)
static void C_ccall f_2948(C_word c,C_word *av) C_noret;
C_noret_decl(f_2956)
static void C_ccall f_2956(C_word c,C_word *av) C_noret;
C_noret_decl(f_2960)
static void C_ccall f_2960(C_word c,C_word *av) C_noret;
C_noret_decl(f_2963)
static void C_ccall f_2963(C_word c,C_word *av) C_noret;
C_noret_decl(f_2968)
static void C_ccall f_2968(C_word c,C_word *av) C_noret;
C_noret_decl(f_2974)
static void C_fcall f_2974(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2982)
static void C_fcall f_2982(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3003)
static void C_ccall f_3003(C_word c,C_word *av) C_noret;
C_noret_decl(f_3012)
static void C_fcall f_3012(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3022)
static void C_ccall f_3022(C_word c,C_word *av) C_noret;
C_noret_decl(f_3035)
static void C_ccall f_3035(C_word c,C_word *av) C_noret;
C_noret_decl(f_3045)
static void C_fcall f_3045(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3067)
static void C_ccall f_3067(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externexport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_2306)
static void C_ccall trf_2306(C_word c,C_word *av) C_noret;
static void C_ccall trf_2306(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2306(t0,t1,t2);}

C_noret_decl(trf_2332)
static void C_ccall trf_2332(C_word c,C_word *av) C_noret;
static void C_ccall trf_2332(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2332(t0,t1);}

C_noret_decl(trf_2424)
static void C_ccall trf_2424(C_word c,C_word *av) C_noret;
static void C_ccall trf_2424(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2424(t0,t1);}

C_noret_decl(trf_2467)
static void C_ccall trf_2467(C_word c,C_word *av) C_noret;
static void C_ccall trf_2467(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2467(t0,t1,t2);}

C_noret_decl(trf_2519)
static void C_ccall trf_2519(C_word c,C_word *av) C_noret;
static void C_ccall trf_2519(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2519(t0,t1);}

C_noret_decl(trf_2547)
static void C_ccall trf_2547(C_word c,C_word *av) C_noret;
static void C_ccall trf_2547(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2547(t0,t1,t2,t3);}

C_noret_decl(trf_2602)
static void C_ccall trf_2602(C_word c,C_word *av) C_noret;
static void C_ccall trf_2602(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2602(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2615)
static void C_ccall trf_2615(C_word c,C_word *av) C_noret;
static void C_ccall trf_2615(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2615(t0,t1);}

C_noret_decl(trf_2686)
static void C_ccall trf_2686(C_word c,C_word *av) C_noret;
static void C_ccall trf_2686(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2686(t0,t1,t2);}

C_noret_decl(trf_2728)
static void C_ccall trf_2728(C_word c,C_word *av) C_noret;
static void C_ccall trf_2728(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2728(t0,t1,t2);}

C_noret_decl(trf_2769)
static void C_ccall trf_2769(C_word c,C_word *av) C_noret;
static void C_ccall trf_2769(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2769(t0,t1,t2);}

C_noret_decl(trf_2899)
static void C_ccall trf_2899(C_word c,C_word *av) C_noret;
static void C_ccall trf_2899(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2899(t0,t1,t2);}

C_noret_decl(trf_2974)
static void C_ccall trf_2974(C_word c,C_word *av) C_noret;
static void C_ccall trf_2974(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2974(t0,t1,t2);}

C_noret_decl(trf_2982)
static void C_ccall trf_2982(C_word c,C_word *av) C_noret;
static void C_ccall trf_2982(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2982(t0,t1,t2);}

C_noret_decl(trf_3012)
static void C_ccall trf_3012(C_word c,C_word *av) C_noret;
static void C_ccall trf_3012(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3012(t0,t1,t2);}

C_noret_decl(trf_3045)
static void C_ccall trf_3045(C_word c,C_word *av) C_noret;
static void C_ccall trf_3045(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3045(t0,t1,t2,t3,t4);}

/* k1012 */
static void C_ccall f_1014(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(49,c,6)))){
C_save_and_reclaim((void *)f_1014,c,av);}
a=C_alloc(49);
t2=C_mutate((C_word*)lf[2]+1 /* (set! chicken.internal#string->c-identifier ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2294,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[8]+1 /* (set! chicken.internal#valid-library-specifier? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2381,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[9]+1 /* (set! chicken.internal#library-id ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2421,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[19]+1 /* (set! chicken.internal#module-requirement ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2582,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[22]+1 /* (set! chicken.internal#check-for-multiple-bindings ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2596,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[26]+1 /* (set! chicken.internal#macro-subset ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2670,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[27]+1 /* (set! chicken.internal#fixup-macro-environment ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2720,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t9=C_SCHEME_FALSE;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_FALSE;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_rand(C_fix(65536));
t14=C_mutate(&lf[31] /* (set! chicken.internal#hash-symbol ...) */,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2801,a[2]=t10,a[3]=t12,a[4]=t13,a[5]=((C_word)li16),tmp=(C_word)a,a+=6,tmp));
t15=C_mutate((C_word*)lf[32]+1 /* (set! chicken.internal#make-hash-table ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2816,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[34]+1 /* (set! chicken.internal#hash-table-ref ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2831,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[35]+1 /* (set! chicken.internal#hash-table-set! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2887,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[36]+1 /* (set! chicken.internal#hash-table-update! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2948,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[37]+1 /* (set! chicken.internal#hash-table-for-each ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2968,a[2]=((C_word)li26),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[38]+1 /* (set! chicken.internal#hash-table-size ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3035,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[40]+1 /* (set! chicken.internal#default-imports ...) */,lf[41]);
t22=C_mutate((C_word*)lf[42]+1 /* (set! chicken.internal#default-syntax-imports ...) */,lf[43]);
t23=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t23;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t23+1)))(2,av2);}}

/* loop in chicken.internal#valid-library-specifier? in k1012 */
static C_word C_fcall f_1391(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
t2=C_i_nullp(t1);
if(C_truep(t2)){
return(t2);}
else{
t3=C_i_car(t1);
t4=C_i_symbolp(t3);
if(C_truep(t4)){
if(C_truep(C_i_not(t4))){
return(C_SCHEME_FALSE);}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}
else{
t5=C_fixnump(t3);
if(C_truep(C_i_not(t5))){
return(C_SCHEME_FALSE);}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}}}

/* chicken.internal#string->c-identifier in k1012 */
static void C_ccall f_2294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2294,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2298,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* internal.scm:68: chicken.base#open-output-string */
t4=*((C_word*)lf[7]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_ccall f_2298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2298,c,av);}
a=C_alloc(9);
t2=C_i_string_length(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2306,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t4,a[6]=((C_word)li0),tmp=(C_word)a,a+=7,tmp));
t6=((C_word*)t4)[1];
f_2306(t6,((C_word*)t0)[3],C_fix(0));}

/* doloop567 in k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_fcall f_2306(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_2306,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
/* internal.scm:71: chicken.base#get-output-string */
t3=*((C_word*)lf[3]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=C_i_string_ref(((C_word*)t0)[4],t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2322,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2332,a[2]=t3,a[3]=t4,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t6=C_u_i_char_alphabeticp(t3);
if(C_truep(C_i_not(t6))){
t7=C_u_i_char_numericp(t3);
t8=C_i_not(t7);
t9=t5;
f_2332(t9,(C_truep(t8)?t8:C_eqp(t2,C_fix(0))));}
else{
t7=t5;
f_2332(t7,C_SCHEME_FALSE);}}}

/* k2320 in doloop567 in k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_ccall f_2322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2322,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2306(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* k2330 in doloop567 in k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_fcall f_2332(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_2332,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_fix(C_character_code(((C_word*)t0)[2]));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2338,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* ##sys#write-char/port */
t4=*((C_word*)lf[6]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_make_character(95);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* ##sys#write-char/port */
t2=*((C_word*)lf[6]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k2336 in k2330 in doloop567 in k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_ccall f_2338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2338,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2341,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[4],C_fix(16)))){
/* ##sys#write-char/port */
t3=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(48);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_2341(2,av2);}}}

/* k2339 in k2336 in k2330 in doloop567 in k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_ccall f_2341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2341,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2348,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* ##sys#fixnum->string */
t3=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(16);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2346 in k2339 in k2336 in k2330 in doloop567 in k2296 in chicken.internal#string->c-identifier in k1012 */
static void C_ccall f_2348(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2348,c,av);}
/* internal.scm:78: scheme#display */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.internal#valid-library-specifier? in k1012 */
static void C_ccall f_2381(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2381,c,av);}
a=C_alloc(3);
t3=C_i_symbolp(t2);
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_listp(t2))){
t4=C_i_nullp(t2);
if(C_truep(C_i_not(t4))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1391,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=(
  f_1391(t2)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}

/* chicken.internal#library-id in k1012 */
static void C_ccall f_2421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
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
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_2421,c,av);}
a=C_alloc(17);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2424,a[2]=t2,a[3]=((C_word)li4),tmp=(C_word)a,a+=4,tmp));
t8=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2467,a[2]=t4,a[3]=((C_word)li5),tmp=(C_word)a,a+=4,tmp));
if(C_truep(C_i_symbolp(t2))){
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
if(C_truep(C_i_nullp(t2))){
/* internal.scm:104: fail */
t9=((C_word*)t4)[1];
f_2424(t9,t1);}
else{
t9=C_i_listp(t2);
if(C_truep(C_i_not(t9))){
/* internal.scm:105: fail */
t10=((C_word*)t4)[1];
f_2424(t10,t1);}
else{
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2519,a[2]=t1,a[3]=t2,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
t11=C_i_cdr(t2);
if(C_truep(C_i_pairp(t11))){
t12=C_i_cddr(t2);
if(C_truep(C_i_nullp(t12))){
t13=C_eqp(lf[18],C_u_i_car(t2));
if(C_truep(t13)){
t14=C_u_i_cdr(t2);
t15=t10;
f_2519(t15,C_fixnump(C_u_i_car(t14)));}
else{
t14=t10;
f_2519(t14,C_SCHEME_FALSE);}}
else{
t13=t10;
f_2519(t13,C_SCHEME_FALSE);}}
else{
t12=t10;
f_2519(t12,C_SCHEME_FALSE);}}}}}

/* fail in chicken.internal#library-id in k1012 */
static void C_fcall f_2424(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_2424,2,t0,t1);}
/* internal.scm:92: ##sys#error */
t2=*((C_word*)lf[10]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[11];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* library-part->string in chicken.internal#library-id in k1012 */
static void C_fcall f_2467(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_2467,3,t0,t1,t2);}
if(C_truep(C_i_symbolp(t2))){
/* internal.scm:99: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[12]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[12]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}
else{
if(C_truep(C_fixnump(t2))){
/* internal.scm:100: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}
else{
/* internal.scm:101: fail */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2424(t3,t1);}}}

/* k2517 in chicken.internal#library-id in k1012 */
static void C_fcall f_2519(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2519,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2526,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2530,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* internal.scm:108: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[13]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[13]+1);
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
tp(3,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2545,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* internal.scm:111: library-part->string */
t4=((C_word*)((C_word*)t0)[4])[1];
f_2467(t4,t3,C_u_i_car(((C_word*)t0)[3]));}}

/* k2524 in k2517 in chicken.internal#library-id in k1012 */
static void C_ccall f_2526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2526,c,av);}
/* internal.scm:107: ##sys#intern-symbol */{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
C_string_to_symbol(3,av2);}}

/* k2528 in k2517 in chicken.internal#library-id in k1012 */
static void C_ccall f_2530(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2530,c,av);}
/* internal.scm:108: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[15];
av2[3]=t1;
tp(4,av2);}}

/* k2543 in k2517 in chicken.internal#library-id in k1012 */
static void C_ccall f_2545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_2545,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2547,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word)li6),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_2547(t5,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* doloop609 in k2543 in k2517 in chicken.internal#library-id in k1012 */
static void C_fcall f_2547(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_2547,4,t0,t1,t2,t3);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
/* internal.scm:114: ##sys#intern-symbol */{
C_word av2[3];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
C_string_to_symbol(3,av2);}}
else{
t4=C_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2568,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2572,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* internal.scm:112: library-part->string */
t7=((C_word*)((C_word*)t0)[3])[1];
f_2467(t7,t6,C_u_i_car(t2));}}

/* k2566 in doloop609 in k2543 in k2517 in chicken.internal#library-id in k1012 */
static void C_ccall f_2568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2568,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2547(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2570 in doloop609 in k2543 in k2517 in chicken.internal#library-id in k1012 */
static void C_ccall f_2572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2572,c,av);}
/* internal.scm:112: scheme#string-append */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[17];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.internal#module-requirement in k1012 */
static void C_ccall f_2582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_2582,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2590,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* internal.scm:121: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(1));
av2[3]=lf[21];
tp(4,av2);}}

/* k2588 in chicken.internal#module-requirement in k1012 */
static void C_ccall f_2590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2590,c,av);}
/* internal.scm:120: ##sys#string->symbol */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[20]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[20]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* chicken.internal#check-for-multiple-bindings in k1012 */
static void C_ccall f_2596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2596,c,av);}
a=C_alloc(8);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2602,a[2]=t6,a[3]=t3,a[4]=t4,a[5]=((C_word)li9),tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_2602(t8,t1,t2,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);}

/* loop in chicken.internal#check-for-multiple-bindings in k1012 */
static void C_fcall f_2602(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_2602,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=C_i_nullp(t2);
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2615,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=t3,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
t7=C_i_caar(t2);
if(C_truep(C_i_memq(t7,t3))){
t8=C_u_i_car(t2);
t9=t6;
f_2615(t9,C_i_not(C_i_memq(C_u_i_car(t8),t4)));}
else{
t8=t6;
f_2615(t8,C_SCHEME_FALSE);}}}

/* k2613 in loop in chicken.internal#check-for-multiple-bindings in k1012 */
static void C_fcall f_2615(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_2615,2,t0,t1);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2618,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2635,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* internal.scm:133: scheme#string-append */
t4=*((C_word*)lf[16]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[24];
av2[3]=((C_word*)t0)[8];
av2[4]=lf[25];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_i_caar(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[6]);
/* internal.scm:137: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_2602(t5,((C_word*)t0)[5],t2,t4,((C_word*)t0)[3]);}}

/* k2616 in k2613 in loop in chicken.internal#check-for-multiple-bindings in k1012 */
static void C_ccall f_2618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2618,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_i_caar(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[3]);
/* internal.scm:136: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_2602(t5,((C_word*)t0)[5],t2,((C_word*)t0)[6],t4);}

/* k2633 in k2613 in loop in chicken.internal#check-for-multiple-bindings in k1012 */
static void C_ccall f_2635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2635,c,av);}
t2=C_u_i_car(((C_word*)t0)[2]);
/* internal.scm:132: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[23]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=C_u_i_car(t2);
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}

/* chicken.internal#macro-subset in k1012 */
static void C_ccall f_2670(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_2670,c,av);}
a=C_alloc(8);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2677,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2684,a[2]=t2,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* internal.scm:142: ##sys#macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[28]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t6;
tp(2,av2);}}

/* k2675 in chicken.internal#macro-subset in k1012 */
static void C_ccall f_2677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2677,c,av);}
/* internal.scm:146: fixup-macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[27]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[27]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k2682 in chicken.internal#macro-subset in k1012 */
static void C_ccall f_2684(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2684,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2686,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li11),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_2686(t5,((C_word*)t0)[3],t1);}

/* loop in k2682 in chicken.internal#macro-subset in k1012 */
static void C_fcall f_2686(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_2686,3,t0,t1,t2);}
a=C_alloc(4);
t3=C_i_nullp(t2);
t4=(C_truep(t3)?t3:C_eqp(t2,((C_word*)t0)[2]));
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2707,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* internal.scm:145: loop */
t8=t6;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}

/* k2705 in loop in k2682 in chicken.internal#macro-subset in k1012 */
static void C_ccall f_2707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2707,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.internal#fixup-macro-environment in k1012 */
static void C_ccall f_2720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2720,c,av);}
a=C_alloc(4);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2727,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
/* internal.scm:149: ##sys#append */
t6=*((C_word*)lf[29]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t2;
f_2727(2,av2);}}}

/* k2725 in chicken.internal#fixup-macro-environment in k1012 */
static void C_ccall f_2727(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_2727,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2728,a[2]=t1,a[3]=((C_word)li13),tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[30]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2767,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2769,a[2]=t6,a[3]=t2,a[4]=((C_word)li14),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_2769(t8,t4,((C_word*)t0)[2]);}

/* g672 in k2725 in chicken.internal#fixup-macro-environment in k1012 */
static void C_fcall f_2728(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_2728,3,t0,t1,t2);}
a=C_alloc(4);
t3=C_i_cdr(t2);
if(C_truep(C_i_pairp(t3))){
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2744,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_i_cadr(t2);
if(C_truep(C_i_nullp(t6))){
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_i_set_car(t4,((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_u_i_cdr(t2);
/* internal.scm:157: ##sys#append */
t8=*((C_word*)lf[29]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t5;
av2[2]=C_u_i_car(t7);
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k2742 in g672 in k2725 in chicken.internal#fixup-macro-environment in k1012 */
static void C_ccall f_2744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2744,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_set_car(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2765 in k2725 in chicken.internal#fixup-macro-environment in k1012 */
static void C_ccall f_2767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2767,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop671 in k2725 in chicken.internal#fixup-macro-environment in k1012 */
static void C_fcall f_2769(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2769,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2779,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* internal.scm:150: g672 */
t4=((C_word*)t0)[3];
f_2728(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2777 in for-each-loop671 in k2725 in chicken.internal#fixup-macro-environment in k1012 */
static void C_ccall f_2779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2779,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2769(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.internal#hash-symbol in k1012 */
static C_word C_fcall f_2801(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;{}
t3=C_eqp(t1,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(t3)){
return(C_fixnum_modulo(((C_word*)((C_word*)t0)[3])[1],t2));}
else{
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t5=C_slot(t1,C_fix(1));
t6=C_mutate(((C_word *)((C_word*)t0)[3])+1,C_u_i_string_hash(t5,((C_word*)t0)[4]));
return(C_fixnum_modulo(((C_word*)((C_word*)t0)[3])[1],t2));}}

/* chicken.internal#make-hash-table in k1012 */
static void C_ccall f_2816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2816,c,av);}
if(C_truep(C_rest_nullp(c,2))){
/* internal.scm:178: scheme#make-vector */
t2=*((C_word*)lf[33]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=C_fix(301);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
/* internal.scm:178: scheme#make-vector */
t2=*((C_word*)lf[33]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=C_get_rest_arg(c,2,av,2,t0);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* chicken.internal#hash-table-ref in k1012 */
static void C_ccall f_2831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2831,c,av);}
a=C_alloc(4);
t4=(
/* internal.scm:181: hash-symbol */
  f_2801(lf[31],t3,C_block_size(t2))
);
t5=C_slot(t2,t4);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2841,a[2]=t3,a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=(
  f_2841(t6,t5)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* loop in chicken.internal#hash-table-ref in k1012 */
static C_word C_fcall f_2841(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
t2=C_eqp(C_SCHEME_END_OF_LIST,t1);
if(C_truep(C_i_not(t2))){
t3=C_slot(t1,C_fix(0));
t4=C_slot(t3,C_fix(0));
t5=C_eqp(((C_word*)t0)[2],t4);
if(C_truep(t5)){
return(C_slot(C_slot(t1,C_fix(0)),C_fix(1)));}
else{
t7=C_slot(t1,C_fix(1));
t1=t7;
goto loop;}}
else{
return(C_SCHEME_FALSE);}}

/* chicken.internal#hash-table-set! in k1012 */
static void C_ccall f_2887(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_2887,c,av);}
a=C_alloc(11);
t5=(
/* internal.scm:188: hash-symbol */
  f_2801(lf[31],t3,C_block_size(t2))
);
t6=C_slot(t2,t5);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2899,a[2]=t3,a[3]=t4,a[4]=t6,a[5]=t2,a[6]=t5,a[7]=t8,a[8]=((C_word)li20),tmp=(C_word)a,a+=9,tmp));
t10=((C_word*)t8)[1];
f_2899(t10,t1,t6);}

/* loop in chicken.internal#hash-table-set! in k1012 */
static void C_fcall f_2899(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_2899,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_eqp(C_SCHEME_END_OF_LIST,t2);
if(C_truep(t3)){
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[4]);
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_i_setslot(((C_word*)t0)[5],((C_word*)t0)[6],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t4=C_slot(t2,C_fix(0));
t5=C_slot(t4,C_fix(0));
t6=C_eqp(((C_word*)t0)[2],t5);
if(C_truep(t6)){
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_i_setslot(C_slot(t2,C_fix(0)),C_fix(1),((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
/* internal.scm:195: loop */
t8=t1;
t9=C_slot(t2,C_fix(1));
t1=t8;
t2=t9;
goto loop;}}}

/* chicken.internal#hash-table-update! in k1012 */
static void C_ccall f_2948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2948,c,av);}
a=C_alloc(10);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2956,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2960,a[2]=t4,a[3]=t6,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* internal.scm:198: hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[34]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[34]+1);
av2[1]=t7;
av2[2]=t2;
av2[3]=t3;
tp(4,av2);}}

/* k2954 in chicken.internal#hash-table-update! in k1012 */
static void C_ccall f_2956(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2956,c,av);}
/* internal.scm:198: hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[35]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[35]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
tp(5,av2);}}

/* k2958 in chicken.internal#hash-table-update! in k1012 */
static void C_ccall f_2960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2960,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2963,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
/* internal.scm:198: updtfunc */
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
/* internal.scm:198: valufunc */
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}}

/* k2961 in k2958 in chicken.internal#hash-table-update! in k1012 */
static void C_ccall f_2963(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2963,c,av);}
/* internal.scm:198: updtfunc */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* chicken.internal#hash-table-for-each in k1012 */
static void C_ccall f_2968(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2968,c,av);}
a=C_alloc(9);
t4=C_block_size(t3);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2974,a[2]=t4,a[3]=t2,a[4]=t3,a[5]=t6,a[6]=((C_word)li25),tmp=(C_word)a,a+=7,tmp));
t8=((C_word*)t6)[1];
f_2974(t8,t1,C_fix(0));}

/* doloop735 in chicken.internal#hash-table-for-each in k1012 */
static void C_fcall f_2974(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_2974,3,t0,t1,t2);}
a=C_alloc(16);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2982,a[2]=((C_word*)t0)[3],a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp);
t4=C_slot(((C_word*)t0)[4],t2);
t5=C_i_check_list_2(t4,lf[30]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3003,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3012,a[2]=t8,a[3]=t3,a[4]=((C_word)li24),tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_3012(t10,t6,t4);}}

/* g741 in doloop735 in chicken.internal#hash-table-for-each in k1012 */
static void C_fcall f_2982(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_2982,3,t0,t1,t2);}
/* internal.scm:204: p */
t3=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t3;
av2[1]=t1;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=C_slot(t2,C_fix(1));
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}

/* k3001 in doloop735 in chicken.internal#hash-table-for-each in k1012 */
static void C_ccall f_3003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3003,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2974(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop740 in doloop735 in chicken.internal#hash-table-for-each in k1012 */
static void C_fcall f_3012(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3012,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3022,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* internal.scm:204: g741 */
t4=((C_word*)t0)[3];
f_2982(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3020 in for-each-loop740 in doloop735 in chicken.internal#hash-table-for-each in k1012 */
static void C_ccall f_3022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3022,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3012(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.internal#hash-table-size in k1012 */
static void C_ccall f_3035(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_3035,c,av);}
a=C_alloc(7);
t3=C_block_size(t2);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3045,a[2]=t5,a[3]=t2,a[4]=((C_word)li27),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_3045(t7,t1,t3,C_fix(0),C_fix(0));}

/* loop in chicken.internal#hash-table-size in k1012 */
static void C_fcall f_3045(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_3045,5,t0,t1,t2,t3,t4);}
a=C_alloc(7);
t5=C_eqp(t3,t2);
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_fixnum_plus(t3,C_fix(1));
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3067,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t6,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* internal.scm:211: ##sys#length */
t8=*((C_word*)lf[39]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_slot(((C_word*)t0)[3],t3);
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}

/* k3065 in loop in chicken.internal#hash-table-size in k1012 */
static void C_ccall f_3067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3067,c,av);}
/* internal.scm:211: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3045(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],C_fixnum_plus(((C_word*)t0)[6],t1));}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_internal_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("internal"));
C_check_nursery_minimum(C_calculate_demand(19,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void*)C_internal_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(305))){
C_save(t1);
C_rereclaim2(305*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(19);
C_initialize_lf(lf,44);
lf[0]=C_h_intern(&lf[0],8, C_text("internal"));
lf[1]=C_h_intern(&lf[1],17, C_text("chicken.internal#"));
lf[2]=C_h_intern(&lf[2],37, C_text("chicken.internal#string->c-identifier"));
lf[3]=C_h_intern(&lf[3],30, C_text("chicken.base#get-output-string"));
lf[4]=C_h_intern(&lf[4],14, C_text("scheme#display"));
lf[5]=C_h_intern(&lf[5],20, C_text("##sys#fixnum->string"));
lf[6]=C_h_intern(&lf[6],21, C_text("##sys#write-char/port"));
lf[7]=C_h_intern(&lf[7],31, C_text("chicken.base#open-output-string"));
lf[8]=C_h_intern(&lf[8],41, C_text("chicken.internal#valid-library-specifier\077"));
lf[9]=C_h_intern(&lf[9],27, C_text("chicken.internal#library-id"));
lf[10]=C_h_intern(&lf[10],11, C_text("##sys#error"));
lf[11]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031invalid library specifier"));
lf[12]=C_h_intern(&lf[12],20, C_text("##sys#symbol->string"));
lf[13]=C_h_intern(&lf[13],20, C_text("##sys#number->string"));
lf[14]=C_h_intern(&lf[14],19, C_text("##sys#string-append"));
lf[15]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005srfi-"));
lf[16]=C_h_intern(&lf[16],20, C_text("scheme#string-append"));
lf[17]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[18]=C_h_intern(&lf[18],4, C_text("srfi"));
lf[19]=C_h_intern(&lf[19],35, C_text("chicken.internal#module-requirement"));
lf[20]=C_h_intern(&lf[20],20, C_text("##sys#string->symbol"));
lf[21]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001#"));
lf[22]=C_h_intern(&lf[22],44, C_text("chicken.internal#check-for-multiple-bindings"));
lf[23]=C_h_intern(&lf[23],10, C_text("##sys#warn"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376B\000\000!variable bound multiple times in "));
lf[25]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012 construct"));
lf[26]=C_h_intern(&lf[26],29, C_text("chicken.internal#macro-subset"));
lf[27]=C_h_intern(&lf[27],40, C_text("chicken.internal#fixup-macro-environment"));
lf[28]=C_h_intern(&lf[28],23, C_text("##sys#macro-environment"));
lf[29]=C_h_intern(&lf[29],12, C_text("##sys#append"));
lf[30]=C_h_intern(&lf[30],8, C_text("for-each"));
lf[32]=C_h_intern(&lf[32],32, C_text("chicken.internal#make-hash-table"));
lf[33]=C_h_intern(&lf[33],18, C_text("scheme#make-vector"));
lf[34]=C_h_intern(&lf[34],31, C_text("chicken.internal#hash-table-ref"));
lf[35]=C_h_intern(&lf[35],32, C_text("chicken.internal#hash-table-set!"));
lf[36]=C_h_intern(&lf[36],35, C_text("chicken.internal#hash-table-update!"));
lf[37]=C_h_intern(&lf[37],36, C_text("chicken.internal#hash-table-for-each"));
lf[38]=C_h_intern(&lf[38],32, C_text("chicken.internal#hash-table-size"));
lf[39]=C_h_intern(&lf[39],12, C_text("##sys#length"));
lf[40]=C_h_intern(&lf[40],32, C_text("chicken.internal#default-imports"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001scheme\376\003\000\000\002\376\001\000\000\014\001chicken.base\376\003\000\000\002\376\001\000\000\016\001chicken.syntax\376\377\016"));
lf[42]=C_h_intern(&lf[42],39, C_text("chicken.internal#default-syntax-imports"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001scheme\376\003\000\000\002\376\001\000\000\014\001chicken.base\376\003\000\000\002\376\001\000\000\016\001chicken.syntax\376\377\016"));
C_register_lf2(lf,44,create_ptable());{}
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1014,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[61] = {
{C_text("f_1014:internal_2escm"),(void*)f_1014},
{C_text("f_1391:internal_2escm"),(void*)f_1391},
{C_text("f_2294:internal_2escm"),(void*)f_2294},
{C_text("f_2298:internal_2escm"),(void*)f_2298},
{C_text("f_2306:internal_2escm"),(void*)f_2306},
{C_text("f_2322:internal_2escm"),(void*)f_2322},
{C_text("f_2332:internal_2escm"),(void*)f_2332},
{C_text("f_2338:internal_2escm"),(void*)f_2338},
{C_text("f_2341:internal_2escm"),(void*)f_2341},
{C_text("f_2348:internal_2escm"),(void*)f_2348},
{C_text("f_2381:internal_2escm"),(void*)f_2381},
{C_text("f_2421:internal_2escm"),(void*)f_2421},
{C_text("f_2424:internal_2escm"),(void*)f_2424},
{C_text("f_2467:internal_2escm"),(void*)f_2467},
{C_text("f_2519:internal_2escm"),(void*)f_2519},
{C_text("f_2526:internal_2escm"),(void*)f_2526},
{C_text("f_2530:internal_2escm"),(void*)f_2530},
{C_text("f_2545:internal_2escm"),(void*)f_2545},
{C_text("f_2547:internal_2escm"),(void*)f_2547},
{C_text("f_2568:internal_2escm"),(void*)f_2568},
{C_text("f_2572:internal_2escm"),(void*)f_2572},
{C_text("f_2582:internal_2escm"),(void*)f_2582},
{C_text("f_2590:internal_2escm"),(void*)f_2590},
{C_text("f_2596:internal_2escm"),(void*)f_2596},
{C_text("f_2602:internal_2escm"),(void*)f_2602},
{C_text("f_2615:internal_2escm"),(void*)f_2615},
{C_text("f_2618:internal_2escm"),(void*)f_2618},
{C_text("f_2635:internal_2escm"),(void*)f_2635},
{C_text("f_2670:internal_2escm"),(void*)f_2670},
{C_text("f_2677:internal_2escm"),(void*)f_2677},
{C_text("f_2684:internal_2escm"),(void*)f_2684},
{C_text("f_2686:internal_2escm"),(void*)f_2686},
{C_text("f_2707:internal_2escm"),(void*)f_2707},
{C_text("f_2720:internal_2escm"),(void*)f_2720},
{C_text("f_2727:internal_2escm"),(void*)f_2727},
{C_text("f_2728:internal_2escm"),(void*)f_2728},
{C_text("f_2744:internal_2escm"),(void*)f_2744},
{C_text("f_2767:internal_2escm"),(void*)f_2767},
{C_text("f_2769:internal_2escm"),(void*)f_2769},
{C_text("f_2779:internal_2escm"),(void*)f_2779},
{C_text("f_2801:internal_2escm"),(void*)f_2801},
{C_text("f_2816:internal_2escm"),(void*)f_2816},
{C_text("f_2831:internal_2escm"),(void*)f_2831},
{C_text("f_2841:internal_2escm"),(void*)f_2841},
{C_text("f_2887:internal_2escm"),(void*)f_2887},
{C_text("f_2899:internal_2escm"),(void*)f_2899},
{C_text("f_2948:internal_2escm"),(void*)f_2948},
{C_text("f_2956:internal_2escm"),(void*)f_2956},
{C_text("f_2960:internal_2escm"),(void*)f_2960},
{C_text("f_2963:internal_2escm"),(void*)f_2963},
{C_text("f_2968:internal_2escm"),(void*)f_2968},
{C_text("f_2974:internal_2escm"),(void*)f_2974},
{C_text("f_2982:internal_2escm"),(void*)f_2982},
{C_text("f_3003:internal_2escm"),(void*)f_3003},
{C_text("f_3012:internal_2escm"),(void*)f_3012},
{C_text("f_3022:internal_2escm"),(void*)f_3022},
{C_text("f_3035:internal_2escm"),(void*)f_3035},
{C_text("f_3045:internal_2escm"),(void*)f_3045},
{C_text("f_3067:internal_2escm"),(void*)f_3067},
{C_text("toplevel:internal_2escm"),(void*)C_internal_toplevel},
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
o|hiding unexported module binding: chicken.internal#d 
o|hiding unexported module binding: chicken.internal#define-alias 
o|hiding unexported module binding: chicken.internal#partition 
o|hiding unexported module binding: chicken.internal#span 
o|hiding unexported module binding: chicken.internal#take 
o|hiding unexported module binding: chicken.internal#drop 
o|hiding unexported module binding: chicken.internal#split-at 
o|hiding unexported module binding: chicken.internal#append-map 
o|hiding unexported module binding: chicken.internal#every 
o|hiding unexported module binding: chicken.internal#any 
o|hiding unexported module binding: chicken.internal#cons* 
o|hiding unexported module binding: chicken.internal#concatenate 
o|hiding unexported module binding: chicken.internal#delete 
o|hiding unexported module binding: chicken.internal#first 
o|hiding unexported module binding: chicken.internal#second 
o|hiding unexported module binding: chicken.internal#third 
o|hiding unexported module binding: chicken.internal#fourth 
o|hiding unexported module binding: chicken.internal#fifth 
o|hiding unexported module binding: chicken.internal#delete-duplicates 
o|hiding unexported module binding: chicken.internal#alist-cons 
o|hiding unexported module binding: chicken.internal#filter 
o|hiding unexported module binding: chicken.internal#filter-map 
o|hiding unexported module binding: chicken.internal#remove 
o|hiding unexported module binding: chicken.internal#unzip1 
o|hiding unexported module binding: chicken.internal#last 
o|hiding unexported module binding: chicken.internal#list-index 
o|hiding unexported module binding: chicken.internal#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.internal#lset-difference/eq? 
o|hiding unexported module binding: chicken.internal#lset-union/eq? 
o|hiding unexported module binding: chicken.internal#lset-intersection/eq? 
o|hiding unexported module binding: chicken.internal#list-tabulate 
o|hiding unexported module binding: chicken.internal#lset<=/eq? 
o|hiding unexported module binding: chicken.internal#lset=/eq? 
o|hiding unexported module binding: chicken.internal#length+ 
o|hiding unexported module binding: chicken.internal#find 
o|hiding unexported module binding: chicken.internal#find-tail 
o|hiding unexported module binding: chicken.internal#iota 
o|hiding unexported module binding: chicken.internal#make-list 
o|hiding unexported module binding: chicken.internal#posq 
o|hiding unexported module binding: chicken.internal#posv 
o|hiding unexported module binding: chicken.internal#hash-symbol 
S|applied compiler syntax:
S|  ##sys#for-each		1
S|  scheme#for-each		1
S|  chicken.base#foldl		3
S|  scheme#map		3
S|  chicken.base#foldr		3
o|eliminated procedure checks: 50 
o|specializations:
o|  2 (scheme#caar (pair pair *))
o|  2 (scheme#cadr (pair * pair))
o|  1 (scheme#number->string fixnum fixnum)
o|  1 (scheme#eqv? * *)
o|  3 (##sys#check-list (or pair list) *)
o|  26 (scheme#cdr pair)
o|  10 (scheme#car pair)
(o e)|safe calls: 289 
o|safe globals: (chicken.internal#default-syntax-imports chicken.internal#default-imports chicken.internal#hash-table-size chicken.internal#hash-table-for-each chicken.internal#hash-table-update! chicken.internal#hash-table-set! chicken.internal#hash-table-ref chicken.internal#make-hash-table chicken.internal#hash-symbol chicken.internal#fixup-macro-environment chicken.internal#macro-subset chicken.internal#check-for-multiple-bindings chicken.internal#module-requirement chicken.internal#library-id chicken.internal#valid-library-specifier? chicken.internal#string->c-identifier chicken.internal#posv chicken.internal#posq chicken.internal#make-list chicken.internal#iota chicken.internal#find-tail chicken.internal#find chicken.internal#length+ chicken.internal#lset=/eq? chicken.internal#lset<=/eq? chicken.internal#list-tabulate chicken.internal#lset-intersection/eq? chicken.internal#lset-union/eq? chicken.internal#lset-difference/eq? chicken.internal#lset-adjoin/eq? chicken.internal#list-index chicken.internal#last chicken.internal#unzip1 chicken.internal#remove chicken.internal#filter-map chicken.internal#filter chicken.internal#alist-cons chicken.internal#delete-duplicates chicken.internal#fifth chicken.internal#fourth chicken.internal#third chicken.internal#second chicken.internal#first chicken.internal#delete chicken.internal#concatenate chicken.internal#cons* chicken.internal#any chicken.internal#every chicken.internal#append-map chicken.internal#split-at chicken.internal#drop chicken.internal#take chicken.internal#span chicken.internal#partition) 
o|removed side-effect free assignment to unused variable: chicken.internal#partition 
o|removed side-effect free assignment to unused variable: chicken.internal#span 
o|removed side-effect free assignment to unused variable: chicken.internal#drop 
o|removed side-effect free assignment to unused variable: chicken.internal#split-at 
o|removed side-effect free assignment to unused variable: chicken.internal#append-map 
o|inlining procedure: k1396 
o|inlining procedure: k1396 
o|inlining procedure: k1427 
o|inlining procedure: k1427 
o|removed side-effect free assignment to unused variable: chicken.internal#cons* 
o|removed side-effect free assignment to unused variable: chicken.internal#concatenate 
o|removed side-effect free assignment to unused variable: chicken.internal#first 
o|removed side-effect free assignment to unused variable: chicken.internal#second 
o|removed side-effect free assignment to unused variable: chicken.internal#third 
o|removed side-effect free assignment to unused variable: chicken.internal#fourth 
o|removed side-effect free assignment to unused variable: chicken.internal#fifth 
o|removed side-effect free assignment to unused variable: chicken.internal#delete-duplicates 
o|removed side-effect free assignment to unused variable: chicken.internal#alist-cons 
o|inlining procedure: k1644 
o|inlining procedure: k1644 
o|inlining procedure: k1636 
o|inlining procedure: k1636 
o|removed side-effect free assignment to unused variable: chicken.internal#filter-map 
o|removed side-effect free assignment to unused variable: chicken.internal#remove 
o|removed side-effect free assignment to unused variable: chicken.internal#unzip1 
o|removed side-effect free assignment to unused variable: chicken.internal#last 
o|removed side-effect free assignment to unused variable: chicken.internal#list-index 
o|removed side-effect free assignment to unused variable: chicken.internal#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.internal#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.internal#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.internal#lset-intersection/eq? 
o|inlining procedure: k2035 
o|inlining procedure: k2035 
o|removed side-effect free assignment to unused variable: chicken.internal#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.internal#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.internal#length+ 
o|removed side-effect free assignment to unused variable: chicken.internal#find 
o|removed side-effect free assignment to unused variable: chicken.internal#find-tail 
o|removed side-effect free assignment to unused variable: chicken.internal#iota 
o|removed side-effect free assignment to unused variable: chicken.internal#make-list 
o|removed side-effect free assignment to unused variable: chicken.internal#posq 
o|removed side-effect free assignment to unused variable: chicken.internal#posv 
o|inlining procedure: k2308 
o|inlining procedure: k2308 
o|substituted constant variable: a2350 
o|inlining procedure: k2366 
o|inlining procedure: k2366 
o|inlining procedure: k2386 
o|inlining procedure: k2386 
o|inlining procedure: k2395 
o|inlining procedure: k2410 
o|inlining procedure: k2410 
o|inlining procedure: k2395 
o|inlining procedure: k2469 
o|inlining procedure: k2469 
o|inlining procedure: k2490 
o|inlining procedure: k2490 
o|inlining procedure: k2505 
o|inlining procedure: k2505 
o|inlining procedure: k2549 
o|inlining procedure: k2549 
o|contracted procedure: "(internal.scm:106) srfi?598" 
o|inlining procedure: k2432 
o|inlining procedure: k2444 
o|inlining procedure: k2444 
o|inlining procedure: k2432 
o|inlining procedure: k2607 
o|inlining procedure: k2607 
o|inlining procedure: k2688 
o|inlining procedure: k2688 
o|inlining procedure: k2730 
o|inlining procedure: k2742 
o|inlining procedure: k2742 
o|inlining procedure: k2730 
o|inlining procedure: k2771 
o|inlining procedure: k2771 
o|inlining procedure: k2803 
o|inlining procedure: k2803 
o|inlining procedure: k2818 
o|inlining procedure: k2818 
o|inlining procedure: k2843 
o|inlining procedure: k2843 
o|inlining procedure: k2901 
o|inlining procedure: k2901 
o|inlining procedure: k2961 
o|inlining procedure: k2961 
o|inlining procedure: k2976 
o|inlining procedure: k2976 
o|inlining procedure: k3014 
o|inlining procedure: k3014 
o|inlining procedure: k3047 
o|inlining procedure: k3047 
o|replaced variables: 221 
o|removed binding forms: 88 
o|removed side-effect free assignment to unused variable: chicken.internal#any 
o|removed side-effect free assignment to unused variable: chicken.internal#filter 
o|removed side-effect free assignment to unused variable: chicken.internal#list-tabulate 
o|contracted procedure: "(internal.scm:88) chicken.internal#every" 
o|substituted constant variable: r23963093 
o|substituted constant variable: r24453104 
o|substituted constant variable: r24333105 
o|substituted constant variable: r26893108 
o|substituted constant variable: r28193120 
o|substituted constant variable: r28193120 
o|substituted constant variable: r28443131 
o|replaced variables: 20 
o|removed binding forms: 217 
o|replaced variables: 3 
o|removed binding forms: 25 
o|removed binding forms: 3 
o|contracted procedure: "(mini-srfi-1.scm:82) a2404" 
o|removed binding forms: 1 
o|replaced variables: 4 
o|inlining procedure: k1411 
o|removed binding forms: 2 
o|replaced variables: 1 
o|removed binding forms: 1 
o|simplifications: ((let . 13) (if . 4) (##core#call . 108)) 
o|  call simplifications:
o|    ##sys#size
o|    ##sys#setslot	2
o|    ##sys#check-list	2
o|    scheme#set-car!	2
o|    scheme#memq	2
o|    scheme#caar	3
o|    scheme#cons	5
o|    ##sys#slot	21
o|    scheme#pair?	4
o|    scheme#cddr
o|    scheme#eq?	7
o|    scheme#cdr	4
o|    scheme#cadr	2
o|    ##sys#intern-symbol	2
o|    scheme#list?	2
o|    scheme#null?	11
o|    scheme#car	5
o|    scheme#symbol?	4
o|    chicken.base#fixnum?	3
o|    scheme#string-length
o|    chicken.fixnum#fx>=	2
o|    scheme#string-ref
o|    scheme#char-alphabetic?
o|    scheme#char-numeric?
o|    scheme#not	8
o|    chicken.fixnum#fx=	2
o|    scheme#char->integer
o|    chicken.fixnum#fx<
o|    scheme#write-char	3
o|    chicken.fixnum#fx+	4
o|contracted procedure: k2299 
o|contracted procedure: k2311 
o|contracted procedure: k2317 
o|contracted procedure: k2327 
o|contracted procedure: k2333 
o|contracted procedure: k2351 
o|contracted procedure: k2377 
o|contracted procedure: k2360 
o|contracted procedure: k2373 
o|contracted procedure: k2363 
o|contracted procedure: k2383 
o|contracted procedure: k2392 
o|contracted procedure: k2417 
o|contracted procedure: k2398 
o|contracted procedure: k1393 
o|contracted procedure: k1415 
o|contracted procedure: k2407 
o|inlining procedure: k1402 
o|contracted procedure: k1411 
o|inlining procedure: k1402 
o|contracted procedure: k2472 
o|contracted procedure: k2481 
o|contracted procedure: k2493 
o|contracted procedure: k2499 
o|contracted procedure: k2578 
o|contracted procedure: k2508 
o|contracted procedure: k2532 
o|contracted procedure: k2539 
o|contracted procedure: k2552 
o|contracted procedure: k2562 
o|contracted procedure: k2463 
o|contracted procedure: k2435 
o|contracted procedure: k2459 
o|contracted procedure: k2441 
o|contracted procedure: k2447 
o|contracted procedure: k2592 
o|contracted procedure: k2604 
o|contracted procedure: k2629 
o|contracted procedure: k2625 
o|contracted procedure: k2649 
o|contracted procedure: k2645 
o|contracted procedure: k2666 
o|contracted procedure: k2652 
o|contracted procedure: k2659 
o|contracted procedure: k2713 
o|contracted procedure: k2672 
o|contracted procedure: k2691 
o|contracted procedure: k2694 
o|contracted procedure: k2701 
o|contracted procedure: k2794 
o|contracted procedure: k2722 
o|contracted procedure: k2759 
o|contracted procedure: k2733 
o|contracted procedure: k2755 
o|contracted procedure: k2745 
o|contracted procedure: k2762 
o|contracted procedure: k2774 
o|contracted procedure: k2784 
o|contracted procedure: k2788 
o|contracted procedure: k2806 
o|contracted procedure: k2812 
o|contracted procedure: k2824 
o|contracted procedure: k2818 
o|contracted procedure: k2837 
o|contracted procedure: k2878 
o|contracted procedure: k2846 
o|contracted procedure: k2874 
o|contracted procedure: k2870 
o|contracted procedure: k2852 
o|contracted procedure: k2859 
o|contracted procedure: k2866 
o|contracted procedure: k2892 
o|contracted procedure: k2904 
o|contracted procedure: k2915 
o|contracted procedure: k2911 
o|contracted procedure: k2943 
o|contracted procedure: k2939 
o|contracted procedure: k2921 
o|contracted procedure: k2928 
o|contracted procedure: k2935 
o|contracted procedure: k2979 
o|contracted procedure: k2988 
o|contracted procedure: k2992 
o|contracted procedure: k2995 
o|contracted procedure: k2998 
o|contracted procedure: k3008 
o|contracted procedure: k3017 
o|contracted procedure: k3027 
o|contracted procedure: k3031 
o|contracted procedure: k3041 
o|contracted procedure: k3050 
o|contracted procedure: k3057 
o|contracted procedure: k3061 
o|contracted procedure: k3069 
o|simplifications: ((let . 39)) 
o|removed binding forms: 92 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest641643 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest641643 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest660662 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest660662 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest700701 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest700701 0 
o|simplifications: ((let . 2)) 
o|removed binding forms: 1 
o|direct leaf routine/allocation: loop199 0 
o|direct leaf routine/allocation: chicken.internal#hash-symbol 0 
o|direct leaf routine/allocation: loop710 0 
o|converted assignments to bindings: (loop199) 
o|contracted procedure: "(internal.scm:181) k2882" 
o|converted assignments to bindings: (loop710) 
o|contracted procedure: "(internal.scm:188) k2889" 
o|simplifications: ((let . 2)) 
o|removed binding forms: 2 
o|customizable procedures: (loop760 g741748 for-each-loop740751 doloop735736 loop720 g672679 for-each-loop671682 loop650 k2613 loop623 k2517 library-part->string599 doloop609610 fail597 k2330 doloop567568) 
o|calls to known targets: 36 
o|identified direct recursive calls: f_1391 2 
o|identified direct recursive calls: f_2686 1 
o|unused rest argument: rest641643 f_2670 
o|unused rest argument: rest660662 f_2720 
o|unused rest argument: rest700701 f_2816 
o|identified direct recursive calls: f_2841 1 
o|identified direct recursive calls: f_2899 1 
o|fast box initializations: 11 
o|fast global references: 2 
o|fast global assignments: 1 
o|dropping unused closure argument: f_1391 
*/
/* end of file */
