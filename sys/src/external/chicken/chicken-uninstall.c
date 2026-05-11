/* Generated from chicken-uninstall.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken-uninstall.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -output-file chicken-uninstall.c
   uses: eval data-structures posix pathname port irregex extras file library
*/
#include "chicken.h"

#ifndef STATICBUILD
# define STATIC_CHICKEN 0
#else
# define STATIC_CHICKEN 1
#endif
#ifndef DEBUGBUILD
# define DEBUG_CHICKEN 0
#else
# define DEBUG_CHICKEN 1
#endif

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_posix_toplevel)
C_externimport void C_ccall C_posix_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_irregex_toplevel)
C_externimport void C_ccall C_irregex_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externimport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[119];
static double C_possibly_force_alignment;


C_noret_decl(f4517)
static void C_ccall f4517(C_word c,C_word *av) C_noret;
C_noret_decl(f4522)
static void C_ccall f4522(C_word c,C_word *av) C_noret;
C_noret_decl(f4529)
static void C_ccall f4529(C_word c,C_word *av) C_noret;
C_noret_decl(f4536)
static void C_ccall f4536(C_word c,C_word *av) C_noret;
C_noret_decl(f_1501)
static void C_ccall f_1501(C_word c,C_word *av) C_noret;
C_noret_decl(f_1504)
static void C_ccall f_1504(C_word c,C_word *av) C_noret;
C_noret_decl(f_1507)
static void C_ccall f_1507(C_word c,C_word *av) C_noret;
C_noret_decl(f_1510)
static void C_ccall f_1510(C_word c,C_word *av) C_noret;
C_noret_decl(f_1513)
static void C_ccall f_1513(C_word c,C_word *av) C_noret;
C_noret_decl(f_1516)
static void C_ccall f_1516(C_word c,C_word *av) C_noret;
C_noret_decl(f_1519)
static void C_ccall f_1519(C_word c,C_word *av) C_noret;
C_noret_decl(f_1522)
static void C_ccall f_1522(C_word c,C_word *av) C_noret;
C_noret_decl(f_1525)
static void C_ccall f_1525(C_word c,C_word *av) C_noret;
C_noret_decl(f_1528)
static void C_ccall f_1528(C_word c,C_word *av) C_noret;
C_noret_decl(f_1905)
static C_word C_fcall f_1905(C_word t0);
C_noret_decl(f_1939)
static C_word C_fcall f_1939(C_word t0,C_word t1);
C_noret_decl(f_1997)
static void C_fcall f_1997(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2015)
static void C_ccall f_2015(C_word c,C_word *av) C_noret;
C_noret_decl(f_2025)
static void C_fcall f_2025(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2052)
static void C_ccall f_2052(C_word c,C_word *av) C_noret;
C_noret_decl(f_2100)
static void C_fcall f_2100(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2114)
static void C_ccall f_2114(C_word c,C_word *av) C_noret;
C_noret_decl(f_2127)
static void C_ccall f_2127(C_word c,C_word *av) C_noret;
C_noret_decl(f_2139)
static void C_fcall f_2139(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2148)
static void C_fcall f_2148(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2156)
static void C_fcall f_2156(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2163)
static void C_ccall f_2163(C_word c,C_word *av) C_noret;
C_noret_decl(f_2177)
static void C_ccall f_2177(C_word c,C_word *av) C_noret;
C_noret_decl(f_2812)
static void C_ccall f_2812(C_word c,C_word *av) C_noret;
C_noret_decl(f_2818)
static void C_ccall f_2818(C_word c,C_word *av) C_noret;
C_noret_decl(f_2822)
static void C_ccall f_2822(C_word c,C_word *av) C_noret;
C_noret_decl(f_2826)
static void C_ccall f_2826(C_word c,C_word *av) C_noret;
C_noret_decl(f_2830)
static void C_ccall f_2830(C_word c,C_word *av) C_noret;
C_noret_decl(f_2834)
static void C_ccall f_2834(C_word c,C_word *av) C_noret;
C_noret_decl(f_2838)
static void C_ccall f_2838(C_word c,C_word *av) C_noret;
C_noret_decl(f_2842)
static void C_ccall f_2842(C_word c,C_word *av) C_noret;
C_noret_decl(f_2846)
static void C_ccall f_2846(C_word c,C_word *av) C_noret;
C_noret_decl(f_2850)
static void C_ccall f_2850(C_word c,C_word *av) C_noret;
C_noret_decl(f_2854)
static void C_ccall f_2854(C_word c,C_word *av) C_noret;
C_noret_decl(f_2858)
static void C_ccall f_2858(C_word c,C_word *av) C_noret;
C_noret_decl(f_2862)
static void C_ccall f_2862(C_word c,C_word *av) C_noret;
C_noret_decl(f_2866)
static void C_ccall f_2866(C_word c,C_word *av) C_noret;
C_noret_decl(f_2870)
static void C_ccall f_2870(C_word c,C_word *av) C_noret;
C_noret_decl(f_2874)
static void C_ccall f_2874(C_word c,C_word *av) C_noret;
C_noret_decl(f_2882)
static void C_ccall f_2882(C_word c,C_word *av) C_noret;
C_noret_decl(f_2886)
static void C_ccall f_2886(C_word c,C_word *av) C_noret;
C_noret_decl(f_2890)
static void C_ccall f_2890(C_word c,C_word *av) C_noret;
C_noret_decl(f_2894)
static void C_ccall f_2894(C_word c,C_word *av) C_noret;
C_noret_decl(f_2898)
static void C_ccall f_2898(C_word c,C_word *av) C_noret;
C_noret_decl(f_2902)
static void C_ccall f_2902(C_word c,C_word *av) C_noret;
C_noret_decl(f_2906)
static void C_ccall f_2906(C_word c,C_word *av) C_noret;
C_noret_decl(f_2910)
static void C_ccall f_2910(C_word c,C_word *av) C_noret;
C_noret_decl(f_2914)
static void C_ccall f_2914(C_word c,C_word *av) C_noret;
C_noret_decl(f_2918)
static void C_ccall f_2918(C_word c,C_word *av) C_noret;
C_noret_decl(f_2922)
static void C_ccall f_2922(C_word c,C_word *av) C_noret;
C_noret_decl(f_2926)
static void C_ccall f_2926(C_word c,C_word *av) C_noret;
C_noret_decl(f_2930)
static void C_ccall f_2930(C_word c,C_word *av) C_noret;
C_noret_decl(f_2934)
static void C_ccall f_2934(C_word c,C_word *av) C_noret;
C_noret_decl(f_2938)
static void C_ccall f_2938(C_word c,C_word *av) C_noret;
C_noret_decl(f_2942)
static void C_ccall f_2942(C_word c,C_word *av) C_noret;
C_noret_decl(f_2946)
static void C_ccall f_2946(C_word c,C_word *av) C_noret;
C_noret_decl(f_2950)
static void C_ccall f_2950(C_word c,C_word *av) C_noret;
C_noret_decl(f_2954)
static void C_ccall f_2954(C_word c,C_word *av) C_noret;
C_noret_decl(f_2958)
static void C_ccall f_2958(C_word c,C_word *av) C_noret;
C_noret_decl(f_2966)
static void C_ccall f_2966(C_word c,C_word *av) C_noret;
C_noret_decl(f_2969)
static void C_ccall f_2969(C_word c,C_word *av) C_noret;
C_noret_decl(f_2972)
static void C_ccall f_2972(C_word c,C_word *av) C_noret;
C_noret_decl(f_2981)
static void C_ccall f_2981(C_word c,C_word *av) C_noret;
C_noret_decl(f_2993)
static void C_ccall f_2993(C_word c,C_word *av) C_noret;
C_noret_decl(f_3017)
static void C_ccall f_3017(C_word c,C_word *av) C_noret;
C_noret_decl(f_3042)
static void C_ccall f_3042(C_word c,C_word *av) C_noret;
C_noret_decl(f_3045)
static void C_ccall f_3045(C_word c,C_word *av) C_noret;
C_noret_decl(f_3049)
static void C_ccall f_3049(C_word c,C_word *av) C_noret;
C_noret_decl(f_3058)
static void C_ccall f_3058(C_word c,C_word *av) C_noret;
C_noret_decl(f_3064)
static void C_ccall f_3064(C_word c,C_word *av) C_noret;
C_noret_decl(f_3068)
static void C_ccall f_3068(C_word c,C_word *av) C_noret;
C_noret_decl(f_3072)
static void C_ccall f_3072(C_word c,C_word *av) C_noret;
C_noret_decl(f_3076)
static void C_ccall f_3076(C_word c,C_word *av) C_noret;
C_noret_decl(f_3080)
static void C_ccall f_3080(C_word c,C_word *av) C_noret;
C_noret_decl(f_3089)
static void C_ccall f_3089(C_word c,C_word *av) C_noret;
C_noret_decl(f_3447)
static void C_ccall f_3447(C_word c,C_word *av) C_noret;
C_noret_decl(f_3452)
static void C_fcall f_3452(C_word t0) C_noret;
C_noret_decl(f_3460)
static void C_fcall f_3460(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3474)
static void C_ccall f_3474(C_word c,C_word *av) C_noret;
C_noret_decl(f_3487)
static void C_ccall f_3487(C_word c,C_word *av) C_noret;
C_noret_decl(f_3490)
static void C_ccall f_3490(C_word c,C_word *av) C_noret;
C_noret_decl(f_3493)
static void C_ccall f_3493(C_word c,C_word *av) C_noret;
C_noret_decl(f_3504)
static void C_fcall f_3504(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3512)
static void C_ccall f_3512(C_word c,C_word *av) C_noret;
C_noret_decl(f_3516)
static void C_ccall f_3516(C_word c,C_word *av) C_noret;
C_noret_decl(f_3522)
static void C_ccall f_3522(C_word c,C_word *av) C_noret;
C_noret_decl(f_3524)
static void C_fcall f_3524(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3549)
static void C_ccall f_3549(C_word c,C_word *av) C_noret;
C_noret_decl(f_3561)
static void C_ccall f_3561(C_word c,C_word *av) C_noret;
C_noret_decl(f_3567)
static C_word C_fcall f_3567(C_word t0,C_word t1);
C_noret_decl(f_3573)
static void C_fcall f_3573(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3598)
static void C_ccall f_3598(C_word c,C_word *av) C_noret;
C_noret_decl(f_3609)
static void C_ccall f_3609(C_word c,C_word *av) C_noret;
C_noret_decl(f_3613)
static void C_ccall f_3613(C_word c,C_word *av) C_noret;
C_noret_decl(f_3619)
static void C_ccall f_3619(C_word c,C_word *av) C_noret;
C_noret_decl(f_3628)
static void C_ccall f_3628(C_word c,C_word *av) C_noret;
C_noret_decl(f_3633)
static void C_fcall f_3633(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3637)
static void C_ccall f_3637(C_word c,C_word *av) C_noret;
C_noret_decl(f_3640)
static void C_ccall f_3640(C_word c,C_word *av) C_noret;
C_noret_decl(f_3643)
static void C_ccall f_3643(C_word c,C_word *av) C_noret;
C_noret_decl(f_3646)
static void C_ccall f_3646(C_word c,C_word *av) C_noret;
C_noret_decl(f_3649)
static void C_ccall f_3649(C_word c,C_word *av) C_noret;
C_noret_decl(f_3676)
static void C_ccall f_3676(C_word c,C_word *av) C_noret;
C_noret_decl(f_3680)
static void C_ccall f_3680(C_word c,C_word *av) C_noret;
C_noret_decl(f_3699)
static void C_ccall f_3699(C_word c,C_word *av) C_noret;
C_noret_decl(f_3701)
static void C_fcall f_3701(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3726)
static void C_ccall f_3726(C_word c,C_word *av) C_noret;
C_noret_decl(f_3738)
static void C_fcall f_3738(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3765)
static void C_ccall f_3765(C_word c,C_word *av) C_noret;
C_noret_decl(f_3778)
static void C_ccall f_3778(C_word c,C_word *av) C_noret;
C_noret_decl(f_3782)
static void C_ccall f_3782(C_word c,C_word *av) C_noret;
C_noret_decl(f_3786)
static void C_ccall f_3786(C_word c,C_word *av) C_noret;
C_noret_decl(f_3790)
static void C_ccall f_3790(C_word c,C_word *av) C_noret;
C_noret_decl(f_3794)
static void C_ccall f_3794(C_word c,C_word *av) C_noret;
C_noret_decl(f_3800)
static void C_ccall f_3800(C_word c,C_word *av) C_noret;
C_noret_decl(f_3806)
static void C_fcall f_3806(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3817)
static void C_ccall f_3817(C_word c,C_word *av) C_noret;
C_noret_decl(f_3826)
static void C_ccall f_3826(C_word c,C_word *av) C_noret;
C_noret_decl(f_3831)
static void C_fcall f_3831(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3841)
static void C_ccall f_3841(C_word c,C_word *av) C_noret;
C_noret_decl(f_3856)
static void C_ccall f_3856(C_word c,C_word *av) C_noret;
C_noret_decl(f_3860)
static void C_ccall f_3860(C_word c,C_word *av) C_noret;
C_noret_decl(f_3864)
static void C_ccall f_3864(C_word c,C_word *av) C_noret;
C_noret_decl(f_3866)
static void C_fcall f_3866(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3885)
static void C_ccall f_3885(C_word c,C_word *av) C_noret;
C_noret_decl(f_3899)
static void C_ccall f_3899(C_word c,C_word *av) C_noret;
C_noret_decl(f_3903)
static void C_ccall f_3903(C_word c,C_word *av) C_noret;
C_noret_decl(f_3909)
static void C_ccall f_3909(C_word c,C_word *av) C_noret;
C_noret_decl(f_3922)
static void C_ccall f_3922(C_word c,C_word *av) C_noret;
C_noret_decl(f_3928)
static void C_ccall f_3928(C_word c,C_word *av) C_noret;
C_noret_decl(f_3943)
static void C_ccall f_3943(C_word c,C_word *av) C_noret;
C_noret_decl(f_3948)
static void C_ccall f_3948(C_word c,C_word *av) C_noret;
C_noret_decl(f_3959)
static void C_fcall f_3959(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3969)
static void C_ccall f_3969(C_word c,C_word *av) C_noret;
C_noret_decl(f_4001)
static void C_fcall f_4001(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4011)
static void C_ccall f_4011(C_word c,C_word *av) C_noret;
C_noret_decl(f_4014)
static void C_ccall f_4014(C_word c,C_word *av) C_noret;
C_noret_decl(f_4021)
static void C_ccall f_4021(C_word c,C_word *av) C_noret;
C_noret_decl(f_4039)
static void C_fcall f_4039(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4050)
static void C_ccall f_4050(C_word c,C_word *av) C_noret;
C_noret_decl(f_4057)
static void C_ccall f_4057(C_word c,C_word *av) C_noret;
C_noret_decl(f_4130)
static void C_ccall f_4130(C_word c,C_word *av) C_noret;
C_noret_decl(f_4143)
static void C_ccall f_4143(C_word c,C_word *av) C_noret;
C_noret_decl(f_4155)
static void C_ccall f_4155(C_word c,C_word *av) C_noret;
C_noret_decl(f_4159)
static void C_fcall f_4159(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4204)
static void C_ccall f_4204(C_word c,C_word *av) C_noret;
C_noret_decl(f_4243)
static void C_ccall f_4243(C_word c,C_word *av) C_noret;
C_noret_decl(f_4249)
static void C_ccall f_4249(C_word c,C_word *av) C_noret;
C_noret_decl(f_4253)
static void C_ccall f_4253(C_word c,C_word *av) C_noret;
C_noret_decl(f_4260)
static void C_ccall f_4260(C_word c,C_word *av) C_noret;
C_noret_decl(f_4263)
static void C_ccall f_4263(C_word c,C_word *av) C_noret;
C_noret_decl(f_4270)
static void C_ccall f_4270(C_word c,C_word *av) C_noret;
C_noret_decl(f_4275)
static void C_ccall f_4275(C_word c,C_word *av) C_noret;
C_noret_decl(f_4280)
static void C_ccall f_4280(C_word c,C_word *av) C_noret;
C_noret_decl(f_4284)
static void C_ccall f_4284(C_word c,C_word *av) C_noret;
C_noret_decl(f_4288)
static void C_ccall f_4288(C_word c,C_word *av) C_noret;
C_noret_decl(f_4295)
static void C_ccall f_4295(C_word c,C_word *av) C_noret;
C_noret_decl(f_4297)
static void C_ccall f_4297(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1997)
static void C_ccall trf_1997(C_word c,C_word *av) C_noret;
static void C_ccall trf_1997(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1997(t0,t1,t2);}

