/* Generated from csc.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: csc.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -output-file csc.c
   uses: eval data-structures posix pathname extras file library
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
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externimport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[441];
static double C_possibly_force_alignment;


C_noret_decl(f8470)
static void C_ccall f8470(C_word c,C_word *av) C_noret;
C_noret_decl(f8476)
static void C_ccall f8476(C_word c,C_word *av) C_noret;
C_noret_decl(f8480)
static void C_ccall f8480(C_word c,C_word *av) C_noret;
C_noret_decl(f8512)
static void C_ccall f8512(C_word c,C_word *av) C_noret;
C_noret_decl(f8556)
static void C_ccall f8556(C_word c,C_word *av) C_noret;
C_noret_decl(f_2237)
static void C_ccall f_2237(C_word c,C_word *av) C_noret;
C_noret_decl(f_2240)
static void C_ccall f_2240(C_word c,C_word *av) C_noret;
C_noret_decl(f_2243)
static void C_ccall f_2243(C_word c,C_word *av) C_noret;
C_noret_decl(f_2246)
static void C_ccall f_2246(C_word c,C_word *av) C_noret;
C_noret_decl(f_2249)
static void C_ccall f_2249(C_word c,C_word *av) C_noret;
C_noret_decl(f_2252)
static void C_ccall f_2252(C_word c,C_word *av) C_noret;
C_noret_decl(f_2255)
static void C_ccall f_2255(C_word c,C_word *av) C_noret;
C_noret_decl(f_2258)
static void C_ccall f_2258(C_word c,C_word *av) C_noret;
C_noret_decl(f_2264)
static void C_ccall f_2264(C_word c,C_word *av) C_noret;
C_noret_decl(f_2270)
static void C_ccall f_2270(C_word c,C_word *av) C_noret;
C_noret_decl(f_2274)
static void C_ccall f_2274(C_word c,C_word *av) C_noret;
C_noret_decl(f_2278)
static void C_ccall f_2278(C_word c,C_word *av) C_noret;
C_noret_decl(f_2282)
static void C_ccall f_2282(C_word c,C_word *av) C_noret;
C_noret_decl(f_2286)
static void C_ccall f_2286(C_word c,C_word *av) C_noret;
C_noret_decl(f_2290)
static void C_ccall f_2290(C_word c,C_word *av) C_noret;
C_noret_decl(f_2294)
static void C_ccall f_2294(C_word c,C_word *av) C_noret;
C_noret_decl(f_2298)
static void C_ccall f_2298(C_word c,C_word *av) C_noret;
C_noret_decl(f_2302)
static void C_ccall f_2302(C_word c,C_word *av) C_noret;
C_noret_decl(f_2306)
static void C_ccall f_2306(C_word c,C_word *av) C_noret;
C_noret_decl(f_2310)
static void C_ccall f_2310(C_word c,C_word *av) C_noret;
C_noret_decl(f_2314)
static void C_ccall f_2314(C_word c,C_word *av) C_noret;
C_noret_decl(f_2318)
static void C_ccall f_2318(C_word c,C_word *av) C_noret;
C_noret_decl(f_2322)
static void C_ccall f_2322(C_word c,C_word *av) C_noret;
C_noret_decl(f_2326)
static void C_ccall f_2326(C_word c,C_word *av) C_noret;
C_noret_decl(f_2334)
static void C_ccall f_2334(C_word c,C_word *av) C_noret;
C_noret_decl(f_2338)
static void C_ccall f_2338(C_word c,C_word *av) C_noret;
C_noret_decl(f_2342)
static void C_ccall f_2342(C_word c,C_word *av) C_noret;
C_noret_decl(f_2346)
static void C_ccall f_2346(C_word c,C_word *av) C_noret;
C_noret_decl(f_2350)
static void C_ccall f_2350(C_word c,C_word *av) C_noret;
C_noret_decl(f_2354)
static void C_ccall f_2354(C_word c,C_word *av) C_noret;
C_noret_decl(f_2358)
static void C_ccall f_2358(C_word c,C_word *av) C_noret;
C_noret_decl(f_2362)
static void C_ccall f_2362(C_word c,C_word *av) C_noret;
C_noret_decl(f_2366)
static void C_ccall f_2366(C_word c,C_word *av) C_noret;
C_noret_decl(f_2370)
static void C_ccall f_2370(C_word c,C_word *av) C_noret;
C_noret_decl(f_2374)
static void C_ccall f_2374(C_word c,C_word *av) C_noret;
C_noret_decl(f_2378)
static void C_ccall f_2378(C_word c,C_word *av) C_noret;
C_noret_decl(f_2382)
static void C_ccall f_2382(C_word c,C_word *av) C_noret;
C_noret_decl(f_2386)
static void C_ccall f_2386(C_word c,C_word *av) C_noret;
C_noret_decl(f_2390)
static void C_ccall f_2390(C_word c,C_word *av) C_noret;
C_noret_decl(f_2394)
static void C_ccall f_2394(C_word c,C_word *av) C_noret;
C_noret_decl(f_2398)
static void C_ccall f_2398(C_word c,C_word *av) C_noret;
C_noret_decl(f_2402)
static void C_ccall f_2402(C_word c,C_word *av) C_noret;
C_noret_decl(f_2406)
static void C_ccall f_2406(C_word c,C_word *av) C_noret;
C_noret_decl(f_2410)
static void C_ccall f_2410(C_word c,C_word *av) C_noret;
C_noret_decl(f_2494)
static void C_ccall f_2494(C_word c,C_word *av) C_noret;
C_noret_decl(f_2497)
static void C_ccall f_2497(C_word c,C_word *av) C_noret;
C_noret_decl(f_2501)
static void C_ccall f_2501(C_word c,C_word *av) C_noret;
C_noret_decl(f_2939)
static void C_fcall f_2939(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2945)
static void C_fcall f_2945(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2959)
static void C_ccall f_2959(C_word c,C_word *av) C_noret;
C_noret_decl(f_3001)
static void C_fcall f_3001(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3028)
static void C_ccall f_3028(C_word c,C_word *av) C_noret;
C_noret_decl(f_3076)
static void C_fcall f_3076(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3090)
static void C_ccall f_3090(C_word c,C_word *av) C_noret;
C_noret_decl(f_3103)
static void C_ccall f_3103(C_word c,C_word *av) C_noret;
C_noret_decl(f_3124)
static void C_fcall f_3124(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3132)
static C_word C_fcall f_3132(C_word *a,C_word t0,C_word t1,C_word t2);
C_noret_decl(f_3153)
static void C_ccall f_3153(C_word c,C_word *av) C_noret;
C_noret_decl(f_3168)
static void C_fcall f_3168(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3180)
static void C_ccall f_3180(C_word c,C_word *av) C_noret;
C_noret_decl(f_3184)
static C_word C_fcall f_3184(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_3202)
static void C_ccall f_3202(C_word c,C_word *av) C_noret;
C_noret_decl(f_3281)
static C_word C_fcall f_3281(C_word t0);
C_noret_decl(f_3381)
static void C_fcall f_3381(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3403)
static C_word C_fcall f_3403(C_word t0,C_word t1);
C_noret_decl(f_3414)
static void C_ccall f_3414(C_word c,C_word *av) C_noret;
C_noret_decl(f_3786)
static void C_ccall f_3786(C_word c,C_word *av) C_noret;
C_noret_decl(f_3812)
static void C_ccall f_3812(C_word c,C_word *av) C_noret;
C_noret_decl(f_3818)
static void C_ccall f_3818(C_word c,C_word *av) C_noret;
C_noret_decl(f_3821)
static void C_fcall f_3821(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3828)
static void C_ccall f_3828(C_word c,C_word *av) C_noret;
C_noret_decl(f_3831)
static void C_ccall f_3831(C_word c,C_word *av) C_noret;
C_noret_decl(f_3834)
static void C_ccall f_3834(C_word c,C_word *av) C_noret;
C_noret_decl(f_3837)
static void C_ccall f_3837(C_word c,C_word *av) C_noret;
C_noret_decl(f_3844)
static void C_ccall f_3844(C_word c,C_word *av) C_noret;
C_noret_decl(f_3848)
static void C_ccall f_3848(C_word c,C_word *av) C_noret;
C_noret_decl(f_3852)
static void C_ccall f_3852(C_word c,C_word *av) C_noret;
C_noret_decl(f_3870)
static void C_ccall f_3870(C_word c,C_word *av) C_noret;
C_noret_decl(f_3878)
static void C_ccall f_3878(C_word c,C_word *av) C_noret;
C_noret_decl(f_3882)
static void C_ccall f_3882(C_word c,C_word *av) C_noret;
C_noret_decl(f_3884)
static void C_ccall f_3884(C_word c,C_word *av) C_noret;
C_noret_decl(f_3892)
static void C_ccall f_3892(C_word c,C_word *av) C_noret;
C_noret_decl(f_3900)
static void C_ccall f_3900(C_word c,C_word *av) C_noret;
C_noret_decl(f_3904)
static void C_ccall f_3904(C_word c,C_word *av) C_noret;
C_noret_decl(f_3908)
static void C_ccall f_3908(C_word c,C_word *av) C_noret;
C_noret_decl(f_3912)
static void C_ccall f_3912(C_word c,C_word *av) C_noret;
C_noret_decl(f_3916)
static void C_ccall f_3916(C_word c,C_word *av) C_noret;
C_noret_decl(f_3920)
static void C_ccall f_3920(C_word c,C_word *av) C_noret;
C_noret_decl(f_3933)
static void C_ccall f_3933(C_word c,C_word *av) C_noret;
C_noret_decl(f_3937)
static void C_ccall f_3937(C_word c,C_word *av) C_noret;
C_noret_decl(f_3942)
static void C_fcall f_3942(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3945)
static void C_fcall f_3945(C_word t0) C_noret;
C_noret_decl(f_3953)
static void C_ccall f_3953(C_word c,C_word *av) C_noret;
C_noret_decl(f_3988)
static void C_ccall f_3988(C_word c,C_word *av) C_noret;
C_noret_decl(f_3992)
static void C_ccall f_3992(C_word c,C_word *av) C_noret;
C_noret_decl(f_3997)
static void C_ccall f_3997(C_word c,C_word *av) C_noret;
C_noret_decl(f_4002)
static void C_ccall f_4002(C_word c,C_word *av) C_noret;
C_noret_decl(f_4009)
static void C_ccall f_4009(C_word c,C_word *av) C_noret;
C_noret_decl(f_4039)
static void C_ccall f_4039(C_word c,C_word *av) C_noret;
C_noret_decl(f_4053)
static void C_ccall f_4053(C_word c,C_word *av) C_noret;
C_noret_decl(f_4057)
static void C_ccall f_4057(C_word c,C_word *av) C_noret;
C_noret_decl(f_4073)
static void C_ccall f_4073(C_word c,C_word *av) C_noret;
C_noret_decl(f_4092)
static void C_ccall f_4092(C_word c,C_word *av) C_noret;
C_noret_decl(f_4111)
static void C_fcall f_4111(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4115)
static void C_fcall f_4115(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4119)
static void C_ccall f_4119(C_word c,C_word *av) C_noret;
C_noret_decl(f_4122)
static void C_ccall f_4122(C_word c,C_word *av) C_noret;
C_noret_decl(f_4135)
static void C_ccall f_4135(C_word c,C_word *av) C_noret;
C_noret_decl(f_4140)
static void C_fcall f_4140(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4165)
static void C_ccall f_4165(C_word c,C_word *av) C_noret;
C_noret_decl(f_4185)
static void C_ccall f_4185(C_word c,C_word *av) C_noret;
C_noret_decl(f_4193)
static void C_ccall f_4193(C_word c,C_word *av) C_noret;
C_noret_decl(f_4197)
static void C_ccall f_4197(C_word c,C_word *av) C_noret;
C_noret_decl(f_4201)
static void C_ccall f_4201(C_word c,C_word *av) C_noret;
C_noret_decl(f_4217)
static void C_ccall f_4217(C_word c,C_word *av) C_noret;
C_noret_decl(f_4224)
static void C_ccall f_4224(C_word c,C_word *av) C_noret;
C_noret_decl(f_4234)
static void C_fcall f_4234(C_word t0) C_noret;
C_noret_decl(f_4246)
static void C_ccall f_4246(C_word c,C_word *av) C_noret;
C_noret_decl(f_4250)
static void C_ccall f_4250(C_word c,C_word *av) C_noret;
C_noret_decl(f_4253)
static void C_ccall f_4253(C_word c,C_word *av) C_noret;
C_noret_decl(f_4256)
static void C_ccall f_4256(C_word c,C_word *av) C_noret;
C_noret_decl(f_4259)
static void C_ccall f_4259(C_word c,C_word *av) C_noret;
C_noret_decl(f_4262)
static void C_ccall f_4262(C_word c,C_word *av) C_noret;
C_noret_decl(f_4268)
static void C_ccall f_4268(C_word c,C_word *av) C_noret;
C_noret_decl(f_4274)
static void C_ccall f_4274(C_word c,C_word *av) C_noret;
C_noret_decl(f_4286)
static void C_ccall f_4286(C_word c,C_word *av) C_noret;
C_noret_decl(f_4296)
static void C_ccall f_4296(C_word c,C_word *av) C_noret;
C_noret_decl(f_4300)
static void C_ccall f_4300(C_word c,C_word *av) C_noret;
C_noret_decl(f_4306)
static void C_ccall f_4306(C_word c,C_word *av) C_noret;
C_noret_decl(f_4318)
static void C_ccall f_4318(C_word c,C_word *av) C_noret;
C_noret_decl(f_4325)
static void C_ccall f_4325(C_word c,C_word *av) C_noret;
C_noret_decl(f_4358)
static void C_fcall f_4358(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4363)
static void C_ccall f_4363(C_word c,C_word *av) C_noret;
C_noret_decl(f_4365)
static void C_fcall f_4365(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4391)
static void C_fcall f_4391(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4396)
static void C_ccall f_4396(C_word c,C_word *av) C_noret;
C_noret_decl(f_4400)
static void C_ccall f_4400(C_word c,C_word *av) C_noret;
C_noret_decl(f_4404)
static void C_ccall f_4404(C_word c,C_word *av) C_noret;
C_noret_decl(f_4421)
static void C_fcall f_4421(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4437)
static void C_fcall f_4437(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4448)
static void C_ccall f_4448(C_word c,C_word *av) C_noret;
C_noret_decl(f_4452)
static void C_ccall f_4452(C_word c,C_word *av) C_noret;
C_noret_decl(f_4455)
static void C_ccall f_4455(C_word c,C_word *av) C_noret;
C_noret_decl(f_4458)
static void C_ccall f_4458(C_word c,C_word *av) C_noret;
C_noret_decl(f_4461)
static void C_ccall f_4461(C_word c,C_word *av) C_noret;
C_noret_decl(f_4467)
static void C_ccall f_4467(C_word c,C_word *av) C_noret;
C_noret_decl(f_4473)
static void C_fcall f_4473(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4476)
static void C_ccall f_4476(C_word c,C_word *av) C_noret;
C_noret_decl(f_4488)
static void C_ccall f_4488(C_word c,C_word *av) C_noret;
C_noret_decl(f_4491)
static void C_ccall f_4491(C_word c,C_word *av) C_noret;
C_noret_decl(f_4494)
static void C_ccall f_4494(C_word c,C_word *av) C_noret;
C_noret_decl(f_4497)
static void C_ccall f_4497(C_word c,C_word *av) C_noret;
C_noret_decl(f_4500)
static void C_ccall f_4500(C_word c,C_word *av) C_noret;
C_noret_decl(f_4503)
static void C_ccall f_4503(C_word c,C_word *av) C_noret;
C_noret_decl(f_4510)
static void C_ccall f_4510(C_word c,C_word *av) C_noret;
C_noret_decl(f_4516)
static void C_ccall f_4516(C_word c,C_word *av) C_noret;
C_noret_decl(f_4519)
static void C_ccall f_4519(C_word c,C_word *av) C_noret;
C_noret_decl(f_4522)
static void C_ccall f_4522(C_word c,C_word *av) C_noret;
C_noret_decl(f_4525)
static void C_ccall f_4525(C_word c,C_word *av) C_noret;
C_noret_decl(f_4528)
static void C_ccall f_4528(C_word c,C_word *av) C_noret;
C_noret_decl(f_4531)
static void C_ccall f_4531(C_word c,C_word *av) C_noret;
C_noret_decl(f_4538)
static void C_ccall f_4538(C_word c,C_word *av) C_noret;
C_noret_decl(f_4542)
static void C_ccall f_4542(C_word c,C_word *av) C_noret;
C_noret_decl(f_4560)
static void C_ccall f_4560(C_word c,C_word *av) C_noret;
C_noret_decl(f_4564)
static void C_ccall f_4564(C_word c,C_word *av) C_noret;
C_noret_decl(f_4570)
static void C_ccall f_4570(C_word c,C_word *av) C_noret;
C_noret_decl(f_4577)
static void C_ccall f_4577(C_word c,C_word *av) C_noret;
C_noret_decl(f_4594)
static void C_ccall f_4594(C_word c,C_word *av) C_noret;
C_noret_decl(f_4604)
static void C_ccall f_4604(C_word c,C_word *av) C_noret;
C_noret_decl(f_4608)
static void C_ccall f_4608(C_word c,C_word *av) C_noret;
C_noret_decl(f_4617)
static void C_fcall f_4617(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4620)
static void C_fcall f_4620(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4627)
static void C_ccall f_4627(C_word c,C_word *av) C_noret;
C_noret_decl(f_4660)
static void C_ccall f_4660(C_word c,C_word *av) C_noret;
C_noret_decl(f_4663)
static void C_ccall f_4663(C_word c,C_word *av) C_noret;
C_noret_decl(f_4666)
static void C_ccall f_4666(C_word c,C_word *av) C_noret;
C_noret_decl(f_4669)
static void C_ccall f_4669(C_word c,C_word *av) C_noret;
C_noret_decl(f_4679)
static void C_ccall f_4679(C_word c,C_word *av) C_noret;
C_noret_decl(f_4686)
static void C_ccall f_4686(C_word c,C_word *av) C_noret;
C_noret_decl(f_4693)
static void C_ccall f_4693(C_word c,C_word *av) C_noret;
C_noret_decl(f_4697)
static void C_ccall f_4697(C_word c,C_word *av) C_noret;
C_noret_decl(f_4704)
static void C_ccall f_4704(C_word c,C_word *av) C_noret;
C_noret_decl(f_4707)
static void C_ccall f_4707(C_word c,C_word *av) C_noret;
C_noret_decl(f_4719)
static void C_ccall f_4719(C_word c,C_word *av) C_noret;
C_noret_decl(f_4731)
static void C_ccall f_4731(C_word c,C_word *av) C_noret;
C_noret_decl(f_4738)
static void C_ccall f_4738(C_word c,C_word *av) C_noret;
C_noret_decl(f_4747)
static void C_ccall f_4747(C_word c,C_word *av) C_noret;
C_noret_decl(f_4754)
static void C_ccall f_4754(C_word c,C_word *av) C_noret;
C_noret_decl(f_4760)
static void C_ccall f_4760(C_word c,C_word *av) C_noret;
C_noret_decl(f_4763)
static void C_ccall f_4763(C_word c,C_word *av) C_noret;
C_noret_decl(f_4766)
static void C_ccall f_4766(C_word c,C_word *av) C_noret;
C_noret_decl(f_4769)
static void C_ccall f_4769(C_word c,C_word *av) C_noret;
C_noret_decl(f_4826)
static void C_ccall f_4826(C_word c,C_word *av) C_noret;
C_noret_decl(f_4838)
static void C_ccall f_4838(C_word c,C_word *av) C_noret;
C_noret_decl(f_4850)
static void C_ccall f_4850(C_word c,C_word *av) C_noret;
C_noret_decl(f_4862)
static void C_ccall f_4862(C_word c,C_word *av) C_noret;
C_noret_decl(f_4885)
static void C_fcall f_4885(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4888)
static void C_ccall f_4888(C_word c,C_word *av) C_noret;
C_noret_decl(f_4900)
static void C_ccall f_4900(C_word c,C_word *av) C_noret;
C_noret_decl(f_4990)
static void C_ccall f_4990(C_word c,C_word *av) C_noret;
C_noret_decl(f_4993)
static void C_ccall f_4993(C_word c,C_word *av) C_noret;
C_noret_decl(f_4997)
static void C_ccall f_4997(C_word c,C_word *av) C_noret;
C_noret_decl(f_5005)
static void C_ccall f_5005(C_word c,C_word *av) C_noret;
C_noret_decl(f_5022)
static void C_ccall f_5022(C_word c,C_word *av) C_noret;
C_noret_decl(f_5042)
static void C_ccall f_5042(C_word c,C_word *av) C_noret;
C_noret_decl(f_5045)
static void C_ccall f_5045(C_word c,C_word *av) C_noret;
C_noret_decl(f_5111)
static void C_ccall f_5111(C_word c,C_word *av) C_noret;
C_noret_decl(f_5115)
static void C_ccall f_5115(C_word c,C_word *av) C_noret;
C_noret_decl(f_5131)
static void C_ccall f_5131(C_word c,C_word *av) C_noret;
C_noret_decl(f_5142)
static void C_ccall f_5142(C_word c,C_word *av) C_noret;
C_noret_decl(f_5158)
static void C_ccall f_5158(C_word c,C_word *av) C_noret;
C_noret_decl(f_5179)
static void C_ccall f_5179(C_word c,C_word *av) C_noret;
C_noret_decl(f_5189)
static void C_ccall f_5189(C_word c,C_word *av) C_noret;
C_noret_decl(f_5199)
static void C_ccall f_5199(C_word c,C_word *av) C_noret;
C_noret_decl(f_5209)
static void C_ccall f_5209(C_word c,C_word *av) C_noret;
C_noret_decl(f_5219)
static void C_ccall f_5219(C_word c,C_word *av) C_noret;
C_noret_decl(f_5229)
static void C_ccall f_5229(C_word c,C_word *av) C_noret;
C_noret_decl(f_5239)
static void C_ccall f_5239(C_word c,C_word *av) C_noret;
C_noret_decl(f_5249)
static void C_ccall f_5249(C_word c,C_word *av) C_noret;
C_noret_decl(f_5259)
static void C_ccall f_5259(C_word c,C_word *av) C_noret;
C_noret_decl(f_5269)
static void C_ccall f_5269(C_word c,C_word *av) C_noret;
C_noret_decl(f_5278)
static void C_ccall f_5278(C_word c,C_word *av) C_noret;
C_noret_decl(f_5281)
static void C_ccall f_5281(C_word c,C_word *av) C_noret;
C_noret_decl(f_5293)
static void C_ccall f_5293(C_word c,C_word *av) C_noret;
C_noret_decl(f_5320)
static void C_fcall f_5320(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5344)
static void C_ccall f_5344(C_word c,C_word *av) C_noret;
C_noret_decl(f_5361)
static void C_ccall f_5361(C_word c,C_word *av) C_noret;
C_noret_decl(f_5378)
static void C_ccall f_5378(C_word c,C_word *av) C_noret;
C_noret_decl(f_5395)
static void C_ccall f_5395(C_word c,C_word *av) C_noret;
C_noret_decl(f_5412)
static void C_ccall f_5412(C_word c,C_word *av) C_noret;
C_noret_decl(f_5416)
static void C_ccall f_5416(C_word c,C_word *av) C_noret;
C_noret_decl(f_5433)
static void C_ccall f_5433(C_word c,C_word *av) C_noret;
C_noret_decl(f_5437)
static void C_ccall f_5437(C_word c,C_word *av) C_noret;
C_noret_decl(f_5445)
static void C_ccall f_5445(C_word c,C_word *av) C_noret;
C_noret_decl(f_5459)
static void C_ccall f_5459(C_word c,C_word *av) C_noret;
C_noret_decl(f_5472)
static void C_ccall f_5472(C_word c,C_word *av) C_noret;
C_noret_decl(f_5476)
static void C_ccall f_5476(C_word c,C_word *av) C_noret;
C_noret_decl(f_5484)
static void C_ccall f_5484(C_word c,C_word *av) C_noret;
C_noret_decl(f_5497)
static void C_ccall f_5497(C_word c,C_word *av) C_noret;
C_noret_decl(f_5511)
static void C_fcall f_5511(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5515)
static void C_ccall f_5515(C_word c,C_word *av) C_noret;
C_noret_decl(f_5523)
static void C_ccall f_5523(C_word c,C_word *av) C_noret;
C_noret_decl(f_5527)
static void C_ccall f_5527(C_word c,C_word *av) C_noret;
C_noret_decl(f_5552)
static void C_ccall f_5552(C_word c,C_word *av) C_noret;
C_noret_decl(f_5555)
static void C_ccall f_5555(C_word c,C_word *av) C_noret;
C_noret_decl(f_5572)
static void C_ccall f_5572(C_word c,C_word *av) C_noret;
C_noret_decl(f_5575)
static void C_ccall f_5575(C_word c,C_word *av) C_noret;
C_noret_decl(f_5593)
static void C_ccall f_5593(C_word c,C_word *av) C_noret;
C_noret_decl(f_5600)
static void C_ccall f_5600(C_word c,C_word *av) C_noret;
C_noret_decl(f_5603)
static void C_fcall f_5603(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5606)
static void C_fcall f_5606(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5613)
static C_word C_fcall f_5613(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_5643)
static void C_ccall f_5643(C_word c,C_word *av) C_noret;
C_noret_decl(f_5646)
static void C_ccall f_5646(C_word c,C_word *av) C_noret;
C_noret_decl(f_5660)
static void C_fcall f_5660(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5679)
static void C_ccall f_5679(C_word c,C_word *av) C_noret;
C_noret_decl(f_5683)
static void C_ccall f_5683(C_word c,C_word *av) C_noret;
C_noret_decl(f_5706)
static void C_ccall f_5706(C_word c,C_word *av) C_noret;
C_noret_decl(f_5710)
static void C_ccall f_5710(C_word c,C_word *av) C_noret;
C_noret_decl(f_5737)
static void C_ccall f_5737(C_word c,C_word *av) C_noret;
C_noret_decl(f_5751)
static void C_ccall f_5751(C_word c,C_word *av) C_noret;
C_noret_decl(f_5761)
static void C_fcall f_5761(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5765)
static void C_ccall f_5765(C_word c,C_word *av) C_noret;
C_noret_decl(f_5788)
static void C_ccall f_5788(C_word c,C_word *av) C_noret;
C_noret_decl(f_5805)
static void C_ccall f_5805(C_word c,C_word *av) C_noret;
C_noret_decl(f_5807)
static void C_fcall f_5807(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5832)
static void C_ccall f_5832(C_word c,C_word *av) C_noret;
C_noret_decl(f_5859)
static void C_ccall f_5859(C_word c,C_word *av) C_noret;
C_noret_decl(f_5863)
static void C_ccall f_5863(C_word c,C_word *av) C_noret;
C_noret_decl(f_5880)
static void C_ccall f_5880(C_word c,C_word *av) C_noret;
C_noret_decl(f_5892)
static void C_ccall f_5892(C_word c,C_word *av) C_noret;
C_noret_decl(f_5897)
static void C_ccall f_5897(C_word c,C_word *av) C_noret;
C_noret_decl(f_5903)
static void C_ccall f_5903(C_word c,C_word *av) C_noret;
C_noret_decl(f_5914)
static void C_ccall f_5914(C_word c,C_word *av) C_noret;
C_noret_decl(f_5928)
static void C_ccall f_5928(C_word c,C_word *av) C_noret;
C_noret_decl(f_5942)
static void C_ccall f_5942(C_word c,C_word *av) C_noret;
C_noret_decl(f_5955)
static void C_fcall f_5955(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5960)
static void C_ccall f_5960(C_word c,C_word *av) C_noret;
C_noret_decl(f_5979)
static void C_ccall f_5979(C_word c,C_word *av) C_noret;
C_noret_decl(f_5991)
static void C_fcall f_5991(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5995)
static void C_ccall f_5995(C_word c,C_word *av) C_noret;
C_noret_decl(f_6003)
static void C_ccall f_6003(C_word c,C_word *av) C_noret;
C_noret_decl(f_6012)
static void C_ccall f_6012(C_word c,C_word *av) C_noret;
C_noret_decl(f_6018)
static void C_ccall f_6018(C_word c,C_word *av) C_noret;
C_noret_decl(f_6048)
static void C_ccall f_6048(C_word c,C_word *av) C_noret;
C_noret_decl(f_6255)
static void C_ccall f_6255(C_word c,C_word *av) C_noret;
C_noret_decl(f_6258)
static void C_ccall f_6258(C_word c,C_word *av) C_noret;
C_noret_decl(f_6261)
static void C_ccall f_6261(C_word c,C_word *av) C_noret;
C_noret_decl(f_6264)
static void C_fcall f_6264(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6268)
static void C_ccall f_6268(C_word c,C_word *av) C_noret;
C_noret_decl(f_6272)
static void C_ccall f_6272(C_word c,C_word *av) C_noret;
C_noret_decl(f_6291)
static void C_ccall f_6291(C_word c,C_word *av) C_noret;
C_noret_decl(f_6295)
static void C_ccall f_6295(C_word c,C_word *av) C_noret;
C_noret_decl(f_6299)
static void C_ccall f_6299(C_word c,C_word *av) C_noret;
C_noret_decl(f_6303)
static void C_ccall f_6303(C_word c,C_word *av) C_noret;
C_noret_decl(f_6307)
static void C_ccall f_6307(C_word c,C_word *av) C_noret;
C_noret_decl(f_6311)
static void C_fcall f_6311(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6322)
static void C_ccall f_6322(C_word c,C_word *av) C_noret;
C_noret_decl(f_6328)
static void C_ccall f_6328(C_word c,C_word *av) C_noret;
C_noret_decl(f_6330)
static void C_fcall f_6330(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6355)
static void C_ccall f_6355(C_word c,C_word *av) C_noret;
C_noret_decl(f_6366)
static void C_fcall f_6366(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6383)
static void C_ccall f_6383(C_word c,C_word *av) C_noret;
C_noret_decl(f_6397)
static void C_ccall f_6397(C_word c,C_word *av) C_noret;
C_noret_decl(f_6426)
static void C_fcall f_6426(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6451)
static void C_fcall f_6451(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6455)
static void C_ccall f_6455(C_word c,C_word *av) C_noret;
C_noret_decl(f_6458)
static void C_ccall f_6458(C_word c,C_word *av) C_noret;
C_noret_decl(f_6461)
static void C_ccall f_6461(C_word c,C_word *av) C_noret;
C_noret_decl(f_6473)
static void C_ccall f_6473(C_word c,C_word *av) C_noret;
C_noret_decl(f_6485)
static void C_ccall f_6485(C_word c,C_word *av) C_noret;
C_noret_decl(f_6489)
static void C_ccall f_6489(C_word c,C_word *av) C_noret;
C_noret_decl(f_6493)
static void C_fcall f_6493(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6497)
static void C_ccall f_6497(C_word c,C_word *av) C_noret;
C_noret_decl(f_6508)
static void C_ccall f_6508(C_word c,C_word *av) C_noret;
C_noret_decl(f_6537)
static void C_ccall f_6537(C_word c,C_word *av) C_noret;
C_noret_decl(f_6540)
static void C_fcall f_6540(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6541)
static void C_fcall f_6541(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6545)
static void C_ccall f_6545(C_word c,C_word *av) C_noret;
C_noret_decl(f_6548)
static void C_ccall f_6548(C_word c,C_word *av) C_noret;
C_noret_decl(f_6560)
static void C_ccall f_6560(C_word c,C_word *av) C_noret;
C_noret_decl(f_6568)
static void C_ccall f_6568(C_word c,C_word *av) C_noret;
C_noret_decl(f_6572)
static void C_ccall f_6572(C_word c,C_word *av) C_noret;
C_noret_decl(f_6578)
static void C_ccall f_6578(C_word c,C_word *av) C_noret;
C_noret_decl(f_6582)
static void C_ccall f_6582(C_word c,C_word *av) C_noret;
C_noret_decl(f_6591)
static void C_ccall f_6591(C_word c,C_word *av) C_noret;
C_noret_decl(f_6599)
static void C_fcall f_6599(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6609)
static void C_ccall f_6609(C_word c,C_word *av) C_noret;
C_noret_decl(f_6622)
static void C_fcall f_6622(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6632)
static void C_ccall f_6632(C_word c,C_word *av) C_noret;
C_noret_decl(f_6647)
static void C_ccall f_6647(C_word c,C_word *av) C_noret;
C_noret_decl(f_6649)
static void C_fcall f_6649(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6659)
static void C_ccall f_6659(C_word c,C_word *av) C_noret;
C_noret_decl(f_6673)
static void C_fcall f_6673(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6676)
static void C_ccall f_6676(C_word c,C_word *av) C_noret;
C_noret_decl(f_6679)
static void C_ccall f_6679(C_word c,C_word *av) C_noret;
C_noret_decl(f_6691)
static void C_ccall f_6691(C_word c,C_word *av) C_noret;
C_noret_decl(f_6698)
static void C_ccall f_6698(C_word c,C_word *av) C_noret;
C_noret_decl(f_6700)
static void C_fcall f_6700(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6710)
static void C_ccall f_6710(C_word c,C_word *av) C_noret;
C_noret_decl(f_6723)
static void C_fcall f_6723(C_word t0) C_noret;
C_noret_decl(f_6734)
static void C_ccall f_6734(C_word c,C_word *av) C_noret;
C_noret_decl(f_6740)
static void C_ccall f_6740(C_word c,C_word *av) C_noret;
C_noret_decl(f_6742)
static void C_fcall f_6742(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6767)
static void C_ccall f_6767(C_word c,C_word *av) C_noret;
C_noret_decl(f_6781)
static void C_ccall f_6781(C_word c,C_word *av) C_noret;
C_noret_decl(f_6790)
static void C_ccall f_6790(C_word c,C_word *av) C_noret;
C_noret_decl(f_6793)
static void C_ccall f_6793(C_word c,C_word *av) C_noret;
C_noret_decl(f_6796)
static void C_ccall f_6796(C_word c,C_word *av) C_noret;
C_noret_decl(f_6799)
static void C_ccall f_6799(C_word c,C_word *av) C_noret;
C_noret_decl(f_6805)
static void C_ccall f_6805(C_word c,C_word *av) C_noret;
C_noret_decl(f_6813)
static void C_fcall f_6813(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6823)
static void C_ccall f_6823(C_word c,C_word *av) C_noret;
C_noret_decl(f_6844)
static void C_ccall f_6844(C_word c,C_word *av) C_noret;
C_noret_decl(f_6848)
static void C_ccall f_6848(C_word c,C_word *av) C_noret;
C_noret_decl(f_6852)
static void C_ccall f_6852(C_word c,C_word *av) C_noret;
C_noret_decl(f_6856)
static void C_ccall f_6856(C_word c,C_word *av) C_noret;
C_noret_decl(f_6860)
static void C_ccall f_6860(C_word c,C_word *av) C_noret;
C_noret_decl(f_6863)
static void C_ccall f_6863(C_word c,C_word *av) C_noret;
C_noret_decl(f_6873)
static void C_ccall f_6873(C_word c,C_word *av) C_noret;
C_noret_decl(f_6880)
static void C_ccall f_6880(C_word c,C_word *av) C_noret;
C_noret_decl(f_6885)
static void C_ccall f_6885(C_word c,C_word *av) C_noret;
C_noret_decl(f_6889)
static void C_ccall f_6889(C_word c,C_word *av) C_noret;
C_noret_decl(f_6897)
static void C_ccall f_6897(C_word c,C_word *av) C_noret;
C_noret_decl(f_6905)
static void C_ccall f_6905(C_word c,C_word *av) C_noret;
C_noret_decl(f_6909)
static void C_ccall f_6909(C_word c,C_word *av) C_noret;
C_noret_decl(f_6913)
static void C_ccall f_6913(C_word c,C_word *av) C_noret;
C_noret_decl(f_6918)
static void C_ccall f_6918(C_word c,C_word *av) C_noret;
C_noret_decl(f_6920)
static void C_fcall f_6920(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6945)
static void C_ccall f_6945(C_word c,C_word *av) C_noret;
C_noret_decl(f_6961)
static void C_ccall f_6961(C_word c,C_word *av) C_noret;
C_noret_decl(f_6964)
static void C_ccall f_6964(C_word c,C_word *av) C_noret;
C_noret_decl(f_6971)
static void C_ccall f_6971(C_word c,C_word *av) C_noret;
C_noret_decl(f_6985)
static void C_ccall f_6985(C_word c,C_word *av) C_noret;
C_noret_decl(f_7000)
static void C_ccall f_7000(C_word c,C_word *av) C_noret;
C_noret_decl(f_7008)
static void C_fcall f_7008(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7018)
static void C_fcall f_7018(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7033)
static void C_ccall f_7033(C_word c,C_word *av) C_noret;
C_noret_decl(f_7042)
static void C_fcall f_7042(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7067)
static void C_ccall f_7067(C_word c,C_word *av) C_noret;
C_noret_decl(f_7079)
static void C_fcall f_7079(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7093)
static void C_ccall f_7093(C_word c,C_word *av) C_noret;
C_noret_decl(f_7099)
static void C_fcall f_7099(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7102)
static void C_ccall f_7102(C_word c,C_word *av) C_noret;
C_noret_decl(f_7105)
static void C_ccall f_7105(C_word c,C_word *av) C_noret;
C_noret_decl(f_7112)
static void C_ccall f_7112(C_word c,C_word *av) C_noret;
C_noret_decl(f_7116)
static void C_ccall f_7116(C_word c,C_word *av) C_noret;
C_noret_decl(f_7125)
static void C_ccall f_7125(C_word c,C_word *av) C_noret;
C_noret_decl(f_7204)
static void C_fcall f_7204(C_word t0) C_noret;
C_noret_decl(f_7215)
static void C_ccall f_7215(C_word c,C_word *av) C_noret;
C_noret_decl(f_7221)
static void C_ccall f_7221(C_word c,C_word *av) C_noret;
C_noret_decl(f_7223)
static void C_fcall f_7223(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7248)
static void C_ccall f_7248(C_word c,C_word *av) C_noret;
C_noret_decl(f_7257)
static void C_fcall f_7257(C_word t0) C_noret;
C_noret_decl(f_7265)
static void C_ccall f_7265(C_word c,C_word *av) C_noret;
C_noret_decl(f_7327)
static void C_ccall f_7327(C_word c,C_word *av) C_noret;
C_noret_decl(f_7330)
static void C_ccall f_7330(C_word c,C_word *av) C_noret;
C_noret_decl(f_7333)
static void C_ccall f_7333(C_word c,C_word *av) C_noret;
C_noret_decl(f_7336)
static void C_ccall f_7336(C_word c,C_word *av) C_noret;
C_noret_decl(f_7353)
static void C_ccall f_7353(C_word c,C_word *av) C_noret;
C_noret_decl(f_7356)
static void C_ccall f_7356(C_word c,C_word *av) C_noret;
C_noret_decl(f_7359)
static void C_ccall f_7359(C_word c,C_word *av) C_noret;
C_noret_decl(f_7362)
static void C_ccall f_7362(C_word c,C_word *av) C_noret;
C_noret_decl(f_7378)
static void C_ccall f_7378(C_word c,C_word *av) C_noret;
C_noret_decl(f_7382)
static void C_fcall f_7382(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7390)
static void C_ccall f_7390(C_word c,C_word *av) C_noret;
C_noret_decl(f_7398)
static void C_fcall f_7398(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7411)
static void C_ccall f_7411(C_word c,C_word *av) C_noret;
C_noret_decl(f_7415)
static void C_ccall f_7415(C_word c,C_word *av) C_noret;
C_noret_decl(f_7430)
static void C_ccall f_7430(C_word c,C_word *av) C_noret;
C_noret_decl(f_7435)
static void C_ccall f_7435(C_word c,C_word *av) C_noret;
C_noret_decl(f_7443)
static void C_ccall f_7443(C_word c,C_word *av) C_noret;
C_noret_decl(f_7461)
static void C_ccall f_7461(C_word c,C_word *av) C_noret;
C_noret_decl(f_7467)
static void C_ccall f_7467(C_word c,C_word *av) C_noret;
C_noret_decl(f_7471)
static void C_ccall f_7471(C_word c,C_word *av) C_noret;
C_noret_decl(f_7475)
static void C_ccall f_7475(C_word c,C_word *av) C_noret;
C_noret_decl(f_7479)
static void C_ccall f_7479(C_word c,C_word *av) C_noret;
C_noret_decl(f_7486)
static void C_fcall f_7486(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7490)
static void C_ccall f_7490(C_word c,C_word *av) C_noret;
C_noret_decl(f_7493)
static void C_ccall f_7493(C_word c,C_word *av) C_noret;
C_noret_decl(f_7509)
static void C_ccall f_7509(C_word c,C_word *av) C_noret;
C_noret_decl(f_7512)
static void C_ccall f_7512(C_word c,C_word *av) C_noret;
C_noret_decl(f_7520)
static void C_fcall f_7520(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7545)
static void C_ccall f_7545(C_word c,C_word *av) C_noret;
C_noret_decl(f_7554)
static void C_fcall f_7554(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7579)
static void C_ccall f_7579(C_word c,C_word *av) C_noret;
C_noret_decl(f_7596)
static void C_ccall f_7596(C_word c,C_word *av) C_noret;
C_noret_decl(f_7616)
static void C_ccall f_7616(C_word c,C_word *av) C_noret;
C_noret_decl(f_7620)
static void C_ccall f_7620(C_word c,C_word *av) C_noret;
C_noret_decl(f_7645)
static void C_ccall f_7645(C_word c,C_word *av) C_noret;
C_noret_decl(f_7663)
static void C_ccall f_7663(C_word c,C_word *av) C_noret;
C_noret_decl(f_7667)
static void C_ccall f_7667(C_word c,C_word *av) C_noret;
C_noret_decl(f_7674)
static void C_ccall f_7674(C_word c,C_word *av) C_noret;
C_noret_decl(f_7678)
static void C_ccall f_7678(C_word c,C_word *av) C_noret;
C_noret_decl(f_7682)
static void C_ccall f_7682(C_word c,C_word *av) C_noret;
C_noret_decl(f_7686)
static void C_ccall f_7686(C_word c,C_word *av) C_noret;
C_noret_decl(f_7697)
static void C_ccall f_7697(C_word c,C_word *av) C_noret;
C_noret_decl(f_7700)
static void C_ccall f_7700(C_word c,C_word *av) C_noret;
C_noret_decl(f_7707)
static void C_ccall f_7707(C_word c,C_word *av) C_noret;
C_noret_decl(f_7712)
static void C_ccall f_7712(C_word c,C_word *av) C_noret;
C_noret_decl(f_7717)
static void C_ccall f_7717(C_word c,C_word *av) C_noret;
C_noret_decl(f_7721)
static void C_ccall f_7721(C_word c,C_word *av) C_noret;
C_noret_decl(f_7725)
static void C_ccall f_7725(C_word c,C_word *av) C_noret;
C_noret_decl(f_7732)
static void C_ccall f_7732(C_word c,C_word *av) C_noret;
C_noret_decl(f_7734)
static void C_ccall f_7734(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_2939)
static void C_ccall trf_2939(C_word c,C_word *av) C_noret;
static void C_ccall trf_2939(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2939(t0,t1,t2);}

C_noret_decl(trf_2945)
static void C_ccall trf_2945(C_word c,C_word *av) C_noret;
static void C_ccall trf_2945(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2945(t0,t1,t2,t3);}

C_noret_decl(trf_3001)
static void C_ccall trf_3001(C_word c,C_word *av) C_noret;
static void C_ccall trf_3001(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3001(t0,t1,t2);}

C_noret_decl(trf_3076)
static void C_ccall trf_3076(C_word c,C_word *av) C_noret;
static void C_ccall trf_3076(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3076(t0,t1,t2);}

C_noret_decl(trf_3124)
static void C_ccall trf_3124(C_word c,C_word *av) C_noret;
static void C_ccall trf_3124(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3124(t0,t1,t2);}

C_noret_decl(trf_3168)
static void C_ccall trf_3168(C_word c,C_word *av) C_noret;
static void C_ccall trf_3168(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3168(t0,t1,t2);}

C_noret_decl(trf_3381)
static void C_ccall trf_3381(C_word c,C_word *av) C_noret;
static void C_ccall trf_3381(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3381(t0,t1,t2,t3);}

C_noret_decl(trf_3821)
static void C_ccall trf_3821(C_word c,C_word *av) C_noret;
static void C_ccall trf_3821(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3821(t0,t1,t2);}

C_noret_decl(trf_3942)
static void C_ccall trf_3942(C_word c,C_word *av) C_noret;
static void C_ccall trf_3942(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3942(t0,t1);}

C_noret_decl(trf_3945)
static void C_ccall trf_3945(C_word c,C_word *av) C_noret;
static void C_ccall trf_3945(C_word c,C_word *av){
C_word t0=av[0];
f_3945(t0);}

C_noret_decl(trf_4111)
static void C_ccall trf_4111(C_word c,C_word *av) C_noret;
static void C_ccall trf_4111(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4111(t0,t1);}

C_noret_decl(trf_4115)
static void C_ccall trf_4115(C_word c,C_word *av) C_noret;
static void C_ccall trf_4115(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4115(t0,t1);}

C_noret_decl(trf_4140)
static void C_ccall trf_4140(C_word c,C_word *av) C_noret;
static void C_ccall trf_4140(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4140(t0,t1,t2);}

C_noret_decl(trf_4234)
static void C_ccall trf_4234(C_word c,C_word *av) C_noret;
static void C_ccall trf_4234(C_word c,C_word *av){
C_word t0=av[0];
f_4234(t0);}

C_noret_decl(trf_4358)
static void C_ccall trf_4358(C_word c,C_word *av) C_noret;
static void C_ccall trf_4358(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4358(t0,t1);}

C_noret_decl(trf_4365)
static void C_ccall trf_4365(C_word c,C_word *av) C_noret;
static void C_ccall trf_4365(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4365(t0,t1,t2,t3);}

C_noret_decl(trf_4391)
static void C_ccall trf_4391(C_word c,C_word *av) C_noret;
static void C_ccall trf_4391(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4391(t0,t1);}

C_noret_decl(trf_4421)
static void C_ccall trf_4421(C_word c,C_word *av) C_noret;
static void C_ccall trf_4421(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4421(t0,t1);}

C_noret_decl(trf_4437)
static void C_ccall trf_4437(C_word c,C_word *av) C_noret;
static void C_ccall trf_4437(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4437(t0,t1,t2);}

C_noret_decl(trf_4473)
static void C_ccall trf_4473(C_word c,C_word *av) C_noret;
static void C_ccall trf_4473(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4473(t0,t1);}

C_noret_decl(trf_4617)
static void C_ccall trf_4617(C_word c,C_word *av) C_noret;
static void C_ccall trf_4617(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4617(t0,t1);}

C_noret_decl(trf_4620)
static void C_ccall trf_4620(C_word c,C_word *av) C_noret;
static void C_ccall trf_4620(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4620(t0,t1);}

C_noret_decl(trf_4885)
static void C_ccall trf_4885(C_word c,C_word *av) C_noret;
static void C_ccall trf_4885(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4885(t0,t1);}

C_noret_decl(trf_5320)
static void C_ccall trf_5320(C_word c,C_word *av) C_noret;
static void C_ccall trf_5320(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5320(t0,t1);}

C_noret_decl(trf_5511)
static void C_ccall trf_5511(C_word c,C_word *av) C_noret;
static void C_ccall trf_5511(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5511(t0,t1);}

C_noret_decl(trf_5603)
static void C_ccall trf_5603(C_word c,C_word *av) C_noret;
static void C_ccall trf_5603(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5603(t0,t1);}

C_noret_decl(trf_5606)
static void C_ccall trf_5606(C_word c,C_word *av) C_noret;
static void C_ccall trf_5606(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5606(t0,t1);}

C_noret_decl(trf_5660)
static void C_ccall trf_5660(C_word c,C_word *av) C_noret;
static void C_ccall trf_5660(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5660(t0,t1);}

C_noret_decl(trf_5761)
static void C_ccall trf_5761(C_word c,C_word *av) C_noret;
static void C_ccall trf_5761(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5761(t0,t1);}

C_noret_decl(trf_5807)
static void C_ccall trf_5807(C_word c,C_word *av) C_noret;
static void C_ccall trf_5807(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5807(t0,t1,t2);}

C_noret_decl(trf_5955)
static void C_ccall trf_5955(C_word c,C_word *av) C_noret;
static void C_ccall trf_5955(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5955(t0,t1);}

C_noret_decl(trf_5991)
static void C_ccall trf_5991(C_word c,C_word *av) C_noret;
static void C_ccall trf_5991(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5991(t0,t1);}

C_noret_decl(trf_6264)
static void C_ccall trf_6264(C_word c,C_word *av) C_noret;
static void C_ccall trf_6264(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6264(t0,t1);}

C_noret_decl(trf_6311)
static void C_ccall trf_6311(C_word c,C_word *av) C_noret;
static void C_ccall trf_6311(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6311(t0,t1);}

C_noret_decl(trf_6330)
static void C_ccall trf_6330(C_word c,C_word *av) C_noret;
static void C_ccall trf_6330(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6330(t0,t1,t2);}

C_noret_decl(trf_6366)
static void C_ccall trf_6366(C_word c,C_word *av) C_noret;
static void C_ccall trf_6366(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6366(t0,t1);}

C_noret_decl(trf_6426)
static void C_ccall trf_6426(C_word c,C_word *av) C_noret;
static void C_ccall trf_6426(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6426(t0,t1,t2);}

C_noret_decl(trf_6451)
static void C_ccall trf_6451(C_word c,C_word *av) C_noret;
static void C_ccall trf_6451(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6451(t0,t1,t2);}

C_noret_decl(trf_6493)
static void C_ccall trf_6493(C_word c,C_word *av) C_noret;
static void C_ccall trf_6493(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6493(t0,t1);}

C_noret_decl(trf_6540)
static void C_ccall trf_6540(C_word c,C_word *av) C_noret;
static void C_ccall trf_6540(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6540(t0,t1);}

C_noret_decl(trf_6541)
static void C_ccall trf_6541(C_word c,C_word *av) C_noret;
static void C_ccall trf_6541(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6541(t0,t1,t2);}

C_noret_decl(trf_6599)
static void C_ccall trf_6599(C_word c,C_word *av) C_noret;
static void C_ccall trf_6599(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6599(t0,t1,t2);}

C_noret_decl(trf_6622)
static void C_ccall trf_6622(C_word c,C_word *av) C_noret;
static void C_ccall trf_6622(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6622(t0,t1,t2);}

C_noret_decl(trf_6649)
static void C_ccall trf_6649(C_word c,C_word *av) C_noret;
static void C_ccall trf_6649(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6649(t0,t1,t2);}

C_noret_decl(trf_6673)
static void C_ccall trf_6673(C_word c,C_word *av) C_noret;
static void C_ccall trf_6673(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6673(t0,t1);}

C_noret_decl(trf_6700)
static void C_ccall trf_6700(C_word c,C_word *av) C_noret;
static void C_ccall trf_6700(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6700(t0,t1,t2);}

C_noret_decl(trf_6723)
static void C_ccall trf_6723(C_word c,C_word *av) C_noret;
static void C_ccall trf_6723(C_word c,C_word *av){
C_word t0=av[0];
f_6723(t0);}

C_noret_decl(trf_6742)
static void C_ccall trf_6742(C_word c,C_word *av) C_noret;
static void C_ccall trf_6742(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6742(t0,t1,t2);}

C_noret_decl(trf_6813)
static void C_ccall trf_6813(C_word c,C_word *av) C_noret;
static void C_ccall trf_6813(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6813(t0,t1,t2);}

C_noret_decl(trf_6920)
static void C_ccall trf_6920(C_word c,C_word *av) C_noret;
static void C_ccall trf_6920(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6920(t0,t1,t2);}

C_noret_decl(trf_7008)
static void C_ccall trf_7008(C_word c,C_word *av) C_noret;
static void C_ccall trf_7008(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7008(t0,t1,t2);}

C_noret_decl(trf_7018)
static void C_ccall trf_7018(C_word c,C_word *av) C_noret;
static void C_ccall trf_7018(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7018(t0,t1);}

C_noret_decl(trf_7042)
static void C_ccall trf_7042(C_word c,C_word *av) C_noret;
static void C_ccall trf_7042(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7042(t0,t1,t2);}

C_noret_decl(trf_7079)
static void C_ccall trf_7079(C_word c,C_word *av) C_noret;
static void C_ccall trf_7079(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7079(t0,t1,t2,t3);}

C_noret_decl(trf_7099)
static void C_ccall trf_7099(C_word c,C_word *av) C_noret;
static void C_ccall trf_7099(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7099(t0,t1);}

C_noret_decl(trf_7204)
static void C_ccall trf_7204(C_word c,C_word *av) C_noret;
static void C_ccall trf_7204(C_word c,C_word *av){
C_word t0=av[0];
f_7204(t0);}

C_noret_decl(trf_7223)
static void C_ccall trf_7223(C_word c,C_word *av) C_noret;
static void C_ccall trf_7223(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7223(t0,t1,t2);}

C_noret_decl(trf_7257)
static void C_ccall trf_7257(C_word c,C_word *av) C_noret;
static void C_ccall trf_7257(C_word c,C_word *av){
C_word t0=av[0];
f_7257(t0);}

C_noret_decl(trf_7382)
static void C_ccall trf_7382(C_word c,C_word *av) C_noret;
static void C_ccall trf_7382(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7382(t0,t1,t2);}

C_noret_decl(trf_7398)
static void C_ccall trf_7398(C_word c,C_word *av) C_noret;
static void C_ccall trf_7398(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7398(t0,t1);}

C_noret_decl(trf_7486)
static void C_ccall trf_7486(C_word c,C_word *av) C_noret;
static void C_ccall trf_7486(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7486(t0,t1);}

C_noret_decl(trf_7520)
static void C_ccall trf_7520(C_word c,C_word *av) C_noret;
static void C_ccall trf_7520(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7520(t0,t1,t2);}

C_noret_decl(trf_7554)
static void C_ccall trf_7554(C_word c,C_word *av) C_noret;
static void C_ccall trf_7554(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7554(t0,t1,t2);}

/* f8470 in k6959 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f8470(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f8470,c,av);}
/* csc.scm:1013: chicken.file#file-exists? */
t2=C_fast_retrieve(lf[137]);{
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

/* f8476 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in ... */
static void C_ccall f8476(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f8476,c,av);}
/* csc.scm:610: ##sys#print */
t2=*((C_word*)lf[48]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* f8480 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in ... */
static void C_ccall f8480(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f8480,c,av);}
/* csc.scm:610: ##sys#print */
t2=*((C_word*)lf[48]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* f8512 in k4661 in k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f8512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f8512,c,av);}
/* csc.scm:574: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f8556 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in ... */
static void C_ccall f8556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f8556,c,av);}
/* csc.scm:93: chicken.process#qs */
t2=C_fast_retrieve(lf[55]);{
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

/* k2235 */
static void C_ccall f_2237(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2237,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2240,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k2238 in k2235 */
static void C_ccall f_2240(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2240,c,av);}
a=C_alloc(13);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2243,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7734,tmp=(C_word)a,a+=2,tmp);
/* csc.scm:28: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[440]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[440]+1);
av2[1]=t3;
av2[2]=t4;
tp(3,av2);}}

/* k2241 in k2238 in k2235 */
static void C_ccall f_2243(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2243,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2246,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2246,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2249,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2249,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2252,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2252(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2252,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2255,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_posix_toplevel(2,av2);}}

