/* Generated from pathname.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: pathname.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file pathname.c -emit-import-library chicken.pathname
   unit: pathname
   uses: data-structures irregex library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_irregex_toplevel)
C_externimport void C_ccall C_irregex_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[76];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,97,98,115,111,108,117,116,101,45,112,97,116,104,110,97,109,101,63,32,112,110,41};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,8),40,108,112,32,108,101,110,41};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,99,104,111,112,45,112,100,115,32,115,116,114,41,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,115,116,114,115,41,0,0,0,0,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,16),40,99,111,110,99,45,100,105,114,115,32,100,105,114,115,41};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,24),40,99,97,110,111,110,105,99,97,108,105,122,101,45,100,105,114,115,32,100,105,114,115,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,33),40,95,109,97,107,101,45,112,97,116,104,110,97,109,101,32,108,111,99,32,100,105,114,32,102,105,108,101,32,101,120,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,109,97,107,101,45,112,97,116,104,110,97,109,101,32,100,105,114,115,32,102,105,108,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,58),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,109,97,107,101,45,97,98,115,111,108,117,116,101,45,112,97,116,104,110,97,109,101,32,100,105,114,115,32,102,105,108,101,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,15),40,115,116,114,105,112,45,112,100,115,32,100,105,114,41,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,100,101,99,111,109,112,111,115,101,45,112,97,116,104,110,97,109,101,32,112,110,41};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,7),40,97,49,48,49,55,41,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,29),40,97,49,48,50,51,32,100,105,114,50,50,57,32,102,105,108,101,50,51,49,32,101,120,116,50,51,51,41,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,100,105,114,101,99,116,111,114,121,32,112,110,41};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,7),40,97,49,48,51,50,41,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,29),40,97,49,48,51,56,32,100,105,114,50,52,51,32,102,105,108,101,50,52,53,32,101,120,116,50,52,55,41,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,102,105,108,101,32,112,110,41,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,7),40,97,49,48,52,55,41,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,29),40,97,49,48,53,51,32,100,105,114,50,53,55,32,102,105,108,101,50,53,57,32,101,120,116,50,54,49,41,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,101,120,116,101,110,115,105,111,110,32,112,110,41};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,7),40,97,49,48,54,50,41,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,29),40,97,49,48,54,56,32,100,105,114,50,55,49,32,102,105,108,101,50,55,51,32,101,120,116,50,55,53,41,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,115,116,114,105,112,45,100,105,114,101,99,116,111,114,121,32,112,110,41,0,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,7),40,97,49,48,56,48,41,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,29),40,97,49,48,56,54,32,100,105,114,50,56,53,32,102,105,108,101,50,56,55,32,101,120,116,50,56,57,41,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,115,116,114,105,112,45,101,120,116,101,110,115,105,111,110,32,112,110,41,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,7),40,97,49,48,57,56,41,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,27),40,97,49,49,48,52,32,95,51,48,48,32,102,105,108,101,51,48,50,32,101,120,116,51,48,52,41,0,0,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,114,101,112,108,97,99,101,45,100,105,114,101,99,116,111,114,121,32,112,110,32,100,105,114,41,0,0,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,7),40,97,49,49,49,54,41,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,26),40,97,49,49,50,50,32,100,105,114,51,49,53,32,95,51,49,55,32,101,120,116,51,49,57,41,0,0,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,114,101,112,108,97,99,101,45,102,105,108,101,32,112,110,32,102,105,108,101,41};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,7),40,97,49,49,51,52,41,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,27),40,97,49,49,52,48,32,100,105,114,51,51,48,32,102,105,108,101,51,51,50,32,95,51,51,52,41,0,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,52),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,112,97,116,104,110,97,109,101,45,114,101,112,108,97,99,101,45,101,120,116,101,110,115,105,111,110,32,112,110,32,101,120,116,41,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,15),40,97,100,100,112,97,114,116,32,112,97,114,116,115,41,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,6),40,112,100,115,63,41,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,8),40,103,51,56,53,32,112,41};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,23),40,102,111,114,45,101,97,99,104,45,108,111,111,112,51,56,52,32,103,51,57,49,41,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,19),40,108,111,111,112,32,105,32,112,114,101,118,32,112,97,114,116,115,41,0,0,0,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,49),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,110,111,114,109,97,108,105,122,101,45,112,97,116,104,110,97,109,101,32,112,97,116,104,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,48),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,115,112,108,105,116,45,100,105,114,101,99,116,111,114,121,32,108,111,99,32,100,105,114,32,107,101,101,112,63,41};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,100,105,114,101,99,116,111,114,121,45,110,117,108,108,63,32,100,105,114,41,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,42),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,100,101,99,111,109,112,111,115,101,45,100,105,114,101,99,116,111,114,121,32,100,105,114,41,0,0,0,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,97,98,115,111,108,117,116,101,45,112,97,116,104,110,97,109,101,45,114,111,111,116,32,112,110,41,0,0,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,114,111,111,116,45,111,114,105,103,105,110,32,114,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,114,111,111,116,45,100,105,114,101,99,116,111,114,121,32,114,116,41,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,97,98,115,111,108,117,116,101,45,112,97,116,104,110,97,109,101,45,114,111,111,116,32,112,110,41,0,0,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,114,111,111,116,45,111,114,105,103,105,110,32,114,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,112,97,116,104,110,97,109,101,35,114,111,111,116,45,100,105,114,101,99,116,111,114,121,32,114,116,41,0,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1006)
static void C_ccall f_1006(C_word c,C_word *av) C_noret;
C_noret_decl(f_1012)
static void C_ccall f_1012(C_word c,C_word *av) C_noret;
C_noret_decl(f_1018)
static void C_ccall f_1018(C_word c,C_word *av) C_noret;
C_noret_decl(f_1024)
static void C_ccall f_1024(C_word c,C_word *av) C_noret;
C_noret_decl(f_1027)
static void C_ccall f_1027(C_word c,C_word *av) C_noret;
C_noret_decl(f_1033)
static void C_ccall f_1033(C_word c,C_word *av) C_noret;
C_noret_decl(f_1039)
static void C_ccall f_1039(C_word c,C_word *av) C_noret;
C_noret_decl(f_1042)
static void C_ccall f_1042(C_word c,C_word *av) C_noret;
C_noret_decl(f_1048)
static void C_ccall f_1048(C_word c,C_word *av) C_noret;
C_noret_decl(f_1054)
static void C_ccall f_1054(C_word c,C_word *av) C_noret;
C_noret_decl(f_1057)
static void C_ccall f_1057(C_word c,C_word *av) C_noret;
C_noret_decl(f_1063)
static void C_ccall f_1063(C_word c,C_word *av) C_noret;
C_noret_decl(f_1069)
static void C_ccall f_1069(C_word c,C_word *av) C_noret;
C_noret_decl(f_1075)
static void C_ccall f_1075(C_word c,C_word *av) C_noret;
C_noret_decl(f_1081)
static void C_ccall f_1081(C_word c,C_word *av) C_noret;
C_noret_decl(f_1087)
static void C_ccall f_1087(C_word c,C_word *av) C_noret;
C_noret_decl(f_1093)
static void C_ccall f_1093(C_word c,C_word *av) C_noret;
C_noret_decl(f_1099)
static void C_ccall f_1099(C_word c,C_word *av) C_noret;
C_noret_decl(f_1105)
static void C_ccall f_1105(C_word c,C_word *av) C_noret;
C_noret_decl(f_1111)
static void C_ccall f_1111(C_word c,C_word *av) C_noret;
C_noret_decl(f_1117)
static void C_ccall f_1117(C_word c,C_word *av) C_noret;
C_noret_decl(f_1123)
static void C_ccall f_1123(C_word c,C_word *av) C_noret;
C_noret_decl(f_1129)
static void C_ccall f_1129(C_word c,C_word *av) C_noret;
C_noret_decl(f_1135)
static void C_ccall f_1135(C_word c,C_word *av) C_noret;
C_noret_decl(f_1141)
static void C_ccall f_1141(C_word c,C_word *av) C_noret;
C_noret_decl(f_1151)
static C_word C_fcall f_1151(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_1189)
static void C_ccall f_1189(C_word c,C_word *av) C_noret;
C_noret_decl(f_1198)
static C_word C_fcall f_1198(C_word t0,C_word t1);
C_noret_decl(f_1221)
static void C_fcall f_1221(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1231)
static void C_fcall f_1231(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1255)
static void C_ccall f_1255(C_word c,C_word *av) C_noret;
C_noret_decl(f_1258)
static void C_ccall f_1258(C_word c,C_word *av) C_noret;
C_noret_decl(f_1261)
static void C_ccall f_1261(C_word c,C_word *av) C_noret;
C_noret_decl(f_1262)
static void C_fcall f_1262(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1266)
static void C_ccall f_1266(C_word c,C_word *av) C_noret;
C_noret_decl(f_1276)
static void C_ccall f_1276(C_word c,C_word *av) C_noret;
C_noret_decl(f_1279)
static void C_ccall f_1279(C_word c,C_word *av) C_noret;
C_noret_decl(f_1282)
static void C_ccall f_1282(C_word c,C_word *av) C_noret;
C_noret_decl(f_1285)
static void C_fcall f_1285(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1292)
static void C_ccall f_1292(C_word c,C_word *av) C_noret;
C_noret_decl(f_1299)
static void C_ccall f_1299(C_word c,C_word *av) C_noret;
C_noret_decl(f_1311)
static void C_fcall f_1311(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1321)
static void C_ccall f_1321(C_word c,C_word *av) C_noret;
C_noret_decl(f_1347)
static void C_ccall f_1347(C_word c,C_word *av) C_noret;
C_noret_decl(f_1356)
static void C_fcall f_1356(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1392)
static void C_ccall f_1392(C_word c,C_word *av) C_noret;
C_noret_decl(f_1408)
static void C_fcall f_1408(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1412)
static void C_ccall f_1412(C_word c,C_word *av) C_noret;
C_noret_decl(f_1462)
static void C_fcall f_1462(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1475)
static void C_ccall f_1475(C_word c,C_word *av) C_noret;
C_noret_decl(f_1483)
static void C_ccall f_1483(C_word c,C_word *av) C_noret;
C_noret_decl(f_1485)
static C_word C_fcall f_1485(C_word t0);
C_noret_decl(f_1515)
static void C_ccall f_1515(C_word c,C_word *av) C_noret;
C_noret_decl(f_1554)
static void C_ccall f_1554(C_word c,C_word *av) C_noret;
C_noret_decl(f_1558)
static void C_ccall f_1558(C_word c,C_word *av) C_noret;
C_noret_decl(f_1561)
static void C_ccall f_1561(C_word c,C_word *av) C_noret;
C_noret_decl(f_1564)
static void C_ccall f_1564(C_word c,C_word *av) C_noret;
C_noret_decl(f_1571)
static void C_ccall f_1571(C_word c,C_word *av) C_noret;
C_noret_decl(f_1593)
static void C_ccall f_1593(C_word c,C_word *av) C_noret;
C_noret_decl(f_1596)
static void C_ccall f_1596(C_word c,C_word *av) C_noret;
C_noret_decl(f_1598)
static void C_ccall f_1598(C_word c,C_word *av) C_noret;
C_noret_decl(f_1604)
static void C_ccall f_1604(C_word c,C_word *av) C_noret;
C_noret_decl(f_1613)
static void C_ccall f_1613(C_word c,C_word *av) C_noret;
C_noret_decl(f_1623)
static void C_ccall f_1623(C_word c,C_word *av) C_noret;
C_noret_decl(f_1625)
static void C_ccall f_1625(C_word c,C_word *av) C_noret;
C_noret_decl(f_1631)
static void C_ccall f_1631(C_word c,C_word *av) C_noret;
C_noret_decl(f_1634)
static void C_ccall f_1634(C_word c,C_word *av) C_noret;
C_noret_decl(f_595)
static void C_ccall f_595(C_word c,C_word *av) C_noret;
C_noret_decl(f_598)
static void C_ccall f_598(C_word c,C_word *av) C_noret;
C_noret_decl(f_601)
static void C_ccall f_601(C_word c,C_word *av) C_noret;
C_noret_decl(f_607)
static void C_fcall f_607(C_word t0,C_word t1) C_noret;
C_noret_decl(f_609)
static void C_ccall f_609(C_word c,C_word *av) C_noret;
C_noret_decl(f_620)
static void C_ccall f_620(C_word c,C_word *av) C_noret;
C_noret_decl(f_622)
static void C_fcall f_622(C_word t0,C_word t1) C_noret;
C_noret_decl(f_635)
static void C_fcall f_635(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_642)
static void C_fcall f_642(C_word t0,C_word t1) C_noret;
C_noret_decl(f_690)
static void C_fcall f_690(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_699)
static void C_fcall f_699(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_727)
static void C_ccall f_727(C_word c,C_word *av) C_noret;
C_noret_decl(f_731)
static void C_ccall f_731(C_word c,C_word *av) C_noret;
C_noret_decl(f_741)
static void C_fcall f_741(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_772)
static void C_fcall f_772(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_795)
static void C_ccall f_795(C_word c,C_word *av) C_noret;
C_noret_decl(f_820)
static void C_fcall f_820(C_word t0,C_word t1) C_noret;
C_noret_decl(f_860)
static void C_ccall f_860(C_word c,C_word *av) C_noret;
C_noret_decl(f_871)
static void C_ccall f_871(C_word c,C_word *av) C_noret;
C_noret_decl(f_879)
static void C_ccall f_879(C_word c,C_word *av) C_noret;
C_noret_decl(f_890)
static void C_ccall f_890(C_word c,C_word *av) C_noret;
C_noret_decl(f_893)
static void C_ccall f_893(C_word c,C_word *av) C_noret;
C_noret_decl(f_896)
static void C_ccall f_896(C_word c,C_word *av) C_noret;
C_noret_decl(f_915)
static void C_ccall f_915(C_word c,C_word *av) C_noret;
C_noret_decl(f_918)
static void C_ccall f_918(C_word c,C_word *av) C_noret;
C_noret_decl(f_919)
static void C_fcall f_919(C_word t0,C_word t1) C_noret;
C_noret_decl(f_926)
static void C_ccall f_926(C_word c,C_word *av) C_noret;
C_noret_decl(f_940)
static void C_ccall f_940(C_word c,C_word *av) C_noret;
C_noret_decl(f_956)
static void C_ccall f_956(C_word c,C_word *av) C_noret;
C_noret_decl(f_966)
static void C_ccall f_966(C_word c,C_word *av) C_noret;
C_noret_decl(f_970)
static void C_ccall f_970(C_word c,C_word *av) C_noret;
C_noret_decl(f_974)
static void C_ccall f_974(C_word c,C_word *av) C_noret;
C_noret_decl(f_978)
static void C_ccall f_978(C_word c,C_word *av) C_noret;
C_noret_decl(f_981)
static void C_ccall f_981(C_word c,C_word *av) C_noret;
C_noret_decl(f_991)
static void C_ccall f_991(C_word c,C_word *av) C_noret;
C_noret_decl(f_995)
static void C_ccall f_995(C_word c,C_word *av) C_noret;
C_noret_decl(f_999)
static void C_ccall f_999(C_word c,C_word *av) C_noret;
C_noret_decl(C_pathname_toplevel)
C_externexport void C_ccall C_pathname_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1221)
static void C_ccall trf_1221(C_word c,C_word *av) C_noret;
static void C_ccall trf_1221(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1221(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1231)
static void C_ccall trf_1231(C_word c,C_word *av) C_noret;
static void C_ccall trf_1231(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1231(t0,t1);}

C_noret_decl(trf_1262)
static void C_ccall trf_1262(C_word c,C_word *av) C_noret;
static void C_ccall trf_1262(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1262(t0,t1,t2);}

C_noret_decl(trf_1285)
static void C_ccall trf_1285(C_word c,C_word *av) C_noret;
static void C_ccall trf_1285(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1285(t0,t1);}

C_noret_decl(trf_1311)
static void C_ccall trf_1311(C_word c,C_word *av) C_noret;
static void C_ccall trf_1311(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1311(t0,t1,t2);}

C_noret_decl(trf_1356)
static void C_ccall trf_1356(C_word c,C_word *av) C_noret;
static void C_ccall trf_1356(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1356(t0,t1);}

C_noret_decl(trf_1408)
static void C_ccall trf_1408(C_word c,C_word *av) C_noret;
static void C_ccall trf_1408(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1408(t0,t1);}

C_noret_decl(trf_1462)
static void C_ccall trf_1462(C_word c,C_word *av) C_noret;
static void C_ccall trf_1462(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1462(t0,t1,t2,t3);}

C_noret_decl(trf_607)
static void C_ccall trf_607(C_word c,C_word *av) C_noret;
static void C_ccall trf_607(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_607(t0,t1);}

C_noret_decl(trf_622)
static void C_ccall trf_622(C_word c,C_word *av) C_noret;
static void C_ccall trf_622(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_622(t0,t1);}

C_noret_decl(trf_635)
static void C_ccall trf_635(C_word c,C_word *av) C_noret;
static void C_ccall trf_635(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_635(t0,t1,t2);}

C_noret_decl(trf_642)
static void C_ccall trf_642(C_word c,C_word *av) C_noret;
static void C_ccall trf_642(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_642(t0,t1);}

C_noret_decl(trf_690)
static void C_ccall trf_690(C_word c,C_word *av) C_noret;
static void C_ccall trf_690(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_690(t0,t1,t2);}

C_noret_decl(trf_699)
static void C_ccall trf_699(C_word c,C_word *av) C_noret;
static void C_ccall trf_699(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_699(t0,t1,t2);}

C_noret_decl(trf_741)
static void C_ccall trf_741(C_word c,C_word *av) C_noret;
static void C_ccall trf_741(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_741(t0,t1,t2);}

C_noret_decl(trf_772)
static void C_ccall trf_772(C_word c,C_word *av) C_noret;
static void C_ccall trf_772(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_772(t0,t1,t2,t3,t4);}

C_noret_decl(trf_820)
static void C_ccall trf_820(C_word c,C_word *av) C_noret;
static void C_ccall trf_820(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_820(t0,t1);}

C_noret_decl(trf_919)
static void C_ccall trf_919(C_word c,C_word *av) C_noret;
static void C_ccall trf_919(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_919(t0,t1);}

/* k1004 in k979 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1006(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1006,c,av);}
/* pathname.scm:187: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}

/* chicken.pathname#pathname-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1012(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_1012,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1018,a[2]=t2,a[3]=((C_word)li11),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1024,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:191: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a1017 in chicken.pathname#pathname-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1018,c,av);}
/* pathname.scm:191: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1023 in chicken.pathname#pathname-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1024(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1024,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* chicken.pathname#pathname-file in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1027(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_1027,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1033,a[2]=t2,a[3]=((C_word)li14),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1039,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:196: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a1032 in chicken.pathname#pathname-file in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1033(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1033,c,av);}
/* pathname.scm:196: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1038 in chicken.pathname#pathname-file in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1039(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1039,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* chicken.pathname#pathname-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1042(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_1042,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1048,a[2]=t2,a[3]=((C_word)li17),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1054,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:201: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a1047 in chicken.pathname#pathname-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1048(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1048,c,av);}
/* pathname.scm:201: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1053 in chicken.pathname#pathname-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1054(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1054,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* chicken.pathname#pathname-strip-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1057(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_1057,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1063,a[2]=t2,a[3]=((C_word)li20),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1069,a[2]=((C_word)li21),tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:206: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a1062 in chicken.pathname#pathname-strip-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1063(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1063,c,av);}
/* pathname.scm:206: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1068 in chicken.pathname#pathname-strip-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1069(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1069,c,av);}
/* pathname.scm:207: make-pathname */
t5=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
av2[3]=t3;
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* chicken.pathname#pathname-strip-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_1075,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1081,a[2]=t2,a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1087,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:211: ##sys#call-with-values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a1080 in chicken.pathname#pathname-strip-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1081(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1081,c,av);}
/* pathname.scm:211: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1086 in chicken.pathname#pathname-strip-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1087,c,av);}
/* pathname.scm:212: make-pathname */
t5=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* chicken.pathname#pathname-replace-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1093(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1093,c,av);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1099,a[2]=t2,a[3]=((C_word)li26),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1105,a[2]=t3,a[3]=((C_word)li27),tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:216: ##sys#call-with-values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
C_call_with_values(4,av2);}}

