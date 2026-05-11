/* Generated from extras.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: extras.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file extras.c -emit-import-library chicken.format -emit-import-library chicken.io -emit-import-library chicken.pretty-print -emit-import-library chicken.random
   unit: extras
   uses: extras data-structures library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_extras_toplevel)
C_externimport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[167];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,17),40,100,111,108,111,111,112,57,56,32,120,32,105,32,120,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,108,105,115,116,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,9),40,103,49,50,50,32,114,108,41,0,0,0,0,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,105,41};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,108,105,110,101,32,46,32,97,114,103,115,41,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,108,110,115,32,110,41,0,0,0,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,30),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,108,105,110,101,115,32,46,32,114,101,115,116,41,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,105,111,35,119,114,105,116,101,45,108,105,110,101,32,115,116,114,32,46,32,112,111,114,116,41,0,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,115,116,97,114,116,32,110,32,109,41};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,115,116,97,114,116,32,110,32,109,41};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,115,116,114,105,110,103,33,47,112,111,114,116,32,110,32,100,101,115,116,32,112,111,114,116,32,115,116,97,114,116,41};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,115,116,114,105,110,103,33,32,110,32,100,101,115,116,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,115,116,114,105,110,103,47,112,111,114,116,32,110,32,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,115,116,114,105,110,103,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,98,117,102,102,101,114,101,100,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,116,111,107,101,110,32,112,114,101,100,32,46,32,112,111,114,116,41,0,0,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,16),40,98,111,100,121,51,49,55,32,110,32,112,111,114,116,41};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,16),40,100,101,102,45,112,111,114,116,51,50,48,32,37,110,41};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,10),40,100,101,102,45,110,51,49,57,41,0,0,0,0,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,105,111,35,119,114,105,116,101,45,115,116,114,105,110,103,32,115,32,46,32,109,111,114,101,41,0,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,105,111,35,114,101,97,100,45,98,121,116,101,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,105,111,35,119,114,105,116,101,45,98,121,116,101,32,98,121,116,101,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,15),40,114,101,97,100,45,109,97,99,114,111,63,32,108,41,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,19),40,114,101,97,100,45,109,97,99,114,111,45,112,114,101,102,105,120,41,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,13),40,111,117,116,32,115,116,114,32,99,111,108,41,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,18),40,119,114,45,101,120,112,114,32,101,120,112,114,32,99,111,108,41,0,0,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,108,32,99,111,108,41,0,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,14),40,119,114,45,108,115,116,32,108,32,99,111,108,41,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,8),40,103,53,48,55,32,97,41};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,105,32,106,32,99,111,108,41,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,9),40,103,53,49,56,32,99,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,53,50,55,32,105,41,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,12),40,119,114,32,111,98,106,32,99,111,108,41,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,14),40,115,112,97,99,101,115,32,110,32,99,111,108,41,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,15),40,105,110,100,101,110,116,32,116,111,32,99,111,108,41,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,11),40,97,50,56,56,48,32,115,116,114,41,0,0,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,26),40,112,114,32,111,98,106,32,99,111,108,32,101,120,116,114,97,32,112,112,45,112,97,105,114,41,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,24),40,112,112,45,101,120,112,114,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,32),40,112,112,45,99,97,108,108,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,32,112,112,45,105,116,101,109,41};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,29),40,112,112,45,108,105,115,116,32,108,32,99,111,108,32,101,120,116,114,97,32,112,112,45,105,116,101,109,41,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,108,32,99,111,108,41,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,35),40,112,112,45,100,111,119,110,32,108,32,99,111,108,49,32,99,111,108,50,32,101,120,116,114,97,32,112,112,45,105,116,101,109,41,0,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,27),40,116,97,105,108,49,32,114,101,115,116,32,99,111,108,49,32,99,111,108,50,32,99,111,108,51,41,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,27),40,116,97,105,108,50,32,114,101,115,116,32,99,111,108,49,32,99,111,108,50,32,99,111,108,51,41,0,0,0,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,22),40,116,97,105,108,51,32,114,101,115,116,32,99,111,108,49,32,99,111,108,50,41,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,49),40,112,112,45,103,101,110,101,114,97,108,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,32,110,97,109,101,100,63,32,112,112,45,49,32,112,112,45,50,32,112,112,45,51,41,0,0,0,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,26),40,112,112,45,101,120,112,114,45,108,105,115,116,32,108,32,99,111,108,32,101,120,116,114,97,41,0,0,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,26),40,112,112,45,108,97,109,98,100,97,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41,0,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,22),40,112,112,45,105,102,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,24),40,112,112,45,99,111,110,100,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,24),40,112,112,45,99,97,115,101,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,23),40,112,112,45,97,110,100,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,23),40,112,112,45,108,101,116,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,25),40,112,112,45,98,101,103,105,110,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,22),40,112,112,45,100,111,32,101,120,112,114,32,99,111,108,32,101,120,116,114,97,41,0,0};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,12),40,115,116,121,108,101,32,104,101,97,100,41,0,0,0,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,12),40,112,112,32,111,98,106,32,99,111,108,41,0,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,62),40,99,104,105,99,107,101,110,46,112,114,101,116,116,121,45,112,114,105,110,116,35,103,101,110,101,114,105,99,45,119,114,105,116,101,32,111,98,106,32,100,105,115,112,108,97,121,63,32,119,105,100,116,104,32,111,117,116,112,117,116,41,0,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,9),40,97,51,52,53,52,32,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,112,114,101,116,116,121,45,112,114,105,110,116,35,112,114,101,116,116,121,45,112,114,105,110,116,32,111,98,106,32,46,32,111,112,116,41,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,6),40,110,101,120,116,41,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,6),40,115,107,105,112,41,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,14),40,114,101,99,32,109,115,103,32,97,114,103,115,41,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,102,111,114,109,97,116,35,102,112,114,105,110,116,102,48,32,108,111,99,32,112,111,114,116,32,109,115,103,32,97,114,103,115,41,0,0,0,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,102,111,114,109,97,116,35,102,112,114,105,110,116,102,32,112,111,114,116,32,102,115,116,114,32,46,32,97,114,103,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,102,111,114,109,97,116,35,112,114,105,110,116,102,32,102,115,116,114,32,46,32,97,114,103,115,41,0,0,0,0,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,102,111,114,109,97,116,35,115,112,114,105,110,116,102,32,102,115,116,114,32,46,32,97,114,103,115,41,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,102,111,114,109,97,116,35,102,111,114,109,97,116,32,102,109,116,45,111,114,45,100,115,116,32,46,32,97,114,103,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,114,97,110,100,111,109,35,115,101,116,45,112,115,101,117,100,111,45,114,97,110,100,111,109,45,115,101,101,100,33,32,98,117,102,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,114,97,110,100,111,109,35,112,115,101,117,100,111,45,114,97,110,100,111,109,45,105,110,116,101,103,101,114,32,110,41};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,114,97,110,100,111,109,35,112,115,101,117,100,111,45,114,97,110,100,111,109,45,114,101,97,108,41,0,0,0,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,114,97,110,100,111,109,35,114,97,110,100,111,109,45,98,121,116,101,115,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1102)
static void C_ccall f_1102(C_word c,C_word *av) C_noret;
C_noret_decl(f_1105)
static void C_ccall f_1105(C_word c,C_word *av) C_noret;
C_noret_decl(f_1107)
static void C_ccall f_1107(C_word c,C_word *av) C_noret;
C_noret_decl(f_1136)
static void C_ccall f_1136(C_word c,C_word *av) C_noret;
C_noret_decl(f_1138)
static void C_fcall f_1138(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1158)
static void C_ccall f_1158(C_word c,C_word *av) C_noret;
C_noret_decl(f_1210)
static void C_ccall f_1210(C_word c,C_word *av) C_noret;
C_noret_decl(f_1220)
static void C_fcall f_1220(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1230)
static void C_fcall f_1230(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1243)
static void C_ccall f_1243(C_word c,C_word *av) C_noret;
C_noret_decl(f_1248)
static void C_fcall f_1248(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1261)
static void C_ccall f_1261(C_word c,C_word *av) C_noret;
C_noret_decl(f_1294)
static void C_ccall f_1294(C_word c,C_word *av) C_noret;
C_noret_decl(f_1303)
static void C_ccall f_1303(C_word c,C_word *av) C_noret;
C_noret_decl(f_1326)
static void C_ccall f_1326(C_word c,C_word *av) C_noret;
C_noret_decl(f_1334)
static void C_ccall f_1334(C_word c,C_word *av) C_noret;
C_noret_decl(f_1363)
static void C_ccall f_1363(C_word c,C_word *av) C_noret;
C_noret_decl(f_1382)
static void C_ccall f_1382(C_word c,C_word *av) C_noret;
C_noret_decl(f_1391)
static void C_fcall f_1391(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1404)
static void C_ccall f_1404(C_word c,C_word *av) C_noret;
C_noret_decl(f_1453)
static void C_ccall f_1453(C_word c,C_word *av) C_noret;
C_noret_decl(f_1469)
static void C_ccall f_1469(C_word c,C_word *av) C_noret;
C_noret_decl(f_1481)
static void C_ccall f_1481(C_word c,C_word *av) C_noret;
C_noret_decl(f_1499)
static void C_fcall f_1499(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1503)
static void C_ccall f_1503(C_word c,C_word *av) C_noret;
C_noret_decl(f_1558)
static void C_fcall f_1558(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1562)
static void C_ccall f_1562(C_word c,C_word *av) C_noret;
C_noret_decl(f_1565)
static void C_fcall f_1565(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1613)
static void C_ccall f_1613(C_word c,C_word *av) C_noret;
C_noret_decl(f_1635)
static void C_ccall f_1635(C_word c,C_word *av) C_noret;
C_noret_decl(f_1641)
static void C_fcall f_1641(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1644)
static void C_ccall f_1644(C_word c,C_word *av) C_noret;
C_noret_decl(f_1690)
static void C_ccall f_1690(C_word c,C_word *av) C_noret;
C_noret_decl(f_1709)
static void C_ccall f_1709(C_word c,C_word *av) C_noret;
C_noret_decl(f_1712)
static void C_ccall f_1712(C_word c,C_word *av) C_noret;
C_noret_decl(f_1724)
static void C_ccall f_1724(C_word c,C_word *av) C_noret;
C_noret_decl(f_1727)
static void C_ccall f_1727(C_word c,C_word *av) C_noret;
C_noret_decl(f_1732)
static void C_fcall f_1732(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1736)
static void C_ccall f_1736(C_word c,C_word *av) C_noret;
C_noret_decl(f_1748)
static void C_ccall f_1748(C_word c,C_word *av) C_noret;
C_noret_decl(f_1756)
static void C_ccall f_1756(C_word c,C_word *av) C_noret;
C_noret_decl(f_1758)
static void C_ccall f_1758(C_word c,C_word *av) C_noret;
C_noret_decl(f_1777)
static void C_ccall f_1777(C_word c,C_word *av) C_noret;
C_noret_decl(f_1811)
static void C_ccall f_1811(C_word c,C_word *av) C_noret;
C_noret_decl(f_1839)
static void C_ccall f_1839(C_word c,C_word *av) C_noret;
C_noret_decl(f_1849)
static void C_ccall f_1849(C_word c,C_word *av) C_noret;
C_noret_decl(f_1854)
static void C_fcall f_1854(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1858)
static void C_ccall f_1858(C_word c,C_word *av) C_noret;
C_noret_decl(f_1864)
static void C_ccall f_1864(C_word c,C_word *av) C_noret;
C_noret_decl(f_1867)
static void C_ccall f_1867(C_word c,C_word *av) C_noret;
C_noret_decl(f_1874)
static void C_ccall f_1874(C_word c,C_word *av) C_noret;
C_noret_decl(f_1895)
static void C_ccall f_1895(C_word c,C_word *av) C_noret;
C_noret_decl(f_1900)
static void C_fcall f_1900(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1907)
static void C_ccall f_1907(C_word c,C_word *av) C_noret;
C_noret_decl(f_1917)
static void C_ccall f_1917(C_word c,C_word *av) C_noret;
C_noret_decl(f_1938)
static void C_fcall f_1938(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1943)
static void C_fcall f_1943(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1978)
static void C_ccall f_1978(C_word c,C_word *av) C_noret;
C_noret_decl(f_1988)
static void C_ccall f_1988(C_word c,C_word *av) C_noret;
C_noret_decl(f_2005)
static void C_ccall f_2005(C_word c,C_word *av) C_noret;
C_noret_decl(f_2012)
static void C_ccall f_2012(C_word c,C_word *av) C_noret;
C_noret_decl(f_2030)
static void C_fcall f_2030(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2033)
static void C_fcall f_2033(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2061)
static void C_fcall f_2061(C_word t0,C_word t1) C_noret;
C_noret_decl(f_2095)
static C_word C_fcall f_2095(C_word t0);
C_noret_decl(f_2134)
static void C_fcall f_2134(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2144)
static void C_ccall f_2144(C_word c,C_word *av) C_noret;
C_noret_decl(f_2153)
static void C_fcall f_2153(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2156)
static void C_fcall f_2156(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2163)
static void C_ccall f_2163(C_word c,C_word *av) C_noret;
C_noret_decl(f_2174)
static void C_ccall f_2174(C_word c,C_word *av) C_noret;
C_noret_decl(f_2183)
static void C_fcall f_2183(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2199)
static void C_ccall f_2199(C_word c,C_word *av) C_noret;
C_noret_decl(f_2201)
static void C_fcall f_2201(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2223)
static void C_ccall f_2223(C_word c,C_word *av) C_noret;
C_noret_decl(f_2229)
static void C_ccall f_2229(C_word c,C_word *av) C_noret;
C_noret_decl(f_2245)
static void C_ccall f_2245(C_word c,C_word *av) C_noret;
C_noret_decl(f_2249)
static void C_ccall f_2249(C_word c,C_word *av) C_noret;
C_noret_decl(f_2258)
static void C_ccall f_2258(C_word c,C_word *av) C_noret;
C_noret_decl(f_2307)
static void C_ccall f_2307(C_word c,C_word *av) C_noret;
C_noret_decl(f_2311)
static void C_ccall f_2311(C_word c,C_word *av) C_noret;
C_noret_decl(f_2330)
static void C_ccall f_2330(C_word c,C_word *av) C_noret;
C_noret_decl(f_2337)
static void C_ccall f_2337(C_word c,C_word *av) C_noret;
C_noret_decl(f_2343)
static void C_ccall f_2343(C_word c,C_word *av) C_noret;
C_noret_decl(f_2349)
static void C_ccall f_2349(C_word c,C_word *av) C_noret;
C_noret_decl(f_2352)
static void C_ccall f_2352(C_word c,C_word *av) C_noret;
C_noret_decl(f_2359)
static void C_ccall f_2359(C_word c,C_word *av) C_noret;
C_noret_decl(f_2372)
static void C_ccall f_2372(C_word c,C_word *av) C_noret;
C_noret_decl(f_2391)
static void C_ccall f_2391(C_word c,C_word *av) C_noret;
C_noret_decl(f_2393)
static void C_fcall f_2393(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2421)
static void C_ccall f_2421(C_word c,C_word *av) C_noret;
C_noret_decl(f_2425)
static void C_ccall f_2425(C_word c,C_word *av) C_noret;
C_noret_decl(f_2429)
static void C_ccall f_2429(C_word c,C_word *av) C_noret;
C_noret_decl(f_2452)
static void C_ccall f_2452(C_word c,C_word *av) C_noret;
C_noret_decl(f_2457)
static void C_ccall f_2457(C_word c,C_word *av) C_noret;
C_noret_decl(f_2458)
static void C_fcall f_2458(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2476)
static void C_ccall f_2476(C_word c,C_word *av) C_noret;
C_noret_decl(f_2480)
static void C_ccall f_2480(C_word c,C_word *av) C_noret;
C_noret_decl(f_2488)
static void C_ccall f_2488(C_word c,C_word *av) C_noret;
C_noret_decl(f_2499)
static void C_ccall f_2499(C_word c,C_word *av) C_noret;
C_noret_decl(f_2517)
static void C_ccall f_2517(C_word c,C_word *av) C_noret;
C_noret_decl(f_2521)
static void C_ccall f_2521(C_word c,C_word *av) C_noret;
C_noret_decl(f_2544)
static void C_ccall f_2544(C_word c,C_word *av) C_noret;
C_noret_decl(f_2552)
static void C_ccall f_2552(C_word c,C_word *av) C_noret;
C_noret_decl(f_2555)
static void C_ccall f_2555(C_word c,C_word *av) C_noret;
C_noret_decl(f_2559)
static void C_fcall f_2559(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2579)
static void C_ccall f_2579(C_word c,C_word *av) C_noret;
C_noret_decl(f_2586)
static void C_ccall f_2586(C_word c,C_word *av) C_noret;
C_noret_decl(f_2597)
static void C_ccall f_2597(C_word c,C_word *av) C_noret;
C_noret_decl(f_2604)
static void C_ccall f_2604(C_word c,C_word *av) C_noret;
C_noret_decl(f_2620)
static void C_ccall f_2620(C_word c,C_word *av) C_noret;
C_noret_decl(f_2650)
static void C_ccall f_2650(C_word c,C_word *av) C_noret;
C_noret_decl(f_2659)
static void C_ccall f_2659(C_word c,C_word *av) C_noret;
C_noret_decl(f_2662)
static void C_ccall f_2662(C_word c,C_word *av) C_noret;
C_noret_decl(f_2669)
static void C_ccall f_2669(C_word c,C_word *av) C_noret;
C_noret_decl(f_2675)
static void C_ccall f_2675(C_word c,C_word *av) C_noret;
C_noret_decl(f_2682)
static void C_ccall f_2682(C_word c,C_word *av) C_noret;
C_noret_decl(f_2692)
static void C_ccall f_2692(C_word c,C_word *av) C_noret;
C_noret_decl(f_2698)
static void C_ccall f_2698(C_word c,C_word *av) C_noret;
C_noret_decl(f_2703)
static void C_fcall f_2703(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2716)
static void C_ccall f_2716(C_word c,C_word *av) C_noret;
C_noret_decl(f_2719)
static void C_ccall f_2719(C_word c,C_word *av) C_noret;
C_noret_decl(f_2730)
static void C_ccall f_2730(C_word c,C_word *av) C_noret;
C_noret_decl(f_2742)
static void C_ccall f_2742(C_word c,C_word *av) C_noret;
C_noret_decl(f_2745)
static void C_ccall f_2745(C_word c,C_word *av) C_noret;
C_noret_decl(f_2752)
static void C_ccall f_2752(C_word c,C_word *av) C_noret;
C_noret_decl(f_2760)
static void C_fcall f_2760(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2763)
static void C_fcall f_2763(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2787)
static void C_ccall f_2787(C_word c,C_word *av) C_noret;
C_noret_decl(f_2794)
static void C_ccall f_2794(C_word c,C_word *av) C_noret;
C_noret_decl(f_2796)
static void C_fcall f_2796(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2812)
static void C_ccall f_2812(C_word c,C_word *av) C_noret;
C_noret_decl(f_2819)
static void C_ccall f_2819(C_word c,C_word *av) C_noret;
C_noret_decl(f_2830)
static void C_fcall f_2830(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_2843)
static void C_ccall f_2843(C_word c,C_word *av) C_noret;
C_noret_decl(f_2846)
static void C_ccall f_2846(C_word c,C_word *av) C_noret;
C_noret_decl(f_2859)
static void C_ccall f_2859(C_word c,C_word *av) C_noret;
C_noret_decl(f_2875)
static void C_ccall f_2875(C_word c,C_word *av) C_noret;
C_noret_decl(f_2879)
static void C_ccall f_2879(C_word c,C_word *av) C_noret;
C_noret_decl(f_2881)
static void C_ccall f_2881(C_word c,C_word *av) C_noret;
C_noret_decl(f_2917)
static void C_ccall f_2917(C_word c,C_word *av) C_noret;
C_noret_decl(f_2924)
static void C_ccall f_2924(C_word c,C_word *av) C_noret;
C_noret_decl(f_2935)
static void C_ccall f_2935(C_word c,C_word *av) C_noret;
C_noret_decl(f_2951)
static void C_ccall f_2951(C_word c,C_word *av) C_noret;
C_noret_decl(f_2977)
static void C_ccall f_2977(C_word c,C_word *av) C_noret;
C_noret_decl(f_2982)
static void C_fcall f_2982(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_2986)
static void C_ccall f_2986(C_word c,C_word *av) C_noret;
C_noret_decl(f_3006)
static void C_ccall f_3006(C_word c,C_word *av) C_noret;
C_noret_decl(f_3008)
static void C_fcall f_3008(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_3012)
static void C_ccall f_3012(C_word c,C_word *av) C_noret;
C_noret_decl(f_3017)
static void C_fcall f_3017(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_3023)
static void C_fcall f_3023(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3044)
static void C_ccall f_3044(C_word c,C_word *av) C_noret;
C_noret_decl(f_3050)
static void C_ccall f_3050(C_word c,C_word *av) C_noret;
C_noret_decl(f_3072)
static void C_ccall f_3072(C_word c,C_word *av) C_noret;
C_noret_decl(f_3076)
static void C_ccall f_3076(C_word c,C_word *av) C_noret;
C_noret_decl(f_3084)
static void C_ccall f_3084(C_word c,C_word *av) C_noret;
C_noret_decl(f_3088)
static void C_ccall f_3088(C_word c,C_word *av) C_noret;
C_noret_decl(f_3090)
static void C_fcall f_3090(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7,C_word t8) C_noret;
C_noret_decl(f_3093)
static void C_fcall f_3093(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_3114)
static void C_ccall f_3114(C_word c,C_word *av) C_noret;
C_noret_decl(f_3118)
static void C_ccall f_3118(C_word c,C_word *av) C_noret;
C_noret_decl(f_3132)
static void C_fcall f_3132(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_3153)
static void C_ccall f_3153(C_word c,C_word *av) C_noret;
C_noret_decl(f_3157)
static void C_ccall f_3157(C_word c,C_word *av) C_noret;
C_noret_decl(f_3171)
static void C_fcall f_3171(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3182)
static void C_ccall f_3182(C_word c,C_word *av) C_noret;
C_noret_decl(f_3195)
static void C_ccall f_3195(C_word c,C_word *av) C_noret;
C_noret_decl(f_3210)
static void C_ccall f_3210(C_word c,C_word *av) C_noret;
C_noret_decl(f_3228)
static void C_ccall f_3228(C_word c,C_word *av) C_noret;
C_noret_decl(f_3230)
static void C_ccall f_3230(C_word c,C_word *av) C_noret;
C_noret_decl(f_3236)
static void C_ccall f_3236(C_word c,C_word *av) C_noret;
C_noret_decl(f_3242)
static void C_ccall f_3242(C_word c,C_word *av) C_noret;
C_noret_decl(f_3248)
static void C_ccall f_3248(C_word c,C_word *av) C_noret;
C_noret_decl(f_3254)
static void C_ccall f_3254(C_word c,C_word *av) C_noret;
C_noret_decl(f_3260)
static void C_ccall f_3260(C_word c,C_word *av) C_noret;
C_noret_decl(f_3266)
static void C_ccall f_3266(C_word c,C_word *av) C_noret;
C_noret_decl(f_3286)
static void C_ccall f_3286(C_word c,C_word *av) C_noret;
C_noret_decl(f_3292)
static void C_ccall f_3292(C_word c,C_word *av) C_noret;
C_noret_decl(f_3301)
static void C_fcall f_3301(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_3311)
static void C_fcall f_3311(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3427)
static void C_ccall f_3427(C_word c,C_word *av) C_noret;
C_noret_decl(f_3431)
static void C_ccall f_3431(C_word c,C_word *av) C_noret;
C_noret_decl(f_3440)
static void C_ccall f_3440(C_word c,C_word *av) C_noret;
C_noret_decl(f_3442)
static void C_ccall f_3442(C_word c,C_word *av) C_noret;
C_noret_decl(f_3449)
static void C_ccall f_3449(C_word c,C_word *av) C_noret;
C_noret_decl(f_3453)
static void C_ccall f_3453(C_word c,C_word *av) C_noret;
C_noret_decl(f_3455)
static void C_ccall f_3455(C_word c,C_word *av) C_noret;
C_noret_decl(f_3459)
static void C_ccall f_3459(C_word c,C_word *av) C_noret;
C_noret_decl(f_3466)
static void C_fcall f_3466(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_3473)
static void C_ccall f_3473(C_word c,C_word *av) C_noret;
C_noret_decl(f_3476)
static void C_ccall f_3476(C_word c,C_word *av) C_noret;
C_noret_decl(f_3498)
static void C_ccall f_3498(C_word c,C_word *av) C_noret;
C_noret_decl(f_3504)
static void C_fcall f_3504(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_3513)
static C_word C_fcall f_3513(C_word t0);
C_noret_decl(f_3520)
static void C_fcall f_3520(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3539)
static void C_fcall f_3539(C_word t0,C_word t1) C_noret;
C_noret_decl(f_3552)
static void C_ccall f_3552(C_word c,C_word *av) C_noret;
C_noret_decl(f_3577)
static void C_ccall f_3577(C_word c,C_word *av) C_noret;
C_noret_decl(f_3590)
static void C_ccall f_3590(C_word c,C_word *av) C_noret;
C_noret_decl(f_3603)
static void C_ccall f_3603(C_word c,C_word *av) C_noret;
C_noret_decl(f_3616)
static void C_ccall f_3616(C_word c,C_word *av) C_noret;
C_noret_decl(f_3620)
static void C_ccall f_3620(C_word c,C_word *av) C_noret;
C_noret_decl(f_3633)
static void C_ccall f_3633(C_word c,C_word *av) C_noret;
C_noret_decl(f_3637)
static void C_ccall f_3637(C_word c,C_word *av) C_noret;
C_noret_decl(f_3650)
static void C_ccall f_3650(C_word c,C_word *av) C_noret;
C_noret_decl(f_3654)
static void C_ccall f_3654(C_word c,C_word *av) C_noret;
C_noret_decl(f_3672)
static void C_ccall f_3672(C_word c,C_word *av) C_noret;
C_noret_decl(f_3675)
static void C_ccall f_3675(C_word c,C_word *av) C_noret;
C_noret_decl(f_3681)
static void C_ccall f_3681(C_word c,C_word *av) C_noret;
C_noret_decl(f_3717)
static C_word C_fcall f_3717(C_word t0,C_word t1);
C_noret_decl(f_3775)
static void C_ccall f_3775(C_word c,C_word *av) C_noret;
C_noret_decl(f_3786)
static void C_ccall f_3786(C_word c,C_word *av) C_noret;
C_noret_decl(f_3792)
static void C_ccall f_3792(C_word c,C_word *av) C_noret;
C_noret_decl(f_3798)
static void C_ccall f_3798(C_word c,C_word *av) C_noret;
C_noret_decl(f_3804)
static void C_ccall f_3804(C_word c,C_word *av) C_noret;
C_noret_decl(f_3812)
static void C_ccall f_3812(C_word c,C_word *av) C_noret;
C_noret_decl(f_3837)
static void C_ccall f_3837(C_word c,C_word *av) C_noret;
C_noret_decl(f_3847)
static void C_ccall f_3847(C_word c,C_word *av) C_noret;
C_noret_decl(f_3850)
static void C_ccall f_3850(C_word c,C_word *av) C_noret;
C_noret_decl(f_3852)
static void C_ccall f_3852(C_word c,C_word *av) C_noret;
C_noret_decl(f_3859)
static void C_ccall f_3859(C_word c,C_word *av) C_noret;
C_noret_decl(f_3862)
static void C_ccall f_3862(C_word c,C_word *av) C_noret;
C_noret_decl(f_3873)
static void C_ccall f_3873(C_word c,C_word *av) C_noret;
C_noret_decl(f_3891)
static void C_ccall f_3891(C_word c,C_word *av) C_noret;
C_noret_decl(f_3907)
static void C_ccall f_3907(C_word c,C_word *av) C_noret;
C_noret_decl(f_3910)
static void C_ccall f_3910(C_word c,C_word *av) C_noret;
C_noret_decl(f_3926)
static void C_ccall f_3926(C_word c,C_word *av) C_noret;
C_noret_decl(f_3929)
static void C_ccall f_3929(C_word c,C_word *av) C_noret;
C_noret_decl(f_3936)
static void C_ccall f_3936(C_word c,C_word *av) C_noret;
C_noret_decl(f_3951)
static void C_ccall f_3951(C_word c,C_word *av) C_noret;
C_noret_decl(f_3974)
static void C_ccall f_3974(C_word c,C_word *av) C_noret;
C_noret_decl(C_extras_toplevel)
C_externexport void C_ccall C_extras_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1138)
static void C_ccall trf_1138(C_word c,C_word *av) C_noret;
static void C_ccall trf_1138(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1138(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1220)
static void C_ccall trf_1220(C_word c,C_word *av) C_noret;
static void C_ccall trf_1220(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1220(t0,t1);}

C_noret_decl(trf_1230)
static void C_ccall trf_1230(C_word c,C_word *av) C_noret;
static void C_ccall trf_1230(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1230(t0,t1,t2);}

C_noret_decl(trf_1248)
static void C_ccall trf_1248(C_word c,C_word *av) C_noret;
static void C_ccall trf_1248(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1248(t0,t1,t2);}

C_noret_decl(trf_1391)
static void C_ccall trf_1391(C_word c,C_word *av) C_noret;
static void C_ccall trf_1391(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1391(t0,t1,t2,t3);}

C_noret_decl(trf_1499)
static void C_ccall trf_1499(C_word c,C_word *av) C_noret;
static void C_ccall trf_1499(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1499(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1558)
static void C_ccall trf_1558(C_word c,C_word *av) C_noret;
static void C_ccall trf_1558(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1558(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1565)
static void C_ccall trf_1565(C_word c,C_word *av) C_noret;
static void C_ccall trf_1565(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1565(t0,t1);}

C_noret_decl(trf_1641)
static void C_ccall trf_1641(C_word c,C_word *av) C_noret;
static void C_ccall trf_1641(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1641(t0,t1);}

C_noret_decl(trf_1732)
static void C_ccall trf_1732(C_word c,C_word *av) C_noret;
static void C_ccall trf_1732(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1732(t0,t1);}

C_noret_decl(trf_1854)
static void C_ccall trf_1854(C_word c,C_word *av) C_noret;
static void C_ccall trf_1854(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1854(t0,t1);}

C_noret_decl(trf_1900)
static void C_ccall trf_1900(C_word c,C_word *av) C_noret;
static void C_ccall trf_1900(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1900(t0,t1,t2,t3);}

C_noret_decl(trf_1938)
static void C_ccall trf_1938(C_word c,C_word *av) C_noret;
static void C_ccall trf_1938(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1938(t0,t1,t2);}

C_noret_decl(trf_1943)
static void C_ccall trf_1943(C_word c,C_word *av) C_noret;
static void C_ccall trf_1943(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1943(t0,t1);}

C_noret_decl(trf_2030)
static void C_ccall trf_2030(C_word c,C_word *av) C_noret;
static void C_ccall trf_2030(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2030(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2033)
static void C_ccall trf_2033(C_word c,C_word *av) C_noret;
static void C_ccall trf_2033(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2033(t0,t1);}

C_noret_decl(trf_2061)
static void C_ccall trf_2061(C_word c,C_word *av) C_noret;
static void C_ccall trf_2061(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_2061(t0,t1);}

C_noret_decl(trf_2134)
static void C_ccall trf_2134(C_word c,C_word *av) C_noret;
static void C_ccall trf_2134(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2134(t0,t1,t2,t3);}

C_noret_decl(trf_2153)
static void C_ccall trf_2153(C_word c,C_word *av) C_noret;
static void C_ccall trf_2153(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2153(t0,t1,t2,t3);}

C_noret_decl(trf_2156)
static void C_ccall trf_2156(C_word c,C_word *av) C_noret;
static void C_ccall trf_2156(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2156(t0,t1,t2,t3);}

C_noret_decl(trf_2183)
static void C_ccall trf_2183(C_word c,C_word *av) C_noret;
static void C_ccall trf_2183(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2183(t0,t1,t2,t3);}

C_noret_decl(trf_2201)
static void C_ccall trf_2201(C_word c,C_word *av) C_noret;
static void C_ccall trf_2201(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2201(t0,t1,t2,t3);}

C_noret_decl(trf_2393)
static void C_ccall trf_2393(C_word c,C_word *av) C_noret;
static void C_ccall trf_2393(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2393(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2458)
static void C_ccall trf_2458(C_word c,C_word *av) C_noret;
static void C_ccall trf_2458(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2458(t0,t1,t2);}

C_noret_decl(trf_2559)
static void C_ccall trf_2559(C_word c,C_word *av) C_noret;
static void C_ccall trf_2559(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2559(t0,t1,t2);}

C_noret_decl(trf_2703)
static void C_ccall trf_2703(C_word c,C_word *av) C_noret;
static void C_ccall trf_2703(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2703(t0,t1,t2);}

C_noret_decl(trf_2760)
static void C_ccall trf_2760(C_word c,C_word *av) C_noret;
static void C_ccall trf_2760(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2760(t0,t1,t2,t3);}

C_noret_decl(trf_2763)
static void C_ccall trf_2763(C_word c,C_word *av) C_noret;
static void C_ccall trf_2763(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2763(t0,t1,t2,t3);}

C_noret_decl(trf_2796)
static void C_ccall trf_2796(C_word c,C_word *av) C_noret;
static void C_ccall trf_2796(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2796(t0,t1,t2,t3);}

C_noret_decl(trf_2830)
static void C_ccall trf_2830(C_word c,C_word *av) C_noret;
static void C_ccall trf_2830(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_2830(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_2982)
static void C_ccall trf_2982(C_word c,C_word *av) C_noret;
static void C_ccall trf_2982(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_2982(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_3008)
static void C_ccall trf_3008(C_word c,C_word *av) C_noret;
static void C_ccall trf_3008(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_3008(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_3017)
static void C_ccall trf_3017(C_word c,C_word *av) C_noret;
static void C_ccall trf_3017(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_3017(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_3023)
static void C_ccall trf_3023(C_word c,C_word *av) C_noret;
static void C_ccall trf_3023(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3023(t0,t1,t2,t3);}

C_noret_decl(trf_3090)
static void C_ccall trf_3090(C_word c,C_word *av) C_noret;
static void C_ccall trf_3090(C_word c,C_word *av){
C_word t0=av[8];
C_word t1=av[7];
C_word t2=av[6];
C_word t3=av[5];
C_word t4=av[4];
C_word t5=av[3];
C_word t6=av[2];
C_word t7=av[1];
C_word t8=av[0];
f_3090(t0,t1,t2,t3,t4,t5,t6,t7,t8);}

C_noret_decl(trf_3093)
static void C_ccall trf_3093(C_word c,C_word *av) C_noret;
static void C_ccall trf_3093(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_3093(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_3132)
static void C_ccall trf_3132(C_word c,C_word *av) C_noret;
static void C_ccall trf_3132(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_3132(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_3171)
static void C_ccall trf_3171(C_word c,C_word *av) C_noret;
static void C_ccall trf_3171(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3171(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3301)
static void C_ccall trf_3301(C_word c,C_word *av) C_noret;
static void C_ccall trf_3301(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_3301(t0,t1,t2);}

C_noret_decl(trf_3311)
static void C_ccall trf_3311(C_word c,C_word *av) C_noret;
static void C_ccall trf_3311(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3311(t0,t1);}

C_noret_decl(trf_3466)
static void C_ccall trf_3466(C_word c,C_word *av) C_noret;
static void C_ccall trf_3466(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_3466(t0,t1,t2,t3,t4);}

C_noret_decl(trf_3504)
static void C_ccall trf_3504(C_word c,C_word *av) C_noret;
static void C_ccall trf_3504(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_3504(t0,t1,t2,t3);}

C_noret_decl(trf_3520)
static void C_ccall trf_3520(C_word c,C_word *av) C_noret;
static void C_ccall trf_3520(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3520(t0,t1);}

C_noret_decl(trf_3539)
static void C_ccall trf_3539(C_word c,C_word *av) C_noret;
static void C_ccall trf_3539(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_3539(t0,t1);}

/* k1100 */
static void C_ccall f_1102(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_1102,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1105,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k1103 in k1100 */
static void C_ccall f_1105(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(54,c,6)))){
C_save_and_reclaim((void *)f_1105,c,av);}
a=C_alloc(54);
t2=*((C_word*)lf[2]+1);
t3=C_mutate((C_word*)lf[3]+1 /* (set! chicken.io#read-list ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1107,a[2]=t2,a[3]=((C_word)li1),tmp=(C_word)a,a+=4,tmp));
t4=C_mutate((C_word*)lf[7]+1 /* (set! chicken.io#read-line ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1210,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[15]+1 /* (set! chicken.io#read-lines ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1363,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[19]+1 /* (set! chicken.io#write-line ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1453,a[2]=((C_word)li7),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[23]+1 /* (set! chicken.io#read-string!/port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1481,a[2]=((C_word)li10),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[24]+1 /* (set! chicken.io#read-string! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1613,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[26]+1 /* (set! chicken.io#read-string/port ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1690,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[32]+1 /* (set! chicken.io#read-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1758,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[26]+1 /* (set! chicken.io#read-string/port ...) */,*((C_word*)lf[26]+1));
t12=C_mutate((C_word*)lf[23]+1 /* (set! chicken.io#read-string!/port ...) */,*((C_word*)lf[23]+1));
t13=C_mutate((C_word*)lf[34]+1 /* (set! chicken.io#read-buffered ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1811,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[37]+1 /* (set! chicken.io#read-token ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1839,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[29]+1 /* (set! chicken.io#write-string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1895,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[40]+1 /* (set! chicken.io#read-byte ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1978,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[42]+1 /* (set! chicken.io#write-byte ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2005,a[2]=((C_word)li23),tmp=(C_word)a,a+=3,tmp));
t18=C_a_i_provide(&a,1,lf[44]);
t19=C_mutate(&lf[45] /* (set! chicken.pretty-print#generic-write ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2030,a[2]=((C_word)li59),tmp=(C_word)a,a+=3,tmp));
t20=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3440,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* extras.scm:553: chicken.base#make-parameter */
t21=*((C_word*)lf[166]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t21;
av2[1]=t20;
av2[2]=C_fix(79);
((C_proc)(void*)(*((C_word*)t21+1)))(3,av2);}}

