/* Generated from chicken-profile.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken-profile.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -output-file chicken-profile.c
   uses: eval data-structures internal posix file library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_posix_toplevel)
C_externimport void C_ccall C_posix_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externimport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[94];
static double C_possibly_force_alignment;


C_noret_decl(f_1258)
static void C_ccall f_1258(C_word c,C_word *av) C_noret;
C_noret_decl(f_1261)
static void C_ccall f_1261(C_word c,C_word *av) C_noret;
C_noret_decl(f_1264)
static void C_ccall f_1264(C_word c,C_word *av) C_noret;
C_noret_decl(f_1267)
static void C_ccall f_1267(C_word c,C_word *av) C_noret;
C_noret_decl(f_1270)
static void C_ccall f_1270(C_word c,C_word *av) C_noret;
C_noret_decl(f_1273)
static void C_ccall f_1273(C_word c,C_word *av) C_noret;
C_noret_decl(f_1276)
static void C_ccall f_1276(C_word c,C_word *av) C_noret;
C_noret_decl(f_1386)
static void C_fcall f_1386(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1404)
static void C_ccall f_1404(C_word c,C_word *av) C_noret;
C_noret_decl(f_1896)
static void C_fcall f_1896(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1925)
static void C_ccall f_1925(C_word c,C_word *av) C_noret;
C_noret_decl(f_2563)
static void C_fcall f_2563(C_word t0) C_noret;
C_noret_decl(f_2567)
static void C_ccall f_2567(C_word c,C_word *av) C_noret;
C_noret_decl(f_2574)
static void C_ccall f_2574(C_word c,C_word *av) C_noret;
C_noret_decl(f_2610)
static void C_fcall f_2610(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2620)
static void C_fcall f_2620(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2627)
static void C_ccall f_2627(C_word c,C_word *av) C_noret;
C_noret_decl(f_2630)
static void C_ccall f_2630(C_word c,C_word *av) C_noret;
C_noret_decl(f_2643)
static void C_ccall f_2643(C_word c,C_word *av) C_noret;
C_noret_decl(f_2645)
static void C_ccall f_2645(C_word c,C_word *av) C_noret;
C_noret_decl(f_2650)
static void C_ccall f_2650(C_word c,C_word *av) C_noret;
C_noret_decl(f_2654)
static void C_ccall f_2654(C_word c,C_word *av) C_noret;
C_noret_decl(f_2660)
static void C_fcall f_2660(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2679)
static void C_fcall f_2679(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2683)
static void C_ccall f_2683(C_word c,C_word *av) C_noret;
C_noret_decl(f_2699)
static void C_ccall f_2699(C_word c,C_word *av) C_noret;
C_noret_decl(f_2702)
static void C_ccall f_2702(C_word c,C_word *av) C_noret;
C_noret_decl(f_2720)
static void C_ccall f_2720(C_word c,C_word *av) C_noret;
C_noret_decl(f_2727)
static void C_ccall f_2727(C_word c,C_word *av) C_noret;
C_noret_decl(f_2735)
static void C_ccall f_2735(C_word c,C_word *av) C_noret;
C_noret_decl(f_2742)
static void C_ccall f_2742(C_word c,C_word *av) C_noret;
C_noret_decl(f_2757)
static void C_ccall f_2757(C_word c,C_word *av) C_noret;
C_noret_decl(f_2793)
static void C_ccall f_2793(C_word c,C_word *av) C_noret;
C_noret_decl(f_2824)
static void C_ccall f_2824(C_word c,C_word *av) C_noret;
C_noret_decl(f_2858)
static void C_ccall f_2858(C_word c,C_word *av) C_noret;
C_noret_decl(f_2887)
static void C_ccall f_2887(C_word c,C_word *av) C_noret;
C_noret_decl(f_2915)
static void C_ccall f_2915(C_word c,C_word *av) C_noret;
C_noret_decl(f_2923)
static void C_ccall f_2923(C_word c,C_word *av) C_noret;
C_noret_decl(f_2927)
static void C_ccall f_2927(C_word c,C_word *av) C_noret;
C_noret_decl(f_2941)
static void C_fcall f_2941(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2953)
static void C_ccall f_2953(C_word c,C_word *av) C_noret;
C_noret_decl(f_2975)
static void C_ccall f_2975(C_word c,C_word *av) C_noret;
C_noret_decl(f_2979)
static void C_ccall f_2979(C_word c,C_word *av) C_noret;
C_noret_decl(f_2983)
static void C_ccall f_2983(C_word c,C_word *av) C_noret;
C_noret_decl(f_2999)
static void C_ccall f_2999(C_word c,C_word *av) C_noret;
C_noret_decl(f_3003)
static void C_ccall f_3003(C_word c,C_word *av) C_noret;
C_noret_decl(f_3006)
static void C_ccall f_3006(C_word c,C_word *av) C_noret;
C_noret_decl(f_3012)
static void C_ccall f_3012(C_word c,C_word *av) C_noret;
C_noret_decl(f_3015)
static void C_ccall f_3015(C_word c,C_word *av) C_noret;
C_noret_decl(f_3020)
static void C_ccall f_3020(C_word c,C_word *av) C_noret;
C_noret_decl(f_3029)
static void C_ccall f_3029(C_word c,C_word *av) C_noret;
C_noret_decl(f_3031)
static void C_fcall f_3031(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3041)
static void C_ccall f_3041(C_word c,C_word *av) C_noret;
C_noret_decl(f_3048)
static void C_ccall f_3048(C_word c,C_word *av) C_noret;
C_noret_decl(f_3070)
static void C_ccall f_3070(C_word c,C_word *av) C_noret;
C_noret_decl(f_3085)
static void C_ccall f_3085(C_word c,C_word *av) C_noret;
C_noret_decl(f_3087)
static void C_fcall f_3087(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3097)
static void C_fcall f_3097(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3148)
static void C_ccall f_3148(C_word c,C_word *av) C_noret;
C_noret_decl(f_3167)
static void C_ccall f_3167(C_word c,C_word *av) C_noret;
C_noret_decl(f_3214)
static void C_fcall f_3214(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3218)
static void C_ccall f_3218(C_word c,C_word *av) C_noret;
C_noret_decl(f_3225)
static void C_ccall f_3225(C_word c,C_word *av) C_noret;
C_noret_decl(f_3233)
static void C_ccall f_3233(C_word c,C_word *av) C_noret;
C_noret_decl(f_3237)
static void C_ccall f_3237(C_word c,C_word *av) C_noret;
C_noret_decl(f_3245)
static void C_ccall f_3245(C_word c,C_word *av) C_noret;
C_noret_decl(f_3249)
static void C_ccall f_3249(C_word c,C_word *av) C_noret;
C_noret_decl(f_3261)
static void C_ccall f_3261(C_word c,C_word *av) C_noret;
C_noret_decl(f_3269)
static void C_ccall f_3269(C_word c,C_word *av) C_noret;
C_noret_decl(f_3275)
static void C_ccall f_3275(C_word c,C_word *av) C_noret;
C_noret_decl(f_3278)
static void C_ccall f_3278(C_word c,C_word *av) C_noret;
C_noret_decl(f_3288)
static void C_ccall f_3288(C_word c,C_word *av) C_noret;
C_noret_decl(f_3291)
static void C_ccall f_3291(C_word c,C_word *av) C_noret;
C_noret_decl(f_3294)
static void C_fcall f_3294(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3319)
static void C_ccall f_3319(C_word c,C_word *av) C_noret;
C_noret_decl(f_3323)
static void C_ccall f_3323(C_word c,C_word *av) C_noret;
C_noret_decl(f_3327)
static void C_ccall f_3327(C_word c,C_word *av) C_noret;
C_noret_decl(f_3331)
static void C_ccall f_3331(C_word c,C_word *av) C_noret;
C_noret_decl(f_3335)
static void C_ccall f_3335(C_word c,C_word *av) C_noret;
C_noret_decl(f_3339)
static void C_ccall f_3339(C_word c,C_word *av) C_noret;
C_noret_decl(f_3345)
static void C_ccall f_3345(C_word c,C_word *av) C_noret;
C_noret_decl(f_3361)
static void C_ccall f_3361(C_word c,C_word *av) C_noret;
C_noret_decl(f_3367)
static void C_ccall f_3367(C_word c,C_word *av) C_noret;
C_noret_decl(f_3376)
static void C_ccall f_3376(C_word c,C_word *av) C_noret;
C_noret_decl(f_3385)
static void C_ccall f_3385(C_word c,C_word *av) C_noret;
C_noret_decl(f_3387)
static void C_fcall f_3387(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3395)
static void C_ccall f_3395(C_word c,C_word *av) C_noret;
C_noret_decl(f_3408)
static void C_ccall f_3408(C_word c,C_word *av) C_noret;
C_noret_decl(f_3410)
static void C_fcall f_3410(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3417)
static void C_fcall f_3417(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3443)
static void C_ccall f_3443(C_word c,C_word *av) C_noret;
C_noret_decl(f_3473)
static void C_ccall f_3473(C_word c,C_word *av) C_noret;
C_noret_decl(f_3476)
static void C_ccall f_3476(C_word c,C_word *av) C_noret;
C_noret_decl(f_3484)
static void C_fcall f_3484(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3494)
static void C_ccall f_3494(C_word c,C_word *av) C_noret;
C_noret_decl(f_3509)
static void C_ccall f_3509(C_word c,C_word *av) C_noret;
C_noret_decl(f_3520)
static void C_ccall f_3520(C_word c,C_word *av) C_noret;
C_noret_decl(f_3530)
static void C_fcall f_3530(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3554)
static void C_fcall f_3554(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3583)
static void C_ccall f_3583(C_word c,C_word *av) C_noret;
C_noret_decl(f_3594)
static void C_fcall f_3594(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3623)
static void C_ccall f_3623(C_word c,C_word *av) C_noret;
C_noret_decl(f_3642)
static void C_fcall f_3642(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3677)
static void C_ccall f_3677(C_word c,C_word *av) C_noret;
C_noret_decl(f_3685)
static void C_fcall f_3685(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3733)
static void C_ccall f_3733(C_word c,C_word *av) C_noret;
C_noret_decl(f_3737)
static void C_ccall f_3737(C_word c,C_word *av) C_noret;
C_noret_decl(f_3746)
static void C_fcall f_3746(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3764)
static void C_ccall f_3764(C_word c,C_word *av) C_noret;
C_noret_decl(f_3771)
static void C_fcall f_3771(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3784)
static void C_ccall f_3784(C_word c,C_word *av) C_noret;
C_noret_decl(f_3800)
static void C_ccall f_3800(C_word c,C_word *av) C_noret;
C_noret_decl(f_3802)
static void C_fcall f_3802(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3827)
static void C_ccall f_3827(C_word c,C_word *av) C_noret;
C_noret_decl(f_3836)
static void C_fcall f_3836(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3857)
static void C_ccall f_3857(C_word c,C_word *av) C_noret;
C_noret_decl(f_3865)
static void C_ccall f_3865(C_word c,C_word *av) C_noret;
C_noret_decl(f_3874)
static void C_ccall f_3874(C_word c,C_word *av) C_noret;
C_noret_decl(f_3885)
static void C_ccall f_3885(C_word c,C_word *av) C_noret;
C_noret_decl(f_3891)
static void C_ccall f_3891(C_word c,C_word *av) C_noret;
C_noret_decl(f_3895)
static void C_ccall f_3895(C_word c,C_word *av) C_noret;
C_noret_decl(f_3897)
static void C_ccall f_3897(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(va4346)
static void C_fcall va4346(C_word t0,C_word t1) C_noret;

C_noret_decl(trf_1386)
static void C_ccall trf_1386(C_word c,C_word *av) C_noret;
static void C_ccall trf_1386(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1386(t0,t1,t2);}

C_noret_decl(trf_1896)
static void C_ccall trf_1896(C_word c,C_word *av) C_noret;
static void C_ccall trf_1896(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1896(t0,t1,t2);}

C_noret_decl(trf_2563)
static void C_ccall trf_2563(C_word c,C_word *av) C_noret;
static void C_ccall trf_2563(C_word c,C_word *av){
C_word t0=av[0];
f_2563(t0);}

C_noret_decl(trf_2610)
static void C_ccall trf_2610(C_word c,C_word *av) C_noret;
static void C_ccall trf_2610(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2610(t0,t1,t2);}

C_noret_decl(trf_2620)
static void C_ccall trf_2620(C_word c,C_word *av) C_noret;
static void C_ccall trf_2620(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2620(t0,t1);}

C_noret_decl(trf_2660)
static void C_ccall trf_2660(C_word c,C_word *av) C_noret;
static void C_ccall trf_2660(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2660(t0,t1);}

C_noret_decl(trf_2679)
static void C_ccall trf_2679(C_word c,C_word *av) C_noret;
static void C_ccall trf_2679(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2679(t0,t1);}

C_noret_decl(trf_2941)
static void C_ccall trf_2941(C_word c,C_word *av) C_noret;
static void C_ccall trf_2941(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2941(t0,t1,t2);}

C_noret_decl(trf_3031)
static void C_ccall trf_3031(C_word c,C_word *av) C_noret;
static void C_ccall trf_3031(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3031(t0,t1,t2);}

C_noret_decl(trf_3087)
static void C_ccall trf_3087(C_word c,C_word *av) C_noret;
static void C_ccall trf_3087(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3087(t0,t1,t2,t3);}

C_noret_decl(trf_3097)
static void C_ccall trf_3097(C_word c,C_word *av) C_noret;
static void C_ccall trf_3097(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3097(t0,t1);}

C_noret_decl(trf_3214)
static void C_ccall trf_3214(C_word c,C_word *av) C_noret;
static void C_ccall trf_3214(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3214(t0,t1,t2);}

C_noret_decl(trf_3294)
static void C_ccall trf_3294(C_word c,C_word *av) C_noret;
static void C_ccall trf_3294(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3294(t0,t1);}

C_noret_decl(trf_3387)
static void C_ccall trf_3387(C_word c,C_word *av) C_noret;
static void C_ccall trf_3387(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3387(t0,t1,t2);}

C_noret_decl(trf_3410)
static void C_ccall trf_3410(C_word c,C_word *av) C_noret;
static void C_ccall trf_3410(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3410(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3417)
static void C_ccall trf_3417(C_word c,C_word *av) C_noret;
static void C_ccall trf_3417(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3417(t0,t1);}

C_noret_decl(trf_3484)
static void C_ccall trf_3484(C_word c,C_word *av) C_noret;
static void C_ccall trf_3484(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3484(t0,t1,t2);}

C_noret_decl(trf_3530)
static void C_ccall trf_3530(C_word c,C_word *av) C_noret;
static void C_ccall trf_3530(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3530(t0,t1,t2,t3);}

C_noret_decl(trf_3554)
static void C_ccall trf_3554(C_word c,C_word *av) C_noret;
static void C_ccall trf_3554(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3554(t0,t1,t2,t3);}

C_noret_decl(trf_3594)
static void C_ccall trf_3594(C_word c,C_word *av) C_noret;
static void C_ccall trf_3594(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3594(t0,t1,t2,t3);}

C_noret_decl(trf_3642)
static void C_ccall trf_3642(C_word c,C_word *av) C_noret;
static void C_ccall trf_3642(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3642(t0,t1,t2);}

C_noret_decl(trf_3685)
static void C_ccall trf_3685(C_word c,C_word *av) C_noret;
static void C_ccall trf_3685(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3685(t0,t1,t2);}

C_noret_decl(trf_3746)
static void C_ccall trf_3746(C_word c,C_word *av) C_noret;
static void C_ccall trf_3746(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3746(t0,t1,t2);}

C_noret_decl(trf_3771)
static void C_ccall trf_3771(C_word c,C_word *av) C_noret;
static void C_ccall trf_3771(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3771(t0,t1);}

C_noret_decl(trf_3802)
static void C_ccall trf_3802(C_word c,C_word *av) C_noret;
static void C_ccall trf_3802(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3802(t0,t1,t2);}

C_noret_decl(trf_3836)
static void C_ccall trf_3836(C_word c,C_word *av) C_noret;
static void C_ccall trf_3836(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3836(t0,t1,t2,t3);}

C_noret_decl(trva4346)
static void C_ccall trva4346(C_word c,C_word *av) C_noret;
static void C_ccall trva4346(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
va4346(t0,t1);}

/* k1256 */
static void C_ccall f_1258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1258,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1261,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k1259 in k1256 */
static void C_ccall f_1261(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_1261,c,av);}
a=C_alloc(13);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1264,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3897,tmp=(C_word)a,a+=2,tmp);
/* chicken-profile.scm:29: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[93]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[93]+1);
av2[1]=t3;
av2[2]=t4;
tp(3,av2);}}

/* k1262 in k1259 in k1256 */
static void C_ccall f_1264(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1264,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1267,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_1267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1267,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1270,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_posix_toplevel(2,av2);}}