/* a1098 in chicken.pathname#pathname-replace-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1099(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1099,c,av);}
/* pathname.scm:216: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1104 in chicken.pathname#pathname-replace-directory in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1105(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1105,c,av);}
/* pathname.scm:217: make-pathname */
t5=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t3;
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* chicken.pathname#pathname-replace-file in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1111(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1111,c,av);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1117,a[2]=t2,a[3]=((C_word)li29),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1123,a[2]=t3,a[3]=((C_word)li30),tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:221: ##sys#call-with-values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
C_call_with_values(4,av2);}}

/* a1116 in chicken.pathname#pathname-replace-file in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1117(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1117,c,av);}
/* pathname.scm:221: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1122 in chicken.pathname#pathname-replace-file in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1123,c,av);}
/* pathname.scm:222: make-pathname */
t5=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)t0)[2];
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* chicken.pathname#pathname-replace-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1129(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1129,c,av);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1135,a[2]=t2,a[3]=((C_word)li32),tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1141,a[2]=t3,a[3]=((C_word)li33),tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:226: ##sys#call-with-values */{
C_word *av2=av;
av2[0]=0;
av2[1]=t1;
av2[2]=t4;
av2[3]=t5;
C_call_with_values(4,av2);}}

/* a1134 in chicken.pathname#pathname-replace-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1135,c,av);}
/* pathname.scm:226: decompose-pathname */
t2=*((C_word*)lf[31]+1);{
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

/* a1140 in chicken.pathname#pathname-replace-extension in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1141(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1141,c,av);}
/* pathname.scm:227: make-pathname */
t5=*((C_word*)lf[12]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}

/* addpart in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static C_word C_fcall f_1151(C_word *a,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_stack_overflow_check;{}
if(C_truep(C_i_string_equal_p(lf[46],t1))){
return(t2);}
else{
if(C_truep(C_u_i_string_equal_p(lf[47],t1))){
t3=C_i_nullp(t2);
if(C_truep(t3)){
return((C_truep(t3)?C_a_i_cons(&a,2,t1,t2):C_i_cdr(t2)));}
else{
t4=C_i_car(t2);
t5=C_i_string_equal_p(lf[48],t4);
return((C_truep(t5)?C_a_i_cons(&a,2,t1,t2):C_i_cdr(t2)));}}
else{
return(C_a_i_cons(&a,2,t1,t2));}}}

/* chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1189(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(22,c,5)))){
C_save_and_reclaim((void *)f_1189,c,av);}
a=C_alloc(22);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?((C_word*)t0)[2]:C_get_rest_arg(c,3,av,3,t0));
t5=C_eqp(t4,lf[44]);
t6=(C_truep(t5)?C_make_character(92):C_make_character(47));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1198,a[2]=t4,a[3]=((C_word)li36),tmp=(C_word)a,a+=4,tmp);
t8=C_i_check_string_2(t2,lf[51]);
t9=C_block_size(t2);
t10=C_SCHEME_FALSE;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_SCHEME_FALSE;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_SCHEME_UNDEFINED;
t15=(*a=C_VECTOR_TYPE|1,a[1]=t14,tmp=(C_word)a,a+=2,tmp);
t16=C_set_block_item(t15,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_1221,a[2]=t9,a[3]=t11,a[4]=t6,a[5]=t13,a[6]=((C_word*)t0)[3],a[7]=t2,a[8]=t7,a[9]=t15,a[10]=t4,a[11]=((C_word)li39),tmp=(C_word)a,a+=12,tmp));
t17=((C_word*)t15)[1];
f_1221(t17,t1,C_fix(0),C_fix(0),C_SCHEME_END_OF_LIST);}

/* pds? in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static C_word C_fcall f_1198(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_stack_overflow_check;{}
t2=C_eqp(((C_word*)t0)[2],lf[44]);
return((C_truep(t2)?C_u_i_memq(t1,lf[50]):C_eqp(t1,C_make_character(47))));}

/* loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1221(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,4)))){
C_save_and_reclaim_args((void *)trf_1221,5,t0,t1,t2,t3,t4);}
a=C_alloc(16);
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1231,a[2]=t5,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=t2,a[8]=t3,tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_fixnum_greaterp(t2,t3))){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1347,a[2]=((C_word*)t0)[6],a[3]=t5,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:254: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t7;
av2[2]=((C_word*)t0)[7];
av2[3]=t3;
av2[4]=t2;
tp(5,av2);}}
else{
t7=t6;
f_1231(t7,C_SCHEME_UNDEFINED);}}
else{
t6=(
/* pathname.scm:273: pds? */
  f_1198(((C_word*)t0)[8],C_i_string_ref(((C_word*)t0)[7],t2))
);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1356,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[9],a[5]=t1,a[6]=t5,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_not(((C_word*)((C_word*)t0)[3])[1]))){
t8=C_eqp(t2,t3);
if(C_truep(t8)){
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[52]);
t10=t7;
f_1356(t10,t9);}
else{
t9=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[60]);
t10=t7;
f_1356(t10,t9);}}
else{
t8=t7;
f_1356(t8,C_SCHEME_UNDEFINED);}}
else{
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1408,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[9],a[4]=t1,a[5]=t2,a[6]=((C_word*)t0)[7],a[7]=t3,a[8]=t5,tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_nullp(((C_word*)t5)[1]))){
t8=C_i_string_ref(((C_word*)t0)[7],t2);
t9=t7;
f_1408(t9,(C_truep(C_u_i_char_equalp(t8,C_make_character(58)))?C_eqp(((C_word*)t0)[10],lf[44]):C_SCHEME_FALSE));}
else{
t8=t7;
f_1408(t8,C_SCHEME_FALSE);}}}}

