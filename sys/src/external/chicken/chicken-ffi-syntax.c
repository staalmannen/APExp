/* Generated from chicken-ffi-syntax.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: chicken-ffi-syntax.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file chicken-ffi-syntax.c
   unit: chicken-ffi-syntax
   uses: data-structures expand internal extras library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externimport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[98];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,16),40,97,50,54,56,57,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,42),40,99,111,109,112,105,108,101,114,45,111,110,108,121,45,101,114,45,116,114,97,110,115,102,111,114,109,101,114,32,116,114,97,110,115,102,111,114,109,101,114,41,0,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,56,50,48,32,103,56,51,50,41,0,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,45),40,97,110,110,111,116,97,116,101,45,102,111,114,101,105,103,110,45,112,114,111,99,101,100,117,114,101,32,101,32,97,114,103,116,121,112,101,115,32,114,116,121,112,101,41,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,16),40,97,50,56,54,54,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,55,54,32,103,57,56,56,41,0,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,16),40,97,50,57,49,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,16),40,97,50,57,56,50,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,51,54,32,103,57,52,56,41,0,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,16),40,97,51,48,49,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,16),40,97,51,48,56,50,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,56,57,51,32,103,57,48,53,41,0,0,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,16),40,97,51,49,49,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,16),40,97,51,50,48,54,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,16),40,97,51,50,50,51,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,16),40,97,51,50,52,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,16),40,97,51,50,54,49,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,16),40,97,51,51,50,55,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,6),40,103,55,50,54,41,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,23),40,108,111,111,112,32,98,105,110,100,105,110,103,115,32,97,108,105,97,115,101,115,41,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,11),40,97,51,53,48,50,32,98,32,97,41,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,10),40,103,49,54,52,32,120,32,114,41,0,0,0,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,15),40,102,111,108,100,114,49,53,57,32,103,49,54,48,41,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,50,48,49,32,103,50,49,51,41,0,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,49,55,52,32,103,49,56,54,41,0,0,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,108,115,116,115,41,0,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,55,50,48,32,103,55,51,50,41,0,0,0,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,16),40,97,51,52,48,48,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,16),40,97,51,53,54,55,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,13),40,97,51,54,53,51,32,120,32,114,32,99,41,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,53,56,32,103,54,55,48,41,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,54,51,49,32,103,54,52,51,41,0,0,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,16),40,97,51,54,55,52,32,102,111,114,109,32,114,32,99,41};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1388)
static void C_ccall f_1388(C_word c,C_word *av) C_noret;
C_noret_decl(f_1391)
static void C_ccall f_1391(C_word c,C_word *av) C_noret;
C_noret_decl(f_1394)
static void C_ccall f_1394(C_word c,C_word *av) C_noret;
C_noret_decl(f_1397)
static void C_ccall f_1397(C_word c,C_word *av) C_noret;
C_noret_decl(f_1400)
static void C_ccall f_1400(C_word c,C_word *av) C_noret;
C_noret_decl(f_1616)
static void C_fcall f_1616(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1624)
static void C_fcall f_1624(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1632)
static void C_ccall f_1632(C_word c,C_word *av) C_noret;
C_noret_decl(f_1643)
static void C_ccall f_1643(C_word c,C_word *av) C_noret;
C_noret_decl(f_1656)
static void C_fcall f_1656(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1670)
static void C_ccall f_1670(C_word c,C_word *av) C_noret;
C_noret_decl(f_1674)
static void C_ccall f_1674(C_word c,C_word *av) C_noret;
C_noret_decl(f_1686)
static void C_ccall f_1686(C_word c,C_word *av) C_noret;
C_noret_decl(f_1688)
static void C_fcall f_1688(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1735)
static void C_ccall f_1735(C_word c,C_word *av) C_noret;
C_noret_decl(f_1737)
static void C_fcall f_1737(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1777)
static C_word C_fcall f_1777(C_word t0);
C_noret_decl(f_1811)
static C_word C_fcall f_1811(C_word t0);
C_noret_decl(f_2682)
static void C_ccall f_2682(C_word c,C_word *av) C_noret;
C_noret_decl(f_2684)
static void C_fcall f_2684(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2690)
static void C_ccall f_2690(C_word c,C_word *av) C_noret;
C_noret_decl(f_2697)
static void C_ccall f_2697(C_word c,C_word *av) C_noret;
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
C_noret_decl(f_2730)
static void C_fcall f_2730(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2742)
static void C_ccall f_2742(C_word c,C_word *av) C_noret;
C_noret_decl(f_2748)
static void C_ccall f_2748(C_word c,C_word *av) C_noret;
C_noret_decl(f_2751)
static void C_ccall f_2751(C_word c,C_word *av) C_noret;
C_noret_decl(f_2757)
static void C_fcall f_2757(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2800)
static void C_ccall f_2800(C_word c,C_word *av) C_noret;
C_noret_decl(f_2802)
static void C_fcall f_2802(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2827)
static void C_ccall f_2827(C_word c,C_word *av) C_noret;
C_noret_decl(f_2837)
static void C_ccall f_2837(C_word c,C_word *av) C_noret;
C_noret_decl(f_2840)
static void C_ccall f_2840(C_word c,C_word *av) C_noret;
C_noret_decl(f_2843)
static void C_ccall f_2843(C_word c,C_word *av) C_noret;
C_noret_decl(f_2846)
static void C_ccall f_2846(C_word c,C_word *av) C_noret;
C_noret_decl(f_2849)
static void C_ccall f_2849(C_word c,C_word *av) C_noret;
C_noret_decl(f_2852)
static void C_ccall f_2852(C_word c,C_word *av) C_noret;
C_noret_decl(f_2855)
static void C_ccall f_2855(C_word c,C_word *av) C_noret;
C_noret_decl(f_2858)
static void C_ccall f_2858(C_word c,C_word *av) C_noret;
C_noret_decl(f_2861)
static void C_ccall f_2861(C_word c,C_word *av) C_noret;
C_noret_decl(f_2865)
static void C_ccall f_2865(C_word c,C_word *av) C_noret;
C_noret_decl(f_2867)
static void C_ccall f_2867(C_word c,C_word *av) C_noret;
C_noret_decl(f_2871)
static void C_ccall f_2871(C_word c,C_word *av) C_noret;
C_noret_decl(f_2874)
static void C_ccall f_2874(C_word c,C_word *av) C_noret;
C_noret_decl(f_2877)
static void C_ccall f_2877(C_word c,C_word *av) C_noret;
C_noret_decl(f_2880)
static void C_ccall f_2880(C_word c,C_word *av) C_noret;
C_noret_decl(f_2895)
static void C_ccall f_2895(C_word c,C_word *av) C_noret;
C_noret_decl(f_2909)
static void C_ccall f_2909(C_word c,C_word *av) C_noret;
C_noret_decl(f_2911)
static void C_ccall f_2911(C_word c,C_word *av) C_noret;
C_noret_decl(f_2915)
static void C_ccall f_2915(C_word c,C_word *av) C_noret;
C_noret_decl(f_2935)
static void C_ccall f_2935(C_word c,C_word *av) C_noret;
C_noret_decl(f_2941)
static void C_fcall f_2941(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2981)
static void C_ccall f_2981(C_word c,C_word *av) C_noret;
C_noret_decl(f_2983)
static void C_ccall f_2983(C_word c,C_word *av) C_noret;
C_noret_decl(f_2987)
static void C_ccall f_2987(C_word c,C_word *av) C_noret;
C_noret_decl(f_3009)
static void C_ccall f_3009(C_word c,C_word *av) C_noret;
C_noret_decl(f_3011)
static void C_ccall f_3011(C_word c,C_word *av) C_noret;
C_noret_decl(f_3015)
static void C_ccall f_3015(C_word c,C_word *av) C_noret;
C_noret_decl(f_3035)
static void C_ccall f_3035(C_word c,C_word *av) C_noret;
C_noret_decl(f_3041)
static void C_fcall f_3041(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3081)
static void C_ccall f_3081(C_word c,C_word *av) C_noret;
C_noret_decl(f_3083)
static void C_ccall f_3083(C_word c,C_word *av) C_noret;
C_noret_decl(f_3087)
static void C_ccall f_3087(C_word c,C_word *av) C_noret;
C_noret_decl(f_3109)
static void C_ccall f_3109(C_word c,C_word *av) C_noret;
C_noret_decl(f_3111)
static void C_ccall f_3111(C_word c,C_word *av) C_noret;
C_noret_decl(f_3115)
static void C_ccall f_3115(C_word c,C_word *av) C_noret;
C_noret_decl(f_3118)
static void C_fcall f_3118(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3133)
static void C_ccall f_3133(C_word c,C_word *av) C_noret;
C_noret_decl(f_3144)
static void C_fcall f_3144(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3205)
static void C_ccall f_3205(C_word c,C_word *av) C_noret;
C_noret_decl(f_3207)
static void C_ccall f_3207(C_word c,C_word *av) C_noret;
C_noret_decl(f_3211)
static void C_ccall f_3211(C_word c,C_word *av) C_noret;
C_noret_decl(f_3222)
static void C_ccall f_3222(C_word c,C_word *av) C_noret;
C_noret_decl(f_3224)
static void C_ccall f_3224(C_word c,C_word *av) C_noret;
C_noret_decl(f_3228)
static void C_ccall f_3228(C_word c,C_word *av) C_noret;
C_noret_decl(f_3239)
static void C_ccall f_3239(C_word c,C_word *av) C_noret;
C_noret_decl(f_3241)
static void C_ccall f_3241(C_word c,C_word *av) C_noret;
C_noret_decl(f_3245)
static void C_ccall f_3245(C_word c,C_word *av) C_noret;
C_noret_decl(f_3260)
static void C_ccall f_3260(C_word c,C_word *av) C_noret;
C_noret_decl(f_3262)
static void C_ccall f_3262(C_word c,C_word *av) C_noret;
C_noret_decl(f_3266)
static void C_ccall f_3266(C_word c,C_word *av) C_noret;
C_noret_decl(f_3269)
static void C_ccall f_3269(C_word c,C_word *av) C_noret;
C_noret_decl(f_3279)
static void C_fcall f_3279(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3287)
static void C_ccall f_3287(C_word c,C_word *av) C_noret;
C_noret_decl(f_3291)
static void C_ccall f_3291(C_word c,C_word *av) C_noret;
C_noret_decl(f_3303)
static void C_ccall f_3303(C_word c,C_word *av) C_noret;
C_noret_decl(f_3326)
static void C_ccall f_3326(C_word c,C_word *av) C_noret;
C_noret_decl(f_3328)
static void C_ccall f_3328(C_word c,C_word *av) C_noret;
C_noret_decl(f_3332)
static void C_ccall f_3332(C_word c,C_word *av) C_noret;
C_noret_decl(f_3335)
static void C_ccall f_3335(C_word c,C_word *av) C_noret;
C_noret_decl(f_3350)
static void C_ccall f_3350(C_word c,C_word *av) C_noret;
C_noret_decl(f_3358)
static void C_ccall f_3358(C_word c,C_word *av) C_noret;
C_noret_decl(f_3364)
static void C_ccall f_3364(C_word c,C_word *av) C_noret;
C_noret_decl(f_3367)
static void C_ccall f_3367(C_word c,C_word *av) C_noret;
C_noret_decl(f_3370)
static void C_ccall f_3370(C_word c,C_word *av) C_noret;
C_noret_decl(f_3373)
static void C_ccall f_3373(C_word c,C_word *av) C_noret;
C_noret_decl(f_3376)
static void C_ccall f_3376(C_word c,C_word *av) C_noret;
C_noret_decl(f_3379)
static void C_ccall f_3379(C_word c,C_word *av) C_noret;
C_noret_decl(f_3383)
static void C_ccall f_3383(C_word c,C_word *av) C_noret;
C_noret_decl(f_3395)
static void C_ccall f_3395(C_word c,C_word *av) C_noret;
C_noret_decl(f_3399)
static void C_ccall f_3399(C_word c,C_word *av) C_noret;
C_noret_decl(f_3401)
static void C_ccall f_3401(C_word c,C_word *av) C_noret;
C_noret_decl(f_3405)
static void C_ccall f_3405(C_word c,C_word *av) C_noret;
C_noret_decl(f_3414)
static void C_fcall f_3414(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3422)
static void C_ccall f_3422(C_word c,C_word *av) C_noret;
C_noret_decl(f_3428)
static void C_ccall f_3428(C_word c,C_word *av) C_noret;
C_noret_decl(f_3435)
static void C_ccall f_3435(C_word c,C_word *av) C_noret;
C_noret_decl(f_3439)
static void C_ccall f_3439(C_word c,C_word *av) C_noret;
C_noret_decl(f_3441)
static void C_fcall f_3441(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3464)
static void C_ccall f_3464(C_word c,C_word *av) C_noret;
C_noret_decl(f_3503)
static void C_ccall f_3503(C_word c,C_word *av) C_noret;
C_noret_decl(f_3526)
static void C_fcall f_3526(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3551)
static void C_ccall f_3551(C_word c,C_word *av) C_noret;
C_noret_decl(f_3566)
static void C_ccall f_3566(C_word c,C_word *av) C_noret;
C_noret_decl(f_3568)
static void C_ccall f_3568(C_word c,C_word *av) C_noret;
C_noret_decl(f_3572)
static void C_ccall f_3572(C_word c,C_word *av) C_noret;
C_noret_decl(f_3587)
static void C_ccall f_3587(C_word c,C_word *av) C_noret;
C_noret_decl(f_3594)
static void C_ccall f_3594(C_word c,C_word *av) C_noret;
C_noret_decl(f_3630)
static void C_ccall f_3630(C_word c,C_word *av) C_noret;
C_noret_decl(f_3634)
static void C_ccall f_3634(C_word c,C_word *av) C_noret;
C_noret_decl(f_3648)
static void C_ccall f_3648(C_word c,C_word *av) C_noret;
C_noret_decl(f_3652)
static void C_ccall f_3652(C_word c,C_word *av) C_noret;
C_noret_decl(f_3654)
static void C_ccall f_3654(C_word c,C_word *av) C_noret;
C_noret_decl(f_3658)
static void C_ccall f_3658(C_word c,C_word *av) C_noret;
C_noret_decl(f_3673)
static void C_ccall f_3673(C_word c,C_word *av) C_noret;
C_noret_decl(f_3675)
static void C_ccall f_3675(C_word c,C_word *av) C_noret;
C_noret_decl(f_3685)
static void C_fcall f_3685(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3691)
static void C_ccall f_3691(C_word c,C_word *av) C_noret;
C_noret_decl(f_3701)
static void C_ccall f_3701(C_word c,C_word *av) C_noret;
C_noret_decl(f_3748)
static void C_ccall f_3748(C_word c,C_word *av) C_noret;
C_noret_decl(f_3761)
static void C_ccall f_3761(C_word c,C_word *av) C_noret;
C_noret_decl(f_3791)
static void C_ccall f_3791(C_word c,C_word *av) C_noret;
C_noret_decl(f_3807)
static void C_ccall f_3807(C_word c,C_word *av) C_noret;
C_noret_decl(f_3819)
static void C_fcall f_3819(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3866)
static void C_ccall f_3866(C_word c,C_word *av) C_noret;
C_noret_decl(f_3868)
static void C_fcall f_3868(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3965)
static void C_ccall f_3965(C_word c,C_word *av) C_noret;
C_noret_decl(f_3969)
static void C_ccall f_3969(C_word c,C_word *av) C_noret;
C_noret_decl(f_3973)
static void C_ccall f_3973(C_word c,C_word *av) C_noret;
C_noret_decl(C_chicken_2dffi_2dsyntax_toplevel)
C_externexport void C_ccall C_chicken_2dffi_2dsyntax_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1616)
static void C_ccall trf_1616(C_word c,C_word *av) C_noret;
static void C_ccall trf_1616(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1616(t0,t1,t2);}

C_noret_decl(trf_1624)
static void C_ccall trf_1624(C_word c,C_word *av) C_noret;
static void C_ccall trf_1624(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1624(t0,t1,t2,t3);}

C_noret_decl(trf_1656)
static void C_ccall trf_1656(C_word c,C_word *av) C_noret;
static void C_ccall trf_1656(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1656(t0,t1,t2);}

C_noret_decl(trf_1688)
static void C_ccall trf_1688(C_word c,C_word *av) C_noret;
static void C_ccall trf_1688(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1688(t0,t1,t2);}

C_noret_decl(trf_1737)
static void C_ccall trf_1737(C_word c,C_word *av) C_noret;
static void C_ccall trf_1737(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1737(t0,t1,t2);}

C_noret_decl(trf_2684)
static void C_ccall trf_2684(C_word c,C_word *av) C_noret;
static void C_ccall trf_2684(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2684(t0,t1);}

C_noret_decl(trf_2730)
static void C_ccall trf_2730(C_word c,C_word *av) C_noret;
static void C_ccall trf_2730(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2730(t0,t1,t2,t3);}

C_noret_decl(trf_2757)
static void C_ccall trf_2757(C_word c,C_word *av) C_noret;
static void C_ccall trf_2757(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2757(t0,t1);}

C_noret_decl(trf_2802)
static void C_ccall trf_2802(C_word c,C_word *av) C_noret;
static void C_ccall trf_2802(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2802(t0,t1,t2);}

C_noret_decl(trf_2941)
static void C_ccall trf_2941(C_word c,C_word *av) C_noret;
static void C_ccall trf_2941(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2941(t0,t1,t2);}

C_noret_decl(trf_3041)
static void C_ccall trf_3041(C_word c,C_word *av) C_noret;
static void C_ccall trf_3041(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3041(t0,t1,t2);}

C_noret_decl(trf_3118)
static void C_ccall trf_3118(C_word c,C_word *av) C_noret;
static void C_ccall trf_3118(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3118(t0,t1);}

C_noret_decl(trf_3144)
static void C_ccall trf_3144(C_word c,C_word *av) C_noret;
static void C_ccall trf_3144(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3144(t0,t1,t2);}

C_noret_decl(trf_3279)
static void C_ccall trf_3279(C_word c,C_word *av) C_noret;
static void C_ccall trf_3279(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3279(t0,t1);}

C_noret_decl(trf_3414)
static void C_ccall trf_3414(C_word c,C_word *av) C_noret;
static void C_ccall trf_3414(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3414(t0,t1);}

C_noret_decl(trf_3441)
static void C_ccall trf_3441(C_word c,C_word *av) C_noret;
static void C_ccall trf_3441(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3441(t0,t1,t2,t3);}

C_noret_decl(trf_3526)
static void C_ccall trf_3526(C_word c,C_word *av) C_noret;
static void C_ccall trf_3526(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3526(t0,t1,t2);}

C_noret_decl(trf_3685)
static void C_ccall trf_3685(C_word c,C_word *av) C_noret;
static void C_ccall trf_3685(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3685(t0,t1);}

C_noret_decl(trf_3819)
static void C_ccall trf_3819(C_word c,C_word *av) C_noret;
static void C_ccall trf_3819(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3819(t0,t1,t2);}

C_noret_decl(trf_3868)
static void C_ccall trf_3868(C_word c,C_word *av) C_noret;
static void C_ccall trf_3868(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3868(t0,t1,t2);}

/* k1386 */
static void C_ccall f_1388(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1388,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1391,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_extras_toplevel(2,av2);}}