/* k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_1270(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1270,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1273,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_1273(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1273,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1276,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_1276(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_1276,c,av);}
a=C_alloc(24);
t2=C_mutate(&lf[1] /* (set! main#take ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_1386,tmp=(C_word)a,a+=2,tmp));
t3=lf[2] /* main#file */ =C_SCHEME_FALSE;;
t4=lf[3] /* main#no-unused */ =C_SCHEME_FALSE;;
t5=lf[4] /* main#seconds-digits */ =C_fix(3);;
t6=lf[5] /* main#average-digits */ =C_fix(3);;
t7=lf[6] /* main#percent-digits */ =C_fix(3);;
t8=lf[7] /* main#top */ =C_fix(0);;
t9=C_mutate(&lf[8] /* (set! main#print-usage ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2563,tmp=(C_word)a,a+=2,tmp));
t10=C_mutate(&lf[16] /* (set! main#sort-by-calls ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2824,tmp=(C_word)a,a+=2,tmp));
t11=C_mutate(&lf[17] /* (set! main#sort-by-time ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2858,tmp=(C_word)a,a+=2,tmp));
t12=C_mutate(&lf[18] /* (set! main#sort-by-avg ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2887,tmp=(C_word)a,a+=2,tmp));
t13=C_mutate(&lf[19] /* (set! main#sort-by-name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2915,tmp=(C_word)a,a+=2,tmp));
t14=C_mutate(&lf[22] /* (set! main#sort-by ...) */,C_retrieve2(lf[17],C_text("main#sort-by-time")));
t15=C_mutate(&lf[23] /* (set! main#read-profile ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2999,tmp=(C_word)a,a+=2,tmp));
t16=C_mutate(&lf[32] /* (set! main#format-string ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3148,tmp=(C_word)a,a+=2,tmp));
t17=C_mutate(&lf[35] /* (set! main#format-real ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3214,tmp=(C_word)a,a+=2,tmp));
t18=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3885,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t19=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3895,a[2]=t18,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:262: chicken.process-context#command-line-arguments */
t20=C_fast_retrieve(lf[90]);{
C_word *av2=av;
av2[0]=t20;
av2[1]=t19;
((C_proc)(void*)(*((C_word*)t20+1)))(2,av2);}}

/* main#take in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_1386(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_1386,3,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_fixnum_less_or_equal_p(t3,C_fix(0)))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1404,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:56: take */
t7=t5;
t8=C_u_i_cdr(t2);
t9=C_fixnum_difference(t3,C_fix(1));
t1=t7;
t2=t8;
t3=t9;
goto loop;}}

/* k1402 in main#take in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_1404(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1404,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* foldr290 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_1896(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_1896,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1925,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t6=t4;
t7=C_slot(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k1923 in foldr290 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_1925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1925,c,av);}
a=C_alloc(3);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_greaterp(t2,C_fix(0));
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_a_i_cons(&a,2,((C_word*)t0)[2],t1):t1);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* main#print-usage in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_2563(C_word t1){
C_word tmp;
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(27,0,2)))){
C_save_and_reclaim_args((void *)trf_2563,1,t1);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2567,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2574,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,lf[11],C_SCHEME_END_OF_LIST);
t5=C_a_i_cons(&a,2,C_retrieve2(lf[6],C_text("main#percent-digits")),t4);
t6=C_a_i_cons(&a,2,lf[12],t5);
t7=C_a_i_cons(&a,2,C_retrieve2(lf[5],C_text("main#average-digits")),t6);
t8=C_a_i_cons(&a,2,lf[13],t7);
t9=C_a_i_cons(&a,2,C_retrieve2(lf[4],C_text("main#seconds-digits")),t8);
t10=C_a_i_cons(&a,2,lf[14],t9);
/* chicken-profile.scm:29: ##sys#print-to-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word av2[3];
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t3;
av2[2]=t10;
tp(3,av2);}}

/* k2565 in main#print-usage in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2567,c,av);}
/* chicken-profile.scm:76: chicken.base#exit */
t2=C_fast_retrieve(lf[9]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(64);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k2572 in main#print-usage in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2574,c,av);}
/* chicken-profile.scm:55: scheme#display */
t2=*((C_word*)lf[10]+1);{
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

/* loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_2610(C_word t0,C_word t1,C_word t2){
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
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,0,3)))){
C_save_and_reclaim_args((void *)trf_2610,3,t0,t1,t2);}
a=C_alloc(23);
if(C_truep(C_i_nullp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2620,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[2],C_text("main#file")))){
t4=t3;
f_2620(t4,C_SCHEME_UNDEFINED);}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2627,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:84: chicken.file#glob */
t5=C_fast_retrieve(lf[68]);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[69];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2660,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t10=t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2679,a[2]=t3,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2702,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
if(C_truep((C_truep(C_i_equalp(t3,lf[73]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[74]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[75]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))){
/* chicken-profile.scm:104: print-usage */
f_2563(t11);}
else{
if(C_truep(C_i_string_equal_p(t3,lf[76]))){
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2720,a[2]=t11,tmp=(C_word)a,a+=3,tmp);
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2727,a[2]=t12,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:106: chicken.platform#chicken-version */
t14=C_fast_retrieve(lf[78]);{
C_word av2[2];
av2[0]=t14;
av2[1]=t13;
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[79]))){
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2735,a[2]=t11,tmp=(C_word)a,a+=3,tmp);
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2742,a[2]=t12,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:109: chicken.platform#chicken-version */
t14=C_fast_retrieve(lf[78]);{
C_word av2[2];
av2[0]=t14;
av2[1]=t13;
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[80]))){
t12=lf[3] /* main#no-unused */ =C_SCHEME_TRUE;;
/* chicken-profile.scm:122: loop */
t17=t1;
t18=((C_word*)t5)[1];
t1=t17;
t2=t18;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[81]))){
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2757,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* chicken-profile.scm:112: next-number */
t13=t8;
f_2679(t13,t12);}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[82]))){
t12=C_mutate(&lf[22] /* (set! main#sort-by ...) */,C_retrieve2(lf[16],C_text("main#sort-by-calls")));
/* chicken-profile.scm:122: loop */
t17=t1;
t18=((C_word*)t5)[1];
t1=t17;
t2=t18;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[83]))){
t12=C_mutate(&lf[22] /* (set! main#sort-by ...) */,C_retrieve2(lf[17],C_text("main#sort-by-time")));
/* chicken-profile.scm:122: loop */
t17=t1;
t18=((C_word*)t5)[1];
t1=t17;
t2=t18;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[84]))){
t12=C_mutate(&lf[22] /* (set! main#sort-by ...) */,C_retrieve2(lf[18],C_text("main#sort-by-avg")));
/* chicken-profile.scm:122: loop */
t17=t1;
t18=((C_word*)t5)[1];
t1=t17;
t2=t18;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[85]))){
t12=C_mutate(&lf[22] /* (set! main#sort-by ...) */,C_retrieve2(lf[19],C_text("main#sort-by-name")));
t13=t11;{
C_word av2[2];
av2[0]=t13;
av2[1]=t12;
f_2702(2,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(t3,lf[86]))){
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2793,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t5,a[5]=t11,tmp=(C_word)a,a+=6,tmp);
/* chicken-profile.scm:117: next-arg */
t13=((C_word*)t7)[1];
f_2660(t13,t12);}
else{
t12=C_block_size(t3);
t13=C_fixnum_greaterp(t12,C_fix(1));
t14=(C_truep(t13)?C_u_i_char_equalp(C_make_character(45),C_i_string_ref(t3,C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t14)){
/* chicken-profile.scm:119: chicken.base#error */
t15=*((C_word*)lf[65]+1);{
C_word av2[4];
av2[0]=t15;
av2[1]=t11;
av2[2]=lf[89];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t15+1)))(4,av2);}}
else{
if(C_truep(C_retrieve2(lf[2],C_text("main#file")))){
/* chicken-profile.scm:120: print-usage */
f_2563(t11);}
else{
t15=C_mutate(&lf[2] /* (set! main#file ...) */,t3);
/* chicken-profile.scm:122: loop */
t17=t1;
t18=((C_word*)t5)[1];
t1=t17;
t2=t18;
goto loop;}}}}}}}}}}}}}}

