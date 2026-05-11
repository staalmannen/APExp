/* Generated from batch-driver.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: batch-driver.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.batch-driver -output-file batch-driver.c
   unit: batch-driver
   uses: user-pass c-backend c-platform lfa2 scrutinizer optimizer compiler compiler-syntax support port expand data-structures pathname eval internal extras library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_user_2dpass_toplevel)
C_externimport void C_ccall C_user_2dpass_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_c_2dbackend_toplevel)
C_externimport void C_ccall C_c_2dbackend_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_c_2dplatform_toplevel)
C_externimport void C_ccall C_c_2dplatform_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_lfa2_toplevel)
C_externimport void C_ccall C_lfa2_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_scrutinizer_toplevel)
C_externimport void C_ccall C_scrutinizer_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_optimizer_toplevel)
C_externimport void C_ccall C_optimizer_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_toplevel)
C_externimport void C_ccall C_compiler_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_compiler_2dsyntax_toplevel)
C_externimport void C_ccall C_compiler_2dsyntax_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_support_toplevel)
C_externimport void C_ccall C_support_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[492];
static double C_possibly_force_alignment;


C_noret_decl(f8775)
static void C_ccall f8775(C_word c,C_word *av) C_noret;
C_noret_decl(f9431)
static void C_ccall f9431(C_word c,C_word *av) C_noret;
C_noret_decl(f9437)
static void C_ccall f9437(C_word c,C_word *av) C_noret;
C_noret_decl(f9443)
static void C_ccall f9443(C_word c,C_word *av) C_noret;
C_noret_decl(f9449)
static void C_ccall f9449(C_word c,C_word *av) C_noret;
C_noret_decl(f9457)
static void C_ccall f9457(C_word c,C_word *av) C_noret;
C_noret_decl(f9463)
static void C_ccall f9463(C_word c,C_word *av) C_noret;
C_noret_decl(f9475)
static void C_ccall f9475(C_word c,C_word *av) C_noret;
C_noret_decl(f9483)
static void C_ccall f9483(C_word c,C_word *av) C_noret;
C_noret_decl(f9493)
static void C_ccall f9493(C_word c,C_word *av) C_noret;
C_noret_decl(f9513)
static void C_ccall f9513(C_word c,C_word *av) C_noret;
C_noret_decl(f9519)
static void C_ccall f9519(C_word c,C_word *av) C_noret;
C_noret_decl(f9533)
static void C_ccall f9533(C_word c,C_word *av) C_noret;
C_noret_decl(f9539)
static void C_ccall f9539(C_word c,C_word *av) C_noret;
C_noret_decl(f9545)
static void C_ccall f9545(C_word c,C_word *av) C_noret;
C_noret_decl(f9551)
static void C_ccall f9551(C_word c,C_word *av) C_noret;
C_noret_decl(f9557)
static void C_ccall f9557(C_word c,C_word *av) C_noret;
C_noret_decl(f9579)
static void C_ccall f9579(C_word c,C_word *av) C_noret;
C_noret_decl(f9595)
static void C_ccall f9595(C_word c,C_word *av) C_noret;
C_noret_decl(f9601)
static void C_ccall f9601(C_word c,C_word *av) C_noret;
C_noret_decl(f9607)
static void C_ccall f9607(C_word c,C_word *av) C_noret;
C_noret_decl(f9613)
static void C_ccall f9613(C_word c,C_word *av) C_noret;
C_noret_decl(f9619)
static void C_ccall f9619(C_word c,C_word *av) C_noret;
C_noret_decl(f_2707)
static void C_ccall f_2707(C_word c,C_word *av) C_noret;
C_noret_decl(f_2710)
static void C_ccall f_2710(C_word c,C_word *av) C_noret;
C_noret_decl(f_2713)
static void C_ccall f_2713(C_word c,C_word *av) C_noret;
C_noret_decl(f_2716)
static void C_ccall f_2716(C_word c,C_word *av) C_noret;
C_noret_decl(f_2719)
static void C_ccall f_2719(C_word c,C_word *av) C_noret;
C_noret_decl(f_2722)
static void C_ccall f_2722(C_word c,C_word *av) C_noret;
C_noret_decl(f_2725)
static void C_ccall f_2725(C_word c,C_word *av) C_noret;
C_noret_decl(f_2728)
static void C_ccall f_2728(C_word c,C_word *av) C_noret;
C_noret_decl(f_2731)
static void C_ccall f_2731(C_word c,C_word *av) C_noret;
C_noret_decl(f_2734)
static void C_ccall f_2734(C_word c,C_word *av) C_noret;
C_noret_decl(f_2737)
static void C_ccall f_2737(C_word c,C_word *av) C_noret;
C_noret_decl(f_2740)
static void C_ccall f_2740(C_word c,C_word *av) C_noret;
C_noret_decl(f_2743)
static void C_ccall f_2743(C_word c,C_word *av) C_noret;
C_noret_decl(f_2746)
static void C_ccall f_2746(C_word c,C_word *av) C_noret;
C_noret_decl(f_2749)
static void C_ccall f_2749(C_word c,C_word *av) C_noret;
C_noret_decl(f_2752)
static void C_ccall f_2752(C_word c,C_word *av) C_noret;
C_noret_decl(f_2755)
static void C_ccall f_2755(C_word c,C_word *av) C_noret;
C_noret_decl(f_2956)
static void C_fcall f_2956(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2971)
static void C_fcall f_2971(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2979)
static void C_fcall f_2979(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2987)
static void C_ccall f_2987(C_word c,C_word *av) C_noret;
C_noret_decl(f_2998)
static void C_ccall f_2998(C_word c,C_word *av) C_noret;
C_noret_decl(f_3011)
static void C_fcall f_3011(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3018)
static void C_ccall f_3018(C_word c,C_word *av) C_noret;
C_noret_decl(f_3025)
static void C_ccall f_3025(C_word c,C_word *av) C_noret;
C_noret_decl(f_3029)
static void C_ccall f_3029(C_word c,C_word *av) C_noret;
C_noret_decl(f_3041)
static void C_ccall f_3041(C_word c,C_word *av) C_noret;
C_noret_decl(f_3043)
static void C_fcall f_3043(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3090)
static void C_ccall f_3090(C_word c,C_word *av) C_noret;
C_noret_decl(f_3092)
static void C_fcall f_3092(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3160)
static void C_fcall f_3160(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3166)
static void C_fcall f_3166(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3176)
static void C_ccall f_3176(C_word c,C_word *av) C_noret;
C_noret_decl(f_3252)
static void C_fcall f_3252(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3279)
static void C_ccall f_3279(C_word c,C_word *av) C_noret;
C_noret_decl(f_3677)
static void C_fcall f_3677(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3702)
static void C_fcall f_3702(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3725)
static void C_ccall f_3725(C_word c,C_word *av) C_noret;
C_noret_decl(f_3730)
static void C_ccall f_3730(C_word c,C_word *av) C_noret;
C_noret_decl(f_3744)
static void C_ccall f_3744(C_word c,C_word *av) C_noret;
C_noret_decl(f_4041)
static void C_ccall f_4041(C_word c,C_word *av) C_noret;
C_noret_decl(f_4047)
static void C_ccall f_4047(C_word c,C_word *av) C_noret;
C_noret_decl(f_4054)
static void C_ccall f_4054(C_word c,C_word *av) C_noret;
C_noret_decl(f_4060)
static void C_ccall f_4060(C_word c,C_word *av) C_noret;
C_noret_decl(f_4063)
static void C_ccall f_4063(C_word c,C_word *av) C_noret;
C_noret_decl(f_4066)
static void C_ccall f_4066(C_word c,C_word *av) C_noret;
C_noret_decl(f_4069)
static void C_ccall f_4069(C_word c,C_word *av) C_noret;
C_noret_decl(f_4072)
static void C_ccall f_4072(C_word c,C_word *av) C_noret;
C_noret_decl(f_4078)
static void C_ccall f_4078(C_word c,C_word *av) C_noret;
C_noret_decl(f_4081)
static void C_ccall f_4081(C_word c,C_word *av) C_noret;
C_noret_decl(f_4084)
static void C_ccall f_4084(C_word c,C_word *av) C_noret;
C_noret_decl(f_4090)
static void C_ccall f_4090(C_word c,C_word *av) C_noret;
C_noret_decl(f_4093)
static void C_ccall f_4093(C_word c,C_word *av) C_noret;
C_noret_decl(f_4096)
static void C_ccall f_4096(C_word c,C_word *av) C_noret;
C_noret_decl(f_4102)
static void C_ccall f_4102(C_word c,C_word *av) C_noret;
C_noret_decl(f_4105)
static void C_ccall f_4105(C_word c,C_word *av) C_noret;
C_noret_decl(f_4108)
static void C_ccall f_4108(C_word c,C_word *av) C_noret;
C_noret_decl(f_4114)
static void C_ccall f_4114(C_word c,C_word *av) C_noret;
C_noret_decl(f_4117)
static void C_ccall f_4117(C_word c,C_word *av) C_noret;
C_noret_decl(f_4120)
static void C_ccall f_4120(C_word c,C_word *av) C_noret;
C_noret_decl(f_4126)
static void C_ccall f_4126(C_word c,C_word *av) C_noret;
C_noret_decl(f_4129)
static void C_ccall f_4129(C_word c,C_word *av) C_noret;
C_noret_decl(f_4134)
static void C_fcall f_4134(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4138)
static void C_ccall f_4138(C_word c,C_word *av) C_noret;
C_noret_decl(f_4150)
static void C_ccall f_4150(C_word c,C_word *av) C_noret;
C_noret_decl(f_4161)
static void C_ccall f_4161(C_word c,C_word *av) C_noret;
C_noret_decl(f_4174)
static void C_fcall f_4174(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4184)
static void C_ccall f_4184(C_word c,C_word *av) C_noret;
C_noret_decl(f_4197)
static void C_fcall f_4197(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4207)
static void C_ccall f_4207(C_word c,C_word *av) C_noret;
C_noret_decl(f_4220)
static void C_fcall f_4220(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4230)
static void C_ccall f_4230(C_word c,C_word *av) C_noret;
C_noret_decl(f_4243)
static void C_fcall f_4243(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4247)
static void C_fcall f_4247(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4252)
static void C_ccall f_4252(C_word c,C_word *av) C_noret;
C_noret_decl(f_4262)
static void C_ccall f_4262(C_word c,C_word *av) C_noret;
C_noret_decl(f_4265)
static void C_ccall f_4265(C_word c,C_word *av) C_noret;
C_noret_decl(f_4268)
static void C_ccall f_4268(C_word c,C_word *av) C_noret;
C_noret_decl(f_4271)
static void C_ccall f_4271(C_word c,C_word *av) C_noret;
C_noret_decl(f_4274)
static void C_ccall f_4274(C_word c,C_word *av) C_noret;
C_noret_decl(f_4277)
static void C_ccall f_4277(C_word c,C_word *av) C_noret;
C_noret_decl(f_4280)
static void C_ccall f_4280(C_word c,C_word *av) C_noret;
C_noret_decl(f_4294)
static void C_ccall f_4294(C_word c,C_word *av) C_noret;
C_noret_decl(f_4305)
static void C_ccall f_4305(C_word c,C_word *av) C_noret;
C_noret_decl(f_4309)
static void C_ccall f_4309(C_word c,C_word *av) C_noret;
C_noret_decl(f_4317)
static void C_fcall f_4317(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4327)
static void C_ccall f_4327(C_word c,C_word *av) C_noret;
C_noret_decl(f_4347)
static void C_ccall f_4347(C_word c,C_word *av) C_noret;
C_noret_decl(f_4358)
static void C_ccall f_4358(C_word c,C_word *av) C_noret;
C_noret_decl(f_4362)
static void C_ccall f_4362(C_word c,C_word *av) C_noret;
C_noret_decl(f_4374)
static void C_ccall f_4374(C_word c,C_word *av) C_noret;
C_noret_decl(f_4385)
static void C_ccall f_4385(C_word c,C_word *av) C_noret;
C_noret_decl(f_4389)
static void C_ccall f_4389(C_word c,C_word *av) C_noret;
C_noret_decl(f_4412)
static void C_ccall f_4412(C_word c,C_word *av) C_noret;
C_noret_decl(f_4428)
static void C_ccall f_4428(C_word c,C_word *av) C_noret;
C_noret_decl(f_4444)
static void C_ccall f_4444(C_word c,C_word *av) C_noret;
C_noret_decl(f_4453)
static void C_fcall f_4453(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4466)
static void C_ccall f_4466(C_word c,C_word *av) C_noret;
C_noret_decl(f_4477)
static void C_fcall f_4477(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4483)
static void C_ccall f_4483(C_word c,C_word *av) C_noret;
C_noret_decl(f_4556)
static void C_fcall f_4556(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4562)
static void C_ccall f_4562(C_word c,C_word *av) C_noret;
C_noret_decl(f_4565)
static void C_ccall f_4565(C_word c,C_word *av) C_noret;
C_noret_decl(f_4568)
static void C_ccall f_4568(C_word c,C_word *av) C_noret;
C_noret_decl(f_4878)
static void C_ccall f_4878(C_word c,C_word *av) C_noret;
C_noret_decl(f_4880)
static void C_ccall f_4880(C_word c,C_word *av) C_noret;
C_noret_decl(f_4883)
static void C_fcall f_4883(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4914)
static void C_ccall f_4914(C_word c,C_word *av) C_noret;
C_noret_decl(f_4923)
static void C_fcall f_4923(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4926)
static void C_fcall f_4926(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4929)
static void C_ccall f_4929(C_word c,C_word *av) C_noret;
C_noret_decl(f_4939)
static void C_fcall f_4939(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4944)
static void C_ccall f_4944(C_word c,C_word *av) C_noret;
C_noret_decl(f_4947)
static void C_ccall f_4947(C_word c,C_word *av) C_noret;
C_noret_decl(f_4952)
static void C_fcall f_4952(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4977)
static void C_ccall f_4977(C_word c,C_word *av) C_noret;
C_noret_decl(f_4995)
static void C_fcall f_4995(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4999)
static void C_ccall f_4999(C_word c,C_word *av) C_noret;
C_noret_decl(f_5011)
static void C_ccall f_5011(C_word c,C_word *av) C_noret;
C_noret_decl(f_5014)
static void C_ccall f_5014(C_word c,C_word *av) C_noret;
C_noret_decl(f_5017)
static void C_ccall f_5017(C_word c,C_word *av) C_noret;
C_noret_decl(f_5020)
static void C_ccall f_5020(C_word c,C_word *av) C_noret;
C_noret_decl(f_5022)
static void C_fcall f_5022(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5029)
static void C_ccall f_5029(C_word c,C_word *av) C_noret;
C_noret_decl(f_5042)
static void C_ccall f_5042(C_word c,C_word *av) C_noret;
C_noret_decl(f_5044)
static void C_fcall f_5044(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_5051)
static void C_ccall f_5051(C_word c,C_word *av) C_noret;
C_noret_decl(f_5057)
static void C_ccall f_5057(C_word c,C_word *av) C_noret;
C_noret_decl(f_5060)
static void C_ccall f_5060(C_word c,C_word *av) C_noret;
C_noret_decl(f_5063)
static void C_ccall f_5063(C_word c,C_word *av) C_noret;
C_noret_decl(f_5066)
static void C_ccall f_5066(C_word c,C_word *av) C_noret;
C_noret_decl(f_5071)
static void C_fcall f_5071(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5078)
static void C_ccall f_5078(C_word c,C_word *av) C_noret;
C_noret_decl(f_5083)
static void C_ccall f_5083(C_word c,C_word *av) C_noret;
C_noret_decl(f_5094)
static void C_fcall f_5094(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5104)
static void C_ccall f_5104(C_word c,C_word *av) C_noret;
C_noret_decl(f_5127)
static void C_fcall f_5127(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5175)
static void C_ccall f_5175(C_word c,C_word *av) C_noret;
C_noret_decl(f_5184)
static void C_ccall f_5184(C_word c,C_word *av) C_noret;
C_noret_decl(f_5189)
static void C_ccall f_5189(C_word c,C_word *av) C_noret;
C_noret_decl(f_5195)
static void C_ccall f_5195(C_word c,C_word *av) C_noret;
C_noret_decl(f_5201)
static void C_ccall f_5201(C_word c,C_word *av) C_noret;
C_noret_decl(f_5207)
static void C_ccall f_5207(C_word c,C_word *av) C_noret;
C_noret_decl(f_5213)
static void C_ccall f_5213(C_word c,C_word *av) C_noret;
C_noret_decl(f_5219)
static void C_ccall f_5219(C_word c,C_word *av) C_noret;
C_noret_decl(f_5225)
static void C_ccall f_5225(C_word c,C_word *av) C_noret;
C_noret_decl(f_5242)
static void C_fcall f_5242(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5251)
static void C_ccall f_5251(C_word c,C_word *av) C_noret;
C_noret_decl(f_5282)
static void C_ccall f_5282(C_word c,C_word *av) C_noret;
C_noret_decl(f_5286)
static void C_ccall f_5286(C_word c,C_word *av) C_noret;
C_noret_decl(f_5302)
static void C_ccall f_5302(C_word c,C_word *av) C_noret;
C_noret_decl(f_5306)
static void C_ccall f_5306(C_word c,C_word *av) C_noret;
C_noret_decl(f_5327)
static void C_fcall f_5327(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5333)
static void C_fcall f_5333(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5341)
static void C_fcall f_5341(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5349)
static void C_ccall f_5349(C_word c,C_word *av) C_noret;
C_noret_decl(f_5353)
static void C_ccall f_5353(C_word c,C_word *av) C_noret;
C_noret_decl(f_5362)
static void C_fcall f_5362(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5370)
static void C_ccall f_5370(C_word c,C_word *av) C_noret;
C_noret_decl(f_5372)
static void C_fcall f_5372(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5382)
static void C_ccall f_5382(C_word c,C_word *av) C_noret;
C_noret_decl(f_5385)
static void C_ccall f_5385(C_word c,C_word *av) C_noret;
C_noret_decl(f_5388)
static void C_ccall f_5388(C_word c,C_word *av) C_noret;
C_noret_decl(f_5391)
static void C_ccall f_5391(C_word c,C_word *av) C_noret;
C_noret_decl(f_5398)
static void C_ccall f_5398(C_word c,C_word *av) C_noret;
C_noret_decl(f_5402)
static void C_ccall f_5402(C_word c,C_word *av) C_noret;
C_noret_decl(f_5410)
static void C_ccall f_5410(C_word c,C_word *av) C_noret;
C_noret_decl(f_5412)
static void C_fcall f_5412(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5414)
static void C_fcall f_5414(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5418)
static void C_ccall f_5418(C_word c,C_word *av) C_noret;
C_noret_decl(f_5421)
static void C_ccall f_5421(C_word c,C_word *av) C_noret;
C_noret_decl(f_5426)
static void C_ccall f_5426(C_word c,C_word *av) C_noret;
C_noret_decl(f_5432)
static void C_ccall f_5432(C_word c,C_word *av) C_noret;
C_noret_decl(f_5437)
static void C_fcall f_5437(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5442)
static void C_fcall f_5442(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5501)
static void C_fcall f_5501(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5504)
static void C_fcall f_5504(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5507)
static void C_ccall f_5507(C_word c,C_word *av) C_noret;
C_noret_decl(f_5514)
static void C_ccall f_5514(C_word c,C_word *av) C_noret;
C_noret_decl(f_5517)
static void C_ccall f_5517(C_word c,C_word *av) C_noret;
C_noret_decl(f_5534)
static void C_ccall f_5534(C_word c,C_word *av) C_noret;
C_noret_decl(f_5538)
static void C_ccall f_5538(C_word c,C_word *av) C_noret;
C_noret_decl(f_5543)
static void C_ccall f_5543(C_word c,C_word *av) C_noret;
C_noret_decl(f_5549)
static void C_ccall f_5549(C_word c,C_word *av) C_noret;
C_noret_decl(f_5552)
static void C_fcall f_5552(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5555)
static void C_fcall f_5555(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5558)
static void C_ccall f_5558(C_word c,C_word *av) C_noret;
C_noret_decl(f_5561)
static void C_fcall f_5561(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5564)
static void C_fcall f_5564(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5567)
static void C_fcall f_5567(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5570)
static void C_fcall f_5570(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5573)
static void C_fcall f_5573(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5576)
static void C_fcall f_5576(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5579)
static void C_fcall f_5579(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5582)
static void C_fcall f_5582(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5585)
static void C_fcall f_5585(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5588)
static void C_fcall f_5588(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5591)
static void C_fcall f_5591(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5594)
static void C_fcall f_5594(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5597)
static void C_fcall f_5597(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5600)
static void C_fcall f_5600(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5603)
static void C_fcall f_5603(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5606)
static void C_fcall f_5606(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5609)
static void C_fcall f_5609(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5612)
static void C_fcall f_5612(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5617)
static void C_fcall f_5617(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5622)
static void C_fcall f_5622(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5627)
static void C_fcall f_5627(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5632)
static void C_fcall f_5632(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5637)
static void C_fcall f_5637(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5640)
static void C_ccall f_5640(C_word c,C_word *av) C_noret;
C_noret_decl(f_5643)
static void C_ccall f_5643(C_word c,C_word *av) C_noret;
C_noret_decl(f_5646)
static void C_ccall f_5646(C_word c,C_word *av) C_noret;
C_noret_decl(f_5649)
static void C_ccall f_5649(C_word c,C_word *av) C_noret;
C_noret_decl(f_5652)
static void C_ccall f_5652(C_word c,C_word *av) C_noret;
C_noret_decl(f_5657)
static void C_ccall f_5657(C_word c,C_word *av) C_noret;
C_noret_decl(f_5660)
static void C_ccall f_5660(C_word c,C_word *av) C_noret;
C_noret_decl(f_5663)
static void C_fcall f_5663(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5666)
static void C_fcall f_5666(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5669)
static void C_fcall f_5669(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5672)
static void C_fcall f_5672(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5675)
static void C_fcall f_5675(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5678)
static void C_ccall f_5678(C_word c,C_word *av) C_noret;
C_noret_decl(f_5681)
static void C_ccall f_5681(C_word c,C_word *av) C_noret;
C_noret_decl(f_5684)
static void C_ccall f_5684(C_word c,C_word *av) C_noret;
C_noret_decl(f_5690)
static void C_ccall f_5690(C_word c,C_word *av) C_noret;
C_noret_decl(f_5693)
static void C_ccall f_5693(C_word c,C_word *av) C_noret;
C_noret_decl(f_5699)
static void C_ccall f_5699(C_word c,C_word *av) C_noret;
C_noret_decl(f_5706)
static void C_ccall f_5706(C_word c,C_word *av) C_noret;
C_noret_decl(f_5709)
static void C_ccall f_5709(C_word c,C_word *av) C_noret;
C_noret_decl(f_5714)
static void C_ccall f_5714(C_word c,C_word *av) C_noret;
C_noret_decl(f_5717)
static void C_ccall f_5717(C_word c,C_word *av) C_noret;
C_noret_decl(f_5732)
static void C_ccall f_5732(C_word c,C_word *av) C_noret;
C_noret_decl(f_5736)
static void C_ccall f_5736(C_word c,C_word *av) C_noret;
C_noret_decl(f_5744)
static void C_ccall f_5744(C_word c,C_word *av) C_noret;
C_noret_decl(f_5747)
static void C_ccall f_5747(C_word c,C_word *av) C_noret;
C_noret_decl(f_5750)
static void C_fcall f_5750(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5753)
static void C_ccall f_5753(C_word c,C_word *av) C_noret;
C_noret_decl(f_5757)
static void C_ccall f_5757(C_word c,C_word *av) C_noret;
C_noret_decl(f_5761)
static void C_ccall f_5761(C_word c,C_word *av) C_noret;
C_noret_decl(f_5764)
static void C_fcall f_5764(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5768)
static void C_ccall f_5768(C_word c,C_word *av) C_noret;
C_noret_decl(f_5772)
static void C_ccall f_5772(C_word c,C_word *av) C_noret;
C_noret_decl(f_5783)
static void C_ccall f_5783(C_word c,C_word *av) C_noret;
C_noret_decl(f_5786)
static void C_ccall f_5786(C_word c,C_word *av) C_noret;
C_noret_decl(f_5789)
static void C_fcall f_5789(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5792)
static void C_ccall f_5792(C_word c,C_word *av) C_noret;
C_noret_decl(f_5795)
static void C_ccall f_5795(C_word c,C_word *av) C_noret;
C_noret_decl(f_5798)
static void C_ccall f_5798(C_word c,C_word *av) C_noret;
C_noret_decl(f_5806)
static void C_ccall f_5806(C_word c,C_word *av) C_noret;
C_noret_decl(f_5817)
static void C_fcall f_5817(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5828)
static void C_ccall f_5828(C_word c,C_word *av) C_noret;
C_noret_decl(f_5835)
static void C_ccall f_5835(C_word c,C_word *av) C_noret;
C_noret_decl(f_5844)
static void C_ccall f_5844(C_word c,C_word *av) C_noret;
C_noret_decl(f_5847)
static void C_ccall f_5847(C_word c,C_word *av) C_noret;
C_noret_decl(f_5850)
static void C_ccall f_5850(C_word c,C_word *av) C_noret;
C_noret_decl(f_5856)
static void C_ccall f_5856(C_word c,C_word *av) C_noret;
C_noret_decl(f_5859)
static void C_ccall f_5859(C_word c,C_word *av) C_noret;
C_noret_decl(f_5862)
static void C_ccall f_5862(C_word c,C_word *av) C_noret;
C_noret_decl(f_5865)
static void C_ccall f_5865(C_word c,C_word *av) C_noret;
C_noret_decl(f_5868)
static void C_ccall f_5868(C_word c,C_word *av) C_noret;
C_noret_decl(f_5872)
static void C_ccall f_5872(C_word c,C_word *av) C_noret;
C_noret_decl(f_5876)
static void C_ccall f_5876(C_word c,C_word *av) C_noret;
C_noret_decl(f_5879)
static void C_ccall f_5879(C_word c,C_word *av) C_noret;
C_noret_decl(f_5882)
static void C_ccall f_5882(C_word c,C_word *av) C_noret;
C_noret_decl(f_5885)
static void C_ccall f_5885(C_word c,C_word *av) C_noret;
C_noret_decl(f_5888)
static void C_ccall f_5888(C_word c,C_word *av) C_noret;
C_noret_decl(f_5891)
static void C_ccall f_5891(C_word c,C_word *av) C_noret;
C_noret_decl(f_5894)
static void C_ccall f_5894(C_word c,C_word *av) C_noret;
C_noret_decl(f_5897)
static void C_fcall f_5897(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5900)
static void C_ccall f_5900(C_word c,C_word *av) C_noret;
C_noret_decl(f_5903)
static void C_ccall f_5903(C_word c,C_word *av) C_noret;
C_noret_decl(f_5912)
static void C_ccall f_5912(C_word c,C_word *av) C_noret;
C_noret_decl(f_5916)
static void C_fcall f_5916(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5922)
static void C_ccall f_5922(C_word c,C_word *av) C_noret;
C_noret_decl(f_5927)
static void C_ccall f_5927(C_word c,C_word *av) C_noret;
C_noret_decl(f_5933)
static void C_ccall f_5933(C_word c,C_word *av) C_noret;
C_noret_decl(f_5939)
static void C_ccall f_5939(C_word c,C_word *av) C_noret;
C_noret_decl(f_5942)
static void C_fcall f_5942(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5948)
static void C_ccall f_5948(C_word c,C_word *av) C_noret;
C_noret_decl(f_5963)
static void C_ccall f_5963(C_word c,C_word *av) C_noret;
C_noret_decl(f_5969)
static void C_ccall f_5969(C_word c,C_word *av) C_noret;
C_noret_decl(f_5972)
static void C_ccall f_5972(C_word c,C_word *av) C_noret;
C_noret_decl(f_5975)
static void C_ccall f_5975(C_word c,C_word *av) C_noret;
C_noret_decl(f_5978)
static void C_ccall f_5978(C_word c,C_word *av) C_noret;
C_noret_decl(f_5981)
static void C_ccall f_5981(C_word c,C_word *av) C_noret;
C_noret_decl(f_5984)
static void C_ccall f_5984(C_word c,C_word *av) C_noret;
C_noret_decl(f_5989)
static void C_ccall f_5989(C_word c,C_word *av) C_noret;
C_noret_decl(f_5992)
static void C_ccall f_5992(C_word c,C_word *av) C_noret;
C_noret_decl(f_5995)
static void C_ccall f_5995(C_word c,C_word *av) C_noret;
C_noret_decl(f_5998)
static void C_ccall f_5998(C_word c,C_word *av) C_noret;
C_noret_decl(f_6001)
static void C_ccall f_6001(C_word c,C_word *av) C_noret;
C_noret_decl(f_6004)
static void C_ccall f_6004(C_word c,C_word *av) C_noret;
C_noret_decl(f_6007)
static void C_ccall f_6007(C_word c,C_word *av) C_noret;
C_noret_decl(f_6010)
static void C_ccall f_6010(C_word c,C_word *av) C_noret;
C_noret_decl(f_6013)
static void C_ccall f_6013(C_word c,C_word *av) C_noret;
C_noret_decl(f_6016)
static void C_ccall f_6016(C_word c,C_word *av) C_noret;
C_noret_decl(f_6019)
static void C_ccall f_6019(C_word c,C_word *av) C_noret;
C_noret_decl(f_6022)
static void C_fcall f_6022(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6028)
static void C_ccall f_6028(C_word c,C_word *av) C_noret;
C_noret_decl(f_6031)
static void C_ccall f_6031(C_word c,C_word *av) C_noret;
C_noret_decl(f_6034)
static void C_ccall f_6034(C_word c,C_word *av) C_noret;
C_noret_decl(f_6037)
static void C_ccall f_6037(C_word c,C_word *av) C_noret;
C_noret_decl(f_6040)
static void C_ccall f_6040(C_word c,C_word *av) C_noret;
C_noret_decl(f_6045)
static void C_fcall f_6045(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_6049)
static void C_ccall f_6049(C_word c,C_word *av) C_noret;
C_noret_decl(f_6052)
static void C_ccall f_6052(C_word c,C_word *av) C_noret;
C_noret_decl(f_6055)
static void C_ccall f_6055(C_word c,C_word *av) C_noret;
C_noret_decl(f_6059)
static void C_ccall f_6059(C_word c,C_word *av) C_noret;
C_noret_decl(f_6062)
static void C_ccall f_6062(C_word c,C_word *av) C_noret;
C_noret_decl(f_6065)
static void C_ccall f_6065(C_word c,C_word *av) C_noret;
C_noret_decl(f_6071)
static void C_ccall f_6071(C_word c,C_word *av) C_noret;
C_noret_decl(f_6074)
static void C_ccall f_6074(C_word c,C_word *av) C_noret;
C_noret_decl(f_6079)
static void C_ccall f_6079(C_word c,C_word *av) C_noret;
C_noret_decl(f_6091)
static void C_ccall f_6091(C_word c,C_word *av) C_noret;
C_noret_decl(f_6095)
static void C_ccall f_6095(C_word c,C_word *av) C_noret;
C_noret_decl(f_6098)
static void C_ccall f_6098(C_word c,C_word *av) C_noret;
C_noret_decl(f_6115)
static void C_ccall f_6115(C_word c,C_word *av) C_noret;
C_noret_decl(f_6129)
static void C_ccall f_6129(C_word c,C_word *av) C_noret;
C_noret_decl(f_6141)
static void C_ccall f_6141(C_word c,C_word *av) C_noret;
C_noret_decl(f_6144)
static void C_ccall f_6144(C_word c,C_word *av) C_noret;
C_noret_decl(f_6147)
static void C_ccall f_6147(C_word c,C_word *av) C_noret;
C_noret_decl(f_6150)
static void C_ccall f_6150(C_word c,C_word *av) C_noret;
C_noret_decl(f_6153)
static void C_ccall f_6153(C_word c,C_word *av) C_noret;
C_noret_decl(f_6156)
static void C_ccall f_6156(C_word c,C_word *av) C_noret;
C_noret_decl(f_6172)
static void C_ccall f_6172(C_word c,C_word *av) C_noret;
C_noret_decl(f_6175)
static void C_ccall f_6175(C_word c,C_word *av) C_noret;
C_noret_decl(f_6178)
static void C_ccall f_6178(C_word c,C_word *av) C_noret;
C_noret_decl(f_6181)
static void C_ccall f_6181(C_word c,C_word *av) C_noret;
C_noret_decl(f_6185)
static void C_ccall f_6185(C_word c,C_word *av) C_noret;
C_noret_decl(f_6188)
static void C_ccall f_6188(C_word c,C_word *av) C_noret;
C_noret_decl(f_6191)
static void C_ccall f_6191(C_word c,C_word *av) C_noret;
C_noret_decl(f_6194)
static void C_ccall f_6194(C_word c,C_word *av) C_noret;
C_noret_decl(f_6197)
static void C_ccall f_6197(C_word c,C_word *av) C_noret;
C_noret_decl(f_6200)
static void C_ccall f_6200(C_word c,C_word *av) C_noret;
C_noret_decl(f_6203)
static void C_ccall f_6203(C_word c,C_word *av) C_noret;
C_noret_decl(f_6208)
static void C_ccall f_6208(C_word c,C_word *av) C_noret;
C_noret_decl(f_6214)
static void C_ccall f_6214(C_word c,C_word *av) C_noret;
C_noret_decl(f_6218)
static void C_ccall f_6218(C_word c,C_word *av) C_noret;
C_noret_decl(f_6221)
static void C_ccall f_6221(C_word c,C_word *av) C_noret;
C_noret_decl(f_6224)
static void C_ccall f_6224(C_word c,C_word *av) C_noret;
C_noret_decl(f_6227)
static void C_ccall f_6227(C_word c,C_word *av) C_noret;
C_noret_decl(f_6230)
static void C_ccall f_6230(C_word c,C_word *av) C_noret;
C_noret_decl(f_6233)
static void C_ccall f_6233(C_word c,C_word *av) C_noret;
C_noret_decl(f_6236)
static void C_ccall f_6236(C_word c,C_word *av) C_noret;
C_noret_decl(f_6239)
static void C_ccall f_6239(C_word c,C_word *av) C_noret;
C_noret_decl(f_6242)
static void C_ccall f_6242(C_word c,C_word *av) C_noret;
C_noret_decl(f_6245)
static void C_ccall f_6245(C_word c,C_word *av) C_noret;
C_noret_decl(f_6258)
static void C_ccall f_6258(C_word c,C_word *av) C_noret;
C_noret_decl(f_6267)
static void C_ccall f_6267(C_word c,C_word *av) C_noret;
C_noret_decl(f_6272)
static void C_ccall f_6272(C_word c,C_word *av) C_noret;
C_noret_decl(f_6296)
static void C_ccall f_6296(C_word c,C_word *av) C_noret;
C_noret_decl(f_6302)
static void C_ccall f_6302(C_word c,C_word *av) C_noret;
C_noret_decl(f_6315)
static void C_ccall f_6315(C_word c,C_word *av) C_noret;
C_noret_decl(f_6317)
static void C_fcall f_6317(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6342)
static void C_ccall f_6342(C_word c,C_word *av) C_noret;
C_noret_decl(f_6352)
static void C_ccall f_6352(C_word c,C_word *av) C_noret;
C_noret_decl(f_6355)
static void C_ccall f_6355(C_word c,C_word *av) C_noret;
C_noret_decl(f_6358)
static void C_ccall f_6358(C_word c,C_word *av) C_noret;
C_noret_decl(f_6361)
static void C_ccall f_6361(C_word c,C_word *av) C_noret;
C_noret_decl(f_6373)
static void C_ccall f_6373(C_word c,C_word *av) C_noret;
C_noret_decl(f_6376)
static void C_ccall f_6376(C_word c,C_word *av) C_noret;
C_noret_decl(f_6380)
static void C_ccall f_6380(C_word c,C_word *av) C_noret;
C_noret_decl(f_6389)
static void C_ccall f_6389(C_word c,C_word *av) C_noret;
C_noret_decl(f_6392)
static void C_ccall f_6392(C_word c,C_word *av) C_noret;
C_noret_decl(f_6395)
static void C_ccall f_6395(C_word c,C_word *av) C_noret;
C_noret_decl(f_6398)
static void C_ccall f_6398(C_word c,C_word *av) C_noret;
C_noret_decl(f_6401)
static void C_fcall f_6401(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6407)
static void C_ccall f_6407(C_word c,C_word *av) C_noret;
C_noret_decl(f_6451)
static void C_ccall f_6451(C_word c,C_word *av) C_noret;
C_noret_decl(f_6457)
static void C_ccall f_6457(C_word c,C_word *av) C_noret;
C_noret_decl(f_6462)
static void C_ccall f_6462(C_word c,C_word *av) C_noret;
C_noret_decl(f_6471)
static void C_ccall f_6471(C_word c,C_word *av) C_noret;
C_noret_decl(f_6477)
static void C_ccall f_6477(C_word c,C_word *av) C_noret;
C_noret_decl(f_6486)
static void C_ccall f_6486(C_word c,C_word *av) C_noret;
C_noret_decl(f_6490)
static void C_ccall f_6490(C_word c,C_word *av) C_noret;
C_noret_decl(f_6496)
static void C_ccall f_6496(C_word c,C_word *av) C_noret;
C_noret_decl(f_6499)
static void C_ccall f_6499(C_word c,C_word *av) C_noret;
C_noret_decl(f_6504)
static void C_ccall f_6504(C_word c,C_word *av) C_noret;
C_noret_decl(f_6507)
static void C_ccall f_6507(C_word c,C_word *av) C_noret;
C_noret_decl(f_6510)
static void C_ccall f_6510(C_word c,C_word *av) C_noret;
C_noret_decl(f_6513)
static void C_ccall f_6513(C_word c,C_word *av) C_noret;
C_noret_decl(f_6516)
static void C_ccall f_6516(C_word c,C_word *av) C_noret;
C_noret_decl(f_6519)
static void C_ccall f_6519(C_word c,C_word *av) C_noret;
C_noret_decl(f_6522)
static void C_ccall f_6522(C_word c,C_word *av) C_noret;
C_noret_decl(f_6525)
static void C_ccall f_6525(C_word c,C_word *av) C_noret;
C_noret_decl(f_6531)
static void C_fcall f_6531(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6541)
static void C_ccall f_6541(C_word c,C_word *av) C_noret;
C_noret_decl(f_6554)
static void C_fcall f_6554(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6564)
static void C_ccall f_6564(C_word c,C_word *av) C_noret;
C_noret_decl(f_6583)
static void C_ccall f_6583(C_word c,C_word *av) C_noret;
C_noret_decl(f_6595)
static void C_ccall f_6595(C_word c,C_word *av) C_noret;
C_noret_decl(f_6606)
static void C_fcall f_6606(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6616)
static void C_ccall f_6616(C_word c,C_word *av) C_noret;
C_noret_decl(f_6632)
static void C_ccall f_6632(C_word c,C_word *av) C_noret;
C_noret_decl(f_6638)
static void C_ccall f_6638(C_word c,C_word *av) C_noret;
C_noret_decl(f_6645)
static void C_ccall f_6645(C_word c,C_word *av) C_noret;
C_noret_decl(f_6653)
static void C_fcall f_6653(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6663)
static void C_ccall f_6663(C_word c,C_word *av) C_noret;
C_noret_decl(f_6678)
static void C_ccall f_6678(C_word c,C_word *av) C_noret;
C_noret_decl(f_6682)
static void C_ccall f_6682(C_word c,C_word *av) C_noret;
C_noret_decl(f_6685)
static void C_ccall f_6685(C_word c,C_word *av) C_noret;
C_noret_decl(f_6688)
static void C_ccall f_6688(C_word c,C_word *av) C_noret;
C_noret_decl(f_6698)
static void C_ccall f_6698(C_word c,C_word *av) C_noret;
C_noret_decl(f_6703)
static void C_fcall f_6703(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6728)
static void C_ccall f_6728(C_word c,C_word *av) C_noret;
C_noret_decl(f_6743)
static void C_ccall f_6743(C_word c,C_word *av) C_noret;
C_noret_decl(f_6749)
static void C_ccall f_6749(C_word c,C_word *av) C_noret;
C_noret_decl(f_6760)
static void C_ccall f_6760(C_word c,C_word *av) C_noret;
C_noret_decl(f_6764)
static void C_ccall f_6764(C_word c,C_word *av) C_noret;
C_noret_decl(f_6772)
static void C_ccall f_6772(C_word c,C_word *av) C_noret;
C_noret_decl(f_6775)
static void C_ccall f_6775(C_word c,C_word *av) C_noret;
C_noret_decl(f_6778)
static void C_ccall f_6778(C_word c,C_word *av) C_noret;
C_noret_decl(f_6781)
static void C_ccall f_6781(C_word c,C_word *av) C_noret;
C_noret_decl(f_6798)
static void C_fcall f_6798(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6808)
static void C_ccall f_6808(C_word c,C_word *av) C_noret;
C_noret_decl(f_6829)
static void C_ccall f_6829(C_word c,C_word *av) C_noret;
C_noret_decl(f_6848)
static void C_ccall f_6848(C_word c,C_word *av) C_noret;
C_noret_decl(f_6850)
static void C_fcall f_6850(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6875)
static void C_ccall f_6875(C_word c,C_word *av) C_noret;
C_noret_decl(f_6907)
static void C_ccall f_6907(C_word c,C_word *av) C_noret;
C_noret_decl(f_6911)
static void C_fcall f_6911(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6915)
static void C_ccall f_6915(C_word c,C_word *av) C_noret;
C_noret_decl(f_6941)
static void C_fcall f_6941(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6975)
static void C_fcall f_6975(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7000)
static void C_ccall f_7000(C_word c,C_word *av) C_noret;
C_noret_decl(f_7009)
static void C_fcall f_7009(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7034)
static void C_ccall f_7034(C_word c,C_word *av) C_noret;
C_noret_decl(f_7059)
static void C_ccall f_7059(C_word c,C_word *av) C_noret;
C_noret_decl(f_7065)
static void C_fcall f_7065(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7090)
static void C_ccall f_7090(C_word c,C_word *av) C_noret;
C_noret_decl(f_7100)
static void C_ccall f_7100(C_word c,C_word *av) C_noret;
C_noret_decl(f_7110)
static void C_ccall f_7110(C_word c,C_word *av) C_noret;
C_noret_decl(f_7112)
static void C_fcall f_7112(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7137)
static void C_ccall f_7137(C_word c,C_word *av) C_noret;
C_noret_decl(f_7147)
static void C_ccall f_7147(C_word c,C_word *av) C_noret;
C_noret_decl(f_7151)
static void C_ccall f_7151(C_word c,C_word *av) C_noret;
C_noret_decl(f_7156)
static void C_fcall f_7156(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7167)
static void C_ccall f_7167(C_word c,C_word *av) C_noret;
C_noret_decl(f_7177)
static void C_ccall f_7177(C_word c,C_word *av) C_noret;
C_noret_decl(f_7181)
static void C_ccall f_7181(C_word c,C_word *av) C_noret;
C_noret_decl(f_7191)
static void C_ccall f_7191(C_word c,C_word *av) C_noret;
C_noret_decl(f_7193)
static void C_fcall f_7193(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7218)
static void C_ccall f_7218(C_word c,C_word *av) C_noret;
C_noret_decl(f_7227)
static void C_fcall f_7227(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7252)
static void C_ccall f_7252(C_word c,C_word *av) C_noret;
C_noret_decl(f_7265)
static void C_ccall f_7265(C_word c,C_word *av) C_noret;
C_noret_decl(f_7268)
static void C_ccall f_7268(C_word c,C_word *av) C_noret;
C_noret_decl(f_7275)
static void C_ccall f_7275(C_word c,C_word *av) C_noret;
C_noret_decl(f_7280)
static void C_ccall f_7280(C_word c,C_word *av) C_noret;
C_noret_decl(f_7286)
static void C_fcall f_7286(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7290)
static void C_ccall f_7290(C_word c,C_word *av) C_noret;
C_noret_decl(f_7308)
static void C_ccall f_7308(C_word c,C_word *av) C_noret;
C_noret_decl(f_7315)
static void C_ccall f_7315(C_word c,C_word *av) C_noret;
C_noret_decl(f_7323)
static void C_ccall f_7323(C_word c,C_word *av) C_noret;
C_noret_decl(f_7341)
static void C_ccall f_7341(C_word c,C_word *av) C_noret;
C_noret_decl(f_7347)
static void C_ccall f_7347(C_word c,C_word *av) C_noret;
C_noret_decl(f_7396)
static void C_ccall f_7396(C_word c,C_word *av) C_noret;
C_noret_decl(f_7403)
static void C_ccall f_7403(C_word c,C_word *av) C_noret;
C_noret_decl(f_7419)
static void C_ccall f_7419(C_word c,C_word *av) C_noret;
C_noret_decl(f_7422)
static void C_ccall f_7422(C_word c,C_word *av) C_noret;
C_noret_decl(f_7428)
static void C_ccall f_7428(C_word c,C_word *av) C_noret;
C_noret_decl(f_7430)
static void C_fcall f_7430(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7464)
static void C_ccall f_7464(C_word c,C_word *av) C_noret;
C_noret_decl(f_7471)
static void C_ccall f_7471(C_word c,C_word *av) C_noret;
C_noret_decl(f_7476)
static void C_fcall f_7476(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7501)
static void C_ccall f_7501(C_word c,C_word *av) C_noret;
C_noret_decl(f_7512)
static void C_ccall f_7512(C_word c,C_word *av) C_noret;
C_noret_decl(f_7519)
static void C_ccall f_7519(C_word c,C_word *av) C_noret;
C_noret_decl(f_7533)
static void C_ccall f_7533(C_word c,C_word *av) C_noret;
C_noret_decl(f_7540)
static void C_ccall f_7540(C_word c,C_word *av) C_noret;
C_noret_decl(f_7545)
static void C_fcall f_7545(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7570)
static void C_ccall f_7570(C_word c,C_word *av) C_noret;
C_noret_decl(f_7581)
static void C_ccall f_7581(C_word c,C_word *av) C_noret;
C_noret_decl(f_7583)
static void C_fcall f_7583(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7593)
static void C_ccall f_7593(C_word c,C_word *av) C_noret;
C_noret_decl(f_7606)
static void C_fcall f_7606(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7616)
static void C_ccall f_7616(C_word c,C_word *av) C_noret;
C_noret_decl(f_7629)
static void C_ccall f_7629(C_word c,C_word *av) C_noret;
C_noret_decl(f_7637)
static void C_ccall f_7637(C_word c,C_word *av) C_noret;
C_noret_decl(f_7639)
static void C_fcall f_7639(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7649)
static void C_ccall f_7649(C_word c,C_word *av) C_noret;
C_noret_decl(f_7662)
static void C_ccall f_7662(C_word c,C_word *av) C_noret;
C_noret_decl(f_7670)
static void C_ccall f_7670(C_word c,C_word *av) C_noret;
C_noret_decl(f_7683)
static void C_ccall f_7683(C_word c,C_word *av) C_noret;
C_noret_decl(f_7692)
static void C_ccall f_7692(C_word c,C_word *av) C_noret;
C_noret_decl(f_7697)
static void C_ccall f_7697(C_word c,C_word *av) C_noret;
C_noret_decl(f_7708)
static void C_fcall f_7708(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7718)
static void C_ccall f_7718(C_word c,C_word *av) C_noret;
C_noret_decl(f_7731)
static void C_fcall f_7731(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7741)
static void C_ccall f_7741(C_word c,C_word *av) C_noret;
C_noret_decl(f_7786)
static void C_ccall f_7786(C_word c,C_word *av) C_noret;
C_noret_decl(f_7792)
static void C_ccall f_7792(C_word c,C_word *av) C_noret;
C_noret_decl(f_7794)
static void C_fcall f_7794(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7804)
static void C_fcall f_7804(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7819)
static void C_ccall f_7819(C_word c,C_word *av) C_noret;
C_noret_decl(f_7831)
static void C_ccall f_7831(C_word c,C_word *av) C_noret;
C_noret_decl(f_7834)
static void C_ccall f_7834(C_word c,C_word *av) C_noret;
C_noret_decl(f_7837)
static void C_ccall f_7837(C_word c,C_word *av) C_noret;
C_noret_decl(f_7840)
static void C_ccall f_7840(C_word c,C_word *av) C_noret;
C_noret_decl(f_7848)
static void C_ccall f_7848(C_word c,C_word *av) C_noret;
C_noret_decl(f_7856)
static void C_ccall f_7856(C_word c,C_word *av) C_noret;
C_noret_decl(f_7862)
static void C_ccall f_7862(C_word c,C_word *av) C_noret;
C_noret_decl(f_7895)
static void C_ccall f_7895(C_word c,C_word *av) C_noret;
C_noret_decl(f_7898)
static void C_ccall f_7898(C_word c,C_word *av) C_noret;
C_noret_decl(f_7905)
static void C_ccall f_7905(C_word c,C_word *av) C_noret;
C_noret_decl(f_7908)
static void C_ccall f_7908(C_word c,C_word *av) C_noret;
C_noret_decl(f_7911)
static void C_ccall f_7911(C_word c,C_word *av) C_noret;
C_noret_decl(f_7918)
static void C_ccall f_7918(C_word c,C_word *av) C_noret;
C_noret_decl(f_7921)
static void C_ccall f_7921(C_word c,C_word *av) C_noret;
C_noret_decl(f_7924)
static void C_ccall f_7924(C_word c,C_word *av) C_noret;
C_noret_decl(f_7931)
static void C_ccall f_7931(C_word c,C_word *av) C_noret;
C_noret_decl(f_7937)
static void C_ccall f_7937(C_word c,C_word *av) C_noret;
C_noret_decl(f_7941)
static void C_ccall f_7941(C_word c,C_word *av) C_noret;
C_noret_decl(f_7973)
static void C_ccall f_7973(C_word c,C_word *av) C_noret;
C_noret_decl(f_8024)
static void C_fcall f_8024(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8062)
static void C_ccall f_8062(C_word c,C_word *av) C_noret;
C_noret_decl(f_8067)
static void C_ccall f_8067(C_word c,C_word *av) C_noret;
C_noret_decl(f_8083)
static void C_ccall f_8083(C_word c,C_word *av) C_noret;
C_noret_decl(f_8088)
static void C_fcall f_8088(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8113)
static void C_ccall f_8113(C_word c,C_word *av) C_noret;
C_noret_decl(f_8124)
static void C_ccall f_8124(C_word c,C_word *av) C_noret;
C_noret_decl(f_8138)
static void C_ccall f_8138(C_word c,C_word *av) C_noret;
C_noret_decl(f_8142)
static void C_ccall f_8142(C_word c,C_word *av) C_noret;
C_noret_decl(f_8158)
static void C_fcall f_8158(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8162)
static void C_ccall f_8162(C_word c,C_word *av) C_noret;
C_noret_decl(f_8186)
static void C_ccall f_8186(C_word c,C_word *av) C_noret;
C_noret_decl(f_8212)
static void C_ccall f_8212(C_word c,C_word *av) C_noret;
C_noret_decl(f_8220)
static void C_fcall f_8220(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8227)
static void C_fcall f_8227(C_word t0,C_word t1) C_noret;
C_noret_decl(C_batch_2ddriver_toplevel)
C_externexport void C_ccall C_batch_2ddriver_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_2956)
static void C_ccall trf_2956(C_word c,C_word *av) C_noret;
static void C_ccall trf_2956(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2956(t0,t1,t2,t3);}

C_noret_decl(trf_2971)
static void C_ccall trf_2971(C_word c,C_word *av) C_noret;
static void C_ccall trf_2971(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2971(t0,t1,t2);}

C_noret_decl(trf_2979)
static void C_ccall trf_2979(C_word c,C_word *av) C_noret;
static void C_ccall trf_2979(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2979(t0,t1,t2,t3);}

C_noret_decl(trf_3011)
static void C_ccall trf_3011(C_word c,C_word *av) C_noret;
static void C_ccall trf_3011(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3011(t0,t1,t2);}

C_noret_decl(trf_3043)
static void C_ccall trf_3043(C_word c,C_word *av) C_noret;
static void C_ccall trf_3043(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3043(t0,t1,t2);}

C_noret_decl(trf_3092)
static void C_ccall trf_3092(C_word c,C_word *av) C_noret;
static void C_ccall trf_3092(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3092(t0,t1,t2);}

C_noret_decl(trf_3160)
static void C_ccall trf_3160(C_word c,C_word *av) C_noret;
static void C_ccall trf_3160(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3160(t0,t1,t2);}

C_noret_decl(trf_3166)
static void C_ccall trf_3166(C_word c,C_word *av) C_noret;
static void C_ccall trf_3166(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3166(t0,t1,t2);}

C_noret_decl(trf_3252)
static void C_ccall trf_3252(C_word c,C_word *av) C_noret;
static void C_ccall trf_3252(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3252(t0,t1,t2);}

C_noret_decl(trf_3677)
static void C_ccall trf_3677(C_word c,C_word *av) C_noret;
static void C_ccall trf_3677(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3677(t0,t1,t2,t3);}

C_noret_decl(trf_3702)
static void C_ccall trf_3702(C_word c,C_word *av) C_noret;
static void C_ccall trf_3702(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3702(t0,t1,t2,t3);}

C_noret_decl(trf_4134)
static void C_ccall trf_4134(C_word c,C_word *av) C_noret;
static void C_ccall trf_4134(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4134(t0,t1);}

C_noret_decl(trf_4174)
static void C_ccall trf_4174(C_word c,C_word *av) C_noret;
static void C_ccall trf_4174(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4174(t0,t1,t2);}

C_noret_decl(trf_4197)
static void C_ccall trf_4197(C_word c,C_word *av) C_noret;
static void C_ccall trf_4197(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4197(t0,t1,t2);}

C_noret_decl(trf_4220)
static void C_ccall trf_4220(C_word c,C_word *av) C_noret;
static void C_ccall trf_4220(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4220(t0,t1,t2);}

C_noret_decl(trf_4243)
static void C_ccall trf_4243(C_word c,C_word *av) C_noret;
static void C_ccall trf_4243(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4243(t0,t1,t2);}

C_noret_decl(trf_4247)
static void C_ccall trf_4247(C_word c,C_word *av) C_noret;
static void C_ccall trf_4247(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4247(t0,t1);}

C_noret_decl(trf_4317)
static void C_ccall trf_4317(C_word c,C_word *av) C_noret;
static void C_ccall trf_4317(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4317(t0,t1,t2);}

C_noret_decl(trf_4453)
static void C_ccall trf_4453(C_word c,C_word *av) C_noret;
static void C_ccall trf_4453(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4453(t0,t1,t2);}

C_noret_decl(trf_4477)
static void C_ccall trf_4477(C_word c,C_word *av) C_noret;
static void C_ccall trf_4477(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4477(t0,t1);}

C_noret_decl(trf_4556)
static void C_ccall trf_4556(C_word c,C_word *av) C_noret;
static void C_ccall trf_4556(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4556(t0,t1);}

C_noret_decl(trf_4883)
static void C_ccall trf_4883(C_word c,C_word *av) C_noret;
static void C_ccall trf_4883(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4883(t0,t1);}

C_noret_decl(trf_4923)
static void C_ccall trf_4923(C_word c,C_word *av) C_noret;
static void C_ccall trf_4923(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4923(t0,t1);}

C_noret_decl(trf_4926)
static void C_ccall trf_4926(C_word c,C_word *av) C_noret;
static void C_ccall trf_4926(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4926(t0,t1);}

C_noret_decl(trf_4939)
static void C_ccall trf_4939(C_word c,C_word *av) C_noret;
static void C_ccall trf_4939(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4939(t0,t1);}

C_noret_decl(trf_4952)
static void C_ccall trf_4952(C_word c,C_word *av) C_noret;
static void C_ccall trf_4952(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4952(t0,t1);}

C_noret_decl(trf_4995)
static void C_ccall trf_4995(C_word c,C_word *av) C_noret;
static void C_ccall trf_4995(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4995(t0,t1,t2);}

C_noret_decl(trf_5022)
static void C_ccall trf_5022(C_word c,C_word *av) C_noret;
static void C_ccall trf_5022(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5022(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5044)
static void C_ccall trf_5044(C_word c,C_word *av) C_noret;
static void C_ccall trf_5044(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_5044(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_5071)
static void C_ccall trf_5071(C_word c,C_word *av) C_noret;
static void C_ccall trf_5071(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5071(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5094)
static void C_ccall trf_5094(C_word c,C_word *av) C_noret;
static void C_ccall trf_5094(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5094(t0,t1,t2);}

C_noret_decl(trf_5127)
static void C_ccall trf_5127(C_word c,C_word *av) C_noret;
static void C_ccall trf_5127(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5127(t0,t1,t2,t3);}

C_noret_decl(trf_5242)
static void C_ccall trf_5242(C_word c,C_word *av) C_noret;
static void C_ccall trf_5242(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5242(t0,t1);}

C_noret_decl(trf_5327)
static void C_ccall trf_5327(C_word c,C_word *av) C_noret;
static void C_ccall trf_5327(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5327(t0,t1,t2);}

C_noret_decl(trf_5333)
static void C_ccall trf_5333(C_word c,C_word *av) C_noret;
static void C_ccall trf_5333(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5333(t0,t1,t2);}

C_noret_decl(trf_5341)
static void C_ccall trf_5341(C_word c,C_word *av) C_noret;
static void C_ccall trf_5341(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5341(t0,t1,t2);}

C_noret_decl(trf_5362)
static void C_ccall trf_5362(C_word c,C_word *av) C_noret;
static void C_ccall trf_5362(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5362(t0,t1);}

C_noret_decl(trf_5372)
static void C_ccall trf_5372(C_word c,C_word *av) C_noret;
static void C_ccall trf_5372(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5372(t0,t1,t2);}

C_noret_decl(trf_5412)
static void C_ccall trf_5412(C_word c,C_word *av) C_noret;
static void C_ccall trf_5412(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5412(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5414)
static void C_ccall trf_5414(C_word c,C_word *av) C_noret;
static void C_ccall trf_5414(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5414(t0,t1,t2,t3);}

C_noret_decl(trf_5437)
static void C_ccall trf_5437(C_word c,C_word *av) C_noret;
static void C_ccall trf_5437(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5437(t0,t1,t2);}

C_noret_decl(trf_5442)
static void C_ccall trf_5442(C_word c,C_word *av) C_noret;
static void C_ccall trf_5442(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5442(t0,t1);}

C_noret_decl(trf_5501)
static void C_ccall trf_5501(C_word c,C_word *av) C_noret;
static void C_ccall trf_5501(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5501(t0,t1);}

C_noret_decl(trf_5504)
static void C_ccall trf_5504(C_word c,C_word *av) C_noret;
static void C_ccall trf_5504(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5504(t0,t1);}

C_noret_decl(trf_5552)
static void C_ccall trf_5552(C_word c,C_word *av) C_noret;
static void C_ccall trf_5552(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5552(t0,t1);}

C_noret_decl(trf_5555)
static void C_ccall trf_5555(C_word c,C_word *av) C_noret;
static void C_ccall trf_5555(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5555(t0,t1);}

C_noret_decl(trf_5561)
static void C_ccall trf_5561(C_word c,C_word *av) C_noret;
static void C_ccall trf_5561(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5561(t0,t1);}

C_noret_decl(trf_5564)
static void C_ccall trf_5564(C_word c,C_word *av) C_noret;
static void C_ccall trf_5564(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5564(t0,t1);}

C_noret_decl(trf_5567)
static void C_ccall trf_5567(C_word c,C_word *av) C_noret;
static void C_ccall trf_5567(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5567(t0,t1);}

C_noret_decl(trf_5570)
static void C_ccall trf_5570(C_word c,C_word *av) C_noret;
static void C_ccall trf_5570(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5570(t0,t1);}

C_noret_decl(trf_5573)
static void C_ccall trf_5573(C_word c,C_word *av) C_noret;
static void C_ccall trf_5573(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5573(t0,t1);}

C_noret_decl(trf_5576)
static void C_ccall trf_5576(C_word c,C_word *av) C_noret;
static void C_ccall trf_5576(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5576(t0,t1);}

C_noret_decl(trf_5579)
static void C_ccall trf_5579(C_word c,C_word *av) C_noret;
static void C_ccall trf_5579(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5579(t0,t1);}

C_noret_decl(trf_5582)
static void C_ccall trf_5582(C_word c,C_word *av) C_noret;
static void C_ccall trf_5582(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5582(t0,t1);}

C_noret_decl(trf_5585)
static void C_ccall trf_5585(C_word c,C_word *av) C_noret;
static void C_ccall trf_5585(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5585(t0,t1);}

C_noret_decl(trf_5588)
static void C_ccall trf_5588(C_word c,C_word *av) C_noret;
static void C_ccall trf_5588(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5588(t0,t1);}

C_noret_decl(trf_5591)
static void C_ccall trf_5591(C_word c,C_word *av) C_noret;
static void C_ccall trf_5591(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5591(t0,t1);}

C_noret_decl(trf_5594)
static void C_ccall trf_5594(C_word c,C_word *av) C_noret;
static void C_ccall trf_5594(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5594(t0,t1);}

C_noret_decl(trf_5597)
static void C_ccall trf_5597(C_word c,C_word *av) C_noret;
static void C_ccall trf_5597(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5597(t0,t1);}

C_noret_decl(trf_5600)
static void C_ccall trf_5600(C_word c,C_word *av) C_noret;
static void C_ccall trf_5600(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5600(t0,t1);}

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

C_noret_decl(trf_5609)
static void C_ccall trf_5609(C_word c,C_word *av) C_noret;
static void C_ccall trf_5609(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5609(t0,t1);}

C_noret_decl(trf_5612)
static void C_ccall trf_5612(C_word c,C_word *av) C_noret;
static void C_ccall trf_5612(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5612(t0,t1);}

C_noret_decl(trf_5617)
static void C_ccall trf_5617(C_word c,C_word *av) C_noret;
static void C_ccall trf_5617(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5617(t0,t1);}

C_noret_decl(trf_5622)
static void C_ccall trf_5622(C_word c,C_word *av) C_noret;
static void C_ccall trf_5622(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5622(t0,t1);}

C_noret_decl(trf_5627)
static void C_ccall trf_5627(C_word c,C_word *av) C_noret;
static void C_ccall trf_5627(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5627(t0,t1);}

C_noret_decl(trf_5632)
static void C_ccall trf_5632(C_word c,C_word *av) C_noret;
static void C_ccall trf_5632(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5632(t0,t1);}

C_noret_decl(trf_5637)
static void C_ccall trf_5637(C_word c,C_word *av) C_noret;
static void C_ccall trf_5637(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5637(t0,t1);}

C_noret_decl(trf_5663)
static void C_ccall trf_5663(C_word c,C_word *av) C_noret;
static void C_ccall trf_5663(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5663(t0,t1);}

C_noret_decl(trf_5666)
static void C_ccall trf_5666(C_word c,C_word *av) C_noret;
static void C_ccall trf_5666(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5666(t0,t1);}

C_noret_decl(trf_5669)
static void C_ccall trf_5669(C_word c,C_word *av) C_noret;
static void C_ccall trf_5669(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5669(t0,t1);}

C_noret_decl(trf_5672)
static void C_ccall trf_5672(C_word c,C_word *av) C_noret;
static void C_ccall trf_5672(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5672(t0,t1);}

C_noret_decl(trf_5675)
static void C_ccall trf_5675(C_word c,C_word *av) C_noret;
static void C_ccall trf_5675(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5675(t0,t1);}

C_noret_decl(trf_5750)
static void C_ccall trf_5750(C_word c,C_word *av) C_noret;
static void C_ccall trf_5750(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5750(t0,t1);}

C_noret_decl(trf_5764)
static void C_ccall trf_5764(C_word c,C_word *av) C_noret;
static void C_ccall trf_5764(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5764(t0,t1);}

C_noret_decl(trf_5789)
static void C_ccall trf_5789(C_word c,C_word *av) C_noret;
static void C_ccall trf_5789(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5789(t0,t1);}

C_noret_decl(trf_5817)
static void C_ccall trf_5817(C_word c,C_word *av) C_noret;
static void C_ccall trf_5817(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5817(t0,t1);}

C_noret_decl(trf_5897)
static void C_ccall trf_5897(C_word c,C_word *av) C_noret;
static void C_ccall trf_5897(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5897(t0,t1);}

C_noret_decl(trf_5916)
static void C_ccall trf_5916(C_word c,C_word *av) C_noret;
static void C_ccall trf_5916(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5916(t0,t1,t2);}

C_noret_decl(trf_5942)
static void C_ccall trf_5942(C_word c,C_word *av) C_noret;
static void C_ccall trf_5942(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5942(t0,t1);}

C_noret_decl(trf_6022)
static void C_ccall trf_6022(C_word c,C_word *av) C_noret;
static void C_ccall trf_6022(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6022(t0,t1);}

C_noret_decl(trf_6045)
static void C_ccall trf_6045(C_word c,C_word *av) C_noret;
static void C_ccall trf_6045(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_6045(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_6317)
static void C_ccall trf_6317(C_word c,C_word *av) C_noret;
static void C_ccall trf_6317(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6317(t0,t1,t2);}

C_noret_decl(trf_6401)
static void C_ccall trf_6401(C_word c,C_word *av) C_noret;
static void C_ccall trf_6401(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6401(t0,t1);}

C_noret_decl(trf_6531)
static void C_ccall trf_6531(C_word c,C_word *av) C_noret;
static void C_ccall trf_6531(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6531(t0,t1,t2);}

C_noret_decl(trf_6554)
static void C_ccall trf_6554(C_word c,C_word *av) C_noret;
static void C_ccall trf_6554(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6554(t0,t1,t2);}

C_noret_decl(trf_6606)
static void C_ccall trf_6606(C_word c,C_word *av) C_noret;
static void C_ccall trf_6606(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6606(t0,t1,t2);}

C_noret_decl(trf_6653)
static void C_ccall trf_6653(C_word c,C_word *av) C_noret;
static void C_ccall trf_6653(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6653(t0,t1,t2);}

C_noret_decl(trf_6703)
static void C_ccall trf_6703(C_word c,C_word *av) C_noret;
static void C_ccall trf_6703(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6703(t0,t1,t2);}

C_noret_decl(trf_6798)
static void C_ccall trf_6798(C_word c,C_word *av) C_noret;
static void C_ccall trf_6798(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6798(t0,t1,t2);}

C_noret_decl(trf_6850)
static void C_ccall trf_6850(C_word c,C_word *av) C_noret;
static void C_ccall trf_6850(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6850(t0,t1,t2);}

C_noret_decl(trf_6911)
static void C_ccall trf_6911(C_word c,C_word *av) C_noret;
static void C_ccall trf_6911(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6911(t0,t1);}

C_noret_decl(trf_6941)
static void C_ccall trf_6941(C_word c,C_word *av) C_noret;
static void C_ccall trf_6941(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6941(t0,t1,t2);}

C_noret_decl(trf_6975)
static void C_ccall trf_6975(C_word c,C_word *av) C_noret;
static void C_ccall trf_6975(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6975(t0,t1,t2);}

C_noret_decl(trf_7009)
static void C_ccall trf_7009(C_word c,C_word *av) C_noret;
static void C_ccall trf_7009(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7009(t0,t1,t2);}

C_noret_decl(trf_7065)
static void C_ccall trf_7065(C_word c,C_word *av) C_noret;
static void C_ccall trf_7065(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7065(t0,t1,t2);}

C_noret_decl(trf_7112)
static void C_ccall trf_7112(C_word c,C_word *av) C_noret;
static void C_ccall trf_7112(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7112(t0,t1,t2);}

C_noret_decl(trf_7156)
static void C_ccall trf_7156(C_word c,C_word *av) C_noret;
static void C_ccall trf_7156(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7156(t0,t1,t2);}

C_noret_decl(trf_7193)
static void C_ccall trf_7193(C_word c,C_word *av) C_noret;
static void C_ccall trf_7193(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7193(t0,t1,t2);}

C_noret_decl(trf_7227)
static void C_ccall trf_7227(C_word c,C_word *av) C_noret;
static void C_ccall trf_7227(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7227(t0,t1,t2);}

C_noret_decl(trf_7286)
static void C_ccall trf_7286(C_word c,C_word *av) C_noret;
static void C_ccall trf_7286(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7286(t0,t1);}

C_noret_decl(trf_7430)
static void C_ccall trf_7430(C_word c,C_word *av) C_noret;
static void C_ccall trf_7430(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7430(t0,t1,t2);}

C_noret_decl(trf_7476)
static void C_ccall trf_7476(C_word c,C_word *av) C_noret;
static void C_ccall trf_7476(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7476(t0,t1,t2);}

C_noret_decl(trf_7545)
static void C_ccall trf_7545(C_word c,C_word *av) C_noret;
static void C_ccall trf_7545(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7545(t0,t1,t2);}

C_noret_decl(trf_7583)
static void C_ccall trf_7583(C_word c,C_word *av) C_noret;
static void C_ccall trf_7583(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7583(t0,t1,t2);}

C_noret_decl(trf_7606)
static void C_ccall trf_7606(C_word c,C_word *av) C_noret;
static void C_ccall trf_7606(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7606(t0,t1,t2);}

C_noret_decl(trf_7639)
static void C_ccall trf_7639(C_word c,C_word *av) C_noret;
static void C_ccall trf_7639(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7639(t0,t1,t2);}

C_noret_decl(trf_7708)
static void C_ccall trf_7708(C_word c,C_word *av) C_noret;
static void C_ccall trf_7708(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7708(t0,t1,t2);}

C_noret_decl(trf_7731)
static void C_ccall trf_7731(C_word c,C_word *av) C_noret;
static void C_ccall trf_7731(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7731(t0,t1,t2);}

C_noret_decl(trf_7794)
static void C_ccall trf_7794(C_word c,C_word *av) C_noret;
static void C_ccall trf_7794(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7794(t0,t1,t2);}

C_noret_decl(trf_7804)
static void C_ccall trf_7804(C_word c,C_word *av) C_noret;
static void C_ccall trf_7804(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7804(t0,t1);}

C_noret_decl(trf_8024)
static void C_ccall trf_8024(C_word c,C_word *av) C_noret;
static void C_ccall trf_8024(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8024(t0,t1,t2);}

C_noret_decl(trf_8088)
static void C_ccall trf_8088(C_word c,C_word *av) C_noret;
static void C_ccall trf_8088(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8088(t0,t1,t2);}

C_noret_decl(trf_8158)
static void C_ccall trf_8158(C_word c,C_word *av) C_noret;
static void C_ccall trf_8158(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8158(t0,t1,t2);}

C_noret_decl(trf_8220)
static void C_ccall trf_8220(C_word c,C_word *av) C_noret;
static void C_ccall trf_8220(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8220(t0,t1);}

C_noret_decl(trf_8227)
static void C_ccall trf_8227(C_word c,C_word *av) C_noret;
static void C_ccall trf_8227(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8227(t0,t1);}

/* f8775 in k6237 in k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in ... */
static void C_ccall f8775(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f8775,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9437,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t2;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[184];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}

/* f9431 in k6243 in k6240 in k6237 in k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in ... */
static void C_ccall f9431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9431,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9437 */
static void C_ccall f9437(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9437,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9443 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in ... */
static void C_ccall f9443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9443,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9449 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in ... */
static void C_ccall f9449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9449,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9457 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f9457(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9457,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9463 in k6399 in k6396 in k6393 in k6390 in k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in ... */
static void C_ccall f9463(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9463,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9475 in for-each-loop2013 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in ... */
static void C_ccall f9475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9475,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9483 in k6630 in for-each-loop1991 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in ... */
static void C_ccall f9483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9483,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9493 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in ... */
static void C_ccall f9493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9493,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9513 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f9513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9513,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9519 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in ... */
static void C_ccall f9519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9519,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9533 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in ... */
static void C_ccall f9533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9533,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9539 in k7345 in k7339 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in ... */
static void C_ccall f9539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9539,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9545 in k7345 in k7339 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in ... */
static void C_ccall f9545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9545,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9551 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in ... */
static void C_ccall f9551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9551,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9557 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in ... */
static void C_ccall f9557(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9557,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9579 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in ... */
static void C_ccall f9579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9579,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9595 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f9595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9595,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9601 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in ... */
static void C_ccall f9601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9601,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9607 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in ... */
static void C_ccall f9607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9607,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9613 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in ... */
static void C_ccall f9613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9613,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* f9619 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in ... */
static void C_ccall f9619(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f9619,c,av);}
/* batch-driver.scm:257: chicken.compiler.support#debugging */
t2=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[104];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k2705 */
static void C_ccall f_2707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2707,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2710,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k2708 in k2705 */
static void C_ccall f_2710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2710,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2713,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k2711 in k2708 in k2705 */
static void C_ccall f_2713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2713,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2716,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2716,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2719,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2719,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2722,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2722,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2725,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_support_toplevel(2,av2);}}

/* k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2725,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2728,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_compiler_2dsyntax_toplevel(2,av2);}}

/* k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2728,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2731,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_compiler_toplevel(2,av2);}}

/* k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2731,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2734,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_optimizer_toplevel(2,av2);}}

/* k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2734,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2737,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2737,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2740,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_scrutinizer_toplevel(2,av2);}}

/* k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2740(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2740,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2743,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_lfa2_toplevel(2,av2);}}

/* k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2743,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2746,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_c_2dplatform_toplevel(2,av2);}}

/* k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2746(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2746,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2749,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_c_2dbackend_toplevel(2,av2);}}

/* k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2749,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2752,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_user_2dpass_toplevel(2,av2);}}

/* k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2752(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_2752,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2755,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_port_toplevel(2,av2);}}

/* k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2755(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,5)))){
C_save_and_reclaim((void *)f_2755,c,av);}
a=C_alloc(16);
t2=C_mutate(&lf[2] /* (set! chicken.compiler.batch-driver#append-map ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_2956,tmp=(C_word)a,a+=2,tmp));
t3=C_mutate(&lf[6] /* (set! chicken.compiler.batch-driver#any ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3160,tmp=(C_word)a,a+=2,tmp));
t4=C_SCHEME_TRUE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_mutate(&lf[8] /* (set! chicken.compiler.batch-driver#initialize-analysis-database ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4134,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=C_SCHEME_FALSE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_mutate(&lf[18] /* (set! chicken.compiler.batch-driver#display-analysis-database ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4243,a[2]=t8,tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[79]+1 /* (set! chicken.compiler.batch-driver#compile-source-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4880,tmp=(C_word)a,a+=2,tmp));
t11=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t11;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}

/* chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_2956(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_2956,4,t1,t2,t3,t4);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t4))){
t5=C_i_check_list_2(t3,lf[3]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2971,a[2]=t2,a[3]=t7,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_2971(t9,t1,t3);}
else{
t5=C_a_i_cons(&a,2,t3,t4);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3011,a[2]=t7,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_3011(t9,t1,t5);}}

/* foldr284 in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_2971(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_2971,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2979,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2998,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g289 in foldr284 in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_2979(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_2979,4,t0,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2987,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:72: proc */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2985 in g289 in foldr284 in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2987(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2987,c,av);}
/* mini-srfi-1.scm:72: scheme#append */
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

/* k2996 in foldr284 in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_2998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2998,c,av);}
/* mini-srfi-1.scm:72: g289 */
t2=((C_word*)t0)[2];
f_2979(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_3011(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3011,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3018,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* mini-srfi-1.scm:74: any */
f_3160(t3,*((C_word*)lf[7]+1),t2);}

/* k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_3018(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_3018,c,av);}
a=C_alloc(21);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3025,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[5]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3090,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3092,a[2]=t5,a[3]=t10,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t12=((C_word*)t10)[1];
f_3092(t12,t8,((C_word*)t0)[4]);}}

/* k3023 in k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_3025(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_3025,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3029,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3041,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3043,a[2]=t5,a[3]=t9,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_3043(t11,t7,((C_word*)t0)[4]);}

/* k3027 in k3023 in k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_ccall f_3029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3029,c,av);}
/* mini-srfi-1.scm:76: scheme#append */
t2=*((C_word*)lf[4]+1);{
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

/* k3039 in k3023 in k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_ccall f_3041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3041,c,av);}
/* mini-srfi-1.scm:77: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3011(t2,((C_word*)t0)[3],t1);}

/* map-loop326 in k3023 in k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_fcall f_3043(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_3043,3,t0,t1,t2);}
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

/* k3088 in k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_3090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3090,c,av);}{
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

/* map-loop299 in k3016 in loop in chicken.compiler.batch-driver#append-map in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_3092(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_3092,3,t0,t1,t2);}
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

/* chicken.compiler.batch-driver#any in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_3160(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_3160,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3166,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_3166(t7,t1,t3);}

/* loop in chicken.compiler.batch-driver#any in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_3166(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3166,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3176,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:88: pred */
t4=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k3174 in loop in chicken.compiler.batch-driver#any in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_3176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3176,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* mini-srfi-1.scm:89: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_3166(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[4]));}}

/* loop in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_fcall f_3252(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3252,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_eqp(lf[134],t3);
if(C_truep(t4)){
/* mini-srfi-1.scm:107: loop */
t8=t1;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}
else{
t5=C_u_i_car(t2);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3279,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:109: loop */
t8=t6;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}}

/* k3277 in loop in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_3279(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3279,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* foldl559 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in ... */
static void C_fcall f_3677(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_3677,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3744,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_slot(t2,C_fix(0));
t7=C_i_check_list_2(t6,lf[378]);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3702,a[2]=t9,tmp=(C_word)a,a+=3,tmp));
t11=((C_word*)t9)[1];
f_3702(t11,t5,t6,t3);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* foldl575 in foldl559 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in ... */
static void C_fcall f_3702(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_3702,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=C_slot(t2,C_fix(0));
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3725,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,a[5]=t3,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3730,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* mini-srfi-1.scm:175: any */
f_3160(t6,t7,t3);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3723 in foldl575 in foldl559 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in ... */
static void C_ccall f_3725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3725,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)((C_word*)t0)[2])[1];
f_3702(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5]);}
else{
t2=C_a_i_cons(&a,2,((C_word*)t0)[6],((C_word*)t0)[5]);
t3=((C_word*)((C_word*)t0)[2])[1];
f_3702(t3,((C_word*)t0)[3],((C_word*)t0)[4],t2);}}

/* a3729 in foldl575 in foldl559 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in ... */
static void C_ccall f_3730(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3730,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_eqp(t2,((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3742 in foldl559 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in ... */
static void C_ccall f_3744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3744,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_3677(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* a4040 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in ... */
static void C_ccall f_4041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4041,c,av);}
/* batch-driver.scm:73: chicken.compiler.core#compute-database-statistics */
t2=*((C_word*)lf[222]+1);{
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

/* a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in ... */
static void C_ccall f_4047(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6=av[6];
C_word t7=av[7];
C_word t8=av[8];
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_4047,c,av);}
a=C_alloc(10);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4054,a[2]=t1,a[3]=t8,a[4]=t7,a[5]=t6,a[6]=t5,a[7]=t4,a[8]=t3,a[9]=t2,tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:74: chicken.compiler.support#debugging */
t10=*((C_word*)lf[103]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[221];
av2[3]=lf[230];
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}

/* k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in ... */
static void C_ccall f_4054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_4054,c,av);}
a=C_alloc(11);
if(C_truep(t1)){
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_4060,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t2,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* batch-driver.scm:75: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[229];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in ... */
static void C_ccall f_4060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_4060,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4063,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:75: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[10];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f_4063(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_4063,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4066,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:75: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[228];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in ... */
static void C_ccall f_4066(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_4066,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4069,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:75: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[9];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in ... */
static void C_ccall f_4069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4069,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4072,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:75: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in ... */
static void C_ccall f_4072(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_4072,c,av);}
a=C_alloc(9);
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4078,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t2,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:76: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[227];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in ... */
static void C_ccall f_4078(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_4078,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4081,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:76: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in ... */
static void C_ccall f_4081(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4081,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4084,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:76: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in ... */
static void C_ccall f_4084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_4084,c,av);}
a=C_alloc(8);
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4090,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t2,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:77: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[226];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in ... */
static void C_ccall f_4090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_4090,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4093,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:77: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in ... */
static void C_ccall f_4093(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4093,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4096,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:77: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in ... */
static void C_ccall f_4096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_4096,c,av);}
a=C_alloc(7);
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4102,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:78: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[225];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in ... */
static void C_ccall f_4102(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4102,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4105,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:78: ##sys#print */
t3=*((C_word*)lf[22]+1);{
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
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in ... */
static void C_ccall f_4105(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4105,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4108,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:78: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4106 in k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in ... */
static void C_ccall f_4108(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4108,c,av);}
a=C_alloc(6);
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4114,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:79: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[224];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4112 in k4106 in k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in k6047 in ... */
static void C_ccall f_4114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4114,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4117,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:79: ##sys#print */
t3=*((C_word*)lf[22]+1);{
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
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4115 in k4112 in k4106 in k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in k6050 in ... */
static void C_ccall f_4117(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4117,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4120,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:79: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
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

/* k4118 in k4115 in k4112 in k4106 in k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in k6053 in ... */
static void C_ccall f_4120(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4120,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4126,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:80: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[223];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k4124 in k4118 in k4115 in k4112 in k4106 in k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in k6057 in ... */
static void C_ccall f_4126(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_4126,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4129,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:80: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4127 in k4124 in k4118 in k4115 in k4112 in k4106 in k4103 in k4100 in k4094 in k4091 in k4088 in k4082 in k4079 in k4076 in k4070 in k4067 in k4064 in k4061 in k4058 in k4052 in a4046 in k6060 in ... */
static void C_ccall f_4129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4129,c,av);}
/* batch-driver.scm:80: ##sys#write-char-0 */
t2=*((C_word*)lf[34]+1);{
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

/* chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4134(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_4134,2,t0,t1);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4138,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t3=*((C_word*)lf[9]+1);
t4=C_i_check_list_2(*((C_word*)lf[9]+1),lf[10]);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4150,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4220,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_4220(t9,t5,*((C_word*)lf[9]+1));}
else{
t3=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4136 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4138(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4138,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4148 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4150(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4150,c,av);}
a=C_alloc(8);
t2=*((C_word*)lf[11]+1);
t3=C_i_check_list_2(*((C_word*)lf[11]+1),lf[10]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4161,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4197,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_4197(t8,t4,*((C_word*)lf[11]+1));}

/* k4159 in k4148 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4161(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4161,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[12]+1);
t3=C_i_check_list_2(*((C_word*)lf[12]+1),lf[10]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4174,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_4174(t7,((C_word*)t0)[2],*((C_word*)lf[12]+1));}

/* for-each-loop817 in k4159 in k4148 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4174(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_4174,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4184,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:102: chicken.compiler.support#mark-variable */
t4=*((C_word*)lf[13]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=lf[14];
av2[4]=lf[15];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4182 in for-each-loop817 in k4159 in k4148 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_ccall f_4184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4184,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4174(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop799 in k4148 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4197(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_4197,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4207,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:98: chicken.compiler.support#mark-variable */
t4=*((C_word*)lf[13]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=lf[14];
av2[4]=lf[16];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4205 in for-each-loop799 in k4148 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4207(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4207,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4197(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop781 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4220(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_4220,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4230,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:94: chicken.compiler.support#mark-variable */
t4=*((C_word*)lf[13]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
av2[3]=lf[14];
av2[4]=lf[17];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4228 in for-each-loop781 in chicken.compiler.batch-driver#initialize-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4230,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4220(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4243(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_4243,3,t0,t1,t2);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4247,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t4=t3;
f_4247(t4,C_SCHEME_UNDEFINED);}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4878,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:123: scheme#append */
t5=*((C_word*)lf[4]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=*((C_word*)lf[77]+1);
av2[3]=*((C_word*)lf[78]+1);
av2[4]=*((C_word*)lf[12]+1);
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4247(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_4247,2,t0,t1);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4252,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:126: chicken.internal#hash-table-for-each */
t3=*((C_word*)lf[76]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4252(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,2)))){
C_save_and_reclaim((void *)f_4252,c,av);}
a=C_alloc(22);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_FALSE;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_FALSE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_END_OF_LIST;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_SCHEME_END_OF_LIST;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_SCHEME_END_OF_LIST;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
if(C_truep(C_i_memq(t2,((C_word*)((C_word*)t0)[2])[1]))){
t16=C_SCHEME_UNDEFINED;
t17=t1;{
C_word *av2=av;
av2[0]=t17;
av2[1]=t16;
((C_proc)(void*)(*((C_word*)t17+1)))(2,av2);}}
else{
t16=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4262,a[2]=t1,a[3]=t9,a[4]=t5,a[5]=t7,a[6]=t11,a[7]=t15,a[8]=t13,a[9]=t3,tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:135: scheme#write */
t17=*((C_word*)lf[75]+1);{
C_word *av2=av;
av2[0]=t17;
av2[1]=t16;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t17+1)))(3,av2);}}}

/* k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_4262,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4265,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_4453,a[2]=t4,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp));
t6=((C_word*)t4)[1];
f_4453(t6,t2,((C_word*)t0)[9]);}

/* k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_ccall f_4265(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4265,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4268,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[8])[1]))){
t3=*((C_word*)lf[20]+1);
t4=*((C_word*)lf[20]+1);
t5=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4444,a[2]=t2,a[3]=((C_word*)t0)[8],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:163: ##sys#print */
t7=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[31];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4268(2,av2);}}}

/* k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in ... */
static void C_ccall f_4268(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4268,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4271,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[7])[1]))){
t3=*((C_word*)lf[20]+1);
t4=*((C_word*)lf[20]+1);
t5=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4428,a[2]=t2,a[3]=((C_word*)t0)[7],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:164: ##sys#print */
t7=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[30];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4271(2,av2);}}}

/* k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in ... */
static void C_ccall f_4271(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_4271,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4274,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[6])[1]))){
t3=*((C_word*)lf[20]+1);
t4=*((C_word*)lf[20]+1);
t5=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4412,a[2]=t2,a[3]=((C_word*)t0)[6],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:165: ##sys#print */
t7=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[29];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4274(2,av2);}}}

/* k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in ... */
static void C_ccall f_4274(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_4274,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4277,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(C_truep(((C_word*)((C_word*)t0)[4])[1])?C_i_not(C_eqp(((C_word*)((C_word*)t0)[4])[1],lf[26])):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=*((C_word*)lf[20]+1);
t5=*((C_word*)lf[20]+1);
t6=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4347,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:167: ##sys#print */
t8=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[27];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}
else{
t4=(C_truep(((C_word*)((C_word*)t0)[5])[1])?C_i_not(C_eqp(((C_word*)((C_word*)t0)[4])[1],lf[26])):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=*((C_word*)lf[20]+1);
t6=*((C_word*)lf[20]+1);
t7=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4374,a[2]=t2,a[3]=t5,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:169: ##sys#print */
t9=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[28];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=t2;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
f_4277(2,av2);}}}}

/* k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in ... */
static void C_ccall f_4277(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4277,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4280,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[3])[1]))){
t3=((C_word*)((C_word*)t0)[3])[1];
t4=C_SCHEME_UNDEFINED;
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4317,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_4317(t8,t2,t3);}
else{
/* batch-driver.scm:175: scheme#newline */
t3=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4278 in k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in ... */
static void C_ccall f_4280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4280,c,av);}
/* batch-driver.scm:175: scheme#newline */
t2=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4292 in for-each-loop1003 in k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in ... */
static void C_ccall f_4294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4294,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4305,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:173: chicken.compiler.support#node-class */
t3=*((C_word*)lf[24]+1);{
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

/* k4303 in k4292 in for-each-loop1003 in k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_ccall f_4305(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4305,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4309,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:173: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[23]+1);{
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

/* k4307 in k4303 in k4292 in for-each-loop1003 in k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_4309(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4309,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* batch-driver.scm:173: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* for-each-loop1003 in k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in ... */
static void C_fcall f_4317(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_4317,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4327,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[20]+1);
t6=*((C_word*)lf[20]+1);
t7=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4294,a[2]=t3,a[3]=t5,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:173: ##sys#print */
t9=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[25];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4325 in for-each-loop1003 in k4275 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in ... */
static void C_ccall f_4327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4327,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4317(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4345 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in ... */
static void C_ccall f_4347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4347,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4358,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:167: chicken.compiler.support#node-class */
t3=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4356 in k4345 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in ... */
static void C_ccall f_4358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4358,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4362,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:167: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[23]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4360 in k4356 in k4345 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in ... */
static void C_ccall f_4362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4362,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* batch-driver.scm:167: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4372 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in ... */
static void C_ccall f_4374(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4374,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4385,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:169: chicken.compiler.support#node-class */
t3=*((C_word*)lf[24]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4383 in k4372 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in ... */
static void C_ccall f_4385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4385,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4389,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:169: chicken.compiler.support#node-parameters */
t3=*((C_word*)lf[23]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4387 in k4383 in k4372 in k4272 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in ... */
static void C_ccall f_4389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_4389,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* batch-driver.scm:169: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4410 in k4269 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in ... */
static void C_ccall f_4412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4412,c,av);}
/* batch-driver.scm:165: ##sys#print */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_length(((C_word*)((C_word*)t0)[3])[1]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4426 in k4266 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in ... */
static void C_ccall f_4428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4428,c,av);}
/* batch-driver.scm:164: ##sys#print */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_length(((C_word*)((C_word*)t0)[3])[1]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4442 in k4263 in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in ... */
static void C_ccall f_4444(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4444,c,av);}
/* batch-driver.scm:163: ##sys#print */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_length(((C_word*)((C_word*)t0)[3])[1]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_fcall f_4453(C_word t0,C_word t1,C_word t2){
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
C_word t21;
C_word t22;
C_word t23;
C_word t24;
C_word t25;
C_word t26;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,2)))){
C_save_and_reclaim_args((void *)trf_4453,3,t0,t1,t2);}
a=C_alloc(18);
if(C_truep(C_i_pairp(t2))){
t3=C_i_caar(t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4466,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=C_eqp(t3,lf[32]);
t6=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4477,a[2]=t2,a[3]=t4,a[4]=t3,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[2],a[7]=t1,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[8],tmp=(C_word)a,a+=13,tmp);
if(C_truep(t5)){
t7=t6;
f_4477(t7,t5);}
else{
t7=C_eqp(t3,lf[55]);
if(C_truep(t7)){
t8=t6;
f_4477(t8,t7);}
else{
t8=C_eqp(t3,lf[56]);
if(C_truep(t8)){
t9=t6;
f_4477(t9,t8);}
else{
t9=C_eqp(t3,lf[57]);
if(C_truep(t9)){
t10=t6;
f_4477(t10,t9);}
else{
t10=C_eqp(t3,lf[58]);
if(C_truep(t10)){
t11=t6;
f_4477(t11,t10);}
else{
t11=C_eqp(t3,lf[59]);
if(C_truep(t11)){
t12=t6;
f_4477(t12,t11);}
else{
t12=C_eqp(t3,lf[60]);
if(C_truep(t12)){
t13=t6;
f_4477(t13,t12);}
else{
t13=C_eqp(t3,lf[61]);
if(C_truep(t13)){
t14=t6;
f_4477(t14,t13);}
else{
t14=C_eqp(t3,lf[62]);
if(C_truep(t14)){
t15=t6;
f_4477(t15,t14);}
else{
t15=C_eqp(t3,lf[63]);
if(C_truep(t15)){
t16=t6;
f_4477(t16,t15);}
else{
t16=C_eqp(t3,lf[64]);
if(C_truep(t16)){
t17=t6;
f_4477(t17,t16);}
else{
t17=C_eqp(t3,lf[65]);
if(C_truep(t17)){
t18=t6;
f_4477(t18,t17);}
else{
t18=C_eqp(t3,lf[66]);
if(C_truep(t18)){
t19=t6;
f_4477(t19,t18);}
else{
t19=C_eqp(t3,lf[67]);
if(C_truep(t19)){
t20=t6;
f_4477(t20,t19);}
else{
t20=C_eqp(t3,lf[68]);
if(C_truep(t20)){
t21=t6;
f_4477(t21,t20);}
else{
t21=C_eqp(t3,lf[69]);
if(C_truep(t21)){
t22=t6;
f_4477(t22,t21);}
else{
t22=C_eqp(t3,lf[70]);
if(C_truep(t22)){
t23=t6;
f_4477(t23,t22);}
else{
t23=C_eqp(t3,lf[71]);
if(C_truep(t23)){
t24=t6;
f_4477(t24,t23);}
else{
t24=C_eqp(t3,lf[72]);
if(C_truep(t24)){
t25=t6;
f_4477(t25,t24);}
else{
t25=C_eqp(t3,lf[73]);
t26=t6;
f_4477(t26,(C_truep(t25)?t25:C_eqp(t3,lf[74])));}}}}}}}}}}}}}}}}}}}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4464 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in ... */
static void C_ccall f_4466(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4466,c,av);}
/* batch-driver.scm:162: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_4453(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* k4475 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in ... */
static void C_fcall f_4477(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_4477,2,t0,t1);}
a=C_alloc(10);
if(C_truep(t1)){
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4483,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:143: ##sys#write-char-0 */
t6=*((C_word*)lf[34]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_make_character(9);
av2[3]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[26]);
if(C_truep(t2)){
t3=C_mutate(((C_word *)((C_word*)t0)[5])+1,lf[26]);
/* batch-driver.scm:162: loop */
t4=((C_word*)((C_word*)t0)[6])[1];
f_4453(t4,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[2]));}
else{
t3=C_eqp(((C_word*)t0)[4],lf[35]);
if(C_truep(t3)){
t4=C_eqp(((C_word*)((C_word*)t0)[5])[1],lf[26]);
if(C_truep(t4)){
/* batch-driver.scm:162: loop */
t5=((C_word*)((C_word*)t0)[6])[1];
f_4453(t5,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[2]));}
else{
t5=C_i_cdar(((C_word*)t0)[2]);
t6=C_mutate(((C_word *)((C_word*)t0)[5])+1,t5);
/* batch-driver.scm:162: loop */
t7=((C_word*)((C_word*)t0)[6])[1];
f_4453(t7,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[2]));}}
else{
t4=C_eqp(((C_word*)t0)[4],lf[36]);
if(C_truep(t4)){
t5=C_eqp(((C_word*)((C_word*)t0)[5])[1],lf[26]);
if(C_truep(t5)){
/* batch-driver.scm:162: loop */
t6=((C_word*)((C_word*)t0)[6])[1];
f_4453(t6,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[2]));}
else{
t6=C_i_cdar(((C_word*)t0)[2]);
t7=C_mutate(((C_word *)((C_word*)t0)[8])+1,t6);
/* batch-driver.scm:162: loop */
t8=((C_word*)((C_word*)t0)[6])[1];
f_4453(t8,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[2]));}}
else{
t5=C_eqp(((C_word*)t0)[4],lf[37]);
if(C_truep(t5)){
t6=C_i_cdar(((C_word*)t0)[2]);
t7=C_mutate(((C_word *)((C_word*)t0)[9])+1,t6);
/* batch-driver.scm:162: loop */
t8=((C_word*)((C_word*)t0)[6])[1];
f_4453(t8,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[2]));}
else{
t6=C_eqp(((C_word*)t0)[4],lf[38]);
t7=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4556,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[12],tmp=(C_word)a,a+=10,tmp);
if(C_truep(t6)){
t8=t7;
f_4556(t8,t6);}
else{
t8=C_eqp(((C_word*)t0)[4],lf[44]);
if(C_truep(t8)){
t9=t7;
f_4556(t9,t8);}
else{
t9=C_eqp(((C_word*)t0)[4],lf[45]);
if(C_truep(t9)){
t10=t7;
f_4556(t10,t9);}
else{
t10=C_eqp(((C_word*)t0)[4],lf[46]);
if(C_truep(t10)){
t11=t7;
f_4556(t11,t10);}
else{
t11=C_eqp(((C_word*)t0)[4],lf[47]);
if(C_truep(t11)){
t12=t7;
f_4556(t12,t11);}
else{
t12=C_eqp(((C_word*)t0)[4],lf[48]);
if(C_truep(t12)){
t13=t7;
f_4556(t13,t12);}
else{
t13=C_eqp(((C_word*)t0)[4],lf[49]);
if(C_truep(t13)){
t14=t7;
f_4556(t14,t13);}
else{
t14=C_eqp(((C_word*)t0)[4],lf[50]);
if(C_truep(t14)){
t15=t7;
f_4556(t15,t14);}
else{
t15=C_eqp(((C_word*)t0)[4],lf[51]);
if(C_truep(t15)){
t16=t7;
f_4556(t16,t15);}
else{
t16=C_eqp(((C_word*)t0)[4],lf[52]);
if(C_truep(t16)){
t17=t7;
f_4556(t17,t16);}
else{
t17=C_eqp(((C_word*)t0)[4],lf[53]);
t18=t7;
f_4556(t18,(C_truep(t17)?t17:C_eqp(((C_word*)t0)[4],lf[54])));}}}}}}}}}}}}}}}}

/* k4481 in k4475 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in ... */
static void C_ccall f_4483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4483,c,av);}
t2=C_i_caar(((C_word*)t0)[2]);
t3=C_i_assq(t2,lf[33]);
/* batch-driver.scm:143: ##sys#print */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=C_i_cdr(t3);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k4554 in k4475 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in ... */
static void C_fcall f_4556(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4556,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4562,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:154: ##sys#write-char-0 */
t6=*((C_word*)lf[34]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_make_character(9);
av2[3]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[39]);
if(C_truep(t2)){
t3=C_i_cdar(((C_word*)t0)[3]);
t4=C_mutate(((C_word *)((C_word*)t0)[5])+1,t3);
/* batch-driver.scm:162: loop */
t5=((C_word*)((C_word*)t0)[6])[1];
f_4453(t5,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[3]));}
else{
t3=C_eqp(((C_word*)t0)[4],lf[40]);
if(C_truep(t3)){
t4=C_i_cdar(((C_word*)t0)[3]);
t5=C_mutate(((C_word *)((C_word*)t0)[8])+1,t4);
/* batch-driver.scm:162: loop */
t6=((C_word*)((C_word*)t0)[6])[1];
f_4453(t6,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[3]));}
else{
t4=C_eqp(((C_word*)t0)[4],lf[41]);
if(C_truep(t4)){
t5=C_i_cdar(((C_word*)t0)[3]);
t6=C_mutate(((C_word *)((C_word*)t0)[9])+1,t5);
/* batch-driver.scm:162: loop */
t7=((C_word*)((C_word*)t0)[6])[1];
f_4453(t7,((C_word*)t0)[7],C_u_i_cdr(((C_word*)t0)[3]));}
else{
/* batch-driver.scm:161: chicken.compiler.support#bomb */
t5=*((C_word*)lf[42]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[43];
av2[3]=C_u_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}}}}

/* k4560 in k4554 in k4475 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in ... */
static void C_ccall f_4562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4562,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4565,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:154: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_caar(((C_word*)t0)[3]);
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4563 in k4560 in k4554 in k4475 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in ... */
static void C_ccall f_4565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4565,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4568,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:154: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(61);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4566 in k4563 in k4560 in k4554 in k4475 in loop in k4260 in a4251 in k4245 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in ... */
static void C_ccall f_4568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4568,c,av);}
/* batch-driver.scm:154: ##sys#print */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cdar(((C_word*)t0)[3]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4876 in chicken.compiler.batch-driver#display-analysis-database in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4878,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_4247(t3,t2);}

/* chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +9,c,3)))){
C_save_and_reclaim((void*)f_4880,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+9);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4883,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4914,a[2]=t4,a[3]=t5,a[4]=t1,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:188: chicken.compiler.core#initialize-compiler */
t7=*((C_word*)lf[491]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* option-arg in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4883(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_4883,2,t1,t2);}
t3=C_i_cdr(t2);
if(C_truep(C_i_nullp(t3))){
/* batch-driver.scm:183: chicken.compiler.support#quit-compiling */
t4=*((C_word*)lf[80]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[81];
av2[3]=C_u_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=C_i_cadr(t2);
if(C_truep(C_i_symbolp(t4))){
/* batch-driver.scm:186: chicken.compiler.support#quit-compiling */
t5=*((C_word*)lf[80]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[82];
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_ccall f_4914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4914,c,av);}
a=C_alloc(7);
t2=C_mutate((C_word*)lf[83]+1 /* (set! chicken.compiler.core#explicit-use-flag ...) */,C_u_i_memq(lf[84],((C_word*)t0)[2]));
t3=C_mutate((C_word*)lf[85]+1 /* (set! chicken.compiler.core#emit-debug-info ...) */,C_u_i_memq(lf[86],((C_word*)t0)[2]));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4923,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_u_i_memq(lf[490],((C_word*)t0)[2]))){
t5=C_mutate((C_word*)lf[483]+1 /* (set! chicken.compiler.core#compile-module-registration ...) */,lf[484]);
t6=t4;
f_4923(t6,t5);}
else{
t5=t4;
f_4923(t5,C_SCHEME_UNDEFINED);}}

/* k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4923(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_4923,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4926,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_u_i_memq(lf[488],((C_word*)t0)[2]))){
t3=C_mutate((C_word*)lf[483]+1 /* (set! chicken.compiler.core#compile-module-registration ...) */,lf[489]);
t4=t2;
f_4926(t4,t3);}
else{
t3=t2;
f_4926(t3,C_SCHEME_UNDEFINED);}}

/* k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 */
static void C_fcall f_4926(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_4926,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_u_i_memq(lf[486],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[482] /* chicken.compiler.core#static-extensions */,0,C_SCHEME_TRUE);
/* batch-driver.scm:197: chicken.platform#register-feature! */
t4=*((C_word*)lf[132]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[487];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_4929(2,av2);}}}

/* k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2705 in ... */
static void C_ccall f_4929(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_4929,c,av);}
a=C_alloc(21);
t2=C_u_i_memq(lf[87],((C_word*)t0)[2]);
t3=C_u_i_memq(lf[88],((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8212,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t2,a[8]=t3,tmp=(C_word)a,a+=9,tmp);
t5=(C_truep(*((C_word*)lf[85]+1))?lf[479]:C_SCHEME_END_OF_LIST);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8220,a[2]=t4,a[3]=t5,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
if(C_truep(*((C_word*)lf[83]+1))){
t7=t6;
f_8220(t7,C_SCHEME_END_OF_LIST);}
else{
t7=C_a_i_cons(&a,2,lf[382],*((C_word*)lf[485]+1));
t8=t6;
f_8220(t8,C_a_i_list(&a,1,t7));}}

/* k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in ... */
static void C_fcall f_4939(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,0,4)))){
C_save_and_reclaim_args((void *)trf_4939,2,t0,t1);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=lf[90];
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_u_i_memq(lf[91],((C_word*)t0)[2]);
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_4944,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=t5,a[11]=((C_word*)t0)[9],tmp=(C_word)a,a+=12,tmp);
if(C_truep(t6)){
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8158,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:222: g1072 */
t9=t8;
f_8158(t9,t7,t6);}
else{
if(C_truep(C_u_i_memq(lf[471],((C_word*)t0)[2]))){
t8=t7;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
f_4944(2,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8186,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[5])){
/* batch-driver.scm:229: chicken.pathname#pathname-file */
t9=*((C_word*)lf[473]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
/* batch-driver.scm:229: chicken.pathname#make-pathname */
t9=*((C_word*)lf[264]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t7;
av2[2]=C_SCHEME_FALSE;
av2[3]=lf[474];
av2[4]=lf[472];
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}}}}

/* k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in ... */
static void C_ccall f_4944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_4944,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_4947,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* batch-driver.scm:230: chicken.compiler.optimizer#default-optimization-passes */
t3=*((C_word*)lf[470]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in ... */
static void C_ccall f_4947(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,2)))){
C_save_and_reclaim((void *)f_4947,c,av);}
a=C_alloc(25);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_END_OF_LIST;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_FALSE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_u_i_memq(lf[92],((C_word*)t0)[2]);
t11=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_4952,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t5,a[5]=t3,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],a[12]=((C_word*)t0)[10],a[13]=t9,a[14]=((C_word*)t0)[11],a[15]=t7,a[16]=((C_word*)t0)[12],tmp=(C_word)a,a+=17,tmp);
if(C_truep(t10)){
t12=t11;
f_4952(t12,t10);}
else{
t12=C_u_i_memq(lf[350],((C_word*)t0)[2]);
t13=t11;
f_4952(t13,(C_truep(t12)?t12:C_u_i_memq(lf[93],((C_word*)t0)[2])));}}

/* k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in ... */
static void C_fcall f_4952(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(37,0,2)))){
C_save_and_reclaim_args((void *)trf_4952,2,t0,t1);}
a=C_alloc(37);
t2=C_u_i_memq(lf[93],((C_word*)t0)[2]);
t3=(C_truep(t2)?C_i_cadr(t2):C_SCHEME_FALSE);
t4=C_u_i_memq(lf[94],((C_word*)t0)[2]);
t5=C_u_i_memq(lf[95],((C_word*)t0)[2]);
t6=C_u_i_memq(lf[96],((C_word*)t0)[2]);
t7=C_u_i_memq(lf[97],((C_word*)t0)[2]);
t8=C_SCHEME_TRUE;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_u_i_memq(lf[98],((C_word*)t0)[2]);
t11=C_SCHEME_FALSE;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_SCHEME_FALSE;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_SCHEME_FALSE;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_u_i_memq(lf[99],((C_word*)t0)[2]);
t18=(C_truep(t17)?t17:C_u_i_memq(lf[100],((C_word*)t0)[2]));
t19=C_u_i_memq(lf[101],((C_word*)t0)[2]);
t20=(*a=C_CLOSURE_TYPE|28,a[1]=(C_word)f_4977,a[2]=t12,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t16,a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=t14,a[12]=((C_word*)t0)[9],a[13]=t6,a[14]=((C_word*)t0)[10],a[15]=((C_word*)t0)[11],a[16]=((C_word*)t0)[12],a[17]=t7,a[18]=((C_word*)t0)[13],a[19]=t10,a[20]=t9,a[21]=((C_word*)t0)[14],a[22]=t3,a[23]=((C_word*)t0)[15],a[24]=t1,a[25]=t18,a[26]=t4,a[27]=t5,a[28]=((C_word*)t0)[16],tmp=(C_word)a,a+=29,tmp);
if(C_truep(t19)){
/* batch-driver.scm:252: option-arg */
f_4883(t20,t19);}
else{
t21=t20;{
C_word av2[2];
av2[0]=t21;
av2[1]=C_SCHEME_FALSE;
f_4977(2,av2);}}}

/* k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in ... */
static void C_ccall f_4977(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(89,c,6)))){
C_save_and_reclaim((void *)f_4977,c,av);}
a=C_alloc(89);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
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
t20=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4995,tmp=(C_word)a,a+=2,tmp));
t21=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5022,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t22=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5044,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t23=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5071,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t24=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5242,tmp=(C_word)a,a+=2,tmp));
t25=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5327,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp));
t26=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5362,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp));
t27=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5372,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp));
t28=C_set_block_item(t19,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5412,a[2]=((C_word*)t0)[7],tmp=(C_word)a,a+=3,tmp));
t29=(*a=C_CLOSURE_TYPE|35,a[1]=(C_word)f_5501,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[12],a[10]=((C_word*)t0)[13],a[11]=t17,a[12]=t15,a[13]=t19,a[14]=t5,a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],a[17]=((C_word*)t0)[16],a[18]=((C_word*)t0)[17],a[19]=t7,a[20]=((C_word*)t0)[18],a[21]=((C_word*)t0)[19],a[22]=((C_word*)t0)[20],a[23]=t13,a[24]=t9,a[25]=((C_word*)t0)[21],a[26]=((C_word*)t0)[22],a[27]=t1,a[28]=((C_word*)t0)[23],a[29]=((C_word*)t0)[24],a[30]=((C_word*)t0)[25],a[31]=t11,a[32]=((C_word*)t0)[3],a[33]=((C_word*)t0)[26],a[34]=((C_word*)t0)[27],a[35]=((C_word*)t0)[5],tmp=(C_word)a,a+=36,tmp);
if(C_truep(((C_word*)t0)[28])){
t30=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8138,a[2]=t29,tmp=(C_word)a,a+=3,tmp);
t31=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8142,a[2]=t30,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:347: option-arg */
f_4883(t31,((C_word*)t0)[28]);}
else{
t30=t29;
f_5501(t30,C_SCHEME_UNDEFINED);}}

/* print-header in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_4995(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_4995,3,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4999,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:260: chicken.compiler.support#debugging */
t5=*((C_word*)lf[103]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[104];
av2[3]=lf[105];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k4997 in print-header in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_4999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4999,c,av);}
a=C_alloc(5);
if(C_truep(C_i_memq(((C_word*)t0)[2],*((C_word*)lf[102]+1)))){
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5011,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:263: ##sys#write-char-0 */
t6=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_make_character(91);
av2[3]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k5009 in k4997 in print-header in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_ccall f_5011(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_5011,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5014,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:263: ##sys#print */
t3=*((C_word*)lf[22]+1);{
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

/* k5012 in k5009 in k4997 in print-header in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5014,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5017,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:263: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(93);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5015 in k5012 in k5009 in k4997 in print-header in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5017(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5017,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5020,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:263: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5018 in k5015 in k5012 in k5009 in k4997 in print-header in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in ... */
static void C_ccall f_5020(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5020,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* print-node in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5022(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_5022,5,t0,t1,t2,t3,t4);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5029,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:267: print-header */
f_4995(t5,t2,t3);}

/* k5027 in print-node in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5029,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
/* batch-driver.scm:269: chicken.compiler.support#dump-nodes */
t2=*((C_word*)lf[106]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5042,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:270: chicken.compiler.support#build-expression-tree */
t3=*((C_word*)lf[108]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5040 in k5027 in print-node in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_ccall f_5042(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5042,c,av);}
/* batch-driver.scm:270: chicken.pretty-print#pretty-print */
t2=*((C_word*)lf[107]+1);{
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

/* print-db in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5044(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_5044,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(5);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5051,a[2]=t1,a[3]=t4,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:273: print-header */
f_4995(t6,t2,t3);}

/* k5049 in print-db in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5051(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5051,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=*((C_word*)lf[20]+1);
t3=*((C_word*)lf[20]+1);
t4=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5057,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:274: ##sys#print */
t6=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[109];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5055 in k5049 in print-db in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_ccall f_5057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5057,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5060,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:274: ##sys#print */
t3=*((C_word*)lf[22]+1);{
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
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5058 in k5055 in k5049 in print-db in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5060,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5063,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:274: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(41);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5061 in k5058 in k5055 in k5049 in print-db in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5063(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5063,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5066,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:274: ##sys#write-char-0 */
t3=*((C_word*)lf[34]+1);{
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

/* k5064 in k5061 in k5058 in k5055 in k5049 in print-db in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in ... */
static void C_ccall f_5066(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5066,c,av);}
/* batch-driver.scm:275: display-analysis-database */
t2=lf[18];
f_4243(t2,((C_word*)t0)[2],((C_word*)t0)[3]);}

/* print-expr in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5071(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_5071,5,t0,t1,t2,t3,t4);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5078,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:278: print-header */
f_4995(t5,t2,t3);}

/* k5076 in print-expr in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5078(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5078,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_i_check_list_2(((C_word*)t0)[2],lf[10]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5094,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_5094(t6,((C_word*)t0)[3],((C_word*)t0)[2]);}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5081 in for-each-loop1185 in k5076 in print-expr in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5083(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5083,c,av);}
/* batch-driver.scm:282: scheme#newline */
t2=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop1185 in k5076 in print-expr in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_fcall f_5094(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_5094,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5104,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5083,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:281: chicken.pretty-print#pretty-print */
t6=*((C_word*)lf[107]+1);{
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

/* k5102 in for-each-loop1185 in k5076 in print-expr in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5104,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_5094(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* loop in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in ... */
static void C_fcall f_5127(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(58,0,4)))){
C_save_and_reclaim_args((void *)trf_5127,4,t0,t1,t2,t3);}
a=C_alloc(58);
if(C_truep(C_i_nequalp(t2,t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=lf[376];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_string_ref(((C_word*)t0)[2],t2);
if(C_truep(C_u_i_char_whitespacep(t4))){
t5=C_a_i_fixnum_plus(&a,2,t2,C_fix(1));
/* batch-driver.scm:290: loop */
t9=t1;
t10=t5;
t11=t3;
t1=t9;
t2=t10;
t3=t11;
goto loop;}
else{
t5=C_s_a_i_minus(&a,2,t3,C_fix(1));
t6=C_i_string_ref(((C_word*)t0)[2],t5);
if(C_truep(C_u_i_char_whitespacep(t6))){
t7=C_s_a_i_minus(&a,2,t3,C_fix(1));
/* batch-driver.scm:292: loop */
t9=t1;
t10=t2;
t11=t7;
t1=t9;
t2=t10;
t3=t11;
goto loop;}
else{
/* batch-driver.scm:293: scheme#substring */
t7=*((C_word*)lf[112]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}}}}

/* k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in ... */
static void C_ccall f_5175(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5175,c,av);}
a=C_alloc(6);
t2=C_i_string_length(t1);
t3=(C_truep(C_i_fixnum_positivep(t2))?C_u_i_char_equalp(C_make_character(40),C_i_string_ref(t1,C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5184,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5189,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:299: scheme#call-with-current-continuation */
t6=*((C_word*)lf[375]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
/* batch-driver.scm:302: scheme#string->symbol */
t4=*((C_word*)lf[321]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k5182 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in ... */
static void C_ccall f_5184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5184,c,av);}
/* batch-driver.scm:299: g1217 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in ... */
static void C_ccall f_5189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_5189,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5195,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5207,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:299: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[374]+1);{
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

/* a5194 in a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in ... */
static void C_ccall f_5195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5195,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5201,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:299: k1214 */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a5200 in a5194 in a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in ... */
static void C_ccall f_5201(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5201,c,av);}
/* batch-driver.scm:300: ##sys#error */
t2=*((C_word*)lf[370]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[371];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a5206 in a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in ... */
static void C_ccall f_5207(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5207,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5213,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5219,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:299: ##sys#call-with-values */{
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

/* a5212 in a5206 in a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in ... */
static void C_ccall f_5213(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5213,c,av);}
/* batch-driver.scm:301: chicken.port#with-input-from-string */
t2=*((C_word*)lf[372]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=*((C_word*)lf[373]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a5218 in a5206 in a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in ... */
static void C_ccall f_5219(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +3,c,2)))){
C_save_and_reclaim((void*)f_5219,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+3);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5225,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:299: k1214 */
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
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a5224 in a5218 in a5206 in a5188 in k5173 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in ... */
static void C_ccall f_5225(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5225,c,av);}{
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

/* arg-val in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5242(C_word t1,C_word t2){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,4)))){
C_save_and_reclaim_args((void *)trf_5242,2,t1,t2);}
a=C_alloc(16);
t3=C_i_string_length(t2);
t4=C_a_i_fixnum_difference(&a,2,t3,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5251,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_lessp(t3,C_fix(2)))){
/* batch-driver.scm:308: scheme#string->number */
t6=*((C_word*)lf[111]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t6=C_i_string_ref(t2,t4);
t7=C_eqp(t6,C_make_character(109));
t8=(C_truep(t7)?t7:C_eqp(t6,C_make_character(77)));
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5282,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5286,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:310: scheme#substring */
t11=*((C_word*)lf[112]+1);{
C_word av2[5];
av2[0]=t11;
av2[1]=t10;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t11+1)))(5,av2);}}
else{
t9=C_eqp(t6,C_make_character(107));
t10=(C_truep(t9)?t9:C_eqp(t6,C_make_character(75)));
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5302,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5306,a[2]=t11,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:311: scheme#substring */
t13=*((C_word*)lf[112]+1);{
C_word av2[5];
av2[0]=t13;
av2[1]=t12;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t13+1)))(5,av2);}}
else{
/* batch-driver.scm:312: scheme#string->number */
t11=*((C_word*)lf[111]+1);{
C_word av2[3];
av2[0]=t11;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}}}}

/* k5249 in arg-val in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5251(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5251,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* batch-driver.scm:313: chicken.compiler.support#quit-compiling */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[110];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k5280 in arg-val in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_5282,c,av);}
a=C_alloc(33);
t2=C_s_a_i_times(&a,2,t1,C_fix(1048576));
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* batch-driver.scm:313: chicken.compiler.support#quit-compiling */
t3=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[110];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k5284 in arg-val in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5286(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5286,c,av);}
/* batch-driver.scm:310: scheme#string->number */
t2=*((C_word*)lf[111]+1);{
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

/* k5300 in arg-val in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_5302,c,av);}
a=C_alloc(33);
t2=C_s_a_i_times(&a,2,t1,C_fix(1024));
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* batch-driver.scm:313: chicken.compiler.support#quit-compiling */
t3=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[110];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k5304 in arg-val in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5306,c,av);}
/* batch-driver.scm:311: scheme#string->number */
t2=*((C_word*)lf[111]+1);{
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

/* collect-options in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5327(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_5327,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5333,a[2]=t2,a[3]=t4,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_5333(t6,t1,((C_word*)t0)[3]);}

/* loop in collect-options in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_fcall f_5333(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_5333,3,t0,t1,t2);}
a=C_alloc(4);
t3=C_i_memq(((C_word*)t0)[2],t2);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5341,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:317: g1249 */
t5=t4;
f_5341(t5,t1,t3);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* g1249 in loop in collect-options in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_fcall f_5341(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_5341,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5349,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:317: option-arg */
f_4883(t3,t2);}

/* k5347 in g1249 in loop in collect-options in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5349(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5349,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5353,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:317: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5333(t3,t2,C_i_cddr(((C_word*)t0)[4]));}

/* k5351 in k5347 in g1249 in loop in collect-options in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_5353,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* begin-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5362(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_5362,2,t0,t1);}
a=C_alloc(4);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5370,a[2]=((C_word*)t0)[3],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:254: chicken.time#current-process-milliseconds */
t3=*((C_word*)lf[113]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5368 in begin-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5370(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5370,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5372(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_5372,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t3=*((C_word*)lf[20]+1);
t4=*((C_word*)lf[20]+1);
t5=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5382,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:325: ##sys#print */
t7=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[117];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_ccall f_5382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5382,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5385,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:325: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5383 in k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_ccall f_5385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_5385,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5388,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:325: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[116];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5386 in k5383 in k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5388(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_5388,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5391,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5398,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5402,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5410,a[2]=((C_word*)t0)[4],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:254: chicken.time#current-process-milliseconds */
t6=*((C_word*)lf[113]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k5389 in k5386 in k5383 in k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5391,c,av);}
/* batch-driver.scm:325: ##sys#write-char-0 */
t2=*((C_word*)lf[34]+1);{
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

/* k5396 in k5386 in k5383 in k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5398,c,av);}
/* batch-driver.scm:325: ##sys#print */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k5400 in k5386 in k5383 in k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5402(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5402,c,av);}
/* batch-driver.scm:327: scheme#inexact->exact */
t2=*((C_word*)lf[114]+1);{
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

/* k5408 in k5386 in k5383 in k5380 in end-time in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,2)))){
C_save_and_reclaim((void *)f_5410,c,av);}
a=C_alloc(29);
t2=C_s_a_i_minus(&a,2,t1,((C_word*)((C_word*)t0)[2])[1]);
/* batch-driver.scm:327: scheme#round */
t3=*((C_word*)lf[115]+1);{
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

/* analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5412(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_5412,5,t0,t1,t2,t3,t4);}
a=C_alloc(11);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5414,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5437,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5442,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t4))){
/* batch-driver.scm:330: def-no1270 */
t8=t7;
f_5442(t8,t1);}
else{
t8=C_i_car(t4);
t9=C_u_i_cdr(t4);
if(C_truep(C_i_nullp(t9))){
/* batch-driver.scm:330: def-contf1271 */
t10=t6;
f_5437(t10,t1,t8);}
else{
t10=C_i_car(t9);
t11=C_u_i_cdr(t9);
/* batch-driver.scm:330: body1268 */
t12=t5;
f_5414(t12,t1,t8,t10);}}}

/* body1268 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_fcall f_5414(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_5414,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5418,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=t2,a[7]=t3,tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:331: chicken.compiler.core#analyze-expression */
t5=*((C_word*)lf[120]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k5416 in body1268 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_ccall f_5418(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,8)))){
C_save_and_reclaim((void *)f_5418,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5421,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5426,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5432,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:333: upap */
t5=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=((C_word*)t0)[5];
av2[5]=t3;
av2[6]=t4;
av2[7]=((C_word*)t0)[6];
av2[8]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t5+1)))(9,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5419 in k5416 in body1268 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5421,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a5425 in k5416 in body1268 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5426,c,av);}
t4=*((C_word*)lf[118]+1);
/* batch-driver.scm:334: g1290 */
t5=*((C_word*)lf[118]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* a5431 in k5416 in body1268 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5432(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5432,c,av);}
t5=*((C_word*)lf[119]+1);
/* batch-driver.scm:335: g1304 */
t6=*((C_word*)lf[119]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t6;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
av2[5]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(6,av2);}}

/* def-contf1271 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_fcall f_5437(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_5437,3,t0,t1,t2);}
/* batch-driver.scm:330: body1268 */
t3=((C_word*)t0)[2];
f_5414(t3,t1,t2,C_SCHEME_TRUE);}

/* def-no1270 in analyze in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_fcall f_5442(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_5442,2,t0,t1);}
/* batch-driver.scm:330: def-contf1271 */
t2=((C_word*)t0)[2];
f_5437(t2,t1,C_fix(0));}

/* k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_fcall f_5501(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,0,2)))){
C_save_and_reclaim_args((void *)trf_5501,2,t0,t1);}
a=C_alloc(36);
t2=(*a=C_CLOSURE_TYPE|35,a[1]=(C_word)f_5504,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],tmp=(C_word)a,a+=36,tmp);
t3=*((C_word*)lf[312]+1);
if(C_truep(*((C_word*)lf[312]+1))){
t4=*((C_word*)lf[312]+1);
if(C_truep(*((C_word*)lf[312]+1))){
t5=C_set_block_item(lf[309] /* chicken.compiler.core#standalone-executable */,0,C_SCHEME_FALSE);
t6=t2;
f_5504(t6,t5);}
else{
t5=t2;
f_5504(t5,C_SCHEME_UNDEFINED);}}
else{
if(C_truep(((C_word*)t0)[17])){
t4=C_set_block_item(lf[309] /* chicken.compiler.core#standalone-executable */,0,C_SCHEME_FALSE);
t5=t2;
f_5504(t5,t4);}
else{
t4=t2;
f_5504(t4,C_SCHEME_UNDEFINED);}}}

/* k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in ... */
static void C_fcall f_5504(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,0,2)))){
C_save_and_reclaim_args((void *)trf_5504,2,t0,t1);}
a=C_alloc(36);
t2=(*a=C_CLOSURE_TYPE|35,a[1]=(C_word)f_5507,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],tmp=(C_word)a,a+=36,tmp);
if(C_truep(C_u_i_memq(lf[269],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[468] /* ##sys#dload-disabled */,0,C_SCHEME_TRUE);
/* batch-driver.scm:352: chicken.platform#repository-path */
t4=*((C_word*)lf[469]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5507(2,av2);}}}

/* k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in ... */
static void C_ccall f_5507(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(42,c,3)))){
C_save_and_reclaim((void *)f_5507,c,av);}
a=C_alloc(42);
t2=C_mutate((C_word*)lf[121]+1 /* (set! chicken.compiler.core#enable-specialization ...) */,C_u_i_memq(lf[122],((C_word*)t0)[2]));
t3=(*a=C_CLOSURE_TYPE|35,a[1]=(C_word)f_5514,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],tmp=(C_word)a,a+=36,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8067,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8124,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:359: collect-options */
t6=((C_word*)((C_word*)t0)[23])[1];
f_5327(t6,t5,lf[467]);}

/* k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_5514(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(39,c,2)))){
C_save_and_reclaim((void *)f_5514,c,av);}
a=C_alloc(39);
t2=C_mutate((C_word*)lf[102]+1 /* (set! chicken.compiler.support#debugging-chicken ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|35,a[1]=(C_word)f_5517,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],tmp=(C_word)a,a+=36,tmp);
if(C_truep(C_i_memq(lf[346],*((C_word*)lf[102]+1)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8062,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:361: chicken.compiler.support#print-debug-options */
t5=*((C_word*)lf[465]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5517(2,av2);}}}

/* k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_5517(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,2)))){
C_save_and_reclaim((void *)f_5517,c,av);}
a=C_alloc(42);
t2=C_i_memq(lf[123],*((C_word*)lf[102]+1));
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|36,a[1]=(C_word)f_5543,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=t6,a[36]=t7,tmp=(C_word)a,a+=37,tmp);
/* batch-driver.scm:368: collect-options */
t9=((C_word*)((C_word*)t0)[23])[1];
f_5327(t9,t8,lf[464]);}

/* k5532 in map-loop1352 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in ... */
static void C_ccall f_5534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5534,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5538,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* ##sys#string-append */
t3=*((C_word*)lf[462]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[463];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k5536 in k5532 in map-loop1352 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in ... */
static void C_ccall f_5538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5538,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[3])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t6=((C_word*)((C_word*)t0)[4])[1];
f_8024(t6,((C_word*)t0)[5],C_slot(((C_word*)t0)[6],C_fix(1)));}

/* k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in ... */
static void C_ccall f_5543(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,3)))){
C_save_and_reclaim((void *)f_5543,c,av);}
a=C_alloc(42);
t2=C_i_check_list_2(t1,lf[5]);
t3=(*a=C_CLOSURE_TYPE|34,a[1]=(C_word)f_5549,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],tmp=(C_word)a,a+=35,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8024,a[2]=((C_word*)t0)[35],a[3]=t5,a[4]=((C_word*)t0)[36],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_8024(t7,t3,t1);}

/* k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in ... */
static void C_ccall f_5549(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(35,c,2)))){
C_save_and_reclaim((void *)f_5549,c,av);}
a=C_alloc(35);
t2=C_mutate((C_word*)lf[124]+1 /* (set! chicken.compiler.core#import-libraries ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|34,a[1]=(C_word)f_5552,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],tmp=(C_word)a,a+=35,tmp);
if(C_truep(C_u_i_memq(lf[460],((C_word*)t0)[2]))){
if(C_truep(C_i_not(((C_word*)t0)[17]))){
t4=C_set_block_item(lf[461] /* chicken.compiler.core#all-import-libraries */,0,C_SCHEME_TRUE);
t5=t3;
f_5552(t5,t4);}
else{
t4=t3;
f_5552(t4,C_SCHEME_UNDEFINED);}}
else{
t4=t3;
f_5552(t4,C_SCHEME_UNDEFINED);}}

/* k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in ... */
static void C_fcall f_5552(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(35,0,2)))){
C_save_and_reclaim_args((void *)trf_5552,2,t0,t1);}
a=C_alloc(35);
t2=(*a=C_CLOSURE_TYPE|34,a[1]=(C_word)f_5555,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],tmp=(C_word)a,a+=35,tmp);
if(C_truep(*((C_word*)lf[121]+1))){
t3=C_set_block_item(((C_word*)t0)[21],0,C_SCHEME_TRUE);
t4=t2;
f_5555(t4,t3);}
else{
t3=t2;
f_5555(t3,C_SCHEME_UNDEFINED);}}

/* k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in ... */
static void C_fcall f_5555(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(35,0,2)))){
C_save_and_reclaim_args((void *)trf_5555,2,t0,t1);}
a=C_alloc(35);
t2=(*a=C_CLOSURE_TYPE|34,a[1]=(C_word)f_5558,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],tmp=(C_word)a,a+=35,tmp);
if(C_truep(C_i_memq(lf[186],*((C_word*)lf[102]+1)))){
/* batch-driver.scm:374: ##sys#start-timer */
t3=*((C_word*)lf[459]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5558(2,av2);}}}

/* k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in ... */
static void C_ccall f_5558(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,2)))){
C_save_and_reclaim((void *)f_5558,c,av);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5561,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_i_memq(lf[458],*((C_word*)lf[102]+1)))){
t3=C_set_block_item(((C_word*)t0)[34],0,C_SCHEME_TRUE);
t4=t2;
f_5561(t4,t3);}
else{
t3=t2;
f_5561(t3,C_SCHEME_UNDEFINED);}}

/* k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in ... */
static void C_fcall f_5561(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5561,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5564,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[457],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[83] /* chicken.compiler.core#explicit-use-flag */,0,C_SCHEME_TRUE);
t4=C_set_block_item(((C_word*)t0)[8],0,C_SCHEME_END_OF_LIST);
t5=C_set_block_item(((C_word*)t0)[4],0,C_SCHEME_END_OF_LIST);
t6=C_set_block_item(((C_word*)t0)[24],0,C_SCHEME_END_OF_LIST);
t7=t2;
f_5564(t7,t6);}
else{
t3=t2;
f_5564(t3,C_SCHEME_UNDEFINED);}}

/* k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in ... */
static void C_fcall f_5564(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5564,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5567,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[455],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[456] /* chicken.compiler.core#emit-closure-info */,0,C_SCHEME_FALSE);
t4=t2;
f_5567(t4,t3);}
else{
t3=t2;
f_5567(t3,C_SCHEME_UNDEFINED);}}

/* k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in ... */
static void C_fcall f_5567(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5567,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5570,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[453],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[454] /* chicken.compiler.core#compiler-syntax-enabled */,0,C_SCHEME_FALSE);
t4=t2;
f_5570(t4,t3);}
else{
t3=t2;
f_5570(t3,C_SCHEME_UNDEFINED);}}

/* k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in ... */
static void C_fcall f_5570(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5570,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5573,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[452],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[430] /* chicken.compiler.core#local-definitions */,0,C_SCHEME_TRUE);
t4=t2;
f_5573(t4,t3);}
else{
t3=t2;
f_5573(t3,C_SCHEME_UNDEFINED);}}

/* k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in ... */
static void C_fcall f_5573(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5573,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5576,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[451],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[275] /* chicken.compiler.core#enable-inline-files */,0,C_SCHEME_TRUE);
t4=C_set_block_item(lf[167] /* chicken.compiler.core#inline-locally */,0,C_SCHEME_TRUE);
t5=t2;
f_5576(t5,t4);}
else{
t3=t2;
f_5576(t3,C_SCHEME_UNDEFINED);}}

/* k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in ... */
static void C_fcall f_5576(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5576,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5579,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[448],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[449] /* chicken.compiler.core#verbose-mode */,0,C_SCHEME_TRUE);
t4=C_set_block_item(lf[450] /* ##sys#notices-enabled */,0,C_SCHEME_TRUE);
t5=t2;
f_5579(t5,t4);}
else{
t3=t2;
f_5579(t3,C_SCHEME_UNDEFINED);}}

/* k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in ... */
static void C_fcall f_5579(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5579,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5582,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[447],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[257] /* chicken.compiler.core#strict-variable-types */,0,C_SCHEME_TRUE);
t4=C_set_block_item(lf[121] /* chicken.compiler.core#enable-specialization */,0,C_SCHEME_TRUE);
t5=t2;
f_5582(t5,t4);}
else{
t3=t2;
f_5582(t3,C_SCHEME_UNDEFINED);}}

/* k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in ... */
static void C_fcall f_5582(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(41,0,4)))){
C_save_and_reclaim_args((void *)trf_5582,2,t0,t1);}
a=C_alloc(41);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5585,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[445],((C_word*)t0)[2]))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7973,a[2]=((C_word*)t0)[21],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9619,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[446];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;
f_5585(t3,C_SCHEME_UNDEFINED);}}

/* k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in ... */
static void C_fcall f_5585(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5585,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5588,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[444],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[173] /* chicken.compiler.core#optimize-leaf-routines */,0,C_SCHEME_TRUE);
t4=t2;
f_5588(t4,t3);}
else{
t3=t2;
f_5588(t3,C_SCHEME_UNDEFINED);}}

/* k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in ... */
static void C_fcall f_5588(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5588,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5591,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[443],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[250] /* chicken.compiler.support#unsafe */,0,C_SCHEME_TRUE);
t4=t2;
f_5591(t4,t3);}
else{
t3=t2;
f_5591(t3,C_SCHEME_UNDEFINED);}}

/* k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in ... */
static void C_fcall f_5591(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5591,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[441],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[442] /* ##sys#setup-mode */,0,C_SCHEME_TRUE);
t4=t2;
f_5594(t4,t3);}
else{
t3=t2;
f_5594(t3,C_SCHEME_UNDEFINED);}}

/* k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in ... */
static void C_fcall f_5594(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5594,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5597,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[439],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[440] /* chicken.compiler.core#preserve-unchanged-import-libraries */,0,C_SCHEME_FALSE);
t4=t2;
f_5597(t4,t3);}
else{
t3=t2;
f_5597(t3,C_SCHEME_UNDEFINED);}}

/* k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in ... */
static void C_fcall f_5597(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5597,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5600,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[438],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[208] /* chicken.compiler.core#insert-timer-checks */,0,C_SCHEME_FALSE);
t4=t2;
f_5600(t4,t3);}
else{
t3=t2;
f_5600(t3,C_SCHEME_UNDEFINED);}}

/* k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in ... */
static void C_fcall f_5600(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5600,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5603,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[435],((C_word*)t0)[2]))){
t3=C_mutate((C_word*)lf[436]+1 /* (set! chicken.compiler.support#number-type ...) */,lf[437]);
t4=t2;
f_5603(t4,t3);}
else{
t3=t2;
f_5603(t3,C_SCHEME_UNDEFINED);}}

/* k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in ... */
static void C_fcall f_5603(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5603,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5606,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[434],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[166] /* chicken.compiler.core#block-compilation */,0,C_SCHEME_TRUE);
t4=t2;
f_5606(t4,t3);}
else{
t3=t2;
f_5606(t3,C_SCHEME_UNDEFINED);}}

/* k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in ... */
static void C_fcall f_5606(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5606,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5609,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[432],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[433] /* chicken.compiler.core#external-protos-first */,0,C_SCHEME_TRUE);
t4=t2;
f_5609(t4,t3);}
else{
t3=t2;
f_5609(t3,C_SCHEME_UNDEFINED);}}

/* k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in ... */
static void C_fcall f_5609(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,2)))){
C_save_and_reclaim_args((void *)trf_5609,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5612,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[431],((C_word*)t0)[2]))){
t3=C_set_block_item(lf[167] /* chicken.compiler.core#inline-locally */,0,C_SCHEME_TRUE);
t4=t2;
f_5612(t4,t3);}
else{
t3=t2;
f_5612(t3,C_SCHEME_UNDEFINED);}}

/* k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in ... */
static void C_fcall f_5612(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(37,0,2)))){
C_save_and_reclaim_args((void *)trf_5612,2,t0,t1);}
a=C_alloc(37);
t2=C_u_i_memq(lf[125],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5617,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7941,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:414: option-arg */
f_4883(t4,t2);}
else{
t4=t3;
f_5617(t4,C_SCHEME_FALSE);}}

/* k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in ... */
static void C_fcall f_5617(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(38,0,2)))){
C_save_and_reclaim_args((void *)trf_5617,2,t0,t1);}
a=C_alloc(38);
t2=C_u_i_memq(lf[126],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5622,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(t2)){
t4=C_set_block_item(lf[167] /* chicken.compiler.core#inline-locally */,0,C_SCHEME_TRUE);
t5=C_set_block_item(lf[430] /* chicken.compiler.core#local-definitions */,0,C_SCHEME_TRUE);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7937,a[2]=((C_word*)t0)[19],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:418: option-arg */
f_4883(t6,t2);}
else{
t4=t3;
f_5622(t4,C_SCHEME_FALSE);}}

/* k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in ... */
static void C_fcall f_5622(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(37,0,2)))){
C_save_and_reclaim_args((void *)trf_5622,2,t0,t1);}
a=C_alloc(37);
t2=C_u_i_memq(lf[127],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5627,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7931,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:420: option-arg */
f_4883(t4,t2);}
else{
t4=t3;
f_5627(t4,C_SCHEME_FALSE);}}

/* k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in ... */
static void C_fcall f_5627(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(37,0,2)))){
C_save_and_reclaim_args((void *)trf_5627,2,t0,t1);}
a=C_alloc(37);
t2=C_u_i_memq(lf[128],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5632,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7918,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:423: option-arg */
f_4883(t4,t2);}
else{
t4=t3;
f_5632(t4,C_SCHEME_FALSE);}}

/* k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in ... */
static void C_fcall f_5632(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(37,0,2)))){
C_save_and_reclaim_args((void *)trf_5632,2,t0,t1);}
a=C_alloc(37);
t2=C_u_i_memq(lf[129],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5637,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7905,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:429: option-arg */
f_4883(t4,t2);}
else{
t4=t3;
f_5637(t4,C_SCHEME_FALSE);}}

/* k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in ... */
static void C_fcall f_5637(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(40,0,4)))){
C_save_and_reclaim_args((void *)trf_5637,2,t0,t1);}
a=C_alloc(40);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5640,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],tmp=(C_word)a,a+=34,tmp);
if(C_truep(C_u_i_memq(lf[426],((C_word*)t0)[4]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7895,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9613,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[427];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5640(2,av2);}}}

/* k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in ... */
static void C_ccall f_5640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,c,2)))){
C_save_and_reclaim((void *)f_5640,c,av);}
a=C_alloc(36);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5643,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(((C_word*)t0)[33])){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7862,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:438: option-arg */
f_4883(t3,((C_word*)t0)[33]);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5643(2,av2);}}}

/* k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in ... */
static void C_ccall f_5643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(39,c,4)))){
C_save_and_reclaim((void *)f_5643,c,av);}
a=C_alloc(39);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5646,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[418],((C_word*)t0)[4]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7856,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9607,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[419];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5646(2,av2);}}}

/* k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in ... */
static void C_ccall f_5646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(39,c,4)))){
C_save_and_reclaim((void *)f_5646,c,av);}
a=C_alloc(39);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5649,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[416],((C_word*)t0)[4]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7848,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9601,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[417];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5649(2,av2);}}}

/* k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in ... */
static void C_ccall f_5649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(39,c,4)))){
C_save_and_reclaim((void *)f_5649,c,av);}
a=C_alloc(39);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5652,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[409],((C_word*)t0)[4]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7831,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9595,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[415];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5652(2,av2);}}}

/* k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_5652(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(43,c,2)))){
C_save_and_reclaim((void *)f_5652,c,av);}
a=C_alloc(43);
t2=C_set_block_item(lf[130] /* ##sys#read-error-with-line-number */,0,C_SCHEME_TRUE);
t3=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5657,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7786,a[2]=t3,a[3]=t6,a[4]=t7,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:458: collect-options */
t9=((C_word*)((C_word*)t0)[22])[1];
f_5327(t9,t8,lf[408]);}

/* k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_5657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,2)))){
C_save_and_reclaim((void *)f_5657,c,av);}
a=C_alloc(33);
t2=C_mutate((C_word*)lf[131]+1 /* (set! ##sys#include-pathnames ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5660,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(((C_word*)t0)[14])){
if(C_truep(((C_word*)t0)[6])){
if(C_truep(C_i_string_equal_p(((C_word*)t0)[14],((C_word*)t0)[6]))){
/* batch-driver.scm:461: chicken.compiler.support#quit-compiling */
t4=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[407];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5660(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5660(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5660(2,av2);}}}

/* k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_5660(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,2)))){
C_save_and_reclaim((void *)f_5660,c,av);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5663,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[405],((C_word*)t0)[4]))){
t3=C_set_block_item(lf[406] /* chicken.compiler.core#undefine-shadowed-macros */,0,C_SCHEME_FALSE);
t4=t2;
f_5663(t4,t3);}
else{
t3=t2;
f_5663(t3,C_SCHEME_UNDEFINED);}}

/* k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_fcall f_5663(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,2)))){
C_save_and_reclaim_args((void *)trf_5663,2,t0,t1);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5666,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[403],((C_word*)t0)[4]))){
t3=C_set_block_item(lf[404] /* chicken.compiler.core#no-argc-checks */,0,C_SCHEME_TRUE);
t4=t2;
f_5666(t4,t3);}
else{
t3=t2;
f_5666(t3,C_SCHEME_UNDEFINED);}}

/* k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in ... */
static void C_fcall f_5666(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,2)))){
C_save_and_reclaim_args((void *)trf_5666,2,t0,t1);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5669,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[401],((C_word*)t0)[4]))){
t3=C_set_block_item(lf[402] /* chicken.compiler.core#no-bound-checks */,0,C_SCHEME_TRUE);
t4=t2;
f_5669(t4,t3);}
else{
t3=t2;
f_5669(t3,C_SCHEME_UNDEFINED);}}

/* k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in ... */
static void C_fcall f_5669(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,2)))){
C_save_and_reclaim_args((void *)trf_5669,2,t0,t1);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5672,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[399],((C_word*)t0)[4]))){
t3=C_set_block_item(lf[400] /* chicken.compiler.core#no-procedure-checks */,0,C_SCHEME_TRUE);
t4=t2;
f_5672(t4,t3);}
else{
t3=t2;
f_5672(t3,C_SCHEME_UNDEFINED);}}

/* k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in ... */
static void C_fcall f_5672(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,2)))){
C_save_and_reclaim_args((void *)trf_5672,2,t0,t1);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5675,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[397],((C_word*)t0)[4]))){
t3=C_set_block_item(lf[398] /* chicken.compiler.core#no-global-procedure-checks */,0,C_SCHEME_TRUE);
t4=t2;
f_5675(t4,t3);}
else{
t3=t2;
f_5675(t3,C_SCHEME_UNDEFINED);}}

/* k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in ... */
static void C_fcall f_5675(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(41,0,3)))){
C_save_and_reclaim_args((void *)trf_5675,2,t0,t1);}
a=C_alloc(41);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5678,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_u_i_memq(lf[394],((C_word*)t0)[4]))){
t3=*((C_word*)lf[77]+1);
t4=C_i_check_list_2(*((C_word*)lf[77]+1),lf[10]);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7692,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7731,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_7731(t9,t5,*((C_word*)lf[77]+1));}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5678(2,av2);}}}

/* k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_5678(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,2)))){
C_save_and_reclaim((void *)f_5678,c,av);}
a=C_alloc(33);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5681,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
if(C_truep(C_i_memq(lf[104],*((C_word*)lf[102]+1)))){
/* batch-driver.scm:483: chicken.load#load-verbose */
t3=*((C_word*)lf[393]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5681(2,av2);}}}

/* k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_5681(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(40,c,3)))){
C_save_and_reclaim((void *)f_5681,c,av);}
a=C_alloc(40);
t2=*((C_word*)lf[132]+1);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5684,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=t2,tmp=(C_word)a,a+=34,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7662,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7670,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:488: collect-options */
t6=((C_word*)((C_word*)t0)[22])[1];
f_5327(t6,t5,lf[392]);}

/* k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in ... */
static void C_ccall f_5684(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(39,c,3)))){
C_save_and_reclaim((void *)f_5684,c,av);}
a=C_alloc(39);
t2=C_i_check_list_2(t1,lf[10]);
t3=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5690,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7639,a[2]=t5,a[3]=((C_word*)t0)[33],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_7639(t7,t3,t1);}

/* k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in ... */
static void C_ccall f_5690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(40,c,3)))){
C_save_and_reclaim((void *)f_5690,c,av);}
a=C_alloc(40);
t2=*((C_word*)lf[133]+1);
t3=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5693,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=t2,tmp=(C_word)a,a+=34,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7629,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7637,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:491: collect-options */
t6=((C_word*)((C_word*)t0)[22])[1];
f_5327(t6,t5,lf[390]);}

/* k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in ... */
static void C_ccall f_5693(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(39,c,3)))){
C_save_and_reclaim((void *)f_5693,c,av);}
a=C_alloc(39);
t2=C_i_check_list_2(t1,lf[10]);
t3=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5699,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7606,a[2]=t5,a[3]=((C_word*)t0)[33],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_7606(t7,t3,t1);}

/* k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in ... */
static void C_ccall f_5699(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,c,2)))){
C_save_and_reclaim((void *)f_5699,c,av);}
a=C_alloc(36);
t2=C_a_i_cons(&a,2,lf[134],*((C_word*)lf[135]+1));
t3=C_mutate((C_word*)lf[135]+1 /* (set! ##sys#features ...) */,t2);
t4=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5706,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
/* batch-driver.scm:495: collect-options */
t5=((C_word*)((C_word*)t0)[22])[1];
f_5327(t5,t4,lf[388]);}

/* k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in ... */
static void C_ccall f_5706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(37,c,4)))){
C_save_and_reclaim((void *)f_5706,c,av);}
a=C_alloc(37);
t2=(*a=C_CLOSURE_TYPE|33,a[1]=(C_word)f_5709,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],a[17]=((C_word*)t0)[16],a[18]=((C_word*)t0)[17],a[19]=((C_word*)t0)[18],a[20]=((C_word*)t0)[19],a[21]=((C_word*)t0)[20],a[22]=((C_word*)t0)[21],a[23]=((C_word*)t0)[22],a[24]=((C_word*)t0)[23],a[25]=((C_word*)t0)[24],a[26]=((C_word*)t0)[25],a[27]=((C_word*)t0)[26],a[28]=((C_word*)t0)[27],a[29]=((C_word*)t0)[28],a[30]=((C_word*)t0)[29],a[31]=((C_word*)t0)[30],a[32]=((C_word*)t0)[31],a[33]=((C_word*)t0)[32],tmp=(C_word)a,a+=34,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9579,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t3;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[387];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}

/* k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in ... */
static void C_ccall f_5709(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(38,c,3)))){
C_save_and_reclaim((void *)f_5709,c,av);}
a=C_alloc(38);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[10]);
t3=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5732,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],tmp=(C_word)a,a+=33,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7583,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_7583(t7,t3,((C_word*)t0)[2]);}

/* k5712 in for-each-loop1519 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_ccall f_5714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5714,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5717,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_not(t1))){
/* batch-driver.scm:500: chicken.compiler.support#quit-compiling */
t3=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[386];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* batch-driver.scm:501: scheme#load */
t3=*((C_word*)lf[385]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k5715 in k5712 in for-each-loop1519 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_5717(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5717,c,av);}
/* batch-driver.scm:501: scheme#load */
t2=*((C_word*)lf[385]+1);{
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

/* k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in ... */
static void C_ccall f_5732(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(38,c,3)))){
C_save_and_reclaim((void *)f_5732,c,av);}
a=C_alloc(38);
t2=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5736,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
t3=*((C_word*)lf[135]+1);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3252,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_3252(t7,t2,*((C_word*)lf[135]+1));}

/* k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_ccall f_5736(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,c,2)))){
C_save_and_reclaim((void *)f_5736,c,av);}
a=C_alloc(36);
t2=C_mutate((C_word*)lf[135]+1 /* (set! ##sys#features ...) */,t1);
t3=C_a_i_cons(&a,2,lf[136],*((C_word*)lf[135]+1));
t4=C_mutate((C_word*)lf[135]+1 /* (set! ##sys#features ...) */,t3);
t5=(*a=C_CLOSURE_TYPE|32,a[1]=(C_word)f_5744,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],tmp=(C_word)a,a+=33,tmp);
/* batch-driver.scm:505: chicken.compiler.user-pass#user-post-analysis-pass */
t6=*((C_word*)lf[384]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in ... */
static void C_ccall f_5744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(38,c,3)))){
C_save_and_reclaim((void *)f_5744,c,av);}
a=C_alloc(38);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|31,a[1]=(C_word)f_5747,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],tmp=(C_word)a,a+=32,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7533,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7581,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:510: collect-options */
t6=((C_word*)((C_word*)t0)[22])[1];
f_5327(t6,t5,lf[382]);}

/* k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in ... */
static void C_ccall f_5747(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(48,c,3)))){
C_save_and_reclaim((void *)f_5747,c,av);}
a=C_alloc(48);
t2=(*a=C_CLOSURE_TYPE|31,a[1]=(C_word)f_5750,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],tmp=(C_word)a,a+=32,tmp);
if(C_truep(C_i_nullp(t1))){
t3=t2;
f_5750(t3,C_SCHEME_UNDEFINED);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7519,a[2]=((C_word*)t0)[7],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_cons(&a,2,lf[382],t1);
t5=C_a_i_list(&a,2,lf[89],t4);
t6=C_a_i_list(&a,1,t5);
/* batch-driver.scm:513: scheme#append */
t7=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[7])[1];
av2[3]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in ... */
static void C_fcall f_5750(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(38,0,3)))){
C_save_and_reclaim_args((void *)trf_5750,2,t0,t1);}
a=C_alloc(38);
t2=(*a=C_CLOSURE_TYPE|31,a[1]=(C_word)f_5753,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],tmp=(C_word)a,a+=32,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7464,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7512,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:518: collect-options */
t5=((C_word*)((C_word*)t0)[21])[1];
f_5327(t5,t4,lf[381]);}

/* k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in ... */
static void C_ccall f_5753(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(40,c,4)))){
C_save_and_reclaim((void *)f_5753,c,av);}
a=C_alloc(40);
t2=(*a=C_CLOSURE_TYPE|31,a[1]=(C_word)f_5757,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],tmp=(C_word)a,a+=32,tmp);
t3=*((C_word*)lf[137]+1);
t4=C_a_i_list(&a,1,t1);
t5=*((C_word*)lf[137]+1);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3677,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_3677(t9,t2,t4,*((C_word*)lf[137]+1));}

/* k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in ... */
static void C_ccall f_5757(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(43,c,2)))){
C_save_and_reclaim((void *)f_5757,c,av);}
a=C_alloc(43);
t2=C_mutate((C_word*)lf[137]+1 /* (set! chicken.compiler.core#linked-libraries ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|31,a[1]=(C_word)f_5761,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],tmp=(C_word)a,a+=32,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7422,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t6,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:526: collect-options */
t9=((C_word*)((C_word*)t0)[21])[1];
f_5327(t9,t8,lf[377]);}

/* k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in ... */
static void C_ccall f_5761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,2)))){
C_save_and_reclaim((void *)f_5761,c,av);}
a=C_alloc(32);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|31,a[1]=(C_word)f_5764,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[2],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],tmp=(C_word)a,a+=32,tmp);
if(C_truep(C_u_i_memq(lf[367],((C_word*)t0)[3]))){
t4=C_set_block_item(lf[368] /* ##sys#enable-runtime-macros */,0,C_SCHEME_TRUE);
t5=t3;
f_5764(t5,t4);}
else{
t4=t3;
f_5764(t4,C_SCHEME_UNDEFINED);}}

/* k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in ... */
static void C_fcall f_5764(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(35,0,2)))){
C_save_and_reclaim_args((void *)trf_5764,2,t0,t1);}
a=C_alloc(35);
t2=(*a=C_CLOSURE_TYPE|30,a[1]=(C_word)f_5768,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],tmp=(C_word)a,a+=31,tmp);
if(C_truep(((C_word*)t0)[31])){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7403,a[2]=((C_word*)t0)[29],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:532: option-arg */
f_4883(t3,((C_word*)t0)[31]);}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_5768(2,av2);}}}

/* k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in ... */
static void C_ccall f_5768(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,2)))){
C_save_and_reclaim((void *)f_5768,c,av);}
a=C_alloc(32);
t2=C_mutate((C_word*)lf[138]+1 /* (set! chicken.compiler.core#target-heap-size ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5772,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],tmp=(C_word)a,a+=28,tmp);
if(C_truep(((C_word*)t0)[28])){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7396,a[2]=((C_word*)t0)[29],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:535: option-arg */
f_4883(t4,((C_word*)t0)[28]);}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_5772(2,av2);}}}

/* k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in ... */
static void C_ccall f_5772(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5772,c,av);}
a=C_alloc(28);
t2=C_mutate((C_word*)lf[139]+1 /* (set! chicken.compiler.core#target-stack-size ...) */,t1);
t3=C_i_not(C_u_i_memq(lf[140],((C_word*)t0)[2]));
t4=C_set_block_item(lf[141] /* chicken.compiler.core#emit-trace-info */,0,t3);
t5=C_mutate((C_word*)lf[142]+1 /* (set! chicken.compiler.core#disable-stack-overflow-checking ...) */,C_u_i_memq(lf[143],((C_word*)t0)[2]));
t6=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5783,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],tmp=(C_word)a,a+=28,tmp);
/* batch-driver.scm:538: chicken.platform#feature? */
t7=*((C_word*)lf[365]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[366];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in ... */
static void C_ccall f_5783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(28,c,2)))){
C_save_and_reclaim((void *)f_5783,c,av);}
a=C_alloc(28);
t2=C_set_block_item(lf[144] /* chicken.compiler.core#bootstrap-mode */,0,t1);
t3=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5786,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],tmp=(C_word)a,a+=28,tmp);
if(C_truep(C_i_memq(lf[363],*((C_word*)lf[102]+1)))){
/* batch-driver.scm:539: chicken.gc#set-gc-report! */
t4=*((C_word*)lf[364]+1);{
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
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5786(2,av2);}}}

/* k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in ... */
static void C_ccall f_5786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(28,c,2)))){
C_save_and_reclaim((void *)f_5786,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5789,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],tmp=(C_word)a,a+=28,tmp);
if(C_truep(C_u_i_memq(lf[362],((C_word*)t0)[2]))){
t3=C_set_block_item(((C_word*)t0)[19],0,C_SCHEME_FALSE);
t4=t2;
f_5789(t4,t3);}
else{
t3=C_mutate((C_word*)lf[9]+1 /* (set! chicken.compiler.core#standard-bindings ...) */,*((C_word*)lf[77]+1));
t4=C_mutate((C_word*)lf[11]+1 /* (set! chicken.compiler.core#extended-bindings ...) */,*((C_word*)lf[78]+1));
t5=t2;
f_5789(t5,t4);}}

/* k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in ... */
static void C_fcall f_5789(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,4)))){
C_save_and_reclaim_args((void *)trf_5789,2,t0,t1);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5792,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],tmp=(C_word)a,a+=28,tmp);
if(C_truep(*((C_word*)lf[141]+1))){
t3=C_a_i_list(&a,1,lf[359]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9551,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[360];
av2[4]=t3;
C_apply(5,av2);}}
else{
t3=C_a_i_list(&a,1,lf[361]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9557,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[360];
av2[4]=t3;
C_apply(5,av2);}}}

/* k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in ... */
static void C_ccall f_5792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,2)))){
C_save_and_reclaim((void *)f_5792,c,av);}
a=C_alloc(32);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5795,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
if(C_truep(((C_word*)t0)[27])){
t3=C_i_car(((C_word*)t0)[27]);
t4=C_eqp(lf[350],t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7341,a[2]=((C_word*)t0)[6],a[3]=t4,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t4)){
if(C_truep(C_i_not(((C_word*)t0)[23]))){
/* batch-driver.scm:552: chicken.compiler.support#quit-compiling */
t6=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[358];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_7341(2,av2);}}}
else{
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_7341(2,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5795(2,av2);}}}

/* k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in ... */
static void C_ccall f_5795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,2)))){
C_save_and_reclaim((void *)f_5795,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5798,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:566: chicken.compiler.support#load-identifier-database */
t3=*((C_word*)lf[348]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[349];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in ... */
static void C_ccall f_5798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,2)))){
C_save_and_reclaim((void *)f_5798,c,av);}
a=C_alloc(27);
if(C_truep(C_u_i_memq(lf[145],((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5806,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:569: chicken.compiler.support#print-version */
t3=*((C_word*)lf[146]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=C_u_i_memq(lf[147],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5817,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
if(C_truep(t2)){
t4=t3;
f_5817(t4,t2);}
else{
t4=C_u_i_memq(lf[345],((C_word*)t0)[2]);
if(C_truep(t4)){
t5=t3;
f_5817(t5,t4);}
else{
t5=C_u_i_memq(lf[346],((C_word*)t0)[2]);
t6=t3;
f_5817(t6,(C_truep(t5)?t5:C_u_i_memq(lf[347],((C_word*)t0)[2])));}}}}

/* k5804 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in ... */
static void C_ccall f_5806(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5806,c,av);}
/* batch-driver.scm:570: scheme#newline */
t2=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in ... */
static void C_fcall f_5817(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,0,4)))){
C_save_and_reclaim_args((void *)trf_5817,2,t0,t1);}
a=C_alloc(33);
if(C_truep(t1)){
/* batch-driver.scm:572: chicken.compiler.support#print-usage */
t2=*((C_word*)lf[148]+1);{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_u_i_memq(lf[149],((C_word*)t0)[3]))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5828,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5835,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:574: chicken.platform#chicken-version */
t4=*((C_word*)lf[151]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_not(((C_word*)t0)[4]))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5844,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:577: chicken.compiler.support#print-version */
t3=*((C_word*)lf[146]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5856,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[13],a[12]=((C_word*)t0)[14],a[13]=((C_word*)t0)[15],a[14]=((C_word*)t0)[16],a[15]=((C_word*)t0)[17],a[16]=((C_word*)t0)[18],a[17]=((C_word*)t0)[2],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[3],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
t3=C_a_i_list(&a,1,((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9533,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[344];
av2[4]=t3;
C_apply(5,av2);}}}}}

/* k5826 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in ... */
static void C_ccall f_5828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5828,c,av);}
/* batch-driver.scm:575: scheme#newline */
t2=*((C_word*)lf[19]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5833 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in ... */
static void C_ccall f_5835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5835,c,av);}
/* batch-driver.scm:574: scheme#display */
t2=*((C_word*)lf[150]+1);{
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

/* k5842 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in ... */
static void C_ccall f_5844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5844,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5847,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:578: scheme#display */
t3=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[154];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5845 in k5842 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in ... */
static void C_ccall f_5847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5847,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5850,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:579: scheme#display */
t3=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[153];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5848 in k5845 in k5842 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in ... */
static void C_ccall f_5850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5850,c,av);}
/* batch-driver.scm:580: scheme#display */
t2=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[152];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in ... */
static void C_ccall f_5856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_5856,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5859,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:585: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[339];
av2[3]=lf[343];
av2[4]=((C_word*)t0)[20];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in ... */
static void C_ccall f_5859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_5859,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5862,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:586: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[339];
av2[3]=lf[342];
av2[4]=*((C_word*)lf[102]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in ... */
static void C_ccall f_5862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_5862,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5865,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:587: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[339];
av2[3]=lf[341];
av2[4]=*((C_word*)lf[138]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in ... */
static void C_ccall f_5865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_5865,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5868,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:588: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[339];
av2[3]=lf[340];
av2[4]=*((C_word*)lf[139]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in ... */
static void C_ccall f_5868(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,2)))){
C_save_and_reclaim((void *)f_5868,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5872,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:254: chicken.time#current-process-milliseconds */
t3=*((C_word*)lf[113]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in ... */
static void C_ccall f_5872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_5872,c,av);}
a=C_alloc(27);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5876,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[2],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:592: scheme#make-vector */
t4=*((C_word*)lf[337]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=*((C_word*)lf[338]+1);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in ... */
static void C_ccall f_5876(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,2)))){
C_save_and_reclaim((void *)f_5876,c,av);}
a=C_alloc(27);
t2=C_mutate((C_word*)lf[155]+1 /* (set! ##sys#line-number-database ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5879,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:593: collect-options */
t4=((C_word*)((C_word*)t0)[19])[1];
f_5327(t4,t3,lf[336]);}

/* k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in ... */
static void C_ccall f_5879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(28,c,2)))){
C_save_and_reclaim((void *)f_5879,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5882,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=t1,tmp=(C_word)a,a+=28,tmp);
/* batch-driver.scm:594: collect-options */
t3=((C_word*)((C_word*)t0)[19])[1];
f_5327(t3,t2,lf[335]);}

/* k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in ... */
static void C_ccall f_5882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,2)))){
C_save_and_reclaim((void *)f_5882,c,av);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|28,a[1]=(C_word)f_5885,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=t1,tmp=(C_word)a,a+=29,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7315,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[19],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:596: collect-options */
t4=((C_word*)((C_word*)t0)[19])[1];
f_5327(t4,t3,lf[334]);}

/* k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in ... */
static void C_ccall f_5885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,2)))){
C_save_and_reclaim((void *)f_5885,c,av);}
a=C_alloc(30);
t2=(*a=C_CLOSURE_TYPE|29,a[1]=(C_word)f_5888,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=t1,a[29]=((C_word*)t0)[28],tmp=(C_word)a,a+=30,tmp);
/* batch-driver.scm:600: chicken.compiler.user-pass#user-read-pass */
t3=*((C_word*)lf[332]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in ... */
static void C_ccall f_5888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(38,c,4)))){
C_save_and_reclaim((void *)f_5888,c,av);}
a=C_alloc(38);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5891,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7147,a[2]=((C_word*)t0)[26],a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[27],a[6]=((C_word*)t0)[28],a[7]=((C_word*)t0)[29],tmp=(C_word)a,a+=8,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9519,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[326];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7156,a[2]=((C_word*)t0)[26],a[3]=((C_word*)t0)[27],a[4]=((C_word*)t0)[29],a[5]=t4,tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_7156(t6,t2,((C_word*)t0)[28]);}}

/* k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in ... */
static void C_ccall f_5891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,2)))){
C_save_and_reclaim((void *)f_5891,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5894,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:624: chicken.compiler.user-pass#user-preprocessor-pass */
t3=*((C_word*)lf[325]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in ... */
static void C_ccall f_5894(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(35,c,4)))){
C_save_and_reclaim((void *)f_5894,c,av);}
a=C_alloc(35);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5897,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7100,a[2]=((C_word*)t0)[26],a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9513,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[324];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;
f_5897(t3,C_SCHEME_UNDEFINED);}}

/* k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_fcall f_5897(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,0,4)))){
C_save_and_reclaim_args((void *)trf_5897,2,t0,t1);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5900,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:629: print-expr */
t3=((C_word*)((C_word*)t0)[21])[1];
f_5071(t3,t2,lf[322],lf[323],((C_word*)((C_word*)t0)[26])[1]);}

/* k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in ... */
static void C_ccall f_5900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,2)))){
C_save_and_reclaim((void *)f_5900,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5903,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:630: begin-time */
t3=((C_word*)((C_word*)t0)[6])[1];
f_5362(t3,t2);}

/* k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in ... */
static void C_ccall f_5903(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(39,c,3)))){
C_save_and_reclaim((void *)f_5903,c,av);}
a=C_alloc(39);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=*((C_word*)lf[156]+1);
t7=((C_word*)((C_word*)t0)[2])[1];
t8=C_i_check_list_2(t7,lf[5]);
t9=(*a=C_CLOSURE_TYPE|25,a[1]=(C_word)f_5912,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],tmp=(C_word)a,a+=26,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7065,a[2]=t4,a[3]=t11,a[4]=t6,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_7065(t13,t9,t7);}

/* k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in ... */
static void C_ccall f_5912(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(36,c,3)))){
C_save_and_reclaim((void *)f_5912,c,av);}
a=C_alloc(36);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5916,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|27,a[1]=(C_word)f_5939,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[2],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=t1,a[23]=((C_word*)t0)[22],a[24]=t4,a[25]=t6,a[26]=t5,a[27]=((C_word*)t0)[23],tmp=(C_word)a,a+=28,tmp);
/* batch-driver.scm:636: scheme#append */
t8=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)((C_word*)t0)[24])[1];
av2[3]=((C_word*)((C_word*)t0)[25])[1];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* g1799 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in ... */
static void C_fcall f_5916(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_5916,3,t0,t1,t2);}
a=C_alloc(15);
t3=((C_word*)t0)[2];
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5922,a[2]=t6,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5927,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5933,a[2]=t4,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:634: ##sys#dynamic-wind */
t10=*((C_word*)lf[158]+1);{
C_word av2[5];
av2[0]=t10;
av2[1]=t1;
av2[2]=t7;
av2[3]=t8;
av2[4]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}

/* a5921 in g1799 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in ... */
static void C_ccall f_5922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5922,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[157]+1));
t3=C_mutate((C_word*)lf[157]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a5926 in g1799 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in ... */
static void C_ccall f_5927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5927,c,av);}
/* batch-driver.scm:635: chicken.compiler.core#canonicalize-expression */
t2=*((C_word*)lf[156]+1);{
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

/* a5932 in g1799 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in ... */
static void C_ccall f_5933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5933,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[157]+1));
t3=C_mutate((C_word*)lf[157]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in ... */
static void C_ccall f_5939(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(31,c,2)))){
C_save_and_reclaim((void *)f_5939,c,av);}
a=C_alloc(31);
t2=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5942,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],tmp=(C_word)a,a+=27,tmp);
if(C_truep(C_i_not(((C_word*)t0)[27]))){
t3=t2;
f_5942(t3,t1);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7059,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:640: scheme#string->symbol */
t4=*((C_word*)lf[321]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[27];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in ... */
static void C_fcall f_5942(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,0,3)))){
C_save_and_reclaim_args((void *)trf_5942,2,t0,t1);}
a=C_alloc(32);
t2=C_i_check_list_2(t1,lf[5]);
t3=(*a=C_CLOSURE_TYPE|23,a[1]=(C_word)f_5948,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],tmp=(C_word)a,a+=24,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7009,a[2]=((C_word*)t0)[24],a[3]=t5,a[4]=((C_word*)t0)[25],a[5]=((C_word*)t0)[26],tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_7009(t7,t3,t1);}

/* k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in ... */
static void C_ccall f_5948(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(32,c,2)))){
C_save_and_reclaim((void *)f_5948,c,av);}
a=C_alloc(32);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|26,a[1]=(C_word)f_5963,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=t1,a[24]=((C_word*)t0)[23],a[25]=t4,a[26]=t5,tmp=(C_word)a,a+=27,tmp);
/* batch-driver.scm:644: ##sys#fast-reverse */
t7=*((C_word*)lf[318]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=*((C_word*)lf[319]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in ... */
static void C_ccall f_5963(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(32,c,3)))){
C_save_and_reclaim((void *)f_5963,c,av);}
a=C_alloc(32);
t2=C_i_check_list_2(t1,lf[5]);
t3=(*a=C_CLOSURE_TYPE|24,a[1]=(C_word)f_5969,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],tmp=(C_word)a,a+=25,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6975,a[2]=((C_word*)t0)[25],a[3]=t5,a[4]=((C_word*)t0)[26],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_6975(t7,t3,t1);}

/* k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in ... */
static void C_ccall f_5969(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5969,c,av);}
a=C_alloc(41);
t2=(*a=C_CLOSURE_TYPE|20,a[1]=(C_word)f_5972,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],tmp=(C_word)a,a+=21,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=*((C_word*)lf[308]+1);
t8=C_i_check_list_2(*((C_word*)lf[308]+1),lf[5]);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6907,a[2]=((C_word*)t0)[21],a[3]=t2,a[4]=((C_word*)t0)[22],a[5]=t1,a[6]=((C_word*)t0)[23],a[7]=((C_word*)t0)[24],tmp=(C_word)a,a+=8,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6941,a[2]=t5,a[3]=t11,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_6941(t13,t9,*((C_word*)lf[308]+1));}

/* k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in ... */
static void C_ccall f_5972(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,3)))){
C_save_and_reclaim((void *)f_5972,c,av);}
a=C_alloc(42);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_5975,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=t3,a[21]=((C_word*)t0)[20],tmp=(C_word)a,a+=22,tmp);
if(C_truep(C_i_nullp(*((C_word*)lf[124]+1)))){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_5975(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6829,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=*((C_word*)lf[124]+1);
t11=C_i_check_list_2(*((C_word*)lf[124]+1),lf[5]);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6848,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6850,a[2]=t8,a[3]=t14,a[4]=t9,tmp=(C_word)a,a+=5,tmp));
t16=((C_word*)t14)[1];
f_6850(t16,t12,*((C_word*)lf[124]+1));}}

/* k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in ... */
static void C_ccall f_5975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_5975,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_5978,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],tmp=(C_word)a,a+=22,tmp);
if(C_truep(C_i_pairp(*((C_word*)lf[297]+1)))){
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6760,tmp=(C_word)a,a+=2,tmp);
/* batch-driver.scm:668: chicken.compiler.support#with-debugging-output */
t4=*((C_word*)lf[302]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[303];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5978(2,av2);}}}

/* k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in ... */
static void C_ccall f_5978(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_5978,c,av);}
a=C_alloc(25);
t2=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_5981,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],tmp=(C_word)a,a+=22,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6749,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:675: chicken.compiler.support#debugging */
t4=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[295];
av2[3]=lf[296];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in ... */
static void C_ccall f_5981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_5981,c,av);}
a=C_alloc(25);
t2=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_5984,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],tmp=(C_word)a,a+=22,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6743,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:677: chicken.compiler.support#debugging */
t4=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[292];
av2[3]=lf[293];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in ... */
static void C_ccall f_5984(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,2)))){
C_save_and_reclaim((void *)f_5984,c,av);}
a=C_alloc(22);
t2=C_mutate((C_word*)lf[155]+1 /* (set! ##sys#line-number-database ...) */,*((C_word*)lf[159]+1));
t3=C_set_block_item(lf[159] /* chicken.compiler.core#line-number-database-2 */,0,C_SCHEME_FALSE);
t4=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_5989,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],tmp=(C_word)a,a+=22,tmp);
/* batch-driver.scm:683: end-time */
t5=((C_word*)((C_word*)t0)[3])[1];
f_5372(t5,t4,lf[290]);}

/* k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in ... */
static void C_ccall f_5989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,4)))){
C_save_and_reclaim((void *)f_5989,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|20,a[1]=(C_word)f_5992,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],tmp=(C_word)a,a+=21,tmp);
/* batch-driver.scm:684: print-expr */
t3=((C_word*)((C_word*)t0)[21])[1];
f_5071(t3,t2,lf[288],lf[289],((C_word*)((C_word*)t0)[20])[1]);}

/* k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in ... */
static void C_ccall f_5992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_5992,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|20,a[1]=(C_word)f_5995,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],tmp=(C_word)a,a+=21,tmp);
if(C_truep(C_u_i_memq(lf[287],((C_word*)t0)[19]))){
/* batch-driver.scm:686: chicken.base#exit */
t3=*((C_word*)lf[199]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_5995(2,av2);}}}

/* k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in ... */
static void C_ccall f_5995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_5995,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|20,a[1]=(C_word)f_5998,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],tmp=(C_word)a,a+=21,tmp);
/* batch-driver.scm:689: chicken.compiler.user-pass#user-pass */
t3=*((C_word*)lf[286]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in ... */
static void C_ccall f_5998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_5998,c,av);}
a=C_alloc(31);
t2=(*a=C_CLOSURE_TYPE|20,a[1]=(C_word)f_6001,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],tmp=(C_word)a,a+=21,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6685,a[2]=((C_word*)t0)[20],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t1,a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9493,a[2]=t3,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[285];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6001(2,av2);}}}

/* k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in ... */
static void C_ccall f_6001(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,2)))){
C_save_and_reclaim((void *)f_6001,c,av);}
a=C_alloc(26);
t2=(*a=C_CLOSURE_TYPE|19,a[1]=(C_word)f_6004,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],tmp=(C_word)a,a+=20,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6678,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6682,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:699: chicken.compiler.support#canonicalize-begin-body */
t5=*((C_word*)lf[283]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)((C_word*)t0)[20])[1];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in ... */
static void C_ccall f_6004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_6004,c,av);}
a=C_alloc(24);
t2=C_SCHEME_FALSE;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_6007,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=t1,a[18]=((C_word*)t0)[17],a[19]=t3,a[20]=((C_word*)t0)[18],a[21]=((C_word*)t0)[19],tmp=(C_word)a,a+=22,tmp);
/* batch-driver.scm:701: print-node */
t5=((C_word*)((C_word*)t0)[6])[1];
f_5022(t5,t4,lf[279],lf[280],t1);}

/* k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in ... */
static void C_ccall f_6007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,2)))){
C_save_and_reclaim((void *)f_6007,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|21,a[1]=(C_word)f_6010,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],tmp=(C_word)a,a+=22,tmp);
/* batch-driver.scm:702: initialize-analysis-database */
t3=lf[8];
f_4134(t3,t2);}

/* k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in ... */
static void C_ccall f_6010(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_6010,c,av);}
a=C_alloc(28);
t2=*((C_word*)lf[160]+1);
t3=(*a=C_CLOSURE_TYPE|22,a[1]=(C_word)f_6013,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=t2,a[20]=((C_word*)t0)[19],a[21]=((C_word*)t0)[20],a[22]=((C_word*)t0)[21],tmp=(C_word)a,a+=23,tmp);
if(C_truep(*((C_word*)lf[275]+1))){
t4=*((C_word*)lf[160]+1);
t5=C_i_check_list_2(*((C_word*)lf[160]+1),lf[10]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6653,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_6653(t9,t3,*((C_word*)lf[160]+1));}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_6013(2,av2);}}}

/* k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in ... */
static void C_ccall f_6013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,2)))){
C_save_and_reclaim((void *)f_6013,c,av);}
a=C_alloc(23);
t2=(*a=C_CLOSURE_TYPE|22,a[1]=(C_word)f_6016,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],tmp=(C_word)a,a+=23,tmp);
/* batch-driver.scm:714: collect-options */
t3=((C_word*)((C_word*)t0)[21])[1];
f_5327(t3,t2,lf[274]);}

/* k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in ... */
static void C_ccall f_6016(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_6016,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|22,a[1]=(C_word)f_6019,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],tmp=(C_word)a,a+=23,tmp);
if(C_truep(C_i_nullp(t1))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6019(2,av2);}}
else{
t3=C_set_block_item(lf[167] /* chicken.compiler.core#inline-locally */,0,C_SCHEME_TRUE);
t4=C_i_check_list_2(t1,lf[10]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6606,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_6606(t8,t2,t1);}}

/* k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in ... */
static void C_ccall f_6019(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(34,c,3)))){
C_save_and_reclaim((void *)f_6019,c,av);}
a=C_alloc(34);
t2=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_6022,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],tmp=(C_word)a,a+=18,tmp);
t3=((C_word*)((C_word*)t0)[18])[1];
t4=(C_truep(t3)?t3:*((C_word*)lf[121]+1));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6457,a[2]=((C_word*)t0)[19],a[3]=((C_word*)t0)[20],a[4]=t2,a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[17],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[18],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[13],a[11]=((C_word*)t0)[5],a[12]=((C_word*)t0)[21],tmp=(C_word)a,a+=13,tmp);
if(C_truep(C_u_i_memq(lf[269],((C_word*)t0)[22]))){
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_6457(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6583,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:726: chicken.compiler.scrutinizer#load-type-database */
t7=*((C_word*)lf[263]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[271];
av2[3]=*((C_word*)lf[121]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}
else{
t5=t2;
f_6022(t5,C_SCHEME_UNDEFINED);}}

/* k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in ... */
static void C_fcall f_6022(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,2)))){
C_save_and_reclaim_args((void *)trf_6022,2,t0,t1);}
a=C_alloc(21);
t2=C_set_block_item(lf[155] /* ##sys#line-number-database */,0,C_SCHEME_FALSE);
t3=C_set_block_item(lf[161] /* chicken.compiler.core#constant-table */,0,C_SCHEME_FALSE);
t4=C_set_block_item(lf[162] /* chicken.compiler.core#inline-table */,0,C_SCHEME_FALSE);
t5=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_6028,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],tmp=(C_word)a,a+=18,tmp);
if(C_truep(*((C_word*)lf[250]+1))){
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_6028(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6451,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:762: chicken.compiler.support#node-subexpressions */
t7=*((C_word*)lf[252]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[17];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in ... */
static void C_ccall f_6028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_6028,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_6031,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],tmp=(C_word)a,a+=18,tmp);
/* batch-driver.scm:764: begin-time */
t3=((C_word*)((C_word*)t0)[4])[1];
f_5362(t3,t2);}

/* k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in ... */
static void C_ccall f_6031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_6031,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_6034,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
/* batch-driver.scm:766: chicken.compiler.core#perform-cps-conversion */
t3=*((C_word*)lf[249]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[17];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in ... */
static void C_ccall f_6034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_6034,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_6037,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=t1,tmp=(C_word)a,a+=18,tmp);
/* batch-driver.scm:767: end-time */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5372(t3,t2,lf[248]);}

/* k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in ... */
static void C_ccall f_6037(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_6037,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_6040,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],tmp=(C_word)a,a+=18,tmp);
/* batch-driver.scm:768: print-node */
t3=((C_word*)((C_word*)t0)[6])[1];
f_5022(t3,t2,lf[246],lf[247],((C_word*)t0)[17]);}

/* k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in ... */
static void C_ccall f_6040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,7)))){
C_save_and_reclaim((void *)f_6040,c,av);}
a=C_alloc(19);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_6045,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],tmp=(C_word)a,a+=17,tmp));
t5=((C_word*)t3)[1];
f_6045(t5,((C_word*)t0)[16],C_fix(1),((C_word*)t0)[17],C_SCHEME_TRUE,C_SCHEME_FALSE,C_SCHEME_FALSE);}

/* loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in ... */
static void C_fcall f_6045(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(25,0,2)))){
C_save_and_reclaim_args((void *)trf_6045,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(25);
t7=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t8=(*a=C_CLOSURE_TYPE|22,a[1]=(C_word)f_6049,a[2]=t4,a[3]=t5,a[4]=t7,a[5]=t2,a[6]=((C_word*)t0)[2],a[7]=t6,a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[6],a[12]=((C_word*)t0)[7],a[13]=t1,a[14]=((C_word*)t0)[8],a[15]=((C_word*)t0)[9],a[16]=((C_word*)t0)[10],a[17]=((C_word*)t0)[11],a[18]=((C_word*)t0)[12],a[19]=((C_word*)t0)[13],a[20]=((C_word*)t0)[14],a[21]=((C_word*)t0)[15],a[22]=((C_word*)t0)[16],tmp=(C_word)a,a+=23,tmp);
/* batch-driver.scm:776: begin-time */
t9=((C_word*)((C_word*)t0)[5])[1];
f_5362(t9,t8);}

/* k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in ... */
static void C_ccall f_6049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,4)))){
C_save_and_reclaim((void *)f_6049,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|22,a[1]=(C_word)f_6052,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],tmp=(C_word)a,a+=23,tmp);
/* batch-driver.scm:778: analyze */
t3=((C_word*)((C_word*)t0)[11])[1];
f_5412(t3,t2,lf[245],((C_word*)((C_word*)t0)[4])[1],C_a_i_list(&a,2,((C_word*)t0)[5],((C_word*)t0)[2]));}

/* k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in ... */
static void C_ccall f_6052(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,2)))){
C_save_and_reclaim((void *)f_6052,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|23,a[1]=(C_word)f_6055,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],a[17]=((C_word*)t0)[16],a[18]=((C_word*)t0)[17],a[19]=((C_word*)t0)[18],a[20]=((C_word*)t0)[19],a[21]=((C_word*)t0)[20],a[22]=((C_word*)t0)[21],a[23]=((C_word*)t0)[22],tmp=(C_word)a,a+=24,tmp);
if(C_truep(*((C_word*)lf[163]+1))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6389,a[2]=t2,a[3]=((C_word*)t0)[15],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_memq(lf[243],*((C_word*)lf[102]+1)))){
/* batch-driver.scm:781: chicken.compiler.support#dump-undefined-globals */
t4=*((C_word*)lf[244]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_6389(2,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6055(2,av2);}}}

/* k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in ... */
static void C_ccall f_6055(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_6055,c,av);}
a=C_alloc(24);
t2=C_set_block_item(lf[163] /* chicken.compiler.core#first-analysis */,0,C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|23,a[1]=(C_word)f_6059,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],tmp=(C_word)a,a+=24,tmp);
/* batch-driver.scm:794: end-time */
t4=((C_word*)((C_word*)t0)[10])[1];
f_5372(t4,t3,lf[233]);}

/* k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in ... */
static void C_ccall f_6059(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,5)))){
C_save_and_reclaim((void *)f_6059,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|23,a[1]=(C_word)f_6062,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],tmp=(C_word)a,a+=24,tmp);
/* batch-driver.scm:795: print-db */
t3=((C_word*)((C_word*)t0)[21])[1];
f_5044(t3,t2,lf[231],lf[232],((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in ... */
static void C_ccall f_6062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,9)))){
C_save_and_reclaim((void *)f_6062,c,av);}
a=C_alloc(29);
t2=(*a=C_CLOSURE_TYPE|23,a[1]=(C_word)f_6065,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],tmp=(C_word)a,a+=24,tmp);
if(C_truep(C_i_memq(lf[221],*((C_word*)lf[102]+1)))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4041,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4047,tmp=(C_word)a,a+=2,tmp);
/* batch-driver.scm:72: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6065(2,av2);}}}

/* k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in ... */
static void C_ccall f_6065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_6065,c,av);}
a=C_alloc(24);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6071,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],tmp=(C_word)a,a+=14,tmp);
/* batch-driver.scm:802: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[104];
av2[3]=lf[181];
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_6172,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[15],a[6]=((C_word*)t0)[16],a[7]=((C_word*)t0)[17],a[8]=((C_word*)t0)[18],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[14],a[11]=((C_word*)t0)[19],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[20],a[14]=((C_word*)t0)[21],a[15]=((C_word*)t0)[6],a[16]=((C_word*)t0)[22],tmp=(C_word)a,a+=17,tmp);
if(C_truep(((C_word*)t0)[23])){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6352,a[2]=((C_word*)t0)[10],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:842: begin-time */
t4=((C_word*)((C_word*)t0)[11])[1];
f_5362(t4,t3);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6172(2,av2);}}}}

/* k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in ... */
static void C_ccall f_6071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6071,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6074,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* batch-driver.scm:803: begin-time */
t3=((C_word*)((C_word*)t0)[10])[1];
f_5362(t3,t2);}

/* k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in ... */
static void C_ccall f_6074(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,4)))){
C_save_and_reclaim((void *)f_6074,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6079,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6091,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[12],tmp=(C_word)a,a+=11,tmp);
/* batch-driver.scm:804: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[13];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a6078 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f_6079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_6079,c,av);}
if(C_truep(((C_word*)t0)[2])){
/* batch-driver.scm:806: chicken.compiler.optimizer#determine-loop-and-dispatch */
t2=*((C_word*)lf[164]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
/* batch-driver.scm:807: chicken.compiler.optimizer#perform-high-level-optimizations */
t2=*((C_word*)lf[165]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=((C_word*)t0)[4];
av2[4]=*((C_word*)lf[166]+1);
av2[5]=*((C_word*)lf[167]+1);
av2[6]=*((C_word*)lf[168]+1);
av2[7]=*((C_word*)lf[169]+1);
av2[8]=*((C_word*)lf[170]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(9,av2);}}}

/* a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f_6091(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6091,c,av);}
a=C_alloc(14);
t4=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6095,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t2,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],a[12]=((C_word*)t0)[9],a[13]=((C_word*)t0)[10],tmp=(C_word)a,a+=14,tmp);
/* batch-driver.scm:812: end-time */
t5=((C_word*)((C_word*)t0)[7])[1];
f_5372(t5,t4,lf[180]);}

/* k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in ... */
static void C_ccall f_6095(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_6095,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6098,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
/* batch-driver.scm:813: print-node */
t3=((C_word*)((C_word*)t0)[13])[1];
f_5022(t3,t2,lf[178],lf[179],((C_word*)t0)[6]);}

/* k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in ... */
static void C_ccall f_6098(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,6)))){
C_save_and_reclaim((void *)f_6098,c,av);}
a=C_alloc(29);
if(C_truep(((C_word*)t0)[2])){
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1));
/* batch-driver.scm:815: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_6045(t3,((C_word*)t0)[5],t2,((C_word*)t0)[6],C_SCHEME_TRUE,C_SCHEME_FALSE,((C_word*)t0)[7]);}
else{
t2=C_i_not(((C_word*)t0)[8]);
t3=(C_truep(t2)?((C_word*)t0)[9]:C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6115,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:817: chicken.compiler.support#debugging */
t5=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[104];
av2[3]=lf[171];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
if(C_truep(C_i_not(*((C_word*)lf[170]+1)))){
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6129,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:820: chicken.compiler.support#debugging */
t5=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[104];
av2[3]=lf[172];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
if(C_truep(*((C_word*)lf[173]+1))){
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6141,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[12],tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:824: begin-time */
t5=((C_word*)((C_word*)t0)[11])[1];
f_5362(t5,t4);}
else{
t4=C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1));
/* batch-driver.scm:837: loop */
t5=((C_word*)((C_word*)t0)[4])[1];
f_6045(t5,((C_word*)t0)[5],t4,((C_word*)t0)[6],C_SCHEME_FALSE,C_SCHEME_FALSE,((C_word*)t0)[8]);}}}}}

/* k6113 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in ... */
static void C_ccall f_6115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,6)))){
C_save_and_reclaim((void *)f_6115,c,av);}
a=C_alloc(29);
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1));
/* batch-driver.scm:818: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_6045(t3,((C_word*)t0)[4],t2,((C_word*)t0)[5],C_SCHEME_TRUE,C_SCHEME_TRUE,C_SCHEME_TRUE);}

/* k6127 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in ... */
static void C_ccall f_6129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,6)))){
C_save_and_reclaim((void *)f_6129,c,av);}
a=C_alloc(29);
t2=C_set_block_item(lf[170] /* chicken.compiler.core#inline-substitutions-enabled */,0,C_SCHEME_TRUE);
t3=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1));
/* batch-driver.scm:822: loop */
t4=((C_word*)((C_word*)t0)[3])[1];
f_6045(t4,((C_word*)t0)[4],t3,((C_word*)t0)[5],C_SCHEME_TRUE,C_SCHEME_FALSE,((C_word*)t0)[6]);}

/* k6139 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in ... */
static void C_ccall f_6141(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_6141,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6144,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:825: analyze */
t3=((C_word*)((C_word*)t0)[9])[1];
f_5412(t3,t2,lf[177],((C_word*)t0)[5],C_SCHEME_END_OF_LIST);}

/* k6142 in k6139 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in ... */
static void C_ccall f_6144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_6144,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6147,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:826: end-time */
t3=((C_word*)((C_word*)t0)[7])[1];
f_5372(t3,t2,lf[176]);}

/* k6145 in k6142 in k6139 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in ... */
static void C_ccall f_6147(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6147,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6150,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:827: begin-time */
t3=((C_word*)((C_word*)t0)[9])[1];
f_5362(t3,t2);}

/* k6148 in k6145 in k6142 in k6139 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in ... */
static void C_ccall f_6150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_6150,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6153,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:829: chicken.compiler.optimizer#transform-direct-lambdas! */
t3=*((C_word*)lf[175]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6151 in k6148 in k6145 in k6142 in k6139 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in ... */
static void C_ccall f_6153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6153,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6156,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:830: end-time */
t3=((C_word*)((C_word*)t0)[7])[1];
f_5372(t3,t2,lf[174]);}

/* k6154 in k6151 in k6148 in k6145 in k6142 in k6139 in k6096 in k6093 in a6090 in k6072 in k6069 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in ... */
static void C_ccall f_6156(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,6)))){
C_save_and_reclaim((void *)f_6156,c,av);}
a=C_alloc(29);
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1));
/* batch-driver.scm:831: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_6045(t3,((C_word*)t0)[4],t2,((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE,((C_word*)t0)[7]);}

/* k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in ... */
static void C_ccall f_6172(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_6172,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_6175,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
/* batch-driver.scm:851: print-node */
t3=((C_word*)((C_word*)t0)[12])[1];
f_5022(t3,t2,lf[213],lf[214],((C_word*)((C_word*)t0)[2])[1]);}

/* k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in ... */
static void C_ccall f_6175(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,4)))){
C_save_and_reclaim((void *)f_6175,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_6178,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
t3=(C_truep(((C_word*)((C_word*)t0)[16])[1])?*((C_word*)lf[208]+1):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=((C_word*)((C_word*)t0)[16])[1];
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6302,a[2]=t2,a[3]=((C_word*)t0)[6],a[4]=t4,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t6=C_a_i_list(&a,1,t4);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9457,a[2]=t5,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t7;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[212];
av2[4]=t6;
C_apply(5,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_6178(2,av2);}}}

/* k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f_6178(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_6178,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_6181,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
/* batch-driver.scm:861: begin-time */
t3=((C_word*)((C_word*)t0)[9])[1];
f_5362(t3,t2);}

/* k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in ... */
static void C_ccall f_6181(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_6181,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_6185,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
/* batch-driver.scm:863: chicken.compiler.core#perform-closure-conversion */
t3=*((C_word*)lf[207]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in ... */
static void C_ccall f_6185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_6185,c,av);}
a=C_alloc(16);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_6188,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],tmp=(C_word)a,a+=16,tmp);
/* batch-driver.scm:864: end-time */
t4=((C_word*)((C_word*)t0)[4])[1];
f_5372(t4,t3,lf[206]);}

/* k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in ... */
static void C_ccall f_6188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_6188,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6191,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* batch-driver.scm:865: print-db */
t3=((C_word*)((C_word*)t0)[14])[1];
f_5044(t3,t2,lf[204],lf[205],((C_word*)t0)[3],((C_word*)t0)[15]);}

/* k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in ... */
static void C_ccall f_6191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_6191,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6194,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
if(C_truep(*((C_word*)lf[202]+1))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6296,a[2]=((C_word*)t0)[13],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:254: chicken.time#current-process-milliseconds */
t4=*((C_word*)lf[113]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6194(2,av2);}}}

/* k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in ... */
static void C_ccall f_6194(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_6194,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6197,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* batch-driver.scm:869: print-node */
t3=((C_word*)((C_word*)t0)[12])[1];
f_5022(t3,t2,lf[200],lf[201],((C_word*)((C_word*)t0)[2])[1]);}

/* k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in ... */
static void C_ccall f_6197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6197,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6200,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(((C_word*)t0)[11])){
/* batch-driver.scm:870: chicken.base#exit */
t3=*((C_word*)lf[199]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(0);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6200(2,av2);}}}

/* k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in ... */
static void C_ccall f_6200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6200,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6203,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
/* batch-driver.scm:871: begin-time */
t3=((C_word*)((C_word*)t0)[9])[1];
f_5362(t3,t2);}

/* k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in ... */
static void C_ccall f_6203(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,7)))){
C_save_and_reclaim((void *)f_6203,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6208,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6214,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[9],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:873: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[10];
av2[2]=t2;
av2[3]=t3;
C_call_with_values(4,av2);}}

/* a6207 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in ... */
static void C_ccall f_6208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6208,c,av);}
/* batch-driver.scm:874: chicken.compiler.core#prepare-for-code-generation */
t2=*((C_word*)lf[182]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in ... */
static void C_ccall f_6214(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6=av[6];
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_6214,c,av);}
a=C_alloc(14);
t7=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6218,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t3,a[6]=t4,a[7]=t5,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=t6,a[13]=((C_word*)t0)[8],tmp=(C_word)a,a+=14,tmp);
/* batch-driver.scm:875: end-time */
t8=((C_word*)((C_word*)t0)[2])[1];
f_5372(t8,t7,lf[198]);}

/* k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in ... */
static void C_ccall f_6218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6218,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6221,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
/* batch-driver.scm:876: begin-time */
t3=((C_word*)((C_word*)t0)[13])[1];
f_5362(t3,t2);}

/* k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in ... */
static void C_ccall f_6221(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6221,c,av);}
a=C_alloc(23);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6224,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
if(C_truep(*((C_word*)lf[194]+1))){
t3=*((C_word*)lf[160]+1);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6267,a[2]=t3,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t5=C_a_i_list(&a,1,*((C_word*)lf[194]+1));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9449,a[2]=t4,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t6;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[197];
av2[4]=t5;
C_apply(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6224(2,av2);}}}

/* k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in ... */
static void C_ccall f_6224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_6224,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6227,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
if(C_truep(((C_word*)t0)[4])){
/* batch-driver.scm:885: scheme#open-output-file */
t3=*((C_word*)lf[193]+1);{
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
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=*((C_word*)lf[20]+1);
f_6227(2,av2);}}}

/* k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in ... */
static void C_ccall f_6227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_6227,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6230,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
t3=C_a_i_list(&a,1,((C_word*)t0)[4]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9443,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[192];
av2[4]=t3;
C_apply(5,av2);}}

/* k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in ... */
static void C_ccall f_6230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,10)))){
C_save_and_reclaim((void *)f_6230,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6233,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:887: chicken.compiler.c-backend#generate-code */
t3=*((C_word*)lf[191]+1);{
C_word *av2;
if(c >= 11) {
  av2=av;
} else {
  av2=C_alloc(11);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=((C_word*)t0)[8];
av2[5]=((C_word*)t0)[5];
av2[6]=((C_word*)t0)[9];
av2[7]=((C_word*)t0)[10];
av2[8]=((C_word*)t0)[11];
av2[9]=((C_word*)t0)[12];
av2[10]=((C_word*)t0)[13];
((C_proc)(void*)(*((C_word*)t3+1)))(11,av2);}}

/* k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in ... */
static void C_ccall f_6233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6233,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6236,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[4])){
/* batch-driver.scm:890: scheme#close-output-port */
t3=*((C_word*)lf[190]+1);{
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
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6236(2,av2);}}}

/* k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in ... */
static void C_ccall f_6236(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6236,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6239,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:891: end-time */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5372(t3,t2,lf[189]);}

/* k6237 in k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in ... */
static void C_ccall f_6239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6239,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6242,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_memq(lf[186],*((C_word*)lf[102]+1)))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6258,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:893: ##sys#stop-timer */
t4=*((C_word*)lf[188]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f8775,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:894: chicken.compiler.support#compiler-cleanup-hook */
t4=*((C_word*)lf[185]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6240 in k6237 in k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in ... */
static void C_ccall f_6242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6242,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6245,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:894: chicken.compiler.support#compiler-cleanup-hook */
t3=*((C_word*)lf[185]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6243 in k6240 in k6237 in k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in ... */
static void C_ccall f_6245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_6245,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9431,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t2;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[184];
av2[4]=C_SCHEME_END_OF_LIST;
C_apply(5,av2);}}

/* k6256 in k6237 in k6234 in k6231 in k6228 in k6225 in k6222 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in ... */
static void C_ccall f_6258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6258,c,av);}
/* batch-driver.scm:893: ##sys#display-times */
t2=*((C_word*)lf[187]+1);{
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

/* k6265 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in ... */
static void C_ccall f_6267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6267,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6272,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:882: scheme#with-output-to-file */
t3=*((C_word*)lf[196]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=*((C_word*)lf[194]+1);
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a6271 in k6265 in k6219 in k6216 in a6213 in k6201 in k6198 in k6195 in k6192 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in ... */
static void C_ccall f_6272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6272,c,av);}
t2=*((C_word*)lf[195]+1);
/* batch-driver.scm:882: g2176 */
t3=*((C_word*)lf[195]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6294 in k6189 in k6186 in k6183 in k6179 in k6176 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in ... */
static void C_ccall f_6296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,2)))){
C_save_and_reclaim((void *)f_6296,c,av);}
a=C_alloc(29);
t2=C_s_a_i_minus(&a,2,t1,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(C_i_greaterp(t2,C_fix(60000)))){
/* batch-driver.scm:868: scheme#display */
t3=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[203];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6194(2,av2);}}}

/* k6300 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f_6302(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,3)))){
C_save_and_reclaim((void *)f_6302,c,av);}
a=C_alloc(19);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=*((C_word*)lf[209]+1);
t7=*((C_word*)lf[210]+1);
t8=C_i_check_list_2(*((C_word*)lf[210]+1),lf[5]);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6315,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6317,a[2]=t4,a[3]=t11,a[4]=t6,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_6317(t13,t9,*((C_word*)lf[210]+1));}

/* k6313 in k6300 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in ... */
static void C_ccall f_6315(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_6315,c,av);}
/* batch-driver.scm:857: chicken.compiler.support#emit-global-inline-file */
t2=*((C_word*)lf[211]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=*((C_word*)lf[166]+1);
av2[6]=*((C_word*)lf[168]+1);
av2[7]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}

/* map-loop2141 in k6300 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in ... */
static void C_fcall f_6317(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6317,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6342,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:860: g2147 */
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

/* k6340 in map-loop2141 in k6300 in k6173 in k6170 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in ... */
static void C_ccall f_6342(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6342,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6317(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in ... */
static void C_ccall f_6352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6352,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6355,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:843: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[104];
av2[3]=lf[220];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6353 in k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in ... */
static void C_ccall f_6355(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6355,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6358,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:844: chicken.compiler.lfa2#perform-secondary-flow-analysis */
t3=*((C_word*)lf[219]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6356 in k6353 in k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in ... */
static void C_ccall f_6358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6358,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6361,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:845: end-time */
t3=((C_word*)((C_word*)t0)[2])[1];
f_5372(t3,t2,lf[218]);}

/* k6359 in k6356 in k6353 in k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in ... */
static void C_ccall f_6361(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6361,c,av);}
a=C_alloc(6);
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
/* batch-driver.scm:850: end-time */
t2=((C_word*)((C_word*)t0)[3])[1];
f_5372(t2,((C_word*)t0)[4],lf[215]);}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6373,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:847: begin-time */
t3=((C_word*)((C_word*)t0)[6])[1];
f_5362(t3,t2);}}

/* k6371 in k6359 in k6356 in k6353 in k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in ... */
static void C_ccall f_6373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6373,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6376,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:848: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[104];
av2[3]=lf[217];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6374 in k6371 in k6359 in k6356 in k6353 in k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in ... */
static void C_ccall f_6376(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6376,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6380,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:849: chicken.compiler.lfa2#perform-unboxing */
t3=*((C_word*)lf[216]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6378 in k6374 in k6371 in k6359 in k6356 in k6353 in k6350 in k6063 in k6060 in k6057 in k6053 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in ... */
static void C_ccall f_6380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6380,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* batch-driver.scm:850: end-time */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5372(t3,((C_word*)t0)[4],lf[215]);}

/* k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in ... */
static void C_ccall f_6389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6389,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6392,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_memq(lf[241],*((C_word*)lf[102]+1)))){
/* batch-driver.scm:783: chicken.compiler.support#dump-defined-globals */
t3=*((C_word*)lf[242]+1);{
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
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6392(2,av2);}}}

/* k6390 in k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in ... */
static void C_ccall f_6392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6392,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6395,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_memq(lf[239],*((C_word*)lf[102]+1)))){
/* batch-driver.scm:785: chicken.compiler.support#dump-global-refs */
t3=*((C_word*)lf[240]+1);{
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
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6395(2,av2);}}}

/* k6393 in k6390 in k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in ... */
static void C_ccall f_6395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6395,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6398,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(*((C_word*)lf[236]+1),C_SCHEME_TRUE);
if(C_truep(t3)){
/* batch-driver.scm:788: chicken.pathname#pathname-replace-extension */
t4=*((C_word*)lf[237]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[238];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_6398(2,av2);}}}

/* k6396 in k6393 in k6390 in k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in ... */
static void C_ccall f_6398(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6398,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6401,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=t2;
f_6401(t3,t1);}
else{
if(C_truep(C_i_stringp(*((C_word*)lf[236]+1)))){
t3=*((C_word*)lf[236]+1);
t4=t2;
f_6401(t4,*((C_word*)lf[236]+1));}
else{
t3=t2;
f_6401(t3,C_SCHEME_FALSE);}}}

/* k6399 in k6396 in k6393 in k6390 in k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in ... */
static void C_fcall f_6401(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_6401,2,t0,t1);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6407,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=C_a_i_list(&a,1,t1);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9463,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[235];
av2[4]=t3;
C_apply(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_6055(2,av2);}}}

/* k6405 in k6399 in k6396 in k6393 in k6390 in k6387 in k6050 in k6047 in loop in k6038 in k6035 in k6032 in k6029 in k6026 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in ... */
static void C_ccall f_6407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6407,c,av);}
/* batch-driver.scm:792: chicken.compiler.scrutinizer#emit-types-file */
t2=*((C_word*)lf[234]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=*((C_word*)lf[166]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k6449 in k6020 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in ... */
static void C_ccall f_6451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6451,c,av);}
/* batch-driver.scm:762: chicken.compiler.optimizer#scan-toplevel-assignments */
t2=*((C_word*)lf[251]+1);{
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

/* k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in ... */
static void C_ccall f_6457(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_6457,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6471,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* batch-driver.scm:734: collect-options */
t3=((C_word*)((C_word*)t0)[12])[1];
f_5327(t3,t2,lf[268]);}

/* k6460 in for-each-loop2036 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in ... */
static void C_ccall f_6462(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6462,c,av);}
if(C_truep(t1)){
t2=((C_word*)((C_word*)t0)[2])[1];
f_6554(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}
else{
/* batch-driver.scm:733: chicken.compiler.support#quit-compiling */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[267];
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in ... */
static void C_ccall f_6471(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_6471,c,av);}
a=C_alloc(17);
t2=C_i_check_list_2(t1,lf[10]);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6477,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6554,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_6554(t7,t3,t1);}

/* k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in ... */
static void C_ccall f_6477(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_6477,c,av);}
a=C_alloc(16);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[10]);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6496,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],tmp=(C_word)a,a+=11,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6531,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_6531(t7,t3,((C_word*)t0)[2]);}

/* k6484 in for-each-loop2057 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in ... */
static void C_ccall f_6486(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6486,c,av);}
/* batch-driver.scm:737: chicken.compiler.scrutinizer#load-type-database */
t2=*((C_word*)lf[263]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=*((C_word*)lf[121]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k6488 in for-each-loop2057 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in ... */
static void C_ccall f_6490(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6490,c,av);}
/* batch-driver.scm:738: chicken.pathname#make-pathname */
t2=*((C_word*)lf[264]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
av2[3]=t1;
av2[4]=lf[265];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in ... */
static void C_ccall f_6496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_6496,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6499,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
/* batch-driver.scm:741: begin-time */
t3=((C_word*)((C_word*)t0)[8])[1];
f_5362(t3,t2);}

/* k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in ... */
static void C_ccall f_6499(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_6499,c,av);}
a=C_alloc(10);
t2=C_set_block_item(lf[163] /* chicken.compiler.core#first-analysis */,0,C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6504,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* batch-driver.scm:743: analyze */
t4=((C_word*)((C_word*)t0)[10])[1];
f_5412(t4,t3,lf[262],((C_word*)t0)[5],C_SCHEME_END_OF_LIST);}

/* k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in ... */
static void C_ccall f_6504(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_6504,c,av);}
a=C_alloc(9);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6507,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:744: print-db */
t4=((C_word*)((C_word*)t0)[9])[1];
f_5044(t4,t3,lf[260],lf[261],((C_word*)((C_word*)t0)[2])[1],C_fix(0));}

/* k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in ... */
static void C_ccall f_6507(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_6507,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6510,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* batch-driver.scm:745: end-time */
t3=((C_word*)((C_word*)t0)[5])[1];
f_5372(t3,t2,lf[259]);}

/* k6508 in k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in ... */
static void C_ccall f_6510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_6510,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6513,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:746: begin-time */
t3=((C_word*)((C_word*)t0)[8])[1];
f_5362(t3,t2);}

/* k6511 in k6508 in k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in ... */
static void C_ccall f_6513(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_6513,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6516,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* batch-driver.scm:747: chicken.compiler.support#debugging */
t3=*((C_word*)lf[103]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[104];
av2[3]=lf[258];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6514 in k6511 in k6508 in k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in ... */
static void C_ccall f_6516(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,7)))){
C_save_and_reclaim((void *)f_6516,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6519,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:748: chicken.compiler.scrutinizer#scrutinize */
t3=*((C_word*)lf[256]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)((C_word*)t0)[6])[1];
av2[4]=((C_word*)((C_word*)t0)[7])[1];
av2[5]=*((C_word*)lf[121]+1);
av2[6]=*((C_word*)lf[257]+1);
av2[7]=*((C_word*)lf[166]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(8,av2);}}

/* k6517 in k6514 in k6511 in k6508 in k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in ... */
static void C_ccall f_6519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6519,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6522,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:751: end-time */
t3=((C_word*)((C_word*)t0)[5])[1];
f_5372(t3,t2,lf[255]);}

/* k6520 in k6517 in k6514 in k6511 in k6508 in k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in ... */
static void C_ccall f_6522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_6522,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6525,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(*((C_word*)lf[121]+1))){
/* batch-driver.scm:753: print-node */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5022(t3,t2,lf[253],lf[254],((C_word*)t0)[4]);}
else{
t3=C_set_block_item(lf[163] /* chicken.compiler.core#first-analysis */,0,C_SCHEME_TRUE);
t4=((C_word*)t0)[2];
f_6022(t4,t3);}}

/* k6523 in k6520 in k6517 in k6514 in k6511 in k6508 in k6505 in k6502 in k6497 in k6494 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in ... */
static void C_ccall f_6525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6525,c,av);}
t2=C_set_block_item(lf[163] /* chicken.compiler.core#first-analysis */,0,C_SCHEME_TRUE);
t3=((C_word*)t0)[2];
f_6022(t3,t2);}

/* for-each-loop2057 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in ... */
static void C_fcall f_6531(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_6531,3,t0,t1,t2);}
a=C_alloc(11);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6541,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6486,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6490,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:738: scheme#symbol->string */
t7=*((C_word*)lf[266]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6539 in for-each-loop2057 in k6475 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in ... */
static void C_ccall f_6541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6541,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6531(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop2036 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in ... */
static void C_fcall f_6554(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_6554,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6564,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6462,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:732: chicken.compiler.scrutinizer#load-type-database */
t6=*((C_word*)lf[263]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=*((C_word*)lf[121]+1);
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6562 in for-each-loop2036 in k6469 in k6455 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in ... */
static void C_ccall f_6564(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6564,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6554(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6581 in k6017 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in ... */
static void C_ccall f_6583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6583,c,av);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_6457(2,av2);}}
else{
/* batch-driver.scm:728: chicken.compiler.support#quit-compiling */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[270];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k6593 in for-each-loop2013 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in ... */
static void C_ccall f_6595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6595,c,av);}
/* batch-driver.scm:720: chicken.compiler.support#load-inline-file */
t2=*((C_word*)lf[272]+1);{
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

/* for-each-loop2013 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in ... */
static void C_fcall f_6606(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_6606,3,t0,t1,t2);}
a=C_alloc(15);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6616,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6595,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_a_i_list(&a,1,t4);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9475,a[2]=t5,tmp=(C_word)a,a+=3,tmp);{
C_word av2[5];
av2[0]=0;
av2[1]=t7;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[273];
av2[4]=t6;
C_apply(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6614 in for-each-loop2013 in k6014 in k6011 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in ... */
static void C_ccall f_6616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6616,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6606(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6630 in for-each-loop1991 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in ... */
static void C_ccall f_6632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_6632,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6638,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_list(&a,1,t1);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9483,a[2]=t2,tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[276];
av2[4]=t3;
C_apply(5,av2);}}
else{
t2=((C_word*)((C_word*)t0)[3])[1];
f_6653(t2,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}}

/* k6636 in k6630 in for-each-loop1991 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in ... */
static void C_ccall f_6638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6638,c,av);}
/* batch-driver.scm:712: chicken.compiler.support#load-inline-file */
t2=*((C_word*)lf[272]+1);{
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

/* k6643 in for-each-loop1991 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in ... */
static void C_ccall f_6645(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6645,c,av);}
/* batch-driver.scm:709: ##sys#resolve-include-filename */
t2=*((C_word*)lf[277]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[278];
av2[4]=C_SCHEME_TRUE;
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* for-each-loop1991 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in ... */
static void C_fcall f_6653(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,2)))){
C_save_and_reclaim_args((void *)trf_6653,3,t0,t1,t2);}
a=C_alloc(14);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6663,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6632,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6645,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:710: scheme#symbol->string */
t7=*((C_word*)lf[266]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6661 in for-each-loop1991 in k6008 in k6005 in k6002 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in ... */
static void C_ccall f_6663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6663,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6653(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6676 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in ... */
static void C_ccall f_6678(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6678,c,av);}
/* batch-driver.scm:697: chicken.compiler.core#build-toplevel-procedure */
t2=*((C_word*)lf[281]+1);{
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

/* k6680 in k5999 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in ... */
static void C_ccall f_6682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6682,c,av);}
/* batch-driver.scm:698: chicken.compiler.support#build-node-graph */
t2=*((C_word*)lf[282]+1);{
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

/* k6683 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in ... */
static void C_ccall f_6685(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6685,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6688,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:692: begin-time */
t3=((C_word*)((C_word*)t0)[6])[1];
f_5362(t3,t2);}

/* k6686 in k6683 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in ... */
static void C_ccall f_6688(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_6688,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=((C_word*)((C_word*)t0)[2])[1];
t7=C_i_check_list_2(t6,lf[5]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6698,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6703,a[2]=t4,a[3]=t10,a[4]=((C_word*)t0)[5],a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_6703(t12,t8,t6);}

/* k6696 in k6686 in k6683 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in ... */
static void C_ccall f_6698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6698,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* batch-driver.scm:694: end-time */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5372(t3,((C_word*)t0)[4],lf[284]);}

/* map-loop1959 in k6686 in k6683 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in ... */
static void C_fcall f_6703(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6703,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6728,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:693: g1965 */
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

/* k6726 in map-loop1959 in k6686 in k6683 in k5996 in k5993 in k5990 in k5987 in k5982 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in ... */
static void C_ccall f_6728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6728,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6703(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6741 in k5979 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in ... */
static void C_ccall f_6743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6743,c,av);}
if(C_truep(t1)){
/* batch-driver.scm:678: ##sys#display-line-number-database */
t2=*((C_word*)lf[291]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_5984(2,av2);}}}

/* k6747 in k5976 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in ... */
static void C_ccall f_6749(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6749,c,av);}
if(C_truep(t1)){
/* batch-driver.scm:676: chicken.compiler.support#display-real-name-table */
t2=*((C_word*)lf[294]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_5981(2,av2);}}}

/* a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in ... */
static void C_ccall f_6760(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6760,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6764,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:671: chicken.base#print */
t3=*((C_word*)lf[300]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[301];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in ... */
static void C_ccall f_6764(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6764,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[297]+1);
t3=C_i_check_list_2(*((C_word*)lf[297]+1),lf[10]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6798,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_6798(t7,((C_word*)t0)[2],*((C_word*)lf[297]+1));}

/* k6770 in for-each-loop1930 in k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in ... */
static void C_ccall f_6772(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6772,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6775,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:673: ##sys#print */
t3=*((C_word*)lf[22]+1);{
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

/* k6773 in k6770 in for-each-loop1930 in k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in ... */
static void C_ccall f_6775(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6775,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6778,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:673: ##sys#print */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[298];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6776 in k6773 in k6770 in for-each-loop1930 in k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in ... */
static void C_ccall f_6778(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6778,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6781,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:673: ##sys#print */
t3=*((C_word*)lf[22]+1);{
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

/* k6779 in k6776 in k6773 in k6770 in for-each-loop1930 in k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in ... */
static void C_ccall f_6781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6781,c,av);}
/* batch-driver.scm:673: ##sys#write-char-0 */
t2=*((C_word*)lf[34]+1);{
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

/* for-each-loop1930 in k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in ... */
static void C_fcall f_6798(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6798,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6808,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[20]+1);
t6=*((C_word*)lf[20]+1);
t7=C_i_check_port_2(*((C_word*)lf[20]+1),C_fix(2),C_SCHEME_TRUE,lf[21]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6772,a[2]=t3,a[3]=t5,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:673: ##sys#print */
t9=*((C_word*)lf[22]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[299];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[20]+1);
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6806 in for-each-loop1930 in k6762 in a6759 in k5973 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in ... */
static void C_ccall f_6808(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6808,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6798(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6827 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in ... */
static void C_ccall f_6829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6829,c,av);}
/* batch-driver.scm:660: chicken.compiler.support#quit-compiling */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[304];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k6846 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in ... */
static void C_ccall f_6848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6848,c,av);}
/* batch-driver.scm:663: chicken.string#string-intersperse */
t2=*((C_word*)lf[305]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[306];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop1903 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in ... */
static void C_fcall f_6850(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6850,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6875,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
/* batch-driver.scm:664: chicken.string#->string */
t5=*((C_word*)lf[307]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t3;
av2[2]=C_i_car(t4);
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6873 in map-loop1903 in k5970 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in ... */
static void C_ccall f_6875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6875,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6850(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6905 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in ... */
static void C_ccall f_6907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_6907,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6911,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(*((C_word*)lf[312]+1))){
t3=C_a_i_list(&a,2,lf[314],*((C_word*)lf[312]+1));
t4=t2;
f_6911(t4,C_a_i_list(&a,1,t3));}
else{
t3=t2;
f_6911(t3,C_SCHEME_END_OF_LIST);}}

/* k6909 in k6905 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in ... */
static void C_fcall f_6911(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_6911,2,t0,t1);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6915,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(*((C_word*)lf[311]+1))){
if(C_truep(C_i_not(*((C_word*)lf[312]+1)))){
if(C_truep(((C_word*)t0)[8])){
/* batch-driver.scm:651: chicken.compiler.support#profiling-prelude-exps */
t3=*((C_word*)lf[313]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
/* batch-driver.scm:651: chicken.compiler.support#profiling-prelude-exps */
t3=*((C_word*)lf[313]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
/* batch-driver.scm:651: chicken.compiler.support#profiling-prelude-exps */
t3=*((C_word*)lf[313]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
f_6915(2,av2);}}}

/* k6913 in k6909 in k6905 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in ... */
static void C_ccall f_6915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_6915,c,av);}
if(C_truep(*((C_word*)lf[309]+1))){
t2=((C_word*)((C_word*)t0)[2])[1];
/* batch-driver.scm:645: scheme#append */
t3=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
av2[6]=t1;
av2[7]=((C_word*)t0)[8];
av2[8]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(9,av2);}}
else{
/* batch-driver.scm:645: scheme#append */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
av2[6]=t1;
av2[7]=((C_word*)t0)[8];
av2[8]=lf[310];
((C_proc)(void*)(*((C_word*)t2+1)))(9,av2);}}}

/* map-loop1866 in k5967 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in ... */
static void C_fcall f_6941(C_word t0,C_word t1,C_word t2){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(18,0,2)))){
C_save_and_reclaim_args((void *)trf_6941,3,t0,t1,t2);}
a=C_alloc(18);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_cdr(t3);
t5=C_u_i_car(t3);
t6=C_a_i_list(&a,2,lf[315],t5);
t7=C_a_i_list(&a,3,lf[316],t4,t6);
t8=C_a_i_cons(&a,2,t7,C_SCHEME_END_OF_LIST);
t9=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t8);
t10=C_mutate(((C_word *)((C_word*)t0)[2])+1,t8);
t12=t1;
t13=C_slot(t2,C_fix(1));
t1=t12;
t2=t13;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* map-loop1835 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in ... */
static void C_fcall f_6975(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_6975,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7000,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_a_i_list(&a,2,lf[317],t4);
/* batch-driver.scm:643: chicken.compiler.core#canonicalize-expression */
t6=*((C_word*)lf[156]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t3;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6998 in map-loop1835 in k5961 in k5946 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in ... */
static void C_ccall f_7000(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7000,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6975(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1793 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in ... */
static void C_fcall f_7009(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7009,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7034,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:633: g1799 */
t4=((C_word*)t0)[4];
f_5916(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7032 in map-loop1793 in k5940 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in ... */
static void C_ccall f_7034(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7034,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7009(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7057 in k5937 in k5910 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in ... */
static void C_ccall f_7059(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_7059,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
t4=C_a_i_cons(&a,2,lf[320],t3);
t5=((C_word*)t0)[3];
f_5942(t5,C_a_i_list(&a,1,t4));}

/* map-loop1766 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in ... */
static void C_fcall f_7065(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7065,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7090,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:632: g1772 */
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

/* k7088 in map-loop1766 in k5901 in k5898 in k5895 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in ... */
static void C_ccall f_7090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7090,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7065(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7098 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7100(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_7100,c,av);}
a=C_alloc(17);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=((C_word*)((C_word*)t0)[2])[1];
t7=C_i_check_list_2(t6,lf[5]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7110,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7112,a[2]=t4,a[3]=t10,a[4]=((C_word*)t0)[4],a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_7112(t12,t8,t6);}

/* k7108 in k7098 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in ... */
static void C_ccall f_7110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7110,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_5897(t3,t2);}

/* map-loop1738 in k7098 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in ... */
static void C_fcall f_7112(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7112,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7137,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:627: g1744 */
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

/* k7135 in map-loop1738 in k7098 in k5892 in k5889 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in ... */
static void C_ccall f_7137(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7137,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7112(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7145 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in ... */
static void C_ccall f_7147(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_7147,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7151,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:603: proc */
t3=((C_word*)t0)[4];{
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
av2[4]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k7149 in k7145 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in ... */
static void C_ccall f_7151(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7151,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_5891(2,av2);}}

/* doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in ... */
static void C_fcall f_7156(C_word t0,C_word t1,C_word t2){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,0,3)))){
C_save_and_reclaim_args((void *)trf_7156,3,t0,t1,t2);}
a=C_alloc(22);
if(C_truep(C_i_nullp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7167,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=*((C_word*)lf[327]+1);
t9=C_i_check_list_2(((C_word*)t0)[3],lf[5]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7177,a[2]=((C_word*)t0)[4],a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7227,a[2]=t6,a[3]=t12,a[4]=t8,a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_7227(t14,t10,((C_word*)t0)[3]);}
else{
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7265,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=t1,a[5]=t2,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:612: chicken.compiler.support#check-and-open-input-file */
t5=*((C_word*)lf[331]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k7165 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in ... */
static void C_ccall f_7167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7167,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k7175 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in ... */
static void C_ccall f_7177(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7177,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7181,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:609: scheme#reverse */
t3=*((C_word*)lf[328]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7179 in k7175 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7181(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_7181,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=*((C_word*)lf[327]+1);
t7=C_i_check_list_2(((C_word*)t0)[2],lf[5]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7191,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7193,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_7193(t12,t8,((C_word*)t0)[2]);}

/* k7189 in k7179 in k7175 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in ... */
static void C_ccall f_7191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7191,c,av);}
/* batch-driver.scm:608: scheme#append */
t2=*((C_word*)lf[4]+1);{
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

/* map-loop1689 in k7179 in k7175 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in ... */
static void C_fcall f_7193(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7193,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7218,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:610: g1695 */
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

/* k7216 in map-loop1689 in k7179 in k7175 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in ... */
static void C_ccall f_7218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7218,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7193(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1663 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in ... */
static void C_fcall f_7227(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7227,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7252,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:608: g1669 */
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

/* k7250 in map-loop1663 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7252(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7252,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7227(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in ... */
static void C_ccall f_7265(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_7265,c,av);}
a=C_alloc(22);
t2=((C_word*)t0)[2];
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_FALSE;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7268,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7275,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7280,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7308,a[2]=t3,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:613: ##sys#dynamic-wind */
t10=*((C_word*)lf[158]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t10;
av2[1]=t6;
av2[2]=t7;
av2[3]=t8;
av2[4]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}

/* k7266 in k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7268(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7268,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7156(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* a7274 in k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7275,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[157]+1));
t3=C_mutate((C_word*)lf[157]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a7279 in k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7280,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7286,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t3,tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_7286(t5,t1);}

/* loop in a7279 in k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in ... */
static void C_fcall f_7286(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_7286,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7290,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:615: chicken.syntax#read-with-source-info */
t3=*((C_word*)lf[330]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7288 in loop in a7279 in k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in ... */
static void C_ccall f_7290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7290,c,av);}
a=C_alloc(3);
if(C_truep(C_eofp(t1))){
/* batch-driver.scm:618: chicken.compiler.support#close-checked-input-file */
t2=*((C_word*)lf[329]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_a_i_cons(&a,2,t1,((C_word*)((C_word*)t0)[5])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[5])+1,t2);
/* batch-driver.scm:621: loop */
t4=((C_word*)((C_word*)t0)[6])[1];
f_7286(t4,((C_word*)t0)[2]);}}

/* a7307 in k7263 in doloop1658 in k5886 in k5883 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in ... */
static void C_ccall f_7308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7308,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[157]+1));
t3=C_mutate((C_word*)lf[157]+1 /* (set! ##sys#current-source-filename ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k7313 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in ... */
static void C_ccall f_7315(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7315,c,av);}
a=C_alloc(8);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7323,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:598: collect-options */
t4=((C_word*)((C_word*)t0)[4])[1];
f_5327(t4,t3,lf[333]);}

/* k7321 in k7313 in k5880 in k5877 in k5874 in k5870 in k5866 in k5863 in k5860 in k5857 in k5854 in k5815 in k5796 in k5793 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in ... */
static void C_ccall f_7323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7323,c,av);}
/* batch-driver.scm:595: scheme#append */
t2=*((C_word*)lf[4]+1);{
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

/* k7339 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in ... */
static void C_ccall f_7341(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_7341,c,av);}
a=C_alloc(5);
t2=C_set_block_item(lf[311] /* chicken.compiler.core#emit-profile */,0,C_SCHEME_TRUE);
t3=C_mutate((C_word*)lf[351]+1 /* (set! chicken.compiler.core#profiled-procedures ...) */,lf[352]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7347,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[3])){
/* batch-driver.scm:557: scheme#append */
t5=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=*((C_word*)lf[356]+1);
av2[4]=lf[357];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
/* batch-driver.scm:557: scheme#append */
t5=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=*((C_word*)lf[356]+1);
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k7345 in k7339 in k5790 in k5787 in k5784 in k5781 in k5770 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in ... */
static void C_ccall f_7347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_7347,c,av);}
a=C_alloc(6);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
if(C_truep(((C_word*)t0)[3])){
t3=C_a_i_list(&a,1,lf[353]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9539,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[354];
av2[4]=t3;
C_apply(5,av2);}}
else{
t3=C_a_i_list(&a,1,lf[355]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9545,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[183]+1);
av2[3]=lf[354];
av2[4]=t3;
C_apply(5,av2);}}}

/* k7394 in k5766 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in ... */
static void C_ccall f_7396(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7396,c,av);}
/* batch-driver.scm:535: arg-val */
f_5242(((C_word*)t0)[3],t1);}

/* k7401 in k5762 in k5759 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in ... */
static void C_ccall f_7403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7403,c,av);}
/* batch-driver.scm:532: arg-val */
f_5242(((C_word*)t0)[3],t1);}

/* k7417 in map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in ... */
static void C_ccall f_7419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_7419,c,av);}
a=C_alloc(9);
t2=C_a_i_list(&a,2,lf[369],t1);
t3=C_a_i_cons(&a,2,t2,C_SCHEME_END_OF_LIST);
t4=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t3);
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t6=((C_word*)((C_word*)t0)[3])[1];
f_7430(t6,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in ... */
static void C_ccall f_7422(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_7422,c,av);}
a=C_alloc(11);
t2=C_i_check_list_2(t1,lf[5]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7428,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7430,a[2]=((C_word*)t0)[4],a[3]=t5,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_7430(t7,t3,t1);}

/* k7426 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in ... */
static void C_ccall f_7428(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7428,c,av);}
/* batch-driver.scm:523: scheme#append */
t2=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop1599 in k7420 in k5755 in k5751 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in ... */
static void C_fcall f_7430(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_7430,3,t0,t1,t2);}
a=C_alloc(15);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7419,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5175,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=C_i_string_length(t3);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5127,a[2]=t3,a[3]=t8,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_5127(t10,t5,C_fix(0),t6);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* a7463 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in ... */
static void C_ccall f_7464(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7464,c,av);}
a=C_alloc(10);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7471,a[2]=t5,a[3]=t6,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:517: chicken.string#string-split */
t8=*((C_word*)lf[379]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
av2[3]=lf[380];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k7469 in a7463 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in ... */
static void C_ccall f_7471(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7471,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7476,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_7476(t5,((C_word*)t0)[4],t1);}

/* map-loop1573 in k7469 in a7463 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in ... */
static void C_fcall f_7476(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7476,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7501,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:517: g1579 */
t4=*((C_word*)lf[321]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7499 in map-loop1573 in k7469 in a7463 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in ... */
static void C_ccall f_7501(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7501,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7476(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7510 in k5748 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in ... */
static void C_ccall f_7512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7512,c,av);}
/* batch-driver.scm:516: append-map */
f_2956(((C_word*)t0)[2],((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* k7517 in k5745 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in ... */
static void C_ccall f_7519(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7519,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_5750(t3,t2);}

/* a7532 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in ... */
static void C_ccall f_7533(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7533,c,av);}
a=C_alloc(10);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7540,a[2]=t5,a[3]=t6,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:509: chicken.string#string-split */
t8=*((C_word*)lf[379]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
av2[3]=lf[383];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k7538 in a7532 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in ... */
static void C_ccall f_7540(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7540,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7545,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_7545(t5,((C_word*)t0)[4],t1);}

/* map-loop1542 in k7538 in a7532 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in ... */
static void C_fcall f_7545(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7545,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7570,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* batch-driver.scm:509: g1548 */
t4=*((C_word*)lf[321]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7568 in map-loop1542 in k7538 in a7532 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in ... */
static void C_ccall f_7570(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7570,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7545(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7579 in k5742 in k5734 in k5730 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in ... */
static void C_ccall f_7581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7581,c,av);}
/* batch-driver.scm:508: append-map */
f_2956(((C_word*)t0)[2],((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* for-each-loop1519 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in ... */
static void C_fcall f_7583(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_7583,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7593,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5714,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:499: ##sys#resolve-include-filename */
t6=*((C_word*)lf[277]+1);{
C_word av2[6];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_TRUE;
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(6,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7591 in for-each-loop1519 in k5707 in k5704 in k5697 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in ... */
static void C_ccall f_7593(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7593,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7583(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1133 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in ... */
static void C_fcall f_7606(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7606,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7616,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:489: g1134 */
t4=((C_word*)t0)[3];{
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

/* k7614 in for-each-loop1133 in k5691 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in ... */
static void C_ccall f_7616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7616,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7606(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* a7628 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in ... */
static void C_ccall f_7629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7629,c,av);}
t3=*((C_word*)lf[379]+1);
/* batch-driver.scm:491: g1509 */
t4=*((C_word*)lf[379]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[389];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k7635 in k5688 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in ... */
static void C_ccall f_7637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7637,c,av);}
/* batch-driver.scm:491: append-map */
f_2956(((C_word*)t0)[2],((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* for-each-loop1123 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in ... */
static void C_fcall f_7639(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7639,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7649,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* batch-driver.scm:486: g1124 */
t4=((C_word*)t0)[3];{
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

/* k7647 in for-each-loop1123 in k5682 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in ... */
static void C_ccall f_7649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7649,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7639(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* a7661 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in ... */
static void C_ccall f_7662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7662,c,av);}
t3=*((C_word*)lf[379]+1);
/* batch-driver.scm:488: g1494 */
t4=*((C_word*)lf[379]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[391];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k7668 in k5679 in k5676 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in ... */
static void C_ccall f_7670(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7670,c,av);}
/* batch-driver.scm:488: append-map */
f_2956(((C_word*)t0)[2],((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* k7681 in for-each-loop1449 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_7683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7683,c,av);}
/* batch-driver.scm:476: chicken.compiler.support#mark-variable */
t2=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[395];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k7690 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_ccall f_7692(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7692,c,av);}
a=C_alloc(5);
t2=*((C_word*)lf[78]+1);
t3=C_i_check_list_2(*((C_word*)lf[78]+1),lf[10]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7708,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_7708(t7,((C_word*)t0)[2],*((C_word*)lf[78]+1));}

/* k7695 in for-each-loop1468 in k7690 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in ... */
static void C_ccall f_7697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7697,c,av);}
/* batch-driver.scm:481: chicken.compiler.support#mark-variable */
t2=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[395];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* for-each-loop1468 in k7690 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in ... */
static void C_fcall f_7708(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_7708,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7718,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7697,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:480: chicken.compiler.support#mark-variable */
t6=*((C_word*)lf[13]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=lf[396];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7716 in for-each-loop1468 in k7690 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in ... */
static void C_ccall f_7718(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7718,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7708(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1449 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in ... */
static void C_fcall f_7731(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_7731,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7741,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7683,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:475: chicken.compiler.support#mark-variable */
t6=*((C_word*)lf[13]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
av2[3]=lf[396];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k7739 in for-each-loop1449 in k5673 in k5670 in k5667 in k5664 in k5661 in k5658 in k5655 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in ... */
static void C_ccall f_7741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7741,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7731(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k7784 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_7786(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7786,c,av);}
a=C_alloc(10);
t2=C_i_check_list_2(t1,lf[5]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7792,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7794,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_7794(t7,t3,t1);}

/* k7790 in k7784 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_7792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7792,c,av);}
/* batch-driver.scm:458: scheme#append */
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
av2[3]=*((C_word*)lf[131]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop1421 in k7784 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_fcall f_7794(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,0,4)))){
C_save_and_reclaim_args((void *)trf_7794,3,t0,t1,t2);}
a=C_alloc(17);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7804,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7819,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_slot(t2,C_fix(0));
t6=C_i_string_length(t5);
t7=C_a_i_fixnum_difference(&a,2,t6,C_fix(1));
if(C_truep(C_i_integer_greaterp(t7,C_fix(0)))){
t8=C_i_string_ref(t5,t7);
if(C_truep((C_truep(C_eqp(t8,C_make_character(92)))?C_SCHEME_TRUE:(C_truep(C_eqp(t8,C_make_character(47)))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
/* batch-driver.scm:343: scheme#substring */
t9=*((C_word*)lf[112]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t4;
av2[2]=t5;
av2[3]=C_fix(0);
av2[4]=t7;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t9=t3;
f_7804(t9,C_a_i_cons(&a,2,t5,C_SCHEME_END_OF_LIST));}}
else{
t8=t3;
f_7804(t8,C_a_i_cons(&a,2,t5,C_SCHEME_END_OF_LIST));}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7802 in map-loop1421 in k7784 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_fcall f_7804(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_7804,2,t0,t1);}
t2=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t1);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t4=((C_word*)((C_word*)t0)[3])[1];
f_7794(t4,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7817 in map-loop1421 in k7784 in k5650 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_7819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7819,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_7804(t2,C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST));}

/* k7829 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in ... */
static void C_ccall f_7831(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7831,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7834,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:452: chicken.base#case-sensitive */
t3=*((C_word*)lf[414]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7832 in k7829 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in ... */
static void C_ccall f_7834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7834,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7837,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:453: chicken.base#keyword-style */
t3=*((C_word*)lf[412]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[413];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7835 in k7832 in k7829 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in ... */
static void C_ccall f_7837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7837,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7840,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:454: chicken.base#parentheses-synonyms */
t3=*((C_word*)lf[411]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7838 in k7835 in k7832 in k7829 in k5647 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in ... */
static void C_ccall f_7840(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7840,c,av);}
/* batch-driver.scm:455: chicken.base#symbol-escape */
t2=*((C_word*)lf[410]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k7846 in k5644 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in ... */
static void C_ccall f_7848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7848,c,av);}
/* batch-driver.scm:449: chicken.base#symbol-escape */
t2=*((C_word*)lf[410]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k7854 in k5641 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in ... */
static void C_ccall f_7856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7856,c,av);}
/* batch-driver.scm:446: chicken.base#parentheses-synonyms */
t2=*((C_word*)lf[411]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k7860 in k5638 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in ... */
static void C_ccall f_7862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7862,c,av);}
if(C_truep(C_i_string_equal_p(lf[420],t1))){
/* batch-driver.scm:439: chicken.base#keyword-style */
t2=*((C_word*)lf[412]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[421];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(lf[422],t1))){
/* batch-driver.scm:440: chicken.base#keyword-style */
t2=*((C_word*)lf[412]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[413];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
if(C_truep(C_u_i_string_equal_p(lf[423],t1))){
/* batch-driver.scm:441: chicken.base#keyword-style */
t2=*((C_word*)lf[412]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[424];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
/* batch-driver.scm:442: chicken.compiler.support#quit-compiling */
t2=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[425];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}}}

/* k7893 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in ... */
static void C_ccall f_7895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7895,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7898,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:435: chicken.platform#register-feature! */
t3=*((C_word*)lf[132]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[426];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7896 in k7893 in k5635 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in ... */
static void C_ccall f_7898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7898,c,av);}
/* batch-driver.scm:436: chicken.base#case-sensitive */
t2=*((C_word*)lf[414]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k7903 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in ... */
static void C_ccall f_7905(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7905,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7908,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:430: scheme#string->number */
t3=*((C_word*)lf[111]+1);{
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

/* k7906 in k7903 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in ... */
static void C_ccall f_7908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7908,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7911,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=C_mutate((C_word*)lf[169]+1 /* (set! chicken.compiler.core#unroll-limit ...) */,t1);
t4=((C_word*)t0)[2];
f_5637(t4,t3);}
else{
/* batch-driver.scm:431: chicken.compiler.support#quit-compiling */
t3=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[428];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k7909 in k7906 in k7903 in k5630 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in ... */
static void C_ccall f_7911(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7911,c,av);}
t2=C_mutate((C_word*)lf[169]+1 /* (set! chicken.compiler.core#unroll-limit ...) */,t1);
t3=((C_word*)t0)[2];
f_5637(t3,t2);}

/* k7916 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in ... */
static void C_ccall f_7918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7918,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7921,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* batch-driver.scm:424: scheme#string->number */
t3=*((C_word*)lf[111]+1);{
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

/* k7919 in k7916 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in ... */
static void C_ccall f_7921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7921,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7924,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=C_mutate((C_word*)lf[168]+1 /* (set! chicken.compiler.core#inline-max-size ...) */,t1);
t4=((C_word*)t0)[2];
f_5632(t4,t3);}
else{
/* batch-driver.scm:425: chicken.compiler.support#quit-compiling */
t3=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[429];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k7922 in k7919 in k7916 in k5625 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in ... */
static void C_ccall f_7924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7924,c,av);}
t2=C_mutate((C_word*)lf[168]+1 /* (set! chicken.compiler.core#inline-max-size ...) */,t1);
t3=((C_word*)t0)[2];
f_5632(t3,t2);}

/* k7929 in k5620 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in ... */
static void C_ccall f_7931(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7931,c,av);}
t2=C_mutate((C_word*)lf[236]+1 /* (set! chicken.compiler.core#types-output-file ...) */,t1);
t3=((C_word*)t0)[2];
f_5627(t3,t2);}

/* k7935 in k5615 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in ... */
static void C_ccall f_7937(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7937,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_5622(t3,t2);}

/* k7939 in k5610 in k5607 in k5604 in k5601 in k5598 in k5595 in k5592 in k5589 in k5586 in k5583 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in ... */
static void C_ccall f_7941(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7941,c,av);}
t2=C_mutate((C_word*)lf[194]+1 /* (set! chicken.compiler.core#emit-link-file ...) */,t1);
t3=((C_word*)t0)[2];
f_5617(t3,t2);}

/* k7971 in k5580 in k5577 in k5574 in k5571 in k5568 in k5565 in k5562 in k5559 in k5556 in k5553 in k5550 in k5547 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in ... */
static void C_ccall f_7973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7973,c,av);}
t2=C_set_block_item(lf[202] /* ##sys#warnings-enabled */,0,C_SCHEME_FALSE);
t3=C_set_block_item(((C_word*)t0)[2],0,C_SCHEME_FALSE);
t4=((C_word*)t0)[3];
f_5585(t4,t3);}

/* map-loop1352 in k5541 in k5515 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in ... */
static void C_fcall f_8024(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_8024,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5534,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* batch-driver.scm:366: scheme#string->symbol */
t5=*((C_word*)lf[321]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8060 in k5512 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_8062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8062,c,av);}
/* batch-driver.scm:362: chicken.base#exit */
t2=*((C_word*)lf[199]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a8066 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_8067(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_8067,c,av);}
a=C_alloc(10);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8083,a[2]=t5,a[3]=t6,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* ##sys#string->list */
t8=*((C_word*)lf[466]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* k8081 in a8066 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in ... */
static void C_ccall f_8083(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_8083,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8088,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_8088(t5,((C_word*)t0)[4],t1);}

/* map-loop1324 in k8081 in a8066 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in ... */
static void C_fcall f_8088(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_8088,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8113,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_a_i_string(&a,1,t4);
/* batch-driver.scm:357: scheme#string->symbol */
t6=*((C_word*)lf[321]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t3;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8111 in map-loop1324 in k8081 in a8066 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in ... */
static void C_ccall f_8113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8113,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8088(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k8122 in k5505 in k5502 in k5499 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in ... */
static void C_ccall f_8124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8124,c,av);}
/* batch-driver.scm:355: append-map */
f_2956(((C_word*)t0)[2],((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* k8136 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_ccall f_8138(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8138,c,av);}
t2=C_mutate((C_word*)lf[312]+1 /* (set! chicken.compiler.core#unit-name ...) */,t1);
t3=((C_word*)t0)[2];
f_5501(t3,t2);}

/* k8140 in k4975 in k4950 in k4945 in k4942 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in ... */
static void C_ccall f_8142(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8142,c,av);}
/* batch-driver.scm:347: scheme#string->symbol */
t2=*((C_word*)lf[321]+1);{
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

/* g1072 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in ... */
static void C_fcall f_8158(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_8158,3,t0,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8162,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* batch-driver.scm:224: option-arg */
f_4883(t3,t2);}

/* k8160 in g1072 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in ... */
static void C_ccall f_8162(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8162,c,av);}
if(C_truep(C_i_symbolp(t1))){
/* batch-driver.scm:226: scheme#symbol->string */
t2=*((C_word*)lf[266]+1);{
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
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k8184 in k4937 in k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in ... */
static void C_ccall f_8186(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8186,c,av);}
/* batch-driver.scm:229: chicken.pathname#make-pathname */
t2=*((C_word*)lf[264]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
av2[3]=t1;
av2[4]=lf[472];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k8210 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in ... */
static void C_ccall f_8212(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,c,2)))){
C_save_and_reclaim((void *)f_8212,c,av);}
a=C_alloc(30);
t2=C_a_i_cons(&a,2,lf[89],t1);
t3=C_a_i_list(&a,1,t2);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_4939,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t5,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t7=C_a_i_cons(&a,2,lf[475],*((C_word*)lf[476]+1));
if(C_truep(*((C_word*)lf[83]+1))){
t8=t6;
f_4939(t8,C_a_i_cons(&a,2,t7,C_SCHEME_END_OF_LIST));}
else{
t8=C_a_i_cons(&a,2,lf[477],*((C_word*)lf[478]+1));
t9=C_a_i_list(&a,1,t8);
t10=t6;
f_4939(t10,C_a_i_cons(&a,2,t7,t9));}}

/* k8218 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in ... */
static void C_fcall f_8220(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8220,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8227,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[482]+1))){
if(C_truep(C_i_not(((C_word*)t0)[4]))){
if(C_truep(C_i_not(((C_word*)t0)[5]))){
if(C_truep(C_i_not(*((C_word*)lf[83]+1)))){
t3=C_i_not(*((C_word*)lf[483]+1));
t4=t2;
f_8227(t4,(C_truep(t3)?t3:C_eqp(*((C_word*)lf[483]+1),lf[484])));}
else{
t3=t2;
f_8227(t3,C_SCHEME_FALSE);}}
else{
t3=t2;
f_8227(t3,C_SCHEME_FALSE);}}
else{
t3=t2;
f_8227(t3,C_SCHEME_FALSE);}}
else{
t3=t2;
f_8227(t3,C_SCHEME_FALSE);}}

/* k8225 in k8218 in k4927 in k4924 in k4921 in k4912 in chicken.compiler.batch-driver#compile-source-file in k2753 in k2750 in k2747 in k2744 in k2741 in k2738 in k2735 in k2732 in k2729 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in ... */
static void C_fcall f_8227(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,5)))){
C_save_and_reclaim_args((void *)trf_8227,2,t0,t1);}
if(C_truep(t1)){
/* batch-driver.scm:201: scheme#append */
t2=*((C_word*)lf[4]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[480]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=lf[481];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
/* batch-driver.scm:201: scheme#append */
t2=*((C_word*)lf[4]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[480]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_batch_2ddriver_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("batch-driver"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_batch_2ddriver_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(3146))){
C_save(t1);
C_rereclaim2(3146*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,492);
lf[0]=C_h_intern(&lf[0],12, C_text("batch-driver"));
lf[1]=C_h_intern(&lf[1],30, C_text("chicken.compiler.batch-driver#"));
lf[3]=C_h_intern(&lf[3],5, C_text("foldr"));
lf[4]=C_h_intern(&lf[4],13, C_text("scheme#append"));
lf[5]=C_h_intern(&lf[5],3, C_text("map"));
lf[7]=C_h_intern(&lf[7],12, C_text("scheme#null\077"));
lf[9]=C_h_intern(&lf[9],39, C_text("chicken.compiler.core#standard-bindings"));
lf[10]=C_h_intern(&lf[10],8, C_text("for-each"));
lf[11]=C_h_intern(&lf[11],39, C_text("chicken.compiler.core#extended-bindings"));
lf[12]=C_h_intern(&lf[12],39, C_text("chicken.compiler.core#internal-bindings"));
lf[13]=C_h_intern(&lf[13],38, C_text("chicken.compiler.support#mark-variable"));
lf[14]=C_h_intern(&lf[14],20, C_text("##compiler#intrinsic"));
lf[15]=C_h_intern(&lf[15],8, C_text("internal"));
lf[16]=C_h_intern(&lf[16],8, C_text("extended"));
lf[17]=C_h_intern(&lf[17],8, C_text("standard"));
lf[19]=C_h_intern(&lf[19],14, C_text("scheme#newline"));
lf[20]=C_h_intern(&lf[20],21, C_text("##sys#standard-output"));
lf[21]=C_h_intern(&lf[21],6, C_text("printf"));
lf[22]=C_h_intern(&lf[22],11, C_text("##sys#print"));
lf[23]=C_h_intern(&lf[23],40, C_text("chicken.compiler.support#node-parameters"));
lf[24]=C_h_intern(&lf[24],35, C_text("chicken.compiler.support#node-class"));
lf[25]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006\011pval="));
lf[26]=C_h_intern(&lf[26],7, C_text("unknown"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005\011val="));
lf[28]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006\011lval="));
lf[29]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005\011css="));
lf[30]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010\011drvars="));
lf[31]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006\011refs="));
lf[32]=C_h_intern(&lf[32],8, C_text("captured"));
lf[33]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001captured\376\001\000\000\003\001cpt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001assigned\376\001\000\000\003\001set\376\003\000\000\002\376\003\000\000\002\376\001\000\000"
"\005\001boxed\376\001\000\000\003\001box\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001global\376\001\000\000\003\001glo\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001assigned-locally\376"
"\001\000\000\003\001stl\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001contractable\376\001\000\000\003\001con\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001standard-binding\376\001\000"
"\000\003\001stb\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001simple\376\001\000\000\003\001sim\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001inlinable\376\001\000\000\003\001inl\376\003\000\000\002\376\003\000\000"
"\002\376\001\000\000\013\001collapsable\376\001\000\000\003\001col\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001removable\376\001\000\000\003\001rem\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001con"
"stant\376\001\000\000\003\001con\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001inline-target\376\001\000\000\003\001ilt\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001inline-trans"
"ient\376\001\000\000\003\001itr\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001undefined\376\001\000\000\003\001und\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001replacing\376\001\000\000\003\001rp"
"g\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001unused\376\001\000\000\003\001uud\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001extended-binding\376\001\000\000\003\001xtb\376\003\000\000\002\376\003"
"\000\000\002\376\001\000\000\015\001inline-export\376\001\000\000\003\001ilx\376\003\000\000\002\376\003\000\000\002\376\001\000\000\013\001hidden-refs\376\001\000\000\003\001hrf\376\003\000\000\002\376\003\000\000\002\376\001\000"
"\000\011\001value-ref\376\001\000\000\003\001vvf\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001customizable\376\001\000\000\003\001cst\376\003\000\000\002\376\003\000\000\002\376\001\000\000\025\001has-un"
"used-parameters\376\001\000\000\003\001hup\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001boxed-rest\376\001\000\000\003\001bxr\376\377\016"));
lf[34]=C_h_intern(&lf[34],18, C_text("##sys#write-char-0"));
lf[35]=C_h_intern(&lf[35],5, C_text("value"));
lf[36]=C_h_intern(&lf[36],11, C_text("local-value"));
lf[37]=C_h_intern(&lf[37],16, C_text("potential-values"));
lf[38]=C_h_intern(&lf[38],10, C_text("replacable"));
lf[39]=C_h_intern(&lf[39],17, C_text("derived-rest-vars"));
lf[40]=C_h_intern(&lf[40],10, C_text("references"));
lf[41]=C_h_intern(&lf[41],10, C_text("call-sites"));
lf[42]=C_h_intern(&lf[42],29, C_text("chicken.compiler.support#bomb"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020Illegal property"));
lf[44]=C_h_intern(&lf[44],4, C_text("home"));
lf[45]=C_h_intern(&lf[45],8, C_text("contains"));
lf[46]=C_h_intern(&lf[46],12, C_text("contained-in"));
lf[47]=C_h_intern(&lf[47],8, C_text("use-expr"));
lf[48]=C_h_intern(&lf[48],12, C_text("closure-size"));
lf[49]=C_h_intern(&lf[49],14, C_text("rest-parameter"));
lf[50]=C_h_intern(&lf[50],18, C_text("captured-variables"));
lf[51]=C_h_intern(&lf[51],13, C_text("explicit-rest"));
lf[52]=C_h_intern(&lf[52],8, C_text("rest-cdr"));
lf[53]=C_h_intern(&lf[53],10, C_text("rest-null\077"));
lf[54]=C_h_intern(&lf[54],15, C_text("consed-rest-arg"));
lf[55]=C_h_intern(&lf[55],8, C_text("assigned"));
lf[56]=C_h_intern(&lf[56],5, C_text("boxed"));
lf[57]=C_h_intern(&lf[57],6, C_text("global"));
lf[58]=C_h_intern(&lf[58],12, C_text("contractable"));
lf[59]=C_h_intern(&lf[59],16, C_text("standard-binding"));
lf[60]=C_h_intern(&lf[60],16, C_text("assigned-locally"));
lf[61]=C_h_intern(&lf[61],11, C_text("collapsable"));
lf[62]=C_h_intern(&lf[62],9, C_text("removable"));
lf[63]=C_h_intern(&lf[63],9, C_text("undefined"));
lf[64]=C_h_intern(&lf[64],9, C_text("replacing"));
lf[65]=C_h_intern(&lf[65],6, C_text("unused"));
lf[66]=C_h_intern(&lf[66],6, C_text("simple"));
lf[67]=C_h_intern(&lf[67],9, C_text("inlinable"));
lf[68]=C_h_intern(&lf[68],13, C_text("inline-export"));
lf[69]=C_h_intern(&lf[69],21, C_text("has-unused-parameters"));
lf[70]=C_h_intern(&lf[70],16, C_text("extended-binding"));
lf[71]=C_h_intern(&lf[71],12, C_text("customizable"));
lf[72]=C_h_intern(&lf[72],8, C_text("constant"));
lf[73]=C_h_intern(&lf[73],10, C_text("boxed-rest"));
lf[74]=C_h_intern(&lf[74],11, C_text("hidden-refs"));
lf[75]=C_h_intern(&lf[75],12, C_text("scheme#write"));
lf[76]=C_h_intern(&lf[76],36, C_text("chicken.internal#hash-table-for-each"));
lf[77]=C_h_intern(&lf[77],47, C_text("chicken.compiler.core#default-standard-bindings"));
lf[78]=C_h_intern(&lf[78],47, C_text("chicken.compiler.core#default-extended-bindings"));
lf[79]=C_h_intern(&lf[79],49, C_text("chicken.compiler.batch-driver#compile-source-file"));
lf[80]=C_h_intern(&lf[80],39, C_text("chicken.compiler.support#quit-compiling"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000 missing argument to `-~A\047 option"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037invalid argument to `~A\047 option"));
lf[83]=C_h_intern(&lf[83],39, C_text("chicken.compiler.core#explicit-use-flag"));
lf[84]=C_h_intern(&lf[84],12, C_text("explicit-use"));
lf[85]=C_h_intern(&lf[85],37, C_text("chicken.compiler.core#emit-debug-info"));
lf[86]=C_h_intern(&lf[86],10, C_text("debug-info"));
lf[87]=C_h_intern(&lf[87],7, C_text("dynamic"));
lf[88]=C_h_intern(&lf[88],4, C_text("unit"));
lf[89]=C_h_intern(&lf[89],14, C_text("##core#declare"));
lf[90]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\003\000\000\002\376\001\000\000\042\001chicken.base#implicit-exit-handler\376\377\016\376\377\016\376\377\016"));
lf[91]=C_h_intern(&lf[91],11, C_text("output-file"));
lf[92]=C_h_intern(&lf[92],7, C_text("profile"));
lf[93]=C_h_intern(&lf[93],12, C_text("profile-name"));
lf[94]=C_h_intern(&lf[94],9, C_text("heap-size"));
lf[95]=C_h_intern(&lf[95],13, C_text("keyword-style"));
lf[96]=C_h_intern(&lf[96],10, C_text("clustering"));
lf[97]=C_h_intern(&lf[97],12, C_text("analyze-only"));
lf[98]=C_h_intern(&lf[98],4, C_text("lfa2"));
lf[99]=C_h_intern(&lf[99],7, C_text("nursery"));
lf[100]=C_h_intern(&lf[100],10, C_text("stack-size"));
lf[101]=C_h_intern(&lf[101],6, C_text("module"));
lf[102]=C_h_intern(&lf[102],42, C_text("chicken.compiler.support#debugging-chicken"));
lf[103]=C_h_intern(&lf[103],34, C_text("chicken.compiler.support#debugging"));
lf[104]=C_h_intern(&lf[104],1, C_text("p"));
lf[105]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004pass"));
lf[106]=C_h_intern(&lf[106],35, C_text("chicken.compiler.support#dump-nodes"));
lf[107]=C_h_intern(&lf[107],33, C_text("chicken.pretty-print#pretty-print"));
lf[108]=C_h_intern(&lf[108],46, C_text("chicken.compiler.support#build-expression-tree"));
lf[109]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013(iteration "));
lf[110]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033invalid numeric argument ~S"));
lf[111]=C_h_intern(&lf[111],21, C_text("scheme#string->number"));
lf[112]=C_h_intern(&lf[112],16, C_text("scheme#substring"));
lf[113]=C_h_intern(&lf[113],41, C_text("chicken.time#current-process-milliseconds"));
lf[114]=C_h_intern(&lf[114],21, C_text("scheme#inexact->exact"));
lf[115]=C_h_intern(&lf[115],12, C_text("scheme#round"));
lf[116]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003: \011"));
lf[117]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030milliseconds needed for "));
lf[118]=C_h_intern(&lf[118],31, C_text("chicken.compiler.support#db-get"));
lf[119]=C_h_intern(&lf[119],32, C_text("chicken.compiler.support#db-put!"));
lf[120]=C_h_intern(&lf[120],40, C_text("chicken.compiler.core#analyze-expression"));
lf[121]=C_h_intern(&lf[121],43, C_text("chicken.compiler.core#enable-specialization"));
lf[122]=C_h_intern(&lf[122],10, C_text("specialize"));
lf[123]=C_h_intern(&lf[123],1, C_text("D"));
lf[124]=C_h_intern(&lf[124],38, C_text("chicken.compiler.core#import-libraries"));
lf[125]=C_h_intern(&lf[125],14, C_text("emit-link-file"));
lf[126]=C_h_intern(&lf[126],16, C_text("emit-inline-file"));
lf[127]=C_h_intern(&lf[127],15, C_text("emit-types-file"));
lf[128]=C_h_intern(&lf[128],12, C_text("inline-limit"));
lf[129]=C_h_intern(&lf[129],12, C_text("unroll-limit"));
lf[130]=C_h_intern(&lf[130],33, C_text("##sys#read-error-with-line-number"));
lf[131]=C_h_intern(&lf[131],23, C_text("##sys#include-pathnames"));
lf[132]=C_h_intern(&lf[132],34, C_text("chicken.platform#register-feature!"));
lf[133]=C_h_intern(&lf[133],36, C_text("chicken.platform#unregister-feature!"));
lf[134]=C_h_intern_kw(&lf[134],18, C_text("compiler-extension"));
lf[135]=C_h_intern(&lf[135],14, C_text("##sys#features"));
lf[136]=C_h_intern_kw(&lf[136],9, C_text("compiling"));
lf[137]=C_h_intern(&lf[137],38, C_text("chicken.compiler.core#linked-libraries"));
lf[138]=C_h_intern(&lf[138],38, C_text("chicken.compiler.core#target-heap-size"));
lf[139]=C_h_intern(&lf[139],39, C_text("chicken.compiler.core#target-stack-size"));
lf[140]=C_h_intern(&lf[140],8, C_text("no-trace"));
lf[141]=C_h_intern(&lf[141],37, C_text("chicken.compiler.core#emit-trace-info"));
lf[142]=C_h_intern(&lf[142],53, C_text("chicken.compiler.core#disable-stack-overflow-checking"));
lf[143]=C_h_intern(&lf[143],29, C_text("disable-stack-overflow-checks"));
lf[144]=C_h_intern(&lf[144],36, C_text("chicken.compiler.core#bootstrap-mode"));
lf[145]=C_h_intern(&lf[145],7, C_text("version"));
lf[146]=C_h_intern(&lf[146],38, C_text("chicken.compiler.support#print-version"));
lf[147]=C_h_intern(&lf[147],4, C_text("help"));
lf[148]=C_h_intern(&lf[148],36, C_text("chicken.compiler.support#print-usage"));
lf[149]=C_h_intern(&lf[149],7, C_text("release"));
lf[150]=C_h_intern(&lf[150],14, C_text("scheme#display"));
lf[151]=C_h_intern(&lf[151],32, C_text("chicken.platform#chicken-version"));
lf[152]=C_decode_literal(C_heaptop,C_text("\376B\000\0001\012Run `csi\047 to start the interactive interpreter.\012"));
lf[153]=C_decode_literal(C_heaptop,C_text("\376B\000\000.or try `csc\047 for a more convenient interface.\012"));
lf[154]=C_decode_literal(C_heaptop,C_text("\376B\000\000C\012Enter `chicken -help\047 for information on how to use the compiler,\012"));
lf[155]=C_h_intern(&lf[155],26, C_text("##sys#line-number-database"));
lf[156]=C_h_intern(&lf[156],45, C_text("chicken.compiler.core#canonicalize-expression"));
lf[157]=C_h_intern(&lf[157],29, C_text("##sys#current-source-filename"));
lf[158]=C_h_intern(&lf[158],18, C_text("##sys#dynamic-wind"));
lf[159]=C_h_intern(&lf[159],44, C_text("chicken.compiler.core#line-number-database-2"));
lf[160]=C_h_intern(&lf[160],41, C_text("chicken.compiler.core#required-extensions"));
lf[161]=C_h_intern(&lf[161],36, C_text("chicken.compiler.core#constant-table"));
lf[162]=C_h_intern(&lf[162],34, C_text("chicken.compiler.core#inline-table"));
lf[163]=C_h_intern(&lf[163],36, C_text("chicken.compiler.core#first-analysis"));
lf[164]=C_h_intern(&lf[164],54, C_text("chicken.compiler.optimizer#determine-loop-and-dispatch"));
lf[165]=C_h_intern(&lf[165],59, C_text("chicken.compiler.optimizer#perform-high-level-optimizations"));
lf[166]=C_h_intern(&lf[166],39, C_text("chicken.compiler.core#block-compilation"));
lf[167]=C_h_intern(&lf[167],36, C_text("chicken.compiler.core#inline-locally"));
lf[168]=C_h_intern(&lf[168],37, C_text("chicken.compiler.core#inline-max-size"));
lf[169]=C_h_intern(&lf[169],34, C_text("chicken.compiler.core#unroll-limit"));
lf[170]=C_h_intern(&lf[170],50, C_text("chicken.compiler.core#inline-substitutions-enabled"));
lf[171]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022clustering enabled"));
lf[172]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022rewritings enabled"));
lf[173]=C_h_intern(&lf[173],44, C_text("chicken.compiler.core#optimize-leaf-routines"));
lf[174]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031leaf routine optimization"));
lf[175]=C_h_intern(&lf[175],52, C_text("chicken.compiler.optimizer#transform-direct-lambdas!"));
lf[176]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010analysis"));
lf[177]=C_h_intern(&lf[177],4, C_text("leaf"));
lf[178]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023optimized-iteration"));
lf[179]=C_h_intern(&lf[179],1, C_text("5"));
lf[180]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014optimization"));
lf[181]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021optimization pass"));
lf[182]=C_h_intern(&lf[182],49, C_text("chicken.compiler.core#prepare-for-code-generation"));
lf[183]=C_h_intern(&lf[183],22, C_text("chicken.format#sprintf"));
lf[184]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025compilation finished."));
lf[185]=C_h_intern(&lf[185],46, C_text("chicken.compiler.support#compiler-cleanup-hook"));
lf[186]=C_h_intern(&lf[186],1, C_text("t"));
lf[187]=C_h_intern(&lf[187],19, C_text("##sys#display-times"));
lf[188]=C_h_intern(&lf[188],16, C_text("##sys#stop-timer"));
lf[189]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017code generation"));
lf[190]=C_h_intern(&lf[190],24, C_text("scheme#close-output-port"));
lf[191]=C_h_intern(&lf[191],40, C_text("chicken.compiler.c-backend#generate-code"));
lf[192]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023generating `~A\047 ..."));
lf[193]=C_h_intern(&lf[193],23, C_text("scheme#open-output-file"));
lf[194]=C_h_intern(&lf[194],36, C_text("chicken.compiler.core#emit-link-file"));
lf[195]=C_h_intern(&lf[195],23, C_text("chicken.pretty-print#pp"));
lf[196]=C_h_intern(&lf[196],26, C_text("scheme#with-output-to-file"));
lf[197]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035generating link file `~a\047 ..."));
lf[198]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013preparation"));
lf[199]=C_h_intern(&lf[199],17, C_text("chicken.base#exit"));
lf[200]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021closure-converted"));
lf[201]=C_h_intern(&lf[201],1, C_text("9"));
lf[202]=C_h_intern(&lf[202],22, C_text("##sys#warnings-enabled"));
lf[203]=C_decode_literal(C_heaptop,C_text("\376B\000\000#(don\047t worry - still compiling...)\012"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016final-analysis"));
lf[205]=C_h_intern(&lf[205],1, C_text("8"));
lf[206]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022closure conversion"));
lf[207]=C_h_intern(&lf[207],48, C_text("chicken.compiler.core#perform-closure-conversion"));
lf[208]=C_h_intern(&lf[208],41, C_text("chicken.compiler.core#insert-timer-checks"));
lf[209]=C_h_intern(&lf[209],37, C_text("chicken.compiler.core#foreign-stub-id"));
lf[210]=C_h_intern(&lf[210],42, C_text("chicken.compiler.core#foreign-lambda-stubs"));
lf[211]=C_h_intern(&lf[211],48, C_text("chicken.compiler.support#emit-global-inline-file"));
lf[212]=C_decode_literal(C_heaptop,C_text("\376B\000\000&generating global inline file `~a\047 ..."));
lf[213]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011optimized"));
lf[214]=C_h_intern(&lf[214],1, C_text("7"));
lf[215]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010unboxing"));
lf[216]=C_h_intern(&lf[216],38, C_text("chicken.compiler.lfa2#perform-unboxing"));
lf[217]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016doing unboxing"));
lf[218]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027secondary flow analysis"));
lf[219]=C_h_intern(&lf[219],53, C_text("chicken.compiler.lfa2#perform-secondary-flow-analysis"));
lf[220]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012doing lfa2"));
lf[221]=C_h_intern(&lf[221],1, C_text("s"));
lf[222]=C_h_intern(&lf[222],49, C_text("chicken.compiler.core#compute-database-statistics"));
lf[223]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027;   database entries: \011"));
lf[224]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027;   known call sites: \011"));
lf[225]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027;   global variables: \011"));
lf[226]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027;   known procedures: \011"));
lf[227]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042;   variables with known values: \011"));
lf[228]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032 \011original program size: \011"));
lf[229]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023;   program size: \011"));
lf[230]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023program statistics:"));
lf[231]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010analysis"));
lf[232]=C_h_intern(&lf[232],1, C_text("4"));
lf[233]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010analysis"));
lf[234]=C_h_intern(&lf[234],44, C_text("chicken.compiler.scrutinizer#emit-types-file"));
lf[235]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035generating type file `~a\047 ..."));
lf[236]=C_h_intern(&lf[236],39, C_text("chicken.compiler.core#types-output-file"));
lf[237]=C_h_intern(&lf[237],43, C_text("chicken.pathname#pathname-replace-extension"));
lf[238]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005types"));
lf[239]=C_h_intern(&lf[239],1, C_text("v"));
lf[240]=C_h_intern(&lf[240],41, C_text("chicken.compiler.support#dump-global-refs"));
lf[241]=C_h_intern(&lf[241],1, C_text("d"));
lf[242]=C_h_intern(&lf[242],45, C_text("chicken.compiler.support#dump-defined-globals"));
lf[243]=C_h_intern(&lf[243],1, C_text("u"));
lf[244]=C_h_intern(&lf[244],47, C_text("chicken.compiler.support#dump-undefined-globals"));
lf[245]=C_h_intern(&lf[245],3, C_text("opt"));
lf[246]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003cps"));
lf[247]=C_h_intern(&lf[247],1, C_text("3"));
lf[248]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016cps conversion"));
lf[249]=C_h_intern(&lf[249],44, C_text("chicken.compiler.core#perform-cps-conversion"));
lf[250]=C_h_intern(&lf[250],31, C_text("chicken.compiler.support#unsafe"));
lf[251]=C_h_intern(&lf[251],52, C_text("chicken.compiler.optimizer#scan-toplevel-assignments"));
lf[252]=C_h_intern(&lf[252],44, C_text("chicken.compiler.support#node-subexpressions"));
lf[253]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016specialization"));
lf[254]=C_h_intern(&lf[254],1, C_text("P"));
lf[255]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010scrutiny"));
lf[256]=C_h_intern(&lf[256],39, C_text("chicken.compiler.scrutinizer#scrutinize"));
lf[257]=C_h_intern(&lf[257],43, C_text("chicken.compiler.core#strict-variable-types"));
lf[258]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023performing scrutiny"));
lf[259]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027pre-analysis (scrutiny)"));
lf[260]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010analysis"));
lf[261]=C_h_intern(&lf[261],1, C_text("0"));
lf[262]=C_h_intern(&lf[262],8, C_text("scrutiny"));
lf[263]=C_h_intern(&lf[263],47, C_text("chicken.compiler.scrutinizer#load-type-database"));
lf[264]=C_h_intern(&lf[264],30, C_text("chicken.pathname#make-pathname"));
lf[265]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005types"));
lf[266]=C_h_intern(&lf[266],21, C_text("scheme#symbol->string"));
lf[267]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034type-database `~a\047 not found"));
lf[268]=C_h_intern(&lf[268],18, C_text("consult-types-file"));
lf[269]=C_h_intern(&lf[269],17, C_text("ignore-repository"));
lf[270]=C_decode_literal(C_heaptop,C_text("\376B\000\000\052default type-database `types.db\047 not found"));
lf[271]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010types.db"));
lf[272]=C_h_intern(&lf[272],41, C_text("chicken.compiler.support#load-inline-file"));
lf[273]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032Loading inline file ~a ..."));
lf[274]=C_h_intern(&lf[274],19, C_text("consult-inline-file"));
lf[275]=C_h_intern(&lf[275],41, C_text("chicken.compiler.core#enable-inline-files"));
lf[276]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032Loading inline file ~a ..."));
lf[277]=C_h_intern(&lf[277],30, C_text("##sys#resolve-include-filename"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\007.inline\376\377\016"));
lf[279]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021initial node tree"));
lf[280]=C_h_intern(&lf[280],1, C_text("T"));
lf[281]=C_h_intern(&lf[281],46, C_text("chicken.compiler.core#build-toplevel-procedure"));
lf[282]=C_h_intern(&lf[282],41, C_text("chicken.compiler.support#build-node-graph"));
lf[283]=C_h_intern(&lf[283],48, C_text("chicken.compiler.support#canonicalize-begin-body"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011user pass"));
lf[285]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014User pass..."));
lf[286]=C_h_intern(&lf[286],36, C_text("chicken.compiler.user-pass#user-pass"));
lf[287]=C_h_intern(&lf[287],12, C_text("check-syntax"));
lf[288]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015canonicalized"));
lf[289]=C_h_intern(&lf[289],1, C_text("2"));
lf[290]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020canonicalization"));
lf[291]=C_h_intern(&lf[291],34, C_text("##sys#display-line-number-database"));
lf[292]=C_h_intern(&lf[292],1, C_text("n"));
lf[293]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025line number database:"));
lf[294]=C_h_intern(&lf[294],48, C_text("chicken.compiler.support#display-real-name-table"));
lf[295]=C_h_intern(&lf[295],1, C_text("N"));
lf[296]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020real name table:"));
lf[297]=C_h_intern(&lf[297],59, C_text("chicken.compiler.compiler-syntax#compiler-syntax-statistics"));
lf[298]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002\011\011"));
lf[299]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[300]=C_h_intern(&lf[300],18, C_text("chicken.base#print"));
lf[301]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030applied compiler syntax:"));
lf[302]=C_h_intern(&lf[302],46, C_text("chicken.compiler.support#with-debugging-output"));
lf[303]=C_h_intern(&lf[303],1, C_text("S"));
lf[304]=C_decode_literal(C_heaptop,C_text("\376B\000\000;No module definition found for import libraries to emit: ~A"));
lf[305]=C_h_intern(&lf[305],33, C_text("chicken.string#string-intersperse"));
lf[306]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002, "));
lf[307]=C_h_intern(&lf[307],23, C_text("chicken.string#->string"));
lf[308]=C_h_intern(&lf[308],41, C_text("chicken.compiler.core#immutable-constants"));
lf[309]=C_h_intern(&lf[309],43, C_text("chicken.compiler.core#standalone-executable"));
lf[310]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016\376\377\016"));
lf[311]=C_h_intern(&lf[311],34, C_text("chicken.compiler.core#emit-profile"));
lf[312]=C_h_intern(&lf[312],31, C_text("chicken.compiler.core#unit-name"));
lf[313]=C_h_intern(&lf[313],47, C_text("chicken.compiler.support#profiling-prelude-exps"));
lf[314]=C_h_intern(&lf[314],14, C_text("##core#provide"));
lf[315]=C_h_intern(&lf[315],5, C_text("quote"));
lf[316]=C_h_intern(&lf[316],4, C_text("set!"));
lf[317]=C_h_intern(&lf[317],14, C_text("##core#require"));
lf[318]=C_h_intern(&lf[318],18, C_text("##sys#fast-reverse"));
lf[319]=C_h_intern(&lf[319],36, C_text("chicken.compiler.core#used-libraries"));
lf[320]=C_h_intern(&lf[320],13, C_text("##core#module"));
lf[321]=C_h_intern(&lf[321],21, C_text("scheme#string->symbol"));
lf[322]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006source"));
lf[323]=C_h_intern(&lf[323],1, C_text("1"));
lf[324]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032User preprocessing pass..."));
lf[325]=C_h_intern(&lf[325],49, C_text("chicken.compiler.user-pass#user-preprocessor-pass"));
lf[326]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021User read pass..."));
lf[327]=C_h_intern(&lf[327],37, C_text("chicken.compiler.support#string->expr"));
lf[328]=C_h_intern(&lf[328],14, C_text("scheme#reverse"));
lf[329]=C_h_intern(&lf[329],49, C_text("chicken.compiler.support#close-checked-input-file"));
lf[330]=C_h_intern(&lf[330],36, C_text("chicken.syntax#read-with-source-info"));
lf[331]=C_h_intern(&lf[331],50, C_text("chicken.compiler.support#check-and-open-input-file"));
lf[332]=C_h_intern(&lf[332],41, C_text("chicken.compiler.user-pass#user-read-pass"));
lf[333]=C_h_intern(&lf[333],8, C_text("epilogue"));
lf[334]=C_h_intern(&lf[334],8, C_text("prologue"));
lf[335]=C_h_intern(&lf[335],8, C_text("postlude"));
lf[336]=C_h_intern(&lf[336],7, C_text("prelude"));
lf[337]=C_h_intern(&lf[337],18, C_text("scheme#make-vector"));
lf[338]=C_h_intern(&lf[338],47, C_text("chicken.compiler.core#line-number-database-size"));
lf[339]=C_h_intern(&lf[339],1, C_text("r"));
lf[340]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021target stack size"));
lf[341]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020target heap size"));
lf[342]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021debugging options"));
lf[343]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007options"));
lf[344]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022compiling `~a\047 ..."));
lf[345]=C_h_intern(&lf[345],5, C_text("-help"));
lf[346]=C_h_intern(&lf[346],1, C_text("h"));
lf[347]=C_h_intern(&lf[347],2, C_text("-h"));
lf[348]=C_h_intern(&lf[348],49, C_text("chicken.compiler.support#load-identifier-database"));
lf[349]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012modules.db"));
lf[350]=C_h_intern(&lf[350],18, C_text("accumulate-profile"));
lf[351]=C_h_intern(&lf[351],41, C_text("chicken.compiler.core#profiled-procedures"));
lf[352]=C_h_intern(&lf[352],3, C_text("all"));
lf[353]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015accumulative "));
lf[354]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032generating ~aprofiled code"));
lf[355]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[356]=C_h_intern(&lf[356],58, C_text("chicken.compiler.c-platform#default-profiling-declarations"));
lf[357]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001set!\376\003\000\000\002\376\001\000\000\031\001##sys#profile-append-mode\376\003\000\000\002\376\377\006\001\376\377\016\376\377\016"));
lf[358]=C_decode_literal(C_heaptop,C_text("\376B\000\000Eyou need to specify -profile-name if using accumulated profiling runs"));
lf[359]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011calltrace"));
lf[360]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022debugging info: ~A"));
lf[361]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004none"));
lf[362]=C_h_intern(&lf[362],21, C_text("no-usual-integrations"));
lf[363]=C_h_intern(&lf[363],1, C_text("m"));
lf[364]=C_h_intern(&lf[364],25, C_text("chicken.gc#set-gc-report!"));
lf[365]=C_h_intern(&lf[365],25, C_text("chicken.platform#feature\077"));
lf[366]=C_h_intern_kw(&lf[366],17, C_text("chicken-bootstrap"));
lf[367]=C_h_intern(&lf[367],14, C_text("compile-syntax"));
lf[368]=C_h_intern(&lf[368],27, C_text("##sys#enable-runtime-macros"));
lf[369]=C_h_intern(&lf[369],6, C_text("import"));
lf[370]=C_h_intern(&lf[370],11, C_text("##sys#error"));
lf[371]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034invalid import specification"));
lf[372]=C_h_intern(&lf[372],35, C_text("chicken.port#with-input-from-string"));
lf[373]=C_h_intern(&lf[373],11, C_text("scheme#read"));
lf[374]=C_h_intern(&lf[374],40, C_text("chicken.condition#with-exception-handler"));
lf[375]=C_h_intern(&lf[375],37, C_text("scheme#call-with-current-continuation"));
lf[376]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[377]=C_h_intern(&lf[377],17, C_text("require-extension"));
lf[378]=C_h_intern(&lf[378],5, C_text("foldl"));
lf[379]=C_h_intern(&lf[379],27, C_text("chicken.string#string-split"));
lf[380]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002, "));
lf[381]=C_h_intern(&lf[381],4, C_text("link"));
lf[382]=C_h_intern(&lf[382],4, C_text("uses"));
lf[383]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002, "));
lf[384]=C_h_intern(&lf[384],50, C_text("chicken.compiler.user-pass#user-post-analysis-pass"));
lf[385]=C_h_intern(&lf[385],11, C_text("scheme#load"));
lf[386]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031cannot load extension: ~a"));
lf[387]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036Loading compiler extensions..."));
lf[388]=C_h_intern(&lf[388],6, C_text("extend"));
lf[389]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001,"));
lf[390]=C_h_intern(&lf[390],10, C_text("no-feature"));
lf[391]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002, "));
lf[392]=C_h_intern(&lf[392],7, C_text("feature"));
lf[393]=C_h_intern(&lf[393],25, C_text("chicken.load#load-verbose"));
lf[394]=C_h_intern(&lf[394],38, C_text("no-procedure-checks-for-usual-bindings"));
lf[395]=C_h_intern(&lf[395],23, C_text("##compiler#always-bound"));
lf[396]=C_h_intern(&lf[396],36, C_text("##compiler#always-bound-to-procedure"));
lf[397]=C_h_intern(&lf[397],41, C_text("no-procedure-checks-for-toplevel-bindings"));
lf[398]=C_h_intern(&lf[398],48, C_text("chicken.compiler.core#no-global-procedure-checks"));
lf[399]=C_h_intern(&lf[399],19, C_text("no-procedure-checks"));
lf[400]=C_h_intern(&lf[400],41, C_text("chicken.compiler.core#no-procedure-checks"));
lf[401]=C_h_intern(&lf[401],15, C_text("no-bound-checks"));
lf[402]=C_h_intern(&lf[402],37, C_text("chicken.compiler.core#no-bound-checks"));
lf[403]=C_h_intern(&lf[403],14, C_text("no-argc-checks"));
lf[404]=C_h_intern(&lf[404],36, C_text("chicken.compiler.core#no-argc-checks"));
lf[405]=C_h_intern(&lf[405],20, C_text("keep-shadowed-macros"));
lf[406]=C_h_intern(&lf[406],46, C_text("chicken.compiler.core#undefine-shadowed-macros"));
lf[407]=C_decode_literal(C_heaptop,C_text("\376B\000\000(source- and output-filename are the same"));
lf[408]=C_h_intern(&lf[408],12, C_text("include-path"));
lf[409]=C_h_intern(&lf[409],11, C_text("r5rs-syntax"));
lf[410]=C_h_intern(&lf[410],26, C_text("chicken.base#symbol-escape"));
lf[411]=C_h_intern(&lf[411],33, C_text("chicken.base#parentheses-synonyms"));
lf[412]=C_h_intern(&lf[412],26, C_text("chicken.base#keyword-style"));
lf[413]=C_h_intern_kw(&lf[413],4, C_text("none"));
lf[414]=C_h_intern(&lf[414],27, C_text("chicken.base#case-sensitive"));
lf[415]=C_decode_literal(C_heaptop,C_text("\376B\000\000.Disabled the CHICKEN extensions to R5RS syntax"));
lf[416]=C_h_intern(&lf[416],16, C_text("no-symbol-escape"));
lf[417]=C_decode_literal(C_heaptop,C_text("\376B\000\000$Disabled support for escaped symbols"));
lf[418]=C_h_intern(&lf[418],23, C_text("no-parentheses-synonyms"));
lf[419]=C_decode_literal(C_heaptop,C_text("\376B\000\000)Disabled support for parentheses synonyms"));
lf[420]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006prefix"));
lf[421]=C_h_intern_kw(&lf[421],6, C_text("prefix"));
lf[422]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004none"));
lf[423]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006suffix"));
lf[424]=C_h_intern_kw(&lf[424],6, C_text("suffix"));
lf[425]=C_decode_literal(C_heaptop,C_text("\376B\000\000+invalid argument to `-keyword-style\047 option"));
lf[426]=C_h_intern(&lf[426],16, C_text("case-insensitive"));
lf[427]=C_decode_literal(C_heaptop,C_text("\376B\000\000,Identifiers and symbols are case insensitive"));
lf[428]=C_decode_literal(C_heaptop,C_text("\376B\000\0000invalid argument to `-unroll-limit\047 option: `~A\047"));
lf[429]=C_decode_literal(C_heaptop,C_text("\376B\000\0000invalid argument to `-inline-limit\047 option: `~A\047"));
lf[430]=C_h_intern(&lf[430],39, C_text("chicken.compiler.core#local-definitions"));
lf[431]=C_h_intern(&lf[431],6, C_text("inline"));
lf[432]=C_h_intern(&lf[432],30, C_text("emit-external-prototypes-first"));
lf[433]=C_h_intern(&lf[433],43, C_text("chicken.compiler.core#external-protos-first"));
lf[434]=C_h_intern(&lf[434],5, C_text("block"));
lf[435]=C_h_intern(&lf[435],17, C_text("fixnum-arithmetic"));
lf[436]=C_h_intern(&lf[436],36, C_text("chicken.compiler.support#number-type"));
lf[437]=C_h_intern(&lf[437],6, C_text("fixnum"));
lf[438]=C_h_intern(&lf[438],18, C_text("disable-interrupts"));
lf[439]=C_h_intern(&lf[439],27, C_text("regenerate-import-libraries"));
lf[440]=C_h_intern(&lf[440],57, C_text("chicken.compiler.core#preserve-unchanged-import-libraries"));
lf[441]=C_h_intern(&lf[441],10, C_text("setup-mode"));
lf[442]=C_h_intern(&lf[442],16, C_text("##sys#setup-mode"));
lf[443]=C_h_intern(&lf[443],6, C_text("unsafe"));
lf[444]=C_h_intern(&lf[444],22, C_text("optimize-leaf-routines"));
lf[445]=C_h_intern(&lf[445],11, C_text("no-warnings"));
lf[446]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025Warnings are disabled"));
lf[447]=C_h_intern(&lf[447],12, C_text("strict-types"));
lf[448]=C_h_intern(&lf[448],7, C_text("verbose"));
lf[449]=C_h_intern(&lf[449],34, C_text("chicken.compiler.core#verbose-mode"));
lf[450]=C_h_intern(&lf[450],21, C_text("##sys#notices-enabled"));
lf[451]=C_h_intern(&lf[451],13, C_text("inline-global"));
lf[452]=C_h_intern(&lf[452],5, C_text("local"));
lf[453]=C_h_intern(&lf[453],18, C_text("no-compiler-syntax"));
lf[454]=C_h_intern(&lf[454],45, C_text("chicken.compiler.core#compiler-syntax-enabled"));
lf[455]=C_h_intern(&lf[455],14, C_text("no-lambda-info"));
lf[456]=C_h_intern(&lf[456],39, C_text("chicken.compiler.core#emit-closure-info"));
lf[457]=C_h_intern(&lf[457],3, C_text("raw"));
lf[458]=C_h_intern(&lf[458],1, C_text("b"));
lf[459]=C_h_intern(&lf[459],17, C_text("##sys#start-timer"));
lf[460]=C_h_intern(&lf[460],25, C_text("emit-all-import-libraries"));
lf[461]=C_h_intern(&lf[461],42, C_text("chicken.compiler.core#all-import-libraries"));
lf[462]=C_h_intern(&lf[462],19, C_text("##sys#string-append"));
lf[463]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013.import.scm"));
lf[464]=C_h_intern(&lf[464],19, C_text("emit-import-library"));
lf[465]=C_h_intern(&lf[465],44, C_text("chicken.compiler.support#print-debug-options"));
lf[466]=C_h_intern(&lf[466],18, C_text("##sys#string->list"));
lf[467]=C_h_intern(&lf[467],5, C_text("debug"));
lf[468]=C_h_intern(&lf[468],20, C_text("##sys#dload-disabled"));
lf[469]=C_h_intern(&lf[469],32, C_text("chicken.platform#repository-path"));
lf[470]=C_h_intern(&lf[470],54, C_text("chicken.compiler.optimizer#default-optimization-passes"));
lf[471]=C_h_intern(&lf[471],9, C_text("to-stdout"));
lf[472]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001c"));
lf[473]=C_h_intern(&lf[473],30, C_text("chicken.pathname#pathname-file"));
lf[474]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003out"));
lf[475]=C_h_intern(&lf[475],17, C_text("import-for-syntax"));
lf[476]=C_h_intern(&lf[476],39, C_text("chicken.internal#default-syntax-imports"));
lf[477]=C_h_intern(&lf[477],13, C_text("import-syntax"));
lf[478]=C_h_intern(&lf[478],32, C_text("chicken.internal#default-imports"));
lf[479]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001uses\376\003\000\000\002\376\001\000\000\017\001debugger-client\376\377\016\376\377\016"));
lf[480]=C_h_intern(&lf[480],48, C_text("chicken.compiler.c-platform#default-declarations"));
lf[481]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001uses\376\003\000\000\002\376\001\000\000\014\001eval-modules\376\377\016\376\377\016"));
lf[482]=C_h_intern(&lf[482],39, C_text("chicken.compiler.core#static-extensions"));
lf[483]=C_h_intern(&lf[483],49, C_text("chicken.compiler.core#compile-module-registration"));
lf[484]=C_h_intern(&lf[484],3, C_text("yes"));
lf[485]=C_h_intern(&lf[485],41, C_text("chicken.compiler.c-platform#default-units"));
lf[486]=C_h_intern(&lf[486],6, C_text("static"));
lf[487]=C_h_intern(&lf[487],22, C_text("chicken-compile-static"));
lf[488]=C_h_intern(&lf[488],22, C_text("no-module-registration"));
lf[489]=C_h_intern(&lf[489],2, C_text("no"));
lf[490]=C_h_intern(&lf[490],19, C_text("module-registration"));
lf[491]=C_h_intern(&lf[491],41, C_text("chicken.compiler.core#initialize-compiler"));
C_register_lf2(lf,492,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2707,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[555] = {
{C_text("f8775:batch_2ddriver_2escm"),(void*)f8775},
{C_text("f9431:batch_2ddriver_2escm"),(void*)f9431},
{C_text("f9437:batch_2ddriver_2escm"),(void*)f9437},
{C_text("f9443:batch_2ddriver_2escm"),(void*)f9443},
{C_text("f9449:batch_2ddriver_2escm"),(void*)f9449},
{C_text("f9457:batch_2ddriver_2escm"),(void*)f9457},
{C_text("f9463:batch_2ddriver_2escm"),(void*)f9463},
{C_text("f9475:batch_2ddriver_2escm"),(void*)f9475},
{C_text("f9483:batch_2ddriver_2escm"),(void*)f9483},
{C_text("f9493:batch_2ddriver_2escm"),(void*)f9493},
{C_text("f9513:batch_2ddriver_2escm"),(void*)f9513},
{C_text("f9519:batch_2ddriver_2escm"),(void*)f9519},
{C_text("f9533:batch_2ddriver_2escm"),(void*)f9533},
{C_text("f9539:batch_2ddriver_2escm"),(void*)f9539},
{C_text("f9545:batch_2ddriver_2escm"),(void*)f9545},
{C_text("f9551:batch_2ddriver_2escm"),(void*)f9551},
{C_text("f9557:batch_2ddriver_2escm"),(void*)f9557},
{C_text("f9579:batch_2ddriver_2escm"),(void*)f9579},
{C_text("f9595:batch_2ddriver_2escm"),(void*)f9595},
{C_text("f9601:batch_2ddriver_2escm"),(void*)f9601},
{C_text("f9607:batch_2ddriver_2escm"),(void*)f9607},
{C_text("f9613:batch_2ddriver_2escm"),(void*)f9613},
{C_text("f9619:batch_2ddriver_2escm"),(void*)f9619},
{C_text("f_2707:batch_2ddriver_2escm"),(void*)f_2707},
{C_text("f_2710:batch_2ddriver_2escm"),(void*)f_2710},
{C_text("f_2713:batch_2ddriver_2escm"),(void*)f_2713},
{C_text("f_2716:batch_2ddriver_2escm"),(void*)f_2716},
{C_text("f_2719:batch_2ddriver_2escm"),(void*)f_2719},
{C_text("f_2722:batch_2ddriver_2escm"),(void*)f_2722},
{C_text("f_2725:batch_2ddriver_2escm"),(void*)f_2725},
{C_text("f_2728:batch_2ddriver_2escm"),(void*)f_2728},
{C_text("f_2731:batch_2ddriver_2escm"),(void*)f_2731},
{C_text("f_2734:batch_2ddriver_2escm"),(void*)f_2734},
{C_text("f_2737:batch_2ddriver_2escm"),(void*)f_2737},
{C_text("f_2740:batch_2ddriver_2escm"),(void*)f_2740},
{C_text("f_2743:batch_2ddriver_2escm"),(void*)f_2743},
{C_text("f_2746:batch_2ddriver_2escm"),(void*)f_2746},
{C_text("f_2749:batch_2ddriver_2escm"),(void*)f_2749},
{C_text("f_2752:batch_2ddriver_2escm"),(void*)f_2752},
{C_text("f_2755:batch_2ddriver_2escm"),(void*)f_2755},
{C_text("f_2956:batch_2ddriver_2escm"),(void*)f_2956},
{C_text("f_2971:batch_2ddriver_2escm"),(void*)f_2971},
{C_text("f_2979:batch_2ddriver_2escm"),(void*)f_2979},
{C_text("f_2987:batch_2ddriver_2escm"),(void*)f_2987},
{C_text("f_2998:batch_2ddriver_2escm"),(void*)f_2998},
{C_text("f_3011:batch_2ddriver_2escm"),(void*)f_3011},
{C_text("f_3018:batch_2ddriver_2escm"),(void*)f_3018},
{C_text("f_3025:batch_2ddriver_2escm"),(void*)f_3025},
{C_text("f_3029:batch_2ddriver_2escm"),(void*)f_3029},
{C_text("f_3041:batch_2ddriver_2escm"),(void*)f_3041},
{C_text("f_3043:batch_2ddriver_2escm"),(void*)f_3043},
{C_text("f_3090:batch_2ddriver_2escm"),(void*)f_3090},
{C_text("f_3092:batch_2ddriver_2escm"),(void*)f_3092},
{C_text("f_3160:batch_2ddriver_2escm"),(void*)f_3160},
{C_text("f_3166:batch_2ddriver_2escm"),(void*)f_3166},
{C_text("f_3176:batch_2ddriver_2escm"),(void*)f_3176},
{C_text("f_3252:batch_2ddriver_2escm"),(void*)f_3252},
{C_text("f_3279:batch_2ddriver_2escm"),(void*)f_3279},
{C_text("f_3677:batch_2ddriver_2escm"),(void*)f_3677},
{C_text("f_3702:batch_2ddriver_2escm"),(void*)f_3702},
{C_text("f_3725:batch_2ddriver_2escm"),(void*)f_3725},
{C_text("f_3730:batch_2ddriver_2escm"),(void*)f_3730},
{C_text("f_3744:batch_2ddriver_2escm"),(void*)f_3744},
{C_text("f_4041:batch_2ddriver_2escm"),(void*)f_4041},
{C_text("f_4047:batch_2ddriver_2escm"),(void*)f_4047},
{C_text("f_4054:batch_2ddriver_2escm"),(void*)f_4054},
{C_text("f_4060:batch_2ddriver_2escm"),(void*)f_4060},
{C_text("f_4063:batch_2ddriver_2escm"),(void*)f_4063},
{C_text("f_4066:batch_2ddriver_2escm"),(void*)f_4066},
{C_text("f_4069:batch_2ddriver_2escm"),(void*)f_4069},
{C_text("f_4072:batch_2ddriver_2escm"),(void*)f_4072},
{C_text("f_4078:batch_2ddriver_2escm"),(void*)f_4078},
{C_text("f_4081:batch_2ddriver_2escm"),(void*)f_4081},
{C_text("f_4084:batch_2ddriver_2escm"),(void*)f_4084},
{C_text("f_4090:batch_2ddriver_2escm"),(void*)f_4090},
{C_text("f_4093:batch_2ddriver_2escm"),(void*)f_4093},
{C_text("f_4096:batch_2ddriver_2escm"),(void*)f_4096},
{C_text("f_4102:batch_2ddriver_2escm"),(void*)f_4102},
{C_text("f_4105:batch_2ddriver_2escm"),(void*)f_4105},
{C_text("f_4108:batch_2ddriver_2escm"),(void*)f_4108},
{C_text("f_4114:batch_2ddriver_2escm"),(void*)f_4114},
{C_text("f_4117:batch_2ddriver_2escm"),(void*)f_4117},
{C_text("f_4120:batch_2ddriver_2escm"),(void*)f_4120},
{C_text("f_4126:batch_2ddriver_2escm"),(void*)f_4126},
{C_text("f_4129:batch_2ddriver_2escm"),(void*)f_4129},
{C_text("f_4134:batch_2ddriver_2escm"),(void*)f_4134},
{C_text("f_4138:batch_2ddriver_2escm"),(void*)f_4138},
{C_text("f_4150:batch_2ddriver_2escm"),(void*)f_4150},
{C_text("f_4161:batch_2ddriver_2escm"),(void*)f_4161},
{C_text("f_4174:batch_2ddriver_2escm"),(void*)f_4174},
{C_text("f_4184:batch_2ddriver_2escm"),(void*)f_4184},
{C_text("f_4197:batch_2ddriver_2escm"),(void*)f_4197},
{C_text("f_4207:batch_2ddriver_2escm"),(void*)f_4207},
{C_text("f_4220:batch_2ddriver_2escm"),(void*)f_4220},
{C_text("f_4230:batch_2ddriver_2escm"),(void*)f_4230},
{C_text("f_4243:batch_2ddriver_2escm"),(void*)f_4243},
{C_text("f_4247:batch_2ddriver_2escm"),(void*)f_4247},
{C_text("f_4252:batch_2ddriver_2escm"),(void*)f_4252},
{C_text("f_4262:batch_2ddriver_2escm"),(void*)f_4262},
{C_text("f_4265:batch_2ddriver_2escm"),(void*)f_4265},
{C_text("f_4268:batch_2ddriver_2escm"),(void*)f_4268},
{C_text("f_4271:batch_2ddriver_2escm"),(void*)f_4271},
{C_text("f_4274:batch_2ddriver_2escm"),(void*)f_4274},
{C_text("f_4277:batch_2ddriver_2escm"),(void*)f_4277},
{C_text("f_4280:batch_2ddriver_2escm"),(void*)f_4280},
{C_text("f_4294:batch_2ddriver_2escm"),(void*)f_4294},
{C_text("f_4305:batch_2ddriver_2escm"),(void*)f_4305},
{C_text("f_4309:batch_2ddriver_2escm"),(void*)f_4309},
{C_text("f_4317:batch_2ddriver_2escm"),(void*)f_4317},
{C_text("f_4327:batch_2ddriver_2escm"),(void*)f_4327},
{C_text("f_4347:batch_2ddriver_2escm"),(void*)f_4347},
{C_text("f_4358:batch_2ddriver_2escm"),(void*)f_4358},
{C_text("f_4362:batch_2ddriver_2escm"),(void*)f_4362},
{C_text("f_4374:batch_2ddriver_2escm"),(void*)f_4374},
{C_text("f_4385:batch_2ddriver_2escm"),(void*)f_4385},
{C_text("f_4389:batch_2ddriver_2escm"),(void*)f_4389},
{C_text("f_4412:batch_2ddriver_2escm"),(void*)f_4412},
{C_text("f_4428:batch_2ddriver_2escm"),(void*)f_4428},
{C_text("f_4444:batch_2ddriver_2escm"),(void*)f_4444},
{C_text("f_4453:batch_2ddriver_2escm"),(void*)f_4453},
{C_text("f_4466:batch_2ddriver_2escm"),(void*)f_4466},
{C_text("f_4477:batch_2ddriver_2escm"),(void*)f_4477},
{C_text("f_4483:batch_2ddriver_2escm"),(void*)f_4483},
{C_text("f_4556:batch_2ddriver_2escm"),(void*)f_4556},
{C_text("f_4562:batch_2ddriver_2escm"),(void*)f_4562},
{C_text("f_4565:batch_2ddriver_2escm"),(void*)f_4565},
{C_text("f_4568:batch_2ddriver_2escm"),(void*)f_4568},
{C_text("f_4878:batch_2ddriver_2escm"),(void*)f_4878},
{C_text("f_4880:batch_2ddriver_2escm"),(void*)f_4880},
{C_text("f_4883:batch_2ddriver_2escm"),(void*)f_4883},
{C_text("f_4914:batch_2ddriver_2escm"),(void*)f_4914},
{C_text("f_4923:batch_2ddriver_2escm"),(void*)f_4923},
{C_text("f_4926:batch_2ddriver_2escm"),(void*)f_4926},
{C_text("f_4929:batch_2ddriver_2escm"),(void*)f_4929},
{C_text("f_4939:batch_2ddriver_2escm"),(void*)f_4939},
{C_text("f_4944:batch_2ddriver_2escm"),(void*)f_4944},
{C_text("f_4947:batch_2ddriver_2escm"),(void*)f_4947},
{C_text("f_4952:batch_2ddriver_2escm"),(void*)f_4952},
{C_text("f_4977:batch_2ddriver_2escm"),(void*)f_4977},
{C_text("f_4995:batch_2ddriver_2escm"),(void*)f_4995},
{C_text("f_4999:batch_2ddriver_2escm"),(void*)f_4999},
{C_text("f_5011:batch_2ddriver_2escm"),(void*)f_5011},
{C_text("f_5014:batch_2ddriver_2escm"),(void*)f_5014},
{C_text("f_5017:batch_2ddriver_2escm"),(void*)f_5017},
{C_text("f_5020:batch_2ddriver_2escm"),(void*)f_5020},
{C_text("f_5022:batch_2ddriver_2escm"),(void*)f_5022},
{C_text("f_5029:batch_2ddriver_2escm"),(void*)f_5029},
{C_text("f_5042:batch_2ddriver_2escm"),(void*)f_5042},
{C_text("f_5044:batch_2ddriver_2escm"),(void*)f_5044},
{C_text("f_5051:batch_2ddriver_2escm"),(void*)f_5051},
{C_text("f_5057:batch_2ddriver_2escm"),(void*)f_5057},
{C_text("f_5060:batch_2ddriver_2escm"),(void*)f_5060},
{C_text("f_5063:batch_2ddriver_2escm"),(void*)f_5063},
{C_text("f_5066:batch_2ddriver_2escm"),(void*)f_5066},
{C_text("f_5071:batch_2ddriver_2escm"),(void*)f_5071},
{C_text("f_5078:batch_2ddriver_2escm"),(void*)f_5078},
{C_text("f_5083:batch_2ddriver_2escm"),(void*)f_5083},
{C_text("f_5094:batch_2ddriver_2escm"),(void*)f_5094},
{C_text("f_5104:batch_2ddriver_2escm"),(void*)f_5104},
{C_text("f_5127:batch_2ddriver_2escm"),(void*)f_5127},
{C_text("f_5175:batch_2ddriver_2escm"),(void*)f_5175},
{C_text("f_5184:batch_2ddriver_2escm"),(void*)f_5184},
{C_text("f_5189:batch_2ddriver_2escm"),(void*)f_5189},
{C_text("f_5195:batch_2ddriver_2escm"),(void*)f_5195},
{C_text("f_5201:batch_2ddriver_2escm"),(void*)f_5201},
{C_text("f_5207:batch_2ddriver_2escm"),(void*)f_5207},
{C_text("f_5213:batch_2ddriver_2escm"),(void*)f_5213},
{C_text("f_5219:batch_2ddriver_2escm"),(void*)f_5219},
{C_text("f_5225:batch_2ddriver_2escm"),(void*)f_5225},
{C_text("f_5242:batch_2ddriver_2escm"),(void*)f_5242},
{C_text("f_5251:batch_2ddriver_2escm"),(void*)f_5251},
{C_text("f_5282:batch_2ddriver_2escm"),(void*)f_5282},
{C_text("f_5286:batch_2ddriver_2escm"),(void*)f_5286},
{C_text("f_5302:batch_2ddriver_2escm"),(void*)f_5302},
{C_text("f_5306:batch_2ddriver_2escm"),(void*)f_5306},
{C_text("f_5327:batch_2ddriver_2escm"),(void*)f_5327},
{C_text("f_5333:batch_2ddriver_2escm"),(void*)f_5333},
{C_text("f_5341:batch_2ddriver_2escm"),(void*)f_5341},
{C_text("f_5349:batch_2ddriver_2escm"),(void*)f_5349},
{C_text("f_5353:batch_2ddriver_2escm"),(void*)f_5353},
{C_text("f_5362:batch_2ddriver_2escm"),(void*)f_5362},
{C_text("f_5370:batch_2ddriver_2escm"),(void*)f_5370},
{C_text("f_5372:batch_2ddriver_2escm"),(void*)f_5372},
{C_text("f_5382:batch_2ddriver_2escm"),(void*)f_5382},
{C_text("f_5385:batch_2ddriver_2escm"),(void*)f_5385},
{C_text("f_5388:batch_2ddriver_2escm"),(void*)f_5388},
{C_text("f_5391:batch_2ddriver_2escm"),(void*)f_5391},
{C_text("f_5398:batch_2ddriver_2escm"),(void*)f_5398},
{C_text("f_5402:batch_2ddriver_2escm"),(void*)f_5402},
{C_text("f_5410:batch_2ddriver_2escm"),(void*)f_5410},
{C_text("f_5412:batch_2ddriver_2escm"),(void*)f_5412},
{C_text("f_5414:batch_2ddriver_2escm"),(void*)f_5414},
{C_text("f_5418:batch_2ddriver_2escm"),(void*)f_5418},
{C_text("f_5421:batch_2ddriver_2escm"),(void*)f_5421},
{C_text("f_5426:batch_2ddriver_2escm"),(void*)f_5426},
{C_text("f_5432:batch_2ddriver_2escm"),(void*)f_5432},
{C_text("f_5437:batch_2ddriver_2escm"),(void*)f_5437},
{C_text("f_5442:batch_2ddriver_2escm"),(void*)f_5442},
{C_text("f_5501:batch_2ddriver_2escm"),(void*)f_5501},
{C_text("f_5504:batch_2ddriver_2escm"),(void*)f_5504},
{C_text("f_5507:batch_2ddriver_2escm"),(void*)f_5507},
{C_text("f_5514:batch_2ddriver_2escm"),(void*)f_5514},
{C_text("f_5517:batch_2ddriver_2escm"),(void*)f_5517},
{C_text("f_5534:batch_2ddriver_2escm"),(void*)f_5534},
{C_text("f_5538:batch_2ddriver_2escm"),(void*)f_5538},
{C_text("f_5543:batch_2ddriver_2escm"),(void*)f_5543},
{C_text("f_5549:batch_2ddriver_2escm"),(void*)f_5549},
{C_text("f_5552:batch_2ddriver_2escm"),(void*)f_5552},
{C_text("f_5555:batch_2ddriver_2escm"),(void*)f_5555},
{C_text("f_5558:batch_2ddriver_2escm"),(void*)f_5558},
{C_text("f_5561:batch_2ddriver_2escm"),(void*)f_5561},
{C_text("f_5564:batch_2ddriver_2escm"),(void*)f_5564},
{C_text("f_5567:batch_2ddriver_2escm"),(void*)f_5567},
{C_text("f_5570:batch_2ddriver_2escm"),(void*)f_5570},
{C_text("f_5573:batch_2ddriver_2escm"),(void*)f_5573},
{C_text("f_5576:batch_2ddriver_2escm"),(void*)f_5576},
{C_text("f_5579:batch_2ddriver_2escm"),(void*)f_5579},
{C_text("f_5582:batch_2ddriver_2escm"),(void*)f_5582},
{C_text("f_5585:batch_2ddriver_2escm"),(void*)f_5585},
{C_text("f_5588:batch_2ddriver_2escm"),(void*)f_5588},
{C_text("f_5591:batch_2ddriver_2escm"),(void*)f_5591},
{C_text("f_5594:batch_2ddriver_2escm"),(void*)f_5594},
{C_text("f_5597:batch_2ddriver_2escm"),(void*)f_5597},
{C_text("f_5600:batch_2ddriver_2escm"),(void*)f_5600},
{C_text("f_5603:batch_2ddriver_2escm"),(void*)f_5603},
{C_text("f_5606:batch_2ddriver_2escm"),(void*)f_5606},
{C_text("f_5609:batch_2ddriver_2escm"),(void*)f_5609},
{C_text("f_5612:batch_2ddriver_2escm"),(void*)f_5612},
{C_text("f_5617:batch_2ddriver_2escm"),(void*)f_5617},
{C_text("f_5622:batch_2ddriver_2escm"),(void*)f_5622},
{C_text("f_5627:batch_2ddriver_2escm"),(void*)f_5627},
{C_text("f_5632:batch_2ddriver_2escm"),(void*)f_5632},
{C_text("f_5637:batch_2ddriver_2escm"),(void*)f_5637},
{C_text("f_5640:batch_2ddriver_2escm"),(void*)f_5640},
{C_text("f_5643:batch_2ddriver_2escm"),(void*)f_5643},
{C_text("f_5646:batch_2ddriver_2escm"),(void*)f_5646},
{C_text("f_5649:batch_2ddriver_2escm"),(void*)f_5649},
{C_text("f_5652:batch_2ddriver_2escm"),(void*)f_5652},
{C_text("f_5657:batch_2ddriver_2escm"),(void*)f_5657},
{C_text("f_5660:batch_2ddriver_2escm"),(void*)f_5660},
{C_text("f_5663:batch_2ddriver_2escm"),(void*)f_5663},
{C_text("f_5666:batch_2ddriver_2escm"),(void*)f_5666},
{C_text("f_5669:batch_2ddriver_2escm"),(void*)f_5669},
{C_text("f_5672:batch_2ddriver_2escm"),(void*)f_5672},
{C_text("f_5675:batch_2ddriver_2escm"),(void*)f_5675},
{C_text("f_5678:batch_2ddriver_2escm"),(void*)f_5678},
{C_text("f_5681:batch_2ddriver_2escm"),(void*)f_5681},
{C_text("f_5684:batch_2ddriver_2escm"),(void*)f_5684},
{C_text("f_5690:batch_2ddriver_2escm"),(void*)f_5690},
{C_text("f_5693:batch_2ddriver_2escm"),(void*)f_5693},
{C_text("f_5699:batch_2ddriver_2escm"),(void*)f_5699},
{C_text("f_5706:batch_2ddriver_2escm"),(void*)f_5706},
{C_text("f_5709:batch_2ddriver_2escm"),(void*)f_5709},
{C_text("f_5714:batch_2ddriver_2escm"),(void*)f_5714},
{C_text("f_5717:batch_2ddriver_2escm"),(void*)f_5717},
{C_text("f_5732:batch_2ddriver_2escm"),(void*)f_5732},
{C_text("f_5736:batch_2ddriver_2escm"),(void*)f_5736},
{C_text("f_5744:batch_2ddriver_2escm"),(void*)f_5744},
{C_text("f_5747:batch_2ddriver_2escm"),(void*)f_5747},
{C_text("f_5750:batch_2ddriver_2escm"),(void*)f_5750},
{C_text("f_5753:batch_2ddriver_2escm"),(void*)f_5753},
{C_text("f_5757:batch_2ddriver_2escm"),(void*)f_5757},
{C_text("f_5761:batch_2ddriver_2escm"),(void*)f_5761},
{C_text("f_5764:batch_2ddriver_2escm"),(void*)f_5764},
{C_text("f_5768:batch_2ddriver_2escm"),(void*)f_5768},
{C_text("f_5772:batch_2ddriver_2escm"),(void*)f_5772},
{C_text("f_5783:batch_2ddriver_2escm"),(void*)f_5783},
{C_text("f_5786:batch_2ddriver_2escm"),(void*)f_5786},
{C_text("f_5789:batch_2ddriver_2escm"),(void*)f_5789},
{C_text("f_5792:batch_2ddriver_2escm"),(void*)f_5792},
{C_text("f_5795:batch_2ddriver_2escm"),(void*)f_5795},
{C_text("f_5798:batch_2ddriver_2escm"),(void*)f_5798},
{C_text("f_5806:batch_2ddriver_2escm"),(void*)f_5806},
{C_text("f_5817:batch_2ddriver_2escm"),(void*)f_5817},
{C_text("f_5828:batch_2ddriver_2escm"),(void*)f_5828},
{C_text("f_5835:batch_2ddriver_2escm"),(void*)f_5835},
{C_text("f_5844:batch_2ddriver_2escm"),(void*)f_5844},
{C_text("f_5847:batch_2ddriver_2escm"),(void*)f_5847},
{C_text("f_5850:batch_2ddriver_2escm"),(void*)f_5850},
{C_text("f_5856:batch_2ddriver_2escm"),(void*)f_5856},
{C_text("f_5859:batch_2ddriver_2escm"),(void*)f_5859},
{C_text("f_5862:batch_2ddriver_2escm"),(void*)f_5862},
{C_text("f_5865:batch_2ddriver_2escm"),(void*)f_5865},
{C_text("f_5868:batch_2ddriver_2escm"),(void*)f_5868},
{C_text("f_5872:batch_2ddriver_2escm"),(void*)f_5872},
{C_text("f_5876:batch_2ddriver_2escm"),(void*)f_5876},
{C_text("f_5879:batch_2ddriver_2escm"),(void*)f_5879},
{C_text("f_5882:batch_2ddriver_2escm"),(void*)f_5882},
{C_text("f_5885:batch_2ddriver_2escm"),(void*)f_5885},
{C_text("f_5888:batch_2ddriver_2escm"),(void*)f_5888},
{C_text("f_5891:batch_2ddriver_2escm"),(void*)f_5891},
{C_text("f_5894:batch_2ddriver_2escm"),(void*)f_5894},
{C_text("f_5897:batch_2ddriver_2escm"),(void*)f_5897},
{C_text("f_5900:batch_2ddriver_2escm"),(void*)f_5900},
{C_text("f_5903:batch_2ddriver_2escm"),(void*)f_5903},
{C_text("f_5912:batch_2ddriver_2escm"),(void*)f_5912},
{C_text("f_5916:batch_2ddriver_2escm"),(void*)f_5916},
{C_text("f_5922:batch_2ddriver_2escm"),(void*)f_5922},
{C_text("f_5927:batch_2ddriver_2escm"),(void*)f_5927},
{C_text("f_5933:batch_2ddriver_2escm"),(void*)f_5933},
{C_text("f_5939:batch_2ddriver_2escm"),(void*)f_5939},
{C_text("f_5942:batch_2ddriver_2escm"),(void*)f_5942},
{C_text("f_5948:batch_2ddriver_2escm"),(void*)f_5948},
{C_text("f_5963:batch_2ddriver_2escm"),(void*)f_5963},
{C_text("f_5969:batch_2ddriver_2escm"),(void*)f_5969},
{C_text("f_5972:batch_2ddriver_2escm"),(void*)f_5972},
{C_text("f_5975:batch_2ddriver_2escm"),(void*)f_5975},
{C_text("f_5978:batch_2ddriver_2escm"),(void*)f_5978},
{C_text("f_5981:batch_2ddriver_2escm"),(void*)f_5981},
{C_text("f_5984:batch_2ddriver_2escm"),(void*)f_5984},
{C_text("f_5989:batch_2ddriver_2escm"),(void*)f_5989},
{C_text("f_5992:batch_2ddriver_2escm"),(void*)f_5992},
{C_text("f_5995:batch_2ddriver_2escm"),(void*)f_5995},
{C_text("f_5998:batch_2ddriver_2escm"),(void*)f_5998},
{C_text("f_6001:batch_2ddriver_2escm"),(void*)f_6001},
{C_text("f_6004:batch_2ddriver_2escm"),(void*)f_6004},
{C_text("f_6007:batch_2ddriver_2escm"),(void*)f_6007},
{C_text("f_6010:batch_2ddriver_2escm"),(void*)f_6010},
{C_text("f_6013:batch_2ddriver_2escm"),(void*)f_6013},
{C_text("f_6016:batch_2ddriver_2escm"),(void*)f_6016},
{C_text("f_6019:batch_2ddriver_2escm"),(void*)f_6019},
{C_text("f_6022:batch_2ddriver_2escm"),(void*)f_6022},
{C_text("f_6028:batch_2ddriver_2escm"),(void*)f_6028},
{C_text("f_6031:batch_2ddriver_2escm"),(void*)f_6031},
{C_text("f_6034:batch_2ddriver_2escm"),(void*)f_6034},
{C_text("f_6037:batch_2ddriver_2escm"),(void*)f_6037},
{C_text("f_6040:batch_2ddriver_2escm"),(void*)f_6040},
{C_text("f_6045:batch_2ddriver_2escm"),(void*)f_6045},
{C_text("f_6049:batch_2ddriver_2escm"),(void*)f_6049},
{C_text("f_6052:batch_2ddriver_2escm"),(void*)f_6052},
{C_text("f_6055:batch_2ddriver_2escm"),(void*)f_6055},
{C_text("f_6059:batch_2ddriver_2escm"),(void*)f_6059},
{C_text("f_6062:batch_2ddriver_2escm"),(void*)f_6062},
{C_text("f_6065:batch_2ddriver_2escm"),(void*)f_6065},
{C_text("f_6071:batch_2ddriver_2escm"),(void*)f_6071},
{C_text("f_6074:batch_2ddriver_2escm"),(void*)f_6074},
{C_text("f_6079:batch_2ddriver_2escm"),(void*)f_6079},
{C_text("f_6091:batch_2ddriver_2escm"),(void*)f_6091},
{C_text("f_6095:batch_2ddriver_2escm"),(void*)f_6095},
{C_text("f_6098:batch_2ddriver_2escm"),(void*)f_6098},
{C_text("f_6115:batch_2ddriver_2escm"),(void*)f_6115},
{C_text("f_6129:batch_2ddriver_2escm"),(void*)f_6129},
{C_text("f_6141:batch_2ddriver_2escm"),(void*)f_6141},
{C_text("f_6144:batch_2ddriver_2escm"),(void*)f_6144},
{C_text("f_6147:batch_2ddriver_2escm"),(void*)f_6147},
{C_text("f_6150:batch_2ddriver_2escm"),(void*)f_6150},
{C_text("f_6153:batch_2ddriver_2escm"),(void*)f_6153},
{C_text("f_6156:batch_2ddriver_2escm"),(void*)f_6156},
{C_text("f_6172:batch_2ddriver_2escm"),(void*)f_6172},
{C_text("f_6175:batch_2ddriver_2escm"),(void*)f_6175},
{C_text("f_6178:batch_2ddriver_2escm"),(void*)f_6178},
{C_text("f_6181:batch_2ddriver_2escm"),(void*)f_6181},
{C_text("f_6185:batch_2ddriver_2escm"),(void*)f_6185},
{C_text("f_6188:batch_2ddriver_2escm"),(void*)f_6188},
{C_text("f_6191:batch_2ddriver_2escm"),(void*)f_6191},
{C_text("f_6194:batch_2ddriver_2escm"),(void*)f_6194},
{C_text("f_6197:batch_2ddriver_2escm"),(void*)f_6197},
{C_text("f_6200:batch_2ddriver_2escm"),(void*)f_6200},
{C_text("f_6203:batch_2ddriver_2escm"),(void*)f_6203},
{C_text("f_6208:batch_2ddriver_2escm"),(void*)f_6208},
{C_text("f_6214:batch_2ddriver_2escm"),(void*)f_6214},
{C_text("f_6218:batch_2ddriver_2escm"),(void*)f_6218},
{C_text("f_6221:batch_2ddriver_2escm"),(void*)f_6221},
{C_text("f_6224:batch_2ddriver_2escm"),(void*)f_6224},
{C_text("f_6227:batch_2ddriver_2escm"),(void*)f_6227},
{C_text("f_6230:batch_2ddriver_2escm"),(void*)f_6230},
{C_text("f_6233:batch_2ddriver_2escm"),(void*)f_6233},
{C_text("f_6236:batch_2ddriver_2escm"),(void*)f_6236},
{C_text("f_6239:batch_2ddriver_2escm"),(void*)f_6239},
{C_text("f_6242:batch_2ddriver_2escm"),(void*)f_6242},
{C_text("f_6245:batch_2ddriver_2escm"),(void*)f_6245},
{C_text("f_6258:batch_2ddriver_2escm"),(void*)f_6258},
{C_text("f_6267:batch_2ddriver_2escm"),(void*)f_6267},
{C_text("f_6272:batch_2ddriver_2escm"),(void*)f_6272},
{C_text("f_6296:batch_2ddriver_2escm"),(void*)f_6296},
{C_text("f_6302:batch_2ddriver_2escm"),(void*)f_6302},
{C_text("f_6315:batch_2ddriver_2escm"),(void*)f_6315},
{C_text("f_6317:batch_2ddriver_2escm"),(void*)f_6317},
{C_text("f_6342:batch_2ddriver_2escm"),(void*)f_6342},
{C_text("f_6352:batch_2ddriver_2escm"),(void*)f_6352},
{C_text("f_6355:batch_2ddriver_2escm"),(void*)f_6355},
{C_text("f_6358:batch_2ddriver_2escm"),(void*)f_6358},
{C_text("f_6361:batch_2ddriver_2escm"),(void*)f_6361},
{C_text("f_6373:batch_2ddriver_2escm"),(void*)f_6373},
{C_text("f_6376:batch_2ddriver_2escm"),(void*)f_6376},
{C_text("f_6380:batch_2ddriver_2escm"),(void*)f_6380},
{C_text("f_6389:batch_2ddriver_2escm"),(void*)f_6389},
{C_text("f_6392:batch_2ddriver_2escm"),(void*)f_6392},
{C_text("f_6395:batch_2ddriver_2escm"),(void*)f_6395},
{C_text("f_6398:batch_2ddriver_2escm"),(void*)f_6398},
{C_text("f_6401:batch_2ddriver_2escm"),(void*)f_6401},
{C_text("f_6407:batch_2ddriver_2escm"),(void*)f_6407},
{C_text("f_6451:batch_2ddriver_2escm"),(void*)f_6451},
{C_text("f_6457:batch_2ddriver_2escm"),(void*)f_6457},
{C_text("f_6462:batch_2ddriver_2escm"),(void*)f_6462},
{C_text("f_6471:batch_2ddriver_2escm"),(void*)f_6471},
{C_text("f_6477:batch_2ddriver_2escm"),(void*)f_6477},
{C_text("f_6486:batch_2ddriver_2escm"),(void*)f_6486},
{C_text("f_6490:batch_2ddriver_2escm"),(void*)f_6490},
{C_text("f_6496:batch_2ddriver_2escm"),(void*)f_6496},
{C_text("f_6499:batch_2ddriver_2escm"),(void*)f_6499},
{C_text("f_6504:batch_2ddriver_2escm"),(void*)f_6504},
{C_text("f_6507:batch_2ddriver_2escm"),(void*)f_6507},
{C_text("f_6510:batch_2ddriver_2escm"),(void*)f_6510},
{C_text("f_6513:batch_2ddriver_2escm"),(void*)f_6513},
{C_text("f_6516:batch_2ddriver_2escm"),(void*)f_6516},
{C_text("f_6519:batch_2ddriver_2escm"),(void*)f_6519},
{C_text("f_6522:batch_2ddriver_2escm"),(void*)f_6522},
{C_text("f_6525:batch_2ddriver_2escm"),(void*)f_6525},
{C_text("f_6531:batch_2ddriver_2escm"),(void*)f_6531},
{C_text("f_6541:batch_2ddriver_2escm"),(void*)f_6541},
{C_text("f_6554:batch_2ddriver_2escm"),(void*)f_6554},
{C_text("f_6564:batch_2ddriver_2escm"),(void*)f_6564},
{C_text("f_6583:batch_2ddriver_2escm"),(void*)f_6583},
{C_text("f_6595:batch_2ddriver_2escm"),(void*)f_6595},
{C_text("f_6606:batch_2ddriver_2escm"),(void*)f_6606},
{C_text("f_6616:batch_2ddriver_2escm"),(void*)f_6616},
{C_text("f_6632:batch_2ddriver_2escm"),(void*)f_6632},
{C_text("f_6638:batch_2ddriver_2escm"),(void*)f_6638},
{C_text("f_6645:batch_2ddriver_2escm"),(void*)f_6645},
{C_text("f_6653:batch_2ddriver_2escm"),(void*)f_6653},
{C_text("f_6663:batch_2ddriver_2escm"),(void*)f_6663},
{C_text("f_6678:batch_2ddriver_2escm"),(void*)f_6678},
{C_text("f_6682:batch_2ddriver_2escm"),(void*)f_6682},
{C_text("f_6685:batch_2ddriver_2escm"),(void*)f_6685},
{C_text("f_6688:batch_2ddriver_2escm"),(void*)f_6688},
{C_text("f_6698:batch_2ddriver_2escm"),(void*)f_6698},
{C_text("f_6703:batch_2ddriver_2escm"),(void*)f_6703},
{C_text("f_6728:batch_2ddriver_2escm"),(void*)f_6728},
{C_text("f_6743:batch_2ddriver_2escm"),(void*)f_6743},
{C_text("f_6749:batch_2ddriver_2escm"),(void*)f_6749},
{C_text("f_6760:batch_2ddriver_2escm"),(void*)f_6760},
{C_text("f_6764:batch_2ddriver_2escm"),(void*)f_6764},
{C_text("f_6772:batch_2ddriver_2escm"),(void*)f_6772},
{C_text("f_6775:batch_2ddriver_2escm"),(void*)f_6775},
{C_text("f_6778:batch_2ddriver_2escm"),(void*)f_6778},
{C_text("f_6781:batch_2ddriver_2escm"),(void*)f_6781},
{C_text("f_6798:batch_2ddriver_2escm"),(void*)f_6798},
{C_text("f_6808:batch_2ddriver_2escm"),(void*)f_6808},
{C_text("f_6829:batch_2ddriver_2escm"),(void*)f_6829},
{C_text("f_6848:batch_2ddriver_2escm"),(void*)f_6848},
{C_text("f_6850:batch_2ddriver_2escm"),(void*)f_6850},
{C_text("f_6875:batch_2ddriver_2escm"),(void*)f_6875},
{C_text("f_6907:batch_2ddriver_2escm"),(void*)f_6907},
{C_text("f_6911:batch_2ddriver_2escm"),(void*)f_6911},
{C_text("f_6915:batch_2ddriver_2escm"),(void*)f_6915},
{C_text("f_6941:batch_2ddriver_2escm"),(void*)f_6941},
{C_text("f_6975:batch_2ddriver_2escm"),(void*)f_6975},
{C_text("f_7000:batch_2ddriver_2escm"),(void*)f_7000},
{C_text("f_7009:batch_2ddriver_2escm"),(void*)f_7009},
{C_text("f_7034:batch_2ddriver_2escm"),(void*)f_7034},
{C_text("f_7059:batch_2ddriver_2escm"),(void*)f_7059},
{C_text("f_7065:batch_2ddriver_2escm"),(void*)f_7065},
{C_text("f_7090:batch_2ddriver_2escm"),(void*)f_7090},
{C_text("f_7100:batch_2ddriver_2escm"),(void*)f_7100},
{C_text("f_7110:batch_2ddriver_2escm"),(void*)f_7110},
{C_text("f_7112:batch_2ddriver_2escm"),(void*)f_7112},
{C_text("f_7137:batch_2ddriver_2escm"),(void*)f_7137},
{C_text("f_7147:batch_2ddriver_2escm"),(void*)f_7147},
{C_text("f_7151:batch_2ddriver_2escm"),(void*)f_7151},
{C_text("f_7156:batch_2ddriver_2escm"),(void*)f_7156},
{C_text("f_7167:batch_2ddriver_2escm"),(void*)f_7167},
{C_text("f_7177:batch_2ddriver_2escm"),(void*)f_7177},
{C_text("f_7181:batch_2ddriver_2escm"),(void*)f_7181},
{C_text("f_7191:batch_2ddriver_2escm"),(void*)f_7191},
{C_text("f_7193:batch_2ddriver_2escm"),(void*)f_7193},
{C_text("f_7218:batch_2ddriver_2escm"),(void*)f_7218},
{C_text("f_7227:batch_2ddriver_2escm"),(void*)f_7227},
{C_text("f_7252:batch_2ddriver_2escm"),(void*)f_7252},
{C_text("f_7265:batch_2ddriver_2escm"),(void*)f_7265},
{C_text("f_7268:batch_2ddriver_2escm"),(void*)f_7268},
{C_text("f_7275:batch_2ddriver_2escm"),(void*)f_7275},
{C_text("f_7280:batch_2ddriver_2escm"),(void*)f_7280},
{C_text("f_7286:batch_2ddriver_2escm"),(void*)f_7286},
{C_text("f_7290:batch_2ddriver_2escm"),(void*)f_7290},
{C_text("f_7308:batch_2ddriver_2escm"),(void*)f_7308},
{C_text("f_7315:batch_2ddriver_2escm"),(void*)f_7315},
{C_text("f_7323:batch_2ddriver_2escm"),(void*)f_7323},
{C_text("f_7341:batch_2ddriver_2escm"),(void*)f_7341},
{C_text("f_7347:batch_2ddriver_2escm"),(void*)f_7347},
{C_text("f_7396:batch_2ddriver_2escm"),(void*)f_7396},
{C_text("f_7403:batch_2ddriver_2escm"),(void*)f_7403},
{C_text("f_7419:batch_2ddriver_2escm"),(void*)f_7419},
{C_text("f_7422:batch_2ddriver_2escm"),(void*)f_7422},
{C_text("f_7428:batch_2ddriver_2escm"),(void*)f_7428},
{C_text("f_7430:batch_2ddriver_2escm"),(void*)f_7430},
{C_text("f_7464:batch_2ddriver_2escm"),(void*)f_7464},
{C_text("f_7471:batch_2ddriver_2escm"),(void*)f_7471},
{C_text("f_7476:batch_2ddriver_2escm"),(void*)f_7476},
{C_text("f_7501:batch_2ddriver_2escm"),(void*)f_7501},
{C_text("f_7512:batch_2ddriver_2escm"),(void*)f_7512},
{C_text("f_7519:batch_2ddriver_2escm"),(void*)f_7519},
{C_text("f_7533:batch_2ddriver_2escm"),(void*)f_7533},
{C_text("f_7540:batch_2ddriver_2escm"),(void*)f_7540},
{C_text("f_7545:batch_2ddriver_2escm"),(void*)f_7545},
{C_text("f_7570:batch_2ddriver_2escm"),(void*)f_7570},
{C_text("f_7581:batch_2ddriver_2escm"),(void*)f_7581},
{C_text("f_7583:batch_2ddriver_2escm"),(void*)f_7583},
{C_text("f_7593:batch_2ddriver_2escm"),(void*)f_7593},
{C_text("f_7606:batch_2ddriver_2escm"),(void*)f_7606},
{C_text("f_7616:batch_2ddriver_2escm"),(void*)f_7616},
{C_text("f_7629:batch_2ddriver_2escm"),(void*)f_7629},
{C_text("f_7637:batch_2ddriver_2escm"),(void*)f_7637},
{C_text("f_7639:batch_2ddriver_2escm"),(void*)f_7639},
{C_text("f_7649:batch_2ddriver_2escm"),(void*)f_7649},
{C_text("f_7662:batch_2ddriver_2escm"),(void*)f_7662},
{C_text("f_7670:batch_2ddriver_2escm"),(void*)f_7670},
{C_text("f_7683:batch_2ddriver_2escm"),(void*)f_7683},
{C_text("f_7692:batch_2ddriver_2escm"),(void*)f_7692},
{C_text("f_7697:batch_2ddriver_2escm"),(void*)f_7697},
{C_text("f_7708:batch_2ddriver_2escm"),(void*)f_7708},
{C_text("f_7718:batch_2ddriver_2escm"),(void*)f_7718},
{C_text("f_7731:batch_2ddriver_2escm"),(void*)f_7731},
{C_text("f_7741:batch_2ddriver_2escm"),(void*)f_7741},
{C_text("f_7786:batch_2ddriver_2escm"),(void*)f_7786},
{C_text("f_7792:batch_2ddriver_2escm"),(void*)f_7792},
{C_text("f_7794:batch_2ddriver_2escm"),(void*)f_7794},
{C_text("f_7804:batch_2ddriver_2escm"),(void*)f_7804},
{C_text("f_7819:batch_2ddriver_2escm"),(void*)f_7819},
{C_text("f_7831:batch_2ddriver_2escm"),(void*)f_7831},
{C_text("f_7834:batch_2ddriver_2escm"),(void*)f_7834},
{C_text("f_7837:batch_2ddriver_2escm"),(void*)f_7837},
{C_text("f_7840:batch_2ddriver_2escm"),(void*)f_7840},
{C_text("f_7848:batch_2ddriver_2escm"),(void*)f_7848},
{C_text("f_7856:batch_2ddriver_2escm"),(void*)f_7856},
{C_text("f_7862:batch_2ddriver_2escm"),(void*)f_7862},
{C_text("f_7895:batch_2ddriver_2escm"),(void*)f_7895},
{C_text("f_7898:batch_2ddriver_2escm"),(void*)f_7898},
{C_text("f_7905:batch_2ddriver_2escm"),(void*)f_7905},
{C_text("f_7908:batch_2ddriver_2escm"),(void*)f_7908},
{C_text("f_7911:batch_2ddriver_2escm"),(void*)f_7911},
{C_text("f_7918:batch_2ddriver_2escm"),(void*)f_7918},
{C_text("f_7921:batch_2ddriver_2escm"),(void*)f_7921},
{C_text("f_7924:batch_2ddriver_2escm"),(void*)f_7924},
{C_text("f_7931:batch_2ddriver_2escm"),(void*)f_7931},
{C_text("f_7937:batch_2ddriver_2escm"),(void*)f_7937},
{C_text("f_7941:batch_2ddriver_2escm"),(void*)f_7941},
{C_text("f_7973:batch_2ddriver_2escm"),(void*)f_7973},
{C_text("f_8024:batch_2ddriver_2escm"),(void*)f_8024},
{C_text("f_8062:batch_2ddriver_2escm"),(void*)f_8062},
{C_text("f_8067:batch_2ddriver_2escm"),(void*)f_8067},
{C_text("f_8083:batch_2ddriver_2escm"),(void*)f_8083},
{C_text("f_8088:batch_2ddriver_2escm"),(void*)f_8088},
{C_text("f_8113:batch_2ddriver_2escm"),(void*)f_8113},
{C_text("f_8124:batch_2ddriver_2escm"),(void*)f_8124},
{C_text("f_8138:batch_2ddriver_2escm"),(void*)f_8138},
{C_text("f_8142:batch_2ddriver_2escm"),(void*)f_8142},
{C_text("f_8158:batch_2ddriver_2escm"),(void*)f_8158},
{C_text("f_8162:batch_2ddriver_2escm"),(void*)f_8162},
{C_text("f_8186:batch_2ddriver_2escm"),(void*)f_8186},
{C_text("f_8212:batch_2ddriver_2escm"),(void*)f_8212},
{C_text("f_8220:batch_2ddriver_2escm"),(void*)f_8220},
{C_text("f_8227:batch_2ddriver_2escm"),(void*)f_8227},
{C_text("toplevel:batch_2ddriver_2escm"),(void*)C_batch_2ddriver_toplevel},
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
o|hiding unexported module binding: chicken.compiler.batch-driver#partition 
o|hiding unexported module binding: chicken.compiler.batch-driver#span 
o|hiding unexported module binding: chicken.compiler.batch-driver#take 
o|hiding unexported module binding: chicken.compiler.batch-driver#drop 
o|hiding unexported module binding: chicken.compiler.batch-driver#split-at 
o|hiding unexported module binding: chicken.compiler.batch-driver#append-map 
o|hiding unexported module binding: chicken.compiler.batch-driver#every 
o|hiding unexported module binding: chicken.compiler.batch-driver#any 
o|hiding unexported module binding: chicken.compiler.batch-driver#cons* 
o|hiding unexported module binding: chicken.compiler.batch-driver#concatenate 
o|hiding unexported module binding: chicken.compiler.batch-driver#delete 
o|hiding unexported module binding: chicken.compiler.batch-driver#first 
o|hiding unexported module binding: chicken.compiler.batch-driver#second 
o|hiding unexported module binding: chicken.compiler.batch-driver#third 
o|hiding unexported module binding: chicken.compiler.batch-driver#fourth 
o|hiding unexported module binding: chicken.compiler.batch-driver#fifth 
o|hiding unexported module binding: chicken.compiler.batch-driver#delete-duplicates 
o|hiding unexported module binding: chicken.compiler.batch-driver#alist-cons 
o|hiding unexported module binding: chicken.compiler.batch-driver#filter 
o|hiding unexported module binding: chicken.compiler.batch-driver#filter-map 
o|hiding unexported module binding: chicken.compiler.batch-driver#remove 
o|hiding unexported module binding: chicken.compiler.batch-driver#unzip1 
o|hiding unexported module binding: chicken.compiler.batch-driver#last 
o|hiding unexported module binding: chicken.compiler.batch-driver#list-index 
o|hiding unexported module binding: chicken.compiler.batch-driver#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.compiler.batch-driver#lset-difference/eq? 
o|hiding unexported module binding: chicken.compiler.batch-driver#lset-union/eq? 
o|hiding unexported module binding: chicken.compiler.batch-driver#lset-intersection/eq? 
o|hiding unexported module binding: chicken.compiler.batch-driver#list-tabulate 
o|hiding unexported module binding: chicken.compiler.batch-driver#lset<=/eq? 
o|hiding unexported module binding: chicken.compiler.batch-driver#lset=/eq? 
o|hiding unexported module binding: chicken.compiler.batch-driver#length+ 
o|hiding unexported module binding: chicken.compiler.batch-driver#find 
o|hiding unexported module binding: chicken.compiler.batch-driver#find-tail 
o|hiding unexported module binding: chicken.compiler.batch-driver#iota 
o|hiding unexported module binding: chicken.compiler.batch-driver#make-list 
o|hiding unexported module binding: chicken.compiler.batch-driver#posq 
o|hiding unexported module binding: chicken.compiler.batch-driver#posv 
o|hiding unexported module binding: chicken.compiler.batch-driver#print-program-statistics 
o|hiding unexported module binding: chicken.compiler.batch-driver#initialize-analysis-database 
o|hiding unexported module binding: chicken.compiler.batch-driver#display-analysis-database 
S|applied compiler syntax:
S|  scheme#for-each		15
S|  chicken.format#printf		18
S|  chicken.base#foldl		3
S|  scheme#map		19
S|  chicken.base#foldr		3
o|eliminated procedure checks: 188 
o|folded constant expression: (scheme#* (quote 1024) (quote 1024)) 
o|specializations:
o|  1 (scheme#current-output-port)
o|  5 (chicken.base#add1 *)
o|  2 (scheme#string=? string string)
o|  1 (scheme#string-append string string)
o|  1 (scheme#> integer integer)
o|  1 (chicken.base#sub1 fixnum)
o|  4 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#< fixnum fixnum)
o|  1 (scheme#- fixnum fixnum)
o|  1 (scheme#char=? char char)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#positive? fixnum)
o|  2 (chicken.base#sub1 *)
o|  1 (chicken.base#add1 fixnum)
o|  69 (scheme#memq * list)
o|  40 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  18 (##sys#check-output-port * * *)
o|  1 (scheme#eqv? * *)
o|  6 (##sys#check-list (or pair list) *)
o|  27 (scheme#cdr pair)
o|  10 (scheme#car pair)
(o e)|safe calls: 685 
(o e)|assignments to immediate values: 5 
o|safe globals: (chicken.compiler.batch-driver#compile-source-file chicken.compiler.batch-driver#display-analysis-database chicken.compiler.batch-driver#initialize-analysis-database chicken.compiler.batch-driver#print-program-statistics chicken.compiler.batch-driver#posv chicken.compiler.batch-driver#posq chicken.compiler.batch-driver#make-list chicken.compiler.batch-driver#iota chicken.compiler.batch-driver#find-tail chicken.compiler.batch-driver#find chicken.compiler.batch-driver#length+ chicken.compiler.batch-driver#lset=/eq? chicken.compiler.batch-driver#lset<=/eq? chicken.compiler.batch-driver#list-tabulate chicken.compiler.batch-driver#lset-intersection/eq? chicken.compiler.batch-driver#lset-union/eq? chicken.compiler.batch-driver#lset-difference/eq? chicken.compiler.batch-driver#lset-adjoin/eq? chicken.compiler.batch-driver#list-index chicken.compiler.batch-driver#last chicken.compiler.batch-driver#unzip1 chicken.compiler.batch-driver#remove chicken.compiler.batch-driver#filter-map chicken.compiler.batch-driver#filter chicken.compiler.batch-driver#alist-cons chicken.compiler.batch-driver#delete-duplicates chicken.compiler.batch-driver#fifth chicken.compiler.batch-driver#fourth chicken.compiler.batch-driver#third chicken.compiler.batch-driver#second chicken.compiler.batch-driver#first chicken.compiler.batch-driver#delete chicken.compiler.batch-driver#concatenate chicken.compiler.batch-driver#cons* chicken.compiler.batch-driver#any chicken.compiler.batch-driver#every chicken.compiler.batch-driver#append-map chicken.compiler.batch-driver#split-at chicken.compiler.batch-driver#drop chicken.compiler.batch-driver#take chicken.compiler.batch-driver#span chicken.compiler.batch-driver#partition) 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#partition 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#span 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#drop 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#split-at 
o|merged explicitly consed rest parameter: lsts279 
o|inlining procedure: k2958 
o|inlining procedure: k2973 
o|inlining procedure: k2973 
o|inlining procedure: k2958 
o|inlining procedure: k3013 
o|inlining procedure: k3013 
o|inlining procedure: k3045 
o|contracted procedure: "(mini-srfi-1.scm:77) g332341" 
o|inlining procedure: k3045 
o|inlining procedure: k3094 
o|contracted procedure: "(mini-srfi-1.scm:76) g305314" 
o|inlining procedure: k3094 
o|inlining procedure: k3137 
o|inlining procedure: k3137 
o|inlining procedure: k3168 
o|inlining procedure: k3168 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#cons* 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#concatenate 
o|inlining procedure: k3254 
o|inlining procedure: k3254 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#second 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#third 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#fourth 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#fifth 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#delete-duplicates 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#alist-cons 
o|inlining procedure: k3385 
o|inlining procedure: k3385 
o|inlining procedure: k3377 
o|inlining procedure: k3377 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#filter-map 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#remove 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#unzip1 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#last 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#list-index 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#lset-intersection/eq? 
o|inlining procedure: k3776 
o|inlining procedure: k3776 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#length+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#find 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#find-tail 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#iota 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#make-list 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#posq 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#posv 
o|inlining procedure: k4136 
o|inlining procedure: k4176 
o|contracted procedure: "(batch-driver.scm:100) g818825" 
o|inlining procedure: k4176 
o|propagated global variable: g824826 chicken.compiler.core#internal-bindings 
o|inlining procedure: k4199 
o|contracted procedure: "(batch-driver.scm:96) g800807" 
o|inlining procedure: k4199 
o|propagated global variable: g806808 chicken.compiler.core#extended-bindings 
o|inlining procedure: k4222 
o|contracted procedure: "(batch-driver.scm:92) g782789" 
o|inlining procedure: k4222 
o|propagated global variable: g788790 chicken.compiler.core#standard-bindings 
o|inlining procedure: k4136 
o|inlining procedure: k4254 
o|inlining procedure: k4254 
o|inlining procedure: k4319 
o|contracted procedure: "(batch-driver.scm:171) g10041011" 
o|propagated global variable: out10141017 ##sys#standard-output 
o|substituted constant variable: a4290 
o|substituted constant variable: a4291 
o|propagated global variable: out10141017 ##sys#standard-output 
o|inlining procedure: k4319 
o|propagated global variable: out988991 ##sys#standard-output 
o|substituted constant variable: a4343 
o|substituted constant variable: a4344 
o|propagated global variable: out988991 ##sys#standard-output 
o|propagated global variable: out995998 ##sys#standard-output 
o|substituted constant variable: a4370 
o|substituted constant variable: a4371 
o|inlining procedure: k4363 
o|propagated global variable: out995998 ##sys#standard-output 
o|inlining procedure: k4363 
o|propagated global variable: out977980 ##sys#standard-output 
o|substituted constant variable: a4408 
o|substituted constant variable: a4409 
o|propagated global variable: out977980 ##sys#standard-output 
o|propagated global variable: out971974 ##sys#standard-output 
o|substituted constant variable: a4424 
o|substituted constant variable: a4425 
o|propagated global variable: out971974 ##sys#standard-output 
o|propagated global variable: out965968 ##sys#standard-output 
o|substituted constant variable: a4440 
o|substituted constant variable: a4441 
o|propagated global variable: out965968 ##sys#standard-output 
o|inlining procedure: k4455 
o|propagated global variable: out916919 ##sys#standard-output 
o|substituted constant variable: a4479 
o|substituted constant variable: a4480 
o|substituted constant variable: names837 
o|propagated global variable: out916919 ##sys#standard-output 
o|inlining procedure: k4499 
o|inlining procedure: k4499 
o|inlining procedure: k4512 
o|inlining procedure: k4512 
o|inlining procedure: k4522 
o|inlining procedure: k4522 
o|propagated global variable: out955958 ##sys#standard-output 
o|substituted constant variable: a4558 
o|substituted constant variable: a4559 
o|inlining procedure: k4548 
o|propagated global variable: out955958 ##sys#standard-output 
o|inlining procedure: k4548 
o|inlining procedure: k4590 
o|inlining procedure: k4590 
o|substituted constant variable: a4616 
o|substituted constant variable: a4618 
o|substituted constant variable: a4620 
o|inlining procedure: k4624 
o|inlining procedure: k4624 
o|inlining procedure: k4636 
o|inlining procedure: k4636 
o|inlining procedure: k4648 
o|inlining procedure: k4648 
o|inlining procedure: k4660 
o|inlining procedure: k4660 
o|inlining procedure: k4672 
o|inlining procedure: k4672 
o|substituted constant variable: a4685 
o|substituted constant variable: a4687 
o|substituted constant variable: a4689 
o|substituted constant variable: a4691 
o|substituted constant variable: a4693 
o|substituted constant variable: a4695 
o|substituted constant variable: a4697 
o|substituted constant variable: a4699 
o|substituted constant variable: a4701 
o|substituted constant variable: a4703 
o|substituted constant variable: a4705 
o|substituted constant variable: a4707 
o|substituted constant variable: a4709 
o|substituted constant variable: a4711 
o|substituted constant variable: a4713 
o|substituted constant variable: a4715 
o|inlining procedure: k4719 
o|inlining procedure: k4719 
o|inlining procedure: k4731 
o|inlining procedure: k4731 
o|inlining procedure: k4743 
o|inlining procedure: k4743 
o|inlining procedure: k4755 
o|inlining procedure: k4755 
o|inlining procedure: k4767 
o|inlining procedure: k4767 
o|inlining procedure: k4779 
o|inlining procedure: k4779 
o|inlining procedure: k4791 
o|inlining procedure: k4791 
o|inlining procedure: k4803 
o|inlining procedure: k4803 
o|inlining procedure: k4815 
o|inlining procedure: k4815 
o|inlining procedure: k4827 
o|inlining procedure: k4827 
o|substituted constant variable: a4834 
o|substituted constant variable: a4836 
o|substituted constant variable: a4838 
o|substituted constant variable: a4840 
o|substituted constant variable: a4842 
o|substituted constant variable: a4844 
o|substituted constant variable: a4846 
o|substituted constant variable: a4848 
o|substituted constant variable: a4850 
o|substituted constant variable: a4852 
o|substituted constant variable: a4854 
o|substituted constant variable: a4856 
o|substituted constant variable: a4858 
o|substituted constant variable: a4860 
o|substituted constant variable: a4862 
o|substituted constant variable: a4864 
o|substituted constant variable: a4866 
o|substituted constant variable: a4868 
o|substituted constant variable: a4870 
o|substituted constant variable: a4872 
o|substituted constant variable: a4874 
o|inlining procedure: k4455 
o|inlining procedure: k4885 
o|inlining procedure: k4885 
o|substituted constant variable: a4916 
o|substituted constant variable: a4919 
o|substituted constant variable: a4930 
o|substituted constant variable: a4932 
o|substituted constant variable: a4940 
o|substituted constant variable: a4948 
o|substituted constant variable: a4953 
o|substituted constant variable: a4958 
o|substituted constant variable: a4960 
o|substituted constant variable: a4962 
o|substituted constant variable: a4964 
o|substituted constant variable: a4966 
o|substituted constant variable: a4968 
o|substituted constant variable: a4973 
o|merged explicitly consed rest parameter: args1150 
o|propagated global variable: out11541157 ##sys#standard-output 
o|substituted constant variable: a5007 
o|substituted constant variable: a5008 
o|inlining procedure: k5000 
o|propagated global variable: out11541157 ##sys#standard-output 
o|inlining procedure: k5000 
o|inlining procedure: k5024 
o|inlining procedure: k5024 
o|propagated global variable: out11711174 ##sys#standard-output 
o|substituted constant variable: a5053 
o|substituted constant variable: a5054 
o|inlining procedure: k5046 
o|propagated global variable: out11711174 ##sys#standard-output 
o|inlining procedure: k5046 
o|inlining procedure: k5073 
o|inlining procedure: k5096 
o|contracted procedure: "(batch-driver.scm:279) g11861193" 
o|inlining procedure: k5096 
o|inlining procedure: k5073 
o|inlining procedure: k5176 
o|inlining procedure: k5176 
o|substituted constant variable: a5240 
o|substituted constant variable: a5237 
o|contracted procedure: "(batch-driver.scm:296) string-trim1113" 
o|inlining procedure: k5129 
o|inlining procedure: k5129 
o|inlining procedure: k5146 
o|inlining procedure: k5146 
o|substituted constant variable: a5248 
o|inlining procedure: k5252 
o|inlining procedure: k5252 
o|inlining procedure: k5267 
o|inlining procedure: k5267 
o|substituted constant variable: a5314 
o|substituted constant variable: a5316 
o|substituted constant variable: a5321 
o|substituted constant variable: a5323 
o|substituted constant variable: a5325 
o|inlining procedure: k5338 
o|inlining procedure: k5338 
o|inlining procedure: k5364 
o|inlining procedure: "(batch-driver.scm:321) cputime1107" 
o|inlining procedure: k5364 
o|propagated global variable: out12541257 ##sys#standard-output 
o|substituted constant variable: a5378 
o|substituted constant variable: a5379 
o|inlining procedure: k5374 
o|inlining procedure: "(batch-driver.scm:327) cputime1107" 
o|propagated global variable: out12541257 ##sys#standard-output 
o|inlining procedure: k5374 
o|merged explicitly consed rest parameter: args1265 
o|inlining procedure: k5419 
o|propagated global variable: g12901291 chicken.compiler.support#db-get 
o|propagated global variable: g13041305 chicken.compiler.support#db-put! 
o|inlining procedure: k5419 
o|inlining procedure: k5447 
o|inlining procedure: k5447 
o|inlining procedure: k5483 
o|inlining procedure: k5483 
o|substituted constant variable: a5493 
o|substituted constant variable: a5498 
o|substituted constant variable: a5509 
o|substituted constant variable: a5613 
o|substituted constant variable: a5618 
o|substituted constant variable: a5623 
o|substituted constant variable: a5628 
o|substituted constant variable: a5633 
o|substituted constant variable: a5778 
o|substituted constant variable: a5802 
o|inlining procedure: k5799 
o|inlining procedure: k5799 
o|substituted constant variable: a5813 
o|substituted constant variable: a5824 
o|inlining procedure: k5821 
o|inlining procedure: k5821 
o|inlining procedure: k6066 
o|inlining procedure: k6081 
o|inlining procedure: k6081 
o|inlining procedure: k6099 
o|inlining procedure: k6099 
o|inlining procedure: k6121 
o|inlining procedure: k6121 
o|consed rest parameter at call site: "(batch-driver.scm:825) analyze1119" 3 
o|inlining procedure: k6066 
o|consed rest parameter at call site: "(batch-driver.scm:895) dribble1108" 2 
o|consed rest parameter at call site: "(batch-driver.scm:886) dribble1108" 2 
o|propagated global variable: g21762177 chicken.pretty-print#pp 
o|consed rest parameter at call site: "(batch-driver.scm:881) dribble1108" 2 
o|inlining procedure: "(batch-driver.scm:867) cputime1107" 
o|inlining procedure: k6319 
o|inlining procedure: k6319 
o|propagated global variable: g21532157 chicken.compiler.core#foreign-lambda-stubs 
o|consed rest parameter at call site: "(batch-driver.scm:856) dribble1108" 2 
o|inlining procedure: k6362 
o|inlining procedure: k6362 
o|contracted procedure: "(batch-driver.scm:798) chicken.compiler.batch-driver#print-program-statistics" 
o|propagated global variable: out728731 ##sys#standard-output 
o|substituted constant variable: a4056 
o|substituted constant variable: a4057 
o|propagated global variable: out737740 ##sys#standard-output 
o|substituted constant variable: a4074 
o|substituted constant variable: a4075 
o|propagated global variable: out744747 ##sys#standard-output 
o|substituted constant variable: a4086 
o|substituted constant variable: a4087 
o|propagated global variable: out751754 ##sys#standard-output 
o|substituted constant variable: a4098 
o|substituted constant variable: a4099 
o|propagated global variable: out758761 ##sys#standard-output 
o|substituted constant variable: a4110 
o|substituted constant variable: a4111 
o|propagated global variable: out765768 ##sys#standard-output 
o|substituted constant variable: a4122 
o|substituted constant variable: a4123 
o|inlining procedure: k4049 
o|propagated global variable: out765768 ##sys#standard-output 
o|propagated global variable: out758761 ##sys#standard-output 
o|propagated global variable: out751754 ##sys#standard-output 
o|propagated global variable: out744747 ##sys#standard-output 
o|propagated global variable: out737740 ##sys#standard-output 
o|propagated global variable: out728731 ##sys#standard-output 
o|inlining procedure: k4049 
o|inlining procedure: k6402 
o|consed rest parameter at call site: "(batch-driver.scm:791) dribble1108" 2 
o|inlining procedure: k6402 
o|inlining procedure: k6411 
o|propagated global variable: r64128432 chicken.compiler.core#types-output-file 
o|inlining procedure: k6411 
o|consed rest parameter at call site: "(batch-driver.scm:778) analyze1119" 3 
o|contracted procedure: "(batch-driver.scm:762) chicken.compiler.batch-driver#first" 
o|inlining procedure: k6523 
o|inlining procedure: k6523 
o|consed rest parameter at call site: "(batch-driver.scm:743) analyze1119" 3 
o|inlining procedure: k6533 
o|contracted procedure: "(batch-driver.scm:735) g20582065" 
o|inlining procedure: k6533 
o|inlining procedure: k6556 
o|contracted procedure: "(batch-driver.scm:730) g20372044" 
o|inlining procedure: k6463 
o|inlining procedure: k6463 
o|inlining procedure: k6556 
o|substituted constant variable: a6576 
o|inlining procedure: k6578 
o|inlining procedure: k6578 
o|consed rest parameter at call site: "(batch-driver.scm:719) dribble1108" 2 
o|inlining procedure: k6608 
o|inlining procedure: k6608 
o|inlining procedure: k6633 
o|consed rest parameter at call site: "(batch-driver.scm:711) dribble1108" 2 
o|inlining procedure: k6633 
o|propagated global variable: extensions1988 chicken.compiler.core#required-extensions 
o|inlining procedure: k6655 
o|inlining procedure: k6655 
o|inlining procedure: k6705 
o|inlining procedure: k6705 
o|consed rest parameter at call site: "(batch-driver.scm:691) dribble1108" 2 
o|substituted constant variable: a6736 
o|inlining procedure: k6800 
o|contracted procedure: "(batch-driver.scm:672) g19311938" 
o|propagated global variable: out19411944 ##sys#standard-output 
o|substituted constant variable: a6768 
o|substituted constant variable: a6769 
o|propagated global variable: out19411944 ##sys#standard-output 
o|inlining procedure: k6800 
o|propagated global variable: g19371939 chicken.compiler.compiler-syntax#compiler-syntax-statistics 
o|inlining procedure: k6852 
o|contracted procedure: "(batch-driver.scm:664) g19091918" 
o|inlining procedure: k6852 
o|propagated global variable: g19151919 chicken.compiler.core#import-libraries 
o|inlining procedure: k6924 
o|inlining procedure: k6924 
o|inlining procedure: k6943 
o|contracted procedure: "(batch-driver.scm:646) g18721881" 
o|inlining procedure: k6943 
o|propagated global variable: g18781882 chicken.compiler.core#immutable-constants 
o|inlining procedure: k6977 
o|contracted procedure: "(batch-driver.scm:642) g18411850" 
o|inlining procedure: k6977 
o|inlining procedure: k7011 
o|inlining procedure: k7011 
o|inlining procedure: k7067 
o|inlining procedure: k7067 
o|inlining procedure: k7114 
o|inlining procedure: k7114 
o|consed rest parameter at call site: "(batch-driver.scm:626) dribble1108" 2 
o|consed rest parameter at call site: "(batch-driver.scm:602) dribble1108" 2 
o|inlining procedure: k7158 
o|inlining procedure: k7195 
o|inlining procedure: k7195 
o|inlining procedure: k7229 
o|inlining procedure: k7229 
o|inlining procedure: k7158 
o|inlining procedure: k7291 
o|inlining procedure: k7291 
o|inlining procedure: "(batch-driver.scm:589) cputime1107" 
o|consed rest parameter at call site: "(batch-driver.scm:584) dribble1108" 2 
o|substituted constant variable: a7324 
o|inlining procedure: k7326 
o|substituted constant variable: a7329 
o|inlining procedure: k7326 
o|substituted constant variable: a7334 
o|consed rest parameter at call site: "(batch-driver.scm:563) dribble1108" 2 
o|inlining procedure: k7352 
o|consed rest parameter at call site: "(batch-driver.scm:563) dribble1108" 2 
o|inlining procedure: k7352 
o|consed rest parameter at call site: "(batch-driver.scm:563) dribble1108" 2 
o|inlining procedure: k7356 
o|inlining procedure: k7356 
o|consed rest parameter at call site: "(batch-driver.scm:545) dribble1108" 2 
o|inlining procedure: k7373 
o|consed rest parameter at call site: "(batch-driver.scm:545) dribble1108" 2 
o|inlining procedure: k7373 
o|consed rest parameter at call site: "(batch-driver.scm:545) dribble1108" 2 
o|substituted constant variable: a7376 
o|substituted constant variable: a7388 
o|substituted constant variable: a7404 
o|inlining procedure: k7432 
o|inlining procedure: k7432 
o|contracted procedure: "(batch-driver.scm:519) chicken.compiler.batch-driver#lset-union/eq?" 
o|propagated global variable: ls552 chicken.compiler.core#linked-libraries 
o|inlining procedure: k3679 
o|contracted procedure: "(mini-srfi-1.scm:171) g566567" 
o|inlining procedure: k3704 
o|contracted procedure: "(mini-srfi-1.scm:173) g582583" 
o|inlining procedure: k3720 
o|inlining procedure: k3720 
o|inlining procedure: k3704 
o|inlining procedure: k3679 
o|inlining procedure: k7478 
o|inlining procedure: k7478 
o|consed rest parameter at call site: "(batch-driver.scm:516) chicken.compiler.batch-driver#append-map" 3 
o|inlining procedure: k7547 
o|inlining procedure: k7547 
o|consed rest parameter at call site: "(batch-driver.scm:508) chicken.compiler.batch-driver#append-map" 3 
o|inlining procedure: k7585 
o|contracted procedure: "(batch-driver.scm:497) g15201527" 
o|inlining procedure: k5715 
o|inlining procedure: k5715 
o|inlining procedure: k7585 
o|consed rest parameter at call site: "(batch-driver.scm:496) dribble1108" 2 
o|inlining procedure: k7608 
o|inlining procedure: k7608 
o|propagated global variable: g15091510 chicken.string#string-split 
o|consed rest parameter at call site: "(batch-driver.scm:491) chicken.compiler.batch-driver#append-map" 3 
o|inlining procedure: k7641 
o|inlining procedure: k7641 
o|propagated global variable: g14941495 chicken.string#string-split 
o|consed rest parameter at call site: "(batch-driver.scm:488) chicken.compiler.batch-driver#append-map" 3 
o|substituted constant variable: a7677 
o|inlining procedure: k7710 
o|contracted procedure: "(batch-driver.scm:478) g14691476" 
o|inlining procedure: k7710 
o|propagated global variable: g14751477 chicken.compiler.core#default-extended-bindings 
o|inlining procedure: k7733 
o|contracted procedure: "(batch-driver.scm:473) g14501457" 
o|inlining procedure: k7733 
o|propagated global variable: g14561458 chicken.compiler.core#default-standard-bindings 
o|substituted constant variable: a7753 
o|substituted constant variable: a7756 
o|substituted constant variable: a7759 
o|substituted constant variable: a7762 
o|substituted constant variable: a7765 
o|inlining procedure: k7774 
o|inlining procedure: k7774 
o|inlining procedure: k7796 
o|inlining procedure: k7796 
o|substituted constant variable: a7827 
o|consed rest parameter at call site: "(batch-driver.scm:451) dribble1108" 2 
o|substituted constant variable: a7844 
o|consed rest parameter at call site: "(batch-driver.scm:448) dribble1108" 2 
o|substituted constant variable: a7852 
o|consed rest parameter at call site: "(batch-driver.scm:445) dribble1108" 2 
o|inlining procedure: k7863 
o|inlining procedure: k7863 
o|substituted constant variable: a7875 
o|substituted constant variable: a7883 
o|inlining procedure: k7880 
o|inlining procedure: k7880 
o|substituted constant variable: a7891 
o|consed rest parameter at call site: "(batch-driver.scm:434) dribble1108" 2 
o|inlining procedure: k7909 
o|inlining procedure: k7909 
o|inlining procedure: k7922 
o|inlining procedure: k7922 
o|substituted constant variable: a7942 
o|substituted constant variable: a7945 
o|substituted constant variable: a7948 
o|substituted constant variable: a7951 
o|substituted constant variable: a7954 
o|substituted constant variable: a7957 
o|substituted constant variable: a7960 
o|substituted constant variable: a7963 
o|substituted constant variable: a7966 
o|substituted constant variable: a7969 
o|consed rest parameter at call site: "(batch-driver.scm:397) dribble1108" 2 
o|substituted constant variable: a7976 
o|substituted constant variable: a7980 
o|substituted constant variable: a7984 
o|substituted constant variable: a7988 
o|substituted constant variable: a7991 
o|substituted constant variable: a7994 
o|substituted constant variable: a7997 
o|substituted constant variable: a8018 
o|inlining procedure: k8014 
o|inlining procedure: k8014 
o|inlining procedure: k8026 
o|contracted procedure: "(batch-driver.scm:365) g13581367" 
o|substituted constant variable: a5540 
o|inlining procedure: k8026 
o|inlining procedure: k8090 
o|contracted procedure: "(batch-driver.scm:357) g13301339" 
o|inlining procedure: k8090 
o|consed rest parameter at call site: "(batch-driver.scm:355) chicken.compiler.batch-driver#append-map" 3 
o|substituted constant variable: a8125 
o|propagated global variable: tmp13171319 chicken.compiler.core#unit-name 
o|inlining procedure: k8131 
o|propagated global variable: tmp13171319 chicken.compiler.core#unit-name 
o|inlining procedure: k8131 
o|substituted constant variable: a8146 
o|substituted constant variable: a8151 
o|inlining procedure: k8153 
o|inlining procedure: k8153 
o|substituted constant variable: a8156 
o|inlining procedure: k8163 
o|inlining procedure: k8163 
o|substituted constant variable: a8178 
o|inlining procedure: k8175 
o|inlining procedure: k8175 
o|inlining procedure: k8184 
o|inlining procedure: k8184 
o|inlining procedure: k8195 
o|inlining procedure: k8195 
o|inlining procedure: k8222 
o|inlining procedure: k8222 
o|inlining procedure: k8228 
o|inlining procedure: k8240 
o|inlining procedure: k8240 
o|inlining procedure: k8228 
o|substituted constant variable: a8262 
o|substituted constant variable: a8268 
o|substituted constant variable: a8271 
o|replaced variables: 1085 
o|removed binding forms: 556 
o|substituted constant variable: r29748276 
o|substituted constant variable: r30148278 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#every 
o|substituted constant variable: r31698286 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#filter 
o|removed side-effect free assignment to unused variable: chicken.compiler.batch-driver#list-tabulate 
o|propagated global variable: out10141017 ##sys#standard-output 
o|inlining procedure: k4278 
o|propagated global variable: out988991 ##sys#standard-output 
o|propagated global variable: out995998 ##sys#standard-output 
o|propagated global variable: out977980 ##sys#standard-output 
o|propagated global variable: out971974 ##sys#standard-output 
o|propagated global variable: out965968 ##sys#standard-output 
o|propagated global variable: out916919 ##sys#standard-output 
o|propagated global variable: out955958 ##sys#standard-output 
o|removed side-effect free assignment to unused variable: cputime1107 
o|propagated global variable: out11541157 ##sys#standard-output 
o|substituted constant variable: r50018358 
o|substituted constant variable: r50018359 
o|propagated global variable: out11711174 ##sys#standard-output 
o|substituted constant variable: r53398379 
o|propagated global variable: out12541257 ##sys#standard-output 
o|propagated global variable: out728731 ##sys#standard-output 
o|propagated global variable: out737740 ##sys#standard-output 
o|propagated global variable: out744747 ##sys#standard-output 
o|propagated global variable: out751754 ##sys#standard-output 
o|propagated global variable: out758761 ##sys#standard-output 
o|propagated global variable: out765768 ##sys#standard-output 
o|substituted constant variable: r64038431 
o|substituted constant variable: r64128433 
o|substituted constant variable: r66348451 
o|propagated global variable: extensions1988 chicken.compiler.core#required-extensions 
o|propagated global variable: out19411944 ##sys#standard-output 
o|inlining procedure: k6924 
o|substituted constant variable: r69258462 
o|substituted constant variable: r69258462 
o|substituted constant variable: r73538488 
o|substituted constant variable: r73538488 
o|substituted constant variable: r73538490 
o|substituted constant variable: r73538490 
o|substituted constant variable: r73578492 
o|substituted constant variable: r73578492 
o|substituted constant variable: r73578494 
o|substituted constant variable: r73578494 
o|substituted constant variable: r73748496 
o|substituted constant variable: r73748496 
o|substituted constant variable: r73748498 
o|substituted constant variable: r73748498 
o|contracted procedure: "(batch-driver.scm:525) string->extension-name1114" 
o|substituted constant variable: r51308370 
o|propagated global variable: ls552 chicken.compiler.core#linked-libraries 
o|contracted procedure: "(batch-driver.scm:503) chicken.compiler.batch-driver#delete" 
o|propagated global variable: lst392 ##sys#features 
o|substituted constant variable: r77758534 
o|substituted constant variable: r80158551 
o|propagated global variable: r81328557 chicken.compiler.core#unit-name 
o|substituted constant variable: r81768565 
o|substituted constant variable: r81858569 
o|substituted constant variable: r81858569 
o|substituted constant variable: r81968571 
o|substituted constant variable: r81968571 
o|substituted constant variable: r82238575 
o|substituted constant variable: r82238575 
o|substituted constant variable: r82238577 
o|substituted constant variable: r82238577 
o|substituted constant variable: r82418581 
o|substituted constant variable: r82298582 
o|converted assignments to bindings: (option-arg1037) 
o|simplifications: ((let . 1)) 
o|replaced variables: 111 
o|removed binding forms: 1062 
o|removed conditional forms: 1 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k4464 
o|inlining procedure: k6240 
o|inlining procedure: k6280 
o|inlining procedure: k6562 
o|inlining procedure: k6917 
o|inlining procedure: k6917 
o|contracted procedure: k6924 
o|inlining procedure: k7359 
o|contracted procedure: "(batch-driver.scm:525) g16051614" 
o|inlining procedure: k3735 
o|substituted constant variable: x391 
o|inlining procedure: k7768 
o|inlining procedure: k7768 
o|contracted procedure: "(batch-driver.scm:458) chop-separator1120" 
o|replaced variables: 8 
o|removed binding forms: 149 
o|substituted constant variable: r62818777 
o|substituted constant variable: r69188801 
o|substituted constant variable: r6925 
o|substituted constant variable: r73608820 
o|substituted constant variable: r77698846 
o|substituted constant variable: r77698847 
o|inlining procedure: k5486 
o|inlining procedure: k5486 
o|replaced variables: 20 
o|removed binding forms: 19 
o|removed conditional forms: 4 
o|inlining procedure: k7817 
o|substituted constant variable: r54878941 
o|inlining procedure: k7817 
o|simplifications: ((if . 1) (let . 1)) 
o|removed binding forms: 13 
o|removed conditional forms: 1 
o|replaced variables: 4 
o|removed binding forms: 1 
o|removed binding forms: 3 
o|simplifications: ((if . 14) (let . 20) (##core#call . 410)) 
o|  call simplifications:
o|    scheme#string->list
o|    scheme#string
o|    scheme#string=?	2
o|    scheme#=
o|    scheme#char-whitespace?	2
o|    ##sys#apply
o|    scheme#list
o|    scheme#eof-object?
o|    ##sys#cons	10
o|    ##sys#list	12
o|    scheme#string?
o|    scheme#>
o|    ##sys#call-with-values	4
o|    scheme#-	2
o|    scheme#cddr
o|    scheme#string-length	4
o|    chicken.fixnum#fx<
o|    scheme#string-ref	4
o|    scheme#*	2
o|    scheme#cadr	2
o|    scheme#symbol?	2
o|    scheme#memq	14
o|    scheme#cdar	7
o|    scheme#caar	3
o|    scheme#assq
o|    scheme#length	3
o|    scheme#eq?	53
o|    scheme#not	15
o|    scheme#null?	11
o|    scheme#car	10
o|    scheme#apply	2
o|    scheme#cdr	4
o|    scheme#cons	49
o|    ##sys#setslot	18
o|    ##sys#check-list	31
o|    scheme#pair?	42
o|    ##sys#slot	91
o|contracted procedure: k2961 
o|contracted procedure: k2964 
o|contracted procedure: k2976 
o|contracted procedure: k2992 
o|contracted procedure: k3000 
o|contracted procedure: k3007 
o|contracted procedure: k3031 
o|contracted procedure: k3048 
o|contracted procedure: k3070 
o|contracted procedure: k3066 
o|contracted procedure: k3051 
o|contracted procedure: k3054 
o|contracted procedure: k3062 
o|contracted procedure: k3077 
o|contracted procedure: k3085 
o|contracted procedure: k3097 
o|contracted procedure: k3119 
o|contracted procedure: k3115 
o|contracted procedure: k3100 
o|contracted procedure: k3103 
o|contracted procedure: k3111 
o|contracted procedure: k3171 
o|contracted procedure: k3186 
o|contracted procedure: k4145 
o|contracted procedure: k4156 
o|contracted procedure: k4167 
o|contracted procedure: k4179 
o|contracted procedure: k4189 
o|contracted procedure: k4193 
o|propagated global variable: g824826 chicken.compiler.core#internal-bindings 
o|contracted procedure: k4202 
o|contracted procedure: k4212 
o|contracted procedure: k4216 
o|propagated global variable: g806808 chicken.compiler.core#extended-bindings 
o|contracted procedure: k4225 
o|contracted procedure: k4235 
o|contracted procedure: k4239 
o|propagated global variable: g788790 chicken.compiler.core#standard-bindings 
o|contracted procedure: k4257 
o|contracted procedure: k4284 
o|contracted procedure: k4310 
o|contracted procedure: k4322 
o|contracted procedure: k4332 
o|contracted procedure: k4336 
o|contracted procedure: k4299 
o|contracted procedure: k4352 
o|contracted procedure: k4379 
o|contracted procedure: k4394 
o|contracted procedure: k4401 
o|contracted procedure: k4404 
o|contracted procedure: k4417 
o|contracted procedure: k4420 
o|contracted procedure: k4433 
o|contracted procedure: k4436 
o|contracted procedure: k4449 
o|contracted procedure: k4458 
o|contracted procedure: k4461 
o|contracted procedure: k4472 
o|contracted procedure: k4496 
o|contracted procedure: k4492 
o|contracted procedure: k4488 
o|contracted procedure: k4502 
o|contracted procedure: k4509 
o|contracted procedure: k4515 
o|contracted procedure: k4519 
o|contracted procedure: k4525 
o|contracted procedure: k4531 
o|contracted procedure: k4535 
o|contracted procedure: k4541 
o|contracted procedure: k4545 
o|contracted procedure: k4551 
o|contracted procedure: k4573 
o|contracted procedure: k4577 
o|contracted procedure: k4583 
o|contracted procedure: k4587 
o|contracted procedure: k4593 
o|contracted procedure: k4597 
o|contracted procedure: k4603 
o|contracted procedure: k4607 
o|contracted procedure: k4621 
o|contracted procedure: k4627 
o|contracted procedure: k4633 
o|contracted procedure: k4639 
o|contracted procedure: k4645 
o|contracted procedure: k4651 
o|contracted procedure: k4657 
o|contracted procedure: k4663 
o|contracted procedure: k4669 
o|contracted procedure: k4675 
o|contracted procedure: k4716 
o|contracted procedure: k4722 
o|contracted procedure: k4728 
o|contracted procedure: k4734 
o|contracted procedure: k4740 
o|contracted procedure: k4746 
o|contracted procedure: k4752 
o|contracted procedure: k4758 
o|contracted procedure: k4764 
o|contracted procedure: k4770 
o|contracted procedure: k4776 
o|contracted procedure: k4782 
o|contracted procedure: k4788 
o|contracted procedure: k4794 
o|contracted procedure: k4800 
o|contracted procedure: k4806 
o|contracted procedure: k4812 
o|contracted procedure: k4818 
o|contracted procedure: k4824 
o|contracted procedure: k4909 
o|contracted procedure: k4888 
o|contracted procedure: k4896 
o|contracted procedure: k4902 
o|contracted procedure: k8206 
o|contracted procedure: k4934 
o|contracted procedure: k4955 
o|contracted procedure: k4970 
o|contracted procedure: k5003 
o|contracted procedure: k5087 
o|contracted procedure: k5099 
o|contracted procedure: k5109 
o|contracted procedure: k5113 
o|contracted procedure: k5244 
o|contracted procedure: k5258 
o|contracted procedure: k5264 
o|contracted procedure: k5270 
o|contracted procedure: k5273 
o|inlining procedure: k5249 
o|contracted procedure: k5290 
o|contracted procedure: k5293 
o|inlining procedure: k5249 
o|contracted procedure: k5335 
o|contracted procedure: k5355 
o|contracted procedure: k5404 
o|contracted procedure: k5450 
o|contracted procedure: k5456 
o|contracted procedure: k5463 
o|contracted procedure: k5469 
o|contracted procedure: k5519 
o|contracted procedure: k5523 
o|contracted procedure: k5544 
o|contracted procedure: k5685 
o|contracted procedure: k5694 
o|contracted procedure: k5701 
o|contracted procedure: k5727 
o|contracted procedure: k5738 
o|contracted procedure: k5774 
o|contracted procedure: k5839 
o|contracted procedure: k5904 
o|contracted procedure: k5907 
o|contracted procedure: k5913 
o|contracted procedure: k5943 
o|contracted procedure: k5949 
o|contracted procedure: k5964 
o|contracted procedure: k6167 
o|contracted procedure: k6110 
o|contracted procedure: k6124 
o|inlining procedure: "(batch-driver.scm:895) dribble1108" 
o|contracted procedure: k6249 
o|inlining procedure: "(batch-driver.scm:895) dribble1108" 
o|inlining procedure: "(batch-driver.scm:886) dribble1108" 
o|inlining procedure: "(batch-driver.scm:881) dribble1108" 
o|contracted procedure: k6290 
o|contracted procedure: k6280 
o|contracted procedure: k6297 
o|contracted procedure: k6307 
o|contracted procedure: k6310 
o|contracted procedure: k6322 
o|contracted procedure: k6325 
o|contracted procedure: k6328 
o|contracted procedure: k6336 
o|contracted procedure: k6344 
o|propagated global variable: g21532157 chicken.compiler.core#foreign-lambda-stubs 
o|inlining procedure: "(batch-driver.scm:856) dribble1108" 
o|contracted procedure: k6368 
o|contracted procedure: k6381 
o|inlining procedure: "(batch-driver.scm:791) dribble1108" 
o|contracted procedure: k6414 
o|contracted procedure: k6417 
o|contracted procedure: k6423 
o|contracted procedure: k6429 
o|contracted procedure: k6435 
o|contracted procedure: k6445 
o|contracted procedure: k6452 
o|contracted procedure: k6472 
o|contracted procedure: k6491 
o|contracted procedure: k6536 
o|contracted procedure: k6546 
o|contracted procedure: k6550 
o|contracted procedure: k6559 
o|contracted procedure: k6569 
o|contracted procedure: k6573 
o|contracted procedure: k65698787 
o|contracted procedure: k6587 
o|inlining procedure: "(batch-driver.scm:719) dribble1108" 
o|contracted procedure: k6599 
o|contracted procedure: k6611 
o|contracted procedure: k6621 
o|contracted procedure: k6625 
o|inlining procedure: "(batch-driver.scm:711) dribble1108" 
o|contracted procedure: k6646 
o|contracted procedure: k6658 
o|contracted procedure: k6668 
o|contracted procedure: k6672 
o|propagated global variable: extensions1988 chicken.compiler.core#required-extensions 
o|contracted procedure: k6690 
o|contracted procedure: k6693 
o|contracted procedure: k6708 
o|contracted procedure: k6711 
o|contracted procedure: k6714 
o|contracted procedure: k6722 
o|contracted procedure: k6730 
o|inlining procedure: "(batch-driver.scm:691) dribble1108" 
o|contracted procedure: k6753 
o|contracted procedure: k6791 
o|contracted procedure: k6803 
o|contracted procedure: k6813 
o|contracted procedure: k6817 
o|contracted procedure: k6788 
o|propagated global variable: g19371939 chicken.compiler.compiler-syntax#compiler-syntax-statistics 
o|contracted procedure: k6820 
o|contracted procedure: k6831 
o|contracted procedure: k6843 
o|contracted procedure: k6855 
o|contracted procedure: k6858 
o|contracted procedure: k6861 
o|contracted procedure: k6869 
o|contracted procedure: k6877 
o|contracted procedure: k6840 
o|propagated global variable: g19151919 chicken.compiler.core#import-libraries 
o|contracted procedure: k6884 
o|contracted procedure: k6902 
o|contracted procedure: k6927 
o|contracted procedure: k6937 
o|contracted procedure: k6946 
o|contracted procedure: k6968 
o|contracted procedure: k6893 
o|contracted procedure: k6897 
o|contracted procedure: k6964 
o|contracted procedure: k6949 
o|contracted procedure: k6952 
o|contracted procedure: k6960 
o|propagated global variable: g18781882 chicken.compiler.core#immutable-constants 
o|contracted procedure: k6980 
o|contracted procedure: k6983 
o|contracted procedure: k6986 
o|contracted procedure: k6994 
o|contracted procedure: k7002 
o|contracted procedure: k5958 
o|contracted procedure: k7014 
o|contracted procedure: k7017 
o|contracted procedure: k7020 
o|contracted procedure: k7028 
o|contracted procedure: k7036 
o|contracted procedure: k7042 
o|contracted procedure: k7061 
o|contracted procedure: k7053 
o|contracted procedure: k7049 
o|contracted procedure: k7070 
o|contracted procedure: k7073 
o|contracted procedure: k7076 
o|contracted procedure: k7084 
o|contracted procedure: k7092 
o|contracted procedure: k7102 
o|contracted procedure: k7105 
o|contracted procedure: k7117 
o|contracted procedure: k7120 
o|contracted procedure: k7123 
o|contracted procedure: k7131 
o|contracted procedure: k7139 
o|inlining procedure: "(batch-driver.scm:626) dribble1108" 
o|inlining procedure: "(batch-driver.scm:602) dribble1108" 
o|contracted procedure: k7161 
o|contracted procedure: k7169 
o|contracted procedure: k7172 
o|contracted procedure: k7183 
o|contracted procedure: k7186 
o|contracted procedure: k7198 
o|contracted procedure: k7201 
o|contracted procedure: k7204 
o|contracted procedure: k7212 
o|contracted procedure: k7220 
o|contracted procedure: k7232 
o|contracted procedure: k7235 
o|contracted procedure: k7238 
o|contracted procedure: k7246 
o|contracted procedure: k7254 
o|contracted procedure: k7260 
o|contracted procedure: k7294 
o|contracted procedure: k7301 
o|contracted procedure: k7317 
o|inlining procedure: "(batch-driver.scm:584) dribble1108" 
o|contracted procedure: k7369 
o|contracted procedure: k7336 
o|inlining procedure: "(batch-driver.scm:563) dribble1108" 
o|inlining procedure: "(batch-driver.scm:563) dribble1108" 
o|contracted procedure: k7359 
o|inlining procedure: "(batch-driver.scm:545) dribble1108" 
o|inlining procedure: "(batch-driver.scm:545) dribble1108" 
o|contracted procedure: k7381 
o|contracted procedure: k7408 
o|contracted procedure: k7423 
o|contracted procedure: k7435 
o|contracted procedure: k7457 
o|contracted procedure: k7453 
o|contracted procedure: k7438 
o|contracted procedure: k7441 
o|contracted procedure: k7449 
o|contracted procedure: k5234 
o|contracted procedure: k5179 
o|contracted procedure: k5123 
o|contracted procedure: k5132 
o|contracted procedure: k5167 
o|contracted procedure: k5138 
o|contracted procedure: k5161 
o|contracted procedure: k5149 
o|contracted procedure: k3682 
o|contracted procedure: k3689 
o|contracted procedure: k3746 
o|contracted procedure: k3695 
o|contracted procedure: k3707 
o|contracted procedure: k3714 
o|contracted procedure: k3739 
o|contracted procedure: k3735 
o|contracted procedure: k7466 
o|contracted procedure: k7481 
o|contracted procedure: k7484 
o|contracted procedure: k7487 
o|contracted procedure: k7495 
o|contracted procedure: k7503 
o|contracted procedure: k7513 
o|contracted procedure: k7529 
o|contracted procedure: k7525 
o|contracted procedure: k7521 
o|contracted procedure: k7535 
o|contracted procedure: k7550 
o|contracted procedure: k7553 
o|contracted procedure: k7556 
o|contracted procedure: k7564 
o|contracted procedure: k7572 
o|contracted procedure: k3257 
o|contracted procedure: k3283 
o|contracted procedure: k3263 
o|contracted procedure: k7588 
o|contracted procedure: k7598 
o|contracted procedure: k7602 
o|contracted procedure: k5721 
o|inlining procedure: "(batch-driver.scm:496) dribble1108" 
o|contracted procedure: k7611 
o|contracted procedure: k7621 
o|contracted procedure: k7625 
o|contracted procedure: k7644 
o|contracted procedure: k7654 
o|contracted procedure: k7658 
o|contracted procedure: k7671 
o|contracted procedure: k7687 
o|contracted procedure: k7701 
o|contracted procedure: k7713 
o|contracted procedure: k7723 
o|contracted procedure: k7727 
o|propagated global variable: g14751477 chicken.compiler.core#default-extended-bindings 
o|contracted procedure: k7736 
o|contracted procedure: k7746 
o|contracted procedure: k7750 
o|propagated global variable: g14561458 chicken.compiler.core#default-standard-bindings 
o|contracted procedure: k7768 
o|contracted procedure: k7781 
o|contracted procedure: k7787 
o|contracted procedure: k7799 
o|contracted procedure: k7805 
o|contracted procedure: k7813 
o|contracted procedure: k7821 
o|contracted procedure: k5480 
o|contracted procedure: k5495 
o|inlining procedure: "(batch-driver.scm:451) dribble1108" 
o|inlining procedure: "(batch-driver.scm:448) dribble1108" 
o|inlining procedure: "(batch-driver.scm:445) dribble1108" 
o|contracted procedure: k7866 
o|inlining procedure: "(batch-driver.scm:434) dribble1108" 
o|inlining procedure: "(batch-driver.scm:397) dribble1108" 
o|contracted procedure: k8003 
o|contracted procedure: k8007 
o|contracted procedure: k8014 
o|contracted procedure: k8029 
o|contracted procedure: k8051 
o|contracted procedure: k8047 
o|contracted procedure: k8032 
o|contracted procedure: k8035 
o|contracted procedure: k8043 
o|contracted procedure: k8057 
o|contracted procedure: k8069 
o|contracted procedure: k8093 
o|contracted procedure: k8096 
o|contracted procedure: k8099 
o|contracted procedure: k8107 
o|contracted procedure: k8115 
o|contracted procedure: k8078 
o|contracted procedure: k8166 
o|contracted procedure: k8191 
o|contracted procedure: k8202 
o|contracted procedure: k8195 
o|contracted procedure: k8214 
o|contracted procedure: k8231 
o|contracted procedure: k8237 
o|contracted procedure: k8243 
o|contracted procedure: k8246 
o|contracted procedure: k8259 
o|simplifications: ((if . 2) (let . 150)) 
o|removed binding forms: 372 
o|contracted procedure: k4339 
o|contracted procedure: k4366 
o|removed side-effect free assignment to unused variable: dribble1108 
o|substituted constant variable: fstr11499428 
o|substituted constant variable: args11509429 
o|substituted constant variable: fstr11499434 
o|substituted constant variable: args11509435 
o|substituted constant variable: fstr11499440 
o|substituted constant variable: fstr11499446 
o|substituted constant variable: fstr11499454 
o|substituted constant variable: fstr11499460 
o|contracted procedure: "(batch-driver.scm:717) g20142021" 
o|substituted constant variable: fstr11499472 
o|contracted procedure: "(batch-driver.scm:707) g19921999" 
o|substituted constant variable: fstr11499480 
o|substituted constant variable: fstr11499490 
o|substituted constant variable: args11509491 
o|substituted constant variable: fstr11499510 
o|substituted constant variable: args11509511 
o|substituted constant variable: fstr11499516 
o|substituted constant variable: args11509517 
o|substituted constant variable: fstr11499530 
o|substituted constant variable: fstr11499536 
o|substituted constant variable: fstr11499542 
o|substituted constant variable: fstr11499548 
o|substituted constant variable: fstr11499554 
o|substituted constant variable: fstr11499576 
o|substituted constant variable: args11509577 
o|substituted constant variable: fstr11499592 
o|substituted constant variable: args11509593 
o|substituted constant variable: fstr11499598 
o|substituted constant variable: args11509599 
o|substituted constant variable: fstr11499604 
o|substituted constant variable: args11509605 
o|substituted constant variable: fstr11499610 
o|substituted constant variable: args11509611 
o|substituted constant variable: fstr11499616 
o|substituted constant variable: args11509617 
o|replaced variables: 22 
o|removed binding forms: 4 
o|replaced variables: 3 
o|removed binding forms: 57 
o|inlining procedure: k6661 
o|removed binding forms: 2 
o|removed binding forms: 1 
x|eliminated type checks:
x|  C_i_check_list_2:	1
o|customizable procedures: (k4921 k4924 k8218 k8225 k4937 g10721073 k4950 k5499 k5502 map-loop13241342 map-loop13521370 k5550 k5553 k5559 k5562 k5565 k5568 k5571 k5574 k5577 k5580 k5583 k5586 k5589 k5592 k5595 k5598 k5601 k5604 k5607 k5610 k5615 k5620 k5625 k5630 k5635 k7802 map-loop14211438 k5661 k5664 k5667 k5670 k5673 for-each-loop14491461 for-each-loop14681480 for-each-loop11231496 for-each-loop11331511 for-each-loop15191532 loop394 map-loop15421559 k5748 chicken.compiler.batch-driver#append-map map-loop15731590 foldl575579 foldl559563 loop1203 map-loop15991620 k5762 arg-val1115 k5787 k5815 loop1723 doloop16581659 map-loop16631680 map-loop16891706 map-loop17381755 k5895 map-loop17661783 k5940 g17991808 map-loop17931825 map-loop18351856 map-loop18661887 k6909 map-loop19031921 for-each-loop19301950 print-expr1112 map-loop19591976 chicken.compiler.batch-driver#initialize-analysis-database for-each-loop19912005 for-each-loop20132025 collect-options1116 for-each-loop20362050 for-each-loop20572068 k6020 k6399 map-loop21412158 print-db1111 print-node1110 analyze1119 begin-time1117 end-time1118 loop2089 def-no12701309 def-contf12711307 body12681277 g12491250 option-arg1037 loop1241 for-each-loop11851197 chicken.compiler.batch-driver#display-analysis-database print-header1109 k4245 k4475 k4554 loop848 for-each-loop10031020 for-each-loop781792 for-each-loop799810 for-each-loop817828 loop368 chicken.compiler.batch-driver#any map-loop299317 map-loop326344 loop295 foldr284287 g289290) 
o|calls to known targets: 396 
o|identified direct recursive calls: f_2971 1 
o|identified direct recursive calls: f_3043 1 
o|identified direct recursive calls: f_3092 1 
o|identified direct recursive calls: f_6941 1 
o|identified direct recursive calls: f_5127 2 
o|identified direct recursive calls: f_3252 2 
o|fast box initializations: 54 
o|fast global references: 9 
o|fast global assignments: 4 
o|dropping unused closure argument: f_2956 
o|dropping unused closure argument: f_3160 
o|dropping unused closure argument: f_4883 
o|dropping unused closure argument: f_4995 
o|dropping unused closure argument: f_5242 
*/
/* end of file */
