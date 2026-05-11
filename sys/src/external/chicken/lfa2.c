/* Generated from lfa2.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: lfa2.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.lfa2 -output-file lfa2.c
   unit: lfa2
   uses: eval extras support library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_support_toplevel)
C_externimport void C_ccall C_support_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[103];
static double C_possibly_force_alignment;


C_noret_decl(f5398)
static void C_ccall f5398(C_word c,C_word *av) C_noret;
C_noret_decl(f5456)
static void C_ccall f5456(C_word c,C_word *av) C_noret;
C_noret_decl(f5477)
static void C_ccall f5477(C_word c,C_word *av) C_noret;
C_noret_decl(f5489)
static void C_ccall f5489(C_word c,C_word *av) C_noret;
C_noret_decl(f5496)
static void C_ccall f5496(C_word c,C_word *av) C_noret;
C_noret_decl(f_1459)
static void C_ccall f_1459(C_word c,C_word *av) C_noret;
C_noret_decl(f_1462)
static void C_ccall f_1462(C_word c,C_word *av) C_noret;
C_noret_decl(f_1465)
static void C_ccall f_1465(C_word c,C_word *av) C_noret;
C_noret_decl(f_1468)
static void C_ccall f_1468(C_word c,C_word *av) C_noret;
C_noret_decl(f_2088)
static void C_fcall f_2088(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2096)
static C_word C_fcall f_2096(C_word *a,C_word t0,C_word t1,C_word t2);
C_noret_decl(f_2117)
static void C_ccall f_2117(C_word c,C_word *av) C_noret;
C_noret_decl(f_2132)
static void C_fcall f_2132(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2148)
static C_word C_fcall f_2148(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_2166)
static void C_ccall f_2166(C_word c,C_word *av) C_noret;
C_noret_decl(f_2178)
static C_word C_fcall f_2178(C_word t0,C_word t1);
C_noret_decl(f_2682)
static void C_fcall f_2682(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2688)
static C_word C_fcall f_2688(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_2753)
static void C_ccall f_2753(C_word c,C_word *av) C_noret;
C_noret_decl(f_2769)
static void C_ccall f_2769(C_word c,C_word *av) C_noret;
C_noret_decl(f_2781)
static void C_ccall f_2781(C_word c,C_word *av) C_noret;
C_noret_decl(f_2784)
static void C_ccall f_2784(C_word c,C_word *av) C_noret;
C_noret_decl(f_2887)
static C_word C_fcall f_2887(C_word t0,C_word t1);
C_noret_decl(f_2938)
static C_word C_fcall f_2938(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_2964)
static void C_fcall f_2964(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2970)
static void C_fcall f_2970(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2975)
static void C_ccall f_2975(C_word c,C_word *av) C_noret;
C_noret_decl(f_3001)
static void C_ccall f_3001(C_word c,C_word *av) C_noret;
C_noret_decl(f_3005)
static void C_ccall f_3005(C_word c,C_word *av) C_noret;
C_noret_decl(f_3009)
static void C_ccall f_3009(C_word c,C_word *av) C_noret;
C_noret_decl(f_3011)
static void C_fcall f_3011(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3015)
static void C_ccall f_3015(C_word c,C_word *av) C_noret;
C_noret_decl(f_3018)
static void C_ccall f_3018(C_word c,C_word *av) C_noret;
C_noret_decl(f_3021)
static void C_ccall f_3021(C_word c,C_word *av) C_noret;
C_noret_decl(f_3026)
static void C_fcall f_3026(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3033)
static void C_ccall f_3033(C_word c,C_word *av) C_noret;
C_noret_decl(f_3034)
static void C_fcall f_3034(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3041)
static void C_ccall f_3041(C_word c,C_word *av) C_noret;
C_noret_decl(f_3051)
static void C_ccall f_3051(C_word c,C_word *av) C_noret;
C_noret_decl(f_3068)
static void C_ccall f_3068(C_word c,C_word *av) C_noret;
C_noret_decl(f_3075)
static void C_ccall f_3075(C_word c,C_word *av) C_noret;
C_noret_decl(f_3103)
static void C_ccall f_3103(C_word c,C_word *av) C_noret;
C_noret_decl(f_3105)
static void C_fcall f_3105(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3115)
static void C_ccall f_3115(C_word c,C_word *av) C_noret;
C_noret_decl(f_3134)
static void C_ccall f_3134(C_word c,C_word *av) C_noret;
C_noret_decl(f_3151)
static C_word C_fcall f_3151(C_word t0,C_word t1);
C_noret_decl(f_3197)
static C_word C_fcall f_3197(C_word t0,C_word t1);
C_noret_decl(f_3203)
static void C_fcall f_3203(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3208)
static void C_ccall f_3208(C_word c,C_word *av) C_noret;
C_noret_decl(f_3210)
static C_word C_fcall f_3210(C_word t0,C_word t1);
C_noret_decl(f_3220)
static void C_fcall f_3220(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3227)
static void C_fcall f_3227(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3231)
static void C_fcall f_3231(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3239)
static void C_ccall f_3239(C_word c,C_word *av) C_noret;
C_noret_decl(f_3251)
static void C_ccall f_3251(C_word c,C_word *av) C_noret;
C_noret_decl(f_3268)
static void C_ccall f_3268(C_word c,C_word *av) C_noret;
C_noret_decl(f_3276)
static void C_fcall f_3276(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3282)
static void C_fcall f_3282(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3288)
static void C_fcall f_3288(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3294)
static void C_fcall f_3294(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3298)
static void C_ccall f_3298(C_word c,C_word *av) C_noret;
C_noret_decl(f_3301)
static void C_ccall f_3301(C_word c,C_word *av) C_noret;
C_noret_decl(f_3304)
static void C_ccall f_3304(C_word c,C_word *av) C_noret;
C_noret_decl(f_3313)
static void C_ccall f_3313(C_word c,C_word *av) C_noret;
C_noret_decl(f_3316)
static void C_ccall f_3316(C_word c,C_word *av) C_noret;
C_noret_decl(f_3363)
static void C_ccall f_3363(C_word c,C_word *av) C_noret;
C_noret_decl(f_3366)
static void C_fcall f_3366(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3373)
static void C_ccall f_3373(C_word c,C_word *av) C_noret;
C_noret_decl(f_3377)
static void C_ccall f_3377(C_word c,C_word *av) C_noret;
C_noret_decl(f_3395)
static void C_ccall f_3395(C_word c,C_word *av) C_noret;
C_noret_decl(f_3399)
static void C_ccall f_3399(C_word c,C_word *av) C_noret;
C_noret_decl(f_3407)
static void C_ccall f_3407(C_word c,C_word *av) C_noret;
C_noret_decl(f_3419)
static void C_ccall f_3419(C_word c,C_word *av) C_noret;
C_noret_decl(f_3463)
static void C_ccall f_3463(C_word c,C_word *av) C_noret;
C_noret_decl(f_3466)
static void C_ccall f_3466(C_word c,C_word *av) C_noret;
C_noret_decl(f_3469)
static void C_ccall f_3469(C_word c,C_word *av) C_noret;
C_noret_decl(f_3480)
static void C_fcall f_3480(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3487)
static void C_fcall f_3487(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3501)
static void C_ccall f_3501(C_word c,C_word *av) C_noret;
C_noret_decl(f_3517)
static void C_ccall f_3517(C_word c,C_word *av) C_noret;
C_noret_decl(f_3525)
static void C_ccall f_3525(C_word c,C_word *av) C_noret;
C_noret_decl(f_3531)
static void C_fcall f_3531(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3573)
static void C_ccall f_3573(C_word c,C_word *av) C_noret;
C_noret_decl(f_3592)
static void C_ccall f_3592(C_word c,C_word *av) C_noret;
C_noret_decl(f_3595)
static void C_ccall f_3595(C_word c,C_word *av) C_noret;
C_noret_decl(f_3598)
static void C_fcall f_3598(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3609)
static void C_ccall f_3609(C_word c,C_word *av) C_noret;
C_noret_decl(f_3623)
static void C_ccall f_3623(C_word c,C_word *av) C_noret;
C_noret_decl(f_3648)
static void C_fcall f_3648(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3652)
static void C_ccall f_3652(C_word c,C_word *av) C_noret;
C_noret_decl(f_3664)
static void C_ccall f_3664(C_word c,C_word *av) C_noret;
C_noret_decl(f_3671)
static void C_fcall f_3671(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3675)
static void C_ccall f_3675(C_word c,C_word *av) C_noret;
C_noret_decl(f_3678)
static void C_ccall f_3678(C_word c,C_word *av) C_noret;
C_noret_decl(f_3693)
static void C_fcall f_3693(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3719)
static void C_ccall f_3719(C_word c,C_word *av) C_noret;
C_noret_decl(f_3739)
static void C_ccall f_3739(C_word c,C_word *av) C_noret;
C_noret_decl(f_3801)
static void C_fcall f_3801(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3808)
static void C_ccall f_3808(C_word c,C_word *av) C_noret;
C_noret_decl(f_3811)
static void C_ccall f_3811(C_word c,C_word *av) C_noret;
C_noret_decl(f_3817)
static void C_ccall f_3817(C_word c,C_word *av) C_noret;
C_noret_decl(f_3820)
static void C_ccall f_3820(C_word c,C_word *av) C_noret;
C_noret_decl(f_3827)
static void C_ccall f_3827(C_word c,C_word *av) C_noret;
C_noret_decl(f_3831)
static void C_ccall f_3831(C_word c,C_word *av) C_noret;
C_noret_decl(f_3835)
static void C_ccall f_3835(C_word c,C_word *av) C_noret;
C_noret_decl(f_3849)
static void C_fcall f_3849(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3903)
static void C_ccall f_3903(C_word c,C_word *av) C_noret;
C_noret_decl(f_3911)
static void C_ccall f_3911(C_word c,C_word *av) C_noret;
C_noret_decl(f_3926)
static void C_ccall f_3926(C_word c,C_word *av) C_noret;
C_noret_decl(f_3929)
static void C_ccall f_3929(C_word c,C_word *av) C_noret;
C_noret_decl(f_3932)
static void C_ccall f_3932(C_word c,C_word *av) C_noret;
C_noret_decl(f_3941)
static void C_fcall f_3941(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3967)
static void C_ccall f_3967(C_word c,C_word *av) C_noret;
C_noret_decl(f_3987)
static void C_ccall f_3987(C_word c,C_word *av) C_noret;
C_noret_decl(f_4045)
static void C_fcall f_4045(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4055)
static void C_fcall f_4055(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4071)
static void C_ccall f_4071(C_word c,C_word *av) C_noret;
C_noret_decl(f_4087)
static void C_ccall f_4087(C_word c,C_word *av) C_noret;
C_noret_decl(f_4118)
static void C_fcall f_4118(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4128)
static void C_ccall f_4128(C_word c,C_word *av) C_noret;
C_noret_decl(f_4144)
static void C_fcall f_4144(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4154)
static void C_ccall f_4154(C_word c,C_word *av) C_noret;
C_noret_decl(f_4156)
static void C_fcall f_4156(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4166)
static void C_ccall f_4166(C_word c,C_word *av) C_noret;
C_noret_decl(f_4218)
static void C_ccall f_4218(C_word c,C_word *av) C_noret;
C_noret_decl(f_4221)
static void C_ccall f_4221(C_word c,C_word *av) C_noret;
C_noret_decl(f_4229)
static void C_ccall f_4229(C_word c,C_word *av) C_noret;
C_noret_decl(f_4233)
static void C_ccall f_4233(C_word c,C_word *av) C_noret;
C_noret_decl(f_4241)
static void C_ccall f_4241(C_word c,C_word *av) C_noret;
C_noret_decl(f_4244)
static void C_ccall f_4244(C_word c,C_word *av) C_noret;
C_noret_decl(f_4247)
static void C_ccall f_4247(C_word c,C_word *av) C_noret;
C_noret_decl(f_4250)
static void C_ccall f_4250(C_word c,C_word *av) C_noret;
C_noret_decl(f_4267)
static void C_fcall f_4267(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4277)
static void C_ccall f_4277(C_word c,C_word *av) C_noret;
C_noret_decl(f_4290)
static void C_ccall f_4290(C_word c,C_word *av) C_noret;
C_noret_decl(f_4294)
static void C_ccall f_4294(C_word c,C_word *av) C_noret;
C_noret_decl(f_4296)
static void C_ccall f_4296(C_word c,C_word *av) C_noret;
C_noret_decl(f_4300)
static void C_ccall f_4300(C_word c,C_word *av) C_noret;
C_noret_decl(f_4303)
static void C_ccall f_4303(C_word c,C_word *av) C_noret;
C_noret_decl(f_4306)
static void C_ccall f_4306(C_word c,C_word *av) C_noret;
C_noret_decl(f_4334)
static void C_ccall f_4334(C_word c,C_word *av) C_noret;
C_noret_decl(f_4371)
static void C_fcall f_4371(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4400)
static void C_ccall f_4400(C_word c,C_word *av) C_noret;
C_noret_decl(f_4402)
static void C_fcall f_4402(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4427)
static void C_ccall f_4427(C_word c,C_word *av) C_noret;
C_noret_decl(f_4451)
static void C_ccall f_4451(C_word c,C_word *av) C_noret;
C_noret_decl(f_4461)
static void C_ccall f_4461(C_word c,C_word *av) C_noret;
C_noret_decl(f_4463)
static void C_fcall f_4463(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4488)
static void C_ccall f_4488(C_word c,C_word *av) C_noret;
C_noret_decl(f_4510)
static void C_ccall f_4510(C_word c,C_word *av) C_noret;
C_noret_decl(f_4523)
static void C_ccall f_4523(C_word c,C_word *av) C_noret;
C_noret_decl(f_4527)
static void C_ccall f_4527(C_word c,C_word *av) C_noret;
C_noret_decl(f_4530)
static void C_ccall f_4530(C_word c,C_word *av) C_noret;
C_noret_decl(f_4533)
static void C_ccall f_4533(C_word c,C_word *av) C_noret;
C_noret_decl(f_4542)
static void C_ccall f_4542(C_word c,C_word *av) C_noret;
C_noret_decl(f_4556)
static void C_ccall f_4556(C_word c,C_word *av) C_noret;
C_noret_decl(f_4579)
static void C_ccall f_4579(C_word c,C_word *av) C_noret;
C_noret_decl(f_4597)
static void C_ccall f_4597(C_word c,C_word *av) C_noret;
C_noret_decl(f_4601)
static void C_ccall f_4601(C_word c,C_word *av) C_noret;
C_noret_decl(f_4618)
static void C_ccall f_4618(C_word c,C_word *av) C_noret;
C_noret_decl(f_4620)
static void C_fcall f_4620(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4645)
static void C_ccall f_4645(C_word c,C_word *av) C_noret;
C_noret_decl(f_4668)
static void C_fcall f_4668(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4680)
static void C_ccall f_4680(C_word c,C_word *av) C_noret;
C_noret_decl(f_4712)
static void C_ccall f_4712(C_word c,C_word *av) C_noret;
C_noret_decl(f_4714)
static void C_fcall f_4714(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4739)
static void C_ccall f_4739(C_word c,C_word *av) C_noret;
C_noret_decl(f_4765)
static void C_ccall f_4765(C_word c,C_word *av) C_noret;
C_noret_decl(f_4767)
static void C_fcall f_4767(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4792)
static void C_ccall f_4792(C_word c,C_word *av) C_noret;
C_noret_decl(f_4816)
static void C_ccall f_4816(C_word c,C_word *av) C_noret;
C_noret_decl(f_4818)
static void C_fcall f_4818(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4843)
static void C_ccall f_4843(C_word c,C_word *av) C_noret;
C_noret_decl(f_4864)
static void C_ccall f_4864(C_word c,C_word *av) C_noret;
C_noret_decl(f_4867)
static void C_ccall f_4867(C_word c,C_word *av) C_noret;
C_noret_decl(f_4869)
static void C_ccall f_4869(C_word c,C_word *av) C_noret;
C_noret_decl(f_4876)
static void C_ccall f_4876(C_word c,C_word *av) C_noret;
C_noret_decl(f_4879)
static void C_ccall f_4879(C_word c,C_word *av) C_noret;
C_noret_decl(f_4882)
static void C_ccall f_4882(C_word c,C_word *av) C_noret;
C_noret_decl(f_4888)
static void C_ccall f_4888(C_word c,C_word *av) C_noret;
C_noret_decl(f_4891)
static void C_ccall f_4891(C_word c,C_word *av) C_noret;
C_noret_decl(C_lfa2_toplevel)
C_externexport void C_ccall C_lfa2_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_2088)
static void C_ccall trf_2088(C_word c,C_word *av) C_noret;
static void C_ccall trf_2088(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2088(t0,t1,t2);}

C_noret_decl(trf_2132)
static void C_ccall trf_2132(C_word c,C_word *av) C_noret;
static void C_ccall trf_2132(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2132(t0,t1,t2);}

C_noret_decl(trf_2682)
static void C_ccall trf_2682(C_word c,C_word *av) C_noret;
static void C_ccall trf_2682(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2682(t0,t1,t2);}

C_noret_decl(trf_2964)
static void C_ccall trf_2964(C_word c,C_word *av) C_noret;
static void C_ccall trf_2964(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2964(t0,t1,t2);}

C_noret_decl(trf_2970)
static void C_ccall trf_2970(C_word c,C_word *av) C_noret;
static void C_ccall trf_2970(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2970(t0,t1,t2);}

C_noret_decl(trf_3011)
static void C_ccall trf_3011(C_word c,C_word *av) C_noret;
static void C_ccall trf_3011(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3011(t0,t1,t2);}

C_noret_decl(trf_3026)
static void C_ccall trf_3026(C_word c,C_word *av) C_noret;
static void C_ccall trf_3026(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3026(t0,t1,t2,t3);}

C_noret_decl(trf_3034)
static void C_ccall trf_3034(C_word c,C_word *av) C_noret;
static void C_ccall trf_3034(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3034(t0,t1,t2);}

C_noret_decl(trf_3105)
static void C_ccall trf_3105(C_word c,C_word *av) C_noret;
static void C_ccall trf_3105(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3105(t0,t1,t2);}

C_noret_decl(trf_3203)
static void C_ccall trf_3203(C_word c,C_word *av) C_noret;
static void C_ccall trf_3203(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3203(t0,t1,t2);}

C_noret_decl(trf_3220)
static void C_ccall trf_3220(C_word c,C_word *av) C_noret;
static void C_ccall trf_3220(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3220(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3227)
static void C_ccall trf_3227(C_word c,C_word *av) C_noret;
static void C_ccall trf_3227(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3227(t0,t1);}

C_noret_decl(trf_3231)
static void C_ccall trf_3231(C_word c,C_word *av) C_noret;
static void C_ccall trf_3231(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3231(t0,t1,t2);}

C_noret_decl(trf_3276)
static void C_ccall trf_3276(C_word c,C_word *av) C_noret;
static void C_ccall trf_3276(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3276(t0,t1,t2);}

C_noret_decl(trf_3282)
static void C_ccall trf_3282(C_word c,C_word *av) C_noret;
static void C_ccall trf_3282(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3282(t0,t1,t2);}

C_noret_decl(trf_3288)
static void C_ccall trf_3288(C_word c,C_word *av) C_noret;
static void C_ccall trf_3288(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3288(t0,t1,t2);}

C_noret_decl(trf_3294)
static void C_ccall trf_3294(C_word c,C_word *av) C_noret;
static void C_ccall trf_3294(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3294(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3366)
static void C_ccall trf_3366(C_word c,C_word *av) C_noret;
static void C_ccall trf_3366(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3366(t0,t1);}

C_noret_decl(trf_3480)
static void C_ccall trf_3480(C_word c,C_word *av) C_noret;
static void C_ccall trf_3480(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3480(t0,t1);}

C_noret_decl(trf_3487)
static void C_ccall trf_3487(C_word c,C_word *av) C_noret;
static void C_ccall trf_3487(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3487(t0,t1);}

C_noret_decl(trf_3531)
static void C_ccall trf_3531(C_word c,C_word *av) C_noret;
static void C_ccall trf_3531(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3531(t0,t1);}

C_noret_decl(trf_3598)
static void C_ccall trf_3598(C_word c,C_word *av) C_noret;
static void C_ccall trf_3598(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3598(t0,t1);}

C_noret_decl(trf_3648)
static void C_ccall trf_3648(C_word c,C_word *av) C_noret;
static void C_ccall trf_3648(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3648(t0,t1,t2);}

C_noret_decl(trf_3671)
static void C_ccall trf_3671(C_word c,C_word *av) C_noret;
static void C_ccall trf_3671(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3671(t0,t1,t2);}

C_noret_decl(trf_3693)
static void C_ccall trf_3693(C_word c,C_word *av) C_noret;
static void C_ccall trf_3693(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3693(t0,t1);}

C_noret_decl(trf_3801)
static void C_ccall trf_3801(C_word c,C_word *av) C_noret;
static void C_ccall trf_3801(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3801(t0,t1,t2);}

C_noret_decl(trf_3849)
static void C_ccall trf_3849(C_word c,C_word *av) C_noret;
static void C_ccall trf_3849(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3849(t0,t1,t2);}

C_noret_decl(trf_3941)
static void C_ccall trf_3941(C_word c,C_word *av) C_noret;
static void C_ccall trf_3941(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3941(t0,t1);}

C_noret_decl(trf_4045)
static void C_ccall trf_4045(C_word c,C_word *av) C_noret;
static void C_ccall trf_4045(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4045(t0,t1,t2);}

C_noret_decl(trf_4055)
static void C_ccall trf_4055(C_word c,C_word *av) C_noret;
static void C_ccall trf_4055(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4055(t0,t1);}

C_noret_decl(trf_4118)
static void C_ccall trf_4118(C_word c,C_word *av) C_noret;
static void C_ccall trf_4118(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4118(t0,t1,t2);}

C_noret_decl(trf_4144)
static void C_ccall trf_4144(C_word c,C_word *av) C_noret;
static void C_ccall trf_4144(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4144(t0,t1,t2);}

C_noret_decl(trf_4156)
static void C_ccall trf_4156(C_word c,C_word *av) C_noret;
static void C_ccall trf_4156(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4156(t0,t1,t2);}

C_noret_decl(trf_4267)
static void C_ccall trf_4267(C_word c,C_word *av) C_noret;
static void C_ccall trf_4267(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4267(t0,t1,t2);}

C_noret_decl(trf_4371)
static void C_ccall trf_4371(C_word c,C_word *av) C_noret;
static void C_ccall trf_4371(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4371(t0,t1,t2);}

C_noret_decl(trf_4402)
static void C_ccall trf_4402(C_word c,C_word *av) C_noret;
static void C_ccall trf_4402(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4402(t0,t1,t2);}

C_noret_decl(trf_4463)
static void C_ccall trf_4463(C_word c,C_word *av) C_noret;
static void C_ccall trf_4463(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4463(t0,t1,t2);}

C_noret_decl(trf_4620)
static void C_ccall trf_4620(C_word c,C_word *av) C_noret;
static void C_ccall trf_4620(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4620(t0,t1,t2);}

C_noret_decl(trf_4668)
static void C_ccall trf_4668(C_word c,C_word *av) C_noret;
static void C_ccall trf_4668(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4668(t0,t1,t2);}

C_noret_decl(trf_4714)
static void C_ccall trf_4714(C_word c,C_word *av) C_noret;
static void C_ccall trf_4714(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4714(t0,t1,t2);}

C_noret_decl(trf_4767)
static void C_ccall trf_4767(C_word c,C_word *av) C_noret;
static void C_ccall trf_4767(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4767(t0,t1,t2);}

C_noret_decl(trf_4818)
static void C_ccall trf_4818(C_word c,C_word *av) C_noret;
static void C_ccall trf_4818(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4818(t0,t1,t2);}

/* f5398 in k3596 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f5398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f5398,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[62];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f5456 in count-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f5456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f5456,c,av);}
a=C_alloc(4);
t2=C_eqp(lf[11],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3268,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:354: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[15]+1);{
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
t3=((C_word*)t0)[2];
f_3227(t3,C_SCHEME_FALSE);}}

/* f5477 in k3478 in k3467 in k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f5477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f5477,c,av);}
a=C_alloc(7);
t2=C_eqp(lf[11],t1);
if(C_truep(t2)){
if(C_truep(C_i_not(((C_word*)t0)[2]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3517,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3525,a[2]=((C_word*)t0)[4],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:403: chicken.compiler.support#node-parameters */
t5=*((C_word*)lf[15]+1);{
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
else{
t3=((C_word*)t0)[3];
f_3487(t3,C_SCHEME_FALSE);}}
else{
t3=((C_word*)t0)[3];
f_3487(t3,C_SCHEME_FALSE);}}