/* k1389 in k1386 */
static void C_ccall f_1391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1391,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1394,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

/* k1392 in k1389 in k1386 */
static void C_ccall f_1394(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_1394,c,av);}
a=C_alloc(11);
t2=C_a_i_provide(&a,1,lf[0]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1397,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_library_toplevel(2,av2);}}

/* k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1397(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1397,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1400,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_expand_toplevel(2,av2);}}

/* k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1400(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1400,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2682,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:51: ##sys#macro-environment */
t3=*((C_word*)lf[97]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* foldr159 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_1616(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_1616,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1624,a[2]=((C_word*)t0)[2],a[3]=((C_word)li22),tmp=(C_word)a,a+=4,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1643,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
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

/* g164 in foldr159 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_1624(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_1624,4,t0,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1632,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* mini-srfi-1.scm:72: proc */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k1630 in g164 in foldr159 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1632,c,av);}
/* mini-srfi-1.scm:72: scheme#append */
t2=*((C_word*)lf[78]+1);{
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

/* k1641 in foldr159 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1643(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1643,c,av);}
/* mini-srfi-1.scm:72: g164 */
t2=((C_word*)t0)[2];
f_1624(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_1656(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,0,3)))){
C_save_and_reclaim_args((void *)trf_1656,3,t0,t1,t2);}
a=C_alloc(25);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1811,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp);
t4=(
  f_1811(t2)
);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1670,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_i_check_list_2(t2,lf[6]);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1735,a[2]=t5,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1737,a[2]=t8,a[3]=t13,a[4]=t9,a[5]=((C_word)li26),tmp=(C_word)a,a+=6,tmp));
t15=((C_word*)t13)[1];
f_1737(t15,t11,t2);}}

