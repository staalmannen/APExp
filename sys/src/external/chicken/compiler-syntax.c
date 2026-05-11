/* Generated from compiler-syntax.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: compiler-syntax.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.compiler-syntax -output-file compiler-syntax.c
   unit: compiler-syntax
   uses: eval expand extras compiler support library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_toplevel)
C_externimport void C_ccall C_compiler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_support_toplevel)
C_externimport void C_ccall C_support_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[105];
static double C_possibly_force_alignment;


C_noret_decl(f_1689)
static void C_ccall f_1689(C_word c,C_word *av) C_noret;
C_noret_decl(f_1692)
static void C_ccall f_1692(C_word c,C_word *av) C_noret;
C_noret_decl(f_1695)
static void C_ccall f_1695(C_word c,C_word *av) C_noret;
C_noret_decl(f_1698)
static void C_ccall f_1698(C_word c,C_word *av) C_noret;
C_noret_decl(f_1701)
static void C_ccall f_1701(C_word c,C_word *av) C_noret;
C_noret_decl(f_1704)
static void C_ccall f_1704(C_word c,C_word *av) C_noret;
C_noret_decl(f_2785)
static void C_fcall f_2785(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2791)
static C_word C_fcall f_2791(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_2985)
static void C_ccall f_2985(C_word c,C_word *av) C_noret;
C_noret_decl(f_2989)
static void C_ccall f_2989(C_word c,C_word *av) C_noret;
C_noret_decl(f_2993)
static void C_ccall f_2993(C_word c,C_word *av) C_noret;
C_noret_decl(f_2997)
static void C_fcall f_2997(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3002)
static void C_fcall f_3002(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3011)
static void C_fcall f_3011(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3021)
static void C_ccall f_3021(C_word c,C_word *av) C_noret;
C_noret_decl(f_3036)
static void C_ccall f_3036(C_word c,C_word *av) C_noret;
C_noret_decl(f_3040)
static void C_ccall f_3040(C_word c,C_word *av) C_noret;
C_noret_decl(f_3044)
static void C_ccall f_3044(C_word c,C_word *av) C_noret;
C_noret_decl(f_3051)
static void C_ccall f_3051(C_word c,C_word *av) C_noret;
C_noret_decl(f_3054)
static void C_ccall f_3054(C_word c,C_word *av) C_noret;
C_noret_decl(f_3057)
static void C_ccall f_3057(C_word c,C_word *av) C_noret;
C_noret_decl(f_3060)
static void C_ccall f_3060(C_word c,C_word *av) C_noret;
C_noret_decl(f_3063)
static void C_ccall f_3063(C_word c,C_word *av) C_noret;
C_noret_decl(f_3066)
static void C_ccall f_3066(C_word c,C_word *av) C_noret;
C_noret_decl(f_3068)
static void C_fcall f_3068(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_3074)
static void C_ccall f_3074(C_word c,C_word *av) C_noret;
C_noret_decl(f_3096)
static void C_fcall f_3096(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3099)
static void C_ccall f_3099(C_word c,C_word *av) C_noret;
C_noret_decl(f_3102)
static void C_fcall f_3102(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3106)
static void C_ccall f_3106(C_word c,C_word *av) C_noret;
C_noret_decl(f_3109)
static void C_ccall f_3109(C_word c,C_word *av) C_noret;
C_noret_decl(f_3119)
static void C_ccall f_3119(C_word c,C_word *av) C_noret;
C_noret_decl(f_3125)
static void C_ccall f_3125(C_word c,C_word *av) C_noret;
C_noret_decl(f_3128)
static void C_ccall f_3128(C_word c,C_word *av) C_noret;
C_noret_decl(f_3131)
static void C_ccall f_3131(C_word c,C_word *av) C_noret;
C_noret_decl(f_3134)
static void C_ccall f_3134(C_word c,C_word *av) C_noret;
C_noret_decl(f_3137)
static void C_ccall f_3137(C_word c,C_word *av) C_noret;
C_noret_decl(f_3140)
static void C_ccall f_3140(C_word c,C_word *av) C_noret;
C_noret_decl(f_3143)
static void C_ccall f_3143(C_word c,C_word *av) C_noret;
C_noret_decl(f_3146)
static void C_ccall f_3146(C_word c,C_word *av) C_noret;
C_noret_decl(f_3150)
static void C_ccall f_3150(C_word c,C_word *av) C_noret;
C_noret_decl(f_3153)
static void C_ccall f_3153(C_word c,C_word *av) C_noret;
C_noret_decl(f_3159)
static void C_ccall f_3159(C_word c,C_word *av) C_noret;
C_noret_decl(f_3162)
static void C_ccall f_3162(C_word c,C_word *av) C_noret;
C_noret_decl(f_3165)
static void C_ccall f_3165(C_word c,C_word *av) C_noret;
C_noret_decl(f_3174)
static void C_ccall f_3174(C_word c,C_word *av) C_noret;
C_noret_decl(f_3177)
static void C_ccall f_3177(C_word c,C_word *av) C_noret;
C_noret_decl(f_3180)
static void C_ccall f_3180(C_word c,C_word *av) C_noret;
C_noret_decl(f_3182)
static C_word C_fcall f_3182(C_word t0);
C_noret_decl(f_3192)
static void C_fcall f_3192(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3211)
static void C_fcall f_3211(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3242)
static void C_ccall f_3242(C_word c,C_word *av) C_noret;
C_noret_decl(f_3249)
static C_word C_fcall f_3249(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_3259)
static void C_fcall f_3259(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3269)
static void C_ccall f_3269(C_word c,C_word *av) C_noret;
C_noret_decl(f_3272)
static void C_ccall f_3272(C_word c,C_word *av) C_noret;
C_noret_decl(f_3295)
static void C_ccall f_3295(C_word c,C_word *av) C_noret;
C_noret_decl(f_3324)
static void C_ccall f_3324(C_word c,C_word *av) C_noret;
C_noret_decl(f_3330)
static void C_ccall f_3330(C_word c,C_word *av) C_noret;
C_noret_decl(f_3347)
static void C_ccall f_3347(C_word c,C_word *av) C_noret;
C_noret_decl(f_3364)
static void C_ccall f_3364(C_word c,C_word *av) C_noret;
C_noret_decl(f_3381)
static void C_ccall f_3381(C_word c,C_word *av) C_noret;
C_noret_decl(f_3402)
static void C_ccall f_3402(C_word c,C_word *av) C_noret;
C_noret_decl(f_3423)
static void C_ccall f_3423(C_word c,C_word *av) C_noret;
C_noret_decl(f_3444)
static void C_ccall f_3444(C_word c,C_word *av) C_noret;
C_noret_decl(f_3466)
static void C_ccall f_3466(C_word c,C_word *av) C_noret;
C_noret_decl(f_3469)
static void C_ccall f_3469(C_word c,C_word *av) C_noret;
C_noret_decl(f_3520)
static void C_fcall f_3520(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3592)
static void C_ccall f_3592(C_word c,C_word *av) C_noret;
C_noret_decl(f_3599)
static void C_ccall f_3599(C_word c,C_word *av) C_noret;
C_noret_decl(f_3603)
static void C_ccall f_3603(C_word c,C_word *av) C_noret;
C_noret_decl(f_3617)
static void C_ccall f_3617(C_word c,C_word *av) C_noret;
C_noret_decl(f_3625)
static void C_ccall f_3625(C_word c,C_word *av) C_noret;
C_noret_decl(f_3628)
static void C_ccall f_3628(C_word c,C_word *av) C_noret;
C_noret_decl(f_3630)
static void C_ccall f_3630(C_word c,C_word *av) C_noret;
C_noret_decl(f_3649)
static void C_ccall f_3649(C_word c,C_word *av) C_noret;
C_noret_decl(f_3652)
static void C_ccall f_3652(C_word c,C_word *av) C_noret;
C_noret_decl(f_3655)
static void C_ccall f_3655(C_word c,C_word *av) C_noret;
C_noret_decl(f_3658)
static void C_ccall f_3658(C_word c,C_word *av) C_noret;
C_noret_decl(f_3661)
static void C_ccall f_3661(C_word c,C_word *av) C_noret;
C_noret_decl(f_3664)
static void C_ccall f_3664(C_word c,C_word *av) C_noret;
C_noret_decl(f_3667)
static void C_ccall f_3667(C_word c,C_word *av) C_noret;
C_noret_decl(f_3746)
static void C_ccall f_3746(C_word c,C_word *av) C_noret;
C_noret_decl(f_3765)
static void C_ccall f_3765(C_word c,C_word *av) C_noret;
C_noret_decl(f_3768)
static void C_ccall f_3768(C_word c,C_word *av) C_noret;
C_noret_decl(f_3771)
static void C_ccall f_3771(C_word c,C_word *av) C_noret;
C_noret_decl(f_3774)
static void C_ccall f_3774(C_word c,C_word *av) C_noret;
C_noret_decl(f_3777)
static void C_ccall f_3777(C_word c,C_word *av) C_noret;
C_noret_decl(f_3780)
static void C_ccall f_3780(C_word c,C_word *av) C_noret;
C_noret_decl(f_3851)
static void C_ccall f_3851(C_word c,C_word *av) C_noret;
C_noret_decl(f_3855)
static void C_ccall f_3855(C_word c,C_word *av) C_noret;
C_noret_decl(f_3864)
static void C_ccall f_3864(C_word c,C_word *av) C_noret;
C_noret_decl(f_3874)
static void C_ccall f_3874(C_word c,C_word *av) C_noret;
C_noret_decl(f_3891)
static void C_ccall f_3891(C_word c,C_word *av) C_noret;
C_noret_decl(f_3895)
static void C_ccall f_3895(C_word c,C_word *av) C_noret;
C_noret_decl(f_3898)
static void C_ccall f_3898(C_word c,C_word *av) C_noret;
C_noret_decl(f_3908)
static void C_ccall f_3908(C_word c,C_word *av) C_noret;
C_noret_decl(f_3920)
static void C_ccall f_3920(C_word c,C_word *av) C_noret;
C_noret_decl(f_3932)
static void C_ccall f_3932(C_word c,C_word *av) C_noret;
C_noret_decl(f_3975)
static void C_ccall f_3975(C_word c,C_word *av) C_noret;
C_noret_decl(f_3985)
static void C_ccall f_3985(C_word c,C_word *av) C_noret;
C_noret_decl(f_3992)
static void C_ccall f_3992(C_word c,C_word *av) C_noret;
C_noret_decl(f_4003)
static void C_ccall f_4003(C_word c,C_word *av) C_noret;
C_noret_decl(f_4005)
static void C_fcall f_4005(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4023)
static void C_ccall f_4023(C_word c,C_word *av) C_noret;
C_noret_decl(f_4039)
static void C_ccall f_4039(C_word c,C_word *av) C_noret;
C_noret_decl(f_4043)
static void C_ccall f_4043(C_word c,C_word *av) C_noret;
C_noret_decl(f_4046)
static void C_ccall f_4046(C_word c,C_word *av) C_noret;
C_noret_decl(f_4049)
static void C_ccall f_4049(C_word c,C_word *av) C_noret;
C_noret_decl(f_4052)
static void C_ccall f_4052(C_word c,C_word *av) C_noret;
C_noret_decl(f_4055)
static void C_ccall f_4055(C_word c,C_word *av) C_noret;
C_noret_decl(f_4058)
static void C_ccall f_4058(C_word c,C_word *av) C_noret;
C_noret_decl(f_4061)
static void C_ccall f_4061(C_word c,C_word *av) C_noret;
C_noret_decl(f_4064)
static void C_ccall f_4064(C_word c,C_word *av) C_noret;
C_noret_decl(f_4067)
static void C_ccall f_4067(C_word c,C_word *av) C_noret;
C_noret_decl(f_4070)
static void C_ccall f_4070(C_word c,C_word *av) C_noret;
C_noret_decl(f_4073)
static void C_ccall f_4073(C_word c,C_word *av) C_noret;
C_noret_decl(f_4076)
static void C_ccall f_4076(C_word c,C_word *av) C_noret;
C_noret_decl(f_4079)
static void C_ccall f_4079(C_word c,C_word *av) C_noret;
C_noret_decl(f_4082)
static void C_ccall f_4082(C_word c,C_word *av) C_noret;
C_noret_decl(f_4091)
static void C_fcall f_4091(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4105)
static void C_ccall f_4105(C_word c,C_word *av) C_noret;
C_noret_decl(f_4128)
static void C_ccall f_4128(C_word c,C_word *av) C_noret;
C_noret_decl(f_4133)
static C_word C_fcall f_4133(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_4148)
static void C_ccall f_4148(C_word c,C_word *av) C_noret;
C_noret_decl(f_4163)
static void C_ccall f_4163(C_word c,C_word *av) C_noret;
C_noret_decl(f_4211)
static void C_ccall f_4211(C_word c,C_word *av) C_noret;
C_noret_decl(f_4213)
static void C_fcall f_4213(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4273)
static void C_ccall f_4273(C_word c,C_word *av) C_noret;
C_noret_decl(f_4275)
static void C_fcall f_4275(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4312)
static C_word C_fcall f_4312(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_4319)
static void C_ccall f_4319(C_word c,C_word *av) C_noret;
C_noret_decl(f_4321)
static void C_fcall f_4321(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4355)
static void C_fcall f_4355(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4403)
static void C_fcall f_4403(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4457)
static void C_ccall f_4457(C_word c,C_word *av) C_noret;
C_noret_decl(f_4459)
static void C_fcall f_4459(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4527)
static void C_fcall f_4527(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4552)
static void C_ccall f_4552(C_word c,C_word *av) C_noret;
C_noret_decl(f_4569)
static void C_ccall f_4569(C_word c,C_word *av) C_noret;
C_noret_decl(f_4571)
static void C_ccall f_4571(C_word c,C_word *av) C_noret;
C_noret_decl(f_4575)
static void C_ccall f_4575(C_word c,C_word *av) C_noret;
C_noret_decl(f_4578)
static void C_ccall f_4578(C_word c,C_word *av) C_noret;
C_noret_decl(f_4581)
static void C_ccall f_4581(C_word c,C_word *av) C_noret;
C_noret_decl(f_4584)
static void C_ccall f_4584(C_word c,C_word *av) C_noret;
C_noret_decl(f_4587)
static void C_ccall f_4587(C_word c,C_word *av) C_noret;
C_noret_decl(f_4590)
static void C_ccall f_4590(C_word c,C_word *av) C_noret;
C_noret_decl(f_4593)
static void C_ccall f_4593(C_word c,C_word *av) C_noret;
C_noret_decl(f_4596)
static void C_ccall f_4596(C_word c,C_word *av) C_noret;
C_noret_decl(f_4599)
static void C_ccall f_4599(C_word c,C_word *av) C_noret;
C_noret_decl(f_4608)
static void C_fcall f_4608(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4622)
static void C_ccall f_4622(C_word c,C_word *av) C_noret;
C_noret_decl(f_4637)
static void C_ccall f_4637(C_word c,C_word *av) C_noret;
C_noret_decl(f_4642)
static C_word C_fcall f_4642(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_4657)
static void C_ccall f_4657(C_word c,C_word *av) C_noret;
C_noret_decl(f_4672)
static void C_ccall f_4672(C_word c,C_word *av) C_noret;
C_noret_decl(f_4708)
static void C_ccall f_4708(C_word c,C_word *av) C_noret;
C_noret_decl(f_4710)
static void C_fcall f_4710(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4754)
static void C_ccall f_4754(C_word c,C_word *av) C_noret;
C_noret_decl(f_4756)
static void C_fcall f_4756(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4793)
static C_word C_fcall f_4793(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_4800)
static void C_ccall f_4800(C_word c,C_word *av) C_noret;
C_noret_decl(f_4802)
static void C_fcall f_4802(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4836)
static void C_fcall f_4836(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4884)
static void C_fcall f_4884(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4930)
static void C_ccall f_4930(C_word c,C_word *av) C_noret;
C_noret_decl(f_4932)
static void C_fcall f_4932(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_4984)
static void C_fcall f_4984(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5009)
static void C_ccall f_5009(C_word c,C_word *av) C_noret;
C_noret_decl(f_5026)
static void C_ccall f_5026(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_2dsyntax_toplevel)
C_externexport void C_ccall C_compiler_2dsyntax_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_2785)
static void C_ccall trf_2785(C_word c,C_word *av) C_noret;
static void C_ccall trf_2785(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2785(t0,t1);}

C_noret_decl(trf_2997)
static void C_ccall trf_2997(C_word c,C_word *av) C_noret;
static void C_ccall trf_2997(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2997(t0,t1,t2,t3);}

C_noret_decl(trf_3002)
static void C_ccall trf_3002(C_word c,C_word *av) C_noret;
static void C_ccall trf_3002(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3002(t0,t1,t2);}

C_noret_decl(trf_3011)
static void C_ccall trf_3011(C_word c,C_word *av) C_noret;
static void C_ccall trf_3011(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3011(t0,t1,t2);}

C_noret_decl(trf_3068)
static void C_ccall trf_3068(C_word c,C_word *av) C_noret;
static void C_ccall trf_3068(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_3068(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_3096)
static void C_ccall trf_3096(C_word c,C_word *av) C_noret;
static void C_ccall trf_3096(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3096(t0,t1);}

C_noret_decl(trf_3102)
static void C_ccall trf_3102(C_word c,C_word *av) C_noret;
static void C_ccall trf_3102(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3102(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3192)
static void C_ccall trf_3192(C_word c,C_word *av) C_noret;
static void C_ccall trf_3192(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3192(t0,t1);}

C_noret_decl(trf_3211)
static void C_ccall trf_3211(C_word c,C_word *av) C_noret;
static void C_ccall trf_3211(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3211(t0,t1,t2);}

C_noret_decl(trf_3259)
static void C_ccall trf_3259(C_word c,C_word *av) C_noret;
static void C_ccall trf_3259(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3259(t0,t1,t2);}

C_noret_decl(trf_3520)
static void C_ccall trf_3520(C_word c,C_word *av) C_noret;
static void C_ccall trf_3520(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3520(t0,t1,t2);}

C_noret_decl(trf_4005)
static void C_ccall trf_4005(C_word c,C_word *av) C_noret;
static void C_ccall trf_4005(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4005(t0,t1,t2);}

C_noret_decl(trf_4091)
static void C_ccall trf_4091(C_word c,C_word *av) C_noret;
static void C_ccall trf_4091(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4091(t0,t1);}

C_noret_decl(trf_4213)
static void C_ccall trf_4213(C_word c,C_word *av) C_noret;
static void C_ccall trf_4213(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4213(t0,t1,t2);}

C_noret_decl(trf_4275)
static void C_ccall trf_4275(C_word c,C_word *av) C_noret;
static void C_ccall trf_4275(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4275(t0,t1,t2);}

C_noret_decl(trf_4321)
static void C_ccall trf_4321(C_word c,C_word *av) C_noret;
static void C_ccall trf_4321(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4321(t0,t1,t2);}

C_noret_decl(trf_4355)
static void C_ccall trf_4355(C_word c,C_word *av) C_noret;
static void C_ccall trf_4355(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4355(t0,t1,t2,t3);}

C_noret_decl(trf_4403)
static void C_ccall trf_4403(C_word c,C_word *av) C_noret;
static void C_ccall trf_4403(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4403(t0,t1,t2);}

C_noret_decl(trf_4459)
static void C_ccall trf_4459(C_word c,C_word *av) C_noret;
static void C_ccall trf_4459(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4459(t0,t1,t2,t3);}

C_noret_decl(trf_4527)
static void C_ccall trf_4527(C_word c,C_word *av) C_noret;
static void C_ccall trf_4527(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4527(t0,t1,t2);}

C_noret_decl(trf_4608)
static void C_ccall trf_4608(C_word c,C_word *av) C_noret;
static void C_ccall trf_4608(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4608(t0,t1);}

C_noret_decl(trf_4710)
static void C_ccall trf_4710(C_word c,C_word *av) C_noret;
static void C_ccall trf_4710(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4710(t0,t1,t2);}

C_noret_decl(trf_4756)
static void C_ccall trf_4756(C_word c,C_word *av) C_noret;
static void C_ccall trf_4756(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4756(t0,t1,t2);}

C_noret_decl(trf_4802)
static void C_ccall trf_4802(C_word c,C_word *av) C_noret;
static void C_ccall trf_4802(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4802(t0,t1,t2);}

C_noret_decl(trf_4836)
static void C_ccall trf_4836(C_word c,C_word *av) C_noret;
static void C_ccall trf_4836(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4836(t0,t1,t2,t3);}

C_noret_decl(trf_4884)
static void C_ccall trf_4884(C_word c,C_word *av) C_noret;
static void C_ccall trf_4884(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4884(t0,t1,t2);}

C_noret_decl(trf_4932)
static void C_ccall trf_4932(C_word c,C_word *av) C_noret;
static void C_ccall trf_4932(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_4932(t0,t1,t2,t3);}

C_noret_decl(trf_4984)
static void C_ccall trf_4984(C_word c,C_word *av) C_noret;
static void C_ccall trf_4984(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4984(t0,t1,t2);}

/* k1687 */
static void C_ccall f_1689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1689,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1692,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k1690 in k1687 */
static void C_ccall f_1692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1692,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1695,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k1693 in k1690 in k1687 */
static void C_ccall f_1695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1695,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1698,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_1698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1698,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1701,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_support_toplevel(2,av2);}}