/* chicken.io#read-list in k1103 in k1100 */
static void C_ccall f_1107(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1107,c,av);}
a=C_alloc(6);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[4]+1):C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?((C_word*)t0)[2]:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=C_rest_nullp(c,4);
t9=(C_truep(t8)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,2,t0));
t10=C_rest_nullp(c,4);
t11=C_i_check_port_2(t3,C_fix(1),C_SCHEME_TRUE,lf[5]);
t12=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1136,a[2]=t9,a[3]=t6,a[4]=t3,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* extras.scm:48: reader */
t13=t6;{
C_word av2[3];
av2[0]=t13;
av2[1]=t12;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t13))(3,av2);}}

/* k1134 in chicken.io#read-list in k1103 in k1100 */
static void C_ccall f_1136(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_1136,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1138,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li0),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_1138(t5,((C_word*)t0)[5],t1,C_fix(0),C_SCHEME_END_OF_LIST);}

/* doloop98 in k1134 in chicken.io#read-list in k1103 in k1100 */
static void C_fcall f_1138(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_1138,5,t0,t1,t2,t3,t4);}
a=C_alloc(7);
t5=C_eofp(t2);
t6=(C_truep(t5)?t5:(C_truep(((C_word*)t0)[2])?C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[2]):C_SCHEME_FALSE));
if(C_truep(t6)){
/* extras.scm:52: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[6]+1);
av2[1]=t1;
av2[2]=t4;
tp(3,av2);}}
else{
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1158,a[2]=t3,a[3]=t2,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* extras.scm:48: reader */
t8=((C_word*)t0)[4];{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t8))(3,av2);}}}

/* k1156 in doloop98 in k1134 in chicken.io#read-list in k1103 in k1100 */
static void C_ccall f_1158(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_1158,c,av);}
a=C_alloc(3);
t2=C_fixnum_plus(((C_word*)t0)[2],C_fix(1));
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t4=((C_word*)((C_word*)t0)[5])[1];
f_1138(t4,((C_word*)t0)[6],t1,t2,t3);}

/* chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_1210,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t3=C_i_pairp(t2);
t4=(C_truep(t3)?C_get_rest_arg(c,2,av,2,t0):*((C_word*)lf[4]+1));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1220,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
t6=C_i_cdr(t2);
t7=C_i_pairp(t6);
t8=t5;
f_1220(t8,(C_truep(t7)?C_i_cadr(t2):C_SCHEME_FALSE));}
else{
t6=t5;
f_1220(t6,C_SCHEME_FALSE);}}

/* k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_fcall f_1220(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_1220,2,t0,t1);}
a=C_alloc(8);
t2=C_i_check_port_2(((C_word*)t0)[2],C_fix(1),C_SCHEME_TRUE,lf[8]);
t3=C_slot(((C_word*)t0)[2],C_fix(2));
t4=C_slot(t3,C_fix(8));
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1230,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word)li2),tmp=(C_word)a,a+=5,tmp);
/* extras.scm:64: g122 */
t6=t5;
f_1230(t6,((C_word*)t0)[3],t4);}
else{
t5=(C_truep(t1)?t1:C_fix(256));
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1243,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t7,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:67: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t8;
av2[2]=((C_word*)t7)[1];
tp(3,av2);}}}

/* g122 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_fcall f_1230(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_1230,3,t0,t1,t2);}
/* extras.scm:64: rl */
t3=t2;{
C_word av2[4];
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}

/* k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1243(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1243,c,av);}
a=C_alloc(12);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1248,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=t5,a[7]=((C_word)li3),tmp=(C_word)a,a+=8,tmp));
t7=((C_word*)t5)[1];
f_1248(t7,((C_word*)t0)[5],C_fix(0));}

/* loop in k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_fcall f_1248(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_1248,3,t0,t1,t2);}
a=C_alloc(8);
t3=(C_truep(((C_word*)t0)[2])?C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]):C_SCHEME_FALSE);
if(C_truep(t3)){
/* extras.scm:70: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t1;
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=C_fix(0);
av2[4]=t2;
tp(5,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1261,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* extras.scm:71: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}}

/* k1259 in loop in k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1261(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1261,c,av);}
a=C_alloc(12);
if(C_truep(C_eofp(t1))){
t2=C_eqp(((C_word*)t0)[2],C_fix(0));
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* extras.scm:75: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[2];
tp(5,av2);}}}
else{
switch(t1){
case C_make_character(10):
/* extras.scm:77: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)((C_word*)t0)[4])[1];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[2];
tp(5,av2);}
case C_make_character(13):
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1294,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:79: scheme#peek-char */
t3=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}
default:
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)t0)[2],((C_word*)((C_word*)t0)[6])[1]))){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1326,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1334,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:87: scheme#make-string */
t4=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=C_setsubchar(((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[2],t1);
/* extras.scm:90: loop */
t3=((C_word*)((C_word*)t0)[7])[1];
f_1248(t3,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[2],C_fix(1)));}}}}

/* k1292 in k1259 in loop in k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1294(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_1294,c,av);}
a=C_alloc(5);
if(C_truep(C_i_char_equalp(t1,C_make_character(10)))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1303,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:81: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}
else{
/* extras.scm:83: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}}

/* k1301 in k1292 in k1259 in loop in k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1303(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1303,c,av);}
/* extras.scm:82: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}

/* k1324 in k1259 in loop in k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1326(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1326,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_fixnum_plus(((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[3])[1]);
t4=C_set_block_item(((C_word*)t0)[3],0,t3);
t5=C_setsubchar(((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[4],((C_word*)t0)[5]);
/* extras.scm:90: loop */
t6=((C_word*)((C_word*)t0)[6])[1];
f_1248(t6,((C_word*)t0)[7],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* k1332 in k1259 in loop in k1241 in k1218 in chicken.io#read-line in k1103 in k1100 */
static void C_ccall f_1334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1334,c,av);}
/* extras.scm:87: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[12]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[12]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=t1;
tp(4,av2);}}

/* chicken.io#read-lines in k1103 in k1100 */
static void C_ccall f_1363(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1363,c,av);}
a=C_alloc(5);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[4]+1):C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=C_i_check_port_2(t3,C_fix(1),C_SCHEME_TRUE,lf[16]);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1382,a[2]=t6,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t6)){
/* extras.scm:95: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t9;
av2[2]=t6;
av2[3]=lf[16];
tp(4,av2);}}
else{
t10=t9;{
C_word *av2=av;
av2[0]=t10;
av2[1]=C_SCHEME_UNDEFINED;
f_1382(2,av2);}}}

/* k1380 in chicken.io#read-lines in k1103 in k1100 */
static void C_ccall f_1382(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_1382,c,av);}
a=C_alloc(7);
t2=(C_truep(((C_word*)t0)[2])?((C_word*)t0)[2]:*((C_word*)lf[17]+1));
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1391,a[2]=t4,a[3]=((C_word*)t0)[3],a[4]=((C_word)li5),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_1391(t6,((C_word*)t0)[4],C_SCHEME_END_OF_LIST,t2);}