/* f5489 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f5489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f5489,c,av);}
a=C_alloc(4);
t2=C_eqp(lf[11],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3623,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:416: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[15]+1);{
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
t3=((C_word*)t0)[2];
f_3598(t3,C_SCHEME_FALSE);}}

/* f5496 in g788 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f5496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f5496,c,av);}
a=C_alloc(7);
t2=C_eqp(lf[11],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3926,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:466: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[15]+1);{
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
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3929,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* lfa2.scm:480: walk */
t4=((C_word*)((C_word*)t0)[8])[1];
f_3294(t4,t3,((C_word*)t0)[5],((C_word*)t0)[9],((C_word*)t0)[10]);}}

/* k1457 */
static void C_ccall f_1459(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1459,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1462,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k1460 in k1457 */
static void C_ccall f_1462(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1462,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1465,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k1463 in k1460 in k1457 */
static void C_ccall f_1465(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1465,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1468,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_support_toplevel(2,av2);}}

/* k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_1468(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_1468,c,av);}
a=C_alloc(22);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=C_mutate(&lf[2] /* (set! chicken.compiler.lfa2#posq ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2682,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate(&lf[3] /* (set! chicken.compiler.lfa2#+unboxed-map+ ...) */,lf[4]);
t6=C_mutate((C_word*)lf[5]+1 /* (set! chicken.compiler.lfa2#perform-secondary-flow-analysis ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2753,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate((C_word*)lf[89]+1 /* (set! chicken.compiler.lfa2#perform-unboxing ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4290,tmp=(C_word)a,a+=2,tmp));
t8=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* foldr250 in eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_2088(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_2088,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2096,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2117,a[2]=t1,a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g255 in foldr250 in eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_2096(C_word *a,C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t3=(
/* mini-srfi-1.scm:131: pred */
  f_2178(((C_word*)t0)[2],t1)
);
return((C_truep(t3)?C_a_i_cons(&a,2,t1,t2):t2));}

/* k2115 in foldr250 in eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2117(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2117,c,av);}
a=C_alloc(3);
/* mini-srfi-1.scm:131: g255 */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* mini-srfi-1.scm:131: g255 */
  f_2096(C_a_i(&a,3),((C_word*)t0)[3],((C_word*)t0)[4],t1)
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* foldr268 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_2132(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_2132,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2166,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
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

/* g283 in k2164 in foldr268 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_2148(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_a_i_cons(&a,2,t1,((C_word*)t0)[2]));}

/* k2164 in foldr268 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2166(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2166,c,av);}
a=C_alloc(6);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_i_nequalp(t2,t3);
t5=(C_truep(t4)?C_u_i_car(((C_word*)t0)[2]):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2148,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* mini-srfi-1.scm:135: g283 */
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=(
/* mini-srfi-1.scm:135: g283 */
  f_2148(C_a_i(&a,3),t6,t5)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* a2177 in eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_2178(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_stack_overflow_check;{}
t2=(
/* mini-srfi-1.scm:141: pred */
  f_3210(((C_word*)t0)[2],t1)
);
return(C_i_not(t2));}

/* chicken.compiler.lfa2#posq in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_2682(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_2682,3,t1,t2,t3);}
a=C_alloc(3);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2688,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=(
  f_2688(t4,C_fix(0),t3)
);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* loop in chicken.compiler.lfa2#posq in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_2688(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t2))){
return(C_SCHEME_FALSE);}
else{
t3=C_i_car(t2);
t4=C_eqp(t3,((C_word*)t0)[2]);
if(C_truep(t4)){
return(t1);}
else{
t6=C_fixnum_plus(t1,C_fix(1));
t7=C_u_i_cdr(t2);
t1=t6;
t2=t7;
goto loop;}}}

/* chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2753(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(83,c,5)))){
C_save_and_reclaim((void *)f_2753,c,av);}
a=C_alloc(83);
t4=C_SCHEME_END_OF_LIST;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_END_OF_LIST;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_SCHEME_UNDEFINED;
t19=(*a=C_VECTOR_TYPE|1,a[1]=t18,tmp=(C_word)a,a+=2,tmp);
t20=C_SCHEME_UNDEFINED;
t21=(*a=C_VECTOR_TYPE|1,a[1]=t20,tmp=(C_word)a,a+=2,tmp);
t22=C_SCHEME_UNDEFINED;
t23=(*a=C_VECTOR_TYPE|1,a[1]=t22,tmp=(C_word)a,a+=2,tmp);
t24=C_SCHEME_UNDEFINED;
t25=(*a=C_VECTOR_TYPE|1,a[1]=t24,tmp=(C_word)a,a+=2,tmp);
t26=C_SCHEME_UNDEFINED;
t27=(*a=C_VECTOR_TYPE|1,a[1]=t26,tmp=(C_word)a,a+=2,tmp);
t28=C_SCHEME_UNDEFINED;
t29=(*a=C_VECTOR_TYPE|1,a[1]=t28,tmp=(C_word)a,a+=2,tmp);
t30=C_SCHEME_UNDEFINED;
t31=(*a=C_VECTOR_TYPE|1,a[1]=t30,tmp=(C_word)a,a+=2,tmp);
t32=C_SCHEME_UNDEFINED;
t33=(*a=C_VECTOR_TYPE|1,a[1]=t32,tmp=(C_word)a,a+=2,tmp);
t34=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2887,tmp=(C_word)a,a+=2,tmp));
t35=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2938,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t36=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2964,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t37=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2970,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t38=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3011,a[2]=t31,tmp=(C_word)a,a+=3,tmp));
t39=C_set_block_item(t19,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3026,a[2]=t11,a[3]=t17,a[4]=t15,tmp=(C_word)a,a+=5,tmp));
t40=C_set_block_item(t21,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3197,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t41=C_set_block_item(t23,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3203,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t42=C_set_block_item(t25,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3220,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t43=C_set_block_item(t27,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3276,a[2]=t25,tmp=(C_word)a,a+=3,tmp));
t44=C_set_block_item(t29,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3282,a[2]=t25,tmp=(C_word)a,a+=3,tmp));
t45=C_set_block_item(t31,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3288,a[2]=t25,tmp=(C_word)a,a+=3,tmp));
t46=C_set_block_item(t33,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3294,a[2]=t27,a[3]=t21,a[4]=t23,a[5]=t9,a[6]=t33,a[7]=t13,a[8]=t7,a[9]=t29,a[10]=t19,tmp=(C_word)a,a+=11,tmp));
t47=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4218,a[2]=t1,a[3]=t7,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:513: walk */
t48=((C_word*)t33)[1];
f_3294(t48,t47,t2,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);}

/* k2767 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2769(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2769,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[38];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[39];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2781,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:259: chicken.compiler.support#big-fixnum? */
t3=*((C_word*)lf[54]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}}

/* k2779 in k2767 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2781,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2784,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_2784(2,av2);}}
else{
/* lfa2.scm:259: chicken.compiler.support#small-bignum? */
t3=*((C_word*)lf[53]+1);{
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

/* k2782 in k2779 in k2767 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2784(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_2784,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[40];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[41];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_bignump(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[42];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_flonump(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[43];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_ratnump(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[44];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_cplxnump(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[45];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_booleanp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_nullp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[46];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_listp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[47];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[48];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_eofp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[49];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_bwpp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[50];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[3]))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[51];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_immp(((C_word*)t0)[3]);
t3=C_i_not(t2);
t4=(C_truep(t3)?C_structurep(((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_slot(((C_word*)t0)[3],C_fix(0));
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,2,lf[6],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=C_charp(((C_word*)t0)[3]);
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=(C_truep(t5)?lf[52]:lf[7]);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}}}}}}}}}}}}}}

/* merge in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_2887(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_stack_overflow_check;{}
t3=C_eqp(t1,t2);
if(C_truep(t3)){
return(t1);}
else{
if(C_truep(C_i_pairp(t1))){
if(C_truep(C_i_pairp(t2))){
t4=C_eqp(C_u_i_car(t1),lf[6]);
if(C_truep(t4)){
t5=C_eqp(C_u_i_car(t2),lf[6]);
if(C_truep(t5)){
t6=C_i_cadr(t1);
t7=C_i_cadr(t2);
t8=C_eqp(t6,t7);
return((C_truep(t8)?t1:lf[7]));}
else{
return(lf[7]);}}
else{
return(lf[7]);}}
else{
return(lf[7]);}}
else{
return(lf[7]);}}}

/* report in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_2938(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;{}
t2=C_i_assoc(t1,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(t2)){
t3=C_i_cdr(t2);
t4=C_s_a_i_plus(&a,2,t3,C_fix(1));
return(C_i_set_cdr(t2,t4));}
else{
t3=((C_word*)((C_word*)t0)[2])[1];
t4=C_a_i_cons(&a,2,t1,C_fix(1));
t5=C_a_i_cons(&a,2,t4,t3);
t6=C_mutate(((C_word *)((C_word*)t0)[2])+1,t5);
return(t6);}}

/* assigned? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_2964(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_2964,3,t0,t1,t2);}
/* lfa2.scm:293: chicken.compiler.support#db-get */
t3=*((C_word*)lf[8]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=lf[9];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* droppable? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_2970(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2970,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2975,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:296: chicken.compiler.support#node-class */
t4=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k2973 in droppable? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_2975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2975,c,av);}
a=C_alloc(5);
t2=C_u_i_memq(t1,lf[10]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3009,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:298: chicken.compiler.support#node-class */
t4=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k2999 in k3003 in k3007 in k2973 in droppable? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3001,c,av);}
t2=C_i_not(t1);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* lfa2.scm:301: chicken.compiler.support#variable-mark */
t3=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[13];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k3003 in k3007 in k2973 in droppable? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3005,c,av);}
a=C_alloc(4);
t2=C_i_car(t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3001,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:300: chicken.compiler.support#db-get */
t4=*((C_word*)lf[8]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=t2;
av2[4]=lf[14];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3007 in k2973 in droppable? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3009,c,av);}
a=C_alloc(4);
t2=C_eqp(lf[11],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3005,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:299: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[15]+1);{
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

/* drop! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3011(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3011,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3015,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:304: sub-boxed */
t4=((C_word*)((C_word*)t0)[2])[1];
f_3288(t4,t3,t2);}

/* k3013 in drop! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3015,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3018,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:305: chicken.compiler.support#node-class-set! */
t3=*((C_word*)lf[19]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[20];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3016 in k3013 in drop! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3018,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3021,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:306: chicken.compiler.support#node-parameters-set! */
t3=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3019 in k3016 in k3013 in drop! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3021(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3021,c,av);}
/* lfa2.scm:307: chicken.compiler.support#node-subexpressions-set! */
t2=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3026(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_3026,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3134,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=t2,a[7]=t3,tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:310: chicken.compiler.support#node-parameters */
t5=*((C_word*)lf[15]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3033(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_3033,c,av);}
a=C_alloc(20);
t2=C_SCHEME_TRUE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3034,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t5=C_i_check_list_2(t1,lf[21]);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3051,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3105,a[2]=t8,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_3105(t10,t6,t1);}

/* g617 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3034(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3034,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3041,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:315: droppable? */
t4=((C_word*)((C_word*)t0)[4])[1];
f_2970(t4,t3,t2);}