/* k1668 in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1670(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_1670,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1674,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1686,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1688,a[2]=t5,a[3]=t9,a[4]=t6,a[5]=((C_word)li25),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_1688(t11,t7,((C_word*)t0)[4]);}

/* k1672 in k1668 in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1674(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1674,c,av);}
/* mini-srfi-1.scm:76: scheme#append */
t2=*((C_word*)lf[78]+1);{
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

/* k1684 in k1668 in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1686(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1686,c,av);}
/* mini-srfi-1.scm:77: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1656(t2,((C_word*)t0)[3],t1);}

/* map-loop201 in k1668 in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_1688(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1688,3,t0,t1,t2);}
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

/* k1733 in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_1735(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1735,c,av);}{
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

/* map-loop174 in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_1737(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_1737,3,t0,t1,t2);}
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

/* loop in k2749 in k2746 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static C_word C_fcall f_1777(C_word t1){
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
t4=C_eqp(lf[9],t3);
if(C_truep(C_i_not(t4))){
return(C_SCHEME_FALSE);}
else{
t6=C_u_i_cdr(t1);
t1=t6;
goto loop;}}}

/* loop in loop in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static C_word C_fcall f_1811(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_nullp(t1))){
return(C_SCHEME_FALSE);}
else{
t2=C_i_car(t1);
t3=C_i_nullp(t2);
if(C_truep(t3)){
return(t3);}
else{
t5=C_u_i_cdr(t1);
t1=t5;
goto loop;}}}

/* k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_2682,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2684,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2710,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3973,a[2]=t3,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:66: chicken.base#alist-ref */
t5=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[88];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* compiler-only-er-transformer in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_2684(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_2684,2,t1,t2);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2690,a[2]=t2,a[3]=((C_word)li0),tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:57: ##sys#er-transformer */
t4=*((C_word*)lf[5]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* a2689 in compiler-only-er-transformer in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2690(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_2690,c,av);}
a=C_alloc(7);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2697,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* chicken-ffi-syntax.scm:59: chicken.platform#feature? */
t6=*((C_word*)lf[3]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[4];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k2695 in a2689 in compiler-only-er-transformer in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2697(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2697,c,av);}
if(C_truep(t1)){
/* chicken-ffi-syntax.scm:60: transformer */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
/* chicken-ffi-syntax.scm:61: chicken.syntax#syntax-error */
t2=*((C_word*)lf[1]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=C_i_car(((C_word*)t0)[4]);
av2[3]=lf[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2710(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_2710,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2713,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3652,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3654,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:106: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2713(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2713,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2716,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3648,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:113: chicken.base#alist-ref */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[80];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_2716,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2719,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3399,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3401,a[2]=((C_word)li29),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:131: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_2719,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2722,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3395,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:166: chicken.base#alist-ref */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[59];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2722(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_2722,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2725,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3260,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3262,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:182: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2725(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_2725,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2728,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3239,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3241,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:208: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_2728,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2730,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2837,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3222,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3224,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:247: compiler-only-er-transformer */
f_2684(t4,t5);}

/* annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_2730(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_2730,4,t1,t2,t3,t4);}
a=C_alloc(12);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2742,a[2]=t1,a[3]=t2,a[4]=t4,a[5]=t7,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
/* chicken-ffi-syntax.scm:218: chicken.syntax#strip-syntax */
t10=*((C_word*)lf[12]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}

/* k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2742(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2742,c,av);}
a=C_alloc(13);
t2=C_i_check_list_2(t1,lf[6]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2748,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2802,a[2]=((C_word*)t0)[5],a[3]=t5,a[4]=((C_word*)t0)[6],a[5]=((C_word)li3),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_2802(t7,t3,t1);}

/* k2746 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2748(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_2748,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2751,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[4])){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2800,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:221: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[12]+1);{
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
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_2751(2,av2);}}}

/* k2749 in k2746 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2751(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2751,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2757,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t3=C_i_not(((C_word*)t0)[4]);
t4=(C_truep(t3)?t3:C_eqp(t1,lf[9]));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1777,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp);
t6=t2;
f_2757(t6,(
  f_1777(((C_word*)t0)[5])
));}
else{
t5=t2;
f_2757(t5,C_SCHEME_FALSE);}}

/* k2755 in k2749 in k2746 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_2757(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,1)))){
C_save_and_reclaim_args((void *)trf_2757,2,t0,t1);}
a=C_alloc(21);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(((C_word*)t0)[4])){
t2=C_a_i_list1(&a,1,((C_word*)t0)[5]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[6],t2);
t4=C_a_i_cons(&a,2,lf[7],t3);
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_list(&a,4,lf[8],t4,C_SCHEME_FALSE,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t2=C_a_i_cons(&a,2,((C_word*)t0)[6],lf[9]);
t3=C_a_i_cons(&a,2,lf[7],t2);
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,4,lf[8],t3,C_SCHEME_FALSE,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}

/* k2798 in k2746 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2800,c,av);}
/* chicken-ffi-syntax.scm:220: chicken.compiler.support#foreign-type->scrutiny-type */
t2=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[11];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* map-loop820 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_2802(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_2802,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2827,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=*((C_word*)lf[10]+1);
/* chicken-ffi-syntax.scm:217: g843 */
t6=*((C_word*)lf[10]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t3;
av2[2]=t4;
av2[3]=lf[13];
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k2825 in map-loop820 in k2740 in annotate-foreign-procedure in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2827,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_2802(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_2837,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2840,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3205,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3207,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:255: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2840(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_2840,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2843,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3109,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3111,a[2]=((C_word*)t0)[5],a[3]=((C_word)li13),tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:263: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2843(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_2843,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2846,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3081,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3083,a[2]=((C_word*)t0)[5],a[3]=((C_word)li11),tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:277: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_2846,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2849,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3009,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3011,a[2]=((C_word*)t0)[5],a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:287: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2849(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_2849,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2852,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2981,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2983,a[2]=((C_word*)t0)[5],a[3]=((C_word)li8),tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:297: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2852(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_2852,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2855,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2909,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2911,a[2]=((C_word*)t0)[5],a[3]=((C_word)li7),tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:307: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2855(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_2855,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2858,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2865,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2867,a[2]=((C_word)li5),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:317: compiler-only-er-transformer */
f_2684(t3,t4);}

/* k2856 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2858,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2861,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:332: chicken.internal#macro-subset */
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

/* k2859 in k2856 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 in ... */
static void C_ccall f_2861(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2861,c,av);}
t2=C_mutate((C_word*)lf[14]+1 /* (set! ##sys#chicken-ffi-macro-environment ...) */,t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k2863 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2865(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2865,c,av);}
/* chicken-ffi-syntax.scm:314: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[17];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a2866 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2867(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_2867,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2871,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:319: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[17];
av2[3]=t2;
av2[4]=lf[30];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k2869 in a2866 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 in ... */
static void C_ccall f_2871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_2871,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2874,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:320: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[12]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2872 in k2869 in a2866 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in ... */
static void C_ccall f_2874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2874,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2877,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:321: chicken.base#gensym */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[28];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k2875 in k2872 in k2869 in a2866 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in ... */
static void C_ccall f_2877(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2877,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2880,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_stringp(((C_word*)t0)[3]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
f_2880(2,av2);}}
else{
/* chicken-ffi-syntax.scm:326: chicken.compiler.c-backend#foreign-type-declaration */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[26];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k2878 in k2875 in k2872 in k2869 in a2866 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in ... */
static void C_ccall f_2880(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_2880,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2895,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:328: scheme#string-append */
t3=*((C_word*)lf[22]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[23];
av2[3]=t1;
av2[4]=lf[24];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k2893 in k2878 in k2875 in k2872 in k2869 in a2866 in k2853 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in ... */
static void C_ccall f_2895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,1)))){
C_save_and_reclaim((void *)f_2895,c,av);}
a=C_alloc(33);
t2=C_a_i_list(&a,4,lf[18],((C_word*)t0)[2],lf[19],t1);
t3=C_a_i_list(&a,4,lf[8],lf[20],C_SCHEME_FALSE,((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[21],t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2907 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2909(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2909,c,av);}
/* chicken-ffi-syntax.scm:304: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[31];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a2910 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2911(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_2911,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2915,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:309: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[31];
av2[3]=t2;
av2[4]=lf[33];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k2913 in a2910 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2915(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_2915,c,av);}
a=C_alloc(22);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[32],t2);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_caddr(((C_word*)t0)[2]);
t9=C_i_check_list_2(t8,lf[6]);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2935,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2941,a[2]=t6,a[3]=t12,a[4]=t7,a[5]=((C_word)li6),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_2941(t14,t10,t8);}

/* k2933 in k2913 in a2910 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 in ... */
static void C_ccall f_2935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2935,c,av);}
/* chicken-ffi-syntax.scm:310: annotate-foreign-procedure */
f_2730(((C_word*)t0)[3],((C_word*)t0)[4],t1,C_i_cadr(((C_word*)t0)[5]));}

/* map-loop976 in k2913 in a2910 in k2850 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 in ... */
static void C_fcall f_2941(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_2941,3,t0,t1,t2);}
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

/* k2979 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2981,c,av);}
/* chicken-ffi-syntax.scm:294: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[34];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a2982 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2983(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_2983,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2987,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:299: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[34];
av2[3]=t2;
av2[4]=lf[36];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k2985 in a2982 in k2847 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_2987(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_2987,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[35],t2);
t4=C_i_cdddr(((C_word*)t0)[2]);
t5=C_u_i_cdr(((C_word*)t0)[2]);
/* chicken-ffi-syntax.scm:300: annotate-foreign-procedure */
f_2730(((C_word*)t0)[4],t3,t4,C_u_i_car(t5));}

/* k3007 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3009,c,av);}
/* chicken-ffi-syntax.scm:284: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[37];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3010 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3011(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3011,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3015,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:289: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[37];
av2[3]=t2;
av2[4]=lf[39];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3013 in a3010 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3015(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_3015,c,av);}
a=C_alloc(22);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[38],t2);
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_caddr(((C_word*)t0)[2]);
t9=C_i_check_list_2(t8,lf[6]);
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3035,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3041,a[2]=t6,a[3]=t12,a[4]=t7,a[5]=((C_word)li9),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_3041(t14,t10,t8);}

/* k3033 in k3013 in a3010 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3035(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3035,c,av);}
/* chicken-ffi-syntax.scm:290: annotate-foreign-procedure */
f_2730(((C_word*)t0)[3],((C_word*)t0)[4],t1,C_i_cadr(((C_word*)t0)[5]));}

/* map-loop936 in k3013 in a3010 in k2844 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3041(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3041,3,t0,t1,t2);}
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

/* k3079 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3081(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3081,c,av);}
/* chicken-ffi-syntax.scm:274: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[40];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3082 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3083(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3083,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3087,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:279: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[40];
av2[3]=t2;
av2[4]=lf[42];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3085 in a3082 in k2841 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3087,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[41],t2);
t4=C_i_cdddr(((C_word*)t0)[2]);
t5=C_u_i_cdr(((C_word*)t0)[2]);
/* chicken-ffi-syntax.scm:280: annotate-foreign-procedure */
f_2730(((C_word*)t0)[4],t3,t4,C_u_i_car(t5));}

/* k3107 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3109,c,av);}
/* chicken-ffi-syntax.scm:260: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[43];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3110 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3111(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3111,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3115,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:265: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[43];
av2[3]=t2;
av2[4]=lf[45];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3113 in a3110 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3115,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3118,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_cddr(((C_word*)t0)[2]);
if(C_truep(C_i_pairp(t3))){
t4=C_i_caddr(((C_word*)t0)[2]);
t5=t2;
f_3118(t5,C_i_not(C_i_stringp(t4)));}
else{
t4=t2;
f_3118(t4,C_SCHEME_FALSE);}}

/* k3116 in k3113 in a3110 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3118(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,0,3)))){
C_save_and_reclaim_args((void *)trf_3118,2,t0,t1);}
a=C_alloc(19);
t2=(C_truep(t1)?C_u_i_car(C_u_i_cdr(((C_word*)t0)[2])):C_SCHEME_FALSE);
t3=(C_truep(t1)?C_i_caddr(((C_word*)t0)[2]):C_u_i_car(C_u_i_cdr(((C_word*)t0)[2])));
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_check_list_2(t3,lf[6]);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3133,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3144,a[2]=t6,a[3]=t11,a[4]=t7,a[5]=((C_word)li12),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_3144(t13,t9,t3);}

/* k3131 in k3116 in k3113 in a3110 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3133(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_3133,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[44],t2);
/* chicken-ffi-syntax.scm:270: annotate-foreign-procedure */
f_2730(((C_word*)t0)[4],t3,t1,((C_word*)t0)[5]);}

/* map-loop893 in k3116 in k3113 in a3110 in k2838 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3144(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3144,3,t0,t1,t2);}
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

/* k3203 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3205(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3205,c,av);}
/* chicken-ffi-syntax.scm:252: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[46];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3206 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3207(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3207,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3211,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:257: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[46];
av2[3]=t2;
av2[4]=lf[47];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3209 in a3206 in k2835 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3211(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3211,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[18],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3220 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3222(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3222,c,av);}
/* chicken-ffi-syntax.scm:244: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[48];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3223 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3224(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3224,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3228,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:249: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[48];
av2[3]=t2;
av2[4]=lf[50];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3226 in a3223 in k2726 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_3228,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[49],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3237 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3239(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3239,c,av);}
/* chicken-ffi-syntax.scm:205: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[51];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3240 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3241(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3241,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3245,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:210: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[51];
av2[3]=t2;
av2[4]=lf[53];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3243 in a3240 in k2723 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_3245,c,av);}
a=C_alloc(9);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[51],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[52],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k3258 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3260,c,av);}
/* chicken-ffi-syntax.scm:179: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[54];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3262(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3262,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3266,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:184: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[54];
av2[3]=t2;
av2[4]=lf[58];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3264 in a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3266,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3269,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:185: chicken.base#gensym */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[57];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3267 in k3264 in a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3269(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_3269,c,av);}
a=C_alloc(22);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3279,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t4=C_i_caddr(((C_word*)t0)[2]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3303,a[2]=t3,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_stringp(t2))){
t6=t3;
f_3279(t6,C_a_i_list(&a,4,lf[18],t1,t4,t2));}
else{
if(C_truep(C_i_symbolp(t2))){
/* chicken-ffi-syntax.scm:191: scheme#symbol->string */
t6=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
/* chicken-ffi-syntax.scm:193: chicken.syntax#syntax-error */
t6=*((C_word*)lf[1]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[54];
av2[3]=lf[56];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}}

/* k3277 in k3267 in k3264 in a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3279(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_3279,2,t0,t1);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3287,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3291,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:198: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[12]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_caddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3285 in k3277 in k3267 in k3264 in a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3287(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_3287,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,4,lf[8],t1,C_SCHEME_FALSE,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[21],((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3289 in k3277 in k3267 in k3264 in a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3291,c,av);}
/* chicken-ffi-syntax.scm:197: chicken.compiler.support#foreign-type->scrutiny-type */
t2=*((C_word*)lf[10]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[11];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* k3301 in k3267 in k3264 in a3261 in k2720 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_3303,c,av);}
a=C_alloc(12);
t2=((C_word*)t0)[2];
f_3279(t2,C_a_i_list(&a,4,lf[18],((C_word*)t0)[3],((C_word*)t0)[4],t1));}

/* k3324 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3326,c,av);}
/* chicken-ffi-syntax.scm:164: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[60];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3328(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3328,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3332,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:169: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[60];
av2[3]=t2;
av2[4]=lf[72];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3332(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3332,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3335,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:170: chicken.base#gensym */
t3=*((C_word*)lf[27]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[71];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3335,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3350,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:172: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[59];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3350(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3350,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3358,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-ffi-syntax.scm:174: chicken.base#open-output-string */
t3=*((C_word*)lf[70]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3358(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3358,c,av);}
a=C_alloc(7);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[61]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3364,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-ffi-syntax.scm:174: ##sys#print */
t4=*((C_word*)lf[64]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[69];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3364(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3364,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3367,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* chicken-ffi-syntax.scm:174: ##sys#print */
t3=*((C_word*)lf[64]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3365 in k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3367(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_3367,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3370,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* chicken-ffi-syntax.scm:174: ##sys#print */
t3=*((C_word*)lf[64]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[68];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3368 in k3365 in k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3370(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3370,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3373,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3383,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:176: chicken.string#string-intersperse */
t4=*((C_word*)lf[66]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cdr(((C_word*)t0)[6]);
av2[3]=lf[67];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3371 in k3368 in k3365 in k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3373(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_3373,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3376,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* chicken-ffi-syntax.scm:174: ##sys#print */
t3=*((C_word*)lf[64]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[65];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k3374 in k3371 in k3368 in k3365 in k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3376(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3376,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3379,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:174: chicken.base#get-output-string */
t3=*((C_word*)lf[63]+1);{
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

/* k3377 in k3374 in k3371 in k3368 in k3365 in k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 in ... */
static void C_ccall f_3379(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,1)))){
C_save_and_reclaim((void *)f_3379,c,av);}
a=C_alloc(27);
t2=C_a_i_list(&a,2,lf[51],t1);
t3=C_a_i_list(&a,2,((C_word*)t0)[2],t2);
t4=C_a_i_list(&a,2,lf[62],((C_word*)t0)[3]);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[21],t3,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k3381 in k3368 in k3365 in k3362 in k3356 in k3348 in k3333 in k3330 in a3327 in k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3383(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3383,c,av);}
/* chicken-ffi-syntax.scm:174: ##sys#print */
t2=*((C_word*)lf[64]+1);{
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

/* k3393 in k2717 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_3395,c,av);}
a=C_alloc(13);
t2=C_a_i_cons(&a,2,lf[59],t1);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3326,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3328,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:167: compiler-only-er-transformer */
f_2684(t4,t5);}

/* k3397 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3399(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3399,c,av);}
/* chicken-ffi-syntax.scm:128: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[74];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3401(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3401,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3405,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:133: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[74];
av2[3]=t2;
av2[4]=lf[79];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3405(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(23,c,3)))){
C_save_and_reclaim((void *)f_3405,c,av);}
a=C_alloc(23);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3414,a[2]=((C_word*)t0)[3],a[3]=((C_word)li19),tmp=(C_word)a,a+=4,tmp);
t10=C_i_check_list_2(t2,lf[6]);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3428,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3526,a[2]=t7,a[3]=t13,a[4]=t9,a[5]=t8,a[6]=((C_word)li28),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_3526(t15,t11,t2);}

/* g726 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3414(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_3414,2,t0,t1);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3422,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:136: chicken.base#gensym */
t3=*((C_word*)lf[27]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3420 in g726 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3422(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3422,c,av);}
/* chicken-ffi-syntax.scm:136: r */
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

/* k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3428(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(22,c,4)))){
C_save_and_reclaim((void *)f_3428,c,av);}
a=C_alloc(22);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3435,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3503,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp);
t4=C_a_i_list(&a,1,t1);
if(C_truep(C_i_nullp(t4))){
t5=C_i_check_list_2(((C_word*)t0)[4],lf[77]);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1616,a[2]=t3,a[3]=t7,a[4]=((C_word)li23),tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_1616(t9,t2,((C_word*)t0)[4]);}
else{
t5=C_a_i_cons(&a,2,((C_word*)t0)[4],t4);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1656,a[2]=t7,a[3]=t3,a[4]=((C_word)li27),tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_1656(t9,t2,t5);}}

/* k3433 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3435(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3435,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3439,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3441,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=((C_word)li20),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_3441(t6,t2,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k3437 in k3433 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3439(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_3439,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[75],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop in k3433 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3441(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_3441,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,lf[75],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_i_car(t3);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3464,a[2]=t4,a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:149: loop */
t8=t6;
t9=C_u_i_cdr(t2);
t10=C_u_i_cdr(t3);
t1=t8;
t2=t9;
t3=t10;
goto loop;}}

/* k3462 in loop in k3433 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_3464,c,av);}
a=C_alloc(15);
t2=C_i_length(((C_word*)t0)[2]);
t3=C_eqp(C_fix(3),t2);
if(C_truep(t3)){
t4=C_i_car(((C_word*)t0)[2]);
t5=C_i_cadr(((C_word*)t0)[2]);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,5,lf[76],t4,t5,((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t4=C_i_car(((C_word*)t0)[2]);
t5=C_i_cadr(((C_word*)t0)[2]);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,4,lf[76],t4,t5,t1);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* a3502 in k3426 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3503(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_3503,c,av);}
a=C_alloc(6);
t4=C_i_cddr(t2);
if(C_truep(C_i_pairp(t4))){
t5=C_u_i_cdr(t2);
t6=C_u_i_cdr(t5);
t7=C_a_i_cons(&a,2,t3,t6);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list1(&a,1,t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* map-loop720 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3526(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_3526,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3551,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* chicken-ffi-syntax.scm:136: g726 */
t4=((C_word*)t0)[4];
f_3414(t4,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k3549 in map-loop720 in k3403 in a3400 in k2714 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_3551,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_3526(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k3564 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3566,c,av);}
/* chicken-ffi-syntax.scm:111: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[81];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3567 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3568(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3568,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3572,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:116: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[81];
av2[3]=t2;
av2[4]=lf[84];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3570 in a3567 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3572(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3572,c,av);}
a=C_alloc(11);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=C_u_i_cdr(t5);
t7=C_i_nullp(t6);
t8=(C_truep(t7)?C_SCHEME_FALSE:C_i_car(t6));
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3587,a[2]=t2,a[3]=t3,a[4]=t8,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3634,a[2]=((C_word*)t0)[4],a[3]=t9,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:120: chicken.base#gensym */
t11=*((C_word*)lf[27]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}

/* k3585 in k3570 in a3567 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3587,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* chicken-ffi-syntax.scm:121: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[80];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}

/* k3592 in k3585 in k3570 in a3567 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3594,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3630,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* chicken-ffi-syntax.scm:122: scheme#symbol->string */
t3=*((C_word*)lf[55]+1);{
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

/* k3628 in k3592 in k3585 in k3570 in a3567 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3630(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(48,c,1)))){
C_save_and_reclaim((void *)f_3630,c,av);}
a=C_alloc(48);
t2=C_a_i_list(&a,4,lf[18],((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=C_a_i_list(&a,5,lf[82],((C_word*)t0)[2],((C_word*)t0)[3],C_SCHEME_FALSE,((C_word*)t0)[4]);
if(C_truep(C_i_pairp(((C_word*)t0)[5]))){
t4=C_u_i_car(((C_word*)t0)[5]);
t5=C_a_i_list(&a,3,lf[83],((C_word*)t0)[2],t4);
t6=C_a_i_list(&a,1,t5);
t7=C_a_i_cons(&a,2,t3,t6);
t8=C_a_i_cons(&a,2,t2,t7);
t9=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[7],t8);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t4=C_a_i_cons(&a,2,t3,C_SCHEME_END_OF_LIST);
t5=C_a_i_cons(&a,2,t2,t4);
t6=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[7],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k3632 in k3570 in a3567 in k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_3634,c,av);}
/* chicken-ffi-syntax.scm:120: r */
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

/* k3646 in k2711 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3648(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_3648,c,av);}
a=C_alloc(13);
t2=C_a_i_cons(&a,2,lf[80],t1);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3566,a[2]=((C_word*)t0)[2],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3568,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:114: compiler-only-er-transformer */
f_2684(t4,t5);}

/* k3650 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3652(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3652,c,av);}
/* chicken-ffi-syntax.scm:103: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[85];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3653 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3654(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_3654,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3658,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* chicken-ffi-syntax.scm:108: ##sys#check-syntax */
t6=*((C_word*)lf[29]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[85];
av2[3]=t2;
av2[4]=lf[87];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k3656 in a3653 in k2708 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_3658,c,av);}
a=C_alloc(6);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[86],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3671 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3673(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3673,c,av);}
/* chicken-ffi-syntax.scm:64: ##sys#extend-macro-environment */
t2=*((C_word*)lf[16]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[90];
av2[3]=((C_word*)t0)[3];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3675(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_3675,c,av);}
a=C_alloc(6);
t5=C_i_cdr(t2);
t6=C_i_pairp(t5);
t7=(C_truep(t6)?C_i_stringp(C_u_i_car(t5)):C_SCHEME_FALSE);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3685,a[2]=t5,a[3]=t1,a[4]=t3,a[5]=t7,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_not(t7))){
t9=C_i_pairp(t5);
t10=t8;
f_3685(t10,(C_truep(t9)?C_i_symbolp(C_u_i_car(t5)):C_SCHEME_FALSE));}
else{
t9=t8;
f_3685(t9,C_SCHEME_FALSE);}}

/* k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3685(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_3685,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3691,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:75: ##sys#check-syntax */
t3=*((C_word*)lf[29]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[90];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[91];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3748,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[5])){
/* chicken-ffi-syntax.scm:85: ##sys#check-syntax */
t3=*((C_word*)lf[29]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[90];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[95];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
/* chicken-ffi-syntax.scm:86: ##sys#check-syntax */
t3=*((C_word*)lf[29]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[90];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[96];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}}

/* k3689 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_3691,c,av);}
a=C_alloc(5);
t2=C_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3701,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* chicken-ffi-syntax.scm:77: r */
t4=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[80];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k3699 in k3689 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3701(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,1)))){
C_save_and_reclaim((void *)f_3701,c,av);}
a=C_alloc(42);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,lf[18],((C_word*)t0)[3],t2);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_car(t4);
t6=C_a_i_list(&a,4,lf[82],((C_word*)t0)[3],t5,C_SCHEME_TRUE);
t7=C_u_i_cdr(((C_word*)t0)[2]);
if(C_truep(C_i_pairp(C_u_i_cdr(t7)))){
t8=C_i_caddr(((C_word*)t0)[2]);
t9=C_a_i_list(&a,3,lf[83],((C_word*)t0)[3],t8);
t10=C_a_i_list(&a,1,t9);
t11=C_a_i_cons(&a,2,t6,t10);
t12=C_a_i_cons(&a,2,t3,t11);
t13=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t13;
av2[1]=C_a_i_cons(&a,2,t1,t12);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}
else{
t8=C_a_i_cons(&a,2,t6,C_SCHEME_END_OF_LIST);
t9=C_a_i_cons(&a,2,t3,t8);
t10=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_a_i_cons(&a,2,t1,t9);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}