/* k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2255,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2258,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2258(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2258,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[1] /* (set! main#staticbuild ...) */,C_mk_bool(STATIC_CHICKEN));
t3=C_mutate(&lf[2] /* (set! main#debugbuild ...) */,C_mk_bool(DEBUG_CHICKEN));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2264,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:43: chicken.platform#feature? */
t5=C_fast_retrieve(lf[426]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[427];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2264(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2264,c,av);}
a=C_alloc(6);
t2=lf[3] /* main#cross-chicken */ =t1;;
t3=lf[4] /* main#binary-version */ =C_fix((C_word)C_BINARY_VERSION);;
t4=lf[5] /* main#major-version */ =C_fix((C_word)C_MAJOR_VERSION);;
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2270,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[50]+1);{
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

/* k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2270(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2270,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[6] /* (set! main#chicken-install-program ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2274,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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

/* k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2274(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2274,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[7] /* (set! main#default-cc ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2278,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_CXX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2278,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[8] /* (set! main#default-cxx ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2282,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_INSTALL_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2282,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2286,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2286(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2286,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[9] /* (set! main#default-cflags ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2290,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LDFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2290,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2294,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2294,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2298,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2298,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2302,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2302,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[10] /* (set! main#default-libs ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2306,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LIB_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2306,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[11] /* (set! main#default-libdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2310,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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

/* k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2310(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2310,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[12] /* (set! main#default-runlibdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2314,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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

/* k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 */
static void C_ccall f_2314(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2314,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2318,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in k2235 in ... */
static void C_ccall f_2318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2318,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[13] /* (set! main#default-incdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2322,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_TARGET_BIN_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in k2238 in ... */
static void C_ccall f_2322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2322,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[14] /* (set! main#default-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2326,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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

/* k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in k2241 in ... */
static void C_ccall f_2326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2326,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[15] /* (set! main#default-sharedir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7732,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:64: chicken.platform#software-type */
t4=C_fast_retrieve(lf[213]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in ... */
static void C_ccall f_2334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2334,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2338,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in ... */
static void C_ccall f_2338(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2338,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[14] /* (set! main#default-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2342,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7725,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t5=*((C_word*)lf[50]+1);{
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

/* k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in ... */
static void C_ccall f_2342(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2342,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2346,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7721,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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

/* k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in ... */
static void C_ccall f_2346(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2346,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2350,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7717,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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

/* k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in ... */
static void C_ccall f_2350(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2350,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2354,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in ... */
static void C_ccall f_2354(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2354,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2358,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in ... */
static void C_ccall f_2358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2358,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2362,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in ... */
static void C_ccall f_2362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2362,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2366,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in ... */
static void C_ccall f_2366(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2366,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2370,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in ... */
static void C_ccall f_2370(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2370,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[18] /* (set! main#host-libdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2374,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_BIN_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in ... */
static void C_ccall f_2374(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2374,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[19] /* (set! main#host-bindir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2378,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_INCLUDE_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in ... */
static void C_ccall f_2378(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2378,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[20] /* (set! main#host-incdir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2382,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_SHARE_HOME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in ... */
static void C_ccall f_2382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2382,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[21] /* (set! main#host-sharedir ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2386,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_MORE_LIBS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in ... */
static void C_ccall f_2386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2386,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[22] /* (set! main#host-libs ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2390,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_CFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in ... */
static void C_ccall f_2390(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2390,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[23] /* (set! main#host-cflags ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2394,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LDFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in ... */
static void C_ccall f_2394(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2394,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2398,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
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

/* k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in ... */
static void C_ccall f_2398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2398,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[24] /* (set! main#host-cc ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2402,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_CXX);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in ... */
static void C_ccall f_2402(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2402,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[25] /* (set! main#host-cxx ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2406,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7712,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_retrieve2(lf[4],C_text("main#binary-version"));
/* ##sys#fixnum->string */
t6=C_fast_retrieve(lf[434]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=C_retrieve2(lf[4],C_text("main#binary-version"));
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in ... */
static void C_ccall f_2406(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2406,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[26] /* (set! main#target-repo ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2410,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7707,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_retrieve2(lf[4],C_text("main#binary-version"));
/* ##sys#fixnum->string */
t6=C_fast_retrieve(lf[434]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=C_retrieve2(lf[4],C_text("main#binary-version"));
av2[3]=C_fix(10);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in ... */
static void C_ccall f_2410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2410,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[27] /* (set! main#target-run-repo ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2494,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:122: chicken.process-context#get-environment-variable */
t4=C_fast_retrieve(lf[159]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[432];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in ... */
static void C_ccall f_2494(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2494,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2497,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_2497(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7697,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:123: chicken.platform#system-cache-directory */
t4=C_fast_retrieve(lf[431]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in ... */
static void C_ccall f_2497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_2497,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[28] /* (set! main#cache-directory ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2501,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* egg-environment.scm:130: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[28],C_text("main#cache-directory"));
av2[3]=lf[429];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in ... */
static void C_ccall f_2501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2501,c,av);}
a=C_alloc(8);
t2=C_mutate(&lf[29] /* (set! main#cons* ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2939,tmp=(C_word)a,a+=2,tmp));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3786,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_MORE_LIBS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* main#cons* in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in ... */
static void C_fcall f_2939(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_2939,3,t1,t2,t3);}
a=C_alloc(5);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2945,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_2945(t7,t1,t2,t3);}

/* loop in main#cons* in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in ... */
static void C_fcall f_2945(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_2945,4,t0,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2959,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:95: loop */
t6=t4;
t7=C_i_car(t3);
t8=C_u_i_cdr(t3);
t1=t6;
t2=t7;
t3=t8;
goto loop;}}

/* k2957 in loop in main#cons* in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in ... */
static void C_ccall f_2959(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2959,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in loop in k7091 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_fcall f_3001(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3001,3,t0,t1,t2);}
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
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3028,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:109: loop */
t7=t5;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}}}

/* k3026 in loop in loop in k7091 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_3028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3028,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k7091 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_fcall f_3076(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3076,3,t0,t1,t2);}
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
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3090,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3103,a[2]=((C_word*)t0)[2],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3001,a[2]=t3,a[3]=t8,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_3001(t10,t6,t4);}}

/* k3088 in loop in k7091 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_3090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3090,c,av);}
a=C_alloc(3);
t2=C_i_equalp(((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?((C_word*)t0)[4]:C_a_i_cons(&a,2,((C_word*)t0)[5],t1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3101 in loop in k7091 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_3103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3103,c,av);}
/* mini-srfi-1.scm:123: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3076(t2,((C_word*)t0)[3],t1);}

/* foldr480 in foldl586 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_fcall f_3124(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_3124,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3132,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3153,a[2]=t1,a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g485 in foldr480 in foldl586 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static C_word C_fcall f_3132(C_word *a,C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t3=(
/* mini-srfi-1.scm:131: pred */
  f_3403(((C_word*)t0)[2],t1)
);
return((C_truep(t3)?C_a_i_cons(&a,2,t1,t2):t2));}

/* k3151 in foldr480 in foldl586 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_3153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3153,c,av);}
a=C_alloc(3);
/* mini-srfi-1.scm:131: g485 */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* mini-srfi-1.scm:131: g485 */
  f_3132(C_a_i(&a,3),((C_word*)t0)[3],((C_word*)t0)[4],t1)
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* foldr498 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_fcall f_3168(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3168,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3202,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
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

/* k3178 in k3200 in foldr498 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_3180(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3180,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3184,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* mini-srfi-1.scm:135: g513 */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
/* mini-srfi-1.scm:135: g513 */
  f_3184(C_a_i(&a,3),t2,t1)
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* g513 in k3178 in k3200 in foldr498 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static C_word C_fcall f_3184(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_a_i_cons(&a,2,t1,((C_word*)t0)[2]));}

/* k3200 in foldr498 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_3202(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3202,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3180,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:135: pred */
t3=C_retrieve2(lf[134],C_text("main#find-object-file"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
f_4246(3,av2);}}

/* loop in k4568 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static C_word C_fcall f_3281(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
t2=C_i_cdr(t1);
if(C_truep(C_i_nullp(t2))){
return(C_u_i_car(t1));}
else{
t4=C_u_i_cdr(t1);
t1=t4;
goto loop;}}

/* foldl586 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_fcall f_3381(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,0,3)))){
C_save_and_reclaim_args((void *)trf_3381,4,t0,t1,t2,t3);}
a=C_alloc(14);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3414,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_slot(t2,C_fix(0));
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3403,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
t8=C_i_check_list_2(t3,lf[390]);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3124,a[2]=t7,a[3]=t10,tmp=(C_word)a,a+=4,tmp));
t12=((C_word*)t10)[1];
f_3124(t12,t5,t3);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* a3402 in foldl586 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static C_word C_fcall f_3403(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_not(C_i_memq(t1,((C_word*)t0)[2])));}

/* k3412 in foldl586 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_3414(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3414,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3381(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in ... */
static void C_ccall f_3786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3786,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[22] /* (set! main#host-libs ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7686,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:67: chicken.platform#software-version */
t4=C_fast_retrieve(lf[242]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in ... */
static void C_ccall f_3812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3812,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[38] /* (set! main#solaris ...) */,C_u_i_memq(t1,lf[39]));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:74: chicken.platform#software-version */
t4=C_fast_retrieve(lf[242]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in ... */
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3818,c,av);}
a=C_alloc(5);
t2=C_mutate(&lf[40] /* (set! main#elf ...) */,C_u_i_memq(t1,lf[41]));
t3=C_mutate(&lf[42] /* (set! main#stop ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3821,tmp=(C_word)a,a+=2,tmp));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3848,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:80: chicken.process-context#command-line-arguments */
t5=C_fast_retrieve(lf[428]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* main#stop in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in ... */
static void C_fcall f_3821(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_3821,3,t1,t2,t3);}
a=C_alloc(13);
t4=*((C_word*)lf[43]+1);
t5=*((C_word*)lf[43]+1);
t6=C_i_check_port_2(*((C_word*)lf[43]+1),C_fix(2),C_SCHEME_TRUE,lf[44]);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3828,a[2]=t1,a[3]=t4,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3844,a[2]=t7,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* ##sys#peek-c-string */
t9=*((C_word*)lf[50]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t8;
av2[2]=C_mpointer(&a,(void*)C_CSC_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* k3826 in main#stop in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in ... */
static void C_ccall f_3828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3828,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3831,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:77: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[49];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3829 in k3826 in main#stop in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in ... */
static void C_ccall f_3831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3831,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3834,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=t2;
av2[2]=*((C_word*)lf[47]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
C_apply(6,av2);}}

/* k3832 in k3829 in k3826 in main#stop in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in ... */
static void C_ccall f_3834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3834,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3837,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:77: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[46]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k3835 in k3832 in k3829 in k3826 in main#stop in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in ... */
static void C_ccall f_3837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3837,c,av);}
/* csc.scm:78: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
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

/* k3842 in main#stop in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in ... */
static void C_ccall f_3844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3844,c,av);}
/* csc.scm:77: ##sys#print */
t2=*((C_word*)lf[48]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in ... */
static void C_ccall f_3848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3848,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[51] /* (set! main#arguments ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3852,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:81: chicken.platform#feature? */
t4=C_fast_retrieve(lf[426]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[427];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in ... */
static void C_ccall f_3852(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_3852,c,av);}
a=C_alloc(16);
t2=lf[3] /* main#cross-chicken */ =t1;;
t3=C_i_not(C_retrieve2(lf[3],C_text("main#cross-chicken")));
t4=(C_truep(t3)?t3:C_i_member(lf[52],C_retrieve2(lf[51],C_text("main#arguments"))));
t5=C_mutate(&lf[53] /* (set! main#host-mode ...) */,t4);
t6=C_mutate(&lf[54] /* (set! main#quotewrap ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3870,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate(&lf[58] /* (set! main#quotewrap-no-slash-trans ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3884,tmp=(C_word)a,a+=2,tmp));
t8=(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))?C_retrieve2(lf[21],C_text("main#host-sharedir")):C_retrieve2(lf[15],C_text("main#default-sharedir")));
t9=C_mutate(&lf[59] /* (set! main#home ...) */,t8);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3900,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7663,a[2]=t10,tmp=(C_word)a,a+=3,tmp);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7667,a[2]=t11,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t13=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t13;
av2[1]=t12;
av2[2]=C_mpointer(&a,(void*)C_CHICKEN_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t13+1)))(4,av2);}}

/* main#quotewrap in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in ... */
static void C_ccall f_3870(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3870,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3878,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3882,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:90: chicken.pathname#normalize-pathname */
t5=C_fast_retrieve(lf[57]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3876 in main#quotewrap in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in ... */
static void C_ccall f_3878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3878,c,av);}
/* csc.scm:90: chicken.process#qs */
t2=C_fast_retrieve(lf[55]);{
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

/* k3880 in main#quotewrap in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in ... */
static void C_ccall f_3882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3882,c,av);}
if(C_truep(C_mk_bool(C_WINDOWS_SHELL))){
/* csc.scm:86: chicken.string#string-translate */
t2=C_fast_retrieve(lf[56]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_make_character(92);
av2[4]=C_make_character(47);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
/* csc.scm:90: chicken.process#qs */
t2=C_fast_retrieve(lf[55]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* main#quotewrap-no-slash-trans in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in ... */
static void C_ccall f_3884(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3884,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3892,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:93: chicken.pathname#normalize-pathname */
t4=C_fast_retrieve(lf[57]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3890 in main#quotewrap-no-slash-trans in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in ... */
static void C_ccall f_3892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3892,c,av);}
/* csc.scm:93: chicken.process#qs */
t2=C_fast_retrieve(lf[55]);{
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

/* k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in ... */
static void C_ccall f_3900(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3900,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[60] /* (set! main#translator ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3904,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t4=C_retrieve2(lf[24],C_text("main#host-cc"));
t5=C_retrieve2(lf[24],C_text("main#host-cc"));
/* csc.scm:101: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[24],C_text("main#host-cc"));
f_3870(3,av2);}}
else{
t4=C_retrieve2(lf[7],C_text("main#default-cc"));
t5=C_retrieve2(lf[7],C_text("main#default-cc"));
/* csc.scm:101: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[7],C_text("main#default-cc"));
f_3870(3,av2);}}}

/* k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in ... */
static void C_ccall f_3904(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3904,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[61] /* (set! main#compiler ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3908,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t4=C_retrieve2(lf[25],C_text("main#host-cxx"));
t5=C_retrieve2(lf[25],C_text("main#host-cxx"));
/* csc.scm:102: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[25],C_text("main#host-cxx"));
f_3870(3,av2);}}
else{
t4=C_retrieve2(lf[8],C_text("main#default-cxx"));
t5=C_retrieve2(lf[8],C_text("main#default-cxx"));
/* csc.scm:102: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[8],C_text("main#default-cxx"));
f_3870(3,av2);}}}

/* k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in ... */
static void C_ccall f_3908(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3908,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[62] /* (set! main#c++-compiler ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3912,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7645,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
/* ##sys#peek-c-string */
t5=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_RC_COMPILER);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
/* ##sys#peek-c-string */
t5=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)C_TARGET_RC_COMPILER);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in ... */
static void C_ccall f_3912(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3912,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[63] /* (set! main#rc-compiler ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3916,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t4=C_retrieve2(lf[24],C_text("main#host-cc"));
t5=C_retrieve2(lf[24],C_text("main#host-cc"));
/* csc.scm:104: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[24],C_text("main#host-cc"));
f_3870(3,av2);}}
else{
t4=C_retrieve2(lf[7],C_text("main#default-cc"));
t5=C_retrieve2(lf[7],C_text("main#default-cc"));
/* csc.scm:104: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[7],C_text("main#default-cc"));
f_3870(3,av2);}}}

/* k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in ... */
static void C_ccall f_3916(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3916,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[64] /* (set! main#linker ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3920,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t4=C_retrieve2(lf[25],C_text("main#host-cxx"));
t5=C_retrieve2(lf[25],C_text("main#host-cxx"));
/* csc.scm:105: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[25],C_text("main#host-cxx"));
f_3870(3,av2);}}
else{
t4=C_retrieve2(lf[8],C_text("main#default-cxx"));
t5=C_retrieve2(lf[8],C_text("main#default-cxx"));
/* csc.scm:105: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=C_retrieve2(lf[8],C_text("main#default-cxx"));
f_3870(3,av2);}}}

/* k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in ... */
static void C_ccall f_3920(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3920,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[65] /* (set! main#c++-linker ...) */,t1);
t3=(C_truep(C_retrieve2(lf[31],C_text("main#mingw")))?lf[66]:lf[67]);
t4=C_mutate(&lf[68] /* (set! main#object-extension ...) */,t3);
t5=C_mutate(&lf[69] /* (set! main#library-extension ...) */,lf[70]);
t6=C_mutate(&lf[71] /* (set! main#executable-extension ...) */,lf[72]);
t7=C_mutate(&lf[73] /* (set! main#shared-library-extension ...) */,C_fast_retrieve(lf[74]));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3933,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:112: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[178]+1);
av2[1]=t8;
av2[2]=lf[425];
av2[3]=C_retrieve2(lf[68],C_text("main#object-extension"));
tp(4,av2);}}

/* k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in ... */
static void C_ccall f_3933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3933,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[75] /* (set! main#static-object-extension ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3937,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:113: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[178]+1);
av2[1]=t3;
av2[2]=lf[424];
av2[3]=C_retrieve2(lf[69],C_text("main#library-extension"));
tp(4,av2);}}

/* k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in ... */
static void C_ccall f_3937(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3937,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[76] /* (set! main#static-library-extension ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3942,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_retrieve2(lf[31],C_text("main#mingw"));
if(C_truep(C_retrieve2(lf[31],C_text("main#mingw")))){
t5=C_retrieve2(lf[31],C_text("main#mingw"));
t6=t3;
f_3942(t6,(C_truep(C_retrieve2(lf[31],C_text("main#mingw")))?lf[422]:lf[423]));}
else{
t5=C_retrieve2(lf[35],C_text("main#cygwin"));
t6=t3;
f_3942(t6,(C_truep(C_retrieve2(lf[35],C_text("main#cygwin")))?lf[422]:lf[423]));}}

/* k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in ... */
static void C_fcall f_3942(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3942,2,t0,t1);}
a=C_alloc(5);
t2=C_mutate(&lf[77] /* (set! main#pic-options ...) */,t1);
t3=lf[78] /* main#generate-manifest */ =C_SCHEME_FALSE;;
t4=C_mutate(&lf[79] /* (set! main#libchicken ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3945,tmp=(C_word)a,a+=2,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3992,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t6=C_retrieve2(lf[23],C_text("main#host-cflags"));
t7=C_retrieve2(lf[23],C_text("main#host-cflags"));
/* csc.scm:133: chicken.string#string-split */
t8=C_fast_retrieve(lf[235]);{
C_word av2[3];
av2[0]=t8;
av2[1]=t5;
av2[2]=C_retrieve2(lf[23],C_text("main#host-cflags"));
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t6=C_retrieve2(lf[9],C_text("main#default-cflags"));
t7=C_retrieve2(lf[9],C_text("main#default-cflags"));
/* csc.scm:133: chicken.string#string-split */
t8=C_fast_retrieve(lf[235]);{
C_word av2[3];
av2[0]=t8;
av2[1]=t5;
av2[2]=C_retrieve2(lf[9],C_text("main#default-cflags"));
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}

/* main#libchicken in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in ... */
static void C_fcall f_3945(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3945,1,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3953,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_not(C_retrieve2(lf[53],C_text("main#host-mode"))))){
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LIB_NAME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* ##sys#peek-c-string */
t3=*((C_word*)lf[50]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LIB_NAME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k3951 in main#libchicken in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in ... */
static void C_ccall f_3953(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3953,c,av);}
/* csc.scm:119: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[81];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3986 in main#linker-libraries in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_3988(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3988,c,av);}
/* csc.scm:130: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[109],C_text("main#library-dir"));
av2[3]=t1;
av2[4]=C_retrieve2(lf[69],C_text("main#library-extension"));
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in ... */
static void C_ccall f_3992(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3992,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[82] /* (set! main#default-compilation-optimization-options ...) */,t1);
t3=C_mutate(&lf[83] /* (set! main#best-compilation-optimization-options ...) */,C_retrieve2(lf[82],C_text("main#default-compilation-optimization-options")));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3997,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7620,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
/* ##sys#peek-c-string */
t6=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LDFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
/* ##sys#peek-c-string */
t6=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LDFLAGS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in ... */
static void C_ccall f_3997(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3997,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[84] /* (set! main#default-linking-optimization-options ...) */,t1);
t3=C_mutate(&lf[85] /* (set! main#best-linking-optimization-options ...) */,C_retrieve2(lf[84],C_text("main#default-linking-optimization-options")));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4002,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_END_OF_LIST;
f_4002(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7616,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_TARGET_FEATURES);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}

/* k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in ... */
static void C_ccall f_4002(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4002,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[86] /* (set! main#extra-features ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4009,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#string->list */
t4=C_fast_retrieve(lf[351]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[421];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in ... */
static void C_ccall f_4009(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4009,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[87] /* (set! main#short-options ...) */,t1);
t3=lf[88] /* main#scheme-files */ =C_SCHEME_END_OF_LIST;;
t4=lf[89] /* main#c-files */ =C_SCHEME_END_OF_LIST;;
t5=lf[90] /* main#rc-files */ =C_SCHEME_END_OF_LIST;;
t6=lf[91] /* main#generated-c-files */ =C_SCHEME_END_OF_LIST;;
t7=lf[92] /* main#generated-rc-files */ =C_SCHEME_END_OF_LIST;;
t8=lf[93] /* main#object-files */ =C_SCHEME_END_OF_LIST;;
t9=lf[94] /* main#generated-object-files */ =C_SCHEME_END_OF_LIST;;
t10=lf[95] /* main#transient-link-files */ =C_SCHEME_END_OF_LIST;;
t11=lf[96] /* main#linked-extensions */ =C_SCHEME_END_OF_LIST;;
t12=lf[97] /* main#cpp-mode */ =C_SCHEME_FALSE;;
t13=lf[98] /* main#objc-mode */ =C_SCHEME_FALSE;;
t14=lf[99] /* main#embedded */ =C_SCHEME_FALSE;;
t15=lf[100] /* main#inquiry-only */ =C_SCHEME_FALSE;;
t16=lf[101] /* main#show-cflags */ =C_SCHEME_FALSE;;
t17=lf[102] /* main#show-ldflags */ =C_SCHEME_FALSE;;
t18=lf[103] /* main#show-libs */ =C_SCHEME_FALSE;;
t19=lf[104] /* main#dry-run */ =C_SCHEME_FALSE;;
t20=lf[105] /* main#deployed */ =C_SCHEME_FALSE;;
t21=lf[106] /* main#rpath */ =C_SCHEME_FALSE;;
t22=lf[107] /* main#ignore-repository */ =C_SCHEME_FALSE;;
t23=lf[108] /* main#show-debugging-help */ =C_SCHEME_FALSE;;
t24=(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))?C_retrieve2(lf[18],C_text("main#host-libdir")):C_retrieve2(lf[11],C_text("main#default-libdir")));
t25=C_mutate(&lf[109] /* (set! main#library-dir ...) */,t24);
t26=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4039,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
/* ##sys#peek-c-string */
t27=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t27;
av2[1]=t26;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_MORE_STATIC_LIBS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t27+1)))(4,av2);}}
else{
/* ##sys#peek-c-string */
t27=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t27;
av2[1]=t26;
av2[2]=C_mpointer(&a,(void*)C_TARGET_MORE_STATIC_LIBS);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t27+1)))(4,av2);}}}