C_noret_decl(trf_2025)
static void C_ccall trf_2025(C_word c,C_word *av) C_noret;
static void C_ccall trf_2025(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2025(t0,t1,t2);}

C_noret_decl(trf_2100)
static void C_ccall trf_2100(C_word c,C_word *av) C_noret;
static void C_ccall trf_2100(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2100(t0,t1,t2);}

C_noret_decl(trf_2139)
static void C_ccall trf_2139(C_word c,C_word *av) C_noret;
static void C_ccall trf_2139(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2139(t0,t1,t2);}

C_noret_decl(trf_2148)
static void C_ccall trf_2148(C_word c,C_word *av) C_noret;
static void C_ccall trf_2148(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2148(t0,t1,t2);}

C_noret_decl(trf_2156)
static void C_ccall trf_2156(C_word c,C_word *av) C_noret;
static void C_ccall trf_2156(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2156(t0,t1,t2,t3);}

C_noret_decl(trf_3452)
static void C_ccall trf_3452(C_word c,C_word *av) C_noret;
static void C_ccall trf_3452(C_word c,C_word *av){
C_word t0=av[0];
f_3452(t0);}

C_noret_decl(trf_3460)
static void C_ccall trf_3460(C_word c,C_word *av) C_noret;
static void C_ccall trf_3460(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3460(t0,t1);}

C_noret_decl(trf_3504)
static void C_ccall trf_3504(C_word c,C_word *av) C_noret;
static void C_ccall trf_3504(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3504(t0,t1,t2);}

C_noret_decl(trf_3524)
static void C_ccall trf_3524(C_word c,C_word *av) C_noret;
static void C_ccall trf_3524(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3524(t0,t1,t2);}

C_noret_decl(trf_3573)
static void C_ccall trf_3573(C_word c,C_word *av) C_noret;
static void C_ccall trf_3573(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3573(t0,t1,t2);}

C_noret_decl(trf_3633)
static void C_ccall trf_3633(C_word c,C_word *av) C_noret;
static void C_ccall trf_3633(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3633(t0,t1);}

C_noret_decl(trf_3701)
static void C_ccall trf_3701(C_word c,C_word *av) C_noret;
static void C_ccall trf_3701(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3701(t0,t1,t2);}

C_noret_decl(trf_3738)
static void C_ccall trf_3738(C_word c,C_word *av) C_noret;
static void C_ccall trf_3738(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3738(t0,t1,t2);}

C_noret_decl(trf_3806)
static void C_ccall trf_3806(C_word c,C_word *av) C_noret;
static void C_ccall trf_3806(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3806(t0,t1);}

C_noret_decl(trf_3831)
static void C_ccall trf_3831(C_word c,C_word *av) C_noret;
static void C_ccall trf_3831(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3831(t0,t1,t2);}

C_noret_decl(trf_3866)
static void C_ccall trf_3866(C_word c,C_word *av) C_noret;
static void C_ccall trf_3866(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3866(t0,t1);}

C_noret_decl(trf_3959)
static void C_ccall trf_3959(C_word c,C_word *av) C_noret;
static void C_ccall trf_3959(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3959(t0,t1,t2);}

C_noret_decl(trf_4001)
static void C_ccall trf_4001(C_word c,C_word *av) C_noret;
static void C_ccall trf_4001(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4001(t0,t1,t2,t3);}

C_noret_decl(trf_4039)
static void C_ccall trf_4039(C_word c,C_word *av) C_noret;
static void C_ccall trf_4039(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4039(t0,t1);}

C_noret_decl(trf_4159)
static void C_ccall trf_4159(C_word c,C_word *av) C_noret;
static void C_ccall trf_4159(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4159(t0,t1,t2);}

/* f4517 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f4517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f4517,c,av);}
/* chicken-uninstall.scm:153: chicken.base#exit */
t2=C_fast_retrieve(lf[60]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* f4522 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f4522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f4522,c,av);}
/* chicken-uninstall.scm:153: chicken.base#exit */
t2=C_fast_retrieve(lf[60]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* f4529 in k4128 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static void C_ccall f4529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f4529,c,av);}
/* chicken-uninstall.scm:153: chicken.base#exit */
t2=C_fast_retrieve(lf[60]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* f4536 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f4536(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f4536,c,av);}
/* chicken-uninstall.scm:153: chicken.base#exit */
t2=C_fast_retrieve(lf[60]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k1499 */
static void C_ccall f_1501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1501,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1504,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k1502 in k1499 */
static void C_ccall f_1504(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1504,c,av);}
a=C_alloc(13);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1507,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4297,tmp=(C_word)a,a+=2,tmp);
/* chicken-uninstall.scm:27: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[118]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[118]+1);
av2[1]=t3;
av2[2]=t4;
tp(3,av2);}}

/* k1505 in k1502 in k1499 */
static void C_ccall f_1507(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1507,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1510,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1510,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1513,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1513,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1516,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_irregex_toplevel(2,av2);}}

/* k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1516(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1516,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1519,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

/* k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1519,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1522,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1522,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1525,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_posix_toplevel(2,av2);}}

/* k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1525,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1528,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_1528(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1528,c,av);}
a=C_alloc(5);
t2=C_mutate(&lf[1] /* (set! main#filter ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2139,tmp=(C_word)a,a+=2,tmp));
t3=C_mutate(&lf[3] /* (set! main#staticbuild ...) */,C_mk_bool(STATIC_CHICKEN));
t4=C_mutate(&lf[4] /* (set! main#debugbuild ...) */,C_mk_bool(DEBUG_CHICKEN));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2812,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:43: chicken.platform#feature? */
t6=C_fast_retrieve(lf[114]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[115];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* loop in k4128 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static C_word C_fcall f_1905(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;
loop:{}
t2=C_i_nullp(t1);
if(C_truep(t2)){
return(t2);}
else{
t3=C_i_car(t1);
t4=C_i_memq(t3,lf[97]);
if(C_truep(C_i_not(t4))){
return(C_SCHEME_FALSE);}
else{
t6=C_u_i_cdr(t1);
t1=t6;
goto loop;}}}

/* loop in a3560 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static C_word C_fcall f_1939(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(C_SCHEME_FALSE);}
else{
t2=(
/* mini-srfi-1.scm:88: pred */
  f_3567(((C_word*)t0)[2],C_i_car(t1))
);
if(C_truep(t2)){
return(t2);}
else{
t4=C_u_i_cdr(t1);
t1=t4;
goto loop;}}}

/* loop in k3520 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_fcall f_1997(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1997,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2015,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:101: loop */
t6=t4;
t7=C_u_i_cdr(t2);
t1=t6;
t2=t7;
goto loop;}}

/* k2013 in loop in k3520 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_2015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2015,c,av);}
/* mini-srfi-1.scm:101: scheme#append */
t2=*((C_word*)lf[74]+1);{
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

/* loop in loop in k3491 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_fcall f_2025(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_2025,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
if(C_truep(C_i_string_equal_p(((C_word*)t0)[2],t3))){
/* mini-srfi-1.scm:107: loop */
t7=t1;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}
else{
t4=C_u_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2052,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:109: loop */
t7=t5;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}}}