/* k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1231(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_1231,2,t0,t1);}
a=C_alloc(9);
if(C_truep(C_i_nullp(((C_word*)((C_word*)t0)[2])[1]))){
t2=C_eqp(((C_word*)((C_word*)t0)[3])[1],lf[52]);
if(C_truep(t2)){
t3=C_a_i_string(&a,1,((C_word*)t0)[4]);
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
/* pathname.scm:257: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=((C_word*)t0)[6];
av2[2]=((C_word*)((C_word*)t0)[5])[1];
av2[3]=t3;
tp(4,av2);}}
else{
t4=((C_word*)t0)[6];{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=lf[53];
if(C_truep(((C_word*)((C_word*)t0)[5])[1])){
/* pathname.scm:257: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=((C_word*)t0)[6];
av2[2]=((C_word*)((C_word*)t0)[5])[1];
av2[3]=t3;
tp(4,av2);}}
else{
t4=((C_word*)t0)[6];{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}
else{
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1255,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
/* pathname.scm:258: chicken.base#open-output-string */
t3=*((C_word*)lf[59]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1255(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_1255,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1258,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* pathname.scm:259: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[58]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[58]+1);
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[8])[1];
tp(3,av2);}}

/* k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1258,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1261,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* pathname.scm:260: scheme#display */
t3=*((C_word*)lf[54]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(t1);
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1261(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_1261,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1262,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li37),tmp=(C_word)a,a+=5,tmp);
t3=C_u_i_cdr(((C_word*)t0)[4]);
t4=C_i_check_list_2(t3,lf[56]);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1276,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],tmp=(C_word)a,a+=9,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1311,a[2]=t7,a[3]=t2,a[4]=((C_word)li38),tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_1311(t9,t5,t3);}