/* k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in ... */
static void C_ccall f_4039(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4039,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[110] /* (set! main#extra-libraries ...) */,t1);
t3=(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))?C_retrieve2(lf[22],C_text("main#host-libs")):C_retrieve2(lf[10],C_text("main#default-libs")));
t4=C_mutate(&lf[111] /* (set! main#extra-shared-libraries ...) */,t3);
t5=lf[112] /* main#translate-options */ =C_SCHEME_END_OF_LIST;;
t6=(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))?C_retrieve2(lf[20],C_text("main#host-incdir")):C_retrieve2(lf[13],C_text("main#default-incdir")));
t7=C_i_member(t6,lf[113]);
t8=C_i_not(t7);
t9=(C_truep(t8)?t6:C_SCHEME_FALSE);
t10=C_mutate(&lf[114] /* (set! main#include-dir ...) */,t9);
t11=lf[115] /* main#compile-options */ =C_SCHEME_END_OF_LIST;;
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4092,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7486,a[2]=t12,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[114],C_text("main#include-dir")))){
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7596,a[2]=t13,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:248: chicken.string#conc */
t15=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t15;
av2[1]=t14;
av2[2]=lf[420];
av2[3]=C_retrieve2(lf[114],C_text("main#include-dir"));
((C_proc)(void*)(*((C_word*)t15+1)))(4,av2);}}
else{
t14=t13;
f_7486(t14,C_SCHEME_END_OF_LIST);}}

/* k4051 in main#linker-libraries in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_4053(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4053,c,av);}
a=C_alloc(6);
t2=C_a_i_list1(&a,1,t1);
t3=(C_truep(C_retrieve2(lf[131],C_text("main#static")))?C_a_i_list1(&a,1,C_retrieve2(lf[110],C_text("main#extra-libraries"))):C_a_i_list1(&a,1,C_retrieve2(lf[111],C_text("main#extra-shared-libraries"))));
/* csc.scm:1046: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k4055 in main#linker-libraries in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_4057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4057,c,av);}
/* csc.scm:232: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[146];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4071 in main#linker-libraries in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_4073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4073,c,av);}
a=C_alloc(6);
t2=C_a_i_list1(&a,1,t1);
t3=(C_truep(C_retrieve2(lf[131],C_text("main#static")))?C_a_i_list1(&a,1,C_retrieve2(lf[110],C_text("main#extra-libraries"))):C_a_i_list1(&a,1,C_retrieve2(lf[111],C_text("main#extra-shared-libraries"))));
/* csc.scm:1046: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in ... */
static void C_ccall f_4092(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_4092,c,av);}
a=C_alloc(26);
t2=C_mutate(&lf[116] /* (set! main#builtin-compile-options ...) */,t1);
t3=lf[117] /* main#translation-optimization-options */ =C_SCHEME_END_OF_LIST;;
t4=C_mutate(&lf[118] /* (set! main#compilation-optimization-options ...) */,C_retrieve2(lf[82],C_text("main#default-compilation-optimization-options")));
t5=C_mutate(&lf[119] /* (set! main#linking-optimization-options ...) */,C_retrieve2(lf[84],C_text("main#default-linking-optimization-options")));
t6=lf[120] /* main#link-options */ =C_SCHEME_END_OF_LIST;;
t7=(C_truep(C_retrieve2(lf[38],C_text("main#solaris")))?lf[121]:lf[122]);
t8=C_mutate(&lf[123] /* (set! main#rpath-option ...) */,t7);
t9=lf[124] /* main#target-filename */ =C_SCHEME_FALSE;;
t10=lf[125] /* main#verbose */ =C_SCHEME_FALSE;;
t11=lf[126] /* main#keep-files */ =C_SCHEME_FALSE;;
t12=lf[127] /* main#translate-only */ =C_SCHEME_FALSE;;
t13=lf[128] /* main#compile-only */ =C_SCHEME_FALSE;;
t14=lf[129] /* main#to-stdout */ =C_SCHEME_FALSE;;
t15=lf[130] /* main#shared */ =C_SCHEME_FALSE;;
t16=lf[131] /* main#static */ =C_SCHEME_FALSE;;
t17=C_mutate(&lf[132] /* (set! main#repo-path ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4234,tmp=(C_word)a,a+=2,tmp));
t18=C_mutate(&lf[134] /* (set! main#find-object-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4246,tmp=(C_word)a,a+=2,tmp));
t19=C_mutate(&lf[139] /* (set! main#compiler-options ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6723,tmp=(C_word)a,a+=2,tmp));
t20=C_mutate(&lf[144] /* (set! main#linker-options ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7204,tmp=(C_word)a,a+=2,tmp));
t21=C_mutate(&lf[145] /* (set! main#linker-libraries ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7257,tmp=(C_word)a,a+=2,tmp));
t22=C_mutate(&lf[140] /* (set! main#quote-option ...) */,C_fast_retrieve(lf[55]));
t23=lf[147] /* main#last-exit-code */ =C_SCHEME_FALSE;;
t24=C_mutate(&lf[148] /* (set! main#command ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7398,tmp=(C_word)a,a+=2,tmp));
t25=C_mutate(&lf[161] /* (set! main#$delete-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7411,tmp=(C_word)a,a+=2,tmp));
t26=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7461,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t27=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7471,a[2]=t26,tmp=(C_word)a,a+=3,tmp);
t28=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7475,a[2]=t27,tmp=(C_word)a,a+=3,tmp);
t29=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7479,a[2]=t28,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1123: chicken.process-context#get-environment-variable */
t30=C_fast_retrieve(lf[159]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t30;
av2[1]=t29;
av2[2]=lf[416];
((C_proc)(void*)(*((C_word*)t30+1)))(3,av2);}}

/* k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_fcall f_4111(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_4111,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4115,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[105],C_text("main#deployed")))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4185,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:277: chicken.platform#software-version */
t4=C_fast_retrieve(lf[242]);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t2;
f_4115(t3,C_SCHEME_END_OF_LIST);}}

/* k4113 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_fcall f_4115(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4115,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4119,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:280: chicken.process-context#get-environment-variable */
t3=C_fast_retrieve(lf[159]);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[237];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4117 in k4113 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4119(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_4119,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4122,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4135,a[2]=t5,a[3]=t6,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:282: chicken.string#string-split */
t8=C_fast_retrieve(lf[235]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=t1;
av2[3]=lf[236];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
/* csc.scm:263: scheme#append */
t3=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k4120 in k4117 in k4113 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4122(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4122,c,av);}
/* csc.scm:263: scheme#append */
t2=*((C_word*)lf[143]+1);{
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

/* k4133 in k4117 in k4113 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4135,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4140,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_4140(t5,((C_word*)t0)[4],t1);}

/* map-loop966 in k4133 in k4117 in k4113 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_fcall f_4140(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_4140,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4165,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:282: g989 */
t4=*((C_word*)lf[80]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[234];
av2[3]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4163 in map-loop966 in k4133 in k4117 in k4113 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_4165(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4165,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4140(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4183 in k4109 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4185,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_4115(t2,(C_truep((C_truep(C_eqp(t1,lf[238]))?C_SCHEME_TRUE:(C_truep(C_eqp(t1,lf[239]))?C_SCHEME_TRUE:(C_truep(C_eqp(t1,lf[240]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))?C_a_i_list1(&a,1,lf[241]):C_SCHEME_END_OF_LIST));}

/* k4191 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4193(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4193,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4197,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4201,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[105],C_text("main#deployed")))){
/* csc.scm:267: chicken.string#conc */
t4=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[244];
av2[3]=C_retrieve2(lf[123],C_text("main#rpath-option"));
av2[4]=lf[245];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t4=C_retrieve2(lf[18],C_text("main#host-libdir"));
t5=C_retrieve2(lf[18],C_text("main#host-libdir"));
/* csc.scm:267: chicken.string#conc */
t6=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=lf[244];
av2[3]=C_retrieve2(lf[123],C_text("main#rpath-option"));
av2[4]=C_retrieve2(lf[18],C_text("main#host-libdir"));
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}}

/* k4195 in k4191 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4197,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];
f_4111(t2,C_a_i_list2(&a,2,((C_word*)t0)[3],t1));}

/* k4199 in k4191 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4201(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4201,c,av);}
/* csc.scm:267: chicken.string#conc */
t2=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[244];
av2[3]=C_retrieve2(lf[123],C_text("main#rpath-option"));
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4215 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4217(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4217,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_4111(t2,C_a_i_list1(&a,1,t1));}

/* k4222 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4224,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_4111(t2,C_a_i_list1(&a,1,t1));}

/* main#repo-path in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_fcall f_4234(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,1)))){
C_save_and_reclaim_args((void *)trf_4234,1,t1);}
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
/* csc.scm:299: chicken.platform#repository-path */
t2=C_fast_retrieve(lf[133]);{
C_word av2[2];
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_SCHEME_END_OF_LIST;
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_retrieve2(lf[26],C_text("main#target-repo"));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=(C_truep(t3)?C_retrieve2(lf[27],C_text("main#target-run-repo")):C_retrieve2(lf[26],C_text("main#target-repo")));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}

/* main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_4246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4246,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4250,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:303: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
av2[3]=t2;
av2[4]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_4250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4250,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4253,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:304: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)t0)[3];
av2[4]=C_retrieve2(lf[69],C_text("main#library-extension"));
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_4253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4253,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4256,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:306: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)t0)[4];
av2[4]=C_retrieve2(lf[76],C_text("main#static-library-extension"));
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4256,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4259,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:307: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
av2[3]=((C_word*)t0)[5];
av2[4]=C_retrieve2(lf[75],C_text("main#static-object-extension"));
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4259(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4259,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4262,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* csc.scm:308: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[137]);{
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

/* k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4262,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4268,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* csc.scm:309: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[137]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k4266 in k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4268(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4268,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4274,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(C_fast_retrieve(lf[136]),C_SCHEME_TRUE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4306,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:311: chicken.file#file-exists? */
t5=C_fast_retrieve(lf[137]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_4274(2,av2);}}}}

/* k4272 in k4266 in k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4274(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4274,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_not(C_retrieve2(lf[107],C_text("main#ignore-repository"))))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4286,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4300,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:314: repo-path */
f_4234(t3);}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* k4284 in k4272 in k4266 in k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_4286(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4286,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4296,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:315: repo-path */
f_4234(t2);}}

/* k4294 in k4284 in k4272 in k4266 in k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_4296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4296,c,av);}
/* csc.scm:315: chicken.load#find-file */
t2=C_fast_retrieve(lf[135]);{
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

/* k4298 in k4272 in k4266 in k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_4300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4300,c,av);}
/* csc.scm:314: chicken.load#find-file */
t2=C_fast_retrieve(lf[135]);{
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

/* k4304 in k4266 in k4260 in k4257 in k4254 in k4251 in k4248 in main#find-object-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4306,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_4274(2,av2);}}
else{
/* csc.scm:312: chicken.file#file-exists? */
t2=C_fast_retrieve(lf[137]);{
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

/* k4316 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4318(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_4318,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4325,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_cons(&a,2,lf[253],C_SCHEME_END_OF_LIST);
t4=C_a_i_cons(&a,2,t1,t3);
t5=C_a_i_cons(&a,2,lf[254],t4);
t6=C_a_i_cons(&a,2,t1,t5);
t7=C_a_i_cons(&a,2,lf[255],t6);
t8=C_a_i_cons(&a,2,t1,t7);
t9=C_a_i_cons(&a,2,lf[256],t8);
/* csc.scm:28: ##sys#print-to-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[208]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[208]+1);
av2[1]=t2;
av2[2]=t9;
tp(3,av2);}}

/* k4323 in k4316 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4325(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4325,c,av);}
/* csc.scm:322: chicken.base#print */
t2=*((C_word*)lf[154]+1);{
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

/* t-options in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_fcall f_4358(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_4358,2,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4363,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:537: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[112],C_text("main#translate-options"));
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k4361 in t-options in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_4363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4363,c,av);}
t2=C_mutate(&lf[112] /* (set! main#translate-options ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* check in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_fcall f_4365(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_4365,4,t1,t2,t3,t4);}
a=C_alloc(3);
t5=C_i_length(t3);
if(C_truep(C_i_nullp(t4))){
if(C_truep(C_i_greater_or_equalp(t5,C_fix(1)))){
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
/* csc.scm:541: stop */
f_3821(t1,lf[165],C_a_i_list(&a,1,t2));}}
else{
t6=C_i_car(t4);
if(C_truep(C_i_greater_or_equalp(t5,t6))){
t7=C_SCHEME_UNDEFINED;
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
/* csc.scm:541: stop */
f_3821(t1,lf[165],C_a_i_list(&a,1,t2));}}}

/* shared-build in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_fcall f_4391(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_4391,2,t1,t2);}
a=C_alloc(10);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4396,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:544: cons* */
f_2939(t3,lf[170],C_a_i_list(&a,2,lf[171],C_retrieve2(lf[112],C_text("main#translate-options"))));}

/* k4394 in shared-build in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_4396(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4396,c,av);}
a=C_alloc(4);
t2=C_mutate(&lf[112] /* (set! main#translate-options ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4400,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:545: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[77],C_text("main#pic-options"));
av2[3]=lf[169];
av2[4]=C_retrieve2(lf[115],C_text("main#compile-options"));
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4398 in k4394 in shared-build in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4400,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4404,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[33],C_text("main#osx")))){
if(C_truep(((C_word*)t0)[3])){
/* csc.scm:547: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[166];
av2[3]=C_retrieve2(lf[120],C_text("main#link-options"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* csc.scm:547: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[167];
av2[3]=C_retrieve2(lf[120],C_text("main#link-options"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}
else{
/* csc.scm:547: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[168];
av2[3]=C_retrieve2(lf[120],C_text("main#link-options"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k4402 in k4398 in k4394 in shared-build in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4404(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4404,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
t3=lf[130] /* main#shared */ =C_SCHEME_TRUE;;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* generate-target-filename in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_fcall f_4421(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_4421,2,t1,t2);}
if(C_truep(C_retrieve2(lf[130],C_text("main#shared")))){
t3=C_retrieve2(lf[73],C_text("main#shared-library-extension"));
t4=C_retrieve2(lf[73],C_text("main#shared-library-extension"));
/* csc.scm:557: chicken.pathname#pathname-replace-extension */
t5=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_retrieve2(lf[73],C_text("main#shared-library-extension"));
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
if(C_truep(C_retrieve2(lf[128],C_text("main#compile-only")))){
t3=C_retrieve2(lf[68],C_text("main#object-extension"));
t4=C_retrieve2(lf[68],C_text("main#object-extension"));
/* csc.scm:557: chicken.pathname#pathname-replace-extension */
t5=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t3=C_retrieve2(lf[71],C_text("main#executable-extension"));
/* csc.scm:557: chicken.pathname#pathname-replace-extension */
t4=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_retrieve2(lf[71],C_text("main#executable-extension"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}}

/* loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_fcall f_4437(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_4437,3,t0,t1,t2);}
a=C_alloc(11);
if(C_truep(C_i_nullp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4448,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:566: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[115],C_text("main#compile-options"));
av2[3]=C_retrieve2(lf[116],C_text("main#builtin-compile-options"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4704,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t5,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t3,a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
/* csc.scm:619: scheme#string->symbol */
t7=*((C_word*)lf[414]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_4448(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,6)))){
C_save_and_reclaim((void *)f_4448,c,av);}
a=C_alloc(13);
t2=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4452,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4697,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4111,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[40],C_text("main#elf")))){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4193,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:266: chicken.string#conc */
t7=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[246];
av2[3]=C_retrieve2(lf[109],C_text("main#library-dir"));
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
if(C_truep(C_retrieve2(lf[37],C_text("main#aix")))){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4217,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:274: chicken.string#conc */
t7=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[247];
av2[3]=C_retrieve2(lf[123],C_text("main#rpath-option"));
av2[4]=lf[248];
av2[5]=C_retrieve2(lf[109],C_text("main#library-dir"));
av2[6]=lf[249];
((C_proc)(void*)(*((C_word*)t7+1)))(7,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4224,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:276: chicken.string#conc */
t7=C_fast_retrieve(lf[243]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[250];
av2[3]=C_retrieve2(lf[109],C_text("main#library-dir"));
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}}

/* k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4452(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4452,c,av);}
a=C_alloc(10);
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4455,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[100],C_text("main#inquiry-only")))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4660,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[101],C_text("main#show-cflags")))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4693,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:570: compiler-options */
f_6723(t5);}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_4660(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_4455(2,av2);}}}

/* k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4455(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4455,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4458,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[128],C_text("main#compile-only")))){
t3=C_i_length(C_retrieve2(lf[88],C_text("main#scheme-files")));
t4=C_i_length(C_retrieve2(lf[89],C_text("main#c-files")));
t5=C_a_i_fixnum_plus(&a,2,t3,t4);
if(C_truep(C_i_integer_greaterp(t5,C_fix(1)))){
/* csc.scm:579: stop */
f_3821(t2,lf[231],C_SCHEME_END_OF_LIST);}
else{
t6=t2;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_4458(2,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4458(2,av2);}}}

/* k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4458(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_4458,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4461,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(C_retrieve2(lf[88],C_text("main#scheme-files"))))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4570,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_i_nullp(C_retrieve2(lf[89],C_text("main#c-files")));
t5=(C_truep(t4)?C_i_nullp(C_retrieve2(lf[93],C_text("main#object-files"))):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4594,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[108],C_text("main#show-debugging-help")))){
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4604,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4608,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:586: cons* */
f_2939(t8,C_retrieve2(lf[60],C_text("main#translator")),C_a_i_list(&a,2,lf[215],C_retrieve2(lf[112],C_text("main#translate-options"))));}
else{
/* csc.scm:587: stop */
f_3821(t3,lf[214],C_SCHEME_END_OF_LIST);}}
else{
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_4570(2,av2);}}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4617,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(C_truep(C_retrieve2(lf[130],C_text("main#shared")))?C_i_not(C_retrieve2(lf[99],C_text("main#embedded"))):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_a_i_cons(&a,2,lf[230],C_retrieve2(lf[112],C_text("main#translate-options")));
t6=C_mutate(&lf[112] /* (set! main#translate-options ...) */,t5);
t7=t3;
f_4617(t7,t6);}
else{
t5=t3;
f_4617(t5,C_SCHEME_UNDEFINED);}}}

/* k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4461(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_4461,c,av);}
a=C_alloc(18);
if(C_truep(C_retrieve2(lf[127],C_text("main#translate-only")))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4467,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_SCHEME_END_OF_LIST;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6451,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=C_retrieve2(lf[89],C_text("main#c-files"));
t7=C_i_check_list_2(C_retrieve2(lf[89],C_text("main#c-files")),lf[173]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6537,a[2]=t4,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6700,a[2]=t10,a[3]=t5,tmp=(C_word)a,a+=4,tmp));
t12=((C_word*)t10)[1];
f_6700(t12,t8,C_retrieve2(lf[89],C_text("main#c-files")));}}

/* k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4467(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_4467,c,av);}
a=C_alloc(14);
if(C_truep(C_retrieve2(lf[128],C_text("main#compile-only")))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4473,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_pairp(C_retrieve2(lf[96],C_text("main#linked-extensions"))))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4560,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4564,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_retrieve2(lf[134],C_text("main#find-object-file"));
t6=C_retrieve2(lf[96],C_text("main#linked-extensions"));
t7=C_retrieve2(lf[96],C_text("main#linked-extensions"));
t8=C_i_noop2(C_retrieve2(lf[96],C_text("main#linked-extensions")),C_SCHEME_UNDEFINED);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3168,a[2]=t10,tmp=(C_word)a,a+=3,tmp));
t12=((C_word*)t10)[1];
f_3168(t12,t4,C_retrieve2(lf[96],C_text("main#linked-extensions")));}
else{
t3=t2;
f_4473(t3,C_SCHEME_UNDEFINED);}}}

/* k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_fcall f_4473(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_4473,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4476,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_member(C_retrieve2(lf[124],C_text("main#target-filename")),C_retrieve2(lf[88],C_text("main#scheme-files"))))){
t3=*((C_word*)lf[43]+1);
t4=*((C_word*)lf[43]+1);
t5=C_i_check_port_2(*((C_word*)lf[43]+1),C_fix(2),C_SCHEME_TRUE,lf[44]);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4488,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:606: ##sys#print */
t7=*((C_word*)lf[48]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[198];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[43]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4476(2,av2);}}}

/* k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_4476(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_4476,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6781,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_retrieve2(lf[93],C_text("main#object-files"));
t4=C_retrieve2(lf[94],C_text("main#generated-object-files"));
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7079,a[2]=t6,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_7079(t8,t2,C_retrieve2(lf[93],C_text("main#object-files")),C_retrieve2(lf[93],C_text("main#object-files")));}

/* k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_4488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4488,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4491,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:606: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_4491(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4491,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4494,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:606: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[197];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_4494(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4494,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4497,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:606: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_4497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4497,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4500,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:606: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[196];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_4500(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4500,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4503,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:606: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[46]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_4503(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4503,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4510,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:610: chicken.base#open-output-string */
t3=C_fast_retrieve(lf[195]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_4510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4510,c,av);}
a=C_alloc(4);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[190]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4516,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_mk_bool(C_WINDOWS_SHELL))){
/* csc.scm:610: ##sys#print */
t4=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[193];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* csc.scm:610: ##sys#print */
t4=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[194];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_ccall f_4516(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4516,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4519,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:610: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[46]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in ... */
static void C_ccall f_4519(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4519,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4522,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_mk_bool(C_WINDOWS_SHELL))){
t3=C_retrieve2(lf[58],C_text("main#quotewrap-no-slash-trans"));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f8476,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t5=C_retrieve2(lf[124],C_text("main#target-filename"));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f8556,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:93: chicken.pathname#normalize-pathname */
t7=C_fast_retrieve(lf[57]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t3=C_retrieve2(lf[54],C_text("main#quotewrap"));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f8480,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:610: g1097 */
t5=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
f_3870(3,av2);}}}

/* k4520 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in ... */
static void C_ccall f_4522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4522,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4525,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:610: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[46]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k4523 in k4520 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in ... */
static void C_ccall f_4525(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_4525,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4528,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(C_truep(C_mk_bool(C_WINDOWS_SHELL))?C_retrieve2(lf[58],C_text("main#quotewrap-no-slash-trans")):C_retrieve2(lf[54],C_text("main#quotewrap")));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4538,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4542,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:614: scheme#string-append */
t6=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
av2[3]=lf[192];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k4526 in k4523 in k4520 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in ... */
static void C_ccall f_4528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4528,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4531,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:610: chicken.base#get-output-string */
t3=C_fast_retrieve(lf[191]);{
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

/* k4529 in k4526 in k4523 in k4520 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in ... */
static void C_ccall f_4531(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4531,c,av);}
/* csc.scm:609: command */
f_7398(((C_word*)t0)[2],t1);}

/* k4536 in k4523 in k4520 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in ... */
static void C_ccall f_4538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4538,c,av);}
/* csc.scm:610: ##sys#print */
t2=*((C_word*)lf[48]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4540 in k4523 in k4520 in k4517 in k4514 in k4508 in k4501 in k4498 in k4495 in k4492 in k4489 in k4486 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in ... */
static void C_ccall f_4542(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4542,c,av);}
/* csc.scm:610: g1099 */
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

/* k4558 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_4560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4560,c,av);}
t2=C_mutate(&lf[93] /* (set! main#object-files ...) */,t1);
t3=((C_word*)t0)[2];
f_4473(t3,t2);}

/* k4562 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_4564(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4564,c,av);}
/* csc.scm:604: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[93],C_text("main#object-files"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4568 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4570(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4570,c,av);}
a=C_alloc(5);
if(C_truep(C_retrieve2(lf[124],C_text("main#target-filename")))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_4461(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4577,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_i_nullp(C_retrieve2(lf[89],C_text("main#c-files")));
t4=(C_truep(t3)?C_retrieve2(lf[93],C_text("main#object-files")):C_retrieve2(lf[89],C_text("main#c-files")));
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3281,tmp=(C_word)a,a+=2,tmp);
t6=(
  f_3281(t4)
);
/* csc.scm:590: generate-target-filename */
f_4421(t2,t6);}}

/* k4575 in k4568 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4577(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4577,c,av);}
t2=C_mutate(&lf[124] /* (set! main#target-filename ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_4461(2,av2);}}

/* k4592 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4594,c,av);}
/* csc.scm:587: stop */
f_3821(((C_word*)t0)[2],lf[214],C_SCHEME_END_OF_LIST);}

/* k4602 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4604(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4604,c,av);}
/* csc.scm:584: command */
f_7398(((C_word*)t0)[2],t1);}

/* k4606 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4608,c,av);}
/* csc.scm:585: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[142]);{
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

/* k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_fcall f_4617(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4617,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4620,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[124],C_text("main#target-filename")))){
t3=t2;
f_4620(t3,C_SCHEME_UNDEFINED);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4627,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_retrieve2(lf[88],C_text("main#scheme-files"));
/* csc.scm:597: generate-target-filename */
f_4421(t3,C_i_car(C_retrieve2(lf[88],C_text("main#scheme-files"))));}}

/* k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_fcall f_4620(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4620,2,t0,t1);}
a=C_alloc(5);
t2=C_retrieve2(lf[88],C_text("main#scheme-files"));
t3=C_i_check_list_2(C_retrieve2(lf[88],C_text("main#scheme-files")),lf[173]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6426,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_6426(t7,((C_word*)t0)[2],C_retrieve2(lf[88],C_text("main#scheme-files")));}

/* k4625 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4627(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4627,c,av);}
t2=C_mutate(&lf[124] /* (set! main#target-filename ...) */,t1);
t3=((C_word*)t0)[2];
f_4620(t3,t2);}

/* k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4660(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4660,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4663,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[102],C_text("main#show-ldflags")))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4686,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:571: linker-options */
f_7204(t3);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4663(2,av2);}}}