/* k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_2620(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_2620,2,t0,t1);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3275,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:205: chicken.base#print */
t3=*((C_word*)lf[51]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[63];
av2[3]=C_retrieve2(lf[2],C_text("main#file"));
av2[4]=lf[64];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k2625 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2627(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2627,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2630,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t1))){
/* chicken-profile.scm:86: chicken.base#error */
t3=*((C_word*)lf[65]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[66];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2643,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2645,tmp=(C_word)a,a+=2,tmp);
/* chicken-profile.scm:87: chicken.sort#sort */
t5=C_fast_retrieve(lf[61]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t1;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k2628 in k2625 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2630(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2630,c,av);}
t2=C_mutate(&lf[2] /* (set! main#file ...) */,t1);
t3=((C_word*)t0)[2];
f_2620(t3,t2);}

/* k2641 in k2625 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2643,c,av);}
t2=C_i_car(t1);
t3=C_mutate(&lf[2] /* (set! main#file ...) */,t2);
t4=((C_word*)t0)[2];
f_2620(t4,t3);}

/* a2644 in k2625 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2645,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2650,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:89: chicken.file.posix#file-modification-time */
t5=C_fast_retrieve(lf[67]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2648 in a2644 in k2625 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2650,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2654,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:90: chicken.file.posix#file-modification-time */
t3=C_fast_retrieve(lf[67]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2652 in k2648 in a2644 in k2625 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2654(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2654,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_integer_greaterp(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* next-arg in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_2660(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_2660,2,t0,t1);}
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[2])[1]))){
/* chicken-profile.scm:96: chicken.base#error */
t2=*((C_word*)lf[65]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[70];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* next-number in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_2679(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_2679,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2683,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2699,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:101: next-arg */
t4=((C_word*)((C_word*)t0)[3])[1];
f_2660(t4,t3);}

/* k2681 in next-number in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2683,c,av);}
if(C_truep(t1)){
if(C_truep(C_i_greaterp(t1,C_fix(0)))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* chicken-profile.scm:102: chicken.base#error */
t2=*((C_word*)lf[65]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[71];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}
else{
/* chicken-profile.scm:102: chicken.base#error */
t2=*((C_word*)lf[65]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[71];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k2697 in next-number in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2699,c,av);}
/* chicken-profile.scm:101: scheme#string->number */
t2=*((C_word*)lf[72]+1);{
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

/* k2700 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2702,c,av);}
/* chicken-profile.scm:122: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2610(t2,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k2718 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2720,c,av);}
/* chicken-profile.scm:107: chicken.base#exit */
t2=C_fast_retrieve(lf[9]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2725 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2727(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2727,c,av);}
/* chicken-profile.scm:106: chicken.base#print */
t2=*((C_word*)lf[51]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[77];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k2733 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2735,c,av);}
/* chicken-profile.scm:110: chicken.base#exit */
t2=C_fast_retrieve(lf[9]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2740 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2742(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2742,c,av);}
/* chicken-profile.scm:109: chicken.base#print */
t2=*((C_word*)lf[51]+1);{
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

/* k2755 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2757(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2757,c,av);}
t2=C_mutate(&lf[7] /* (set! main#top ...) */,t1);
/* chicken-profile.scm:122: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2610(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k2791 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2793(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2793,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2941,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=C_i_string_length(t1);
t4=C_eqp(t3,C_fix(3));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2975,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-profile.scm:159: arg-digit */
t6=t2;
f_2941(t6,t5,C_fix(0));}
else{
/* chicken-profile.scm:162: chicken.base#error */
t5=*((C_word*)lf[65]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[88];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* main#sort-by-calls in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2824(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2824,c,av);}
t4=C_i_cadr(t2);
t5=C_i_cadr(t3);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=(C_truep(C_i_eqvp(t4,t5))?C_i_greaterp(C_i_caddr(t2),C_i_caddr(t3)):(C_truep(t4)?(C_truep(t5)?C_i_greaterp(t4,t5):C_SCHEME_TRUE):C_SCHEME_TRUE));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* main#sort-by-time in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2858(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2858,c,av);}
t4=C_i_caddr(t2);
t5=C_i_caddr(t3);
t6=C_i_nequalp(t4,t5);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=(C_truep(t6)?C_i_greaterp(C_i_cadr(t2),C_i_cadr(t3)):C_i_greaterp(t4,t5));
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* main#sort-by-avg in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2887(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2887,c,av);}
t4=C_i_cadddr(t2);
t5=C_i_cadddr(t3);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=(C_truep(C_i_eqvp(t4,t5))?C_i_greaterp(C_i_caddr(t2),C_i_caddr(t3)):C_i_greaterp(t4,t5));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* main#sort-by-name in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2915,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2923,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:146: scheme#symbol->string */
t5=*((C_word*)lf[21]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2921 in main#sort-by-name in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2923,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2927,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:146: scheme#symbol->string */
t3=*((C_word*)lf[21]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2925 in k2921 in main#sort-by-name in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2927,c,av);}
/* chicken-profile.scm:146: scheme#string<? */
t2=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* arg-digit in k2791 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_2941(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_2941,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_i_string_ref(((C_word*)t0)[2],t2);
t4=C_fix(C_character_code(t3));
t5=C_a_i_fixnum_difference(&a,2,t4,C_fix(48));
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2953,a[2]=t1,a[3]=t5,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* chicken-profile.scm:154: scheme#<= */{
C_word av2[5];
av2[0]=0;
av2[1]=t6;
av2[2]=C_fix(0);
av2[3]=t5;
av2[4]=C_fix(9);
C_less_or_equal_p(5,av2);}}

/* k2951 in arg-digit in k2791 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2953(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2953,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(C_i_integer_equalp(((C_word*)t0)[3],C_fix(9)))?C_fix(8):((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* chicken-profile.scm:156: chicken.base#error */
t2=*((C_word*)lf[65]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[87];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k2973 in k2791 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2975,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[4] /* (set! main#seconds-digits ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2979,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken-profile.scm:160: arg-digit */
t4=((C_word*)t0)[5];
f_2941(t4,t3,C_fix(1));}

/* k2977 in k2973 in k2791 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2979(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2979,c,av);}
a=C_alloc(5);
t2=C_mutate(&lf[5] /* (set! main#average-digits ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2983,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-profile.scm:161: arg-digit */
t4=((C_word*)t0)[5];
f_2941(t4,t3,C_fix(2));}

/* k2981 in k2977 in k2973 in k2791 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2983,c,av);}
t2=C_mutate(&lf[6] /* (set! main#percent-digits ...) */,t1);
/* chicken-profile.scm:122: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2610(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_2999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_2999,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3003,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:165: scheme#make-vector */
t3=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(3001);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3003,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3006,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:169: scheme#read */
t3=*((C_word*)lf[26]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3006(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3006,c,av);}
a=C_alloc(9);
t2=C_i_symbolp(t1);
t3=(C_truep(t2)?t1:lf[24]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3012,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3029,a[2]=((C_word*)t0)[3],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_symbolp(t1))){
/* chicken-profile.scm:171: scheme#read */
t6=*((C_word*)lf[26]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
f_3029(2,av2);}}}

/* k3010 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3012(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_3012,c,av);}
a=C_alloc(10);
t2=C_SCHEME_END_OF_LIST;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3015,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3020,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:179: chicken.internal#hash-table-for-each */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[25]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[25]+1);
av2[1]=t4;
av2[2]=t5;
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}

/* k3013 in k3010 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3015,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a3019 in k3010 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3020(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_3020,c,av);}
a=C_alloc(6);
t4=((C_word*)((C_word*)t0)[2])[1];
t5=C_a_i_cons(&a,2,t2,t3);
t6=C_a_i_cons(&a,2,t5,t4);
t7=C_mutate(((C_word *)((C_word*)t0)[2])+1,t6);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3029,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3031,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_3031(t5,((C_word*)t0)[3],t1);}

/* doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3031(C_word t0,C_word t1,C_word t2){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(17,0,3)))){
C_save_and_reclaim_args((void *)trf_3031,3,t0,t1,t2);}
a=C_alloc(17);
if(C_truep(C_eofp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3041,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=C_i_car(t2);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3070,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=t7,a[7]=t8,tmp=(C_word)a,a+=8,tmp);
/* chicken-profile.scm:176: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[30]);
C_word av2[4];
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t9;
av2[2]=((C_word*)t0)[3];
av2[3]=C_i_car(t2);
tp(4,av2);}}}

/* k3039 in doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3041,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3048,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:171: scheme#read */
t3=*((C_word*)lf[26]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3046 in k3039 in doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3048(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3048,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3031(t2,((C_word*)t0)[3],t1);}

/* k3068 in doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3070(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_3070,c,av);}
a=C_alloc(12);
t2=(C_truep(t1)?t1:lf[27]);
t3=C_i_cdr(((C_word*)t0)[2]);
t4=C_i_check_list_2(t2,lf[28]);
t5=C_i_check_list_2(t3,lf[28]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3085,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3087,a[2]=((C_word*)t0)[6],a[3]=t8,a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_3087(t10,t6,t2,t3);}

/* k3083 in k3068 in doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3085(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3085,c,av);}
/* chicken-profile.scm:173: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[29]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[29]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
tp(5,av2);}}

/* map-loop651 in k3068 in doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3087(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(39,0,2)))){
C_save_and_reclaim_args((void *)trf_3087,4,t0,t1,t2,t3);}
a=C_alloc(39);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3097,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
t7=C_slot(t2,C_fix(0));
t8=C_slot(t3,C_fix(0));
if(C_truep(t7)){
if(C_truep(t8)){
t9=C_s_a_i_plus(&a,2,t7,t8);
t10=t6;
f_3097(t10,C_a_i_cons(&a,2,t9,C_SCHEME_END_OF_LIST));}
else{
t9=t6;
f_3097(t9,C_a_i_cons(&a,2,C_SCHEME_FALSE,C_SCHEME_END_OF_LIST));}}
else{
t9=t6;
f_3097(t9,C_a_i_cons(&a,2,C_SCHEME_FALSE,C_SCHEME_END_OF_LIST));}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k3095 in map-loop651 in k3068 in doloop646 in k3027 in k3004 in k3001 in main#read-profile in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3097(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_3097,2,t0,t1);}
t2=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t1);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t4=((C_word*)((C_word*)t0)[3])[1];
f_3087(t4,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)),C_slot(((C_word*)t0)[6],C_fix(1)));}

/* main#format-string in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3148(C_word c,C_word *av){
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
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3148,c,av);}
a=C_alloc(5);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_make_character(32):C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_i_string_length(t2);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3167,a[2]=t5,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t12=C_fixnum_difference(t3,t10);
/* chicken-profile.scm:187: scheme#make-string */
t13=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t13;
av2[1]=t11;
av2[2]=C_i_fixnum_max(C_fix(0),t12);
av2[3]=t8;
((C_proc)(void*)(*((C_word*)t13+1)))(4,av2);}}