/* k3039 in g617 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3041,c,av);}
if(C_truep(t1)){
/* lfa2.scm:316: drop! */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3011(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}
else{
t2=C_set_block_item(((C_word*)t0)[5],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3049 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3051(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3051,c,av);}
a=C_alloc(8);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
/* lfa2.scm:320: drop! */
t2=((C_word*)((C_word*)t0)[3])[1];
f_3011(t2,((C_word*)t0)[4],((C_word*)t0)[5]);}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3068,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3103,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:326: chicken.compiler.support#node-subexpressions */
t4=*((C_word*)lf[28]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k3066 in k3049 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3068,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* lfa2.scm:321: chicken.compiler.support#node-parameters-set! */
t3=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k3073 in k3101 in k3049 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3075,c,av);}
/* lfa2.scm:324: scheme#string-append */
t2=*((C_word*)lf[22]+1);{
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

/* k3101 in k3049 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3103,c,av);}
a=C_alloc(4);
t2=C_i_length(t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3075,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
switch(t2){
case C_fix(1):
/* lfa2.scm:324: scheme#string-append */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[23];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}
case C_fix(2):
/* lfa2.scm:324: scheme#string-append */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[24];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}
case C_fix(3):
/* lfa2.scm:324: scheme#string-append */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[25];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}
default:
/* lfa2.scm:330: chicken.compiler.support#bomb */
t4=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[27];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* for-each-loop616 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3105(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3105,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3115,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:313: g617 */
t4=((C_word*)t0)[3];
f_3034(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3113 in for-each-loop616 in k3031 in k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3115,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3105(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k3132 in extinguish! in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(42,c,2)))){
C_save_and_reclaim((void *)f_3134,c,av);}
a=C_alloc(42);
t2=(
/* lfa2.scm:310: report */
  f_2938(C_a_i(&a,35),((C_word*)((C_word*)t0)[2])[1],C_i_car(t1))
);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3033,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* lfa2.scm:311: chicken.compiler.support#node-subexpressions */
t4=*((C_word*)lf[28]+1);{
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

/* loop in k3314 in k3311 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_3151(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(lf[7]);}
else{
t2=C_i_cdar(t1);
t3=C_eqp(((C_word*)t0)[2],t2);
if(C_truep(t3)){
t4=C_u_i_car(t1);
t5=C_i_assq(C_u_i_car(t4),((C_word*)t0)[3]);
if(C_truep(t5)){
return(C_i_cdr(t5));}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}}

/* floatvar? in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_3197(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)((C_word*)t0)[2])[1]));}

/* eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3203(C_word t0,C_word t1,C_word t2){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_3203,3,t0,t1,t2);}
a=C_alloc(16);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3208,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3210,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t5=((C_word*)((C_word*)t0)[2])[1];
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2178,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t7=C_i_check_list_2(t5,lf[29]);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2088,a[2]=t6,a[3]=t9,tmp=(C_word)a,a+=4,tmp));
t11=((C_word*)t9)[1];
f_2088(t11,t3,t5);}

/* k3206 in eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3208,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a3209 in eliminate-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static C_word C_fcall f_3210(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_eqp(((C_word*)t0)[2],C_i_car(t1)));}

/* count-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3220(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_3220,5,t0,t1,t2,t3,t4);}
a=C_alloc(10);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?C_fix(1):C_i_car(t4));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3227,a[2]=t6,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f5456,a[2]=t7,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:343: chicken.compiler.support#node-class */
t9=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k3225 in count-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3227(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_3227,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3231,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:353: g682 */
t3=t2;
f_3231(t3,((C_word*)t0)[4],t1);}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* g682 in k3225 in count-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3231(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3231,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3239,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:357: acc */
t4=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3237 in g682 in k3225 in count-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3239,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3251,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:357: acc */
t3=((C_word*)t0)[4];{
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

/* k3249 in k3237 in g682 in k3225 in count-floatvar in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3251(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_3251,c,av);}
a=C_alloc(29);
t2=C_i_car(t1);
t3=C_s_a_i_plus(&a,2,((C_word*)t0)[2],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_set_car(((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3266 */
static void C_ccall f_3268(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3268,c,av);}
t2=((C_word*)t0)[2];
f_3227(t2,C_i_assq(C_i_car(t1),((C_word*)((C_word*)t0)[3])[1]));}

/* add-boxed in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3276(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_3276,3,t0,t1,t2);}
/* lfa2.scm:359: count-floatvar */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3220(t3,t1,t2,*((C_word*)lf[30]+1),C_SCHEME_END_OF_LIST);}

/* add-unboxed in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3282(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_3282,3,t0,t1,t2);}
/* lfa2.scm:360: count-floatvar */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3220(t3,t1,t2,*((C_word*)lf[31]+1),C_SCHEME_END_OF_LIST);}

/* sub-boxed in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3288(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_3288,3,t0,t1,t2);}
a=C_alloc(3);
/* lfa2.scm:361: count-floatvar */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3220(t3,t1,t2,*((C_word*)lf[30]+1),C_a_i_list(&a,1,C_fix(-1)));}

/* walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3294(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_3294,5,t0,t1,t2,t3,t4);}
a=C_alloc(15);
t5=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_3298,a[2]=t3,a[3]=t1,a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=t2,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[8],a[13]=((C_word*)t0)[9],a[14]=((C_word*)t0)[10],tmp=(C_word)a,a+=15,tmp);
/* lfa2.scm:364: chicken.compiler.support#node-class */
t6=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3298(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_3298,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_3301,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],tmp=(C_word)a,a+=16,tmp);
/* lfa2.scm:365: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_3301,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_3304,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],tmp=(C_word)a,a+=17,tmp);
/* lfa2.scm:366: chicken.compiler.support#node-subexpressions */
t3=*((C_word*)lf[28]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3304(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_3304,c,av);}
a=C_alloc(23);
t2=C_eqp(((C_word*)t0)[2],lf[11]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3313,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
t4=(
/* lfa2.scm:369: floatvar? */
  f_3197(((C_word*)((C_word*)t0)[9])[1],C_i_car(((C_word*)t0)[3]))
);
if(C_truep(t4)){
t5=C_i_car(((C_word*)t0)[3]);
if(C_truep(C_i_not(C_i_assq(t5,((C_word*)t0)[4])))){
/* lfa2.scm:371: eliminate-floatvar */
t6=((C_word*)((C_word*)t0)[10])[1];
f_3203(t6,t3,C_i_car(((C_word*)t0)[3]));}
else{
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_3313(2,av2);}}}
else{
t5=t3;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_3313(2,av2);}}}
else{
t3=C_eqp(((C_word*)t0)[2],lf[32]);
t4=(C_truep(t3)?t3:C_eqp(((C_word*)t0)[2],lf[33]));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3363,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[11],a[4]=((C_word*)t0)[12],a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:375: walk */
t6=((C_word*)((C_word*)t0)[12])[1];
f_3294(t6,t5,C_i_car(t1),((C_word*)t0)[4],((C_word*)t0)[6]);}
else{
t5=C_eqp(((C_word*)t0)[2],lf[36]);
if(C_truep(t5)){
t6=C_i_car(((C_word*)t0)[3]);
if(C_truep(C_i_stringp(t6))){
t7=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[37];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2769,a[2]=((C_word*)t0)[5],a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:256: chicken.keyword#keyword? */
t8=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}
else{
t6=C_eqp(((C_word*)t0)[2],lf[56]);
if(C_truep(t6)){
t7=C_i_car(t1);
t8=C_i_car(((C_word*)t0)[3]);
t9=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_3463,a[2]=t1,a[3]=t8,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[12],a[6]=((C_word*)t0)[5],a[7]=t7,a[8]=((C_word*)t0)[13],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[14],a[11]=((C_word*)t0)[15],a[12]=((C_word*)t0)[7],a[13]=((C_word*)t0)[9],tmp=(C_word)a,a+=14,tmp);
/* lfa2.scm:389: walk */
t10=((C_word*)((C_word*)t0)[12])[1];
f_3294(t10,t9,t7,((C_word*)t0)[4],((C_word*)t0)[6]);}
else{
t7=C_eqp(((C_word*)t0)[2],lf[57]);
t8=(C_truep(t7)?t7:C_eqp(((C_word*)t0)[2],lf[58]));
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3573,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:411: walk */
t10=((C_word*)((C_word*)t0)[12])[1];
f_3294(t10,t9,C_i_car(t1),C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);}
else{
t9=C_eqp(((C_word*)t0)[2],lf[60]);
t10=(C_truep(t9)?t9:C_eqp(((C_word*)t0)[2],lf[61]));
if(C_truep(t10)){
t11=C_i_car(t1);
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3592,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[12],a[4]=t11,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t13=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3598,a[2]=((C_word*)t0)[10],a[3]=t12,a[4]=t11,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[12],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f5489,a[2]=t13,a[3]=((C_word*)t0)[9],a[4]=t11,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:343: chicken.compiler.support#node-class */
t15=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t15;
av2[1]=t14;
av2[2]=t11;
((C_proc)(void*)(*((C_word*)t15+1)))(3,av2);}}
else{
t11=C_eqp(((C_word*)t0)[2],lf[20]);
if(C_truep(t11)){
t12=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t12;
av2[1]=lf[62];
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t12=C_eqp(((C_word*)t0)[2],lf[63]);
if(C_truep(t12)){
t13=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t13;
av2[1]=lf[59];
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}
else{
t13=C_eqp(((C_word*)t0)[2],lf[64]);
t14=(C_truep(t13)?t13:C_eqp(((C_word*)t0)[2],lf[65]));
if(C_truep(t14)){
t15=C_i_car(((C_word*)t0)[3]);
t16=C_i_assoc(t15,lf[3]);
t17=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3648,a[2]=t16,a[3]=((C_word*)t0)[15],a[4]=((C_word*)t0)[12],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t18=C_i_check_list_2(t1,lf[21]);
t19=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3664,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[16],a[4]=((C_word*)t0)[8],a[5]=t1,a[6]=((C_word*)t0)[12],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[5],tmp=(C_word)a,a+=10,tmp);
t20=C_SCHEME_UNDEFINED;
t21=(*a=C_VECTOR_TYPE|1,a[1]=t20,tmp=(C_word)a,a+=2,tmp);
t22=C_set_block_item(t21,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4118,a[2]=t21,a[3]=t17,tmp=(C_word)a,a+=4,tmp));
t23=((C_word*)t21)[1];
f_4118(t23,t19,t1);}
else{
t15=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4144,a[2]=((C_word*)t0)[12],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t16=C_i_check_list_2(t1,lf[21]);
t17=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4154,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
t18=C_SCHEME_UNDEFINED;
t19=(*a=C_VECTOR_TYPE|1,a[1]=t18,tmp=(C_word)a,a+=2,tmp);
t20=C_set_block_item(t19,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4156,a[2]=t19,a[3]=t15,tmp=(C_word)a,a+=4,tmp));
t21=((C_word*)t19)[1];
f_4156(t21,t17,t1);}}}}}}}}}}

/* k3311 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3313(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3313,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3316,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:372: add-boxed */
t3=((C_word*)((C_word*)t0)[6])[1];
f_3276(t3,t2,((C_word*)t0)[7]);}

/* k3314 in k3311 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3316,c,av);}
a=C_alloc(4);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_assq(t2,((C_word*)t0)[3]);
if(C_truep(t3)){
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_cdr(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3151,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=(
  f_3151(t4,((C_word*)t0)[5])
);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3363(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_3363,c,av);}
a=C_alloc(23);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3366,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_i_pairp(t1);
t4=(C_truep(t3)?C_eqp(lf[34],C_u_i_car(t1)):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3395,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],a[7]=t1,a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
t6=C_i_cadr(((C_word*)t0)[5]);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3419,a[2]=((C_word*)t0)[4],a[3]=t5,a[4]=t6,a[5]=((C_word*)t0)[7],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:378: scheme#append */
t8=*((C_word*)lf[35]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=C_i_cadr(t1);
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
t5=t2;
f_3366(t5,C_SCHEME_UNDEFINED);}}

/* k3364 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3366(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_3366,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3373,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:383: walk */
t3=((C_word*)((C_word*)t0)[4])[1];
f_3294(t3,t2,C_i_cadr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7]);}

/* k3371 in k3364 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3373,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3377,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:384: walk */
t3=((C_word*)((C_word*)t0)[4])[1];
f_3294(t3,t2,C_i_caddr(((C_word*)t0)[5]),((C_word*)t0)[6],((C_word*)t0)[7]);}

/* k3375 in k3371 in k3364 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3377,c,av);}
/* lfa2.scm:383: merge */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(
/* lfa2.scm:383: merge */
  f_2887(((C_word*)t0)[4],t1)
);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3393 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_3395,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3399,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_i_caddr(((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3407,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=t3,a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:381: scheme#append */
t5=*((C_word*)lf[35]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_caddr(((C_word*)t0)[7]);
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k3397 in k3393 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3399(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3399,c,av);}
/* lfa2.scm:377: merge */
t2=((C_word*)t0)[2];
f_3366(t2,(
/* lfa2.scm:377: merge */
  f_2887(((C_word*)t0)[4],t1)
));}

/* k3405 in k3393 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3407,c,av);}
/* lfa2.scm:380: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3294(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5]);}

/* k3417 in k3361 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3419,c,av);}
/* lfa2.scm:377: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3294(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5]);}

/* k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3463(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3463,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_3466,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
/* lfa2.scm:390: assigned? */
t3=((C_word*)((C_word*)t0)[8])[1];
f_2964(t3,t2,((C_word*)t0)[3]);}

/* k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3466(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,2)))){
C_save_and_reclaim((void *)f_3466,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3469,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3531,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[11],a[4]=((C_word*)t0)[12],a[5]=t2,a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[13],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_not(t1))){
t4=C_eqp(lf[43],((C_word*)t0)[10]);
if(C_truep(t4)){
t5=(
/* lfa2.scm:393: floatvar? */
  f_3197(((C_word*)((C_word*)t0)[14])[1],((C_word*)t0)[3])
);
t6=t3;
f_3531(t6,C_i_not(t5));}
else{
t5=t3;
f_3531(t5,C_SCHEME_FALSE);}}
else{
t4=t3;
f_3531(t4,C_SCHEME_FALSE);}}

/* k3467 in k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3469(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_3469,c,av);}
a=C_alloc(16);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3480,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t2,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
if(C_truep(((C_word*)t0)[8])){
t4=t3;
f_3480(t4,((C_word*)t0)[10]);}
else{
t4=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[11]);
t5=t3;
f_3480(t5,C_a_i_cons(&a,2,t4,((C_word*)t0)[10]));}}

/* k3478 in k3467 in k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3480(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_3480,2,t0,t1);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3487,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f5477,a[2]=((C_word*)t0)[8],a[3]=t2,a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[7],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:343: chicken.compiler.support#node-class */
t4=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3485 in k3478 in k3467 in k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3487(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_3487,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3501,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:404: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
/* lfa2.scm:397: walk */
t2=((C_word*)((C_word*)t0)[4])[1];
f_3294(t2,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[3]);}}

/* k3499 in k3485 in k3478 in k3467 in k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3501(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_3501,c,av);}
a=C_alloc(12);
t2=C_i_car(t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[3]);
t5=C_a_i_cons(&a,2,((C_word*)t0)[2],t2);
t6=C_a_i_cons(&a,2,t5,t4);
/* lfa2.scm:397: walk */
t7=((C_word*)((C_word*)t0)[4])[1];
f_3294(t7,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t6);}

/* k3515 */
static void C_ccall f_3517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3517,c,av);}
t2=((C_word*)t0)[2];
f_3487(t2,C_i_not(t1));}

/* k3523 */
static void C_ccall f_3525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3525,c,av);}
/* lfa2.scm:403: assigned? */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2964(t2,((C_word*)t0)[3],C_i_car(t1));}

/* k3529 in k3464 in k3461 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3531(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_3531,2,t0,t1);}
a=C_alloc(12);
if(C_truep(t1)){
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],C_fix(0),C_fix(0));
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[3])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
/* lfa2.scm:395: add-unboxed */
t5=((C_word*)((C_word*)t0)[4])[1];
f_3282(t5,((C_word*)t0)[5],((C_word*)t0)[6]);}
else{
/* lfa2.scm:396: add-boxed */
t2=((C_word*)((C_word*)t0)[7])[1];
f_3276(t2,((C_word*)t0)[5],((C_word*)t0)[6]);}}

/* k3571 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3573(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3573,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[59];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3590 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3592(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3592,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3595,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:418: walk */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3294(t3,t2,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k3593 in k3590 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3595,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[62];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3596 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3598(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,4)))){
C_save_and_reclaim_args((void *)trf_3598,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3609,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:417: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f5398,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:418: walk */
t3=((C_word*)((C_word*)t0)[6])[1];
f_3294(t3,t2,((C_word*)t0)[4],((C_word*)t0)[7],((C_word*)t0)[8]);}}

/* k3607 in k3596 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3609,c,av);}
/* lfa2.scm:417: eliminate-floatvar */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3203(t2,((C_word*)t0)[3],C_i_car(t1));}

/* k3621 */
static void C_ccall f_3623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3623,c,av);}
/* lfa2.scm:416: floatvar? */
t2=((C_word*)t0)[2];
f_3598(t2,(
/* lfa2.scm:416: floatvar? */
  f_3197(((C_word*)((C_word*)t0)[3])[1],C_i_car(t1))
));}

/* g742 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3648(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_3648,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3652,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:426: walk */
t4=((C_word*)((C_word*)t0)[4])[1];
f_3294(t4,t3,t2,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k3650 in g742 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3652,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* lfa2.scm:427: add-unboxed */
t2=((C_word*)((C_word*)t0)[3])[1];
f_3282(t2,((C_word*)t0)[4],((C_word*)t0)[5]);}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3664(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_3664,c,av);}
a=C_alloc(8);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_assoc(t2,lf[66]);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3671,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:429: g764 */
t5=t4;
f_3671(t5,((C_word*)t0)[9],t3);}
else{
t4=C_i_car(((C_word*)t0)[2]);
t5=C_i_assoc(t4,lf[73]);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3801,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* lfa2.scm:429: g779 */
t7=t6;
f_3801(t7,((C_word*)t0)[9],t5);}
else{
t6=C_i_car(((C_word*)t0)[2]);
t7=C_i_assoc(t6,lf[74]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3849,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:429: g788 */
t9=t8;
f_3849(t9,((C_word*)t0)[9],t7);}
else{
t8=C_i_car(((C_word*)t0)[2]);
t9=C_i_assoc(t8,lf[78]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4045,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:429: g815 */
t11=t10;
f_4045(t11,((C_word*)t0)[9],t9);}
else{
t10=C_SCHEME_UNDEFINED;
t11=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}}}}

/* g764 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3671(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_3671,3,t0,t1,t2);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3675,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t2,a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* lfa2.scm:431: walk */
t4=((C_word*)((C_word*)t0)[5])[1];
f_3294(t4,t3,C_i_car(((C_word*)t0)[4]),((C_word*)t0)[6],((C_word*)t0)[7]);}

/* k3673 in g764 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3675(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_3675,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3678,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(*((C_word*)lf[67]+1))){
/* lfa2.scm:433: extinguish! */
t3=((C_word*)((C_word*)t0)[3])[1];
f_3026(t3,t2,((C_word*)t0)[4],lf[68]);}
else{
t3=C_i_cadr(((C_word*)t0)[5]);
t4=C_eqp(lf[69],t3);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3693,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_pairp(t1))){
t6=C_i_car(t1);
t7=C_eqp(lf[6],t6);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3739,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:438: chicken.compiler.support#node-class */
t9=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cadr(((C_word*)t0)[6]);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t8=t5;
f_3693(t8,C_SCHEME_FALSE);}}
else{
t6=t5;
f_3693(t6,C_SCHEME_FALSE);}}
else{
t5=C_i_pairp(t1);
t6=(C_truep(t5)?C_eqp(lf[34],C_u_i_car(t1)):C_SCHEME_FALSE);
if(C_truep(t6)){
if(C_truep(C_i_memq(lf[34],C_u_i_cdr(((C_word*)t0)[5])))){
/* lfa2.scm:445: extinguish! */
t7=((C_word*)((C_word*)t0)[3])[1];
f_3026(t7,t2,((C_word*)t0)[4],lf[71]);}
else{
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
if(C_truep(C_i_member(t1,C_u_i_cdr(((C_word*)t0)[5])))){
/* lfa2.scm:448: extinguish! */
t7=((C_word*)((C_word*)t0)[3])[1];
f_3026(t7,t2,((C_word*)t0)[4],lf[72]);}
else{
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}}}}