/* k4661 in k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4663,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4666,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[103],C_text("main#show-libs")))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4679,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:572: linker-libraries */
f_7257(t3);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f8512,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:573: scheme#newline */
t4=*((C_word*)lf[232]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4664 in k4661 in k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4666,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4669,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:573: scheme#newline */
t3=*((C_word*)lf[232]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4667 in k4664 in k4661 in k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4669(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4669,c,av);}
/* csc.scm:574: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4677 in k4661 in k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4679,c,av);}
/* csc.scm:572: chicken.base#print* */
t2=*((C_word*)lf[233]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_make_character(32);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4684 in k4658 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4686,c,av);}
/* csc.scm:571: chicken.base#print* */
t2=*((C_word*)lf[233]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_make_character(32);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4691 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4693(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4693,c,av);}
/* csc.scm:570: chicken.base#print* */
t2=*((C_word*)lf[233]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_make_character(32);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4695 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4697,c,av);}
/* csc.scm:567: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[120],C_text("main#link-options"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_4704(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_4704,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4707,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(t1,lf[251]);
t4=(C_truep(t3)?t3:C_eqp(t1,lf[252]));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4719,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4318,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t7=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=C_mpointer(&a,(void*)C_CSC_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t5=C_eqp(t1,lf[257]);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4731,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4738,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:625: chicken.platform#chicken-version */
t8=C_fast_retrieve(lf[258]);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t6=C_eqp(t1,lf[259]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4747,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4754,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:628: chicken.base#open-output-string */
t9=C_fast_retrieve(lf[195]);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t7=C_eqp(t1,lf[261]);
if(C_truep(t7)){
t8=lf[97] /* main#cpp-mode */ =C_SCHEME_TRUE;;
if(C_truep(C_retrieve2(lf[33],C_text("main#osx")))){
t9=C_a_i_cons(&a,2,lf[262],C_retrieve2(lf[115],C_text("main#compile-options")));
t10=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t9);
/* csc.scm:864: loop */
t11=((C_word*)((C_word*)t0)[2])[1];
f_4437(t11,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
/* csc.scm:864: loop */
t9=((C_word*)((C_word*)t0)[2])[1];
f_4437(t9,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}}
else{
t8=C_eqp(t1,lf[263]);
if(C_truep(t8)){
t9=lf[98] /* main#objc-mode */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t10=((C_word*)((C_word*)t0)[2])[1];
f_4437(t10,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t9=C_eqp(t1,lf[264]);
if(C_truep(t9)){
t10=C_a_i_cons(&a,2,lf[265],C_retrieve2(lf[112],C_text("main#translate-options")));
t11=C_mutate(&lf[112] /* (set! main#translate-options ...) */,t10);
t12=lf[131] /* main#static */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t13=((C_word*)((C_word*)t0)[2])[1];
f_4437(t13,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t10=C_eqp(t1,lf[266]);
if(C_truep(t10)){
t11=lf[100] /* main#inquiry-only */ =C_SCHEME_TRUE;;
t12=lf[101] /* main#show-cflags */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t13=((C_word*)((C_word*)t0)[2])[1];
f_4437(t13,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t11=C_eqp(t1,lf[267]);
if(C_truep(t11)){
t12=lf[100] /* main#inquiry-only */ =C_SCHEME_TRUE;;
t13=lf[102] /* main#show-ldflags */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t14=((C_word*)((C_word*)t0)[2])[1];
f_4437(t14,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t12=C_eqp(t1,lf[268]);
if(C_truep(t12)){
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4826,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:644: chicken.base#print */
t14=*((C_word*)lf[154]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t14;
av2[1]=t13;
av2[2]=C_retrieve2(lf[61],C_text("main#compiler"));
((C_proc)(void*)(*((C_word*)t14+1)))(3,av2);}}
else{
t13=C_eqp(t1,lf[269]);
if(C_truep(t13)){
t14=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4838,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:645: chicken.base#print */
t15=*((C_word*)lf[154]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t15;
av2[1]=t14;
av2[2]=C_retrieve2(lf[62],C_text("main#c++-compiler"));
((C_proc)(void*)(*((C_word*)t15+1)))(3,av2);}}
else{
t14=C_eqp(t1,lf[270]);
if(C_truep(t14)){
t15=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4850,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:646: chicken.base#print */
t16=*((C_word*)lf[154]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t16;
av2[1]=t15;
av2[2]=C_retrieve2(lf[64],C_text("main#linker"));
((C_proc)(void*)(*((C_word*)t16+1)))(3,av2);}}
else{
t15=C_eqp(t1,lf[271]);
if(C_truep(t15)){
t16=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4862,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:647: chicken.base#print */
t17=*((C_word*)lf[154]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t17;
av2[1]=t16;
av2[2]=C_retrieve2(lf[59],C_text("main#home"));
((C_proc)(void*)(*((C_word*)t17+1)))(3,av2);}}
else{
t16=C_eqp(t1,lf[272]);
if(C_truep(t16)){
t17=lf[100] /* main#inquiry-only */ =C_SCHEME_TRUE;;
t18=lf[103] /* main#show-libs */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t19=((C_word*)((C_word*)t0)[2])[1];
f_4437(t19,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t17=C_eqp(t1,lf[273]);
t18=(C_truep(t17)?t17:C_eqp(t1,lf[274]));
if(C_truep(t18)){
t19=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4885,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_numberp(C_retrieve2(lf[125],C_text("main#verbose"))))){
t20=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4900,a[2]=t19,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:653: cons* */
f_2939(t20,lf[277],C_a_i_list(&a,2,lf[278],C_retrieve2(lf[115],C_text("main#compile-options"))));}
else{
t20=t19;
f_4885(t20,C_SCHEME_UNDEFINED);}}
else{
t19=C_eqp(t1,lf[279]);
t20=(C_truep(t19)?t19:C_eqp(t1,lf[280]));
if(C_truep(t20)){
t21=C_a_i_cons(&a,2,lf[281],C_retrieve2(lf[115],C_text("main#compile-options")));
t22=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t21);
/* csc.scm:661: t-options */
f_4358(t2,C_a_i_list(&a,1,lf[282]));}
else{
t21=C_eqp(t1,lf[283]);
t22=(C_truep(t21)?t21:C_eqp(t1,lf[284]));
if(C_truep(t22)){
t23=lf[127] /* main#translate-only */ =C_SCHEME_TRUE;;
/* csc.scm:664: t-options */
f_4358(t2,C_a_i_list(&a,1,lf[285]));}
else{
t23=C_eqp(t1,lf[286]);
t24=(C_truep(t23)?t23:C_eqp(t1,lf[287]));
if(C_truep(t24)){
t25=lf[127] /* main#translate-only */ =C_SCHEME_TRUE;;
/* csc.scm:667: t-options */
f_4358(t2,C_a_i_list(&a,1,lf[288]));}
else{
t25=C_eqp(t1,lf[289]);
if(C_truep(t25)){
t26=lf[126] /* main#keep-files */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t27=((C_word*)((C_word*)t0)[2])[1];
f_4437(t27,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t26=C_eqp(t1,lf[290]);
if(C_truep(t26)){
t27=lf[128] /* main#compile-only */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t28=((C_word*)((C_word*)t0)[2])[1];
f_4437(t28,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t27=C_eqp(t1,lf[291]);
if(C_truep(t27)){
t28=lf[127] /* main#translate-only */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t29=((C_word*)((C_word*)t0)[2])[1];
f_4437(t29,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t28=C_eqp(t1,lf[292]);
t29=(C_truep(t28)?t28:C_eqp(t1,lf[293]));
if(C_truep(t29)){
t30=lf[99] /* main#embedded */ =C_SCHEME_TRUE;;
t31=C_a_i_cons(&a,2,lf[294],C_retrieve2(lf[115],C_text("main#compile-options")));
t32=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t31);
/* csc.scm:864: loop */
t33=((C_word*)((C_word*)t0)[2])[1];
f_4437(t33,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t30=C_eqp(t1,lf[295]);
if(C_truep(t30)){
t31=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4990,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:675: check */
f_4365(t31,t1,((C_word*)((C_word*)t0)[4])[1],C_SCHEME_END_OF_LIST);}
else{
t31=C_eqp(t1,lf[298]);
if(C_truep(t31)){
t32=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5022,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:681: check */
f_4365(t32,t1,((C_word*)((C_word*)t0)[4])[1],C_SCHEME_END_OF_LIST);}
else{
t32=C_eqp(t1,lf[299]);
t33=(C_truep(t32)?t32:C_eqp(t1,lf[300]));
if(C_truep(t33)){
t34=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5042,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:685: check */
f_4365(t34,t1,((C_word*)((C_word*)t0)[4])[1],C_SCHEME_END_OF_LIST);}
else{
t34=C_eqp(t1,lf[302]);
if(C_truep(t34)){
t35=C_a_i_cons(&a,2,lf[303],C_retrieve2(lf[115],C_text("main#compile-options")));
t36=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t35);
/* csc.scm:864: loop */
t37=((C_word*)((C_word*)t0)[2])[1];
f_4437(t37,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t35=C_eqp(t1,lf[304]);
if(C_truep(t35)){
t36=lf[107] /* main#ignore-repository */ =C_SCHEME_TRUE;;
/* csc.scm:692: t-options */
f_4358(t2,C_a_i_list(&a,1,((C_word*)t0)[7]));}
else{
t36=C_eqp(t1,lf[305]);
if(C_truep(t36)){
t37=C_set_block_item(lf[136] /* ##sys#setup-mode */,0,C_SCHEME_TRUE);
/* csc.scm:695: t-options */
f_4358(t2,C_a_i_list(&a,1,((C_word*)t0)[7]));}
else{
t37=C_eqp(t1,lf[306]);
if(C_truep(t37)){
t38=lf[78] /* main#generate-manifest */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t39=((C_word*)((C_word*)t0)[2])[1];
f_4437(t39,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t38=C_eqp(t1,lf[307]);
if(C_truep(t38)){
t39=C_a_i_cons(&a,2,lf[308],C_retrieve2(lf[115],C_text("main#compile-options")));
t40=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t39);
if(C_truep(C_retrieve2(lf[31],C_text("main#mingw")))){
t41=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5115,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:703: chicken.pathname#make-pathname */
t42=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t42;
av2[1]=t41;
av2[2]=C_retrieve2(lf[21],C_text("main#host-sharedir"));
av2[3]=lf[313];
av2[4]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t42+1)))(5,av2);}}
else{
/* csc.scm:864: loop */
t41=((C_word*)((C_word*)t0)[2])[1];
f_4437(t41,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}}
else{
t39=C_eqp(t1,lf[314]);
if(C_truep(t39)){
t40=lf[105] /* main#deployed */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t41=((C_word*)((C_word*)t0)[2])[1];
f_4437(t41,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t40=C_eqp(t1,lf[315]);
if(C_truep(t40)){
t41=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5131,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:713: check */
f_4365(t41,t1,((C_word*)((C_word*)t0)[4])[1],C_SCHEME_END_OF_LIST);}
else{
t41=C_eqp(t1,lf[317]);
t42=(C_truep(t41)?t41:C_eqp(t1,lf[318]));
if(C_truep(t42)){
t43=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5158,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:718: check */
f_4365(t43,t1,((C_word*)((C_word*)t0)[4])[1],C_SCHEME_END_OF_LIST);}
else{
t43=C_eqp(t1,lf[319]);
t44=(C_truep(t43)?t43:C_eqp(t1,lf[320]));
if(C_truep(t44)){
t45=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5179,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:722: cons* */
f_2939(t45,lf[321],C_a_i_list(&a,2,lf[322],((C_word*)((C_word*)t0)[4])[1]));}
else{
t45=C_eqp(t1,lf[323]);
if(C_truep(t45)){
t46=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5189,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:723: cons* */
f_2939(t46,lf[324],C_a_i_list(&a,2,lf[325],((C_word*)((C_word*)t0)[4])[1]));}
else{
t46=C_eqp(t1,lf[326]);
if(C_truep(t46)){
t47=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5199,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:724: cons* */
f_2939(t47,lf[327],C_a_i_list(&a,2,lf[328],((C_word*)((C_word*)t0)[4])[1]));}
else{
t47=C_eqp(t1,lf[329]);
if(C_truep(t47)){
t48=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5209,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:725: cons* */
f_2939(t48,lf[330],C_a_i_list(&a,2,lf[331],((C_word*)((C_word*)t0)[4])[1]));}
else{
t48=C_eqp(t1,lf[332]);
if(C_truep(t48)){
t49=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5219,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:726: cons* */
f_2939(t49,lf[333],C_a_i_list(&a,2,lf[334],((C_word*)((C_word*)t0)[4])[1]));}
else{
t49=C_eqp(t1,lf[335]);
if(C_truep(t49)){
t50=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5229,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:728: cons* */
f_2939(t50,lf[336],C_a_i_list(&a,2,lf[337],((C_word*)((C_word*)t0)[4])[1]));}
else{
t50=C_eqp(t1,lf[338]);
if(C_truep(t50)){
t51=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5239,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:729: cons* */
f_2939(t51,lf[339],C_a_i_list(&a,2,lf[340],((C_word*)((C_word*)t0)[4])[1]));}
else{
t51=C_eqp(t1,lf[341]);
if(C_truep(t51)){
t52=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5249,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:730: cons* */
f_2939(t52,lf[342],C_a_i_list(&a,2,lf[343],((C_word*)((C_word*)t0)[4])[1]));}
else{
t52=C_eqp(t1,lf[344]);
if(C_truep(t52)){
t53=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5259,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:731: cons* */
f_2939(t53,lf[345],C_a_i_list(&a,2,lf[346],((C_word*)((C_word*)t0)[4])[1]));}
else{
t53=C_eqp(t1,lf[347]);
if(C_truep(t53)){
t54=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5269,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:732: cons* */
f_2939(t54,lf[348],C_a_i_list(&a,2,lf[349],((C_word*)((C_word*)t0)[4])[1]));}
else{
t54=C_eqp(t1,lf[350]);
if(C_truep(t54)){
t55=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5278,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* csc.scm:734: check */
f_4365(t55,t1,((C_word*)((C_word*)t0)[4])[1],C_SCHEME_END_OF_LIST);}
else{
t55=C_eqp(t1,lf[352]);
if(C_truep(t55)){
t56=lf[125] /* main#verbose */ =C_SCHEME_TRUE;;
t57=lf[104] /* main#dry-run */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t58=((C_word*)((C_word*)t0)[2])[1];
f_4437(t58,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t56=C_eqp(t1,lf[353]);
t57=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5320,a[2]=((C_word*)t0)[8],a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[7],tmp=(C_word)a,a+=11,tmp);
if(C_truep(t56)){
t58=t57;
f_5320(t58,t56);}
else{
t58=C_eqp(t1,lf[412]);
t59=t57;
f_5320(t59,(C_truep(t58)?t58:C_eqp(t1,lf[413])));}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

/* k4705 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4707,c,av);}
/* csc.scm:864: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_4437(t2,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k4717 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4719,c,av);}
/* csc.scm:623: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4729 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4731,c,av);}
/* csc.scm:626: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4736 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4738,c,av);}
/* csc.scm:625: chicken.base#print */
t2=*((C_word*)lf[154]+1);{
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

/* k4745 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4747(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4747,c,av);}
/* csc.scm:629: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4752 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4754,c,av);}
a=C_alloc(4);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[190]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4760,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:628: ##sys#print */
t4=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[60],C_text("main#translator"));
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4758 in k4752 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4760(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4760,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4763,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:628: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[46]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k4761 in k4758 in k4752 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4763(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4763,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4766,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:628: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[260];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4764 in k4761 in k4758 in k4752 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_4766(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4766,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4769,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:628: chicken.base#get-output-string */
t3=C_fast_retrieve(lf[191]);{
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

/* k4767 in k4764 in k4761 in k4758 in k4752 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_4769(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4769,c,av);}
/* csc.scm:628: chicken.process#system */
t2=C_fast_retrieve(lf[153]);{
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

/* k4824 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4826,c,av);}
/* csc.scm:644: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
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

/* k4836 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4838,c,av);}
/* csc.scm:645: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
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

/* k4848 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4850,c,av);}
/* csc.scm:646: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
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

/* k4860 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4862,c,av);}
/* csc.scm:647: chicken.base#exit */
t2=C_fast_retrieve(lf[45]);{
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

/* k4883 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_fcall f_4885(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_4885,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4888,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:655: t-options */
f_4358(t2,C_a_i_list(&a,1,lf[275]));}

/* k4886 in k4883 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4888,c,av);}
if(C_truep(C_retrieve2(lf[125],C_text("main#verbose")))){
t2=lf[125] /* main#verbose */ =C_fix(2);;
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t2=lf[125] /* main#verbose */ =C_SCHEME_TRUE;;
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}}

/* k4898 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4900,c,av);}
a=C_alloc(3);
t2=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t1);
t3=C_a_i_cons(&a,2,lf[276],C_retrieve2(lf[120],C_text("main#link-options")));
t4=C_mutate(&lf[120] /* (set! main#link-options ...) */,t3);
t5=((C_word*)t0)[2];
f_4885(t5,t4);}

/* k4988 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_4990(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4990,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4993,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:676: t-options */
f_4358(t2,C_a_i_list(&a,2,lf[297],t3));}

/* k4991 in k4988 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_4993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4993,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4997,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5005,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:678: chicken.string#string-split */
t4=C_fast_retrieve(lf[235]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
av2[3]=lf[296];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k4995 in k4991 in k4988 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_4997(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4997,c,av);}
t2=C_mutate(&lf[96] /* (set! main#linked-extensions ...) */,t1);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
/* csc.scm:864: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_4437(t5,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5003 in k4991 in k4988 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5005,c,av);}
/* csc.scm:678: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[96],C_text("main#linked-extensions"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5020 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5022(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5022,c,av);}
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(&lf[109] /* (set! main#library-dir ...) */,t2);
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t4);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5040 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5042(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5042,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5045,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:686: t-options */
f_4358(t2,C_a_i_list(&a,2,lf[301],t3));}

/* k5043 in k5040 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5045,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5109 in k5113 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5111(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5111,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5113 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_5115,c,av);}
a=C_alloc(20);
t2=C_a_i_cons(&a,2,t1,C_retrieve2(lf[93],C_text("main#object-files")));
t3=C_mutate(&lf[93] /* (set! main#object-files ...) */,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5111,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:708: cons* */
f_2939(t4,lf[309],C_a_i_list(&a,4,lf[310],lf[311],lf[312],C_retrieve2(lf[120],C_text("main#link-options"))));}

/* k5129 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_5131,c,av);}
a=C_alloc(11);
if(C_truep(C_retrieve2(lf[33],C_text("main#osx")))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5142,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:715: cons* */
f_2939(t2,lf[316],C_a_i_list(&a,2,t3,C_retrieve2(lf[120],C_text("main#link-options"))));}
else{
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}}

/* k5140 in k5129 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5142(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5142,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
/* csc.scm:864: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_4437(t5,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5156 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5158(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5158,c,av);}
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t5=C_mutate(&lf[124] /* (set! main#target-filename ...) */,t2);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5177 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5179,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5187 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5189,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5197 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5199,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5207 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5209(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5209,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5217 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5219(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5219,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5227 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5229,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5237 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5239,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5247 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5249,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5257 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5259(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5259,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5267 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5269,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5276 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_5278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5278,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5281,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:735: t-options */
f_4358(t2,C_a_i_list(&a,2,((C_word*)t0)[6],t3));}

/* k5279 in k5276 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5281,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5293,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#string->list */
t3=C_fast_retrieve(lf[351]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5291 in k5279 in k5276 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5293(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5293,c,av);}
if(C_truep(C_u_i_memq(C_make_character(104),t1))){
t2=lf[108] /* main#show-debugging-help */ =C_SCHEME_TRUE;;
t3=lf[127] /* main#translate-only */ =C_SCHEME_TRUE;;
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t4);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}
else{
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}}

/* k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_fcall f_5320(C_word t0,C_word t1){
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
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
C_word t19;
C_word t20;
C_word t21;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_5320,2,t0,t1);}
a=C_alloc(10);
if(C_truep(t1)){
/* csc.scm:744: shared-build */
f_4391(((C_word*)t0)[3],C_SCHEME_FALSE);}
else{
t2=C_eqp(((C_word*)t0)[4],lf[354]);
t3=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[4],lf[355]));
if(C_truep(t3)){
/* csc.scm:746: shared-build */
f_4391(((C_word*)t0)[3],C_SCHEME_TRUE);}
else{
t4=C_eqp(((C_word*)t0)[4],lf[356]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5344,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:748: check */
f_4365(t5,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t5=C_eqp(((C_word*)t0)[4],lf[357]);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5361,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:752: check */
f_4365(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t6=C_eqp(((C_word*)t0)[4],lf[358]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5378,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:756: check */
f_4365(t7,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t7=C_eqp(((C_word*)t0)[4],lf[359]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5395,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:760: check */
f_4365(t8,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t8=C_eqp(((C_word*)t0)[4],lf[360]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5412,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:764: check */
f_4365(t9,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t9=C_eqp(((C_word*)t0)[4],lf[362]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5433,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:767: check */
f_4365(t10,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t10=C_eqp(((C_word*)t0)[4],lf[363]);
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5459,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t12=C_a_i_list1(&a,1,lf[364]);
/* csc.scm:771: scheme#append */
t13=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t13;
av2[1]=t11;
av2[2]=C_retrieve2(lf[120],C_text("main#link-options"));
av2[3]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(4,av2);}}
else{
t11=C_eqp(((C_word*)t0)[4],lf[365]);
if(C_truep(t11)){
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5472,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:773: check */
f_4365(t12,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t12=C_eqp(((C_word*)t0)[4],lf[366]);
if(C_truep(t12)){
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5497,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:777: check */
f_4365(t13,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t13=C_eqp(((C_word*)t0)[4],lf[371]);
if(C_truep(t13)){
/* csc.scm:864: loop */
t14=((C_word*)((C_word*)t0)[6])[1];
f_4437(t14,((C_word*)t0)[7],((C_word*)((C_word*)t0)[5])[1]);}
else{
t14=C_eqp(((C_word*)t0)[4],lf[372]);
if(C_truep(t14)){
t15=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5552,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:786: check */
f_4365(t15,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t15=C_eqp(((C_word*)t0)[4],lf[374]);
if(C_truep(t15)){
t16=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5572,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:790: check */
f_4365(t16,((C_word*)t0)[4],((C_word*)((C_word*)t0)[5])[1],C_SCHEME_END_OF_LIST);}
else{
t16=C_eqp(((C_word*)t0)[4],lf[376]);
if(C_truep(t16)){
t17=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5593,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:794: scheme#append */
t18=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t18;
av2[1]=t17;
av2[2]=C_retrieve2(lf[88],C_text("main#scheme-files"));
av2[3]=lf[378];
((C_proc)(void*)(*((C_word*)t18+1)))(4,av2);}}
else{
t17=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5603,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t18=C_eqp(((C_word*)t0)[4],lf[411]);
if(C_truep(t18)){
t19=lf[129] /* main#to-stdout */ =C_SCHEME_TRUE;;
t20=lf[127] /* main#translate-only */ =C_SCHEME_TRUE;;
t21=t17;
f_5603(t21,t20);}
else{
t19=t17;
f_5603(t19,C_SCHEME_UNDEFINED);}}}}}}}}}}}}}}}}}

/* k5342 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5344(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5344,c,av);}
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(&lf[60] /* (set! main#translator ...) */,t2);
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t4);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5359 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5361(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5361,c,av);}
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(&lf[61] /* (set! main#compiler ...) */,t2);
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t4);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5376 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5378(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5378,c,av);}
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(&lf[62] /* (set! main#c++-compiler ...) */,t2);
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t4);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5393 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5395(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5395,c,av);}
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(&lf[64] /* (set! main#linker ...) */,t2);
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t4);
/* csc.scm:864: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_4437(t6,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5410 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_5412,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5416,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t4=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:765: cons* */
f_2939(t2,lf[361],C_a_i_list(&a,2,t3,t4));}

/* k5414 in k5410 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5416(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5416,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5431 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5433(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5433,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5437,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5445,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:768: chicken.string#string-split */
t4=C_fast_retrieve(lf[235]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k5435 in k5431 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5437,c,av);}
t2=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t1);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
/* csc.scm:864: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_4437(t5,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5443 in k5431 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5445(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5445,c,av);}
/* csc.scm:768: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[115],C_text("main#compile-options"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5457 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5459(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5459,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5470 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5472(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5472,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5476,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5484,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:774: chicken.string#string-split */
t4=C_fast_retrieve(lf[235]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k5474 in k5470 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5476(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5476,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
/* csc.scm:864: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_4437(t5,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5482 in k5470 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5484(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5484,c,av);}
/* csc.scm:774: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[120],C_text("main#link-options"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5495 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5497(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5497,c,av);}
a=C_alloc(8);
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(&lf[106] /* (set! main#rpath ...) */,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5511,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5527,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:779: chicken.platform#build-platform */
t6=C_fast_retrieve(lf[370]);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k5509 in k5495 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_fcall f_5511(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_5511,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5515,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5523,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:782: scheme#string-append */
t4=*((C_word*)lf[80]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[367];
av2[3]=C_retrieve2(lf[123],C_text("main#rpath-option"));
av2[4]=C_retrieve2(lf[106],C_text("main#rpath"));
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}}

/* k5513 in k5509 in k5495 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_5515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5515,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
/* csc.scm:864: loop */
t5=((C_word*)((C_word*)t0)[3])[1];
f_4437(t5,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5521 in k5509 in k5495 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_5523(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5523,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* csc.scm:782: scheme#append */
t3=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[120],C_text("main#link-options"));
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5525 in k5495 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5527,c,av);}
if(C_truep((C_truep(C_eqp(t1,lf[368]))?C_SCHEME_TRUE:(C_truep(C_eqp(t1,lf[369]))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
t2=C_i_not(C_retrieve2(lf[31],C_text("main#mingw")));
t3=((C_word*)t0)[2];
f_5511(t3,(C_truep(t2)?C_i_not(C_retrieve2(lf[33],C_text("main#osx"))):C_SCHEME_FALSE));}
else{
t2=((C_word*)t0)[2];
f_5511(t2,C_SCHEME_FALSE);}}

/* k5550 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5552,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5555,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:787: t-options */
f_4358(t2,C_a_i_list(&a,2,lf[373],t3));}

/* k5553 in k5550 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5555(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5555,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5570 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5572,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5575,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:791: t-options */
f_4358(t2,C_a_i_list(&a,2,lf[375],t3));}

/* k5573 in k5570 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5575,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5591 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_5593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5593,c,av);}
a=C_alloc(5);
t2=C_mutate(&lf[88] /* (set! main#scheme-files ...) */,t1);
if(C_truep(C_retrieve2(lf[124],C_text("main#target-filename")))){
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5600,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:796: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
av2[3]=lf[377];
av2[4]=C_retrieve2(lf[71],C_text("main#executable-extension"));
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k5598 in k5591 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_5600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5600,c,av);}
t2=C_mutate(&lf[124] /* (set! main#target-filename ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_fcall f_5603(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_5603,2,t0,t1);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5606,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
if(C_truep((C_truep(C_eqp(((C_word*)t0)[2],lf[409]))?C_SCHEME_TRUE:(C_truep(C_eqp(((C_word*)t0)[2],lf[410]))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
t3=C_mutate(&lf[118] /* (set! main#compilation-optimization-options ...) */,C_retrieve2(lf[83],C_text("main#best-compilation-optimization-options")));
t4=C_mutate(&lf[119] /* (set! main#linking-optimization-options ...) */,C_retrieve2(lf[85],C_text("main#best-linking-optimization-options")));
t5=t2;
f_5606(t5,t4);}
else{
t3=t2;
f_5606(t3,C_SCHEME_UNDEFINED);}}

/* k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_fcall f_5606(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_5606,2,t0,t1);}
a=C_alloc(12);
t2=C_i_assq(((C_word*)t0)[2],lf[379]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5613,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t4=(
/* csc.scm:804: g1245 */
  f_5613(C_a_i(&a,3),t3,t2)
);
/* csc.scm:864: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_4437(t5,((C_word*)t0)[5],((C_word*)((C_word*)t0)[3])[1]);}
else{
if(C_truep(C_i_memq(((C_word*)t0)[2],lf[380]))){
/* csc.scm:805: t-options */
f_4358(((C_word*)t0)[7],C_a_i_list(&a,1,((C_word*)t0)[8]));}
else{
if(C_truep(C_i_memq(((C_word*)t0)[2],lf[381]))){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5643,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* csc.scm:807: check */
f_4365(t3,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1],C_SCHEME_END_OF_LIST);}
else{
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5660,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
t4=C_block_size(((C_word*)t0)[8]);
if(C_truep(C_fixnum_greaterp(t4,C_fix(2)))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6048,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:810: scheme#substring */
t6=*((C_word*)lf[386]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[8];
av2[3]=C_fix(0);
av2[4]=C_fix(2);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t5=t3;
f_5660(t5,C_SCHEME_FALSE);}}}}}

/* g1245 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static C_word C_fcall f_5613(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;{}
t2=C_i_cadr(t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
return(t4);}

/* k5641 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_5643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5643,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5646,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
/* csc.scm:808: t-options */
f_4358(t2,C_a_i_list(&a,2,((C_word*)t0)[6],t3));}

/* k5644 in k5641 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5646,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_4437(t4,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_fcall f_5660(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_5660,2,t0,t1);}
a=C_alloc(11);
if(C_truep(t1)){
/* csc.scm:811: t-options */
f_4358(((C_word*)t0)[3],C_a_i_list(&a,1,((C_word*)t0)[4]));}
else{
t2=C_block_size(((C_word*)t0)[4]);
t3=C_fixnum_greaterp(t2,C_fix(1));
t4=(C_truep(t3)?C_u_i_char_equalp(C_make_character(45),C_i_string_ref(((C_word*)t0)[4],C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_i_string_ref(((C_word*)t0)[4],C_fix(1));
if(C_truep(C_u_i_char_equalp(C_make_character(76),t5))){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5679,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_u_i_char_whitespacep(C_i_string_ref(((C_word*)t0)[4],C_fix(2))))){
/* csc.scm:816: chicken.base#error */
t7=*((C_word*)lf[382]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[383];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t7=t6;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_SCHEME_UNDEFINED;
f_5679(2,av2);}}}
else{
t6=C_i_string_ref(((C_word*)t0)[4],C_fix(1));
if(C_truep(C_u_i_char_equalp(C_make_character(73),t6))){
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5706,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_u_i_char_whitespacep(C_i_string_ref(((C_word*)t0)[4],C_fix(2))))){
/* csc.scm:820: chicken.base#error */
t8=*((C_word*)lf[382]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[384];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
t8=t7;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
f_5706(2,av2);}}}
else{
t7=C_i_string_ref(((C_word*)t0)[4],C_fix(1));
if(C_truep(C_u_i_char_equalp(C_make_character(68),t7))){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5737,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:823: scheme#substring */
t9=*((C_word*)lf[386]+1);{
C_word av2[4];
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(2);
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
t8=C_i_string_ref(((C_word*)t0)[4],C_fix(1));
if(C_truep(C_u_i_char_equalp(C_make_character(70),t8))){
if(C_truep(C_retrieve2(lf[33],C_text("main#osx")))){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5751,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
t10=C_a_i_list1(&a,1,((C_word*)t0)[4]);
/* csc.scm:826: scheme#append */
t11=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t11;
av2[1]=t9;
av2[2]=C_retrieve2(lf[115],C_text("main#compile-options"));
av2[3]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(4,av2);}}
else{
/* csc.scm:864: loop */
t9=((C_word*)((C_word*)t0)[5])[1];
f_4437(t9,((C_word*)t0)[6],((C_word*)((C_word*)t0)[7])[1]);}}
else{
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5761,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
t10=C_block_size(((C_word*)t0)[4]);
if(C_truep(C_fixnum_greaterp(t10,C_fix(3)))){
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5880,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:827: scheme#substring */
t12=*((C_word*)lf[386]+1);{
C_word av2[5];
av2[0]=t12;
av2[1]=t11;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=C_fix(4);
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}
else{
t11=t9;
f_5761(t11,C_SCHEME_FALSE);}}}}}}
else{
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5892,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* csc.scm:840: chicken.file#file-exists? */
t6=C_fast_retrieve(lf[137]);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}}

/* k5677 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_5679,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5683,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_list1(&a,1,((C_word*)t0)[5]);
/* csc.scm:817: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_retrieve2(lf[120],C_text("main#link-options"));
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5681 in k5677 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_5683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5683,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5704 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_5706,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5710,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_list1(&a,1,((C_word*)t0)[5]);
/* csc.scm:821: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_retrieve2(lf[115],C_text("main#compile-options"));
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5708 in k5704 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_5710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5710,c,av);}
t2=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5735 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5737,c,av);}
a=C_alloc(6);
/* csc.scm:823: t-options */
f_4358(((C_word*)t0)[3],C_a_i_list(&a,2,lf[385],t1));}

/* k5749 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5751(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5751,c,av);}
t2=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_fcall f_5761(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_5761,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5765,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_list1(&a,1,((C_word*)t0)[5]);
/* csc.scm:828: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t2;
av2[2]=C_retrieve2(lf[120],C_text("main#link-options"));
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=C_block_size(((C_word*)t0)[5]);
if(C_truep(C_fixnum_greaterp(t2,C_fix(2)))){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5863,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* ##sys#string->list */
t4=C_fast_retrieve(lf[351]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* csc.scm:839: stop */
f_3821(((C_word*)t0)[6],lf[391],C_a_i_list(&a,1,((C_word*)t0)[7]));}}}

/* k5763 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_5765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5765,c,av);}
t2=C_mutate(&lf[120] /* (set! main#link-options ...) */,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_4437(t3,((C_word*)t0)[3],((C_word*)((C_word*)t0)[4])[1]);}

/* k5786 in k5857 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_5788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5788,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* csc.scm:864: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_4437(t3,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1]);}

/* k5803 in k5857 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_5805(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5805,c,av);}
/* csc.scm:833: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop1266 in k5857 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_fcall f_5807(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_5807,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5832,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_a_i_string(&a,1,t4);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word av2[4];
av2[0]=*((C_word*)lf[178]+1);
av2[1]=t3;
av2[2]=lf[387];
av2[3]=t5;
tp(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5830 in map-loop1266 in k5857 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_5832(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5832,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_5807(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k5857 in k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_5859(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_5859,c,av);}
a=C_alloc(21);
if(C_truep(C_i_nullp(t1))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5788,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5805,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5807,a[2]=t5,a[3]=t9,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_5807(t11,t7,((C_word*)t0)[5]);}
else{
t2=C_i_car(((C_word*)t0)[5]);
if(C_truep(C_i_char_equalp(C_make_character(108),t2))){
/* csc.scm:837: stop */
f_3821(((C_word*)t0)[6],lf[388],C_a_i_list(&a,1,((C_word*)t0)[7]));}
else{
/* csc.scm:838: stop */
f_3821(((C_word*)t0)[6],lf[389],C_a_i_list(&a,1,((C_word*)t0)[7]));}}}

/* k5861 in k5759 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_5863(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5863,c,av);}
a=C_alloc(16);
t2=C_i_cdr(t1);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5859,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t4=C_retrieve2(lf[87],C_text("main#short-options"));
t5=C_a_i_list(&a,1,C_retrieve2(lf[87],C_text("main#short-options")));
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3381,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_3381(t9,t3,t5,t2);}

/* k5878 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5880,c,av);}
t2=((C_word*)t0)[2];
f_5761(t2,C_u_i_string_equal_p(lf[392],t1));}

/* k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_5892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_5892,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5897,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5903,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:841: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6012,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[178]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[407];
tp(4,av2);}}}

/* a5896 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_5897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5897,c,av);}
/* csc.scm:841: chicken.pathname#decompose-pathname */
t2=C_fast_retrieve(lf[393]);{
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

/* a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_5903(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5903,c,av);}
a=C_alloc(7);
if(C_truep(C_i_not(t4))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5914,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_list1(&a,1,((C_word*)t0)[2]);
/* csc.scm:843: scheme#append */
t7=*((C_word*)lf[143]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
av2[2]=C_retrieve2(lf[88],C_text("main#scheme-files"));
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
if(C_truep((C_truep(C_i_equalp(t4,lf[394]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[395]))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5928,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_list1(&a,1,((C_word*)t0)[2]);
/* csc.scm:845: scheme#append */
t7=*((C_word*)lf[143]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
av2[2]=C_retrieve2(lf[89],C_text("main#c-files"));
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
if(C_truep(C_i_string_ci_equal_p(t4,lf[396]))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5942,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_list1(&a,1,((C_word*)t0)[2]);
/* csc.scm:847: scheme#append */
t7=*((C_word*)lf[143]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
av2[2]=C_retrieve2(lf[90],C_text("main#rc-files"));
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
if(C_truep((C_truep(C_i_equalp(t4,lf[397]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[398]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[399]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[400]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[401]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5955,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[33],C_text("main#osx")))){
t6=C_a_i_cons(&a,2,lf[402],C_retrieve2(lf[115],C_text("main#compile-options")));
t7=C_mutate(&lf[115] /* (set! main#compile-options ...) */,t6);
t8=t5;
f_5955(t8,t7);}
else{
t6=t5;
f_5955(t6,C_SCHEME_UNDEFINED);}}
else{
if(C_truep((C_truep(C_i_equalp(t4,lf[403]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[404]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[405]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))){
t5=lf[98] /* main#objc-mode */ =C_SCHEME_TRUE;;
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5979,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t7=C_a_i_list1(&a,1,((C_word*)t0)[2]);
/* csc.scm:854: scheme#append */
t8=*((C_word*)lf[143]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t6;
av2[2]=C_retrieve2(lf[89],C_text("main#c-files"));
av2[3]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
t5=C_retrieve2(lf[68],C_text("main#object-extension"));
t6=C_u_i_string_equal_p(t4,C_retrieve2(lf[68],C_text("main#object-extension")));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5991,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t6)){
t8=t7;
f_5991(t8,t6);}
else{
t8=C_retrieve2(lf[69],C_text("main#library-extension"));
t9=t7;
f_5991(t9,C_u_i_string_equal_p(t4,C_retrieve2(lf[69],C_text("main#library-extension"))));}}}}}}}

/* k5912 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_5914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5914,c,av);}
t2=C_mutate(&lf[88] /* (set! main#scheme-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5926 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_5928(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5928,c,av);}
t2=C_mutate(&lf[89] /* (set! main#c-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5940 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_5942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5942,c,av);}
t2=C_mutate(&lf[90] /* (set! main#rc-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5953 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_fcall f_5955(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_5955,2,t0,t1);}
a=C_alloc(6);
t2=lf[97] /* main#cpp-mode */ =C_SCHEME_TRUE;;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5960,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_list1(&a,1,((C_word*)t0)[3]);
/* csc.scm:851: scheme#append */
t5=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t3;
av2[2]=C_retrieve2(lf[89],C_text("main#c-files"));
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k5958 in k5953 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_5960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5960,c,av);}
t2=C_mutate(&lf[89] /* (set! main#c-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5977 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_5979(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5979,c,av);}
t2=C_mutate(&lf[89] /* (set! main#c-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5989 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_fcall f_5991(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_5991,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5995,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_list1(&a,1,((C_word*)t0)[3]);
/* csc.scm:857: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t2;
av2[2]=C_retrieve2(lf[93],C_text("main#object-files"));
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6003,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_list1(&a,1,((C_word*)t0)[3]);
/* csc.scm:858: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t2;
av2[2]=C_retrieve2(lf[88],C_text("main#scheme-files"));
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k5993 in k5989 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_5995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5995,c,av);}
t2=C_mutate(&lf[93] /* (set! main#object-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6001 in k5989 in a5902 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6003,c,av);}
t2=C_mutate(&lf[88] /* (set! main#scheme-files ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6010 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_6012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6012,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6018,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* csc.scm:861: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[137]);{
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

/* k6016 in k6010 in k5890 in k5658 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_6018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6018,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
/* csc.scm:864: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_4437(t4,((C_word*)t0)[5],((C_word*)((C_word*)t0)[3])[1]);}
else{
/* csc.scm:863: stop */
f_3821(((C_word*)t0)[6],lf[406],C_a_i_list(&a,1,((C_word*)t0)[7]));}}

/* k6046 in k5604 in k5601 in k5318 in k4702 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_6048(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6048,c,av);}
t2=((C_word*)t0)[2];
f_5660(t2,C_u_i_string_equal_p(lf[408],t1));}

/* k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_6255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_6255,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6258,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_member(t1,C_retrieve2(lf[89],C_text("main#c-files"))))){
/* csc.scm:881: stop */
f_3821(t2,lf[226],C_a_i_list(&a,2,((C_word*)t0)[5],t1));}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6258(2,av2);}}}

/* k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6258(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_6258,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6261,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6295,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6299,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6303,a[2]=t4,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:885: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[6];
f_3870(3,av2);}}

/* k6259 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6261(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6261,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6264,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(C_truep(C_retrieve2(lf[131],C_text("main#static")))?C_retrieve2(lf[128],C_text("main#compile-only")):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6291,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:910: chicken.pathname#pathname-replace-extension */
t5=C_fast_retrieve(lf[172]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[216];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t4=t2;
f_6264(t4,C_SCHEME_UNDEFINED);}}

/* k6262 in k6259 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_fcall f_6264(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_6264,2,t0,t1);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6268,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_a_i_list1(&a,1,((C_word*)t0)[5]);
/* csc.scm:912: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
av2[3]=C_retrieve2(lf[89],C_text("main#c-files"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k6266 in k6262 in k6259 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6268(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6268,c,av);}
a=C_alloc(8);
t2=C_mutate(&lf[89] /* (set! main#c-files ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6272,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=C_a_i_list1(&a,1,((C_word*)t0)[5]);
/* csc.scm:913: scheme#append */
t5=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
av2[3]=C_retrieve2(lf[91],C_text("main#generated-c-files"));
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k6270 in k6266 in k6262 in k6259 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6272,c,av);}
t2=C_mutate(&lf[91] /* (set! main#generated-c-files ...) */,t1);
t3=((C_word*)((C_word*)t0)[2])[1];
f_6426(t3,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6289 in k6259 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_6291,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_retrieve2(lf[95],C_text("main#transient-link-files")));
t3=C_mutate(&lf[95] /* (set! main#transient-link-files ...) */,t2);
t4=((C_word*)t0)[2];
f_6264(t4,t3);}

/* k6293 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6295,c,av);}
/* csc.scm:883: command */
f_7398(((C_word*)t0)[2],t1);}

/* k6297 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6299(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6299,c,av);}
/* csc.scm:884: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[142]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[217];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6303(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6303,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6307,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6311,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[129],C_text("main#to-stdout")))){
t4=t3;
f_6311(t4,lf[224]);}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6397,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:889: quotewrap */
t5=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
f_3870(3,av2);}}}

/* k6305 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6307,c,av);}
a=C_alloc(6);
/* csc.scm:885: cons* */
f_2939(((C_word*)t0)[2],C_retrieve2(lf[60],C_text("main#translator")),C_a_i_list(&a,2,((C_word*)t0)[3],t1));}

/* k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_fcall f_6311(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_6311,2,t0,t1);}
a=C_alloc(18);
t2=(C_truep(C_i_debug_modep())?lf[218]:C_SCHEME_END_OF_LIST);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_retrieve2(lf[140],C_text("main#quote-option"));
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6322,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t5,a[6]=t6,tmp=(C_word)a,a+=7,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6366,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
t10=(C_truep(C_retrieve2(lf[131],C_text("main#static")))?C_i_not(C_i_member(lf[221],C_retrieve2(lf[112],C_text("main#translate-options")))):C_SCHEME_FALSE);
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6383,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:901: chicken.pathname#pathname-replace-extension */
t12=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t12;
av2[1]=t11;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[223];
((C_proc)(void*)(*((C_word*)t12+1)))(4,av2);}}
else{
t11=t9;
f_6366(t11,C_SCHEME_END_OF_LIST);}}

/* k6320 in k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6322(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_6322,c,av);}
a=C_alloc(12);
t2=C_i_check_list_2(t1,lf[141]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6328,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6330,a[2]=((C_word*)t0)[5],a[3]=t5,a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_6330(t7,t3,t1);}

/* k6326 in k6320 in k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6328,c,av);}
/* csc.scm:886: scheme#append */
t2=*((C_word*)lf[143]+1);{
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

/* map-loop1347 in k6320 in k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_fcall f_6330(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6330,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6355,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:893: g1353 */
{C_proc tp=(C_proc)C_retrieve2_symbol_proc(lf[140],C_text("main#quote-option"));
C_word av2[3];
av2[0]=lf[140];
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
tp(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6353 in map-loop1347 in k6320 in k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_6355(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6355,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6330(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6364 in k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_fcall f_6366(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_6366,2,t0,t1);}
if(C_truep(C_retrieve2(lf[97],C_text("main#cpp-mode")))){
/* csc.scm:894: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word av2[7];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[86],C_text("main#extra-features"));
av2[3]=C_retrieve2(lf[112],C_text("main#translate-options"));
av2[4]=t1;
av2[5]=lf[219];
av2[6]=C_retrieve2(lf[117],C_text("main#translation-optimization-options"));
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}
else{
if(C_truep(C_retrieve2(lf[98],C_text("main#objc-mode")))){
/* csc.scm:894: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word av2[7];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[86],C_text("main#extra-features"));
av2[3]=C_retrieve2(lf[112],C_text("main#translate-options"));
av2[4]=t1;
av2[5]=lf[220];
av2[6]=C_retrieve2(lf[117],C_text("main#translation-optimization-options"));
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}
else{
/* csc.scm:894: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word av2[7];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[86],C_text("main#extra-features"));
av2[3]=C_retrieve2(lf[112],C_text("main#translate-options"));
av2[4]=t1;
av2[5]=C_SCHEME_END_OF_LIST;
av2[6]=C_retrieve2(lf[117],C_text("main#translation-optimization-options"));
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}}}

/* k6381 in k6309 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_6383,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];
f_6366(t2,C_a_i_list2(&a,2,lf[222],t1));}

/* k6395 in k6301 in k6256 in k6253 in for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6397(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_6397,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];
f_6311(t2,C_a_i_list(&a,2,lf[225],t1));}

/* for-each-loop1326 in k4618 in k4615 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_fcall f_6426(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_6426,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_length(C_retrieve2(lf[88],C_text("main#scheme-files")));
t5=C_eqp(C_fix(1),t4);
t6=(C_truep(t5)?C_retrieve2(lf[124],C_text("main#target-filename")):t3);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6255,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_retrieve2(lf[97],C_text("main#cpp-mode")))){
/* csc.scm:875: chicken.pathname#pathname-replace-extension */
t8=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t6;
av2[3]=lf[227];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
if(C_truep(C_retrieve2(lf[98],C_text("main#objc-mode")))){
/* csc.scm:875: chicken.pathname#pathname-replace-extension */
t8=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t6;
av2[3]=lf[228];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
/* csc.scm:875: chicken.pathname#pathname-replace-extension */
t8=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t6;
av2[3]=lf[229];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_fcall f_6451(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_6451,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6455,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_retrieve2(lf[128],C_text("main#compile-only")))){
if(C_truep(C_retrieve2(lf[124],C_text("main#target-filename")))){
t4=C_i_length(C_retrieve2(lf[89],C_text("main#c-files")));
t5=C_eqp(C_fix(1),t4);
if(C_truep(t5)){
t6=t3;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_retrieve2(lf[124],C_text("main#target-filename"));
f_6455(2,av2);}}
else{
/* csc.scm:927: chicken.pathname#pathname-replace-extension */
t6=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}
else{
/* csc.scm:927: chicken.pathname#pathname-replace-extension */
t4=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}
else{
/* csc.scm:927: chicken.pathname#pathname-replace-extension */
t4=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_6455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_6455,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6458,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_member(t1,C_retrieve2(lf[93],C_text("main#object-files"))))){
/* csc.scm:929: stop */
f_3821(t2,lf[204],C_a_i_list(&a,2,((C_word*)t0)[4],t1));}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6458(2,av2);}}}

/* k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_6458(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6458,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6461,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6473,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(C_truep(C_retrieve2(lf[97],C_text("main#cpp-mode")))?C_retrieve2(lf[62],C_text("main#c++-compiler")):C_retrieve2(lf[61],C_text("main#compiler")));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6485,a[2]=t4,a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:935: quotewrap */
t6=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[5];
f_3870(3,av2);}}

/* k6459 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6461(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_6461,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],C_retrieve2(lf[94],C_text("main#generated-object-files")));
t3=C_mutate(&lf[94] /* (set! main#generated-object-files ...) */,t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t4);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k6471 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6473(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6473,c,av);}
/* csc.scm:931: command */
f_7398(((C_word*)t0)[2],t1);}

/* k6483 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6485(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6485,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6489,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6508,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:936: quotewrap */
t4=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
f_3870(3,av2);}}