/* loop in k1380 in chicken.io#read-lines in k1103 in k1100 */
static void C_fcall f_1391(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_1391,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_eqp(t3,C_fix(0));
if(C_truep(t4)){
/* extras.scm:99: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[6]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1404,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* extras.scm:100: read-line */
t6=*((C_word*)lf[7]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}

/* k1402 in loop in k1380 in chicken.io#read-lines in k1103 in k1100 */
static void C_ccall f_1404(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_1404,c,av);}
a=C_alloc(3);
if(C_truep(C_eofp(t1))){
/* extras.scm:102: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[6]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[6]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[3]);
/* extras.scm:103: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_1391(t3,((C_word*)t0)[2],t2,C_fixnum_difference(((C_word*)t0)[5],C_fix(1)));}}

/* chicken.io#write-line in k1103 in k1100 */
static void C_ccall f_1453(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +4,c,3)))){
C_save_and_reclaim((void*)f_1453,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+4);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
t4=(C_truep(C_eqp(t3,C_SCHEME_END_OF_LIST))?*((C_word*)lf[20]+1):C_slot(t3,C_fix(0)));
t5=C_i_check_port_2(t4,C_fix(2),C_SCHEME_TRUE,lf[21]);
t6=C_i_check_string_2(t2,lf[21]);
t7=C_slot(t4,C_fix(2));
t8=C_slot(t7,C_fix(3));
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1469,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* extras.scm:107: g174 */
t10=t8;{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t10;
av2[1]=t9;
av2[2]=t4;
av2[3]=t2;
((C_proc)C_fast_retrieve_proc(t10))(4,av2);}}

/* k1467 in chicken.io#write-line in k1103 in k1100 */
static void C_ccall f_1469(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1469,c,av);}
/* extras.scm:113: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_make_character(10);
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* chicken.io#read-string!/port in k1103 in k1100 */
static void C_ccall f_1481(C_word c,C_word *av){
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
if(c!=6) C_bad_argc_2(c,6,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_1481,c,av);}
a=C_alloc(9);
t6=C_eqp(t2,C_fix(0));
if(C_truep(t6)){
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_fix(0);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t7=C_slot(t4,C_fix(2));
t8=C_slot(t7,C_fix(7));
if(C_truep(t8)){
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1499,a[2]=t4,a[3]=t10,a[4]=t8,a[5]=t3,a[6]=((C_word)li8),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_1499(t12,t1,t5,t2,C_fix(0));}
else{
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1558,a[2]=t10,a[3]=t3,a[4]=t4,a[5]=((C_word)li9),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_1558(t12,t1,t5,t2,C_fix(0));}}}

/* loop in chicken.io#read-string!/port in k1103 in k1100 */
static void C_fcall f_1499(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,5)))){
C_save_and_reclaim_args((void *)trf_1499,5,t0,t1,t2,t3,t4);}
a=C_alloc(8);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1503,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,a[5]=t3,a[6]=t2,a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
/* extras.scm:124: rdstring */
t6=((C_word*)t0)[4];{
C_word av2[6];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[2];
av2[3]=t3;
av2[4]=((C_word*)t0)[5];
av2[5]=t2;
((C_proc)C_fast_retrieve_proc(t6))(6,av2);}}

/* k1501 in loop in chicken.io#read-string!/port in k1103 in k1100 */
static void C_ccall f_1503(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1503,c,av);}
t2=C_slot(((C_word*)t0)[2],C_fix(5));
t3=C_fixnum_plus(t2,t1);
t4=C_i_set_i_slot(((C_word*)t0)[2],C_fix(5),t3);
t5=C_eqp(t1,C_fix(0));
if(C_truep(t5)){
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_i_not(((C_word*)t0)[5]);
t7=(C_truep(t6)?t6:C_fixnum_lessp(t1,((C_word*)t0)[5]));
if(C_truep(t7)){
t8=C_fixnum_plus(((C_word*)t0)[6],t1);
t9=(C_truep(((C_word*)t0)[5])?C_fixnum_difference(((C_word*)t0)[5],t1):C_SCHEME_FALSE);
/* extras.scm:129: loop */
t10=((C_word*)((C_word*)t0)[7])[1];
f_1499(t10,((C_word*)t0)[3],t8,t9,C_fixnum_plus(((C_word*)t0)[4],t1));}
else{
t8=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_fixnum_plus(t1,((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}}

/* loop in chicken.io#read-string!/port in k1103 in k1100 */
static void C_fcall f_1558(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_1558,5,t0,t1,t2,t3,t4);}
a=C_alloc(8);
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1562,a[2]=t1,a[3]=t4,a[4]=t3,a[5]=t2,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],tmp=(C_word)a,a+=8,tmp);
/* extras.scm:132: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k1560 in loop in chicken.io#read-string!/port in k1103 in k1100 */
static void C_ccall f_1562(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1562,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1565,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_eofp(t1))){
t3=t2;
f_1565(t3,C_fix(0));}
else{
t3=C_setsubchar(((C_word*)t0)[7],((C_word*)t0)[5],t1);
t4=t2;
f_1565(t4,C_fix(1));}}

/* k1563 in k1560 in loop in chicken.io#read-string!/port in k1103 in k1100 */
static void C_fcall f_1565(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_1565,2,t0,t1);}
t2=C_eqp(t1,C_fix(0));
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_not(((C_word*)t0)[4]);
t4=(C_truep(t3)?t3:C_fixnum_lessp(t1,((C_word*)t0)[4]));
if(C_truep(t4)){
t5=C_fixnum_plus(((C_word*)t0)[5],t1);
t6=(C_truep(((C_word*)t0)[4])?C_fixnum_difference(((C_word*)t0)[4],t1):C_SCHEME_FALSE);
/* extras.scm:140: loop */
t7=((C_word*)((C_word*)t0)[6])[1];
f_1558(t7,((C_word*)t0)[2],t5,t6,C_fixnum_plus(((C_word*)t0)[3],t1));}
else{
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=C_fixnum_plus(t1,((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* chicken.io#read-string! in k1103 in k1100 */
static void C_ccall f_1613(C_word c,C_word *av){
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
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_1613,c,av);}
a=C_alloc(9);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t5=C_rest_nullp(c,4);
t6=(C_truep(t5)?*((C_word*)lf[4]+1):C_get_rest_arg(c,4,av,4,t0));
t7=C_rest_nullp(c,4);
t8=C_rest_nullp(c,5);
t9=(C_truep(t8)?C_fix(0):C_get_rest_arg(c,5,av,4,t0));
t10=C_rest_nullp(c,5);
t11=C_i_check_port_2(t6,C_fix(1),C_SCHEME_TRUE,lf[25]);
t12=C_i_check_string_2(t3,lf[25]);
t13=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1635,a[2]=t3,a[3]=t1,a[4]=t4,a[5]=t6,a[6]=t9,tmp=(C_word)a,a+=7,tmp);
if(C_truep(((C_word*)t4)[1])){
/* extras.scm:146: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t13;
av2[2]=((C_word*)t4)[1];
av2[3]=lf[25];
tp(4,av2);}}
else{
t14=t13;{
C_word *av2=av;
av2[0]=t14;
av2[1]=C_SCHEME_UNDEFINED;
f_1635(2,av2);}}}

/* k1633 in chicken.io#read-string! in k1103 in k1100 */
static void C_ccall f_1635(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_1635,c,av);}
a=C_alloc(7);
t2=C_block_size(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1641,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=(C_truep(((C_word*)((C_word*)t0)[4])[1])?C_fixnum_less_or_equal_p(C_fixnum_plus(((C_word*)t0)[6],((C_word*)((C_word*)t0)[4])[1]),t2):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=t3;
f_1641(t5,C_SCHEME_UNDEFINED);}
else{
t5=C_fixnum_difference(t2,((C_word*)t0)[6]);
t6=C_set_block_item(((C_word*)t0)[4],0,t5);
t7=t3;
f_1641(t7,t6);}}

/* k1639 in k1633 in chicken.io#read-string! in k1103 in k1100 */
static void C_fcall f_1641(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_1641,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1644,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:150: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[25];
tp(4,av2);}}

/* k1642 in k1639 in k1633 in chicken.io#read-string! in k1103 in k1100 */
static void C_ccall f_1644(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1644,c,av);}
/* extras.scm:151: read-string!/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[23]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)((C_word*)t0)[3])[1];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=((C_word*)t0)[6];
tp(6,av2);}}

/* chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1690,c,av);}
a=C_alloc(5);
t4=C_eqp(t2,C_fix(0));
if(C_truep(t4)){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=lf[27];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1756,a[2]=t1,a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:158: ##sys#peek-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t5;
av2[2]=t3;
tp(3,av2);}}}

/* k1707 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1709(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_1709,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1712,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:160: read-string!/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[23]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=t1;
av2[4]=((C_word*)t0)[4];
av2[5]=C_fix(0);
tp(6,av2);}}

/* k1710 in k1707 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1712(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1712,c,av);}
t2=C_eqp(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* extras.scm:163: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=t1;
tp(5,av2);}}}

/* k1722 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1724(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1724,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1727,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t2;
av2[2]=C_fix(2048);
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k1725 in k1722 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1727(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1727,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1732,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word)li12),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_1732(t5,((C_word*)t0)[4]);}

/* loop in k1725 in k1722 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_fcall f_1732(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,5)))){
C_save_and_reclaim_args((void *)trf_1732,2,t0,t1);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1736,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:168: read-string!/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[23]+1));
C_word av2[6];
av2[0]=*((C_word*)lf[23]+1);
av2[1]=t2;
av2[2]=C_fix(2048);
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=C_fix(0);
tp(6,av2);}}

/* k1734 in loop in k1725 in k1722 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1736(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_1736,c,av);}
a=C_alloc(4);
t2=C_eqp(t1,C_fix(0));
if(C_truep(t2)){
/* extras.scm:170: chicken.base#get-output-string */
t3=*((C_word*)lf[28]+1);{
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
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1748,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:172: write-string */
t4=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=t1;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k1746 in k1734 in loop in k1725 in k1722 in k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1748(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1748,c,av);}
/* extras.scm:173: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1732(t2,((C_word*)t0)[3]);}

/* k1754 in chicken.io#read-string/port in k1103 in k1100 */
static void C_ccall f_1756(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1756,c,av);}
a=C_alloc(5);
if(C_truep(C_eofp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_FILE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(((C_word*)t0)[3])){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1709,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:159: ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1724,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:165: chicken.base#open-output-string */
t3=*((C_word*)lf[30]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* chicken.io#read-string in k1103 in k1100 */
static void C_ccall f_1758(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_1758,c,av);}
a=C_alloc(5);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?*((C_word*)lf[4]+1):C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=C_i_check_port_2(t6,C_fix(1),C_SCHEME_TRUE,lf[33]);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1777,a[2]=t1,a[3]=t3,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t3)){
/* extras.scm:177: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t9;
av2[2]=t3;
av2[3]=lf[33];
tp(4,av2);}}
else{
/* extras.scm:178: read-string/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t1;
av2[2]=t3;
av2[3]=t6;
tp(4,av2);}}}

/* k1775 in chicken.io#read-string in k1103 in k1100 */
static void C_ccall f_1777(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1777,c,av);}
/* extras.scm:178: read-string/port */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[26]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}

/* chicken.io#read-buffered in k1103 in k1100 */
static void C_ccall f_1811(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1811,c,av);}
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[4]+1):C_get_rest_arg(c,2,av,2,t0));
t4=C_i_check_port_2(t3,C_fix(1),C_SCHEME_TRUE,lf[35]);
t5=C_slot(t3,C_fix(2));
t6=C_slot(t5,C_fix(9));
if(C_truep(t6)){
/* extras.scm:190: rb */
t7=t6;{
C_word av2[3];
av2[0]=t7;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=lf[36];
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* chicken.io#read-token in k1103 in k1100 */
static void C_ccall f_1839(C_word c,C_word *av){
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
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1839,c,av);}
a=C_alloc(5);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?*((C_word*)lf[4]+1):C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_port_2(t4,C_fix(1),C_SCHEME_TRUE,lf[38]);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1849,a[2]=t4,a[3]=t2,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:200: chicken.base#open-output-string */
t7=*((C_word*)lf[30]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* k1847 in chicken.io#read-token in k1103 in k1100 */
static void C_ccall f_1849(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1849,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1854,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word)li16),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_1854(t5,((C_word*)t0)[4]);}

/* loop in k1847 in chicken.io#read-token in k1103 in k1100 */
static void C_fcall f_1854(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_1854,2,t0,t1);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1858,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:202: ##sys#peek-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[31]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[31]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k1856 in loop in k1847 in chicken.io#read-token in k1103 in k1100 */
static void C_ccall f_1858(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1858,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1864,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_eofp(t1);
if(C_truep(C_i_not(t3))){
/* extras.scm:203: pred */
t4=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_1864(2,av2);}}}

/* k1862 in k1856 in loop in k1847 in chicken.io#read-token in k1103 in k1100 */
static void C_ccall f_1864(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_1864,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1867,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1874,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:205: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}
else{
/* extras.scm:207: chicken.base#get-output-string */
t2=*((C_word*)lf[28]+1);{
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

/* k1865 in k1862 in k1856 in loop in k1847 in chicken.io#read-token in k1103 in k1100 */
static void C_ccall f_1867(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1867,c,av);}
/* extras.scm:206: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1854(t2,((C_word*)t0)[3]);}

/* k1872 in k1862 in k1856 in loop in k1847 in chicken.io#read-token in k1103 in k1100 */
static void C_ccall f_1874(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1874,c,av);}
/* extras.scm:205: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* chicken.io#write-string in k1103 in k1100 */
static void C_ccall f_1895(C_word c,C_word *av){
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
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_1895,c,av);}
a=C_alloc(12);
t3=C_i_check_string_2(t2,lf[39]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1900,a[2]=t2,a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1938,a[2]=t4,a[3]=((C_word)li19),tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1943,a[2]=t5,a[3]=((C_word)li20),tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_rest_nullp(c,3))){
/* extras.scm:212: def-n319 */
t7=t6;
f_1943(t7,t1);}
else{
t7=C_get_rest_arg(c,3,av,3,t0);
if(C_truep(C_rest_nullp(c,4))){
/* extras.scm:212: def-port320 */
t8=t5;
f_1938(t8,t1,t7);}
else{
t8=C_get_rest_arg(c,4,av,3,t0);
/* extras.scm:212: body317 */
t9=t4;
f_1900(t9,t1,t7,t8);}}}

/* body317 in chicken.io#write-string in k1103 in k1100 */
static void C_fcall f_1900(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_1900,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_check_port_2(t3,C_fix(2),C_SCHEME_TRUE,lf[39]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1907,a[2]=t3,a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
/* extras.scm:214: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[39];
tp(4,av2);}}
else{
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_UNDEFINED;
f_1907(2,av2);}}}

/* k1905 in body317 in chicken.io#write-string in k1103 in k1100 */
static void C_ccall f_1907(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1907,c,av);}
a=C_alloc(5);
t2=C_slot(((C_word*)t0)[2],C_fix(2));
t3=C_slot(t2,C_fix(3));
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1917,a[2]=t3,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
t5=(C_truep(((C_word*)t0)[4])?C_fixnum_lessp(((C_word*)t0)[4],C_block_size(((C_word*)t0)[5])):C_SCHEME_FALSE);
if(C_truep(t5)){
/* extras.scm:218: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}
else{
/* extras.scm:212: g329 */
t6=t3;{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}}

/* k1915 in k1905 in body317 in chicken.io#write-string in k1103 in k1100 */
static void C_ccall f_1917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1917,c,av);}
/* extras.scm:212: g329 */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* def-port320 in chicken.io#write-string in k1103 in k1100 */
static void C_fcall f_1938(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_1938,3,t0,t1,t2);}
/* extras.scm:212: body317 */
t3=((C_word*)t0)[2];
f_1900(t3,t1,t2,*((C_word*)lf[20]+1));}

/* def-n319 in chicken.io#write-string in k1103 in k1100 */
static void C_fcall f_1943(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_1943,2,t0,t1);}
/* extras.scm:212: def-port320 */
t2=((C_word*)t0)[2];
f_1938(t2,t1,C_SCHEME_FALSE);}

/* chicken.io#read-byte in k1103 in k1100 */
static void C_ccall f_1978(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1978,c,av);}
a=C_alloc(3);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[4]+1):C_get_rest_arg(c,2,av,2,t0));
t4=C_i_check_port_2(t3,C_fix(1),C_SCHEME_TRUE,lf[41]);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1988,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* extras.scm:226: ##sys#read-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[10]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t5;
av2[2]=t3;
tp(3,av2);}}

/* k1986 in chicken.io#read-byte in k1103 in k1100 */
static void C_ccall f_1988(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1988,c,av);}
t2=C_eofp(t1);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t1:C_fix(C_character_code(t1)));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.io#write-byte in k1103 in k1100 */
static void C_ccall f_2005(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2005,c,av);}
a=C_alloc(5);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?*((C_word*)lf[20]+1):C_get_rest_arg(c,3,av,3,t0));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2012,a[2]=t4,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:232: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t5;
av2[2]=t2;
av2[3]=lf[43];
tp(4,av2);}}

/* k2010 in chicken.io#write-byte in k1103 in k1100 */
static void C_ccall f_2012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2012,c,av);}
t2=C_i_check_port_2(((C_word*)t0)[2],C_fix(2),C_SCHEME_TRUE,lf[43]);
/* extras.scm:234: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=C_make_character(C_unfix(((C_word*)t0)[4]));
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}

/* chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2030(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(43,0,4)))){
C_save_and_reclaim_args((void *)trf_2030,5,t1,t2,t3,t4,t5);}
a=C_alloc(43);
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
t16=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2033,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp));
t17=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2095,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp));
t18=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2134,a[2]=t5,a[3]=((C_word)li26),tmp=(C_word)a,a+=4,tmp));
t19=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2153,a[2]=t13,a[3]=t9,a[4]=t11,a[5]=t7,a[6]=t3,a[7]=((C_word)li34),tmp=(C_word)a,a+=8,tmp));
t20=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2760,a[2]=t11,a[3]=t3,a[4]=t4,a[5]=t13,a[6]=t9,a[7]=t7,a[8]=((C_word)li58),tmp=(C_word)a,a+=9,tmp));
if(C_truep(t4)){
t21=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3427,a[2]=t11,a[3]=t1,a[4]=t15,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t21;
av2[2]=C_fix(1);
av2[3]=C_make_character(10);
tp(4,av2);}}
else{
/* extras.scm:548: wr */
t21=((C_word*)t13)[1];
f_2153(t21,t1,t2,C_fix(0));}}

/* read-macro? in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2033(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_2033,2,t1,t2);}
a=C_alloc(4);
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=C_eqp(t3,lf[46]);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2061,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t5)){
t7=t6;
f_2061(t7,t5);}
else{
t7=C_eqp(t3,lf[47]);
if(C_truep(t7)){
t8=t6;
f_2061(t8,t7);}
else{
t8=C_eqp(t3,lf[48]);
t9=t6;
f_2061(t9,(C_truep(t8)?t8:C_eqp(t3,lf[49])));}}}

/* k2059 in read-macro? in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2061(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,1)))){
C_save_and_reclaim_args((void *)trf_2061,2,t0,t1);}
if(C_truep(t1)){
t2=C_i_pairp(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t3;
av2[1]=(C_truep(t2)?C_i_nullp(C_u_i_cdr(((C_word*)t0)[2])):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* read-macro-prefix in chicken.pretty-print#generic-write in k1103 in k1100 */
static C_word C_fcall f_2095(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_stack_overflow_check;{}
t2=C_i_car(t1);
t3=C_u_i_cdr(t1);
t4=C_eqp(t2,lf[46]);
if(C_truep(t4)){
return(lf[50]);}
else{
t5=C_eqp(t2,lf[47]);
if(C_truep(t5)){
return(lf[51]);}
else{
t6=C_eqp(t2,lf[48]);
if(C_truep(t6)){
return(lf[52]);}
else{
t7=C_eqp(t2,lf[49]);
return((C_truep(t7)?lf[53]:C_SCHEME_UNDEFINED));}}}}

/* out in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2134(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_2134,4,t0,t1,t2,t3);}
a=C_alloc(5);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2144,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:275: output */
t5=((C_word*)t0)[2];{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2142 in out in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,1)))){
C_save_and_reclaim((void *)f_2144,c,av);}
a=C_alloc(29);
if(C_truep(t1)){
t2=C_i_string_length(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_s_a_i_plus(&a,2,((C_word*)t0)[4],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2153(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(22,0,4)))){
C_save_and_reclaim_args((void *)trf_2153,4,t0,t1,t2,t3);}
a=C_alloc(22);
t4=C_SCHEME_UNDEFINED;
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2156,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t6,a[6]=((C_word*)t0)[5],a[7]=((C_word)li27),tmp=(C_word)a,a+=8,tmp);
t8=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2183,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word)li29),tmp=(C_word)a,a+=5,tmp));
if(C_truep(C_i_pairp(t2))){
/* extras.scm:295: wr-expr */
t9=t4;
f_2156(t9,t1,t2,t3);}
else{
if(C_truep(C_i_nullp(t2))){
/* extras.scm:296: wr-lst */
t9=((C_word*)t6)[1];
f_2183(t9,t1,t2,t3);}
else{
if(C_truep(C_eofp(t2))){
/* extras.scm:297: out */
t9=((C_word*)((C_word*)t0)[4])[1];
f_2134(t9,t1,lf[60],t3);}
else{
if(C_truep(C_bwpp(t2))){
/* extras.scm:299: out */
t9=((C_word*)((C_word*)t0)[4])[1];
f_2134(t9,t1,lf[61],t3);}
else{
if(C_truep(C_i_vectorp(t2))){
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2307,a[2]=t6,a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* extras.scm:300: scheme#vector->list */
t10=*((C_word*)lf[63]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
if(C_truep(C_booleanp(t2))){
if(C_truep(t2)){
/* extras.scm:301: out */
t9=((C_word*)((C_word*)t0)[4])[1];
f_2134(t9,t1,lf[64],t3);}
else{
/* extras.scm:301: out */
t9=((C_word*)((C_word*)t0)[4])[1];
f_2134(t9,t1,lf[65],t3);}}
else{
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2330,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t3,a[5]=t2,a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:302: ##sys#number? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[99]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[99]+1);
av2[1]=t9;
av2[2]=t2;
tp(3,av2);}}}}}}}}

/* wr-expr in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2156(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_2156,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2163,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=t3,a[8]=((C_word*)t0)[5],tmp=(C_word)a,a+=9,tmp);
/* extras.scm:280: read-macro? */
f_2033(t4,t2);}

/* k2161 in wr-expr in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2163(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2163,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2174,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t4=(
/* extras.scm:281: read-macro-prefix */
  f_2095(((C_word*)t0)[2])
);
/* extras.scm:281: out */
t5=((C_word*)((C_word*)t0)[6])[1];
f_2134(t5,t3,t4,((C_word*)t0)[7]);}
else{
/* extras.scm:282: wr-lst */
t2=((C_word*)((C_word*)t0)[8])[1];
f_2183(t2,((C_word*)t0)[4],((C_word*)t0)[2],((C_word*)t0)[7]);}}