/* g385 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1262(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_1262,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1266,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:263: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[55]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[55]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[2];
tp(4,av2);}}

/* k1264 in g385 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1266(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1266,c,av);}
/* pathname.scm:264: scheme#display */
t2=*((C_word*)lf[54]+1);{
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

/* k1274 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1276(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_1276,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1279,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=C_eqp(((C_word*)t0)[7],((C_word*)t0)[8]);
if(C_truep(t3)){
/* pathname.scm:266: ##sys#write-char-0 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[55]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[55]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
tp(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_1279(2,av2);}}}

/* k1277 in k1274 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1279(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1279,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1282,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* pathname.scm:267: chicken.base#get-output-string */
t3=*((C_word*)lf[57]+1);{
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

/* k1280 in k1277 in k1274 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1282(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_1282,c,av);}
a=C_alloc(13);
t2=t1;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1285,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t5=C_eqp(((C_word*)((C_word*)t0)[4])[1],lf[52]);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1299,a[2]=t3,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
t7=C_a_i_string(&a,1,((C_word*)t0)[5]);
/* pathname.scm:269: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t6;
av2[2]=t7;
av2[3]=((C_word*)t3)[1];
tp(4,av2);}}
else{
t6=t4;
f_1285(t6,C_SCHEME_UNDEFINED);}}

/* k1283 in k1280 in k1277 in k1274 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1285(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_1285,2,t0,t1);}
a=C_alloc(4);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1292,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:271: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t2;
av2[2]=((C_word*)((C_word*)t0)[2])[1];
av2[3]=((C_word*)((C_word*)t0)[3])[1];
tp(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k1290 in k1283 in k1280 in k1277 in k1274 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1292(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1292,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)((C_word*)t0)[2])[1];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k1297 in k1280 in k1277 in k1274 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1299(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1299,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_1285(t3,t2);}

/* for-each-loop384 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1311(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_1311,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1321,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:261: g385 */
t4=((C_word*)t0)[3];
f_1262(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k1319 in for-each-loop384 in k1259 in k1256 in k1253 in k1229 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1321(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1321,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_1311(t2,((C_word*)t0)[3],C_slot(((C_word*)t0)[4],C_fix(1)));}

/* k1345 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1347(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_1347,c,av);}
a=C_alloc(9);
t2=(
/* pathname.scm:254: addpart */
  f_1151(C_a_i(&a,9),t1,((C_word*)((C_word*)t0)[3])[1])
);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
t4=((C_word*)t0)[4];
f_1231(t4,t3);}

/* k1354 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1356(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_1356,2,t0,t1);}
a=C_alloc(8);
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(t2)){
/* pathname.scm:277: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_1221(t3,((C_word*)t0)[5],C_fixnum_plus(((C_word*)t0)[2],C_fix(1)),C_fixnum_plus(((C_word*)t0)[2],C_fix(1)),((C_word*)((C_word*)t0)[6])[1]);}
else{
t3=C_fixnum_plus(((C_word*)t0)[2],C_fix(1));
t4=C_fixnum_plus(((C_word*)t0)[2],C_fix(1));
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1392,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t3,a[7]=t4,tmp=(C_word)a,a+=8,tmp);
/* pathname.scm:280: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[8];
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[2];
tp(5,av2);}}}

/* k1390 in k1354 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_1392,c,av);}
a=C_alloc(9);
t2=(
/* pathname.scm:280: addpart */
  f_1151(C_a_i(&a,9),t1,((C_word*)((C_word*)t0)[3])[1])
);
/* pathname.scm:278: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_1221(t3,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7],t2);}

/* k1406 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1408(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,4)))){
C_save_and_reclaim_args((void *)trf_1408,2,t0,t1);}
a=C_alloc(6);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1412,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* pathname.scm:284: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(((C_word*)t0)[5],C_fix(1));
tp(5,av2);}}
else{
/* pathname.scm:286: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_1221(t2,((C_word*)t0)[4],C_fixnum_plus(((C_word*)t0)[5],C_fix(1)),((C_word*)t0)[7],((C_word*)((C_word*)t0)[8])[1]);}}

/* k1410 in k1406 in loop in chicken.pathname#normalize-pathname in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1412(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1412,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
/* pathname.scm:285: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_1221(t3,((C_word*)t0)[4],C_fixnum_plus(((C_word*)t0)[5],C_fix(1)),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)),C_SCHEME_END_OF_LIST);}

/* chicken.pathname#split-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_1462(C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_1462,4,t1,t2,t3,t4);}
t5=C_i_check_string_2(t3,t2);
if(C_truep(*((C_word*)lf[10]+1))){
/* pathname.scm:294: chicken.string#string-split */
t6=*((C_word*)lf[62]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t1;
av2[2]=t3;
av2[3]=lf[63];
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
/* pathname.scm:294: chicken.string#string-split */
t6=*((C_word*)lf[62]+1);{
C_word av2[5];
av2[0]=t6;
av2[1]=t1;
av2[2]=t3;
av2[3]=lf[64];
av2[4]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}}

/* chicken.pathname#directory-null? in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1475(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_1475,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1483,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
if(C_truep(C_i_listp(t2))){
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
f_1483(2,av2);}}
else{
/* pathname.scm:300: split-directory */
f_1462(t3,lf[68],t2,C_SCHEME_TRUE);}}

/* k1481 in chicken.pathname#directory-null? in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1483(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1483,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1485,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_1485(t1)
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop in k1481 in chicken.pathname#directory-null? in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static C_word C_fcall f_1485(C_word t1){
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
if(C_truep((C_truep(C_i_equalp(t3,lf[66]))?C_SCHEME_TRUE:(C_truep(C_i_equalp(t3,lf[67]))?C_SCHEME_TRUE:C_SCHEME_FALSE)))){
t5=C_u_i_cdr(t1);
t1=t5;
goto loop;}
else{
return(C_SCHEME_FALSE);}}}

/* chicken.pathname#decompose-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_1515,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1558,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:326: split-directory */
f_1462(t3,lf[70],t2,C_SCHEME_FALSE);}

/* k1552 in k1569 in k1562 in k1559 in k1556 in chicken.pathname#decompose-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1554(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_1554,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
/* pathname.scm:329: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=t2;
C_values(5,av2);}}

/* k1556 in chicken.pathname#decompose-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1558(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_1558,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1561,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:327: absolute-pathname-root */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[2]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=lf[2];
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* k1559 in k1556 in chicken.pathname#decompose-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1561(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1561,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1564,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:328: root-origin */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[3]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=lf[3];
av2[1]=t2;
av2[2]=t1;
tp(3,av2);}}

/* k1562 in k1559 in k1556 in chicken.pathname#decompose-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1564(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1564,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1571,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:329: root-directory */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[4]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=lf[4];
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
tp(3,av2);}}

/* k1569 in k1562 in k1559 in k1556 in chicken.pathname#decompose-directory in k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1571(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_1571,c,av);}
a=C_alloc(6);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=C_i_not(t2);
t4=(C_truep(t3)?((C_word*)t0)[2]:C_SCHEME_FALSE);
if(C_truep(C_i_not(((C_word*)t0)[3]))){
/* pathname.scm:329: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=t4;
C_values(5,av2);}}
else{
t5=C_i_car(t4);
t6=C_block_size(((C_word*)t0)[3]);
if(C_truep(C_i_not(C_substring_compare(((C_word*)t0)[3],t5,C_fix(0),C_fix(0),t6)))){
/* pathname.scm:329: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=t4;
C_values(5,av2);}}
else{
t7=C_u_i_cdr(t4);
t8=C_block_size(t5);
t9=C_eqp(t6,t8);
if(C_truep(t9)){
/* pathname.scm:329: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=t7;
C_values(5,av2);}}
else{
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1554,a[2]=t7,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* pathname.scm:325: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=t10;
av2[2]=t5;
av2[3]=t6;
av2[4]=t8;
tp(5,av2);}}}}}

/* k1591 in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_1593(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,5)))){
C_save_and_reclaim((void *)f_1593,c,av);}
a=C_alloc(17);
t2=C_eqp(t1,lf[43]);
t3=(C_truep(t2)?lf[44]:lf[45]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1151,a[2]=((C_word)li35),tmp=(C_word)a,a+=3,tmp);
t5=C_mutate((C_word*)lf[49]+1 /* (set! chicken.pathname#normalize-pathname ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1189,a[2]=t3,a[3]=t4,a[4]=((C_word)li40),tmp=(C_word)a,a+=5,tmp));
t6=C_mutate(&lf[61] /* (set! chicken.pathname#split-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1462,a[2]=((C_word)li41),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[65]+1 /* (set! chicken.pathname#directory-null? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1475,a[2]=((C_word)li43),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[69]+1 /* (set! chicken.pathname#decompose-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1515,a[2]=((C_word)li44),tmp=(C_word)a,a+=3,tmp));
t9=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k1594 in k599 in k596 in k593 */
static void C_ccall f_1596(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1596,c,av);}
a=C_alloc(10);
t2=C_mutate(&lf[2] /* (set! chicken.pathname#absolute-pathname-root ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1598,a[2]=t1,a[3]=((C_word)li45),tmp=(C_word)a,a+=4,tmp));
t3=C_mutate(&lf[3] /* (set! chicken.pathname#root-origin ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1604,a[2]=((C_word)li46),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate(&lf[4] /* (set! chicken.pathname#root-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1613,a[2]=((C_word)li47),tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t0)[2];
f_607(t5,t4);}

/* chicken.pathname#absolute-pathname-root in k1594 in k599 in k596 in k593 */
static void C_ccall f_1598(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1598,c,av);}
/* pathname.scm:72: chicken.irregex#irregex-match */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.pathname#root-origin in k1594 in k599 in k596 in k593 */
static void C_ccall f_1604(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1604,c,av);}
if(C_truep(t2)){
/* pathname.scm:73: chicken.irregex#irregex-match-substring */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* chicken.pathname#root-directory in k1594 in k599 in k596 in k593 */
static void C_ccall f_1613(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1613,c,av);}
if(C_truep(t2)){
/* pathname.scm:74: chicken.irregex#irregex-match-substring */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k1621 in k599 in k596 in k593 */
static void C_ccall f_1623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_1623,c,av);}
a=C_alloc(10);
t2=C_mutate(&lf[2] /* (set! chicken.pathname#absolute-pathname-root ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1625,a[2]=t1,a[3]=((C_word)li48),tmp=(C_word)a,a+=4,tmp));
t3=C_mutate(&lf[3] /* (set! chicken.pathname#root-origin ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1631,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate(&lf[4] /* (set! chicken.pathname#root-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1634,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp));
t5=((C_word*)t0)[2];
f_607(t5,t4);}

/* chicken.pathname#absolute-pathname-root in k1621 in k599 in k596 in k593 */
static void C_ccall f_1625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1625,c,av);}
/* pathname.scm:76: chicken.irregex#irregex-match */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.pathname#root-origin in k1621 in k599 in k596 in k593 */
static void C_ccall f_1631(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1631,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* chicken.pathname#root-directory in k1621 in k599 in k596 in k593 */
static void C_ccall f_1634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1634,c,av);}
if(C_truep(t2)){
/* pathname.scm:78: chicken.irregex#irregex-match-substring */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k593 */
static void C_ccall f_595(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_595,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_598,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_irregex_toplevel(2,av2);}}