/* k6487 in k6483 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6489,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6493,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_retrieve2(lf[97],C_text("main#cpp-mode")))){
t3=C_i_string_equal_p(lf[200],C_retrieve2(lf[62],C_text("main#c++-compiler")));
t4=t2;
f_6493(t4,(C_truep(t3)?lf[201]:lf[202]));}
else{
t3=t2;
f_6493(t3,lf[202]);}}

/* k6491 in k6487 in k6483 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_fcall f_6493(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_6493,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6497,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* csc.scm:941: compiler-options */
f_6723(t2);}

/* k6495 in k6491 in k6487 in k6483 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_6497,c,av);}
a=C_alloc(18);
t2=C_a_i_list6(&a,6,((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],lf[199],((C_word*)t0)[5],t1);
/* csc.scm:932: chicken.string#string-intersperse */
t3=C_fast_retrieve(lf[142]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[6];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6506 in k6483 in k6456 in k6453 in g1390 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6508(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6508,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[178]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[203];
av2[3]=t1;
tp(4,av2);}}

/* k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_6537(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6537,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6540,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6673,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[78],C_text("main#generate-manifest")))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6698,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:945: chicken.platform#software-type */
t5=C_fast_retrieve(lf[213]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=t3;
f_6673(t4,C_SCHEME_FALSE);}}

/* k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_fcall f_6540(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_6540,2,t0,t1);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6541,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_retrieve2(lf[90],C_text("main#rc-files"));
t4=C_i_check_list_2(C_retrieve2(lf[90],C_text("main#rc-files")),lf[173]);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6578,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6649,a[2]=t7,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_6649(t9,t5,C_retrieve2(lf[90],C_text("main#rc-files")));}

/* g1400 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_fcall f_6541(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_6541,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6545,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:952: scheme#string-append */
t4=*((C_word*)lf[80]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[205];
av2[4]=C_retrieve2(lf[68],C_text("main#object-extension"));
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k6543 in g1400 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6545,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6548,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6560,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6568,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:955: quotewrap */
t5=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
f_3870(3,av2);}}

/* k6546 in k6543 in g1400 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6548(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_6548,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],C_retrieve2(lf[94],C_text("main#generated-object-files")));
t3=C_mutate(&lf[94] /* (set! main#generated-object-files ...) */,t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t4);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k6558 in k6543 in g1400 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6560,c,av);}
/* csc.scm:953: command */
f_7398(((C_word*)t0)[2],t1);}

/* k6566 in k6543 in g1400 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6568,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6572,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:955: quotewrap */
t3=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
f_3870(3,av2);}}

/* k6570 in k6566 in k6543 in g1400 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6572,c,av);}
a=C_alloc(9);
t2=C_a_i_list3(&a,3,C_retrieve2(lf[63],C_text("main#rc-compiler")),((C_word*)t0)[2],t1);
/* csc.scm:954: chicken.string#string-intersperse */
t3=C_fast_retrieve(lf[142]);{
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

/* k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_6578(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6578,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6582,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6647,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:959: scheme#reverse */
t4=*((C_word*)lf[181]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6580 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6582(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6582,c,av);}
a=C_alloc(8);
t2=C_mutate(&lf[93] /* (set! main#object-files ...) */,t1);
if(C_truep(C_retrieve2(lf[126],C_text("main#keep-files")))){
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_4467(2,av2);}}
else{
t3=C_retrieve2(lf[161],C_text("main#$delete-file"));
t4=C_retrieve2(lf[91],C_text("main#generated-c-files"));
t5=C_i_check_list_2(C_retrieve2(lf[91],C_text("main#generated-c-files")),lf[173]);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6591,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6622,a[2]=t8,tmp=(C_word)a,a+=3,tmp));
t10=((C_word*)t8)[1];
f_6622(t10,t6,C_retrieve2(lf[91],C_text("main#generated-c-files")));}}

/* k6589 in k6580 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6591(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6591,c,av);}
a=C_alloc(5);
t2=C_retrieve2(lf[161],C_text("main#$delete-file"));
t3=C_retrieve2(lf[92],C_text("main#generated-rc-files"));
t4=C_i_check_list_2(C_retrieve2(lf[92],C_text("main#generated-rc-files")),lf[173]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6599,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_6599(t8,((C_word*)t0)[2],C_retrieve2(lf[92],C_text("main#generated-rc-files")));}

/* for-each-loop1459 in k6589 in k6580 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_fcall f_6599(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6599,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6609,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:962: g1460 */
t4=C_retrieve2(lf[161],C_text("main#$delete-file"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_7411(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6607 in for-each-loop1459 in k6589 in k6580 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6609,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6599(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1442 in k6580 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_fcall f_6622(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6622,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6632,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:961: g1443 */
t4=C_retrieve2(lf[161],C_text("main#$delete-file"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_7411(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6630 in for-each-loop1442 in k6580 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6632,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6622(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6645 in k6576 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6647(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6647,c,av);}
/* csc.scm:959: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[93],C_text("main#object-files"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* for-each-loop1399 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_fcall f_6649(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6649,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6659,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:950: g1400 */
t4=((C_word*)t0)[3];
f_6541(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6657 in for-each-loop1399 in k6538 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6659,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6649(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_fcall f_6673(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_6673,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6676,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:946: chicken.pathname#pathname-replace-extension */
t3=C_fast_retrieve(lf[172]);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
av2[3]=lf[212];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t2=((C_word*)t0)[2];
f_6540(t2,C_SCHEME_UNDEFINED);}}

/* k6674 in k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in ... */
static void C_ccall f_6676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6676,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6679,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6691,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:947: chicken.pathname#pathname-file */
t4=C_fast_retrieve(lf[211]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6677 in k6674 in k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6679(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_6679,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],C_retrieve2(lf[90],C_text("main#rc-files")));
t3=C_mutate(&lf[90] /* (set! main#rc-files ...) */,t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],C_retrieve2(lf[92],C_text("main#generated-rc-files")));
t5=C_mutate(&lf[92] /* (set! main#generated-rc-files ...) */,t4);
t6=((C_word*)t0)[3];
f_6540(t6,t5);}

/* k6689 in k6674 in k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6691,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7430,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_retrieve2(lf[125],C_text("main#verbose")))){
/* csc.scm:1097: chicken.base#print */
t3=*((C_word*)lf[154]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[210];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_7430(2,av2);}}}

/* k6696 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_6698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6698,c,av);}
t2=((C_word*)t0)[2];
f_6673(t2,C_eqp(lf[16],t1));}

/* for-each-loop1389 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_fcall f_6700(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6700,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6710,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:921: g1390 */
t4=((C_word*)t0)[3];
f_6451(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6708 in for-each-loop1389 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in ... */
static void C_ccall f_6710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6710,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6700(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* main#compiler-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_fcall f_6723(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_6723,1,t1);}
a=C_alloc(10);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_retrieve2(lf[140],C_text("main#quote-option"));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6734,a[2]=t1,a[3]=t4,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:967: scheme#append */
t8=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_retrieve2(lf[118],C_text("main#compilation-optimization-options"));
av2[3]=C_retrieve2(lf[115],C_text("main#compile-options"));
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k6732 in main#compiler-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_6734(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_6734,c,av);}
a=C_alloc(10);
t2=C_i_check_list_2(t1,lf[141]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6740,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6742,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_6742(t7,t3,t1);}

/* k6738 in k6732 in main#compiler-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_6740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6740,c,av);}
/* csc.scm:965: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[142]);{
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

/* map-loop1482 in k6732 in main#compiler-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_fcall f_6742(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6742,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6767,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:966: g1488 */
{C_proc tp=(C_proc)C_retrieve2_symbol_proc(lf[140],C_text("main#quote-option"));
C_word av2[3];
av2[0]=lf[140];
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
tp(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6765 in map-loop1482 in k6732 in main#compiler-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_6767(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6767,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6742(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_ccall f_6781(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_6781,c,av);}
a=C_alloc(15);
t2=C_mutate(&lf[93] /* (set! main#object-files ...) */,t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_retrieve2(lf[54],C_text("main#quotewrap"));
t8=C_retrieve2(lf[93],C_text("main#object-files"));
t9=C_i_check_list_2(C_retrieve2(lf[93],C_text("main#object-files")),lf[141]);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6790,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6920,a[2]=t5,a[3]=t12,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t14=((C_word*)t12)[1];
f_6920(t14,t10,C_retrieve2(lf[93],C_text("main#object-files")));}

/* k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_6790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6790,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6793,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:978: quotewrap */
t3=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
f_3870(3,av2);}}

/* k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6793(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_6793,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6796,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6885,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6889,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(C_truep(C_retrieve2(lf[97],C_text("main#cpp-mode")))?C_retrieve2(lf[65],C_text("main#c++-linker")):C_retrieve2(lf[64],C_text("main#linker")));
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6897,a[2]=t4,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6905,a[2]=t6,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6918,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:986: quotewrap */
t9=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=C_retrieve2(lf[124],C_text("main#target-filename"));
f_3870(3,av2);}}

/* k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6796(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6796,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6799,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(C_truep(C_retrieve2(lf[33],C_text("main#osx")))?C_retrieve2(lf[53],C_text("main#host-mode")):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6844,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6848,a[2]=t4,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_POSTINSTALL_PROGRAM);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_6799(2,av2);}}}

/* k6797 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6799(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6799,c,av);}
a=C_alloc(3);
if(C_truep(C_retrieve2(lf[126],C_text("main#keep-files")))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_retrieve2(lf[161],C_text("main#$delete-file"));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6805,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1005: scheme#append */
t4=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_retrieve2(lf[94],C_text("main#generated-object-files"));
av2[3]=C_retrieve2(lf[95],C_text("main#transient-link-files"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k6803 in k6797 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_6805(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6805,c,av);}
a=C_alloc(5);
t2=C_i_check_list_2(t1,lf[173]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6813,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_6813(t6,((C_word*)t0)[2],t1);}

/* for-each-loop1543 in k6803 in k6797 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_fcall f_6813(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6813,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6823,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:1004: g1544 */
t4=C_retrieve2(lf[161],C_text("main#$delete-file"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_7411(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6821 in for-each-loop1543 in k6803 in k6797 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in ... */
static void C_ccall f_6823(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6823,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6813(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6842 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6844,c,av);}
/* csc.scm:990: command */
f_7398(((C_word*)t0)[2],t1);}

/* k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6848,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6852,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:992: libchicken */
f_3945(t2);}

/* k6850 in k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_6852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6852,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6856,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6860,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6880,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:994: libchicken */
f_3945(t4);}

/* k6854 in k6850 in k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_ccall f_6856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_6856,c,av);}
/* csc.scm:991: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[174];
av2[4]=((C_word*)t0)[4];
av2[5]=lf[175];
av2[6]=t1;
av2[7]=lf[176];
av2[8]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(9,av2);}}

/* k6858 in k6850 in k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_ccall f_6860(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6860,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6863,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[105],C_text("main#deployed")))){
/* csc.scm:996: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[177];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6873,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
t4=C_retrieve2(lf[18],C_text("main#host-libdir"));
t5=C_retrieve2(lf[18],C_text("main#host-libdir"));
/* csc.scm:997: chicken.pathname#make-pathname */
t6=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=C_retrieve2(lf[18],C_text("main#host-libdir"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
/* ##sys#peek-c-string */
t4=*((C_word*)lf[50]+1);{
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
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}}

/* k6861 in k6858 in k6850 in k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in ... */
static void C_ccall f_6863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6863,c,av);}
/* csc.scm:993: quotewrap */
t2=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
f_3870(3,av2);}}

/* k6871 in k6858 in k6850 in k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in ... */
static void C_ccall f_6873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6873,c,av);}
/* csc.scm:997: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[138]);{
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

/* k6878 in k6850 in k6846 in k6794 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_ccall f_6880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6880,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[178]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[179];
tp(4,av2);}}

/* k6883 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6885,c,av);}
/* csc.scm:980: command */
f_7398(((C_word*)t0)[2],t1);}

/* k6887 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6889,c,av);}
/* csc.scm:981: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[142]);{
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

/* k6895 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6897,c,av);}
a=C_alloc(3);
/* csc.scm:982: cons* */
f_2939(((C_word*)t0)[2],((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* k6903 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6905(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6905,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6909,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:987: linker-options */
f_7204(t2);}

/* k6907 in k6903 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6909(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6909,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6913,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:988: linker-libraries */
f_7257(t2);}

/* k6911 in k6907 in k6903 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_6913(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6913,c,av);}
a=C_alloc(9);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
/* csc.scm:984: scheme#append */
t3=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6916 in k6791 in k6788 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6918,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[178]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[178]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[180];
av2[3]=t1;
tp(4,av2);}}

/* map-loop1510 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_fcall f_6920(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6920,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6945,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:977: g1516 */
t4=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_3870(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6943 in map-loop1510 in k6779 in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6945(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6945,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6920(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6959 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_6961(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6961,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6964,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_fast_retrieve(lf[136]))){
/* csc.scm:1012: chicken.string#string-chomp */
t3=C_fast_retrieve(lf[187]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[188];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f8470,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1013: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
av2[3]=t1;
av2[4]=lf[186];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k6962 in k6959 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_6964(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_6964,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6971,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1013: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
av2[3]=t1;
av2[4]=lf[186];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6969 in k6962 in k6959 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_6971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6971,c,av);}
/* csc.scm:1013: chicken.file#file-exists? */
t2=C_fast_retrieve(lf[137]);{
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

/* k6983 in map-loop1572 in k6998 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_ccall f_6985(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6985,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];
f_7018(t2,C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST));}
else{
/* csc.scm:1017: stop */
f_3821(((C_word*)t0)[3],lf[183],C_a_i_list(&a,1,((C_word*)t0)[4]));}}

/* k6998 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_7000(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7000,c,av);}
a=C_alloc(7);
t2=C_i_check_list_2(t1,lf[141]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7008,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_7008(t6,((C_word*)t0)[4],t1);}

/* map-loop1572 in k6998 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_fcall f_7008(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,2)))){
C_save_and_reclaim_args((void *)trf_7008,3,t0,t1,t2);}
a=C_alloc(14);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7018,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7033,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_slot(t2,C_fix(0));
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6985,a[2]=t3,a[3]=t4,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:1016: find-object-file */
t7=C_retrieve2(lf[134],C_text("main#find-object-file"));{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t5;
f_4246(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7016 in map-loop1572 in k6998 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_fcall f_7018(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_7018,2,t0,t1);}
t2=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t1);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t4=((C_word*)((C_word*)t0)[3])[1];
f_7008(t4,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7031 in map-loop1572 in k6998 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in ... */
static void C_ccall f_7033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7033,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_7018(t2,C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST));}

/* map-loop1595 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_fcall f_7042(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7042,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7067,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:1018: g1601 */
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

/* k7065 in map-loop1595 in k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_7067(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7067,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7042(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in ... */
static void C_fcall f_7079(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7079,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7093,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1021: scheme#reverse */
t5=*((C_word*)lf[181]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=C_retrieve2(lf[131],C_text("main#static"));
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7099,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_retrieve2(lf[131],C_text("main#static")))){
t6=t5;
f_7099(t6,C_retrieve2(lf[131],C_text("main#static")));}
else{
t6=C_i_car(t2);
t7=t5;
f_7099(t7,C_i_not(C_i_member(t6,((C_word*)t0)[3])));}}}

/* k7091 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_7093(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7093,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3076,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_3076(t5,((C_word*)t0)[2],t1);}

/* k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_fcall f_7099(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_7099,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7102,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_i_car(((C_word*)t0)[5]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6961,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1010: chicken.pathname#pathname-strip-extension */
t5=C_fast_retrieve(lf[189]);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[5]);
t3=C_u_i_car(((C_word*)t0)[5]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[4]);
/* csc.scm:1028: loop */
t5=((C_word*)((C_word*)t0)[2])[1];
f_7079(t5,((C_word*)t0)[3],t2,t4);}}

/* k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_7102(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_7102,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7105,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7125,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1025: scheme#with-input-from-file */
t4=C_fast_retrieve(lf[184]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
av2[3]=*((C_word*)lf[185]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
f_7105(2,av2);}}}

/* k7103 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_7105(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_7105,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7112,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csc.scm:1027: scheme#append */
t3=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=C_u_i_cdr(((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k7110 in k7103 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in ... */
static void C_ccall f_7112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7112,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7116,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:1027: scheme#append */
t3=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k7114 in k7110 in k7103 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in ... */
static void C_ccall f_7116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7116,c,av);}
/* csc.scm:1027: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7079(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k7123 in k7100 in k7097 in loop in k4474 in k4471 in k4465 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_7125(C_word c,C_word *av){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_7125,c,av);}
a=C_alloc(23);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_fast_retrieve(lf[182]);
t11=C_i_check_list_2(t1,lf[141]);
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7000,a[2]=t4,a[3]=t5,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7042,a[2]=t8,a[3]=t14,a[4]=t10,a[5]=t9,tmp=(C_word)a,a+=6,tmp));
t16=((C_word*)t14)[1];
f_7042(t16,t12,t1);}

/* main#linker-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_fcall f_7204(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_7204,1,t1);}
a=C_alloc(10);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_retrieve2(lf[140],C_text("main#quote-option"));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7215,a[2]=t1,a[3]=t4,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* csc.scm:1042: scheme#append */
t8=*((C_word*)lf[143]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_retrieve2(lf[119],C_text("main#linking-optimization-options"));
av2[3]=C_retrieve2(lf[120],C_text("main#link-options"));
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k7213 in main#linker-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7215(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7215,c,av);}
a=C_alloc(10);
t2=C_i_check_list_2(t1,lf[141]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7221,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7223,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_7223(t7,t3,t1);}

/* k7219 in k7213 in main#linker-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_7221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7221,c,av);}
/* csc.scm:1040: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[142]);{
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

/* map-loop1665 in k7213 in main#linker-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_fcall f_7223(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7223,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7248,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:1041: g1671 */
{C_proc tp=(C_proc)C_retrieve2_symbol_proc(lf[140],C_text("main#quote-option"));
C_word av2[3];
av2[0]=lf[140];
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
tp(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7246 in map-loop1665 in k7213 in main#linker-options in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_7248(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7248,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7223(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* main#linker-libraries in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_fcall f_7257(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_7257,1,t1);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7265,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[131],C_text("main#static")))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4073,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3988,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csc.scm:130: libchicken */
f_3945(t4);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4053,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4057,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_retrieve2(lf[53],C_text("main#host-mode")))){
/* ##sys#peek-c-string */
t5=*((C_word*)lf[50]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)C_INSTALL_LIB_NAME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
/* ##sys#peek-c-string */
t5=*((C_word*)lf[50]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)C_TARGET_LIB_NAME);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}}

/* k7263 in main#linker-libraries in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7265(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7265,c,av);}
/* csc.scm:1045: chicken.string#string-intersperse */
t2=C_fast_retrieve(lf[142]);{
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

/* k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7327,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7330,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[125],C_text("main#verbose")))){
/* csc.scm:1079: chicken.base#print */
t3=*((C_word*)lf[154]+1);{
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
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_7330(2,av2);}}}

/* k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_7330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7330,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7333,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[104],C_text("main#dry-run")))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_fix(0);
f_7333(2,av2);}}
else{
/* csc.scm:1080: chicken.process#system */
t3=C_fast_retrieve(lf[153]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k7331 in k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_7333(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_7333,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7336,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_eqp(t1,C_fix(0));
if(C_truep(t3)){
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_7336(2,av2);}}
else{
t4=*((C_word*)lf[149]+1);
t5=*((C_word*)lf[149]+1);
t6=C_i_check_port_2(*((C_word*)lf[149]+1),C_fix(2),C_SCHEME_TRUE,lf[150]);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7353,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:1082: ##sys#print */
t8=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[152];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[149]+1);
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}}

/* k7334 in k7331 in k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_7336(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7336,c,av);}
t2=C_eqp(((C_word*)t0)[2],C_fix(0));
if(C_truep(t2)){
t3=lf[147] /* main#last-exit-code */ =C_fix(0);;
t4=C_retrieve2(lf[147],C_text("main#last-exit-code"));
if(C_truep(C_i_zerop(C_retrieve2(lf[147],C_text("main#last-exit-code"))))){
t5=C_SCHEME_UNDEFINED;
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* csc.scm:1089: chicken.base#exit */
t5=C_fast_retrieve(lf[45]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=C_retrieve2(lf[147],C_text("main#last-exit-code"));
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}
else{
t3=lf[147] /* main#last-exit-code */ =C_fix(1);;
t4=C_retrieve2(lf[147],C_text("main#last-exit-code"));
if(C_truep(C_i_zerop(C_retrieve2(lf[147],C_text("main#last-exit-code"))))){
t5=C_SCHEME_UNDEFINED;
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* csc.scm:1089: chicken.base#exit */
t5=C_fast_retrieve(lf[45]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=C_retrieve2(lf[147],C_text("main#last-exit-code"));
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}}

/* k7351 in k7331 in k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_7353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_7353,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7356,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:1082: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k7354 in k7351 in k7331 in k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in ... */
static void C_ccall f_7356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_7356,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7359,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csc.scm:1082: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[151];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k7357 in k7354 in k7351 in k7331 in k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in ... */
static void C_ccall f_7359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_7359,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7362,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:1082: ##sys#print */
t3=*((C_word*)lf[48]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k7360 in k7357 in k7354 in k7351 in k7331 in k7328 in k7325 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in ... */
static void C_ccall f_7362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7362,c,av);}
/* csc.scm:1082: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[46]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[46]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k7376 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7378(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7378,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7382,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1072: g1714 */
t3=t2;
f_7382(t3,((C_word*)t0)[3],t1);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
f_7327(2,av2);}}}

/* g1714 in k7376 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_fcall f_7382(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_7382,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7390,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csc.scm:1077: chicken.process#qs */
t4=C_fast_retrieve(lf[55]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k7388 in g1714 in k7376 in main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_7390(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7390,c,av);}
/* csc.scm:1076: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[157];
av2[3]=t1;
av2[4]=lf[158];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* main#command in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_fcall f_7398(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_7398,2,t1,t2);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7327,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_mk_bool(C_WINDOWS_SHELL))){
/* csc.scm:1073: scheme#string-append */
t4=*((C_word*)lf[80]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[155];
av2[3]=t2;
av2[4]=lf[156];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7378,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[33],C_text("main#osx")))){
/* csc.scm:1074: chicken.process-context#get-environment-variable */
t5=C_fast_retrieve(lf[159]);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[160];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_7378(2,av2);}}}}

/* main#$delete-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_7411(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7411,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7415,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_retrieve2(lf[125],C_text("main#verbose")))){
/* csc.scm:1093: chicken.base#print */
t4=*((C_word*)lf[154]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[163];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
if(C_truep(C_retrieve2(lf[104],C_text("main#dry-run")))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* csc.scm:1094: chicken.file#delete-file */
t4=C_fast_retrieve(lf[162]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}}

/* k7413 in main#$delete-file in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7415,c,av);}
if(C_truep(C_retrieve2(lf[104],C_text("main#dry-run")))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* csc.scm:1094: chicken.file#delete-file */
t2=C_fast_retrieve(lf[162]);{
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

/* k7428 in k6689 in k6674 in k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in ... */
static void C_ccall f_7430(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7430,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7435,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:1098: scheme#with-output-to-file */
t3=C_fast_retrieve(lf[209]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a7434 in k7428 in k6689 in k6674 in k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in ... */
static void C_ccall f_7435(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7435,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7443,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_cons(&a,2,lf[206],C_SCHEME_END_OF_LIST);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],t3);
t5=C_a_i_cons(&a,2,lf[207],t4);
/* csc.scm:28: ##sys#print-to-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[208]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[208]+1);
av2[1]=t2;
av2[2]=t5;
tp(3,av2);}}

/* k7441 in a7434 in k7428 in k6689 in k6674 in k6671 in k6535 in k4459 in k4456 in k4453 in k4450 in k4446 in loop in k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in ... */
static void C_ccall f_7443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7443,c,av);}
/* csc.scm:1100: chicken.base#print */
t2=*((C_word*)lf[154]+1);{
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

/* k7459 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_7461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7461,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7467,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base#implicit-exit-handler */
t3=C_fast_retrieve(lf[164]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k7465 in k7459 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7467,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7469 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_7471(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,5)))){
C_save_and_reclaim((void *)f_7471,c,av);}
a=C_alloc(25);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4358,tmp=(C_word)a,a+=2,tmp));
t11=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4365,tmp=(C_word)a,a+=2,tmp));
t12=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4391,tmp=(C_word)a,a+=2,tmp));
t13=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4421,tmp=(C_word)a,a+=2,tmp));
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4437,a[2]=t9,a[3]=t15,a[4]=t3,a[5]=t5,a[6]=t7,tmp=(C_word)a,a+=7,tmp));
t17=((C_word*)t15)[1];
f_4437(t17,((C_word*)t0)[2],t1);}