/* k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3748(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_3748,c,av);}
a=C_alloc(8);
t2=(C_truep(((C_word*)t0)[2])?C_i_cadr(((C_word*)t0)[3]):C_i_car(((C_word*)t0)[3]));
t3=C_i_cdr(t2);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3761,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t3,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
/* chicken-ffi-syntax.scm:89: r */
t5=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[88];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k3759 in k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3761(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(37,c,3)))){
C_save_and_reclaim((void *)f_3761,c,av);}
a=C_alloc(37);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_a_i_list(&a,2,lf[92],t3);
t5=(C_truep(((C_word*)t0)[3])?C_i_car(((C_word*)t0)[4]):lf[93]);
t6=(C_truep(((C_word*)t0)[3])?C_i_caddr(((C_word*)t0)[4]):C_i_cadr(((C_word*)t0)[4]));
t7=C_a_i_list(&a,2,lf[92],t6);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=C_i_check_list_2(((C_word*)t0)[5],lf[6]);
t13=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3866,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=t5,a[6]=t7,a[7]=((C_word*)t0)[6],a[8]=t1,a[9]=t2,a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[7],tmp=(C_word)a,a+=12,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3868,a[2]=t10,a[3]=t15,a[4]=t11,a[5]=((C_word)li33),tmp=(C_word)a,a+=6,tmp));
t17=((C_word*)t15)[1];
f_3868(t17,t13,((C_word*)t0)[5]);}