/* k2172 in k2161 in wr-expr in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2174(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2174,c,av);}
/* extras.scm:281: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2183(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_2183,4,t0,t1,t2,t3);}
a=C_alloc(11);
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2199,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
t6=C_u_i_car(t2);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2258,a[2]=((C_word*)t0)[2],a[3]=t5,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:287: out */
t8=((C_word*)((C_word*)t0)[3])[1];
f_2134(t8,t7,lf[58],t3);}
else{
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_2199(2,av2);}}}
else{
/* extras.scm:293: out */
t4=((C_word*)((C_word*)t0)[3])[1];
f_2134(t4,t1,lf[59],t3);}}

/* k2197 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2199(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2199,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2201,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li28),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_2201(t5,((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* loop in k2197 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2201(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_2201,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_not(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2223,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_u_i_car(t2);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2229,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:290: out */
t8=((C_word*)((C_word*)t0)[4])[1];
f_2134(t8,t7,lf[54],t3);}
else{
if(C_truep(C_i_nullp(t2))){
/* extras.scm:291: out */
t4=((C_word*)((C_word*)t0)[4])[1];
f_2134(t4,t1,lf[55],t3);}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2245,a[2]=((C_word*)t0)[4],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2249,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:292: out */
t6=((C_word*)((C_word*)t0)[4])[1];
f_2134(t6,t5,lf[57],t3);}}}}

/* k2221 in loop in k2197 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2223(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2223,c,av);}
/* extras.scm:290: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2201(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2227 in loop in k2197 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2229(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2229,c,av);}
/* extras.scm:290: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2243 in loop in k2197 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2245(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2245,c,av);}
/* extras.scm:292: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[56],t1);}

/* k2247 in loop in k2197 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2249(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2249,c,av);}
/* extras.scm:292: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2256 in wr-lst in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2258,c,av);}
/* extras.scm:287: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2305 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2307(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2307,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2311,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:300: out */
t3=((C_word*)((C_word*)t0)[4])[1];
f_2134(t3,t2,lf[62],((C_word*)t0)[5]);}

/* k2309 in k2305 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2311(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2311,c,av);}
/* extras.scm:300: wr-lst */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2183(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2330(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_2330,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2337,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:302: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[66]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[66]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2343,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:303: chicken.keyword#keyword? */
t3=*((C_word*)lf[98]+1);{
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

/* k2335 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2337(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2337,c,av);}
/* extras.scm:302: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2343(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_2343,c,av);}
a=C_alloc(7);
t2=(C_truep(t1)?t1:C_i_symbolp(((C_word*)t0)[2]));
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2349,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:304: chicken.base#open-output-string */
t4=*((C_word*)lf[30]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_closurep(((C_word*)t0)[2]))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2372,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:307: ##sys#procedure->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[68]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[68]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
if(C_truep(C_i_stringp(((C_word*)t0)[2]))){
if(C_truep(((C_word*)t0)[6])){
/* extras.scm:310: out */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2134(t3,((C_word*)t0)[4],((C_word*)t0)[2],((C_word*)t0)[5]);}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2391,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:311: out */
t4=((C_word*)((C_word*)t0)[3])[1];
f_2134(t4,t3,lf[76],((C_word*)t0)[5]);}}
else{
if(C_truep(C_charp(((C_word*)t0)[2]))){
if(C_truep(((C_word*)t0)[6])){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2544,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t3;
av2[2]=C_fix(1);
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}
else{
t3=C_fix(C_character_code(((C_word*)t0)[2]));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2552,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[4],a[5]=t3,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:348: out */
t5=((C_word*)((C_word*)t0)[3])[1];
f_2134(t5,t4,lf[81],((C_word*)t0)[5]);}}
else{
if(C_truep(C_undefinedp(((C_word*)t0)[2]))){
/* extras.scm:359: out */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2134(t3,((C_word*)t0)[4],lf[82],((C_word*)t0)[5]);}
else{
if(C_truep(C_unboundvaluep(((C_word*)t0)[2]))){
/* extras.scm:360: out */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2134(t3,((C_word*)t0)[4],lf[83],((C_word*)t0)[5]);}
else{
if(C_truep(C_immp(((C_word*)t0)[2]))){
/* extras.scm:361: out */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2134(t3,((C_word*)t0)[4],lf[84],((C_word*)t0)[5]);}
else{
if(C_truep(C_anypointerp(((C_word*)t0)[2]))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2650,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:362: ##sys#pointer->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[85]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[85]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}
else{
if(C_truep(C_structurep(((C_word*)t0)[2]))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2659,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:364: chicken.base#open-output-string */
t4=*((C_word*)lf[30]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2675,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:367: chicken.base#port? */
t4=*((C_word*)lf[97]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}}}}}}}}}

/* k2347 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2349(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2349,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2352,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* extras.scm:305: ##sys#print */
t3=*((C_word*)lf[67]+1);{
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
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k2350 in k2347 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2352,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2359,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:306: chicken.base#get-output-string */
t3=*((C_word*)lf[28]+1);{
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

/* k2357 in k2350 in k2347 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2359,c,av);}
/* extras.scm:306: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2370 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2372,c,av);}
/* extras.scm:307: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_2391,c,av);}
a=C_alloc(8);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2393,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word)li31),tmp=(C_word)a,a+=6,tmp));
t5=((C_word*)t3)[1];
f_2393(t5,((C_word*)t0)[4],C_fix(0),C_fix(0),t1);}

/* loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2393(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word t17;
C_word t18;
C_word t19;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(20,0,4)))){
C_save_and_reclaim_args((void *)trf_2393,5,t0,t1,t2,t3,t4);}
a=C_alloc(20);
t5=(C_truep(t4)?C_fixnum_lessp(t3,C_i_string_length(((C_word*)t0)[2])):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_string_ref(((C_word*)t0)[2],t3);
t7=C_u_i_char_equalp(t6,C_make_character(92));
t8=(C_truep(t7)?t7:C_u_i_char_equalp(t6,C_make_character(34)));
if(C_truep(t8)){
t9=C_a_i_fixnum_plus(&a,2,t3,C_fix(1));
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2421,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,a[5]=t9,tmp=(C_word)a,a+=6,tmp);
t11=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2425,a[2]=((C_word*)t0)[4],a[3]=t10,tmp=(C_word)a,a+=4,tmp);
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2429,a[2]=((C_word*)t0)[4],a[3]=t11,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:320: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t12;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}
else{
t9=C_u_i_char_lessp(t6,C_make_character(32));
t10=(C_truep(t9)?t9:C_u_i_char_equalp(t6,C_make_character(127)));
if(C_truep(t10)){
t11=C_fixnum_plus(t3,C_fix(1));
t12=C_fixnum_plus(t3,C_fix(1));
t13=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2452,a[2]=t6,a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t11,a[6]=t12,a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2499,a[2]=((C_word*)t0)[4],a[3]=t13,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:327: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t14;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}
else{
/* extras.scm:342: loop */
t16=t1;
t17=t2;
t18=C_fixnum_plus(t3,C_fix(1));
t19=t4;
t1=t16;
t2=t17;
t3=t18;
t4=t19;
goto loop;}}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2517,a[2]=((C_word*)t0)[4],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2521,a[2]=((C_word*)t0)[4],a[3]=t6,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:344: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t7;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}}

/* k2419 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2421(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2421,c,av);}
/* extras.scm:317: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2393(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k2423 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2425,c,av);}
/* extras.scm:319: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[69],t1);}

/* k2427 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2429(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2429,c,av);}
/* extras.scm:320: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2450 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2452(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_2452,c,av);}
a=C_alloc(12);
t2=C_u_i_assq(((C_word*)t0)[2],lf[70]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2457,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t2)){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2458,a[2]=((C_word*)t0)[7],a[3]=t1,a[4]=((C_word)li30),tmp=(C_word)a,a+=5,tmp);
/* extras.scm:328: g507 */
t5=t4;
f_2458(t5,t3,t2);}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2476,a[2]=((C_word*)t0)[7],a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* ##sys#fixnum->string */
t5=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_fix(C_character_code(((C_word*)t0)[2]));
av2[3]=C_fix(16);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k2455 in k2450 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2457(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2457,c,av);}
/* extras.scm:324: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2393(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* g507 in k2450 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2458(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_2458,3,t0,t1,t2);}
/* extras.scm:337: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t1,C_i_cdr(t2),((C_word*)t0)[3]);}

/* k2474 in k2450 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2476(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2476,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2480,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=(C_truep(C_u_i_char_lessp(((C_word*)t0)[4],C_make_character(16)))?lf[71]:lf[72]);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2488,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:341: out */
t5=((C_word*)((C_word*)t0)[2])[1];
f_2134(t5,t4,lf[73],((C_word*)t0)[5]);}

/* k2478 in k2474 in k2450 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2480(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2480,c,av);}
/* extras.scm:339: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2486 in k2474 in k2450 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2488,c,av);}
/* extras.scm:340: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2497 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2499(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2499,c,av);}
/* extras.scm:327: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2515 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2517(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2517,c,av);}
/* extras.scm:343: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[75],t1);}

/* k2519 in loop in k2389 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2521(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2521,c,av);}
/* extras.scm:344: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2542 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2544,c,av);}
/* extras.scm:346: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_2552,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2555,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:349: chicken.base#char-name */
t3=*((C_word*)lf[80]+1);{
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

/* k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2555(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_2555,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2559,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li32),tmp=(C_word)a,a+=5,tmp);
/* extras.scm:349: g518 */
t3=t2;
f_2559(t3,((C_word*)t0)[4],t1);}
else{
if(C_truep(C_fixnum_lessp(((C_word*)t0)[5],C_fix(32)))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2579,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:353: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t2,lf[77],((C_word*)t0)[3]);}
else{
if(C_truep(C_fixnum_greaterp(((C_word*)t0)[5],C_fix(255)))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2597,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_greaterp(((C_word*)t0)[5],C_fix(65535)))){
/* extras.scm:356: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t2,lf[78],((C_word*)t0)[3]);}
else{
/* extras.scm:356: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t2,lf[79],((C_word*)t0)[3]);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2620,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t2;
av2[2]=C_fix(1);
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}}}}

/* g518 in k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2559(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_2559,3,t0,t1,t2);}
/* extras.scm:351: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t1,C_slot(t2,C_fix(1)),((C_word*)t0)[3]);}

/* k2577 in k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2579(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2579,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2586,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#fixnum->string */
t3=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(16);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2584 in k2577 in k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2586,c,av);}
/* extras.scm:354: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2595 in k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2597,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2604,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* ##sys#fixnum->string */
t3=*((C_word*)lf[74]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(16);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k2602 in k2595 in k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2604(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2604,c,av);}
/* extras.scm:357: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2618 in k2553 in k2550 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2620,c,av);}
/* extras.scm:358: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2648 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2650,c,av);}
/* extras.scm:362: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2657 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2659(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2659,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2662,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* extras.scm:365: ##sys#user-print-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[86]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[86]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_SCHEME_TRUE;
av2[4]=t1;
tp(5,av2);}}

/* k2660 in k2657 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2662(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_2662,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2669,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:366: chicken.base#get-output-string */
t3=*((C_word*)lf[28]+1);{
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

/* k2667 in k2660 in k2657 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2669(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2669,c,av);}
/* extras.scm:366: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2675(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_2675,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2682,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:367: scheme#string-append */
t3=*((C_word*)lf[87]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[88];
av2[3]=C_slot(((C_word*)t0)[5],C_fix(3));
av2[4]=lf[89];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
if(C_truep(C_bytevectorp(((C_word*)t0)[5]))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2692,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:369: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t2,lf[92],((C_word*)t0)[4]);}
else{
if(C_truep(C_lambdainfop(((C_word*)t0)[5]))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2742,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* extras.scm:379: out */
t3=((C_word*)((C_word*)t0)[2])[1];
f_2134(t3,t2,lf[95],((C_word*)t0)[4]);}
else{
/* extras.scm:382: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[96],((C_word*)t0)[4]);}}}}

/* k2680 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2682,c,av);}
/* extras.scm:367: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2690 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2692(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_2692,c,av);}
a=C_alloc(15);
t2=C_block_size(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2698,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2703,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t5,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[5],a[7]=((C_word)li33),tmp=(C_word)a,a+=8,tmp));
t7=((C_word*)t5)[1];
f_2703(t7,t3,C_fix(0));}

/* k2696 in k2690 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2698,c,av);}
/* extras.scm:377: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[90],((C_word*)t0)[4]);}

/* doloop527 in k2690 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2703(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_2703,3,t0,t1,t2);}
a=C_alloc(8);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_subbyte(((C_word*)t0)[3],t2);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2716,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t3,tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_fixnum_lessp(t3,C_fix(16)))){
/* extras.scm:375: out */
t5=((C_word*)((C_word*)t0)[5])[1];
f_2134(t5,t4,lf[91],((C_word*)t0)[6]);}
else{
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_2716(2,av2);}}}}

/* k2714 in doloop527 in k2690 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_2716,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2719,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2730,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:376: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[66]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[66]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
av2[3]=C_fix(16);
tp(4,av2);}}

/* k2717 in k2714 in doloop527 in k2690 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2719(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2719,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2703(t2,((C_word*)t0)[3],C_fixnum_plus(((C_word*)t0)[4],C_fix(1)));}

/* k2728 in k2714 in doloop527 in k2690 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2730(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2730,c,av);}
/* extras.scm:376: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2740 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2742(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_2742,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2745,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2752,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:380: ##sys#lambda-info->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[94]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[94]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
tp(3,av2);}}

/* k2743 in k2740 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2745(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2745,c,av);}
/* extras.scm:381: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[93],((C_word*)t0)[4]);}

/* k2750 in k2740 in k2673 in k2341 in k2328 in wr in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2752(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2752,c,av);}
/* extras.scm:380: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2760(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(152,0,9)))){
C_save_and_reclaim_args((void *)trf_2760,4,t0,t1,t2,t3);}
a=C_alloc(152);
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
t34=C_SCHEME_UNDEFINED;
t35=(*a=C_VECTOR_TYPE|1,a[1]=t34,tmp=(C_word)a,a+=2,tmp);
t36=C_SCHEME_UNDEFINED;
t37=(*a=C_VECTOR_TYPE|1,a[1]=t36,tmp=(C_word)a,a+=2,tmp);
t38=C_SCHEME_UNDEFINED;
t39=(*a=C_VECTOR_TYPE|1,a[1]=t38,tmp=(C_word)a,a+=2,tmp);
t40=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2763,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=((C_word)li35),tmp=(C_word)a,a+=5,tmp));
t41=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2796,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=((C_word)li36),tmp=(C_word)a,a+=5,tmp));
t42=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2830,a[2]=((C_word*)t0)[2],a[3]=t15,a[4]=t11,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word)li38),tmp=(C_word)a,a+=9,tmp));
t43=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_2917,a[2]=t9,a[3]=t11,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[2],a[6]=t19,a[7]=t13,a[8]=t39,a[9]=t15,a[10]=((C_word*)t0)[7],a[11]=((C_word)li39),tmp=(C_word)a,a+=12,tmp));
t44=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2982,a[2]=t17,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],a[5]=((C_word)li40),tmp=(C_word)a,a+=6,tmp));
t45=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3008,a[2]=t17,a[3]=((C_word*)t0)[2],a[4]=((C_word)li41),tmp=(C_word)a,a+=5,tmp));
t46=C_set_block_item(t17,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3017,a[2]=t9,a[3]=t7,a[4]=((C_word*)t0)[2],a[5]=((C_word)li43),tmp=(C_word)a,a+=6,tmp));
t47=C_set_block_item(t19,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3090,a[2]=t9,a[3]=t7,a[4]=t17,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[2],a[7]=((C_word)li47),tmp=(C_word)a,a+=8,tmp));
t48=C_set_block_item(t21,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3230,a[2]=t15,a[3]=t11,a[4]=((C_word)li48),tmp=(C_word)a,a+=5,tmp));
t49=C_set_block_item(t23,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3236,a[2]=t19,a[3]=t21,a[4]=t11,a[5]=((C_word)li49),tmp=(C_word)a,a+=6,tmp));
t50=C_set_block_item(t25,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3242,a[2]=t19,a[3]=t11,a[4]=((C_word)li50),tmp=(C_word)a,a+=5,tmp));
t51=C_set_block_item(t27,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3248,a[2]=t13,a[3]=t21,a[4]=((C_word)li51),tmp=(C_word)a,a+=5,tmp));
t52=C_set_block_item(t29,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3254,a[2]=t19,a[3]=t11,a[4]=t21,a[5]=((C_word)li52),tmp=(C_word)a,a+=6,tmp));
t53=C_set_block_item(t31,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3260,a[2]=t13,a[3]=t11,a[4]=((C_word)li53),tmp=(C_word)a,a+=5,tmp));
t54=C_set_block_item(t33,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3266,a[2]=t19,a[3]=t21,a[4]=t11,a[5]=((C_word)li54),tmp=(C_word)a,a+=6,tmp));
t55=C_set_block_item(t35,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3286,a[2]=t19,a[3]=t11,a[4]=((C_word)li55),tmp=(C_word)a,a+=5,tmp));
t56=C_set_block_item(t37,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3292,a[2]=t19,a[3]=t21,a[4]=t11,a[5]=((C_word)li56),tmp=(C_word)a,a+=6,tmp));
t57=C_set_block_item(t39,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3301,a[2]=t23,a[3]=t25,a[4]=t27,a[5]=t29,a[6]=t31,a[7]=t33,a[8]=t35,a[9]=t37,a[10]=((C_word)li57),tmp=(C_word)a,a+=11,tmp));
/* extras.scm:544: pr */
t58=((C_word*)t9)[1];
f_2830(t58,t1,t2,t3,C_fix(0),((C_word*)t11)[1]);}

/* spaces in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2763(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(34,0,4)))){
C_save_and_reclaim_args((void *)trf_2763,4,t0,t1,t2,t3);}
a=C_alloc(34);
if(C_truep(C_i_greaterp(t2,C_fix(0)))){
if(C_truep(C_i_greaterp(t2,C_fix(7)))){
t4=C_s_a_i_minus(&a,2,t2,C_fix(8));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2787,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:389: out */
t6=((C_word*)((C_word*)t0)[3])[1];
f_2134(t6,t5,lf[100],t3);}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2794,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:390: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t4;
av2[2]=lf[101];
av2[3]=C_fix(0);
av2[4]=t2;
tp(5,av2);}}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2785 in spaces in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2787,c,av);}
/* extras.scm:389: spaces */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2763(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2792 in spaces in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2794,c,av);}
/* extras.scm:390: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* indent in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2796(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,0,3)))){
C_save_and_reclaim_args((void *)trf_2796,4,t0,t1,t2,t3);}
a=C_alloc(29);
if(C_truep(t3)){
if(C_truep(C_i_lessp(t2,t3))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2812,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2819,a[2]=((C_word*)t0)[3],a[3]=t4,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[14]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[14]+1);
av2[1]=t5;
av2[2]=C_fix(1);
av2[3]=C_make_character(10);
tp(4,av2);}}
else{
t4=C_s_a_i_minus(&a,2,t2,t3);
/* extras.scm:397: spaces */
t5=((C_word*)((C_word*)t0)[2])[1];
f_2763(t5,t1,t4,t3);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2810 in indent in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2812,c,av);}
if(C_truep(t1)){
/* extras.scm:396: spaces */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2763(t2,((C_word*)t0)[3],((C_word*)t0)[4],C_fix(0));}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k2817 in indent in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2819,c,av);}
/* extras.scm:396: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2830(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(101,0,3)))){
C_save_and_reclaim_args((void *)trf_2830,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(101);
t6=C_i_pairp(t2);
t7=(C_truep(t6)?t6:C_i_vectorp(t2));
if(C_truep(t7)){
t8=C_SCHEME_END_OF_LIST;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_2843,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t9,a[6]=t2,a[7]=t5,a[8]=t4,a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[4],a[11]=((C_word*)t0)[5],tmp=(C_word)a,a+=12,tmp);
t11=C_s_a_i_minus(&a,2,((C_word*)t0)[6],t3);
t12=C_s_a_i_minus(&a,2,t11,t4);
t13=C_s_a_i_plus(&a,2,t12,C_fix(1));
/* extras.scm:402: scheme#max */
t14=*((C_word*)lf[104]+1);{
C_word av2[4];
av2[0]=t14;
av2[1]=t10;
av2[2]=t13;
av2[3]=C_fix(50);
((C_proc)(void*)(*((C_word*)t14+1)))(4,av2);}}
else{
/* extras.scm:413: wr */
t8=((C_word*)((C_word*)t0)[7])[1];
f_2153(t8,t1,t2,t3);}}

/* k2841 in pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2843(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(19,c,5)))){
C_save_and_reclaim((void *)f_2843,c,av);}
a=C_alloc(19);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_2846,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2881,a[2]=((C_word*)t0)[5],a[3]=t3,a[4]=((C_word)li37),tmp=(C_word)a,a+=5,tmp);
/* extras.scm:403: generic-write */
f_2030(t4,((C_word*)t0)[6],((C_word*)t0)[11],C_SCHEME_FALSE,t5);}

/* k2844 in k2841 in pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2846,c,av);}
a=C_alloc(8);
if(C_truep(C_i_greaterp(((C_word*)((C_word*)t0)[2])[1],C_fix(0)))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2859,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* extras.scm:409: chicken.string#reverse-string-append */
t3=*((C_word*)lf[102]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[7]))){
/* extras.scm:411: pp-pair */
t2=((C_word*)t0)[8];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[9];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2875,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
/* extras.scm:412: scheme#vector->list */
t3=*((C_word*)lf[63]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}}

/* k2857 in k2844 in k2841 in pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2859,c,av);}
/* extras.scm:409: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k2873 in k2844 in k2841 in pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2875(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2875,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2879,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:412: out */
t3=((C_word*)((C_word*)t0)[6])[1];
f_2134(t3,t2,lf[103],((C_word*)t0)[7]);}

/* k2877 in k2873 in k2844 in k2841 in pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2879,c,av);}
/* extras.scm:412: pp-list */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3008(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5],((C_word*)((C_word*)t0)[6])[1]);}

/* a2880 in k2841 in pr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2881(C_word c,C_word *av){
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
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(32,c,1)))){
C_save_and_reclaim((void *)f_2881,c,av);}
a=C_alloc(32);
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[2])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t5=C_i_string_length(t2);
t6=C_s_a_i_minus(&a,2,((C_word*)((C_word*)t0)[3])[1],t5);
t7=C_mutate(((C_word *)((C_word*)t0)[3])+1,t6);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_i_greaterp(((C_word*)((C_word*)t0)[3])[1],C_fix(0));
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* pp-expr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2917(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_2917,c,av);}
a=C_alloc(14);
t5=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_2924,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t4,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=t3,a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[8],a[13]=((C_word*)t0)[9],tmp=(C_word)a,a+=14,tmp);
/* extras.scm:416: read-macro? */
f_2033(t5,t2);}