/* k3165 in main#format-string in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3167,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[33]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[33]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}
else{
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[33]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[33]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
tp(4,av2);}}}

/* main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3214(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_3214,3,t1,t2,t3);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3218,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3269,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:193: scheme#truncate */
t6=*((C_word*)lf[42]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3218,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3225,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[40]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[40]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=C_fix(10);
tp(4,av2);}}

/* k3223 in k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3225(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(48,c,2)))){
C_save_and_reclaim((void *)f_3225,c,av);}
a=C_alloc(48);
t2=C_i_greaterp(((C_word*)t0)[2],C_fix(0));
t3=(C_truep(t2)?lf[36]:lf[37]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3233,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3237,a[2]=((C_word*)t0)[2],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3245,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3249,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)va4346,a[2]=t7,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t9=t8;
va4346(t9,C_s_a_i_minus(&a,2,((C_word*)t0)[4],((C_word*)t0)[5]));}

/* k3231 in k3223 in k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3233,c,av);}
/* chicken-profile.scm:194: scheme#string-append */
t2=*((C_word*)lf[38]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3235 in k3223 in k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3237(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,4)))){
C_save_and_reclaim((void *)f_3237,c,av);}
a=C_alloc(29);
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1));
/* chicken-profile.scm:197: scheme#substring */
t3=*((C_word*)lf[39]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=C_fix(1);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3243 in k3223 in k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3245,c,av);}
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[40]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[40]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(10);
tp(4,av2);}}

/* k3247 in k3223 in k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3249,c,av);}
/* chicken-profile.scm:199: scheme#inexact->exact */
t2=*((C_word*)lf[41]+1);{
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

/* k3259 */
static void C_ccall f_3261(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,2)))){
C_save_and_reclaim((void *)f_3261,c,av);}
a=C_alloc(33);
t2=C_s_a_i_times(&a,2,((C_word*)t0)[2],t1);
/* chicken-profile.scm:200: scheme#truncate */
t3=*((C_word*)lf[42]+1);{
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

/* k3267 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3269,c,av);}
/* chicken-profile.scm:193: scheme#inexact->exact */
t2=*((C_word*)lf[41]+1);{
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

/* k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3275,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3278,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-profile.scm:206: scheme#with-input-from-file */
t3=C_fast_retrieve(lf[62]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_retrieve2(lf[2],C_text("main#file"));
av2[3]=C_retrieve2(lf[23],C_text("main#read-profile"));
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3278(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_3278,c,av);}
a=C_alloc(10);
t2=C_i_car(t1);
t3=C_u_i_cdr(t1);
t4=C_i_check_list_2(t3,lf[45]);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3288,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3836,a[2]=t2,a[3]=t7,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_3836(t9,t5,t3,C_fix(0));}

/* k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3288(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_3288,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3291,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3746,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3800,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3802,a[2]=t5,a[3]=t10,a[4]=t7,a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_3802(t12,t8,((C_word*)t0)[3]);}

/* k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3291(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_3291,c,av);}
a=C_alloc(10);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3294,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3733,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:230: scheme#< */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t5;
av2[2]=C_fix(0);
av2[3]=C_retrieve2(lf[7],C_text("main#top"));
av2[4]=C_i_length(((C_word*)t3)[1]);
C_lessp(5,av2);}}

/* k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3294(C_word t0,C_word t1){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_3294,2,t0,t1);}
a=C_alloc(16);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3361,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_retrieve2(lf[3],C_text("main#no-unused")))){
t7=((C_word*)((C_word*)t0)[2])[1];
t8=C_i_check_list_2(t7,lf[59]);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1896,a[2]=t10,tmp=(C_word)a,a+=3,tmp));
t12=((C_word*)t10)[1];
f_1896(t12,t6,t7);}
else{
t7=t6;{
C_word av2[2];
av2[0]=t7;
av2[1]=((C_word*)((C_word*)t0)[2])[1];
f_3361(2,av2);}}}

/* k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3319,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3323,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
if(C_truep(C_i_not(((C_word*)t0)[9]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[57];
f_3323(2,av2);}}
else{
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[40]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[40]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[9];
av2[3]=C_fix(10);
tp(4,av2);}}}

/* k3321 in k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_3323,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3327,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3345,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#/-2 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[56]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[56]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
av2[3]=C_fix(1000);
tp(4,av2);}}

/* k3325 in k3321 in k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_3327,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3331,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3339,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#/-2 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[56]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[56]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[9];
av2[3]=C_fix(1000);
tp(4,av2);}}

/* k3329 in k3325 in k3321 in k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3331(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3331,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3335,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* chicken-profile.scm:241: format-real */
f_3214(t2,((C_word*)t0)[9],C_retrieve2(lf[6],C_text("main#percent-digits")));}

/* k3333 in k3329 in k3325 in k3321 in k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 in ... */
static void C_ccall f_3335(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_3335,c,av);}
a=C_alloc(18);
t2=C_a_i_list5(&a,5,((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[6])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[6])+1,t3);
t6=((C_word*)((C_word*)t0)[7])[1];
f_3685(t6,((C_word*)t0)[8],C_slot(((C_word*)t0)[9],C_fix(1)));}

/* k3337 in k3325 in k3321 in k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3339(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3339,c,av);}
/* chicken-profile.scm:240: format-real */
f_3214(((C_word*)t0)[2],t1,C_retrieve2(lf[5],C_text("main#average-digits")));}

/* k3343 in k3321 in k3317 in map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3345(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3345,c,av);}
/* chicken-profile.scm:239: format-real */
f_3214(((C_word*)t0)[2],t1,C_retrieve2(lf[4],C_text("main#seconds-digits")));}

/* k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3361(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_3361,c,av);}
a=C_alloc(11);
t2=C_i_check_list_2(t1,lf[28]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3367,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3685,a[2]=((C_word*)t0)[4],a[3]=t5,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_3685(t7,t3,t1);}

/* k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3367(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(36,c,3)))){
C_save_and_reclaim((void *)f_3367,c,av);}
a=C_alloc(36);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_a_i_list5(&a,5,lf[46],lf[47],lf[48],lf[49],lf[50]);
t4=C_a_i_list5(&a,5,C_SCHEME_FALSE,C_SCHEME_TRUE,C_SCHEME_TRUE,C_SCHEME_TRUE,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3376,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t4,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[55]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[55]+1);
av2[1]=t5;
av2[2]=C_fix(2);
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3376(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,c,4)))){
C_save_and_reclaim((void *)f_3376,c,av);}
a=C_alloc(30);
t2=C_a_i_list5(&a,5,C_fix(0),C_fix(0),C_fix(0),C_fix(0),C_fix(0));
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3385,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3554,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_3554(t8,t4,t3,t2);}

/* k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_3385,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3387,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3473,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=t1,a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
/* chicken-profile.scm:256: print-row */
t4=t2;
f_3387(t4,t3,((C_word*)t0)[6]);}

/* print-row in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3387(C_word t0,C_word t1,C_word t2){
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
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(19,0,5)))){
C_save_and_reclaim_args((void *)trf_3387,3,t0,t1,t2);}
a=C_alloc(19);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3395,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_retrieve2(lf[32],C_text("main#format-string"));
t9=C_i_check_list_2(t2,lf[28]);
t10=C_i_check_list_2(((C_word*)t0)[2],lf[28]);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3408,a[2]=t3,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3410,a[2]=t6,a[3]=t13,a[4]=t7,tmp=(C_word)a,a+=5,tmp));
t15=((C_word*)t13)[1];
f_3410(t15,t11,t2,((C_word*)t0)[2],((C_word*)t0)[4]);}

/* k3393 in print-row in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3395,c,av);}
/* chicken-profile.scm:255: chicken.base#print */
t2=*((C_word*)lf[51]+1);{
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

/* k3406 in print-row in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3408(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3408,c,av);}
/* chicken-profile.scm:255: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[52]);{
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

/* map-loop908 in print-row in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3410(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_3410,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3417,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,a[7]=t4,a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_pairp(t2))){
t6=C_i_pairp(t3);
t7=t5;
f_3417(t7,(C_truep(t6)?C_i_pairp(t4):C_SCHEME_FALSE));}
else{
t6=t5;
f_3417(t6,C_SCHEME_FALSE);}}

/* k3415 in map-loop908 in print-row in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 in ... */
static void C_fcall f_3417(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_3417,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3443,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* chicken-profile.scm:255: g914 */
t3=C_retrieve2(lf[32],C_text("main#format-string"));{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[5],C_fix(0));
av2[3]=C_slot(((C_word*)t0)[6],C_fix(0));
av2[4]=C_slot(((C_word*)t0)[7],C_fix(0));
f_3148(5,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[8],C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3441 in k3415 in map-loop908 in print-row in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in ... */
static void C_ccall f_3443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3443,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3410(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)),C_slot(((C_word*)t0)[6],C_fix(1)),C_slot(((C_word*)t0)[7],C_fix(1)));}

