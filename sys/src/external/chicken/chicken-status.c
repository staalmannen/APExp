/* Generated from chicken-status.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken-status.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -output-file chicken-status.c
   uses: eval data-structures pathname port irregex extras file library
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

static C_TLS C_word lf[146];
static double C_possibly_force_alignment;


C_noret_decl(f5319)
static void C_ccall f5319(C_word c,C_word *av) C_noret;
C_noret_decl(f5326)
static void C_ccall f5326(C_word c,C_word *av) C_noret;
C_noret_decl(f5333)
static void C_ccall f5333(C_word c,C_word *av) C_noret;
C_noret_decl(f_1674)
static void C_ccall f_1674(C_word c,C_word *av) C_noret;
C_noret_decl(f_1677)
static void C_ccall f_1677(C_word c,C_word *av) C_noret;
C_noret_decl(f_1680)
static void C_ccall f_1680(C_word c,C_word *av) C_noret;
C_noret_decl(f_1683)
static void C_ccall f_1683(C_word c,C_word *av) C_noret;
C_noret_decl(f_1686)
static void C_ccall f_1686(C_word c,C_word *av) C_noret;
C_noret_decl(f_1689)
static void C_ccall f_1689(C_word c,C_word *av) C_noret;
C_noret_decl(f_1692)
static void C_ccall f_1692(C_word c,C_word *av) C_noret;
C_noret_decl(f_1695)
static void C_ccall f_1695(C_word c,C_word *av) C_noret;
C_noret_decl(f_1698)
static void C_ccall f_1698(C_word c,C_word *av) C_noret;
C_noret_decl(f_1899)
static void C_fcall f_1899(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1914)
static void C_fcall f_1914(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1922)
static void C_fcall f_1922(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1930)
static void C_ccall f_1930(C_word c,C_word *av) C_noret;
C_noret_decl(f_1941)
static void C_ccall f_1941(C_word c,C_word *av) C_noret;
C_noret_decl(f_1954)
static void C_fcall f_1954(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1961)
static void C_ccall f_1961(C_word c,C_word *av) C_noret;
C_noret_decl(f_1968)
static void C_ccall f_1968(C_word c,C_word *av) C_noret;
C_noret_decl(f_1972)
static void C_ccall f_1972(C_word c,C_word *av) C_noret;
C_noret_decl(f_1984)
static void C_ccall f_1984(C_word c,C_word *av) C_noret;
C_noret_decl(f_1986)
static void C_fcall f_1986(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2033)
static void C_ccall f_2033(C_word c,C_word *av) C_noret;
C_noret_decl(f_2035)
static void C_fcall f_2035(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2075)
static C_word C_fcall f_2075(C_word t0);
C_noret_decl(f_2103)
static void C_fcall f_2103(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2109)
static void C_fcall f_2109(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2119)
static void C_ccall f_2119(C_word c,C_word *av) C_noret;
C_noret_decl(f_2167)
static void C_fcall f_2167(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2185)
static void C_ccall f_2185(C_word c,C_word *av) C_noret;
C_noret_decl(f_2195)
static void C_fcall f_2195(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2208)
static void C_ccall f_2208(C_word c,C_word *av) C_noret;
C_noret_decl(f_2222)
static void C_ccall f_2222(C_word c,C_word *av) C_noret;
C_noret_decl(f_2264)
static void C_fcall f_2264(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2270)
static void C_fcall f_2270(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2284)
static void C_ccall f_2284(C_word c,C_word *av) C_noret;
C_noret_decl(f_2297)
static void C_ccall f_2297(C_word c,C_word *av) C_noret;
C_noret_decl(f_2309)
static void C_fcall f_2309(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2318)
static void C_fcall f_2318(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2326)
static void C_fcall f_2326(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2333)
static void C_ccall f_2333(C_word c,C_word *av) C_noret;
C_noret_decl(f_2347)
static void C_ccall f_2347(C_word c,C_word *av) C_noret;
C_noret_decl(f_2982)
static void C_ccall f_2982(C_word c,C_word *av) C_noret;
C_noret_decl(f_2988)
static void C_ccall f_2988(C_word c,C_word *av) C_noret;
C_noret_decl(f_2992)
static void C_ccall f_2992(C_word c,C_word *av) C_noret;
C_noret_decl(f_2996)
static void C_ccall f_2996(C_word c,C_word *av) C_noret;
C_noret_decl(f_3000)
static void C_ccall f_3000(C_word c,C_word *av) C_noret;
C_noret_decl(f_3004)
static void C_ccall f_3004(C_word c,C_word *av) C_noret;
C_noret_decl(f_3008)
static void C_ccall f_3008(C_word c,C_word *av) C_noret;
C_noret_decl(f_3012)
static void C_ccall f_3012(C_word c,C_word *av) C_noret;
C_noret_decl(f_3016)
static void C_ccall f_3016(C_word c,C_word *av) C_noret;
C_noret_decl(f_3020)
static void C_ccall f_3020(C_word c,C_word *av) C_noret;
C_noret_decl(f_3024)
static void C_ccall f_3024(C_word c,C_word *av) C_noret;
C_noret_decl(f_3028)
static void C_ccall f_3028(C_word c,C_word *av) C_noret;
C_noret_decl(f_3032)
static void C_ccall f_3032(C_word c,C_word *av) C_noret;
C_noret_decl(f_3036)
static void C_ccall f_3036(C_word c,C_word *av) C_noret;
C_noret_decl(f_3040)
static void C_ccall f_3040(C_word c,C_word *av) C_noret;
C_noret_decl(f_3044)
static void C_ccall f_3044(C_word c,C_word *av) C_noret;
C_noret_decl(f_3052)
static void C_ccall f_3052(C_word c,C_word *av) C_noret;
C_noret_decl(f_3056)
static void C_ccall f_3056(C_word c,C_word *av) C_noret;
C_noret_decl(f_3060)
static void C_ccall f_3060(C_word c,C_word *av) C_noret;
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
C_noret_decl(f_3084)
static void C_ccall f_3084(C_word c,C_word *av) C_noret;
C_noret_decl(f_3088)
static void C_ccall f_3088(C_word c,C_word *av) C_noret;
C_noret_decl(f_3092)
static void C_ccall f_3092(C_word c,C_word *av) C_noret;
C_noret_decl(f_3096)
static void C_ccall f_3096(C_word c,C_word *av) C_noret;
C_noret_decl(f_3100)
static void C_ccall f_3100(C_word c,C_word *av) C_noret;
C_noret_decl(f_3104)
static void C_ccall f_3104(C_word c,C_word *av) C_noret;
C_noret_decl(f_3108)
static void C_ccall f_3108(C_word c,C_word *av) C_noret;
C_noret_decl(f_3112)
static void C_ccall f_3112(C_word c,C_word *av) C_noret;
C_noret_decl(f_3116)
static void C_ccall f_3116(C_word c,C_word *av) C_noret;
C_noret_decl(f_3120)
static void C_ccall f_3120(C_word c,C_word *av) C_noret;
C_noret_decl(f_3124)
static void C_ccall f_3124(C_word c,C_word *av) C_noret;
C_noret_decl(f_3128)
static void C_ccall f_3128(C_word c,C_word *av) C_noret;
C_noret_decl(f_3212)
static void C_ccall f_3212(C_word c,C_word *av) C_noret;
C_noret_decl(f_3215)
static void C_ccall f_3215(C_word c,C_word *av) C_noret;
C_noret_decl(f_3219)
static void C_ccall f_3219(C_word c,C_word *av) C_noret;
C_noret_decl(f_3228)
static void C_ccall f_3228(C_word c,C_word *av) C_noret;
C_noret_decl(f_3234)
static void C_ccall f_3234(C_word c,C_word *av) C_noret;
C_noret_decl(f_3238)
static void C_ccall f_3238(C_word c,C_word *av) C_noret;
C_noret_decl(f_3242)
static void C_ccall f_3242(C_word c,C_word *av) C_noret;
C_noret_decl(f_3246)
static void C_ccall f_3246(C_word c,C_word *av) C_noret;
C_noret_decl(f_3250)
static void C_ccall f_3250(C_word c,C_word *av) C_noret;
C_noret_decl(f_3259)
static void C_ccall f_3259(C_word c,C_word *av) C_noret;
C_noret_decl(f_3270)
static C_word C_fcall f_3270(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_3294)
static C_word C_fcall f_3294(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_3613)
static void C_fcall f_3613(C_word t0) C_noret;
C_noret_decl(f_3620)
static void C_ccall f_3620(C_word c,C_word *av) C_noret;
C_noret_decl(f_3623)
static void C_ccall f_3623(C_word c,C_word *av) C_noret;
C_noret_decl(f_3626)
static void C_ccall f_3626(C_word c,C_word *av) C_noret;
C_noret_decl(f_3635)
static void C_ccall f_3635(C_word c,C_word *av) C_noret;
C_noret_decl(f_3641)
static void C_ccall f_3641(C_word c,C_word *av) C_noret;
C_noret_decl(f_3647)
static void C_ccall f_3647(C_word c,C_word *av) C_noret;
C_noret_decl(f_3650)
static void C_ccall f_3650(C_word c,C_word *av) C_noret;
C_noret_decl(f_3656)
static void C_ccall f_3656(C_word c,C_word *av) C_noret;
C_noret_decl(f_3662)
static void C_ccall f_3662(C_word c,C_word *av) C_noret;
C_noret_decl(f_3668)
static void C_ccall f_3668(C_word c,C_word *av) C_noret;
C_noret_decl(f_3674)
static void C_ccall f_3674(C_word c,C_word *av) C_noret;
C_noret_decl(f_3680)
static void C_ccall f_3680(C_word c,C_word *av) C_noret;
C_noret_decl(f_3690)
static void C_fcall f_3690(C_word t0) C_noret;
C_noret_decl(f_3718)
static void C_ccall f_3718(C_word c,C_word *av) C_noret;
C_noret_decl(f_3724)
static void C_fcall f_3724(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3728)
static void C_ccall f_3728(C_word c,C_word *av) C_noret;
C_noret_decl(f_3740)
static void C_ccall f_3740(C_word c,C_word *av) C_noret;
C_noret_decl(f_3750)
static void C_ccall f_3750(C_word c,C_word *av) C_noret;
C_noret_decl(f_3779)
static void C_fcall f_3779(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3783)
static void C_ccall f_3783(C_word c,C_word *av) C_noret;
C_noret_decl(f_3800)
static void C_fcall f_3800(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3808)
static void C_ccall f_3808(C_word c,C_word *av) C_noret;
C_noret_decl(f_3812)
static void C_ccall f_3812(C_word c,C_word *av) C_noret;
C_noret_decl(f_3818)
static void C_ccall f_3818(C_word c,C_word *av) C_noret;
C_noret_decl(f_3820)
static void C_fcall f_3820(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3845)
static void C_ccall f_3845(C_word c,C_word *av) C_noret;
C_noret_decl(f_3857)
static void C_ccall f_3857(C_word c,C_word *av) C_noret;
C_noret_decl(f_3863)
static void C_ccall f_3863(C_word c,C_word *av) C_noret;
C_noret_decl(f_3877)
static void C_ccall f_3877(C_word c,C_word *av) C_noret;
C_noret_decl(f_3879)
static void C_ccall f_3879(C_word c,C_word *av) C_noret;
C_noret_decl(f_3886)
static void C_ccall f_3886(C_word c,C_word *av) C_noret;
C_noret_decl(f_3891)
static void C_fcall f_3891(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3916)
static void C_ccall f_3916(C_word c,C_word *av) C_noret;
C_noret_decl(f_3927)
static void C_ccall f_3927(C_word c,C_word *av) C_noret;
C_noret_decl(f_3931)
static void C_ccall f_3931(C_word c,C_word *av) C_noret;
C_noret_decl(f_3933)
static void C_fcall f_3933(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3952)
static void C_ccall f_3952(C_word c,C_word *av) C_noret;
C_noret_decl(f_3999)
static void C_ccall f_3999(C_word c,C_word *av) C_noret;
C_noret_decl(f_4003)
static void C_ccall f_4003(C_word c,C_word *av) C_noret;
C_noret_decl(f_4013)
static void C_fcall f_4013(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4020)
static void C_ccall f_4020(C_word c,C_word *av) C_noret;
C_noret_decl(f_4028)
static void C_fcall f_4028(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4038)
static void C_ccall f_4038(C_word c,C_word *av) C_noret;
C_noret_decl(f_4078)
static void C_ccall f_4078(C_word c,C_word *av) C_noret;
C_noret_decl(f_4082)
static void C_ccall f_4082(C_word c,C_word *av) C_noret;
C_noret_decl(f_4088)
static void C_fcall f_4088(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4095)
static void C_ccall f_4095(C_word c,C_word *av) C_noret;
C_noret_decl(f_4099)
static void C_ccall f_4099(C_word c,C_word *av) C_noret;
C_noret_decl(f_4103)
static void C_ccall f_4103(C_word c,C_word *av) C_noret;
C_noret_decl(f_4108)
static void C_ccall f_4108(C_word c,C_word *av) C_noret;
C_noret_decl(f_4112)
static void C_ccall f_4112(C_word c,C_word *av) C_noret;
C_noret_decl(f_4115)
static void C_ccall f_4115(C_word c,C_word *av) C_noret;
C_noret_decl(f_4118)
static void C_ccall f_4118(C_word c,C_word *av) C_noret;
C_noret_decl(f_4128)
static void C_ccall f_4128(C_word c,C_word *av) C_noret;
C_noret_decl(f_4144)
static void C_ccall f_4144(C_word c,C_word *av) C_noret;
C_noret_decl(f_4153)
static void C_ccall f_4153(C_word c,C_word *av) C_noret;
C_noret_decl(f_4156)
static void C_ccall f_4156(C_word c,C_word *av) C_noret;
C_noret_decl(f_4164)
static void C_fcall f_4164(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4174)
static void C_ccall f_4174(C_word c,C_word *av) C_noret;
C_noret_decl(f_4189)
static void C_ccall f_4189(C_word c,C_word *av) C_noret;
C_noret_decl(f_4193)
static void C_ccall f_4193(C_word c,C_word *av) C_noret;
C_noret_decl(f_4195)
static void C_fcall f_4195(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4201)
static void C_ccall f_4201(C_word c,C_word *av) C_noret;
C_noret_decl(f_4207)
static void C_ccall f_4207(C_word c,C_word *av) C_noret;
C_noret_decl(f_4378)
static void C_ccall f_4378(C_word c,C_word *av) C_noret;
C_noret_decl(f_4383)
static void C_fcall f_4383(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4387)
static void C_ccall f_4387(C_word c,C_word *av) C_noret;
C_noret_decl(f_4396)
static void C_ccall f_4396(C_word c,C_word *av) C_noret;
C_noret_decl(f_4402)
static void C_ccall f_4402(C_word c,C_word *av) C_noret;
C_noret_decl(f_4411)
static void C_ccall f_4411(C_word c,C_word *av) C_noret;
C_noret_decl(f_4415)
static void C_ccall f_4415(C_word c,C_word *av) C_noret;
C_noret_decl(f_4439)
static void C_ccall f_4439(C_word c,C_word *av) C_noret;
C_noret_decl(f_4447)
static void C_ccall f_4447(C_word c,C_word *av) C_noret;
C_noret_decl(f_4459)
static void C_fcall f_4459(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4469)
static void C_ccall f_4469(C_word c,C_word *av) C_noret;
C_noret_decl(f_4487)
static void C_ccall f_4487(C_word c,C_word *av) C_noret;
C_noret_decl(f_4491)
static void C_ccall f_4491(C_word c,C_word *av) C_noret;
C_noret_decl(f_4495)
static void C_ccall f_4495(C_word c,C_word *av) C_noret;
C_noret_decl(f_4500)
static void C_ccall f_4500(C_word c,C_word *av) C_noret;
C_noret_decl(f_4504)
static void C_ccall f_4504(C_word c,C_word *av) C_noret;
C_noret_decl(f_4515)
static void C_fcall f_4515(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4525)
static void C_ccall f_4525(C_word c,C_word *av) C_noret;
C_noret_decl(f_4544)
static void C_ccall f_4544(C_word c,C_word *av) C_noret;
C_noret_decl(f_4546)
static void C_ccall f_4546(C_word c,C_word *av) C_noret;
C_noret_decl(f_4550)
static void C_ccall f_4550(C_word c,C_word *av) C_noret;
C_noret_decl(f_4558)
static void C_fcall f_4558(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4568)
static void C_ccall f_4568(C_word c,C_word *av) C_noret;
C_noret_decl(f_4583)
static void C_ccall f_4583(C_word c,C_word *av) C_noret;
C_noret_decl(f_4585)
static void C_ccall f_4585(C_word c,C_word *av) C_noret;
C_noret_decl(f_4593)
static void C_ccall f_4593(C_word c,C_word *av) C_noret;
C_noret_decl(f_4595)
static void C_ccall f_4595(C_word c,C_word *av) C_noret;
C_noret_decl(f_4612)
static void C_ccall f_4612(C_word c,C_word *av) C_noret;
C_noret_decl(f_4623)
static void C_ccall f_4623(C_word c,C_word *av) C_noret;
C_noret_decl(f_4631)
static void C_fcall f_4631(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4641)
static void C_ccall f_4641(C_word c,C_word *av) C_noret;
C_noret_decl(f_4670)
static void C_fcall f_4670(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4683)
static void C_fcall f_4683(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4686)
static void C_ccall f_4686(C_word c,C_word *av) C_noret;
C_noret_decl(f_4691)
static void C_ccall f_4691(C_word c,C_word *av) C_noret;
C_noret_decl(f_4704)
static void C_fcall f_4704(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4711)
static void C_ccall f_4711(C_word c,C_word *av) C_noret;
C_noret_decl(f_4715)
static void C_ccall f_4715(C_word c,C_word *av) C_noret;
C_noret_decl(f_4828)
static void C_ccall f_4828(C_word c,C_word *av) C_noret;
C_noret_decl(f_4835)
static void C_ccall f_4835(C_word c,C_word *av) C_noret;
C_noret_decl(f_4850)
static void C_ccall f_4850(C_word c,C_word *av) C_noret;
C_noret_decl(f_4863)
static void C_ccall f_4863(C_word c,C_word *av) C_noret;
C_noret_decl(f_4875)
static void C_ccall f_4875(C_word c,C_word *av) C_noret;
C_noret_decl(f_4879)
static void C_fcall f_4879(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4924)
static void C_ccall f_4924(C_word c,C_word *av) C_noret;
C_noret_decl(f_4958)
static void C_ccall f_4958(C_word c,C_word *av) C_noret;
C_noret_decl(f_4964)
static void C_ccall f_4964(C_word c,C_word *av) C_noret;
C_noret_decl(f_4968)
static void C_ccall f_4968(C_word c,C_word *av) C_noret;
C_noret_decl(f_4976)
static void C_ccall f_4976(C_word c,C_word *av) C_noret;
C_noret_decl(f_4983)
static void C_ccall f_4983(C_word c,C_word *av) C_noret;
C_noret_decl(f_4986)
static void C_ccall f_4986(C_word c,C_word *av) C_noret;
C_noret_decl(f_4993)
static void C_ccall f_4993(C_word c,C_word *av) C_noret;
C_noret_decl(f_4998)
static void C_ccall f_4998(C_word c,C_word *av) C_noret;
C_noret_decl(f_5003)
static void C_ccall f_5003(C_word c,C_word *av) C_noret;
C_noret_decl(f_5007)
static void C_ccall f_5007(C_word c,C_word *av) C_noret;
C_noret_decl(f_5011)
static void C_ccall f_5011(C_word c,C_word *av) C_noret;
C_noret_decl(f_5018)
static void C_ccall f_5018(C_word c,C_word *av) C_noret;
C_noret_decl(f_5020)
static void C_ccall f_5020(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1899)
static void C_ccall trf_1899(C_word c,C_word *av) C_noret;
static void C_ccall trf_1899(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1899(t0,t1,t2,t3);}

C_noret_decl(trf_1914)
static void C_ccall trf_1914(C_word c,C_word *av) C_noret;
static void C_ccall trf_1914(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1914(t0,t1,t2);}

C_noret_decl(trf_1922)
static void C_ccall trf_1922(C_word c,C_word *av) C_noret;
static void C_ccall trf_1922(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1922(t0,t1,t2,t3);}

C_noret_decl(trf_1954)
static void C_ccall trf_1954(C_word c,C_word *av) C_noret;
static void C_ccall trf_1954(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1954(t0,t1,t2);}

C_noret_decl(trf_1986)
static void C_ccall trf_1986(C_word c,C_word *av) C_noret;
static void C_ccall trf_1986(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1986(t0,t1,t2);}

C_noret_decl(trf_2035)
static void C_ccall trf_2035(C_word c,C_word *av) C_noret;
static void C_ccall trf_2035(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2035(t0,t1,t2);}

C_noret_decl(trf_2103)
static void C_ccall trf_2103(C_word c,C_word *av) C_noret;
static void C_ccall trf_2103(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2103(t0,t1,t2);}

C_noret_decl(trf_2109)
static void C_ccall trf_2109(C_word c,C_word *av) C_noret;
static void C_ccall trf_2109(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2109(t0,t1,t2);}

C_noret_decl(trf_2167)
static void C_ccall trf_2167(C_word c,C_word *av) C_noret;
static void C_ccall trf_2167(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2167(t0,t1,t2);}

C_noret_decl(trf_2195)
static void C_ccall trf_2195(C_word c,C_word *av) C_noret;
static void C_ccall trf_2195(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2195(t0,t1,t2);}

C_noret_decl(trf_2264)
static void C_ccall trf_2264(C_word c,C_word *av) C_noret;
static void C_ccall trf_2264(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2264(t0,t1,t2);}

C_noret_decl(trf_2270)
static void C_ccall trf_2270(C_word c,C_word *av) C_noret;
static void C_ccall trf_2270(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2270(t0,t1,t2);}

C_noret_decl(trf_2309)
static void C_ccall trf_2309(C_word c,C_word *av) C_noret;
static void C_ccall trf_2309(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2309(t0,t1,t2);}

C_noret_decl(trf_2318)
static void C_ccall trf_2318(C_word c,C_word *av) C_noret;
static void C_ccall trf_2318(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2318(t0,t1,t2);}

C_noret_decl(trf_2326)
static void C_ccall trf_2326(C_word c,C_word *av) C_noret;
static void C_ccall trf_2326(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2326(t0,t1,t2,t3);}

C_noret_decl(trf_3613)
static void C_ccall trf_3613(C_word c,C_word *av) C_noret;
static void C_ccall trf_3613(C_word c,C_word *av){
C_word t0=av[0];
f_3613(t0);}

C_noret_decl(trf_3690)
static void C_ccall trf_3690(C_word c,C_word *av) C_noret;
static void C_ccall trf_3690(C_word c,C_word *av){
C_word t0=av[0];
f_3690(t0);}

C_noret_decl(trf_3724)
static void C_ccall trf_3724(C_word c,C_word *av) C_noret;
static void C_ccall trf_3724(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3724(t0,t1,t2);}

C_noret_decl(trf_3779)
static void C_ccall trf_3779(C_word c,C_word *av) C_noret;
static void C_ccall trf_3779(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3779(t0,t1,t2,t3);}

C_noret_decl(trf_3800)
static void C_ccall trf_3800(C_word c,C_word *av) C_noret;
static void C_ccall trf_3800(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3800(t0,t1,t2);}

C_noret_decl(trf_3820)
static void C_ccall trf_3820(C_word c,C_word *av) C_noret;
static void C_ccall trf_3820(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3820(t0,t1,t2);}

C_noret_decl(trf_3891)
static void C_ccall trf_3891(C_word c,C_word *av) C_noret;
static void C_ccall trf_3891(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3891(t0,t1,t2);}

C_noret_decl(trf_3933)
static void C_ccall trf_3933(C_word c,C_word *av) C_noret;
static void C_ccall trf_3933(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3933(t0,t1,t2,t3);}

C_noret_decl(trf_4013)
static void C_ccall trf_4013(C_word c,C_word *av) C_noret;
static void C_ccall trf_4013(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4013(t0,t1,t2);}

C_noret_decl(trf_4028)
static void C_ccall trf_4028(C_word c,C_word *av) C_noret;
static void C_ccall trf_4028(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4028(t0,t1,t2);}

C_noret_decl(trf_4088)
static void C_ccall trf_4088(C_word c,C_word *av) C_noret;
static void C_ccall trf_4088(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4088(t0,t1);}

C_noret_decl(trf_4164)
static void C_ccall trf_4164(C_word c,C_word *av) C_noret;
static void C_ccall trf_4164(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4164(t0,t1,t2);}

C_noret_decl(trf_4195)
static void C_ccall trf_4195(C_word c,C_word *av) C_noret;
static void C_ccall trf_4195(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4195(t0,t1,t2);}

C_noret_decl(trf_4383)
static void C_ccall trf_4383(C_word c,C_word *av) C_noret;
static void C_ccall trf_4383(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4383(t0,t1,t2);}

C_noret_decl(trf_4459)
static void C_ccall trf_4459(C_word c,C_word *av) C_noret;
static void C_ccall trf_4459(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4459(t0,t1,t2);}

C_noret_decl(trf_4515)
static void C_ccall trf_4515(C_word c,C_word *av) C_noret;
static void C_ccall trf_4515(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4515(t0,t1,t2);}

C_noret_decl(trf_4558)
static void C_ccall trf_4558(C_word c,C_word *av) C_noret;
static void C_ccall trf_4558(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4558(t0,t1,t2);}

C_noret_decl(trf_4631)
static void C_ccall trf_4631(C_word c,C_word *av) C_noret;
static void C_ccall trf_4631(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4631(t0,t1,t2);}

C_noret_decl(trf_4670)
static void C_ccall trf_4670(C_word c,C_word *av) C_noret;
static void C_ccall trf_4670(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4670(t0,t1,t2,t3);}

C_noret_decl(trf_4683)
static void C_ccall trf_4683(C_word c,C_word *av) C_noret;
static void C_ccall trf_4683(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4683(t0,t1);}

C_noret_decl(trf_4704)
static void C_ccall trf_4704(C_word c,C_word *av) C_noret;
static void C_ccall trf_4704(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4704(t0,t1);}

C_noret_decl(trf_4879)
static void C_ccall trf_4879(C_word c,C_word *av) C_noret;
static void C_ccall trf_4879(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4879(t0,t1,t2);}

/* f5319 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f5319(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f5319,c,av);}
/* chicken-status.scm:210: chicken.base#exit */
t2=C_fast_retrieve(lf[100]);{
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

/* f5326 in k4848 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f5326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f5326,c,av);}
/* chicken-status.scm:210: chicken.base#exit */
t2=C_fast_retrieve(lf[100]);{
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

/* f5333 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f5333(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f5333,c,av);}
/* chicken-status.scm:210: chicken.base#exit */
t2=C_fast_retrieve(lf[100]);{
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

/* k1672 */
static void C_ccall f_1674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1674,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1677,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k1675 in k1672 */
static void C_ccall f_1677(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1677,c,av);}
a=C_alloc(13);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1680,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5020,tmp=(C_word)a,a+=2,tmp);
/* chicken-status.scm:26: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[145]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[145]+1);
av2[1]=t3;
av2[2]=t4;
tp(3,av2);}}

/* k1678 in k1675 in k1672 */
static void C_ccall f_1680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1680,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1683,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1683,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1686,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1686,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1689,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_irregex_toplevel(2,av2);}}