/* k596 in k593 */
static void C_ccall f_598(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_598,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_601,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k599 in k596 in k593 */
static void C_ccall f_601(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_601,c,av);}
a=C_alloc(6);
t2=lf[2] /* chicken.pathname#absolute-pathname-root */ =C_SCHEME_UNDEFINED;;
t3=lf[3] /* chicken.pathname#root-origin */ =C_SCHEME_UNDEFINED;;
t4=lf[4] /* chicken.pathname#root-directory */ =C_SCHEME_UNDEFINED;;
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_607,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(*((C_word*)lf[10]+1))){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1596,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:71: chicken.irregex#irregex */
t7=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[74];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1623,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:75: chicken.irregex#irregex */
t7=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[75];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* k605 in k599 in k596 in k593 */
static void C_fcall f_607(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(38,0,6)))){
C_save_and_reclaim_args((void *)trf_607,2,t0,t1);}
a=C_alloc(38);
t2=C_mutate((C_word*)lf[5]+1 /* (set! chicken.pathname#absolute-pathname? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_609,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate(&lf[8] /* (set! chicken.pathname#chop-pds ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_622,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t4=C_set_block_item(lf[12] /* chicken.pathname#make-pathname */,0,C_SCHEME_UNDEFINED);
t5=C_set_block_item(lf[13] /* chicken.pathname#make-absolute-pathname */,0,C_SCHEME_UNDEFINED);
t6=(C_truep(*((C_word*)lf[10]+1))?lf[14]:lf[15]);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_690,a[2]=t6,a[3]=((C_word)li4),tmp=(C_word)a,a+=4,tmp));
t14=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_741,a[2]=t8,a[3]=((C_word)li5),tmp=(C_word)a,a+=4,tmp));
t15=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_772,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[12]+1 /* (set! chicken.pathname#make-pathname ...) */,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_860,a[2]=t12,a[3]=t10,a[4]=((C_word)li7),tmp=(C_word)a,a+=5,tmp));
t17=C_mutate((C_word*)lf[13]+1 /* (set! chicken.pathname#make-absolute-pathname ...) */,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_879,a[2]=t12,a[3]=t6,a[4]=t10,a[5]=((C_word)li8),tmp=(C_word)a,a+=6,tmp));
t18=(C_truep(*((C_word*)lf[10]+1))?lf[27]:lf[28]);
t19=(C_truep(*((C_word*)lf[10]+1))?lf[29]:lf[30]);
t20=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_915,a[2]=((C_word*)t0)[2],a[3]=t19,tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:162: chicken.irregex#irregex */
t21=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t21;
av2[1]=t20;
av2[2]=t18;
((C_proc)(void*)(*((C_word*)t21+1)))(3,av2);}}

/* chicken.pathname#absolute-pathname? in k605 in k599 in k596 in k593 */
static void C_ccall f_609(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_609,c,av);}
a=C_alloc(3);
t3=C_i_check_string_2(t2,lf[6]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_620,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:82: absolute-pathname-root */
{C_proc tp=(C_proc)C_fast_retrieve_proc(lf[2]);
C_word *av2=av;
av2[0]=lf[2];
av2[1]=t4;
av2[2]=t2;
tp(3,av2);}}

/* k618 in chicken.pathname#absolute-pathname? in k605 in k599 in k596 in k593 */
static void C_ccall f_620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_620,c,av);}
/* pathname.scm:82: chicken.irregex#irregex-match-data? */
t2=*((C_word*)lf[7]+1);{
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

/* chicken.pathname#chop-pds in k605 in k599 in k596 in k593 */
static void C_fcall f_622(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_622,2,t1,t2);}
a=C_alloc(7);
if(C_truep(t2)){
t3=C_block_size(t2);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_635,a[2]=t5,a[3]=t2,a[4]=((C_word)li1),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_635(t7,t1,t3);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* lp in chicken.pathname#chop-pds in k605 in k599 in k596 in k593 */
static void C_fcall f_635(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_635,3,t0,t1,t2);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_642,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(t2,C_fix(1)))){
t4=C_fixnum_difference(t2,C_fix(1));
t5=C_subchar(((C_word*)t0)[3],t4);
t6=t3;
f_642(t6,(C_truep(*((C_word*)lf[10]+1))?C_u_i_memq(t5,lf[11]):C_eqp(C_make_character(47),t5)));}
else{
t4=t3;
f_642(t4,C_SCHEME_FALSE);}}

/* k640 in lp in chicken.pathname#chop-pds in k605 in k599 in k596 in k593 */
static void C_fcall f_642(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_642,2,t0,t1);}
if(C_truep(t1)){
/* pathname.scm:94: lp */
t2=((C_word*)((C_word*)t0)[2])[1];
f_635(t2,((C_word*)t0)[3],C_fixnum_difference(((C_word*)t0)[4],C_fix(1)));}
else{
t2=C_block_size(((C_word*)t0)[5]);
if(C_truep(C_fixnum_lessp(((C_word*)t0)[4],t2))){
/* pathname.scm:96: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(0);
av2[4]=((C_word*)t0)[4];
tp(5,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t3;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}

/* conc-dirs in k605 in k599 in k596 in k593 */
static void C_fcall f_690(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_690,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_i_check_list_2(t2,lf[16]);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_699,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=((C_word)li3),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_699(t7,t1,t2);}

/* loop in conc-dirs in k605 in k599 in k596 in k593 */
static void C_fcall f_699(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_699,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[17];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_i_string_length(t3);
t5=C_eqp(t4,C_fix(0));
if(C_truep(t5)){
/* pathname.scm:111: loop */
t8=t1;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_727,a[2]=t1,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[2],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* pathname.scm:113: chop-pds */
f_622(t6,C_u_i_car(t2));}}}

/* k725 in loop in conc-dirs in k605 in k599 in k596 in k593 */
static void C_ccall f_727(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_727,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_731,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:115: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_699(t3,t2,C_u_i_cdr(((C_word*)t0)[5]));}

/* k729 in k725 in loop in conc-dirs in k605 in k599 in k596 in k593 */
static void C_ccall f_731(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_731,c,av);}
/* pathname.scm:112: scheme#string-append */
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
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* canonicalize-dirs in k605 in k599 in k596 in k593 */
static void C_fcall f_741(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,2)))){
C_save_and_reclaim_args((void *)trf_741,3,t0,t1,t2);}
a=C_alloc(3);
t3=C_i_not(t2);
t4=(C_truep(t3)?t3:C_i_nullp(t2));
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=lf[19];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
if(C_truep(C_i_stringp(t2))){
t5=C_a_i_list1(&a,1,t2);
/* pathname.scm:119: conc-dirs */
t6=((C_word*)((C_word*)t0)[2])[1];
f_690(t6,t1,t5);}
else{
/* pathname.scm:120: conc-dirs */
t5=((C_word*)((C_word*)t0)[2])[1];
f_690(t5,t1,t2);}}}

/* _make-pathname in k605 in k599 in k596 in k593 */
static void C_fcall f_772(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_772,5,t1,t2,t3,t4,t5);}
a=C_alloc(9);
t6=(C_truep(t5)?t5:lf[20]);
t7=(C_truep(t4)?t4:lf[21]);
t8=C_i_check_string_2(t3,t2);
t9=C_i_check_string_2(t7,t2);
t10=C_i_check_string_2(t6,t2);
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_795,a[2]=t6,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_820,a[2]=t11,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
t13=C_block_size(t3);
if(C_truep(C_fixnum_greater_or_equal_p(t13,C_fix(1)))){
t14=C_block_size(t7);
if(C_truep(C_fixnum_greater_or_equal_p(t14,C_fix(1)))){
t15=C_subchar(t7,C_fix(0));
t16=t12;
f_820(t16,(C_truep(*((C_word*)lf[10]+1))?C_u_i_memq(t15,lf[24]):C_eqp(C_make_character(47),t15)));}
else{
t15=t12;
f_820(t15,C_SCHEME_FALSE);}}
else{
t14=t12;
f_820(t14,C_SCHEME_FALSE);}}

/* k793 in _make-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_795(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_795,c,av);}
t2=C_block_size(((C_word*)t0)[2]);
t3=C_fixnum_greaterp(t2,C_fix(0));
t4=(C_truep(t3)?C_i_not(C_i_char_equalp(C_subchar(((C_word*)t0)[2],C_fix(0)),C_make_character(46))):C_SCHEME_FALSE);
if(C_truep(t4)){
/* pathname.scm:128: scheme#string-append */
t5=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=lf[22];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
/* pathname.scm:128: scheme#string-append */
t5=*((C_word*)lf[18]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=lf[23];
av2[5]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}

/* k818 in _make-pathname in k605 in k599 in k596 in k593 */
static void C_fcall f_820(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_820,2,t0,t1);}
if(C_truep(t1)){
/* pathname.scm:133: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word av2[5];
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(1);
av2[4]=C_block_size(((C_word*)t0)[3]);
tp(5,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word av2[2];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
f_795(2,av2);}}}

/* chicken.pathname#make-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_860(C_word c,C_word *av){
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
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_860,c,av);}
a=C_alloc(6);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_871,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* pathname.scm:143: canonicalize-dirs */
t7=((C_word*)((C_word*)t0)[3])[1];
f_741(t7,t6,t2);}