/* k7473 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_7475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7475,c,av);}
/* csc.scm:1122: scheme#append */
t2=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[51],C_text("main#arguments"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k7477 in k4090 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_7479(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7479,c,av);}
if(C_truep(t1)){
/* csc.scm:1123: chicken.string#string-split */
t2=C_fast_retrieve(lf[235]);{
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
/* csc.scm:1123: chicken.string#string-split */
t2=C_fast_retrieve(lf[235]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[415];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in ... */
static void C_fcall f_7486(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_7486,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7490,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csc.scm:249: chicken.process-context#get-environment-variable */
t3=C_fast_retrieve(lf[159]);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[419];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in ... */
static void C_ccall f_7490(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_7490,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7493,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t8=t7;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=((C_word*)t9)[1];
t11=C_retrieve2(lf[54],C_text("main#quotewrap"));
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7509,a[2]=t5,a[3]=t6,a[4]=t2,a[5]=t9,a[6]=t10,tmp=(C_word)a,a+=7,tmp);
/* csc.scm:251: chicken.string#string-split */
t13=C_fast_retrieve(lf[235]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t13;
av2[1]=t12;
av2[2]=t1;
av2[3]=lf[418];
((C_proc)(void*)(*((C_word*)t13+1)))(4,av2);}}
else{
/* csc.scm:247: scheme#append */
t3=*((C_word*)lf[143]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k7491 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7493,c,av);}
/* csc.scm:247: scheme#append */
t2=*((C_word*)lf[143]+1);{
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

/* k7507 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in ... */
static void C_ccall f_7509(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_7509,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7512,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7554,a[2]=((C_word*)t0)[5],a[3]=t4,a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_7554(t6,t2,t1);}

/* k7510 in k7507 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_ccall f_7512(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7512,c,av);}
a=C_alloc(7);
t2=C_i_check_list_2(t1,lf[141]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7520,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_7520(t6,((C_word*)t0)[4],t1);}

/* map-loop886 in k7510 in k7507 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_fcall f_7520(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7520,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7545,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:251: g909 */
t4=*((C_word*)lf[80]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[417];
av2[3]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7543 in map-loop886 in k7510 in k7507 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in ... */
static void C_ccall f_7545(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7545,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7520(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop913 in k7507 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in ... */
static void C_fcall f_7554(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7554,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7579,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csc.scm:251: g919 */
t4=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_3870(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7577 in map-loop913 in k7507 in k7488 in k7484 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in ... */
static void C_ccall f_7579(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7579,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7554(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7594 in k4037 in k4007 in k4000 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in ... */
static void C_ccall f_7596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7596,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_7486(t2,C_a_i_list1(&a,1,t1));}

/* k7614 in k3995 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in ... */
static void C_ccall f_7616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7616,c,av);}
/* csc.scm:144: chicken.string#string-split */
t2=C_fast_retrieve(lf[235]);{
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

/* k7618 in k3990 in k3940 in k3935 in k3931 in k3918 in k3914 in k3910 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in ... */
static void C_ccall f_7620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7620,c,av);}
/* csc.scm:139: chicken.string#string-split */
t2=C_fast_retrieve(lf[235]);{
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

/* k7643 in k3906 in k3902 in k3898 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in ... */
static void C_ccall f_7645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7645,c,av);}
/* csc.scm:103: quotewrap */
t2=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
f_3870(3,av2);}}

/* k7661 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in ... */
static void C_ccall f_7663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7663,c,av);}
/* csc.scm:99: quotewrap */
t2=C_retrieve2(lf[54],C_text("main#quotewrap"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
f_3870(3,av2);}}

/* k7665 in k3850 in k3846 in k3816 in k3810 in k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in ... */
static void C_ccall f_7667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7667,c,av);}
/* csc.scm:99: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[19],C_text("main#host-bindir"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k7672 in k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in ... */
static void C_ccall f_7674(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7674,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[36]);
t3=lf[37] /* main#aix */ =t2;;
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3812,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:71: chicken.platform#software-version */
t5=C_fast_retrieve(lf[242]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7676 in k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in ... */
static void C_ccall f_7678(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7678,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[34]);
t3=lf[35] /* main#cygwin */ =t2;;
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7674,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:70: chicken.platform#build-platform */
t5=C_fast_retrieve(lf[370]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7680 in k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in ... */
static void C_ccall f_7682(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7682,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[32]);
t3=lf[33] /* main#osx */ =t2;;
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7678,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:69: chicken.platform#software-version */
t5=C_fast_retrieve(lf[242]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7684 in k3784 in k2499 in k2495 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in ... */
static void C_ccall f_7686(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7686,c,av);}
a=C_alloc(3);
t2=C_eqp(t1,lf[30]);
t3=lf[31] /* main#mingw */ =t2;;
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7682,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csc.scm:68: chicken.platform#software-version */
t5=C_fast_retrieve(lf[242]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k7695 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in ... */
static void C_ccall f_7697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7697,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7700,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
/* egg-environment.scm:123: chicken.pathname#make-pathname */
t3=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[6],C_text("main#chicken-install-program"));
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* egg-environment.scm:124: chicken.process-context#current-directory */
t3=C_fast_retrieve(lf[430]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7698 in k7695 in k2492 in k2408 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in ... */
static void C_ccall f_7700(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7700,c,av);}
/* egg-environment.scm:123: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_retrieve2(lf[6],C_text("main#chicken-install-program"));
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k7705 in k2404 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in ... */
static void C_ccall f_7707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7707,c,av);}
/* egg-environment.scm:99: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[12],C_text("main#default-runlibdir"));
av2[3]=lf[433];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k7710 in k2400 in k2396 in k2392 in k2388 in k2384 in k2380 in k2376 in k2372 in k2368 in k2364 in k2360 in k2356 in k2352 in k2348 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in ... */
static void C_ccall f_7712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7712,c,av);}
/* egg-environment.scm:96: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[11],C_text("main#default-libdir"));
av2[3]=lf[435];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k7715 in k2344 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in ... */
static void C_ccall f_7717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7717,c,av);}
/* egg-environment.scm:78: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[138]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[14],C_text("main#default-bindir"));
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k7719 in k2340 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in ... */
static void C_ccall f_7721(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7721,c,av);}
/* egg-environment.scm:75: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[14],C_text("main#default-bindir"));
av2[3]=lf[436];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k7723 in k2336 in k2332 in k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in ... */
static void C_ccall f_7725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7725,c,av);}
/* egg-environment.scm:72: scheme#string-append */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[14],C_text("main#default-bindir"));
av2[3]=lf[437];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k7730 in k2324 in k2320 in k2316 in k2312 in k2308 in k2304 in k2300 in k2296 in k2292 in k2288 in k2284 in k2280 in k2276 in k2272 in k2268 in k2262 in k2256 in k2253 in k2250 in k2247 in k2244 in ... */
static void C_ccall f_7732(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7732,c,av);}
a=C_alloc(6);
t2=C_eqp(t1,lf[16]);
t3=(C_truep(t2)?C_mk_bool(C_WINDOWS_SHELL):lf[17]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2334,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#peek-c-string */
t5=*((C_word*)lf[50]+1);{
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

/* a7733 in k2238 in k2235 */
static void C_ccall f_7734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_7734,c,av);}
/* csc.scm:28: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[438]);
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[438]+1);
av2[1]=t1;
av2[2]=lf[439];
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
if(C_unlikely(!C_demand_2(2235))){
C_save(t1);
C_rereclaim2(2235*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,441);
lf[0]=C_h_intern(&lf[0],5, C_text("main#"));
lf[16]=C_h_intern(&lf[16],7, C_text("windows"));
lf[17]=C_h_intern(&lf[17],4, C_text("unix"));
lf[30]=C_h_intern(&lf[30],7, C_text("mingw32"));
lf[32]=C_h_intern(&lf[32],6, C_text("macosx"));
lf[34]=C_h_intern(&lf[34],6, C_text("cygwin"));
lf[36]=C_h_intern(&lf[36],3, C_text("aix"));
lf[39]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\007\001solaris\376\003\000\000\002\376\001\000\000\005\001sunos\376\377\016"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\005\001linux\376\003\000\000\002\376\001\000\000\006\001netbsd\376\003\000\000\002\376\001\000\000\007\001freebsd\376\003\000\000\002\376\001\000\000\007\001solaris\376\003\000\000\002\376\001\000\000\007\001"
"openbsd\376\003\000\000\002\376\001\000\000\004\001hurd\376\003\000\000\002\376\001\000\000\005\001haiku\376\377\016"));
lf[43]=C_h_intern(&lf[43],20, C_text("##sys#standard-error"));
lf[44]=C_h_intern(&lf[44],7, C_text("fprintf"));
lf[45]=C_h_intern(&lf[45],17, C_text("chicken.base#exit"));
lf[46]=C_h_intern(&lf[46],18, C_text("##sys#write-char-0"));
lf[47]=C_h_intern(&lf[47],22, C_text("chicken.format#fprintf"));
lf[48]=C_h_intern(&lf[48],11, C_text("##sys#print"));
lf[49]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[50]=C_h_intern(&lf[50],19, C_text("##sys#peek-c-string"));
lf[52]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-host"));
lf[55]=C_h_intern(&lf[55],18, C_text("chicken.process#qs"));
lf[56]=C_h_intern(&lf[56],31, C_text("chicken.string#string-translate"));
lf[57]=C_h_intern(&lf[57],35, C_text("chicken.pathname#normalize-pathname"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003obj"));
lf[67]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001o"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001a"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[74]=C_h_intern(&lf[74],28, C_text("##sys#load-dynamic-extension"));
lf[80]=C_h_intern(&lf[80],20, C_text("scheme#string-append"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003lib"));
lf[113]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\014/usr/include\376\003\000\000\002\376B\000\000\000\376\377\016"));
lf[121]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-R"));
lf[122]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-rpath="));
lf[133]=C_h_intern(&lf[133],32, C_text("chicken.platform#repository-path"));
lf[135]=C_h_intern(&lf[135],22, C_text("chicken.load#find-file"));
lf[136]=C_h_intern(&lf[136],16, C_text("##sys#setup-mode"));
lf[137]=C_h_intern(&lf[137],25, C_text("chicken.file#file-exists\077"));
lf[138]=C_h_intern(&lf[138],30, C_text("chicken.pathname#make-pathname"));
lf[141]=C_h_intern(&lf[141],3, C_text("map"));
lf[142]=C_h_intern(&lf[142],33, C_text("chicken.string#string-intersperse"));
lf[143]=C_h_intern(&lf[143],13, C_text("scheme#append"));
lf[146]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-l"));
lf[149]=C_h_intern(&lf[149],21, C_text("##sys#standard-output"));
lf[150]=C_h_intern(&lf[150],6, C_text("printf"));
lf[151]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[152]=C_decode_literal(C_heaptop,C_text("\376B\000\000;\012Error: shell command terminated with non-zero exit status "));
lf[153]=C_h_intern(&lf[153],22, C_text("chicken.process#system"));
lf[154]=C_h_intern(&lf[154],18, C_text("chicken.base#print"));
lf[155]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[156]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[157]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037/usr/bin/env DYLD_LIBRARY_PATH="));
lf[158]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[159]=C_h_intern(&lf[159],48, C_text("chicken.process-context#get-environment-variable"));
lf[160]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021DYLD_LIBRARY_PATH"));
lf[162]=C_h_intern(&lf[162],24, C_text("chicken.file#delete-file"));
lf[163]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003rm "));
lf[164]=C_h_intern(&lf[164],34, C_text("chicken.base#implicit-exit-handler"));
lf[165]=C_decode_literal(C_heaptop,C_text("\376B\000\000#not enough arguments to option `~A\047"));
lf[166]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\013-dynamiclib\376\377\016"));
lf[167]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\007-bundle\376\003\000\000\002\376B\000\000\034-headerpad_max_install_names\376\377\016"));
lf[168]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\007-shared\376\377\016"));
lf[169]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\012-DC_SHARED\376\377\016"));
lf[170]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-feature"));
lf[171]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026chicken-compile-shared"));
lf[172]=C_h_intern(&lf[172],43, C_text("chicken.pathname#pathname-replace-extension"));
lf[173]=C_h_intern(&lf[173],8, C_text("for-each"));
lf[174]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011 -change "));
lf[175]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007.dylib "));
lf[176]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[177]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020@executable_path"));
lf[178]=C_h_intern(&lf[178],19, C_text("##sys#string-append"));
lf[179]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006.dylib"));
lf[180]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003-o "));
lf[181]=C_h_intern(&lf[181],14, C_text("scheme#reverse"));
lf[182]=C_h_intern(&lf[182],23, C_text("chicken.string#->string"));
lf[183]=C_decode_literal(C_heaptop,C_text("\376B\000\000#could not find linked extension: ~A"));
lf[184]=C_h_intern(&lf[184],27, C_text("scheme#with-input-from-file"));
lf[185]=C_h_intern(&lf[185],11, C_text("scheme#read"));
lf[186]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004link"));
lf[187]=C_h_intern(&lf[187],27, C_text("chicken.string#string-chomp"));
lf[188]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007.static"));
lf[189]=C_h_intern(&lf[189],41, C_text("chicken.pathname#pathname-strip-extension"));
lf[190]=C_h_intern(&lf[190],6, C_text("format"));
lf[191]=C_h_intern(&lf[191],30, C_text("chicken.base#get-output-string"));
lf[192]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004.old"));
lf[193]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004move"));
lf[194]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002mv"));
lf[195]=C_h_intern(&lf[195],31, C_text("chicken.base#open-output-string"));
lf[196]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005.old\047"));
lf[197]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030\047 - renaming source to `"));
lf[198]=C_decode_literal(C_heaptop,C_text("\376B\000\0001Warning: output file will overwrite source file `"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-c"));
lf[200]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003g++"));
lf[201]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022-Wno-write-strings"));
lf[202]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[203]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003-o "));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000Pobject file generated from `~a\047 will overwrite explicitly given object file"
" `~a\047"));
lf[205]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[206]=C_decode_literal(C_heaptop,C_text("\376B\000\001\232\042\042 type=\042\042win32\042\042/>\134r\134n\042\012  \042  <ms_asmv2:trustInfo xmlns:ms_asmv2=\042\042urn:sche"
"mas-microsoft-com:asm.v2\042\042>\134r\134n\042\012  \042    <ms_asmv2:security>\134r\134n\042\012  \042      <ms_as"
"mv2:requestedPrivileges>\134r\134n\042\012  \042        <ms_asmv2:requestedExecutionLevel level"
"=\042\042asInvoker\042\042 uiAccess=\042\042false\042\042/>\134r\134n\042\012  \042      </ms_asmv2:requestedPrivileges"
">\134r\134n\042\012  \042    </ms_asmv2:security>\134r\134n\042\012  \042  </ms_asmv2:trustInfo>\134r\134n\042\012  \042</ass"
"embly>\134r\134n\042\012END"));
lf[207]=C_decode_literal(C_heaptop,C_text("\376B\000\001\0031 24 MOVEABLE PURE\012BEGIN\012  \042<\077xml version=\042\0421.0\042\042 encoding=\042\042UTF-8\042\042 standa"
"lone=\042\042yes\042\042\077>\134r\134n\042\012  \042<assembly xmlns=\042\042urn:schemas-microsoft-com:asm.v1\042\042 mani"
"festVersion=\042\0421.0\042\042>\134r\134n\042\012  \042  <assemblyIdentity version=\042\0421.0.0.0\042\042 processorAr"
"chitecture=\042\042\052\042\042 name=\042\042"));
lf[208]=C_h_intern(&lf[208],21, C_text("##sys#print-to-string"));
lf[209]=C_h_intern(&lf[209],26, C_text("scheme#with-output-to-file"));
lf[210]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013generating "));
lf[211]=C_h_intern(&lf[211],30, C_text("chicken.pathname#pathname-file"));
lf[212]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002rc"));
lf[213]=C_h_intern(&lf[213],30, C_text("chicken.platform#software-type"));
lf[214]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031no source files specified"));
lf[215]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011bogus.scm"));
lf[216]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004link"));
lf[217]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[218]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\003-:d\376\377\016"));
lf[219]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\010-feature\376\003\000\000\002\376B\000\000\025chicken-scheme-to-c++\376\377\016"));
lf[220]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\010-feature\376\003\000\000\002\376B\000\000\026chicken-scheme-to-objc\376\377\016"));
lf[221]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-emit-link-file"));
lf[222]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-emit-link-file"));
lf[223]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004link"));
lf[224]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\012-to-stdout\376\377\016"));
lf[225]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-output-file"));
lf[226]=C_decode_literal(C_heaptop,C_text("\376B\000\000KC file generated from `~a\047 will overwrite explicitly given source file `~a\047"
));
lf[227]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003cpp"));
lf[228]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001m"));
lf[229]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001c"));
lf[230]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-dynamic"));
lf[231]=C_decode_literal(C_heaptop,C_text("\376B\000\000Gthe `-c\047 option cannot be used in combination with multiple input files"));
lf[232]=C_h_intern(&lf[232],14, C_text("scheme#newline"));
lf[233]=C_h_intern(&lf[233],19, C_text("chicken.base#print\052"));
lf[234]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-L"));
lf[235]=C_h_intern(&lf[235],27, C_text("chicken.string#string-split"));
lf[236]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002:;"));
lf[237]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026CHICKEN_C_LIBRARY_PATH"));
lf[238]=C_h_intern(&lf[238],7, C_text("freebsd"));
lf[239]=C_h_intern(&lf[239],7, C_text("openbsd"));
lf[240]=C_h_intern(&lf[240],6, C_text("netbsd"));
lf[241]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-Wl,-z,origin"));
lf[242]=C_h_intern(&lf[242],33, C_text("chicken.platform#software-version"));
lf[243]=C_h_intern(&lf[243],19, C_text("chicken.string#conc"));
lf[244]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004-Wl,"));
lf[245]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007$ORIGIN"));
lf[246]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-L"));
lf[247]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004-Wl,"));
lf[248]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[249]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[250]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-L"));
lf[251]=C_h_intern(&lf[251],5, C_text("-help"));
lf[252]=C_h_intern(&lf[252],6, C_text("--help"));
lf[253]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003\047.\012"));
lf[254]=C_decode_literal(C_heaptop,C_text("\376B\000\052+\047 is a driver program for the CHICKEN compiler. Files given on the\012  comman"
"d line are translated, compiled or linked as needed.\012\012  FILENAME is a Scheme sou"
"rce file name with optional extension or a\012  C/C++/Objective-C source, object or"
" library file name with extension. OPTION\012  may be one of the following:\012\012  Gene"
"ral options:\012\012    -h  -help                      display this text and exit\012    "
"-v  -verbose                   show compiler notes and tool-invocations\012    -vv "
"                           display information about translation\012               "
"                     progress\012    -vvv                           display informa"
"tion about all compilation\012                                    stages\012    -versi"
"on                       display Scheme compiler version and exit\012    -release  "
"                     display release number and exit\012\012  File and pathname option"
"s:\012\012    -o -output-file FILENAME       specifies target executable name\012    -I -"
"include-path PATHNAME      specifies alternative path for included\012             "
"                       files\012    -to-stdout                     write compiler t"
"o stdout (implies -t)\012    -s -shared -dynamic            generate dynamically lo"
"adable shared object\012                                    file\012\012  Language option"
"s:\012\012    -D  -DSYMBOL  -feature SYMBOL  register feature identifier\012    -no-featu"
"re SYMBOL             disable builtin feature identifier\012    -c++               "
"            compile via a C++ source file (.cpp) \012    -objc                     "
"     compile via Objective-C source file (.m)\012\012  Syntax related options:\012\012    -i"
" -case-insensitive           don\047t preserve case of read symbols    \012    -K -key"
"word-style STYLE        enable alternative keyword-syntax\012                      "
"              (prefix, suffix or none)\012       -no-parentheses-synonyms    disabl"
"es list delimiter synonyms\012       -no-symbol-escape           disables support f"
"or escaped symbols\012       -r5rs-syntax                disables the CHICKEN exten"
"sions to\012                                    R5RS syntax\012    -compile-syntax    "
"            macros are made available at run-time\012    -j -emit-import-library MO"
"DULE write compile-time module information into\012                                "
"    separate file\012    -J -emit-all-import-libraries  emit import-libraries for a"
"ll defined modules\012    -no-compiler-syntax            disable expansion of compi"
"ler-macros\012    -m -module NAME                wrap compiled code in a module\012   "
" -M -module-registration        always generate module registration code\012    -N "
"-no-module-registration     never generate module registration code\012            "
"                        (overrides `-M\047)\012\012  Translation options:\012\012    -x  -expli"
"cit-use              do not use units `library\047 and `eval\047 by\012                  "
"                  default\012    -P  -check-syntax              stop compilation af"
"ter macro-expansion\012    -A  -analyze-only              stop compilation after fi"
"rst analysis pass\012\012  Debugging options:\012\012    -w  -no-warnings               disa"
"ble warnings\012    -d0 -d1 -d2 -d3 -debug-level NUMBER\012                           "
"        set level of available debugging information\012    -no-trace              "
"        disable rudimentary debugging information\012    -debug-info               "
"     enable debug-information in compiled code for use\012                         "
"           with an external debugger\012    -profile                       executab"
"le emits profiling information \012    -accumulate-profile            executable em"
"its profiling information in\012                                    append mode\012   "
" -profile-name FILENAME         name of the generated profile information\012      "
"                              file\012    -consult-types-file FILENAME   load addit"
"ional type database\012\012  Optimization options:\012\012    -O -O0 -O1 -O2 -O3 -O4 -O5 -op"
"timize-level NUMBER\012                                   enable certain sets of op"
"timization options\012    -optimize-leaf-routines        enable leaf routine optimi"
"zation\012    -no-usual-integrations         standard procedures may be redefined\012 "
"   -u  -unsafe                    disable safety checks\012    -local              "
"           assume globals are only modified in current\012                         "
"           file\012    -b  -block                     enable block-compilation\012    "
"-disable-interrupts            disable interrupts in compiled code\012    -f  -fixn"
"um-arithmetic         assume all numbers are fixnums\012    -disable-stack-overflow"
"-checks disables detection of stack-overflows\012    -inline                       "
" enable inlining\012    -inline-limit LIMIT            set inlining threshold\012    -"
"inline-global                 enable cross-module inlining\012    -specialize      "
"              perform type-based specialization of primitive calls\012    -oi -emit"
"-inline-file FILENAME generate file with globally inlinable\012                    "
"                procedures (implies -inline -local)\012    -consult-inline-file FIL"
"ENAME  explicitly load inline file\012    -ot  -emit-types-file FILENAME write type"
"-declaration information into file\012    -no-argc-checks                disable ar"
"gument count checks\012    -no-bound-checks               disable bound variable ch"
"ecks\012    -no-procedure-checks           disable procedure call checks\012    -no-pr"
"ocedure-checks-for-usual-bindings\012                                   disable pro"
"cedure call checks only for usual\012                                    bindings\012 "
"   -no-procedure-checks-for-toplevel-bindings\012                                  "
" disable procedure call checks for toplevel\012                                    "
"bindings\012    -strict-types                  assume variable do not change their "
"type\012    -clustering                    combine groups of local procedures into "
"dispatch\012                                     loop\012    -lfa2                    "
"      perform additional lightweight flow-analysis pass\012    -unroll-limit LIMIT "
"         specifies inlining limit for self-recursive calls\012\012  Configuration opti"
"ons:\012\012    -unit NAME                     compile file as a library unit\012    -use"
"s NAME                     declare library unit as used.\012    -heap-size NUMBER  "
"            specifies heap-size of compiled executable\012    -nursery NUMBER  -sta"
"ck-size NUMBER\012                                   specifies nursery size of comp"
"iled\012                                   executable\012    -X -extend FILENAME      "
"      load file before compilation commences\012    -prelude EXPRESSION            "
"add expression to beginning of source file\012    -postlude EXPRESSION           ad"
"d expression to end of source file\012    -prologue FILENAME             include fi"
"le before main source file\012    -epilogue FILENAME             include file after"
" main source file\012\012    -e  -embedded                  compile as embedded\012      "
"                              (don\047t generate `main()\047)\012    -gui                "
"           compile as GUI application\012    -link NAME                     link ex"
"tension with compiled executable\012                                    (implies -u"
"ses)\012    -R  -require-extension NAME    require extension and import in compiled"
"\012                                    code\012    -dll -library                  com"
"pile multiple units into a dynamic\012                                    library\012 "
"   -libdir DIRECTORY              override directory for runtime library\012\012  Opti"
"ons to other passes:\012\012    -C OPTION                      pass option to C compil"
"er\012    -L OPTION                      pass option to linker\012    -I<DIR>         "
"               pass \134\042-I<DIR>\134\042 to C compiler\012                                  "
"  (add include path)\012    -L<DIR>                        pass \134\042-L<DIR>\134\042 to link"
"er\012                                    (add library path)\012    -k                "
"             keep intermediate files\012    -c                             stop aft"
"er compilation to object files\012    -t                             stop after tra"
"nslation to C\012    -cc COMPILER                   select other C compiler than th"
"e default\012    -cxx COMPILER                  select other C++ compiler than the "
"default\012    -ld COMPILER                   select other linker than the default "
"\012    -static                        link with static CHICKEN libraries and\012     "
"                               extensions (if possible)\012    -F<DIR>             "
"           pass \134\042-F<DIR>\134\042 to C compiler\012                                    (a"
"dd framework header path on Mac OS X)\012    -framework NAME                passed "
"to linker on Mac OS X\012    -rpath PATHNAME                add directory to runtim"
"e library search path\012    -Wl,...                        pass linker options\012   "
" -strip                         strip resulting binary\012\012  Inquiry options:\012\012    "
"-home                          show home-directory (where support files go)\012    "
"-cflags                        show required C-compiler flags and exit\012    -ldfl"
"ags                       show required linker flags and exit\012    -libs         "
"                 show required libraries and exit\012    -cc-name                  "
"     show name of default C compiler used\012    -cxx-name                      sho"
"w name of default C++ compiler used\012    -ld-name                       show name"
" of default linker used\012    -dry-run                       just show commands ex"
"ecuted, don\047t run them\012                                    (implies `-v\047)\012\012  Obs"
"cure options:\012\012    -debug MODES                   display debugging output for t"
"he given modes\012    -compiler PATHNAME             use other compiler than defaul"
"t `chicken\047\012    -raw                           do not generate implicit init- an"
"d exit code\012    -emit-external-prototypes-first\012                                "
"   emit prototypes for callbacks before foreign\012                                "
"    declarations\012    -regenerate-import-libraries   emit import libraries even w"
"hen unchanged\012    -ignore-repository             do not refer to repository for "
"extensions\012    -keep-shadowed-macros          do not remove shadowed macro\012    -"
"host                          compile for host when configured for\012             "
"                       cross-compiling\012    -private-repository            load e"
"xtensions from executable path\012    -deployed                      link support f"
"ile to be used from a deployed \012                                    executable ("
"sets `rpath\047 accordingly, if supported\012                                    on th"
"is platform)\012    -no-elevation                  embed manifest on Windows to sup"
"ress elevation\012                                    warnings for programs named `"
"install\047 or `setup\047\012\012  Options can be collapsed if unambiguous, so\012\012    -vkfO\012\012 "
" is the same as\012\012    -v -k -fixnum-arithmetic -optimize\012\012  The contents of the e"
"nvironment variable CSC_OPTIONS are implicitly passed to\012  every invocation of `"
));
lf[255]=C_decode_literal(C_heaptop,C_text("\376B\000\000! [OPTION ...] [FILENAME ...]\012\012  `"));
lf[256]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007Usage: "));
lf[257]=C_h_intern(&lf[257],8, C_text("-release"));
lf[258]=C_h_intern(&lf[258],32, C_text("chicken.platform#chicken-version"));
lf[259]=C_h_intern(&lf[259],8, C_text("-version"));
lf[260]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011 -version"));
lf[261]=C_h_intern(&lf[261],4, C_text("-c++"));
lf[262]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-no-cpp-precomp"));
lf[263]=C_h_intern(&lf[263],5, C_text("-objc"));
lf[264]=C_h_intern(&lf[264],7, C_text("-static"));
lf[265]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-static"));
lf[266]=C_h_intern(&lf[266],7, C_text("-cflags"));
lf[267]=C_h_intern(&lf[267],8, C_text("-ldflags"));
lf[268]=C_h_intern(&lf[268],8, C_text("-cc-name"));
lf[269]=C_h_intern(&lf[269],9, C_text("-cxx-name"));
lf[270]=C_h_intern(&lf[270],8, C_text("-ld-name"));
lf[271]=C_h_intern(&lf[271],5, C_text("-home"));
lf[272]=C_h_intern(&lf[272],5, C_text("-libs"));
lf[273]=C_h_intern(&lf[273],2, C_text("-v"));
lf[274]=C_h_intern(&lf[274],8, C_text("-verbose"));
lf[275]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-verbose"));
lf[276]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-v"));
lf[277]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-v"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-Q"));
lf[279]=C_h_intern(&lf[279],2, C_text("-w"));
lf[280]=C_h_intern(&lf[280],12, C_text("-no-warnings"));
lf[281]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-w"));
lf[282]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-no-warnings"));
lf[283]=C_h_intern(&lf[283],2, C_text("-A"));
lf[284]=C_h_intern(&lf[284],13, C_text("-analyze-only"));
lf[285]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-analyze-only"));
lf[286]=C_h_intern(&lf[286],2, C_text("-P"));
lf[287]=C_h_intern(&lf[287],13, C_text("-check-syntax"));
lf[288]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-check-syntax"));
lf[289]=C_h_intern(&lf[289],2, C_text("-k"));
lf[290]=C_h_intern(&lf[290],2, C_text("-c"));
lf[291]=C_h_intern(&lf[291],2, C_text("-t"));
lf[292]=C_h_intern(&lf[292],2, C_text("-e"));
lf[293]=C_h_intern(&lf[293],9, C_text("-embedded"));
lf[294]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-DC_EMBEDDED"));
lf[295]=C_h_intern(&lf[295],5, C_text("-link"));
lf[296]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002, "));
lf[297]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-link"));
lf[298]=C_h_intern(&lf[298],7, C_text("-libdir"));
lf[299]=C_h_intern(&lf[299],18, C_text("-require-extension"));
lf[300]=C_h_intern(&lf[300],2, C_text("-R"));
lf[301]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022-require-extension"));
lf[302]=C_h_intern(&lf[302],19, C_text("-private-repository"));
lf[303]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026-DC_PRIVATE_REPOSITORY"));
lf[304]=C_h_intern(&lf[304],18, C_text("-ignore-repository"));
lf[305]=C_h_intern(&lf[305],11, C_text("-setup-mode"));
lf[306]=C_h_intern(&lf[306],13, C_text("-no-elevation"));
lf[307]=C_h_intern(&lf[307],4, C_text("-gui"));
lf[308]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-DC_GUI"));
lf[309]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012-lkernel32"));
lf[310]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-luser32"));
lf[311]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-lgdi32"));
lf[312]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011-mwindows"));
lf[313]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012chicken.rc"));
lf[314]=C_h_intern(&lf[314],9, C_text("-deployed"));
lf[315]=C_h_intern(&lf[315],10, C_text("-framework"));
lf[316]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012-framework"));
lf[317]=C_h_intern(&lf[317],2, C_text("-o"));
lf[318]=C_h_intern(&lf[318],12, C_text("-output-file"));
lf[319]=C_h_intern(&lf[319],2, C_text("-O"));
lf[320]=C_h_intern(&lf[320],3, C_text("-O1"));
lf[321]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-optimize-level"));
lf[322]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0011"));
lf[323]=C_h_intern(&lf[323],3, C_text("-O0"));
lf[324]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-optimize-level"));
lf[325]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0010"));
lf[326]=C_h_intern(&lf[326],3, C_text("-O2"));
lf[327]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-optimize-level"));
lf[328]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0012"));
lf[329]=C_h_intern(&lf[329],3, C_text("-O3"));
lf[330]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-optimize-level"));
lf[331]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0013"));
lf[332]=C_h_intern(&lf[332],3, C_text("-O4"));
lf[333]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-optimize-level"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0014"));
lf[335]=C_h_intern(&lf[335],3, C_text("-O5"));
lf[336]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-optimize-level"));
lf[337]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0015"));
lf[338]=C_h_intern(&lf[338],3, C_text("-d0"));
lf[339]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-debug-level"));
lf[340]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0010"));
lf[341]=C_h_intern(&lf[341],3, C_text("-d1"));
lf[342]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-debug-level"));
lf[343]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0011"));
lf[344]=C_h_intern(&lf[344],3, C_text("-d2"));
lf[345]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-debug-level"));
lf[346]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0012"));
lf[347]=C_h_intern(&lf[347],3, C_text("-d3"));
lf[348]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014-debug-level"));
lf[349]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0013"));
lf[350]=C_h_intern(&lf[350],6, C_text("-debug"));
lf[351]=C_h_intern(&lf[351],18, C_text("##sys#string->list"));
lf[352]=C_h_intern(&lf[352],8, C_text("-dry-run"));
lf[353]=C_h_intern(&lf[353],2, C_text("-s"));
lf[354]=C_h_intern(&lf[354],4, C_text("-dll"));
lf[355]=C_h_intern(&lf[355],8, C_text("-library"));
lf[356]=C_h_intern(&lf[356],9, C_text("-compiler"));
lf[357]=C_h_intern(&lf[357],3, C_text("-cc"));
lf[358]=C_h_intern(&lf[358],4, C_text("-cxx"));
lf[359]=C_h_intern(&lf[359],3, C_text("-ld"));
lf[360]=C_h_intern(&lf[360],2, C_text("-I"));
lf[361]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-include-path"));
lf[362]=C_h_intern(&lf[362],2, C_text("-C"));
lf[363]=C_h_intern(&lf[363],6, C_text("-strip"));
lf[364]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-s"));
lf[365]=C_h_intern(&lf[365],2, C_text("-L"));
lf[366]=C_h_intern(&lf[366],6, C_text("-rpath"));
lf[367]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004-Wl,"));
lf[368]=C_h_intern(&lf[368],3, C_text("gnu"));
lf[369]=C_h_intern(&lf[369],5, C_text("clang"));
lf[370]=C_h_intern(&lf[370],31, C_text("chicken.platform#build-platform"));
lf[371]=C_h_intern(&lf[371],5, C_text("-host"));
lf[372]=C_h_intern(&lf[372],3, C_text("-oi"));
lf[373]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021-emit-inline-file"));
lf[374]=C_h_intern(&lf[374],3, C_text("-ot"));
lf[375]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020-emit-types-file"));
lf[376]=C_h_intern(&lf[376],1, C_text("-"));
lf[377]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001a"));
lf[378]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\001-\376\377\016"));
lf[379]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-h\376\003\000\000\002\376B\000\000\005-help\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-s\376\003\000\000\002\376B\000\000\007-shared\376\377\016\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\002\001-m\376\003\000\000\002\376B\000\000\007-module\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-P\376\003\000\000\002\376B\000\000\015-check-syntax\376\377\016\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\002\001-f\376\003\000\000\002\376B\000\000\022-fixnum-arithmetic\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-D\376\003\000\000\002\376B\000\000\010-featur"
"e\376\377\016\376\003\000\000\002\376\003\000\000\002\376\016\000\000\002\376\377\001\000\000\000\000\376\377\001\377\377\377\377\376\003\000\000\002\376B\000\000\021-case-insensitive\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-"
"K\376\003\000\000\002\376B\000\000\016-keyword-style\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-X\376\003\000\000\002\376B\000\000\007-extend\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\002\001-J\376\003\000\000\002\376B\000\000\032-emit-all-import-libraries\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-M\376\003\000\000\002\376B\000\000\024-module-r"
"egistration\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-N\376\003\000\000\002\376B\000\000\027-no-module-registration\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\002\001-x\376\003\000\000\002\376B\000\000\015-explicit-use\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-u\376\003\000\000\002\376B\000\000\007-unsafe\376\377\016\376\003\000\000\002\376\003\000\000\002"
"\376\001\000\000\002\001-j\376\003\000\000\002\376B\000\000\024-emit-import-library\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\002\001-b\376\003\000\000\002\376B\000\000\006-block\376\377\016\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\006\001-types\376\003\000\000\002\376B\000\000\023-consult-types-file\376\377\016\376\377\016"));
lf[380]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\015\001-explicit-use\376\003\000\000\002\376\001\000\000\011\001-no-trace\376\003\000\000\002\376\001\000\000\014\001-no-warnings\376\003\000\000\002\376\001\000\000\026\001-n"
"o-usual-integrations\376\003\000\000\002\376\001\000\000\027\001-optimize-leaf-routines\376\003\000\000\002\376\001\000\000\007\001-unsafe\376\003\000\000\002\376\001\000"
"\000\006\001-block\376\003\000\000\002\376\001\000\000\023\001-disable-interrupts\376\003\000\000\002\376\001\000\000\022\001-fixnum-arithmetic\376\003\000\000\002\376\001\000\000\012\001-"
"to-stdout\376\003\000\000\002\376\001\000\000\010\001-profile\376\003\000\000\002\376\001\000\000\004\001-raw\376\003\000\000\002\376\001\000\000\023\001-accumulate-profile\376\003\000\000\002\376\001"
"\000\000\015\001-check-syntax\376\003\000\000\002\376\001\000\000\021\001-case-insensitive\376\003\000\000\002\376\001\000\000\007\001-shared\376\003\000\000\002\376\001\000\000\017\001-compi"
"le-syntax\376\003\000\000\002\376\001\000\000\017\001-no-lambda-info\376\003\000\000\002\376\001\000\000\010\001-dynamic\376\003\000\000\002\376\001\000\000\036\001-disable-stack-"
"overflow-checks\376\003\000\000\002\376\001\000\000\006\001-local\376\003\000\000\002\376\001\000\000\037\001-emit-external-prototypes-first\376\003\000\000\002\376"
"\001\000\000\007\001-inline\376\003\000\000\002\376\001\000\000\010\001-release\376\003\000\000\002\376\001\000\000\015\001-analyze-only\376\003\000\000\002\376\001\000\000\025\001-keep-shadowed"
"-macros\376\003\000\000\002\376\001\000\000\016\001-inline-global\376\003\000\000\002\376\001\000\000\022\001-ignore-repository\376\003\000\000\002\376\001\000\000\021\001-no-symb"
"ol-escape\376\003\000\000\002\376\001\000\000\030\001-no-parentheses-synonyms\376\003\000\000\002\376\001\000\000\014\001-r5rs-syntax\376\003\000\000\002\376\001\000\000\017\001-n"
"o-argc-checks\376\003\000\000\002\376\001\000\000\020\001-no-bound-checks\376\003\000\000\002\376\001\000\000\024\001-no-procedure-checks\376\003\000\000\002\376\001\000\000"
"\023\001-no-compiler-syntax\376\003\000\000\002\376\001\000\000\032\001-emit-all-import-libraries\376\003\000\000\002\376\001\000\000\015\001-no-elevati"
"on\376\003\000\000\002\376\001\000\000\024\001-module-registration\376\003\000\000\002\376\001\000\000\027\001-no-module-registration\376\003\000\000\002\376\001\000\000\047\001-n"
"o-procedure-checks-for-usual-bindings\376\003\000\000\002\376\001\000\000\034\001-regenerate-import-libraries\376\003\000\000"
"\002\376\001\000\000\013\001-specialize\376\003\000\000\002\376\001\000\000\015\001-strict-types\376\003\000\000\002\376\001\000\000\013\001-clustering\376\003\000\000\002\376\001\000\000\005\001-lfa2"
"\376\003\000\000\002\376\001\000\000\013\001-debug-info\376\003\000\000\002\376\001\000\000\052\001-no-procedure-checks-for-toplevel-bindings\376\377\016"));
lf[381]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001-debug\376\003\000\000\002\376\001\000\000\012\001-heap-size\376\003\000\000\002\376\001\000\000\010\001-nursery\376\003\000\000\002\376\001\000\000\013\001-stack-size\376"
"\003\000\000\002\376\001\000\000\011\001-compiler\376\003\000\000\002\376\001\000\000\005\001-unit\376\003\000\000\002\376\001\000\000\005\001-uses\376\003\000\000\002\376\001\000\000\016\001-keyword-style\376\003\000\000"
"\002\376\001\000\000\017\001-optimize-level\376\003\000\000\002\376\001\000\000\015\001-include-path\376\003\000\000\002\376\001\000\000\016\001-database-size\376\003\000\000\002\376\001\000\000"
"\007\001-extend\376\003\000\000\002\376\001\000\000\010\001-prelude\376\003\000\000\002\376\001\000\000\011\001-postlude\376\003\000\000\002\376\001\000\000\011\001-prologue\376\003\000\000\002\376\001\000\000\011\001-"
"epilogue\376\003\000\000\002\376\001\000\000\017\001-emit-link-file\376\003\000\000\002\376\001\000\000\015\001-inline-limit\376\003\000\000\002\376\001\000\000\015\001-profile-na"
"me\376\003\000\000\002\376\001\000\000\015\001-unroll-limit\376\003\000\000\002\376\001\000\000\021\001-emit-inline-file\376\003\000\000\002\376\001\000\000\024\001-consult-inline"
"-file\376\003\000\000\002\376\001\000\000\020\001-emit-types-file\376\003\000\000\002\376\001\000\000\023\001-consult-types-file\376\003\000\000\002\376\001\000\000\010\001-featur"
"e\376\003\000\000\002\376\001\000\000\014\001-debug-level\376\003\000\000\002\376\001\000\000\024\001-emit-import-library\376\003\000\000\002\376\001\000\000\007\001-module\376\003\000\000\002\376\001"
"\000\000\005\001-link\376\003\000\000\002\376\001\000\000\013\001-no-feature\376\377\016"));
lf[382]=C_h_intern(&lf[382],18, C_text("chicken.base#error"));
lf[383]=C_decode_literal(C_heaptop,C_text("\376B\000\000-bad -L argument, <DIR> starts with whitespace"));
lf[384]=C_decode_literal(C_heaptop,C_text("\376B\000\000-bad -I argument: <DIR> starts with whitespace"));
lf[385]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-feature"));
lf[386]=C_h_intern(&lf[386],16, C_text("scheme#substring"));
lf[387]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001-"));
lf[388]=C_decode_literal(C_heaptop,C_text("\376B\000\0004invalid option `~A\047 - did you mean `-L -l<library>\047\077"));
lf[389]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023invalid option `~A\047"));
lf[390]=C_h_intern(&lf[390],5, C_text("foldr"));
lf[391]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023invalid option `~A\047"));
lf[392]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004-Wl,"));
lf[393]=C_h_intern(&lf[393],35, C_text("chicken.pathname#decompose-pathname"));
lf[394]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001h"));
lf[395]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001c"));
lf[396]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002rc"));
lf[397]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003cpp"));
lf[398]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001C"));
lf[399]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002cc"));
lf[400]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003cxx"));
lf[401]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003hpp"));
lf[402]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017-no-cpp-precomp"));
lf[403]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001m"));
lf[404]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001M"));
lf[405]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002mm"));
lf[406]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030file `~A\047 does not exist"));
lf[407]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004.scm"));
lf[408]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-:"));
lf[409]=C_h_intern(&lf[409],15, C_text("-optimize-level"));
lf[410]=C_h_intern(&lf[410],15, C_text("-benchmark-mode"));
lf[411]=C_h_intern(&lf[411],10, C_text("-to-stdout"));
lf[412]=C_h_intern(&lf[412],7, C_text("-shared"));
lf[413]=C_h_intern(&lf[413],8, C_text("-dynamic"));
lf[414]=C_h_intern(&lf[414],21, C_text("scheme#string->symbol"));
lf[415]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[416]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013CSC_OPTIONS"));
lf[417]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-I"));
lf[418]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002:;"));
lf[419]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026CHICKEN_C_INCLUDE_PATH"));
lf[420]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-I"));
lf[421]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030PHhsfiENxubvwAOeWkctgSJM"));
lf[422]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\005-DPIC\376\377\016"));
lf[423]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\005-fPIC\376\003\000\000\002\376B\000\000\005-DPIC\376\377\016"));
lf[424]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007static."));
lf[425]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007static."));
lf[426]=C_h_intern(&lf[426],25, C_text("chicken.platform#feature\077"));
lf[427]=C_h_intern_kw(&lf[427],13, C_text("cross-chicken"));
lf[428]=C_h_intern(&lf[428],46, C_text("chicken.process-context#command-line-arguments"));
lf[429]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017.cache-metadata"));
lf[430]=C_h_intern(&lf[430],41, C_text("chicken.process-context#current-directory"));
lf[431]=C_h_intern(&lf[431],39, C_text("chicken.platform#system-cache-directory"));
lf[432]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021CHICKEN_EGG_CACHE"));
lf[433]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011/chicken/"));
lf[434]=C_h_intern(&lf[434],20, C_text("##sys#fixnum->string"));
lf[435]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011/chicken/"));
lf[436]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[437]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[438]=C_h_intern(&lf[438],30, C_text("##sys#register-compiled-module"));
lf[439]=C_h_intern(&lf[439],4, C_text("main"));
lf[440]=C_h_intern(&lf[440],22, C_text("##sys#with-environment"));
C_register_lf2(lf,441,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2237,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[452] = {
{C_text("f8470:csc_2escm"),(void*)f8470},
{C_text("f8476:csc_2escm"),(void*)f8476},
{C_text("f8480:csc_2escm"),(void*)f8480},
{C_text("f8512:csc_2escm"),(void*)f8512},
{C_text("f8556:csc_2escm"),(void*)f8556},
{C_text("f_2237:csc_2escm"),(void*)f_2237},
{C_text("f_2240:csc_2escm"),(void*)f_2240},
{C_text("f_2243:csc_2escm"),(void*)f_2243},
{C_text("f_2246:csc_2escm"),(void*)f_2246},
{C_text("f_2249:csc_2escm"),(void*)f_2249},
{C_text("f_2252:csc_2escm"),(void*)f_2252},
{C_text("f_2255:csc_2escm"),(void*)f_2255},
{C_text("f_2258:csc_2escm"),(void*)f_2258},
{C_text("f_2264:csc_2escm"),(void*)f_2264},
{C_text("f_2270:csc_2escm"),(void*)f_2270},
{C_text("f_2274:csc_2escm"),(void*)f_2274},
{C_text("f_2278:csc_2escm"),(void*)f_2278},
{C_text("f_2282:csc_2escm"),(void*)f_2282},
{C_text("f_2286:csc_2escm"),(void*)f_2286},
{C_text("f_2290:csc_2escm"),(void*)f_2290},
{C_text("f_2294:csc_2escm"),(void*)f_2294},
{C_text("f_2298:csc_2escm"),(void*)f_2298},
{C_text("f_2302:csc_2escm"),(void*)f_2302},
{C_text("f_2306:csc_2escm"),(void*)f_2306},
{C_text("f_2310:csc_2escm"),(void*)f_2310},
{C_text("f_2314:csc_2escm"),(void*)f_2314},
{C_text("f_2318:csc_2escm"),(void*)f_2318},
{C_text("f_2322:csc_2escm"),(void*)f_2322},
{C_text("f_2326:csc_2escm"),(void*)f_2326},
{C_text("f_2334:csc_2escm"),(void*)f_2334},
{C_text("f_2338:csc_2escm"),(void*)f_2338},
{C_text("f_2342:csc_2escm"),(void*)f_2342},
{C_text("f_2346:csc_2escm"),(void*)f_2346},
{C_text("f_2350:csc_2escm"),(void*)f_2350},
{C_text("f_2354:csc_2escm"),(void*)f_2354},
{C_text("f_2358:csc_2escm"),(void*)f_2358},
{C_text("f_2362:csc_2escm"),(void*)f_2362},
{C_text("f_2366:csc_2escm"),(void*)f_2366},
{C_text("f_2370:csc_2escm"),(void*)f_2370},
{C_text("f_2374:csc_2escm"),(void*)f_2374},
{C_text("f_2378:csc_2escm"),(void*)f_2378},
{C_text("f_2382:csc_2escm"),(void*)f_2382},
{C_text("f_2386:csc_2escm"),(void*)f_2386},
{C_text("f_2390:csc_2escm"),(void*)f_2390},
{C_text("f_2394:csc_2escm"),(void*)f_2394},
{C_text("f_2398:csc_2escm"),(void*)f_2398},
{C_text("f_2402:csc_2escm"),(void*)f_2402},
{C_text("f_2406:csc_2escm"),(void*)f_2406},
{C_text("f_2410:csc_2escm"),(void*)f_2410},
{C_text("f_2494:csc_2escm"),(void*)f_2494},
{C_text("f_2497:csc_2escm"),(void*)f_2497},
{C_text("f_2501:csc_2escm"),(void*)f_2501},
{C_text("f_2939:csc_2escm"),(void*)f_2939},
{C_text("f_2945:csc_2escm"),(void*)f_2945},
{C_text("f_2959:csc_2escm"),(void*)f_2959},
{C_text("f_3001:csc_2escm"),(void*)f_3001},
{C_text("f_3028:csc_2escm"),(void*)f_3028},
{C_text("f_3076:csc_2escm"),(void*)f_3076},
{C_text("f_3090:csc_2escm"),(void*)f_3090},
{C_text("f_3103:csc_2escm"),(void*)f_3103},
{C_text("f_3124:csc_2escm"),(void*)f_3124},
{C_text("f_3132:csc_2escm"),(void*)f_3132},
{C_text("f_3153:csc_2escm"),(void*)f_3153},
{C_text("f_3168:csc_2escm"),(void*)f_3168},
{C_text("f_3180:csc_2escm"),(void*)f_3180},
{C_text("f_3184:csc_2escm"),(void*)f_3184},
{C_text("f_3202:csc_2escm"),(void*)f_3202},
{C_text("f_3281:csc_2escm"),(void*)f_3281},
{C_text("f_3381:csc_2escm"),(void*)f_3381},
{C_text("f_3403:csc_2escm"),(void*)f_3403},
{C_text("f_3414:csc_2escm"),(void*)f_3414},
{C_text("f_3786:csc_2escm"),(void*)f_3786},
{C_text("f_3812:csc_2escm"),(void*)f_3812},
{C_text("f_3818:csc_2escm"),(void*)f_3818},
{C_text("f_3821:csc_2escm"),(void*)f_3821},
{C_text("f_3828:csc_2escm"),(void*)f_3828},
{C_text("f_3831:csc_2escm"),(void*)f_3831},
{C_text("f_3834:csc_2escm"),(void*)f_3834},
{C_text("f_3837:csc_2escm"),(void*)f_3837},
{C_text("f_3844:csc_2escm"),(void*)f_3844},
{C_text("f_3848:csc_2escm"),(void*)f_3848},
{C_text("f_3852:csc_2escm"),(void*)f_3852},
{C_text("f_3870:csc_2escm"),(void*)f_3870},
{C_text("f_3878:csc_2escm"),(void*)f_3878},
{C_text("f_3882:csc_2escm"),(void*)f_3882},
{C_text("f_3884:csc_2escm"),(void*)f_3884},
{C_text("f_3892:csc_2escm"),(void*)f_3892},
{C_text("f_3900:csc_2escm"),(void*)f_3900},
{C_text("f_3904:csc_2escm"),(void*)f_3904},
{C_text("f_3908:csc_2escm"),(void*)f_3908},
{C_text("f_3912:csc_2escm"),(void*)f_3912},
{C_text("f_3916:csc_2escm"),(void*)f_3916},
{C_text("f_3920:csc_2escm"),(void*)f_3920},
{C_text("f_3933:csc_2escm"),(void*)f_3933},
{C_text("f_3937:csc_2escm"),(void*)f_3937},
{C_text("f_3942:csc_2escm"),(void*)f_3942},
{C_text("f_3945:csc_2escm"),(void*)f_3945},
{C_text("f_3953:csc_2escm"),(void*)f_3953},
{C_text("f_3988:csc_2escm"),(void*)f_3988},
{C_text("f_3992:csc_2escm"),(void*)f_3992},
{C_text("f_3997:csc_2escm"),(void*)f_3997},
{C_text("f_4002:csc_2escm"),(void*)f_4002},
{C_text("f_4009:csc_2escm"),(void*)f_4009},
{C_text("f_4039:csc_2escm"),(void*)f_4039},
{C_text("f_4053:csc_2escm"),(void*)f_4053},
{C_text("f_4057:csc_2escm"),(void*)f_4057},
{C_text("f_4073:csc_2escm"),(void*)f_4073},
{C_text("f_4092:csc_2escm"),(void*)f_4092},
{C_text("f_4111:csc_2escm"),(void*)f_4111},
{C_text("f_4115:csc_2escm"),(void*)f_4115},
{C_text("f_4119:csc_2escm"),(void*)f_4119},
{C_text("f_4122:csc_2escm"),(void*)f_4122},
{C_text("f_4135:csc_2escm"),(void*)f_4135},
{C_text("f_4140:csc_2escm"),(void*)f_4140},
{C_text("f_4165:csc_2escm"),(void*)f_4165},
{C_text("f_4185:csc_2escm"),(void*)f_4185},
{C_text("f_4193:csc_2escm"),(void*)f_4193},
{C_text("f_4197:csc_2escm"),(void*)f_4197},
{C_text("f_4201:csc_2escm"),(void*)f_4201},
{C_text("f_4217:csc_2escm"),(void*)f_4217},
{C_text("f_4224:csc_2escm"),(void*)f_4224},
{C_text("f_4234:csc_2escm"),(void*)f_4234},
{C_text("f_4246:csc_2escm"),(void*)f_4246},
{C_text("f_4250:csc_2escm"),(void*)f_4250},
{C_text("f_4253:csc_2escm"),(void*)f_4253},
{C_text("f_4256:csc_2escm"),(void*)f_4256},
{C_text("f_4259:csc_2escm"),(void*)f_4259},
{C_text("f_4262:csc_2escm"),(void*)f_4262},
{C_text("f_4268:csc_2escm"),(void*)f_4268},
{C_text("f_4274:csc_2escm"),(void*)f_4274},
{C_text("f_4286:csc_2escm"),(void*)f_4286},
{C_text("f_4296:csc_2escm"),(void*)f_4296},
{C_text("f_4300:csc_2escm"),(void*)f_4300},
{C_text("f_4306:csc_2escm"),(void*)f_4306},
{C_text("f_4318:csc_2escm"),(void*)f_4318},
{C_text("f_4325:csc_2escm"),(void*)f_4325},
{C_text("f_4358:csc_2escm"),(void*)f_4358},
{C_text("f_4363:csc_2escm"),(void*)f_4363},
{C_text("f_4365:csc_2escm"),(void*)f_4365},
{C_text("f_4391:csc_2escm"),(void*)f_4391},
{C_text("f_4396:csc_2escm"),(void*)f_4396},
{C_text("f_4400:csc_2escm"),(void*)f_4400},
{C_text("f_4404:csc_2escm"),(void*)f_4404},
{C_text("f_4421:csc_2escm"),(void*)f_4421},
{C_text("f_4437:csc_2escm"),(void*)f_4437},
{C_text("f_4448:csc_2escm"),(void*)f_4448},
{C_text("f_4452:csc_2escm"),(void*)f_4452},
{C_text("f_4455:csc_2escm"),(void*)f_4455},
{C_text("f_4458:csc_2escm"),(void*)f_4458},
{C_text("f_4461:csc_2escm"),(void*)f_4461},
{C_text("f_4467:csc_2escm"),(void*)f_4467},
{C_text("f_4473:csc_2escm"),(void*)f_4473},
{C_text("f_4476:csc_2escm"),(void*)f_4476},
{C_text("f_4488:csc_2escm"),(void*)f_4488},
{C_text("f_4491:csc_2escm"),(void*)f_4491},
{C_text("f_4494:csc_2escm"),(void*)f_4494},
{C_text("f_4497:csc_2escm"),(void*)f_4497},
{C_text("f_4500:csc_2escm"),(void*)f_4500},
{C_text("f_4503:csc_2escm"),(void*)f_4503},
{C_text("f_4510:csc_2escm"),(void*)f_4510},
{C_text("f_4516:csc_2escm"),(void*)f_4516},
{C_text("f_4519:csc_2escm"),(void*)f_4519},
{C_text("f_4522:csc_2escm"),(void*)f_4522},
{C_text("f_4525:csc_2escm"),(void*)f_4525},
{C_text("f_4528:csc_2escm"),(void*)f_4528},
{C_text("f_4531:csc_2escm"),(void*)f_4531},
{C_text("f_4538:csc_2escm"),(void*)f_4538},
{C_text("f_4542:csc_2escm"),(void*)f_4542},
{C_text("f_4560:csc_2escm"),(void*)f_4560},
{C_text("f_4564:csc_2escm"),(void*)f_4564},
{C_text("f_4570:csc_2escm"),(void*)f_4570},
{C_text("f_4577:csc_2escm"),(void*)f_4577},
{C_text("f_4594:csc_2escm"),(void*)f_4594},
{C_text("f_4604:csc_2escm"),(void*)f_4604},
{C_text("f_4608:csc_2escm"),(void*)f_4608},
{C_text("f_4617:csc_2escm"),(void*)f_4617},
{C_text("f_4620:csc_2escm"),(void*)f_4620},
{C_text("f_4627:csc_2escm"),(void*)f_4627},
{C_text("f_4660:csc_2escm"),(void*)f_4660},
{C_text("f_4663:csc_2escm"),(void*)f_4663},
{C_text("f_4666:csc_2escm"),(void*)f_4666},
{C_text("f_4669:csc_2escm"),(void*)f_4669},
{C_text("f_4679:csc_2escm"),(void*)f_4679},
{C_text("f_4686:csc_2escm"),(void*)f_4686},
{C_text("f_4693:csc_2escm"),(void*)f_4693},
{C_text("f_4697:csc_2escm"),(void*)f_4697},
{C_text("f_4704:csc_2escm"),(void*)f_4704},
{C_text("f_4707:csc_2escm"),(void*)f_4707},
{C_text("f_4719:csc_2escm"),(void*)f_4719},
{C_text("f_4731:csc_2escm"),(void*)f_4731},
{C_text("f_4738:csc_2escm"),(void*)f_4738},
{C_text("f_4747:csc_2escm"),(void*)f_4747},
{C_text("f_4754:csc_2escm"),(void*)f_4754},
{C_text("f_4760:csc_2escm"),(void*)f_4760},
{C_text("f_4763:csc_2escm"),(void*)f_4763},
{C_text("f_4766:csc_2escm"),(void*)f_4766},
{C_text("f_4769:csc_2escm"),(void*)f_4769},
{C_text("f_4826:csc_2escm"),(void*)f_4826},
{C_text("f_4838:csc_2escm"),(void*)f_4838},
{C_text("f_4850:csc_2escm"),(void*)f_4850},
{C_text("f_4862:csc_2escm"),(void*)f_4862},
{C_text("f_4885:csc_2escm"),(void*)f_4885},
{C_text("f_4888:csc_2escm"),(void*)f_4888},
{C_text("f_4900:csc_2escm"),(void*)f_4900},
{C_text("f_4990:csc_2escm"),(void*)f_4990},
{C_text("f_4993:csc_2escm"),(void*)f_4993},
{C_text("f_4997:csc_2escm"),(void*)f_4997},
{C_text("f_5005:csc_2escm"),(void*)f_5005},
{C_text("f_5022:csc_2escm"),(void*)f_5022},
{C_text("f_5042:csc_2escm"),(void*)f_5042},
{C_text("f_5045:csc_2escm"),(void*)f_5045},
{C_text("f_5111:csc_2escm"),(void*)f_5111},
{C_text("f_5115:csc_2escm"),(void*)f_5115},
{C_text("f_5131:csc_2escm"),(void*)f_5131},
{C_text("f_5142:csc_2escm"),(void*)f_5142},
{C_text("f_5158:csc_2escm"),(void*)f_5158},
{C_text("f_5179:csc_2escm"),(void*)f_5179},
{C_text("f_5189:csc_2escm"),(void*)f_5189},
{C_text("f_5199:csc_2escm"),(void*)f_5199},
{C_text("f_5209:csc_2escm"),(void*)f_5209},
{C_text("f_5219:csc_2escm"),(void*)f_5219},
{C_text("f_5229:csc_2escm"),(void*)f_5229},
{C_text("f_5239:csc_2escm"),(void*)f_5239},
{C_text("f_5249:csc_2escm"),(void*)f_5249},
{C_text("f_5259:csc_2escm"),(void*)f_5259},
{C_text("f_5269:csc_2escm"),(void*)f_5269},
{C_text("f_5278:csc_2escm"),(void*)f_5278},
{C_text("f_5281:csc_2escm"),(void*)f_5281},
{C_text("f_5293:csc_2escm"),(void*)f_5293},
{C_text("f_5320:csc_2escm"),(void*)f_5320},
{C_text("f_5344:csc_2escm"),(void*)f_5344},
{C_text("f_5361:csc_2escm"),(void*)f_5361},
{C_text("f_5378:csc_2escm"),(void*)f_5378},
{C_text("f_5395:csc_2escm"),(void*)f_5395},
{C_text("f_5412:csc_2escm"),(void*)f_5412},
{C_text("f_5416:csc_2escm"),(void*)f_5416},
{C_text("f_5433:csc_2escm"),(void*)f_5433},
{C_text("f_5437:csc_2escm"),(void*)f_5437},
{C_text("f_5445:csc_2escm"),(void*)f_5445},
{C_text("f_5459:csc_2escm"),(void*)f_5459},
{C_text("f_5472:csc_2escm"),(void*)f_5472},
{C_text("f_5476:csc_2escm"),(void*)f_5476},
{C_text("f_5484:csc_2escm"),(void*)f_5484},
{C_text("f_5497:csc_2escm"),(void*)f_5497},
{C_text("f_5511:csc_2escm"),(void*)f_5511},
{C_text("f_5515:csc_2escm"),(void*)f_5515},
{C_text("f_5523:csc_2escm"),(void*)f_5523},
{C_text("f_5527:csc_2escm"),(void*)f_5527},
{C_text("f_5552:csc_2escm"),(void*)f_5552},
{C_text("f_5555:csc_2escm"),(void*)f_5555},
{C_text("f_5572:csc_2escm"),(void*)f_5572},
{C_text("f_5575:csc_2escm"),(void*)f_5575},
{C_text("f_5593:csc_2escm"),(void*)f_5593},
{C_text("f_5600:csc_2escm"),(void*)f_5600},
{C_text("f_5603:csc_2escm"),(void*)f_5603},
{C_text("f_5606:csc_2escm"),(void*)f_5606},
{C_text("f_5613:csc_2escm"),(void*)f_5613},
{C_text("f_5643:csc_2escm"),(void*)f_5643},
{C_text("f_5646:csc_2escm"),(void*)f_5646},
{C_text("f_5660:csc_2escm"),(void*)f_5660},
{C_text("f_5679:csc_2escm"),(void*)f_5679},
{C_text("f_5683:csc_2escm"),(void*)f_5683},
{C_text("f_5706:csc_2escm"),(void*)f_5706},
{C_text("f_5710:csc_2escm"),(void*)f_5710},
{C_text("f_5737:csc_2escm"),(void*)f_5737},
{C_text("f_5751:csc_2escm"),(void*)f_5751},
{C_text("f_5761:csc_2escm"),(void*)f_5761},
{C_text("f_5765:csc_2escm"),(void*)f_5765},
{C_text("f_5788:csc_2escm"),(void*)f_5788},
{C_text("f_5805:csc_2escm"),(void*)f_5805},
{C_text("f_5807:csc_2escm"),(void*)f_5807},
{C_text("f_5832:csc_2escm"),(void*)f_5832},
{C_text("f_5859:csc_2escm"),(void*)f_5859},
{C_text("f_5863:csc_2escm"),(void*)f_5863},
{C_text("f_5880:csc_2escm"),(void*)f_5880},
{C_text("f_5892:csc_2escm"),(void*)f_5892},
{C_text("f_5897:csc_2escm"),(void*)f_5897},
{C_text("f_5903:csc_2escm"),(void*)f_5903},
{C_text("f_5914:csc_2escm"),(void*)f_5914},
{C_text("f_5928:csc_2escm"),(void*)f_5928},
{C_text("f_5942:csc_2escm"),(void*)f_5942},
{C_text("f_5955:csc_2escm"),(void*)f_5955},
{C_text("f_5960:csc_2escm"),(void*)f_5960},
{C_text("f_5979:csc_2escm"),(void*)f_5979},
{C_text("f_5991:csc_2escm"),(void*)f_5991},
{C_text("f_5995:csc_2escm"),(void*)f_5995},
{C_text("f_6003:csc_2escm"),(void*)f_6003},
{C_text("f_6012:csc_2escm"),(void*)f_6012},
{C_text("f_6018:csc_2escm"),(void*)f_6018},
{C_text("f_6048:csc_2escm"),(void*)f_6048},
{C_text("f_6255:csc_2escm"),(void*)f_6255},
{C_text("f_6258:csc_2escm"),(void*)f_6258},
{C_text("f_6261:csc_2escm"),(void*)f_6261},
{C_text("f_6264:csc_2escm"),(void*)f_6264},
{C_text("f_6268:csc_2escm"),(void*)f_6268},
{C_text("f_6272:csc_2escm"),(void*)f_6272},
{C_text("f_6291:csc_2escm"),(void*)f_6291},
{C_text("f_6295:csc_2escm"),(void*)f_6295},
{C_text("f_6299:csc_2escm"),(void*)f_6299},
{C_text("f_6303:csc_2escm"),(void*)f_6303},
{C_text("f_6307:csc_2escm"),(void*)f_6307},
{C_text("f_6311:csc_2escm"),(void*)f_6311},
{C_text("f_6322:csc_2escm"),(void*)f_6322},
{C_text("f_6328:csc_2escm"),(void*)f_6328},
{C_text("f_6330:csc_2escm"),(void*)f_6330},
{C_text("f_6355:csc_2escm"),(void*)f_6355},
{C_text("f_6366:csc_2escm"),(void*)f_6366},
{C_text("f_6383:csc_2escm"),(void*)f_6383},
{C_text("f_6397:csc_2escm"),(void*)f_6397},
{C_text("f_6426:csc_2escm"),(void*)f_6426},
{C_text("f_6451:csc_2escm"),(void*)f_6451},
{C_text("f_6455:csc_2escm"),(void*)f_6455},
{C_text("f_6458:csc_2escm"),(void*)f_6458},
{C_text("f_6461:csc_2escm"),(void*)f_6461},
{C_text("f_6473:csc_2escm"),(void*)f_6473},
{C_text("f_6485:csc_2escm"),(void*)f_6485},
{C_text("f_6489:csc_2escm"),(void*)f_6489},
{C_text("f_6493:csc_2escm"),(void*)f_6493},
{C_text("f_6497:csc_2escm"),(void*)f_6497},
{C_text("f_6508:csc_2escm"),(void*)f_6508},
{C_text("f_6537:csc_2escm"),(void*)f_6537},
{C_text("f_6540:csc_2escm"),(void*)f_6540},
{C_text("f_6541:csc_2escm"),(void*)f_6541},
{C_text("f_6545:csc_2escm"),(void*)f_6545},
{C_text("f_6548:csc_2escm"),(void*)f_6548},
{C_text("f_6560:csc_2escm"),(void*)f_6560},
{C_text("f_6568:csc_2escm"),(void*)f_6568},
{C_text("f_6572:csc_2escm"),(void*)f_6572},
{C_text("f_6578:csc_2escm"),(void*)f_6578},
{C_text("f_6582:csc_2escm"),(void*)f_6582},
{C_text("f_6591:csc_2escm"),(void*)f_6591},
{C_text("f_6599:csc_2escm"),(void*)f_6599},
{C_text("f_6609:csc_2escm"),(void*)f_6609},
{C_text("f_6622:csc_2escm"),(void*)f_6622},
{C_text("f_6632:csc_2escm"),(void*)f_6632},
{C_text("f_6647:csc_2escm"),(void*)f_6647},
{C_text("f_6649:csc_2escm"),(void*)f_6649},
{C_text("f_6659:csc_2escm"),(void*)f_6659},
{C_text("f_6673:csc_2escm"),(void*)f_6673},
{C_text("f_6676:csc_2escm"),(void*)f_6676},
{C_text("f_6679:csc_2escm"),(void*)f_6679},
{C_text("f_6691:csc_2escm"),(void*)f_6691},
{C_text("f_6698:csc_2escm"),(void*)f_6698},
{C_text("f_6700:csc_2escm"),(void*)f_6700},
{C_text("f_6710:csc_2escm"),(void*)f_6710},
{C_text("f_6723:csc_2escm"),(void*)f_6723},
{C_text("f_6734:csc_2escm"),(void*)f_6734},
{C_text("f_6740:csc_2escm"),(void*)f_6740},
{C_text("f_6742:csc_2escm"),(void*)f_6742},
{C_text("f_6767:csc_2escm"),(void*)f_6767},
{C_text("f_6781:csc_2escm"),(void*)f_6781},
{C_text("f_6790:csc_2escm"),(void*)f_6790},
{C_text("f_6793:csc_2escm"),(void*)f_6793},
{C_text("f_6796:csc_2escm"),(void*)f_6796},
{C_text("f_6799:csc_2escm"),(void*)f_6799},
{C_text("f_6805:csc_2escm"),(void*)f_6805},
{C_text("f_6813:csc_2escm"),(void*)f_6813},
{C_text("f_6823:csc_2escm"),(void*)f_6823},
{C_text("f_6844:csc_2escm"),(void*)f_6844},
{C_text("f_6848:csc_2escm"),(void*)f_6848},
{C_text("f_6852:csc_2escm"),(void*)f_6852},
{C_text("f_6856:csc_2escm"),(void*)f_6856},
{C_text("f_6860:csc_2escm"),(void*)f_6860},
{C_text("f_6863:csc_2escm"),(void*)f_6863},
{C_text("f_6873:csc_2escm"),(void*)f_6873},
{C_text("f_6880:csc_2escm"),(void*)f_6880},
{C_text("f_6885:csc_2escm"),(void*)f_6885},
{C_text("f_6889:csc_2escm"),(void*)f_6889},
{C_text("f_6897:csc_2escm"),(void*)f_6897},
{C_text("f_6905:csc_2escm"),(void*)f_6905},
{C_text("f_6909:csc_2escm"),(void*)f_6909},
{C_text("f_6913:csc_2escm"),(void*)f_6913},
{C_text("f_6918:csc_2escm"),(void*)f_6918},
{C_text("f_6920:csc_2escm"),(void*)f_6920},
{C_text("f_6945:csc_2escm"),(void*)f_6945},
{C_text("f_6961:csc_2escm"),(void*)f_6961},
{C_text("f_6964:csc_2escm"),(void*)f_6964},
{C_text("f_6971:csc_2escm"),(void*)f_6971},
{C_text("f_6985:csc_2escm"),(void*)f_6985},
{C_text("f_7000:csc_2escm"),(void*)f_7000},
{C_text("f_7008:csc_2escm"),(void*)f_7008},
{C_text("f_7018:csc_2escm"),(void*)f_7018},
{C_text("f_7033:csc_2escm"),(void*)f_7033},
{C_text("f_7042:csc_2escm"),(void*)f_7042},
{C_text("f_7067:csc_2escm"),(void*)f_7067},
{C_text("f_7079:csc_2escm"),(void*)f_7079},
{C_text("f_7093:csc_2escm"),(void*)f_7093},
{C_text("f_7099:csc_2escm"),(void*)f_7099},
{C_text("f_7102:csc_2escm"),(void*)f_7102},
{C_text("f_7105:csc_2escm"),(void*)f_7105},
{C_text("f_7112:csc_2escm"),(void*)f_7112},
{C_text("f_7116:csc_2escm"),(void*)f_7116},
{C_text("f_7125:csc_2escm"),(void*)f_7125},
{C_text("f_7204:csc_2escm"),(void*)f_7204},
{C_text("f_7215:csc_2escm"),(void*)f_7215},
{C_text("f_7221:csc_2escm"),(void*)f_7221},
{C_text("f_7223:csc_2escm"),(void*)f_7223},
{C_text("f_7248:csc_2escm"),(void*)f_7248},
{C_text("f_7257:csc_2escm"),(void*)f_7257},
{C_text("f_7265:csc_2escm"),(void*)f_7265},
{C_text("f_7327:csc_2escm"),(void*)f_7327},
{C_text("f_7330:csc_2escm"),(void*)f_7330},
{C_text("f_7333:csc_2escm"),(void*)f_7333},
{C_text("f_7336:csc_2escm"),(void*)f_7336},
{C_text("f_7353:csc_2escm"),(void*)f_7353},
{C_text("f_7356:csc_2escm"),(void*)f_7356},
{C_text("f_7359:csc_2escm"),(void*)f_7359},
{C_text("f_7362:csc_2escm"),(void*)f_7362},
{C_text("f_7378:csc_2escm"),(void*)f_7378},
{C_text("f_7382:csc_2escm"),(void*)f_7382},
{C_text("f_7390:csc_2escm"),(void*)f_7390},
{C_text("f_7398:csc_2escm"),(void*)f_7398},
{C_text("f_7411:csc_2escm"),(void*)f_7411},
{C_text("f_7415:csc_2escm"),(void*)f_7415},
{C_text("f_7430:csc_2escm"),(void*)f_7430},
{C_text("f_7435:csc_2escm"),(void*)f_7435},
{C_text("f_7443:csc_2escm"),(void*)f_7443},
{C_text("f_7461:csc_2escm"),(void*)f_7461},
{C_text("f_7467:csc_2escm"),(void*)f_7467},
{C_text("f_7471:csc_2escm"),(void*)f_7471},
{C_text("f_7475:csc_2escm"),(void*)f_7475},
{C_text("f_7479:csc_2escm"),(void*)f_7479},
{C_text("f_7486:csc_2escm"),(void*)f_7486},
{C_text("f_7490:csc_2escm"),(void*)f_7490},
{C_text("f_7493:csc_2escm"),(void*)f_7493},
{C_text("f_7509:csc_2escm"),(void*)f_7509},
{C_text("f_7512:csc_2escm"),(void*)f_7512},
{C_text("f_7520:csc_2escm"),(void*)f_7520},
{C_text("f_7545:csc_2escm"),(void*)f_7545},
{C_text("f_7554:csc_2escm"),(void*)f_7554},
{C_text("f_7579:csc_2escm"),(void*)f_7579},
{C_text("f_7596:csc_2escm"),(void*)f_7596},
{C_text("f_7616:csc_2escm"),(void*)f_7616},
{C_text("f_7620:csc_2escm"),(void*)f_7620},
{C_text("f_7645:csc_2escm"),(void*)f_7645},
{C_text("f_7663:csc_2escm"),(void*)f_7663},
{C_text("f_7667:csc_2escm"),(void*)f_7667},
{C_text("f_7674:csc_2escm"),(void*)f_7674},
{C_text("f_7678:csc_2escm"),(void*)f_7678},
{C_text("f_7682:csc_2escm"),(void*)f_7682},
{C_text("f_7686:csc_2escm"),(void*)f_7686},
{C_text("f_7697:csc_2escm"),(void*)f_7697},
{C_text("f_7700:csc_2escm"),(void*)f_7700},
{C_text("f_7707:csc_2escm"),(void*)f_7707},
{C_text("f_7712:csc_2escm"),(void*)f_7712},
{C_text("f_7717:csc_2escm"),(void*)f_7717},
{C_text("f_7721:csc_2escm"),(void*)f_7721},
{C_text("f_7725:csc_2escm"),(void*)f_7725},
{C_text("f_7732:csc_2escm"),(void*)f_7732},
{C_text("f_7734:csc_2escm"),(void*)f_7734},
{C_text("toplevel:csc_2escm"),(void*)C_toplevel},
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
o|hiding unexported module binding: main#host-libs 
o|hiding unexported module binding: main#TARGET_CC 
o|hiding unexported module binding: main#windows 
o|hiding unexported module binding: main#mingw 
o|hiding unexported module binding: main#osx 
o|hiding unexported module binding: main#cygwin 
o|hiding unexported module binding: main#aix 
o|hiding unexported module binding: main#solaris 
o|hiding unexported module binding: main#elf 
o|hiding unexported module binding: main#stop 
o|hiding unexported module binding: main#arguments 
o|hiding unexported module binding: main#cross-chicken 
o|hiding unexported module binding: main#host-mode 
o|hiding unexported module binding: main#back-slash->forward-slash 
o|hiding unexported module binding: main#quotewrap 
o|hiding unexported module binding: main#quotewrap-no-slash-trans 
o|hiding unexported module binding: main#home 
o|hiding unexported module binding: main#translator 
o|hiding unexported module binding: main#compiler 
o|hiding unexported module binding: main#c++-compiler 
o|hiding unexported module binding: main#rc-compiler 
o|hiding unexported module binding: main#linker 
o|hiding unexported module binding: main#c++-linker 
o|hiding unexported module binding: main#object-extension 
o|hiding unexported module binding: main#library-extension 
o|hiding unexported module binding: main#link-output-flag 
o|hiding unexported module binding: main#executable-extension 
o|hiding unexported module binding: main#compile-output-flag 
o|hiding unexported module binding: main#shared-library-extension 
o|hiding unexported module binding: main#static-object-extension 
o|hiding unexported module binding: main#static-library-extension 
o|hiding unexported module binding: main#default-translation-optimization-options 
o|hiding unexported module binding: main#pic-options 
o|hiding unexported module binding: main#generate-manifest 
o|hiding unexported module binding: main#libchicken 
o|hiding unexported module binding: main#dynamic-libchicken 
o|hiding unexported module binding: main#default-library 
o|hiding unexported module binding: main#default-compilation-optimization-options 
o|hiding unexported module binding: main#best-compilation-optimization-options 
o|hiding unexported module binding: main#default-linking-optimization-options 
o|hiding unexported module binding: main#best-linking-optimization-options 
o|hiding unexported module binding: main#extra-features 
o|hiding unexported module binding: main#constant831 
o|hiding unexported module binding: main#constant834 
o|hiding unexported module binding: main#constant838 
o|hiding unexported module binding: main#short-options 
o|hiding unexported module binding: main#scheme-files 
o|hiding unexported module binding: main#c-files 
o|hiding unexported module binding: main#rc-files 
o|hiding unexported module binding: main#generated-c-files 
o|hiding unexported module binding: main#generated-rc-files 
o|hiding unexported module binding: main#object-files 
o|hiding unexported module binding: main#generated-object-files 
o|hiding unexported module binding: main#transient-link-files 
o|hiding unexported module binding: main#linked-extensions 
o|hiding unexported module binding: main#cpp-mode 
o|hiding unexported module binding: main#objc-mode 
o|hiding unexported module binding: main#embedded 
o|hiding unexported module binding: main#inquiry-only 
o|hiding unexported module binding: main#show-cflags 
o|hiding unexported module binding: main#show-ldflags 
o|hiding unexported module binding: main#show-libs 
o|hiding unexported module binding: main#dry-run 
o|hiding unexported module binding: main#gui 
o|hiding unexported module binding: main#deployed 
o|hiding unexported module binding: main#rpath 
o|hiding unexported module binding: main#ignore-repository 
o|hiding unexported module binding: main#show-debugging-help 
o|hiding unexported module binding: main#library-dir 
o|hiding unexported module binding: main#extra-libraries 
o|hiding unexported module binding: main#extra-shared-libraries 
o|hiding unexported module binding: main#default-library-files 
o|hiding unexported module binding: main#library-files 
o|hiding unexported module binding: main#shared-library-files 
o|hiding unexported module binding: main#translate-options 
o|hiding unexported module binding: main#include-dir 
o|hiding unexported module binding: main#compile-options 
o|hiding unexported module binding: main#builtin-compile-options 
o|hiding unexported module binding: main#compile-only-flag 
o|hiding unexported module binding: main#translation-optimization-options 
o|hiding unexported module binding: main#compilation-optimization-options 
o|hiding unexported module binding: main#linking-optimization-options 
o|hiding unexported module binding: main#link-options 
o|hiding unexported module binding: main#rpath-option 
o|hiding unexported module binding: main#builtin-link-options 
o|hiding unexported module binding: main#target-filename 
o|hiding unexported module binding: main#verbose 
o|hiding unexported module binding: main#keep-files 
o|hiding unexported module binding: main#translate-only 
o|hiding unexported module binding: main#compile-only 
o|hiding unexported module binding: main#to-stdout 
o|hiding unexported module binding: main#shared 
o|hiding unexported module binding: main#static 
o|hiding unexported module binding: main#repo-path 
o|hiding unexported module binding: main#find-object-file 
o|hiding unexported module binding: main#usage 
o|hiding unexported module binding: main#run 
o|hiding unexported module binding: main#run-translation 
o|hiding unexported module binding: main#run-compilation 
o|hiding unexported module binding: main#compiler-options 
o|hiding unexported module binding: main#run-linking 
o|hiding unexported module binding: main#collect-linked-objects 
o|hiding unexported module binding: main#copy-files 
o|hiding unexported module binding: main#linker-options 
o|hiding unexported module binding: main#linker-libraries 
o|hiding unexported module binding: main#string-any 
o|hiding unexported module binding: main#quote-option 
o|hiding unexported module binding: main#last-exit-code 
o|hiding unexported module binding: main#$system 
o|hiding unexported module binding: main#command 
o|hiding unexported module binding: main#$delete-file 
o|hiding unexported module binding: main#create-win-manifest 
S|applied compiler syntax:
S|  chicken.format#printf		1
S|  scheme#for-each		6
S|  chicken.format#sprintf		3
S|  chicken.format#fprintf		2
S|  chicken.base#foldl		3
S|  scheme#map		13
S|  chicken.base#foldr		3
o|eliminated procedure checks: 149 
o|specializations:
o|  1 (scheme#zero? *)
o|  2 (scheme#zero? integer)
o|  1 (scheme#= integer integer)
o|  1 (##sys#debug-mode?)
o|  2 (scheme#= fixnum fixnum)
o|  5 (scheme#string-append string string)
o|  5 (scheme#char=? char char)
o|  7 (scheme#string-ref string fixnum)
o|  4 (scheme#string=? string string)
o|  4 (scheme#> fixnum fixnum)
o|  4 (scheme#string-length string)
o|  1 (scheme#memv (or symbol keyword procedure eof null fixnum char boolean) list)
o|  71 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#> integer integer)
o|  2 (scheme#+ fixnum fixnum)
o|  6 (##sys#check-output-port * * *)
o|  2 (chicken.base#current-error-port)
o|  5 (scheme#memq * list)
o|  1 (scheme#eqv? * *)
o|  6 (##sys#check-list (or pair list) *)
o|  24 (scheme#cdr pair)
o|  8 (scheme#car pair)
o|  2 (scheme#number->string fixnum)
(o e)|safe calls: 804 
(o e)|assignments to immediate values: 25 
o|removed side-effect free assignment to unused variable: main#default-install-program 
o|removed side-effect free assignment to unused variable: main#default-ldflags 
o|removed side-effect free assignment to unused variable: main#default-install-program-executable-flags 
o|removed side-effect free assignment to unused variable: main#default-install-program-data-flags 
o|removed side-effect free assignment to unused variable: main#default-slibdir 
o|removed side-effect free assignment to unused variable: main#default-platform 
o|removed side-effect free assignment to unused variable: main#default-prefix 
o|removed side-effect free assignment to unused variable: main#default-csc 
o|removed side-effect free assignment to unused variable: main#default-csi 
o|removed side-effect free assignment to unused variable: main#default-builder 
o|removed side-effect free assignment to unused variable: main#target-librarian 
o|removed side-effect free assignment to unused variable: main#target-librarian-options 
o|removed side-effect free assignment to unused variable: main#host-prefix 
o|removed side-effect free assignment to unused variable: main#host-ldflags 
o|removed side-effect free assignment to unused variable: main#+egg-info-extension+ 
o|removed side-effect free assignment to unused variable: main#+egg-extension+ 
o|removed side-effect free assignment to unused variable: main#validate-environment 
o|removed side-effect free assignment to unused variable: main#probe-dir 
o|removed side-effect free assignment to unused variable: main#cache-metadata-directory 
o|removed side-effect free assignment to unused variable: main#+version-file+ 
o|removed side-effect free assignment to unused variable: main#+timestamp-file+ 
o|removed side-effect free assignment to unused variable: main#+status-file+ 
o|removed side-effect free assignment to unused variable: main#partition 
o|removed side-effect free assignment to unused variable: main#span 
o|removed side-effect free assignment to unused variable: main#drop 
o|removed side-effect free assignment to unused variable: main#split-at 
o|removed side-effect free assignment to unused variable: main#append-map 
o|inlining procedure: k2886 
o|inlining procedure: k2886 
o|inlining procedure: k2917 
o|inlining procedure: k2917 
o|merged explicitly consed rest parameter: xs429 
o|inlining procedure: k2947 
o|inlining procedure: k2947 
o|removed side-effect free assignment to unused variable: main#concatenate 
o|removed side-effect free assignment to unused variable: main#second 
o|removed side-effect free assignment to unused variable: main#third 
o|removed side-effect free assignment to unused variable: main#fourth 
o|removed side-effect free assignment to unused variable: main#fifth 
o|removed side-effect free assignment to unused variable: main#alist-cons 
o|inlining procedure: k3134 
o|inlining procedure: k3134 
o|inlining procedure: k3126 
o|inlining procedure: k3126 
o|removed side-effect free assignment to unused variable: main#remove 
o|removed side-effect free assignment to unused variable: main#unzip1 
o|removed side-effect free assignment to unused variable: main#list-index 
o|removed side-effect free assignment to unused variable: main#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: main#lset-union/eq? 
o|removed side-effect free assignment to unused variable: main#lset-intersection/eq? 
o|inlining procedure: k3525 
o|inlining procedure: k3525 
o|removed side-effect free assignment to unused variable: main#lset<=/eq? 
o|removed side-effect free assignment to unused variable: main#lset=/eq? 
o|removed side-effect free assignment to unused variable: main#length+ 
o|removed side-effect free assignment to unused variable: main#find 
o|removed side-effect free assignment to unused variable: main#find-tail 
o|removed side-effect free assignment to unused variable: main#iota 
o|removed side-effect free assignment to unused variable: main#make-list 
o|removed side-effect free assignment to unused variable: main#posq 
o|removed side-effect free assignment to unused variable: main#posv 
o|removed side-effect free assignment to unused variable: main#TARGET_CC 
o|removed side-effect free assignment to unused variable: main#windows 
o|substituted constant variable: a3813 
o|substituted constant variable: a3819 
o|merged explicitly consed rest parameter: args780 
o|propagated global variable: out781784 ##sys#standard-error 
o|substituted constant variable: a3824 
o|substituted constant variable: a3825 
o|contracted procedure: "(csc.scm:90) main#back-slash->forward-slash" 
o|inlining procedure: k3863 
o|inlining procedure: k3863 
o|inlining procedure: k3951 
o|inlining procedure: k3951 
o|removed side-effect free assignment to unused variable: main#dynamic-libchicken 
o|removed side-effect free assignment to unused variable: main#gui 
o|substituted constant variable: main#default-translation-optimization-options 
o|inlining procedure: k4236 
o|inlining procedure: k4236 
o|contracted procedure: "(csc.scm:300) main#destination-repository" 
o|inlining procedure: k2458 
o|inlining procedure: k2458 
o|inlining procedure: k4263 
o|inlining procedure: k4263 
o|inlining procedure: k4275 
o|inlining procedure: k4275 
o|inlining procedure: k4287 
o|inlining procedure: k4287 
o|inlining procedure: k4307 
o|inlining procedure: k4307 
o|inlining procedure: k6744 
o|inlining procedure: k6744 
o|removed side-effect free assignment to unused variable: main#copy-files 
o|inlining procedure: k7225 
o|inlining procedure: k7225 
o|inlining procedure: k7271 
o|inlining procedure: k7271 
o|contracted procedure: "(csc.scm:1048) main#library-files" 
o|contracted procedure: "(csc.scm:234) main#default-library" 
o|contracted procedure: "(csc.scm:1049) main#shared-library-files" 
o|contracted procedure: "(csc.scm:235) main#default-library-files" 
o|inlining procedure: k4055 
o|inlining procedure: k4055 
o|removed side-effect free assignment to unused variable: main#string-any 
o|inlining procedure: k7400 
o|inlining procedure: k7400 
o|contracted procedure: "(csc.scm:1088) main#$system" 
o|inlining procedure: k7338 
o|inlining procedure: k7338 
o|propagated global variable: out17181721 ##sys#standard-output 
o|substituted constant variable: a7349 
o|substituted constant variable: a7350 
o|propagated global variable: out17181721 ##sys#standard-output 
o|inlining procedure: k7379 
o|inlining procedure: k7379 
o|inlining procedure: k7416 
o|inlining procedure: k7416 
o|contracted procedure: "(csc.scm:1121) main#run" 
o|merged explicitly consed rest parameter: os1039 
o|merged explicitly consed rest parameter: n1042 
o|inlining procedure: k4367 
o|inlining procedure: k4367 
o|consed rest parameter at call site: "(csc.scm:541) main#stop" 2 
o|inlining procedure: k4381 
o|inlining procedure: k4381 
o|inlining procedure: k4407 
o|inlining procedure: k4407 
o|consed rest parameter at call site: "(csc.scm:544) main#cons*" 2 
o|inlining procedure: k4427 
o|propagated global variable: r44287819 main#shared-library-extension 
o|inlining procedure: k4427 
o|inlining procedure: k4439 
o|inlining procedure: k4468 
o|inlining procedure: k4468 
o|contracted procedure: "(csc.scm:615) main#run-linking" 
o|inlining procedure: k6800 
o|inlining procedure: k6800 
o|inlining procedure: k6815 
o|inlining procedure: k6815 
o|inlining procedure: k6861 
o|inlining procedure: k6861 
o|inlining procedure: k6871 
o|propagated global variable: r68727834 main#host-libdir 
o|inlining procedure: k6871 
o|substituted constant variable: a6881 
o|consed rest parameter at call site: "(csc.scm:982) main#cons*" 2 
o|substituted constant variable: main#link-output-flag 
o|substituted constant variable: main#link-output-flag 
o|inlining procedure: k6922 
o|inlining procedure: k6922 
o|propagated global variable: g15221526 main#object-files 
o|contracted procedure: "(csc.scm:976) main#collect-linked-objects" 
o|inlining procedure: k7081 
o|contracted procedure: "(csc.scm:1021) main#delete-duplicates" 
o|inlining procedure: k3078 
o|inlining procedure: k3078 
o|contracted procedure: "(mini-srfi-1.scm:123) main#delete" 
o|inlining procedure: k3003 
o|inlining procedure: k3003 
o|inlining procedure: k7081 
o|contracted procedure: "(csc.scm:1025) locate-objects1565" 
o|inlining procedure: k7010 
o|contracted procedure: "(csc.scm:1015) g15781587" 
o|inlining procedure: k6986 
o|inlining procedure: k6986 
o|consed rest parameter at call site: "(csc.scm:1017) main#stop" 2 
o|inlining procedure: k7010 
o|inlining procedure: k7044 
o|inlining procedure: k7044 
o|contracted procedure: "(csc.scm:1023) locate-link-file1564" 
o|propagated global variable: tmp16331635 main#static 
o|propagated global variable: tmp16331635 main#static 
o|propagated global variable: ofiles1562 main#object-files 
o|propagated global variable: ofiles1562 main#object-files 
o|propagated global variable: out10791082 ##sys#standard-error 
o|substituted constant variable: a4484 
o|substituted constant variable: a4485 
o|substituted constant variable: a4512 
o|substituted constant variable: a4513 
o|inlining procedure: k4551 
o|inlining procedure: k4551 
o|propagated global variable: out10791082 ##sys#standard-error 
o|contracted procedure: "(csc.scm:604) main#filter-map" 
o|propagated global variable: lst493 main#linked-extensions 
o|inlining procedure: k3181 
o|inlining procedure: k3181 
o|inlining procedure: k3170 
o|inlining procedure: k3170 
o|contracted procedure: "(csc.scm:600) main#run-compilation" 
o|substituted constant variable: main#compile-only-flag 
o|inlining procedure: k6498 
o|inlining procedure: k6498 
o|substituted constant variable: main#compile-output-flag 
o|substituted constant variable: main#compile-output-flag 
o|consed rest parameter at call site: "(csc.scm:929) main#stop" 2 
o|inlining procedure: k6521 
o|substituted constant variable: a6527 
o|inlining procedure: k6521 
o|inlining procedure: k6583 
o|inlining procedure: k6583 
o|inlining procedure: k6601 
o|inlining procedure: k6601 
o|propagated global variable: g14661468 main#generated-rc-files 
o|inlining procedure: k6624 
o|inlining procedure: k6624 
o|propagated global variable: g14491451 main#generated-c-files 
o|inlining procedure: k6651 
o|inlining procedure: k6651 
o|propagated global variable: g14061430 main#rc-files 
o|contracted procedure: "(csc.scm:947) main#create-win-manifest" 
o|inlining procedure: k6702 
o|inlining procedure: k6702 
o|propagated global variable: g13961408 main#c-files 
o|inlining procedure: k4571 
o|inlining procedure: k4571 
o|contracted procedure: "(csc.scm:591) main#last" 
o|inlining procedure: k3283 
o|inlining procedure: k3283 
o|consed rest parameter at call site: "(csc.scm:587) main#stop" 2 
o|inlining procedure: k4592 
o|consed rest parameter at call site: "(csc.scm:587) main#stop" 2 
o|consed rest parameter at call site: "(csc.scm:586) main#cons*" 2 
o|inlining procedure: k4592 
o|consed rest parameter at call site: "(csc.scm:587) main#stop" 2 
o|contracted procedure: "(csc.scm:598) main#run-translation" 
o|inlining procedure: k6428 
o|contracted procedure: "(csc.scm:870) g13271334" 
o|consed rest parameter at call site: "(csc.scm:885) main#cons*" 2 
o|inlining procedure: k6332 
o|inlining procedure: k6332 
o|inlining procedure: k6368 
o|inlining procedure: k6368 
o|consed rest parameter at call site: "(csc.scm:881) main#stop" 2 
o|inlining procedure: k6405 
o|inlining procedure: k6405 
o|substituted constant variable: a6414 
o|inlining procedure: k6428 
o|propagated global variable: g13331335 main#scheme-files 
o|contracted procedure: "(csc.scm:597) main#first" 
o|propagated global variable: x451 main#scheme-files 
o|consed rest parameter at call site: "(csc.scm:579) main#stop" 2 
o|substituted constant variable: a4657 
o|contracted procedure: "(csc.scm:567) main#builtin-link-options" 
o|inlining procedure: k4120 
o|contracted procedure: "(csc.scm:280) g961962" 
o|inlining procedure: k4142 
o|contracted procedure: "(csc.scm:282) g972981" 
o|inlining procedure: k4142 
o|inlining procedure: k4120 
o|substituted constant variable: a4186 
o|inlining procedure: k4199 
o|inlining procedure: k4199 
o|inlining procedure: k4208 
o|inlining procedure: k4208 
o|inlining procedure: k4439 
o|contracted procedure: "(csc.scm:622) main#usage" 
o|inlining procedure: k4723 
o|inlining procedure: k4723 
o|substituted constant variable: a4756 
o|substituted constant variable: a4757 
o|inlining procedure: k4770 
o|inlining procedure: k4770 
o|inlining procedure: k4791 
o|inlining procedure: k4791 
o|inlining procedure: k4810 
o|inlining procedure: k4810 
o|inlining procedure: k4830 
o|inlining procedure: k4830 
o|inlining procedure: k4854 
o|inlining procedure: k4854 
o|inlining procedure: k4874 
o|consed rest parameter at call site: "(csc.scm:655) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:653) main#cons*" 2 
o|inlining procedure: k4874 
o|consed rest parameter at call site: "(csc.scm:661) t-options1034" 1 
o|inlining procedure: k4921 
o|consed rest parameter at call site: "(csc.scm:664) t-options1034" 1 
o|inlining procedure: k4921 
o|consed rest parameter at call site: "(csc.scm:667) t-options1034" 1 
o|inlining procedure: k4947 
o|inlining procedure: k4947 
o|inlining procedure: k4961 
o|inlining procedure: k4961 
o|inlining procedure: k4982 
o|consed rest parameter at call site: "(csc.scm:676) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:675) check1035" 3 
o|inlining procedure: k4982 
o|consed rest parameter at call site: "(csc.scm:681) check1035" 3 
o|inlining procedure: k5031 
o|consed rest parameter at call site: "(csc.scm:686) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:685) check1035" 3 
o|inlining procedure: k5031 
o|contracted procedure: "(csc.scm:689) use-private-repository1037" 
o|inlining procedure: k5063 
o|consed rest parameter at call site: "(csc.scm:692) t-options1034" 1 
o|inlining procedure: k5063 
o|consed rest parameter at call site: "(csc.scm:695) t-options1034" 1 
o|inlining procedure: k5083 
o|inlining procedure: k5083 
o|removed side-effect free assignment to unused variable: main#gui 
o|inlining procedure: k5101 
o|consed rest parameter at call site: "(csc.scm:708) main#cons*" 2 
o|inlining procedure: k5101 
o|inlining procedure: k5116 
o|inlining procedure: k5116 
o|consed rest parameter at call site: "(csc.scm:715) main#cons*" 2 
o|consed rest parameter at call site: "(csc.scm:713) check1035" 3 
o|inlining procedure: k5147 
o|consed rest parameter at call site: "(csc.scm:718) check1035" 3 
o|inlining procedure: k5147 
o|consed rest parameter at call site: "(csc.scm:722) main#cons*" 2 
o|inlining procedure: k5180 
o|consed rest parameter at call site: "(csc.scm:723) main#cons*" 2 
o|inlining procedure: k5180 
o|consed rest parameter at call site: "(csc.scm:724) main#cons*" 2 
o|inlining procedure: k5200 
o|consed rest parameter at call site: "(csc.scm:725) main#cons*" 2 
o|inlining procedure: k5200 
o|consed rest parameter at call site: "(csc.scm:726) main#cons*" 2 
o|inlining procedure: k5220 
o|consed rest parameter at call site: "(csc.scm:728) main#cons*" 2 
o|inlining procedure: k5220 
o|consed rest parameter at call site: "(csc.scm:729) main#cons*" 2 
o|inlining procedure: k5240 
o|consed rest parameter at call site: "(csc.scm:730) main#cons*" 2 
o|inlining procedure: k5240 
o|consed rest parameter at call site: "(csc.scm:731) main#cons*" 2 
o|inlining procedure: k5260 
o|consed rest parameter at call site: "(csc.scm:732) main#cons*" 2 
o|inlining procedure: k5260 
o|substituted constant variable: a5289 
o|consed rest parameter at call site: "(csc.scm:735) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:734) check1035" 3 
o|inlining procedure: k5304 
o|inlining procedure: k5304 
o|inlining procedure: k5324 
o|inlining procedure: k5324 
o|consed rest parameter at call site: "(csc.scm:748) check1035" 3 
o|inlining procedure: k5353 
o|consed rest parameter at call site: "(csc.scm:752) check1035" 3 
o|inlining procedure: k5353 
o|consed rest parameter at call site: "(csc.scm:756) check1035" 3 
o|inlining procedure: k5387 
o|consed rest parameter at call site: "(csc.scm:760) check1035" 3 
o|inlining procedure: k5387 
o|consed rest parameter at call site: "(csc.scm:765) main#cons*" 2 
o|consed rest parameter at call site: "(csc.scm:764) check1035" 3 
o|inlining procedure: k5425 
o|consed rest parameter at call site: "(csc.scm:767) check1035" 3 
o|inlining procedure: k5425 
o|inlining procedure: k5464 
o|consed rest parameter at call site: "(csc.scm:773) check1035" 3 
o|inlining procedure: k5464 
o|substituted constant variable: a5528 
o|inlining procedure: k5529 
o|inlining procedure: k5529 
o|consed rest parameter at call site: "(csc.scm:777) check1035" 3 
o|inlining procedure: k5538 
o|inlining procedure: k5538 
o|consed rest parameter at call site: "(csc.scm:787) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:786) check1035" 3 
o|inlining procedure: k5564 
o|consed rest parameter at call site: "(csc.scm:791) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:790) check1035" 3 
o|inlining procedure: k5564 
o|inlining procedure: k5594 
o|inlining procedure: k5594 
o|inlining procedure: k5610 
o|inlining procedure: k5610 
o|consed rest parameter at call site: "(csc.scm:805) t-options1034" 1 
o|inlining procedure: k5635 
o|consed rest parameter at call site: "(csc.scm:808) t-options1034" 1 
o|consed rest parameter at call site: "(csc.scm:807) check1035" 3 
o|inlining procedure: k5635 
o|consed rest parameter at call site: "(csc.scm:811) t-options1034" 1 
o|inlining procedure: k5664 
o|substituted constant variable: a5676 
o|substituted constant variable: a5673 
o|substituted constant variable: a5696 
o|substituted constant variable: a5703 
o|substituted constant variable: a5700 
o|inlining procedure: k5697 
o|substituted constant variable: a5723 
o|inlining procedure: k5697 
o|substituted constant variable: a5730 
o|substituted constant variable: a5727 
o|consed rest parameter at call site: "(csc.scm:823) t-options1034" 1 
o|substituted constant variable: a5744 
o|substituted constant variable: a5741 
o|inlining procedure: k5738 
o|inlining procedure: k5738 
o|inlining procedure: k5770 
o|inlining procedure: k5809 
o|contracted procedure: "(csc.scm:833) g12721281" 
o|substituted constant variable: a5798 
o|inlining procedure: k5809 
o|inlining procedure: k5840 
o|consed rest parameter at call site: "(csc.scm:837) main#stop" 2 
o|inlining procedure: k5840 
o|consed rest parameter at call site: "(csc.scm:838) main#stop" 2 
o|contracted procedure: "(csc.scm:831) main#lset-difference/eq?" 
o|inlining procedure: k3383 
o|contracted procedure: "(mini-srfi-1.scm:164) g593594" 
o|inlining procedure: k3383 
o|inlining procedure: k5770 
o|consed rest parameter at call site: "(csc.scm:839) main#stop" 2 
o|substituted constant variable: a5871 
o|substituted constant variable: a5876 
o|substituted constant variable: a5885 
o|inlining procedure: k5664 
o|inlining procedure: k5905 
o|inlining procedure: k5905 
o|inlining procedure: k5933 
o|inlining procedure: k5933 
o|inlining procedure: k5969 
o|inlining procedure: k5969 
o|inlining procedure: k6013 
o|inlining procedure: k6013 
o|consed rest parameter at call site: "(csc.scm:863) main#stop" 2 
o|substituted constant variable: a6027 
o|substituted constant variable: a6034 
o|substituted constant variable: a6031 
o|substituted constant variable: a6039 
o|substituted constant variable: a6044 
o|substituted constant variable: a6053 
o|substituted constant variable: main#constant834 
o|substituted constant variable: main#constant831 
o|substituted constant variable: main#constant838 
o|substituted constant variable: a6056 
o|substituted constant variable: a6065 
o|substituted constant variable: a6067 
o|substituted constant variable: a6069 
o|substituted constant variable: a6071 
o|substituted constant variable: a6073 
o|substituted constant variable: a6075 
o|substituted constant variable: a6077 
o|substituted constant variable: a6079 
o|substituted constant variable: a6081 
o|substituted constant variable: a6083 
o|substituted constant variable: a6085 
o|substituted constant variable: a6087 
o|substituted constant variable: a6089 
o|substituted constant variable: a6094 
o|substituted constant variable: a6096 
o|inlining procedure: k6100 
o|inlining procedure: k6100 
o|substituted constant variable: a6107 
o|substituted constant variable: a6109 
o|substituted constant variable: a6111 
o|substituted constant variable: a6113 
o|substituted constant variable: a6115 
o|substituted constant variable: a6117 
o|substituted constant variable: a6119 
o|substituted constant variable: a6121 
o|substituted constant variable: a6123 
o|substituted constant variable: a6125 
o|substituted constant variable: a6127 
o|substituted constant variable: a6129 
o|substituted constant variable: a6131 
o|substituted constant variable: a6133 
o|substituted constant variable: a6138 
o|substituted constant variable: a6140 
o|substituted constant variable: a6145 
o|substituted constant variable: a6147 
o|substituted constant variable: a6149 
o|substituted constant variable: a6151 
o|substituted constant variable: a6153 
o|substituted constant variable: a6155 
o|substituted constant variable: a6157 
o|substituted constant variable: a6159 
o|substituted constant variable: a6161 
o|substituted constant variable: a6166 
o|substituted constant variable: a6168 
o|substituted constant variable: a6170 
o|substituted constant variable: a6172 
o|substituted constant variable: a6177 
o|substituted constant variable: a6179 
o|substituted constant variable: a6181 
o|substituted constant variable: a6183 
o|substituted constant variable: a6185 
o|substituted constant variable: a6190 
o|substituted constant variable: a6192 
o|substituted constant variable: a6197 
o|substituted constant variable: a6199 
o|substituted constant variable: a6204 
o|substituted constant variable: a6206 
o|substituted constant variable: a6211 
o|substituted constant variable: a6213 
o|substituted constant variable: a6215 
o|substituted constant variable: a6217 
o|substituted constant variable: a6219 
o|substituted constant variable: a6221 
o|substituted constant variable: a6223 
o|substituted constant variable: a6225 
o|substituted constant variable: a6227 
o|substituted constant variable: a6229 
o|substituted constant variable: a6231 
o|substituted constant variable: a6233 
o|substituted constant variable: a6235 
o|substituted constant variable: a6237 
o|substituted constant variable: a6242 
o|substituted constant variable: a6244 
o|inlining procedure: k7480 
o|inlining procedure: k7480 
o|inlining procedure: k7491 
o|contracted procedure: "(csc.scm:249) g881882" 
o|inlining procedure: k7522 
o|contracted procedure: "(csc.scm:251) g892901" 
o|inlining procedure: k7522 
o|inlining procedure: k7556 
o|inlining procedure: k7556 
o|inlining procedure: k7491 
o|inlining procedure: k7618 
o|inlining procedure: k7618 
o|inlining procedure: k7628 
o|propagated global variable: r76298024 main#host-cflags 
o|inlining procedure: k7628 
o|propagated global variable: r76298026 main#default-cflags 
o|inlining procedure: k7631 
o|inlining procedure: k7631 
o|propagated global variable: r76328029 main#cygwin 
o|inlining procedure: k7635 
o|propagated global variable: r76368030 main#host-cxx 
o|inlining procedure: k7635 
o|propagated global variable: r76368032 main#default-cxx 
o|inlining procedure: k7639 
o|propagated global variable: r76408034 main#host-cc 
o|inlining procedure: k7639 
o|propagated global variable: r76408036 main#default-cc 
o|inlining procedure: k7643 
o|inlining procedure: k7643 
o|inlining procedure: k7653 
o|propagated global variable: r76548042 main#host-cxx 
o|inlining procedure: k7653 
o|propagated global variable: r76548044 main#default-cxx 
o|inlining procedure: k7657 
o|propagated global variable: r76588046 main#host-cc 
o|inlining procedure: k7657 
o|propagated global variable: r76588048 main#default-cc 
o|inlining procedure: k7698 
o|inlining procedure: k7698 
o|simplifications: ((if . 2)) 
o|replaced variables: 1136 
o|removed binding forms: 452 
o|removed side-effect free assignment to unused variable: main#every 
o|removed side-effect free assignment to unused variable: main#any 
o|removed side-effect free assignment to unused variable: main#list-tabulate 
o|propagated global variable: out781784 ##sys#standard-error 
o|removed side-effect free assignment to unused variable: main#link-output-flag 
o|removed side-effect free assignment to unused variable: main#compile-output-flag 
o|removed side-effect free assignment to unused variable: main#default-translation-optimization-options 
o|removed side-effect free assignment to unused variable: main#constant831 
o|removed side-effect free assignment to unused variable: main#constant834 
o|removed side-effect free assignment to unused variable: main#constant838 
o|removed side-effect free assignment to unused variable: main#compile-only-flag 
o|substituted constant variable: mode209 
o|folded constant expression: (scheme#eq? (quote target) (quote target)) 
o|substituted constant variable: r73397799 
o|substituted constant variable: r73397802 
o|propagated global variable: out17181721 ##sys#standard-output 
o|substituted constant variable: r43827811 
o|substituted constant variable: r43827811 
o|inlining procedure: k4407 
o|substituted constant variable: r44087817 
o|substituted constant variable: r44087817 
o|inlining procedure: k4427 
o|propagated global variable: r44288064 main#object-extension 
o|propagated global variable: r44288064 main#object-extension 
o|propagated global variable: out10791082 ##sys#standard-error 
o|substituted constant variable: r45527852 
o|substituted constant variable: r45527852 
o|substituted constant variable: r45527854 
o|substituted constant variable: r45527854 
o|substituted constant variable: r31717859 
o|propagated global variable: lst493 main#linked-extensions 
o|substituted constant variable: r64997861 
o|substituted constant variable: r65227863 
o|substituted constant variable: r63697891 
o|substituted constant variable: r63697891 
o|inlining procedure: k6368 
o|substituted constant variable: r64067895 
o|substituted constant variable: r64067895 
o|inlining procedure: k6405 
o|substituted constant variable: r41217904 
o|substituted constant variable: r41217904 
o|substituted constant variable: r42007906 
o|substituted constant variable: r42007906 
o|inlining procedure: k4199 
o|propagated global variable: r42008128 main#host-libdir 
o|propagated global variable: r42008128 main#host-libdir 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|substituted constant variable: r55307970 
o|inlining procedure: k4705 
o|substituted constant variable: r55397972 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|inlining procedure: k4705 
o|contracted procedure: "(mini-srfi-1.scm:166) main#filter" 
o|substituted constant variable: r31277764 
o|inlining procedure: k4705 
o|substituted constant variable: r74818010 
o|substituted constant variable: r74818010 
o|substituted constant variable: r74928018 
o|substituted constant variable: r74928018 
o|removed call to pure procedure with unused result: "(csc.scm:66) scheme#eq?" 
o|replaced variables: 138 
o|removed binding forms: 987 
o|removed conditional forms: 1 
o|contracted procedure: k3789 
o|inlining procedure: k3876 
o|contracted procedure: k2461 
o|inlining procedure: k7404 
o|propagated global variable: r74058441 main#last-exit-code 
o|inlining procedure: k7404 
o|propagated global variable: r74058443 main#last-exit-code 
o|inlining procedure: k7413 
o|contracted procedure: k4407 
o|contracted procedure: k4427 
o|propagated global variable: r4428 main#executable-extension 
o|inlining procedure: k7031 
o|inlining procedure: k6962 
o|inlining procedure: k4544 
o|propagated global variable: r45458474 main#quotewrap-no-slash-trans 
o|inlining procedure: k4544 
o|propagated global variable: r45458478 main#quotewrap 
o|contracted procedure: "(mini-srfi-1.scm:134) g503504" 
o|inlining procedure: k6515 
o|inlining procedure: k6515 
o|inlining procedure: k6434 
o|contracted procedure: k6368 
o|contracted procedure: k6405 
o|inlining procedure: k4642 
o|inlining procedure: k4642 
o|inlining procedure: k4664 
o|inlining procedure: k4176 
o|inlining procedure: k4176 
o|inlining procedure: k4705 
o|removed call to pure procedure with unused result: "(csc.scm:66) chicken.platform#software-type" 
o|replaced variables: 4 
o|removed binding forms: 267 
o|contracted procedure: k7688 
o|substituted constant variable: r2462 
o|substituted constant variable: r44088062 
o|substituted constant variable: r4408 
o|inlining procedure: "(csc.scm:610) main#quotewrap-no-slash-trans" 
o|propagated global variable: str8018554 main#target-filename 
o|substituted constant variable: r65168484 
o|substituted constant variable: r65168485 
o|substituted constant variable: r63698114 
o|substituted constant variable: r6369 
o|substituted constant variable: r64068116 
o|substituted constant variable: r6406 
o|substituted constant variable: r46438509 
o|substituted constant variable: r41778517 
o|simplifications: ((if . 1) (let . 2)) 
o|replaced variables: 8 
o|removed binding forms: 17 
o|removed conditional forms: 5 
o|removed side-effect free assignment to unused variable: main#host-repo 
o|inlining procedure: k2455 
o|replaced variables: 4 
o|removed binding forms: 18 
o|substituted constant variable: r24568591 
o|removed binding forms: 4 
o|removed conditional forms: 1 
o|removed binding forms: 1 
o|simplifications: ((if . 40) (let . 9) (##core#call . 382)) 
o|  call simplifications:
o|    scheme#assq
o|    ##sys#call-with-values
o|    scheme#string-ci=?
o|    ##sys#size	4
o|    chicken.fixnum#fx>	4
o|    scheme#memq	3
o|    scheme#char=?
o|    scheme#string
o|    scheme#char-whitespace?	2
o|    scheme#cadr
o|    scheme#string->list	3
o|    scheme#number?
o|    ##sys#list
o|    scheme#member	10
o|    scheme#cdr	20
o|    scheme#string=?	2
o|    scheme#equal?
o|    scheme#length	5
o|    scheme#>=	2
o|    scheme#list	32
o|    ##sys#check-list	15
o|    scheme#pair?	20
o|    ##sys#setslot	10
o|    ##sys#slot	48
o|    scheme#eq?	83
o|    scheme#not	11
o|    ##sys#apply
o|    scheme#null?	13
o|    scheme#car	29
o|    scheme#cons	56
o|contracted procedure: k7726 
o|contracted procedure: k2328 
o|contracted procedure: k2950 
o|contracted procedure: k2961 
o|contracted procedure: k3793 
o|contracted procedure: k3797 
o|contracted procedure: k3801 
o|contracted procedure: k3805 
o|contracted procedure: k3854 
o|contracted procedure: k3857 
o|contracted procedure: k3894 
o|contracted procedure: k3922 
o|contracted procedure: k3954 
o|contracted procedure: k4033 
o|contracted procedure: k4041 
o|contracted procedure: k4082 
o|contracted procedure: k7601 
o|contracted procedure: k7597 
o|contracted procedure: k4085 
o|contracted procedure: k4099 
o|contracted procedure: k2473 
o|contracted procedure: k2455 
o|contracted procedure: k4281 
o|contracted procedure: k4301 
o|contracted procedure: k6729 
o|contracted procedure: k6735 
o|contracted procedure: k6747 
o|contracted procedure: k6750 
o|contracted procedure: k6753 
o|contracted procedure: k6761 
o|contracted procedure: k6769 
o|contracted procedure: k7210 
o|contracted procedure: k7216 
o|contracted procedure: k7228 
o|contracted procedure: k7231 
o|contracted procedure: k7234 
o|contracted procedure: k7242 
o|contracted procedure: k7250 
o|contracted procedure: k7271 
o|contracted procedure: k7341 
o|contracted procedure: k7345 
o|contracted procedure: k4377 
o|contracted procedure: k4384 
o|inlining procedure: k4370 
o|contracted procedure: k4381 
o|inlining procedure: k4370 
o|contracted procedure: k4442 
o|contracted procedure: k6782 
o|contracted procedure: k6785 
o|contracted procedure: k6806 
o|contracted procedure: k6818 
o|contracted procedure: k6828 
o|contracted procedure: k6832 
o|contracted procedure: k6835 
o|contracted procedure: k6891 
o|contracted procedure: k6899 
o|contracted procedure: k6925 
o|contracted procedure: k6928 
o|contracted procedure: k6931 
o|contracted procedure: k6939 
o|contracted procedure: k6947 
o|propagated global variable: g15221526 main#object-files 
o|contracted procedure: k7084 
o|contracted procedure: k3081 
o|contracted procedure: k3084 
o|contracted procedure: k3094 
o|contracted procedure: k3006 
o|contracted procedure: k3032 
o|contracted procedure: k3012 
o|contracted procedure: k6978 
o|contracted procedure: k6992 
o|contracted procedure: k6995 
o|contracted procedure: k7001 
o|contracted procedure: k7013 
o|contracted procedure: k7019 
o|contracted procedure: k7027 
o|contracted procedure: k7035 
o|contracted procedure: k7047 
o|contracted procedure: k7050 
o|contracted procedure: k7053 
o|contracted procedure: k7061 
o|contracted procedure: k7069 
o|contracted procedure: k7127 
o|contracted procedure: k7134 
o|contracted procedure: k7138 
o|contracted procedure: k7151 
o|contracted procedure: k7147 
o|contracted procedure: k4480 
o|contracted procedure: k4533 
o|contracted procedure: k4554 
o|contracted procedure: k3161 
o|contracted procedure: k3173 
o|contracted procedure: k3196 
o|contracted procedure: k3204 
o|propagated global variable: lst493 main#linked-extensions 
o|contracted procedure: k6463 
o|contracted procedure: k6467 
o|contracted procedure: k6479 
o|contracted procedure: k6475 
o|contracted procedure: k6498 
o|contracted procedure: k6509 
o|contracted procedure: k6529 
o|contracted procedure: k6515 
o|contracted procedure: k6532 
o|contracted procedure: k6550 
o|contracted procedure: k6554 
o|contracted procedure: k6562 
o|contracted procedure: k6573 
o|contracted procedure: k6586 
o|contracted procedure: k6592 
o|contracted procedure: k6604 
o|contracted procedure: k6614 
o|contracted procedure: k6618 
o|propagated global variable: g14661468 main#generated-rc-files 
o|contracted procedure: k6627 
o|contracted procedure: k6637 
o|contracted procedure: k6641 
o|propagated global variable: g14491451 main#generated-c-files 
o|contracted procedure: k6654 
o|contracted procedure: k6664 
o|contracted procedure: k6668 
o|propagated global variable: g14061430 main#rc-files 
o|contracted procedure: k6681 
o|contracted procedure: k6685 
o|contracted procedure: k7453 
o|contracted procedure: k7449 
o|contracted procedure: k7445 
o|contracted procedure: k6705 
o|contracted procedure: k6715 
o|contracted procedure: k6719 
o|propagated global variable: g13961408 main#c-files 
o|contracted procedure: k4565 
o|contracted procedure: k4586 
o|contracted procedure: k4583 
o|contracted procedure: k3296 
o|contracted procedure: k3286 
o|contracted procedure: k4609 
o|contracted procedure: k4589 
o|contracted procedure: k6419 
o|contracted procedure: k6431 
o|contracted procedure: k6445 
o|contracted procedure: k6416 
o|contracted procedure: k6411 
o|contracted procedure: k6250 
o|contracted procedure: k64418503 
o|contracted procedure: k6274 
o|contracted procedure: k6278 
o|contracted procedure: k6281 
o|contracted procedure: k6285 
o|contracted procedure: k6313 
o|contracted procedure: k6317 
o|contracted procedure: k6323 
o|contracted procedure: k6335 
o|contracted procedure: k6338 
o|contracted procedure: k6341 
o|contracted procedure: k6349 
o|contracted procedure: k6357 
o|contracted procedure: k6388 
o|contracted procedure: k6398 
o|propagated global variable: g13331335 main#scheme-files 
o|contracted procedure: k4629 
o|contracted procedure: k4632 
o|contracted procedure: k4636 
o|contracted procedure: k4650 
o|contracted procedure: k4654 
o|contracted procedure: k4125 
o|contracted procedure: k4145 
o|contracted procedure: k4148 
o|contracted procedure: k4151 
o|contracted procedure: k4159 
o|contracted procedure: k4167 
o|contracted procedure: k4698 
o|contracted procedure: k4711 
o|contracted procedure: k4714 
o|contracted procedure: k4351 
o|contracted procedure: k4347 
o|contracted procedure: k4343 
o|contracted procedure: k4339 
o|contracted procedure: k4335 
o|contracted procedure: k4331 
o|contracted procedure: k4327 
o|contracted procedure: k4726 
o|contracted procedure: k4742 
o|contracted procedure: k4773 
o|contracted procedure: k4781 
o|contracted procedure: k4787 
o|contracted procedure: k4794 
o|contracted procedure: k4798 
o|contracted procedure: k4805 
o|contracted procedure: k4813 
o|contracted procedure: k4821 
o|contracted procedure: k4833 
o|contracted procedure: k4845 
o|contracted procedure: k4857 
o|contracted procedure: k4869 
o|contracted procedure: k4877 
o|contracted procedure: k4880 
o|contracted procedure: k4894 
o|contracted procedure: k4902 
o|contracted procedure: k4908 
o|contracted procedure: k4911 
o|contracted procedure: k4915 
o|contracted procedure: k4924 
o|contracted procedure: k4927 
o|contracted procedure: k4937 
o|contracted procedure: k4940 
o|contracted procedure: k4950 
o|contracted procedure: k4957 
o|contracted procedure: k4964 
o|contracted procedure: k4971 
o|contracted procedure: k4974 
o|contracted procedure: k4979 
o|contracted procedure: k4985 
o|contracted procedure: k4999 
o|contracted procedure: k5007 
o|contracted procedure: k5011 
o|contracted procedure: k5017 
o|contracted procedure: k5024 
o|contracted procedure: k5028 
o|contracted procedure: k5034 
o|contracted procedure: k5037 
o|contracted procedure: k5047 
o|contracted procedure: k5051 
o|contracted procedure: k5057 
o|contracted procedure: k4417 
o|contracted procedure: k5066 
o|contracted procedure: k5076 
o|contracted procedure: k5086 
o|contracted procedure: k5093 
o|contracted procedure: k5098 
o|contracted procedure: k5105 
o|contracted procedure: k5119 
o|contracted procedure: k5126 
o|contracted procedure: k5136 
o|contracted procedure: k5144 
o|contracted procedure: k5150 
o|contracted procedure: k5153 
o|contracted procedure: k5159 
o|contracted procedure: k5163 
o|contracted procedure: k5170 
o|contracted procedure: k5173 
o|contracted procedure: k5183 
o|contracted procedure: k5193 
o|contracted procedure: k5203 
o|contracted procedure: k5213 
o|contracted procedure: k5223 
o|contracted procedure: k5233 
o|contracted procedure: k5243 
o|contracted procedure: k5253 
o|contracted procedure: k5263 
o|contracted procedure: k5273 
o|contracted procedure: k5286 
o|contracted procedure: k5297 
o|contracted procedure: k5301 
o|contracted procedure: k5307 
o|contracted procedure: k5315 
o|contracted procedure: k5327 
o|contracted procedure: k5330 
o|contracted procedure: k5339 
o|contracted procedure: k5346 
o|contracted procedure: k5350 
o|contracted procedure: k5356 
o|contracted procedure: k5363 
o|contracted procedure: k5367 
o|contracted procedure: k5373 
o|contracted procedure: k5380 
o|contracted procedure: k5384 
o|contracted procedure: k5390 
o|contracted procedure: k5397 
o|contracted procedure: k5401 
o|contracted procedure: k5407 
o|contracted procedure: k5418 
o|contracted procedure: k5422 
o|contracted procedure: k5428 
o|contracted procedure: k5439 
o|contracted procedure: k5447 
o|contracted procedure: k5453 
o|contracted procedure: k5461 
o|contracted procedure: k5467 
o|contracted procedure: k5478 
o|contracted procedure: k5486 
o|contracted procedure: k5492 
o|contracted procedure: k5499 
o|contracted procedure: k5506 
o|contracted procedure: k5517 
o|contracted procedure: k5532 
o|contracted procedure: k5541 
o|contracted procedure: k5547 
o|contracted procedure: k5557 
o|contracted procedure: k5561 
o|contracted procedure: k5567 
o|contracted procedure: k5577 
o|contracted procedure: k5581 
o|contracted procedure: k5587 
o|contracted procedure: k5607 
o|contracted procedure: k5620 
o|contracted procedure: k5616 
o|contracted procedure: k5629 
o|contracted procedure: k5638 
o|contracted procedure: k5648 
o|contracted procedure: k5652 
o|contracted procedure: k6036 
o|contracted procedure: k6028 
o|contracted procedure: k5667 
o|contracted procedure: k5685 
o|contracted procedure: k5688 
o|contracted procedure: k5712 
o|contracted procedure: k5715 
o|contracted procedure: k5753 
o|contracted procedure: k5767 
o|contracted procedure: k5868 
o|contracted procedure: k5773 
o|contracted procedure: k5776 
o|contracted procedure: k5782 
o|contracted procedure: k5790 
o|contracted procedure: k5812 
o|contracted procedure: k5815 
o|contracted procedure: k5818 
o|contracted procedure: k5826 
o|contracted procedure: k5834 
o|contracted procedure: k5800 
o|contracted procedure: k5853 
o|contracted procedure: k5843 
o|contracted procedure: k3386 
o|contracted procedure: k3393 
o|contracted procedure: k3416 
o|contracted procedure: k3409 
o|contracted procedure: k3117 
o|contracted procedure: k3129 
o|contracted procedure: k3147 
o|contracted procedure: k3155 
o|contracted procedure: k5882 
o|contracted procedure: k5873 
o|contracted procedure: k5908 
o|contracted procedure: k5916 
o|contracted procedure: k5922 
o|contracted procedure: k5930 
o|contracted procedure: k5936 
o|contracted procedure: k5944 
o|contracted procedure: k5950 
o|contracted procedure: k5962 
o|contracted procedure: k5966 
o|contracted procedure: k5972 
o|contracted procedure: k5981 
o|contracted procedure: k5997 
o|contracted procedure: k6005 
o|contracted procedure: k6020 
o|contracted procedure: k6050 
o|contracted procedure: k6041 
o|contracted procedure: k6059 
o|contracted procedure: k6097 
o|contracted procedure: k7496 
o|contracted procedure: k7504 
o|contracted procedure: k7513 
o|contracted procedure: k7525 
o|contracted procedure: k7528 
o|contracted procedure: k7531 
o|contracted procedure: k7539 
o|contracted procedure: k7547 
o|contracted procedure: k7559 
o|contracted procedure: k7562 
o|contracted procedure: k7565 
o|contracted procedure: k7573 
o|contracted procedure: k7581 
o|contracted procedure: k7740 
o|contracted procedure: k7744 
o|contracted procedure: k7748 
o|contracted procedure: k7752 
o|simplifications: ((if . 4) (let . 90)) 
o|removed binding forms: 359 
o|inlining procedure: k7267 
o|inlining procedure: k7267 
o|contracted procedure: k6374 
o|inlining procedure: k5132 
o|inlining procedure: k5132 
o|inlining procedure: k5282 
o|inlining procedure: k5282 
o|inlining procedure: k5502 
o|inlining procedure: k5502 
o|substituted constant variable: r7741 
o|substituted constant variable: r7745 
o|substituted constant variable: r7749 
o|substituted constant variable: r7753 
o|simplifications: ((let . 2)) 
o|replaced variables: 10 
o|removed binding forms: 2 
o|removed binding forms: 17 
o|direct leaf routine/allocation: g513514 3 
o|direct leaf routine/allocation: loop553 0 
o|direct leaf routine/allocation: g12451246 3 
o|direct leaf routine/allocation: a3402 0 
o|contracted procedure: k4579 
o|converted assignments to bindings: (loop553) 
o|inlining procedure: "(csc.scm:804) k4705" 
o|contracted procedure: "(mini-srfi-1.scm:131) k3137" 
o|simplifications: ((let . 1)) 
o|removed binding forms: 2 
o|direct leaf routine/allocation: g485486 3 
x|eliminated type checks:
x|  C_i_check_list_2:	1
o|customizable procedures: (k3940 k7484 map-loop913930 map-loop886937 k5318 k5601 k5604 k5658 k5989 k5953 k5759 foldr480483 foldl586590 map-loop12661284 k5509 shared-build1036 check1035 k4883 t-options1034 loop1058 k4109 k4113 map-loop966991 k4615 k4618 k6309 k6364 map-loop13471368 k6262 for-each-loop13261380 generate-target-filename1038 g13901407 for-each-loop13891420 k6671 k6538 g14001429 for-each-loop13991435 for-each-loop14421452 for-each-loop14591469 k6491 main#compiler-options foldr498501 k4471 k7097 map-loop15951612 k7016 map-loop15721619 loop1626 loop443 loop463 map-loop15101527 main#linker-options main#linker-libraries main#command for-each-loop15431553 main#cons* main#stop g17141715 main#libchicken map-loop16651682 map-loop14821499 main#repo-path loop430) 
o|calls to known targets: 301 
o|identified direct recursive calls: f_2945 1 
o|identified direct recursive calls: f_3001 2 
o|identified direct recursive calls: f_3168 1 
o|identified direct recursive calls: f_3281 1 
o|identified direct recursive calls: f_3124 1 
o|fast box initializations: 28 
o|fast global references: 432 
o|fast global assignments: 202 
o|dropping unused closure argument: f_2939 
o|dropping unused closure argument: f_3281 
o|dropping unused closure argument: f_3821 
o|dropping unused closure argument: f_3945 
o|dropping unused closure argument: f_4234 
o|dropping unused closure argument: f_4358 
o|dropping unused closure argument: f_4365 
o|dropping unused closure argument: f_4391 
o|dropping unused closure argument: f_4421 
o|dropping unused closure argument: f_6723 
o|dropping unused closure argument: f_7204 
o|dropping unused closure argument: f_7257 
o|dropping unused closure argument: f_7398 
*/
/* end of file */