/* k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1689,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1692,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

/* k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1692,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1695,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1695,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1698,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1698(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_1698,c,av);}
a=C_alloc(11);
t2=C_mutate(&lf[1] /* (set! main#append-map ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_1899,tmp=(C_word)a,a+=2,tmp));
t3=C_mutate(&lf[5] /* (set! main#any ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2103,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate(&lf[7] /* (set! main#delete-duplicates ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2264,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate(&lf[8] /* (set! main#filter ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2309,tmp=(C_word)a,a+=2,tmp));
t6=C_mutate(&lf[9] /* (set! main#staticbuild ...) */,C_mk_bool(STATIC_CHICKEN));
t7=C_mutate(&lf[10] /* (set! main#debugbuild ...) */,C_mk_bool(DEBUG_CHICKEN));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2982,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:43: chicken.platform#feature? */
t9=C_fast_retrieve(lf[141]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[142];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_1899(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_1899,4,t1,t2,t3,t4);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t4))){
t5=C_i_check_list_2(t3,lf[2]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1914,a[2]=t2,a[3]=t7,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_1914(t9,t1,t3);}
else{
t5=C_a_i_cons(&a,2,t3,t4);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1954,a[2]=t7,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_1954(t9,t1,t5);}}

/* foldr192 in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_1914(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1914,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1922,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1941,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g197 in foldr192 in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_1922(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_1922,4,t0,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1930,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:72: proc */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k1928 in g197 in foldr192 in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1930,c,av);}
/* mini-srfi-1.scm:72: scheme#append */
t2=*((C_word*)lf[3]+1);{
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

/* k1939 in foldr192 in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1941(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1941,c,av);}
/* mini-srfi-1.scm:72: g197 */
t2=((C_word*)t0)[2];
f_1922(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_1954(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_1954,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1961,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* mini-srfi-1.scm:74: any */
f_2103(t3,*((C_word*)lf[6]+1),t2);}

/* k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1961(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_1961,c,av);}
a=C_alloc(21);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1968,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[4]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2033,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2035,a[2]=t5,a[3]=t10,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t12=((C_word*)t10)[1];
f_2035(t12,t8,((C_word*)t0)[4]);}}

/* k1966 in k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1968(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_1968,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1972,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1984,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1986,a[2]=t5,a[3]=t9,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_1986(t11,t7,((C_word*)t0)[4]);}

/* k1970 in k1966 in k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1972(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1972,c,av);}
/* mini-srfi-1.scm:76: scheme#append */
t2=*((C_word*)lf[3]+1);{
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

/* k1982 in k1966 in k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_1984(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1984,c,av);}
/* mini-srfi-1.scm:77: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1954(t2,((C_word*)t0)[3],t1);}

/* map-loop234 in k1966 in k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_1986(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1986,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_cdr(t3);
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

/* k2031 in k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2033,c,av);}{
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
C_apply(4,av2);}}

/* map-loop207 in k1959 in loop in main#append-map in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2035(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_2035,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
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

/* loop in k4848 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static C_word C_fcall f_2075(C_word t1){
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
t4=C_i_memq(t3,lf[125]);
if(C_truep(C_i_not(t4))){
return(C_SCHEME_FALSE);}
else{
t6=C_u_i_cdr(t1);
t1=t6;
goto loop;}}}

/* main#any in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2103(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2103,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2109,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_2109(t7,t1,t3);}

/* loop in main#any in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2109(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2109,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2119,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:88: pred */
t4=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(t2);
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}}

/* k2117 in loop in main#any in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2119,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* mini-srfi-1.scm:89: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_2109(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[4]));}}

/* loop in k3816 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_2167(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_2167,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2185,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:101: loop */
t6=t4;
t7=C_u_i_cdr(t2);
t1=t6;
t2=t7;
goto loop;}}

/* k2183 in loop in k3816 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_2185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2185,c,av);}
/* mini-srfi-1.scm:101: scheme#append */
t2=*((C_word*)lf[3]+1);{
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

/* loop in loop in main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2195(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_2195,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2208,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:106: test */
t4=((C_word*)t0)[3];{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=C_i_car(t2);
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}

/* k2206 in loop in loop in main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2208,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
/* mini-srfi-1.scm:107: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2195(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t2=C_u_i_car(((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2222,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:109: loop */
t4=((C_word*)((C_word*)t0)[2])[1];
f_2195(t4,t3,C_u_i_cdr(((C_word*)t0)[4]));}}