/* k869 in chicken.pathname#make-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_871(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_871,c,av);}
/* pathname.scm:143: _make-pathname */
f_772(((C_word*)t0)[3],lf[16],t1,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* chicken.pathname#make-absolute-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_879(C_word c,C_word *av){
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
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_879,c,av);}
a=C_alloc(7);
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_get_rest_arg(c,4,av,4,t0));
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_890,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t5,a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
/* pathname.scm:149: canonicalize-dirs */
t7=((C_word*)((C_word*)t0)[4])[1];
f_741(t7,t6,t2);}

/* k888 in chicken.pathname#make-absolute-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_890,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_893,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_896,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t2,a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
/* pathname.scm:150: absolute-pathname? */
t4=*((C_word*)lf[5]+1);{
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

/* k891 in k888 in chicken.pathname#make-absolute-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_893(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_893,c,av);}
/* pathname.scm:147: _make-pathname */
f_772(((C_word*)t0)[3],lf[25],t1,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k894 in k888 in chicken.pathname#make-absolute-pathname in k605 in k599 in k596 in k593 */
static void C_ccall f_896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_896,c,av);}
if(C_truep(t1)){
/* pathname.scm:147: _make-pathname */
f_772(((C_word*)t0)[3],lf[25],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6]);}
else{
/* pathname.scm:152: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[26]+1);
av2[1]=((C_word*)t0)[7];
av2[2]=((C_word*)t0)[8];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}}

/* k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_915(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_915,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_918,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:163: chicken.irregex#irregex */
t3=*((C_word*)lf[72]+1);{
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

/* k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_918(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(36,c,4)))){
C_save_and_reclaim((void *)f_918,c,av);}
a=C_alloc(36);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_919,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp);
t3=C_mutate((C_word*)lf[31]+1 /* (set! chicken.pathname#decompose-pathname ...) */,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_940,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word)li10),tmp=(C_word)a,a+=6,tmp));
t4=C_mutate((C_word*)lf[35]+1 /* (set! chicken.pathname#pathname-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1012,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[36]+1 /* (set! chicken.pathname#pathname-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1027,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[37]+1 /* (set! chicken.pathname#pathname-extension ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1042,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t7=C_mutate((C_word*)lf[38]+1 /* (set! chicken.pathname#pathname-strip-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1057,a[2]=((C_word)li22),tmp=(C_word)a,a+=3,tmp));
t8=C_mutate((C_word*)lf[39]+1 /* (set! chicken.pathname#pathname-strip-extension ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1075,a[2]=((C_word)li25),tmp=(C_word)a,a+=3,tmp));
t9=C_mutate((C_word*)lf[40]+1 /* (set! chicken.pathname#pathname-replace-directory ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1093,a[2]=((C_word)li28),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[41]+1 /* (set! chicken.pathname#pathname-replace-file ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1111,a[2]=((C_word)li31),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[42]+1 /* (set! chicken.pathname#pathname-replace-extension ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1129,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp));
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1593,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:232: chicken.platform#software-version */
t13=*((C_word*)lf[71]+1);{
C_word *av2=av;
av2[0]=t13;
av2[1]=t12;
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}

/* strip-pds in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_fcall f_919(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_919,2,t1,t2);}
a=C_alloc(4);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_926,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:167: chop-pds */
f_622(t3,t2);}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k924 in strip-pds in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_926(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_926,c,av);}
t2=C_block_size(t1);
if(C_truep(C_fixnum_greaterp(t2,C_fix(0)))){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* pathname.scm:170: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[9]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[9]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(0);
av2[4]=C_fix(1);
tp(5,av2);}}}

/* chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_940(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_940,c,av);}
a=C_alloc(6);
t3=C_i_check_string_2(t2,lf[32]);
t4=C_block_size(t2);
t5=C_eqp(C_fix(0),t4);
if(C_truep(t5)){
/* pathname.scm:174: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=t1;
av2[2]=C_SCHEME_FALSE;
av2[3]=C_SCHEME_FALSE;
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_956,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* pathname.scm:175: chicken.irregex#irregex-search */
t7=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[4];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}

/* k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_956(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_956,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_966,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_978,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:178: chicken.irregex#irregex-match-substring */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_981,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:181: chicken.irregex#irregex-search */
t3=*((C_word*)lf[34]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}}

/* k964 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_966(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_966,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_970,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:179: chicken.irregex#irregex-match-substring */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k968 in k964 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_970(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_970,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_974,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* pathname.scm:180: chicken.irregex#irregex-match-substring */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(4);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k972 in k968 in k964 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_974(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_974,c,av);}
/* pathname.scm:177: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=t1;
C_values(5,av2);}}

/* k976 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_978(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_978,c,av);}
/* pathname.scm:178: strip-pds */
f_919(((C_word*)t0)[3],t1);}

/* k979 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_981(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_981,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_991,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_999,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:184: chicken.irregex#irregex-match-substring */
t4=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
av2[3]=C_fix(1);
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1006,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* pathname.scm:187: strip-pds */
f_919(t2,((C_word*)t0)[4]);}}

/* k989 in k979 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_991(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_991,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_995,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* pathname.scm:185: chicken.irregex#irregex-match-substring */
t3=*((C_word*)lf[33]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(2);
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k993 in k989 in k979 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_995,c,av);}
/* pathname.scm:183: scheme#values */{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_SCHEME_FALSE;
C_values(5,av2);}}