/* k3789 in k3864 in k3759 in k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3791(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,3)))){
C_save_and_reclaim((void *)f_3791,c,av);}
a=C_alloc(25);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3807,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3819,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li32),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_3819(t10,t6,((C_word*)t0)[11]);}

/* k3805 in k3789 in k3864 in k3759 in k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(33,c,1)))){
C_save_and_reclaim((void *)f_3807,c,av);}
a=C_alloc(33);
t2=(C_truep(((C_word*)t0)[2])?C_i_cdddr(((C_word*)t0)[3]):C_i_cddr(((C_word*)t0)[3]));
t3=C_a_i_cons(&a,2,t1,t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
t5=C_a_i_list(&a,6,lf[94],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[8],t4);
t6=((C_word*)t0)[9];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,((C_word*)t0)[10],((C_word*)t0)[11],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* map-loop658 in k3789 in k3864 in k3759 in k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3819(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3819,3,t0,t1,t2);}
a=C_alloc(3);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_cadr(t3);
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

/* k3864 in k3759 in k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_3866,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,2,lf[92],t1);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3791,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t2,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* chicken-ffi-syntax.scm:95: r */
t4=((C_word*)t0)[11];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[89];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* map-loop631 in k3759 in k3746 in k3683 in a3674 in k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_fcall f_3868(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_3868,3,t0,t1,t2);}
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

/* k3963 in k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3965(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,5)))){
C_save_and_reclaim((void *)f_3965,c,av);}
a=C_alloc(19);
t2=C_a_i_cons(&a,2,lf[89],t1);
t3=C_a_i_list(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3673,a[2]=((C_word*)t0)[4],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3675,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp);
/* chicken-ffi-syntax.scm:69: compiler-only-er-transformer */
f_2684(t4,t5);}