/* k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3473(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_3473,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3476,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3509,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_i_check_list_2(((C_word*)t0)[5],lf[45]);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3520,a[2]=((C_word*)t0)[6],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3530,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_3530(t9,t5,((C_word*)t0)[5],C_fix(0));}

/* k3474 in k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3476(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3476,c,av);}
a=C_alloc(6);
t2=((C_word*)((C_word*)t0)[2])[1];
t3=C_i_check_list_2(t2,lf[53]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3484,a[2]=t5,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_3484(t7,((C_word*)t0)[4],t2);}

/* for-each-loop897 in k3474 in k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 in ... */
static void C_fcall f_3484(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3484,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3494,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-profile.scm:260: g898 */
t4=((C_word*)t0)[3];
f_3387(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3492 in for-each-loop897 in k3474 in k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in ... */
static void C_ccall f_3494(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3494,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3484(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k3507 in k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3509,c,av);}
/* chicken-profile.scm:257: chicken.base#print */
t2=*((C_word*)lf[51]+1);{
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

/* k3518 in k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3520(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(39,c,3)))){
C_save_and_reclaim((void *)f_3520,c,av);}
a=C_alloc(39);
t2=C_i_length(((C_word*)t0)[2]);
t3=C_a_i_fixnum_difference(&a,2,t2,C_fix(1));
t4=C_s_a_u_i_integer_times(&a,2,C_fix(2),t3);
t5=C_s_a_i_plus(&a,2,t1,t4);
/* chicken-profile.scm:257: scheme#make-string */
t6=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[3];
av2[2]=t5;
av2[3]=C_make_character(45);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* foldl947 in k3471 in k3383 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3530(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,0,3)))){
C_save_and_reclaim_args((void *)trf_3530,4,t0,t1,t2,t3);}
a=C_alloc(29);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=C_slot(t2,C_fix(0));
t6=C_s_a_i_plus(&a,2,t3,t5);
t8=t1;
t9=t4;
t10=t6;
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* foldl824 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3554(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(28,0,3)))){
C_save_and_reclaim_args((void *)trf_3554,4,t0,t1,t2,t3);}
a=C_alloc(28);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3677,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_slot(t2,C_fix(0));
t7=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t8=t7;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=((C_word*)t9)[1];
t11=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t12=t11;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=((C_word*)t13)[1];
t15=C_i_check_list_2(t6,lf[28]);
t16=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3583,a[2]=t3,a[3]=t9,a[4]=t10,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
t17=C_SCHEME_UNDEFINED;
t18=(*a=C_VECTOR_TYPE|1,a[1]=t17,tmp=(C_word)a,a+=2,tmp);
t19=C_set_block_item(t18,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3642,a[2]=t13,a[3]=t18,a[4]=t14,tmp=(C_word)a,a+=5,tmp));
t20=((C_word*)t18)[1];
f_3642(t20,t16,t6);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3581 in foldl824 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3583(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3583,c,av);}
a=C_alloc(7);
t2=C_i_check_list_2(t1,lf[28]);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[28]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3594,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_3594(t7,((C_word*)t0)[5],t1,((C_word*)t0)[2]);}

/* map-loop837 in k3581 in foldl824 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3594(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_3594,4,t0,t1,t2,t3);}
a=C_alloc(7);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3623,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* chicken-profile.scm:251: g843 */
t7=*((C_word*)lf[54]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=C_slot(t3,C_fix(0));
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k3621 in map-loop837 in k3581 in foldl824 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 in ... */
static void C_ccall f_3623(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3623,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3594(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)),C_slot(((C_word*)t0)[6],C_fix(1)));}

/* map-loop858 in foldl824 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3642(C_word t0,C_word t1,C_word t2){
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
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_3642,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_string_length(t3);
t5=C_a_i_cons(&a,2,t4,C_SCHEME_END_OF_LIST);
t6=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t5);
t7=C_mutate(((C_word *)((C_word*)t0)[2])+1,t5);
t9=t1;
t10=C_slot(t2,C_fix(1));
t1=t9;
t2=t10;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3675 in foldl824 in k3374 in k3365 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3677,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3554(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* map-loop784 in k3359 in k3292 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3685(C_word t0,C_word t1,C_word t2){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_3685,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_cadr(t3);
t5=C_i_caddr(t3);
t6=C_i_cadddr(t3);
t7=C_i_cddddr(t3);
t8=C_i_car(t7);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3319,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t8,a[7]=t6,a[8]=t5,a[9]=t4,tmp=(C_word)a,a+=10,tmp);
/* chicken-profile.scm:237: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[58]);
C_word av2[3];
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t9;
av2[2]=C_i_car(t3);
tp(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3731 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3733(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3733,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3737,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:231: take */
f_1386(t2,((C_word*)((C_word*)t0)[2])[1],C_retrieve2(lf[7],C_text("main#top")));}
else{
t2=((C_word*)t0)[3];
f_3294(t2,C_SCHEME_UNDEFINED);}}

/* k3735 in k3731 in k3289 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3737,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_3294(t3,t2);}

/* g752 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3746(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3746,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_cadr(t2);
t4=C_i_caddr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3764,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t4,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
if(C_truep(C_i_greaterp(t3,C_fix(0)))){
/* ##sys#/-2 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[56]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[56]+1);
av2[1]=t5;
av2[2]=t4;
av2[3]=t3;
tp(4,av2);}}
else{
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_3764(2,av2);}}}
else{
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_3764(2,av2);}}}

/* k3762 in g752 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3764(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3764,c,av);}
a=C_alloc(8);
t2=(C_truep(t1)?t1:C_fix(0));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3771,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_greaterp(((C_word*)t0)[4],C_fix(0)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3784,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#/-2 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[56]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[56]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}
else{
t4=t3;
f_3771(t4,C_SCHEME_FALSE);}}

/* k3769 in k3762 in g752 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3771(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3771,2,t0,t1);}
a=C_alloc(6);
t2=(C_truep(t1)?C_a_i_list2(&a,2,((C_word*)t0)[2],t1):C_a_i_list2(&a,2,((C_word*)t0)[2],C_fix(0)));
/* chicken-profile.scm:219: scheme#append */
t3=*((C_word*)lf[60]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3782 in k3762 in g752 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3784(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,1)))){
C_save_and_reclaim((void *)f_3784,c,av);}
a=C_alloc(33);
t2=((C_word*)t0)[2];
f_3771(t2,C_s_a_i_times(&a,2,t1,C_fix(100)));}