/* k3676 in k3673 in g764 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3678(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3678,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3691 in k3673 in g764 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3693(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_3693,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3719,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* lfa2.scm:439: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[7]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[6];{
C_word av2[2];
av2[0]=t2;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3717 in k3691 in k3673 in g764 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3719,c,av);}
t2=C_i_car(t1);
if(C_truep(C_i_symbolp(t2))){
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_eqp(t2,t3);
if(C_truep(t4)){
/* lfa2.scm:442: extinguish! */
t5=((C_word*)((C_word*)t0)[3])[1];
f_3026(t5,((C_word*)t0)[4],((C_word*)t0)[5],lf[70]);}
else{
t5=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t5;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3737 in k3673 in g764 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3739(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3739,c,av);}
t2=((C_word*)t0)[2];
f_3693(t2,C_eqp(lf[36],t1));}

/* g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3801(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_3801,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_car(((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3808,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:453: walk */
t5=((C_word*)((C_word*)t0)[4])[1];
f_3294(t5,t4,t3,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3808(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_3808,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3811,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_i_cdr(((C_word*)t0)[3]);
if(C_truep(C_i_member(t1,t3))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3817,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3835,a[2]=t4,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:455: chicken.compiler.support#node-class */
t6=*((C_word*)lf[16]+1);{
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
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3809 in k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3811(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3811,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3815 in k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3817(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_3817,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3820,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3831,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:456: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[15]+1);{
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

/* k3818 in k3815 in k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3820(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3820,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3827,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:457: chicken.compiler.support#node-subexpressions */
t3=*((C_word*)lf[28]+1);{
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

/* k3825 in k3818 in k3815 in k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3827,c,av);}
/* lfa2.scm:457: chicken.compiler.support#node-subexpressions-set! */
t2=*((C_word*)lf[17]+1);{
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

/* k3829 in k3815 in k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3831,c,av);}
/* lfa2.scm:456: chicken.compiler.support#node-parameters-set! */
t2=*((C_word*)lf[18]+1);{
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

/* k3833 in k3806 in g779 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_3835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3835,c,av);}
/* lfa2.scm:455: chicken.compiler.support#node-class-set! */
t2=*((C_word*)lf[19]+1);{
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

/* g788 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_3849(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_3849,3,t0,t1,t2);}
a=C_alloc(11);
t3=C_i_car(((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f5496,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t3,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],tmp=(C_word)a,a+=11,tmp);
/* lfa2.scm:343: chicken.compiler.support#node-class */
t5=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3901 in k3909 in k3924 */
static void C_ccall f_3903(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_3903,c,av);}
a=C_alloc(21);
t2=C_i_car(t1);
if(C_truep(C_i_symbolp(t2))){
t3=C_a_i_list(&a,2,lf[6],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],t3);
t5=C_a_i_list(&a,1,t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[34],t5,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],lf[6]);
t4=C_a_i_list(&a,1,t3);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[34],t4,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k3909 in k3924 */
static void C_ccall f_3911(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3911,c,av);}
a=C_alloc(15);
t2=C_eqp(lf[36],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3903,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:471: chicken.compiler.support#node-parameters */
t4=*((C_word*)lf[15]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],lf[6]);
t4=C_a_i_list(&a,1,t3);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[34],t4,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k3924 */
static void C_ccall f_3926(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3926,c,av);}
a=C_alloc(15);
t2=C_i_car(t1);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_eqp(lf[69],t3);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3911,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:469: chicken.compiler.support#node-class */
t6=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_cadr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_i_cadr(((C_word*)t0)[2]);
t6=C_a_i_cons(&a,2,t2,t5);
t7=C_a_i_list(&a,1,t6);
t8=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,3,lf[34],t7,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k3927 */
static void C_ccall f_3929(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_3929,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3932,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_i_cadr(((C_word*)t0)[3]);
t4=C_eqp(lf[69],t3);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3941,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_pairp(t1))){
t6=C_i_car(t1);
t7=C_eqp(lf[6],t6);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3987,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:485: chicken.compiler.support#node-class */
t9=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_cadr(((C_word*)t0)[6]);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t8=t5;
f_3941(t8,C_SCHEME_FALSE);}}
else{
t6=t5;
f_3941(t6,C_SCHEME_FALSE);}}
else{
t5=C_i_pairp(t1);
t6=(C_truep(t5)?C_eqp(lf[34],C_u_i_car(t1)):C_SCHEME_FALSE);
if(C_truep(t6)){
if(C_truep(C_i_memq(lf[34],C_u_i_cdr(((C_word*)t0)[3])))){
/* lfa2.scm:493: extinguish! */
t7=((C_word*)((C_word*)t0)[4])[1];
f_3026(t7,t2,((C_word*)t0)[5],lf[76]);}
else{
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
if(C_truep(C_i_member(t1,C_u_i_cdr(((C_word*)t0)[3])))){
/* lfa2.scm:496: extinguish! */
t7=((C_word*)((C_word*)t0)[4])[1];
f_3026(t7,t2,((C_word*)t0)[5],lf[77]);}
else{
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}}}

/* k3930 in k3927 */
static void C_ccall f_3932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3932,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3939 in k3927 */
static void C_fcall f_3941(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_3941,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3967,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* lfa2.scm:487: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[7]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[6];{
C_word av2[2];
av2[0]=t2;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3965 in k3939 in k3927 */
static void C_ccall f_3967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3967,c,av);}
t2=C_i_car(t1);
if(C_truep(C_i_symbolp(t2))){
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_eqp(t2,t3);
if(C_truep(t4)){
/* lfa2.scm:490: extinguish! */
t5=((C_word*)((C_word*)t0)[3])[1];
f_3026(t5,((C_word*)t0)[4],((C_word*)t0)[5],lf[75]);}
else{
t5=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t5;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[34];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3985 in k3927 */
static void C_ccall f_3987(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3987,c,av);}
t2=((C_word*)t0)[2];
f_3941(t2,C_eqp(lf[36],t1));}

/* g815 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4045(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_4045,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_i_pairp(((C_word*)t0)[2]);
t4=(C_truep(t3)?C_i_car(((C_word*)t0)[2]):C_SCHEME_FALSE);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4055,a[2]=t1,a[3]=t4,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t4)){
t6=C_i_cadr(t2);
t7=C_eqp(lf[69],t6);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4087,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:503: chicken.compiler.support#node-class */
t9=*((C_word*)lf[16]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t8=t5;
f_4055(t8,C_SCHEME_FALSE);}}
else{
t6=t5;
f_4055(t6,C_SCHEME_FALSE);}}

/* k4053 in g815 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4055(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_4055,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4071,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:504: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_i_cadr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k4069 in k4053 in g815 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4071,c,av);}
a=C_alloc(6);
t2=C_i_car(t1);
t3=C_i_symbolp(t2);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_a_i_list(&a,2,lf[6],t2):lf[6]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k4085 in g815 in k3662 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4087,c,av);}
t2=((C_word*)t0)[2];
f_4055(t2,C_eqp(lf[36],t1));}

/* for-each-loop741 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4118(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4118,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4128,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:424: g742 */
t4=((C_word*)t0)[3];
f_3648(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4126 in for-each-loop741 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4128,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4118(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* g830 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4144(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_4144,3,t0,t1,t2);}
/* lfa2.scm:510: g845 */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3294(t3,t1,t2,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k4152 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4154(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4154,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[7];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop829 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4156(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4156,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4166,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:510: g830 */
t4=((C_word*)t0)[3];
f_4144(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4164 in for-each-loop829 in k3302 in k3299 in k3296 in walk in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4166,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4156(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4218,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4221,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[4])[1]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4229,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:515: chicken.compiler.support#with-debugging-output */
t4=*((C_word*)lf[87]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[88];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4219 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4221,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4229,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4233,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:518: chicken.base#print */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[86];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4233(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4233,c,av);}
a=C_alloc(5);
t2=((C_word*)((C_word*)t0)[2])[1];
t3=C_i_check_list_2(t2,lf[21]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4267,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_4267(t7,((C_word*)t0)[3],t2);}

/* k4239 in for-each-loop855 in k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4241(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4241,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4244,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:520: ##sys#print */
t3=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[4]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4242 in k4239 in for-each-loop855 in k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4244(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4244,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4247,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:520: ##sys#print */
t3=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[83];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4245 in k4242 in k4239 in for-each-loop855 in k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4247(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4247,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4250,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:520: ##sys#print */
t3=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_cdr(((C_word*)t0)[4]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4248 in k4245 in k4242 in k4239 in for-each-loop855 in k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4250,c,av);}
/* lfa2.scm:520: ##sys#write-char-0 */
t2=*((C_word*)lf[81]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* for-each-loop855 in k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4267(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_4267,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4277,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[79]+1);
t6=*((C_word*)lf[79]+1);
t7=C_i_check_port_2(*((C_word*)lf[79]+1),C_fix(2),C_SCHEME_TRUE,lf[80]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4241,a[2]=t3,a[3]=t5,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:520: ##sys#print */
t9=*((C_word*)lf[82]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[84];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[79]+1);
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4275 in for-each-loop855 in k4231 in a4228 in k4216 in chicken.compiler.lfa2#perform-secondary-flow-analysis in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4277(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4277,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4267(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4290(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_4290,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4294,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t5=C_i_check_list_2(t3,lf[29]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2132,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_2132(t9,t4,t3);}

/* k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4294(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_4294,c,av);}
a=C_alloc(23);
t2=C_fix(0);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4296,a[2]=t1,a[3]=t3,a[4]=t5,a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t9=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4523,a[2]=t1,a[3]=t7,a[4]=t5,a[5]=t3,tmp=(C_word)a,a+=6,tmp));
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4864,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:606: walk */
t11=((C_word*)t7)[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t10;
av2[2]=((C_word*)t0)[3];
f_4523(3,av2);}}

/* walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4296,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4300,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:534: chicken.compiler.support#node-class */
t4=*((C_word*)lf[16]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4300,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4303,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* lfa2.scm:535: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
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

/* k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4303,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4306,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* lfa2.scm:536: chicken.compiler.support#node-subexpressions */
t3=*((C_word*)lf[28]+1);{
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

/* k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4306(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,4)))){
C_save_and_reclaim((void *)f_4306,c,av);}
a=C_alloc(21);
t2=C_eqp(((C_word*)t0)[2],lf[36]);
if(C_truep(t2)){
t3=C_i_car(((C_word*)t0)[3]);
if(C_truep(C_i_flonump(t3))){
t4=C_a_i_list1(&a,1,t3);
/* lfa2.scm:541: chicken.compiler.support#make-node */
t5=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[91];
av2[3]=t4;
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=C_eqp(((C_word*)t0)[2],lf[11]);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4334,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:544: posq */
f_2682(t4,C_i_car(((C_word*)t0)[3]),((C_word*)t0)[6]);}
else{
t4=C_eqp(((C_word*)t0)[2],lf[64]);
t5=(C_truep(t4)?t4:C_eqp(((C_word*)t0)[2],lf[65]));
if(C_truep(t5)){
t6=C_i_car(((C_word*)t0)[3]);
t7=C_i_assoc(t6,lf[3]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4371,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:549: g929 */
t9=t8;
f_4371(t9,((C_word*)t0)[4],t7);}
else{
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4451,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
t9=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t10=t9;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=((C_word*)t11)[1];
t13=C_i_check_list_2(t1,lf[95]);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4461,a[2]=t8,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4463,a[2]=t11,a[3]=t16,a[4]=((C_word*)t0)[9],a[5]=t12,tmp=(C_word)a,a+=6,tmp));
t18=((C_word*)t16)[1];
f_4463(t18,t14,t1);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4510,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* lfa2.scm:564: walk */
t7=((C_word*)((C_word*)t0)[9])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[5];
f_4523(3,av2);}}}}}

/* k4332 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4334,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* lfa2.scm:546: chicken.compiler.support#make-node */
t3=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[92];
av2[3]=t2;
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t2=C_a_i_list1(&a,1,((C_word*)t0)[4]);
/* lfa2.scm:547: chicken.compiler.support#make-node */
t3=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[93];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* g929 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4371(C_word t0,C_word t1,C_word t2){
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
C_word t19;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(49,0,3)))){
C_save_and_reclaim_args((void *)trf_4371,3,t0,t1,t2);}
a=C_alloc(49);
t3=C_i_cadr(t2);
t4=C_i_caddr(t2);
t5=((C_word*)((C_word*)t0)[2])[1];
t6=C_mutate(((C_word *)((C_word*)t0)[2])+1,C_s_a_i_plus(&a,2,t5,C_fix(1)));
t7=C_a_i_list1(&a,1,t3);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_eqp(t4,lf[94]);
t13=(C_truep(t12)?((C_word*)((C_word*)t0)[3])[1]:((C_word*)((C_word*)t0)[4])[1]);
t14=C_i_check_list_2(((C_word*)t0)[5],lf[95]);
t15=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4400,a[2]=t1,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4402,a[2]=t10,a[3]=t17,a[4]=t13,a[5]=t11,tmp=(C_word)a,a+=6,tmp));
t19=((C_word*)t17)[1];
f_4402(t19,t15,((C_word*)t0)[5]);}

/* k4398 in g929 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4400,c,av);}
/* lfa2.scm:554: chicken.compiler.support#make-node */
t2=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[64];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* map-loop936 in g929 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4402(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4402,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4427,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:556: g942 */
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

/* k4425 in map-loop936 in g929 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4427,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4402(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4449 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4451,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* lfa2.scm:561: chicken.compiler.support#make-node */
t3=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[93];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4459 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4461(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4461,c,av);}
/* lfa2.scm:562: chicken.compiler.support#make-node */
t2=*((C_word*)lf[90]+1);{
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

/* map-loop963 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4463(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4463,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4488,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:563: g969 */
t4=((C_word*)((C_word*)t0)[4])[1];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_4523(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4486 in map-loop963 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4488,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4463(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4508 in k4304 in k4301 in k4298 in walk/unbox in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4510,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* lfa2.scm:564: chicken.compiler.support#make-node */
t3=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[93];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4523(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4523,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4527,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
/* lfa2.scm:567: chicken.compiler.support#node-class */
t4=*((C_word*)lf[16]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_4527,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4530,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* lfa2.scm:568: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[15]+1);{
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

/* k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4530(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4530,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4533,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* lfa2.scm:569: chicken.compiler.support#node-subexpressions */
t3=*((C_word*)lf[28]+1);{
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

/* k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4533(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_4533,c,av);}
a=C_alloc(18);
t2=C_eqp(((C_word*)t0)[2],lf[11]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4542,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:572: posq */
f_2682(t3,C_i_car(((C_word*)t0)[4]),((C_word*)t0)[6]);}
else{
t3=C_eqp(((C_word*)t0)[2],lf[56]);
if(C_truep(t3)){
t4=C_i_car(t1);
t5=C_i_car(((C_word*)t0)[4]);
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4579,a[2]=t5,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=t1,a[6]=((C_word*)t0)[8],a[7]=t4,a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
/* lfa2.scm:581: posq */
f_2682(t6,t5,((C_word*)t0)[6]);}
else{
t4=C_eqp(((C_word*)t0)[2],lf[64]);
t5=(C_truep(t4)?t4:C_eqp(((C_word*)t0)[2],lf[65]));
if(C_truep(t5)){
t6=C_i_car(((C_word*)t0)[4]);
t7=C_i_assoc(t6,lf[3]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4668,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:588: g1036 */
t9=t8;
f_4668(t9,((C_word*)t0)[3],t7);}
else{
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_i_check_list_2(t1,lf[95]);
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4765,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4767,a[2]=t10,a[3]=t15,a[4]=((C_word*)t0)[7],a[5]=t11,tmp=(C_word)a,a+=6,tmp));
t17=((C_word*)t15)[1];
f_4767(t17,t13,t1);}}
else{
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_i_check_list_2(t1,lf[95]);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4816,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4818,a[2]=t8,a[3]=t13,a[4]=((C_word*)t0)[7],a[5]=t9,tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_4818(t15,t11,t1);}}}}

/* k4540 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4542(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4542,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4556,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_a_i_cons(&a,2,t1,((C_word*)t0)[3]);
/* lfa2.scm:575: chicken.compiler.support#make-node */
t4=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[92];
av2[3]=t3;
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k4554 in k4540 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4556,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* lfa2.scm:574: chicken.compiler.support#make-node */
t3=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[96];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4577 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4579(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_4579,c,av);}
a=C_alloc(17);
if(C_truep(t1)){
t2=C_a_i_list2(&a,2,t1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4597,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:584: walk/unbox */
t4=((C_word*)((C_word*)t0)[6])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
f_4296(3,av2);}}
else{
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[5],lf[95]);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4618,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4620,a[2]=t4,a[3]=t9,a[4]=((C_word*)t0)[4],a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_4620(t11,t7,((C_word*)t0)[5]);}}

/* k4595 in k4577 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4597,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4601,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:585: walk */
t3=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[5]);
f_4523(3,av2);}}

/* k4599 in k4595 in k4577 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4601,c,av);}
a=C_alloc(6);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
/* lfa2.scm:583: chicken.compiler.support#make-node */
t3=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[97];
av2[3]=((C_word*)t0)[4];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4616 in k4577 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4618,c,av);}
/* lfa2.scm:586: chicken.compiler.support#make-node */
t2=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[56];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* map-loop1003 in k4577 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4620(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4620,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4645,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:586: g1009 */
t4=((C_word*)((C_word*)t0)[4])[1];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_4523(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4643 in map-loop1003 in k4577 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4645,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4620(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* g1036 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4668(C_word t0,C_word t1,C_word t2){
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
C_word t19;
C_word t20;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(53,0,3)))){
C_save_and_reclaim_args((void *)trf_4668,3,t0,t1,t2);}
a=C_alloc(53);
t3=C_i_cadr(t2);
t4=C_i_caddr(t2);
t5=((C_word*)((C_word*)t0)[2])[1];
t6=C_mutate(((C_word *)((C_word*)t0)[2])+1,C_s_a_i_plus(&a,2,t5,C_fix(1)));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4680,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t8=C_a_i_list1(&a,1,t3);
t9=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t10=t9;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=((C_word*)t11)[1];
t13=C_eqp(t4,lf[99]);
t14=(C_truep(t13)?((C_word*)((C_word*)t0)[3])[1]:((C_word*)((C_word*)t0)[4])[1]);
t15=C_i_check_list_2(((C_word*)t0)[5],lf[95]);
t16=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4712,a[2]=t7,a[3]=t8,tmp=(C_word)a,a+=4,tmp);
t17=C_SCHEME_UNDEFINED;
t18=(*a=C_VECTOR_TYPE|1,a[1]=t17,tmp=(C_word)a,a+=2,tmp);
t19=C_set_block_item(t18,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4714,a[2]=t11,a[3]=t18,a[4]=t14,a[5]=t12,tmp=(C_word)a,a+=6,tmp));
t20=((C_word*)t18)[1];
f_4714(t20,t16,((C_word*)t0)[5]);}