/* k3967 in k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3969(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3969,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,lf[80],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3965,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-ffi-syntax.scm:68: chicken.base#alist-ref */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[89];
av2[3]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3971 in k2680 in k1398 in k1395 in k1392 in k1389 in k1386 */
static void C_ccall f_3973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_3973,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,lf[88],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3969,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* chicken-ffi-syntax.scm:67: chicken.base#alist-ref */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[80];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_chicken_2dffi_2dsyntax_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("chicken-ffi-syntax"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_chicken_2dffi_2dsyntax_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(1118))){
C_save(t1);
C_rereclaim2(1118*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,98);
lf[0]=C_h_intern(&lf[0],18, C_text("chicken-ffi-syntax"));
lf[1]=C_h_intern(&lf[1],27, C_text("chicken.syntax#syntax-error"));
lf[2]=C_decode_literal(C_heaptop,C_text("\376B\000\000,The FFI is not supported in interpreted mode"));
lf[3]=C_h_intern(&lf[3],25, C_text("chicken.platform#feature\077"));
lf[4]=C_h_intern(&lf[4],9, C_text("compiling"));
lf[5]=C_h_intern(&lf[5],20, C_text("##sys#er-transformer"));
lf[6]=C_h_intern(&lf[6],3, C_text("map"));
lf[7]=C_h_intern(&lf[7],9, C_text("procedure"));
lf[8]=C_h_intern(&lf[8],10, C_text("##core#the"));
lf[9]=C_h_intern(&lf[9],1, C_text("\052"));
lf[10]=C_h_intern(&lf[10],52, C_text("chicken.compiler.support#foreign-type->scrutiny-type"));
lf[11]=C_h_intern(&lf[11],6, C_text("result"));
lf[12]=C_h_intern(&lf[12],27, C_text("chicken.syntax#strip-syntax"));
lf[13]=C_h_intern(&lf[13],3, C_text("arg"));
lf[14]=C_h_intern(&lf[14],35, C_text("##sys#chicken-ffi-macro-environment"));
lf[15]=C_h_intern(&lf[15],29, C_text("chicken.internal#macro-subset"));
lf[16]=C_h_intern(&lf[16],30, C_text("##sys#extend-macro-environment"));
lf[17]=C_h_intern(&lf[17],17, C_text("foreign-type-size"));
lf[18]=C_h_intern(&lf[18],30, C_text("##core#define-foreign-variable"));
lf[19]=C_h_intern(&lf[19],6, C_text("size_t"));
lf[20]=C_h_intern(&lf[20],6, C_text("fixnum"));
lf[21]=C_h_intern(&lf[21],12, C_text("##core#begin"));
lf[22]=C_h_intern(&lf[22],20, C_text("scheme#string-append"));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007sizeof("));
lf[24]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001)"));
lf[25]=C_h_intern(&lf[25],51, C_text("chicken.compiler.c-backend#foreign-type-declaration"));
lf[26]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[27]=C_h_intern(&lf[27],19, C_text("chicken.base#gensym"));
lf[28]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005code_"));
lf[29]=C_h_intern(&lf[29],18, C_text("##sys#check-syntax"));
lf[30]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[31]=C_h_intern(&lf[31],20, C_text("foreign-safe-lambda\052"));
lf[32]=C_h_intern(&lf[32],27, C_text("##core#foreign-safe-lambda\052"));
lf[33]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[34]=C_h_intern(&lf[34],19, C_text("foreign-safe-lambda"));
lf[35]=C_h_intern(&lf[35],26, C_text("##core#foreign-safe-lambda"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[37]=C_h_intern(&lf[37],15, C_text("foreign-lambda\052"));
lf[38]=C_h_intern(&lf[38],22, C_text("##core#foreign-lambda\052"));
lf[39]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[40]=C_h_intern(&lf[40],14, C_text("foreign-lambda"));
lf[41]=C_h_intern(&lf[41],21, C_text("##core#foreign-lambda"));
lf[42]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[43]=C_h_intern(&lf[43],17, C_text("foreign-primitive"));
lf[44]=C_h_intern(&lf[44],24, C_text("##core#foreign-primitive"));
lf[45]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\001\001_"));
lf[46]=C_h_intern(&lf[46],23, C_text("define-foreign-variable"));
lf[47]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001symbol\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\006\001string\376\377\001\000\000\000\000\376\377\001\000\000\000\001"));
lf[48]=C_h_intern(&lf[48],19, C_text("define-foreign-type"));
lf[49]=C_h_intern(&lf[49],26, C_text("##core#define-foreign-type"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001symbol\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\001\000\000\000\002"));
lf[51]=C_h_intern(&lf[51],15, C_text("foreign-declare"));
lf[52]=C_h_intern(&lf[52],14, C_text("##core#declare"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\006\001string\376\377\001\000\000\000\000"));
lf[54]=C_h_intern(&lf[54],13, C_text("foreign-value"));
lf[55]=C_h_intern(&lf[55],21, C_text("scheme#symbol->string"));
lf[56]=C_decode_literal(C_heaptop,C_text("\376B\000\000\052bad argument type - not a string or symbol"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005code_"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[59]=C_h_intern(&lf[59],7, C_text("declare"));
lf[60]=C_h_intern(&lf[60],12, C_text("foreign-code"));
lf[61]=C_h_intern(&lf[61],6, C_text("format"));
lf[62]=C_h_intern(&lf[62],13, C_text("##core#inline"));
lf[63]=C_h_intern(&lf[63],30, C_text("chicken.base#get-output-string"));
lf[64]=C_h_intern(&lf[64],11, C_text("##sys#print"));
lf[65]=C_decode_literal(C_heaptop,C_text("\376B\000\000 \012; return C_SCHEME_UNDEFINED; }\012"));
lf[66]=C_h_intern(&lf[66],33, C_text("chicken.string#string-intersperse"));
lf[67]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[68]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005() { "));
lf[69]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016static C_word "));
lf[70]=C_h_intern(&lf[70],31, C_text("chicken.base#open-output-string"));
lf[71]=C_h_intern(&lf[71],5, C_text("code_"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\006\001string\376\377\001\000\000\000\000"));
lf[73]=C_h_intern(&lf[73],22, C_text("chicken.base#alist-ref"));
lf[74]=C_h_intern(&lf[74],12, C_text("let-location"));
lf[75]=C_h_intern(&lf[75],10, C_text("##core#let"));
lf[76]=C_h_intern(&lf[76],19, C_text("##core#let-location"));
lf[77]=C_h_intern(&lf[77],5, C_text("foldr"));
lf[78]=C_h_intern(&lf[78],13, C_text("scheme#append"));
lf[79]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\001\000\000\000\001\376"
"\377\001\000\000\000\000\376\001\000\000\001\001_"));
lf[80]=C_h_intern(&lf[80],5, C_text("begin"));
lf[81]=C_h_intern(&lf[81],15, C_text("define-location"));
lf[82]=C_h_intern(&lf[82],31, C_text("##core#define-external-variable"));
lf[83]=C_h_intern(&lf[83],11, C_text("##core#set!"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\001\000\000\000\001"));
lf[85]=C_h_intern(&lf[85],8, C_text("location"));
lf[86]=C_h_intern(&lf[86],15, C_text("##core#location"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\010\001location\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[88]=C_h_intern(&lf[88],6, C_text("define"));
lf[89]=C_h_intern(&lf[89],6, C_text("lambda"));
lf[90]=C_h_intern(&lf[90],15, C_text("define-external"));
lf[91]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001symbol\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\003\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\001\000\000\000\001"));
lf[92]=C_h_intern(&lf[92],12, C_text("##core#quote"));
lf[93]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[94]=C_h_intern(&lf[94],31, C_text("##core#foreign-callback-wrapper"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\006\001string\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001symbol\376\000\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016\376\377\001\000"
"\000\000\000\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[96]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\006\001symbol\376\000\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\006\001symbol\376\377\016\376\377\001\000\000\000\000\376\003\000\000\002\376\001\000\000\001\001_\376\000"
"\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[97]=C_h_intern(&lf[97],23, C_text("##sys#macro-environment"));
C_register_lf2(lf,98,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1388,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[147] = {
{C_text("f_1388:chicken_2dffi_2dsyntax_2escm"),(void*)f_1388},
{C_text("f_1391:chicken_2dffi_2dsyntax_2escm"),(void*)f_1391},
{C_text("f_1394:chicken_2dffi_2dsyntax_2escm"),(void*)f_1394},
{C_text("f_1397:chicken_2dffi_2dsyntax_2escm"),(void*)f_1397},
{C_text("f_1400:chicken_2dffi_2dsyntax_2escm"),(void*)f_1400},
{C_text("f_1616:chicken_2dffi_2dsyntax_2escm"),(void*)f_1616},
{C_text("f_1624:chicken_2dffi_2dsyntax_2escm"),(void*)f_1624},
{C_text("f_1632:chicken_2dffi_2dsyntax_2escm"),(void*)f_1632},
{C_text("f_1643:chicken_2dffi_2dsyntax_2escm"),(void*)f_1643},
{C_text("f_1656:chicken_2dffi_2dsyntax_2escm"),(void*)f_1656},
{C_text("f_1670:chicken_2dffi_2dsyntax_2escm"),(void*)f_1670},
{C_text("f_1674:chicken_2dffi_2dsyntax_2escm"),(void*)f_1674},
{C_text("f_1686:chicken_2dffi_2dsyntax_2escm"),(void*)f_1686},
{C_text("f_1688:chicken_2dffi_2dsyntax_2escm"),(void*)f_1688},
{C_text("f_1735:chicken_2dffi_2dsyntax_2escm"),(void*)f_1735},
{C_text("f_1737:chicken_2dffi_2dsyntax_2escm"),(void*)f_1737},
{C_text("f_1777:chicken_2dffi_2dsyntax_2escm"),(void*)f_1777},
{C_text("f_1811:chicken_2dffi_2dsyntax_2escm"),(void*)f_1811},
{C_text("f_2682:chicken_2dffi_2dsyntax_2escm"),(void*)f_2682},
{C_text("f_2684:chicken_2dffi_2dsyntax_2escm"),(void*)f_2684},
{C_text("f_2690:chicken_2dffi_2dsyntax_2escm"),(void*)f_2690},
{C_text("f_2697:chicken_2dffi_2dsyntax_2escm"),(void*)f_2697},
{C_text("f_2710:chicken_2dffi_2dsyntax_2escm"),(void*)f_2710},
{C_text("f_2713:chicken_2dffi_2dsyntax_2escm"),(void*)f_2713},
{C_text("f_2716:chicken_2dffi_2dsyntax_2escm"),(void*)f_2716},
{C_text("f_2719:chicken_2dffi_2dsyntax_2escm"),(void*)f_2719},
{C_text("f_2722:chicken_2dffi_2dsyntax_2escm"),(void*)f_2722},
{C_text("f_2725:chicken_2dffi_2dsyntax_2escm"),(void*)f_2725},
{C_text("f_2728:chicken_2dffi_2dsyntax_2escm"),(void*)f_2728},
{C_text("f_2730:chicken_2dffi_2dsyntax_2escm"),(void*)f_2730},
{C_text("f_2742:chicken_2dffi_2dsyntax_2escm"),(void*)f_2742},
{C_text("f_2748:chicken_2dffi_2dsyntax_2escm"),(void*)f_2748},
{C_text("f_2751:chicken_2dffi_2dsyntax_2escm"),(void*)f_2751},
{C_text("f_2757:chicken_2dffi_2dsyntax_2escm"),(void*)f_2757},
{C_text("f_2800:chicken_2dffi_2dsyntax_2escm"),(void*)f_2800},
{C_text("f_2802:chicken_2dffi_2dsyntax_2escm"),(void*)f_2802},
{C_text("f_2827:chicken_2dffi_2dsyntax_2escm"),(void*)f_2827},
{C_text("f_2837:chicken_2dffi_2dsyntax_2escm"),(void*)f_2837},
{C_text("f_2840:chicken_2dffi_2dsyntax_2escm"),(void*)f_2840},
{C_text("f_2843:chicken_2dffi_2dsyntax_2escm"),(void*)f_2843},
{C_text("f_2846:chicken_2dffi_2dsyntax_2escm"),(void*)f_2846},
{C_text("f_2849:chicken_2dffi_2dsyntax_2escm"),(void*)f_2849},
{C_text("f_2852:chicken_2dffi_2dsyntax_2escm"),(void*)f_2852},
{C_text("f_2855:chicken_2dffi_2dsyntax_2escm"),(void*)f_2855},
{C_text("f_2858:chicken_2dffi_2dsyntax_2escm"),(void*)f_2858},
{C_text("f_2861:chicken_2dffi_2dsyntax_2escm"),(void*)f_2861},
{C_text("f_2865:chicken_2dffi_2dsyntax_2escm"),(void*)f_2865},
{C_text("f_2867:chicken_2dffi_2dsyntax_2escm"),(void*)f_2867},
{C_text("f_2871:chicken_2dffi_2dsyntax_2escm"),(void*)f_2871},
{C_text("f_2874:chicken_2dffi_2dsyntax_2escm"),(void*)f_2874},
{C_text("f_2877:chicken_2dffi_2dsyntax_2escm"),(void*)f_2877},
{C_text("f_2880:chicken_2dffi_2dsyntax_2escm"),(void*)f_2880},
{C_text("f_2895:chicken_2dffi_2dsyntax_2escm"),(void*)f_2895},
{C_text("f_2909:chicken_2dffi_2dsyntax_2escm"),(void*)f_2909},
{C_text("f_2911:chicken_2dffi_2dsyntax_2escm"),(void*)f_2911},
{C_text("f_2915:chicken_2dffi_2dsyntax_2escm"),(void*)f_2915},
{C_text("f_2935:chicken_2dffi_2dsyntax_2escm"),(void*)f_2935},
{C_text("f_2941:chicken_2dffi_2dsyntax_2escm"),(void*)f_2941},
{C_text("f_2981:chicken_2dffi_2dsyntax_2escm"),(void*)f_2981},
{C_text("f_2983:chicken_2dffi_2dsyntax_2escm"),(void*)f_2983},
{C_text("f_2987:chicken_2dffi_2dsyntax_2escm"),(void*)f_2987},
{C_text("f_3009:chicken_2dffi_2dsyntax_2escm"),(void*)f_3009},
{C_text("f_3011:chicken_2dffi_2dsyntax_2escm"),(void*)f_3011},
{C_text("f_3015:chicken_2dffi_2dsyntax_2escm"),(void*)f_3015},
{C_text("f_3035:chicken_2dffi_2dsyntax_2escm"),(void*)f_3035},
{C_text("f_3041:chicken_2dffi_2dsyntax_2escm"),(void*)f_3041},
{C_text("f_3081:chicken_2dffi_2dsyntax_2escm"),(void*)f_3081},
{C_text("f_3083:chicken_2dffi_2dsyntax_2escm"),(void*)f_3083},
{C_text("f_3087:chicken_2dffi_2dsyntax_2escm"),(void*)f_3087},
{C_text("f_3109:chicken_2dffi_2dsyntax_2escm"),(void*)f_3109},
{C_text("f_3111:chicken_2dffi_2dsyntax_2escm"),(void*)f_3111},
{C_text("f_3115:chicken_2dffi_2dsyntax_2escm"),(void*)f_3115},
{C_text("f_3118:chicken_2dffi_2dsyntax_2escm"),(void*)f_3118},
{C_text("f_3133:chicken_2dffi_2dsyntax_2escm"),(void*)f_3133},
{C_text("f_3144:chicken_2dffi_2dsyntax_2escm"),(void*)f_3144},
{C_text("f_3205:chicken_2dffi_2dsyntax_2escm"),(void*)f_3205},
{C_text("f_3207:chicken_2dffi_2dsyntax_2escm"),(void*)f_3207},
{C_text("f_3211:chicken_2dffi_2dsyntax_2escm"),(void*)f_3211},
{C_text("f_3222:chicken_2dffi_2dsyntax_2escm"),(void*)f_3222},
{C_text("f_3224:chicken_2dffi_2dsyntax_2escm"),(void*)f_3224},
{C_text("f_3228:chicken_2dffi_2dsyntax_2escm"),(void*)f_3228},
{C_text("f_3239:chicken_2dffi_2dsyntax_2escm"),(void*)f_3239},
{C_text("f_3241:chicken_2dffi_2dsyntax_2escm"),(void*)f_3241},
{C_text("f_3245:chicken_2dffi_2dsyntax_2escm"),(void*)f_3245},
{C_text("f_3260:chicken_2dffi_2dsyntax_2escm"),(void*)f_3260},
{C_text("f_3262:chicken_2dffi_2dsyntax_2escm"),(void*)f_3262},
{C_text("f_3266:chicken_2dffi_2dsyntax_2escm"),(void*)f_3266},
{C_text("f_3269:chicken_2dffi_2dsyntax_2escm"),(void*)f_3269},
{C_text("f_3279:chicken_2dffi_2dsyntax_2escm"),(void*)f_3279},
{C_text("f_3287:chicken_2dffi_2dsyntax_2escm"),(void*)f_3287},
{C_text("f_3291:chicken_2dffi_2dsyntax_2escm"),(void*)f_3291},
{C_text("f_3303:chicken_2dffi_2dsyntax_2escm"),(void*)f_3303},
{C_text("f_3326:chicken_2dffi_2dsyntax_2escm"),(void*)f_3326},
{C_text("f_3328:chicken_2dffi_2dsyntax_2escm"),(void*)f_3328},
{C_text("f_3332:chicken_2dffi_2dsyntax_2escm"),(void*)f_3332},
{C_text("f_3335:chicken_2dffi_2dsyntax_2escm"),(void*)f_3335},
{C_text("f_3350:chicken_2dffi_2dsyntax_2escm"),(void*)f_3350},
{C_text("f_3358:chicken_2dffi_2dsyntax_2escm"),(void*)f_3358},
{C_text("f_3364:chicken_2dffi_2dsyntax_2escm"),(void*)f_3364},
{C_text("f_3367:chicken_2dffi_2dsyntax_2escm"),(void*)f_3367},
{C_text("f_3370:chicken_2dffi_2dsyntax_2escm"),(void*)f_3370},
{C_text("f_3373:chicken_2dffi_2dsyntax_2escm"),(void*)f_3373},
{C_text("f_3376:chicken_2dffi_2dsyntax_2escm"),(void*)f_3376},
{C_text("f_3379:chicken_2dffi_2dsyntax_2escm"),(void*)f_3379},
{C_text("f_3383:chicken_2dffi_2dsyntax_2escm"),(void*)f_3383},
{C_text("f_3395:chicken_2dffi_2dsyntax_2escm"),(void*)f_3395},
{C_text("f_3399:chicken_2dffi_2dsyntax_2escm"),(void*)f_3399},
{C_text("f_3401:chicken_2dffi_2dsyntax_2escm"),(void*)f_3401},
{C_text("f_3405:chicken_2dffi_2dsyntax_2escm"),(void*)f_3405},
{C_text("f_3414:chicken_2dffi_2dsyntax_2escm"),(void*)f_3414},
{C_text("f_3422:chicken_2dffi_2dsyntax_2escm"),(void*)f_3422},
{C_text("f_3428:chicken_2dffi_2dsyntax_2escm"),(void*)f_3428},
{C_text("f_3435:chicken_2dffi_2dsyntax_2escm"),(void*)f_3435},
{C_text("f_3439:chicken_2dffi_2dsyntax_2escm"),(void*)f_3439},
{C_text("f_3441:chicken_2dffi_2dsyntax_2escm"),(void*)f_3441},
{C_text("f_3464:chicken_2dffi_2dsyntax_2escm"),(void*)f_3464},
{C_text("f_3503:chicken_2dffi_2dsyntax_2escm"),(void*)f_3503},
{C_text("f_3526:chicken_2dffi_2dsyntax_2escm"),(void*)f_3526},
{C_text("f_3551:chicken_2dffi_2dsyntax_2escm"),(void*)f_3551},
{C_text("f_3566:chicken_2dffi_2dsyntax_2escm"),(void*)f_3566},
{C_text("f_3568:chicken_2dffi_2dsyntax_2escm"),(void*)f_3568},
{C_text("f_3572:chicken_2dffi_2dsyntax_2escm"),(void*)f_3572},
{C_text("f_3587:chicken_2dffi_2dsyntax_2escm"),(void*)f_3587},
{C_text("f_3594:chicken_2dffi_2dsyntax_2escm"),(void*)f_3594},
{C_text("f_3630:chicken_2dffi_2dsyntax_2escm"),(void*)f_3630},
{C_text("f_3634:chicken_2dffi_2dsyntax_2escm"),(void*)f_3634},
{C_text("f_3648:chicken_2dffi_2dsyntax_2escm"),(void*)f_3648},
{C_text("f_3652:chicken_2dffi_2dsyntax_2escm"),(void*)f_3652},
{C_text("f_3654:chicken_2dffi_2dsyntax_2escm"),(void*)f_3654},
{C_text("f_3658:chicken_2dffi_2dsyntax_2escm"),(void*)f_3658},
{C_text("f_3673:chicken_2dffi_2dsyntax_2escm"),(void*)f_3673},
{C_text("f_3675:chicken_2dffi_2dsyntax_2escm"),(void*)f_3675},
{C_text("f_3685:chicken_2dffi_2dsyntax_2escm"),(void*)f_3685},
{C_text("f_3691:chicken_2dffi_2dsyntax_2escm"),(void*)f_3691},
{C_text("f_3701:chicken_2dffi_2dsyntax_2escm"),(void*)f_3701},
{C_text("f_3748:chicken_2dffi_2dsyntax_2escm"),(void*)f_3748},
{C_text("f_3761:chicken_2dffi_2dsyntax_2escm"),(void*)f_3761},
{C_text("f_3791:chicken_2dffi_2dsyntax_2escm"),(void*)f_3791},
{C_text("f_3807:chicken_2dffi_2dsyntax_2escm"),(void*)f_3807},
{C_text("f_3819:chicken_2dffi_2dsyntax_2escm"),(void*)f_3819},
{C_text("f_3866:chicken_2dffi_2dsyntax_2escm"),(void*)f_3866},
{C_text("f_3868:chicken_2dffi_2dsyntax_2escm"),(void*)f_3868},
{C_text("f_3965:chicken_2dffi_2dsyntax_2escm"),(void*)f_3965},
{C_text("f_3969:chicken_2dffi_2dsyntax_2escm"),(void*)f_3969},
{C_text("f_3973:chicken_2dffi_2dsyntax_2escm"),(void*)f_3973},
{C_text("toplevel:chicken_2dffi_2dsyntax_2escm"),(void*)C_chicken_2dffi_2dsyntax_toplevel},
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
S|applied compiler syntax:
S|  chicken.format#sprintf		1
S|  chicken.base#foldl		3
S|  scheme#map		10
S|  chicken.base#foldr		3
o|eliminated procedure checks: 128 
o|specializations:
o|  1 (##sys#check-output-port * * *)
o|  1 (scheme#= fixnum fixnum)
o|  1 (scheme#cdddr (pair * (pair * pair)))
o|  3 (scheme#cddr (pair * pair))
o|  5 (scheme#cadr (pair * pair))
o|  1 (scheme#eqv? * *)
o|  4 (##sys#check-list (or pair list) *)
o|  25 (scheme#cdr pair)
o|  12 (scheme#car pair)
(o e)|safe calls: 389 
o|safe globals: (posv posq make-list iota find-tail find length+ lset=/eq? lset<=/eq? list-tabulate lset-intersection/eq? lset-union/eq? lset-difference/eq? lset-adjoin/eq? list-index last unzip1 remove filter-map filter alist-cons delete-duplicates fifth fourth third second first delete concatenate cons* any every append-map split-at drop take span partition) 
o|removed side-effect free assignment to unused variable: partition 
o|removed side-effect free assignment to unused variable: span 
o|removed side-effect free assignment to unused variable: drop 
o|removed side-effect free assignment to unused variable: split-at 
o|inlining procedure: k1782 
o|inlining procedure: k1782 
o|inlining procedure: k1813 
o|inlining procedure: k1813 
o|removed side-effect free assignment to unused variable: cons* 
o|removed side-effect free assignment to unused variable: concatenate 
o|removed side-effect free assignment to unused variable: first 
o|removed side-effect free assignment to unused variable: second 
o|removed side-effect free assignment to unused variable: third 
o|removed side-effect free assignment to unused variable: fourth 
o|removed side-effect free assignment to unused variable: fifth 
o|removed side-effect free assignment to unused variable: delete-duplicates 
o|removed side-effect free assignment to unused variable: alist-cons 
o|inlining procedure: k2030 
o|inlining procedure: k2030 
o|inlining procedure: k2022 
o|inlining procedure: k2022 
o|removed side-effect free assignment to unused variable: filter-map 
o|removed side-effect free assignment to unused variable: remove 
o|removed side-effect free assignment to unused variable: unzip1 
o|removed side-effect free assignment to unused variable: last 
o|removed side-effect free assignment to unused variable: list-index 
o|removed side-effect free assignment to unused variable: lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: lset-difference/eq? 
o|removed side-effect free assignment to unused variable: lset-union/eq? 
o|removed side-effect free assignment to unused variable: lset-intersection/eq? 
o|inlining procedure: k2421 
o|inlining procedure: k2421 
o|removed side-effect free assignment to unused variable: lset<=/eq? 
o|removed side-effect free assignment to unused variable: lset=/eq? 
o|removed side-effect free assignment to unused variable: length+ 
o|removed side-effect free assignment to unused variable: find 
o|removed side-effect free assignment to unused variable: find-tail 
o|removed side-effect free assignment to unused variable: iota 
o|removed side-effect free assignment to unused variable: make-list 
o|removed side-effect free assignment to unused variable: posq 
o|removed side-effect free assignment to unused variable: posv 
o|inlining procedure: k2692 
o|inlining procedure: k2692 
o|inlining procedure: k2752 
o|inlining procedure: k2752 
o|inlining procedure: k2770 
o|inlining procedure: k2770 
o|inlining procedure: k2804 
o|contracted procedure: "(chicken-ffi-syntax.scm:217) g826835" 
o|propagated global variable: g843844 chicken.compiler.support#foreign-type->scrutiny-type 
o|inlining procedure: k2804 
o|inlining procedure: k2943 
o|inlining procedure: k2943 
o|inlining procedure: k3043 
o|inlining procedure: k3043 
o|inlining procedure: k3146 
o|inlining procedure: k3146 
o|inlining procedure: k3301 
o|inlining procedure: k3301 
o|substituted constant variable: a3360 
o|substituted constant variable: a3361 
o|removed unused formal parameters: (_737) 
o|inlining procedure: k3443 
o|inlining procedure: k3443 
o|substituted constant variable: a3493 
o|inlining procedure: k3505 
o|inlining procedure: k3505 
o|contracted procedure: "(chicken-ffi-syntax.scm:138) append-map" 
o|inlining procedure: k1603 
o|inlining procedure: k1618 
o|inlining procedure: k1618 
o|inlining procedure: k1603 
o|inlining procedure: k1658 
o|inlining procedure: k1658 
o|inlining procedure: k1690 
o|contracted procedure: "(mini-srfi-1.scm:77) g207216" 
o|inlining procedure: k1690 
o|inlining procedure: k1739 
o|contracted procedure: "(mini-srfi-1.scm:76) g180189" 
o|inlining procedure: k1739 
o|inlining procedure: k3528 
o|removed unused parameter to known procedure: _737 "(chicken-ffi-syntax.scm:136) g726735" 
o|inlining procedure: k3528 
o|inlining procedure: k3612 
o|inlining procedure: k3612 
o|inlining procedure: k3686 
o|inlining procedure: k3719 
o|inlining procedure: k3719 
o|inlining procedure: k3686 
o|inlining procedure: k3809 
o|inlining procedure: k3809 
o|inlining procedure: k3821 
o|contracted procedure: "(chicken-ffi-syntax.scm:96) g664673" 
o|inlining procedure: k3821 
o|inlining procedure: k3870 
o|contracted procedure: "(chicken-ffi-syntax.scm:94) g637646" 
o|inlining procedure: k3870 
o|inlining procedure: k3902 
o|inlining procedure: k3902 
o|inlining procedure: k3931 
o|inlining procedure: k3931 
o|replaced variables: 425 
o|removed binding forms: 139 
o|removed side-effect free assignment to unused variable: filter 
o|removed side-effect free assignment to unused variable: list-tabulate 
o|substituted constant variable: r27713990 
o|substituted constant variable: r27713990 
o|contracted procedure: "(chicken-ffi-syntax.scm:232) every" 
o|converted assignments to bindings: (annotate-foreign-procedure812) 
o|substituted constant variable: r35064007 
o|substituted constant variable: r16194011 
o|substituted constant variable: r16594013 
o|contracted procedure: "(mini-srfi-1.scm:74) any" 
o|substituted constant variable: r18143976 
o|substituted constant variable: r36134023 
o|substituted constant variable: r36134023 
o|substituted constant variable: r37204028 
o|substituted constant variable: r37204028 
o|substituted constant variable: r39324044 
o|converted assignments to bindings: (compiler-only-er-transformer596) 
o|simplifications: ((let . 2)) 
o|replaced variables: 21 
o|removed binding forms: 374 
o|removed call to pure procedure with unused result: "(chicken-ffi-syntax.scm:136) ##sys#slot" 
o|replaced variables: 5 
o|removed binding forms: 32 
o|inlining procedure: "(mini-srfi-1.scm:82) a2785" 
o|contracted procedure: k3553 
o|removed binding forms: 7 
o|replaced variables: 2 
o|removed binding forms: 2 
o|removed binding forms: 2 
o|simplifications: ((if . 10) (let . 11) (##core#call . 220)) 
o|  call simplifications:
o|    scheme#apply
o|    scheme#length
o|    scheme#symbol?	2
o|    scheme#cddr	3
o|    scheme#cdddr	3
o|    scheme#cdr	11
o|    scheme#caddr	9
o|    scheme#cadr	13
o|    scheme#string?	4
o|    ##sys#check-list	8
o|    scheme#pair?	16
o|    scheme#cons	20
o|    ##sys#setslot	9
o|    ##sys#slot	28
o|    scheme#null?	6
o|    scheme#eq?	3
o|    scheme#not	4
o|    scheme#list	2
o|    ##sys#cons	28
o|    ##sys#list	33
o|    scheme#car	16
o|contracted procedure: k2705 
o|contracted procedure: k2732 
o|contracted procedure: k2743 
o|contracted procedure: k2762 
o|contracted procedure: k2770 
o|contracted procedure: k2776 
o|contracted procedure: k2779 
o|contracted procedure: k1779 
o|contracted procedure: k1801 
o|contracted procedure: k1797 
o|contracted procedure: k1788 
o|contracted procedure: k2807 
o|contracted procedure: k2810 
o|contracted procedure: k2813 
o|contracted procedure: k2821 
o|contracted procedure: k2829 
o|contracted procedure: k2885 
o|contracted procedure: k2889 
o|contracted procedure: k2896 
o|contracted procedure: k2903 
o|contracted procedure: k2975 
o|contracted procedure: k2920 
o|contracted procedure: k2924 
o|contracted procedure: k2927 
o|contracted procedure: k2930 
o|contracted procedure: k2937 
o|contracted procedure: k2946 
o|contracted procedure: k2968 
o|contracted procedure: k2964 
o|contracted procedure: k2949 
o|contracted procedure: k2952 
o|contracted procedure: k2960 
o|contracted procedure: k3003 
o|contracted procedure: k2992 
o|contracted procedure: k2996 
o|contracted procedure: k3075 
o|contracted procedure: k3020 
o|contracted procedure: k3024 
o|contracted procedure: k3027 
o|contracted procedure: k3030 
o|contracted procedure: k3037 
o|contracted procedure: k3046 
o|contracted procedure: k3068 
o|contracted procedure: k3064 
o|contracted procedure: k3049 
o|contracted procedure: k3052 
o|contracted procedure: k3060 
o|contracted procedure: k3103 
o|contracted procedure: k3092 
o|contracted procedure: k3096 
o|contracted procedure: k3119 
o|contracted procedure: k3122 
o|contracted procedure: k3125 
o|contracted procedure: k3128 
o|contracted procedure: k3138 
o|contracted procedure: k3149 
o|contracted procedure: k3171 
o|contracted procedure: k3167 
o|contracted procedure: k3152 
o|contracted procedure: k3155 
o|contracted procedure: k3163 
o|contracted procedure: k3199 
o|contracted procedure: k3184 
o|contracted procedure: k3195 
o|contracted procedure: k3191 
o|contracted procedure: k3216 
o|contracted procedure: k3233 
o|contracted procedure: k3254 
o|contracted procedure: k3250 
o|contracted procedure: k3270 
o|contracted procedure: k3281 
o|contracted procedure: k3293 
o|contracted procedure: k3297 
o|contracted procedure: k3304 
o|contracted procedure: k3310 
o|contracted procedure: k3389 
o|contracted procedure: k3320 
o|contracted procedure: k3352 
o|contracted procedure: k3340 
o|contracted procedure: k3344 
o|contracted procedure: k3385 
o|contracted procedure: k3406 
o|contracted procedure: k3411 
o|contracted procedure: k3423 
o|contracted procedure: k3446 
o|contracted procedure: k3453 
o|contracted procedure: k3456 
o|contracted procedure: k3459 
o|contracted procedure: k3495 
o|contracted procedure: k3468 
o|contracted procedure: k3475 
o|contracted procedure: k3479 
o|contracted procedure: k3486 
o|contracted procedure: k3490 
o|contracted procedure: k3522 
o|contracted procedure: k3508 
o|contracted procedure: k3515 
o|contracted procedure: k1606 
o|contracted procedure: k1609 
o|contracted procedure: k1621 
o|contracted procedure: k1637 
o|contracted procedure: k1645 
o|contracted procedure: k1652 
o|contracted procedure: k1676 
o|contracted procedure: k1693 
o|contracted procedure: k1715 
o|contracted procedure: k1711 
o|contracted procedure: k1696 
o|contracted procedure: k1699 
o|contracted procedure: k1707 
o|contracted procedure: k1722 
o|contracted procedure: k1730 
o|contracted procedure: k1742 
o|contracted procedure: k1764 
o|contracted procedure: k1760 
o|contracted procedure: k1745 
o|contracted procedure: k1748 
o|contracted procedure: k1756 
o|contracted procedure: k1816 
o|contracted procedure: k1831 
o|contracted procedure: k1819 
o|contracted procedure: k3531 
o|contracted procedure: k3534 
o|contracted procedure: k3537 
o|contracted procedure: k3545 
o|contracted procedure: k3642 
o|contracted procedure: k3560 
o|contracted procedure: k3573 
o|contracted procedure: k3576 
o|contracted procedure: k3635 
o|contracted procedure: k3582 
o|contracted procedure: k3600 
o|contracted procedure: k3596 
o|contracted procedure: k3608 
o|contracted procedure: k3615 
o|contracted procedure: k3622 
o|contracted procedure: k3612 
o|contracted procedure: k3663 
o|contracted procedure: k3951 
o|contracted procedure: k3955 
o|contracted procedure: k3959 
o|contracted procedure: k3667 
o|contracted procedure: k3677 
o|contracted procedure: k3942 
o|contracted procedure: k3680 
o|contracted procedure: k3692 
o|contracted procedure: k3743 
o|contracted procedure: k3707 
o|contracted procedure: k3703 
o|contracted procedure: k3715 
o|contracted procedure: k3722 
o|contracted procedure: k3733 
o|contracted procedure: k3729 
o|contracted procedure: k3719 
o|contracted procedure: k3749 
o|contracted procedure: k3752 
o|contracted procedure: k3769 
o|contracted procedure: k3773 
o|contracted procedure: k3902 
o|contracted procedure: k3777 
o|contracted procedure: k3853 
o|contracted procedure: k3861 
o|contracted procedure: k3781 
o|contracted procedure: k3797 
o|contracted procedure: k3809 
o|contracted procedure: k3793 
o|contracted procedure: k3785 
o|contracted procedure: k3765 
o|contracted procedure: k3824 
o|contracted procedure: k3846 
o|contracted procedure: k3842 
o|contracted procedure: k3827 
o|contracted procedure: k3830 
o|contracted procedure: k3838 
o|contracted procedure: k3873 
o|contracted procedure: k3895 
o|contracted procedure: k3891 
o|contracted procedure: k3876 
o|contracted procedure: k3879 
o|contracted procedure: k3887 
o|contracted procedure: k3928 
o|contracted procedure: k3934 
o|simplifications: ((let . 39)) 
o|removed binding forms: 182 
o|inlining procedure: k2766 
o|inlining procedure: k2766 
o|inlining procedure: k3604 
o|inlining procedure: k3604 
o|inlining procedure: k3711 
o|inlining procedure: k3711 
o|removed binding forms: 3 
o|direct leaf routine/allocation: loop230 0 
o|direct leaf routine/allocation: loop243 0 
o|converted assignments to bindings: (loop230) 
o|contracted procedure: k1661 
o|converted assignments to bindings: (loop243) 
o|simplifications: ((let . 2)) 
o|removed binding forms: 1 
o|customizable procedures: (k3683 map-loop631649 map-loop658676 g726735 map-loop720738 map-loop174192 map-loop201219 loop170 foldr159162 g164165 loop750 k3277 k3116 map-loop893910 map-loop936953 map-loop976993 annotate-foreign-procedure812 compiler-only-er-transformer596 map-loop820845 k2755) 
o|calls to known targets: 56 
o|identified direct recursive calls: f_1777 1 
o|identified direct recursive calls: f_2941 1 
o|identified direct recursive calls: f_3041 1 
o|identified direct recursive calls: f_3144 1 
o|identified direct recursive calls: f_3441 1 
o|identified direct recursive calls: f_1616 1 
o|identified direct recursive calls: f_1811 1 
o|identified direct recursive calls: f_1688 1 
o|identified direct recursive calls: f_1737 1 
o|identified direct recursive calls: f_3819 1 
o|identified direct recursive calls: f_3868 1 
o|fast box initializations: 12 
o|dropping unused closure argument: f_1777 
o|dropping unused closure argument: f_1811 
o|dropping unused closure argument: f_2684 
o|dropping unused closure argument: f_2730 
*/
/* end of file */