/* k2050 in loop in loop in k3491 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_ccall f_2052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2052,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k3491 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_fcall f_2100(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_2100,3,t0,t1,t2);}
a=C_alloc(16);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2114,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2127,a[2]=((C_word*)t0)[2],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2025,a[2]=t3,a[3]=t8,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_2025(t10,t6,t4);}}

/* k2112 in loop in k3491 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_2114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2114,c,av);}
a=C_alloc(3);
t2=C_i_equalp(((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?((C_word*)t0)[4]:C_a_i_cons(&a,2,((C_word*)t0)[5],t1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2125 in loop in k3491 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_2127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2127,c,av);}
/* mini-srfi-1.scm:123: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2100(t2,((C_word*)t0)[3],t1);}

/* main#filter in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_fcall f_2139(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2139,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_check_list_2(t3,lf[2]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2148,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_2148(t8,t1,t3);}

/* foldr329 in main#filter in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_fcall f_2148(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_2148,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2156,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2177,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t7=t5;
t8=C_slot(t2,C_fix(1));
t1=t7;
t2=t8;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* g334 in foldr329 in main#filter in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_fcall f_2156(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2156,4,t0,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2163,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:131: pred */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k2161 in g334 in foldr329 in main#filter in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2163(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2163,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]):((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2175 in foldr329 in main#filter in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2177(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2177,c,av);}
/* mini-srfi-1.scm:131: g334 */
t2=((C_word*)t0)[2];
f_2156(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2812(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2812,c,av);}
a=C_alloc(6);
t2=lf[5] /* main#cross-chicken */ =t1;;
t3=lf[6] /* main#binary-version */ =C_fix((C_word)C_BINARY_VERSION);;
t4=lf[7] /* main#major-version */ =C_fix((C_word)C_MAJOR_VERSION);;
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_CHICKEN_INSTALL_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2818,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[8] /* (set! main#chicken-install-program ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2822,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_CC);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2822(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2822,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2826,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_CXX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2826,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2830,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_INSTALL_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2830,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2834,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_CFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2834,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2838,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LDFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2838,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2842,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_INSTALL_PROGRAM_EXECUTABLE_OPTIONS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2842,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2846,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_INSTALL_PROGRAM_FILE_OPTIONS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2846,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2850,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_MORE_LIBS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2850,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2854,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LIB_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 */
static void C_ccall f_2854(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2854,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[9] /* (set! main#default-libdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2858,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_RUN_LIB_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in k1499 in ... */
static void C_ccall f_2858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2858,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[10] /* (set! main#default-runlibdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2862,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_STATIC_LIB_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in k1502 in ... */
static void C_ccall f_2862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2862,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2866,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_INCLUDE_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in k1505 in ... */
static void C_ccall f_2866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2866,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2870,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_BIN_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in k1508 in ... */
static void C_ccall f_2870(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2870,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[11] /* (set! main#default-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2874,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_SHARE_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in k1511 in ... */
static void C_ccall f_2874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2874,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4295,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:64: chicken.platform#software-type */
t3=C_fast_retrieve(lf[113]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in ... */
static void C_ccall f_2882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2882,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2886,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_BIN_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in ... */
static void C_ccall f_2886(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2886,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[11] /* (set! main#default-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2890,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4288,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t5=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)C_CSC_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in ... */
static void C_ccall f_2890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2890,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2894,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4284,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_CSI_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in ... */
static void C_ccall f_2894(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2894,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2898,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4280,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_CHICKEN_DO_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in ... */
static void C_ccall f_2898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2898,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2902,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LIBRARIAN);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in ... */
static void C_ccall f_2902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2902,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2906,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LIBRARIAN_FLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in ... */
static void C_ccall f_2906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2906,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2910,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_PREFIX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in ... */
static void C_ccall f_2910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2910,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2914,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_EGG_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in ... */
static void C_ccall f_2914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2914,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[15] /* (set! main#host-repo ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2918,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LIB_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in ... */
static void C_ccall f_2918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2918,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2922,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_BIN_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in ... */
static void C_ccall f_2922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2922,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2926,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_INCLUDE_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in ... */
static void C_ccall f_2926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2926,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2930,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_SHARE_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in ... */
static void C_ccall f_2930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2930,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2934,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_MORE_LIBS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in ... */
static void C_ccall f_2934(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2934,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2938,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_CFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in ... */
static void C_ccall f_2938(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2938,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2942,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LDFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in ... */
static void C_ccall f_2942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2942,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2946,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_CC);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in ... */
static void C_ccall f_2946(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2946,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2950,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_CXX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in ... */
static void C_ccall f_2950(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2950,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2954,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4275,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_retrieve2(lf[6],C_text("main#binary-version"));
/* ##sys#fixnum->string */
t5=C_fast_retrieve(lf[108]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=C_retrieve2(lf[6],C_text("main#binary-version"));
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in ... */
static void C_ccall f_2954(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2954,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[16] /* (set! main#target-repo ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2958,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4270,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_retrieve2(lf[6],C_text("main#binary-version"));
/* ##sys#fixnum->string */
t6=C_fast_retrieve(lf[108]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=C_retrieve2(lf[6],C_text("main#binary-version"));
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in ... */
static void C_ccall f_2958(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2958,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[17] /* (set! main#target-run-repo ...) */,t1);
t3=C_mutate(&lf[18] /* (set! main#+egg-info-extension+ ...) */,lf[19]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3042,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:122: chicken.process-context#get-environment-variable */
t5=C_fast_retrieve(lf[28]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[106];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2964 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f_2966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2966,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2969,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* egg-environment.scm:106: chicken.process-context#get-environment-variable */
t3=C_fast_retrieve(lf[28]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[85];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2967 in k2964 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static void C_ccall f_2969(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2969,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2972,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_i_not(((C_word*)t0)[3]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2993,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
if(C_truep(t3)){
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_2972(2,av2);}}
else{
/* egg-environment.scm:108: chicken.base#error */
t5=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=lf[84];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}
else{
/* egg-environment.scm:107: chicken.pathname#absolute-pathname? */
t5=C_fast_retrieve(lf[83]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k2970 in k2967 in k2964 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in ... */
static void C_ccall f_2972(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2972,c,av);}
a=C_alloc(4);
t2=C_i_not(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2981,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t2)){
if(C_truep(t2)){
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_4014(2,av2);}}
else{
/* egg-environment.scm:110: chicken.base#error */
t4=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[82];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}
else{
/* egg-environment.scm:109: chicken.pathname#absolute-pathname? */
t4=C_fast_retrieve(lf[83]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k2979 in k2970 in k2967 in k2964 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_2981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2981,c,av);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_4014(2,av2);}}
else{
/* egg-environment.scm:110: chicken.base#error */
t2=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[82];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k2991 in k2967 in k2964 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in ... */
static void C_ccall f_2993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2993,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_2972(2,av2);}}
else{
/* egg-environment.scm:108: chicken.base#error */
t2=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[84];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k3015 in k3458 in main#repo-path in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f_3017(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3017,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?t1:C_retrieve2(lf[15],C_text("main#host-repo")));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in ... */
static void C_ccall f_3042(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3042,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3045,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_3045(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4260,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:123: chicken.platform#system-cache-directory */
t4=C_fast_retrieve(lf[105]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in ... */
static void C_ccall f_3045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3045,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[20] /* (set! main#cache-directory ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3049,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:130: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[52]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[20],C_text("main#cache-directory"));
av2[3]=lf[103];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in ... */
static void C_ccall f_3049(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3049,c,av);}
a=C_alloc(3);
t2=lf[21] /* main#host-extensions */ =C_SCHEME_TRUE;;
t3=lf[22] /* main#force-uninstall */ =C_SCHEME_FALSE;;
t4=lf[23] /* main#sudo-uninstall */ =C_SCHEME_FALSE;;
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3447,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:53: chicken.process-context#get-environment-variable */
t6=C_fast_retrieve(lf[28]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[102];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3056 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_ccall f_3058(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3058,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3064,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* egg-information.scm:34: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[42]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3062 in k3056 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in ... */
static void C_ccall f_3064(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3064,c,av);}
a=C_alloc(4);
t2=(C_truep(t1)?((C_word*)t0)[2]:((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3089,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* egg-information.scm:38: scheme#with-input-from-file */
t4=C_fast_retrieve(lf[50]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=*((C_word*)lf[51]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3066 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_ccall f_3068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3068,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3072,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* egg-information.scm:32: chicken.pathname#pathname-file */
t3=C_fast_retrieve(lf[54]);{
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

/* k3070 in k3066 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in ... */
static void C_ccall f_3072(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3072,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3076,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* egg-information.scm:33: chicken.pathname#pathname-extension */
t3=C_fast_retrieve(lf[53]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3074 in k3070 in k3066 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3076,c,av);}
/* egg-information.scm:30: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[52]);{
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

/* k3078 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_ccall f_3080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3080,c,av);}
/* egg-information.scm:30: chicken.pathname#make-pathname */
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
av2[3]=lf[55];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3087 in k3062 in k3056 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3089(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3089,c,av);}
if(C_truep(C_eofp(t1))){
/* egg-information.scm:40: chicken.base#error */
t2=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[49];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_3856(2,av2);}}}

/* k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in ... */
static void C_ccall f_3447(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3447,c,av);}
a=C_alloc(10);
t2=(C_truep(t1)?t1:lf[24]);
t3=C_mutate(&lf[25] /* (set! main#sudo-program ...) */,t2);
t4=C_mutate(&lf[26] /* (set! main#repo-path ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3452,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate(&lf[31] /* (set! main#delete-installed-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3866,tmp=(C_word)a,a+=2,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4243,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4253,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:199: chicken.process-context#command-line-arguments */
t8=C_fast_retrieve(lf[101]);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* main#repo-path in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in ... */
static void C_fcall f_3452(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_3452,1,t1);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3460,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[5],C_text("main#cross-chicken")))){
t3=C_i_not(C_retrieve2(lf[21],C_text("main#host-extensions")));
t4=t2;
f_3460(t4,(C_truep(t3)?lf[27]:lf[30]));}
else{
t3=t2;
f_3460(t3,lf[30]);}}

/* k3458 in main#repo-path in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in ... */
static void C_fcall f_3460(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_3460,2,t0,t1);}
a=C_alloc(3);
t2=C_SCHEME_END_OF_LIST;
t3=C_i_nullp(t2);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_i_car(t2));
t5=C_eqp(lf[27],t1);
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t6;
av2[1]=(C_truep(t4)?C_retrieve2(lf[17],C_text("main#target-run-repo")):C_retrieve2(lf[16],C_text("main#target-repo")));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3017,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:115: chicken.process-context#get-environment-variable */
t7=C_fast_retrieve(lf[28]);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[29];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* a3473 in k3510 in g984 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_3474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3474,c,av);}
t3=C_fast_retrieve(lf[77]);
/* chicken-uninstall.scm:63: g943 */
t4=C_fast_retrieve(lf[77]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in ... */
static void C_ccall f_3487(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_3487,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3490,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3573,a[2]=((C_word*)t0)[5],a[3]=t4,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_3573(t6,t2,t1);}

/* k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_3490(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_3490,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3493,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3504,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t8=C_i_check_list_2(((C_word*)t0)[4],lf[73]);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3522,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3524,a[2]=t5,a[3]=t11,a[4]=t7,a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_3524(t13,t9,((C_word*)t0)[4]);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3561,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:73: filter */
f_2139(t2,t3,t1);}}

/* k3491 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_ccall f_3493(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3493,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2100,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_2100(t5,((C_word*)t0)[2],t1);}

/* g984 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_fcall f_3504(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_3504,3,t0,t1,t2);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3512,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3516,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:71: chicken.irregex#glob->sre */
t5=C_fast_retrieve(lf[79]);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3510 in g984 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_ccall f_3512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3512,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3474,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:63: filter */
f_2139(((C_word*)t0)[2],t2,((C_word*)t0)[3]);}

/* k3514 in g984 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_ccall f_3516(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3516,c,av);}
/* chicken-uninstall.scm:71: chicken.irregex#irregex */
t2=C_fast_retrieve(lf[78]);{
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

/* k3520 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_ccall f_3522(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3522,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1997,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_1997(t5,((C_word*)t0)[2],t1);}

/* map-loop978 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_fcall f_3524(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3524,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3549,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-uninstall.scm:70: g984 */
t4=((C_word*)t0)[4];
f_3504(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3547 in map-loop978 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_ccall f_3549(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3549,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3524(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a3560 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_ccall f_3561(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3561,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3567,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1939,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=(
  f_1939(t4,((C_word*)t0)[2])
);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* a3566 in a3560 in k3488 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static C_word C_fcall f_3567(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_string_equal_p(t1,((C_word*)t0)[2]));}

/* map-loop951 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_fcall f_3573(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3573,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3598,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-uninstall.scm:66: g957 */
t4=((C_word*)t0)[4];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3596 in map-loop951 in k3485 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_ccall f_3598(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3598,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3573(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k3607 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in ... */
static void C_ccall f_3609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3609,c,av);}
/* chicken-uninstall.scm:67: chicken.file#glob */
t2=C_fast_retrieve(lf[80]);{
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

/* k3611 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in ... */
static void C_ccall f_3613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3613,c,av);}
/* chicken-uninstall.scm:67: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[52]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[81];
av2[4]=C_retrieve2(lf[18],C_text("main#+egg-info-extension+"));
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3617 in k3647 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in ... */
static void C_ccall f_3619(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3619,c,av);}
/* chicken-uninstall.scm:81: chicken.base#exit */
t2=C_fast_retrieve(lf[60]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_3628(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3628,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3633,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_3633(t5,((C_word*)t0)[2]);}

/* loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_fcall f_3633(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3633,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3637,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:89: scheme#display */
t3=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[69];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_ccall f_3637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3637,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3640,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:90: chicken.base#flush-output */
t3=*((C_word*)lf[67]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_3640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3640,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3643,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:91: chicken.io#read-line */
t3=C_fast_retrieve(lf[66]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_ccall f_3643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3643,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3646,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_eofp(t1))){
/* chicken-uninstall.scm:93: chicken.base#error */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[65];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_3646(2,av2);}}}

/* k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in ... */
static void C_ccall f_3646(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_3646,c,av);}
a=C_alloc(26);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3649,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3738,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3778,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3782,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3786,a[2]=t4,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3790,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3794,a[2]=t4,a[3]=t9,tmp=(C_word)a,a+=4,tmp);
/* ##sys#string->list */
t11=C_fast_retrieve(lf[64]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t10;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}

/* k3647 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3649,c,av);}
a=C_alloc(3);
t2=C_i_string_equal_p(t1,lf[58]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(t1,lf[59]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3619,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:80: chicken.base#print */
t4=*((C_word*)lf[44]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[61];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* chicken-uninstall.scm:97: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3633(t3,((C_word*)t0)[2]);}}}

/* k3674 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_3676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3676,c,av);}
/* chicken-uninstall.scm:84: chicken.base#print */
t2=*((C_word*)lf[44]+1);{
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

/* k3678 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_3680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3680,c,av);}
/* chicken-uninstall.scm:84: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[70]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[71];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3697 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_3699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3699,c,av);}
/* chicken-uninstall.scm:85: scheme#append */
t2=*((C_word*)lf[74]+1);{
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

/* map-loop1019 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_fcall f_3701(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_3701,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3726,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-uninstall.scm:86: g1042 */
t4=*((C_word*)lf[36]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[75];
av2[3]=C_slot(t2,C_fix(0));
av2[4]=lf[76];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3724 in map-loop1019 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_ccall f_3726(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3726,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3701(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* left in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_fcall f_3738(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3738,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
if(C_truep(C_u_i_char_whitespacep(t3))){
/* chicken-uninstall.scm:102: left */
t7=t1;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}
else{
t4=C_u_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3765,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:103: left */
t7=t5;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}}}

/* k3763 in left in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in ... */
static void C_ccall f_3765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3765,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3776 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3778(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3778,c,av);}
/* ##sys#list->string */
t2=C_fast_retrieve(lf[62]);{
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

/* k3780 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3782(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3782,c,av);}
/* chicken-uninstall.scm:104: scheme#reverse */
t2=*((C_word*)lf[63]+1);{
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

/* k3784 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3786,c,av);}
/* chicken-uninstall.scm:104: left */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3738(t2,((C_word*)t0)[3],t1);}

/* k3788 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3790,c,av);}
/* chicken-uninstall.scm:104: scheme#reverse */
t2=*((C_word*)lf[63]+1);{
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

/* k3792 in k3644 in k3641 in k3638 in k3635 in loop in k3626 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3794,c,av);}
/* chicken-uninstall.scm:104: left */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3738(t2,((C_word*)t0)[3],t1);}

/* k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_3800(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_3800,c,av);}
a=C_alloc(21);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3806,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3856,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3058,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3068,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3080,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* egg-information.scm:30: chicken.pathname#pathname-directory */
t7=C_fast_retrieve(lf[56]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t2=((C_word*)((C_word*)t0)[3])[1];
f_3959(t2,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}}

/* k3804 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_fcall f_3806(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_3806,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
t2=C_i_check_list_2(t1,lf[46]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3826,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3831,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_3831(t7,t3,t1);}
else{
t2=((C_word*)((C_word*)t0)[4])[1];
f_3959(t2,((C_word*)t0)[5],C_slot(((C_word*)t0)[6],C_fix(1)));}}

/* k3815 in for-each-loop1081 in k3804 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3817(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3817,c,av);}
if(C_truep(t1)){
/* chicken-uninstall.scm:113: delete-installed-file */
f_3866(((C_word*)t0)[2],((C_word*)t0)[3]);}
else{
t2=((C_word*)((C_word*)t0)[4])[1];
f_3831(t2,((C_word*)t0)[5],C_slot(((C_word*)t0)[6],C_fix(1)));}}

/* k3824 in k3804 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in ... */
static void C_ccall f_3826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3826,c,av);}
/* chicken-uninstall.scm:115: delete-installed-file */
f_3866(((C_word*)t0)[2],((C_word*)t0)[3]);}

/* for-each-loop1081 in k3804 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in ... */
static void C_fcall f_3831(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_3831,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3841,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3817,a[2]=t3,a[3]=t4,a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
/* chicken-uninstall.scm:113: chicken.file#file-exists? */
t6=C_fast_retrieve(lf[42]);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3839 in for-each-loop1081 in k3804 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in ... */
static void C_ccall f_3841(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3841,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3831(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k3854 in k3798 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in ... */
static void C_ccall f_3856(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3856,c,av);}
t2=C_SCHEME_END_OF_LIST;
t3=C_i_nullp(t2);
t4=(C_truep(t3)?C_SCHEME_END_OF_LIST:C_i_car(t2));
t5=C_i_assq(lf[47],t1);
if(C_truep(t5)){
t6=C_i_cdr(t5);
t7=((C_word*)t0)[2];
f_3806(t7,(C_truep(t6)?t6:t4));}
else{
t6=((C_word*)t0)[2];
f_3806(t6,t4);}}

/* k3858 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_3860(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3860,c,av);}
/* chicken-uninstall.scm:107: chicken.file#file-exists? */
t2=C_fast_retrieve(lf[42]);{
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

/* k3862 in k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in ... */
static void C_ccall f_3864(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3864,c,av);}
/* chicken-uninstall.scm:108: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[52]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
av2[4]=C_retrieve2(lf[18],C_text("main#+egg-info-extension+"));
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* main#delete-installed-file in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in ... */
static void C_fcall f_3866(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3866,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3922,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:118: chicken.file#file-exists? */
t4=C_fast_retrieve(lf[42]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3883 in k3920 in main#delete-installed-file in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f_3885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3885,c,av);}
t2=C_eqp(t1,C_fix(0));
if(C_truep(t2)){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* chicken-uninstall.scm:123: chicken.base#warning */
t3=C_fast_retrieve(lf[32]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[34];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k3897 in k3920 in main#delete-installed-file in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f_3899(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3899,c,av);}
/* chicken-uninstall.scm:121: chicken.process#system */
t2=C_fast_retrieve(lf[35]);{
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

/* k3901 in k3920 in main#delete-installed-file in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f_3903(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3903,c,av);}
/* chicken-uninstall.scm:121: scheme#string-append */
t2=*((C_word*)lf[36]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[25],C_text("main#sudo-program"));
av2[3]=lf[37];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3907 in k3920 in main#delete-installed-file in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f_3909(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3909,c,av);}
if(C_truep(t1)){
/* chicken-uninstall.scm:125: chicken.file#delete-directory */
t2=C_fast_retrieve(lf[39]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
/* chicken-uninstall.scm:127: chicken.file#delete-file */
t2=C_fast_retrieve(lf[40]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k3920 in main#delete-installed-file in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in ... */
static void C_ccall f_3922(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3922,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(t1))){
/* chicken-uninstall.scm:119: chicken.base#warning */
t2=C_fast_retrieve(lf[32]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[33];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(C_truep(C_retrieve2(lf[23],C_text("main#sudo-uninstall")))?C_eqp(lf[13],C_retrieve2(lf[14],C_text("main#default-platform"))):C_SCHEME_FALSE);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3885,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3899,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3903,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:121: chicken.process#qs */
t6=C_fast_retrieve(lf[38]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3909,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:124: chicken.file#directory-exists? */
t4=C_fast_retrieve(lf[41]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}}

/* k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in ... */
static void C_ccall f_3928(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,3)))){
C_save_and_reclaim((void *)f_3928,c,av);}
a=C_alloc(32);
if(C_truep(C_i_nullp(t1))){
/* chicken-uninstall.scm:132: chicken.base#print */
t2=*((C_word*)lf[44]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[45];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_retrieve2(lf[22],C_text("main#force-uninstall"));
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3943,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[22],C_text("main#force-uninstall")))){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_retrieve2(lf[22],C_text("main#force-uninstall"));
f_3943(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3628,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3676,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3680,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t7=C_a_i_list1(&a,1,lf[72]);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_i_check_list_2(t1,lf[73]);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3699,a[2]=t6,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3701,a[2]=t10,a[3]=t15,a[4]=t11,tmp=(C_word)a,a+=5,tmp));
t17=((C_word*)t15)[1];
f_3701(t17,t13,t1);}}}

/* k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in ... */
static void C_ccall f_3943(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3943,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_i_check_list_2(((C_word*)t0)[2],lf[46]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3959,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_3959(t6,((C_word*)t0)[3],((C_word*)t0)[2]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3946 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_ccall f_3948(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3948,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3800,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3860,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3864,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:108: repo-path */
f_3452(t4);}

/* for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in ... */
static void C_fcall f_3959(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_3959,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3969,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3948,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* chicken-uninstall.scm:136: chicken.base#print */
t6=*((C_word*)lf[44]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[57];
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3967 in for-each-loop1120 in k3941 in k3926 in k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in ... */
static void C_ccall f_3969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3969,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3959(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in ... */
static void C_fcall f_4001(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_4001,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4011,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f4517,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:141: chicken.base#print */
t6=*((C_word*)lf[44]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[87];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_4011(2,av2);}}}
else{
t4=C_i_car(t2);
t5=C_i_string_equal_p(t4,lf[88]);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4039,a[2]=t1,a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=t2,a[6]=t3,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t5)){
t7=t6;
f_4039(t7,t5);}
else{
t7=C_u_i_string_equal_p(t4,lf[99]);
t8=t6;
f_4039(t8,(C_truep(t7)?t7:C_u_i_string_equal_p(t4,lf[100])));}}}

/* k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_ccall f_4011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4011,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4014,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2966,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:105: chicken.process-context#get-environment-variable */
t4=C_fast_retrieve(lf[28]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[86];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f_4014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4014,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4021,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-uninstall.scm:163: scheme#reverse */
t3=*((C_word*)lf[63]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4019 in k4012 in k4009 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static void C_ccall f_4021(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,2)))){
C_save_and_reclaim((void *)f_4021,c,av);}
a=C_alloc(22);
t2=((C_word*)((C_word*)t0)[2])[1];
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3928,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_fast_retrieve(lf[54]);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3487,a[2]=t3,a[3]=t2,a[4]=t1,a[5]=t6,a[6]=t8,a[7]=t7,tmp=(C_word)a,a+=8,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3609,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3613,a[2]=t10,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:67: repo-path */
f_3452(t11);}

/* k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in ... */
static void C_fcall f_4039(C_word t0,C_word t1){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4039,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f4522,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:141: chicken.base#print */
t3=*((C_word*)lf[44]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[87];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(((C_word*)t0)[3],lf[89]))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4050,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4057,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:171: chicken.platform#chicken-version */
t4=C_fast_retrieve(lf[90]);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(((C_word*)t0)[3],lf[91]))){
t2=lf[21] /* main#host-extensions */ =C_SCHEME_FALSE;;
/* chicken-uninstall.scm:175: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_4001(t3,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[5]),((C_word*)t0)[6]);}
else{
if(C_truep(C_u_i_string_equal_p(((C_word*)t0)[3],lf[92]))){
/* chicken-uninstall.scm:178: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_4001(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[5]),((C_word*)t0)[6]);}
else{
if(C_truep(C_u_i_string_equal_p(((C_word*)t0)[3],lf[93]))){
t2=lf[22] /* main#force-uninstall */ =C_SCHEME_TRUE;;
/* chicken-uninstall.scm:181: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_4001(t3,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[5]),((C_word*)t0)[6]);}
else{
if(C_truep(C_u_i_string_equal_p(((C_word*)t0)[3],lf[94]))){
t2=C_set_block_item(((C_word*)t0)[7],0,C_SCHEME_TRUE);
/* chicken-uninstall.scm:184: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_4001(t3,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[5]),((C_word*)t0)[6]);}
else{
t2=C_u_i_string_equal_p(((C_word*)t0)[3],lf[95]);
t3=(C_truep(t2)?t2:C_u_i_string_equal_p(((C_word*)t0)[3],lf[96]));
if(C_truep(t3)){
t4=lf[23] /* main#sudo-uninstall */ =C_SCHEME_TRUE;;
/* chicken-uninstall.scm:187: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_4001(t5,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[5]),((C_word*)t0)[6]);}
else{
t4=C_block_size(((C_word*)t0)[3]);
t5=(C_truep(C_i_fixnum_positivep(t4))?C_u_i_char_equalp(C_make_character(45),C_i_string_ref(((C_word*)t0)[3],C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_block_size(((C_word*)t0)[3]);
if(C_truep(C_fixnum_greaterp(t6,C_fix(2)))){
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4130,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4204,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:191: scheme#substring */
t9=*((C_word*)lf[98]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f4536,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:141: chicken.base#print */
t8=*((C_word*)lf[44]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[87];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}
else{
t6=C_u_i_cdr(((C_word*)t0)[5]);
t7=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[6]);
/* chicken-uninstall.scm:197: loop */
t8=((C_word*)((C_word*)t0)[4])[1];
f_4001(t8,((C_word*)t0)[2],t6,t7);}}}}}}}}}