/* k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_1701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1701,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1704,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_compiler_toplevel(2,av2);}}

/* k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_1704(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,5)))){
C_save_and_reclaim((void *)f_1704,c,av);}
a=C_alloc(27);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=C_mutate(&lf[2] /* (set! chicken.compiler.compiler-syntax#length+ ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2785,tmp=(C_word)a,a+=2,tmp));
t5=C_set_block_item(lf[3] /* chicken.compiler.compiler-syntax#compiler-syntax-statistics */,0,C_SCHEME_END_OF_LIST);
t6=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#compiler-syntax-hook ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2985,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate(&lf[8] /* (set! chicken.compiler.compiler-syntax#r-c-s ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2997,tmp=(C_word)a,a+=2,tmp));
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3051,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4571,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:71: r-c-s */
f_2997(t8,lf[103],t9,lf[104]);}

/* chicken.compiler.compiler-syntax#length+ in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_2785(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,0,4)))){
C_save_and_reclaim_args((void *)trf_2785,2,t1,t2);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2791,tmp=(C_word)a,a+=2,tmp);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=(
  f_2791(t2,t2,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* lp in chicken.compiler.compiler-syntax#length+ in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static C_word C_fcall f_2791(C_word t1,C_word t2,C_word t3){
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
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t4=C_u_i_cdr(t1);
t5=C_fixnum_plus(t3,C_fix(1));
if(C_truep(C_i_pairp(t4))){
t6=C_u_i_cdr(t4);
t7=C_i_cdr(t2);
t8=C_fixnum_plus(t5,C_fix(1));
t9=C_eqp(t6,t7);
if(C_truep(C_i_not(t9))){
t11=t6;
t12=t7;
t13=t8;
t1=t11;
t2=t12;
t3=t13;
goto loop;}
else{
return(C_SCHEME_FALSE);}}
else{
return(t5);}}
else{
return(t3);}}

/* ##sys#compiler-syntax-hook in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_2985(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_2985,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2989,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* compiler-syntax.scm:52: chicken.base#alist-ref */
t5=*((C_word*)lf[6]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=*((C_word*)lf[3]+1);
av2[4]=*((C_word*)lf[7]+1);
av2[5]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}

/* k2987 in ##sys#compiler-syntax-hook in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_2989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,4)))){
C_save_and_reclaim((void *)f_2989,c,av);}
a=C_alloc(32);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2993,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_s_a_i_plus(&a,2,t1,C_fix(1));
/* compiler-syntax.scm:54: chicken.base#alist-update! */
t4=*((C_word*)lf[5]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=t3;
av2[4]=*((C_word*)lf[3]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k2991 in k2987 in ##sys#compiler-syntax-hook in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_2993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2993,c,av);}
t2=C_mutate((C_word*)lf[3]+1 /* (set! chicken.compiler.compiler-syntax#compiler-syntax-statistics ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_2997(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_2997,4,t1,t2,t3,t4);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3036,a[2]=t1,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3044,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* compiler-syntax.scm:58: ##sys#er-transformer */
t7=*((C_word*)lf[14]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* g551 in k3038 in k3034 in chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3002(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_3002,3,t0,t1,t2);}
/* compiler-syntax.scm:63: ##sys#put! */
t3=*((C_word*)lf[9]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[10];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* for-each-loop550 in k3038 in k3034 in chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3011(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3011,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3021,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:61: g551 */
t4=((C_word*)t0)[3];
f_3002(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3019 in for-each-loop550 in k3038 in k3034 in chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3021(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3021,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3011(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k3034 in chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3036(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3036,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3040,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:60: scheme#append */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=*((C_word*)lf[12]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3038 in k3034 in chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3040(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_3040,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3002,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3011,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_3011(t7,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k3042 in chicken.compiler.compiler-syntax#r-c-s in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3044,c,av);}
/* compiler-syntax.scm:57: ##sys#ensure-transformer */
t2=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3051(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_3051,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3054,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4039,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:101: r-c-s */
f_2997(t2,lf[98],t3,lf[99]);}

/* k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_3054,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3057,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3975,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:143: r-c-s */
f_2997(t2,lf[86],t3,C_SCHEME_END_OF_LIST);}

/* k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3057(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(41,c,5)))){
C_save_and_reclaim((void *)f_3057,c,av);}
a=C_alloc(41);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3060,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3891,tmp=(C_word)a,a+=2,tmp);
t4=C_a_i_cons(&a,2,lf[75],lf[76]);
t5=C_a_i_cons(&a,2,lf[77],lf[78]);
t6=C_a_i_cons(&a,2,lf[38],lf[79]);
t7=C_a_i_cons(&a,2,lf[80],lf[81]);
t8=C_a_i_cons(&a,2,lf[72],lf[26]);
t9=C_a_i_cons(&a,2,lf[71],lf[19]);
t10=C_a_i_list(&a,6,t4,t5,t6,t7,t8,t9);
/* compiler-syntax.scm:150: r-c-s */
f_2997(t2,lf[82],t3,t10);}

/* k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_3060,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3063,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3864,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:167: r-c-s */
f_2997(t2,lf[69],t3,lf[70]);}

/* k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3063(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_3063,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3066,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3851,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:179: r-c-s */
f_2997(t2,lf[66],t3,lf[67]);}

/* k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3066(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,8)))){
C_save_and_reclaim((void *)f_3066,c,av);}
a=C_alloc(7);
t2=C_mutate(&lf[15] /* (set! chicken.compiler.compiler-syntax#compile-format-string ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3068,tmp=(C_word)a,a+=2,tmp));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3625,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3746,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:278: r-c-s */
f_2997(t3,lf[62],t4,lf[63]);}

/* chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3068(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7){
C_word tmp;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_3068,7,t1,t2,t3,t4,t5,t6,t7);}
a=C_alloc(8);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3074,a[2]=t5,a[3]=t2,a[4]=t4,a[5]=t3,a[6]=t6,a[7]=t7,tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:190: chicken.base#call/cc */
t9=*((C_word*)lf[44]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t1;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3074(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3074,c,av);}
a=C_alloc(10);
t3=C_i_length(((C_word*)t0)[2]);
if(C_truep(C_fixnum_greater_or_equal_p(t3,C_fix(1)))){
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3617,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t1,a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
/* compiler-syntax.scm:193: chicken.base#symbol-append */
t5=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[43];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3096(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_3096,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3099,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_stringp(C_u_i_car(((C_word*)t0)[2])))){
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_u_i_car(((C_word*)t0)[2]);
f_3099(2,av2);}}
else{
/* compiler-syntax.scm:198: scheme#cadar */
t3=*((C_word*)lf[41]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=((C_word*)t0)[7];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3099(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,5)))){
C_save_and_reclaim((void *)f_3099,c,av);}
a=C_alloc(24);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3102,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t5=C_SCHEME_END_OF_LIST;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_fix(0);
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_i_string_length(t1);
t10=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3174,a[2]=t1,a[3]=t8,a[4]=t3,a[5]=t4,a[6]=t6,a[7]=t9,a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],tmp=(C_word)a,a+=12,tmp);
/* compiler-syntax.scm:211: r */
t11=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t10;
av2[2]=lf[40];
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}

/* fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3102(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_3102,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3106,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t3,a[6]=t4,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:201: chicken.syntax#get-line-number */
t6=*((C_word*)lf[28]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3106(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3106,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3109,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3119,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:203: chicken.base#open-output-string */
t4=*((C_word*)lf[26]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3107 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3109,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* compiler-syntax.scm:207: return */
t2=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_3119,c,av);}
a=C_alloc(16);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[17]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3125,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3150,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[7])){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3153,a[2]=t4,a[3]=((C_word*)t0)[7],tmp=(C_word)a,a+=4,tmp);
/* compiler-syntax.scm:204: chicken.base#open-output-string */
t6=*((C_word*)lf[26]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* compiler-syntax.scm:203: ##sys#print */
t5=*((C_word*)lf[21]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[27];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3125(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3125,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3128,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:203: ##sys#write-char-0 */
t3=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(96);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_3128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3128,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3131,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:203: ##sys#print */
t3=*((C_word*)lf[21]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3129 in k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3131,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3134,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:203: ##sys#print */
t3=*((C_word*)lf[21]+1);{
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
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3132 in k3129 in k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_ccall f_3134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3134,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3137,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:203: ##sys#print */
t3=*((C_word*)lf[21]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3135 in k3132 in k3129 in k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in ... */
static void C_ccall f_3137(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3137,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3140,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:203: ##sys#print */
t3=*((C_word*)lf[21]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[22];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3138 in k3135 in k3132 in k3129 in k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in ... */
static void C_ccall f_3140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3140,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3143,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=t2;
av2[2]=*((C_word*)lf[20]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
C_apply(6,av2);}}

/* k3141 in k3138 in k3135 in k3132 in k3129 in k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in ... */
static void C_ccall f_3143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3143,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3146,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* compiler-syntax.scm:203: chicken.base#get-output-string */
t3=*((C_word*)lf[19]+1);{
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

/* k3144 in k3141 in k3138 in k3135 in k3132 in k3129 in k3126 in k3123 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in ... */
static void C_ccall f_3146(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3146,c,av);}
/* compiler-syntax.scm:202: chicken.base#warning */
t2=*((C_word*)lf[18]+1);{
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

/* k3148 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3150,c,av);}
/* compiler-syntax.scm:203: ##sys#print */
t2=*((C_word*)lf[21]+1);{
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

/* k3151 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3153,c,av);}
a=C_alloc(5);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[17]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3159,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:204: ##sys#write-char-0 */
t4=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_make_character(40);
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3157 in k3151 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_3159(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3159,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3162,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* compiler-syntax.scm:204: ##sys#print */
t3=*((C_word*)lf[21]+1);{
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

/* k3160 in k3157 in k3151 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3162(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3162,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3165,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* compiler-syntax.scm:204: ##sys#print */
t3=*((C_word*)lf[21]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[25];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3163 in k3160 in k3157 in k3151 in k3117 in k3104 in fail in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_ccall f_3165(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3165,c,av);}
/* compiler-syntax.scm:204: chicken.base#get-output-string */
t2=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3174(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3174,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_3177,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* compiler-syntax.scm:212: r */
t3=((C_word*)t0)[11];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[39];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3177(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3177,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_3180,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t1,a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* compiler-syntax.scm:213: r */
t3=((C_word*)t0)[12];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[38];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3180(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,3)))){
C_save_and_reclaim((void *)f_3180,c,av);}
a=C_alloc(42);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3182,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp));
t11=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3192,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp));
t12=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3211,a[2]=((C_word*)t0)[6],a[3]=t9,tmp=(C_word)a,a+=4,tmp));
t13=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3249,a[2]=((C_word*)t0)[7],tmp=(C_word)a,a+=3,tmp));
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_3259,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[7],a[9]=t7,a[10]=((C_word*)t0)[4],a[11]=((C_word*)t0)[5],a[12]=t3,a[13]=t15,a[14]=t9,a[15]=t5,a[16]=t1,tmp=(C_word)a,a+=17,tmp));
t17=((C_word*)t15)[1];
f_3259(t17,((C_word*)t0)[12],C_SCHEME_END_OF_LIST);}

/* fetch in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static C_word C_fcall f_3182(C_word t0){
C_word tmp;
C_word t1;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t1=C_i_string_ref(((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t2=C_fixnum_plus(((C_word*)((C_word*)t0)[3])[1],C_fix(1));
t3=C_set_block_item(((C_word*)t0)[3],0,t2);
return(t1);}

/* next in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3192(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_3192,2,t0,t1);}
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[2])[1]))){
/* compiler-syntax.scm:220: fail */
t2=((C_word*)t0)[3];
f_3102(t2,t1,C_SCHEME_TRUE,lf[29],C_SCHEME_END_OF_LIST);}
else{
t2=C_i_car(((C_word*)((C_word*)t0)[2])[1]);
t3=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* endchunk in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3211(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_3211,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_i_length(t2);
t4=C_eqp(C_fix(1),t3);
if(C_truep(t4)){
t5=C_i_car(t2);
t6=C_a_i_list(&a,3,lf[24],t5,((C_word*)t0)[2]);
/* compiler-syntax.scm:226: push */
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=(
/* compiler-syntax.scm:226: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[3])[1],t6)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3242,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:229: ##sys#reverse-list->string */
t6=*((C_word*)lf[30]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3240 in endchunk in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_3242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_3242,c,av);}
a=C_alloc(15);
t2=C_a_i_list(&a,4,lf[21],t1,C_SCHEME_FALSE,((C_word*)t0)[2]);
/* compiler-syntax.scm:226: push */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
/* compiler-syntax.scm:226: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[4])[1],t2)
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* push in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static C_word C_fcall f_3249(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_a_i_cons(&a,2,t1,((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
return(t3);}

/* loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_3259(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_3259,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_greater_or_equalp(((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]))){
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3269,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=t2,tmp=(C_word)a,a+=10,tmp);
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[10])[1]))){
t4=t3;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_3269(2,av2);}}
else{
/* compiler-syntax.scm:235: fail */
t4=((C_word*)t0)[11];
f_3102(t4,t3,C_SCHEME_FALSE,lf[34],C_SCHEME_END_OF_LIST);}}
else{
t3=(
/* compiler-syntax.scm:241: fetch */
  f_3182(((C_word*)((C_word*)t0)[12])[1])
);
t4=C_eqp(t3,C_make_character(126));
if(C_truep(t4)){
t5=(
/* compiler-syntax.scm:243: fetch */
  f_3182(((C_word*)((C_word*)t0)[12])[1])
);
t6=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3324,a[2]=t5,a[3]=((C_word*)t0)[13],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[14],a[7]=((C_word*)t0)[15],a[8]=((C_word*)t0)[16],a[9]=((C_word*)t0)[12],a[10]=((C_word*)t0)[2],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* compiler-syntax.scm:244: endchunk */
t7=((C_word*)((C_word*)t0)[9])[1];
f_3211(t7,t6,t2);}
else{
t5=C_a_i_cons(&a,2,t3,t2);
/* compiler-syntax.scm:276: loop */
t8=t1;
t9=t5;
t1=t8;
t2=t9;
goto loop;}}}

/* k3267 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_3269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3269,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3272,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:236: endchunk */
t3=((C_word*)((C_word*)t0)[8])[1];
f_3211(t3,t2,((C_word*)t0)[9]);}

/* k3270 in k3267 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3272(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,2)))){
C_save_and_reclaim((void *)f_3272,c,av);}
a=C_alloc(33);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[31],((C_word*)t0)[4]);
t5=C_a_i_list(&a,4,lf[32],((C_word*)t0)[2],C_SCHEME_TRUE,t4);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3295,a[2]=t5,a[3]=t3,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:239: scheme#reverse */
t7=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)((C_word*)t0)[7])[1];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k3293 in k3270 in k3267 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_ccall f_3295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_3295,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_3324(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_3324,c,av);}
a=C_alloc(16);
t2=C_u_i_char_upcase(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3330,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
switch(t2){
case C_make_character(83):
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3347,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:246: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(65):
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3364,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:247: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(67):
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3381,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:248: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(66):
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3402,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:251: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(79):
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3423,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:255: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(88):
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3444,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:259: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(33):
t4=C_a_i_list(&a,2,lf[35],((C_word*)t0)[5]);
t5=(
/* compiler-syntax.scm:261: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[6])[1],t4)
);
/* compiler-syntax.scm:275: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_3259(t6,((C_word*)t0)[4],C_SCHEME_END_OF_LIST);
case C_make_character(63):
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3466,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:263: next */
t5=((C_word*)((C_word*)t0)[7])[1];
f_3192(t5,t4);
case C_make_character(126):
t4=C_a_i_list(&a,3,lf[24],C_make_character(126),((C_word*)t0)[5]);
t5=(
/* compiler-syntax.scm:266: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[6])[1],t4)
);
/* compiler-syntax.scm:275: loop */
t6=((C_word*)((C_word*)t0)[3])[1];
f_3259(t6,((C_word*)t0)[4],C_SCHEME_END_OF_LIST);
default:
t4=C_eqp(t2,C_make_character(37));
t5=(C_truep(t4)?t4:C_eqp(t2,C_make_character(78)));
if(C_truep(t5)){
t6=C_a_i_list(&a,3,lf[24],C_make_character(10),((C_word*)t0)[5]);
/* compiler-syntax.scm:267: push */
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=(
/* compiler-syntax.scm:267: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[6])[1],t6)
);
f_3330(2,av2);}}
else{
if(C_truep(C_u_i_char_whitespacep(((C_word*)t0)[2]))){
t6=(
/* compiler-syntax.scm:270: fetch */
  f_3182(((C_word*)((C_word*)t0)[9])[1])
);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3520,a[2]=((C_word*)t0)[9],a[3]=t8,a[4]=((C_word*)t0)[10],tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_3520(t10,t3,t6);}
else{
/* compiler-syntax.scm:274: fail */
t6=((C_word*)t0)[11];
f_3102(t6,t3,C_SCHEME_TRUE,lf[37],C_a_i_list(&a,1,((C_word*)t0)[2]));}}}}

/* k3328 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3330,c,av);}
/* compiler-syntax.scm:275: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3259(t2,((C_word*)t0)[3],C_SCHEME_END_OF_LIST);}

/* k3345 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3347,c,av);}
a=C_alloc(15);
t2=C_a_i_list(&a,4,lf[21],t1,C_SCHEME_TRUE,((C_word*)t0)[2]);
t3=(
/* compiler-syntax.scm:246: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[3])[1],t2)
);
/* compiler-syntax.scm:275: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_3259(t4,((C_word*)t0)[5],C_SCHEME_END_OF_LIST);}

/* k3362 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3364(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3364,c,av);}
a=C_alloc(15);
t2=C_a_i_list(&a,4,lf[21],t1,C_SCHEME_FALSE,((C_word*)t0)[2]);
t3=(
/* compiler-syntax.scm:247: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[3])[1],t2)
);
/* compiler-syntax.scm:275: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_3259(t4,((C_word*)t0)[5],C_SCHEME_END_OF_LIST);}

/* k3379 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3381(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_3381,c,av);}
a=C_alloc(12);
t2=C_a_i_list(&a,3,lf[24],t1,((C_word*)t0)[2]);
t3=(
/* compiler-syntax.scm:248: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[3])[1],t2)
);
/* compiler-syntax.scm:275: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_3259(t4,((C_word*)t0)[5],C_SCHEME_END_OF_LIST);}

/* k3400 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3402(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_3402,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,3,((C_word*)t0)[2],t1,C_fix(2));
t3=C_a_i_list(&a,4,lf[21],t2,C_SCHEME_FALSE,((C_word*)t0)[3]);
t4=(
/* compiler-syntax.scm:250: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[4])[1],t3)
);
/* compiler-syntax.scm:275: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_3259(t5,((C_word*)t0)[6],C_SCHEME_END_OF_LIST);}

/* k3421 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_3423,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,3,((C_word*)t0)[2],t1,C_fix(8));
t3=C_a_i_list(&a,4,lf[21],t2,C_SCHEME_FALSE,((C_word*)t0)[3]);
t4=(
/* compiler-syntax.scm:254: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[4])[1],t3)
);
/* compiler-syntax.scm:275: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_3259(t5,((C_word*)t0)[6],C_SCHEME_END_OF_LIST);}

/* k3442 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3444(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_3444,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,3,((C_word*)t0)[2],t1,C_fix(16));
t3=C_a_i_list(&a,4,lf[21],t2,C_SCHEME_FALSE,((C_word*)t0)[3]);
t4=(
/* compiler-syntax.scm:258: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[4])[1],t3)
);
/* compiler-syntax.scm:275: loop */
t5=((C_word*)((C_word*)t0)[5])[1];
f_3259(t5,((C_word*)t0)[6],C_SCHEME_END_OF_LIST);}

/* k3464 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_3466(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3466,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3469,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:264: next */
t3=((C_word*)((C_word*)t0)[6])[1];
f_3192(t3,t2);}

/* k3467 in k3464 in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_ccall f_3469(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_3469,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,5,lf[36],lf[20],((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=(
/* compiler-syntax.scm:265: push */
  f_3249(C_a_i(&a,3),((C_word*)((C_word*)t0)[4])[1],t2)
);
/* compiler-syntax.scm:275: loop */
t4=((C_word*)((C_word*)t0)[5])[1];
f_3259(t4,((C_word*)t0)[6],C_SCHEME_END_OF_LIST);}

/* skip in k3322 in loop in k3178 in k3175 in k3172 in k3097 in k3094 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_fcall f_3520(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(29,0,2)))){
C_save_and_reclaim_args((void *)trf_3520,3,t0,t1,t2);}
a=C_alloc(29);
if(C_truep(C_u_i_char_whitespacep(t2))){
t3=(
/* compiler-syntax.scm:272: fetch */
  f_3182(((C_word*)((C_word*)t0)[2])[1])
);
/* compiler-syntax.scm:272: skip */
t6=t1;
t7=t3;
t1=t6;
t2=t7;
goto loop;}
else{
t3=((C_word*)((C_word*)t0)[4])[1];
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,C_s_a_i_minus(&a,2,t3,C_fix(1)));
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k3590 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3592(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3592,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3599,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* compiler-syntax.scm:197: scheme#cadar */
t3=*((C_word*)lf[41]+1);{
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
else{
t2=((C_word*)t0)[2];
f_3096(t2,C_SCHEME_FALSE);}}

/* k3597 in k3590 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3599,c,av);}
t2=((C_word*)t0)[2];
f_3096(t2,C_i_stringp(t1));}

/* k3601 in k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3603,c,av);}
/* compiler-syntax.scm:196: c */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=C_i_caar(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3615 in a3073 in chicken.compiler.compiler-syntax#compile-format-string in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3617(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_3617,c,av);}
a=C_alloc(18);
if(C_truep(C_i_memq(t1,*((C_word*)lf[16]+1)))){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_stringp(t2);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3096,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(t3)){
t5=t4;
f_3096(t5,t3);}
else{
if(C_truep(C_i_listp(C_u_i_car(((C_word*)t0)[2])))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3592,a[2]=t4,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3603,a[2]=((C_word*)t0)[9],a[3]=t5,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:196: r */
t7=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[31];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t5=t4;
f_3096(t5,C_SCHEME_FALSE);}}}
else{
t2=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_3625,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3628,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3630,tmp=(C_word)a,a+=2,tmp);
/* compiler-syntax.scm:300: r-c-s */
f_2997(t2,lf[57],t3,lf[58]);}