/* k997 in k979 in k954 in chicken.pathname#decompose-pathname in k916 in k913 in k605 in k599 in k596 in k593 */
static void C_ccall f_999(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_999,c,av);}
/* pathname.scm:184: strip-pds */
f_919(((C_word*)t0)[3],t1);}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_pathname_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("pathname"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_pathname_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(340))){
C_save(t1);
C_rereclaim2(340*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,76);
lf[0]=C_h_intern(&lf[0],8, C_text("pathname"));
lf[1]=C_h_intern(&lf[1],17, C_text("chicken.pathname#"));
lf[5]=C_h_intern(&lf[5],35, C_text("chicken.pathname#absolute-pathname\077"));
lf[6]=C_h_intern(&lf[6],18, C_text("absolute-pathname\077"));
lf[7]=C_h_intern(&lf[7],35, C_text("chicken.irregex#irregex-match-data\077"));
lf[9]=C_h_intern(&lf[9],15, C_text("##sys#substring"));
lf[10]=C_h_intern(&lf[10],22, C_text("##sys#windows-platform"));
lf[11]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000\134\376\003\000\000\002\376\377\012\000\000/\376\377\016"));
lf[12]=C_h_intern(&lf[12],30, C_text("chicken.pathname#make-pathname"));
lf[13]=C_h_intern(&lf[13],39, C_text("chicken.pathname#make-absolute-pathname"));
lf[14]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\134"));
lf[15]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[16]=C_h_intern(&lf[16],13, C_text("make-pathname"));
lf[17]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[18]=C_h_intern(&lf[18],20, C_text("scheme#string-append"));
lf[19]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[20]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[21]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[22]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[23]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[24]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000\134\376\003\000\000\002\376\377\012\000\000/\376\377\016"));
lf[25]=C_h_intern(&lf[25],22, C_text("make-absolute-pathname"));
lf[26]=C_h_intern(&lf[26],19, C_text("##sys#string-append"));
lf[27]=C_decode_literal(C_heaptop,C_text("\376B\000\000&^(.\052[\134/\134\134])\077([^\134/\134\134]+)(\134.([^\134/\134\134.]+))$"));
lf[28]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033^(.\052/)\077([^/]+)(\134.([^/.]+))$"));
lf[29]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034^(.\052[\134/\134\134])\077((\134.)\077[^\134/\134\134]+)$"));
lf[30]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024^(.\052/)\077((\134.)\077[^/]+)$"));
lf[31]=C_h_intern(&lf[31],35, C_text("chicken.pathname#decompose-pathname"));
lf[32]=C_h_intern(&lf[32],18, C_text("decompose-pathname"));
lf[33]=C_h_intern(&lf[33],39, C_text("chicken.irregex#irregex-match-substring"));
lf[34]=C_h_intern(&lf[34],30, C_text("chicken.irregex#irregex-search"));
lf[35]=C_h_intern(&lf[35],35, C_text("chicken.pathname#pathname-directory"));
lf[36]=C_h_intern(&lf[36],30, C_text("chicken.pathname#pathname-file"));
lf[37]=C_h_intern(&lf[37],35, C_text("chicken.pathname#pathname-extension"));
lf[38]=C_h_intern(&lf[38],41, C_text("chicken.pathname#pathname-strip-directory"));
lf[39]=C_h_intern(&lf[39],41, C_text("chicken.pathname#pathname-strip-extension"));
lf[40]=C_h_intern(&lf[40],43, C_text("chicken.pathname#pathname-replace-directory"));
lf[41]=C_h_intern(&lf[41],38, C_text("chicken.pathname#pathname-replace-file"));
lf[42]=C_h_intern(&lf[42],43, C_text("chicken.pathname#pathname-replace-extension"));
lf[43]=C_h_intern(&lf[43],7, C_text("mingw32"));
lf[44]=C_h_intern(&lf[44],7, C_text("windows"));
lf[45]=C_h_intern(&lf[45],4, C_text("unix"));
lf[46]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[47]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002.."));
lf[48]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002.."));
lf[49]=C_h_intern(&lf[49],35, C_text("chicken.pathname#normalize-pathname"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\377\012\000\000/\376\003\000\000\002\376\377\012\000\000\134\376\377\016"));
lf[51]=C_h_intern(&lf[51],18, C_text("normalize-pathname"));
lf[52]=C_h_intern(&lf[52],3, C_text("abs"));
lf[53]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[54]=C_h_intern(&lf[54],14, C_text("scheme#display"));
lf[55]=C_h_intern(&lf[55],18, C_text("##sys#write-char-0"));
lf[56]=C_h_intern(&lf[56],8, C_text("for-each"));
lf[57]=C_h_intern(&lf[57],30, C_text("chicken.base#get-output-string"));
lf[58]=C_h_intern(&lf[58],18, C_text("##sys#fast-reverse"));
lf[59]=C_h_intern(&lf[59],31, C_text("chicken.base#open-output-string"));
lf[60]=C_h_intern(&lf[60],3, C_text("rel"));
lf[62]=C_h_intern(&lf[62],27, C_text("chicken.string#string-split"));
lf[63]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002/\134"));
lf[64]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001/"));
lf[65]=C_h_intern(&lf[65],32, C_text("chicken.pathname#directory-null\077"));
lf[66]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[67]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001."));
lf[68]=C_h_intern(&lf[68],15, C_text("directory-null\077"));
lf[69]=C_h_intern(&lf[69],36, C_text("chicken.pathname#decompose-directory"));
lf[70]=C_h_intern(&lf[70],19, C_text("decompose-directory"));
lf[71]=C_h_intern(&lf[71],33, C_text("chicken.platform#software-version"));
lf[72]=C_h_intern(&lf[72],23, C_text("chicken.irregex#irregex"));
lf[73]=C_h_intern(&lf[73],29, C_text("chicken.irregex#irregex-match"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026([A-Za-z]:)\077([\134/\134\134]).\052"));
lf[75]=C_decode_literal(C_heaptop,C_text("\376B\000\000\005(/).\052"));
C_register_lf2(lf,76,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_595,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[106] = {
{C_text("f_1006:pathname_2escm"),(void*)f_1006},
{C_text("f_1012:pathname_2escm"),(void*)f_1012},
{C_text("f_1018:pathname_2escm"),(void*)f_1018},
{C_text("f_1024:pathname_2escm"),(void*)f_1024},
{C_text("f_1027:pathname_2escm"),(void*)f_1027},
{C_text("f_1033:pathname_2escm"),(void*)f_1033},
{C_text("f_1039:pathname_2escm"),(void*)f_1039},
{C_text("f_1042:pathname_2escm"),(void*)f_1042},
{C_text("f_1048:pathname_2escm"),(void*)f_1048},
{C_text("f_1054:pathname_2escm"),(void*)f_1054},
{C_text("f_1057:pathname_2escm"),(void*)f_1057},
{C_text("f_1063:pathname_2escm"),(void*)f_1063},
{C_text("f_1069:pathname_2escm"),(void*)f_1069},
{C_text("f_1075:pathname_2escm"),(void*)f_1075},
{C_text("f_1081:pathname_2escm"),(void*)f_1081},
{C_text("f_1087:pathname_2escm"),(void*)f_1087},
{C_text("f_1093:pathname_2escm"),(void*)f_1093},
{C_text("f_1099:pathname_2escm"),(void*)f_1099},
{C_text("f_1105:pathname_2escm"),(void*)f_1105},
{C_text("f_1111:pathname_2escm"),(void*)f_1111},
{C_text("f_1117:pathname_2escm"),(void*)f_1117},
{C_text("f_1123:pathname_2escm"),(void*)f_1123},
{C_text("f_1129:pathname_2escm"),(void*)f_1129},
{C_text("f_1135:pathname_2escm"),(void*)f_1135},
{C_text("f_1141:pathname_2escm"),(void*)f_1141},
{C_text("f_1151:pathname_2escm"),(void*)f_1151},
{C_text("f_1189:pathname_2escm"),(void*)f_1189},
{C_text("f_1198:pathname_2escm"),(void*)f_1198},
{C_text("f_1221:pathname_2escm"),(void*)f_1221},
{C_text("f_1231:pathname_2escm"),(void*)f_1231},
{C_text("f_1255:pathname_2escm"),(void*)f_1255},
{C_text("f_1258:pathname_2escm"),(void*)f_1258},
{C_text("f_1261:pathname_2escm"),(void*)f_1261},
{C_text("f_1262:pathname_2escm"),(void*)f_1262},
{C_text("f_1266:pathname_2escm"),(void*)f_1266},
{C_text("f_1276:pathname_2escm"),(void*)f_1276},
{C_text("f_1279:pathname_2escm"),(void*)f_1279},
{C_text("f_1282:pathname_2escm"),(void*)f_1282},
{C_text("f_1285:pathname_2escm"),(void*)f_1285},
{C_text("f_1292:pathname_2escm"),(void*)f_1292},
{C_text("f_1299:pathname_2escm"),(void*)f_1299},
{C_text("f_1311:pathname_2escm"),(void*)f_1311},
{C_text("f_1321:pathname_2escm"),(void*)f_1321},
{C_text("f_1347:pathname_2escm"),(void*)f_1347},
{C_text("f_1356:pathname_2escm"),(void*)f_1356},
{C_text("f_1392:pathname_2escm"),(void*)f_1392},
{C_text("f_1408:pathname_2escm"),(void*)f_1408},
{C_text("f_1412:pathname_2escm"),(void*)f_1412},
{C_text("f_1462:pathname_2escm"),(void*)f_1462},
{C_text("f_1475:pathname_2escm"),(void*)f_1475},
{C_text("f_1483:pathname_2escm"),(void*)f_1483},
{C_text("f_1485:pathname_2escm"),(void*)f_1485},
{C_text("f_1515:pathname_2escm"),(void*)f_1515},
{C_text("f_1554:pathname_2escm"),(void*)f_1554},
{C_text("f_1558:pathname_2escm"),(void*)f_1558},
{C_text("f_1561:pathname_2escm"),(void*)f_1561},
{C_text("f_1564:pathname_2escm"),(void*)f_1564},
{C_text("f_1571:pathname_2escm"),(void*)f_1571},
{C_text("f_1593:pathname_2escm"),(void*)f_1593},
{C_text("f_1596:pathname_2escm"),(void*)f_1596},
{C_text("f_1598:pathname_2escm"),(void*)f_1598},
{C_text("f_1604:pathname_2escm"),(void*)f_1604},
{C_text("f_1613:pathname_2escm"),(void*)f_1613},
{C_text("f_1623:pathname_2escm"),(void*)f_1623},
{C_text("f_1625:pathname_2escm"),(void*)f_1625},
{C_text("f_1631:pathname_2escm"),(void*)f_1631},
{C_text("f_1634:pathname_2escm"),(void*)f_1634},
{C_text("f_595:pathname_2escm"),(void*)f_595},
{C_text("f_598:pathname_2escm"),(void*)f_598},
{C_text("f_601:pathname_2escm"),(void*)f_601},
{C_text("f_607:pathname_2escm"),(void*)f_607},
{C_text("f_609:pathname_2escm"),(void*)f_609},
{C_text("f_620:pathname_2escm"),(void*)f_620},
{C_text("f_622:pathname_2escm"),(void*)f_622},
{C_text("f_635:pathname_2escm"),(void*)f_635},
{C_text("f_642:pathname_2escm"),(void*)f_642},
{C_text("f_690:pathname_2escm"),(void*)f_690},
{C_text("f_699:pathname_2escm"),(void*)f_699},
{C_text("f_727:pathname_2escm"),(void*)f_727},
{C_text("f_731:pathname_2escm"),(void*)f_731},
{C_text("f_741:pathname_2escm"),(void*)f_741},
{C_text("f_772:pathname_2escm"),(void*)f_772},
{C_text("f_795:pathname_2escm"),(void*)f_795},
{C_text("f_820:pathname_2escm"),(void*)f_820},
{C_text("f_860:pathname_2escm"),(void*)f_860},
{C_text("f_871:pathname_2escm"),(void*)f_871},
{C_text("f_879:pathname_2escm"),(void*)f_879},
{C_text("f_890:pathname_2escm"),(void*)f_890},
{C_text("f_893:pathname_2escm"),(void*)f_893},
{C_text("f_896:pathname_2escm"),(void*)f_896},
{C_text("f_915:pathname_2escm"),(void*)f_915},
{C_text("f_918:pathname_2escm"),(void*)f_918},
{C_text("f_919:pathname_2escm"),(void*)f_919},
{C_text("f_926:pathname_2escm"),(void*)f_926},
{C_text("f_940:pathname_2escm"),(void*)f_940},
{C_text("f_956:pathname_2escm"),(void*)f_956},
{C_text("f_966:pathname_2escm"),(void*)f_966},
{C_text("f_970:pathname_2escm"),(void*)f_970},
{C_text("f_974:pathname_2escm"),(void*)f_974},
{C_text("f_978:pathname_2escm"),(void*)f_978},
{C_text("f_981:pathname_2escm"),(void*)f_981},
{C_text("f_991:pathname_2escm"),(void*)f_991},
{C_text("f_995:pathname_2escm"),(void*)f_995},
{C_text("f_999:pathname_2escm"),(void*)f_999},
{C_text("toplevel:pathname_2escm"),(void*)C_pathname_toplevel},
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
o|hiding unexported module binding: chicken.pathname#d 
o|hiding unexported module binding: chicken.pathname#define-alias 
o|hiding unexported module binding: chicken.pathname#absolute-pathname-root 
o|hiding unexported module binding: chicken.pathname#root-origin 
o|hiding unexported module binding: chicken.pathname#root-directory 
o|hiding unexported module binding: chicken.pathname#chop-pds 
o|hiding unexported module binding: chicken.pathname#split-directory 
S|applied compiler syntax:
S|  scheme#for-each		1
o|eliminated procedure checks: 10 
o|specializations:
o|  1 (scheme#char=? char char)
o|  1 (scheme#string-ref string fixnum)
o|  1 (scheme#string=? string string)
o|  1 (scheme#car pair)
o|  5 (scheme#cdr pair)
o|  1 (scheme#zero? integer)
o|  3 (scheme#memq * list)
(o e)|safe calls: 158 
o|safe globals: (chicken.pathname#root-directory chicken.pathname#root-origin chicken.pathname#absolute-pathname-root) 
o|inlining procedure: k624 
o|inlining procedure: k637 
o|inlining procedure: k637 
o|contracted procedure: "(pathname.scm:93) g140141" 
o|inlining procedure: k668 
o|substituted constant variable: a672 
o|inlining procedure: k668 
o|inlining procedure: k624 
o|inlining procedure: k701 
o|inlining procedure: k701 
o|inlining procedure: k743 
o|inlining procedure: k743 
o|inlining procedure: k797 
o|inlining procedure: k797 
o|inlining procedure: k831 
o|contracted procedure: "(pathname.scm:132) g178179" 
o|inlining procedure: k839 
o|substituted constant variable: a843 
o|inlining procedure: k839 
o|inlining procedure: k831 
o|inlining procedure: k891 
o|inlining procedure: k891 
o|inlining procedure: k921 
o|inlining procedure: k921 
o|inlining procedure: k945 
o|inlining procedure: k945 
o|inlining procedure: k982 
o|inlining procedure: k982 
o|inlining procedure: k1153 
o|inlining procedure: k1153 
o|substituted constant variable: a1162 
o|inlining procedure: k1164 
o|inlining procedure: k1164 
o|inlining procedure: k1200 
o|substituted constant variable: a1207 
o|inlining procedure: k1200 
o|inlining procedure: k1223 
o|inlining procedure: k1241 
o|inlining procedure: k1241 
o|inlining procedure: k1286 
o|inlining procedure: k1286 
o|inlining procedure: k1313 
o|inlining procedure: k1313 
o|inlining procedure: k1223 
o|inlining procedure: k1357 
o|inlining procedure: k1357 
o|inlining procedure: k1397 
o|inlining procedure: k1397 
o|inlining procedure: k1403 
o|inlining procedure: k1403 
o|substituted constant variable: a1444 
o|inlining procedure: k1438 
o|inlining procedure: k1438 
o|inlining procedure: k1471 
o|inlining procedure: k1471 
o|inlining procedure: k1490 
o|inlining procedure: k1490 
o|contracted procedure: "(pathname.scm:329) strip-origin-prefix432" 
o|inlining procedure: k1520 
o|inlining procedure: k1520 
o|inlining procedure: k1542 
o|inlining procedure: k1542 
o|inlining procedure: k1606 
o|inlining procedure: k1606 
o|inlining procedure: k1615 
o|inlining procedure: k1615 
o|inlining procedure: k1636 
o|inlining procedure: k1636 
o|replaced variables: 282 
o|removed binding forms: 79 
o|substituted constant variable: r6251647 
o|substituted constant variable: r7021648 
o|substituted constant variable: r7441650 
o|substituted constant variable: r7981652 
o|substituted constant variable: r7981652 
o|substituted constant variable: r7981654 
o|substituted constant variable: r7981654 
o|substituted constant variable: r8321659 
o|substituted constant variable: r9221665 
o|substituted constant variable: r13981688 
o|substituted constant variable: r13981690 
o|substituted constant variable: r14391695 
o|converted assignments to bindings: (pds?366) 
o|substituted constant variable: r14721696 
o|substituted constant variable: r14721696 
o|substituted constant variable: r14721698 
o|substituted constant variable: r14721698 
o|converted assignments to bindings: (addpart344) 
o|substituted constant variable: r16071707 
o|substituted constant variable: r16161709 
o|substituted constant variable: r16371711 
o|simplifications: ((let . 2)) 
o|replaced variables: 26 
o|removed binding forms: 237 
o|inlining procedure: k1238 
o|inlining procedure: k1573 
o|inlining procedure: k1573 
o|inlining procedure: k1573 
o|removed binding forms: 35 
o|replaced variables: 3 
o|removed binding forms: 1 
o|removed binding forms: 3 
o|simplifications: ((if . 17) (let . 9) (##core#call . 111)) 
o|  call simplifications:
o|    scheme#list?
o|    scheme#member
o|    scheme#string-ref
o|    chicken.fixnum#fx+	8
o|    scheme#pair?
o|    ##sys#slot	2
o|    scheme#string	2
o|    scheme#string=?	2
o|    scheme#cdr
o|    scheme#cons	3
o|    ##sys#call-with-values	8
o|    chicken.fixnum#fx=	5
o|    scheme#values	8
o|    chicken.fixnum#fx>	3
o|    scheme#char=?
o|    scheme#not	6
o|    scheme#string?
o|    scheme#list
o|    ##sys#check-list	2
o|    scheme#null?	10
o|    scheme#car	8
o|    scheme#string-length
o|    chicken.fixnum#fx>=	4
o|    scheme#eq?	10
o|    ##sys#size	11
o|    chicken.fixnum#fx<
o|    chicken.fixnum#fx-	2
o|    ##sys#check-string	7
o|contracted procedure: k611 
o|contracted procedure: k631 
o|contracted procedure: k647 
o|contracted procedure: k660 
o|contracted procedure: k653 
o|contracted procedure: k663 
o|contracted procedure: k681 
o|contracted procedure: k686 
o|contracted procedure: k692 
o|contracted procedure: k704 
o|contracted procedure: k707 
o|contracted procedure: k737 
o|contracted procedure: k713 
o|contracted procedure: k746 
o|contracted procedure: k749 
o|contracted procedure: k755 
o|contracted procedure: k762 
o|contracted procedure: k774 
o|contracted procedure: k777 
o|contracted procedure: k780 
o|contracted procedure: k783 
o|contracted procedure: k786 
o|contracted procedure: k815 
o|contracted procedure: k803 
o|contracted procedure: k810 
o|contracted procedure: k825 
o|contracted procedure: k856 
o|contracted procedure: k828 
o|contracted procedure: k852 
o|contracted procedure: k834 
o|contracted procedure: k872 
o|contracted procedure: k862 
o|contracted procedure: k900 
o|contracted procedure: k881 
o|contracted procedure: k907 
o|contracted procedure: k910 
o|contracted procedure: k937 
o|contracted procedure: k930 
o|contracted procedure: k942 
o|contracted procedure: k1008 
o|contracted procedure: k948 
o|contracted procedure: k1587 
o|contracted procedure: k1147 
o|contracted procedure: k1156 
o|contracted procedure: k1167 
o|inlining procedure: k1170 
o|contracted procedure: k1183 
o|inlining procedure: k1170 
o|contracted procedure: k1455 
o|contracted procedure: k1191 
o|contracted procedure: k1452 
o|contracted procedure: k1194 
o|contracted procedure: k1203 
o|contracted procedure: k1211 
o|contracted procedure: k1214 
o|contracted procedure: k1226 
o|contracted procedure: k1235 
o|contracted procedure: k1247 
o|contracted procedure: k1238 
o|contracted procedure: k1271 
o|contracted procedure: k1293 
o|contracted procedure: k1301 
o|contracted procedure: k1304 
o|contracted procedure: k1316 
o|contracted procedure: k1326 
o|contracted procedure: k1330 
o|contracted procedure: k1334 
o|contracted procedure: k1337 
o|contracted procedure: k1360 
o|contracted procedure: k1367 
o|contracted procedure: k1371 
o|contracted procedure: k1378 
o|contracted procedure: k1382 
o|contracted procedure: k1393 
o|contracted procedure: k1400 
o|contracted procedure: k1417 
o|contracted procedure: k1421 
o|contracted procedure: k1425 
o|contracted procedure: k1432 
o|contracted procedure: k1435 
o|contracted procedure: k1449 
o|contracted procedure: k1464 
o|contracted procedure: k1487 
o|contracted procedure: k1505 
o|contracted procedure: k1496 
o|contracted procedure: k1508 
o|contracted procedure: k1584 
o|contracted procedure: k1580 
o|contracted procedure: k1577 
o|contracted procedure: k1523 
o|contracted procedure: k1526 
o|contracted procedure: k1529 
o|contracted procedure: k1535 
o|contracted procedure: k1539 
o|contracted procedure: k1545 
o|contracted procedure: k1573 
o|simplifications: ((if . 2) (let . 31)) 
o|removed binding forms: 94 
o|contracted procedure: k800 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest188191 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest188191 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest200203 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest200203 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest357359 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest357359 0 
o|replaced variables: 3 
o|removed binding forms: 2 
o|removed binding forms: 2 
o|direct leaf routine/allocation: addpart344 9 
o|direct leaf routine/allocation: pds?366 0 
o|direct leaf routine/allocation: loop423 0 
o|contracted procedure: "(pathname.scm:254) k1341" 
o|contracted procedure: "(pathname.scm:273) k1351" 
o|contracted procedure: "(pathname.scm:280) k1386" 
o|converted assignments to bindings: (loop423) 
o|simplifications: ((let . 1)) 
o|removed binding forms: 3 
o|customizable procedures: (k605 chicken.pathname#split-directory k1406 k1354 loop371 k1229 g385392 for-each-loop384396 k1283 strip-pds219 canonicalize-dirs148 _make-pathname149 k818 conc-dirs147 chicken.pathname#chop-pds loop151 k640 lp133) 
o|calls to known targets: 46 
o|identified direct recursive calls: f_699 1 
o|unused rest argument: rest188191 f_860 
o|unused rest argument: rest200203 f_879 
o|unused rest argument: rest357359 f_1189 
o|identified direct recursive calls: f_1485 1 
o|fast box initializations: 7 
o|fast global references: 8 
o|fast global assignments: 11 
o|dropping unused closure argument: f_1151 
o|dropping unused closure argument: f_1462 
o|dropping unused closure argument: f_1485 
o|dropping unused closure argument: f_622 
o|dropping unused closure argument: f_772 
o|dropping unused closure argument: f_919 
*/
/* end of file */