/* k2220 in k2206 in loop in loop in main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2222,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2264(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2264,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2270,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_2270(t7,t1,t2);}

/* loop in main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2270(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_2270,3,t0,t1,t2);}
a=C_alloc(17);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2284,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2297,a[2]=((C_word*)t0)[2],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2195,a[2]=t8,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_2195(t10,t6,t4);}}

/* k2282 in loop in main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2284,c,av);}
a=C_alloc(3);
t2=C_i_equalp(((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?((C_word*)t0)[4]:C_a_i_cons(&a,2,((C_word*)t0)[5],t1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2295 in loop in main#delete-duplicates in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2297(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2297,c,av);}
/* mini-srfi-1.scm:123: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2270(t2,((C_word*)t0)[3],t1);}

/* main#filter in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2309(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2309,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_check_list_2(t3,lf[2]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2318,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_2318(t8,t1,t3);}

/* foldr339 in main#filter in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2318(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_2318,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2326,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2347,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g344 in foldr339 in main#filter in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_fcall f_2326(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2326,4,t0,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2333,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:131: pred */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k2331 in g344 in foldr339 in main#filter in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2333(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2333,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]):((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2345 in foldr339 in main#filter in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2347,c,av);}
/* mini-srfi-1.scm:131: g344 */
t2=((C_word*)t0)[2];
f_2326(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2982(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2982,c,av);}
a=C_alloc(6);
t2=lf[11] /* main#cross-chicken */ =t1;;
t3=lf[12] /* main#binary-version */ =C_fix((C_word)C_BINARY_VERSION);;
t4=lf[13] /* main#major-version */ =C_fix((C_word)C_MAJOR_VERSION);;
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2988,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[137]+1);{
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

/* k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2988(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2988,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[14] /* (set! main#chicken-install-program ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2992,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[137]+1);{
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

/* k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2992,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2996,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_2996(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2996,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3000,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3000(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3000,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3004,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3004,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3008,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3008,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3012,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3012,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3016,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3016(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3016,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3020,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3020,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3024,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3024(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3024,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[15] /* (set! main#default-libdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3028,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[137]+1);{
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

/* k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 */
static void C_ccall f_3028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3028,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[16] /* (set! main#default-runlibdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3032,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[137]+1);{
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

/* k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in k1672 in ... */
static void C_ccall f_3032(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3032,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3036,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in k1675 in ... */
static void C_ccall f_3036(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3036,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3040,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in k1678 in ... */
static void C_ccall f_3040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3040,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[17] /* (set! main#default-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3044,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[137]+1);{
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

/* k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in k1681 in ... */
static void C_ccall f_3044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3044,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5018,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:64: chicken.platform#software-type */
t3=C_fast_retrieve(lf[140]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_3052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3052,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3056,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3056(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3056,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[17] /* (set! main#default-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3060,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5011,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t5=*((C_word*)lf[137]+1);{
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

/* k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in ... */
static void C_ccall f_3060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3060,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3064,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5007,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[137]+1);{
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

/* k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in ... */
static void C_ccall f_3064(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3064,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3068,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5003,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[137]+1);{
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

/* k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in ... */
static void C_ccall f_3068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3068,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3072,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in ... */
static void C_ccall f_3072(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3072,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3076,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in ... */
static void C_ccall f_3076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3076,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3080,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in ... */
static void C_ccall f_3080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3080,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3084,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in ... */
static void C_ccall f_3084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3084,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3088,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LIB_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in ... */
static void C_ccall f_3088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3088,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3092,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in ... */
static void C_ccall f_3092(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3092,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3096,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in ... */
static void C_ccall f_3096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3096,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3100,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in ... */
static void C_ccall f_3100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3100,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3104,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in ... */
static void C_ccall f_3104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3104,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3108,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in ... */
static void C_ccall f_3108(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3108,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3112,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in ... */
static void C_ccall f_3112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3112,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3116,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in ... */
static void C_ccall f_3116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3116,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3120,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[137]+1);{
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

/* k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in ... */
static void C_ccall f_3120(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3120,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3124,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4998,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_retrieve2(lf[12],C_text("main#binary-version"));
/* ##sys#fixnum->string */
t5=C_fast_retrieve(lf[135]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=C_retrieve2(lf[12],C_text("main#binary-version"));
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in ... */
static void C_ccall f_3124(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3124,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[20] /* (set! main#target-repo ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3128,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4993,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_retrieve2(lf[12],C_text("main#binary-version"));
/* ##sys#fixnum->string */
t6=C_fast_retrieve(lf[135]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=C_retrieve2(lf[12],C_text("main#binary-version"));
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in ... */
static void C_ccall f_3128(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3128,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[21] /* (set! main#target-run-repo ...) */,t1);
t3=C_mutate(&lf[22] /* (set! main#+egg-info-extension+ ...) */,lf[23]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3212,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:122: chicken.process-context#get-environment-variable */
t5=C_fast_retrieve(lf[132]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[133];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in ... */
static void C_ccall f_3212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3212,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3215,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_3215(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4983,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:123: chicken.platform#system-cache-directory */
t4=C_fast_retrieve(lf[131]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in ... */
static void C_ccall f_3215(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3215,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[24] /* (set! main#cache-directory ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3219,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:130: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[24],C_text("main#cache-directory"));
av2[3]=lf[129];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in ... */
static void C_ccall f_3219(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_3219,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[25] /* (set! main#cache-metadata-directory ...) */,t1);
t3=C_mutate(&lf[26] /* (set! main#get-egg-property ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3270,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate(&lf[27] /* (set! main#get-egg-property* ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3294,tmp=(C_word)a,a+=2,tmp));
t5=lf[28] /* main#host-extensions */ =C_SCHEME_TRUE;;
t6=lf[29] /* main#target-extensions */ =C_SCHEME_TRUE;;
t7=C_mutate(&lf[30] /* (set! main#get-terminal-width ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3613,tmp=(C_word)a,a+=2,tmp));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4976,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:62: get-terminal-width */
f_3613(t8);}

/* k3226 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3228,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3234,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* egg-information.scm:34: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[46]);{
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

/* k3232 in k3226 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3234(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3234,c,av);}
a=C_alloc(4);
t2=(C_truep(t1)?((C_word*)t0)[2]:((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3259,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* egg-information.scm:38: scheme#with-input-from-file */
t4=C_fast_retrieve(lf[44]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=*((C_word*)lf[45]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3236 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3238(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3238,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3242,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* egg-information.scm:32: chicken.pathname#pathname-file */
t3=C_fast_retrieve(lf[49]);{
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

/* k3240 in k3236 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3242,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3246,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* egg-information.scm:33: chicken.pathname#pathname-extension */
t3=C_fast_retrieve(lf[48]);{
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

/* k3244 in k3240 in k3236 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_3246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3246,c,av);}
/* egg-information.scm:30: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[47]);{
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

/* k3248 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3250,c,av);}
/* egg-information.scm:30: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[50];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3257 in k3232 in k3226 in k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_3259(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3259,c,av);}
if(C_truep(C_eofp(t1))){
/* egg-information.scm:40: chicken.base#error */
t2=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[43];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* main#get-egg-property in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in ... */
static C_word C_fcall f_3270(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_stack_overflow_check;{}
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_i_car(t3));
t6=C_i_assq(t2,t1);
if(C_truep(t6)){
t7=C_i_cadr(t6);
return((C_truep(t7)?t7:t5));}
else{
return(t5);}}

/* main#get-egg-property* in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in ... */
static C_word C_fcall f_3294(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_stack_overflow_check;{}
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_END_OF_LIST:C_i_car(t3));
t6=C_i_assq(t2,t1);
if(C_truep(t6)){
t7=C_i_cdr(t6);
return((C_truep(t7)?t7:t5));}
else{
return(t5);}}

/* main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in ... */
static void C_fcall f_3613(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3613,1,t1);}
a=C_alloc(4);
t2=*((C_word*)lf[31]+1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3620,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:55: chicken.port#terminal-port? */
t4=C_fast_retrieve(lf[36]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=*((C_word*)lf[31]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_3620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3620,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3623,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3635,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:56: scheme#call-with-current-continuation */
t4=*((C_word*)lf[35]+1);{
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
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(79);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3621 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3623,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3626,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:56: g943 */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k3624 in k3621 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3626(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3626,c,av);}
if(C_truep(C_i_zerop(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(79);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* chicken-status.scm:59: scheme#min */
t2=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(79);
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3635(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_3635,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3641,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3650,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:56: chicken.condition#with-exception-handler */
t5=C_fast_retrieve(lf[34]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* a3640 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,2)))){
C_save_and_reclaim((void *)f_3641,c,av);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3647,tmp=(C_word)a,a+=2,tmp);
/* chicken-status.scm:56: k940 */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a3646 in a3640 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3647(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3647,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a3649 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3650,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3656,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3674,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:56: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a3655 in a3649 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3656(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3656,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3662,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3668,tmp=(C_word)a,a+=2,tmp);
/* chicken-status.scm:56: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a3661 in a3655 in a3649 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3662,c,av);}
/* chicken-status.scm:56: chicken.port#terminal-size */
t2=C_fast_retrieve(lf[33]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a3667 in a3655 in a3649 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,1)))){
C_save_and_reclaim((void*)f_3668,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_list_ref(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a3673 in a3649 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +3,c,2)))){
C_save_and_reclaim((void*)f_3674,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+3);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3680,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:56: k940 */
t4=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a3679 in a3673 in a3649 in a3634 in k3618 in main#get-terminal-width in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3680,c,av);}{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
C_apply_values(3,av2);}}

/* main#repo-path in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_fcall f_3690(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_3690,1,t1);}
t2=(C_truep(C_retrieve2(lf[11],C_text("main#cross-chicken")))?C_i_not(C_retrieve2(lf[28],C_text("main#host-extensions"))):C_SCHEME_FALSE);
if(C_truep(t2)){
t3=C_SCHEME_END_OF_LIST;
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_i_car(t3));
if(C_truep(t5)){
t6=C_retrieve2(lf[21],C_text("main#target-run-repo"));
/* chicken-status.scm:66: ##sys#split-path */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[39]);
C_word av2[3];
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t1;
av2[2]=C_retrieve2(lf[21],C_text("main#target-run-repo"));
tp(3,av2);}}
else{
t6=C_retrieve2(lf[20],C_text("main#target-repo"));
/* chicken-status.scm:66: ##sys#split-path */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[39]);
C_word av2[3];
av2[0]=*((C_word*)lf[39]+1);
av2[1]=t1;
av2[2]=C_retrieve2(lf[20],C_text("main#target-repo"));
tp(3,av2);}}}
else{
/* chicken-status.scm:67: chicken.platform#repository-path */
t3=C_fast_retrieve(lf[40]);{
C_word av2[2];
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a3717 in k3806 in g1001 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_3718(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3718,c,av);}
t3=C_fast_retrieve(lf[55]);
/* chicken-status.scm:70: g963 */
t4=C_fast_retrieve(lf[55]);{
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

/* main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_fcall f_3724(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3724,3,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3728,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
/* chicken-status.scm:72: repo-path */
f_3690(t4);}
else{
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_i_car(t3);
f_3728(2,av2);}}}

/* k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3728(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3728,c,av);}
a=C_alloc(7);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_retrieve2(lf[22],C_text("main#+egg-info-extension+")):C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3740,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3750,a[2]=t8,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:73: chicken.pathname#make-pathname */
t10=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t10;
av2[1]=t9;
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)t0)[4];
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}

/* k3738 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3740,c,av);}
a=C_alloc(11);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3228,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3238,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3250,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* egg-information.scm:30: chicken.pathname#pathname-directory */
t5=C_fast_retrieve(lf[51]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3748 in k3726 in main#read-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3750(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3750,c,av);}
/* chicken-status.scm:73: chicken.load#find-file */
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

/* main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_fcall f_3779(C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(22,0,3)))){
C_save_and_reclaim_args((void *)trf_3779,4,t1,t2,t3,t4);}
a=C_alloc(22);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3783,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t3))){
/* chicken-status.scm:88: delete-duplicates */
f_2264(t1,t2,*((C_word*)lf[54]+1));}
else{
if(C_truep(t4)){
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3800,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t11=C_i_check_list_2(t3,lf[4]);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3818,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3820,a[2]=t8,a[3]=t14,a[4]=t10,a[5]=t9,tmp=(C_word)a,a+=6,tmp));
t16=((C_word*)t14)[1];
f_3820(t16,t12,t3);}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3857,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:84: filter */
f_2309(t5,t6,t2);}}}

/* k3781 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3783,c,av);}
/* chicken-status.scm:88: delete-duplicates */
f_2264(((C_word*)t0)[2],t1,*((C_word*)lf[54]+1));}

/* g1001 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_fcall f_3800(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_3800,3,t0,t1,t2);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3808,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3812,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:81: chicken.irregex#glob->sre */
t5=C_fast_retrieve(lf[57]);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3806 in g1001 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3808(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3808,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3718,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:70: filter */
f_2309(((C_word*)t0)[2],t2,((C_word*)t0)[3]);}

/* k3810 in g1001 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3812,c,av);}
/* chicken-status.scm:81: chicken.irregex#irregex */
t2=C_fast_retrieve(lf[56]);{
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

/* k3816 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3818(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3818,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2167,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_2167(t5,((C_word*)t0)[2],t1);}

/* map-loop995 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_fcall f_3820(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3820,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3845,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-status.scm:80: g1001 */
t4=((C_word*)t0)[4];
f_3800(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3843 in map-loop995 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3845(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3845,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3820(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a3856 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3857,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3863,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:86: any */
f_2103(t1,t3,((C_word*)t0)[2]);}

/* a3862 in a3856 in main#filter-egg-names in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_3863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3863,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_string_equal_p(t2,((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3875 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3877,c,av);}
/* chicken-status.scm:91: delete-duplicates */
f_2264(((C_word*)t0)[2],t1,*((C_word*)lf[107]+1));}

/* a3878 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3879(C_word c,C_word *av){
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
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_3879,c,av);}
a=C_alloc(14);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_fast_retrieve(lf[49]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3886,a[2]=t5,a[3]=t7,a[4]=t6,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3927,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:95: chicken.pathname#make-pathname */
t10=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t10;
av2[1]=t9;
av2[2]=t2;
av2[3]=lf[109];
av2[4]=C_retrieve2(lf[22],C_text("main#+egg-info-extension+"));
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}

/* k3884 in a3878 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_3886(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3886,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3891,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_3891(t5,((C_word*)t0)[5],t1);}

/* map-loop1033 in k3884 in a3878 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in ... */
static void C_fcall f_3891(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3891,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3916,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-status.scm:94: g1039 */
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

/* k3914 in map-loop1033 in k3884 in a3878 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in ... */
static void C_ccall f_3916(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3916,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3891(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k3925 in a3878 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_3927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3927,c,av);}
/* chicken-status.scm:95: chicken.file#glob */
t2=C_fast_retrieve(lf[108]);{
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

/* k3929 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_3931(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3931,c,av);}
/* chicken-status.scm:92: append-map */
f_1899(((C_word*)t0)[2],((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* main#format-string in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_fcall f_3933(C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_3933,4,t1,t2,t3,t4);}
a=C_alloc(5);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_i_car(t4));
t7=C_i_nullp(t4);
t8=(C_truep(t7)?C_SCHEME_END_OF_LIST:C_i_cdr(t4));
t9=C_i_nullp(t8);
t10=(C_truep(t9)?C_make_character(32):C_i_car(t8));
t11=C_i_nullp(t8);
t12=(C_truep(t11)?C_SCHEME_END_OF_LIST:C_i_cdr(t8));
t13=C_i_string_length(t2);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3952,a[2]=t6,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t15=C_fixnum_difference(t3,t13);
/* chicken-status.scm:101: scheme#make-string */
t16=*((C_word*)lf[60]+1);{
C_word av2[4];
av2[0]=t16;
av2[1]=t14;
av2[2]=C_i_fixnum_max(C_fix(0),t15);
av2[3]=t10;
((C_proc)(void*)(*((C_word*)t16+1)))(4,av2);}}

/* k3950 in main#format-string in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_3952(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3952,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[59]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[59]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}
else{
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[59]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[59]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
tp(4,av2);}}}

/* main#list-installed-eggs in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_3999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_3999,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4003,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
/* chicken-status.scm:106: repo-path */
f_3690(t4);}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_car(t3);
f_4003(2,av2);}}}

/* k4001 in main#list-installed-eggs in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4003(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4003,c,av);}
a=C_alloc(8);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_retrieve2(lf[22],C_text("main#+egg-info-extension+")):C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4013,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4020,a[2]=t8,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:109: chicken.sort#sort */
t10=C_fast_retrieve(lf[64]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t10;
av2[1]=t9;
av2[2]=((C_word*)t0)[4];
av2[3]=*((C_word*)lf[65]+1);
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}

/* g1097 in k4001 in main#list-installed-eggs in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_4013(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_4013,3,t0,t1,t2);}
t3=C_retrieve2(lf[62],C_text("main#list-egg-info"));
/* chicken-status.scm:108: g1112 */
t4=C_retrieve2(lf[62],C_text("main#list-egg-info"));{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)t0)[2];
av2[4]=((C_word*)t0)[3];
f_4078(5,av2);}}

/* k4018 in k4001 in main#list-installed-eggs in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4020(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4020,c,av);}
a=C_alloc(6);
t2=C_i_check_list_2(t1,lf[63]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4028,a[2]=t4,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_4028(t6,((C_word*)t0)[3],t1);}

/* for-each-loop1096 in k4018 in k4001 in main#list-installed-eggs in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_fcall f_4028(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4028,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4038,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-status.scm:108: g1097 */
t4=((C_word*)t0)[3];
f_4013(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4036 in for-each-loop1096 in k4018 in k4001 in main#list-installed-eggs in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4038,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4028(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4078(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_4078,c,av);}
a=C_alloc(10);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4082,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:113: read-info */
f_3724(t5,t2,C_a_i_list(&a,2,t3,t4));}

/* k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4082(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_4082,c,av);}
a=C_alloc(16);
t2=(C_truep(t1)?(
/* chicken-status.scm:114: get-egg-property */
  f_3270(t1,lf[66],C_SCHEME_END_OF_LIST)
):C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4088,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t2)){
t4=t3;
f_4088(t4,t2);}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4115,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4128,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_list2(&a,2,C_retrieve2(lf[25],C_text("main#cache-metadata-directory")),((C_word*)t0)[3]);
/* chicken-status.scm:116: chicken.pathname#make-pathname */
t7=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=lf[73];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k4086 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_4088(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_4088,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4095,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4112,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:120: scheme#string-append */
t4=*((C_word*)lf[70]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[71];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k4093 in k4086 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4095,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4099,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4103,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4108,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:123: chicken.string#->string */
t5=C_fast_retrieve(lf[69]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k4097 in k4093 in k4086 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4099(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4099,c,av);}
/* chicken-status.scm:120: chicken.base#print */
t2=*((C_word*)lf[67]+1);{
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

/* k4101 in k4093 in k4086 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4103,c,av);}
a=C_alloc(6);
/* chicken-status.scm:122: format-string */
f_3933(((C_word*)t0)[2],t1,C_retrieve2(lf[37],C_text("main#list-width")),C_a_i_list(&a,2,C_SCHEME_TRUE,C_make_character(46)));}

/* k4106 in k4093 in k4086 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4108(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4108,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[59]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[59]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[68];
av2[3]=t1;
tp(4,av2);}}

/* k4110 in k4086 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4112,c,av);}
a=C_alloc(6);
/* chicken-status.scm:120: format-string */
f_3933(((C_word*)t0)[2],t1,C_retrieve2(lf[37],C_text("main#list-width")),C_a_i_list(&a,2,C_SCHEME_FALSE,C_make_character(46)));}

/* k4113 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4115,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4118,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
/* chicken-status.scm:118: scheme#with-input-from-file */
t3=C_fast_retrieve(lf[44]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=*((C_word*)lf[45]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=((C_word*)t0)[2];
f_4088(t3,lf[72]);}}

/* k4116 in k4113 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4118(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4118,c,av);}
t2=((C_word*)t0)[2];
f_4088(t2,(C_truep(t1)?t1:lf[72]));}

/* k4126 in k4080 in main#list-egg-info in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4128,c,av);}
/* chicken-status.scm:115: chicken.file#file-exists? */
t2=C_fast_retrieve(lf[46]);{
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

/* k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4144,c,av);}
a=C_alloc(11);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4156,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4189,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4193,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-status.scm:131: chicken.file#directory */
t5=C_fast_retrieve(lf[105]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_retrieve2(lf[24],C_text("main#cache-directory"));
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4151 in for-each-loop1139 in k4154 in k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in ... */
static void C_ccall f_4153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4153,c,av);}
/* chicken-status.scm:130: list-egg-info */
t2=C_retrieve2(lf[62],C_text("main#list-egg-info"));{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=lf[104];
f_4078(5,av2);}}

