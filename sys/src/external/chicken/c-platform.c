/* Generated from c-platform.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: c-platform.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.c-platform -output-file c-platform.c
   unit: c-platform
   uses: eval internal compiler support optimizer library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_toplevel)
C_externimport void C_ccall C_compiler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_support_toplevel)
C_externimport void C_ccall C_support_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_optimizer_toplevel)
C_externimport void C_ccall C_optimizer_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[952];
static double C_possibly_force_alignment;


C_noret_decl(f_1679)
static void C_ccall f_1679(C_word c,C_word *av) C_noret;
C_noret_decl(f_1682)
static void C_ccall f_1682(C_word c,C_word *av) C_noret;
C_noret_decl(f_1685)
static void C_ccall f_1685(C_word c,C_word *av) C_noret;
C_noret_decl(f_1688)
static void C_ccall f_1688(C_word c,C_word *av) C_noret;
C_noret_decl(f_1691)
static void C_ccall f_1691(C_word c,C_word *av) C_noret;
C_noret_decl(f_1694)
static void C_ccall f_1694(C_word c,C_word *av) C_noret;
C_noret_decl(f_2129)
static void C_fcall f_2129(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2135)
static void C_fcall f_2135(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2149)
static void C_ccall f_2149(C_word c,C_word *av) C_noret;
C_noret_decl(f_2305)
static void C_fcall f_2305(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2314)
static void C_fcall f_2314(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2322)
static void C_fcall f_2322(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2329)
static void C_ccall f_2329(C_word c,C_word *av) C_noret;
C_noret_decl(f_2343)
static void C_ccall f_2343(C_word c,C_word *av) C_noret;
C_noret_decl(f_2471)
static C_word C_fcall f_2471(C_word t0);
C_noret_decl(f_2713)
static void C_fcall f_2713(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2727)
static void C_ccall f_2727(C_word c,C_word *av) C_noret;
C_noret_decl(f_2731)
static void C_ccall f_2731(C_word c,C_word *av) C_noret;
C_noret_decl(f_2975)
static void C_ccall f_2975(C_word c,C_word *av) C_noret;
C_noret_decl(f_2983)
static void C_ccall f_2983(C_word c,C_word *av) C_noret;
C_noret_decl(f_2986)
static void C_ccall f_2986(C_word c,C_word *av) C_noret;
C_noret_decl(f_2989)
static void C_ccall f_2989(C_word c,C_word *av) C_noret;
C_noret_decl(f_3004)
static void C_ccall f_3004(C_word c,C_word *av) C_noret;
C_noret_decl(f_3011)
static void C_ccall f_3011(C_word c,C_word *av) C_noret;
C_noret_decl(f_3020)
static void C_ccall f_3020(C_word c,C_word *av) C_noret;
C_noret_decl(f_3022)
static void C_fcall f_3022(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3024)
static void C_ccall f_3024(C_word c,C_word *av) C_noret;
C_noret_decl(f_3046)
static void C_ccall f_3046(C_word c,C_word *av) C_noret;
C_noret_decl(f_3079)
static void C_ccall f_3079(C_word c,C_word *av) C_noret;
C_noret_decl(f_3087)
static void C_ccall f_3087(C_word c,C_word *av) C_noret;
C_noret_decl(f_3090)
static void C_ccall f_3090(C_word c,C_word *av) C_noret;
C_noret_decl(f_3092)
static void C_ccall f_3092(C_word c,C_word *av) C_noret;
C_noret_decl(f_3108)
static void C_ccall f_3108(C_word c,C_word *av) C_noret;
C_noret_decl(f_3117)
static void C_fcall f_3117(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3120)
static void C_fcall f_3120(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3135)
static void C_ccall f_3135(C_word c,C_word *av) C_noret;
C_noret_decl(f_3147)
static void C_ccall f_3147(C_word c,C_word *av) C_noret;
C_noret_decl(f_3161)
static void C_ccall f_3161(C_word c,C_word *av) C_noret;
C_noret_decl(f_3165)
static void C_ccall f_3165(C_word c,C_word *av) C_noret;
C_noret_decl(f_3174)
static void C_ccall f_3174(C_word c,C_word *av) C_noret;
C_noret_decl(f_3188)
static void C_ccall f_3188(C_word c,C_word *av) C_noret;
C_noret_decl(f_3192)
static void C_ccall f_3192(C_word c,C_word *av) C_noret;
C_noret_decl(f_3222)
static void C_ccall f_3222(C_word c,C_word *av) C_noret;
C_noret_decl(f_3226)
static void C_ccall f_3226(C_word c,C_word *av) C_noret;
C_noret_decl(f_3230)
static void C_ccall f_3230(C_word c,C_word *av) C_noret;
C_noret_decl(f_3234)
static void C_ccall f_3234(C_word c,C_word *av) C_noret;
C_noret_decl(f_3238)
static void C_ccall f_3238(C_word c,C_word *av) C_noret;
C_noret_decl(f_3246)
static void C_ccall f_3246(C_word c,C_word *av) C_noret;
C_noret_decl(f_3249)
static void C_ccall f_3249(C_word c,C_word *av) C_noret;
C_noret_decl(f_3252)
static void C_ccall f_3252(C_word c,C_word *av) C_noret;
C_noret_decl(f_3254)
static void C_ccall f_3254(C_word c,C_word *av) C_noret;
C_noret_decl(f_3282)
static void C_ccall f_3282(C_word c,C_word *av) C_noret;
C_noret_decl(f_3290)
static void C_ccall f_3290(C_word c,C_word *av) C_noret;
C_noret_decl(f_3307)
static void C_ccall f_3307(C_word c,C_word *av) C_noret;
C_noret_decl(f_3309)
static void C_fcall f_3309(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3334)
static void C_ccall f_3334(C_word c,C_word *av) C_noret;
C_noret_decl(f_3345)
static void C_ccall f_3345(C_word c,C_word *av) C_noret;
C_noret_decl(f_3349)
static void C_ccall f_3349(C_word c,C_word *av) C_noret;
C_noret_decl(f_3352)
static void C_ccall f_3352(C_word c,C_word *av) C_noret;
C_noret_decl(f_3366)
static void C_ccall f_3366(C_word c,C_word *av) C_noret;
C_noret_decl(f_3370)
static void C_ccall f_3370(C_word c,C_word *av) C_noret;
C_noret_decl(f_3393)
static void C_ccall f_3393(C_word c,C_word *av) C_noret;
C_noret_decl(f_3408)
static void C_ccall f_3408(C_word c,C_word *av) C_noret;
C_noret_decl(f_3416)
static void C_ccall f_3416(C_word c,C_word *av) C_noret;
C_noret_decl(f_3425)
static void C_ccall f_3425(C_word c,C_word *av) C_noret;
C_noret_decl(f_3429)
static void C_ccall f_3429(C_word c,C_word *av) C_noret;
C_noret_decl(f_3432)
static void C_ccall f_3432(C_word c,C_word *av) C_noret;
C_noret_decl(f_3435)
static void C_ccall f_3435(C_word c,C_word *av) C_noret;
C_noret_decl(f_3437)
static void C_fcall f_3437(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3443)
static void C_ccall f_3443(C_word c,C_word *av) C_noret;
C_noret_decl(f_3455)
static void C_ccall f_3455(C_word c,C_word *av) C_noret;
C_noret_decl(f_3474)
static void C_ccall f_3474(C_word c,C_word *av) C_noret;
C_noret_decl(f_3505)
static void C_ccall f_3505(C_word c,C_word *av) C_noret;
C_noret_decl(f_3508)
static void C_ccall f_3508(C_word c,C_word *av) C_noret;
C_noret_decl(f_3511)
static void C_ccall f_3511(C_word c,C_word *av) C_noret;
C_noret_decl(f_3514)
static void C_ccall f_3514(C_word c,C_word *av) C_noret;
C_noret_decl(f_3517)
static void C_ccall f_3517(C_word c,C_word *av) C_noret;
C_noret_decl(f_3520)
static void C_ccall f_3520(C_word c,C_word *av) C_noret;
C_noret_decl(f_3521)
static void C_ccall f_3521(C_word c,C_word *av) C_noret;
C_noret_decl(f_3547)
static void C_ccall f_3547(C_word c,C_word *av) C_noret;
C_noret_decl(f_3550)
static void C_ccall f_3550(C_word c,C_word *av) C_noret;
C_noret_decl(f_3552)
static void C_ccall f_3552(C_word c,C_word *av) C_noret;
C_noret_decl(f_3586)
static void C_ccall f_3586(C_word c,C_word *av) C_noret;
C_noret_decl(f_3613)
static void C_ccall f_3613(C_word c,C_word *av) C_noret;
C_noret_decl(f_3616)
static void C_ccall f_3616(C_word c,C_word *av) C_noret;
C_noret_decl(f_3619)
static void C_ccall f_3619(C_word c,C_word *av) C_noret;
C_noret_decl(f_3634)
static void C_ccall f_3634(C_word c,C_word *av) C_noret;
C_noret_decl(f_3638)
static void C_ccall f_3638(C_word c,C_word *av) C_noret;
C_noret_decl(f_3650)
static void C_ccall f_3650(C_word c,C_word *av) C_noret;
C_noret_decl(f_3662)
static void C_ccall f_3662(C_word c,C_word *av) C_noret;
C_noret_decl(f_3674)
static void C_ccall f_3674(C_word c,C_word *av) C_noret;
C_noret_decl(f_3678)
static void C_ccall f_3678(C_word c,C_word *av) C_noret;
C_noret_decl(f_3686)
static void C_ccall f_3686(C_word c,C_word *av) C_noret;
C_noret_decl(f_3693)
static void C_ccall f_3693(C_word c,C_word *av) C_noret;
C_noret_decl(f_3697)
static void C_ccall f_3697(C_word c,C_word *av) C_noret;
C_noret_decl(f_3701)
static void C_ccall f_3701(C_word c,C_word *av) C_noret;
C_noret_decl(f_3705)
static void C_ccall f_3705(C_word c,C_word *av) C_noret;
C_noret_decl(f_3709)
static void C_ccall f_3709(C_word c,C_word *av) C_noret;
C_noret_decl(f_3717)
static void C_ccall f_3717(C_word c,C_word *av) C_noret;
C_noret_decl(f_3720)
static void C_ccall f_3720(C_word c,C_word *av) C_noret;
C_noret_decl(f_3723)
static void C_ccall f_3723(C_word c,C_word *av) C_noret;
C_noret_decl(f_3726)
static void C_ccall f_3726(C_word c,C_word *av) C_noret;
C_noret_decl(f_3729)
static void C_ccall f_3729(C_word c,C_word *av) C_noret;
C_noret_decl(f_3732)
static void C_ccall f_3732(C_word c,C_word *av) C_noret;
C_noret_decl(f_3735)
static void C_ccall f_3735(C_word c,C_word *av) C_noret;
C_noret_decl(f_3738)
static void C_ccall f_3738(C_word c,C_word *av) C_noret;
C_noret_decl(f_3741)
static void C_ccall f_3741(C_word c,C_word *av) C_noret;
C_noret_decl(f_3744)
static void C_ccall f_3744(C_word c,C_word *av) C_noret;
C_noret_decl(f_3747)
static void C_ccall f_3747(C_word c,C_word *av) C_noret;
C_noret_decl(f_3750)
static void C_ccall f_3750(C_word c,C_word *av) C_noret;
C_noret_decl(f_3753)
static void C_ccall f_3753(C_word c,C_word *av) C_noret;
C_noret_decl(f_3756)
static void C_ccall f_3756(C_word c,C_word *av) C_noret;
C_noret_decl(f_3759)
static void C_ccall f_3759(C_word c,C_word *av) C_noret;
C_noret_decl(f_3762)
static void C_ccall f_3762(C_word c,C_word *av) C_noret;
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
C_noret_decl(f_3783)
static void C_ccall f_3783(C_word c,C_word *av) C_noret;
C_noret_decl(f_3786)
static void C_ccall f_3786(C_word c,C_word *av) C_noret;
C_noret_decl(f_3789)
static void C_ccall f_3789(C_word c,C_word *av) C_noret;
C_noret_decl(f_3792)
static void C_ccall f_3792(C_word c,C_word *av) C_noret;
C_noret_decl(f_3795)
static void C_ccall f_3795(C_word c,C_word *av) C_noret;
C_noret_decl(f_3798)
static void C_ccall f_3798(C_word c,C_word *av) C_noret;
C_noret_decl(f_3801)
static void C_ccall f_3801(C_word c,C_word *av) C_noret;
C_noret_decl(f_3804)
static void C_ccall f_3804(C_word c,C_word *av) C_noret;
C_noret_decl(f_3807)
static void C_ccall f_3807(C_word c,C_word *av) C_noret;
C_noret_decl(f_3810)
static void C_ccall f_3810(C_word c,C_word *av) C_noret;
C_noret_decl(f_3813)
static void C_ccall f_3813(C_word c,C_word *av) C_noret;
C_noret_decl(f_3816)
static void C_ccall f_3816(C_word c,C_word *av) C_noret;
C_noret_decl(f_3819)
static void C_ccall f_3819(C_word c,C_word *av) C_noret;
C_noret_decl(f_3822)
static void C_ccall f_3822(C_word c,C_word *av) C_noret;
C_noret_decl(f_3825)
static void C_ccall f_3825(C_word c,C_word *av) C_noret;
C_noret_decl(f_3828)
static void C_ccall f_3828(C_word c,C_word *av) C_noret;
C_noret_decl(f_3831)
static void C_ccall f_3831(C_word c,C_word *av) C_noret;
C_noret_decl(f_3834)
static void C_ccall f_3834(C_word c,C_word *av) C_noret;
C_noret_decl(f_3837)
static void C_ccall f_3837(C_word c,C_word *av) C_noret;
C_noret_decl(f_3840)
static void C_ccall f_3840(C_word c,C_word *av) C_noret;
C_noret_decl(f_3843)
static void C_ccall f_3843(C_word c,C_word *av) C_noret;
C_noret_decl(f_3846)
static void C_ccall f_3846(C_word c,C_word *av) C_noret;
C_noret_decl(f_3849)
static void C_ccall f_3849(C_word c,C_word *av) C_noret;
C_noret_decl(f_3852)
static void C_ccall f_3852(C_word c,C_word *av) C_noret;
C_noret_decl(f_3855)
static void C_ccall f_3855(C_word c,C_word *av) C_noret;
C_noret_decl(f_3858)
static void C_ccall f_3858(C_word c,C_word *av) C_noret;
C_noret_decl(f_3861)
static void C_ccall f_3861(C_word c,C_word *av) C_noret;
C_noret_decl(f_3864)
static void C_ccall f_3864(C_word c,C_word *av) C_noret;
C_noret_decl(f_3867)
static void C_ccall f_3867(C_word c,C_word *av) C_noret;
C_noret_decl(f_3870)
static void C_ccall f_3870(C_word c,C_word *av) C_noret;
C_noret_decl(f_3873)
static void C_ccall f_3873(C_word c,C_word *av) C_noret;
C_noret_decl(f_3876)
static void C_ccall f_3876(C_word c,C_word *av) C_noret;
C_noret_decl(f_3879)
static void C_ccall f_3879(C_word c,C_word *av) C_noret;
C_noret_decl(f_3882)
static void C_ccall f_3882(C_word c,C_word *av) C_noret;
C_noret_decl(f_3885)
static void C_ccall f_3885(C_word c,C_word *av) C_noret;
C_noret_decl(f_3888)
static void C_ccall f_3888(C_word c,C_word *av) C_noret;
C_noret_decl(f_3891)
static void C_ccall f_3891(C_word c,C_word *av) C_noret;
C_noret_decl(f_3894)
static void C_ccall f_3894(C_word c,C_word *av) C_noret;
C_noret_decl(f_3897)
static void C_ccall f_3897(C_word c,C_word *av) C_noret;
C_noret_decl(f_3900)
static void C_ccall f_3900(C_word c,C_word *av) C_noret;
C_noret_decl(f_3903)
static void C_ccall f_3903(C_word c,C_word *av) C_noret;
C_noret_decl(f_3906)
static void C_ccall f_3906(C_word c,C_word *av) C_noret;
C_noret_decl(f_3909)
static void C_ccall f_3909(C_word c,C_word *av) C_noret;
C_noret_decl(f_3912)
static void C_ccall f_3912(C_word c,C_word *av) C_noret;
C_noret_decl(f_3915)
static void C_ccall f_3915(C_word c,C_word *av) C_noret;
C_noret_decl(f_3918)
static void C_ccall f_3918(C_word c,C_word *av) C_noret;
C_noret_decl(f_3921)
static void C_ccall f_3921(C_word c,C_word *av) C_noret;
C_noret_decl(f_3924)
static void C_ccall f_3924(C_word c,C_word *av) C_noret;
C_noret_decl(f_3927)
static void C_ccall f_3927(C_word c,C_word *av) C_noret;
C_noret_decl(f_3930)
static void C_ccall f_3930(C_word c,C_word *av) C_noret;
C_noret_decl(f_3933)
static void C_ccall f_3933(C_word c,C_word *av) C_noret;
C_noret_decl(f_3936)
static void C_ccall f_3936(C_word c,C_word *av) C_noret;
C_noret_decl(f_3939)
static void C_ccall f_3939(C_word c,C_word *av) C_noret;
C_noret_decl(f_3942)
static void C_ccall f_3942(C_word c,C_word *av) C_noret;
C_noret_decl(f_3945)
static void C_ccall f_3945(C_word c,C_word *av) C_noret;
C_noret_decl(f_3948)
static void C_ccall f_3948(C_word c,C_word *av) C_noret;
C_noret_decl(f_3951)
static void C_ccall f_3951(C_word c,C_word *av) C_noret;
C_noret_decl(f_3954)
static void C_ccall f_3954(C_word c,C_word *av) C_noret;
C_noret_decl(f_3957)
static void C_ccall f_3957(C_word c,C_word *av) C_noret;
C_noret_decl(f_3960)
static void C_ccall f_3960(C_word c,C_word *av) C_noret;
C_noret_decl(f_3963)
static void C_ccall f_3963(C_word c,C_word *av) C_noret;
C_noret_decl(f_3966)
static void C_ccall f_3966(C_word c,C_word *av) C_noret;
C_noret_decl(f_3969)
static void C_ccall f_3969(C_word c,C_word *av) C_noret;
C_noret_decl(f_3972)
static void C_ccall f_3972(C_word c,C_word *av) C_noret;
C_noret_decl(f_3975)
static void C_ccall f_3975(C_word c,C_word *av) C_noret;
C_noret_decl(f_3978)
static void C_ccall f_3978(C_word c,C_word *av) C_noret;
C_noret_decl(f_3981)
static void C_ccall f_3981(C_word c,C_word *av) C_noret;
C_noret_decl(f_3984)
static void C_ccall f_3984(C_word c,C_word *av) C_noret;
C_noret_decl(f_3987)
static void C_ccall f_3987(C_word c,C_word *av) C_noret;
C_noret_decl(f_3990)
static void C_ccall f_3990(C_word c,C_word *av) C_noret;
C_noret_decl(f_3993)
static void C_ccall f_3993(C_word c,C_word *av) C_noret;
C_noret_decl(f_3996)
static void C_ccall f_3996(C_word c,C_word *av) C_noret;
C_noret_decl(f_3999)
static void C_ccall f_3999(C_word c,C_word *av) C_noret;
C_noret_decl(f_4002)
static void C_ccall f_4002(C_word c,C_word *av) C_noret;
C_noret_decl(f_4005)
static void C_ccall f_4005(C_word c,C_word *av) C_noret;
C_noret_decl(f_4008)
static void C_ccall f_4008(C_word c,C_word *av) C_noret;
C_noret_decl(f_4011)
static void C_ccall f_4011(C_word c,C_word *av) C_noret;
C_noret_decl(f_4014)
static void C_ccall f_4014(C_word c,C_word *av) C_noret;
C_noret_decl(f_4017)
static void C_ccall f_4017(C_word c,C_word *av) C_noret;
C_noret_decl(f_4020)
static void C_ccall f_4020(C_word c,C_word *av) C_noret;
C_noret_decl(f_4023)
static void C_ccall f_4023(C_word c,C_word *av) C_noret;
C_noret_decl(f_4026)
static void C_ccall f_4026(C_word c,C_word *av) C_noret;
C_noret_decl(f_4029)
static void C_ccall f_4029(C_word c,C_word *av) C_noret;
C_noret_decl(f_4032)
static void C_ccall f_4032(C_word c,C_word *av) C_noret;
C_noret_decl(f_4035)
static void C_ccall f_4035(C_word c,C_word *av) C_noret;
C_noret_decl(f_4038)
static void C_ccall f_4038(C_word c,C_word *av) C_noret;
C_noret_decl(f_4041)
static void C_ccall f_4041(C_word c,C_word *av) C_noret;
C_noret_decl(f_4044)
static void C_ccall f_4044(C_word c,C_word *av) C_noret;
C_noret_decl(f_4047)
static void C_ccall f_4047(C_word c,C_word *av) C_noret;
C_noret_decl(f_4050)
static void C_ccall f_4050(C_word c,C_word *av) C_noret;
C_noret_decl(f_4053)
static void C_ccall f_4053(C_word c,C_word *av) C_noret;
C_noret_decl(f_4056)
static void C_ccall f_4056(C_word c,C_word *av) C_noret;
C_noret_decl(f_4059)
static void C_ccall f_4059(C_word c,C_word *av) C_noret;
C_noret_decl(f_4062)
static void C_ccall f_4062(C_word c,C_word *av) C_noret;
C_noret_decl(f_4065)
static void C_ccall f_4065(C_word c,C_word *av) C_noret;
C_noret_decl(f_4068)
static void C_ccall f_4068(C_word c,C_word *av) C_noret;
C_noret_decl(f_4071)
static void C_ccall f_4071(C_word c,C_word *av) C_noret;
C_noret_decl(f_4074)
static void C_ccall f_4074(C_word c,C_word *av) C_noret;
C_noret_decl(f_4077)
static void C_ccall f_4077(C_word c,C_word *av) C_noret;
C_noret_decl(f_4080)
static void C_ccall f_4080(C_word c,C_word *av) C_noret;
C_noret_decl(f_4083)
static void C_ccall f_4083(C_word c,C_word *av) C_noret;
C_noret_decl(f_4086)
static void C_ccall f_4086(C_word c,C_word *av) C_noret;
C_noret_decl(f_4089)
static void C_ccall f_4089(C_word c,C_word *av) C_noret;
C_noret_decl(f_4092)
static void C_ccall f_4092(C_word c,C_word *av) C_noret;
C_noret_decl(f_4095)
static void C_ccall f_4095(C_word c,C_word *av) C_noret;
C_noret_decl(f_4098)
static void C_ccall f_4098(C_word c,C_word *av) C_noret;
C_noret_decl(f_4101)
static void C_ccall f_4101(C_word c,C_word *av) C_noret;
C_noret_decl(f_4104)
static void C_ccall f_4104(C_word c,C_word *av) C_noret;
C_noret_decl(f_4107)
static void C_ccall f_4107(C_word c,C_word *av) C_noret;
C_noret_decl(f_4110)
static void C_ccall f_4110(C_word c,C_word *av) C_noret;
C_noret_decl(f_4113)
static void C_ccall f_4113(C_word c,C_word *av) C_noret;
C_noret_decl(f_4116)
static void C_ccall f_4116(C_word c,C_word *av) C_noret;
C_noret_decl(f_4119)
static void C_ccall f_4119(C_word c,C_word *av) C_noret;
C_noret_decl(f_4122)
static void C_ccall f_4122(C_word c,C_word *av) C_noret;
C_noret_decl(f_4125)
static void C_ccall f_4125(C_word c,C_word *av) C_noret;
C_noret_decl(f_4128)
static void C_ccall f_4128(C_word c,C_word *av) C_noret;
C_noret_decl(f_4131)
static void C_ccall f_4131(C_word c,C_word *av) C_noret;
C_noret_decl(f_4134)
static void C_ccall f_4134(C_word c,C_word *av) C_noret;
C_noret_decl(f_4137)
static void C_ccall f_4137(C_word c,C_word *av) C_noret;
C_noret_decl(f_4140)
static void C_ccall f_4140(C_word c,C_word *av) C_noret;
C_noret_decl(f_4143)
static void C_ccall f_4143(C_word c,C_word *av) C_noret;
C_noret_decl(f_4146)
static void C_ccall f_4146(C_word c,C_word *av) C_noret;
C_noret_decl(f_4149)
static void C_ccall f_4149(C_word c,C_word *av) C_noret;
C_noret_decl(f_4152)
static void C_ccall f_4152(C_word c,C_word *av) C_noret;
C_noret_decl(f_4155)
static void C_ccall f_4155(C_word c,C_word *av) C_noret;
C_noret_decl(f_4158)
static void C_ccall f_4158(C_word c,C_word *av) C_noret;
C_noret_decl(f_4161)
static void C_ccall f_4161(C_word c,C_word *av) C_noret;
C_noret_decl(f_4164)
static void C_ccall f_4164(C_word c,C_word *av) C_noret;
C_noret_decl(f_4167)
static void C_ccall f_4167(C_word c,C_word *av) C_noret;
C_noret_decl(f_4170)
static void C_ccall f_4170(C_word c,C_word *av) C_noret;
C_noret_decl(f_4173)
static void C_ccall f_4173(C_word c,C_word *av) C_noret;
C_noret_decl(f_4176)
static void C_ccall f_4176(C_word c,C_word *av) C_noret;
C_noret_decl(f_4179)
static void C_ccall f_4179(C_word c,C_word *av) C_noret;
C_noret_decl(f_4182)
static void C_ccall f_4182(C_word c,C_word *av) C_noret;
C_noret_decl(f_4185)
static void C_ccall f_4185(C_word c,C_word *av) C_noret;
C_noret_decl(f_4188)
static void C_ccall f_4188(C_word c,C_word *av) C_noret;
C_noret_decl(f_4191)
static void C_ccall f_4191(C_word c,C_word *av) C_noret;
C_noret_decl(f_4194)
static void C_ccall f_4194(C_word c,C_word *av) C_noret;
C_noret_decl(f_4197)
static void C_ccall f_4197(C_word c,C_word *av) C_noret;
C_noret_decl(f_4200)
static void C_ccall f_4200(C_word c,C_word *av) C_noret;
C_noret_decl(f_4203)
static void C_ccall f_4203(C_word c,C_word *av) C_noret;
C_noret_decl(f_4206)
static void C_ccall f_4206(C_word c,C_word *av) C_noret;
C_noret_decl(f_4209)
static void C_ccall f_4209(C_word c,C_word *av) C_noret;
C_noret_decl(f_4212)
static void C_ccall f_4212(C_word c,C_word *av) C_noret;
C_noret_decl(f_4215)
static void C_ccall f_4215(C_word c,C_word *av) C_noret;
C_noret_decl(f_4218)
static void C_ccall f_4218(C_word c,C_word *av) C_noret;
C_noret_decl(f_4221)
static void C_ccall f_4221(C_word c,C_word *av) C_noret;
C_noret_decl(f_4224)
static void C_ccall f_4224(C_word c,C_word *av) C_noret;
C_noret_decl(f_4227)
static void C_ccall f_4227(C_word c,C_word *av) C_noret;
C_noret_decl(f_4230)
static void C_ccall f_4230(C_word c,C_word *av) C_noret;
C_noret_decl(f_4233)
static void C_ccall f_4233(C_word c,C_word *av) C_noret;
C_noret_decl(f_4236)
static void C_ccall f_4236(C_word c,C_word *av) C_noret;
C_noret_decl(f_4239)
static void C_ccall f_4239(C_word c,C_word *av) C_noret;
C_noret_decl(f_4242)
static void C_ccall f_4242(C_word c,C_word *av) C_noret;
C_noret_decl(f_4245)
static void C_ccall f_4245(C_word c,C_word *av) C_noret;
C_noret_decl(f_4248)
static void C_ccall f_4248(C_word c,C_word *av) C_noret;
C_noret_decl(f_4251)
static void C_ccall f_4251(C_word c,C_word *av) C_noret;
C_noret_decl(f_4254)
static void C_ccall f_4254(C_word c,C_word *av) C_noret;
C_noret_decl(f_4257)
static void C_ccall f_4257(C_word c,C_word *av) C_noret;
C_noret_decl(f_4260)
static void C_ccall f_4260(C_word c,C_word *av) C_noret;
C_noret_decl(f_4263)
static void C_ccall f_4263(C_word c,C_word *av) C_noret;
C_noret_decl(f_4266)
static void C_ccall f_4266(C_word c,C_word *av) C_noret;
C_noret_decl(f_4269)
static void C_ccall f_4269(C_word c,C_word *av) C_noret;
C_noret_decl(f_4272)
static void C_ccall f_4272(C_word c,C_word *av) C_noret;
C_noret_decl(f_4275)
static void C_ccall f_4275(C_word c,C_word *av) C_noret;
C_noret_decl(f_4278)
static void C_ccall f_4278(C_word c,C_word *av) C_noret;
C_noret_decl(f_4281)
static void C_ccall f_4281(C_word c,C_word *av) C_noret;
C_noret_decl(f_4284)
static void C_ccall f_4284(C_word c,C_word *av) C_noret;
C_noret_decl(f_4287)
static void C_ccall f_4287(C_word c,C_word *av) C_noret;
C_noret_decl(f_4290)
static void C_ccall f_4290(C_word c,C_word *av) C_noret;
C_noret_decl(f_4293)
static void C_ccall f_4293(C_word c,C_word *av) C_noret;
C_noret_decl(f_4296)
static void C_ccall f_4296(C_word c,C_word *av) C_noret;
C_noret_decl(f_4299)
static void C_ccall f_4299(C_word c,C_word *av) C_noret;
C_noret_decl(f_4302)
static void C_ccall f_4302(C_word c,C_word *av) C_noret;
C_noret_decl(f_4305)
static void C_ccall f_4305(C_word c,C_word *av) C_noret;
C_noret_decl(f_4308)
static void C_ccall f_4308(C_word c,C_word *av) C_noret;
C_noret_decl(f_4311)
static void C_ccall f_4311(C_word c,C_word *av) C_noret;
C_noret_decl(f_4314)
static void C_ccall f_4314(C_word c,C_word *av) C_noret;
C_noret_decl(f_4317)
static void C_ccall f_4317(C_word c,C_word *av) C_noret;
C_noret_decl(f_4320)
static void C_ccall f_4320(C_word c,C_word *av) C_noret;
C_noret_decl(f_4323)
static void C_ccall f_4323(C_word c,C_word *av) C_noret;
C_noret_decl(f_4326)
static void C_ccall f_4326(C_word c,C_word *av) C_noret;
C_noret_decl(f_4329)
static void C_ccall f_4329(C_word c,C_word *av) C_noret;
C_noret_decl(f_4332)
static void C_ccall f_4332(C_word c,C_word *av) C_noret;
C_noret_decl(f_4335)
static void C_ccall f_4335(C_word c,C_word *av) C_noret;
C_noret_decl(f_4338)
static void C_ccall f_4338(C_word c,C_word *av) C_noret;
C_noret_decl(f_4341)
static void C_ccall f_4341(C_word c,C_word *av) C_noret;
C_noret_decl(f_4344)
static void C_ccall f_4344(C_word c,C_word *av) C_noret;
C_noret_decl(f_4347)
static void C_ccall f_4347(C_word c,C_word *av) C_noret;
C_noret_decl(f_4350)
static void C_ccall f_4350(C_word c,C_word *av) C_noret;
C_noret_decl(f_4353)
static void C_ccall f_4353(C_word c,C_word *av) C_noret;
C_noret_decl(f_4356)
static void C_ccall f_4356(C_word c,C_word *av) C_noret;
C_noret_decl(f_4359)
static void C_ccall f_4359(C_word c,C_word *av) C_noret;
C_noret_decl(f_4362)
static void C_ccall f_4362(C_word c,C_word *av) C_noret;
C_noret_decl(f_4365)
static void C_ccall f_4365(C_word c,C_word *av) C_noret;
C_noret_decl(f_4368)
static void C_ccall f_4368(C_word c,C_word *av) C_noret;
C_noret_decl(f_4371)
static void C_ccall f_4371(C_word c,C_word *av) C_noret;
C_noret_decl(f_4374)
static void C_ccall f_4374(C_word c,C_word *av) C_noret;
C_noret_decl(f_4377)
static void C_ccall f_4377(C_word c,C_word *av) C_noret;
C_noret_decl(f_4380)
static void C_ccall f_4380(C_word c,C_word *av) C_noret;
C_noret_decl(f_4383)
static void C_ccall f_4383(C_word c,C_word *av) C_noret;
C_noret_decl(f_4386)
static void C_ccall f_4386(C_word c,C_word *av) C_noret;
C_noret_decl(f_4389)
static void C_ccall f_4389(C_word c,C_word *av) C_noret;
C_noret_decl(f_4392)
static void C_ccall f_4392(C_word c,C_word *av) C_noret;
C_noret_decl(f_4395)
static void C_ccall f_4395(C_word c,C_word *av) C_noret;
C_noret_decl(f_4398)
static void C_ccall f_4398(C_word c,C_word *av) C_noret;
C_noret_decl(f_4401)
static void C_ccall f_4401(C_word c,C_word *av) C_noret;
C_noret_decl(f_4404)
static void C_ccall f_4404(C_word c,C_word *av) C_noret;
C_noret_decl(f_4407)
static void C_ccall f_4407(C_word c,C_word *av) C_noret;
C_noret_decl(f_4410)
static void C_ccall f_4410(C_word c,C_word *av) C_noret;
C_noret_decl(f_4413)
static void C_ccall f_4413(C_word c,C_word *av) C_noret;
C_noret_decl(f_4416)
static void C_ccall f_4416(C_word c,C_word *av) C_noret;
C_noret_decl(f_4419)
static void C_ccall f_4419(C_word c,C_word *av) C_noret;
C_noret_decl(f_4422)
static void C_ccall f_4422(C_word c,C_word *av) C_noret;
C_noret_decl(f_4425)
static void C_ccall f_4425(C_word c,C_word *av) C_noret;
C_noret_decl(f_4428)
static void C_ccall f_4428(C_word c,C_word *av) C_noret;
C_noret_decl(f_4431)
static void C_ccall f_4431(C_word c,C_word *av) C_noret;
C_noret_decl(f_4434)
static void C_ccall f_4434(C_word c,C_word *av) C_noret;
C_noret_decl(f_4437)
static void C_ccall f_4437(C_word c,C_word *av) C_noret;
C_noret_decl(f_4440)
static void C_ccall f_4440(C_word c,C_word *av) C_noret;
C_noret_decl(f_4443)
static void C_ccall f_4443(C_word c,C_word *av) C_noret;
C_noret_decl(f_4446)
static void C_ccall f_4446(C_word c,C_word *av) C_noret;
C_noret_decl(f_4449)
static void C_ccall f_4449(C_word c,C_word *av) C_noret;
C_noret_decl(f_4452)
static void C_ccall f_4452(C_word c,C_word *av) C_noret;
C_noret_decl(f_4455)
static void C_ccall f_4455(C_word c,C_word *av) C_noret;
C_noret_decl(f_4458)
static void C_ccall f_4458(C_word c,C_word *av) C_noret;
C_noret_decl(f_4460)
static void C_ccall f_4460(C_word c,C_word *av) C_noret;
C_noret_decl(f_4497)
static void C_ccall f_4497(C_word c,C_word *av) C_noret;
C_noret_decl(f_4499)
static void C_ccall f_4499(C_word c,C_word *av) C_noret;
C_noret_decl(f_4506)
static void C_fcall f_4506(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4517)
static void C_ccall f_4517(C_word c,C_word *av) C_noret;
C_noret_decl(f_4538)
static void C_ccall f_4538(C_word c,C_word *av) C_noret;
C_noret_decl(f_4542)
static void C_ccall f_4542(C_word c,C_word *av) C_noret;
C_noret_decl(f_4555)
static void C_ccall f_4555(C_word c,C_word *av) C_noret;
C_noret_decl(f_4557)
static void C_ccall f_4557(C_word c,C_word *av) C_noret;
C_noret_decl(f_4579)
static void C_ccall f_4579(C_word c,C_word *av) C_noret;
C_noret_decl(f_4583)
static void C_ccall f_4583(C_word c,C_word *av) C_noret;
C_noret_decl(f_4593)
static void C_ccall f_4593(C_word c,C_word *av) C_noret;
C_noret_decl(f_4596)
static void C_ccall f_4596(C_word c,C_word *av) C_noret;
C_noret_decl(f_4599)
static void C_ccall f_4599(C_word c,C_word *av) C_noret;
C_noret_decl(f_4602)
static void C_ccall f_4602(C_word c,C_word *av) C_noret;
C_noret_decl(f_4605)
static void C_ccall f_4605(C_word c,C_word *av) C_noret;
C_noret_decl(f_4608)
static void C_ccall f_4608(C_word c,C_word *av) C_noret;
C_noret_decl(f_4611)
static void C_ccall f_4611(C_word c,C_word *av) C_noret;
C_noret_decl(f_4614)
static void C_ccall f_4614(C_word c,C_word *av) C_noret;
C_noret_decl(f_4617)
static void C_ccall f_4617(C_word c,C_word *av) C_noret;
C_noret_decl(f_4620)
static void C_ccall f_4620(C_word c,C_word *av) C_noret;
C_noret_decl(f_4623)
static void C_ccall f_4623(C_word c,C_word *av) C_noret;
C_noret_decl(f_4626)
static void C_ccall f_4626(C_word c,C_word *av) C_noret;
C_noret_decl(f_4629)
static void C_ccall f_4629(C_word c,C_word *av) C_noret;
C_noret_decl(f_4632)
static void C_ccall f_4632(C_word c,C_word *av) C_noret;
C_noret_decl(f_4635)
static void C_ccall f_4635(C_word c,C_word *av) C_noret;
C_noret_decl(f_4638)
static void C_ccall f_4638(C_word c,C_word *av) C_noret;
C_noret_decl(f_4641)
static void C_ccall f_4641(C_word c,C_word *av) C_noret;
C_noret_decl(f_4644)
static void C_ccall f_4644(C_word c,C_word *av) C_noret;
C_noret_decl(f_4647)
static void C_ccall f_4647(C_word c,C_word *av) C_noret;
C_noret_decl(f_4650)
static void C_ccall f_4650(C_word c,C_word *av) C_noret;
C_noret_decl(f_4653)
static void C_ccall f_4653(C_word c,C_word *av) C_noret;
C_noret_decl(f_4656)
static void C_ccall f_4656(C_word c,C_word *av) C_noret;
C_noret_decl(f_4659)
static void C_ccall f_4659(C_word c,C_word *av) C_noret;
C_noret_decl(f_4662)
static void C_ccall f_4662(C_word c,C_word *av) C_noret;
C_noret_decl(f_4665)
static void C_ccall f_4665(C_word c,C_word *av) C_noret;
C_noret_decl(f_4668)
static void C_ccall f_4668(C_word c,C_word *av) C_noret;
C_noret_decl(f_4671)
static void C_ccall f_4671(C_word c,C_word *av) C_noret;
C_noret_decl(f_4674)
static void C_ccall f_4674(C_word c,C_word *av) C_noret;
C_noret_decl(f_4677)
static void C_ccall f_4677(C_word c,C_word *av) C_noret;
C_noret_decl(f_4680)
static void C_ccall f_4680(C_word c,C_word *av) C_noret;
C_noret_decl(f_4683)
static void C_ccall f_4683(C_word c,C_word *av) C_noret;
C_noret_decl(f_4686)
static void C_ccall f_4686(C_word c,C_word *av) C_noret;
C_noret_decl(f_4689)
static void C_ccall f_4689(C_word c,C_word *av) C_noret;
C_noret_decl(f_4692)
static void C_ccall f_4692(C_word c,C_word *av) C_noret;
C_noret_decl(f_4695)
static void C_ccall f_4695(C_word c,C_word *av) C_noret;
C_noret_decl(f_4698)
static void C_ccall f_4698(C_word c,C_word *av) C_noret;
C_noret_decl(f_4701)
static void C_ccall f_4701(C_word c,C_word *av) C_noret;
C_noret_decl(f_4704)
static void C_ccall f_4704(C_word c,C_word *av) C_noret;
C_noret_decl(f_4707)
static void C_ccall f_4707(C_word c,C_word *av) C_noret;
C_noret_decl(f_4710)
static void C_ccall f_4710(C_word c,C_word *av) C_noret;
C_noret_decl(f_4713)
static void C_ccall f_4713(C_word c,C_word *av) C_noret;
C_noret_decl(f_4716)
static void C_ccall f_4716(C_word c,C_word *av) C_noret;
C_noret_decl(f_4719)
static void C_ccall f_4719(C_word c,C_word *av) C_noret;
C_noret_decl(f_4722)
static void C_ccall f_4722(C_word c,C_word *av) C_noret;
C_noret_decl(f_4725)
static void C_ccall f_4725(C_word c,C_word *av) C_noret;
C_noret_decl(f_4728)
static void C_ccall f_4728(C_word c,C_word *av) C_noret;
C_noret_decl(f_4731)
static void C_ccall f_4731(C_word c,C_word *av) C_noret;
C_noret_decl(f_4734)
static void C_ccall f_4734(C_word c,C_word *av) C_noret;
C_noret_decl(f_4737)
static void C_ccall f_4737(C_word c,C_word *av) C_noret;
C_noret_decl(f_4740)
static void C_ccall f_4740(C_word c,C_word *av) C_noret;
C_noret_decl(f_4743)
static void C_ccall f_4743(C_word c,C_word *av) C_noret;
C_noret_decl(f_4746)
static void C_ccall f_4746(C_word c,C_word *av) C_noret;
C_noret_decl(f_4749)
static void C_ccall f_4749(C_word c,C_word *av) C_noret;
C_noret_decl(f_4752)
static void C_ccall f_4752(C_word c,C_word *av) C_noret;
C_noret_decl(f_4755)
static void C_ccall f_4755(C_word c,C_word *av) C_noret;
C_noret_decl(f_4758)
static void C_ccall f_4758(C_word c,C_word *av) C_noret;
C_noret_decl(f_4761)
static void C_ccall f_4761(C_word c,C_word *av) C_noret;
C_noret_decl(f_4764)
static void C_ccall f_4764(C_word c,C_word *av) C_noret;
C_noret_decl(f_4767)
static void C_ccall f_4767(C_word c,C_word *av) C_noret;
C_noret_decl(f_4770)
static void C_ccall f_4770(C_word c,C_word *av) C_noret;
C_noret_decl(f_4773)
static void C_ccall f_4773(C_word c,C_word *av) C_noret;
C_noret_decl(f_4776)
static void C_ccall f_4776(C_word c,C_word *av) C_noret;
C_noret_decl(f_4779)
static void C_ccall f_4779(C_word c,C_word *av) C_noret;
C_noret_decl(f_4782)
static void C_ccall f_4782(C_word c,C_word *av) C_noret;
C_noret_decl(f_4785)
static void C_ccall f_4785(C_word c,C_word *av) C_noret;
C_noret_decl(f_4788)
static void C_ccall f_4788(C_word c,C_word *av) C_noret;
C_noret_decl(f_4791)
static void C_ccall f_4791(C_word c,C_word *av) C_noret;
C_noret_decl(f_4794)
static void C_ccall f_4794(C_word c,C_word *av) C_noret;
C_noret_decl(f_4797)
static void C_ccall f_4797(C_word c,C_word *av) C_noret;
C_noret_decl(f_4800)
static void C_ccall f_4800(C_word c,C_word *av) C_noret;
C_noret_decl(f_4803)
static void C_ccall f_4803(C_word c,C_word *av) C_noret;
C_noret_decl(f_4806)
static void C_ccall f_4806(C_word c,C_word *av) C_noret;
C_noret_decl(f_4809)
static void C_ccall f_4809(C_word c,C_word *av) C_noret;
C_noret_decl(f_4812)
static void C_ccall f_4812(C_word c,C_word *av) C_noret;
C_noret_decl(f_4815)
static void C_ccall f_4815(C_word c,C_word *av) C_noret;
C_noret_decl(f_4818)
static void C_ccall f_4818(C_word c,C_word *av) C_noret;
C_noret_decl(f_4821)
static void C_ccall f_4821(C_word c,C_word *av) C_noret;
C_noret_decl(f_4824)
static void C_ccall f_4824(C_word c,C_word *av) C_noret;
C_noret_decl(f_4827)
static void C_ccall f_4827(C_word c,C_word *av) C_noret;
C_noret_decl(f_4830)
static void C_ccall f_4830(C_word c,C_word *av) C_noret;
C_noret_decl(f_4833)
static void C_ccall f_4833(C_word c,C_word *av) C_noret;
C_noret_decl(f_4836)
static void C_ccall f_4836(C_word c,C_word *av) C_noret;
C_noret_decl(f_4839)
static void C_ccall f_4839(C_word c,C_word *av) C_noret;
C_noret_decl(f_4842)
static void C_ccall f_4842(C_word c,C_word *av) C_noret;
C_noret_decl(f_4845)
static void C_ccall f_4845(C_word c,C_word *av) C_noret;
C_noret_decl(f_4848)
static void C_ccall f_4848(C_word c,C_word *av) C_noret;
C_noret_decl(f_4851)
static void C_ccall f_4851(C_word c,C_word *av) C_noret;
C_noret_decl(f_4854)
static void C_ccall f_4854(C_word c,C_word *av) C_noret;
C_noret_decl(f_4857)
static void C_ccall f_4857(C_word c,C_word *av) C_noret;
C_noret_decl(f_4860)
static void C_ccall f_4860(C_word c,C_word *av) C_noret;
C_noret_decl(f_4863)
static void C_ccall f_4863(C_word c,C_word *av) C_noret;
C_noret_decl(f_4866)
static void C_ccall f_4866(C_word c,C_word *av) C_noret;
C_noret_decl(f_4869)
static void C_ccall f_4869(C_word c,C_word *av) C_noret;
C_noret_decl(f_4872)
static void C_ccall f_4872(C_word c,C_word *av) C_noret;
C_noret_decl(f_4875)
static void C_ccall f_4875(C_word c,C_word *av) C_noret;
C_noret_decl(f_4878)
static void C_ccall f_4878(C_word c,C_word *av) C_noret;
C_noret_decl(f_4881)
static void C_ccall f_4881(C_word c,C_word *av) C_noret;
C_noret_decl(f_4884)
static void C_ccall f_4884(C_word c,C_word *av) C_noret;
C_noret_decl(f_4887)
static void C_ccall f_4887(C_word c,C_word *av) C_noret;
C_noret_decl(f_4890)
static void C_ccall f_4890(C_word c,C_word *av) C_noret;
C_noret_decl(f_4893)
static void C_ccall f_4893(C_word c,C_word *av) C_noret;
C_noret_decl(f_4896)
static void C_ccall f_4896(C_word c,C_word *av) C_noret;
C_noret_decl(f_4899)
static void C_ccall f_4899(C_word c,C_word *av) C_noret;
C_noret_decl(f_4902)
static void C_ccall f_4902(C_word c,C_word *av) C_noret;
C_noret_decl(f_4905)
static void C_ccall f_4905(C_word c,C_word *av) C_noret;
C_noret_decl(f_4908)
static void C_ccall f_4908(C_word c,C_word *av) C_noret;
C_noret_decl(f_4911)
static void C_ccall f_4911(C_word c,C_word *av) C_noret;
C_noret_decl(f_4914)
static void C_ccall f_4914(C_word c,C_word *av) C_noret;
C_noret_decl(f_4917)
static void C_ccall f_4917(C_word c,C_word *av) C_noret;
C_noret_decl(f_4920)
static void C_ccall f_4920(C_word c,C_word *av) C_noret;
C_noret_decl(f_4923)
static void C_ccall f_4923(C_word c,C_word *av) C_noret;
C_noret_decl(f_4926)
static void C_ccall f_4926(C_word c,C_word *av) C_noret;
C_noret_decl(f_4929)
static void C_ccall f_4929(C_word c,C_word *av) C_noret;
C_noret_decl(f_4932)
static void C_ccall f_4932(C_word c,C_word *av) C_noret;
C_noret_decl(f_4935)
static void C_ccall f_4935(C_word c,C_word *av) C_noret;
C_noret_decl(f_4938)
static void C_ccall f_4938(C_word c,C_word *av) C_noret;
C_noret_decl(f_4941)
static void C_ccall f_4941(C_word c,C_word *av) C_noret;
C_noret_decl(f_4944)
static void C_ccall f_4944(C_word c,C_word *av) C_noret;
C_noret_decl(f_4947)
static void C_ccall f_4947(C_word c,C_word *av) C_noret;
C_noret_decl(f_4950)
static void C_ccall f_4950(C_word c,C_word *av) C_noret;
C_noret_decl(f_4953)
static void C_ccall f_4953(C_word c,C_word *av) C_noret;
C_noret_decl(f_4956)
static void C_ccall f_4956(C_word c,C_word *av) C_noret;
C_noret_decl(f_4959)
static void C_ccall f_4959(C_word c,C_word *av) C_noret;
C_noret_decl(f_4962)
static void C_ccall f_4962(C_word c,C_word *av) C_noret;
C_noret_decl(f_4965)
static void C_ccall f_4965(C_word c,C_word *av) C_noret;
C_noret_decl(f_4968)
static void C_ccall f_4968(C_word c,C_word *av) C_noret;
C_noret_decl(f_4971)
static void C_ccall f_4971(C_word c,C_word *av) C_noret;
C_noret_decl(f_4974)
static void C_ccall f_4974(C_word c,C_word *av) C_noret;
C_noret_decl(f_4977)
static void C_ccall f_4977(C_word c,C_word *av) C_noret;
C_noret_decl(f_4980)
static void C_ccall f_4980(C_word c,C_word *av) C_noret;
C_noret_decl(f_4983)
static void C_ccall f_4983(C_word c,C_word *av) C_noret;
C_noret_decl(f_4986)
static void C_ccall f_4986(C_word c,C_word *av) C_noret;
C_noret_decl(f_4989)
static void C_ccall f_4989(C_word c,C_word *av) C_noret;
C_noret_decl(f_4992)
static void C_ccall f_4992(C_word c,C_word *av) C_noret;
C_noret_decl(f_4995)
static void C_ccall f_4995(C_word c,C_word *av) C_noret;
C_noret_decl(f_4998)
static void C_ccall f_4998(C_word c,C_word *av) C_noret;
C_noret_decl(f_5001)
static void C_ccall f_5001(C_word c,C_word *av) C_noret;
C_noret_decl(f_5004)
static void C_ccall f_5004(C_word c,C_word *av) C_noret;
C_noret_decl(f_5007)
static void C_ccall f_5007(C_word c,C_word *av) C_noret;
C_noret_decl(f_5010)
static void C_ccall f_5010(C_word c,C_word *av) C_noret;
C_noret_decl(f_5013)
static void C_ccall f_5013(C_word c,C_word *av) C_noret;
C_noret_decl(f_5016)
static void C_ccall f_5016(C_word c,C_word *av) C_noret;
C_noret_decl(f_5019)
static void C_ccall f_5019(C_word c,C_word *av) C_noret;
C_noret_decl(f_5022)
static void C_ccall f_5022(C_word c,C_word *av) C_noret;
C_noret_decl(f_5025)
static void C_ccall f_5025(C_word c,C_word *av) C_noret;
C_noret_decl(f_5028)
static void C_ccall f_5028(C_word c,C_word *av) C_noret;
C_noret_decl(f_5031)
static void C_ccall f_5031(C_word c,C_word *av) C_noret;
C_noret_decl(f_5034)
static void C_ccall f_5034(C_word c,C_word *av) C_noret;
C_noret_decl(f_5037)
static void C_ccall f_5037(C_word c,C_word *av) C_noret;
C_noret_decl(f_5040)
static void C_ccall f_5040(C_word c,C_word *av) C_noret;
C_noret_decl(f_5043)
static void C_ccall f_5043(C_word c,C_word *av) C_noret;
C_noret_decl(f_5046)
static void C_ccall f_5046(C_word c,C_word *av) C_noret;
C_noret_decl(f_5049)
static void C_ccall f_5049(C_word c,C_word *av) C_noret;
C_noret_decl(f_5052)
static void C_ccall f_5052(C_word c,C_word *av) C_noret;
C_noret_decl(f_5055)
static void C_ccall f_5055(C_word c,C_word *av) C_noret;
C_noret_decl(f_5058)
static void C_ccall f_5058(C_word c,C_word *av) C_noret;
C_noret_decl(f_5061)
static void C_ccall f_5061(C_word c,C_word *av) C_noret;
C_noret_decl(f_5064)
static void C_ccall f_5064(C_word c,C_word *av) C_noret;
C_noret_decl(f_5067)
static void C_ccall f_5067(C_word c,C_word *av) C_noret;
C_noret_decl(f_5070)
static void C_ccall f_5070(C_word c,C_word *av) C_noret;
C_noret_decl(f_5073)
static void C_ccall f_5073(C_word c,C_word *av) C_noret;
C_noret_decl(f_5076)
static void C_ccall f_5076(C_word c,C_word *av) C_noret;
C_noret_decl(f_5079)
static void C_ccall f_5079(C_word c,C_word *av) C_noret;
C_noret_decl(f_5082)
static void C_ccall f_5082(C_word c,C_word *av) C_noret;
C_noret_decl(f_5085)
static void C_ccall f_5085(C_word c,C_word *av) C_noret;
C_noret_decl(f_5088)
static void C_ccall f_5088(C_word c,C_word *av) C_noret;
C_noret_decl(f_5091)
static void C_ccall f_5091(C_word c,C_word *av) C_noret;
C_noret_decl(f_5094)
static void C_ccall f_5094(C_word c,C_word *av) C_noret;
C_noret_decl(f_5097)
static void C_ccall f_5097(C_word c,C_word *av) C_noret;
C_noret_decl(f_5100)
static void C_ccall f_5100(C_word c,C_word *av) C_noret;
C_noret_decl(f_5103)
static void C_ccall f_5103(C_word c,C_word *av) C_noret;
C_noret_decl(f_5106)
static void C_ccall f_5106(C_word c,C_word *av) C_noret;
C_noret_decl(f_5109)
static void C_ccall f_5109(C_word c,C_word *av) C_noret;
C_noret_decl(f_5112)
static void C_ccall f_5112(C_word c,C_word *av) C_noret;
C_noret_decl(f_5115)
static void C_ccall f_5115(C_word c,C_word *av) C_noret;
C_noret_decl(f_5118)
static void C_ccall f_5118(C_word c,C_word *av) C_noret;
C_noret_decl(f_5121)
static void C_ccall f_5121(C_word c,C_word *av) C_noret;
C_noret_decl(f_5124)
static void C_ccall f_5124(C_word c,C_word *av) C_noret;
C_noret_decl(f_5127)
static void C_ccall f_5127(C_word c,C_word *av) C_noret;
C_noret_decl(f_5130)
static void C_ccall f_5130(C_word c,C_word *av) C_noret;
C_noret_decl(f_5133)
static void C_ccall f_5133(C_word c,C_word *av) C_noret;
C_noret_decl(f_5136)
static void C_ccall f_5136(C_word c,C_word *av) C_noret;
C_noret_decl(f_5139)
static void C_ccall f_5139(C_word c,C_word *av) C_noret;
C_noret_decl(f_5142)
static void C_ccall f_5142(C_word c,C_word *av) C_noret;
C_noret_decl(f_5145)
static void C_ccall f_5145(C_word c,C_word *av) C_noret;
C_noret_decl(f_5148)
static void C_ccall f_5148(C_word c,C_word *av) C_noret;
C_noret_decl(f_5151)
static void C_ccall f_5151(C_word c,C_word *av) C_noret;
C_noret_decl(f_5154)
static void C_ccall f_5154(C_word c,C_word *av) C_noret;
C_noret_decl(f_5157)
static void C_ccall f_5157(C_word c,C_word *av) C_noret;
C_noret_decl(f_5160)
static void C_ccall f_5160(C_word c,C_word *av) C_noret;
C_noret_decl(f_5163)
static void C_ccall f_5163(C_word c,C_word *av) C_noret;
C_noret_decl(f_5166)
static void C_ccall f_5166(C_word c,C_word *av) C_noret;
C_noret_decl(f_5169)
static void C_ccall f_5169(C_word c,C_word *av) C_noret;
C_noret_decl(f_5172)
static void C_ccall f_5172(C_word c,C_word *av) C_noret;
C_noret_decl(f_5174)
static void C_ccall f_5174(C_word c,C_word *av) C_noret;
C_noret_decl(f_5196)
static void C_ccall f_5196(C_word c,C_word *av) C_noret;
C_noret_decl(f_5211)
static void C_ccall f_5211(C_word c,C_word *av) C_noret;
C_noret_decl(f_5214)
static void C_ccall f_5214(C_word c,C_word *av) C_noret;
C_noret_decl(f_5229)
static void C_ccall f_5229(C_word c,C_word *av) C_noret;
C_noret_decl(f_5241)
static void C_ccall f_5241(C_word c,C_word *av) C_noret;
C_noret_decl(f_5249)
static void C_ccall f_5249(C_word c,C_word *av) C_noret;
C_noret_decl(f_5251)
static void C_fcall f_5251(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5272)
static void C_ccall f_5272(C_word c,C_word *av) C_noret;
C_noret_decl(f_5276)
static void C_ccall f_5276(C_word c,C_word *av) C_noret;
C_noret_decl(f_5279)
static void C_ccall f_5279(C_word c,C_word *av) C_noret;
C_noret_decl(f_5282)
static void C_ccall f_5282(C_word c,C_word *av) C_noret;
C_noret_decl(f_5284)
static void C_ccall f_5284(C_word c,C_word *av) C_noret;
C_noret_decl(f_5303)
static void C_ccall f_5303(C_word c,C_word *av) C_noret;
C_noret_decl(f_5320)
static void C_ccall f_5320(C_word c,C_word *av) C_noret;
C_noret_decl(f_5363)
static void C_ccall f_5363(C_word c,C_word *av) C_noret;
C_noret_decl(f_5367)
static void C_ccall f_5367(C_word c,C_word *av) C_noret;
C_noret_decl(f_5371)
static void C_ccall f_5371(C_word c,C_word *av) C_noret;
C_noret_decl(f_5375)
static void C_ccall f_5375(C_word c,C_word *av) C_noret;
C_noret_decl(f_5382)
static void C_ccall f_5382(C_word c,C_word *av) C_noret;
C_noret_decl(f_5386)
static void C_ccall f_5386(C_word c,C_word *av) C_noret;
C_noret_decl(f_5394)
static void C_ccall f_5394(C_word c,C_word *av) C_noret;
C_noret_decl(f_5398)
static void C_ccall f_5398(C_word c,C_word *av) C_noret;
C_noret_decl(f_5406)
static void C_ccall f_5406(C_word c,C_word *av) C_noret;
C_noret_decl(f_5409)
static void C_ccall f_5409(C_word c,C_word *av) C_noret;
C_noret_decl(f_5413)
static void C_ccall f_5413(C_word c,C_word *av) C_noret;
C_noret_decl(f_5416)
static void C_ccall f_5416(C_word c,C_word *av) C_noret;
C_noret_decl(f_5419)
static void C_ccall f_5419(C_word c,C_word *av) C_noret;
C_noret_decl(f_5422)
static void C_ccall f_5422(C_word c,C_word *av) C_noret;
C_noret_decl(f_5425)
static void C_ccall f_5425(C_word c,C_word *av) C_noret;
C_noret_decl(f_5428)
static void C_ccall f_5428(C_word c,C_word *av) C_noret;
C_noret_decl(f_5431)
static void C_ccall f_5431(C_word c,C_word *av) C_noret;
C_noret_decl(f_5434)
static void C_ccall f_5434(C_word c,C_word *av) C_noret;
C_noret_decl(f_5437)
static void C_ccall f_5437(C_word c,C_word *av) C_noret;
C_noret_decl(f_5440)
static void C_ccall f_5440(C_word c,C_word *av) C_noret;
C_noret_decl(f_5443)
static void C_ccall f_5443(C_word c,C_word *av) C_noret;
C_noret_decl(f_5446)
static void C_ccall f_5446(C_word c,C_word *av) C_noret;
C_noret_decl(f_5449)
static void C_ccall f_5449(C_word c,C_word *av) C_noret;
C_noret_decl(f_5452)
static void C_ccall f_5452(C_word c,C_word *av) C_noret;
C_noret_decl(f_5455)
static void C_ccall f_5455(C_word c,C_word *av) C_noret;
C_noret_decl(f_5458)
static void C_ccall f_5458(C_word c,C_word *av) C_noret;
C_noret_decl(f_5460)
static void C_ccall f_5460(C_word c,C_word *av) C_noret;
C_noret_decl(f_5482)
static void C_ccall f_5482(C_word c,C_word *av) C_noret;
C_noret_decl(f_5500)
static void C_ccall f_5500(C_word c,C_word *av) C_noret;
C_noret_decl(f_5522)
static void C_ccall f_5522(C_word c,C_word *av) C_noret;
C_noret_decl(f_5540)
static void C_ccall f_5540(C_word c,C_word *av) C_noret;
C_noret_decl(f_5565)
static void C_ccall f_5565(C_word c,C_word *av) C_noret;
C_noret_decl(f_5586)
static void C_ccall f_5586(C_word c,C_word *av) C_noret;
C_noret_decl(f_5594)
static void C_ccall f_5594(C_word c,C_word *av) C_noret;
C_noret_decl(f_5598)
static void C_ccall f_5598(C_word c,C_word *av) C_noret;
C_noret_decl(f_5605)
static void C_ccall f_5605(C_word c,C_word *av) C_noret;
C_noret_decl(f_5633)
static void C_ccall f_5633(C_word c,C_word *av) C_noret;
C_noret_decl(f_5636)
static void C_ccall f_5636(C_word c,C_word *av) C_noret;
C_noret_decl(f_5667)
static void C_fcall f_5667(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5689)
static void C_ccall f_5689(C_word c,C_word *av) C_noret;
C_noret_decl(f_5712)
static void C_ccall f_5712(C_word c,C_word *av) C_noret;
C_noret_decl(f_5716)
static void C_ccall f_5716(C_word c,C_word *av) C_noret;
C_noret_decl(f_5720)
static void C_ccall f_5720(C_word c,C_word *av) C_noret;
C_noret_decl(f_5727)
static void C_ccall f_5727(C_word c,C_word *av) C_noret;
C_noret_decl(f_5749)
static void C_ccall f_5749(C_word c,C_word *av) C_noret;
C_noret_decl(f_5759)
static void C_ccall f_5759(C_word c,C_word *av) C_noret;
C_noret_decl(f_5773)
static void C_ccall f_5773(C_word c,C_word *av) C_noret;
C_noret_decl(f_5777)
static void C_ccall f_5777(C_word c,C_word *av) C_noret;
C_noret_decl(f_5784)
static void C_ccall f_5784(C_word c,C_word *av) C_noret;
C_noret_decl(f_5815)
static void C_ccall f_5815(C_word c,C_word *av) C_noret;
C_noret_decl(f_5818)
static void C_fcall f_5818(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5833)
static void C_ccall f_5833(C_word c,C_word *av) C_noret;
C_noret_decl(f_5850)
static void C_ccall f_5850(C_word c,C_word *av) C_noret;
C_noret_decl(f_5854)
static void C_ccall f_5854(C_word c,C_word *av) C_noret;
C_noret_decl(f_5861)
static void C_ccall f_5861(C_word c,C_word *av) C_noret;
C_noret_decl(f_5892)
static void C_ccall f_5892(C_word c,C_word *av) C_noret;
C_noret_decl(f_5920)
static void C_ccall f_5920(C_word c,C_word *av) C_noret;
C_noret_decl(f_5922)
static void C_ccall f_5922(C_word c,C_word *av) C_noret;
C_noret_decl(f_5945)
static void C_ccall f_5945(C_word c,C_word *av) C_noret;
C_noret_decl(f_5947)
static void C_ccall f_5947(C_word c,C_word *av) C_noret;
C_noret_decl(f_5966)
static void C_ccall f_5966(C_word c,C_word *av) C_noret;
C_noret_decl(f_5970)
static void C_ccall f_5970(C_word c,C_word *av) C_noret;
C_noret_decl(f_5985)
static void C_ccall f_5985(C_word c,C_word *av) C_noret;
C_noret_decl(f_6016)
static void C_ccall f_6016(C_word c,C_word *av) C_noret;
C_noret_decl(f_6044)
static void C_ccall f_6044(C_word c,C_word *av) C_noret;
C_noret_decl(f_6046)
static void C_ccall f_6046(C_word c,C_word *av) C_noret;
C_noret_decl(f_6069)
static void C_ccall f_6069(C_word c,C_word *av) C_noret;
C_noret_decl(f_6071)
static void C_ccall f_6071(C_word c,C_word *av) C_noret;
C_noret_decl(f_6090)
static void C_ccall f_6090(C_word c,C_word *av) C_noret;
C_noret_decl(f_6094)
static void C_ccall f_6094(C_word c,C_word *av) C_noret;
C_noret_decl(f_6109)
static void C_ccall f_6109(C_word c,C_word *av) C_noret;
C_noret_decl(f_6113)
static void C_ccall f_6113(C_word c,C_word *av) C_noret;
C_noret_decl(f_6134)
static void C_ccall f_6134(C_word c,C_word *av) C_noret;
C_noret_decl(f_6176)
static void C_ccall f_6176(C_word c,C_word *av) C_noret;
C_noret_decl(f_6178)
static void C_ccall f_6178(C_word c,C_word *av) C_noret;
C_noret_decl(f_6185)
static void C_fcall f_6185(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6196)
static void C_ccall f_6196(C_word c,C_word *av) C_noret;
C_noret_decl(f_6217)
static void C_ccall f_6217(C_word c,C_word *av) C_noret;
C_noret_decl(f_6221)
static void C_ccall f_6221(C_word c,C_word *av) C_noret;
C_noret_decl(f_6227)
static void C_ccall f_6227(C_word c,C_word *av) C_noret;
C_noret_decl(f_6249)
static void C_ccall f_6249(C_word c,C_word *av) C_noret;
C_noret_decl(f_6253)
static void C_ccall f_6253(C_word c,C_word *av) C_noret;
C_noret_decl(f_6255)
static void C_ccall f_6255(C_word c,C_word *av) C_noret;
C_noret_decl(f_6271)
static void C_ccall f_6271(C_word c,C_word *av) C_noret;
C_noret_decl(f_6277)
static void C_ccall f_6277(C_word c,C_word *av) C_noret;
C_noret_decl(f_6295)
static void C_ccall f_6295(C_word c,C_word *av) C_noret;
C_noret_decl(f_6298)
static void C_fcall f_6298(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6301)
static void C_fcall f_6301(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6316)
static void C_ccall f_6316(C_word c,C_word *av) C_noret;
C_noret_decl(f_6328)
static void C_ccall f_6328(C_word c,C_word *av) C_noret;
C_noret_decl(f_6338)
static void C_ccall f_6338(C_word c,C_word *av) C_noret;
C_noret_decl(f_6342)
static void C_ccall f_6342(C_word c,C_word *av) C_noret;
C_noret_decl(f_6351)
static void C_ccall f_6351(C_word c,C_word *av) C_noret;
C_noret_decl(f_6361)
static void C_ccall f_6361(C_word c,C_word *av) C_noret;
C_noret_decl(f_6365)
static void C_ccall f_6365(C_word c,C_word *av) C_noret;
C_noret_decl(f_6395)
static void C_ccall f_6395(C_word c,C_word *av) C_noret;
C_noret_decl(f_6399)
static void C_ccall f_6399(C_word c,C_word *av) C_noret;
C_noret_decl(f_6403)
static void C_ccall f_6403(C_word c,C_word *av) C_noret;
C_noret_decl(f_6407)
static void C_ccall f_6407(C_word c,C_word *av) C_noret;
C_noret_decl(f_6411)
static void C_ccall f_6411(C_word c,C_word *av) C_noret;
C_noret_decl(f_6420)
static void C_ccall f_6420(C_word c,C_word *av) C_noret;
C_noret_decl(f_6424)
static void C_ccall f_6424(C_word c,C_word *av) C_noret;
C_noret_decl(f_6426)
static void C_fcall f_6426(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6436)
static void C_ccall f_6436(C_word c,C_word *av) C_noret;
C_noret_decl(f_6449)
static void C_fcall f_6449(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6474)
static void C_ccall f_6474(C_word c,C_word *av) C_noret;
C_noret_decl(C_c_2dplatform_toplevel)
C_externexport void C_ccall C_c_2dplatform_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_2129)
static void C_ccall trf_2129(C_word c,C_word *av) C_noret;
static void C_ccall trf_2129(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2129(t0,t1,t2);}

C_noret_decl(trf_2135)
static void C_ccall trf_2135(C_word c,C_word *av) C_noret;
static void C_ccall trf_2135(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2135(t0,t1,t2,t3);}

C_noret_decl(trf_2305)
static void C_ccall trf_2305(C_word c,C_word *av) C_noret;
static void C_ccall trf_2305(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2305(t0,t1,t2);}

C_noret_decl(trf_2314)
static void C_ccall trf_2314(C_word c,C_word *av) C_noret;
static void C_ccall trf_2314(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2314(t0,t1,t2);}

C_noret_decl(trf_2322)
static void C_ccall trf_2322(C_word c,C_word *av) C_noret;
static void C_ccall trf_2322(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2322(t0,t1,t2,t3);}

C_noret_decl(trf_2713)
static void C_ccall trf_2713(C_word c,C_word *av) C_noret;
static void C_ccall trf_2713(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2713(t0,t1,t2);}

C_noret_decl(trf_3022)
static void C_ccall trf_3022(C_word c,C_word *av) C_noret;
static void C_ccall trf_3022(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3022(t0,t1,t2,t3);}

C_noret_decl(trf_3117)
static void C_ccall trf_3117(C_word c,C_word *av) C_noret;
static void C_ccall trf_3117(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3117(t0,t1);}

C_noret_decl(trf_3120)
static void C_ccall trf_3120(C_word c,C_word *av) C_noret;
static void C_ccall trf_3120(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3120(t0,t1);}

C_noret_decl(trf_3309)
static void C_ccall trf_3309(C_word c,C_word *av) C_noret;
static void C_ccall trf_3309(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3309(t0,t1,t2);}

C_noret_decl(trf_3437)
static void C_ccall trf_3437(C_word c,C_word *av) C_noret;
static void C_ccall trf_3437(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3437(t0,t1,t2,t3);}

C_noret_decl(trf_4506)
static void C_ccall trf_4506(C_word c,C_word *av) C_noret;
static void C_ccall trf_4506(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4506(t0,t1);}

C_noret_decl(trf_5251)
static void C_ccall trf_5251(C_word c,C_word *av) C_noret;
static void C_ccall trf_5251(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5251(t0,t1);}

C_noret_decl(trf_5667)
static void C_ccall trf_5667(C_word c,C_word *av) C_noret;
static void C_ccall trf_5667(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5667(t0,t1);}

C_noret_decl(trf_5818)
static void C_ccall trf_5818(C_word c,C_word *av) C_noret;
static void C_ccall trf_5818(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5818(t0,t1);}

C_noret_decl(trf_6185)
static void C_ccall trf_6185(C_word c,C_word *av) C_noret;
static void C_ccall trf_6185(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6185(t0,t1);}

C_noret_decl(trf_6298)
static void C_ccall trf_6298(C_word c,C_word *av) C_noret;
static void C_ccall trf_6298(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6298(t0,t1);}

C_noret_decl(trf_6301)
static void C_ccall trf_6301(C_word c,C_word *av) C_noret;
static void C_ccall trf_6301(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6301(t0,t1);}

C_noret_decl(trf_6426)
static void C_ccall trf_6426(C_word c,C_word *av) C_noret;
static void C_ccall trf_6426(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6426(t0,t1,t2);}

C_noret_decl(trf_6449)
static void C_ccall trf_6449(C_word c,C_word *av) C_noret;
static void C_ccall trf_6449(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6449(t0,t1,t2);}

/* k1677 */
static void C_ccall f_1679(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1679,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1682,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k1680 in k1677 */
static void C_ccall f_1682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1682,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1685,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k1683 in k1680 in k1677 */
static void C_ccall f_1685(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1685,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1688,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_optimizer_toplevel(2,av2);}}

/* k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_1688(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1688,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1691,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_support_toplevel(2,av2);}}

/* k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_1691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1691,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1694,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_compiler_toplevel(2,av2);}}

/* k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_1694(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_1694,c,av);}
a=C_alloc(23);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=C_mutate(&lf[2] /* (set! chicken.compiler.c-platform#cons* ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2129,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate(&lf[3] /* (set! chicken.compiler.c-platform#filter ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2305,tmp=(C_word)a,a+=2,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2975,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:55: chicken.compiler.optimizer#default-optimization-passes */
t7=*((C_word*)lf[951]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=C_fix(3);
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* chicken.compiler.c-platform#cons* in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_2129(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_2129,3,t1,t2,t3);}
a=C_alloc(5);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2135,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_2135(t7,t1,t2,t3);}

/* loop in chicken.compiler.c-platform#cons* in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_2135(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_2135,4,t0,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2149,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:95: loop */
t6=t4;
t7=C_i_car(t3);
t8=C_u_i_cdr(t3);
t1=t6;
t2=t7;
t3=t8;
goto loop;}}

/* k2147 in loop in chicken.compiler.c-platform#cons* in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2149,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.c-platform#filter in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_2305(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2305,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_check_list_2(t3,lf[4]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2314,a[2]=t2,a[3]=t6,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_2314(t8,t1,t3);}

/* foldr260 in chicken.compiler.c-platform#filter in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_2314(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_2314,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2322,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2343,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g265 in foldr260 in chicken.compiler.c-platform#filter in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_2322(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2322,4,t0,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2329,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:131: pred */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2327 in g265 in foldr260 in chicken.compiler.c-platform#filter in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2329,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]):((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2341 in foldr260 in chicken.compiler.c-platform#filter in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2343(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2343,c,av);}
/* mini-srfi-1.scm:131: g265 */
t2=((C_word*)t0)[2];
f_2322(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* loop in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static C_word C_fcall f_2471(C_word t1){
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

/* loop in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_fcall f_2713(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2713,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2727,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:190: proc */
t4=((C_word*)t0)[4];
f_5251(t4,t3);}}

/* k2725 in loop in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in ... */
static void C_ccall f_2727(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2727,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2731,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:190: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2713(t3,t2,C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* k2729 in k2725 in loop in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in ... */
static void C_ccall f_2731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2731,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2975(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2975,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[5]+1 /* (set! chicken.compiler.c-platform#default-declarations ...) */,lf[6]);
t3=C_mutate((C_word*)lf[7]+1 /* (set! chicken.compiler.c-platform#default-profiling-declarations ...) */,lf[8]);
t4=C_mutate((C_word*)lf[9]+1 /* (set! chicken.compiler.c-platform#default-units ...) */,lf[10]);
t5=C_set_block_item(lf[11] /* chicken.compiler.c-platform#words-per-flonum */,0,C_fix(4));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2983,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:85: chicken.compiler.optimizer#eq-inline-operator */
t7=*((C_word*)lf[949]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[950];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2983,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2986,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:86: chicken.compiler.optimizer#membership-test-operators */
t3=*((C_word*)lf[947]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[948];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2986,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2989,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:89: chicken.compiler.optimizer#membership-unfold-limit */
t3=*((C_word*)lf[946]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(20);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_2989(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_2989,c,av);}
a=C_alloc(15);
t2=C_mutate((C_word*)lf[12]+1 /* (set! chicken.compiler.c-platform#target-include-file ...) */,lf[13]);
t3=C_mutate((C_word*)lf[14]+1 /* (set! chicken.compiler.c-platform#valid-compiler-options ...) */,lf[15]);
t4=C_mutate((C_word*)lf[16]+1 /* (set! chicken.compiler.c-platform#valid-compiler-options-with-argument ...) */,lf[17]);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3004,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6449,a[2]=t7,a[3]=t11,a[4]=t8,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_6449(t13,t9,lf[945]);}

/* k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3004,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[18]+1 /* (set! chicken.compiler.core#default-standard-bindings ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3011,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:266: scheme#append */
t4=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[940];
av2[3]=lf[941];
av2[4]=lf[942];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3011(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3011,c,av);}
a=C_alloc(8);
t2=C_mutate((C_word*)lf[19]+1 /* (set! chicken.compiler.core#default-extended-bindings ...) */,t1);
t3=C_mutate((C_word*)lf[20]+1 /* (set! chicken.compiler.core#internal-bindings ...) */,lf[21]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3020,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6426,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_6426(t8,t4,lf[939]);}

/* k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_3020,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3022,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3087,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6424,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:320: op1 */
f_3022(t4,lf[934],lf[935],lf[936]);}

/* op1 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_3022(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,6)))){
C_save_and_reclaim_args((void *)trf_3022,4,t1,t2,t3,t4);}
a=C_alloc(5);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3024,a[2]=t3,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* f_3024 in op1 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3024(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_3024,c,av);}
a=C_alloc(19);
t6=C_i_length(t5);
t7=C_eqp(t6,C_fix(1));
if(C_truep(t7)){
t8=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3046,a[2]=t4,a[3]=t1,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
t10=C_eqp(lf[24],*((C_word*)lf[25]+1));
if(C_truep(t10)){
t11=(C_truep(*((C_word*)lf[26]+1))?C_a_i_list1(&a,1,((C_word*)t0)[2]):C_a_i_list1(&a,1,((C_word*)t0)[3]));
/* c-platform.scm:316: chicken.compiler.support#make-node */
t12=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t9;
av2[2]=lf[27];
av2[3]=t11;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}
else{
t11=C_a_i_list2(&a,2,((C_word*)t0)[4],C_fix(36));
t12=C_i_car(t5);
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3079,a[2]=t12,a[3]=t9,a[4]=t11,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:319: chicken.compiler.support#qnode */
t14=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t14;
av2[1]=t13;
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t14+1)))(3,av2);}}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3044 */
static void C_ccall f_3046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3046,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:311: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3077 */
static void C_ccall f_3079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3079,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:317: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[28];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3087,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3090,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6420,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:321: op1 */
f_3022(t3,lf[930],lf[931],lf[932]);}

/* k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_3090,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3092,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3246,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:344: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[833];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3092(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3092,c,av);}
a=C_alloc(13);
t6=C_i_length(t5);
t7=C_eqp(t6,C_fix(2));
if(C_truep(t7)){
t8=C_i_car(t5);
t9=C_i_cadr(t5);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3108,a[2]=t1,a[3]=t4,a[4]=t5,a[5]=t9,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3238,a[2]=t4,a[3]=t10,a[4]=t9,a[5]=t8,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:331: chicken.compiler.support#node-class */
t12=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3108(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3108,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3117,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3192,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:335: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k3115 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_3117(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_3117,2,t0,t1);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3120,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=t2;
f_3120(t3,t1);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3165,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:338: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k3118 in k3115 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_3120(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_3120,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3135,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:343: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[27];
av2[3]=lf[30];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3133 in k3118 in k3115 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3135,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:341: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3145 in k3159 in k3163 in k3115 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3147(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3147,c,av);}
t2=((C_word*)t0)[2];
f_3120(t2,(C_truep(t1)?t1:C_i_not(C_i_numberp(((C_word*)t0)[3]))));}

/* k3159 in k3163 in k3115 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3161(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3161,c,av);}
a=C_alloc(4);
t2=C_i_car(t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3147,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:340: chicken.compiler.support#immediate? */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3163 in k3115 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3165(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3165,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3161,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:339: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_3120(t3,C_SCHEME_FALSE);}}

/* k3172 in k3186 in k3190 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3174(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3174,c,av);}
t2=((C_word*)t0)[2];
f_3117(t2,(C_truep(t1)?t1:C_i_not(C_i_numberp(((C_word*)t0)[3]))));}

/* k3186 in k3190 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3188,c,av);}
a=C_alloc(4);
t2=C_i_car(t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3174,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:337: chicken.compiler.support#immediate? */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3190 in k3106 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3192,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3188,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:336: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_3117(t3,C_SCHEME_FALSE);}}

/* k3220 in k3228 in k3224 in k3232 in k3236 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3222,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:334: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3224 in k3232 in k3236 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3226(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3226,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3230,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:333: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[33]+1);{
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

/* k3228 in k3224 in k3232 in k3236 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3230,c,av);}
a=C_alloc(8);
if(C_truep(C_i_equalp(((C_word*)t0)[2],t1))){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3222,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:334: chicken.compiler.support#qnode */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_3108(2,av2);}}}

/* k3232 in k3236 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3234(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3234,c,av);}
a=C_alloc(5);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3226,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:333: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_3108(2,av2);}}}

/* k3236 in eqv?-id in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3238(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3238,c,av);}
a=C_alloc(6);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3234,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:332: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_3108(2,av2);}}}

/* k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3246,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3249,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:345: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[831];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_3249,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3252,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6255,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:347: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[928];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3252(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_3252,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3254,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3432,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:402: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[925];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3254(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3254,c,av);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t5))){
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2471,tmp=(C_word)a,a+=2,tmp);
t7=(
  f_2471(t5)
);
t8=C_u_i_car(t5);
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3429,a[2]=t1,a[3]=t5,a[4]=t4,a[5]=t7,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:382: chicken.compiler.support#node-class */
t10=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=t7;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k3280 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3282,c,av);}
/* c-platform.scm:383: chicken.compiler.support#make-node */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3288 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3290,c,av);}
a=C_alloc(6);
/* c-platform.scm:385: cons* */
f_2129(((C_word*)t0)[2],((C_word*)t0)[3],C_a_i_list(&a,2,((C_word*)t0)[4],t1));}

/* k3305 in k3343 in k3347 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_ccall f_3307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3307,c,av);}
/* c-platform.scm:387: scheme#append */
t2=*((C_word*)lf[37]+1);{
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

/* map-loop700 in k3343 in k3347 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_fcall f_3309(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3309,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3334,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:387: g706 */
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

/* k3332 in map-loop700 in k3343 in k3347 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in ... */
static void C_ccall f_3334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3334,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3309(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k3343 in k3347 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_3345(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_3345,c,av);}
a=C_alloc(12);
t2=C_i_car(t1);
t3=C_i_check_list_2(t2,lf[36]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3307,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3309,a[2]=((C_word*)t0)[4],a[3]=t6,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp));
t8=((C_word*)t6)[1];
f_3309(t8,t4,t2);}

/* k3347 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3349(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_3349,c,av);}
a=C_alloc(12);
t2=C_i_cdr(t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=*((C_word*)lf[29]+1);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3345,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t5,a[5]=t7,a[6]=t6,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:387: chicken.compiler.support#node-parameters */
t9=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k3350 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_3352,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3366,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3370,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:400: chicken.compiler.support#make-node */
t5=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[39];
av2[3]=lf[40];
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k3364 in k3350 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_3366(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3366,c,av);}
/* c-platform.scm:398: chicken.compiler.support#make-node */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3368 in k3350 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_3370(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3370,c,av);}
a=C_alloc(6);
/* c-platform.scm:400: cons* */
f_2129(((C_word*)t0)[2],t1,C_a_i_list(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]));}

/* k3391 in k3414 in k3423 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_ccall f_3393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_3393,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3408,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:395: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[39];
av2[3]=lf[43];
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_3352(2,av2);}}}

/* k3406 in k3391 in k3414 in k3423 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in ... */
static void C_ccall f_3408(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_3408,c,av);}
a=C_alloc(9);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list3(&a,3,t1,((C_word*)t0)[3],t2);
/* c-platform.scm:393: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[5];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3414 in k3423 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_3416(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3416,c,av);}
a=C_alloc(5);
t2=C_i_car(t1);
if(C_truep((C_truep(C_eqp(t2,lf[41]))?C_SCHEME_TRUE:(C_truep(C_eqp(t2,lf[42]))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3393,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:392: chicken.compiler.support#intrinsic? */
t4=*((C_word*)lf[44]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_3352(2,av2);}}}

/* k3423 in k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3425,c,av);}
a=C_alloc(5);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=C_i_length(((C_word*)t0)[2]);
t4=C_eqp(C_fix(2),t3);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3416,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:390: chicken.compiler.support#node-parameters */
t6=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_3352(2,av2);}}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_3352(2,av2);}}}

/* k3427 in rewrite-apply in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3429(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_3429,c,av);}
a=C_alloc(16);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=C_a_i_list1(&a,1,C_SCHEME_FALSE);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3282,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_i_car(((C_word*)t0)[3]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3290,a[2]=t4,a[3]=t5,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3349,a[2]=t6,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:387: chicken.base#butlast */
t8=*((C_word*)lf[38]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3352,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3425,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:388: chicken.compiler.support#node-class */
t5=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3432(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3432,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3435,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:403: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[924];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3435(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_3435,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3437,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3505,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:424: rewrite-c..r */
f_3437(t3,lf[921],lf[922],lf[923]);}

/* rewrite-c..r in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_3437(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,6)))){
C_save_and_reclaim_args((void *)trf_3437,4,t1,t2,t3,t4);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3443,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:407: chicken.compiler.optimizer#rewrite */
t6=*((C_word*)lf[46]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(8);
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* a3442 in rewrite-c..r in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_3443(C_word c,C_word *av){
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
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_3443,c,av);}
a=C_alloc(6);
t6=C_i_length(t5);
t7=C_eqp(t6,C_fix(1));
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3455,a[2]=t5,a[3]=t4,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:413: scheme#call-with-current-continuation */
t9=*((C_word*)lf[45]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t1;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* a3454 in a3442 in rewrite-c..r in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_ccall f_3455(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_3455,c,av);}
a=C_alloc(11);
t3=C_i_car(((C_word*)t0)[2]);
t4=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3474,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(C_truep(*((C_word*)lf[26]+1))?((C_word*)t0)[4]:C_SCHEME_FALSE);
if(C_truep(t6)){
t7=C_a_i_list1(&a,1,((C_word*)t0)[4]);
/* c-platform.scm:420: chicken.compiler.support#make-node */
t8=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[27];
av2[3]=t7;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}
else{
if(C_truep(((C_word*)t0)[5])){
t7=C_a_i_list1(&a,1,((C_word*)t0)[5]);
/* c-platform.scm:421: chicken.compiler.support#make-node */
t8=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t5;
av2[2]=lf[27];
av2[3]=t7;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}
else{
/* c-platform.scm:422: return */
t7=t2;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}}

/* k3472 in a3454 in a3442 in rewrite-c..r in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in ... */
static void C_ccall f_3474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3474,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:416: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_3505(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3505,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3508,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:425: rewrite-c..r */
f_3437(t2,lf[918],lf[919],lf[920]);}

/* k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_3508(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3508,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3511,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:426: rewrite-c..r */
f_3437(t2,lf[915],lf[916],lf[917]);}

/* k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_ccall f_3511(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3511,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3514,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:427: rewrite-c..r */
f_3437(t2,lf[912],lf[913],lf[914]);}

/* k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in ... */
static void C_ccall f_3514(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3514,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3517,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:428: rewrite-c..r */
f_3437(t2,lf[888],lf[910],lf[911]);}

/* k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in ... */
static void C_ccall f_3517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3517,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3520,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:429: rewrite-c..r */
f_3437(t2,lf[867],lf[908],lf[909]);}

/* k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in ... */
static void C_ccall f_3520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_3520,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3521,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3547,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:436: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[906];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* rvalues in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in ... */
static void C_ccall f_3521(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3521,c,av);}
a=C_alloc(6);
t6=C_i_length(t5);
t7=C_eqp(t6,C_fix(1));
if(C_truep(t7)){
t8=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t9=C_a_i_cons(&a,2,t4,t5);
/* c-platform.scm:435: chicken.compiler.support#make-node */
t10=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t1;
av2[2]=lf[23];
av2[3]=t8;
av2[4]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in ... */
static void C_ccall f_3547(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3547,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3550,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:437: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[42];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in ... */
static void C_ccall f_3550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_3550,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3552,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3717,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:468: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[902];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in ... */
static void C_ccall f_3552(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3552,c,av);}
a=C_alloc(7);
t6=C_i_length(t5);
t7=C_eqp(C_fix(2),t6);
if(C_truep(t7)){
t8=C_i_car(t5);
t9=C_i_cadr(t5);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3709,a[2]=t1,a[3]=t8,a[4]=t9,a[5]=t4,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:446: chicken.compiler.support#node-class */
t11=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in ... */
static void C_ccall f_3586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3586,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3697,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:450: chicken.compiler.support#node-class */
t3=*((C_word*)lf[34]+1);{
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
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in ... */
static void C_ccall f_3613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3613,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3616,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* c-platform.scm:455: chicken.base#gensym */
t3=*((C_word*)lf[50]+1);{
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

/* k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in ... */
static void C_ccall f_3616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3616,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3619,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3686,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:456: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in ... */
static void C_ccall f_3619(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3619,c,av);}
a=C_alloc(15);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3634,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3678,a[2]=((C_word*)t0)[5],a[3]=t3,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:461: chicken.base#gensym */
t5=*((C_word*)lf[50]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[51];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3632 in k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in ... */
static void C_ccall f_3634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3634,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3638,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3650,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:467: chicken.compiler.support#varnode */
t5=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3636 in k3632 in k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in ... */
static void C_ccall f_3638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3638,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:457: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[48];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3648 in k3632 in k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in ... */
static void C_ccall f_3650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3650,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:465: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3660 in k3676 in k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in ... */
static void C_ccall f_3662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3662,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* c-platform.scm:459: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[47];
av2[3]=((C_word*)t0)[3];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3672 in k3676 in k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in ... */
static void C_ccall f_3674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_3674,c,av);}
a=C_alloc(9);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
/* c-platform.scm:462: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[5];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3676 in k3617 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in ... */
static void C_ccall f_3678(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,2)))){
C_save_and_reclaim((void *)f_3678,c,av);}
a=C_alloc(28);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=C_a_i_list4(&a,4,t1,C_SCHEME_FALSE,t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3662,a[2]=((C_word*)t0)[3],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3674,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t4,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:464: chicken.compiler.support#varnode */
t7=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k3684 in k3614 in k3611 in k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in ... */
static void C_ccall f_3686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3686,c,av);}
/* c-platform.scm:456: chicken.compiler.support#debugging */
t2=*((C_word*)lf[52]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[53];
av2[3]=lf[54];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k3691 in k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in ... */
static void C_ccall f_3693(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3693,c,av);}
a=C_alloc(7);
t2=C_i_caddr(t1);
if(C_truep(C_i_listp(t2))){
t3=C_eqp(C_fix(2),C_u_i_length(t2));
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3613,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:454: chicken.base#gensym */
t5=*((C_word*)lf[50]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3695 in k3584 in k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in ... */
static void C_ccall f_3697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3697,c,av);}
a=C_alloc(7);
t2=C_eqp(lf[47],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3693,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:451: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3699 in k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in ... */
static void C_ccall f_3701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3701,c,av);}
a=C_alloc(6);
t2=C_i_car(t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3586,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:449: chicken.compiler.support#db-get */
t4=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
av2[3]=t2;
av2[4]=lf[57];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3703 in k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in ... */
static void C_ccall f_3705(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3705,c,av);}
a=C_alloc(7);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3701,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:448: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3707 in rewrite-c-w-v in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in ... */
static void C_ccall f_3709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3709,c,av);}
a=C_alloc(7);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3705,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:447: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in ... */
static void C_ccall f_3717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3717,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3720,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:469: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[899];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in ... */
static void C_ccall f_3720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3720,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3723,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:471: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[906];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[907];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in ... */
static void C_ccall f_3723(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3723,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3726,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:472: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[42];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[905];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in ... */
static void C_ccall f_3726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3726,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3729,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:473: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[902];
av2[3]=C_fix(13);
av2[4]=C_fix(2);
av2[5]=lf[904];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in ... */
static void C_ccall f_3729(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3729,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3732,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:474: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[902];
av2[3]=C_fix(13);
av2[4]=C_fix(2);
av2[5]=lf[903];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in k3018 in ... */
static void C_ccall f_3732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3732,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3735,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:475: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[899];
av2[3]=C_fix(13);
av2[4]=C_fix(2);
av2[5]=lf[901];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in k3085 in ... */
static void C_ccall f_3735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3735,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3738,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:476: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[899];
av2[3]=C_fix(13);
av2[4]=C_fix(2);
av2[5]=lf[900];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in k3088 in ... */
static void C_ccall f_3738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3738,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3741,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:477: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[897];
av2[3]=C_fix(13);
av2[4]=C_fix(2);
av2[5]=lf[898];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in k3244 in ... */
static void C_ccall f_3741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3741,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3744,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:479: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[850];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[896];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in k3247 in ... */
static void C_ccall f_3744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3744,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3747,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:480: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[848];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[895];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in k3250 in ... */
static void C_ccall f_3747(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3747,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3750,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:481: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[846];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[894];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in k3430 in ... */
static void C_ccall f_3750(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3750,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3753,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:482: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[892];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[893];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in k3433 in ... */
static void C_ccall f_3753(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3753,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3756,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:483: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[890];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[891];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in k3503 in ... */
static void C_ccall f_3756(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3756,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3759,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:484: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[888];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[889];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in k3506 in ... */
static void C_ccall f_3759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3759,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3762,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:485: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[886];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[887];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in k3509 in ... */
static void C_ccall f_3762(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3762,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3765,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:486: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[884];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[885];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in k3512 in ... */
static void C_ccall f_3765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3765,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3768,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:487: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[882];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[883];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in k3515 in ... */
static void C_ccall f_3768(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3768,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3771,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:488: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[844];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[881];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in k3518 in ... */
static void C_ccall f_3771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3771,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3774,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:489: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[879];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[880];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in k3545 in ... */
static void C_ccall f_3774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3774,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3777,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:490: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[877];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[878];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in k3548 in ... */
static void C_ccall f_3777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3777,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3780,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:491: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[875];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[876];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in k3715 in ... */
static void C_ccall f_3780(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3780,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3783,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:492: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[873];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[874];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in k3718 in ... */
static void C_ccall f_3783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3783,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3786,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:493: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[871];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[872];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in k3721 in ... */
static void C_ccall f_3786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3786,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3789,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:494: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[869];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[870];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in k3724 in ... */
static void C_ccall f_3789(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3789,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3792,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:495: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[867];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[868];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in k3727 in ... */
static void C_ccall f_3792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3792,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3795,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:496: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[865];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[866];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in k3730 in ... */
static void C_ccall f_3795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3795,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3798,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:497: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[863];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[864];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in k3733 in ... */
static void C_ccall f_3798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3798,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3801,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:498: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[861];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[862];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in k3736 in ... */
static void C_ccall f_3801(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3801,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3804,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:499: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[859];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[860];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in k3739 in ... */
static void C_ccall f_3804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3804,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3807,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:500: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[857];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[858];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in k3742 in ... */
static void C_ccall f_3807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3807,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3810,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:501: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[855];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[856];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in k3745 in ... */
static void C_ccall f_3810(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3810,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3813,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:502: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[853];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[854];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in k3748 in ... */
static void C_ccall f_3813(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3813,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3816,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:503: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[842];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[852];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in k3751 in ... */
static void C_ccall f_3816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3816,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3819,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:505: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[850];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[851];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in k3754 in ... */
static void C_ccall f_3819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3819,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3822,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:506: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[848];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[849];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in k3757 in ... */
static void C_ccall f_3822(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3822,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3825,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:507: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[846];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[847];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in k3760 in ... */
static void C_ccall f_3825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3825,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3828,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:508: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[844];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[845];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in k3763 in ... */
static void C_ccall f_3828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3828,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3831,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:509: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[842];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[843];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in k3766 in ... */
static void C_ccall f_3831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3831,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3834,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:511: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[839];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[841];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in k3769 in ... */
static void C_ccall f_3834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3834,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3837,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:512: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[839];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[840];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in k3772 in ... */
static void C_ccall f_3837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3837,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3840,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:514: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[837];
av2[3]=C_fix(1);
av2[4]=C_fix(2);
av2[5]=lf[838];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in k3775 in ... */
static void C_ccall f_3840(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3840,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3843,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:515: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[835];
av2[3]=C_fix(1);
av2[4]=C_fix(2);
av2[5]=lf[836];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in k3778 in ... */
static void C_ccall f_3843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3843,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3846,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:516: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[833];
av2[3]=C_fix(1);
av2[4]=C_fix(2);
av2[5]=lf[834];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in k3781 in ... */
static void C_ccall f_3846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3846,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3849,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:517: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[831];
av2[3]=C_fix(1);
av2[4]=C_fix(2);
av2[5]=lf[832];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in k3784 in ... */
static void C_ccall f_3849(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3849,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3852,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:519: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[828];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[830];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in k3787 in ... */
static void C_ccall f_3852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3852,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3855,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:520: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[828];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[829];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in k3790 in ... */
static void C_ccall f_3855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3855,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3858,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:521: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[826];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[827];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in k3793 in ... */
static void C_ccall f_3858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3858,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3861,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:522: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[824];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[825];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in k3796 in ... */
static void C_ccall f_3861(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3861,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3864,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:523: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[822];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[823];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in k3799 in ... */
static void C_ccall f_3864(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3864,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3867,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:524: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[820];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[821];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in k3802 in ... */
static void C_ccall f_3867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3867,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3870,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:525: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[818];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[819];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in k3805 in ... */
static void C_ccall f_3870(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3870,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3873,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:526: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[816];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[817];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in k3808 in ... */
static void C_ccall f_3873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3873,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3876,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:527: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[814];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[815];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in k3811 in ... */
static void C_ccall f_3876(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3876,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3879,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:528: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[812];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[813];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in k3814 in ... */
static void C_ccall f_3879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3879,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3882,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:529: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[810];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[811];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in k3817 in ... */
static void C_ccall f_3882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3882,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3885,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:530: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[808];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[809];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in k3820 in ... */
static void C_ccall f_3885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3885,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3888,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:531: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[806];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[807];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in k3823 in ... */
static void C_ccall f_3888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3888,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3891,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:532: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[804];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[805];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in k3826 in ... */
static void C_ccall f_3891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3891,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3894,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:533: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[802];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[803];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in k3829 in ... */
static void C_ccall f_3894(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3894,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3897,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:534: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[800];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[801];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in k3832 in ... */
static void C_ccall f_3897(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3897,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3900,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:535: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[798];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[799];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in k3835 in ... */
static void C_ccall f_3900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3900,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3903,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:536: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[796];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[797];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in k3838 in ... */
static void C_ccall f_3903(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3903,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3906,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:537: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[794];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[795];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in k3841 in ... */
static void C_ccall f_3906(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3906,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3909,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:538: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[792];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[793];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in k3844 in ... */
static void C_ccall f_3909(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3909,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3912,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:539: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[790];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[791];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in k3847 in ... */
static void C_ccall f_3912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3912,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3915,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:540: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[788];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[789];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in k3850 in ... */
static void C_ccall f_3915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3915,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3918,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:541: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[786];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[787];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in k3853 in ... */
static void C_ccall f_3918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3918,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3921,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:542: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[784];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[785];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in k3856 in ... */
static void C_ccall f_3921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3921,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3924,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:543: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[782];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[783];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in k3859 in ... */
static void C_ccall f_3924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3924,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3927,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:544: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[780];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[781];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in k3862 in ... */
static void C_ccall f_3927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3927,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3930,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:545: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[778];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[779];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in k3865 in ... */
static void C_ccall f_3930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3930,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3933,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:546: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[776];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[777];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in k3868 in ... */
static void C_ccall f_3933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3933,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3936,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:547: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[774];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[775];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in k3871 in ... */
static void C_ccall f_3936(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3936,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3939,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:548: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[772];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[773];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in k3874 in ... */
static void C_ccall f_3939(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3939,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3942,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:549: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[770];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[771];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in k3877 in ... */
static void C_ccall f_3942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3942,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3945,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:550: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[768];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[769];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in k3880 in ... */
static void C_ccall f_3945(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3945,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3948,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:551: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[766];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[767];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in k3883 in ... */
static void C_ccall f_3948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3948,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3951,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:552: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[764];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[765];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in k3886 in ... */
static void C_ccall f_3951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3951,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3954,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:553: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[762];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[763];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in k3889 in ... */
static void C_ccall f_3954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3954,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3957,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:554: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[760];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[761];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in k3892 in ... */
static void C_ccall f_3957(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3957,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3960,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:555: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[758];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[759];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in k3895 in ... */
static void C_ccall f_3960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3960,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3963,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:556: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[756];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[757];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in k3898 in ... */
static void C_ccall f_3963(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3963,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3966,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:557: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[754];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[755];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in k3901 in ... */
static void C_ccall f_3966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3966,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3969,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:558: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[752];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[753];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in k3904 in ... */
static void C_ccall f_3969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3969,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3972,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:559: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[750];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[751];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in k3907 in ... */
static void C_ccall f_3972(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3972,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3975,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:560: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[748];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[749];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in k3910 in ... */
static void C_ccall f_3975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3975,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3978,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:561: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[746];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[747];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in k3913 in ... */
static void C_ccall f_3978(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3978,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3981,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:562: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[744];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[745];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in k3916 in ... */
static void C_ccall f_3981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3981,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3984,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:563: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[742];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[743];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in k3919 in ... */
static void C_ccall f_3984(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3984,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3987,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:564: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[740];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[741];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in k3922 in ... */
static void C_ccall f_3987(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3987,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3990,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:565: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[738];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[739];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in k3925 in ... */
static void C_ccall f_3990(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3990,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3993,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:566: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[735];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[737];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in k3928 in ... */
static void C_ccall f_3993(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3993,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3996,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:567: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[735];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[736];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in k3931 in ... */
static void C_ccall f_3996(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3996,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3999,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:568: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[732];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[734];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in k3934 in ... */
static void C_ccall f_3999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_3999,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4002,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:569: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[732];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[733];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in k3937 in ... */
static void C_ccall f_4002(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4002,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4005,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:570: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[730];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[731];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in k3940 in ... */
static void C_ccall f_4005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4005,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4008,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:571: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[728];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[729];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in k3943 in ... */
static void C_ccall f_4008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4008,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4011,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:572: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[726];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[727];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in k3946 in ... */
static void C_ccall f_4011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4011,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4014,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:573: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[723];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[725];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in k3949 in ... */
static void C_ccall f_4014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4014,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4017,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:574: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[723];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[724];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in k3952 in ... */
static void C_ccall f_4017(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4017,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4020,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:575: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[720];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[722];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in k3955 in ... */
static void C_ccall f_4020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4020,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4023,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:576: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[720];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[721];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in k3958 in ... */
static void C_ccall f_4023(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4023,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4026,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:577: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[717];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[719];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in k3961 in ... */
static void C_ccall f_4026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4026,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4029,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:578: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[717];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[718];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in k3964 in ... */
static void C_ccall f_4029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4029,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4032,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:579: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[714];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[716];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in k3967 in ... */
static void C_ccall f_4032(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4032,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4035,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:580: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[714];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[715];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in k3970 in ... */
static void C_ccall f_4035(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4035,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4038,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:581: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[711];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[713];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in k3973 in ... */
static void C_ccall f_4038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4038,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4041,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:582: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[711];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[712];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in k3976 in ... */
static void C_ccall f_4041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4041,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4044,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:583: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[708];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[710];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in k3979 in ... */
static void C_ccall f_4044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4044,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4047,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:584: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[708];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[709];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in k3982 in ... */
static void C_ccall f_4047(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4047,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4050,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:585: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[705];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[707];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in k3985 in ... */
static void C_ccall f_4050(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4050,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4053,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:586: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[705];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[706];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in k3988 in ... */
static void C_ccall f_4053(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4053,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4056,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:587: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[702];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[704];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in k3991 in ... */
static void C_ccall f_4056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4056,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4059,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:588: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[702];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[703];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in k3994 in ... */
static void C_ccall f_4059(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4059,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4062,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:589: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[700];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[701];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in k3997 in ... */
static void C_ccall f_4062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4062,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4065,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:590: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[698];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[699];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in k4000 in ... */
static void C_ccall f_4065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4065,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4068,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:591: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[696];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[697];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in k4003 in ... */
static void C_ccall f_4068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4068,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4071,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:592: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[694];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[695];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in k4006 in ... */
static void C_ccall f_4071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4071,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4074,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:593: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[692];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[693];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in k4009 in ... */
static void C_ccall f_4074(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4074,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4077,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:594: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[690];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[691];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in k4012 in ... */
static void C_ccall f_4077(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4077,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4080,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:595: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[688];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[689];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in k4015 in ... */
static void C_ccall f_4080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4080,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4083,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:596: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[686];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[687];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in k4018 in ... */
static void C_ccall f_4083(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4083,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4086,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:597: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[684];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[685];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in k4021 in ... */
static void C_ccall f_4086(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4086,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4089,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:598: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[682];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[683];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in k4024 in ... */
static void C_ccall f_4089(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4089,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4092,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:599: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[680];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[681];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in k4027 in ... */
static void C_ccall f_4092(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4092,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4095,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:600: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[678];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[679];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in k4030 in ... */
static void C_ccall f_4095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4095,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4098,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:601: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[676];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[677];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in k4033 in ... */
static void C_ccall f_4098(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4098,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4101,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:602: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[674];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[675];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in k4036 in ... */
static void C_ccall f_4101(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4101,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4104,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:603: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[672];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[673];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in k4039 in ... */
static void C_ccall f_4104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4104,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4107,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:604: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[670];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[671];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in k4042 in ... */
static void C_ccall f_4107(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4107,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4110,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:605: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[668];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[669];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in k4045 in ... */
static void C_ccall f_4110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4110,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4113,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:606: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[666];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[667];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in k4048 in ... */
static void C_ccall f_4113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4113,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4116,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:607: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[664];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[665];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in k4051 in ... */
static void C_ccall f_4116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4116,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4119,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:608: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[662];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[663];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in k4054 in ... */
static void C_ccall f_4119(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4119,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4122,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:609: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[660];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[661];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in k4057 in ... */
static void C_ccall f_4122(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4122,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4125,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:610: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[658];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[659];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in k4060 in ... */
static void C_ccall f_4125(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4125,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4128,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:611: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[656];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[657];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in k4063 in ... */
static void C_ccall f_4128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4128,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4131,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:612: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[654];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[655];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in k4066 in ... */
static void C_ccall f_4131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4131,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4134,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:613: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[652];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[653];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in k4069 in ... */
static void C_ccall f_4134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4134,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4137,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:614: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[650];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[651];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in k4072 in ... */
static void C_ccall f_4137(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4137,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4140,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:615: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[648];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[649];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in k4075 in ... */
static void C_ccall f_4140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4140,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4143,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:616: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[646];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[647];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in k4078 in ... */
static void C_ccall f_4143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4143,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4146,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:617: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[644];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[645];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in k4081 in ... */
static void C_ccall f_4146(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4146,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4149,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:618: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[642];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[643];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in k4084 in ... */
static void C_ccall f_4149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4149,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4152,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:619: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[640];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[641];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in k4087 in ... */
static void C_ccall f_4152(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4152,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4155,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:620: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[638];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[639];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in k4090 in ... */
static void C_ccall f_4155(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4155,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4158,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:621: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[636];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[637];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in k4093 in ... */
static void C_ccall f_4158(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4158,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4161,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:622: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[634];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[635];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in k4096 in ... */
static void C_ccall f_4161(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4161,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4164,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:623: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[632];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[633];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in k4099 in ... */
static void C_ccall f_4164(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4164,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4167,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:624: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[630];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[631];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in k4102 in ... */
static void C_ccall f_4167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4167,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4170,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:625: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[628];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[629];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in k4105 in ... */
static void C_ccall f_4170(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4170,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4173,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:627: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[624];
av2[3]=C_fix(14);
av2[4]=lf[24];
av2[5]=C_fix(2);
av2[6]=lf[626];
av2[7]=lf[627];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in k4108 in ... */
static void C_ccall f_4173(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4173,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4176,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:628: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[624];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[625];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in k4111 in ... */
static void C_ccall f_4176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4176,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4179,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:629: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[620];
av2[3]=C_fix(14);
av2[4]=lf[24];
av2[5]=C_fix(2);
av2[6]=lf[622];
av2[7]=lf[623];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in k4114 in ... */
static void C_ccall f_4179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4179,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4182,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:630: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[620];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[621];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in k4117 in ... */
static void C_ccall f_4182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4182,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4185,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:631: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[617];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[618];
av2[6]=lf[619];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in k4120 in ... */
static void C_ccall f_4185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4185,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4188,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:632: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[614];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[615];
av2[6]=lf[616];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in k4123 in ... */
static void C_ccall f_4188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4188,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4191,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:633: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[612];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[613];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in k4126 in ... */
static void C_ccall f_4191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4191,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4194,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:634: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[610];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[611];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in k4129 in ... */
static void C_ccall f_4194(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4194,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4197,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:636: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[607];
av2[3]=C_fix(4);
av2[4]=lf[300];
av2[5]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in k4132 in ... */
static void C_ccall f_4197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4197,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4200,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:637: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[604];
av2[3]=C_fix(4);
av2[4]=lf[300];
av2[5]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in k4135 in ... */
static void C_ccall f_4200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4200,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4203,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:638: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[607];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[608];
av2[6]=lf[609];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in k4138 in ... */
static void C_ccall f_4203(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4203,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4206,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:639: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[604];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[605];
av2[6]=lf[606];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in k4141 in ... */
static void C_ccall f_4206(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4206,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4209,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:641: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[601];
av2[3]=C_fix(14);
av2[4]=lf[24];
av2[5]=C_fix(1);
av2[6]=lf[602];
av2[7]=lf[603];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in k4144 in ... */
static void C_ccall f_4209(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4209,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4212,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:643: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[597];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in k4147 in ... */
static void C_ccall f_4212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4212,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4215,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:644: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[593];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in k4150 in ... */
static void C_ccall f_4215(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4215,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4218,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:645: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[589];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in k4153 in ... */
static void C_ccall f_4218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4218,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4221,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:647: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[597];
av2[3]=C_fix(21);
av2[4]=C_fix(-1);
av2[5]=lf[598];
av2[6]=lf[599];
av2[7]=lf[600];
av2[8]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in k4156 in ... */
static void C_ccall f_4221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4221,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4224,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:648: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[593];
av2[3]=C_fix(21);
av2[4]=C_fix(0);
av2[5]=lf[594];
av2[6]=lf[595];
av2[7]=lf[596];
av2[8]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in k4159 in ... */
static void C_ccall f_4224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4224,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4227,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:649: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[589];
av2[3]=C_fix(21);
av2[4]=C_fix(0);
av2[5]=lf[590];
av2[6]=lf[591];
av2[7]=lf[592];
av2[8]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in k4162 in ... */
static void C_ccall f_4227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4227,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4230,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:651: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[586];
av2[3]=C_fix(22);
av2[4]=C_fix(1);
av2[5]=lf[587];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(5);
av2[8]=lf[588];
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in k4165 in ... */
static void C_ccall f_4230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4230,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4233,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:653: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[584];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[585];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in k4168 in ... */
static void C_ccall f_4233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4233,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4236,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:654: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[582];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[583];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in k4171 in ... */
static void C_ccall f_4236(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4236,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4239,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:655: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[580];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[581];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in k4174 in ... */
static void C_ccall f_4239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4239,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4242,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:656: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[578];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[579];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in k4177 in ... */
static void C_ccall f_4242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4242,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4245,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:657: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[576];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[577];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in k4180 in ... */
static void C_ccall f_4245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4245,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4248,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:658: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[574];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[575];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in k4183 in ... */
static void C_ccall f_4248(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4248,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4251,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:659: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[572];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[573];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in k4186 in ... */
static void C_ccall f_4251(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4251,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4254,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:660: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[570];
av2[3]=C_fix(16);
av2[4]=C_fix(3);
av2[5]=lf[571];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in k4189 in ... */
static void C_ccall f_4254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4254,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4257,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:662: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[566];
av2[3]=C_fix(5);
av2[4]=lf[569];
av2[5]=C_fix(0);
av2[6]=lf[24];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in k4192 in ... */
static void C_ccall f_4257(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4257,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4260,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:663: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[566];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[568];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in k4195 in ... */
static void C_ccall f_4260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4260,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4263,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:664: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[566];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[567];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in k4198 in ... */
static void C_ccall f_4263(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4263,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4266,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:665: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[562];
av2[3]=C_fix(5);
av2[4]=lf[565];
av2[5]=C_fix(0);
av2[6]=lf[24];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in k4201 in ... */
static void C_ccall f_4266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4266,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4269,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:666: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[562];
av2[3]=C_fix(5);
av2[4]=lf[564];
av2[5]=C_fix(0);
av2[6]=lf[393];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in k4204 in ... */
static void C_ccall f_4269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4269,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4272,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:667: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[562];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[563];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in k4207 in ... */
static void C_ccall f_4272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4272,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4275,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:668: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[558];
av2[3]=C_fix(5);
av2[4]=lf[561];
av2[5]=C_fix(0);
av2[6]=lf[24];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in k4210 in ... */
static void C_ccall f_4275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4275,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4278,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:669: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[558];
av2[3]=C_fix(5);
av2[4]=lf[560];
av2[5]=C_fix(0);
av2[6]=lf[393];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in k4213 in ... */
static void C_ccall f_4278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4278,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4281,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:670: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[558];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[559];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in k4216 in ... */
static void C_ccall f_4281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4281,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4284,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:672: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[546];
av2[3]=C_fix(6);
av2[4]=lf[556];
av2[5]=lf[557];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in k4219 in ... */
static void C_ccall f_4284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4284,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4287,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:673: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[542];
av2[3]=C_fix(6);
av2[4]=lf[554];
av2[5]=lf[555];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in k4222 in ... */
static void C_ccall f_4287(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4287,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4290,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:674: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[551];
av2[3]=C_fix(6);
av2[4]=lf[552];
av2[5]=lf[553];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in k4225 in ... */
static void C_ccall f_4290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4290,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4293,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:675: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[548];
av2[3]=C_fix(6);
av2[4]=lf[549];
av2[5]=lf[550];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in k4228 in ... */
static void C_ccall f_4293(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4293,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4296,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:677: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[546];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[547];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in k4231 in ... */
static void C_ccall f_4296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4296,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4299,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:678: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[544];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[545];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in k4234 in ... */
static void C_ccall f_4299(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4299,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4302,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:679: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[542];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[543];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in k4237 in ... */
static void C_ccall f_4302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4302,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4305,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:681: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[528];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[541];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in k4240 in ... */
static void C_ccall f_4305(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4305,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4308,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:682: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[526];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[540];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in k4243 in ... */
static void C_ccall f_4308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4308,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4311,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:683: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[524];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[539];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in k4246 in ... */
static void C_ccall f_4311(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4311,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4314,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:684: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[522];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[538];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in k4249 in ... */
static void C_ccall f_4314(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4314,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4317,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:685: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[520];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[537];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in k4252 in ... */
static void C_ccall f_4317(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4317,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4320,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:686: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[518];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[536];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in k4255 in ... */
static void C_ccall f_4320(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4320,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4323,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:687: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[516];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[535];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in k4258 in ... */
static void C_ccall f_4323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4323,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4326,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:688: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[514];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[534];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in k4261 in ... */
static void C_ccall f_4326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4326,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4329,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:689: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[512];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[533];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in k4264 in ... */
static void C_ccall f_4329(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4329,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4332,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:690: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[510];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[532];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in k4267 in ... */
static void C_ccall f_4332(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4332,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4335,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:691: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[508];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[531];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in k4270 in ... */
static void C_ccall f_4335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4335,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4338,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:692: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[506];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[530];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in k4273 in ... */
static void C_ccall f_4338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4338,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4341,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:693: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[528];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[529];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in k4276 in ... */
static void C_ccall f_4341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4341,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4344,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:694: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[526];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[527];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in k4279 in ... */
static void C_ccall f_4344(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4344,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4347,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:695: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[524];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[525];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in k4282 in ... */
static void C_ccall f_4347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4347,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4350,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:696: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[522];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[523];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in k4285 in ... */
static void C_ccall f_4350(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4350,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4353,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:697: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[520];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[521];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in k4288 in ... */
static void C_ccall f_4353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4353,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4356,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:698: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[518];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[519];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in k4291 in ... */
static void C_ccall f_4356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4356,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4359,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:699: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[516];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[517];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in k4294 in ... */
static void C_ccall f_4359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4359,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4362,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:700: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[514];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[515];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in k4297 in ... */
static void C_ccall f_4362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4362,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4365,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:701: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[512];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[513];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in k4300 in ... */
static void C_ccall f_4365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4365,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4368,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:702: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[510];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[511];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in k4303 in ... */
static void C_ccall f_4368(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4368,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4371,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:703: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[508];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[509];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in k4306 in ... */
static void C_ccall f_4371(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4371,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4374,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:704: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[506];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[507];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in k4309 in ... */
static void C_ccall f_4374(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4374,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4377,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:706: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[444];
av2[3]=C_fix(9);
av2[4]=lf[504];
av2[5]=lf[505];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in k4312 in ... */
static void C_ccall f_4377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4377,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4380,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:707: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[442];
av2[3]=C_fix(9);
av2[4]=lf[502];
av2[5]=lf[503];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in k4315 in ... */
static void C_ccall f_4380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4380,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4383,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:708: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[440];
av2[3]=C_fix(9);
av2[4]=lf[500];
av2[5]=lf[501];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in k4318 in ... */
static void C_ccall f_4383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4383,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4386,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:709: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[438];
av2[3]=C_fix(9);
av2[4]=lf[498];
av2[5]=lf[499];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in k4321 in ... */
static void C_ccall f_4386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4386,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4389,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:710: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[436];
av2[3]=C_fix(9);
av2[4]=lf[496];
av2[5]=lf[497];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in k4324 in ... */
static void C_ccall f_4389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4389,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4392,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:712: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[495];
av2[3]=C_fix(11);
av2[4]=C_fix(1);
av2[5]=lf[99];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in k4327 in ... */
static void C_ccall f_4392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4392,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4395,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:713: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[493];
av2[3]=C_fix(11);
av2[4]=C_fix(2);
av2[5]=lf[494];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in k4330 in ... */
static void C_ccall f_4395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4395,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4398,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:714: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[491];
av2[3]=C_fix(11);
av2[4]=C_fix(2);
av2[5]=lf[492];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in k4333 in ... */
static void C_ccall f_4398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4398,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4401,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:715: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[490];
av2[3]=C_fix(11);
av2[4]=C_fix(3);
av2[5]=lf[300];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in k4336 in ... */
static void C_ccall f_4401(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4401,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4404,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:716: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[489];
av2[3]=C_fix(11);
av2[4]=C_fix(3);
av2[5]=lf[300];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in k4339 in ... */
static void C_ccall f_4404(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4404,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4407,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:717: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[488];
av2[3]=C_fix(11);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[343];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in k4342 in ... */
static void C_ccall f_4407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4407,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4410,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:718: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[486];
av2[3]=C_fix(11);
av2[4]=C_fix(3);
av2[5]=lf[487];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in k4345 in ... */
static void C_ccall f_4410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4410,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4413,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:719: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[484];
av2[3]=C_fix(11);
av2[4]=C_fix(2);
av2[5]=lf[485];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in k4348 in ... */
static void C_ccall f_4413(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4413,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4416,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:720: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[482];
av2[3]=C_fix(11);
av2[4]=C_fix(1);
av2[5]=lf[483];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in k4351 in ... */
static void C_ccall f_4416(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4416,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4419,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:721: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[480];
av2[3]=C_fix(11);
av2[4]=C_fix(1);
av2[5]=lf[481];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in k4354 in ... */
static void C_ccall f_4419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4419,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4422,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:723: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[478];
av2[3]=C_fix(11);
av2[4]=C_fix(3);
av2[5]=lf[300];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in k4357 in ... */
static void C_ccall f_4422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4422,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4425,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:724: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[478];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[479];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in k4360 in ... */
static void C_ccall f_4425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4425,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4428,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:726: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[474];
av2[3]=C_fix(12);
av2[4]=lf[477];
av2[5]=C_SCHEME_TRUE;
av2[6]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in k4363 in ... */
static void C_ccall f_4428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4428,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4431,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:727: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[473];
av2[3]=C_fix(12);
av2[4]=lf[476];
av2[5]=C_SCHEME_TRUE;
av2[6]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in k4366 in ... */
static void C_ccall f_4431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4431,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4434,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:728: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[475];
av2[3]=C_fix(12);
av2[4]=C_SCHEME_FALSE;
av2[5]=C_SCHEME_TRUE;
av2[6]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in k4369 in ... */
static void C_ccall f_4434(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4434,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4437,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:730: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[474];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in k4372 in ... */
static void C_ccall f_4437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4437,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4440,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:731: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[473];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in k4375 in ... */
static void C_ccall f_4440(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4440,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4443,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:733: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[474];
av2[3]=C_fix(18);
av2[4]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in k4378 in ... */
static void C_ccall f_4443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4443,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4446,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:734: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[473];
av2[3]=C_fix(18);
av2[4]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in k4381 in ... */
static void C_ccall f_4446(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4446,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4449,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:735: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[352];
av2[3]=C_fix(18);
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in k4384 in ... */
static void C_ccall f_4449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_4449,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4452,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6109,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:737: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[434];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in ... */
static void C_ccall f_4452(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_4452,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4455,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5985,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:767: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[432];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in ... */
static void C_ccall f_4455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_4455,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4458,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5861,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:803: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[429];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_4458(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_4458,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4460,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4593,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:865: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[459];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_4460(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4460,c,av);}
a=C_alloc(7);
t6=C_eqp(*((C_word*)lf[25]+1),lf[24]);
if(C_truep(t6)){
t7=C_i_length(t5);
if(C_truep(C_fixnum_greater_or_equal_p(t7,C_fix(2)))){
t8=C_i_car(t5);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4555,a[2]=t8,a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4557,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:849: filter */
f_2305(t9,t10,C_u_i_cdr(t5));}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k4495 in k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in ... */
static void C_ccall f_4497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4497,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:855: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a4498 in k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in ... */
static void C_ccall f_4499(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4499,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4506,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4542,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:861: chicken.compiler.support#node-class */
t6=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k4504 in a4498 in k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_fcall f_4506(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_4506,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4517,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:862: chicken.compiler.support#qnode */
t3=*((C_word*)lf[29]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[4]);
/* c-platform.scm:863: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[59];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k4515 in k4504 in a4498 in k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in ... */
static void C_ccall f_4517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4517,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:862: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[58];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4536 in k4540 in a4498 in k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in ... */
static void C_ccall f_4538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4538,c,av);}
t2=((C_word*)t0)[2];
f_4506(t2,C_eqp(C_fix(2),C_i_car(t1)));}

/* k4540 in a4498 in k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_ccall f_4542(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4542,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4538,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:861: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_4506(t3,C_SCHEME_FALSE);}}

/* k4553 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_4555(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_4555,c,av);}
a=C_alloc(13);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_i_length(t2);
if(C_truep(C_fixnum_greater_or_equal_p(t3,C_fix(2)))){
t4=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4497,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4499,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:859: chicken.compiler.support#fold-inner */
t7=*((C_word*)lf[60]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* a4556 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_4557(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4557,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4583,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:851: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4577 in k4581 in a4556 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_ccall f_4579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4579,c,av);}
t2=C_i_car(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_not(C_eqp(C_fix(1),t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4581 in a4556 in rewrite-div in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in ... */
static void C_ccall f_4583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4583,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4579,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:852: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_4593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4593,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4596,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:866: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[462];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_4596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_4596,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4599,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5784,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:868: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[454];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in ... */
static void C_ccall f_4599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4599,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4602,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:886: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[432];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_ccall f_4602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4602,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4605,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:887: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[429];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in ... */
static void C_ccall f_4605(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4605,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4608,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:888: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[434];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in ... */
static void C_ccall f_4608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4608,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4611,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:889: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[459];
av2[3]=C_fix(19);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in ... */
static void C_ccall f_4611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4611,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4614,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:891: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[432];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[458];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(29);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in ... */
static void C_ccall f_4614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4614,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4617,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:892: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[429];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[457];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(29);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in ... */
static void C_ccall f_4617(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4617,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4620,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:893: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[434];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[456];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(33);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in ... */
static void C_ccall f_4620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4620,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4623,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:894: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[454];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[455];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in ... */
static void C_ccall f_4623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4623,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4626,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:895: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[405];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[453];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in ... */
static void C_ccall f_4626(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4626,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4629,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:896: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[451];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[452];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in ... */
static void C_ccall f_4629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4629,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4632,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:898: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[444];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[450];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in ... */
static void C_ccall f_4632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4632,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4635,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:899: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[442];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[449];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in ... */
static void C_ccall f_4635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4635,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4638,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:900: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[440];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[448];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in ... */
static void C_ccall f_4638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4638,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4641,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:901: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[438];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[447];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in ... */
static void C_ccall f_4641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4641,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4644,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:902: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[436];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[446];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in ... */
static void C_ccall f_4644(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4644,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4647,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:904: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[444];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[445];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in k4450 in ... */
static void C_ccall f_4647(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4647,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4650,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:905: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[442];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[443];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in k4453 in ... */
static void C_ccall f_4650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4650,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4653,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:906: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[440];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[441];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in k4456 in ... */
static void C_ccall f_4653(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4653,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4656,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:907: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[438];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[439];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in k4591 in ... */
static void C_ccall f_4656(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4656,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4659,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:908: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[436];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[437];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in k4594 in ... */
static void C_ccall f_4659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4659,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4662,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:910: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[434];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[435];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in k4597 in ... */
static void C_ccall f_4662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4662,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4665,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:911: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[432];
av2[3]=C_fix(13);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[433];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in k4600 in ... */
static void C_ccall f_4665(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4665,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4668,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:912: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[429];
av2[3]=C_fix(13);
av2[4]=lf[430];
av2[5]=lf[431];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in k4603 in ... */
static void C_ccall f_4668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4668,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4671,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:914: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[426];
av2[3]=C_fix(13);
av2[4]=lf[427];
av2[5]=lf[428];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in k4606 in ... */
static void C_ccall f_4671(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4671,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4674,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:915: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[424];
av2[3]=C_fix(13);
av2[4]=C_fix(1);
av2[5]=lf[425];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in k4609 in ... */
static void C_ccall f_4674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4674,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4677,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:916: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[422];
av2[3]=C_fix(13);
av2[4]=C_fix(4);
av2[5]=lf[423];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in k4612 in ... */
static void C_ccall f_4677(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4677,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4680,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:917: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[420];
av2[3]=C_fix(13);
av2[4]=C_fix(1);
av2[5]=lf[421];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in k4615 in ... */
static void C_ccall f_4680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4680,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4683,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:918: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[418];
av2[3]=C_fix(13);
av2[4]=C_fix(0);
av2[5]=lf[419];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in k4618 in ... */
static void C_ccall f_4683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4683,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4686,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:919: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[416];
av2[3]=C_fix(13);
av2[4]=C_fix(1);
av2[5]=lf[417];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in k4621 in ... */
static void C_ccall f_4686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4686,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4689,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:920: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[414];
av2[3]=C_fix(13);
av2[4]=C_fix(1);
av2[5]=lf[415];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in k4624 in ... */
static void C_ccall f_4689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4689,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4692,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:921: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[412];
av2[3]=C_fix(13);
av2[4]=C_fix(1);
av2[5]=lf[413];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in k4627 in ... */
static void C_ccall f_4692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4692,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4695,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:923: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[403];
av2[3]=C_fix(14);
av2[4]=lf[24];
av2[5]=C_fix(1);
av2[6]=lf[410];
av2[7]=lf[411];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in k4630 in ... */
static void C_ccall f_4695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4695,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4698,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:924: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[401];
av2[3]=C_fix(14);
av2[4]=lf[24];
av2[5]=C_fix(1);
av2[6]=lf[408];
av2[7]=lf[409];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in k4633 in ... */
static void C_ccall f_4698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4698,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4701,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:925: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[405];
av2[3]=C_fix(14);
av2[4]=lf[24];
av2[5]=C_fix(2);
av2[6]=lf[406];
av2[7]=lf[407];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in k4636 in ... */
static void C_ccall f_4701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4701,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4704,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:927: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[403];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[404];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in k4639 in ... */
static void C_ccall f_4704(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4704,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4707,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:928: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[401];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[402];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in k4642 in ... */
static void C_ccall f_4707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4707,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4710,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:930: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[399];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[400];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in k4645 in ... */
static void C_ccall f_4710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4710,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4713,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:931: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[397];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[398];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in k4648 in ... */
static void C_ccall f_4713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4713,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4716,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:933: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[395];
av2[3]=C_fix(15);
av2[4]=lf[393];
av2[5]=lf[24];
av2[6]=lf[396];
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in k4651 in ... */
static void C_ccall f_4716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4716,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4719,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:934: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[394];
av2[3]=C_fix(15);
av2[4]=lf[393];
av2[5]=lf[24];
av2[6]=lf[363];
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in k4654 in ... */
static void C_ccall f_4719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4719,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4722,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:935: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[392];
av2[3]=C_fix(15);
av2[4]=lf[393];
av2[5]=lf[24];
av2[6]=lf[366];
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in k4657 in ... */
static void C_ccall f_4722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4722,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4725,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:937: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[390];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[391];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in k4660 in ... */
static void C_ccall f_4725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4725,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4728,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:938: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[388];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[389];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in k4663 in ... */
static void C_ccall f_4728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4728,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4731,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:939: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[386];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[387];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in k4666 in ... */
static void C_ccall f_4731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4731,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4734,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:940: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[384];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[385];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in k4669 in ... */
static void C_ccall f_4734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4734,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4737,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:941: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[382];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[383];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in k4672 in ... */
static void C_ccall f_4737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4737,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4740,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:942: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[380];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[381];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in k4675 in ... */
static void C_ccall f_4740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4740,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4743,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:943: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[378];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[379];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in k4678 in ... */
static void C_ccall f_4743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4743,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4746,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:944: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[376];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[377];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in k4681 in ... */
static void C_ccall f_4746(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4746,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4749,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:945: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[374];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[375];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in k4684 in ... */
static void C_ccall f_4749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4749,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4752,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:946: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[372];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[373];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in k4687 in ... */
static void C_ccall f_4752(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4752,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4755,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:947: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[370];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[371];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in k4690 in ... */
static void C_ccall f_4755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4755,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4758,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:948: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[368];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[369];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in k4693 in ... */
static void C_ccall f_4758(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4758,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4761,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:949: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[366];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[367];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in k4696 in ... */
static void C_ccall f_4761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4761,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4764,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:950: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[361];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[365];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in k4699 in ... */
static void C_ccall f_4764(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4764,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4767,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:951: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[363];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[364];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in k4702 in ... */
static void C_ccall f_4767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4767,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4770,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:952: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[361];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[362];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in k4705 in ... */
static void C_ccall f_4770(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4770,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4773,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:954: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[359];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[360];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(3);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in k4708 in ... */
static void C_ccall f_4773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4773,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4776,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:955: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[357];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[358];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(3);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in k4711 in ... */
static void C_ccall f_4776(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4776,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4779,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:956: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[355];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[356];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(3);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in k4714 in ... */
static void C_ccall f_4779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4779,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4782,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:957: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[352];
av2[3]=C_fix(16);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[353];
av2[6]=C_SCHEME_TRUE;
av2[7]=lf[354];
av2[8]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in k4717 in ... */
static void C_ccall f_4782(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4782,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4785,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:958: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[349];
av2[3]=C_fix(16);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[350];
av2[6]=C_SCHEME_TRUE;
av2[7]=lf[351];
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in k4720 in ... */
static void C_ccall f_4785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4785,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4788,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:959: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[347];
av2[3]=C_fix(16);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[348];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_TRUE;
av2[8]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in k4723 in ... */
static void C_ccall f_4788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4788,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4791,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:960: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[345];
av2[3]=C_fix(16);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[346];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in k4726 in ... */
static void C_ccall f_4791(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_4791,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4794,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:961: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[343];
av2[3]=C_fix(16);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[344];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_TRUE;
av2[8]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in k4729 in ... */
static void C_ccall f_4794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4794,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4797,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:962: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[341];
av2[3]=C_fix(16);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[342];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in k4732 in ... */
static void C_ccall f_4797(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4797,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4800,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:963: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[339];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[340];
av2[6]=C_SCHEME_FALSE;
av2[7]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in k4735 in ... */
static void C_ccall f_4800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4800,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4803,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:964: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[337];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[338];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in k4738 in ... */
static void C_ccall f_4803(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4803,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4806,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:965: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[335];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[336];
av2[6]=C_SCHEME_FALSE;
av2[7]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in k4741 in ... */
static void C_ccall f_4806(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4806,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4809,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:966: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[333];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[334];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(6);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in k4744 in ... */
static void C_ccall f_4809(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4809,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4812,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:968: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[331];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[332];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in k4747 in ... */
static void C_ccall f_4812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4812,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4815,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:969: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[329];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[330];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in k4750 in ... */
static void C_ccall f_4815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4815,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4818,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:970: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[327];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[328];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in k4753 in ... */
static void C_ccall f_4818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4818,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4821,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:971: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[325];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[326];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in k4756 in ... */
static void C_ccall f_4821(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4821,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4824,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:972: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[323];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[324];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in k4759 in ... */
static void C_ccall f_4824(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4824,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4827,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:973: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[321];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[322];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in k4762 in ... */
static void C_ccall f_4827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4827,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4830,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:974: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[319];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[320];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in k4765 in ... */
static void C_ccall f_4830(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4830,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4833,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:975: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[317];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[318];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in k4768 in ... */
static void C_ccall f_4833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4833,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4836,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:976: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[315];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[316];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in k4771 in ... */
static void C_ccall f_4836(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4836,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4839,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:977: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[313];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[314];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in k4774 in ... */
static void C_ccall f_4839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4839,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4842,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:978: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[311];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[312];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in k4777 in ... */
static void C_ccall f_4842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4842,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4845,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:979: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[309];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[310];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in k4780 in ... */
static void C_ccall f_4845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4845,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4848,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:983: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[307];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[308];
av2[6]=C_SCHEME_FALSE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in k4783 in ... */
static void C_ccall f_4848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4848,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4851,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:984: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[305];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[306];
av2[6]=C_SCHEME_FALSE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in k4786 in ... */
static void C_ccall f_4851(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4851,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4854,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:986: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[303];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[304];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in k4789 in ... */
static void C_ccall f_4854(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_4854,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4857,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:987: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[301];
av2[3]=C_fix(16);
av2[4]=C_fix(1);
av2[5]=lf[302];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in k4792 in ... */
static void C_ccall f_4857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_4857,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4860,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5727,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:989: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[300];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in ... */
static void C_ccall f_4860(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4860,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4863,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1007: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[295];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[296];
av2[6]=lf[297];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in ... */
static void C_ccall f_4863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4863,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4866,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1008: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[292];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[293];
av2[6]=lf[294];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in ... */
static void C_ccall f_4866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4866,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4869,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1009: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[290];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[291];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in ... */
static void C_ccall f_4869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4869,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4872,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1010: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[288];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[289];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in ... */
static void C_ccall f_4872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4872,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4875,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1011: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[285];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[286];
av2[6]=lf[287];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in ... */
static void C_ccall f_4875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4875,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4878,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1012: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[282];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[283];
av2[6]=lf[284];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in ... */
static void C_ccall f_4878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4878,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4881,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1013: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[279];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[280];
av2[6]=lf[281];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in ... */
static void C_ccall f_4881(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4881,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4884,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1014: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[276];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[277];
av2[6]=lf[278];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in ... */
static void C_ccall f_4884(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4884,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4887,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1015: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[273];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[274];
av2[6]=lf[275];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in ... */
static void C_ccall f_4887(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4887,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4890,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1016: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[270];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[271];
av2[6]=lf[272];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in ... */
static void C_ccall f_4890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4890,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4893,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1017: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[268];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[269];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in ... */
static void C_ccall f_4893(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_4893,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4896,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5605,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:1019: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[267];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in ... */
static void C_ccall f_4896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4896,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4899,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1053: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[260];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[261];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in ... */
static void C_ccall f_4899(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4899,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4902,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1054: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[258];
av2[3]=C_fix(17);
av2[4]=C_fix(3);
av2[5]=lf[259];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in ... */
static void C_ccall f_4902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4902,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4905,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1055: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[256];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[257];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in ... */
static void C_ccall f_4905(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4905,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4908,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1056: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[254];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[255];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in ... */
static void C_ccall f_4908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4908,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4911,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1057: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[252];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[253];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in ... */
static void C_ccall f_4911(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4911,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4914,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1058: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[250];
av2[3]=C_fix(17);
av2[4]=C_fix(3);
av2[5]=lf[251];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in ... */
static void C_ccall f_4914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4914,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4917,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1059: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[248];
av2[3]=C_fix(17);
av2[4]=C_fix(3);
av2[5]=lf[249];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in ... */
static void C_ccall f_4917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4917,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4920,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1060: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[246];
av2[3]=C_fix(17);
av2[4]=C_fix(3);
av2[5]=lf[247];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in ... */
static void C_ccall f_4920(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4920,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4923,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1061: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[243];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[244];
av2[6]=lf[245];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in ... */
static void C_ccall f_4923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4923,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4926,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1062: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[241];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[242];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in ... */
static void C_ccall f_4926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4926,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4929,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1063: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[239];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[240];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in ... */
static void C_ccall f_4929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4929,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4932,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1064: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[236];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[237];
av2[6]=lf[238];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in ... */
static void C_ccall f_4932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4932,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4935,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1065: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[234];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[235];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in ... */
static void C_ccall f_4935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4935,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4938,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1066: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[231];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[233];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in ... */
static void C_ccall f_4938(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4938,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4941,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1067: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[231];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[232];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in ... */
static void C_ccall f_4941(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4941,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4944,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1068: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[229];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[230];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in k4879 in ... */
static void C_ccall f_4944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4944,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4947,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1069: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[227];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[228];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in k4882 in ... */
static void C_ccall f_4947(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4947,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4950,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1070: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[225];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[226];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in k4885 in ... */
static void C_ccall f_4950(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4950,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4953,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1071: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[223];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[224];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in k4888 in ... */
static void C_ccall f_4953(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4953,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4956,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1072: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[221];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[222];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in k4891 in ... */
static void C_ccall f_4956(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4956,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4959,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1073: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[219];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[220];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in k4894 in ... */
static void C_ccall f_4959(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4959,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4962,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1074: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[217];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[218];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in k4897 in ... */
static void C_ccall f_4962(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4962,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4965,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1075: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[215];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[216];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in k4900 in ... */
static void C_ccall f_4965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4965,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4968,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1076: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[213];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[214];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in k4903 in ... */
static void C_ccall f_4968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4968,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4971,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1077: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[211];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[212];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in k4906 in ... */
static void C_ccall f_4971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_4971,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4974,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1078: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[209];
av2[3]=C_fix(17);
av2[4]=C_fix(2);
av2[5]=lf[210];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in k4909 in ... */
static void C_ccall f_4974(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4974,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4977,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1080: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[207];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[208];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in k4912 in ... */
static void C_ccall f_4977(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4977,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4980,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1083: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[204];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[206];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in k4915 in ... */
static void C_ccall f_4980(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4980,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4983,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1084: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[204];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[205];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in k4918 in ... */
static void C_ccall f_4983(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4983,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4986,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1085: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[201];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[203];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in k4921 in ... */
static void C_ccall f_4986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4986,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4989,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1086: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[201];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[202];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in k4924 in ... */
static void C_ccall f_4989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4989,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4992,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1087: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[198];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[200];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in k4927 in ... */
static void C_ccall f_4992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4992,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4995,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1088: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[198];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[199];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in k4930 in ... */
static void C_ccall f_4995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4995,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4998,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1089: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[195];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[197];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in k4933 in ... */
static void C_ccall f_4998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_4998,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5001,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1090: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[195];
av2[3]=C_fix(2);
av2[4]=C_fix(2);
av2[5]=lf[196];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in k4936 in ... */
static void C_ccall f_5001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5001,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5004,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1092: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[193];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[194];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in k4939 in ... */
static void C_ccall f_5004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5004,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5007,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1093: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[191];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[192];
av2[6]=C_SCHEME_TRUE;
av2[7]=C_fix(5);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in k4942 in ... */
static void C_ccall f_5007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5007,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5010,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1095: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[188];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[190];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in k4945 in ... */
static void C_ccall f_5010(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5010,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5013,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1096: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[188];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[189];
av2[6]=C_SCHEME_TRUE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in k4948 in ... */
static void C_ccall f_5013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5013,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5016,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1097: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[185];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[187];
av2[6]=C_SCHEME_FALSE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in k4951 in ... */
static void C_ccall f_5016(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5016,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5019,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1098: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[185];
av2[3]=C_fix(16);
av2[4]=C_fix(2);
av2[5]=lf[186];
av2[6]=C_SCHEME_TRUE;
av2[7]=*((C_word*)lf[11]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in k4954 in ... */
static void C_ccall f_5019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5019,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5022,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1100: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[182];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[184];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in k4957 in ... */
static void C_ccall f_5022(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5022,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5025,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1101: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[182];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[183];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in k4960 in ... */
static void C_ccall f_5025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5025,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5028,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1102: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[179];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[181];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in k4963 in ... */
static void C_ccall f_5028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5028,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5031,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1103: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[179];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[180];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in k4966 in ... */
static void C_ccall f_5031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5031,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5034,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1104: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[176];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[178];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in k4969 in ... */
static void C_ccall f_5034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5034,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5037,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1105: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[176];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[177];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in k4972 in ... */
static void C_ccall f_5037(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5037,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5040,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1106: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[173];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[175];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in k4975 in ... */
static void C_ccall f_5040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5040,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5043,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1107: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[173];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[174];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in k4978 in ... */
static void C_ccall f_5043(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5043,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5046,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1108: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[170];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[172];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in k4981 in ... */
static void C_ccall f_5046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5046,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5049,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1109: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[170];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[171];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in k4984 in ... */
static void C_ccall f_5049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5049,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5052,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1110: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[167];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[169];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in k4987 in ... */
static void C_ccall f_5052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5052,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5055,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1111: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[167];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[168];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in k4990 in ... */
static void C_ccall f_5055(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5055,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5058,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1112: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[164];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[166];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in k4993 in ... */
static void C_ccall f_5058(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5058,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5061,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1113: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[164];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[165];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in k4996 in ... */
static void C_ccall f_5061(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5061,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5064,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1114: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[161];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[163];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in k4999 in ... */
static void C_ccall f_5064(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5064,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5067,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1115: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[161];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[162];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in k5002 in ... */
static void C_ccall f_5067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5067,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5070,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1116: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[158];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[160];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in k5005 in ... */
static void C_ccall f_5070(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5070,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5073,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1117: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[158];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[159];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in k5008 in ... */
static void C_ccall f_5073(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5073,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5076,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1118: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[155];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[157];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in k5011 in ... */
static void C_ccall f_5076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5076,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5079,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1119: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[155];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=lf[156];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in k5014 in ... */
static void C_ccall f_5079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5079,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5082,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1121: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[152];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[154];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in k5017 in ... */
static void C_ccall f_5082(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5082,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5085,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1122: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[152];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[153];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in k5020 in ... */
static void C_ccall f_5085(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5085,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5088,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1123: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[149];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[151];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in k5023 in ... */
static void C_ccall f_5088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5088,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5091,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1124: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[149];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[150];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in k5026 in ... */
static void C_ccall f_5091(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5091,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5094,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1125: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[146];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[148];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in k5029 in ... */
static void C_ccall f_5094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5094,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5097,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1126: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[146];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[147];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in k5032 in ... */
static void C_ccall f_5097(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5097,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5100,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1127: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[143];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[145];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in k5035 in ... */
static void C_ccall f_5100(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5100,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5103,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1128: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[143];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[144];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in k5038 in ... */
static void C_ccall f_5103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5103,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5106,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1129: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[140];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[142];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in k5041 in ... */
static void C_ccall f_5106(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5106,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5109,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1130: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[140];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[141];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in k5044 in ... */
static void C_ccall f_5109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5109,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5112,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1131: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[137];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[139];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in k5047 in ... */
static void C_ccall f_5112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5112,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5115,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1132: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[137];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[138];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in k5050 in ... */
static void C_ccall f_5115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5115,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5118,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1133: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[134];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[136];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in k5053 in ... */
static void C_ccall f_5118(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5118,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5121,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1134: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[134];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[135];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in k5056 in ... */
static void C_ccall f_5121(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5121,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5124,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1135: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[131];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[133];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in k5059 in ... */
static void C_ccall f_5124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5124,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5127,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1136: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[131];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[132];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in k5062 in ... */
static void C_ccall f_5127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5127,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5130,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1137: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[128];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[130];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in k5065 in ... */
static void C_ccall f_5130(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5130,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5133,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1138: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[128];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[129];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in k5068 in ... */
static void C_ccall f_5133(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5133,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5136,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1139: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[125];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[127];
av2[6]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in k5071 in ... */
static void C_ccall f_5136(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5136,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5139,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1140: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[125];
av2[3]=C_fix(2);
av2[4]=C_fix(1);
av2[5]=lf[126];
av2[6]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in k5074 in ... */
static void C_ccall f_5139(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5139,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5142,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1142: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[123];
av2[3]=C_fix(17);
av2[4]=C_fix(1);
av2[5]=lf[124];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in k5077 in ... */
static void C_ccall f_5142(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5142,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5145,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1144: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[121];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[122];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in k5080 in ... */
static void C_ccall f_5145(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5145,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5148,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1145: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[119];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[120];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in k5083 in ... */
static void C_ccall f_5148(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5148,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5151,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1146: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[117];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[118];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in k5086 in ... */
static void C_ccall f_5151(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5151,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5154,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1147: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[115];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[116];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in k5089 in ... */
static void C_ccall f_5154(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5154,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5157,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1148: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[113];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[114];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in k5092 in ... */
static void C_ccall f_5157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5157,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5160,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1149: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[111];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[112];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in k5095 in ... */
static void C_ccall f_5160(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5160,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5163,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1150: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[109];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[110];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in k5098 in ... */
static void C_ccall f_5163(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5163,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5166,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1151: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[107];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[108];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in k5101 in ... */
static void C_ccall f_5166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5166,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5169,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1152: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[105];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[106];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in k5104 in ... */
static void C_ccall f_5169(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5169,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5172,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1153: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[103];
av2[3]=C_fix(7);
av2[4]=C_fix(1);
av2[5]=lf[104];
av2[6]=C_fix(1);
av2[7]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in k5107 in ... */
static void C_ccall f_5172(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_5172,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5174,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5279,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:1181: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[102];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in ... */
static void C_ccall f_5174(C_word c,C_word *av){
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
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5174,c,av);}
a=C_alloc(6);
t6=C_i_length(t5);
if(C_truep(C_i_pairp(t5))){
t7=C_i_car(t5);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5276,a[2]=t1,a[3]=t4,a[4]=t5,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1162: chicken.compiler.support#node-class */
t9=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=t7;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in ... */
static void C_ccall f_5196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5196,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5272,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1164: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in ... */
static void C_ccall f_5211(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5211,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5214,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(C_u_i_cdr(((C_word*)t0)[6])))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_cadr(((C_word*)t0)[6]);
f_5214(2,av2);}}
else{
/* c-platform.scm:1169: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[62];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in ... */
static void C_ccall f_5214(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(41,c,3)))){
C_save_and_reclaim((void *)f_5214,c,av);}
a=C_alloc(41);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5229,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5241,a[2]=((C_word*)t0)[4],a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_a_i_fixnum_plus(&a,2,((C_word*)t0)[5],C_fix(1));
t7=C_a_i_list2(&a,2,lf[61],t6);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5249,a[2]=t5,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5251,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2713,a[2]=((C_word*)t0)[5],a[3]=t11,a[4]=t9,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_2713(t13,t8,C_fix(0));}

/* k5227 in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_ccall f_5229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5229,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1170: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[48];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5239 in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_ccall f_5241(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5241,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1174: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5247 in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_ccall f_5249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5249,c,av);}
/* c-platform.scm:1177: chicken.compiler.support#make-node */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[28];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a5250 in k5212 in k5209 in k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_fcall f_5251(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_5251,2,t0,t1);}
/* c-platform.scm:1180: chicken.compiler.support#varnode */
t2=*((C_word*)lf[49]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k5270 in k5194 in k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in ... */
static void C_ccall f_5272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_5272,c,av);}
a=C_alloc(7);
t2=C_i_car(t1);
if(C_truep(C_fixnump(t2))){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5211,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:1166: scheme#<= */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t3;
av2[2]=C_fix(0);
av2[3]=t2;
av2[4]=C_fix(32);
C_less_or_equal_p(5,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5274 in rewrite-make-vector in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in ... */
static void C_ccall f_5276(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5276,c,av);}
a=C_alloc(6);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5196,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1163: chicken.base#gensym */
t4=*((C_word*)lf[50]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in k5110 in ... */
static void C_ccall f_5279(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_5279,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5282,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1182: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[101];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in k5113 in ... */
static void C_ccall f_5282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_5282,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5284,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5406,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:1204: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[45];
av2[3]=C_fix(8);
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in ... */
static void C_ccall f_5284(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5284,c,av);}
a=C_alloc(6);
t6=C_i_length(t5);
t7=C_eqp(C_fix(1),t6);
if(C_truep(t7)){
t8=C_i_car(t5);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5398,a[2]=t8,a[3]=t4,a[4]=t2,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1189: chicken.compiler.support#node-class */
t10=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in ... */
static void C_ccall f_5303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5303,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5386,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:1191: chicken.compiler.support#node-class */
t3=*((C_word*)lf[34]+1);{
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
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a5319 in k5380 in k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in ... */
static void C_ccall f_5320(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_5320,c,av);}
a=C_alloc(7);
if(C_truep(C_i_nequalp(t3,C_fix(2)))){
t5=(C_truep(t4)?t4:C_i_cadr(((C_word*)t0)[2]));
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5375,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word*)t0)[5],a[6]=t5,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:1198: chicken.compiler.support#db-get */
t7=*((C_word*)lf[56]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[5];
av2[3]=t5;
av2[4]=lf[65];
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k5361 in k5365 in k5369 in k5373 in a5319 in k5380 in k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in ... */
static void C_ccall f_5363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_5363,c,av);}
a=C_alloc(9);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
/* c-platform.scm:1201: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[5];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5365 in k5369 in k5373 in a5319 in k5380 in k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in ... */
static void C_ccall f_5367(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_5367,c,av);}
a=C_alloc(9);
if(C_truep(C_i_not(t1))){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5363,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1203: chicken.compiler.support#qnode */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5369 in k5373 in a5319 in k5380 in k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in ... */
static void C_ccall f_5371(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5371,c,av);}
a=C_alloc(5);
if(C_truep(C_i_not(t1))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5367,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:1200: chicken.compiler.support#db-get */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=lf[63];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5373 in a5319 in k5380 in k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in ... */
static void C_ccall f_5375(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_5375,c,av);}
a=C_alloc(7);
if(C_truep(C_i_not(t1))){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5371,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:1199: chicken.compiler.support#db-get */
t3=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=lf[64];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5380 in k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_ccall f_5382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_5382,c,av);}
a=C_alloc(6);
t2=C_i_caddr(t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5320,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1193: ##sys#decompose-lambda-list */
t4=*((C_word*)lf[66]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[5];
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5384 in k5301 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in ... */
static void C_ccall f_5386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5386,c,av);}
a=C_alloc(6);
t2=C_eqp(lf[47],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5382,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:1192: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5392 in k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in ... */
static void C_ccall f_5394(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5394,c,av);}
/* c-platform.scm:1190: chicken.compiler.support#db-get */
t2=*((C_word*)lf[56]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_i_car(t1);
av2[4]=lf[57];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k5396 in rewrite-call/cc in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in ... */
static void C_ccall f_5398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_5398,c,av);}
a=C_alloc(10);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5303,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5394,a[2]=t3,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:1190: chicken.compiler.support#node-parameters */
t5=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in k5116 in ... */
static void C_ccall f_5406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_5406,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5409,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1205: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[100];
av2[3]=C_fix(8);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in k5119 in ... */
static void C_ccall f_5409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_5409,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5413,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5540,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:1233: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[99];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in ... */
static void C_ccall f_5413(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5413,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5416,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1247: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[97];
av2[3]=C_fix(3);
av2[4]=lf[96];
av2[5]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in ... */
static void C_ccall f_5416(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5416,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5419,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1248: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[95];
av2[3]=C_fix(3);
av2[4]=lf[96];
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_ccall f_5419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5419,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5422,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1249: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[94];
av2[3]=C_fix(3);
av2[4]=lf[84];
av2[5]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in ... */
static void C_ccall f_5422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5422,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5425,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1250: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[93];
av2[3]=C_fix(3);
av2[4]=lf[81];
av2[5]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in ... */
static void C_ccall f_5425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_5425,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5428,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1251: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[91];
av2[3]=C_fix(3);
av2[4]=lf[92];
av2[5]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in ... */
static void C_ccall f_5428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_5428,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5431,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5500,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:1253: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[90];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in ... */
static void C_ccall f_5431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_5431,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5434,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5460,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:1265: chicken.compiler.optimizer#rewrite */
t4=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[87];
av2[3]=C_fix(8);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in ... */
static void C_ccall f_5434(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5434,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5437,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1277: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[82];
av2[3]=C_fix(23);
av2[4]=C_fix(0);
av2[5]=lf[83];
av2[6]=lf[84];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in ... */
static void C_ccall f_5437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5437,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5440,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1278: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[79];
av2[3]=C_fix(23);
av2[4]=C_fix(1);
av2[5]=lf[80];
av2[6]=lf[81];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in ... */
static void C_ccall f_5440(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_5440,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5443,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1279: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[77];
av2[3]=C_fix(23);
av2[4]=C_fix(2);
av2[5]=lf[78];
av2[6]=C_fix(0);
av2[7]=C_fix(0);
av2[8]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k5441 in k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in ... */
static void C_ccall f_5443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,8)))){
C_save_and_reclaim((void *)f_5443,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5446,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1280: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[75];
av2[3]=C_fix(23);
av2[4]=C_fix(2);
av2[5]=lf[76];
av2[6]=C_fix(0);
av2[7]=C_fix(0);
av2[8]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}

/* k5444 in k5441 in k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in ... */
static void C_ccall f_5446(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5446,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5449,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1281: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[73];
av2[3]=C_fix(23);
av2[4]=C_fix(2);
av2[5]=lf[74];
av2[6]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5447 in k5444 in k5441 in k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in ... */
static void C_ccall f_5449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,6)))){
C_save_and_reclaim((void *)f_5449,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5452,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1282: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[71];
av2[3]=C_fix(23);
av2[4]=C_fix(2);
av2[5]=lf[72];
av2[6]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}

/* k5450 in k5447 in k5444 in k5441 in k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in ... */
static void C_ccall f_5452(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5452,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5455,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1284: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[69];
av2[3]=C_fix(7);
av2[4]=C_fix(2);
av2[5]=lf[70];
av2[6]=C_SCHEME_FALSE;
av2[7]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5453 in k5450 in k5447 in k5444 in k5441 in k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in ... */
static void C_ccall f_5455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,7)))){
C_save_and_reclaim((void *)f_5455,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5458,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1285: chicken.compiler.optimizer#rewrite */
t3=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[67];
av2[3]=C_fix(7);
av2[4]=C_fix(2);
av2[5]=lf[68];
av2[6]=C_SCHEME_FALSE;
av2[7]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k5456 in k5453 in k5450 in k5447 in k5444 in k5441 in k5438 in k5435 in k5432 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in ... */
static void C_ccall f_5458(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5458,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5459 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in ... */
static void C_ccall f_5460(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_5460,c,av);}
a=C_alloc(11);
t6=C_i_length(t5);
t7=C_eqp(C_fix(1),t6);
if(C_truep(t7)){
t8=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5482,a[2]=t4,a[3]=t1,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
t10=C_eqp(*((C_word*)lf[25]+1),lf[24]);
t11=(C_truep(t10)?C_a_i_list1(&a,1,lf[85]):C_a_i_list1(&a,1,lf[86]));
/* c-platform.scm:1272: chicken.compiler.support#make-node */
t12=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t9;
av2[2]=lf[27];
av2[3]=t11;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k5480 in a5459 in k5429 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in ... */
static void C_ccall f_5482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5482,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1269: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a5499 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in ... */
static void C_ccall f_5500(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_5500,c,av);}
a=C_alloc(11);
t6=C_i_length(t5);
t7=C_eqp(C_fix(2),t6);
if(C_truep(t7)){
t8=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5522,a[2]=t4,a[3]=t1,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
t10=C_eqp(*((C_word*)lf[25]+1),lf[24]);
t11=(C_truep(t10)?C_a_i_list1(&a,1,lf[88]):C_a_i_list1(&a,1,lf[89]));
/* c-platform.scm:1260: chicken.compiler.support#make-node */
t12=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t9;
av2[2]=lf[27];
av2[3]=t11;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k5520 in a5499 in k5426 in k5423 in k5420 in k5417 in k5414 in k5411 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in ... */
static void C_ccall f_5522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5522,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1257: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a5539 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in k5122 in ... */
static void C_ccall f_5540(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5540,c,av);}
a=C_alloc(5);
t6=C_i_length(t5);
t7=C_eqp(C_fix(1),t6);
if(C_truep(t7)){
t8=C_i_car(t5);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5598,a[2]=t4,a[3]=t1,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:1239: chicken.compiler.support#node-class */
t10=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k5563 in k5592 in k5596 in a5539 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in ... */
static void C_ccall f_5565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5565,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_i_assq(((C_word*)t0)[2],lf[98]);
if(C_truep(t2)){
t3=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5586,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:1245: chicken.compiler.support#varnode */
t5=*((C_word*)lf[49]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_cdr(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5584 in k5563 in k5592 in k5596 in a5539 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in ... */
static void C_ccall f_5586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5586,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1243: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5592 in k5596 in a5539 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in ... */
static void C_ccall f_5594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5594,c,av);}
a=C_alloc(5);
t2=C_i_car(t1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5565,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:1241: chicken.compiler.support#intrinsic? */
t4=*((C_word*)lf[44]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k5596 in a5539 in k5407 in k5404 in k5280 in k5277 in k5170 in k5167 in k5164 in k5161 in k5158 in k5155 in k5152 in k5149 in k5146 in k5143 in k5140 in k5137 in k5134 in k5131 in k5128 in k5125 in ... */
static void C_ccall f_5598(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5598,c,av);}
a=C_alloc(4);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:1240: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in ... */
static void C_ccall f_5605(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_5605,c,av);}
a=C_alloc(10);
t6=C_i_length(t5);
t7=C_eqp(C_fix(2),t6);
if(C_truep(t7)){
t8=C_i_cadr(t5);
t9=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5720,a[2]=t4,a[3]=t1,a[4]=t9,a[5]=t5,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
/* c-platform.scm:1035: chicken.compiler.support#node-class */
t11=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k5631 in k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in ... */
static void C_ccall f_5633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_5633,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5636,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1032: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=C_eqp(*((C_word*)lf[25]+1),lf[24]);
if(C_truep(t3)){
/* c-platform.scm:1047: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[27];
av2[3]=lf[262];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=C_a_i_list2(&a,2,lf[263],C_fix(5));
/* c-platform.scm:1049: chicken.compiler.support#make-node */
t5=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=lf[28];
av2[3]=t4;
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}}

/* k5634 in k5631 in k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in ... */
static void C_ccall f_5636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5636,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1032: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5665 in k5714 in k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in ... */
static void C_fcall f_5667(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,4)))){
C_save_and_reclaim_args((void *)trf_5667,2,t0,t1);}
a=C_alloc(33);
if(C_truep(t1)){
if(C_truep(C_i_negativep(((C_word*)t0)[2]))){
t2=C_i_car(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5689,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t4=C_s_a_i_negate(&a,1,((C_word*)t0)[2]);
/* c-platform.scm:1042: chicken.compiler.support#qnode */
t5=*((C_word*)lf[29]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t2=C_i_car(((C_word*)t0)[3]);
t3=C_a_i_list2(&a,2,t2,((C_word*)t0)[5]);
/* c-platform.scm:1043: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[27];
av2[3]=lf[265];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_5633(2,av2);}}}

/* k5687 in k5665 in k5714 in k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in ... */
static void C_ccall f_5689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5689,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:1040: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[264];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5710 in k5714 in k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in ... */
static void C_ccall f_5712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5712,c,av);}
t2=((C_word*)t0)[2];
f_5667(t2,C_i_not(t1));}

/* k5714 in k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in ... */
static void C_ccall f_5716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_5716,c,av);}
a=C_alloc(9);
t2=C_i_car(t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5667,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnump(t2))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5712,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1038: chicken.compiler.support#big-fixnum? */
t5=*((C_word*)lf[266]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=t3;
f_5667(t4,C_SCHEME_FALSE);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_5633(2,av2);}}}

/* k5718 in a5604 in k4891 in k4888 in k4885 in k4882 in k4879 in k4876 in k4873 in k4870 in k4867 in k4864 in k4861 in k4858 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in ... */
static void C_ccall f_5720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5720,c,av);}
a=C_alloc(11);
t2=C_eqp(lf[31],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5633,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=C_eqp(*((C_word*)lf[25]+1),lf[24]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5716,a[2]=((C_word*)t0)[5],a[3]=t3,a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:1037: chicken.compiler.support#node-parameters */
t6=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=t3;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_5633(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_5633(2,av2);}}}

/* a5726 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in k4795 in ... */
static void C_ccall f_5727(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_5727,c,av);}
a=C_alloc(16);
t6=C_i_length(t5);
t7=C_eqp(t6,C_fix(3));
if(C_truep(t7)){
t8=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5749,a[2]=t4,a[3]=t1,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
t10=C_i_caddr(t5);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5759,a[2]=t9,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5777,a[2]=t11,a[3]=t10,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:1001: chicken.compiler.support#node-class */
t13=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t13;
av2[1]=t12;
av2[2]=t10;
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k5747 in a5726 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in ... */
static void C_ccall f_5749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5749,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:995: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5757 in a5726 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in ... */
static void C_ccall f_5759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5759,c,av);}
if(C_truep(t1)){
/* c-platform.scm:998: chicken.compiler.support#make-node */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[27];
av2[3]=lf[298];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
/* c-platform.scm:998: chicken.compiler.support#make-node */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[27];
av2[3]=lf[299];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k5771 in k5775 in a5726 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in ... */
static void C_ccall f_5773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5773,c,av);}
/* c-platform.scm:1002: chicken.compiler.support#immediate? */
t2=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_car(t1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k5775 in a5726 in k4855 in k4852 in k4849 in k4846 in k4843 in k4840 in k4837 in k4834 in k4831 in k4828 in k4825 in k4822 in k4819 in k4816 in k4813 in k4810 in k4807 in k4804 in k4801 in k4798 in ... */
static void C_ccall f_5777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5777,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5773,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:1002: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_5759(2,av2);}}}

/* a5783 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in ... */
static void C_ccall f_5784(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_5784,c,av);}
a=C_alloc(16);
t6=C_eqp(lf[24],*((C_word*)lf[25]+1));
if(C_truep(t6)){
t7=C_i_length(t5);
t8=C_eqp(t7,C_fix(2));
if(C_truep(t8)){
t9=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t10=C_i_cadr(t5);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5815,a[2]=t4,a[3]=t1,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5818,a[2]=t5,a[3]=t11,tmp=(C_word)a,a+=4,tmp);
t13=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5854,a[2]=t12,a[3]=t10,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:879: chicken.compiler.support#node-class */
t14=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t14;
av2[1]=t13;
av2[2]=t10;
((C_proc)(void*)(*((C_word*)t14+1)))(3,av2);}}
else{
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k5813 in a5783 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_ccall f_5815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5815,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:875: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5816 in a5783 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_fcall f_5818(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,4)))){
C_save_and_reclaim_args((void *)trf_5818,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5833,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:883: chicken.compiler.support#qnode */
t4=*((C_word*)lf[29]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* c-platform.scm:884: chicken.compiler.support#make-node */
t2=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[461];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k5831 in k5816 in a5783 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in ... */
static void C_ccall f_5833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5833,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:881: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[460];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5848 in k5852 in a5783 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in ... */
static void C_ccall f_5850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5850,c,av);}
t2=((C_word*)t0)[2];
f_5818(t2,C_eqp(C_fix(2),C_i_car(t1)));}

/* k5852 in a5783 in k4594 in k4591 in k4456 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in ... */
static void C_ccall f_5854(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5854,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5850,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:880: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_5818(t3,C_SCHEME_FALSE);}}

/* a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_5861(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_5861,c,av);}
a=C_alloc(8);
t6=C_i_nullp(t5);
t7=(C_truep(t6)?t6:C_i_not(C_eqp(*((C_word*)lf[25]+1),lf[24])));
if(C_truep(t7)){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_i_cdr(t5);
if(C_truep(C_i_nullp(t8))){
t9=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5892,a[2]=t4,a[3]=t1,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[26]+1))){
/* c-platform.scm:817: chicken.compiler.support#make-node */
t11=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=lf[27];
av2[3]=lf[463];
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}
else{
/* c-platform.scm:817: chicken.compiler.support#make-node */
t11=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=lf[27];
av2[3]=lf[464];
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}}
else{
t9=C_u_i_car(t5);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5945,a[2]=t9,a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t11=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5947,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:823: filter */
f_2305(t10,t11,C_u_i_cdr(t5));}}}

/* k5890 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_5892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5892,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:814: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5918 in k5943 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_5920(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5920,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:829: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a5921 in k5943 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_5922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5922,c,av);}
a=C_alloc(6);
t4=(C_truep(*((C_word*)lf[26]+1))?lf[465]:lf[466]);
t5=C_a_i_list2(&a,2,t2,t3);
/* c-platform.scm:835: chicken.compiler.support#make-node */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[27];
av2[3]=t4;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k5943 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_5945(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_5945,c,av);}
a=C_alloc(13);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_i_length(t2);
if(C_truep(C_fixnum_greater_or_equal_p(t3,C_fix(2)))){
t4=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5920,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5922,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:833: chicken.compiler.support#fold-inner */
t7=*((C_word*)lf[60]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* a5946 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_5947(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5947,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5970,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:825: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k5964 in k5968 in a5946 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in ... */
static void C_ccall f_5966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5966,c,av);}
t2=C_i_car(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_not(C_i_zerop(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5968 in a5946 in a5860 in k4453 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_5970(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5970,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5966,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:826: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in ... */
static void C_ccall f_5985(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_5985,c,av);}
a=C_alloc(8);
t6=C_i_nullp(t5);
t7=(C_truep(t6)?t6:C_i_not(C_eqp(*((C_word*)lf[25]+1),lf[24])));
if(C_truep(t7)){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_i_cdr(t5);
if(C_truep(C_i_nullp(t8))){
t9=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6016,a[2]=t4,a[3]=t1,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[26]+1))){
/* c-platform.scm:780: chicken.compiler.support#make-node */
t11=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=lf[27];
av2[3]=lf[467];
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}
else{
/* c-platform.scm:780: chicken.compiler.support#make-node */
t11=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=lf[27];
av2[3]=lf[468];
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}}
else{
t9=C_u_i_car(t5);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6069,a[2]=t9,a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t11=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6071,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:786: filter */
f_2305(t10,t11,C_u_i_cdr(t5));}}}

/* k6014 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6016(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6016,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:777: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6042 in k6067 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_6044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6044,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:792: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a6045 in k6067 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_6046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6046,c,av);}
a=C_alloc(6);
t4=(C_truep(*((C_word*)lf[26]+1))?lf[469]:lf[470]);
t5=C_a_i_list2(&a,2,t2,t3);
/* c-platform.scm:798: chicken.compiler.support#make-node */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[27];
av2[3]=t4;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k6067 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6069(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_6069,c,av);}
a=C_alloc(13);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_i_length(t2);
if(C_truep(C_fixnum_greater_or_equal_p(t3,C_fix(2)))){
t4=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6044,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6046,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:796: chicken.compiler.support#fold-inner */
t7=*((C_word*)lf[60]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* a6070 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6071,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6094,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:788: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6088 in k6092 in a6070 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_6090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6090,c,av);}
t2=C_i_car(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_not(C_i_zerop(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6092 in a6070 in a5984 in k4450 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_6094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6094,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6090,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:789: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in k4387 in ... */
static void C_ccall f_6109(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6109,c,av);}
a=C_alloc(6);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6113,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6227,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:746: filter */
f_2305(t6,t7,t5);}

/* k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in ... */
static void C_ccall f_6113(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6113,c,av);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t1))){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6134,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:751: chicken.compiler.support#qnode */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=C_i_cdr(t1);
if(C_truep(C_i_nullp(t2))){
t3=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t4=C_i_car(t1);
t5=C_a_i_list2(&a,2,((C_word*)t0)[2],t4);
/* c-platform.scm:753: chicken.compiler.support#make-node */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=t3;
av2[4]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t3=C_eqp(*((C_word*)lf[25]+1),lf[24]);
if(C_truep(t3)){
t4=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6176,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6178,tmp=(C_word)a,a+=2,tmp);
/* c-platform.scm:759: chicken.compiler.support#fold-inner */
t7=*((C_word*)lf[60]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}}

/* k6132 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6134,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:751: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6174 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6176,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:755: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* a6177 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6178(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6178,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6185,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6221,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:761: chicken.compiler.support#node-class */
t6=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k6183 in a6177 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_fcall f_6185(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_6185,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6196,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:762: chicken.compiler.support#qnode */
t3=*((C_word*)lf[29]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[4]);
/* c-platform.scm:763: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[472];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k6194 in k6183 in a6177 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_6196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6196,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:762: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[27];
av2[3]=lf[471];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6215 in k6219 in a6177 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in ... */
static void C_ccall f_6217(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6217,c,av);}
t2=((C_word*)t0)[2];
f_6185(t2,C_eqp(C_fix(2),C_i_car(t1)));}

/* k6219 in a6177 in k6111 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_6221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6221,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6217,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:761: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_6185(t3,C_SCHEME_FALSE);}}

/* a6226 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in k4390 in ... */
static void C_ccall f_6227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6227,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6253,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:748: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6247 in k6251 in a6226 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in ... */
static void C_ccall f_6249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6249,c,av);}
t2=C_i_car(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_not(C_eqp(C_fix(1),t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6251 in a6226 in a6108 in k4447 in k4444 in k4441 in k4438 in k4435 in k4432 in k4429 in k4426 in k4423 in k4420 in k4417 in k4414 in k4411 in k4408 in k4405 in k4402 in k4399 in k4396 in k4393 in ... */
static void C_ccall f_6253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6253,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6249,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:749: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6255(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6255,c,av);}
a=C_alloc(13);
t6=C_i_length(t5);
t7=C_eqp(t6,C_fix(2));
if(C_truep(t7)){
t8=C_i_car(t5);
t9=C_i_cadr(t5);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6271,a[2]=t1,a[3]=t4,a[4]=t5,a[5]=t9,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6411,a[2]=t4,a[3]=t10,a[4]=t9,a[5]=t8,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:356: chicken.compiler.support#node-class */
t12=*((C_word*)lf[34]+1);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6271(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_6271,c,av);}
a=C_alloc(15);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6277,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6298,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6365,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:360: chicken.compiler.support#node-class */
t5=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k6275 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6277(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_6277,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6295,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:371: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[27];
av2[3]=lf[926];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k6293 in k6275 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6295,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:369: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6296 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_6298(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_6298,2,t0,t1);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6301,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=t2;
f_6301(t3,t1);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6342,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:363: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k6299 in k6296 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_6301(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_6301,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6316,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:368: chicken.compiler.support#make-node */
t4=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[27];
av2[3]=lf[927];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_6277(2,av2);}}}

/* k6314 in k6299 in k6296 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_6316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6316,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:366: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6326 in k6336 in k6340 in k6296 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_ccall f_6328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6328,c,av);}
t2=((C_word*)t0)[2];
f_6301(t2,(C_truep(t1)?t1:C_i_symbolp(((C_word*)t0)[3])));}

/* k6336 in k6340 in k6296 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_6338(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6338,c,av);}
a=C_alloc(4);
t2=C_i_car(t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6328,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:365: chicken.compiler.support#immediate? */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6340 in k6296 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6342(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6342,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6338,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:364: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_6301(t3,C_SCHEME_FALSE);}}

/* k6349 in k6359 in k6363 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_6351(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6351,c,av);}
t2=((C_word*)t0)[2];
f_6298(t2,(C_truep(t1)?t1:C_i_symbolp(((C_word*)t0)[3])));}

/* k6359 in k6363 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6361(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6361,c,av);}
a=C_alloc(4);
t2=C_i_car(t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6351,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* c-platform.scm:362: chicken.compiler.support#immediate? */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k6363 in k6269 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6365,c,av);}
a=C_alloc(3);
t2=C_eqp(lf[31],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6361,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* c-platform.scm:361: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
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
else{
t3=((C_word*)t0)[2];
f_6298(t3,C_SCHEME_FALSE);}}

/* k6393 in k6401 in k6397 in k6405 in k6409 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in ... */
static void C_ccall f_6395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_6395,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* c-platform.scm:359: chicken.compiler.support#make-node */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[23];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6397 in k6405 in k6409 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6399(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6399,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6403,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:358: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[33]+1);{
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

/* k6401 in k6397 in k6405 in k6409 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 in ... */
static void C_ccall f_6403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6403,c,av);}
a=C_alloc(8);
if(C_truep(C_i_equalp(((C_word*)t0)[2],t1))){
t2=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6395,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:359: chicken.compiler.support#qnode */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_6271(2,av2);}}}

/* k6405 in k6409 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6407,c,av);}
a=C_alloc(5);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6399,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* c-platform.scm:358: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_6271(2,av2);}}}

/* k6409 in a6254 in k3247 in k3244 in k3088 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6411(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6411,c,av);}
a=C_alloc(6);
t2=C_eqp(lf[35],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6407,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:357: chicken.compiler.support#node-class */
t4=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_6271(2,av2);}}}

/* k6418 in k3085 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6420(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6420,c,av);}
/* c-platform.scm:321: chicken.compiler.optimizer#rewrite */
t2=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[929];
av2[3]=C_fix(8);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6422 in k3018 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6424(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6424,c,av);}
/* c-platform.scm:320: chicken.compiler.optimizer#rewrite */
t2=*((C_word*)lf[46]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[933];
av2[3]=C_fix(8);
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* for-each-loop596 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_6426(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_6426,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6436,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[937]+1);
/* c-platform.scm:292: g612 */
t6=*((C_word*)lf[937]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=lf[938];
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6434 in for-each-loop596 in k3009 in k3002 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6436(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6436,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6426(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* map-loop558 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_fcall f_6449(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_6449,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6474,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* c-platform.scm:125: chicken.base#symbol-append */
t4=*((C_word*)lf[943]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[944];
av2[3]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6472 in map-loop558 in k2987 in k2984 in k2981 in k2973 in k1692 in k1689 in k1686 in k1683 in k1680 in k1677 */
static void C_ccall f_6474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6474,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6449(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_c_2dplatform_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("c-platform"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_c_2dplatform_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(10076))){
C_save(t1);
C_rereclaim2(10076*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,952);
lf[0]=C_h_intern(&lf[0],10, C_text("c-platform"));
lf[1]=C_h_intern(&lf[1],28, C_text("chicken.compiler.c-platform#"));
lf[4]=C_h_intern(&lf[4],5, C_text("foldr"));
lf[5]=C_h_intern(&lf[5],48, C_text("chicken.compiler.c-platform#default-declarations"));
lf[6]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001always-bound\376\003\000\000\002\376\001\000\000\024\001##sys#standard-input\376\003\000\000\002\376\001\000\000\025\001##sys#stan"
"dard-output\376\003\000\000\002\376\001\000\000\024\001##sys#standard-error\376\003\000\000\002\376\001\000\000\025\001##sys#undefined-value\376\377\016\376\003\000"
"\000\002\376\003\000\000\002\376\001\000\000\022\001bound-to-procedure\376\003\000\000\002\376\001\000\000\016\001##sys#for-each\376\003\000\000\002\376\001\000\000\011\001##sys#map\376\003\000\000"
"\002\376\001\000\000\013\001##sys#print\376\003\000\000\002\376\001\000\000\014\001##sys#setter\376\003\000\000\002\376\001\000\000\015\001##sys#setslot\376\003\000\000\002\376\001\000\000\022\001##sy"
"s#dynamic-wind\376\003\000\000\002\376\001\000\000\026\001##sys#call-with-values\376\003\000\000\002\376\001\000\000\021\001##sys#start-timer\376\003\000\000\002"
"\376\001\000\000\020\001##sys#stop-timer\376\003\000\000\002\376\001\000\000\011\001##sys#gcd\376\003\000\000\002\376\001\000\000\011\001##sys#lcm\376\003\000\000\002\376\001\000\000\020\001##sys#s"
"tructure\077\376\003\000\000\002\376\001\000\000\012\001##sys#slot\376\003\000\000\002\376\001\000\000\025\001##sys#allocate-vector\376\003\000\000\002\376\001\000\000\022\001##sys#l"
"ist->vector\376\003\000\000\002\376\001\000\000\017\001##sys#block-ref\376\003\000\000\002\376\001\000\000\020\001##sys#block-set!\376\003\000\000\002\376\001\000\000\012\001##sys"
"#list\376\003\000\000\002\376\001\000\000\012\001##sys#cons\376\003\000\000\002\376\001\000\000\014\001##sys#append\376\003\000\000\002\376\001\000\000\014\001##sys#vector\376\003\000\000\002\376\001\000"
"\000\033\001##sys#foreign-char-argument\376\003\000\000\002\376\001\000\000\035\001##sys#foreign-fixnum-argument\376\003\000\000\002\376\001\000\000\035"
"\001##sys#foreign-flonum-argument\376\003\000\000\002\376\001\000\000\013\001##sys#error\376\003\000\000\002\376\001\000\000\023\001##sys#peek-c-stri"
"ng\376\003\000\000\002\376\001\000\000\033\001##sys#peek-nonnull-c-string\376\003\000\000\002\376\001\000\000\034\001##sys#peek-and-free-c-string\376"
"\003\000\000\002\376\001\000\000$\001##sys#peek-and-free-nonnull-c-string\376\003\000\000\002\376\001\000\000\034\001##sys#foreign-block-arg"
"ument\376\003\000\000\002\376\001\000\000\035\001##sys#foreign-string-argument\376\003\000\000\002\376\001\000\000\036\001##sys#foreign-pointer-ar"
"gument\376\003\000\000\002\376\001\000\000$\001##sys#call-with-current-continuation\376\377\016\376\377\016"));
lf[7]=C_h_intern(&lf[7],58, C_text("chicken.compiler.c-platform#default-profiling-declarations"));
lf[8]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001##core#declare\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001uses\376\003\000\000\002\376\001\000\000\010\001profiler\376\377\016\376\003\000\000\002\376\003\000"
"\000\002\376\001\000\000\022\001bound-to-procedure\376\003\000\000\002\376\001\000\000\023\001##sys#profile-entry\376\003\000\000\002\376\001\000\000\022\001##sys#profile"
"-exit\376\003\000\000\002\376\001\000\000\033\001##sys#register-profile-info\376\003\000\000\002\376\001\000\000\036\001##sys#set-profile-info-vec"
"tor!\376\377\016\376\377\016\376\377\016"));
lf[9]=C_h_intern(&lf[9],41, C_text("chicken.compiler.c-platform#default-units"));
lf[10]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\007\001library\376\003\000\000\002\376\001\000\000\004\001eval\376\377\016"));
lf[11]=C_h_intern(&lf[11],44, C_text("chicken.compiler.c-platform#words-per-flonum"));
lf[12]=C_h_intern(&lf[12],47, C_text("chicken.compiler.c-platform#target-include-file"));
lf[13]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011chicken.h"));
lf[14]=C_h_intern(&lf[14],50, C_text("chicken.compiler.c-platform#valid-compiler-options"));
lf[15]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\005\001-help\376\003\000\000\002\376\001\000\000\001\001h\376\003\000\000\002\376\001\000\000\004\001help\376\003\000\000\002\376\001\000\000\007\001version\376\003\000\000\002\376\001\000\000\007\001verbose\376"
"\003\000\000\002\376\001\000\000\014\001explicit-use\376\003\000\000\002\376\001\000\000\010\001no-trace\376\003\000\000\002\376\001\000\000\013\001no-warnings\376\003\000\000\002\376\001\000\000\006\001unsafe"
"\376\003\000\000\002\376\001\000\000\005\001block\376\003\000\000\002\376\001\000\000\014\001check-syntax\376\003\000\000\002\376\001\000\000\011\001to-stdout\376\003\000\000\002\376\001\000\000\025\001no-usual-i"
"ntegrations\376\003\000\000\002\376\001\000\000\020\001case-insensitive\376\003\000\000\002\376\001\000\000\016\001no-lambda-info\376\003\000\000\002\376\001\000\000\007\001profil"
"e\376\003\000\000\002\376\001\000\000\006\001inline\376\003\000\000\002\376\001\000\000\024\001keep-shadowed-macros\376\003\000\000\002\376\001\000\000\021\001ignore-repository\376\003\000"
"\000\002\376\001\000\000\021\001fixnum-arithmetic\376\003\000\000\002\376\001\000\000\022\001disable-interrupts\376\003\000\000\002\376\001\000\000\026\001optimize-leaf-r"
"outines\376\003\000\000\002\376\001\000\000\016\001compile-syntax\376\003\000\000\002\376\001\000\000\014\001tag-pointers\376\003\000\000\002\376\001\000\000\022\001accumulate-pro"
"file\376\003\000\000\002\376\001\000\000\035\001disable-stack-overflow-checks\376\003\000\000\002\376\001\000\000\003\001raw\376\003\000\000\002\376\001\000\000\012\001specialize\376"
"\003\000\000\002\376\001\000\000\036\001emit-external-prototypes-first\376\003\000\000\002\376\001\000\000\007\001release\376\003\000\000\002\376\001\000\000\005\001local\376\003\000\000\002\376"
"\001\000\000\015\001inline-global\376\003\000\000\002\376\001\000\000\014\001analyze-only\376\003\000\000\002\376\001\000\000\007\001dynamic\376\003\000\000\002\376\001\000\000\006\001static\376\003\000\000"
"\002\376\001\000\000\016\001no-argc-checks\376\003\000\000\002\376\001\000\000\023\001no-procedure-checks\376\003\000\000\002\376\001\000\000\027\001no-parentheses-syn"
"onyms\376\003\000\000\002\376\001\000\000)\001no-procedure-checks-for-toplevel-bindings\376\003\000\000\002\376\001\000\000\017\001no-bound-che"
"cks\376\003\000\000\002\376\001\000\000&\001no-procedure-checks-for-usual-bindings\376\003\000\000\002\376\001\000\000\022\001no-compiler-synta"
"x\376\003\000\000\002\376\001\000\000\027\001no-parentheses-synonyms\376\003\000\000\002\376\001\000\000\020\001no-symbol-escape\376\003\000\000\002\376\001\000\000\013\001r5rs-sy"
"ntax\376\003\000\000\002\376\001\000\000\031\001emit-all-import-libraries\376\003\000\000\002\376\001\000\000\014\001strict-types\376\003\000\000\002\376\001\000\000\012\001cluste"
"ring\376\003\000\000\002\376\001\000\000\004\001lfa2\376\003\000\000\002\376\001\000\000\012\001debug-info\376\003\000\000\002\376\001\000\000\033\001regenerate-import-libraries\376\003"
"\000\000\002\376\001\000\000\012\001setup-mode\376\003\000\000\002\376\001\000\000\023\001module-registration\376\003\000\000\002\376\001\000\000\026\001no-module-registrati"
"on\376\377\016"));
lf[16]=C_h_intern(&lf[16],64, C_text("chicken.compiler.c-platform#valid-compiler-options-with-argument"));
lf[17]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\005\001debug\376\003\000\000\002\376\001\000\000\004\001link\376\003\000\000\002\376\001\000\000\016\001emit-link-file\376\003\000\000\002\376\001\000\000\013\001output-file\376\003"
"\000\000\002\376\001\000\000\014\001include-path\376\003\000\000\002\376\001\000\000\011\001heap-size\376\003\000\000\002\376\001\000\000\012\001stack-size\376\003\000\000\002\376\001\000\000\004\001unit\376\003\000"
"\000\002\376\001\000\000\004\001uses\376\003\000\000\002\376\001\000\000\006\001module\376\003\000\000\002\376\001\000\000\015\001keyword-style\376\003\000\000\002\376\001\000\000\021\001require-extensio"
"n\376\003\000\000\002\376\001\000\000\014\001inline-limit\376\003\000\000\002\376\001\000\000\014\001profile-name\376\003\000\000\002\376\001\000\000\007\001prelude\376\003\000\000\002\376\001\000\000\010\001post"
"lude\376\003\000\000\002\376\001\000\000\010\001prologue\376\003\000\000\002\376\001\000\000\010\001epilogue\376\003\000\000\002\376\001\000\000\007\001nursery\376\003\000\000\002\376\001\000\000\006\001extend\376\003\000"
"\000\002\376\001\000\000\007\001feature\376\003\000\000\002\376\001\000\000\012\001no-feature\376\003\000\000\002\376\001\000\000\014\001unroll-limit\376\003\000\000\002\376\001\000\000\020\001emit-inlin"
"e-file\376\003\000\000\002\376\001\000\000\023\001consult-inline-file\376\003\000\000\002\376\001\000\000\017\001emit-types-file\376\003\000\000\002\376\001\000\000\022\001consult"
"-types-file\376\003\000\000\002\376\001\000\000\023\001emit-import-library\376\377\016"));
lf[18]=C_h_intern(&lf[18],47, C_text("chicken.compiler.core#default-standard-bindings"));
lf[19]=C_h_intern(&lf[19],47, C_text("chicken.compiler.core#default-extended-bindings"));
lf[20]=C_h_intern(&lf[20],39, C_text("chicken.compiler.core#internal-bindings"));
lf[21]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001##sys#slot\376\003\000\000\002\376\001\000\000\015\001##sys#setslot\376\003\000\000\002\376\001\000\000\017\001##sys#block-ref\376\003\000\000\002\376\001\000\000"
"\020\001##sys#block-set!\376\003\000\000\002\376\001\000\000\011\001##sys#/-2\376\003\000\000\002\376\001\000\000$\001##sys#call-with-current-continu"
"ation\376\003\000\000\002\376\001\000\000\012\001##sys#size\376\003\000\000\002\376\001\000\000\012\001##sys#byte\376\003\000\000\002\376\001\000\000\015\001##sys#setbyte\376\003\000\000\002\376\001\000\000"
"\016\001##sys#pointer\077\376\003\000\000\002\376\001\000\000\030\001##sys#generic-structure\077\376\003\000\000\002\376\001\000\000\020\001##sys#structure\077\376\003"
"\000\000\002\376\001\000\000\025\001##sys#check-structure\376\003\000\000\002\376\001\000\000\022\001##sys#check-number\376\003\000\000\002\376\001\000\000\020\001##sys#chec"
"k-list\376\003\000\000\002\376\001\000\000\020\001##sys#check-pair\376\003\000\000\002\376\001\000\000\022\001##sys#check-string\376\003\000\000\002\376\001\000\000\022\001##sys#c"
"heck-symbol\376\003\000\000\002\376\001\000\000\023\001##sys#check-boolean\376\003\000\000\002\376\001\000\000\024\001##sys#check-locative\376\003\000\000\002\376\001\000"
"\000\020\001##sys#check-port\376\003\000\000\002\376\001\000\000\026\001##sys#check-input-port\376\003\000\000\002\376\001\000\000\027\001##sys#check-outpu"
"t-port\376\003\000\000\002\376\001\000\000\025\001##sys#check-open-port\376\003\000\000\002\376\001\000\000\020\001##sys#check-char\376\003\000\000\002\376\001\000\000\022\001##sy"
"s#check-vector\376\003\000\000\002\376\001\000\000\027\001##sys#check-byte-vector\376\003\000\000\002\376\001\000\000\012\001##sys#list\376\003\000\000\002\376\001\000\000\012\001"
"##sys#cons\376\003\000\000\002\376\001\000\000\026\001##sys#call-with-values\376\003\000\000\002\376\001\000\000\035\001##sys#flonum-in-fixnum-ran"
"ge\077\376\003\000\000\002\376\001\000\000\020\001##sys#immediate\077\376\003\000\000\002\376\001\000\000\024\001##sys#context-switch\376\003\000\000\002\376\001\000\000\024\001##sys#ma"
"ke-structure\376\003\000\000\002\376\001\000\000\013\001##sys#apply\376\003\000\000\002\376\001\000\000\022\001##sys#apply-values\376\003\000\000\002\376\001\000\000\047\001chicke"
"n.continuation#continuation-graft\376\003\000\000\002\376\001\000\000\021\001##sys#bytevector\077\376\003\000\000\002\376\001\000\000\021\001##sys#ma"
"ke-vector\376\003\000\000\002\376\001\000\000\014\001##sys#setter\376\003\000\000\002\376\001\000\000\011\001##sys#car\376\003\000\000\002\376\001\000\000\011\001##sys#cdr\376\003\000\000\002\376\001\000"
"\000\013\001##sys#pair\077\376\003\000\000\002\376\001\000\000\011\001##sys#eq\077\376\003\000\000\002\376\001\000\000\013\001##sys#list\077\376\003\000\000\002\376\001\000\000\015\001##sys#vector\077"
"\376\003\000\000\002\376\001\000\000\012\001##sys#eqv\077\376\003\000\000\002\376\001\000\000\021\001##sys#get-keyword\376\003\000\000\002\376\001\000\000\033\001##sys#foreign-char-a"
"rgument\376\003\000\000\002\376\001\000\000\035\001##sys#foreign-fixnum-argument\376\003\000\000\002\376\001\000\000\035\001##sys#foreign-flonum-a"
"rgument\376\003\000\000\002\376\001\000\000\034\001##sys#foreign-block-argument\376\003\000\000\002\376\001\000\000%\001##sys#foreign-struct-wr"
"apper-argument\376\003\000\000\002\376\001\000\000\035\001##sys#foreign-string-argument\376\003\000\000\002\376\001\000\000\036\001##sys#foreign-p"
"ointer-argument\376\003\000\000\002\376\001\000\000\012\001##sys#void\376\003\000\000\002\376\001\000\000%\001##sys#foreign-ranged-integer-argu"
"ment\376\003\000\000\002\376\001\000\000.\001##sys#foreign-unsigned-ranged-integer-argument\376\003\000\000\002\376\001\000\000\021\001##sys#pe"
"ek-fixnum\376\003\000\000\002\376\001\000\000\016\001##sys#setislot\376\003\000\000\002\376\001\000\000\022\001##sys#poke-integer\376\003\000\000\002\376\001\000\000\020\001##sys#"
"permanent\077\376\003\000\000\002\376\001\000\000\014\001##sys#values\376\003\000\000\002\376\001\000\000\021\001##sys#poke-double\376\003\000\000\002\376\001\000\000\023\001##sys#in"
"tern-symbol\376\003\000\000\002\376\001\000\000\023\001##sys#null-pointer\077\376\003\000\000\002\376\001\000\000\017\001##sys#peek-byte\376\003\000\000\002\376\001\000\000\022\001##"
"sys#file-exists\077\376\003\000\000\002\376\001\000\000\025\001##sys#substring-index\376\003\000\000\002\376\001\000\000\030\001##sys#substring-index"
"-ci\376\003\000\000\002\376\001\000\000\011\001##sys#lcm\376\003\000\000\002\376\001\000\000\011\001##sys#gcd\376\377\016"));
lf[22]=C_h_intern(&lf[22],34, C_text("chicken.compiler.support#make-node"));
lf[23]=C_h_intern(&lf[23],11, C_text("##core#call"));
lf[24]=C_h_intern(&lf[24],6, C_text("fixnum"));
lf[25]=C_h_intern(&lf[25],36, C_text("chicken.compiler.support#number-type"));
lf[26]=C_h_intern(&lf[26],31, C_text("chicken.compiler.support#unsafe"));
lf[27]=C_h_intern(&lf[27],13, C_text("##core#inline"));
lf[28]=C_h_intern(&lf[28],22, C_text("##core#inline_allocate"));
lf[29]=C_h_intern(&lf[29],30, C_text("chicken.compiler.support#qnode"));
lf[30]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\005C_eqp\376\377\016"));
lf[31]=C_h_intern(&lf[31],5, C_text("quote"));
lf[32]=C_h_intern(&lf[32],35, C_text("chicken.compiler.support#immediate\077"));
lf[33]=C_h_intern(&lf[33],40, C_text("chicken.compiler.support#node-parameters"));
lf[34]=C_h_intern(&lf[34],35, C_text("chicken.compiler.support#node-class"));
lf[35]=C_h_intern(&lf[35],15, C_text("##core#variable"));
lf[36]=C_h_intern(&lf[36],3, C_text("map"));
lf[37]=C_h_intern(&lf[37],13, C_text("scheme#append"));
lf[38]=C_h_intern(&lf[38],20, C_text("chicken.base#butlast"));
lf[39]=C_h_intern(&lf[39],11, C_text("##core#proc"));
lf[40]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\007C_apply\376\003\000\000\002\376\377\006\001\376\377\016"));
lf[41]=C_h_intern(&lf[41],6, C_text("values"));
lf[42]=C_h_intern(&lf[42],12, C_text("##sys#values"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\016C_apply_values\376\003\000\000\002\376\377\006\001\376\377\016"));
lf[44]=C_h_intern(&lf[44],35, C_text("chicken.compiler.support#intrinsic\077"));
lf[45]=C_h_intern(&lf[45],37, C_text("scheme#call-with-current-continuation"));
lf[46]=C_h_intern(&lf[46],34, C_text("chicken.compiler.optimizer#rewrite"));
lf[47]=C_h_intern(&lf[47],13, C_text("##core#lambda"));
lf[48]=C_h_intern(&lf[48],3, C_text("let"));
lf[49]=C_h_intern(&lf[49],32, C_text("chicken.compiler.support#varnode"));
lf[50]=C_h_intern(&lf[50],19, C_text("chicken.base#gensym"));
lf[51]=C_h_intern(&lf[51],2, C_text("f_"));
lf[52]=C_h_intern(&lf[52],34, C_text("chicken.compiler.support#debugging"));
lf[53]=C_h_intern(&lf[53],1, C_text("o"));
lf[54]=C_decode_literal(C_heaptop,C_text("\376B\000\000)removing single-valued `call-with-values\047"));
lf[55]=C_h_intern(&lf[55],1, C_text("r"));
lf[56]=C_h_intern(&lf[56],31, C_text("chicken.compiler.support#db-get"));
lf[57]=C_h_intern(&lf[57],5, C_text("value"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\024C_fixnum_shift_right\376\377\016"));
lf[59]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\017C_fixnum_divide\376\377\016"));
lf[60]=C_h_intern(&lf[60],35, C_text("chicken.compiler.support#fold-inner"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_a_i_vector"));
lf[62]=C_h_intern(&lf[62],16, C_text("##core#undefined"));
lf[63]=C_h_intern(&lf[63],16, C_text("inline-transient"));
lf[64]=C_h_intern(&lf[64],8, C_text("assigned"));
lf[65]=C_h_intern(&lf[65],10, C_text("references"));
lf[66]=C_h_intern(&lf[66],27, C_text("##sys#decompose-lambda-list"));
lf[67]=C_h_intern(&lf[67],17, C_text("##sys#get-keyword"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_get_keyword"));
lf[69]=C_h_intern(&lf[69],27, C_text("chicken.keyword#get-keyword"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_get_keyword"));
lf[71]=C_h_intern(&lf[71],33, C_text("chicken.string#substring-index-ci"));
lf[72]=C_h_intern(&lf[72],24, C_text("##sys#substring-index-ci"));
lf[73]=C_h_intern(&lf[73],30, C_text("chicken.string#substring-index"));
lf[74]=C_h_intern(&lf[74],21, C_text("##sys#substring-index"));
lf[75]=C_h_intern(&lf[75],29, C_text("chicken.string#substring-ci=\077"));
lf[76]=C_h_intern(&lf[76],20, C_text("##sys#substring-ci=\077"));
lf[77]=C_h_intern(&lf[77],26, C_text("chicken.string#substring=\077"));
lf[78]=C_h_intern(&lf[78],17, C_text("##sys#substring=\077"));
lf[79]=C_h_intern(&lf[79],17, C_text("scheme#write-char"));
lf[80]=C_h_intern(&lf[80],21, C_text("##sys#write-char/port"));
lf[81]=C_h_intern(&lf[81],21, C_text("##sys#standard-output"));
lf[82]=C_h_intern(&lf[82],16, C_text("scheme#read-char"));
lf[83]=C_h_intern(&lf[83],20, C_text("##sys#read-char/port"));
lf[84]=C_h_intern(&lf[84],20, C_text("##sys#standard-input"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_fixnum_length"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_integer_length"));
lf[87]=C_h_intern(&lf[87],30, C_text("chicken.bitwise#integer-length"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_u_i_bit_to_bool"));
lf[89]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_bit_to_bool"));
lf[90]=C_h_intern(&lf[90],28, C_text("chicken.bitwise#bit->boolean"));
lf[91]=C_h_intern(&lf[91],31, C_text("chicken.base#current-error-port"));
lf[92]=C_h_intern(&lf[92],20, C_text("##sys#standard-error"));
lf[93]=C_h_intern(&lf[93],26, C_text("scheme#current-output-port"));
lf[94]=C_h_intern(&lf[94],25, C_text("scheme#current-input-port"));
lf[95]=C_h_intern(&lf[95],10, C_text("##sys#void"));
lf[96]=C_h_intern(&lf[96],21, C_text("##sys#undefined-value"));
lf[97]=C_h_intern(&lf[97],17, C_text("chicken.base#void"));
lf[98]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001scheme#car\376\001\000\000\017\001scheme#set-car!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001scheme#cdr\376\001\000\000\017\001s"
"cheme#set-cdr!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001scheme#string-ref\376\001\000\000\022\001scheme#string-set!\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\021\001scheme#vector-ref\376\001\000\000\022\001scheme#vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001srfi-4#u8vector-"
"ref\376\001\000\000\024\001srfi-4#u8vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\023\001srfi-4#s8vector-ref\376\001\000\000\024\001srfi-4#s8v"
"ector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001srfi-4#u16vector-ref\376\001\000\000\025\001srfi-4#u16vector-set!\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\024\001srfi-4#s16vector-ref\376\001\000\000\025\001srfi-4#s16vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001srfi-4#u"
"32vector-ref\376\001\000\000\025\001srfi-4#u32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001srfi-4#s32vector-ref\376\001\000\000\025"
"\001srfi-4#s32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001srfi-4#u64vector-ref\376\001\000\000\025\001srfi-4#u64vector"
"-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001srfi-4#s64vector-ref\376\001\000\000\025\001srfi-4#s64vector-set!\376\003\000\000\002\376\003\000\000\002\376\001"
"\000\000\024\001srfi-4#f32vector-ref\376\001\000\000\025\001srfi-4#f32vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\024\001srfi-4#f64vec"
"tor-ref\376\001\000\000\025\001srfi-4#f64vector-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\035\001chicken.locative#locative-ref\376"
"\001\000\000\036\001chicken.locative#locative-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\035\001chicken.memory#pointer-u8-ref"
"\376\001\000\000\036\001chicken.memory#pointer-u8-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\035\001chicken.memory#pointer-s8-re"
"f\376\001\000\000\036\001chicken.memory#pointer-s8-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointer-u16-"
"ref\376\001\000\000\037\001chicken.memory#pointer-u16-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointer-s"
"16-ref\376\001\000\000\037\001chicken.memory#pointer-s16-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointe"
"r-u32-ref\376\001\000\000\037\001chicken.memory#pointer-u32-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001chicken.memory#poi"
"nter-s32-ref\376\001\000\000\037\001chicken.memory#pointer-s32-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001chicken.memory#"
"pointer-f32-ref\376\001\000\000\037\001chicken.memory#pointer-f32-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\036\001chicken.memo"
"ry#pointer-f64-ref\376\001\000\000\037\001chicken.memory#pointer-f64-set!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\047\001chicken.m"
"emory.representation#block-ref\376\001\000\000(\001chicken.memory.representation#block-set!\376\377\016"));
lf[99]=C_h_intern(&lf[99],12, C_text("##sys#setter"));
lf[100]=C_h_intern(&lf[100],20, C_text("chicken.base#call/cc"));
lf[101]=C_h_intern(&lf[101],17, C_text("##sys#make-vector"));
lf[102]=C_h_intern(&lf[102],18, C_text("scheme#make-vector"));
lf[103]=C_h_intern(&lf[103],29, C_text("srfi-4#f64vector->blob/shared"));
lf[104]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[105]=C_h_intern(&lf[105],29, C_text("srfi-4#f32vector->blob/shared"));
lf[106]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[107]=C_h_intern(&lf[107],29, C_text("srfi-4#s64vector->blob/shared"));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[109]=C_h_intern(&lf[109],29, C_text("srfi-4#u64vector->blob/shared"));
lf[110]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[111]=C_h_intern(&lf[111],29, C_text("srfi-4#s32vector->blob/shared"));
lf[112]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[113]=C_h_intern(&lf[113],29, C_text("srfi-4#u32vector->blob/shared"));
lf[114]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[115]=C_h_intern(&lf[115],29, C_text("srfi-4#s16vector->blob/shared"));
lf[116]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[117]=C_h_intern(&lf[117],29, C_text("srfi-4#u16vector->blob/shared"));
lf[118]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[119]=C_h_intern(&lf[119],28, C_text("srfi-4#s8vector->blob/shared"));
lf[120]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[121]=C_h_intern(&lf[121],28, C_text("srfi-4#u8vector->blob/shared"));
lf[122]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[123]=C_h_intern(&lf[123],18, C_text("chicken.base#atom\077"));
lf[124]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_not_pair_p"));
lf[125]=C_h_intern(&lf[125],23, C_text("srfi-4#f64vector-length"));
lf[126]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_f64vector_length"));
lf[127]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_f64vector_length"));
lf[128]=C_h_intern(&lf[128],23, C_text("srfi-4#f32vector-length"));
lf[129]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_f32vector_length"));
lf[130]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_f32vector_length"));
lf[131]=C_h_intern(&lf[131],23, C_text("srfi-4#s64vector-length"));
lf[132]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_s64vector_length"));
lf[133]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_s64vector_length"));
lf[134]=C_h_intern(&lf[134],23, C_text("srfi-4#u64vector-length"));
lf[135]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_u64vector_length"));
lf[136]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_u64vector_length"));
lf[137]=C_h_intern(&lf[137],23, C_text("srfi-4#s32vector-length"));
lf[138]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_s32vector_length"));
lf[139]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_s32vector_length"));
lf[140]=C_h_intern(&lf[140],23, C_text("srfi-4#u32vector-length"));
lf[141]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_u32vector_length"));
lf[142]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_u32vector_length"));
lf[143]=C_h_intern(&lf[143],23, C_text("srfi-4#s16vector-length"));
lf[144]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_s16vector_length"));
lf[145]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_s16vector_length"));
lf[146]=C_h_intern(&lf[146],23, C_text("srfi-4#u16vector-length"));
lf[147]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_u16vector_length"));
lf[148]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_u16vector_length"));
lf[149]=C_h_intern(&lf[149],22, C_text("srfi-4#s8vector-length"));
lf[150]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_i_s8vector_length"));
lf[151]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_s8vector_length"));
lf[152]=C_h_intern(&lf[152],22, C_text("srfi-4#u8vector-length"));
lf[153]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_i_u8vector_length"));
lf[154]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_u8vector_length"));
lf[155]=C_h_intern(&lf[155],21, C_text("srfi-4#f64vector-set!"));
lf[156]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_f64vector_set"));
lf[157]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_f64vector_set"));
lf[158]=C_h_intern(&lf[158],21, C_text("srfi-4#f32vector-set!"));
lf[159]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_f32vector_set"));
lf[160]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_f32vector_set"));
lf[161]=C_h_intern(&lf[161],21, C_text("srfi-4#s64vector-set!"));
lf[162]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_s64vector_set"));
lf[163]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_s64vector_set"));
lf[164]=C_h_intern(&lf[164],21, C_text("srfi-4#u64vector-set!"));
lf[165]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_u64vector_set"));
lf[166]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_u64vector_set"));
lf[167]=C_h_intern(&lf[167],21, C_text("srfi-4#s32vector-set!"));
lf[168]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_s32vector_set"));
lf[169]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_s32vector_set"));
lf[170]=C_h_intern(&lf[170],21, C_text("srfi-4#u32vector-set!"));
lf[171]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_u32vector_set"));
lf[172]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_u32vector_set"));
lf[173]=C_h_intern(&lf[173],21, C_text("srfi-4#s16vector-set!"));
lf[174]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_s16vector_set"));
lf[175]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_s16vector_set"));
lf[176]=C_h_intern(&lf[176],21, C_text("srfi-4#u16vector-set!"));
lf[177]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_u16vector_set"));
lf[178]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_u16vector_set"));
lf[179]=C_h_intern(&lf[179],20, C_text("srfi-4#s8vector-set!"));
lf[180]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_s8vector_set"));
lf[181]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_u_i_s8vector_set"));
lf[182]=C_h_intern(&lf[182],20, C_text("srfi-4#u8vector-set!"));
lf[183]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_u8vector_set"));
lf[184]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_u_i_u8vector_set"));
lf[185]=C_h_intern(&lf[185],20, C_text("srfi-4#f64vector-ref"));
lf[186]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_a_i_f64vector_ref"));
lf[187]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_a_u_i_f64vector_ref"));
lf[188]=C_h_intern(&lf[188],20, C_text("srfi-4#f32vector-ref"));
lf[189]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_a_i_f32vector_ref"));
lf[190]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_a_u_i_f32vector_ref"));
lf[191]=C_h_intern(&lf[191],20, C_text("srfi-4#s32vector-ref"));
lf[192]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_a_i_s32vector_ref"));
lf[193]=C_h_intern(&lf[193],20, C_text("srfi-4#u32vector-ref"));
lf[194]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_a_i_u32vector_ref"));
lf[195]=C_h_intern(&lf[195],20, C_text("srfi-4#s16vector-ref"));
lf[196]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_s16vector_ref"));
lf[197]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_s16vector_ref"));
lf[198]=C_h_intern(&lf[198],20, C_text("srfi-4#u16vector-ref"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_u16vector_ref"));
lf[200]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_u16vector_ref"));
lf[201]=C_h_intern(&lf[201],19, C_text("srfi-4#s8vector-ref"));
lf[202]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_s8vector_ref"));
lf[203]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_u_i_s8vector_ref"));
lf[204]=C_h_intern(&lf[204],19, C_text("srfi-4#u8vector-ref"));
lf[205]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_u8vector_ref"));
lf[206]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_u_i_u8vector_ref"));
lf[207]=C_h_intern(&lf[207],22, C_text("chicken.blob#blob-size"));
lf[208]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_block_size"));
lf[209]=C_h_intern(&lf[209],46, C_text("##sys#foreign-unsigned-ranged-integer-argument"));
lf[210]=C_decode_literal(C_heaptop,C_text("\376B\000\000-C_i_foreign_unsigned_ranged_integer_argumentp"));
lf[211]=C_h_intern(&lf[211],37, C_text("##sys#foreign-ranged-integer-argument"));
lf[212]=C_decode_literal(C_heaptop,C_text("\376B\000\000$C_i_foreign_ranged_integer_argumentp"));
lf[213]=C_h_intern(&lf[213],30, C_text("##sys#foreign-pointer-argument"));
lf[214]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035C_i_foreign_pointer_argumentp"));
lf[215]=C_h_intern(&lf[215],29, C_text("##sys#foreign-string-argument"));
lf[216]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034C_i_foreign_string_argumentp"));
lf[217]=C_h_intern(&lf[217],37, C_text("##sys#foreign-struct-wrapper-argument"));
lf[218]=C_decode_literal(C_heaptop,C_text("\376B\000\000$C_i_foreign_struct_wrapper_argumentp"));
lf[219]=C_h_intern(&lf[219],28, C_text("##sys#foreign-block-argument"));
lf[220]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033C_i_foreign_block_argumentp"));
lf[221]=C_h_intern(&lf[221],29, C_text("##sys#foreign-flonum-argument"));
lf[222]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034C_i_foreign_flonum_argumentp"));
lf[223]=C_h_intern(&lf[223],27, C_text("##sys#foreign-char-argument"));
lf[224]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032C_i_foreign_char_argumentp"));
lf[225]=C_h_intern(&lf[225],29, C_text("##sys#foreign-fixnum-argument"));
lf[226]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034C_i_foreign_fixnum_argumentp"));
lf[227]=C_h_intern(&lf[227],30, C_text("chicken.locative#locative-set!"));
lf[228]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_locative_set"));
lf[229]=C_h_intern(&lf[229],31, C_text("chicken.locative#locative-index"));
lf[230]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_locative_index"));
lf[231]=C_h_intern(&lf[231],33, C_text("chicken.locative#locative->object"));
lf[232]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_i_locative_to_object"));
lf[233]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_i_locative_to_object"));
lf[234]=C_h_intern(&lf[234],16, C_text("##sys#immediate\077"));
lf[235]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_immp"));
lf[236]=C_h_intern(&lf[236],19, C_text("##sys#null-pointer\077"));
lf[237]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_null_pointerp"));
lf[238]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_null_pointerp"));
lf[239]=C_h_intern(&lf[239],16, C_text("##sys#permanent\077"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_permanentp"));
lf[241]=C_h_intern(&lf[241],18, C_text("scheme#string-ci=\077"));
lf[242]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_i_string_ci_equal_p"));
lf[243]=C_h_intern(&lf[243],15, C_text("scheme#string=\077"));
lf[244]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_string_equal_p"));
lf[245]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_i_string_equal_p"));
lf[246]=C_h_intern(&lf[246],17, C_text("##sys#poke-double"));
lf[247]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_poke_double"));
lf[248]=C_h_intern(&lf[248],18, C_text("##sys#poke-integer"));
lf[249]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_poke_integer"));
lf[250]=C_h_intern(&lf[250],14, C_text("##sys#setislot"));
lf[251]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_set_i_slot"));
lf[252]=C_h_intern(&lf[252],30, C_text("chicken.memory#pointer->object"));
lf[253]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_pointer_to_object"));
lf[254]=C_h_intern(&lf[254],15, C_text("##sys#peek-byte"));
lf[255]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_peek_byte"));
lf[256]=C_h_intern(&lf[256],17, C_text("##sys#peek-fixnum"));
lf[257]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_peek_fixnum"));
lf[258]=C_h_intern(&lf[258],13, C_text("##sys#setbyte"));
lf[259]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_setbyte"));
lf[260]=C_h_intern(&lf[260],10, C_text("##sys#byte"));
lf[261]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_subbyte"));
lf[262]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\033C_i_fixnum_arithmetic_shift\376\377\016"));
lf[263]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_s_a_i_arithmetic_shift"));
lf[264]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\024C_fixnum_shift_right\376\377\016"));
lf[265]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\023C_fixnum_shift_left\376\377\016"));
lf[266]=C_h_intern(&lf[266],36, C_text("chicken.compiler.support#big-fixnum\077"));
lf[267]=C_h_intern(&lf[267],32, C_text("chicken.bitwise#arithmetic-shift"));
lf[268]=C_h_intern(&lf[268],20, C_text("chicken.fixnum#fxrem"));
lf[269]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034C_i_fixnum_remainder_checked"));
lf[270]=C_h_intern(&lf[270],20, C_text("chicken.fixnum#fxmod"));
lf[271]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_fixnum_modulo"));
lf[272]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_u_fixnum_modulo"));
lf[273]=C_h_intern(&lf[273],18, C_text("chicken.fixnum#fx/"));
lf[274]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_fixnum_divide"));
lf[275]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_u_fixnum_divide"));
lf[276]=C_h_intern(&lf[276],20, C_text("chicken.fixnum#fxior"));
lf[277]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_fixnum_or"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_u_fixnum_or"));
lf[279]=C_h_intern(&lf[279],20, C_text("chicken.fixnum#fxand"));
lf[280]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_and"));
lf[281]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_u_fixnum_and"));
lf[282]=C_h_intern(&lf[282],20, C_text("chicken.fixnum#fxxor"));
lf[283]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_xor"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_xor"));
lf[285]=C_h_intern(&lf[285],20, C_text("chicken.fixnum#fxneg"));
lf[286]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_fixnum_negate"));
lf[287]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_u_fixnum_negate"));
lf[288]=C_h_intern(&lf[288],20, C_text("chicken.fixnum#fxshr"));
lf[289]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_fixnum_shift_right"));
lf[290]=C_h_intern(&lf[290],20, C_text("chicken.fixnum#fxshl"));
lf[291]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_fixnum_shift_left"));
lf[292]=C_h_intern(&lf[292],18, C_text("chicken.fixnum#fx-"));
lf[293]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_fixnum_difference"));
lf[294]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_fixnum_difference"));
lf[295]=C_h_intern(&lf[295],18, C_text("chicken.fixnum#fx+"));
lf[296]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_fixnum_plus"));
lf[297]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_u_fixnum_plus"));
lf[298]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\016C_i_set_i_slot\376\377\016"));
lf[299]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\013C_i_setslot\376\377\016"));
lf[300]=C_h_intern(&lf[300],13, C_text("##sys#setslot"));
lf[301]=C_h_intern(&lf[301],30, C_text("chicken.memory#pointer-f64-ref"));
lf[302]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027C_a_u_i_pointer_f64_ref"));
lf[303]=C_h_intern(&lf[303],30, C_text("chicken.memory#pointer-f32-ref"));
lf[304]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027C_a_u_i_pointer_f32_ref"));
lf[305]=C_h_intern(&lf[305],30, C_text("chicken.memory#pointer-s32-ref"));
lf[306]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027C_a_u_i_pointer_s32_ref"));
lf[307]=C_h_intern(&lf[307],30, C_text("chicken.memory#pointer-u32-ref"));
lf[308]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027C_a_u_i_pointer_u32_ref"));
lf[309]=C_h_intern(&lf[309],31, C_text("chicken.memory#pointer-f64-set!"));
lf[310]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_f64_set"));
lf[311]=C_h_intern(&lf[311],31, C_text("chicken.memory#pointer-f32-set!"));
lf[312]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_f32_set"));
lf[313]=C_h_intern(&lf[313],31, C_text("chicken.memory#pointer-s32-set!"));
lf[314]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_s32_set"));
lf[315]=C_h_intern(&lf[315],31, C_text("chicken.memory#pointer-u32-set!"));
lf[316]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_u32_set"));
lf[317]=C_h_intern(&lf[317],31, C_text("chicken.memory#pointer-s16-set!"));
lf[318]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_s16_set"));
lf[319]=C_h_intern(&lf[319],31, C_text("chicken.memory#pointer-u16-set!"));
lf[320]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_u16_set"));
lf[321]=C_h_intern(&lf[321],30, C_text("chicken.memory#pointer-s8-set!"));
lf[322]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_i_pointer_s8_set"));
lf[323]=C_h_intern(&lf[323],30, C_text("chicken.memory#pointer-u8-set!"));
lf[324]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_i_pointer_u8_set"));
lf[325]=C_h_intern(&lf[325],30, C_text("chicken.memory#pointer-s16-ref"));
lf[326]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_s16_ref"));
lf[327]=C_h_intern(&lf[327],30, C_text("chicken.memory#pointer-u16-ref"));
lf[328]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_u_i_pointer_u16_ref"));
lf[329]=C_h_intern(&lf[329],29, C_text("chicken.memory#pointer-s8-ref"));
lf[330]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_i_pointer_s8_ref"));
lf[331]=C_h_intern(&lf[331],29, C_text("chicken.memory#pointer-u8-ref"));
lf[332]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_i_pointer_u8_ref"));
lf[333]=C_h_intern(&lf[333],29, C_text("chicken.locative#locative-ref"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_a_i_locative_ref"));
lf[335]=C_h_intern(&lf[335],23, C_text("chicken.memory#pointer+"));
lf[336]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_a_u_i_pointer_inc"));
lf[337]=C_h_intern(&lf[337],31, C_text("chicken.memory#pointer->address"));
lf[338]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_a_i_pointer_to_address"));
lf[339]=C_h_intern(&lf[339],31, C_text("chicken.memory#address->pointer"));
lf[340]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_a_i_address_to_pointer"));
lf[341]=C_h_intern(&lf[341],13, C_text("scheme#string"));
lf[342]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_a_i_string"));
lf[343]=C_h_intern(&lf[343],20, C_text("##sys#make-structure"));
lf[344]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_a_i_record"));
lf[345]=C_h_intern(&lf[345],12, C_text("##sys#vector"));
lf[346]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_a_i_vector"));
lf[347]=C_h_intern(&lf[347],13, C_text("scheme#vector"));
lf[348]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_a_i_vector"));
lf[349]=C_h_intern(&lf[349],10, C_text("##sys#list"));
lf[350]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_a_i_list"));
lf[351]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\001\000\000\000\000\376\003\000\000\002\376\377\001\000\000\000\003\376\377\016"));
lf[352]=C_h_intern(&lf[352],11, C_text("scheme#list"));
lf[353]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_a_i_list"));
lf[354]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\001\000\000\000\000\376\003\000\000\002\376\377\001\000\000\000\003\376\377\016"));
lf[355]=C_h_intern(&lf[355],22, C_text("chicken.base#weak-cons"));
lf[356]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_a_i_weak_cons"));
lf[357]=C_h_intern(&lf[357],10, C_text("##sys#cons"));
lf[358]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_a_i_cons"));
lf[359]=C_h_intern(&lf[359],11, C_text("scheme#cons"));
lf[360]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_a_i_cons"));
lf[361]=C_h_intern(&lf[361],22, C_text("chicken.flonum#fpround"));
lf[362]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_a_i_flonum_floor"));
lf[363]=C_h_intern(&lf[363],24, C_text("chicken.flonum#fpceiling"));
lf[364]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_a_i_flonum_ceiling"));
lf[365]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_a_i_flonum_round"));
lf[366]=C_h_intern(&lf[366],25, C_text("chicken.flonum#fptruncate"));
lf[367]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_a_i_flonum_truncate"));
lf[368]=C_h_intern(&lf[368],20, C_text("chicken.flonum#fpabs"));
lf[369]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_abs"));
lf[370]=C_h_intern(&lf[370],21, C_text("chicken.flonum#fpsqrt"));
lf[371]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_a_i_flonum_sqrt"));
lf[372]=C_h_intern(&lf[372],20, C_text("chicken.flonum#fplog"));
lf[373]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_log"));
lf[374]=C_h_intern(&lf[374],21, C_text("chicken.flonum#fpexpt"));
lf[375]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_a_i_flonum_expt"));
lf[376]=C_h_intern(&lf[376],20, C_text("chicken.flonum#fpexp"));
lf[377]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_exp"));
lf[378]=C_h_intern(&lf[378],22, C_text("chicken.flonum#fpatan2"));
lf[379]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_a_i_flonum_atan2"));
lf[380]=C_h_intern(&lf[380],21, C_text("chicken.flonum#fpatan"));
lf[381]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_a_i_flonum_atan"));
lf[382]=C_h_intern(&lf[382],21, C_text("chicken.flonum#fpacos"));
lf[383]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_a_i_flonum_acos"));
lf[384]=C_h_intern(&lf[384],21, C_text("chicken.flonum#fpasin"));
lf[385]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_a_i_flonum_asin"));
lf[386]=C_h_intern(&lf[386],20, C_text("chicken.flonum#fptan"));
lf[387]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_tan"));
lf[388]=C_h_intern(&lf[388],20, C_text("chicken.flonum#fpcos"));
lf[389]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_cos"));
lf[390]=C_h_intern(&lf[390],20, C_text("chicken.flonum#fpsin"));
lf[391]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_sin"));
lf[392]=C_h_intern(&lf[392],15, C_text("scheme#truncate"));
lf[393]=C_h_intern(&lf[393],6, C_text("flonum"));
lf[394]=C_h_intern(&lf[394],14, C_text("scheme#ceiling"));
lf[395]=C_h_intern(&lf[395],12, C_text("scheme#floor"));
lf[396]=C_h_intern(&lf[396],22, C_text("chicken.flonum#fpfloor"));
lf[397]=C_h_intern(&lf[397],22, C_text("chicken.fixnum#fxeven\077"));
lf[398]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_fixnumevenp"));
lf[399]=C_h_intern(&lf[399],21, C_text("chicken.fixnum#fxodd\077"));
lf[400]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_fixnumoddp"));
lf[401]=C_h_intern(&lf[401],11, C_text("scheme#odd\077"));
lf[402]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_oddp"));
lf[403]=C_h_intern(&lf[403],12, C_text("scheme#even\077"));
lf[404]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_evenp"));
lf[405]=C_h_intern(&lf[405],16, C_text("scheme#remainder"));
lf[406]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_fixnum_modulo"));
lf[407]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_fixnum_modulo"));
lf[408]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_fixnumoddp"));
lf[409]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_fixnumoddp"));
lf[410]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_fixnumevenp"));
lf[411]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_fixnumevenp"));
lf[412]=C_h_intern(&lf[412],17, C_text("##sys#make-symbol"));
lf[413]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_make_symbol"));
lf[414]=C_h_intern(&lf[414],19, C_text("##sys#intern-symbol"));
lf[415]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_string_to_symbol"));
lf[416]=C_h_intern(&lf[416],20, C_text("##sys#context-switch"));
lf[417]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_context_switch"));
lf[418]=C_h_intern(&lf[418],31, C_text("chicken.platform#return-to-host"));
lf[419]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_return_to_host"));
lf[420]=C_h_intern(&lf[420],25, C_text("##sys#ensure-heap-reserve"));
lf[421]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_ensure_heap_reserve"));
lf[422]=C_h_intern(&lf[422],21, C_text("##sys#allocate-vector"));
lf[423]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_allocate_vector"));
lf[424]=C_h_intern(&lf[424],36, C_text("##sys#call-with-current-continuation"));
lf[425]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_call_cc"));
lf[426]=C_h_intern(&lf[426],21, C_text("scheme#number->string"));
lf[427]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\001\000\000\000\001\376\377\001\000\000\000\002"));
lf[428]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_number_to_string"));
lf[429]=C_h_intern(&lf[429],8, C_text("scheme#-"));
lf[430]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\001\000\000\000\001\376\377\006\000"));
lf[431]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_minus"));
lf[432]=C_h_intern(&lf[432],8, C_text("scheme#+"));
lf[433]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_plus"));
lf[434]=C_h_intern(&lf[434],8, C_text("scheme#\052"));
lf[435]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_times"));
lf[436]=C_h_intern(&lf[436],9, C_text("scheme#<="));
lf[437]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_less_or_equal_p"));
lf[438]=C_h_intern(&lf[438],9, C_text("scheme#>="));
lf[439]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_greater_or_equal_p"));
lf[440]=C_h_intern(&lf[440],8, C_text("scheme#<"));
lf[441]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_lessp"));
lf[442]=C_h_intern(&lf[442],8, C_text("scheme#>"));
lf[443]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_greaterp"));
lf[444]=C_h_intern(&lf[444],8, C_text("scheme#="));
lf[445]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_nequalp"));
lf[446]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_less_or_equalp"));
lf[447]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_i_greater_or_equalp"));
lf[448]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_lessp"));
lf[449]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_greaterp"));
lf[450]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_nequalp"));
lf[451]=C_h_intern(&lf[451],13, C_text("scheme#modulo"));
lf[452]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_s_a_i_modulo"));
lf[453]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_s_a_i_remainder"));
lf[454]=C_h_intern(&lf[454],15, C_text("scheme#quotient"));
lf[455]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_s_a_i_quotient"));
lf[456]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_s_a_i_times"));
lf[457]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_s_a_i_minus"));
lf[458]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_s_a_i_plus"));
lf[459]=C_h_intern(&lf[459],8, C_text("scheme#/"));
lf[460]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\024C_fixnum_shift_right\376\377\016"));
lf[461]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\017C_fixnum_divide\376\377\016"));
lf[462]=C_h_intern(&lf[462],9, C_text("##sys#/-2"));
lf[463]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\021C_u_fixnum_negate\376\377\016"));
lf[464]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\017C_fixnum_negate\376\377\016"));
lf[465]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\025C_u_fixnum_difference\376\377\016"));
lf[466]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\023C_fixnum_difference\376\377\016"));
lf[467]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\017C_u_fixnum_plus\376\377\016"));
lf[468]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\015C_fixnum_plus\376\377\016"));
lf[469]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\017C_u_fixnum_plus\376\377\016"));
lf[470]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\015C_fixnum_plus\376\377\016"));
lf[471]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\023C_fixnum_shift_left\376\377\016"));
lf[472]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\016C_fixnum_times\376\377\016"));
lf[473]=C_h_intern(&lf[473],10, C_text("scheme#lcm"));
lf[474]=C_h_intern(&lf[474],10, C_text("scheme#gcd"));
lf[475]=C_h_intern(&lf[475],21, C_text("chicken.base#identity"));
lf[476]=C_h_intern(&lf[476],9, C_text("##sys#lcm"));
lf[477]=C_h_intern(&lf[477],9, C_text("##sys#gcd"));
lf[478]=C_h_intern(&lf[478],18, C_text("scheme#vector-set!"));
lf[479]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_vector_set"));
lf[480]=C_h_intern(&lf[480],19, C_text("scheme#list->string"));
lf[481]=C_h_intern(&lf[481],18, C_text("##sys#list->string"));
lf[482]=C_h_intern(&lf[482],19, C_text("scheme#string->list"));
lf[483]=C_h_intern(&lf[483],18, C_text("##sys#string->list"));
lf[484]=C_h_intern(&lf[484],20, C_text("scheme#string-append"));
lf[485]=C_h_intern(&lf[485],19, C_text("##sys#string-append"));
lf[486]=C_h_intern(&lf[486],16, C_text("scheme#substring"));
lf[487]=C_h_intern(&lf[487],15, C_text("##sys#substring"));
lf[488]=C_h_intern(&lf[488],50, C_text("chicken.memory.representation#make-record-instance"));
lf[489]=C_h_intern(&lf[489],16, C_text("##sys#block-set!"));
lf[490]=C_h_intern(&lf[490],40, C_text("chicken.memory.representation#block-set!"));
lf[491]=C_h_intern(&lf[491],10, C_text("scheme#map"));
lf[492]=C_h_intern(&lf[492],9, C_text("##sys#map"));
lf[493]=C_h_intern(&lf[493],15, C_text("scheme#for-each"));
lf[494]=C_h_intern(&lf[494],14, C_text("##sys#for-each"));
lf[495]=C_h_intern(&lf[495],6, C_text("setter"));
lf[496]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_fixnum_less_or_equal_p"));
lf[497]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_flonum_less_or_equal_p"));
lf[498]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033C_fixnum_greater_or_equal_p"));
lf[499]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033C_flonum_greater_or_equal_p"));
lf[500]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_fixnum_lessp"));
lf[501]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_flonum_lessp"));
lf[502]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_fixnum_greaterp"));
lf[503]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_flonum_greaterp"));
lf[504]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_eqp"));
lf[505]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_equalp"));
lf[506]=C_h_intern(&lf[506],16, C_text("##sys#check-char"));
lf[507]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_char_2"));
lf[508]=C_h_intern(&lf[508],21, C_text("##sys#check-structure"));
lf[509]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_i_check_structure_2"));
lf[510]=C_h_intern(&lf[510],18, C_text("##sys#check-vector"));
lf[511]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_check_vector_2"));
lf[512]=C_h_intern(&lf[512],23, C_text("##sys#check-byte-vector"));
lf[513]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_i_check_bytevector_2"));
lf[514]=C_h_intern(&lf[514],18, C_text("##sys#check-string"));
lf[515]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_check_string_2"));
lf[516]=C_h_intern(&lf[516],18, C_text("##sys#check-symbol"));
lf[517]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_check_symbol_2"));
lf[518]=C_h_intern(&lf[518],20, C_text("##sys#check-locative"));
lf[519]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_check_locative_2"));
lf[520]=C_h_intern(&lf[520],19, C_text("##sys#check-boolean"));
lf[521]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_i_check_boolean_2"));
lf[522]=C_h_intern(&lf[522],16, C_text("##sys#check-pair"));
lf[523]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_pair_2"));
lf[524]=C_h_intern(&lf[524],16, C_text("##sys#check-list"));
lf[525]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_list_2"));
lf[526]=C_h_intern(&lf[526],18, C_text("##sys#check-number"));
lf[527]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_check_number_2"));
lf[528]=C_h_intern(&lf[528],18, C_text("##sys#check-fixnum"));
lf[529]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_check_fixnum_2"));
lf[530]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_check_char"));
lf[531]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_i_check_structure"));
lf[532]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_vector"));
lf[533]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_i_check_bytevector"));
lf[534]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_string"));
lf[535]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_symbol"));
lf[536]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_check_locative"));
lf[537]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_check_boolean"));
lf[538]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_check_pair"));
lf[539]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_check_list"));
lf[540]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_number"));
lf[541]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_i_check_fixnum"));
lf[542]=C_h_intern(&lf[542],20, C_text("scheme#string-length"));
lf[543]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_string_length"));
lf[544]=C_h_intern(&lf[544],19, C_text("##sys#vector-length"));
lf[545]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_vector_length"));
lf[546]=C_h_intern(&lf[546],20, C_text("scheme#vector-length"));
lf[547]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_vector_length"));
lf[548]=C_h_intern(&lf[548],20, C_text("scheme#integer->char"));
lf[549]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_make_character"));
lf[550]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_unfix"));
lf[551]=C_h_intern(&lf[551],20, C_text("scheme#char->integer"));
lf[552]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_fix"));
lf[553]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_character_code"));
lf[554]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_fix"));
lf[555]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_header_size"));
lf[556]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_fix"));
lf[557]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_header_size"));
lf[558]=C_h_intern(&lf[558],16, C_text("scheme#negative\077"));
lf[559]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_negativep"));
lf[560]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_flonum_lessp"));
lf[561]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_fixnum_lessp"));
lf[562]=C_h_intern(&lf[562],16, C_text("scheme#positive\077"));
lf[563]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_positivep"));
lf[564]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_flonum_greaterp"));
lf[565]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_fixnum_greaterp"));
lf[566]=C_h_intern(&lf[566],12, C_text("scheme#zero\077"));
lf[567]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_zerop"));
lf[568]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_zerop2"));
lf[569]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_eqp"));
lf[570]=C_h_intern(&lf[570],19, C_text("chicken.flonum#fp\052+"));
lf[571]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031C_a_i_flonum_multiply_add"));
lf[572]=C_h_intern(&lf[572],20, C_text("chicken.flonum#fpgcd"));
lf[573]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_a_i_flonum_gcd"));
lf[574]=C_h_intern(&lf[574],20, C_text("chicken.flonum#fpneg"));
lf[575]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_a_i_flonum_negate"));
lf[576]=C_h_intern(&lf[576],19, C_text("chicken.flonum#fp/\077"));
lf[577]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035C_a_i_flonum_quotient_checked"));
lf[578]=C_h_intern(&lf[578],18, C_text("chicken.flonum#fp/"));
lf[579]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_a_i_flonum_quotient"));
lf[580]=C_h_intern(&lf[580],18, C_text("chicken.flonum#fp\052"));
lf[581]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_a_i_flonum_times"));
lf[582]=C_h_intern(&lf[582],18, C_text("chicken.flonum#fp-"));
lf[583]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027C_a_i_flonum_difference"));
lf[584]=C_h_intern(&lf[584],18, C_text("chicken.flonum#fp+"));
lf[585]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_a_i_flonum_plus"));
lf[586]=C_h_intern(&lf[586],27, C_text("chicken.bitwise#bitwise-not"));
lf[587]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_s_a_i_bitwise_not"));
lf[588]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_not"));
lf[589]=C_h_intern(&lf[589],27, C_text("chicken.bitwise#bitwise-ior"));
lf[590]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_fixnum_or"));
lf[591]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_u_fixnum_or"));
lf[592]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_s_a_i_bitwise_ior"));
lf[593]=C_h_intern(&lf[593],27, C_text("chicken.bitwise#bitwise-xor"));
lf[594]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_xor"));
lf[595]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_xor"));
lf[596]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_s_a_i_bitwise_xor"));
lf[597]=C_h_intern(&lf[597],27, C_text("chicken.bitwise#bitwise-and"));
lf[598]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_and"));
lf[599]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_u_fixnum_and"));
lf[600]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_s_a_i_bitwise_and"));
lf[601]=C_h_intern(&lf[601],10, C_text("scheme#abs"));
lf[602]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_abs"));
lf[603]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_abs"));
lf[604]=C_h_intern(&lf[604],15, C_text("scheme#set-cdr!"));
lf[605]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_set_cdr"));
lf[606]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_u_i_set_cdr"));
lf[607]=C_h_intern(&lf[607],15, C_text("scheme#set-car!"));
lf[608]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_set_car"));
lf[609]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_u_i_set_car"));
lf[610]=C_h_intern(&lf[610],13, C_text("scheme#member"));
lf[611]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_member"));
lf[612]=C_h_intern(&lf[612],12, C_text("scheme#assoc"));
lf[613]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_assoc"));
lf[614]=C_h_intern(&lf[614],11, C_text("scheme#memq"));
lf[615]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_memq"));
lf[616]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_memq"));
lf[617]=C_h_intern(&lf[617],11, C_text("scheme#assq"));
lf[618]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_assq"));
lf[619]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_assq"));
lf[620]=C_h_intern(&lf[620],11, C_text("scheme#memv"));
lf[621]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_memv"));
lf[622]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_memq"));
lf[623]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_memq"));
lf[624]=C_h_intern(&lf[624],11, C_text("scheme#assv"));
lf[625]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_assv"));
lf[626]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_assq"));
lf[627]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_assq"));
lf[628]=C_h_intern(&lf[628],45, C_text("chicken.memory.representation#number-of-slots"));
lf[629]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_block_size"));
lf[630]=C_h_intern(&lf[630],39, C_text("chicken.memory.representation#block-ref"));
lf[631]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[632]=C_h_intern(&lf[632],17, C_text("##sys#bytevector\077"));
lf[633]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_bytevectorp"));
lf[634]=C_h_intern(&lf[634],16, C_text("##sys#structure\077"));
lf[635]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_structurep"));
lf[636]=C_h_intern(&lf[636],16, C_text("scheme#list-tail"));
lf[637]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_list_tail"));
lf[638]=C_h_intern(&lf[638],20, C_text("scheme#char-downcase"));
lf[639]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_char_downcase"));
lf[640]=C_h_intern(&lf[640],18, C_text("scheme#char-upcase"));
lf[641]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_u_i_char_upcase"));
lf[642]=C_h_intern(&lf[642],23, C_text("scheme#char-lower-case\077"));
lf[643]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_char_lower_casep"));
lf[644]=C_h_intern(&lf[644],23, C_text("scheme#char-upper-case\077"));
lf[645]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_char_upper_casep"));
lf[646]=C_h_intern(&lf[646],23, C_text("scheme#char-whitespace\077"));
lf[647]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_char_whitespacep"));
lf[648]=C_h_intern(&lf[648],23, C_text("scheme#char-alphabetic\077"));
lf[649]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026C_u_i_char_alphabeticp"));
lf[650]=C_h_intern(&lf[650],20, C_text("scheme#char-numeric\077"));
lf[651]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_char_numericp"));
lf[652]=C_h_intern(&lf[652],20, C_text("chicken.fixnum#fxlen"));
lf[653]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_fixnum_length"));
lf[654]=C_h_intern(&lf[654],20, C_text("chicken.fixnum#fxgcd"));
lf[655]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_fixnum_gcd"));
lf[656]=C_h_intern(&lf[656],20, C_text("chicken.flonum#fpmin"));
lf[657]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_flonum_min"));
lf[658]=C_h_intern(&lf[658],20, C_text("chicken.flonum#fpmax"));
lf[659]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_flonum_max"));
lf[660]=C_h_intern(&lf[660],20, C_text("chicken.fixnum#fxmin"));
lf[661]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_fixnum_min"));
lf[662]=C_h_intern(&lf[662],20, C_text("chicken.fixnum#fxmax"));
lf[663]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_fixnum_max"));
lf[664]=C_h_intern(&lf[664],19, C_text("chicken.flonum#fp<="));
lf[665]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_flonum_less_or_equal_p"));
lf[666]=C_h_intern(&lf[666],19, C_text("chicken.flonum#fp>="));
lf[667]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033C_flonum_greater_or_equal_p"));
lf[668]=C_h_intern(&lf[668],18, C_text("chicken.flonum#fp<"));
lf[669]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_flonum_lessp"));
lf[670]=C_h_intern(&lf[670],18, C_text("chicken.flonum#fp>"));
lf[671]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_flonum_greaterp"));
lf[672]=C_h_intern(&lf[672],18, C_text("chicken.flonum#fp="));
lf[673]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_flonum_equalp"));
lf[674]=C_h_intern(&lf[674],19, C_text("chicken.fixnum#fx<="));
lf[675]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_fixnum_less_or_equal_p"));
lf[676]=C_h_intern(&lf[676],19, C_text("chicken.fixnum#fx>="));
lf[677]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033C_fixnum_greater_or_equal_p"));
lf[678]=C_h_intern(&lf[678],18, C_text("chicken.fixnum#fx<"));
lf[679]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_fixnum_lessp"));
lf[680]=C_h_intern(&lf[680],18, C_text("chicken.fixnum#fx>"));
lf[681]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_fixnum_greaterp"));
lf[682]=C_h_intern(&lf[682],18, C_text("chicken.fixnum#fx="));
lf[683]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_eqp"));
lf[684]=C_h_intern(&lf[684],19, C_text("chicken.fixnum#fx/\077"));
lf[685]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_i_o_fixnum_quotient"));
lf[686]=C_h_intern(&lf[686],19, C_text("chicken.fixnum#fx\052\077"));
lf[687]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_o_fixnum_times"));
lf[688]=C_h_intern(&lf[688],19, C_text("chicken.fixnum#fx-\077"));
lf[689]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027C_i_o_fixnum_difference"));
lf[690]=C_h_intern(&lf[690],19, C_text("chicken.fixnum#fx+\077"));
lf[691]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_o_fixnum_plus"));
lf[692]=C_h_intern(&lf[692],18, C_text("chicken.fixnum#fx\052"));
lf[693]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_fixnum_times"));
lf[694]=C_h_intern(&lf[694],20, C_text("chicken.fixnum#fxnot"));
lf[695]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_fixnum_not"));
lf[696]=C_h_intern(&lf[696],10, C_text("##sys#size"));
lf[697]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_block_size"));
lf[698]=C_h_intern(&lf[698],15, C_text("##sys#block-ref"));
lf[699]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_block_ref"));
lf[700]=C_h_intern(&lf[700],10, C_text("##sys#slot"));
lf[701]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[702]=C_h_intern(&lf[702],14, C_text("scheme#char<=\077"));
lf[703]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030C_i_char_less_or_equal_p"));
lf[704]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032C_u_i_char_less_or_equal_p"));
lf[705]=C_h_intern(&lf[705],14, C_text("scheme#char>=\077"));
lf[706]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033C_i_char_greater_or_equal_p"));
lf[707]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035C_u_i_char_greater_or_equal_p"));
lf[708]=C_h_intern(&lf[708],13, C_text("scheme#char<\077"));
lf[709]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_char_lessp"));
lf[710]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_u_i_char_lessp"));
lf[711]=C_h_intern(&lf[711],13, C_text("scheme#char>\077"));
lf[712]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_char_greaterp"));
lf[713]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_i_char_greaterp"));
lf[714]=C_h_intern(&lf[714],13, C_text("scheme#char=\077"));
lf[715]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017C_i_char_equalp"));
lf[716]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_u_i_char_equalp"));
lf[717]=C_h_intern(&lf[717],17, C_text("scheme#vector-ref"));
lf[718]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_vector_ref"));
lf[719]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_slot"));
lf[720]=C_h_intern(&lf[720],18, C_text("scheme#string-set!"));
lf[721]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_string_set"));
lf[722]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_setsubchar"));
lf[723]=C_h_intern(&lf[723],17, C_text("scheme#string-ref"));
lf[724]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_string_ref"));
lf[725]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_subchar"));
lf[726]=C_h_intern(&lf[726],24, C_text("chicken.base#bwp-object\077"));
lf[727]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_bwpp"));
lf[728]=C_h_intern(&lf[728],18, C_text("scheme#eof-object\077"));
lf[729]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006C_eofp"));
lf[730]=C_h_intern(&lf[730],12, C_text("scheme#list\077"));
lf[731]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_listp"));
lf[732]=C_h_intern(&lf[732],15, C_text("scheme#inexact\077"));
lf[733]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_u_i_inexactp"));
lf[734]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_inexactp"));
lf[735]=C_h_intern(&lf[735],13, C_text("scheme#exact\077"));
lf[736]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_exactp"));
lf[737]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_exactp"));
lf[738]=C_h_intern(&lf[738],24, C_text("##sys#generic-structure\077"));
lf[739]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_structurep"));
lf[740]=C_h_intern(&lf[740],8, C_text("pointer\077"));
lf[741]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_i_safe_pointerp"));
lf[742]=C_h_intern(&lf[742],14, C_text("##sys#pointer\077"));
lf[743]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_anypointerp"));
lf[744]=C_h_intern(&lf[744],25, C_text("chicken.flonum#fpinteger\077"));
lf[745]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020C_u_i_fpintegerp"));
lf[746]=C_h_intern(&lf[746],22, C_text("chicken.base#infinite\077"));
lf[747]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_infinitep"));
lf[748]=C_h_intern(&lf[748],20, C_text("chicken.base#finite\077"));
lf[749]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_finitep"));
lf[750]=C_h_intern(&lf[750],17, C_text("chicken.base#nan\077"));
lf[751]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_nanp"));
lf[752]=C_h_intern(&lf[752],20, C_text("chicken.base#ratnum\077"));
lf[753]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_ratnump"));
lf[754]=C_h_intern(&lf[754],21, C_text("chicken.base#cplxnum\077"));
lf[755]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_cplxnump"));
lf[756]=C_h_intern(&lf[756],20, C_text("chicken.base#bignum\077"));
lf[757]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_bignump"));
lf[758]=C_h_intern(&lf[758],20, C_text("chicken.base#fixnum\077"));
lf[759]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_fixnump"));
lf[760]=C_h_intern(&lf[760],20, C_text("chicken.base#flonum\077"));
lf[761]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_flonump"));
lf[762]=C_h_intern(&lf[762],27, C_text("chicken.base#exact-integer\077"));
lf[763]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_exact_integerp"));
lf[764]=C_h_intern(&lf[764],15, C_text("scheme#integer\077"));
lf[765]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_integerp"));
lf[766]=C_h_intern(&lf[766],12, C_text("scheme#real\077"));
lf[767]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_realp"));
lf[768]=C_h_intern(&lf[768],16, C_text("scheme#rational\077"));
lf[769]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_rationalp"));
lf[770]=C_h_intern(&lf[770],15, C_text("scheme#complex\077"));
lf[771]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_numberp"));
lf[772]=C_h_intern(&lf[772],14, C_text("scheme#number\077"));
lf[773]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_numberp"));
lf[774]=C_h_intern(&lf[774],15, C_text("scheme#boolean\077"));
lf[775]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_booleanp"));
lf[776]=C_h_intern(&lf[776],18, C_text("chicken.base#port\077"));
lf[777]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_portp"));
lf[778]=C_h_intern(&lf[778],17, C_text("scheme#procedure\077"));
lf[779]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_closurep"));
lf[780]=C_h_intern(&lf[780],23, C_text("chicken.base#weak-pair\077"));
lf[781]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_weak_pairp"));
lf[782]=C_h_intern(&lf[782],11, C_text("##sys#pair\077"));
lf[783]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_pairp"));
lf[784]=C_h_intern(&lf[784],12, C_text("scheme#pair\077"));
lf[785]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_pairp"));
lf[786]=C_h_intern(&lf[786],17, C_text("srfi-4#f64vector\077"));
lf[787]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_f64vectorp"));
lf[788]=C_h_intern(&lf[788],17, C_text("srfi-4#f32vector\077"));
lf[789]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_f32vectorp"));
lf[790]=C_h_intern(&lf[790],17, C_text("srfi-4#s64vector\077"));
lf[791]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_s64vectorp"));
lf[792]=C_h_intern(&lf[792],17, C_text("srfi-4#u64vector\077"));
lf[793]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_u64vectorp"));
lf[794]=C_h_intern(&lf[794],17, C_text("srfi-4#s32vector\077"));
lf[795]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_s32vectorp"));
lf[796]=C_h_intern(&lf[796],17, C_text("srfi-4#u32vector\077"));
lf[797]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_u32vectorp"));
lf[798]=C_h_intern(&lf[798],17, C_text("srfi-4#s16vector\077"));
lf[799]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_s16vectorp"));
lf[800]=C_h_intern(&lf[800],17, C_text("srfi-4#u16vector\077"));
lf[801]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_i_u16vectorp"));
lf[802]=C_h_intern(&lf[802],16, C_text("srfi-4#s8vector\077"));
lf[803]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_s8vectorp"));
lf[804]=C_h_intern(&lf[804],16, C_text("srfi-4#u8vector\077"));
lf[805]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_u8vectorp"));
lf[806]=C_h_intern(&lf[806],20, C_text("##sys#srfi-4-vector\077"));
lf[807]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_i_srfi_4_vectorp"));
lf[808]=C_h_intern(&lf[808],13, C_text("##sys#vector\077"));
lf[809]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_vectorp"));
lf[810]=C_h_intern(&lf[810],14, C_text("scheme#vector\077"));
lf[811]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_vectorp"));
lf[812]=C_h_intern(&lf[812],14, C_text("scheme#symbol\077"));
lf[813]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_symbolp"));
lf[814]=C_h_intern(&lf[814],26, C_text("chicken.locative#locative\077"));
lf[815]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_i_locativep"));
lf[816]=C_h_intern(&lf[816],14, C_text("scheme#string\077"));
lf[817]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_i_stringp"));
lf[818]=C_h_intern(&lf[818],12, C_text("scheme#char\077"));
lf[819]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_charp"));
lf[820]=C_h_intern(&lf[820],10, C_text("scheme#not"));
lf[821]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_not"));
lf[822]=C_h_intern(&lf[822],13, C_text("scheme#length"));
lf[823]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_length"));
lf[824]=C_h_intern(&lf[824],11, C_text("##sys#null\077"));
lf[825]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_nullp"));
lf[826]=C_h_intern(&lf[826],12, C_text("scheme#null\077"));
lf[827]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_nullp"));
lf[828]=C_h_intern(&lf[828],15, C_text("scheme#list-ref"));
lf[829]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_list_ref"));
lf[830]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016C_u_i_list_ref"));
lf[831]=C_h_intern(&lf[831],10, C_text("##sys#eqv\077"));
lf[832]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_eqvp"));
lf[833]=C_h_intern(&lf[833],11, C_text("scheme#eqv\077"));
lf[834]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_eqvp"));
lf[835]=C_h_intern(&lf[835],9, C_text("##sys#eq\077"));
lf[836]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_eqp"));
lf[837]=C_h_intern(&lf[837],10, C_text("scheme#eq\077"));
lf[838]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_eqp"));
lf[839]=C_h_intern(&lf[839],10, C_text("scheme#cdr"));
lf[840]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_cdr"));
lf[841]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_u_i_cdr"));
lf[842]=C_h_intern(&lf[842],13, C_text("scheme#cddddr"));
lf[843]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_cddddr"));
lf[844]=C_h_intern(&lf[844],12, C_text("scheme#cdddr"));
lf[845]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_cdddr"));
lf[846]=C_h_intern(&lf[846],11, C_text("scheme#cddr"));
lf[847]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_cddr"));
lf[848]=C_h_intern(&lf[848],11, C_text("scheme#cdar"));
lf[849]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_cdar"));
lf[850]=C_h_intern(&lf[850],11, C_text("scheme#caar"));
lf[851]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_caar"));
lf[852]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cddddr"));
lf[853]=C_h_intern(&lf[853],13, C_text("scheme#cdddar"));
lf[854]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cdddar"));
lf[855]=C_h_intern(&lf[855],13, C_text("scheme#cddadr"));
lf[856]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cddadr"));
lf[857]=C_h_intern(&lf[857],13, C_text("scheme#cddaar"));
lf[858]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cddaar"));
lf[859]=C_h_intern(&lf[859],13, C_text("scheme#cdaddr"));
lf[860]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cdaddr"));
lf[861]=C_h_intern(&lf[861],13, C_text("scheme#cdadar"));
lf[862]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cdadar"));
lf[863]=C_h_intern(&lf[863],13, C_text("scheme#cdaadr"));
lf[864]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cdaadr"));
lf[865]=C_h_intern(&lf[865],13, C_text("scheme#cdaaar"));
lf[866]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cdaaar"));
lf[867]=C_h_intern(&lf[867],13, C_text("scheme#cadddr"));
lf[868]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cadddr"));
lf[869]=C_h_intern(&lf[869],13, C_text("scheme#caddar"));
lf[870]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_caddar"));
lf[871]=C_h_intern(&lf[871],13, C_text("scheme#cadadr"));
lf[872]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cadadr"));
lf[873]=C_h_intern(&lf[873],13, C_text("scheme#cadaar"));
lf[874]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cadaar"));
lf[875]=C_h_intern(&lf[875],13, C_text("scheme#caaddr"));
lf[876]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_caaddr"));
lf[877]=C_h_intern(&lf[877],13, C_text("scheme#caadar"));
lf[878]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_caadar"));
lf[879]=C_h_intern(&lf[879],13, C_text("scheme#caaaar"));
lf[880]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_caaaar"));
lf[881]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_cdddr"));
lf[882]=C_h_intern(&lf[882],12, C_text("scheme#cddar"));
lf[883]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_cddar"));
lf[884]=C_h_intern(&lf[884],12, C_text("scheme#cdadr"));
lf[885]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_cdadr"));
lf[886]=C_h_intern(&lf[886],12, C_text("scheme#cdaar"));
lf[887]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_cdaar"));
lf[888]=C_h_intern(&lf[888],12, C_text("scheme#caddr"));
lf[889]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_caddr"));
lf[890]=C_h_intern(&lf[890],12, C_text("scheme#cadar"));
lf[891]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_cadar"));
lf[892]=C_h_intern(&lf[892],12, C_text("scheme#caaar"));
lf[893]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_caaar"));
lf[894]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_cddr"));
lf[895]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_cdar"));
lf[896]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_caar"));
lf[897]=C_h_intern(&lf[897],39, C_text("chicken.continuation#continuation-graft"));
lf[898]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_continuation_graft"));
lf[899]=C_h_intern(&lf[899],22, C_text("##sys#call-with-values"));
lf[900]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_call_with_values"));
lf[901]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_call_with_values"));
lf[902]=C_h_intern(&lf[902],23, C_text("scheme#call-with-values"));
lf[903]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022C_call_with_values"));
lf[904]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024C_u_call_with_values"));
lf[905]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_values"));
lf[906]=C_h_intern(&lf[906],13, C_text("scheme#values"));
lf[907]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_values"));
lf[908]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_cadddr"));
lf[909]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_u_i_cadddr"));
lf[910]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_i_caddr"));
lf[911]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013C_u_i_caddr"));
lf[912]=C_h_intern(&lf[912],11, C_text("scheme#cadr"));
lf[913]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_cadr"));
lf[914]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_u_i_cadr"));
lf[915]=C_h_intern(&lf[915],9, C_text("##sys#cdr"));
lf[916]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_cdr"));
lf[917]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_u_i_cdr"));
lf[918]=C_h_intern(&lf[918],9, C_text("##sys#car"));
lf[919]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_car"));
lf[920]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_u_i_car"));
lf[921]=C_h_intern(&lf[921],10, C_text("scheme#car"));
lf[922]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_car"));
lf[923]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011C_u_i_car"));
lf[924]=C_h_intern(&lf[924],11, C_text("##sys#apply"));
lf[925]=C_h_intern(&lf[925],12, C_text("scheme#apply"));
lf[926]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\012C_i_equalp\376\377\016"));
lf[927]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\005C_eqp\376\377\016"));
lf[928]=C_h_intern(&lf[928],13, C_text("scheme#equal\077"));
lf[929]=C_h_intern(&lf[929],17, C_text("chicken.base#sub1"));
lf[930]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_fixnum_decrease"));
lf[931]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_fixnum_decrease"));
lf[932]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015C_s_a_i_minus"));
lf[933]=C_h_intern(&lf[933],17, C_text("chicken.base#add1"));
lf[934]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021C_fixnum_increase"));
lf[935]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023C_u_fixnum_increase"));
lf[936]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_s_a_i_plus"));
lf[937]=C_h_intern(&lf[937],38, C_text("chicken.compiler.support#mark-variable"));
lf[938]=C_h_intern(&lf[938],15, C_text("##compiler#pure"));
lf[939]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001##sys#slot\376\003\000\000\002\376\001\000\000\017\001##sys#block-ref\376\003\000\000\002\376\001\000\000\012\001##sys#size\376\003\000\000\002\376\001\000\000\012\001#"
"#sys#byte\376\003\000\000\002\376\001\000\000\016\001##sys#pointer\077\376\003\000\000\002\376\001\000\000\030\001##sys#generic-structure\077\376\003\000\000\002\376\001\000\000\020\001"
"##sys#immediate\077\376\003\000\000\002\376\001\000\000\021\001##sys#bytevector\077\376\003\000\000\002\376\001\000\000\013\001##sys#pair\077\376\003\000\000\002\376\001\000\000\011\001##s"
"ys#eq\077\376\003\000\000\002\376\001\000\000\013\001##sys#list\077\376\003\000\000\002\376\001\000\000\015\001##sys#vector\077\376\003\000\000\002\376\001\000\000\012\001##sys#eqv\077\376\003\000\000\002\376\001"
"\000\000\021\001##sys#get-keyword\376\003\000\000\002\376\001\000\000\012\001##sys#void\376\003\000\000\002\376\001\000\000\020\001##sys#permanent\077\376\377\016"));
lf[940]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\022\001chicken.fixnum#fx\052\376\003\000\000\002\376\001\000\000\023\001chicken.fixnum#fx\052\077\376\003\000\000\002\376\001\000\000\022\001chicken.fi"
"xnum#fx+\376\003\000\000\002\376\001\000\000\023\001chicken.fixnum#fx+\077\376\003\000\000\002\376\001\000\000\022\001chicken.fixnum#fx-\376\003\000\000\002\376\001\000\000\023\001ch"
"icken.fixnum#fx-\077\376\003\000\000\002\376\001\000\000\022\001chicken.fixnum#fx/\376\003\000\000\002\376\001\000\000\023\001chicken.fixnum#fx/\077\376\003\000\000"
"\002\376\001\000\000\022\001chicken.fixnum#fx<\376\003\000\000\002\376\001\000\000\023\001chicken.fixnum#fx<=\376\003\000\000\002\376\001\000\000\022\001chicken.fixnum"
"#fx=\376\003\000\000\002\376\001\000\000\022\001chicken.fixnum#fx>\376\003\000\000\002\376\001\000\000\023\001chicken.fixnum#fx>=\376\003\000\000\002\376\001\000\000\024\001chicke"
"n.fixnum#fxand\376\003\000\000\002\376\001\000\000\026\001chicken.fixnum#fxeven\077\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxgcd\376\003"
"\000\000\002\376\001\000\000\024\001chicken.fixnum#fxior\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxlen\376\003\000\000\002\376\001\000\000\024\001chicken.f"
"ixnum#fxmax\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxmin\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxmod\376\003\000\000\002\376\001"
"\000\000\024\001chicken.fixnum#fxneg\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxnot\376\003\000\000\002\376\001\000\000\025\001chicken.fixnum"
"#fxodd\077\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxrem\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxshl\376\003\000\000\002\376\001\000\000\024\001"
"chicken.fixnum#fxshr\376\003\000\000\002\376\001\000\000\024\001chicken.fixnum#fxxor\376\377\016"));
lf[941]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\023\001chicken.flonum#fp/\077\376\003\000\000\002\376\001\000\000\022\001chicken.flonum#fp+\376\003\000\000\002\376\001\000\000\022\001chicken.fl"
"onum#fp-\376\003\000\000\002\376\001\000\000\022\001chicken.flonum#fp\052\376\003\000\000\002\376\001\000\000\022\001chicken.flonum#fp/\376\003\000\000\002\376\001\000\000\022\001chi"
"cken.flonum#fp>\376\003\000\000\002\376\001\000\000\022\001chicken.flonum#fp<\376\003\000\000\002\376\001\000\000\022\001chicken.flonum#fp=\376\003\000\000\002\376\001"
"\000\000\023\001chicken.flonum#fp>=\376\003\000\000\002\376\001\000\000\023\001chicken.flonum#fp<=\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#f"
"pmin\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#fpmax\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#fpneg\376\003\000\000\002\376\001\000\000\024\001chi"
"cken.flonum#fpgcd\376\003\000\000\002\376\001\000\000\023\001chicken.flonum#fp\052+\376\003\000\000\002\376\001\000\000\026\001chicken.flonum#fpfloor"
"\376\003\000\000\002\376\001\000\000\030\001chicken.flonum#fpceiling\376\003\000\000\002\376\001\000\000\031\001chicken.flonum#fptruncate\376\003\000\000\002\376\001\000\000"
"\026\001chicken.flonum#fpround\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#fpsin\376\003\000\000\002\376\001\000\000\024\001chicken.flonum"
"#fpcos\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#fptan\376\003\000\000\002\376\001\000\000\025\001chicken.flonum#fpasin\376\003\000\000\002\376\001\000\000\025\001"
"chicken.flonum#fpacos\376\003\000\000\002\376\001\000\000\025\001chicken.flonum#fpatan\376\003\000\000\002\376\001\000\000\026\001chicken.flonum#f"
"patan2\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#fpexp\376\003\000\000\002\376\001\000\000\025\001chicken.flonum#fpexpt\376\003\000\000\002\376\001\000\000\024\001"
"chicken.flonum#fplog\376\003\000\000\002\376\001\000\000\025\001chicken.flonum#fpsqrt\376\003\000\000\002\376\001\000\000\024\001chicken.flonum#fp"
"abs\376\003\000\000\002\376\001\000\000\031\001chicken.flonum#fpinteger\077\376\377\016"));
lf[942]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\024\001chicken.base#bignum\077\376\003\000\000\002\376\001\000\000\025\001chicken.base#cplxnum\077\376\003\000\000\002\376\001\000\000\024\001chicke"
"n.base#fixnum\077\376\003\000\000\002\376\001\000\000\024\001chicken.base#flonum\077\376\003\000\000\002\376\001\000\000\024\001chicken.base#ratnum\077\376\003\000\000"
"\002\376\001\000\000\021\001chicken.base#add1\376\003\000\000\002\376\001\000\000\021\001chicken.base#sub1\376\003\000\000\002\376\001\000\000\021\001chicken.base#nan\077"
"\376\003\000\000\002\376\001\000\000\024\001chicken.base#finite\077\376\003\000\000\002\376\001\000\000\026\001chicken.base#infinite\077\376\003\000\000\002\376\001\000\000\023\001chick"
"en.base#gensym\376\003\000\000\002\376\001\000\000\021\001chicken.base#void\376\003\000\000\002\376\001\000\000\022\001chicken.base#print\376\003\000\000\002\376\001\000\000"
"\023\001chicken.base#print\052\376\003\000\000\002\376\001\000\000\022\001chicken.base#error\376\003\000\000\002\376\001\000\000\024\001chicken.base#call/c"
"c\376\003\000\000\002\376\001\000\000\026\001chicken.base#char-name\376\003\000\000\002\376\001\000\000\037\001chicken.base#current-error-port\376\003\000\000"
"\002\376\001\000\000\032\001chicken.base#symbol-append\376\003\000\000\002\376\001\000\000\022\001chicken.base#foldl\376\003\000\000\002\376\001\000\000\022\001chicken"
".base#foldr\376\003\000\000\002\376\001\000\000\023\001chicken.base#setter\376\003\000\000\002\376\001\000\000\037\001chicken.base#getter-with-set"
"ter\376\003\000\000\002\376\001\000\000\024\001chicken.base#equal=\077\376\003\000\000\002\376\001\000\000\033\001chicken.base#exact-integer\077\376\003\000\000\002\376\001\000"
"\000\031\001chicken.base#flush-output\376\003\000\000\002\376\001\000\000\026\001chicken.base#weak-cons\376\003\000\000\002\376\001\000\000\027\001chicken."
"base#weak-pair\077\376\003\000\000\002\376\001\000\000\030\001chicken.base#bwp-object\077\376\003\000\000\002\376\001\000\000\025\001chicken.base#identi"
"ty\376\003\000\000\002\376\001\000\000\016\001chicken.base#o\376\003\000\000\002\376\001\000\000\022\001chicken.base#atom\077\376\003\000\000\002\376\001\000\000\026\001chicken.base#"
"alist-ref\376\003\000\000\002\376\001\000\000\023\001chicken.base#rassoc\376\003\000\000\002\376\001\000\000\036\001chicken.bitwise#integer-length"
"\376\003\000\000\002\376\001\000\000\033\001chicken.bitwise#bitwise-and\376\003\000\000\002\376\001\000\000\033\001chicken.bitwise#bitwise-not\376\003\000\000"
"\002\376\001\000\000\033\001chicken.bitwise#bitwise-ior\376\003\000\000\002\376\001\000\000\033\001chicken.bitwise#bitwise-xor\376\003\000\000\002\376\001\000"
"\000 \001chicken.bitwise#arithmetic-shift\376\003\000\000\002\376\001\000\000\034\001chicken.bitwise#bit->boolean\376\003\000\000\002\376"
"\001\000\000\026\001chicken.blob#blob-size\376\003\000\000\002\376\001\000\000\023\001chicken.blob#blob=\077\376\003\000\000\002\376\001\000\000\033\001chicken.keyw"
"ord#get-keyword\376\003\000\000\002\376\001\000\000\020\001srfi-4#u8vector\077\376\003\000\000\002\376\001\000\000\020\001srfi-4#s8vector\077\376\003\000\000\002\376\001\000\000\021\001"
"srfi-4#u16vector\077\376\003\000\000\002\376\001\000\000\021\001srfi-4#s16vector\077\376\003\000\000\002\376\001\000\000\021\001srfi-4#u32vector\077\376\003\000\000\002\376\001"
"\000\000\021\001srfi-4#u64vector\077\376\003\000\000\002\376\001\000\000\021\001srfi-4#s32vector\077\376\003\000\000\002\376\001\000\000\021\001srfi-4#s64vector\077\376\003\000"
"\000\002\376\001\000\000\021\001srfi-4#f32vector\077\376\003\000\000\002\376\001\000\000\021\001srfi-4#f64vector\077\376\003\000\000\002\376\001\000\000\026\001srfi-4#u8vector-"
"length\376\003\000\000\002\376\001\000\000\026\001srfi-4#s8vector-length\376\003\000\000\002\376\001\000\000\027\001srfi-4#u16vector-length\376\003\000\000\002\376\001"
"\000\000\027\001srfi-4#s16vector-length\376\003\000\000\002\376\001\000\000\027\001srfi-4#u32vector-length\376\003\000\000\002\376\001\000\000\027\001srfi-4#u"
"64vector-length\376\003\000\000\002\376\001\000\000\027\001srfi-4#s32vector-length\376\003\000\000\002\376\001\000\000\027\001srfi-4#s64vector-len"
"gth\376\003\000\000\002\376\001\000\000\027\001srfi-4#f32vector-length\376\003\000\000\002\376\001\000\000\027\001srfi-4#f64vector-length\376\003\000\000\002\376\001\000\000"
"\023\001srfi-4#u8vector-ref\376\003\000\000\002\376\001\000\000\023\001srfi-4#s8vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-4#u16vector-r"
"ef\376\003\000\000\002\376\001\000\000\024\001srfi-4#s16vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-4#u32vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-"
"4#u64vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-4#s32vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-4#s64vector-ref\376\003\000"
"\000\002\376\001\000\000\024\001srfi-4#f32vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-4#f64vector-ref\376\003\000\000\002\376\001\000\000\024\001srfi-4#u8v"
"ector-set!\376\003\000\000\002\376\001\000\000\024\001srfi-4#s8vector-set!\376\003\000\000\002\376\001\000\000\025\001srfi-4#u16vector-set!\376\003\000\000\002\376\001"
"\000\000\025\001srfi-4#s16vector-set!\376\003\000\000\002\376\001\000\000\025\001srfi-4#u32vector-set!\376\003\000\000\002\376\001\000\000\025\001srfi-4#u64ve"
"ctor-set!\376\003\000\000\002\376\001\000\000\025\001srfi-4#s32vector-set!\376\003\000\000\002\376\001\000\000\025\001srfi-4#s64vector-set!\376\003\000\000\002\376\001"
"\000\000\025\001srfi-4#f32vector-set!\376\003\000\000\002\376\001\000\000\025\001srfi-4#f64vector-set!\376\003\000\000\002\376\001\000\000\034\001srfi-4#u8vec"
"tor->blob/shared\376\003\000\000\002\376\001\000\000\034\001srfi-4#s8vector->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#u16vect"
"or->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#s16vector->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#u32vect"
"or->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#s32vector->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#u64vect"
"or->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#s64vector->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#f32vect"
"or->blob/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#f64vector->blob/shared\376\003\000\000\002\376\001\000\000\034\001srfi-4#blob->u"
"8vector/shared\376\003\000\000\002\376\001\000\000\034\001srfi-4#blob->s8vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->u16"
"vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->s16vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->u32"
"vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->s32vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->u64"
"vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->s64vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->f32"
"vector/shared\376\003\000\000\002\376\001\000\000\035\001srfi-4#blob->f64vector/shared\376\003\000\000\002\376\001\000\000\033\001chicken.memory#u"
"8vector-ref\376\003\000\000\002\376\001\000\000\033\001chicken.memory#s8vector-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#u16ve"
"ctor-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#s16vector-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#u32vect"
"or-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#s32vector-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#u64vector"
"-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#s64vector-ref\376\003\000\000\002\376\001\000\000\034\001chicken.memory#f32vector-r"
"ef\376\003\000\000\002\376\001\000\000\034\001chicken.memory#f64vector-ref\376\003\000\000\002\376\001\000\000\035\001chicken.memory#f32vector-set"
"!\376\003\000\000\002\376\001\000\000\035\001chicken.memory#f64vector-set!\376\003\000\000\002\376\001\000\000\034\001chicken.memory#u8vector-set!"
"\376\003\000\000\002\376\001\000\000\034\001chicken.memory#s8vector-set!\376\003\000\000\002\376\001\000\000\035\001chicken.memory#u16vector-set!\376"
"\003\000\000\002\376\001\000\000\035\001chicken.memory#s16vector-set!\376\003\000\000\002\376\001\000\000\035\001chicken.memory#u32vector-set!\376"
"\003\000\000\002\376\001\000\000\035\001chicken.memory#s32vector-set!\376\003\000\000\002\376\001\000\000\035\001chicken.memory#u64vector-set!\376"
"\003\000\000\002\376\001\000\000\035\001chicken.memory#s64vector-set!\376\003\000\000\002\376\001\000\000-\001chicken.memory.representation#"
"number-of-slots\376\003\000\000\002\376\001\000\0002\001chicken.memory.representation#make-record-instance\376\003\000\000"
"\002\376\001\000\000\047\001chicken.memory.representation#block-ref\376\003\000\000\002\376\001\000\000(\001chicken.memory.represen"
"tation#block-set!\376\003\000\000\002\376\001\000\000\035\001chicken.locative#locative-ref\376\003\000\000\002\376\001\000\000\036\001chicken.loca"
"tive#locative-set!\376\003\000\000\002\376\001\000\000!\001chicken.locative#locative->object\376\003\000\000\002\376\001\000\000\032\001chicken"
".locative#locative\077\376\003\000\000\002\376\001\000\000\037\001chicken.locative#locative-index\376\003\000\000\002\376\001\000\000\027\001chicken."
"memory#pointer+\376\003\000\000\002\376\001\000\000\030\001chicken.memory#pointer=\077\376\003\000\000\002\376\001\000\000\037\001chicken.memory#addr"
"ess->pointer\376\003\000\000\002\376\001\000\000\037\001chicken.memory#pointer->address\376\003\000\000\002\376\001\000\000\036\001chicken.memory#"
"pointer->object\376\003\000\000\002\376\001\000\000\036\001chicken.memory#object->pointer\376\003\000\000\002\376\001\000\000\035\001chicken.memor"
"y#pointer-u8-ref\376\003\000\000\002\376\001\000\000\035\001chicken.memory#pointer-s8-ref\376\003\000\000\002\376\001\000\000\036\001chicken.memor"
"y#pointer-u16-ref\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointer-s16-ref\376\003\000\000\002\376\001\000\000\036\001chicken.mem"
"ory#pointer-u32-ref\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointer-s32-ref\376\003\000\000\002\376\001\000\000\036\001chicken.m"
"emory#pointer-f32-ref\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointer-f64-ref\376\003\000\000\002\376\001\000\000\036\001chicken"
".memory#pointer-u8-set!\376\003\000\000\002\376\001\000\000\036\001chicken.memory#pointer-s8-set!\376\003\000\000\002\376\001\000\000\037\001chick"
"en.memory#pointer-u16-set!\376\003\000\000\002\376\001\000\000\037\001chicken.memory#pointer-s16-set!\376\003\000\000\002\376\001\000\000\037\001c"
"hicken.memory#pointer-u32-set!\376\003\000\000\002\376\001\000\000\037\001chicken.memory#pointer-s32-set!\376\003\000\000\002\376\001\000"
"\000\037\001chicken.memory#pointer-f32-set!\376\003\000\000\002\376\001\000\000\037\001chicken.memory#pointer-f64-set!\376\003\000\000"
"\002\376\001\000\000\036\001chicken.string#substring-index\376\003\000\000\002\376\001\000\000!\001chicken.string#substring-index-c"
"i\376\003\000\000\002\376\001\000\000\032\001chicken.string#substring=\077\376\003\000\000\002\376\001\000\000\035\001chicken.string#substring-ci=\077\376\003"
"\000\000\002\376\001\000\000\026\001chicken.io#read-string\376\003\000\000\002\376\001\000\000\025\001chicken.format#format\376\003\000\000\002\376\001\000\000\025\001chicke"
"n.format#printf\376\003\000\000\002\376\001\000\000\026\001chicken.format#sprintf\376\003\000\000\002\376\001\000\000\026\001chicken.format#fprint"
"f\376\377\016"));
lf[943]=C_h_intern(&lf[943],26, C_text("chicken.base#symbol-append"));
lf[944]=C_h_intern(&lf[944],7, C_text("scheme#"));
lf[945]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001not\376\003\000\000\002\376\001\000\000\010\001boolean\077\376\003\000\000\002\376\001\000\000\005\001apply\376\003\000\000\002\376\001\000\000\036\001call-with-current-co"
"ntinuation\376\003\000\000\002\376\001\000\000\003\001eq\077\376\003\000\000\002\376\001\000\000\004\001eqv\077\376\003\000\000\002\376\001\000\000\006\001equal\077\376\003\000\000\002\376\001\000\000\005\001pair\077\376\003\000\000\002\376\001\000"
"\000\004\001cons\376\003\000\000\002\376\001\000\000\003\001car\376\003\000\000\002\376\001\000\000\003\001cdr\376\003\000\000\002\376\001\000\000\004\001caar\376\003\000\000\002\376\001\000\000\004\001cadr\376\003\000\000\002\376\001\000\000\004\001cdar"
"\376\003\000\000\002\376\001\000\000\004\001cddr\376\003\000\000\002\376\001\000\000\005\001caaar\376\003\000\000\002\376\001\000\000\005\001caadr\376\003\000\000\002\376\001\000\000\005\001cadar\376\003\000\000\002\376\001\000\000\005\001caddr\376"
"\003\000\000\002\376\001\000\000\005\001cdaar\376\003\000\000\002\376\001\000\000\005\001cdadr\376\003\000\000\002\376\001\000\000\005\001cddar\376\003\000\000\002\376\001\000\000\005\001cdddr\376\003\000\000\002\376\001\000\000\006\001caaaar"
"\376\003\000\000\002\376\001\000\000\006\001caaadr\376\003\000\000\002\376\001\000\000\006\001caadar\376\003\000\000\002\376\001\000\000\006\001caaddr\376\003\000\000\002\376\001\000\000\006\001cadaar\376\003\000\000\002\376\001\000\000\006\001c"
"adadr\376\003\000\000\002\376\001\000\000\006\001caddar\376\003\000\000\002\376\001\000\000\006\001cadddr\376\003\000\000\002\376\001\000\000\006\001cdaaar\376\003\000\000\002\376\001\000\000\006\001cdaadr\376\003\000\000\002\376\001"
"\000\000\006\001cdadar\376\003\000\000\002\376\001\000\000\006\001cdaddr\376\003\000\000\002\376\001\000\000\006\001cddaar\376\003\000\000\002\376\001\000\000\006\001cddadr\376\003\000\000\002\376\001\000\000\006\001cdddar\376\003"
"\000\000\002\376\001\000\000\006\001cddddr\376\003\000\000\002\376\001\000\000\010\001set-car!\376\003\000\000\002\376\001\000\000\010\001set-cdr!\376\003\000\000\002\376\001\000\000\005\001null\077\376\003\000\000\002\376\001\000\000\004\001"
"list\376\003\000\000\002\376\001\000\000\005\001list\077\376\003\000\000\002\376\001\000\000\006\001length\376\003\000\000\002\376\001\000\000\005\001zero\077\376\003\000\000\002\376\001\000\000\001\001\052\376\003\000\000\002\376\001\000\000\001\001-\376\003\000"
"\000\002\376\001\000\000\001\001+\376\003\000\000\002\376\001\000\000\001\001/\376\003\000\000\002\376\001\000\000\001\001-\376\003\000\000\002\376\001\000\000\001\001>\376\003\000\000\002\376\001\000\000\001\001<\376\003\000\000\002\376\001\000\000\002\001>=\376\003\000\000\002\376\001\000\000\002"
"\001<=\376\003\000\000\002\376\001\000\000\001\001=\376\003\000\000\002\376\001\000\000\023\001current-output-port\376\003\000\000\002\376\001\000\000\022\001current-input-port\376\003\000\000\002\376"
"\001\000\000\012\001write-char\376\003\000\000\002\376\001\000\000\007\001newline\376\003\000\000\002\376\001\000\000\005\001write\376\003\000\000\002\376\001\000\000\007\001display\376\003\000\000\002\376\001\000\000\006\001ap"
"pend\376\003\000\000\002\376\001\000\000\016\001symbol->string\376\003\000\000\002\376\001\000\000\010\001for-each\376\003\000\000\002\376\001\000\000\003\001map\376\003\000\000\002\376\001\000\000\005\001char\077\376\003"
"\000\000\002\376\001\000\000\015\001char->integer\376\003\000\000\002\376\001\000\000\015\001integer->char\376\003\000\000\002\376\001\000\000\013\001eof-object\077\376\003\000\000\002\376\001\000\000\015\001v"
"ector-length\376\003\000\000\002\376\001\000\000\015\001string-length\376\003\000\000\002\376\001\000\000\012\001string-ref\376\003\000\000\002\376\001\000\000\013\001string-set!\376"
"\003\000\000\002\376\001\000\000\012\001vector-ref\376\003\000\000\002\376\001\000\000\013\001vector-set!\376\003\000\000\002\376\001\000\000\006\001char=\077\376\003\000\000\002\376\001\000\000\006\001char<\077\376\003\000\000"
"\002\376\001\000\000\006\001char>\077\376\003\000\000\002\376\001\000\000\007\001char>=\077\376\003\000\000\002\376\001\000\000\007\001char<=\077\376\003\000\000\002\376\001\000\000\003\001gcd\376\003\000\000\002\376\001\000\000\003\001lcm\376\003\000"
"\000\002\376\001\000\000\007\001reverse\376\003\000\000\002\376\001\000\000\007\001symbol\077\376\003\000\000\002\376\001\000\000\016\001string->symbol\376\003\000\000\002\376\001\000\000\007\001number\077\376\003\000\000"
"\002\376\001\000\000\010\001complex\077\376\003\000\000\002\376\001\000\000\005\001real\077\376\003\000\000\002\376\001\000\000\010\001integer\077\376\003\000\000\002\376\001\000\000\011\001rational\077\376\003\000\000\002\376\001\000\000\004"
"\001odd\077\376\003\000\000\002\376\001\000\000\005\001even\077\376\003\000\000\002\376\001\000\000\011\001positive\077\376\003\000\000\002\376\001\000\000\011\001negative\077\376\003\000\000\002\376\001\000\000\006\001exact\077\376\003"
"\000\000\002\376\001\000\000\010\001inexact\077\376\003\000\000\002\376\001\000\000\003\001max\376\003\000\000\002\376\001\000\000\003\001min\376\003\000\000\002\376\001\000\000\010\001quotient\376\003\000\000\002\376\001\000\000\011\001remai"
"nder\376\003\000\000\002\376\001\000\000\006\001modulo\376\003\000\000\002\376\001\000\000\005\001floor\376\003\000\000\002\376\001\000\000\007\001ceiling\376\003\000\000\002\376\001\000\000\010\001truncate\376\003\000\000\002\376"
"\001\000\000\005\001round\376\003\000\000\002\376\001\000\000\013\001rationalize\376\003\000\000\002\376\001\000\000\016\001exact->inexact\376\003\000\000\002\376\001\000\000\016\001inexact->exa"
"ct\376\003\000\000\002\376\001\000\000\003\001exp\376\003\000\000\002\376\001\000\000\003\001log\376\003\000\000\002\376\001\000\000\003\001sin\376\003\000\000\002\376\001\000\000\004\001expt\376\003\000\000\002\376\001\000\000\004\001sqrt\376\003\000\000\002\376"
"\001\000\000\003\001cos\376\003\000\000\002\376\001\000\000\003\001tan\376\003\000\000\002\376\001\000\000\004\001asin\376\003\000\000\002\376\001\000\000\004\001acos\376\003\000\000\002\376\001\000\000\004\001atan\376\003\000\000\002\376\001\000\000\016\001nu"
"mber->string\376\003\000\000\002\376\001\000\000\016\001string->number\376\003\000\000\002\376\001\000\000\011\001char-ci=\077\376\003\000\000\002\376\001\000\000\011\001char-ci<\077\376\003\000"
"\000\002\376\001\000\000\011\001char-ci>\077\376\003\000\000\002\376\001\000\000\012\001char-ci>=\077\376\003\000\000\002\376\001\000\000\012\001char-ci<=\077\376\003\000\000\002\376\001\000\000\020\001char-alpha"
"betic\077\376\003\000\000\002\376\001\000\000\020\001char-whitespace\077\376\003\000\000\002\376\001\000\000\015\001char-numeric\077\376\003\000\000\002\376\001\000\000\020\001char-lower-c"
"ase\077\376\003\000\000\002\376\001\000\000\020\001char-upper-case\077\376\003\000\000\002\376\001\000\000\013\001char-upcase\376\003\000\000\002\376\001\000\000\015\001char-downcase\376\003\000"
"\000\002\376\001\000\000\007\001string\077\376\003\000\000\002\376\001\000\000\010\001string=\077\376\003\000\000\002\376\001\000\000\010\001string>\077\376\003\000\000\002\376\001\000\000\010\001string<\077\376\003\000\000\002\376\001\000"
"\000\011\001string>=\077\376\003\000\000\002\376\001\000\000\011\001string<=\077\376\003\000\000\002\376\001\000\000\013\001string-ci=\077\376\003\000\000\002\376\001\000\000\013\001string-ci<\077\376\003\000\000"
"\002\376\001\000\000\013\001string-ci>\077\376\003\000\000\002\376\001\000\000\014\001string-ci<=\077\376\003\000\000\002\376\001\000\000\014\001string-ci>=\077\376\003\000\000\002\376\001\000\000\015\001strin"
"g-append\376\003\000\000\002\376\001\000\000\014\001string->list\376\003\000\000\002\376\001\000\000\014\001list->string\376\003\000\000\002\376\001\000\000\007\001vector\077\376\003\000\000\002\376\001\000"
"\000\014\001vector->list\376\003\000\000\002\376\001\000\000\014\001list->vector\376\003\000\000\002\376\001\000\000\006\001string\376\003\000\000\002\376\001\000\000\004\001read\376\003\000\000\002\376\001\000\000\011"
"\001read-char\376\003\000\000\002\376\001\000\000\011\001substring\376\003\000\000\002\376\001\000\000\014\001string-fill!\376\003\000\000\002\376\001\000\000\014\001vector-copy!\376\003\000\000"
"\002\376\001\000\000\014\001vector-fill!\376\003\000\000\002\376\001\000\000\013\001make-string\376\003\000\000\002\376\001\000\000\013\001make-vector\376\003\000\000\002\376\001\000\000\017\001open-i"
"nput-file\376\003\000\000\002\376\001\000\000\020\001open-output-file\376\003\000\000\002\376\001\000\000\024\001call-with-input-file\376\003\000\000\002\376\001\000\000\025\001ca"
"ll-with-output-file\376\003\000\000\002\376\001\000\000\020\001close-input-port\376\003\000\000\002\376\001\000\000\021\001close-output-port\376\003\000\000\002\376"
"\001\000\000\006\001values\376\003\000\000\002\376\001\000\000\020\001call-with-values\376\003\000\000\002\376\001\000\000\006\001vector\376\003\000\000\002\376\001\000\000\012\001procedure\077\376\003\000\000"
"\002\376\001\000\000\004\001memq\376\003\000\000\002\376\001\000\000\004\001memv\376\003\000\000\002\376\001\000\000\006\001member\376\003\000\000\002\376\001\000\000\004\001assq\376\003\000\000\002\376\001\000\000\004\001assv\376\003\000\000\002\376\001"
"\000\000\005\001assoc\376\003\000\000\002\376\001\000\000\011\001list-tail\376\003\000\000\002\376\001\000\000\010\001list-ref\376\003\000\000\002\376\001\000\000\003\001abs\376\003\000\000\002\376\001\000\000\013\001char-re"
"ady\077\376\003\000\000\002\376\001\000\000\011\001peek-char\376\003\000\000\002\376\001\000\000\014\001list->string\376\003\000\000\002\376\001\000\000\014\001string->list\376\003\000\000\002\376\001\000\000\022"
"\001current-input-port\376\003\000\000\002\376\001\000\000\023\001current-output-port\376\003\000\000\002\376\001\000\000\012\001make-polar\376\003\000\000\002\376\001\000\000\020"
"\001make-rectangular\376\003\000\000\002\376\001\000\000\011\001real-part\376\003\000\000\002\376\001\000\000\011\001imag-part\376\003\000\000\002\376\001\000\000\004\001load\376\003\000\000\002\376\001\000"
"\000\004\001eval\376\003\000\000\002\376\001\000\000\027\001interaction-environment\376\003\000\000\002\376\001\000\000\020\001null-environment\376\003\000\000\002\376\001\000\000\031\001s"
"cheme-report-environment\376\377\016"));
lf[946]=C_h_intern(&lf[946],50, C_text("chicken.compiler.optimizer#membership-unfold-limit"));
lf[947]=C_h_intern(&lf[947],52, C_text("chicken.compiler.optimizer#membership-test-operators"));
lf[948]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376B\000\000\010C_i_memq\376B\000\000\005C_eqp\376\003\000\000\002\376\003\000\000\002\376B\000\000\012C_u_i_memq\376B\000\000\005C_eqp\376\003\000\000\002\376\003\000\000\002\376B"
"\000\000\012C_i_member\376B\000\000\012C_i_equalp\376\003\000\000\002\376\003\000\000\002\376B\000\000\010C_i_memv\376B\000\000\010C_i_eqvp\376\377\016"));
lf[949]=C_h_intern(&lf[949],45, C_text("chicken.compiler.optimizer#eq-inline-operator"));
lf[950]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005C_eqp"));
lf[951]=C_h_intern(&lf[951],54, C_text("chicken.compiler.optimizer#default-optimization-passes"));
C_register_lf2(lf,952,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1679,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[674] = {
{C_text("f_1679:c_2dplatform_2escm"),(void*)f_1679},
{C_text("f_1682:c_2dplatform_2escm"),(void*)f_1682},
{C_text("f_1685:c_2dplatform_2escm"),(void*)f_1685},
{C_text("f_1688:c_2dplatform_2escm"),(void*)f_1688},
{C_text("f_1691:c_2dplatform_2escm"),(void*)f_1691},
{C_text("f_1694:c_2dplatform_2escm"),(void*)f_1694},
{C_text("f_2129:c_2dplatform_2escm"),(void*)f_2129},
{C_text("f_2135:c_2dplatform_2escm"),(void*)f_2135},
{C_text("f_2149:c_2dplatform_2escm"),(void*)f_2149},
{C_text("f_2305:c_2dplatform_2escm"),(void*)f_2305},
{C_text("f_2314:c_2dplatform_2escm"),(void*)f_2314},
{C_text("f_2322:c_2dplatform_2escm"),(void*)f_2322},
{C_text("f_2329:c_2dplatform_2escm"),(void*)f_2329},
{C_text("f_2343:c_2dplatform_2escm"),(void*)f_2343},
{C_text("f_2471:c_2dplatform_2escm"),(void*)f_2471},
{C_text("f_2713:c_2dplatform_2escm"),(void*)f_2713},
{C_text("f_2727:c_2dplatform_2escm"),(void*)f_2727},
{C_text("f_2731:c_2dplatform_2escm"),(void*)f_2731},
{C_text("f_2975:c_2dplatform_2escm"),(void*)f_2975},
{C_text("f_2983:c_2dplatform_2escm"),(void*)f_2983},
{C_text("f_2986:c_2dplatform_2escm"),(void*)f_2986},
{C_text("f_2989:c_2dplatform_2escm"),(void*)f_2989},
{C_text("f_3004:c_2dplatform_2escm"),(void*)f_3004},
{C_text("f_3011:c_2dplatform_2escm"),(void*)f_3011},
{C_text("f_3020:c_2dplatform_2escm"),(void*)f_3020},
{C_text("f_3022:c_2dplatform_2escm"),(void*)f_3022},
{C_text("f_3024:c_2dplatform_2escm"),(void*)f_3024},
{C_text("f_3046:c_2dplatform_2escm"),(void*)f_3046},
{C_text("f_3079:c_2dplatform_2escm"),(void*)f_3079},
{C_text("f_3087:c_2dplatform_2escm"),(void*)f_3087},
{C_text("f_3090:c_2dplatform_2escm"),(void*)f_3090},
{C_text("f_3092:c_2dplatform_2escm"),(void*)f_3092},
{C_text("f_3108:c_2dplatform_2escm"),(void*)f_3108},
{C_text("f_3117:c_2dplatform_2escm"),(void*)f_3117},
{C_text("f_3120:c_2dplatform_2escm"),(void*)f_3120},
{C_text("f_3135:c_2dplatform_2escm"),(void*)f_3135},
{C_text("f_3147:c_2dplatform_2escm"),(void*)f_3147},
{C_text("f_3161:c_2dplatform_2escm"),(void*)f_3161},
{C_text("f_3165:c_2dplatform_2escm"),(void*)f_3165},
{C_text("f_3174:c_2dplatform_2escm"),(void*)f_3174},
{C_text("f_3188:c_2dplatform_2escm"),(void*)f_3188},
{C_text("f_3192:c_2dplatform_2escm"),(void*)f_3192},
{C_text("f_3222:c_2dplatform_2escm"),(void*)f_3222},
{C_text("f_3226:c_2dplatform_2escm"),(void*)f_3226},
{C_text("f_3230:c_2dplatform_2escm"),(void*)f_3230},
{C_text("f_3234:c_2dplatform_2escm"),(void*)f_3234},
{C_text("f_3238:c_2dplatform_2escm"),(void*)f_3238},
{C_text("f_3246:c_2dplatform_2escm"),(void*)f_3246},
{C_text("f_3249:c_2dplatform_2escm"),(void*)f_3249},
{C_text("f_3252:c_2dplatform_2escm"),(void*)f_3252},
{C_text("f_3254:c_2dplatform_2escm"),(void*)f_3254},
{C_text("f_3282:c_2dplatform_2escm"),(void*)f_3282},
{C_text("f_3290:c_2dplatform_2escm"),(void*)f_3290},
{C_text("f_3307:c_2dplatform_2escm"),(void*)f_3307},
{C_text("f_3309:c_2dplatform_2escm"),(void*)f_3309},
{C_text("f_3334:c_2dplatform_2escm"),(void*)f_3334},
{C_text("f_3345:c_2dplatform_2escm"),(void*)f_3345},
{C_text("f_3349:c_2dplatform_2escm"),(void*)f_3349},
{C_text("f_3352:c_2dplatform_2escm"),(void*)f_3352},
{C_text("f_3366:c_2dplatform_2escm"),(void*)f_3366},
{C_text("f_3370:c_2dplatform_2escm"),(void*)f_3370},
{C_text("f_3393:c_2dplatform_2escm"),(void*)f_3393},
{C_text("f_3408:c_2dplatform_2escm"),(void*)f_3408},
{C_text("f_3416:c_2dplatform_2escm"),(void*)f_3416},
{C_text("f_3425:c_2dplatform_2escm"),(void*)f_3425},
{C_text("f_3429:c_2dplatform_2escm"),(void*)f_3429},
{C_text("f_3432:c_2dplatform_2escm"),(void*)f_3432},
{C_text("f_3435:c_2dplatform_2escm"),(void*)f_3435},
{C_text("f_3437:c_2dplatform_2escm"),(void*)f_3437},
{C_text("f_3443:c_2dplatform_2escm"),(void*)f_3443},
{C_text("f_3455:c_2dplatform_2escm"),(void*)f_3455},
{C_text("f_3474:c_2dplatform_2escm"),(void*)f_3474},
{C_text("f_3505:c_2dplatform_2escm"),(void*)f_3505},
{C_text("f_3508:c_2dplatform_2escm"),(void*)f_3508},
{C_text("f_3511:c_2dplatform_2escm"),(void*)f_3511},
{C_text("f_3514:c_2dplatform_2escm"),(void*)f_3514},
{C_text("f_3517:c_2dplatform_2escm"),(void*)f_3517},
{C_text("f_3520:c_2dplatform_2escm"),(void*)f_3520},
{C_text("f_3521:c_2dplatform_2escm"),(void*)f_3521},
{C_text("f_3547:c_2dplatform_2escm"),(void*)f_3547},
{C_text("f_3550:c_2dplatform_2escm"),(void*)f_3550},
{C_text("f_3552:c_2dplatform_2escm"),(void*)f_3552},
{C_text("f_3586:c_2dplatform_2escm"),(void*)f_3586},
{C_text("f_3613:c_2dplatform_2escm"),(void*)f_3613},
{C_text("f_3616:c_2dplatform_2escm"),(void*)f_3616},
{C_text("f_3619:c_2dplatform_2escm"),(void*)f_3619},
{C_text("f_3634:c_2dplatform_2escm"),(void*)f_3634},
{C_text("f_3638:c_2dplatform_2escm"),(void*)f_3638},
{C_text("f_3650:c_2dplatform_2escm"),(void*)f_3650},
{C_text("f_3662:c_2dplatform_2escm"),(void*)f_3662},
{C_text("f_3674:c_2dplatform_2escm"),(void*)f_3674},
{C_text("f_3678:c_2dplatform_2escm"),(void*)f_3678},
{C_text("f_3686:c_2dplatform_2escm"),(void*)f_3686},
{C_text("f_3693:c_2dplatform_2escm"),(void*)f_3693},
{C_text("f_3697:c_2dplatform_2escm"),(void*)f_3697},
{C_text("f_3701:c_2dplatform_2escm"),(void*)f_3701},
{C_text("f_3705:c_2dplatform_2escm"),(void*)f_3705},
{C_text("f_3709:c_2dplatform_2escm"),(void*)f_3709},
{C_text("f_3717:c_2dplatform_2escm"),(void*)f_3717},
{C_text("f_3720:c_2dplatform_2escm"),(void*)f_3720},
{C_text("f_3723:c_2dplatform_2escm"),(void*)f_3723},
{C_text("f_3726:c_2dplatform_2escm"),(void*)f_3726},
{C_text("f_3729:c_2dplatform_2escm"),(void*)f_3729},
{C_text("f_3732:c_2dplatform_2escm"),(void*)f_3732},
{C_text("f_3735:c_2dplatform_2escm"),(void*)f_3735},
{C_text("f_3738:c_2dplatform_2escm"),(void*)f_3738},
{C_text("f_3741:c_2dplatform_2escm"),(void*)f_3741},
{C_text("f_3744:c_2dplatform_2escm"),(void*)f_3744},
{C_text("f_3747:c_2dplatform_2escm"),(void*)f_3747},
{C_text("f_3750:c_2dplatform_2escm"),(void*)f_3750},
{C_text("f_3753:c_2dplatform_2escm"),(void*)f_3753},
{C_text("f_3756:c_2dplatform_2escm"),(void*)f_3756},
{C_text("f_3759:c_2dplatform_2escm"),(void*)f_3759},
{C_text("f_3762:c_2dplatform_2escm"),(void*)f_3762},
{C_text("f_3765:c_2dplatform_2escm"),(void*)f_3765},
{C_text("f_3768:c_2dplatform_2escm"),(void*)f_3768},
{C_text("f_3771:c_2dplatform_2escm"),(void*)f_3771},
{C_text("f_3774:c_2dplatform_2escm"),(void*)f_3774},
{C_text("f_3777:c_2dplatform_2escm"),(void*)f_3777},
{C_text("f_3780:c_2dplatform_2escm"),(void*)f_3780},
{C_text("f_3783:c_2dplatform_2escm"),(void*)f_3783},
{C_text("f_3786:c_2dplatform_2escm"),(void*)f_3786},
{C_text("f_3789:c_2dplatform_2escm"),(void*)f_3789},
{C_text("f_3792:c_2dplatform_2escm"),(void*)f_3792},
{C_text("f_3795:c_2dplatform_2escm"),(void*)f_3795},
{C_text("f_3798:c_2dplatform_2escm"),(void*)f_3798},
{C_text("f_3801:c_2dplatform_2escm"),(void*)f_3801},
{C_text("f_3804:c_2dplatform_2escm"),(void*)f_3804},
{C_text("f_3807:c_2dplatform_2escm"),(void*)f_3807},
{C_text("f_3810:c_2dplatform_2escm"),(void*)f_3810},
{C_text("f_3813:c_2dplatform_2escm"),(void*)f_3813},
{C_text("f_3816:c_2dplatform_2escm"),(void*)f_3816},
{C_text("f_3819:c_2dplatform_2escm"),(void*)f_3819},
{C_text("f_3822:c_2dplatform_2escm"),(void*)f_3822},
{C_text("f_3825:c_2dplatform_2escm"),(void*)f_3825},
{C_text("f_3828:c_2dplatform_2escm"),(void*)f_3828},
{C_text("f_3831:c_2dplatform_2escm"),(void*)f_3831},
{C_text("f_3834:c_2dplatform_2escm"),(void*)f_3834},
{C_text("f_3837:c_2dplatform_2escm"),(void*)f_3837},
{C_text("f_3840:c_2dplatform_2escm"),(void*)f_3840},
{C_text("f_3843:c_2dplatform_2escm"),(void*)f_3843},
{C_text("f_3846:c_2dplatform_2escm"),(void*)f_3846},
{C_text("f_3849:c_2dplatform_2escm"),(void*)f_3849},
{C_text("f_3852:c_2dplatform_2escm"),(void*)f_3852},
{C_text("f_3855:c_2dplatform_2escm"),(void*)f_3855},
{C_text("f_3858:c_2dplatform_2escm"),(void*)f_3858},
{C_text("f_3861:c_2dplatform_2escm"),(void*)f_3861},
{C_text("f_3864:c_2dplatform_2escm"),(void*)f_3864},
{C_text("f_3867:c_2dplatform_2escm"),(void*)f_3867},
{C_text("f_3870:c_2dplatform_2escm"),(void*)f_3870},
{C_text("f_3873:c_2dplatform_2escm"),(void*)f_3873},
{C_text("f_3876:c_2dplatform_2escm"),(void*)f_3876},
{C_text("f_3879:c_2dplatform_2escm"),(void*)f_3879},
{C_text("f_3882:c_2dplatform_2escm"),(void*)f_3882},
{C_text("f_3885:c_2dplatform_2escm"),(void*)f_3885},
{C_text("f_3888:c_2dplatform_2escm"),(void*)f_3888},
{C_text("f_3891:c_2dplatform_2escm"),(void*)f_3891},
{C_text("f_3894:c_2dplatform_2escm"),(void*)f_3894},
{C_text("f_3897:c_2dplatform_2escm"),(void*)f_3897},
{C_text("f_3900:c_2dplatform_2escm"),(void*)f_3900},
{C_text("f_3903:c_2dplatform_2escm"),(void*)f_3903},
{C_text("f_3906:c_2dplatform_2escm"),(void*)f_3906},
{C_text("f_3909:c_2dplatform_2escm"),(void*)f_3909},
{C_text("f_3912:c_2dplatform_2escm"),(void*)f_3912},
{C_text("f_3915:c_2dplatform_2escm"),(void*)f_3915},
{C_text("f_3918:c_2dplatform_2escm"),(void*)f_3918},
{C_text("f_3921:c_2dplatform_2escm"),(void*)f_3921},
{C_text("f_3924:c_2dplatform_2escm"),(void*)f_3924},
{C_text("f_3927:c_2dplatform_2escm"),(void*)f_3927},
{C_text("f_3930:c_2dplatform_2escm"),(void*)f_3930},
{C_text("f_3933:c_2dplatform_2escm"),(void*)f_3933},
{C_text("f_3936:c_2dplatform_2escm"),(void*)f_3936},
{C_text("f_3939:c_2dplatform_2escm"),(void*)f_3939},
{C_text("f_3942:c_2dplatform_2escm"),(void*)f_3942},
{C_text("f_3945:c_2dplatform_2escm"),(void*)f_3945},
{C_text("f_3948:c_2dplatform_2escm"),(void*)f_3948},
{C_text("f_3951:c_2dplatform_2escm"),(void*)f_3951},
{C_text("f_3954:c_2dplatform_2escm"),(void*)f_3954},
{C_text("f_3957:c_2dplatform_2escm"),(void*)f_3957},
{C_text("f_3960:c_2dplatform_2escm"),(void*)f_3960},
{C_text("f_3963:c_2dplatform_2escm"),(void*)f_3963},
{C_text("f_3966:c_2dplatform_2escm"),(void*)f_3966},
{C_text("f_3969:c_2dplatform_2escm"),(void*)f_3969},
{C_text("f_3972:c_2dplatform_2escm"),(void*)f_3972},
{C_text("f_3975:c_2dplatform_2escm"),(void*)f_3975},
{C_text("f_3978:c_2dplatform_2escm"),(void*)f_3978},
{C_text("f_3981:c_2dplatform_2escm"),(void*)f_3981},
{C_text("f_3984:c_2dplatform_2escm"),(void*)f_3984},
{C_text("f_3987:c_2dplatform_2escm"),(void*)f_3987},
{C_text("f_3990:c_2dplatform_2escm"),(void*)f_3990},
{C_text("f_3993:c_2dplatform_2escm"),(void*)f_3993},
{C_text("f_3996:c_2dplatform_2escm"),(void*)f_3996},
{C_text("f_3999:c_2dplatform_2escm"),(void*)f_3999},
{C_text("f_4002:c_2dplatform_2escm"),(void*)f_4002},
{C_text("f_4005:c_2dplatform_2escm"),(void*)f_4005},
{C_text("f_4008:c_2dplatform_2escm"),(void*)f_4008},
{C_text("f_4011:c_2dplatform_2escm"),(void*)f_4011},
{C_text("f_4014:c_2dplatform_2escm"),(void*)f_4014},
{C_text("f_4017:c_2dplatform_2escm"),(void*)f_4017},
{C_text("f_4020:c_2dplatform_2escm"),(void*)f_4020},
{C_text("f_4023:c_2dplatform_2escm"),(void*)f_4023},
{C_text("f_4026:c_2dplatform_2escm"),(void*)f_4026},
{C_text("f_4029:c_2dplatform_2escm"),(void*)f_4029},
{C_text("f_4032:c_2dplatform_2escm"),(void*)f_4032},
{C_text("f_4035:c_2dplatform_2escm"),(void*)f_4035},
{C_text("f_4038:c_2dplatform_2escm"),(void*)f_4038},
{C_text("f_4041:c_2dplatform_2escm"),(void*)f_4041},
{C_text("f_4044:c_2dplatform_2escm"),(void*)f_4044},
{C_text("f_4047:c_2dplatform_2escm"),(void*)f_4047},
{C_text("f_4050:c_2dplatform_2escm"),(void*)f_4050},
{C_text("f_4053:c_2dplatform_2escm"),(void*)f_4053},
{C_text("f_4056:c_2dplatform_2escm"),(void*)f_4056},
{C_text("f_4059:c_2dplatform_2escm"),(void*)f_4059},
{C_text("f_4062:c_2dplatform_2escm"),(void*)f_4062},
{C_text("f_4065:c_2dplatform_2escm"),(void*)f_4065},
{C_text("f_4068:c_2dplatform_2escm"),(void*)f_4068},
{C_text("f_4071:c_2dplatform_2escm"),(void*)f_4071},
{C_text("f_4074:c_2dplatform_2escm"),(void*)f_4074},
{C_text("f_4077:c_2dplatform_2escm"),(void*)f_4077},
{C_text("f_4080:c_2dplatform_2escm"),(void*)f_4080},
{C_text("f_4083:c_2dplatform_2escm"),(void*)f_4083},
{C_text("f_4086:c_2dplatform_2escm"),(void*)f_4086},
{C_text("f_4089:c_2dplatform_2escm"),(void*)f_4089},
{C_text("f_4092:c_2dplatform_2escm"),(void*)f_4092},
{C_text("f_4095:c_2dplatform_2escm"),(void*)f_4095},
{C_text("f_4098:c_2dplatform_2escm"),(void*)f_4098},
{C_text("f_4101:c_2dplatform_2escm"),(void*)f_4101},
{C_text("f_4104:c_2dplatform_2escm"),(void*)f_4104},
{C_text("f_4107:c_2dplatform_2escm"),(void*)f_4107},
{C_text("f_4110:c_2dplatform_2escm"),(void*)f_4110},
{C_text("f_4113:c_2dplatform_2escm"),(void*)f_4113},
{C_text("f_4116:c_2dplatform_2escm"),(void*)f_4116},
{C_text("f_4119:c_2dplatform_2escm"),(void*)f_4119},
{C_text("f_4122:c_2dplatform_2escm"),(void*)f_4122},
{C_text("f_4125:c_2dplatform_2escm"),(void*)f_4125},
{C_text("f_4128:c_2dplatform_2escm"),(void*)f_4128},
{C_text("f_4131:c_2dplatform_2escm"),(void*)f_4131},
{C_text("f_4134:c_2dplatform_2escm"),(void*)f_4134},
{C_text("f_4137:c_2dplatform_2escm"),(void*)f_4137},
{C_text("f_4140:c_2dplatform_2escm"),(void*)f_4140},
{C_text("f_4143:c_2dplatform_2escm"),(void*)f_4143},
{C_text("f_4146:c_2dplatform_2escm"),(void*)f_4146},
{C_text("f_4149:c_2dplatform_2escm"),(void*)f_4149},
{C_text("f_4152:c_2dplatform_2escm"),(void*)f_4152},
{C_text("f_4155:c_2dplatform_2escm"),(void*)f_4155},
{C_text("f_4158:c_2dplatform_2escm"),(void*)f_4158},
{C_text("f_4161:c_2dplatform_2escm"),(void*)f_4161},
{C_text("f_4164:c_2dplatform_2escm"),(void*)f_4164},
{C_text("f_4167:c_2dplatform_2escm"),(void*)f_4167},
{C_text("f_4170:c_2dplatform_2escm"),(void*)f_4170},
{C_text("f_4173:c_2dplatform_2escm"),(void*)f_4173},
{C_text("f_4176:c_2dplatform_2escm"),(void*)f_4176},
{C_text("f_4179:c_2dplatform_2escm"),(void*)f_4179},
{C_text("f_4182:c_2dplatform_2escm"),(void*)f_4182},
{C_text("f_4185:c_2dplatform_2escm"),(void*)f_4185},
{C_text("f_4188:c_2dplatform_2escm"),(void*)f_4188},
{C_text("f_4191:c_2dplatform_2escm"),(void*)f_4191},
{C_text("f_4194:c_2dplatform_2escm"),(void*)f_4194},
{C_text("f_4197:c_2dplatform_2escm"),(void*)f_4197},
{C_text("f_4200:c_2dplatform_2escm"),(void*)f_4200},
{C_text("f_4203:c_2dplatform_2escm"),(void*)f_4203},
{C_text("f_4206:c_2dplatform_2escm"),(void*)f_4206},
{C_text("f_4209:c_2dplatform_2escm"),(void*)f_4209},
{C_text("f_4212:c_2dplatform_2escm"),(void*)f_4212},
{C_text("f_4215:c_2dplatform_2escm"),(void*)f_4215},
{C_text("f_4218:c_2dplatform_2escm"),(void*)f_4218},
{C_text("f_4221:c_2dplatform_2escm"),(void*)f_4221},
{C_text("f_4224:c_2dplatform_2escm"),(void*)f_4224},
{C_text("f_4227:c_2dplatform_2escm"),(void*)f_4227},
{C_text("f_4230:c_2dplatform_2escm"),(void*)f_4230},
{C_text("f_4233:c_2dplatform_2escm"),(void*)f_4233},
{C_text("f_4236:c_2dplatform_2escm"),(void*)f_4236},
{C_text("f_4239:c_2dplatform_2escm"),(void*)f_4239},
{C_text("f_4242:c_2dplatform_2escm"),(void*)f_4242},
{C_text("f_4245:c_2dplatform_2escm"),(void*)f_4245},
{C_text("f_4248:c_2dplatform_2escm"),(void*)f_4248},
{C_text("f_4251:c_2dplatform_2escm"),(void*)f_4251},
{C_text("f_4254:c_2dplatform_2escm"),(void*)f_4254},
{C_text("f_4257:c_2dplatform_2escm"),(void*)f_4257},
{C_text("f_4260:c_2dplatform_2escm"),(void*)f_4260},
{C_text("f_4263:c_2dplatform_2escm"),(void*)f_4263},
{C_text("f_4266:c_2dplatform_2escm"),(void*)f_4266},
{C_text("f_4269:c_2dplatform_2escm"),(void*)f_4269},
{C_text("f_4272:c_2dplatform_2escm"),(void*)f_4272},
{C_text("f_4275:c_2dplatform_2escm"),(void*)f_4275},
{C_text("f_4278:c_2dplatform_2escm"),(void*)f_4278},
{C_text("f_4281:c_2dplatform_2escm"),(void*)f_4281},
{C_text("f_4284:c_2dplatform_2escm"),(void*)f_4284},
{C_text("f_4287:c_2dplatform_2escm"),(void*)f_4287},
{C_text("f_4290:c_2dplatform_2escm"),(void*)f_4290},
{C_text("f_4293:c_2dplatform_2escm"),(void*)f_4293},
{C_text("f_4296:c_2dplatform_2escm"),(void*)f_4296},
{C_text("f_4299:c_2dplatform_2escm"),(void*)f_4299},
{C_text("f_4302:c_2dplatform_2escm"),(void*)f_4302},
{C_text("f_4305:c_2dplatform_2escm"),(void*)f_4305},
{C_text("f_4308:c_2dplatform_2escm"),(void*)f_4308},
{C_text("f_4311:c_2dplatform_2escm"),(void*)f_4311},
{C_text("f_4314:c_2dplatform_2escm"),(void*)f_4314},
{C_text("f_4317:c_2dplatform_2escm"),(void*)f_4317},
{C_text("f_4320:c_2dplatform_2escm"),(void*)f_4320},
{C_text("f_4323:c_2dplatform_2escm"),(void*)f_4323},
{C_text("f_4326:c_2dplatform_2escm"),(void*)f_4326},
{C_text("f_4329:c_2dplatform_2escm"),(void*)f_4329},
{C_text("f_4332:c_2dplatform_2escm"),(void*)f_4332},
{C_text("f_4335:c_2dplatform_2escm"),(void*)f_4335},
{C_text("f_4338:c_2dplatform_2escm"),(void*)f_4338},
{C_text("f_4341:c_2dplatform_2escm"),(void*)f_4341},
{C_text("f_4344:c_2dplatform_2escm"),(void*)f_4344},
{C_text("f_4347:c_2dplatform_2escm"),(void*)f_4347},
{C_text("f_4350:c_2dplatform_2escm"),(void*)f_4350},
{C_text("f_4353:c_2dplatform_2escm"),(void*)f_4353},
{C_text("f_4356:c_2dplatform_2escm"),(void*)f_4356},
{C_text("f_4359:c_2dplatform_2escm"),(void*)f_4359},
{C_text("f_4362:c_2dplatform_2escm"),(void*)f_4362},
{C_text("f_4365:c_2dplatform_2escm"),(void*)f_4365},
{C_text("f_4368:c_2dplatform_2escm"),(void*)f_4368},
{C_text("f_4371:c_2dplatform_2escm"),(void*)f_4371},
{C_text("f_4374:c_2dplatform_2escm"),(void*)f_4374},
{C_text("f_4377:c_2dplatform_2escm"),(void*)f_4377},
{C_text("f_4380:c_2dplatform_2escm"),(void*)f_4380},
{C_text("f_4383:c_2dplatform_2escm"),(void*)f_4383},
{C_text("f_4386:c_2dplatform_2escm"),(void*)f_4386},
{C_text("f_4389:c_2dplatform_2escm"),(void*)f_4389},
{C_text("f_4392:c_2dplatform_2escm"),(void*)f_4392},
{C_text("f_4395:c_2dplatform_2escm"),(void*)f_4395},
{C_text("f_4398:c_2dplatform_2escm"),(void*)f_4398},
{C_text("f_4401:c_2dplatform_2escm"),(void*)f_4401},
{C_text("f_4404:c_2dplatform_2escm"),(void*)f_4404},
{C_text("f_4407:c_2dplatform_2escm"),(void*)f_4407},
{C_text("f_4410:c_2dplatform_2escm"),(void*)f_4410},
{C_text("f_4413:c_2dplatform_2escm"),(void*)f_4413},
{C_text("f_4416:c_2dplatform_2escm"),(void*)f_4416},
{C_text("f_4419:c_2dplatform_2escm"),(void*)f_4419},
{C_text("f_4422:c_2dplatform_2escm"),(void*)f_4422},
{C_text("f_4425:c_2dplatform_2escm"),(void*)f_4425},
{C_text("f_4428:c_2dplatform_2escm"),(void*)f_4428},
{C_text("f_4431:c_2dplatform_2escm"),(void*)f_4431},
{C_text("f_4434:c_2dplatform_2escm"),(void*)f_4434},
{C_text("f_4437:c_2dplatform_2escm"),(void*)f_4437},
{C_text("f_4440:c_2dplatform_2escm"),(void*)f_4440},
{C_text("f_4443:c_2dplatform_2escm"),(void*)f_4443},
{C_text("f_4446:c_2dplatform_2escm"),(void*)f_4446},
{C_text("f_4449:c_2dplatform_2escm"),(void*)f_4449},
{C_text("f_4452:c_2dplatform_2escm"),(void*)f_4452},
{C_text("f_4455:c_2dplatform_2escm"),(void*)f_4455},
{C_text("f_4458:c_2dplatform_2escm"),(void*)f_4458},
{C_text("f_4460:c_2dplatform_2escm"),(void*)f_4460},
{C_text("f_4497:c_2dplatform_2escm"),(void*)f_4497},
{C_text("f_4499:c_2dplatform_2escm"),(void*)f_4499},
{C_text("f_4506:c_2dplatform_2escm"),(void*)f_4506},
{C_text("f_4517:c_2dplatform_2escm"),(void*)f_4517},
{C_text("f_4538:c_2dplatform_2escm"),(void*)f_4538},
{C_text("f_4542:c_2dplatform_2escm"),(void*)f_4542},
{C_text("f_4555:c_2dplatform_2escm"),(void*)f_4555},
{C_text("f_4557:c_2dplatform_2escm"),(void*)f_4557},
{C_text("f_4579:c_2dplatform_2escm"),(void*)f_4579},
{C_text("f_4583:c_2dplatform_2escm"),(void*)f_4583},
{C_text("f_4593:c_2dplatform_2escm"),(void*)f_4593},
{C_text("f_4596:c_2dplatform_2escm"),(void*)f_4596},
{C_text("f_4599:c_2dplatform_2escm"),(void*)f_4599},
{C_text("f_4602:c_2dplatform_2escm"),(void*)f_4602},
{C_text("f_4605:c_2dplatform_2escm"),(void*)f_4605},
{C_text("f_4608:c_2dplatform_2escm"),(void*)f_4608},
{C_text("f_4611:c_2dplatform_2escm"),(void*)f_4611},
{C_text("f_4614:c_2dplatform_2escm"),(void*)f_4614},
{C_text("f_4617:c_2dplatform_2escm"),(void*)f_4617},
{C_text("f_4620:c_2dplatform_2escm"),(void*)f_4620},
{C_text("f_4623:c_2dplatform_2escm"),(void*)f_4623},
{C_text("f_4626:c_2dplatform_2escm"),(void*)f_4626},
{C_text("f_4629:c_2dplatform_2escm"),(void*)f_4629},
{C_text("f_4632:c_2dplatform_2escm"),(void*)f_4632},
{C_text("f_4635:c_2dplatform_2escm"),(void*)f_4635},
{C_text("f_4638:c_2dplatform_2escm"),(void*)f_4638},
{C_text("f_4641:c_2dplatform_2escm"),(void*)f_4641},
{C_text("f_4644:c_2dplatform_2escm"),(void*)f_4644},
{C_text("f_4647:c_2dplatform_2escm"),(void*)f_4647},
{C_text("f_4650:c_2dplatform_2escm"),(void*)f_4650},
{C_text("f_4653:c_2dplatform_2escm"),(void*)f_4653},
{C_text("f_4656:c_2dplatform_2escm"),(void*)f_4656},
{C_text("f_4659:c_2dplatform_2escm"),(void*)f_4659},
{C_text("f_4662:c_2dplatform_2escm"),(void*)f_4662},
{C_text("f_4665:c_2dplatform_2escm"),(void*)f_4665},
{C_text("f_4668:c_2dplatform_2escm"),(void*)f_4668},
{C_text("f_4671:c_2dplatform_2escm"),(void*)f_4671},
{C_text("f_4674:c_2dplatform_2escm"),(void*)f_4674},
{C_text("f_4677:c_2dplatform_2escm"),(void*)f_4677},
{C_text("f_4680:c_2dplatform_2escm"),(void*)f_4680},
{C_text("f_4683:c_2dplatform_2escm"),(void*)f_4683},
{C_text("f_4686:c_2dplatform_2escm"),(void*)f_4686},
{C_text("f_4689:c_2dplatform_2escm"),(void*)f_4689},
{C_text("f_4692:c_2dplatform_2escm"),(void*)f_4692},
{C_text("f_4695:c_2dplatform_2escm"),(void*)f_4695},
{C_text("f_4698:c_2dplatform_2escm"),(void*)f_4698},
{C_text("f_4701:c_2dplatform_2escm"),(void*)f_4701},
{C_text("f_4704:c_2dplatform_2escm"),(void*)f_4704},
{C_text("f_4707:c_2dplatform_2escm"),(void*)f_4707},
{C_text("f_4710:c_2dplatform_2escm"),(void*)f_4710},
{C_text("f_4713:c_2dplatform_2escm"),(void*)f_4713},
{C_text("f_4716:c_2dplatform_2escm"),(void*)f_4716},
{C_text("f_4719:c_2dplatform_2escm"),(void*)f_4719},
{C_text("f_4722:c_2dplatform_2escm"),(void*)f_4722},
{C_text("f_4725:c_2dplatform_2escm"),(void*)f_4725},
{C_text("f_4728:c_2dplatform_2escm"),(void*)f_4728},
{C_text("f_4731:c_2dplatform_2escm"),(void*)f_4731},
{C_text("f_4734:c_2dplatform_2escm"),(void*)f_4734},
{C_text("f_4737:c_2dplatform_2escm"),(void*)f_4737},
{C_text("f_4740:c_2dplatform_2escm"),(void*)f_4740},
{C_text("f_4743:c_2dplatform_2escm"),(void*)f_4743},
{C_text("f_4746:c_2dplatform_2escm"),(void*)f_4746},
{C_text("f_4749:c_2dplatform_2escm"),(void*)f_4749},
{C_text("f_4752:c_2dplatform_2escm"),(void*)f_4752},
{C_text("f_4755:c_2dplatform_2escm"),(void*)f_4755},
{C_text("f_4758:c_2dplatform_2escm"),(void*)f_4758},
{C_text("f_4761:c_2dplatform_2escm"),(void*)f_4761},
{C_text("f_4764:c_2dplatform_2escm"),(void*)f_4764},
{C_text("f_4767:c_2dplatform_2escm"),(void*)f_4767},
{C_text("f_4770:c_2dplatform_2escm"),(void*)f_4770},
{C_text("f_4773:c_2dplatform_2escm"),(void*)f_4773},
{C_text("f_4776:c_2dplatform_2escm"),(void*)f_4776},
{C_text("f_4779:c_2dplatform_2escm"),(void*)f_4779},
{C_text("f_4782:c_2dplatform_2escm"),(void*)f_4782},
{C_text("f_4785:c_2dplatform_2escm"),(void*)f_4785},
{C_text("f_4788:c_2dplatform_2escm"),(void*)f_4788},
{C_text("f_4791:c_2dplatform_2escm"),(void*)f_4791},
{C_text("f_4794:c_2dplatform_2escm"),(void*)f_4794},
{C_text("f_4797:c_2dplatform_2escm"),(void*)f_4797},
{C_text("f_4800:c_2dplatform_2escm"),(void*)f_4800},
{C_text("f_4803:c_2dplatform_2escm"),(void*)f_4803},
{C_text("f_4806:c_2dplatform_2escm"),(void*)f_4806},
{C_text("f_4809:c_2dplatform_2escm"),(void*)f_4809},
{C_text("f_4812:c_2dplatform_2escm"),(void*)f_4812},
{C_text("f_4815:c_2dplatform_2escm"),(void*)f_4815},
{C_text("f_4818:c_2dplatform_2escm"),(void*)f_4818},
{C_text("f_4821:c_2dplatform_2escm"),(void*)f_4821},
{C_text("f_4824:c_2dplatform_2escm"),(void*)f_4824},
{C_text("f_4827:c_2dplatform_2escm"),(void*)f_4827},
{C_text("f_4830:c_2dplatform_2escm"),(void*)f_4830},
{C_text("f_4833:c_2dplatform_2escm"),(void*)f_4833},
{C_text("f_4836:c_2dplatform_2escm"),(void*)f_4836},
{C_text("f_4839:c_2dplatform_2escm"),(void*)f_4839},
{C_text("f_4842:c_2dplatform_2escm"),(void*)f_4842},
{C_text("f_4845:c_2dplatform_2escm"),(void*)f_4845},
{C_text("f_4848:c_2dplatform_2escm"),(void*)f_4848},
{C_text("f_4851:c_2dplatform_2escm"),(void*)f_4851},
{C_text("f_4854:c_2dplatform_2escm"),(void*)f_4854},
{C_text("f_4857:c_2dplatform_2escm"),(void*)f_4857},
{C_text("f_4860:c_2dplatform_2escm"),(void*)f_4860},
{C_text("f_4863:c_2dplatform_2escm"),(void*)f_4863},
{C_text("f_4866:c_2dplatform_2escm"),(void*)f_4866},
{C_text("f_4869:c_2dplatform_2escm"),(void*)f_4869},
{C_text("f_4872:c_2dplatform_2escm"),(void*)f_4872},
{C_text("f_4875:c_2dplatform_2escm"),(void*)f_4875},
{C_text("f_4878:c_2dplatform_2escm"),(void*)f_4878},
{C_text("f_4881:c_2dplatform_2escm"),(void*)f_4881},
{C_text("f_4884:c_2dplatform_2escm"),(void*)f_4884},
{C_text("f_4887:c_2dplatform_2escm"),(void*)f_4887},
{C_text("f_4890:c_2dplatform_2escm"),(void*)f_4890},
{C_text("f_4893:c_2dplatform_2escm"),(void*)f_4893},
{C_text("f_4896:c_2dplatform_2escm"),(void*)f_4896},
{C_text("f_4899:c_2dplatform_2escm"),(void*)f_4899},
{C_text("f_4902:c_2dplatform_2escm"),(void*)f_4902},
{C_text("f_4905:c_2dplatform_2escm"),(void*)f_4905},
{C_text("f_4908:c_2dplatform_2escm"),(void*)f_4908},
{C_text("f_4911:c_2dplatform_2escm"),(void*)f_4911},
{C_text("f_4914:c_2dplatform_2escm"),(void*)f_4914},
{C_text("f_4917:c_2dplatform_2escm"),(void*)f_4917},
{C_text("f_4920:c_2dplatform_2escm"),(void*)f_4920},
{C_text("f_4923:c_2dplatform_2escm"),(void*)f_4923},
{C_text("f_4926:c_2dplatform_2escm"),(void*)f_4926},
{C_text("f_4929:c_2dplatform_2escm"),(void*)f_4929},
{C_text("f_4932:c_2dplatform_2escm"),(void*)f_4932},
{C_text("f_4935:c_2dplatform_2escm"),(void*)f_4935},
{C_text("f_4938:c_2dplatform_2escm"),(void*)f_4938},
{C_text("f_4941:c_2dplatform_2escm"),(void*)f_4941},
{C_text("f_4944:c_2dplatform_2escm"),(void*)f_4944},
{C_text("f_4947:c_2dplatform_2escm"),(void*)f_4947},
{C_text("f_4950:c_2dplatform_2escm"),(void*)f_4950},
{C_text("f_4953:c_2dplatform_2escm"),(void*)f_4953},
{C_text("f_4956:c_2dplatform_2escm"),(void*)f_4956},
{C_text("f_4959:c_2dplatform_2escm"),(void*)f_4959},
{C_text("f_4962:c_2dplatform_2escm"),(void*)f_4962},
{C_text("f_4965:c_2dplatform_2escm"),(void*)f_4965},
{C_text("f_4968:c_2dplatform_2escm"),(void*)f_4968},
{C_text("f_4971:c_2dplatform_2escm"),(void*)f_4971},
{C_text("f_4974:c_2dplatform_2escm"),(void*)f_4974},
{C_text("f_4977:c_2dplatform_2escm"),(void*)f_4977},
{C_text("f_4980:c_2dplatform_2escm"),(void*)f_4980},
{C_text("f_4983:c_2dplatform_2escm"),(void*)f_4983},
{C_text("f_4986:c_2dplatform_2escm"),(void*)f_4986},
{C_text("f_4989:c_2dplatform_2escm"),(void*)f_4989},
{C_text("f_4992:c_2dplatform_2escm"),(void*)f_4992},
{C_text("f_4995:c_2dplatform_2escm"),(void*)f_4995},
{C_text("f_4998:c_2dplatform_2escm"),(void*)f_4998},
{C_text("f_5001:c_2dplatform_2escm"),(void*)f_5001},
{C_text("f_5004:c_2dplatform_2escm"),(void*)f_5004},
{C_text("f_5007:c_2dplatform_2escm"),(void*)f_5007},
{C_text("f_5010:c_2dplatform_2escm"),(void*)f_5010},
{C_text("f_5013:c_2dplatform_2escm"),(void*)f_5013},
{C_text("f_5016:c_2dplatform_2escm"),(void*)f_5016},
{C_text("f_5019:c_2dplatform_2escm"),(void*)f_5019},
{C_text("f_5022:c_2dplatform_2escm"),(void*)f_5022},
{C_text("f_5025:c_2dplatform_2escm"),(void*)f_5025},
{C_text("f_5028:c_2dplatform_2escm"),(void*)f_5028},
{C_text("f_5031:c_2dplatform_2escm"),(void*)f_5031},
{C_text("f_5034:c_2dplatform_2escm"),(void*)f_5034},
{C_text("f_5037:c_2dplatform_2escm"),(void*)f_5037},
{C_text("f_5040:c_2dplatform_2escm"),(void*)f_5040},
{C_text("f_5043:c_2dplatform_2escm"),(void*)f_5043},
{C_text("f_5046:c_2dplatform_2escm"),(void*)f_5046},
{C_text("f_5049:c_2dplatform_2escm"),(void*)f_5049},
{C_text("f_5052:c_2dplatform_2escm"),(void*)f_5052},
{C_text("f_5055:c_2dplatform_2escm"),(void*)f_5055},
{C_text("f_5058:c_2dplatform_2escm"),(void*)f_5058},
{C_text("f_5061:c_2dplatform_2escm"),(void*)f_5061},
{C_text("f_5064:c_2dplatform_2escm"),(void*)f_5064},
{C_text("f_5067:c_2dplatform_2escm"),(void*)f_5067},
{C_text("f_5070:c_2dplatform_2escm"),(void*)f_5070},
{C_text("f_5073:c_2dplatform_2escm"),(void*)f_5073},
{C_text("f_5076:c_2dplatform_2escm"),(void*)f_5076},
{C_text("f_5079:c_2dplatform_2escm"),(void*)f_5079},
{C_text("f_5082:c_2dplatform_2escm"),(void*)f_5082},
{C_text("f_5085:c_2dplatform_2escm"),(void*)f_5085},
{C_text("f_5088:c_2dplatform_2escm"),(void*)f_5088},
{C_text("f_5091:c_2dplatform_2escm"),(void*)f_5091},
{C_text("f_5094:c_2dplatform_2escm"),(void*)f_5094},
{C_text("f_5097:c_2dplatform_2escm"),(void*)f_5097},
{C_text("f_5100:c_2dplatform_2escm"),(void*)f_5100},
{C_text("f_5103:c_2dplatform_2escm"),(void*)f_5103},
{C_text("f_5106:c_2dplatform_2escm"),(void*)f_5106},
{C_text("f_5109:c_2dplatform_2escm"),(void*)f_5109},
{C_text("f_5112:c_2dplatform_2escm"),(void*)f_5112},
{C_text("f_5115:c_2dplatform_2escm"),(void*)f_5115},
{C_text("f_5118:c_2dplatform_2escm"),(void*)f_5118},
{C_text("f_5121:c_2dplatform_2escm"),(void*)f_5121},
{C_text("f_5124:c_2dplatform_2escm"),(void*)f_5124},
{C_text("f_5127:c_2dplatform_2escm"),(void*)f_5127},
{C_text("f_5130:c_2dplatform_2escm"),(void*)f_5130},
{C_text("f_5133:c_2dplatform_2escm"),(void*)f_5133},
{C_text("f_5136:c_2dplatform_2escm"),(void*)f_5136},
{C_text("f_5139:c_2dplatform_2escm"),(void*)f_5139},
{C_text("f_5142:c_2dplatform_2escm"),(void*)f_5142},
{C_text("f_5145:c_2dplatform_2escm"),(void*)f_5145},
{C_text("f_5148:c_2dplatform_2escm"),(void*)f_5148},
{C_text("f_5151:c_2dplatform_2escm"),(void*)f_5151},
{C_text("f_5154:c_2dplatform_2escm"),(void*)f_5154},
{C_text("f_5157:c_2dplatform_2escm"),(void*)f_5157},
{C_text("f_5160:c_2dplatform_2escm"),(void*)f_5160},
{C_text("f_5163:c_2dplatform_2escm"),(void*)f_5163},
{C_text("f_5166:c_2dplatform_2escm"),(void*)f_5166},
{C_text("f_5169:c_2dplatform_2escm"),(void*)f_5169},
{C_text("f_5172:c_2dplatform_2escm"),(void*)f_5172},
{C_text("f_5174:c_2dplatform_2escm"),(void*)f_5174},
{C_text("f_5196:c_2dplatform_2escm"),(void*)f_5196},
{C_text("f_5211:c_2dplatform_2escm"),(void*)f_5211},
{C_text("f_5214:c_2dplatform_2escm"),(void*)f_5214},
{C_text("f_5229:c_2dplatform_2escm"),(void*)f_5229},
{C_text("f_5241:c_2dplatform_2escm"),(void*)f_5241},
{C_text("f_5249:c_2dplatform_2escm"),(void*)f_5249},
{C_text("f_5251:c_2dplatform_2escm"),(void*)f_5251},
{C_text("f_5272:c_2dplatform_2escm"),(void*)f_5272},
{C_text("f_5276:c_2dplatform_2escm"),(void*)f_5276},
{C_text("f_5279:c_2dplatform_2escm"),(void*)f_5279},
{C_text("f_5282:c_2dplatform_2escm"),(void*)f_5282},
{C_text("f_5284:c_2dplatform_2escm"),(void*)f_5284},
{C_text("f_5303:c_2dplatform_2escm"),(void*)f_5303},
{C_text("f_5320:c_2dplatform_2escm"),(void*)f_5320},
{C_text("f_5363:c_2dplatform_2escm"),(void*)f_5363},
{C_text("f_5367:c_2dplatform_2escm"),(void*)f_5367},
{C_text("f_5371:c_2dplatform_2escm"),(void*)f_5371},
{C_text("f_5375:c_2dplatform_2escm"),(void*)f_5375},
{C_text("f_5382:c_2dplatform_2escm"),(void*)f_5382},
{C_text("f_5386:c_2dplatform_2escm"),(void*)f_5386},
{C_text("f_5394:c_2dplatform_2escm"),(void*)f_5394},
{C_text("f_5398:c_2dplatform_2escm"),(void*)f_5398},
{C_text("f_5406:c_2dplatform_2escm"),(void*)f_5406},
{C_text("f_5409:c_2dplatform_2escm"),(void*)f_5409},
{C_text("f_5413:c_2dplatform_2escm"),(void*)f_5413},
{C_text("f_5416:c_2dplatform_2escm"),(void*)f_5416},
{C_text("f_5419:c_2dplatform_2escm"),(void*)f_5419},
{C_text("f_5422:c_2dplatform_2escm"),(void*)f_5422},
{C_text("f_5425:c_2dplatform_2escm"),(void*)f_5425},
{C_text("f_5428:c_2dplatform_2escm"),(void*)f_5428},
{C_text("f_5431:c_2dplatform_2escm"),(void*)f_5431},
{C_text("f_5434:c_2dplatform_2escm"),(void*)f_5434},
{C_text("f_5437:c_2dplatform_2escm"),(void*)f_5437},
{C_text("f_5440:c_2dplatform_2escm"),(void*)f_5440},
{C_text("f_5443:c_2dplatform_2escm"),(void*)f_5443},
{C_text("f_5446:c_2dplatform_2escm"),(void*)f_5446},
{C_text("f_5449:c_2dplatform_2escm"),(void*)f_5449},
{C_text("f_5452:c_2dplatform_2escm"),(void*)f_5452},
{C_text("f_5455:c_2dplatform_2escm"),(void*)f_5455},
{C_text("f_5458:c_2dplatform_2escm"),(void*)f_5458},
{C_text("f_5460:c_2dplatform_2escm"),(void*)f_5460},
{C_text("f_5482:c_2dplatform_2escm"),(void*)f_5482},
{C_text("f_5500:c_2dplatform_2escm"),(void*)f_5500},
{C_text("f_5522:c_2dplatform_2escm"),(void*)f_5522},
{C_text("f_5540:c_2dplatform_2escm"),(void*)f_5540},
{C_text("f_5565:c_2dplatform_2escm"),(void*)f_5565},
{C_text("f_5586:c_2dplatform_2escm"),(void*)f_5586},
{C_text("f_5594:c_2dplatform_2escm"),(void*)f_5594},
{C_text("f_5598:c_2dplatform_2escm"),(void*)f_5598},
{C_text("f_5605:c_2dplatform_2escm"),(void*)f_5605},
{C_text("f_5633:c_2dplatform_2escm"),(void*)f_5633},
{C_text("f_5636:c_2dplatform_2escm"),(void*)f_5636},
{C_text("f_5667:c_2dplatform_2escm"),(void*)f_5667},
{C_text("f_5689:c_2dplatform_2escm"),(void*)f_5689},
{C_text("f_5712:c_2dplatform_2escm"),(void*)f_5712},
{C_text("f_5716:c_2dplatform_2escm"),(void*)f_5716},
{C_text("f_5720:c_2dplatform_2escm"),(void*)f_5720},
{C_text("f_5727:c_2dplatform_2escm"),(void*)f_5727},
{C_text("f_5749:c_2dplatform_2escm"),(void*)f_5749},
{C_text("f_5759:c_2dplatform_2escm"),(void*)f_5759},
{C_text("f_5773:c_2dplatform_2escm"),(void*)f_5773},
{C_text("f_5777:c_2dplatform_2escm"),(void*)f_5777},
{C_text("f_5784:c_2dplatform_2escm"),(void*)f_5784},
{C_text("f_5815:c_2dplatform_2escm"),(void*)f_5815},
{C_text("f_5818:c_2dplatform_2escm"),(void*)f_5818},
{C_text("f_5833:c_2dplatform_2escm"),(void*)f_5833},
{C_text("f_5850:c_2dplatform_2escm"),(void*)f_5850},
{C_text("f_5854:c_2dplatform_2escm"),(void*)f_5854},
{C_text("f_5861:c_2dplatform_2escm"),(void*)f_5861},
{C_text("f_5892:c_2dplatform_2escm"),(void*)f_5892},
{C_text("f_5920:c_2dplatform_2escm"),(void*)f_5920},
{C_text("f_5922:c_2dplatform_2escm"),(void*)f_5922},
{C_text("f_5945:c_2dplatform_2escm"),(void*)f_5945},
{C_text("f_5947:c_2dplatform_2escm"),(void*)f_5947},
{C_text("f_5966:c_2dplatform_2escm"),(void*)f_5966},
{C_text("f_5970:c_2dplatform_2escm"),(void*)f_5970},
{C_text("f_5985:c_2dplatform_2escm"),(void*)f_5985},
{C_text("f_6016:c_2dplatform_2escm"),(void*)f_6016},
{C_text("f_6044:c_2dplatform_2escm"),(void*)f_6044},
{C_text("f_6046:c_2dplatform_2escm"),(void*)f_6046},
{C_text("f_6069:c_2dplatform_2escm"),(void*)f_6069},
{C_text("f_6071:c_2dplatform_2escm"),(void*)f_6071},
{C_text("f_6090:c_2dplatform_2escm"),(void*)f_6090},
{C_text("f_6094:c_2dplatform_2escm"),(void*)f_6094},
{C_text("f_6109:c_2dplatform_2escm"),(void*)f_6109},
{C_text("f_6113:c_2dplatform_2escm"),(void*)f_6113},
{C_text("f_6134:c_2dplatform_2escm"),(void*)f_6134},
{C_text("f_6176:c_2dplatform_2escm"),(void*)f_6176},
{C_text("f_6178:c_2dplatform_2escm"),(void*)f_6178},
{C_text("f_6185:c_2dplatform_2escm"),(void*)f_6185},
{C_text("f_6196:c_2dplatform_2escm"),(void*)f_6196},
{C_text("f_6217:c_2dplatform_2escm"),(void*)f_6217},
{C_text("f_6221:c_2dplatform_2escm"),(void*)f_6221},
{C_text("f_6227:c_2dplatform_2escm"),(void*)f_6227},
{C_text("f_6249:c_2dplatform_2escm"),(void*)f_6249},
{C_text("f_6253:c_2dplatform_2escm"),(void*)f_6253},
{C_text("f_6255:c_2dplatform_2escm"),(void*)f_6255},
{C_text("f_6271:c_2dplatform_2escm"),(void*)f_6271},
{C_text("f_6277:c_2dplatform_2escm"),(void*)f_6277},
{C_text("f_6295:c_2dplatform_2escm"),(void*)f_6295},
{C_text("f_6298:c_2dplatform_2escm"),(void*)f_6298},
{C_text("f_6301:c_2dplatform_2escm"),(void*)f_6301},
{C_text("f_6316:c_2dplatform_2escm"),(void*)f_6316},
{C_text("f_6328:c_2dplatform_2escm"),(void*)f_6328},
{C_text("f_6338:c_2dplatform_2escm"),(void*)f_6338},
{C_text("f_6342:c_2dplatform_2escm"),(void*)f_6342},
{C_text("f_6351:c_2dplatform_2escm"),(void*)f_6351},
{C_text("f_6361:c_2dplatform_2escm"),(void*)f_6361},
{C_text("f_6365:c_2dplatform_2escm"),(void*)f_6365},
{C_text("f_6395:c_2dplatform_2escm"),(void*)f_6395},
{C_text("f_6399:c_2dplatform_2escm"),(void*)f_6399},
{C_text("f_6403:c_2dplatform_2escm"),(void*)f_6403},
{C_text("f_6407:c_2dplatform_2escm"),(void*)f_6407},
{C_text("f_6411:c_2dplatform_2escm"),(void*)f_6411},
{C_text("f_6420:c_2dplatform_2escm"),(void*)f_6420},
{C_text("f_6424:c_2dplatform_2escm"),(void*)f_6424},
{C_text("f_6426:c_2dplatform_2escm"),(void*)f_6426},
{C_text("f_6436:c_2dplatform_2escm"),(void*)f_6436},
{C_text("f_6449:c_2dplatform_2escm"),(void*)f_6449},
{C_text("f_6474:c_2dplatform_2escm"),(void*)f_6474},
{C_text("toplevel:c_2dplatform_2escm"),(void*)C_c_2dplatform_toplevel},
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
o|hiding unexported module binding: chicken.compiler.c-platform#partition 
o|hiding unexported module binding: chicken.compiler.c-platform#span 
o|hiding unexported module binding: chicken.compiler.c-platform#take 
o|hiding unexported module binding: chicken.compiler.c-platform#drop 
o|hiding unexported module binding: chicken.compiler.c-platform#split-at 
o|hiding unexported module binding: chicken.compiler.c-platform#append-map 
o|hiding unexported module binding: chicken.compiler.c-platform#every 
o|hiding unexported module binding: chicken.compiler.c-platform#any 
o|hiding unexported module binding: chicken.compiler.c-platform#cons* 
o|hiding unexported module binding: chicken.compiler.c-platform#concatenate 
o|hiding unexported module binding: chicken.compiler.c-platform#delete 
o|hiding unexported module binding: chicken.compiler.c-platform#first 
o|hiding unexported module binding: chicken.compiler.c-platform#second 
o|hiding unexported module binding: chicken.compiler.c-platform#third 
o|hiding unexported module binding: chicken.compiler.c-platform#fourth 
o|hiding unexported module binding: chicken.compiler.c-platform#fifth 
o|hiding unexported module binding: chicken.compiler.c-platform#delete-duplicates 
o|hiding unexported module binding: chicken.compiler.c-platform#alist-cons 
o|hiding unexported module binding: chicken.compiler.c-platform#filter 
o|hiding unexported module binding: chicken.compiler.c-platform#filter-map 
o|hiding unexported module binding: chicken.compiler.c-platform#remove 
o|hiding unexported module binding: chicken.compiler.c-platform#unzip1 
o|hiding unexported module binding: chicken.compiler.c-platform#last 
o|hiding unexported module binding: chicken.compiler.c-platform#list-index 
o|hiding unexported module binding: chicken.compiler.c-platform#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.compiler.c-platform#lset-difference/eq? 
o|hiding unexported module binding: chicken.compiler.c-platform#lset-union/eq? 
o|hiding unexported module binding: chicken.compiler.c-platform#lset-intersection/eq? 
o|hiding unexported module binding: chicken.compiler.c-platform#list-tabulate 
o|hiding unexported module binding: chicken.compiler.c-platform#lset<=/eq? 
o|hiding unexported module binding: chicken.compiler.c-platform#lset=/eq? 
o|hiding unexported module binding: chicken.compiler.c-platform#length+ 
o|hiding unexported module binding: chicken.compiler.c-platform#find 
o|hiding unexported module binding: chicken.compiler.c-platform#find-tail 
o|hiding unexported module binding: chicken.compiler.c-platform#iota 
o|hiding unexported module binding: chicken.compiler.c-platform#make-list 
o|hiding unexported module binding: chicken.compiler.c-platform#posq 
o|hiding unexported module binding: chicken.compiler.c-platform#posv 
o|hiding unexported module binding: chicken.compiler.c-platform#min-words-per-bignum 
o|hiding unexported module binding: chicken.compiler.c-platform#constant584 
o|hiding unexported module binding: chicken.compiler.c-platform#constant588 
o|hiding unexported module binding: chicken.compiler.c-platform#constant592 
o|hiding unexported module binding: chicken.compiler.c-platform#setter-map 
S|applied compiler syntax:
S|  scheme#for-each		1
S|  chicken.base#foldl		3
S|  scheme#map		5
S|  chicken.base#foldr		3
o|eliminated procedure checks: 34 
o|specializations:
o|  1 (chicken.base#add1 fixnum)
o|  1 (scheme#- *)
o|  1 (scheme#negative? *)
o|  4 (scheme#>= fixnum fixnum)
o|  2 (scheme#zero? *)
o|  1 (scheme#length list)
o|  1 (scheme#memq * list)
o|  15 (scheme#= fixnum fixnum)
o|  1 (scheme#eqv? * *)
o|  5 (##sys#check-list (or pair list) *)
o|  26 (scheme#cdr pair)
o|  10 (scheme#car pair)
(o e)|safe calls: 461 
(o e)|assignments to immediate values: 2 
o|safe globals: (chicken.compiler.c-platform#posv chicken.compiler.c-platform#posq chicken.compiler.c-platform#make-list chicken.compiler.c-platform#iota chicken.compiler.c-platform#find-tail chicken.compiler.c-platform#find chicken.compiler.c-platform#length+ chicken.compiler.c-platform#lset=/eq? chicken.compiler.c-platform#lset<=/eq? chicken.compiler.c-platform#list-tabulate chicken.compiler.c-platform#lset-intersection/eq? chicken.compiler.c-platform#lset-union/eq? chicken.compiler.c-platform#lset-difference/eq? chicken.compiler.c-platform#lset-adjoin/eq? chicken.compiler.c-platform#list-index chicken.compiler.c-platform#last chicken.compiler.c-platform#unzip1 chicken.compiler.c-platform#remove chicken.compiler.c-platform#filter-map chicken.compiler.c-platform#filter chicken.compiler.c-platform#alist-cons chicken.compiler.c-platform#delete-duplicates chicken.compiler.c-platform#fifth chicken.compiler.c-platform#fourth chicken.compiler.c-platform#third chicken.compiler.c-platform#second chicken.compiler.c-platform#first chicken.compiler.c-platform#delete chicken.compiler.c-platform#concatenate chicken.compiler.c-platform#cons* chicken.compiler.c-platform#any chicken.compiler.c-platform#every chicken.compiler.c-platform#append-map chicken.compiler.c-platform#split-at chicken.compiler.c-platform#drop chicken.compiler.c-platform#take chicken.compiler.c-platform#span chicken.compiler.c-platform#partition) 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#partition 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#span 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#drop 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#split-at 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#append-map 
o|inlining procedure: k2076 
o|inlining procedure: k2076 
o|inlining procedure: k2107 
o|inlining procedure: k2107 
o|merged explicitly consed rest parameter: xs209 
o|inlining procedure: k2137 
o|inlining procedure: k2137 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#concatenate 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#fourth 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#fifth 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#delete-duplicates 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#alist-cons 
o|inlining procedure: k2324 
o|inlining procedure: k2324 
o|inlining procedure: k2316 
o|inlining procedure: k2316 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#filter-map 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#remove 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#unzip1 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#list-index 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#lset-intersection/eq? 
o|inlining procedure: k2715 
o|inlining procedure: k2715 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#length+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#find 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#find-tail 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#iota 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#make-list 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#posq 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#posv 
o|inlining procedure: k3026 
o|inlining procedure: k3044 
o|inlining procedure: k3058 
o|inlining procedure: k3058 
o|inlining procedure: k3044 
o|inlining procedure: k3026 
o|substituted constant variable: a3084 
o|inlining procedure: k3094 
o|inlining procedure: k3112 
o|inlining procedure: k3112 
o|inlining procedure: k3136 
o|inlining procedure: "(c-platform.scm:339) chicken.compiler.c-platform#first" 
o|inlining procedure: k3136 
o|inlining procedure: k3175 
o|inlining procedure: k3175 
o|inlining procedure: "(c-platform.scm:336) chicken.compiler.c-platform#first" 
o|inlining procedure: k3196 
o|inlining procedure: k3196 
o|inlining procedure: "(c-platform.scm:330) chicken.compiler.c-platform#second" 
o|inlining procedure: "(c-platform.scm:329) chicken.compiler.c-platform#first" 
o|inlining procedure: k3094 
o|substituted constant variable: a3243 
o|inlining procedure: k3256 
o|consed rest parameter at call site: "(c-platform.scm:385) chicken.compiler.c-platform#cons*" 2 
o|inlining procedure: k3311 
o|inlining procedure: k3311 
o|inlining procedure: "(c-platform.scm:387) chicken.compiler.c-platform#first" 
o|inlining procedure: "(c-platform.scm:385) chicken.compiler.c-platform#first" 
o|inlining procedure: k3353 
o|inlining procedure: k3353 
o|consed rest parameter at call site: "(c-platform.scm:400) chicken.compiler.c-platform#cons*" 2 
o|inlining procedure: k3374 
o|substituted constant variable: a3387 
o|inlining procedure: k3388 
o|inlining procedure: k3388 
o|inlining procedure: k3374 
o|substituted constant variable: a3417 
o|contracted procedure: "(c-platform.scm:380) chicken.compiler.c-platform#last" 
o|inlining procedure: k2473 
o|inlining procedure: k2473 
o|inlining procedure: k3256 
o|inlining procedure: k3445 
o|inlining procedure: k3472 
o|inlining procedure: k3472 
o|inlining procedure: "(c-platform.scm:415) chicken.compiler.c-platform#first" 
o|inlining procedure: k3445 
o|substituted constant variable: a3502 
o|inlining procedure: k3523 
o|inlining procedure: k3523 
o|substituted constant variable: a3544 
o|inlining procedure: k3554 
o|inlining procedure: k3572 
o|inlining procedure: k3587 
o|inlining procedure: k3599 
o|substituted constant variable: a3687 
o|inlining procedure: k3599 
o|inlining procedure: "(c-platform.scm:451) chicken.compiler.c-platform#third" 
o|inlining procedure: k3587 
o|inlining procedure: k3572 
o|inlining procedure: k3554 
o|substituted constant variable: a3710 
o|inlining procedure: k4462 
o|inlining procedure: k4477 
o|inlining procedure: k4501 
o|inlining procedure: k4501 
o|inlining procedure: "(c-platform.scm:861) chicken.compiler.c-platform#first" 
o|inlining procedure: k4477 
o|substituted constant variable: a4547 
o|inlining procedure: k4563 
o|inlining procedure: "(c-platform.scm:852) chicken.compiler.c-platform#first" 
o|inlining procedure: k4563 
o|substituted constant variable: a4590 
o|inlining procedure: k4462 
o|inlining procedure: k5179 
o|inlining procedure: k5200 
o|inlining procedure: "(c-platform.scm:1168) chicken.compiler.c-platform#second" 
o|inlining procedure: k5200 
o|inlining procedure: "(c-platform.scm:1164) chicken.compiler.c-platform#first" 
o|inlining procedure: "(c-platform.scm:1161) chicken.compiler.c-platform#first" 
o|inlining procedure: k5179 
o|inlining procedure: k5286 
o|inlining procedure: k5304 
o|inlining procedure: k5322 
o|inlining procedure: k5337 
o|inlining procedure: k5337 
o|inlining procedure: "(c-platform.scm:1197) chicken.compiler.c-platform#second" 
o|inlining procedure: k5322 
o|inlining procedure: "(c-platform.scm:1192) chicken.compiler.c-platform#third" 
o|inlining procedure: k5304 
o|inlining procedure: "(c-platform.scm:1190) chicken.compiler.c-platform#first" 
o|inlining procedure: "(c-platform.scm:1188) chicken.compiler.c-platform#first" 
o|inlining procedure: k5286 
o|substituted constant variable: a5399 
o|inlining procedure: k5462 
o|inlining procedure: k5488 
o|inlining procedure: k5488 
o|inlining procedure: k5462 
o|substituted constant variable: a5494 
o|inlining procedure: k5502 
o|inlining procedure: k5528 
o|inlining procedure: k5528 
o|inlining procedure: k5502 
o|substituted constant variable: a5534 
o|inlining procedure: k5542 
o|inlining procedure: k5560 
o|substituted constant variable: chicken.compiler.c-platform#setter-map 
o|inlining procedure: k5560 
o|inlining procedure: k5542 
o|substituted constant variable: a5599 
o|substituted constant variable: chicken.compiler.c-platform#min-words-per-bignum 
o|substituted constant variable: chicken.compiler.c-platform#min-words-per-bignum 
o|inlining procedure: k5607 
o|inlining procedure: k5634 
o|inlining procedure: k5634 
o|inlining procedure: k5656 
o|inlining procedure: k5668 
o|inlining procedure: "(c-platform.scm:1042) chicken.compiler.c-platform#first" 
o|inlining procedure: "(c-platform.scm:1045) chicken.compiler.c-platform#first" 
o|inlining procedure: k5668 
o|inlining procedure: "(c-platform.scm:1037) chicken.compiler.c-platform#first" 
o|inlining procedure: k5656 
o|inlining procedure: "(c-platform.scm:1031) chicken.compiler.c-platform#second" 
o|inlining procedure: k5607 
o|substituted constant variable: a5721 
o|inlining procedure: k5729 
o|inlining procedure: k5754 
o|inlining procedure: k5754 
o|inlining procedure: "(c-platform.scm:1002) chicken.compiler.c-platform#first" 
o|inlining procedure: "(c-platform.scm:1000) chicken.compiler.c-platform#third" 
o|inlining procedure: k5729 
o|substituted constant variable: a5782 
o|substituted constant variable: chicken.compiler.c-platform#min-words-per-bignum 
o|substituted constant variable: chicken.compiler.c-platform#min-words-per-bignum 
o|inlining procedure: k5786 
o|inlining procedure: k5813 
o|inlining procedure: "(c-platform.scm:883) chicken.compiler.c-platform#first" 
o|inlining procedure: k5813 
o|inlining procedure: "(c-platform.scm:880) chicken.compiler.c-platform#first" 
o|inlining procedure: "(c-platform.scm:877) chicken.compiler.c-platform#second" 
o|substituted constant variable: a5859 
o|inlining procedure: k5786 
o|inlining procedure: k5863 
o|inlining procedure: k5863 
o|inlining procedure: k5894 
o|inlining procedure: k5894 
o|inlining procedure: k5900 
o|inlining procedure: k5900 
o|substituted constant variable: a5939 
o|inlining procedure: k5953 
o|inlining procedure: "(c-platform.scm:826) chicken.compiler.c-platform#first" 
o|inlining procedure: k5953 
o|inlining procedure: k5987 
o|inlining procedure: k5987 
o|inlining procedure: k6018 
o|inlining procedure: k6018 
o|inlining procedure: k6024 
o|inlining procedure: k6024 
o|substituted constant variable: a6063 
o|inlining procedure: k6077 
o|inlining procedure: "(c-platform.scm:789) chicken.compiler.c-platform#first" 
o|inlining procedure: k6077 
o|inlining procedure: k6114 
o|inlining procedure: k6114 
o|inlining procedure: "(c-platform.scm:753) chicken.compiler.c-platform#first" 
o|inlining procedure: k6156 
o|inlining procedure: k6180 
o|inlining procedure: k6180 
o|inlining procedure: "(c-platform.scm:761) chicken.compiler.c-platform#first" 
o|inlining procedure: k6156 
o|inlining procedure: k6233 
o|inlining procedure: "(c-platform.scm:749) chicken.compiler.c-platform#first" 
o|inlining procedure: k6233 
o|inlining procedure: k6257 
o|inlining procedure: k6278 
o|inlining procedure: k6278 
o|inlining procedure: k6317 
o|inlining procedure: "(c-platform.scm:364) chicken.compiler.c-platform#first" 
o|inlining procedure: k6317 
o|inlining procedure: k6352 
o|inlining procedure: k6352 
o|inlining procedure: "(c-platform.scm:361) chicken.compiler.c-platform#first" 
o|inlining procedure: k6369 
o|inlining procedure: k6369 
o|inlining procedure: "(c-platform.scm:355) chicken.compiler.c-platform#second" 
o|inlining procedure: "(c-platform.scm:354) chicken.compiler.c-platform#first" 
o|inlining procedure: k6257 
o|substituted constant variable: a6416 
o|inlining procedure: k6428 
o|contracted procedure: "(c-platform.scm:291) g597604" 
o|propagated global variable: g612613 chicken.compiler.support#mark-variable 
o|inlining procedure: k6428 
o|substituted constant variable: chicken.compiler.c-platform#constant588 
o|substituted constant variable: chicken.compiler.c-platform#constant584 
o|substituted constant variable: chicken.compiler.c-platform#constant592 
o|inlining procedure: k6451 
o|contracted procedure: "(c-platform.scm:125) g564573" 
o|inlining procedure: k6451 
o|simplifications: ((if . 1)) 
o|replaced variables: 608 
o|removed binding forms: 585 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#every 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#any 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#first 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#second 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#third 
o|substituted constant variable: r23176491 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#min-words-per-bignum 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#constant584 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#constant588 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#constant592 
o|substituted constant variable: r30276503 
o|substituted constant variable: r31136506 
o|substituted constant variable: r31376513 
o|substituted constant variable: r31976522 
o|substituted constant variable: r30956533 
o|substituted constant variable: r33896551 
o|substituted constant variable: r33756553 
o|substituted constant variable: r32576556 
o|substituted constant variable: r34466567 
o|substituted constant variable: r35246569 
o|substituted constant variable: r36006574 
o|substituted constant variable: r35886580 
o|substituted constant variable: r35736581 
o|substituted constant variable: r35556582 
o|substituted constant variable: r44786592 
o|substituted constant variable: r45646600 
o|substituted constant variable: r45646600 
o|folded constant expression: (scheme#not (quote #f)) 
o|substituted constant variable: r44636602 
o|contracted procedure: "(c-platform.scm:1180) chicken.compiler.c-platform#list-tabulate" 
o|substituted constant variable: r27166492 
o|substituted constant variable: r52016610 
o|substituted constant variable: r51806621 
o|substituted constant variable: r53386626 
o|substituted constant variable: r53236632 
o|substituted constant variable: r53056638 
o|substituted constant variable: r52876649 
o|removed side-effect free assignment to unused variable: chicken.compiler.c-platform#setter-map 
o|substituted constant variable: r54896651 
o|substituted constant variable: r54896651 
o|substituted constant variable: r54896653 
o|substituted constant variable: r54896653 
o|substituted constant variable: r54636655 
o|substituted constant variable: r55296657 
o|substituted constant variable: r55296657 
o|substituted constant variable: r55296659 
o|substituted constant variable: r55296659 
o|substituted constant variable: r55036661 
o|substituted constant variable: r55616664 
o|substituted constant variable: r55436665 
o|converted assignments to bindings: (rewrite-call/cc902) 
o|converted assignments to bindings: (rewrite-make-vector885) 
o|substituted constant variable: r56696683 
o|substituted constant variable: r56576689 
o|substituted constant variable: r56086695 
o|substituted constant variable: r57556697 
o|substituted constant variable: r57556697 
o|substituted constant variable: r57556699 
o|substituted constant variable: r57556699 
o|substituted constant variable: r57306711 
o|substituted constant variable: r57876732 
o|converted assignments to bindings: (rewrite-div833) 
o|substituted constant variable: r58646733 
o|substituted constant variable: r58956735 
o|substituted constant variable: r58956735 
o|substituted constant variable: r58956737 
o|substituted constant variable: r58956737 
o|substituted constant variable: r59016740 
o|substituted constant variable: r59546748 
o|substituted constant variable: r59546748 
o|folded constant expression: (scheme#not (quote #f)) 
o|substituted constant variable: r59886750 
o|substituted constant variable: r60196752 
o|substituted constant variable: r60196752 
o|substituted constant variable: r60196754 
o|substituted constant variable: r60196754 
o|substituted constant variable: r60256757 
o|substituted constant variable: r60786765 
o|substituted constant variable: r60786765 
o|folded constant expression: (scheme#not (quote #f)) 
o|substituted constant variable: r61576782 
o|substituted constant variable: r62346790 
o|substituted constant variable: r62346790 
o|folded constant expression: (scheme#not (quote #f)) 
o|converted assignments to bindings: (rewrite-c-w-v763) 
o|converted assignments to bindings: (rewrite-c..r734) 
o|converted assignments to bindings: (rewrite-apply690) 
o|substituted constant variable: r63186801 
o|substituted constant variable: r63706810 
o|substituted constant variable: r62586821 
o|converted assignments to bindings: (eqv?-id630) 
o|converted assignments to bindings: (op1619) 
o|substituted constant variable: g603605 
o|substituted constant variable: g570574 
o|simplifications: ((let . 8)) 
o|replaced variables: 127 
o|removed binding forms: 548 
o|replaced variables: 3 
o|removed binding forms: 208 
o|removed binding forms: 3 
o|removed unused formal parameters: (i899) 
o|removed unused parameter to known procedure: i899 "(mini-srfi-1.scm:190) a5250" 
o|simplifications: ((if . 10) (let . 10) (##core#call . 280)) 
o|  call simplifications:
o|    scheme#symbol?	2
o|    scheme#assq
o|    scheme#=
o|    chicken.base#fixnum?	2
o|    scheme#<=
o|    chicken.fixnum#fx+
o|    chicken.fixnum#fx>=	5
o|    scheme#caddr	3
o|    scheme#list?
o|    scheme#cdr	6
o|    ##sys#setslot	2
o|    scheme#cadr	8
o|    scheme#equal?	2
o|    scheme#number?	2
o|    scheme#not	12
o|    scheme#length	19
o|    scheme#eq?	56
o|    scheme#list	84
o|    ##sys#check-list	2
o|    scheme#pair?	7
o|    ##sys#slot	10
o|    scheme#null?	8
o|    scheme#car	34
o|    scheme#cons	11
o|contracted procedure: k2140 
o|contracted procedure: k2151 
o|contracted procedure: k2307 
o|contracted procedure: k2319 
o|contracted procedure: k2337 
o|contracted procedure: k2345 
o|contracted procedure: k2994 
o|contracted procedure: k3081 
o|contracted procedure: k3029 
o|contracted procedure: k3036 
o|contracted procedure: k3040 
o|contracted procedure: k3047 
o|contracted procedure: k3054 
o|contracted procedure: k3065 
o|contracted procedure: k3073 
o|contracted procedure: k3069 
o|contracted procedure: k3240 
o|contracted procedure: k3097 
o|contracted procedure: k3100 
o|contracted procedure: k3103 
o|contracted procedure: k3125 
o|contracted procedure: k3129 
o|contracted procedure: k3139 
o|contracted procedure: k3142 
o|contracted procedure: k3155 
o|contracted procedure: k3166 
o|contracted procedure: k3169 
o|contracted procedure: k3182 
o|contracted procedure: k3193 
o|contracted procedure: k3199 
o|contracted procedure: k3205 
o|contracted procedure: k3212 
o|contracted procedure: k3216 
o|contracted procedure: k3259 
o|contracted procedure: k3269 
o|contracted procedure: k3276 
o|contracted procedure: k3284 
o|contracted procedure: k3292 
o|contracted procedure: k3296 
o|contracted procedure: k3299 
o|contracted procedure: k3302 
o|contracted procedure: k3314 
o|contracted procedure: k3317 
o|contracted procedure: k3320 
o|contracted procedure: k3328 
o|contracted procedure: k3336 
o|contracted procedure: k3360 
o|contracted procedure: k3371 
o|contracted procedure: k3419 
o|contracted procedure: k3377 
o|contracted procedure: k3380 
o|contracted procedure: k3398 
o|contracted procedure: k3410 
o|contracted procedure: k3402 
o|contracted procedure: k2486 
o|contracted procedure: k2476 
o|contracted procedure: k3499 
o|contracted procedure: k3448 
o|contracted procedure: k3457 
o|contracted procedure: k3464 
o|contracted procedure: k3468 
o|contracted procedure: k3475 
o|contracted procedure: k3482 
o|contracted procedure: k3492 
o|contracted procedure: k3541 
o|contracted procedure: k3526 
o|contracted procedure: k3533 
o|contracted procedure: k3537 
o|contracted procedure: k3712 
o|contracted procedure: k3557 
o|contracted procedure: k3560 
o|contracted procedure: k3563 
o|contracted procedure: k3569 
o|contracted procedure: k3575 
o|contracted procedure: k3578 
o|contracted procedure: k3593 
o|contracted procedure: k3596 
o|contracted procedure: k3602 
o|contracted procedure: k3608 
o|contracted procedure: k3624 
o|contracted procedure: k3628 
o|contracted procedure: k3640 
o|contracted procedure: k3644 
o|contracted procedure: k3680 
o|contracted procedure: k3652 
o|contracted procedure: k3656 
o|contracted procedure: k3664 
o|contracted procedure: k3668 
o|contracted procedure: k4465 
o|contracted procedure: k4587 
o|contracted procedure: k4471 
o|contracted procedure: k4549 
o|contracted procedure: k4474 
o|contracted procedure: k4544 
o|contracted procedure: k4480 
o|contracted procedure: k4487 
o|contracted procedure: k4491 
o|contracted procedure: k4511 
o|contracted procedure: k4522 
o|contracted procedure: k4525 
o|contracted procedure: k4532 
o|contracted procedure: k4566 
o|contracted procedure: k4573 
o|contracted procedure: k4563 
o|contracted procedure: k5176 
o|contracted procedure: k5182 
o|contracted procedure: k5185 
o|contracted procedure: k5191 
o|contracted procedure: k5197 
o|contracted procedure: k5203 
o|contracted procedure: k5219 
o|contracted procedure: k5223 
o|contracted procedure: k5231 
o|contracted procedure: k5235 
o|contracted procedure: k5243 
o|contracted procedure: k2718 
o|contracted procedure: k2733 
o|contracted procedure: k5258 
o|contracted procedure: k5401 
o|contracted procedure: k5289 
o|contracted procedure: k5292 
o|contracted procedure: k5298 
o|contracted procedure: k5307 
o|contracted procedure: k5313 
o|contracted procedure: k5325 
o|contracted procedure: k5328 
o|contracted procedure: k5334 
o|contracted procedure: k5340 
o|contracted procedure: k5346 
o|contracted procedure: k5353 
o|contracted procedure: k5357 
o|contracted procedure: k5388 
o|contracted procedure: k5496 
o|contracted procedure: k5465 
o|contracted procedure: k5472 
o|contracted procedure: k5476 
o|contracted procedure: k5491 
o|contracted procedure: k5484 
o|contracted procedure: k5536 
o|contracted procedure: k5505 
o|contracted procedure: k5512 
o|contracted procedure: k5516 
o|contracted procedure: k5531 
o|contracted procedure: k5524 
o|contracted procedure: k5601 
o|contracted procedure: k5545 
o|contracted procedure: k5548 
o|contracted procedure: k5554 
o|contracted procedure: k5557 
o|contracted procedure: k5566 
o|contracted procedure: k5576 
o|contracted procedure: k5580 
o|contracted procedure: k5588 
o|contracted procedure: k5723 
o|contracted procedure: k5610 
o|contracted procedure: k5613 
o|contracted procedure: k5620 
o|contracted procedure: k5628 
o|inlining procedure: k5624 
o|inlining procedure: k5624 
o|contracted procedure: k5640 
o|contracted procedure: k5650 
o|contracted procedure: k5653 
o|contracted procedure: k5659 
o|contracted procedure: k5683 
o|contracted procedure: k5679 
o|contracted procedure: k5700 
o|contracted procedure: k5696 
o|contracted procedure: k5703 
o|contracted procedure: k5779 
o|contracted procedure: k5732 
o|contracted procedure: k5739 
o|contracted procedure: k5743 
o|contracted procedure: k5751 
o|contracted procedure: k5760 
o|contracted procedure: k5767 
o|contracted procedure: k5789 
o|contracted procedure: k5856 
o|contracted procedure: k5795 
o|contracted procedure: k5802 
o|contracted procedure: k5806 
o|contracted procedure: k5809 
o|contracted procedure: k5827 
o|contracted procedure: k5823 
o|contracted procedure: k5837 
o|contracted procedure: k5844 
o|contracted procedure: k5866 
o|contracted procedure: k5974 
o|contracted procedure: k5875 
o|contracted procedure: k5882 
o|contracted procedure: k5886 
o|contracted procedure: k5897 
o|contracted procedure: k5936 
o|contracted procedure: k5903 
o|contracted procedure: k5910 
o|contracted procedure: k5914 
o|contracted procedure: k5928 
o|contracted procedure: k5932 
o|contracted procedure: k5956 
o|contracted procedure: k5960 
o|contracted procedure: k5981 
o|contracted procedure: k5990 
o|contracted procedure: k6098 
o|contracted procedure: k5999 
o|contracted procedure: k6006 
o|contracted procedure: k6010 
o|contracted procedure: k6021 
o|contracted procedure: k6060 
o|contracted procedure: k6027 
o|contracted procedure: k6034 
o|contracted procedure: k6038 
o|contracted procedure: k6052 
o|contracted procedure: k6056 
o|contracted procedure: k6080 
o|contracted procedure: k6084 
o|contracted procedure: k6105 
o|contracted procedure: k6117 
o|contracted procedure: k6124 
o|contracted procedure: k6128 
o|contracted procedure: k6223 
o|contracted procedure: k6138 
o|contracted procedure: k6145 
o|contracted procedure: k6153 
o|contracted procedure: k6149 
o|contracted procedure: k6159 
o|contracted procedure: k6166 
o|contracted procedure: k6170 
o|contracted procedure: k6190 
o|contracted procedure: k6201 
o|contracted procedure: k6204 
o|contracted procedure: k6211 
o|contracted procedure: k6236 
o|contracted procedure: k6243 
o|contracted procedure: k6233 
o|contracted procedure: k6413 
o|contracted procedure: k6260 
o|contracted procedure: k6263 
o|contracted procedure: k6266 
o|contracted procedure: k6285 
o|contracted procedure: k6289 
o|contracted procedure: k6306 
o|contracted procedure: k6310 
o|contracted procedure: k6320 
o|contracted procedure: k6323 
o|contracted procedure: k6343 
o|contracted procedure: k6346 
o|contracted procedure: k6366 
o|contracted procedure: k6372 
o|contracted procedure: k6378 
o|contracted procedure: k6385 
o|contracted procedure: k6389 
o|contracted procedure: k6431 
o|contracted procedure: k6441 
o|contracted procedure: k6445 
o|contracted procedure: k6454 
o|contracted procedure: k6457 
o|contracted procedure: k6460 
o|contracted procedure: k6468 
o|contracted procedure: k6476 
o|simplifications: ((if . 4) (let . 47)) 
o|removed binding forms: 257 
o|contracted procedure: k5869 
o|contracted procedure: k5993 
o|removed binding forms: 3 
o|direct leaf routine/allocation: loop333 0 
o|contracted procedure: k3262 
o|converted assignments to bindings: (loop333) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 1 
o|customizable procedures: (map-loop558576 for-each-loop596614 op1619 k6296 k6299 rewrite-c..r734 k6183 k5816 k5665 a5250 loop428 chicken.compiler.c-platform#filter k4504 map-loop700717 chicken.compiler.c-platform#cons* k3115 k3118 foldr260263 g265266 loop210) 
o|calls to known targets: 63 
o|identified direct recursive calls: f_2135 1 
o|identified direct recursive calls: f_2314 1 
o|identified direct recursive calls: f_2471 1 
o|fast box initializations: 6 
o|fast global references: 6 
o|fast global assignments: 2 
o|dropping unused closure argument: f_2129 
o|dropping unused closure argument: f_2305 
o|dropping unused closure argument: f_2471 
o|dropping unused closure argument: f_3022 
o|dropping unused closure argument: f_3437 
*/
/* end of file */