/* k3626 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3628(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3628,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3630(C_word c,C_word *av){
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
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3630,c,av);}
a=C_alloc(7);
t5=C_i_length(t2);
t6=C_eqp(t5,C_fix(4));
t7=(C_truep(t6)?C_i_memq(lf[45],*((C_word*)lf[16]+1)):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=C_i_cadr(t2);
t9=C_i_caddr(t2);
t10=C_i_cadddr(t2);
t11=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3649,a[2]=t9,a[3]=t10,a[4]=t8,a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:307: r */
t12=t3;{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
av2[2]=lf[56];
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3649,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3652,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:308: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[39];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3650 in k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3652,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3655,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:309: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[55];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3653 in k3650 in k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3655,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3658,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:310: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[54];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3656 in k3653 in k3650 in k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3658,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3661,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* compiler-syntax.scm:311: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3659 in k3656 in k3653 in k3650 in k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3661,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3664,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* compiler-syntax.scm:312: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[53];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3662 in k3659 in k3656 in k3653 in k3650 in k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3664(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_3664,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3667,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* compiler-syntax.scm:313: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3665 in k3662 in k3659 in k3656 in k3653 in k3650 in k3647 in a3629 in k3623 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3667(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(138,c,1)))){
C_save_and_reclaim((void *)f_3667,c,av);}
a=C_alloc(138);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list(&a,2,t1,((C_word*)t0)[4]);
t4=C_a_i_list(&a,2,t2,t3);
t5=C_a_i_list(&a,2,lf[46],lf[47]);
t6=C_a_i_list(&a,3,lf[48],t1,t5);
t7=C_a_i_list(&a,2,lf[49],t6);
t8=C_a_i_list(&a,2,t1,t1);
t9=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[2]);
t10=C_a_i_list(&a,2,t8,t9);
t11=C_a_i_list(&a,2,((C_word*)t0)[5],t1);
t12=C_a_i_list(&a,3,lf[50],t1,C_fix(1));
t13=C_a_i_list(&a,3,lf[50],t1,C_fix(0));
t14=C_a_i_list(&a,3,((C_word*)t0)[6],((C_word*)t0)[2],t13);
t15=C_a_i_list(&a,4,lf[51],((C_word*)t0)[7],t12,t14);
t16=C_a_i_list(&a,4,((C_word*)t0)[8],t11,t15,((C_word*)t0)[2]);
t17=C_a_i_list(&a,4,((C_word*)t0)[9],((C_word*)t0)[7],t10,t16);
t18=((C_word*)t0)[10];{
C_word *av2=av;
av2[0]=t18;
av2[1]=C_a_i_list(&a,4,((C_word*)t0)[11],t4,t7,t17);
((C_proc)(void*)(*((C_word*)t18+1)))(2,av2);}}

/* a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3746(C_word c,C_word *av){
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
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3746,c,av);}
a=C_alloc(7);
t5=C_i_length(t2);
t6=C_eqp(t5,C_fix(4));
t7=(C_truep(t6)?C_i_memq(lf[59],*((C_word*)lf[16]+1)):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=C_i_cadr(t2);
t9=C_i_caddr(t2);
t10=C_i_cadddr(t2);
t11=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3765,a[2]=t10,a[3]=t8,a[4]=t9,a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:285: r */
t12=t3;{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
av2[2]=lf[56];
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3763 in a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3765,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3768,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:286: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[39];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3766 in k3763 in a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3768(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3768,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3771,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:287: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[54];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3769 in k3766 in k3763 in a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3771,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3774,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:288: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[55];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3772 in k3769 in k3766 in k3763 in a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3774,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3777,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* compiler-syntax.scm:289: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[61];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3775 in k3772 in k3769 in k3766 in k3763 in a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3777,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3780,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* compiler-syntax.scm:290: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in a3745 in k3064 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3780(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(117,c,1)))){
C_save_and_reclaim((void *)f_3780,c,av);}
a=C_alloc(117);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[46],lf[60]);
t5=C_a_i_list(&a,3,lf[48],t1,t4);
t6=C_a_i_list(&a,2,lf[49],t5);
t7=C_a_i_list(&a,2,t1,t1);
t8=C_a_i_list(&a,1,t7);
t9=C_a_i_list(&a,2,((C_word*)t0)[3],t1);
t10=C_a_i_list(&a,3,lf[50],t1,C_fix(0));
t11=C_a_i_list(&a,3,lf[50],t1,C_fix(1));
t12=C_a_i_list(&a,3,lf[51],((C_word*)t0)[4],t11);
t13=C_a_i_list(&a,3,((C_word*)t0)[5],t10,t12);
t14=C_a_i_list(&a,4,((C_word*)t0)[6],t9,t13,((C_word*)t0)[7]);
t15=C_a_i_list(&a,4,((C_word*)t0)[8],((C_word*)t0)[4],t8,t14);
t16=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t16;
av2[1]=C_a_i_list(&a,4,((C_word*)t0)[10],t3,t6,t15);
((C_proc)(void*)(*((C_word*)t16+1)))(2,av2);}}

/* a3850 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3851(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,7)))){
C_save_and_reclaim((void *)f_3851,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3855,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* compiler-syntax.scm:186: compile-format-string */
f_3068(t5,lf[64],lf[65],t2,C_i_cdr(t2),t3,t4);}

/* k3853 in a3850 in k3061 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3855,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?t1:((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a3863 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3864(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,7)))){
C_save_and_reclaim((void *)f_3864,c,av);}
a=C_alloc(4);
t5=C_i_length(t2);
if(C_truep(C_fixnum_greater_or_equal_p(t5,C_fix(3)))){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3874,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t7=C_i_cadr(t2);
t8=C_u_i_cdr(t2);
/* compiler-syntax.scm:175: compile-format-string */
f_3068(t6,lf[68],t7,t2,C_u_i_cdr(t8),t3,t4);}
else{
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k3872 in a3863 in k3058 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3874,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?t1:((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a3890 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3891,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3895,a[2]=t1,a[3]=t3,a[4]=t2,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:157: chicken.base#gensym */
t6=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[40];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3893 in a3890 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,7)))){
C_save_and_reclaim((void *)f_3895,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3898,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=C_i_car(((C_word*)t0)[4]);
t4=C_eqp(t3,lf[73]);
t5=(C_truep(t4)?lf[74]:lf[17]);
/* compiler-syntax.scm:158: compile-format-string */
f_3068(t2,t5,t1,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[3],((C_word*)t0)[5]);}

/* k3896 in k3893 in a3890 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3898,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3908,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:162: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[39];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3906 in k3896 in k3893 in a3890 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3908,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3932,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:162: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[72];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3918 in k3930 in k3906 in k3896 in k3893 in a3890 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3920(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_3920,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,4,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3930 in k3906 in k3896 in k3893 in a3890 in k3055 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_3932,c,av);}
a=C_alloc(19);
t2=C_a_i_list(&a,1,t1);
t3=C_a_i_list(&a,2,((C_word*)t0)[2],t2);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3920,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t4,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:164: r */
t6=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[71];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* a3974 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3975(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3975,c,av);}
a=C_alloc(5);
t5=C_i_length(t2);
t6=C_fixnum_greaterp(t5,C_fix(1));
t7=(C_truep(t6)?C_i_memq(lf[83],*((C_word*)lf[16]+1)):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3985,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:146: r */
t9=t3;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[85];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3983 in a3974 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3985(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3985,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3992,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:147: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[84];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3990 in k3983 in a3974 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_3992(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_3992,c,av);}
a=C_alloc(14);
t2=C_a_i_list(&a,1,((C_word*)t0)[2]);
t3=C_i_cdr(((C_word*)t0)[3]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4003,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4005,a[2]=t6,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_4005(t8,t4,t3);}

/* k4001 in k3990 in k3983 in a3974 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_4003,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* foldr1081 in k3990 in k3983 in a3974 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_4005(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_4005,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4023,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t6=t4;
t7=C_slot(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4021 in foldr1081 in k3990 in k3983 in a3974 in k3052 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4023(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4023,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4039(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4039,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4043,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:103: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[39];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4043(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4043,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4046,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:104: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[55];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4046,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4049,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:105: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[97];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4049,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4052,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:106: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4052,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4055,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:107: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[96];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4055(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4055,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4058,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* compiler-syntax.scm:108: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[95];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4058(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4058,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4061,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* compiler-syntax.scm:109: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4061(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_4061,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4064,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* compiler-syntax.scm:110: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4064(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_4064,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4067,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* compiler-syntax.scm:111: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_4067,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_4070,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* compiler-syntax.scm:112: r */
t3=((C_word*)t0)[12];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[31];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4070(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_4070,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_4073,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
/* compiler-syntax.scm:113: r */
t3=((C_word*)t0)[13];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[94];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_4073,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_4076,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],tmp=(C_word)a,a+=15,tmp);
/* compiler-syntax.scm:114: r */
t3=((C_word*)t0)[14];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[84];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_4076,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_4079,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],tmp=(C_word)a,a+=15,tmp);
/* compiler-syntax.scm:115: r */
t3=((C_word*)t0)[14];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[93];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_4079,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_4082,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
/* compiler-syntax.scm:116: r */
t3=((C_word*)t0)[14];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[54];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_4082(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,2)))){
C_save_and_reclaim((void *)f_4082,c,av);}
a=C_alloc(20);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4091,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=t1,a[12]=((C_word*)t0)[10],a[13]=((C_word*)t0)[11],a[14]=((C_word*)t0)[12],a[15]=((C_word*)t0)[13],a[16]=((C_word*)t0)[14],tmp=(C_word)a,a+=17,tmp);
if(C_truep(C_i_memq(lf[91],*((C_word*)lf[92]+1)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4569,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* compiler-syntax.scm:119: length+ */
f_2785(t4,((C_word*)t0)[2]);}
else{
t4=t3;
f_4091(t4,C_SCHEME_FALSE);}}

/* k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_fcall f_4091(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,0,3)))){
C_save_and_reclaim_args((void *)trf_4091,2,t0,t1);}
a=C_alloc(29);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[87]);
t7=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4105,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[2],tmp=(C_word)a,a+=17,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4527,a[2]=t4,a[3]=t9,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_4527(t11,t7,((C_word*)t0)[2]);}
else{
t2=((C_word*)t0)[10];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_ccall f_4105(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(70,c,4)))){
C_save_and_reclaim((void *)f_4105,c,av);}
a=C_alloc(70);
t2=C_a_i_list(&a,1,lf[88]);
t3=C_a_i_list(&a,2,((C_word*)t0)[2],C_SCHEME_END_OF_LIST);
t4=C_a_i_list(&a,3,((C_word*)t0)[3],t2,t3);
t5=C_a_i_list(&a,2,((C_word*)t0)[4],t4);
t6=C_a_i_list(&a,1,t5);
t7=C_a_i_list(&a,2,((C_word*)t0)[5],((C_word*)t0)[4]);
t8=C_i_cadr(((C_word*)t0)[6]);
t9=C_a_i_list(&a,2,((C_word*)t0)[7],t8);
t10=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t11=t10;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=((C_word*)t12)[1];
t14=C_i_check_list_2(t1,lf[87]);
t15=(*a=C_CLOSURE_TYPE|18,a[1]=(C_word)f_4457,a[2]=t9,a[3]=t7,a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],a[6]=t6,a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[3],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[4],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[5],a[17]=((C_word*)t0)[15],a[18]=t1,tmp=(C_word)a,a+=19,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4459,a[2]=t12,a[3]=t17,a[4]=t13,tmp=(C_word)a,a+=5,tmp));
t19=((C_word*)t17)[1];
f_4459(t19,t15,t1,((C_word*)t0)[16]);}

/* k4126 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in ... */
static void C_ccall f_4128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_4128,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* g923 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in ... */
static C_word C_fcall f_4133(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_a_i_list(&a,2,((C_word*)t0)[2],lf[87]);
t3=C_a_i_list(&a,3,lf[48],t1,t2);
return(C_a_i_list(&a,2,lf[49],t3));}

/* k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in ... */
static void C_ccall f_4148(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,4)))){
C_save_and_reclaim((void *)f_4148,c,av);}
a=C_alloc(29);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4163,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=t1,a[16]=((C_word*)t0)[15],tmp=(C_word)a,a+=17,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4355,a[2]=t4,a[3]=t8,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_4355(t10,t6,((C_word*)t0)[15],((C_word*)t0)[15]);}

/* k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in ... */
static void C_ccall f_4163(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_4163,c,av);}
a=C_alloc(33);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4312,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4319,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=t1,a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4321,a[2]=t6,a[3]=t4,a[4]=t9,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_4321(t11,t7,((C_word*)t0)[16]);}

/* k4209 in k4271 in k4317 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in ... */
static void C_ccall f_4211(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(57,c,3)))){
C_save_and_reclaim((void *)f_4211,c,av);}
a=C_alloc(57);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[51],t2);
t4=C_a_i_list(&a,5,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],t3);
t5=C_a_i_list(&a,3,lf[50],((C_word*)t0)[7],C_fix(1));
t6=C_a_i_list(&a,4,((C_word*)t0)[8],((C_word*)t0)[9],t4,t5);
t7=C_a_i_list(&a,4,((C_word*)t0)[3],((C_word*)t0)[2],((C_word*)t0)[10],t6);
t8=C_a_i_list(&a,1,t7);
/* compiler-syntax.scm:121: ##sys#append */
t9=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t9;
av2[1]=((C_word*)t0)[11];
av2[2]=((C_word*)t0)[12];
av2[3]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* map-loop1038 in k4271 in k4317 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in ... */
static void C_fcall f_4213(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_4213,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,3,lf[50],t3,C_fix(1));
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

/* k4271 in k4317 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in ... */
static void C_ccall f_4273(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(73,c,3)))){
C_save_and_reclaim((void *)f_4273,c,av);}
a=C_alloc(73);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list(&a,2,((C_word*)t0)[3],C_SCHEME_END_OF_LIST);
t4=C_a_i_list(&a,3,((C_word*)t0)[4],t2,t3);
t5=C_a_i_list(&a,2,((C_word*)t0)[5],t4);
t6=C_a_i_list(&a,1,t5);
t7=C_a_i_list(&a,4,lf[89],((C_word*)t0)[6],C_fix(1),((C_word*)t0)[5]);
t8=C_a_i_list(&a,3,((C_word*)t0)[7],((C_word*)t0)[6],((C_word*)t0)[5]);
t9=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t10=t9;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=((C_word*)t11)[1];
t13=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4211,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[9],a[4]=t6,a[5]=t7,a[6]=t8,a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[12],a[10]=((C_word*)t0)[13],a[11]=((C_word*)t0)[14],a[12]=((C_word*)t0)[15],tmp=(C_word)a,a+=13,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4213,a[2]=t11,a[3]=t15,a[4]=t12,tmp=(C_word)a,a+=5,tmp));
t17=((C_word*)t15)[1];
f_4213(t17,t13,((C_word*)t0)[16]);}

/* map-loop1008 in k4317 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in ... */
static void C_fcall f_4275(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_4275,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,3,lf[50],t3,C_fix(0));
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

/* g984 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in ... */
static C_word C_fcall f_4312(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_a_i_list(&a,2,((C_word*)t0)[2],t1));}

/* k4317 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in ... */
static void C_ccall f_4319(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(32,c,3)))){
C_save_and_reclaim((void *)f_4319,c,av);}
a=C_alloc(32);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4273,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=t2,a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4275,a[2]=t5,a[3]=t9,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_4275(t11,t7,((C_word*)t0)[16]);}