/* k4154 in k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4156(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4156,c,av);}
a=C_alloc(5);
t2=C_i_check_list_2(t1,lf[63]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4164,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_4164(t6,((C_word*)t0)[2],t1);}

/* for-each-loop1139 in k4154 in k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_fcall f_4164(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4164,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4174,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4153,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:130: chicken.pathname#make-pathname */
t6=C_fast_retrieve(lf[47]);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_retrieve2(lf[24],C_text("main#cache-directory"));
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4172 in for-each-loop1139 in k4154 in k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in ... */
static void C_ccall f_4174(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4174,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4164(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4187 in k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4189,c,av);}
/* chicken-status.scm:131: chicken.sort#sort */
t2=C_fast_retrieve(lf[64]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=*((C_word*)lf[65]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4191 in k4142 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4193(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4193,c,av);}
/* chicken-status.scm:131: filter-egg-names */
f_3779(((C_word*)t0)[2],t1,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* main#gather-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_fcall f_4195(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_4195,3,t1,t2,t3);}
a=C_alloc(3);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4201,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:134: append-map */
f_1899(t1,t4,t2,C_SCHEME_END_OF_LIST);}

/* a4200 in main#gather-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4201(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4201,c,av);}
t3=C_retrieve2(lf[75],C_text("main#gather-components-rec"));
/* chicken-status.scm:134: g1164 */
t4=C_retrieve2(lf[75],C_text("main#gather-components-rec"));{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)t0)[2];
f_4207(4,av2);}}

/* main#gather-components-rec in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4207(C_word c,C_word *av){
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
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_4207,c,av);}
a=C_alloc(12);
t4=C_i_car(t2);
t5=C_eqp(t4,lf[76]);
if(C_truep(t5)){
if(C_truep(C_retrieve2(lf[28],C_text("main#host-extensions")))){
/* chicken-status.scm:139: gather-components */
f_4195(t1,C_u_i_cdr(t2),lf[76]);}
else{
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}
else{
t6=C_eqp(t4,lf[77]);
if(C_truep(t6)){
if(C_truep(C_retrieve2(lf[29],C_text("main#target-extensions")))){
/* chicken-status.scm:141: gather-components */
f_4195(t1,C_u_i_cdr(t2),lf[77]);}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t7=C_eqp(t4,lf[78]);
if(C_truep(t7)){
t8=C_i_cadr(t2);
t9=C_a_i_list3(&a,3,lf[78],t3,t8);
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_a_i_list1(&a,1,t9);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t8=C_eqp(t4,lf[79]);
if(C_truep(t8)){
t9=C_i_cadr(t2);
t10=C_a_i_list3(&a,3,lf[79],t3,t9);
t11=t1;{
C_word *av2=av;
av2[0]=t11;
av2[1]=C_a_i_list1(&a,1,t10);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
t9=C_eqp(t4,lf[80]);
if(C_truep(t9)){
t10=C_i_cadr(t2);
t11=C_a_i_list3(&a,3,lf[80],t3,t10);
t12=t1;{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list1(&a,1,t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t10=C_eqp(t4,lf[81]);
if(C_truep(t10)){
t11=C_i_cadr(t2);
t12=C_a_i_list3(&a,3,lf[81],t3,t11);
t13=t1;{
C_word *av2=av;
av2[0]=t13;
av2[1]=C_a_i_list1(&a,1,t12);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}
else{
t11=C_eqp(t4,lf[82]);
if(C_truep(t11)){
t12=C_i_cadr(t2);
t13=C_a_i_list3(&a,3,lf[82],t3,t12);
t14=t1;{
C_word *av2=av;
av2[0]=t14;
av2[1]=C_a_i_list1(&a,1,t13);
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}
else{
t12=C_eqp(t4,lf[83]);
if(C_truep(t12)){
t13=C_i_cadr(t2);
t14=C_a_i_list3(&a,3,lf[83],t3,t13);
t15=t1;{
C_word *av2=av;
av2[0]=t15;
av2[1]=C_a_i_list1(&a,1,t14);
((C_proc)(void*)(*((C_word*)t15+1)))(2,av2);}}
else{
t13=C_eqp(t4,lf[84]);
if(C_truep(t13)){
t14=C_i_cadr(t2);
t15=C_a_i_list3(&a,3,lf[84],t3,t14);
t16=t1;{
C_word *av2=av;
av2[0]=t16;
av2[1]=C_a_i_list1(&a,1,t15);
((C_proc)(void*)(*((C_word*)t16+1)))(2,av2);}}
else{
t14=t1;{
C_word *av2=av;
av2[0]=t14;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}}}}}}}}}}

/* main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4378(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4378,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4544,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:152: get-terminal-width */
f_3613(t3);}

/* g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_4383(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4383,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4387,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-status.scm:155: read-info */
f_3724(t3,t2,C_SCHEME_END_OF_LIST);}

/* k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4387(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_4387,c,av);}
a=C_alloc(13);
t2=(
/* chicken-status.scm:156: get-egg-property */
  f_3270(t1,lf[66],C_SCHEME_END_OF_LIST)
);
t3=(
/* chicken-status.scm:157: get-egg-property* */
  f_3294(t1,lf[86],C_SCHEME_END_OF_LIST)
);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4396,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t2)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4487,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4504,a[2]=t5,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:159: scheme#string-append */
t7=*((C_word*)lf[70]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[93];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
/* chicken-status.scm:163: chicken.base#print */
t5=*((C_word*)lf[67]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4396(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4396,c,av);}
a=C_alloc(3);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4402,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:165: gather-components */
f_4195(t2,((C_word*)t0)[2],C_SCHEME_FALSE);}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_4402(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4402,c,av);}
a=C_alloc(5);
t2=C_i_check_list_2(t1,lf[63]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4459,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_4459(t6,((C_word*)t0)[2],t1);}

/* k4409 in for-each-loop1197 in k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in ... */
static void C_ccall f_4411(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4411,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4415,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4439,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:169: chicken.string#->string */
t4=C_fast_retrieve(lf[69]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_caddr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4413 in k4409 in for-each-loop1197 in k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in ... */
static void C_ccall f_4415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_4415,c,av);}
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_eqp(t2,lf[76]);
if(C_truep(t3)){
/* chicken-status.scm:168: chicken.base#print */
t4=*((C_word*)lf[67]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[87];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[88];
av2[5]=t1;
av2[6]=lf[89];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}}
else{
t4=C_eqp(t2,lf[77]);
if(C_truep(t4)){
/* chicken-status.scm:168: chicken.base#print */
t5=*((C_word*)lf[67]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[87];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[88];
av2[5]=t1;
av2[6]=lf[90];
((C_proc)(void*)(*((C_word*)t5+1)))(7,av2);}}
else{
/* chicken-status.scm:168: chicken.base#print */
t5=*((C_word*)lf[67]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[87];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[88];
av2[5]=t1;
av2[6]=lf[91];
((C_proc)(void*)(*((C_word*)t5+1)))(7,av2);}}}}

/* k4437 in k4409 in for-each-loop1197 in k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in ... */
static void C_ccall f_4439(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4439,c,av);}
/* chicken-status.scm:169: format-string */
f_3933(((C_word*)t0)[2],t1,C_fix(32),C_SCHEME_END_OF_LIST);}

/* k4445 in for-each-loop1197 in k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in ... */
static void C_ccall f_4447(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4447,c,av);}
/* chicken-status.scm:168: format-string */
f_3933(((C_word*)t0)[2],t1,C_fix(32),C_SCHEME_END_OF_LIST);}