/* k2922 in pp-expr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_2924,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2935,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=(
/* extras.scm:418: read-macro-prefix */
  f_2095(((C_word*)t0)[2])
);
/* extras.scm:418: out */
t5=((C_word*)((C_word*)t0)[8])[1];
f_2134(t5,t3,t4,((C_word*)t0)[9]);}
else{
t2=C_i_car(((C_word*)t0)[2]);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_2951,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[11],a[9]=t2,tmp=(C_word)a,a+=10,tmp);
/* extras.scm:423: style */
t4=((C_word*)((C_word*)t0)[12])[1];
f_3301(t4,t3,t2);}
else{
/* extras.scm:430: pp-list */
t3=((C_word*)((C_word*)t0)[13])[1];
f_3008(t3,((C_word*)t0)[4],((C_word*)t0)[2],((C_word*)t0)[9],((C_word*)t0)[5],((C_word*)((C_word*)t0)[6])[1]);}}}

/* k2933 in k2922 in pp-expr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2935,c,av);}
/* extras.scm:417: pr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2830(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5],((C_word*)((C_word*)t0)[6])[1]);}

/* k2949 in k2922 in pp-expr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_2951,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
/* extras.scm:425: proc */
t2=t1;{
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
av2[4]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2977,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* extras.scm:426: ##sys#symbol->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[105]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[105]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[9];
tp(3,av2);}}}

/* k2975 in k2949 in k2922 in pp-expr in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2977(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_2977,c,av);}
t2=C_i_string_length(t1);
if(C_truep(C_i_greaterp(t2,C_fix(5)))){
/* extras.scm:428: pp-general */
t3=((C_word*)((C_word*)t0)[2])[1];
f_3090(t3,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[7])[1]);}
else{
/* extras.scm:429: pp-call */
t3=((C_word*)((C_word*)t0)[8])[1];
f_2982(t3,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)((C_word*)t0)[7])[1]);}}

/* pp-call in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_2982(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,3)))){
C_save_and_reclaim_args((void *)trf_2982,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(13);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2986,a[2]=t3,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=t1,a[6]=t4,a[7]=t5,tmp=(C_word)a,a+=8,tmp);
t7=C_i_car(t2);
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3006,a[2]=((C_word*)t0)[3],a[3]=t6,a[4]=t7,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:436: out */
t9=((C_word*)((C_word*)t0)[4])[1];
f_2134(t9,t8,lf[106],t3);}

/* k2984 in pp-call in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_2986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,6)))){
C_save_and_reclaim((void *)f_2986,c,av);}
a=C_alloc(29);
if(C_truep(((C_word*)t0)[2])){
t2=C_u_i_cdr(((C_word*)t0)[3]);
t3=C_s_a_i_plus(&a,2,t1,C_fix(1));
/* extras.scm:438: pp-down */
t4=((C_word*)((C_word*)t0)[4])[1];
f_3017(t4,((C_word*)t0)[5],t2,t1,t3,((C_word*)t0)[6],((C_word*)t0)[7]);}
else{
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k3004 in pp-call in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3006(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3006,c,av);}
/* extras.scm:436: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* pp-list in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3008(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_3008,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(7);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3012,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t4,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
/* extras.scm:444: out */
t7=((C_word*)((C_word*)t0)[3])[1];
f_2134(t7,t6,lf[107],t3);}

/* k3010 in pp-list in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_3012,c,av);}
/* extras.scm:445: pp-down */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3017(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,t1,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3017(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_3017,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(12);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_3023,a[2]=t5,a[3]=t8,a[4]=((C_word*)t0)[2],a[5]=t6,a[6]=((C_word*)t0)[3],a[7]=t4,a[8]=((C_word*)t0)[4],a[9]=((C_word)li42),tmp=(C_word)a,a+=10,tmp));
t10=((C_word*)t8)[1];
f_3023(t10,t1,t2,t3);}

/* loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3023(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(41,0,3)))){
C_save_and_reclaim_args((void *)trf_3023,4,t0,t1,t2,t3);}
a=C_alloc(41);
if(C_truep(t3)){
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_cdr(t2);
t5=C_i_nullp(t4);
t6=(C_truep(t5)?C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1)):C_fix(0));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3044,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t8=C_u_i_car(t2);
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3050,a[2]=((C_word*)t0)[4],a[3]=t7,a[4]=t8,a[5]=t6,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:454: indent */
t10=((C_word*)((C_word*)t0)[6])[1];
f_2796(t10,t9,((C_word*)t0)[7],t3);}
else{
if(C_truep(C_i_nullp(t2))){
/* extras.scm:456: out */
t4=((C_word*)((C_word*)t0)[8])[1];
f_2134(t4,t1,lf[108],t3);}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3072,a[2]=((C_word*)t0)[8],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3076,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=t4,a[5]=t2,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3084,a[2]=((C_word*)t0)[6],a[3]=t5,a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3088,a[2]=((C_word*)t0)[8],a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* extras.scm:460: indent */
t8=((C_word*)((C_word*)t0)[6])[1];
f_2796(t8,t7,((C_word*)t0)[7],t3);}}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3042 in loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3044,c,av);}
/* extras.scm:453: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3023(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k3048 in loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3050(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3050,c,av);}
/* extras.scm:454: pr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2830(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k3070 in loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3072(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3072,c,av);}
/* extras.scm:458: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[109],t1);}

/* k3074 in loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,5)))){
C_save_and_reclaim((void *)f_3076,c,av);}
a=C_alloc(29);
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(1));
/* extras.scm:459: pr */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2830(t3,((C_word*)t0)[4],((C_word*)t0)[5],t1,t2,((C_word*)t0)[6]);}

/* k3082 in loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3084(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3084,c,av);}
/* extras.scm:460: indent */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2796(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k3086 in loop in pp-down in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3088(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3088,c,av);}
/* extras.scm:460: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],lf[110],t1);}

/* pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3090(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6,C_word t7,C_word t8){
C_word tmp;
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(42,0,6)))){
C_save_and_reclaim_args((void *)trf_3090,9,t0,t1,t2,t3,t4,t5,t6,t7,t8);}
a=C_alloc(42);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3093,a[2]=t6,a[3]=t4,a[4]=t12,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],a[7]=((C_word)li44),tmp=(C_word)a,a+=8,tmp));
t16=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_3132,a[2]=t7,a[3]=t4,a[4]=t14,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],a[7]=((C_word)li45),tmp=(C_word)a,a+=8,tmp));
t17=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3171,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=t8,a[5]=((C_word)li46),tmp=(C_word)a,a+=6,tmp));
t18=C_i_car(t2);
t19=C_u_i_cdr(t2);
t20=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_3182,a[2]=t5,a[3]=t19,a[4]=t3,a[5]=t10,a[6]=t1,a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
t21=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3228,a[2]=((C_word*)t0)[5],a[3]=t20,a[4]=t18,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:487: out */
t22=((C_word*)((C_word*)t0)[6])[1];
f_2134(t22,t21,lf[112],t3);}

/* tail1 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3093(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(43,0,5)))){
C_save_and_reclaim_args((void *)trf_3093,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(43);
t6=(C_truep(((C_word*)t0)[2])?C_i_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t6)){
t7=C_i_car(t2);
t8=C_u_i_cdr(t2);
t9=C_i_nullp(t8);
t10=(C_truep(t9)?C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1)):C_fix(0));
t11=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3114,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t8,a[5]=t3,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3118,a[2]=((C_word*)t0)[5],a[3]=t11,a[4]=t7,a[5]=t10,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:471: indent */
t13=((C_word*)((C_word*)t0)[6])[1];
f_2796(t13,t12,t5,t4);}
else{
/* extras.scm:472: tail2 */
t7=((C_word*)((C_word*)t0)[4])[1];
f_3132(t7,t1,t2,t3,t4,t5);}}

/* k3112 in tail1 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3114,c,av);}
/* extras.scm:471: tail2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3132(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1,((C_word*)t0)[6]);}

/* k3116 in tail1 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3118(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3118,c,av);}
/* extras.scm:471: pr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2830(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* tail2 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3132(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(42,0,4)))){
C_save_and_reclaim_args((void *)trf_3132,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(42);
t6=(C_truep(((C_word*)t0)[2])?C_i_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t6)){
t7=C_i_car(t2);
t8=C_u_i_cdr(t2);
t9=C_i_nullp(t8);
t10=(C_truep(t9)?C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1)):C_fix(0));
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3153,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t8,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
t12=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3157,a[2]=((C_word*)t0)[5],a[3]=t11,a[4]=t7,a[5]=t10,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:479: indent */
t13=((C_word*)((C_word*)t0)[6])[1];
f_2796(t13,t12,t5,t4);}
else{
/* extras.scm:480: tail3 */
t7=((C_word*)((C_word*)t0)[4])[1];
f_3171(t7,t1,t2,t3,t4);}}

/* k3151 in tail2 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3153,c,av);}
/* extras.scm:479: tail3 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3171(t2,((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1);}

/* k3155 in tail2 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3157(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3157,c,av);}
/* extras.scm:479: pr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2830(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* tail3 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3171(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_3171,5,t0,t1,t2,t3,t4);}
/* extras.scm:483: pp-down */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3017(t5,t1,t2,t4,t3,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k3180 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3182(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(58,c,5)))){
C_save_and_reclaim((void *)f_3182,c,av);}
a=C_alloc(58);
t2=(C_truep(((C_word*)t0)[2])?C_i_pairp(((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t2)){
t3=C_i_car(((C_word*)t0)[3]);
t4=C_u_i_cdr(((C_word*)t0)[3]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3195,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t4,tmp=(C_word)a,a+=6,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3210,a[2]=((C_word*)t0)[7],a[3]=t5,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:491: out */
t7=((C_word*)((C_word*)t0)[8])[1];
f_2134(t7,t6,lf[111],t1);}
else{
t3=C_s_a_i_plus(&a,2,((C_word*)t0)[4],C_fix(2));
t4=C_s_a_i_plus(&a,2,t1,C_fix(1));
/* extras.scm:493: tail1 */
t5=((C_word*)((C_word*)t0)[5])[1];
f_3093(t5,((C_word*)t0)[6],((C_word*)t0)[3],t3,t1,t4);}}

/* k3193 in k3180 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3195(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(58,c,5)))){
C_save_and_reclaim((void *)f_3195,c,av);}
a=C_alloc(58);
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[2],C_fix(2));
t3=C_s_a_i_plus(&a,2,t1,C_fix(1));
/* extras.scm:492: tail1 */
t4=((C_word*)((C_word*)t0)[3])[1];
f_3093(t4,((C_word*)t0)[4],((C_word*)t0)[5],t2,t1,t3);}

/* k3208 in k3180 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3210(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3210,c,av);}
/* extras.scm:491: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k3226 in pp-general in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3228,c,av);}
/* extras.scm:487: wr */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2153(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* pp-expr-list in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3230,c,av);}
/* extras.scm:496: pp-list */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3008(t5,t1,t2,t3,t4,((C_word*)((C_word*)t0)[3])[1]);}

/* pp-lambda in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3236(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3236,c,av);}
/* extras.scm:499: pp-general */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3090(t5,t1,t2,t3,t4,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1],C_SCHEME_FALSE,((C_word*)((C_word*)t0)[4])[1]);}

/* pp-if in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3242(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3242,c,av);}
/* extras.scm:502: pp-general */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3090(t5,t1,t2,t3,t4,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1],C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1]);}

/* pp-cond in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3248(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3248,c,av);}
/* extras.scm:505: pp-call */
t5=((C_word*)((C_word*)t0)[2])[1];
f_2982(t5,t1,t2,t3,t4,((C_word*)((C_word*)t0)[3])[1]);}

/* pp-case in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3254,c,av);}
/* extras.scm:508: pp-general */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3090(t5,t1,t2,t3,t4,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1],C_SCHEME_FALSE,((C_word*)((C_word*)t0)[4])[1]);}

/* pp-and in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_3260,c,av);}
/* extras.scm:511: pp-call */
t5=((C_word*)((C_word*)t0)[2])[1];
f_2982(t5,t1,t2,t3,t4,((C_word*)((C_word*)t0)[3])[1]);}

/* pp-let in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3266(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3266,c,av);}
t5=C_i_cdr(t2);
if(C_truep(C_i_pairp(t5))){
/* extras.scm:516: pp-general */
t6=((C_word*)((C_word*)t0)[2])[1];
f_3090(t6,t1,t2,t3,t4,C_i_symbolp(C_u_i_car(t5)),((C_word*)((C_word*)t0)[3])[1],C_SCHEME_FALSE,((C_word*)((C_word*)t0)[4])[1]);}
else{
/* extras.scm:516: pp-general */
t6=((C_word*)((C_word*)t0)[2])[1];
f_3090(t6,t1,t2,t3,t4,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1],C_SCHEME_FALSE,((C_word*)((C_word*)t0)[4])[1]);}}

/* pp-begin in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3286(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3286,c,av);}
/* extras.scm:519: pp-general */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3090(t5,t1,t2,t3,t4,C_SCHEME_FALSE,C_SCHEME_FALSE,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1]);}

/* pp-do in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3292(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,8)))){
C_save_and_reclaim((void *)f_3292,c,av);}
/* extras.scm:522: pp-general */
t5=((C_word*)((C_word*)t0)[2])[1];
f_3090(t5,t1,t2,t3,t4,C_SCHEME_FALSE,((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[4])[1]);}

/* style in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3301(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_3301,3,t0,t1,t2);}
a=C_alloc(12);
t3=C_eqp(t2,lf[113]);
t4=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_3311,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],tmp=(C_word)a,a+=12,tmp);
if(C_truep(t3)){
t5=t4;
f_3311(t5,t3);}
else{
t5=C_eqp(t2,lf[123]);
if(C_truep(t5)){
t6=t4;
f_3311(t6,t5);}
else{
t6=C_eqp(t2,lf[124]);
if(C_truep(t6)){
t7=t4;
f_3311(t7,t6);}
else{
t7=C_eqp(t2,lf[125]);
t8=t4;
f_3311(t8,(C_truep(t7)?t7:C_eqp(t2,lf[126])));}}}}

/* k3309 in style in pp in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_fcall f_3311(C_word t0,C_word t1){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,1)))){
C_save_and_reclaim_args((void *)trf_3311,2,t0,t1);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_eqp(((C_word*)t0)[4],lf[114]);
t3=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[4],lf[115]));
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)((C_word*)t0)[5])[1];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_eqp(((C_word*)t0)[4],lf[116]);
if(C_truep(t4)){
t5=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t5;
av2[1]=((C_word*)((C_word*)t0)[6])[1];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(((C_word*)t0)[4],lf[117]);
if(C_truep(t5)){
t6=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t6;
av2[1]=((C_word*)((C_word*)t0)[7])[1];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_eqp(((C_word*)t0)[4],lf[118]);
t7=(C_truep(t6)?t6:C_eqp(((C_word*)t0)[4],lf[119]));
if(C_truep(t7)){
t8=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t8;
av2[1]=((C_word*)((C_word*)t0)[8])[1];
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=C_eqp(((C_word*)t0)[4],lf[120]);
if(C_truep(t8)){
t9=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t9;
av2[1]=((C_word*)((C_word*)t0)[9])[1];
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t9=C_eqp(((C_word*)t0)[4],lf[121]);
if(C_truep(t9)){
t10=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t10;
av2[1]=((C_word*)((C_word*)t0)[10])[1];
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t10=C_eqp(((C_word*)t0)[4],lf[122]);
t11=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t11;
av2[1]=(C_truep(t10)?((C_word*)((C_word*)t0)[11])[1]:C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}}}}}}}

/* k3425 in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_3427,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3431,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:547: pp */
t3=((C_word*)((C_word*)t0)[4])[1];
f_2760(t3,t2,((C_word*)t0)[5],C_fix(0));}

/* k3429 in k3425 in chicken.pretty-print#generic-write in k1103 in k1100 */
static void C_ccall f_3431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3431,c,av);}
/* extras.scm:547: out */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2134(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k3438 in k1103 in k1100 */
static void C_ccall f_3440(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,6)))){
C_save_and_reclaim((void *)f_3440,c,av);}
a=C_alloc(29);
t2=C_mutate((C_word*)lf[127]+1 /* (set! chicken.pretty-print#pretty-print-width ...) */,t1);
t3=C_mutate((C_word*)lf[128]+1 /* (set! chicken.pretty-print#pretty-print ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3442,a[2]=((C_word)li61),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[130]+1 /* (set! chicken.pretty-print#pp ...) */,*((C_word*)lf[128]+1));
t5=C_a_i_provide(&a,1,lf[131]);
t6=C_mutate(&lf[132] /* (set! chicken.format#fprintf0 ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3466,a[2]=((C_word)li66),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[140]+1 /* (set! chicken.format#fprintf ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3786,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[142]+1 /* (set! chicken.format#printf ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3792,a[2]=((C_word)li68),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[144]+1 /* (set! chicken.format#sprintf ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3798,a[2]=((C_word)li69),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[146]+1 /* (set! chicken.format#format ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3804,a[2]=((C_word)li70),tmp=(C_word)a,a+=3,tmp));
t11=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3847,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* extras.scm:642: chicken.platform#register-feature! */
t12=*((C_word*)lf[164]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t12;
av2[1]=t11;
av2[2]=lf[165];
((C_proc)(void*)(*((C_word*)t12+1)))(3,av2);}}

/* chicken.pretty-print#pretty-print in k3438 in k1103 in k1100 */
static void C_ccall f_3442(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +8,c,2)))){
C_save_and_reclaim((void*)f_3442,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+8);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t4=C_i_pairp(t3);
t5=(C_truep(t4)?C_get_rest_arg(c,3,av,3,t0):*((C_word*)lf[20]+1));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3449,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3453,a[2]=t5,a[3]=t6,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* extras.scm:557: pretty-print-width */
t8=*((C_word*)lf[127]+1);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* k3447 in chicken.pretty-print#pretty-print in k3438 in k1103 in k1100 */
static void C_ccall f_3449(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3449,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k3451 in chicken.pretty-print#pretty-print in k3438 in k1103 in k1100 */
static void C_ccall f_3453(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,5)))){
C_save_and_reclaim((void *)f_3453,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3455,a[2]=((C_word*)t0)[2],a[3]=((C_word)li60),tmp=(C_word)a,a+=4,tmp);
/* extras.scm:557: generic-write */
f_2030(((C_word*)t0)[3],((C_word*)t0)[4],C_SCHEME_FALSE,t1,t2);}