/* k3798 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3800,c,av);}
/* chicken-profile.scm:217: chicken.sort#sort */
t2=C_fast_retrieve(lf[61]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[22],C_text("main#sort-by"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop746 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3802(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3802,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3827,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-profile.scm:217: g752 */
t4=((C_word*)t0)[4];
f_3746(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3825 in map-loop746 in k3286 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3827,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3802(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* foldl728 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall f_3836(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_3836,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=C_eqp(((C_word*)t0)[2],lf[24]);
t6=(C_truep(t5)?(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3865,tmp=(C_word)a,a+=2,tmp):(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3874,tmp=(C_word)a,a+=2,tmp));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3857,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* chicken-profile.scm:213: g735 */
t8=t6;{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t3;
av2[3]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3855 in foldl728 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3857,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3836(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* f_3865 in foldl728 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3865,c,av);}
/* chicken-profile.scm:214: scheme#max */
t4=*((C_word*)lf[54]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_i_caddr(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* f_3874 in foldl728 in k3276 in k3273 in k2618 in loop in k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_3874,c,av);}
a=C_alloc(29);
t4=C_i_caddr(t3);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_s_a_i_plus(&a,2,t2,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k3883 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3885,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3891,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base#implicit-exit-handler */
t3=C_fast_retrieve(lf[44]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3889 in k3883 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3891,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3893 in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_ccall f_3895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3895,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2610,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_2610(t5,((C_word*)t0)[2],t1);}

/* a3896 in k1259 in k1256 */
static void C_ccall f_3897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3897,c,av);}
/* chicken-profile.scm:29: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[91]);
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[91]+1);
av2[1]=t1;
av2[2]=lf[92];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=C_SCHEME_END_OF_LIST;
av2[6]=C_SCHEME_END_OF_LIST;
av2[7]=C_SCHEME_END_OF_LIST;
av2[8]=C_SCHEME_END_OF_LIST;
tp(9,av2);}}

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
if(C_unlikely(!C_demand_2(307))){
C_save(t1);
C_rereclaim2(307*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,94);
lf[0]=C_h_intern(&lf[0],5, C_text("main#"));
lf[9]=C_h_intern(&lf[9],17, C_text("chicken.base#exit"));
lf[10]=C_h_intern(&lf[10],14, C_text("scheme#display"));
lf[11]=C_decode_literal(C_heaptop,C_text("\376B\000\001\242)\012 -no-unused                remove procedures that are never called\012 -top "
"N                    display only the top N entries\012 -help                     s"
"how this text and exit\012 -version                  show version and exit\012 -releas"
"e                  show release number and exit\012\012 FILENAME defaults to the `PROF"
"ILE.<number>\047, selecting the one with\012 the highest modification time, in case mu"
"ltiple profiles exist.\012"));
lf[12]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[13]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[14]=C_decode_literal(C_heaptop,C_text("\376B\000\001\321Usage: chicken-profile [OPTION ...] [FILENAME ...]\012\012 -sort-by-calls        "
"    sort output by call frequency\012 -sort-by-time             sort output by proc"
"edure execution time\012 -sort-by-avg              sort output by average procedure"
" execution time\012 -sort-by-name             sort output alphabetically by procedu"
"re name\012 -decimals DDD             set number of decimals for seconds, average a"
"nd\012                           percent columns (three digits, default: "));
lf[15]=C_h_intern(&lf[15],21, C_text("##sys#print-to-string"));
lf[20]=C_h_intern(&lf[20],15, C_text("scheme#string<\077"));
lf[21]=C_h_intern(&lf[21],21, C_text("scheme#symbol->string"));
lf[24]=C_h_intern(&lf[24],12, C_text("instrumented"));
lf[25]=C_h_intern(&lf[25],36, C_text("chicken.internal#hash-table-for-each"));
lf[26]=C_h_intern(&lf[26],11, C_text("scheme#read"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\001\000\000\000\000\376\003\000\000\002\376\377\001\000\000\000\000\376\377\016"));
lf[28]=C_h_intern(&lf[28],3, C_text("map"));
lf[29]=C_h_intern(&lf[29],32, C_text("chicken.internal#hash-table-set!"));
lf[30]=C_h_intern(&lf[30],31, C_text("chicken.internal#hash-table-ref"));
lf[31]=C_h_intern(&lf[31],18, C_text("scheme#make-vector"));
lf[33]=C_h_intern(&lf[33],19, C_text("##sys#string-append"));
lf[34]=C_h_intern(&lf[34],18, C_text("scheme#make-string"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[37]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[38]=C_h_intern(&lf[38],20, C_text("scheme#string-append"));
lf[39]=C_h_intern(&lf[39],16, C_text("scheme#substring"));
lf[40]=C_h_intern(&lf[40],20, C_text("##sys#number->string"));
lf[41]=C_h_intern(&lf[41],21, C_text("scheme#inexact->exact"));
lf[42]=C_h_intern(&lf[42],15, C_text("scheme#truncate"));
lf[43]=C_h_intern(&lf[43],11, C_text("scheme#expt"));
lf[44]=C_h_intern(&lf[44],34, C_text("chicken.base#implicit-exit-handler"));
lf[45]=C_h_intern(&lf[45],5, C_text("foldl"));
lf[46]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011procedure"));
lf[47]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005calls"));
lf[48]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007seconds"));
lf[49]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007average"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007percent"));
lf[51]=C_h_intern(&lf[51],18, C_text("chicken.base#print"));
lf[52]=C_h_intern(&lf[52],33, C_text("chicken.string#string-intersperse"));
lf[53]=C_h_intern(&lf[53],8, C_text("for-each"));
lf[54]=C_h_intern(&lf[54],10, C_text("scheme#max"));
lf[55]=C_h_intern(&lf[55],17, C_text("##sys#make-string"));
lf[56]=C_h_intern(&lf[56],9, C_text("##sys#/-2"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010overflow"));
lf[58]=C_h_intern(&lf[58],20, C_text("##sys#symbol->string"));
lf[59]=C_h_intern(&lf[59],5, C_text("foldr"));
lf[60]=C_h_intern(&lf[60],13, C_text("scheme#append"));
lf[61]=C_h_intern(&lf[61],17, C_text("chicken.sort#sort"));
lf[62]=C_h_intern(&lf[62],27, C_text("scheme#with-input-from-file"));
lf[63]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011reading `"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006\047 ...\012"));
lf[65]=C_h_intern(&lf[65],18, C_text("chicken.base#error"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021no PROFILEs found"));
lf[67]=C_h_intern(&lf[67],41, C_text("chicken.file.posix#file-modification-time"));
lf[68]=C_h_intern(&lf[68],17, C_text("chicken.file#glob"));
lf[69]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011PROFILE.\052"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032missing argument to option"));
lf[71]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032invalid argument to option"));
lf[72]=C_h_intern(&lf[72],21, C_text("scheme#string->number"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-h"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-help"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006--help"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-version"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032chicken-profile - Version "));
lf[78]=C_h_intern(&lf[78],32, C_text("chicken.platform#chicken-version"));
lf[79]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-release"));
lf[80]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012-no-unused"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004-top"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016-sort-by-calls"));
lf[83]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-sort-by-time"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-sort-by-avg"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-sort-by-name"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011-decimals"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\000$invalid argument to -decimals option"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376B\000\000$invalid argument to -decimals option"));
lf[89]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016invalid option"));
lf[90]=C_h_intern(&lf[90],46, C_text("chicken.process-context#command-line-arguments"));
lf[91]=C_h_intern(&lf[91],30, C_text("##sys#register-compiled-module"));
lf[92]=C_h_intern(&lf[92],4, C_text("main"));
lf[93]=C_h_intern(&lf[93],22, C_text("##sys#with-environment"));
C_register_lf2(lf,94,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1258,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

/* va4346 in k3223 in k3216 in main#format-real in k1274 in k1271 in k1268 in k1265 in k1262 in k1259 in k1256 */
static void C_fcall va4346(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,3)))){
C_save_and_reclaim_args((void *)trva4346,2,t0,t1);}
a=C_alloc(33);
t2=C_s_a_i_minus(&a,2,t1,C_fix(-1));
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3261,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-profile.scm:201: scheme#expt */
t4=*((C_word*)lf[43]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_fix(10);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[125] = {
{C_text("f_1258:chicken_2dprofile_2escm"),(void*)f_1258},
{C_text("f_1261:chicken_2dprofile_2escm"),(void*)f_1261},
{C_text("f_1264:chicken_2dprofile_2escm"),(void*)f_1264},
{C_text("f_1267:chicken_2dprofile_2escm"),(void*)f_1267},
{C_text("f_1270:chicken_2dprofile_2escm"),(void*)f_1270},
{C_text("f_1273:chicken_2dprofile_2escm"),(void*)f_1273},
{C_text("f_1276:chicken_2dprofile_2escm"),(void*)f_1276},
{C_text("f_1386:chicken_2dprofile_2escm"),(void*)f_1386},
{C_text("f_1404:chicken_2dprofile_2escm"),(void*)f_1404},
{C_text("f_1896:chicken_2dprofile_2escm"),(void*)f_1896},
{C_text("f_1925:chicken_2dprofile_2escm"),(void*)f_1925},
{C_text("f_2563:chicken_2dprofile_2escm"),(void*)f_2563},
{C_text("f_2567:chicken_2dprofile_2escm"),(void*)f_2567},
{C_text("f_2574:chicken_2dprofile_2escm"),(void*)f_2574},
{C_text("f_2610:chicken_2dprofile_2escm"),(void*)f_2610},
{C_text("f_2620:chicken_2dprofile_2escm"),(void*)f_2620},
{C_text("f_2627:chicken_2dprofile_2escm"),(void*)f_2627},
{C_text("f_2630:chicken_2dprofile_2escm"),(void*)f_2630},
{C_text("f_2643:chicken_2dprofile_2escm"),(void*)f_2643},
{C_text("f_2645:chicken_2dprofile_2escm"),(void*)f_2645},
{C_text("f_2650:chicken_2dprofile_2escm"),(void*)f_2650},
{C_text("f_2654:chicken_2dprofile_2escm"),(void*)f_2654},
{C_text("f_2660:chicken_2dprofile_2escm"),(void*)f_2660},
{C_text("f_2679:chicken_2dprofile_2escm"),(void*)f_2679},
{C_text("f_2683:chicken_2dprofile_2escm"),(void*)f_2683},
{C_text("f_2699:chicken_2dprofile_2escm"),(void*)f_2699},
{C_text("f_2702:chicken_2dprofile_2escm"),(void*)f_2702},
{C_text("f_2720:chicken_2dprofile_2escm"),(void*)f_2720},
{C_text("f_2727:chicken_2dprofile_2escm"),(void*)f_2727},
{C_text("f_2735:chicken_2dprofile_2escm"),(void*)f_2735},
{C_text("f_2742:chicken_2dprofile_2escm"),(void*)f_2742},
{C_text("f_2757:chicken_2dprofile_2escm"),(void*)f_2757},
{C_text("f_2793:chicken_2dprofile_2escm"),(void*)f_2793},
{C_text("f_2824:chicken_2dprofile_2escm"),(void*)f_2824},
{C_text("f_2858:chicken_2dprofile_2escm"),(void*)f_2858},
{C_text("f_2887:chicken_2dprofile_2escm"),(void*)f_2887},
{C_text("f_2915:chicken_2dprofile_2escm"),(void*)f_2915},
{C_text("f_2923:chicken_2dprofile_2escm"),(void*)f_2923},
{C_text("f_2927:chicken_2dprofile_2escm"),(void*)f_2927},
{C_text("f_2941:chicken_2dprofile_2escm"),(void*)f_2941},
{C_text("f_2953:chicken_2dprofile_2escm"),(void*)f_2953},
{C_text("f_2975:chicken_2dprofile_2escm"),(void*)f_2975},
{C_text("f_2979:chicken_2dprofile_2escm"),(void*)f_2979},
{C_text("f_2983:chicken_2dprofile_2escm"),(void*)f_2983},
{C_text("f_2999:chicken_2dprofile_2escm"),(void*)f_2999},
{C_text("f_3003:chicken_2dprofile_2escm"),(void*)f_3003},
{C_text("f_3006:chicken_2dprofile_2escm"),(void*)f_3006},
{C_text("f_3012:chicken_2dprofile_2escm"),(void*)f_3012},
{C_text("f_3015:chicken_2dprofile_2escm"),(void*)f_3015},
{C_text("f_3020:chicken_2dprofile_2escm"),(void*)f_3020},
{C_text("f_3029:chicken_2dprofile_2escm"),(void*)f_3029},
{C_text("f_3031:chicken_2dprofile_2escm"),(void*)f_3031},
{C_text("f_3041:chicken_2dprofile_2escm"),(void*)f_3041},
{C_text("f_3048:chicken_2dprofile_2escm"),(void*)f_3048},
{C_text("f_3070:chicken_2dprofile_2escm"),(void*)f_3070},
{C_text("f_3085:chicken_2dprofile_2escm"),(void*)f_3085},
{C_text("f_3087:chicken_2dprofile_2escm"),(void*)f_3087},
{C_text("f_3097:chicken_2dprofile_2escm"),(void*)f_3097},
{C_text("f_3148:chicken_2dprofile_2escm"),(void*)f_3148},
{C_text("f_3167:chicken_2dprofile_2escm"),(void*)f_3167},
{C_text("f_3214:chicken_2dprofile_2escm"),(void*)f_3214},
{C_text("f_3218:chicken_2dprofile_2escm"),(void*)f_3218},
{C_text("f_3225:chicken_2dprofile_2escm"),(void*)f_3225},
{C_text("f_3233:chicken_2dprofile_2escm"),(void*)f_3233},
{C_text("f_3237:chicken_2dprofile_2escm"),(void*)f_3237},
{C_text("f_3245:chicken_2dprofile_2escm"),(void*)f_3245},
{C_text("f_3249:chicken_2dprofile_2escm"),(void*)f_3249},
{C_text("f_3261:chicken_2dprofile_2escm"),(void*)f_3261},
{C_text("f_3269:chicken_2dprofile_2escm"),(void*)f_3269},
{C_text("f_3275:chicken_2dprofile_2escm"),(void*)f_3275},
{C_text("f_3278:chicken_2dprofile_2escm"),(void*)f_3278},
{C_text("f_3288:chicken_2dprofile_2escm"),(void*)f_3288},
{C_text("f_3291:chicken_2dprofile_2escm"),(void*)f_3291},
{C_text("f_3294:chicken_2dprofile_2escm"),(void*)f_3294},
{C_text("f_3319:chicken_2dprofile_2escm"),(void*)f_3319},
{C_text("f_3323:chicken_2dprofile_2escm"),(void*)f_3323},
{C_text("f_3327:chicken_2dprofile_2escm"),(void*)f_3327},
{C_text("f_3331:chicken_2dprofile_2escm"),(void*)f_3331},
{C_text("f_3335:chicken_2dprofile_2escm"),(void*)f_3335},
{C_text("f_3339:chicken_2dprofile_2escm"),(void*)f_3339},
{C_text("f_3345:chicken_2dprofile_2escm"),(void*)f_3345},
{C_text("f_3361:chicken_2dprofile_2escm"),(void*)f_3361},
{C_text("f_3367:chicken_2dprofile_2escm"),(void*)f_3367},
{C_text("f_3376:chicken_2dprofile_2escm"),(void*)f_3376},
{C_text("f_3385:chicken_2dprofile_2escm"),(void*)f_3385},
{C_text("f_3387:chicken_2dprofile_2escm"),(void*)f_3387},
{C_text("f_3395:chicken_2dprofile_2escm"),(void*)f_3395},
{C_text("f_3408:chicken_2dprofile_2escm"),(void*)f_3408},
{C_text("f_3410:chicken_2dprofile_2escm"),(void*)f_3410},
{C_text("f_3417:chicken_2dprofile_2escm"),(void*)f_3417},
{C_text("f_3443:chicken_2dprofile_2escm"),(void*)f_3443},
{C_text("f_3473:chicken_2dprofile_2escm"),(void*)f_3473},
{C_text("f_3476:chicken_2dprofile_2escm"),(void*)f_3476},
{C_text("f_3484:chicken_2dprofile_2escm"),(void*)f_3484},
{C_text("f_3494:chicken_2dprofile_2escm"),(void*)f_3494},
{C_text("f_3509:chicken_2dprofile_2escm"),(void*)f_3509},
{C_text("f_3520:chicken_2dprofile_2escm"),(void*)f_3520},
{C_text("f_3530:chicken_2dprofile_2escm"),(void*)f_3530},
{C_text("f_3554:chicken_2dprofile_2escm"),(void*)f_3554},
{C_text("f_3583:chicken_2dprofile_2escm"),(void*)f_3583},
{C_text("f_3594:chicken_2dprofile_2escm"),(void*)f_3594},
{C_text("f_3623:chicken_2dprofile_2escm"),(void*)f_3623},
{C_text("f_3642:chicken_2dprofile_2escm"),(void*)f_3642},
{C_text("f_3677:chicken_2dprofile_2escm"),(void*)f_3677},
{C_text("f_3685:chicken_2dprofile_2escm"),(void*)f_3685},
{C_text("f_3733:chicken_2dprofile_2escm"),(void*)f_3733},
{C_text("f_3737:chicken_2dprofile_2escm"),(void*)f_3737},
{C_text("f_3746:chicken_2dprofile_2escm"),(void*)f_3746},
{C_text("f_3764:chicken_2dprofile_2escm"),(void*)f_3764},
{C_text("f_3771:chicken_2dprofile_2escm"),(void*)f_3771},
{C_text("f_3784:chicken_2dprofile_2escm"),(void*)f_3784},
{C_text("f_3800:chicken_2dprofile_2escm"),(void*)f_3800},
{C_text("f_3802:chicken_2dprofile_2escm"),(void*)f_3802},
{C_text("f_3827:chicken_2dprofile_2escm"),(void*)f_3827},
{C_text("f_3836:chicken_2dprofile_2escm"),(void*)f_3836},
{C_text("f_3857:chicken_2dprofile_2escm"),(void*)f_3857},
{C_text("f_3865:chicken_2dprofile_2escm"),(void*)f_3865},
{C_text("f_3874:chicken_2dprofile_2escm"),(void*)f_3874},
{C_text("f_3885:chicken_2dprofile_2escm"),(void*)f_3885},
{C_text("f_3891:chicken_2dprofile_2escm"),(void*)f_3891},
{C_text("f_3895:chicken_2dprofile_2escm"),(void*)f_3895},
{C_text("f_3897:chicken_2dprofile_2escm"),(void*)f_3897},
{C_text("toplevel:chicken_2dprofile_2escm"),(void*)C_toplevel},
{C_text("va4346:chicken_2dprofile_2escm"),(void*)va4346},
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
o|hiding unexported module binding: main#partition 
o|hiding unexported module binding: main#span 
o|hiding unexported module binding: main#take 
o|hiding unexported module binding: main#drop 
o|hiding unexported module binding: main#split-at 
o|hiding unexported module binding: main#append-map 
o|hiding unexported module binding: main#every 
o|hiding unexported module binding: main#any 
o|hiding unexported module binding: main#cons* 
o|hiding unexported module binding: main#concatenate 
o|hiding unexported module binding: main#delete 
o|hiding unexported module binding: main#first 
o|hiding unexported module binding: main#second 
o|hiding unexported module binding: main#third 
o|hiding unexported module binding: main#fourth 
o|hiding unexported module binding: main#fifth 
o|hiding unexported module binding: main#delete-duplicates 
o|hiding unexported module binding: main#alist-cons 
o|hiding unexported module binding: main#filter 
o|hiding unexported module binding: main#filter-map 
o|hiding unexported module binding: main#remove 
o|hiding unexported module binding: main#unzip1 
o|hiding unexported module binding: main#last 
o|hiding unexported module binding: main#list-index 
o|hiding unexported module binding: main#lset-adjoin/eq? 
o|hiding unexported module binding: main#lset-difference/eq? 
o|hiding unexported module binding: main#lset-union/eq? 
o|hiding unexported module binding: main#lset-intersection/eq? 
o|hiding unexported module binding: main#list-tabulate 
o|hiding unexported module binding: main#lset<=/eq? 
o|hiding unexported module binding: main#lset=/eq? 
o|hiding unexported module binding: main#length+ 
o|hiding unexported module binding: main#find 
o|hiding unexported module binding: main#find-tail 
o|hiding unexported module binding: main#iota 
o|hiding unexported module binding: main#make-list 
o|hiding unexported module binding: main#posq 
o|hiding unexported module binding: main#posv 
o|hiding unexported module binding: main#symbol-table-size 
o|hiding unexported module binding: main#sort-by 
o|hiding unexported module binding: main#file 
o|hiding unexported module binding: main#no-unused 
o|hiding unexported module binding: main#seconds-digits 
o|hiding unexported module binding: main#average-digits 
o|hiding unexported module binding: main#percent-digits 
o|hiding unexported module binding: main#top 
o|hiding unexported module binding: main#print-usage 
o|hiding unexported module binding: main#run 
o|hiding unexported module binding: main#sort-by-calls 
o|hiding unexported module binding: main#sort-by-time 
o|hiding unexported module binding: main#sort-by-avg 
o|hiding unexported module binding: main#sort-by-name 
o|hiding unexported module binding: main#set-decimals 
o|hiding unexported module binding: main#make-symbol-table 
o|hiding unexported module binding: main#read-profile 
o|hiding unexported module binding: main#format-string 
o|hiding unexported module binding: main#format-real 
o|hiding unexported module binding: main#write-profile 
S|applied compiler syntax:
S|  scheme#for-each		1
S|  chicken.base#foldl		6
S|  scheme#map		9
S|  chicken.base#foldr		3
o|eliminated procedure checks: 64 
o|folded constant expression: (scheme#char->integer (quote #\0)) 
o|specializations:
o|  1 (scheme#* integer integer)
o|  1 (scheme#make-string fixnum char)
o|  4 (scheme#/ * *)
o|  3 (scheme#number->string *)
o|  2 (scheme#string-append string string)
o|  1 (scheme#= fixnum fixnum)
o|  1 (scheme#= integer integer)
o|  2 (scheme#- fixnum fixnum)
o|  1 (scheme#char=? char char)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#> fixnum fixnum)
o|  1 (scheme#string-length string)
o|  8 (scheme#string=? string string)
o|  1 (scheme#> integer integer)
o|  3 (scheme#eqv? * *)
o|  6 (##sys#check-list (or pair list) *)
o|  24 (scheme#cdr pair)
o|  7 (scheme#car pair)
(o e)|safe calls: 419 
(o e)|assignments to immediate values: 5 
o|dropping redundant toplevel assignment: main#sort-by 
o|removed side-effect free assignment to unused variable: main#partition 
o|removed side-effect free assignment to unused variable: main#span 
o|inlining procedure: k1388 
o|inlining procedure: k1388 
o|removed side-effect free assignment to unused variable: main#drop 
o|removed side-effect free assignment to unused variable: main#split-at 
o|removed side-effect free assignment to unused variable: main#append-map 
o|inlining procedure: k1658 
o|inlining procedure: k1658 
o|inlining procedure: k1689 
o|inlining procedure: k1689 
o|removed side-effect free assignment to unused variable: main#cons* 
o|removed side-effect free assignment to unused variable: main#concatenate 
o|removed side-effect free assignment to unused variable: main#delete-duplicates 
o|inlining procedure: k1906 
o|inlining procedure: k1906 
o|inlining procedure: k1898 
o|inlining procedure: k1898 
o|removed side-effect free assignment to unused variable: main#filter-map 
o|removed side-effect free assignment to unused variable: main#remove 
o|removed side-effect free assignment to unused variable: main#unzip1 
o|removed side-effect free assignment to unused variable: main#last 
o|removed side-effect free assignment to unused variable: main#list-index 
o|removed side-effect free assignment to unused variable: main#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: main#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: main#lset-union/eq? 
o|removed side-effect free assignment to unused variable: main#lset-intersection/eq? 
o|inlining procedure: k2297 
o|inlining procedure: k2297 
o|removed side-effect free assignment to unused variable: main#lset<=/eq? 
o|removed side-effect free assignment to unused variable: main#lset=/eq? 
o|removed side-effect free assignment to unused variable: main#length+ 
o|removed side-effect free assignment to unused variable: main#find 
o|removed side-effect free assignment to unused variable: main#find-tail 
o|removed side-effect free assignment to unused variable: main#iota 
o|removed side-effect free assignment to unused variable: main#make-list 
o|removed side-effect free assignment to unused variable: main#posq 
o|removed side-effect free assignment to unused variable: main#posv 
o|inlining procedure: k2832 
o|inlining procedure: "(chicken-profile.scm:128) main#third" 
o|inlining procedure: "(chicken-profile.scm:128) main#third" 
o|inlining procedure: k2832 
o|inlining procedure: k2851 
o|inlining procedure: k2851 
o|inlining procedure: "(chicken-profile.scm:126) main#second" 
o|inlining procedure: "(chicken-profile.scm:125) main#second" 
o|inlining procedure: k2866 
o|inlining procedure: "(chicken-profile.scm:135) main#second" 
o|inlining procedure: "(chicken-profile.scm:135) main#second" 
o|inlining procedure: k2866 
o|inlining procedure: "(chicken-profile.scm:133) main#third" 
o|inlining procedure: "(chicken-profile.scm:132) main#third" 
o|inlining procedure: k2895 
o|inlining procedure: "(chicken-profile.scm:142) main#third" 
o|inlining procedure: "(chicken-profile.scm:142) main#third" 
o|inlining procedure: k2895 
o|inlining procedure: "(chicken-profile.scm:146) main#first" 
o|inlining procedure: "(chicken-profile.scm:146) main#first" 
o|contracted procedure: "(chicken-profile.scm:181) main#alist-cons" 
o|inlining procedure: k3033 
o|inlining procedure: k3033 
o|inlining procedure: k3089 
o|contracted procedure: "(chicken-profile.scm:175) g657667" 
o|inlining procedure: k3059 
o|inlining procedure: k3059 
o|inlining procedure: k3089 
o|inlining procedure: "(chicken-profile.scm:176) main#first" 
o|inlining procedure: "(chicken-profile.scm:174) main#first" 
o|contracted procedure: "(chicken-profile.scm:168) main#make-symbol-table" 
o|substituted constant variable: main#symbol-table-size 
o|inlining procedure: k3168 
o|inlining procedure: k3168 
o|contracted procedure: "(chicken-profile.scm:262) main#run" 
o|inlining procedure: k2612 
o|contracted procedure: "(chicken-profile.scm:91) main#write-profile" 
o|inlining procedure: k3412 
o|inlining procedure: k3412 
o|inlining procedure: k3462 
o|inlining procedure: k3462 
o|inlining procedure: k3486 
o|inlining procedure: k3486 
o|substituted constant variable: spacing816 
o|substituted constant variable: a3528 
o|substituted constant variable: spacing816 
o|inlining procedure: k3532 
o|inlining procedure: k3532 
o|substituted constant variable: g946949 
o|inlining procedure: k3556 
o|contracted procedure: "(chicken-profile.scm:249) g831832" 
o|inlining procedure: k3596 
o|inlining procedure: k3596 
o|inlining procedure: k3644 
o|inlining procedure: k3644 
o|inlining procedure: k3556 
o|substituted constant variable: spacing816 
o|substituted constant variable: spacing816 
o|substituted constant variable: a3683 
o|inlining procedure: k3687 
o|contracted procedure: "(chicken-profile.scm:232) g790799" 
o|substituted constant variable: a3341 
o|substituted constant variable: a3347 
o|inlining procedure: "(chicken-profile.scm:237) main#first" 
o|contracted procedure: "(chicken-profile.scm:236) main#fifth" 
o|contracted procedure: "(chicken-profile.scm:235) main#fourth" 
o|inlining procedure: "(chicken-profile.scm:234) main#third" 
o|inlining procedure: "(chicken-profile.scm:233) main#second" 
o|inlining procedure: k3687 
o|inlining procedure: "(chicken-profile.scm:243) main#second" 
o|inlining procedure: k3772 
o|inlining procedure: k3772 
o|inlining procedure: k3787 
o|inlining procedure: k3787 
o|inlining procedure: "(chicken-profile.scm:222) main#third" 
o|inlining procedure: "(chicken-profile.scm:221) main#second" 
o|inlining procedure: k3804 
o|inlining procedure: k3804 
o|inlining procedure: k3838 
o|inlining procedure: "(chicken-profile.scm:214) main#third" 
o|inlining procedure: "(chicken-profile.scm:215) main#third" 
o|inlining procedure: k3838 
o|substituted constant variable: g727730 
o|inlining procedure: k2628 
o|inlining procedure: k2628 
o|inlining procedure: "(chicken-profile.scm:87) main#first" 
o|inlining procedure: k2662 
o|inlining procedure: k2662 
o|inlining procedure: k2684 
o|inlining procedure: k2684 
o|inlining procedure: k2612 
o|inlining procedure: k2712 
o|inlining procedure: k2712 
o|substituted constant variable: a2732 
o|substituted constant variable: a2747 
o|inlining procedure: k2743 
o|inlining procedure: k2743 
o|substituted constant variable: a2753 
o|substituted constant variable: a2762 
o|inlining procedure: k2758 
o|inlining procedure: k2758 
o|substituted constant variable: a2768 
o|substituted constant variable: a2774 
o|inlining procedure: k2770 
o|inlining procedure: k2770 
o|substituted constant variable: a2780 
o|substituted constant variable: a2786 
o|inlining procedure: k2782 
o|contracted procedure: "(chicken-profile.scm:117) main#set-decimals" 
o|substituted constant variable: a2947 
o|inlining procedure: k2948 
o|substituted constant variable: a2958 
o|inlining procedure: k2948 
o|inlining procedure: k2966 
o|inlining procedure: k2966 
o|substituted constant variable: a2991 
o|inlining procedure: k2782 
o|inlining procedure: k2803 
o|inlining procedure: k2803 
o|substituted constant variable: a2816 
o|substituted constant variable: a2813 
o|substituted constant variable: a2821 
o|replaced variables: 409 
o|removed binding forms: 144 
o|substituted constant variable: r13893918 
o|removed side-effect free assignment to unused variable: main#every 
o|removed side-effect free assignment to unused variable: main#any 
o|removed side-effect free assignment to unused variable: main#first 
o|removed side-effect free assignment to unused variable: main#second 
o|removed side-effect free assignment to unused variable: main#third 
o|removed side-effect free assignment to unused variable: main#list-tabulate 
o|removed side-effect free assignment to unused variable: main#symbol-table-size 
o|substituted constant variable: r28523943 
o|substituted constant variable: r30604002 
o|substituted constant variable: r34634020 
o|converted assignments to bindings: (print-row894) 
o|contracted procedure: "(chicken-profile.scm:243) main#filter" 
o|substituted constant variable: r18993927 
o|substituted constant variable: r37734055 
o|substituted constant variable: r37734055 
o|substituted constant variable: r37884058 
o|inlining procedure: k2700 
o|inlining procedure: k2700 
o|inlining procedure: k2700 
o|converted assignments to bindings: (arg-digit635) 
o|inlining procedure: k2700 
o|simplifications: ((let . 2)) 
o|replaced variables: 117 
o|removed binding forms: 385 
o|inlining procedure: k3114 
o|inlining procedure: k3114 
o|inlining procedure: k2700 
o|replaced variables: 2 
o|removed binding forms: 127 
o|substituted constant variable: r31154171 
o|substituted constant variable: r31154172 
o|inlining procedure: "(mini-srfi-1.scm:131) a3721" 
o|inlining procedure: k2687 
o|removed binding forms: 3 
o|contracted procedure: "(mini-srfi-1.scm:131) g295296" 
o|substituted constant variable: r26884233 
o|replaced variables: 2 
o|removed binding forms: 4 
o|removed conditional forms: 1 
o|replaced variables: 6 
o|removed binding forms: 3 
o|removed binding forms: 3 
o|simplifications: ((let . 1) (if . 18) (##core#call . 194)) 
o|  call simplifications:
o|    scheme#member
o|    scheme#string=?
o|    ##sys#size
o|    chicken.fixnum#fx>
o|    scheme#string-ref
o|    scheme#char->integer
o|    scheme#<=
o|    scheme#eq?	2
o|    scheme#<
o|    scheme#cddddr
o|    scheme#not
o|    scheme#list	10
o|    scheme#length	2
o|    scheme#-
o|    scheme#*	2
o|    scheme#null?	7
o|    scheme#string-length	3
o|    chicken.fixnum#fxmax
o|    scheme#symbol?	2
o|    scheme#eof-object?
o|    scheme#cdr	4
o|    ##sys#check-list	12
o|    scheme#pair?	15
o|    scheme#+	5
o|    ##sys#setslot	6
o|    ##sys#slot	36
o|    scheme#cadddr	3
o|    scheme#=
o|    scheme#cadr	7
o|    scheme#caddr	10
o|    scheme#>	11
o|    chicken.fixnum#fx<=
o|    scheme#car	13
o|    chicken.fixnum#fx-	2
o|    scheme#cons	27
o|contracted procedure: k1391 
o|contracted procedure: k1398 
o|contracted procedure: k1408 
o|contracted procedure: k2600 
o|contracted procedure: k2596 
o|contracted procedure: k2592 
o|contracted procedure: k2588 
o|contracted procedure: k2584 
o|contracted procedure: k2580 
o|contracted procedure: k2576 
o|contracted procedure: k2826 
o|contracted procedure: k2829 
o|contracted procedure: k2841 
o|contracted procedure: k2845 
o|contracted procedure: k2860 
o|contracted procedure: k2863 
o|contracted procedure: k2869 
o|contracted procedure: k2876 
o|contracted procedure: k2880 
o|contracted procedure: k2889 
o|contracted procedure: k2892 
o|contracted procedure: k2904 
o|contracted procedure: k2908 
o|contracted procedure: k2929 
o|contracted procedure: k2933 
o|contracted procedure: k3144 
o|contracted procedure: k3007 
o|contracted procedure: k1883 
o|contracted procedure: k3023 
o|contracted procedure: k3036 
o|contracted procedure: k3050 
o|contracted procedure: k3054 
o|contracted procedure: k3071 
o|contracted procedure: k3074 
o|contracted procedure: k3077 
o|contracted procedure: k3080 
o|contracted procedure: k3128 
o|contracted procedure: k3092 
o|contracted procedure: k3098 
o|contracted procedure: k3106 
o|contracted procedure: k3110 
o|contracted procedure: k3118 
o|contracted procedure: k3122 
o|contracted procedure: k3114 
o|contracted procedure: k3135 
o|contracted procedure: k3138 
o|contracted procedure: k3207 
o|contracted procedure: k3150 
o|contracted procedure: k3201 
o|contracted procedure: k3153 
o|contracted procedure: k3195 
o|contracted procedure: k3156 
o|contracted procedure: k3189 
o|contracted procedure: k3159 
o|contracted procedure: k3162 
o|contracted procedure: k3186 
o|contracted procedure: k3182 
o|contracted procedure: k3262 
o|contracted procedure: k3227 
o|contracted procedure: k3239 
o|contracted procedure: k3251 
o|contracted procedure: k2615 
o|contracted procedure: k3279 
o|contracted procedure: k3283 
o|contracted procedure: k3296 
o|contracted procedure: k3362 
o|contracted procedure: k3368 
o|contracted procedure: k3371 
o|contracted procedure: k3377 
o|contracted procedure: k3380 
o|contracted procedure: k3397 
o|contracted procedure: k3400 
o|contracted procedure: k3403 
o|contracted procedure: k3418 
o|contracted procedure: k3421 
o|contracted procedure: k3429 
o|contracted procedure: k3433 
o|contracted procedure: k3437 
o|contracted procedure: k3445 
o|contracted procedure: k3449 
o|contracted procedure: k3453 
o|contracted procedure: k3459 
o|contracted procedure: k3465 
o|contracted procedure: k3477 
o|contracted procedure: k3489 
o|contracted procedure: k3499 
o|contracted procedure: k3503 
o|contracted procedure: k3515 
o|contracted procedure: k3525 
o|contracted procedure: k3511 
o|contracted procedure: k3535 
o|contracted procedure: k3542 
o|contracted procedure: k3550 
o|contracted procedure: k3546 
o|contracted procedure: k3559 
o|contracted procedure: k3566 
o|contracted procedure: k3679 
o|contracted procedure: k3572 
o|contracted procedure: k3575 
o|contracted procedure: k3578 
o|contracted procedure: k3584 
o|contracted procedure: k3587 
o|contracted procedure: k3635 
o|contracted procedure: k3599 
o|contracted procedure: k3602 
o|contracted procedure: k3605 
o|contracted procedure: k3613 
o|contracted procedure: k3617 
o|contracted procedure: k3625 
o|contracted procedure: k3629 
o|contracted procedure: k3647 
o|contracted procedure: k3669 
o|contracted procedure: k3665 
o|contracted procedure: k3650 
o|contracted procedure: k3653 
o|contracted procedure: k3661 
o|contracted procedure: k3690 
o|contracted procedure: k3712 
o|contracted procedure: k3301 
o|contracted procedure: k3304 
o|contracted procedure: k3307 
o|contracted procedure: k1838 
o|contracted procedure: k3310 
o|contracted procedure: k3708 
o|contracted procedure: k3693 
o|contracted procedure: k3696 
o|contracted procedure: k3704 
o|contracted procedure: k3348 
o|contracted procedure: k3356 
o|contracted procedure: k1889 
o|contracted procedure: k1901 
o|contracted procedure: k1919 
o|contracted procedure: k37284226 
o|contracted procedure: k1909 
o|contracted procedure: k1927 
o|contracted procedure: k3739 
o|contracted procedure: k3743 
o|contracted procedure: k3752 
o|contracted procedure: k3755 
o|contracted procedure: k3765 
o|contracted procedure: k3758 
o|contracted procedure: k3775 
o|contracted procedure: k3790 
o|contracted procedure: k3807 
o|contracted procedure: k3810 
o|contracted procedure: k3813 
o|contracted procedure: k3821 
o|contracted procedure: k3829 
o|contracted procedure: k3841 
o|contracted procedure: k3848 
o|contracted procedure: k3862 
o|contracted procedure: k3852 
o|contracted procedure: k3871 
o|contracted procedure: k3880 
o|contracted procedure: k3859 
o|contracted procedure: k2631 
o|inlining procedure: k2628 
o|contracted procedure: k2655 
o|contracted procedure: k2665 
o|contracted procedure: k2671 
o|contracted procedure: k2675 
o|contracted procedure: k2687 
o|contracted procedure: k2706 
o|contracted procedure: k2715 
o|inlining procedure: k2700 
o|inlining procedure: k2700 
o|contracted procedure: k2963 
o|contracted procedure: k2944 
o|contracted procedure: k2988 
o|contracted procedure: k2969 
o|contracted procedure: k2818 
o|contracted procedure: k2810 
o|contracted procedure: k2797 
o|contracted procedure: k3903 
o|contracted procedure: k3907 
o|contracted procedure: k3911 
o|contracted procedure: k3915 
o|simplifications: ((##core#call . 2) (if . 4) (let . 56)) 
o|  call simplifications:
o|    scheme#-	2
o|removed binding forms: 174 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest698701 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest698701 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest698701 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest698701 0 
o|contracted procedure: k3255 
o|substituted constant variable: r3904 
o|substituted constant variable: r3908 
o|substituted constant variable: r3912 
o|substituted constant variable: r3916 
o|replaced variables: 3 
o|removed binding forms: 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3154 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r3154 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3154 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r3154 1 
o|removed binding forms: 5 
o|removed binding forms: 2 
o|customizable procedures: (arg-digit635 next-number603 main#print-usage loop590 next-arg602 k2618 foldl728732 g752761 map-loop746775 k3769 k3292 foldr290293 main#format-real map-loop784807 map-loop858875 map-loop837882 foldl824828 foldl947951 print-row894 for-each-loop897958 k3415 map-loop908929 va4346 k3095 map-loop651677 doloop646647 main#take) 
o|calls to known targets: 69 
o|identified direct recursive calls: f_1386 1 
o|unused rest argument: rest698701 f_3148 
o|identified direct recursive calls: f_3530 1 
o|identified direct recursive calls: f_3642 1 
o|identified direct recursive calls: f_1896 1 
o|identified direct recursive calls: f_2610 5 
o|fast box initializations: 14 
o|fast global references: 29 
o|fast global assignments: 28 
o|dropping unused closure argument: f_1386 
o|dropping unused closure argument: f_2563 
o|dropping unused closure argument: f_3214 
*/
/* end of file */