/* map-loop978 in k4161 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in ... */
static void C_fcall f_4321(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_4321,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(
/* compiler-syntax.scm:129: g984 */
  f_4312(C_a_i(&a,6),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
);
t4=C_a_i_cons(&a,2,t3,C_SCHEME_END_OF_LIST);
t5=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t4);
t6=C_mutate(((C_word *)((C_word*)t0)[3])+1,t4);
t8=t1;
t9=C_slot(t2,C_fix(1));
t1=t8;
t2=t9;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* map-loop947 in k4146 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in ... */
static void C_fcall f_4355(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4355,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list2(&a,2,t6,t7);
t9=C_a_i_cons(&a,2,t8,C_SCHEME_END_OF_LIST);
t10=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t9);
t11=C_mutate(((C_word *)((C_word*)t0)[2])+1,t9);
t13=t1;
t14=C_slot(t2,C_fix(1));
t15=C_slot(t3,C_fix(1));
t1=t13;
t2=t14;
t3=t15;
goto loop;}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* map-loop917 in k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in ... */
static void C_fcall f_4403(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,0,2)))){
C_save_and_reclaim_args((void *)trf_4403,3,t0,t1,t2);}
a=C_alloc(24);
if(C_truep(C_i_pairp(t2))){
t3=(
/* compiler-syntax.scm:125: g923 */
  f_4133(C_a_i(&a,21),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
);
t4=C_a_i_cons(&a,2,t3,C_SCHEME_END_OF_LIST);
t5=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t4);
t6=C_mutate(((C_word *)((C_word*)t0)[3])+1,t4);
t8=t1;
t9=C_slot(t2,C_fix(1));
t1=t8;
t2=t9;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4455 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in ... */
static void C_ccall f_4457(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(44,c,3)))){
C_save_and_reclaim((void *)f_4457,c,av);}
a=C_alloc(44);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4128,a[2]=t3,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4133,a[2]=((C_word*)t0)[7],tmp=(C_word)a,a+=3,tmp);
t10=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_4148,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[11],a[7]=((C_word*)t0)[12],a[8]=((C_word*)t0)[13],a[9]=((C_word*)t0)[14],a[10]=((C_word*)t0)[15],a[11]=((C_word*)t0)[4],a[12]=((C_word*)t0)[16],a[13]=((C_word*)t0)[17],a[14]=t4,a[15]=((C_word*)t0)[18],tmp=(C_word)a,a+=16,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4403,a[2]=t9,a[3]=t7,a[4]=t12,a[5]=t8,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_4403(t14,t10,((C_word*)t0)[18]);}

/* map-loop886 in k4103 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in ... */
static void C_fcall f_4459(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4459,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list2(&a,2,t6,t7);
t9=C_a_i_cons(&a,2,t8,C_SCHEME_END_OF_LIST);
t10=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t9);
t11=C_mutate(((C_word *)((C_word*)t0)[2])+1,t9);
t13=t1;
t14=C_slot(t2,C_fix(1));
t15=C_slot(t3,C_fix(1));
t1=t13;
t2=t14;
t3=t15;
goto loop;}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* map-loop856 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_fcall f_4527(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4527,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4552,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:120: chicken.base#gensym */
t4=*((C_word*)lf[52]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4550 in map-loop856 in k4089 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in ... */
static void C_ccall f_4552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4552,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4527(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4567 in k4080 in k4077 in k4074 in k4071 in k4068 in k4065 in k4062 in k4059 in k4056 in k4053 in k4050 in k4047 in k4044 in k4041 in a4038 in k3049 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_4569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4569,c,av);}
t2=((C_word*)t0)[2];
f_4091(t2,C_i_greaterp(t1,C_fix(2)));}

/* a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4571(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4571,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4575,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* compiler-syntax.scm:73: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[39];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_4575,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4578,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:74: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[55];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4578(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4578,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4581,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* compiler-syntax.scm:75: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[102];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4581,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4584,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* compiler-syntax.scm:76: chicken.base#gensym */
t3=*((C_word*)lf[52]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4584(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4584,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4587,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* compiler-syntax.scm:77: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[94];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4587,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4590,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* compiler-syntax.scm:78: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[31];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_4590,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4593,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* compiler-syntax.scm:79: r */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[93];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_4593,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4596,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* compiler-syntax.scm:80: r */
t3=((C_word*)t0)[10];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[54];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_4596,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4599,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* compiler-syntax.scm:81: r */
t3=((C_word*)t0)[11];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[84];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_4599,c,av);}
a=C_alloc(16);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4608,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
if(C_truep(C_i_memq(lf[101],*((C_word*)lf[92]+1)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5026,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* compiler-syntax.scm:84: length+ */
f_2785(t4,((C_word*)t0)[2]);}
else{
t4=t3;
f_4608(t4,C_SCHEME_FALSE);}}

/* k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_4608(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,0,3)))){
C_save_and_reclaim_args((void *)trf_4608,2,t0,t1);}
a=C_alloc(25);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[87]);
t7=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4622,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[2],tmp=(C_word)a,a+=13,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4984,a[2]=t4,a[3]=t9,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_4984(t11,t7,((C_word*)t0)[2]);}
else{
t2=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4622(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_4622,c,av);}
a=C_alloc(31);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_check_list_2(t1,lf[87]);
t9=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4930,a[2]=t3,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=t1,tmp=(C_word)a,a+=13,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4932,a[2]=t6,a[3]=t11,a[4]=t7,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_4932(t13,t9,t1,((C_word*)t0)[12]);}

/* k4635 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4637,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* g688 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static C_word C_fcall f_4642(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_a_i_list(&a,2,((C_word*)t0)[2],lf[100]);
t3=C_a_i_list(&a,3,lf[48],t1,t2);
return(C_a_i_list(&a,2,lf[49],t3));}

/* k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4657(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_4657,c,av);}
a=C_alloc(24);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4672,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4836,a[2]=t4,a[3]=t8,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_4836(t10,t6,((C_word*)t0)[10],((C_word*)t0)[10]);}

/* k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4672(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_4672,c,av);}
a=C_alloc(28);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4793,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4800,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t1,a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4802,a[2]=t6,a[3]=t4,a[4]=t9,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_4802(t11,t7,((C_word*)t0)[11]);}

/* k4706 in k4752 in k4798 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_ccall f_4708(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(39,c,3)))){
C_save_and_reclaim((void *)f_4708,c,av);}
a=C_alloc(39);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[51],t2);
t4=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t3);
t5=C_a_i_list(&a,3,((C_word*)t0)[5],((C_word*)t0)[6],t4);
t6=C_a_i_list(&a,4,((C_word*)t0)[7],((C_word*)t0)[2],((C_word*)t0)[8],t5);
t7=C_a_i_list(&a,1,t6);
/* compiler-syntax.scm:86: ##sys#append */
t8=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=((C_word*)t0)[9];
av2[2]=((C_word*)t0)[10];
av2[3]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* map-loop803 in k4752 in k4798 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in ... */
static void C_fcall f_4710(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_4710,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,3,lf[50],t3,C_fix(1));
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

/* k4752 in k4798 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_ccall f_4754(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_4754,c,av);}
a=C_alloc(26);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4708,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4710,a[2]=t5,a[3]=t9,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_4710(t11,t7,((C_word*)t0)[11]);}

/* map-loop773 in k4798 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in ... */
static void C_fcall f_4756(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_4756,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,3,lf[50],t3,C_fix(0));
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

/* g749 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static C_word C_fcall f_4793(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_a_i_list(&a,2,((C_word*)t0)[2],t1));}

/* k4798 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_ccall f_4800(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_4800,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4754,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t2,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4756,a[2]=t5,a[3]=t9,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_4756(t11,t7,((C_word*)t0)[11]);}

/* map-loop743 in k4670 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 in ... */
static void C_fcall f_4802(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_4802,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(
/* compiler-syntax.scm:92: g749 */
  f_4793(C_a_i(&a,6),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
);
t4=C_a_i_cons(&a,2,t3,C_SCHEME_END_OF_LIST);
t5=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t4);
t6=C_mutate(((C_word *)((C_word*)t0)[3])+1,t4);
t8=t1;
t9=C_slot(t2,C_fix(1));
t1=t8;
t2=t9;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* map-loop712 in k4655 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_4836(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4836,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list2(&a,2,t6,t7);
t9=C_a_i_cons(&a,2,t8,C_SCHEME_END_OF_LIST);
t10=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t9);
t11=C_mutate(((C_word *)((C_word*)t0)[2])+1,t9);
t13=t1;
t14=C_slot(t2,C_fix(1));
t15=C_slot(t3,C_fix(1));
t1=t13;
t2=t14;
t3=t15;
goto loop;}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* map-loop682 in k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_4884(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,0,2)))){
C_save_and_reclaim_args((void *)trf_4884,3,t0,t1,t2);}
a=C_alloc(24);
if(C_truep(C_i_pairp(t2))){
t3=(
/* compiler-syntax.scm:88: g688 */
  f_4642(C_a_i(&a,21),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
);
t4=C_a_i_cons(&a,2,t3,C_SCHEME_END_OF_LIST);
t5=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t4);
t6=C_mutate(((C_word *)((C_word*)t0)[3])+1,t4);
t8=t1;
t9=C_slot(t2,C_fix(1));
t1=t8;
t2=t9;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4928 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_4930(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,3)))){
C_save_and_reclaim((void *)f_4930,c,av);}
a=C_alloc(35);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4637,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4642,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4657,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[4],a[9]=t3,a[10]=((C_word*)t0)[12],tmp=(C_word)a,a+=11,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4884,a[2]=t8,a[3]=t6,a[4]=t11,a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_4884(t13,t9,((C_word*)t0)[12]);}