/* a3454 in k3451 in chicken.pretty-print#pretty-print in k3438 in k1103 in k1100 */
static void C_ccall f_3455(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3455,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3459,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* extras.scm:557: scheme#display */
t4=*((C_word*)lf[129]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k3457 in a3454 in k3451 in chicken.pretty-print#pretty-print in k3438 in k1103 in k1100 */
static void C_ccall f_3459(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3459,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_fcall f_3466(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,2)))){
C_save_and_reclaim_args((void *)trf_3466,5,t1,t2,t3,t4,t5);}
a=C_alloc(11);
t6=(C_truep(t3)?C_i_check_port_2(t3,C_fix(2),C_SCHEME_TRUE,t2):C_SCHEME_UNDEFINED);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3473,a[2]=t3,a[3]=t1,a[4]=t2,a[5]=t4,a[6]=t5,tmp=(C_word)a,a+=7,tmp);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3775,a[2]=t7,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t3)){
/* extras.scm:573: ##sys#tty-port? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[139]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[139]+1);
av2[1]=t8;
av2[2]=t3;
tp(3,av2);}}
else{
/* extras.scm:575: chicken.base#open-output-string */
t9=*((C_word*)lf[30]+1);{
C_word av2[2];
av2[0]=t9;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}

/* k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3473(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_3473,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3476,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3504,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t4,a[5]=((C_word)li65),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_3504(t6,t2,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k3474 in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3476(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_3476,c,av);}
a=C_alloc(4);
if(C_truep(C_i_not(((C_word*)t0)[2]))){
/* extras.scm:619: chicken.base#get-output-string */
t2=*((C_word*)lf[28]+1);{
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
t2=C_eqp(((C_word*)t0)[4],((C_word*)t0)[2]);
if(C_truep(C_i_not(t2))){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3498,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:621: chicken.base#get-output-string */
t4=*((C_word*)lf[28]+1);{
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
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* k3496 in k3474 in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3498(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3498,c,av);}
/* extras.scm:621: ##sys#print */
t2=*((C_word*)lf[67]+1);{
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

/* rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_fcall f_3504(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word t18;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(30,0,2)))){
C_save_and_reclaim_args((void *)trf_3504,4,t0,t1,t2,t3);}
a=C_alloc(30);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_i_check_string_2(t2,((C_word*)t0)[2]);
t6=C_fix(0);
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_block_size(t2);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3513,a[2]=t2,a[3]=t7,tmp=(C_word)a,a+=4,tmp));
t14=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3520,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word)li62),tmp=(C_word)a,a+=5,tmp));
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_3539,a[2]=t7,a[3]=t8,a[4]=t10,a[5]=t16,a[6]=((C_word*)t0)[3],a[7]=t12,a[8]=((C_word*)t0)[2],a[9]=((C_word*)t0)[4],a[10]=((C_word)li64),tmp=(C_word)a,a+=11,tmp));
t18=((C_word*)t16)[1];
f_3539(t18,t1);}

/* fetch in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static C_word C_fcall f_3513(C_word t0){
C_word tmp;
C_word t1;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t1=C_subchar(((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t2=C_fixnum_plus(((C_word*)((C_word*)t0)[3])[1],C_fix(1));
t3=C_set_block_item(((C_word*)t0)[3],0,t2);
return(t1);}

/* next in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_fcall f_3520(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_3520,2,t0,t1);}
if(C_truep(C_eqp(((C_word*)((C_word*)t0)[2])[1],C_SCHEME_END_OF_LIST))){
/* extras.scm:586: ##sys#error */
t2=*((C_word*)lf[133]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[134];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_slot(((C_word*)((C_word*)t0)[2])[1],C_fix(0));
t3=C_slot(((C_word*)((C_word*)t0)[2])[1],C_fix(1));
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_fcall f_3539(C_word t0,C_word t1){
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
C_word t23;
C_word t24;
C_word *a;
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_3539,2,t0,t1);}
a=C_alloc(11);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]))){
t2=C_SCHEME_UNDEFINED;
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(
/* extras.scm:592: fetch */
  f_3513(((C_word*)((C_word*)t0)[4])[1])
);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3552,a[2]=((C_word*)t0)[5],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=C_eqp(t2,C_make_character(126));
t5=(C_truep(t4)?C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=(
/* extras.scm:594: fetch */
  f_3513(((C_word*)((C_word*)t0)[4])[1])
);
t7=C_u_i_char_upcase(t6);
switch(t7){
case C_make_character(83):
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3577,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:596: next */
t9=((C_word*)((C_word*)t0)[7])[1];
f_3520(t9,t8);
case C_make_character(65):
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3590,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:597: next */
t9=((C_word*)((C_word*)t0)[7])[1];
f_3520(t9,t8);
case C_make_character(67):
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3603,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:598: next */
t9=((C_word*)((C_word*)t0)[7])[1];
f_3520(t9,t8);
case C_make_character(66):
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3616,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3620,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
/* extras.scm:599: next */
t10=((C_word*)((C_word*)t0)[7])[1];
f_3520(t10,t9);
case C_make_character(79):
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3633,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3637,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
/* extras.scm:600: next */
t10=((C_word*)((C_word*)t0)[7])[1];
f_3520(t10,t9);
case C_make_character(88):
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3650,a[2]=t3,a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3654,a[2]=t8,tmp=(C_word)a,a+=3,tmp);
/* extras.scm:601: next */
t10=((C_word*)((C_word*)t0)[7])[1];
f_3520(t10,t9);
case C_make_character(33):
/* extras.scm:602: ##sys#flush-output */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[136]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[136]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
tp(3,av2);}
case C_make_character(63):
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3672,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[5],a[4]=t1,a[5]=((C_word*)t0)[9],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* extras.scm:604: next */
t9=((C_word*)((C_word*)t0)[7])[1];
f_3520(t9,t8);
case C_make_character(126):
/* extras.scm:608: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[22]+1);
av2[1]=t3;
av2[2]=C_make_character(126);
av2[3]=((C_word*)t0)[6];
tp(4,av2);}
default:
t8=C_eqp(t7,C_make_character(37));
t9=(C_truep(t8)?t8:C_eqp(t7,C_make_character(78)));
if(C_truep(t9)){
/* extras.scm:609: scheme#newline */
t10=*((C_word*)lf[137]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
if(C_truep(C_u_i_char_whitespacep(t6))){
t10=(
/* extras.scm:612: fetch */
  f_3513(((C_word*)((C_word*)t0)[4])[1])
);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3717,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word)li63),tmp=(C_word)a,a+=5,tmp);
t12=(
  f_3717(t11,t10)
);
/* extras.scm:618: loop */
t24=t1;
t1=t24;
goto loop;}
else{
/* extras.scm:616: ##sys#error */
t10=*((C_word*)lf[133]+1);{
C_word av2[5];
av2[0]=t10;
av2[1]=t3;
av2[2]=((C_word*)t0)[8];
av2[3]=lf[138];
av2[4]=t6;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}}}}
else{
/* extras.scm:617: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[22]+1);
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}}}

/* k3550 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3552(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3552,c,av);}
/* extras.scm:618: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3539(t2,((C_word*)t0)[3]);}

/* k3575 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3577(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3577,c,av);}
/* extras.scm:596: scheme#write */
t2=*((C_word*)lf[135]+1);{
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

/* k3588 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3590,c,av);}
/* extras.scm:597: scheme#display */
t2=*((C_word*)lf[129]+1);{
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

/* k3601 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3603,c,av);}
/* extras.scm:598: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[22]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[22]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}

/* k3614 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3616(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3616,c,av);}
/* extras.scm:599: scheme#display */
t2=*((C_word*)lf[129]+1);{
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

/* k3618 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3620,c,av);}
/* extras.scm:599: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[66]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[66]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(2);
tp(4,av2);}}

/* k3631 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3633(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3633,c,av);}
/* extras.scm:600: scheme#display */
t2=*((C_word*)lf[129]+1);{
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

/* k3635 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3637,c,av);}
/* extras.scm:600: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[66]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[66]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(8);
tp(4,av2);}}

/* k3648 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3650,c,av);}
/* extras.scm:601: scheme#display */
t2=*((C_word*)lf[129]+1);{
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

/* k3652 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3654(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3654,c,av);}
/* extras.scm:601: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[66]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[66]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_fix(16);
tp(4,av2);}}

/* k3670 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_3672,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_3675,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* extras.scm:605: next */
t3=((C_word*)((C_word*)t0)[6])[1];
f_3520(t3,t2);}

/* k3673 in k3670 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3675(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_3675,c,av);}
a=C_alloc(4);
t2=C_i_check_list_2(t1,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3681,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* extras.scm:607: rec */
t4=((C_word*)((C_word*)t0)[5])[1];
f_3504(t4,t3,((C_word*)t0)[6],t1);}

/* k3679 in k3673 in k3670 in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3681(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3681,c,av);}
/* extras.scm:618: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_3539(t2,((C_word*)t0)[3]);}

/* skip in loop in rec in k3471 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static C_word C_fcall f_3717(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_u_i_char_whitespacep(t1))){
t2=(
/* extras.scm:614: fetch */
  f_3513(((C_word*)((C_word*)t0)[2])[1])
);
t5=t2;
t1=t5;
goto loop;}
else{
t2=C_fixnum_difference(((C_word*)((C_word*)t0)[3])[1],C_fix(1));
t3=C_set_block_item(((C_word*)t0)[3],0,t2);
return(t3);}}

/* k3773 in chicken.format#fprintf0 in k3438 in k1103 in k1100 */
static void C_ccall f_3775(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3775,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_3473(2,av2);}}
else{
/* extras.scm:575: chicken.base#open-output-string */
t2=*((C_word*)lf[30]+1);{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.format#fprintf in k3438 in k1103 in k1100 */
static void C_ccall f_3786(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +0,c,5)))){
C_save_and_reclaim((void*)f_3786,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+0);
t4=C_build_rest(&a,c,4,av);
C_word t5;
/* extras.scm:624: fprintf0 */
f_3466(t1,lf[141],t2,t3,t4);}

/* chicken.format#printf in k3438 in k1103 in k1100 */
static void C_ccall f_3792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +0,c,5)))){
C_save_and_reclaim((void*)f_3792,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+0);
t3=C_build_rest(&a,c,3,av);
C_word t4;
/* extras.scm:627: fprintf0 */
f_3466(t1,lf[143],*((C_word*)lf[20]+1),t2,t3);}

/* chicken.format#sprintf in k3438 in k1103 in k1100 */
static void C_ccall f_3798(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +0,c,5)))){
C_save_and_reclaim((void*)f_3798,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+0);
t3=C_build_rest(&a,c,3,av);
C_word t4;
/* extras.scm:630: fprintf0 */
f_3466(t1,lf[145],C_SCHEME_FALSE,t2,t3);}

/* chicken.format#format in k3438 in k1103 in k1100 */
static void C_ccall f_3804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +12,c,3)))){
C_save_and_reclaim((void*)f_3804,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+12);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3812,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_not(t2))){{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[144]+1);
av2[3]=((C_word*)t4)[1];
C_apply(4,av2);}}
else{
if(C_truep(C_booleanp(t2))){{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[142]+1);
av2[3]=((C_word*)t4)[1];
C_apply(4,av2);}}
else{
if(C_truep(C_i_stringp(t2))){
t6=C_a_i_cons(&a,2,t2,((C_word*)t4)[1]);
t7=C_set_block_item(t4,0,t6);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=*((C_word*)lf[144]+1);
av2[3]=((C_word*)t4)[1];
C_apply(4,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3837,a[2]=t2,a[3]=t4,a[4]=t1,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* extras.scm:637: scheme#output-port? */
t7=*((C_word*)lf[149]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}}}

/* k3810 in chicken.format#format in k3438 in k1103 in k1100 */
static void C_ccall f_3812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_3812,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=((C_word*)((C_word*)t0)[3])[1];
C_apply(4,av2);}}

/* k3835 in chicken.format#format in k3438 in k1103 in k1100 */
static void C_ccall f_3837(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_3837,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=*((C_word*)lf[140]+1);
av2[3]=((C_word*)((C_word*)t0)[3])[1];
C_apply(4,av2);}}
else{
/* extras.scm:639: ##sys#error */
t2=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[147];
av2[3]=lf[148];
av2[4]=((C_word*)t0)[2];
av2[5]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}}

/* k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_3847,c,av);}
a=C_alloc(11);
t2=C_a_i_provide(&a,1,lf[150]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3850,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t3;
C_extras_toplevel(2,av2);}}

/* k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3850(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3850,c,av);}
a=C_alloc(13);
t2=C_mutate((C_word*)lf[151]+1 /* (set! chicken.random#set-pseudo-random-seed! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3852,a[2]=((C_word)li71),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[155]+1 /* (set! chicken.random#pseudo-random-integer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3891,a[2]=((C_word)li72),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[158]+1 /* (set! chicken.random#pseudo-random-real ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_3907,a[2]=((C_word)li73),tmp=(C_word)a,a+=3,tmp));
t5=C_fix(C_MOST_POSITIVE_FIXNUM&(C_word)C_RANDOM_STATE_SIZE);
t6=C_mutate((C_word*)lf[159]+1 /* (set! chicken.random#random-bytes ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3910,a[2]=t5,a[3]=((C_word)li74),tmp=(C_word)a,a+=4,tmp));
t7=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}

/* chicken.random#set-pseudo-random-seed! in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3852(C_word c,C_word *av){
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
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_3852,c,av);}
a=C_alloc(11);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3859,a[2]=t2,a[3]=t1,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t6)[1])){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3873,a[2]=t6,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* extras.scm:653: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t8;
av2[2]=((C_word*)t6)[1];
av2[3]=lf[152];
tp(4,av2);}}
else{
t8=C_block_size(t2);
t9=C_set_block_item(t6,0,t8);
t10=t7;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
f_3859(2,av2);}}}

/* k3857 in chicken.random#set-pseudo-random-seed! in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_3859,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3862,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_byteblockp(((C_word*)t0)[2]))){
t3=C_block_size(((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_set_random_seed(((C_word*)t0)[2],C_i_fixnum_min(((C_word*)((C_word*)t0)[4])[1],t3));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* extras.scm:658: ##sys#error */
t3=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[152];
av2[3]=lf[153];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k3860 in k3857 in chicken.random#set-pseudo-random-seed! in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3862,c,av);}
t2=C_block_size(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_set_random_seed(((C_word*)t0)[2],C_i_fixnum_min(((C_word*)((C_word*)t0)[4])[1],t2));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k3871 in chicken.random#set-pseudo-random-seed! in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3873,c,av);}
if(C_truep(C_fixnum_lessp(((C_word*)((C_word*)t0)[2])[1],C_fix(0)))){
/* extras.scm:655: ##sys#error */
t2=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[152];
av2[3]=lf[154];
av2[4]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_3859(2,av2);}}}