/* for-each-loop1197 in k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in ... */
static void C_fcall f_4459(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_4459,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4469,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4411,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4447,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:168: chicken.string#->string */
t7=C_fast_retrieve(lf[69]);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_i_car(t4);
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4467 in for-each-loop1197 in k4400 in k4394 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in ... */
static void C_ccall f_4469(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4469,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4459(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4485 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4487(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4487,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4491,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4495,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4500,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:161: chicken.string#->string */
t5=C_fast_retrieve(lf[69]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k4489 in k4485 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_4491(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4491,c,av);}
/* chicken-status.scm:159: chicken.base#print */
t2=*((C_word*)lf[67]+1);{
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

/* k4493 in k4485 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_4495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4495,c,av);}
a=C_alloc(6);
/* chicken-status.scm:160: format-string */
f_3933(((C_word*)t0)[2],t1,((C_word*)t0)[3],C_a_i_list(&a,2,C_SCHEME_TRUE,C_make_character(46)));}

/* k4498 in k4485 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in ... */
static void C_ccall f_4500(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4500,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[59]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[59]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[92];
av2[3]=t1;
tp(4,av2);}}

/* k4502 in k4385 in g1181 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4504(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4504,c,av);}
a=C_alloc(6);
/* chicken-status.scm:159: format-string */
f_3933(((C_word*)t0)[2],t1,((C_word*)t0)[3],C_a_i_list(&a,2,C_SCHEME_FALSE,C_make_character(46)));}

/* for-each-loop1180 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_4515(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4515,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4525,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-status.scm:153: g1181 */
t4=((C_word*)t0)[3];
f_4383(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4523 in for-each-loop1180 in k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4525,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4515(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4542 in main#list-installed-components in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4544(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(43,c,3)))){
C_save_and_reclaim((void *)f_4544,c,av);}
a=C_alloc(43);
t2=C_s_a_i_minus(&a,2,t1,C_fix(2));
t3=C_s_a_i_quotient(&a,2,t2,C_fix(2));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4383,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_i_check_list_2(((C_word*)t0)[2],lf[63]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4515,a[2]=t7,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_4515(t9,((C_word*)t0)[3],((C_word*)t0)[2]);}

/* main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4546(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_4546,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4550,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4583,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4585,tmp=(C_word)a,a+=2,tmp);
/* chicken-status.scm:181: append-map */
f_1899(t4,t5,t2,C_SCHEME_END_OF_LIST);}

/* k4548 in main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4550(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4550,c,av);}
a=C_alloc(5);
t2=C_i_check_list_2(t1,lf[63]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4558,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_4558(t6,((C_word*)t0)[2],t1);}

/* for-each-loop1229 in k4548 in main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_4558(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4558,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4568,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-status.scm:178: g1230 */
t4=*((C_word*)lf[67]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4566 in for-each-loop1229 in k4548 in main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4568,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4558(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4581 in main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4583,c,av);}
/* chicken-status.scm:180: chicken.sort#sort */
t2=C_fast_retrieve(lf[64]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=*((C_word*)lf[65]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a4584 in main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4585(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4585,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4593,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:183: read-info */
f_3724(t3,t2,C_SCHEME_END_OF_LIST);}

/* k4591 in a4584 in main#list-installed-files in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4593,c,av);}
/* chicken-status.scm:183: get-egg-property* */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* chicken-status.scm:183: get-egg-property* */
  f_3294(t1,lf[95],C_SCHEME_END_OF_LIST)
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* main#dump-installed-versions in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4595(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4595,c,av);}
a=C_alloc(5);
t3=C_i_check_list_2(t2,lf[63]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4631,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_4631(t7,t1,t2);}

/* k4610 in k4621 in for-each-loop1249 in main#dump-installed-versions in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4612(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4612,c,av);}
a=C_alloc(6);
if(C_truep(((C_word*)t0)[2])){
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
/* chicken-status.scm:191: chicken.pretty-print#pp */
t4=C_fast_retrieve(lf[97]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
/* chicken-status.scm:191: chicken.pretty-print#pp */
t3=C_fast_retrieve(lf[97]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k4621 in for-each-loop1249 in main#dump-installed-versions in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4623,c,av);}
a=C_alloc(4);
t2=(
/* chicken-status.scm:190: get-egg-property */
  f_3270(t1,lf[66],C_SCHEME_END_OF_LIST)
);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4612,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:191: scheme#string->symbol */
t4=*((C_word*)lf[98]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* for-each-loop1249 in main#dump-installed-versions in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_fcall f_4631(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4631,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4641,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4623,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:190: read-info */
f_3724(t5,t4,C_SCHEME_END_OF_LIST);}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4639 in for-each-loop1249 in main#dump-installed-versions in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4641,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4631(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_fcall f_4670(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4670,4,t0,t1,t2,t3);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4683,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t3,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
t5=((C_word*)((C_word*)t0)[4])[1];
if(C_truep(t5)){
t6=t4;
f_4683(t6,t5);}
else{
t6=((C_word*)((C_word*)t0)[5])[1];
t7=t4;
f_4683(t7,t6);}}
else{
t5=t4;
f_4683(t5,C_SCHEME_FALSE);}}
else{
t4=C_i_car(t2);
if(C_truep((C_truep(C_i_equalp(t4,lf[110]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[111]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[112]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5319,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:196: chicken.base#print */
t6=*((C_word*)lf[67]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
if(C_truep(C_i_string_equal_p(t4,lf[114]))){
t5=lf[29] /* main#target-extensions */ =C_SCHEME_FALSE;;
/* chicken-status.scm:238: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t4,lf[115]))){
t5=lf[28] /* main#host-extensions */ =C_SCHEME_FALSE;;
/* chicken-status.scm:241: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t4,lf[116]))){
t5=C_set_block_item(((C_word*)t0)[3],0,C_SCHEME_TRUE);
/* chicken-status.scm:244: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t4,lf[117]))){
t5=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_TRUE);
/* chicken-status.scm:247: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t4,lf[118]))){
t5=C_set_block_item(((C_word*)t0)[4],0,C_SCHEME_TRUE);
/* chicken-status.scm:250: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
t5=C_u_i_string_equal_p(t4,lf[119]);
t6=(C_truep(t5)?t5:C_u_i_string_equal_p(t4,lf[120]));
if(C_truep(t6)){
t7=C_set_block_item(((C_word*)t0)[5],0,C_SCHEME_TRUE);
/* chicken-status.scm:253: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
t7=C_u_i_string_equal_p(t4,lf[121]);
t8=(C_truep(t7)?t7:C_u_i_string_equal_p(t4,lf[122]));
if(C_truep(t8)){
t9=C_set_block_item(((C_word*)t0)[6],0,C_SCHEME_TRUE);
/* chicken-status.scm:256: loop */
t15=t1;
t16=C_u_i_cdr(t2);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
if(C_truep(C_u_i_string_equal_p(t4,lf[123]))){
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4828,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4835,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:258: chicken.platform#chicken-version */
t11=C_fast_retrieve(lf[124]);{
C_word av2[2];
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
t9=C_block_size(t4);
t10=(C_truep(C_i_fixnum_positivep(t9))?C_u_i_char_equalp(C_make_character(45),C_i_string_ref(t4,C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t10)){
t11=C_block_size(t4);
if(C_truep(C_fixnum_greaterp(t11,C_fix(2)))){
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4850,a[2]=((C_word*)t0)[7],a[3]=t1,a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4924,a[2]=t12,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:263: scheme#substring */
t14=*((C_word*)lf[127]+1);{
C_word av2[4];
av2[0]=t14;
av2[1]=t13;
av2[2]=t4;
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t14+1)))(4,av2);}}
else{
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5333,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:196: chicken.base#print */
t13=*((C_word*)lf[67]+1);{
C_word av2[3];
av2[0]=t13;
av2[1]=t12;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}}
else{
t11=C_u_i_cdr(t2);
t12=C_a_i_cons(&a,2,t4,t3);
/* chicken-status.scm:269: loop */
t15=t1;
t16=t11;
t17=t12;
t1=t15;
t2=t16;
t3=t17;
goto loop;}}}}}}}}}}}}

/* k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_fcall f_4683(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4683,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4686,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4691,tmp=(C_word)a,a+=2,tmp);
/* chicken-status.scm:223: chicken.port#with-output-to-port */
t4=C_fast_retrieve(lf[102]);{
C_word av2[4];
av2[0]=t4;
av2[1]=t2;
av2[2]=*((C_word*)lf[103]+1);
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
t2=((C_word*)((C_word*)t0)[4])[1];
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4144,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* chicken-status.scm:127: chicken.file#directory-exists? */
t4=C_fast_retrieve(lf[106]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[24],C_text("main#cache-directory"));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4704,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)((C_word*)t0)[6])[1])){
t3=t2;
f_4704(t3,C_retrieve2(lf[96],C_text("main#dump-installed-versions")));}
else{
if(C_truep(((C_word*)((C_word*)t0)[7])[1])){
t3=C_retrieve2(lf[94],C_text("main#list-installed-files"));
t4=t2;
f_4704(t4,C_retrieve2(lf[94],C_text("main#list-installed-files")));}
else{
t3=t2;
f_4704(t3,(C_truep(((C_word*)((C_word*)t0)[8])[1])?C_retrieve2(lf[85],C_text("main#list-installed-components")):C_retrieve2(lf[61],C_text("main#list-installed-eggs"))));}}}}}

/* k4684 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4686,c,av);}
/* chicken-status.scm:225: chicken.base#exit */
t2=C_fast_retrieve(lf[100]);{
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

/* a4690 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4691,c,av);}
/* chicken-status.scm:224: g1291 */
t2=*((C_word*)lf[67]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[101];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_fcall f_4704(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_4704,2,t0,t1);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4711,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4715,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3877,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3879,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3931,a[2]=t4,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* chicken-status.scm:96: repo-path */
f_3690(t6);}

/* k4709 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4711(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4711,c,av);}
/* chicken-status.scm:222: g1294 */
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
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k4713 in k4702 in k4681 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in ... */
static void C_ccall f_4715(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4715,c,av);}
/* chicken-status.scm:232: filter-egg-names */
f_3779(((C_word*)t0)[2],t1,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k4826 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4828,c,av);}
/* chicken-status.scm:259: chicken.base#exit */
t2=C_fast_retrieve(lf[100]);{
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

/* k4833 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4835,c,av);}
/* chicken-status.scm:258: chicken.base#print */
t2=*((C_word*)lf[67]+1);{
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

/* k4848 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4850(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4850,c,av);}
a=C_alloc(23);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2075,tmp=(C_word)a,a+=2,tmp);
t3=(
  f_2075(t1)
);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4863,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4875,a[2]=t4,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4879,a[2]=t7,a[3]=t11,a[4]=t8,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_4879(t13,t9,t1);}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5326,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:196: chicken.base#print */
t5=*((C_word*)lf[67]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k4861 in k4848 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4863,c,av);}
/* chicken-status.scm:265: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_4670(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k4873 in k4848 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_ccall f_4875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4875,c,av);}
/* chicken-status.scm:265: scheme#append */
t2=*((C_word*)lf[3]+1);{
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

/* map-loop1330 in k4848 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in ... */
static void C_fcall f_4879(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_4879,3,t0,t1,t2);}
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

/* k4922 in loop in k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in ... */
static void C_ccall f_4924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4924,c,av);}
/* ##sys#string->list */
t2=C_fast_retrieve(lf[126]);{
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

/* k4956 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4958(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4958,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4964,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base#implicit-exit-handler */
t3=C_fast_retrieve(lf[99]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4962 in k4956 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in ... */
static void C_ccall f_4964(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4964,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4966 in k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in ... */
static void C_ccall f_4968(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_4968,c,av);}
a=C_alloc(20);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_FALSE;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_FALSE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_FALSE;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4670,a[2]=t9,a[3]=t11,a[4]=t7,a[5]=t3,a[6]=t5,a[7]=t13,tmp=(C_word)a,a+=8,tmp));
t15=((C_word*)t13)[1];
f_4670(t15,((C_word*)t0)[2],t1,C_SCHEME_END_OF_LIST);}

/* k4974 in k3217 in k3213 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in ... */
static void C_ccall f_4976(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(62,c,5)))){
C_save_and_reclaim((void *)f_4976,c,av);}
a=C_alloc(62);
t2=C_s_a_i_minus(&a,2,t1,C_fix(2));
t3=C_s_a_i_quotient(&a,2,t2,C_fix(2));
t4=C_mutate(&lf[37] /* (set! main#list-width ...) */,t3);
t5=C_mutate(&lf[38] /* (set! main#repo-path ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3690,tmp=(C_word)a,a+=2,tmp));
t6=C_mutate(&lf[41] /* (set! main#read-info ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3724,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate(&lf[53] /* (set! main#filter-egg-names ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3779,tmp=(C_word)a,a+=2,tmp));
t8=C_mutate(&lf[58] /* (set! main#format-string ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3933,tmp=(C_word)a,a+=2,tmp));
t9=C_mutate(&lf[61] /* (set! main#list-installed-eggs ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3999,tmp=(C_word)a,a+=2,tmp));
t10=C_mutate(&lf[62] /* (set! main#list-egg-info ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4078,tmp=(C_word)a,a+=2,tmp));
t11=C_mutate(&lf[74] /* (set! main#gather-components ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4195,tmp=(C_word)a,a+=2,tmp));
t12=C_mutate(&lf[75] /* (set! main#gather-components-rec ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4207,tmp=(C_word)a,a+=2,tmp));
t13=C_mutate(&lf[85] /* (set! main#list-installed-components ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4378,tmp=(C_word)a,a+=2,tmp));
t14=C_mutate(&lf[94] /* (set! main#list-installed-files ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4546,tmp=(C_word)a,a+=2,tmp));
t15=C_mutate(&lf[96] /* (set! main#dump-installed-versions ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4595,tmp=(C_word)a,a+=2,tmp));
t16=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4958,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t17=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4968,a[2]=t16,tmp=(C_word)a,a+=3,tmp);
/* chicken-status.scm:271: chicken.process-context#command-line-arguments */
t18=C_fast_retrieve(lf[128]);{
C_word *av2=av;
av2[0]=t18;
av2[1]=t17;
((C_proc)(void*)(*((C_word*)t18+1)))(2,av2);}}

