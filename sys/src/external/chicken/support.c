/* Generated from support.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: support.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -no-lambda-info -no-trace -emit-import-library chicken.compiler.support -output-file support.c
   unit: support
   uses: eval expand data-structures port pathname internal extras file library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_port_toplevel)
C_externimport void C_ccall C_port_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externimport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_file_toplevel)
C_externimport void C_ccall C_file_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[541];
static double C_possibly_force_alignment;


#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub4238(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word lit=(C_word )(C_a0);
return(C_header_size(lit));
C_ret:
#undef return

return C_r;}

/* from k7256 */
C_regparm static C_word C_fcall stub932(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_wordstobytes(t0));
return C_r;}

/* from k7249 */
C_regparm static C_word C_fcall stub927(C_word C_buf,C_word C_a0){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
int t0=(int )C_unfix(C_a0);
C_r=C_fix((C_word)C_bytestowords(t0));
return C_r;}

C_noret_decl(f19574)
static void C_ccall f19574(C_word c,C_word *av) C_noret;
C_noret_decl(f_10002)
static void C_fcall f_10002(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10027)
static void C_ccall f_10027(C_word c,C_word *av) C_noret;
C_noret_decl(f_10057)
static void C_ccall f_10057(C_word c,C_word *av) C_noret;
C_noret_decl(f_10059)
static void C_fcall f_10059(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10084)
static void C_ccall f_10084(C_word c,C_word *av) C_noret;
C_noret_decl(f_10115)
static void C_fcall f_10115(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_10127)
static void C_ccall f_10127(C_word c,C_word *av) C_noret;
C_noret_decl(f_10131)
static void C_ccall f_10131(C_word c,C_word *av) C_noret;
C_noret_decl(f_10154)
static void C_ccall f_10154(C_word c,C_word *av) C_noret;
C_noret_decl(f_10165)
static void C_fcall f_10165(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10172)
static void C_ccall f_10172(C_word c,C_word *av) C_noret;
C_noret_decl(f_10183)
static void C_ccall f_10183(C_word c,C_word *av) C_noret;
C_noret_decl(f_10185)
static void C_fcall f_10185(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10210)
static void C_ccall f_10210(C_word c,C_word *av) C_noret;
C_noret_decl(f_10240)
static void C_ccall f_10240(C_word c,C_word *av) C_noret;
C_noret_decl(f_10242)
static void C_fcall f_10242(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10267)
static void C_ccall f_10267(C_word c,C_word *av) C_noret;
C_noret_decl(f_10281)
static void C_ccall f_10281(C_word c,C_word *av) C_noret;
C_noret_decl(f_10291)
static void C_ccall f_10291(C_word c,C_word *av) C_noret;
C_noret_decl(f_10293)
static void C_fcall f_10293(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10318)
static void C_ccall f_10318(C_word c,C_word *av) C_noret;
C_noret_decl(f_10391)
static void C_ccall f_10391(C_word c,C_word *av) C_noret;
C_noret_decl(f_10397)
static void C_fcall f_10397(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10423)
static void C_ccall f_10423(C_word c,C_word *av) C_noret;
C_noret_decl(f_10427)
static void C_ccall f_10427(C_word c,C_word *av) C_noret;
C_noret_decl(f_10443)
static void C_ccall f_10443(C_word c,C_word *av) C_noret;
C_noret_decl(f_10449)
static void C_ccall f_10449(C_word c,C_word *av) C_noret;
C_noret_decl(f_10455)
static void C_ccall f_10455(C_word c,C_word *av) C_noret;
C_noret_decl(f_10461)
static void C_ccall f_10461(C_word c,C_word *av) C_noret;
C_noret_decl(f_10465)
static void C_ccall f_10465(C_word c,C_word *av) C_noret;
C_noret_decl(f_10468)
static void C_ccall f_10468(C_word c,C_word *av) C_noret;
C_noret_decl(f_10482)
static void C_ccall f_10482(C_word c,C_word *av) C_noret;
C_noret_decl(f_10485)
static void C_ccall f_10485(C_word c,C_word *av) C_noret;
C_noret_decl(f_10488)
static void C_ccall f_10488(C_word c,C_word *av) C_noret;
C_noret_decl(f_10495)
static void C_ccall f_10495(C_word c,C_word *av) C_noret;
C_noret_decl(f_10497)
static void C_fcall f_10497(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10512)
static void C_fcall f_10512(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10545)
static void C_ccall f_10545(C_word c,C_word *av) C_noret;
C_noret_decl(f_10573)
static void C_ccall f_10573(C_word c,C_word *av) C_noret;
C_noret_decl(f_10577)
static void C_ccall f_10577(C_word c,C_word *av) C_noret;
C_noret_decl(f_10601)
static void C_ccall f_10601(C_word c,C_word *av) C_noret;
C_noret_decl(f_10633)
static void C_ccall f_10633(C_word c,C_word *av) C_noret;
C_noret_decl(f_10642)
static void C_fcall f_10642(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10646)
static void C_ccall f_10646(C_word c,C_word *av) C_noret;
C_noret_decl(f_10652)
static void C_ccall f_10652(C_word c,C_word *av) C_noret;
C_noret_decl(f_10658)
static void C_ccall f_10658(C_word c,C_word *av) C_noret;
C_noret_decl(f_10661)
static void C_ccall f_10661(C_word c,C_word *av) C_noret;
C_noret_decl(f_10666)
static void C_fcall f_10666(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10676)
static void C_ccall f_10676(C_word c,C_word *av) C_noret;
C_noret_decl(f_10691)
static void C_ccall f_10691(C_word c,C_word *av) C_noret;
C_noret_decl(f_10693)
static void C_fcall f_10693(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10718)
static void C_ccall f_10718(C_word c,C_word *av) C_noret;
C_noret_decl(f_10739)
static void C_fcall f_10739(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10764)
static void C_ccall f_10764(C_word c,C_word *av) C_noret;
C_noret_decl(f_10786)
static void C_ccall f_10786(C_word c,C_word *av) C_noret;
C_noret_decl(f_10794)
static void C_fcall f_10794(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10845)
static void C_ccall f_10845(C_word c,C_word *av) C_noret;
C_noret_decl(f_10852)
static void C_ccall f_10852(C_word c,C_word *av) C_noret;
C_noret_decl(f_10855)
static void C_ccall f_10855(C_word c,C_word *av) C_noret;
C_noret_decl(f_10884)
static void C_ccall f_10884(C_word c,C_word *av) C_noret;
C_noret_decl(f_10892)
static void C_ccall f_10892(C_word c,C_word *av) C_noret;
C_noret_decl(f_10908)
static void C_ccall f_10908(C_word c,C_word *av) C_noret;
C_noret_decl(f_10911)
static void C_ccall f_10911(C_word c,C_word *av) C_noret;
C_noret_decl(f_10917)
static void C_ccall f_10917(C_word c,C_word *av) C_noret;
C_noret_decl(f_10937)
static void C_ccall f_10937(C_word c,C_word *av) C_noret;
C_noret_decl(f_10960)
static void C_ccall f_10960(C_word c,C_word *av) C_noret;
C_noret_decl(f_10965)
static void C_fcall f_10965(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10969)
static void C_ccall f_10969(C_word c,C_word *av) C_noret;
C_noret_decl(f_10972)
static void C_ccall f_10972(C_word c,C_word *av) C_noret;
C_noret_decl(f_10978)
static void C_ccall f_10978(C_word c,C_word *av) C_noret;
C_noret_decl(f_10981)
static void C_ccall f_10981(C_word c,C_word *av) C_noret;
C_noret_decl(f_10998)
static void C_fcall f_10998(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11008)
static void C_ccall f_11008(C_word c,C_word *av) C_noret;
C_noret_decl(f_11010)
static void C_fcall f_11010(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11035)
static void C_ccall f_11035(C_word c,C_word *av) C_noret;
C_noret_decl(f_11046)
static void C_ccall f_11046(C_word c,C_word *av) C_noret;
C_noret_decl(f_11054)
static void C_ccall f_11054(C_word c,C_word *av) C_noret;
C_noret_decl(f_11062)
static void C_ccall f_11062(C_word c,C_word *av) C_noret;
C_noret_decl(f_11075)
static void C_ccall f_11075(C_word c,C_word *av) C_noret;
C_noret_decl(f_11077)
static void C_fcall f_11077(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11125)
static void C_fcall f_11125(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11150)
static void C_ccall f_11150(C_word c,C_word *av) C_noret;
C_noret_decl(f_11169)
static void C_ccall f_11169(C_word c,C_word *av) C_noret;
C_noret_decl(f_11174)
static void C_fcall f_11174(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11184)
static void C_ccall f_11184(C_word c,C_word *av) C_noret;
C_noret_decl(f_11186)
static void C_fcall f_11186(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11211)
static void C_ccall f_11211(C_word c,C_word *av) C_noret;
C_noret_decl(f_11233)
static void C_fcall f_11233(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11284)
static void C_fcall f_11284(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11328)
static void C_ccall f_11328(C_word c,C_word *av) C_noret;
C_noret_decl(f_11375)
static void C_ccall f_11375(C_word c,C_word *av) C_noret;
C_noret_decl(f_11403)
static void C_ccall f_11403(C_word c,C_word *av) C_noret;
C_noret_decl(f_11407)
static void C_ccall f_11407(C_word c,C_word *av) C_noret;
C_noret_decl(f_11411)
static void C_ccall f_11411(C_word c,C_word *av) C_noret;
C_noret_decl(f_11430)
static void C_ccall f_11430(C_word c,C_word *av) C_noret;
C_noret_decl(f_11442)
static void C_ccall f_11442(C_word c,C_word *av) C_noret;
C_noret_decl(f_11444)
static void C_fcall f_11444(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11486)
static void C_fcall f_11486(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11496)
static void C_ccall f_11496(C_word c,C_word *av) C_noret;
C_noret_decl(f_11518)
static void C_ccall f_11518(C_word c,C_word *av) C_noret;
C_noret_decl(f_11545)
static void C_ccall f_11545(C_word c,C_word *av) C_noret;
C_noret_decl(f_11565)
static void C_fcall f_11565(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11618)
static void C_ccall f_11618(C_word c,C_word *av) C_noret;
C_noret_decl(f_11665)
static void C_ccall f_11665(C_word c,C_word *av) C_noret;
C_noret_decl(f_11682)
static void C_ccall f_11682(C_word c,C_word *av) C_noret;
C_noret_decl(f_11688)
static void C_fcall f_11688(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11702)
static void C_ccall f_11702(C_word c,C_word *av) C_noret;
C_noret_decl(f_11706)
static void C_ccall f_11706(C_word c,C_word *av) C_noret;
C_noret_decl(f_11712)
static void C_ccall f_11712(C_word c,C_word *av) C_noret;
C_noret_decl(f_11750)
static void C_ccall f_11750(C_word c,C_word *av) C_noret;
C_noret_decl(f_11754)
static void C_ccall f_11754(C_word c,C_word *av) C_noret;
C_noret_decl(f_11757)
static void C_ccall f_11757(C_word c,C_word *av) C_noret;
C_noret_decl(f_11760)
static void C_ccall f_11760(C_word c,C_word *av) C_noret;
C_noret_decl(f_11795)
static void C_fcall f_11795(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11839)
static void C_ccall f_11839(C_word c,C_word *av) C_noret;
C_noret_decl(f_11841)
static void C_fcall f_11841(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11866)
static void C_ccall f_11866(C_word c,C_word *av) C_noret;
C_noret_decl(f_11881)
static void C_fcall f_11881(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11910)
static void C_ccall f_11910(C_word c,C_word *av) C_noret;
C_noret_decl(f_11912)
static void C_fcall f_11912(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11937)
static void C_ccall f_11937(C_word c,C_word *av) C_noret;
C_noret_decl(f_11946)
static void C_ccall f_11946(C_word c,C_word *av) C_noret;
C_noret_decl(f_11949)
static void C_fcall f_11949(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11955)
static void C_ccall f_11955(C_word c,C_word *av) C_noret;
C_noret_decl(f_12003)
static void C_ccall f_12003(C_word c,C_word *av) C_noret;
C_noret_decl(f_12006)
static void C_ccall f_12006(C_word c,C_word *av) C_noret;
C_noret_decl(f_12012)
static void C_ccall f_12012(C_word c,C_word *av) C_noret;
C_noret_decl(f_12020)
static void C_ccall f_12020(C_word c,C_word *av) C_noret;
C_noret_decl(f_12028)
static void C_fcall f_12028(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12038)
static void C_ccall f_12038(C_word c,C_word *av) C_noret;
C_noret_decl(f_12057)
static void C_ccall f_12057(C_word c,C_word *av) C_noret;
C_noret_decl(f_12061)
static void C_ccall f_12061(C_word c,C_word *av) C_noret;
C_noret_decl(f_12066)
static void C_ccall f_12066(C_word c,C_word *av) C_noret;
C_noret_decl(f_12072)
static void C_ccall f_12072(C_word c,C_word *av) C_noret;
C_noret_decl(f_12075)
static void C_ccall f_12075(C_word c,C_word *av) C_noret;
C_noret_decl(f_12080)
static void C_fcall f_12080(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12090)
static void C_ccall f_12090(C_word c,C_word *av) C_noret;
C_noret_decl(f_12105)
static void C_ccall f_12105(C_word c,C_word *av) C_noret;
C_noret_decl(f_12107)
static void C_ccall f_12107(C_word c,C_word *av) C_noret;
C_noret_decl(f_12114)
static void C_ccall f_12114(C_word c,C_word *av) C_noret;
C_noret_decl(f_12135)
static void C_fcall f_12135(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12169)
static void C_ccall f_12169(C_word c,C_word *av) C_noret;
C_noret_decl(f_12172)
static void C_fcall f_12172(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12197)
static void C_ccall f_12197(C_word c,C_word *av) C_noret;
C_noret_decl(f_12203)
static void C_ccall f_12203(C_word c,C_word *av) C_noret;
C_noret_decl(f_12229)
static void C_ccall f_12229(C_word c,C_word *av) C_noret;
C_noret_decl(f_12262)
static void C_ccall f_12262(C_word c,C_word *av) C_noret;
C_noret_decl(f_12264)
static void C_ccall f_12264(C_word c,C_word *av) C_noret;
C_noret_decl(f_12270)
static void C_ccall f_12270(C_word c,C_word *av) C_noret;
C_noret_decl(f_12276)
static void C_fcall f_12276(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12280)
static void C_ccall f_12280(C_word c,C_word *av) C_noret;
C_noret_decl(f_12303)
static void C_ccall f_12303(C_word c,C_word *av) C_noret;
C_noret_decl(f_12314)
static void C_ccall f_12314(C_word c,C_word *av) C_noret;
C_noret_decl(f_12320)
static void C_ccall f_12320(C_word c,C_word *av) C_noret;
C_noret_decl(f_12323)
static void C_fcall f_12323(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12331)
static C_word C_fcall f_12331(C_word t0,C_word t1);
C_noret_decl(f_12357)
static void C_fcall f_12357(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12379)
static void C_ccall f_12379(C_word c,C_word *av) C_noret;
C_noret_decl(f_12404)
static void C_fcall f_12404(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12426)
static void C_ccall f_12426(C_word c,C_word *av) C_noret;
C_noret_decl(f_12444)
static void C_fcall f_12444(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12475)
static void C_ccall f_12475(C_word c,C_word *av) C_noret;
C_noret_decl(f_12527)
static void C_ccall f_12527(C_word c,C_word *av) C_noret;
C_noret_decl(f_12533)
static void C_ccall f_12533(C_word c,C_word *av) C_noret;
C_noret_decl(f_12553)
static void C_ccall f_12553(C_word c,C_word *av) C_noret;
C_noret_decl(f_12559)
static void C_ccall f_12559(C_word c,C_word *av) C_noret;
C_noret_decl(f_12585)
static void C_fcall f_12585(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12599)
static void C_fcall f_12599(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12607)
static void C_ccall f_12607(C_word c,C_word *av) C_noret;
C_noret_decl(f_12662)
static void C_ccall f_12662(C_word c,C_word *av) C_noret;
C_noret_decl(f_12691)
static void C_ccall f_12691(C_word c,C_word *av) C_noret;
C_noret_decl(f_12788)
static void C_ccall f_12788(C_word c,C_word *av) C_noret;
C_noret_decl(f_12794)
static void C_ccall f_12794(C_word c,C_word *av) C_noret;
C_noret_decl(f_12801)
static void C_fcall f_12801(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12804)
static void C_ccall f_12804(C_word c,C_word *av) C_noret;
C_noret_decl(f_12827)
static void C_ccall f_12827(C_word c,C_word *av) C_noret;
C_noret_decl(f_12829)
static void C_ccall f_12829(C_word c,C_word *av) C_noret;
C_noret_decl(f_12835)
static void C_ccall f_12835(C_word c,C_word *av) C_noret;
C_noret_decl(f_12842)
static void C_fcall f_12842(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12845)
static void C_ccall f_12845(C_word c,C_word *av) C_noret;
C_noret_decl(f_12864)
static void C_ccall f_12864(C_word c,C_word *av) C_noret;
C_noret_decl(f_12866)
static void C_ccall f_12866(C_word c,C_word *av) C_noret;
C_noret_decl(f_12872)
static void C_ccall f_12872(C_word c,C_word *av) C_noret;
C_noret_decl(f_12885)
static void C_ccall f_12885(C_word c,C_word *av) C_noret;
C_noret_decl(f_12913)
static void C_ccall f_12913(C_word c,C_word *av) C_noret;
C_noret_decl(f_12915)
static void C_ccall f_12915(C_word c,C_word *av) C_noret;
C_noret_decl(f_12936)
static void C_ccall f_12936(C_word c,C_word *av) C_noret;
C_noret_decl(f_12943)
static void C_ccall f_12943(C_word c,C_word *av) C_noret;
C_noret_decl(f_12949)
static void C_ccall f_12949(C_word c,C_word *av) C_noret;
C_noret_decl(f_12955)
static void C_ccall f_12955(C_word c,C_word *av) C_noret;
C_noret_decl(f_12964)
static void C_ccall f_12964(C_word c,C_word *av) C_noret;
C_noret_decl(f_12973)
static void C_ccall f_12973(C_word c,C_word *av) C_noret;
C_noret_decl(f_12982)
static void C_ccall f_12982(C_word c,C_word *av) C_noret;
C_noret_decl(f_12991)
static void C_ccall f_12991(C_word c,C_word *av) C_noret;
C_noret_decl(f_13000)
static void C_ccall f_13000(C_word c,C_word *av) C_noret;
C_noret_decl(f_13026)
static void C_ccall f_13026(C_word c,C_word *av) C_noret;
C_noret_decl(f_13029)
static void C_ccall f_13029(C_word c,C_word *av) C_noret;
C_noret_decl(f_13040)
static void C_ccall f_13040(C_word c,C_word *av) C_noret;
C_noret_decl(f_13042)
static void C_ccall f_13042(C_word c,C_word *av) C_noret;
C_noret_decl(f_13096)
static void C_ccall f_13096(C_word c,C_word *av) C_noret;
C_noret_decl(f_13102)
static void C_ccall f_13102(C_word c,C_word *av) C_noret;
C_noret_decl(f_13108)
static void C_ccall f_13108(C_word c,C_word *av) C_noret;
C_noret_decl(f_13114)
static void C_fcall f_13114(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_13139)
static void C_fcall f_13139(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13154)
static void C_fcall f_13154(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13172)
static void C_ccall f_13172(C_word c,C_word *av) C_noret;
C_noret_decl(f_13222)
static void C_ccall f_13222(C_word c,C_word *av) C_noret;
C_noret_decl(f_13237)
static void C_fcall f_13237(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13277)
static void C_fcall f_13277(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13280)
static void C_ccall f_13280(C_word c,C_word *av) C_noret;
C_noret_decl(f_13295)
static void C_fcall f_13295(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13319)
static void C_fcall f_13319(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13345)
static void C_fcall f_13345(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13351)
static void C_ccall f_13351(C_word c,C_word *av) C_noret;
C_noret_decl(f_13357)
static void C_ccall f_13357(C_word c,C_word *av) C_noret;
C_noret_decl(f_13360)
static void C_ccall f_13360(C_word c,C_word *av) C_noret;
C_noret_decl(f_13363)
static void C_ccall f_13363(C_word c,C_word *av) C_noret;
C_noret_decl(f_13366)
static void C_ccall f_13366(C_word c,C_word *av) C_noret;
C_noret_decl(f_13388)
static void C_fcall f_13388(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13394)
static void C_ccall f_13394(C_word c,C_word *av) C_noret;
C_noret_decl(f_13400)
static void C_ccall f_13400(C_word c,C_word *av) C_noret;
C_noret_decl(f_13403)
static void C_ccall f_13403(C_word c,C_word *av) C_noret;
C_noret_decl(f_13406)
static void C_ccall f_13406(C_word c,C_word *av) C_noret;
C_noret_decl(f_13409)
static void C_ccall f_13409(C_word c,C_word *av) C_noret;
C_noret_decl(f_13432)
static void C_fcall f_13432(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13435)
static void C_ccall f_13435(C_word c,C_word *av) C_noret;
C_noret_decl(f_13476)
static void C_fcall f_13476(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13479)
static void C_ccall f_13479(C_word c,C_word *av) C_noret;
C_noret_decl(f_13494)
static void C_fcall f_13494(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13521)
static void C_fcall f_13521(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13564)
static void C_ccall f_13564(C_word c,C_word *av) C_noret;
C_noret_decl(f_13568)
static void C_fcall f_13568(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_13595)
static void C_fcall f_13595(C_word t0,C_word t1) C_noret;
C_noret_decl(f_13598)
static void C_ccall f_13598(C_word c,C_word *av) C_noret;
C_noret_decl(f_13633)
static void C_ccall f_13633(C_word c,C_word *av) C_noret;
C_noret_decl(f_13669)
static void C_ccall f_13669(C_word c,C_word *av) C_noret;
C_noret_decl(f_14172)
static void C_ccall f_14172(C_word c,C_word *av) C_noret;
C_noret_decl(f_14178)
static void C_fcall f_14178(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14188)
static void C_ccall f_14188(C_word c,C_word *av) C_noret;
C_noret_decl(f_14199)
static void C_fcall f_14199(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14209)
static void C_ccall f_14209(C_word c,C_word *av) C_noret;
C_noret_decl(f_14220)
static void C_ccall f_14220(C_word c,C_word *av) C_noret;
C_noret_decl(f_14224)
static void C_ccall f_14224(C_word c,C_word *av) C_noret;
C_noret_decl(f_14235)
static void C_ccall f_14235(C_word c,C_word *av) C_noret;
C_noret_decl(f_14239)
static void C_ccall f_14239(C_word c,C_word *av) C_noret;
C_noret_decl(f_14250)
static void C_ccall f_14250(C_word c,C_word *av) C_noret;
C_noret_decl(f_14256)
static void C_ccall f_14256(C_word c,C_word *av) C_noret;
C_noret_decl(f_14260)
static void C_ccall f_14260(C_word c,C_word *av) C_noret;
C_noret_decl(f_14264)
static void C_fcall f_14264(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14283)
static void C_ccall f_14283(C_word c,C_word *av) C_noret;
C_noret_decl(f_14289)
static void C_ccall f_14289(C_word c,C_word *av) C_noret;
C_noret_decl(f_14292)
static void C_fcall f_14292(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14301)
static void C_ccall f_14301(C_word c,C_word *av) C_noret;
C_noret_decl(f_14311)
static void C_fcall f_14311(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14320)
static void C_fcall f_14320(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14332)
static void C_fcall f_14332(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14344)
static void C_fcall f_14344(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14356)
static void C_fcall f_14356(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14362)
static void C_ccall f_14362(C_word c,C_word *av) C_noret;
C_noret_decl(f_14366)
static void C_fcall f_14366(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14393)
static void C_fcall f_14393(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14758)
static void C_ccall f_14758(C_word c,C_word *av) C_noret;
C_noret_decl(f_14764)
static void C_ccall f_14764(C_word c,C_word *av) C_noret;
C_noret_decl(f_14776)
static void C_ccall f_14776(C_word c,C_word *av) C_noret;
C_noret_decl(f_14786)
static void C_fcall f_14786(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14798)
static void C_fcall f_14798(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14804)
static void C_ccall f_14804(C_word c,C_word *av) C_noret;
C_noret_decl(f_14808)
static void C_fcall f_14808(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14835)
static void C_fcall f_14835(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15208)
static void C_ccall f_15208(C_word c,C_word *av) C_noret;
C_noret_decl(f_15214)
static void C_ccall f_15214(C_word c,C_word *av) C_noret;
C_noret_decl(f_15218)
static void C_ccall f_15218(C_word c,C_word *av) C_noret;
C_noret_decl(f_15334)
static void C_fcall f_15334(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15362)
static void C_ccall f_15362(C_word c,C_word *av) C_noret;
C_noret_decl(f_15482)
static void C_ccall f_15482(C_word c,C_word *av) C_noret;
C_noret_decl(f_15489)
static void C_ccall f_15489(C_word c,C_word *av) C_noret;
C_noret_decl(f_15492)
static void C_ccall f_15492(C_word c,C_word *av) C_noret;
C_noret_decl(f_15495)
static void C_ccall f_15495(C_word c,C_word *av) C_noret;
C_noret_decl(f_15519)
static void C_fcall f_15519(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15594)
static void C_fcall f_15594(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15681)
static void C_fcall f_15681(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15714)
static void C_fcall f_15714(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15732)
static void C_fcall f_15732(C_word t0,C_word t1) C_noret;
C_noret_decl(f_15754)
static void C_fcall f_15754(C_word t0,C_word t1) C_noret;
C_noret_decl(f_16136)
static void C_ccall f_16136(C_word c,C_word *av) C_noret;
C_noret_decl(f_16140)
static void C_ccall f_16140(C_word c,C_word *av) C_noret;
C_noret_decl(f_16142)
static void C_fcall f_16142(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_16174)
static void C_fcall f_16174(C_word t0,C_word t1) C_noret;
C_noret_decl(f_16182)
static void C_fcall f_16182(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_16192)
static void C_ccall f_16192(C_word c,C_word *av) C_noret;
C_noret_decl(f_16238)
static void C_fcall f_16238(C_word t0,C_word t1) C_noret;
C_noret_decl(f_16246)
static void C_fcall f_16246(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_16256)
static void C_ccall f_16256(C_word c,C_word *av) C_noret;
C_noret_decl(f_16291)
static void C_ccall f_16291(C_word c,C_word *av) C_noret;
C_noret_decl(f_16294)
static void C_fcall f_16294(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_16328)
static void C_fcall f_16328(C_word t0,C_word t1) C_noret;
C_noret_decl(f_16347)
static void C_ccall f_16347(C_word c,C_word *av) C_noret;
C_noret_decl(f_16353)
static void C_ccall f_16353(C_word c,C_word *av) C_noret;
C_noret_decl(f_16357)
static void C_ccall f_16357(C_word c,C_word *av) C_noret;
C_noret_decl(f_16383)
static void C_ccall f_16383(C_word c,C_word *av) C_noret;
C_noret_decl(f_16392)
static void C_ccall f_16392(C_word c,C_word *av) C_noret;
C_noret_decl(f_16403)
static void C_ccall f_16403(C_word c,C_word *av) C_noret;
C_noret_decl(f_16422)
static void C_ccall f_16422(C_word c,C_word *av) C_noret;
C_noret_decl(f_16434)
static void C_ccall f_16434(C_word c,C_word *av) C_noret;
C_noret_decl(f_16478)
static void C_fcall f_16478(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_16480)
static void C_fcall f_16480(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_16492)
static void C_fcall f_16492(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_16502)
static void C_ccall f_16502(C_word c,C_word *av) C_noret;
C_noret_decl(f_16516)
static void C_ccall f_16516(C_word c,C_word *av) C_noret;
C_noret_decl(f_16522)
static void C_ccall f_16522(C_word c,C_word *av) C_noret;
C_noret_decl(f_16528)
static void C_ccall f_16528(C_word c,C_word *av) C_noret;
C_noret_decl(f_16534)
static void C_ccall f_16534(C_word c,C_word *av) C_noret;
C_noret_decl(f_16543)
static void C_ccall f_16543(C_word c,C_word *av) C_noret;
C_noret_decl(f_16551)
static void C_ccall f_16551(C_word c,C_word *av) C_noret;
C_noret_decl(f_16557)
static void C_ccall f_16557(C_word c,C_word *av) C_noret;
C_noret_decl(f_16560)
static void C_ccall f_16560(C_word c,C_word *av) C_noret;
C_noret_decl(f_16563)
static void C_ccall f_16563(C_word c,C_word *av) C_noret;
C_noret_decl(f_16566)
static void C_ccall f_16566(C_word c,C_word *av) C_noret;
C_noret_decl(f_16569)
static void C_ccall f_16569(C_word c,C_word *av) C_noret;
C_noret_decl(f_16574)
static void C_ccall f_16574(C_word c,C_word *av) C_noret;
C_noret_decl(f_16578)
static void C_ccall f_16578(C_word c,C_word *av) C_noret;
C_noret_decl(f_16590)
static void C_ccall f_16590(C_word c,C_word *av) C_noret;
C_noret_decl(f_16595)
static void C_ccall f_16595(C_word c,C_word *av) C_noret;
C_noret_decl(f_16597)
static void C_ccall f_16597(C_word c,C_word *av) C_noret;
C_noret_decl(f_16603)
static void C_ccall f_16603(C_word c,C_word *av) C_noret;
C_noret_decl(f_16610)
static void C_ccall f_16610(C_word c,C_word *av) C_noret;
C_noret_decl(f_16613)
static void C_fcall f_16613(C_word t0,C_word t1) C_noret;
C_noret_decl(f_16617)
static void C_ccall f_16617(C_word c,C_word *av) C_noret;
C_noret_decl(f_16623)
static void C_ccall f_16623(C_word c,C_word *av) C_noret;
C_noret_decl(f_16629)
static void C_ccall f_16629(C_word c,C_word *av) C_noret;
C_noret_decl(f_16656)
static void C_ccall f_16656(C_word c,C_word *av) C_noret;
C_noret_decl(f_16658)
static void C_fcall f_16658(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_16672)
static void C_ccall f_16672(C_word c,C_word *av) C_noret;
C_noret_decl(f_16682)
static void C_ccall f_16682(C_word c,C_word *av) C_noret;
C_noret_decl(f_16695)
static void C_ccall f_16695(C_word c,C_word *av) C_noret;
C_noret_decl(f_16710)
static void C_ccall f_16710(C_word c,C_word *av) C_noret;
C_noret_decl(f_16714)
static void C_ccall f_16714(C_word c,C_word *av) C_noret;
C_noret_decl(f_16721)
static void C_ccall f_16721(C_word c,C_word *av) C_noret;
C_noret_decl(f_16725)
static void C_ccall f_16725(C_word c,C_word *av) C_noret;
C_noret_decl(f_16730)
static void C_ccall f_16730(C_word c,C_word *av) C_noret;
C_noret_decl(f_16734)
static void C_ccall f_16734(C_word c,C_word *av) C_noret;
C_noret_decl(f_16742)
static void C_ccall f_16742(C_word c,C_word *av) C_noret;
C_noret_decl(f_16748)
static void C_ccall f_16748(C_word c,C_word *av) C_noret;
C_noret_decl(f_16755)
static void C_ccall f_16755(C_word c,C_word *av) C_noret;
C_noret_decl(f_16758)
static void C_ccall f_16758(C_word c,C_word *av) C_noret;
C_noret_decl(f_16761)
static void C_ccall f_16761(C_word c,C_word *av) C_noret;
C_noret_decl(f_16766)
static void C_ccall f_16766(C_word c,C_word *av) C_noret;
C_noret_decl(f_16786)
static void C_ccall f_16786(C_word c,C_word *av) C_noret;
C_noret_decl(f_16790)
static void C_ccall f_16790(C_word c,C_word *av) C_noret;
C_noret_decl(f_16801)
static void C_ccall f_16801(C_word c,C_word *av) C_noret;
C_noret_decl(f_16816)
static void C_ccall f_16816(C_word c,C_word *av) C_noret;
C_noret_decl(f_16828)
static void C_ccall f_16828(C_word c,C_word *av) C_noret;
C_noret_decl(f_16835)
static void C_ccall f_16835(C_word c,C_word *av) C_noret;
C_noret_decl(f_16865)
static void C_ccall f_16865(C_word c,C_word *av) C_noret;
C_noret_decl(f_16889)
static void C_ccall f_16889(C_word c,C_word *av) C_noret;
C_noret_decl(f_16904)
static void C_ccall f_16904(C_word c,C_word *av) C_noret;
C_noret_decl(f_16907)
static void C_ccall f_16907(C_word c,C_word *av) C_noret;
C_noret_decl(f_16913)
static void C_ccall f_16913(C_word c,C_word *av) C_noret;
C_noret_decl(f_16922)
static void C_ccall f_16922(C_word c,C_word *av) C_noret;
C_noret_decl(f_16925)
static void C_ccall f_16925(C_word c,C_word *av) C_noret;
C_noret_decl(f_16964)
static void C_ccall f_16964(C_word c,C_word *av) C_noret;
C_noret_decl(f_16970)
static void C_ccall f_16970(C_word c,C_word *av) C_noret;
C_noret_decl(f_16976)
static void C_ccall f_16976(C_word c,C_word *av) C_noret;
C_noret_decl(f_16979)
static void C_ccall f_16979(C_word c,C_word *av) C_noret;
C_noret_decl(f_16985)
static void C_ccall f_16985(C_word c,C_word *av) C_noret;
C_noret_decl(f_16991)
static void C_ccall f_16991(C_word c,C_word *av) C_noret;
C_noret_decl(f_16997)
static void C_ccall f_16997(C_word c,C_word *av) C_noret;
C_noret_decl(f_17003)
static void C_ccall f_17003(C_word c,C_word *av) C_noret;
C_noret_decl(f_17025)
static void C_ccall f_17025(C_word c,C_word *av) C_noret;
C_noret_decl(f_17027)
static void C_fcall f_17027(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17061)
static void C_fcall f_17061(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17095)
static void C_ccall f_17095(C_word c,C_word *av) C_noret;
C_noret_decl(f_17098)
static void C_ccall f_17098(C_word c,C_word *av) C_noret;
C_noret_decl(f_17126)
static void C_ccall f_17126(C_word c,C_word *av) C_noret;
C_noret_decl(f_17133)
static void C_ccall f_17133(C_word c,C_word *av) C_noret;
C_noret_decl(f_17148)
static void C_ccall f_17148(C_word c,C_word *av) C_noret;
C_noret_decl(f_17154)
static void C_ccall f_17154(C_word c,C_word *av) C_noret;
C_noret_decl(f_17157)
static void C_ccall f_17157(C_word c,C_word *av) C_noret;
C_noret_decl(f_17194)
static void C_ccall f_17194(C_word c,C_word *av) C_noret;
C_noret_decl(f_17209)
static void C_ccall f_17209(C_word c,C_word *av) C_noret;
C_noret_decl(f_17219)
static void C_ccall f_17219(C_word c,C_word *av) C_noret;
C_noret_decl(f_17222)
static void C_ccall f_17222(C_word c,C_word *av) C_noret;
C_noret_decl(f_17234)
static void C_ccall f_17234(C_word c,C_word *av) C_noret;
C_noret_decl(f_17240)
static void C_ccall f_17240(C_word c,C_word *av) C_noret;
C_noret_decl(f_17246)
static void C_ccall f_17246(C_word c,C_word *av) C_noret;
C_noret_decl(f_17249)
static void C_ccall f_17249(C_word c,C_word *av) C_noret;
C_noret_decl(f_17251)
static void C_fcall f_17251(C_word t0,C_word t1) C_noret;
C_noret_decl(f_17258)
static void C_fcall f_17258(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17264)
static void C_ccall f_17264(C_word c,C_word *av) C_noret;
C_noret_decl(f_17275)
static void C_ccall f_17275(C_word c,C_word *av) C_noret;
C_noret_decl(f_17323)
static void C_ccall f_17323(C_word c,C_word *av) C_noret;
C_noret_decl(f_17325)
static C_word C_fcall f_17325(C_word t0,C_word t1);
C_noret_decl(f_17331)
static void C_ccall f_17331(C_word c,C_word *av) C_noret;
C_noret_decl(f_17335)
static void C_ccall f_17335(C_word c,C_word *av) C_noret;
C_noret_decl(f_17340)
static void C_fcall f_17340(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_17368)
static void C_ccall f_17368(C_word c,C_word *av) C_noret;
C_noret_decl(f_17376)
static void C_ccall f_17376(C_word c,C_word *av) C_noret;
C_noret_decl(f_17379)
static void C_ccall f_17379(C_word c,C_word *av) C_noret;
C_noret_decl(f_17382)
static void C_ccall f_17382(C_word c,C_word *av) C_noret;
C_noret_decl(f_17385)
static void C_ccall f_17385(C_word c,C_word *av) C_noret;
C_noret_decl(f_17388)
static void C_ccall f_17388(C_word c,C_word *av) C_noret;
C_noret_decl(f_17391)
static void C_ccall f_17391(C_word c,C_word *av) C_noret;
C_noret_decl(f_17392)
static void C_fcall f_17392(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17402)
static void C_ccall f_17402(C_word c,C_word *av) C_noret;
C_noret_decl(f_17408)
static void C_ccall f_17408(C_word c,C_word *av) C_noret;
C_noret_decl(f_17420)
static void C_ccall f_17420(C_word c,C_word *av) C_noret;
C_noret_decl(f_17423)
static void C_ccall f_17423(C_word c,C_word *av) C_noret;
C_noret_decl(f_17426)
static void C_ccall f_17426(C_word c,C_word *av) C_noret;
C_noret_decl(f_17431)
static void C_fcall f_17431(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17444)
static void C_ccall f_17444(C_word c,C_word *av) C_noret;
C_noret_decl(f_17447)
static void C_ccall f_17447(C_word c,C_word *av) C_noret;
C_noret_decl(f_17464)
static void C_fcall f_17464(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17474)
static void C_ccall f_17474(C_word c,C_word *av) C_noret;
C_noret_decl(f_17487)
static void C_ccall f_17487(C_word c,C_word *av) C_noret;
C_noret_decl(f_17493)
static void C_ccall f_17493(C_word c,C_word *av) C_noret;
C_noret_decl(f_17503)
static void C_ccall f_17503(C_word c,C_word *av) C_noret;
C_noret_decl(f_17506)
static void C_ccall f_17506(C_word c,C_word *av) C_noret;
C_noret_decl(f_17522)
static void C_ccall f_17522(C_word c,C_word *av) C_noret;
C_noret_decl(f_17527)
static void C_fcall f_17527(C_word t0,C_word t1) C_noret;
C_noret_decl(f_17531)
static void C_ccall f_17531(C_word c,C_word *av) C_noret;
C_noret_decl(f_17548)
static void C_ccall f_17548(C_word c,C_word *av) C_noret;
C_noret_decl(f_17559)
static void C_ccall f_17559(C_word c,C_word *av) C_noret;
C_noret_decl(f_17571)
static void C_ccall f_17571(C_word c,C_word *av) C_noret;
C_noret_decl(f_17574)
static void C_ccall f_17574(C_word c,C_word *av) C_noret;
C_noret_decl(f_17582)
static void C_ccall f_17582(C_word c,C_word *av) C_noret;
C_noret_decl(f_17587)
static void C_ccall f_17587(C_word c,C_word *av) C_noret;
C_noret_decl(f_17600)
static void C_ccall f_17600(C_word c,C_word *av) C_noret;
C_noret_decl(f_17611)
static void C_ccall f_17611(C_word c,C_word *av) C_noret;
C_noret_decl(f_17633)
static void C_ccall f_17633(C_word c,C_word *av) C_noret;
C_noret_decl(f_17635)
static void C_ccall f_17635(C_word c,C_word *av) C_noret;
C_noret_decl(f_17655)
static void C_ccall f_17655(C_word c,C_word *av) C_noret;
C_noret_decl(f_17675)
static void C_ccall f_17675(C_word c,C_word *av) C_noret;
C_noret_decl(f_17683)
static void C_ccall f_17683(C_word c,C_word *av) C_noret;
C_noret_decl(f_17692)
static void C_ccall f_17692(C_word c,C_word *av) C_noret;
C_noret_decl(f_17697)
static void C_ccall f_17697(C_word c,C_word *av) C_noret;
C_noret_decl(f_17701)
static void C_ccall f_17701(C_word c,C_word *av) C_noret;
C_noret_decl(f_17722)
static void C_ccall f_17722(C_word c,C_word *av) C_noret;
C_noret_decl(f_17737)
static void C_ccall f_17737(C_word c,C_word *av) C_noret;
C_noret_decl(f_17743)
static void C_ccall f_17743(C_word c,C_word *av) C_noret;
C_noret_decl(f_17754)
static void C_ccall f_17754(C_word c,C_word *av) C_noret;
C_noret_decl(f_17765)
static void C_ccall f_17765(C_word c,C_word *av) C_noret;
C_noret_decl(f_17776)
static void C_ccall f_17776(C_word c,C_word *av) C_noret;
C_noret_decl(f_17780)
static void C_ccall f_17780(C_word c,C_word *av) C_noret;
C_noret_decl(f_17786)
static void C_ccall f_17786(C_word c,C_word *av) C_noret;
C_noret_decl(f_17798)
static void C_ccall f_17798(C_word c,C_word *av) C_noret;
C_noret_decl(f_17802)
static void C_ccall f_17802(C_word c,C_word *av) C_noret;
C_noret_decl(f_17814)
static void C_ccall f_17814(C_word c,C_word *av) C_noret;
C_noret_decl(f_17822)
static void C_fcall f_17822(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_17832)
static void C_ccall f_17832(C_word c,C_word *av) C_noret;
C_noret_decl(f_17847)
static void C_ccall f_17847(C_word c,C_word *av) C_noret;
C_noret_decl(f_17853)
static void C_ccall f_17853(C_word c,C_word *av) C_noret;
C_noret_decl(f_17856)
static void C_ccall f_17856(C_word c,C_word *av) C_noret;
C_noret_decl(f_17859)
static void C_ccall f_17859(C_word c,C_word *av) C_noret;
C_noret_decl(f_17862)
static void C_ccall f_17862(C_word c,C_word *av) C_noret;
C_noret_decl(f_17865)
static void C_ccall f_17865(C_word c,C_word *av) C_noret;
C_noret_decl(f_17869)
static void C_ccall f_17869(C_word c,C_word *av) C_noret;
C_noret_decl(f_17871)
static void C_ccall f_17871(C_word c,C_word *av) C_noret;
C_noret_decl(f_17878)
static void C_ccall f_17878(C_word c,C_word *av) C_noret;
C_noret_decl(f_17885)
static void C_ccall f_17885(C_word c,C_word *av) C_noret;
C_noret_decl(f_17896)
static void C_ccall f_17896(C_word c,C_word *av) C_noret;
C_noret_decl(f_17900)
static void C_ccall f_17900(C_word c,C_word *av) C_noret;
C_noret_decl(f_17903)
static void C_ccall f_17903(C_word c,C_word *av) C_noret;
C_noret_decl(f_17908)
static void C_ccall f_17908(C_word c,C_word *av) C_noret;
C_noret_decl(f_17914)
static void C_ccall f_17914(C_word c,C_word *av) C_noret;
C_noret_decl(f_17921)
static void C_ccall f_17921(C_word c,C_word *av) C_noret;
C_noret_decl(f_17924)
static void C_ccall f_17924(C_word c,C_word *av) C_noret;
C_noret_decl(f_17927)
static void C_ccall f_17927(C_word c,C_word *av) C_noret;
C_noret_decl(f_17930)
static void C_ccall f_17930(C_word c,C_word *av) C_noret;
C_noret_decl(f_5275)
static void C_ccall f_5275(C_word c,C_word *av) C_noret;
C_noret_decl(f_5278)
static void C_ccall f_5278(C_word c,C_word *av) C_noret;
C_noret_decl(f_5281)
static void C_ccall f_5281(C_word c,C_word *av) C_noret;
C_noret_decl(f_5284)
static void C_ccall f_5284(C_word c,C_word *av) C_noret;
C_noret_decl(f_5287)
static void C_ccall f_5287(C_word c,C_word *av) C_noret;
C_noret_decl(f_5290)
static void C_ccall f_5290(C_word c,C_word *av) C_noret;
C_noret_decl(f_5293)
static void C_ccall f_5293(C_word c,C_word *av) C_noret;
C_noret_decl(f_5296)
static void C_ccall f_5296(C_word c,C_word *av) C_noret;
C_noret_decl(f_5299)
static void C_ccall f_5299(C_word c,C_word *av) C_noret;
C_noret_decl(f_5409)
static void C_fcall f_5409(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5427)
static void C_ccall f_5427(C_word c,C_word *av) C_noret;
C_noret_decl(f_5467)
static void C_fcall f_5467(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_5481)
static void C_ccall f_5481(C_word c,C_word *av) C_noret;
C_noret_decl(f_5670)
static void C_fcall f_5670(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5676)
static void C_fcall f_5676(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5698)
static void C_ccall f_5698(C_word c,C_word *av) C_noret;
C_noret_decl(f_5704)
static void C_fcall f_5704(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5710)
static void C_fcall f_5710(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5720)
static void C_ccall f_5720(C_word c,C_word *av) C_noret;
C_noret_decl(f_5734)
static void C_fcall f_5734(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5740)
static void C_fcall f_5740(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5754)
static void C_ccall f_5754(C_word c,C_word *av) C_noret;
C_noret_decl(f_5963)
static void C_fcall f_5963(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5971)
static void C_fcall f_5971(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_5979)
static C_word C_fcall f_5979(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_5997)
static void C_ccall f_5997(C_word c,C_word *av) C_noret;
C_noret_decl(f_6036)
static void C_fcall f_6036(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6070)
static void C_fcall f_6070(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6076)
static C_word C_fcall f_6076(C_word t0);
C_noret_decl(f_6129)
static void C_fcall f_6129(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6135)
static void C_fcall f_6135(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6318)
static void C_fcall f_6318(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6336)
static void C_ccall f_6336(C_word c,C_word *av) C_noret;
C_noret_decl(f_6431)
static void C_fcall f_6431(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6444)
static void C_ccall f_6444(C_word c,C_word *av) C_noret;
C_noret_decl(f_6582)
static void C_ccall f_6582(C_word c,C_word *av) C_noret;
C_noret_decl(f_6586)
static void C_ccall f_6586(C_word c,C_word *av) C_noret;
C_noret_decl(f_6600)
static void C_ccall f_6600(C_word c,C_word *av) C_noret;
C_noret_decl(f_6611)
static void C_ccall f_6611(C_word c,C_word *av) C_noret;
C_noret_decl(f_6614)
static void C_fcall f_6614(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6629)
static void C_ccall f_6629(C_word c,C_word *av) C_noret;
C_noret_decl(f_6635)
static void C_ccall f_6635(C_word c,C_word *av) C_noret;
C_noret_decl(f_6638)
static void C_fcall f_6638(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6644)
static void C_ccall f_6644(C_word c,C_word *av) C_noret;
C_noret_decl(f_6648)
static void C_ccall f_6648(C_word c,C_word *av) C_noret;
C_noret_decl(f_6651)
static void C_ccall f_6651(C_word c,C_word *av) C_noret;
C_noret_decl(f_6660)
static void C_ccall f_6660(C_word c,C_word *av) C_noret;
C_noret_decl(f_6668)
static void C_ccall f_6668(C_word c,C_word *av) C_noret;
C_noret_decl(f_6675)
static void C_ccall f_6675(C_word c,C_word *av) C_noret;
C_noret_decl(f_6680)
static void C_fcall f_6680(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6690)
static void C_ccall f_6690(C_word c,C_word *av) C_noret;
C_noret_decl(f_6703)
static void C_fcall f_6703(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6710)
static void C_ccall f_6710(C_word c,C_word *av) C_noret;
C_noret_decl(f_6713)
static void C_ccall f_6713(C_word c,C_word *av) C_noret;
C_noret_decl(f_6722)
static void C_ccall f_6722(C_word c,C_word *av) C_noret;
C_noret_decl(f_6725)
static void C_ccall f_6725(C_word c,C_word *av) C_noret;
C_noret_decl(f_6728)
static void C_ccall f_6728(C_word c,C_word *av) C_noret;
C_noret_decl(f_6731)
static void C_ccall f_6731(C_word c,C_word *av) C_noret;
C_noret_decl(f_6734)
static void C_ccall f_6734(C_word c,C_word *av) C_noret;
C_noret_decl(f_6737)
static void C_ccall f_6737(C_word c,C_word *av) C_noret;
C_noret_decl(f_6743)
static void C_ccall f_6743(C_word c,C_word *av) C_noret;
C_noret_decl(f_6746)
static void C_ccall f_6746(C_word c,C_word *av) C_noret;
C_noret_decl(f_6753)
static void C_ccall f_6753(C_word c,C_word *av) C_noret;
C_noret_decl(f_6755)
static void C_ccall f_6755(C_word c,C_word *av) C_noret;
C_noret_decl(f_6758)
static void C_fcall f_6758(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6760)
static void C_fcall f_6760(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6767)
static void C_ccall f_6767(C_word c,C_word *av) C_noret;
C_noret_decl(f_6770)
static void C_ccall f_6770(C_word c,C_word *av) C_noret;
C_noret_decl(f_6773)
static void C_ccall f_6773(C_word c,C_word *av) C_noret;
C_noret_decl(f_6787)
static void C_ccall f_6787(C_word c,C_word *av) C_noret;
C_noret_decl(f_6792)
static void C_fcall f_6792(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6802)
static void C_ccall f_6802(C_word c,C_word *av) C_noret;
C_noret_decl(f_6819)
static void C_ccall f_6819(C_word c,C_word *av) C_noret;
C_noret_decl(f_6822)
static void C_ccall f_6822(C_word c,C_word *av) C_noret;
C_noret_decl(f_6825)
static void C_ccall f_6825(C_word c,C_word *av) C_noret;
C_noret_decl(f_6828)
static void C_ccall f_6828(C_word c,C_word *av) C_noret;
C_noret_decl(f_6834)
static void C_ccall f_6834(C_word c,C_word *av) C_noret;
C_noret_decl(f_6843)
static void C_ccall f_6843(C_word c,C_word *av) C_noret;
C_noret_decl(f_6850)
static void C_ccall f_6850(C_word c,C_word *av) C_noret;
C_noret_decl(f_6852)
static void C_ccall f_6852(C_word c,C_word *av) C_noret;
C_noret_decl(f_6856)
static void C_ccall f_6856(C_word c,C_word *av) C_noret;
C_noret_decl(f_6859)
static void C_ccall f_6859(C_word c,C_word *av) C_noret;
C_noret_decl(f_6866)
static void C_ccall f_6866(C_word c,C_word *av) C_noret;
C_noret_decl(f_6868)
static void C_ccall f_6868(C_word c,C_word *av) C_noret;
C_noret_decl(f_6872)
static void C_fcall f_6872(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6875)
static void C_ccall f_6875(C_word c,C_word *av) C_noret;
C_noret_decl(f_6876)
static void C_fcall f_6876(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6886)
static void C_ccall f_6886(C_word c,C_word *av) C_noret;
C_noret_decl(f_6889)
static void C_ccall f_6889(C_word c,C_word *av) C_noret;
C_noret_decl(f_6894)
static void C_fcall f_6894(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6904)
static void C_ccall f_6904(C_word c,C_word *av) C_noret;
C_noret_decl(f_6921)
static void C_ccall f_6921(C_word c,C_word *av) C_noret;
C_noret_decl(f_6924)
static void C_ccall f_6924(C_word c,C_word *av) C_noret;
C_noret_decl(f_6927)
static void C_ccall f_6927(C_word c,C_word *av) C_noret;
C_noret_decl(f_6930)
static void C_ccall f_6930(C_word c,C_word *av) C_noret;
C_noret_decl(f_6933)
static void C_ccall f_6933(C_word c,C_word *av) C_noret;
C_noret_decl(f_6942)
static void C_ccall f_6942(C_word c,C_word *av) C_noret;
C_noret_decl(f_6945)
static void C_ccall f_6945(C_word c,C_word *av) C_noret;
C_noret_decl(f_6948)
static void C_ccall f_6948(C_word c,C_word *av) C_noret;
C_noret_decl(f_6965)
static void C_ccall f_6965(C_word c,C_word *av) C_noret;
C_noret_decl(f_7019)
static void C_ccall f_7019(C_word c,C_word *av) C_noret;
C_noret_decl(f_7025)
static C_word C_fcall f_7025(C_word t0,C_word t1);
C_noret_decl(f_7060)
static void C_ccall f_7060(C_word c,C_word *av) C_noret;
C_noret_decl(f_7066)
static void C_fcall f_7066(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7088)
static void C_ccall f_7088(C_word c,C_word *av) C_noret;
C_noret_decl(f_7097)
static void C_ccall f_7097(C_word c,C_word *av) C_noret;
C_noret_decl(f_7109)
static void C_ccall f_7109(C_word c,C_word *av) C_noret;
C_noret_decl(f_7113)
static void C_ccall f_7113(C_word c,C_word *av) C_noret;
C_noret_decl(f_7115)
static void C_fcall f_7115(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7137)
static void C_fcall f_7137(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7144)
static void C_fcall f_7144(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7148)
static void C_ccall f_7148(C_word c,C_word *av) C_noret;
C_noret_decl(f_7152)
static void C_ccall f_7152(C_word c,C_word *av) C_noret;
C_noret_decl(f_7158)
static void C_ccall f_7158(C_word c,C_word *av) C_noret;
C_noret_decl(f_7180)
static void C_ccall f_7180(C_word c,C_word *av) C_noret;
C_noret_decl(f_7196)
static void C_ccall f_7196(C_word c,C_word *av) C_noret;
C_noret_decl(f_7200)
static void C_ccall f_7200(C_word c,C_word *av) C_noret;
C_noret_decl(f_7221)
static void C_ccall f_7221(C_word c,C_word *av) C_noret;
C_noret_decl(f_7244)
static void C_ccall f_7244(C_word c,C_word *av) C_noret;
C_noret_decl(f_7246)
static void C_ccall f_7246(C_word c,C_word *av) C_noret;
C_noret_decl(f_7253)
static void C_ccall f_7253(C_word c,C_word *av) C_noret;
C_noret_decl(f_7260)
static void C_ccall f_7260(C_word c,C_word *av) C_noret;
C_noret_decl(f_7273)
static void C_ccall f_7273(C_word c,C_word *av) C_noret;
C_noret_decl(f_7304)
static void C_ccall f_7304(C_word c,C_word *av) C_noret;
C_noret_decl(f_7316)
static void C_ccall f_7316(C_word c,C_word *av) C_noret;
C_noret_decl(f_7330)
static void C_ccall f_7330(C_word c,C_word *av) C_noret;
C_noret_decl(f_7332)
static void C_fcall f_7332(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7358)
static void C_ccall f_7358(C_word c,C_word *av) C_noret;
C_noret_decl(f_7372)
static void C_fcall f_7372(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7378)
static void C_fcall f_7378(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7393)
static void C_ccall f_7393(C_word c,C_word *av) C_noret;
C_noret_decl(f_7409)
static void C_ccall f_7409(C_word c,C_word *av) C_noret;
C_noret_decl(f_7417)
static void C_ccall f_7417(C_word c,C_word *av) C_noret;
C_noret_decl(f_7421)
static void C_ccall f_7421(C_word c,C_word *av) C_noret;
C_noret_decl(f_7423)
static void C_ccall f_7423(C_word c,C_word *av) C_noret;
C_noret_decl(f_7434)
static void C_ccall f_7434(C_word c,C_word *av) C_noret;
C_noret_decl(f_7436)
static void C_fcall f_7436(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_7453)
static void C_ccall f_7453(C_word c,C_word *av) C_noret;
C_noret_decl(f_7467)
static void C_ccall f_7467(C_word c,C_word *av) C_noret;
C_noret_decl(f_7470)
static void C_ccall f_7470(C_word c,C_word *av) C_noret;
C_noret_decl(f_7510)
static void C_ccall f_7510(C_word c,C_word *av) C_noret;
C_noret_decl(f_7522)
static void C_ccall f_7522(C_word c,C_word *av) C_noret;
C_noret_decl(f_7538)
static void C_ccall f_7538(C_word c,C_word *av) C_noret;
C_noret_decl(f_7574)
static void C_ccall f_7574(C_word c,C_word *av) C_noret;
C_noret_decl(f_7578)
static void C_fcall f_7578(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7624)
static void C_ccall f_7624(C_word c,C_word *av) C_noret;
C_noret_decl(f_7626)
static void C_ccall f_7626(C_word c,C_word *av) C_noret;
C_noret_decl(f_7642)
static void C_ccall f_7642(C_word c,C_word *av) C_noret;
C_noret_decl(f_7648)
static void C_ccall f_7648(C_word c,C_word *av) C_noret;
C_noret_decl(f_7663)
static void C_ccall f_7663(C_word c,C_word *av) C_noret;
C_noret_decl(f_7680)
static void C_ccall f_7680(C_word c,C_word *av) C_noret;
C_noret_decl(f_7682)
static void C_ccall f_7682(C_word c,C_word *av) C_noret;
C_noret_decl(f_7688)
static void C_fcall f_7688(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7712)
static void C_fcall f_7712(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7728)
static void C_ccall f_7728(C_word c,C_word *av) C_noret;
C_noret_decl(f_7738)
static void C_ccall f_7738(C_word c,C_word *av) C_noret;
C_noret_decl(f_7743)
static void C_ccall f_7743(C_word c,C_word *av) C_noret;
C_noret_decl(f_7757)
static void C_ccall f_7757(C_word c,C_word *av) C_noret;
C_noret_decl(f_7760)
static void C_ccall f_7760(C_word c,C_word *av) C_noret;
C_noret_decl(f_7761)
static void C_ccall f_7761(C_word c,C_word *av) C_noret;
C_noret_decl(f_7765)
static void C_ccall f_7765(C_word c,C_word *av) C_noret;
C_noret_decl(f_7770)
static void C_ccall f_7770(C_word c,C_word *av) C_noret;
C_noret_decl(f_7776)
static void C_ccall f_7776(C_word c,C_word *av) C_noret;
C_noret_decl(f_7782)
static void C_ccall f_7782(C_word c,C_word *av) C_noret;
C_noret_decl(f_7790)
static void C_ccall f_7790(C_word c,C_word *av) C_noret;
C_noret_decl(f_7793)
static void C_ccall f_7793(C_word c,C_word *av) C_noret;
C_noret_decl(f_7801)
static void C_ccall f_7801(C_word c,C_word *av) C_noret;
C_noret_decl(f_7803)
static void C_fcall f_7803(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7807)
static void C_ccall f_7807(C_word c,C_word *av) C_noret;
C_noret_decl(f_7829)
static void C_ccall f_7829(C_word c,C_word *av) C_noret;
C_noret_decl(f_7835)
static void C_fcall f_7835(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7839)
static void C_ccall f_7839(C_word c,C_word *av) C_noret;
C_noret_decl(f_7856)
static void C_fcall f_7856(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7862)
static void C_ccall f_7862(C_word c,C_word *av) C_noret;
C_noret_decl(f_7873)
static void C_ccall f_7873(C_word c,C_word *av) C_noret;
C_noret_decl(f_7875)
static void C_ccall f_7875(C_word c,C_word *av) C_noret;
C_noret_decl(f_7878)
static void C_ccall f_7878(C_word c,C_word *av) C_noret;
C_noret_decl(f_7884)
static C_word C_fcall f_7884(C_word t0,C_word t1);
C_noret_decl(f_7923)
static void C_ccall f_7923(C_word c,C_word *av) C_noret;
C_noret_decl(f_7928)
static void C_ccall f_7928(C_word c,C_word *av) C_noret;
C_noret_decl(f_7932)
static void C_ccall f_7932(C_word c,C_word *av) C_noret;
C_noret_decl(f_7936)
static void C_ccall f_7936(C_word c,C_word *av) C_noret;
C_noret_decl(f_7987)
static void C_ccall f_7987(C_word c,C_word *av) C_noret;
C_noret_decl(f_8024)
static void C_ccall f_8024(C_word c,C_word *av) C_noret;
C_noret_decl(f_8026)
static void C_fcall f_8026(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8076)
static void C_ccall f_8076(C_word c,C_word *av) C_noret;
C_noret_decl(f_8080)
static void C_ccall f_8080(C_word c,C_word *av) C_noret;
C_noret_decl(f_8094)
static void C_ccall f_8094(C_word c,C_word *av) C_noret;
C_noret_decl(f_8098)
static void C_ccall f_8098(C_word c,C_word *av) C_noret;
C_noret_decl(f_8106)
static C_word C_fcall f_8106(C_word t0,C_word t1);
C_noret_decl(f_8112)
static void C_ccall f_8112(C_word c,C_word *av) C_noret;
C_noret_decl(f_8116)
static void C_ccall f_8116(C_word c,C_word *av) C_noret;
C_noret_decl(f_8158)
static void C_ccall f_8158(C_word c,C_word *av) C_noret;
C_noret_decl(f_8162)
static void C_ccall f_8162(C_word c,C_word *av) C_noret;
C_noret_decl(f_8210)
static void C_ccall f_8210(C_word c,C_word *av) C_noret;
C_noret_decl(f_8214)
static void C_ccall f_8214(C_word c,C_word *av) C_noret;
C_noret_decl(f_8220)
static void C_ccall f_8220(C_word c,C_word *av) C_noret;
C_noret_decl(f_8226)
static void C_ccall f_8226(C_word c,C_word *av) C_noret;
C_noret_decl(f_8232)
static void C_ccall f_8232(C_word c,C_word *av) C_noret;
C_noret_decl(f_8241)
static void C_ccall f_8241(C_word c,C_word *av) C_noret;
C_noret_decl(f_8250)
static void C_ccall f_8250(C_word c,C_word *av) C_noret;
C_noret_decl(f_8259)
static void C_ccall f_8259(C_word c,C_word *av) C_noret;
C_noret_decl(f_8268)
static void C_ccall f_8268(C_word c,C_word *av) C_noret;
C_noret_decl(f_8277)
static void C_ccall f_8277(C_word c,C_word *av) C_noret;
C_noret_decl(f_8287)
static void C_ccall f_8287(C_word c,C_word *av) C_noret;
C_noret_decl(f_8289)
static void C_ccall f_8289(C_word c,C_word *av) C_noret;
C_noret_decl(f_8295)
static void C_ccall f_8295(C_word c,C_word *av) C_noret;
C_noret_decl(f_8310)
static void C_ccall f_8310(C_word c,C_word *av) C_noret;
C_noret_decl(f_8325)
static void C_ccall f_8325(C_word c,C_word *av) C_noret;
C_noret_decl(f_8328)
static void C_fcall f_8328(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8395)
static void C_ccall f_8395(C_word c,C_word *av) C_noret;
C_noret_decl(f_8397)
static void C_fcall f_8397(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8422)
static void C_ccall f_8422(C_word c,C_word *av) C_noret;
C_noret_decl(f_8445)
static void C_ccall f_8445(C_word c,C_word *av) C_noret;
C_noret_decl(f_8448)
static void C_fcall f_8448(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8451)
static void C_ccall f_8451(C_word c,C_word *av) C_noret;
C_noret_decl(f_8458)
static void C_ccall f_8458(C_word c,C_word *av) C_noret;
C_noret_decl(f_8505)
static void C_ccall f_8505(C_word c,C_word *av) C_noret;
C_noret_decl(f_8509)
static void C_ccall f_8509(C_word c,C_word *av) C_noret;
C_noret_decl(f_8514)
static void C_fcall f_8514(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8531)
static void C_ccall f_8531(C_word c,C_word *av) C_noret;
C_noret_decl(f_8539)
static void C_ccall f_8539(C_word c,C_word *av) C_noret;
C_noret_decl(f_8541)
static void C_fcall f_8541(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8566)
static void C_ccall f_8566(C_word c,C_word *av) C_noret;
C_noret_decl(f_8602)
static void C_ccall f_8602(C_word c,C_word *av) C_noret;
C_noret_decl(f_8636)
static void C_ccall f_8636(C_word c,C_word *av) C_noret;
C_noret_decl(f_8667)
static void C_fcall f_8667(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_8690)
static void C_ccall f_8690(C_word c,C_word *av) C_noret;
C_noret_decl(f_8711)
static void C_ccall f_8711(C_word c,C_word *av) C_noret;
C_noret_decl(f_8733)
static void C_ccall f_8733(C_word c,C_word *av) C_noret;
C_noret_decl(f_8741)
static void C_ccall f_8741(C_word c,C_word *av) C_noret;
C_noret_decl(f_8745)
static void C_ccall f_8745(C_word c,C_word *av) C_noret;
C_noret_decl(f_8753)
static void C_ccall f_8753(C_word c,C_word *av) C_noret;
C_noret_decl(f_8774)
static void C_ccall f_8774(C_word c,C_word *av) C_noret;
C_noret_decl(f_8778)
static void C_ccall f_8778(C_word c,C_word *av) C_noret;
C_noret_decl(f_8790)
static void C_ccall f_8790(C_word c,C_word *av) C_noret;
C_noret_decl(f_8817)
static void C_fcall f_8817(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8829)
static void C_ccall f_8829(C_word c,C_word *av) C_noret;
C_noret_decl(f_8831)
static void C_fcall f_8831(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8856)
static void C_ccall f_8856(C_word c,C_word *av) C_noret;
C_noret_decl(f_8890)
static void C_fcall f_8890(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8916)
static void C_ccall f_8916(C_word c,C_word *av) C_noret;
C_noret_decl(f_8918)
static void C_fcall f_8918(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8943)
static void C_ccall f_8943(C_word c,C_word *av) C_noret;
C_noret_decl(f_9027)
static void C_ccall f_9027(C_word c,C_word *av) C_noret;
C_noret_decl(f_9029)
static void C_fcall f_9029(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9054)
static void C_ccall f_9054(C_word c,C_word *av) C_noret;
C_noret_decl(f_9094)
static void C_ccall f_9094(C_word c,C_word *av) C_noret;
C_noret_decl(f_9135)
static void C_fcall f_9135(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9164)
static void C_ccall f_9164(C_word c,C_word *av) C_noret;
C_noret_decl(f_9166)
static void C_fcall f_9166(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9191)
static void C_ccall f_9191(C_word c,C_word *av) C_noret;
C_noret_decl(f_9227)
static void C_ccall f_9227(C_word c,C_word *av) C_noret;
C_noret_decl(f_9229)
static void C_fcall f_9229(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9254)
static void C_ccall f_9254(C_word c,C_word *av) C_noret;
C_noret_decl(f_9266)
static void C_ccall f_9266(C_word c,C_word *av) C_noret;
C_noret_decl(f_9272)
static void C_ccall f_9272(C_word c,C_word *av) C_noret;
C_noret_decl(f_9295)
static void C_ccall f_9295(C_word c,C_word *av) C_noret;
C_noret_decl(f_9297)
static void C_fcall f_9297(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9322)
static void C_ccall f_9322(C_word c,C_word *av) C_noret;
C_noret_decl(f_9333)
static void C_fcall f_9333(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9337)
static void C_ccall f_9337(C_word c,C_word *av) C_noret;
C_noret_decl(f_9340)
static void C_ccall f_9340(C_word c,C_word *av) C_noret;
C_noret_decl(f_9347)
static void C_ccall f_9347(C_word c,C_word *av) C_noret;
C_noret_decl(f_9361)
static void C_ccall f_9361(C_word c,C_word *av) C_noret;
C_noret_decl(f_9467)
static void C_ccall f_9467(C_word c,C_word *av) C_noret;
C_noret_decl(f_9469)
static void C_fcall f_9469(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9494)
static void C_ccall f_9494(C_word c,C_word *av) C_noret;
C_noret_decl(f_9512)
static void C_ccall f_9512(C_word c,C_word *av) C_noret;
C_noret_decl(f_9515)
static void C_ccall f_9515(C_word c,C_word *av) C_noret;
C_noret_decl(f_9521)
static void C_ccall f_9521(C_word c,C_word *av) C_noret;
C_noret_decl(f_9527)
static void C_fcall f_9527(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9561)
static void C_fcall f_9561(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9574)
static void C_ccall f_9574(C_word c,C_word *av) C_noret;
C_noret_decl(f_9576)
static void C_fcall f_9576(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9601)
static void C_ccall f_9601(C_word c,C_word *av) C_noret;
C_noret_decl(f_9631)
static void C_ccall f_9631(C_word c,C_word *av) C_noret;
C_noret_decl(f_9633)
static void C_fcall f_9633(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9658)
static void C_ccall f_9658(C_word c,C_word *av) C_noret;
C_noret_decl(f_9731)
static void C_ccall f_9731(C_word c,C_word *av) C_noret;
C_noret_decl(f_9734)
static void C_ccall f_9734(C_word c,C_word *av) C_noret;
C_noret_decl(f_9743)
static void C_ccall f_9743(C_word c,C_word *av) C_noret;
C_noret_decl(f_9747)
static void C_ccall f_9747(C_word c,C_word *av) C_noret;
C_noret_decl(f_9751)
static void C_ccall f_9751(C_word c,C_word *av) C_noret;
C_noret_decl(f_9753)
static void C_fcall f_9753(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9801)
static void C_fcall f_9801(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9826)
static void C_ccall f_9826(C_word c,C_word *av) C_noret;
C_noret_decl(f_9854)
static void C_ccall f_9854(C_word c,C_word *av) C_noret;
C_noret_decl(f_9878)
static void C_ccall f_9878(C_word c,C_word *av) C_noret;
C_noret_decl(f_9912)
static void C_ccall f_9912(C_word c,C_word *av) C_noret;
C_noret_decl(f_9916)
static void C_ccall f_9916(C_word c,C_word *av) C_noret;
C_noret_decl(f_9926)
static void C_fcall f_9926(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9950)
static void C_ccall f_9950(C_word c,C_word *av) C_noret;
C_noret_decl(f_9965)
static void C_ccall f_9965(C_word c,C_word *av) C_noret;
C_noret_decl(f_9977)
static void C_ccall f_9977(C_word c,C_word *av) C_noret;
C_noret_decl(C_support_toplevel)
C_externexport void C_ccall C_support_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_10002)
static void C_ccall trf_10002(C_word c,C_word *av) C_noret;
static void C_ccall trf_10002(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10002(t0,t1,t2);}

C_noret_decl(trf_10059)
static void C_ccall trf_10059(C_word c,C_word *av) C_noret;
static void C_ccall trf_10059(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10059(t0,t1,t2);}

C_noret_decl(trf_10115)
static void C_ccall trf_10115(C_word c,C_word *av) C_noret;
static void C_ccall trf_10115(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_10115(t0,t1,t2,t3,t4);}

C_noret_decl(trf_10165)
static void C_ccall trf_10165(C_word c,C_word *av) C_noret;
static void C_ccall trf_10165(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10165(t0,t1);}

C_noret_decl(trf_10185)
static void C_ccall trf_10185(C_word c,C_word *av) C_noret;
static void C_ccall trf_10185(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10185(t0,t1,t2);}

C_noret_decl(trf_10242)
static void C_ccall trf_10242(C_word c,C_word *av) C_noret;
static void C_ccall trf_10242(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10242(t0,t1,t2);}

C_noret_decl(trf_10293)
static void C_ccall trf_10293(C_word c,C_word *av) C_noret;
static void C_ccall trf_10293(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10293(t0,t1,t2);}

C_noret_decl(trf_10397)
static void C_ccall trf_10397(C_word c,C_word *av) C_noret;
static void C_ccall trf_10397(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10397(t0,t1,t2);}

C_noret_decl(trf_10497)
static void C_ccall trf_10497(C_word c,C_word *av) C_noret;
static void C_ccall trf_10497(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10497(t0,t1,t2,t3);}

C_noret_decl(trf_10512)
static void C_ccall trf_10512(C_word c,C_word *av) C_noret;
static void C_ccall trf_10512(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10512(t0,t1,t2,t3);}

C_noret_decl(trf_10642)
static void C_ccall trf_10642(C_word c,C_word *av) C_noret;
static void C_ccall trf_10642(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10642(t0,t1,t2);}

C_noret_decl(trf_10666)
static void C_ccall trf_10666(C_word c,C_word *av) C_noret;
static void C_ccall trf_10666(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10666(t0,t1,t2);}

C_noret_decl(trf_10693)
static void C_ccall trf_10693(C_word c,C_word *av) C_noret;
static void C_ccall trf_10693(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10693(t0,t1,t2);}

C_noret_decl(trf_10739)
static void C_ccall trf_10739(C_word c,C_word *av) C_noret;
static void C_ccall trf_10739(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10739(t0,t1,t2);}

C_noret_decl(trf_10794)
static void C_ccall trf_10794(C_word c,C_word *av) C_noret;
static void C_ccall trf_10794(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10794(t0,t1,t2,t3);}

C_noret_decl(trf_10965)
static void C_ccall trf_10965(C_word c,C_word *av) C_noret;
static void C_ccall trf_10965(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10965(t0,t1,t2);}

C_noret_decl(trf_10998)
static void C_ccall trf_10998(C_word c,C_word *av) C_noret;
static void C_ccall trf_10998(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10998(t0,t1,t2);}

C_noret_decl(trf_11010)
static void C_ccall trf_11010(C_word c,C_word *av) C_noret;
static void C_ccall trf_11010(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11010(t0,t1,t2);}

C_noret_decl(trf_11077)
static void C_ccall trf_11077(C_word c,C_word *av) C_noret;
static void C_ccall trf_11077(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11077(t0,t1,t2,t3);}

C_noret_decl(trf_11125)
static void C_ccall trf_11125(C_word c,C_word *av) C_noret;
static void C_ccall trf_11125(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11125(t0,t1,t2);}

C_noret_decl(trf_11174)
static void C_ccall trf_11174(C_word c,C_word *av) C_noret;
static void C_ccall trf_11174(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11174(t0,t1,t2);}

C_noret_decl(trf_11186)
static void C_ccall trf_11186(C_word c,C_word *av) C_noret;
static void C_ccall trf_11186(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11186(t0,t1,t2);}

C_noret_decl(trf_11233)
static void C_ccall trf_11233(C_word c,C_word *av) C_noret;
static void C_ccall trf_11233(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11233(t0,t1,t2,t3);}

C_noret_decl(trf_11284)
static void C_ccall trf_11284(C_word c,C_word *av) C_noret;
static void C_ccall trf_11284(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11284(t0,t1,t2);}

C_noret_decl(trf_11444)
static void C_ccall trf_11444(C_word c,C_word *av) C_noret;
static void C_ccall trf_11444(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11444(t0,t1,t2,t3);}

C_noret_decl(trf_11486)
static void C_ccall trf_11486(C_word c,C_word *av) C_noret;
static void C_ccall trf_11486(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11486(t0,t1,t2);}

C_noret_decl(trf_11565)
static void C_ccall trf_11565(C_word c,C_word *av) C_noret;
static void C_ccall trf_11565(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11565(t0,t1,t2,t3);}

C_noret_decl(trf_11688)
static void C_ccall trf_11688(C_word c,C_word *av) C_noret;
static void C_ccall trf_11688(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11688(t0,t1,t2);}

C_noret_decl(trf_11795)
static void C_ccall trf_11795(C_word c,C_word *av) C_noret;
static void C_ccall trf_11795(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11795(t0,t1,t2);}

C_noret_decl(trf_11841)
static void C_ccall trf_11841(C_word c,C_word *av) C_noret;
static void C_ccall trf_11841(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11841(t0,t1,t2);}

C_noret_decl(trf_11881)
static void C_ccall trf_11881(C_word c,C_word *av) C_noret;
static void C_ccall trf_11881(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11881(t0,t1,t2);}

C_noret_decl(trf_11912)
static void C_ccall trf_11912(C_word c,C_word *av) C_noret;
static void C_ccall trf_11912(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11912(t0,t1,t2);}

C_noret_decl(trf_11949)
static void C_ccall trf_11949(C_word c,C_word *av) C_noret;
static void C_ccall trf_11949(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11949(t0,t1,t2);}

C_noret_decl(trf_12028)
static void C_ccall trf_12028(C_word c,C_word *av) C_noret;
static void C_ccall trf_12028(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12028(t0,t1,t2);}

C_noret_decl(trf_12080)
static void C_ccall trf_12080(C_word c,C_word *av) C_noret;
static void C_ccall trf_12080(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12080(t0,t1,t2);}

C_noret_decl(trf_12135)
static void C_ccall trf_12135(C_word c,C_word *av) C_noret;
static void C_ccall trf_12135(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12135(t0,t1);}

C_noret_decl(trf_12172)
static void C_ccall trf_12172(C_word c,C_word *av) C_noret;
static void C_ccall trf_12172(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12172(t0,t1);}

C_noret_decl(trf_12276)
static void C_ccall trf_12276(C_word c,C_word *av) C_noret;
static void C_ccall trf_12276(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12276(t0,t1);}

C_noret_decl(trf_12323)
static void C_ccall trf_12323(C_word c,C_word *av) C_noret;
static void C_ccall trf_12323(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12323(t0,t1,t2,t3);}

C_noret_decl(trf_12357)
static void C_ccall trf_12357(C_word c,C_word *av) C_noret;
static void C_ccall trf_12357(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12357(t0,t1,t2,t3);}

C_noret_decl(trf_12404)
static void C_ccall trf_12404(C_word c,C_word *av) C_noret;
static void C_ccall trf_12404(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12404(t0,t1,t2,t3);}

C_noret_decl(trf_12444)
static void C_ccall trf_12444(C_word c,C_word *av) C_noret;
static void C_ccall trf_12444(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12444(t0,t1,t2,t3);}

C_noret_decl(trf_12585)
static void C_ccall trf_12585(C_word c,C_word *av) C_noret;
static void C_ccall trf_12585(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12585(t0,t1);}

C_noret_decl(trf_12599)
static void C_ccall trf_12599(C_word c,C_word *av) C_noret;
static void C_ccall trf_12599(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12599(t0,t1,t2);}

C_noret_decl(trf_12801)
static void C_ccall trf_12801(C_word c,C_word *av) C_noret;
static void C_ccall trf_12801(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12801(t0,t1);}

C_noret_decl(trf_12842)
static void C_ccall trf_12842(C_word c,C_word *av) C_noret;
static void C_ccall trf_12842(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12842(t0,t1);}

C_noret_decl(trf_13114)
static void C_ccall trf_13114(C_word c,C_word *av) C_noret;
static void C_ccall trf_13114(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_13114(t0,t1,t2);}

C_noret_decl(trf_13139)
static void C_ccall trf_13139(C_word c,C_word *av) C_noret;
static void C_ccall trf_13139(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13139(t0,t1);}

C_noret_decl(trf_13154)
static void C_ccall trf_13154(C_word c,C_word *av) C_noret;
static void C_ccall trf_13154(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13154(t0,t1);}

C_noret_decl(trf_13237)
static void C_ccall trf_13237(C_word c,C_word *av) C_noret;
static void C_ccall trf_13237(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13237(t0,t1);}

C_noret_decl(trf_13277)
static void C_ccall trf_13277(C_word c,C_word *av) C_noret;
static void C_ccall trf_13277(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13277(t0,t1);}

C_noret_decl(trf_13295)
static void C_ccall trf_13295(C_word c,C_word *av) C_noret;
static void C_ccall trf_13295(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13295(t0,t1);}

C_noret_decl(trf_13319)
static void C_ccall trf_13319(C_word c,C_word *av) C_noret;
static void C_ccall trf_13319(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13319(t0,t1);}

C_noret_decl(trf_13345)
static void C_ccall trf_13345(C_word c,C_word *av) C_noret;
static void C_ccall trf_13345(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13345(t0,t1);}

C_noret_decl(trf_13388)
static void C_ccall trf_13388(C_word c,C_word *av) C_noret;
static void C_ccall trf_13388(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13388(t0,t1);}

C_noret_decl(trf_13432)
static void C_ccall trf_13432(C_word c,C_word *av) C_noret;
static void C_ccall trf_13432(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13432(t0,t1);}

C_noret_decl(trf_13476)
static void C_ccall trf_13476(C_word c,C_word *av) C_noret;
static void C_ccall trf_13476(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13476(t0,t1);}

C_noret_decl(trf_13494)
static void C_ccall trf_13494(C_word c,C_word *av) C_noret;
static void C_ccall trf_13494(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13494(t0,t1);}

C_noret_decl(trf_13521)
static void C_ccall trf_13521(C_word c,C_word *av) C_noret;
static void C_ccall trf_13521(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13521(t0,t1);}

C_noret_decl(trf_13568)
static void C_ccall trf_13568(C_word c,C_word *av) C_noret;
static void C_ccall trf_13568(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_13568(t0,t1,t2);}

C_noret_decl(trf_13595)
static void C_ccall trf_13595(C_word c,C_word *av) C_noret;
static void C_ccall trf_13595(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13595(t0,t1);}

C_noret_decl(trf_14178)
static void C_ccall trf_14178(C_word c,C_word *av) C_noret;
static void C_ccall trf_14178(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14178(t0,t1);}

C_noret_decl(trf_14199)
static void C_ccall trf_14199(C_word c,C_word *av) C_noret;
static void C_ccall trf_14199(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14199(t0,t1);}

C_noret_decl(trf_14264)
static void C_ccall trf_14264(C_word c,C_word *av) C_noret;
static void C_ccall trf_14264(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14264(t0,t1,t2);}

C_noret_decl(trf_14292)
static void C_ccall trf_14292(C_word c,C_word *av) C_noret;
static void C_ccall trf_14292(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14292(t0,t1);}

C_noret_decl(trf_14311)
static void C_ccall trf_14311(C_word c,C_word *av) C_noret;
static void C_ccall trf_14311(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14311(t0,t1);}

C_noret_decl(trf_14320)
static void C_ccall trf_14320(C_word c,C_word *av) C_noret;
static void C_ccall trf_14320(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14320(t0,t1);}

C_noret_decl(trf_14332)
static void C_ccall trf_14332(C_word c,C_word *av) C_noret;
static void C_ccall trf_14332(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14332(t0,t1);}

C_noret_decl(trf_14344)
static void C_ccall trf_14344(C_word c,C_word *av) C_noret;
static void C_ccall trf_14344(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14344(t0,t1);}

C_noret_decl(trf_14356)
static void C_ccall trf_14356(C_word c,C_word *av) C_noret;
static void C_ccall trf_14356(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14356(t0,t1);}

C_noret_decl(trf_14366)
static void C_ccall trf_14366(C_word c,C_word *av) C_noret;
static void C_ccall trf_14366(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14366(t0,t1,t2);}

C_noret_decl(trf_14393)
static void C_ccall trf_14393(C_word c,C_word *av) C_noret;
static void C_ccall trf_14393(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14393(t0,t1);}

C_noret_decl(trf_14786)
static void C_ccall trf_14786(C_word c,C_word *av) C_noret;
static void C_ccall trf_14786(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14786(t0,t1);}

C_noret_decl(trf_14798)
static void C_ccall trf_14798(C_word c,C_word *av) C_noret;
static void C_ccall trf_14798(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14798(t0,t1);}

C_noret_decl(trf_14808)
static void C_ccall trf_14808(C_word c,C_word *av) C_noret;
static void C_ccall trf_14808(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14808(t0,t1,t2);}

C_noret_decl(trf_14835)
static void C_ccall trf_14835(C_word c,C_word *av) C_noret;
static void C_ccall trf_14835(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14835(t0,t1);}

C_noret_decl(trf_15334)
static void C_ccall trf_15334(C_word c,C_word *av) C_noret;
static void C_ccall trf_15334(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15334(t0,t1);}

C_noret_decl(trf_15519)
static void C_ccall trf_15519(C_word c,C_word *av) C_noret;
static void C_ccall trf_15519(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15519(t0,t1);}

C_noret_decl(trf_15594)
static void C_ccall trf_15594(C_word c,C_word *av) C_noret;
static void C_ccall trf_15594(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15594(t0,t1);}

C_noret_decl(trf_15681)
static void C_ccall trf_15681(C_word c,C_word *av) C_noret;
static void C_ccall trf_15681(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15681(t0,t1);}

C_noret_decl(trf_15714)
static void C_ccall trf_15714(C_word c,C_word *av) C_noret;
static void C_ccall trf_15714(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15714(t0,t1);}

C_noret_decl(trf_15732)
static void C_ccall trf_15732(C_word c,C_word *av) C_noret;
static void C_ccall trf_15732(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15732(t0,t1);}

C_noret_decl(trf_15754)
static void C_ccall trf_15754(C_word c,C_word *av) C_noret;
static void C_ccall trf_15754(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_15754(t0,t1);}

C_noret_decl(trf_16142)
static void C_ccall trf_16142(C_word c,C_word *av) C_noret;
static void C_ccall trf_16142(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_16142(t0,t1,t2);}

C_noret_decl(trf_16174)
static void C_ccall trf_16174(C_word c,C_word *av) C_noret;
static void C_ccall trf_16174(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_16174(t0,t1);}

C_noret_decl(trf_16182)
static void C_ccall trf_16182(C_word c,C_word *av) C_noret;
static void C_ccall trf_16182(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_16182(t0,t1,t2);}

C_noret_decl(trf_16238)
static void C_ccall trf_16238(C_word c,C_word *av) C_noret;
static void C_ccall trf_16238(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_16238(t0,t1);}

C_noret_decl(trf_16246)
static void C_ccall trf_16246(C_word c,C_word *av) C_noret;
static void C_ccall trf_16246(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_16246(t0,t1,t2);}

C_noret_decl(trf_16294)
static void C_ccall trf_16294(C_word c,C_word *av) C_noret;
static void C_ccall trf_16294(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_16294(t0,t1,t2,t3);}

C_noret_decl(trf_16328)
static void C_ccall trf_16328(C_word c,C_word *av) C_noret;
static void C_ccall trf_16328(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_16328(t0,t1);}

C_noret_decl(trf_16478)
static void C_ccall trf_16478(C_word c,C_word *av) C_noret;
static void C_ccall trf_16478(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_16478(t0,t1,t2,t3);}

C_noret_decl(trf_16480)
static void C_ccall trf_16480(C_word c,C_word *av) C_noret;
static void C_ccall trf_16480(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_16480(t0,t1,t2);}

C_noret_decl(trf_16492)
static void C_ccall trf_16492(C_word c,C_word *av) C_noret;
static void C_ccall trf_16492(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_16492(t0,t1,t2);}

C_noret_decl(trf_16613)
static void C_ccall trf_16613(C_word c,C_word *av) C_noret;
static void C_ccall trf_16613(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_16613(t0,t1);}

C_noret_decl(trf_16658)
static void C_ccall trf_16658(C_word c,C_word *av) C_noret;
static void C_ccall trf_16658(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_16658(t0,t1,t2,t3,t4);}

C_noret_decl(trf_17027)
static void C_ccall trf_17027(C_word c,C_word *av) C_noret;
static void C_ccall trf_17027(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17027(t0,t1,t2);}

C_noret_decl(trf_17061)
static void C_ccall trf_17061(C_word c,C_word *av) C_noret;
static void C_ccall trf_17061(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17061(t0,t1,t2);}

C_noret_decl(trf_17251)
static void C_ccall trf_17251(C_word c,C_word *av) C_noret;
static void C_ccall trf_17251(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_17251(t0,t1);}

C_noret_decl(trf_17258)
static void C_ccall trf_17258(C_word c,C_word *av) C_noret;
static void C_ccall trf_17258(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17258(t0,t1,t2);}

C_noret_decl(trf_17340)
static void C_ccall trf_17340(C_word c,C_word *av) C_noret;
static void C_ccall trf_17340(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_17340(t0,t1,t2,t3);}

C_noret_decl(trf_17392)
static void C_ccall trf_17392(C_word c,C_word *av) C_noret;
static void C_ccall trf_17392(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17392(t0,t1,t2);}

C_noret_decl(trf_17431)
static void C_ccall trf_17431(C_word c,C_word *av) C_noret;
static void C_ccall trf_17431(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17431(t0,t1,t2);}

C_noret_decl(trf_17464)
static void C_ccall trf_17464(C_word c,C_word *av) C_noret;
static void C_ccall trf_17464(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17464(t0,t1,t2);}

C_noret_decl(trf_17527)
static void C_ccall trf_17527(C_word c,C_word *av) C_noret;
static void C_ccall trf_17527(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_17527(t0,t1);}

C_noret_decl(trf_17822)
static void C_ccall trf_17822(C_word c,C_word *av) C_noret;
static void C_ccall trf_17822(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_17822(t0,t1,t2);}

C_noret_decl(trf_5409)
static void C_ccall trf_5409(C_word c,C_word *av) C_noret;
static void C_ccall trf_5409(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5409(t0,t1,t2);}

C_noret_decl(trf_5467)
static void C_ccall trf_5467(C_word c,C_word *av) C_noret;
static void C_ccall trf_5467(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_5467(t0,t1,t2,t3,t4);}

C_noret_decl(trf_5670)
static void C_ccall trf_5670(C_word c,C_word *av) C_noret;
static void C_ccall trf_5670(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5670(t0,t1,t2);}

C_noret_decl(trf_5676)
static void C_ccall trf_5676(C_word c,C_word *av) C_noret;
static void C_ccall trf_5676(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5676(t0,t1,t2);}

C_noret_decl(trf_5704)
static void C_ccall trf_5704(C_word c,C_word *av) C_noret;
static void C_ccall trf_5704(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5704(t0,t1,t2);}

C_noret_decl(trf_5710)
static void C_ccall trf_5710(C_word c,C_word *av) C_noret;
static void C_ccall trf_5710(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5710(t0,t1,t2);}

C_noret_decl(trf_5734)
static void C_ccall trf_5734(C_word c,C_word *av) C_noret;
static void C_ccall trf_5734(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5734(t0,t1,t2);}

C_noret_decl(trf_5740)
static void C_ccall trf_5740(C_word c,C_word *av) C_noret;
static void C_ccall trf_5740(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5740(t0,t1,t2,t3);}

C_noret_decl(trf_5963)
static void C_ccall trf_5963(C_word c,C_word *av) C_noret;
static void C_ccall trf_5963(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5963(t0,t1,t2);}

C_noret_decl(trf_5971)
static void C_ccall trf_5971(C_word c,C_word *av) C_noret;
static void C_ccall trf_5971(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_5971(t0,t1,t2,t3);}

C_noret_decl(trf_6036)
static void C_ccall trf_6036(C_word c,C_word *av) C_noret;
static void C_ccall trf_6036(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6036(t0,t1,t2);}

C_noret_decl(trf_6070)
static void C_ccall trf_6070(C_word c,C_word *av) C_noret;
static void C_ccall trf_6070(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6070(t0,t1);}

C_noret_decl(trf_6129)
static void C_ccall trf_6129(C_word c,C_word *av) C_noret;
static void C_ccall trf_6129(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6129(t0,t1,t2);}

C_noret_decl(trf_6135)
static void C_ccall trf_6135(C_word c,C_word *av) C_noret;
static void C_ccall trf_6135(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6135(t0,t1,t2,t3);}

C_noret_decl(trf_6318)
static void C_ccall trf_6318(C_word c,C_word *av) C_noret;
static void C_ccall trf_6318(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6318(t0,t1,t2);}

C_noret_decl(trf_6431)
static void C_ccall trf_6431(C_word c,C_word *av) C_noret;
static void C_ccall trf_6431(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6431(t0,t1,t2);}

C_noret_decl(trf_6614)
static void C_ccall trf_6614(C_word c,C_word *av) C_noret;
static void C_ccall trf_6614(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6614(t0,t1,t2);}

C_noret_decl(trf_6638)
static void C_ccall trf_6638(C_word c,C_word *av) C_noret;
static void C_ccall trf_6638(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6638(t0,t1);}

C_noret_decl(trf_6680)
static void C_ccall trf_6680(C_word c,C_word *av) C_noret;
static void C_ccall trf_6680(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6680(t0,t1,t2);}

C_noret_decl(trf_6703)
static void C_ccall trf_6703(C_word c,C_word *av) C_noret;
static void C_ccall trf_6703(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6703(t0,t1,t2);}

C_noret_decl(trf_6758)
static void C_ccall trf_6758(C_word c,C_word *av) C_noret;
static void C_ccall trf_6758(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6758(t0,t1,t2);}

C_noret_decl(trf_6760)
static void C_ccall trf_6760(C_word c,C_word *av) C_noret;
static void C_ccall trf_6760(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6760(t0,t1,t2);}

C_noret_decl(trf_6792)
static void C_ccall trf_6792(C_word c,C_word *av) C_noret;
static void C_ccall trf_6792(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6792(t0,t1,t2);}

C_noret_decl(trf_6872)
static void C_ccall trf_6872(C_word c,C_word *av) C_noret;
static void C_ccall trf_6872(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6872(t0,t1);}

C_noret_decl(trf_6876)
static void C_ccall trf_6876(C_word c,C_word *av) C_noret;
static void C_ccall trf_6876(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6876(t0,t1,t2);}

C_noret_decl(trf_6894)
static void C_ccall trf_6894(C_word c,C_word *av) C_noret;
static void C_ccall trf_6894(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6894(t0,t1,t2);}

C_noret_decl(trf_7066)
static void C_ccall trf_7066(C_word c,C_word *av) C_noret;
static void C_ccall trf_7066(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7066(t0,t1,t2,t3);}

C_noret_decl(trf_7115)
static void C_ccall trf_7115(C_word c,C_word *av) C_noret;
static void C_ccall trf_7115(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7115(t0,t1,t2);}

C_noret_decl(trf_7137)
static void C_ccall trf_7137(C_word c,C_word *av) C_noret;
static void C_ccall trf_7137(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7137(t0,t1);}

C_noret_decl(trf_7144)
static void C_ccall trf_7144(C_word c,C_word *av) C_noret;
static void C_ccall trf_7144(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7144(t0,t1);}

C_noret_decl(trf_7332)
static void C_ccall trf_7332(C_word c,C_word *av) C_noret;
static void C_ccall trf_7332(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7332(t0,t1,t2);}

C_noret_decl(trf_7372)
static void C_ccall trf_7372(C_word c,C_word *av) C_noret;
static void C_ccall trf_7372(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7372(t0,t1,t2,t3);}

C_noret_decl(trf_7378)
static void C_ccall trf_7378(C_word c,C_word *av) C_noret;
static void C_ccall trf_7378(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7378(t0,t1,t2,t3);}

C_noret_decl(trf_7436)
static void C_ccall trf_7436(C_word c,C_word *av) C_noret;
static void C_ccall trf_7436(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_7436(t0,t1,t2,t3,t4);}

C_noret_decl(trf_7578)
static void C_ccall trf_7578(C_word c,C_word *av) C_noret;
static void C_ccall trf_7578(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7578(t0,t1);}

C_noret_decl(trf_7688)
static void C_ccall trf_7688(C_word c,C_word *av) C_noret;
static void C_ccall trf_7688(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7688(t0,t1,t2);}

C_noret_decl(trf_7712)
static void C_ccall trf_7712(C_word c,C_word *av) C_noret;
static void C_ccall trf_7712(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7712(t0,t1);}

C_noret_decl(trf_7803)
static void C_ccall trf_7803(C_word c,C_word *av) C_noret;
static void C_ccall trf_7803(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7803(t0,t1);}

C_noret_decl(trf_7835)
static void C_ccall trf_7835(C_word c,C_word *av) C_noret;
static void C_ccall trf_7835(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7835(t0,t1,t2);}

C_noret_decl(trf_7856)
static void C_ccall trf_7856(C_word c,C_word *av) C_noret;
static void C_ccall trf_7856(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7856(t0,t1,t2);}

C_noret_decl(trf_8026)
static void C_ccall trf_8026(C_word c,C_word *av) C_noret;
static void C_ccall trf_8026(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8026(t0,t1,t2);}

C_noret_decl(trf_8328)
static void C_ccall trf_8328(C_word c,C_word *av) C_noret;
static void C_ccall trf_8328(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8328(t0,t1,t2);}

C_noret_decl(trf_8397)
static void C_ccall trf_8397(C_word c,C_word *av) C_noret;
static void C_ccall trf_8397(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8397(t0,t1,t2);}

C_noret_decl(trf_8448)
static void C_ccall trf_8448(C_word c,C_word *av) C_noret;
static void C_ccall trf_8448(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8448(t0,t1);}

C_noret_decl(trf_8514)
static void C_ccall trf_8514(C_word c,C_word *av) C_noret;
static void C_ccall trf_8514(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8514(t0,t1,t2);}

C_noret_decl(trf_8541)
static void C_ccall trf_8541(C_word c,C_word *av) C_noret;
static void C_ccall trf_8541(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8541(t0,t1,t2);}

C_noret_decl(trf_8667)
static void C_ccall trf_8667(C_word c,C_word *av) C_noret;
static void C_ccall trf_8667(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_8667(t0,t1,t2,t3,t4);}

C_noret_decl(trf_8817)
static void C_ccall trf_8817(C_word c,C_word *av) C_noret;
static void C_ccall trf_8817(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8817(t0,t1);}

C_noret_decl(trf_8831)
static void C_ccall trf_8831(C_word c,C_word *av) C_noret;
static void C_ccall trf_8831(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8831(t0,t1,t2);}

C_noret_decl(trf_8890)
static void C_ccall trf_8890(C_word c,C_word *av) C_noret;
static void C_ccall trf_8890(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8890(t0,t1);}

C_noret_decl(trf_8918)
static void C_ccall trf_8918(C_word c,C_word *av) C_noret;
static void C_ccall trf_8918(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8918(t0,t1,t2);}

C_noret_decl(trf_9029)
static void C_ccall trf_9029(C_word c,C_word *av) C_noret;
static void C_ccall trf_9029(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9029(t0,t1,t2);}

C_noret_decl(trf_9135)
static void C_ccall trf_9135(C_word c,C_word *av) C_noret;
static void C_ccall trf_9135(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9135(t0,t1);}

C_noret_decl(trf_9166)
static void C_ccall trf_9166(C_word c,C_word *av) C_noret;
static void C_ccall trf_9166(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9166(t0,t1,t2);}

C_noret_decl(trf_9229)
static void C_ccall trf_9229(C_word c,C_word *av) C_noret;
static void C_ccall trf_9229(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9229(t0,t1,t2);}

C_noret_decl(trf_9297)
static void C_ccall trf_9297(C_word c,C_word *av) C_noret;
static void C_ccall trf_9297(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9297(t0,t1,t2);}

C_noret_decl(trf_9333)
static void C_ccall trf_9333(C_word c,C_word *av) C_noret;
static void C_ccall trf_9333(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9333(t0,t1);}

C_noret_decl(trf_9469)
static void C_ccall trf_9469(C_word c,C_word *av) C_noret;
static void C_ccall trf_9469(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9469(t0,t1,t2);}

C_noret_decl(trf_9527)
static void C_ccall trf_9527(C_word c,C_word *av) C_noret;
static void C_ccall trf_9527(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9527(t0,t1,t2);}

C_noret_decl(trf_9561)
static void C_ccall trf_9561(C_word c,C_word *av) C_noret;
static void C_ccall trf_9561(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9561(t0,t1);}

C_noret_decl(trf_9576)
static void C_ccall trf_9576(C_word c,C_word *av) C_noret;
static void C_ccall trf_9576(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9576(t0,t1,t2);}

C_noret_decl(trf_9633)
static void C_ccall trf_9633(C_word c,C_word *av) C_noret;
static void C_ccall trf_9633(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9633(t0,t1,t2);}

C_noret_decl(trf_9753)
static void C_ccall trf_9753(C_word c,C_word *av) C_noret;
static void C_ccall trf_9753(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9753(t0,t1,t2,t3);}

C_noret_decl(trf_9801)
static void C_ccall trf_9801(C_word c,C_word *av) C_noret;
static void C_ccall trf_9801(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9801(t0,t1,t2);}

C_noret_decl(trf_9926)
static void C_ccall trf_9926(C_word c,C_word *av) C_noret;
static void C_ccall trf_9926(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9926(t0,t1,t2,t3);}

/* f19574 in chicken.compiler.support#print-version in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f19574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f19574,c,av);}
/* support.scm:1754: chicken.base#print */
t2=*((C_word*)lf[233]+1);{
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

/* map-loop1868 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10002(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10002,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10027,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:607: g1874 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10025 in map-loop1868 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10027(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10027,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10002(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k10055 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10057,c,av);}
a=C_alloc(6);
/* support.scm:608: cons* */
f_5734(((C_word*)t0)[2],lf[185],C_a_i_list(&a,2,((C_word*)t0)[3],t1));}

/* map-loop1894 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10059(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10059,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10084,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:608: g1900 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10082 in map-loop1894 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10084,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10059(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* loop in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10115(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(36,0,2)))){
C_save_and_reclaim_args((void *)trf_10115,5,t0,t1,t2,t3,t4);}
a=C_alloc(36);
if(C_truep(C_i_zerop(t2))){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10127,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:613: scheme#reverse */
t6=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_s_a_i_minus(&a,2,t2,C_fix(1));
t6=C_i_cdr(t3);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10154,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t5,a[6]=t6,tmp=(C_word)a,a+=7,tmp);
/* support.scm:614: walk */
t8=((C_word*)((C_word*)t0)[2])[1];
f_9527(t8,t7,C_u_i_car(t3));}}

/* k10125 in loop in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10127,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10131,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:613: walk */
t3=((C_word*)((C_word*)t0)[3])[1];
f_9527(t3,t2,C_i_car(((C_word*)t0)[4]));}

/* k10129 in k10125 in loop in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10131(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_10131,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[194],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k10152 in loop in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10154(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_10154,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* support.scm:614: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_10115(t3,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],t2);}

/* k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10165(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,3)))){
C_save_and_reclaim_args((void *)trf_10165,2,t0,t1);}
a=C_alloc(21);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10172,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* support.scm:616: walk */
t3=((C_word*)((C_word*)t0)[6])[1];
f_9527(t3,t2,C_i_car(((C_word*)t0)[2]));}
else{
t2=C_eqp(((C_word*)t0)[4],lf[172]);
if(C_truep(t2)){
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10240,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10242,a[2]=t5,a[3]=t10,a[4]=((C_word*)t0)[6],a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_10242(t12,t8,((C_word*)t0)[2]);}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10281,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10291,a[2]=t3,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10293,a[2]=t6,a[3]=t11,a[4]=((C_word*)t0)[6],a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_10293(t13,t9,((C_word*)t0)[2]);}}}

/* k10170 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10172(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,3)))){
C_save_and_reclaim((void *)f_10172,c,av);}
a=C_alloc(19);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_u_i_cdr(((C_word*)t0)[2]);
t7=C_i_check_list_2(t6,lf[125]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10183,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10185,a[2]=t4,a[3]=t10,a[4]=((C_word*)t0)[6],a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_10185(t12,t8,t6);}

/* k10181 in k10170 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10183(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_10183,c,av);}
a=C_alloc(9);
/* support.scm:616: cons* */
f_5734(((C_word*)t0)[2],((C_word*)t0)[3],C_a_i_list(&a,3,((C_word*)t0)[4],((C_word*)t0)[5],t1));}

/* map-loop1937 in k10170 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10185(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10185,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10210,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:616: g1943 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10208 in map-loop1937 in k10170 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10210,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10185(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k10238 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10240(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10240,c,av);}
a=C_alloc(6);
/* support.scm:618: cons* */
f_5734(((C_word*)t0)[2],((C_word*)t0)[3],C_a_i_list(&a,2,((C_word*)t0)[4],t1));}

/* map-loop1963 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10242(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10242,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10267,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:618: g1969 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10265 in map-loop1963 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10267,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10242(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k10279 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_10281,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k10289 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10291,c,av);}
/* support.scm:619: scheme#append */
t2=*((C_word*)lf[58]+1);{
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

/* map-loop1989 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10293(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10293,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10318,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:619: g1995 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10316 in map-loop1989 in k10163 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10318,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10293(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* chicken.compiler.support#fold-boolean in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10391(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_10391,c,av);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10397,a[2]=t2,a[3]=t5,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_10397(t7,t1,t3);}

/* fold in chicken.compiler.support#fold-boolean in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10397(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_10397,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_cddr(t2);
if(C_truep(C_i_nullp(t3))){{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
C_apply(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10423,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:627: proc */
t5=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_car(t2);
av2[3]=C_i_cadr(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k10421 in fold in chicken.compiler.support#fold-boolean in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10423,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10427,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:628: fold */
t3=((C_word*)((C_word*)t0)[3])[1];
f_10397(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k10425 in k10421 in fold in chicken.compiler.support#fold-boolean in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_10427,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[167],lf[202],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6=av[6];
C_word t7=av[7];
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_10443,c,av);}
a=C_alloc(7);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10449,a[2]=t3,a[3]=t6,a[4]=t5,a[5]=t7,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* support.scm:632: ##sys#decompose-lambda-list */
t9=*((C_word*)lf[221]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t1;
av2[2]=t2;
av2[3]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}

/* a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10449(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_10449,c,av);}
a=C_alloc(13);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10455,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10461,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=((C_word*)t0)[4],a[6]=t2,a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
/* support.scm:635: ##sys#call-with-values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t5;
av2[3]=t6;
C_call_with_values(4,av2);}}

/* a10454 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10455(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_10455,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5467,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_5467(t5,t1,((C_word*)t0)[2],C_SCHEME_END_OF_LIST,((C_word*)t0)[3]);}

/* a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10461(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_10461,c,av);}
a=C_alloc(24);
t4=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_10465,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t2,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],tmp=(C_word)a,a+=12,tmp);
if(C_truep(((C_word*)t0)[5])){
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(((C_word*)t0)[6],lf[125]);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10739,a[2]=t7,a[3]=t11,a[4]=t8,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_10739(t13,t4,((C_word*)t0)[6]);}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[6];
f_10465(2,av2);}}}

/* k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10465(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_10465,c,av);}
a=C_alloc(27);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10468,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[8])){
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[9],lf[125]);
t8=C_i_check_list_2(t1,lf[125]);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10786,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[11],tmp=(C_word)a,a+=6,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11233,a[2]=t5,a[3]=t11,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t13=((C_word*)t11)[1];
f_11233(t13,t9,((C_word*)t0)[9],t1);}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[11];
f_10468(2,av2);}}}

/* k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10468(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_10468,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t7=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_10482,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10693,a[2]=t4,a[3]=t9,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_10693(t11,t7,((C_word*)t0)[2]);}

/* k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_10482,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10485,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10691,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[6],a[5]=t2,a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
/* support.scm:641: last */
f_6070(t3,((C_word*)t0)[5]);}

/* k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10485(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_10485,c,av);}
a=C_alloc(20);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10488,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(((C_word*)t0)[2])){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10642,a[2]=((C_word*)t0)[6],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10652,a[2]=t2,a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[2],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* support.scm:649: db-get-list */
t5=*((C_word*)lf[134]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[208];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_10488(2,av2);}}}

/* k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_10488,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_10495,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* support.scm:653: take */
f_5409(t2,((C_word*)t0)[5],((C_word*)t0)[10]);}

/* k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_10495(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_10495,c,av);}
a=C_alloc(11);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10497,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,tmp=(C_word)a,a+=9,tmp));
t5=((C_word*)t3)[1];
f_10497(t5,((C_word*)t0)[8],t1,((C_word*)t0)[9]);}

/* loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_fcall f_10497(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_10497,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t2))){
if(C_truep(((C_word*)t0)[2])){
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10512,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],a[7]=t5,tmp=(C_word)a,a+=8,tmp));
t7=((C_word*)t5)[1];
f_10512(t7,t1,((C_word*)t0)[4],((C_word*)t0)[7]);}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t4=C_i_car(t2);
t5=C_a_i_list1(&a,1,t4);
t6=C_i_car(t3);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10633,a[2]=t6,a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* support.scm:679: loop */
t9=t7;
t10=C_u_i_cdr(t2);
t11=C_u_i_cdr(t3);
t1=t9;
t2=t10;
t3=t11;
goto loop;}}

/* loop2 in loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_fcall f_10512(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_10512,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t3))){
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10577,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:662: db-get-list */
t5=*((C_word*)lf[134]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=lf[205];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t4=C_i_car(t3);
t5=C_a_i_list1(&a,1,t4);
t6=C_i_car(t2);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10601,a[2]=t6,a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* support.scm:675: loop2 */
t9=t7;
t10=C_u_i_cdr(t2);
t11=C_u_i_cdr(t3);
t1=t9;
t2=t10;
t3=t11;
goto loop;}}

/* k10543 in k10571 in k10575 in loop2 in loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in ... */
static void C_ccall f_10545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_10545,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[97],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10571 in k10575 in loop2 in loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_ccall f_10573(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,2)))){
C_save_and_reclaim((void *)f_10573,c,av);}
a=C_alloc(35);
t2=C_a_i_list1(&a,1,t1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10545,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
/* support.scm:667: qnode */
t4=*((C_word*)lf[150]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=C_i_length(((C_word*)t0)[4]);
t5=C_a_i_fixnum_times(&a,2,C_fix(3),t4);
t6=C_a_i_list2(&a,2,lf[204],t5);
t7=C_a_i_record4(&a,4,lf[136],lf[172],t6,((C_word*)t0)[4]);
t8=C_a_i_list2(&a,2,t7,((C_word*)t0)[2]);
t9=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[97],t2,t8);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* k10575 in loop2 in loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_10577(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_10577,c,av);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10573,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:665: last */
f_6070(t2,((C_word*)t0)[5]);}}

/* k10599 in loop2 in loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_10601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_10601,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[97],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10631 in loop in k10493 in k10486 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_10633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_10633,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[97],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* g2096 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10642(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,5)))){
C_save_and_reclaim_args((void *)trf_10642,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10646,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:647: db-put! */
t4=*((C_word*)lf[131]+1);{
C_word av2[6];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=lf[207];
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}

/* k10644 in g2096 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_10646(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_10646,c,av);}
/* support.scm:648: db-put! */
t2=*((C_word*)lf[131]+1);{
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
av2[4]=lf[206];
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k10650 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10652(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10652,c,av);}
a=C_alloc(11);
t2=C_i_check_list_2(t1,lf[44]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10658,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10666,a[2]=t5,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_10666(t7,t3,t1);}

/* k10656 in k10650 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_10658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_10658,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10661,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:650: db-put! */
t3=*((C_word*)lf[131]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[207];
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k10659 in k10656 in k10650 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_10661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_10661,c,av);}
/* support.scm:651: db-put! */
t2=*((C_word*)lf[131]+1);{
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
av2[4]=lf[208];
av2[5]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* for-each-loop2095 in k10650 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_10666(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10666,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10676,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:646: g2096 */
t4=((C_word*)t0)[3];
f_10642(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10674 in for-each-loop2095 in k10650 in k10483 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_10676(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10676,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10666(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_10691,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11284,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=t3,tmp=(C_word)a,a+=7,tmp));
/* support.scm:765: walk */
t5=((C_word*)t3)[1];
f_11284(t5,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* map-loop2068 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10693(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10693,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10718,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:640: chicken.base#gensym */
t4=*((C_word*)lf[98]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[215];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10716 in map-loop2068 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10718(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10718,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10693(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop2040 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10739(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10739,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10764,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:636: g2046 */
t4=*((C_word*)lf[98]+1);{
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

/* k10762 in map-loop2040 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10764(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10764,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10739(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_10786,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10794,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp));
/* support.scm:728: walk */
t5=((C_word*)t3)[1];
f_10794(t5,((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10794(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,0,5)))){
C_save_and_reclaim_args((void *)trf_10794,4,t0,t1,t2,t3);}
a=C_alloc(10);
t4=C_slot(t2,C_fix(3));
t5=C_slot(t2,C_fix(2));
t6=C_slot(t2,C_fix(1));
t7=C_eqp(t6,lf[86]);
if(C_truep(t7)){
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_a_i_record4(&a,4,lf[136],t6,t5,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_eqp(t6,lf[149]);
if(C_truep(t8)){
t9=C_i_car(t5);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10845,a[2]=t1,a[3]=t9,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10855,a[2]=((C_word*)t0)[2],a[3]=t10,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
/* support.scm:694: db-get */
t12=*((C_word*)lf[127]+1);{
C_word av2[5];
av2[0]=t12;
av2[1]=t11;
av2[2]=((C_word*)t0)[3];
av2[3]=t9;
av2[4]=lf[218];
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}
else{
t9=C_eqp(t6,lf[124]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10892,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t11=C_i_car(t5);
/* support.scm:684: chicken.base#alist-ref */
t12=*((C_word*)lf[216]+1);{
C_word av2[6];
av2[0]=t12;
av2[1]=t10;
av2[2]=t11;
av2[3]=t3;
av2[4]=*((C_word*)lf[217]+1);
av2[5]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(6,av2);}}
else{
t10=C_eqp(t6,lf[97]);
if(C_truep(t10)){
t11=C_i_car(t5);
t12=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10908,a[2]=t11,a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=t4,a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
/* support.scm:703: walk */
t15=t12;
t16=C_i_car(t4);
t17=t3;
t1=t15;
t2=t16;
t3=t17;
goto loop;}
else{
t11=C_eqp(t6,lf[118]);
if(C_truep(t11)){
t12=C_i_caddr(t5);
t13=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10960,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],a[5]=t4,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* support.scm:711: ##sys#decompose-lambda-list */
t14=*((C_word*)lf[221]+1);{
C_word av2[4];
av2[0]=t14;
av2[1]=t1;
av2[2]=t12;
av2[3]=t13;
((C_proc)(void*)(*((C_word*)t14+1)))(4,av2);}}
else{
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11169,a[2]=((C_word*)t0)[4],a[3]=t3,a[4]=t4,a[5]=t1,a[6]=t6,tmp=(C_word)a,a+=7,tmp);
/* support.scm:726: tree-copy */
t13=*((C_word*)lf[222]+1);{
C_word av2[3];
av2[0]=t13;
av2[1]=t12;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}}}}}}

/* k10843 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_10845,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10852,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:684: chicken.base#alist-ref */
t3=*((C_word*)lf[216]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=*((C_word*)lf[217]+1);
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k10850 in k10843 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10852,c,av);}
/* support.scm:696: varnode */
t2=*((C_word*)lf[148]+1);{
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

/* k10853 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10855,c,av);}
if(C_truep(t1)){
/* support.scm:695: cfk */
t2=((C_word*)t0)[2];{
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
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_10845(2,av2);}}}

/* k10882 in k10890 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10884(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_10884,c,av);}
a=C_alloc(8);
t2=C_a_i_list1(&a,1,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[124],((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10890 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10892(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_10892,c,av);}
a=C_alloc(7);
t2=C_a_i_list1(&a,1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10884,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:700: walk */
t4=((C_word*)((C_word*)t0)[3])[1];
f_10794(t4,t3,C_i_car(((C_word*)t0)[4]),((C_word*)t0)[5]);}

/* k10906 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_10908,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10911,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* support.scm:704: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
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

/* k10909 in k10906 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10911(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_10911,c,av);}
a=C_alloc(14);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10917,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=t3,tmp=(C_word)a,a+=8,tmp);
/* support.scm:706: db-put! */
t5=*((C_word*)lf[131]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[8];
av2[3]=t1;
av2[4]=lf[219];
av2[5]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}

/* k10915 in k10909 in k10906 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_10917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_10917,c,av);}
a=C_alloc(8);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10937,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:709: walk */
t4=((C_word*)((C_word*)t0)[5])[1];
f_10794(t4,t3,C_i_cadr(((C_word*)t0)[6]),((C_word*)t0)[7]);}

/* k10935 in k10915 in k10909 in k10906 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_10937(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_10937,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[97],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10960(C_word c,C_word *av){
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
C_word t13;
C_word t14;
C_word t15;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,3)))){
C_save_and_reclaim((void *)f_10960,c,av);}
a=C_alloc(26);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10965,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t10=C_i_check_list_2(t2,lf[125]);
t11=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_10978,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t1,a[6]=t3,a[7]=t4,a[8]=((C_word*)t0)[6],a[9]=t2,tmp=(C_word)a,a+=10,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11125,a[2]=t7,a[3]=t13,a[4]=t9,a[5]=t8,tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_11125(t15,t11,t2);}

/* g2240 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_10965(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10965,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10969,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:715: chicken.base#gensym */
t4=*((C_word*)lf[98]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k10967 in g2240 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_10969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_10969,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10972,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:716: db-put! */
t3=*((C_word*)lf[131]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[219];
av2[5]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k10970 in k10967 in g2240 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_10972(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10972,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_10978(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,4)))){
C_save_and_reclaim((void *)f_10978,c,av);}
a=C_alloc(25);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10981,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(t1,lf[125]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11075,a[2]=t2,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11077,a[2]=t5,a[3]=t10,a[4]=t6,tmp=(C_word)a,a+=5,tmp));
t12=((C_word*)t10)[1];
f_11077(t12,t8,((C_word*)t0)[9],t1);}

/* k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_10981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_10981,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_11046,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* support.scm:722: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[220];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* g2307 in k11052 in k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_fcall f_10998(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_10998,3,t0,t1,t2);}
/* support.scm:725: g2324 */
t3=((C_word*)((C_word*)t0)[2])[1];
f_10794(t3,t1,t2,((C_word*)t0)[3]);}

/* k11006 in k11052 in k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_11008(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_11008,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[118],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2301 in k11052 in k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_fcall f_11010(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11010,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11035,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:725: g2307 */
t4=((C_word*)t0)[4];
f_10998(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11033 in map-loop2301 in k11052 in k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_ccall f_11035(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11035,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11010(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_11046(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_11046,c,av);}
a=C_alloc(14);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11054,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11062,a[2]=t3,a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[9])){
/* support.scm:684: chicken.base#alist-ref */
t5=*((C_word*)lf[216]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[9];
av2[3]=((C_word*)t0)[4];
av2[4]=*((C_word*)lf[217]+1);
av2[5]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
/* support.scm:723: build-lambda-list */
t5=*((C_word*)lf[54]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[8];
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k11052 in k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_11054(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(33,c,3)))){
C_save_and_reclaim((void *)f_11054,c,av);}
a=C_alloc(33);
t2=C_i_cadddr(((C_word*)t0)[2]);
t3=C_a_i_list4(&a,4,((C_word*)t0)[3],((C_word*)t0)[4],t1,t2);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10998,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t9=C_i_check_list_2(((C_word*)t0)[7],lf[125]);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11008,a[2]=((C_word*)t0)[8],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11010,a[2]=t6,a[3]=t12,a[4]=t8,a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_11010(t14,t10,((C_word*)t0)[7]);}

/* k11060 in k11044 in k10979 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_11062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11062,c,av);}
/* support.scm:723: build-lambda-list */
t2=*((C_word*)lf[54]+1);{
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

/* k11073 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11075,c,av);}
/* support.scm:719: scheme#append */
t2=*((C_word*)lf[58]+1);{
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

/* map-loop2264 in k10976 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_11077(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_11077,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_cons(&a,2,t6,t7);
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

/* map-loop2234 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11125(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11125,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11150,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:714: g2240 */
t4=((C_word*)t0)[4];
f_10965(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11148 in map-loop2234 in a10959 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11150(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11150,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11125(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k11167 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11169(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_11169,c,av);}
a=C_alloc(22);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11174,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t7=C_i_check_list_2(((C_word*)t0)[4],lf[125]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11184,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11186,a[2]=t4,a[3]=t10,a[4]=t6,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_11186(t12,t8,((C_word*)t0)[4]);}

/* g2346 in k11167 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11174(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_11174,3,t0,t1,t2);}
/* support.scm:727: g2363 */
t3=((C_word*)((C_word*)t0)[2])[1];
f_10794(t3,t1,t2,((C_word*)t0)[3]);}

/* k11182 in k11167 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11184(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_11184,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2340 in k11167 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11186(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11186,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11211,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:727: g2346 */
t4=((C_word*)t0)[4];
f_11174(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11209 in map-loop2340 in k11167 in walk in k10784 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11211(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11211,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11186(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop2153 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11233(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_11233,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_cons(&a,2,t6,t7);
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

/* walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11284(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,5)))){
C_save_and_reclaim_args((void *)trf_11284,3,t0,t1,t2);}
a=C_alloc(9);
t3=C_slot(t2,C_fix(3));
t4=C_slot(t2,C_fix(2));
t5=C_slot(t2,C_fix(1));
t6=C_eqp(t5,lf[209]);
if(C_truep(t6)){
t7=C_i_car(t4);
t8=C_eqp(((C_word*)t0)[2],t7);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11328,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t10=C_i_length(((C_word*)t0)[3]);
t11=C_i_cadr(t4);
/* support.scm:740: qnode */
t12=*((C_word*)lf[150]+1);{
C_word av2[3];
av2[0]=t12;
av2[1]=t9;
av2[2]=C_i_less_or_equalp(t10,t11);
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}
else{
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
t7=C_eqp(t5,lf[211]);
if(C_truep(t7)){
t8=C_i_car(t4);
t9=C_eqp(((C_word*)t0)[2],t8);
if(C_truep(t9)){
t10=C_i_cadr(t4);
t11=C_i_length(((C_word*)t0)[3]);
if(C_truep(C_i_greaterp(t11,t10))){
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11375,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:747: varnode */
t13=*((C_word*)lf[148]+1);{
C_word av2[3];
av2[0]=t13;
av2[1]=t12;
av2[2]=C_i_list_ref(((C_word*)t0)[3],t10);
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}
else{
t12=C_a_i_list1(&a,1,lf[212]);
t13=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11403,a[2]=t12,a[3]=t1,a[4]=t2,a[5]=t10,tmp=(C_word)a,a+=6,tmp);
/* support.scm:750: qnode */
t14=*((C_word*)lf[150]+1);{
C_word av2[3];
av2[0]=t14;
av2[1]=t13;
av2[2]=t11;
((C_proc)(void*)(*((C_word*)t14+1)))(3,av2);}}}
else{
t10=t1;{
C_word av2[2];
av2[0]=t10;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}
else{
t8=C_eqp(t5,lf[213]);
if(C_truep(t8)){
t9=C_i_car(t4);
t10=C_eqp(((C_word*)t0)[2],t9);
if(C_truep(t10)){
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11430,a[2]=t4,a[3]=t2,a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:755: collect! */
t12=*((C_word*)lf[133]+1);{
C_word av2[6];
av2[0]=t12;
av2[1]=t11;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[205];
av2[5]=t2;
((C_proc)(void*)(*((C_word*)t12+1)))(6,av2);}}
else{
t11=t1;{
C_word av2[2];
av2[0]=t11;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}
else{
t9=C_i_check_list_2(t3,lf[44]);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11486,a[2]=t11,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp));
t13=((C_word*)t11)[1];
f_11486(t13,t1,t3);}}}}

/* k11326 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11328,c,av);}
/* support.scm:740: copy-node! */
t2=*((C_word*)lf[210]+1);{
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

/* k11373 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11375(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11375,c,av);}
/* support.scm:747: copy-node! */
t2=*((C_word*)lf[210]+1);{
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

/* k11401 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11403,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11407,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:750: qnode */
t3=*((C_word*)lf[150]+1);{
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

/* k11405 in k11401 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_11407(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_11407,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11411,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* support.scm:750: qnode */
t3=*((C_word*)lf[150]+1);{
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

/* k11409 in k11405 in k11401 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_11411(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_11411,c,av);}
a=C_alloc(14);
t2=C_a_i_list3(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=C_a_i_record4(&a,4,lf[136],lf[167],((C_word*)t0)[4],t2);
/* support.scm:748: copy-node! */
t4=*((C_word*)lf[210]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[5];
av2[2]=t3;
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k11428 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_11430(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,2)))){
C_save_and_reclaim((void *)f_11430,c,av);}
a=C_alloc(34);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_s_a_i_plus(&a,2,t2,C_fix(1));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11442,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:757: varnode */
t5=*((C_word*)lf[148]+1);{
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

/* k11440 in k11428 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_11442(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_11442,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11444,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_11444(t5,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* lp in k11440 in k11428 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_fcall f_11444(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(40,0,3)))){
C_save_and_reclaim_args((void *)trf_11444,4,t0,t1,t2,t3);}
a=C_alloc(40);
if(C_truep(C_i_zerop(t2))){
/* support.scm:759: copy-node! */
t4=*((C_word*)lf[210]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=C_s_a_i_minus(&a,2,t2,C_fix(1));
t5=C_a_i_list1(&a,1,lf[214]);
t6=C_a_i_list1(&a,1,t3);
t7=C_a_i_record4(&a,4,lf[136],lf[167],t5,t6);
/* support.scm:760: lp */
t9=t1;
t10=t4;
t11=t7;
t1=t9;
t2=t10;
t3=t11;
goto loop;}}

/* for-each-loop2423 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_11486(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11486,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11496,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:763: g2424 */
t4=((C_word*)((C_word*)t0)[3])[1];
f_11284(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11494 in for-each-loop2423 in walk in k10689 in k10480 in k10466 in k10463 in a10460 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_11496(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11496,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_11486(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.compiler.support#replace-rest-op-with-list-ops in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11518(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(34,c,4)))){
C_save_and_reclaim((void *)f_11518,c,av);}
a=C_alloc(34);
t5=C_eqp(t2,lf[211]);
if(C_truep(t5)){
t6=C_a_i_list1(&a,1,lf[224]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11545,a[2]=t3,a[3]=t1,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
/* support.scm:772: qnode */
t8=*((C_word*)lf[150]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
av2[2]=C_i_cadr(t4);
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t6=C_eqp(t2,lf[213]);
if(C_truep(t6)){
t7=C_i_cadr(t4);
t8=C_s_a_i_plus(&a,2,t7,C_fix(1));
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11565,a[2]=t10,tmp=(C_word)a,a+=3,tmp));
t12=((C_word*)t10)[1];
f_11565(t12,t1,t8,t3);}
else{
t7=C_eqp(t2,lf[209]);
if(C_truep(t7)){
t8=C_a_i_list1(&a,1,lf[226]);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11618,a[2]=t3,a[3]=t1,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
/* support.scm:783: qnode */
t10=*((C_word*)lf[150]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=C_i_cadr(t4);
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t8=C_eqp(t2,lf[228]);
if(C_truep(t8)){
t9=C_a_i_list1(&a,1,lf[229]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11665,a[2]=t3,a[3]=t1,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
/* support.scm:788: qnode */
t11=*((C_word*)lf[150]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=C_i_cadr(t4);
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}
else{
/* support.scm:789: bomb */
t9=*((C_word*)lf[13]+1);{
C_word *av2=av;
av2[0]=t9;
av2[1]=t1;
av2[2]=lf[230];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}}}}}

/* k11543 in chicken.compiler.support#replace-rest-op-with-list-ops in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11545(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_11545,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[167],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* lp in chicken.compiler.support#replace-rest-op-with-list-ops in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11565(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(40,0,3)))){
C_save_and_reclaim_args((void *)trf_11565,4,t0,t1,t2,t3);}
a=C_alloc(40);
if(C_truep(C_i_zerop(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_s_a_i_minus(&a,2,t2,C_fix(1));
t5=C_a_i_list1(&a,1,lf[225]);
t6=C_a_i_list1(&a,1,t3);
t7=C_a_i_record4(&a,4,lf[136],lf[167],t5,t6);
/* support.scm:778: lp */
t9=t1;
t10=t4;
t11=t7;
t1=t9;
t2=t10;
t3=t11;
goto loop;}}

/* k11616 in chicken.compiler.support#replace-rest-op-with-list-ops in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11618(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,1)))){
C_save_and_reclaim((void *)f_11618,c,av);}
a=C_alloc(22);
t2=C_a_i_list1(&a,1,lf[227]);
t3=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t4=C_a_i_record4(&a,4,lf[136],lf[167],t2,t3);
t5=C_a_i_list2(&a,2,t1,t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[167],((C_word*)t0)[4],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k11663 in chicken.compiler.support#replace-rest-op-with-list-ops in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11665(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,1)))){
C_save_and_reclaim((void *)f_11665,c,av);}
a=C_alloc(11);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[167],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#tree-copy in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11682,c,av);}
a=C_alloc(5);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11688,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_11688(t6,t1,t2);}

/* rec in chicken.compiler.support#tree-copy in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11688(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11688,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11702,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:795: rec */
t5=t3;
t6=C_u_i_car(t2);
t1=t5;
t2=t6;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11700 in rec in chicken.compiler.support#tree-copy in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11702(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11702,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11706,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:795: rec */
t3=((C_word*)((C_word*)t0)[3])[1];
f_11688(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k11704 in k11700 in rec in chicken.compiler.support#tree-copy in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11706(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_11706,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#copy-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_11712,c,av);}
a=C_alloc(5);
t3=C_slot(t2,C_fix(1));
t4=C_slot(t2,C_fix(2));
t5=C_slot(t2,C_fix(3));
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_record4(&a,4,lf[136],t3,t4,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* chicken.compiler.support#copy-node! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11750(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11750,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11754,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:804: node-class-set! */
t5=*((C_word*)lf[140]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
av2[3]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k11752 in chicken.compiler.support#copy-node! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_11754,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11757,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:805: node-parameters-set! */
t3=*((C_word*)lf[144]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_slot(((C_word*)t0)[4],C_fix(2));
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k11755 in k11752 in chicken.compiler.support#copy-node! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11757(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_11757,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11760,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:806: node-subexpressions-set! */
t3=*((C_word*)lf[147]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_slot(((C_word*)t0)[4],C_fix(3));
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k11758 in k11755 in k11752 in chicken.compiler.support#copy-node! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11760(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11760,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* walk in k12201 in k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_fcall f_11795(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_11795,3,t0,t1,t2);}
a=C_alloc(18);
t3=C_slot(t2,C_fix(1));
t4=C_slot(t2,C_fix(2));
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_slot(t2,C_fix(3));
t10=C_i_check_list_2(t9,lf[125]);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11839,a[2]=t4,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11841,a[2]=t7,a[3]=t13,a[4]=((C_word*)t0)[2],a[5]=t8,tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_11841(t15,t11,t9);}

/* k11837 in walk in k12201 in k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_11839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_11839,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* map-loop2529 in walk in k12201 in k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_fcall f_11841(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11841,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11866,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:813: g2535 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_11795(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11864 in map-loop2529 in walk in k12201 in k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_11866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11866,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11841(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* walk in k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11881(C_word t0,C_word t1,C_word t2){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_11881,3,t0,t1,t2);}
a=C_alloc(18);
t3=C_i_car(t2);
t4=C_i_cadr(t2);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_u_i_cdr(t2);
t10=C_u_i_cdr(t9);
t11=C_i_check_list_2(t10,lf[125]);
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11910,a[2]=t1,a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11912,a[2]=t7,a[3]=t14,a[4]=((C_word*)t0)[2],a[5]=t8,tmp=(C_word)a,a+=6,tmp));
t16=((C_word*)t14)[1];
f_11912(t16,t12,t10);}

/* k11908 in walk in k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11910(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_11910,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2568 in walk in k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11912(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_11912,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11937,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:817: g2574 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_11881(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k11935 in map-loop2568 in walk in k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11937(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11937,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_11912(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11946(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6=av[6];
C_word t7=av[7];
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word t14;
C_word t15;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_11946,c,av);}
a=C_alloc(22);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11949,a[2]=t7,tmp=(C_word)a,a+=3,tmp);
t9=C_SCHEME_END_OF_LIST;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_END_OF_LIST;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12003,a[2]=t1,a[3]=t10,a[4]=t12,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
t14=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12107,a[2]=t10,a[3]=t12,a[4]=t8,a[5]=t6,a[6]=t4,a[7]=t5,tmp=(C_word)a,a+=8,tmp);
/* support.scm:832: chicken.internal#hash-table-for-each */
t15=*((C_word*)lf[257]+1);{
C_word *av2=av;
av2[0]=t15;
av2[1]=t13;
av2[2]=t14;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t15+1)))(4,av2);}}

/* uses-foreign-stubs? in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_11949(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_11949,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11955,a[2]=((C_word*)t0)[2],a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];{
C_word av2[3];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
f_11955(3,av2);}}

/* walk in uses-foreign-stubs? in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_11955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11955,c,av);}
t3=C_slot(t2,C_fix(1));
t4=C_eqp(t3,lf[167]);
if(C_truep(t4)){
t5=C_slot(t2,C_fix(2));
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_i_memq(C_i_car(t5),((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* support.scm:829: any */
f_5704(t1,((C_word*)((C_word*)t0)[3])[1],C_slot(t2,C_fix(3)));}}

/* k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_12003,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12006,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12057,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* support.scm:853: scheme#with-output-to-file */
t4=*((C_word*)lf[246]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12006(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_12006,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12012,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[3])[1]))){
/* support.scm:864: debugging */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[238];
av2[3]=lf[239];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_12012(2,av2);}}}

/* k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_12012,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12020,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)((C_word*)t0)[3])[1];
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7409,tmp=(C_word)a,a+=2,tmp);
/* support.scm:279: chicken.sort#sort */
t5=*((C_word*)lf[237]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12018 in k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12020(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12020,c,av);}
a=C_alloc(5);
t2=C_i_check_list_2(t1,lf[44]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12028,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_12028(t6,((C_word*)t0)[2],t1);}

/* for-each-loop2694 in k12018 in k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12028(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_12028,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12038,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:865: g2710 */
t4=*((C_word*)lf[233]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[234];
av2[3]=C_slot(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k12036 in for-each-loop2694 in k12018 in k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12038(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_12038,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_12028(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12057,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12061,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12105,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:855: chicken.platform#chicken-version */
t4=*((C_word*)lf[245]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k12059 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12061(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_12061,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12072,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:861: scheme#reverse */
t3=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k12064 in for-each-loop2672 in k12070 in k12059 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12066(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12066,c,av);}
/* support.scm:860: scheme#newline */
t2=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12070 in k12059 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12072(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12072,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12075,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12080,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_12080(t6,t2,t1);}

/* k12073 in k12070 in k12059 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_12075,c,av);}
/* support.scm:862: chicken.base#print */
t2=*((C_word*)lf[233]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[240];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* for-each-loop2672 in k12070 in k12059 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12080(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_12080,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12090,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12066,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* support.scm:859: chicken.pretty-print#pp */
t6=*((C_word*)lf[241]+1);{
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

/* k12088 in for-each-loop2672 in k12070 in k12059 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12090(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_12090,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_12080(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k12103 in a12056 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12105(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_12105,c,av);}
/* support.scm:855: chicken.base#print */
t2=*((C_word*)lf[233]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[242];
av2[3]=t1;
av2[4]=lf[243];
av2[5]=((C_word*)t0)[3];
av2[6]=lf[244];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}

/* a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12107(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_12107,c,av);}
a=C_alloc(10);
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12114,a[2]=t3,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=t1,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
/* support.scm:834: variable-visible? */
t5=*((C_word*)lf[256]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_12114,c,av);}
a=C_alloc(11);
if(C_truep(t1)){
t2=C_i_assq(lf[247],((C_word*)t0)[2]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_12262,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* tweaks.scm:60: ##sys#get */
t4=*((C_word*)lf[178]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[255];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12135(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_12135,2,t0,t1);}
a=C_alloc(10);
if(C_truep(t1)){
if(C_truep(C_i_assq(lf[249],((C_word*)t0)[2]))){
t2=C_i_cdr(((C_word*)t0)[3]);
t3=C_slot(t2,C_fix(2));
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12229,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[8],a[8]=t3,a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* support.scm:842: db-get */
t5=*((C_word*)lf[127]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[10];
av2[3]=((C_word*)t0)[4];
av2[4]=lf[253];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t4=((C_word*)t0)[7];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t2=((C_word*)t0)[7];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}
else{
t2=((C_word*)t0)[7];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12169(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12169,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12172,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_eqp(t1,lf[250]);
if(C_truep(t3)){
t4=t2;
f_12172(t4,C_SCHEME_TRUE);}
else{
t4=C_eqp(t1,lf[251]);
t5=t2;
f_12172(t5,(C_truep(t4)?C_SCHEME_FALSE:C_i_lessp(C_i_cadddr(((C_word*)t0)[8]),((C_word*)t0)[9])));}}

/* k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12172(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_12172,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12203,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* support.scm:849: uses-foreign-stubs? */
t3=((C_word*)t0)[7];
f_11949(t3,t2,C_u_i_cdr(((C_word*)t0)[6]));}
else{
t2=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12195 in k12201 in k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_12197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12197,c,av);}
a=C_alloc(9);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[3])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k12201 in k12170 in k12167 in k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_12203(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_12203,c,av);}
a=C_alloc(13);
if(C_truep(C_i_not(t1))){
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12197,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t5=C_u_i_cdr(((C_word*)t0)[6]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11795,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_11795(t9,t4,t5);}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12227 in k12133 in k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_12229,c,av);}
a=C_alloc(10);
if(C_truep(C_i_not(t1))){
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12169,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* tweaks.scm:60: ##sys#get */
t3=*((C_word*)lf[178]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[252];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12260 in k12112 in a12106 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12262(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_12262,c,av);}
a=C_alloc(11);
t2=C_i_structurep(t1,lf[136]);
if(C_truep(C_i_not(t2))){
t3=C_i_assq(lf[248],((C_word*)t0)[2]);
t4=C_i_not(t3);
t5=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_12135,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(t4)){
t6=t5;
f_12135(t6,t4);}
else{
t6=C_i_cdr(t3);
t7=t5;
f_12135(t7,C_i_not(C_eqp(lf[254],t6)));}}
else{
t3=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12264(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,3)))){
C_save_and_reclaim((void *)f_12264,c,av);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12270,tmp=(C_word)a,a+=2,tmp);
/* support.scm:869: scheme#with-input-from-file */
t4=*((C_word*)lf[260]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12270(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_12270,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12276,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_12276(t5,t1);}

/* loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12276(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_12276,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12280,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:872: scheme#read */
t3=*((C_word*)lf[83]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12280(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_12280,c,av);}
a=C_alloc(13);
if(C_truep(C_eofp(t1))){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12303,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_i_car(t1);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12314,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_i_cadr(t1);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11881,a[2]=t7,tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t7)[1];
f_11881(t9,t4,t5);}}

/* k12301 in k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12303,c,av);}
/* support.scm:878: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12276(t2,((C_word*)t0)[3]);}

/* k12312 in k12278 in loop in a12269 in chicken.compiler.support#load-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12314(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_12314,c,av);}
a=C_alloc(3);
t2=C_a_i_list(&a,1,t1);
if(C_truep(C_i_nullp(t2))){
/* tweaks.scm:57: ##sys#put! */
t3=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[255];
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
/* tweaks.scm:57: ##sys#put! */
t3=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[255];
av2[4]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12320(C_word c,C_word *av){
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
C_word t13;
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,4)))){
C_save_and_reclaim((void *)f_12320,c,av);}
a=C_alloc(27);
t5=C_SCHEME_END_OF_LIST;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12323,a[2]=t6,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t14=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12357,a[2]=t8,a[3]=t10,tmp=(C_word)a,a+=4,tmp));
t15=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12404,a[2]=t8,a[3]=t12,a[4]=t10,tmp=(C_word)a,a+=5,tmp));
t16=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12527,a[2]=t6,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* support.scm:912: matchn */
t17=((C_word*)t12)[1];
f_12404(t17,t16,t2,t3);}

/* resolve in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12323(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_12323,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_assq(t2,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12331,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* support.scm:887: g2756 */
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(
/* support.scm:887: g2756 */
  f_12331(t5,t4)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(C_i_memq(t2,((C_word*)t0)[3]))){
t5=((C_word*)((C_word*)t0)[2])[1];
t6=C_a_i_cons(&a,2,t2,t3);
t7=C_a_i_cons(&a,2,t6,t5);
t8=C_mutate(((C_word *)((C_word*)t0)[2])+1,t7);
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_eqp(t2,t3);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* g2756 in resolve in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_12331(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_equalp(((C_word*)t0)[2],C_i_cdr(t1)));}

/* match1 in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12357(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_12357,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
/* support.scm:894: resolve */
t5=((C_word*)((C_word*)t0)[2])[1];
f_12323(t5,t1,t3,t2);}
else{
t5=C_i_pairp(t2);
if(C_truep(C_i_not(t5))){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12379,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* support.scm:896: match1 */
t8=t6;
t9=C_i_car(t2);
t10=C_i_car(t3);
t1=t8;
t2=t9;
t3=t10;
goto loop;}}}

/* k12377 in match1 in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12379,c,av);}
if(C_truep(t1)){
/* support.scm:896: match1 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12357(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_u_i_cdr(((C_word*)t0)[5]));}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* matchn in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12404(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_12404,4,t0,t1,t2,t3);}
a=C_alloc(7);
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
/* support.scm:901: resolve */
t5=((C_word*)((C_word*)t0)[2])[1];
f_12323(t5,t1,t3,t2);}
else{
t5=C_slot(t2,C_fix(1));
t6=C_i_car(t3);
t7=C_eqp(t5,t6);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12426,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* support.scm:903: match1 */
t9=((C_word*)((C_word*)t0)[4])[1];
f_12357(t9,t8,C_slot(t2,C_fix(2)),C_i_cadr(t3));}
else{
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}}

/* k12424 in matchn in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12426(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_12426,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_slot(((C_word*)t0)[2],C_fix(3));
t3=C_i_cddr(((C_word*)t0)[3]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12444,a[2]=((C_word*)t0)[4],a[3]=t5,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_12444(t7,((C_word*)t0)[6],t2,t3);}
else{
t2=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* loop in k12424 in matchn in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12444(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_12444,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_i_nullp(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
/* support.scm:907: resolve */
t5=((C_word*)((C_word*)t0)[2])[1];
f_12323(t5,t1,t3,t2);}
else{
if(C_truep(C_i_nullp(t2))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12475,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* support.scm:909: matchn */
t6=((C_word*)((C_word*)t0)[4])[1];
f_12404(t6,t5,C_i_car(t2),C_i_car(t3));}}}}

/* k12473 in loop in k12424 in matchn in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12475,c,av);}
if(C_truep(t1)){
/* support.scm:910: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12444(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_u_i_cdr(((C_word*)t0)[5]));}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12525 in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12527(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,6)))){
C_save_and_reclaim((void *)f_12527,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12533,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:915: debugging */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[262];
av2[3]=lf[263];
av2[4]=C_slot(((C_word*)t0)[4],C_fix(1));
av2[5]=C_slot(((C_word*)t0)[4],C_fix(2));
av2[6]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k12531 in k12525 in chicken.compiler.support#match-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12533,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12553(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_12553,c,av);}
a=C_alloc(5);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12559,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
av2[2]=t2;
f_12559(3,av2);}}

/* walk in chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12559(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_12559,c,av);}
a=C_alloc(7);
t3=C_slot(t2,C_fix(3));
t4=C_slot(t2,C_fix(1));
t5=C_eqp(t4,lf[149]);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12585,a[2]=t1,a[3]=t4,a[4]=t2,a[5]=((C_word*)t0)[2],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
if(C_truep(t5)){
t7=t6;
f_12585(t7,t5);}
else{
t7=C_eqp(t4,lf[86]);
if(C_truep(t7)){
t8=t6;
f_12585(t8,t7);}
else{
t8=C_eqp(t4,lf[154]);
t9=t6;
f_12585(t9,(C_truep(t8)?t8:C_eqp(t4,lf[169])));}}}

/* k12583 in walk in chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12585(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_12585,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[118]);
if(C_truep(t2)){
t3=C_slot(((C_word*)t0)[4],C_fix(2));
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12599,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=*((C_word*)lf[266]+1);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6431,a[2]=t8,a[3]=t5,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];
f_6431(t10,((C_word*)t0)[2],*((C_word*)lf[266]+1));}
else{
t3=C_eqp(((C_word*)t0)[3],lf[153]);
if(C_truep(t3)){
if(C_truep(t3)){
/* support.scm:931: any */
f_5704(((C_word*)t0)[2],((C_word*)((C_word*)t0)[5])[1],((C_word*)t0)[6]);}
else{
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t4=C_eqp(((C_word*)t0)[3],lf[97]);
if(C_truep(t4)){
/* support.scm:931: any */
f_5704(((C_word*)t0)[2],((C_word*)((C_word*)t0)[5])[1],((C_word*)t0)[6]);}
else{
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}}}

/* a12598 in k12583 in walk in chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12599(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_12599,3,t0,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12607,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:929: foreign-callback-stub-id */
t4=*((C_word*)lf[265]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k12605 in a12598 in k12583 in walk in chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12607,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#simple-lambda-node? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12662(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_12662,c,av);}
a=C_alloc(6);
t3=C_slot(t2,C_fix(2));
t4=C_i_caddr(t3);
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_i_car(t4):C_SCHEME_FALSE);
if(C_truep(t6)){
if(C_truep(C_i_cadr(t3))){
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12691,a[2]=t6,a[3]=t8,tmp=(C_word)a,a+=4,tmp));
t10=((C_word*)t8)[1];{
C_word *av2=av;
av2[0]=t10;
av2[1]=t1;
av2[2]=t2;
f_12691(3,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* rec in chicken.compiler.support#simple-lambda-node? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12691(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12691,c,av);}
t3=C_slot(t2,C_fix(1));
t4=C_eqp(t3,lf[174]);
if(C_truep(t4)){
t5=C_slot(t2,C_fix(3));
t6=C_i_car(t5);
t7=C_slot(t6,C_fix(1));
t8=C_eqp(lf[149],t7);
if(C_truep(t8)){
t9=C_slot(t6,C_fix(2));
t10=C_i_car(t9);
t11=C_eqp(((C_word*)t0)[2],t10);
if(C_truep(t11)){
/* support.scm:947: every */
f_5670(t1,((C_word*)((C_word*)t0)[3])[1],C_i_cdr(t5));}
else{
t12=t1;{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}}
else{
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
t5=C_eqp(t3,lf[185]);
if(C_truep(t5)){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
/* support.scm:949: every */
f_5670(t1,((C_word*)((C_word*)t0)[3])[1],C_slot(t2,C_fix(3)));}}}

/* chicken.compiler.support#dump-undefined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_12788,c,av);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12794,tmp=(C_word)a,a+=2,tmp);
/* support.scm:955: chicken.internal#hash-table-for-each */
t4=*((C_word*)lf[257]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* a12793 in chicken.compiler.support#dump-undefined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12794,c,av);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12801,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12827,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* support.scm:957: chicken.keyword#keyword? */
t6=*((C_word*)lf[272]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k12799 in a12793 in chicken.compiler.support#dump-undefined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12801(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12801,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12804,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:960: scheme#write */
t3=*((C_word*)lf[269]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12802 in k12799 in a12793 in chicken.compiler.support#dump-undefined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12804,c,av);}
/* support.scm:961: scheme#newline */
t2=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12825 in a12793 in chicken.compiler.support#dump-undefined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12827,c,av);}
if(C_truep(C_i_not(t1))){
t2=C_i_assq(lf[270],((C_word*)t0)[2]);
t3=((C_word*)t0)[3];
f_12801(t3,(C_truep(t2)?C_i_not(C_i_assq(lf[271],((C_word*)t0)[2])):C_SCHEME_FALSE));}
else{
t2=((C_word*)t0)[3];
f_12801(t2,C_SCHEME_FALSE);}}

/* chicken.compiler.support#dump-defined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_12829,c,av);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12835,tmp=(C_word)a,a+=2,tmp);
/* support.scm:965: chicken.internal#hash-table-for-each */
t4=*((C_word*)lf[257]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* a12834 in chicken.compiler.support#dump-defined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12835,c,av);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12842,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12864,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* support.scm:967: chicken.keyword#keyword? */
t6=*((C_word*)lf[272]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k12840 in a12834 in chicken.compiler.support#dump-defined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_12842(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_12842,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12845,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:970: scheme#write */
t3=*((C_word*)lf[269]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12843 in k12840 in a12834 in chicken.compiler.support#dump-defined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12845(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12845,c,av);}
/* support.scm:971: scheme#newline */
t2=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12862 in a12834 in chicken.compiler.support#dump-defined-globals in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12864(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12864,c,av);}
if(C_truep(C_i_not(t1))){
t2=C_i_assq(lf[270],((C_word*)t0)[2]);
t3=((C_word*)t0)[3];
f_12842(t3,(C_truep(t2)?C_i_assq(lf[271],((C_word*)t0)[2]):C_SCHEME_FALSE));}
else{
t2=((C_word*)t0)[3];
f_12842(t2,C_SCHEME_FALSE);}}

/* chicken.compiler.support#dump-global-refs in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_12866,c,av);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12872,tmp=(C_word)a,a+=2,tmp);
/* support.scm:975: chicken.internal#hash-table-for-each */
t4=*((C_word*)lf[257]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* a12871 in chicken.compiler.support#dump-global-refs in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12872(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_12872,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12913,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:977: chicken.keyword#keyword? */
t5=*((C_word*)lf[272]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k12883 in k12911 in a12871 in chicken.compiler.support#dump-global-refs in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12885,c,av);}
/* support.scm:980: scheme#newline */
t2=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12911 in a12871 in chicken.compiler.support#dump-global-refs in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12913(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12913,c,av);}
a=C_alloc(9);
t2=C_i_not(t1);
t3=(C_truep(t2)?C_i_assq(lf[270],((C_word*)t0)[2]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_i_assq(lf[205],((C_word*)t0)[2]);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12885,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t4)){
t6=C_i_cdr(t4);
t7=C_i_length(t6);
t8=C_a_i_list2(&a,2,((C_word*)t0)[4],t7);
/* support.scm:979: scheme#write */
t9=*((C_word*)lf[269]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t5;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
t6=C_a_i_list2(&a,2,((C_word*)t0)[4],C_fix(0));
/* support.scm:979: scheme#write */
t7=*((C_word*)lf[269]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}
else{
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* ##sys#toplevel-definition-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_12915,c,av);}
a=C_alloc(4);
if(C_truep(C_u_i_namespaced_symbolp(t2))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17692,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1712: variable-hidden? */
t6=*((C_word*)lf[278]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
if(C_truep(C_i_not(t4))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12936,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* support.scm:991: debugging */
t6=*((C_word*)lf[22]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[186];
av2[3]=lf[280];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* k12934 in ##sys#toplevel-definition-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12936(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_12936,c,av);}
/* support.scm:992: hide-variable */
t2=*((C_word*)lf[279]+1);{
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

/* chicken.compiler.support#make-foreign-callback-stub in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12943(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6=av[6];
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,1)))){
C_save_and_reclaim((void *)f_12943,c,av);}
a=C_alloc(7);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_record6(&a,6,lf[282],t2,t3,t4,t5,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* chicken.compiler.support#foreign-callback-stub? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12949(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12949,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_structurep(t2,lf[282]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#foreign-callback-stub-id in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12955(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12955,c,av);}
t3=C_i_check_structure_2(t2,lf[282],lf[284]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#foreign-callback-stub-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12964(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12964,c,av);}
t3=C_i_check_structure_2(t2,lf[282],lf[286]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(2));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#foreign-callback-stub-qualifiers in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12973,c,av);}
t3=C_i_check_structure_2(t2,lf[282],lf[288]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(3));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#foreign-callback-stub-return-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12982(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12982,c,av);}
t3=C_i_check_structure_2(t2,lf[282],lf[290]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(4));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#foreign-callback-stub-argument-types in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_12991(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12991,c,av);}
t3=C_i_check_structure_2(t2,lf[282],lf[292]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(5));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#register-foreign-callback-stub! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13000(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_13000,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13026,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t4;
av2[2]=*((C_word*)lf[281]+1);
av2[3]=t2;
av2[4]=t3;
C_apply(5,av2);}}

/* k13024 in chicken.compiler.support#register-foreign-callback-stub! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_13026,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,*((C_word*)lf[266]+1));
t3=C_mutate((C_word*)lf[266]+1 /* (set! chicken.compiler.support#foreign-callback-stubs ...) */,t2);
t4=C_SCHEME_END_OF_LIST;
if(C_truep(C_i_nullp(t4))){
/* tweaks.scm:57: ##sys#put! */
t5=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[294];
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
/* tweaks.scm:57: ##sys#put! */
t5=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[294];
av2[4]=C_i_car(t4);
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* chicken.compiler.support#clear-foreign-type-table! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_13029,c,av);}
a=C_alloc(3);
if(C_truep(lf[295])){
/* support.scm:1020: scheme#vector-fill! */
t2=*((C_word*)lf[297]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[295];
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13040,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1021: scheme#make-vector */
t3=*((C_word*)lf[298]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(301);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k13038 in chicken.compiler.support#clear-foreign-type-table! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13040(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_13040,c,av);}
t2=C_mutate(&lf[295] /* (set! chicken.compiler.support#foreign-type-table ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#register-foreign-type! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13042(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_13042,c,av);}
a=C_alloc(4);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=(C_truep(t8)?t5:C_SCHEME_FALSE);
t11=(C_truep(t5)?C_a_i_vector3(&a,3,t3,t10,t8):C_a_i_vector3(&a,3,t3,t10,C_SCHEME_FALSE));
/* support.scm:1029: chicken.internal#hash-table-set! */
t12=*((C_word*)lf[132]+1);{
C_word av2[5];
av2[0]=t12;
av2[1]=t1;
av2[2]=lf[295];
av2[3]=t2;
av2[4]=t11;
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* chicken.compiler.support#lookup-foreign-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13096,c,av);}
/* support.scm:1037: chicken.internal#hash-table-ref */
t3=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[295];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13102(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_13102,c,av);}
a=C_alloc(7);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13108,a[2]=t2,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14172,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1054: follow-without-loop */
f_7372(t1,t3,t4,t5);}

/* a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13108(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_13108,c,av);}
a=C_alloc(8);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13114,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_13114(t7,t1,t2);}

/* repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13114(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_13114,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_eqp(t2,lf[303]);
t4=(C_truep(t3)?t3:C_eqp(t2,lf[304]));
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=(C_truep(*((C_word*)lf[10]+1))?((C_word*)t0)[2]:C_a_i_list(&a,2,lf[305],((C_word*)t0)[2]));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(t2,lf[306]);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13139,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t5)){
t7=t6;
f_13139(t7,t5);}
else{
t7=C_eqp(t2,lf[393]);
if(C_truep(t7)){
t8=t6;
f_13139(t8,t7);}
else{
t8=C_eqp(t2,lf[394]);
if(C_truep(t8)){
t9=t6;
f_13139(t9,t8);}
else{
t9=C_eqp(t2,lf[395]);
if(C_truep(t9)){
t10=t6;
f_13139(t10,t9);}
else{
t10=C_eqp(t2,lf[396]);
t11=t6;
f_13139(t11,(C_truep(t10)?t10:C_eqp(t2,lf[397])));}}}}}}

/* k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13139(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_13139,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=(C_truep(*((C_word*)lf[10]+1))?((C_word*)t0)[3]:C_a_i_list(&a,2,lf[307],((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[308]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13154,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t2)){
t4=t3;
f_13154(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[4],lf[391]);
t5=t3;
f_13154(t5,(C_truep(t4)?t4:C_eqp(((C_word*)t0)[4],lf[392])));}}}

/* k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13154(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_13154,2,t0,t1);}
a=C_alloc(15);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=(C_truep(*((C_word*)lf[10]+1))?((C_word*)t0)[3]:C_a_i_list(&a,2,lf[309],((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[310]);
t3=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[4],lf[311]));
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13172,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1065: chicken.base#gensym */
t5=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[4],lf[316]);
t5=(C_truep(t4)?t4:C_eqp(((C_word*)t0)[4],lf[317]));
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t6;
av2[1]=(C_truep(*((C_word*)lf[10]+1))?((C_word*)t0)[3]:C_a_i_list(&a,2,lf[312],((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(((C_word*)t0)[4],lf[318]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13222,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1077: chicken.base#gensym */
t8=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(((C_word*)t0)[4],lf[320]);
if(C_truep(t7)){
if(C_truep(*((C_word*)lf[10]+1))){
t8=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t8;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_a_i_list(&a,2,lf[313],lf[318]);
t9=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t9;
av2[1]=C_a_i_list(&a,3,lf[319],t8,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
t8=C_eqp(((C_word*)t0)[4],lf[321]);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13277,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t8)){
t10=t9;
f_13277(t10,t8);}
else{
t10=C_eqp(((C_word*)t0)[4],lf[382]);
if(C_truep(t10)){
t11=t9;
f_13277(t11,t10);}
else{
t11=C_eqp(((C_word*)t0)[4],lf[383]);
if(C_truep(t11)){
t12=t9;
f_13277(t12,t11);}
else{
t12=C_eqp(((C_word*)t0)[4],lf[384]);
if(C_truep(t12)){
t13=t9;
f_13277(t13,t12);}
else{
t13=C_eqp(((C_word*)t0)[4],lf[385]);
if(C_truep(t13)){
t14=t9;
f_13277(t14,t13);}
else{
t14=C_eqp(((C_word*)t0)[4],lf[386]);
if(C_truep(t14)){
t15=t9;
f_13277(t15,t14);}
else{
t15=C_eqp(((C_word*)t0)[4],lf[387]);
if(C_truep(t15)){
t16=t9;
f_13277(t16,t15);}
else{
t16=C_eqp(((C_word*)t0)[4],lf[388]);
if(C_truep(t16)){
t17=t9;
f_13277(t17,t16);}
else{
t17=C_eqp(((C_word*)t0)[4],lf[389]);
t18=t9;
f_13277(t18,(C_truep(t17)?t17:C_eqp(((C_word*)t0)[4],lf[390])));}}}}}}}}}}}}}}

/* k13170 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13172(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_13172,c,av);}
a=C_alloc(42);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(C_truep(*((C_word*)lf[10]+1))?t1:C_a_i_list(&a,2,lf[312],t1));
t5=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t6=C_a_i_list(&a,4,lf[314],t1,t4,t5);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,3,lf[315],t3,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k13220 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,2)))){
C_save_and_reclaim((void *)f_13222,c,av);}
a=C_alloc(29);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13237,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[10]+1))){
t5=t4;
f_13237(t5,t1);}
else{
t5=C_a_i_list(&a,2,lf[313],lf[318]);
t6=t4;
f_13237(t6,C_a_i_list(&a,3,lf[319],t5,t1));}}

/* k13235 in k13220 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13237(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,0,1)))){
C_save_and_reclaim_args((void *)trf_13237,2,t0,t1);}
a=C_alloc(27);
t2=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t3=C_a_i_list(&a,4,lf[314],((C_word*)t0)[2],t1,t2);
t4=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[315],((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13277(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_13277,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13280,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1090: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[322]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13319,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t2)){
t4=t3;
f_13319(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[4],lf[373]);
if(C_truep(t4)){
t5=t3;
f_13319(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[4],lf[374]);
if(C_truep(t5)){
t6=t3;
f_13319(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[4],lf[375]);
if(C_truep(t6)){
t7=t3;
f_13319(t7,t6);}
else{
t7=C_eqp(((C_word*)t0)[4],lf[376]);
if(C_truep(t7)){
t8=t3;
f_13319(t8,t7);}
else{
t8=C_eqp(((C_word*)t0)[4],lf[377]);
if(C_truep(t8)){
t9=t3;
f_13319(t9,t8);}
else{
t9=C_eqp(((C_word*)t0)[4],lf[378]);
if(C_truep(t9)){
t10=t3;
f_13319(t10,t9);}
else{
t10=C_eqp(((C_word*)t0)[4],lf[379]);
if(C_truep(t10)){
t11=t3;
f_13319(t11,t10);}
else{
t11=C_eqp(((C_word*)t0)[4],lf[380]);
t12=t3;
f_13319(t12,(C_truep(t11)?t11:C_eqp(((C_word*)t0)[4],lf[381])));}}}}}}}}}}

/* k13278 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_13280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,2)))){
C_save_and_reclaim((void *)f_13280,c,av);}
a=C_alloc(29);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13295,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[10]+1))){
t5=t4;
f_13295(t5,t1);}
else{
t5=C_a_i_list(&a,2,lf[313],((C_word*)t0)[4]);
t6=t4;
f_13295(t6,C_a_i_list(&a,3,lf[319],t5,t1));}}

/* k13293 in k13278 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13295(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,0,1)))){
C_save_and_reclaim_args((void *)trf_13295,2,t0,t1);}
a=C_alloc(27);
t2=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t3=C_a_i_list(&a,4,lf[314],((C_word*)t0)[2],t1,t2);
t4=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[315],((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13319(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_13319,2,t0,t1);}
a=C_alloc(15);
if(C_truep(t1)){
if(C_truep(*((C_word*)lf[10]+1))){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_slot(C_u_i_assq(((C_word*)t0)[4],lf[323]),C_fix(1));
t3=C_a_i_list(&a,2,lf[313],t2);
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[319],t3,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[324]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13345,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t2)){
t4=t3;
f_13345(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[4],lf[368]);
if(C_truep(t4)){
t5=t3;
f_13345(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[4],lf[369]);
if(C_truep(t5)){
t6=t3;
f_13345(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[4],lf[370]);
if(C_truep(t6)){
t7=t3;
f_13345(t7,t6);}
else{
t7=C_eqp(((C_word*)t0)[4],lf[371]);
t8=t3;
f_13345(t8,(C_truep(t7)?t7:C_eqp(((C_word*)t0)[4],lf[372])));}}}}}}

/* k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_13345(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_13345,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_slot(C_u_i_assq(((C_word*)t0)[2],((C_word*)t0)[3]),C_fix(1));
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13351,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1109: chicken.base#open-output-string */
t4=*((C_word*)lf[331]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[2],lf[332]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13388,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t2)){
t4=t3;
f_13388(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[2],lf[363]);
if(C_truep(t4)){
t5=t3;
f_13388(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[2],lf[364]);
if(C_truep(t5)){
t6=t3;
f_13388(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[2],lf[365]);
if(C_truep(t6)){
t7=t3;
f_13388(t7,t6);}
else{
t7=C_eqp(((C_word*)t0)[2],lf[366]);
t8=t3;
f_13388(t8,(C_truep(t7)?t7:C_eqp(((C_word*)t0)[2],lf[367])));}}}}}}

/* k13349 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_13351(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_13351,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[325]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13357,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:1109: ##sys#print */
t4=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[330];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k13355 in k13349 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_13357(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_13357,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13360,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1109: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k13358 in k13355 in k13349 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_13360(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_13360,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13363,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1109: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[329];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k13361 in k13358 in k13355 in k13349 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_13363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_13363,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13366,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1109: chicken.base#get-output-string */
t3=*((C_word*)lf[328]+1);{
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

/* k13364 in k13361 in k13358 in k13355 in k13349 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_ccall f_13366(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_13366,c,av);}
a=C_alloc(18);
if(C_truep(*((C_word*)lf[10]+1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_list(&a,3,lf[326],t1,lf[306]);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[327],((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_13388(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_13388,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_i_assq(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_slot(t2,C_fix(1));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13394,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1117: chicken.base#open-output-string */
t5=*((C_word*)lf[331]+1);{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[2],lf[336]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13432,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t2)){
t4=t3;
f_13432(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[2],lf[361]);
t5=t3;
f_13432(t5,(C_truep(t4)?t4:C_eqp(((C_word*)t0)[2],lf[362])));}}}

/* k13392 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_13394(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_13394,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[325]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13400,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:1117: ##sys#print */
t4=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[335];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k13398 in k13392 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_13400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_13400,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13403,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1117: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k13401 in k13398 in k13392 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_13403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_13403,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13406,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1117: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[334];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k13404 in k13401 in k13398 in k13392 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_ccall f_13406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_13406,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13409,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1117: chicken.base#get-output-string */
t3=*((C_word*)lf[328]+1);{
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

/* k13407 in k13404 in k13401 in k13398 in k13392 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in ... */
static void C_ccall f_13409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_13409,c,av);}
a=C_alloc(18);
if(C_truep(*((C_word*)lf[10]+1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_list(&a,3,lf[326],t1,lf[306]);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[333],((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_fcall f_13432(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_13432,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13435,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1123: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[338]);
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[337],((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_eqp(((C_word*)t0)[4],lf[339]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13476,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t3)){
t5=t4;
f_13476(t5,t3);}
else{
t5=C_eqp(((C_word*)t0)[4],lf[358]);
if(C_truep(t5)){
t6=t4;
f_13476(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[4],lf[359]);
t7=t4;
f_13476(t7,(C_truep(t6)?t6:C_eqp(((C_word*)t0)[4],lf[360])));}}}}}

/* k13433 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_13435(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_13435,c,av);}
a=C_alloc(42);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[337],t1);
t5=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t6=C_a_i_list(&a,4,lf[314],t1,t4,t5);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,3,lf[315],t3,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_fcall f_13476(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_13476,2,t0,t1);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13479,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1131: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[342]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13521,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t2)){
t4=t3;
f_13521(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[4],lf[356]);
t5=t3;
f_13521(t5,(C_truep(t4)?t4:C_eqp(((C_word*)t0)[4],lf[357])));}}}

/* k13477 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_13479(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(26,c,2)))){
C_save_and_reclaim((void *)f_13479,c,av);}
a=C_alloc(26);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13494,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[10]+1))){
t5=t4;
f_13494(t5,C_a_i_list(&a,2,lf[340],t1));}
else{
t5=C_a_i_list(&a,2,lf[341],t1);
t6=t4;
f_13494(t6,C_a_i_list(&a,2,lf[340],t5));}}

/* k13492 in k13477 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_fcall f_13494(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,0,1)))){
C_save_and_reclaim_args((void *)trf_13494,2,t0,t1);}
a=C_alloc(27);
t2=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t3=C_a_i_list(&a,4,lf[314],((C_word*)t0)[2],t1,t2);
t4=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[315],((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_fcall f_13521(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,2)))){
C_save_and_reclaim_args((void *)trf_13521,2,t0,t1);}
a=C_alloc(18);
if(C_truep(t1)){
if(C_truep(*((C_word*)lf[10]+1))){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,lf[340],((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_a_i_list(&a,2,lf[341],((C_word*)t0)[3]);
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[340],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[343]);
if(C_truep(t2)){
if(C_truep(*((C_word*)lf[10]+1))){
t3=C_a_i_list(&a,2,lf[176],((C_word*)t0)[3]);
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[340],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_a_i_list(&a,2,lf[176],((C_word*)t0)[3]);
t4=C_a_i_list(&a,2,lf[341],t3);
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_list(&a,2,lf[340],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13564,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_symbolp(((C_word*)t0)[4]))){
/* support.scm:1147: lookup-foreign-type */
t4=*((C_word*)lf[300]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t4=t3;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_13564(2,av2);}}}}}

/* k13562 in k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_ccall f_13564(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13564,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13568,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1147: g3243 */
t3=t2;
f_13568(t3,((C_word*)t0)[3],t1);}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t2=C_u_i_car(((C_word*)t0)[4]);
t3=C_eqp(t2,lf[344]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13595,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t3)){
t5=t4;
f_13595(t5,t3);}
else{
t5=C_eqp(t2,lf[354]);
if(C_truep(t5)){
t6=t4;
f_13595(t6,t5);}
else{
t6=C_eqp(t2,lf[355]);
t7=t4;
f_13595(t7,(C_truep(t6)?t6:C_eqp(t2,lf[336])));}}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* g3243 in k13562 in k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in ... */
static void C_fcall f_13568(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_13568,3,t0,t1,t2);}
/* support.scm:1148: next */
t3=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=C_i_vector_ref(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k13593 in k13562 in k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in ... */
static void C_fcall f_13595(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,2)))){
C_save_and_reclaim_args((void *)trf_13595,2,t0,t1);}
a=C_alloc(18);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13598,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1152: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[345]);
t3=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[4],lf[346]));
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13633,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1158: chicken.base#gensym */
t5=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[4],lf[311]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13669,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1164: chicken.base#gensym */
t6=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=C_eqp(((C_word*)t0)[4],lf[316]);
if(C_truep(t5)){
t6=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t6;
av2[1]=(C_truep(*((C_word*)lf[10]+1))?((C_word*)t0)[2]:C_a_i_list(&a,2,lf[312],((C_word*)t0)[2]));
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(((C_word*)t0)[4],lf[349]);
if(C_truep(t6)){
t7=C_a_i_list(&a,2,lf[313],lf[347]);
t8=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t8;
av2[1]=C_a_i_list(&a,3,lf[348],((C_word*)t0)[2],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(((C_word*)t0)[4],lf[350]);
if(C_truep(t7)){
/* support.scm:1177: repeat */
t8=((C_word*)((C_word*)t0)[5])[1];
f_13114(t8,((C_word*)t0)[3],C_i_cadr(((C_word*)t0)[6]));}
else{
t8=C_eqp(((C_word*)t0)[4],lf[351]);
if(C_truep(t8)){
if(C_truep(*((C_word*)lf[10]+1))){
t9=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t9;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=C_a_i_list(&a,3,lf[326],lf[352],lf[306]);
t10=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t10;
av2[1]=C_a_i_list(&a,3,lf[327],((C_word*)t0)[2],t9);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}
else{
t9=C_eqp(((C_word*)t0)[4],lf[353]);
if(C_truep(t9)){
t10=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t10;
av2[1]=(C_truep(t9)?C_a_i_list(&a,2,lf[337],((C_word*)t0)[2]):((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t10=C_eqp(((C_word*)t0)[4],lf[338]);
t11=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t11;
av2[1]=(C_truep(t10)?C_a_i_list(&a,2,lf[337],((C_word*)t0)[2]):((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}}}}}}}}

/* k13596 in k13593 in k13562 in k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in ... */
static void C_ccall f_13598(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_13598,c,av);}
a=C_alloc(42);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[337],t1);
t5=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t6=C_a_i_list(&a,4,lf[314],t1,t4,t5);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,3,lf[315],t3,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k13631 in k13593 in k13562 in k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in ... */
static void C_ccall f_13633(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(51,c,1)))){
C_save_and_reclaim((void *)f_13633,c,av);}
a=C_alloc(51);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[313],lf[347]);
t5=C_a_i_list(&a,3,lf[348],((C_word*)t0)[2],t4);
t6=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t7=C_a_i_list(&a,4,lf[314],t1,t5,t6);
t8=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,3,lf[315],t3,t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* k13667 in k13593 in k13562 in k13519 in k13474 in k13430 in k13386 in k13343 in k13317 in k13275 in k13152 in k13137 in repeat in a13107 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in ... */
static void C_ccall f_13669(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_13669,c,av);}
a=C_alloc(42);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(C_truep(*((C_word*)lf[10]+1))?t1:C_a_i_list(&a,2,lf[312],t1));
t5=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t6=C_a_i_list(&a,4,lf[314],t1,t4,t5);
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,3,lf[315],t3,t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* a14171 in chicken.compiler.support#foreign-type-check in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14172(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_14172,c,av);}
/* support.scm:1189: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[398];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.compiler.support#foreign-type-result-converter in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14178(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_14178,2,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14188,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1196: lookup-foreign-type */
t4=*((C_word*)lf[300]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k14186 in chicken.compiler.support#foreign-type-result-converter in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_14188,c,av);}
if(C_truep(t1)){
t2=C_i_vector_ref(t1,C_fix(2));
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#foreign-type-argument-converter in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14199(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_14199,2,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14209,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1202: lookup-foreign-type */
t4=*((C_word*)lf[300]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k14207 in chicken.compiler.support#foreign-type-argument-converter in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14209(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_14209,c,av);}
if(C_truep(t1)){
t2=C_i_vector_ref(t1,C_fix(1));
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#foreign-type-convert-result in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14220(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_14220,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14224,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1207: foreign-type-result-converter */
f_14178(t4,t3);}

/* k14222 in chicken.compiler.support#foreign-type-convert-result in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_14224,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_a_i_list2(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#foreign-type-convert-argument in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14235(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_14235,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14239,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1212: foreign-type-argument-converter */
f_14199(t4,t3);}

/* k14237 in chicken.compiler.support#foreign-type-convert-argument in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_14239,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_a_i_list2(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#final-foreign-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_14250,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14256,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14283,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1217: follow-without-loop */
f_7372(t1,t2,t3,t4);}

/* a14255 in chicken.compiler.support#final-foreign-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_14256,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14260,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_symbolp(t2))){
/* support.scm:1220: lookup-foreign-type */
t5=*((C_word*)lf[300]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_14260(2,av2);}}}

/* k14258 in a14255 in chicken.compiler.support#final-foreign-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_14260,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14264,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1220: g3338 */
t3=t2;
f_14264(t3,((C_word*)t0)[3],t1);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* g3338 in k14258 in a14255 in chicken.compiler.support#final-foreign-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14264(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_14264,3,t0,t1,t2);}
/* support.scm:1221: next */
t3=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=C_i_vector_ref(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a14282 in chicken.compiler.support#final-foreign-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14283(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_14283,c,av);}
/* support.scm:1223: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[404];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_14289,c,av);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14292,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14301,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14758,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1231: follow-without-loop */
f_7372(t1,t2,t4,t5);}

/* err in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14292(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_14292,2,t0,t1);}
/* support.scm:1230: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[406];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14301(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_14301,c,av);}
a=C_alloc(6);
t4=C_eqp(t2,lf[303]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14311,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t4)){
t6=t5;
f_14311(t6,t4);}
else{
t6=C_eqp(t2,lf[306]);
if(C_truep(t6)){
t7=t5;
f_14311(t7,t6);}
else{
t7=C_eqp(t2,lf[370]);
if(C_truep(t7)){
t8=t5;
f_14311(t8,t7);}
else{
t8=C_eqp(t2,lf[407]);
if(C_truep(t8)){
t9=t5;
f_14311(t9,t8);}
else{
t9=C_eqp(t2,lf[408]);
if(C_truep(t9)){
t10=t5;
f_14311(t10,t9);}
else{
t10=C_eqp(t2,lf[332]);
if(C_truep(t10)){
t11=t5;
f_14311(t11,t10);}
else{
t11=C_eqp(t2,lf[409]);
if(C_truep(t11)){
t12=t5;
f_14311(t12,t11);}
else{
t12=C_eqp(t2,lf[304]);
if(C_truep(t12)){
t13=t5;
f_14311(t13,t12);}
else{
t13=C_eqp(t2,lf[393]);
if(C_truep(t13)){
t14=t5;
f_14311(t14,t13);}
else{
t14=C_eqp(t2,lf[394]);
if(C_truep(t14)){
t15=t5;
f_14311(t15,t14);}
else{
t15=C_eqp(t2,lf[395]);
if(C_truep(t15)){
t16=t5;
f_14311(t16,t15);}
else{
t16=C_eqp(t2,lf[396]);
t17=t5;
f_14311(t17,(C_truep(t16)?t16:C_eqp(t2,lf[397])));}}}}}}}}}}}}

/* k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14311(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_14311,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[339]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14320,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=t3;
f_14320(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[3],lf[342]);
if(C_truep(t4)){
t5=t3;
f_14320(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[3],lf[336]);
if(C_truep(t5)){
t6=t3;
f_14320(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[3],lf[338]);
if(C_truep(t6)){
t7=t3;
f_14320(t7,t6);}
else{
t7=C_eqp(((C_word*)t0)[3],lf[343]);
if(C_truep(t7)){
t8=t3;
f_14320(t8,t7);}
else{
t8=C_eqp(((C_word*)t0)[3],lf[358]);
if(C_truep(t8)){
t9=t3;
f_14320(t9,t8);}
else{
t9=C_eqp(((C_word*)t0)[3],lf[356]);
if(C_truep(t9)){
t10=t3;
f_14320(t10,t9);}
else{
t10=C_eqp(((C_word*)t0)[3],lf[359]);
if(C_truep(t10)){
t11=t3;
f_14320(t11,t10);}
else{
t11=C_eqp(((C_word*)t0)[3],lf[360]);
if(C_truep(t11)){
t12=t3;
f_14320(t12,t11);}
else{
t12=C_eqp(((C_word*)t0)[3],lf[357]);
if(C_truep(t12)){
t13=t3;
f_14320(t13,t12);}
else{
t13=C_eqp(((C_word*)t0)[3],lf[361]);
t14=t3;
f_14320(t14,(C_truep(t13)?t13:C_eqp(((C_word*)t0)[3],lf[362])));}}}}}}}}}}}}

/* k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14320(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_14320,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
/* support.scm:1241: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(3);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[364]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14332,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=t3;
f_14332(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[3],lf[371]);
if(C_truep(t4)){
t5=t3;
f_14332(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[3],lf[369]);
if(C_truep(t5)){
t6=t3;
f_14332(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[3],lf[363]);
if(C_truep(t6)){
t7=t3;
f_14332(t7,t6);}
else{
t7=C_eqp(((C_word*)t0)[3],lf[324]);
t8=t3;
f_14332(t8,(C_truep(t7)?t7:C_eqp(((C_word*)t0)[3],lf[366])));}}}}}}

/* k14330 in k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14332(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_14332,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
/* support.scm:1243: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(6);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[308]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14344,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=t3;
f_14344(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[3],lf[391]);
t5=t3;
f_14344(t5,(C_truep(t4)?t4:C_eqp(((C_word*)t0)[3],lf[392])));}}}

/* k14342 in k14330 in k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14344(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_14344,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
/* support.scm:1245: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(4);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[368]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14356,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=t3;
f_14356(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[3],lf[367]);
if(C_truep(t4)){
t5=t3;
f_14356(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[3],lf[365]);
t6=t3;
f_14356(t6,(C_truep(t5)?t5:C_eqp(((C_word*)t0)[3],lf[372])));}}}}

/* k14354 in k14342 in k14330 in k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14356(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_14356,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
/* support.scm:1247: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(7);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14362,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_symbolp(((C_word*)t0)[4]))){
/* support.scm:1249: lookup-foreign-type */
t3=*((C_word*)lf[300]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_14362(2,av2);}}}}

/* k14360 in k14354 in k14342 in k14330 in k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14362(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_14362,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14366,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1249: g3459 */
t3=t2;
f_14366(t3,((C_word*)t0)[3],t1);}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t2=C_u_i_car(((C_word*)t0)[4]);
t3=C_eqp(t2,lf[344]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14393,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t3)){
t5=t4;
f_14393(t5,t3);}
else{
t5=C_eqp(t2,lf[353]);
if(C_truep(t5)){
t6=t4;
f_14393(t6,t5);}
else{
t6=C_eqp(t2,lf[354]);
if(C_truep(t6)){
t7=t4;
f_14393(t7,t6);}
else{
t7=C_eqp(t2,lf[336]);
if(C_truep(t7)){
t8=t4;
f_14393(t8,t7);}
else{
t8=C_eqp(t2,lf[338]);
if(C_truep(t8)){
t9=t4;
f_14393(t9,t8);}
else{
t9=C_eqp(t2,lf[355]);
if(C_truep(t9)){
t10=t4;
f_14393(t10,t9);}
else{
t10=C_eqp(t2,lf[345]);
if(C_truep(t10)){
t11=t4;
f_14393(t11,t10);}
else{
t11=C_eqp(t2,lf[346]);
t12=t4;
f_14393(t12,(C_truep(t11)?t11:C_eqp(t2,lf[349])));}}}}}}}}
else{
/* support.scm:1258: err */
t2=((C_word*)t0)[5];
f_14292(t2,((C_word*)t0)[3]);}}}

/* g3459 in k14360 in k14354 in k14342 in k14330 in k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_14366(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_14366,3,t0,t1,t2);}
/* support.scm:1250: next */
t3=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=C_i_vector_ref(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k14391 in k14360 in k14354 in k14342 in k14330 in k14318 in k14309 in a14300 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_14393(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_14393,2,t0,t1);}
if(C_truep(t1)){
/* support.scm:1254: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(3);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[350]);
if(C_truep(t2)){
/* support.scm:1255: next */
t3=((C_word*)t0)[4];{
C_word av2[3];
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cadr(((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=C_eqp(((C_word*)t0)[3],lf[351]);
if(C_truep(t3)){
/* support.scm:1256: words->bytes */
t4=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(6);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* support.scm:1257: err */
t4=((C_word*)t0)[6];
f_14292(t4,((C_word*)t0)[2]);}}}}

/* a14757 in chicken.compiler.support#estimate-foreign-result-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14758(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_14758,c,av);}
/* support.scm:1259: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[410];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14764(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_14764,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14776,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_15208,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1264: follow-without-loop */
f_7372(t1,t2,t3,t4);}

/* a14775 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14776(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_14776,c,av);}
a=C_alloc(5);
t4=C_eqp(t2,lf[303]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14786,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t4)){
t6=t5;
f_14786(t6,t4);}
else{
t6=C_eqp(t2,lf[306]);
if(C_truep(t6)){
t7=t5;
f_14786(t7,t6);}
else{
t7=C_eqp(t2,lf[370]);
if(C_truep(t7)){
t8=t5;
f_14786(t8,t7);}
else{
t8=C_eqp(t2,lf[407]);
if(C_truep(t8)){
t9=t5;
f_14786(t9,t8);}
else{
t9=C_eqp(t2,lf[332]);
if(C_truep(t9)){
t10=t5;
f_14786(t10,t9);}
else{
t10=C_eqp(t2,lf[304]);
if(C_truep(t10)){
t11=t5;
f_14786(t11,t10);}
else{
t11=C_eqp(t2,lf[393]);
if(C_truep(t11)){
t12=t5;
f_14786(t12,t11);}
else{
t12=C_eqp(t2,lf[371]);
if(C_truep(t12)){
t13=t5;
f_14786(t13,t12);}
else{
t13=C_eqp(t2,lf[363]);
if(C_truep(t13)){
t14=t5;
f_14786(t14,t13);}
else{
t14=C_eqp(t2,lf[394]);
if(C_truep(t14)){
t15=t5;
f_14786(t15,t14);}
else{
t15=C_eqp(t2,lf[395]);
if(C_truep(t15)){
t16=t5;
f_14786(t16,t15);}
else{
t16=C_eqp(t2,lf[336]);
if(C_truep(t16)){
t17=t5;
f_14786(t17,t16);}
else{
t17=C_eqp(t2,lf[338]);
if(C_truep(t17)){
t18=t5;
f_14786(t18,t17);}
else{
t18=C_eqp(t2,lf[364]);
if(C_truep(t18)){
t19=t5;
f_14786(t19,t18);}
else{
t19=C_eqp(t2,lf[369]);
if(C_truep(t19)){
t20=t5;
f_14786(t20,t19);}
else{
t20=C_eqp(t2,lf[308]);
if(C_truep(t20)){
t21=t5;
f_14786(t21,t20);}
else{
t21=C_eqp(t2,lf[339]);
if(C_truep(t21)){
t22=t5;
f_14786(t22,t21);}
else{
t22=C_eqp(t2,lf[343]);
if(C_truep(t22)){
t23=t5;
f_14786(t23,t22);}
else{
t23=C_eqp(t2,lf[311]);
if(C_truep(t23)){
t24=t5;
f_14786(t24,t23);}
else{
t24=C_eqp(t2,lf[316]);
if(C_truep(t24)){
t25=t5;
f_14786(t25,t24);}
else{
t25=C_eqp(t2,lf[396]);
if(C_truep(t25)){
t26=t5;
f_14786(t26,t25);}
else{
t26=C_eqp(t2,lf[397]);
if(C_truep(t26)){
t27=t5;
f_14786(t27,t26);}
else{
t27=C_eqp(t2,lf[324]);
if(C_truep(t27)){
t28=t5;
f_14786(t28,t27);}
else{
t28=C_eqp(t2,lf[366]);
if(C_truep(t28)){
t29=t5;
f_14786(t29,t28);}
else{
t29=C_eqp(t2,lf[359]);
if(C_truep(t29)){
t30=t5;
f_14786(t30,t29);}
else{
t30=C_eqp(t2,lf[360]);
if(C_truep(t30)){
t31=t5;
f_14786(t31,t30);}
else{
t31=C_eqp(t2,lf[357]);
if(C_truep(t31)){
t32=t5;
f_14786(t32,t31);}
else{
t32=C_eqp(t2,lf[342]);
if(C_truep(t32)){
t33=t5;
f_14786(t33,t32);}
else{
t33=C_eqp(t2,lf[358]);
if(C_truep(t33)){
t34=t5;
f_14786(t34,t33);}
else{
t34=C_eqp(t2,lf[356]);
if(C_truep(t34)){
t35=t5;
f_14786(t35,t34);}
else{
t35=C_eqp(t2,lf[361]);
t36=t5;
f_14786(t36,(C_truep(t35)?t35:C_eqp(t2,lf[362])));}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}

/* k14784 in a14775 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14786(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_14786,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
/* support.scm:1273: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[391]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14798,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t2)){
t4=t3;
f_14798(t4,t2);}
else{
t4=C_eqp(((C_word*)t0)[3],lf[368]);
if(C_truep(t4)){
t5=t3;
f_14798(t5,t4);}
else{
t5=C_eqp(((C_word*)t0)[3],lf[367]);
if(C_truep(t5)){
t6=t3;
f_14798(t6,t5);}
else{
t6=C_eqp(((C_word*)t0)[3],lf[365]);
t7=t3;
f_14798(t7,(C_truep(t6)?t6:C_eqp(((C_word*)t0)[3],lf[372])));}}}}}

/* k14796 in k14784 in a14775 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14798(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_14798,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
/* support.scm:1275: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(2);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14804,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_symbolp(((C_word*)t0)[4]))){
/* support.scm:1277: lookup-foreign-type */
t3=*((C_word*)lf[300]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=t2;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_14804(2,av2);}}}}

/* k14802 in k14796 in k14784 in a14775 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_14804(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_14804,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14808,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1277: g3617 */
t3=t2;
f_14808(t3,((C_word*)t0)[3],t1);}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t2=C_u_i_car(((C_word*)t0)[4]);
t3=C_eqp(t2,lf[344]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14835,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
t5=t4;
f_14835(t5,t3);}
else{
t5=C_eqp(t2,lf[353]);
if(C_truep(t5)){
t6=t4;
f_14835(t6,t5);}
else{
t6=C_eqp(t2,lf[354]);
if(C_truep(t6)){
t7=t4;
f_14835(t7,t6);}
else{
t7=C_eqp(t2,lf[336]);
if(C_truep(t7)){
t8=t4;
f_14835(t8,t7);}
else{
t8=C_eqp(t2,lf[338]);
if(C_truep(t8)){
t9=t4;
f_14835(t9,t8);}
else{
t9=C_eqp(t2,lf[355]);
if(C_truep(t9)){
t10=t4;
f_14835(t10,t9);}
else{
t10=C_eqp(t2,lf[311]);
if(C_truep(t10)){
t11=t4;
f_14835(t11,t10);}
else{
t11=C_eqp(t2,lf[316]);
t12=t4;
f_14835(t12,(C_truep(t11)?t11:C_eqp(t2,lf[351])));}}}}}}}}
else{
/* support.scm:1263: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[412];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}}

/* g3617 in k14802 in k14796 in k14784 in a14775 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14808(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_14808,3,t0,t1,t2);}
/* support.scm:1278: next */
t3=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=C_i_vector_ref(t2,C_fix(0));
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k14833 in k14802 in k14796 in k14784 in a14775 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_14835(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_14835,2,t0,t1);}
if(C_truep(t1)){
/* support.scm:1283: words->bytes */
t2=*((C_word*)lf[68]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(1);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[350]);
if(C_truep(t2)){
/* support.scm:1284: next */
t3=((C_word*)t0)[4];{
C_word av2[3];
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cadr(((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
/* support.scm:1263: quit-compiling */
t3=*((C_word*)lf[37]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[412];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}}

/* a15207 in chicken.compiler.support#estimate-foreign-result-location-size in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_15208,c,av);}
/* support.scm:1287: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[413];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* chicken.compiler.support#finish-foreign-result in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15214(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_15214,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_15218,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1293: chicken.syntax#strip-syntax */
t5=*((C_word*)lf[427]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k15216 in chicken.compiler.support#finish-foreign-result in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15218(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_15218,c,av);}
a=C_alloc(21);
t2=C_eqp(t1,lf[339]);
t3=(C_truep(t2)?t2:C_eqp(t1,lf[359]));
if(C_truep(t3)){
t4=C_a_i_list(&a,2,lf[313],C_fix(0));
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[415],((C_word*)t0)[3],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_eqp(t1,lf[342]);
if(C_truep(t4)){
t5=C_a_i_list(&a,2,lf[313],C_fix(0));
t6=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[416],((C_word*)t0)[3],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=C_eqp(t1,lf[358]);
t6=(C_truep(t5)?t5:C_eqp(t1,lf[360]));
if(C_truep(t6)){
t7=C_a_i_list(&a,2,lf[313],C_fix(0));
t8=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,3,lf[417],((C_word*)t0)[3],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(t1,lf[356]);
t8=(C_truep(t7)?t7:C_eqp(t1,lf[357]));
if(C_truep(t8)){
t9=C_a_i_list(&a,2,lf[313],C_fix(0));
t10=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_a_i_list(&a,3,lf[418],((C_word*)t0)[3],t9);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t9=C_eqp(t1,lf[343]);
if(C_truep(t9)){
t10=C_a_i_list(&a,2,lf[313],C_fix(0));
t11=C_a_i_list(&a,3,lf[415],((C_word*)t0)[3],t10);
t12=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list(&a,2,lf[419],t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t10=C_eqp(t1,lf[361]);
if(C_truep(t10)){
t11=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t12=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list(&a,3,lf[420],((C_word*)t0)[3],t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t11=C_eqp(t1,lf[362]);
if(C_truep(t11)){
t12=C_a_i_list(&a,2,lf[313],C_SCHEME_FALSE);
t13=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t13;
av2[1]=C_a_i_list(&a,3,lf[421],((C_word*)t0)[3],t12);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}
else{
if(C_truep(C_i_listp(t1))){
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_15334,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t13=C_i_car(t1);
t14=C_eqp(t13,lf[350]);
if(C_truep(t14)){
t15=C_i_length(t1);
t16=C_eqp(C_fix(2),t15);
t17=t12;
f_15334(t17,(C_truep(t16)?C_u_i_memq(C_i_cadr(t1),lf[426]):C_SCHEME_FALSE));}
else{
t15=t12;
f_15334(t15,C_SCHEME_FALSE);}}
else{
t12=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t12;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}}}}}}}}}

/* k15332 in k15216 in chicken.compiler.support#finish-foreign-result in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_15334(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_15334,2,t0,t1);}
a=C_alloc(18);
if(C_truep(t1)){
/* support.scm:1310: finish-foreign-result */
t2=*((C_word*)lf[414]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_i_length(((C_word*)t0)[3]);
t3=C_eqp(C_fix(3),t2);
if(C_truep(t3)){
t4=C_i_car(((C_word*)t0)[3]);
t5=C_eqp(t4,lf[345]);
t6=(C_truep(t5)?t5:C_eqp(t4,lf[346]));
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_15362,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1314: chicken.base#gensym */
t8=*((C_word*)lf[98]+1);{
C_word av2[2];
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(t4,lf[349]);
if(C_truep(t7)){
t8=C_i_caddr(((C_word*)t0)[3]);
t9=C_a_i_list(&a,2,lf[313],lf[347]);
t10=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t10;
av2[1]=C_a_i_list(&a,4,lf[424],t8,t9,((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t8=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t8;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}}
else{
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}

/* k15360 in k15332 in k15216 in chicken.compiler.support#finish-foreign-result in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15362(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(60,c,1)))){
C_save_and_reclaim((void *)f_15362,c,av);}
a=C_alloc(60);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,lf[422],t1);
t5=C_a_i_list(&a,2,lf[423],t4);
t6=C_i_caddr(((C_word*)t0)[3]);
t7=C_a_i_list(&a,2,lf[313],lf[347]);
t8=C_a_i_list(&a,4,lf[424],t6,t7,t1);
t9=C_a_i_list(&a,4,lf[425],t1,t5,t8);
t10=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_a_i_list(&a,3,lf[97],t3,t9);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}

/* chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_15482,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_15489,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=C_eqp(t3,lf[430]);
if(C_truep(t5)){
/* support.scm:1333: foreign-type-argument-converter */
f_14199(t4,t2);}
else{
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_15489(2,av2);}}}

/* k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15489(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_15489,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_15492,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_15492(2,av2);}}
else{
t3=C_eqp(((C_word*)t0)[3],lf[455]);
if(C_truep(t3)){
/* support.scm:1334: foreign-type-result-converter */
f_14178(t2,((C_word*)t0)[4]);}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_15492(2,av2);}}}}

/* k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15492(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_15492,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[165];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_15495,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1338: final-foreign-type */
t3=*((C_word*)lf[403]+1);{
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

/* k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_15495(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_15495,c,av);}
a=C_alloc(6);
t2=C_eqp(t1,lf[408]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[429];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_eqp(t1,lf[303]);
t4=(C_truep(t3)?t3:C_eqp(t1,lf[304]));
if(C_truep(t4)){
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=lf[303];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(t1,lf[306]);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_15519,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t5)){
t7=t6;
f_15519(t7,t5);}
else{
t7=C_eqp(t1,lf[393]);
if(C_truep(t7)){
t8=t6;
f_15519(t8,t7);}
else{
t8=C_eqp(t1,lf[370]);
if(C_truep(t8)){
t9=t6;
f_15519(t9,t8);}
else{
t9=C_eqp(t1,lf[332]);
if(C_truep(t9)){
t10=t6;
f_15519(t10,t9);}
else{
t10=C_eqp(t1,lf[394]);
if(C_truep(t10)){
t11=t6;
f_15519(t11,t10);}
else{
t11=C_eqp(t1,lf[395]);
if(C_truep(t11)){
t12=t6;
f_15519(t12,t11);}
else{
t12=C_eqp(t1,lf[396]);
t13=t6;
f_15519(t13,(C_truep(t12)?t12:C_eqp(t1,lf[397])));}}}}}}}}}

/* k15517 in k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_15519(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_15519,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=lf[159];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[308]);
t3=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[3],lf[391]));
if(C_truep(t3)){
t4=C_eqp(((C_word*)t0)[4],lf[430]);
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=(C_truep(t4)?lf[392]:lf[308]);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[3],lf[311]);
t5=(C_truep(t4)?t4:C_eqp(((C_word*)t0)[3],lf[316]));
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t6;
av2[1]=lf[165];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(((C_word*)t0)[3],lf[310]);
if(C_truep(t6)){
t7=C_eqp(((C_word*)t0)[4],lf[430]);
t8=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t8;
av2[1]=(C_truep(t7)?lf[431]:lf[310]);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t7=C_eqp(((C_word*)t0)[3],lf[317]);
if(C_truep(t7)){
t8=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t8;
av2[1]=lf[310];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_eqp(((C_word*)t0)[3],lf[318]);
if(C_truep(t8)){
t9=C_eqp(((C_word*)t0)[4],lf[430]);
t10=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t10;
av2[1]=(C_truep(t9)?lf[432]:lf[318]);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t9=C_eqp(((C_word*)t0)[3],lf[320]);
if(C_truep(t9)){
t10=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t10;
av2[1]=lf[318];
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t10=C_eqp(((C_word*)t0)[3],lf[321]);
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_15594,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t10)){
t12=t11;
f_15594(t12,t10);}
else{
t12=C_eqp(((C_word*)t0)[3],lf[382]);
if(C_truep(t12)){
t13=t11;
f_15594(t13,t12);}
else{
t13=C_eqp(((C_word*)t0)[3],lf[383]);
if(C_truep(t13)){
t14=t11;
f_15594(t14,t13);}
else{
t14=C_eqp(((C_word*)t0)[3],lf[384]);
if(C_truep(t14)){
t15=t11;
f_15594(t15,t14);}
else{
t15=C_eqp(((C_word*)t0)[3],lf[385]);
if(C_truep(t15)){
t16=t11;
f_15594(t16,t15);}
else{
t16=C_eqp(((C_word*)t0)[3],lf[386]);
if(C_truep(t16)){
t17=t11;
f_15594(t17,t16);}
else{
t17=C_eqp(((C_word*)t0)[3],lf[387]);
if(C_truep(t17)){
t18=t11;
f_15594(t18,t17);}
else{
t18=C_eqp(((C_word*)t0)[3],lf[388]);
if(C_truep(t18)){
t19=t11;
f_15594(t19,t18);}
else{
t19=C_eqp(((C_word*)t0)[3],lf[389]);
t20=t11;
f_15594(t20,(C_truep(t19)?t19:C_eqp(((C_word*)t0)[3],lf[390])));}}}}}}}}}}}}}}}}

/* k15592 in k15517 in k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_15594(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,2)))){
C_save_and_reclaim_args((void *)trf_15594,2,t0,t1);}
a=C_alloc(15);
if(C_truep(t1)){
t2=C_eqp(((C_word*)t0)[2],lf[430]);
if(C_truep(t2)){
t3=C_a_i_list(&a,2,lf[433],((C_word*)t0)[3]);
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[434],lf[435],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[433],((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[322]);
if(C_truep(t2)){
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[436];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_eqp(((C_word*)t0)[3],lf[374]);
if(C_truep(t3)){
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=lf[437];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[3],lf[373]);
if(C_truep(t4)){
t5=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t5;
av2[1]=lf[438];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(((C_word*)t0)[3],lf[375]);
if(C_truep(t5)){
t6=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t6;
av2[1]=lf[439];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(((C_word*)t0)[3],lf[376]);
if(C_truep(t6)){
t7=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t7;
av2[1]=lf[440];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_eqp(((C_word*)t0)[3],lf[377]);
if(C_truep(t7)){
t8=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t8;
av2[1]=lf[441];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_eqp(((C_word*)t0)[3],lf[378]);
if(C_truep(t8)){
t9=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t9;
av2[1]=lf[442];
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=C_eqp(((C_word*)t0)[3],lf[379]);
if(C_truep(t9)){
t10=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t10;
av2[1]=lf[443];
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t10=C_eqp(((C_word*)t0)[3],lf[380]);
if(C_truep(t10)){
t11=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t11;
av2[1]=lf[444];
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
t11=C_eqp(((C_word*)t0)[3],lf[381]);
if(C_truep(t11)){
t12=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t12;
av2[1]=lf[445];
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t12=C_eqp(((C_word*)t0)[3],lf[369]);
t13=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_15681,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t12)){
t14=t13;
f_15681(t14,t12);}
else{
t14=C_eqp(((C_word*)t0)[3],lf[371]);
if(C_truep(t14)){
t15=t13;
f_15681(t15,t14);}
else{
t15=C_eqp(((C_word*)t0)[3],lf[365]);
if(C_truep(t15)){
t16=t13;
f_15681(t16,t15);}
else{
t16=C_eqp(((C_word*)t0)[3],lf[372]);
if(C_truep(t16)){
t17=t13;
f_15681(t17,t16);}
else{
t17=C_eqp(((C_word*)t0)[3],lf[324]);
if(C_truep(t17)){
t18=t13;
f_15681(t18,t17);}
else{
t18=C_eqp(((C_word*)t0)[3],lf[366]);
if(C_truep(t18)){
t19=t13;
f_15681(t19,t18);}
else{
t19=C_eqp(((C_word*)t0)[3],lf[368]);
if(C_truep(t19)){
t20=t13;
f_15681(t20,t19);}
else{
t20=C_eqp(((C_word*)t0)[3],lf[367]);
t21=t13;
f_15681(t21,(C_truep(t20)?t20:C_eqp(((C_word*)t0)[3],lf[363])));}}}}}}}}}}}}}}}}}}}

/* k15679 in k15592 in k15517 in k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_15681(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_15681,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=lf[369];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[336]);
if(C_truep(t2)){
t3=C_eqp(lf[430],((C_word*)t0)[4]);
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=(C_truep(t3)?lf[446]:lf[447]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_eqp(((C_word*)t0)[3],lf[338]);
if(C_truep(t3)){
t4=C_eqp(lf[430],((C_word*)t0)[4]);
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=(C_truep(t4)?lf[448]:lf[354]);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[3],lf[339]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_15714,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t4)){
t6=t5;
f_15714(t6,t4);}
else{
t6=C_eqp(((C_word*)t0)[3],lf[358]);
if(C_truep(t6)){
t7=t5;
f_15714(t7,t6);}
else{
t7=C_eqp(((C_word*)t0)[3],lf[359]);
t8=t5;
f_15714(t8,(C_truep(t7)?t7:C_eqp(((C_word*)t0)[3],lf[360])));}}}}}}

/* k15712 in k15679 in k15592 in k15517 in k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_15714(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_15714,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=lf[449];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[361]);
t3=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[3],lf[362]));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=lf[450];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[3],lf[342]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_15732,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t4)){
t6=t5;
f_15732(t6,t4);}
else{
t6=C_eqp(((C_word*)t0)[3],lf[356]);
t7=t5;
f_15732(t7,(C_truep(t6)?t6:C_eqp(((C_word*)t0)[3],lf[357])));}}}}

/* k15730 in k15712 in k15679 in k15592 in k15517 in k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_fcall f_15732(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_15732,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=lf[451];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[343]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[343];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t3=C_u_i_car(((C_word*)t0)[4]);
t4=C_eqp(t3,lf[344]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_15754,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=t3,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t4)){
t6=t5;
f_15754(t6,t4);}
else{
t6=C_eqp(t3,lf[354]);
if(C_truep(t6)){
t7=t5;
f_15754(t7,t6);}
else{
t7=C_eqp(t3,lf[355]);
t8=t5;
f_15754(t8,(C_truep(t7)?t7:C_eqp(t3,lf[336])));}}}
else{
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[165];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}}

/* k15752 in k15730 in k15712 in k15679 in k15592 in k15517 in k15493 in k15490 in k15487 in chicken.compiler.support#foreign-type->scrutiny-type in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_fcall f_15754(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_15754,2,t0,t1);}
if(C_truep(t1)){
t2=C_eqp(lf[430],((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t3;
av2[1]=(C_truep(t2)?lf[452]:lf[453]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[350]);
if(C_truep(t2)){
/* support.scm:1397: foreign-type->scrutiny-type */
t3=*((C_word*)lf[428]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=C_i_cadr(((C_word*)t0)[5]);
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=C_eqp(((C_word*)t0)[4],lf[351]);
if(C_truep(t3)){
t4=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t4;
av2[1]=lf[369];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[4],lf[353]);
t5=(C_truep(t4)?t4:C_eqp(((C_word*)t0)[4],lf[338]));
if(C_truep(t5)){
t6=C_eqp(lf[430],((C_word*)t0)[2]);
t7=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t7;
av2[1]=(C_truep(t6)?lf[454]:lf[354]);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t6=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t6;
av2[1]=lf[165];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}}}}

/* chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16136(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_16136,c,av);}
a=C_alloc(13);
t4=C_SCHEME_END_OF_LIST;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16140,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16142,a[2]=t8,a[3]=t3,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_16142(t10,t6,t2);}

/* k16138 in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16140(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16140,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16142(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_16142,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_slot(t2,C_fix(3));
t4=C_slot(t2,C_fix(1));
t5=C_eqp(t4,lf[149]);
t6=(C_truep(t5)?t5:C_eqp(t4,lf[124]));
if(C_truep(t6)){
t7=C_slot(t2,C_fix(2));
t8=C_i_car(t7);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16174,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t10=C_i_memq(t8,((C_word*)t0)[3]);
t11=(C_truep(t10)?C_i_not(C_i_memq(t8,((C_word*)((C_word*)t0)[4])[1])):C_SCHEME_FALSE);
if(C_truep(t11)){
t12=C_a_i_cons(&a,2,t8,((C_word*)((C_word*)t0)[4])[1]);
t13=C_mutate(((C_word *)((C_word*)t0)[4])+1,t12);
t14=t9;
f_16174(t14,t13);}
else{
t12=t9;
f_16174(t12,C_SCHEME_UNDEFINED);}}
else{
t7=C_eqp(t4,lf[86]);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16238,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t7)){
t9=t8;
f_16238(t9,t7);}
else{
t9=C_eqp(t4,lf[154]);
t10=t8;
f_16238(t10,(C_truep(t9)?t9:C_eqp(t4,lf[166])));}}}

/* k16172 in walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16174(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_16174,2,t0,t1);}
a=C_alloc(6);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[44]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16182,a[2]=t4,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_16182(t6,((C_word*)t0)[4],((C_word*)t0)[2]);}

/* for-each-loop3903 in k16172 in walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16182(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_16182,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16192,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1418: g3904 */
t4=((C_word*)((C_word*)t0)[3])[1];
f_16142(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k16190 in for-each-loop3903 in k16172 in walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16192(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_16192,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_16182(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k16236 in walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16238(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_16238,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_check_list_2(((C_word*)t0)[3],lf[44]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16246,a[2]=t4,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_16246(t6,((C_word*)t0)[2],((C_word*)t0)[3]);}}

/* for-each-loop3928 in k16236 in walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16246(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_16246,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16256,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1420: g3929 */
t4=((C_word*)((C_word*)t0)[3])[1];
f_16142(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k16254 in for-each-loop3928 in k16236 in walk in chicken.compiler.support#scan-used-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16256(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_16256,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_16246(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16291(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(23,c,4)))){
C_save_and_reclaim((void *)f_16291,c,av);}
a=C_alloc(23);
t4=C_SCHEME_END_OF_LIST;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_END_OF_LIST;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_16294,a[2]=t5,a[3]=t7,a[4]=t3,a[5]=t9,a[6]=t11,tmp=(C_word)a,a+=7,tmp));
t13=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16478,a[2]=t9,tmp=(C_word)a,a+=3,tmp));
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16516,a[2]=t1,a[3]=t5,a[4]=t7,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1458: walk */
t15=((C_word*)t9)[1];
f_16294(t15,t14,t2,C_SCHEME_END_OF_LIST);}

/* walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16294(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_16294,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_slot(t2,C_fix(3));
t5=C_slot(t2,C_fix(2));
t6=C_slot(t2,C_fix(1));
t7=C_eqp(t6,lf[86]);
t8=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_16328,a[2]=t1,a[3]=t6,a[4]=t5,a[5]=t3,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=t4,a[11]=((C_word*)t0)[6],tmp=(C_word)a,a+=12,tmp);
if(C_truep(t7)){
t9=t8;
f_16328(t9,t7);}
else{
t9=C_eqp(t6,lf[154]);
if(C_truep(t9)){
t10=t8;
f_16328(t10,t9);}
else{
t10=C_eqp(t6,lf[166]);
if(C_truep(t10)){
t11=t8;
f_16328(t11,t10);}
else{
t11=C_eqp(t6,lf[169]);
t12=t8;
f_16328(t12,(C_truep(t11)?t11:C_eqp(t6,lf[180])));}}}}

/* k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16328(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,5)))){
C_save_and_reclaim_args((void *)trf_16328,2,t0,t1);}
a=C_alloc(10);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[3],lf[149]);
if(C_truep(t2)){
t3=C_i_car(((C_word*)t0)[4]);
if(C_truep(C_i_memq(t3,((C_word*)t0)[5]))){
t4=C_SCHEME_UNDEFINED;
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_16347,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[7],a[5]=t3,a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* support.scm:1438: lset-adjoin/eq? */
f_6129(t4,((C_word*)((C_word*)t0)[6])[1],C_a_i_list(&a,1,t3));}}
else{
t3=C_eqp(((C_word*)t0)[3],lf[124]);
if(C_truep(t3)){
t4=C_i_car(((C_word*)t0)[4]);
if(C_truep(C_i_memq(t4,((C_word*)t0)[5]))){
/* support.scm:1444: walk */
t5=((C_word*)((C_word*)t0)[9])[1];
f_16294(t5,((C_word*)t0)[2],C_i_car(((C_word*)t0)[10]),((C_word*)t0)[5]);}
else{
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_16383,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* support.scm:1443: lset-adjoin/eq? */
f_6129(t5,((C_word*)((C_word*)t0)[6])[1],C_a_i_list(&a,1,t4));}}
else{
t4=C_eqp(((C_word*)t0)[3],lf[97]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_16392,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* support.scm:1446: walk */
t6=((C_word*)((C_word*)t0)[9])[1];
f_16294(t6,t5,C_i_car(((C_word*)t0)[10]),((C_word*)t0)[5]);}
else{
t5=C_eqp(((C_word*)t0)[3],lf[118]);
if(C_truep(t5)){
t6=C_i_caddr(((C_word*)t0)[4]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16422,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[9],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1449: ##sys#decompose-lambda-list */
t8=*((C_word*)lf[221]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=((C_word*)t0)[2];
av2[2]=t6;
av2[3]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
/* support.scm:1453: walkeach */
t6=((C_word*)((C_word*)t0)[11])[1];
f_16478(t6,((C_word*)t0)[2],((C_word*)t0)[10],((C_word*)t0)[5]);}}}}}}

/* k16345 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_16347,c,av);}
a=C_alloc(5);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16353,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1439: variable-visible? */
t4=*((C_word*)lf[256]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k16351 in k16345 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16353(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_16353,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16357,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1440: lset-adjoin/eq? */
f_6129(t2,((C_word*)((C_word*)t0)[3])[1],C_a_i_list(&a,1,((C_word*)t0)[4]));}}

/* k16355 in k16351 in k16345 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16357(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16357,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k16381 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16383,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* support.scm:1444: walk */
t3=((C_word*)((C_word*)t0)[3])[1];
f_16294(t3,((C_word*)t0)[4],C_i_car(((C_word*)t0)[5]),((C_word*)t0)[6]);}

/* k16390 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_16392,c,av);}
a=C_alloc(5);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16403,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1447: scheme#append */
t4=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k16401 in k16390 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16403(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16403,c,av);}
/* support.scm:1447: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_16294(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* a16421 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16422(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_16422,c,av);}
a=C_alloc(5);
t5=C_i_car(((C_word*)t0)[2]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16434,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1452: scheme#append */
t7=*((C_word*)lf[58]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* k16432 in a16421 in k16326 in walk in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16434(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16434,c,av);}
/* support.scm:1452: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_16294(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* walkeach in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16478(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_16478,4,t0,t1,t2,t3);}
a=C_alloc(10);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16480,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_i_check_list_2(t2,lf[44]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16492,a[2]=t7,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_16492(t9,t1,t2);}

/* g3996 in walkeach in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16480(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_16480,3,t0,t1,t2);}
/* support.scm:1456: walk */
t3=((C_word*)((C_word*)t0)[2])[1];
f_16294(t3,t1,t2,((C_word*)t0)[3]);}

/* for-each-loop3995 in walkeach in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16492(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_16492,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16502,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1456: g3996 */
t4=((C_word*)t0)[3];
f_16480(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k16500 in for-each-loop3995 in walkeach in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16502(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_16502,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_16492(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k16514 in chicken.compiler.support#scan-free-variables in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16516(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16516,c,av);}
/* support.scm:1459: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=((C_word*)((C_word*)t0)[4])[1];
C_values(4,av2);}}

/* chicken.compiler.support#make-block-variable-literal in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_16522,c,av);}
a=C_alloc(3);
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record2(&a,2,lf[459],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#block-variable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16528,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_structurep(t2,lf[459]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#block-variable-literal-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16534(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16534,c,av);}
t3=C_i_check_structure_2(t2,lf[459],lf[462]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16543(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_16543,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16551,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1475: chicken.base#open-output-string */
t4=*((C_word*)lf[331]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_16551,c,av);}
a=C_alloc(8);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[325]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16557,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16578,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[3]))){
/* support.scm:1476: chicken.base#gensym */
t5=*((C_word*)lf[98]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* support.scm:1475: ##sys#print */
t5=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=C_i_car(((C_word*)t0)[3]);
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k16555 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16557(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_16557,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16560,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1475: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(45);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k16558 in k16555 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_16560,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16563,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16574,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1477: chicken.time#current-seconds */
t4=*((C_word*)lf[464]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k16561 in k16558 in k16555 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_16563,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16566,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1475: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_random_fixnum(C_fix(1000));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k16564 in k16561 in k16558 in k16555 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_16566,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16569,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1475: chicken.base#get-output-string */
t3=*((C_word*)lf[328]+1);{
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

/* k16567 in k16564 in k16561 in k16558 in k16555 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_16569,c,av);}
/* support.scm:1474: scheme#string->symbol */
t2=*((C_word*)lf[463]+1);{
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

/* k16572 in k16558 in k16555 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_16574,c,av);}
/* support.scm:1475: ##sys#print */
t2=*((C_word*)lf[27]+1);{
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

/* k16576 in k16549 in chicken.compiler.support#make-random-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16578(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_16578,c,av);}
/* support.scm:1475: ##sys#print */
t2=*((C_word*)lf[27]+1);{
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

/* chicken.compiler.support#clear-real-name-table! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_16590,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16595,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1493: scheme#make-vector */
t3=*((C_word*)lf[298]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_fix(997);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k16593 in chicken.compiler.support#clear-real-name-table! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16595,c,av);}
t2=C_mutate(&lf[465] /* (set! chicken.compiler.support#real-name-table ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#set-real-name! in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_16597,c,av);}
/* support.scm:1496: chicken.internal#hash-table-set! */
t4=*((C_word*)lf[132]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[465];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* chicken.compiler.support#get-real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16603,c,av);}
/* support.scm:1501: chicken.internal#hash-table-ref */
t3=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[465];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16610(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +8,c,3)))){
C_save_and_reclaim((void*)f_16610,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+8);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16613,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_16629,a[2]=t1,a[3]=t2,a[4]=t3,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* support.scm:1513: resolve */
f_16613(t5,t2);}

/* resolve in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16613(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_16613,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16617,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1508: chicken.internal#hash-table-ref */
t4=*((C_word*)lf[128]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[465];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k16615 in resolve in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16617(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_16617,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16623,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1510: chicken.internal#hash-table-ref */
t3=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[465];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k16621 in k16615 in resolve in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16623,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?t1:((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_16629,c,av);}
a=C_alloc(6);
if(C_truep(C_i_not(t1))){
/* support.scm:1514: ##sys#symbol->string */
t2=*((C_word*)lf[176]+1);{
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
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t2=C_u_i_car(((C_word*)t0)[4]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_16725,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* support.scm:1517: ##sys#symbol->string */
t4=*((C_word*)lf[176]+1);{
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
/* support.scm:1531: ##sys#symbol->string */
t2=*((C_word*)lf[176]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}}

/* k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16656(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_16656,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16658,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_16658(t5,((C_word*)t0)[4],((C_word*)t0)[5],C_fix(0),t1);}

/* loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_16658(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_16658,5,t0,t1,t2,t3,t4);}
a=C_alloc(8);
if(C_truep(C_i_greaterp(t3,C_fix(20)))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16672,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t6=C_a_i_cons(&a,2,lf[471],t2);
/* support.scm:1522: scheme#reverse */
t7=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t5;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_16682,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
/* support.scm:1524: resolve */
f_16613(t5,t4);}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16721,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1530: scheme#reverse */
t6=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}}

/* k16670 in loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16672,c,av);}
/* support.scm:1522: chicken.string#string-intersperse */
t2=*((C_word*)lf[469]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[470];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k16680 in loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_16682,c,av);}
a=C_alloc(8);
t2=C_eqp(t1,((C_word*)t0)[2]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16695,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1526: scheme#reverse */
t4=*((C_word*)lf[80]+1);{
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
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_16714,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* support.scm:1527: scheme#symbol->string */
t4=*((C_word*)lf[236]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k16693 in k16680 in loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16695,c,av);}
/* support.scm:1526: chicken.string#string-intersperse */
t2=*((C_word*)lf[469]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[472];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k16708 in k16712 in k16680 in loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_16710,c,av);}
/* support.scm:1527: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_16658(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k16712 in k16680 in loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16714(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_16714,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=C_fixnum_plus(((C_word*)t0)[3],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_16710,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* support.scm:1529: db-get */
t5=*((C_word*)lf[127]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[6];
av2[3]=((C_word*)t0)[7];
av2[4]=lf[473];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k16719 in loop in k16654 in k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16721(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16721,c,av);}
/* support.scm:1530: chicken.string#string-intersperse */
t2=*((C_word*)lf[469]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[474];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k16723 in k16627 in chicken.compiler.support#real-name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_16725,c,av);}
a=C_alloc(9);
t2=C_a_i_list1(&a,1,t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_16656,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:1519: db-get */
t4=*((C_word*)lf[127]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[5];
av2[4]=lf[473];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* chicken.compiler.support#real-name2 in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16730(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_16730,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16734,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1534: chicken.internal#hash-table-ref */
t5=*((C_word*)lf[128]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[465];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k16732 in chicken.compiler.support#real-name2 in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16734,c,av);}
if(C_truep(t1)){
/* support.scm:1535: real-name */
t2=*((C_word*)lf[177]+1);{
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
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#display-real-name-table in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16742(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_16742,c,av);}
a=C_alloc(2);
t2=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16748,tmp=(C_word)a,a+=2,tmp);
/* support.scm:1538: chicken.internal#hash-table-for-each */
t3=*((C_word*)lf[257]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[465];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* a16747 in chicken.compiler.support#display-real-name-table in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16748(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_16748,c,av);}
a=C_alloc(5);
t4=*((C_word*)lf[24]+1);
t5=*((C_word*)lf[24]+1);
t6=C_i_check_port_2(*((C_word*)lf[24]+1),C_fix(2),C_SCHEME_TRUE,lf[25]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16755,a[2]=t1,a[3]=t4,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1540: ##sys#print */
t8=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}

/* k16753 in a16747 in chicken.compiler.support#display-real-name-table in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_16755,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16758,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1540: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(9);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k16756 in k16753 in a16747 in chicken.compiler.support#display-real-name-table in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16758(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_16758,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16761,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1540: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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

/* k16759 in k16756 in k16753 in a16747 in chicken.compiler.support#display-real-name-table in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16761,c,av);}
/* support.scm:1540: ##sys#write-char-0 */
t2=*((C_word*)lf[26]+1);{
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

/* chicken.compiler.support#source-info->string in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16766(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_16766,c,av);}
a=C_alloc(13);
if(C_truep(C_i_listp(t2))){
t3=C_i_car(t2);
t4=C_i_cadr(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16786,a[2]=t1,a[3]=t3,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16790,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
t7=C_i_string_length(t3);
t8=C_a_i_fixnum_difference(&a,2,C_fix(4),t7);
/* support.scm:1547: scheme#max */
t9=*((C_word*)lf[482]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t9;
av2[1]=t6;
av2[2]=C_fix(0);
av2[3]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
/* support.scm:1548: chicken.string#->string */
t3=*((C_word*)lf[66]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k16784 in chicken.compiler.support#source-info->string in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_16786,c,av);}
/* support.scm:1547: chicken.string#conc */
t2=*((C_word*)lf[478]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[479];
av2[4]=t1;
av2[5]=lf[480];
av2[6]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(7,av2);}}

/* k16788 in chicken.compiler.support#source-info->string in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16790,c,av);}
/* support.scm:1547: scheme#make-string */
t2=*((C_word*)lf[481]+1);{
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

/* chicken.compiler.support#source-info->name in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16801(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_16801,c,av);}
if(C_truep(C_i_listp(t2))){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_cadr(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* support.scm:1551: chicken.string#->string */
t3=*((C_word*)lf[66]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* chicken.compiler.support#source-info->line in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16816,c,av);}
t3=C_i_listp(t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_i_car(t2):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#call-info in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16828(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_16828,c,av);}
a=C_alloc(4);
t4=C_i_cdr(t2);
t5=C_i_pairp(t4);
t6=(C_truep(t5)?C_i_cadr(t2):C_SCHEME_FALSE);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16835,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t6)){
if(C_truep(C_i_listp(t6))){
t8=C_i_car(t6);
t9=C_i_cadr(t6);
/* support.scm:1561: chicken.string#conc */
t10=*((C_word*)lf[478]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t10;
av2[1]=t7;
av2[2]=lf[486];
av2[3]=t8;
av2[4]=lf[487];
av2[5]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(6,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k16833 in chicken.compiler.support#call-info in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16835,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?t1:((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16865(C_word c,C_word *av){
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
C_word t13;
C_word t14;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_16865,c,av);}
a=C_alloc(17);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(t3,lf[125]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16889,a[2]=t2,a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17061,a[2]=t7,a[3]=t12,a[4]=t8,tmp=(C_word)a,a+=5,tmp));
t14=((C_word*)t12)[1];
f_17061(t14,t10,t3);}

/* k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16889(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_16889,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(t1,lf[125]);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17025,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17027,a[2]=t4,a[3]=t9,a[4]=t5,tmp=(C_word)a,a+=5,tmp));
t11=((C_word*)t9)[1];
f_17027(t11,t7,t1);}

/* k16902 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_16904,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16907,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1573: g4189 */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k16905 in k16902 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_16907,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_16913,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:1574: chicken.condition#condition? */
t3=*((C_word*)lf[492]+1);{
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

/* k16911 in k16905 in k16902 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16913(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_16913,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
/* support.scm:1574: k */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=C_SCHEME_FALSE;
av2[3]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_16922,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_i_length(((C_word*)t0)[4]);
t4=C_eqp(C_fix(1),t3);
if(C_truep(t4)){
/* support.scm:1576: encodeable-literal? */
t5=lf[491];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[4]);
f_17194(3,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_16922(2,av2);}}}}

/* k16920 in k16911 in k16905 in k16902 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16922(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_16922,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16925,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1577: debugging */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[186];
av2[3]=lf[489];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t2=C_eqp(C_fix(1),C_u_i_length(((C_word*)t0)[4]));
if(C_truep(t2)){
/* support.scm:1580: k */
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=C_SCHEME_FALSE;
av2[3]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* support.scm:1582: bomb */
t3=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[490];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}}

/* k16923 in k16920 in k16911 in k16905 in k16902 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16925,c,av);}
/* support.scm:1578: k */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=C_SCHEME_TRUE;
av2[3]=C_i_car(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16964(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_16964,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16970,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16979,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1573: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[106]+1);{
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

/* a16969 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16970(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_16970,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16976,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1573: k4186 */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a16975 in a16969 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16976(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_16976,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a16978 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16979(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_16979,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16985,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_16997,a[2]=((C_word*)t0)[4],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1573: ##sys#call-with-values */{
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

/* a16984 in a16978 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16985(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_16985,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16991,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1573: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=*((C_word*)lf[493]+1);
C_call_with_values(4,av2);}}

/* a16990 in a16984 in a16978 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16991(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_16991,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[3];
C_apply(4,av2);}}

/* a16996 in a16978 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_16997(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +3,c,2)))){
C_save_and_reclaim((void*)f_16997,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+3);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17003,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1573: k4186 */
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

/* a17002 in a16996 in a16978 in a16963 in k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17003(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17003,c,av);}{
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

/* k17023 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17025(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_17025,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_slot(((C_word*)t0)[2],C_fix(0));
if(C_truep(C_i_closurep(t3))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_16904,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_16964,a[2]=t3,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1573: scheme#call-with-current-continuation */
t6=*((C_word*)lf[107]+1);{
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
/* support.scm:1583: bomb */
t4=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=lf[494];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* map-loop4156 in k16887 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17027(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_17027,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,2,lf[86],t3);
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

/* map-loop4125 in chicken.compiler.support#constant-form-eval in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17061(C_word t0,C_word t1,C_word t2){
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
loop:
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_17061,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_slot(t3,C_fix(2));
t5=C_i_car(t4);
t6=C_a_i_cons(&a,2,t5,C_SCHEME_END_OF_LIST);
t7=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t6);
t8=C_mutate(((C_word *)((C_word*)t0)[2])+1,t6);
t10=t1;
t11=C_slot(t2,C_fix(1));
t1=t10;
t2=t11;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17095(C_word c,C_word *av){
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
C_word t13;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_17095,c,av);}
a=C_alloc(14);
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17098,tmp=(C_word)a,a+=2,tmp);
t6=C_i_car(t3);
t7=C_slot(t6,C_fix(1));
t8=C_eqp(lf[149],t7);
if(C_truep(t8)){
t9=C_slot(C_u_i_car(t3),C_fix(2));
t10=C_i_car(t9);
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17126,a[2]=t3,a[3]=t4,a[4]=t1,a[5]=t10,tmp=(C_word)a,a+=6,tmp);
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17148,a[2]=t11,a[3]=t5,a[4]=t3,a[5]=t10,tmp=(C_word)a,a+=6,tmp);
/* tweaks.scm:51: ##sys#get */
t13=*((C_word*)lf[178]+1);{
C_word *av2=av;
av2[0]=t13;
av2[1]=t12;
av2[2]=t10;
av2[3]=lf[498];
((C_proc)(void*)(*((C_word*)t13+1)))(4,av2);}}
else{
/* support.scm:1595: k */
t9=t4;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}}

/* constant-node? in chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17098(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17098,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_eqp(lf[86],C_slot(t2,C_fix(1)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k17124 in chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17126(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_17126,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17133,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1593: constant-form-eval */
t4=*((C_word*)lf[488]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* support.scm:1594: k */
t2=((C_word*)t0)[3];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=C_SCHEME_FALSE;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* a17132 in k17124 in chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17133(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_17133,c,av);}
/* support.scm:1593: k */
t4=((C_word*)t0)[2];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k17146 in chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17148(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_17148,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17154,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* support.scm:1590: foldable? */
t3=*((C_word*)lf[497]+1);{
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
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_17126(2,av2);}}}

/* k17152 in k17146 in chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17154(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_17154,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17157,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
if(C_truep(t1)){
/* support.scm:1592: every */
f_5670(((C_word*)t0)[2],((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_17126(2,av2);}}}
else{
/* support.scm:1591: predicate? */
t3=*((C_word*)lf[496]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k17155 in k17152 in k17146 in chicken.compiler.support#maybe-constant-fold-call in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17157,c,av);}
if(C_truep(t1)){
/* support.scm:1592: every */
f_5670(((C_word*)t0)[2],((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_17126(2,av2);}}}

/* chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17194(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_17194,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17209,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1605: immediate? */
t4=*((C_word*)lf[90]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17209(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_17209,c,av);}
a=C_alloc(13);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_exact_integerp(((C_word*)t0)[3]))){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17219,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17234,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1610: scheme#call-with-current-continuation */
t4=*((C_word*)lf[107]+1);{
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
t2=C_i_flonump(((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
t3=C_slot(((C_word*)t0)[3],C_fix(1));
t4=C_i_string_length(t3);
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_fixnum_less_or_equal_p(C_i_integer_length(t4),C_fix(24));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
if(C_truep(C_byteblockp(((C_word*)t0)[3]))){
t3=stub4238(C_SCHEME_UNDEFINED,((C_word*)t0)[3]);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_fixnum_less_or_equal_p(C_i_integer_length(t3),C_fix(24));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=stub4238(C_SCHEME_UNDEFINED,((C_word*)t0)[3]);
if(C_truep(C_fixnum_less_or_equal_p(C_i_integer_length(t3),C_fix(24)))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17323,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17325,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6318,a[2]=t3,a[3]=t5,a[4]=t7,tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_6318(t9,t4,C_fix(0));}
else{
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}}}}}

/* k17217 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17219(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_17219,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17222,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1610: g4247 */
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k17220 in k17217 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17222,c,av);}
if(C_truep(t1)){
t2=C_i_string_length(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_fixnum_less_or_equal_p(C_i_integer_length(t2),C_fix(24));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17234(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_17234,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17240,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17249,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1610: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[106]+1);{
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

/* a17239 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17240(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,2)))){
C_save_and_reclaim((void *)f_17240,c,av);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17246,tmp=(C_word)a,a+=2,tmp);
/* support.scm:1610: k4244 */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a17245 in a17239 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17246,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a17248 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_17249,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17251,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17258,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17275,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tmp15264 */
t5=t2;
f_17251(t5,t4);}

/* tmp15264 in a17248 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17251(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_17251,2,t0,t1);}
/* ##sys#number->string */
t2=*((C_word*)lf[499]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=C_fix(16);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* tmp25265 in a17248 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17258(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_17258,3,t0,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17264,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1610: k4244 */
t4=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a17263 in tmp25265 in a17248 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17264(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17264,c,av);}{
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

/* k17273 in a17248 in a17233 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_17275,c,av);}
a=C_alloc(3);
/* tmp25265 */
t2=((C_word*)t0)[2];
f_17258(t2,((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* k17321 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17323(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17323,c,av);}
/* support.scm:1621: every */
f_5670(((C_word*)t0)[2],lf[491],t1);}

/* a17324 in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_17325(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_slot(((C_word*)t0)[2],t1));}

/* chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17331(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_17331,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17335,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17340,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_17340(t7,t3,C_fix(0),t2);}

/* k17333 in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17335,c,av);}
/* support.scm:1646: scheme#newline */
t2=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17340(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_17340,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_slot(t3,C_fix(1));
t5=C_slot(t3,C_fix(2));
t6=C_slot(t3,C_fix(3));
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_17368,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t6,a[5]=t3,a[6]=t1,a[7]=t5,a[8]=t4,tmp=(C_word)a,a+=9,tmp);
/* support.scm:1634: scheme#make-string */
t8=*((C_word*)lf[481]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t2;
av2[3]=C_make_character(32);
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17368(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_17368,c,av);}
a=C_alloc(16);
t2=C_a_i_fixnum_plus(&a,2,((C_word*)t0)[2],C_fix(2));
t3=*((C_word*)lf[24]+1);
t4=*((C_word*)lf[24]+1);
t5=C_i_check_port_2(*((C_word*)lf[24]+1),C_fix(2),C_SCHEME_TRUE,lf[25]);
t6=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_17376,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=((C_word*)t0)[8],a[10]=t1,tmp=(C_word)a,a+=11,tmp);
/* support.scm:1636: ##sys#write-char-0 */
t7=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=C_make_character(10);
av2[3]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17376(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_17376,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_17379,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* support.scm:1636: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[10];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_17379,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_17382,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* support.scm:1636: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(60);
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17382(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_17382,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_17385,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* support.scm:1636: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[9];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17385(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_17385,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_17388,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* support.scm:1636: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17388(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_17388,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_17391,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* support.scm:1636: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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
av2[4]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_17391(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_17391,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17392,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_i_check_list_2(((C_word*)t0)[4],lf[44]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17402,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17464,a[2]=t6,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_17464(t8,t4,((C_word*)t0)[4]);}

/* g4287 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_fcall f_17392(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_17392,3,t0,t1,t2);}
/* support.scm:1637: g4309 */
t3=((C_word*)((C_word*)t0)[2])[1];
f_17340(t3,t1,((C_word*)t0)[3],t2);}

/* k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_ccall f_17402(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_17402,c,av);}
a=C_alloc(9);
t2=C_block_size(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17408,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_fixnum_greaterp(t2,C_fix(4)))){
t4=*((C_word*)lf[24]+1);
t5=*((C_word*)lf[24]+1);
t6=C_i_check_port_2(*((C_word*)lf[24]+1),C_fix(2),C_SCHEME_TRUE,lf[25]);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17420,a[2]=t3,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* support.scm:1640: ##sys#write-char-0 */
t8=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=C_make_character(91);
av2[3]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
/* ##sys#write-char/port */
t4=*((C_word*)lf[501]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=C_make_character(62);
av2[3]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k17406 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_17408(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17408,c,av);}
/* ##sys#write-char/port */
t2=*((C_word*)lf[501]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(62);
av2[3]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k17418 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_17420(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_17420,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17423,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1640: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[4],C_fix(4));
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17421 in k17418 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in ... */
static void C_ccall f_17423(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_17423,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17426,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17431,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_17431(t6,t2,C_fix(5));}

/* k17424 in k17421 in k17418 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_ccall f_17426(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17426,c,av);}
/* ##sys#write-char/port */
t2=*((C_word*)lf[501]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(93);
av2[3]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* doloop4323 in k17421 in k17418 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in ... */
static void C_fcall f_17431(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_17431,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=*((C_word*)lf[24]+1);
t4=*((C_word*)lf[24]+1);
t5=C_i_check_port_2(*((C_word*)lf[24]+1),C_fix(2),C_SCHEME_TRUE,lf[25]);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_17444,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* support.scm:1643: ##sys#write-char-0 */
t7=*((C_word*)lf[26]+1);{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_make_character(32);
av2[3]=*((C_word*)lf[24]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k17442 in doloop4323 in k17421 in k17418 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in ... */
static void C_ccall f_17444(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_17444,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17447,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1643: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[5],((C_word*)t0)[4]);
av2[3]=C_SCHEME_TRUE;
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17445 in k17442 in doloop4323 in k17421 in k17418 in k17400 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in ... */
static void C_ccall f_17447(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17447,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_17431(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* for-each-loop4286 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in ... */
static void C_fcall f_17464(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_17464,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17474,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:1637: g4287 */
t4=((C_word*)t0)[3];
f_17392(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k17472 in for-each-loop4286 in k17389 in k17386 in k17383 in k17380 in k17377 in k17374 in k17366 in loop in chicken.compiler.support#dump-nodes in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in ... */
static void C_ccall f_17474(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17474,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_17464(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* chicken.compiler.support#read/source-info in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17487(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17487,c,av);}
/* support.scm:1651: chicken.syntax#read-with-source-info */
t3=*((C_word*)lf[503]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_17493,c,av);}
a=C_alloc(4);
if(C_truep(C_i_char_equalp(C_make_character(62),t2))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17503,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* ##sys#read-char/port */
t5=*((C_word*)lf[508]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
/* support.scm:1662: old-hook */
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17503(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_17503,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17506,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17522,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1665: chicken.base#open-output-string */
t4=*((C_word*)lf[331]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k17504 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17506(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_17506,c,av);}
a=C_alloc(12);
t2=C_a_i_list(&a,2,lf[505],t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[506],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_17522,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17527,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_17527(t5,((C_word*)t0)[3]);}

/* loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17527(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_17527,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17531,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* ##sys#read-char/port */
t3=*((C_word*)lf[508]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k17529 in loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17531(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_17531,c,av);}
a=C_alloc(5);
if(C_truep(C_eofp(t1))){
/* support.scm:1669: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[507];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
if(C_truep(C_u_i_char_equalp(t1,C_make_character(10)))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17548,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1671: scheme#newline */
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
else{
if(C_truep(C_u_i_char_equalp(t1,C_make_character(60)))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17559,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* ##sys#read-char/port */
t3=*((C_word*)lf[508]+1);{
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
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17582,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* ##sys#write-char/port */
t3=*((C_word*)lf[501]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}}}

/* k17546 in k17529 in loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17548,c,av);}
/* support.scm:1672: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_17527(t2,((C_word*)t0)[3]);}

/* k17557 in k17529 in loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17559(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_17559,c,av);}
a=C_alloc(6);
t2=C_eqp(C_make_character(35),t1);
if(C_truep(t2)){
/* support.scm:1676: chicken.base#get-output-string */
t3=*((C_word*)lf[328]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_17571,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* ##sys#write-char/port */
t4=*((C_word*)lf[501]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_make_character(60);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}

/* k17569 in k17557 in k17529 in loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17571(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_17571,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17574,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* ##sys#write-char/port */
t3=*((C_word*)lf[501]+1);{
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

/* k17572 in k17569 in k17557 in k17529 in loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17574,c,av);}
/* support.scm:1680: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_17527(t2,((C_word*)t0)[3]);}

/* k17580 in k17529 in loop in k17520 in k17501 in ##sys#user-read-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17582,c,av);}
/* support.scm:1683: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_17527(t2,((C_word*)t0)[3]);}

/* chicken.compiler.support#big-fixnum? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_17587,c,av);}
a=C_alloc(4);
if(C_truep(C_fixnump(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17600,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1690: chicken.platform#feature? */
t4=*((C_word*)lf[509]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[510];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k17598 in chicken.compiler.support#big-fixnum? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17600,c,av);}
if(C_truep(t1)){
t2=C_fixnum_greaterp(((C_word*)t0)[2],C_fix(1073741823));
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:C_fixnum_lessp(((C_word*)t0)[2],C_fix(-1073741824)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#small-bignum? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_17611,c,av);}
a=C_alloc(4);
if(C_truep(C_i_bignump(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17633,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1696: chicken.platform#feature? */
t4=*((C_word*)lf[509]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[510];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k17631 in chicken.compiler.support#small-bignum? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17633,c,av);}
t2=C_i_not(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?C_fixnum_less_or_equal_p(C_i_integer_length(((C_word*)t0)[3]),C_fix(62)):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#hide-variable in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_17635,c,av);}
a=C_alloc(3);
t3=C_a_i_list(&a,1,lf[512]);
if(C_truep(C_i_nullp(t3))){
/* tweaks.scm:57: ##sys#put! */
t4=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[277];
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* tweaks.scm:57: ##sys#put! */
t4=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[277];
av2[4]=C_i_car(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* chicken.compiler.support#export-variable in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_17655,c,av);}
a=C_alloc(3);
t3=C_a_i_list(&a,1,lf[514]);
if(C_truep(C_i_nullp(t3))){
/* tweaks.scm:57: ##sys#put! */
t4=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[277];
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* tweaks.scm:57: ##sys#put! */
t4=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[277];
av2[4]=C_i_car(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* chicken.compiler.support#variable-hidden? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17675(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_17675,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17683,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1709: ##sys#get */
t4=*((C_word*)lf[178]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[277];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k17681 in chicken.compiler.support#variable-hidden? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17683(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17683,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_eqp(t1,lf[512]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k17690 in ##sys#toplevel-definition-hook in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17692,c,av);}
if(C_truep(t1)){
/* support.scm:1712: chicken.plist#remprop! */
t2=*((C_word*)lf[276]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[277];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.compiler.support#variable-visible? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_17697,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17701,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1715: ##sys#get */
t5=*((C_word*)lf[178]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[277];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k17699 in chicken.compiler.support#variable-visible? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_17701,c,av);}
t2=C_eqp(t1,lf[512]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_eqp(t1,lf[514]);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_SCHEME_TRUE:C_i_not(((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* chicken.compiler.support#mark-variable in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_17722,c,av);}
if(C_truep(C_rest_nullp(c,4))){
/* support.scm:1725: ##sys#put! */
t4=*((C_word*)lf[259]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* support.scm:1725: ##sys#put! */
t4=*((C_word*)lf[259]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_get_rest_arg(c,4,av,4,t0);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* chicken.compiler.support#variable-mark in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17737,c,av);}
/* support.scm:1728: ##sys#get */
t4=*((C_word*)lf[178]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* chicken.compiler.support#intrinsic? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17743,c,av);}
/* tweaks.scm:60: ##sys#get */
t3=*((C_word*)lf[178]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[498];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.compiler.support#foldable? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17754,c,av);}
/* tweaks.scm:60: ##sys#get */
t3=*((C_word*)lf[178]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[518];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.compiler.support#predicate? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17765,c,av);}
/* tweaks.scm:60: ##sys#get */
t3=*((C_word*)lf[178]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=lf[519];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17776(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_17776,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17780,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17869,a[2]=t3,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1739: chicken.platform#repository-path */
t5=*((C_word*)lf[527]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17780(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_17780,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17786,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17847,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1740: chicken.base#open-output-string */
t4=*((C_word*)lf[331]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k17784 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_17786,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17814,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1747: scheme#call-with-input-file */
t3=*((C_word*)lf[522]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=*((C_word*)lf[82]+1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k17796 in for-each-loop4490 in k17812 in k17784 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_17798,c,av);}
/* support.scm:1744: ##sys#put! */
t2=*((C_word*)lf[259]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=lf[521];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k17800 in for-each-loop4490 in k17812 in k17784 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17802(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_17802,c,av);}
a=C_alloc(3);
t2=(C_truep(t1)?t1:C_SCHEME_END_OF_LIST);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_list1(&a,1,t3);
/* support.scm:1746: scheme#append */
t5=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* k17812 in k17784 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17814(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_17814,c,av);}
a=C_alloc(5);
t2=C_i_check_list_2(t1,lf[44]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17822,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_17822(t6,((C_word*)t0)[2],t1);}

/* for-each-loop4490 in k17812 in k17784 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_17822(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_17822,3,t0,t1,t2);}
a=C_alloc(13);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17832,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_i_car(t4);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17798,a[2]=t3,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17802,a[2]=t4,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* support.scm:1746: ##sys#get */
t8=*((C_word*)lf[178]+1);{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=t5;
av2[3]=lf[521];
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k17830 in for-each-loop4490 in k17812 in k17784 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17832(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17832,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_17822(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k17845 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_17847,c,av);}
a=C_alloc(5);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[325]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17853,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* support.scm:1740: ##sys#print */
t4=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[525];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k17851 in k17845 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17853(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_17853,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17856,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1740: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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

/* k17854 in k17851 in k17845 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_17856,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17859,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1740: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[524];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17857 in k17854 in k17851 in k17845 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_17859,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17862,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:1740: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
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

/* k17860 in k17857 in k17854 in k17851 in k17845 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_17862,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17865,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1740: chicken.base#get-output-string */
t3=*((C_word*)lf[328]+1);{
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

/* k17863 in k17860 in k17857 in k17854 in k17851 in k17845 in k17778 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17865,c,av);}
/* support.scm:1740: debugging */
t2=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[523];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k17867 in chicken.compiler.support#load-identifier-database in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17869,c,av);}
/* support.scm:1739: chicken.load#find-file */
t2=*((C_word*)lf[526]+1);{
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

/* chicken.compiler.support#print-version in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17871(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_17871,c,av);}
a=C_alloc(6);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17878,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(t3)){
/* support.scm:1753: chicken.base#print* */
t5=*((C_word*)lf[529]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[530];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f19574,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1754: chicken.platform#chicken-version */
t6=*((C_word*)lf[245]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}

/* k17876 in chicken.compiler.support#print-version in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_17878,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17885,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1754: chicken.platform#chicken-version */
t3=*((C_word*)lf[245]+1);{
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

/* k17883 in k17876 in chicken.compiler.support#print-version in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17885,c,av);}
/* support.scm:1754: chicken.base#print */
t2=*((C_word*)lf[233]+1);{
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

/* chicken.compiler.support#print-usage in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_17896,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17900,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:1759: print-version */
t3=*((C_word*)lf[528]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k17898 in chicken.compiler.support#print-usage in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_17900,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17903,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:1760: scheme#newline */
t3=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k17901 in k17898 in chicken.compiler.support#print-usage in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17903(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17903,c,av);}
/* support.scm:1761: scheme#display */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[532];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* chicken.compiler.support#print-debug-options in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_17908,c,av);}
/* support.scm:1893: scheme#display */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=lf[534];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* a17913 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17914(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_17914,c,av);}
a=C_alloc(5);
t4=C_i_check_port_2(t3,C_fix(2),C_SCHEME_TRUE,lf[32]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17921,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:462: ##sys#print */
t6=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[535];
av2[3]=C_SCHEME_FALSE;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k17919 in a17913 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_17921,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17924,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:462: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[4],C_fix(1));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17922 in k17919 in a17913 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_17924,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_17927,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:462: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k17925 in k17922 in k17919 in a17913 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_17927,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_17930,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:462: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_slot(((C_word*)t0)[4],C_fix(2));
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k17928 in k17925 in k17922 in k17919 in a17913 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_17930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_17930,c,av);}
/* support.scm:462: ##sys#write-char-0 */
t2=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(62);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k5273 */
static void C_ccall f_5275(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5275,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5278,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k5276 in k5273 */
static void C_ccall f_5278(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5278,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5281,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k5279 in k5276 in k5273 */
static void C_ccall f_5281(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5281,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5284,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5284(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5284,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5287,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_file_toplevel(2,av2);}}

/* k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5287(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5287,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5290,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5290(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5290,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5293,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_pathname_toplevel(2,av2);}}

/* k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5293(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5293,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5296,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_port_toplevel(2,av2);}}

/* k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5296(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_5296,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5299,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_expand_toplevel(2,av2);}}

/* k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5299(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,4)))){
C_save_and_reclaim((void *)f_5299,c,av);}
a=C_alloc(19);
t2=C_mutate(&lf[2] /* (set! chicken.compiler.support#take ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5409,tmp=(C_word)a,a+=2,tmp));
t3=C_mutate(&lf[3] /* (set! chicken.compiler.support#every ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5670,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate(&lf[4] /* (set! chicken.compiler.support#any ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5704,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate(&lf[5] /* (set! chicken.compiler.support#cons* ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_5734,tmp=(C_word)a,a+=2,tmp));
t6=C_mutate(&lf[6] /* (set! chicken.compiler.support#last ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6070,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate(&lf[7] /* (set! chicken.compiler.support#lset-adjoin/eq? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6129,tmp=(C_word)a,a+=2,tmp));
t8=C_mutate((C_word*)lf[8]+1 /* (set! chicken.compiler.support#number-type ...) */,lf[9]);
t9=C_set_block_item(lf[10] /* chicken.compiler.support#unsafe */,0,C_SCHEME_FALSE);
t10=C_mutate((C_word*)lf[11]+1 /* (set! chicken.compiler.support#compiler-cleanup-hook ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6582,tmp=(C_word)a,a+=2,tmp));
t11=C_set_block_item(lf[12] /* chicken.compiler.support#debugging-chicken */,0,C_SCHEME_END_OF_LIST);
t12=C_mutate((C_word*)lf[13]+1 /* (set! chicken.compiler.support#bomb ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6586,tmp=(C_word)a,a+=2,tmp));
t13=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6611,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:119: chicken.base#open-output-string */
t14=*((C_word*)lf[331]+1);{
C_word *av2=av;
av2[0]=t14;
av2[1]=t13;
((C_proc)(void*)(*((C_word*)t14+1)))(2,av2);}}

/* chicken.compiler.support#take in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5409(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_5409,3,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_fixnum_less_or_equal_p(t3,C_fix(0)))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5427,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:56: take */
t7=t5;
t8=C_u_i_cdr(t2);
t9=C_fixnum_difference(t3,C_fix(1));
t1=t7;
t2=t8;
t3=t9;
goto loop;}}

/* k5425 in chicken.compiler.support#take in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_5427,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in a10454 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5467(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,4)))){
C_save_and_reclaim_args((void *)trf_5467,5,t0,t1,t2,t3,t4);}
a=C_alloc(4);
if(C_truep(C_fixnum_less_or_equal_p(t2,C_fix(0)))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5481,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:67: scheme#reverse */
t6=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_fixnum_difference(t2,C_fix(1));
t6=C_i_car(t4);
t7=C_a_i_cons(&a,2,t6,t3);
/* mini-srfi-1.scm:68: loop */
t9=t1;
t10=t5;
t11=t7;
t12=C_u_i_cdr(t4);
t1=t9;
t2=t10;
t3=t11;
t4=t12;
goto loop;}}

/* k5479 in loop in a10454 in a10448 in chicken.compiler.support#inline-lambda-bindings in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5481(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5481,c,av);}
/* mini-srfi-1.scm:67: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
C_values(4,av2);}}

/* chicken.compiler.support#every in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5670(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_5670,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5676,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_5676(t7,t1,t3);}

/* loop in chicken.compiler.support#every in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5676(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_5676,3,t0,t1,t2);}
a=C_alloc(5);
t3=C_i_nullp(t2);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5698,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:82: pred */
t5=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k5696 in loop in chicken.compiler.support#every in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5698,c,av);}
if(C_truep(C_i_not(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* mini-srfi-1.scm:83: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_5676(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[4]));}}

/* chicken.compiler.support#any in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5704(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_5704,3,t1,t2,t3);}
a=C_alloc(6);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5710,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_5710(t7,t1,t3);}

/* loop in chicken.compiler.support#any in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5710(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_5710,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5720,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:88: pred */
t4=((C_word*)t0)[3];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k5718 in loop in chicken.compiler.support#any in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5720,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* mini-srfi-1.scm:89: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_5710(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[4]));}}

/* chicken.compiler.support#cons* in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5734(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_5734,3,t1,t2,t3);}
a=C_alloc(5);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5740,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_5740(t7,t1,t2,t3);}

/* loop in chicken.compiler.support#cons* in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5740(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_5740,4,t0,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5754,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:95: loop */
t6=t4;
t7=C_i_car(t3);
t8=C_u_i_cdr(t3);
t1=t6;
t2=t7;
t3=t8;
goto loop;}}

/* k5752 in loop in chicken.compiler.support#cons* in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5754(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_5754,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* foldr408 in k8096 in chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5963(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_5963,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5971,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5997,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g413 in foldr408 in k8096 in chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_5971(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5971,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=(
/* mini-srfi-1.scm:135: pred */
  f_8106(((C_word*)t0)[2],t2)
);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5979,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* mini-srfi-1.scm:135: g423 */
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(
/* mini-srfi-1.scm:135: g423 */
  f_5979(C_a_i(&a,3),t5,t4)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* g423 in g413 in foldr408 in k8096 in chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_5979(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_a_i_cons(&a,2,t1,((C_word*)t0)[2]));}

/* k5995 in foldr408 in k8096 in chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_5997(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_5997,c,av);}
/* mini-srfi-1.scm:134: g413 */
t2=((C_word*)t0)[2];
f_5971(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* map-loop436 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6036(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6036,3,t0,t1,t2);}
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

/* chicken.compiler.support#last in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6070(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,0,2)))){
C_save_and_reclaim_args((void *)trf_6070,2,t1,t2);}
a=C_alloc(2);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6076,tmp=(C_word)a,a+=2,tmp);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=(
  f_6076(t2)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* loop in chicken.compiler.support#last in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_6076(C_word t1){
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

/* chicken.compiler.support#lset-adjoin/eq? in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6129(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_6129,3,t1,t2,t3);}
a=C_alloc(5);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6135,a[2]=t5,tmp=(C_word)a,a+=3,tmp));
t7=((C_word*)t5)[1];
f_6135(t7,t1,t3,t2);}

/* loop in chicken.compiler.support#lset-adjoin/eq? in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6135(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_6135,4,t0,t1,t2,t3);}
a=C_alloc(3);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
if(C_truep(C_i_memq(t4,t3))){
/* mini-srfi-1.scm:160: loop */
t9=t1;
t10=C_u_i_cdr(t2);
t11=t3;
t1=t9;
t2=t10;
t3=t11;
goto loop;}
else{
t5=C_u_i_cdr(t2);
t6=C_u_i_car(t2);
t7=C_a_i_cons(&a,2,t6,t3);
/* mini-srfi-1.scm:161: loop */
t9=t1;
t10=t5;
t11=t7;
t1=t9;
t2=t10;
t3=t11;
goto loop;}}}

/* loop in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6318(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_6318,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(
/* mini-srfi-1.scm:190: proc */
  f_17325(((C_word*)t0)[3],t2)
);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6336,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:190: loop */
t6=t4;
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}}

/* k6334 in loop in k17207 in chicken.compiler.support#encodeable-literal? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6336(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_6336,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k12583 in walk in chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6431(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6431,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6444,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* mini-srfi-1.scm:216: pred */
t4=((C_word*)t0)[3];
f_12599(t4,t3,C_i_car(t2));}}

/* k6442 in loop in k12583 in walk in chicken.compiler.support#expression-has-side-effects? in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6444(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6444,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_u_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* mini-srfi-1.scm:217: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_6431(t2,((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[3]));}}

/* chicken.compiler.support#compiler-cleanup-hook in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6582(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6582,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#bomb in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,3)))){
C_save_and_reclaim((void*)f_6586,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6600,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:115: scheme#string-append */
t4=*((C_word*)lf[15]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[16];
av2[3]=C_u_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* support.scm:116: chicken.base#error */
t3=*((C_word*)lf[14]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[17];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k6598 in chicken.compiler.support#bomb in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6600,c,av);}{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[14]+1);
av2[3]=t1;
av2[4]=C_u_i_cdr(((C_word*)t0)[3]);
C_apply(5,av2);}}

/* k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6611(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(49,c,5)))){
C_save_and_reclaim((void *)f_6611,c,av);}
a=C_alloc(49);
t2=C_mutate((C_word*)lf[18]+1 /* (set! chicken.compiler.support#collected-debugging-output ...) */,t1);
t3=C_mutate(&lf[19] /* (set! chicken.compiler.support#+logged-debugging-modes+ ...) */,lf[20]);
t4=C_mutate(&lf[21] /* (set! chicken.compiler.support#test-debugging-mode ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6614,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate((C_word*)lf[22]+1 /* (set! chicken.compiler.support#debugging ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6635,tmp=(C_word)a,a+=2,tmp));
t6=C_mutate((C_word*)lf[34]+1 /* (set! chicken.compiler.support#with-debugging-output ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6755,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate((C_word*)lf[37]+1 /* (set! chicken.compiler.support#quit-compiling ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6852,tmp=(C_word)a,a+=2,tmp));
t8=C_mutate((C_word*)lf[42]+1 /* (set! ##sys#syntax-error-hook ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6868,tmp=(C_word)a,a+=2,tmp));
t9=C_mutate((C_word*)lf[51]+1 /* (set! chicken.syntax#syntax-error ...) */,*((C_word*)lf[42]+1));
t10=C_mutate((C_word*)lf[52]+1 /* (set! chicken.compiler.support#emit-syntax-trace-info ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_6965,tmp=(C_word)a,a+=2,tmp));
t11=C_mutate((C_word*)lf[53]+1 /* (set! chicken.compiler.support#check-signature ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7019,tmp=(C_word)a,a+=2,tmp));
t12=C_mutate((C_word*)lf[54]+1 /* (set! chicken.compiler.support#build-lambda-list ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7060,tmp=(C_word)a,a+=2,tmp));
t13=C_mutate((C_word*)lf[55]+1 /* (set! chicken.compiler.support#c-ify-string ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7097,tmp=(C_word)a,a+=2,tmp));
t14=C_mutate((C_word*)lf[65]+1 /* (set! chicken.compiler.support#valid-c-identifier? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7196,tmp=(C_word)a,a+=2,tmp));
t15=C_mutate((C_word*)lf[67]+1 /* (set! chicken.compiler.support#bytes->words ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7246,tmp=(C_word)a,a+=2,tmp));
t16=C_mutate((C_word*)lf[68]+1 /* (set! chicken.compiler.support#words->bytes ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7253,tmp=(C_word)a,a+=2,tmp));
t17=C_mutate((C_word*)lf[69]+1 /* (set! chicken.compiler.support#check-and-open-input-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7260,tmp=(C_word)a,a+=2,tmp));
t18=C_mutate((C_word*)lf[76]+1 /* (set! chicken.compiler.support#close-checked-input-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7304,tmp=(C_word)a,a+=2,tmp));
t19=C_mutate((C_word*)lf[79]+1 /* (set! chicken.compiler.support#fold-inner ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7316,tmp=(C_word)a,a+=2,tmp));
t20=C_mutate(&lf[81] /* (set! chicken.compiler.support#follow-without-loop ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7372,tmp=(C_word)a,a+=2,tmp));
t21=C_mutate((C_word*)lf[82]+1 /* (set! chicken.compiler.support#read-expressions ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7423,tmp=(C_word)a,a+=2,tmp));
t22=C_mutate((C_word*)lf[84]+1 /* (set! chicken.base#bwp-object? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7467,tmp=(C_word)a,a+=2,tmp));
t23=C_mutate((C_word*)lf[85]+1 /* (set! chicken.compiler.support#constant? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7470,tmp=(C_word)a,a+=2,tmp));
t24=C_mutate((C_word*)lf[89]+1 /* (set! chicken.compiler.support#collapsable-literal? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7538,tmp=(C_word)a,a+=2,tmp));
t25=C_mutate((C_word*)lf[90]+1 /* (set! chicken.compiler.support#immediate? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7574,tmp=(C_word)a,a+=2,tmp));
t26=C_mutate((C_word*)lf[92]+1 /* (set! chicken.compiler.support#basic-literal? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7626,tmp=(C_word)a,a+=2,tmp));
t27=C_mutate((C_word*)lf[94]+1 /* (set! chicken.compiler.support#canonicalize-begin-body ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7682,tmp=(C_word)a,a+=2,tmp));
t28=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7757,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:348: chicken.condition#condition-predicate */
t29=*((C_word*)lf[540]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t29;
av2[1]=t28;
av2[2]=lf[538];
((C_proc)(void*)(*((C_word*)t29+1)))(3,av2);}}

/* chicken.compiler.support#test-debugging-mode in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6614(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_6614,3,t1,t2,t3);}
a=C_alloc(3);
if(C_truep(C_i_symbolp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_i_memq(t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6629,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* support.scm:126: any */
f_5704(t1,t4,t2);}}

/* a6628 in chicken.compiler.support#test-debugging-mode in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6629,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_memq(t2,((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +17,c,3)))){
C_save_and_reclaim((void*)f_6635,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+17);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6638,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t10=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6703,a[2]=t2,tmp=(C_word)a,a+=3,tmp));
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6722,a[2]=t1,a[3]=t8,a[4]=t2,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* support.scm:141: test-debugging-mode */
f_6614(t11,t2,*((C_word*)lf[12]+1));}

/* text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6638(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_6638,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6644,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:130: chicken.port#with-output-to-string */
t3=*((C_word*)lf[31]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6644(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6644,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6648,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:132: scheme#display */
t3=*((C_word*)lf[29]+1);{
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

/* k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6648(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_6648,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6651,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[3]))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6660,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:134: scheme#display */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[30];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* support.scm:138: scheme#newline */
t3=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k6649 in k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6651(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6651,c,av);}
/* support.scm:138: scheme#newline */
t2=*((C_word*)lf[23]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k6658 in k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6660(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6660,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6680,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_6680(t5,((C_word*)t0)[2],((C_word*)t0)[3]);}

/* k6666 in for-each-loop704 in k6658 in k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6668(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6668,c,av);}
/* support.scm:136: ##sys#write-char-0 */
t2=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(32);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k6673 in for-each-loop704 in k6658 in k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6675(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6675,c,av);}
/* support.scm:136: ##sys#print */
t2=*((C_word*)lf[27]+1);{
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

/* for-each-loop704 in k6658 in k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6680(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,0,2)))){
C_save_and_reclaim_args((void *)trf_6680,3,t0,t1,t2);}
a=C_alloc(13);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6690,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[24]+1);
t6=*((C_word*)lf[24]+1);
t7=C_i_check_port_2(*((C_word*)lf[24]+1),C_fix(2),C_SCHEME_TRUE,lf[25]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6668,a[2]=t3,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6675,a[2]=t8,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* support.scm:136: scheme#force */
t10=*((C_word*)lf[28]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6688 in for-each-loop704 in k6658 in k6646 in a6643 in text in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6690,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6680(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* dump in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6703(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_6703,3,t0,t1,t2);}
a=C_alloc(5);
t3=*((C_word*)lf[18]+1);
t4=*((C_word*)lf[18]+1);
t5=C_i_check_port_2(*((C_word*)lf[18]+1),C_fix(2),C_SCHEME_TRUE,lf[32]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6710,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:140: ##sys#print */
t7=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}

/* k6708 in dump in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6710,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6713,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:140: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(124);
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6711 in k6708 in dump in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6713,c,av);}
/* support.scm:140: ##sys#print */
t2=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6722,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6725,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:142: text */
t3=((C_word*)((C_word*)t0)[5])[1];
f_6638(t3,t2);}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6743,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6746,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* support.scm:149: test-debugging-mode */
f_6614(t3,((C_word*)t0)[4],lf[19]);}}

/* k6723 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6725,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6728,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:143: scheme#display */
t3=*((C_word*)lf[29]+1);{
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

/* k6726 in k6723 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6728,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6731,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* support.scm:144: chicken.base#flush-output */
t3=*((C_word*)lf[33]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6729 in k6726 in k6723 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6731,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6734,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6737,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* support.scm:145: test-debugging-mode */
f_6614(t3,((C_word*)t0)[5],lf[19]);}

/* k6732 in k6729 in k6726 in k6723 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6734(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6734,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k6735 in k6729 in k6726 in k6723 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6737(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6737,c,av);}
if(C_truep(t1)){
/* support.scm:146: dump */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6703(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k6741 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6743,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k6744 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6746(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6746,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6753,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:150: text */
t3=((C_word*)((C_word*)t0)[4])[1];
f_6638(t3,t2);}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k6751 in k6744 in k6720 in chicken.compiler.support#debugging in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6753(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6753,c,av);}
/* support.scm:150: dump */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6703(t2,((C_word*)t0)[3],t1);}

/* chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_6755,c,av);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6758,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6819,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* support.scm:161: test-debugging-mode */
f_6614(t5,t2,*((C_word*)lf[12]+1));}

/* collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6758(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_6758,3,t0,t1,t2);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6760,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6787,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:160: chicken.string#string-split */
t5=*((C_word*)lf[35]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=lf[36];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* g756 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6760(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_6760,3,t0,t1,t2);}
a=C_alloc(5);
t3=*((C_word*)lf[18]+1);
t4=*((C_word*)lf[18]+1);
t5=C_i_check_port_2(*((C_word*)lf[18]+1),C_fix(2),C_SCHEME_TRUE,lf[32]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6767,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
/* support.scm:157: ##sys#print */
t7=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t6;
av2[2]=C_u_i_car(((C_word*)t0)[2]);
av2[3]=C_SCHEME_FALSE;
av2[4]=*((C_word*)lf[18]+1);
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
/* support.scm:157: ##sys#print */
t7=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[2];
av2[3]=C_SCHEME_FALSE;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}}

/* k6765 in g756 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6767,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6770,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:157: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_make_character(124);
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6768 in k6765 in g756 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6770(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6770,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6773,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:157: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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

/* k6771 in k6768 in k6765 in g756 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6773,c,av);}
/* support.scm:157: ##sys#write-char-0 */
t2=*((C_word*)lf[26]+1);{
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

/* k6785 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6787,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6792,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_6792(t5,((C_word*)t0)[3],t1);}

/* for-each-loop755 in k6785 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6792(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6792,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6802,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:155: g756 */
t4=((C_word*)t0)[3];
f_6760(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6800 in for-each-loop755 in k6785 in collect in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6802(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6802,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6792(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6819,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6822,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:162: chicken.port#with-output-to-string */
t3=*((C_word*)lf[31]+1);{
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
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6843,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* support.scm:167: test-debugging-mode */
f_6614(t2,((C_word*)t0)[4],lf[19]);}}

/* k6820 in k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6822(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6822,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6825,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:163: scheme#display */
t3=*((C_word*)lf[29]+1);{
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

/* k6823 in k6820 in k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6825,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6828,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* support.scm:164: chicken.base#flush-output */
t3=*((C_word*)lf[33]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k6826 in k6823 in k6820 in k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_6828,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6834,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:165: test-debugging-mode */
f_6614(t2,((C_word*)t0)[5],lf[19]);}

/* k6832 in k6826 in k6823 in k6820 in k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6834(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6834,c,av);}
if(C_truep(t1)){
/* support.scm:166: collect */
t2=((C_word*)t0)[2];
f_6758(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k6841 in k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6843,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6850,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:168: chicken.port#with-output-to-string */
t3=*((C_word*)lf[31]+1);{
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
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k6848 in k6841 in k6817 in chicken.compiler.support#with-debugging-output in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6850(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6850,c,av);}
/* support.scm:168: collect */
t2=((C_word*)t0)[2];
f_6758(t2,((C_word*)t0)[3],t1);}

/* chicken.compiler.support#quit-compiling in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +9,c,3)))){
C_save_and_reclaim((void*)f_6852,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+9);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
t4=*((C_word*)lf[38]+1);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6856,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6866,a[2]=t5,a[3]=t4,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:172: scheme#string-append */
t7=*((C_word*)lf[15]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[41];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* k6854 in chicken.compiler.support#quit-compiling in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6856,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6859,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:173: scheme#newline */
t3=*((C_word*)lf[23]+1);{
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

/* k6857 in k6854 in chicken.compiler.support#quit-compiling in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6859,c,av);}
/* support.scm:174: chicken.base#exit */
t2=*((C_word*)lf[39]+1);{
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

/* k6864 in chicken.compiler.support#quit-compiling in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_6866,c,av);}{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[40]+1);
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
av2[5]=((C_word*)t0)[4];
C_apply(6,av2);}}

/* ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6868(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +10,c,2)))){
C_save_and_reclaim((void*)f_6868,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+10);
t3=C_build_rest(&a,c,3,av);
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
t4=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t6=*((C_word*)lf[38]+1);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6872,a[2]=t6,a[3]=t5,a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_symbolp(((C_word*)t4)[1]))){
t8=((C_word*)t4)[1];
t9=C_i_car(((C_word*)t5)[1]);
t10=C_set_block_item(t4,0,t9);
t11=C_i_cdr(((C_word*)t5)[1]);
t12=C_set_block_item(t5,0,t11);
t13=t7;
f_6872(t13,t8);}
else{
t8=t7;
f_6872(t8,C_SCHEME_FALSE);}}

/* k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6872(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_6872,2,t0,t1);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6875,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
t3=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[32]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6921,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* support.scm:185: ##sys#print */
t5=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[49];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t3=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[32]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6942,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* support.scm:186: ##sys#print */
t5=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[50];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k6873 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6875(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_6875,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6876,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)((C_word*)t0)[3])[1];
t4=C_i_check_list_2(t3,lf[44]);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6886,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6894,a[2]=t7,a[3]=t2,tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_6894(t9,t5,t3);}

/* g800 in k6873 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6876(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_6876,3,t0,t1,t2);}
/* support.scm:187: g833 */
t3=*((C_word*)lf[40]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[43];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6884 in k6873 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6886(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_6886,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6889,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:188: chicken.base#print-call-chain */
t3=*((C_word*)lf[45]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(0);
av2[4]=*((C_word*)lf[46]+1);
av2[5]=lf[47];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}

/* k6887 in k6884 in k6873 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6889,c,av);}
/* support.scm:189: chicken.base#exit */
t2=*((C_word*)lf[39]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_fix(70);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* for-each-loop799 in k6873 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_6894(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_6894,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6904,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* support.scm:187: g800 */
t4=((C_word*)t0)[3];
f_6876(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k6902 in for-each-loop799 in k6873 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6904,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_6894(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k6919 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6921,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6924,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:185: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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

/* k6922 in k6919 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6924,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6927,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:185: ##sys#print */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[48];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k6925 in k6922 in k6919 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6927,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6930,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:185: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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

/* k6928 in k6925 in k6922 in k6919 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6930,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6933,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:185: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
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

/* k6931 in k6928 in k6925 in k6922 in k6919 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6933(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6933,c,av);}
/* support.scm:185: ##sys#write-char-0 */
t2=*((C_word*)lf[26]+1);{
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

/* k6940 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_6942,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6945,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:186: ##sys#print */
t3=*((C_word*)lf[27]+1);{
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

/* k6943 in k6940 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6945(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_6945,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6948,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:186: ##sys#write-char-0 */
t3=*((C_word*)lf[26]+1);{
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

/* k6946 in k6943 in k6940 in k6870 in ##sys#syntax-error-hook in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6948(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6948,c,av);}
/* support.scm:186: ##sys#write-char-0 */
t2=*((C_word*)lf[26]+1);{
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

/* chicken.compiler.support#emit-syntax-trace-info in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_6965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6965,c,av);}
t4=*((C_word*)lf[46]+1);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_emit_syntax_trace_info(t2,t3,C_slot(*((C_word*)lf[46]+1),C_fix(14)));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* chicken.compiler.support#check-signature in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7019(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,3)))){
C_save_and_reclaim((void *)f_7019,c,av);}
a=C_alloc(2);
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7025,tmp=(C_word)a,a+=2,tmp);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=(
  f_7025(t3,t4)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* loop in chicken.compiler.support#check-signature in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_7025(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t2))){
return(C_i_nullp(t1));}
else{
t3=C_i_symbolp(t2);
if(C_truep(t3)){
return(t3);}
else{
if(C_truep(C_i_nullp(t1))){
return(C_SCHEME_FALSE);}
else{
t5=C_i_cdr(t1);
t6=C_i_cdr(t2);
t1=t5;
t2=t6;
goto loop;}}}}

/* chicken.compiler.support#build-lambda-list in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7060(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_7060,c,av);}
a=C_alloc(6);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7066,a[2]=t4,a[3]=t6,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_7066(t8,t1,t2,t3);}

/* loop in chicken.compiler.support#build-lambda-list in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7066(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(33,0,3)))){
C_save_and_reclaim_args((void *)trf_7066,4,t0,t1,t2,t3);}
a=C_alloc(33);
t4=C_i_zerop(t3);
t5=(C_truep(t4)?t4:C_i_nullp(t2));
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=(C_truep(((C_word*)t0)[2])?((C_word*)t0)[2]:C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_i_car(t2);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7088,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
t8=C_u_i_cdr(t2);
t9=C_s_a_i_minus(&a,2,t3,C_fix(1));
/* support.scm:217: loop */
t11=t7;
t12=t8;
t13=t9;
t1=t11;
t2=t12;
t3=t13;
goto loop;}}

/* k7086 in loop in chicken.compiler.support#build-lambda-list in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7088,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7097(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7097,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7109,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7113,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* ##sys#string->list */
t5=*((C_word*)lf[60]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7107 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7109,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,C_make_character(34),t1);
/* ##sys#list->string */
t3=*((C_word*)lf[56]+1);{
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

/* k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7113(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7113,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7115,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_7115(t5,((C_word*)t0)[2],t1);}

/* loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7115(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_7115,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[57];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_fix(C_character_code(t3));
t5=C_fixnum_lessp(t4,C_fix(32));
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7137,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=t4,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
if(C_truep(t5)){
t7=t6;
f_7137(t7,t5);}
else{
t7=C_fixnum_greater_or_equal_p(t4,C_fix(127));
t8=t6;
f_7137(t8,(C_truep(t7)?t7:C_u_i_memq(t3,lf[64])));}}}

/* k7135 in loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7137(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7137,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7144,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[5],C_fix(8)))){
t3=t2;
f_7144(t3,lf[62]);}
else{
t3=C_fixnum_lessp(((C_word*)t0)[5],C_fix(64));
t4=t2;
f_7144(t4,(C_truep(t3)?lf[63]:C_SCHEME_END_OF_LIST));}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7180,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* support.scm:236: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_7115(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}}

/* k7142 in k7135 in loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7144(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_7144,2,t0,t1);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7148,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7158,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* ##sys#fixnum->string */
t4=*((C_word*)lf[61]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(8);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k7146 in k7142 in k7135 in loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7148(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_7148,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7152,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* support.scm:235: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_7115(t3,t2,C_u_i_cdr(((C_word*)t0)[5]));}

/* k7150 in k7146 in k7142 in k7135 in loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7152(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_7152,c,av);}
/* support.scm:230: scheme#append */
t2=*((C_word*)lf[58]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[59];
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k7156 in k7142 in k7135 in loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7158(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7158,c,av);}
/* ##sys#string->list */
t2=*((C_word*)lf[60]+1);{
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

/* k7178 in k7135 in loop in k7111 in chicken.compiler.support#c-ify-string in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7180(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7180,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#valid-c-identifier? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7196(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7196,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7200,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7244,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* support.scm:240: chicken.string#->string */
t5=*((C_word*)lf[66]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7198 in chicken.compiler.support#valid-c-identifier? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,3)))){
C_save_and_reclaim((void *)f_7200,c,av);}
a=C_alloc(2);
if(C_truep(C_i_pairp(t1))){
t2=C_u_i_car(t1);
t3=C_u_i_char_alphabeticp(t2);
t4=(C_truep(t3)?t3:C_u_i_char_equalp(C_make_character(95),t2));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7221,tmp=(C_word)a,a+=2,tmp);
/* support.scm:244: every */
f_5670(((C_word*)t0)[2],t5,C_u_i_cdr(t1));}
else{
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a7220 in k7198 in chicken.compiler.support#valid-c-identifier? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7221,c,av);}
t3=C_u_i_char_alphabeticp(t2);
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_u_i_char_numericp(t2);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=(C_truep(t4)?t4:C_u_i_char_equalp(C_make_character(95),t2));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k7242 in chicken.compiler.support#valid-c-identifier? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7244(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7244,c,av);}
/* ##sys#string->list */
t2=*((C_word*)lf[60]+1);{
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

/* chicken.compiler.support#bytes->words in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7246,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub927(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#words->bytes in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7253,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=stub932(C_SCHEME_UNDEFINED,C_i_foreign_fixnum_argumentp(t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#check-and-open-input-file in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_7260,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
if(C_truep(C_i_string_equal_p(t2,lf[70]))){
t4=*((C_word*)lf[71]+1);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=*((C_word*)lf[71]+1);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7273,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* support.scm:254: chicken.file#file-exists? */
t5=*((C_word*)lf[75]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k7271 in chicken.compiler.support#check-and-open-input-file in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7273(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7273,c,av);}
if(C_truep(t1)){
/* support.scm:254: scheme#open-input-file */
t2=*((C_word*)lf[72]+1);{
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
t2=C_i_nullp(((C_word*)t0)[4]);
t3=(C_truep(t2)?t2:C_i_not(C_i_car(((C_word*)t0)[4])));
if(C_truep(t3)){
/* support.scm:256: quit-compiling */
t4=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[73];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* support.scm:257: quit-compiling */
t4=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[74];
av2[3]=C_i_car(((C_word*)t0)[4]);
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}}

/* chicken.compiler.support#close-checked-input-file in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7304(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7304,c,av);}
if(C_truep(C_i_string_equal_p(t3,lf[77]))){
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* support.scm:260: scheme#close-input-port */
t4=*((C_word*)lf[78]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* chicken.compiler.support#fold-inner in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7316(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7316,c,av);}
a=C_alloc(4);
t4=C_i_cdr(t3);
if(C_truep(C_i_nullp(t4))){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7330,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:265: scheme#reverse */
t6=*((C_word*)lf[80]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}

/* k7328 in chicken.compiler.support#fold-inner in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_7330,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7332,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_7332(t5,((C_word*)t0)[3],t1);}

/* fold in k7328 in chicken.compiler.support#fold-inner in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7332(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_7332,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_cddr(t2);
if(C_truep(C_i_nullp(t3))){
t4=C_u_i_cdr(t2);
t5=C_u_i_car(t4);
t6=C_u_i_car(t2);
t7=C_a_i_list2(&a,2,t5,t6);{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t7;
C_apply(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7358,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* support.scm:270: fold */
t9=t4;
t10=C_u_i_cdr(t2);
t1=t9;
t2=t10;
goto loop;}}

/* k7356 in fold in k7328 in chicken.compiler.support#fold-inner in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_7358,c,av);}
a=C_alloc(6);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_a_i_list2(&a,2,t1,t2);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t3;
C_apply(4,av2);}}

/* chicken.compiler.support#follow-without-loop in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7372(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_7372,4,t1,t2,t3,t4);}
a=C_alloc(7);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7378,a[2]=t4,a[3]=t6,a[4]=t3,tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_7378(t8,t1,t2,C_SCHEME_END_OF_LIST);}

/* loop in chicken.compiler.support#follow-without-loop in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7378(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_7378,4,t0,t1,t2,t3);}
a=C_alloc(5);
if(C_truep(C_i_member(t2,t3))){
/* support.scm:275: abort */
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7393,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* support.scm:276: proc */
t5=((C_word*)t0)[4];{
C_word av2[4];
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* a7392 in loop in chicken.compiler.support#follow-without-loop in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7393(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7393,c,av);}
a=C_alloc(3);
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
/* support.scm:276: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_7378(t4,t1,t2,t3);}

/* a7408 in k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7409(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7409,c,av);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7417,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* support.scm:279: scheme#symbol->string */
t5=*((C_word*)lf[236]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7415 in a7408 in k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7417(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7417,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7421,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:279: scheme#symbol->string */
t3=*((C_word*)lf[236]+1);{
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

/* k7419 in k7415 in a7408 in k12010 in k12004 in k12001 in chicken.compiler.support#emit-global-inline-file in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7421,c,av);}
/* support.scm:279: scheme#string<? */
t2=*((C_word*)lf[235]+1);{
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

/* chicken.compiler.support#read-expressions in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7423(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7423,c,av);}
a=C_alloc(4);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[71]+1):C_get_rest_arg(c,2,av,2,t0));
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7434,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:282: scheme#read */
t5=*((C_word*)lf[83]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7432 in chicken.compiler.support#read-expressions in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7434(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_7434,c,av);}
a=C_alloc(6);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7436,a[2]=t3,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t5=((C_word*)t3)[1];
f_7436(t5,((C_word*)t0)[3],t1,C_fix(0),C_SCHEME_END_OF_LIST);}

/* doloop978 in k7432 in chicken.compiler.support#read-expressions in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7436(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_7436,5,t0,t1,t2,t3,t4);}
a=C_alloc(7);
if(C_truep(C_eofp(t2))){
/* support.scm:285: scheme#reverse */
t5=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t1;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7453,a[2]=t3,a[3]=t2,a[4]=t4,a[5]=((C_word*)t0)[2],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* support.scm:282: scheme#read */
t6=*((C_word*)lf[83]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}

/* k7451 in doloop978 in k7432 in chicken.compiler.support#read-expressions in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7453(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,4)))){
C_save_and_reclaim((void *)f_7453,c,av);}
a=C_alloc(32);
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1));
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t4=((C_word*)((C_word*)t0)[5])[1];
f_7436(t4,((C_word*)t0)[6],t1,t2,t3);}

/* chicken.base#bwp-object? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7467,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_bwpp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#constant? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7470(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7470,c,av);}
a=C_alloc(4);
t3=C_i_numberp(t2);
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_charp(t2);
if(C_truep(t4)){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_stringp(t2);
if(C_truep(t5)){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_booleanp(t2);
if(C_truep(t6)){
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_eofp(t2);
if(C_truep(t7)){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_bwpp(t2);
if(C_truep(t8)){
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7510,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:300: chicken.blob#blob? */
t10=*((C_word*)lf[88]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}}}}}}}

/* k7508 in chicken.compiler.support#constant? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7510,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_vectorp(((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7522,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:302: ##sys#srfi-4-vector? */
t4=*((C_word*)lf[87]+1);{
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

/* k7520 in k7508 in chicken.compiler.support#constant? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7522(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7522,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_pairp(((C_word*)t0)[3]);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?C_eqp(lf[86],C_u_i_car(((C_word*)t0)[3])):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.compiler.support#collapsable-literal? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7538(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7538,c,av);}
t3=C_booleanp(t2);
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_charp(t2);
if(C_truep(t4)){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eofp(t2);
if(C_truep(t5)){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_bwpp(t2);
if(C_truep(t6)){
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_i_numberp(t2);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=(C_truep(t7)?t7:C_i_symbolp(t2));
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}}}}

/* chicken.compiler.support#immediate? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7574,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7578,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnump(t2))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7624,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* support.scm:314: big-fixnum? */
t5=*((C_word*)lf[91]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=t3;
f_7578(t4,C_SCHEME_FALSE);}}

/* k7576 in chicken.compiler.support#immediate? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7578(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,1)))){
C_save_and_reclaim_args((void *)trf_7578,2,t0,t1);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(C_SCHEME_UNDEFINED,((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_nullp(((C_word*)t0)[3]);
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eofp(((C_word*)t0)[3]);
if(C_truep(t4)){
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_bwpp(((C_word*)t0)[3]);
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_charp(((C_word*)t0)[3]);
t7=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t7;
av2[1]=(C_truep(t6)?t6:C_booleanp(((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}}}}}

/* k7622 in chicken.compiler.support#immediate? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7624(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7624,c,av);}
t2=((C_word*)t0)[2];
f_7578(t2,C_i_not(t1));}

/* chicken.compiler.support#basic-literal? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7626(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7626,c,av);}
a=C_alloc(4);
t3=C_i_nullp(t2);
if(C_truep(t3)){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_symbolp(t2);
if(C_truep(t4)){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7642,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:325: constant? */
t6=*((C_word*)lf[85]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}}

/* k7640 in chicken.compiler.support#basic-literal? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7642(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7642,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7648,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_vectorp(((C_word*)t0)[3]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7680,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:326: scheme#vector->list */
t4=*((C_word*)lf[93]+1);{
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
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_7648(2,av2);}}}}

/* k7646 in k7640 in chicken.compiler.support#basic-literal? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7648(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7648,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[3]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7663,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:328: basic-literal? */
t3=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* k7661 in k7646 in k7640 in chicken.compiler.support#basic-literal? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7663(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7663,c,av);}
if(C_truep(t1)){
/* support.scm:329: basic-literal? */
t2=*((C_word*)lf[92]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_u_i_cdr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k7678 in k7640 in chicken.compiler.support#basic-literal? in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7680,c,av);}
/* support.scm:326: every */
f_5670(((C_word*)t0)[2],*((C_word*)lf[92]+1),t1);}

/* chicken.compiler.support#canonicalize-begin-body in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7682,c,av);}
a=C_alloc(5);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7688,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_7688(t6,t1,t2);}

/* loop in chicken.compiler.support#canonicalize-begin-body in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7688(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_7688,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[95];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_cdr(t2);
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_u_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_u_i_car(t2);
t5=C_i_equalp(t4,lf[96]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7712,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t5)){
t7=t6;
f_7712(t7,t5);}
else{
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7743,a[2]=t6,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* support.scm:340: constant? */
t8=*((C_word*)lf[85]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}}}

/* k7710 in loop in chicken.compiler.support#canonicalize-begin-body in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7712(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7712,2,t0,t1);}
a=C_alloc(5);
if(C_truep(t1)){
/* support.scm:342: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_7688(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7738,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* support.scm:343: chicken.base#gensym */
t3=*((C_word*)lf[98]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[99];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k7726 in k7736 in k7710 in loop in chicken.compiler.support#canonicalize-begin-body in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7728,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[97],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7736 in k7710 in loop in chicken.compiler.support#canonicalize-begin-body in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7738(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7738,c,av);}
a=C_alloc(13);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,t1,t2);
t4=C_a_i_list(&a,1,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7728,a[2]=((C_word*)t0)[3],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* support.scm:344: loop */
t6=((C_word*)((C_word*)t0)[4])[1];
f_7688(t6,t5,C_u_i_cdr(((C_word*)t0)[2]));}

/* k7741 in loop in chicken.compiler.support#canonicalize-begin-body in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7743,c,av);}
t2=((C_word*)t0)[2];
f_7712(t2,(C_truep(t1)?t1:C_i_equalp(((C_word*)t0)[3],lf[100])));}

/* k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7757(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_7757,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7760,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* support.scm:349: chicken.condition#condition-property-accessor */
t3=*((C_word*)lf[537]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[538];
av2[3]=lf[539];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7760(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(45,c,6)))){
C_save_and_reclaim((void *)f_7760,c,av);}
a=C_alloc(45);
t2=C_mutate((C_word*)lf[101]+1 /* (set! chicken.compiler.support#string->expr ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7761,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp));
t3=C_mutate((C_word*)lf[108]+1 /* (set! chicken.compiler.support#llist-length ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7875,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate((C_word*)lf[109]+1 /* (set! chicken.compiler.support#llist-match? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7878,tmp=(C_word)a,a+=2,tmp));
t5=lf[110] /* chicken.compiler.support#profile-info-vector-name */ =C_SCHEME_FALSE;;
t6=C_mutate((C_word*)lf[111]+1 /* (set! chicken.compiler.support#reset-profile-info-vector-name! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7923,tmp=(C_word)a,a+=2,tmp));
t7=lf[114] /* chicken.compiler.support#profile-lambda-list */ =C_SCHEME_END_OF_LIST;;
t8=lf[115] /* chicken.compiler.support#profile-lambda-index */ =C_fix(0);;
t9=C_mutate((C_word*)lf[116]+1 /* (set! chicken.compiler.support#expand-profile-lambda ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7932,tmp=(C_word)a,a+=2,tmp));
t10=C_mutate((C_word*)lf[122]+1 /* (set! chicken.compiler.support#profiling-prelude-exps ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7987,tmp=(C_word)a,a+=2,tmp));
t11=C_mutate((C_word*)lf[127]+1 /* (set! chicken.compiler.support#db-get ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8076,tmp=(C_word)a,a+=2,tmp));
t12=C_mutate((C_word*)lf[129]+1 /* (set! chicken.compiler.support#db-get-all ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8094,tmp=(C_word)a,a+=2,tmp));
t13=C_mutate((C_word*)lf[131]+1 /* (set! chicken.compiler.support#db-put! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8112,tmp=(C_word)a,a+=2,tmp));
t14=C_mutate((C_word*)lf[133]+1 /* (set! chicken.compiler.support#collect! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8158,tmp=(C_word)a,a+=2,tmp));
t15=C_mutate((C_word*)lf[134]+1 /* (set! chicken.compiler.support#db-get-list ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8210,tmp=(C_word)a,a+=2,tmp));
t16=C_mutate((C_word*)lf[135]+1 /* (set! chicken.compiler.support#make-node ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8220,tmp=(C_word)a,a+=2,tmp));
t17=C_mutate((C_word*)lf[137]+1 /* (set! chicken.compiler.support#node? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8226,tmp=(C_word)a,a+=2,tmp));
t18=C_mutate((C_word*)lf[138]+1 /* (set! chicken.compiler.support#node-class ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8232,tmp=(C_word)a,a+=2,tmp));
t19=C_mutate((C_word*)lf[140]+1 /* (set! chicken.compiler.support#node-class-set! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8241,tmp=(C_word)a,a+=2,tmp));
t20=C_mutate((C_word*)lf[142]+1 /* (set! chicken.compiler.support#node-parameters ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8250,tmp=(C_word)a,a+=2,tmp));
t21=C_mutate((C_word*)lf[144]+1 /* (set! chicken.compiler.support#node-parameters-set! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8259,tmp=(C_word)a,a+=2,tmp));
t22=C_mutate((C_word*)lf[145]+1 /* (set! chicken.compiler.support#node-subexpressions ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8268,tmp=(C_word)a,a+=2,tmp));
t23=C_mutate((C_word*)lf[147]+1 /* (set! chicken.compiler.support#node-subexpressions-set! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8277,tmp=(C_word)a,a+=2,tmp));
t24=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8287,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t25=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17914,tmp=(C_word)a,a+=2,tmp);
/* support.scm:460: chicken.base#set-record-printer! */
t26=*((C_word*)lf[536]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t26;
av2[1]=t24;
av2[2]=lf[136];
av2[3]=t25;
((C_proc)(void*)(*((C_word*)t26+1)))(4,av2);}}

/* chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7761,c,av);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7765,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7770,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* support.scm:351: scheme#call-with-current-continuation */
t5=*((C_word*)lf[107]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k7763 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7765(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7765,c,av);}
/* support.scm:350: g1097 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7770(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7770,c,av);}
a=C_alloc(10);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7776,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7801,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:351: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[106]+1);{
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

/* a7775 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7776(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_7776,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7782,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* support.scm:351: k1094 */
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a7781 in a7775 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7782(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_7782,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7790,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7793,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* support.scm:354: exn? */
t4=((C_word*)t0)[5];{
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

/* k7788 in a7781 in a7775 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_7790,c,av);}
/* support.scm:352: quit-compiling */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[102];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k7791 in a7781 in a7775 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7793(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7793,c,av);}
if(C_truep(t1)){
/* support.scm:355: exn-msg */
t2=((C_word*)t0)[2];{
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
/* support.scm:356: chicken.string#->string */
t2=*((C_word*)lf[66]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7801(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_7801,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7803,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7856,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7873,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* tmp14908 */
t5=t2;
f_7803(t5,t4);}

/* tmp14908 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7803(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_7803,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7807,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7829,tmp=(C_word)a,a+=2,tmp);
/* support.scm:357: chicken.port#with-input-from-string */
t4=*((C_word*)lf[105]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k7805 in tmp14908 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7807,c,av);}
a=C_alloc(3);
if(C_truep(C_i_nullp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[103];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_i_cdr(t1);
t3=C_i_nullp(t2);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_u_i_car(t1):C_a_i_cons(&a,2,lf[104],t1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* a7828 in tmp14908 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_7829,c,av);}
a=C_alloc(5);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7835,a[2]=t3,tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t3)[1];
f_7835(t5,t1,C_SCHEME_END_OF_LIST);}

/* loop in a7828 in tmp14908 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7835(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_7835,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7839,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* support.scm:361: scheme#read */
t4=*((C_word*)lf[83]+1);{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k7837 in loop in a7828 in tmp14908 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7839(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7839,c,av);}
a=C_alloc(3);
if(C_truep(C_eofp(t1))){
/* support.scm:363: scheme#reverse */
t2=*((C_word*)lf[80]+1);{
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
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[3]);
/* support.scm:364: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_7835(t3,((C_word*)t0)[2],t2);}}

/* tmp24909 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_7856(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_7856,3,t0,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7862,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* support.scm:351: k1094 */
t4=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a7861 in tmp24909 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7862,c,av);}{
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

/* k7871 in a7800 in a7769 in chicken.compiler.support#string->expr in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7873,c,av);}
a=C_alloc(3);
/* tmp24909 */
t2=((C_word*)t0)[2];
f_7856(t2,((C_word*)t0)[3],C_a_i_list(&a,1,t1));}

/* chicken.compiler.support#llist-length in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7875,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_u_i_length(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#llist-match? in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,3)))){
C_save_and_reclaim((void *)f_7878,c,av);}
a=C_alloc(2);
t4=(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_7884,tmp=(C_word)a,a+=2,tmp);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=(
  f_7884(t2,t3)
);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* loop in chicken.compiler.support#llist-match? in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_7884(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(C_i_nullp(t2));}
else{
t3=C_i_symbolp(t1);
if(C_truep(t3)){
return(t3);}
else{
if(C_truep(C_i_nullp(t2))){
return(C_i_not_pair_p(t1));}
else{
t5=C_i_cdr(t1);
t6=C_i_cdr(t2);
t1=t5;
t2=t6;
goto loop;}}}}

/* chicken.compiler.support#reset-profile-info-vector-name! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7923,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7928,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:385: make-random-name */
t3=*((C_word*)lf[112]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[113];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k7926 in chicken.compiler.support#reset-profile-info-vector-name! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7928(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7928,c,av);}
t2=C_mutate(&lf[110] /* (set! chicken.compiler.support#profile-info-vector-name ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#expand-profile-lambda in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7932(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_7932,c,av);}
a=C_alloc(7);
t5=lf[115];
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7936,a[2]=t5,a[3]=t2,a[4]=t3,a[5]=t4,a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* support.scm:392: chicken.base#gensym */
t7=*((C_word*)lf[98]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k7934 in chicken.compiler.support#expand-profile-lambda in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7936(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(131,c,1)))){
C_save_and_reclaim((void *)f_7936,c,av);}
a=C_alloc(131);
t2=lf[114];
t3=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,t3,lf[114]);
t5=C_mutate(&lf[114] /* (set! chicken.compiler.support#profile-lambda-list ...) */,t4);
t6=C_mutate(&lf[115] /* (set! chicken.compiler.support#profile-lambda-index ...) */,C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1)));
t7=C_a_i_list(&a,2,lf[86],((C_word*)t0)[2]);
t8=C_a_i_list(&a,3,lf[117],t7,lf[110]);
t9=C_a_i_list(&a,3,lf[118],C_SCHEME_END_OF_LIST,t8);
t10=C_a_i_list(&a,3,lf[118],((C_word*)t0)[4],((C_word*)t0)[5]);
t11=C_a_i_list(&a,3,lf[119],t10,t1);
t12=C_a_i_list(&a,3,lf[118],C_SCHEME_END_OF_LIST,t11);
t13=C_a_i_list(&a,2,lf[86],((C_word*)t0)[2]);
t14=C_a_i_list(&a,3,lf[120],t13,lf[110]);
t15=C_a_i_list(&a,3,lf[118],C_SCHEME_END_OF_LIST,t14);
t16=C_a_i_list(&a,4,lf[121],t9,t12,t15);
t17=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t17;
av2[1]=C_a_i_list(&a,3,lf[118],t1,t16);
((C_proc)(void*)(*((C_word*)t17+1)))(2,av2);}}

/* chicken.compiler.support#profiling-prelude-exps in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_7987(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(46,c,3)))){
C_save_and_reclaim((void *)f_7987,c,av);}
a=C_alloc(46);
t3=C_i_length(lf[114]);
t4=C_a_i_list(&a,2,lf[86],t3);
t5=C_a_i_list(&a,2,lf[86],t2);
t6=C_a_i_list(&a,3,lf[123],t4,t5);
t7=C_a_i_list(&a,3,lf[124],lf[110],t6);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=lf[114];
t13=C_i_check_list_2(lf[114],lf[125]);
t14=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8024,a[2]=t1,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8026,a[2]=t10,a[3]=t16,a[4]=t11,tmp=(C_word)a,a+=5,tmp));
t18=((C_word*)t16)[1];
f_8026(t18,t14,lf[114]);}

/* k8022 in chicken.compiler.support#profiling-prelude-exps in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8024(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8024,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1152 in chicken.compiler.support#profiling-prelude-exps in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8026(C_word t0,C_word t1,C_word t2){
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
loop:
if(C_unlikely(!C_demand(C_calculate_demand(27,0,2)))){
C_save_and_reclaim_args((void *)trf_8026,3,t0,t1,t2);}
a=C_alloc(27);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_a_i_list(&a,2,lf[86],t4);
t6=C_u_i_cdr(t3);
t7=C_a_i_list(&a,2,lf[86],t6);
t8=C_a_i_list(&a,4,lf[126],lf[110],t5,t7);
t9=C_a_i_cons(&a,2,t8,C_SCHEME_END_OF_LIST);
t10=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t9);
t11=C_mutate(((C_word *)((C_word*)t0)[2])+1,t9);
t13=t1;
t14=C_slot(t2,C_fix(1));
t1=t13;
t2=t14;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.compiler.support#db-get in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_8076,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8080,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:417: chicken.internal#hash-table-ref */
t6=*((C_word*)lf[128]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k8078 in chicken.compiler.support#db-get in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8080,c,av);}
if(C_truep(t1)){
t2=C_i_assq(((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?C_slot(t2,C_fix(1)):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +4,c,3)))){
C_save_and_reclaim((void*)f_8094,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+4);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8098,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:423: chicken.internal#hash-table-ref */
t6=*((C_word*)lf[128]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k8096 in chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8098(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_8098,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8106,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[130]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5963,a[2]=t2,a[3]=t5,tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t5)[1];
f_5963(t7,((C_word*)t0)[3],((C_word*)t0)[2]);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* a8105 in k8096 in chicken.compiler.support#db-get-all in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static C_word C_fcall f_8106(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_assq(t1,((C_word*)t0)[2]));}

/* chicken.compiler.support#db-put! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8112(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_8112,c,av);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8116,a[2]=t4,a[3]=t1,a[4]=t5,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* support.scm:429: chicken.internal#hash-table-ref */
t7=*((C_word*)lf[128]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* k8114 in chicken.compiler.support#db-put! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8116(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8116,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_setslot(t2,C_fix(1),((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(((C_word*)t0)[4])){
t3=C_slot(t1,C_fix(1));
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[4]);
t5=C_a_i_cons(&a,2,t4,t3);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_i_setslot(t1,C_fix(1),t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t3=C_SCHEME_UNDEFINED;
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}
else{
if(C_truep(((C_word*)t0)[4])){
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[4]);
t3=C_a_i_list1(&a,1,t2);
/* support.scm:434: chicken.internal#hash-table-set! */
t4=*((C_word*)lf[132]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* chicken.compiler.support#collect! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8158(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_8158,c,av);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8162,a[2]=t4,a[3]=t5,a[4]=t1,a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* support.scm:437: chicken.internal#hash-table-ref */
t7=*((C_word*)lf[128]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}

/* k8160 in chicken.compiler.support#collect! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8162(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_8162,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=C_slot(t2,C_fix(1));
t4=C_a_i_cons(&a,2,((C_word*)t0)[3],t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_setslot(t2,C_fix(1),t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=C_a_i_list1(&a,1,((C_word*)t0)[3]);
t4=C_slot(t1,C_fix(1));
t5=C_a_i_cons(&a,2,((C_word*)t0)[2],t3);
t6=C_a_i_cons(&a,2,t5,t4);
t7=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_i_setslot(t1,C_fix(1),t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list1(&a,1,t2);
/* support.scm:442: chicken.internal#hash-table-set! */
t4=*((C_word*)lf[132]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* chicken.compiler.support#db-get-list in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8210,c,av);}
a=C_alloc(3);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8214,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:445: db-get */
t6=*((C_word*)lf[127]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k8212 in chicken.compiler.support#db-get-list in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8214(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8214,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?t1:C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#make-node in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8220(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8220,c,av);}
a=C_alloc(5);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_record4(&a,4,lf[136],t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* chicken.compiler.support#node? in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8226(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8226,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_structurep(t2,lf[136]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.compiler.support#node-class in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8232(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8232,c,av);}
t3=C_i_check_structure_2(t2,lf[136],lf[139]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#node-class-set! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8241(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8241,c,av);}
t4=C_i_check_structure_2(t2,lf[136],C_SCHEME_FALSE);
/* support.scm:453: ##sys#block-set! */
t5=*((C_word*)lf[141]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(1);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* chicken.compiler.support#node-parameters in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8250(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8250,c,av);}
t3=C_i_check_structure_2(t2,lf[136],lf[143]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(2));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#node-parameters-set! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8259(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8259,c,av);}
t4=C_i_check_structure_2(t2,lf[136],C_SCHEME_FALSE);
/* support.scm:453: ##sys#block-set! */
t5=*((C_word*)lf[141]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(2);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* chicken.compiler.support#node-subexpressions in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8268(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8268,c,av);}
t3=C_i_check_structure_2(t2,lf[136],lf[146]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_i_block_ref(t2,C_fix(3));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#node-subexpressions-set! in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8277(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8277,c,av);}
t4=C_i_check_structure_2(t2,lf[136],C_SCHEME_FALSE);
/* support.scm:453: ##sys#block-set! */
t5=*((C_word*)lf[141]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(3);
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8287(C_word c,C_word *av){
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
C_word t60;
C_word t61;
C_word t62;
C_word t63;
C_word t64;
C_word t65;
C_word t66;
C_word t67;
C_word t68;
C_word t69;
C_word t70;
C_word t71;
C_word t72;
C_word t73;
C_word t74;
C_word t75;
C_word t76;
C_word t77;
C_word t78;
C_word t79;
C_word t80;
C_word t81;
C_word t82;
C_word t83;
C_word t84;
C_word t85;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(158,c,8)))){
C_save_and_reclaim((void *)f_8287,c,av);}
a=C_alloc(158);
t2=C_mutate((C_word*)lf[135]+1 /* (set! chicken.compiler.support#make-node ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8289,tmp=(C_word)a,a+=2,tmp));
t3=C_mutate((C_word*)lf[148]+1 /* (set! chicken.compiler.support#varnode ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8295,tmp=(C_word)a,a+=2,tmp));
t4=C_mutate((C_word*)lf[150]+1 /* (set! chicken.compiler.support#qnode ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8310,tmp=(C_word)a,a+=2,tmp));
t5=C_mutate((C_word*)lf[151]+1 /* (set! chicken.compiler.support#build-node-graph ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_8325,tmp=(C_word)a,a+=2,tmp));
t6=C_mutate((C_word*)lf[188]+1 /* (set! chicken.compiler.support#build-expression-tree ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_9521,tmp=(C_word)a,a+=2,tmp));
t7=C_mutate((C_word*)lf[201]+1 /* (set! chicken.compiler.support#fold-boolean ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_10391,tmp=(C_word)a,a+=2,tmp));
t8=C_mutate((C_word*)lf[203]+1 /* (set! chicken.compiler.support#inline-lambda-bindings ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_10443,tmp=(C_word)a,a+=2,tmp));
t9=C_mutate((C_word*)lf[223]+1 /* (set! chicken.compiler.support#replace-rest-op-with-list-ops ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_11518,tmp=(C_word)a,a+=2,tmp));
t10=C_mutate((C_word*)lf[222]+1 /* (set! chicken.compiler.support#tree-copy ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_11682,tmp=(C_word)a,a+=2,tmp));
t11=C_mutate((C_word*)lf[231]+1 /* (set! chicken.compiler.support#copy-node ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_11712,tmp=(C_word)a,a+=2,tmp));
t12=C_mutate((C_word*)lf[210]+1 /* (set! chicken.compiler.support#copy-node! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_11750,tmp=(C_word)a,a+=2,tmp));
t13=C_mutate((C_word*)lf[232]+1 /* (set! chicken.compiler.support#emit-global-inline-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_11946,tmp=(C_word)a,a+=2,tmp));
t14=C_mutate((C_word*)lf[258]+1 /* (set! chicken.compiler.support#load-inline-file ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12264,tmp=(C_word)a,a+=2,tmp));
t15=C_mutate((C_word*)lf[261]+1 /* (set! chicken.compiler.support#match-node ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12320,tmp=(C_word)a,a+=2,tmp));
t16=C_mutate((C_word*)lf[264]+1 /* (set! chicken.compiler.support#expression-has-side-effects? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12553,tmp=(C_word)a,a+=2,tmp));
t17=C_mutate((C_word*)lf[267]+1 /* (set! chicken.compiler.support#simple-lambda-node? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12662,tmp=(C_word)a,a+=2,tmp));
t18=C_mutate((C_word*)lf[268]+1 /* (set! chicken.compiler.support#dump-undefined-globals ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12788,tmp=(C_word)a,a+=2,tmp));
t19=C_mutate((C_word*)lf[273]+1 /* (set! chicken.compiler.support#dump-defined-globals ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12829,tmp=(C_word)a,a+=2,tmp));
t20=C_mutate((C_word*)lf[274]+1 /* (set! chicken.compiler.support#dump-global-refs ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12866,tmp=(C_word)a,a+=2,tmp));
t21=C_mutate((C_word*)lf[275]+1 /* (set! ##sys#toplevel-definition-hook ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12915,tmp=(C_word)a,a+=2,tmp));
t22=C_set_block_item(lf[266] /* chicken.compiler.support#foreign-callback-stubs */,0,C_SCHEME_END_OF_LIST);
t23=C_mutate((C_word*)lf[281]+1 /* (set! chicken.compiler.support#make-foreign-callback-stub ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12943,tmp=(C_word)a,a+=2,tmp));
t24=C_mutate((C_word*)lf[283]+1 /* (set! chicken.compiler.support#foreign-callback-stub? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12949,tmp=(C_word)a,a+=2,tmp));
t25=C_mutate((C_word*)lf[265]+1 /* (set! chicken.compiler.support#foreign-callback-stub-id ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12955,tmp=(C_word)a,a+=2,tmp));
t26=C_mutate((C_word*)lf[285]+1 /* (set! chicken.compiler.support#foreign-callback-stub-name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12964,tmp=(C_word)a,a+=2,tmp));
t27=C_mutate((C_word*)lf[287]+1 /* (set! chicken.compiler.support#foreign-callback-stub-qualifiers ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12973,tmp=(C_word)a,a+=2,tmp));
t28=C_mutate((C_word*)lf[289]+1 /* (set! chicken.compiler.support#foreign-callback-stub-return-type ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12982,tmp=(C_word)a,a+=2,tmp));
t29=C_mutate((C_word*)lf[291]+1 /* (set! chicken.compiler.support#foreign-callback-stub-argument-types ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_12991,tmp=(C_word)a,a+=2,tmp));
t30=C_mutate((C_word*)lf[293]+1 /* (set! chicken.compiler.support#register-foreign-callback-stub! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_13000,tmp=(C_word)a,a+=2,tmp));
t31=lf[295] /* chicken.compiler.support#foreign-type-table */ =C_SCHEME_FALSE;;
t32=C_mutate((C_word*)lf[296]+1 /* (set! chicken.compiler.support#clear-foreign-type-table! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_13029,tmp=(C_word)a,a+=2,tmp));
t33=C_mutate((C_word*)lf[299]+1 /* (set! chicken.compiler.support#register-foreign-type! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_13042,tmp=(C_word)a,a+=2,tmp));
t34=C_mutate((C_word*)lf[300]+1 /* (set! chicken.compiler.support#lookup-foreign-type ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_13096,tmp=(C_word)a,a+=2,tmp));
t35=lf[301];
t36=C_mutate((C_word*)lf[302]+1 /* (set! chicken.compiler.support#foreign-type-check ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13102,a[2]=t35,tmp=(C_word)a,a+=3,tmp));
t37=C_mutate(&lf[399] /* (set! chicken.compiler.support#foreign-type-result-converter ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14178,tmp=(C_word)a,a+=2,tmp));
t38=C_mutate(&lf[400] /* (set! chicken.compiler.support#foreign-type-argument-converter ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14199,tmp=(C_word)a,a+=2,tmp));
t39=C_mutate((C_word*)lf[401]+1 /* (set! chicken.compiler.support#foreign-type-convert-result ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14220,tmp=(C_word)a,a+=2,tmp));
t40=C_mutate((C_word*)lf[402]+1 /* (set! chicken.compiler.support#foreign-type-convert-argument ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14235,tmp=(C_word)a,a+=2,tmp));
t41=C_mutate((C_word*)lf[403]+1 /* (set! chicken.compiler.support#final-foreign-type ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14250,tmp=(C_word)a,a+=2,tmp));
t42=C_mutate((C_word*)lf[405]+1 /* (set! chicken.compiler.support#estimate-foreign-result-size ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14289,tmp=(C_word)a,a+=2,tmp));
t43=C_mutate((C_word*)lf[411]+1 /* (set! chicken.compiler.support#estimate-foreign-result-location-size ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_14764,tmp=(C_word)a,a+=2,tmp));
t44=C_mutate((C_word*)lf[414]+1 /* (set! chicken.compiler.support#finish-foreign-result ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_15214,tmp=(C_word)a,a+=2,tmp));
t45=C_mutate((C_word*)lf[428]+1 /* (set! chicken.compiler.support#foreign-type->scrutiny-type ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_15482,tmp=(C_word)a,a+=2,tmp));
t46=C_mutate((C_word*)lf[456]+1 /* (set! chicken.compiler.support#scan-used-variables ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16136,tmp=(C_word)a,a+=2,tmp));
t47=C_mutate((C_word*)lf[457]+1 /* (set! chicken.compiler.support#scan-free-variables ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16291,tmp=(C_word)a,a+=2,tmp));
t48=C_mutate((C_word*)lf[458]+1 /* (set! chicken.compiler.support#make-block-variable-literal ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16522,tmp=(C_word)a,a+=2,tmp));
t49=C_mutate((C_word*)lf[460]+1 /* (set! chicken.compiler.support#block-variable-literal? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16528,tmp=(C_word)a,a+=2,tmp));
t50=C_mutate((C_word*)lf[461]+1 /* (set! chicken.compiler.support#block-variable-literal-name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16534,tmp=(C_word)a,a+=2,tmp));
t51=C_mutate((C_word*)lf[112]+1 /* (set! chicken.compiler.support#make-random-name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16543,tmp=(C_word)a,a+=2,tmp));
t52=lf[465] /* chicken.compiler.support#real-name-table */ =C_SCHEME_FALSE;;
t53=C_mutate((C_word*)lf[466]+1 /* (set! chicken.compiler.support#clear-real-name-table! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16590,tmp=(C_word)a,a+=2,tmp));
t54=C_mutate((C_word*)lf[467]+1 /* (set! chicken.compiler.support#set-real-name! ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16597,tmp=(C_word)a,a+=2,tmp));
t55=C_mutate((C_word*)lf[468]+1 /* (set! chicken.compiler.support#get-real-name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16603,tmp=(C_word)a,a+=2,tmp));
t56=C_mutate((C_word*)lf[177]+1 /* (set! chicken.compiler.support#real-name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16610,tmp=(C_word)a,a+=2,tmp));
t57=C_mutate((C_word*)lf[475]+1 /* (set! chicken.compiler.support#real-name2 ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16730,tmp=(C_word)a,a+=2,tmp));
t58=C_mutate((C_word*)lf[476]+1 /* (set! chicken.compiler.support#display-real-name-table ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16742,tmp=(C_word)a,a+=2,tmp));
t59=C_mutate((C_word*)lf[477]+1 /* (set! chicken.compiler.support#source-info->string ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16766,tmp=(C_word)a,a+=2,tmp));
t60=C_mutate((C_word*)lf[483]+1 /* (set! chicken.compiler.support#source-info->name ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16801,tmp=(C_word)a,a+=2,tmp));
t61=C_mutate((C_word*)lf[484]+1 /* (set! chicken.compiler.support#source-info->line ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16816,tmp=(C_word)a,a+=2,tmp));
t62=C_mutate((C_word*)lf[485]+1 /* (set! chicken.compiler.support#call-info ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16828,tmp=(C_word)a,a+=2,tmp));
t63=C_mutate((C_word*)lf[488]+1 /* (set! chicken.compiler.support#constant-form-eval ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_16865,tmp=(C_word)a,a+=2,tmp));
t64=C_mutate((C_word*)lf[495]+1 /* (set! chicken.compiler.support#maybe-constant-fold-call ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17095,tmp=(C_word)a,a+=2,tmp));
t65=C_mutate(&lf[491] /* (set! chicken.compiler.support#encodeable-literal? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17194,tmp=(C_word)a,a+=2,tmp));
t66=C_mutate((C_word*)lf[500]+1 /* (set! chicken.compiler.support#dump-nodes ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17331,tmp=(C_word)a,a+=2,tmp));
t67=C_mutate((C_word*)lf[502]+1 /* (set! chicken.compiler.support#read/source-info ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17487,tmp=(C_word)a,a+=2,tmp));
t68=*((C_word*)lf[504]+1);
t69=C_mutate((C_word*)lf[504]+1 /* (set! ##sys#user-read-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_17493,a[2]=t68,tmp=(C_word)a,a+=3,tmp));
t70=C_mutate((C_word*)lf[91]+1 /* (set! chicken.compiler.support#big-fixnum? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17587,tmp=(C_word)a,a+=2,tmp));
t71=C_mutate((C_word*)lf[511]+1 /* (set! chicken.compiler.support#small-bignum? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17611,tmp=(C_word)a,a+=2,tmp));
t72=C_mutate((C_word*)lf[279]+1 /* (set! chicken.compiler.support#hide-variable ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17635,tmp=(C_word)a,a+=2,tmp));
t73=C_mutate((C_word*)lf[513]+1 /* (set! chicken.compiler.support#export-variable ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17655,tmp=(C_word)a,a+=2,tmp));
t74=C_mutate((C_word*)lf[278]+1 /* (set! chicken.compiler.support#variable-hidden? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17675,tmp=(C_word)a,a+=2,tmp));
t75=C_mutate((C_word*)lf[256]+1 /* (set! chicken.compiler.support#variable-visible? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17697,tmp=(C_word)a,a+=2,tmp));
t76=C_mutate((C_word*)lf[515]+1 /* (set! chicken.compiler.support#mark-variable ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17722,tmp=(C_word)a,a+=2,tmp));
t77=C_mutate((C_word*)lf[516]+1 /* (set! chicken.compiler.support#variable-mark ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17737,tmp=(C_word)a,a+=2,tmp));
t78=C_mutate((C_word*)lf[517]+1 /* (set! chicken.compiler.support#intrinsic? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17743,tmp=(C_word)a,a+=2,tmp));
t79=C_mutate((C_word*)lf[497]+1 /* (set! chicken.compiler.support#foldable? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17754,tmp=(C_word)a,a+=2,tmp));
t80=C_mutate((C_word*)lf[496]+1 /* (set! chicken.compiler.support#predicate? ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17765,tmp=(C_word)a,a+=2,tmp));
t81=C_mutate((C_word*)lf[520]+1 /* (set! chicken.compiler.support#load-identifier-database ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17776,tmp=(C_word)a,a+=2,tmp));
t82=C_mutate((C_word*)lf[528]+1 /* (set! chicken.compiler.support#print-version ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17871,tmp=(C_word)a,a+=2,tmp));
t83=C_mutate((C_word*)lf[531]+1 /* (set! chicken.compiler.support#print-usage ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17896,tmp=(C_word)a,a+=2,tmp));
t84=C_mutate((C_word*)lf[533]+1 /* (set! chicken.compiler.support#print-debug-options ...) */,(*a=C_CLOSURE_TYPE|1,a[1]=(C_word)f_17908,tmp=(C_word)a,a+=2,tmp));
t85=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t85;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t85+1)))(2,av2);}}

/* chicken.compiler.support#make-node in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8289(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8289,c,av);}
a=C_alloc(5);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_record4(&a,4,lf[136],t2,t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* chicken.compiler.support#varnode in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_8295,c,av);}
a=C_alloc(8);
t3=C_a_i_list1(&a,1,t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[149],t3,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#qnode in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8310(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_8310,c,av);}
a=C_alloc(8);
t3=C_a_i_list1(&a,1,t2);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[86],t3,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8325(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_8325,c,av);}
a=C_alloc(12);
t3=C_fix(0);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8328,a[2]=t6,a[3]=t4,tmp=(C_word)a,a+=4,tmp));
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9512,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* support.scm:563: walk */
t9=((C_word*)t6)[1];
f_8328(t9,t8,t2);}

/* walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8328(C_word t0,C_word t1,C_word t2){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(20,0,3)))){
C_save_and_reclaim_args((void *)trf_8328,3,t0,t1,t2);}
a=C_alloc(20);
if(C_truep(C_i_symbolp(t2))){
/* support.scm:473: varnode */
t3=*((C_word*)lf[148]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_i_structurep(t2,lf[136]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_pairp(t2);
if(C_truep(C_i_not(t3))){
/* support.scm:475: bomb */
t4=*((C_word*)lf[13]+1);{
C_word av2[4];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[152];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=C_i_car(t2);
if(C_truep(C_i_symbolp(t4))){
t5=C_u_i_car(t2);
t6=C_eqp(t5,lf[153]);
t7=(C_truep(t6)?t6:C_eqp(t5,lf[154]));
if(C_truep(t7)){
t8=C_u_i_car(t2);
t9=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t10=t9;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=((C_word*)t11)[1];
t13=C_u_i_cdr(t2);
t14=C_i_check_list_2(t13,lf[125]);
t15=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8395,a[2]=t1,a[3]=t8,tmp=(C_word)a,a+=4,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8397,a[2]=t11,a[3]=t17,a[4]=((C_word*)t0)[2],a[5]=t12,tmp=(C_word)a,a+=6,tmp));
t19=((C_word*)t17)[1];
f_8397(t19,t15,t13);}
else{
t8=C_eqp(t5,lf[86]);
if(C_truep(t8)){
t9=C_i_cadr(t2);
t10=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8445,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8448,a[2]=t10,a[3]=t9,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_numberp(t9))){
t12=C_eqp(lf[159],*((C_word*)lf[8]+1));
t13=t11;
f_8448(t13,(C_truep(t12)?C_i_not(C_i_integerp(t9)):C_SCHEME_FALSE));}
else{
t12=t11;
f_8448(t12,C_SCHEME_FALSE);}}
else{
t9=C_eqp(t5,lf[97]);
if(C_truep(t9)){
t10=C_i_cadr(t2);
t11=C_i_caddr(t2);
if(C_truep(C_i_nullp(t10))){
/* support.scm:493: walk */
t22=t1;
t23=t11;
t1=t22;
t2=t23;
goto loop;}
else{
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8505,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=t11,tmp=(C_word)a,a+=6,tmp);
t13=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t14=t13;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=((C_word*)t15)[1];
t17=C_i_check_list_2(t10,lf[125]);
t18=C_SCHEME_UNDEFINED;
t19=(*a=C_VECTOR_TYPE|1,a[1]=t18,tmp=(C_word)a,a+=2,tmp);
t20=C_set_block_item(t19,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6036,a[2]=t15,a[3]=t19,a[4]=t16,tmp=(C_word)a,a+=5,tmp));
t21=((C_word*)t19)[1];
f_6036(t21,t12,t10);}}
else{
t10=C_eqp(t5,lf[160]);
t11=(C_truep(t10)?t10:C_eqp(t5,lf[118]));
if(C_truep(t11)){
t12=C_i_cadr(t2);
t13=C_a_i_list1(&a,1,t12);
t14=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8602,a[2]=t1,a[3]=t13,tmp=(C_word)a,a+=4,tmp);
/* support.scm:499: walk */
t22=t14;
t23=C_i_caddr(t2);
t1=t22;
t2=t23;
goto loop;}
else{
t12=C_eqp(t5,lf[161]);
if(C_truep(t12)){
t13=C_i_cadr(t2);
t14=C_i_caddr(t2);
t15=C_a_i_list2(&a,2,t13,t14);
t16=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8636,a[2]=t1,a[3]=t15,tmp=(C_word)a,a+=4,tmp);
/* support.scm:503: walk */
t22=t16;
t23=C_i_cadddr(t2);
t1=t22;
t2=t23;
goto loop;}
else{
t13=C_eqp(t5,lf[162]);
if(C_truep(t13)){
t14=C_i_cdddr(t2);
t15=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8790,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t14,tmp=(C_word)a,a+=6,tmp);
t16=C_u_i_cdr(t2);
t17=C_u_i_cdr(t16);
/* support.scm:506: walk */
t22=t15;
t23=C_u_i_car(t17);
t1=t22;
t2=t23;
goto loop;}
else{
t14=C_eqp(t5,lf[166]);
if(C_truep(t14)){
t15=C_i_cadr(t2);
t16=C_u_i_car(t2);
t17=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8817,a[2]=t2,a[3]=t1,a[4]=t16,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t15))){
t18=C_eqp(lf[86],C_u_i_car(t15));
if(C_truep(t18)){
t19=C_i_cadr(t15);
t20=t17;
f_8817(t20,C_a_i_list1(&a,1,t19));}
else{
t19=t17;
f_8817(t19,C_a_i_list1(&a,1,t15));}}
else{
t18=t17;
f_8817(t18,C_a_i_list1(&a,1,t15));}}
else{
t15=C_eqp(t5,lf[167]);
t16=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8890,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t5,a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t15)){
t17=t16;
f_8890(t17,t15);}
else{
t17=C_eqp(t5,lf[184]);
t18=t16;
f_8890(t18,(C_truep(t17)?t17:C_eqp(t5,lf[185])));}}}}}}}}}
else{
t5=C_a_i_list1(&a,1,C_SCHEME_FALSE);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9467,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9469,a[2]=t8,a[3]=t12,a[4]=((C_word*)t0)[2],a[5]=t9,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_9469(t14,t10,t2);}}}}}

/* k8393 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8395,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],((C_word*)t0)[3],C_SCHEME_END_OF_LIST,t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1324 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8397(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8397,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8422,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:478: g1330 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8420 in map-loop1324 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8422,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8397(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k8443 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8445(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8445,c,av);}
/* support.scm:481: qnode */
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

/* k8446 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8448(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_8448,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8451,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* support.scm:485: chicken.base#warning */
t3=*((C_word*)lf[157]+1);{
C_word av2[4];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[158];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
/* support.scm:481: qnode */
t2=*((C_word*)lf[150]+1);{
C_word av2[3];
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}}

/* k8449 in k8446 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8451(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8451,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8458,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* support.scm:487: scheme#truncate */
t3=*((C_word*)lf[156]+1);{
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

/* k8456 in k8449 in k8446 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8458(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8458,c,av);}
/* support.scm:487: scheme#inexact->exact */
t2=*((C_word*)lf[155]+1);{
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

/* k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8505(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_8505,c,av);}
a=C_alloc(25);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8509,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8514,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
t8=C_i_cadr(((C_word*)t0)[4]);
t9=C_i_check_list_2(t8,lf[125]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8531,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8541,a[2]=t5,a[3]=t12,a[4]=t7,a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_8541(t14,t10,t8);}

/* k8507 in k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8509,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[97],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* g1367 in k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8514(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_8514,3,t0,t1,t2);}
/* support.scm:496: walk */
t3=((C_word*)((C_word*)t0)[2])[1];
f_8328(t3,t1,C_i_cadr(t2));}

/* k8529 in k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8531(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_8531,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8539,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* support.scm:497: walk */
t3=((C_word*)((C_word*)t0)[3])[1];
f_8328(t3,t2,((C_word*)t0)[4]);}

/* k8537 in k8529 in k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_8539,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* support.scm:496: scheme#append */
t3=*((C_word*)lf[58]+1);{
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

/* map-loop1361 in k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8541(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8541,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8566,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:496: g1367 */
t4=((C_word*)t0)[4];
f_8514(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8564 in map-loop1361 in k8503 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8566,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8541(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k8600 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_8602,c,av);}
a=C_alloc(8);
t2=C_a_i_list1(&a,1,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[160],((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8634 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_8636,c,av);}
a=C_alloc(8);
t2=C_a_i_list1(&a,1,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[161],((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8667(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,0,2)))){
C_save_and_reclaim_args((void *)trf_8667,5,t0,t1,t2,t3,t4);}
a=C_alloc(14);
if(C_truep(C_i_nullp(t2))){
t5=C_i_cadr(((C_word*)t0)[2]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8711,a[2]=t5,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* support.scm:510: scheme#reverse */
t7=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t5=C_i_caar(t2);
t6=C_eqp(lf[163],t5);
if(C_truep(t6)){
t7=C_i_cadr(((C_word*)t0)[2]);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8753,a[2]=t7,a[3]=t1,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=t2,tmp=(C_word)a,a+=7,tmp);
t9=C_a_i_cons(&a,2,lf[165],t3);
/* support.scm:516: scheme#reverse */
t10=*((C_word*)lf[80]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t8;
av2[2]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t7=C_u_i_cdr(t2);
t8=C_i_caar(t2);
t9=C_a_i_cons(&a,2,t8,t3);
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8774,a[2]=t4,a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=t7,a[6]=t9,tmp=(C_word)a,a+=7,tmp);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8778,a[2]=((C_word*)t0)[3],a[3]=t10,tmp=(C_word)a,a+=4,tmp);
/* support.scm:520: scheme#cadar */
t12=*((C_word*)lf[164]+1);{
C_word av2[3];
av2[0]=t12;
av2[1]=t11;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}}}

/* k8688 in k8709 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8690,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[162],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8709 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8711(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8711,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8690,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=C_a_i_record4(&a,4,lf[136],lf[154],C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[4]);
/* support.scm:511: scheme#reverse */
t6=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t3;
av2[2]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k8731 in k8751 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8733(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8733,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[162],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8739 in k8751 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8741(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8741,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* support.scm:517: scheme#reverse */
t3=*((C_word*)lf[80]+1);{
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

/* k8743 in k8751 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8745,c,av);}
/* support.scm:517: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_8328(t2,((C_word*)t0)[3],t1);}

/* k8751 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8753(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8753,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8733,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8741,a[2]=((C_word*)t0)[4],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8745,a[2]=((C_word*)t0)[5],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* support.scm:517: scheme#cadar */
t6=*((C_word*)lf[164]+1);{
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

/* k8772 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8774(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8774,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* support.scm:518: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_8667(t3,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],t2);}

/* k8776 in loop in k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8778(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8778,c,av);}
/* support.scm:520: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_8328(t2,((C_word*)t0)[3],t1);}

/* k8788 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_8790,c,av);}
a=C_alloc(10);
t2=C_a_i_list1(&a,1,t1);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8667,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t4,tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_8667(t6,((C_word*)t0)[4],((C_word*)t0)[5],C_SCHEME_END_OF_LIST,t2);}

/* k8815 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8817(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_8817,2,t0,t1);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_u_i_cdr(((C_word*)t0)[2]);
t7=C_u_i_cdr(t6);
t8=C_i_check_list_2(t7,lf[125]);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8829,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8831,a[2]=t4,a[3]=t11,a[4]=((C_word*)t0)[5],a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_8831(t13,t9,t7);}

/* k8827 in k8815 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8829,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1432 in k8815 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8831(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8831,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8856,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:526: g1438 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8854 in map-loop1432 in k8815 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8856,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8831(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8890(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,3)))){
C_save_and_reclaim_args((void *)trf_8890,2,t0,t1);}
a=C_alloc(21);
if(C_truep(t1)){
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_a_i_list1(&a,1,t3);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_u_i_cdr(((C_word*)t0)[2]);
t10=C_u_i_cdr(t9);
t11=C_i_check_list_2(t10,lf[125]);
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8916,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8918,a[2]=t7,a[3]=t14,a[4]=((C_word*)t0)[4],a[5]=t8,tmp=(C_word)a,a+=6,tmp));
t16=((C_word*)t14)[1];
f_8918(t16,t12,t10);}
else{
t2=C_eqp(((C_word*)t0)[5],lf[168]);
if(C_truep(t2)){
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_record4(&a,4,lf[136],t3,t4,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=C_eqp(((C_word*)t0)[5],lf[169]);
if(C_truep(t3)){
t4=C_i_cadr(((C_word*)t0)[2]);
t5=C_a_i_list2(&a,2,t4,C_SCHEME_TRUE);
t6=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t6;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[169],t5,C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[5],lf[124]);
t5=(C_truep(t4)?t4:C_eqp(((C_word*)t0)[5],lf[170]));
if(C_truep(t5)){
t6=C_i_cadr(((C_word*)t0)[2]);
t7=C_a_i_list1(&a,1,t6);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_u_i_cdr(((C_word*)t0)[2]);
t13=C_u_i_cdr(t12);
t14=C_i_check_list_2(t13,lf[125]);
t15=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9027,a[2]=((C_word*)t0)[3],a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9029,a[2]=t10,a[3]=t17,a[4]=((C_word*)t0)[4],a[5]=t11,tmp=(C_word)a,a+=6,tmp));
t19=((C_word*)t17)[1];
f_9029(t19,t15,t13);}
else{
t6=C_eqp(((C_word*)t0)[5],lf[171]);
if(C_truep(t6)){
t7=C_i_cadr(((C_word*)t0)[2]);
t8=C_i_cadr(t7);
t9=C_i_caddr(((C_word*)t0)[2]);
t10=C_i_cadr(t9);
t11=C_i_cadddr(((C_word*)t0)[2]);
t12=C_i_cadr(t11);
t13=C_i_cddddr(((C_word*)t0)[2]);
t14=C_i_car(t13);
t15=C_i_cadr(t14);
t16=C_a_i_list4(&a,4,t8,t10,t12,t15);
t17=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9094,a[2]=((C_word*)t0)[3],a[3]=t16,tmp=(C_word)a,a+=4,tmp);
/* support.scm:542: walk */
t18=((C_word*)((C_word*)t0)[4])[1];
f_8328(t18,t17,C_i_list_ref(((C_word*)t0)[2],C_fix(5)));}
else{
t7=C_eqp(((C_word*)t0)[5],lf[172]);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9135,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t7)){
t9=t8;
f_9135(t9,t7);}
else{
t9=C_eqp(((C_word*)t0)[5],lf[180]);
if(C_truep(t9)){
t10=t8;
f_9135(t10,t9);}
else{
t10=C_eqp(((C_word*)t0)[5],lf[181]);
if(C_truep(t10)){
t11=t8;
f_9135(t11,t10);}
else{
t11=C_eqp(((C_word*)t0)[5],lf[182]);
t12=t8;
f_9135(t12,(C_truep(t11)?t11:C_eqp(((C_word*)t0)[5],lf[183])));}}}}}}}}}

/* k8914 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_8916,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1469 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_8918(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_8918,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8943,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:528: g1475 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k8941 in map-loop1469 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_8943(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_8943,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8918(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9025 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9027(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_9027,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[124],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1513 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9029(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9029,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9054,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:536: g1519 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9052 in map-loop1513 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9054,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9029(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9092 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,1)))){
C_save_and_reclaim((void *)f_9094,c,av);}
a=C_alloc(8);
t2=C_a_i_list1(&a,1,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[171],((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9135(C_word t0,C_word t1){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,0,4)))){
C_save_and_reclaim_args((void *)trf_9135,2,t0,t1);}
a=C_alloc(20);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_cddr(((C_word*)t0)[2]);
t9=C_i_check_list_2(t8,lf[125]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9164,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9166,a[2]=t6,a[3]=t12,a[4]=((C_word*)t0)[4],a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_9166(t14,t10,t8);}
else{
t2=C_eqp(((C_word*)t0)[5],lf[173]);
if(C_truep(t2)){
t3=C_a_i_list1(&a,1,C_SCHEME_TRUE);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_u_i_cdr(((C_word*)t0)[2]);
t9=C_i_check_list_2(t8,lf[125]);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9227,a[2]=((C_word*)t0)[3],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9229,a[2]=t6,a[3]=t12,a[4]=((C_word*)t0)[4],a[5]=t7,tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_9229(t14,t10,t8);}
else{
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9266,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9272,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* support.scm:549: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}}}

/* k9162 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9164(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_9164,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1562 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9166(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9166,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9191,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:545: g1568 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9189 in map-loop1562 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9191,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9166(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9225 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_9227,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[174],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1593 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9229(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9229,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9254,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:547: g1599 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9252 in map-loop1593 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9254,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9229(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* a9265 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9266,c,av);}
/* support.scm:549: ##sys#get-line-2 */
t2=*((C_word*)lf[175]+1);{
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

/* a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9272(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_9272,c,av);}
a=C_alloc(11);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9333,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t3,a[6]=t2,tmp=(C_word)a,a+=7,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9361,a[2]=((C_word*)t0)[4],a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* tweaks.scm:60: ##sys#get */
t6=*((C_word*)lf[178]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[179];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}

/* k9293 in k9335 in k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9295(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_9295,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[174],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1639 in k9335 in k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9297(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9297,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9322,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:561: g1645 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9320 in map-loop1639 in k9335 in k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 in ... */
static void C_ccall f_9322(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9322,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9297(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9333(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_9333,2,t0,t1);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9337,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9340,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* support.scm:557: real-name */
t4=*((C_word*)lf[177]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
/* support.scm:560: ##sys#symbol->string */
t3=*((C_word*)lf[176]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}

/* k9335 in k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9337(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_9337,c,av);}
a=C_alloc(23);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[3],lf[125]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9295,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9297,a[2]=t5,a[3]=t10,a[4]=((C_word*)t0)[5],a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_9297(t12,t8,((C_word*)t0)[3]);}

/* k9338 in k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9340(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_9340,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9347,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],t1);
f_9337(2,av2);}}
else{
/* support.scm:559: ##sys#symbol->string */
t3=*((C_word*)lf[176]+1);{
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

/* k9345 in k9338 in k9331 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_9347,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list2(&a,2,((C_word*)t0)[3],t1);
f_9337(2,av2);}}

/* k9359 in a9271 in k9133 in k8888 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9361(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_9361,c,av);}
a=C_alloc(29);
if(C_truep(t1)){
t2=((C_word*)((C_word*)t0)[2])[1];
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,C_s_a_i_plus(&a,2,t2,C_fix(1)));
t4=((C_word*)t0)[3];
f_9333(t4,C_SCHEME_TRUE);}
else{
t2=((C_word*)t0)[3];
f_9333(t2,C_SCHEME_FALSE);}}

/* k9465 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,1)))){
C_save_and_reclaim((void *)f_9467,c,av);}
a=C_alloc(5);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_record4(&a,4,lf[136],lf[174],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1670 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9469(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9469,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9494,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:562: g1676 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_8328(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9492 in map-loop1670 in walk in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9494(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9494,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9469(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9510 in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9512(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_9512,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9515,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=((C_word*)((C_word*)t0)[3])[1];
if(C_truep(C_i_positivep(t3))){
/* support.scm:565: debugging */
t4=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[186];
av2[3]=lf[187];
av2[4]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9513 in k9510 in chicken.compiler.support#build-node-graph in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9515,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9521(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_9521,c,av);}
a=C_alloc(5);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9527,a[2]=t4,tmp=(C_word)a,a+=3,tmp));
t6=((C_word*)t4)[1];
f_9527(t6,t1,t2);}

/* walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9527(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_9527,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_slot(t2,C_fix(3));
t4=C_slot(t2,C_fix(2));
t5=C_slot(t2,C_fix(1));
t6=C_eqp(t5,lf[153]);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9561,a[2]=t3,a[3]=t1,a[4]=t5,a[5]=((C_word*)t0)[2],a[6]=t4,tmp=(C_word)a,a+=7,tmp);
if(C_truep(t6)){
t8=t7;
f_9561(t8,t6);}
else{
t8=C_eqp(t5,lf[199]);
t9=t7;
f_9561(t9,(C_truep(t8)?t8:C_eqp(t5,lf[200])));}}

/* k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9561(C_word t0,C_word t1){
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
C_word t22;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(20,0,5)))){
C_save_and_reclaim_args((void *)trf_9561,2,t0,t1);}
a=C_alloc(20);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9574,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9576,a[2]=t4,a[3]=t9,a[4]=((C_word*)t0)[5],a[5]=t5,tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_9576(t11,t7,((C_word*)t0)[2]);}
else{
t2=C_eqp(((C_word*)t0)[4],lf[189]);
if(C_truep(t2)){
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9631,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9633,a[2]=t5,a[3]=t10,a[4]=((C_word*)t0)[5],a[5]=t6,tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_9633(t12,t8,((C_word*)t0)[2]);}
else{
t3=C_eqp(((C_word*)t0)[4],lf[149]);
if(C_truep(t3)){
t4=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_i_car(((C_word*)t0)[6]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[4],lf[86]);
if(C_truep(t4)){
t5=C_i_car(((C_word*)t0)[6]);
t6=C_booleanp(t5);
if(C_truep(t6)){
if(C_truep(t6)){
t7=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t7;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_u_i_car(((C_word*)t0)[6]);
t8=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t8;
av2[1]=C_a_i_list(&a,2,lf[86],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}
else{
t7=C_i_stringp(t5);
if(C_truep(t7)){
if(C_truep(t7)){
t8=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t8;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_u_i_car(((C_word*)t0)[6]);
t9=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t9;
av2[1]=C_a_i_list(&a,2,lf[86],t8);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
t8=C_i_numberp(t5);
t9=(C_truep(t8)?t8:C_charp(t5));
if(C_truep(t9)){
t10=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t10;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t10=C_u_i_car(((C_word*)t0)[6]);
t11=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t11;
av2[1]=C_a_i_list(&a,2,lf[86],t10);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}}}
else{
t5=C_eqp(((C_word*)t0)[4],lf[97]);
if(C_truep(t5)){
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t11=t10;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=((C_word*)t12)[1];
t14=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9731,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=t8,a[7]=t9,a[8]=t12,a[9]=t13,tmp=(C_word)a,a+=10,tmp);
/* support.scm:584: chicken.base#butlast */
t15=*((C_word*)lf[190]+1);{
C_word av2[3];
av2[0]=t15;
av2[1]=t14;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t15+1)))(3,av2);}}
else{
t6=C_eqp(((C_word*)t0)[4],lf[118]);
if(C_truep(t6)){
t7=C_i_cadr(((C_word*)t0)[6]);
t8=(C_truep(t7)?lf[160]:lf[118]);
t9=C_i_caddr(((C_word*)t0)[6]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9854,a[2]=((C_word*)t0)[3],a[3]=t8,a[4]=t9,tmp=(C_word)a,a+=5,tmp);
/* support.scm:591: walk */
t11=((C_word*)((C_word*)t0)[5])[1];
f_9527(t11,t10,C_i_car(((C_word*)t0)[2]));}
else{
t7=C_eqp(((C_word*)t0)[4],lf[161]);
if(C_truep(t7)){
t8=C_i_car(((C_word*)t0)[6]);
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9878,a[2]=((C_word*)t0)[3],a[3]=t8,tmp=(C_word)a,a+=4,tmp);
/* support.scm:593: walk */
t10=((C_word*)((C_word*)t0)[5])[1];
f_9527(t10,t9,C_i_car(((C_word*)t0)[2]));}
else{
t8=C_eqp(((C_word*)t0)[4],lf[192]);
if(C_truep(t8)){
/* support.scm:595: walk */
t9=((C_word*)((C_word*)t0)[5])[1];
f_9527(t9,((C_word*)t0)[3],C_i_car(((C_word*)t0)[2]));}
else{
t9=C_eqp(((C_word*)t0)[4],lf[162]);
if(C_truep(t9)){
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9912,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* support.scm:598: walk */
t11=((C_word*)((C_word*)t0)[5])[1];
f_9527(t11,t10,C_i_car(((C_word*)t0)[2]));}
else{
t10=C_eqp(((C_word*)t0)[4],lf[174]);
if(C_truep(t10)){
t11=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t12=t11;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=((C_word*)t13)[1];
t15=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t16=C_SCHEME_UNDEFINED;
t17=(*a=C_VECTOR_TYPE|1,a[1]=t16,tmp=(C_word)a,a+=2,tmp);
t18=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10002,a[2]=t13,a[3]=t17,a[4]=((C_word*)t0)[5],a[5]=t14,tmp=(C_word)a,a+=6,tmp));
t19=((C_word*)t17)[1];
f_10002(t19,((C_word*)t0)[3],((C_word*)t0)[2]);}
else{
t11=C_eqp(((C_word*)t0)[4],lf[185]);
if(C_truep(t11)){
t12=C_i_car(((C_word*)t0)[6]);
t13=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t14=t13;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=((C_word*)t15)[1];
t17=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t18=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10057,a[2]=((C_word*)t0)[3],a[3]=t12,tmp=(C_word)a,a+=4,tmp);
t19=C_SCHEME_UNDEFINED;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=C_set_block_item(t20,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10059,a[2]=t15,a[3]=t20,a[4]=((C_word*)t0)[5],a[5]=t16,tmp=(C_word)a,a+=6,tmp));
t22=((C_word*)t20)[1];
f_10059(t22,t18,((C_word*)t0)[2]);}
else{
t12=C_eqp(((C_word*)t0)[4],lf[154]);
if(C_truep(t12)){
t13=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t13;
av2[1]=C_a_i_list1(&a,1,((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}
else{
t13=C_eqp(((C_word*)t0)[4],lf[194]);
if(C_truep(t13)){
t14=C_i_car(((C_word*)t0)[6]);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10115,a[2]=((C_word*)t0)[5],a[3]=t16,tmp=(C_word)a,a+=4,tmp));
t18=((C_word*)t16)[1];
f_10115(t18,((C_word*)t0)[3],t14,((C_word*)t0)[2],C_SCHEME_END_OF_LIST);}
else{
t14=C_eqp(((C_word*)t0)[4],lf[195]);
t15=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10165,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t14)){
t16=t15;
f_10165(t16,t14);}
else{
t16=C_eqp(((C_word*)t0)[4],lf[196]);
if(C_truep(t16)){
t17=t15;
f_10165(t17,t16);}
else{
t17=C_eqp(((C_word*)t0)[4],lf[197]);
t18=t15;
f_10165(t18,(C_truep(t17)?t17:C_eqp(((C_word*)t0)[4],lf[198])));}}}}}}}}}}}}}}}}

/* k9572 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9574,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop1727 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9576(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9576,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9601,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:574: g1733 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9599 in map-loop1727 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9601,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9576(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9629 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9631(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_9631,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[189],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* map-loop1756 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9633(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9633,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9658,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:576: g1762 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9656 in map-loop1756 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9658,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9633(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_9731,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9734,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9801,a[2]=((C_word*)t0)[8],a[3]=t4,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[9],tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_9801(t6,t2,t1);}

/* k9732 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9734(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_9734,c,av);}
a=C_alloc(12);
t2=C_i_check_list_2(((C_word*)t0)[2],lf[125]);
t3=C_i_check_list_2(t1,lf[125]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9743,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9753,a[2]=((C_word*)t0)[6],a[3]=t6,a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_9753(t8,t4,((C_word*)t0)[2],t1);}

/* k9741 in k9732 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9743(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9743,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9747,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9751,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:585: last */
f_6070(t3,((C_word*)t0)[4]);}

/* k9745 in k9741 in k9732 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9747(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_9747,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[97],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9749 in k9741 in k9732 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9751(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9751,c,av);}
/* support.scm:585: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9527(t2,((C_word*)t0)[3],t1);}

/* map-loop1798 in k9732 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9753(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_9753,4,t0,t1,t2,t3);}
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

/* map-loop1819 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9801(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9801,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9826,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* support.scm:584: g1825 */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9527(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9824 in map-loop1819 in k9729 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9826(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9826,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_9801(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k9852 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9854(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_9854,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list3(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9876 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9878(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_9878,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[191],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9910 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9912(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_9912,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9916,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_i_cdr(((C_word*)t0)[3]);
t4=C_i_cdr(((C_word*)t0)[4]);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9926,a[2]=((C_word*)t0)[5],a[3]=t6,tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_9926(t8,t2,t3,t4);}

/* k9914 in k9910 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9916(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_9916,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[193],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop in k9910 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_fcall f_9926(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_9926,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_i_nullp(t2))){
if(C_truep(C_i_nullp(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9950,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* support.scm:603: walk */
t5=((C_word*)((C_word*)t0)[2])[1];
f_9527(t5,t4,C_i_car(t3));}}
else{
t4=C_i_car(t2);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9977,a[2]=t4,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t2,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* support.scm:604: walk */
t6=((C_word*)((C_word*)t0)[2])[1];
f_9527(t6,t5,C_i_car(t3));}}

/* k9948 in loop in k9910 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9950(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_9950,c,av);}
a=C_alloc(9);
t2=C_a_i_list(&a,2,lf[163],t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k9963 in k9975 in loop in k9910 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9965,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9975 in loop in k9910 in k9559 in walk in chicken.compiler.support#build-expression-tree in k8285 in k7758 in k7755 in k6609 in k5297 in k5294 in k5291 in k5288 in k5285 in k5282 in k5279 in k5276 in k5273 */
static void C_ccall f_9977(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_9977,c,av);}
a=C_alloc(10);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9965,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* support.scm:605: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_9926(t4,t3,C_u_i_cdr(((C_word*)t0)[5]),C_u_i_cdr(((C_word*)t0)[6]));}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_support_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("support"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_support_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(4021))){
C_save(t1);
C_rereclaim2(4021*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,541);
lf[0]=C_h_intern(&lf[0],7, C_text("support"));
lf[1]=C_h_intern(&lf[1],25, C_text("chicken.compiler.support#"));
lf[8]=C_h_intern(&lf[8],36, C_text("chicken.compiler.support#number-type"));
lf[9]=C_h_intern(&lf[9],7, C_text("generic"));
lf[10]=C_h_intern(&lf[10],31, C_text("chicken.compiler.support#unsafe"));
lf[11]=C_h_intern(&lf[11],46, C_text("chicken.compiler.support#compiler-cleanup-hook"));
lf[12]=C_h_intern(&lf[12],42, C_text("chicken.compiler.support#debugging-chicken"));
lf[13]=C_h_intern(&lf[13],29, C_text("chicken.compiler.support#bomb"));
lf[14]=C_h_intern(&lf[14],18, C_text("chicken.base#error"));
lf[15]=C_h_intern(&lf[15],20, C_text("scheme#string-append"));
lf[16]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032[internal compiler error] "));
lf[17]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031[internal compiler error]"));
lf[18]=C_h_intern(&lf[18],51, C_text("chicken.compiler.support#collected-debugging-output"));
lf[20]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001o\376\003\000\000\002\376\001\000\000\001\001x\376\003\000\000\002\376\001\000\000\001\001S\376\377\016"));
lf[22]=C_h_intern(&lf[22],34, C_text("chicken.compiler.support#debugging"));
lf[23]=C_h_intern(&lf[23],14, C_text("scheme#newline"));
lf[24]=C_h_intern(&lf[24],21, C_text("##sys#standard-output"));
lf[25]=C_h_intern(&lf[25],6, C_text("printf"));
lf[26]=C_h_intern(&lf[26],18, C_text("##sys#write-char-0"));
lf[27]=C_h_intern(&lf[27],11, C_text("##sys#print"));
lf[28]=C_h_intern(&lf[28],12, C_text("scheme#force"));
lf[29]=C_h_intern(&lf[29],14, C_text("scheme#display"));
lf[30]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[31]=C_h_intern(&lf[31],34, C_text("chicken.port#with-output-to-string"));
lf[32]=C_h_intern(&lf[32],7, C_text("fprintf"));
lf[33]=C_h_intern(&lf[33],25, C_text("chicken.base#flush-output"));
lf[34]=C_h_intern(&lf[34],46, C_text("chicken.compiler.support#with-debugging-output"));
lf[35]=C_h_intern(&lf[35],27, C_text("chicken.string#string-split"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[37]=C_h_intern(&lf[37],39, C_text("chicken.compiler.support#quit-compiling"));
lf[38]=C_h_intern(&lf[38],20, C_text("##sys#standard-error"));
lf[39]=C_h_intern(&lf[39],17, C_text("chicken.base#exit"));
lf[40]=C_h_intern(&lf[40],22, C_text("chicken.format#fprintf"));
lf[41]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010\012Error: "));
lf[42]=C_h_intern(&lf[42],23, C_text("##sys#syntax-error-hook"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005\011~s~%"));
lf[44]=C_h_intern(&lf[44],8, C_text("for-each"));
lf[45]=C_h_intern(&lf[45],29, C_text("chicken.base#print-call-chain"));
lf[46]=C_h_intern(&lf[46],20, C_text("##sys#current-thread"));
lf[47]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025\012\011Expansion history:\012"));
lf[48]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003): "));
lf[49]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017\012Syntax error ("));
lf[50]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017\012Syntax error: "));
lf[51]=C_h_intern(&lf[51],27, C_text("chicken.syntax#syntax-error"));
lf[52]=C_h_intern(&lf[52],47, C_text("chicken.compiler.support#emit-syntax-trace-info"));
lf[53]=C_h_intern(&lf[53],40, C_text("chicken.compiler.support#check-signature"));
lf[54]=C_h_intern(&lf[54],42, C_text("chicken.compiler.support#build-lambda-list"));
lf[55]=C_h_intern(&lf[55],37, C_text("chicken.compiler.support#c-ify-string"));
lf[56]=C_h_intern(&lf[56],18, C_text("##sys#list->string"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000\042\376\377\016"));
lf[58]=C_h_intern(&lf[58],13, C_text("scheme#append"));
lf[59]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000\134\376\377\016"));
lf[60]=C_h_intern(&lf[60],18, C_text("##sys#string->list"));
lf[61]=C_h_intern(&lf[61],20, C_text("##sys#fixnum->string"));
lf[62]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\0000\376\003\000\000\002\376\377\012\000\0000\376\377\016"));
lf[63]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\0000\376\377\016"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000\042\376\003\000\000\002\376\377\012\000\000\047\376\003\000\000\002\376\377\012\000\000\134\376\003\000\000\002\376\377\012\000\000\077\376\003\000\000\002\376\377\012\000\000\052\376\377\016"));
lf[65]=C_h_intern(&lf[65],44, C_text("chicken.compiler.support#valid-c-identifier\077"));
lf[66]=C_h_intern(&lf[66],23, C_text("chicken.string#->string"));
lf[67]=C_h_intern(&lf[67],37, C_text("chicken.compiler.support#bytes->words"));
lf[68]=C_h_intern(&lf[68],37, C_text("chicken.compiler.support#words->bytes"));
lf[69]=C_h_intern(&lf[69],50, C_text("chicken.compiler.support#check-and-open-input-file"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001-"));
lf[71]=C_h_intern(&lf[71],20, C_text("##sys#standard-input"));
lf[72]=C_h_intern(&lf[72],22, C_text("scheme#open-input-file"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024Can not open file ~s"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376B\000\000\031(~a) can not open file ~s"));
lf[75]=C_h_intern(&lf[75],25, C_text("chicken.file#file-exists\077"));
lf[76]=C_h_intern(&lf[76],49, C_text("chicken.compiler.support#close-checked-input-file"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001-"));
lf[78]=C_h_intern(&lf[78],23, C_text("scheme#close-input-port"));
lf[79]=C_h_intern(&lf[79],35, C_text("chicken.compiler.support#fold-inner"));
lf[80]=C_h_intern(&lf[80],14, C_text("scheme#reverse"));
lf[82]=C_h_intern(&lf[82],41, C_text("chicken.compiler.support#read-expressions"));
lf[83]=C_h_intern(&lf[83],11, C_text("scheme#read"));
lf[84]=C_h_intern(&lf[84],24, C_text("chicken.base#bwp-object\077"));
lf[85]=C_h_intern(&lf[85],34, C_text("chicken.compiler.support#constant\077"));
lf[86]=C_h_intern(&lf[86],5, C_text("quote"));
lf[87]=C_h_intern(&lf[87],20, C_text("##sys#srfi-4-vector\077"));
lf[88]=C_h_intern(&lf[88],18, C_text("chicken.blob#blob\077"));
lf[89]=C_h_intern(&lf[89],45, C_text("chicken.compiler.support#collapsable-literal\077"));
lf[90]=C_h_intern(&lf[90],35, C_text("chicken.compiler.support#immediate\077"));
lf[91]=C_h_intern(&lf[91],36, C_text("chicken.compiler.support#big-fixnum\077"));
lf[92]=C_h_intern(&lf[92],39, C_text("chicken.compiler.support#basic-literal\077"));
lf[93]=C_h_intern(&lf[93],19, C_text("scheme#vector->list"));
lf[94]=C_h_intern(&lf[94],48, C_text("chicken.compiler.support#canonicalize-begin-body"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[96]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[97]=C_h_intern(&lf[97],3, C_text("let"));
lf[98]=C_h_intern(&lf[98],19, C_text("chicken.base#gensym"));
lf[99]=C_h_intern(&lf[99],1, C_text("t"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001##sys#void\376\377\016"));
lf[101]=C_h_intern(&lf[101],37, C_text("chicken.compiler.support#string->expr"));
lf[102]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042cannot parse expression: ~s [~a]~%"));
lf[103]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[104]=C_h_intern(&lf[104],5, C_text("begin"));
lf[105]=C_h_intern(&lf[105],35, C_text("chicken.port#with-input-from-string"));
lf[106]=C_h_intern(&lf[106],40, C_text("chicken.condition#with-exception-handler"));
lf[107]=C_h_intern(&lf[107],37, C_text("scheme#call-with-current-continuation"));
lf[108]=C_h_intern(&lf[108],37, C_text("chicken.compiler.support#llist-length"));
lf[109]=C_h_intern(&lf[109],37, C_text("chicken.compiler.support#llist-match\077"));
lf[111]=C_h_intern(&lf[111],56, C_text("chicken.compiler.support#reset-profile-info-vector-name!"));
lf[112]=C_h_intern(&lf[112],41, C_text("chicken.compiler.support#make-random-name"));
lf[113]=C_h_intern(&lf[113],12, C_text("profile-info"));
lf[116]=C_h_intern(&lf[116],46, C_text("chicken.compiler.support#expand-profile-lambda"));
lf[117]=C_h_intern(&lf[117],19, C_text("##sys#profile-entry"));
lf[118]=C_h_intern(&lf[118],13, C_text("##core#lambda"));
lf[119]=C_h_intern(&lf[119],11, C_text("##sys#apply"));
lf[120]=C_h_intern(&lf[120],18, C_text("##sys#profile-exit"));
lf[121]=C_h_intern(&lf[121],18, C_text("##sys#dynamic-wind"));
lf[122]=C_h_intern(&lf[122],47, C_text("chicken.compiler.support#profiling-prelude-exps"));
lf[123]=C_h_intern(&lf[123],27, C_text("##sys#register-profile-info"));
lf[124]=C_h_intern(&lf[124],4, C_text("set!"));
lf[125]=C_h_intern(&lf[125],3, C_text("map"));
lf[126]=C_h_intern(&lf[126],30, C_text("##sys#set-profile-info-vector!"));
lf[127]=C_h_intern(&lf[127],31, C_text("chicken.compiler.support#db-get"));
lf[128]=C_h_intern(&lf[128],31, C_text("chicken.internal#hash-table-ref"));
lf[129]=C_h_intern(&lf[129],35, C_text("chicken.compiler.support#db-get-all"));
lf[130]=C_h_intern(&lf[130],5, C_text("foldr"));
lf[131]=C_h_intern(&lf[131],32, C_text("chicken.compiler.support#db-put!"));
lf[132]=C_h_intern(&lf[132],32, C_text("chicken.internal#hash-table-set!"));
lf[133]=C_h_intern(&lf[133],33, C_text("chicken.compiler.support#collect!"));
lf[134]=C_h_intern(&lf[134],36, C_text("chicken.compiler.support#db-get-list"));
lf[135]=C_h_intern(&lf[135],34, C_text("chicken.compiler.support#make-node"));
lf[136]=C_h_intern(&lf[136],29, C_text("chicken.compiler.support#node"));
lf[137]=C_h_intern(&lf[137],30, C_text("chicken.compiler.support#node\077"));
lf[138]=C_h_intern(&lf[138],35, C_text("chicken.compiler.support#node-class"));
lf[139]=C_h_intern(&lf[139],10, C_text("node-class"));
lf[140]=C_h_intern(&lf[140],40, C_text("chicken.compiler.support#node-class-set!"));
lf[141]=C_h_intern(&lf[141],16, C_text("##sys#block-set!"));
lf[142]=C_h_intern(&lf[142],40, C_text("chicken.compiler.support#node-parameters"));
lf[143]=C_h_intern(&lf[143],15, C_text("node-parameters"));
lf[144]=C_h_intern(&lf[144],45, C_text("chicken.compiler.support#node-parameters-set!"));
lf[145]=C_h_intern(&lf[145],44, C_text("chicken.compiler.support#node-subexpressions"));
lf[146]=C_h_intern(&lf[146],19, C_text("node-subexpressions"));
lf[147]=C_h_intern(&lf[147],49, C_text("chicken.compiler.support#node-subexpressions-set!"));
lf[148]=C_h_intern(&lf[148],32, C_text("chicken.compiler.support#varnode"));
lf[149]=C_h_intern(&lf[149],15, C_text("##core#variable"));
lf[150]=C_h_intern(&lf[150],30, C_text("chicken.compiler.support#qnode"));
lf[151]=C_h_intern(&lf[151],41, C_text("chicken.compiler.support#build-node-graph"));
lf[152]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016bad expression"));
lf[153]=C_h_intern(&lf[153],2, C_text("if"));
lf[154]=C_h_intern(&lf[154],16, C_text("##core#undefined"));
lf[155]=C_h_intern(&lf[155],21, C_text("scheme#inexact->exact"));
lf[156]=C_h_intern(&lf[156],15, C_text("scheme#truncate"));
lf[157]=C_h_intern(&lf[157],20, C_text("chicken.base#warning"));
lf[158]=C_decode_literal(C_heaptop,C_text("\376B\000\0006literal is out of range - will be truncated to integer"));
lf[159]=C_h_intern(&lf[159],6, C_text("fixnum"));
lf[160]=C_h_intern(&lf[160],6, C_text("lambda"));
lf[161]=C_h_intern(&lf[161],10, C_text("##core#the"));
lf[162]=C_h_intern(&lf[162],15, C_text("##core#typecase"));
lf[163]=C_h_intern(&lf[163],4, C_text("else"));
lf[164]=C_h_intern(&lf[164],12, C_text("scheme#cadar"));
lf[165]=C_h_intern(&lf[165],1, C_text("\052"));
lf[166]=C_h_intern(&lf[166],16, C_text("##core#primitive"));
lf[167]=C_h_intern(&lf[167],13, C_text("##core#inline"));
lf[168]=C_h_intern(&lf[168],18, C_text("##core#debug-event"));
lf[169]=C_h_intern(&lf[169],11, C_text("##core#proc"));
lf[170]=C_h_intern(&lf[170],11, C_text("##core#set!"));
lf[171]=C_h_intern(&lf[171],31, C_text("##core#foreign-callback-wrapper"));
lf[172]=C_h_intern(&lf[172],22, C_text("##core#inline_allocate"));
lf[173]=C_h_intern(&lf[173],10, C_text("##core#app"));
lf[174]=C_h_intern(&lf[174],11, C_text("##core#call"));
lf[175]=C_h_intern(&lf[175],16, C_text("##sys#get-line-2"));
lf[176]=C_h_intern(&lf[176],20, C_text("##sys#symbol->string"));
lf[177]=C_h_intern(&lf[177],34, C_text("chicken.compiler.support#real-name"));
lf[178]=C_h_intern(&lf[178],9, C_text("##sys#get"));
lf[179]=C_h_intern(&lf[179],36, C_text("##compiler#always-bound-to-procedure"));
lf[180]=C_h_intern(&lf[180],17, C_text("##core#inline_ref"));
lf[181]=C_h_intern(&lf[181],20, C_text("##core#inline_update"));
lf[182]=C_h_intern(&lf[182],21, C_text("##core#inline_loc_ref"));
lf[183]=C_h_intern(&lf[183],24, C_text("##core#inline_loc_update"));
lf[184]=C_h_intern(&lf[184],14, C_text("##core#provide"));
lf[185]=C_h_intern(&lf[185],15, C_text("##core#callunit"));
lf[186]=C_h_intern(&lf[186],1, C_text("o"));
lf[187]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033eliminated procedure checks"));
lf[188]=C_h_intern(&lf[188],46, C_text("chicken.compiler.support#build-expression-tree"));
lf[189]=C_h_intern(&lf[189],14, C_text("##core#closure"));
lf[190]=C_h_intern(&lf[190],20, C_text("chicken.base#butlast"));
lf[191]=C_h_intern(&lf[191],3, C_text("the"));
lf[192]=C_h_intern(&lf[192],17, C_text("##core#the/result"));
lf[193]=C_h_intern(&lf[193],17, C_text("compiler-typecase"));
lf[194]=C_h_intern(&lf[194],11, C_text("##core#bind"));
lf[195]=C_h_intern(&lf[195],12, C_text("##core#unbox"));
lf[196]=C_h_intern(&lf[196],10, C_text("##core#ref"));
lf[197]=C_h_intern(&lf[197],13, C_text("##core#update"));
lf[198]=C_h_intern(&lf[198],15, C_text("##core#update_i"));
lf[199]=C_h_intern(&lf[199],10, C_text("##core#box"));
lf[200]=C_h_intern(&lf[200],11, C_text("##core#cond"));
lf[201]=C_h_intern(&lf[201],37, C_text("chicken.compiler.support#fold-boolean"));
lf[202]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376B\000\000\005C_and\376\377\016"));
lf[203]=C_h_intern(&lf[203],47, C_text("chicken.compiler.support#inline-lambda-bindings"));
lf[204]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_a_i_list"));
lf[205]=C_h_intern(&lf[205],10, C_text("references"));
lf[206]=C_h_intern(&lf[206],10, C_text("rest-null\077"));
lf[207]=C_h_intern(&lf[207],8, C_text("rest-cdr"));
lf[208]=C_h_intern(&lf[208],17, C_text("derived-rest-vars"));
lf[209]=C_h_intern(&lf[209],17, C_text("##core#rest-null\077"));
lf[210]=C_h_intern(&lf[210],35, C_text("chicken.compiler.support#copy-node!"));
lf[211]=C_h_intern(&lf[211],15, C_text("##core#rest-car"));
lf[212]=C_decode_literal(C_heaptop,C_text("\376B\000\000$C_rest_arg_out_of_bounds_error_value"));
lf[213]=C_h_intern(&lf[213],15, C_text("##core#rest-cdr"));
lf[214]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_cdr"));
lf[215]=C_h_intern(&lf[215],4, C_text("rarg"));
lf[216]=C_h_intern(&lf[216],22, C_text("chicken.base#alist-ref"));
lf[217]=C_h_intern(&lf[217],10, C_text("scheme#eq\077"));
lf[218]=C_h_intern(&lf[218],12, C_text("contractable"));
lf[219]=C_h_intern(&lf[219],16, C_text("inline-transient"));
lf[220]=C_h_intern(&lf[220],1, C_text("f"));
lf[221]=C_h_intern(&lf[221],27, C_text("##sys#decompose-lambda-list"));
lf[222]=C_h_intern(&lf[222],34, C_text("chicken.compiler.support#tree-copy"));
lf[223]=C_h_intern(&lf[223],54, C_text("chicken.compiler.support#replace-rest-op-with-list-ops"));
lf[224]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014C_i_list_ref"));
lf[225]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007C_i_cdr"));
lf[226]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025C_i_greater_or_equalp"));
lf[227]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_length"));
lf[228]=C_h_intern(&lf[228],18, C_text("##core#rest-length"));
lf[229]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012C_i_length"));
lf[230]=C_decode_literal(C_heaptop,C_text("\376B\000\000gUnknown rest op node class while undoing rest op for explicitly consed rest"
" arg. This shouldn\047t happen!"));
lf[231]=C_h_intern(&lf[231],34, C_text("chicken.compiler.support#copy-node"));
lf[232]=C_h_intern(&lf[232],48, C_text("chicken.compiler.support#emit-global-inline-file"));
lf[233]=C_h_intern(&lf[233],18, C_text("chicken.base#print"));
lf[234]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002  "));
lf[235]=C_h_intern(&lf[235],15, C_text("scheme#string<\077"));
lf[236]=C_h_intern(&lf[236],21, C_text("scheme#symbol->string"));
lf[237]=C_h_intern(&lf[237],17, C_text("chicken.sort#sort"));
lf[238]=C_h_intern(&lf[238],1, C_text("i"));
lf[239]=C_decode_literal(C_heaptop,C_text("\376B\000\0001the following procedures can be globally inlined:"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015; END OF FILE"));
lf[241]=C_h_intern(&lf[241],23, C_text("chicken.pretty-print#pp"));
lf[242]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027; GENERATED BY CHICKEN "));
lf[243]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006 FROM "));
lf[244]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[245]=C_h_intern(&lf[245],32, C_text("chicken.platform#chicken-version"));
lf[246]=C_h_intern(&lf[246],26, C_text("scheme#with-output-to-file"));
lf[247]=C_h_intern(&lf[247],11, C_text("local-value"));
lf[248]=C_h_intern(&lf[248],5, C_text("value"));
lf[249]=C_h_intern(&lf[249],9, C_text("inlinable"));
lf[250]=C_h_intern(&lf[250],3, C_text("yes"));
lf[251]=C_h_intern(&lf[251],2, C_text("no"));
lf[252]=C_h_intern(&lf[252],17, C_text("##compiler#inline"));
lf[253]=C_h_intern(&lf[253],11, C_text("hidden-refs"));
lf[254]=C_h_intern(&lf[254],7, C_text("unknown"));
lf[255]=C_h_intern(&lf[255],24, C_text("##compiler#inline-global"));
lf[256]=C_h_intern(&lf[256],42, C_text("chicken.compiler.support#variable-visible\077"));
lf[257]=C_h_intern(&lf[257],36, C_text("chicken.internal#hash-table-for-each"));
lf[258]=C_h_intern(&lf[258],41, C_text("chicken.compiler.support#load-inline-file"));
lf[259]=C_h_intern(&lf[259],10, C_text("##sys#put!"));
lf[260]=C_h_intern(&lf[260],27, C_text("scheme#with-input-from-file"));
lf[261]=C_h_intern(&lf[261],35, C_text("chicken.compiler.support#match-node"));
lf[262]=C_h_intern(&lf[262],1, C_text("a"));
lf[263]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007matched"));
lf[264]=C_h_intern(&lf[264],53, C_text("chicken.compiler.support#expression-has-side-effects\077"));
lf[265]=C_h_intern(&lf[265],49, C_text("chicken.compiler.support#foreign-callback-stub-id"));
lf[266]=C_h_intern(&lf[266],47, C_text("chicken.compiler.support#foreign-callback-stubs"));
lf[267]=C_h_intern(&lf[267],44, C_text("chicken.compiler.support#simple-lambda-node\077"));
lf[268]=C_h_intern(&lf[268],47, C_text("chicken.compiler.support#dump-undefined-globals"));
lf[269]=C_h_intern(&lf[269],12, C_text("scheme#write"));
lf[270]=C_h_intern(&lf[270],6, C_text("global"));
lf[271]=C_h_intern(&lf[271],8, C_text("assigned"));
lf[272]=C_h_intern(&lf[272],24, C_text("chicken.keyword#keyword\077"));
lf[273]=C_h_intern(&lf[273],45, C_text("chicken.compiler.support#dump-defined-globals"));
lf[274]=C_h_intern(&lf[274],41, C_text("chicken.compiler.support#dump-global-refs"));
lf[275]=C_h_intern(&lf[275],30, C_text("##sys#toplevel-definition-hook"));
lf[276]=C_h_intern(&lf[276],22, C_text("chicken.plist#remprop!"));
lf[277]=C_h_intern(&lf[277],21, C_text("##compiler#visibility"));
lf[278]=C_h_intern(&lf[278],41, C_text("chicken.compiler.support#variable-hidden\077"));
lf[279]=C_h_intern(&lf[279],38, C_text("chicken.compiler.support#hide-variable"));
lf[280]=C_decode_literal(C_heaptop,C_text("\376B\000\000 hiding unexported module binding"));
lf[281]=C_h_intern(&lf[281],51, C_text("chicken.compiler.support#make-foreign-callback-stub"));
lf[282]=C_h_intern(&lf[282],46, C_text("chicken.compiler.support#foreign-callback-stub"));
lf[283]=C_h_intern(&lf[283],47, C_text("chicken.compiler.support#foreign-callback-stub\077"));
lf[284]=C_h_intern(&lf[284],24, C_text("foreign-callback-stub-id"));
lf[285]=C_h_intern(&lf[285],51, C_text("chicken.compiler.support#foreign-callback-stub-name"));
lf[286]=C_h_intern(&lf[286],26, C_text("foreign-callback-stub-name"));
lf[287]=C_h_intern(&lf[287],57, C_text("chicken.compiler.support#foreign-callback-stub-qualifiers"));
lf[288]=C_h_intern(&lf[288],32, C_text("foreign-callback-stub-qualifiers"));
lf[289]=C_h_intern(&lf[289],58, C_text("chicken.compiler.support#foreign-callback-stub-return-type"));
lf[290]=C_h_intern(&lf[290],33, C_text("foreign-callback-stub-return-type"));
lf[291]=C_h_intern(&lf[291],61, C_text("chicken.compiler.support#foreign-callback-stub-argument-types"));
lf[292]=C_h_intern(&lf[292],36, C_text("foreign-callback-stub-argument-types"));
lf[293]=C_h_intern(&lf[293],56, C_text("chicken.compiler.support#register-foreign-callback-stub!"));
lf[294]=C_h_intern(&lf[294],26, C_text("##compiler#callback-lambda"));
lf[296]=C_h_intern(&lf[296],50, C_text("chicken.compiler.support#clear-foreign-type-table!"));
lf[297]=C_h_intern(&lf[297],19, C_text("scheme#vector-fill!"));
lf[298]=C_h_intern(&lf[298],18, C_text("scheme#make-vector"));
lf[299]=C_h_intern(&lf[299],47, C_text("chicken.compiler.support#register-foreign-type!"));
lf[300]=C_h_intern(&lf[300],44, C_text("chicken.compiler.support#lookup-foreign-type"));
lf[301]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\007\001integer\376B\000\000\003int\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001unsigned-integer\376B\000\000\014unsigned int"
"\376\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001integer32\376B\000\000\005C_s32\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001unsigned-integer32\376B\000\000\005C_u32\376"
"\003\000\000\002\376\003\000\000\002\376\001\000\000\011\001integer64\376B\000\000\005C_s64\376\003\000\000\002\376\003\000\000\002\376\001\000\000\022\001unsigned-integer64\376B\000\000\005C_u64\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\005\001short\376B\000\000\005short\376\003\000\000\002\376\003\000\000\002\376\001\000\000\016\001unsigned-short\376B\000\000\016unsigned short\376\003"
"\000\000\002\376\003\000\000\002\376\001\000\000\004\001long\376B\000\000\004long\376\003\000\000\002\376\003\000\000\002\376\001\000\000\015\001unsigned-long\376B\000\000\015unsigned long\376\003\000\000\002\376"
"\003\000\000\002\376\001\000\000\007\001ssize_t\376B\000\000\007ssize_t\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001size_t\376B\000\000\006size_t\376\377\016"));
lf[302]=C_h_intern(&lf[302],43, C_text("chicken.compiler.support#foreign-type-check"));
lf[303]=C_h_intern(&lf[303],4, C_text("char"));
lf[304]=C_h_intern(&lf[304],13, C_text("unsigned-char"));
lf[305]=C_h_intern(&lf[305],27, C_text("##sys#foreign-char-argument"));
lf[306]=C_h_intern(&lf[306],3, C_text("int"));
lf[307]=C_h_intern(&lf[307],29, C_text("##sys#foreign-fixnum-argument"));
lf[308]=C_h_intern(&lf[308],5, C_text("float"));
lf[309]=C_h_intern(&lf[309],29, C_text("##sys#foreign-flonum-argument"));
lf[310]=C_h_intern(&lf[310],4, C_text("blob"));
lf[311]=C_h_intern(&lf[311],14, C_text("scheme-pointer"));
lf[312]=C_h_intern(&lf[312],28, C_text("##sys#foreign-block-argument"));
lf[313]=C_h_intern(&lf[313],12, C_text("##core#quote"));
lf[314]=C_h_intern(&lf[314],9, C_text("##core#if"));
lf[315]=C_h_intern(&lf[315],10, C_text("##core#let"));
lf[316]=C_h_intern(&lf[316],22, C_text("nonnull-scheme-pointer"));
lf[317]=C_h_intern(&lf[317],12, C_text("nonnull-blob"));
lf[318]=C_h_intern(&lf[318],14, C_text("pointer-vector"));
lf[319]=C_h_intern(&lf[319],37, C_text("##sys#foreign-struct-wrapper-argument"));
lf[320]=C_h_intern(&lf[320],22, C_text("nonnull-pointer-vector"));
lf[321]=C_h_intern(&lf[321],8, C_text("u8vector"));
lf[322]=C_h_intern(&lf[322],16, C_text("nonnull-u8vector"));
lf[323]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001nonnull-u8vector\376\001\000\000\010\001u8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonnull-u16vector\376"
"\001\000\000\011\001u16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001nonnull-s8vector\376\001\000\000\010\001s8vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonn"
"ull-s16vector\376\001\000\000\011\001s16vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonnull-u32vector\376\001\000\000\011\001u32vector\376\003\000\000"
"\002\376\003\000\000\002\376\001\000\000\021\001nonnull-s32vector\376\001\000\000\011\001s32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonnull-u64vector\376\001\000"
"\000\011\001u64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonnull-s64vector\376\001\000\000\011\001s64vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonn"
"ull-f32vector\376\001\000\000\011\001f32vector\376\003\000\000\002\376\003\000\000\002\376\001\000\000\021\001nonnull-f64vector\376\001\000\000\011\001f64vector\376\377\016"));
lf[324]=C_h_intern(&lf[324],9, C_text("integer32"));
lf[325]=C_h_intern(&lf[325],6, C_text("format"));
lf[326]=C_h_intern(&lf[326],13, C_text("foreign-value"));
lf[327]=C_h_intern(&lf[327],37, C_text("##sys#foreign-ranged-integer-argument"));
lf[328]=C_h_intern(&lf[328],30, C_text("chicken.base#get-output-string"));
lf[329]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014) \052 CHAR_BIT"));
lf[330]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007sizeof("));
lf[331]=C_h_intern(&lf[331],31, C_text("chicken.base#open-output-string"));
lf[332]=C_h_intern(&lf[332],14, C_text("unsigned-short"));
lf[333]=C_h_intern(&lf[333],46, C_text("##sys#foreign-unsigned-ranged-integer-argument"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014) \052 CHAR_BIT"));
lf[335]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007sizeof("));
lf[336]=C_h_intern(&lf[336],9, C_text("c-pointer"));
lf[337]=C_h_intern(&lf[337],30, C_text("##sys#foreign-pointer-argument"));
lf[338]=C_h_intern(&lf[338],17, C_text("nonnull-c-pointer"));
lf[339]=C_h_intern(&lf[339],8, C_text("c-string"));
lf[340]=C_h_intern(&lf[340],19, C_text("##sys#make-c-string"));
lf[341]=C_h_intern(&lf[341],29, C_text("##sys#foreign-string-argument"));
lf[342]=C_h_intern(&lf[342],16, C_text("nonnull-c-string"));
lf[343]=C_h_intern(&lf[343],6, C_text("symbol"));
lf[344]=C_h_intern(&lf[344],3, C_text("ref"));
lf[345]=C_h_intern(&lf[345],8, C_text("instance"));
lf[346]=C_h_intern(&lf[346],12, C_text("instance-ref"));
lf[347]=C_h_intern(&lf[347],4, C_text("this"));
lf[348]=C_h_intern(&lf[348],8, C_text("slot-ref"));
lf[349]=C_h_intern(&lf[349],16, C_text("nonnull-instance"));
lf[350]=C_h_intern(&lf[350],5, C_text("const"));
lf[351]=C_h_intern(&lf[351],4, C_text("enum"));
lf[352]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026sizeof(int) \052 CHAR_BIT"));
lf[353]=C_h_intern(&lf[353],15, C_text("nonnull-pointer"));
lf[354]=C_h_intern(&lf[354],7, C_text("pointer"));
lf[355]=C_h_intern(&lf[355],8, C_text("function"));
lf[356]=C_h_intern(&lf[356],17, C_text("nonnull-c-string\052"));
lf[357]=C_h_intern(&lf[357],26, C_text("nonnull-unsigned-c-string\052"));
lf[358]=C_h_intern(&lf[358],9, C_text("c-string\052"));
lf[359]=C_h_intern(&lf[359],17, C_text("unsigned-c-string"));
lf[360]=C_h_intern(&lf[360],18, C_text("unsigned-c-string\052"));
lf[361]=C_h_intern(&lf[361],13, C_text("c-string-list"));
lf[362]=C_h_intern(&lf[362],14, C_text("c-string-list\052"));
lf[363]=C_h_intern(&lf[363],13, C_text("unsigned-long"));
lf[364]=C_h_intern(&lf[364],16, C_text("unsigned-integer"));
lf[365]=C_h_intern(&lf[365],6, C_text("size_t"));
lf[366]=C_h_intern(&lf[366],18, C_text("unsigned-integer32"));
lf[367]=C_h_intern(&lf[367],18, C_text("unsigned-integer64"));
lf[368]=C_h_intern(&lf[368],9, C_text("integer64"));
lf[369]=C_h_intern(&lf[369],7, C_text("integer"));
lf[370]=C_h_intern(&lf[370],5, C_text("short"));
lf[371]=C_h_intern(&lf[371],4, C_text("long"));
lf[372]=C_h_intern(&lf[372],7, C_text("ssize_t"));
lf[373]=C_h_intern(&lf[373],17, C_text("nonnull-u16vector"));
lf[374]=C_h_intern(&lf[374],16, C_text("nonnull-s8vector"));
lf[375]=C_h_intern(&lf[375],17, C_text("nonnull-s16vector"));
lf[376]=C_h_intern(&lf[376],17, C_text("nonnull-u32vector"));
lf[377]=C_h_intern(&lf[377],17, C_text("nonnull-s32vector"));
lf[378]=C_h_intern(&lf[378],17, C_text("nonnull-u64vector"));
lf[379]=C_h_intern(&lf[379],17, C_text("nonnull-s64vector"));
lf[380]=C_h_intern(&lf[380],17, C_text("nonnull-f32vector"));
lf[381]=C_h_intern(&lf[381],17, C_text("nonnull-f64vector"));
lf[382]=C_h_intern(&lf[382],9, C_text("u16vector"));
lf[383]=C_h_intern(&lf[383],8, C_text("s8vector"));
lf[384]=C_h_intern(&lf[384],9, C_text("s16vector"));
lf[385]=C_h_intern(&lf[385],9, C_text("u32vector"));
lf[386]=C_h_intern(&lf[386],9, C_text("s32vector"));
lf[387]=C_h_intern(&lf[387],9, C_text("u64vector"));
lf[388]=C_h_intern(&lf[388],9, C_text("s64vector"));
lf[389]=C_h_intern(&lf[389],9, C_text("f32vector"));
lf[390]=C_h_intern(&lf[390],9, C_text("f64vector"));
lf[391]=C_h_intern(&lf[391],6, C_text("double"));
lf[392]=C_h_intern(&lf[392],6, C_text("number"));
lf[393]=C_h_intern(&lf[393],12, C_text("unsigned-int"));
lf[394]=C_h_intern(&lf[394],4, C_text("byte"));
lf[395]=C_h_intern(&lf[395],13, C_text("unsigned-byte"));
lf[396]=C_h_intern(&lf[396],5, C_text("int32"));
lf[397]=C_h_intern(&lf[397],14, C_text("unsigned-int32"));
lf[398]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042foreign type `~S\047 refers to itself"));
lf[401]=C_h_intern(&lf[401],52, C_text("chicken.compiler.support#foreign-type-convert-result"));
lf[402]=C_h_intern(&lf[402],54, C_text("chicken.compiler.support#foreign-type-convert-argument"));
lf[403]=C_h_intern(&lf[403],43, C_text("chicken.compiler.support#final-foreign-type"));
lf[404]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042foreign type `~S\047 refers to itself"));
lf[405]=C_h_intern(&lf[405],53, C_text("chicken.compiler.support#estimate-foreign-result-size"));
lf[406]=C_decode_literal(C_heaptop,C_text("\376B\000\0008cannot compute size for unknown foreign type `~S\047 result"));
lf[407]=C_h_intern(&lf[407],4, C_text("bool"));
lf[408]=C_h_intern(&lf[408],4, C_text("void"));
lf[409]=C_h_intern(&lf[409],13, C_text("scheme-object"));
lf[410]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042foreign type `~S\047 refers to itself"));
lf[411]=C_h_intern(&lf[411],62, C_text("chicken.compiler.support#estimate-foreign-result-location-size"));
lf[412]=C_decode_literal(C_heaptop,C_text("\376B\000\0005cannot compute size of location for foreign type `~S\047"));
lf[413]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042foreign type `~S\047 refers to itself"));
lf[414]=C_h_intern(&lf[414],46, C_text("chicken.compiler.support#finish-foreign-result"));
lf[415]=C_h_intern(&lf[415],19, C_text("##sys#peek-c-string"));
lf[416]=C_h_intern(&lf[416],27, C_text("##sys#peek-nonnull-c-string"));
lf[417]=C_h_intern(&lf[417],28, C_text("##sys#peek-and-free-c-string"));
lf[418]=C_h_intern(&lf[418],36, C_text("##sys#peek-and-free-nonnull-c-string"));
lf[419]=C_h_intern(&lf[419],19, C_text("##sys#intern-symbol"));
lf[420]=C_h_intern(&lf[420],24, C_text("##sys#peek-c-string-list"));
lf[421]=C_h_intern(&lf[421],33, C_text("##sys#peek-and-free-c-string-list"));
lf[422]=C_h_intern(&lf[422],19, C_text("##sys#null-pointer\077"));
lf[423]=C_h_intern(&lf[423],3, C_text("not"));
lf[424]=C_h_intern(&lf[424],4, C_text("make"));
lf[425]=C_h_intern(&lf[425],3, C_text("and"));
lf[426]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\010\001c-string\376\003\000\000\002\376\001\000\000\011\001c-string\052\376\003\000\000\002\376\001\000\000\021\001unsigned-c-string\376\003\000\000\002\376\001\000\000\022\001un"
"signed-c-string\052\376\003\000\000\002\376\001\000\000\020\001nonnull-c-string\376\003\000\000\002\376\001\000\000\021\001nonnull-c-string\052\376\003\000\000\002\376\001\000\000"
"\030\001nonnull-unsigned-string\052\376\377\016"));
lf[427]=C_h_intern(&lf[427],27, C_text("chicken.syntax#strip-syntax"));
lf[428]=C_h_intern(&lf[428],52, C_text("chicken.compiler.support#foreign-type->scrutiny-type"));
lf[429]=C_h_intern(&lf[429],9, C_text("undefined"));
lf[430]=C_h_intern(&lf[430],3, C_text("arg"));
lf[431]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\004\001blob\376\377\016"));
lf[432]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\016\001pointer-vector\376\377\016"));
lf[433]=C_h_intern(&lf[433],6, C_text("struct"));
lf[434]=C_h_intern(&lf[434],2, C_text("or"));
lf[435]=C_h_intern(&lf[435],5, C_text("false"));
lf[436]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\010\001u8vector\376\377\016"));
lf[437]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\010\001s8vector\376\377\016"));
lf[438]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001u16vector\376\377\016"));
lf[439]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001s16vector\376\377\016"));
lf[440]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001u32vector\376\377\016"));
lf[441]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001s32vector\376\377\016"));
lf[442]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001u64vector\376\377\016"));
lf[443]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001s64vector\376\377\016"));
lf[444]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001f32vector\376\377\016"));
lf[445]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001struct\376\003\000\000\002\376\001\000\000\011\001f64vector\376\377\016"));
lf[446]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\007\001pointer\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016"));
lf[447]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\007\001pointer\376\377\016"));
lf[448]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\007\001pointer\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016"));
lf[449]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\006\001string\376\377\016"));
lf[450]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\007\001list-of\376\003\000\000\002\376\001\000\000\006\001string\376\377\016"));
lf[451]=C_h_intern(&lf[451],6, C_text("string"));
lf[452]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\007\001pointer\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016"));
lf[453]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\005\001false\376\003\000\000\002\376\001\000\000\007\001pointer\376\377\016"));
lf[454]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\002\001or\376\003\000\000\002\376\001\000\000\007\001pointer\376\003\000\000\002\376\001\000\000\010\001locative\376\377\016"));
lf[455]=C_h_intern(&lf[455],6, C_text("result"));
lf[456]=C_h_intern(&lf[456],44, C_text("chicken.compiler.support#scan-used-variables"));
lf[457]=C_h_intern(&lf[457],44, C_text("chicken.compiler.support#scan-free-variables"));
lf[458]=C_h_intern(&lf[458],52, C_text("chicken.compiler.support#make-block-variable-literal"));
lf[459]=C_h_intern(&lf[459],47, C_text("chicken.compiler.support#block-variable-literal"));
lf[460]=C_h_intern(&lf[460],48, C_text("chicken.compiler.support#block-variable-literal\077"));
lf[461]=C_h_intern(&lf[461],52, C_text("chicken.compiler.support#block-variable-literal-name"));
lf[462]=C_h_intern(&lf[462],27, C_text("block-variable-literal-name"));
lf[463]=C_h_intern(&lf[463],21, C_text("scheme#string->symbol"));
lf[464]=C_h_intern(&lf[464],28, C_text("chicken.time#current-seconds"));
lf[466]=C_h_intern(&lf[466],47, C_text("chicken.compiler.support#clear-real-name-table!"));
lf[467]=C_h_intern(&lf[467],39, C_text("chicken.compiler.support#set-real-name!"));
lf[468]=C_h_intern(&lf[468],38, C_text("chicken.compiler.support#get-real-name"));
lf[469]=C_h_intern(&lf[469],33, C_text("chicken.string#string-intersperse"));
lf[470]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004 in "));
lf[471]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003..."));
lf[472]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004 in "));
lf[473]=C_h_intern(&lf[473],12, C_text("contained-in"));
lf[474]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004 in "));
lf[475]=C_h_intern(&lf[475],35, C_text("chicken.compiler.support#real-name2"));
lf[476]=C_h_intern(&lf[476],48, C_text("chicken.compiler.support#display-real-name-table"));
lf[477]=C_h_intern(&lf[477],44, C_text("chicken.compiler.support#source-info->string"));
lf[478]=C_h_intern(&lf[478],19, C_text("chicken.string#conc"));
lf[479]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001:"));
lf[480]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[481]=C_h_intern(&lf[481],18, C_text("scheme#make-string"));
lf[482]=C_h_intern(&lf[482],10, C_text("scheme#max"));
lf[483]=C_h_intern(&lf[483],42, C_text("chicken.compiler.support#source-info->name"));
lf[484]=C_h_intern(&lf[484],42, C_text("chicken.compiler.support#source-info->line"));
lf[485]=C_h_intern(&lf[485],34, C_text("chicken.compiler.support#call-info"));
lf[486]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[487]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002) "));
lf[488]=C_h_intern(&lf[488],43, C_text("chicken.compiler.support#constant-form-eval"));
lf[489]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032folded constant expression"));
lf[490]=C_decode_literal(C_heaptop,C_text("\376B\000\000Dattempt to constant-fold call to procedure that has multiple results"));
lf[492]=C_h_intern(&lf[492],28, C_text("chicken.condition#condition\077"));
lf[493]=C_h_intern(&lf[493],10, C_text("##sys#list"));
lf[494]=C_decode_literal(C_heaptop,C_text("\376B\000\000.attempt to constant-fold call to non-procedure"));
lf[495]=C_h_intern(&lf[495],49, C_text("chicken.compiler.support#maybe-constant-fold-call"));
lf[496]=C_h_intern(&lf[496],35, C_text("chicken.compiler.support#predicate\077"));
lf[497]=C_h_intern(&lf[497],34, C_text("chicken.compiler.support#foldable\077"));
lf[498]=C_h_intern(&lf[498],20, C_text("##compiler#intrinsic"));
lf[499]=C_h_intern(&lf[499],20, C_text("##sys#number->string"));
lf[500]=C_h_intern(&lf[500],35, C_text("chicken.compiler.support#dump-nodes"));
lf[501]=C_h_intern(&lf[501],21, C_text("##sys#write-char/port"));
lf[502]=C_h_intern(&lf[502],41, C_text("chicken.compiler.support#read/source-info"));
lf[503]=C_h_intern(&lf[503],36, C_text("chicken.syntax#read-with-source-info"));
lf[504]=C_h_intern(&lf[504],20, C_text("##sys#user-read-hook"));
lf[505]=C_h_intern(&lf[505],15, C_text("foreign-declare"));
lf[506]=C_h_intern(&lf[506],7, C_text("declare"));
lf[507]=C_decode_literal(C_heaptop,C_text("\376B\000\000&unexpected end of `#> ... <#\047 sequence"));
lf[508]=C_h_intern(&lf[508],20, C_text("##sys#read-char/port"));
lf[509]=C_h_intern(&lf[509],25, C_text("chicken.platform#feature\077"));
lf[510]=C_h_intern_kw(&lf[510],5, C_text("64bit"));
lf[511]=C_h_intern(&lf[511],38, C_text("chicken.compiler.support#small-bignum\077"));
lf[512]=C_h_intern(&lf[512],6, C_text("hidden"));
lf[513]=C_h_intern(&lf[513],40, C_text("chicken.compiler.support#export-variable"));
lf[514]=C_h_intern(&lf[514],8, C_text("exported"));
lf[515]=C_h_intern(&lf[515],38, C_text("chicken.compiler.support#mark-variable"));
lf[516]=C_h_intern(&lf[516],38, C_text("chicken.compiler.support#variable-mark"));
lf[517]=C_h_intern(&lf[517],35, C_text("chicken.compiler.support#intrinsic\077"));
lf[518]=C_h_intern(&lf[518],19, C_text("##compiler#foldable"));
lf[519]=C_h_intern(&lf[519],20, C_text("##compiler#predicate"));
lf[520]=C_h_intern(&lf[520],49, C_text("chicken.compiler.support#load-identifier-database"));
lf[521]=C_h_intern(&lf[521],9, C_text("##core#db"));
lf[522]=C_h_intern(&lf[522],27, C_text("scheme#call-with-input-file"));
lf[523]=C_h_intern(&lf[523],1, C_text("p"));
lf[524]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004 ..."));
lf[525]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034loading identifier database "));
lf[526]=C_h_intern(&lf[526],22, C_text("chicken.load#find-file"));
lf[527]=C_h_intern(&lf[527],32, C_text("chicken.platform#repository-path"));
lf[528]=C_h_intern(&lf[528],38, C_text("chicken.compiler.support#print-version"));
lf[529]=C_h_intern(&lf[529],19, C_text("chicken.base#print\052"));
lf[530]=C_decode_literal(C_heaptop,C_text("\376B\000\000KCHICKEN\012(c) 2008-2022, The CHICKEN Team\012(c) 2000-2007, Felix L. Winkelmann\012"
));
lf[531]=C_h_intern(&lf[531],36, C_text("chicken.compiler.support#print-usage"));
lf[532]=C_decode_literal(C_heaptop,C_text("\376B\000\031\317Usage: chicken FILENAME [OPTION ...]\012\012  `chicken\047 is the CHICKEN compiler.\012"
"  \012  FILENAME should be a complete source file name with extension, or \042-\042 for\012 "
" standard input. OPTION may be one of the following:\012\012  General options:\012\012    -h"
"elp                        display this text and exit\012    -version              "
"       display compiler version and exit\012    -release                     print "
"release number and exit\012    -verbose                     display information on "
"compilation progress\012\012  File and pathname options:\012\012    -output-file FILENAME   "
"     specifies output-filename, default is \047out.c\047\012    -include-path PATHNAME   "
"    specifies alternative path for included files\012    -to-stdout                "
"   write compiled file to stdout instead of file\012\012  Language options:\012\012    -feat"
"ure SYMBOL              register feature identifier\012    -no-feature SYMBOL      "
"     disable built-in feature identifier\012\012  Syntax related options:\012\012    -case-i"
"nsensitive            don\047t preserve case of read symbols\012    -keyword-style STY"
"LE         allow alternative keyword syntax\012                                  (p"
"refix, suffix or none)\012    -no-parentheses-synonyms     disables list delimiter "
"synonyms\012    -no-symbol-escape            disables support for escaped symbols\012 "
"   -r5rs-syntax                 disables the CHICKEN extensions to\012             "
"                     R5RS syntax\012    -compile-syntax              macros are mad"
"e available at run-time\012    -emit-import-library MODULE  write compile-time modu"
"le information into\012                                  separate file\012    -emit-al"
"l-import-libraries   emit import-libraries for all defined modules\012    -no-compi"
"ler-syntax          disable expansion of compiler-macros\012    -module NAME       "
"          wrap compiled code in a module\012    -module-registration         always"
" generate module registration code\012    -no-module-registration      never genera"
"te module registration code\012                                  (overrides `-modul"
"e-registration\047)\012\012  Translation options:\012\012    -explicit-use                do no"
"t use units \047library\047 and \047eval\047 by\012                                  default\012  "
"  -check-syntax                stop compilation after macro-expansion\012    -analy"
"ze-only                stop compilation after first analysis pass\012\012  Debugging o"
"ptions:\012\012    -no-warnings                 disable warnings\012    -debug-level NUMB"
"ER          set level of available debugging information\012    -no-trace          "
"          disable tracing information\012    -debug-info                  enable de"
"bug-information in compiled code for use\012                                  with "
"an external debugger\012    -profile                     executable emits profiling"
" information \012    -profile-name FILENAME       name of the generated profile inf"
"ormation file\012    -accumulate-profile          executable emits profiling inform"
"ation in\012                                  append mode\012    -no-lambda-info      "
"        omit additional procedure-information\012    -emit-types-file FILENAME    w"
"rite type-declaration information into file\012    -consult-types-file FILENAME loa"
"d additional type database\012\012  Optimization options:\012\012    -optimize-level NUMBER "
"      enable certain sets of optimization options\012    -optimize-leaf-routines   "
"   enable leaf routine optimization\012    -no-usual-integrations       standard pr"
"ocedures may be redefined\012    -unsafe                      disable all safety ch"
"ecks\012    -local                       assume globals are only modified in curren"
"t\012                                  file\012    -block                       enable"
" block-compilation\012    -disable-interrupts          disable interrupts in compil"
"ed code\012    -fixnum-arithmetic           assume all numbers are fixnums\012    -dis"
"able-stack-overflow-checks  disables detection of stack-overflows\012    -inline   "
"                   enable inlining\012    -inline-limit LIMIT          set inlining"
" threshold\012    -inline-global               enable cross-module inlining\012    -sp"
"ecialize                  perform type-based specialization of primitive calls\012 "
"   -emit-inline-file FILENAME   generate file with globally inlinable\012          "
"                        procedures (implies -inline -local)\012    -consult-inline-"
"file FILENAME  explicitly load inline file\012    -no-argc-checks              disa"
"ble argument count checks\012    -no-bound-checks             disable bound variabl"
"e checks\012    -no-procedure-checks         disable procedure call checks\012    -no-"
"procedure-checks-for-usual-bindings\012                                   disable p"
"rocedure call checks only for usual\012                                   bindings\012"
"    -no-procedure-checks-for-toplevel-bindings\012                                 "
"  disable procedure call checks for toplevel\012                                   "
"bindings\012    -strict-types                assume variable do not change their ty"
"pe\012    -clustering                  combine groups of local procedures into disp"
"atch\012                                   loop\012    -lfa2                        pe"
"rform additional lightweight flow-analysis pass\012    -unroll-limit LIMIT         "
" specifies inlining limit for self-recursive calls\012\012  Configuration options:\012\012  "
"  -unit NAME                   compile file as a library unit\012    -uses NAME    "
"               declare library unit as used.\012    -heap-size NUMBER            sp"
"ecifies heap-size of compiled executable\012    -nursery NUMBER  -stack-size NUMBER"
"\012                                 specifies nursery size of compiled executable\012"
"    -extend FILENAME             load file before compilation commences\012    -pre"
"lude EXPRESSION          add expression to front of source file\012    -postlude EX"
"PRESSION         add expression to end of source file\012    -prologue FILENAME    "
"       include file before main source file\012    -epilogue FILENAME           inc"
"lude file after main source file\012    -dynamic                     compile as dyn"
"amically loadable code\012    -require-extension NAME      require and import exten"
"sion NAME\012\012  Obscure options:\012\012    -debug MODES                 display debuggin"
"g output for the given modes\012    -raw                         do not generate im"
"plicit init- and exit code                           \012    -emit-external-prototy"
"pes-first\012                                 emit prototypes for callbacks before "
"foreign\012                                  declarations\012    -regenerate-import-li"
"braries emit import libraries even when unchanged\012    -ignore-repository        "
"   do not refer to repository for extensions\012    -setup-mode                  pr"
"efer the current directory when locating extensions\012"));
lf[533]=C_h_intern(&lf[533],44, C_text("chicken.compiler.support#print-debug-options"));
lf[534]=C_decode_literal(C_heaptop,C_text("\376B\000\006\344\012Available debugging options:\012\012     a          show node-matching during si"
"mplification\012     b          show breakdown of time needed for each compiler pas"
"s\012     c          print every expression before macro-expansion\012     d          "
"lists all assigned global variables\012     e          show information about speci"
"alizations\012     h          you already figured that out\012     i          show inf"
"ormation about inlining\012     m          show GC statistics during compilation\012  "
"   n          print the line-number database \012     o          show performed opt"
"imizations\012     p          display information about what the compiler is curren"
"tly doing\012     r          show invocation parameters\012     s          show progra"
"m-size information and other statistics\012     t          show time needed for com"
"pilation\012     u          lists all unassigned global variable references\012     x "
"         display information about experimental features\012     D          when pr"
"inting nodes, use node-tree output\012     I          show inferred type informatio"
"n for unexported globals\012     N          show the real-name mapping table\012     P"
"          show expressions after specialization\012     S          show application"
"s of compiler syntax\012     T          show expressions after converting to node t"
"ree\012     1          show source expressions\012     2          show canonicalized e"
"xpressions\012     3          show expressions converted into CPS\012     4          s"
"how database after each analysis pass\012     5          show expressions after eac"
"h optimization pass\012     6          show expressions after each inlining pass\012  "
"   7          show expressions after complete optimization\012     8          show "
"database after final analysis\012     9          show expressions after closure con"
"version\012\012"));
lf[535]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007#<node "));
lf[536]=C_h_intern(&lf[536],32, C_text("chicken.base#set-record-printer!"));
lf[537]=C_h_intern(&lf[537],45, C_text("chicken.condition#condition-property-accessor"));
lf[538]=C_h_intern(&lf[538],3, C_text("exn"));
lf[539]=C_h_intern(&lf[539],7, C_text("message"));
lf[540]=C_h_intern(&lf[540],37, C_text("chicken.condition#condition-predicate"));
C_register_lf2(lf,541,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5275,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[766] = {
{C_text("f19574:support_2escm"),(void*)f19574},
{C_text("f_10002:support_2escm"),(void*)f_10002},
{C_text("f_10027:support_2escm"),(void*)f_10027},
{C_text("f_10057:support_2escm"),(void*)f_10057},
{C_text("f_10059:support_2escm"),(void*)f_10059},
{C_text("f_10084:support_2escm"),(void*)f_10084},
{C_text("f_10115:support_2escm"),(void*)f_10115},
{C_text("f_10127:support_2escm"),(void*)f_10127},
{C_text("f_10131:support_2escm"),(void*)f_10131},
{C_text("f_10154:support_2escm"),(void*)f_10154},
{C_text("f_10165:support_2escm"),(void*)f_10165},
{C_text("f_10172:support_2escm"),(void*)f_10172},
{C_text("f_10183:support_2escm"),(void*)f_10183},
{C_text("f_10185:support_2escm"),(void*)f_10185},
{C_text("f_10210:support_2escm"),(void*)f_10210},
{C_text("f_10240:support_2escm"),(void*)f_10240},
{C_text("f_10242:support_2escm"),(void*)f_10242},
{C_text("f_10267:support_2escm"),(void*)f_10267},
{C_text("f_10281:support_2escm"),(void*)f_10281},
{C_text("f_10291:support_2escm"),(void*)f_10291},
{C_text("f_10293:support_2escm"),(void*)f_10293},
{C_text("f_10318:support_2escm"),(void*)f_10318},
{C_text("f_10391:support_2escm"),(void*)f_10391},
{C_text("f_10397:support_2escm"),(void*)f_10397},
{C_text("f_10423:support_2escm"),(void*)f_10423},
{C_text("f_10427:support_2escm"),(void*)f_10427},
{C_text("f_10443:support_2escm"),(void*)f_10443},
{C_text("f_10449:support_2escm"),(void*)f_10449},
{C_text("f_10455:support_2escm"),(void*)f_10455},
{C_text("f_10461:support_2escm"),(void*)f_10461},
{C_text("f_10465:support_2escm"),(void*)f_10465},
{C_text("f_10468:support_2escm"),(void*)f_10468},
{C_text("f_10482:support_2escm"),(void*)f_10482},
{C_text("f_10485:support_2escm"),(void*)f_10485},
{C_text("f_10488:support_2escm"),(void*)f_10488},
{C_text("f_10495:support_2escm"),(void*)f_10495},
{C_text("f_10497:support_2escm"),(void*)f_10497},
{C_text("f_10512:support_2escm"),(void*)f_10512},
{C_text("f_10545:support_2escm"),(void*)f_10545},
{C_text("f_10573:support_2escm"),(void*)f_10573},
{C_text("f_10577:support_2escm"),(void*)f_10577},
{C_text("f_10601:support_2escm"),(void*)f_10601},
{C_text("f_10633:support_2escm"),(void*)f_10633},
{C_text("f_10642:support_2escm"),(void*)f_10642},
{C_text("f_10646:support_2escm"),(void*)f_10646},
{C_text("f_10652:support_2escm"),(void*)f_10652},
{C_text("f_10658:support_2escm"),(void*)f_10658},
{C_text("f_10661:support_2escm"),(void*)f_10661},
{C_text("f_10666:support_2escm"),(void*)f_10666},
{C_text("f_10676:support_2escm"),(void*)f_10676},
{C_text("f_10691:support_2escm"),(void*)f_10691},
{C_text("f_10693:support_2escm"),(void*)f_10693},
{C_text("f_10718:support_2escm"),(void*)f_10718},
{C_text("f_10739:support_2escm"),(void*)f_10739},
{C_text("f_10764:support_2escm"),(void*)f_10764},
{C_text("f_10786:support_2escm"),(void*)f_10786},
{C_text("f_10794:support_2escm"),(void*)f_10794},
{C_text("f_10845:support_2escm"),(void*)f_10845},
{C_text("f_10852:support_2escm"),(void*)f_10852},
{C_text("f_10855:support_2escm"),(void*)f_10855},
{C_text("f_10884:support_2escm"),(void*)f_10884},
{C_text("f_10892:support_2escm"),(void*)f_10892},
{C_text("f_10908:support_2escm"),(void*)f_10908},
{C_text("f_10911:support_2escm"),(void*)f_10911},
{C_text("f_10917:support_2escm"),(void*)f_10917},
{C_text("f_10937:support_2escm"),(void*)f_10937},
{C_text("f_10960:support_2escm"),(void*)f_10960},
{C_text("f_10965:support_2escm"),(void*)f_10965},
{C_text("f_10969:support_2escm"),(void*)f_10969},
{C_text("f_10972:support_2escm"),(void*)f_10972},
{C_text("f_10978:support_2escm"),(void*)f_10978},
{C_text("f_10981:support_2escm"),(void*)f_10981},
{C_text("f_10998:support_2escm"),(void*)f_10998},
{C_text("f_11008:support_2escm"),(void*)f_11008},
{C_text("f_11010:support_2escm"),(void*)f_11010},
{C_text("f_11035:support_2escm"),(void*)f_11035},
{C_text("f_11046:support_2escm"),(void*)f_11046},
{C_text("f_11054:support_2escm"),(void*)f_11054},
{C_text("f_11062:support_2escm"),(void*)f_11062},
{C_text("f_11075:support_2escm"),(void*)f_11075},
{C_text("f_11077:support_2escm"),(void*)f_11077},
{C_text("f_11125:support_2escm"),(void*)f_11125},
{C_text("f_11150:support_2escm"),(void*)f_11150},
{C_text("f_11169:support_2escm"),(void*)f_11169},
{C_text("f_11174:support_2escm"),(void*)f_11174},
{C_text("f_11184:support_2escm"),(void*)f_11184},
{C_text("f_11186:support_2escm"),(void*)f_11186},
{C_text("f_11211:support_2escm"),(void*)f_11211},
{C_text("f_11233:support_2escm"),(void*)f_11233},
{C_text("f_11284:support_2escm"),(void*)f_11284},
{C_text("f_11328:support_2escm"),(void*)f_11328},
{C_text("f_11375:support_2escm"),(void*)f_11375},
{C_text("f_11403:support_2escm"),(void*)f_11403},
{C_text("f_11407:support_2escm"),(void*)f_11407},
{C_text("f_11411:support_2escm"),(void*)f_11411},
{C_text("f_11430:support_2escm"),(void*)f_11430},
{C_text("f_11442:support_2escm"),(void*)f_11442},
{C_text("f_11444:support_2escm"),(void*)f_11444},
{C_text("f_11486:support_2escm"),(void*)f_11486},
{C_text("f_11496:support_2escm"),(void*)f_11496},
{C_text("f_11518:support_2escm"),(void*)f_11518},
{C_text("f_11545:support_2escm"),(void*)f_11545},
{C_text("f_11565:support_2escm"),(void*)f_11565},
{C_text("f_11618:support_2escm"),(void*)f_11618},
{C_text("f_11665:support_2escm"),(void*)f_11665},
{C_text("f_11682:support_2escm"),(void*)f_11682},
{C_text("f_11688:support_2escm"),(void*)f_11688},
{C_text("f_11702:support_2escm"),(void*)f_11702},
{C_text("f_11706:support_2escm"),(void*)f_11706},
{C_text("f_11712:support_2escm"),(void*)f_11712},
{C_text("f_11750:support_2escm"),(void*)f_11750},
{C_text("f_11754:support_2escm"),(void*)f_11754},
{C_text("f_11757:support_2escm"),(void*)f_11757},
{C_text("f_11760:support_2escm"),(void*)f_11760},
{C_text("f_11795:support_2escm"),(void*)f_11795},
{C_text("f_11839:support_2escm"),(void*)f_11839},
{C_text("f_11841:support_2escm"),(void*)f_11841},
{C_text("f_11866:support_2escm"),(void*)f_11866},
{C_text("f_11881:support_2escm"),(void*)f_11881},
{C_text("f_11910:support_2escm"),(void*)f_11910},
{C_text("f_11912:support_2escm"),(void*)f_11912},
{C_text("f_11937:support_2escm"),(void*)f_11937},
{C_text("f_11946:support_2escm"),(void*)f_11946},
{C_text("f_11949:support_2escm"),(void*)f_11949},
{C_text("f_11955:support_2escm"),(void*)f_11955},
{C_text("f_12003:support_2escm"),(void*)f_12003},
{C_text("f_12006:support_2escm"),(void*)f_12006},
{C_text("f_12012:support_2escm"),(void*)f_12012},
{C_text("f_12020:support_2escm"),(void*)f_12020},
{C_text("f_12028:support_2escm"),(void*)f_12028},
{C_text("f_12038:support_2escm"),(void*)f_12038},
{C_text("f_12057:support_2escm"),(void*)f_12057},
{C_text("f_12061:support_2escm"),(void*)f_12061},
{C_text("f_12066:support_2escm"),(void*)f_12066},
{C_text("f_12072:support_2escm"),(void*)f_12072},
{C_text("f_12075:support_2escm"),(void*)f_12075},
{C_text("f_12080:support_2escm"),(void*)f_12080},
{C_text("f_12090:support_2escm"),(void*)f_12090},
{C_text("f_12105:support_2escm"),(void*)f_12105},
{C_text("f_12107:support_2escm"),(void*)f_12107},
{C_text("f_12114:support_2escm"),(void*)f_12114},
{C_text("f_12135:support_2escm"),(void*)f_12135},
{C_text("f_12169:support_2escm"),(void*)f_12169},
{C_text("f_12172:support_2escm"),(void*)f_12172},
{C_text("f_12197:support_2escm"),(void*)f_12197},
{C_text("f_12203:support_2escm"),(void*)f_12203},
{C_text("f_12229:support_2escm"),(void*)f_12229},
{C_text("f_12262:support_2escm"),(void*)f_12262},
{C_text("f_12264:support_2escm"),(void*)f_12264},
{C_text("f_12270:support_2escm"),(void*)f_12270},
{C_text("f_12276:support_2escm"),(void*)f_12276},
{C_text("f_12280:support_2escm"),(void*)f_12280},
{C_text("f_12303:support_2escm"),(void*)f_12303},
{C_text("f_12314:support_2escm"),(void*)f_12314},
{C_text("f_12320:support_2escm"),(void*)f_12320},
{C_text("f_12323:support_2escm"),(void*)f_12323},
{C_text("f_12331:support_2escm"),(void*)f_12331},
{C_text("f_12357:support_2escm"),(void*)f_12357},
{C_text("f_12379:support_2escm"),(void*)f_12379},
{C_text("f_12404:support_2escm"),(void*)f_12404},
{C_text("f_12426:support_2escm"),(void*)f_12426},
{C_text("f_12444:support_2escm"),(void*)f_12444},
{C_text("f_12475:support_2escm"),(void*)f_12475},
{C_text("f_12527:support_2escm"),(void*)f_12527},
{C_text("f_12533:support_2escm"),(void*)f_12533},
{C_text("f_12553:support_2escm"),(void*)f_12553},
{C_text("f_12559:support_2escm"),(void*)f_12559},
{C_text("f_12585:support_2escm"),(void*)f_12585},
{C_text("f_12599:support_2escm"),(void*)f_12599},
{C_text("f_12607:support_2escm"),(void*)f_12607},
{C_text("f_12662:support_2escm"),(void*)f_12662},
{C_text("f_12691:support_2escm"),(void*)f_12691},
{C_text("f_12788:support_2escm"),(void*)f_12788},
{C_text("f_12794:support_2escm"),(void*)f_12794},
{C_text("f_12801:support_2escm"),(void*)f_12801},
{C_text("f_12804:support_2escm"),(void*)f_12804},
{C_text("f_12827:support_2escm"),(void*)f_12827},
{C_text("f_12829:support_2escm"),(void*)f_12829},
{C_text("f_12835:support_2escm"),(void*)f_12835},
{C_text("f_12842:support_2escm"),(void*)f_12842},
{C_text("f_12845:support_2escm"),(void*)f_12845},
{C_text("f_12864:support_2escm"),(void*)f_12864},
{C_text("f_12866:support_2escm"),(void*)f_12866},
{C_text("f_12872:support_2escm"),(void*)f_12872},
{C_text("f_12885:support_2escm"),(void*)f_12885},
{C_text("f_12913:support_2escm"),(void*)f_12913},
{C_text("f_12915:support_2escm"),(void*)f_12915},
{C_text("f_12936:support_2escm"),(void*)f_12936},
{C_text("f_12943:support_2escm"),(void*)f_12943},
{C_text("f_12949:support_2escm"),(void*)f_12949},
{C_text("f_12955:support_2escm"),(void*)f_12955},
{C_text("f_12964:support_2escm"),(void*)f_12964},
{C_text("f_12973:support_2escm"),(void*)f_12973},
{C_text("f_12982:support_2escm"),(void*)f_12982},
{C_text("f_12991:support_2escm"),(void*)f_12991},
{C_text("f_13000:support_2escm"),(void*)f_13000},
{C_text("f_13026:support_2escm"),(void*)f_13026},
{C_text("f_13029:support_2escm"),(void*)f_13029},
{C_text("f_13040:support_2escm"),(void*)f_13040},
{C_text("f_13042:support_2escm"),(void*)f_13042},
{C_text("f_13096:support_2escm"),(void*)f_13096},
{C_text("f_13102:support_2escm"),(void*)f_13102},
{C_text("f_13108:support_2escm"),(void*)f_13108},
{C_text("f_13114:support_2escm"),(void*)f_13114},
{C_text("f_13139:support_2escm"),(void*)f_13139},
{C_text("f_13154:support_2escm"),(void*)f_13154},
{C_text("f_13172:support_2escm"),(void*)f_13172},
{C_text("f_13222:support_2escm"),(void*)f_13222},
{C_text("f_13237:support_2escm"),(void*)f_13237},
{C_text("f_13277:support_2escm"),(void*)f_13277},
{C_text("f_13280:support_2escm"),(void*)f_13280},
{C_text("f_13295:support_2escm"),(void*)f_13295},
{C_text("f_13319:support_2escm"),(void*)f_13319},
{C_text("f_13345:support_2escm"),(void*)f_13345},
{C_text("f_13351:support_2escm"),(void*)f_13351},
{C_text("f_13357:support_2escm"),(void*)f_13357},
{C_text("f_13360:support_2escm"),(void*)f_13360},
{C_text("f_13363:support_2escm"),(void*)f_13363},
{C_text("f_13366:support_2escm"),(void*)f_13366},
{C_text("f_13388:support_2escm"),(void*)f_13388},
{C_text("f_13394:support_2escm"),(void*)f_13394},
{C_text("f_13400:support_2escm"),(void*)f_13400},
{C_text("f_13403:support_2escm"),(void*)f_13403},
{C_text("f_13406:support_2escm"),(void*)f_13406},
{C_text("f_13409:support_2escm"),(void*)f_13409},
{C_text("f_13432:support_2escm"),(void*)f_13432},
{C_text("f_13435:support_2escm"),(void*)f_13435},
{C_text("f_13476:support_2escm"),(void*)f_13476},
{C_text("f_13479:support_2escm"),(void*)f_13479},
{C_text("f_13494:support_2escm"),(void*)f_13494},
{C_text("f_13521:support_2escm"),(void*)f_13521},
{C_text("f_13564:support_2escm"),(void*)f_13564},
{C_text("f_13568:support_2escm"),(void*)f_13568},
{C_text("f_13595:support_2escm"),(void*)f_13595},
{C_text("f_13598:support_2escm"),(void*)f_13598},
{C_text("f_13633:support_2escm"),(void*)f_13633},
{C_text("f_13669:support_2escm"),(void*)f_13669},
{C_text("f_14172:support_2escm"),(void*)f_14172},
{C_text("f_14178:support_2escm"),(void*)f_14178},
{C_text("f_14188:support_2escm"),(void*)f_14188},
{C_text("f_14199:support_2escm"),(void*)f_14199},
{C_text("f_14209:support_2escm"),(void*)f_14209},
{C_text("f_14220:support_2escm"),(void*)f_14220},
{C_text("f_14224:support_2escm"),(void*)f_14224},
{C_text("f_14235:support_2escm"),(void*)f_14235},
{C_text("f_14239:support_2escm"),(void*)f_14239},
{C_text("f_14250:support_2escm"),(void*)f_14250},
{C_text("f_14256:support_2escm"),(void*)f_14256},
{C_text("f_14260:support_2escm"),(void*)f_14260},
{C_text("f_14264:support_2escm"),(void*)f_14264},
{C_text("f_14283:support_2escm"),(void*)f_14283},
{C_text("f_14289:support_2escm"),(void*)f_14289},
{C_text("f_14292:support_2escm"),(void*)f_14292},
{C_text("f_14301:support_2escm"),(void*)f_14301},
{C_text("f_14311:support_2escm"),(void*)f_14311},
{C_text("f_14320:support_2escm"),(void*)f_14320},
{C_text("f_14332:support_2escm"),(void*)f_14332},
{C_text("f_14344:support_2escm"),(void*)f_14344},
{C_text("f_14356:support_2escm"),(void*)f_14356},
{C_text("f_14362:support_2escm"),(void*)f_14362},
{C_text("f_14366:support_2escm"),(void*)f_14366},
{C_text("f_14393:support_2escm"),(void*)f_14393},
{C_text("f_14758:support_2escm"),(void*)f_14758},
{C_text("f_14764:support_2escm"),(void*)f_14764},
{C_text("f_14776:support_2escm"),(void*)f_14776},
{C_text("f_14786:support_2escm"),(void*)f_14786},
{C_text("f_14798:support_2escm"),(void*)f_14798},
{C_text("f_14804:support_2escm"),(void*)f_14804},
{C_text("f_14808:support_2escm"),(void*)f_14808},
{C_text("f_14835:support_2escm"),(void*)f_14835},
{C_text("f_15208:support_2escm"),(void*)f_15208},
{C_text("f_15214:support_2escm"),(void*)f_15214},
{C_text("f_15218:support_2escm"),(void*)f_15218},
{C_text("f_15334:support_2escm"),(void*)f_15334},
{C_text("f_15362:support_2escm"),(void*)f_15362},
{C_text("f_15482:support_2escm"),(void*)f_15482},
{C_text("f_15489:support_2escm"),(void*)f_15489},
{C_text("f_15492:support_2escm"),(void*)f_15492},
{C_text("f_15495:support_2escm"),(void*)f_15495},
{C_text("f_15519:support_2escm"),(void*)f_15519},
{C_text("f_15594:support_2escm"),(void*)f_15594},
{C_text("f_15681:support_2escm"),(void*)f_15681},
{C_text("f_15714:support_2escm"),(void*)f_15714},
{C_text("f_15732:support_2escm"),(void*)f_15732},
{C_text("f_15754:support_2escm"),(void*)f_15754},
{C_text("f_16136:support_2escm"),(void*)f_16136},
{C_text("f_16140:support_2escm"),(void*)f_16140},
{C_text("f_16142:support_2escm"),(void*)f_16142},
{C_text("f_16174:support_2escm"),(void*)f_16174},
{C_text("f_16182:support_2escm"),(void*)f_16182},
{C_text("f_16192:support_2escm"),(void*)f_16192},
{C_text("f_16238:support_2escm"),(void*)f_16238},
{C_text("f_16246:support_2escm"),(void*)f_16246},
{C_text("f_16256:support_2escm"),(void*)f_16256},
{C_text("f_16291:support_2escm"),(void*)f_16291},
{C_text("f_16294:support_2escm"),(void*)f_16294},
{C_text("f_16328:support_2escm"),(void*)f_16328},
{C_text("f_16347:support_2escm"),(void*)f_16347},
{C_text("f_16353:support_2escm"),(void*)f_16353},
{C_text("f_16357:support_2escm"),(void*)f_16357},
{C_text("f_16383:support_2escm"),(void*)f_16383},
{C_text("f_16392:support_2escm"),(void*)f_16392},
{C_text("f_16403:support_2escm"),(void*)f_16403},
{C_text("f_16422:support_2escm"),(void*)f_16422},
{C_text("f_16434:support_2escm"),(void*)f_16434},
{C_text("f_16478:support_2escm"),(void*)f_16478},
{C_text("f_16480:support_2escm"),(void*)f_16480},
{C_text("f_16492:support_2escm"),(void*)f_16492},
{C_text("f_16502:support_2escm"),(void*)f_16502},
{C_text("f_16516:support_2escm"),(void*)f_16516},
{C_text("f_16522:support_2escm"),(void*)f_16522},
{C_text("f_16528:support_2escm"),(void*)f_16528},
{C_text("f_16534:support_2escm"),(void*)f_16534},
{C_text("f_16543:support_2escm"),(void*)f_16543},
{C_text("f_16551:support_2escm"),(void*)f_16551},
{C_text("f_16557:support_2escm"),(void*)f_16557},
{C_text("f_16560:support_2escm"),(void*)f_16560},
{C_text("f_16563:support_2escm"),(void*)f_16563},
{C_text("f_16566:support_2escm"),(void*)f_16566},
{C_text("f_16569:support_2escm"),(void*)f_16569},
{C_text("f_16574:support_2escm"),(void*)f_16574},
{C_text("f_16578:support_2escm"),(void*)f_16578},
{C_text("f_16590:support_2escm"),(void*)f_16590},
{C_text("f_16595:support_2escm"),(void*)f_16595},
{C_text("f_16597:support_2escm"),(void*)f_16597},
{C_text("f_16603:support_2escm"),(void*)f_16603},
{C_text("f_16610:support_2escm"),(void*)f_16610},
{C_text("f_16613:support_2escm"),(void*)f_16613},
{C_text("f_16617:support_2escm"),(void*)f_16617},
{C_text("f_16623:support_2escm"),(void*)f_16623},
{C_text("f_16629:support_2escm"),(void*)f_16629},
{C_text("f_16656:support_2escm"),(void*)f_16656},
{C_text("f_16658:support_2escm"),(void*)f_16658},
{C_text("f_16672:support_2escm"),(void*)f_16672},
{C_text("f_16682:support_2escm"),(void*)f_16682},
{C_text("f_16695:support_2escm"),(void*)f_16695},
{C_text("f_16710:support_2escm"),(void*)f_16710},
{C_text("f_16714:support_2escm"),(void*)f_16714},
{C_text("f_16721:support_2escm"),(void*)f_16721},
{C_text("f_16725:support_2escm"),(void*)f_16725},
{C_text("f_16730:support_2escm"),(void*)f_16730},
{C_text("f_16734:support_2escm"),(void*)f_16734},
{C_text("f_16742:support_2escm"),(void*)f_16742},
{C_text("f_16748:support_2escm"),(void*)f_16748},
{C_text("f_16755:support_2escm"),(void*)f_16755},
{C_text("f_16758:support_2escm"),(void*)f_16758},
{C_text("f_16761:support_2escm"),(void*)f_16761},
{C_text("f_16766:support_2escm"),(void*)f_16766},
{C_text("f_16786:support_2escm"),(void*)f_16786},
{C_text("f_16790:support_2escm"),(void*)f_16790},
{C_text("f_16801:support_2escm"),(void*)f_16801},
{C_text("f_16816:support_2escm"),(void*)f_16816},
{C_text("f_16828:support_2escm"),(void*)f_16828},
{C_text("f_16835:support_2escm"),(void*)f_16835},
{C_text("f_16865:support_2escm"),(void*)f_16865},
{C_text("f_16889:support_2escm"),(void*)f_16889},
{C_text("f_16904:support_2escm"),(void*)f_16904},
{C_text("f_16907:support_2escm"),(void*)f_16907},
{C_text("f_16913:support_2escm"),(void*)f_16913},
{C_text("f_16922:support_2escm"),(void*)f_16922},
{C_text("f_16925:support_2escm"),(void*)f_16925},
{C_text("f_16964:support_2escm"),(void*)f_16964},
{C_text("f_16970:support_2escm"),(void*)f_16970},
{C_text("f_16976:support_2escm"),(void*)f_16976},
{C_text("f_16979:support_2escm"),(void*)f_16979},
{C_text("f_16985:support_2escm"),(void*)f_16985},
{C_text("f_16991:support_2escm"),(void*)f_16991},
{C_text("f_16997:support_2escm"),(void*)f_16997},
{C_text("f_17003:support_2escm"),(void*)f_17003},
{C_text("f_17025:support_2escm"),(void*)f_17025},
{C_text("f_17027:support_2escm"),(void*)f_17027},
{C_text("f_17061:support_2escm"),(void*)f_17061},
{C_text("f_17095:support_2escm"),(void*)f_17095},
{C_text("f_17098:support_2escm"),(void*)f_17098},
{C_text("f_17126:support_2escm"),(void*)f_17126},
{C_text("f_17133:support_2escm"),(void*)f_17133},
{C_text("f_17148:support_2escm"),(void*)f_17148},
{C_text("f_17154:support_2escm"),(void*)f_17154},
{C_text("f_17157:support_2escm"),(void*)f_17157},
{C_text("f_17194:support_2escm"),(void*)f_17194},
{C_text("f_17209:support_2escm"),(void*)f_17209},
{C_text("f_17219:support_2escm"),(void*)f_17219},
{C_text("f_17222:support_2escm"),(void*)f_17222},
{C_text("f_17234:support_2escm"),(void*)f_17234},
{C_text("f_17240:support_2escm"),(void*)f_17240},
{C_text("f_17246:support_2escm"),(void*)f_17246},
{C_text("f_17249:support_2escm"),(void*)f_17249},
{C_text("f_17251:support_2escm"),(void*)f_17251},
{C_text("f_17258:support_2escm"),(void*)f_17258},
{C_text("f_17264:support_2escm"),(void*)f_17264},
{C_text("f_17275:support_2escm"),(void*)f_17275},
{C_text("f_17323:support_2escm"),(void*)f_17323},
{C_text("f_17325:support_2escm"),(void*)f_17325},
{C_text("f_17331:support_2escm"),(void*)f_17331},
{C_text("f_17335:support_2escm"),(void*)f_17335},
{C_text("f_17340:support_2escm"),(void*)f_17340},
{C_text("f_17368:support_2escm"),(void*)f_17368},
{C_text("f_17376:support_2escm"),(void*)f_17376},
{C_text("f_17379:support_2escm"),(void*)f_17379},
{C_text("f_17382:support_2escm"),(void*)f_17382},
{C_text("f_17385:support_2escm"),(void*)f_17385},
{C_text("f_17388:support_2escm"),(void*)f_17388},
{C_text("f_17391:support_2escm"),(void*)f_17391},
{C_text("f_17392:support_2escm"),(void*)f_17392},
{C_text("f_17402:support_2escm"),(void*)f_17402},
{C_text("f_17408:support_2escm"),(void*)f_17408},
{C_text("f_17420:support_2escm"),(void*)f_17420},
{C_text("f_17423:support_2escm"),(void*)f_17423},
{C_text("f_17426:support_2escm"),(void*)f_17426},
{C_text("f_17431:support_2escm"),(void*)f_17431},
{C_text("f_17444:support_2escm"),(void*)f_17444},
{C_text("f_17447:support_2escm"),(void*)f_17447},
{C_text("f_17464:support_2escm"),(void*)f_17464},
{C_text("f_17474:support_2escm"),(void*)f_17474},
{C_text("f_17487:support_2escm"),(void*)f_17487},
{C_text("f_17493:support_2escm"),(void*)f_17493},
{C_text("f_17503:support_2escm"),(void*)f_17503},
{C_text("f_17506:support_2escm"),(void*)f_17506},
{C_text("f_17522:support_2escm"),(void*)f_17522},
{C_text("f_17527:support_2escm"),(void*)f_17527},
{C_text("f_17531:support_2escm"),(void*)f_17531},
{C_text("f_17548:support_2escm"),(void*)f_17548},
{C_text("f_17559:support_2escm"),(void*)f_17559},
{C_text("f_17571:support_2escm"),(void*)f_17571},
{C_text("f_17574:support_2escm"),(void*)f_17574},
{C_text("f_17582:support_2escm"),(void*)f_17582},
{C_text("f_17587:support_2escm"),(void*)f_17587},
{C_text("f_17600:support_2escm"),(void*)f_17600},
{C_text("f_17611:support_2escm"),(void*)f_17611},
{C_text("f_17633:support_2escm"),(void*)f_17633},
{C_text("f_17635:support_2escm"),(void*)f_17635},
{C_text("f_17655:support_2escm"),(void*)f_17655},
{C_text("f_17675:support_2escm"),(void*)f_17675},
{C_text("f_17683:support_2escm"),(void*)f_17683},
{C_text("f_17692:support_2escm"),(void*)f_17692},
{C_text("f_17697:support_2escm"),(void*)f_17697},
{C_text("f_17701:support_2escm"),(void*)f_17701},
{C_text("f_17722:support_2escm"),(void*)f_17722},
{C_text("f_17737:support_2escm"),(void*)f_17737},
{C_text("f_17743:support_2escm"),(void*)f_17743},
{C_text("f_17754:support_2escm"),(void*)f_17754},
{C_text("f_17765:support_2escm"),(void*)f_17765},
{C_text("f_17776:support_2escm"),(void*)f_17776},
{C_text("f_17780:support_2escm"),(void*)f_17780},
{C_text("f_17786:support_2escm"),(void*)f_17786},
{C_text("f_17798:support_2escm"),(void*)f_17798},
{C_text("f_17802:support_2escm"),(void*)f_17802},
{C_text("f_17814:support_2escm"),(void*)f_17814},
{C_text("f_17822:support_2escm"),(void*)f_17822},
{C_text("f_17832:support_2escm"),(void*)f_17832},
{C_text("f_17847:support_2escm"),(void*)f_17847},
{C_text("f_17853:support_2escm"),(void*)f_17853},
{C_text("f_17856:support_2escm"),(void*)f_17856},
{C_text("f_17859:support_2escm"),(void*)f_17859},
{C_text("f_17862:support_2escm"),(void*)f_17862},
{C_text("f_17865:support_2escm"),(void*)f_17865},
{C_text("f_17869:support_2escm"),(void*)f_17869},
{C_text("f_17871:support_2escm"),(void*)f_17871},
{C_text("f_17878:support_2escm"),(void*)f_17878},
{C_text("f_17885:support_2escm"),(void*)f_17885},
{C_text("f_17896:support_2escm"),(void*)f_17896},
{C_text("f_17900:support_2escm"),(void*)f_17900},
{C_text("f_17903:support_2escm"),(void*)f_17903},
{C_text("f_17908:support_2escm"),(void*)f_17908},
{C_text("f_17914:support_2escm"),(void*)f_17914},
{C_text("f_17921:support_2escm"),(void*)f_17921},
{C_text("f_17924:support_2escm"),(void*)f_17924},
{C_text("f_17927:support_2escm"),(void*)f_17927},
{C_text("f_17930:support_2escm"),(void*)f_17930},
{C_text("f_5275:support_2escm"),(void*)f_5275},
{C_text("f_5278:support_2escm"),(void*)f_5278},
{C_text("f_5281:support_2escm"),(void*)f_5281},
{C_text("f_5284:support_2escm"),(void*)f_5284},
{C_text("f_5287:support_2escm"),(void*)f_5287},
{C_text("f_5290:support_2escm"),(void*)f_5290},
{C_text("f_5293:support_2escm"),(void*)f_5293},
{C_text("f_5296:support_2escm"),(void*)f_5296},
{C_text("f_5299:support_2escm"),(void*)f_5299},
{C_text("f_5409:support_2escm"),(void*)f_5409},
{C_text("f_5427:support_2escm"),(void*)f_5427},
{C_text("f_5467:support_2escm"),(void*)f_5467},
{C_text("f_5481:support_2escm"),(void*)f_5481},
{C_text("f_5670:support_2escm"),(void*)f_5670},
{C_text("f_5676:support_2escm"),(void*)f_5676},
{C_text("f_5698:support_2escm"),(void*)f_5698},
{C_text("f_5704:support_2escm"),(void*)f_5704},
{C_text("f_5710:support_2escm"),(void*)f_5710},
{C_text("f_5720:support_2escm"),(void*)f_5720},
{C_text("f_5734:support_2escm"),(void*)f_5734},
{C_text("f_5740:support_2escm"),(void*)f_5740},
{C_text("f_5754:support_2escm"),(void*)f_5754},
{C_text("f_5963:support_2escm"),(void*)f_5963},
{C_text("f_5971:support_2escm"),(void*)f_5971},
{C_text("f_5979:support_2escm"),(void*)f_5979},
{C_text("f_5997:support_2escm"),(void*)f_5997},
{C_text("f_6036:support_2escm"),(void*)f_6036},
{C_text("f_6070:support_2escm"),(void*)f_6070},
{C_text("f_6076:support_2escm"),(void*)f_6076},
{C_text("f_6129:support_2escm"),(void*)f_6129},
{C_text("f_6135:support_2escm"),(void*)f_6135},
{C_text("f_6318:support_2escm"),(void*)f_6318},
{C_text("f_6336:support_2escm"),(void*)f_6336},
{C_text("f_6431:support_2escm"),(void*)f_6431},
{C_text("f_6444:support_2escm"),(void*)f_6444},
{C_text("f_6582:support_2escm"),(void*)f_6582},
{C_text("f_6586:support_2escm"),(void*)f_6586},
{C_text("f_6600:support_2escm"),(void*)f_6600},
{C_text("f_6611:support_2escm"),(void*)f_6611},
{C_text("f_6614:support_2escm"),(void*)f_6614},
{C_text("f_6629:support_2escm"),(void*)f_6629},
{C_text("f_6635:support_2escm"),(void*)f_6635},
{C_text("f_6638:support_2escm"),(void*)f_6638},
{C_text("f_6644:support_2escm"),(void*)f_6644},
{C_text("f_6648:support_2escm"),(void*)f_6648},
{C_text("f_6651:support_2escm"),(void*)f_6651},
{C_text("f_6660:support_2escm"),(void*)f_6660},
{C_text("f_6668:support_2escm"),(void*)f_6668},
{C_text("f_6675:support_2escm"),(void*)f_6675},
{C_text("f_6680:support_2escm"),(void*)f_6680},
{C_text("f_6690:support_2escm"),(void*)f_6690},
{C_text("f_6703:support_2escm"),(void*)f_6703},
{C_text("f_6710:support_2escm"),(void*)f_6710},
{C_text("f_6713:support_2escm"),(void*)f_6713},
{C_text("f_6722:support_2escm"),(void*)f_6722},
{C_text("f_6725:support_2escm"),(void*)f_6725},
{C_text("f_6728:support_2escm"),(void*)f_6728},
{C_text("f_6731:support_2escm"),(void*)f_6731},
{C_text("f_6734:support_2escm"),(void*)f_6734},
{C_text("f_6737:support_2escm"),(void*)f_6737},
{C_text("f_6743:support_2escm"),(void*)f_6743},
{C_text("f_6746:support_2escm"),(void*)f_6746},
{C_text("f_6753:support_2escm"),(void*)f_6753},
{C_text("f_6755:support_2escm"),(void*)f_6755},
{C_text("f_6758:support_2escm"),(void*)f_6758},
{C_text("f_6760:support_2escm"),(void*)f_6760},
{C_text("f_6767:support_2escm"),(void*)f_6767},
{C_text("f_6770:support_2escm"),(void*)f_6770},
{C_text("f_6773:support_2escm"),(void*)f_6773},
{C_text("f_6787:support_2escm"),(void*)f_6787},
{C_text("f_6792:support_2escm"),(void*)f_6792},
{C_text("f_6802:support_2escm"),(void*)f_6802},
{C_text("f_6819:support_2escm"),(void*)f_6819},
{C_text("f_6822:support_2escm"),(void*)f_6822},
{C_text("f_6825:support_2escm"),(void*)f_6825},
{C_text("f_6828:support_2escm"),(void*)f_6828},
{C_text("f_6834:support_2escm"),(void*)f_6834},
{C_text("f_6843:support_2escm"),(void*)f_6843},
{C_text("f_6850:support_2escm"),(void*)f_6850},
{C_text("f_6852:support_2escm"),(void*)f_6852},
{C_text("f_6856:support_2escm"),(void*)f_6856},
{C_text("f_6859:support_2escm"),(void*)f_6859},
{C_text("f_6866:support_2escm"),(void*)f_6866},
{C_text("f_6868:support_2escm"),(void*)f_6868},
{C_text("f_6872:support_2escm"),(void*)f_6872},
{C_text("f_6875:support_2escm"),(void*)f_6875},
{C_text("f_6876:support_2escm"),(void*)f_6876},
{C_text("f_6886:support_2escm"),(void*)f_6886},
{C_text("f_6889:support_2escm"),(void*)f_6889},
{C_text("f_6894:support_2escm"),(void*)f_6894},
{C_text("f_6904:support_2escm"),(void*)f_6904},
{C_text("f_6921:support_2escm"),(void*)f_6921},
{C_text("f_6924:support_2escm"),(void*)f_6924},
{C_text("f_6927:support_2escm"),(void*)f_6927},
{C_text("f_6930:support_2escm"),(void*)f_6930},
{C_text("f_6933:support_2escm"),(void*)f_6933},
{C_text("f_6942:support_2escm"),(void*)f_6942},
{C_text("f_6945:support_2escm"),(void*)f_6945},
{C_text("f_6948:support_2escm"),(void*)f_6948},
{C_text("f_6965:support_2escm"),(void*)f_6965},
{C_text("f_7019:support_2escm"),(void*)f_7019},
{C_text("f_7025:support_2escm"),(void*)f_7025},
{C_text("f_7060:support_2escm"),(void*)f_7060},
{C_text("f_7066:support_2escm"),(void*)f_7066},
{C_text("f_7088:support_2escm"),(void*)f_7088},
{C_text("f_7097:support_2escm"),(void*)f_7097},
{C_text("f_7109:support_2escm"),(void*)f_7109},
{C_text("f_7113:support_2escm"),(void*)f_7113},
{C_text("f_7115:support_2escm"),(void*)f_7115},
{C_text("f_7137:support_2escm"),(void*)f_7137},
{C_text("f_7144:support_2escm"),(void*)f_7144},
{C_text("f_7148:support_2escm"),(void*)f_7148},
{C_text("f_7152:support_2escm"),(void*)f_7152},
{C_text("f_7158:support_2escm"),(void*)f_7158},
{C_text("f_7180:support_2escm"),(void*)f_7180},
{C_text("f_7196:support_2escm"),(void*)f_7196},
{C_text("f_7200:support_2escm"),(void*)f_7200},
{C_text("f_7221:support_2escm"),(void*)f_7221},
{C_text("f_7244:support_2escm"),(void*)f_7244},
{C_text("f_7246:support_2escm"),(void*)f_7246},
{C_text("f_7253:support_2escm"),(void*)f_7253},
{C_text("f_7260:support_2escm"),(void*)f_7260},
{C_text("f_7273:support_2escm"),(void*)f_7273},
{C_text("f_7304:support_2escm"),(void*)f_7304},
{C_text("f_7316:support_2escm"),(void*)f_7316},
{C_text("f_7330:support_2escm"),(void*)f_7330},
{C_text("f_7332:support_2escm"),(void*)f_7332},
{C_text("f_7358:support_2escm"),(void*)f_7358},
{C_text("f_7372:support_2escm"),(void*)f_7372},
{C_text("f_7378:support_2escm"),(void*)f_7378},
{C_text("f_7393:support_2escm"),(void*)f_7393},
{C_text("f_7409:support_2escm"),(void*)f_7409},
{C_text("f_7417:support_2escm"),(void*)f_7417},
{C_text("f_7421:support_2escm"),(void*)f_7421},
{C_text("f_7423:support_2escm"),(void*)f_7423},
{C_text("f_7434:support_2escm"),(void*)f_7434},
{C_text("f_7436:support_2escm"),(void*)f_7436},
{C_text("f_7453:support_2escm"),(void*)f_7453},
{C_text("f_7467:support_2escm"),(void*)f_7467},
{C_text("f_7470:support_2escm"),(void*)f_7470},
{C_text("f_7510:support_2escm"),(void*)f_7510},
{C_text("f_7522:support_2escm"),(void*)f_7522},
{C_text("f_7538:support_2escm"),(void*)f_7538},
{C_text("f_7574:support_2escm"),(void*)f_7574},
{C_text("f_7578:support_2escm"),(void*)f_7578},
{C_text("f_7624:support_2escm"),(void*)f_7624},
{C_text("f_7626:support_2escm"),(void*)f_7626},
{C_text("f_7642:support_2escm"),(void*)f_7642},
{C_text("f_7648:support_2escm"),(void*)f_7648},
{C_text("f_7663:support_2escm"),(void*)f_7663},
{C_text("f_7680:support_2escm"),(void*)f_7680},
{C_text("f_7682:support_2escm"),(void*)f_7682},
{C_text("f_7688:support_2escm"),(void*)f_7688},
{C_text("f_7712:support_2escm"),(void*)f_7712},
{C_text("f_7728:support_2escm"),(void*)f_7728},
{C_text("f_7738:support_2escm"),(void*)f_7738},
{C_text("f_7743:support_2escm"),(void*)f_7743},
{C_text("f_7757:support_2escm"),(void*)f_7757},
{C_text("f_7760:support_2escm"),(void*)f_7760},
{C_text("f_7761:support_2escm"),(void*)f_7761},
{C_text("f_7765:support_2escm"),(void*)f_7765},
{C_text("f_7770:support_2escm"),(void*)f_7770},
{C_text("f_7776:support_2escm"),(void*)f_7776},
{C_text("f_7782:support_2escm"),(void*)f_7782},
{C_text("f_7790:support_2escm"),(void*)f_7790},
{C_text("f_7793:support_2escm"),(void*)f_7793},
{C_text("f_7801:support_2escm"),(void*)f_7801},
{C_text("f_7803:support_2escm"),(void*)f_7803},
{C_text("f_7807:support_2escm"),(void*)f_7807},
{C_text("f_7829:support_2escm"),(void*)f_7829},
{C_text("f_7835:support_2escm"),(void*)f_7835},
{C_text("f_7839:support_2escm"),(void*)f_7839},
{C_text("f_7856:support_2escm"),(void*)f_7856},
{C_text("f_7862:support_2escm"),(void*)f_7862},
{C_text("f_7873:support_2escm"),(void*)f_7873},
{C_text("f_7875:support_2escm"),(void*)f_7875},
{C_text("f_7878:support_2escm"),(void*)f_7878},
{C_text("f_7884:support_2escm"),(void*)f_7884},
{C_text("f_7923:support_2escm"),(void*)f_7923},
{C_text("f_7928:support_2escm"),(void*)f_7928},
{C_text("f_7932:support_2escm"),(void*)f_7932},
{C_text("f_7936:support_2escm"),(void*)f_7936},
{C_text("f_7987:support_2escm"),(void*)f_7987},
{C_text("f_8024:support_2escm"),(void*)f_8024},
{C_text("f_8026:support_2escm"),(void*)f_8026},
{C_text("f_8076:support_2escm"),(void*)f_8076},
{C_text("f_8080:support_2escm"),(void*)f_8080},
{C_text("f_8094:support_2escm"),(void*)f_8094},
{C_text("f_8098:support_2escm"),(void*)f_8098},
{C_text("f_8106:support_2escm"),(void*)f_8106},
{C_text("f_8112:support_2escm"),(void*)f_8112},
{C_text("f_8116:support_2escm"),(void*)f_8116},
{C_text("f_8158:support_2escm"),(void*)f_8158},
{C_text("f_8162:support_2escm"),(void*)f_8162},
{C_text("f_8210:support_2escm"),(void*)f_8210},
{C_text("f_8214:support_2escm"),(void*)f_8214},
{C_text("f_8220:support_2escm"),(void*)f_8220},
{C_text("f_8226:support_2escm"),(void*)f_8226},
{C_text("f_8232:support_2escm"),(void*)f_8232},
{C_text("f_8241:support_2escm"),(void*)f_8241},
{C_text("f_8250:support_2escm"),(void*)f_8250},
{C_text("f_8259:support_2escm"),(void*)f_8259},
{C_text("f_8268:support_2escm"),(void*)f_8268},
{C_text("f_8277:support_2escm"),(void*)f_8277},
{C_text("f_8287:support_2escm"),(void*)f_8287},
{C_text("f_8289:support_2escm"),(void*)f_8289},
{C_text("f_8295:support_2escm"),(void*)f_8295},
{C_text("f_8310:support_2escm"),(void*)f_8310},
{C_text("f_8325:support_2escm"),(void*)f_8325},
{C_text("f_8328:support_2escm"),(void*)f_8328},
{C_text("f_8395:support_2escm"),(void*)f_8395},
{C_text("f_8397:support_2escm"),(void*)f_8397},
{C_text("f_8422:support_2escm"),(void*)f_8422},
{C_text("f_8445:support_2escm"),(void*)f_8445},
{C_text("f_8448:support_2escm"),(void*)f_8448},
{C_text("f_8451:support_2escm"),(void*)f_8451},
{C_text("f_8458:support_2escm"),(void*)f_8458},
{C_text("f_8505:support_2escm"),(void*)f_8505},
{C_text("f_8509:support_2escm"),(void*)f_8509},
{C_text("f_8514:support_2escm"),(void*)f_8514},
{C_text("f_8531:support_2escm"),(void*)f_8531},
{C_text("f_8539:support_2escm"),(void*)f_8539},
{C_text("f_8541:support_2escm"),(void*)f_8541},
{C_text("f_8566:support_2escm"),(void*)f_8566},
{C_text("f_8602:support_2escm"),(void*)f_8602},
{C_text("f_8636:support_2escm"),(void*)f_8636},
{C_text("f_8667:support_2escm"),(void*)f_8667},
{C_text("f_8690:support_2escm"),(void*)f_8690},
{C_text("f_8711:support_2escm"),(void*)f_8711},
{C_text("f_8733:support_2escm"),(void*)f_8733},
{C_text("f_8741:support_2escm"),(void*)f_8741},
{C_text("f_8745:support_2escm"),(void*)f_8745},
{C_text("f_8753:support_2escm"),(void*)f_8753},
{C_text("f_8774:support_2escm"),(void*)f_8774},
{C_text("f_8778:support_2escm"),(void*)f_8778},
{C_text("f_8790:support_2escm"),(void*)f_8790},
{C_text("f_8817:support_2escm"),(void*)f_8817},
{C_text("f_8829:support_2escm"),(void*)f_8829},
{C_text("f_8831:support_2escm"),(void*)f_8831},
{C_text("f_8856:support_2escm"),(void*)f_8856},
{C_text("f_8890:support_2escm"),(void*)f_8890},
{C_text("f_8916:support_2escm"),(void*)f_8916},
{C_text("f_8918:support_2escm"),(void*)f_8918},
{C_text("f_8943:support_2escm"),(void*)f_8943},
{C_text("f_9027:support_2escm"),(void*)f_9027},
{C_text("f_9029:support_2escm"),(void*)f_9029},
{C_text("f_9054:support_2escm"),(void*)f_9054},
{C_text("f_9094:support_2escm"),(void*)f_9094},
{C_text("f_9135:support_2escm"),(void*)f_9135},
{C_text("f_9164:support_2escm"),(void*)f_9164},
{C_text("f_9166:support_2escm"),(void*)f_9166},
{C_text("f_9191:support_2escm"),(void*)f_9191},
{C_text("f_9227:support_2escm"),(void*)f_9227},
{C_text("f_9229:support_2escm"),(void*)f_9229},
{C_text("f_9254:support_2escm"),(void*)f_9254},
{C_text("f_9266:support_2escm"),(void*)f_9266},
{C_text("f_9272:support_2escm"),(void*)f_9272},
{C_text("f_9295:support_2escm"),(void*)f_9295},
{C_text("f_9297:support_2escm"),(void*)f_9297},
{C_text("f_9322:support_2escm"),(void*)f_9322},
{C_text("f_9333:support_2escm"),(void*)f_9333},
{C_text("f_9337:support_2escm"),(void*)f_9337},
{C_text("f_9340:support_2escm"),(void*)f_9340},
{C_text("f_9347:support_2escm"),(void*)f_9347},
{C_text("f_9361:support_2escm"),(void*)f_9361},
{C_text("f_9467:support_2escm"),(void*)f_9467},
{C_text("f_9469:support_2escm"),(void*)f_9469},
{C_text("f_9494:support_2escm"),(void*)f_9494},
{C_text("f_9512:support_2escm"),(void*)f_9512},
{C_text("f_9515:support_2escm"),(void*)f_9515},
{C_text("f_9521:support_2escm"),(void*)f_9521},
{C_text("f_9527:support_2escm"),(void*)f_9527},
{C_text("f_9561:support_2escm"),(void*)f_9561},
{C_text("f_9574:support_2escm"),(void*)f_9574},
{C_text("f_9576:support_2escm"),(void*)f_9576},
{C_text("f_9601:support_2escm"),(void*)f_9601},
{C_text("f_9631:support_2escm"),(void*)f_9631},
{C_text("f_9633:support_2escm"),(void*)f_9633},
{C_text("f_9658:support_2escm"),(void*)f_9658},
{C_text("f_9731:support_2escm"),(void*)f_9731},
{C_text("f_9734:support_2escm"),(void*)f_9734},
{C_text("f_9743:support_2escm"),(void*)f_9743},
{C_text("f_9747:support_2escm"),(void*)f_9747},
{C_text("f_9751:support_2escm"),(void*)f_9751},
{C_text("f_9753:support_2escm"),(void*)f_9753},
{C_text("f_9801:support_2escm"),(void*)f_9801},
{C_text("f_9826:support_2escm"),(void*)f_9826},
{C_text("f_9854:support_2escm"),(void*)f_9854},
{C_text("f_9878:support_2escm"),(void*)f_9878},
{C_text("f_9912:support_2escm"),(void*)f_9912},
{C_text("f_9916:support_2escm"),(void*)f_9916},
{C_text("f_9926:support_2escm"),(void*)f_9926},
{C_text("f_9950:support_2escm"),(void*)f_9950},
{C_text("f_9965:support_2escm"),(void*)f_9965},
{C_text("f_9977:support_2escm"),(void*)f_9977},
{C_text("toplevel:support_2escm"),(void*)C_support_toplevel},
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
o|hiding unexported module binding: chicken.compiler.support#partition 
o|hiding unexported module binding: chicken.compiler.support#span 
o|hiding unexported module binding: chicken.compiler.support#take 
o|hiding unexported module binding: chicken.compiler.support#drop 
o|hiding unexported module binding: chicken.compiler.support#split-at 
o|hiding unexported module binding: chicken.compiler.support#append-map 
o|hiding unexported module binding: chicken.compiler.support#every 
o|hiding unexported module binding: chicken.compiler.support#any 
o|hiding unexported module binding: chicken.compiler.support#cons* 
o|hiding unexported module binding: chicken.compiler.support#concatenate 
o|hiding unexported module binding: chicken.compiler.support#delete 
o|hiding unexported module binding: chicken.compiler.support#first 
o|hiding unexported module binding: chicken.compiler.support#second 
o|hiding unexported module binding: chicken.compiler.support#third 
o|hiding unexported module binding: chicken.compiler.support#fourth 
o|hiding unexported module binding: chicken.compiler.support#fifth 
o|hiding unexported module binding: chicken.compiler.support#delete-duplicates 
o|hiding unexported module binding: chicken.compiler.support#alist-cons 
o|hiding unexported module binding: chicken.compiler.support#filter 
o|hiding unexported module binding: chicken.compiler.support#filter-map 
o|hiding unexported module binding: chicken.compiler.support#remove 
o|hiding unexported module binding: chicken.compiler.support#unzip1 
o|hiding unexported module binding: chicken.compiler.support#last 
o|hiding unexported module binding: chicken.compiler.support#list-index 
o|hiding unexported module binding: chicken.compiler.support#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.compiler.support#lset-difference/eq? 
o|hiding unexported module binding: chicken.compiler.support#lset-union/eq? 
o|hiding unexported module binding: chicken.compiler.support#lset-intersection/eq? 
o|hiding unexported module binding: chicken.compiler.support#list-tabulate 
o|hiding unexported module binding: chicken.compiler.support#lset<=/eq? 
o|hiding unexported module binding: chicken.compiler.support#lset=/eq? 
o|hiding unexported module binding: chicken.compiler.support#length+ 
o|hiding unexported module binding: chicken.compiler.support#find 
o|hiding unexported module binding: chicken.compiler.support#find-tail 
o|hiding unexported module binding: chicken.compiler.support#iota 
o|hiding unexported module binding: chicken.compiler.support#make-list 
o|hiding unexported module binding: chicken.compiler.support#posq 
o|hiding unexported module binding: chicken.compiler.support#posv 
o|hiding unexported module binding: chicken.compiler.support#constant678 
o|hiding unexported module binding: chicken.compiler.support#+logged-debugging-modes+ 
o|hiding unexported module binding: chicken.compiler.support#test-debugging-mode 
o|hiding unexported module binding: chicken.compiler.support#map-llist 
o|hiding unexported module binding: chicken.compiler.support#follow-without-loop 
o|hiding unexported module binding: chicken.compiler.support#sort-symbols 
o|hiding unexported module binding: chicken.compiler.support#bwp-object? 
o|hiding unexported module binding: chicken.compiler.support#profile-info-vector-name 
o|hiding unexported module binding: chicken.compiler.support#profile-lambda-list 
o|hiding unexported module binding: chicken.compiler.support#profile-lambda-index 
o|hiding unexported module binding: chicken.compiler.support#node 
o|hiding unexported module binding: chicken.compiler.support#copy-node-tree-and-rename 
o|hiding unexported module binding: chicken.compiler.support#replace-rest-ops-in-known-call! 
o|hiding unexported module binding: chicken.compiler.support#node->sexpr 
o|hiding unexported module binding: chicken.compiler.support#sexpr->node 
o|hiding unexported module binding: chicken.compiler.support#foreign-callback-stub 
o|hiding unexported module binding: chicken.compiler.support#foreign-type-table 
o|hiding unexported module binding: chicken.compiler.support#foreign-type-result-converter 
o|hiding unexported module binding: chicken.compiler.support#foreign-type-argument-converter 
o|hiding unexported module binding: chicken.compiler.support#block-variable-literal 
o|hiding unexported module binding: chicken.compiler.support#real-name-table 
o|hiding unexported module binding: chicken.compiler.support#real-name-max-depth 
o|hiding unexported module binding: chicken.compiler.support#encodeable-literal? 
o|hiding unexported module binding: chicken.compiler.support#scan-sharp-greater-string 
o|hiding unexported module binding: chicken.compiler.support#unhide-variable 
S|applied compiler syntax:
S|  chicken.format#sprintf		4
S|  chicken.format#fprintf		5
S|  chicken.format#printf		5
S|  scheme#for-each		12
S|  chicken.base#foldl		3
S|  scheme#map		33
S|  chicken.base#foldr		3
o|eliminated procedure checks: 446 
o|specializations:
o|  1 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#+ fixnum fixnum)
o|  1 (scheme#number->string * *)
o|  1 (chicken.base#exact-integer? *)
o|  2 (chicken.bitwise#integer-length *)
o|  1 (scheme#length list)
o|  1 (scheme#- fixnum fixnum)
o|  4 (scheme#= fixnum fixnum)
o|  2 (scheme#assq * (list-of pair))
o|  1 (scheme#* fixnum fixnum)
o|  1 (scheme#positive? *)
o|  4 (scheme#cddr (pair * pair))
o|  1 (scheme#caddr (pair * (pair * pair)))
o|  1 (scheme#integer? *)
o|  338 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  2 (##sys#call-with-values (procedure () *) *)
o|  5 (chicken.base#add1 *)
o|  1 (scheme#cadr (pair * pair))
o|  2 (scheme#current-input-port)
o|  4 (scheme#char=? char char)
o|  1 (scheme#number->string fixnum fixnum)
o|  2 (scheme#memq * list)
o|  1 (scheme#>= fixnum fixnum)
o|  3 (scheme#< fixnum fixnum)
o|  3 (chicken.base#sub1 *)
o|  4 (scheme#zero? *)
o|  2 (chicken.base#current-error-port)
o|  14 (##sys#check-output-port * * *)
o|  1 (scheme#eqv? * *)
o|  9 (##sys#check-list (or pair list) *)
o|  55 (scheme#cdr pair)
o|  33 (scheme#car pair)
(o e)|safe calls: 1878 
(o e)|assignments to immediate values: 5 
o|safe globals: (chicken.compiler.support#bomb chicken.compiler.support#debugging-chicken chicken.compiler.support#compiler-cleanup-hook chicken.compiler.support#unsafe chicken.compiler.support#number-type chicken.compiler.support#constant678 chicken.compiler.support#posv chicken.compiler.support#posq chicken.compiler.support#make-list chicken.compiler.support#iota chicken.compiler.support#find-tail chicken.compiler.support#find chicken.compiler.support#length+ chicken.compiler.support#lset=/eq? chicken.compiler.support#lset<=/eq? chicken.compiler.support#list-tabulate chicken.compiler.support#lset-intersection/eq? chicken.compiler.support#lset-union/eq? chicken.compiler.support#lset-difference/eq? chicken.compiler.support#lset-adjoin/eq? chicken.compiler.support#list-index chicken.compiler.support#last chicken.compiler.support#unzip1 chicken.compiler.support#remove chicken.compiler.support#filter-map chicken.compiler.support#filter chicken.compiler.support#alist-cons chicken.compiler.support#delete-duplicates chicken.compiler.support#fifth chicken.compiler.support#fourth chicken.compiler.support#third chicken.compiler.support#second chicken.compiler.support#first chicken.compiler.support#delete chicken.compiler.support#concatenate chicken.compiler.support#cons* chicken.compiler.support#any chicken.compiler.support#every chicken.compiler.support#append-map chicken.compiler.support#split-at chicken.compiler.support#drop chicken.compiler.support#take chicken.compiler.support#span chicken.compiler.support#partition) 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#partition 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#span 
o|inlining procedure: k5411 
o|inlining procedure: k5411 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#drop 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#append-map 
o|inlining procedure: k5681 
o|inlining procedure: k5681 
o|inlining procedure: k5712 
o|inlining procedure: k5712 
o|merged explicitly consed rest parameter: xs339 
o|inlining procedure: k5742 
o|inlining procedure: k5742 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#concatenate 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#delete-duplicates 
o|inlining procedure: k5929 
o|inlining procedure: k5929 
o|inlining procedure: k5921 
o|inlining procedure: k5921 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#remove 
o|inlining procedure: k6078 
o|inlining procedure: k6078 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#list-index 
o|merged explicitly consed rest parameter: vals479 
o|inlining procedure: k6137 
o|inlining procedure: k6137 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#lset-intersection/eq? 
o|inlining procedure: k6320 
o|inlining procedure: k6320 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#length+ 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#find-tail 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#iota 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#make-list 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#posq 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#posv 
o|inlining procedure: k6588 
o|inlining procedure: k6588 
o|inlining procedure: k6616 
o|inlining procedure: k6616 
o|inlining procedure: k6649 
o|inlining procedure: k6682 
o|contracted procedure: "(support.scm:135) g705712" 
o|propagated global variable: out715718 ##sys#standard-output 
o|substituted constant variable: a6664 
o|substituted constant variable: a6665 
o|inlining procedure: k6682 
o|inlining procedure: k6649 
o|propagated global variable: out730733 chicken.compiler.support#collected-debugging-output 
o|substituted constant variable: a6706 
o|substituted constant variable: a6707 
o|propagated global variable: out730733 chicken.compiler.support#collected-debugging-output 
o|inlining procedure: k6717 
o|inlining procedure: k6717 
o|propagated global variable: out766769 chicken.compiler.support#collected-debugging-output 
o|substituted constant variable: a6763 
o|substituted constant variable: a6764 
o|inlining procedure: k6778 
o|inlining procedure: k6778 
o|inlining procedure: k6794 
o|inlining procedure: k6794 
o|inlining procedure: k6814 
o|inlining procedure: k6814 
o|inlining procedure: k6896 
o|inlining procedure: k6896 
o|substituted constant variable: a6917 
o|substituted constant variable: a6918 
o|substituted constant variable: a6938 
o|substituted constant variable: a6939 
o|contracted procedure: "(support.scm:196) thread-id846" 
o|propagated global variable: t847 ##sys#current-thread 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#map-llist 
o|inlining procedure: k7027 
o|inlining procedure: k7027 
o|inlining procedure: k7042 
o|inlining procedure: k7042 
o|inlining procedure: k7068 
o|inlining procedure: k7068 
o|inlining procedure: k7117 
o|inlining procedure: k7117 
o|substituted constant variable: a7160 
o|inlining procedure: k7164 
o|inlining procedure: k7164 
o|substituted constant variable: a7171 
o|substituted constant variable: a7173 
o|inlining procedure: k7186 
o|inlining procedure: k7186 
o|substituted constant variable: a7190 
o|substituted constant variable: a7192 
o|substituted constant variable: a7194 
o|inlining procedure: k7201 
o|inlining procedure: k7226 
o|inlining procedure: k7226 
o|substituted constant variable: a7235 
o|substituted constant variable: a7239 
o|inlining procedure: k7201 
o|inlining procedure: k7262 
o|propagated global variable: r726318014 ##sys#standard-input 
o|inlining procedure: k7262 
o|inlining procedure: k7277 
o|inlining procedure: k7277 
o|inlining procedure: k7306 
o|inlining procedure: k7306 
o|inlining procedure: k7318 
o|inlining procedure: k7318 
o|inlining procedure: k7338 
o|inlining procedure: k7338 
o|inlining procedure: k7380 
o|inlining procedure: k7380 
o|inlining procedure: k7438 
o|inlining procedure: k7438 
o|inlining procedure: k7475 
o|inlining procedure: k7475 
o|inlining procedure: k7487 
o|inlining procedure: k7487 
o|inlining procedure: k7499 
o|inlining procedure: k7499 
o|inlining procedure: k7511 
o|inlining procedure: k7511 
o|inlining procedure: k7523 
o|inlining procedure: k7523 
o|inlining procedure: k7543 
o|inlining procedure: k7543 
o|inlining procedure: k7555 
o|inlining procedure: k7555 
o|inlining procedure: k7567 
o|inlining procedure: k7567 
o|inlining procedure: k7579 
o|inlining procedure: k7579 
o|inlining procedure: k7591 
o|inlining procedure: k7591 
o|inlining procedure: k7603 
o|inlining procedure: k7603 
o|inlining procedure: k7631 
o|inlining procedure: k7631 
o|inlining procedure: k7643 
o|inlining procedure: k7643 
o|inlining procedure: k7652 
o|inlining procedure: k7652 
o|inlining procedure: k7690 
o|inlining procedure: k7690 
o|inlining procedure: k7703 
o|inlining procedure: k7703 
o|inlining procedure: k7744 
o|inlining procedure: k7744 
o|inlining procedure: k7788 
o|inlining procedure: k7788 
o|inlining procedure: k7808 
o|inlining procedure: k7808 
o|inlining procedure: k7840 
o|inlining procedure: k7840 
o|merged explicitly consed rest parameter: args10951113 
o|consed rest parameter at call site: tmp24909 1 
o|inlining procedure: k7886 
o|inlining procedure: k7886 
o|inlining procedure: k7901 
o|inlining procedure: k7901 
o|inlining procedure: k8028 
o|contracted procedure: "(support.scm:407) g11581167" 
o|inlining procedure: k8028 
o|propagated global variable: g11641168 chicken.compiler.support#profile-lambda-list 
o|inlining procedure: k8081 
o|inlining procedure: k8081 
o|inlining procedure: k8099 
o|contracted procedure: "(support.scm:425) chicken.compiler.support#filter-map" 
o|inlining procedure: k5976 
o|inlining procedure: k5976 
o|inlining procedure: k5965 
o|inlining procedure: k5965 
o|inlining procedure: k8099 
o|inlining procedure: k8117 
o|inlining procedure: k8129 
o|inlining procedure: k8129 
o|inlining procedure: k8117 
o|inlining procedure: k8163 
o|inlining procedure: k8163 
o|inlining procedure: k8215 
o|inlining procedure: k8215 
o|contracted procedure: "(support.scm:467) g12841285" 
o|contracted procedure: "(support.scm:468) g12911292" 
o|inlining procedure: k8330 
o|inlining procedure: k8330 
o|inlining procedure: k8350 
o|inlining procedure: k8350 
o|inlining procedure: k8366 
o|contracted procedure: "(support.scm:478) g13171318" 
o|inlining procedure: k8399 
o|inlining procedure: k8399 
o|inlining procedure: k8366 
o|inlining procedure: k8443 
o|inlining procedure: k8443 
o|inlining procedure: k8462 
o|inlining procedure: k8462 
o|inlining procedure: k8473 
o|contracted procedure: "(support.scm:494) g13541355" 
o|inlining procedure: k8543 
o|inlining procedure: k8543 
o|contracted procedure: "(support.scm:495) chicken.compiler.support#unzip1" 
o|inlining procedure: k6038 
o|contracted procedure: "(mini-srfi-1.scm:143) g442451" 
o|inlining procedure: k6038 
o|inlining procedure: k8473 
o|contracted procedure: "(support.scm:499) g13891390" 
o|inlining procedure: k8611 
o|contracted procedure: "(support.scm:501) g13941395" 
o|inlining procedure: "(support.scm:503) chicken.compiler.support#fourth" 
o|inlining procedure: "(support.scm:502) chicken.compiler.support#third" 
o|inlining procedure: "(support.scm:502) chicken.compiler.support#second" 
o|inlining procedure: k8611 
o|inlining procedure: k8669 
o|contracted procedure: "(support.scm:508) g14071408" 
o|contracted procedure: "(support.scm:512) g14121413" 
o|inlining procedure: k8669 
o|contracted procedure: "(support.scm:514) g14171418" 
o|inlining procedure: k8795 
o|contracted procedure: "(support.scm:523) g14241425" 
o|inlining procedure: k8833 
o|inlining procedure: k8833 
o|inlining procedure: k8865 
o|inlining procedure: k8865 
o|inlining procedure: k8795 
o|contracted procedure: "(support.scm:528) g14621463" 
o|inlining procedure: k8920 
o|inlining procedure: k8920 
o|inlining procedure: k8955 
o|contracted procedure: "(support.scm:530) g14931494" 
o|inlining procedure: k8955 
o|contracted procedure: "(support.scm:532) g14981499" 
o|inlining procedure: k8995 
o|contracted procedure: "(support.scm:534) g15061507" 
o|inlining procedure: k9031 
o|inlining procedure: k9031 
o|inlining procedure: k8995 
o|contracted procedure: "(support.scm:539) g15381539" 
o|contracted procedure: "(support.scm:541) chicken.compiler.support#fifth" 
o|inlining procedure: "(support.scm:541) chicken.compiler.support#fourth" 
o|inlining procedure: "(support.scm:541) chicken.compiler.support#third" 
o|inlining procedure: "(support.scm:538) chicken.compiler.support#second" 
o|inlining procedure: k9127 
o|contracted procedure: "(support.scm:545) g15551556" 
o|inlining procedure: k9168 
o|inlining procedure: k9168 
o|inlining procedure: "(support.scm:545) chicken.compiler.support#second" 
o|inlining procedure: "(support.scm:545) chicken.compiler.support#first" 
o|inlining procedure: k9127 
o|contracted procedure: "(support.scm:547) g15861587" 
o|inlining procedure: k9231 
o|inlining procedure: k9231 
o|contracted procedure: "(support.scm:550) g16191620" 
o|inlining procedure: k9299 
o|inlining procedure: k9299 
o|inlining procedure: k9335 
o|inlining procedure: k9345 
o|inlining procedure: k9345 
o|inlining procedure: k9335 
o|contracted procedure: "(support.scm:552) g16281629" 
o|substituted constant variable: a9365 
o|inlining procedure: k9369 
o|inlining procedure: k9369 
o|inlining procedure: k9381 
o|inlining procedure: k9381 
o|substituted constant variable: a9388 
o|substituted constant variable: a9390 
o|substituted constant variable: a9392 
o|substituted constant variable: a9394 
o|substituted constant variable: a9396 
o|substituted constant variable: a9398 
o|substituted constant variable: a9403 
o|substituted constant variable: a9405 
o|substituted constant variable: a9407 
o|substituted constant variable: a9409 
o|inlining procedure: k9413 
o|inlining procedure: k9413 
o|substituted constant variable: a9420 
o|substituted constant variable: a9422 
o|substituted constant variable: a9424 
o|substituted constant variable: a9426 
o|substituted constant variable: a9428 
o|substituted constant variable: a9430 
o|substituted constant variable: a9435 
o|substituted constant variable: a9437 
o|substituted constant variable: a9439 
o|substituted constant variable: a9441 
o|substituted constant variable: a9446 
o|substituted constant variable: a9448 
o|contracted procedure: "(support.scm:562) g16631664" 
o|inlining procedure: k9471 
o|inlining procedure: k9471 
o|contracted procedure: "(support.scm:474) g13051306" 
o|inlining procedure: k9513 
o|inlining procedure: k9513 
o|inlining procedure: k9553 
o|inlining procedure: k9578 
o|inlining procedure: k9578 
o|inlining procedure: k9553 
o|inlining procedure: k9635 
o|inlining procedure: k9635 
o|inlining procedure: k9666 
o|inlining procedure: k9666 
o|inlining procedure: k9684 
o|inlining procedure: k9684 
o|inlining procedure: k9701 
o|inlining procedure: k9701 
o|inlining procedure: k9713 
o|inlining procedure: k9755 
o|inlining procedure: k9755 
o|inlining procedure: k9803 
o|inlining procedure: k9803 
o|inlining procedure: k9713 
o|inlining procedure: "(support.scm:590) chicken.compiler.support#third" 
o|inlining procedure: "(support.scm:587) chicken.compiler.support#second" 
o|inlining procedure: k9862 
o|inlining procedure: "(support.scm:593) chicken.compiler.support#first" 
o|inlining procedure: "(support.scm:593) chicken.compiler.support#first" 
o|inlining procedure: k9862 
o|inlining procedure: "(support.scm:595) chicken.compiler.support#first" 
o|inlining procedure: k9896 
o|inlining procedure: k9928 
o|inlining procedure: k9928 
o|inlining procedure: "(support.scm:598) chicken.compiler.support#first" 
o|inlining procedure: k9896 
o|inlining procedure: k10004 
o|inlining procedure: k10004 
o|inlining procedure: k10035 
o|consed rest parameter at call site: "(support.scm:608) chicken.compiler.support#cons*" 2 
o|inlining procedure: k10061 
o|inlining procedure: k10061 
o|inlining procedure: k10035 
o|inlining procedure: k10101 
o|inlining procedure: k10117 
o|inlining procedure: k10117 
o|inlining procedure: k10101 
o|consed rest parameter at call site: "(support.scm:616) chicken.compiler.support#cons*" 2 
o|inlining procedure: k10187 
o|inlining procedure: k10187 
o|inlining procedure: k10222 
o|consed rest parameter at call site: "(support.scm:618) chicken.compiler.support#cons*" 2 
o|inlining procedure: k10244 
o|inlining procedure: k10244 
o|inlining procedure: k10222 
o|inlining procedure: k10295 
o|inlining procedure: k10295 
o|substituted constant variable: a10327 
o|inlining procedure: k10331 
o|inlining procedure: k10331 
o|substituted constant variable: a10344 
o|substituted constant variable: a10346 
o|substituted constant variable: a10348 
o|substituted constant variable: a10350 
o|substituted constant variable: a10352 
o|substituted constant variable: a10354 
o|substituted constant variable: a10356 
o|substituted constant variable: a10358 
o|substituted constant variable: a10360 
o|substituted constant variable: a10362 
o|substituted constant variable: a10364 
o|substituted constant variable: a10366 
o|substituted constant variable: a10368 
o|substituted constant variable: a10370 
o|substituted constant variable: a10372 
o|substituted constant variable: a10374 
o|inlining procedure: k10378 
o|inlining procedure: k10378 
o|substituted constant variable: a10385 
o|substituted constant variable: a10387 
o|substituted constant variable: a10389 
o|contracted procedure: "(support.scm:572) g17101711" 
o|contracted procedure: "(support.scm:571) g17071708" 
o|contracted procedure: "(support.scm:570) g17041705" 
o|inlining procedure: k10399 
o|inlining procedure: k10399 
o|contracted procedure: "(support.scm:625) g20192020" 
o|inlining procedure: "(support.scm:627) chicken.compiler.support#second" 
o|inlining procedure: "(support.scm:627) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:635) chicken.compiler.support#split-at" 
o|inlining procedure: k5469 
o|inlining procedure: k5469 
o|inlining procedure: k10499 
o|inlining procedure: k10514 
o|contracted procedure: "(support.scm:664) g21202121" 
o|inlining procedure: k10543 
o|inlining procedure: k10543 
o|contracted procedure: "(support.scm:668) g21252126" 
o|substituted constant variable: a10565 
o|inlining procedure: k10514 
o|contracted procedure: "(support.scm:673) g21302131" 
o|inlining procedure: k10499 
o|contracted procedure: "(support.scm:677) g21362137" 
o|inlining procedure: k10668 
o|inlining procedure: k10668 
o|contracted procedure: "(support.scm:641) chicken.compiler.support#replace-rest-ops-in-known-call!" 
o|inlining procedure: k11310 
o|inlining procedure: "(support.scm:740) chicken.compiler.support#second" 
o|inlining procedure: "(support.scm:739) chicken.compiler.support#first" 
o|inlining procedure: k11310 
o|inlining procedure: k11351 
o|contracted procedure: "(support.scm:748) g24022403" 
o|inlining procedure: "(support.scm:744) chicken.compiler.support#second" 
o|inlining procedure: k11351 
o|inlining procedure: "(support.scm:743) chicken.compiler.support#first" 
o|inlining procedure: k11416 
o|inlining procedure: k11446 
o|inlining procedure: k11446 
o|contracted procedure: "(support.scm:761) g24142415" 
o|inlining procedure: "(support.scm:756) chicken.compiler.support#second" 
o|inlining procedure: "(support.scm:754) chicken.compiler.support#first" 
o|inlining procedure: k11416 
o|inlining procedure: k11488 
o|inlining procedure: k11488 
o|substituted constant variable: a11509 
o|substituted constant variable: a11511 
o|substituted constant variable: a11513 
o|contracted procedure: "(support.scm:736) g23912392" 
o|contracted procedure: "(support.scm:735) g23882389" 
o|contracted procedure: "(support.scm:734) g23852386" 
o|inlining procedure: k10695 
o|contracted procedure: "(support.scm:640) g20742083" 
o|inlining procedure: k10695 
o|contracted procedure: "(support.scm:638) chicken.compiler.support#copy-node-tree-and-rename" 
o|inlining procedure: k10820 
o|contracted procedure: "(support.scm:691) g22062207" 
o|inlining procedure: k10820 
o|inlining procedure: "(support.scm:696) rename2182" 
o|inlining procedure: "(support.scm:693) chicken.compiler.support#first" 
o|inlining procedure: k10859 
o|contracted procedure: "(support.scm:698) g22132214" 
o|inlining procedure: "(support.scm:700) chicken.compiler.support#first" 
o|inlining procedure: "(support.scm:699) rename2182" 
o|inlining procedure: "(support.scm:699) chicken.compiler.support#first" 
o|inlining procedure: k10859 
o|contracted procedure: "(support.scm:707) g22222223" 
o|inlining procedure: "(support.scm:709) chicken.compiler.support#second" 
o|inlining procedure: "(support.scm:703) chicken.compiler.support#first" 
o|inlining procedure: "(support.scm:702) chicken.compiler.support#first" 
o|inlining procedure: k10946 
o|contracted procedure: "(support.scm:720) g22932294" 
o|inlining procedure: k11012 
o|inlining procedure: k11012 
o|inlining procedure: "(support.scm:724) chicken.compiler.support#fourth" 
o|inlining procedure: k11060 
o|inlining procedure: "(support.scm:723) rename2182" 
o|inlining procedure: k11060 
o|inlining procedure: "(support.scm:722) chicken.compiler.support#second" 
o|inlining procedure: k11079 
o|inlining procedure: k11079 
o|inlining procedure: k11127 
o|inlining procedure: k11127 
o|inlining procedure: "(support.scm:712) chicken.compiler.support#third" 
o|inlining procedure: k10946 
o|contracted procedure: "(support.scm:726) g23332334" 
o|inlining procedure: k11188 
o|inlining procedure: k11188 
o|substituted constant variable: a11220 
o|substituted constant variable: a11222 
o|substituted constant variable: a11224 
o|substituted constant variable: a11226 
o|substituted constant variable: a11228 
o|contracted procedure: "(support.scm:688) g21972198" 
o|contracted procedure: "(support.scm:687) g21942195" 
o|contracted procedure: "(support.scm:686) g21912192" 
o|inlining procedure: k11235 
o|inlining procedure: k11235 
o|inlining procedure: k10741 
o|inlining procedure: k10741 
o|inlining procedure: k11520 
o|contracted procedure: "(support.scm:770) g24492450" 
o|inlining procedure: "(support.scm:772) chicken.compiler.support#second" 
o|inlining procedure: k11520 
o|inlining procedure: k11567 
o|inlining procedure: k11567 
o|contracted procedure: "(support.scm:779) g24572458" 
o|inlining procedure: "(support.scm:774) chicken.compiler.support#second" 
o|inlining procedure: k11593 
o|contracted procedure: "(support.scm:781) g24632464" 
o|contracted procedure: "(support.scm:784) g24682469" 
o|inlining procedure: "(support.scm:783) chicken.compiler.support#second" 
o|inlining procedure: k11593 
o|contracted procedure: "(support.scm:786) g24732474" 
o|inlining procedure: "(support.scm:788) chicken.compiler.support#second" 
o|substituted constant variable: a11674 
o|substituted constant variable: a11676 
o|substituted constant variable: a11678 
o|substituted constant variable: a11680 
o|inlining procedure: k11690 
o|inlining procedure: k11690 
o|contracted procedure: "(support.scm:799) g24852486" 
o|contracted procedure: "(support.scm:801) g24962497" 
o|contracted procedure: "(support.scm:800) g24932494" 
o|contracted procedure: "(support.scm:799) g24902491" 
o|contracted procedure: "(support.scm:806) g25082509" 
o|contracted procedure: "(support.scm:805) g25052506" 
o|contracted procedure: "(support.scm:804) g25022503" 
o|inlining procedure: k11965 
o|contracted procedure: "(support.scm:827) g26132614" 
o|inlining procedure: k11965 
o|contracted procedure: "(support.scm:829) g26162617" 
o|substituted constant variable: a12000 
o|contracted procedure: "(support.scm:825) g26102611" 
o|inlining procedure: k12007 
o|inlining procedure: k12030 
o|contracted procedure: "(support.scm:865) g26952702" 
o|inlining procedure: k12030 
o|contracted procedure: "(support.scm:865) chicken.compiler.support#sort-symbols" 
o|inlining procedure: k12007 
o|inlining procedure: k12082 
o|contracted procedure: "(support.scm:857) g26732680" 
o|inlining procedure: k12082 
o|inlining procedure: k12109 
o|inlining procedure: k12124 
o|inlining procedure: k12142 
o|inlining procedure: k12159 
o|inlining procedure: k12179 
o|contracted procedure: "(support.scm:851) chicken.compiler.support#node->sexpr" 
o|inlining procedure: k11843 
o|inlining procedure: k11843 
o|contracted procedure: "(support.scm:813) g25462547" 
o|contracted procedure: "(support.scm:812) g25242525" 
o|contracted procedure: "(support.scm:811) g25212522" 
o|inlining procedure: k12179 
o|inlining procedure: k12209 
o|inlining procedure: k12209 
o|inlining procedure: "(support.scm:847) chicken.compiler.support#fourth" 
o|substituted constant variable: a12223 
o|substituted constant variable: a12225 
o|contracted procedure: "(support.scm:843) g26632664" 
o|inlining procedure: k12159 
o|contracted procedure: "(support.scm:841) g26522653" 
o|inlining procedure: k12142 
o|inlining procedure: k12124 
o|contracted procedure: "(support.scm:836) g26382639" 
o|contracted procedure: "(support.scm:836) g26412642" 
o|inlining procedure: k12109 
o|inlining procedure: k12281 
o|inlining procedure: k12281 
o|contracted procedure: "(support.scm:874) g27242725" 
o|contracted procedure: "(support.scm:877) chicken.compiler.support#sexpr->node" 
o|contracted procedure: "(support.scm:817) g25612562" 
o|inlining procedure: k11914 
o|inlining procedure: k11914 
o|inlining procedure: k12328 
o|inlining procedure: k12328 
o|inlining procedure: k12359 
o|inlining procedure: k12359 
o|inlining procedure: k12374 
o|inlining procedure: k12374 
o|inlining procedure: k12406 
o|inlining procedure: k12406 
o|inlining procedure: k12421 
o|inlining procedure: k12446 
o|inlining procedure: k12446 
o|inlining procedure: k12464 
o|inlining procedure: k12464 
o|contracted procedure: "(support.scm:904) g27852786" 
o|inlining procedure: k12421 
o|inlining procedure: "(support.scm:903) chicken.compiler.support#second" 
o|contracted procedure: "(support.scm:903) g27732774" 
o|inlining procedure: "(support.scm:902) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:902) g27692770" 
o|inlining procedure: k12528 
o|contracted procedure: "(support.scm:915) g27932794" 
o|contracted procedure: "(support.scm:915) g27902791" 
o|inlining procedure: k12528 
o|inlining procedure: k12577 
o|inlining procedure: k12577 
o|contracted procedure: "(support.scm:928) chicken.compiler.support#find" 
o|inlining procedure: k6433 
o|inlining procedure: k6433 
o|propagated global variable: lst585 chicken.compiler.support#foreign-callback-stubs 
o|inlining procedure: "(support.scm:927) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:927) g28282829" 
o|inlining procedure: k12617 
o|inlining procedure: k12617 
o|substituted constant variable: a12633 
o|substituted constant variable: a12635 
o|substituted constant variable: a12637 
o|inlining procedure: k12641 
o|inlining procedure: k12641 
o|substituted constant variable: a12654 
o|substituted constant variable: a12656 
o|substituted constant variable: a12658 
o|substituted constant variable: a12660 
o|contracted procedure: "(support.scm:924) g28152816" 
o|contracted procedure: "(support.scm:923) g28062807" 
o|inlining procedure: k12678 
o|inlining procedure: k12701 
o|inlining procedure: k12724 
o|inlining procedure: k12724 
o|inlining procedure: "(support.scm:946) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:946) g28682869" 
o|contracted procedure: "(support.scm:945) g28642865" 
o|inlining procedure: "(support.scm:944) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:943) g28592860" 
o|inlining procedure: k12701 
o|contracted procedure: "(support.scm:949) g28712872" 
o|substituted constant variable: a12778 
o|substituted constant variable: a12780 
o|contracted procedure: "(support.scm:941) g28552856" 
o|inlining procedure: "(support.scm:939) chicken.compiler.support#second" 
o|inlining procedure: k12678 
o|inlining procedure: "(support.scm:937) chicken.compiler.support#first" 
o|inlining procedure: "(support.scm:936) chicken.compiler.support#third" 
o|contracted procedure: "(support.scm:935) g28392840" 
o|inlining procedure: k12796 
o|inlining procedure: k12796 
o|inlining procedure: k12811 
o|inlining procedure: k12811 
o|inlining procedure: k12837 
o|inlining procedure: k12837 
o|inlining procedure: k12852 
o|inlining procedure: k12852 
o|inlining procedure: k12874 
o|inlining procedure: k12894 
o|inlining procedure: k12894 
o|inlining procedure: k12874 
o|inlining procedure: k12917 
o|contracted procedure: "(support.scm:989) chicken.compiler.support#unhide-variable" 
o|inlining procedure: k17687 
o|inlining procedure: k17687 
o|inlining procedure: k12917 
o|contracted procedure: "(support.scm:988) g29032904" 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#foreign-callback-stub 
o|contracted procedure: "(support.scm:1012) g29452946" 
o|inlining procedure: k13031 
o|inlining procedure: k13031 
o|inlining procedure: k13068 
o|inlining procedure: k13068 
o|inlining procedure: k13116 
o|inlining procedure: k13116 
o|inlining procedure: k13140 
o|inlining procedure: k13140 
o|inlining procedure: k13146 
o|inlining procedure: k13146 
o|inlining procedure: k13199 
o|inlining procedure: k13199 
o|inlining procedure: k13253 
o|inlining procedure: k13253 
o|inlining procedure: k13311 
o|substituted constant variable: tmap2985 
o|substituted constant variable: tmap2985 
o|inlining procedure: k13311 
o|substituted constant variable: a13353 
o|substituted constant variable: a13354 
o|inlining procedure: k13367 
o|inlining procedure: k13367 
o|substituted constant variable: a13396 
o|substituted constant variable: a13397 
o|inlining procedure: k13380 
o|inlining procedure: k13380 
o|inlining procedure: k13459 
o|inlining procedure: k13459 
o|inlining procedure: k13513 
o|inlining procedure: k13513 
o|inlining procedure: k13541 
o|inlining procedure: k13541 
o|inlining procedure: k13565 
o|inlining procedure: k13565 
o|inlining procedure: k13587 
o|inlining procedure: k13587 
o|inlining procedure: k13661 
o|inlining procedure: k13661 
o|inlining procedure: k13702 
o|inlining procedure: k13702 
o|inlining procedure: k13708 
o|inlining procedure: k13708 
o|inlining procedure: k13734 
o|inlining procedure: k13734 
o|substituted constant variable: a13766 
o|substituted constant variable: a13768 
o|substituted constant variable: a13770 
o|substituted constant variable: a13772 
o|substituted constant variable: a13774 
o|substituted constant variable: a13776 
o|substituted constant variable: a13778 
o|substituted constant variable: a13783 
o|substituted constant variable: a13785 
o|inlining procedure: k13789 
o|inlining procedure: k13789 
o|substituted constant variable: a13802 
o|substituted constant variable: a13804 
o|substituted constant variable: a13806 
o|substituted constant variable: a13808 
o|substituted constant variable: a13816 
o|inlining procedure: k13820 
o|inlining procedure: k13820 
o|substituted constant variable: a13827 
o|substituted constant variable: a13829 
o|substituted constant variable: a13831 
o|inlining procedure: k13835 
o|inlining procedure: k13835 
o|substituted constant variable: a13848 
o|substituted constant variable: a13850 
o|substituted constant variable: a13852 
o|substituted constant variable: a13854 
o|substituted constant variable: a13856 
o|inlining procedure: k13860 
o|inlining procedure: k13860 
o|substituted constant variable: a13867 
o|substituted constant variable: a13869 
o|substituted constant variable: a13871 
o|inlining procedure: k13875 
o|inlining procedure: k13875 
o|inlining procedure: k13887 
o|inlining procedure: k13887 
o|substituted constant variable: a13900 
o|substituted constant variable: a13902 
o|substituted constant variable: a13904 
o|substituted constant variable: a13906 
o|substituted constant variable: a13908 
o|substituted constant variable: a13910 
o|inlining procedure: k13914 
o|inlining procedure: k13914 
o|inlining procedure: k13926 
o|inlining procedure: k13926 
o|substituted constant variable: a13939 
o|substituted constant variable: a13941 
o|substituted constant variable: a13943 
o|substituted constant variable: a13945 
o|substituted constant variable: a13947 
o|substituted constant variable: a13949 
o|inlining procedure: k13953 
o|inlining procedure: k13953 
o|inlining procedure: k13965 
o|inlining procedure: k13965 
o|inlining procedure: k13977 
o|inlining procedure: k13977 
o|inlining procedure: k13989 
o|inlining procedure: k13989 
o|substituted constant variable: a14002 
o|substituted constant variable: a14004 
o|substituted constant variable: a14006 
o|substituted constant variable: a14008 
o|substituted constant variable: a14010 
o|substituted constant variable: a14012 
o|substituted constant variable: a14014 
o|substituted constant variable: a14016 
o|substituted constant variable: a14018 
o|substituted constant variable: a14020 
o|inlining procedure: k14024 
o|inlining procedure: k14024 
o|inlining procedure: k14036 
o|inlining procedure: k14036 
o|inlining procedure: k14048 
o|inlining procedure: k14048 
o|inlining procedure: k14060 
o|inlining procedure: k14060 
o|substituted constant variable: a14073 
o|substituted constant variable: a14075 
o|substituted constant variable: a14077 
o|substituted constant variable: a14079 
o|substituted constant variable: a14081 
o|substituted constant variable: a14083 
o|substituted constant variable: a14085 
o|substituted constant variable: a14087 
o|substituted constant variable: a14089 
o|substituted constant variable: a14091 
o|substituted constant variable: a14093 
o|substituted constant variable: a14095 
o|substituted constant variable: a14100 
o|substituted constant variable: a14102 
o|substituted constant variable: a14107 
o|substituted constant variable: a14109 
o|inlining procedure: k14113 
o|inlining procedure: k14113 
o|substituted constant variable: a14120 
o|substituted constant variable: a14122 
o|substituted constant variable: a14124 
o|inlining procedure: k14128 
o|inlining procedure: k14128 
o|inlining procedure: k14140 
o|inlining procedure: k14140 
o|substituted constant variable: a14153 
o|substituted constant variable: a14155 
o|substituted constant variable: a14157 
o|substituted constant variable: a14159 
o|substituted constant variable: a14161 
o|substituted constant variable: a14163 
o|substituted constant variable: a14168 
o|substituted constant variable: a14170 
o|inlining procedure: k14183 
o|inlining procedure: k14195 
o|inlining procedure: k14195 
o|inlining procedure: k14183 
o|inlining procedure: k14204 
o|inlining procedure: k14216 
o|inlining procedure: k14216 
o|inlining procedure: k14204 
o|inlining procedure: k14228 
o|inlining procedure: k14228 
o|inlining procedure: k14243 
o|inlining procedure: k14243 
o|inlining procedure: k14261 
o|inlining procedure: k14261 
o|removed unused formal parameters: (t3344) 
o|inlining procedure: k14303 
o|inlining procedure: k14303 
o|inlining procedure: k14324 
o|inlining procedure: k14324 
o|inlining procedure: k14348 
o|inlining procedure: k14348 
o|inlining procedure: k14378 
o|inlining procedure: k14397 
o|inlining procedure: k14397 
o|removed unused parameter to known procedure: t3344 "(support.scm:1257) err3343" 
o|substituted constant variable: a14423 
o|substituted constant variable: a14425 
o|inlining procedure: k14429 
o|inlining procedure: k14429 
o|inlining procedure: k14441 
o|inlining procedure: k14441 
o|inlining procedure: k14453 
o|inlining procedure: k14453 
o|inlining procedure: k14465 
o|inlining procedure: k14465 
o|substituted constant variable: a14472 
o|substituted constant variable: a14474 
o|substituted constant variable: a14476 
o|substituted constant variable: a14478 
o|substituted constant variable: a14480 
o|substituted constant variable: a14482 
o|substituted constant variable: a14484 
o|substituted constant variable: a14486 
o|substituted constant variable: a14488 
o|inlining procedure: k14378 
o|removed unused parameter to known procedure: t3344 "(support.scm:1258) err3343" 
o|inlining procedure: k14501 
o|inlining procedure: k14501 
o|substituted constant variable: a14514 
o|substituted constant variable: a14516 
o|substituted constant variable: a14518 
o|substituted constant variable: a14520 
o|inlining procedure: k14524 
o|inlining procedure: k14524 
o|substituted constant variable: a14531 
o|substituted constant variable: a14533 
o|substituted constant variable: a14535 
o|inlining procedure: k14539 
o|inlining procedure: k14539 
o|inlining procedure: k14551 
o|inlining procedure: k14551 
o|substituted constant variable: a14564 
o|substituted constant variable: a14566 
o|substituted constant variable: a14568 
o|substituted constant variable: a14570 
o|substituted constant variable: a14572 
o|substituted constant variable: a14574 
o|inlining procedure: k14578 
o|inlining procedure: k14578 
o|inlining procedure: k14590 
o|inlining procedure: k14590 
o|inlining procedure: k14602 
o|inlining procedure: k14602 
o|inlining procedure: k14614 
o|inlining procedure: k14614 
o|inlining procedure: k14626 
o|inlining procedure: k14626 
o|substituted constant variable: a14639 
o|substituted constant variable: a14641 
o|substituted constant variable: a14643 
o|substituted constant variable: a14645 
o|substituted constant variable: a14647 
o|substituted constant variable: a14649 
o|substituted constant variable: a14651 
o|substituted constant variable: a14653 
o|substituted constant variable: a14655 
o|substituted constant variable: a14657 
o|substituted constant variable: a14659 
o|substituted constant variable: a14661 
o|inlining procedure: k14665 
o|inlining procedure: k14665 
o|inlining procedure: k14677 
o|inlining procedure: k14677 
o|inlining procedure: k14689 
o|inlining procedure: k14689 
o|inlining procedure: k14701 
o|inlining procedure: k14701 
o|inlining procedure: k14713 
o|inlining procedure: k14713 
o|inlining procedure: k14725 
o|inlining procedure: k14725 
o|substituted constant variable: a14732 
o|substituted constant variable: a14734 
o|substituted constant variable: a14736 
o|substituted constant variable: a14738 
o|substituted constant variable: a14740 
o|substituted constant variable: a14742 
o|substituted constant variable: a14744 
o|substituted constant variable: a14746 
o|substituted constant variable: a14748 
o|substituted constant variable: a14750 
o|substituted constant variable: a14752 
o|substituted constant variable: a14754 
o|substituted constant variable: a14756 
o|inlining procedure: k14778 
o|inlining procedure: k14778 
o|inlining procedure: k14805 
o|inlining procedure: k14805 
o|inlining procedure: k14827 
o|inlining procedure: k14827 
o|inlining procedure: "(support.scm:1285) err3495" 
o|substituted constant variable: a14856 
o|inlining procedure: k14860 
o|inlining procedure: k14860 
o|inlining procedure: k14872 
o|inlining procedure: k14872 
o|inlining procedure: k14884 
o|inlining procedure: k14884 
o|inlining procedure: k14896 
o|inlining procedure: k14896 
o|substituted constant variable: a14903 
o|substituted constant variable: a14905 
o|substituted constant variable: a14907 
o|substituted constant variable: a14909 
o|substituted constant variable: a14911 
o|substituted constant variable: a14913 
o|substituted constant variable: a14915 
o|substituted constant variable: a14917 
o|substituted constant variable: a14919 
o|inlining procedure: "(support.scm:1286) err3495" 
o|inlining procedure: k14932 
o|inlining procedure: k14932 
o|inlining procedure: k14944 
o|inlining procedure: k14944 
o|substituted constant variable: a14951 
o|substituted constant variable: a14953 
o|substituted constant variable: a14955 
o|substituted constant variable: a14957 
o|substituted constant variable: a14959 
o|inlining procedure: k14963 
o|inlining procedure: k14963 
o|inlining procedure: k14975 
o|inlining procedure: k14975 
o|inlining procedure: k14987 
o|inlining procedure: k14987 
o|inlining procedure: k14999 
o|inlining procedure: k14999 
o|inlining procedure: k15011 
o|inlining procedure: k15011 
o|inlining procedure: k15023 
o|inlining procedure: k15023 
o|inlining procedure: k15035 
o|inlining procedure: k15035 
o|inlining procedure: k15047 
o|inlining procedure: k15047 
o|inlining procedure: k15059 
o|inlining procedure: k15059 
o|inlining procedure: k15071 
o|inlining procedure: k15071 
o|inlining procedure: k15083 
o|inlining procedure: k15083 
o|inlining procedure: k15095 
o|inlining procedure: k15095 
o|inlining procedure: k15107 
o|inlining procedure: k15107 
o|inlining procedure: k15119 
o|inlining procedure: k15119 
o|inlining procedure: k15131 
o|inlining procedure: k15131 
o|substituted constant variable: a15144 
o|substituted constant variable: a15146 
o|substituted constant variable: a15148 
o|substituted constant variable: a15150 
o|substituted constant variable: a15152 
o|substituted constant variable: a15154 
o|substituted constant variable: a15156 
o|substituted constant variable: a15158 
o|substituted constant variable: a15160 
o|substituted constant variable: a15162 
o|substituted constant variable: a15164 
o|substituted constant variable: a15166 
o|substituted constant variable: a15168 
o|substituted constant variable: a15170 
o|substituted constant variable: a15172 
o|substituted constant variable: a15174 
o|substituted constant variable: a15176 
o|substituted constant variable: a15178 
o|substituted constant variable: a15180 
o|substituted constant variable: a15182 
o|substituted constant variable: a15184 
o|substituted constant variable: a15186 
o|substituted constant variable: a15188 
o|substituted constant variable: a15190 
o|substituted constant variable: a15192 
o|substituted constant variable: a15194 
o|substituted constant variable: a15196 
o|substituted constant variable: a15198 
o|substituted constant variable: a15200 
o|substituted constant variable: a15202 
o|substituted constant variable: a15204 
o|substituted constant variable: a15206 
o|inlining procedure: k15219 
o|inlining procedure: k15219 
o|inlining procedure: k15248 
o|inlining procedure: k15248 
o|inlining procedure: k15280 
o|inlining procedure: k15280 
o|inlining procedure: k15310 
o|inlining procedure: k15310 
o|inlining procedure: k15329 
o|inlining procedure: k15329 
o|inlining procedure: k15351 
o|inlining procedure: k15351 
o|substituted constant variable: a15416 
o|substituted constant variable: a15421 
o|substituted constant variable: a15423 
o|substituted constant variable: a15424 
o|inlining procedure: k15432 
o|substituted constant variable: a15442 
o|inlining procedure: k15432 
o|substituted constant variable: a15443 
o|substituted constant variable: a15453 
o|substituted constant variable: a15455 
o|substituted constant variable: a15457 
o|substituted constant variable: a15462 
o|substituted constant variable: a15464 
o|substituted constant variable: a15469 
o|substituted constant variable: a15471 
o|substituted constant variable: a15473 
o|substituted constant variable: a15478 
o|substituted constant variable: a15480 
o|inlining procedure: k15484 
o|inlining procedure: k15484 
o|inlining procedure: k15502 
o|inlining procedure: k15502 
o|inlining procedure: k15520 
o|substituted constant variable: a15536 
o|inlining procedure: k15520 
o|inlining procedure: k15546 
o|substituted constant variable: a15559 
o|inlining procedure: k15546 
o|inlining procedure: k15566 
o|substituted constant variable: a15579 
o|inlining procedure: k15566 
o|inlining procedure: k15586 
o|substituted constant variable: a15612 
o|inlining procedure: k15586 
o|inlining procedure: k15619 
o|inlining procedure: k15619 
o|inlining procedure: k15631 
o|inlining procedure: k15631 
o|inlining procedure: k15643 
o|inlining procedure: k15643 
o|inlining procedure: k15655 
o|inlining procedure: k15655 
o|inlining procedure: k15667 
o|inlining procedure: k15667 
o|inlining procedure: k15682 
o|inlining procedure: k15682 
o|inlining procedure: k15700 
o|inlining procedure: k15700 
o|inlining procedure: k15706 
o|inlining procedure: k15706 
o|inlining procedure: k15724 
o|inlining procedure: k15724 
o|inlining procedure: k15739 
o|inlining procedure: k15755 
o|inlining procedure: k15755 
o|inlining procedure: k15761 
o|inlining procedure: k15761 
o|inlining procedure: k15780 
o|inlining procedure: k15780 
o|substituted constant variable: a15799 
o|substituted constant variable: a15801 
o|substituted constant variable: a15803 
o|substituted constant variable: a15805 
o|inlining procedure: k15809 
o|inlining procedure: k15809 
o|substituted constant variable: a15822 
o|substituted constant variable: a15824 
o|substituted constant variable: a15826 
o|substituted constant variable: a15828 
o|inlining procedure: k15739 
o|substituted constant variable: a15830 
o|inlining procedure: k15834 
o|inlining procedure: k15834 
o|substituted constant variable: a15841 
o|substituted constant variable: a15843 
o|substituted constant variable: a15845 
o|substituted constant variable: a15850 
o|substituted constant variable: a15852 
o|inlining procedure: k15856 
o|inlining procedure: k15856 
o|substituted constant variable: a15869 
o|substituted constant variable: a15871 
o|substituted constant variable: a15873 
o|substituted constant variable: a15875 
o|substituted constant variable: a15877 
o|substituted constant variable: a15879 
o|inlining procedure: k15883 
o|inlining procedure: k15883 
o|inlining procedure: k15895 
o|inlining procedure: k15895 
o|inlining procedure: k15907 
o|inlining procedure: k15907 
o|inlining procedure: k15919 
o|inlining procedure: k15919 
o|substituted constant variable: a15926 
o|substituted constant variable: a15928 
o|substituted constant variable: a15930 
o|substituted constant variable: a15932 
o|substituted constant variable: a15934 
o|substituted constant variable: a15936 
o|substituted constant variable: a15938 
o|substituted constant variable: a15940 
o|substituted constant variable: a15942 
o|substituted constant variable: a15944 
o|substituted constant variable: a15946 
o|substituted constant variable: a15948 
o|substituted constant variable: a15950 
o|substituted constant variable: a15952 
o|substituted constant variable: a15954 
o|substituted constant variable: a15956 
o|substituted constant variable: a15958 
o|substituted constant variable: a15960 
o|substituted constant variable: a15962 
o|inlining procedure: k15966 
o|inlining procedure: k15966 
o|inlining procedure: k15978 
o|inlining procedure: k15978 
o|inlining procedure: k15990 
o|inlining procedure: k15990 
o|inlining procedure: k16002 
o|inlining procedure: k16002 
o|substituted constant variable: a16015 
o|substituted constant variable: a16017 
o|substituted constant variable: a16019 
o|substituted constant variable: a16021 
o|substituted constant variable: a16023 
o|substituted constant variable: a16025 
o|substituted constant variable: a16027 
o|substituted constant variable: a16029 
o|substituted constant variable: a16031 
o|substituted constant variable: a16033 
o|substituted constant variable: a16035 
o|substituted constant variable: a16037 
o|substituted constant variable: a16039 
o|substituted constant variable: a16041 
o|substituted constant variable: a16046 
o|substituted constant variable: a16048 
o|substituted constant variable: a16053 
o|substituted constant variable: a16055 
o|inlining procedure: k16059 
o|inlining procedure: k16059 
o|inlining procedure: k16071 
o|inlining procedure: k16071 
o|inlining procedure: k16083 
o|inlining procedure: k16083 
o|substituted constant variable: a16096 
o|substituted constant variable: a16098 
o|substituted constant variable: a16100 
o|substituted constant variable: a16102 
o|substituted constant variable: a16104 
o|substituted constant variable: a16106 
o|substituted constant variable: a16108 
o|substituted constant variable: a16110 
o|substituted constant variable: a16115 
o|substituted constant variable: a16117 
o|substituted constant variable: a16119 
o|inlining procedure: k16120 
o|inlining procedure: k16120 
o|inlining procedure: k16160 
o|inlining procedure: k16184 
o|inlining procedure: k16184 
o|inlining procedure: "(support.scm:1415) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:1415) g38983899" 
o|inlining procedure: k16160 
o|inlining procedure: k16248 
o|inlining procedure: k16248 
o|inlining procedure: k16271 
o|inlining procedure: k16271 
o|substituted constant variable: a16278 
o|substituted constant variable: a16280 
o|substituted constant variable: a16282 
o|substituted constant variable: a16287 
o|substituted constant variable: a16289 
o|contracted procedure: "(support.scm:1413) g38913892" 
o|contracted procedure: "(support.scm:1412) g38823883" 
o|inlining procedure: k16320 
o|inlining procedure: k16320 
o|inlining procedure: k16338 
o|inlining procedure: k16338 
o|consed rest parameter at call site: "(support.scm:1440) chicken.compiler.support#lset-adjoin/eq?" 2 
o|consed rest parameter at call site: "(support.scm:1438) chicken.compiler.support#lset-adjoin/eq?" 2 
o|inlining procedure: "(support.scm:1436) chicken.compiler.support#first" 
o|inlining procedure: k16358 
o|consed rest parameter at call site: "(support.scm:1443) chicken.compiler.support#lset-adjoin/eq?" 2 
o|inlining procedure: "(support.scm:1442) chicken.compiler.support#first" 
o|inlining procedure: k16358 
o|inlining procedure: "(support.scm:1447) chicken.compiler.support#second" 
o|inlining procedure: "(support.scm:1446) chicken.compiler.support#first" 
o|inlining procedure: k16408 
o|inlining procedure: "(support.scm:1452) chicken.compiler.support#first" 
o|inlining procedure: "(support.scm:1450) chicken.compiler.support#third" 
o|inlining procedure: k16408 
o|substituted constant variable: a16439 
o|substituted constant variable: a16441 
o|substituted constant variable: a16443 
o|substituted constant variable: a16445 
o|inlining procedure: k16449 
o|inlining procedure: k16449 
o|inlining procedure: k16461 
o|inlining procedure: k16461 
o|substituted constant variable: a16468 
o|substituted constant variable: a16470 
o|substituted constant variable: a16472 
o|substituted constant variable: a16474 
o|substituted constant variable: a16476 
o|contracted procedure: "(support.scm:1433) g39683969" 
o|contracted procedure: "(support.scm:1432) g39593960" 
o|contracted procedure: "(support.scm:1431) g39563957" 
o|inlining procedure: k16494 
o|inlining procedure: k16494 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#block-variable-literal 
o|substituted constant variable: a16553 
o|substituted constant variable: a16554 
o|inlining procedure: k16576 
o|inlining procedure: k16576 
o|inlining procedure: k16618 
o|inlining procedure: k16618 
o|inlining procedure: k16630 
o|inlining procedure: k16630 
o|inlining procedure: k16660 
o|inlining procedure: k16660 
o|inlining procedure: k16683 
o|inlining procedure: k16683 
o|substituted constant variable: chicken.compiler.support#real-name-max-depth 
o|inlining procedure: k16735 
o|inlining procedure: k16735 
o|propagated global variable: out40894092 ##sys#standard-output 
o|substituted constant variable: a16751 
o|substituted constant variable: a16752 
o|propagated global variable: out40894092 ##sys#standard-output 
o|inlining procedure: k16768 
o|substituted constant variable: a16792 
o|inlining procedure: k16768 
o|inlining procedure: k16803 
o|inlining procedure: k16803 
o|inlining procedure: k16818 
o|inlining procedure: k16818 
o|inlining procedure: k16836 
o|inlining procedure: k16836 
o|inlining procedure: k16839 
o|inlining procedure: k16839 
o|inlining procedure: "(support.scm:1557) chicken.compiler.support#second" 
o|inlining procedure: k16896 
o|inlining procedure: k16917 
o|inlining procedure: k16917 
o|substituted constant variable: a16945 
o|substituted constant variable: a16958 
o|inlining procedure: k16896 
o|inlining procedure: k17029 
o|contracted procedure: "(support.scm:1569) g41624171" 
o|inlining procedure: k17029 
o|inlining procedure: k17063 
o|contracted procedure: "(support.scm:1568) g41314140" 
o|inlining procedure: "(support.scm:1568) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:1568) g41434144" 
o|inlining procedure: k17063 
o|contracted procedure: "(support.scm:1586) g42064207" 
o|inlining procedure: k17112 
o|inlining procedure: k17149 
o|inlining procedure: k17149 
o|contracted procedure: "(support.scm:1589) g42174218" 
o|inlining procedure: "(support.scm:1588) chicken.compiler.support#first" 
o|contracted procedure: "(support.scm:1588) g42134214" 
o|inlining procedure: k17112 
o|contracted procedure: "(support.scm:1587) g42094210" 
o|inlining procedure: k17210 
o|inlining procedure: k17210 
o|inlining procedure: k17223 
o|inlining procedure: k17223 
o|substituted constant variable: a17257 
o|merged explicitly consed rest parameter: args42454251 
o|consed rest parameter at call site: tmp25265 1 
o|inlining procedure: k17279 
o|inlining procedure: k17279 
o|inlining procedure: k17298 
o|inlining procedure: "(support.scm:1617) getsize4235" 
o|inlining procedure: k17298 
o|inlining procedure: "(support.scm:1619) getsize4235" 
o|substituted constant variable: a17370 
o|propagated global variable: out42814294 ##sys#standard-output 
o|substituted constant variable: a17372 
o|substituted constant variable: a17373 
o|propagated global variable: out43174320 ##sys#standard-output 
o|substituted constant variable: a17416 
o|substituted constant variable: a17417 
o|inlining procedure: k17406 
o|inlining procedure: k17433 
o|propagated global variable: out43264329 ##sys#standard-output 
o|substituted constant variable: a17440 
o|substituted constant variable: a17441 
o|inlining procedure: k17433 
o|propagated global variable: out43264329 ##sys#standard-output 
o|propagated global variable: out43174320 ##sys#standard-output 
o|inlining procedure: k17406 
o|inlining procedure: k17466 
o|inlining procedure: k17466 
o|propagated global variable: out42814294 ##sys#standard-output 
o|contracted procedure: "(support.scm:1633) g42784279" 
o|contracted procedure: "(support.scm:1632) g42754276" 
o|contracted procedure: "(support.scm:1631) g42724273" 
o|inlining procedure: k17495 
o|contracted procedure: "(support.scm:1660) chicken.compiler.support#scan-sharp-greater-string" 
o|inlining procedure: k17532 
o|inlining procedure: k17532 
o|substituted constant variable: a17545 
o|substituted constant variable: a17556 
o|inlining procedure: k17552 
o|substituted constant variable: a17578 
o|inlining procedure: k17552 
o|inlining procedure: k17495 
o|inlining procedure: k17589 
o|inlining procedure: k17604 
o|inlining procedure: k17604 
o|inlining procedure: k17589 
o|inlining procedure: k17613 
o|inlining procedure: k17613 
o|contracted procedure: "(support.scm:1703) g43794380" 
o|contracted procedure: "(support.scm:1706) g43954396" 
o|inlining procedure: k17702 
o|inlining procedure: k17702 
o|substituted constant variable: a17718 
o|substituted constant variable: a17720 
o|contracted procedure: "(support.scm:1730) g44464447" 
o|contracted procedure: "(support.scm:1732) g44574458" 
o|contracted procedure: "(support.scm:1733) g44684469" 
o|inlining procedure: k17781 
o|inlining procedure: k17824 
o|contracted procedure: "(support.scm:1741) g44914498" 
o|inlining procedure: k17824 
o|substituted constant variable: a17849 
o|substituted constant variable: a17850 
o|inlining procedure: k17781 
o|substituted constant variable: chicken.compiler.support#constant678 
o|substituted constant variable: a17917 
o|substituted constant variable: a17918 
o|contracted procedure: "(support.scm:462) g12701271" 
o|contracted procedure: "(support.scm:462) g12671268" 
o|substituted constant variable: chicken.compiler.support#node 
o|replaced variables: 3968 
o|removed binding forms: 694 
o|substituted constant variable: r541217952 
o|substituted constant variable: r571317956 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#first 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#second 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#third 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#fourth 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#filter 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#constant678 
o|propagated global variable: out715718 ##sys#standard-output 
o|propagated global variable: out730733 chicken.compiler.support#collected-debugging-output 
o|substituted constant variable: r671817986 
o|inlining procedure: k6732 
o|substituted constant variable: r671817987 
o|inlining procedure: k6741 
o|propagated global variable: out766769 chicken.compiler.support#collected-debugging-output 
o|converted assignments to bindings: (collect751) 
o|substituted constant variable: r704318000 
o|substituted constant variable: r711818004 
o|substituted constant variable: r716518006 
o|substituted constant variable: r716518007 
o|substituted constant variable: r720218013 
o|substituted constant variable: r765318057 
o|substituted constant variable: r769118058 
o|substituted constant variable: r780918068 
o|substituted constant variable: r808218079 
o|substituted constant variable: r596618084 
o|substituted constant variable: r810018085 
o|substituted constant variable: r821618093 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#node 
o|substituted constant variable: c1286 
o|substituted constant variable: s1288 
o|substituted constant variable: c1293 
o|substituted constant variable: s1295 
o|substituted constant variable: p1320 
o|substituted constant variable: r846318107 
o|substituted constant variable: c1356 
o|substituted constant variable: c1391 
o|substituted constant variable: c1396 
o|substituted constant variable: c1409 
o|substituted constant variable: c1414 
o|substituted constant variable: p1415 
o|substituted constant variable: s1416 
o|substituted constant variable: c1419 
o|substituted constant variable: s1497 
o|substituted constant variable: c1500 
o|substituted constant variable: s1502 
o|substituted constant variable: c1508 
o|substituted constant variable: c1540 
o|substituted constant variable: c1588 
o|substituted constant variable: c1621 
o|substituted constant variable: mark1631 
o|substituted constant variable: c1665 
o|substituted constant variable: c2021 
o|substituted constant variable: p2022 
o|substituted constant variable: c2122 
o|substituted constant variable: c2127 
o|substituted constant variable: c2132 
o|substituted constant variable: c2138 
o|substituted constant variable: c2404 
o|substituted constant variable: c2416 
o|removed side-effect free assignment to unused variable: rename2182 
o|substituted constant variable: s2210 
o|substituted constant variable: c2215 
o|substituted constant variable: c2224 
o|substituted constant variable: c2295 
o|substituted constant variable: r1106118406 
o|substituted constant variable: r1106118406 
o|substituted constant variable: c2451 
o|substituted constant variable: c2459 
o|substituted constant variable: c2465 
o|substituted constant variable: c2470 
o|substituted constant variable: c2475 
o|substituted constant variable: r1218018472 
o|substituted constant variable: r1221018473 
o|substituted constant variable: mark2666 
o|substituted constant variable: r1216018480 
o|substituted constant variable: r1214318481 
o|substituted constant variable: r1212518482 
o|substituted constant variable: mark2644 
o|converted assignments to bindings: (uses-foreign-stubs?2600) 
o|substituted constant variable: mark2731 
o|substituted constant variable: r1237518494 
o|substituted constant variable: r1246518500 
o|substituted constant variable: r1242218502 
o|substituted constant variable: r1252918514 
o|substituted constant variable: r1257818515 
o|substituted constant variable: r643418517 
o|substituted constant variable: r1261818525 
o|substituted constant variable: r1272518531 
o|substituted constant variable: r1267918548 
o|substituted constant variable: r1281218562 
o|substituted constant variable: r1285318566 
o|substituted constant variable: r1289518570 
o|substituted constant variable: r1289518570 
o|substituted constant variable: mark2952 
o|substituted constant variable: r1306918581 
o|substituted constant variable: r1306918581 
o|substituted constant variable: r1419618657 
o|substituted constant variable: r1418418658 
o|substituted constant variable: r1421718661 
o|substituted constant variable: r1420518662 
o|substituted constant variable: r1430418669 
o|converted assignments to bindings: (err3343) 
o|removed side-effect free assignment to unused variable: err3495 
o|substituted constant variable: r1543318788 
o|substituted constant variable: r1548518789 
o|substituted constant variable: r1550318791 
o|substituted constant variable: r1562018801 
o|substituted constant variable: r1563218803 
o|substituted constant variable: r1564418805 
o|substituted constant variable: r1565618807 
o|substituted constant variable: r1566818809 
o|substituted constant variable: r1570118813 
o|substituted constant variable: r1570118814 
o|substituted constant variable: r1570718815 
o|substituted constant variable: r1572518817 
o|substituted constant variable: r1575618820 
o|substituted constant variable: r1575618821 
o|substituted constant variable: r1578118825 
o|substituted constant variable: r1574018828 
o|substituted constant variable: r1612118856 
o|substituted constant variable: r1632118870 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#real-name-max-depth 
o|converted assignments to bindings: (resolve4058) 
o|substituted constant variable: r1673618927 
o|propagated global variable: out40894092 ##sys#standard-output 
o|substituted constant variable: r1681918933 
o|substituted constant variable: r1684018937 
o|substituted constant variable: r1715018958 
o|converted assignments to bindings: (constant-node?4204) 
o|removed side-effect free assignment to unused variable: getsize4235 
o|substituted constant variable: r1722418968 
o|contracted procedure: "(support.scm:1623) chicken.compiler.support#list-tabulate" 
o|substituted constant variable: r632117968 
o|propagated global variable: out42814294 ##sys#standard-output 
o|propagated global variable: out43174320 ##sys#standard-output 
o|propagated global variable: out43264329 ##sys#standard-output 
o|substituted constant variable: r1759019000 
o|substituted constant variable: r1761419002 
o|substituted constant variable: mark4386 
o|substituted constant variable: mark4402 
o|substituted constant variable: r1770319005 
o|substituted constant variable: mark4449 
o|substituted constant variable: mark4460 
o|substituted constant variable: mark4471 
o|substituted constant variable: r1778219010 
o|simplifications: ((let . 5)) 
o|replaced variables: 638 
o|removed binding forms: 3343 
o|substituted constant variable: r67181798619038 
o|substituted constant variable: r67181798719040 
o|inlining procedure: "(support.scm:393) chicken.compiler.support#alist-cons" 
o|inlining procedure: "(support.scm:433) chicken.compiler.support#alist-cons" 
o|inlining procedure: "(support.scm:441) chicken.compiler.support#alist-cons" 
o|removed call to pure procedure with unused result: "(support.scm:640) ##sys#slot" 
o|inlining procedure: "(support.scm:705) chicken.compiler.support#alist-cons" 
o|inlining procedure: k12289 
o|inlining procedure: "(support.scm:889) chicken.compiler.support#alist-cons" 
o|inlining procedure: k12623 
o|inlining procedure: k13008 
o|inlining procedure: k13756 
o|inlining procedure: k14225 
o|inlining procedure: k14240 
o|inlining procedure: k16367 
o|inlining procedure: k16367 
o|inlining procedure: k16833 
o|inlining procedure: k16833 
o|inlining procedure: "(support.scm:1611) fits?4236" 
o|inlining procedure: "(support.scm:1615) fits?4236" 
o|inlining procedure: "(support.scm:1617) fits?4236" 
o|inlining procedure: "(support.scm:1620) fits?4236" 
o|converted assignments to bindings: (fits?4236) 
o|inlining procedure: k17639 
o|inlining procedure: k17659 
o|inlining procedure: k17724 
o|inlining procedure: k17876 
o|simplifications: ((let . 1)) 
o|replaced variables: 3 
o|removed binding forms: 759 
o|removed side-effect free assignment to unused variable: chicken.compiler.support#alist-cons 
o|inlining procedure: k8868 
o|contracted procedure: k10720 
o|substituted constant variable: r1229019478 
o|contracted procedure: k12922 
o|substituted constant variable: r1300919506 
o|substituted constant variable: r1422619510 
o|substituted constant variable: r1422619510 
o|substituted constant variable: r1424119513 
o|substituted constant variable: r1424119513 
o|substituted constant variable: r1683419534 
o|substituted constant variable: r1683419534 
o|substituted constant variable: r1683419537 
o|substituted constant variable: r1683419537 
o|contracted procedure: k17305 
o|contracted procedure: k17308 
o|substituted constant variable: r1764019567 
o|substituted constant variable: r1766019568 
o|substituted constant variable: r1772519569 
o|simplifications: ((let . 1)) 
o|replaced variables: 28 
o|removed binding forms: 23 
o|removed conditional forms: 4 
o|substituted constant variable: r886919624 
o|removed binding forms: 39 
o|removed conditional forms: 1 
o|removed binding forms: 1 
o|simplifications: ((if . 107) (let . 51) (##core#call . 1493)) 
o|  call simplifications:
o|    chicken.base#bignum?
o|    scheme#char=?
o|    scheme#read-char	3
o|    ##sys#size
o|    chicken.fixnum#fx>	2
o|    scheme#write-char	6
o|    chicken.base#flonum?
o|    scheme#procedure?
o|    scheme#string-length	3
o|    chicken.fixnum#fx+	3
o|    scheme#list?	5
o|    scheme#vector-ref	6
o|    scheme#vector	2
o|    scheme#<
o|    scheme#>	2
o|    scheme#<=
o|    scheme#values	2
o|    scheme#-
o|    ##sys#call-with-values	4
o|    scheme#cddddr
o|    scheme#list-ref	2
o|    scheme#cdddr
o|    scheme#caar	2
o|    scheme#cadddr	4
o|    scheme#caddr	10
o|    scheme#cadr	45
o|    ##sys#check-structure	12
o|    ##sys#block-ref	9
o|    ##sys#structure?	5
o|    ##sys#make-structure	42
o|    scheme#assq	15
o|    scheme#length	8
o|    ##sys#setslot	35
o|    chicken.base#atom?
o|    ##sys#apply	3
o|    ##sys#cons	8
o|    scheme#equal?	3
o|    ##sys#list	139
o|    chicken.base#fixnum?	2
o|    scheme#number?	4
o|    scheme#char?	4
o|    scheme#string?	2
o|    scheme#boolean?	4
o|    chicken.base#bwp-object?	3
o|    scheme#vector?	2
o|    scheme#eq?	368
o|    scheme#eof-object?	7
o|    scheme#member
o|    scheme#cddr	4
o|    scheme#list	65
o|    scheme#string=?	2
o|    ##sys#foreign-fixnum-argument	2
o|    scheme#char-alphabetic?	2
o|    scheme#char-numeric?
o|    scheme#char->integer
o|    chicken.fixnum#fx>=	3
o|    chicken.fixnum#fx<	4
o|    scheme#string->list	3
o|    scheme#list->string
o|    ##sys#check-list	41
o|    ##sys#slot	188
o|    scheme#symbol?	15
o|    scheme#pair?	68
o|    scheme#apply	6
o|    scheme#memq	9
o|    scheme#cdr	20
o|    scheme#null?	47
o|    scheme#not	23
o|    chicken.fixnum#fx<=	7
o|    scheme#car	84
o|    chicken.fixnum#fx-	2
o|    scheme#cons	107
o|contracted procedure: k5414 
o|contracted procedure: k5421 
o|contracted procedure: k5431 
o|contracted procedure: k5678 
o|contracted procedure: k5687 
o|contracted procedure: k5700 
o|contracted procedure: k5715 
o|contracted procedure: k5730 
o|contracted procedure: k5745 
o|contracted procedure: k5756 
o|contracted procedure: k6091 
o|contracted procedure: k6081 
o|contracted procedure: k6140 
o|contracted procedure: k6166 
o|contracted procedure: k6146 
o|contracted procedure: k6160 
o|contracted procedure: k6591 
o|contracted procedure: k6619 
o|contracted procedure: k6655 
o|contracted procedure: k6685 
o|contracted procedure: k6695 
o|contracted procedure: k6699 
o|contracted procedure: k6781 
o|propagated global variable: out766769 chicken.compiler.support#collected-debugging-output 
o|contracted procedure: k6797 
o|contracted procedure: k6807 
o|contracted procedure: k6811 
o|contracted procedure: k6881 
o|contracted procedure: k6899 
o|contracted procedure: k6909 
o|contracted procedure: k6913 
o|contracted procedure: k6952 
o|contracted procedure: k6956 
o|contracted procedure: k6960 
o|contracted procedure: k6974 
o|contracted procedure: k7030 
o|contracted procedure: k7036 
o|contracted procedure: k7045 
o|contracted procedure: k7052 
o|contracted procedure: k7056 
o|contracted procedure: k7072 
o|contracted procedure: k7082 
o|contracted procedure: k7103 
o|contracted procedure: k7120 
o|contracted procedure: k7123 
o|contracted procedure: k7126 
o|contracted procedure: k7132 
o|contracted procedure: k7161 
o|contracted procedure: k7167 
o|contracted procedure: k7183 
o|contracted procedure: k7204 
o|contracted procedure: k7211 
o|contracted procedure: k7214 
o|contracted procedure: k7223 
o|contracted procedure: k7229 
o|contracted procedure: k7249 
o|contracted procedure: k7256 
o|contracted procedure: k7265 
o|contracted procedure: k7280 
o|contracted procedure: k7293 
o|contracted procedure: k7300 
o|contracted procedure: k7309 
o|contracted procedure: k7368 
o|contracted procedure: k7321 
o|contracted procedure: k7364 
o|contracted procedure: k7341 
o|inlining procedure: k7338 
o|inlining procedure: k7338 
o|contracted procedure: k7383 
o|contracted procedure: k7399 
o|contracted procedure: k7460 
o|contracted procedure: k7425 
o|contracted procedure: k7441 
o|contracted procedure: k7457 
o|contracted procedure: k7472 
o|contracted procedure: k7478 
o|contracted procedure: k7484 
o|contracted procedure: k7490 
o|contracted procedure: k7496 
o|contracted procedure: k7502 
o|contracted procedure: k7514 
o|contracted procedure: k7529 
o|contracted procedure: k7540 
o|contracted procedure: k7546 
o|contracted procedure: k7552 
o|contracted procedure: k7558 
o|contracted procedure: k7564 
o|contracted procedure: k7582 
o|contracted procedure: k7588 
o|contracted procedure: k7594 
o|contracted procedure: k7600 
o|contracted procedure: k7606 
o|contracted procedure: k7615 
o|contracted procedure: k7628 
o|contracted procedure: k7634 
o|contracted procedure: k7655 
o|contracted procedure: k7671 
o|contracted procedure: k7693 
o|contracted procedure: k7751 
o|contracted procedure: k7699 
o|contracted procedure: k7707 
o|contracted procedure: k7732 
o|contracted procedure: k7722 
o|contracted procedure: k7811 
o|contracted procedure: k7825 
o|contracted procedure: k7817 
o|contracted procedure: k7843 
o|contracted procedure: k7853 
o|contracted procedure: k7889 
o|contracted procedure: k7895 
o|contracted procedure: k7904 
o|contracted procedure: k7914 
o|contracted procedure: k7918 
o|contracted procedure: k590619334 
o|contracted procedure: k7938 
o|propagated global variable: z38219331 chicken.compiler.support#profile-lambda-list 
o|contracted procedure: k7983 
o|contracted procedure: k7979 
o|contracted procedure: k7951 
o|contracted procedure: k7975 
o|contracted procedure: k7971 
o|contracted procedure: k7955 
o|contracted procedure: k7967 
o|contracted procedure: k7963 
o|contracted procedure: k7959 
o|contracted procedure: k7947 
o|contracted procedure: k8072 
o|contracted procedure: k8064 
o|contracted procedure: k8068 
o|contracted procedure: k8060 
o|contracted procedure: k7993 
o|contracted procedure: k7997 
o|contracted procedure: k8019 
o|contracted procedure: k8031 
o|contracted procedure: k8053 
o|contracted procedure: k8016 
o|contracted procedure: k8006 
o|contracted procedure: k8010 
o|contracted procedure: k8049 
o|contracted procedure: k8034 
o|contracted procedure: k8037 
o|contracted procedure: k8045 
o|propagated global variable: g11641168 chicken.compiler.support#profile-lambda-list 
o|contracted procedure: k8084 
o|contracted procedure: k5956 
o|contracted procedure: k5968 
o|contracted procedure: k5991 
o|contracted procedure: k5999 
o|contracted procedure: k8120 
o|contracted procedure: k8140 
o|contracted procedure: k590619345 
o|contracted procedure: k8136 
o|contracted procedure: k8154 
o|contracted procedure: k8150 
o|contracted procedure: k8166 
o|contracted procedure: k8180 
o|contracted procedure: k8176 
o|contracted procedure: k8191 
o|contracted procedure: k8195 
o|contracted procedure: k590619352 
o|contracted procedure: k8187 
o|contracted procedure: k8206 
o|contracted procedure: k8202 
o|contracted procedure: k8234 
o|contracted procedure: k8243 
o|contracted procedure: k8252 
o|contracted procedure: k8261 
o|contracted procedure: k8270 
o|contracted procedure: k8279 
o|contracted procedure: k8306 
o|contracted procedure: k8321 
o|contracted procedure: k8333 
o|contracted procedure: k8347 
o|contracted procedure: k9507 
o|contracted procedure: k8353 
o|contracted procedure: k9503 
o|contracted procedure: k8362 
o|contracted procedure: k8369 
o|contracted procedure: k8372 
o|contracted procedure: k8386 
o|contracted procedure: k8390 
o|contracted procedure: k8402 
o|contracted procedure: k8405 
o|contracted procedure: k8408 
o|contracted procedure: k8416 
o|contracted procedure: k8424 
o|contracted procedure: k8433 
o|contracted procedure: k8436 
o|contracted procedure: k8459 
o|contracted procedure: k8465 
o|contracted procedure: k8476 
o|contracted procedure: k8479 
o|contracted procedure: k8482 
o|contracted procedure: k8488 
o|contracted procedure: k8511 
o|contracted procedure: k8520 
o|contracted procedure: k8523 
o|contracted procedure: k8526 
o|contracted procedure: k8533 
o|contracted procedure: k8546 
o|contracted procedure: k8549 
o|contracted procedure: k8552 
o|contracted procedure: k8560 
o|contracted procedure: k8568 
o|contracted procedure: k6021 
o|contracted procedure: k6029 
o|contracted procedure: k6041 
o|contracted procedure: k6063 
o|contracted procedure: k6059 
o|contracted procedure: k6044 
o|contracted procedure: k6047 
o|contracted procedure: k6055 
o|contracted procedure: k8577 
o|contracted procedure: k8580 
o|contracted procedure: k8608 
o|contracted procedure: k8592 
o|contracted procedure: k8596 
o|contracted procedure: k8604 
o|contracted procedure: k8614 
o|contracted procedure: k8642 
o|contracted procedure: k8646 
o|contracted procedure: k8626 
o|contracted procedure: k8630 
o|contracted procedure: k8638 
o|contracted procedure: k8652 
o|contracted procedure: k8659 
o|contracted procedure: k8663 
o|contracted procedure: k8672 
o|contracted procedure: k8705 
o|contracted procedure: k8684 
o|contracted procedure: k8701 
o|contracted procedure: k8692 
o|contracted procedure: k8784 
o|contracted procedure: k8715 
o|contracted procedure: k8747 
o|contracted procedure: k8727 
o|contracted procedure: k8735 
o|contracted procedure: k8755 
o|contracted procedure: k8780 
o|contracted procedure: k8764 
o|contracted procedure: k8768 
o|contracted procedure: k8798 
o|contracted procedure: k8801 
o|contracted procedure: k8819 
o|contracted procedure: k8824 
o|contracted procedure: k8836 
o|contracted procedure: k8839 
o|contracted procedure: k8842 
o|contracted procedure: k8850 
o|contracted procedure: k8858 
o|contracted procedure: k8874 
o|contracted procedure: k8868 
o|contracted procedure: k8865 
o|contracted procedure: k8885 
o|contracted procedure: k8952 
o|contracted procedure: k8902 
o|contracted procedure: k8906 
o|contracted procedure: k8911 
o|contracted procedure: k8923 
o|contracted procedure: k8926 
o|contracted procedure: k8929 
o|contracted procedure: k8937 
o|contracted procedure: k8945 
o|contracted procedure: k8958 
o|contracted procedure: k8976 
o|contracted procedure: k8992 
o|contracted procedure: k8988 
o|contracted procedure: k8998 
o|contracted procedure: k9001 
o|contracted procedure: k9063 
o|contracted procedure: k9013 
o|contracted procedure: k9017 
o|contracted procedure: k9022 
o|contracted procedure: k9034 
o|contracted procedure: k9037 
o|contracted procedure: k9040 
o|contracted procedure: k9048 
o|contracted procedure: k9056 
o|contracted procedure: k9069 
o|contracted procedure: k9124 
o|contracted procedure: k9072 
o|contracted procedure: k9120 
o|contracted procedure: k9100 
o|contracted procedure: k9116 
o|contracted procedure: k9104 
o|contracted procedure: k5861 
o|contracted procedure: k9112 
o|contracted procedure: k9108 
o|contracted procedure: k9084 
o|contracted procedure: k9088 
o|contracted procedure: k9096 
o|contracted procedure: k9130 
o|contracted procedure: k9145 
o|contracted procedure: k9149 
o|contracted procedure: k9153 
o|contracted procedure: k9156 
o|contracted procedure: k9159 
o|contracted procedure: k9171 
o|contracted procedure: k9174 
o|contracted procedure: k9177 
o|contracted procedure: k9185 
o|contracted procedure: k9193 
o|contracted procedure: k9202 
o|contracted procedure: k9214 
o|contracted procedure: k9218 
o|contracted procedure: k9222 
o|contracted procedure: k9234 
o|contracted procedure: k9237 
o|contracted procedure: k9240 
o|contracted procedure: k9248 
o|contracted procedure: k9256 
o|contracted procedure: k9283 
o|contracted procedure: k9287 
o|contracted procedure: k9290 
o|contracted procedure: k9302 
o|contracted procedure: k9305 
o|contracted procedure: k9308 
o|contracted procedure: k9316 
o|contracted procedure: k9324 
o|contracted procedure: k9366 
o|contracted procedure: k9372 
o|contracted procedure: k9378 
o|contracted procedure: k9410 
o|contracted procedure: k9458 
o|contracted procedure: k9462 
o|contracted procedure: k9474 
o|contracted procedure: k9477 
o|contracted procedure: k9480 
o|contracted procedure: k9488 
o|contracted procedure: k9496 
o|contracted procedure: k9534 
o|contracted procedure: k9542 
o|contracted procedure: k9550 
o|contracted procedure: k9556 
o|contracted procedure: k9566 
o|contracted procedure: k9569 
o|contracted procedure: k9581 
o|contracted procedure: k9584 
o|contracted procedure: k9587 
o|contracted procedure: k9595 
o|contracted procedure: k9603 
o|contracted procedure: k9612 
o|contracted procedure: k9623 
o|contracted procedure: k9626 
o|contracted procedure: k9619 
o|contracted procedure: k9638 
o|contracted procedure: k9641 
o|contracted procedure: k9644 
o|contracted procedure: k9652 
o|contracted procedure: k9660 
o|contracted procedure: k9669 
o|contracted procedure: k9678 
o|contracted procedure: k9681 
o|contracted procedure: k9687 
o|inlining procedure: k9690 
o|contracted procedure: k9698 
o|inlining procedure: k9690 
o|contracted procedure: k9704 
o|contracted procedure: k9716 
o|contracted procedure: k9723 
o|contracted procedure: k9726 
o|contracted procedure: k9735 
o|contracted procedure: k9738 
o|contracted procedure: k9794 
o|contracted procedure: k9758 
o|contracted procedure: k9784 
o|contracted procedure: k9788 
o|contracted procedure: k9780 
o|contracted procedure: k9761 
o|contracted procedure: k9764 
o|contracted procedure: k9772 
o|contracted procedure: k9776 
o|contracted procedure: k9806 
o|contracted procedure: k9809 
o|contracted procedure: k9812 
o|contracted procedure: k9820 
o|contracted procedure: k9828 
o|contracted procedure: k9837 
o|contracted procedure: k9859 
o|contracted procedure: k9844 
o|contracted procedure: k9848 
o|contracted procedure: k9856 
o|contracted procedure: k9865 
o|contracted procedure: k9872 
o|contracted procedure: k9880 
o|contracted procedure: k9886 
o|contracted procedure: k9893 
o|contracted procedure: k9899 
o|contracted procedure: k9906 
o|contracted procedure: k9918 
o|contracted procedure: k9922 
o|contracted procedure: k9931 
o|contracted procedure: k9937 
o|contracted procedure: k9944 
o|contracted procedure: k9952 
o|contracted procedure: k9971 
o|contracted procedure: k9959 
o|contracted procedure: k9979 
o|contracted procedure: k9983 
o|contracted procedure: k9989 
o|contracted procedure: k9992 
o|contracted procedure: k9995 
o|contracted procedure: k10007 
o|contracted procedure: k10010 
o|contracted procedure: k10013 
o|contracted procedure: k10021 
o|contracted procedure: k10029 
o|contracted procedure: k10038 
o|contracted procedure: k10045 
o|contracted procedure: k10049 
o|contracted procedure: k10052 
o|contracted procedure: k10064 
o|contracted procedure: k10067 
o|contracted procedure: k10070 
o|contracted procedure: k10078 
o|contracted procedure: k10086 
o|contracted procedure: k10095 
o|contracted procedure: k10104 
o|contracted procedure: k10111 
o|contracted procedure: k10133 
o|contracted procedure: k10140 
o|contracted procedure: k10144 
o|contracted procedure: k10148 
o|contracted procedure: k10160 
o|contracted procedure: k10174 
o|contracted procedure: k10178 
o|contracted procedure: k10190 
o|contracted procedure: k10193 
o|contracted procedure: k10196 
o|contracted procedure: k10204 
o|contracted procedure: k10212 
o|contracted procedure: k10219 
o|contracted procedure: k10225 
o|contracted procedure: k10232 
o|contracted procedure: k10235 
o|contracted procedure: k10247 
o|contracted procedure: k10250 
o|contracted procedure: k10253 
o|contracted procedure: k10261 
o|contracted procedure: k10269 
o|contracted procedure: k10283 
o|contracted procedure: k10286 
o|contracted procedure: k10298 
o|contracted procedure: k10301 
o|contracted procedure: k10304 
o|contracted procedure: k10312 
o|contracted procedure: k10320 
o|contracted procedure: k10328 
o|contracted procedure: k10334 
o|contracted procedure: k10375 
o|contracted procedure: k10439 
o|contracted procedure: k10402 
o|contracted procedure: k10417 
o|contracted procedure: k10431 
o|contracted procedure: k10435 
o|contracted procedure: k5472 
o|contracted procedure: k5486 
o|contracted procedure: k5496 
o|contracted procedure: k5490 
o|contracted procedure: k10469 
o|contracted procedure: k10477 
o|contracted procedure: k10502 
o|contracted procedure: k10517 
o|contracted procedure: k10523 
o|contracted procedure: k10535 
o|contracted procedure: k10539 
o|contracted procedure: k10546 
o|contracted procedure: k10567 
o|contracted procedure: k10561 
o|contracted procedure: k10607 
o|contracted procedure: k10587 
o|contracted procedure: k10595 
o|contracted procedure: k10591 
o|contracted procedure: k10639 
o|contracted procedure: k10619 
o|contracted procedure: k10627 
o|contracted procedure: k10623 
o|contracted procedure: k10653 
o|contracted procedure: k10671 
o|contracted procedure: k10681 
o|contracted procedure: k10685 
o|contracted procedure: k11291 
o|contracted procedure: k11299 
o|contracted procedure: k11307 
o|contracted procedure: k11313 
o|contracted procedure: k11342 
o|contracted procedure: k11319 
o|contracted procedure: k11334 
o|contracted procedure: k11338 
o|contracted procedure: k11330 
o|contracted procedure: k11348 
o|contracted procedure: k11413 
o|contracted procedure: k11354 
o|contracted procedure: k11357 
o|contracted procedure: k11360 
o|contracted procedure: k11366 
o|contracted procedure: k11377 
o|contracted procedure: k11393 
o|contracted procedure: k11397 
o|contracted procedure: k11389 
o|contracted procedure: k11419 
o|contracted procedure: k11476 
o|contracted procedure: k11425 
o|contracted procedure: k11436 
o|contracted procedure: k11468 
o|contracted procedure: k11472 
o|contracted procedure: k11464 
o|contracted procedure: k11479 
o|contracted procedure: k11491 
o|contracted procedure: k11501 
o|contracted procedure: k11505 
o|contracted procedure: k10698 
o|contracted procedure: k10701 
o|contracted procedure: k10704 
o|contracted procedure: k10712 
o|contracted procedure: k10775 
o|contracted procedure: k10778 
o|contracted procedure: k10781 
o|contracted procedure: k10801 
o|contracted procedure: k10809 
o|contracted procedure: k10817 
o|contracted procedure: k10823 
o|contracted procedure: k10837 
o|contracted procedure: k10840 
o|contracted procedure: k10862 
o|contracted procedure: k10874 
o|contracted procedure: k10878 
o|contracted procedure: k10886 
o|contracted procedure: k10894 
o|contracted procedure: k10900 
o|contracted procedure: k10903 
o|contracted procedure: k590619443 
o|contracted procedure: k10912 
o|contracted procedure: k10927 
o|contracted procedure: k10931 
o|contracted procedure: k10939 
o|contracted procedure: k10943 
o|contracted procedure: k10949 
o|contracted procedure: k10956 
o|contracted procedure: k10962 
o|contracted procedure: k10973 
o|contracted procedure: k11048 
o|contracted procedure: k11056 
o|contracted procedure: k10991 
o|contracted procedure: k10995 
o|contracted procedure: k11003 
o|contracted procedure: k11015 
o|contracted procedure: k11018 
o|contracted procedure: k11021 
o|contracted procedure: k11029 
o|contracted procedure: k11037 
o|contracted procedure: k11067 
o|contracted procedure: k11070 
o|contracted procedure: k11118 
o|contracted procedure: k11082 
o|contracted procedure: k11108 
o|contracted procedure: k11112 
o|contracted procedure: k11104 
o|contracted procedure: k11085 
o|contracted procedure: k11088 
o|contracted procedure: k11096 
o|contracted procedure: k11100 
o|contracted procedure: k11130 
o|contracted procedure: k11133 
o|contracted procedure: k11136 
o|contracted procedure: k11144 
o|contracted procedure: k11152 
o|contracted procedure: k11171 
o|contracted procedure: k11179 
o|contracted procedure: k11191 
o|contracted procedure: k11194 
o|contracted procedure: k11197 
o|contracted procedure: k11205 
o|contracted procedure: k11213 
o|contracted procedure: k11274 
o|contracted procedure: k11238 
o|contracted procedure: k11264 
o|contracted procedure: k11268 
o|contracted procedure: k11260 
o|contracted procedure: k11241 
o|contracted procedure: k11244 
o|contracted procedure: k11252 
o|contracted procedure: k11256 
o|contracted procedure: k10729 
o|contracted procedure: k10732 
o|contracted procedure: k10744 
o|contracted procedure: k10747 
o|contracted procedure: k10750 
o|contracted procedure: k10758 
o|contracted procedure: k10766 
o|contracted procedure: k11523 
o|contracted procedure: k11535 
o|contracted procedure: k11539 
o|contracted procedure: k11547 
o|contracted procedure: k11553 
o|contracted procedure: k11561 
o|contracted procedure: k11586 
o|contracted procedure: k11590 
o|contracted procedure: k11582 
o|contracted procedure: k11596 
o|contracted procedure: k11608 
o|contracted procedure: k11629 
o|contracted procedure: k11633 
o|contracted procedure: k11625 
o|contracted procedure: k11612 
o|contracted procedure: k11637 
o|contracted procedure: k11643 
o|contracted procedure: k11655 
o|contracted procedure: k11659 
o|contracted procedure: k11667 
o|contracted procedure: k11693 
o|contracted procedure: k11728 
o|contracted procedure: k11737 
o|contracted procedure: k11746 
o|contracted procedure: k11767 
o|contracted procedure: k11776 
o|contracted procedure: k11785 
o|contracted procedure: k11962 
o|contracted procedure: k11968 
o|contracted procedure: k11984 
o|contracted procedure: k11975 
o|contracted procedure: k11996 
o|contracted procedure: k12021 
o|contracted procedure: k12033 
o|contracted procedure: k12043 
o|contracted procedure: k12047 
o|contracted procedure: k12050 
o|contracted procedure: k12085 
o|contracted procedure: k12095 
o|contracted procedure: k12099 
o|contracted procedure: k12115 
o|contracted procedure: k12251 
o|contracted procedure: k12121 
o|contracted procedure: k12127 
o|contracted procedure: k12130 
o|contracted procedure: k12139 
o|contracted procedure: k12231 
o|contracted procedure: k12150 
o|contracted procedure: k12156 
o|contracted procedure: k12176 
o|contracted procedure: k12183 
o|contracted procedure: k12191 
o|contracted procedure: k12187 
o|contracted procedure: k11806 
o|contracted procedure: k11819 
o|contracted procedure: k11823 
o|contracted procedure: k11831 
o|contracted procedure: k11834 
o|contracted procedure: k11810 
o|contracted procedure: k11846 
o|contracted procedure: k11849 
o|contracted procedure: k11852 
o|contracted procedure: k11860 
o|contracted procedure: k11868 
o|contracted procedure: k12206 
o|contracted procedure: k12212 
o|contracted procedure: k12219 
o|contracted procedure: k12242 
o|contracted procedure: k12238 
o|contracted procedure: k12284 
o|contracted procedure: k12308 
o|contracted procedure: k12295 
o|contracted procedure: k12289 
o|contracted procedure: k12316 
o|contracted procedure: k11892 
o|contracted procedure: k11896 
o|contracted procedure: k11900 
o|contracted procedure: k11905 
o|contracted procedure: k11917 
o|contracted procedure: k11920 
o|contracted procedure: k11923 
o|contracted procedure: k11931 
o|contracted procedure: k11939 
o|contracted procedure: k12325 
o|contracted procedure: k12337 
o|contracted procedure: k12346 
o|contracted procedure: k590619495 
o|contracted procedure: k12350 
o|contracted procedure: k12400 
o|contracted procedure: k12362 
o|contracted procedure: k12396 
o|contracted procedure: k12371 
o|contracted procedure: k12388 
o|contracted procedure: k12392 
o|contracted procedure: k12522 
o|contracted procedure: k12409 
o|contracted procedure: k12514 
o|contracted procedure: k12518 
o|contracted procedure: k12418 
o|contracted procedure: k12436 
o|contracted procedure: k12440 
o|contracted procedure: k12449 
o|contracted procedure: k12492 
o|contracted procedure: k12458 
o|contracted procedure: k12467 
o|contracted procedure: k12484 
o|contracted procedure: k12488 
o|contracted procedure: k12501 
o|contracted procedure: k12505 
o|contracted procedure: k12540 
o|contracted procedure: k12549 
o|contracted procedure: k12566 
o|contracted procedure: k12574 
o|contracted procedure: k12580 
o|contracted procedure: k12589 
o|contracted procedure: k12614 
o|contracted procedure: k12592 
o|contracted procedure: k6436 
o|contracted procedure: k6452 
o|contracted procedure: k12620 
o|contracted procedure: k12623 
o|contracted procedure: k12638 
o|contracted procedure: k12644 
o|contracted procedure: k12669 
o|contracted procedure: k12672 
o|contracted procedure: k12781 
o|contracted procedure: k12675 
o|contracted procedure: k12684 
o|contracted procedure: k12698 
o|contracted procedure: k12704 
o|contracted procedure: k12712 
o|contracted procedure: k12715 
o|contracted procedure: k12756 
o|contracted procedure: k12721 
o|contracted procedure: k12747 
o|contracted procedure: k12738 
o|contracted procedure: k12727 
o|contracted procedure: k12734 
o|contracted procedure: k12762 
o|contracted procedure: k12774 
o|contracted procedure: k12808 
o|contracted procedure: k12814 
o|contracted procedure: k12821 
o|contracted procedure: k12849 
o|contracted procedure: k12855 
o|contracted procedure: k12904 
o|contracted procedure: k12877 
o|contracted procedure: k12880 
o|contracted procedure: k12901 
o|contracted procedure: k12894 
o|inlining procedure: k12890 
o|inlining procedure: k12890 
o|contracted procedure: k12931 
o|contracted procedure: k12957 
o|contracted procedure: k12966 
o|contracted procedure: k12975 
o|contracted procedure: k12984 
o|contracted procedure: k12993 
o|contracted procedure: k13003 
o|contracted procedure: k13014 
o|contracted procedure: k13008 
o|contracted procedure: k13089 
o|contracted procedure: k13044 
o|contracted procedure: k13083 
o|contracted procedure: k13047 
o|contracted procedure: k13077 
o|contracted procedure: k13050 
o|contracted procedure: k13071 
o|contracted procedure: k13053 
o|contracted procedure: k13064 
o|contracted procedure: k13060 
o|contracted procedure: k13119 
o|contracted procedure: k13122 
o|contracted procedure: k13134 
o|contracted procedure: k13149 
o|contracted procedure: k13164 
o|contracted procedure: k13167 
o|contracted procedure: k13196 
o|contracted procedure: k13177 
o|contracted procedure: k13185 
o|contracted procedure: k13189 
o|contracted procedure: k13181 
o|contracted procedure: k13202 
o|contracted procedure: k13205 
o|contracted procedure: k13217 
o|contracted procedure: k13250 
o|contracted procedure: k13227 
o|contracted procedure: k13239 
o|contracted procedure: k13231 
o|contracted procedure: k13246 
o|contracted procedure: k13256 
o|contracted procedure: k13266 
o|contracted procedure: k13272 
o|contracted procedure: k13308 
o|contracted procedure: k13285 
o|contracted procedure: k13297 
o|contracted procedure: k13289 
o|contracted procedure: k13304 
o|contracted procedure: k13314 
o|contracted procedure: k13331 
o|contracted procedure: k13327 
o|contracted procedure: k13340 
o|contracted procedure: k13346 
o|contracted procedure: k13374 
o|contracted procedure: k13383 
o|contracted procedure: k13421 
o|contracted procedure: k13389 
o|contracted procedure: k13417 
o|contracted procedure: k13427 
o|contracted procedure: k13456 
o|contracted procedure: k13440 
o|contracted procedure: k13448 
o|contracted procedure: k13452 
o|contracted procedure: k13444 
o|contracted procedure: k13462 
o|contracted procedure: k13471 
o|contracted procedure: k13510 
o|contracted procedure: k13484 
o|contracted procedure: k13496 
o|contracted procedure: k13488 
o|contracted procedure: k13506 
o|contracted procedure: k13516 
o|contracted procedure: k13532 
o|contracted procedure: k13538 
o|contracted procedure: k13548 
o|contracted procedure: k13559 
o|contracted procedure: k13555 
o|contracted procedure: k13574 
o|contracted procedure: k13583 
o|contracted procedure: k13590 
o|contracted procedure: k13619 
o|contracted procedure: k13603 
o|contracted procedure: k13611 
o|contracted procedure: k13615 
o|contracted procedure: k13607 
o|contracted procedure: k13625 
o|contracted procedure: k13628 
o|contracted procedure: k13658 
o|contracted procedure: k13638 
o|contracted procedure: k13654 
o|contracted procedure: k13646 
o|contracted procedure: k13650 
o|contracted procedure: k13642 
o|contracted procedure: k13664 
o|contracted procedure: k13693 
o|contracted procedure: k13674 
o|contracted procedure: k13682 
o|contracted procedure: k13686 
o|contracted procedure: k13678 
o|contracted procedure: k13699 
o|contracted procedure: k13711 
o|contracted procedure: k13718 
o|contracted procedure: k13724 
o|contracted procedure: k13731 
o|contracted procedure: k13737 
o|contracted procedure: k13747 
o|contracted procedure: k13753 
o|contracted procedure: k13756 
o|contracted procedure: k13786 
o|contracted procedure: k13792 
o|contracted procedure: k13809 
o|contracted procedure: k13817 
o|contracted procedure: k13832 
o|contracted procedure: k13838 
o|contracted procedure: k13857 
o|contracted procedure: k13872 
o|contracted procedure: k13878 
o|contracted procedure: k13884 
o|contracted procedure: k13890 
o|contracted procedure: k13911 
o|contracted procedure: k13917 
o|contracted procedure: k13923 
o|contracted procedure: k13929 
o|contracted procedure: k13950 
o|contracted procedure: k13956 
o|contracted procedure: k13962 
o|contracted procedure: k13968 
o|contracted procedure: k13974 
o|contracted procedure: k13980 
o|contracted procedure: k13986 
o|contracted procedure: k13992 
o|contracted procedure: k14021 
o|contracted procedure: k14027 
o|contracted procedure: k14033 
o|contracted procedure: k14039 
o|contracted procedure: k14045 
o|contracted procedure: k14051 
o|contracted procedure: k14057 
o|contracted procedure: k14063 
o|contracted procedure: k14110 
o|contracted procedure: k14125 
o|contracted procedure: k14131 
o|contracted procedure: k14137 
o|contracted procedure: k14143 
o|contracted procedure: k14180 
o|contracted procedure: k14192 
o|contracted procedure: k14201 
o|contracted procedure: k14213 
o|contracted procedure: k14225 
o|contracted procedure: k14240 
o|contracted procedure: k14270 
o|contracted procedure: k14276 
o|contracted procedure: k14306 
o|contracted procedure: k14315 
o|contracted procedure: k14327 
o|contracted procedure: k14339 
o|contracted procedure: k14351 
o|contracted procedure: k14372 
o|contracted procedure: k14381 
o|contracted procedure: k14388 
o|contracted procedure: k14400 
o|contracted procedure: k14407 
o|contracted procedure: k14413 
o|contracted procedure: k14426 
o|contracted procedure: k14432 
o|contracted procedure: k14438 
o|contracted procedure: k14444 
o|contracted procedure: k14450 
o|contracted procedure: k14456 
o|contracted procedure: k14462 
o|contracted procedure: k14492 
o|contracted procedure: k14498 
o|contracted procedure: k14504 
o|contracted procedure: k14521 
o|contracted procedure: k14536 
o|contracted procedure: k14542 
o|contracted procedure: k14548 
o|contracted procedure: k14554 
o|contracted procedure: k14575 
o|contracted procedure: k14581 
o|contracted procedure: k14587 
o|contracted procedure: k14593 
o|contracted procedure: k14599 
o|contracted procedure: k14605 
o|contracted procedure: k14611 
o|contracted procedure: k14617 
o|contracted procedure: k14623 
o|contracted procedure: k14629 
o|contracted procedure: k14662 
o|contracted procedure: k14668 
o|contracted procedure: k14674 
o|contracted procedure: k14680 
o|contracted procedure: k14686 
o|contracted procedure: k14692 
o|contracted procedure: k14698 
o|contracted procedure: k14704 
o|contracted procedure: k14710 
o|contracted procedure: k14716 
o|contracted procedure: k14722 
o|contracted procedure: k14781 
o|contracted procedure: k14793 
o|contracted procedure: k14814 
o|contracted procedure: k14823 
o|contracted procedure: k14830 
o|contracted procedure: k14842 
o|contracted procedure: k14849 
o|contracted procedure: k14857 
o|contracted procedure: k14863 
o|contracted procedure: k14869 
o|contracted procedure: k14875 
o|contracted procedure: k14881 
o|contracted procedure: k14887 
o|contracted procedure: k14893 
o|contracted procedure: k14923 
o|contracted procedure: k14929 
o|contracted procedure: k14935 
o|contracted procedure: k14941 
o|contracted procedure: k14960 
o|contracted procedure: k14966 
o|contracted procedure: k14972 
o|contracted procedure: k14978 
o|contracted procedure: k14984 
o|contracted procedure: k14990 
o|contracted procedure: k14996 
o|contracted procedure: k15002 
o|contracted procedure: k15008 
o|contracted procedure: k15014 
o|contracted procedure: k15020 
o|contracted procedure: k15026 
o|contracted procedure: k15032 
o|contracted procedure: k15038 
o|contracted procedure: k15044 
o|contracted procedure: k15050 
o|contracted procedure: k15056 
o|contracted procedure: k15062 
o|contracted procedure: k15068 
o|contracted procedure: k15074 
o|contracted procedure: k15080 
o|contracted procedure: k15086 
o|contracted procedure: k15092 
o|contracted procedure: k15098 
o|contracted procedure: k15104 
o|contracted procedure: k15110 
o|contracted procedure: k15116 
o|contracted procedure: k15122 
o|contracted procedure: k15128 
o|contracted procedure: k15134 
o|contracted procedure: k15222 
o|contracted procedure: k15225 
o|contracted procedure: k15232 
o|contracted procedure: k15238 
o|contracted procedure: k15245 
o|contracted procedure: k15251 
o|contracted procedure: k15254 
o|contracted procedure: k15261 
o|contracted procedure: k15267 
o|contracted procedure: k15270 
o|contracted procedure: k15277 
o|contracted procedure: k15283 
o|contracted procedure: k15294 
o|contracted procedure: k15290 
o|contracted procedure: k15300 
o|contracted procedure: k15307 
o|contracted procedure: k15313 
o|contracted procedure: k15320 
o|contracted procedure: k15326 
o|contracted procedure: k15339 
o|contracted procedure: k15426 
o|contracted procedure: k15345 
o|contracted procedure: k15348 
o|contracted procedure: k15354 
o|contracted procedure: k15357 
o|contracted procedure: k15395 
o|contracted procedure: k15367 
o|contracted procedure: k15391 
o|contracted procedure: k15375 
o|contracted procedure: k15383 
o|contracted procedure: k15387 
o|contracted procedure: k15379 
o|contracted procedure: k15371 
o|contracted procedure: k15401 
o|contracted procedure: k15408 
o|contracted procedure: k15412 
o|contracted procedure: k15449 
o|contracted procedure: k15429 
o|contracted procedure: k15445 
o|contracted procedure: k15435 
o|contracted procedure: k15439 
o|contracted procedure: k15499 
o|contracted procedure: k15505 
o|contracted procedure: k15508 
o|contracted procedure: k15514 
o|contracted procedure: k15523 
o|contracted procedure: k15526 
o|contracted procedure: k15532 
o|contracted procedure: k15540 
o|contracted procedure: k15543 
o|contracted procedure: k15549 
o|contracted procedure: k15555 
o|contracted procedure: k15563 
o|contracted procedure: k15569 
o|contracted procedure: k15575 
o|contracted procedure: k15583 
o|contracted procedure: k15589 
o|contracted procedure: k15598 
o|contracted procedure: k15605 
o|contracted procedure: k15616 
o|contracted procedure: k15622 
o|contracted procedure: k15628 
o|contracted procedure: k15634 
o|contracted procedure: k15640 
o|contracted procedure: k15646 
o|contracted procedure: k15652 
o|contracted procedure: k15658 
o|contracted procedure: k15664 
o|contracted procedure: k15670 
o|contracted procedure: k15676 
o|contracted procedure: k15685 
o|contracted procedure: k15691 
o|contracted procedure: k15697 
o|contracted procedure: k15703 
o|contracted procedure: k15709 
o|contracted procedure: k15718 
o|contracted procedure: k15721 
o|contracted procedure: k15727 
o|contracted procedure: k15736 
o|contracted procedure: k15742 
o|contracted procedure: k15749 
o|contracted procedure: k15758 
o|contracted procedure: k15764 
o|contracted procedure: k15771 
o|contracted procedure: k15777 
o|contracted procedure: k15783 
o|contracted procedure: k15786 
o|contracted procedure: k15792 
o|contracted procedure: k15806 
o|contracted procedure: k15812 
o|contracted procedure: k15831 
o|contracted procedure: k15853 
o|contracted procedure: k15859 
o|contracted procedure: k15880 
o|contracted procedure: k15886 
o|contracted procedure: k15892 
o|contracted procedure: k15898 
o|contracted procedure: k15904 
o|contracted procedure: k15910 
o|contracted procedure: k15916 
o|contracted procedure: k15963 
o|contracted procedure: k15969 
o|contracted procedure: k15975 
o|contracted procedure: k15981 
o|contracted procedure: k15987 
o|contracted procedure: k15993 
o|contracted procedure: k15999 
o|contracted procedure: k16005 
o|contracted procedure: k16056 
o|contracted procedure: k16062 
o|contracted procedure: k16068 
o|contracted procedure: k16074 
o|contracted procedure: k16080 
o|contracted procedure: k16086 
o|contracted procedure: k16123 
o|contracted procedure: k16129 
o|contracted procedure: k16149 
o|contracted procedure: k16157 
o|contracted procedure: k16163 
o|contracted procedure: k16166 
o|contracted procedure: k16227 
o|contracted procedure: k16169 
o|contracted procedure: k16175 
o|contracted procedure: k16187 
o|contracted procedure: k16197 
o|contracted procedure: k16201 
o|contracted procedure: k16208 
o|contracted procedure: k16211 
o|contracted procedure: k16218 
o|contracted procedure: k16233 
o|contracted procedure: k16239 
o|contracted procedure: k16251 
o|contracted procedure: k16261 
o|contracted procedure: k16265 
o|contracted procedure: k16268 
o|contracted procedure: k16301 
o|contracted procedure: k16309 
o|contracted procedure: k16317 
o|contracted procedure: k16323 
o|contracted procedure: k16332 
o|contracted procedure: k16335 
o|contracted procedure: k16341 
o|contracted procedure: k16361 
o|contracted procedure: k16364 
o|contracted procedure: k16377 
o|contracted procedure: k1637419525 
o|contracted procedure: k1637419529 
o|contracted procedure: k16387 
o|contracted procedure: k16397 
o|contracted procedure: k16405 
o|contracted procedure: k16411 
o|contracted procedure: k16418 
o|contracted procedure: k16428 
o|contracted procedure: k16446 
o|contracted procedure: k16452 
o|contracted procedure: k16458 
o|contracted procedure: k16485 
o|contracted procedure: k16497 
o|contracted procedure: k16507 
o|contracted procedure: k16511 
o|contracted procedure: k16536 
o|contracted procedure: k16579 
o|inlining procedure: k16576 
o|contracted procedure: k16633 
o|contracted procedure: k16642 
o|contracted procedure: k16650 
o|contracted procedure: k16663 
o|contracted procedure: k16674 
o|contracted procedure: k16686 
o|contracted procedure: k16700 
o|contracted procedure: k16704 
o|contracted procedure: k16771 
o|contracted procedure: k16774 
o|contracted procedure: k16777 
o|contracted procedure: k16794 
o|contracted procedure: k16806 
o|contracted procedure: k16821 
o|contracted procedure: k16861 
o|contracted procedure: k16854 
o|contracted procedure: k16830 
o|contracted procedure: k16842 
o|contracted procedure: k16845 
o|contracted procedure: k16848 
o|contracted procedure: k16867 
o|contracted procedure: k16884 
o|contracted procedure: k17012 
o|contracted procedure: k17020 
o|contracted procedure: k16890 
o|contracted procedure: k16893 
o|contracted procedure: k16899 
o|contracted procedure: k16930 
o|contracted procedure: k16936 
o|contracted procedure: k16960 
o|contracted procedure: k16948 
o|contracted procedure: k16955 
o|contracted procedure: k17032 
o|contracted procedure: k17054 
o|contracted procedure: k17050 
o|contracted procedure: k17035 
o|contracted procedure: k17038 
o|contracted procedure: k17046 
o|contracted procedure: k17066 
o|contracted procedure: k17088 
o|contracted procedure: k16881 
o|contracted procedure: k17084 
o|contracted procedure: k17069 
o|contracted procedure: k17072 
o|contracted procedure: k17080 
o|contracted procedure: k17109 
o|contracted procedure: k17190 
o|contracted procedure: k17186 
o|contracted procedure: k17115 
o|contracted procedure: k17172 
o|contracted procedure: k17118 
o|inlining procedure: k17155 
o|contracted procedure: k17230 
o|contracted procedure: k17276 
o|contracted procedure: k17285 
o|contracted procedure: k17288 
o|contracted procedure: k17295 
o|contracted procedure: k17314 
o|contracted procedure: k6323 
o|contracted procedure: k6338 
o|contracted procedure: k17347 
o|contracted procedure: k17355 
o|contracted procedure: k17363 
o|contracted procedure: k17397 
o|contracted procedure: k17403 
o|contracted procedure: k17412 
o|contracted procedure: k17436 
o|contracted procedure: k17452 
o|contracted procedure: k17456 
o|contracted procedure: k17460 
o|contracted procedure: k17469 
o|contracted procedure: k17479 
o|contracted procedure: k17483 
o|contracted procedure: k17498 
o|contracted procedure: k17511 
o|contracted procedure: k17535 
o|contracted procedure: k17563 
o|contracted procedure: k17592 
o|contracted procedure: k17601 
o|contracted procedure: k17616 
o|contracted procedure: k17622 
o|contracted procedure: k17645 
o|contracted procedure: k17639 
o|contracted procedure: k17665 
o|contracted procedure: k17659 
o|contracted procedure: k17705 
o|contracted procedure: k17711 
o|contracted procedure: k17730 
o|contracted procedure: k17724 
o|contracted procedure: k17815 
o|contracted procedure: k17827 
o|contracted procedure: k17837 
o|contracted procedure: k17841 
o|contracted procedure: k17789 
o|contracted procedure: k17803 
o|contracted procedure: k17807 
o|contracted procedure: k17889 
o|contracted procedure: k17873 
o|contracted procedure: k17940 
o|contracted procedure: k17949 
o|simplifications: ((if . 5) (let . 307)) 
o|removed binding forms: 1239 
o|contracted procedure: k7283 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest971972 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest971972 0 
o|contracted procedure: k9690 
o|inlining procedure: k10543 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest29662969 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest29662969 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest29662969 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest29662969 0 
o|contracted procedure: k16204 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest44274430 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest44274430 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest45164517 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest45164517 0 
o|simplifications: ((let . 1)) 
o|replaced variables: 3 
o|removed binding forms: 5 
(o x)|known list op on rest arg sublist: ##core#rest-null? r13048 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r13048 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r13048 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r13048 1 
o|removed binding forms: 3 
o|removed binding forms: 2 
o|direct leaf routine/allocation: loop463 0 
o|direct leaf routine/allocation: loop863 0 
o|direct leaf routine/allocation: loop1119 0 
o|direct leaf routine/allocation: a8105 0 
o|direct leaf routine/allocation: g423424 3 
o|direct leaf routine/allocation: g27562757 0 
o|direct leaf routine/allocation: a17324 0 
o|converted assignments to bindings: (loop463) 
o|converted assignments to bindings: (loop863) 
o|converted assignments to bindings: (loop1119) 
o|contracted procedure: "(mini-srfi-1.scm:135) k5973" 
o|contracted procedure: "(mini-srfi-1.scm:190) k6330" 
o|simplifications: ((let . 3)) 
o|removed binding forms: 2 
o|customizable procedures: (for-each-loop44904505 loop4354 g42874301 for-each-loop42864311 doloop43234324 loop4264 loop558 tmp15264 tmp25265 map-loop41254146 map-loop41564177 resolve4058 loop4070 g39964003 for-each-loop39954006 k16326 walkeach3951 walk3950 chicken.compiler.support#lset-adjoin/eq? k16236 for-each-loop39283938 k16172 walk3879 for-each-loop39033914 k15517 k15592 k15679 k15712 k15730 k15752 k15332 k14784 k14796 k14833 g36173618 k14309 k14318 k14330 k14342 k14354 k14391 err3343 g34593460 g33383339 chicken.compiler.support#foreign-type-argument-converter chicken.compiler.support#foreign-type-result-converter chicken.compiler.support#follow-without-loop k13137 k13152 k13275 k13317 k13343 k13386 k13430 k13474 k13519 k13593 repeat2991 g32433244 k13492 k13293 k13235 k12840 k12799 k12583 a12598 loop586 matchn2747 loop2776 match12746 resolve2745 walk2559 map-loop25682585 loop2722 k12133 k12170 uses-foreign-stubs?2600 walk2516 map-loop25292549 for-each-loop26722684 for-each-loop26942712 rec2480 lp2454 map-loop20402057 map-loop21532172 g23462355 map-loop23402365 g22402249 map-loop22342254 map-loop22642283 g23072316 map-loop23012326 walk2183 map-loop20682086 walk2380 for-each-loop24232433 lp2411 g20962103 for-each-loop20952107 loop2114 loop22117 loop230 fold2017 k9559 k10163 map-loop19892006 map-loop19631980 map-loop19371954 loop1918 map-loop18941911 chicken.compiler.support#cons* map-loop18681885 loop1859 map-loop18191836 map-loop17981843 chicken.compiler.support#last map-loop17561773 walk1699 map-loop17271744 map-loop16701687 k8888 k9133 k9331 map-loop16391656 map-loop15931610 map-loop15621579 map-loop15131530 map-loop14691486 k8815 map-loop14321449 loop1399 map-loop436454 g13671376 map-loop13611379 k8446 walk1299 map-loop13241341 foldr408411 g413414 map-loop11521173 tmp14908 tmp24909 loop1102 k7710 loop1073 k7576 doloop978979 loop958 fold951 chicken.compiler.support#every k7135 k7142 loop894 loop878 k6870 g800825 for-each-loop799835 collect751 g756763 for-each-loop755774 text700 chicken.compiler.support#test-debugging-mode dump701 for-each-loop704721 chicken.compiler.support#any loop480 loop340 loop327 loop314 chicken.compiler.support#take) 
o|calls to known targets: 527 
o|identified direct recursive calls: f_5409 1 
o|identified direct recursive calls: f_5740 1 
o|identified direct recursive calls: f_6076 1 
o|identified direct recursive calls: f_6135 2 
o|identified direct recursive calls: f_7025 1 
o|identified direct recursive calls: f_7066 1 
o|identified direct recursive calls: f_7332 1 
o|unused rest argument: rest971972 f_7423 
o|identified direct recursive calls: f_7884 1 
o|identified direct recursive calls: f_8026 1 
o|identified direct recursive calls: f_5963 1 
o|identified direct recursive calls: f_6036 1 
o|identified direct recursive calls: f_8328 4 
o|identified direct recursive calls: f_9753 1 
o|identified direct recursive calls: f_5467 1 
o|identified direct recursive calls: f_10512 1 
o|identified direct recursive calls: f_10497 1 
o|identified direct recursive calls: f_11444 1 
o|identified direct recursive calls: f_11077 1 
o|identified direct recursive calls: f_10794 1 
o|identified direct recursive calls: f_11233 1 
o|identified direct recursive calls: f_11565 1 
o|identified direct recursive calls: f_11688 1 
o|identified direct recursive calls: f_12357 1 
o|unused rest argument: rest29662969 f_13042 
o|identified direct recursive calls: f_17027 1 
o|identified direct recursive calls: f_17061 1 
o|identified direct recursive calls: f_6318 1 
o|unused rest argument: rest44274430 f_17722 
o|unused rest argument: rest45164517 f_17871 
o|fast box initializations: 93 
o|fast global references: 63 
o|fast global assignments: 22 
o|dropping unused closure argument: f_14178 
o|dropping unused closure argument: f_14199 
o|dropping unused closure argument: f_16613 
o|dropping unused closure argument: f_5409 
o|dropping unused closure argument: f_5670 
o|dropping unused closure argument: f_5704 
o|dropping unused closure argument: f_5734 
o|dropping unused closure argument: f_6070 
o|dropping unused closure argument: f_6076 
o|dropping unused closure argument: f_6129 
o|dropping unused closure argument: f_6614 
o|dropping unused closure argument: f_7025 
o|dropping unused closure argument: f_7372 
o|dropping unused closure argument: f_7884 
*/
/* end of file */