/* chicken.random#pseudo-random-integer in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3891(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,4)))){
C_save_and_reclaim((void *)f_3891,c,av);}
a=C_alloc(2);
if(C_truep(C_fixnump(t2))){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_random_fixnum(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_not(C_i_bignump(t2)))){
/* extras.scm:668: ##sys#error */
t3=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[156];
av2[3]=lf[157];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_s_a_u_i_random_int(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* chicken.random#pseudo-random-real in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3907(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(2,c,1)))){
C_save_and_reclaim((void *)f_3907,c,av);}
a=C_alloc(2);
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_random_real(&a,0);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.random#random-bytes in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3910(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_3910,c,av);}
a=C_alloc(10);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?C_SCHEME_FALSE:C_get_rest_arg(c,2,av,2,t0));
t4=C_rest_nullp(c,2);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,2,t0));
t7=C_rest_nullp(c,3);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_3926,a[2]=t6,a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t6)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3974,a[2]=t6,a[3]=t8,tmp=(C_word)a,a+=4,tmp);
/* extras.scm:679: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[18]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[18]+1);
av2[1]=t9;
av2[2]=t6;
av2[3]=lf[160];
tp(4,av2);}}
else{
t9=t8;{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_UNDEFINED;
f_3926(2,av2);}}}

/* k3924 in chicken.random#random-bytes in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_3926,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_3951,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=C_immp(((C_word*)t0)[3]);
if(C_truep(t4)){
if(C_truep(t4)){
/* extras.scm:685: ##sys#error */
t5=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[160];
av2[3]=lf[162];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
f_3929(2,av2);}}}
else{
if(C_truep(C_i_not(C_byteblockp(((C_word*)t0)[3])))){
/* extras.scm:685: ##sys#error */
t5=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[160];
av2[3]=lf[162];
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
f_3929(2,av2);}}}}
else{
if(C_truep(((C_word*)t0)[2])){
/* extras.scm:688: scheme#make-string */
t3=*((C_word*)lf[13]+1);{
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
else{
/* extras.scm:688: scheme#make-string */
t3=*((C_word*)lf[13]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}}}

/* k3927 in k3924 in chicken.random#random-bytes in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3929(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_3929,c,av);}
a=C_alloc(5);
t2=(C_truep(((C_word*)t0)[2])?((C_word*)t0)[2]:C_block_size(t1));
t3=C_random_bytes(t1,t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_3936,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t3)){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
f_3936(2,av2);}}
else{
/* extras.scm:692: ##sys#error */
t5=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[160];
av2[3]=lf[161];
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k3934 in k3927 in k3924 in chicken.random#random-bytes in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3936(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3936,c,av);}
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_string_to_bytevector(((C_word*)t0)[3]);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k3949 in k3924 in chicken.random#random-bytes in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3951(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_3951,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_3929(2,av2);}}

/* k3972 in chicken.random#random-bytes in k3848 in k3845 in k3438 in k1103 in k1100 */
static void C_ccall f_3974(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_3974,c,av);}
if(C_truep(C_i_lessp(((C_word*)t0)[2],C_fix(0)))){
/* extras.scm:681: ##sys#error */
t2=*((C_word*)lf[133]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[160];
av2[3]=lf[163];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}
else{
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_3926(2,av2);}}}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_extras_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("extras"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_extras_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(791))){
C_save(t1);
C_rereclaim2(791*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,167);
lf[0]=C_h_intern(&lf[0],6, C_text("extras"));
lf[1]=C_h_intern(&lf[1],11, C_text("chicken.io#"));
lf[2]=C_h_intern(&lf[2],11, C_text("scheme#read"));
lf[3]=C_h_intern(&lf[3],20, C_text("chicken.io#read-list"));
lf[4]=C_h_intern(&lf[4],20, C_text("##sys#standard-input"));
lf[5]=C_h_intern(&lf[5],9, C_text("read-list"));
lf[6]=C_h_intern(&lf[6],18, C_text("##sys#fast-reverse"));
lf[7]=C_h_intern(&lf[7],20, C_text("chicken.io#read-line"));
lf[8]=C_h_intern(&lf[8],9, C_text("read-line"));
lf[9]=C_h_intern(&lf[9],15, C_text("##sys#substring"));
lf[10]=C_h_intern(&lf[10],17, C_text("##sys#read-char-0"));
lf[11]=C_h_intern(&lf[11],16, C_text("scheme#peek-char"));
lf[12]=C_h_intern(&lf[12],19, C_text("##sys#string-append"));
lf[13]=C_h_intern(&lf[13],18, C_text("scheme#make-string"));
lf[14]=C_h_intern(&lf[14],17, C_text("##sys#make-string"));
lf[15]=C_h_intern(&lf[15],21, C_text("chicken.io#read-lines"));
lf[16]=C_h_intern(&lf[16],10, C_text("read-lines"));
lf[17]=C_h_intern(&lf[17],35, C_text("chicken.fixnum#most-positive-fixnum"));
lf[18]=C_h_intern(&lf[18],18, C_text("##sys#check-fixnum"));
lf[19]=C_h_intern(&lf[19],21, C_text("chicken.io#write-line"));
lf[20]=C_h_intern(&lf[20],21, C_text("##sys#standard-output"));
lf[21]=C_h_intern(&lf[21],10, C_text("write-line"));
lf[22]=C_h_intern(&lf[22],18, C_text("##sys#write-char-0"));
lf[23]=C_h_intern(&lf[23],28, C_text("chicken.io#read-string!/port"));
lf[24]=C_h_intern(&lf[24],23, C_text("chicken.io#read-string!"));
lf[25]=C_h_intern(&lf[25],12, C_text("read-string!"));
lf[26]=C_h_intern(&lf[26],27, C_text("chicken.io#read-string/port"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[28]=C_h_intern(&lf[28],30, C_text("chicken.base#get-output-string"));
lf[29]=C_h_intern(&lf[29],23, C_text("chicken.io#write-string"));
lf[30]=C_h_intern(&lf[30],31, C_text("chicken.base#open-output-string"));
lf[31]=C_h_intern(&lf[31],17, C_text("##sys#peek-char-0"));
lf[32]=C_h_intern(&lf[32],22, C_text("chicken.io#read-string"));
lf[33]=C_h_intern(&lf[33],11, C_text("read-string"));
lf[34]=C_h_intern(&lf[34],24, C_text("chicken.io#read-buffered"));
lf[35]=C_h_intern(&lf[35],13, C_text("read-buffered"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[37]=C_h_intern(&lf[37],21, C_text("chicken.io#read-token"));
lf[38]=C_h_intern(&lf[38],10, C_text("read-token"));
lf[39]=C_h_intern(&lf[39],12, C_text("write-string"));
lf[40]=C_h_intern(&lf[40],20, C_text("chicken.io#read-byte"));
lf[41]=C_h_intern(&lf[41],9, C_text("read-byte"));
lf[42]=C_h_intern(&lf[42],21, C_text("chicken.io#write-byte"));
lf[43]=C_h_intern(&lf[43],10, C_text("write-byte"));
lf[44]=C_h_intern(&lf[44],21, C_text("chicken.pretty-print#"));
lf[46]=C_h_intern(&lf[46],5, C_text("quote"));
lf[47]=C_h_intern(&lf[47],10, C_text("quasiquote"));
lf[48]=C_h_intern(&lf[48],7, C_text("unquote"));
lf[49]=C_h_intern(&lf[49],16, C_text("unquote-splicing"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\047"));
lf[51]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001`"));
lf[52]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001,"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002,@"));
lf[54]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[55]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001)"));
lf[56]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001)"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003 . "));
lf[58]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[59]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002()"));
lf[60]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005#!eof"));
lf[61]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005#!bwp"));
lf[62]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001#"));
lf[63]=C_h_intern(&lf[63],19, C_text("scheme#vector->list"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002#t"));
lf[65]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002#f"));
lf[66]=C_h_intern(&lf[66],20, C_text("##sys#number->string"));
lf[67]=C_h_intern(&lf[67],11, C_text("##sys#print"));
lf[68]=C_h_intern(&lf[68],23, C_text("##sys#procedure->string"));
lf[69]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\134"));
lf[70]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\377\012\000\000\011\376B\000\000\002\134t\376\003\000\000\002\376\003\000\000\002\376\377\012\000\000\012\376B\000\000\002\134n\376\003\000\000\002\376\003\000\000\002\376\377\012\000\000\015\376B\000\000\002\134r\376\003\000\000\002\376\003\000\000\002\376"
"\377\012\000\000\013\376B\000\000\002\134v\376\003\000\000\002\376\003\000\000\002\376\377\012\000\000\014\376B\000\000\002\134f\376\003\000\000\002\376\003\000\000\002\376\377\012\000\000\007\376B\000\000\002\134a\376\003\000\000\002\376\003\000\000\002\376\377\012\000\000\010\376B\000\000\002\134"
"b\376\377\016"));
lf[71]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0010"));
lf[72]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[73]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002\134x"));
lf[74]=C_h_intern(&lf[74],20, C_text("##sys#fixnum->string"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[76]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\042"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001x"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001U"));
lf[79]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001u"));
lf[80]=C_h_intern(&lf[80],22, C_text("chicken.base#char-name"));
lf[81]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002#\134"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016#<unspecified>"));
lf[83]=C_decode_literal(C_heaptop,C_text("\376B\000\000\020#<unbound value>"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025#<unprintable object>"));
lf[85]=C_h_intern(&lf[85],21, C_text("##sys#pointer->string"));
lf[86]=C_h_intern(&lf[86],21, C_text("##sys#user-print-hook"));
lf[87]=C_h_intern(&lf[87],20, C_text("scheme#string-append"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007#<port "));
lf[89]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001>"));
lf[90]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001}"));
lf[91]=C_decode_literal(C_heaptop,C_text("\376B\000\000\0010"));
lf[92]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003#${"));
lf[93]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001>"));
lf[94]=C_h_intern(&lf[94],25, C_text("##sys#lambda-info->string"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016#<lambda info "));
lf[96]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025#<unprintable object>"));
lf[97]=C_h_intern(&lf[97],18, C_text("chicken.base#port\077"));
lf[98]=C_h_intern(&lf[98],24, C_text("chicken.keyword#keyword\077"));
lf[99]=C_h_intern(&lf[99],13, C_text("##sys#number\077"));
lf[100]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010        "));
lf[101]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010        "));
lf[102]=C_h_intern(&lf[102],36, C_text("chicken.string#reverse-string-append"));
lf[103]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001#"));
lf[104]=C_h_intern(&lf[104],10, C_text("scheme#max"));
lf[105]=C_h_intern(&lf[105],20, C_text("##sys#symbol->string"));
lf[106]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[107]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001)"));
lf[109]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001)"));
lf[110]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[111]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[112]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[113]=C_h_intern(&lf[113],6, C_text("lambda"));
lf[114]=C_h_intern(&lf[114],2, C_text("if"));
lf[115]=C_h_intern(&lf[115],4, C_text("set!"));
lf[116]=C_h_intern(&lf[116],4, C_text("cond"));
lf[117]=C_h_intern(&lf[117],4, C_text("case"));
lf[118]=C_h_intern(&lf[118],3, C_text("and"));
lf[119]=C_h_intern(&lf[119],2, C_text("or"));
lf[120]=C_h_intern(&lf[120],3, C_text("let"));
lf[121]=C_h_intern(&lf[121],5, C_text("begin"));
lf[122]=C_h_intern(&lf[122],2, C_text("do"));
lf[123]=C_h_intern(&lf[123],4, C_text("let\052"));
lf[124]=C_h_intern(&lf[124],6, C_text("letrec"));
lf[125]=C_h_intern(&lf[125],7, C_text("letrec\052"));
lf[126]=C_h_intern(&lf[126],6, C_text("define"));
lf[127]=C_h_intern(&lf[127],39, C_text("chicken.pretty-print#pretty-print-width"));
lf[128]=C_h_intern(&lf[128],33, C_text("chicken.pretty-print#pretty-print"));
lf[129]=C_h_intern(&lf[129],14, C_text("scheme#display"));
lf[130]=C_h_intern(&lf[130],23, C_text("chicken.pretty-print#pp"));
lf[131]=C_h_intern(&lf[131],15, C_text("chicken.format#"));
lf[133]=C_h_intern(&lf[133],11, C_text("##sys#error"));
lf[134]=C_decode_literal(C_heaptop,C_text("\376B\000\000/too few arguments to formatted output procedure"));
lf[135]=C_h_intern(&lf[135],12, C_text("scheme#write"));
lf[136]=C_h_intern(&lf[136],18, C_text("##sys#flush-output"));
lf[137]=C_h_intern(&lf[137],14, C_text("scheme#newline"));
lf[138]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037illegal format-string character"));
lf[139]=C_h_intern(&lf[139],15, C_text("##sys#tty-port\077"));
lf[140]=C_h_intern(&lf[140],22, C_text("chicken.format#fprintf"));
lf[141]=C_h_intern(&lf[141],7, C_text("fprintf"));
lf[142]=C_h_intern(&lf[142],21, C_text("chicken.format#printf"));
lf[143]=C_h_intern(&lf[143],6, C_text("printf"));
lf[144]=C_h_intern(&lf[144],22, C_text("chicken.format#sprintf"));
lf[145]=C_h_intern(&lf[145],7, C_text("sprintf"));
lf[146]=C_h_intern(&lf[146],21, C_text("chicken.format#format"));
lf[147]=C_h_intern(&lf[147],6, C_text("format"));
lf[148]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023illegal destination"));
lf[149]=C_h_intern(&lf[149],19, C_text("scheme#output-port\077"));
lf[150]=C_h_intern(&lf[150],15, C_text("chicken.random#"));
lf[151]=C_h_intern(&lf[151],38, C_text("chicken.random#set-pseudo-random-seed!"));
lf[152]=C_h_intern(&lf[152],23, C_text("set-pseudo-random-seed!"));
lf[153]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023invalid buffer type"));
lf[154]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid size"));
lf[155]=C_h_intern(&lf[155],36, C_text("chicken.random#pseudo-random-integer"));
lf[156]=C_h_intern(&lf[156],21, C_text("pseudo-random-integer"));
lf[157]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021bad argument type"));
lf[158]=C_h_intern(&lf[158],33, C_text("chicken.random#pseudo-random-real"));
lf[159]=C_h_intern(&lf[159],27, C_text("chicken.random#random-bytes"));
lf[160]=C_h_intern(&lf[160],12, C_text("random-bytes"));
lf[161]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033unable to read random bytes"));
lf[162]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023invalid buffer type"));
lf[163]=C_decode_literal(C_heaptop,C_text("\376B\000\000\014invalid size"));
lf[164]=C_h_intern(&lf[164],34, C_text("chicken.platform#register-feature!"));
lf[165]=C_h_intern(&lf[165],7, C_text("srfi-28"));
lf[166]=C_h_intern(&lf[166],27, C_text("chicken.base#make-parameter"));
C_register_lf2(lf,167,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1102,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[234] = {
{C_text("f_1102:extras_2escm"),(void*)f_1102},
{C_text("f_1105:extras_2escm"),(void*)f_1105},
{C_text("f_1107:extras_2escm"),(void*)f_1107},
{C_text("f_1136:extras_2escm"),(void*)f_1136},
{C_text("f_1138:extras_2escm"),(void*)f_1138},
{C_text("f_1158:extras_2escm"),(void*)f_1158},
{C_text("f_1210:extras_2escm"),(void*)f_1210},
{C_text("f_1220:extras_2escm"),(void*)f_1220},
{C_text("f_1230:extras_2escm"),(void*)f_1230},
{C_text("f_1243:extras_2escm"),(void*)f_1243},
{C_text("f_1248:extras_2escm"),(void*)f_1248},
{C_text("f_1261:extras_2escm"),(void*)f_1261},
{C_text("f_1294:extras_2escm"),(void*)f_1294},
{C_text("f_1303:extras_2escm"),(void*)f_1303},
{C_text("f_1326:extras_2escm"),(void*)f_1326},
{C_text("f_1334:extras_2escm"),(void*)f_1334},
{C_text("f_1363:extras_2escm"),(void*)f_1363},
{C_text("f_1382:extras_2escm"),(void*)f_1382},
{C_text("f_1391:extras_2escm"),(void*)f_1391},
{C_text("f_1404:extras_2escm"),(void*)f_1404},
{C_text("f_1453:extras_2escm"),(void*)f_1453},
{C_text("f_1469:extras_2escm"),(void*)f_1469},
{C_text("f_1481:extras_2escm"),(void*)f_1481},
{C_text("f_1499:extras_2escm"),(void*)f_1499},
{C_text("f_1503:extras_2escm"),(void*)f_1503},
{C_text("f_1558:extras_2escm"),(void*)f_1558},
{C_text("f_1562:extras_2escm"),(void*)f_1562},
{C_text("f_1565:extras_2escm"),(void*)f_1565},
{C_text("f_1613:extras_2escm"),(void*)f_1613},
{C_text("f_1635:extras_2escm"),(void*)f_1635},
{C_text("f_1641:extras_2escm"),(void*)f_1641},
{C_text("f_1644:extras_2escm"),(void*)f_1644},
{C_text("f_1690:extras_2escm"),(void*)f_1690},
{C_text("f_1709:extras_2escm"),(void*)f_1709},
{C_text("f_1712:extras_2escm"),(void*)f_1712},
{C_text("f_1724:extras_2escm"),(void*)f_1724},
{C_text("f_1727:extras_2escm"),(void*)f_1727},
{C_text("f_1732:extras_2escm"),(void*)f_1732},
{C_text("f_1736:extras_2escm"),(void*)f_1736},
{C_text("f_1748:extras_2escm"),(void*)f_1748},
{C_text("f_1756:extras_2escm"),(void*)f_1756},
{C_text("f_1758:extras_2escm"),(void*)f_1758},
{C_text("f_1777:extras_2escm"),(void*)f_1777},
{C_text("f_1811:extras_2escm"),(void*)f_1811},
{C_text("f_1839:extras_2escm"),(void*)f_1839},
{C_text("f_1849:extras_2escm"),(void*)f_1849},
{C_text("f_1854:extras_2escm"),(void*)f_1854},
{C_text("f_1858:extras_2escm"),(void*)f_1858},
{C_text("f_1864:extras_2escm"),(void*)f_1864},
{C_text("f_1867:extras_2escm"),(void*)f_1867},
{C_text("f_1874:extras_2escm"),(void*)f_1874},
{C_text("f_1895:extras_2escm"),(void*)f_1895},
{C_text("f_1900:extras_2escm"),(void*)f_1900},
{C_text("f_1907:extras_2escm"),(void*)f_1907},
{C_text("f_1917:extras_2escm"),(void*)f_1917},
{C_text("f_1938:extras_2escm"),(void*)f_1938},
{C_text("f_1943:extras_2escm"),(void*)f_1943},
{C_text("f_1978:extras_2escm"),(void*)f_1978},
{C_text("f_1988:extras_2escm"),(void*)f_1988},
{C_text("f_2005:extras_2escm"),(void*)f_2005},
{C_text("f_2012:extras_2escm"),(void*)f_2012},
{C_text("f_2030:extras_2escm"),(void*)f_2030},
{C_text("f_2033:extras_2escm"),(void*)f_2033},
{C_text("f_2061:extras_2escm"),(void*)f_2061},
{C_text("f_2095:extras_2escm"),(void*)f_2095},
{C_text("f_2134:extras_2escm"),(void*)f_2134},
{C_text("f_2144:extras_2escm"),(void*)f_2144},
{C_text("f_2153:extras_2escm"),(void*)f_2153},
{C_text("f_2156:extras_2escm"),(void*)f_2156},
{C_text("f_2163:extras_2escm"),(void*)f_2163},
{C_text("f_2174:extras_2escm"),(void*)f_2174},
{C_text("f_2183:extras_2escm"),(void*)f_2183},
{C_text("f_2199:extras_2escm"),(void*)f_2199},
{C_text("f_2201:extras_2escm"),(void*)f_2201},
{C_text("f_2223:extras_2escm"),(void*)f_2223},
{C_text("f_2229:extras_2escm"),(void*)f_2229},
{C_text("f_2245:extras_2escm"),(void*)f_2245},
{C_text("f_2249:extras_2escm"),(void*)f_2249},
{C_text("f_2258:extras_2escm"),(void*)f_2258},
{C_text("f_2307:extras_2escm"),(void*)f_2307},
{C_text("f_2311:extras_2escm"),(void*)f_2311},
{C_text("f_2330:extras_2escm"),(void*)f_2330},
{C_text("f_2337:extras_2escm"),(void*)f_2337},
{C_text("f_2343:extras_2escm"),(void*)f_2343},
{C_text("f_2349:extras_2escm"),(void*)f_2349},
{C_text("f_2352:extras_2escm"),(void*)f_2352},
{C_text("f_2359:extras_2escm"),(void*)f_2359},
{C_text("f_2372:extras_2escm"),(void*)f_2372},
{C_text("f_2391:extras_2escm"),(void*)f_2391},
{C_text("f_2393:extras_2escm"),(void*)f_2393},
{C_text("f_2421:extras_2escm"),(void*)f_2421},
{C_text("f_2425:extras_2escm"),(void*)f_2425},
{C_text("f_2429:extras_2escm"),(void*)f_2429},
{C_text("f_2452:extras_2escm"),(void*)f_2452},
{C_text("f_2457:extras_2escm"),(void*)f_2457},
{C_text("f_2458:extras_2escm"),(void*)f_2458},
{C_text("f_2476:extras_2escm"),(void*)f_2476},
{C_text("f_2480:extras_2escm"),(void*)f_2480},
{C_text("f_2488:extras_2escm"),(void*)f_2488},
{C_text("f_2499:extras_2escm"),(void*)f_2499},
{C_text("f_2517:extras_2escm"),(void*)f_2517},
{C_text("f_2521:extras_2escm"),(void*)f_2521},
{C_text("f_2544:extras_2escm"),(void*)f_2544},
{C_text("f_2552:extras_2escm"),(void*)f_2552},
{C_text("f_2555:extras_2escm"),(void*)f_2555},
{C_text("f_2559:extras_2escm"),(void*)f_2559},
{C_text("f_2579:extras_2escm"),(void*)f_2579},
{C_text("f_2586:extras_2escm"),(void*)f_2586},
{C_text("f_2597:extras_2escm"),(void*)f_2597},
{C_text("f_2604:extras_2escm"),(void*)f_2604},
{C_text("f_2620:extras_2escm"),(void*)f_2620},
{C_text("f_2650:extras_2escm"),(void*)f_2650},
{C_text("f_2659:extras_2escm"),(void*)f_2659},
{C_text("f_2662:extras_2escm"),(void*)f_2662},
{C_text("f_2669:extras_2escm"),(void*)f_2669},
{C_text("f_2675:extras_2escm"),(void*)f_2675},
{C_text("f_2682:extras_2escm"),(void*)f_2682},
{C_text("f_2692:extras_2escm"),(void*)f_2692},
{C_text("f_2698:extras_2escm"),(void*)f_2698},
{C_text("f_2703:extras_2escm"),(void*)f_2703},
{C_text("f_2716:extras_2escm"),(void*)f_2716},
{C_text("f_2719:extras_2escm"),(void*)f_2719},
{C_text("f_2730:extras_2escm"),(void*)f_2730},
{C_text("f_2742:extras_2escm"),(void*)f_2742},
{C_text("f_2745:extras_2escm"),(void*)f_2745},
{C_text("f_2752:extras_2escm"),(void*)f_2752},
{C_text("f_2760:extras_2escm"),(void*)f_2760},
{C_text("f_2763:extras_2escm"),(void*)f_2763},
{C_text("f_2787:extras_2escm"),(void*)f_2787},
{C_text("f_2794:extras_2escm"),(void*)f_2794},
{C_text("f_2796:extras_2escm"),(void*)f_2796},
{C_text("f_2812:extras_2escm"),(void*)f_2812},
{C_text("f_2819:extras_2escm"),(void*)f_2819},
{C_text("f_2830:extras_2escm"),(void*)f_2830},
{C_text("f_2843:extras_2escm"),(void*)f_2843},
{C_text("f_2846:extras_2escm"),(void*)f_2846},
{C_text("f_2859:extras_2escm"),(void*)f_2859},
{C_text("f_2875:extras_2escm"),(void*)f_2875},
{C_text("f_2879:extras_2escm"),(void*)f_2879},
{C_text("f_2881:extras_2escm"),(void*)f_2881},
{C_text("f_2917:extras_2escm"),(void*)f_2917},
{C_text("f_2924:extras_2escm"),(void*)f_2924},
{C_text("f_2935:extras_2escm"),(void*)f_2935},
{C_text("f_2951:extras_2escm"),(void*)f_2951},
{C_text("f_2977:extras_2escm"),(void*)f_2977},
{C_text("f_2982:extras_2escm"),(void*)f_2982},
{C_text("f_2986:extras_2escm"),(void*)f_2986},
{C_text("f_3006:extras_2escm"),(void*)f_3006},
{C_text("f_3008:extras_2escm"),(void*)f_3008},
{C_text("f_3012:extras_2escm"),(void*)f_3012},
{C_text("f_3017:extras_2escm"),(void*)f_3017},
{C_text("f_3023:extras_2escm"),(void*)f_3023},
{C_text("f_3044:extras_2escm"),(void*)f_3044},
{C_text("f_3050:extras_2escm"),(void*)f_3050},
{C_text("f_3072:extras_2escm"),(void*)f_3072},
{C_text("f_3076:extras_2escm"),(void*)f_3076},
{C_text("f_3084:extras_2escm"),(void*)f_3084},
{C_text("f_3088:extras_2escm"),(void*)f_3088},
{C_text("f_3090:extras_2escm"),(void*)f_3090},
{C_text("f_3093:extras_2escm"),(void*)f_3093},
{C_text("f_3114:extras_2escm"),(void*)f_3114},
{C_text("f_3118:extras_2escm"),(void*)f_3118},
{C_text("f_3132:extras_2escm"),(void*)f_3132},
{C_text("f_3153:extras_2escm"),(void*)f_3153},
{C_text("f_3157:extras_2escm"),(void*)f_3157},
{C_text("f_3171:extras_2escm"),(void*)f_3171},
{C_text("f_3182:extras_2escm"),(void*)f_3182},
{C_text("f_3195:extras_2escm"),(void*)f_3195},
{C_text("f_3210:extras_2escm"),(void*)f_3210},
{C_text("f_3228:extras_2escm"),(void*)f_3228},
{C_text("f_3230:extras_2escm"),(void*)f_3230},
{C_text("f_3236:extras_2escm"),(void*)f_3236},
{C_text("f_3242:extras_2escm"),(void*)f_3242},
{C_text("f_3248:extras_2escm"),(void*)f_3248},
{C_text("f_3254:extras_2escm"),(void*)f_3254},
{C_text("f_3260:extras_2escm"),(void*)f_3260},
{C_text("f_3266:extras_2escm"),(void*)f_3266},
{C_text("f_3286:extras_2escm"),(void*)f_3286},
{C_text("f_3292:extras_2escm"),(void*)f_3292},
{C_text("f_3301:extras_2escm"),(void*)f_3301},
{C_text("f_3311:extras_2escm"),(void*)f_3311},
{C_text("f_3427:extras_2escm"),(void*)f_3427},
{C_text("f_3431:extras_2escm"),(void*)f_3431},
{C_text("f_3440:extras_2escm"),(void*)f_3440},
{C_text("f_3442:extras_2escm"),(void*)f_3442},
{C_text("f_3449:extras_2escm"),(void*)f_3449},
{C_text("f_3453:extras_2escm"),(void*)f_3453},
{C_text("f_3455:extras_2escm"),(void*)f_3455},
{C_text("f_3459:extras_2escm"),(void*)f_3459},
{C_text("f_3466:extras_2escm"),(void*)f_3466},
{C_text("f_3473:extras_2escm"),(void*)f_3473},
{C_text("f_3476:extras_2escm"),(void*)f_3476},
{C_text("f_3498:extras_2escm"),(void*)f_3498},
{C_text("f_3504:extras_2escm"),(void*)f_3504},
{C_text("f_3513:extras_2escm"),(void*)f_3513},
{C_text("f_3520:extras_2escm"),(void*)f_3520},
{C_text("f_3539:extras_2escm"),(void*)f_3539},
{C_text("f_3552:extras_2escm"),(void*)f_3552},
{C_text("f_3577:extras_2escm"),(void*)f_3577},
{C_text("f_3590:extras_2escm"),(void*)f_3590},
{C_text("f_3603:extras_2escm"),(void*)f_3603},
{C_text("f_3616:extras_2escm"),(void*)f_3616},
{C_text("f_3620:extras_2escm"),(void*)f_3620},
{C_text("f_3633:extras_2escm"),(void*)f_3633},
{C_text("f_3637:extras_2escm"),(void*)f_3637},
{C_text("f_3650:extras_2escm"),(void*)f_3650},
{C_text("f_3654:extras_2escm"),(void*)f_3654},
{C_text("f_3672:extras_2escm"),(void*)f_3672},
{C_text("f_3675:extras_2escm"),(void*)f_3675},
{C_text("f_3681:extras_2escm"),(void*)f_3681},
{C_text("f_3717:extras_2escm"),(void*)f_3717},
{C_text("f_3775:extras_2escm"),(void*)f_3775},
{C_text("f_3786:extras_2escm"),(void*)f_3786},
{C_text("f_3792:extras_2escm"),(void*)f_3792},
{C_text("f_3798:extras_2escm"),(void*)f_3798},
{C_text("f_3804:extras_2escm"),(void*)f_3804},
{C_text("f_3812:extras_2escm"),(void*)f_3812},
{C_text("f_3837:extras_2escm"),(void*)f_3837},
{C_text("f_3847:extras_2escm"),(void*)f_3847},
{C_text("f_3850:extras_2escm"),(void*)f_3850},
{C_text("f_3852:extras_2escm"),(void*)f_3852},
{C_text("f_3859:extras_2escm"),(void*)f_3859},
{C_text("f_3862:extras_2escm"),(void*)f_3862},
{C_text("f_3873:extras_2escm"),(void*)f_3873},
{C_text("f_3891:extras_2escm"),(void*)f_3891},
{C_text("f_3907:extras_2escm"),(void*)f_3907},
{C_text("f_3910:extras_2escm"),(void*)f_3910},
{C_text("f_3926:extras_2escm"),(void*)f_3926},
{C_text("f_3929:extras_2escm"),(void*)f_3929},
{C_text("f_3936:extras_2escm"),(void*)f_3936},
{C_text("f_3951:extras_2escm"),(void*)f_3951},
{C_text("f_3974:extras_2escm"),(void*)f_3974},
{C_text("toplevel:extras_2escm"),(void*)C_extras_toplevel},
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
o|hiding unexported module binding: chicken.io#d 
o|hiding unexported module binding: chicken.io#define-alias 
o|hiding unexported module binding: chicken.io#read-string!/port 
o|hiding unexported module binding: chicken.io#read-string/port 
o|hiding unexported module binding: chicken.pretty-print#generic-write 
o|hiding unexported module binding: chicken.format#fprintf0 
o|eliminated procedure checks: 27 
o|specializations:
o|  11 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#current-output-port)
o|  4 (scheme#make-string fixnum char)
o|  3 (scheme#number->string fixnum fixnum)
o|  1 (scheme#assq * (list-of pair))
o|  2 (scheme#char<? char char)
o|  1 (scheme#+ fixnum fixnum)
o|  3 (scheme#char=? char char)
o|  5 (scheme#car pair)
o|  13 (scheme#cdr pair)
o|  1 (scheme#make-string fixnum)
o|  4 (##sys#check-output-port * * *)
o|  24 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  8 (##sys#check-input-port * * *)
(o e)|safe calls: 337 
(o e)|assignments to immediate values: 8 
o|safe globals: (chicken.pretty-print#generic-write chicken.io#write-byte chicken.io#read-byte chicken.io#write-string chicken.io#read-token chicken.io#read-buffered chicken.io#read-string chicken.io#read-string/port chicken.io#read-string! chicken.io#read-string!/port chicken.io#write-line chicken.io#read-lines chicken.io#read-line chicken.io#read-list) 
o|substituted constant variable: a1128 
o|substituted constant variable: a1129 
o|inlining procedure: k1140 
o|inlining procedure: k1140 
o|inlining procedure: k1167 
o|inlining procedure: k1167 
o|substituted constant variable: a1222 
o|substituted constant variable: a1223 
o|inlining procedure: k1227 
o|inlining procedure: k1227 
o|inlining procedure: k1250 
o|inlining procedure: k1250 
o|inlining procedure: k1268 
o|inlining procedure: k1268 
o|inlining procedure: k1277 
o|inlining procedure: k1277 
o|inlining procedure: k1295 
o|inlining procedure: k1295 
o|substituted constant variable: a1336 
o|substituted constant variable: a1338 
o|inlining procedure: k1346 
o|inlining procedure: k1346 
o|substituted constant variable: a1378 
o|substituted constant variable: a1379 
o|inlining procedure: k1393 
o|inlining procedure: k1393 
o|substituted constant variable: a1459 
o|substituted constant variable: a1460 
o|inlining procedure: k1483 
o|inlining procedure: k1483 
o|inlining procedure: k1507 
o|inlining procedure: k1507 
o|inlining procedure: k1566 
o|inlining procedure: k1566 
o|substituted constant variable: a1628 
o|substituted constant variable: a1629 
o|inlining procedure: k1692 
o|inlining procedure: k1692 
o|inlining procedure: k1704 
o|inlining procedure: k1704 
o|inlining procedure: k1737 
o|inlining procedure: k1737 
o|substituted constant variable: a1752 
o|substituted constant variable: a1773 
o|substituted constant variable: a1774 
o|inlining procedure: k1775 
o|inlining procedure: k1775 
o|substituted constant variable: a1817 
o|substituted constant variable: a1818 
o|inlining procedure: k1822 
o|inlining procedure: k1822 
o|substituted constant variable: a1845 
o|substituted constant variable: a1846 
o|inlining procedure: k1859 
o|inlining procedure: k1859 
o|substituted constant variable: a1903 
o|substituted constant variable: a1904 
o|inlining procedure: k1915 
o|inlining procedure: k1915 
o|inlining procedure: k1948 
o|inlining procedure: k1948 
o|substituted constant variable: a1984 
o|substituted constant variable: a1985 
o|inlining procedure: k1989 
o|inlining procedure: k1989 
o|substituted constant variable: a2014 
o|substituted constant variable: a2015 
o|inlining procedure: k2053 
o|contracted procedure: "(extras.scm:260) length1?423" 
o|inlining procedure: k2038 
o|inlining procedure: k2038 
o|inlining procedure: k2053 
o|inlining procedure: k2068 
o|inlining procedure: k2068 
o|substituted constant variable: a2081 
o|substituted constant variable: a2083 
o|substituted constant variable: a2085 
o|substituted constant variable: a2087 
o|inlining procedure: k2101 
o|inlining procedure: k2101 
o|inlining procedure: k2113 
o|inlining procedure: k2113 
o|substituted constant variable: a2126 
o|substituted constant variable: a2128 
o|substituted constant variable: a2130 
o|substituted constant variable: a2132 
o|inlining procedure: k2136 
o|inlining procedure: k2136 
o|inlining procedure: k2158 
o|inlining procedure: "(extras.scm:281) read-macro-body417" 
o|inlining procedure: k2158 
o|inlining procedure: k2185 
o|inlining procedure: k2203 
o|inlining procedure: k2203 
o|inlining procedure: k2230 
o|inlining procedure: k2230 
o|inlining procedure: k2185 
o|inlining procedure: k2262 
o|inlining procedure: k2262 
o|inlining procedure: k2280 
o|inlining procedure: k2280 
o|inlining procedure: k2295 
o|inlining procedure: k2295 
o|inlining procedure: k2322 
o|inlining procedure: k2322 
o|inlining procedure: k2325 
o|inlining procedure: k2325 
o|inlining procedure: k2360 
o|inlining procedure: k2360 
o|inlining procedure: k2379 
o|inlining procedure: k2379 
o|inlining procedure: k2395 
o|substituted constant variable: a2408 
o|substituted constant variable: a2417 
o|substituted constant variable: a2434 
o|inlining procedure: k2430 
o|substituted constant variable: a2454 
o|inlining procedure: k2455 
o|inlining procedure: k2455 
o|substituted constant variable: a2490 
o|substituted constant variable: a2495 
o|inlining procedure: k2430 
o|substituted constant variable: a2508 
o|substituted constant variable: a2510 
o|inlining procedure: k2395 
o|inlining procedure: k2529 
o|substituted constant variable: a2545 
o|inlining procedure: k2556 
o|inlining procedure: k2556 
o|substituted constant variable: a2588 
o|inlining procedure: k2589 
o|substituted constant variable: a2606 
o|inlining procedure: k2608 
o|inlining procedure: k2608 
o|inlining procedure: k2589 
o|substituted constant variable: a2621 
o|inlining procedure: k2529 
o|inlining procedure: k2629 
o|inlining procedure: k2629 
o|inlining procedure: k2641 
o|inlining procedure: k2641 
o|inlining procedure: k2670 
o|inlining procedure: k2670 
o|inlining procedure: k2705 
o|inlining procedure: k2705 
o|inlining procedure: k2737 
o|inlining procedure: k2737 
o|inlining procedure: k2765 
o|inlining procedure: k2765 
o|inlining procedure: k2798 
o|inlining procedure: k2807 
o|inlining procedure: k2807 
o|substituted constant variable: a2820 
o|substituted constant variable: a2821 
o|inlining procedure: k2798 
o|inlining procedure: k2832 
o|inlining procedure: k2860 
o|inlining procedure: k2860 
o|substituted constant variable: max-expr-width561 
o|inlining procedure: k2832 
o|inlining procedure: k2919 
o|inlining procedure: "(extras.scm:417) read-macro-body417" 
o|inlining procedure: k2919 
o|inlining procedure: k2952 
o|inlining procedure: k2952 
o|substituted constant variable: max-call-head-width560 
o|inlining procedure: k2987 
o|inlining procedure: k2987 
o|inlining procedure: k3025 
o|inlining procedure: k3057 
o|inlining procedure: k3057 
o|inlining procedure: k3025 
o|inlining procedure: k3095 
o|inlining procedure: k3095 
o|inlining procedure: k3134 
o|inlining procedure: k3134 
o|inlining procedure: k3183 
o|substituted constant variable: indent-general559 
o|inlining procedure: k3183 
o|substituted constant variable: indent-general559 
o|inlining procedure: k3303 
o|inlining procedure: k3303 
o|inlining procedure: k3321 
o|inlining procedure: k3321 
o|inlining procedure: k3333 
o|inlining procedure: k3333 
o|inlining procedure: k3348 
o|inlining procedure: k3348 
o|substituted constant variable: a3361 
o|substituted constant variable: a3363 
o|substituted constant variable: a3365 
o|substituted constant variable: a3370 
o|substituted constant variable: a3372 
o|substituted constant variable: a3374 
o|substituted constant variable: a3376 
o|substituted constant variable: a3381 
o|substituted constant variable: a3383 
o|inlining procedure: k3387 
o|inlining procedure: k3387 
o|inlining procedure: k3399 
o|inlining procedure: k3399 
o|substituted constant variable: a3406 
o|substituted constant variable: a3408 
o|substituted constant variable: a3410 
o|substituted constant variable: a3412 
o|substituted constant variable: a3414 
o|inlining procedure: k3418 
o|substituted constant variable: a3432 
o|substituted constant variable: a3433 
o|inlining procedure: k3418 
o|inlining procedure: k3477 
o|inlining procedure: k3477 
o|inlining procedure: k3522 
o|inlining procedure: k3522 
o|inlining procedure: k3541 
o|inlining procedure: k3541 
o|inlining procedure: k3565 
o|inlining procedure: k3565 
o|inlining procedure: k3591 
o|inlining procedure: k3591 
o|inlining procedure: k3621 
o|inlining procedure: k3621 
o|inlining procedure: k3655 
o|inlining procedure: k3655 
o|inlining procedure: k3682 
o|inlining procedure: k3682 
o|inlining procedure: k3703 
o|inlining procedure: k3719 
o|inlining procedure: k3719 
o|inlining procedure: k3703 
o|substituted constant variable: a3743 
o|substituted constant variable: a3745 
o|substituted constant variable: a3747 
o|substituted constant variable: a3749 
o|substituted constant variable: a3751 
o|substituted constant variable: a3753 
o|substituted constant variable: a3755 
o|substituted constant variable: a3757 
o|substituted constant variable: a3759 
o|substituted constant variable: a3761 
o|substituted constant variable: a3763 
o|substituted constant variable: a3783 
o|inlining procedure: k3810 
o|propagated global variable: r38114194 chicken.format#sprintf 
o|inlining procedure: k3810 
o|inlining procedure: k3822 
o|propagated global variable: r38234198 chicken.format#sprintf 
o|inlining procedure: k3822 
o|inlining procedure: k3874 
o|inlining procedure: k3874 
o|inlining procedure: k3893 
o|inlining procedure: k3893 
o|inlining procedure: k3937 
o|inlining procedure: k3937 
o|inlining procedure: k3949 
o|inlining procedure: k3949 
o|inlining procedure: k3969 
o|inlining procedure: k3969 
o|inlining procedure: k3975 
o|inlining procedure: k3975 
o|replaced variables: 939 
o|removed binding forms: 153 
o|substituted constant variable: r11684011 
o|substituted constant variable: r13474023 
o|substituted constant variable: r14844026 
o|substituted constant variable: r16934032 
o|substituted constant variable: r18234049 
o|substituted constant variable: r20394062 
o|substituted constant variable: r20544063 
o|removed side-effect free assignment to unused variable: read-macro-body417 
o|substituted constant variable: r21024066 
o|substituted constant variable: r21144068 
o|substituted constant variable: r21374071 
o|substituted constant variable: r23234091 
o|substituted constant variable: r23234091 
o|substituted constant variable: r23234093 
o|substituted constant variable: r23234093 
o|substituted constant variable: r26094113 
o|substituted constant variable: r26094113 
o|substituted constant variable: r26094115 
o|substituted constant variable: r26094115 
o|substituted constant variable: r28084133 
o|substituted constant variable: r27994134 
o|substituted constant variable: r29884149 
o|substituted constant variable: r30264153 
o|removed side-effect free assignment to unused variable: indent-general559 
o|removed side-effect free assignment to unused variable: max-call-head-width560 
o|removed side-effect free assignment to unused variable: max-expr-width561 
o|inlining procedure: k3550 
o|propagated global variable: a38094195 chicken.format#sprintf 
o|inlining procedure: k3810 
o|propagated global variable: r38114279 chicken.format#printf 
o|propagated global variable: r38114279 chicken.format#printf 
o|inlining procedure: k3810 
o|propagated global variable: r38114281 chicken.format#sprintf 
o|propagated global variable: r38114281 chicken.format#sprintf 
o|inlining procedure: k3810 
o|propagated global variable: r38114283 chicken.format#fprintf 
o|propagated global variable: r38114283 chicken.format#fprintf 
o|replaced variables: 32 
o|removed binding forms: 755 
o|inlining procedure: k3271 
o|inlining procedure: k3773 
o|removed binding forms: 72 
o|substituted constant variable: r32724307 
o|substituted constant variable: r37744314 
o|inlining procedure: k3955 
o|removed conditional forms: 1 
o|replaced variables: 1 
o|removed binding forms: 2 
o|removed binding forms: 1 
o|simplifications: ((let . 6) (if . 63) (##core#call . 282)) 
o|  call simplifications:
o|    ##sys#immediate?
o|    scheme#apply	5
o|    scheme#char-upcase
o|    scheme#char-whitespace?	2
o|    ##sys#check-list
o|    scheme#<	2
o|    scheme#>	5
o|    scheme#-	5
o|    scheme#vector?	2
o|    scheme#boolean?	2
o|    scheme#symbol?	3
o|    scheme#procedure?
o|    scheme#string?	2
o|    scheme#char?
o|    ##sys#generic-structure?
o|    ##sys#byte
o|    chicken.fixnum#fx>	2
o|    scheme#string-ref
o|    scheme#string-length	4
o|    scheme#+	11
o|    scheme#integer->char
o|    scheme#char->integer	3
o|    ##sys#size	7
o|    chicken.fixnum#fx<=
o|    ##sys#setislot
o|    scheme#not	9
o|    chicken.fixnum#fx<	7
o|    ##sys#check-string	4
o|    chicken.fixnum#fx-	5
o|    scheme#pair?	14
o|    scheme#cadr	3
o|    ##sys#slot	16
o|    scheme#eq?	45
o|    scheme#char=?
o|    chicken.fixnum#fx=
o|    scheme#car	27
o|    scheme#null?	36
o|    scheme#cdr	14
o|    scheme#eof-object?	8
o|    chicken.fixnum#fx>=	5
o|    chicken.fixnum#fx+	16
o|    scheme#cons	5
o|contracted procedure: k1203 
o|contracted procedure: k1109 
o|contracted procedure: k1197 
o|contracted procedure: k1112 
o|contracted procedure: k1191 
o|contracted procedure: k1115 
o|contracted procedure: k1185 
o|contracted procedure: k1118 
o|contracted procedure: k1179 
o|contracted procedure: k1121 
o|contracted procedure: k1173 
o|contracted procedure: k1124 
o|contracted procedure: k1143 
o|contracted procedure: k1146 
o|contracted procedure: k1160 
o|contracted procedure: k1164 
o|contracted procedure: k1212 
o|contracted procedure: k1215 
o|contracted procedure: k1343 
o|contracted procedure: k1224 
o|contracted procedure: k1238 
o|contracted procedure: k1253 
o|contracted procedure: k1265 
o|contracted procedure: k1271 
o|contracted procedure: k1280 
o|contracted procedure: k1289 
o|contracted procedure: k1298 
o|contracted procedure: k1317 
o|contracted procedure: k1320 
o|contracted procedure: k1328 
o|contracted procedure: k1356 
o|contracted procedure: k1349 
o|contracted procedure: k1446 
o|contracted procedure: k1365 
o|contracted procedure: k1440 
o|contracted procedure: k1368 
o|contracted procedure: k1434 
o|contracted procedure: k1371 
o|contracted procedure: k1428 
o|contracted procedure: k1374 
o|contracted procedure: k1387 
o|contracted procedure: k1396 
o|contracted procedure: k1408 
o|contracted procedure: k1418 
o|contracted procedure: k1422 
o|contracted procedure: k1455 
o|contracted procedure: k1461 
o|contracted procedure: k1474 
o|contracted procedure: k1464 
o|contracted procedure: k1486 
o|contracted procedure: k1609 
o|contracted procedure: k1489 
o|contracted procedure: k1551 
o|contracted procedure: k1547 
o|contracted procedure: k1504 
o|contracted procedure: k1510 
o|contracted procedure: k1516 
o|contracted procedure: k1519 
o|contracted procedure: k1526 
o|contracted procedure: k1530 
o|contracted procedure: k1534 
o|contracted procedure: k1569 
o|contracted procedure: k1575 
o|contracted procedure: k1578 
o|contracted procedure: k1585 
o|contracted procedure: k1589 
o|contracted procedure: k1593 
o|contracted procedure: k1605 
o|contracted procedure: k1683 
o|contracted procedure: k1615 
o|contracted procedure: k1677 
o|contracted procedure: k1618 
o|contracted procedure: k1671 
o|contracted procedure: k1621 
o|contracted procedure: k1665 
o|contracted procedure: k1624 
o|contracted procedure: k1630 
o|contracted procedure: k1636 
o|contracted procedure: k1652 
o|contracted procedure: k1659 
o|contracted procedure: k1695 
o|contracted procedure: k1701 
o|contracted procedure: k1716 
o|contracted procedure: k1740 
o|contracted procedure: k1802 
o|contracted procedure: k1760 
o|contracted procedure: k1796 
o|contracted procedure: k1763 
o|contracted procedure: k1790 
o|contracted procedure: k1766 
o|contracted procedure: k1784 
o|contracted procedure: k1769 
o|contracted procedure: k1832 
o|contracted procedure: k1813 
o|contracted procedure: k1829 
o|contracted procedure: k1819 
o|contracted procedure: k1888 
o|contracted procedure: k1841 
o|contracted procedure: k1885 
o|contracted procedure: k1878 
o|contracted procedure: k1897 
o|contracted procedure: k1932 
o|contracted procedure: k1908 
o|contracted procedure: k1928 
o|contracted procedure: k1951 
o|contracted procedure: k1957 
o|contracted procedure: k1964 
o|contracted procedure: k1970 
o|contracted procedure: k1998 
o|contracted procedure: k1980 
o|contracted procedure: k1992 
o|contracted procedure: k2023 
o|contracted procedure: k2007 
o|contracted procedure: k2020 
o|contracted procedure: k2049 
o|contracted procedure: k2056 
o|contracted procedure: k2041 
o|contracted procedure: k2065 
o|contracted procedure: k2071 
o|contracted procedure: k2097 
o|contracted procedure: k2104 
o|contracted procedure: k2110 
o|contracted procedure: k2116 
o|contracted procedure: k2122 
o|contracted procedure: k2149 
o|contracted procedure: k2168 
o|contracted procedure: k2188 
o|contracted procedure: k2206 
o|contracted procedure: k2212 
o|contracted procedure: k2233 
o|contracted procedure: k2265 
o|contracted procedure: k2274 
o|contracted procedure: k2283 
o|contracted procedure: k2298 
o|contracted procedure: k2315 
o|contracted procedure: k2344 
o|contracted procedure: k2363 
o|contracted procedure: k2376 
o|contracted procedure: k2401 
o|contracted procedure: k2409 
o|contracted procedure: k2435 
o|contracted procedure: k2442 
o|contracted procedure: k2446 
o|contracted procedure: k2464 
o|contracted procedure: k2482 
o|contracted procedure: k2492 
o|contracted procedure: k2504 
o|contracted procedure: k2526 
o|contracted procedure: k2532 
o|contracted procedure: k2547 
o|contracted procedure: k2565 
o|contracted procedure: k2574 
o|contracted procedure: k2592 
o|contracted procedure: k2611 
o|contracted procedure: k2654 
o|contracted procedure: k2684 
o|contracted procedure: k2693 
o|contracted procedure: k2708 
o|contracted procedure: k2711 
o|contracted procedure: k2724 
o|contracted procedure: k2731 
o|contracted procedure: k2768 
o|contracted procedure: k2774 
o|contracted procedure: k2781 
o|contracted procedure: k2804 
o|contracted procedure: k2826 
o|contracted procedure: k2835 
o|contracted procedure: k2838 
o|contracted procedure: k2850 
o|contracted procedure: k2863 
o|contracted procedure: k2884 
o|contracted procedure: k2895 
o|contracted procedure: k2888 
o|contracted procedure: k2907 
o|contracted procedure: k2903 
o|contracted procedure: k2899 
o|contracted procedure: k2929 
o|contracted procedure: k2940 
o|contracted procedure: k2946 
o|contracted procedure: k2971 
o|contracted procedure: k2961 
o|contracted procedure: k2996 
o|contracted procedure: k3000 
o|contracted procedure: k3031 
o|contracted procedure: k3051 
o|contracted procedure: k3035 
o|contracted procedure: k3060 
o|contracted procedure: k3078 
o|contracted procedure: k3098 
o|contracted procedure: k3101 
o|contracted procedure: k3119 
o|contracted procedure: k3105 
o|contracted procedure: k3137 
o|contracted procedure: k3140 
o|contracted procedure: k3158 
o|contracted procedure: k3144 
o|contracted procedure: k3176 
o|contracted procedure: k3186 
o|contracted procedure: k3189 
o|contracted procedure: k3200 
o|contracted procedure: k3204 
o|contracted procedure: k3215 
o|contracted procedure: k3219 
o|contracted procedure: k3268 
o|contracted procedure: k3277 
o|contracted procedure: k3271 
o|contracted procedure: k3306 
o|contracted procedure: k3315 
o|contracted procedure: k3318 
o|contracted procedure: k3324 
o|contracted procedure: k3330 
o|contracted procedure: k3336 
o|contracted procedure: k3339 
o|contracted procedure: k3345 
o|contracted procedure: k3351 
o|contracted procedure: k3357 
o|contracted procedure: k3384 
o|contracted procedure: k3390 
o|contracted procedure: k3396 
o|contracted procedure: k3460 
o|contracted procedure: k3444 
o|contracted procedure: k3468 
o|contracted procedure: k3480 
o|contracted procedure: k3500 
o|contracted procedure: k3489 
o|contracted procedure: k3506 
o|contracted procedure: k3509 
o|contracted procedure: k3516 
o|contracted procedure: k3528 
o|contracted procedure: k3532 
o|contracted procedure: k3544 
o|contracted procedure: k3767 
o|contracted procedure: k3556 
o|contracted procedure: k3562 
o|contracted procedure: k3568 
o|contracted procedure: k3581 
o|contracted procedure: k3594 
o|contracted procedure: k3607 
o|contracted procedure: k3624 
o|contracted procedure: k3641 
o|contracted procedure: k3658 
o|contracted procedure: k3667 
o|contracted procedure: k3676 
o|contracted procedure: k3685 
o|contracted procedure: k3694 
o|contracted procedure: k3697 
o|contracted procedure: k3706 
o|contracted procedure: k3722 
o|contracted procedure: k3733 
o|contracted procedure: k3813 
o|contracted procedure: k3819 
o|contracted procedure: k3825 
o|contracted procedure: k3829 
o|contracted procedure: k3839 
o|contracted procedure: k3884 
o|contracted procedure: k3854 
o|contracted procedure: k3865 
o|contracted procedure: k3881 
o|contracted procedure: k3899 
o|contracted procedure: k4002 
o|contracted procedure: k3912 
o|contracted procedure: k3996 
o|contracted procedure: k3915 
o|contracted procedure: k3990 
o|contracted procedure: k3918 
o|contracted procedure: k3984 
o|contracted procedure: k3921 
o|contracted procedure: k3931 
o|contracted procedure: k3940 
o|contracted procedure: k3952 
o|contracted procedure: k3955 
o|contracted procedure: k3978 
o|simplifications: ((if . 3) (let . 72)) 
o|removed binding forms: 272 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest8485 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest8485 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest8485 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest8485 0 
(o x)|known list op on rest arg sublist: ##core#rest-car args110 0 
o|inlining procedure: k1310 
o|inlining procedure: k1310 
(o x)|known list op on rest arg sublist: ##core#rest-cdr args110 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest148149 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest148149 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest148149 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest148149 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest224227 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest224227 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest224227 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest224227 0 
o|contracted procedure: k1648 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest268269 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest268269 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest268269 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest268269 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest288289 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest288289 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? port299 0 
(o x)|known list op on rest arg sublist: ##core#rest-car port299 0 
o|contracted procedure: k1918 
(o x)|known list op on rest arg sublist: ##core#rest-null? more314 0 
(o x)|known list op on rest arg sublist: ##core#rest-car more314 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr more314 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest346347 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest346347 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest359361 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest359361 0 
o|contracted procedure: k2398 
(o x)|known list op on rest arg sublist: ##core#rest-car opt738 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest871873 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest871873 0 
o|inlining procedure: k3860 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest898899 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest898899 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest898899 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest898899 0 
o|removed binding forms: 3 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1113 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1113 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1113 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1113 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1369 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1369 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1369 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1369 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1619 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1619 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1619 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1619 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1764 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1764 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1764 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1764 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? _%rest318338 1 
(o x)|known list op on rest arg sublist: ##core#rest-car _%rest318338 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr _%rest318338 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3916 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r3916 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r3916 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r3916 1 
o|removed binding forms: 4 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1119 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1119 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1119 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1119 2 
o|removed binding forms: 11 
o|removed binding forms: 2 
o|direct leaf routine/allocation: read-macro-prefix418 0 
o|direct leaf routine/allocation: fetch781 0 
o|contracted procedure: "(extras.scm:281) k2176" 
o|contracted procedure: "(extras.scm:418) k2937" 
o|contracted procedure: "(extras.scm:592) k3547" 
o|contracted procedure: "(extras.scm:594) k3559" 
o|contracted procedure: "(extras.scm:612) k3713" 
o|contracted procedure: "(extras.scm:614) k3729" 
o|removed binding forms: 6 
o|direct leaf routine/allocation: skip804 0 
o|inlining procedure: k3550 
o|converted assignments to bindings: (skip804) 
o|simplifications: ((let . 1)) 
o|customizable procedures: (chicken.format#fprintf0 rec776 next782 loop787 pp421 k3309 tail1621 tail3623 tail2622 indent543 loop603 pp-down548 style562 pp-call546 pp-general549 pr544 chicken.pretty-print#generic-write pp-list547 spaces542 doloop527528 g518519 g507508 loop484 wr-expr464 loop470 read-macro?416 wr-lst465 out419 wr420 k2059 def-n319336 def-port320334 body317326 loop306 loop256 k1639 k1563 loop204 loop189 loop160 k1218 loop127 g122123 doloop9899) 
o|calls to known targets: 197 
o|unused rest argument: rest8485 f_1107 
o|unused rest argument: rest148149 f_1363 
o|unused rest argument: rest224227 f_1613 
o|unused rest argument: rest268269 f_1758 
o|unused rest argument: rest288289 f_1811 
o|unused rest argument: port299 f_1839 
o|unused rest argument: more314 f_1895 
o|unused rest argument: rest346347 f_1978 
o|unused rest argument: rest359361 f_2005 
o|identified direct recursive calls: f_2393 1 
o|identified direct recursive calls: f_3717 1 
o|identified direct recursive calls: f_3539 1 
o|unused rest argument: rest871873 f_3852 
o|unused rest argument: rest898899 f_3910 
o|fast box initializations: 43 
o|fast global references: 5 
o|fast global assignments: 2 
o|dropping unused closure argument: f_2030 
o|dropping unused closure argument: f_2033 
o|dropping unused closure argument: f_2095 
o|dropping unused closure argument: f_3466 
*/
/* end of file */