/* map-loop651 in k4620 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_4932(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_4932,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list2(&a,2,t6,t7);
t9=C_a_i_cons(&a,2,t8,C_SCHEME_END_OF_LIST);
t10=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t9);
t11=C_mutate(((C_word *)((C_word*)t0)[2])+1,t9);
t13=t1;
t14=C_slot(t2,C_fix(1));
t15=C_slot(t3,C_fix(1));
t1=t13;
t2=t14;
t3=t15;
goto loop;}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* map-loop621 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_fcall f_4984(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4984,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5009,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* compiler-syntax.scm:85: chicken.base#gensym */
t4=*((C_word*)lf[52]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5007 in map-loop621 in k4606 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_5009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5009,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4984(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k5024 in k4597 in k4594 in k4591 in k4588 in k4585 in k4582 in k4579 in k4576 in k4573 in a4570 in k1702 in k1699 in k1696 in k1693 in k1690 in k1687 */
static void C_ccall f_5026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5026,c,av);}
t2=((C_word*)t0)[2];
f_4608(t2,C_i_greaterp(t1,C_fix(2)));}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_compiler_2dsyntax_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("compiler-syntax"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_compiler_2dsyntax_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(1003))){
C_save(t1);
C_rereclaim2(1003*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,105);
lf[0]=C_h_intern(&lf[0],15, C_text("compiler-syntax"));
lf[1]=C_h_intern(&lf[1],33, C_text("chicken.compiler.compiler-syntax#"));
lf[3]=C_h_intern(&lf[3],59, C_text("chicken.compiler.compiler-syntax#compiler-syntax-statistics"));
lf[4]=C_h_intern(&lf[4],26, C_text("##sys#compiler-syntax-hook"));
lf[5]=C_h_intern(&lf[5],26, C_text("chicken.base#alist-update!"));
lf[6]=C_h_intern(&lf[6],22, C_text("chicken.base#alist-ref"));
lf[7]=C_h_intern(&lf[7],10, C_text("scheme#eq\077"));
lf[9]=C_h_intern(&lf[9],10, C_text("##sys#put!"));
lf[10]=C_h_intern(&lf[10],26, C_text("##compiler#compiler-syntax"));
lf[11]=C_h_intern(&lf[11],13, C_text("scheme#append"));
lf[12]=C_h_intern(&lf[12],31, C_text("##sys#default-macro-environment"));
lf[13]=C_h_intern(&lf[13],24, C_text("##sys#ensure-transformer"));
lf[14]=C_h_intern(&lf[14],20, C_text("##sys#er-transformer"));
lf[16]=C_h_intern(&lf[16],39, C_text("chicken.compiler.core#extended-bindings"));
lf[17]=C_h_intern(&lf[17],6, C_text("format"));
lf[18]=C_h_intern(&lf[18],20, C_text("chicken.base#warning"));
lf[19]=C_h_intern(&lf[19],30, C_text("chicken.base#get-output-string"));
lf[20]=C_h_intern(&lf[20],22, C_text("chicken.format#fprintf"));
lf[21]=C_h_intern(&lf[21],11, C_text("##sys#print"));
lf[22]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002, "));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024\047, in format string "));
lf[24]=C_h_intern(&lf[24],18, C_text("##sys#write-char-0"));
lf[25]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002) "));
lf[26]=C_h_intern(&lf[26],31, C_text("chicken.base#open-output-string"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[28]=C_h_intern(&lf[28],30, C_text("chicken.syntax#get-line-number"));
lf[29]=C_decode_literal(C_heaptop,C_text("\376B\000\000/too few arguments to formatted output procedure"));
lf[30]=C_h_intern(&lf[30],26, C_text("##sys#reverse-list->string"));
lf[31]=C_h_intern(&lf[31],5, C_text("quote"));
lf[32]=C_h_intern(&lf[32],23, C_text("##sys#check-output-port"));
lf[33]=C_h_intern(&lf[33],14, C_text("scheme#reverse"));
lf[34]=C_decode_literal(C_heaptop,C_text("\376B\000\0000too many arguments to formatted output procedure"));
lf[35]=C_h_intern(&lf[35],18, C_text("##sys#flush-output"));
lf[36]=C_h_intern(&lf[36],11, C_text("##sys#apply"));
lf[37]=C_decode_literal(C_heaptop,C_text("\376B\000\000$illegal format-string character `~c\047"));
lf[38]=C_h_intern(&lf[38],14, C_text("number->string"));
lf[39]=C_h_intern(&lf[39],3, C_text("let"));
lf[40]=C_h_intern(&lf[40],3, C_text("out"));
lf[41]=C_h_intern(&lf[41],12, C_text("scheme#cadar"));
lf[42]=C_h_intern(&lf[42],26, C_text("chicken.base#symbol-append"));
lf[43]=C_h_intern(&lf[43],15, C_text("chicken.format#"));
lf[44]=C_h_intern(&lf[44],20, C_text("chicken.base#call/cc"));
lf[45]=C_h_intern(&lf[45],18, C_text("chicken.base#foldl"));
lf[46]=C_h_intern(&lf[46],12, C_text("##core#quote"));
lf[47]=C_h_intern(&lf[47],5, C_text("foldl"));
lf[48]=C_h_intern(&lf[48],16, C_text("##sys#check-list"));
lf[49]=C_h_intern(&lf[49],12, C_text("##core#check"));
lf[50]=C_h_intern(&lf[50],10, C_text("##sys#slot"));
lf[51]=C_h_intern(&lf[51],10, C_text("##core#app"));
lf[52]=C_h_intern(&lf[52],19, C_text("chicken.base#gensym"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005foldl"));
lf[54]=C_h_intern(&lf[54],5, C_text("pair\077"));
lf[55]=C_h_intern(&lf[55],2, C_text("if"));
lf[56]=C_h_intern(&lf[56],4, C_text("let\052"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\022\001chicken.base#foldl\376\377\016"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001pair\077\376\001\000\000\014\001scheme#pair\077\376\377\016"));
lf[59]=C_h_intern(&lf[59],18, C_text("chicken.base#foldr"));
lf[60]=C_h_intern(&lf[60],5, C_text("foldr"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005foldr"));
lf[62]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\022\001chicken.base#foldr\376\377\016"));
lf[63]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001pair\077\376\001\000\000\014\001scheme#pair\077\376\377\016"));
lf[64]=C_h_intern(&lf[64],6, C_text("printf"));
lf[65]=C_h_intern(&lf[65],21, C_text("##sys#standard-output"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\025\001chicken.format#printf\376\377\016"));
lf[67]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001display\376\001\000\000\016\001scheme#display\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001write\376\001\000\000\014\001scheme#wri"
"te\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001number->string\376\001\000\000\025\001scheme#number->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001write"
"-char\376\001\000\000\021\001scheme#write-char\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001open-output-string\376\001\000\000\037\001chicken.base"
"#open-output-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001get-output-string\376\001\000\000\036\001chicken.base#get-outpu"
"t-string\376\377\016"));
lf[68]=C_h_intern(&lf[68],7, C_text("fprintf"));
lf[69]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\026\001chicken.format#fprintf\376\377\016"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001display\376\001\000\000\016\001scheme#display\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001write\376\001\000\000\014\001scheme#wri"
"te\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001number->string\376\001\000\000\025\001scheme#number->string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001write"
"-char\376\001\000\000\021\001scheme#write-char\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001open-output-string\376\001\000\000\037\001chicken.base"
"#open-output-string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001get-output-string\376\001\000\000\036\001chicken.base#get-outpu"
"t-string\376\377\016"));
lf[71]=C_h_intern(&lf[71],17, C_text("get-output-string"));
lf[72]=C_h_intern(&lf[72],18, C_text("open-output-string"));
lf[73]=C_h_intern(&lf[73],22, C_text("chicken.format#sprintf"));
lf[74]=C_h_intern(&lf[74],7, C_text("sprintf"));
lf[75]=C_h_intern(&lf[75],7, C_text("display"));
lf[76]=C_h_intern(&lf[76],14, C_text("scheme#display"));
lf[77]=C_h_intern(&lf[77],5, C_text("write"));
lf[78]=C_h_intern(&lf[78],12, C_text("scheme#write"));
lf[79]=C_h_intern(&lf[79],21, C_text("scheme#number->string"));
lf[80]=C_h_intern(&lf[80],10, C_text("write-char"));
lf[81]=C_h_intern(&lf[81],17, C_text("scheme#write-char"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\026\001chicken.format#sprintf\376\003\000\000\002\376\001\000\000\025\001chicken.format#format\376\377\016"));
lf[83]=C_h_intern(&lf[83],14, C_text("chicken.base#o"));
lf[84]=C_h_intern(&lf[84],6, C_text("lambda"));
lf[85]=C_h_intern(&lf[85],3, C_text("tmp"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\016\001chicken.base#o\376\377\016"));
lf[87]=C_h_intern(&lf[87],3, C_text("map"));
lf[88]=C_h_intern(&lf[88],16, C_text("##core#undefined"));
lf[89]=C_h_intern(&lf[89],13, C_text("##sys#setslot"));
lf[90]=C_h_intern(&lf[90],12, C_text("##sys#append"));
lf[91]=C_h_intern(&lf[91],10, C_text("scheme#map"));
lf[92]=C_h_intern(&lf[92],39, C_text("chicken.compiler.core#standard-bindings"));
lf[93]=C_h_intern(&lf[93],3, C_text("and"));
lf[94]=C_h_intern(&lf[94],5, C_text("begin"));
lf[95]=C_h_intern(&lf[95],4, C_text("set!"));
lf[96]=C_h_intern(&lf[96],4, C_text("cons"));
lf[97]=C_h_intern(&lf[97],8, C_text("map-loop"));
lf[98]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001scheme#map\376\003\000\000\002\376\001\000\000\011\001##sys#map\376\377\016"));
lf[99]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001pair\077\376\001\000\000\014\001scheme#pair\077\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001cons\376\001\000\000\013\001scheme#cons\376\377\016"));
lf[100]=C_h_intern(&lf[100],8, C_text("for-each"));
lf[101]=C_h_intern(&lf[101],15, C_text("scheme#for-each"));
lf[102]=C_h_intern(&lf[102],13, C_text("for-each-loop"));
lf[103]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\017\001scheme#for-each\376\003\000\000\002\376\001\000\000\016\001##sys#for-each\376\377\016"));
lf[104]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\005\001pair\077\376\001\000\000\014\001scheme#pair\077\376\377\016"));
C_register_lf2(lf,105,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1689,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[172] = {
{C_text("f_1689:compiler_2dsyntax_2escm"),(void*)f_1689},
{C_text("f_1692:compiler_2dsyntax_2escm"),(void*)f_1692},
{C_text("f_1695:compiler_2dsyntax_2escm"),(void*)f_1695},
{C_text("f_1698:compiler_2dsyntax_2escm"),(void*)f_1698},
{C_text("f_1701:compiler_2dsyntax_2escm"),(void*)f_1701},
{C_text("f_1704:compiler_2dsyntax_2escm"),(void*)f_1704},
{C_text("f_2785:compiler_2dsyntax_2escm"),(void*)f_2785},
{C_text("f_2791:compiler_2dsyntax_2escm"),(void*)f_2791},
{C_text("f_2985:compiler_2dsyntax_2escm"),(void*)f_2985},
{C_text("f_2989:compiler_2dsyntax_2escm"),(void*)f_2989},
{C_text("f_2993:compiler_2dsyntax_2escm"),(void*)f_2993},
{C_text("f_2997:compiler_2dsyntax_2escm"),(void*)f_2997},
{C_text("f_3002:compiler_2dsyntax_2escm"),(void*)f_3002},
{C_text("f_3011:compiler_2dsyntax_2escm"),(void*)f_3011},
{C_text("f_3021:compiler_2dsyntax_2escm"),(void*)f_3021},
{C_text("f_3036:compiler_2dsyntax_2escm"),(void*)f_3036},
{C_text("f_3040:compiler_2dsyntax_2escm"),(void*)f_3040},
{C_text("f_3044:compiler_2dsyntax_2escm"),(void*)f_3044},
{C_text("f_3051:compiler_2dsyntax_2escm"),(void*)f_3051},
{C_text("f_3054:compiler_2dsyntax_2escm"),(void*)f_3054},
{C_text("f_3057:compiler_2dsyntax_2escm"),(void*)f_3057},
{C_text("f_3060:compiler_2dsyntax_2escm"),(void*)f_3060},
{C_text("f_3063:compiler_2dsyntax_2escm"),(void*)f_3063},
{C_text("f_3066:compiler_2dsyntax_2escm"),(void*)f_3066},
{C_text("f_3068:compiler_2dsyntax_2escm"),(void*)f_3068},
{C_text("f_3074:compiler_2dsyntax_2escm"),(void*)f_3074},
{C_text("f_3096:compiler_2dsyntax_2escm"),(void*)f_3096},
{C_text("f_3099:compiler_2dsyntax_2escm"),(void*)f_3099},
{C_text("f_3102:compiler_2dsyntax_2escm"),(void*)f_3102},
{C_text("f_3106:compiler_2dsyntax_2escm"),(void*)f_3106},
{C_text("f_3109:compiler_2dsyntax_2escm"),(void*)f_3109},
{C_text("f_3119:compiler_2dsyntax_2escm"),(void*)f_3119},
{C_text("f_3125:compiler_2dsyntax_2escm"),(void*)f_3125},
{C_text("f_3128:compiler_2dsyntax_2escm"),(void*)f_3128},
{C_text("f_3131:compiler_2dsyntax_2escm"),(void*)f_3131},
{C_text("f_3134:compiler_2dsyntax_2escm"),(void*)f_3134},
{C_text("f_3137:compiler_2dsyntax_2escm"),(void*)f_3137},
{C_text("f_3140:compiler_2dsyntax_2escm"),(void*)f_3140},
{C_text("f_3143:compiler_2dsyntax_2escm"),(void*)f_3143},
{C_text("f_3146:compiler_2dsyntax_2escm"),(void*)f_3146},
{C_text("f_3150:compiler_2dsyntax_2escm"),(void*)f_3150},
{C_text("f_3153:compiler_2dsyntax_2escm"),(void*)f_3153},
{C_text("f_3159:compiler_2dsyntax_2escm"),(void*)f_3159},
{C_text("f_3162:compiler_2dsyntax_2escm"),(void*)f_3162},
{C_text("f_3165:compiler_2dsyntax_2escm"),(void*)f_3165},
{C_text("f_3174:compiler_2dsyntax_2escm"),(void*)f_3174},
{C_text("f_3177:compiler_2dsyntax_2escm"),(void*)f_3177},
{C_text("f_3180:compiler_2dsyntax_2escm"),(void*)f_3180},
{C_text("f_3182:compiler_2dsyntax_2escm"),(void*)f_3182},
{C_text("f_3192:compiler_2dsyntax_2escm"),(void*)f_3192},
{C_text("f_3211:compiler_2dsyntax_2escm"),(void*)f_3211},
{C_text("f_3242:compiler_2dsyntax_2escm"),(void*)f_3242},
{C_text("f_3249:compiler_2dsyntax_2escm"),(void*)f_3249},
{C_text("f_3259:compiler_2dsyntax_2escm"),(void*)f_3259},
{C_text("f_3269:compiler_2dsyntax_2escm"),(void*)f_3269},
{C_text("f_3272:compiler_2dsyntax_2escm"),(void*)f_3272},
{C_text("f_3295:compiler_2dsyntax_2escm"),(void*)f_3295},
{C_text("f_3324:compiler_2dsyntax_2escm"),(void*)f_3324},
{C_text("f_3330:compiler_2dsyntax_2escm"),(void*)f_3330},
{C_text("f_3347:compiler_2dsyntax_2escm"),(void*)f_3347},
{C_text("f_3364:compiler_2dsyntax_2escm"),(void*)f_3364},
{C_text("f_3381:compiler_2dsyntax_2escm"),(void*)f_3381},
{C_text("f_3402:compiler_2dsyntax_2escm"),(void*)f_3402},
{C_text("f_3423:compiler_2dsyntax_2escm"),(void*)f_3423},
{C_text("f_3444:compiler_2dsyntax_2escm"),(void*)f_3444},
{C_text("f_3466:compiler_2dsyntax_2escm"),(void*)f_3466},
{C_text("f_3469:compiler_2dsyntax_2escm"),(void*)f_3469},
{C_text("f_3520:compiler_2dsyntax_2escm"),(void*)f_3520},
{C_text("f_3592:compiler_2dsyntax_2escm"),(void*)f_3592},
{C_text("f_3599:compiler_2dsyntax_2escm"),(void*)f_3599},
{C_text("f_3603:compiler_2dsyntax_2escm"),(void*)f_3603},
{C_text("f_3617:compiler_2dsyntax_2escm"),(void*)f_3617},
{C_text("f_3625:compiler_2dsyntax_2escm"),(void*)f_3625},
{C_text("f_3628:compiler_2dsyntax_2escm"),(void*)f_3628},
{C_text("f_3630:compiler_2dsyntax_2escm"),(void*)f_3630},
{C_text("f_3649:compiler_2dsyntax_2escm"),(void*)f_3649},
{C_text("f_3652:compiler_2dsyntax_2escm"),(void*)f_3652},
{C_text("f_3655:compiler_2dsyntax_2escm"),(void*)f_3655},
{C_text("f_3658:compiler_2dsyntax_2escm"),(void*)f_3658},
{C_text("f_3661:compiler_2dsyntax_2escm"),(void*)f_3661},
{C_text("f_3664:compiler_2dsyntax_2escm"),(void*)f_3664},
{C_text("f_3667:compiler_2dsyntax_2escm"),(void*)f_3667},
{C_text("f_3746:compiler_2dsyntax_2escm"),(void*)f_3746},
{C_text("f_3765:compiler_2dsyntax_2escm"),(void*)f_3765},
{C_text("f_3768:compiler_2dsyntax_2escm"),(void*)f_3768},
{C_text("f_3771:compiler_2dsyntax_2escm"),(void*)f_3771},
{C_text("f_3774:compiler_2dsyntax_2escm"),(void*)f_3774},
{C_text("f_3777:compiler_2dsyntax_2escm"),(void*)f_3777},
{C_text("f_3780:compiler_2dsyntax_2escm"),(void*)f_3780},
{C_text("f_3851:compiler_2dsyntax_2escm"),(void*)f_3851},
{C_text("f_3855:compiler_2dsyntax_2escm"),(void*)f_3855},
{C_text("f_3864:compiler_2dsyntax_2escm"),(void*)f_3864},
{C_text("f_3874:compiler_2dsyntax_2escm"),(void*)f_3874},
{C_text("f_3891:compiler_2dsyntax_2escm"),(void*)f_3891},
{C_text("f_3895:compiler_2dsyntax_2escm"),(void*)f_3895},
{C_text("f_3898:compiler_2dsyntax_2escm"),(void*)f_3898},
{C_text("f_3908:compiler_2dsyntax_2escm"),(void*)f_3908},
{C_text("f_3920:compiler_2dsyntax_2escm"),(void*)f_3920},
{C_text("f_3932:compiler_2dsyntax_2escm"),(void*)f_3932},
{C_text("f_3975:compiler_2dsyntax_2escm"),(void*)f_3975},
{C_text("f_3985:compiler_2dsyntax_2escm"),(void*)f_3985},
{C_text("f_3992:compiler_2dsyntax_2escm"),(void*)f_3992},
{C_text("f_4003:compiler_2dsyntax_2escm"),(void*)f_4003},
{C_text("f_4005:compiler_2dsyntax_2escm"),(void*)f_4005},
{C_text("f_4023:compiler_2dsyntax_2escm"),(void*)f_4023},
{C_text("f_4039:compiler_2dsyntax_2escm"),(void*)f_4039},
{C_text("f_4043:compiler_2dsyntax_2escm"),(void*)f_4043},
{C_text("f_4046:compiler_2dsyntax_2escm"),(void*)f_4046},
{C_text("f_4049:compiler_2dsyntax_2escm"),(void*)f_4049},
{C_text("f_4052:compiler_2dsyntax_2escm"),(void*)f_4052},
{C_text("f_4055:compiler_2dsyntax_2escm"),(void*)f_4055},
{C_text("f_4058:compiler_2dsyntax_2escm"),(void*)f_4058},
{C_text("f_4061:compiler_2dsyntax_2escm"),(void*)f_4061},
{C_text("f_4064:compiler_2dsyntax_2escm"),(void*)f_4064},
{C_text("f_4067:compiler_2dsyntax_2escm"),(void*)f_4067},
{C_text("f_4070:compiler_2dsyntax_2escm"),(void*)f_4070},
{C_text("f_4073:compiler_2dsyntax_2escm"),(void*)f_4073},
{C_text("f_4076:compiler_2dsyntax_2escm"),(void*)f_4076},
{C_text("f_4079:compiler_2dsyntax_2escm"),(void*)f_4079},
{C_text("f_4082:compiler_2dsyntax_2escm"),(void*)f_4082},
{C_text("f_4091:compiler_2dsyntax_2escm"),(void*)f_4091},
{C_text("f_4105:compiler_2dsyntax_2escm"),(void*)f_4105},
{C_text("f_4128:compiler_2dsyntax_2escm"),(void*)f_4128},
{C_text("f_4133:compiler_2dsyntax_2escm"),(void*)f_4133},
{C_text("f_4148:compiler_2dsyntax_2escm"),(void*)f_4148},
{C_text("f_4163:compiler_2dsyntax_2escm"),(void*)f_4163},
{C_text("f_4211:compiler_2dsyntax_2escm"),(void*)f_4211},
{C_text("f_4213:compiler_2dsyntax_2escm"),(void*)f_4213},
{C_text("f_4273:compiler_2dsyntax_2escm"),(void*)f_4273},
{C_text("f_4275:compiler_2dsyntax_2escm"),(void*)f_4275},
{C_text("f_4312:compiler_2dsyntax_2escm"),(void*)f_4312},
{C_text("f_4319:compiler_2dsyntax_2escm"),(void*)f_4319},
{C_text("f_4321:compiler_2dsyntax_2escm"),(void*)f_4321},
{C_text("f_4355:compiler_2dsyntax_2escm"),(void*)f_4355},
{C_text("f_4403:compiler_2dsyntax_2escm"),(void*)f_4403},
{C_text("f_4457:compiler_2dsyntax_2escm"),(void*)f_4457},
{C_text("f_4459:compiler_2dsyntax_2escm"),(void*)f_4459},
{C_text("f_4527:compiler_2dsyntax_2escm"),(void*)f_4527},
{C_text("f_4552:compiler_2dsyntax_2escm"),(void*)f_4552},
{C_text("f_4569:compiler_2dsyntax_2escm"),(void*)f_4569},
{C_text("f_4571:compiler_2dsyntax_2escm"),(void*)f_4571},
{C_text("f_4575:compiler_2dsyntax_2escm"),(void*)f_4575},
{C_text("f_4578:compiler_2dsyntax_2escm"),(void*)f_4578},
{C_text("f_4581:compiler_2dsyntax_2escm"),(void*)f_4581},
{C_text("f_4584:compiler_2dsyntax_2escm"),(void*)f_4584},
{C_text("f_4587:compiler_2dsyntax_2escm"),(void*)f_4587},
{C_text("f_4590:compiler_2dsyntax_2escm"),(void*)f_4590},
{C_text("f_4593:compiler_2dsyntax_2escm"),(void*)f_4593},
{C_text("f_4596:compiler_2dsyntax_2escm"),(void*)f_4596},
{C_text("f_4599:compiler_2dsyntax_2escm"),(void*)f_4599},
{C_text("f_4608:compiler_2dsyntax_2escm"),(void*)f_4608},
{C_text("f_4622:compiler_2dsyntax_2escm"),(void*)f_4622},
{C_text("f_4637:compiler_2dsyntax_2escm"),(void*)f_4637},
{C_text("f_4642:compiler_2dsyntax_2escm"),(void*)f_4642},
{C_text("f_4657:compiler_2dsyntax_2escm"),(void*)f_4657},
{C_text("f_4672:compiler_2dsyntax_2escm"),(void*)f_4672},
{C_text("f_4708:compiler_2dsyntax_2escm"),(void*)f_4708},
{C_text("f_4710:compiler_2dsyntax_2escm"),(void*)f_4710},
{C_text("f_4754:compiler_2dsyntax_2escm"),(void*)f_4754},
{C_text("f_4756:compiler_2dsyntax_2escm"),(void*)f_4756},
{C_text("f_4793:compiler_2dsyntax_2escm"),(void*)f_4793},
{C_text("f_4800:compiler_2dsyntax_2escm"),(void*)f_4800},
{C_text("f_4802:compiler_2dsyntax_2escm"),(void*)f_4802},
{C_text("f_4836:compiler_2dsyntax_2escm"),(void*)f_4836},
{C_text("f_4884:compiler_2dsyntax_2escm"),(void*)f_4884},
{C_text("f_4930:compiler_2dsyntax_2escm"),(void*)f_4930},
{C_text("f_4932:compiler_2dsyntax_2escm"),(void*)f_4932},
{C_text("f_4984:compiler_2dsyntax_2escm"),(void*)f_4984},
{C_text("f_5009:compiler_2dsyntax_2escm"),(void*)f_5009},
{C_text("f_5026:compiler_2dsyntax_2escm"),(void*)f_5026},
{C_text("toplevel:compiler_2dsyntax_2escm"),(void*)C_compiler_2dsyntax_toplevel},
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
o|hiding unexported module binding: chicken.compiler.compiler-syntax#partition 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#span 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#take 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#drop 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#split-at 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#append-map 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#every 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#any 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#cons* 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#concatenate 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#delete 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#first 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#second 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#third 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#fourth 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#fifth 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#delete-duplicates 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#alist-cons 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#filter 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#filter-map 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#remove 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#unzip1 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#last 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#list-index 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#lset-difference/eq? 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#lset-union/eq? 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#lset-intersection/eq? 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#list-tabulate 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#lset<=/eq? 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#lset=/eq? 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#length+ 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#find 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#find-tail 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#iota 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#make-list 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#posq 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#posv 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#r-c-s 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#define-internal-compiler-syntax 
o|hiding unexported module binding: chicken.compiler.compiler-syntax#compile-format-string 
S|applied compiler syntax:
S|  chicken.format#sprintf		2
S|  scheme#for-each		1
S|  chicken.base#foldl		3
S|  scheme#map		17
S|  chicken.base#foldr		4
o|eliminated procedure checks: 220 
o|specializations:
o|  1 (chicken.base#sub1 *)
o|  11 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#= fixnum fixnum)
o|  2 (##sys#check-output-port * * *)
o|  1 (scheme#cddr (pair * pair))
o|  2 (scheme#>= fixnum fixnum)
o|  1 (chicken.base#add1 *)
o|  1 (scheme#eqv? * *)
o|  19 (##sys#check-list (or pair list) *)
o|  24 (scheme#cdr pair)
o|  10 (scheme#car pair)
(o e)|safe calls: 535 
(o e)|assignments to immediate values: 2 
o|safe globals: (chicken.compiler.compiler-syntax#r-c-s ##sys#compiler-syntax-hook chicken.compiler.compiler-syntax#compiler-syntax-statistics chicken.compiler.compiler-syntax#posv chicken.compiler.compiler-syntax#posq chicken.compiler.compiler-syntax#make-list chicken.compiler.compiler-syntax#iota chicken.compiler.compiler-syntax#find-tail chicken.compiler.compiler-syntax#find chicken.compiler.compiler-syntax#length+ chicken.compiler.compiler-syntax#lset=/eq? chicken.compiler.compiler-syntax#lset<=/eq? chicken.compiler.compiler-syntax#list-tabulate chicken.compiler.compiler-syntax#lset-intersection/eq? chicken.compiler.compiler-syntax#lset-union/eq? chicken.compiler.compiler-syntax#lset-difference/eq? chicken.compiler.compiler-syntax#lset-adjoin/eq? chicken.compiler.compiler-syntax#list-index chicken.compiler.compiler-syntax#last chicken.compiler.compiler-syntax#unzip1 chicken.compiler.compiler-syntax#remove chicken.compiler.compiler-syntax#filter-map chicken.compiler.compiler-syntax#filter chicken.compiler.compiler-syntax#alist-cons chicken.compiler.compiler-syntax#delete-duplicates chicken.compiler.compiler-syntax#fifth chicken.compiler.compiler-syntax#fourth chicken.compiler.compiler-syntax#third chicken.compiler.compiler-syntax#second chicken.compiler.compiler-syntax#first chicken.compiler.compiler-syntax#delete chicken.compiler.compiler-syntax#concatenate chicken.compiler.compiler-syntax#cons* chicken.compiler.compiler-syntax#any chicken.compiler.compiler-syntax#every chicken.compiler.compiler-syntax#append-map chicken.compiler.compiler-syntax#split-at chicken.compiler.compiler-syntax#drop chicken.compiler.compiler-syntax#take chicken.compiler.compiler-syntax#span chicken.compiler.compiler-syntax#partition) 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#partition 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#span 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#drop 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#split-at 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#append-map 
o|inlining procedure: k2086 
o|inlining procedure: k2086 
o|inlining procedure: k2117 
o|inlining procedure: k2117 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#cons* 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#concatenate 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#first 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#second 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#third 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#fourth 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#fifth 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#delete-duplicates 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#alist-cons 
o|inlining procedure: k2334 
o|inlining procedure: k2334 
o|inlining procedure: k2326 
o|inlining procedure: k2326 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#filter-map 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#remove 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#unzip1 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#last 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#list-index 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#lset-intersection/eq? 
o|inlining procedure: k2725 
o|inlining procedure: k2725 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#lset=/eq? 
o|inlining procedure: k2793 
o|inlining procedure: k2816 
o|inlining procedure: k2816 
o|inlining procedure: k2793 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#find 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#find-tail 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#iota 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#make-list 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#posq 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#posv 
o|inlining procedure: k3013 
o|inlining procedure: k3013 
o|inlining procedure: k3076 
o|merged explicitly consed rest parameter: args1143 
o|inlining procedure: k3110 
o|inlining procedure: k3110 
o|substituted constant variable: a3121 
o|substituted constant variable: a3122 
o|substituted constant variable: a3155 
o|substituted constant variable: a3156 
o|inlining procedure: k3148 
o|inlining procedure: k3148 
o|inlining procedure: k3194 
o|consed rest parameter at call site: "(compiler-syntax.scm:220) fail1140" 3 
o|inlining procedure: k3194 
o|inlining procedure: k3213 
o|inlining procedure: k3223 
o|inlining procedure: k3223 
o|substituted constant variable: a3243 
o|inlining procedure: k3213 
o|inlining procedure: k3088 
o|inlining procedure: k3261 
o|consed rest parameter at call site: "(compiler-syntax.scm:235) fail1140" 3 
o|inlining procedure: k3261 
o|inlining procedure: k3328 
o|inlining procedure: k3328 
o|inlining procedure: k3365 
o|inlining procedure: k3365 
o|inlining procedure: k3403 
o|inlining procedure: k3403 
o|inlining procedure: k3445 
o|inlining procedure: k3445 
o|inlining procedure: k3477 
o|inlining procedure: k3477 
o|inlining procedure: k3506 
o|inlining procedure: k3522 
o|inlining procedure: k3522 
o|inlining procedure: k3506 
o|consed rest parameter at call site: "(compiler-syntax.scm:274) fail1140" 3 
o|substituted constant variable: a3544 
o|substituted constant variable: a3546 
o|substituted constant variable: a3548 
o|substituted constant variable: a3550 
o|substituted constant variable: a3552 
o|substituted constant variable: a3554 
o|substituted constant variable: a3556 
o|substituted constant variable: a3558 
o|substituted constant variable: a3560 
o|substituted constant variable: a3562 
o|substituted constant variable: a3564 
o|inlining procedure: k3088 
o|inlining procedure: k3581 
o|inlining procedure: k3581 
o|inlining procedure: k3076 
o|substituted constant variable: a3622 
o|inlining procedure: k3632 
o|inlining procedure: k3632 
o|inlining procedure: k3748 
o|inlining procedure: k3748 
o|inlining procedure: k3856 
o|inlining procedure: k3856 
o|inlining procedure: k3866 
o|inlining procedure: k3866 
o|substituted constant variable: a3889 
o|inlining procedure: k3899 
o|inlining procedure: k3899 
o|inlining procedure: k3977 
o|inlining procedure: k4007 
o|inlining procedure: k4007 
o|inlining procedure: k3977 
o|inlining procedure: k4086 
o|inlining procedure: k4215 
o|contracted procedure: "(compiler-syntax.scm:139) g10441053" 
o|inlining procedure: k4215 
o|inlining procedure: k4277 
o|contracted procedure: "(compiler-syntax.scm:133) g10141023" 
o|inlining procedure: k4277 
o|inlining procedure: k4323 
o|inlining procedure: k4323 
o|inlining procedure: k4357 
o|inlining procedure: k4357 
o|inlining procedure: k4405 
o|inlining procedure: k4405 
o|inlining procedure: k4461 
o|inlining procedure: k4461 
o|inlining procedure: k4529 
o|contracted procedure: "(compiler-syntax.scm:120) g862871" 
o|inlining procedure: k4529 
o|inlining procedure: k4086 
o|inlining procedure: k4603 
o|inlining procedure: k4712 
o|contracted procedure: "(compiler-syntax.scm:98) g809818" 
o|inlining procedure: k4712 
o|inlining procedure: k4758 
o|contracted procedure: "(compiler-syntax.scm:95) g779788" 
o|inlining procedure: k4758 
o|inlining procedure: k4804 
o|inlining procedure: k4804 
o|inlining procedure: k4838 
o|inlining procedure: k4838 
o|inlining procedure: k4886 
o|inlining procedure: k4886 
o|inlining procedure: k4934 
o|inlining procedure: k4934 
o|inlining procedure: k4986 
o|contracted procedure: "(compiler-syntax.scm:85) g627636" 
o|inlining procedure: k4986 
o|inlining procedure: k4603 
o|replaced variables: 622 
o|removed binding forms: 183 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#every 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#any 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#filter 
o|removed side-effect free assignment to unused variable: chicken.compiler.compiler-syntax#list-tabulate 
o|substituted constant variable: r28175039 
o|substituted constant variable: r31495048 
o|substituted constant variable: r31495048 
o|converted assignments to bindings: (fail1140) 
o|substituted constant variable: r30895083 
o|substituted constant variable: r35825085 
o|substituted constant variable: r30775086 
o|simplifications: ((let . 1)) 
o|replaced variables: 23 
o|removed binding forms: 538 
o|removed call to pure procedure with unused result: "(compiler-syntax.scm:120) ##sys#slot" 
o|removed call to pure procedure with unused result: "(compiler-syntax.scm:85) ##sys#slot" 
o|removed binding forms: 33 
o|contracted procedure: k4554 
o|contracted procedure: k5011 
o|removed binding forms: 2 
o|removed binding forms: 2 
o|simplifications: ((let . 4) (if . 11) (##core#call . 320)) 
o|  call simplifications:
o|    scheme#cddr	2
o|    scheme#>	2
o|    ##sys#check-list	4
o|    ##sys#setslot	14
o|    chicken.fixnum#fx>
o|    scheme#list	5
o|    chicken.fixnum#fx=	2
o|    scheme#cadr	5
o|    scheme#caddr	2
o|    scheme#cadddr	2
o|    chicken.fixnum#fx>=	2
o|    scheme#memq	6
o|    scheme#list?
o|    scheme#caar
o|    scheme#string?	3
o|    scheme#string-length
o|    scheme#>=
o|    scheme#char-upcase
o|    scheme#char-whitespace?	2
o|    ##sys#cons	24
o|    scheme#length	6
o|    ##sys#list	95
o|    scheme#null?	2
o|    scheme#string-ref
o|    ##sys#apply
o|    scheme#car	5
o|    scheme#cons	31
o|    ##sys#slot	52
o|    scheme#pair?	23
o|    scheme#cdr	4
o|    chicken.fixnum#fx+	3
o|    scheme#eq?	15
o|    scheme#not
o|contracted procedure: k2796 
o|contracted procedure: k2800 
o|contracted procedure: k2806 
o|contracted procedure: k2810 
o|contracted procedure: k2813 
o|contracted procedure: k2826 
o|contracted procedure: k2819 
o|contracted procedure: k2999 
o|contracted procedure: k3016 
o|contracted procedure: k3026 
o|contracted procedure: k3030 
o|contracted procedure: k3046 
o|contracted procedure: k3619 
o|contracted procedure: k3079 
o|contracted procedure: k3085 
o|contracted procedure: k3611 
o|contracted procedure: k3091 
o|contracted procedure: k3169 
o|contracted procedure: k3184 
o|contracted procedure: k3188 
o|contracted procedure: k3197 
o|contracted procedure: k3203 
o|contracted procedure: k3207 
o|contracted procedure: k3216 
o|contracted procedure: k3245 
o|contracted procedure: k3226 
o|contracted procedure: k3233 
o|inlining procedure: k3223 
o|inlining procedure: k3223 
o|contracted procedure: k3252 
o|contracted procedure: k3264 
o|contracted procedure: k3301 
o|contracted procedure: k3281 
o|contracted procedure: k3297 
o|contracted procedure: k3289 
o|contracted procedure: k3285 
o|contracted procedure: k3277 
o|contracted procedure: k3304 
o|contracted procedure: k3316 
o|contracted procedure: k3325 
o|contracted procedure: k3334 
o|contracted procedure: k3341 
o|contracted procedure: k3351 
o|contracted procedure: k3358 
o|contracted procedure: k3368 
o|contracted procedure: k3375 
o|contracted procedure: k3385 
o|contracted procedure: k3396 
o|contracted procedure: k3392 
o|contracted procedure: k3406 
o|contracted procedure: k3417 
o|contracted procedure: k3413 
o|contracted procedure: k3427 
o|contracted procedure: k3438 
o|contracted procedure: k3434 
o|contracted procedure: k3448 
o|contracted procedure: k3455 
o|contracted procedure: k3461 
o|contracted procedure: k3474 
o|contracted procedure: k3480 
o|contracted procedure: k3487 
o|contracted procedure: k3493 
o|contracted procedure: k3496 
o|contracted procedure: k3503 
o|contracted procedure: k3509 
o|contracted procedure: k3525 
o|contracted procedure: k3569 
o|contracted procedure: k3572 
o|contracted procedure: k3584 
o|contracted procedure: k3605 
o|contracted procedure: k3742 
o|contracted procedure: k3735 
o|contracted procedure: k3635 
o|contracted procedure: k3638 
o|contracted procedure: k3641 
o|contracted procedure: k3644 
o|contracted procedure: k3728 
o|contracted procedure: k3732 
o|contracted procedure: k3672 
o|contracted procedure: k3724 
o|contracted procedure: k3720 
o|contracted procedure: k3676 
o|contracted procedure: k3712 
o|contracted procedure: k3716 
o|contracted procedure: k3684 
o|contracted procedure: k3692 
o|contracted procedure: k3700 
o|contracted procedure: k3708 
o|contracted procedure: k3704 
o|contracted procedure: k3696 
o|contracted procedure: k3688 
o|contracted procedure: k3680 
o|contracted procedure: k3847 
o|contracted procedure: k3840 
o|contracted procedure: k3751 
o|contracted procedure: k3754 
o|contracted procedure: k3757 
o|contracted procedure: k3760 
o|contracted procedure: k3837 
o|contracted procedure: k3785 
o|contracted procedure: k3833 
o|contracted procedure: k3829 
o|contracted procedure: k3789 
o|contracted procedure: k3825 
o|contracted procedure: k3797 
o|contracted procedure: k3805 
o|contracted procedure: k3813 
o|contracted procedure: k3821 
o|contracted procedure: k3817 
o|contracted procedure: k3809 
o|contracted procedure: k3801 
o|contracted procedure: k3793 
o|contracted procedure: k3860 
o|contracted procedure: k3886 
o|contracted procedure: k3869 
o|contracted procedure: k3879 
o|contracted procedure: k3926 
o|contracted procedure: k3922 
o|contracted procedure: k3910 
o|contracted procedure: k3914 
o|contracted procedure: k3943 
o|contracted procedure: k3939 
o|contracted procedure: k3934 
o|contracted procedure: k3951 
o|contracted procedure: k3955 
o|contracted procedure: k3959 
o|contracted procedure: k3963 
o|contracted procedure: k3967 
o|contracted procedure: k3971 
o|contracted procedure: k3947 
o|contracted procedure: k4035 
o|contracted procedure: k4028 
o|contracted procedure: k3980 
o|contracted procedure: k3994 
o|contracted procedure: k3998 
o|contracted procedure: k4010 
o|contracted procedure: k4017 
o|contracted procedure: k4025 
o|contracted procedure: k4083 
o|contracted procedure: k4092 
o|contracted procedure: k4100 
o|contracted procedure: k4519 
o|contracted procedure: k4523 
o|contracted procedure: k4515 
o|contracted procedure: k4511 
o|contracted procedure: k4110 
o|contracted procedure: k4437 
o|contracted procedure: k4507 
o|contracted procedure: k4445 
o|contracted procedure: k4449 
o|contracted procedure: k4452 
o|contracted procedure: k4441 
o|contracted procedure: k4122 
o|contracted procedure: k4118 
o|contracted procedure: k4114 
o|contracted procedure: k4130 
o|contracted procedure: k4143 
o|contracted procedure: k4139 
o|contracted procedure: k4158 
o|contracted procedure: k4309 
o|contracted procedure: k4169 
o|contracted procedure: k4263 
o|contracted procedure: k4255 
o|contracted procedure: k4259 
o|contracted procedure: k4251 
o|contracted procedure: k4247 
o|contracted procedure: k4181 
o|contracted procedure: k4185 
o|contracted procedure: k4189 
o|contracted procedure: k4201 
o|contracted procedure: k4197 
o|contracted procedure: k4193 
o|contracted procedure: k4173 
o|contracted procedure: k4177 
o|contracted procedure: k4165 
o|contracted procedure: k4154 
o|contracted procedure: k4150 
o|contracted procedure: k4218 
o|contracted procedure: k4240 
o|contracted procedure: k4236 
o|contracted procedure: k4221 
o|contracted procedure: k4224 
o|contracted procedure: k4232 
o|contracted procedure: k4280 
o|contracted procedure: k4302 
o|contracted procedure: k4298 
o|contracted procedure: k4283 
o|contracted procedure: k4286 
o|contracted procedure: k4294 
o|contracted procedure: k4326 
o|contracted procedure: k4329 
o|contracted procedure: k4332 
o|contracted procedure: k4340 
o|contracted procedure: k4348 
o|contracted procedure: k4396 
o|contracted procedure: k4360 
o|contracted procedure: k4386 
o|contracted procedure: k4390 
o|contracted procedure: k4382 
o|contracted procedure: k4363 
o|contracted procedure: k4366 
o|contracted procedure: k4374 
o|contracted procedure: k4378 
o|contracted procedure: k4408 
o|contracted procedure: k4411 
o|contracted procedure: k4414 
o|contracted procedure: k4422 
o|contracted procedure: k4430 
o|contracted procedure: k4500 
o|contracted procedure: k4464 
o|contracted procedure: k4490 
o|contracted procedure: k4494 
o|contracted procedure: k4486 
o|contracted procedure: k4467 
o|contracted procedure: k4470 
o|contracted procedure: k4478 
o|contracted procedure: k4482 
o|contracted procedure: k4532 
o|contracted procedure: k4535 
o|contracted procedure: k4538 
o|contracted procedure: k4546 
o|contracted procedure: k4560 
o|contracted procedure: k4600 
o|contracted procedure: k4609 
o|contracted procedure: k4617 
o|contracted procedure: k4980 
o|contracted procedure: k4918 
o|contracted procedure: k4922 
o|contracted procedure: k4925 
o|contracted procedure: k4631 
o|contracted procedure: k4627 
o|contracted procedure: k4639 
o|contracted procedure: k4652 
o|contracted procedure: k4648 
o|contracted procedure: k4667 
o|contracted procedure: k4790 
o|contracted procedure: k4678 
o|contracted procedure: k4744 
o|contracted procedure: k4686 
o|contracted procedure: k4698 
o|contracted procedure: k4694 
o|contracted procedure: k4690 
o|contracted procedure: k4682 
o|contracted procedure: k4674 
o|contracted procedure: k4663 
o|contracted procedure: k4659 
o|contracted procedure: k4715 
o|contracted procedure: k4737 
o|contracted procedure: k4733 
o|contracted procedure: k4718 
o|contracted procedure: k4721 
o|contracted procedure: k4729 
o|contracted procedure: k4761 
o|contracted procedure: k4783 
o|contracted procedure: k4779 
o|contracted procedure: k4764 
o|contracted procedure: k4767 
o|contracted procedure: k4775 
o|contracted procedure: k4807 
o|contracted procedure: k4810 
o|contracted procedure: k4813 
o|contracted procedure: k4821 
o|contracted procedure: k4829 
o|contracted procedure: k4877 
o|contracted procedure: k4841 
o|contracted procedure: k4867 
o|contracted procedure: k4871 
o|contracted procedure: k4863 
o|contracted procedure: k4844 
o|contracted procedure: k4847 
o|contracted procedure: k4855 
o|contracted procedure: k4859 
o|contracted procedure: k4889 
o|contracted procedure: k4892 
o|contracted procedure: k4895 
o|contracted procedure: k4903 
o|contracted procedure: k4911 
o|contracted procedure: k4973 
o|contracted procedure: k4937 
o|contracted procedure: k4963 
o|contracted procedure: k4967 
o|contracted procedure: k4959 
o|contracted procedure: k4940 
o|contracted procedure: k4943 
o|contracted procedure: k4951 
o|contracted procedure: k4955 
o|contracted procedure: k4989 
o|contracted procedure: k4992 
o|contracted procedure: k4995 
o|contracted procedure: k5003 
o|contracted procedure: k5017 
o|simplifications: ((let . 64)) 
o|removed binding forms: 289 
o|removed binding forms: 1 
o|direct leaf routine/allocation: lp433 0 
o|direct leaf routine/allocation: fetch1180 0 
o|direct leaf routine/allocation: push1183 3 
o|direct leaf routine/allocation: g923932 21 
o|direct leaf routine/allocation: g984993 6 
o|direct leaf routine/allocation: g688697 21 
o|direct leaf routine/allocation: g749758 6 
o|converted assignments to bindings: (lp433) 
o|contracted procedure: "(compiler-syntax.scm:241) k3310" 
o|contracted procedure: "(compiler-syntax.scm:243) k3319" 
o|inlining procedure: "(compiler-syntax.scm:246) k3328" 
o|inlining procedure: "(compiler-syntax.scm:247) k3328" 
o|inlining procedure: "(compiler-syntax.scm:248) k3328" 
o|inlining procedure: "(compiler-syntax.scm:250) k3328" 
o|inlining procedure: "(compiler-syntax.scm:254) k3328" 
o|inlining procedure: "(compiler-syntax.scm:258) k3328" 
o|inlining procedure: "(compiler-syntax.scm:261) k3328" 
o|inlining procedure: "(compiler-syntax.scm:265) k3328" 
o|inlining procedure: "(compiler-syntax.scm:266) k3328" 
o|contracted procedure: "(compiler-syntax.scm:270) k3516" 
o|contracted procedure: "(compiler-syntax.scm:272) k3532" 
o|contracted procedure: "(compiler-syntax.scm:129) k4344" 
o|contracted procedure: "(compiler-syntax.scm:125) k4426" 
o|contracted procedure: "(compiler-syntax.scm:92) k4825" 
o|contracted procedure: "(compiler-syntax.scm:88) k4907" 
o|simplifications: ((let . 1)) 
o|removed binding forms: 8 
o|customizable procedures: (k4606 map-loop621639 map-loop651670 map-loop682703 map-loop712731 map-loop743764 map-loop773794 map-loop803824 chicken.compiler.compiler-syntax#length+ k4089 map-loop856874 map-loop886905 map-loop917938 map-loop947966 map-loop978999 map-loop10081029 map-loop10381059 foldr10811084 chicken.compiler.compiler-syntax#compile-format-string chicken.compiler.compiler-syntax#r-c-s k3094 skip1250 next1181 loop1196 endchunk1182 fail1140 g551558 for-each-loop550561) 
o|calls to known targets: 84 
o|identified direct recursive calls: f_2791 1 
o|identified direct recursive calls: f_3520 1 
o|identified direct recursive calls: f_3259 1 
o|identified direct recursive calls: f_4005 1 
o|identified direct recursive calls: f_4213 1 
o|identified direct recursive calls: f_4275 1 
o|identified direct recursive calls: f_4321 1 
o|identified direct recursive calls: f_4355 1 
o|identified direct recursive calls: f_4403 1 
o|identified direct recursive calls: f_4459 1 
o|identified direct recursive calls: f_4710 1 
o|identified direct recursive calls: f_4756 1 
o|identified direct recursive calls: f_4802 1 
o|identified direct recursive calls: f_4836 1 
o|identified direct recursive calls: f_4884 1 
o|identified direct recursive calls: f_4932 1 
o|fast box initializations: 22 
o|fast global references: 13 
o|fast global assignments: 3 
o|dropping unused closure argument: f_2785 
o|dropping unused closure argument: f_2791 
o|dropping unused closure argument: f_2997 
o|dropping unused closure argument: f_3068 
*/
/* end of file */