/* k4981 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in ... */
static void C_ccall f_4983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4983,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4986,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
/* egg-environment.scm:123: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[14],C_text("main#chicken-install-program"));
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* egg-environment.scm:124: chicken.process-context#current-directory */
t3=C_fast_retrieve(lf[130]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4984 in k4981 in k3210 in k3126 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in ... */
static void C_ccall f_4986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4986,c,av);}
/* egg-environment.scm:123: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[14],C_text("main#chicken-install-program"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4991 in k3122 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in ... */
static void C_ccall f_4993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4993,c,av);}
/* egg-environment.scm:99: scheme#string-append */
t2=*((C_word*)lf[70]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[16],C_text("main#default-runlibdir"));
av2[3]=lf[134];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4996 in k3118 in k3114 in k3110 in k3106 in k3102 in k3098 in k3094 in k3090 in k3086 in k3082 in k3078 in k3074 in k3070 in k3066 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in ... */
static void C_ccall f_4998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4998,c,av);}
/* egg-environment.scm:96: scheme#string-append */
t2=*((C_word*)lf[70]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[15],C_text("main#default-libdir"));
av2[3]=lf[136];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k5001 in k3062 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in ... */
static void C_ccall f_5003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5003,c,av);}
/* egg-environment.scm:78: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[47]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[17],C_text("main#default-bindir"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5005 in k3058 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in ... */
static void C_ccall f_5007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5007,c,av);}
/* egg-environment.scm:75: scheme#string-append */
t2=*((C_word*)lf[70]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[17],C_text("main#default-bindir"));
av2[3]=lf[138];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k5009 in k3054 in k3050 in k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in ... */
static void C_ccall f_5011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5011,c,av);}
/* egg-environment.scm:72: scheme#string-append */
t2=*((C_word*)lf[70]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[17],C_text("main#default-bindir"));
av2[3]=lf[139];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k5016 in k3042 in k3038 in k3034 in k3030 in k3026 in k3022 in k3018 in k3014 in k3010 in k3006 in k3002 in k2998 in k2994 in k2990 in k2986 in k2980 in k1696 in k1693 in k1690 in k1687 in k1684 in ... */
static void C_ccall f_5018(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5018,c,av);}
a=C_alloc(6);
t2=C_eqp(t1,lf[18]);
t3=(C_truep(t2)?C_mk_bool(C_WINDOWS_SHELL):lf[19]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3052,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t5=*((C_word*)lf[137]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_PREFIX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* a5019 in k1675 in k1672 */
static void C_ccall f_5020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_5020,c,av);}
/* chicken-status.scm:26: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[143]);
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[143]+1);
av2[1]=t1;
av2[2]=lf[144];
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
if(C_unlikely(!C_demand_2(523))){
C_save(t1);
C_rereclaim2(523*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,146);
lf[0]=C_h_intern(&lf[0],5, C_text("main#"));
lf[2]=C_h_intern(&lf[2],5, C_text("foldr"));
lf[3]=C_h_intern(&lf[3],13, C_text("scheme#append"));
lf[4]=C_h_intern(&lf[4],3, C_text("map"));
lf[6]=C_h_intern(&lf[6],12, C_text("scheme#null\077"));
lf[18]=C_h_intern(&lf[18],7, C_text("windows"));
lf[19]=C_h_intern(&lf[19],4, C_text("unix"));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010egg-info"));
lf[31]=C_h_intern(&lf[31],21, C_text("##sys#standard-output"));
lf[32]=C_h_intern(&lf[32],10, C_text("scheme#min"));
lf[33]=C_h_intern(&lf[33],26, C_text("chicken.port#terminal-size"));
lf[34]=C_h_intern(&lf[34],40, C_text("chicken.condition#with-exception-handler"));
lf[35]=C_h_intern(&lf[35],37, C_text("scheme#call-with-current-continuation"));
lf[36]=C_h_intern(&lf[36],27, C_text("chicken.port#terminal-port\077"));
lf[39]=C_h_intern(&lf[39],16, C_text("##sys#split-path"));
lf[40]=C_h_intern(&lf[40],32, C_text("chicken.platform#repository-path"));
lf[42]=C_h_intern(&lf[42],18, C_text("chicken.base#error"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000xempty egg-info file, possibly due to an aborted egg-install - please remove"
" the file and reinstall the corresponding egg"));
lf[44]=C_h_intern(&lf[44],27, C_text("scheme#with-input-from-file"));
lf[45]=C_h_intern(&lf[45],11, C_text("scheme#read"));
lf[46]=C_h_intern(&lf[46],25, C_text("chicken.file#file-exists\077"));
lf[47]=C_h_intern(&lf[47],30, C_text("chicken.pathname#make-pathname"));
lf[48]=C_h_intern(&lf[48],35, C_text("chicken.pathname#pathname-extension"));
lf[49]=C_h_intern(&lf[49],30, C_text("chicken.pathname#pathname-file"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007chicken"));
lf[51]=C_h_intern(&lf[51],35, C_text("chicken.pathname#pathname-directory"));
lf[52]=C_h_intern(&lf[52],22, C_text("chicken.load#find-file"));
lf[54]=C_h_intern(&lf[54],15, C_text("scheme#string=\077"));
lf[55]=C_h_intern(&lf[55],30, C_text("chicken.irregex#irregex-search"));
lf[56]=C_h_intern(&lf[56],23, C_text("chicken.irregex#irregex"));
lf[57]=C_h_intern(&lf[57],25, C_text("chicken.irregex#glob->sre"));
lf[59]=C_h_intern(&lf[59],19, C_text("##sys#string-append"));
lf[60]=C_h_intern(&lf[60],18, C_text("scheme#make-string"));
lf[63]=C_h_intern(&lf[63],8, C_text("for-each"));
lf[64]=C_h_intern(&lf[64],17, C_text("chicken.sort#sort"));
lf[65]=C_h_intern(&lf[65],15, C_text("scheme#string<\077"));
lf[66]=C_h_intern(&lf[66],7, C_text("version"));
lf[67]=C_h_intern(&lf[67],18, C_text("chicken.base#print"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012 version: "));
lf[69]=C_h_intern(&lf[69],23, C_text("chicken.string#->string"));
lf[70]=C_h_intern(&lf[70],20, C_text("scheme#string-append"));
lf[71]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[72]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007unknown"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007VERSION"));
lf[76]=C_h_intern(&lf[76],4, C_text("host"));
lf[77]=C_h_intern(&lf[77],6, C_text("target"));
lf[78]=C_h_intern(&lf[78],9, C_text("extension"));
lf[79]=C_h_intern(&lf[79],4, C_text("data"));
lf[80]=C_h_intern(&lf[80],21, C_text("generated-source-file"));
lf[81]=C_h_intern(&lf[81],9, C_text("c-include"));
lf[82]=C_h_intern(&lf[82],14, C_text("scheme-include"));
lf[83]=C_h_intern(&lf[83],7, C_text("program"));
lf[84]=C_h_intern(&lf[84],8, C_text("c-object"));
lf[86]=C_h_intern(&lf[86],10, C_text("components"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[88]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[89]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007 (host)"));
lf[90]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011 (target)"));
lf[91]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012 version: "));
lf[93]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[95]=C_h_intern(&lf[95],15, C_text("installed-files"));
lf[97]=C_h_intern(&lf[97],23, C_text("chicken.pretty-print#pp"));
lf[98]=C_h_intern(&lf[98],21, C_text("scheme#string->symbol"));
lf[99]=C_h_intern(&lf[99],34, C_text("chicken.base#implicit-exit-handler"));
lf[100]=C_h_intern(&lf[100],17, C_text("chicken.base#exit"));
lf[101]=C_decode_literal(C_heaptop,C_text("\376B\000\000&-components cannot be used with -list."));
lf[102]=C_h_intern(&lf[102],32, C_text("chicken.port#with-output-to-port"));
lf[103]=C_h_intern(&lf[103],20, C_text("##sys#standard-error"));
lf[104]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003egg"));
lf[105]=C_h_intern(&lf[105],22, C_text("chicken.file#directory"));
lf[106]=C_h_intern(&lf[106],30, C_text("chicken.file#directory-exists\077"));
lf[107]=C_h_intern(&lf[107],13, C_text("scheme#equal\077"));
lf[108]=C_h_intern(&lf[108],17, C_text("chicken.file#glob"));
lf[109]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\052"));
lf[110]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-help"));
lf[111]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-h"));
lf[112]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006--help"));
lf[113]=C_decode_literal(C_heaptop,C_text("\376B\000\002wusage: chicken-status [OPTION ...] [NAME ...]\012\012  -h   -help                "
"    show this message\012       -version                 show version and exit\012  -c"
"   -components              list installed components\012       -cached            "
"      list eggs in cache\012  -f   -files                   list installed files\012  "
"     -list                    dump installed extensions and their versions in \042o"
"verride\042 format\012       -match                   treat NAME as glob pattern\012     "
"  -host                    when cross-compiling, only show host extensions\012     "
"  -target                  when cross-compiling, only show target extensions"));
lf[114]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-host"));
lf[115]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-target"));
lf[116]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006-match"));
lf[117]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-cached"));
lf[118]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-list"));
lf[119]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-f"));
lf[120]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006-files"));
lf[121]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-c"));
lf[122]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013-components"));
lf[123]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-version"));
lf[124]=C_h_intern(&lf[124],32, C_text("chicken.platform#chicken-version"));
lf[125]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000h\376\003\000\000\002\376\377\012\000\000f\376\003\000\000\002\376\377\012\000\000c\376\003\000\000\002\376\377\012\000\000a\376\377\016"));
lf[126]=C_h_intern(&lf[126],18, C_text("##sys#string->list"));
lf[127]=C_h_intern(&lf[127],16, C_text("scheme#substring"));
lf[128]=C_h_intern(&lf[128],46, C_text("chicken.process-context#command-line-arguments"));
lf[129]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017.cache-metadata"));
lf[130]=C_h_intern(&lf[130],41, C_text("chicken.process-context#current-directory"));
lf[131]=C_h_intern(&lf[131],39, C_text("chicken.platform#system-cache-directory"));
lf[132]=C_h_intern(&lf[132],48, C_text("chicken.process-context#get-environment-variable"));
lf[133]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021CHICKEN_EGG_CACHE"));
lf[134]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011/chicken/"));
lf[135]=C_h_intern(&lf[135],20, C_text("##sys#fixnum->string"));
lf[136]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011/chicken/"));
lf[137]=C_h_intern(&lf[137],19, C_text("##sys#peek-c-string"));
lf[138]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[139]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[140]=C_h_intern(&lf[140],30, C_text("chicken.platform#software-type"));
lf[141]=C_h_intern(&lf[141],25, C_text("chicken.platform#feature\077"));
lf[142]=C_h_intern_kw(&lf[142],13, C_text("cross-chicken"));
lf[143]=C_h_intern(&lf[143],30, C_text("##sys#register-compiled-module"));
lf[144]=C_h_intern(&lf[144],4, C_text("main"));
lf[145]=C_h_intern(&lf[145],22, C_text("##sys#with-environment"));
C_register_lf2(lf,146,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1674,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[216] = {
{C_text("f5319:chicken_2dstatus_2escm"),(void*)f5319},
{C_text("f5326:chicken_2dstatus_2escm"),(void*)f5326},
{C_text("f5333:chicken_2dstatus_2escm"),(void*)f5333},
{C_text("f_1674:chicken_2dstatus_2escm"),(void*)f_1674},
{C_text("f_1677:chicken_2dstatus_2escm"),(void*)f_1677},
{C_text("f_1680:chicken_2dstatus_2escm"),(void*)f_1680},
{C_text("f_1683:chicken_2dstatus_2escm"),(void*)f_1683},
{C_text("f_1686:chicken_2dstatus_2escm"),(void*)f_1686},
{C_text("f_1689:chicken_2dstatus_2escm"),(void*)f_1689},
{C_text("f_1692:chicken_2dstatus_2escm"),(void*)f_1692},
{C_text("f_1695:chicken_2dstatus_2escm"),(void*)f_1695},
{C_text("f_1698:chicken_2dstatus_2escm"),(void*)f_1698},
{C_text("f_1899:chicken_2dstatus_2escm"),(void*)f_1899},
{C_text("f_1914:chicken_2dstatus_2escm"),(void*)f_1914},
{C_text("f_1922:chicken_2dstatus_2escm"),(void*)f_1922},
{C_text("f_1930:chicken_2dstatus_2escm"),(void*)f_1930},
{C_text("f_1941:chicken_2dstatus_2escm"),(void*)f_1941},
{C_text("f_1954:chicken_2dstatus_2escm"),(void*)f_1954},
{C_text("f_1961:chicken_2dstatus_2escm"),(void*)f_1961},
{C_text("f_1968:chicken_2dstatus_2escm"),(void*)f_1968},
{C_text("f_1972:chicken_2dstatus_2escm"),(void*)f_1972},
{C_text("f_1984:chicken_2dstatus_2escm"),(void*)f_1984},
{C_text("f_1986:chicken_2dstatus_2escm"),(void*)f_1986},
{C_text("f_2033:chicken_2dstatus_2escm"),(void*)f_2033},
{C_text("f_2035:chicken_2dstatus_2escm"),(void*)f_2035},
{C_text("f_2075:chicken_2dstatus_2escm"),(void*)f_2075},
{C_text("f_2103:chicken_2dstatus_2escm"),(void*)f_2103},
{C_text("f_2109:chicken_2dstatus_2escm"),(void*)f_2109},
{C_text("f_2119:chicken_2dstatus_2escm"),(void*)f_2119},
{C_text("f_2167:chicken_2dstatus_2escm"),(void*)f_2167},
{C_text("f_2185:chicken_2dstatus_2escm"),(void*)f_2185},
{C_text("f_2195:chicken_2dstatus_2escm"),(void*)f_2195},
{C_text("f_2208:chicken_2dstatus_2escm"),(void*)f_2208},
{C_text("f_2222:chicken_2dstatus_2escm"),(void*)f_2222},
{C_text("f_2264:chicken_2dstatus_2escm"),(void*)f_2264},
{C_text("f_2270:chicken_2dstatus_2escm"),(void*)f_2270},
{C_text("f_2284:chicken_2dstatus_2escm"),(void*)f_2284},
{C_text("f_2297:chicken_2dstatus_2escm"),(void*)f_2297},
{C_text("f_2309:chicken_2dstatus_2escm"),(void*)f_2309},
{C_text("f_2318:chicken_2dstatus_2escm"),(void*)f_2318},
{C_text("f_2326:chicken_2dstatus_2escm"),(void*)f_2326},
{C_text("f_2333:chicken_2dstatus_2escm"),(void*)f_2333},
{C_text("f_2347:chicken_2dstatus_2escm"),(void*)f_2347},
{C_text("f_2982:chicken_2dstatus_2escm"),(void*)f_2982},
{C_text("f_2988:chicken_2dstatus_2escm"),(void*)f_2988},
{C_text("f_2992:chicken_2dstatus_2escm"),(void*)f_2992},
{C_text("f_2996:chicken_2dstatus_2escm"),(void*)f_2996},
{C_text("f_3000:chicken_2dstatus_2escm"),(void*)f_3000},
{C_text("f_3004:chicken_2dstatus_2escm"),(void*)f_3004},
{C_text("f_3008:chicken_2dstatus_2escm"),(void*)f_3008},
{C_text("f_3012:chicken_2dstatus_2escm"),(void*)f_3012},
{C_text("f_3016:chicken_2dstatus_2escm"),(void*)f_3016},
{C_text("f_3020:chicken_2dstatus_2escm"),(void*)f_3020},
{C_text("f_3024:chicken_2dstatus_2escm"),(void*)f_3024},
{C_text("f_3028:chicken_2dstatus_2escm"),(void*)f_3028},
{C_text("f_3032:chicken_2dstatus_2escm"),(void*)f_3032},
{C_text("f_3036:chicken_2dstatus_2escm"),(void*)f_3036},
{C_text("f_3040:chicken_2dstatus_2escm"),(void*)f_3040},
{C_text("f_3044:chicken_2dstatus_2escm"),(void*)f_3044},
{C_text("f_3052:chicken_2dstatus_2escm"),(void*)f_3052},
{C_text("f_3056:chicken_2dstatus_2escm"),(void*)f_3056},
{C_text("f_3060:chicken_2dstatus_2escm"),(void*)f_3060},
{C_text("f_3064:chicken_2dstatus_2escm"),(void*)f_3064},
{C_text("f_3068:chicken_2dstatus_2escm"),(void*)f_3068},
{C_text("f_3072:chicken_2dstatus_2escm"),(void*)f_3072},
{C_text("f_3076:chicken_2dstatus_2escm"),(void*)f_3076},
{C_text("f_3080:chicken_2dstatus_2escm"),(void*)f_3080},
{C_text("f_3084:chicken_2dstatus_2escm"),(void*)f_3084},
{C_text("f_3088:chicken_2dstatus_2escm"),(void*)f_3088},
{C_text("f_3092:chicken_2dstatus_2escm"),(void*)f_3092},
{C_text("f_3096:chicken_2dstatus_2escm"),(void*)f_3096},
{C_text("f_3100:chicken_2dstatus_2escm"),(void*)f_3100},
{C_text("f_3104:chicken_2dstatus_2escm"),(void*)f_3104},
{C_text("f_3108:chicken_2dstatus_2escm"),(void*)f_3108},
{C_text("f_3112:chicken_2dstatus_2escm"),(void*)f_3112},
{C_text("f_3116:chicken_2dstatus_2escm"),(void*)f_3116},
{C_text("f_3120:chicken_2dstatus_2escm"),(void*)f_3120},
{C_text("f_3124:chicken_2dstatus_2escm"),(void*)f_3124},
{C_text("f_3128:chicken_2dstatus_2escm"),(void*)f_3128},
{C_text("f_3212:chicken_2dstatus_2escm"),(void*)f_3212},
{C_text("f_3215:chicken_2dstatus_2escm"),(void*)f_3215},
{C_text("f_3219:chicken_2dstatus_2escm"),(void*)f_3219},
{C_text("f_3228:chicken_2dstatus_2escm"),(void*)f_3228},
{C_text("f_3234:chicken_2dstatus_2escm"),(void*)f_3234},
{C_text("f_3238:chicken_2dstatus_2escm"),(void*)f_3238},
{C_text("f_3242:chicken_2dstatus_2escm"),(void*)f_3242},
{C_text("f_3246:chicken_2dstatus_2escm"),(void*)f_3246},
{C_text("f_3250:chicken_2dstatus_2escm"),(void*)f_3250},
{C_text("f_3259:chicken_2dstatus_2escm"),(void*)f_3259},
{C_text("f_3270:chicken_2dstatus_2escm"),(void*)f_3270},
{C_text("f_3294:chicken_2dstatus_2escm"),(void*)f_3294},
{C_text("f_3613:chicken_2dstatus_2escm"),(void*)f_3613},
{C_text("f_3620:chicken_2dstatus_2escm"),(void*)f_3620},
{C_text("f_3623:chicken_2dstatus_2escm"),(void*)f_3623},
{C_text("f_3626:chicken_2dstatus_2escm"),(void*)f_3626},
{C_text("f_3635:chicken_2dstatus_2escm"),(void*)f_3635},
{C_text("f_3641:chicken_2dstatus_2escm"),(void*)f_3641},
{C_text("f_3647:chicken_2dstatus_2escm"),(void*)f_3647},
{C_text("f_3650:chicken_2dstatus_2escm"),(void*)f_3650},
{C_text("f_3656:chicken_2dstatus_2escm"),(void*)f_3656},
{C_text("f_3662:chicken_2dstatus_2escm"),(void*)f_3662},
{C_text("f_3668:chicken_2dstatus_2escm"),(void*)f_3668},
{C_text("f_3674:chicken_2dstatus_2escm"),(void*)f_3674},
{C_text("f_3680:chicken_2dstatus_2escm"),(void*)f_3680},
{C_text("f_3690:chicken_2dstatus_2escm"),(void*)f_3690},
{C_text("f_3718:chicken_2dstatus_2escm"),(void*)f_3718},
{C_text("f_3724:chicken_2dstatus_2escm"),(void*)f_3724},
{C_text("f_3728:chicken_2dstatus_2escm"),(void*)f_3728},
{C_text("f_3740:chicken_2dstatus_2escm"),(void*)f_3740},
{C_text("f_3750:chicken_2dstatus_2escm"),(void*)f_3750},
{C_text("f_3779:chicken_2dstatus_2escm"),(void*)f_3779},
{C_text("f_3783:chicken_2dstatus_2escm"),(void*)f_3783},
{C_text("f_3800:chicken_2dstatus_2escm"),(void*)f_3800},
{C_text("f_3808:chicken_2dstatus_2escm"),(void*)f_3808},
{C_text("f_3812:chicken_2dstatus_2escm"),(void*)f_3812},
{C_text("f_3818:chicken_2dstatus_2escm"),(void*)f_3818},
{C_text("f_3820:chicken_2dstatus_2escm"),(void*)f_3820},
{C_text("f_3845:chicken_2dstatus_2escm"),(void*)f_3845},
{C_text("f_3857:chicken_2dstatus_2escm"),(void*)f_3857},
{C_text("f_3863:chicken_2dstatus_2escm"),(void*)f_3863},
{C_text("f_3877:chicken_2dstatus_2escm"),(void*)f_3877},
{C_text("f_3879:chicken_2dstatus_2escm"),(void*)f_3879},
{C_text("f_3886:chicken_2dstatus_2escm"),(void*)f_3886},
{C_text("f_3891:chicken_2dstatus_2escm"),(void*)f_3891},
{C_text("f_3916:chicken_2dstatus_2escm"),(void*)f_3916},
{C_text("f_3927:chicken_2dstatus_2escm"),(void*)f_3927},
{C_text("f_3931:chicken_2dstatus_2escm"),(void*)f_3931},
{C_text("f_3933:chicken_2dstatus_2escm"),(void*)f_3933},
{C_text("f_3952:chicken_2dstatus_2escm"),(void*)f_3952},
{C_text("f_3999:chicken_2dstatus_2escm"),(void*)f_3999},
{C_text("f_4003:chicken_2dstatus_2escm"),(void*)f_4003},
{C_text("f_4013:chicken_2dstatus_2escm"),(void*)f_4013},
{C_text("f_4020:chicken_2dstatus_2escm"),(void*)f_4020},
{C_text("f_4028:chicken_2dstatus_2escm"),(void*)f_4028},
{C_text("f_4038:chicken_2dstatus_2escm"),(void*)f_4038},
{C_text("f_4078:chicken_2dstatus_2escm"),(void*)f_4078},
{C_text("f_4082:chicken_2dstatus_2escm"),(void*)f_4082},
{C_text("f_4088:chicken_2dstatus_2escm"),(void*)f_4088},
{C_text("f_4095:chicken_2dstatus_2escm"),(void*)f_4095},
{C_text("f_4099:chicken_2dstatus_2escm"),(void*)f_4099},
{C_text("f_4103:chicken_2dstatus_2escm"),(void*)f_4103},
{C_text("f_4108:chicken_2dstatus_2escm"),(void*)f_4108},
{C_text("f_4112:chicken_2dstatus_2escm"),(void*)f_4112},
{C_text("f_4115:chicken_2dstatus_2escm"),(void*)f_4115},
{C_text("f_4118:chicken_2dstatus_2escm"),(void*)f_4118},
{C_text("f_4128:chicken_2dstatus_2escm"),(void*)f_4128},
{C_text("f_4144:chicken_2dstatus_2escm"),(void*)f_4144},
{C_text("f_4153:chicken_2dstatus_2escm"),(void*)f_4153},
{C_text("f_4156:chicken_2dstatus_2escm"),(void*)f_4156},
{C_text("f_4164:chicken_2dstatus_2escm"),(void*)f_4164},
{C_text("f_4174:chicken_2dstatus_2escm"),(void*)f_4174},
{C_text("f_4189:chicken_2dstatus_2escm"),(void*)f_4189},
{C_text("f_4193:chicken_2dstatus_2escm"),(void*)f_4193},
{C_text("f_4195:chicken_2dstatus_2escm"),(void*)f_4195},
{C_text("f_4201:chicken_2dstatus_2escm"),(void*)f_4201},
{C_text("f_4207:chicken_2dstatus_2escm"),(void*)f_4207},
{C_text("f_4378:chicken_2dstatus_2escm"),(void*)f_4378},
{C_text("f_4383:chicken_2dstatus_2escm"),(void*)f_4383},
{C_text("f_4387:chicken_2dstatus_2escm"),(void*)f_4387},
{C_text("f_4396:chicken_2dstatus_2escm"),(void*)f_4396},
{C_text("f_4402:chicken_2dstatus_2escm"),(void*)f_4402},
{C_text("f_4411:chicken_2dstatus_2escm"),(void*)f_4411},
{C_text("f_4415:chicken_2dstatus_2escm"),(void*)f_4415},
{C_text("f_4439:chicken_2dstatus_2escm"),(void*)f_4439},
{C_text("f_4447:chicken_2dstatus_2escm"),(void*)f_4447},
{C_text("f_4459:chicken_2dstatus_2escm"),(void*)f_4459},
{C_text("f_4469:chicken_2dstatus_2escm"),(void*)f_4469},
{C_text("f_4487:chicken_2dstatus_2escm"),(void*)f_4487},
{C_text("f_4491:chicken_2dstatus_2escm"),(void*)f_4491},
{C_text("f_4495:chicken_2dstatus_2escm"),(void*)f_4495},
{C_text("f_4500:chicken_2dstatus_2escm"),(void*)f_4500},
{C_text("f_4504:chicken_2dstatus_2escm"),(void*)f_4504},
{C_text("f_4515:chicken_2dstatus_2escm"),(void*)f_4515},
{C_text("f_4525:chicken_2dstatus_2escm"),(void*)f_4525},
{C_text("f_4544:chicken_2dstatus_2escm"),(void*)f_4544},
{C_text("f_4546:chicken_2dstatus_2escm"),(void*)f_4546},
{C_text("f_4550:chicken_2dstatus_2escm"),(void*)f_4550},
{C_text("f_4558:chicken_2dstatus_2escm"),(void*)f_4558},
{C_text("f_4568:chicken_2dstatus_2escm"),(void*)f_4568},
{C_text("f_4583:chicken_2dstatus_2escm"),(void*)f_4583},
{C_text("f_4585:chicken_2dstatus_2escm"),(void*)f_4585},
{C_text("f_4593:chicken_2dstatus_2escm"),(void*)f_4593},
{C_text("f_4595:chicken_2dstatus_2escm"),(void*)f_4595},
{C_text("f_4612:chicken_2dstatus_2escm"),(void*)f_4612},
{C_text("f_4623:chicken_2dstatus_2escm"),(void*)f_4623},
{C_text("f_4631:chicken_2dstatus_2escm"),(void*)f_4631},
{C_text("f_4641:chicken_2dstatus_2escm"),(void*)f_4641},
{C_text("f_4670:chicken_2dstatus_2escm"),(void*)f_4670},
{C_text("f_4683:chicken_2dstatus_2escm"),(void*)f_4683},
{C_text("f_4686:chicken_2dstatus_2escm"),(void*)f_4686},
{C_text("f_4691:chicken_2dstatus_2escm"),(void*)f_4691},
{C_text("f_4704:chicken_2dstatus_2escm"),(void*)f_4704},
{C_text("f_4711:chicken_2dstatus_2escm"),(void*)f_4711},
{C_text("f_4715:chicken_2dstatus_2escm"),(void*)f_4715},
{C_text("f_4828:chicken_2dstatus_2escm"),(void*)f_4828},
{C_text("f_4835:chicken_2dstatus_2escm"),(void*)f_4835},
{C_text("f_4850:chicken_2dstatus_2escm"),(void*)f_4850},
{C_text("f_4863:chicken_2dstatus_2escm"),(void*)f_4863},
{C_text("f_4875:chicken_2dstatus_2escm"),(void*)f_4875},
{C_text("f_4879:chicken_2dstatus_2escm"),(void*)f_4879},
{C_text("f_4924:chicken_2dstatus_2escm"),(void*)f_4924},
{C_text("f_4958:chicken_2dstatus_2escm"),(void*)f_4958},
{C_text("f_4964:chicken_2dstatus_2escm"),(void*)f_4964},
{C_text("f_4968:chicken_2dstatus_2escm"),(void*)f_4968},
{C_text("f_4976:chicken_2dstatus_2escm"),(void*)f_4976},
{C_text("f_4983:chicken_2dstatus_2escm"),(void*)f_4983},
{C_text("f_4986:chicken_2dstatus_2escm"),(void*)f_4986},
{C_text("f_4993:chicken_2dstatus_2escm"),(void*)f_4993},
{C_text("f_4998:chicken_2dstatus_2escm"),(void*)f_4998},
{C_text("f_5003:chicken_2dstatus_2escm"),(void*)f_5003},
{C_text("f_5007:chicken_2dstatus_2escm"),(void*)f_5007},
{C_text("f_5011:chicken_2dstatus_2escm"),(void*)f_5011},
{C_text("f_5018:chicken_2dstatus_2escm"),(void*)f_5018},
{C_text("f_5020:chicken_2dstatus_2escm"),(void*)f_5020},
{C_text("toplevel:chicken_2dstatus_2escm"),(void*)C_toplevel},
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
o|hiding unexported module binding: main#get-terminal-width 
o|hiding unexported module binding: main#list-width 
o|hiding unexported module binding: main#repo-path 
o|hiding unexported module binding: main#grep 
o|hiding unexported module binding: main#read-info 
o|hiding unexported module binding: main#filter-egg-names 
o|hiding unexported module binding: main#gather-eggs 
o|hiding unexported module binding: main#format-string 
o|hiding unexported module binding: main#list-installed-eggs 
o|hiding unexported module binding: main#list-egg-info 
o|hiding unexported module binding: main#list-cached-eggs 
o|hiding unexported module binding: main#gather-components 
o|hiding unexported module binding: main#gather-components-rec 
o|hiding unexported module binding: main#list-installed-components 
o|hiding unexported module binding: main#list-installed-files 
o|hiding unexported module binding: main#dump-installed-versions 
o|hiding unexported module binding: main#usage 
o|hiding unexported module binding: main#short-options 
o|hiding unexported module binding: main#main 
S|applied compiler syntax:
S|  scheme#for-each		6
S|  chicken.base#foldl		3
S|  scheme#map		6
S|  chicken.base#foldr		3
o|eliminated procedure checks: 83 
o|specializations:
o|  1 (scheme#> fixnum fixnum)
o|  1 (scheme#char=? char char)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#positive? fixnum)
o|  2 (scheme#string-length string)
o|  9 (scheme#string=? string string)
o|  1 (chicken.base#current-error-port)
o|  4 (scheme#string-append string string)
o|  1 (scheme#zero? *)
o|  1 (scheme#current-output-port)
o|  2 (scheme#cdar (pair pair *))
o|  16 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  2 (scheme#number->string fixnum)
o|  1 (scheme#eqv? * *)
o|  5 (##sys#check-list (or pair list) *)
o|  39 (scheme#cdr pair)
o|  8 (scheme#car pair)
(o e)|safe calls: 498 
(o e)|assignments to immediate values: 3 
o|removed side-effect free assignment to unused variable: main#partition 
o|removed side-effect free assignment to unused variable: main#span 
o|removed side-effect free assignment to unused variable: main#drop 
o|removed side-effect free assignment to unused variable: main#split-at 
o|merged explicitly consed rest parameter: lsts187 
o|inlining procedure: k1901 
o|inlining procedure: k1916 
o|inlining procedure: k1916 
o|inlining procedure: k1901 
o|inlining procedure: k1956 
o|inlining procedure: k1956 
o|inlining procedure: k1988 
o|contracted procedure: "(mini-srfi-1.scm:77) g240249" 
o|inlining procedure: k1988 
o|inlining procedure: k2037 
o|contracted procedure: "(mini-srfi-1.scm:76) g213222" 
o|inlining procedure: k2037 
o|inlining procedure: k2080 
o|inlining procedure: k2080 
o|inlining procedure: k2111 
o|inlining procedure: k2111 
o|removed side-effect free assignment to unused variable: main#cons* 
o|removed side-effect free assignment to unused variable: main#first 
o|removed side-effect free assignment to unused variable: main#second 
o|removed side-effect free assignment to unused variable: main#third 
o|removed side-effect free assignment to unused variable: main#fourth 
o|removed side-effect free assignment to unused variable: main#fifth 
o|inlining procedure: k2272 
o|inlining procedure: k2272 
o|contracted procedure: "(mini-srfi-1.scm:123) main#delete" 
o|inlining procedure: k2197 
o|inlining procedure: k2197 
o|removed side-effect free assignment to unused variable: main#alist-cons 
o|inlining procedure: k2328 
o|inlining procedure: k2328 
o|inlining procedure: k2320 
o|inlining procedure: k2320 
o|removed side-effect free assignment to unused variable: main#filter-map 
o|removed side-effect free assignment to unused variable: main#remove 
o|removed side-effect free assignment to unused variable: main#unzip1 
o|removed side-effect free assignment to unused variable: main#last 
o|removed side-effect free assignment to unused variable: main#list-index 
o|removed side-effect free assignment to unused variable: main#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: main#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: main#lset-union/eq? 
o|removed side-effect free assignment to unused variable: main#lset-intersection/eq? 
o|inlining procedure: k2719 
o|inlining procedure: k2719 
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
o|removed side-effect free assignment to unused variable: main#default-platform 
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
o|removed side-effect free assignment to unused variable: main#validate-environment 
o|removed side-effect free assignment to unused variable: main#probe-dir 
o|removed side-effect free assignment to unused variable: main#+timestamp-file+ 
o|removed side-effect free assignment to unused variable: main#+status-file+ 
o|merged explicitly consed rest parameter: rest809812 
o|inlining procedure: k3281 
o|inlining procedure: k3281 
o|merged explicitly consed rest parameter: rest827830 
o|inlining procedure: k3305 
o|inlining procedure: k3305 
o|inlining procedure: k3323 
o|inlining procedure: k3341 
o|inlining procedure: k3341 
o|inlining procedure: k3358 
o|inlining procedure: k3358 
o|substituted constant variable: a3399 
o|substituted constant variable: a3401 
o|inlining procedure: k3323 
o|inlining procedure: k3409 
o|inlining procedure: k3409 
o|inlining procedure: k3419 
o|inlining procedure: k3437 
o|inlining procedure: k3437 
o|inlining procedure: k3454 
o|inlining procedure: k3454 
o|inlining procedure: k3484 
o|inlining procedure: k3484 
o|substituted constant variable: a3513 
o|substituted constant variable: a3515 
o|substituted constant variable: a3517 
o|inlining procedure: k3419 
o|removed side-effect free assignment to unused variable: main#get-extension-property 
o|removed side-effect free assignment to unused variable: main#get-extension-property* 
o|inlining procedure: k3615 
o|substituted constant variable: default-width937 
o|substituted constant variable: default-width937 
o|inlining procedure: k3615 
o|substituted constant variable: default-width937 
o|propagated global variable: cop938 ##sys#standard-output 
o|inlining procedure: k3692 
o|contracted procedure: "(chicken-status.scm:66) main#destination-repository" 
o|inlining procedure: k3176 
o|inlining procedure: k3176 
o|inlining procedure: k3692 
o|merged explicitly consed rest parameter: rest969971 
o|inlining procedure: k3741 
o|contracted procedure: "(chicken-status.scm:74) main#load-egg-info" 
o|inlining procedure: k3260 
o|inlining procedure: k3260 
o|contracted procedure: "(egg-information.scm:37) main#locate-egg-file" 
o|inlining procedure: k3229 
o|inlining procedure: k3229 
o|inlining procedure: k3741 
o|inlining procedure: k3781 
o|inlining procedure: k3781 
o|contracted procedure: "(chicken-status.scm:81) main#grep" 
o|propagated global variable: g963964 chicken.irregex#irregex-search 
o|contracted procedure: "(chicken-status.scm:79) main#concatenate" 
o|inlining procedure: k2169 
o|inlining procedure: k2169 
o|inlining procedure: k3822 
o|inlining procedure: k3822 
o|merged explicitly consed rest parameter: rest10611064 
o|inlining procedure: k3953 
o|inlining procedure: k3953 
o|inlining procedure: k4030 
o|inlining procedure: k4030 
o|consed rest parameter at call site: "(chicken-status.scm:122) main#format-string" 3 
o|substituted constant variable: a4104 
o|consed rest parameter at call site: "(chicken-status.scm:120) main#format-string" 3 
o|inlining procedure: k4119 
o|inlining procedure: k4119 
o|substituted constant variable: main#+version-file+ 
o|consed rest parameter at call site: "(chicken-status.scm:114) main#get-egg-property" 3 
o|consed rest parameter at call site: "(chicken-status.scm:113) main#read-info" 2 
o|consed rest parameter at call site: "(chicken-status.scm:134) main#append-map" 3 
o|inlining procedure: k4212 
o|inlining procedure: k4212 
o|inlining procedure: k4232 
o|inlining procedure: k4232 
o|inlining procedure: k4240 
o|inlining procedure: k4240 
o|inlining procedure: k4274 
o|inlining procedure: k4274 
o|inlining procedure: k4308 
o|inlining procedure: k4308 
o|inlining procedure: k4342 
o|inlining procedure: k4342 
o|substituted constant variable: a4360 
o|substituted constant variable: a4362 
o|substituted constant variable: a4364 
o|substituted constant variable: a4366 
o|substituted constant variable: a4368 
o|substituted constant variable: a4370 
o|substituted constant variable: a4372 
o|substituted constant variable: a4374 
o|substituted constant variable: a4376 
o|inlining procedure: k4397 
o|inlining procedure: k4461 
o|contracted procedure: "(chicken-status.scm:166) g11981205" 
o|inlining procedure: k4420 
o|inlining procedure: k4420 
o|substituted constant variable: a4433 
o|substituted constant variable: a4435 
o|consed rest parameter at call site: "(chicken-status.scm:169) main#format-string" 3 
o|consed rest parameter at call site: "(chicken-status.scm:168) main#format-string" 3 
o|inlining procedure: k4461 
o|inlining procedure: k4397 
o|consed rest parameter at call site: "(chicken-status.scm:160) main#format-string" 3 
o|substituted constant variable: a4496 
o|consed rest parameter at call site: "(chicken-status.scm:159) main#format-string" 3 
o|consed rest parameter at call site: "(chicken-status.scm:157) main#get-egg-property*" 3 
o|consed rest parameter at call site: "(chicken-status.scm:156) main#get-egg-property" 3 
o|consed rest parameter at call site: "(chicken-status.scm:155) main#read-info" 2 
o|inlining procedure: k4517 
o|inlining procedure: k4517 
o|inlining procedure: k4560 
o|inlining procedure: k4560 
o|consed rest parameter at call site: "(chicken-status.scm:183) main#get-egg-property*" 3 
o|consed rest parameter at call site: "(chicken-status.scm:183) main#read-info" 2 
o|consed rest parameter at call site: "(chicken-status.scm:181) main#append-map" 3 
o|inlining procedure: k4633 
o|contracted procedure: "(chicken-status.scm:188) g12501257" 
o|inlining procedure: k4614 
o|inlining procedure: k4614 
o|consed rest parameter at call site: "(chicken-status.scm:190) main#get-egg-property" 3 
o|consed rest parameter at call site: "(chicken-status.scm:190) main#read-info" 2 
o|inlining procedure: k4633 
o|contracted procedure: "(chicken-status.scm:271) main#main" 
o|inlining procedure: k4672 
o|inlining procedure: k4696 
o|contracted procedure: "(chicken-status.scm:226) main#list-cached-eggs" 
o|inlining procedure: k4139 
o|inlining procedure: k4166 
o|contracted procedure: "(chicken-status.scm:128) g11401147" 
o|substituted constant variable: main#+egg-extension+ 
o|inlining procedure: k4166 
o|inlining procedure: k4139 
o|inlining procedure: k4696 
o|contracted procedure: "(chicken-status.scm:232) main#gather-eggs" 
o|inlining procedure: k3893 
o|inlining procedure: k3893 
o|consed rest parameter at call site: "(chicken-status.scm:92) main#append-map" 3 
o|inlining procedure: k4716 
o|propagated global variable: r47175156 main#list-installed-files 
o|inlining procedure: k4716 
o|inlining procedure: k4722 
o|inlining procedure: k4722 
o|inlining procedure: k4672 
o|inlining procedure: k4737 
o|inlining procedure: k4737 
o|substituted constant variable: a4753 
o|substituted constant variable: a4764 
o|inlining procedure: k4760 
o|inlining procedure: k4760 
o|substituted constant variable: a4775 
o|substituted constant variable: a4786 
o|inlining procedure: k4782 
o|inlining procedure: k4782 
o|substituted constant variable: a4797 
o|substituted constant variable: a4811 
o|inlining procedure: k4807 
o|inlining procedure: k4807 
o|substituted constant variable: a4825 
o|inlining procedure: k4836 
o|inlining procedure: k4851 
o|inlining procedure: k4881 
o|contracted procedure: "(chicken-status.scm:265) g13361345" 
o|inlining procedure: k4881 
o|inlining procedure: k4851 
o|substituted constant variable: main#short-options 
o|substituted constant variable: a4932 
o|inlining procedure: k4836 
o|substituted constant variable: a4950 
o|substituted constant variable: a4947 
o|substituted constant variable: a4953 
o|substituted constant variable: a4955 
o|inlining procedure: k4984 
o|inlining procedure: k4984 
o|replaced variables: 630 
o|removed binding forms: 210 
o|substituted constant variable: r19175043 
o|substituted constant variable: r19575045 
o|substituted constant variable: r21125053 
o|substituted constant variable: r23215062 
o|removed side-effect free assignment to unused variable: main#list-tabulate 
o|removed side-effect free assignment to unused variable: main#+egg-extension+ 
o|removed side-effect free assignment to unused variable: main#+version-file+ 
o|removed side-effect free assignment to unused variable: main#get-extension-property/internal 
o|substituted constant variable: r36165086 
o|substituted constant variable: mode723 
o|folded constant expression: (scheme#eq? (quote target) (quote target)) 
o|substituted constant variable: r37425096 
o|substituted constant variable: r21705107 
o|substituted constant variable: r41205116 
o|substituted constant variable: r42335120 
o|substituted constant variable: r43435128 
o|substituted constant variable: r44215131 
o|substituted constant variable: r44215131 
o|inlining procedure: k4420 
o|inlining procedure: k4420 
o|substituted constant variable: r46155144 
o|substituted constant variable: r46155144 
o|removed side-effect free assignment to unused variable: main#short-options 
o|contracted procedure: "(chicken-status.scm:264) main#every" 
o|replaced variables: 65 
o|removed binding forms: 556 
o|inlining procedure: k3278 
o|inlining procedure: k3302 
o|contracted procedure: k3179 
o|inlining procedure: k3702 
o|propagated global variable: r37035287 main#target-run-repo 
o|inlining procedure: k3702 
o|propagated global variable: r37035288 main#target-repo 
o|inlining procedure: k3702 
o|inlining procedure: k3702 
o|propagated global variable: r37035290 main#host-repo 
o|inlining procedure: k4116 
o|inlining procedure: "(chicken-status.scm:235) main#usage" 
o|inlining procedure: "(chicken-status.scm:267) main#usage" 
o|inlining procedure: "(chicken-status.scm:268) main#usage" 
o|replaced variables: 3 
o|removed binding forms: 74 
o|substituted constant variable: r32795281 
o|substituted constant variable: r32795281 
o|substituted constant variable: r33035284 
o|substituted constant variable: r33035284 
o|substituted constant variable: r3180 
o|substituted constant variable: r41175301 
o|substituted constant variable: r41175301 
o|substituted constant variable: r44215217 
o|substituted constant variable: r44215219 
o|removed side-effect free assignment to unused variable: main#usage 
o|substituted constant variable: code12675317 
o|substituted constant variable: code12675324 
o|inlining procedure: "(mini-srfi-1.scm:82) a4915" 
o|substituted constant variable: code12675331 
o|replaced variables: 4 
o|removed binding forms: 10 
o|removed conditional forms: 4 
o|removed side-effect free assignment to unused variable: main#host-repo 
o|replaced variables: 2 
o|removed binding forms: 14 
o|removed binding forms: 3 
o|simplifications: ((if . 25) (let . 16) (##core#call . 194)) 
o|  call simplifications:
o|    scheme#member
o|    ##sys#size	2
o|    chicken.fixnum#fx>
o|    scheme#string->list
o|    scheme#memq
o|    scheme#string
o|    scheme#-	2
o|    scheme#quotient	2
o|    scheme#caddr
o|    scheme#eq?	12
o|    scheme#list	20
o|    scheme#string-length
o|    chicken.fixnum#fx-
o|    chicken.fixnum#fxmax
o|    scheme#string=?	2
o|    scheme#eof-object?
o|    scheme#not	2
o|    ##sys#apply
o|    ##sys#call-with-values	2
o|    scheme#list-ref
o|    scheme#assq	2
o|    scheme#cadr	9
o|    scheme#equal?
o|    scheme#null?	23
o|    scheme#car	18
o|    scheme#apply
o|    scheme#cdr	8
o|    scheme#cons	17
o|    ##sys#setslot	5
o|    ##sys#check-list	10
o|    scheme#pair?	13
o|    ##sys#slot	31
o|contracted procedure: k1904 
o|contracted procedure: k1907 
o|contracted procedure: k1919 
o|contracted procedure: k1935 
o|contracted procedure: k1943 
o|contracted procedure: k1950 
o|contracted procedure: k1974 
o|contracted procedure: k1991 
o|contracted procedure: k2013 
o|contracted procedure: k2009 
o|contracted procedure: k1994 
o|contracted procedure: k1997 
o|contracted procedure: k2005 
o|contracted procedure: k2020 
o|contracted procedure: k2028 
o|contracted procedure: k2040 
o|contracted procedure: k2062 
o|contracted procedure: k2058 
o|contracted procedure: k2043 
o|contracted procedure: k2046 
o|contracted procedure: k2054 
o|contracted procedure: k2114 
o|contracted procedure: k2129 
o|contracted procedure: k2275 
o|contracted procedure: k2278 
o|contracted procedure: k2288 
o|contracted procedure: k2200 
o|contracted procedure: k2226 
o|contracted procedure: k2311 
o|contracted procedure: k2323 
o|contracted procedure: k2341 
o|contracted procedure: k2349 
o|contracted procedure: k5012 
o|contracted procedure: k3046 
o|contracted procedure: k3287 
o|contracted procedure: k3272 
o|contracted procedure: k3275 
o|contracted procedure: k3278 
o|contracted procedure: k3311 
o|contracted procedure: k3296 
o|contracted procedure: k3299 
o|contracted procedure: k3302 
o|contracted procedure: k4970 
o|contracted procedure: k3686 
o|contracted procedure: k3695 
o|contracted procedure: k3191 
o|contracted procedure: k3173 
o|contracted procedure: k3763 
o|contracted procedure: k3729 
o|contracted procedure: k3757 
o|contracted procedure: k3732 
o|contracted procedure: k3751 
o|contracted procedure: k3735 
o|contracted procedure: k3254 
o|contracted procedure: k3263 
o|contracted procedure: k3769 
o|contracted procedure: k3787 
o|contracted procedure: k3797 
o|contracted procedure: k3813 
o|contracted procedure: k2172 
o|contracted procedure: k2179 
o|contracted procedure: k3825 
o|contracted procedure: k3828 
o|contracted procedure: k3831 
o|contracted procedure: k3839 
o|contracted procedure: k3847 
o|contracted procedure: k3992 
o|contracted procedure: k3935 
o|contracted procedure: k3986 
o|contracted procedure: k3938 
o|contracted procedure: k3980 
o|contracted procedure: k3941 
o|contracted procedure: k3974 
o|contracted procedure: k3944 
o|contracted procedure: k3947 
o|contracted procedure: k3971 
o|contracted procedure: k3967 
o|contracted procedure: k4062 
o|contracted procedure: k4004 
o|contracted procedure: k4056 
o|contracted procedure: k4007 
o|contracted procedure: k4050 
o|contracted procedure: k4010 
o|contracted procedure: k4021 
o|contracted procedure: k4033 
o|contracted procedure: k4043 
o|contracted procedure: k4047 
o|contracted procedure: k4068 
o|contracted procedure: k4130 
o|contracted procedure: k4209 
o|contracted procedure: k4215 
o|contracted procedure: k4229 
o|contracted procedure: k4243 
o|contracted procedure: k4254 
o|contracted procedure: k4250 
o|contracted procedure: k4260 
o|contracted procedure: k4271 
o|contracted procedure: k4267 
o|contracted procedure: k4277 
o|contracted procedure: k4288 
o|contracted procedure: k4284 
o|contracted procedure: k4294 
o|contracted procedure: k4305 
o|contracted procedure: k4301 
o|contracted procedure: k4311 
o|contracted procedure: k4322 
o|contracted procedure: k4318 
o|contracted procedure: k4328 
o|contracted procedure: k4339 
o|contracted procedure: k4335 
o|contracted procedure: k4345 
o|contracted procedure: k4356 
o|contracted procedure: k4352 
o|contracted procedure: k4538 
o|contracted procedure: k4380 
o|contracted procedure: k4452 
o|contracted procedure: k4464 
o|contracted procedure: k4474 
o|contracted procedure: k4478 
o|contracted procedure: k4417 
o|contracted procedure: k4423 
o|contracted procedure: k4429 
o|contracted procedure: k4441 
o|contracted procedure: k4449 
o|contracted procedure: k4508 
o|contracted procedure: k4520 
o|contracted procedure: k4530 
o|contracted procedure: k4534 
o|contracted procedure: k4551 
o|contracted procedure: k4563 
o|contracted procedure: k4573 
o|contracted procedure: k4577 
o|contracted procedure: k4624 
o|contracted procedure: k4636 
o|contracted procedure: k4646 
o|contracted procedure: k4650 
o|contracted procedure: k4614 
o|inlining procedure: k4606 
o|inlining procedure: k4606 
o|contracted procedure: k4675 
o|contracted procedure: k4157 
o|contracted procedure: k4169 
o|contracted procedure: k4179 
o|contracted procedure: k4183 
o|contracted procedure: k3881 
o|contracted procedure: k3896 
o|contracted procedure: k3899 
o|contracted procedure: k3902 
o|contracted procedure: k3910 
o|contracted procedure: k3918 
o|contracted procedure: k4725 
o|contracted procedure: k4731 
o|contracted procedure: k4740 
o|contracted procedure: k4798 
o|contracted procedure: k4812 
o|contracted procedure: k4944 
o|contracted procedure: k4839 
o|contracted procedure: k4929 
o|contracted procedure: k4845 
o|contracted procedure: k4865 
o|contracted procedure: k4884 
o|contracted procedure: k4906 
o|contracted procedure: k4902 
o|contracted procedure: k4887 
o|contracted procedure: k4890 
o|contracted procedure: k4898 
o|contracted procedure: k2077 
o|contracted procedure: k2099 
o|contracted procedure: k2095 
o|contracted procedure: k2086 
o|contracted procedure: k4940 
o|contracted procedure: k5026 
o|contracted procedure: k5030 
o|contracted procedure: k5034 
o|contracted procedure: k5038 
o|simplifications: ((if . 1) (let . 50)) 
o|removed binding forms: 173 
o|substituted constant variable: r5027 
o|substituted constant variable: r5031 
o|substituted constant variable: r5035 
o|substituted constant variable: r5039 
o|replaced variables: 3 
o|removed binding forms: 1 
o|removed binding forms: 5 
o|direct leaf routine/allocation: main#get-egg-property 0 
o|direct leaf routine/allocation: main#get-egg-property* 0 
o|direct leaf routine/allocation: loop263 0 
o|contracted procedure: "(chicken-status.scm:156) k4388" 
o|contracted procedure: "(chicken-status.scm:157) k4391" 
o|contracted procedure: "(chicken-status.scm:190) k4599" 
o|contracted procedure: k4854 
o|converted assignments to bindings: (loop263) 
o|simplifications: ((let . 1) (if . 1)) 
o|removed binding forms: 4 
o|contracted procedure: "(chicken-status.scm:114) k4083" 
o|removed binding forms: 1 
o|customizable procedures: (map-loop13301355 loop1277 k4681 k4702 map-loop10331050 main#filter-egg-names for-each-loop11391150 for-each-loop12491261 for-each-loop12291240 main#get-terminal-width g11811188 for-each-loop11801220 for-each-loop11971214 main#gather-components main#append-map main#read-info k4086 main#format-string g10971104 for-each-loop10961114 g10011010 map-loop9951013 loop295 main#filter main#delete-duplicates main#repo-path foldr339342 g344345 loop302 loop322 loop276 main#any map-loop207225 map-loop234252 loop203 foldr192195 g197198) 
o|calls to known targets: 97 
o|identified direct recursive calls: f_1914 1 
o|identified direct recursive calls: f_1986 1 
o|identified direct recursive calls: f_2035 1 
o|identified direct recursive calls: f_2318 1 
o|identified direct recursive calls: f_2167 1 
o|identified direct recursive calls: f_2075 1 
o|identified direct recursive calls: f_4879 1 
o|identified direct recursive calls: f_4670 8 
o|fast box initializations: 19 
o|fast global references: 74 
o|fast global assignments: 38 
o|dropping unused closure argument: f_1899 
o|dropping unused closure argument: f_2075 
o|dropping unused closure argument: f_2103 
o|dropping unused closure argument: f_2264 
o|dropping unused closure argument: f_2309 
o|dropping unused closure argument: f_3270 
o|dropping unused closure argument: f_3294 
o|dropping unused closure argument: f_3613 
o|dropping unused closure argument: f_3690 
o|dropping unused closure argument: f_3724 
o|dropping unused closure argument: f_3779 
o|dropping unused closure argument: f_3933 
o|dropping unused closure argument: f_4195 
*/
/* end of file */
