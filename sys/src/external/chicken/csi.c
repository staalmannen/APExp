/* Generated from csi.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: csi.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -output-file csi.c
   uses: expand data-structures repl posix port pathname eval internal file extras library
*/
#include "chicken.h"

#include <signal.h>

#if defined(HAVE_DIRECT_H)
# include <direct.h>
#else
# define _getcwd(buf, len)       NULL
#endif

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_repl_toplevel)
C_externimport void C_ccall C_repl_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_posix_toplevel)
C_externimport void C_ccall C_posix_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externimport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[407];
static double C_possibly_force_alignment;


/* from k3954 */
C_regparm static C_word C_fcall stub733(C_word C_buf,C_word C_a0,C_word C_a1){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
void * t0=(void * )C_data_pointer_or_null(C_a0);
int t1=(int )C_unfix(C_a1);
C_r=C_mpointer(&C_a,(void*)_getcwd(t0,t1));
return C_r;}

C_noret_decl(f9525)
static void C_ccall f9525(C_word c,C_word *av) C_noret;
C_noret_decl(f9529)
static void C_ccall f9529(C_word c,C_word *av) C_noret;
C_noret_decl(f9650)
static void C_ccall f9650(C_word c,C_word *av) C_noret;
C_noret_decl(f9676)
static void C_ccall f9676(C_word c,C_word *av) C_noret;
C_noret_decl(f9680)
static void C_ccall f9680(C_word c,C_word *av) C_noret;
C_noret_decl(f_2529)
static void C_ccall f_2529(C_word c,C_word *av) C_noret;
C_noret_decl(f_2532)
static void C_ccall f_2532(C_word c,C_word *av) C_noret;
C_noret_decl(f_2535)
static void C_ccall f_2535(C_word c,C_word *av) C_noret;
C_noret_decl(f_2538)
static void C_ccall f_2538(C_word c,C_word *av) C_noret;
C_noret_decl(f_2541)
static void C_ccall f_2541(C_word c,C_word *av) C_noret;
C_noret_decl(f_2544)
static void C_ccall f_2544(C_word c,C_word *av) C_noret;
C_noret_decl(f_2547)
static void C_ccall f_2547(C_word c,C_word *av) C_noret;
C_noret_decl(f_2550)
static void C_ccall f_2550(C_word c,C_word *av) C_noret;
C_noret_decl(f_2553)
static void C_ccall f_2553(C_word c,C_word *av) C_noret;
C_noret_decl(f_2556)
static void C_ccall f_2556(C_word c,C_word *av) C_noret;
C_noret_decl(f_2559)
static void C_ccall f_2559(C_word c,C_word *av) C_noret;
C_noret_decl(f_2562)
static void C_ccall f_2562(C_word c,C_word *av) C_noret;
C_noret_decl(f_3060)
static void C_fcall f_3060(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3087)
static void C_ccall f_3087(C_word c,C_word *av) C_noret;
C_noret_decl(f_3135)
static void C_fcall f_3135(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3149)
static void C_ccall f_3149(C_word c,C_word *av) C_noret;
C_noret_decl(f_3162)
static void C_ccall f_3162(C_word c,C_word *av) C_noret;
C_noret_decl(f_3852)
static void C_ccall f_3852(C_word c,C_word *av) C_noret;
C_noret_decl(f_3857)
static void C_ccall f_3857(C_word c,C_word *av) C_noret;
C_noret_decl(f_3860)
static void C_fcall f_3860(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3866)
static void C_ccall f_3866(C_word c,C_word *av) C_noret;
C_noret_decl(f_3869)
static void C_ccall f_3869(C_word c,C_word *av) C_noret;
C_noret_decl(f_3876)
static void C_ccall f_3876(C_word c,C_word *av) C_noret;
C_noret_decl(f_3900)
static void C_ccall f_3900(C_word c,C_word *av) C_noret;
C_noret_decl(f_3915)
static void C_ccall f_3915(C_word c,C_word *av) C_noret;
C_noret_decl(f_3929)
static void C_ccall f_3929(C_word c,C_word *av) C_noret;
C_noret_decl(f_3942)
static void C_ccall f_3942(C_word c,C_word *av) C_noret;
C_noret_decl(f_3961)
static void C_fcall f_3961(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3968)
static void C_ccall f_3968(C_word c,C_word *av) C_noret;
C_noret_decl(f_3971)
static void C_ccall f_3971(C_word c,C_word *av) C_noret;
C_noret_decl(f_3977)
static void C_ccall f_3977(C_word c,C_word *av) C_noret;
C_noret_decl(f_3990)
static void C_fcall f_3990(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4003)
static void C_ccall f_4003(C_word c,C_word *av) C_noret;
C_noret_decl(f_4012)
static void C_fcall f_4012(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4016)
static void C_ccall f_4016(C_word c,C_word *av) C_noret;
C_noret_decl(f_4028)
static void C_ccall f_4028(C_word c,C_word *av) C_noret;
C_noret_decl(f_4037)
static void C_ccall f_4037(C_word c,C_word *av) C_noret;
C_noret_decl(f_4040)
static void C_ccall f_4040(C_word c,C_word *av) C_noret;
C_noret_decl(f_4047)
static void C_ccall f_4047(C_word c,C_word *av) C_noret;
C_noret_decl(f_4051)
static void C_ccall f_4051(C_word c,C_word *av) C_noret;
C_noret_decl(f_4054)
static void C_ccall f_4054(C_word c,C_word *av) C_noret;
C_noret_decl(f_4060)
static void C_ccall f_4060(C_word c,C_word *av) C_noret;
C_noret_decl(f_4067)
static void C_ccall f_4067(C_word c,C_word *av) C_noret;
C_noret_decl(f_4069)
static void C_fcall f_4069(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4079)
static void C_ccall f_4079(C_word c,C_word *av) C_noret;
C_noret_decl(f_4082)
static void C_ccall f_4082(C_word c,C_word *av) C_noret;
C_noret_decl(f_4096)
static void C_ccall f_4096(C_word c,C_word *av) C_noret;
C_noret_decl(f_4119)
static void C_fcall f_4119(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4129)
static void C_fcall f_4129(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4143)
static void C_ccall f_4143(C_word c,C_word *av) C_noret;
C_noret_decl(f_4174)
static void C_fcall f_4174(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4187)
static void C_ccall f_4187(C_word c,C_word *av) C_noret;
C_noret_decl(f_4190)
static void C_ccall f_4190(C_word c,C_word *av) C_noret;
C_noret_decl(f_4193)
static void C_ccall f_4193(C_word c,C_word *av) C_noret;
C_noret_decl(f_4196)
static void C_ccall f_4196(C_word c,C_word *av) C_noret;
C_noret_decl(f_4199)
static void C_ccall f_4199(C_word c,C_word *av) C_noret;
C_noret_decl(f_4208)
static void C_ccall f_4208(C_word c,C_word *av) C_noret;
C_noret_decl(f_4218)
static void C_fcall f_4218(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4222)
static void C_ccall f_4222(C_word c,C_word *av) C_noret;
C_noret_decl(f_4245)
static void C_ccall f_4245(C_word c,C_word *av) C_noret;
C_noret_decl(f_4262)
static void C_ccall f_4262(C_word c,C_word *av) C_noret;
C_noret_decl(f_4274)
static void C_ccall f_4274(C_word c,C_word *av) C_noret;
C_noret_decl(f_4282)
static void C_ccall f_4282(C_word c,C_word *av) C_noret;
C_noret_decl(f_4285)
static void C_ccall f_4285(C_word c,C_word *av) C_noret;
C_noret_decl(f_4296)
static void C_ccall f_4296(C_word c,C_word *av) C_noret;
C_noret_decl(f_4303)
static void C_ccall f_4303(C_word c,C_word *av) C_noret;
C_noret_decl(f_4309)
static void C_ccall f_4309(C_word c,C_word *av) C_noret;
C_noret_decl(f_4329)
static C_word C_fcall f_4329(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_4364)
static void C_ccall f_4364(C_word c,C_word *av) C_noret;
C_noret_decl(f_4397)
static void C_ccall f_4397(C_word c,C_word *av) C_noret;
C_noret_decl(f_4412)
static void C_ccall f_4412(C_word c,C_word *av) C_noret;
C_noret_decl(f_4415)
static void C_ccall f_4415(C_word c,C_word *av) C_noret;
C_noret_decl(f_4422)
static void C_ccall f_4422(C_word c,C_word *av) C_noret;
C_noret_decl(f_4426)
static void C_ccall f_4426(C_word c,C_word *av) C_noret;
C_noret_decl(f_4435)
static void C_ccall f_4435(C_word c,C_word *av) C_noret;
C_noret_decl(f_4438)
static void C_ccall f_4438(C_word c,C_word *av) C_noret;
C_noret_decl(f_4441)
static void C_ccall f_4441(C_word c,C_word *av) C_noret;
C_noret_decl(f_4453)
static void C_ccall f_4453(C_word c,C_word *av) C_noret;
C_noret_decl(f_4456)
static void C_ccall f_4456(C_word c,C_word *av) C_noret;
C_noret_decl(f_4468)
static void C_ccall f_4468(C_word c,C_word *av) C_noret;
C_noret_decl(f_4471)
static void C_ccall f_4471(C_word c,C_word *av) C_noret;
C_noret_decl(f_4483)
static void C_ccall f_4483(C_word c,C_word *av) C_noret;
C_noret_decl(f_4486)
static void C_ccall f_4486(C_word c,C_word *av) C_noret;
C_noret_decl(f_4489)
static void C_ccall f_4489(C_word c,C_word *av) C_noret;
C_noret_decl(f_4492)
static void C_ccall f_4492(C_word c,C_word *av) C_noret;
C_noret_decl(f_4522)
static void C_ccall f_4522(C_word c,C_word *av) C_noret;
C_noret_decl(f_4525)
static void C_ccall f_4525(C_word c,C_word *av) C_noret;
C_noret_decl(f_4530)
static void C_fcall f_4530(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4540)
static void C_ccall f_4540(C_word c,C_word *av) C_noret;
C_noret_decl(f_4555)
static void C_ccall f_4555(C_word c,C_word *av) C_noret;
C_noret_decl(f_4564)
static void C_ccall f_4564(C_word c,C_word *av) C_noret;
C_noret_decl(f_4565)
static void C_fcall f_4565(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4571)
static void C_ccall f_4571(C_word c,C_word *av) C_noret;
C_noret_decl(f_4575)
static void C_ccall f_4575(C_word c,C_word *av) C_noret;
C_noret_decl(f_4581)
static void C_ccall f_4581(C_word c,C_word *av) C_noret;
C_noret_decl(f_4586)
static void C_fcall f_4586(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4596)
static void C_ccall f_4596(C_word c,C_word *av) C_noret;
C_noret_decl(f_4611)
static void C_ccall f_4611(C_word c,C_word *av) C_noret;
C_noret_decl(f_4620)
static void C_ccall f_4620(C_word c,C_word *av) C_noret;
C_noret_decl(f_4625)
static void C_ccall f_4625(C_word c,C_word *av) C_noret;
C_noret_decl(f_4629)
static void C_ccall f_4629(C_word c,C_word *av) C_noret;
C_noret_decl(f_4634)
static void C_ccall f_4634(C_word c,C_word *av) C_noret;
C_noret_decl(f_4640)
static void C_ccall f_4640(C_word c,C_word *av) C_noret;
C_noret_decl(f_4644)
static void C_ccall f_4644(C_word c,C_word *av) C_noret;
C_noret_decl(f_4651)
static void C_ccall f_4651(C_word c,C_word *av) C_noret;
C_noret_decl(f_4653)
static void C_ccall f_4653(C_word c,C_word *av) C_noret;
C_noret_decl(f_4657)
static void C_ccall f_4657(C_word c,C_word *av) C_noret;
C_noret_decl(f_4672)
static void C_ccall f_4672(C_word c,C_word *av) C_noret;
C_noret_decl(f_4688)
static void C_ccall f_4688(C_word c,C_word *av) C_noret;
C_noret_decl(f_4706)
static void C_ccall f_4706(C_word c,C_word *av) C_noret;
C_noret_decl(f_4710)
static void C_ccall f_4710(C_word c,C_word *av) C_noret;
C_noret_decl(f_4726)
static void C_ccall f_4726(C_word c,C_word *av) C_noret;
C_noret_decl(f_4738)
static void C_ccall f_4738(C_word c,C_word *av) C_noret;
C_noret_decl(f_4750)
static void C_ccall f_4750(C_word c,C_word *av) C_noret;
C_noret_decl(f_4762)
static void C_ccall f_4762(C_word c,C_word *av) C_noret;
C_noret_decl(f_4769)
static void C_ccall f_4769(C_word c,C_word *av) C_noret;
C_noret_decl(f_4782)
static void C_ccall f_4782(C_word c,C_word *av) C_noret;
C_noret_decl(f_4791)
static void C_ccall f_4791(C_word c,C_word *av) C_noret;
C_noret_decl(f_4794)
static void C_ccall f_4794(C_word c,C_word *av) C_noret;
C_noret_decl(f_4797)
static void C_ccall f_4797(C_word c,C_word *av) C_noret;
C_noret_decl(f_4810)
static void C_ccall f_4810(C_word c,C_word *av) C_noret;
C_noret_decl(f_4832)
static void C_ccall f_4832(C_word c,C_word *av) C_noret;
C_noret_decl(f_4837)
static void C_fcall f_4837(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4847)
static void C_ccall f_4847(C_word c,C_word *av) C_noret;
C_noret_decl(f_4861)
static void C_ccall f_4861(C_word c,C_word *av) C_noret;
C_noret_decl(f_4907)
static void C_ccall f_4907(C_word c,C_word *av) C_noret;
C_noret_decl(f_4913)
static void C_ccall f_4913(C_word c,C_word *av) C_noret;
C_noret_decl(f_4917)
static void C_ccall f_4917(C_word c,C_word *av) C_noret;
C_noret_decl(f_4933)
static void C_ccall f_4933(C_word c,C_word *av) C_noret;
C_noret_decl(f_4939)
static void C_ccall f_4939(C_word c,C_word *av) C_noret;
C_noret_decl(f_4953)
static void C_ccall f_4953(C_word c,C_word *av) C_noret;
C_noret_decl(f_4956)
static void C_ccall f_4956(C_word c,C_word *av) C_noret;
C_noret_decl(f_4962)
static void C_ccall f_4962(C_word c,C_word *av) C_noret;
C_noret_decl(f_4965)
static void C_ccall f_4965(C_word c,C_word *av) C_noret;
C_noret_decl(f_4973)
static void C_fcall f_4973(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_4983)
static void C_fcall f_4983(C_word t0,C_word t1) C_noret;
C_noret_decl(f_4998)
static void C_ccall f_4998(C_word c,C_word *av) C_noret;
C_noret_decl(f_5007)
static void C_ccall f_5007(C_word c,C_word *av) C_noret;
C_noret_decl(f_5013)
static void C_ccall f_5013(C_word c,C_word *av) C_noret;
C_noret_decl(f_5019)
static void C_ccall f_5019(C_word c,C_word *av) C_noret;
C_noret_decl(f_5025)
static void C_ccall f_5025(C_word c,C_word *av) C_noret;
C_noret_decl(f_5031)
static void C_ccall f_5031(C_word c,C_word *av) C_noret;
C_noret_decl(f_5039)
static void C_ccall f_5039(C_word c,C_word *av) C_noret;
C_noret_decl(f_5041)
static void C_fcall f_5041(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5058)
static void C_ccall f_5058(C_word c,C_word *av) C_noret;
C_noret_decl(f_5064)
static void C_ccall f_5064(C_word c,C_word *av) C_noret;
C_noret_decl(f_5070)
static void C_ccall f_5070(C_word c,C_word *av) C_noret;
C_noret_decl(f_5078)
static void C_ccall f_5078(C_word c,C_word *av) C_noret;
C_noret_decl(f_5079)
static void C_fcall f_5079(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5089)
static void C_ccall f_5089(C_word c,C_word *av) C_noret;
C_noret_decl(f_5093)
static void C_ccall f_5093(C_word c,C_word *av) C_noret;
C_noret_decl(f_5096)
static void C_ccall f_5096(C_word c,C_word *av) C_noret;
C_noret_decl(f_5099)
static void C_ccall f_5099(C_word c,C_word *av) C_noret;
C_noret_decl(f_5101)
static void C_fcall f_5101(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5109)
static void C_ccall f_5109(C_word c,C_word *av) C_noret;
C_noret_decl(f_5117)
static void C_ccall f_5117(C_word c,C_word *av) C_noret;
C_noret_decl(f_5120)
static void C_ccall f_5120(C_word c,C_word *av) C_noret;
C_noret_decl(f_5121)
static void C_fcall f_5121(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5125)
static void C_ccall f_5125(C_word c,C_word *av) C_noret;
C_noret_decl(f_5135)
static void C_fcall f_5135(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5144)
static void C_ccall f_5144(C_word c,C_word *av) C_noret;
C_noret_decl(f_5152)
static void C_ccall f_5152(C_word c,C_word *av) C_noret;
C_noret_decl(f_5167)
static void C_ccall f_5167(C_word c,C_word *av) C_noret;
C_noret_decl(f_5170)
static void C_ccall f_5170(C_word c,C_word *av) C_noret;
C_noret_decl(f_5173)
static void C_ccall f_5173(C_word c,C_word *av) C_noret;
C_noret_decl(f_5176)
static void C_ccall f_5176(C_word c,C_word *av) C_noret;
C_noret_decl(f_5183)
static void C_ccall f_5183(C_word c,C_word *av) C_noret;
C_noret_decl(f_5188)
static void C_ccall f_5188(C_word c,C_word *av) C_noret;
C_noret_decl(f_5192)
static void C_ccall f_5192(C_word c,C_word *av) C_noret;
C_noret_decl(f_5196)
static void C_ccall f_5196(C_word c,C_word *av) C_noret;
C_noret_decl(f_5200)
static void C_ccall f_5200(C_word c,C_word *av) C_noret;
C_noret_decl(f_5204)
static void C_ccall f_5204(C_word c,C_word *av) C_noret;
C_noret_decl(f_5208)
static void C_ccall f_5208(C_word c,C_word *av) C_noret;
C_noret_decl(f_5212)
static void C_ccall f_5212(C_word c,C_word *av) C_noret;
C_noret_decl(f_5216)
static void C_ccall f_5216(C_word c,C_word *av) C_noret;
C_noret_decl(f_5244)
static void C_ccall f_5244(C_word c,C_word *av) C_noret;
C_noret_decl(f_5256)
static void C_ccall f_5256(C_word c,C_word *av) C_noret;
C_noret_decl(f_5258)
static void C_fcall f_5258(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5268)
static void C_ccall f_5268(C_word c,C_word *av) C_noret;
C_noret_decl(f_5289)
static void C_ccall f_5289(C_word c,C_word *av) C_noret;
C_noret_decl(f_5291)
static void C_fcall f_5291(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5316)
static void C_ccall f_5316(C_word c,C_word *av) C_noret;
C_noret_decl(f_5336)
static C_word C_fcall f_5336(C_word t0,C_word t1);
C_noret_decl(f_5371)
static C_word C_fcall f_5371(C_word t0);
C_noret_decl(f_5401)
static void C_ccall f_5401(C_word c,C_word *av) C_noret;
C_noret_decl(f_5403)
static void C_fcall f_5403(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5409)
static void C_ccall f_5409(C_word c,C_word *av) C_noret;
C_noret_decl(f_5416)
static void C_ccall f_5416(C_word c,C_word *av) C_noret;
C_noret_decl(f_5421)
static void C_fcall f_5421(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5444)
static void C_ccall f_5444(C_word c,C_word *av) C_noret;
C_noret_decl(f_5453)
static void C_fcall f_5453(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5463)
static void C_ccall f_5463(C_word c,C_word *av) C_noret;
C_noret_decl(f_5466)
static void C_ccall f_5466(C_word c,C_word *av) C_noret;
C_noret_decl(f_5495)
static void C_ccall f_5495(C_word c,C_word *av) C_noret;
C_noret_decl(f_5523)
static void C_ccall f_5523(C_word c,C_word *av) C_noret;
C_noret_decl(f_5538)
static void C_ccall f_5538(C_word c,C_word *av) C_noret;
C_noret_decl(f_5541)
static void C_ccall f_5541(C_word c,C_word *av) C_noret;
C_noret_decl(f_5544)
static void C_ccall f_5544(C_word c,C_word *av) C_noret;
C_noret_decl(f_5616)
static void C_ccall f_5616(C_word c,C_word *av) C_noret;
C_noret_decl(f_5622)
static void C_ccall f_5622(C_word c,C_word *av) C_noret;
C_noret_decl(f_5713)
static void C_ccall f_5713(C_word c,C_word *av) C_noret;
C_noret_decl(f_5720)
static void C_ccall f_5720(C_word c,C_word *av) C_noret;
C_noret_decl(f_5729)
static void C_ccall f_5729(C_word c,C_word *av) C_noret;
C_noret_decl(f_5732)
static void C_ccall f_5732(C_word c,C_word *av) C_noret;
C_noret_decl(f_5744)
static void C_ccall f_5744(C_word c,C_word *av) C_noret;
C_noret_decl(f_5749)
static void C_fcall f_5749(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5759)
static void C_ccall f_5759(C_word c,C_word *av) C_noret;
C_noret_decl(f_5762)
static void C_ccall f_5762(C_word c,C_word *av) C_noret;
C_noret_decl(f_5765)
static void C_ccall f_5765(C_word c,C_word *av) C_noret;
C_noret_decl(f_5774)
static void C_ccall f_5774(C_word c,C_word *av) C_noret;
C_noret_decl(f_5794)
static void C_ccall f_5794(C_word c,C_word *av) C_noret;
C_noret_decl(f_5797)
static void C_ccall f_5797(C_word c,C_word *av) C_noret;
C_noret_decl(f_5800)
static void C_ccall f_5800(C_word c,C_word *av) C_noret;
C_noret_decl(f_5812)
static void C_fcall f_5812(C_word t0,C_word t1) C_noret;
C_noret_decl(f_5815)
static void C_ccall f_5815(C_word c,C_word *av) C_noret;
C_noret_decl(f_5824)
static void C_fcall f_5824(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5855)
static void C_ccall f_5855(C_word c,C_word *av) C_noret;
C_noret_decl(f_5919)
static void C_ccall f_5919(C_word c,C_word *av) C_noret;
C_noret_decl(f_5923)
static void C_ccall f_5923(C_word c,C_word *av) C_noret;
C_noret_decl(f_5929)
static void C_ccall f_5929(C_word c,C_word *av) C_noret;
C_noret_decl(f_5948)
static void C_ccall f_5948(C_word c,C_word *av) C_noret;
C_noret_decl(f_5966)
static void C_ccall f_5966(C_word c,C_word *av) C_noret;
C_noret_decl(f_5973)
static void C_ccall f_5973(C_word c,C_word *av) C_noret;
C_noret_decl(f_6090)
static void C_ccall f_6090(C_word c,C_word *av) C_noret;
C_noret_decl(f_6096)
static void C_ccall f_6096(C_word c,C_word *av) C_noret;
C_noret_decl(f_6102)
static void C_ccall f_6102(C_word c,C_word *av) C_noret;
C_noret_decl(f_6115)
static void C_ccall f_6115(C_word c,C_word *av) C_noret;
C_noret_decl(f_6127)
static void C_ccall f_6127(C_word c,C_word *av) C_noret;
C_noret_decl(f_6130)
static void C_ccall f_6130(C_word c,C_word *av) C_noret;
C_noret_decl(f_6141)
static void C_fcall f_6141(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6149)
static void C_fcall f_6149(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6170)
static void C_ccall f_6170(C_word c,C_word *av) C_noret;
C_noret_decl(f_6179)
static void C_fcall f_6179(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6189)
static void C_ccall f_6189(C_word c,C_word *av) C_noret;
C_noret_decl(f_6224)
static void C_ccall f_6224(C_word c,C_word *av) C_noret;
C_noret_decl(f_6225)
static void C_fcall f_6225(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6229)
static void C_ccall f_6229(C_word c,C_word *av) C_noret;
C_noret_decl(f_6238)
static void C_fcall f_6238(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6248)
static void C_ccall f_6248(C_word c,C_word *av) C_noret;
C_noret_decl(f_6261)
static void C_ccall f_6261(C_word c,C_word *av) C_noret;
C_noret_decl(f_6266)
static void C_ccall f_6266(C_word c,C_word *av) C_noret;
C_noret_decl(f_6293)
static void C_fcall f_6293(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6303)
static void C_ccall f_6303(C_word c,C_word *av) C_noret;
C_noret_decl(f_6330)
static void C_ccall f_6330(C_word c,C_word *av) C_noret;
C_noret_decl(f_6334)
static void C_fcall f_6334(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6348)
static void C_fcall f_6348(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6356)
static void C_ccall f_6356(C_word c,C_word *av) C_noret;
C_noret_decl(f_6369)
static void C_ccall f_6369(C_word c,C_word *av) C_noret;
C_noret_decl(f_6375)
static void C_fcall f_6375(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6400)
static void C_ccall f_6400(C_word c,C_word *av) C_noret;
C_noret_decl(f_6413)
static void C_ccall f_6413(C_word c,C_word *av) C_noret;
C_noret_decl(f_6441)
static void C_ccall f_6441(C_word c,C_word *av) C_noret;
C_noret_decl(f_6449)
static void C_ccall f_6449(C_word c,C_word *av) C_noret;
C_noret_decl(f_6458)
static void C_fcall f_6458(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6460)
static void C_fcall f_6460(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6463)
static void C_fcall f_6463(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6485)
static void C_ccall f_6485(C_word c,C_word *av) C_noret;
C_noret_decl(f_6492)
static void C_ccall f_6492(C_word c,C_word *av) C_noret;
C_noret_decl(f_6509)
static void C_ccall f_6509(C_word c,C_word *av) C_noret;
C_noret_decl(f_6538)
static void C_ccall f_6538(C_word c,C_word *av) C_noret;
C_noret_decl(f_6566)
static void C_fcall f_6566(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6571)
static void C_fcall f_6571(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6606)
static void C_fcall f_6606(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_6609)
static void C_fcall f_6609(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_6613)
static void C_ccall f_6613(C_word c,C_word *av) C_noret;
C_noret_decl(f_6629)
static void C_ccall f_6629(C_word c,C_word *av) C_noret;
C_noret_decl(f_6641)
static void C_fcall f_6641(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6651)
static void C_ccall f_6651(C_word c,C_word *av) C_noret;
C_noret_decl(f_6654)
static void C_ccall f_6654(C_word c,C_word *av) C_noret;
C_noret_decl(f_6657)
static void C_ccall f_6657(C_word c,C_word *av) C_noret;
C_noret_decl(f_6660)
static void C_ccall f_6660(C_word c,C_word *av) C_noret;
C_noret_decl(f_6663)
static void C_ccall f_6663(C_word c,C_word *av) C_noret;
C_noret_decl(f_6666)
static void C_ccall f_6666(C_word c,C_word *av) C_noret;
C_noret_decl(f_6675)
static void C_fcall f_6675(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6688)
static void C_ccall f_6688(C_word c,C_word *av) C_noret;
C_noret_decl(f_6691)
static void C_ccall f_6691(C_word c,C_word *av) C_noret;
C_noret_decl(f_6726)
static void C_fcall f_6726(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6760)
static void C_fcall f_6760(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6770)
static void C_ccall f_6770(C_word c,C_word *av) C_noret;
C_noret_decl(f_6780)
static void C_ccall f_6780(C_word c,C_word *av) C_noret;
C_noret_decl(f_6783)
static void C_ccall f_6783(C_word c,C_word *av) C_noret;
C_noret_decl(f_6798)
static void C_ccall f_6798(C_word c,C_word *av) C_noret;
C_noret_decl(f_6802)
static void C_ccall f_6802(C_word c,C_word *av) C_noret;
C_noret_decl(f_6809)
static void C_ccall f_6809(C_word c,C_word *av) C_noret;
C_noret_decl(f_6811)
static void C_fcall f_6811(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6814)
static void C_fcall f_6814(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6820)
static void C_ccall f_6820(C_word c,C_word *av) C_noret;
C_noret_decl(f_6837)
static void C_fcall f_6837(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6846)
static void C_fcall f_6846(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6877)
static void C_ccall f_6877(C_word c,C_word *av) C_noret;
C_noret_decl(f_6880)
static void C_ccall f_6880(C_word c,C_word *av) C_noret;
C_noret_decl(f_6883)
static void C_ccall f_6883(C_word c,C_word *av) C_noret;
C_noret_decl(f_6886)
static void C_ccall f_6886(C_word c,C_word *av) C_noret;
C_noret_decl(f_6889)
static void C_ccall f_6889(C_word c,C_word *av) C_noret;
C_noret_decl(f_6892)
static void C_ccall f_6892(C_word c,C_word *av) C_noret;
C_noret_decl(f_6895)
static void C_ccall f_6895(C_word c,C_word *av) C_noret;
C_noret_decl(f_6898)
static void C_ccall f_6898(C_word c,C_word *av) C_noret;
C_noret_decl(f_6901)
static void C_ccall f_6901(C_word c,C_word *av) C_noret;
C_noret_decl(f_6904)
static void C_ccall f_6904(C_word c,C_word *av) C_noret;
C_noret_decl(f_6907)
static void C_ccall f_6907(C_word c,C_word *av) C_noret;
C_noret_decl(f_6920)
static void C_fcall f_6920(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6930)
static void C_ccall f_6930(C_word c,C_word *av) C_noret;
C_noret_decl(f_6935)
static void C_fcall f_6935(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6948)
static void C_ccall f_6948(C_word c,C_word *av) C_noret;
C_noret_decl(f_6951)
static void C_ccall f_6951(C_word c,C_word *av) C_noret;
C_noret_decl(f_6954)
static void C_ccall f_6954(C_word c,C_word *av) C_noret;
C_noret_decl(f_6957)
static void C_ccall f_6957(C_word c,C_word *av) C_noret;
C_noret_decl(f_6960)
static void C_ccall f_6960(C_word c,C_word *av) C_noret;
C_noret_decl(f_6994)
static void C_fcall f_6994(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7004)
static void C_ccall f_7004(C_word c,C_word *av) C_noret;
C_noret_decl(f_7038)
static void C_ccall f_7038(C_word c,C_word *av) C_noret;
C_noret_decl(f_7041)
static void C_ccall f_7041(C_word c,C_word *av) C_noret;
C_noret_decl(f_7096)
static void C_fcall f_7096(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7153)
static void C_fcall f_7153(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7155)
static void C_fcall f_7155(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7166)
static void C_ccall f_7166(C_word c,C_word *av) C_noret;
C_noret_decl(f_7186)
static void C_ccall f_7186(C_word c,C_word *av) C_noret;
C_noret_decl(f_7189)
static void C_fcall f_7189(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7193)
static void C_ccall f_7193(C_word c,C_word *av) C_noret;
C_noret_decl(f_7196)
static void C_ccall f_7196(C_word c,C_word *av) C_noret;
C_noret_decl(f_7208)
static void C_fcall f_7208(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7233)
static void C_ccall f_7233(C_word c,C_word *av) C_noret;
C_noret_decl(f_7242)
static void C_fcall f_7242(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7248)
static void C_fcall f_7248(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7258)
static void C_ccall f_7258(C_word c,C_word *av) C_noret;
C_noret_decl(f_7270)
static void C_ccall f_7270(C_word c,C_word *av) C_noret;
C_noret_decl(f_7273)
static void C_ccall f_7273(C_word c,C_word *av) C_noret;
C_noret_decl(f_7276)
static void C_ccall f_7276(C_word c,C_word *av) C_noret;
C_noret_decl(f_7279)
static void C_ccall f_7279(C_word c,C_word *av) C_noret;
C_noret_decl(f_7282)
static void C_ccall f_7282(C_word c,C_word *av) C_noret;
C_noret_decl(f_7318)
static void C_ccall f_7318(C_word c,C_word *av) C_noret;
C_noret_decl(f_7325)
static void C_ccall f_7325(C_word c,C_word *av) C_noret;
C_noret_decl(f_7327)
static void C_fcall f_7327(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7337)
static void C_ccall f_7337(C_word c,C_word *av) C_noret;
C_noret_decl(f_7380)
static void C_ccall f_7380(C_word c,C_word *av) C_noret;
C_noret_decl(f_7385)
static void C_fcall f_7385(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7391)
static void C_fcall f_7391(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7403)
static void C_fcall f_7403(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7440)
static void C_fcall f_7440(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7446)
static void C_fcall f_7446(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7481)
static void C_ccall f_7481(C_word c,C_word *av) C_noret;
C_noret_decl(f_7493)
static void C_fcall f_7493(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7507)
static void C_ccall f_7507(C_word c,C_word *av) C_noret;
C_noret_decl(f_7528)
static void C_ccall f_7528(C_word c,C_word *av) C_noret;
C_noret_decl(f_7532)
static void C_ccall f_7532(C_word c,C_word *av) C_noret;
C_noret_decl(f_7536)
static void C_fcall f_7536(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7575)
static void C_ccall f_7575(C_word c,C_word *av) C_noret;
C_noret_decl(f_7583)
static void C_ccall f_7583(C_word c,C_word *av) C_noret;
C_noret_decl(f_7625)
static C_word C_fcall f_7625(C_word t0);
C_noret_decl(f_7661)
static void C_fcall f_7661(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7709)
static void C_ccall f_7709(C_word c,C_word *av) C_noret;
C_noret_decl(f_7718)
static void C_ccall f_7718(C_word c,C_word *av) C_noret;
C_noret_decl(f_7723)
static void C_ccall f_7723(C_word c,C_word *av) C_noret;
C_noret_decl(f_7729)
static void C_ccall f_7729(C_word c,C_word *av) C_noret;
C_noret_decl(f_7735)
static void C_ccall f_7735(C_word c,C_word *av) C_noret;
C_noret_decl(f_7741)
static void C_ccall f_7741(C_word c,C_word *av) C_noret;
C_noret_decl(f_7747)
static void C_ccall f_7747(C_word c,C_word *av) C_noret;
C_noret_decl(f_7753)
static void C_ccall f_7753(C_word c,C_word *av) C_noret;
C_noret_decl(f_7759)
static void C_ccall f_7759(C_word c,C_word *av) C_noret;
C_noret_decl(f_7780)
static void C_ccall f_7780(C_word c,C_word *av) C_noret;
C_noret_decl(f_7783)
static void C_ccall f_7783(C_word c,C_word *av) C_noret;
C_noret_decl(f_7786)
static void C_ccall f_7786(C_word c,C_word *av) C_noret;
C_noret_decl(f_7789)
static void C_ccall f_7789(C_word c,C_word *av) C_noret;
C_noret_decl(f_7792)
static void C_fcall f_7792(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7795)
static void C_ccall f_7795(C_word c,C_word *av) C_noret;
C_noret_decl(f_7798)
static void C_fcall f_7798(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7801)
static void C_ccall f_7801(C_word c,C_word *av) C_noret;
C_noret_decl(f_7806)
static void C_fcall f_7806(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7812)
static void C_fcall f_7812(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7820)
static void C_fcall f_7820(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7841)
static void C_ccall f_7841(C_word c,C_word *av) C_noret;
C_noret_decl(f_7857)
static void C_ccall f_7857(C_word c,C_word *av) C_noret;
C_noret_decl(f_7860)
static void C_ccall f_7860(C_word c,C_word *av) C_noret;
C_noret_decl(f_7863)
static void C_ccall f_7863(C_word c,C_word *av) C_noret;
C_noret_decl(f_7866)
static void C_ccall f_7866(C_word c,C_word *av) C_noret;
C_noret_decl(f_7872)
static void C_ccall f_7872(C_word c,C_word *av) C_noret;
C_noret_decl(f_7881)
static void C_ccall f_7881(C_word c,C_word *av) C_noret;
C_noret_decl(f_7903)
static void C_ccall f_7903(C_word c,C_word *av) C_noret;
C_noret_decl(f_7918)
static void C_fcall f_7918(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7925)
static void C_ccall f_7925(C_word c,C_word *av) C_noret;
C_noret_decl(f_7932)
static void C_ccall f_7932(C_word c,C_word *av) C_noret;
C_noret_decl(f_7934)
static void C_fcall f_7934(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7944)
static void C_ccall f_7944(C_word c,C_word *av) C_noret;
C_noret_decl(f_7951)
static void C_ccall f_7951(C_word c,C_word *av) C_noret;
C_noret_decl(f_7955)
static void C_ccall f_7955(C_word c,C_word *av) C_noret;
C_noret_decl(f_7957)
static void C_ccall f_7957(C_word c,C_word *av) C_noret;
C_noret_decl(f_7965)
static void C_ccall f_7965(C_word c,C_word *av) C_noret;
C_noret_decl(f_7975)
static void C_ccall f_7975(C_word c,C_word *av) C_noret;
C_noret_decl(f_7978)
static void C_ccall f_7978(C_word c,C_word *av) C_noret;
C_noret_decl(f_7981)
static void C_fcall f_7981(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7984)
static void C_ccall f_7984(C_word c,C_word *av) C_noret;
C_noret_decl(f_7987)
static void C_fcall f_7987(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7990)
static void C_ccall f_7990(C_word c,C_word *av) C_noret;
C_noret_decl(f_7993)
static void C_ccall f_7993(C_word c,C_word *av) C_noret;
C_noret_decl(f_7999)
static void C_ccall f_7999(C_word c,C_word *av) C_noret;
C_noret_decl(f_8002)
static void C_ccall f_8002(C_word c,C_word *av) C_noret;
C_noret_decl(f_8008)
static void C_ccall f_8008(C_word c,C_word *av) C_noret;
C_noret_decl(f_8011)
static void C_ccall f_8011(C_word c,C_word *av) C_noret;
C_noret_decl(f_8017)
static void C_ccall f_8017(C_word c,C_word *av) C_noret;
C_noret_decl(f_8021)
static void C_ccall f_8021(C_word c,C_word *av) C_noret;
C_noret_decl(f_8024)
static void C_ccall f_8024(C_word c,C_word *av) C_noret;
C_noret_decl(f_8027)
static void C_ccall f_8027(C_word c,C_word *av) C_noret;
C_noret_decl(f_8030)
static void C_ccall f_8030(C_word c,C_word *av) C_noret;
C_noret_decl(f_8033)
static void C_ccall f_8033(C_word c,C_word *av) C_noret;
C_noret_decl(f_8036)
static void C_ccall f_8036(C_word c,C_word *av) C_noret;
C_noret_decl(f_8039)
static void C_ccall f_8039(C_word c,C_word *av) C_noret;
C_noret_decl(f_8042)
static void C_ccall f_8042(C_word c,C_word *av) C_noret;
C_noret_decl(f_8045)
static void C_ccall f_8045(C_word c,C_word *av) C_noret;
C_noret_decl(f_8048)
static void C_fcall f_8048(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8053)
static void C_fcall f_8053(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8069)
static void C_ccall f_8069(C_word c,C_word *av) C_noret;
C_noret_decl(f_8081)
static void C_ccall f_8081(C_word c,C_word *av) C_noret;
C_noret_decl(f_8110)
static void C_ccall f_8110(C_word c,C_word *av) C_noret;
C_noret_decl(f_8122)
static void C_ccall f_8122(C_word c,C_word *av) C_noret;
C_noret_decl(f_8137)
static void C_ccall f_8137(C_word c,C_word *av) C_noret;
C_noret_decl(f_8156)
static void C_ccall f_8156(C_word c,C_word *av) C_noret;
C_noret_decl(f_8166)
static void C_ccall f_8166(C_word c,C_word *av) C_noret;
C_noret_decl(f_8181)
static void C_ccall f_8181(C_word c,C_word *av) C_noret;
C_noret_decl(f_8191)
static void C_ccall f_8191(C_word c,C_word *av) C_noret;
C_noret_decl(f_8201)
static void C_ccall f_8201(C_word c,C_word *av) C_noret;
C_noret_decl(f_8212)
static void C_ccall f_8212(C_word c,C_word *av) C_noret;
C_noret_decl(f_8216)
static void C_ccall f_8216(C_word c,C_word *av) C_noret;
C_noret_decl(f_8223)
static void C_ccall f_8223(C_word c,C_word *av) C_noret;
C_noret_decl(f_8225)
static void C_ccall f_8225(C_word c,C_word *av) C_noret;
C_noret_decl(f_8253)
static void C_ccall f_8253(C_word c,C_word *av) C_noret;
C_noret_decl(f_8257)
static void C_ccall f_8257(C_word c,C_word *av) C_noret;
C_noret_decl(f_8263)
static void C_ccall f_8263(C_word c,C_word *av) C_noret;
C_noret_decl(f_8266)
static void C_ccall f_8266(C_word c,C_word *av) C_noret;
C_noret_decl(f_8269)
static void C_ccall f_8269(C_word c,C_word *av) C_noret;
C_noret_decl(f_8272)
static void C_ccall f_8272(C_word c,C_word *av) C_noret;
C_noret_decl(f_8277)
static void C_fcall f_8277(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8290)
static void C_ccall f_8290(C_word c,C_word *av) C_noret;
C_noret_decl(f_8293)
static void C_ccall f_8293(C_word c,C_word *av) C_noret;
C_noret_decl(f_8308)
static void C_ccall f_8308(C_word c,C_word *av) C_noret;
C_noret_decl(f_8327)
static void C_ccall f_8327(C_word c,C_word *av) C_noret;
C_noret_decl(f_8339)
static void C_ccall f_8339(C_word c,C_word *av) C_noret;
C_noret_decl(f_8342)
static void C_ccall f_8342(C_word c,C_word *av) C_noret;
C_noret_decl(f_8356)
static void C_ccall f_8356(C_word c,C_word *av) C_noret;
C_noret_decl(f_8359)
static void C_ccall f_8359(C_word c,C_word *av) C_noret;
C_noret_decl(f_8362)
static void C_ccall f_8362(C_word c,C_word *av) C_noret;
C_noret_decl(f_8365)
static void C_ccall f_8365(C_word c,C_word *av) C_noret;
C_noret_decl(f_8368)
static void C_ccall f_8368(C_word c,C_word *av) C_noret;
C_noret_decl(f_8377)
static void C_ccall f_8377(C_word c,C_word *av) C_noret;
C_noret_decl(f_8380)
static void C_ccall f_8380(C_word c,C_word *av) C_noret;
C_noret_decl(f_8389)
static void C_ccall f_8389(C_word c,C_word *av) C_noret;
C_noret_decl(f_8392)
static void C_ccall f_8392(C_word c,C_word *av) C_noret;
C_noret_decl(f_8456)
static void C_ccall f_8456(C_word c,C_word *av) C_noret;
C_noret_decl(f_8463)
static void C_ccall f_8463(C_word c,C_word *av) C_noret;
C_noret_decl(f_8469)
static void C_ccall f_8469(C_word c,C_word *av) C_noret;
C_noret_decl(f_8476)
static void C_ccall f_8476(C_word c,C_word *av) C_noret;
C_noret_decl(f_8482)
static void C_ccall f_8482(C_word c,C_word *av) C_noret;
C_noret_decl(f_8484)
static void C_fcall f_8484(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8509)
static void C_ccall f_8509(C_word c,C_word *av) C_noret;
C_noret_decl(f_8518)
static void C_fcall f_8518(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8543)
static void C_ccall f_8543(C_word c,C_word *av) C_noret;
C_noret_decl(f_8552)
static void C_fcall f_8552(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8562)
static void C_ccall f_8562(C_word c,C_word *av) C_noret;
C_noret_decl(f_8575)
static void C_fcall f_8575(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8585)
static void C_ccall f_8585(C_word c,C_word *av) C_noret;
C_noret_decl(f_8598)
static void C_fcall f_8598(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8608)
static void C_ccall f_8608(C_word c,C_word *av) C_noret;
C_noret_decl(f_8622)
static void C_ccall f_8622(C_word c,C_word *av) C_noret;
C_noret_decl(f_8625)
static void C_ccall f_8625(C_word c,C_word *av) C_noret;
C_noret_decl(f_8628)
static void C_ccall f_8628(C_word c,C_word *av) C_noret;
C_noret_decl(f_8637)
static void C_ccall f_8637(C_word c,C_word *av) C_noret;
C_noret_decl(f_8640)
static void C_ccall f_8640(C_word c,C_word *av) C_noret;
C_noret_decl(f_8650)
static void C_ccall f_8650(C_word c,C_word *av) C_noret;
C_noret_decl(f_8657)
static void C_ccall f_8657(C_word c,C_word *av) C_noret;
C_noret_decl(f_8667)
static void C_ccall f_8667(C_word c,C_word *av) C_noret;
C_noret_decl(f_8673)
static void C_ccall f_8673(C_word c,C_word *av) C_noret;
C_noret_decl(f_8676)
static void C_ccall f_8676(C_word c,C_word *av) C_noret;
C_noret_decl(f_8685)
static void C_ccall f_8685(C_word c,C_word *av) C_noret;
C_noret_decl(f_8691)
static void C_ccall f_8691(C_word c,C_word *av) C_noret;
C_noret_decl(f_8694)
static void C_ccall f_8694(C_word c,C_word *av) C_noret;
C_noret_decl(f_8697)
static void C_ccall f_8697(C_word c,C_word *av) C_noret;
C_noret_decl(f_8700)
static void C_ccall f_8700(C_word c,C_word *av) C_noret;
C_noret_decl(f_8709)
static void C_ccall f_8709(C_word c,C_word *av) C_noret;
C_noret_decl(f_8774)
static void C_ccall f_8774(C_word c,C_word *av) C_noret;
C_noret_decl(f_8787)
static void C_ccall f_8787(C_word c,C_word *av) C_noret;
C_noret_decl(f_8791)
static void C_ccall f_8791(C_word c,C_word *av) C_noret;
C_noret_decl(f_8795)
static void C_ccall f_8795(C_word c,C_word *av) C_noret;
C_noret_decl(f_8801)
static void C_ccall f_8801(C_word c,C_word *av) C_noret;
C_noret_decl(f_8807)
static void C_ccall f_8807(C_word c,C_word *av) C_noret;
C_noret_decl(f_8809)
static void C_ccall f_8809(C_word c,C_word *av) C_noret;
C_noret_decl(f_8815)
static void C_ccall f_8815(C_word c,C_word *av) C_noret;
C_noret_decl(f_8819)
static void C_ccall f_8819(C_word c,C_word *av) C_noret;
C_noret_decl(f_8828)
static void C_ccall f_8828(C_word c,C_word *av) C_noret;
C_noret_decl(f_8834)
static void C_ccall f_8834(C_word c,C_word *av) C_noret;
C_noret_decl(f_8838)
static void C_fcall f_8838(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8842)
static void C_ccall f_8842(C_word c,C_word *av) C_noret;
C_noret_decl(f_8855)
static void C_ccall f_8855(C_word c,C_word *av) C_noret;
C_noret_decl(f_8857)
static void C_ccall f_8857(C_word c,C_word *av) C_noret;
C_noret_decl(f_8865)
static void C_ccall f_8865(C_word c,C_word *av) C_noret;
C_noret_decl(f_8868)
static void C_ccall f_8868(C_word c,C_word *av) C_noret;
C_noret_decl(f_8875)
static void C_ccall f_8875(C_word c,C_word *av) C_noret;
C_noret_decl(f_8879)
static void C_ccall f_8879(C_word c,C_word *av) C_noret;
C_noret_decl(f_8888)
static void C_ccall f_8888(C_word c,C_word *av) C_noret;
C_noret_decl(f_8890)
static void C_ccall f_8890(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_3060)
static void C_ccall trf_3060(C_word c,C_word *av) C_noret;
static void C_ccall trf_3060(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3060(t0,t1,t2);}

C_noret_decl(trf_3135)
static void C_ccall trf_3135(C_word c,C_word *av) C_noret;
static void C_ccall trf_3135(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3135(t0,t1,t2);}

C_noret_decl(trf_3860)
static void C_ccall trf_3860(C_word c,C_word *av) C_noret;
static void C_ccall trf_3860(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3860(t0,t1);}

C_noret_decl(trf_3961)
static void C_ccall trf_3961(C_word c,C_word *av) C_noret;
static void C_ccall trf_3961(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3961(t0,t1);}

C_noret_decl(trf_3990)
static void C_ccall trf_3990(C_word c,C_word *av) C_noret;
static void C_ccall trf_3990(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3990(t0,t1,t2);}

C_noret_decl(trf_4012)
static void C_ccall trf_4012(C_word c,C_word *av) C_noret;
static void C_ccall trf_4012(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4012(t0,t1,t2);}

C_noret_decl(trf_4069)
static void C_ccall trf_4069(C_word c,C_word *av) C_noret;
static void C_ccall trf_4069(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4069(t0,t1,t2);}

C_noret_decl(trf_4119)
static void C_ccall trf_4119(C_word c,C_word *av) C_noret;
static void C_ccall trf_4119(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4119(t0,t1,t2);}

C_noret_decl(trf_4129)
static void C_ccall trf_4129(C_word c,C_word *av) C_noret;
static void C_ccall trf_4129(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4129(t0,t1);}

C_noret_decl(trf_4174)
static void C_ccall trf_4174(C_word c,C_word *av) C_noret;
static void C_ccall trf_4174(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4174(t0,t1,t2);}

C_noret_decl(trf_4218)
static void C_ccall trf_4218(C_word c,C_word *av) C_noret;
static void C_ccall trf_4218(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4218(t0,t1);}

C_noret_decl(trf_4530)
static void C_ccall trf_4530(C_word c,C_word *av) C_noret;
static void C_ccall trf_4530(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4530(t0,t1,t2);}

C_noret_decl(trf_4565)
static void C_ccall trf_4565(C_word c,C_word *av) C_noret;
static void C_ccall trf_4565(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4565(t0,t1,t2);}

C_noret_decl(trf_4586)
static void C_ccall trf_4586(C_word c,C_word *av) C_noret;
static void C_ccall trf_4586(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4586(t0,t1,t2);}

C_noret_decl(trf_4837)
static void C_ccall trf_4837(C_word c,C_word *av) C_noret;
static void C_ccall trf_4837(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4837(t0,t1,t2);}

C_noret_decl(trf_4973)
static void C_ccall trf_4973(C_word c,C_word *av) C_noret;
static void C_ccall trf_4973(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_4973(t0,t1,t2);}

C_noret_decl(trf_4983)
static void C_ccall trf_4983(C_word c,C_word *av) C_noret;
static void C_ccall trf_4983(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_4983(t0,t1);}

C_noret_decl(trf_5041)
static void C_ccall trf_5041(C_word c,C_word *av) C_noret;
static void C_ccall trf_5041(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5041(t0,t1,t2,t3);}

C_noret_decl(trf_5079)
static void C_ccall trf_5079(C_word c,C_word *av) C_noret;
static void C_ccall trf_5079(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5079(t0,t1,t2);}

C_noret_decl(trf_5101)
static void C_ccall trf_5101(C_word c,C_word *av) C_noret;
static void C_ccall trf_5101(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5101(t0,t1);}

C_noret_decl(trf_5121)
static void C_ccall trf_5121(C_word c,C_word *av) C_noret;
static void C_ccall trf_5121(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5121(t0,t1,t2);}

C_noret_decl(trf_5135)
static void C_ccall trf_5135(C_word c,C_word *av) C_noret;
static void C_ccall trf_5135(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5135(t0,t1);}

C_noret_decl(trf_5258)
static void C_ccall trf_5258(C_word c,C_word *av) C_noret;
static void C_ccall trf_5258(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5258(t0,t1,t2);}

C_noret_decl(trf_5291)
static void C_ccall trf_5291(C_word c,C_word *av) C_noret;
static void C_ccall trf_5291(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5291(t0,t1,t2);}

C_noret_decl(trf_5403)
static void C_ccall trf_5403(C_word c,C_word *av) C_noret;
static void C_ccall trf_5403(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5403(t0,t1,t2,t3);}

C_noret_decl(trf_5421)
static void C_ccall trf_5421(C_word c,C_word *av) C_noret;
static void C_ccall trf_5421(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5421(t0,t1,t2);}

C_noret_decl(trf_5453)
static void C_ccall trf_5453(C_word c,C_word *av) C_noret;
static void C_ccall trf_5453(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5453(t0,t1,t2,t3);}

C_noret_decl(trf_5749)
static void C_ccall trf_5749(C_word c,C_word *av) C_noret;
static void C_ccall trf_5749(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5749(t0,t1,t2);}

C_noret_decl(trf_5812)
static void C_ccall trf_5812(C_word c,C_word *av) C_noret;
static void C_ccall trf_5812(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_5812(t0,t1);}

C_noret_decl(trf_5824)
static void C_ccall trf_5824(C_word c,C_word *av) C_noret;
static void C_ccall trf_5824(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5824(t0,t1,t2,t3);}

C_noret_decl(trf_6141)
static void C_ccall trf_6141(C_word c,C_word *av) C_noret;
static void C_ccall trf_6141(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6141(t0,t1,t2);}

C_noret_decl(trf_6149)
static void C_ccall trf_6149(C_word c,C_word *av) C_noret;
static void C_ccall trf_6149(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6149(t0,t1,t2);}

C_noret_decl(trf_6179)
static void C_ccall trf_6179(C_word c,C_word *av) C_noret;
static void C_ccall trf_6179(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6179(t0,t1,t2);}

C_noret_decl(trf_6225)
static void C_ccall trf_6225(C_word c,C_word *av) C_noret;
static void C_ccall trf_6225(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6225(t0,t1,t2);}

C_noret_decl(trf_6238)
static void C_ccall trf_6238(C_word c,C_word *av) C_noret;
static void C_ccall trf_6238(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6238(t0,t1,t2);}

C_noret_decl(trf_6293)
static void C_ccall trf_6293(C_word c,C_word *av) C_noret;
static void C_ccall trf_6293(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6293(t0,t1,t2);}

C_noret_decl(trf_6334)
static void C_ccall trf_6334(C_word c,C_word *av) C_noret;
static void C_ccall trf_6334(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6334(t0,t1,t2);}

C_noret_decl(trf_6348)
static void C_ccall trf_6348(C_word c,C_word *av) C_noret;
static void C_ccall trf_6348(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6348(t0,t1,t2);}

C_noret_decl(trf_6375)
static void C_ccall trf_6375(C_word c,C_word *av) C_noret;
static void C_ccall trf_6375(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6375(t0,t1,t2);}

C_noret_decl(trf_6458)
static void C_ccall trf_6458(C_word c,C_word *av) C_noret;
static void C_ccall trf_6458(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6458(t0,t1,t2);}

C_noret_decl(trf_6460)
static void C_ccall trf_6460(C_word c,C_word *av) C_noret;
static void C_ccall trf_6460(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6460(t0,t1,t2,t3);}

C_noret_decl(trf_6463)
static void C_ccall trf_6463(C_word c,C_word *av) C_noret;
static void C_ccall trf_6463(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6463(t0,t1,t2);}

C_noret_decl(trf_6566)
static void C_ccall trf_6566(C_word c,C_word *av) C_noret;
static void C_ccall trf_6566(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6566(t0,t1,t2);}

C_noret_decl(trf_6571)
static void C_ccall trf_6571(C_word c,C_word *av) C_noret;
static void C_ccall trf_6571(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6571(t0,t1);}

C_noret_decl(trf_6606)
static void C_ccall trf_6606(C_word c,C_word *av) C_noret;
static void C_ccall trf_6606(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_6606(t0,t1,t2,t3,t4);}

C_noret_decl(trf_6609)
static void C_ccall trf_6609(C_word c,C_word *av) C_noret;
static void C_ccall trf_6609(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_6609(t0,t1,t2,t3,t4);}

C_noret_decl(trf_6641)
static void C_ccall trf_6641(C_word c,C_word *av) C_noret;
static void C_ccall trf_6641(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6641(t0,t1,t2);}

C_noret_decl(trf_6675)
static void C_ccall trf_6675(C_word c,C_word *av) C_noret;
static void C_ccall trf_6675(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6675(t0,t1,t2,t3);}

C_noret_decl(trf_6726)
static void C_ccall trf_6726(C_word c,C_word *av) C_noret;
static void C_ccall trf_6726(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6726(t0,t1,t2,t3);}

C_noret_decl(trf_6760)
static void C_ccall trf_6760(C_word c,C_word *av) C_noret;
static void C_ccall trf_6760(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6760(t0,t1,t2);}

C_noret_decl(trf_6811)
static void C_ccall trf_6811(C_word c,C_word *av) C_noret;
static void C_ccall trf_6811(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6811(t0,t1);}

C_noret_decl(trf_6814)
static void C_ccall trf_6814(C_word c,C_word *av) C_noret;
static void C_ccall trf_6814(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6814(t0,t1);}

C_noret_decl(trf_6837)
static void C_ccall trf_6837(C_word c,C_word *av) C_noret;
static void C_ccall trf_6837(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6837(t0,t1);}

C_noret_decl(trf_6846)
static void C_ccall trf_6846(C_word c,C_word *av) C_noret;
static void C_ccall trf_6846(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6846(t0,t1,t2,t3);}

C_noret_decl(trf_6920)
static void C_ccall trf_6920(C_word c,C_word *av) C_noret;
static void C_ccall trf_6920(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6920(t0,t1,t2,t3);}

C_noret_decl(trf_6935)
static void C_ccall trf_6935(C_word c,C_word *av) C_noret;
static void C_ccall trf_6935(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6935(t0,t1,t2,t3);}

C_noret_decl(trf_6994)
static void C_ccall trf_6994(C_word c,C_word *av) C_noret;
static void C_ccall trf_6994(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6994(t0,t1,t2,t3);}

C_noret_decl(trf_7096)
static void C_ccall trf_7096(C_word c,C_word *av) C_noret;
static void C_ccall trf_7096(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7096(t0,t1);}

C_noret_decl(trf_7153)
static void C_ccall trf_7153(C_word c,C_word *av) C_noret;
static void C_ccall trf_7153(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7153(t0,t1);}

C_noret_decl(trf_7155)
static void C_ccall trf_7155(C_word c,C_word *av) C_noret;
static void C_ccall trf_7155(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7155(t0,t1,t2);}

C_noret_decl(trf_7189)
static void C_ccall trf_7189(C_word c,C_word *av) C_noret;
static void C_ccall trf_7189(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7189(t0,t1,t2);}

C_noret_decl(trf_7208)
static void C_ccall trf_7208(C_word c,C_word *av) C_noret;
static void C_ccall trf_7208(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7208(t0,t1,t2);}

C_noret_decl(trf_7242)
static void C_ccall trf_7242(C_word c,C_word *av) C_noret;
static void C_ccall trf_7242(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7242(t0,t1,t2,t3);}

C_noret_decl(trf_7248)
static void C_ccall trf_7248(C_word c,C_word *av) C_noret;
static void C_ccall trf_7248(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7248(t0,t1,t2,t3);}

C_noret_decl(trf_7327)
static void C_ccall trf_7327(C_word c,C_word *av) C_noret;
static void C_ccall trf_7327(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7327(t0,t1,t2,t3);}

C_noret_decl(trf_7385)
static void C_ccall trf_7385(C_word c,C_word *av) C_noret;
static void C_ccall trf_7385(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7385(t0,t1,t2);}

C_noret_decl(trf_7391)
static void C_ccall trf_7391(C_word c,C_word *av) C_noret;
static void C_ccall trf_7391(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7391(t0,t1,t2);}

C_noret_decl(trf_7403)
static void C_ccall trf_7403(C_word c,C_word *av) C_noret;
static void C_ccall trf_7403(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7403(t0,t1,t2);}

C_noret_decl(trf_7440)
static void C_ccall trf_7440(C_word c,C_word *av) C_noret;
static void C_ccall trf_7440(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7440(t0,t1);}

C_noret_decl(trf_7446)
static void C_ccall trf_7446(C_word c,C_word *av) C_noret;
static void C_ccall trf_7446(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7446(t0,t1,t2);}

C_noret_decl(trf_7493)
static void C_ccall trf_7493(C_word c,C_word *av) C_noret;
static void C_ccall trf_7493(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7493(t0,t1);}

C_noret_decl(trf_7536)
static void C_ccall trf_7536(C_word c,C_word *av) C_noret;
static void C_ccall trf_7536(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7536(t0,t1,t2);}

C_noret_decl(trf_7661)
static void C_ccall trf_7661(C_word c,C_word *av) C_noret;
static void C_ccall trf_7661(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7661(t0,t1,t2,t3);}

C_noret_decl(trf_7792)
static void C_ccall trf_7792(C_word c,C_word *av) C_noret;
static void C_ccall trf_7792(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7792(t0,t1);}

C_noret_decl(trf_7798)
static void C_ccall trf_7798(C_word c,C_word *av) C_noret;
static void C_ccall trf_7798(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7798(t0,t1);}

C_noret_decl(trf_7806)
static void C_ccall trf_7806(C_word c,C_word *av) C_noret;
static void C_ccall trf_7806(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7806(t0,t1,t2);}

C_noret_decl(trf_7812)
static void C_ccall trf_7812(C_word c,C_word *av) C_noret;
static void C_ccall trf_7812(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7812(t0,t1,t2);}

C_noret_decl(trf_7820)
static void C_ccall trf_7820(C_word c,C_word *av) C_noret;
static void C_ccall trf_7820(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7820(t0,t1,t2);}

C_noret_decl(trf_7918)
static void C_ccall trf_7918(C_word c,C_word *av) C_noret;
static void C_ccall trf_7918(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7918(t0,t1,t2);}

C_noret_decl(trf_7934)
static void C_ccall trf_7934(C_word c,C_word *av) C_noret;
static void C_ccall trf_7934(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7934(t0,t1,t2);}

C_noret_decl(trf_7981)
static void C_ccall trf_7981(C_word c,C_word *av) C_noret;
static void C_ccall trf_7981(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7981(t0,t1);}

C_noret_decl(trf_7987)
static void C_ccall trf_7987(C_word c,C_word *av) C_noret;
static void C_ccall trf_7987(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7987(t0,t1);}

C_noret_decl(trf_8048)
static void C_ccall trf_8048(C_word c,C_word *av) C_noret;
static void C_ccall trf_8048(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8048(t0,t1);}

C_noret_decl(trf_8053)
static void C_ccall trf_8053(C_word c,C_word *av) C_noret;
static void C_ccall trf_8053(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8053(t0,t1,t2);}

C_noret_decl(trf_8277)
static void C_ccall trf_8277(C_word c,C_word *av) C_noret;
static void C_ccall trf_8277(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8277(t0,t1,t2);}

C_noret_decl(trf_8484)
static void C_ccall trf_8484(C_word c,C_word *av) C_noret;
static void C_ccall trf_8484(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8484(t0,t1,t2);}

C_noret_decl(trf_8518)
static void C_ccall trf_8518(C_word c,C_word *av) C_noret;
static void C_ccall trf_8518(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8518(t0,t1,t2);}

C_noret_decl(trf_8552)
static void C_ccall trf_8552(C_word c,C_word *av) C_noret;
static void C_ccall trf_8552(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8552(t0,t1,t2);}

C_noret_decl(trf_8575)
static void C_ccall trf_8575(C_word c,C_word *av) C_noret;
static void C_ccall trf_8575(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8575(t0,t1,t2);}

C_noret_decl(trf_8598)
static void C_ccall trf_8598(C_word c,C_word *av) C_noret;
static void C_ccall trf_8598(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8598(t0,t1,t2);}

C_noret_decl(trf_8838)
static void C_ccall trf_8838(C_word c,C_word *av) C_noret;
static void C_ccall trf_8838(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8838(t0,t1,t2);}

/* f9525 in k4708 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f9525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f9525,c,av);}
/* csi.scm:347: scheme#string-append */
t2=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[78];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* f9529 in k4708 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f9529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f9529,c,av);}
/* csi.scm:347: scheme#string-append */
t2=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_retrieve2(lf[9],C_text("chicken.csi#default-editor"));
av2[3]=lf[78];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* f9650 in k8337 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in ... */
static void C_ccall f9650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f9650,c,av);}
/* csi.scm:144: chicken.base#print */
t2=*((C_word*)lf[105]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[321];
av2[3]=t1;
av2[4]=lf[322];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* f9676 in k8620 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in ... */
static void C_ccall f9676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f9676,c,av);}
/* csi.scm:1068: chicken.base#case-sensitive */
t2=C_fast_retrieve(lf[331]);{
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

/* f9680 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f9680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f9680,c,av);}
/* csi.scm:144: chicken.base#print */
t2=*((C_word*)lf[105]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[321];
av2[3]=t1;
av2[4]=lf[322];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k2527 */
static void C_ccall f_2529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2529,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2532,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k2530 in k2527 */
static void C_ccall f_2532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_2532,c,av);}
a=C_alloc(13);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2535,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8890,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:43: ##sys#with-environment */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[406]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[406]+1);
av2[1]=t3;
av2[2]=t4;
tp(3,av2);}}

/* k2533 in k2530 in k2527 */
static void C_ccall f_2535(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2535,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2538,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2538,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2541,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2541,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2544,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2544,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2547,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2547(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2547,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2550,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

/* k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2550(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2550,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2553,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_posix_toplevel(2,av2);}}

/* k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2553,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2556,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_repl_toplevel(2,av2);}}

/* k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2556,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2559,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2559(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2559,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2562,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_2562(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_2562,c,av);}
a=C_alloc(6);
t2=C_mutate(&lf[1] /* (set! chicken.csi#constant701 ...) */,lf[2]);
t3=C_set_block_item(lf[3] /* ##sys#repl-print-length-limit */,0,C_fix(2048));
t4=C_a_i_cons(&a,2,lf[4],C_fast_retrieve(lf[5]));
t5=C_mutate((C_word*)lf[5]+1 /* (set! ##sys#features ...) */,t4);
t6=C_set_block_item(lf[6] /* ##sys#notices-enabled */,0,C_SCHEME_TRUE);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3852,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:81: chicken.base#make-parameter */
t8=C_fast_retrieve(lf[402]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* loop in loop in k8454 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_fcall f_3060(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3060,3,t0,t1,t2);}
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
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3087,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:109: loop */
t7=t5;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}}}

/* k3085 in loop in loop in k8454 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in ... */
static void C_ccall f_3087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3087,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k8454 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in ... */
static void C_fcall f_3135(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3135,3,t0,t1,t2);}
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
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3149,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3162,a[2]=((C_word*)t0)[2],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3060,a[2]=t3,a[3]=t8,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_3060(t10,t6,t4);}}

/* k3147 in loop in k8454 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_ccall f_3149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3149,c,av);}
a=C_alloc(3);
t2=C_i_equalp(((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?((C_word*)t0)[4]:C_a_i_cons(&a,2,((C_word*)t0)[5],t1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3160 in loop in k8454 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_ccall f_3162(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3162,c,av);}
/* mini-srfi-1.scm:123: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3135(t2,((C_word*)t0)[3],t1);}

/* k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3852,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[7]+1 /* (set! chicken.csi#editor-command ...) */,t1);
t3=lf[8] /* chicken.csi#selected-frame */ =C_SCHEME_FALSE;;
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3857,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:85: chicken.process-context#get-environment-variable */
t5=C_fast_retrieve(lf[23]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[401];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3857,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3860,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=t2;
f_3860(t3,t1);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8879,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:86: chicken.process-context#get-environment-variable */
t4=C_fast_retrieve(lf[23]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[400];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_3860(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_3860,2,t0,t1);}
a=C_alloc(7);
t2=C_mutate(&lf[9] /* (set! chicken.csi#default-editor ...) */,t1);
t3=C_mutate(&lf[10] /* (set! chicken.csi#dirseparator? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3900,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate(&lf[12] /* (set! chicken.csi#chop-separator ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3915,tmp=(C_word)a,a+=2,tmp));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3942,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[396]);
C_word av2[4];
av2[0]=*((C_word*)lf[396]+1);
av2[1]=t5;
av2[2]=C_fix(256);
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k3864 in k8671 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_3866(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_3866,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3869,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3876,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,lf[360],C_SCHEME_END_OF_LIST);
t5=C_a_i_cons(&a,2,C_retrieve2(lf[1],C_text("chicken.csi#constant701")),t4);
t6=C_a_i_cons(&a,2,lf[361],t5);
/* csi.scm:43: ##sys#print-to-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[362]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[362]+1);
av2[1]=t3;
av2[2]=t6;
tp(3,av2);}}

/* k3867 in k3864 in k8671 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_3869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3869,c,av);}
/* csi.scm:121: scheme#display */
t2=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[359];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k3874 in k3864 in k8671 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_3876(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3876,c,av);}
/* csi.scm:116: scheme#display */
t2=*((C_word*)lf[92]+1);{
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

/* chicken.csi#dirseparator? in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3900,c,av);}
if(C_truep(*((C_word*)lf[11]+1))){
t3=C_i_char_equalp(t2,C_make_character(92));
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?t3:C_i_char_equalp(t2,C_make_character(47)));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_char_equalp(t2,C_make_character(47));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.csi#chop-separator in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3915(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_3915,c,av);}
a=C_alloc(10);
t3=C_block_size(t2);
t4=C_a_i_fixnum_difference(&a,2,t3,C_fix(1));
t5=C_i_string_ref(t2,t4);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3929,a[2]=t1,a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_fixnum_greaterp(t4,C_fix(0)))){
/* csi.scm:158: dirseparator? */
t7=C_retrieve2(lf[10],C_text("chicken.csi#dirseparator\077"));{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t5;
f_3900(3,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k3927 in chicken.csi#chop-separator in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3929,c,av);}
if(C_truep(t1)){
/* csi.scm:159: substring */
t2=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3942(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(49,c,3)))){
C_save_and_reclaim((void *)f_3942,c,av);}
a=C_alloc(49);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_3961,tmp=(C_word)a,a+=2,tmp);
t3=C_mutate(&lf[17] /* (set! chicken.csi#lookup-script-file ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4012,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp));
t4=C_SCHEME_UNDEFINED;
t5=C_a_i_vector(&a,32,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4,t4);
t6=C_mutate(&lf[25] /* (set! chicken.csi#history-list ...) */,t5);
t7=lf[26] /* chicken.csi#history-count */ =C_fix(1);;
t8=C_fast_retrieve(lf[27]);
t9=C_mutate(&lf[28] /* (set! chicken.csi#history-add ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4119,a[2]=t8,tmp=(C_word)a,a+=3,tmp));
t10=C_mutate(&lf[30] /* (set! chicken.csi#history-ref ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4218,tmp=(C_word)a,a+=2,tmp));
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4285,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t12=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8857,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:246: chicken.repl#repl-prompt */
t13=C_fast_retrieve(lf[395]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t13;
av2[1]=t11;
av2[2]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}

/* addext in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_3961(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3961,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3968,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:169: chicken.file#file-exists? */
t4=C_fast_retrieve(lf[14]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3966 in addext in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_3968,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3971,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[16];
tp(4,av2);}}}

/* k3969 in k3966 in addext in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3971,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3977,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:172: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[14]);{
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

/* k3975 in k3969 in k3966 in addext in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_3977(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3977,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?((C_word*)t0)[3]:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_3990(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_3990,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4003,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:177: proc */
t4=C_retrieve2(lf[10],C_text("chicken.csi#dirseparator\077"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_subchar(((C_word*)t0)[4],t2);
f_3900(3,av2);}}}

/* k4001 in loop in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4003,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* csi.scm:178: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_3990(t2,((C_word*)t0)[2],C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}}

/* chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4012(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_4012,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4016,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:180: chicken.process-context#get-environment-variable */
t4=C_fast_retrieve(lf[23]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[24];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4016(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4016,c,av);}
a=C_alloc(7);
t2=C_block_size(((C_word*)t0)[2]);
if(C_truep(C_fixnum_greaterp(t2,C_fix(0)))){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4028,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* csi.scm:182: dirseparator? */
t4=C_retrieve2(lf[10],C_text("chicken.csi#dirseparator\077"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_string_ref(((C_word*)t0)[2],C_fix(0));
f_3900(3,av2);}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4028(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4028,c,av);}
a=C_alloc(14);
if(C_truep(t1)){
/* csi.scm:182: addext */
f_3961(((C_word*)t0)[3],((C_word*)t0)[4]);}
else{
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_4037,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=C_retrieve2(lf[10],C_text("chicken.csi#dirseparator\077"));
t4=C_block_size(((C_word*)t0)[4]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3990,a[2]=t4,a[3]=t6,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_3990(t8,t2,C_fix(0));}}

/* k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4037(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_4037,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4040,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_bytevector(&a,1,C_fix(3));
t4=(C_truep(((C_word*)t0)[5])?C_i_foreign_block_argumentp(((C_word*)t0)[5]):C_SCHEME_FALSE);
t5=C_fix(256);
/* csi.scm:167: ##sys#peek-nonnull-c-string */
t6=*((C_word*)lf[20]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=t2;
av2[2]=stub733(t3,t4,t5);
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4054,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:186: addext */
f_3961(t2,((C_word*)t0)[4]);}}

/* k4038 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_4040,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4047,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4051,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:185: chop-separator */
t4=C_retrieve2(lf[12],C_text("chicken.csi#chop-separator"));{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
f_3915(3,av2);}}

/* k4045 in k4038 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4047(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4047,c,av);}
/* csi.scm:185: addext */
f_3961(((C_word*)t0)[3],t1);}

/* k4049 in k4038 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4051(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4051,c,av);}
/* csi.scm:185: scheme#string-append */
t2=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[19];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4054,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4060,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t2;
av2[2]=lf[22];
av2[3]=((C_word*)t0)[5];
tp(4,av2);}}}

/* k4058 in k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4060(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4060,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4067,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:189: ##sys#split-path */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[21]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[21]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k4065 in k4058 in k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_4067(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4067,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4069,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_4069(t5,((C_word*)t0)[4],t1);}

/* loop in k4065 in k4058 in k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_fcall f_4069(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_4069,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4079,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4096,a[2]=t3,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:191: chop-separator */
t5=C_retrieve2(lf[12],C_text("chicken.csi#chop-separator"));{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_slot(t2,C_fix(0));
f_3915(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4077 in loop in k4065 in k4058 in k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_4079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4079,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4082,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:192: addext */
f_3961(t2,t1);}

/* k4080 in k4077 in loop in k4065 in k4058 in k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_4082(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4082,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* csi.scm:193: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_4069(t2,((C_word*)t0)[2],C_slot(((C_word*)t0)[4],C_fix(1)));}}

/* k4094 in loop in k4065 in k4058 in k4052 in k4035 in k4026 in k4014 in chicken.csi#lookup-script-file in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_4096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4096,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* chicken.csi#history-add in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4119(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_4119,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_i_nullp(t2);
t4=(C_truep(t3)?*((C_word*)lf[29]+1):C_slot(t2,C_fix(0)));
t5=C_block_size(C_retrieve2(lf[25],C_text("chicken.csi#history-list")));
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4129,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(C_retrieve2(lf[26],C_text("chicken.csi#history-count")),t5))){
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4143,a[2]=t6,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:208: vector-resize */
t8=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_retrieve2(lf[25],C_text("chicken.csi#history-list"));
av2[3]=C_fixnum_times(C_fix(2),t5);
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
t7=t6;
f_4129(t7,C_SCHEME_UNDEFINED);}}

/* k4127 in chicken.csi#history-add in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4129(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,1)))){
C_save_and_reclaim_args((void *)trf_4129,2,t0,t1);}
t2=C_i_vector_set(C_retrieve2(lf[25],C_text("chicken.csi#history-list")),C_retrieve2(lf[26],C_text("chicken.csi#history-count")),((C_word*)t0)[2]);
t3=C_fixnum_plus(C_retrieve2(lf[26],C_text("chicken.csi#history-count")),C_fix(1));
t4=lf[26] /* chicken.csi#history-count */ =t3;;
t5=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k4141 in chicken.csi#history-add in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4143(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4143,c,av);}
t2=C_mutate(&lf[25] /* (set! chicken.csi#history-list ...) */,t1);
t3=((C_word*)t0)[2];
f_4129(t3,t2);}

/* doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4174(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_4174,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_greater_or_equalp(t2,C_retrieve2(lf[26],C_text("chicken.csi#history-count"))))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=*((C_word*)lf[82]+1);
t4=*((C_word*)lf[82]+1);
t5=C_i_check_port_2(*((C_word*)lf[82]+1),C_fix(2),C_SCHEME_TRUE,lf[83]);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4187,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:221: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word av2[4];
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t6;
av2[2]=C_make_character(35);
av2[3]=*((C_word*)lf[82]+1);
tp(4,av2);}}}

/* k4185 in doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4187(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_4187,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4190,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:221: ##sys#print */
t3=*((C_word*)lf[85]+1);{
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
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4188 in k4185 in doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4190(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_4190,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4193,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:221: ##sys#print */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[87];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k4191 in k4188 in k4185 in doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4193(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4193,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4196,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4208,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:222: ##sys#with-print-length-limit */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[86]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[86]+1);
av2[1]=t2;
av2[2]=C_fix(80);
av2[3]=t3;
tp(4,av2);}}

/* k4194 in k4191 in k4188 in k4185 in doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_4196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4196,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4199,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:226: newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4197 in k4194 in k4191 in k4188 in k4185 in doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_4199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4199,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4174(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* a4207 in k4191 in k4188 in k4185 in doloop790 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_4208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_4208,c,av);}
/* csi.scm:225: ##sys#print */
t2=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=C_i_vector_ref(C_retrieve2(lf[25],C_text("chicken.csi#history-list")),((C_word*)t0)[2]);
av2[3]=C_SCHEME_TRUE;
av2[4]=*((C_word*)lf[82]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.csi#history-ref in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4218(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_4218,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4222,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:229: scheme#inexact->exact */
t4=*((C_word*)lf[33]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4220 in chicken.csi#history-ref in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4222,c,av);}
t2=C_fixnum_greaterp(t1,C_fix(0));
t3=(C_truep(t2)?C_fixnum_less_or_equal_p(t1,C_retrieve2(lf[26],C_text("chicken.csi#history-count"))):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_vector_ref(C_retrieve2(lf[25],C_text("chicken.csi#history-list")),t1);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* csi.scm:232: ##sys#error */
t4=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[32];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* ##sys#user-read-hook in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_4245(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4245,c,av);}
a=C_alloc(3);
t4=C_i_char_equalp(C_make_character(41),t2);
t5=(C_truep(t4)?t4:C_u_i_char_whitespacep(t2));
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4262,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:241: history-ref */
f_4218(t6,C_fixnum_difference(C_retrieve2(lf[26],C_text("chicken.csi#history-count")),C_fix(1)));}
else{
/* csi.scm:242: old-hook */
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}}

/* k4260 in ##sys#user-read-hook in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_4262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4262,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,lf[275],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#sharp-number-hook in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_4274(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4274,c,av);}
a=C_alloc(3);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4282,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:244: history-ref */
f_4218(t4,t3);}

/* k4280 in ##sys#sharp-number-hook in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_4282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_4282,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,lf[275],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4285(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,4)))){
C_save_and_reclaim((void *)f_4285,c,av);}
a=C_alloc(18);
t2=C_fast_retrieve(lf[34]);
t3=C_mutate((C_word*)lf[34]+1 /* (set! ##sys#read-prompt-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4296,a[2]=t2,tmp=(C_word)a,a+=3,tmp));
t4=lf[37] /* chicken.csi#command-table */ =C_SCHEME_END_OF_LIST;;
t5=C_mutate((C_word*)lf[38]+1 /* (set! chicken.csi#toplevel-command ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4309,tmp=(C_word)a,a+=2,tmp));
t6=C_fast_retrieve(lf[40]);
t7=C_fast_retrieve(lf[41]);
t8=C_fast_retrieve(lf[42]);
t9=C_fast_retrieve(lf[43]);
t10=C_fast_retrieve(lf[44]);
t11=*((C_word*)lf[45]+1);
t12=C_mutate((C_word*)lf[46]+1 /* (set! chicken.csi#default-evaluator ...) */,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_4364,a[2]=t10,a[3]=t9,a[4]=t8,a[5]=t7,a[6]=t6,a[7]=t11,tmp=(C_word)a,a+=8,tmp));
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4933,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t14=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8815,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:413: toplevel-command */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[38]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[38]+1);
av2[1]=t13;
av2[2]=lf[388];
av2[3]=t14;
av2[4]=lf[389];
tp(5,av2);}}

/* ##sys#read-prompt-hook in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4296,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4303,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_i_tty_forcedp();
if(C_truep(t3)){
if(C_truep(t3)){
/* csi.scm:266: old */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)C_fast_retrieve_proc(t4))(2,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
/* csi.scm:261: ##sys#tty-port? */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[35]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[35]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[36]+1);
tp(3,av2);}}}

/* k4301 in ##sys#read-prompt-hook in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4303,c,av);}
if(C_truep(t1)){
/* csi.scm:266: old */
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.csi#toplevel-command in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4309(C_word c,C_word *av){
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
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_4309,c,av);}
a=C_alloc(12);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_i_check_symbol_2(t2,lf[39]);
t7=(C_truep(t5)?C_i_check_string_2(t5,lf[39]):C_SCHEME_UNDEFINED);
t8=C_i_assq(t2,C_retrieve2(lf[37],C_text("chicken.csi#command-table")));
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4329,a[2]=t3,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t10=(
/* csi.scm:273: g855 */
  f_4329(C_a_i(&a,6),t9,t8)
);
t11=t1;{
C_word *av2=av;
av2[0]=t11;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
t9=C_a_i_list3(&a,3,t2,t3,t5);
t10=C_a_i_cons(&a,2,t9,C_retrieve2(lf[37],C_text("chicken.csi#command-table")));
t11=C_mutate(&lf[37] /* (set! chicken.csi#command-table ...) */,t10);
t12=t1;{
C_word *av2=av;
av2[0]=t12;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}}

/* g855 in chicken.csi#toplevel-command in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static C_word C_fcall f_4329(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_stack_overflow_check;{}
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
return(C_i_set_cdr(t1,t2));}

/* chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4364(C_word c,C_word *av){
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
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_4364,c,av);}
a=C_alloc(10);
if(C_truep(C_eofp(t2))){
/* csi.scm:292: chicken.repl#quit */
t3=C_fast_retrieve(lf[47]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_pairp(t2);
t4=(C_truep(t3)?C_eqp(lf[48],C_slot(t2,C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_i_cadr(t2);
t6=C_i_assq(t5,C_retrieve2(lf[37],C_text("chicken.csi#command-table")));
if(C_truep(t6)){
t7=C_i_cadr(t6);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4397,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:297: g888 */
t9=t7;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)C_fast_retrieve_proc(t9))(2,av2);}}
else{
t7=C_eqp(t5,lf[49]);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4412,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t9=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t8=C_eqp(t5,lf[52]);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4435,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t10=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t9=C_eqp(t5,lf[54]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4453,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t11=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}
else{
t10=C_eqp(t5,lf[56]);
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4468,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t12=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t12;
av2[1]=t11;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t11=C_eqp(t5,lf[58]);
if(C_truep(t11)){
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4483,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t13=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t13;
av2[1]=t12;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}
else{
t12=C_eqp(t5,lf[59]);
if(C_truep(t12)){
/* csi.scm:326: report */
t13=C_retrieve2(lf[60],C_text("chicken.csi#report"));
f_5079(t13,t1,C_SCHEME_END_OF_LIST);}
else{
t13=C_eqp(t5,lf[61]);
if(C_truep(t13)){
/* csi.scm:327: chicken.repl#quit */
t14=C_fast_retrieve(lf[47]);{
C_word *av2=av;
av2[0]=t14;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}
else{
t14=C_eqp(t5,lf[62]);
if(C_truep(t14)){
t15=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4522,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t16=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4555,a[2]=((C_word*)t0)[4],a[3]=t15,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:329: read-line */
t17=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t17;
av2[1]=t16;
((C_proc)(void*)(*((C_word*)t17+1)))(2,av2);}}
else{
t15=C_eqp(t5,lf[64]);
if(C_truep(t15)){
t16=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4564,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[6],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t17=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4611,a[2]=((C_word*)t0)[4],a[3]=t16,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:333: read-line */
t18=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t18;
av2[1]=t17;
((C_proc)(void*)(*((C_word*)t18+1)))(2,av2);}}
else{
t16=C_eqp(t5,lf[68]);
if(C_truep(t16)){
t17=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4620,a[2]=((C_word*)t0)[7],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t18=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t18;
av2[1]=t17;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t18+1)))(3,av2);}}
else{
t17=C_eqp(t5,lf[72]);
if(C_truep(t17)){
if(C_truep(C_fast_retrieve(lf[73]))){
t18=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4672,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t19=C_a_i_list1(&a,1,C_fast_retrieve(lf[73]));
/* csi.scm:343: history-add */
t20=C_retrieve2(lf[28],C_text("chicken.csi#history-add"));
f_4119(t20,t18,t19);}
else{
t18=C_SCHEME_UNDEFINED;
t19=t1;{
C_word *av2=av;
av2[0]=t19;
av2[1]=t18;
((C_proc)(void*)(*((C_word*)t19+1)))(2,av2);}}}
else{
t18=C_eqp(t5,lf[74]);
if(C_truep(t18)){
t19=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4688,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t20=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4706,a[2]=t19,tmp=(C_word)a,a+=3,tmp);
t21=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4710,a[2]=t20,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:348: editor-command */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[7]);
C_word *av2=av;
av2[0]=*((C_word*)lf[7]+1);
av2[1]=t21;
tp(2,av2);}}
else{
t19=C_eqp(t5,lf[79]);
if(C_truep(t19)){
t20=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4726,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t21=*((C_word*)lf[29]+1);
/* csi.scm:214: scheme#vector-fill! */
t22=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t22;
av2[1]=t20;
av2[2]=C_retrieve2(lf[25],C_text("chicken.csi#history-list"));
av2[3]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t22+1)))(4,av2);}}
else{
t20=C_eqp(t5,lf[81]);
if(C_truep(t20)){
t21=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4738,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t22=C_SCHEME_UNDEFINED;
t23=(*a=C_VECTOR_TYPE|1,a[1]=t22,tmp=(C_word)a,a+=2,tmp);
t24=C_set_block_item(t23,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4174,a[2]=t23,tmp=(C_word)a,a+=3,tmp));
t25=((C_word*)t23)[1];
f_4174(t25,t21,C_fix(1));}
else{
t21=C_eqp(t5,lf[89]);
if(C_truep(t21)){
t22=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4750,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:359: show-frameinfo */
f_6811(t22,C_retrieve2(lf[8],C_text("chicken.csi#selected-frame")));}
else{
t22=C_eqp(t5,lf[91]);
if(C_truep(t22)){
t23=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4762,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t24=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4769,a[2]=t23,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t25=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t25;
av2[1]=t24;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t25+1)))(3,av2);}}
else{
t23=C_eqp(t5,lf[95]);
if(C_truep(t23)){
t24=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4782,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t25=C_fast_retrieve(lf[51]);{
C_word *av2=av;
av2[0]=t25;
av2[1]=t24;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t25+1)))(3,av2);}}
else{
t24=C_eqp(t5,lf[103]);
if(C_truep(t24)){
t25=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4791,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:367: read-line */
t26=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t26;
av2[1]=t25;
((C_proc)(void*)(*((C_word*)t26+1)))(2,av2);}}
else{
t25=C_eqp(t5,lf[104]);
if(C_truep(t25)){
t26=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4810,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:372: display */
t27=*((C_word*)lf[92]+1);{
C_word *av2=av;
av2[0]=t27;
av2[1]=t26;
av2[2]=lf[107];
((C_proc)(void*)(*((C_word*)t27+1)))(3,av2);}}
else{
t26=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4861,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:403: printf */
t27=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t27;
av2[1]=t26;
av2[2]=lf[108];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t27+1)))(4,av2);}}}}}}}}}}}}}}}}}}}}}}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4907,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4913,a[2]=((C_word*)t0)[7],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:406: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}}}

/* k4395 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4397(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4397,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4410 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_4412,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4415,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4422,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4426,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:305: expand */
t5=((C_word*)t0)[4];{
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

/* k4413 in k4410 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4415(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4415,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4420 in k4410 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4422,c,av);}
/* csi.scm:305: pretty-print */
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

/* k4424 in k4410 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4426,c,av);}
/* csi.scm:305: chicken.syntax#strip-syntax */
t2=C_fast_retrieve(lf[50]);{
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

/* k4433 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4435(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4435,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4438,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:309: eval */
t3=*((C_word*)lf[53]+1);{
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

/* k4436 in k4433 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4438,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4441,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:310: pretty-print */
t3=((C_word*)t0)[3];{
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

/* k4439 in k4436 in k4433 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4441(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4441,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4451 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4453(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4453,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4456,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:314: eval */
t3=*((C_word*)lf[53]+1);{
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

/* k4454 in k4451 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4456,c,av);}
/* csi.scm:315: describe */
t2=C_retrieve2(lf[55],C_text("chicken.csi#describe"));
f_5403(t2,((C_word*)t0)[2],t1,C_SCHEME_END_OF_LIST);}

/* k4466 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4468(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4468,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4471,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:318: eval */
t3=*((C_word*)lf[53]+1);{
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

/* k4469 in k4466 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4471(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4471,c,av);}
/* csi.scm:319: dump */
f_6458(((C_word*)t0)[2],t1,C_SCHEME_END_OF_LIST);}

/* k4481 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4483,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4486,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:283: chicken.syntax#read-with-source-info */
t3=C_fast_retrieve(lf[51]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=*((C_word*)lf[36]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4484 in k4481 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4486(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4486,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4489,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:323: eval */
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
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4487 in k4484 in k4481 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4489,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4492,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:324: eval */
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
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k4490 in k4487 in k4484 in k4481 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_4492,c,av);}
a=C_alloc(3);
/* csi.scm:325: dump */
f_6458(((C_word*)t0)[2],((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* k4520 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_4522,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4525,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4530,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_4530(t6,t2,t1);}

/* k4523 in k4520 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4525,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop913 in k4520 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4530(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4530,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4540,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:330: g914 */
t4=*((C_word*)lf[63]+1);{
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

/* k4538 in for-each-loop913 in k4520 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4540(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4540,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4530(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4553 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4555(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4555,c,av);}
/* csi.scm:329: string-split */
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

/* k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4564(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_4564,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4565,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4581,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4586,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_4586(t7,t3,t1);}

/* g933 in k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4565(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_4565,3,t0,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4571,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:334: g948 */
t4=((C_word*)t0)[3];{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[67];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* a4570 in g933 in k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4571(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4571,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4575,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:334: pretty-print */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k4573 in a4570 in g933 in k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4575,c,av);}
/* csi.scm:334: chicken.base#print* */
t2=*((C_word*)lf[65]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[66];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k4579 in k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4581,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop932 in k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4586(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_4586,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4596,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:334: g933 */
t4=((C_word*)t0)[3];
f_4565(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4594 in for-each-loop932 in k4562 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4596,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4586(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4609 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4611,c,av);}
/* csi.scm:333: string-split */
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

/* k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_4620,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4625,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4653,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:338: ##sys#call-with-values */{
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

/* a4624 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4625,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4629,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:338: ##sys#start-timer */
t3=*((C_word*)lf[71]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k4627 in a4624 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_4629,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4634,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4640,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:338: ##sys#call-with-values */{
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

/* a4633 in k4627 in a4624 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4634,c,av);}
/* csi.scm:338: eval */
t2=*((C_word*)lf[53]+1);{
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

/* a4639 in k4627 in a4624 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +7,c,2)))){
C_save_and_reclaim((void*)f_4640,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+7);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4644,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4651,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:338: ##sys#stop-timer */
t5=*((C_word*)lf[70]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k4642 in a4639 in k4627 in a4624 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_4644(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4644,c,av);}{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
C_apply_values(3,av2);}}

/* k4649 in a4639 in k4627 in a4624 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_4651(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4651,c,av);}
/* csi.scm:338: ##sys#display-times */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[69]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[69]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* a4652 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4653(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_4653,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+5);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4657,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:339: history-add */
t4=C_retrieve2(lf[28],C_text("chicken.csi#history-add"));
f_4119(t4,t3,t2);}

/* k4655 in a4652 in k4618 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4657,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_apply(4,av2);}}

/* k4670 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4672,c,av);}
/* csi.scm:344: describe */
t2=C_retrieve2(lf[55],C_text("chicken.csi#describe"));
f_5403(t2,((C_word*)t0)[2],C_fast_retrieve(lf[73]),C_SCHEME_END_OF_LIST);}

/* k4686 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4688(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4688,c,av);}
t2=C_eqp(t1,C_fix(0));
if(C_truep(C_i_not(t2))){
/* csi.scm:351: printf */
t3=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[76];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4704 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4706,c,av);}
/* csi.scm:346: chicken.process#system */
t2=C_fast_retrieve(lf[77]);{
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

/* k4708 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4710,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f9525,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:349: read-line */
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_retrieve2(lf[9],C_text("chicken.csi#default-editor"));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9529,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:349: read-line */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4724 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4726(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4726,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4736 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4738(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4738,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4748 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4750(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4750,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4760 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4762(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4762,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4767 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4769(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_4769,c,av);}
a=C_alloc(4);
t2=C_i_numberp(t1);
t3=C_i_not(t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7096,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
t5=t4;
f_7096(t5,t3);}
else{
t5=C_i_not(C_fast_retrieve(lf[94]));
if(C_truep(t5)){
t6=t4;
f_7096(t6,t5);}
else{
t6=C_fixnum_lessp(t1,C_fix(0));
t7=t4;
f_7096(t7,(C_truep(t6)?t6:C_fixnum_greater_or_equal_p(t1,C_i_length(C_fast_retrieve(lf[94])))));}}}

/* k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4782(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4782,c,av);}
a=C_alloc(7);
t2=C_fast_retrieve(lf[94]);
t3=(C_truep(C_fast_retrieve(lf[94]))?C_fast_retrieve(lf[94]):C_SCHEME_END_OF_LIST);
t4=C_i_length(t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7153,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_symbolp(t1))){
t6=t5;
f_7153(t6,C_slot(t1,C_fix(1)));}
else{
if(C_truep(C_i_stringp(t1))){
t6=t5;
f_7153(t6,t1);}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7380,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:869: display */
t7=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[102];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}}

/* k4789 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4791(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4791,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4794,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:368: chicken.process#system */
t3=C_fast_retrieve(lf[77]);{
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

/* k4792 in k4789 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_4794,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4797,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_list1(&a,1,t1);
/* csi.scm:369: history-add */
t4=C_retrieve2(lf[28],C_text("chicken.csi#history-add"));
f_4119(t4,t2,t3);}

/* k4795 in k4792 in k4789 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4797(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4797,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k4808 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4810(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4810,c,av);}
a=C_alloc(8);
t2=C_retrieve2(lf[37],C_text("chicken.csi#command-table"));
t3=C_i_check_list_2(C_retrieve2(lf[37],C_text("chicken.csi#command-table")),lf[99]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4832,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4837,a[2]=t6,tmp=(C_word)a,a+=3,tmp));
t8=((C_word*)t6)[1];
f_4837(t8,t4,C_retrieve2(lf[37],C_text("chicken.csi#command-table")));}

/* k4830 in k4808 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4832(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4832,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* for-each-loop979 in k4808 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_4837(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_4837,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4847,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_i_caddr(t4);
if(C_truep(t5)){
/* csi.scm:398: chicken.base#print */
t6=*((C_word*)lf[105]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=C_make_character(32);
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
/* csi.scm:399: chicken.base#print */
t6=*((C_word*)lf[105]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=lf[106];
av2[3]=C_u_i_car(t4);
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k4845 in for-each-loop979 in k4808 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4847,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_4837(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k4859 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4861(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_4861,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a4906 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4907,c,av);}
/* csi.scm:406: eval */
t2=*((C_word*)lf[53]+1);{
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

/* a4912 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4913(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_4913,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+5);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4917,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:407: history-add */
t4=C_retrieve2(lf[28],C_text("chicken.csi#history-add"));
f_4119(t4,t3,t2);}

/* k4915 in a4912 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_4917,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
C_apply(4,av2);}}

/* k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_4933(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4933,c,av);}
a=C_alloc(9);
t2=C_fast_retrieve(lf[109]);
t3=C_fast_retrieve(lf[110]);
t4=C_fast_retrieve(lf[111]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5078,a[2]=t4,a[3]=t2,a[4]=t3,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* ##sys#peek-c-string */
t6=*((C_word*)lf[381]+1);{
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

/* k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_4939(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_4939,c,av);}
a=C_alloc(14);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4962,a[2]=t4,a[3]=t5,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5007,a[2]=((C_word*)t0)[3],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:440: scheme#call-with-current-continuation */
t8=*((C_word*)lf[293]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t6;
av2[2]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* k4951 in map-loop1019 in k4963 in k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_4953(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_4953,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4956,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:438: scheme#write */
t3=*((C_word*)lf[174]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k4954 in k4951 in map-loop1019 in k4963 in k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_4956(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_4956,c,av);}
/* csi.scm:439: chicken.base#get-output-string */
t2=C_fast_retrieve(lf[375]);{
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

/* k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_4962(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_4962,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4965,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:440: g1042 */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)C_fast_retrieve_proc(t3))(2,av2);}}

/* k4963 in k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_4965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_4965,c,av);}
a=C_alloc(7);
t2=C_i_check_list_2(t1,lf[132]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_4973,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_4973(t6,((C_word*)t0)[4],t1);}

/* map-loop1019 in k4963 in k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_fcall f_4973(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,2)))){
C_save_and_reclaim_args((void *)trf_4973,3,t0,t1,t2);}
a=C_alloc(13);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_4983,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4998,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_slot(t2,C_fix(0));
if(C_truep(C_i_stringp(t5))){
t6=t3;
f_4983(t6,C_a_i_cons(&a,2,t5,C_SCHEME_END_OF_LIST));}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4953,a[2]=t4,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:437: chicken.base#open-output-string */
t7=C_fast_retrieve(lf[376]);{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k4981 in map-loop1019 in k4963 in k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_fcall f_4983(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_4983,2,t0,t1);}
t2=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t1);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t4=((C_word*)((C_word*)t0)[3])[1];
f_4973(t4,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k4996 in map-loop1019 in k4963 in k4960 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_4998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_4998,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];
f_4983(t2,C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST));}

/* a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_5007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_5007,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5013,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5025,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:440: chicken.condition#with-exception-handler */
t5=C_fast_retrieve(lf[292]);{
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

/* a5012 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5013,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5019,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:440: k1039 */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a5018 in a5012 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5019,c,av);}
/* csi.scm:440: ##sys#error */
t2=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[377];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5025,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5031,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5064,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:440: ##sys#call-with-values */{
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

/* a5030 in a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5031,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5039,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:441: scheme#read */
t3=*((C_word*)lf[291]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k5037 in a5030 in a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5039(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_5039,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5041,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_5041(t5,((C_word*)t0)[3],t1,C_SCHEME_END_OF_LIST);}

/* doloop1046 in k5037 in a5030 in a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_5041(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5041,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eofp(t2))){
/* csi.scm:443: scheme#reverse */
t4=*((C_word*)lf[378]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5058,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:441: scheme#read */
t5=*((C_word*)lf[291]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k5056 in doloop1046 in k5037 in a5030 in a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5058(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5058,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=((C_word*)((C_word*)t0)[4])[1];
f_5041(t3,((C_word*)t0)[5],t1,t2);}

/* a5063 in a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5064(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +3,c,2)))){
C_save_and_reclaim((void*)f_5064,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+3);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5070,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:440: k1039 */
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

/* a5069 in a5063 in a5024 in a5006 in k4937 in k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5070(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5070,c,av);}{
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

/* k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_5078(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_5078,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[60] /* (set! chicken.csi#report ...) */,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5079,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp));
t3=C_mutate(&lf[138] /* (set! chicken.csi#bytevector-data ...) */,lf[139]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5401,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:554: scheme#make-vector */
t5=*((C_word*)lf[380]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_fix(37);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_5079(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_5079,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_pairp(t2);
t4=(C_truep(t3)?C_u_i_car(t2):*((C_word*)lf[82]+1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5089,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:456: with-output-to-port */
t6=((C_word*)t0)[5];{
C_word av2[4];
av2[0]=t6;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_5089(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5089,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5093,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:458: chicken.gc#gc */
t3=C_fast_retrieve(lf[137]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_5093(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_5093,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5096,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:459: ##sys#symbol-table-info */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[136]);
C_word *av2=av;
av2[0]=*((C_word*)lf[136]+1);
av2[1]=t2;
tp(2,av2);}}

/* k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_5096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_5096,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5099,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* csi.scm:460: chicken.gc#memory-statistics */
t3=C_fast_retrieve(lf[135]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5099(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_5099,c,av);}
a=C_alloc(14);
t2=C_mk_bool(C_interrupts_enabled);
t3=C_mk_bool(C_heap_size_is_fixed);
t4=C_mk_bool(C_STACK_GROWS_DOWNWARD);
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5101,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5117,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t3,a[7]=t4,a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=t5,a[11]=((C_word*)t0)[6],tmp=(C_word)a,a+=12,tmp);
/* csi.scm:465: printf */
t7=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[134];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* shorten in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_fcall f_5101(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,0,2)))){
C_save_and_reclaim_args((void *)trf_5101,2,t1,t2);}
a=C_alloc(36);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5109,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=C_s_a_i_times(&a,2,t2,C_fix(100));
/* csi.scm:464: scheme#truncate */
t5=*((C_word*)lf[113]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k5107 in shorten in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5109,c,av);}
/* ##sys#/-2 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[112]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[112]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(100);
tp(4,av2);}}

/* k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5117(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,3)))){
C_save_and_reclaim((void *)f_5117,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5120,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_fast_retrieve(lf[124]);
t8=C_fast_retrieve(lf[5]);
t9=C_i_check_list_2(C_fast_retrieve(lf[5]),lf[132]);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5289,a[2]=((C_word*)t0)[11],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5291,a[2]=t5,a[3]=t12,a[4]=t7,a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_5291(t14,t10,C_fast_retrieve(lf[5]));}

/* k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5120(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_5120,c,av);}
a=C_alloc(22);
t2=C_fix(0);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5121,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=C_i_check_list_2(t1,lf[99]);
t6=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_5167,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5258,a[2]=t8,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_5258(t10,t6,t1);}

/* g1109 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_5121(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_5121,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5125,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:470: printf */
t4=*((C_word*)lf[75]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[116];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k5123 in g1109 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5125(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(99,c,2)))){
C_save_and_reclaim((void *)f_5125,c,av);}
a=C_alloc(99);
t2=C_i_string_length(((C_word*)t0)[2]);
t3=C_a_i_fixnum_difference(&a,2,C_fix(16),t2);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)((C_word*)t0)[3])[1];
t6=C_mutate(((C_word *)((C_word*)t0)[3])+1,C_s_a_i_plus(&a,2,t5,C_fix(1)));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5135,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_less_or_equalp(((C_word*)t4)[1],C_fix(0)))){
t8=((C_word*)((C_word*)t0)[3])[1];
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,C_s_a_i_plus(&a,2,t8,C_fix(1)));
t10=C_s_a_i_plus(&a,2,((C_word*)t4)[1],C_fix(18));
t11=C_set_block_item(t4,0,t10);
t12=t7;
f_5135(t12,t11);}
else{
t8=t7;
f_5135(t8,C_SCHEME_UNDEFINED);}}

/* k5133 in k5123 in g1109 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_5135(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_5135,2,t0,t1);}
a=C_alloc(4);
if(C_truep(C_i_greater_or_equalp(((C_word*)((C_word*)t0)[2])[1],C_fix(3)))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5144,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:478: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[114];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5152,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:481: scheme#make-string */
t3=*((C_word*)lf[115]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=C_make_character(32);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k5142 in k5133 in k5123 in g1109 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_5144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5144,c,av);}
t2=C_set_block_item(((C_word*)t0)[2],0,C_fix(0));
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5150 in k5133 in k5123 in g1109 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_5152(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5152,c,av);}
/* csi.scm:481: scheme#display */
t2=*((C_word*)lf[92]+1);{
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

/* k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_5167(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_5167,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5170,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5183,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=t2,a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],tmp=(C_word)a,a+=10,tmp);
/* csi.scm:499: chicken.platform#machine-type */
t4=C_fast_retrieve(lf[131]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5168 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5170(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_5170,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5173,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:518: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t2;
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[82]+1);
tp(4,av2);}}

/* k5171 in k5168 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_5173(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5173,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5176,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
/* csi.scm:519: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[117];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k5174 in k5171 in k5168 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_5176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5176,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5183(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_5183,c,av);}
a=C_alloc(12);
t2=C_fix((C_word)C_WORD_SIZE);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_5188,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=t2,a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],tmp=(C_word)a,a+=12,tmp);
/* csi.scm:501: chicken.platform#software-type */
t4=C_fast_retrieve(lf[130]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_5188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_5188,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_5192,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=t1,a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],tmp=(C_word)a,a+=13,tmp);
/* csi.scm:502: chicken.platform#software-version */
t3=C_fast_retrieve(lf[129]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_5192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_5192,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_5196,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],tmp=(C_word)a,a+=14,tmp);
/* csi.scm:503: chicken.platform#build-platform */
t3=C_fast_retrieve(lf[128]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_5196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_5196,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_5200,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t1,a[12]=((C_word*)t0)[11],a[13]=((C_word*)t0)[12],a[14]=((C_word*)t0)[13],tmp=(C_word)a,a+=15,tmp);
/* csi.scm:505: chicken.platform#installation-repository */
t3=C_fast_retrieve(lf[127]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_5200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_5200,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|15,a[1]=(C_word)f_5204,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=t1,a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],tmp=(C_word)a,a+=16,tmp);
/* csi.scm:506: chicken.platform#repository-path */
t3=C_fast_retrieve(lf[126]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5202 in k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_ccall f_5204(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,2)))){
C_save_and_reclaim((void *)f_5204,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_5208,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=t1,a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],tmp=(C_word)a,a+=17,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5256,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:508: chicken.base#keyword-style */
t4=C_fast_retrieve(lf[125]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k5206 in k5202 in k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_5208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_5208,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_5212,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=t1,a[16]=((C_word*)t0)[15],a[17]=((C_word*)t0)[16],tmp=(C_word)a,a+=18,tmp);
/* csi.scm:509: shorten */
f_5101(t2,C_i_vector_ref(((C_word*)t0)[2],C_fix(0)));}

/* k5210 in k5206 in k5202 in k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in ... */
static void C_ccall f_5212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_5212,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_5216,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=t1,a[17]=((C_word*)t0)[16],tmp=(C_word)a,a+=18,tmp);
/* csi.scm:510: shorten */
f_5101(t2,C_i_vector_ref(((C_word*)t0)[2],C_fix(1)));}

/* k5214 in k5210 in k5206 in k5202 in k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in ... */
static void C_ccall f_5216(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,2)))){
C_save_and_reclaim((void *)f_5216,c,av);}
a=C_alloc(20);
t2=C_i_vector_ref(((C_word*)t0)[2],C_fix(2));
t3=C_i_vector_ref(((C_word*)t0)[3],C_fix(0));
t4=(C_truep(((C_word*)t0)[4])?lf[118]:lf[119]);
t5=C_i_vector_ref(((C_word*)t0)[3],C_fix(1));
t6=C_i_vector_ref(((C_word*)t0)[3],C_fix(2));
t7=(C_truep(((C_word*)t0)[5])?lf[120]:lf[121]);
t8=(*a=C_CLOSURE_TYPE|19,a[1]=(C_word)f_5244,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[12],a[9]=((C_word*)t0)[13],a[10]=((C_word*)t0)[14],a[11]=((C_word*)t0)[15],a[12]=((C_word*)t0)[16],a[13]=t1,a[14]=t2,a[15]=t3,a[16]=t4,a[17]=t5,a[18]=t6,a[19]=t7,tmp=(C_word)a,a+=20,tmp);
/* csi.scm:517: argv */
t9=((C_word*)t0)[17];{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k5242 in k5214 in k5210 in k5206 in k5202 in k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in ... */
static void C_ccall f_5244(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,21)))){
C_save_and_reclaim((void *)f_5244,c,av);}
/* csi.scm:483: printf */
t2=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 22) {
  av2=av;
} else {
  av2=C_alloc(22);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[122];
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
av2[6]=((C_word*)t0)[6];
av2[7]=((C_word*)t0)[7];
av2[8]=((C_word*)t0)[8];
av2[9]=((C_word*)t0)[9];
av2[10]=((C_word*)t0)[10];
av2[11]=C_fast_retrieve(lf[123]);
av2[12]=((C_word*)t0)[11];
av2[13]=((C_word*)t0)[12];
av2[14]=((C_word*)t0)[13];
av2[15]=((C_word*)t0)[14];
av2[16]=((C_word*)t0)[15];
av2[17]=((C_word*)t0)[16];
av2[18]=((C_word*)t0)[17];
av2[19]=((C_word*)t0)[18];
av2[20]=((C_word*)t0)[19];
av2[21]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(22,av2);}}

/* k5254 in k5202 in k5198 in k5194 in k5190 in k5186 in k5181 in k5165 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_5256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5256,c,av);}
/* csi.scm:508: chicken.keyword#keyword->string */
t2=C_fast_retrieve(lf[124]);{
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

/* for-each-loop1108 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_5258(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_5258,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5268,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:468: g1109 */
t4=((C_word*)t0)[3];
f_5121(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k5266 in for-each-loop1108 in k5118 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5268(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5268,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_5258(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k5287 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5289,c,av);}
/* csi.scm:466: sort */
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
av2[3]=*((C_word*)lf[133]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop1082 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_fcall f_5291(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5291,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5316,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:466: g1088 */
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

/* k5314 in map-loop1082 in k5115 in k5097 in k5094 in k5091 in a5088 in chicken.csi#report in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_5316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5316,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_5291(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* lp in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static C_word C_fcall f_5336(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t3=C_u_i_cdr(t1);
if(C_truep(C_i_pairp(t3))){
t4=C_u_i_cdr(t3);
t5=C_i_cdr(t2);
t6=C_eqp(t4,t5);
if(C_truep(t6)){
return(t6);}
else{
t8=t4;
t9=t5;
t1=t8;
t2=t9;
goto loop;}}
else{
return(C_SCHEME_FALSE);}}
else{
return(C_SCHEME_FALSE);}}

/* lp in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static C_word C_fcall f_5371(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;
loop:{}
t2=C_i_pairp(t1);
if(C_truep(C_i_not(t2))){
return(C_SCHEME_FALSE);}
else{
t3=C_i_car(t1);
t4=C_eqp(t1,t3);
if(C_truep(t4)){
return(t4);}
else{
t6=C_u_i_cdr(t1);
t1=t6;
goto loop;}}}

/* k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_5401(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,6)))){
C_save_and_reclaim((void *)f_5401,c,av);}
a=C_alloc(28);
t2=C_mutate(&lf[140] /* (set! chicken.csi#describer-table ...) */,t1);
t3=*((C_word*)lf[141]+1);
t4=*((C_word*)lf[142]+1);
t5=*((C_word*)lf[143]+1);
t6=C_mutate(&lf[55] /* (set! chicken.csi#describe ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5403,a[2]=t5,a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp));
t7=C_mutate((C_word*)lf[235]+1 /* (set! chicken.csi#set-describer! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6449,tmp=(C_word)a,a+=2,tmp));
t8=C_mutate(&lf[57] /* (set! chicken.csi#dump ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6458,tmp=(C_word)a,a+=2,tmp));
t9=C_mutate(&lf[210] /* (set! chicken.csi#hexdump ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6606,tmp=(C_word)a,a+=2,tmp));
t10=C_mutate(&lf[90] /* (set! chicken.csi#show-frameinfo ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6811,tmp=(C_word)a,a+=2,tmp));
t11=C_establish_signal_handler(C_fix((C_word)SIGINT),C_fix((C_word)SIGINT));
t12=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8809,tmp=(C_word)a,a+=2,tmp);
t13=C_i_setslot(C_fast_retrieve(lf[254]),C_fix((C_word)SIGINT),t12);
t14=C_mutate(&lf[255] /* (set! chicken.csi#member* ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7385,tmp=(C_word)a,a+=2,tmp));
t15=C_mutate(&lf[256] /* (set! chicken.csi#constant1687 ...) */,lf[257]);
t16=C_mutate(&lf[258] /* (set! chicken.csi#canonicalize-args ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7440,tmp=(C_word)a,a+=2,tmp));
t17=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8801,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t18=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7780,a[2]=t17,tmp=(C_word)a,a+=3,tmp);
t19=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8795,a[2]=t18,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1000: chicken.process-context#get-environment-variable */
t20=C_fast_retrieve(lf[23]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t20;
av2[1]=t19;
av2[2]=lf[379];
((C_proc)(void*)(*((C_word*)t20+1)))(3,av2);}}

/* chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_5403(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,0,6)))){
C_save_and_reclaim_args((void *)trf_5403,4,t0,t1,t2,t3);}
a=C_alloc(17);
t4=C_i_nullp(t3);
t5=(C_truep(t4)?*((C_word*)lf[82]+1):C_i_car(t3));
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5409,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5541,a[2]=t1,a[3]=t2,a[4]=t5,a[5]=t6,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_permanentp(t2))){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6441,a[2]=t7,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:588: ##sys#block-address */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[234]);
C_word av2[3];
av2[0]=*((C_word*)lf[234]+1);
av2[1]=t8;
av2[2]=t2;
tp(3,av2);}}
else{
t8=t7;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_UNDEFINED;
f_5541(2,av2);}}}

/* descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_5409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word t7;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_5409,c,av);}
a=C_alloc(8);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5538,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=t1,a[7]=t2,tmp=(C_word)a,a+=8,tmp);
/* csi.scm:565: plen */
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}

/* k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5416(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_5416,c,av);}
a=C_alloc(10);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5421,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t3,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp));
t5=((C_word*)t3)[1];
f_5421(t5,((C_word*)t0)[7],C_fix(0));}

/* loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_fcall f_5421(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_5421,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_greater_or_equal_p(t2,C_fix(40)))){
/* csi.scm:570: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[145];
av2[4]=C_fixnum_difference(((C_word*)t0)[2],t2);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5444,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=t1,tmp=(C_word)a,a+=10,tmp);
/* csi.scm:572: pref */
t5=((C_word*)t0)[6];{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[7];
av2[3]=C_fixnum_plus(((C_word*)t0)[4],t2);
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}}}

/* k5442 in loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5444(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5444,c,av);}
a=C_alloc(12);
t2=C_fixnum_plus(((C_word*)t0)[2],C_fix(1));
t3=C_fixnum_plus(((C_word*)t0)[3],t2);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_5453,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],a[6]=t1,a[7]=t5,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp));
t7=((C_word*)t5)[1];
f_5453(t7,((C_word*)t0)[9],C_fix(1),t3);}

/* loop2 in k5442 in loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_5453(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_5453,4,t0,t1,t2,t3);}
a=C_alloc(12);
if(C_truep(C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[2]))){
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5463,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=t2,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5495,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:575: ##sys#with-print-length-limit */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[86]);
C_word av2[4];
av2[0]=*((C_word*)lf[86]+1);
av2[1]=t4;
av2[2]=C_fix(1000);
av2[3]=t5;
tp(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5523,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=t1,a[5]=t2,a[6]=t3,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* csi.scm:585: pref */
t5=((C_word*)t0)[8];{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[9];
av2[3]=t3;
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}}

/* k5461 in loop2 in k5442 in loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5463(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_5463,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5466,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_greaterp(((C_word*)t0)[5],C_fix(1)))){
t3=C_fixnum_difference(((C_word*)t0)[5],C_fix(1));
t4=C_eqp(((C_word*)t0)[5],C_fix(2));
if(C_truep(t4)){
/* csi.scm:580: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[146];
av2[4]=t3;
av2[5]=lf[147];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
/* csi.scm:580: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[146];
av2[4]=t3;
av2[5]=lf[148];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}
else{
/* csi.scm:583: scheme#newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k5464 in k5461 in loop2 in k5442 in loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_5466(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5466,c,av);}
/* csi.scm:584: loop1 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_5421(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],((C_word*)t0)[5]));}

/* a5494 in loop2 in k5442 in loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5495,c,av);}
/* csi.scm:578: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[149];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k5521 in loop2 in k5442 in loop1 in k5414 in k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5523(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5523,c,av);}
t2=C_eqp(((C_word*)t0)[2],t1);
if(C_truep(t2)){
/* csi.scm:585: loop2 */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5453(t3,((C_word*)t0)[4],C_fixnum_plus(((C_word*)t0)[5],C_fix(1)),C_fixnum_plus(((C_word*)t0)[6],C_fix(1)));}
else{
/* csi.scm:586: loop2 */
t3=((C_word*)((C_word*)t0)[3])[1];
f_5453(t3,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[7]);}}

/* k5536 in descseq in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_5538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_5538,c,av);}
a=C_alloc(8);
t2=C_fixnum_difference(t1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5416,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[7])){
/* csi.scm:566: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[150];
av2[4]=((C_word*)t0)[7];
av2[5]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_5416(2,av2);}}}

/* k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_5541(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,7)))){
C_save_and_reclaim((void *)f_5541,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5544,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_charp(((C_word*)t0)[3]))){
t3=C_fix(C_character_code(((C_word*)t0)[3]));
/* csi.scm:591: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[151];
av2[4]=((C_word*)t0)[3];
av2[5]=t3;
av2[6]=t3;
av2[7]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(8,av2);}}
else{
switch(((C_word*)t0)[3]){
case C_SCHEME_TRUE:
/* csi.scm:592: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[152];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}
case C_SCHEME_FALSE:
/* csi.scm:593: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[153];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}
default:
if(C_truep(C_i_nullp(((C_word*)t0)[3]))){
/* csi.scm:594: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[154];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
if(C_truep(C_bwpp(((C_word*)t0)[3]))){
/* csi.scm:597: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[155];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
if(C_truep(C_eofp(((C_word*)t0)[3]))){
/* csi.scm:598: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[156];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=*((C_word*)lf[29]+1);
t4=C_eqp(*((C_word*)lf[29]+1),((C_word*)t0)[3]);
if(C_truep(t4)){
/* csi.scm:599: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[157];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
if(C_truep(C_fixnump(((C_word*)t0)[3]))){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5616,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:601: fprintf */
t6=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[159];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[3];
av2[7]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(8,av2);}}
else{
if(C_truep(C_i_bignump(((C_word*)t0)[3]))){
/* csi.scm:607: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[160];
av2[4]=((C_word*)t0)[3];
av2[5]=((C_word*)t0)[3];
av2[6]=((C_word*)t0)[3];
av2[7]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(8,av2);}}
else{
if(C_truep(C_unboundvaluep(((C_word*)t0)[3]))){
/* csi.scm:610: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[161];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
if(C_truep(C_i_flonump(((C_word*)t0)[3]))){
/* csi.scm:611: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[162];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
if(C_truep(C_i_ratnump(((C_word*)t0)[3]))){
/* csi.scm:612: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[163];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
if(C_truep(C_i_cplxnump(((C_word*)t0)[3]))){
if(C_truep(C_i_exactp(((C_word*)t0)[3]))){
/* csi.scm:613: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[164];
av2[4]=lf[165];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
/* csi.scm:613: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[164];
av2[4]=lf[166];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}
else{
if(C_truep(C_i_numberp(((C_word*)t0)[3]))){
/* csi.scm:615: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[167];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
if(C_truep(C_i_stringp(((C_word*)t0)[3]))){
/* csi.scm:616: descseq */
t5=((C_word*)t0)[5];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=lf[168];
av2[3]=*((C_word*)lf[169]+1);
av2[4]=((C_word*)t0)[6];
av2[5]=C_fix(0);
f_5409(6,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[3]))){
/* csi.scm:617: descseq */
t5=((C_word*)t0)[5];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=lf[170];
av2[3]=*((C_word*)lf[169]+1);
av2[4]=*((C_word*)lf[171]+1);
av2[5]=C_fix(0);
f_5409(6,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_5713,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* csi.scm:618: chicken.keyword#keyword? */
t6=C_fast_retrieve(lf[232]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}}}}}}}}}}}}}}}

/* k5542 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_5544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5544,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k5614 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_5616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_5616,c,av);}
a=C_alloc(3);
t2=C_make_character(C_unfix(((C_word*)t0)[2]));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5622,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[2],C_fix(65536)))){
/* csi.scm:604: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[158];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* csi.scm:605: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[82]+1);
tp(4,av2);}}}

/* k5620 in k5614 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5622(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5622,c,av);}
/* csi.scm:605: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[82]+1);
tp(4,av2);}}

/* k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_5713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_5713,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5720,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:620: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[173]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[173]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[4]))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5729,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5800,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:622: ##sys#symbol-has-toplevel-binding? */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[182]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[182]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5336,tmp=(C_word)a,a+=2,tmp);
t3=(
  f_5336(((C_word*)t0)[4],((C_word*)t0)[4])
);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5812,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t3)){
t5=t4;
f_5812(t5,t3);}
else{
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5371,tmp=(C_word)a,a+=2,tmp);
t6=t4;
f_5812(t6,(
  f_5371(((C_word*)t0)[4])
));}}}}

/* k5718 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_5720,c,av);}
/* csi.scm:619: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[172];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5729(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_5729,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5732,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5797,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:625: ##sys#interned-symbol? */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[180]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[180]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}

/* k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_5732,c,av);}
a=C_alloc(5);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
if(C_truep(C_i_nullp(t2))){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5744,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:629: scheme#display */
t4=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[176];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k5742 in k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5744(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5744,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5749,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_5749(t5,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* doloop1222 in k5742 in k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_5749(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_5749,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5759,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:632: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[175];
av2[4]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k5757 in doloop1222 in k5742 in k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_5759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_5759,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5762,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5774,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:633: ##sys#with-print-length-limit */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[86]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[86]+1);
av2[1]=t2;
av2[2]=C_fix(1000);
av2[3]=t3;
tp(4,av2);}}

/* k5760 in k5757 in doloop1222 in k5742 in k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_5762(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5762,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5765,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:637: scheme#newline */
t3=*((C_word*)lf[84]+1);{
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

/* k5763 in k5760 in k5757 in doloop1222 in k5742 in k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_5765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5765,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_5749(t2,((C_word*)t0)[3],C_i_cddr(((C_word*)t0)[4]));}

/* a5773 in k5757 in doloop1222 in k5742 in k5730 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_5774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5774,c,av);}
/* csi.scm:636: scheme#write */
t2=*((C_word*)lf[174]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5792 in k5795 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5794,c,av);}
/* csi.scm:624: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[179];
av2[4]=((C_word*)t0)[4];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k5795 in k5727 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5797(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5797,c,av);}
a=C_alloc(5);
t2=(C_truep(t1)?lf[177]:lf[178]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5794,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:626: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[173]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[173]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k5798 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_5800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5800,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_5729(2,av2);}}
else{
/* csi.scm:623: scheme#display */
t2=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[181];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_fcall f_5812(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,5)))){
C_save_and_reclaim_args((void *)trf_5812,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5815,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:639: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[186];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
if(C_truep(C_i_listp(((C_word*)t0)[2]))){
/* csi.scm:649: descseq */
t2=((C_word*)t0)[5];{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[187];
av2[3]=((C_word*)t0)[6];
av2[4]=((C_word*)t0)[7];
av2[5]=C_fix(0);
f_5409(6,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
/* csi.scm:650: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word av2[6];
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[188];
av2[4]=C_u_i_car(((C_word*)t0)[2]);
av2[5]=C_u_i_cdr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
if(C_truep(C_i_closurep(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5919,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5923,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:654: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[191]);
C_word av2[4];
av2[0]=*((C_word*)lf[191]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(0);
tp(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:656: chicken.base#port? */
t3=C_fast_retrieve(lf[231]);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}}}}

/* k5813 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5815(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5815,c,av);}
a=C_alloc(9);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5824,a[2]=((C_word*)t0)[3],a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_5824(t6,((C_word*)t0)[4],((C_word*)t0)[2],t2);}

/* loop-print in k5813 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_fcall f_5824(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_5824,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_not_pair_p(t2);
t5=(C_truep(t4)?t4:C_i_nullp(t2));
if(C_truep(t5)){
/* csi.scm:643: printf */
t6=*((C_word*)lf[75]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[183];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t6=C_i_car(t2);
if(C_truep(C_i_memq(t6,t3))){
/* csi.scm:645: fprintf */
t7=*((C_word*)lf[144]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[184];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t7=C_i_memq(C_u_i_car(t2),t3);
if(C_truep(C_i_not(t7))){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5855,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:647: fprintf */
t9=*((C_word*)lf[144]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[185];
av2[4]=C_u_i_car(t2);
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t8=C_SCHEME_UNDEFINED;
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}}}

/* k5853 in loop-print in k5813 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_5855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_5855,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[3]);
/* csi.scm:648: loop-print */
t5=((C_word*)((C_word*)t0)[4])[1];
f_5824(t5,((C_word*)t0)[5],t2,t4);}

/* k5917 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5919(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_5919,c,av);}
/* csi.scm:653: descseq */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=*((C_word*)lf[169]+1);
av2[4]=*((C_word*)lf[171]+1);
av2[5]=C_fix(1);
f_5409(6,av2);}}

/* k5921 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5923,c,av);}
/* csi.scm:654: sprintf */
t2=*((C_word*)lf[189]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[190];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_5929(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_5929,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=(C_truep(t2)?lf[192]:lf[193]);
t4=C_slot(((C_word*)t0)[2],C_fix(7));
t5=C_slot(((C_word*)t0)[2],C_fix(3));
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5948,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=t4,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
/* csi.scm:662: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[191]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[191]+1);
av2[1]=t6;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(0);
tp(4,av2);}}
else{
if(C_truep(C_i_not(C_blockp(((C_word*)t0)[2])))){
/* csi.scm:665: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[195];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5966,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:666: ##sys#locative? */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[230]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[230]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}}

/* k5946 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_5948,c,av);}
/* csi.scm:657: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[194];
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
av2[6]=((C_word*)t0)[6];
av2[7]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}

/* k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_5966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_5966,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5973,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:668: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[191]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[191]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(0);
tp(4,av2);}}
else{
if(C_truep(C_anypointerp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6090,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:683: ##sys#peek-unsigned-integer */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[191]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[191]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(0);
tp(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6096,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:684: ##sys#bytevector? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[229]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[229]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}}

/* k5971 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_5973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_5973,c,av);}
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=C_slot(((C_word*)t0)[2],C_fix(2));
switch(t3){
case C_fix(0):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[197];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(1):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[198];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(2):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[199];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(3):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[200];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(4):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[201];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(5):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[202];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(6):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[203];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(7):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[204];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(8):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[205];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(9):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[206];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(10):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[207];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
case C_fix(11):
/* csi.scm:667: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=lf[208];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}
default:
t4=C_SCHEME_UNDEFINED;
/* csi.scm:667: fprintf */
t5=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[196];
av2[4]=t1;
av2[5]=t2;
av2[6]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(7,av2);}}}

/* k6088 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6090,c,av);}
/* csi.scm:683: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[209];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,6)))){
C_save_and_reclaim((void *)f_6096,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_block_size(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6102,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:686: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[212];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
if(C_truep(C_lambdainfop(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6115,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:689: ##sys#lambda-info->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[214]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[214]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
if(C_truep(C_i_structurep(((C_word*)t0)[2],lf[215]))){
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6127,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t4=C_eqp(t2,C_fix(1));
t5=(C_truep(t4)?lf[218]:lf[219]);
/* csi.scm:692: fprintf */
t6=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[220];
av2[4]=t2;
av2[5]=t5;
av2[6]=C_slot(((C_word*)t0)[2],C_fix(3));
((C_proc)(void*)(*((C_word*)t6+1)))(7,av2);}}
else{
if(C_truep(C_i_structurep(((C_word*)t0)[2],lf[221]))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6224,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:706: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[224];
av2[4]=C_slot(((C_word*)t0)[2],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
if(C_truep(C_structurep(((C_word*)t0)[2]))){
t2=C_slot(((C_word*)t0)[2],C_fix(0));
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6330,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t2,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* csi.scm:722: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[227]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[227]+1);
av2[1]=t3;
av2[2]=C_retrieve2(lf[140],C_text("chicken.csi#describer-table"));
av2[3]=t2;
tp(4,av2);}}
else{
/* csi.scm:729: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=lf[228];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}}}}}

/* k6100 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6102(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6102,c,av);}
/* csi.scm:687: hexdump */
f_6606(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4],*((C_word*)lf[211]+1),((C_word*)t0)[5]);}

/* k6113 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6115,c,av);}
/* csi.scm:689: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[213];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6127,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6130,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:694: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[217];
av2[4]=C_slot(((C_word*)t0)[2],C_fix(4));
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6128 in k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_6130(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_6130,c,av);}
a=C_alloc(8);
t2=C_slot(((C_word*)t0)[2],C_fix(1));
t3=C_block_size(t2);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6141,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_6141(t7,((C_word*)t0)[4],C_fix(0));}

/* doloop1260 in k6128 in k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_fcall f_6141(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,0,3)))){
C_save_and_reclaim_args((void *)trf_6141,3,t0,t1,t2);}
a=C_alloc(14);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6149,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(((C_word*)t0)[4],t2);
t5=C_i_check_list_2(t4,lf[99]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6170,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6179,a[2]=t8,a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_6179(t10,t6,t4);}}

/* g1266 in doloop1260 in k6128 in k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_fcall f_6149(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,5)))){
C_save_and_reclaim_args((void *)trf_6149,3,t0,t1,t2);}
/* csi.scm:702: fprintf */
t3=*((C_word*)lf[144]+1);{
C_word av2[6];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[216];
av2[4]=C_slot(t2,C_fix(0));
av2[5]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k6168 in doloop1260 in k6128 in k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_6170(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6170,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6141(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1265 in doloop1260 in k6128 in k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_fcall f_6179(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6179,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6189,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:700: g1266 */
t4=((C_word*)t0)[3];
f_6149(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6187 in for-each-loop1265 in doloop1260 in k6128 in k6125 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_6189(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6189,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6179(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6224(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_6224,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6225,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_slot(((C_word*)t0)[2],C_fix(1));
t4=C_i_check_list_2(t3,lf[99]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6293,a[2]=t6,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_6293(t8,((C_word*)t0)[4],t3);}

/* g1288 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_6225(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_6225,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6229,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:709: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[223];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k6227 in g1288 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_6229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6229,c,av);}
a=C_alloc(7);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6238,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_6238(t6,((C_word*)t0)[5],t2);}

/* loop in k6227 in g1288 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_fcall f_6238(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_6238,3,t0,t1,t2);}
a=C_alloc(13);
if(C_truep(C_i_nullp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6248,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_i_caar(t2);
t5=C_eqp(((C_word*)t0)[3],t4);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6261,a[2]=t3,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6266,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:713: ##sys#with-print-length-limit */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[86]);
C_word av2[4];
av2[0]=*((C_word*)lf[86]+1);
av2[1]=t6;
av2[2]=C_fix(100);
av2[3]=t7;
tp(4,av2);}}
else{
/* csi.scm:718: loop */
t9=t1;
t10=C_i_cddr(t2);
t1=t9;
t2=t10;
goto loop;}}}

/* k6246 in loop in k6227 in g1288 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_6248(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6248,c,av);}
/* csi.scm:718: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6238(t2,((C_word*)t0)[3],C_i_cddr(((C_word*)t0)[4]));}

/* k6259 in loop in k6227 in g1288 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_6261(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6261,c,av);}
/* csi.scm:717: scheme#newline */
t2=*((C_word*)lf[84]+1);{
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

/* a6265 in loop in k6227 in g1288 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_6266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6266,c,av);}
/* csi.scm:716: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[222];
av2[4]=C_i_cdar(((C_word*)t0)[3]);
av2[5]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* for-each-loop1287 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_6293(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6293,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6303,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:707: g1288 */
t4=((C_word*)t0)[3];
f_6225(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6301 in for-each-loop1287 in k6222 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_6303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6303,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6293(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6330,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6334,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:722: g1317 */
t3=t2;
f_6334(t3,((C_word*)t0)[4],t1);}
else{
t2=C_i_assq(((C_word*)t0)[5],C_retrieve2(lf[138],C_text("chicken.csi#bytevector-data")));
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6348,a[2]=((C_word*)t0)[6],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:722: g1328 */
t4=t3;
f_6348(t4,((C_word*)t0)[4],t2);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6413,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:727: fprintf */
t4=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[226];
av2[4]=C_slot(((C_word*)t0)[2],C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}}

/* g1317 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_6334(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_6334,3,t0,t1,t2);}
/* csi.scm:722: g1325 */
t3=t2;{
C_word av2[4];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}

/* g1328 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_6348(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,0,3)))){
C_save_and_reclaim_args((void *)trf_6348,3,t0,t1,t2);}
a=C_alloc(19);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6356,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_cdr(t2);
t9=C_i_check_list_2(t8,lf[132]);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6369,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6375,a[2]=t6,a[3]=t12,a[4]=t7,tmp=(C_word)a,a+=5,tmp));
t14=((C_word*)t12)[1];
f_6375(t14,t10,t8);}

/* k6354 in g1328 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_6356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6356,c,av);}{
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

/* k6367 in g1328 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_6369(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_6369,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,C_fix(0));
/* csi.scm:725: scheme#append */
t3=*((C_word*)lf[225]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* map-loop1333 in g1328 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_fcall f_6375(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6375,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6400,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:725: g1339 */
t4=*((C_word*)lf[53]+1);{
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

/* k6398 in map-loop1333 in g1328 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_6400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6400,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6375(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6411 in k6328 in k6094 in k5964 in k5927 in k5810 in k5711 in k5539 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_6413(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6413,c,av);}
/* csi.scm:728: descseq */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=C_SCHEME_FALSE;
av2[3]=*((C_word*)lf[169]+1);
av2[4]=*((C_word*)lf[171]+1);
av2[5]=C_fix(1);
f_5409(6,av2);}}

/* k6439 in chicken.csi#describe in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_6441(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6441,c,av);}
/* csi.scm:588: fprintf */
t2=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[233];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* chicken.csi#set-describer! in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_6449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6449,c,av);}
t4=C_i_check_symbol_2(t2,lf[236]);
/* csi.scm:734: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[237]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[237]+1);
av2[1]=t1;
av2[2]=C_retrieve2(lf[140],C_text("chicken.csi#describer-table"));
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}

/* chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_6458(C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_6458,3,t1,t2,t3);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6460,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6566,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6571,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_nullp(t3))){
/* csi.scm:741: def-len1372 */
t7=t6;
f_6571(t7,t1);}
else{
t7=C_i_car(t3);
t8=C_u_i_cdr(t3);
if(C_truep(C_i_nullp(t8))){
/* csi.scm:741: def-out1373 */
t9=t5;
f_6566(t9,t1,t7);}
else{
t9=C_i_car(t8);
t10=C_u_i_cdr(t8);
/* csi.scm:741: body1370 */
t11=t4;
f_6460(t11,t1,t7,t9);}}}

/* body1370 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6460(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_6460,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6463,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_immp(((C_word*)t0)[2]))){
/* csi.scm:745: ##sys#error */
t5=*((C_word*)lf[31]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t1;
av2[2]=lf[239];
av2[3]=lf[240];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6485,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:746: ##sys#bytevector? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[229]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[229]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}

/* bestlen in body1370 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_fcall f_6463(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_6463,3,t0,t1,t2);}
if(C_truep(((C_word*)t0)[2])){
/* csi.scm:744: scheme#min */
t3=*((C_word*)lf[238]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6483 in body1370 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_6485(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_6485,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6492,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:746: bestlen */
t3=((C_word*)t0)[5];
f_6463(t3,t2,C_block_size(((C_word*)t0)[3]));}
else{
if(C_truep(C_i_stringp(((C_word*)t0)[3]))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6509,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:747: bestlen */
t3=((C_word*)t0)[5];
f_6463(t3,t2,C_block_size(((C_word*)t0)[3]));}
else{
t2=C_immp(((C_word*)t0)[3]);
t3=C_i_not(t2);
t4=(C_truep(t3)?C_anypointerp(((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t4)){
/* csi.scm:749: hexdump */
f_6606(((C_word*)t0)[2],((C_word*)t0)[3],C_fix(32),*((C_word*)lf[241]+1),((C_word*)t0)[4]);}
else{
t5=C_structurep(((C_word*)t0)[3]);
t6=(C_truep(t5)?C_i_assq(C_slot(((C_word*)t0)[3],C_fix(0)),C_retrieve2(lf[138],C_text("chicken.csi#bytevector-data"))):C_SCHEME_FALSE);
if(C_truep(t6)){
t7=C_slot(((C_word*)t0)[3],C_fix(1));
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6538,a[2]=((C_word*)t0)[2],a[3]=t7,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:752: bestlen */
t9=((C_word*)t0)[5];
f_6463(t9,t8,C_block_size(t7));}
else{
/* csi.scm:753: ##sys#error */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[239];
av2[3]=lf[242];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}}}}}

/* k6490 in k6483 in body1370 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_6492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6492,c,av);}
/* csi.scm:746: hexdump */
f_6606(((C_word*)t0)[2],((C_word*)t0)[3],t1,*((C_word*)lf[211]+1),((C_word*)t0)[4]);}

/* k6507 in k6483 in body1370 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_6509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6509,c,av);}
/* csi.scm:747: hexdump */
f_6606(((C_word*)t0)[2],((C_word*)t0)[3],t1,*((C_word*)lf[211]+1),((C_word*)t0)[4]);}

/* k6536 in k6483 in body1370 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_6538(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6538,c,av);}
/* csi.scm:752: hexdump */
f_6606(((C_word*)t0)[2],((C_word*)t0)[3],t1,*((C_word*)lf[211]+1),((C_word*)t0)[4]);}

/* def-out1373 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6566(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_6566,3,t0,t1,t2);}
/* csi.scm:741: body1370 */
t3=((C_word*)t0)[2];
f_6460(t3,t1,t2,*((C_word*)lf[82]+1));}

/* def-len1372 in chicken.csi#dump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6571(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_6571,2,t0,t1);}
/* csi.scm:741: def-out1373 */
t2=((C_word*)t0)[2];
f_6566(t2,t1,C_SCHEME_FALSE);}

/* chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_6606(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,6)))){
C_save_and_reclaim_args((void *)trf_6606,5,t1,t2,t3,t4,t5);}
a=C_alloc(12);
t6=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6609,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6641,a[2]=t3,a[3]=t8,a[4]=t5,a[5]=t4,a[6]=t2,a[7]=t6,tmp=(C_word)a,a+=8,tmp));
t10=((C_word*)t8)[1];
f_6641(t10,t1,C_fix(0));}

/* justify in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6609(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_6609,5,t1,t2,t3,t4,t5);}
a=C_alloc(5);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6613,a[2]=t3,a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[243]);
C_word av2[4];
av2[0]=*((C_word*)lf[243]+1);
av2[1]=t6;
av2[2]=t2;
av2[3]=t4;
tp(4,av2);}}

/* k6611 in justify in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_6613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6613,c,av);}
a=C_alloc(4);
t2=C_block_size(t1);
if(C_truep(C_fixnum_lessp(t2,((C_word*)t0)[2]))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6629,a[2]=((C_word*)t0)[3],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:766: make-string */
t4=*((C_word*)lf[115]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_fixnum_difference(((C_word*)t0)[2],t2);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6627 in k6611 in justify in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_6629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6629,c,av);}
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6641(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,5)))){
C_save_and_reclaim_args((void *)trf_6641,3,t0,t1,t2);}
a=C_alloc(14);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6651,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6809,a[2]=t3,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:771: justify */
f_6609(t4,t2,C_fix(4),C_fix(10),C_make_character(32));}}

/* k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_6651(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_6651,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6654,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* ##sys#write-char/port */
t3=C_fast_retrieve(lf[244]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(58);
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_6654(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_6654,c,av);}
a=C_alloc(19);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6657,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6726,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[5],a[4]=t4,a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp));
t6=((C_word*)t4)[1];
f_6726(t6,t2,C_fix(0),((C_word*)t0)[4]);}

/* k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_6657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6657,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6660,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* ##sys#write-char/port */
t3=C_fast_retrieve(lf[244]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6658 in k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_6660(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_6660,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6663,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6675,a[2]=((C_word*)t0)[6],a[3]=t4,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp));
t6=((C_word*)t4)[1];
f_6675(t6,t2,C_fix(0),((C_word*)t0)[4]);}

/* k6661 in k6658 in k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6663,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6666,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#write-char/port */
t3=C_fast_retrieve(lf[244]);{
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

/* k6664 in k6661 in k6658 in k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6666,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6641(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(16)));}

/* doloop1419 in k6658 in k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_6675(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_6675,4,t0,t1,t2,t3);}
a=C_alloc(7);
t4=C_fixnum_greater_or_equal_p(t2,C_fix(16));
t5=(C_truep(t4)?t4:C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[2]));
if(C_truep(t5)){
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6688,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
/* csi.scm:788: ref */
t7=((C_word*)t0)[5];{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[6];
av2[3]=t3;
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}}

/* k6686 in doloop1419 in k6658 in k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6688(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6688,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6691,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_fixnum_greater_or_equal_p(t1,C_fix(32));
t4=(C_truep(t3)?C_fixnum_lessp(t1,C_fix(128)):C_SCHEME_FALSE);
if(C_truep(t4)){
/* ##sys#write-char/port */
t5=C_fast_retrieve(lf[244]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=C_make_character(C_unfix(t1));
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
/* ##sys#write-char/port */
t5=C_fast_retrieve(lf[244]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=C_make_character(46);
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k6689 in k6686 in doloop1419 in k6658 in k6655 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_6691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6691,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6675(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_fcall f_6726(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_6726,4,t0,t1,t2,t3);}
a=C_alloc(10);
t4=C_fixnum_greater_or_equal_p(t2,C_fix(16));
t5=(C_truep(t4)?t4:C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[2]));
if(C_truep(t5)){
if(C_truep(C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[2]))){
t6=C_fixnum_modulo(((C_word*)t0)[2],C_fix(16));
t7=C_eqp(t6,C_fix(0));
if(C_truep(t7)){
t8=C_SCHEME_UNDEFINED;
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t8=C_fixnum_difference(C_fix(16),t6);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6760,a[2]=t10,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp));
t12=((C_word*)t10)[1];
f_6760(t12,t1,t8);}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}
else{
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6780,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
/* ##sys#write-char/port */
t7=C_fast_retrieve(lf[244]);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* doloop1427 in doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_fcall f_6760(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_6760,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_eqp(t2,C_fix(0));
if(C_truep(t3)){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6770,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:781: display */
t5=*((C_word*)lf[92]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[245];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k6768 in doloop1427 in doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6770(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6770,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6760(t2,((C_word*)t0)[3],C_fixnum_difference(((C_word*)t0)[4],C_fix(1)));}

/* k6778 in doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_6780(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_6780,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6783,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6798,a[2]=t2,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6802,a[2]=((C_word*)t0)[7],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:783: ref */
t5=((C_word*)t0)[8];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[9];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}

/* k6781 in k6778 in doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6783,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6726(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* k6796 in k6778 in doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6798,c,av);}
/* csi.scm:783: display */
t2=*((C_word*)lf[92]+1);{
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

/* k6800 in k6778 in doloop1418 in k6652 in k6649 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6802(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6802,c,av);}
/* csi.scm:783: justify */
f_6609(((C_word*)t0)[3],t1,C_fix(2),C_fix(16),C_make_character(48));}

/* k6807 in doloop1408 in chicken.csi#hexdump in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_6809(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6809,c,av);}
/* csi.scm:771: display */
t2=*((C_word*)lf[92]+1);{
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

/* chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_6811(C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_6811,2,t1,t2);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6814,tmp=(C_word)a,a+=2,tmp);
t4=C_fast_retrieve(lf[94]);
t5=(C_truep(C_fast_retrieve(lf[94]))?C_fast_retrieve(lf[94]):C_SCHEME_END_OF_LIST);
t6=C_i_length(t5);
t7=(C_truep(C_u_i_memq(t2,t5))?t2:C_SCHEME_FALSE);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6837,a[2]=t6,a[3]=t3,a[4]=t1,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t7)){
t9=t8;
f_6837(t9,t7);}
else{
t9=C_fixnum_greaterp(t6,C_fix(0));
t10=t8;
f_6837(t10,(C_truep(t9)?C_i_list_ref(t5,C_fixnum_difference(t6,C_fix(1))):C_SCHEME_FALSE));}}

/* prin1 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6814(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_6814,2,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6820,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:802: ##sys#with-print-length-limit */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[86]);
C_word av2[4];
av2[0]=*((C_word*)lf[86]+1);
av2[1]=t1;
av2[2]=C_fix(100);
av2[3]=t3;
tp(4,av2);}}

/* a6819 in prin1 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_6820(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6820,c,av);}
/* csi.scm:805: ##sys#print */
t2=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_TRUE;
av2[4]=*((C_word*)lf[82]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_6837(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_6837,2,t0,t1);}
a=C_alloc(6);
t2=C_mutate(&lf[8] /* (set! chicken.csi#selected-frame ...) */,t1);
t3=C_fixnum_difference(((C_word*)t0)[2],C_fix(1));
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6846,a[2]=t5,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_6846(t7,((C_word*)t0)[4],((C_word*)t0)[5],t3);}

/* doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_fcall f_6846(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,4)))){
C_save_and_reclaim_args((void *)trf_6846,4,t0,t1,t2,t3);}
a=C_alloc(14);
if(C_truep(C_i_nullp(t2))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_eqp(C_retrieve2(lf[8],C_text("chicken.csi#selected-frame")),t4);
t6=C_slot(t4,C_fix(1));
t7=C_slot(t4,C_fix(2));
t8=C_i_structurep(t7,lf[97]);
t9=(C_truep(t8)?C_slot(t7,C_fix(1)):t7);
t10=*((C_word*)lf[82]+1);
t11=*((C_word*)lf[82]+1);
t12=C_i_check_port_2(*((C_word*)lf[82]+1),C_fix(2),C_SCHEME_TRUE,lf[83]);
t13=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6877,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t5,a[7]=t8,a[8]=((C_word*)t0)[3],a[9]=t7,a[10]=t6,a[11]=t9,a[12]=t10,a[13]=t4,tmp=(C_word)a,a+=14,tmp);
if(C_truep(t5)){
/* csi.scm:821: ##sys#print */
t14=*((C_word*)lf[85]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=C_make_character(42);
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[82]+1);
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}
else{
/* csi.scm:821: ##sys#print */
t14=*((C_word*)lf[85]+1);{
C_word av2[5];
av2[0]=t14;
av2[1]=t13;
av2[2]=C_make_character(32);
av2[3]=C_SCHEME_FALSE;
av2[4]=t10;
((C_proc)(void*)(*((C_word*)t14+1)))(5,av2);}}}}

/* k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_6877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_6877,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6880,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* csi.scm:821: ##sys#print */
t3=*((C_word*)lf[85]+1);{
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
av2[4]=((C_word*)t0)[12];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_6880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_6880,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6883,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* csi.scm:821: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t2;
av2[2]=C_make_character(58);
av2[3]=((C_word*)t0)[12];
tp(4,av2);}}

/* k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_6883(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_6883,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6886,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
t3=(C_truep(((C_word*)t0)[7])?C_i_pairp(C_slot(((C_word*)t0)[9],C_fix(2))):C_SCHEME_FALSE);
if(C_truep(t3)){
/* csi.scm:821: ##sys#print */
t4=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[251];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[12];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* csi.scm:821: ##sys#print */
t4=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[252];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[12];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_6886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_6886,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_6889,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* csi.scm:821: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t2;
av2[2]=C_make_character(9);
av2[3]=((C_word*)t0)[12];
tp(4,av2);}}

/* k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_6889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_6889,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_6892,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
/* csi.scm:821: ##sys#print */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[13],C_fix(0));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[12];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_6892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_6892,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6895,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
/* csi.scm:821: ##sys#print */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[250];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[12];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_6895(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6895,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6898,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(((C_word*)t0)[11])){
t3=*((C_word*)lf[82]+1);
t4=*((C_word*)lf[82]+1);
t5=C_i_check_port_2(*((C_word*)lf[82]+1),C_fix(2),C_SCHEME_TRUE,lf[83]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7038,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[11],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:826: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=t6;
av2[2]=C_make_character(91);
av2[3]=*((C_word*)lf[82]+1);
tp(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6898(2,av2);}}}

/* k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_6898(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_6898,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6901,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
if(C_truep(((C_word*)t0)[10])){
/* csi.scm:827: prin1 */
f_6814(t2,((C_word*)t0)[10]);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_6901(2,av2);}}}

/* k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_6901(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_6901,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6904,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* csi.scm:828: newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_ccall f_6904(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_6904,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6907,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(C_truep(((C_word*)t0)[6])?((C_word*)t0)[7]:C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6920,a[2]=((C_word*)t0)[8],tmp=(C_word)a,a+=3,tmp);
t5=C_slot(((C_word*)t0)[9],C_fix(2));
t6=C_slot(((C_word*)t0)[9],C_fix(3));
t7=C_i_check_list_2(t5,lf[99]);
t8=C_i_check_list_2(t6,lf[99]);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6994,a[2]=t10,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t12=((C_word*)t10)[1];
f_6994(t12,t2,t5,t6);}
else{
t4=((C_word*)((C_word*)t0)[2])[1];
f_6846(t4,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_fixnum_difference(((C_word*)t0)[5],C_fix(1)));}}

/* k6905 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_6907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6907,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6846(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_fixnum_difference(((C_word*)t0)[5],C_fix(1)));}

/* g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_fcall f_6920(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6920,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6930,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:833: display */
t5=*((C_word*)lf[92]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[248];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in ... */
static void C_ccall f_6930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_6930,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6935,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_6935(t5,((C_word*)t0)[4],C_fix(0),((C_word*)t0)[5]);}

/* doloop1515 in k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in ... */
static void C_fcall f_6935(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_6935,4,t0,t1,t2,t3);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t3))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=*((C_word*)lf[82]+1);
t5=*((C_word*)lf[82]+1);
t6=C_i_check_port_2(*((C_word*)lf[82]+1),C_fix(2),C_SCHEME_TRUE,lf[83]);
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6948,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=t4,tmp=(C_word)a,a+=9,tmp);
/* csi.scm:837: ##sys#print */
t8=*((C_word*)lf[85]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[247];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[82]+1);
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}}

/* k6946 in doloop1515 in k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in ... */
static void C_ccall f_6948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_6948,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6951,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* csi.scm:837: ##sys#print */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[5]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6949 in k6946 in doloop1515 in k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in ... */
static void C_ccall f_6951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_6951,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6954,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* csi.scm:837: ##sys#print */
t3=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[246];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6952 in k6949 in k6946 in doloop1515 in k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in ... */
static void C_ccall f_6954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6954,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6957,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:838: prin1 */
f_6814(t2,C_slot(((C_word*)t0)[7],((C_word*)t0)[4]));}

/* k6955 in k6952 in k6949 in k6946 in doloop1515 in k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in ... */
static void C_ccall f_6957(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6957,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6960,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:839: newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6958 in k6955 in k6952 in k6949 in k6946 in doloop1515 in k6928 in g1502 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in ... */
static void C_ccall f_6960(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6960,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6935(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)),C_u_i_cdr(((C_word*)t0)[5]));}

/* for-each-loop1501 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_fcall f_6994(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_6994,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7004,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:830: g1502 */
t7=((C_word*)t0)[3];
f_6920(t7,t6,C_slot(t2,C_fix(0)),C_slot(t3,C_fix(0)));}
else{
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k7002 in for-each-loop1501 in k6902 in k6899 in k6896 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in ... */
static void C_ccall f_7004(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7004,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6994(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7036 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_7038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_7038,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7041,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:826: ##sys#print */
t3=*((C_word*)lf[85]+1);{
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

/* k7039 in k7036 in k6893 in k6890 in k6887 in k6884 in k6881 in k6878 in k6875 in doloop1464 in k6835 in chicken.csi#show-frameinfo in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_7041(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7041,c,av);}
/* csi.scm:826: ##sys#print */
t2=*((C_word*)lf[85]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[249];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k7094 in k4767 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_7096(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_7096,2,t0,t1);}
if(C_truep(t1)){
/* csi.scm:850: display */
t2=*((C_word*)lf[92]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[93];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_i_length(C_fast_retrieve(lf[94]));
t3=C_fixnum_plus(((C_word*)t0)[3],C_fix(1));
t4=C_fixnum_difference(t2,t3);
t5=C_i_list_ref(C_fast_retrieve(lf[94]),t4);
t6=C_mutate(&lf[8] /* (set! chicken.csi#selected-frame ...) */,t5);
/* csi.scm:856: show-frameinfo */
f_6811(((C_word*)t0)[2],C_retrieve2(lf[8],C_text("chicken.csi#selected-frame")));}}

/* k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_7153(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_7153,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7155,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7186,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:877: call/cc */
t4=*((C_word*)lf[101]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t3;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* compare in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_7155(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,4)))){
C_save_and_reclaim_args((void *)trf_7155,3,t0,t1,t2);}
a=C_alloc(4);
t3=C_slot(t2,C_fix(1));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7166,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t5=C_i_string_length(((C_word*)t0)[2]);
t6=C_i_string_length(t3);
/* csi.scm:875: scheme#substring */
t7=*((C_word*)lf[13]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_fix(0);
av2[4]=C_i_fixnum_min(t5,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}

/* k7164 in compare in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_7166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7166,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_string_equal_p(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_7186(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_7186,c,av);}
a=C_alloc(12);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7189,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7208,a[2]=t3,a[3]=t5,a[4]=t2,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp));
t7=((C_word*)t5)[1];
f_7208(t7,t1,((C_word*)t0)[4]);}

/* fail in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_7189(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_7189,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7193,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:880: display */
t4=*((C_word*)lf[92]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k7191 in fail in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_7193(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7193,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7196,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:881: newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k7194 in k7191 in fail in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7196,c,av);}
t2=*((C_word*)lf[29]+1);
/* csi.scm:882: return */
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=*((C_word*)lf[29]+1);
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_7208(C_word t0,C_word t1,C_word t2){
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
loop:
if(C_unlikely(!C_demand(C_calculate_demand(20,0,4)))){
C_save_and_reclaim_args((void *)trf_7208,3,t0,t1,t2);}
a=C_alloc(20);
if(C_truep(C_i_nullp(t2))){
/* csi.scm:884: fail */
t3=((C_word*)t0)[2];
f_7189(t3,t1,lf[96]);}
else{
t3=C_i_car(t2);
t4=C_eqp(C_retrieve2(lf[8],C_text("chicken.csi#selected-frame")),t3);
t5=C_slot(t3,C_fix(2));
t6=C_i_structurep(t5,lf[97]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7233,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t8=(C_truep(t4)?t6:C_SCHEME_FALSE);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7242,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t10=C_slot(t5,C_fix(2));
t11=C_slot(t5,C_fix(3));
t12=C_i_check_list_2(t10,lf[99]);
t13=C_i_check_list_2(t11,lf[99]);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7318,a[2]=((C_word*)t0)[2],a[3]=t7,a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7327,a[2]=t16,a[3]=t9,tmp=(C_word)a,a+=4,tmp));
t18=((C_word*)t16)[1];
f_7327(t18,t14,t10,t11);}
else{
t19=t1;
t20=C_u_i_cdr(t2);
t1=t19;
t2=t20;
goto loop;}}}

/* k7231 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_7233(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7233,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7208(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_fcall f_7242(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_7242,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7248,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_7248(t7,t1,C_fix(0),t2);}

/* doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_fcall f_7248(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_7248,4,t0,t1,t2,t3);}
a=C_alloc(15);
if(C_truep(C_i_nullp(t3))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7258,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7270,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word*)t0)[4],a[5]=t2,a[6]=t3,a[7]=((C_word*)t0)[2],a[8]=t1,tmp=(C_word)a,a+=9,tmp);
/* csi.scm:896: compare */
t6=((C_word*)t0)[5];
f_7155(t6,t5,C_i_car(t3));}}

/* k7256 in doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_7258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7258,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7248(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)),C_u_i_cdr(((C_word*)t0)[5]));}

/* k7268 in doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_7270(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7270,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7273,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* csi.scm:897: display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[98];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)((C_word*)t0)[7])[1];
f_7248(t2,((C_word*)t0)[8],C_fixnum_plus(((C_word*)t0)[5],C_fix(1)),C_u_i_cdr(((C_word*)t0)[6]));}}

/* k7271 in k7268 in doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_7273(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7273,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7276,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:898: display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_car(((C_word*)t0)[6]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7274 in k7271 in k7268 in doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_7276(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7276,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7279,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:899: newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k7277 in k7274 in k7271 in k7268 in doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_7279(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_7279,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7282,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_slot(((C_word*)t0)[4],((C_word*)t0)[5]);
t4=C_a_i_list1(&a,1,t3);
/* csi.scm:900: history-add */
t5=C_retrieve2(lf[28],C_text("chicken.csi#history-add"));
f_4119(t5,t2,t4);}

/* k7280 in k7277 in k7274 in k7271 in k7268 in doloop1612 in g1599 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_7282(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7282,c,av);}
/* csi.scm:901: return */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=C_slot(((C_word*)t0)[4],((C_word*)t0)[5]);
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}

/* k7316 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_7318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7318,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7325,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:904: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t2;
av2[2]=lf[100];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}

/* k7323 in k7316 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7325(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7325,c,av);}
/* csi.scm:904: fail */
t2=((C_word*)t0)[2];
f_7189(t2,((C_word*)t0)[3],t1);}

/* for-each-loop1598 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_fcall f_7327(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7327,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7337,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:891: g1599 */
t7=((C_word*)t0)[3];
f_7242(t7,t6,C_slot(t2,C_fix(0)),C_slot(t3,C_fix(0)));}
else{
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k7335 in for-each-loop1598 in doloop1584 in a7185 in k7151 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7337(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7337,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7327(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)),C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7378 in k4780 in chicken.csi#default-evaluator in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_7380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7380,c,av);}
t2=((C_word*)t0)[2];
f_7153(t2,C_SCHEME_FALSE);}

/* chicken.csi#member* in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_7385(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7385,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7391,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_7391(t7,t1,t3);}

/* loop in chicken.csi#member* in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_7391(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_7391,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7403,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_7403(t6,t1,((C_word*)t0)[3]);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* find in loop in chicken.csi#member* in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_fcall f_7403(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_7403,3,t0,t1,t2);}
if(C_truep(C_i_nullp(t2))){
/* csi.scm:928: loop */
t3=((C_word*)((C_word*)t0)[2])[1];
f_7391(t3,t1,C_i_cdr(((C_word*)t0)[3]));}
else{
t3=C_i_car(t2);
t4=C_i_car(((C_word*)t0)[3]);
if(C_truep(C_i_equalp(t3,t4))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* csi.scm:930: find */
t6=t1;
t7=C_u_i_cdr(t2);
t1=t6;
t2=t7;
goto loop;}}}

/* chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_7440(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_7440,2,t1,t2);}
a=C_alloc(5);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7446,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_7446(t6,t1,t2);}

/* loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_fcall f_7446(C_word t0,C_word t1,C_word t2){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7446,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
if(C_truep((C_truep(C_i_equalp(t3,lf[259]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[260]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[261]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[262]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[263]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_block_size(t3);
t5=C_eqp(t4,C_fix(2));
t6=(C_truep(t5)?C_i_char_equalp(C_make_character(45),C_subchar(t3,C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t6)){
if(C_truep(C_i_memq(C_subchar(t3,C_fix(1)),C_retrieve2(lf[256],C_text("chicken.csi#constant1687"))))){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7481,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:951: loop */
t11=t7;
t12=C_u_i_cdr(t2);
t1=t11;
t2=t12;
goto loop;}
else{
/* csi.scm:952: ##sys#error */
t7=*((C_word*)lf[31]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t1;
av2[2]=lf[264];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}
else{
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7493,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t8=C_block_size(t3);
if(C_truep(C_fixnum_greaterp(t8,C_fix(2)))){
t9=C_i_char_equalp(C_make_character(45),C_subchar(t3,C_fix(0)));
t10=t7;
f_7493(t10,(C_truep(t9)?C_i_not(C_i_member(t3,lf[267])):C_SCHEME_FALSE));}
else{
t9=t7;
f_7493(t9,C_SCHEME_FALSE);}}}}}

/* k7479 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_7481(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7481,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_fcall f_7493(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_7493,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
if(C_truep(C_i_char_equalp(C_make_character(58),C_subchar(((C_word*)t0)[2],C_fix(1))))){
/* csi.scm:957: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_7446(t2,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[5]));}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7507,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7575,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:958: scheme#substring */
t4=*((C_word*)lf[13]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7583,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:962: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_7446(t3,t2,C_u_i_cdr(((C_word*)t0)[5]));}}

/* k7505 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7507(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7507,c,av);}
a=C_alloc(19);
t2=C_retrieve2(lf[256],C_text("chicken.csi#constant1687"));
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7625,tmp=(C_word)a,a+=2,tmp);
t4=(
  f_7625(t1)
);
if(C_truep(t4)){
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7528,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7536,a[2]=t7,a[3]=t11,a[4]=t8,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_7536(t13,t9,t1);}
else{
/* csi.scm:961: ##sys#error */
t5=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[265];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k7526 in k7505 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_7528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7528,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7532,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:960: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_7446(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k7530 in k7526 in k7505 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_7532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7532,c,av);}
/* csi.scm:960: scheme#append */
t2=*((C_word*)lf[225]+1);{
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

/* map-loop1710 in k7505 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_fcall f_7536(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7536,3,t0,t1,t2);}
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

/* k7573 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7575(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7575,c,av);}
/* ##sys#string->list */
t2=C_fast_retrieve(lf[266]);{
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

/* k7581 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7583,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k7505 in k7491 in loop in chicken.csi#canonicalize-args in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static C_word C_fcall f_7625(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
t2=C_i_nullp(t1);
if(C_truep(t2)){
return(t2);}
else{
t3=C_i_car(t1);
if(C_truep(C_i_memq(t3,C_retrieve2(lf[256],C_text("chicken.csi#constant1687"))))){
t5=C_u_i_cdr(t1);
t1=t5;
goto loop;}
else{
return(C_SCHEME_FALSE);}}}

/* loop in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_fcall f_7661(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_7661,4,t0,t1,t2,t3);}
a=C_alloc(58);
if(C_truep(C_i_nequalp(t2,t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=lf[295];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_string_ref(((C_word*)t0)[2],t2);
if(C_truep(C_u_i_char_whitespacep(t4))){
t5=C_a_i_fixnum_plus(&a,2,t2,C_fix(1));
/* csi.scm:985: loop */
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
/* csi.scm:987: loop */
t9=t1;
t10=t2;
t11=t7;
t1=t9;
t2=t10;
t3=t11;
goto loop;}
else{
/* csi.scm:988: scheme#substring */
t7=*((C_word*)lf[13]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}}}}

/* k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_7709(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7709,c,av);}
a=C_alloc(6);
t2=C_i_string_length(t1);
t3=(C_truep(C_i_fixnum_positivep(t2))?C_u_i_char_equalp(C_make_character(40),C_i_string_ref(t1,C_fix(0))):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7718,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7723,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:994: scheme#call-with-current-continuation */
t6=*((C_word*)lf[293]+1);{
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
/* csi.scm:997: scheme#string->symbol */
t4=*((C_word*)lf[294]+1);{
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

/* k7716 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_7718(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7718,c,av);}
/* csi.scm:994: g1785 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_7723(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7723,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7729,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7741,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:994: chicken.condition#with-exception-handler */
t5=C_fast_retrieve(lf[292]);{
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

/* a7728 in a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in ... */
static void C_ccall f_7729(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7729,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7735,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:994: k1782 */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a7734 in a7728 in a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in ... */
static void C_ccall f_7735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7735,c,av);}
/* csi.scm:995: ##sys#error */
t2=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[289];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a7740 in a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in ... */
static void C_ccall f_7741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_7741,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7747,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7753,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:994: ##sys#call-with-values */{
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

/* a7746 in a7740 in a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in ... */
static void C_ccall f_7747(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7747,c,av);}
/* csi.scm:996: chicken.port#with-input-from-string */
t2=C_fast_retrieve(lf[290]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=*((C_word*)lf[291]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a7752 in a7740 in a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in ... */
static void C_ccall f_7753(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +3,c,2)))){
C_save_and_reclaim((void*)f_7753,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+3);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7759,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:994: k1782 */
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

/* a7758 in a7752 in a7740 in a7722 in k7707 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in ... */
static void C_ccall f_7759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7759,c,av);}{
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

/* k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_7780(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7780,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7783,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8791,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1001: chicken.process-context#command-line-arguments */
t4=C_fast_retrieve(lf[304]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_7783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_7783,c,av);}
a=C_alloc(7);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7786,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* csi.scm:1003: member* */
f_7385(t4,lf[373],((C_word*)t3)[1]);}

/* k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in ... */
static void C_ccall f_7786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_7786,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7789,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1004: member* */
f_7385(t2,lf[372],((C_word*)((C_word*)t0)[2])[1]);}

/* k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in ... */
static void C_ccall f_7789(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_7789,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7792,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8691,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_i_cdr(t1);
t5=C_i_pairp(t4);
t6=C_i_not(t5);
if(C_truep(t6)){
if(C_truep(t6)){
/* csi.scm:1009: ##sys#error */
t7=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=lf[370];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_UNDEFINED;
f_8691(2,av2);}}}
else{
t7=C_i_cadr(t1);
t8=C_i_string_length(t7);
t9=C_eqp(t8,C_fix(0));
if(C_truep(t9)){
if(C_truep(t9)){
/* csi.scm:1009: ##sys#error */
t10=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t10;
av2[1]=t3;
av2[2]=lf[370];
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t10=t3;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_SCHEME_UNDEFINED;
f_8691(2,av2);}}}
else{
t10=C_u_i_cdr(t1);
t11=C_i_string_ref(C_u_i_car(t10),C_fix(0));
if(C_truep(C_u_i_char_equalp(C_make_character(45),t11))){
/* csi.scm:1009: ##sys#error */
t12=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t12;
av2[1]=t3;
av2[2]=lf[370];
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t12=t3;{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_SCHEME_UNDEFINED;
f_8691(2,av2);}}}}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8774,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8787,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1019: canonicalize-args */
f_7440(t4,((C_word*)t0)[5]);}}

/* k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_fcall f_7792(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7792,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7795,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1022: member* */
f_7385(t2,lf[367],((C_word*)((C_word*)t0)[3])[1]);}

/* k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_7795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_7795,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7798,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[2])){
t3=t2;
f_7798(t3,((C_word*)t0)[2]);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8685,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1023: member* */
f_7385(t3,lf[366],((C_word*)((C_word*)t0)[3])[1]);}}

/* k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_fcall f_7798(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_7798,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7801,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* csi.scm:1024: member* */
f_7385(t2,lf[365],((C_word*)((C_word*)t0)[4])[1]);}

/* k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_7801(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_7801,c,av);}
a=C_alloc(23);
t2=(C_truep(((C_word*)t0)[2])?((C_word*)t0)[2]:(C_truep(t1)?t1:((C_word*)t0)[3]));
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7806,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp));
t8=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7918,tmp=(C_word)a,a+=2,tmp));
t9=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7975,a[2]=((C_word*)t0)[5],a[3]=t6,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[3],a[8]=t2,a[9]=((C_word*)t0)[7],a[10]=t4,tmp=(C_word)a,a+=11,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8673,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1051: member* */
f_7385(t10,lf[364],((C_word*)((C_word*)t0)[4])[1]);}

/* collect-options in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_7806(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7806,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7812,a[2]=t2,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_7812(t6,t1,((C_word*)((C_word*)t0)[2])[1]);}

/* loop in collect-options in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_fcall f_7812(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_7812,3,t0,t1,t2);}
a=C_alloc(4);
t3=C_i_member(((C_word*)t0)[2],t2);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7820,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1028: g1876 */
t5=t4;
f_7820(t5,t1,t3);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* g1876 in loop in collect-options in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_fcall f_7820(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_7820,3,t0,t1,t2);}
a=C_alloc(4);
t3=C_i_cdr(t2);
if(C_truep(C_i_nullp(t3))){
/* csi.scm:1031: ##sys#error */
t4=*((C_word*)lf[31]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[269];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=C_i_cadr(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7841,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=C_u_i_cdr(t2);
/* csi.scm:1032: loop */
t7=((C_word*)((C_word*)t0)[3])[1];
f_7812(t7,t5,C_u_i_cdr(t6));}}

/* k7839 in g1876 in loop in collect-options in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_7841(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7841,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in ... */
static void C_ccall f_7857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_7857,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7860,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=C_a_i_list2(&a,2,t1,lf[317]);
/* csi.scm:1036: chicken.pathname#make-pathname */
t4=C_fast_retrieve(lf[314]);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
av2[3]=C_retrieve2(lf[1],C_text("chicken.csi#constant701"));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_7860(2,av2);}}}

/* k7858 in k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in ... */
static void C_ccall f_7860(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7860,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7863,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1038: chicken.process-context#get-environment-variable */
t3=C_fast_retrieve(lf[23]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[316];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7861 in k7858 in k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_7863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7863,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7866,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
t3=C_i_string_equal_p(t1,lf[313]);
if(C_truep(C_i_not(t3))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7903,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t5=C_retrieve2(lf[1],C_text("chicken.csi#constant701"));
/* ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t4;
av2[2]=lf[315];
av2[3]=C_retrieve2(lf[1],C_text("chicken.csi#constant701"));
tp(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_7866(2,av2);}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_7866(2,av2);}}}

/* k7864 in k7861 in k7858 in k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_7866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7866,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7872,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[3])){
/* csi.scm:1041: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[14]);{
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
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_7872(2,av2);}}}

/* k7870 in k7864 in k7861 in k7858 in k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in ... */
static void C_ccall f_7872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7872,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
/* csi.scm:1042: scheme#load */
t2=*((C_word*)lf[63]+1);{
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
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7881,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
if(C_truep(((C_word*)t0)[4])){
/* csi.scm:1043: chicken.file#file-exists? */
t3=C_fast_retrieve(lf[14]);{
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
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_8045(2,av2);}}}}

/* k7879 in k7870 in k7864 in k7861 in k7858 in k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in ... */
static void C_ccall f_7881(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7881,c,av);}
if(C_truep(t1)){
/* csi.scm:1044: scheme#load */
t2=*((C_word*)lf[63]+1);{
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
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_8045(2,av2);}}}

/* k7901 in k7861 in k7858 in k7855 in k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_7903(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7903,c,av);}
/* csi.scm:1040: chicken.pathname#make-pathname */
t2=C_fast_retrieve(lf[314]);{
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

/* evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_fcall f_7918(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7918,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_nullp(t3);
t5=(C_truep(t4)?(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7965,tmp=(C_word)a,a+=2,tmp):C_i_car(t3));
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7925,a[2]=t5,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1046: chicken.base#open-input-string */
t7=C_fast_retrieve(lf[271]);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_7925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7925,c,av);}
a=C_alloc(6);
t2=C_fast_retrieve(lf[51]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7932,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1048: read-with-source-info */
t4=C_fast_retrieve(lf[51]);{
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

/* k7930 in k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_ccall f_7932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7932,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7934,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_7934(t5,((C_word*)t0)[5],t1);}

/* doloop1907 in k7930 in k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_fcall f_7934(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_7934,3,t0,t1,t2);}
a=C_alloc(13);
if(C_truep(C_eofp(t2))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7944,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7955,a[2]=((C_word*)t0)[5],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7957,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1050: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t4;
av2[2]=t5;
av2[3]=*((C_word*)lf[270]+1);
C_call_with_values(4,av2);}}}

/* k7942 in doloop1907 in k7930 in k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_ccall f_7944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7944,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7951,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1048: read-with-source-info */
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

/* k7949 in k7942 in doloop1907 in k7930 in k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_7951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7951,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_7934(t2,((C_word*)t0)[3],t1);}

/* k7953 in doloop1907 in k7930 in k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_ccall f_7955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7955,c,av);}
/* csi.scm:1050: rec */
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

/* a7956 in doloop1907 in k7930 in k7923 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_ccall f_7957(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7957,c,av);}
/* csi.scm:1050: scheme#eval */
t2=*((C_word*)lf[53]+1);{
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

/* f_7965 in evalstring in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_7965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7965,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=*((C_word*)lf[29]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_7975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_7975,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7978,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_member(lf[358],((C_word*)((C_word*)t0)[6])[1]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8667,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9680,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:144: chicken.platform#chicken-version */
t5=C_fast_retrieve(lf[323]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_7978(2,av2);}}}

/* k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_7978(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_7978,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7981,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_member(lf[356],((C_word*)((C_word*)t0)[6])[1]))){
t3=C_set_block_item(lf[357] /* ##sys#setup-mode */,0,C_SCHEME_TRUE);
t4=t2;
f_7981(t4,t3);}
else{
t3=t2;
f_7981(t3,C_SCHEME_UNDEFINED);}}

/* k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in ... */
static void C_fcall f_7981(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,0,2)))){
C_save_and_reclaim_args((void *)trf_7981,2,t0,t1);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7984,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_member(lf[355],((C_word*)((C_word*)t0)[6])[1]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8650,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8657,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1060: chicken.platform#chicken-version */
t5=C_fast_retrieve(lf[323]);{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_7984(2,av2);}}}

/* k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_7984(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_7984,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7987,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8637,a[2]=t2,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1062: member* */
f_7385(t3,lf[354],((C_word*)((C_word*)t0)[6])[1]);}

/* k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_fcall f_7987(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_7987,2,t0,t1);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7990,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8622,a[2]=t2,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1065: member* */
f_7385(t3,lf[351],((C_word*)((C_word*)t0)[6])[1]);}

/* k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_7990(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7990,c,av);}
a=C_alloc(12);
t2=C_fast_retrieve(lf[272]);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7993,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t2,tmp=(C_word)a,a+=12,tmp);
/* csi.scm:1069: collect-options */
t4=((C_word*)((C_word*)t0)[10])[1];
f_7806(t4,t3,lf[348]);}

/* k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in ... */
static void C_ccall f_7993(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7993,c,av);}
a=C_alloc(17);
t2=C_i_check_list_2(t1,lf[99]);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7999,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8598,a[2]=t5,a[3]=((C_word*)t0)[11],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_8598(t7,t3,t1);}

/* k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in ... */
static void C_ccall f_7999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_7999,c,av);}
a=C_alloc(12);
t2=C_fast_retrieve(lf[272]);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_8002,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t2,tmp=(C_word)a,a+=12,tmp);
/* csi.scm:1070: collect-options */
t4=((C_word*)((C_word*)t0)[10])[1];
f_7806(t4,t3,lf[347]);}

/* k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in ... */
static void C_ccall f_8002(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8002,c,av);}
a=C_alloc(17);
t2=C_i_check_list_2(t1,lf[99]);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_8008,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8575,a[2]=t5,a[3]=((C_word*)t0)[11],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_8575(t7,t3,t1);}

/* k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in ... */
static void C_ccall f_8008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_8008,c,av);}
a=C_alloc(12);
t2=C_fast_retrieve(lf[273]);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_8011,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=t2,tmp=(C_word)a,a+=12,tmp);
/* csi.scm:1071: collect-options */
t4=((C_word*)((C_word*)t0)[10])[1];
f_7806(t4,t3,lf[346]);}

/* k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in ... */
static void C_ccall f_8011(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8011,c,av);}
a=C_alloc(17);
t2=C_i_check_list_2(t1,lf[99]);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_8017,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8552,a[2]=t5,a[3]=((C_word*)t0)[11],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_8552(t7,t3,t1);}

/* k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in ... */
static void C_ccall f_8017(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,2)))){
C_save_and_reclaim((void *)f_8017,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8021,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8456,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_retrieve2(lf[12],C_text("chicken.csi#chop-separator"));
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8463,a[2]=t3,a[3]=((C_word*)t0)[10],a[4]=t6,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1074: collect-options */
t10=((C_word*)((C_word*)t0)[10])[1];
f_7806(t10,t9,lf[345]);}

/* k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in ... */
static void C_ccall f_8021(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_8021,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[123]+1 /* (set! ##sys#include-pathnames ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8024,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[9])){
t4=C_i_cdr(((C_word*)t0)[9]);
t5=C_i_pairp(t4);
if(C_truep(C_i_not(t5))){
/* csi.scm:1080: ##sys#error */
t6=*((C_word*)lf[31]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=lf[338];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t6=C_i_cadr(((C_word*)t0)[9]);
if(C_truep(C_i_string_equal_p(lf[339],t6))){
/* csi.scm:1082: chicken.base#keyword-style */
t7=C_fast_retrieve(lf[125]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=lf[340];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t7=C_u_i_cdr(((C_word*)t0)[9]);
if(C_truep(C_i_string_equal_p(lf[341],C_u_i_car(t7)))){
/* csi.scm:1084: chicken.base#keyword-style */
t8=C_fast_retrieve(lf[125]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t3;
av2[2]=lf[330];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t8=C_u_i_cdr(((C_word*)t0)[9]);
if(C_truep(C_i_string_equal_p(lf[342],C_u_i_car(t8)))){
/* csi.scm:1086: chicken.base#keyword-style */
t9=C_fast_retrieve(lf[125]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t3;
av2[2]=lf[343];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t9=t3;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_UNDEFINED;
f_8024(2,av2);}}}}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_8024(2,av2);}}}

/* k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in ... */
static void C_ccall f_8024(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_8024,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8027,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8389,a[2]=t2,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1087: member* */
f_7385(t3,lf[337],((C_word*)((C_word*)t0)[6])[1]);}

/* k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_ccall f_8027(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_8027,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8030,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8377,a[2]=t2,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1090: member* */
f_7385(t3,lf[335],((C_word*)((C_word*)t0)[6])[1]);}

/* k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in ... */
static void C_ccall f_8030(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_8030,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8033,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8356,a[2]=t2,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1093: member* */
f_7385(t3,lf[333],((C_word*)((C_word*)t0)[6])[1]);}

/* k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in ... */
static void C_ccall f_8033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_8033,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8036,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=C_a_i_cons(&a,2,lf[326],C_fast_retrieve(lf[327]));
/* csi.scm:1102: scheme#eval */
t4=*((C_word*)lf[53]+1);{
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

/* k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in ... */
static void C_ccall f_8036(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_8036,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8039,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=C_a_i_cons(&a,2,lf[288],C_fast_retrieve(lf[325]));
/* csi.scm:1103: scheme#eval */
t4=*((C_word*)lf[53]+1);{
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

/* k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in ... */
static void C_ccall f_8039(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_8039,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8042,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)t0)[8])){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_8042(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8339,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1105: chicken.load#load-verbose */
t4=C_fast_retrieve(lf[324]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in ... */
static void C_ccall f_8042(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_8042,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8045,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8327,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[7],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:1108: member* */
f_7385(t3,lf[319],((C_word*)((C_word*)t0)[6])[1]);}

/* k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in ... */
static void C_ccall f_8045(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_8045,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8048,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t0)[2])){
t3=C_set_block_item(lf[6] /* ##sys#notices-enabled */,0,C_SCHEME_FALSE);
t4=t2;
f_8048(t4,t3);}
else{
t3=t2;
f_8048(t3,C_SCHEME_UNDEFINED);}}

/* k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in ... */
static void C_fcall f_8048(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_8048,2,t0,t1);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8053,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_8053(t5,((C_word*)t0)[5],((C_word*)((C_word*)t0)[6])[1]);}

/* doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in ... */
static void C_fcall f_8053(C_word t0,C_word t1,C_word t2){
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
loop:
if(C_unlikely(!C_demand(C_calculate_demand(24,0,4)))){
C_save_and_reclaim_args((void *)trf_8053,3,t0,t1,t2);}
a=C_alloc(24);
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
if(C_truep(C_i_nullp(((C_word*)t3)[1]))){
t4=C_fast_retrieve(lf[274]);
t5=C_mutate((C_word*)lf[274]+1 /* (set! ##sys#user-read-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4245,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[276]+1 /* (set! ##sys#sharp-number-hook ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_4274,tmp=(C_word)a,a+=2,tmp));
if(C_truep(((C_word*)t0)[2])){
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8069,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1116: chicken.repl#repl */
t8=C_fast_retrieve(lf[277]);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_fast_retrieve(lf[46]);
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}
else{
t4=C_i_car(((C_word*)t3)[1]);
t5=C_i_member(t4,lf[278]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8081,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t5)){
t19=t1;
t20=C_i_cdr(((C_word*)t3)[1]);
t1=t19;
t2=t20;
goto loop;}
else{
if(C_truep((C_truep(C_i_equalp(t4,lf[279]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[280]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[281]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[282]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[283]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[284]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t4,lf[285]))?C_SCHEME_TRUE:C_SCHEME_FALSE))))))))){
t7=C_i_cdr(((C_word*)t3)[1]);
t8=C_set_block_item(t3,0,t7);
t19=t1;
t20=C_i_cdr(((C_word*)t3)[1]);
t1=t19;
t2=t20;
goto loop;}
else{
t7=C_i_string_equal_p(lf[286],t4);
t8=(C_truep(t7)?t7:C_u_i_string_equal_p(lf[287],t4));
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8110,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8122,a[2]=t9,tmp=(C_word)a,a+=3,tmp);
t11=C_i_cadr(((C_word*)t3)[1]);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7709,a[2]=t10,tmp=(C_word)a,a+=3,tmp);
t13=C_i_string_length(t11);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7661,a[2]=t11,a[3]=t15,tmp=(C_word)a,a+=4,tmp));
t17=((C_word*)t15)[1];
f_7661(t17,t12,C_fix(0),t13);}
else{
t9=C_u_i_string_equal_p(lf[296],t4);
t10=(C_truep(t9)?t9:C_u_i_string_equal_p(lf[297],t4));
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8137,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:1126: evalstring */
f_7918(t11,C_i_cadr(((C_word*)t3)[1]),C_SCHEME_END_OF_LIST);}
else{
t11=C_u_i_string_equal_p(lf[298],t4);
t12=(C_truep(t11)?t11:C_u_i_string_equal_p(lf[299],t4));
if(C_truep(t12)){
t13=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8156,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t14=C_i_cadr(((C_word*)t3)[1]);
t15=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8166,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:1129: evalstring */
f_7918(t13,t14,C_a_i_list(&a,1,t15));}
else{
t13=C_u_i_string_equal_p(lf[301],t4);
t14=(C_truep(t13)?t13:C_u_i_string_equal_p(lf[302],t4));
if(C_truep(t14)){
t15=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8181,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t16=C_i_cadr(((C_word*)t3)[1]);
t17=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8191,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:1132: evalstring */
f_7918(t15,t16,C_a_i_list(&a,1,t17));}
else{
t15=(C_truep(((C_word*)t0)[5])?C_i_car(((C_word*)t0)[5]):C_SCHEME_FALSE);
t16=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8201,a[2]=t15,a[3]=t6,a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_equalp(lf[307],t15))){
t17=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8253,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:1136: scheme#load */
t18=*((C_word*)lf[63]+1);{
C_word av2[4];
av2[0]=t18;
av2[1]=t16;
av2[2]=t4;
av2[3]=t17;
((C_proc)(void*)(*((C_word*)t18+1)))(4,av2);}}
else{
/* csi.scm:1136: scheme#load */
t17=*((C_word*)lf[63]+1);{
C_word av2[4];
av2[0]=t17;
av2[1]=t16;
av2[2]=t4;
av2[3]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t17+1)))(4,av2);}}}}}}}}}}

/* k8067 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8069,c,av);}
/* csi.scm:1117: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[88]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[88]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[82]+1);
tp(4,av2);}}

/* k8079 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8081(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8081,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8053(t2,((C_word*)t0)[3],C_i_cdr(((C_word*)((C_word*)t0)[4])[1]));}

/* k8108 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8110,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)((C_word*)t0)[3])[1];
f_8053(t4,((C_word*)t0)[4],C_i_cdr(((C_word*)((C_word*)t0)[2])[1]));}

/* k8120 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8122(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8122,c,av);}
a=C_alloc(6);
t2=C_a_i_list(&a,2,lf[288],t1);
/* csi.scm:1123: scheme#eval */
t3=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8135 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8137(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8137,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)((C_word*)t0)[3])[1];
f_8053(t4,((C_word*)t0)[4],C_i_cdr(((C_word*)((C_word*)t0)[2])[1]));}

/* k8154 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8156(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8156,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)((C_word*)t0)[3])[1];
f_8053(t4,((C_word*)t0)[4],C_i_cdr(((C_word*)((C_word*)t0)[2])[1]));}

/* a8165 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,4)))){
C_save_and_reclaim((void*)f_8166,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[300]+1);
av2[3]=*((C_word*)lf[105]+1);
av2[4]=t2;
C_apply(5,av2);}}

/* k8179 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8181(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8181,c,av);}
t2=C_i_cdr(((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)((C_word*)t0)[3])[1];
f_8053(t4,((C_word*)t0)[4],C_i_cdr(((C_word*)((C_word*)t0)[2])[1]));}

/* a8190 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +0,c,4)))){
C_save_and_reclaim((void*)f_8191,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+0);
t2=C_build_rest(&a,c,2,av);
C_word t3;{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[300]+1);
av2[3]=C_fast_retrieve(lf[44]);
av2[4]=t2;
C_apply(5,av2);}}

/* k8199 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8201(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8201,c,av);}
a=C_alloc(4);
if(C_truep(C_i_equalp(lf[303],((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8212,tmp=(C_word)a,a+=2,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8225,tmp=(C_word)a,a+=2,tmp);
/* csi.scm:1153: ##sys#call-with-values */{
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
t2=((C_word*)((C_word*)t0)[4])[1];
f_8053(t2,((C_word*)t0)[5],C_i_cdr(((C_word*)((C_word*)t0)[6])[1]));}}

/* a8211 in k8199 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_8212(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8212,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8216,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1153: scheme#eval */
t3=*((C_word*)lf[53]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[305];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8214 in a8211 in k8199 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in ... */
static void C_ccall f_8216(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8216,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8223,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1153: chicken.process-context#command-line-arguments */
t3=C_fast_retrieve(lf[304]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8221 in k8214 in a8211 in k8199 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in ... */
static void C_ccall f_8223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8223,c,av);}
/* csi.scm:1153: g2080 */
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

/* a8224 in k8199 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in ... */
static void C_ccall f_8225(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8225,c,av);}
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
if(C_truep(C_fixnump(t3))){
/* csi.scm:1155: chicken.base#exit */
t4=C_fast_retrieve(lf[306]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* csi.scm:1155: chicken.base#exit */
t4=C_fast_retrieve(lf[306]);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* f_8253 in doloop1866 in k8046 in k8043 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in ... */
static void C_ccall f_8253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_8253,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8257,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8308,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1140: chicken.port#with-output-to-string */
t5=C_fast_retrieve(lf[312]);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k8255 */
static void C_ccall f_8257(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8257,c,av);}
a=C_alloc(6);
t2=C_block_size(t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8263,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1142: chicken.base#flush-output */
t4=*((C_word*)lf[311]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=*((C_word*)lf[82]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k8261 in k8255 */
static void C_ccall f_8263(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_8263,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8266,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1143: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[310];
av2[3]=*((C_word*)lf[308]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k8264 in k8261 in k8255 */
static void C_ccall f_8266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_8266,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8269,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8277,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t4,tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_8277(t6,t2,C_fix(0));}

/* k8267 in k8264 in k8261 in k8255 */
static void C_ccall f_8269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8269,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8272,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1150: scheme#newline */
t3=*((C_word*)lf[84]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=*((C_word*)lf[308]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8270 in k8267 in k8264 in k8261 in k8255 */
static void C_ccall f_8272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8272,c,av);}
/* csi.scm:1151: scheme#eval */
t2=*((C_word*)lf[53]+1);{
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

/* doloop2069 in k8264 in k8261 in k8255 */
static void C_fcall f_8277(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_8277,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_i_string_ref(((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8290,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* ##sys#write-char/port */
t5=C_fast_retrieve(lf[244]);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=*((C_word*)lf[308]+1);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k8288 in doloop2069 in k8264 in k8261 in k8255 */
static void C_ccall f_8290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_8290,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8293,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_u_i_char_equalp(C_make_character(10),((C_word*)t0)[5]))){
/* csi.scm:1149: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[309];
av2[3]=*((C_word*)lf[308]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=((C_word*)((C_word*)t0)[2])[1];
f_8277(t3,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}}

/* k8291 in k8288 in doloop2069 in k8264 in k8261 in k8255 */
static void C_ccall f_8293(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8293,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8277(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* a8307 */
static void C_ccall f_8308(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8308,c,av);}
t2=C_fast_retrieve(lf[44]);
/* csi.scm:1140: g2066 */
t3=C_fast_retrieve(lf[44]);{
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

/* k8325 in k8040 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in ... */
static void C_ccall f_8327(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8327,c,av);}
a=C_alloc(3);
t2=(C_truep(t1)?t1:(C_truep(((C_word*)t0)[2])?((C_word*)t0)[2]:((C_word*)t0)[3]));
if(C_truep(t2)){
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_8045(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7857,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1035: chicken.platform#system-config-directory */
t4=C_fast_retrieve(lf[318]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8337 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in ... */
static void C_ccall f_8339(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8339,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8342,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9650,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:144: chicken.platform#chicken-version */
t4=C_fast_retrieve(lf[323]);{
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

/* k8340 in k8337 in k8037 in k8034 in k8031 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in ... */
static void C_ccall f_8342(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8342,c,av);}
/* csi.scm:1107: chicken.base#print */
t2=*((C_word*)lf[105]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[320];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k8354 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in ... */
static void C_ccall f_8356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8356,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8359,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_8359(2,av2);}}
else{
/* csi.scm:1094: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[332];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_8033(2,av2);}}}

/* k8357 in k8354 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in ... */
static void C_ccall f_8359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8359,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8362,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1095: chicken.base#case-sensitive */
t3=C_fast_retrieve(lf[331]);{
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

/* k8360 in k8357 in k8354 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in ... */
static void C_ccall f_8362(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8362,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8365,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1096: chicken.base#keyword-style */
t3=C_fast_retrieve(lf[125]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[330];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8363 in k8360 in k8357 in k8354 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in ... */
static void C_ccall f_8365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8365,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8368,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1097: chicken.base#parentheses-synonyms */
t3=C_fast_retrieve(lf[329]);{
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

/* k8366 in k8363 in k8360 in k8357 in k8354 in k8028 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in ... */
static void C_ccall f_8368(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8368,c,av);}
/* csi.scm:1098: chicken.base#symbol-escape */
t2=C_fast_retrieve(lf[328]);{
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

/* k8375 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in ... */
static void C_ccall f_8377(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8377,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8380,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
/* csi.scm:1092: chicken.base#symbol-escape */
t3=C_fast_retrieve(lf[328]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
/* csi.scm:1091: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[334];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_8030(2,av2);}}}

/* k8378 in k8375 in k8025 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in ... */
static void C_ccall f_8380(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8380,c,av);}
/* csi.scm:1092: chicken.base#symbol-escape */
t2=C_fast_retrieve(lf[328]);{
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

/* k8387 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_ccall f_8389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8389,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8392,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
/* csi.scm:1089: chicken.base#parentheses-synonyms */
t3=C_fast_retrieve(lf[329]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
/* csi.scm:1088: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[336];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_8027(2,av2);}}}

/* k8390 in k8387 in k8022 in k8019 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in ... */
static void C_ccall f_8392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8392,c,av);}
/* csi.scm:1089: chicken.base#parentheses-synonyms */
t2=C_fast_retrieve(lf[329]);{
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

/* k8454 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in ... */
static void C_ccall f_8456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_8456,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3135,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_3135(t5,((C_word*)t0)[2],t1);}

/* k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in ... */
static void C_ccall f_8463(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8463,c,av);}
a=C_alloc(11);
t2=C_i_check_list_2(t1,lf[132]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8469,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8518,a[2]=((C_word*)t0)[4],a[3]=t5,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_8518(t7,t3,t1);}

/* k8467 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in ... */
static void C_ccall f_8469(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_8469,c,av);}
a=C_alloc(11);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_retrieve2(lf[12],C_text("chicken.csi#chop-separator"));
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8476,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1075: collect-options */
t8=((C_word*)((C_word*)t0)[3])[1];
f_7806(t8,t7,lf[344]);}

/* k8474 in k8467 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_ccall f_8476(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8476,c,av);}
a=C_alloc(11);
t2=C_i_check_list_2(t1,lf[132]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8482,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8484,a[2]=((C_word*)t0)[4],a[3]=t5,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_8484(t7,t3,t1);}

/* k8480 in k8474 in k8467 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in ... */
static void C_ccall f_8482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8482,c,av);}
/* csi.scm:1074: scheme#append */
t2=*((C_word*)lf[225]+1);{
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
av2[4]=C_fast_retrieve(lf[123]);
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* map-loop1967 in k8474 in k8467 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in ... */
static void C_fcall f_8484(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8484,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8509,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1075: g1973 */
t4=C_retrieve2(lf[12],C_text("chicken.csi#chop-separator"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_3915(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8507 in map-loop1967 in k8474 in k8467 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in ... */
static void C_ccall f_8509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8509,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8484(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop1941 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in ... */
static void C_fcall f_8518(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8518,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8543,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* csi.scm:1074: g1947 */
t4=C_retrieve2(lf[12],C_text("chicken.csi#chop-separator"));{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
f_3915(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8541 in map-loop1941 in k8461 in k8015 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in ... */
static void C_ccall f_8543(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8543,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8518(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* for-each-loop1858 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in ... */
static void C_fcall f_8552(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8552,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8562,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:1071: g1859 */
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

/* k8560 in for-each-loop1858 in k8009 in k8006 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in ... */
static void C_ccall f_8562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8562,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8552(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1848 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in ... */
static void C_fcall f_8575(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8575,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8585,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:1070: g1849 */
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

/* k8583 in for-each-loop1848 in k8000 in k7997 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in ... */
static void C_ccall f_8585(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8585,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8575(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop1838 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in ... */
static void C_fcall f_8598(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8598,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8608,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* csi.scm:1069: g1839 */
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

/* k8606 in for-each-loop1838 in k7991 in k7988 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in ... */
static void C_ccall f_8608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8608,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8598(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k8620 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_8622(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8622,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8625,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f9676,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1067: chicken.platform#register-feature! */
t4=C_fast_retrieve(lf[272]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[349];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* csi.scm:1066: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[350];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_7990(2,av2);}}}

/* k8623 in k8620 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in ... */
static void C_ccall f_8625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8625,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8628,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:1067: chicken.platform#register-feature! */
t3=C_fast_retrieve(lf[272]);{
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

/* k8626 in k8623 in k8620 in k7985 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in ... */
static void C_ccall f_8628(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8628,c,av);}
/* csi.scm:1068: chicken.base#case-sensitive */
t2=C_fast_retrieve(lf[331]);{
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

/* k8635 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in ... */
static void C_ccall f_8637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8637,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8640,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=C_set_block_item(lf[352] /* ##sys#warnings-enabled */,0,C_SCHEME_FALSE);
t4=((C_word*)t0)[2];
f_7987(t4,t3);}
else{
/* csi.scm:1063: scheme#display */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[353];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}
else{
t2=((C_word*)t0)[2];
f_7987(t2,C_SCHEME_UNDEFINED);}}

/* k8638 in k8635 in k7982 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in ... */
static void C_ccall f_8640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8640,c,av);}
t2=C_set_block_item(lf[352] /* ##sys#warnings-enabled */,0,C_SCHEME_FALSE);
t3=((C_word*)t0)[2];
f_7987(t3,t2);}

/* k8648 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_8650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8650,c,av);}
/* csi.scm:1061: chicken.base#exit */
t2=C_fast_retrieve(lf[306]);{
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

/* k8655 in k7979 in k7976 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in ... */
static void C_ccall f_8657(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8657,c,av);}
/* csi.scm:1060: chicken.base#print */
t2=*((C_word*)lf[105]+1);{
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

/* k8665 in k7973 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_8667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8667,c,av);}
/* csi.scm:1056: chicken.base#exit */
t2=C_fast_retrieve(lf[306]);{
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

/* k8671 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_8673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8673,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8676,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3866,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:95: scheme#display */
t4=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[363];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_7975(2,av2);}}}

/* k8674 in k8671 in k7799 in k7796 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in ... */
static void C_ccall f_8676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8676,c,av);}
/* csi.scm:1053: chicken.base#exit */
t2=C_fast_retrieve(lf[306]);{
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

/* k8683 in k7793 in k7790 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_8685(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8685,c,av);}
t2=((C_word*)t0)[2];
f_7798(t2,(C_truep(t1)?t1:((C_word*)t0)[3]));}

/* k8689 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_8691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8691,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8694,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1010: chicken.process-context#program-name */
t3=C_fast_retrieve(lf[369]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8692 in k8689 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in ... */
static void C_ccall f_8694(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8694,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8697,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_u_i_cdr(((C_word*)t0)[2]);
/* csi.scm:1011: chicken.process-context#command-line-arguments */
t4=C_fast_retrieve(lf[304]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=C_u_i_cdr(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k8695 in k8692 in k8689 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in ... */
static void C_ccall f_8697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8697,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8700,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1013: chicken.platform#register-feature! */
t3=C_fast_retrieve(lf[272]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[368];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k8698 in k8695 in k8692 in k8689 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in ... */
static void C_ccall f_8700(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8700,c,av);}
a=C_alloc(4);
t2=C_i_set_i_slot(C_u_i_cdr(((C_word*)t0)[2]),C_fix(1),C_SCHEME_END_OF_LIST);
if(C_truep(*((C_word*)lf[11]+1))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8709,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:1016: lookup-script-file */
t4=C_retrieve2(lf[17],C_text("chicken.csi#lookup-script-file"));
f_4012(t4,t3,C_i_cadr(((C_word*)t0)[2]));}
else{
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[3];
f_7792(t4,t3);}}

/* k8707 in k8698 in k8695 in k8692 in k8689 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in ... */
static void C_ccall f_8709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8709,c,av);}
t2=((C_word*)t0)[2];
f_7792(t2,(C_truep(t1)?C_i_set_car(C_u_i_cdr(((C_word*)t0)[3]),t1):C_SCHEME_FALSE));}

/* k8772 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_8774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8774,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_i_member(lf[371],((C_word*)((C_word*)t0)[2])[1]);
t4=((C_word*)t0)[3];
f_7792(t4,(C_truep(t3)?C_i_set_cdr(t3,C_SCHEME_END_OF_LIST):C_SCHEME_FALSE));}

/* k8785 in k7787 in k7784 in k7781 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in ... */
static void C_ccall f_8787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8787,c,av);}
/* csi.scm:1019: scheme#append */
t2=*((C_word*)lf[225]+1);{
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

/* k8789 in k7778 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_8791(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8791,c,av);}
/* csi.scm:1001: canonicalize-args */
f_7440(((C_word*)t0)[2],t1);}

/* k8793 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8795,c,av);}
a=C_alloc(4);
t2=(C_truep(t1)?t1:lf[374]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_4939,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* csi.scm:433: chicken.base#open-input-string */
t4=C_fast_retrieve(lf[271]);{
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

/* k8799 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8801(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8801,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8807,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken.base#implicit-exit-handler */
t3=C_fast_retrieve(lf[268]);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8805 in k8799 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_8807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8807,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a8808 in k5399 in k5076 in k4931 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8809(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8809,c,av);}
/* csi.scm:919: ##sys#user-interrupt-hook */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[253]);
C_word *av2=av;
av2[0]=*((C_word*)lf[253]+1);
av2[1]=t1;
tp(2,av2);}}

/* a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8815(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8815,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8819,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:417: scheme#read */
t3=*((C_word*)lf[291]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8817 in a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_8819,c,av);}
a=C_alloc(7);
if(C_truep(C_i_not(t1))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8828,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:419: ##sys#switch-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[383]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[383]+1);
av2[1]=t2;
av2[2]=C_SCHEME_FALSE;
tp(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8834,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8855,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:421: ##sys#resolve-module-name */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[387]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[387]+1);
av2[1]=t3;
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}}

/* k8826 in k8817 in a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8828,c,av);}
/* csi.scm:420: printf */
t2=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[382];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k8832 in k8817 in a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8834,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8838,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:418: g1010 */
t3=t2;
f_8838(t3,((C_word*)t0)[3],t1);}
else{
/* csi.scm:426: printf */
t2=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[385];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* g1010 in k8832 in k8817 in a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_fcall f_8838(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_8838,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8842,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* csi.scm:423: ##sys#switch-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[383]);
C_word av2[3];
av2[0]=*((C_word*)lf[383]+1);
av2[1]=t3;
av2[2]=t2;
tp(3,av2);}}

/* k8840 in g1010 in k8832 in k8817 in a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 in ... */
static void C_ccall f_8842(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8842,c,av);}
/* csi.scm:424: printf */
t2=*((C_word*)lf[75]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[384];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k8853 in k8817 in a8814 in k4283 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8855,c,av);}
/* csi.scm:421: ##sys#find-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[386]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[386]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
tp(4,av2);}}

/* a8856 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8857,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8865,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:250: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[394]);
C_word *av2=av;
av2[0]=*((C_word*)lf[394]+1);
av2[1]=t2;
tp(2,av2);}}

/* k8863 in a8856 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_8865,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8868,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8875,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* csi.scm:252: ##sys#module-name */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[392]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[392]+1);
av2[1]=t3;
av2[2]=t1;
tp(3,av2);}}
else{
/* csi.scm:249: sprintf */
t3=*((C_word*)lf[189]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[390];
av2[3]=lf[393];
av2[4]=C_retrieve2(lf[26],C_text("chicken.csi#history-count"));
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k8866 in k8863 in a8856 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8868(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8868,c,av);}
/* csi.scm:249: sprintf */
t2=*((C_word*)lf[189]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[390];
av2[3]=t1;
av2[4]=C_retrieve2(lf[26],C_text("chicken.csi#history-count"));
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k8873 in k8863 in a8856 in k3940 in k3858 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8875,c,av);}
/* csi.scm:252: sprintf */
t2=*((C_word*)lf[189]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[391];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k8877 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8879,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];
f_3860(t2,t1);}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8888,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* csi.scm:87: chicken.process-context#get-environment-variable */
t3=C_fast_retrieve(lf[23]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[399];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k8886 in k8877 in k3855 in k3850 in k2560 in k2557 in k2554 in k2551 in k2548 in k2545 in k2542 in k2539 in k2536 in k2533 in k2530 in k2527 */
static void C_ccall f_8888(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8888,c,av);}
t2=((C_word*)t0)[2];
f_3860(t2,(C_truep(t1)?lf[397]:lf[398]));}

/* a8889 in k2530 in k2527 */
static void C_ccall f_8890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_8890,c,av);}
/* csi.scm:43: ##sys#register-compiled-module */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[403]);
C_word *av2;
if(c >= 9) {
  av2=av;
} else {
  av2=C_alloc(9);
}
av2[0]=*((C_word*)lf[403]+1);
av2[1]=t1;
av2[2]=lf[404];
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=lf[405];
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
if(C_unlikely(!C_demand_2(2020))){
C_save(t1);
C_rereclaim2(2020*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,407);
lf[0]=C_h_intern(&lf[0],12, C_text("chicken.csi#"));
lf[2]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005csirc"));
lf[3]=C_h_intern(&lf[3],29, C_text("##sys#repl-print-length-limit"));
lf[4]=C_h_intern_kw(&lf[4],3, C_text("csi"));
lf[5]=C_h_intern(&lf[5],14, C_text("##sys#features"));
lf[6]=C_h_intern(&lf[6],21, C_text("##sys#notices-enabled"));
lf[7]=C_h_intern(&lf[7],26, C_text("chicken.csi#editor-command"));
lf[11]=C_h_intern(&lf[11],22, C_text("##sys#windows-platform"));
lf[13]=C_h_intern(&lf[13],16, C_text("scheme#substring"));
lf[14]=C_h_intern(&lf[14],25, C_text("chicken.file#file-exists\077"));
lf[15]=C_h_intern(&lf[15],19, C_text("##sys#string-append"));
lf[16]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004.bat"));
lf[18]=C_h_intern(&lf[18],20, C_text("scheme#string-append"));
lf[19]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[20]=C_h_intern(&lf[20],27, C_text("##sys#peek-nonnull-c-string"));
lf[21]=C_h_intern(&lf[21],16, C_text("##sys#split-path"));
lf[22]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[23]=C_h_intern(&lf[23],48, C_text("chicken.process-context#get-environment-variable"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004PATH"));
lf[27]=C_h_intern(&lf[27],26, C_text("chicken.base#vector-resize"));
lf[29]=C_h_intern(&lf[29],21, C_text("##sys#undefined-value"));
lf[31]=C_h_intern(&lf[31],11, C_text("##sys#error"));
lf[32]=C_decode_literal(C_heaptop,C_text("\376B\000\000 history entry index out of range"));
lf[33]=C_h_intern(&lf[33],21, C_text("scheme#inexact->exact"));
lf[34]=C_h_intern(&lf[34],22, C_text("##sys#read-prompt-hook"));
lf[35]=C_h_intern(&lf[35],15, C_text("##sys#tty-port\077"));
lf[36]=C_h_intern(&lf[36],20, C_text("##sys#standard-input"));
lf[38]=C_h_intern(&lf[38],28, C_text("chicken.csi#toplevel-command"));
lf[39]=C_h_intern(&lf[39],16, C_text("toplevel-command"));
lf[40]=C_h_intern(&lf[40],25, C_text("chicken.load#load-noisily"));
lf[41]=C_h_intern(&lf[41],20, C_text("chicken.io#read-line"));
lf[42]=C_h_intern(&lf[42],27, C_text("chicken.string#string-split"));
lf[43]=C_h_intern(&lf[43],21, C_text("chicken.syntax#expand"));
lf[44]=C_h_intern(&lf[44],33, C_text("chicken.pretty-print#pretty-print"));
lf[45]=C_h_intern(&lf[45],13, C_text("scheme#values"));
lf[46]=C_h_intern(&lf[46],29, C_text("chicken.csi#default-evaluator"));
lf[47]=C_h_intern(&lf[47],17, C_text("chicken.repl#quit"));
lf[48]=C_h_intern(&lf[48],7, C_text("unquote"));
lf[49]=C_h_intern(&lf[49],1, C_text("x"));
lf[50]=C_h_intern(&lf[50],27, C_text("chicken.syntax#strip-syntax"));
lf[51]=C_h_intern(&lf[51],36, C_text("chicken.syntax#read-with-source-info"));
lf[52]=C_h_intern(&lf[52],1, C_text("p"));
lf[53]=C_h_intern(&lf[53],11, C_text("scheme#eval"));
lf[54]=C_h_intern(&lf[54],1, C_text("d"));
lf[56]=C_h_intern(&lf[56],2, C_text("du"));
lf[58]=C_h_intern(&lf[58],3, C_text("dur"));
lf[59]=C_h_intern(&lf[59],1, C_text("r"));
lf[61]=C_h_intern(&lf[61],1, C_text("q"));
lf[62]=C_h_intern(&lf[62],1, C_text("l"));
lf[63]=C_h_intern(&lf[63],11, C_text("scheme#load"));
lf[64]=C_h_intern(&lf[64],2, C_text("ln"));
lf[65]=C_h_intern(&lf[65],19, C_text("chicken.base#print\052"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004==> "));
lf[67]=C_h_intern_kw(&lf[67],7, C_text("printer"));
lf[68]=C_h_intern(&lf[68],1, C_text("t"));
lf[69]=C_h_intern(&lf[69],19, C_text("##sys#display-times"));
lf[70]=C_h_intern(&lf[70],16, C_text("##sys#stop-timer"));
lf[71]=C_h_intern(&lf[71],17, C_text("##sys#start-timer"));
lf[72]=C_h_intern(&lf[72],3, C_text("exn"));
lf[73]=C_h_intern(&lf[73],20, C_text("##sys#last-exception"));
lf[74]=C_h_intern(&lf[74],1, C_text("e"));
lf[75]=C_h_intern(&lf[75],21, C_text("chicken.format#printf"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000,editor returned with non-zero exit status ~a"));
lf[77]=C_h_intern(&lf[77],22, C_text("chicken.process#system"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[79]=C_h_intern(&lf[79],2, C_text("ch"));
lf[80]=C_h_intern(&lf[80],19, C_text("scheme#vector-fill!"));
lf[81]=C_h_intern(&lf[81],1, C_text("h"));
lf[82]=C_h_intern(&lf[82],21, C_text("##sys#standard-output"));
lf[83]=C_h_intern(&lf[83],6, C_text("printf"));
lf[84]=C_h_intern(&lf[84],14, C_text("scheme#newline"));
lf[85]=C_h_intern(&lf[85],11, C_text("##sys#print"));
lf[86]=C_h_intern(&lf[86],29, C_text("##sys#with-print-length-limit"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[88]=C_h_intern(&lf[88],18, C_text("##sys#write-char-0"));
lf[89]=C_h_intern(&lf[89],1, C_text("c"));
lf[91]=C_h_intern(&lf[91],1, C_text("f"));
lf[92]=C_h_intern(&lf[92],14, C_text("scheme#display"));
lf[93]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016no such frame\012"));
lf[94]=C_h_intern(&lf[94],28, C_text("##sys#repl-recent-call-chain"));
lf[95]=C_h_intern(&lf[95],1, C_text("g"));
lf[96]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027no environment in frame"));
lf[97]=C_h_intern(&lf[97],9, C_text("frameinfo"));
lf[98]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012; getting "));
lf[99]=C_h_intern(&lf[99],8, C_text("for-each"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022no such variable: "));
lf[101]=C_h_intern(&lf[101],20, C_text("chicken.base#call/cc"));
lf[102]=C_decode_literal(C_heaptop,C_text("\376B\000\000#string or symbol required for `,g\047\012"));
lf[103]=C_h_intern(&lf[103],1, C_text("s"));
lf[104]=C_h_intern(&lf[104],1, C_text("\077"));
lf[105]=C_h_intern(&lf[105],18, C_text("chicken.base#print"));
lf[106]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002 ,"));
lf[107]=C_decode_literal(C_heaptop,C_text("\376B\000\003\266Toplevel commands:\012\012 ,\077                Show this text\012 ,p EXP            Pr"
"etty print evaluated expression EXP\012 ,d EXP            Describe result of evalua"
"ted expression EXP\012 ,du EXP           Dump data of expression EXP\012 ,dur EXP N   "
"     Dump range\012 ,q                Quit interpreter\012 ,l FILENAME ...   Load one "
"or more files\012 ,ln FILENAME ...  Load one or more files and print result of each"
" top-level expression\012 ,r                Show system information\012 ,h            "
"    Show history of expression results\012 ,ch               Clear history of expre"
"ssion results\012 ,e FILENAME       Run external editor\012 ,s TEXT ...       Execute "
"shell-command\012 ,exn              Describe last exception\012 ,c                Show"
" call-chain of most recent error\012 ,f N              Select frame N\012 ,g NAME     "
"      Get variable NAME from current frame\012 ,t EXP            Evaluate form and "
"print elapsed time\012 ,x EXP            Pretty print expanded expression EXP\012"));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\0005undefined toplevel command ~s - enter `,\077\047 for help~%"));
lf[109]=C_h_intern(&lf[109],17, C_text("chicken.sort#sort"));
lf[110]=C_h_intern(&lf[110],32, C_text("chicken.port#with-output-to-port"));
lf[111]=C_h_intern(&lf[111],28, C_text("chicken.process-context#argv"));
lf[112]=C_h_intern(&lf[112],9, C_text("##sys#/-2"));
lf[113]=C_h_intern(&lf[113],15, C_text("scheme#truncate"));
lf[114]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[115]=C_h_intern(&lf[115],18, C_text("scheme#make-string"));
lf[116]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004  ~a"));
lf[117]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027interrupts are enabled\012"));
lf[118]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010 (fixed)"));
lf[119]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[120]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010downward"));
lf[121]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006upward"));
lf[122]=C_decode_literal(C_heaptop,C_text("\376B\000\002\362~%~%~\012                   Machine type:    \011~A (~A-bit)~%~\012                 "
"  Software type:   \011~A~%~\012                   Software version:\011~A~%~\012           "
"        Build platform:  \011~A~%~\012                   Installation prefix:\011~A~%~\012  "
"                 Extension installation location:\011~A~%~\012                   Exten"
"sion path:  \011~A~%~\012                   Include path:    \011~A~%~\012                  "
" Keyword style:   \011~A~%~\012                   Symbol-table load:\011~S~%  ~\012         "
"            Avg bucket length:\011~S~%  ~\012                     Total symbol count:\011"
"~S~%~\012                   Memory:\011heap size is ~S bytes~A with ~S bytes currently"
" in use~%~  \012                     nursery size is ~S bytes, stack grows ~A~%~\012  "
"                 Command line:    \011~S~%"));
lf[123]=C_h_intern(&lf[123],23, C_text("##sys#include-pathnames"));
lf[124]=C_h_intern(&lf[124],31, C_text("chicken.keyword#keyword->string"));
lf[125]=C_h_intern(&lf[125],26, C_text("chicken.base#keyword-style"));
lf[126]=C_h_intern(&lf[126],32, C_text("chicken.platform#repository-path"));
lf[127]=C_h_intern(&lf[127],40, C_text("chicken.platform#installation-repository"));
lf[128]=C_h_intern(&lf[128],31, C_text("chicken.platform#build-platform"));
lf[129]=C_h_intern(&lf[129],33, C_text("chicken.platform#software-version"));
lf[130]=C_h_intern(&lf[130],30, C_text("chicken.platform#software-type"));
lf[131]=C_h_intern(&lf[131],29, C_text("chicken.platform#machine-type"));
lf[132]=C_h_intern(&lf[132],3, C_text("map"));
lf[133]=C_h_intern(&lf[133],15, C_text("scheme#string<\077"));
lf[134]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015Features:~%~%"));
lf[135]=C_h_intern(&lf[135],28, C_text("chicken.gc#memory-statistics"));
lf[136]=C_h_intern(&lf[136],23, C_text("##sys#symbol-table-info"));
lf[137]=C_h_intern(&lf[137],13, C_text("chicken.gc#gc"));
lf[139]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001u8vector\376\003\000\000\002\376B\000\000\030vector of unsigned bytes\376\003\000\000\002\376\001\000\000\017\001u8vector-le"
"ngth\376\003\000\000\002\376\001\000\000\014\001u8vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001s8vector\376\003\000\000\002\376B\000\000\026vector of signed"
" bytes\376\003\000\000\002\376\001\000\000\017\001s8vector-length\376\003\000\000\002\376\001\000\000\014\001s8vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u16vec"
"tor\376\003\000\000\002\376B\000\000\037vector of unsigned 16-bit words\376\003\000\000\002\376\001\000\000\020\001u16vector-length\376\003\000\000\002\376\001\000\000"
"\015\001u16vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s16vector\376\003\000\000\002\376B\000\000\035vector of signed 16-bit wor"
"ds\376\003\000\000\002\376\001\000\000\020\001s16vector-length\376\003\000\000\002\376\001\000\000\015\001s16vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u32vecto"
"r\376\003\000\000\002\376B\000\000\037vector of unsigned 32-bit words\376\003\000\000\002\376\001\000\000\020\001u32vector-length\376\003\000\000\002\376\001\000\000\015\001"
"u32vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s32vector\376\003\000\000\002\376B\000\000\035vector of signed 32-bit words"
"\376\003\000\000\002\376\001\000\000\020\001s32vector-length\376\003\000\000\002\376\001\000\000\015\001s32vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001u64vector\376"
"\003\000\000\002\376B\000\000\037vector of unsigned 64-bit words\376\003\000\000\002\376\001\000\000\020\001u64vector-length\376\003\000\000\002\376\001\000\000\015\001u6"
"4vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001s64vector\376\003\000\000\002\376B\000\000\035vector of signed 64-bit words\376\003"
"\000\000\002\376\001\000\000\020\001s64vector-length\376\003\000\000\002\376\001\000\000\015\001s64vector-ref\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001f32vector\376\003\000"
"\000\002\376B\000\000\027vector of 32-bit floats\376\003\000\000\002\376\001\000\000\020\001f32vector-length\376\003\000\000\002\376\001\000\000\015\001f32vector-re"
"f\376\377\016\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001f64vector\376\003\000\000\002\376B\000\000\027vector of 64-bit floats\376\003\000\000\002\376\001\000\000\020\001f64vect"
"or-length\376\003\000\000\002\376\001\000\000\015\001f64vector-ref\376\377\016\376\377\016"));
lf[141]=C_h_intern(&lf[141],13, C_text("scheme#length"));
lf[142]=C_h_intern(&lf[142],15, C_text("scheme#list-ref"));
lf[143]=C_h_intern(&lf[143],17, C_text("scheme#string-ref"));
lf[144]=C_h_intern(&lf[144],22, C_text("chicken.format#fprintf"));
lf[145]=C_decode_literal(C_heaptop,C_text("\376B\000\000 ~% (~A elements not displayed)~%"));
lf[146]=C_decode_literal(C_heaptop,C_text("\376B\000\000.\011(followed by ~A identical instance~a)~% ...~%"));
lf[147]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[148]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001s"));
lf[149]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007 ~S: ~S"));
lf[150]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021~A of length ~S~%"));
lf[151]=C_decode_literal(C_heaptop,C_text("\376B\000\000$character ~S, code: ~S, #x~X, #o~O~%"));
lf[152]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016boolean true~%"));
lf[153]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017boolean false~%"));
lf[154]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014empty list~%"));
lf[155]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025broken weak pointer~%"));
lf[156]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024end-of-file object~%"));
lf[157]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024unspecified object~%"));
lf[158]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016, character ~S"));
lf[159]=C_decode_literal(C_heaptop,C_text("\376B\000\0002exact immediate integer ~S~%  #x~X~%  #o~O~%  #b~B"));
lf[160]=C_decode_literal(C_heaptop,C_text("\376B\000\0000exact large integer ~S~%  #x~X~%  #o~O~%  #b~B~%"));
lf[161]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017unbound value~%"));
lf[162]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034inexact rational number ~S~%"));
lf[163]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020exact ratio ~S~%"));
lf[164]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026~A complex number ~S~%"));
lf[165]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005exact"));
lf[166]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007inexact"));
lf[167]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013number ~S~%"));
lf[168]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006string"));
lf[169]=C_h_intern(&lf[169],10, C_text("##sys#size"));
lf[170]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006vector"));
lf[171]=C_h_intern(&lf[171],10, C_text("##sys#slot"));
lf[172]=C_decode_literal(C_heaptop,C_text("\376B\000\000\035keyword symbol with name ~s~%"));
lf[173]=C_h_intern(&lf[173],20, C_text("##sys#symbol->string"));
lf[174]=C_h_intern(&lf[174],12, C_text("scheme#write"));
lf[175]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005  ~s\011"));
lf[176]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020  \012properties:\012\012"));
lf[177]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[178]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013uninterned "));
lf[179]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027~asymbol with name ~S~%"));
lf[180]=C_h_intern(&lf[180],22, C_text("##sys#interned-symbol\077"));
lf[181]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010unbound "));
lf[182]=C_h_intern(&lf[182],34, C_text("##sys#symbol-has-toplevel-binding\077"));
lf[183]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005eol~%"));
lf[184]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012(circle)~%"));
lf[185]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006~S -> "));
lf[186]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024circular structure: "));
lf[187]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004list"));
lf[188]=C_decode_literal(C_heaptop,C_text("\376B\000\000\036pair with car ~S~%and cdr ~S~%"));
lf[189]=C_h_intern(&lf[189],22, C_text("chicken.format#sprintf"));
lf[190]=C_decode_literal(C_heaptop,C_text("\376B\000\000 procedure with code pointer 0x~X"));
lf[191]=C_h_intern(&lf[191],27, C_text("##sys#peek-unsigned-integer"));
lf[192]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005input"));
lf[193]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006output"));
lf[194]=C_decode_literal(C_heaptop,C_text("\376B\000\0005~A port of type ~A with name ~S and file pointer ~X~%"));
lf[195]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032unknown immediate object~%"));
lf[196]=C_decode_literal(C_heaptop,C_text("\376B\000\000/locative~%  pointer ~X~%  index ~A~%  type ~A~%"));
lf[197]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004slot"));
lf[198]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004char"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010u8vector"));
lf[200]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010s8vector"));
lf[201]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011u16vector"));
lf[202]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011s16vector"));
lf[203]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011u32vector"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011s32vector"));
lf[205]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011u64vector"));
lf[206]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011s64vector"));
lf[207]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011f32vector"));
lf[208]=C_decode_literal(C_heaptop,C_text("\376B\000\000\011f64vector"));
lf[209]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024machine pointer ~X~%"));
lf[211]=C_h_intern(&lf[211],10, C_text("##sys#byte"));
lf[212]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022blob of size ~S:~%"));
lf[213]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030lambda information: ~s~%"));
lf[214]=C_h_intern(&lf[214],25, C_text("##sys#lambda-info->string"));
lf[215]=C_h_intern(&lf[215],10, C_text("hash-table"));
lf[216]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013 ~S\011-> ~S~%"));
lf[217]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025  hash function: ~a~%"));
lf[218]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[219]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001s"));
lf[220]=C_decode_literal(C_heaptop,C_text("\376B\000\000:hash-table with ~S element~a~%  comparison procedure: ~A~%"));
lf[221]=C_h_intern(&lf[221],9, C_text("condition"));
lf[222]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007\011~s: ~s"));
lf[223]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005 ~s~%"));
lf[224]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017condition: ~s~%"));
lf[225]=C_h_intern(&lf[225],13, C_text("scheme#append"));
lf[226]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031structure of type `~S\047:~%"));
lf[227]=C_h_intern(&lf[227],31, C_text("chicken.internal#hash-table-ref"));
lf[228]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020unknown object~%"));
lf[229]=C_h_intern(&lf[229],17, C_text("##sys#bytevector\077"));
lf[230]=C_h_intern(&lf[230],15, C_text("##sys#locative\077"));
lf[231]=C_h_intern(&lf[231],18, C_text("chicken.base#port\077"));
lf[232]=C_h_intern(&lf[232],24, C_text("chicken.keyword#keyword\077"));
lf[233]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034statically allocated (0x~X) "));
lf[234]=C_h_intern(&lf[234],19, C_text("##sys#block-address"));
lf[235]=C_h_intern(&lf[235],26, C_text("chicken.csi#set-describer!"));
lf[236]=C_h_intern(&lf[236],14, C_text("set-describer!"));
lf[237]=C_h_intern(&lf[237],32, C_text("chicken.internal#hash-table-set!"));
lf[238]=C_h_intern(&lf[238],10, C_text("scheme#min"));
lf[239]=C_h_intern(&lf[239],4, C_text("dump"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034cannot dump immediate object"));
lf[241]=C_h_intern(&lf[241],15, C_text("##sys#peek-byte"));
lf[242]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022cannot dump object"));
lf[243]=C_h_intern(&lf[243],20, C_text("##sys#number->string"));
lf[244]=C_h_intern(&lf[244],21, C_text("##sys#write-char/port"));
lf[245]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003   "));
lf[246]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004:\011  "));
lf[247]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[248]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006  ---\012"));
lf[249]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002] "));
lf[250]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003\011  "));
lf[251]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002[]"));
lf[252]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[253]=C_h_intern(&lf[253],25, C_text("##sys#user-interrupt-hook"));
lf[254]=C_h_intern(&lf[254],19, C_text("##sys#signal-vector"));
lf[257]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000k\376\003\000\000\002\376\377\012\000\000s\376\003\000\000\002\376\377\012\000\000h\376\003\000\000\002\376\377\012\000\000D\376\003\000\000\002\376\377\012\000\000e\376\003\000\000\002\376\377\012\000\000i\376\003\000\000\002\376\377\012\000\000R\376\003\000"
"\000\002\376\377\012\000\000b\376\003\000\000\002\376\377\012\000\000n\376\003\000\000\002\376\377\012\000\000q\376\003\000\000\002\376\377\012\000\000w\376\003\000\000\002\376\377\012\000\000-\376\003\000\000\002\376\377\012\000\000I\376\003\000\000\002\376\377\012\000\000p\376\003\000\000\002\376"
"\377\012\000\000P\376\003\000\000\002\376\377\012\000\000K\376\377\016"));
lf[259]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-s"));
lf[260]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003-ss"));
lf[261]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007-script"));
lf[262]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003-sx"));
lf[263]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002--"));
lf[264]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016invalid option"));
lf[265]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016invalid option"));
lf[266]=C_h_intern(&lf[266],18, C_text("##sys#string->list"));
lf[267]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\003-ss\376\003\000\000\002\376B\000\000\003-sx\376\003\000\000\002\376B\000\000\007-script\376\003\000\000\002\376B\000\000\010-version\376\003\000\000\002\376B\000\000\005-help\376\003\000\000"
"\002\376B\000\000\006--help\376\003\000\000\002\376B\000\000\010-feature\376\003\000\000\002\376B\000\000\013-no-feature\376\003\000\000\002\376B\000\000\005-eval\376\003\000\000\002\376B\000\000\021-cas"
"e-insensitive\376\003\000\000\002\376B\000\000\016-keyword-style\376\003\000\000\002\376B\000\000\030-no-parentheses-synonyms\376\003\000\000\002\376B\000\000"
"\021-no-symbol-escape\376\003\000\000\002\376B\000\000\014-r5rs-syntax\376\003\000\000\002\376B\000\000\013-setup-mode\376\003\000\000\002\376B\000\000\022-require-"
"extension\376\003\000\000\002\376B\000\000\006-batch\376\003\000\000\002\376B\000\000\006-quiet\376\003\000\000\002\376B\000\000\014-no-warnings\376\003\000\000\002\376B\000\000\010-no-ini"
"t\376\003\000\000\002\376B\000\000\015-include-path\376\003\000\000\002\376B\000\000\010-release\376\003\000\000\002\376B\000\000\006-print\376\003\000\000\002\376B\000\000\015-pretty-prin"
"t\376\003\000\000\002\376B\000\000\002--\376\377\016"));
lf[268]=C_h_intern(&lf[268],34, C_text("chicken.base#implicit-exit-handler"));
lf[269]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047missing argument to command-line option"));
lf[270]=C_h_intern(&lf[270],10, C_text("##sys#list"));
lf[271]=C_h_intern(&lf[271],30, C_text("chicken.base#open-input-string"));
lf[272]=C_h_intern(&lf[272],34, C_text("chicken.platform#register-feature!"));
lf[273]=C_h_intern(&lf[273],36, C_text("chicken.platform#unregister-feature!"));
lf[274]=C_h_intern(&lf[274],20, C_text("##sys#user-read-hook"));
lf[275]=C_h_intern(&lf[275],5, C_text("quote"));
lf[276]=C_h_intern(&lf[276],23, C_text("##sys#sharp-number-hook"));
lf[277]=C_h_intern(&lf[277],17, C_text("chicken.repl#repl"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002--\376\003\000\000\002\376B\000\000\002-b\376\003\000\000\002\376B\000\000\006-batch\376\003\000\000\002\376B\000\000\002-q\376\003\000\000\002\376B\000\000\006-quiet\376\003\000\000\002\376B\000\000\002-n"
"\376\003\000\000\002\376B\000\000\010-no-init\376\003\000\000\002\376B\000\000\002-w\376\003\000\000\002\376B\000\000\014-no-warnings\376\003\000\000\002\376B\000\000\002-i\376\003\000\000\002\376B\000\000\021-case-"
"insensitive\376\003\000\000\002\376B\000\000\030-no-parentheses-synonyms\376\003\000\000\002\376B\000\000\021-no-symbol-escape\376\003\000\000\002\376B\000"
"\000\014-r5rs-syntax\376\003\000\000\002\376B\000\000\013-setup-mode\376\003\000\000\002\376B\000\000\003-ss\376\003\000\000\002\376B\000\000\003-sx\376\003\000\000\002\376B\000\000\002-s\376\003\000\000\002\376B"
"\000\000\007-script\376\377\016"));
lf[279]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-D"));
lf[280]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-feature"));
lf[281]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-I"));
lf[282]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-include-path"));
lf[283]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-K"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016-keyword-style"));
lf[285]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013-no-feature"));
lf[286]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-R"));
lf[287]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022-require-extension"));
lf[288]=C_h_intern(&lf[288],6, C_text("import"));
lf[289]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034invalid import specification"));
lf[290]=C_h_intern(&lf[290],35, C_text("chicken.port#with-input-from-string"));
lf[291]=C_h_intern(&lf[291],11, C_text("scheme#read"));
lf[292]=C_h_intern(&lf[292],40, C_text("chicken.condition#with-exception-handler"));
lf[293]=C_h_intern(&lf[293],37, C_text("scheme#call-with-current-continuation"));
lf[294]=C_h_intern(&lf[294],21, C_text("scheme#string->symbol"));
lf[295]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[296]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-e"));
lf[297]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005-eval"));
lf[298]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-p"));
lf[299]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006-print"));
lf[300]=C_h_intern(&lf[300],15, C_text("scheme#for-each"));
lf[301]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-P"));
lf[302]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-pretty-print"));
lf[303]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003-ss"));
lf[304]=C_h_intern(&lf[304],46, C_text("chicken.process-context#command-line-arguments"));
lf[305]=C_h_intern(&lf[305],4, C_text("main"));
lf[306]=C_h_intern(&lf[306],17, C_text("chicken.base#exit"));
lf[307]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003-sx"));
lf[308]=C_h_intern(&lf[308],20, C_text("##sys#standard-error"));
lf[309]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002; "));
lf[310]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003\012; "));
lf[311]=C_h_intern(&lf[311],25, C_text("chicken.base#flush-output"));
lf[312]=C_h_intern(&lf[312],34, C_text("chicken.port#with-output-to-string"));
lf[313]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[314]=C_h_intern(&lf[314],30, C_text("chicken.pathname#make-pathname"));
lf[315]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[316]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004HOME"));
lf[317]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007chicken"));
lf[318]=C_h_intern(&lf[318],40, C_text("chicken.platform#system-config-directory"));
lf[319]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-n\376\003\000\000\002\376B\000\000\010-no-init\376\377\016"));
lf[320]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021Type ,\077 for help."));
lf[321]=C_decode_literal(C_heaptop,C_text("\376B\000\000KCHICKEN\012(c) 2008-2022, The CHICKEN Team\012(c) 2000-2007, Felix L. Winkelmann\012"
));
lf[322]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[323]=C_h_intern(&lf[323],32, C_text("chicken.platform#chicken-version"));
lf[324]=C_h_intern(&lf[324],25, C_text("chicken.load#load-verbose"));
lf[325]=C_h_intern(&lf[325],32, C_text("chicken.internal#default-imports"));
lf[326]=C_h_intern(&lf[326],17, C_text("import-for-syntax"));
lf[327]=C_h_intern(&lf[327],39, C_text("chicken.internal#default-syntax-imports"));
lf[328]=C_h_intern(&lf[328],26, C_text("chicken.base#symbol-escape"));
lf[329]=C_h_intern(&lf[329],33, C_text("chicken.base#parentheses-synonyms"));
lf[330]=C_h_intern_kw(&lf[330],4, C_text("none"));
lf[331]=C_h_intern(&lf[331],27, C_text("chicken.base#case-sensitive"));
lf[332]=C_decode_literal(C_heaptop,C_text("\376B\000\000/Disabled the CHICKEN extensions to R5RS syntax\012"));
lf[333]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\014-r5rs-syntax\376\377\016"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000%Disabled support for escaped symbols\012"));
lf[335]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\021-no-symbol-escape\376\377\016"));
lf[336]=C_decode_literal(C_heaptop,C_text("\376B\000\000\052Disabled support for parentheses synonyms\012"));
lf[337]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\030-no-parentheses-synonyms\376\377\016"));
lf[338]=C_decode_literal(C_heaptop,C_text("\376B\000\000+missing argument to `-keyword-style\047 option"));
lf[339]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006prefix"));
lf[340]=C_h_intern_kw(&lf[340],6, C_text("prefix"));
lf[341]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004none"));
lf[342]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006suffix"));
lf[343]=C_h_intern_kw(&lf[343],6, C_text("suffix"));
lf[344]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-I"));
lf[345]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015-include-path"));
lf[346]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013-no-feature"));
lf[347]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002-D"));
lf[348]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-feature"));
lf[349]=C_h_intern(&lf[349],16, C_text("case-insensitive"));
lf[350]=C_decode_literal(C_heaptop,C_text("\376B\000\000-Identifiers and symbols are case insensitive\012"));
lf[351]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-i\376\003\000\000\002\376B\000\000\021-case-insensitive\376\377\016"));
lf[352]=C_h_intern(&lf[352],22, C_text("##sys#warnings-enabled"));
lf[353]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026Warnings are disabled\012"));
lf[354]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-w\376\003\000\000\002\376B\000\000\014-no-warnings\376\377\016"));
lf[355]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-release"));
lf[356]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013-setup-mode"));
lf[357]=C_h_intern(&lf[357],16, C_text("##sys#setup-mode"));
lf[358]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010-version"));
lf[359]=C_decode_literal(C_heaptop,C_text("\376B\000\004e    -b  -batch                    terminate after command-line processing\012 "
"   -w  -no-warnings              disable all warnings\012    -K  -keyword-style STY"
"LE      enable alternative keyword-syntax\012                                   (pr"
"efix, suffix or none)\012        -no-parentheses-synonyms  disables list delimiter "
"synonyms\012        -no-symbol-escape         disables support for escaped symbols\012"
"        -r5rs-syntax              disables the CHICKEN extensions to\012           "
"                        R5RS syntax\012    -s  -script PATHNAME          use csi as"
" interpreter for Scheme scripts\012        -ss PATHNAME              same as `-s\047, "
"but invoke `main\047 procedure\012        -sx PATHNAME              same as `-s\047, but "
"print each expression\012                                   as it is evaluated\012    "
"    -setup-mode               prefer the current directory when locating extensi"
"ons\012    -R  -require-extension NAME   require extension and import before\012      "
"                             executing code\012    -I  -include-path PATHNAME    ad"
"d PATHNAME to include path\012    --                            ignore all followin"
"g options\012"));
lf[360]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 \047\012"));
lf[361]=C_decode_literal(C_heaptop,C_text("\376B\000\000D    -n  -no-init                  do not load initialization file ` "));
lf[362]=C_h_intern(&lf[362],21, C_text("##sys#print-to-string"));
lf[363]=C_decode_literal(C_heaptop,C_text("\376B\000\003.usage: csi [OPTION ...] [FILENAME ...]\012\012  `csi\047 is the CHICKEN interpreter."
"\012  \012  FILENAME is a Scheme source file name with optional extension. OPTION may "
"be\012  one of the following:\012\012    -h  -help                     display this text "
"and exit\012        -version                  display version and exit\012        -rel"
"ease                  print release number and exit\012    -i  -case-insensitive   "
"      enable case-insensitive reading\012    -e  -eval EXPRESSION          evaluate"
" given expression\012    -p  -print EXPRESSION         evaluate and print result(s)"
"\012    -P  -pretty-print EXPRESSION  evaluate and print result(s) prettily\012    -D "
" -feature SYMBOL           register feature identifier\012        -no-feature SYMBO"
"L        disable built-in feature identifier\012    -q  -quiet                    d"
"o not print banner\012"));
lf[364]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-h\376\003\000\000\002\376B\000\000\005-help\376\003\000\000\002\376B\000\000\006--help\376\377\016"));
lf[365]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-q\376\003\000\000\002\376B\000\000\006-quiet\376\377\016"));
lf[366]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-b\376\003\000\000\002\376B\000\000\006-batch\376\377\016"));
lf[367]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-e\376\003\000\000\002\376B\000\000\002-p\376\003\000\000\002\376B\000\000\002-P\376\003\000\000\002\376B\000\000\005-eval\376\003\000\000\002\376B\000\000\006-print\376\003\000\000\002\376B\000\000\015-pr"
"etty-print\376\377\016"));
lf[368]=C_h_intern(&lf[368],14, C_text("chicken-script"));
lf[369]=C_h_intern(&lf[369],36, C_text("chicken.process-context#program-name"));
lf[370]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042missing or invalid script argument"));
lf[371]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002--"));
lf[372]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\003-ss\376\003\000\000\002\376B\000\000\003-sx\376\003\000\000\002\376B\000\000\002-s\376\003\000\000\002\376B\000\000\007-script\376\377\016"));
lf[373]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\002-K\376\003\000\000\002\376B\000\000\016-keyword-style\376\377\016"));
lf[374]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[375]=C_h_intern(&lf[375],30, C_text("chicken.base#get-output-string"));
lf[376]=C_h_intern(&lf[376],31, C_text("chicken.base#open-output-string"));
lf[377]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025invalid option syntax"));
lf[378]=C_h_intern(&lf[378],14, C_text("scheme#reverse"));
lf[379]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013CSI_OPTIONS"));
lf[380]=C_h_intern(&lf[380],18, C_text("scheme#make-vector"));
lf[381]=C_h_intern(&lf[381],19, C_text("##sys#peek-c-string"));
lf[382]=C_decode_literal(C_heaptop,C_text("\376B\000\000(; resetting current module to toplevel~%"));
lf[383]=C_h_intern(&lf[383],19, C_text("##sys#switch-module"));
lf[384]=C_decode_literal(C_heaptop,C_text("\376B\000\000$; switching current module to `~a\047~%"));
lf[385]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027undefined module `~a\047~%"));
lf[386]=C_h_intern(&lf[386],17, C_text("##sys#find-module"));
lf[387]=C_h_intern(&lf[387],25, C_text("##sys#resolve-module-name"));
lf[388]=C_h_intern(&lf[388],1, C_text("m"));
lf[389]=C_decode_literal(C_heaptop,C_text("\376B\000\0005,m MODULE         switch to module with name `MODULE\047"));
lf[390]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010#;~A~A> "));
lf[391]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003~a:"));
lf[392]=C_h_intern(&lf[392],17, C_text("##sys#module-name"));
lf[393]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[394]=C_h_intern(&lf[394],20, C_text("##sys#current-module"));
lf[395]=C_h_intern(&lf[395],24, C_text("chicken.repl#repl-prompt"));
lf[396]=C_h_intern(&lf[396],17, C_text("##sys#make-string"));
lf[397]=C_decode_literal(C_heaptop,C_text("\376B\000\000\013emacsclient"));
lf[398]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002vi"));
lf[399]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005EMACS"));
lf[400]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006VISUAL"));
lf[401]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006EDITOR"));
lf[402]=C_h_intern(&lf[402],27, C_text("chicken.base#make-parameter"));
lf[403]=C_h_intern(&lf[403],30, C_text("##sys#register-compiled-module"));
lf[404]=C_h_intern(&lf[404],11, C_text("chicken.csi"));
lf[405]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001editor-command\376\001\000\000\032\001chicken.csi#editor-command\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001to"
"plevel-command\376\001\000\000\034\001chicken.csi#toplevel-command\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001set-describer!\376\001"
"\000\000\032\001chicken.csi#set-describer!\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001default-evaluator\376\001\000\000\035\001chicken.csi"
"#default-evaluator\376\377\016"));
lf[406]=C_h_intern(&lf[406],22, C_text("##sys#with-environment"));
C_register_lf2(lf,407,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2529,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[505] = {
{C_text("f9525:csi_2escm"),(void*)f9525},
{C_text("f9529:csi_2escm"),(void*)f9529},
{C_text("f9650:csi_2escm"),(void*)f9650},
{C_text("f9676:csi_2escm"),(void*)f9676},
{C_text("f9680:csi_2escm"),(void*)f9680},
{C_text("f_2529:csi_2escm"),(void*)f_2529},
{C_text("f_2532:csi_2escm"),(void*)f_2532},
{C_text("f_2535:csi_2escm"),(void*)f_2535},
{C_text("f_2538:csi_2escm"),(void*)f_2538},
{C_text("f_2541:csi_2escm"),(void*)f_2541},
{C_text("f_2544:csi_2escm"),(void*)f_2544},
{C_text("f_2547:csi_2escm"),(void*)f_2547},
{C_text("f_2550:csi_2escm"),(void*)f_2550},
{C_text("f_2553:csi_2escm"),(void*)f_2553},
{C_text("f_2556:csi_2escm"),(void*)f_2556},
{C_text("f_2559:csi_2escm"),(void*)f_2559},
{C_text("f_2562:csi_2escm"),(void*)f_2562},
{C_text("f_3060:csi_2escm"),(void*)f_3060},
{C_text("f_3087:csi_2escm"),(void*)f_3087},
{C_text("f_3135:csi_2escm"),(void*)f_3135},
{C_text("f_3149:csi_2escm"),(void*)f_3149},
{C_text("f_3162:csi_2escm"),(void*)f_3162},
{C_text("f_3852:csi_2escm"),(void*)f_3852},
{C_text("f_3857:csi_2escm"),(void*)f_3857},
{C_text("f_3860:csi_2escm"),(void*)f_3860},
{C_text("f_3866:csi_2escm"),(void*)f_3866},
{C_text("f_3869:csi_2escm"),(void*)f_3869},
{C_text("f_3876:csi_2escm"),(void*)f_3876},
{C_text("f_3900:csi_2escm"),(void*)f_3900},
{C_text("f_3915:csi_2escm"),(void*)f_3915},
{C_text("f_3929:csi_2escm"),(void*)f_3929},
{C_text("f_3942:csi_2escm"),(void*)f_3942},
{C_text("f_3961:csi_2escm"),(void*)f_3961},
{C_text("f_3968:csi_2escm"),(void*)f_3968},
{C_text("f_3971:csi_2escm"),(void*)f_3971},
{C_text("f_3977:csi_2escm"),(void*)f_3977},
{C_text("f_3990:csi_2escm"),(void*)f_3990},
{C_text("f_4003:csi_2escm"),(void*)f_4003},
{C_text("f_4012:csi_2escm"),(void*)f_4012},
{C_text("f_4016:csi_2escm"),(void*)f_4016},
{C_text("f_4028:csi_2escm"),(void*)f_4028},
{C_text("f_4037:csi_2escm"),(void*)f_4037},
{C_text("f_4040:csi_2escm"),(void*)f_4040},
{C_text("f_4047:csi_2escm"),(void*)f_4047},
{C_text("f_4051:csi_2escm"),(void*)f_4051},
{C_text("f_4054:csi_2escm"),(void*)f_4054},
{C_text("f_4060:csi_2escm"),(void*)f_4060},
{C_text("f_4067:csi_2escm"),(void*)f_4067},
{C_text("f_4069:csi_2escm"),(void*)f_4069},
{C_text("f_4079:csi_2escm"),(void*)f_4079},
{C_text("f_4082:csi_2escm"),(void*)f_4082},
{C_text("f_4096:csi_2escm"),(void*)f_4096},
{C_text("f_4119:csi_2escm"),(void*)f_4119},
{C_text("f_4129:csi_2escm"),(void*)f_4129},
{C_text("f_4143:csi_2escm"),(void*)f_4143},
{C_text("f_4174:csi_2escm"),(void*)f_4174},
{C_text("f_4187:csi_2escm"),(void*)f_4187},
{C_text("f_4190:csi_2escm"),(void*)f_4190},
{C_text("f_4193:csi_2escm"),(void*)f_4193},
{C_text("f_4196:csi_2escm"),(void*)f_4196},
{C_text("f_4199:csi_2escm"),(void*)f_4199},
{C_text("f_4208:csi_2escm"),(void*)f_4208},
{C_text("f_4218:csi_2escm"),(void*)f_4218},
{C_text("f_4222:csi_2escm"),(void*)f_4222},
{C_text("f_4245:csi_2escm"),(void*)f_4245},
{C_text("f_4262:csi_2escm"),(void*)f_4262},
{C_text("f_4274:csi_2escm"),(void*)f_4274},
{C_text("f_4282:csi_2escm"),(void*)f_4282},
{C_text("f_4285:csi_2escm"),(void*)f_4285},
{C_text("f_4296:csi_2escm"),(void*)f_4296},
{C_text("f_4303:csi_2escm"),(void*)f_4303},
{C_text("f_4309:csi_2escm"),(void*)f_4309},
{C_text("f_4329:csi_2escm"),(void*)f_4329},
{C_text("f_4364:csi_2escm"),(void*)f_4364},
{C_text("f_4397:csi_2escm"),(void*)f_4397},
{C_text("f_4412:csi_2escm"),(void*)f_4412},
{C_text("f_4415:csi_2escm"),(void*)f_4415},
{C_text("f_4422:csi_2escm"),(void*)f_4422},
{C_text("f_4426:csi_2escm"),(void*)f_4426},
{C_text("f_4435:csi_2escm"),(void*)f_4435},
{C_text("f_4438:csi_2escm"),(void*)f_4438},
{C_text("f_4441:csi_2escm"),(void*)f_4441},
{C_text("f_4453:csi_2escm"),(void*)f_4453},
{C_text("f_4456:csi_2escm"),(void*)f_4456},
{C_text("f_4468:csi_2escm"),(void*)f_4468},
{C_text("f_4471:csi_2escm"),(void*)f_4471},
{C_text("f_4483:csi_2escm"),(void*)f_4483},
{C_text("f_4486:csi_2escm"),(void*)f_4486},
{C_text("f_4489:csi_2escm"),(void*)f_4489},
{C_text("f_4492:csi_2escm"),(void*)f_4492},
{C_text("f_4522:csi_2escm"),(void*)f_4522},
{C_text("f_4525:csi_2escm"),(void*)f_4525},
{C_text("f_4530:csi_2escm"),(void*)f_4530},
{C_text("f_4540:csi_2escm"),(void*)f_4540},
{C_text("f_4555:csi_2escm"),(void*)f_4555},
{C_text("f_4564:csi_2escm"),(void*)f_4564},
{C_text("f_4565:csi_2escm"),(void*)f_4565},
{C_text("f_4571:csi_2escm"),(void*)f_4571},
{C_text("f_4575:csi_2escm"),(void*)f_4575},
{C_text("f_4581:csi_2escm"),(void*)f_4581},
{C_text("f_4586:csi_2escm"),(void*)f_4586},
{C_text("f_4596:csi_2escm"),(void*)f_4596},
{C_text("f_4611:csi_2escm"),(void*)f_4611},
{C_text("f_4620:csi_2escm"),(void*)f_4620},
{C_text("f_4625:csi_2escm"),(void*)f_4625},
{C_text("f_4629:csi_2escm"),(void*)f_4629},
{C_text("f_4634:csi_2escm"),(void*)f_4634},
{C_text("f_4640:csi_2escm"),(void*)f_4640},
{C_text("f_4644:csi_2escm"),(void*)f_4644},
{C_text("f_4651:csi_2escm"),(void*)f_4651},
{C_text("f_4653:csi_2escm"),(void*)f_4653},
{C_text("f_4657:csi_2escm"),(void*)f_4657},
{C_text("f_4672:csi_2escm"),(void*)f_4672},
{C_text("f_4688:csi_2escm"),(void*)f_4688},
{C_text("f_4706:csi_2escm"),(void*)f_4706},
{C_text("f_4710:csi_2escm"),(void*)f_4710},
{C_text("f_4726:csi_2escm"),(void*)f_4726},
{C_text("f_4738:csi_2escm"),(void*)f_4738},
{C_text("f_4750:csi_2escm"),(void*)f_4750},
{C_text("f_4762:csi_2escm"),(void*)f_4762},
{C_text("f_4769:csi_2escm"),(void*)f_4769},
{C_text("f_4782:csi_2escm"),(void*)f_4782},
{C_text("f_4791:csi_2escm"),(void*)f_4791},
{C_text("f_4794:csi_2escm"),(void*)f_4794},
{C_text("f_4797:csi_2escm"),(void*)f_4797},
{C_text("f_4810:csi_2escm"),(void*)f_4810},
{C_text("f_4832:csi_2escm"),(void*)f_4832},
{C_text("f_4837:csi_2escm"),(void*)f_4837},
{C_text("f_4847:csi_2escm"),(void*)f_4847},
{C_text("f_4861:csi_2escm"),(void*)f_4861},
{C_text("f_4907:csi_2escm"),(void*)f_4907},
{C_text("f_4913:csi_2escm"),(void*)f_4913},
{C_text("f_4917:csi_2escm"),(void*)f_4917},
{C_text("f_4933:csi_2escm"),(void*)f_4933},
{C_text("f_4939:csi_2escm"),(void*)f_4939},
{C_text("f_4953:csi_2escm"),(void*)f_4953},
{C_text("f_4956:csi_2escm"),(void*)f_4956},
{C_text("f_4962:csi_2escm"),(void*)f_4962},
{C_text("f_4965:csi_2escm"),(void*)f_4965},
{C_text("f_4973:csi_2escm"),(void*)f_4973},
{C_text("f_4983:csi_2escm"),(void*)f_4983},
{C_text("f_4998:csi_2escm"),(void*)f_4998},
{C_text("f_5007:csi_2escm"),(void*)f_5007},
{C_text("f_5013:csi_2escm"),(void*)f_5013},
{C_text("f_5019:csi_2escm"),(void*)f_5019},
{C_text("f_5025:csi_2escm"),(void*)f_5025},
{C_text("f_5031:csi_2escm"),(void*)f_5031},
{C_text("f_5039:csi_2escm"),(void*)f_5039},
{C_text("f_5041:csi_2escm"),(void*)f_5041},
{C_text("f_5058:csi_2escm"),(void*)f_5058},
{C_text("f_5064:csi_2escm"),(void*)f_5064},
{C_text("f_5070:csi_2escm"),(void*)f_5070},
{C_text("f_5078:csi_2escm"),(void*)f_5078},
{C_text("f_5079:csi_2escm"),(void*)f_5079},
{C_text("f_5089:csi_2escm"),(void*)f_5089},
{C_text("f_5093:csi_2escm"),(void*)f_5093},
{C_text("f_5096:csi_2escm"),(void*)f_5096},
{C_text("f_5099:csi_2escm"),(void*)f_5099},
{C_text("f_5101:csi_2escm"),(void*)f_5101},
{C_text("f_5109:csi_2escm"),(void*)f_5109},
{C_text("f_5117:csi_2escm"),(void*)f_5117},
{C_text("f_5120:csi_2escm"),(void*)f_5120},
{C_text("f_5121:csi_2escm"),(void*)f_5121},
{C_text("f_5125:csi_2escm"),(void*)f_5125},
{C_text("f_5135:csi_2escm"),(void*)f_5135},
{C_text("f_5144:csi_2escm"),(void*)f_5144},
{C_text("f_5152:csi_2escm"),(void*)f_5152},
{C_text("f_5167:csi_2escm"),(void*)f_5167},
{C_text("f_5170:csi_2escm"),(void*)f_5170},
{C_text("f_5173:csi_2escm"),(void*)f_5173},
{C_text("f_5176:csi_2escm"),(void*)f_5176},
{C_text("f_5183:csi_2escm"),(void*)f_5183},
{C_text("f_5188:csi_2escm"),(void*)f_5188},
{C_text("f_5192:csi_2escm"),(void*)f_5192},
{C_text("f_5196:csi_2escm"),(void*)f_5196},
{C_text("f_5200:csi_2escm"),(void*)f_5200},
{C_text("f_5204:csi_2escm"),(void*)f_5204},
{C_text("f_5208:csi_2escm"),(void*)f_5208},
{C_text("f_5212:csi_2escm"),(void*)f_5212},
{C_text("f_5216:csi_2escm"),(void*)f_5216},
{C_text("f_5244:csi_2escm"),(void*)f_5244},
{C_text("f_5256:csi_2escm"),(void*)f_5256},
{C_text("f_5258:csi_2escm"),(void*)f_5258},
{C_text("f_5268:csi_2escm"),(void*)f_5268},
{C_text("f_5289:csi_2escm"),(void*)f_5289},
{C_text("f_5291:csi_2escm"),(void*)f_5291},
{C_text("f_5316:csi_2escm"),(void*)f_5316},
{C_text("f_5336:csi_2escm"),(void*)f_5336},
{C_text("f_5371:csi_2escm"),(void*)f_5371},
{C_text("f_5401:csi_2escm"),(void*)f_5401},
{C_text("f_5403:csi_2escm"),(void*)f_5403},
{C_text("f_5409:csi_2escm"),(void*)f_5409},
{C_text("f_5416:csi_2escm"),(void*)f_5416},
{C_text("f_5421:csi_2escm"),(void*)f_5421},
{C_text("f_5444:csi_2escm"),(void*)f_5444},
{C_text("f_5453:csi_2escm"),(void*)f_5453},
{C_text("f_5463:csi_2escm"),(void*)f_5463},
{C_text("f_5466:csi_2escm"),(void*)f_5466},
{C_text("f_5495:csi_2escm"),(void*)f_5495},
{C_text("f_5523:csi_2escm"),(void*)f_5523},
{C_text("f_5538:csi_2escm"),(void*)f_5538},
{C_text("f_5541:csi_2escm"),(void*)f_5541},
{C_text("f_5544:csi_2escm"),(void*)f_5544},
{C_text("f_5616:csi_2escm"),(void*)f_5616},
{C_text("f_5622:csi_2escm"),(void*)f_5622},
{C_text("f_5713:csi_2escm"),(void*)f_5713},
{C_text("f_5720:csi_2escm"),(void*)f_5720},
{C_text("f_5729:csi_2escm"),(void*)f_5729},
{C_text("f_5732:csi_2escm"),(void*)f_5732},
{C_text("f_5744:csi_2escm"),(void*)f_5744},
{C_text("f_5749:csi_2escm"),(void*)f_5749},
{C_text("f_5759:csi_2escm"),(void*)f_5759},
{C_text("f_5762:csi_2escm"),(void*)f_5762},
{C_text("f_5765:csi_2escm"),(void*)f_5765},
{C_text("f_5774:csi_2escm"),(void*)f_5774},
{C_text("f_5794:csi_2escm"),(void*)f_5794},
{C_text("f_5797:csi_2escm"),(void*)f_5797},
{C_text("f_5800:csi_2escm"),(void*)f_5800},
{C_text("f_5812:csi_2escm"),(void*)f_5812},
{C_text("f_5815:csi_2escm"),(void*)f_5815},
{C_text("f_5824:csi_2escm"),(void*)f_5824},
{C_text("f_5855:csi_2escm"),(void*)f_5855},
{C_text("f_5919:csi_2escm"),(void*)f_5919},
{C_text("f_5923:csi_2escm"),(void*)f_5923},
{C_text("f_5929:csi_2escm"),(void*)f_5929},
{C_text("f_5948:csi_2escm"),(void*)f_5948},
{C_text("f_5966:csi_2escm"),(void*)f_5966},
{C_text("f_5973:csi_2escm"),(void*)f_5973},
{C_text("f_6090:csi_2escm"),(void*)f_6090},
{C_text("f_6096:csi_2escm"),(void*)f_6096},
{C_text("f_6102:csi_2escm"),(void*)f_6102},
{C_text("f_6115:csi_2escm"),(void*)f_6115},
{C_text("f_6127:csi_2escm"),(void*)f_6127},
{C_text("f_6130:csi_2escm"),(void*)f_6130},
{C_text("f_6141:csi_2escm"),(void*)f_6141},
{C_text("f_6149:csi_2escm"),(void*)f_6149},
{C_text("f_6170:csi_2escm"),(void*)f_6170},
{C_text("f_6179:csi_2escm"),(void*)f_6179},
{C_text("f_6189:csi_2escm"),(void*)f_6189},
{C_text("f_6224:csi_2escm"),(void*)f_6224},
{C_text("f_6225:csi_2escm"),(void*)f_6225},
{C_text("f_6229:csi_2escm"),(void*)f_6229},
{C_text("f_6238:csi_2escm"),(void*)f_6238},
{C_text("f_6248:csi_2escm"),(void*)f_6248},
{C_text("f_6261:csi_2escm"),(void*)f_6261},
{C_text("f_6266:csi_2escm"),(void*)f_6266},
{C_text("f_6293:csi_2escm"),(void*)f_6293},
{C_text("f_6303:csi_2escm"),(void*)f_6303},
{C_text("f_6330:csi_2escm"),(void*)f_6330},
{C_text("f_6334:csi_2escm"),(void*)f_6334},
{C_text("f_6348:csi_2escm"),(void*)f_6348},
{C_text("f_6356:csi_2escm"),(void*)f_6356},
{C_text("f_6369:csi_2escm"),(void*)f_6369},
{C_text("f_6375:csi_2escm"),(void*)f_6375},
{C_text("f_6400:csi_2escm"),(void*)f_6400},
{C_text("f_6413:csi_2escm"),(void*)f_6413},
{C_text("f_6441:csi_2escm"),(void*)f_6441},
{C_text("f_6449:csi_2escm"),(void*)f_6449},
{C_text("f_6458:csi_2escm"),(void*)f_6458},
{C_text("f_6460:csi_2escm"),(void*)f_6460},
{C_text("f_6463:csi_2escm"),(void*)f_6463},
{C_text("f_6485:csi_2escm"),(void*)f_6485},
{C_text("f_6492:csi_2escm"),(void*)f_6492},
{C_text("f_6509:csi_2escm"),(void*)f_6509},
{C_text("f_6538:csi_2escm"),(void*)f_6538},
{C_text("f_6566:csi_2escm"),(void*)f_6566},
{C_text("f_6571:csi_2escm"),(void*)f_6571},
{C_text("f_6606:csi_2escm"),(void*)f_6606},
{C_text("f_6609:csi_2escm"),(void*)f_6609},
{C_text("f_6613:csi_2escm"),(void*)f_6613},
{C_text("f_6629:csi_2escm"),(void*)f_6629},
{C_text("f_6641:csi_2escm"),(void*)f_6641},
{C_text("f_6651:csi_2escm"),(void*)f_6651},
{C_text("f_6654:csi_2escm"),(void*)f_6654},
{C_text("f_6657:csi_2escm"),(void*)f_6657},
{C_text("f_6660:csi_2escm"),(void*)f_6660},
{C_text("f_6663:csi_2escm"),(void*)f_6663},
{C_text("f_6666:csi_2escm"),(void*)f_6666},
{C_text("f_6675:csi_2escm"),(void*)f_6675},
{C_text("f_6688:csi_2escm"),(void*)f_6688},
{C_text("f_6691:csi_2escm"),(void*)f_6691},
{C_text("f_6726:csi_2escm"),(void*)f_6726},
{C_text("f_6760:csi_2escm"),(void*)f_6760},
{C_text("f_6770:csi_2escm"),(void*)f_6770},
{C_text("f_6780:csi_2escm"),(void*)f_6780},
{C_text("f_6783:csi_2escm"),(void*)f_6783},
{C_text("f_6798:csi_2escm"),(void*)f_6798},
{C_text("f_6802:csi_2escm"),(void*)f_6802},
{C_text("f_6809:csi_2escm"),(void*)f_6809},
{C_text("f_6811:csi_2escm"),(void*)f_6811},
{C_text("f_6814:csi_2escm"),(void*)f_6814},
{C_text("f_6820:csi_2escm"),(void*)f_6820},
{C_text("f_6837:csi_2escm"),(void*)f_6837},
{C_text("f_6846:csi_2escm"),(void*)f_6846},
{C_text("f_6877:csi_2escm"),(void*)f_6877},
{C_text("f_6880:csi_2escm"),(void*)f_6880},
{C_text("f_6883:csi_2escm"),(void*)f_6883},
{C_text("f_6886:csi_2escm"),(void*)f_6886},
{C_text("f_6889:csi_2escm"),(void*)f_6889},
{C_text("f_6892:csi_2escm"),(void*)f_6892},
{C_text("f_6895:csi_2escm"),(void*)f_6895},
{C_text("f_6898:csi_2escm"),(void*)f_6898},
{C_text("f_6901:csi_2escm"),(void*)f_6901},
{C_text("f_6904:csi_2escm"),(void*)f_6904},
{C_text("f_6907:csi_2escm"),(void*)f_6907},
{C_text("f_6920:csi_2escm"),(void*)f_6920},
{C_text("f_6930:csi_2escm"),(void*)f_6930},
{C_text("f_6935:csi_2escm"),(void*)f_6935},
{C_text("f_6948:csi_2escm"),(void*)f_6948},
{C_text("f_6951:csi_2escm"),(void*)f_6951},
{C_text("f_6954:csi_2escm"),(void*)f_6954},
{C_text("f_6957:csi_2escm"),(void*)f_6957},
{C_text("f_6960:csi_2escm"),(void*)f_6960},
{C_text("f_6994:csi_2escm"),(void*)f_6994},
{C_text("f_7004:csi_2escm"),(void*)f_7004},
{C_text("f_7038:csi_2escm"),(void*)f_7038},
{C_text("f_7041:csi_2escm"),(void*)f_7041},
{C_text("f_7096:csi_2escm"),(void*)f_7096},
{C_text("f_7153:csi_2escm"),(void*)f_7153},
{C_text("f_7155:csi_2escm"),(void*)f_7155},
{C_text("f_7166:csi_2escm"),(void*)f_7166},
{C_text("f_7186:csi_2escm"),(void*)f_7186},
{C_text("f_7189:csi_2escm"),(void*)f_7189},
{C_text("f_7193:csi_2escm"),(void*)f_7193},
{C_text("f_7196:csi_2escm"),(void*)f_7196},
{C_text("f_7208:csi_2escm"),(void*)f_7208},
{C_text("f_7233:csi_2escm"),(void*)f_7233},
{C_text("f_7242:csi_2escm"),(void*)f_7242},
{C_text("f_7248:csi_2escm"),(void*)f_7248},
{C_text("f_7258:csi_2escm"),(void*)f_7258},
{C_text("f_7270:csi_2escm"),(void*)f_7270},
{C_text("f_7273:csi_2escm"),(void*)f_7273},
{C_text("f_7276:csi_2escm"),(void*)f_7276},
{C_text("f_7279:csi_2escm"),(void*)f_7279},
{C_text("f_7282:csi_2escm"),(void*)f_7282},
{C_text("f_7318:csi_2escm"),(void*)f_7318},
{C_text("f_7325:csi_2escm"),(void*)f_7325},
{C_text("f_7327:csi_2escm"),(void*)f_7327},
{C_text("f_7337:csi_2escm"),(void*)f_7337},
{C_text("f_7380:csi_2escm"),(void*)f_7380},
{C_text("f_7385:csi_2escm"),(void*)f_7385},
{C_text("f_7391:csi_2escm"),(void*)f_7391},
{C_text("f_7403:csi_2escm"),(void*)f_7403},
{C_text("f_7440:csi_2escm"),(void*)f_7440},
{C_text("f_7446:csi_2escm"),(void*)f_7446},
{C_text("f_7481:csi_2escm"),(void*)f_7481},
{C_text("f_7493:csi_2escm"),(void*)f_7493},
{C_text("f_7507:csi_2escm"),(void*)f_7507},
{C_text("f_7528:csi_2escm"),(void*)f_7528},
{C_text("f_7532:csi_2escm"),(void*)f_7532},
{C_text("f_7536:csi_2escm"),(void*)f_7536},
{C_text("f_7575:csi_2escm"),(void*)f_7575},
{C_text("f_7583:csi_2escm"),(void*)f_7583},
{C_text("f_7625:csi_2escm"),(void*)f_7625},
{C_text("f_7661:csi_2escm"),(void*)f_7661},
{C_text("f_7709:csi_2escm"),(void*)f_7709},
{C_text("f_7718:csi_2escm"),(void*)f_7718},
{C_text("f_7723:csi_2escm"),(void*)f_7723},
{C_text("f_7729:csi_2escm"),(void*)f_7729},
{C_text("f_7735:csi_2escm"),(void*)f_7735},
{C_text("f_7741:csi_2escm"),(void*)f_7741},
{C_text("f_7747:csi_2escm"),(void*)f_7747},
{C_text("f_7753:csi_2escm"),(void*)f_7753},
{C_text("f_7759:csi_2escm"),(void*)f_7759},
{C_text("f_7780:csi_2escm"),(void*)f_7780},
{C_text("f_7783:csi_2escm"),(void*)f_7783},
{C_text("f_7786:csi_2escm"),(void*)f_7786},
{C_text("f_7789:csi_2escm"),(void*)f_7789},
{C_text("f_7792:csi_2escm"),(void*)f_7792},
{C_text("f_7795:csi_2escm"),(void*)f_7795},
{C_text("f_7798:csi_2escm"),(void*)f_7798},
{C_text("f_7801:csi_2escm"),(void*)f_7801},
{C_text("f_7806:csi_2escm"),(void*)f_7806},
{C_text("f_7812:csi_2escm"),(void*)f_7812},
{C_text("f_7820:csi_2escm"),(void*)f_7820},
{C_text("f_7841:csi_2escm"),(void*)f_7841},
{C_text("f_7857:csi_2escm"),(void*)f_7857},
{C_text("f_7860:csi_2escm"),(void*)f_7860},
{C_text("f_7863:csi_2escm"),(void*)f_7863},
{C_text("f_7866:csi_2escm"),(void*)f_7866},
{C_text("f_7872:csi_2escm"),(void*)f_7872},
{C_text("f_7881:csi_2escm"),(void*)f_7881},
{C_text("f_7903:csi_2escm"),(void*)f_7903},
{C_text("f_7918:csi_2escm"),(void*)f_7918},
{C_text("f_7925:csi_2escm"),(void*)f_7925},
{C_text("f_7932:csi_2escm"),(void*)f_7932},
{C_text("f_7934:csi_2escm"),(void*)f_7934},
{C_text("f_7944:csi_2escm"),(void*)f_7944},
{C_text("f_7951:csi_2escm"),(void*)f_7951},
{C_text("f_7955:csi_2escm"),(void*)f_7955},
{C_text("f_7957:csi_2escm"),(void*)f_7957},
{C_text("f_7965:csi_2escm"),(void*)f_7965},
{C_text("f_7975:csi_2escm"),(void*)f_7975},
{C_text("f_7978:csi_2escm"),(void*)f_7978},
{C_text("f_7981:csi_2escm"),(void*)f_7981},
{C_text("f_7984:csi_2escm"),(void*)f_7984},
{C_text("f_7987:csi_2escm"),(void*)f_7987},
{C_text("f_7990:csi_2escm"),(void*)f_7990},
{C_text("f_7993:csi_2escm"),(void*)f_7993},
{C_text("f_7999:csi_2escm"),(void*)f_7999},
{C_text("f_8002:csi_2escm"),(void*)f_8002},
{C_text("f_8008:csi_2escm"),(void*)f_8008},
{C_text("f_8011:csi_2escm"),(void*)f_8011},
{C_text("f_8017:csi_2escm"),(void*)f_8017},
{C_text("f_8021:csi_2escm"),(void*)f_8021},
{C_text("f_8024:csi_2escm"),(void*)f_8024},
{C_text("f_8027:csi_2escm"),(void*)f_8027},
{C_text("f_8030:csi_2escm"),(void*)f_8030},
{C_text("f_8033:csi_2escm"),(void*)f_8033},
{C_text("f_8036:csi_2escm"),(void*)f_8036},
{C_text("f_8039:csi_2escm"),(void*)f_8039},
{C_text("f_8042:csi_2escm"),(void*)f_8042},
{C_text("f_8045:csi_2escm"),(void*)f_8045},
{C_text("f_8048:csi_2escm"),(void*)f_8048},
{C_text("f_8053:csi_2escm"),(void*)f_8053},
{C_text("f_8069:csi_2escm"),(void*)f_8069},
{C_text("f_8081:csi_2escm"),(void*)f_8081},
{C_text("f_8110:csi_2escm"),(void*)f_8110},
{C_text("f_8122:csi_2escm"),(void*)f_8122},
{C_text("f_8137:csi_2escm"),(void*)f_8137},
{C_text("f_8156:csi_2escm"),(void*)f_8156},
{C_text("f_8166:csi_2escm"),(void*)f_8166},
{C_text("f_8181:csi_2escm"),(void*)f_8181},
{C_text("f_8191:csi_2escm"),(void*)f_8191},
{C_text("f_8201:csi_2escm"),(void*)f_8201},
{C_text("f_8212:csi_2escm"),(void*)f_8212},
{C_text("f_8216:csi_2escm"),(void*)f_8216},
{C_text("f_8223:csi_2escm"),(void*)f_8223},
{C_text("f_8225:csi_2escm"),(void*)f_8225},
{C_text("f_8253:csi_2escm"),(void*)f_8253},
{C_text("f_8257:csi_2escm"),(void*)f_8257},
{C_text("f_8263:csi_2escm"),(void*)f_8263},
{C_text("f_8266:csi_2escm"),(void*)f_8266},
{C_text("f_8269:csi_2escm"),(void*)f_8269},
{C_text("f_8272:csi_2escm"),(void*)f_8272},
{C_text("f_8277:csi_2escm"),(void*)f_8277},
{C_text("f_8290:csi_2escm"),(void*)f_8290},
{C_text("f_8293:csi_2escm"),(void*)f_8293},
{C_text("f_8308:csi_2escm"),(void*)f_8308},
{C_text("f_8327:csi_2escm"),(void*)f_8327},
{C_text("f_8339:csi_2escm"),(void*)f_8339},
{C_text("f_8342:csi_2escm"),(void*)f_8342},
{C_text("f_8356:csi_2escm"),(void*)f_8356},
{C_text("f_8359:csi_2escm"),(void*)f_8359},
{C_text("f_8362:csi_2escm"),(void*)f_8362},
{C_text("f_8365:csi_2escm"),(void*)f_8365},
{C_text("f_8368:csi_2escm"),(void*)f_8368},
{C_text("f_8377:csi_2escm"),(void*)f_8377},
{C_text("f_8380:csi_2escm"),(void*)f_8380},
{C_text("f_8389:csi_2escm"),(void*)f_8389},
{C_text("f_8392:csi_2escm"),(void*)f_8392},
{C_text("f_8456:csi_2escm"),(void*)f_8456},
{C_text("f_8463:csi_2escm"),(void*)f_8463},
{C_text("f_8469:csi_2escm"),(void*)f_8469},
{C_text("f_8476:csi_2escm"),(void*)f_8476},
{C_text("f_8482:csi_2escm"),(void*)f_8482},
{C_text("f_8484:csi_2escm"),(void*)f_8484},
{C_text("f_8509:csi_2escm"),(void*)f_8509},
{C_text("f_8518:csi_2escm"),(void*)f_8518},
{C_text("f_8543:csi_2escm"),(void*)f_8543},
{C_text("f_8552:csi_2escm"),(void*)f_8552},
{C_text("f_8562:csi_2escm"),(void*)f_8562},
{C_text("f_8575:csi_2escm"),(void*)f_8575},
{C_text("f_8585:csi_2escm"),(void*)f_8585},
{C_text("f_8598:csi_2escm"),(void*)f_8598},
{C_text("f_8608:csi_2escm"),(void*)f_8608},
{C_text("f_8622:csi_2escm"),(void*)f_8622},
{C_text("f_8625:csi_2escm"),(void*)f_8625},
{C_text("f_8628:csi_2escm"),(void*)f_8628},
{C_text("f_8637:csi_2escm"),(void*)f_8637},
{C_text("f_8640:csi_2escm"),(void*)f_8640},
{C_text("f_8650:csi_2escm"),(void*)f_8650},
{C_text("f_8657:csi_2escm"),(void*)f_8657},
{C_text("f_8667:csi_2escm"),(void*)f_8667},
{C_text("f_8673:csi_2escm"),(void*)f_8673},
{C_text("f_8676:csi_2escm"),(void*)f_8676},
{C_text("f_8685:csi_2escm"),(void*)f_8685},
{C_text("f_8691:csi_2escm"),(void*)f_8691},
{C_text("f_8694:csi_2escm"),(void*)f_8694},
{C_text("f_8697:csi_2escm"),(void*)f_8697},
{C_text("f_8700:csi_2escm"),(void*)f_8700},
{C_text("f_8709:csi_2escm"),(void*)f_8709},
{C_text("f_8774:csi_2escm"),(void*)f_8774},
{C_text("f_8787:csi_2escm"),(void*)f_8787},
{C_text("f_8791:csi_2escm"),(void*)f_8791},
{C_text("f_8795:csi_2escm"),(void*)f_8795},
{C_text("f_8801:csi_2escm"),(void*)f_8801},
{C_text("f_8807:csi_2escm"),(void*)f_8807},
{C_text("f_8809:csi_2escm"),(void*)f_8809},
{C_text("f_8815:csi_2escm"),(void*)f_8815},
{C_text("f_8819:csi_2escm"),(void*)f_8819},
{C_text("f_8828:csi_2escm"),(void*)f_8828},
{C_text("f_8834:csi_2escm"),(void*)f_8834},
{C_text("f_8838:csi_2escm"),(void*)f_8838},
{C_text("f_8842:csi_2escm"),(void*)f_8842},
{C_text("f_8855:csi_2escm"),(void*)f_8855},
{C_text("f_8857:csi_2escm"),(void*)f_8857},
{C_text("f_8865:csi_2escm"),(void*)f_8865},
{C_text("f_8868:csi_2escm"),(void*)f_8868},
{C_text("f_8875:csi_2escm"),(void*)f_8875},
{C_text("f_8879:csi_2escm"),(void*)f_8879},
{C_text("f_8888:csi_2escm"),(void*)f_8888},
{C_text("f_8890:csi_2escm"),(void*)f_8890},
{C_text("toplevel:csi_2escm"),(void*)C_toplevel},
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
o|hiding unexported module binding: chicken.csi#constant214 
o|hiding unexported module binding: chicken.csi#partition 
o|hiding unexported module binding: chicken.csi#span 
o|hiding unexported module binding: chicken.csi#take 
o|hiding unexported module binding: chicken.csi#drop 
o|hiding unexported module binding: chicken.csi#split-at 
o|hiding unexported module binding: chicken.csi#append-map 
o|hiding unexported module binding: chicken.csi#every 
o|hiding unexported module binding: chicken.csi#any 
o|hiding unexported module binding: chicken.csi#cons* 
o|hiding unexported module binding: chicken.csi#concatenate 
o|hiding unexported module binding: chicken.csi#delete 
o|hiding unexported module binding: chicken.csi#first 
o|hiding unexported module binding: chicken.csi#second 
o|hiding unexported module binding: chicken.csi#third 
o|hiding unexported module binding: chicken.csi#fourth 
o|hiding unexported module binding: chicken.csi#fifth 
o|hiding unexported module binding: chicken.csi#delete-duplicates 
o|hiding unexported module binding: chicken.csi#alist-cons 
o|hiding unexported module binding: chicken.csi#filter 
o|hiding unexported module binding: chicken.csi#filter-map 
o|hiding unexported module binding: chicken.csi#remove 
o|hiding unexported module binding: chicken.csi#unzip1 
o|hiding unexported module binding: chicken.csi#last 
o|hiding unexported module binding: chicken.csi#list-index 
o|hiding unexported module binding: chicken.csi#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.csi#lset-difference/eq? 
o|hiding unexported module binding: chicken.csi#lset-union/eq? 
o|hiding unexported module binding: chicken.csi#lset-intersection/eq? 
o|hiding unexported module binding: chicken.csi#list-tabulate 
o|hiding unexported module binding: chicken.csi#lset<=/eq? 
o|hiding unexported module binding: chicken.csi#lset=/eq? 
o|hiding unexported module binding: chicken.csi#length+ 
o|hiding unexported module binding: chicken.csi#find 
o|hiding unexported module binding: chicken.csi#find-tail 
o|hiding unexported module binding: chicken.csi#iota 
o|hiding unexported module binding: chicken.csi#make-list 
o|hiding unexported module binding: chicken.csi#posq 
o|hiding unexported module binding: chicken.csi#posv 
o|hiding unexported module binding: chicken.csi#constant701 
o|hiding unexported module binding: chicken.csi#selected-frame 
o|hiding unexported module binding: chicken.csi#default-editor 
o|hiding unexported module binding: chicken.csi#print-usage 
o|hiding unexported module binding: chicken.csi#print-banner 
o|hiding unexported module binding: chicken.csi#dirseparator? 
o|hiding unexported module binding: chicken.csi#chop-separator 
o|hiding unexported module binding: chicken.csi#lookup-script-file 
o|hiding unexported module binding: chicken.csi#history-list 
o|hiding unexported module binding: chicken.csi#history-count 
o|hiding unexported module binding: chicken.csi#history-add 
o|hiding unexported module binding: chicken.csi#history-clear 
o|hiding unexported module binding: chicken.csi#history-show 
o|hiding unexported module binding: chicken.csi#history-ref 
o|hiding unexported module binding: chicken.csi#register-repl-history! 
o|hiding unexported module binding: chicken.csi#tty-input? 
o|hiding unexported module binding: chicken.csi#command-table 
o|hiding unexported module binding: chicken.csi#parse-option-string 
o|hiding unexported module binding: chicken.csi#report 
o|hiding unexported module binding: chicken.csi#bytevector-data 
o|hiding unexported module binding: chicken.csi#circular-list? 
o|hiding unexported module binding: chicken.csi#improper-pairs? 
o|hiding unexported module binding: chicken.csi#describer-table 
o|hiding unexported module binding: chicken.csi#describe 
o|hiding unexported module binding: chicken.csi#dump 
o|hiding unexported module binding: chicken.csi#hexdump 
o|hiding unexported module binding: chicken.csi#show-frameinfo 
o|hiding unexported module binding: chicken.csi#select-frame 
o|hiding unexported module binding: chicken.csi#copy-from-frame 
o|hiding unexported module binding: chicken.csi#defhandler 
o|hiding unexported module binding: chicken.csi#member* 
o|hiding unexported module binding: chicken.csi#constant1687 
o|hiding unexported module binding: chicken.csi#constant1693 
o|hiding unexported module binding: chicken.csi#canonicalize-args 
o|hiding unexported module binding: chicken.csi#findall 
o|hiding unexported module binding: chicken.csi#constant1758 
o|hiding unexported module binding: chicken.csi#constant1766 
o|hiding unexported module binding: chicken.csi#string-trim 
o|hiding unexported module binding: chicken.csi#string->extension-name 
o|hiding unexported module binding: chicken.csi#run 
S|applied compiler syntax:
S|  scheme#for-each		11
S|  chicken.format#printf		4
S|  chicken.base#foldl		3
S|  scheme#map		9
S|  chicken.base#foldr		3
o|eliminated procedure checks: 160 
o|eliminated procedure checks: 1 
o|specializations:
o|  1 (scheme#string-length string)
o|  7 (scheme#string=? string string)
o|  1 (scheme#set-cdr! pair *)
o|  2 (scheme#cddr (pair * pair))
o|  3 (scheme#cadr (pair * pair))
o|  3 (scheme#char=? char char)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#positive? fixnum)
o|  2 (chicken.base#sub1 *)
o|  1 (chicken.base#add1 fixnum)
o|  1 (scheme#min fixnum fixnum)
o|  1 (scheme#memq * list)
o|  1 (scheme#number->string * *)
o|  2 (chicken.base#add1 *)
o|  1 (scheme#- fixnum fixnum)
o|  1 (scheme#/ * *)
o|  1 (scheme#current-output-port)
o|  2 (scheme#zero? integer)
o|  31 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  1 (scheme#current-input-port)
o|  4 (##sys#check-output-port * * *)
o|  1 (scheme#> fixnum fixnum)
o|  5 (scheme#string-append string string)
o|  1 (scheme#make-string fixnum)
o|  1 (chicken.base#sub1 fixnum)
o|  1 (scheme#eqv? * *)
o|  6 (##sys#check-list (or pair list) *)
o|  41 (scheme#cdr pair)
o|  14 (scheme#car pair)
(o e)|safe calls: 1019 
(o e)|assignments to immediate values: 5 
o|removed side-effect free assignment to unused variable: chicken.csi#partition 
o|removed side-effect free assignment to unused variable: chicken.csi#span 
o|removed side-effect free assignment to unused variable: chicken.csi#drop 
o|removed side-effect free assignment to unused variable: chicken.csi#split-at 
o|removed side-effect free assignment to unused variable: chicken.csi#append-map 
o|inlining procedure: k2945 
o|inlining procedure: k2945 
o|inlining procedure: k2976 
o|inlining procedure: k2976 
o|removed side-effect free assignment to unused variable: chicken.csi#cons* 
o|removed side-effect free assignment to unused variable: chicken.csi#concatenate 
o|removed side-effect free assignment to unused variable: chicken.csi#first 
o|removed side-effect free assignment to unused variable: chicken.csi#second 
o|removed side-effect free assignment to unused variable: chicken.csi#third 
o|removed side-effect free assignment to unused variable: chicken.csi#fourth 
o|removed side-effect free assignment to unused variable: chicken.csi#fifth 
o|removed side-effect free assignment to unused variable: chicken.csi#alist-cons 
o|inlining procedure: k3193 
o|inlining procedure: k3193 
o|inlining procedure: k3185 
o|inlining procedure: k3185 
o|removed side-effect free assignment to unused variable: chicken.csi#filter-map 
o|removed side-effect free assignment to unused variable: chicken.csi#remove 
o|removed side-effect free assignment to unused variable: chicken.csi#unzip1 
o|removed side-effect free assignment to unused variable: chicken.csi#last 
o|removed side-effect free assignment to unused variable: chicken.csi#list-index 
o|removed side-effect free assignment to unused variable: chicken.csi#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.csi#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.csi#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.csi#lset-intersection/eq? 
o|inlining procedure: k3584 
o|inlining procedure: k3584 
o|removed side-effect free assignment to unused variable: chicken.csi#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.csi#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.csi#length+ 
o|removed side-effect free assignment to unused variable: chicken.csi#find 
o|removed side-effect free assignment to unused variable: chicken.csi#find-tail 
o|removed side-effect free assignment to unused variable: chicken.csi#iota 
o|removed side-effect free assignment to unused variable: chicken.csi#make-list 
o|removed side-effect free assignment to unused variable: chicken.csi#posq 
o|removed side-effect free assignment to unused variable: chicken.csi#posv 
o|substituted constant variable: chicken.csi#constant214 
o|inlining procedure: k3905 
o|inlining procedure: k3905 
o|inlining procedure: k3924 
o|inlining procedure: k3924 
o|inlining procedure: k3963 
o|inlining procedure: k3963 
o|substituted constant variable: a3979 
o|inlining procedure: k4017 
o|inlining procedure: k4032 
o|contracted procedure: "(csi.scm:184) _getcwd730" 
o|inlining procedure: k4032 
o|inlining procedure: k4071 
o|inlining procedure: k4071 
o|substituted constant variable: a4102 
o|contracted procedure: "(csi.scm:183) string-index741" 
o|inlining procedure: k3992 
o|inlining procedure: k3992 
o|inlining procedure: k4017 
o|substituted constant variable: a4112 
o|inlining procedure: k4176 
o|propagated global variable: out793796 ##sys#standard-output 
o|substituted constant variable: a4183 
o|substituted constant variable: a4184 
o|inlining procedure: k4176 
o|propagated global variable: out793796 ##sys#standard-output 
o|inlining procedure: k4223 
o|inlining procedure: k4223 
o|inlining procedure: k4298 
o|inlining procedure: k4298 
o|contracted procedure: "(csi.scm:266) chicken.csi#tty-input?" 
o|inlining procedure: k4289 
o|inlining procedure: k4289 
o|inlining procedure: k4323 
o|inlining procedure: k4323 
o|inlining procedure: k4366 
o|inlining procedure: k4366 
o|inlining procedure: k4387 
o|contracted procedure: "(csi.scm:296) g885886" 
o|inlining procedure: k4387 
o|inlining procedure: "(csi.scm:304) read864" 
o|inlining procedure: k4427 
o|inlining procedure: "(csi.scm:308) read864" 
o|inlining procedure: k4427 
o|consed rest parameter at call site: "(csi.scm:315) chicken.csi#describe" 2 
o|inlining procedure: "(csi.scm:313) read864" 
o|inlining procedure: k4460 
o|consed rest parameter at call site: "(csi.scm:319) chicken.csi#dump" 2 
o|inlining procedure: "(csi.scm:317) read864" 
o|inlining procedure: k4460 
o|consed rest parameter at call site: "(csi.scm:325) chicken.csi#dump" 2 
o|inlining procedure: "(csi.scm:322) read864" 
o|inlining procedure: "(csi.scm:321) read864" 
o|inlining procedure: k4496 
o|consed rest parameter at call site: "(csi.scm:326) chicken.csi#report" 1 
o|inlining procedure: k4496 
o|inlining procedure: k4514 
o|inlining procedure: k4532 
o|inlining procedure: k4532 
o|inlining procedure: k4514 
o|inlining procedure: k4588 
o|inlining procedure: k4588 
o|inlining procedure: k4612 
o|inlining procedure: "(csi.scm:337) read864" 
o|inlining procedure: k4612 
o|inlining procedure: k4667 
o|consed rest parameter at call site: "(csi.scm:344) chicken.csi#describe" 2 
o|inlining procedure: k4667 
o|inlining procedure: k4680 
o|inlining procedure: k4680 
o|contracted procedure: "(csi.scm:353) chicken.csi#history-clear" 
o|inlining procedure: k4730 
o|inlining procedure: k4730 
o|inlining procedure: k4754 
o|inlining procedure: "(csi.scm:362) read864" 
o|inlining procedure: k4754 
o|inlining procedure: "(csi.scm:365) read864" 
o|inlining procedure: k4783 
o|inlining procedure: k4783 
o|inlining procedure: k4839 
o|contracted procedure: "(csi.scm:394) g980987" 
o|inlining procedure: k4816 
o|inlining procedure: k4816 
o|inlining procedure: k4839 
o|propagated global variable: g986988 chicken.csi#command-table 
o|substituted constant variable: a4866 
o|substituted constant variable: a4868 
o|substituted constant variable: a4870 
o|substituted constant variable: a4872 
o|substituted constant variable: a4874 
o|substituted constant variable: a4876 
o|substituted constant variable: a4878 
o|substituted constant variable: a4880 
o|substituted constant variable: a4882 
o|substituted constant variable: a4884 
o|substituted constant variable: a4886 
o|substituted constant variable: a4888 
o|substituted constant variable: a4890 
o|substituted constant variable: a4892 
o|substituted constant variable: a4894 
o|substituted constant variable: a4896 
o|substituted constant variable: a4898 
o|substituted constant variable: a4900 
o|substituted constant variable: a4902 
o|merged explicitly consed rest parameter: port1067 
o|substituted constant variable: a5110 
o|substituted constant variable: a5129 
o|inlining procedure: k5136 
o|inlining procedure: k5136 
o|inlining procedure: k5174 
o|inlining procedure: k5174 
o|inlining procedure: k5260 
o|inlining procedure: k5260 
o|inlining procedure: k5293 
o|inlining procedure: k5293 
o|propagated global variable: g10941098 ##sys#features 
o|merged explicitly consed rest parameter: rest11771179 
o|inlining procedure: k5426 
o|inlining procedure: k5426 
o|inlining procedure: k5455 
o|inlining procedure: k5485 
o|inlining procedure: k5485 
o|inlining procedure: k5455 
o|inlining procedure: k5542 
o|inlining procedure: k5542 
o|inlining procedure: k5566 
o|inlining procedure: k5566 
o|inlining procedure: k5584 
o|inlining procedure: k5584 
o|inlining procedure: k5599 
o|inlining procedure: k5599 
o|inlining procedure: k5620 
o|inlining procedure: k5620 
o|inlining procedure: k5632 
o|inlining procedure: k5632 
o|inlining procedure: k5647 
o|inlining procedure: k5647 
o|inlining procedure: k5665 
o|inlining procedure: k5675 
o|inlining procedure: k5675 
o|inlining procedure: k5665 
o|inlining procedure: k5690 
o|inlining procedure: k5690 
o|inlining procedure: k5708 
o|inlining procedure: k5708 
o|inlining procedure: k5736 
o|inlining procedure: k5736 
o|inlining procedure: k5751 
o|inlining procedure: k5751 
o|inlining procedure: k5804 
o|inlining procedure: k5826 
o|inlining procedure: k5826 
o|inlining procedure: k5847 
o|inlining procedure: k5847 
o|inlining procedure: k5804 
o|inlining procedure: k5891 
o|inlining procedure: k5891 
o|inlining procedure: k5924 
o|inlining procedure: k5924 
o|inlining procedure: k5961 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|inlining procedure: k5994 
o|inlining procedure: k5994 
o|inlining procedure: k6006 
o|inlining procedure: k6006 
o|inlining procedure: k6018 
o|inlining procedure: k6018 
o|inlining procedure: k6030 
o|inlining procedure: k6030 
o|inlining procedure: k6042 
o|inlining procedure: k6042 
o|substituted constant variable: a6055 
o|substituted constant variable: a6057 
o|substituted constant variable: a6059 
o|substituted constant variable: a6061 
o|substituted constant variable: a6063 
o|substituted constant variable: a6065 
o|substituted constant variable: a6067 
o|substituted constant variable: a6069 
o|substituted constant variable: a6071 
o|substituted constant variable: a6073 
o|substituted constant variable: a6075 
o|substituted constant variable: a6077 
o|inlining procedure: k5961 
o|inlining procedure: k6091 
o|inlining procedure: k6091 
o|inlining procedure: k6116 
o|inlining procedure: k6143 
o|inlining procedure: k6143 
o|inlining procedure: k6181 
o|inlining procedure: k6181 
o|inlining procedure: k6116 
o|inlining procedure: k6240 
o|inlining procedure: k6240 
o|inlining procedure: k6295 
o|inlining procedure: k6295 
o|inlining procedure: k6319 
o|inlining procedure: k6377 
o|inlining procedure: k6377 
o|inlining procedure: k6345 
o|inlining procedure: k6345 
o|inlining procedure: k6319 
o|contracted procedure: "(csi.scm:638) chicken.csi#improper-pairs?" 
o|inlining procedure: k5373 
o|inlining procedure: k5373 
o|contracted procedure: "(csi.scm:638) chicken.csi#circular-list?" 
o|inlining procedure: k5338 
o|inlining procedure: k5358 
o|inlining procedure: k5358 
o|inlining procedure: k5338 
o|merged explicitly consed rest parameter: len-out1367 
o|inlining procedure: k6465 
o|inlining procedure: k6465 
o|inlining procedure: k6471 
o|inlining procedure: k6471 
o|inlining procedure: k6497 
o|inlining procedure: k6497 
o|inlining procedure: k6523 
o|inlining procedure: k6523 
o|inlining procedure: k6576 
o|inlining procedure: k6576 
o|inlining procedure: k6617 
o|inlining procedure: k6617 
o|inlining procedure: k6643 
o|inlining procedure: k6643 
o|inlining procedure: k6677 
o|inlining procedure: k6677 
o|inlining procedure: k6728 
o|inlining procedure: k6746 
o|inlining procedure: k6746 
o|inlining procedure: k6762 
o|inlining procedure: k6762 
o|inlining procedure: k6728 
o|inlining procedure: k6848 
o|propagated global variable: out14791482 ##sys#standard-output 
o|substituted constant variable: a6873 
o|substituted constant variable: a6874 
o|inlining procedure: k6848 
o|inlining procedure: k6922 
o|inlining procedure: k6922 
o|inlining procedure: k6937 
o|propagated global variable: out15191522 ##sys#standard-output 
o|substituted constant variable: a6944 
o|substituted constant variable: a6945 
o|inlining procedure: k6937 
o|propagated global variable: out15191522 ##sys#standard-output 
o|inlining procedure: k6996 
o|inlining procedure: k6996 
o|propagated global variable: out14911494 ##sys#standard-output 
o|substituted constant variable: a7034 
o|substituted constant variable: a7035 
o|propagated global variable: out14911494 ##sys#standard-output 
o|inlining procedure: k7050 
o|inlining procedure: k7050 
o|inlining procedure: k7064 
o|propagated global variable: out14791482 ##sys#standard-output 
o|inlining procedure: k7064 
o|inlining procedure: k7070 
o|inlining procedure: k7070 
o|propagated global variable: tmp14601462 ##sys#repl-recent-call-chain 
o|propagated global variable: tmp14601462 ##sys#repl-recent-call-chain 
o|inlining procedure: k7088 
o|inlining procedure: k7088 
o|inlining procedure: k7122 
o|inlining procedure: k7122 
o|inlining procedure: k7179 
o|inlining procedure: k7210 
o|inlining procedure: k7210 
o|inlining procedure: k7250 
o|inlining procedure: k7250 
o|inlining procedure: k7329 
o|inlining procedure: k7329 
o|inlining procedure: k7179 
o|inlining procedure: k7372 
o|inlining procedure: k7372 
o|propagated global variable: tmp15701572 ##sys#repl-recent-call-chain 
o|propagated global variable: tmp15701572 ##sys#repl-recent-call-chain 
o|inlining procedure: k7393 
o|inlining procedure: k7405 
o|inlining procedure: k7405 
o|inlining procedure: k7393 
o|inlining procedure: k7448 
o|inlining procedure: k7448 
o|inlining procedure: k7463 
o|inlining procedure: k7463 
o|inlining procedure: k7494 
o|inlining procedure: k7494 
o|inlining procedure: k7538 
o|contracted procedure: "(csi.scm:960) g17161725" 
o|inlining procedure: k7538 
o|contracted procedure: "(csi.scm:959) chicken.csi#findall" 
o|inlining procedure: k7630 
o|inlining procedure: k7630 
o|inlining procedure: k7589 
o|substituted constant variable: chicken.csi#constant1693 
o|inlining procedure: k7589 
o|contracted procedure: "(csi.scm:1157) chicken.csi#run" 
o|inlining procedure: k7822 
o|inlining procedure: k7822 
o|inlining procedure: k7817 
o|inlining procedure: k7817 
o|merged explicitly consed rest parameter: rest18961898 
o|inlining procedure: k7936 
o|inlining procedure: k7936 
o|propagated global variable: read-with-source-info1906 chicken.syntax#read-with-source-info 
o|inlining procedure: k8055 
o|contracted procedure: "(csi.scm:1114) chicken.csi#register-repl-history!" 
o|inlining procedure: k4247 
o|inlining procedure: k4247 
o|inlining procedure: k8055 
o|inlining procedure: k8089 
o|inlining procedure: k8089 
o|contracted procedure: "(csi.scm:1123) chicken.csi#string->extension-name" 
o|inlining procedure: k7710 
o|inlining procedure: k7710 
o|substituted constant variable: a7774 
o|substituted constant variable: a7771 
o|contracted procedure: "(csi.scm:991) chicken.csi#string-trim" 
o|inlining procedure: k7663 
o|inlining procedure: k7663 
o|inlining procedure: k7680 
o|inlining procedure: k7680 
o|substituted constant variable: a8130 
o|inlining procedure: k8127 
o|consed rest parameter at call site: "(csi.scm:1126) evalstring1835" 2 
o|inlining procedure: k8127 
o|substituted constant variable: a8149 
o|consed rest parameter at call site: "(csi.scm:1129) evalstring1835" 2 
o|substituted constant variable: a8174 
o|inlining procedure: k8171 
o|consed rest parameter at call site: "(csi.scm:1132) evalstring1835" 2 
o|inlining procedure: k8171 
o|inlining procedure: k8234 
o|inlining procedure: k8234 
o|inlining procedure: k8247 
o|inlining procedure: k8279 
o|inlining procedure: k8279 
o|substituted constant variable: a8301 
o|propagated global variable: g20662067 chicken.pretty-print#pretty-print 
o|inlining procedure: k8247 
o|substituted constant variable: a8316 
o|substituted constant variable: a8318 
o|substituted constant variable: a8320 
o|substituted constant variable: a8322 
o|substituted constant variable: chicken.csi#constant1766 
o|substituted constant variable: chicken.csi#constant1758 
o|contracted procedure: "(csi.scm:1109) loadinit1834" 
o|inlining procedure: k7867 
o|inlining procedure: k7867 
o|inlining procedure: k7891 
o|substituted constant variable: a7904 
o|inlining procedure: k7891 
o|inlining procedure: k8334 
o|inlining procedure: k8334 
o|inlining procedure: k8378 
o|inlining procedure: k8378 
o|inlining procedure: k8390 
o|inlining procedure: k8390 
o|inlining procedure: k8399 
o|inlining procedure: k8399 
o|inlining procedure: k8417 
o|inlining procedure: k8417 
o|contracted procedure: "(csi.scm:1073) chicken.csi#delete-duplicates" 
o|inlining procedure: k3137 
o|inlining procedure: k3137 
o|contracted procedure: "(mini-srfi-1.scm:123) chicken.csi#delete" 
o|inlining procedure: k3062 
o|inlining procedure: k3062 
o|inlining procedure: k8486 
o|inlining procedure: k8486 
o|inlining procedure: k8520 
o|inlining procedure: k8520 
o|inlining procedure: k8554 
o|inlining procedure: k8554 
o|inlining procedure: k8577 
o|inlining procedure: k8577 
o|inlining procedure: k8600 
o|inlining procedure: k8600 
o|inlining procedure: k8638 
o|inlining procedure: k8638 
o|contracted procedure: "(csi.scm:1052) chicken.csi#print-usage" 
o|inlining procedure: k8680 
o|inlining procedure: k8680 
o|inlining procedure: k8686 
o|inlining procedure: k8686 
o|inlining procedure: k8704 
o|inlining procedure: k8704 
o|substituted constant variable: a8724 
o|inlining procedure: k8744 
o|inlining procedure: k8744 
o|substituted constant variable: a8747 
o|inlining procedure: k8778 
o|inlining procedure: k8778 
o|contracted procedure: "(csi.scm:1000) chicken.csi#parse-option-string" 
o|inlining procedure: k4975 
o|contracted procedure: "(csi.scm:434) g10251034" 
o|inlining procedure: k4945 
o|inlining procedure: k4945 
o|inlining procedure: k4975 
o|inlining procedure: k5043 
o|inlining procedure: k5043 
o|inlining procedure: k8820 
o|inlining procedure: k8820 
o|inlining procedure: k8866 
o|inlining procedure: k8866 
o|substituted constant variable: a8876 
o|inlining procedure: k8880 
o|inlining procedure: k8880 
o|replaced variables: 1428 
o|removed binding forms: 406 
o|removed side-effect free assignment to unused variable: chicken.csi#constant214 
o|removed side-effect free assignment to unused variable: chicken.csi#every 
o|removed side-effect free assignment to unused variable: chicken.csi#any 
o|removed side-effect free assignment to unused variable: chicken.csi#filter 
o|removed side-effect free assignment to unused variable: chicken.csi#list-tabulate 
o|substituted constant variable: int732737 
o|substituted constant variable: r40728931 
o|substituted constant variable: r39938932 
o|substituted constant variable: r40188934 
o|contracted procedure: "(csi.scm:356) chicken.csi#history-show" 
o|propagated global variable: out793796 ##sys#standard-output 
o|contracted procedure: "(csi.scm:362) chicken.csi#select-frame" 
o|contracted procedure: "(csi.scm:365) chicken.csi#copy-from-frame" 
o|converted assignments to bindings: (fail1585) 
o|converted assignments to bindings: (compare1580) 
o|substituted constant variable: r73739186 
o|converted assignments to bindings: (shorten1076) 
o|substituted constant variable: r54869034 
o|substituted constant variable: r54869034 
o|substituted constant variable: r54869036 
o|substituted constant variable: r54869036 
o|inlining procedure: k5542 
o|substituted constant variable: r56769070 
o|substituted constant variable: r56769070 
o|substituted constant variable: r56769072 
o|substituted constant variable: r56769072 
o|inlining procedure: k5542 
o|removed call to pure procedure with unused result: "(csi.scm:652) ##sys#size" 
o|substituted constant variable: r59839094 
o|substituted constant variable: r59839094 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|substituted constant variable: r59959098 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|substituted constant variable: r60079100 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|substituted constant variable: r60199102 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|substituted constant variable: r60319104 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|substituted constant variable: r60439106 
o|inlining procedure: k5982 
o|inlining procedure: k5982 
o|substituted constant variable: r53749127 
o|substituted constant variable: r53399132 
o|converted assignments to bindings: (descseq1185) 
o|converted assignments to bindings: (bestlen1386) 
o|converted assignments to bindings: (justify1409) 
o|propagated global variable: out14791482 ##sys#standard-output 
o|propagated global variable: out15191522 ##sys#standard-output 
o|propagated global variable: out14911494 ##sys#standard-output 
o|substituted constant variable: r70519163 
o|substituted constant variable: r70519163 
o|substituted constant variable: r70519165 
o|substituted constant variable: r70519165 
o|substituted constant variable: r70659167 
o|substituted constant variable: r70659167 
o|substituted constant variable: r70659169 
o|substituted constant variable: r70659169 
o|substituted constant variable: r70719172 
o|converted assignments to bindings: (prin11457) 
o|substituted constant variable: r73949190 
o|removed side-effect free assignment to unused variable: chicken.csi#constant1693 
o|substituted constant variable: r74499191 
o|substituted constant variable: r75909202 
o|removed side-effect free assignment to unused variable: chicken.csi#constant1758 
o|removed side-effect free assignment to unused variable: chicken.csi#constant1766 
o|substituted constant variable: r78189206 
o|substituted constant variable: r76649217 
o|substituted constant variable: r82359227 
o|substituted constant variable: r82359227 
o|substituted constant variable: r82489233 
o|substituted constant variable: r82489233 
o|substituted constant variable: r78929238 
o|substituted constant variable: r87799294 
o|substituted constant variable: r88679305 
o|substituted constant variable: r88679305 
o|converted assignments to bindings: (addext740) 
o|simplifications: ((let . 8)) 
o|replaced variables: 106 
o|removed binding forms: 1194 
o|inlining procedure: k3902 
o|inlining procedure: k4301 
o|inlining procedure: k4711 
o|inlining procedure: k4711 
o|inlining procedure: k7231 
o|contracted procedure: k5910 
o|inlining procedure: k6246 
o|inlining procedure: k8079 
o|inlining procedure: k8079 
o|inlining procedure: k8079 
o|inlining procedure: k8079 
o|inlining procedure: k8079 
o|inlining procedure: k8079 
o|inlining procedure: k8079 
o|inlining procedure: k8291 
o|inlining procedure: k7879 
o|inlining procedure: "(csi.scm:1106) chicken.csi#print-banner" 
o|inlining procedure: k8623 
o|inlining procedure: "(csi.scm:1055) chicken.csi#print-banner" 
o|inlining procedure: k8735 
o|inlining procedure: k8735 
o|inlining procedure: k8735 
o|inlining procedure: k4996 
o|replaced variables: 13 
o|removed binding forms: 165 
o|removed side-effect free assignment to unused variable: chicken.csi#print-banner 
o|substituted constant variable: r39039511 
o|substituted constant variable: r39039511 
o|inlining procedure: k3927 
o|substituted constant variable: r59839370 
o|substituted constant variable: r59839372 
o|substituted constant variable: r59839374 
o|substituted constant variable: r59839376 
o|substituted constant variable: r59839378 
o|substituted constant variable: r59839380 
o|substituted constant variable: r59839382 
o|substituted constant variable: r59839384 
o|substituted constant variable: r59839386 
o|substituted constant variable: r59839388 
o|substituted constant variable: r59839390 
o|contracted procedure: k8061 
o|substituted constant variable: r78809647 
o|replaced variables: 9 
o|removed binding forms: 23 
o|removed conditional forms: 2 
o|substituted constant variable: r39289690 
o|removed binding forms: 23 
o|removed conditional forms: 1 
o|simplifications: ((let . 1)) 
o|removed binding forms: 1 
o|simplifications: ((let . 34) (if . 47) (##core#call . 558)) 
o|  call simplifications:
o|    scheme#make-vector
o|    scheme#set-car!
o|    ##sys#cons	2
o|    scheme#=
o|    scheme#char-whitespace?	3
o|    ##sys#list	3
o|    chicken.base#void
o|    scheme#member	9
o|    scheme#string->list
o|    scheme#string
o|    scheme#equal?	4
o|    chicken.fixnum#fxmod
o|    scheme#write-char	7
o|    ##sys#immediate?	2
o|    ##sys#permanent?
o|    scheme#char?
o|    chicken.base#fixnum?	2
o|    chicken.base#bignum?
o|    chicken.base#flonum?
o|    chicken.base#ratnum?
o|    chicken.base#cplxnum?
o|    scheme#vector?
o|    scheme#list?
o|    scheme#procedure?
o|    ##sys#pointer?	2
o|    ##sys#generic-structure?	2
o|    scheme#cdr	19
o|    scheme#caar
o|    scheme#cdar
o|    chicken.fixnum#fx=	4
o|    chicken.base#atom?
o|    scheme#memq	4
o|    scheme#cddr	3
o|    scheme#exact?
o|    scheme#integer->char	2
o|    scheme#char->integer
o|    ##sys#setslot	8
o|    scheme#<=
o|    scheme#+
o|    scheme#*
o|    scheme#eof-object?	4
o|    scheme#caddr
o|    scheme#symbol?	2
o|    scheme#string?	4
o|    ##sys#structure?	4
o|    ##sys#check-list	16
o|    scheme#string-length	6
o|    chicken.fixnum#fxmin
o|    scheme#string=?	7
o|    scheme#number?	2
o|    chicken.fixnum#fx<	4
o|    scheme#length	4
o|    chicken.fixnum#fx-	11
o|    scheme#list-ref	2
o|    scheme#>=	2
o|    scheme#eq?	44
o|    scheme#not	12
o|    scheme#apply	5
o|    ##sys#call-with-values	7
o|    ##sys#apply	3
o|    scheme#cadr	13
o|    scheme#car	21
o|    ##sys#check-symbol	2
o|    ##sys#check-string
o|    scheme#assq	4
o|    scheme#cons	25
o|    scheme#list	12
o|    scheme#set-cdr!	2
o|    chicken.fixnum#fx<=
o|    scheme#vector-ref	8
o|    scheme#null?	24
o|    ##sys#void	20
o|    chicken.fixnum#fx*
o|    scheme#vector-set!
o|    chicken.fixnum#fx>=	15
o|    chicken.fixnum#fx+	20
o|    scheme#pair?	30
o|    ##sys#slot	83
o|    ##sys#foreign-block-argument
o|    ##sys#foreign-fixnum-argument
o|    ##sys#size	13
o|    scheme#string-ref	6
o|    chicken.fixnum#fx>	6
o|    scheme#char=?	7
o|contracted procedure: k3845 
o|contracted procedure: k3902 
o|contracted procedure: k3918 
o|contracted procedure: k3921 
o|contracted procedure: k3933 
o|contracted procedure: k4109 
o|contracted procedure: k4020 
o|contracted procedure: k3950 
o|contracted procedure: k3954 
o|contracted procedure: k4074 
o|contracted procedure: k4090 
o|contracted procedure: k4099 
o|contracted procedure: k3983 
o|contracted procedure: k3995 
o|contracted procedure: k4008 
o|contracted procedure: k4105 
o|contracted procedure: k4114 
o|contracted procedure: k4148 
o|contracted procedure: k4121 
o|contracted procedure: k4124 
o|contracted procedure: k4130 
o|contracted procedure: k4134 
o|contracted procedure: k4137 
o|contracted procedure: k4145 
o|contracted procedure: k4235 
o|contracted procedure: k4226 
o|contracted procedure: k4352 
o|contracted procedure: k4311 
o|contracted procedure: k4314 
o|contracted procedure: k4317 
o|contracted procedure: k4320 
o|contracted procedure: k4335 
o|contracted procedure: k4346 
o|contracted procedure: k4342 
o|contracted procedure: k4369 
o|contracted procedure: k4381 
o|contracted procedure: k4384 
o|contracted procedure: k4392 
o|contracted procedure: k4407 
o|contracted procedure: k4430 
o|contracted procedure: k4448 
o|contracted procedure: k4463 
o|contracted procedure: k4478 
o|contracted procedure: k4499 
o|contracted procedure: k4508 
o|contracted procedure: k4517 
o|contracted procedure: k4535 
o|contracted procedure: k4545 
o|contracted procedure: k4549 
o|contracted procedure: k4559 
o|contracted procedure: k4591 
o|contracted procedure: k4601 
o|contracted procedure: k4605 
o|contracted procedure: k4615 
o|contracted procedure: k4664 
o|contracted procedure: k4677 
o|contracted procedure: k4683 
o|contracted procedure: k4699 
o|contracted procedure: k4692 
o|contracted procedure: k4721 
o|contracted procedure: k4164 
o|propagated global variable: r4165 ##sys#undefined-value 
o|contracted procedure: k4733 
o|contracted procedure: k4179 
o|contracted procedure: k4204 
o|contracted procedure: k4214 
o|contracted procedure: k4745 
o|contracted procedure: k4757 
o|contracted procedure: k7139 
o|contracted procedure: k7091 
o|contracted procedure: k7112 
o|contracted procedure: k7116 
o|contracted procedure: k7108 
o|contracted procedure: k7101 
o|contracted procedure: k7119 
o|contracted procedure: k7125 
o|contracted procedure: k7135 
o|contracted procedure: k4773 
o|contracted procedure: k7145 
o|contracted procedure: k7148 
o|contracted procedure: k7157 
o|contracted procedure: k7172 
o|contracted procedure: k7176 
o|contracted procedure: k7168 
o|contracted procedure: k7201 
o|propagated global variable: r7202 ##sys#undefined-value 
o|contracted procedure: k7213 
o|contracted procedure: k7219 
o|contracted procedure: k7222 
o|contracted procedure: k7225 
o|contracted procedure: k7228 
o|contracted procedure: k7239 
o|contracted procedure: k7253 
o|contracted procedure: k7263 
o|contracted procedure: k7287 
o|contracted procedure: k7295 
o|contracted procedure: k7291 
o|contracted procedure: k7301 
o|contracted procedure: k7304 
o|contracted procedure: k7307 
o|contracted procedure: k7310 
o|contracted procedure: k7313 
o|contracted procedure: k7357 
o|contracted procedure: k7332 
o|contracted procedure: k7342 
o|contracted procedure: k7346 
o|contracted procedure: k7350 
o|contracted procedure: k7354 
o|contracted procedure: k7366 
o|contracted procedure: k7375 
o|contracted procedure: k4786 
o|contracted procedure: k4799 
o|contracted procedure: k4805 
o|contracted procedure: k4827 
o|contracted procedure: k4842 
o|contracted procedure: k4852 
o|contracted procedure: k4856 
o|contracted procedure: k4813 
o|propagated global variable: g986988 chicken.csi#command-table 
o|contracted procedure: k4921 
o|contracted procedure: k4928 
o|contracted procedure: k5324 
o|contracted procedure: k5085 
o|contracted procedure: k5112 
o|contracted procedure: k5126 
o|contracted procedure: k5139 
o|contracted procedure: k5153 
o|contracted procedure: k5159 
o|contracted procedure: k5162 
o|contracted procedure: k5218 
o|contracted procedure: k5222 
o|contracted procedure: k5226 
o|contracted procedure: k5230 
o|contracted procedure: k5234 
o|contracted procedure: k5238 
o|contracted procedure: k5246 
o|contracted procedure: k5250 
o|contracted procedure: k5263 
o|contracted procedure: k5273 
o|contracted procedure: k5277 
o|contracted procedure: k5281 
o|contracted procedure: k5284 
o|contracted procedure: k5296 
o|contracted procedure: k5299 
o|contracted procedure: k5302 
o|contracted procedure: k5310 
o|contracted procedure: k5318 
o|propagated global variable: g10941098 ##sys#features 
o|contracted procedure: k6442 
o|contracted procedure: k5405 
o|contracted procedure: k5411 
o|contracted procedure: k5423 
o|contracted procedure: k5432 
o|contracted procedure: k5439 
o|contracted procedure: k5525 
o|contracted procedure: k5449 
o|contracted procedure: k5458 
o|contracted procedure: k5471 
o|contracted procedure: k5474 
o|contracted procedure: k5481 
o|contracted procedure: k5488 
o|contracted procedure: k5503 
o|contracted procedure: k5510 
o|contracted procedure: k5514 
o|contracted procedure: k5529 
o|contracted procedure: k5548 
o|contracted procedure: k5551 
o|contracted procedure: k5560 
o|contracted procedure: k5569 
o|contracted procedure: k5578 
o|contracted procedure: k5593 
o|contracted procedure: k6429 
o|contracted procedure: k5602 
o|propagated global variable: r6430 ##sys#undefined-value 
o|contracted procedure: k5611 
o|contracted procedure: k5617 
o|contracted procedure: k5626 
o|contracted procedure: k5635 
o|contracted procedure: k5650 
o|contracted procedure: k5659 
o|contracted procedure: k5668 
o|contracted procedure: k5678 
o|contracted procedure: k5684 
o|contracted procedure: k5693 
o|contracted procedure: k5702 
o|contracted procedure: k5724 
o|contracted procedure: k5733 
o|contracted procedure: k5739 
o|contracted procedure: k5754 
o|contracted procedure: k5770 
o|contracted procedure: k5780 
o|contracted procedure: k5784 
o|contracted procedure: k5788 
o|contracted procedure: k5820 
o|contracted procedure: k5829 
o|contracted procedure: k5832 
o|contracted procedure: k5876 
o|contracted procedure: k5841 
o|contracted procedure: k5870 
o|contracted procedure: k5850 
o|contracted procedure: k5862 
o|contracted procedure: k5885 
o|contracted procedure: k5894 
o|contracted procedure: k5907 
o|contracted procedure: k5949 
o|contracted procedure: k5934 
o|contracted procedure: k5938 
o|contracted procedure: k5942 
o|contracted procedure: k5955 
o|contracted procedure: k5975 
o|contracted procedure: k5979 
o|contracted procedure: k5985 
o|contracted procedure: k5991 
o|contracted procedure: k5997 
o|contracted procedure: k6003 
o|contracted procedure: k6009 
o|contracted procedure: k6015 
o|contracted procedure: k6021 
o|contracted procedure: k6027 
o|contracted procedure: k6033 
o|contracted procedure: k6039 
o|contracted procedure: k6045 
o|contracted procedure: k6051 
o|contracted procedure: k6081 
o|contracted procedure: k6097 
o|contracted procedure: k6119 
o|contracted procedure: k6122 
o|contracted procedure: k6131 
o|contracted procedure: k6134 
o|contracted procedure: k6146 
o|contracted procedure: k6155 
o|contracted procedure: k6159 
o|contracted procedure: k6162 
o|contracted procedure: k6165 
o|contracted procedure: k6175 
o|contracted procedure: k6184 
o|contracted procedure: k6194 
o|contracted procedure: k6198 
o|contracted procedure: k6202 
o|contracted procedure: k6213 
o|contracted procedure: k6206 
o|contracted procedure: k6210 
o|contracted procedure: k6219 
o|contracted procedure: k6234 
o|contracted procedure: k6243 
o|contracted procedure: k6253 
o|contracted procedure: k6280 
o|contracted procedure: k6256 
o|contracted procedure: k6272 
o|contracted procedure: k6276 
o|contracted procedure: k62539562 
o|contracted procedure: k6283 
o|contracted procedure: k6286 
o|contracted procedure: k6298 
o|contracted procedure: k6308 
o|contracted procedure: k6312 
o|contracted procedure: k6316 
o|contracted procedure: k6322 
o|contracted procedure: k6325 
o|contracted procedure: k6342 
o|contracted procedure: k6358 
o|contracted procedure: k6361 
o|contracted procedure: k6364 
o|contracted procedure: k6371 
o|contracted procedure: k6380 
o|contracted procedure: k6383 
o|contracted procedure: k6386 
o|contracted procedure: k6394 
o|contracted procedure: k6402 
o|contracted procedure: k6418 
o|contracted procedure: k5395 
o|contracted procedure: k5376 
o|contracted procedure: k5391 
o|contracted procedure: k5379 
o|contracted procedure: k5341 
o|contracted procedure: k5348 
o|contracted procedure: k5352 
o|contracted procedure: k5355 
o|contracted procedure: k6432 
o|contracted procedure: k6451 
o|contracted procedure: k6474 
o|contracted procedure: k6494 
o|contracted procedure: k6500 
o|contracted procedure: k6511 
o|contracted procedure: k6563 
o|contracted procedure: k6556 
o|contracted procedure: k6517 
o|contracted procedure: k6529 
o|contracted procedure: k6540 
o|contracted procedure: k6546 
o|contracted procedure: k6553 
o|contracted procedure: k6579 
o|contracted procedure: k6585 
o|contracted procedure: k6592 
o|contracted procedure: k6598 
o|contracted procedure: k6614 
o|contracted procedure: k6620 
o|contracted procedure: k6632 
o|contracted procedure: k6646 
o|contracted procedure: k6671 
o|contracted procedure: k6680 
o|contracted procedure: k6683 
o|contracted procedure: k6696 
o|contracted procedure: k6700 
o|contracted procedure: k6716 
o|contracted procedure: k6703 
o|contracted procedure: k6710 
o|contracted procedure: k6731 
o|contracted procedure: k6734 
o|contracted procedure: k6740 
o|contracted procedure: k6743 
o|contracted procedure: k6749 
o|contracted procedure: k6756 
o|contracted procedure: k6765 
o|contracted procedure: k6775 
o|contracted procedure: k6788 
o|contracted procedure: k6792 
o|contracted procedure: k6825 
o|contracted procedure: k6828 
o|contracted procedure: k6832 
o|contracted procedure: k6842 
o|contracted procedure: k6851 
o|contracted procedure: k6854 
o|contracted procedure: k6857 
o|contracted procedure: k6860 
o|contracted procedure: k6863 
o|contracted procedure: k6866 
o|contracted procedure: k6869 
o|contracted procedure: k6914 
o|contracted procedure: k6917 
o|contracted procedure: k6925 
o|contracted procedure: k6940 
o|contracted procedure: k6965 
o|contracted procedure: k6971 
o|contracted procedure: k6975 
o|contracted procedure: k6978 
o|contracted procedure: k6981 
o|contracted procedure: k6984 
o|contracted procedure: k6987 
o|contracted procedure: k7024 
o|contracted procedure: k6999 
o|contracted procedure: k7009 
o|contracted procedure: k7013 
o|contracted procedure: k7017 
o|contracted procedure: k7021 
o|contracted procedure: k7046 
o|contracted procedure: k7060 
o|contracted procedure: k7073 
o|contracted procedure: k7080 
o|contracted procedure: k7381 
o|contracted procedure: k7396 
o|contracted procedure: k7408 
o|contracted procedure: k7415 
o|contracted procedure: k7430 
o|contracted procedure: k7434 
o|contracted procedure: k7421 
o|contracted procedure: k7451 
o|contracted procedure: k7454 
o|contracted procedure: k7460 
o|contracted procedure: k7615 
o|contracted procedure: k7607 
o|contracted procedure: k7466 
o|contracted procedure: k7472 
o|contracted procedure: k7497 
o|contracted procedure: k7518 
o|contracted procedure: k7541 
o|contracted procedure: k7563 
o|contracted procedure: k7559 
o|contracted procedure: k7544 
o|contracted procedure: k7547 
o|contracted procedure: k7555 
o|contracted procedure: k7627 
o|contracted procedure: k7645 
o|contracted procedure: k7636 
o|contracted procedure: k7604 
o|contracted procedure: k7586 
o|contracted procedure: k7592 
o|contracted procedure: k7599 
o|contracted procedure: k7802 
o|contracted procedure: k7814 
o|contracted procedure: k7846 
o|contracted procedure: k7825 
o|contracted procedure: k7835 
o|contracted procedure: k7962 
o|contracted procedure: k7920 
o|contracted procedure: k7939 
o|contracted procedure: k7994 
o|contracted procedure: k8003 
o|contracted procedure: k8012 
o|contracted procedure: k8058 
o|contracted procedure: k4250 
o|contracted procedure: k4253 
o|contracted procedure: k4264 
o|contracted procedure: k8073 
o|contracted procedure: k8076 
o|contracted procedure: k8086 
o|contracted procedure: k80869612 
o|contracted procedure: k8092 
o|contracted procedure: k8096 
o|contracted procedure: k80869616 
o|contracted procedure: k8102 
o|contracted procedure: k8105 
o|contracted procedure: k8112 
o|contracted procedure: k80869620 
o|contracted procedure: k8116 
o|contracted procedure: k8124 
o|contracted procedure: k7768 
o|contracted procedure: k7713 
o|contracted procedure: k7657 
o|contracted procedure: k7666 
o|contracted procedure: k7701 
o|contracted procedure: k7672 
o|contracted procedure: k7695 
o|contracted procedure: k7683 
o|contracted procedure: k8132 
o|contracted procedure: k8139 
o|contracted procedure: k80869626 
o|contracted procedure: k8143 
o|contracted procedure: k8151 
o|contracted procedure: k8158 
o|contracted procedure: k80869630 
o|contracted procedure: k8162 
o|contracted procedure: k8176 
o|contracted procedure: k8183 
o|contracted procedure: k80869634 
o|contracted procedure: k8187 
o|contracted procedure: k8196 
o|contracted procedure: k8205 
o|contracted procedure: k8240 
o|contracted procedure: k8227 
o|contracted procedure: k8237 
o|contracted procedure: k80869638 
o|contracted procedure: k8250 
o|contracted procedure: k8258 
o|contracted procedure: k8282 
o|contracted procedure: k8285 
o|contracted procedure: k8298 
o|contracted procedure: k82989642 
o|contracted procedure: k8328 
o|contracted procedure: k7907 
o|contracted procedure: k7894 
o|contracted procedure: k7914 
o|contracted procedure: k8347 
o|contracted procedure: k8351 
o|contracted procedure: k8450 
o|contracted procedure: k8446 
o|contracted procedure: k8402 
o|contracted procedure: k8442 
o|contracted procedure: k8411 
o|contracted procedure: k8420 
o|contracted procedure: k8429 
o|contracted procedure: k3140 
o|contracted procedure: k3143 
o|contracted procedure: k3153 
o|contracted procedure: k3065 
o|contracted procedure: k3091 
o|contracted procedure: k3071 
o|contracted procedure: k8458 
o|contracted procedure: k8464 
o|contracted procedure: k8471 
o|contracted procedure: k8477 
o|contracted procedure: k8489 
o|contracted procedure: k8492 
o|contracted procedure: k8495 
o|contracted procedure: k8503 
o|contracted procedure: k8511 
o|contracted procedure: k8523 
o|contracted procedure: k8526 
o|contracted procedure: k8529 
o|contracted procedure: k8537 
o|contracted procedure: k8545 
o|contracted procedure: k8557 
o|contracted procedure: k8567 
o|contracted procedure: k8571 
o|contracted procedure: k8580 
o|contracted procedure: k8590 
o|contracted procedure: k8594 
o|contracted procedure: k8603 
o|contracted procedure: k8613 
o|contracted procedure: k8617 
o|contracted procedure: k8645 
o|contracted procedure: k8658 
o|contracted procedure: k8662 
o|contracted procedure: k3886 
o|contracted procedure: k3882 
o|contracted procedure: k3878 
o|contracted procedure: k8701 
o|contracted procedure: k8719 
o|contracted procedure: k8729 
o|contracted procedure: k8768 
o|contracted procedure: k8764 
o|contracted procedure: k8732 
o|contracted procedure: k8760 
o|contracted procedure: k8756 
o|contracted procedure: k8741 
o|contracted procedure: k8749 
o|contracted procedure: k8775 
o|contracted procedure: k8796 
o|contracted procedure: k4940 
o|contracted procedure: k4966 
o|contracted procedure: k4978 
o|contracted procedure: k4984 
o|contracted procedure: k4992 
o|contracted procedure: k5000 
o|contracted procedure: k4948 
o|contracted procedure: k5046 
o|contracted procedure: k5060 
o|contracted procedure: k8823 
o|contracted procedure: k8896 
o|contracted procedure: k8900 
o|contracted procedure: k8904 
o|contracted procedure: k8908 
o|simplifications: ((if . 8) (let . 225)) 
o|removed binding forms: 507 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest840843 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest840843 0 
o|contracted procedure: k4378 
o|inlining procedure: k7256 
o|contracted procedure: k6526 
o|inlining procedure: k6905 
o|contracted procedure: k7053 
(o x)|known list op on rest arg sublist: ##core#rest-null? rs2082 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rs2082 0 
o|substituted constant variable: r8897 
o|substituted constant variable: r8901 
o|substituted constant variable: r8905 
o|substituted constant variable: r8909 
o|replaced variables: 12 
o|removed binding forms: 3 
o|removed binding forms: 8 
o|direct leaf routine/allocation: g855856 6 
o|direct leaf routine/allocation: lp1160 0 
o|direct leaf routine/allocation: lp1146 0 
o|direct leaf routine/allocation: loop1746 0 
o|contracted procedure: "(csi.scm:273) k4323" 
o|contracted procedure: k5807 
o|converted assignments to bindings: (lp1160) 
o|converted assignments to bindings: (lp1146) 
o|contracted procedure: k7511 
o|converted assignments to bindings: (loop1746) 
o|simplifications: ((let . 3)) 
o|removed binding forms: 3 
o|customizable procedures: (k3858 g10101011 doloop10461047 k4981 map-loop10191052 chicken.csi#canonicalize-args chicken.csi#lookup-script-file k7790 k7796 k7979 k7985 for-each-loop18381920 for-each-loop18481927 for-each-loop18581934 map-loop19411958 collect-options1833 map-loop19671984 loop375 loop395 chicken.csi#member* k8046 doloop20692070 evalstring1835 loop1770 doloop18662015 chicken.csi#history-ref doloop19071908 g18761877 loop1868 k7491 map-loop17101735 loop1697 find1676 loop1673 k6835 g15021510 for-each-loop15011531 prin11457 doloop15151516 doloop14641470 justify1409 doloop14181420 doloop14271428 doloop14191435 doloop14081416 def-len13721394 def-out13731392 body13701379 bestlen1386 k5810 g13281329 map-loop13331350 g13171318 g12881295 for-each-loop12871304 loop1298 g12661273 for-each-loop12651276 doloop12601261 chicken.csi#hexdump loop-print1235 doloop12221223 loop21205 loop11195 map-loop10821099 g11091116 for-each-loop11081130 shorten1076 k5133 for-each-loop979991 k7151 g15991607 for-each-loop15981622 compare1580 doloop16121613 doloop15841589 fail1585 k7094 chicken.csi#show-frameinfo doloop790791 chicken.csi#history-add g933940 for-each-loop932952 for-each-loop913923 chicken.csi#report chicken.csi#dump chicken.csi#describe k4127 loop748 loop767 addext740) 
o|calls to known targets: 252 
o|unused rest argument: rest840843 f_4309 
o|identified direct recursive calls: f_7208 1 
o|identified direct recursive calls: f_5336 1 
o|identified direct recursive calls: f_6238 1 
o|identified direct recursive calls: f_5371 1 
o|identified direct recursive calls: f_7403 1 
o|identified direct recursive calls: f_7625 1 
o|identified direct recursive calls: f_7536 1 
o|identified direct recursive calls: f_7446 1 
o|unused rest argument: _1904 f_7965 
o|identified direct recursive calls: f_7661 2 
o|unused rest argument: rs2082 f_8225 
o|identified direct recursive calls: f_8053 2 
o|identified direct recursive calls: f_3060 2 
o|fast box initializations: 49 
o|fast global references: 81 
o|fast global assignments: 26 
o|dropping unused closure argument: f_3961 
o|dropping unused closure argument: f_4218 
o|dropping unused closure argument: f_5101 
o|dropping unused closure argument: f_5336 
o|dropping unused closure argument: f_5371 
o|dropping unused closure argument: f_6458 
o|dropping unused closure argument: f_6606 
o|dropping unused closure argument: f_6609 
o|dropping unused closure argument: f_6811 
o|dropping unused closure argument: f_6814 
o|dropping unused closure argument: f_7385 
o|dropping unused closure argument: f_7440 
o|dropping unused closure argument: f_7625 
o|dropping unused closure argument: f_7918 
*/
/* end of file */