/* k4678 in g1036 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4680,c,av);}
a=C_alloc(3);
t2=C_eqp(((C_word*)t0)[2],lf[98]);
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_a_i_list1(&a,1,t1);
/* lfa2.scm:601: chicken.compiler.support#make-node */
t4=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[96];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k4710 in g1036 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4712,c,av);}
/* lfa2.scm:593: chicken.compiler.support#make-node */
t2=*((C_word*)lf[90]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[64];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* map-loop1044 in g1036 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4714(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4714,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4739,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:595: g1050 */
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

/* k4737 in map-loop1044 in g1036 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4739(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4739,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4714(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4763 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4765,c,av);}
/* lfa2.scm:603: chicken.compiler.support#make-node */
t2=*((C_word*)lf[90]+1);{
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

/* map-loop1077 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4767(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4767,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4792,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:603: g1083 */
t4=((C_word*)((C_word*)t0)[4])[1];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_4523(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4790 in map-loop1077 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4792,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4767(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4814 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4816,c,av);}
/* lfa2.scm:604: chicken.compiler.support#make-node */
t2=*((C_word*)lf[90]+1);{
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

/* map-loop1103 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_fcall f_4818(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4818,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4843,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:604: g1109 */
t4=((C_word*)((C_word*)t0)[4])[1];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_4523(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4841 in map-loop1103 in k4531 in k4528 in k4525 in walk in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4843,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_4818(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4864(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4864,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4867,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4869,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:607: chicken.compiler.support#with-debugging-output */
t4=*((C_word*)lf[87]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[102];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k4865 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4867,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a4868 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4869,c,av);}
a=C_alloc(6);
t2=*((C_word*)lf[79]+1);
t3=*((C_word*)lf[79]+1);
t4=C_i_check_port_2(*((C_word*)lf[79]+1),C_fix(2),C_SCHEME_TRUE,lf[80]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4876,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* lfa2.scm:610: ##sys#print */
t6=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[101];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[79]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4874 in a4868 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4876(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4876,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4879,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:610: ##sys#print */
t3=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_length(((C_word*)t0)[5]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4877 in k4874 in a4868 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4879,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4882,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:610: ##sys#write-char-0 */
t3=*((C_word*)lf[81]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4880 in k4877 in k4874 in a4868 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4882,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[79]+1);
t3=*((C_word*)lf[79]+1);
t4=C_i_check_port_2(*((C_word*)lf[79]+1),C_fix(2),C_SCHEME_TRUE,lf[80]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4888,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* lfa2.scm:612: ##sys#print */
t6=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[100];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[79]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4886 in k4880 in k4877 in k4874 in a4868 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4888,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4891,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* lfa2.scm:612: ##sys#print */
t3=*((C_word*)lf[82]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4889 in k4886 in k4880 in k4877 in k4874 in a4868 in k4862 in k4292 in chicken.compiler.lfa2#perform-unboxing in k1466 in k1463 in k1460 in k1457 */
static void C_ccall f_4891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4891,c,av);}
/* lfa2.scm:612: ##sys#write-char-0 */
t2=*((C_word*)lf[81]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_lfa2_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("lfa2"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_lfa2_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(3770))){
C_save(t1);
C_rereclaim2(3770*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,103);
lf[0]=C_h_intern(&lf[0],4, C_text("lfa2"));
lf[1]=C_h_intern(&lf[1],22, C_text("chicken.compiler.lfa2#"));
lf[4]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_plus\376\003\000\000\002\376B\000\000\022C_ub_i_flonum_plus\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000"
"\002\376\003\000\000\002\376B\000\000\027C_a_i_flonum_difference\376\003\000\000\002\376B\000\000\030C_ub_i_flonum_difference\376\003\000\000\002\376\001\000\000\002\001o"
"p\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_times\376\003\000\000\002\376B\000\000\023C_ub_i_flonum_times\376\003\000\000\002\376\001\000\000\002\001op\376"
"\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\031C_a_i_flonum_multiply_add\376\003\000\000\002\376B\000\000\032C_ub_i_flonum_multiply_add\376\003"
"\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_a_i_flonum_quotient\376\003\000\000\002\376B\000\000\026C_ub_i_flonum_quotie"
"nt\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\017C_flonum_equalp\376\003\000\000\002\376B\000\000\024C_ub_i_flonum_equalp\376\003"
"\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_flonum_greaterp\376\003\000\000\002\376B\000\000\026C_ub_i_flonum_greaterp"
"\376\003\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\016C_flonum_lessp\376\003\000\000\002\376B\000\000\023C_ub_i_flonum_lessp\376\003\000\000"
"\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\033C_flonum_greater_or_equal_p\376\003\000\000\002\376B\000\000 C_ub_i_flonum_"
"greater_or_equal_p\376\003\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\030C_flonum_less_or_equal_p\376\003\000\000\002"
"\376B\000\000\035C_ub_i_flonum_less_or_equal_p\376\003\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_u_i_flonum_"
"nanp\376\003\000\000\002\376B\000\000\022C_ub_i_flonum_nanp\376\003\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\026C_u_i_flonum_in"
"finitep\376\003\000\000\002\376B\000\000\027C_ub_i_flonum_infinitep\376\003\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_u_i_f"
"lonum_finitepp\376\003\000\000\002\376B\000\000\025C_ub_i_flonum_finitep\376\003\000\000\002\376\001\000\000\004\001pred\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_"
"a_i_flonum_sin\376\003\000\000\002\376B\000\000\005C_sin\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flonum_cos\376\003\000\000"
"\002\376B\000\000\005C_cos\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flonum_tan\376\003\000\000\002\376B\000\000\005C_tan\376\003\000\000\002\376\001"
"\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_asin\376\003\000\000\002\376B\000\000\006C_asin\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003"
"\000\000\002\376B\000\000\021C_a_i_flonum_acos\376\003\000\000\002\376B\000\000\006C_acos\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_fl"
"onum_atan\376\003\000\000\002\376B\000\000\006C_atan\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_atan2\376\003\000\000\002\376"
"B\000\000\007C_atan2\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_sinh\376\003\000\000\002\376B\000\000\006C_sinh\376\003\000\000\002"
"\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_cosh\376\003\000\000\002\376B\000\000\006C_cosh\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002"
"\376\003\000\000\002\376B\000\000\021C_a_i_flonum_tanh\376\003\000\000\002\376B\000\000\006C_tanh\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_"
"flonum_asinh\376\003\000\000\002\376B\000\000\007C_asinh\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_acosh\376\003"
"\000\000\002\376B\000\000\007C_acosh\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_atanh\376\003\000\000\002\376B\000\000\007C_atan"
"h\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flonum_exp\376\003\000\000\002\376B\000\000\005C_exp\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376"
"\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_expr\376\003\000\000\002\376B\000\000\005C_pow\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a"
"_i_flonum_log\376\003\000\000\002\376B\000\000\005C_log\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_sqrt\376\003\000\000"
"\002\376B\000\000\006C_sqrt\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_a_i_flonum_truncate\376\003\000\000\002\376B\000\000\007C_trun"
"c\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\024C_a_i_flonum_ceiling\376\003\000\000\002\376B\000\000\006C_ceil\376\003\000\000\002\376\001\000\000\002\001o"
"p\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_floor\376\003\000\000\002\376B\000\000\007C_floor\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002"
"\376B\000\000\022C_a_i_flonum_round\376\003\000\000\002\376B\000\000\007C_round\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flo"
"num_abs\376\003\000\000\002\376B\000\000\006C_fabs\376\003\000\000\002\376\001\000\000\002\001op\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_a_u_i_f32vector_ref\376\003\000\000\002"
"\376B\000\000\024C_ub_i_f32vector_ref\376\003\000\000\002\376\001\000\000\003\001acc\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_a_u_i_f64vector_ref\376\003"
"\000\000\002\376B\000\000\024C_ub_i_f64vector_ref\376\003\000\000\002\376\001\000\000\003\001acc\376\377\016\376\377\016"));
lf[5]=C_h_intern(&lf[5],53, C_text("chicken.compiler.lfa2#perform-secondary-flow-analysis"));
lf[6]=C_h_intern(&lf[6],6, C_text("struct"));
lf[7]=C_h_intern(&lf[7],1, C_text("\052"));
lf[8]=C_h_intern(&lf[8],31, C_text("chicken.compiler.support#db-get"));
lf[9]=C_h_intern(&lf[9],8, C_text("assigned"));
lf[10]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\005\001quote\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\003\000\000\002\376\001\000\000\020\001##core#primitive\376\003\000\000\002\376\001\000\000\015"
"\001##core#lambda\376\377\016"));
lf[11]=C_h_intern(&lf[11],15, C_text("##core#variable"));
lf[12]=C_h_intern(&lf[12],38, C_text("chicken.compiler.support#variable-mark"));
lf[13]=C_h_intern(&lf[13],23, C_text("##compiler#always-bound"));
lf[14]=C_h_intern(&lf[14],6, C_text("global"));
lf[15]=C_h_intern(&lf[15],40, C_text("chicken.compiler.support#node-parameters"));
lf[16]=C_h_intern(&lf[16],35, C_text("chicken.compiler.support#node-class"));
lf[17]=C_h_intern(&lf[17],49, C_text("chicken.compiler.support#node-subexpressions-set!"));
lf[18]=C_h_intern(&lf[18],45, C_text("chicken.compiler.support#node-parameters-set!"));
lf[19]=C_h_intern(&lf[19],40, C_text("chicken.compiler.support#node-class-set!"));
lf[20]=C_h_intern(&lf[20],16, C_text("##core#undefined"));
lf[21]=C_h_intern(&lf[21],8, C_text("for-each"));
lf[22]=C_h_intern(&lf[22],20, C_text("scheme#string-append"));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0011"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0012"));
lf[25]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0013"));
lf[26]=C_h_intern(&lf[26],29, C_text("chicken.compiler.support#bomb"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376B\000\0005bad number of arguments to extinguished ##core#inline"));
lf[28]=C_h_intern(&lf[28],44, C_text("chicken.compiler.support#node-subexpressions"));
lf[29]=C_h_intern(&lf[29],5, C_text("foldr"));
lf[30]=C_h_intern(&lf[30],10, C_text("scheme#cdr"));
lf[31]=C_h_intern(&lf[31],11, C_text("scheme#cddr"));
lf[32]=C_h_intern(&lf[32],2, C_text("if"));
lf[33]=C_h_intern(&lf[33],11, C_text("##core#cond"));
lf[34]=C_h_intern(&lf[34],7, C_text("boolean"));
lf[35]=C_h_intern(&lf[35],13, C_text("scheme#append"));
lf[36]=C_h_intern(&lf[36],5, C_text("quote"));
lf[37]=C_h_intern(&lf[37],6, C_text("string"));
lf[38]=C_h_intern(&lf[38],7, C_text("keyword"));
lf[39]=C_h_intern(&lf[39],6, C_text("symbol"));
lf[40]=C_h_intern(&lf[40],7, C_text("integer"));
lf[41]=C_h_intern(&lf[41],6, C_text("fixnum"));
lf[42]=C_h_intern(&lf[42],6, C_text("bignum"));
lf[43]=C_h_intern(&lf[43],5, C_text("float"));
lf[44]=C_h_intern(&lf[44],6, C_text("ratnum"));
lf[45]=C_h_intern(&lf[45],7, C_text("cplxnum"));
lf[46]=C_h_intern(&lf[46],4, C_text("null"));
lf[47]=C_h_intern(&lf[47],4, C_text("list"));
lf[48]=C_h_intern(&lf[48],4, C_text("pair"));
lf[49]=C_h_intern(&lf[49],3, C_text("eof"));
lf[50]=C_h_intern(&lf[50],3, C_text("bwp"));
lf[51]=C_h_intern(&lf[51],6, C_text("vector"));
lf[52]=C_h_intern(&lf[52],4, C_text("char"));
lf[53]=C_h_intern(&lf[53],38, C_text("chicken.compiler.support#small-bignum\077"));
lf[54]=C_h_intern(&lf[54],36, C_text("chicken.compiler.support#big-fixnum\077"));
lf[55]=C_h_intern(&lf[55],24, C_text("chicken.keyword#keyword\077"));
lf[56]=C_h_intern(&lf[56],3, C_text("let"));
lf[57]=C_h_intern(&lf[57],13, C_text("##core#lambda"));
lf[58]=C_h_intern(&lf[58],20, C_text("##core#direct_lambda"));
lf[59]=C_h_intern(&lf[59],9, C_text("procedure"));
lf[60]=C_h_intern(&lf[60],4, C_text("set!"));
lf[61]=C_h_intern(&lf[61],11, C_text("##core#set!"));
lf[62]=C_h_intern(&lf[62],9, C_text("undefined"));
lf[63]=C_h_intern(&lf[63],16, C_text("##core#primitive"));
lf[64]=C_h_intern(&lf[64],13, C_text("##core#inline"));
lf[65]=C_h_intern(&lf[65],22, C_text("##core#inline_allocate"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_i_check_closure\376\003\000\000\002\376\001\000\000\011\001procedure\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\017C_i_check_"
"exact\376\003\000\000\002\376\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\006\001bignum\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001ratnum\376\377\016\376\003\000"
"\000\002\376\003\000\000\002\376B\000\000\021C_i_check_inexact\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_i_check_number\376"
"\003\000\000\002\376\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001bignum\376\003\000\000\002\376\001\000\000\006\001ratnum\376\003\000\000\002\376\001\000\000\005\001f"
"loat\376\003\000\000\002\376\001\000\000\007\001cplxnum\376\003\000\000\002\376\001\000\000\006\001number\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_i_check_string\376\003\000\000\002\376\001"
"\000\000\006\001string\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\024C_i_check_bytevector\376\003\000\000\002\376\001\000\000\004\001blob\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000"
"\020C_i_check_symbol\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_i_check_keyword\376\003\000\000\002\376\001\000\000\007\001"
"keyword\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\016C_i_check_list\376\003\000\000\002\376\001\000\000\004\001null\376\003\000\000\002\376\001\000\000\004\001pair\376\003\000\000\002\376\001\000\000\004\001"
"list\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\016C_i_check_pair\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_i_check_l"
"ocative\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_i_check_boolean\376\003\000\000\002\376\001\000\000\007\001boolean\376"
"\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_i_check_vector\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\023C_i_check_st"
"ructure\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\016C_i_check_char\376\003\000\000\002\376\001\000\000\004\001char\376\377\016\376\003\000\000"
"\002\376\003\000\000\002\376B\000\000\023C_i_check_closure_2\376\003\000\000\002\376\001\000\000\011\001procedure\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_i_check_ex"
"act_2\376\003\000\000\002\376\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\006\001bignum\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001ratnum\376\377\016\376\003\000"
"\000\002\376\003\000\000\002\376B\000\000\023C_i_check_inexact_2\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_i_check_numbe"
"r_2\376\003\000\000\002\376\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001bignum\376\003\000\000\002\376\001\000\000\006\001ratnum\376\003\000\000\002\376\001\000"
"\000\005\001float\376\003\000\000\002\376\001\000\000\007\001cplxnum\376\003\000\000\002\376\001\000\000\006\001number\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_i_check_string_2\376"
"\003\000\000\002\376\001\000\000\006\001string\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\026C_i_check_bytevector_2\376\003\000\000\002\376\001\000\000\004\001blob\376\377\016\376\003\000\000\002\376"
"\003\000\000\002\376B\000\000\022C_i_check_symbol_2\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\023C_i_check_keyword_"
"2\376\003\000\000\002\376\001\000\000\007\001keyword\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_i_check_list_2\376\003\000\000\002\376\001\000\000\004\001null\376\003\000\000\002\376\001\000\000\004\001p"
"air\376\003\000\000\002\376\001\000\000\004\001list\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_i_check_pair_2\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002"
"\376B\000\000\024C_i_check_locative_2\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\023C_i_check_boolean_"
"2\376\003\000\000\002\376\001\000\000\007\001boolean\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_i_check_vector_2\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002"
"\376\003\000\000\002\376B\000\000\025C_i_check_structure_2\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_i_check_ch"
"ar_2\376\003\000\000\002\376\001\000\000\004\001char\376\377\016\376\377\016"));
lf[67]=C_h_intern(&lf[67],31, C_text("chicken.compiler.support#unsafe"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_noop"));
lf[69]=C_h_intern(&lf[69],8, C_text("\052struct\052"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_noop"));
lf[71]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_noop"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_noop"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376B\000\000\034C_i_foreign_fixnum_argumentp\376\003\000\000\002\376\001\000\000\006\001fixnum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\035C_"
"i_foreign_integer_argumentp\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\006\001bignum\376"
"\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\032C_i_foreign_char_argumentp\376\003\000\000\002\376\001\000\000\004\001char\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\034C_i_"
"foreign_flonum_argumentp\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\034C_i_foreign_string_arg"
"umentp\376\003\000\000\002\376\001\000\000\006\001string\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\034C_i_foreign_symbol_argumentp\376\003\000\000\002\376\001\000\000\006\001"
"symbol\376\377\016\376\377\016"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376B\000\000\014C_i_closurep\376\003\000\000\002\376\001\000\000\011\001procedure\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_fixnump\376\003\000\000\002\376"
"\001\000\000\006\001fixnum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_bignump\376\003\000\000\002\376\001\000\000\006\001bignum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_i_exa"
"ct_integerp\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\006\001bignum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000"
"\013C_i_flonump\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_i_numberp\376\003\000\000\002\376\001\000\000\006\001number\376\003\000\000\002\376"
"\001\000\000\006\001fixnum\376\003\000\000\002\376\001\000\000\007\001integer\376\003\000\000\002\376\001\000\000\006\001bignum\376\003\000\000\002\376\001\000\000\006\001ratnum\376\003\000\000\002\376\001\000\000\005\001float\376"
"\003\000\000\002\376\001\000\000\007\001cplxnum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_i_ratnump\376\003\000\000\002\376\001\000\000\006\001ratnum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000"
"\014C_i_cplxnump\376\003\000\000\002\376\001\000\000\007\001cplxnum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_stringp\376\003\000\000\002\376\001\000\000\006\001string\376\377\016\376\003"
"\000\000\002\376\003\000\000\002\376B\000\000\015C_bytevectorp\376\003\000\000\002\376\001\000\000\004\001blob\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\014C_i_keywordp\376\003\000\000\002\376\001\000\000"
"\007\001keyword\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_i_symbolp\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_i_lis"
"tp\376\003\000\000\002\376\001\000\000\004\001list\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_i_pairp\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_l"
"ocativep\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\012C_booleanp\376\003\000\000\002\376\001\000\000\007\001boolean\376\377\016\376\003\000\000"
"\002\376\003\000\000\002\376B\000\000\013C_i_vectorp\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\014C_structurep\376\003\000\000\002\376\001\000\000\006\001"
"struct\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\016C_i_structurep\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\007C_cha"
"rp\376\003\000\000\002\376\001\000\000\004\001char\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_i_portp\376\003\000\000\002\376\001\000\000\004\001port\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\011C_i"
"_nullp\376\003\000\000\002\376\001\000\000\004\001null\376\377\016\376\377\016"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_true"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_true"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010C_i_true"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_record1\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_record2\376\003"
"\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_record3\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002"
"\376B\000\000\015C_a_i_record4\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_record5\376\003\000\000\002\376\001\000\000\010\001\052"
"struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_record6\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i"
"_record7\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_record8\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016"
"\376\003\000\000\002\376\003\000\000\002\376B\000\000\014C_a_i_record\376\003\000\000\002\376\001\000\000\010\001\052struct\052\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\014C_a_i_string\376\003\000\000"
"\002\376\001\000\000\006\001string\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\012C_a_i_port\376\003\000\000\002\376\001\000\000\004\001port\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_"
"vector1\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_vector2\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002"
"\376\003\000\000\002\376B\000\000\015C_a_i_vector3\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_vector4\376\003\000\000\002\376\001\000\000"
"\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_vector5\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_"
"vector6\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_vector7\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002"
"\376\003\000\000\002\376B\000\000\015C_a_i_vector8\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\010C_a_pair\376\003\000\000\002\376\001\000\000\004\001pai"
"r\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_bytevector\376\003\000\000\002\376\001\000\000\004\001blob\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\023C_a_i_make_l"
"ocative\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\014C_a_i_vector\376\003\000\000\002\376\001\000\000\006\001vector\376\377\016\376\003\000\000"
"\002\376\003\000\000\002\376B\000\000\013C_a_i_list1\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_a_i_list2\376\003\000\000\002\376\001\000\000\004\001pai"
"r\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_a_i_list3\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_a_i_list4\376\003\000\000\002\376"
"\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_a_i_list5\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_a_i_lis"
"t6\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C_a_i_list7\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\013C"
"_a_i_list8\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\012C_a_i_cons\376\003\000\000\002\376\001\000\000\004\001pair\376\377\016\376\003\000\000\002\376\003\000\000"
"\002\376B\000\000\014C_a_i_flonum\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_fix_to_flo\376\003\000\000\002\376\001\000\000\005\001f"
"loat\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_big_to_flo\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_fi"
"x_to_big\376\003\000\000\002\376\001\000\000\006\001bignum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_bignum0\376\003\000\000\002\376\001\000\000\006\001bignum\376\377\016\376\003\000\000"
"\002\376\003\000\000\002\376B\000\000\015C_a_i_bignum1\376\003\000\000\002\376\001\000\000\006\001bignum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\015C_a_i_bignum2\376\003\000\000\002\376\001\000"
"\000\006\001bignum\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flonum_abs\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a"
"_i_flonum_acos\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_acosh\376\003\000\000\002\376\001\000\000\005\001flo"
"at\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000$C_a_i_flonum_actual_quotient_checked\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002"
"\376\003\000\000\002\376B\000\000\021C_a_i_flonum_asin\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_asinh\376"
"\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_atan2\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002"
"\376B\000\000\021C_a_i_flonum_atan\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_atanh\376\003\000\000\002\376"
"\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\024C_a_i_flonum_ceiling\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000"
"\000\020C_a_i_flonum_cos\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_cosh\376\003\000\000\002\376\001\000\000\005\001"
"float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\027C_a_i_flonum_difference\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020"
"C_a_i_flonum_exp\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_expt\376\003\000\000\002\376\001\000\000\005\001fl"
"oat\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_floor\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_f"
"lonum_gcd\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flonum_log\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003"
"\000\000\002\376\003\000\000\002\376B\000\000\033C_a_i_flonum_modulo_checked\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\023C_a_i_"
"flonum_negate\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_plus\376\003\000\000\002\376\001\000\000\005\001float"
"\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\035C_a_i_flonum_quotient_checked\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000"
"\025C_a_i_flonum_quotient\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\036C_a_i_flonum_remainder_c"
"hecked\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\022C_a_i_flonum_round\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000"
"\000\002\376\003\000\000\002\376B\000\000\031C_a_i_flonum_round_proper\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flo"
"num_sin\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_sinh\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000"
"\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_sqrt\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\020C_a_i_flonum_tan\376"
"\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\021C_a_i_flonum_tanh\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376"
"B\000\000\022C_a_i_flonum_times\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\031C_a_i_flonum_multiply_ad"
"d\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_a_i_flonum_truncate\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002"
"\376\003\000\000\002\376B\000\000\025C_a_u_i_f64vector_ref\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\003\000\000\002\376\003\000\000\002\376B\000\000\025C_a_u_i_f32vect"
"or_ref\376\003\000\000\002\376\001\000\000\005\001float\376\377\016\376\377\016"));
lf[79]=C_h_intern(&lf[79],21, C_text("##sys#standard-output"));
lf[80]=C_h_intern(&lf[80],6, C_text("printf"));
lf[81]=C_h_intern(&lf[81],18, C_text("##sys#write-char-0"));
lf[82]=C_h_intern(&lf[82],11, C_text("##sys#print"));
lf[83]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002:\011"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[85]=C_h_intern(&lf[85],18, C_text("chicken.base#print"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027eliminated type checks:"));
lf[87]=C_h_intern(&lf[87],46, C_text("chicken.compiler.support#with-debugging-output"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001x\376\003\000\000\002\376\001\000\000\001\001o\376\377\016"));
lf[89]=C_h_intern(&lf[89],38, C_text("chicken.compiler.lfa2#perform-unboxing"));
lf[90]=C_h_intern(&lf[90],34, C_text("chicken.compiler.support#make-node"));
lf[91]=C_h_intern(&lf[91],12, C_text("##core#float"));
lf[92]=C_h_intern(&lf[92],21, C_text("##core#float-variable"));
lf[93]=C_h_intern(&lf[93],18, C_text("##core#unbox_float"));
lf[94]=C_h_intern(&lf[94],2, C_text("op"));
lf[95]=C_h_intern(&lf[95],3, C_text("map"));
lf[96]=C_h_intern(&lf[96],16, C_text("##core#box_float"));
lf[97]=C_h_intern(&lf[97],16, C_text("##core#let_float"));
lf[98]=C_h_intern(&lf[98],4, C_text("pred"));
lf[99]=C_h_intern(&lf[99],3, C_text("acc"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376B\000\0008number of inline operations replaced with unboxed ones: "));
lf[101]=C_decode_literal(C_heaptop,C_text("\376B\000\000#number of unboxed float variables: "));
lf[102]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001x\376\003\000\000\002\376\001\000\000\001\001o\376\377\016"));
C_register_lf2(lf,103,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1459,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[183] = {
{C_text("f5398:lfa2_2escm"),(void*)f5398},
{C_text("f5456:lfa2_2escm"),(void*)f5456},
{C_text("f5477:lfa2_2escm"),(void*)f5477},
{C_text("f5489:lfa2_2escm"),(void*)f5489},
{C_text("f5496:lfa2_2escm"),(void*)f5496},
{C_text("f_1459:lfa2_2escm"),(void*)f_1459},
{C_text("f_1462:lfa2_2escm"),(void*)f_1462},
{C_text("f_1465:lfa2_2escm"),(void*)f_1465},
{C_text("f_1468:lfa2_2escm"),(void*)f_1468},
{C_text("f_2088:lfa2_2escm"),(void*)f_2088},
{C_text("f_2096:lfa2_2escm"),(void*)f_2096},
{C_text("f_2117:lfa2_2escm"),(void*)f_2117},
{C_text("f_2132:lfa2_2escm"),(void*)f_2132},
{C_text("f_2148:lfa2_2escm"),(void*)f_2148},
{C_text("f_2166:lfa2_2escm"),(void*)f_2166},
{C_text("f_2178:lfa2_2escm"),(void*)f_2178},
{C_text("f_2682:lfa2_2escm"),(void*)f_2682},
{C_text("f_2688:lfa2_2escm"),(void*)f_2688},
{C_text("f_2753:lfa2_2escm"),(void*)f_2753},
{C_text("f_2769:lfa2_2escm"),(void*)f_2769},
{C_text("f_2781:lfa2_2escm"),(void*)f_2781},
{C_text("f_2784:lfa2_2escm"),(void*)f_2784},
{C_text("f_2887:lfa2_2escm"),(void*)f_2887},
{C_text("f_2938:lfa2_2escm"),(void*)f_2938},
{C_text("f_2964:lfa2_2escm"),(void*)f_2964},
{C_text("f_2970:lfa2_2escm"),(void*)f_2970},
{C_text("f_2975:lfa2_2escm"),(void*)f_2975},
{C_text("f_3001:lfa2_2escm"),(void*)f_3001},
{C_text("f_3005:lfa2_2escm"),(void*)f_3005},
{C_text("f_3009:lfa2_2escm"),(void*)f_3009},
{C_text("f_3011:lfa2_2escm"),(void*)f_3011},
{C_text("f_3015:lfa2_2escm"),(void*)f_3015},
{C_text("f_3018:lfa2_2escm"),(void*)f_3018},
{C_text("f_3021:lfa2_2escm"),(void*)f_3021},
{C_text("f_3026:lfa2_2escm"),(void*)f_3026},
{C_text("f_3033:lfa2_2escm"),(void*)f_3033},
{C_text("f_3034:lfa2_2escm"),(void*)f_3034},
{C_text("f_3041:lfa2_2escm"),(void*)f_3041},
{C_text("f_3051:lfa2_2escm"),(void*)f_3051},
{C_text("f_3068:lfa2_2escm"),(void*)f_3068},
{C_text("f_3075:lfa2_2escm"),(void*)f_3075},
{C_text("f_3103:lfa2_2escm"),(void*)f_3103},
{C_text("f_3105:lfa2_2escm"),(void*)f_3105},
{C_text("f_3115:lfa2_2escm"),(void*)f_3115},
{C_text("f_3134:lfa2_2escm"),(void*)f_3134},
{C_text("f_3151:lfa2_2escm"),(void*)f_3151},
{C_text("f_3197:lfa2_2escm"),(void*)f_3197},
{C_text("f_3203:lfa2_2escm"),(void*)f_3203},
{C_text("f_3208:lfa2_2escm"),(void*)f_3208},
{C_text("f_3210:lfa2_2escm"),(void*)f_3210},
{C_text("f_3220:lfa2_2escm"),(void*)f_3220},
{C_text("f_3227:lfa2_2escm"),(void*)f_3227},
{C_text("f_3231:lfa2_2escm"),(void*)f_3231},
{C_text("f_3239:lfa2_2escm"),(void*)f_3239},
{C_text("f_3251:lfa2_2escm"),(void*)f_3251},
{C_text("f_3268:lfa2_2escm"),(void*)f_3268},
{C_text("f_3276:lfa2_2escm"),(void*)f_3276},
{C_text("f_3282:lfa2_2escm"),(void*)f_3282},
{C_text("f_3288:lfa2_2escm"),(void*)f_3288},
{C_text("f_3294:lfa2_2escm"),(void*)f_3294},
{C_text("f_3298:lfa2_2escm"),(void*)f_3298},
{C_text("f_3301:lfa2_2escm"),(void*)f_3301},
{C_text("f_3304:lfa2_2escm"),(void*)f_3304},
{C_text("f_3313:lfa2_2escm"),(void*)f_3313},
{C_text("f_3316:lfa2_2escm"),(void*)f_3316},
{C_text("f_3363:lfa2_2escm"),(void*)f_3363},
{C_text("f_3366:lfa2_2escm"),(void*)f_3366},
{C_text("f_3373:lfa2_2escm"),(void*)f_3373},
{C_text("f_3377:lfa2_2escm"),(void*)f_3377},
{C_text("f_3395:lfa2_2escm"),(void*)f_3395},
{C_text("f_3399:lfa2_2escm"),(void*)f_3399},
{C_text("f_3407:lfa2_2escm"),(void*)f_3407},
{C_text("f_3419:lfa2_2escm"),(void*)f_3419},
{C_text("f_3463:lfa2_2escm"),(void*)f_3463},
{C_text("f_3466:lfa2_2escm"),(void*)f_3466},
{C_text("f_3469:lfa2_2escm"),(void*)f_3469},
{C_text("f_3480:lfa2_2escm"),(void*)f_3480},
{C_text("f_3487:lfa2_2escm"),(void*)f_3487},
{C_text("f_3501:lfa2_2escm"),(void*)f_3501},
{C_text("f_3517:lfa2_2escm"),(void*)f_3517},
{C_text("f_3525:lfa2_2escm"),(void*)f_3525},
{C_text("f_3531:lfa2_2escm"),(void*)f_3531},
{C_text("f_3573:lfa2_2escm"),(void*)f_3573},
{C_text("f_3592:lfa2_2escm"),(void*)f_3592},
{C_text("f_3595:lfa2_2escm"),(void*)f_3595},
{C_text("f_3598:lfa2_2escm"),(void*)f_3598},
{C_text("f_3609:lfa2_2escm"),(void*)f_3609},
{C_text("f_3623:lfa2_2escm"),(void*)f_3623},
{C_text("f_3648:lfa2_2escm"),(void*)f_3648},
{C_text("f_3652:lfa2_2escm"),(void*)f_3652},
{C_text("f_3664:lfa2_2escm"),(void*)f_3664},
{C_text("f_3671:lfa2_2escm"),(void*)f_3671},
{C_text("f_3675:lfa2_2escm"),(void*)f_3675},
{C_text("f_3678:lfa2_2escm"),(void*)f_3678},
{C_text("f_3693:lfa2_2escm"),(void*)f_3693},
{C_text("f_3719:lfa2_2escm"),(void*)f_3719},
{C_text("f_3739:lfa2_2escm"),(void*)f_3739},
{C_text("f_3801:lfa2_2escm"),(void*)f_3801},
{C_text("f_3808:lfa2_2escm"),(void*)f_3808},
{C_text("f_3811:lfa2_2escm"),(void*)f_3811},
{C_text("f_3817:lfa2_2escm"),(void*)f_3817},
{C_text("f_3820:lfa2_2escm"),(void*)f_3820},
{C_text("f_3827:lfa2_2escm"),(void*)f_3827},
{C_text("f_3831:lfa2_2escm"),(void*)f_3831},
{C_text("f_3835:lfa2_2escm"),(void*)f_3835},
{C_text("f_3849:lfa2_2escm"),(void*)f_3849},
{C_text("f_3903:lfa2_2escm"),(void*)f_3903},
{C_text("f_3911:lfa2_2escm"),(void*)f_3911},
{C_text("f_3926:lfa2_2escm"),(void*)f_3926},
{C_text("f_3929:lfa2_2escm"),(void*)f_3929},
{C_text("f_3932:lfa2_2escm"),(void*)f_3932},
{C_text("f_3941:lfa2_2escm"),(void*)f_3941},
{C_text("f_3967:lfa2_2escm"),(void*)f_3967},
{C_text("f_3987:lfa2_2escm"),(void*)f_3987},
{C_text("f_4045:lfa2_2escm"),(void*)f_4045},
{C_text("f_4055:lfa2_2escm"),(void*)f_4055},
{C_text("f_4071:lfa2_2escm"),(void*)f_4071},
{C_text("f_4087:lfa2_2escm"),(void*)f_4087},
{C_text("f_4118:lfa2_2escm"),(void*)f_4118},
{C_text("f_4128:lfa2_2escm"),(void*)f_4128},
{C_text("f_4144:lfa2_2escm"),(void*)f_4144},
{C_text("f_4154:lfa2_2escm"),(void*)f_4154},
{C_text("f_4156:lfa2_2escm"),(void*)f_4156},
{C_text("f_4166:lfa2_2escm"),(void*)f_4166},
{C_text("f_4218:lfa2_2escm"),(void*)f_4218},
{C_text("f_4221:lfa2_2escm"),(void*)f_4221},
{C_text("f_4229:lfa2_2escm"),(void*)f_4229},
{C_text("f_4233:lfa2_2escm"),(void*)f_4233},
{C_text("f_4241:lfa2_2escm"),(void*)f_4241},
{C_text("f_4244:lfa2_2escm"),(void*)f_4244},
{C_text("f_4247:lfa2_2escm"),(void*)f_4247},
{C_text("f_4250:lfa2_2escm"),(void*)f_4250},
{C_text("f_4267:lfa2_2escm"),(void*)f_4267},
{C_text("f_4277:lfa2_2escm"),(void*)f_4277},
{C_text("f_4290:lfa2_2escm"),(void*)f_4290},
{C_text("f_4294:lfa2_2escm"),(void*)f_4294},
{C_text("f_4296:lfa2_2escm"),(void*)f_4296},
{C_text("f_4300:lfa2_2escm"),(void*)f_4300},
{C_text("f_4303:lfa2_2escm"),(void*)f_4303},
{C_text("f_4306:lfa2_2escm"),(void*)f_4306},
{C_text("f_4334:lfa2_2escm"),(void*)f_4334},
{C_text("f_4371:lfa2_2escm"),(void*)f_4371},
{C_text("f_4400:lfa2_2escm"),(void*)f_4400},
{C_text("f_4402:lfa2_2escm"),(void*)f_4402},
{C_text("f_4427:lfa2_2escm"),(void*)f_4427},
{C_text("f_4451:lfa2_2escm"),(void*)f_4451},
{C_text("f_4461:lfa2_2escm"),(void*)f_4461},
{C_text("f_4463:lfa2_2escm"),(void*)f_4463},
{C_text("f_4488:lfa2_2escm"),(void*)f_4488},
{C_text("f_4510:lfa2_2escm"),(void*)f_4510},
{C_text("f_4523:lfa2_2escm"),(void*)f_4523},
{C_text("f_4527:lfa2_2escm"),(void*)f_4527},
{C_text("f_4530:lfa2_2escm"),(void*)f_4530},
{C_text("f_4533:lfa2_2escm"),(void*)f_4533},
{C_text("f_4542:lfa2_2escm"),(void*)f_4542},
{C_text("f_4556:lfa2_2escm"),(void*)f_4556},
{C_text("f_4579:lfa2_2escm"),(void*)f_4579},
{C_text("f_4597:lfa2_2escm"),(void*)f_4597},
{C_text("f_4601:lfa2_2escm"),(void*)f_4601},
{C_text("f_4618:lfa2_2escm"),(void*)f_4618},
{C_text("f_4620:lfa2_2escm"),(void*)f_4620},
{C_text("f_4645:lfa2_2escm"),(void*)f_4645},
{C_text("f_4668:lfa2_2escm"),(void*)f_4668},
{C_text("f_4680:lfa2_2escm"),(void*)f_4680},
{C_text("f_4712:lfa2_2escm"),(void*)f_4712},
{C_text("f_4714:lfa2_2escm"),(void*)f_4714},
{C_text("f_4739:lfa2_2escm"),(void*)f_4739},
{C_text("f_4765:lfa2_2escm"),(void*)f_4765},
{C_text("f_4767:lfa2_2escm"),(void*)f_4767},
{C_text("f_4792:lfa2_2escm"),(void*)f_4792},
{C_text("f_4816:lfa2_2escm"),(void*)f_4816},
{C_text("f_4818:lfa2_2escm"),(void*)f_4818},
{C_text("f_4843:lfa2_2escm"),(void*)f_4843},
{C_text("f_4864:lfa2_2escm"),(void*)f_4864},
{C_text("f_4867:lfa2_2escm"),(void*)f_4867},
{C_text("f_4869:lfa2_2escm"),(void*)f_4869},
{C_text("f_4876:lfa2_2escm"),(void*)f_4876},
{C_text("f_4879:lfa2_2escm"),(void*)f_4879},
{C_text("f_4882:lfa2_2escm"),(void*)f_4882},
{C_text("f_4888:lfa2_2escm"),(void*)f_4888},
{C_text("f_4891:lfa2_2escm"),(void*)f_4891},
{C_text("toplevel:lfa2_2escm"),(void*)C_lfa2_toplevel},
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
o|hiding unexported module binding: chicken.compiler.lfa2#partition 
o|hiding unexported module binding: chicken.compiler.lfa2#span 
o|hiding unexported module binding: chicken.compiler.lfa2#take 
o|hiding unexported module binding: chicken.compiler.lfa2#drop 
o|hiding unexported module binding: chicken.compiler.lfa2#split-at 
o|hiding unexported module binding: chicken.compiler.lfa2#append-map 
o|hiding unexported module binding: chicken.compiler.lfa2#every 
o|hiding unexported module binding: chicken.compiler.lfa2#any 
o|hiding unexported module binding: chicken.compiler.lfa2#cons* 
o|hiding unexported module binding: chicken.compiler.lfa2#concatenate 
o|hiding unexported module binding: chicken.compiler.lfa2#delete 
o|hiding unexported module binding: chicken.compiler.lfa2#first 
o|hiding unexported module binding: chicken.compiler.lfa2#second 
o|hiding unexported module binding: chicken.compiler.lfa2#third 
o|hiding unexported module binding: chicken.compiler.lfa2#fourth 
o|hiding unexported module binding: chicken.compiler.lfa2#fifth 
o|hiding unexported module binding: chicken.compiler.lfa2#delete-duplicates 
o|hiding unexported module binding: chicken.compiler.lfa2#alist-cons 
o|hiding unexported module binding: chicken.compiler.lfa2#filter 
o|hiding unexported module binding: chicken.compiler.lfa2#filter-map 
o|hiding unexported module binding: chicken.compiler.lfa2#remove 
o|hiding unexported module binding: chicken.compiler.lfa2#unzip1 
o|hiding unexported module binding: chicken.compiler.lfa2#last 
o|hiding unexported module binding: chicken.compiler.lfa2#list-index 
o|hiding unexported module binding: chicken.compiler.lfa2#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.compiler.lfa2#lset-difference/eq? 
o|hiding unexported module binding: chicken.compiler.lfa2#lset-union/eq? 
o|hiding unexported module binding: chicken.compiler.lfa2#lset-intersection/eq? 
o|hiding unexported module binding: chicken.compiler.lfa2#list-tabulate 
o|hiding unexported module binding: chicken.compiler.lfa2#lset<=/eq? 
o|hiding unexported module binding: chicken.compiler.lfa2#lset=/eq? 
o|hiding unexported module binding: chicken.compiler.lfa2#length+ 
o|hiding unexported module binding: chicken.compiler.lfa2#find 
o|hiding unexported module binding: chicken.compiler.lfa2#find-tail 
o|hiding unexported module binding: chicken.compiler.lfa2#iota 
o|hiding unexported module binding: chicken.compiler.lfa2#make-list 
o|hiding unexported module binding: chicken.compiler.lfa2#posq 
o|hiding unexported module binding: chicken.compiler.lfa2#posv 
o|hiding unexported module binding: chicken.compiler.lfa2#+type-check-map+ 
o|hiding unexported module binding: chicken.compiler.lfa2#+predicate-map+ 
o|hiding unexported module binding: chicken.compiler.lfa2#+ffi-type-check-map+ 
o|hiding unexported module binding: chicken.compiler.lfa2#+constructor-map+ 
o|hiding unexported module binding: chicken.compiler.lfa2#+unboxed-map+ 
S|applied compiler syntax:
S|  chicken.format#printf		3
S|  scheme#for-each		4
S|  chicken.base#foldl		3
S|  scheme#map		9
S|  chicken.base#foldr		3
o|eliminated procedure checks: 71 
o|specializations:
o|  3 (##sys#check-output-port * * *)
o|  22 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  1 (scheme#caar (pair pair *))
o|  3 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#memq * list)
o|  3 (chicken.base#add1 *)
o|  1 (scheme#eqv? * *)
o|  3 (##sys#check-list (or pair list) *)
o|  28 (scheme#cdr pair)
o|  13 (scheme#car pair)
(o e)|safe calls: 473 
o|safe globals: (chicken.compiler.lfa2#perform-unboxing chicken.compiler.lfa2#perform-secondary-flow-analysis chicken.compiler.lfa2#+unboxed-map+ chicken.compiler.lfa2#+constructor-map+ chicken.compiler.lfa2#+ffi-type-check-map+ chicken.compiler.lfa2#+predicate-map+ chicken.compiler.lfa2#+type-check-map+ chicken.compiler.lfa2#posv chicken.compiler.lfa2#posq chicken.compiler.lfa2#make-list chicken.compiler.lfa2#iota chicken.compiler.lfa2#find-tail chicken.compiler.lfa2#find chicken.compiler.lfa2#length+ chicken.compiler.lfa2#lset=/eq? chicken.compiler.lfa2#lset<=/eq? chicken.compiler.lfa2#list-tabulate chicken.compiler.lfa2#lset-intersection/eq? chicken.compiler.lfa2#lset-union/eq? chicken.compiler.lfa2#lset-difference/eq? chicken.compiler.lfa2#lset-adjoin/eq? chicken.compiler.lfa2#list-index chicken.compiler.lfa2#last chicken.compiler.lfa2#unzip1 chicken.compiler.lfa2#remove chicken.compiler.lfa2#filter-map chicken.compiler.lfa2#filter chicken.compiler.lfa2#alist-cons chicken.compiler.lfa2#delete-duplicates chicken.compiler.lfa2#fifth chicken.compiler.lfa2#fourth chicken.compiler.lfa2#third chicken.compiler.lfa2#second chicken.compiler.lfa2#first chicken.compiler.lfa2#delete chicken.compiler.lfa2#concatenate chicken.compiler.lfa2#cons* chicken.compiler.lfa2#any chicken.compiler.lfa2#every chicken.compiler.lfa2#append-map chicken.compiler.lfa2#split-at chicken.compiler.lfa2#drop chicken.compiler.lfa2#take chicken.compiler.lfa2#span chicken.compiler.lfa2#partition) 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#partition 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#span 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#drop 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#split-at 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#append-map 
o|inlining procedure: k1850 
o|inlining procedure: k1850 
o|inlining procedure: k1881 
o|inlining procedure: k1881 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#cons* 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#concatenate 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#fourth 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#fifth 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#delete-duplicates 
o|inlining procedure: k2098 
o|inlining procedure: k2098 
o|inlining procedure: k2090 
o|inlining procedure: k2090 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#unzip1 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#last 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#list-index 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#lset-intersection/eq? 
o|inlining procedure: k2489 
o|inlining procedure: k2489 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#length+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#find 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#find-tail 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#iota 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#make-list 
o|inlining procedure: k2690 
o|inlining procedure: k2690 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#posv 
o|inlining procedure: k2889 
o|inlining procedure: k2889 
o|inlining procedure: k2898 
o|inlining procedure: k2910 
o|inlining procedure: k2910 
o|inlining procedure: k2898 
o|inlining procedure: k2943 
o|contracted procedure: "(lfa2.scm:288) g593594" 
o|inlining procedure: k2943 
o|substituted constant variable: a2976 
o|inlining procedure: k2977 
o|inlining procedure: k2977 
o|inlining procedure: k2992 
o|inlining procedure: k2992 
o|inlining procedure: "(lfa2.scm:299) chicken.compiler.lfa2#first" 
o|inlining procedure: k3036 
o|inlining procedure: k3036 
o|inlining procedure: k3052 
o|inlining procedure: k3052 
o|inlining procedure: k3073 
o|inlining procedure: k3073 
o|inlining procedure: k3085 
o|inlining procedure: k3085 
o|substituted constant variable: a3095 
o|substituted constant variable: a3097 
o|substituted constant variable: a3099 
o|inlining procedure: k3107 
o|inlining procedure: k3107 
o|inlining procedure: "(lfa2.scm:310) chicken.compiler.lfa2#first" 
o|contracted procedure: "(lfa2.scm:350) chicken.compiler.lfa2#remove" 
o|merged explicitly consed rest parameter: rest666669 
o|inlining procedure: k3228 
o|inlining procedure: k3228 
o|inlining procedure: "(lfa2.scm:354) chicken.compiler.lfa2#first" 
o|consed rest parameter at call site: "(lfa2.scm:359) count-floatvar559" 3 
o|consed rest parameter at call site: "(lfa2.scm:360) count-floatvar559" 3 
o|consed rest parameter at call site: "(lfa2.scm:361) count-floatvar559" 3 
o|inlining procedure: k3305 
o|contracted procedure: "(lfa2.scm:373) vartype555" 
o|inlining procedure: k3141 
o|inlining procedure: k3141 
o|inlining procedure: k3153 
o|inlining procedure: k3153 
o|inlining procedure: "(lfa2.scm:373) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:371) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:370) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:369) chicken.compiler.lfa2#first" 
o|inlining procedure: k3305 
o|inlining procedure: "(lfa2.scm:384) chicken.compiler.lfa2#third" 
o|inlining procedure: "(lfa2.scm:383) chicken.compiler.lfa2#second" 
o|inlining procedure: "(lfa2.scm:381) chicken.compiler.lfa2#third" 
o|inlining procedure: "(lfa2.scm:380) chicken.compiler.lfa2#third" 
o|inlining procedure: "(lfa2.scm:378) chicken.compiler.lfa2#second" 
o|inlining procedure: "(lfa2.scm:377) chicken.compiler.lfa2#second" 
o|inlining procedure: "(lfa2.scm:375) chicken.compiler.lfa2#first" 
o|inlining procedure: k3436 
o|contracted procedure: "(lfa2.scm:385) constant-result548" 
o|inlining procedure: k2758 
o|inlining procedure: k2758 
o|inlining procedure: k2770 
o|inlining procedure: k2770 
o|inlining procedure: k2785 
o|inlining procedure: k2785 
o|inlining procedure: k2797 
o|inlining procedure: k2797 
o|inlining procedure: k2809 
o|inlining procedure: k2809 
o|inlining procedure: k2821 
o|inlining procedure: k2821 
o|inlining procedure: k2833 
o|inlining procedure: k2833 
o|inlining procedure: k2845 
o|inlining procedure: k2845 
o|inlining procedure: k2854 
o|inlining procedure: k2854 
o|inlining procedure: "(lfa2.scm:385) chicken.compiler.lfa2#first" 
o|inlining procedure: k3436 
o|inlining procedure: k3482 
o|inlining procedure: "(lfa2.scm:404) chicken.compiler.lfa2#first" 
o|inlining procedure: k3482 
o|inlining procedure: k3505 
o|inlining procedure: "(lfa2.scm:403) chicken.compiler.lfa2#first" 
o|inlining procedure: k3505 
o|inlining procedure: "(lfa2.scm:397) chicken.compiler.lfa2#second" 
o|inlining procedure: k3549 
o|inlining procedure: k3549 
o|inlining procedure: "(lfa2.scm:388) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:387) chicken.compiler.lfa2#first" 
o|inlining procedure: k3562 
o|inlining procedure: "(lfa2.scm:411) chicken.compiler.lfa2#first" 
o|inlining procedure: k3562 
o|inlining procedure: "(lfa2.scm:417) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:416) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:414) chicken.compiler.lfa2#first" 
o|inlining procedure: k3624 
o|inlining procedure: k3624 
o|inlining procedure: k3653 
o|inlining procedure: k3653 
o|inlining procedure: k3636 
o|inlining procedure: k3676 
o|inlining procedure: k3676 
o|inlining procedure: k3688 
o|inlining procedure: "(lfa2.scm:441) chicken.compiler.lfa2#second" 
o|inlining procedure: "(lfa2.scm:439) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:439) chicken.compiler.lfa2#second" 
o|inlining procedure: k3688 
o|inlining procedure: k3727 
o|inlining procedure: "(lfa2.scm:438) chicken.compiler.lfa2#second" 
o|inlining procedure: k3727 
o|inlining procedure: "(lfa2.scm:437) chicken.compiler.lfa2#first" 
o|inlining procedure: k3748 
o|inlining procedure: k3748 
o|inlining procedure: "(lfa2.scm:431) chicken.compiler.lfa2#first" 
o|inlining procedure: k3809 
o|inlining procedure: k3809 
o|inlining procedure: "(lfa2.scm:452) chicken.compiler.lfa2#first" 
o|inlining procedure: k3798 
o|inlining procedure: k3798 
o|inlining procedure: k3854 
o|inlining procedure: k3876 
o|inlining procedure: k3891 
o|inlining procedure: k3891 
o|inlining procedure: "(lfa2.scm:470) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:472) chicken.compiler.lfa2#second" 
o|inlining procedure: "(lfa2.scm:469) chicken.compiler.lfa2#second" 
o|inlining procedure: k3876 
o|inlining procedure: "(lfa2.scm:466) chicken.compiler.lfa2#first" 
o|inlining procedure: k3854 
o|inlining procedure: k3936 
o|inlining procedure: "(lfa2.scm:489) chicken.compiler.lfa2#second" 
o|inlining procedure: "(lfa2.scm:486) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:487) chicken.compiler.lfa2#second" 
o|inlining procedure: k3936 
o|inlining procedure: k3975 
o|inlining procedure: "(lfa2.scm:485) chicken.compiler.lfa2#second" 
o|inlining procedure: k3975 
o|inlining procedure: "(lfa2.scm:484) chicken.compiler.lfa2#first" 
o|inlining procedure: k3996 
o|inlining procedure: k3996 
o|inlining procedure: "(lfa2.scm:463) chicken.compiler.lfa2#first" 
o|inlining procedure: k4050 
o|inlining procedure: "(lfa2.scm:504) chicken.compiler.lfa2#first" 
o|inlining procedure: k4050 
o|inlining procedure: k4075 
o|inlining procedure: k4075 
o|inlining procedure: "(lfa2.scm:500) chicken.compiler.lfa2#first" 
o|inlining procedure: k4042 
o|inlining procedure: k4042 
o|substituted constant variable: chicken.compiler.lfa2#+constructor-map+ 
o|inlining procedure: "(lfa2.scm:498) chicken.compiler.lfa2#first" 
o|substituted constant variable: chicken.compiler.lfa2#+predicate-map+ 
o|inlining procedure: "(lfa2.scm:461) chicken.compiler.lfa2#first" 
o|substituted constant variable: chicken.compiler.lfa2#+ffi-type-check-map+ 
o|inlining procedure: "(lfa2.scm:450) chicken.compiler.lfa2#first" 
o|substituted constant variable: chicken.compiler.lfa2#+type-check-map+ 
o|inlining procedure: "(lfa2.scm:429) chicken.compiler.lfa2#first" 
o|inlining procedure: k4120 
o|inlining procedure: k4120 
o|inlining procedure: "(lfa2.scm:423) chicken.compiler.lfa2#first" 
o|inlining procedure: k3636 
o|inlining procedure: k4158 
o|inlining procedure: k4158 
o|substituted constant variable: a4182 
o|substituted constant variable: a4184 
o|substituted constant variable: a4186 
o|substituted constant variable: a4188 
o|substituted constant variable: a4193 
o|substituted constant variable: a4195 
o|substituted constant variable: a4200 
o|substituted constant variable: a4202 
o|substituted constant variable: a4204 
o|substituted constant variable: a4206 
o|substituted constant variable: a4211 
o|substituted constant variable: a4213 
o|substituted constant variable: a4215 
o|inlining procedure: k4219 
o|inlining procedure: k4269 
o|contracted procedure: "(lfa2.scm:519) g856863" 
o|propagated global variable: out866869 ##sys#standard-output 
o|substituted constant variable: a4237 
o|substituted constant variable: a4238 
o|propagated global variable: out866869 ##sys#standard-output 
o|inlining procedure: k4269 
o|inlining procedure: k4219 
o|inlining procedure: k4307 
o|inlining procedure: "(lfa2.scm:539) chicken.compiler.lfa2#first" 
o|inlining procedure: k4307 
o|inlining procedure: k4335 
o|inlining procedure: k4335 
o|inlining procedure: "(lfa2.scm:544) chicken.compiler.lfa2#first" 
o|inlining procedure: k4356 
o|inlining procedure: k4404 
o|inlining procedure: k4404 
o|inlining procedure: "(lfa2.scm:552) chicken.compiler.lfa2#third" 
o|inlining procedure: "(lfa2.scm:551) chicken.compiler.lfa2#second" 
o|inlining procedure: k4465 
o|inlining procedure: k4465 
o|inlining procedure: "(lfa2.scm:549) chicken.compiler.lfa2#first" 
o|inlining procedure: k4356 
o|substituted constant variable: a4515 
o|substituted constant variable: a4517 
o|substituted constant variable: a4519 
o|substituted constant variable: a4521 
o|inlining procedure: k4534 
o|inlining procedure: "(lfa2.scm:572) chicken.compiler.lfa2#first" 
o|inlining procedure: k4534 
o|inlining procedure: k4580 
o|inlining procedure: "(lfa2.scm:585) chicken.compiler.lfa2#second" 
o|inlining procedure: k4580 
o|inlining procedure: k4622 
o|inlining procedure: k4622 
o|inlining procedure: "(lfa2.scm:580) chicken.compiler.lfa2#first" 
o|inlining procedure: "(lfa2.scm:579) chicken.compiler.lfa2#first" 
o|inlining procedure: k4653 
o|inlining procedure: k4681 
o|inlining procedure: k4681 
o|substituted constant variable: a4695 
o|inlining procedure: k4716 
o|inlining procedure: k4716 
o|inlining procedure: "(lfa2.scm:591) chicken.compiler.lfa2#third" 
o|inlining procedure: "(lfa2.scm:590) chicken.compiler.lfa2#second" 
o|inlining procedure: k4769 
o|inlining procedure: k4769 
o|inlining procedure: "(lfa2.scm:588) chicken.compiler.lfa2#first" 
o|inlining procedure: k4653 
o|inlining procedure: k4820 
o|inlining procedure: k4820 
o|substituted constant variable: a4855 
o|substituted constant variable: a4857 
o|substituted constant variable: a4859 
o|substituted constant variable: a4861 
o|propagated global variable: out11281134 ##sys#standard-output 
o|substituted constant variable: a4872 
o|substituted constant variable: a4873 
o|propagated global variable: out11311138 ##sys#standard-output 
o|substituted constant variable: a4884 
o|substituted constant variable: a4885 
o|propagated global variable: out11311138 ##sys#standard-output 
o|propagated global variable: out11281134 ##sys#standard-output 
o|inlining procedure: k4902 
o|inlining procedure: k4902 
o|contracted procedure: "(lfa2.scm:526) chicken.compiler.lfa2#filter-map" 
o|inlining procedure: k2145 
o|inlining procedure: k2145 
o|inlining procedure: k2134 
o|inlining procedure: k2134 
o|replaced variables: 741 
o|removed binding forms: 158 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#every 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#any 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#first 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#second 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#third 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#list-tabulate 
o|substituted constant variable: r26914927 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#+type-check-map+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#+predicate-map+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#+ffi-type-check-map+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#+constructor-map+ 
o|inlining procedure: k2898 
o|inlining procedure: k2898 
o|substituted constant variable: r29114933 
o|inlining procedure: k2898 
o|substituted constant variable: r28994934 
o|substituted constant variable: r30744950 
o|substituted constant variable: r30744950 
o|inlining procedure: k3073 
o|inlining procedure: k3073 
o|substituted constant variable: r30864954 
o|contracted procedure: "(mini-srfi-1.scm:141) chicken.compiler.lfa2#filter" 
o|substituted constant variable: r20914924 
o|substituted constant variable: r31544973 
o|substituted constant variable: r27595032 
o|substituted constant variable: r27715034 
o|substituted constant variable: r27865036 
o|substituted constant variable: r27985038 
o|substituted constant variable: r28105040 
o|substituted constant variable: r28225042 
o|substituted constant variable: r28345044 
o|substituted constant variable: r28465046 
o|substituted constant variable: r35065071 
o|substituted constant variable: r35505078 
o|substituted constant variable: r35635089 
o|inlining procedure: k3590 
o|substituted constant variable: r36255111 
o|inlining procedure: k3676 
o|inlining procedure: k3676 
o|substituted constant variable: r37285143 
o|inlining procedure: k3676 
o|inlining procedure: k3676 
o|inlining procedure: k3876 
o|substituted constant variable: r38925171 
o|inlining procedure: k3876 
o|substituted constant variable: r38555194 
o|inlining procedure: k3930 
o|inlining procedure: k3930 
o|substituted constant variable: r39765218 
o|inlining procedure: k3930 
o|inlining procedure: k3930 
o|substituted constant variable: r40765239 
o|substituted constant variable: r36375274 
o|propagated global variable: out866869 ##sys#standard-output 
o|propagated global variable: out11281134 ##sys#standard-output 
o|propagated global variable: out11311138 ##sys#standard-output 
o|substituted constant variable: r49035370 
o|substituted constant variable: r21355374 
o|replaced variables: 249 
o|removed binding forms: 582 
o|removed conditional forms: 1 
o|substituted constant variable: r28995379 
o|substituted constant variable: r28995380 
o|substituted constant variable: r28995381 
o|inlining procedure: "(lfa2.scm:290) chicken.compiler.lfa2#alist-cons" 
o|inlining procedure: "(lfa2.scm:353) varnode?556" 
o|inlining procedure: "(lfa2.scm:405) chicken.compiler.lfa2#alist-cons" 
o|inlining procedure: "(lfa2.scm:405) chicken.compiler.lfa2#alist-cons" 
o|inlining procedure: "(lfa2.scm:401) varnode?556" 
o|inlining procedure: "(lfa2.scm:400) chicken.compiler.lfa2#alist-cons" 
o|inlining procedure: "(lfa2.scm:415) varnode?556" 
o|inlining procedure: k3700 
o|substituted constant variable: r38775404 
o|substituted constant variable: r38775406 
o|substituted constant variable: r385551945409 
o|substituted constant variable: r385551945411 
o|substituted constant variable: r385551945413 
o|substituted constant variable: r385551945415 
o|inlining procedure: "(lfa2.scm:464) varnode?556" 
o|replaced variables: 4 
o|removed binding forms: 259 
o|removed conditional forms: 3 
o|removed side-effect free assignment to unused variable: chicken.compiler.lfa2#alist-cons 
o|substituted constant variable: y2415444 
o|substituted constant variable: r30745382 
o|substituted constant variable: r30745384 
o|removed side-effect free assignment to unused variable: varnode?556 
o|substituted constant variable: r37015491 
o|inlining procedure: k3948 
o|contracted procedure: "(mini-srfi-1.scm:135) a4899" 
o|replaced variables: 22 
o|removed binding forms: 16 
o|removed conditional forms: 1 
o|substituted constant variable: r39495526 
o|contracted procedure: "(mini-srfi-1.scm:134) g273274" 
o|replaced variables: 5 
o|removed binding forms: 31 
o|removed conditional forms: 1 
o|replaced variables: 7 
o|removed binding forms: 3 
o|removed binding forms: 3 
o|simplifications: ((if . 19) (##core#call . 306) (let . 14)) 
o|  call simplifications:
o|    scheme#=
o|    ##sys#setslot	6
o|    ##sys#cons	3
o|    scheme#member	3
o|    scheme#memq	2
o|    scheme#string?
o|    scheme#symbol?	5
o|    chicken.base#fixnum?
o|    chicken.base#bignum?
o|    chicken.base#flonum?
o|    chicken.base#ratnum?
o|    chicken.base#cplxnum?
o|    scheme#boolean?
o|    scheme#list?
o|    scheme#eof-object?
o|    scheme#vector?
o|    ##sys#immediate?
o|    ##sys#generic-structure?
o|    scheme#char?
o|    ##sys#list	5
o|    scheme#caddr	6
o|    scheme#cdar
o|    scheme#+
o|    scheme#set-car!
o|    scheme#assq	5
o|    ##sys#check-list	12
o|    ##sys#slot	31
o|    scheme#length	2
o|    scheme#list	12
o|    scheme#not	8
o|    scheme#assoc	8
o|    scheme#cons	25
o|    scheme#cdr	4
o|    scheme#set-cdr!
o|    scheme#pair?	22
o|    scheme#cadr	24
o|    scheme#null?	4
o|    scheme#car	45
o|    scheme#eq?	55
o|    chicken.fixnum#fx+
o|contracted procedure: k2693 
o|contracted procedure: k2712 
o|contracted procedure: k2699 
o|contracted procedure: k2706 
o|contracted procedure: k2892 
o|contracted procedure: k2901 
o|contracted procedure: k2907 
o|contracted procedure: k2913 
o|contracted procedure: k2919 
o|contracted procedure: k2926 
o|contracted procedure: k2930 
o|contracted procedure: k2898 
o|contracted procedure: k2940 
o|contracted procedure: k2953 
o|contracted procedure: k20755448 
o|contracted procedure: k2960 
o|contracted procedure: k2983 
o|contracted procedure: k2986 
o|contracted procedure: k2989 
o|contracted procedure: k3046 
o|contracted procedure: k3062 
o|contracted procedure: k3070 
o|contracted procedure: k3076 
o|contracted procedure: k3082 
o|contracted procedure: k3088 
o|contracted procedure: k3110 
o|contracted procedure: k3120 
o|contracted procedure: k3124 
o|contracted procedure: k3128 
o|contracted procedure: k3216 
o|contracted procedure: k2081 
o|contracted procedure: k2093 
o|contracted procedure: k2111 
o|contracted procedure: k2119 
o|contracted procedure: k3269 
o|contracted procedure: k3222 
o|contracted procedure: k3245 
o|contracted procedure: k3241 
o|contracted procedure: k3255 
o|contracted procedure: k3262 
o|contracted procedure: k3308 
o|contracted procedure: k3321 
o|contracted procedure: k3138 
o|contracted procedure: k3156 
o|contracted procedure: k3183 
o|contracted procedure: k3173 
o|inlining procedure: k3159 
o|inlining procedure: k3159 
o|contracted procedure: k3331 
o|contracted procedure: k3345 
o|contracted procedure: k3341 
o|contracted procedure: k3349 
o|contracted procedure: k3355 
o|contracted procedure: k3358 
o|contracted procedure: k3379 
o|contracted procedure: k3383 
o|contracted procedure: k3424 
o|contracted procedure: k3386 
o|contracted procedure: k3401 
o|contracted procedure: k3409 
o|contracted procedure: k3413 
o|contracted procedure: k3421 
o|contracted procedure: k3433 
o|contracted procedure: k3439 
o|contracted procedure: k3446 
o|contracted procedure: k2761 
o|contracted procedure: k2773 
o|contracted procedure: k2788 
o|contracted procedure: k2794 
o|contracted procedure: k2800 
o|contracted procedure: k2806 
o|contracted procedure: k2812 
o|contracted procedure: k2818 
o|contracted procedure: k2824 
o|contracted procedure: k2830 
o|contracted procedure: k2836 
o|contracted procedure: k2842 
o|contracted procedure: k2851 
o|contracted procedure: k2880 
o|contracted procedure: k2873 
o|contracted procedure: k2857 
o|contracted procedure: k2864 
o|contracted procedure: k2870 
o|contracted procedure: k3452 
o|contracted procedure: k3455 
o|contracted procedure: k3458 
o|contracted procedure: k3474 
o|contracted procedure: k3488 
o|contracted procedure: k20755473 
o|contracted procedure: k3495 
o|contracted procedure: k20755466 
o|contracted procedure: k3482 
o|contracted procedure: k3502 
o|contracted procedure: k3508 
o|contracted procedure: k3519 
o|contracted procedure: k20755485 
o|contracted procedure: k3540 
o|contracted procedure: k3533 
o|contracted procedure: k3546 
o|contracted procedure: k3552 
o|contracted procedure: k3565 
o|contracted procedure: k3568 
o|contracted procedure: k3575 
o|contracted procedure: k3581 
o|contracted procedure: k3584 
o|contracted procedure: k3587 
o|contracted procedure: k3603 
o|contracted procedure: k3610 
o|contracted procedure: k3617 
o|contracted procedure: k3627 
o|contracted procedure: k3633 
o|contracted procedure: k3639 
o|contracted procedure: k3642 
o|contracted procedure: k4141 
o|contracted procedure: k3645 
o|contracted procedure: k3659 
o|contracted procedure: k4114 
o|contracted procedure: k3665 
o|contracted procedure: k3785 
o|contracted procedure: k3685 
o|contracted procedure: k3694 
o|contracted procedure: k3706 
o|contracted procedure: k3713 
o|contracted procedure: k3700 
o|contracted procedure: k3721 
o|contracted procedure: k3724 
o|contracted procedure: k3745 
o|contracted procedure: k3730 
o|contracted procedure: k3741 
o|contracted procedure: k3776 
o|contracted procedure: k3751 
o|contracted procedure: k3757 
o|contracted procedure: k3768 
o|contracted procedure: k3789 
o|contracted procedure: k4110 
o|contracted procedure: k3795 
o|contracted procedure: k3803 
o|contracted procedure: k3837 
o|contracted procedure: k3812 
o|contracted procedure: k4106 
o|contracted procedure: k3843 
o|contracted procedure: k3851 
o|contracted procedure: k3857 
o|contracted procedure: k3864 
o|contracted procedure: k3872 
o|contracted procedure: k3920 
o|contracted procedure: k3879 
o|contracted procedure: k3885 
o|contracted procedure: k3888 
o|contracted procedure: k3894 
o|inlining procedure: k3876 
o|contracted procedure: k3905 
o|contracted procedure: k3913 
o|inlining procedure: k3876 
o|contracted procedure: k4033 
o|contracted procedure: k3933 
o|contracted procedure: k3942 
o|contracted procedure: k3954 
o|contracted procedure: k3961 
o|contracted procedure: k3948 
o|contracted procedure: k3969 
o|contracted procedure: k3972 
o|contracted procedure: k3993 
o|contracted procedure: k3978 
o|contracted procedure: k3989 
o|contracted procedure: k4024 
o|contracted procedure: k3999 
o|contracted procedure: k4005 
o|contracted procedure: k4016 
o|contracted procedure: k4102 
o|contracted procedure: k4039 
o|contracted procedure: k4092 
o|contracted procedure: k4047 
o|contracted procedure: k4056 
o|contracted procedure: k4062 
o|contracted procedure: k4089 
o|contracted procedure: k4078 
o|contracted procedure: k4123 
o|contracted procedure: k4133 
o|contracted procedure: k4137 
o|contracted procedure: k4149 
o|contracted procedure: k4161 
o|contracted procedure: k4171 
o|contracted procedure: k4175 
o|contracted procedure: k4222 
o|contracted procedure: k4260 
o|contracted procedure: k4272 
o|contracted procedure: k4282 
o|contracted procedure: k4286 
o|contracted procedure: k4257 
o|contracted procedure: k4310 
o|contracted procedure: k4313 
o|contracted procedure: k4323 
o|contracted procedure: k4329 
o|contracted procedure: k4342 
o|contracted procedure: k4349 
o|contracted procedure: k4353 
o|contracted procedure: k4359 
o|contracted procedure: k4362 
o|contracted procedure: k4497 
o|contracted procedure: k4365 
o|contracted procedure: k4373 
o|contracted procedure: k4376 
o|contracted procedure: k4385 
o|contracted procedure: k4389 
o|contracted procedure: k4435 
o|contracted procedure: k4392 
o|contracted procedure: k4395 
o|contracted procedure: k4407 
o|contracted procedure: k4410 
o|contracted procedure: k4413 
o|contracted procedure: k4421 
o|contracted procedure: k4429 
o|contracted procedure: k4445 
o|contracted procedure: k4453 
o|contracted procedure: k4456 
o|contracted procedure: k4468 
o|contracted procedure: k4471 
o|contracted procedure: k4474 
o|contracted procedure: k4482 
o|contracted procedure: k4490 
o|contracted procedure: k4504 
o|contracted procedure: k4537 
o|contracted procedure: k4550 
o|contracted procedure: k4558 
o|contracted procedure: k4562 
o|contracted procedure: k4568 
o|contracted procedure: k4571 
o|contracted procedure: k4574 
o|contracted procedure: k4587 
o|contracted procedure: k4591 
o|contracted procedure: k4603 
o|contracted procedure: k4610 
o|contracted procedure: k4613 
o|contracted procedure: k4625 
o|contracted procedure: k4628 
o|contracted procedure: k4631 
o|contracted procedure: k4639 
o|contracted procedure: k4647 
o|contracted procedure: k4656 
o|contracted procedure: k4659 
o|contracted procedure: k4801 
o|contracted procedure: k4662 
o|contracted procedure: k4670 
o|contracted procedure: k4673 
o|contracted procedure: k4684 
o|contracted procedure: k4691 
o|contracted procedure: k4697 
o|contracted procedure: k4701 
o|contracted procedure: k4747 
o|contracted procedure: k4704 
o|contracted procedure: k4707 
o|contracted procedure: k4719 
o|contracted procedure: k4722 
o|contracted procedure: k4725 
o|contracted procedure: k4733 
o|contracted procedure: k4741 
o|contracted procedure: k4757 
o|contracted procedure: k4760 
o|contracted procedure: k4772 
o|contracted procedure: k4775 
o|contracted procedure: k4778 
o|contracted procedure: k4786 
o|contracted procedure: k4794 
o|contracted procedure: k4808 
o|contracted procedure: k4811 
o|contracted procedure: k4823 
o|contracted procedure: k4826 
o|contracted procedure: k4829 
o|contracted procedure: k4837 
o|contracted procedure: k4845 
o|contracted procedure: k4896 
o|contracted procedure: k2125 
o|contracted procedure: k2137 
o|contracted procedure: k2160 
o|contracted procedure: k4910 
o|contracted procedure: k4914 
o|contracted procedure: k4905 
o|contracted procedure: k2142 
o|contracted procedure: k2168 
o|simplifications: ((let . 93)) 
o|removed binding forms: 276 
o|substituted constant variable: r31605695 
o|substituted constant variable: r31605695 
o|inlining procedure: k3324 
o|inlining procedure: k3324 
o|inlining procedure: k3868 
o|inlining procedure: k3868 
o|inlining procedure: k3868 
o|inlining procedure: k3868 
o|removed binding forms: 2 
o|removed conditional forms: 1 
o|substituted constant variable: r33255729 
o|simplifications: ((let . 1)) 
o|removed binding forms: 3 
o|removed conditional forms: 1 
o|removed binding forms: 1 
o|direct leaf routine/allocation: loop482 0 
o|direct leaf routine/allocation: merge549 0 
o|direct leaf routine/allocation: report550 35 
o|direct leaf routine/allocation: floatvar?557 0 
o|direct leaf routine/allocation: a3209 0 
o|direct leaf routine/allocation: loop649 0 
o|direct leaf routine/allocation: g283284 3 
o|converted assignments to bindings: (loop482) 
o|contracted procedure: "(lfa2.scm:310) k3028" 
o|contracted procedure: "(mini-srfi-1.scm:141) k2184" 
o|converted assignments to bindings: (loop649) 
o|contracted procedure: "(lfa2.scm:369) k3334" 
o|contracted procedure: "(lfa2.scm:393) k3559" 
o|simplifications: ((let . 2)) 
o|removed binding forms: 4 
o|direct leaf routine/allocation: a2177 0 
o|contracted procedure: "(mini-srfi-1.scm:131) k2101" 
o|removed binding forms: 1 
o|direct leaf routine/allocation: g255256 3 
o|customizable procedures: (foldr268271 map-loop11031120 map-loop10771094 g10361037 map-loop10441061 map-loop10031020 map-loop963980 g929930 map-loop936953 chicken.compiler.lfa2#posq for-each-loop855875 g830837 for-each-loop829847 g742749 for-each-loop741753 g815816 k4053 g788789 k3939 g779780 g764765 k3691 extinguish!554 k3596 k3529 add-unboxed561 k3478 assigned?551 k3485 k3364 walk563 eliminate-floatvar558 add-boxed560 count-floatvar559 k3225 g682683 foldr250253 g617624 for-each-loop616627 droppable?552 drop!553 sub-boxed562) 
o|calls to known targets: 110 
o|identified direct recursive calls: f_2688 1 
o|identified direct recursive calls: f_2088 1 
o|identified direct recursive calls: f_3151 2 
o|identified direct recursive calls: f_2132 1 
o|fast box initializations: 27 
o|fast global references: 6 
o|fast global assignments: 2 
o|dropping unused closure argument: f_2682 
o|dropping unused closure argument: f_2887 
*/
/* end of file */