/* k4048 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f_4050(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4050,c,av);}
/* chicken-uninstall.scm:172: chicken.base#exit */
t2=C_fast_retrieve(lf[60]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k4055 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f_4057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4057,c,av);}
/* chicken-uninstall.scm:171: chicken.base#print */
t2=*((C_word*)lf[44]+1);{
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

/* k4128 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f_4130(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_4130,c,av);}
a=C_alloc(23);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_1905,tmp=(C_word)a,a+=2,tmp);
t3=(
  f_1905(t1)
);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4143,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4155,a[2]=t4,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4159,a[2]=t7,a[3]=t11,a[4]=t8,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_4159(t13,t9,t1);}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f4529,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* chicken-uninstall.scm:141: chicken.base#print */
t5=*((C_word*)lf[44]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[87];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k4141 in k4128 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static void C_ccall f_4143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4143,c,av);}
/* chicken-uninstall.scm:193: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_4001(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k4153 in k4128 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static void C_ccall f_4155(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4155,c,av);}
/* chicken-uninstall.scm:193: scheme#append */
t2=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_u_i_cdr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop1185 in k4128 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in ... */
static void C_fcall f_4159(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4159,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_string(&a,2,C_make_character(45),t3);
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

/* k4202 in k4037 in loop in k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in ... */
static void C_ccall f_4204(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4204,c,av);}
/* ##sys#string->list */
t2=C_fast_retrieve(lf[64]);{
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

/* k4241 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in ... */
static void C_ccall f_4243(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4243,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4249,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base#implicit-exit-handler */
t3=C_fast_retrieve(lf[43]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4247 in k4241 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in ... */
static void C_ccall f_4249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4249,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4251 in k3445 in k3047 in k3043 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in ... */
static void C_ccall f_4253(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_4253,c,av);}
a=C_alloc(8);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4001,a[2]=t3,a[3]=t5,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_4001(t7,((C_word*)t0)[2],t1,C_SCHEME_END_OF_LIST);}

/* k4258 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in ... */
static void C_ccall f_4260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4260,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4263,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
/* egg-environment.scm:123: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[52]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[8],C_text("main#chicken-install-program"));
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* egg-environment.scm:124: chicken.process-context#current-directory */
t3=C_fast_retrieve(lf[104]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4261 in k4258 in k3040 in k2956 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in ... */
static void C_ccall f_4263(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4263,c,av);}
/* egg-environment.scm:123: chicken.pathname#make-pathname */
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
av2[3]=C_retrieve2(lf[8],C_text("main#chicken-install-program"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4268 in k2952 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in ... */
static void C_ccall f_4270(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4270,c,av);}
/* egg-environment.scm:99: scheme#string-append */
t2=*((C_word*)lf[36]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[10],C_text("main#default-runlibdir"));
av2[3]=lf[107];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4273 in k2948 in k2944 in k2940 in k2936 in k2932 in k2928 in k2924 in k2920 in k2916 in k2912 in k2908 in k2904 in k2900 in k2896 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in ... */
static void C_ccall f_4275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4275,c,av);}
/* egg-environment.scm:96: scheme#string-append */
t2=*((C_word*)lf[36]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[9],C_text("main#default-libdir"));
av2[3]=lf[109];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4278 in k2892 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in ... */
static void C_ccall f_4280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4280,c,av);}
/* egg-environment.scm:78: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[52]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[11],C_text("main#default-bindir"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4282 in k2888 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in ... */
static void C_ccall f_4284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4284,c,av);}
/* egg-environment.scm:75: scheme#string-append */
t2=*((C_word*)lf[36]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[11],C_text("main#default-bindir"));
av2[3]=lf[111];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4286 in k2884 in k2880 in k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in ... */
static void C_ccall f_4288(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4288,c,av);}
/* egg-environment.scm:72: scheme#string-append */
t2=*((C_word*)lf[36]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[11],C_text("main#default-bindir"));
av2[3]=lf[112];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4293 in k2872 in k2868 in k2864 in k2860 in k2856 in k2852 in k2848 in k2844 in k2840 in k2836 in k2832 in k2828 in k2824 in k2820 in k2816 in k2810 in k1526 in k1523 in k1520 in k1517 in k1514 in ... */
static void C_ccall f_4295(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4295,c,av);}
a=C_alloc(6);
t2=C_eqp(t1,lf[12]);
t3=(C_truep(t2)?C_mk_bool(C_WINDOWS_SHELL):lf[13]);
t4=C_mutate(&lf[14] /* (set! main#default-platform ...) */,t3);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2882,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[110]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_PREFIX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* a4296 in k1502 in k1499 */
static void C_ccall f_4297(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_4297,c,av);}
/* chicken-uninstall.scm:27: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[116]);
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[116]+1);
av2[1]=t1;
av2[2]=lf[117];
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
if(C_unlikely(!C_demand_2(387))){
C_save(t1);
C_rereclaim2(387*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,119);
lf[0]=C_h_intern(&lf[0],5, C_text("main#"));
lf[2]=C_h_intern(&lf[2],5, C_text("foldr"));
lf[12]=C_h_intern(&lf[12],7, C_text("windows"));
lf[13]=C_h_intern(&lf[13],4, C_text("unix"));
lf[19]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010egg-info"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004sudo"));
lf[27]=C_h_intern(&lf[27],6, C_text("target"));
lf[28]=C_h_intern(&lf[28],48, C_text("chicken.process-context#get-environment-variable"));
lf[29]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032CHICKEN_INSTALL_REPOSITORY"));
lf[30]=C_h_intern(&lf[30],4, C_text("host"));
lf[32]=C_h_intern(&lf[32],20, C_text("chicken.base#warning"));
lf[33]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023file does not exist"));
lf[34]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024deleting file failed"));
lf[35]=C_h_intern(&lf[35],22, C_text("chicken.process#system"));
lf[36]=C_h_intern(&lf[36],20, C_text("scheme#string-append"));
lf[37]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015 rm -f -r -- "));
lf[38]=C_h_intern(&lf[38],18, C_text("chicken.process#qs"));
lf[39]=C_h_intern(&lf[39],29, C_text("chicken.file#delete-directory"));
lf[40]=C_h_intern(&lf[40],24, C_text("chicken.file#delete-file"));
lf[41]=C_h_intern(&lf[41],30, C_text("chicken.file#directory-exists\077"));
lf[42]=C_h_intern(&lf[42],25, C_text("chicken.file#file-exists\077"));
lf[43]=C_h_intern(&lf[43],34, C_text("chicken.base#implicit-exit-handler"));
lf[44]=C_h_intern(&lf[44],18, C_text("chicken.base#print"));
lf[45]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022nothing to remove."));
lf[46]=C_h_intern(&lf[46],8, C_text("for-each"));
lf[47]=C_h_intern(&lf[47],15, C_text("installed-files"));
lf[48]=C_h_intern(&lf[48],18, C_text("chicken.base#error"));
lf[49]=C_decode_literal(C_heaptop,C_text("\376B\000\000xempty egg-info file, possibly due to an aborted egg-install - please remove"
" the file and reinstall the corresponding egg"));
lf[50]=C_h_intern(&lf[50],27, C_text("scheme#with-input-from-file"));
lf[51]=C_h_intern(&lf[51],11, C_text("scheme#read"));
lf[52]=C_h_intern(&lf[52],30, C_text("chicken.pathname#make-pathname"));
lf[53]=C_h_intern(&lf[53],35, C_text("chicken.pathname#pathname-extension"));
lf[54]=C_h_intern(&lf[54],30, C_text("chicken.pathname#pathname-file"));
lf[55]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007chicken"));
lf[56]=C_h_intern(&lf[56],35, C_text("chicken.pathname#pathname-directory"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011removing "));
lf[58]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003yes"));
lf[59]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002no"));
lf[60]=C_h_intern(&lf[60],17, C_text("chicken.base#exit"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010aborted."));
lf[62]=C_h_intern(&lf[62],18, C_text("##sys#list->string"));
lf[63]=C_h_intern(&lf[63],14, C_text("scheme#reverse"));
lf[64]=C_h_intern(&lf[64],18, C_text("##sys#string->list"));
lf[65]=C_decode_literal(C_heaptop,C_text("\376B\000\000$EOF - use `-force\047 to proceed anyway"));
lf[66]=C_h_intern(&lf[66],20, C_text("chicken.io#read-line"));
lf[67]=C_h_intern(&lf[67],25, C_text("chicken.base#flush-output"));
lf[68]=C_h_intern(&lf[68],14, C_text("scheme#display"));
lf[69]=C_decode_literal(C_heaptop,C_text("\376B\000\000!Do you want to proceed\077 (yes/no) "));
lf[70]=C_h_intern(&lf[70],33, C_text("chicken.string#string-intersperse"));
lf[71]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376B\000\000+About to delete the following extensions:\012\012"));
lf[73]=C_h_intern(&lf[73],3, C_text("map"));
lf[74]=C_h_intern(&lf[74],13, C_text("scheme#append"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[77]=C_h_intern(&lf[77],30, C_text("chicken.irregex#irregex-search"));
lf[78]=C_h_intern(&lf[78],23, C_text("chicken.irregex#irregex"));
lf[79]=C_h_intern(&lf[79],25, C_text("chicken.irregex#glob->sre"));
lf[80]=C_h_intern(&lf[80],17, C_text("chicken.file#glob"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\052"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376B\000\0003CHICKEN_INSTALL_PREFIX must be an absolute pathname"));
lf[83]=C_h_intern(&lf[83],35, C_text("chicken.pathname#absolute-pathname\077"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\0007CHICKEN_INSTALL_REPOSITORY must be an absolute pathname"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026CHICKEN_INSTALL_PREFIX"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032CHICKEN_INSTALL_REPOSITORY"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\002,usage: chicken-uninstall [OPTION ...] [NAME ...]\012\012  -h   -help             "
"       show this message and exit\012       -version                 show version a"
"nd exit\012       -force                   don\047t ask, delete whatever matches\012     "
"  -match                   treat NAME as a glob pattern\012  -s   -sudo            "
"        use external command to elevate privileges for deleting files\012       -ho"
"st                    when cross-compiling, uninstall host extensions only\012     "
"  -target                  when cross-compiling, uninstall target extensions onl"
"y"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-help"));
lf[89]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-version"));
lf[90]=C_h_intern(&lf[90],32, C_text("chicken.platform#chicken-version"));
lf[91]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-target"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-host"));
lf[93]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006-force"));
lf[94]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006-match"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-s"));
lf[96]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-sudo"));
lf[97]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000h\376\003\000\000\002\376\377\012\000\000s\376\003\000\000\002\376\377\012\000\000p\376\377\016"));
lf[98]=C_h_intern(&lf[98],16, C_text("scheme#substring"));
lf[99]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-h"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006--help"));
lf[101]=C_h_intern(&lf[101],46, C_text("chicken.process-context#command-line-arguments"));
lf[102]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004SUDO"));
lf[103]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017.cache-metadata"));
lf[104]=C_h_intern(&lf[104],41, C_text("chicken.process-context#current-directory"));
lf[105]=C_h_intern(&lf[105],39, C_text("chicken.platform#system-cache-directory"));
lf[106]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021CHICKEN_EGG_CACHE"));
lf[107]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011/chicken/"));
lf[108]=C_h_intern(&lf[108],20, C_text("##sys#fixnum->string"));
lf[109]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011/chicken/"));
lf[110]=C_h_intern(&lf[110],19, C_text("##sys#peek-c-string"));
lf[111]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[112]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[113]=C_h_intern(&lf[113],30, C_text("chicken.platform#software-type"));
lf[114]=C_h_intern(&lf[114],25, C_text("chicken.platform#feature\077"));
lf[115]=C_h_intern_kw(&lf[115],13, C_text("cross-chicken"));
lf[116]=C_h_intern(&lf[116],30, C_text("##sys#register-compiled-module"));
lf[117]=C_h_intern(&lf[117],4, C_text("main"));
lf[118]=C_h_intern(&lf[118],22, C_text("##sys#with-environment"));
C_register_lf2(lf,119,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1501,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[165] = {
{C_text("f4517:chicken_2duninstall_2escm"),(void*)f4517},
{C_text("f4522:chicken_2duninstall_2escm"),(void*)f4522},
{C_text("f4529:chicken_2duninstall_2escm"),(void*)f4529},
{C_text("f4536:chicken_2duninstall_2escm"),(void*)f4536},
{C_text("f_1501:chicken_2duninstall_2escm"),(void*)f_1501},
{C_text("f_1504:chicken_2duninstall_2escm"),(void*)f_1504},
{C_text("f_1507:chicken_2duninstall_2escm"),(void*)f_1507},
{C_text("f_1510:chicken_2duninstall_2escm"),(void*)f_1510},
{C_text("f_1513:chicken_2duninstall_2escm"),(void*)f_1513},
{C_text("f_1516:chicken_2duninstall_2escm"),(void*)f_1516},
{C_text("f_1519:chicken_2duninstall_2escm"),(void*)f_1519},
{C_text("f_1522:chicken_2duninstall_2escm"),(void*)f_1522},
{C_text("f_1525:chicken_2duninstall_2escm"),(void*)f_1525},
{C_text("f_1528:chicken_2duninstall_2escm"),(void*)f_1528},
{C_text("f_1905:chicken_2duninstall_2escm"),(void*)f_1905},
{C_text("f_1939:chicken_2duninstall_2escm"),(void*)f_1939},
{C_text("f_1997:chicken_2duninstall_2escm"),(void*)f_1997},
{C_text("f_2015:chicken_2duninstall_2escm"),(void*)f_2015},
{C_text("f_2025:chicken_2duninstall_2escm"),(void*)f_2025},
{C_text("f_2052:chicken_2duninstall_2escm"),(void*)f_2052},
{C_text("f_2100:chicken_2duninstall_2escm"),(void*)f_2100},
{C_text("f_2114:chicken_2duninstall_2escm"),(void*)f_2114},
{C_text("f_2127:chicken_2duninstall_2escm"),(void*)f_2127},
{C_text("f_2139:chicken_2duninstall_2escm"),(void*)f_2139},
{C_text("f_2148:chicken_2duninstall_2escm"),(void*)f_2148},
{C_text("f_2156:chicken_2duninstall_2escm"),(void*)f_2156},
{C_text("f_2163:chicken_2duninstall_2escm"),(void*)f_2163},
{C_text("f_2177:chicken_2duninstall_2escm"),(void*)f_2177},
{C_text("f_2812:chicken_2duninstall_2escm"),(void*)f_2812},
{C_text("f_2818:chicken_2duninstall_2escm"),(void*)f_2818},
{C_text("f_2822:chicken_2duninstall_2escm"),(void*)f_2822},
{C_text("f_2826:chicken_2duninstall_2escm"),(void*)f_2826},
{C_text("f_2830:chicken_2duninstall_2escm"),(void*)f_2830},
{C_text("f_2834:chicken_2duninstall_2escm"),(void*)f_2834},
{C_text("f_2838:chicken_2duninstall_2escm"),(void*)f_2838},
{C_text("f_2842:chicken_2duninstall_2escm"),(void*)f_2842},
{C_text("f_2846:chicken_2duninstall_2escm"),(void*)f_2846},
{C_text("f_2850:chicken_2duninstall_2escm"),(void*)f_2850},
{C_text("f_2854:chicken_2duninstall_2escm"),(void*)f_2854},
{C_text("f_2858:chicken_2duninstall_2escm"),(void*)f_2858},
{C_text("f_2862:chicken_2duninstall_2escm"),(void*)f_2862},
{C_text("f_2866:chicken_2duninstall_2escm"),(void*)f_2866},
{C_text("f_2870:chicken_2duninstall_2escm"),(void*)f_2870},
{C_text("f_2874:chicken_2duninstall_2escm"),(void*)f_2874},
{C_text("f_2882:chicken_2duninstall_2escm"),(void*)f_2882},
{C_text("f_2886:chicken_2duninstall_2escm"),(void*)f_2886},
{C_text("f_2890:chicken_2duninstall_2escm"),(void*)f_2890},
{C_text("f_2894:chicken_2duninstall_2escm"),(void*)f_2894},
{C_text("f_2898:chicken_2duninstall_2escm"),(void*)f_2898},
{C_text("f_2902:chicken_2duninstall_2escm"),(void*)f_2902},
{C_text("f_2906:chicken_2duninstall_2escm"),(void*)f_2906},
{C_text("f_2910:chicken_2duninstall_2escm"),(void*)f_2910},
{C_text("f_2914:chicken_2duninstall_2escm"),(void*)f_2914},
{C_text("f_2918:chicken_2duninstall_2escm"),(void*)f_2918},
{C_text("f_2922:chicken_2duninstall_2escm"),(void*)f_2922},
{C_text("f_2926:chicken_2duninstall_2escm"),(void*)f_2926},
{C_text("f_2930:chicken_2duninstall_2escm"),(void*)f_2930},
{C_text("f_2934:chicken_2duninstall_2escm"),(void*)f_2934},
{C_text("f_2938:chicken_2duninstall_2escm"),(void*)f_2938},
{C_text("f_2942:chicken_2duninstall_2escm"),(void*)f_2942},
{C_text("f_2946:chicken_2duninstall_2escm"),(void*)f_2946},
{C_text("f_2950:chicken_2duninstall_2escm"),(void*)f_2950},
{C_text("f_2954:chicken_2duninstall_2escm"),(void*)f_2954},
{C_text("f_2958:chicken_2duninstall_2escm"),(void*)f_2958},
{C_text("f_2966:chicken_2duninstall_2escm"),(void*)f_2966},
{C_text("f_2969:chicken_2duninstall_2escm"),(void*)f_2969},
{C_text("f_2972:chicken_2duninstall_2escm"),(void*)f_2972},
{C_text("f_2981:chicken_2duninstall_2escm"),(void*)f_2981},
{C_text("f_2993:chicken_2duninstall_2escm"),(void*)f_2993},
{C_text("f_3017:chicken_2duninstall_2escm"),(void*)f_3017},
{C_text("f_3042:chicken_2duninstall_2escm"),(void*)f_3042},
{C_text("f_3045:chicken_2duninstall_2escm"),(void*)f_3045},
{C_text("f_3049:chicken_2duninstall_2escm"),(void*)f_3049},
{C_text("f_3058:chicken_2duninstall_2escm"),(void*)f_3058},
{C_text("f_3064:chicken_2duninstall_2escm"),(void*)f_3064},
{C_text("f_3068:chicken_2duninstall_2escm"),(void*)f_3068},
{C_text("f_3072:chicken_2duninstall_2escm"),(void*)f_3072},
{C_text("f_3076:chicken_2duninstall_2escm"),(void*)f_3076},
{C_text("f_3080:chicken_2duninstall_2escm"),(void*)f_3080},
{C_text("f_3089:chicken_2duninstall_2escm"),(void*)f_3089},
{C_text("f_3447:chicken_2duninstall_2escm"),(void*)f_3447},
{C_text("f_3452:chicken_2duninstall_2escm"),(void*)f_3452},
{C_text("f_3460:chicken_2duninstall_2escm"),(void*)f_3460},
{C_text("f_3474:chicken_2duninstall_2escm"),(void*)f_3474},
{C_text("f_3487:chicken_2duninstall_2escm"),(void*)f_3487},
{C_text("f_3490:chicken_2duninstall_2escm"),(void*)f_3490},
{C_text("f_3493:chicken_2duninstall_2escm"),(void*)f_3493},
{C_text("f_3504:chicken_2duninstall_2escm"),(void*)f_3504},
{C_text("f_3512:chicken_2duninstall_2escm"),(void*)f_3512},
{C_text("f_3516:chicken_2duninstall_2escm"),(void*)f_3516},
{C_text("f_3522:chicken_2duninstall_2escm"),(void*)f_3522},
{C_text("f_3524:chicken_2duninstall_2escm"),(void*)f_3524},
{C_text("f_3549:chicken_2duninstall_2escm"),(void*)f_3549},
{C_text("f_3561:chicken_2duninstall_2escm"),(void*)f_3561},
{C_text("f_3567:chicken_2duninstall_2escm"),(void*)f_3567},
{C_text("f_3573:chicken_2duninstall_2escm"),(void*)f_3573},
{C_text("f_3598:chicken_2duninstall_2escm"),(void*)f_3598},
{C_text("f_3609:chicken_2duninstall_2escm"),(void*)f_3609},
{C_text("f_3613:chicken_2duninstall_2escm"),(void*)f_3613},
{C_text("f_3619:chicken_2duninstall_2escm"),(void*)f_3619},
{C_text("f_3628:chicken_2duninstall_2escm"),(void*)f_3628},
{C_text("f_3633:chicken_2duninstall_2escm"),(void*)f_3633},
{C_text("f_3637:chicken_2duninstall_2escm"),(void*)f_3637},
{C_text("f_3640:chicken_2duninstall_2escm"),(void*)f_3640},
{C_text("f_3643:chicken_2duninstall_2escm"),(void*)f_3643},
{C_text("f_3646:chicken_2duninstall_2escm"),(void*)f_3646},
{C_text("f_3649:chicken_2duninstall_2escm"),(void*)f_3649},
{C_text("f_3676:chicken_2duninstall_2escm"),(void*)f_3676},
{C_text("f_3680:chicken_2duninstall_2escm"),(void*)f_3680},
{C_text("f_3699:chicken_2duninstall_2escm"),(void*)f_3699},
{C_text("f_3701:chicken_2duninstall_2escm"),(void*)f_3701},
{C_text("f_3726:chicken_2duninstall_2escm"),(void*)f_3726},
{C_text("f_3738:chicken_2duninstall_2escm"),(void*)f_3738},
{C_text("f_3765:chicken_2duninstall_2escm"),(void*)f_3765},
{C_text("f_3778:chicken_2duninstall_2escm"),(void*)f_3778},
{C_text("f_3782:chicken_2duninstall_2escm"),(void*)f_3782},
{C_text("f_3786:chicken_2duninstall_2escm"),(void*)f_3786},
{C_text("f_3790:chicken_2duninstall_2escm"),(void*)f_3790},
{C_text("f_3794:chicken_2duninstall_2escm"),(void*)f_3794},
{C_text("f_3800:chicken_2duninstall_2escm"),(void*)f_3800},
{C_text("f_3806:chicken_2duninstall_2escm"),(void*)f_3806},
{C_text("f_3817:chicken_2duninstall_2escm"),(void*)f_3817},
{C_text("f_3826:chicken_2duninstall_2escm"),(void*)f_3826},
{C_text("f_3831:chicken_2duninstall_2escm"),(void*)f_3831},
{C_text("f_3841:chicken_2duninstall_2escm"),(void*)f_3841},
{C_text("f_3856:chicken_2duninstall_2escm"),(void*)f_3856},
{C_text("f_3860:chicken_2duninstall_2escm"),(void*)f_3860},
{C_text("f_3864:chicken_2duninstall_2escm"),(void*)f_3864},
{C_text("f_3866:chicken_2duninstall_2escm"),(void*)f_3866},
{C_text("f_3885:chicken_2duninstall_2escm"),(void*)f_3885},
{C_text("f_3899:chicken_2duninstall_2escm"),(void*)f_3899},
{C_text("f_3903:chicken_2duninstall_2escm"),(void*)f_3903},
{C_text("f_3909:chicken_2duninstall_2escm"),(void*)f_3909},
{C_text("f_3922:chicken_2duninstall_2escm"),(void*)f_3922},
{C_text("f_3928:chicken_2duninstall_2escm"),(void*)f_3928},
{C_text("f_3943:chicken_2duninstall_2escm"),(void*)f_3943},
{C_text("f_3948:chicken_2duninstall_2escm"),(void*)f_3948},
{C_text("f_3959:chicken_2duninstall_2escm"),(void*)f_3959},
{C_text("f_3969:chicken_2duninstall_2escm"),(void*)f_3969},
{C_text("f_4001:chicken_2duninstall_2escm"),(void*)f_4001},
{C_text("f_4011:chicken_2duninstall_2escm"),(void*)f_4011},
{C_text("f_4014:chicken_2duninstall_2escm"),(void*)f_4014},
{C_text("f_4021:chicken_2duninstall_2escm"),(void*)f_4021},
{C_text("f_4039:chicken_2duninstall_2escm"),(void*)f_4039},
{C_text("f_4050:chicken_2duninstall_2escm"),(void*)f_4050},
{C_text("f_4057:chicken_2duninstall_2escm"),(void*)f_4057},
{C_text("f_4130:chicken_2duninstall_2escm"),(void*)f_4130},
{C_text("f_4143:chicken_2duninstall_2escm"),(void*)f_4143},
{C_text("f_4155:chicken_2duninstall_2escm"),(void*)f_4155},
{C_text("f_4159:chicken_2duninstall_2escm"),(void*)f_4159},
{C_text("f_4204:chicken_2duninstall_2escm"),(void*)f_4204},
{C_text("f_4243:chicken_2duninstall_2escm"),(void*)f_4243},
{C_text("f_4249:chicken_2duninstall_2escm"),(void*)f_4249},
{C_text("f_4253:chicken_2duninstall_2escm"),(void*)f_4253},
{C_text("f_4260:chicken_2duninstall_2escm"),(void*)f_4260},
{C_text("f_4263:chicken_2duninstall_2escm"),(void*)f_4263},
{C_text("f_4270:chicken_2duninstall_2escm"),(void*)f_4270},
{C_text("f_4275:chicken_2duninstall_2escm"),(void*)f_4275},
{C_text("f_4280:chicken_2duninstall_2escm"),(void*)f_4280},
{C_text("f_4284:chicken_2duninstall_2escm"),(void*)f_4284},
{C_text("f_4288:chicken_2duninstall_2escm"),(void*)f_4288},
{C_text("f_4295:chicken_2duninstall_2escm"),(void*)f_4295},
{C_text("f_4297:chicken_2duninstall_2escm"),(void*)f_4297},
{C_text("toplevel:chicken_2duninstall_2escm"),(void*)C_toplevel},
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
o|hiding unexported module binding: main#staticbuild 
o|hiding unexported module binding: main#debugbuild 
o|hiding unexported module binding: main#cross-chicken 
o|hiding unexported module binding: main#binary-version 
o|hiding unexported module binding: main#major-version 
o|hiding unexported module binding: main#chicken-install-program 
o|hiding unexported module binding: main#default-cc 
o|hiding unexported module binding: main#default-cxx 
o|hiding unexported module binding: main#default-install-program 
o|hiding unexported module binding: main#default-cflags 
o|hiding unexported module binding: main#default-ldflags 
o|hiding unexported module binding: main#default-install-program-executable-flags 
o|hiding unexported module binding: main#default-install-program-data-flags 
o|hiding unexported module binding: main#default-libs 
o|hiding unexported module binding: main#default-libdir 
o|hiding unexported module binding: main#default-runlibdir 
o|hiding unexported module binding: main#default-slibdir 
o|hiding unexported module binding: main#default-incdir 
o|hiding unexported module binding: main#default-bindir 
o|hiding unexported module binding: main#default-sharedir 
o|hiding unexported module binding: main#default-platform 
o|hiding unexported module binding: main#default-prefix 
o|hiding unexported module binding: main#default-bindir 
o|hiding unexported module binding: main#default-csc 
o|hiding unexported module binding: main#default-csi 
o|hiding unexported module binding: main#default-builder 
o|hiding unexported module binding: main#target-librarian 
o|hiding unexported module binding: main#target-librarian-options 
o|hiding unexported module binding: main#host-prefix 
o|hiding unexported module binding: main#host-repo 
o|hiding unexported module binding: main#host-libdir 
o|hiding unexported module binding: main#host-bindir 
o|hiding unexported module binding: main#host-incdir 
o|hiding unexported module binding: main#host-sharedir 
o|hiding unexported module binding: main#host-libs 
o|hiding unexported module binding: main#host-cflags 
o|hiding unexported module binding: main#host-ldflags 
o|hiding unexported module binding: main#host-cc 
o|hiding unexported module binding: main#host-cxx 
o|hiding unexported module binding: main#target-repo 
o|hiding unexported module binding: main#target-run-repo 
o|hiding unexported module binding: main#+egg-info-extension+ 
o|hiding unexported module binding: main#+egg-extension+ 
o|hiding unexported module binding: main#validate-environment 
o|hiding unexported module binding: main#destination-repository 
o|hiding unexported module binding: main#probe-dir 
o|hiding unexported module binding: main#cache-directory 
o|hiding unexported module binding: main#cache-metadata-directory 
o|hiding unexported module binding: main#+version-file+ 
o|hiding unexported module binding: main#+timestamp-file+ 
o|hiding unexported module binding: main#+status-file+ 
o|hiding unexported module binding: main#locate-egg-file 
o|hiding unexported module binding: main#load-egg-info 
o|hiding unexported module binding: main#get-egg-property 
o|hiding unexported module binding: main#get-egg-property* 
o|hiding unexported module binding: main#get-extension-property/internal 
o|hiding unexported module binding: main#get-extension-property 
o|hiding unexported module binding: main#get-extension-property* 
o|hiding unexported module binding: main#host-extensions 
o|hiding unexported module binding: main#target-extensions 
o|hiding unexported module binding: main#force-uninstall 
o|hiding unexported module binding: main#sudo-uninstall 
o|hiding unexported module binding: main#sudo-program 
o|hiding unexported module binding: main#repo-path 
o|hiding unexported module binding: main#grep 
o|hiding unexported module binding: main#gather-eggs 
o|hiding unexported module binding: main#fini 
o|hiding unexported module binding: main#ask 
o|hiding unexported module binding: main#trim 
o|hiding unexported module binding: main#remove-extension 
o|hiding unexported module binding: main#delete-installed-file 
o|hiding unexported module binding: main#uninstall 
o|hiding unexported module binding: main#usage 
o|hiding unexported module binding: main#short-options 
o|hiding unexported module binding: main#main 
S|applied compiler syntax:
S|  scheme#for-each		2
S|  chicken.base#foldl		3
S|  scheme#map		7
S|  chicken.base#foldr		3
o|eliminated procedure checks: 77 
o|specializations:
o|  1 (scheme#> fixnum fixnum)
o|  1 (scheme#char=? char char)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#positive? fixnum)
o|  2 (scheme#string-length string)
o|  1 (scheme#zero? integer)
o|  10 (scheme#string=? string string)
o|  2 (scheme#cdar (pair pair *))
o|  5 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  2 (scheme#number->string fixnum)
o|  1 (scheme#eqv? * *)
o|  5 (##sys#check-list (or pair list) *)
o|  37 (scheme#cdr pair)
o|  9 (scheme#car pair)
(o e)|safe calls: 397 
(o e)|assignments to immediate values: 3 
o|removed side-effect free assignment to unused variable: main#partition 
o|removed side-effect free assignment to unused variable: main#span 
o|removed side-effect free assignment to unused variable: main#drop 
o|removed side-effect free assignment to unused variable: main#split-at 
o|removed side-effect free assignment to unused variable: main#append-map 
o|inlining procedure: k1910 
o|inlining procedure: k1910 
o|inlining procedure: k1941 
o|inlining procedure: k1941 
o|removed side-effect free assignment to unused variable: main#cons* 
o|removed side-effect free assignment to unused variable: main#first 
o|removed side-effect free assignment to unused variable: main#second 
o|removed side-effect free assignment to unused variable: main#third 
o|removed side-effect free assignment to unused variable: main#fourth 
o|removed side-effect free assignment to unused variable: main#fifth 
o|removed side-effect free assignment to unused variable: main#alist-cons 
o|inlining procedure: k2158 
o|inlining procedure: k2158 
o|inlining procedure: k2150 
o|inlining procedure: k2150 
o|removed side-effect free assignment to unused variable: main#filter-map 
o|removed side-effect free assignment to unused variable: main#remove 
o|removed side-effect free assignment to unused variable: main#unzip1 
o|removed side-effect free assignment to unused variable: main#last 
o|removed side-effect free assignment to unused variable: main#list-index 
o|removed side-effect free assignment to unused variable: main#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: main#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: main#lset-union/eq? 
o|removed side-effect free assignment to unused variable: main#lset-intersection/eq? 
o|inlining procedure: k2549 
o|inlining procedure: k2549 
o|removed side-effect free assignment to unused variable: main#lset<=/eq? 
o|removed side-effect free assignment to unused variable: main#lset=/eq? 
o|removed side-effect free assignment to unused variable: main#length+ 
o|removed side-effect free assignment to unused variable: main#find 
o|removed side-effect free assignment to unused variable: main#find-tail 
o|removed side-effect free assignment to unused variable: main#iota 
o|removed side-effect free assignment to unused variable: main#make-list 
o|removed side-effect free assignment to unused variable: main#posq 
o|removed side-effect free assignment to unused variable: main#posv 
o|removed side-effect free assignment to unused variable: main#default-cc 
o|removed side-effect free assignment to unused variable: main#default-cxx 
o|removed side-effect free assignment to unused variable: main#default-install-program 
o|removed side-effect free assignment to unused variable: main#default-cflags 
o|removed side-effect free assignment to unused variable: main#default-ldflags 
o|removed side-effect free assignment to unused variable: main#default-install-program-executable-flags 
o|removed side-effect free assignment to unused variable: main#default-install-program-data-flags 
o|removed side-effect free assignment to unused variable: main#default-libs 
o|removed side-effect free assignment to unused variable: main#default-slibdir 
o|removed side-effect free assignment to unused variable: main#default-incdir 
o|removed side-effect free assignment to unused variable: main#default-sharedir 
o|removed side-effect free assignment to unused variable: main#default-prefix 
o|removed side-effect free assignment to unused variable: main#default-csc 
o|removed side-effect free assignment to unused variable: main#default-csi 
o|removed side-effect free assignment to unused variable: main#default-builder 
o|removed side-effect free assignment to unused variable: main#target-librarian 
o|removed side-effect free assignment to unused variable: main#target-librarian-options 
o|removed side-effect free assignment to unused variable: main#host-prefix 
o|removed side-effect free assignment to unused variable: main#host-libdir 
o|removed side-effect free assignment to unused variable: main#host-bindir 
o|removed side-effect free assignment to unused variable: main#host-incdir 
o|removed side-effect free assignment to unused variable: main#host-sharedir 
o|removed side-effect free assignment to unused variable: main#host-libs 
o|removed side-effect free assignment to unused variable: main#host-cflags 
o|removed side-effect free assignment to unused variable: main#host-ldflags 
o|removed side-effect free assignment to unused variable: main#host-cc 
o|removed side-effect free assignment to unused variable: main#host-cxx 
o|removed side-effect free assignment to unused variable: main#+egg-extension+ 
o|removed side-effect free assignment to unused variable: main#probe-dir 
o|removed side-effect free assignment to unused variable: main#cache-metadata-directory 
o|removed side-effect free assignment to unused variable: main#+version-file+ 
o|removed side-effect free assignment to unused variable: main#+timestamp-file+ 
o|removed side-effect free assignment to unused variable: main#+status-file+ 
o|removed side-effect free assignment to unused variable: main#get-egg-property 
o|inlining procedure: k3153 
o|inlining procedure: k3171 
o|inlining procedure: k3171 
o|inlining procedure: k3188 
o|inlining procedure: k3188 
o|substituted constant variable: a3229 
o|substituted constant variable: a3231 
o|inlining procedure: k3153 
o|inlining procedure: k3239 
o|inlining procedure: k3239 
o|inlining procedure: k3249 
o|inlining procedure: k3267 
o|inlining procedure: k3267 
o|inlining procedure: k3284 
o|inlining procedure: k3284 
o|inlining procedure: k3314 
o|inlining procedure: k3314 
o|substituted constant variable: a3343 
o|substituted constant variable: a3345 
o|substituted constant variable: a3347 
o|inlining procedure: k3249 
o|removed side-effect free assignment to unused variable: main#get-extension-property 
o|removed side-effect free assignment to unused variable: main#get-extension-property* 
o|removed side-effect free assignment to unused variable: main#target-extensions 
o|contracted procedure: "(chicken-uninstall.scm:57) main#destination-repository" 
o|inlining procedure: k3006 
o|inlining procedure: k3006 
o|inlining procedure: k3461 
o|inlining procedure: k3461 
o|inlining procedure: k3868 
o|inlining procedure: k3868 
o|inlining procedure: k3886 
o|inlining procedure: k3886 
o|inlining procedure: k3904 
o|inlining procedure: k3904 
o|contracted procedure: "(chicken-uninstall.scm:199) main#main" 
o|inlining procedure: k4003 
o|contracted procedure: "(chicken-uninstall.scm:163) main#uninstall" 
o|inlining procedure: k3929 
o|inlining procedure: k3929 
o|inlining procedure: k3961 
o|contracted procedure: "(chicken-uninstall.scm:134) g11211128" 
o|contracted procedure: "(chicken-uninstall.scm:137) main#remove-extension" 
o|inlining procedure: k3801 
o|inlining procedure: k3833 
o|contracted procedure: "(chicken-uninstall.scm:111) g10821089" 
o|inlining procedure: k3812 
o|inlining procedure: k3812 
o|inlining procedure: k3833 
o|contracted procedure: "(chicken-uninstall.scm:109) main#get-egg-property*" 
o|inlining procedure: k3135 
o|inlining procedure: k3135 
o|contracted procedure: "(chicken-uninstall.scm:109) main#load-egg-info" 
o|inlining procedure: k3090 
o|inlining procedure: k3090 
o|contracted procedure: "(egg-information.scm:37) main#locate-egg-file" 
o|inlining procedure: k3059 
o|inlining procedure: k3059 
o|inlining procedure: k3801 
o|inlining procedure: k3961 
o|propagated global variable: tmp11151117 main#force-uninstall 
o|propagated global variable: tmp11151117 main#force-uninstall 
o|contracted procedure: "(chicken-uninstall.scm:133) main#ask" 
o|inlining procedure: k3653 
o|inlining procedure: k3653 
o|substituted constant variable: a3660 
o|contracted procedure: "(chicken-uninstall.scm:96) main#fini" 
o|contracted procedure: "(chicken-uninstall.scm:94) main#trim" 
o|inlining procedure: k3740 
o|inlining procedure: k3740 
o|inlining procedure: k3703 
o|contracted procedure: "(chicken-uninstall.scm:86) g10251034" 
o|inlining procedure: k3703 
o|contracted procedure: "(chicken-uninstall.scm:130) main#gather-eggs" 
o|contracted procedure: "(chicken-uninstall.scm:77) main#delete-duplicates" 
o|inlining procedure: k2102 
o|inlining procedure: k2102 
o|contracted procedure: "(mini-srfi-1.scm:123) main#delete" 
o|inlining procedure: k2027 
o|inlining procedure: k2027 
o|contracted procedure: "(chicken-uninstall.scm:71) main#grep" 
o|propagated global variable: g943944 chicken.irregex#irregex-search 
o|contracted procedure: "(chicken-uninstall.scm:69) main#concatenate" 
o|inlining procedure: k1999 
o|inlining procedure: k1999 
o|inlining procedure: k3526 
o|inlining procedure: k3526 
o|inlining procedure: k3575 
o|inlining procedure: k3575 
o|contracted procedure: "(chicken-uninstall.scm:162) main#validate-environment" 
o|inlining procedure: k2973 
o|inlining procedure: k2973 
o|inlining procedure: k4003 
o|substituted constant variable: a4047 
o|inlining procedure: k4043 
o|inlining procedure: k4043 
o|substituted constant variable: a4062 
o|substituted constant variable: a4073 
o|removed side-effect free assignment to unused variable: main#target-extensions 
o|inlining procedure: k4069 
o|inlining procedure: k4069 
o|substituted constant variable: a4084 
o|substituted constant variable: a4095 
o|inlining procedure: k4091 
o|inlining procedure: k4091 
o|substituted constant variable: a4106 
o|inlining procedure: k4116 
o|inlining procedure: k4131 
o|inlining procedure: k4161 
o|contracted procedure: "(chicken-uninstall.scm:193) g11911200" 
o|inlining procedure: k4161 
o|inlining procedure: k4131 
o|substituted constant variable: main#short-options 
o|substituted constant variable: a4212 
o|inlining procedure: k4116 
o|substituted constant variable: a4230 
o|substituted constant variable: a4227 
o|substituted constant variable: a4233 
o|substituted constant variable: a4235 
o|inlining procedure: k4236 
o|inlining procedure: k4236 
o|substituted constant variable: a4240 
o|inlining procedure: k4261 
o|inlining procedure: k4261 
o|replaced variables: 417 
o|removed binding forms: 189 
o|substituted constant variable: r21514325 
o|removed side-effect free assignment to unused variable: main#list-tabulate 
o|removed side-effect free assignment to unused variable: main#get-extension-property/internal 
o|substituted constant variable: r34624347 
o|removed side-effect free assignment to unused variable: main#short-options 
o|substituted constant variable: prop819 
o|substituted constant variable: r38024369 
o|substituted constant variable: code1013 
o|substituted constant variable: r37414373 
o|substituted constant variable: r20004381 
o|contracted procedure: "(chicken-uninstall.scm:75) main#any" 
o|substituted constant variable: r19424320 
o|contracted procedure: "(chicken-uninstall.scm:192) main#every" 
o|replaced variables: 75 
o|removed binding forms: 383 
o|removed conditional forms: 1 
o|inlining procedure: k3839 
o|inlining procedure: k3967 
o|inlining procedure: k3132 
o|inlining procedure: k3967 
o|inlining procedure: k2979 
o|inlining procedure: k2991 
o|inlining procedure: "(chicken-uninstall.scm:161) main#usage" 
o|inlining procedure: "(chicken-uninstall.scm:169) main#usage" 
o|inlining procedure: "(chicken-uninstall.scm:195) main#usage" 
o|inlining procedure: "(chicken-uninstall.scm:196) main#usage" 
o|replaced variables: 6 
o|removed binding forms: 68 
o|removed side-effect free assignment to unused variable: main#usage 
o|substituted constant variable: r31334468 
o|substituted constant variable: r31334468 
o|substituted constant variable: code11384515 
o|substituted constant variable: code11384520 
o|substituted constant variable: code11384527 
o|inlining procedure: "(mini-srfi-1.scm:82) a4195" 
o|substituted constant variable: code11384534 
o|replaced variables: 6 
o|removed binding forms: 12 
o|removed conditional forms: 1 
o|replaced variables: 2 
o|removed binding forms: 14 
o|removed binding forms: 2 
o|simplifications: ((let . 15) (if . 15) (##core#call . 102)) 
o|  call simplifications:
o|    ##sys#size	2
o|    chicken.fixnum#fx>
o|    scheme#memq
o|    scheme#string
o|    scheme#equal?
o|    scheme#list	5
o|    ##sys#setslot	4
o|    scheme#string->list	2
o|    scheme#list->string
o|    scheme#char-whitespace?
o|    scheme#string=?	4
o|    scheme#eof-object?	2
o|    scheme#assq
o|    scheme#cdr
o|    scheme#not	5
o|    scheme#null?	11
o|    scheme#car	9
o|    scheme#eq?	4
o|    ##sys#check-list	5
o|    scheme#pair?	7
o|    ##sys#slot	21
o|    scheme#cons	13
o|contracted procedure: k2141 
o|contracted procedure: k2153 
o|contracted procedure: k2171 
o|contracted procedure: k2179 
o|contracted procedure: k4289 
o|contracted procedure: k2876 
o|contracted procedure: k3448 
o|contracted procedure: k3021 
o|contracted procedure: k3003 
o|contracted procedure: k3009 
o|contracted procedure: k3461 
o|contracted procedure: k3871 
o|contracted procedure: k3880 
o|contracted procedure: k3889 
o|contracted procedure: k4006 
o|contracted procedure: k3932 
o|contracted procedure: k3952 
o|contracted procedure: k3964 
o|contracted procedure: k3974 
o|contracted procedure: k3978 
o|contracted procedure: k3821 
o|contracted procedure: k3836 
o|contracted procedure: k3846 
o|contracted procedure: k3850 
o|contracted procedure: k38464461 
o|contracted procedure: k39744467 
o|contracted procedure: k3141 
o|contracted procedure: k3126 
o|contracted procedure: k3129 
o|contracted procedure: k3132 
o|contracted procedure: k3084 
o|contracted procedure: k3093 
o|contracted procedure: k39744474 
o|contracted procedure: k3650 
o|contracted procedure: k3743 
o|contracted procedure: k3769 
o|contracted procedure: k3749 
o|contracted procedure: k3667 
o|contracted procedure: k3682 
o|contracted procedure: k3686 
o|contracted procedure: k3694 
o|contracted procedure: k3706 
o|contracted procedure: k3709 
o|contracted procedure: k3712 
o|contracted procedure: k3720 
o|contracted procedure: k3728 
o|contracted procedure: k3482 
o|contracted procedure: k2105 
o|contracted procedure: k2108 
o|contracted procedure: k2118 
o|contracted procedure: k2030 
o|contracted procedure: k2056 
o|contracted procedure: k2036 
o|contracted procedure: k3501 
o|contracted procedure: k3517 
o|contracted procedure: k2002 
o|contracted procedure: k2009 
o|contracted procedure: k3529 
o|contracted procedure: k3532 
o|contracted procedure: k3535 
o|contracted procedure: k3543 
o|contracted procedure: k3551 
o|contracted procedure: k1944 
o|contracted procedure: k1959 
o|contracted procedure: k3578 
o|contracted procedure: k3581 
o|contracted procedure: k3584 
o|contracted procedure: k3592 
o|contracted procedure: k3600 
o|contracted procedure: k2976 
o|contracted procedure: k2988 
o|contracted procedure: k4022 
o|contracted procedure: k4028 
o|contracted procedure: k4034 
o|contracted procedure: k4107 
o|contracted procedure: k4224 
o|contracted procedure: k4119 
o|contracted procedure: k4209 
o|contracted procedure: k4125 
o|contracted procedure: k4145 
o|contracted procedure: k4164 
o|contracted procedure: k4186 
o|contracted procedure: k4182 
o|contracted procedure: k4167 
o|contracted procedure: k4170 
o|contracted procedure: k4178 
o|contracted procedure: k1907 
o|contracted procedure: k1929 
o|contracted procedure: k1925 
o|contracted procedure: k1916 
o|contracted procedure: k4220 
o|contracted procedure: k4303 
o|contracted procedure: k4307 
o|contracted procedure: k4311 
o|contracted procedure: k4315 
o|simplifications: ((let . 36)) 
o|removed binding forms: 95 
o|substituted constant variable: r4304 
o|substituted constant variable: r4308 
o|substituted constant variable: r4312 
o|substituted constant variable: r4316 
o|removed binding forms: 4 
o|direct leaf routine/allocation: a3566 0 
o|direct leaf routine/allocation: loop253 0 
o|contracted procedure: "(mini-srfi-1.scm:88) k1947" 
o|contracted procedure: k4134 
o|converted assignments to bindings: (loop253) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 2 
o|direct leaf routine/allocation: loop266 0 
o|converted assignments to bindings: (loop266) 
o|simplifications: ((let . 1)) 
o|customizable procedures: (k4037 map-loop11851210 loop1144 map-loop951968 g984993 map-loop978996 loop285 main#filter loop292 loop312 map-loop10191044 left1068 loop1051 main#repo-path k3804 for-each-loop10811092 main#delete-installed-file for-each-loop11201132 k3458 foldr329332 g334335) 
o|calls to known targets: 61 
o|identified direct recursive calls: f_2148 1 
o|identified direct recursive calls: f_3738 2 
o|identified direct recursive calls: f_2025 2 
o|identified direct recursive calls: f_1997 1 
o|identified direct recursive calls: f_1939 1 
o|identified direct recursive calls: f_1905 1 
o|identified direct recursive calls: f_4159 1 
o|fast box initializations: 13 
o|fast global references: 31 
o|fast global assignments: 26 
o|dropping unused closure argument: f_1905 
o|dropping unused closure argument: f_2139 
o|dropping unused closure argument: f_3452 
o|dropping unused closure argument: f_3866 
*/
/* end of file */
