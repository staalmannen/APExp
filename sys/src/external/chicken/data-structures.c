/* Generated from data-structures.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: data-structures.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file data-structures.c -emit-import-library chicken.sort -emit-import-library chicken.string
   unit: data-structures
   uses: library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[85];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,8),40,108,111,111,112,32,107,41};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,23),40,114,101,118,45,115,116,114,105,110,103,45,97,112,112,101,110,100,32,108,32,105,41,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,114,101,118,101,114,115,101,45,115,116,114,105,110,103,45,97,112,112,101,110,100,32,108,41};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,39),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,114,101,118,101,114,115,101,45,108,105,115,116,45,62,115,116,114,105,110,103,32,108,41,0};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,27),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,45,62,115,116,114,105,110,103,32,120,41,0,0,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,16),40,109,97,112,45,108,111,111,112,56,48,32,103,57,50,41};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,28),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,99,111,110,99,32,46,32,97,114,103,115,41,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,13),40,108,111,111,112,32,105,115,116,97,114,116,41,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,37),40,116,114,97,118,101,114,115,101,32,119,104,105,99,104,32,119,104,101,114,101,32,115,116,97,114,116,32,116,101,115,116,32,108,111,99,41,0,0,0};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,11),40,97,49,49,48,49,32,105,32,108,41,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,41),40,35,35,115,121,115,35,115,117,98,115,116,114,105,110,103,45,105,110,100,101,120,32,119,104,105,99,104,32,119,104,101,114,101,32,115,116,97,114,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,11),40,97,49,49,49,48,32,105,32,108,41,0,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,44),40,35,35,115,121,115,35,115,117,98,115,116,114,105,110,103,45,105,110,100,101,120,45,99,105,32,119,104,105,99,104,32,119,104,101,114,101,32,115,116,97,114,116,41,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,117,98,115,116,114,105,110,103,45,105,110,100,101,120,32,119,104,105,99,104,32,119,104,101,114,101,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,54),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,117,98,115,116,114,105,110,103,45,105,110,100,101,120,45,99,105,32,119,104,105,99,104,32,119,104,101,114,101,32,46,32,114,101,115,116,41,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,38),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,99,111,109,112,97,114,101,51,32,115,49,32,115,50,41,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,99,111,109,112,97,114,101,51,45,99,105,32,115,49,32,115,50,41,0,0,0,0,0,0,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,41),40,35,35,115,121,115,35,115,117,98,115,116,114,105,110,103,61,63,32,115,49,32,115,50,32,115,116,97,114,116,49,32,115,116,97,114,116,50,32,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,41),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,117,98,115,116,114,105,110,103,61,63,32,115,49,32,115,50,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,44),40,35,35,115,121,115,35,115,117,98,115,116,114,105,110,103,45,99,105,61,63,32,115,49,32,115,50,32,115,116,97,114,116,49,32,115,116,97,114,116,50,32,110,41,0,0,0,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,44),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,117,98,115,116,114,105,110,103,45,99,105,61,63,32,115,49,32,115,50,32,46,32,114,101,115,116,41,0,0,0,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,18),40,97,100,100,32,102,114,111,109,32,116,111,32,108,97,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,8),40,115,99,97,110,32,106,41};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,18),40,108,111,111,112,32,105,32,108,97,115,116,32,102,114,111,109,41,0,0,0,0,0,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,115,112,108,105,116,32,115,116,114,32,46,32,100,101,108,115,116,114,45,97,110,100,45,102,108,97,103,41,0,0,0,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,50,32,110,50,41,0,0,0,0,0,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,49,32,115,115,32,110,41,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,105,110,116,101,114,115,112,101,114,115,101,32,115,116,114,115,32,46,32,114,101,115,116,41,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,10),40,102,95,49,54,57,48,32,99,41,0,0,0,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,12),40,105,110,115,116,114,105,110,103,32,115,41,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,105,32,106,41,0,0,0,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,10),40,102,95,49,56,54,50,32,99,41,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,47),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,116,114,97,110,115,108,97,116,101,32,115,116,114,32,102,114,111,109,32,46,32,116,111,41,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,115,109,97,112,41,0,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,25),40,99,111,108,108,101,99,116,32,105,32,102,114,111,109,32,116,111,116,97,108,32,102,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,43),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,116,114,97,110,115,108,97,116,101,42,32,115,116,114,32,115,109,97,112,41,0,0,0,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,116,111,116,97,108,32,112,111,115,41};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,99,104,111,112,32,115,116,114,32,108,101,110,41,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,115,116,114,105,110,103,35,115,116,114,105,110,103,45,99,104,111,109,112,32,115,116,114,32,46,32,114,101,115,116,41};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,52,55,49,32,105,41,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,108,97,115,116,32,110,101,120,116,41};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,32),40,99,104,105,99,107,101,110,46,115,111,114,116,35,115,111,114,116,101,100,63,32,115,101,113,32,108,101,115,115,63,41};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,120,32,97,32,121,32,98,41,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,30),40,99,104,105,99,107,101,110,46,115,111,114,116,35,109,101,114,103,101,32,97,32,98,32,108,101,115,115,63,41,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,114,32,97,32,98,41,0,0,0,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,31),40,99,104,105,99,107,101,110,46,115,111,114,116,35,109,101,114,103,101,33,32,97,32,98,32,108,101,115,115,63,41,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,8),40,115,116,101,112,32,110,41};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,15),40,100,111,108,111,111,112,53,52,50,32,112,32,105,41,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,30),40,99,104,105,99,107,101,110,46,115,111,114,116,35,115,111,114,116,33,32,115,101,113,32,108,101,115,115,63,41,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,29),40,99,104,105,99,107,101,110,46,115,111,114,116,35,115,111,114,116,32,115,101,113,32,108,101,115,115,63,41,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,18),40,119,97,108,107,32,101,100,103,101,115,32,115,116,97,116,101,41,0,0,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,33),40,118,105,115,105,116,32,100,97,103,32,110,111,100,101,32,101,100,103,101,115,32,112,97,116,104,32,115,116,97,116,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,100,97,103,32,115,116,97,116,101,41};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,18),40,103,53,57,50,32,114,101,115,117,108,116,32,110,111,100,101,41,0,0,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,20),40,102,111,108,100,108,53,56,53,32,103,53,56,54,32,103,53,56,52,41,0,0,0,0};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,40),40,99,104,105,99,107,101,110,46,115,111,114,116,35,116,111,112,111,108,111,103,105,99,97,108,45,115,111,114,116,32,100,97,103,32,112,114,101,100,41};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_1013)
static void C_ccall f_1013(C_word c,C_word *av) C_noret;
C_noret_decl(f_1022)
static void C_fcall f_1022(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_1041)
static void C_ccall f_1041(C_word c,C_word *av) C_noret;
C_noret_decl(f_1064)
static void C_fcall f_1064(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1077)
static void C_ccall f_1077(C_word c,C_word *av) C_noret;
C_noret_decl(f_1096)
static void C_ccall f_1096(C_word c,C_word *av) C_noret;
C_noret_decl(f_1102)
static void C_ccall f_1102(C_word c,C_word *av) C_noret;
C_noret_decl(f_1105)
static void C_ccall f_1105(C_word c,C_word *av) C_noret;
C_noret_decl(f_1111)
static void C_ccall f_1111(C_word c,C_word *av) C_noret;
C_noret_decl(f_1114)
static void C_ccall f_1114(C_word c,C_word *av) C_noret;
C_noret_decl(f_1129)
static void C_ccall f_1129(C_word c,C_word *av) C_noret;
C_noret_decl(f_1144)
static void C_ccall f_1144(C_word c,C_word *av) C_noret;
C_noret_decl(f_1175)
static void C_ccall f_1175(C_word c,C_word *av) C_noret;
C_noret_decl(f_1206)
static void C_ccall f_1206(C_word c,C_word *av) C_noret;
C_noret_decl(f_1216)
static void C_ccall f_1216(C_word c,C_word *av) C_noret;
C_noret_decl(f_1219)
static void C_ccall f_1219(C_word c,C_word *av) C_noret;
C_noret_decl(f_1228)
static void C_ccall f_1228(C_word c,C_word *av) C_noret;
C_noret_decl(f_1266)
static void C_ccall f_1266(C_word c,C_word *av) C_noret;
C_noret_decl(f_1326)
static void C_ccall f_1326(C_word c,C_word *av) C_noret;
C_noret_decl(f_1336)
static void C_ccall f_1336(C_word c,C_word *av) C_noret;
C_noret_decl(f_1339)
static void C_ccall f_1339(C_word c,C_word *av) C_noret;
C_noret_decl(f_1348)
static void C_ccall f_1348(C_word c,C_word *av) C_noret;
C_noret_decl(f_1386)
static void C_ccall f_1386(C_word c,C_word *av) C_noret;
C_noret_decl(f_1446)
static void C_ccall f_1446(C_word c,C_word *av) C_noret;
C_noret_decl(f_1467)
static void C_fcall f_1467(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1482)
static void C_ccall f_1482(C_word c,C_word *av) C_noret;
C_noret_decl(f_1487)
static void C_fcall f_1487(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_1497)
static void C_ccall f_1497(C_word c,C_word *av) C_noret;
C_noret_decl(f_1514)
static void C_fcall f_1514(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1553)
static void C_ccall f_1553(C_word c,C_word *av) C_noret;
C_noret_decl(f_1580)
static void C_ccall f_1580(C_word c,C_word *av) C_noret;
C_noret_decl(f_1598)
static void C_fcall f_1598(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1608)
static void C_ccall f_1608(C_word c,C_word *av) C_noret;
C_noret_decl(f_1613)
static C_word C_fcall f_1613(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_1682)
static void C_ccall f_1682(C_word c,C_word *av) C_noret;
C_noret_decl(f_1685)
static void C_fcall f_1685(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1690)
static void C_ccall f_1690(C_word c,C_word *av) C_noret;
C_noret_decl(f_1696)
static C_word C_fcall f_1696(C_word t0,C_word t1);
C_noret_decl(f_1720)
static void C_ccall f_1720(C_word c,C_word *av) C_noret;
C_noret_decl(f_1723)
static void C_ccall f_1723(C_word c,C_word *av) C_noret;
C_noret_decl(f_1735)
static void C_ccall f_1735(C_word c,C_word *av) C_noret;
C_noret_decl(f_1740)
static void C_fcall f_1740(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_1759)
static void C_ccall f_1759(C_word c,C_word *av) C_noret;
C_noret_decl(f_1862)
static void C_ccall f_1862(C_word c,C_word *av) C_noret;
C_noret_decl(f_1879)
static void C_ccall f_1879(C_word c,C_word *av) C_noret;
C_noret_decl(f_1887)
static void C_ccall f_1887(C_word c,C_word *av) C_noret;
C_noret_decl(f_1899)
static void C_fcall f_1899(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_1913)
static void C_ccall f_1913(C_word c,C_word *av) C_noret;
C_noret_decl(f_1927)
static void C_ccall f_1927(C_word c,C_word *av) C_noret;
C_noret_decl(f_1932)
static void C_fcall f_1932(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_1972)
static void C_fcall f_1972(C_word t0,C_word t1) C_noret;
C_noret_decl(f_1998)
static void C_ccall f_1998(C_word c,C_word *av) C_noret;
C_noret_decl(f_2015)
static void C_ccall f_2015(C_word c,C_word *av) C_noret;
C_noret_decl(f_2022)
static void C_ccall f_2022(C_word c,C_word *av) C_noret;
C_noret_decl(f_2030)
static void C_fcall f_2030(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2050)
static void C_ccall f_2050(C_word c,C_word *av) C_noret;
C_noret_decl(f_2061)
static void C_ccall f_2061(C_word c,C_word *av) C_noret;
C_noret_decl(f_2065)
static void C_ccall f_2065(C_word c,C_word *av) C_noret;
C_noret_decl(f_2079)
static void C_ccall f_2079(C_word c,C_word *av) C_noret;
C_noret_decl(f_2118)
static void C_ccall f_2118(C_word c,C_word *av) C_noret;
C_noret_decl(f_2145)
static void C_fcall f_2145(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2155)
static void C_ccall f_2155(C_word c,C_word *av) C_noret;
C_noret_decl(f_2193)
static void C_fcall f_2193(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2217)
static void C_ccall f_2217(C_word c,C_word *av) C_noret;
C_noret_decl(f_2223)
static void C_ccall f_2223(C_word c,C_word *av) C_noret;
C_noret_decl(f_2253)
static void C_fcall f_2253(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_2260)
static void C_ccall f_2260(C_word c,C_word *av) C_noret;
C_noret_decl(f_2280)
static void C_ccall f_2280(C_word c,C_word *av) C_noret;
C_noret_decl(f_2306)
static void C_ccall f_2306(C_word c,C_word *av) C_noret;
C_noret_decl(f_2314)
static void C_ccall f_2314(C_word c,C_word *av) C_noret;
C_noret_decl(f_2317)
static void C_fcall f_2317(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_2324)
static void C_ccall f_2324(C_word c,C_word *av) C_noret;
C_noret_decl(f_2392)
static void C_ccall f_2392(C_word c,C_word *av) C_noret;
C_noret_decl(f_2395)
static void C_ccall f_2395(C_word c,C_word *av) C_noret;
C_noret_decl(f_2413)
static void C_ccall f_2413(C_word c,C_word *av) C_noret;
C_noret_decl(f_2438)
static void C_ccall f_2438(C_word c,C_word *av) C_noret;
C_noret_decl(f_2441)
static void C_fcall f_2441(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_2454)
static void C_ccall f_2454(C_word c,C_word *av) C_noret;
C_noret_decl(f_2460)
static void C_ccall f_2460(C_word c,C_word *av) C_noret;
C_noret_decl(f_2492)
static void C_ccall f_2492(C_word c,C_word *av) C_noret;
C_noret_decl(f_2526)
static void C_ccall f_2526(C_word c,C_word *av) C_noret;
C_noret_decl(f_2533)
static void C_ccall f_2533(C_word c,C_word *av) C_noret;
C_noret_decl(f_2535)
static void C_fcall f_2535(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2566)
static void C_ccall f_2566(C_word c,C_word *av) C_noret;
C_noret_decl(f_2580)
static void C_ccall f_2580(C_word c,C_word *av) C_noret;
C_noret_decl(f_2584)
static void C_ccall f_2584(C_word c,C_word *av) C_noret;
C_noret_decl(f_2591)
static void C_ccall f_2591(C_word c,C_word *av) C_noret;
C_noret_decl(f_2593)
static void C_ccall f_2593(C_word c,C_word *av) C_noret;
C_noret_decl(f_2596)
static void C_fcall f_2596(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_2600)
static void C_ccall f_2600(C_word c,C_word *av) C_noret;
C_noret_decl(f_2637)
static void C_ccall f_2637(C_word c,C_word *av) C_noret;
C_noret_decl(f_2649)
static void C_ccall f_2649(C_word c,C_word *av) C_noret;
C_noret_decl(f_2662)
static void C_ccall f_2662(C_word c,C_word *av) C_noret;
C_noret_decl(f_2668)
static void C_fcall f_2668(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2682)
static void C_ccall f_2682(C_word c,C_word *av) C_noret;
C_noret_decl(f_2704)
static void C_ccall f_2704(C_word c,C_word *av) C_noret;
C_noret_decl(f_2738)
static void C_ccall f_2738(C_word c,C_word *av) C_noret;
C_noret_decl(f_2747)
static void C_fcall f_2747(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2768)
static void C_ccall f_2768(C_word c,C_word *av) C_noret;
C_noret_decl(f_2785)
static void C_fcall f_2785(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2801)
static void C_fcall f_2801(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_2813)
static void C_ccall f_2813(C_word c,C_word *av) C_noret;
C_noret_decl(f_2819)
static void C_ccall f_2819(C_word c,C_word *av) C_noret;
C_noret_decl(f_2827)
static void C_ccall f_2827(C_word c,C_word *av) C_noret;
C_noret_decl(f_849)
static void C_ccall f_849(C_word c,C_word *av) C_noret;
C_noret_decl(f_851)
static void C_ccall f_851(C_word c,C_word *av) C_noret;
C_noret_decl(f_854)
static void C_fcall f_854(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_868)
static void C_ccall f_868(C_word c,C_word *av) C_noret;
C_noret_decl(f_877)
static C_word C_fcall f_877(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_924)
static void C_ccall f_924(C_word c,C_word *av) C_noret;
C_noret_decl(f_930)
static void C_ccall f_930(C_word c,C_word *av) C_noret;
C_noret_decl(f_967)
static void C_ccall f_967(C_word c,C_word *av) C_noret;
C_noret_decl(f_970)
static void C_ccall f_970(C_word c,C_word *av) C_noret;
C_noret_decl(f_975)
static void C_ccall f_975(C_word c,C_word *av) C_noret;
C_noret_decl(f_986)
static void C_ccall f_986(C_word c,C_word *av) C_noret;
C_noret_decl(f_988)
static void C_fcall f_988(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(C_data_2dstructures_toplevel)
C_externexport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_1022)
static void C_ccall trf_1022(C_word c,C_word *av) C_noret;
static void C_ccall trf_1022(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_1022(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_1064)
static void C_ccall trf_1064(C_word c,C_word *av) C_noret;
static void C_ccall trf_1064(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1064(t0,t1,t2);}

C_noret_decl(trf_1467)
static void C_ccall trf_1467(C_word c,C_word *av) C_noret;
static void C_ccall trf_1467(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1467(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1487)
static void C_ccall trf_1487(C_word c,C_word *av) C_noret;
static void C_ccall trf_1487(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_1487(t0,t1,t2,t3,t4);}

C_noret_decl(trf_1514)
static void C_ccall trf_1514(C_word c,C_word *av) C_noret;
static void C_ccall trf_1514(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1514(t0,t1,t2);}

C_noret_decl(trf_1598)
static void C_ccall trf_1598(C_word c,C_word *av) C_noret;
static void C_ccall trf_1598(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1598(t0,t1,t2,t3);}

C_noret_decl(trf_1685)
static void C_ccall trf_1685(C_word c,C_word *av) C_noret;
static void C_ccall trf_1685(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1685(t0,t1);}

C_noret_decl(trf_1740)
static void C_ccall trf_1740(C_word c,C_word *av) C_noret;
static void C_ccall trf_1740(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_1740(t0,t1,t2,t3);}

C_noret_decl(trf_1899)
static void C_ccall trf_1899(C_word c,C_word *av) C_noret;
static void C_ccall trf_1899(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_1899(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_1932)
static void C_ccall trf_1932(C_word c,C_word *av) C_noret;
static void C_ccall trf_1932(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_1932(t0,t1,t2);}

C_noret_decl(trf_1972)
static void C_ccall trf_1972(C_word c,C_word *av) C_noret;
static void C_ccall trf_1972(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_1972(t0,t1);}

C_noret_decl(trf_2030)
static void C_ccall trf_2030(C_word c,C_word *av) C_noret;
static void C_ccall trf_2030(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2030(t0,t1,t2,t3);}

C_noret_decl(trf_2145)
static void C_ccall trf_2145(C_word c,C_word *av) C_noret;
static void C_ccall trf_2145(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2145(t0,t1,t2);}

C_noret_decl(trf_2193)
static void C_ccall trf_2193(C_word c,C_word *av) C_noret;
static void C_ccall trf_2193(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2193(t0,t1,t2,t3);}

C_noret_decl(trf_2253)
static void C_ccall trf_2253(C_word c,C_word *av) C_noret;
static void C_ccall trf_2253(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_2253(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_2317)
static void C_ccall trf_2317(C_word c,C_word *av) C_noret;
static void C_ccall trf_2317(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_2317(t0,t1,t2,t3,t4);}

C_noret_decl(trf_2441)
static void C_ccall trf_2441(C_word c,C_word *av) C_noret;
static void C_ccall trf_2441(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_2441(t0,t1,t2);}

C_noret_decl(trf_2535)
static void C_ccall trf_2535(C_word c,C_word *av) C_noret;
static void C_ccall trf_2535(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2535(t0,t1,t2,t3);}

C_noret_decl(trf_2596)
static void C_ccall trf_2596(C_word c,C_word *av) C_noret;
static void C_ccall trf_2596(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_2596(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_2668)
static void C_ccall trf_2668(C_word c,C_word *av) C_noret;
static void C_ccall trf_2668(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2668(t0,t1,t2,t3);}

C_noret_decl(trf_2747)
static void C_ccall trf_2747(C_word c,C_word *av) C_noret;
static void C_ccall trf_2747(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2747(t0,t1,t2,t3);}

C_noret_decl(trf_2785)
static void C_ccall trf_2785(C_word c,C_word *av) C_noret;
static void C_ccall trf_2785(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2785(t0,t1,t2,t3);}

C_noret_decl(trf_2801)
static void C_ccall trf_2801(C_word c,C_word *av) C_noret;
static void C_ccall trf_2801(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_2801(t0,t1,t2,t3);}

C_noret_decl(trf_854)
static void C_ccall trf_854(C_word c,C_word *av) C_noret;
static void C_ccall trf_854(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_854(t0,t1,t2,t3);}

C_noret_decl(trf_988)
static void C_ccall trf_988(C_word c,C_word *av) C_noret;
static void C_ccall trf_988(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_988(t0,t1,t2);}

/* k1011 in map-loop80 in chicken.string#conc in k847 */
static void C_ccall f_1013(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1013,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_988(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* traverse in k847 */
static void C_fcall f_1022(C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
C_word t12;
C_word t13;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_1022,6,t1,t2,t3,t4,t5,t6);}
a=C_alloc(9);
t7=C_i_check_string_2(t2,t6);
t8=C_i_check_string_2(t3,t6);
t9=C_block_size(t3);
t10=C_block_size(t2);
t11=C_fixnum_difference(t9,t10);
t12=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_1041,a[2]=t4,a[3]=t9,a[4]=t10,a[5]=t1,a[6]=t11,a[7]=t5,a[8]=t6,tmp=(C_word)a,a+=9,tmp);
/* data-structures.scm:93: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word av2[4];
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t12;
av2[2]=t4;
av2[3]=t6;
tp(4,av2);}}

/* k1039 in traverse in k847 */
static void C_ccall f_1041(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_1041,c,av);}
a=C_alloc(9);
t2=C_fixnum_greater_or_equal_p(((C_word*)t0)[2],C_fix(0));
t3=(C_truep(t2)?C_fixnum_greater_or_equal_p(((C_word*)t0)[3],((C_word*)t0)[2]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_eqp(((C_word*)t0)[4],C_fix(0));
if(C_truep(t4)){
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)t0)[6],C_fix(0)))){
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1064,a[2]=((C_word*)t0)[6],a[3]=t6,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[4],a[6]=((C_word)li7),tmp=(C_word)a,a+=7,tmp));
t8=((C_word*)t6)[1];
f_1064(t8,((C_word*)t0)[5],((C_word*)t0)[2]);}
else{
t5=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}
else{
t4=C_fix((C_word)C_OUT_OF_RANGE_ERROR);
/* data-structures.scm:103: ##sys#error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[14]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[14]+1);
av2[1]=((C_word*)t0)[5];
av2[2]=t4;
av2[3]=((C_word*)t0)[8];
av2[4]=((C_word*)t0)[2];
av2[5]=((C_word*)t0)[3];
tp(6,av2);}}}

/* loop in k1039 in traverse in k847 */
static void C_fcall f_1064(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_1064,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greaterp(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1077,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:101: test */
t4=((C_word*)t0)[4];{
C_word av2[4];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}

/* k1075 in loop in k1039 in traverse in k847 */
static void C_ccall f_1077(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1077,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* data-structures.scm:102: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_1064(t2,((C_word*)t0)[2],C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}}

/* ##sys#substring-index in k847 */
static void C_ccall f_1096(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_1096,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1102,a[2]=t2,a[3]=t3,a[4]=((C_word)li9),tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:110: traverse */
f_1022(t1,t2,t3,t4,t5,lf[17]);}

/* a1101 in ##sys#substring-index in k847 */
static void C_ccall f_1102(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1102,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_substring_compare(((C_word*)t0)[2],((C_word*)t0)[3],C_fix(0),t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* ##sys#substring-index-ci in k847 */
static void C_ccall f_1105(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_1105,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1111,a[2]=t2,a[3]=t3,a[4]=((C_word)li11),tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:116: traverse */
f_1022(t1,t2,t3,t4,t5,lf[19]);}

/* a1110 in ##sys#substring-index-ci in k847 */
static void C_ccall f_1111(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1111,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_substring_compare_case_insensitive(((C_word*)t0)[2],((C_word*)t0)[3],C_fix(0),t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.string#substring-index in k847 */
static void C_ccall f_1114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1114,c,av);}
if(C_truep(C_rest_nullp(c,4))){
/* data-structures.scm:122: ##sys#substring-index */
t4=*((C_word*)lf[16]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* data-structures.scm:122: ##sys#substring-index */
t4=*((C_word*)lf[16]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_get_rest_arg(c,4,av,4,t0);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* chicken.string#substring-index-ci in k847 */
static void C_ccall f_1129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1129,c,av);}
if(C_truep(C_rest_nullp(c,4))){
/* data-structures.scm:125: ##sys#substring-index-ci */
t4=*((C_word*)lf[18]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_fix(0);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
/* data-structures.scm:125: ##sys#substring-index-ci */
t4=*((C_word*)lf[18]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=C_get_rest_arg(c,4,av,4,t0);
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* chicken.string#string-compare3 in k847 */
static void C_ccall f_1144(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1144,c,av);}
t4=C_i_check_string_2(t2,lf[23]);
t5=C_i_check_string_2(t3,lf[23]);
t6=C_block_size(t2);
t7=C_block_size(t3);
t8=C_fixnum_difference(t6,t7);
t9=C_fixnum_lessp(t8,C_fix(0));
t10=(C_truep(t9)?t6:t7);
t11=C_string_compare(t2,t3,t10);
t12=C_eqp(t11,C_fix(0));
t13=t1;{
C_word *av2=av;
av2[0]=t13;
av2[1]=(C_truep(t12)?t8:t11);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}

/* chicken.string#string-compare3-ci in k847 */
static void C_ccall f_1175(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1175,c,av);}
t4=C_i_check_string_2(t2,lf[25]);
t5=C_i_check_string_2(t3,lf[25]);
t6=C_block_size(t2);
t7=C_block_size(t3);
t8=C_fixnum_difference(t6,t7);
t9=C_fixnum_lessp(t8,C_fix(0));
t10=(C_truep(t9)?t6:t7);
t11=C_string_compare_case_insensitive(t2,t3,t10);
t12=C_eqp(t11,C_fix(0));
t13=t1;{
C_word *av2=av;
av2[0]=t13;
av2[1]=(C_truep(t12)?t8:t11);
((C_proc)(void*)(*((C_word*)t13+1)))(2,av2);}}

/* ##sys#substring=? in k847 */
static void C_ccall f_1206(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(c!=7) C_bad_argc_2(c,7,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1206,c,av);}
a=C_alloc(8);
t7=C_i_check_string_2(t2,lf[27]);
t8=C_i_check_string_2(t3,lf[27]);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1216,a[2]=t2,a[3]=t4,a[4]=t3,a[5]=t5,a[6]=t6,a[7]=t1,tmp=(C_word)a,a+=8,tmp);
t10=C_block_size(t2);
/* data-structures.scm:158: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[28]);
C_word *av2=av;
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t9;
av2[2]=t4;
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(t10,C_fix(1));
av2[5]=lf[27];
tp(6,av2);}}

/* k1214 in ##sys#substring=? in k847 */
static void C_ccall f_1216(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1216,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1219,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_block_size(((C_word*)t0)[4]);
/* data-structures.scm:159: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[28]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(t3,C_fix(1));
av2[5]=lf[27];
tp(6,av2);}}

/* k1217 in k1214 in ##sys#substring=? in k847 */
static void C_ccall f_1219(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1219,c,av);}
a=C_alloc(8);
t2=C_block_size(((C_word*)t0)[2]);
t3=C_fixnum_difference(t2,((C_word*)t0)[3]);
t4=C_block_size(((C_word*)t0)[4]);
t5=C_fixnum_difference(t4,((C_word*)t0)[5]);
t6=C_i_fixnum_min(t3,t5);
if(C_truep(((C_word*)t0)[6])){
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1228,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* data-structures.scm:163: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[28]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t7;
av2[2]=((C_word*)t0)[6];
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(t6,C_fix(1));
av2[5]=lf[27];
tp(6,av2);}}
else{
t7=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_substring_compare(((C_word*)t0)[2],((C_word*)t0)[4],((C_word*)t0)[3],((C_word*)t0)[5],t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k1226 in k1217 in k1214 in ##sys#substring=? in k847 */
static void C_ccall f_1228(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1228,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_substring_compare(((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.string#substring=? in k847 */
static void C_ccall f_1266(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1266,c,av);}
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_fix(0):C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_fix(0):C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_rest_nullp(c,6);
t11=(C_truep(t10)?C_SCHEME_FALSE:C_get_rest_arg(c,6,av,4,t0));
if(C_truep(C_rest_nullp(c,6))){
/* data-structures.scm:168: ##sys#substring=? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[7];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t5;
av2[5]=t8;
av2[6]=t11;
tp(7,av2);}}
else{
/* data-structures.scm:168: ##sys#substring=? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[26]+1));
C_word av2[7];
av2[0]=*((C_word*)lf[26]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t5;
av2[5]=t8;
av2[6]=t11;
tp(7,av2);}}}

/* ##sys#substring-ci=? in k847 */
static void C_ccall f_1326(C_word c,C_word *av){
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
C_word t9;
C_word t10;
C_word t11;
C_word *a;
if(c!=7) C_bad_argc_2(c,7,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1326,c,av);}
a=C_alloc(8);
t7=C_i_check_string_2(t2,lf[31]);
t8=C_i_check_string_2(t3,lf[31]);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1336,a[2]=t2,a[3]=t4,a[4]=t3,a[5]=t5,a[6]=t6,a[7]=t1,tmp=(C_word)a,a+=8,tmp);
t10=C_block_size(t2);
/* data-structures.scm:173: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[28]);
C_word *av2=av;
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t9;
av2[2]=t4;
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(t10,C_fix(1));
av2[5]=lf[31];
tp(6,av2);}}

/* k1334 in ##sys#substring-ci=? in k847 */
static void C_ccall f_1336(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1336,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1339,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_block_size(((C_word*)t0)[4]);
/* data-structures.scm:174: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[28]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(t3,C_fix(1));
av2[5]=lf[31];
tp(6,av2);}}

/* k1337 in k1334 in ##sys#substring-ci=? in k847 */
static void C_ccall f_1339(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,5)))){
C_save_and_reclaim((void *)f_1339,c,av);}
a=C_alloc(8);
t2=C_block_size(((C_word*)t0)[2]);
t3=C_fixnum_difference(t2,((C_word*)t0)[3]);
t4=C_block_size(((C_word*)t0)[4]);
t5=C_fixnum_difference(t4,((C_word*)t0)[5]);
t6=C_i_fixnum_min(t3,t5);
if(C_truep(((C_word*)t0)[6])){
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1348,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* data-structures.scm:178: ##sys#check-range */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[28]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[28]+1);
av2[1]=t7;
av2[2]=((C_word*)t0)[6];
av2[3]=C_fix(0);
av2[4]=C_fixnum_plus(t6,C_fix(1));
av2[5]=lf[31];
tp(6,av2);}}
else{
t7=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_substring_compare_case_insensitive(((C_word*)t0)[2],((C_word*)t0)[4],((C_word*)t0)[3],((C_word*)t0)[5],t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k1346 in k1337 in k1334 in ##sys#substring-ci=? in k847 */
static void C_ccall f_1348(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1348,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_substring_compare_case_insensitive(((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.string#substring-ci=? in k847 */
static void C_ccall f_1386(C_word c,C_word *av){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,6)))){
C_save_and_reclaim((void *)f_1386,c,av);}
t4=C_rest_nullp(c,4);
t5=(C_truep(t4)?C_fix(0):C_get_rest_arg(c,4,av,4,t0));
t6=C_rest_nullp(c,4);
t7=C_rest_nullp(c,5);
t8=(C_truep(t7)?C_fix(0):C_get_rest_arg(c,5,av,4,t0));
t9=C_rest_nullp(c,5);
t10=C_rest_nullp(c,6);
t11=(C_truep(t10)?C_SCHEME_FALSE:C_get_rest_arg(c,6,av,4,t0));
if(C_truep(C_rest_nullp(c,6))){
/* data-structures.scm:184: ##sys#substring-ci=? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word av2[7];
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t5;
av2[5]=t8;
av2[6]=t11;
tp(7,av2);}}
else{
/* data-structures.scm:184: ##sys#substring-ci=? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[30]+1));
C_word av2[7];
av2[0]=*((C_word*)lf[30]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t5;
av2[5]=t8;
av2[6]=t11;
tp(7,av2);}}}

/* chicken.string#string-split in k847 */
static void C_ccall f_1446(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +20,c,5)))){
C_save_and_reclaim((void*)f_1446,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+20);
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
C_word t14;
C_word t15;
C_word t16;
C_word t17;
C_word t18;
t4=C_i_check_string_2(t2,lf[34]);
t5=C_rest_nullp(c,3);
t6=(C_truep(t5)?lf[35]:C_get_rest_arg(c,3,av,3,t0));
t7=C_eqp(C_fix(c - 3),C_fix(2));
t8=(C_truep(t7)?C_i_cadr(t3):C_SCHEME_FALSE);
t9=C_block_size(t2);
t10=C_i_check_string_2(t6,lf[34]);
t11=C_block_size(t6);
t12=C_SCHEME_FALSE;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1467,a[2]=t13,a[3]=t2,a[4]=((C_word)li21),tmp=(C_word)a,a+=5,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_1487,a[2]=t9,a[3]=t13,a[4]=t8,a[5]=t14,a[6]=t2,a[7]=t11,a[8]=t16,a[9]=t6,a[10]=((C_word)li23),tmp=(C_word)a,a+=11,tmp));
t18=((C_word*)t16)[1];
f_1487(t18,t1,C_fix(0),C_SCHEME_FALSE,C_fix(0));}

/* add in chicken.string#string-split in k847 */
static void C_fcall f_1467(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_1467,5,t0,t1,t2,t3,t4);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1482,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:199: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
av2[3]=t2;
av2[4]=t3;
tp(5,av2);}}

/* k1480 in add in chicken.string#string-split in k847 */
static void C_ccall f_1482(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1482,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
if(C_truep(((C_word*)((C_word*)t0)[2])[1])){
t3=C_i_setslot(((C_word*)t0)[3],C_fix(1),t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* loop in chicken.string#string-split in k847 */
static void C_fcall f_1487(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_1487,5,t0,t1,t2,t3,t4);}
a=C_alloc(15);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1497,a[2]=((C_word*)t0)[3],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t6=C_fixnum_greaterp(t2,t4);
t7=(C_truep(t6)?t6:((C_word*)t0)[4]);
if(C_truep(t7)){
/* data-structures.scm:206: add */
t8=((C_word*)t0)[5];
f_1467(t8,t5,t4,t2,t3);}
else{
t8=((C_word*)((C_word*)t0)[3])[1];
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=(C_truep(t8)?t8:C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}}
else{
t5=C_subchar(((C_word*)t0)[6],t2);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_1514,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=t2,a[5]=t3,a[6]=t4,a[7]=t5,a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[5],a[11]=t7,a[12]=((C_word)li22),tmp=(C_word)a,a+=13,tmp));
t9=((C_word*)t7)[1];
f_1514(t9,t1,C_fix(0));}}

/* k1495 in loop in chicken.string#string-split in k847 */
static void C_ccall f_1497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1497,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:C_SCHEME_END_OF_LIST);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* scan in loop in chicken.string#string-split in k847 */
static void C_fcall f_1514(C_word t0,C_word t1,C_word t2){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_1514,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
/* data-structures.scm:211: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_1487(t3,t1,C_fixnum_plus(((C_word*)t0)[4],C_fix(1)),((C_word*)t0)[5],((C_word*)t0)[6]);}
else{
t3=C_eqp(((C_word*)t0)[7],C_subchar(((C_word*)t0)[8],t2));
if(C_truep(t3)){
t4=C_fixnum_plus(((C_word*)t0)[4],C_fix(1));
t5=C_fixnum_greaterp(((C_word*)t0)[4],((C_word*)t0)[6]);
t6=(C_truep(t5)?t5:((C_word*)t0)[9]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1553,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:215: add */
t8=((C_word*)t0)[10];
f_1467(t8,t7,((C_word*)t0)[6],((C_word*)t0)[4],((C_word*)t0)[5]);}
else{
/* data-structures.scm:216: loop */
t7=((C_word*)((C_word*)t0)[3])[1];
f_1487(t7,t1,t4,((C_word*)t0)[5],t4);}}
else{
/* data-structures.scm:217: scan */
t9=t1;
t10=C_fixnum_plus(t2,C_fix(1));
t1=t9;
t2=t10;
goto loop;}}}

/* k1551 in scan in loop in chicken.string#string-split in k847 */
static void C_ccall f_1553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_1553,c,av);}
/* data-structures.scm:215: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_1487(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1,((C_word*)t0)[4]);}

/* chicken.string#string-intersperse in k847 */
static void C_ccall f_1580(C_word c,C_word *av){
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
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_1580,c,av);}
a=C_alloc(9);
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?lf[38]:C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_list_2(t2,lf[39]);
t6=C_i_check_string_2(t4,lf[39]);
t7=C_block_size(t4);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1598,a[2]=t2,a[3]=t4,a[4]=t7,a[5]=t9,a[6]=((C_word)li26),tmp=(C_word)a,a+=7,tmp));
t11=((C_word*)t9)[1];
f_1598(t11,t1,t2,C_fix(0));}

/* loop1 in chicken.string#string-intersperse in k847 */
static void C_fcall f_1598(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,5)))){
C_save_and_reclaim_args((void *)trf_1598,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_eqp(t2,C_SCHEME_END_OF_LIST))){
if(C_truep(C_eqp(((C_word*)t0)[2],C_SCHEME_END_OF_LIST))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=lf[40];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1608,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* data-structures.scm:230: ##sys#allocate-vector */
t5=*((C_word*)lf[41]+1);{
C_word av2[6];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_fixnum_difference(t3,((C_word*)t0)[4]);
av2[3]=C_SCHEME_TRUE;
av2[4]=C_make_character(32);
av2[5]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}
else{
t4=(C_truep(C_blockp(t2))?C_pairp(t2):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_slot(t2,C_fix(0));
t6=C_i_check_string_2(t5,lf[39]);
t7=C_slot(t2,C_fix(1));
t8=C_block_size(t5);
t9=C_fixnum_plus(((C_word*)t0)[4],t3);
/* data-structures.scm:245: loop1 */
t11=t1;
t12=t7;
t13=C_fixnum_plus(t8,t9);
t1=t11;
t2=t12;
t3=t13;
goto loop;}
else{
/* data-structures.scm:247: ##sys#error-not-a-proper-list */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[42]);
C_word av2[3];
av2[0]=*((C_word*)lf[42]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
tp(3,av2);}}}}

/* k1606 in loop1 in chicken.string#string-intersperse in k847 */
static void C_ccall f_1608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_1608,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1613,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li25),tmp=(C_word)a,a+=6,tmp);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_1613(t2,((C_word*)t0)[5],C_fix(0))
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* loop2 in k1606 in loop1 in chicken.string#string-intersperse in k847 */
static C_word C_fcall f_1613(C_word t0,C_word t1,C_word t2){
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
C_stack_overflow_check;
loop:{}
t3=C_slot(t1,C_fix(0));
t4=C_slot(t1,C_fix(1));
t5=C_block_size(t3);
t6=C_substring_copy(t3,((C_word*)t0)[2],C_fix(0),t5,t2);
t7=C_fixnum_plus(t2,t5);
if(C_truep(C_eqp(t4,C_SCHEME_END_OF_LIST))){
return(((C_word*)t0)[2]);}
else{
t8=C_substring_copy(((C_word*)t0)[3],((C_word*)t0)[2],C_fix(0),((C_word*)t0)[4],t7);
t10=t4;
t11=C_fixnum_plus(t7,((C_word*)t0)[4]);
t1=t10;
t2=t11;
goto loop;}}

/* chicken.string#string-translate in k847 */
static void C_ccall f_1682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c<4) C_bad_min_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-4)*C_SIZEOF_PAIR +12,c,3)))){
C_save_and_reclaim((void*)f_1682,c,av);}
a=C_alloc((c-4)*C_SIZEOF_PAIR+12);
t4=C_build_rest(&a,c,4,av);
C_word t5;
C_word t6;
C_word t7;
C_word t8;
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1685,a[2]=((C_word)li30),tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1720,a[2]=t2,a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_charp(t3))){
t7=t6;{
C_word *av2=av;
av2[0]=t7;
av2[1]=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1862,a[2]=t3,a[3]=((C_word)li32),tmp=(C_word)a,a+=4,tmp);
f_1720(2,av2);}}
else{
if(C_truep(C_i_pairp(t3))){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1879,a[2]=t5,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* ##sys#list->string */
t8=C_fast_retrieve(lf[48]);{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t7=C_i_check_string_2(t3,lf[44]);
/* data-structures.scm:268: instring */
f_1685(t6,t3);}}}

/* instring in chicken.string#string-translate in k847 */
static void C_fcall f_1685(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_1685,2,t1,t2);}
a=C_alloc(5);
t3=C_block_size(t2);
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1690,a[2]=t3,a[3]=t2,a[4]=((C_word)li29),tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* f_1690 in instring in chicken.string#string-translate in k847 */
static void C_ccall f_1690(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_1690,c,av);}
a=C_alloc(6);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1696,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word)li28),tmp=(C_word)a,a+=6,tmp);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
  f_1696(t3,C_fix(0))
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* loop */
static C_word C_fcall f_1696(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[2]))){
return(C_SCHEME_FALSE);}
else{
t2=C_eqp(((C_word*)t0)[3],C_subchar(((C_word*)t0)[4],t1));
if(C_truep(t2)){
return(t1);}
else{
t4=C_fixnum_plus(t1,C_fix(1));
t1=t4;
goto loop;}}}

/* k1718 in chicken.string#string-translate in k847 */
static void C_ccall f_1720(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_1720,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_1723,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t3=C_slot(((C_word*)t0)[4],C_fix(0));
if(C_truep(C_charp(t3))){
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_1723(2,av2);}}
else{
if(C_truep(C_i_pairp(t3))){
/* ##sys#list->string */
t4=C_fast_retrieve(lf[48]);{
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
t4=C_i_check_string_2(t3,lf[44]);
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
f_1723(2,av2);}}}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_1723(2,av2);}}}

/* k1721 in k1718 in chicken.string#string-translate in k847 */
static void C_ccall f_1723(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_1723,c,av);}
a=C_alloc(8);
t2=C_i_stringp(t1);
t3=(C_truep(t2)?C_block_size(t1):C_SCHEME_FALSE);
t4=C_i_check_string_2(((C_word*)t0)[2],lf[44]);
t5=C_block_size(((C_word*)t0)[2]);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1735,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t3,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
/* ##sys#make-string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[47]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[47]+1);
av2[1]=t6;
av2[2]=t5;
av2[3]=C_make_character(32);
tp(4,av2);}}

/* k1733 in k1721 in k1718 in chicken.string#string-translate in k847 */
static void C_ccall f_1735(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_1735,c,av);}
a=C_alloc(12);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1740,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=t3,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word)li31),tmp=(C_word)a,a+=10,tmp));
t5=((C_word*)t3)[1];
f_1740(t5,((C_word*)t0)[7],C_fix(0),C_fix(0));}

/* loop in k1733 in k1721 in k1718 in chicken.string#string-translate in k847 */
static void C_fcall f_1740(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_1740,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
if(C_truep(C_fixnum_lessp(t3,t2))){
/* data-structures.scm:284: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=C_fix(0);
av2[4]=t3;
tp(5,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t4=C_subchar(((C_word*)t0)[4],t2);
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_1759,a[2]=((C_word*)t0)[3],a[3]=t3,a[4]=t4,a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=t2,a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],tmp=(C_word)a,a+=10,tmp);
/* data-structures.scm:287: from */
t6=((C_word*)t0)[8];{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}

/* k1757 in loop in k1733 in k1721 in k1718 in chicken.string#string-translate in k847 */
static void C_ccall f_1759(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_1759,c,av);}
if(C_truep(C_i_not(t1))){
t2=C_setsubchar(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[4]);
/* data-structures.scm:290: loop */
t3=((C_word*)((C_word*)t0)[5])[1];
f_1740(t3,((C_word*)t0)[6],C_fixnum_plus(((C_word*)t0)[7],C_fix(1)),C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}
else{
if(C_truep(C_i_not(((C_word*)t0)[8]))){
/* data-structures.scm:291: loop */
t2=((C_word*)((C_word*)t0)[5])[1];
f_1740(t2,((C_word*)t0)[6],C_fixnum_plus(((C_word*)t0)[7],C_fix(1)),((C_word*)t0)[3]);}
else{
if(C_truep(C_charp(((C_word*)t0)[8]))){
t2=C_setsubchar(((C_word*)t0)[2],((C_word*)t0)[3],((C_word*)t0)[8]);
/* data-structures.scm:294: loop */
t3=((C_word*)((C_word*)t0)[5])[1];
f_1740(t3,((C_word*)t0)[6],C_fixnum_plus(((C_word*)t0)[7],C_fix(1)),C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}
else{
if(C_truep(C_fixnum_greater_or_equal_p(t1,((C_word*)t0)[9]))){
/* data-structures.scm:296: ##sys#error */
t2=*((C_word*)lf[45]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[6];
av2[2]=lf[44];
av2[3]=lf[46];
av2[4]=((C_word*)t0)[7];
av2[5]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}
else{
t2=C_subchar(((C_word*)t0)[8],t1);
t3=C_setsubchar(((C_word*)t0)[2],((C_word*)t0)[3],t2);
/* data-structures.scm:299: loop */
t4=((C_word*)((C_word*)t0)[5])[1];
f_1740(t4,((C_word*)t0)[6],C_fixnum_plus(((C_word*)t0)[7],C_fix(1)),C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}}}}}

/* f_1862 in chicken.string#string-translate in k847 */
static void C_ccall f_1862(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_1862,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_eqp(t2,((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k1877 in chicken.string#string-translate in k847 */
static void C_ccall f_1879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_1879,c,av);}
/* data-structures.scm:265: instring */
f_1685(((C_word*)t0)[3],t1);}

/* chicken.string#string-translate* in k847 */
static void C_ccall f_1887(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,6)))){
C_save_and_reclaim((void *)f_1887,c,av);}
a=C_alloc(9);
t4=C_i_check_string_2(t2,lf[50]);
t5=C_i_check_list_2(t3,lf[50]);
t6=C_block_size(t2);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_1899,a[2]=t6,a[3]=t2,a[4]=t8,a[5]=t3,a[6]=((C_word)li35),tmp=(C_word)a,a+=7,tmp));
/* data-structures.scm:330: collect */
t10=((C_word*)t8)[1];
f_1899(t10,t1,C_fix(0),C_fix(0),C_fix(0),C_SCHEME_END_OF_LIST);}

/* collect in chicken.string#string-translate* in k847 */
static void C_fcall f_1899(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,4)))){
C_save_and_reclaim_args((void *)trf_1899,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(15);
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1913,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_fixnum_greaterp(t2,t3))){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1927,a[2]=t6,a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:311: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t8;
av2[2]=((C_word*)t0)[3];
av2[3]=t3;
av2[4]=t2;
tp(5,av2);}}
else{
t8=((C_word*)t6)[1];
/* data-structures.scm:309: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[52]);
C_word av2[3];
av2[0]=*((C_word*)lf[52]+1);
av2[1]=t7;
av2[2]=t8;
tp(3,av2);}}}
else{
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_1932,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=t3,a[5]=t4,a[6]=t6,a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[3],a[9]=t8,a[10]=((C_word)li34),tmp=(C_word)a,a+=11,tmp));
t10=((C_word*)t8)[1];
f_1932(t10,t1,((C_word*)t0)[5]);}}

/* k1911 in collect in chicken.string#string-translate* in k847 */
static void C_ccall f_1913(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_1913,c,av);}
/* data-structures.scm:307: ##sys#fragments->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[51]);
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[51]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k1925 in collect in chicken.string#string-translate* in k847 */
static void C_ccall f_1927(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_1927,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)((C_word*)t0)[2])[1]);
/* data-structures.scm:309: ##sys#fast-reverse */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[52]);
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[52]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t2;
tp(3,av2);}}

/* loop in collect in chicken.string#string-translate* in k847 */
static void C_fcall f_1932(C_word t0,C_word t1,C_word t2){
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
loop:
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,5)))){
C_save_and_reclaim_args((void *)trf_1932,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_nullp(t2))){
/* data-structures.scm:315: collect */
t3=((C_word*)((C_word*)t0)[2])[1];
f_1899(t3,t1,C_fixnum_plus(((C_word*)t0)[3],C_fix(1)),((C_word*)t0)[4],C_fixnum_plus(((C_word*)t0)[5],C_fix(1)),((C_word*)((C_word*)t0)[6])[1]);}
else{
t3=C_i_car(t2);
t4=C_i_car(t3);
t5=C_i_string_length(t4);
t6=C_u_i_cdr(t3);
t7=C_fixnum_plus(((C_word*)t0)[3],t5);
t8=C_fixnum_less_or_equal_p(t7,((C_word*)t0)[7]);
t9=(C_truep(t8)?C_substring_compare(((C_word*)t0)[8],t4,((C_word*)t0)[3],C_fix(0),t5):C_SCHEME_FALSE);
if(C_truep(t9)){
t10=C_fixnum_plus(((C_word*)t0)[3],t5);
t11=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_1972,a[2]=t6,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[2],a[6]=t1,a[7]=t10,tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_fixnum_greaterp(((C_word*)t0)[3],((C_word*)t0)[4]))){
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1998,a[2]=((C_word*)t0)[6],a[3]=t11,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:324: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t12;
av2[2]=((C_word*)t0)[8];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[3];
tp(5,av2);}}
else{
t12=t11;
f_1972(t12,C_SCHEME_UNDEFINED);}}
else{
/* data-structures.scm:329: loop */
t14=t1;
t15=C_u_i_cdr(t2);
t1=t14;
t2=t15;
goto loop;}}}

/* k1970 in loop in collect in chicken.string#string-translate* in k847 */
static void C_fcall f_1972(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,5)))){
C_save_and_reclaim_args((void *)trf_1972,2,t0,t1);}
a=C_alloc(3);
t2=C_i_string_length(((C_word*)t0)[2]);
t3=C_fixnum_plus(((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)((C_word*)t0)[4])[1]);
/* data-structures.scm:325: collect */
t5=((C_word*)((C_word*)t0)[5])[1];
f_1899(t5,((C_word*)t0)[6],((C_word*)t0)[7],((C_word*)t0)[7],t3,t4);}

/* k1996 in loop in collect in chicken.string#string-translate* in k847 */
static void C_ccall f_1998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_1998,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,((C_word*)((C_word*)t0)[2])[1]);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)t0)[3];
f_1972(t4,t3);}

/* chicken.string#string-chop in k847 */
static void C_ccall f_2015(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_2015,c,av);}
a=C_alloc(5);
t4=C_i_check_string_2(t2,lf[54]);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2022,a[2]=t2,a[3]=t3,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:337: ##sys#check-fixnum */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[15]);
C_word *av2=av;
av2[0]=*((C_word*)lf[15]+1);
av2[1]=t5;
av2[2]=t3;
av2[3]=lf[54];
tp(4,av2);}}

/* k2020 in chicken.string#string-chop in k847 */
static void C_ccall f_2022(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_2022,c,av);}
a=C_alloc(8);
t2=C_block_size(((C_word*)t0)[2]);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2030,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=t4,a[5]=((C_word)li37),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_2030(t6,((C_word*)t0)[4],t2,C_fix(0));}

/* loop in k2020 in chicken.string#string-chop in k847 */
static void C_fcall f_2030(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_2030,4,t0,t1,t2,t3);}
a=C_alloc(7);
if(C_truep(C_fixnum_less_or_equal_p(t2,C_fix(0)))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_fixnum_less_or_equal_p(t2,((C_word*)t0)[2]))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2050,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* data-structures.scm:341: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
av2[3]=t3;
av2[4]=C_fixnum_plus(t3,t2);
tp(5,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2061,a[2]=t1,a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[2],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* data-structures.scm:342: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t4;
av2[2]=((C_word*)t0)[3];
av2[3]=t3;
av2[4]=C_fixnum_plus(t3,((C_word*)t0)[2]);
tp(5,av2);}}}}

/* k2048 in loop in k2020 in chicken.string#string-chop in k847 */
static void C_ccall f_2050(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2050,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list1(&a,1,t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2059 in loop in k2020 in chicken.string#string-chop in k847 */
static void C_ccall f_2061(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_2061,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2065,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:342: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_2030(t3,t2,C_fixnum_difference(((C_word*)t0)[4],((C_word*)t0)[5]),C_fixnum_plus(((C_word*)t0)[6],((C_word*)t0)[5]));}

/* k2063 in k2059 in loop in k2020 in chicken.string#string-chop in k847 */
static void C_ccall f_2065(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2065,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.string#string-chomp in k847 */
static void C_ccall f_2079(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2079,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?lf[56]:C_get_rest_arg(c,3,av,3,t0));
t5=C_i_check_string_2(t2,lf[57]);
t6=C_i_check_string_2(t4,lf[57]);
t7=C_block_size(t2);
t8=C_block_size(t4);
t9=C_fixnum_difference(t7,t8);
if(C_truep(C_fixnum_greater_or_equal_p(t7,t8))){
if(C_truep(C_substring_compare(t2,t4,t9,C_fix(0),t8))){
/* data-structures.scm:355: ##sys#substring */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[36]);
C_word av2[5];
av2[0]=*((C_word*)lf[36]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=t9;
tp(5,av2);}}
else{
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}
else{
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}}

/* chicken.sort#sorted? in k847 */
static void C_ccall f_2118(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_2118,c,av);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_vectorp(t2))){
t4=C_block_size(t2);
if(C_truep(C_fixnum_less_or_equal_p(t4,C_fix(1)))){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2145,a[2]=t4,a[3]=t6,a[4]=t2,a[5]=t3,a[6]=((C_word)li40),tmp=(C_word)a,a+=7,tmp));
t8=((C_word*)t6)[1];
f_2145(t8,t1,C_fix(1));}}
else{
t4=C_i_car(t2);
t5=C_u_i_cdr(t2);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2193,a[2]=t7,a[3]=t3,a[4]=((C_word)li41),tmp=(C_word)a,a+=5,tmp));
t9=((C_word*)t7)[1];
f_2193(t9,t1,t4,t5);}}}

/* doloop471 in chicken.sort#sorted? in k847 */
static void C_fcall f_2145(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_2145,3,t0,t1,t2);}
a=C_alloc(11);
t3=C_i_nequalp(t2,((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2155,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=t3;
f_2155(2,av2);}}
else{
t5=C_i_vector_ref(((C_word*)t0)[4],t2);
t6=C_a_i_fixnum_difference(&a,2,t2,C_fix(1));
/* data-structures.scm:394: less? */
t7=((C_word*)t0)[5];{
C_word av2[4];
av2[0]=t7;
av2[1]=t4;
av2[2]=t5;
av2[3]=C_i_vector_ref(((C_word*)t0)[4],t6);
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}}

/* k2153 in doloop471 in chicken.sort#sorted? in k847 */
static void C_ccall f_2155(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(29,c,2)))){
C_save_and_reclaim((void *)f_2155,c,av);}
a=C_alloc(29);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_nequalp(((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_s_a_i_plus(&a,2,((C_word*)t0)[3],C_fix(1));
t3=((C_word*)((C_word*)t0)[5])[1];
f_2145(t3,((C_word*)t0)[2],t2);}}

/* loop in chicken.sort#sorted? in k847 */
static void C_fcall f_2193(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_2193,4,t0,t1,t2,t3);}
a=C_alloc(5);
t4=C_i_nullp(t3);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2217,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:400: less? */
t6=((C_word*)t0)[3];{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_car(t3);
av2[3]=t2;
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}}

/* k2215 in loop in chicken.sort#sorted? in k847 */
static void C_ccall f_2217(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2217,c,av);}
if(C_truep(C_i_not(t1))){
/* data-structures.scm:401: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2193(t2,((C_word*)t0)[3],C_u_i_car(((C_word*)t0)[4]),C_u_i_cdr(((C_word*)t0)[4]));}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.sort#merge in k847 */
static void C_ccall f_2223(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,6)))){
C_save_and_reclaim((void *)f_2223,c,av);}
a=C_alloc(7);
if(C_truep(C_i_nullp(t2))){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
if(C_truep(C_i_nullp(t3))){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=C_u_i_cdr(t2);
t7=C_i_car(t3);
t8=C_u_i_cdr(t3);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2253,a[2]=t10,a[3]=t4,a[4]=((C_word)li43),tmp=(C_word)a,a+=5,tmp));
t12=((C_word*)t10)[1];
f_2253(t12,t1,t5,t6,t7,t8);}}}

/* loop in chicken.sort#merge in k847 */
static void C_fcall f_2253(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
C_word tmp;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_2253,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(8);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_2260,a[2]=t5,a[3]=t2,a[4]=t3,a[5]=t1,a[6]=t4,a[7]=((C_word*)t0)[2],tmp=(C_word)a,a+=8,tmp);
/* data-structures.scm:417: less? */
t7=((C_word*)t0)[3];{
C_word av2[4];
av2[0]=t7;
av2[1]=t6;
av2[2]=t4;
av2[3]=t2;
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}

/* k2258 in loop in chicken.sort#merge in k847 */
static void C_ccall f_2260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_2260,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
t2=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[6],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2280,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:420: loop */
t3=((C_word*)((C_word*)t0)[7])[1];
f_2253(t3,t2,((C_word*)t0)[3],((C_word*)t0)[4],C_i_car(((C_word*)t0)[2]),C_u_i_cdr(((C_word*)t0)[2]));}}
else{
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
t2=C_a_i_cons(&a,2,((C_word*)t0)[6],((C_word*)t0)[2]);
t3=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2306,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:424: loop */
t3=((C_word*)((C_word*)t0)[7])[1];
f_2253(t3,t2,C_i_car(((C_word*)t0)[4]),C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[6],((C_word*)t0)[2]);}}}

/* k2278 in k2258 in loop in chicken.sort#merge in k847 */
static void C_ccall f_2280(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2280,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2304 in k2258 in loop in chicken.sort#merge in k847 */
static void C_ccall f_2306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_2306,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.sort#merge! in k847 */
static void C_ccall f_2314(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_2314,c,av);}
a=C_alloc(13);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2317,a[2]=t6,a[3]=t4,a[4]=((C_word)li45),tmp=(C_word)a,a+=5,tmp));
if(C_truep(C_i_nullp(t2))){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
if(C_truep(C_i_nullp(t3))){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2392,a[2]=t1,a[3]=t3,a[4]=t2,a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* data-structures.scm:449: less? */
t9=t4;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=C_i_car(t3);
av2[3]=C_i_car(t2);
((C_proc)C_fast_retrieve_proc(t9))(4,av2);}}}}

/* loop in chicken.sort#merge! in k847 */
static void C_fcall f_2317(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_2317,5,t0,t1,t2,t3,t4);}
a=C_alloc(7);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2324,a[2]=t2,a[3]=t4,a[4]=t1,a[5]=t3,a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* data-structures.scm:434: less? */
t6=((C_word*)t0)[3];{
C_word av2[4];
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_car(t4);
av2[3]=C_i_car(t3);
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}

/* k2322 in loop in chicken.sort#merge! in k847 */
static void C_ccall f_2324(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2324,c,av);}
if(C_truep(t1)){
t2=C_i_set_cdr(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[3])))){
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_setslot(((C_word*)t0)[3],C_fix(1),((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* data-structures.scm:439: loop */
t3=((C_word*)((C_word*)t0)[6])[1];
f_2317(t3,((C_word*)t0)[4],((C_word*)t0)[3],((C_word*)t0)[5],C_u_i_cdr(((C_word*)t0)[3]));}}
else{
t2=C_i_set_cdr(((C_word*)t0)[2],((C_word*)t0)[5]);
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[5])))){
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_setslot(((C_word*)t0)[5],C_fix(1),((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* data-structures.scm:445: loop */
t3=((C_word*)((C_word*)t0)[6])[1];
f_2317(t3,((C_word*)t0)[4],((C_word*)t0)[5],C_u_i_cdr(((C_word*)t0)[5]),((C_word*)t0)[3]);}}}

/* k2390 in chicken.sort#merge! in k847 */
static void C_ccall f_2392(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_2392,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2395,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[3])))){
t3=C_i_setslot(((C_word*)t0)[3],C_fix(1),((C_word*)t0)[4]);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* data-structures.scm:452: loop */
t3=((C_word*)((C_word*)t0)[5])[1];
f_2317(t3,t2,((C_word*)t0)[3],((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[3]));}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2413,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[4])))){
t3=C_i_setslot(((C_word*)t0)[4],C_fix(1),((C_word*)t0)[3]);
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
/* data-structures.scm:457: loop */
t3=((C_word*)((C_word*)t0)[5])[1];
f_2317(t3,t2,((C_word*)t0)[4],C_u_i_cdr(((C_word*)t0)[4]),((C_word*)t0)[3]);}}}

/* k2393 in k2390 in chicken.sort#merge! in k847 */
static void C_ccall f_2395(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2395,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k2411 in k2390 in chicken.sort#merge! in k847 */
static void C_ccall f_2413(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2413,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.sort#sort! in k847 */
static void C_ccall f_2438(C_word c,C_word *av){
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
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,3)))){
C_save_and_reclaim((void *)f_2438,c,av);}
a=C_alloc(17);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2441,a[2]=t3,a[3]=t6,a[4]=t4,a[5]=((C_word)li47),tmp=(C_word)a,a+=6,tmp));
if(C_truep(C_i_vectorp(((C_word*)t4)[1]))){
t8=C_i_vector_length(((C_word*)t4)[1]);
t9=((C_word*)t4)[1];
t10=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2526,a[2]=t4,a[3]=t9,a[4]=t1,a[5]=t6,a[6]=t8,tmp=(C_word)a,a+=7,tmp);
/* data-structures.scm:496: scheme#vector->list */
t11=*((C_word*)lf[63]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
av2[2]=((C_word*)t4)[1];
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}
else{
/* data-structures.scm:502: step */
t8=((C_word*)t6)[1];
f_2441(t8,t1,C_i_length(((C_word*)t4)[1]));}}

/* step in chicken.sort#sort! in k847 */
static void C_fcall f_2441(C_word t0,C_word t1,C_word t2){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_2441,3,t0,t1,t2);}
a=C_alloc(12);
if(C_truep(C_i_greaterp(t2,C_fix(2)))){
t3=C_s_a_i_quotient(&a,2,t2,C_fix(2));
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2454,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
/* data-structures.scm:472: step */
t10=t4;
t11=t3;
t1=t10;
t2=t11;
goto loop;}
else{
if(C_truep(C_i_nequalp(t2,C_fix(2)))){
t3=C_i_car(((C_word*)((C_word*)t0)[4])[1]);
t4=C_i_cadr(((C_word*)((C_word*)t0)[4])[1]);
t5=((C_word*)((C_word*)t0)[4])[1];
t6=C_i_cddr(((C_word*)((C_word*)t0)[4])[1]);
t7=C_mutate(((C_word *)((C_word*)t0)[4])+1,t6);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2492,a[2]=t5,a[3]=t4,a[4]=t3,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* data-structures.scm:481: less? */
t9=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t9;
av2[1]=t8;
av2[2]=t4;
av2[3]=t3;
((C_proc)C_fast_retrieve_proc(t9))(4,av2);}}
else{
if(C_truep(C_i_nequalp(t2,C_fix(1)))){
t3=((C_word*)((C_word*)t0)[4])[1];
t4=C_i_cdr(((C_word*)((C_word*)t0)[4])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[4])+1,t4);
t6=C_i_set_cdr(t3,C_SCHEME_END_OF_LIST);
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}}

/* k2452 in step in chicken.sort#sort! in k847 */
static void C_ccall f_2454(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(34,c,2)))){
C_save_and_reclaim((void *)f_2454,c,av);}
a=C_alloc(34);
t2=C_s_a_i_minus(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2460,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:474: step */
t4=((C_word*)((C_word*)t0)[6])[1];
f_2441(t4,t3,t2);}

/* k2458 in k2452 in step in chicken.sort#sort! in k847 */
static void C_ccall f_2460(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_2460,c,av);}
/* data-structures.scm:475: merge! */
t2=*((C_word*)lf[61]+1);{
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
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k2490 in step in chicken.sort#sort! in k847 */
static void C_ccall f_2492(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_2492,c,av);}
if(C_truep(t1)){
t2=C_i_set_car(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_i_set_car(C_u_i_cdr(((C_word*)t0)[2]),((C_word*)t0)[4]);
t4=C_i_cdr(((C_word*)t0)[2]);
t5=C_i_set_cdr(t4,C_SCHEME_END_OF_LIST);
t6=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t6;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_i_set_cdr(t2,C_SCHEME_END_OF_LIST);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k2524 in chicken.sort#sort! in k847 */
static void C_ccall f_2526(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_2526,c,av);}
a=C_alloc(4);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2533,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:497: step */
t4=((C_word*)((C_word*)t0)[5])[1];
f_2441(t4,t3,((C_word*)t0)[6]);}

/* k2531 in k2524 in chicken.sort#sort! in k847 */
static void C_ccall f_2533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_2533,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2535,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li48),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_2535(t5,((C_word*)t0)[3],t1,C_fix(0));}

/* doloop542 in k2531 in k2524 in chicken.sort#sort! in k847 */
static void C_fcall f_2535(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_2535,4,t0,t1,t2,t3);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_i_vector_set(((C_word*)t0)[2],t3,t4);
t6=C_u_i_cdr(t2);
t7=C_a_i_fixnum_plus(&a,2,t3,C_fix(1));
t9=t1;
t10=t6;
t11=t7;
t1=t9;
t2=t10;
t3=t11;
goto loop;}}

/* chicken.sort#sort in k847 */
static void C_ccall f_2566(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_2566,c,av);}
a=C_alloc(7);
if(C_truep(C_i_vectorp(t2))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2580,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2584,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:513: scheme#vector->list */
t6=*((C_word*)lf[63]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2591,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:514: scheme#append */
t5=*((C_word*)lf[66]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k2578 in chicken.sort#sort in k847 */
static void C_ccall f_2580(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_2580,c,av);}
/* data-structures.scm:513: scheme#list->vector */
t2=*((C_word*)lf[65]+1);{
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

/* k2582 in chicken.sort#sort in k847 */
static void C_ccall f_2584(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2584,c,av);}
/* data-structures.scm:513: sort! */
t2=*((C_word*)lf[62]+1);{
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

/* k2589 in chicken.sort#sort in k847 */
static void C_ccall f_2591(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2591,c,av);}
/* data-structures.scm:514: sort! */
t2=*((C_word*)lf[62]+1);{
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

/* chicken.sort#topological-sort in k847 */
static void C_ccall f_2593(C_word c,C_word *av){
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
if(c!=4) C_bad_argc_2(c,4,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(22,c,7)))){
C_save_and_reclaim((void *)f_2593,c,av);}
a=C_alloc(22);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2596,a[2]=t3,a[3]=t5,a[4]=((C_word)li52),tmp=(C_word)a,a+=5,tmp));
t9=C_i_check_list_2(t2,lf[84]);
t10=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2738,a[2]=t7,a[3]=t5,a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2785,a[2]=t3,a[3]=t2,a[4]=t12,a[5]=((C_word)li55),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_2785(t14,t10,t2,C_SCHEME_END_OF_LIST);}

/* visit in chicken.sort#topological-sort in k847 */
static void C_fcall f_2596(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_2596,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(10);
t7=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_2600,a[2]=t3,a[3]=t1,a[4]=t5,a[5]=t6,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=t2,a[9]=t4,tmp=(C_word)a,a+=10,tmp);
/* data-structures.scm:524: chicken.base#alist-ref */
t8=*((C_word*)lf[83]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=t3;
av2[3]=C_i_car(t6);
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}

/* k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_ccall f_2600(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_2600,c,av);}
a=C_alloc(12);
t2=C_eqp(t1,lf[68]);
if(C_truep(t2)){
t3=C_a_i_cons(&a,2,lf[69],lf[70]);
t4=C_a_i_cons(&a,2,lf[69],lf[71]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2649,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t4,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* data-structures.scm:531: scheme#reverse */
t6=*((C_word*)lf[80]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=C_eqp(t1,lf[81]);
if(C_truep(t3)){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2662,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[3],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[9])){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=((C_word*)t0)[9];
f_2662(2,av2);}}
else{
/* data-structures.scm:537: chicken.base#alist-ref */
t5=*((C_word*)lf[83]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[8];
av2[4]=((C_word*)t0)[6];
av2[5]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}}}}

/* k2635 in k2647 in k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_ccall f_2637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(31,c,2)))){
C_save_and_reclaim((void *)f_2637,c,av);}
a=C_alloc(31);
t2=C_a_i_cons(&a,2,lf[69],lf[73]);
t3=C_a_i_list(&a,8,((C_word*)t0)[2],lf[74],((C_word*)t0)[3],((C_word*)t0)[4],((C_word*)t0)[5],t1,t2,lf[75]);
t4=C_a_i_record3(&a,3,lf[76],lf[77],t3);
/* data-structures.scm:526: chicken.condition#abort */
t5=C_fast_retrieve(lf[78]);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[6];
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k2647 in k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_ccall f_2649(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_2649,c,av);}
a=C_alloc(16);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_list1(&a,1,t2);
t4=C_a_i_cons(&a,2,lf[69],lf[72]);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_2637,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t3,a[5]=t4,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* data-structures.scm:532: chicken.base#get-call-chain */
t6=C_fast_retrieve(lf[79]);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k2660 in k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_ccall f_2662(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_2662,c,av);}
a=C_alloc(20);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],lf[68]);
t3=C_u_i_car(((C_word*)t0)[3]);
t4=C_a_i_cons(&a,2,t2,t3);
t5=C_u_i_cdr(((C_word*)t0)[3]);
t6=C_a_i_cons(&a,2,t4,t5);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_2668,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=t8,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li51),tmp=(C_word)a,a+=9,tmp));
t10=((C_word*)t8)[1];
f_2668(t10,((C_word*)t0)[8],t1,t6);}

/* walk in k2660 in k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_fcall f_2668(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,6)))){
C_save_and_reclaim_args((void *)trf_2668,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_nullp(t2))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2682,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:541: chicken.base#alist-update! */
t5=C_fast_retrieve(lf[82]);{
C_word av2[6];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
av2[3]=lf[81];
av2[4]=C_i_car(t3);
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(6,av2);}}
else{
t4=C_i_car(t2);
t5=C_u_i_cdr(t2);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2704,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t5,tmp=(C_word)a,a+=5,tmp);
t7=C_a_i_cons(&a,2,t4,((C_word*)t0)[5]);
/* data-structures.scm:545: visit */
t8=((C_word*)((C_word*)t0)[6])[1];
f_2596(t8,t6,((C_word*)t0)[7],t4,C_SCHEME_FALSE,t7,t3);}}

/* k2680 in walk in k2660 in k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_ccall f_2682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_2682,c,av);}
a=C_alloc(6);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,t1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k2702 in walk in k2660 in k2598 in visit in chicken.sort#topological-sort in k847 */
static void C_ccall f_2704(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2704,c,av);}
/* data-structures.scm:544: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2668(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k2736 in chicken.sort#topological-sort in k847 */
static void C_ccall f_2738(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_2738,c,av);}
a=C_alloc(10);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2747,a[2]=t5,a[3]=((C_word*)t0)[3],a[4]=((C_word)li53),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_2747(t7,((C_word*)t0)[4],((C_word*)((C_word*)t0)[2])[1],t3);}

/* loop in k2736 in chicken.sort#topological-sort in k847 */
static void C_fcall f_2747(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,6)))){
C_save_and_reclaim_args((void *)trf_2747,4,t0,t1,t2,t3);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_i_cdr(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2768,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_i_caar(t2);
t7=C_u_i_car(t2);
/* data-structures.scm:564: visit */
t8=((C_word*)((C_word*)t0)[3])[1];
f_2596(t8,t5,t2,t6,C_u_i_cdr(t7),C_SCHEME_END_OF_LIST,t3);}}

/* k2766 in loop in k2736 in chicken.sort#topological-sort in k847 */
static void C_ccall f_2768(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2768,c,av);}
/* data-structures.scm:563: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_2747(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* foldl585 in chicken.sort#topological-sort in k847 */
static void C_fcall f_2785(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_2785,4,t0,t1,t2,t3);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2801,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li54),tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_2827,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* data-structures.scm:551: g592 */
t7=t5;
f_2801(t7,t6,t3,C_slot(t2,C_fix(0)));}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* g592 in foldl585 in chicken.sort#topological-sort in k847 */
static void C_fcall f_2801(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_2801,4,t0,t1,t2,t3);}
a=C_alloc(10);
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_2813,a[2]=t1,a[3]=t4,a[4]=t2,a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t6=C_u_i_cdr(t3);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_2819,a[2]=t5,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:554: chicken.base#alist-ref */
t8=*((C_word*)lf[83]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_u_i_car(t3);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}

/* k2811 in g592 in foldl585 in chicken.sort#topological-sort in k847 */
static void C_ccall f_2813(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_2813,c,av);}
/* data-structures.scm:552: chicken.base#alist-update! */
t2=C_fast_retrieve(lf[82]);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=((C_word*)t0)[4];
av2[5]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* k2817 in g592 in foldl585 in chicken.sort#topological-sort in k847 */
static void C_ccall f_2819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2819,c,av);}
if(C_truep(t1)){
/* data-structures.scm:553: scheme#append */
t2=*((C_word*)lf[66]+1);{
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
else{
/* data-structures.scm:553: scheme#append */
t2=*((C_word*)lf[66]+1);{
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
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k2825 in foldl585 in chicken.sort#topological-sort in k847 */
static void C_ccall f_2827(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_2827,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_2785(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k847 */
static void C_ccall f_849(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(91,c,7)))){
C_save_and_reclaim((void *)f_849,c,av);}
a=C_alloc(91);
t2=C_mutate((C_word*)lf[2]+1 /* (set! chicken.string#reverse-string-append ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_851,a[2]=((C_word)li2),tmp=(C_word)a,a+=3,tmp));
t3=C_mutate((C_word*)lf[4]+1 /* (set! chicken.string#reverse-list->string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_924,a[2]=((C_word)li3),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[6]+1 /* (set! chicken.string#->string ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_930,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[12]+1 /* (set! chicken.string#conc ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_975,a[2]=((C_word)li6),tmp=(C_word)a,a+=3,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1022,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp);
t7=C_mutate((C_word*)lf[16]+1 /* (set! ##sys#substring-index ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1096,a[2]=t6,a[3]=((C_word)li10),tmp=(C_word)a,a+=4,tmp));
t8=C_mutate((C_word*)lf[18]+1 /* (set! ##sys#substring-index-ci ...) */,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_1105,a[2]=t6,a[3]=((C_word)li12),tmp=(C_word)a,a+=4,tmp));
t9=C_mutate((C_word*)lf[20]+1 /* (set! chicken.string#substring-index ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1114,a[2]=((C_word)li13),tmp=(C_word)a,a+=3,tmp));
t10=C_mutate((C_word*)lf[21]+1 /* (set! chicken.string#substring-index-ci ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1129,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[22]+1 /* (set! chicken.string#string-compare3 ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1144,a[2]=((C_word)li15),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[24]+1 /* (set! chicken.string#string-compare3-ci ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1175,a[2]=((C_word)li16),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[26]+1 /* (set! ##sys#substring=? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1206,a[2]=((C_word)li17),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[29]+1 /* (set! chicken.string#substring=? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1266,a[2]=((C_word)li18),tmp=(C_word)a,a+=3,tmp));
t15=C_mutate((C_word*)lf[30]+1 /* (set! ##sys#substring-ci=? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1326,a[2]=((C_word)li19),tmp=(C_word)a,a+=3,tmp));
t16=C_mutate((C_word*)lf[32]+1 /* (set! chicken.string#substring-ci=? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1386,a[2]=((C_word)li20),tmp=(C_word)a,a+=3,tmp));
t17=C_mutate((C_word*)lf[33]+1 /* (set! chicken.string#string-split ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1446,a[2]=((C_word)li24),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[37]+1 /* (set! chicken.string#string-intersperse ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1580,a[2]=((C_word)li27),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[43]+1 /* (set! chicken.string#string-translate ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1682,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[49]+1 /* (set! chicken.string#string-translate* ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_1887,a[2]=((C_word)li36),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[53]+1 /* (set! chicken.string#string-chop ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2015,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp));
t22=C_mutate((C_word*)lf[55]+1 /* (set! chicken.string#string-chomp ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2079,a[2]=((C_word)li39),tmp=(C_word)a,a+=3,tmp));
t23=C_a_i_provide(&a,1,lf[58]);
t24=C_mutate((C_word*)lf[59]+1 /* (set! chicken.sort#sorted? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2118,a[2]=((C_word)li42),tmp=(C_word)a,a+=3,tmp));
t25=C_mutate((C_word*)lf[60]+1 /* (set! chicken.sort#merge ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2223,a[2]=((C_word)li44),tmp=(C_word)a,a+=3,tmp));
t26=C_mutate((C_word*)lf[61]+1 /* (set! chicken.sort#merge! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2314,a[2]=((C_word)li46),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate((C_word*)lf[62]+1 /* (set! chicken.sort#sort! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2438,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate((C_word*)lf[64]+1 /* (set! chicken.sort#sort ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2566,a[2]=((C_word)li50),tmp=(C_word)a,a+=3,tmp));
t29=C_mutate((C_word*)lf[67]+1 /* (set! chicken.sort#topological-sort ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_2593,a[2]=((C_word)li56),tmp=(C_word)a,a+=3,tmp));
t30=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t30;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t30+1)))(2,av2);}}

/* chicken.string#reverse-string-append in k847 */
static void C_ccall f_851(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_851,c,av);}
a=C_alloc(6);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_854,a[2]=t4,a[3]=((C_word)li1),tmp=(C_word)a,a+=4,tmp));
/* data-structures.scm:61: rev-string-append */
t6=((C_word*)t4)[1];
f_854(t6,t1,t2,C_fix(0));}

/* rev-string-append in chicken.string#reverse-string-append in k847 */
static void C_fcall f_854(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_854,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_car(t2);
t5=C_i_string_length(t4);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_868,a[2]=t3,a[3]=t5,a[4]=t4,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* data-structures.scm:53: rev-string-append */
t8=t6;
t9=C_u_i_cdr(t2);
t10=C_fixnum_plus(t3,t5);
t1=t8;
t2=t9;
t3=t10;
goto loop;}
else{
/* data-structures.scm:60: scheme#make-string */
t4=*((C_word*)lf[3]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k866 in rev-string-append in chicken.string#reverse-string-append in k847 */
static void C_ccall f_868(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_868,c,av);}
a=C_alloc(6);
t2=C_i_string_length(t1);
t3=C_fixnum_difference(t2,((C_word*)t0)[2]);
t4=C_fixnum_difference(t3,((C_word*)t0)[3]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_877,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t1,a[5]=((C_word)li0),tmp=(C_word)a,a+=6,tmp);
t6=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t6;
av2[1]=(
  f_877(t5,C_fix(0),t4)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* loop in k866 in rev-string-append in chicken.string#reverse-string-append in k847 */
static C_word C_fcall f_877(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_lessp(t1,((C_word*)t0)[2]))){
t3=C_i_string_ref(((C_word*)t0)[3],t1);
t4=C_i_string_set(((C_word*)t0)[4],t2,t3);
t6=C_fixnum_plus(t1,C_fix(1));
t7=C_fixnum_plus(t2,C_fix(1));
t1=t6;
t2=t7;
goto loop;}
else{
return(((C_word*)t0)[4]);}}

/* chicken.string#reverse-list->string in k847 */
static void C_ccall f_924(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_924,c,av);}
/* data-structures.scm:64: ##sys#reverse-list->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[5]);
C_word *av2=av;
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}

/* chicken.string#->string in k847 */
static void C_ccall f_930(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_930,c,av);}
a=C_alloc(4);
if(C_truep(C_i_stringp(t2))){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(t2))){
/* data-structures.scm:71: scheme#symbol->string */
t3=*((C_word*)lf[7]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
if(C_truep(C_charp(t2))){
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_string(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_numberp(t2))){
/* data-structures.scm:73: ##sys#number->string */
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[8]);
C_word *av2=av;
av2[0]=*((C_word*)lf[8]+1);
av2[1]=t1;
av2[2]=t2;
tp(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_967,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:75: chicken.base#open-output-string */
t4=C_fast_retrieve(lf[11]);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}}}}

/* k965 in chicken.string#->string in k847 */
static void C_ccall f_967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_967,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_970,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* data-structures.scm:76: scheme#display */
t3=*((C_word*)lf[10]+1);{
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

/* k968 in k965 in chicken.string#->string in k847 */
static void C_ccall f_970(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_970,c,av);}
/* data-structures.scm:77: chicken.base#get-output-string */
t2=C_fast_retrieve(lf[9]);{
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

/* chicken.string#conc in k847 */
static void C_ccall f_975(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +17,c,3)))){
C_save_and_reclaim((void*)f_975,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+17);
t2=C_build_rest(&a,c,2,av);
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
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=*((C_word*)lf[6]+1);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_986,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_988,a[2]=t5,a[3]=t10,a[4]=t7,a[5]=t6,a[6]=((C_word)li5),tmp=(C_word)a,a+=7,tmp));
t12=((C_word*)t10)[1];
f_988(t12,t8,t2);}

/* k984 in chicken.string#conc in k847 */
static void C_ccall f_986(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_986,c,av);}{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[13]+1);
av2[3]=t1;
C_apply(4,av2);}}

/* map-loop80 in chicken.string#conc in k847 */
static void C_fcall f_988(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_988,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_1013,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* data-structures.scm:81: g86 */
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

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("data-structures"));
C_check_nursery_minimum(C_calculate_demand(19,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void*)C_data_2dstructures_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(576))){
C_save(t1);
C_rereclaim2(576*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(19);
C_initialize_lf(lf,85);
lf[0]=C_h_intern(&lf[0],15, C_text("data-structures"));
lf[1]=C_h_intern(&lf[1],15, C_text("chicken.string#"));
lf[2]=C_h_intern(&lf[2],36, C_text("chicken.string#reverse-string-append"));
lf[3]=C_h_intern(&lf[3],18, C_text("scheme#make-string"));
lf[4]=C_h_intern(&lf[4],35, C_text("chicken.string#reverse-list->string"));
lf[5]=C_h_intern(&lf[5],26, C_text("##sys#reverse-list->string"));
lf[6]=C_h_intern(&lf[6],23, C_text("chicken.string#->string"));
lf[7]=C_h_intern(&lf[7],21, C_text("scheme#symbol->string"));
lf[8]=C_h_intern(&lf[8],20, C_text("##sys#number->string"));
lf[9]=C_h_intern(&lf[9],30, C_text("chicken.base#get-output-string"));
lf[10]=C_h_intern(&lf[10],14, C_text("scheme#display"));
lf[11]=C_h_intern(&lf[11],31, C_text("chicken.base#open-output-string"));
lf[12]=C_h_intern(&lf[12],19, C_text("chicken.string#conc"));
lf[13]=C_h_intern(&lf[13],20, C_text("scheme#string-append"));
lf[14]=C_h_intern(&lf[14],16, C_text("##sys#error-hook"));
lf[15]=C_h_intern(&lf[15],18, C_text("##sys#check-fixnum"));
lf[16]=C_h_intern(&lf[16],21, C_text("##sys#substring-index"));
lf[17]=C_h_intern(&lf[17],15, C_text("substring-index"));
lf[18]=C_h_intern(&lf[18],24, C_text("##sys#substring-index-ci"));
lf[19]=C_h_intern(&lf[19],18, C_text("substring-index-ci"));
lf[20]=C_h_intern(&lf[20],30, C_text("chicken.string#substring-index"));
lf[21]=C_h_intern(&lf[21],33, C_text("chicken.string#substring-index-ci"));
lf[22]=C_h_intern(&lf[22],30, C_text("chicken.string#string-compare3"));
lf[23]=C_h_intern(&lf[23],15, C_text("string-compare3"));
lf[24]=C_h_intern(&lf[24],33, C_text("chicken.string#string-compare3-ci"));
lf[25]=C_h_intern(&lf[25],18, C_text("string-compare3-ci"));
lf[26]=C_h_intern(&lf[26],17, C_text("##sys#substring=\077"));
lf[27]=C_h_intern(&lf[27],11, C_text("substring=\077"));
lf[28]=C_h_intern(&lf[28],17, C_text("##sys#check-range"));
lf[29]=C_h_intern(&lf[29],26, C_text("chicken.string#substring=\077"));
lf[30]=C_h_intern(&lf[30],20, C_text("##sys#substring-ci=\077"));
lf[31]=C_h_intern(&lf[31],14, C_text("substring-ci=\077"));
lf[32]=C_h_intern(&lf[32],29, C_text("chicken.string#substring-ci=\077"));
lf[33]=C_h_intern(&lf[33],27, C_text("chicken.string#string-split"));
lf[34]=C_h_intern(&lf[34],12, C_text("string-split"));
lf[35]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003\011\012 "));
lf[36]=C_h_intern(&lf[36],15, C_text("##sys#substring"));
lf[37]=C_h_intern(&lf[37],33, C_text("chicken.string#string-intersperse"));
lf[38]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[39]=C_h_intern(&lf[39],18, C_text("string-intersperse"));
lf[40]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[41]=C_h_intern(&lf[41],21, C_text("##sys#allocate-vector"));
lf[42]=C_h_intern(&lf[42],29, C_text("##sys#error-not-a-proper-list"));
lf[43]=C_h_intern(&lf[43],31, C_text("chicken.string#string-translate"));
lf[44]=C_h_intern(&lf[44],16, C_text("string-translate"));
lf[45]=C_h_intern(&lf[45],11, C_text("##sys#error"));
lf[46]=C_decode_literal(C_heaptop,C_text("\376B\000\000\037invalid translation destination"));
lf[47]=C_h_intern(&lf[47],17, C_text("##sys#make-string"));
lf[48]=C_h_intern(&lf[48],18, C_text("##sys#list->string"));
lf[49]=C_h_intern(&lf[49],32, C_text("chicken.string#string-translate\052"));
lf[50]=C_h_intern(&lf[50],17, C_text("string-translate\052"));
lf[51]=C_h_intern(&lf[51],23, C_text("##sys#fragments->string"));
lf[52]=C_h_intern(&lf[52],18, C_text("##sys#fast-reverse"));
lf[53]=C_h_intern(&lf[53],26, C_text("chicken.string#string-chop"));
lf[54]=C_h_intern(&lf[54],11, C_text("string-chop"));
lf[55]=C_h_intern(&lf[55],27, C_text("chicken.string#string-chomp"));
lf[56]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[57]=C_h_intern(&lf[57],12, C_text("string-chomp"));
lf[58]=C_h_intern(&lf[58],13, C_text("chicken.sort#"));
lf[59]=C_h_intern(&lf[59],20, C_text("chicken.sort#sorted\077"));
lf[60]=C_h_intern(&lf[60],18, C_text("chicken.sort#merge"));
lf[61]=C_h_intern(&lf[61],19, C_text("chicken.sort#merge!"));
lf[62]=C_h_intern(&lf[62],18, C_text("chicken.sort#sort!"));
lf[63]=C_h_intern(&lf[63],19, C_text("scheme#vector->list"));
lf[64]=C_h_intern(&lf[64],17, C_text("chicken.sort#sort"));
lf[65]=C_h_intern(&lf[65],19, C_text("scheme#list->vector"));
lf[66]=C_h_intern(&lf[66],13, C_text("scheme#append"));
lf[67]=C_h_intern(&lf[67],29, C_text("chicken.sort#topological-sort"));
lf[68]=C_h_intern(&lf[68],4, C_text("grey"));
lf[69]=C_h_intern(&lf[69],3, C_text("exn"));
lf[70]=C_h_intern(&lf[70],7, C_text("message"));
lf[71]=C_h_intern(&lf[71],9, C_text("arguments"));
lf[72]=C_h_intern(&lf[72],10, C_text("call-chain"));
lf[73]=C_h_intern(&lf[73],8, C_text("location"));
lf[74]=C_decode_literal(C_heaptop,C_text("\376B\000\000\016cycle detected"));
lf[75]=C_h_intern(&lf[75],16, C_text("topological-sort"));
lf[76]=C_h_intern(&lf[76],9, C_text("condition"));
lf[77]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001exn\376\003\000\000\002\376\001\000\000\007\001runtime\376\003\000\000\002\376\001\000\000\005\001cycle\376\377\016"));
lf[78]=C_h_intern(&lf[78],23, C_text("chicken.condition#abort"));
lf[79]=C_h_intern(&lf[79],27, C_text("chicken.base#get-call-chain"));
lf[80]=C_h_intern(&lf[80],14, C_text("scheme#reverse"));
lf[81]=C_h_intern(&lf[81],5, C_text("black"));
lf[82]=C_h_intern(&lf[82],26, C_text("chicken.base#alist-update!"));
lf[83]=C_h_intern(&lf[83],22, C_text("chicken.base#alist-ref"));
lf[84]=C_h_intern(&lf[84],5, C_text("foldl"));
C_register_lf2(lf,85,create_ptable());{}
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_849,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[118] = {
{C_text("f_1013:data_2dstructures_2escm"),(void*)f_1013},
{C_text("f_1022:data_2dstructures_2escm"),(void*)f_1022},
{C_text("f_1041:data_2dstructures_2escm"),(void*)f_1041},
{C_text("f_1064:data_2dstructures_2escm"),(void*)f_1064},
{C_text("f_1077:data_2dstructures_2escm"),(void*)f_1077},
{C_text("f_1096:data_2dstructures_2escm"),(void*)f_1096},
{C_text("f_1102:data_2dstructures_2escm"),(void*)f_1102},
{C_text("f_1105:data_2dstructures_2escm"),(void*)f_1105},
{C_text("f_1111:data_2dstructures_2escm"),(void*)f_1111},
{C_text("f_1114:data_2dstructures_2escm"),(void*)f_1114},
{C_text("f_1129:data_2dstructures_2escm"),(void*)f_1129},
{C_text("f_1144:data_2dstructures_2escm"),(void*)f_1144},
{C_text("f_1175:data_2dstructures_2escm"),(void*)f_1175},
{C_text("f_1206:data_2dstructures_2escm"),(void*)f_1206},
{C_text("f_1216:data_2dstructures_2escm"),(void*)f_1216},
{C_text("f_1219:data_2dstructures_2escm"),(void*)f_1219},
{C_text("f_1228:data_2dstructures_2escm"),(void*)f_1228},
{C_text("f_1266:data_2dstructures_2escm"),(void*)f_1266},
{C_text("f_1326:data_2dstructures_2escm"),(void*)f_1326},
{C_text("f_1336:data_2dstructures_2escm"),(void*)f_1336},
{C_text("f_1339:data_2dstructures_2escm"),(void*)f_1339},
{C_text("f_1348:data_2dstructures_2escm"),(void*)f_1348},
{C_text("f_1386:data_2dstructures_2escm"),(void*)f_1386},
{C_text("f_1446:data_2dstructures_2escm"),(void*)f_1446},
{C_text("f_1467:data_2dstructures_2escm"),(void*)f_1467},
{C_text("f_1482:data_2dstructures_2escm"),(void*)f_1482},
{C_text("f_1487:data_2dstructures_2escm"),(void*)f_1487},
{C_text("f_1497:data_2dstructures_2escm"),(void*)f_1497},
{C_text("f_1514:data_2dstructures_2escm"),(void*)f_1514},
{C_text("f_1553:data_2dstructures_2escm"),(void*)f_1553},
{C_text("f_1580:data_2dstructures_2escm"),(void*)f_1580},
{C_text("f_1598:data_2dstructures_2escm"),(void*)f_1598},
{C_text("f_1608:data_2dstructures_2escm"),(void*)f_1608},
{C_text("f_1613:data_2dstructures_2escm"),(void*)f_1613},
{C_text("f_1682:data_2dstructures_2escm"),(void*)f_1682},
{C_text("f_1685:data_2dstructures_2escm"),(void*)f_1685},
{C_text("f_1690:data_2dstructures_2escm"),(void*)f_1690},
{C_text("f_1696:data_2dstructures_2escm"),(void*)f_1696},
{C_text("f_1720:data_2dstructures_2escm"),(void*)f_1720},
{C_text("f_1723:data_2dstructures_2escm"),(void*)f_1723},
{C_text("f_1735:data_2dstructures_2escm"),(void*)f_1735},
{C_text("f_1740:data_2dstructures_2escm"),(void*)f_1740},
{C_text("f_1759:data_2dstructures_2escm"),(void*)f_1759},
{C_text("f_1862:data_2dstructures_2escm"),(void*)f_1862},
{C_text("f_1879:data_2dstructures_2escm"),(void*)f_1879},
{C_text("f_1887:data_2dstructures_2escm"),(void*)f_1887},
{C_text("f_1899:data_2dstructures_2escm"),(void*)f_1899},
{C_text("f_1913:data_2dstructures_2escm"),(void*)f_1913},
{C_text("f_1927:data_2dstructures_2escm"),(void*)f_1927},
{C_text("f_1932:data_2dstructures_2escm"),(void*)f_1932},
{C_text("f_1972:data_2dstructures_2escm"),(void*)f_1972},
{C_text("f_1998:data_2dstructures_2escm"),(void*)f_1998},
{C_text("f_2015:data_2dstructures_2escm"),(void*)f_2015},
{C_text("f_2022:data_2dstructures_2escm"),(void*)f_2022},
{C_text("f_2030:data_2dstructures_2escm"),(void*)f_2030},
{C_text("f_2050:data_2dstructures_2escm"),(void*)f_2050},
{C_text("f_2061:data_2dstructures_2escm"),(void*)f_2061},
{C_text("f_2065:data_2dstructures_2escm"),(void*)f_2065},
{C_text("f_2079:data_2dstructures_2escm"),(void*)f_2079},
{C_text("f_2118:data_2dstructures_2escm"),(void*)f_2118},
{C_text("f_2145:data_2dstructures_2escm"),(void*)f_2145},
{C_text("f_2155:data_2dstructures_2escm"),(void*)f_2155},
{C_text("f_2193:data_2dstructures_2escm"),(void*)f_2193},
{C_text("f_2217:data_2dstructures_2escm"),(void*)f_2217},
{C_text("f_2223:data_2dstructures_2escm"),(void*)f_2223},
{C_text("f_2253:data_2dstructures_2escm"),(void*)f_2253},
{C_text("f_2260:data_2dstructures_2escm"),(void*)f_2260},
{C_text("f_2280:data_2dstructures_2escm"),(void*)f_2280},
{C_text("f_2306:data_2dstructures_2escm"),(void*)f_2306},
{C_text("f_2314:data_2dstructures_2escm"),(void*)f_2314},
{C_text("f_2317:data_2dstructures_2escm"),(void*)f_2317},
{C_text("f_2324:data_2dstructures_2escm"),(void*)f_2324},
{C_text("f_2392:data_2dstructures_2escm"),(void*)f_2392},
{C_text("f_2395:data_2dstructures_2escm"),(void*)f_2395},
{C_text("f_2413:data_2dstructures_2escm"),(void*)f_2413},
{C_text("f_2438:data_2dstructures_2escm"),(void*)f_2438},
{C_text("f_2441:data_2dstructures_2escm"),(void*)f_2441},
{C_text("f_2454:data_2dstructures_2escm"),(void*)f_2454},
{C_text("f_2460:data_2dstructures_2escm"),(void*)f_2460},
{C_text("f_2492:data_2dstructures_2escm"),(void*)f_2492},
{C_text("f_2526:data_2dstructures_2escm"),(void*)f_2526},
{C_text("f_2533:data_2dstructures_2escm"),(void*)f_2533},
{C_text("f_2535:data_2dstructures_2escm"),(void*)f_2535},
{C_text("f_2566:data_2dstructures_2escm"),(void*)f_2566},
{C_text("f_2580:data_2dstructures_2escm"),(void*)f_2580},
{C_text("f_2584:data_2dstructures_2escm"),(void*)f_2584},
{C_text("f_2591:data_2dstructures_2escm"),(void*)f_2591},
{C_text("f_2593:data_2dstructures_2escm"),(void*)f_2593},
{C_text("f_2596:data_2dstructures_2escm"),(void*)f_2596},
{C_text("f_2600:data_2dstructures_2escm"),(void*)f_2600},
{C_text("f_2637:data_2dstructures_2escm"),(void*)f_2637},
{C_text("f_2649:data_2dstructures_2escm"),(void*)f_2649},
{C_text("f_2662:data_2dstructures_2escm"),(void*)f_2662},
{C_text("f_2668:data_2dstructures_2escm"),(void*)f_2668},
{C_text("f_2682:data_2dstructures_2escm"),(void*)f_2682},
{C_text("f_2704:data_2dstructures_2escm"),(void*)f_2704},
{C_text("f_2738:data_2dstructures_2escm"),(void*)f_2738},
{C_text("f_2747:data_2dstructures_2escm"),(void*)f_2747},
{C_text("f_2768:data_2dstructures_2escm"),(void*)f_2768},
{C_text("f_2785:data_2dstructures_2escm"),(void*)f_2785},
{C_text("f_2801:data_2dstructures_2escm"),(void*)f_2801},
{C_text("f_2813:data_2dstructures_2escm"),(void*)f_2813},
{C_text("f_2819:data_2dstructures_2escm"),(void*)f_2819},
{C_text("f_2827:data_2dstructures_2escm"),(void*)f_2827},
{C_text("f_849:data_2dstructures_2escm"),(void*)f_849},
{C_text("f_851:data_2dstructures_2escm"),(void*)f_851},
{C_text("f_854:data_2dstructures_2escm"),(void*)f_854},
{C_text("f_868:data_2dstructures_2escm"),(void*)f_868},
{C_text("f_877:data_2dstructures_2escm"),(void*)f_877},
{C_text("f_924:data_2dstructures_2escm"),(void*)f_924},
{C_text("f_930:data_2dstructures_2escm"),(void*)f_930},
{C_text("f_967:data_2dstructures_2escm"),(void*)f_967},
{C_text("f_970:data_2dstructures_2escm"),(void*)f_970},
{C_text("f_975:data_2dstructures_2escm"),(void*)f_975},
{C_text("f_986:data_2dstructures_2escm"),(void*)f_986},
{C_text("f_988:data_2dstructures_2escm"),(void*)f_988},
{C_text("toplevel:data_2dstructures_2escm"),(void*)C_data_2dstructures_toplevel},
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
S|  chicken.base#foldl		1
S|  scheme#map		1
o|eliminated procedure checks: 19 
o|eliminated procedure checks: 1 
o|eliminated procedure checks: 1 
o|eliminated procedure checks: 1 
o|eliminated procedure checks: 1 
o|specializations:
o|  1 (scheme#cdar (pair pair *))
o|  2 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  1 (scheme#+ fixnum fixnum)
o|  4 (scheme#set-cdr! pair *)
o|  1 (scheme#- fixnum fixnum)
o|  1 (scheme#<= fixnum fixnum)
o|  1 (scheme#vector-length vector)
o|  1 (scheme#make-string fixnum)
o|  1 (scheme#length list)
o|  1 (##sys#check-list (or pair list) *)
o|  23 (scheme#cdr pair)
o|  4 (scheme#car pair)
(o e)|safe calls: 330 
o|safe globals: (chicken.sort#topological-sort chicken.sort#sort chicken.sort#sort! chicken.sort#merge! chicken.sort#merge chicken.sort#sorted? chicken.string#string-chomp chicken.string#string-chop chicken.string#string-translate* chicken.string#string-translate chicken.string#string-intersperse chicken.string#string-split chicken.string#substring-ci=? ##sys#substring-ci=? chicken.string#substring=? ##sys#substring=? chicken.string#string-compare3-ci chicken.string#string-compare3 chicken.string#substring-index-ci chicken.string#substring-index ##sys#substring-index-ci ##sys#substring-index chicken.string#conc chicken.string#->string chicken.string#reverse-list->string chicken.string#reverse-string-append) 
o|inlining procedure: k856 
o|inlining procedure: k879 
o|inlining procedure: k879 
o|inlining procedure: k856 
o|inlining procedure: k932 
o|inlining procedure: k932 
o|inlining procedure: k947 
o|inlining procedure: k947 
o|inlining procedure: k990 
o|inlining procedure: k990 
o|inlining procedure: k1042 
o|inlining procedure: k1054 
o|inlining procedure: k1066 
o|inlining procedure: k1066 
o|inlining procedure: k1054 
o|inlining procedure: k1042 
o|inlining procedure: k1165 
o|inlining procedure: k1165 
o|inlining procedure: k1196 
o|inlining procedure: k1196 
o|inlining procedure: k1223 
o|inlining procedure: k1223 
o|inlining procedure: k1343 
o|inlining procedure: k1343 
o|inlining procedure: k1472 
o|inlining procedure: k1472 
o|inlining procedure: k1489 
o|inlining procedure: k1489 
o|inlining procedure: k1516 
o|inlining procedure: k1516 
o|inlining procedure: k1538 
o|inlining procedure: k1538 
o|inlining procedure: k1600 
o|inlining procedure: k1627 
o|inlining procedure: k1627 
o|inlining procedure: k1600 
o|inlining procedure: k1698 
o|inlining procedure: k1698 
o|inlining procedure: k1742 
o|inlining procedure: k1742 
o|inlining procedure: k1777 
o|inlining procedure: k1777 
o|inlining procedure: k1807 
o|inlining procedure: k1807 
o|inlining procedure: k1841 
o|inlining procedure: k1841 
o|inlining procedure: k1867 
o|inlining procedure: k1867 
o|inlining procedure: k1901 
o|inlining procedure: k1915 
o|inlining procedure: k1915 
o|inlining procedure: k1901 
o|inlining procedure: k1934 
o|inlining procedure: k1934 
o|inlining procedure: k2032 
o|inlining procedure: k2032 
o|inlining procedure: k2099 
o|inlining procedure: k2099 
o|inlining procedure: k2120 
o|inlining procedure: k2120 
o|inlining procedure: k2135 
o|inlining procedure: k2135 
o|inlining procedure: k2147 
o|inlining procedure: k2147 
o|substituted constant variable: a2179 
o|substituted constant variable: a2181 
o|inlining procedure: k2198 
o|inlining procedure: k2198 
o|inlining procedure: k2225 
o|inlining procedure: k2225 
o|inlining procedure: k2255 
o|inlining procedure: k2255 
o|inlining procedure: k2319 
o|inlining procedure: k2319 
o|inlining procedure: k2375 
o|inlining procedure: k2375 
o|inlining procedure: k2387 
o|inlining procedure: k2387 
o|inlining procedure: k2443 
o|inlining procedure: k2443 
o|inlining procedure: k2501 
o|inlining procedure: k2501 
o|inlining procedure: k2514 
o|inlining procedure: k2537 
o|inlining procedure: k2537 
o|substituted constant variable: a2553 
o|inlining procedure: k2514 
o|inlining procedure: k2568 
o|inlining procedure: k2568 
o|inlining procedure: k2601 
o|inlining procedure: k2601 
o|inlining procedure: k2670 
o|inlining procedure: k2670 
o|substituted constant variable: a2725 
o|substituted constant variable: a2727 
o|inlining procedure: k2749 
o|inlining procedure: k2749 
o|inlining procedure: k2787 
o|inlining procedure: k2820 
o|inlining procedure: k2820 
o|inlining procedure: k2787 
o|substituted constant variable: g584587 
o|replaced variables: 541 
o|removed binding forms: 116 
o|substituted constant variable: r10672844 
o|substituted constant variable: r10552846 
o|converted assignments to bindings: (add256) 
o|substituted constant variable: r16992874 
o|converted assignments to bindings: (instring334) 
o|substituted constant variable: r20332894 
o|substituted constant variable: r21212898 
o|substituted constant variable: r21362900 
o|substituted constant variable: r25022919 
o|substituted constant variable: r28212935 
o|substituted constant variable: r28212935 
o|converted assignments to bindings: (traverse104) 
o|simplifications: ((let . 3)) 
o|replaced variables: 28 
o|removed binding forms: 443 
o|inlining procedure: k1116 
o|inlining procedure: k1131 
o|inlining procedure: k1283 
o|inlining procedure: k1403 
o|inlining procedure: k1495 
o|removed binding forms: 38 
o|substituted constant variable: r11173031 
o|substituted constant variable: r11323032 
o|inlining procedure: k2102 
o|inlining procedure: k2102 
o|removed binding forms: 3 
o|substituted constant variable: r21033100 
o|simplifications: ((let . 1)) 
o|removed binding forms: 3 
o|removed conditional forms: 1 
o|removed binding forms: 1 
o|simplifications: ((let . 19) (if . 26) (##core#call . 302)) 
o|  call simplifications:
o|    scheme#caar
o|    ##sys#cons	4
o|    ##sys#list
o|    ##sys#make-structure
o|    scheme#length
o|    scheme#vector-length
o|    scheme#vector-set!
o|    scheme#>
o|    scheme#cddr
o|    scheme#set-car!	2
o|    scheme#quotient
o|    scheme#-
o|    scheme#set-cdr!	4
o|    scheme#vector?	3
o|    scheme#vector-ref	2
o|    scheme#+
o|    scheme#=	4
o|    scheme#list	4
o|    chicken.fixnum#fx<=	4
o|    scheme#list->string	2
o|    scheme#not	3
o|    ##sys#check-list	3
o|    scheme#cadr	2
o|    scheme#eq?	5
o|    scheme#cdr	10
o|    chicken.fixnum#fxmin	2
o|    scheme#null?	33
o|    scheme#car	29
o|    ##sys#check-string	21
o|    ##sys#size	27
o|    chicken.fixnum#fx=	4
o|    chicken.fixnum#fx>=	10
o|    chicken.fixnum#fx>	5
o|    scheme#cons	21
o|    ##sys#setslot	6
o|    ##sys#slot	10
o|    scheme#apply
o|    scheme#string?	2
o|    scheme#symbol?
o|    scheme#char?	4
o|    scheme#number?
o|    scheme#string
o|    scheme#pair?	6
o|    scheme#string-length	4
o|    chicken.fixnum#fx-	12
o|    chicken.fixnum#fx<	4
o|    scheme#string-ref
o|    scheme#string-set!
o|    chicken.fixnum#fx+	33
o|contracted procedure: k859 
o|contracted procedure: k863 
o|contracted procedure: k908 
o|contracted procedure: k904 
o|contracted procedure: k873 
o|contracted procedure: k882 
o|contracted procedure: k900 
o|contracted procedure: k885 
o|contracted procedure: k892 
o|contracted procedure: k896 
o|contracted procedure: k914 
o|contracted procedure: k935 
o|contracted procedure: k941 
o|contracted procedure: k950 
o|contracted procedure: k959 
o|contracted procedure: k981 
o|contracted procedure: k993 
o|contracted procedure: k996 
o|contracted procedure: k999 
o|contracted procedure: k1007 
o|contracted procedure: k1015 
o|contracted procedure: k1024 
o|contracted procedure: k1027 
o|contracted procedure: k1030 
o|contracted procedure: k1033 
o|contracted procedure: k1036 
o|contracted procedure: k1089 
o|contracted procedure: k1045 
o|contracted procedure: k1051 
o|contracted procedure: k1057 
o|contracted procedure: k1069 
o|contracted procedure: k1082 
o|contracted procedure: k1122 
o|contracted procedure: k1116 
o|contracted procedure: k1137 
o|contracted procedure: k1131 
o|contracted procedure: k1146 
o|contracted procedure: k1149 
o|contracted procedure: k1152 
o|contracted procedure: k1155 
o|contracted procedure: k1158 
o|contracted procedure: k1171 
o|contracted procedure: k1162 
o|contracted procedure: k1168 
o|contracted procedure: k1177 
o|contracted procedure: k1180 
o|contracted procedure: k1183 
o|contracted procedure: k1186 
o|contracted procedure: k1189 
o|contracted procedure: k1202 
o|contracted procedure: k1193 
o|contracted procedure: k1199 
o|contracted procedure: k1208 
o|contracted procedure: k1211 
o|contracted procedure: k1246 
o|contracted procedure: k1234 
o|contracted procedure: k1242 
o|contracted procedure: k1238 
o|contracted procedure: k1220 
o|contracted procedure: k1230 
o|contracted procedure: k1254 
o|contracted procedure: k1250 
o|contracted procedure: k1262 
o|contracted procedure: k1258 
o|contracted procedure: k1319 
o|contracted procedure: k1268 
o|contracted procedure: k1313 
o|contracted procedure: k1271 
o|contracted procedure: k1307 
o|contracted procedure: k1274 
o|contracted procedure: k1301 
o|contracted procedure: k1277 
o|contracted procedure: k1295 
o|contracted procedure: k1280 
o|contracted procedure: k1289 
o|contracted procedure: k1283 
o|contracted procedure: k1328 
o|contracted procedure: k1331 
o|contracted procedure: k1366 
o|contracted procedure: k1354 
o|contracted procedure: k1362 
o|contracted procedure: k1358 
o|contracted procedure: k1340 
o|contracted procedure: k1350 
o|contracted procedure: k1374 
o|contracted procedure: k1370 
o|contracted procedure: k1382 
o|contracted procedure: k1378 
o|contracted procedure: k1439 
o|contracted procedure: k1388 
o|contracted procedure: k1433 
o|contracted procedure: k1391 
o|contracted procedure: k1427 
o|contracted procedure: k1394 
o|contracted procedure: k1421 
o|contracted procedure: k1397 
o|contracted procedure: k1415 
o|contracted procedure: k1400 
o|contracted procedure: k1409 
o|contracted procedure: k1403 
o|contracted procedure: k1448 
o|contracted procedure: k1573 
o|contracted procedure: k1451 
o|contracted procedure: k1565 
o|contracted procedure: k1454 
o|contracted procedure: k1457 
o|contracted procedure: k1460 
o|contracted procedure: k1463 
o|contracted procedure: k1469 
o|contracted procedure: k1472 
o|contracted procedure: k1492 
o|contracted procedure: k1501 
o|contracted procedure: k1504 
o|contracted procedure: k1519 
o|contracted procedure: k1526 
o|contracted procedure: k1532 
o|contracted procedure: k1535 
o|contracted procedure: k1541 
o|contracted procedure: k1544 
o|contracted procedure: k1561 
o|contracted procedure: k1675 
o|contracted procedure: k1582 
o|contracted procedure: k1585 
o|contracted procedure: k1588 
o|contracted procedure: k1591 
o|contracted procedure: k1615 
o|contracted procedure: k1618 
o|contracted procedure: k1621 
o|contracted procedure: k1624 
o|contracted procedure: k1634 
o|contracted procedure: k1638 
o|contracted procedure: k1644 
o|contracted procedure: k1647 
o|contracted procedure: k1650 
o|contracted procedure: k1657 
o|contracted procedure: k1665 
o|contracted procedure: k1669 
o|contracted procedure: k1661 
o|contracted procedure: k1687 
o|contracted procedure: k1701 
o|contracted procedure: k1707 
o|contracted procedure: k1714 
o|contracted procedure: k1829 
o|contracted procedure: k1724 
o|contracted procedure: k1727 
o|contracted procedure: k1730 
o|contracted procedure: k1745 
o|contracted procedure: k1751 
o|contracted procedure: k1763 
o|contracted procedure: k1770 
o|contracted procedure: k1774 
o|contracted procedure: k1780 
o|contracted procedure: k1787 
o|contracted procedure: k1793 
o|contracted procedure: k1800 
o|contracted procedure: k1804 
o|contracted procedure: k1810 
o|contracted procedure: k1821 
o|contracted procedure: k1825 
o|contracted procedure: k1835 
o|contracted procedure: k1838 
o|contracted procedure: k1844 
o|contracted procedure: k1850 
o|contracted procedure: k1856 
o|contracted procedure: k1859 
o|contracted procedure: k1870 
o|contracted procedure: k1880 
o|contracted procedure: k1889 
o|contracted procedure: k1892 
o|contracted procedure: k1895 
o|contracted procedure: k1904 
o|contracted procedure: k1918 
o|contracted procedure: k1915 
o|contracted procedure: k1937 
o|contracted procedure: k1944 
o|contracted procedure: k1948 
o|contracted procedure: k1951 
o|contracted procedure: k1954 
o|contracted procedure: k1957 
o|contracted procedure: k2008 
o|contracted procedure: k2004 
o|contracted procedure: k1964 
o|contracted procedure: k1967 
o|contracted procedure: k1985 
o|contracted procedure: k1977 
o|contracted procedure: k1981 
o|contracted procedure: k1988 
o|contracted procedure: k1992 
o|contracted procedure: k2017 
o|contracted procedure: k2023 
o|contracted procedure: k2035 
o|contracted procedure: k2041 
o|contracted procedure: k2052 
o|contracted procedure: k2067 
o|contracted procedure: k2071 
o|contracted procedure: k2075 
o|contracted procedure: k2111 
o|contracted procedure: k2081 
o|contracted procedure: k2084 
o|contracted procedure: k2087 
o|contracted procedure: k2090 
o|contracted procedure: k2093 
o|contracted procedure: k2096 
o|contracted procedure: k2108 
o|contracted procedure: k2123 
o|contracted procedure: k2129 
o|contracted procedure: k2132 
o|contracted procedure: k2138 
o|contracted procedure: k2150 
o|contracted procedure: k2163 
o|contracted procedure: k2170 
o|contracted procedure: k2174 
o|contracted procedure: k2187 
o|contracted procedure: k2195 
o|contracted procedure: k2204 
o|contracted procedure: k2219 
o|contracted procedure: k2228 
o|contracted procedure: k2234 
o|contracted procedure: k2241 
o|contracted procedure: k2247 
o|contracted procedure: k2264 
o|contracted procedure: k2271 
o|contracted procedure: k2282 
o|contracted procedure: k2290 
o|contracted procedure: k2297 
o|contracted procedure: k2308 
o|contracted procedure: k2325 
o|contracted procedure: k2331 
o|contracted procedure: k2346 
o|contracted procedure: k2352 
o|contracted procedure: k2368 
o|contracted procedure: k2372 
o|contracted procedure: k2378 
o|contracted procedure: k2384 
o|contracted procedure: k2396 
o|inlining procedure: k2393 
o|contracted procedure: k2414 
o|inlining procedure: k2411 
o|contracted procedure: k2430 
o|contracted procedure: k2434 
o|contracted procedure: k2446 
o|contracted procedure: k2449 
o|contracted procedure: k2455 
o|contracted procedure: k2467 
o|contracted procedure: k2470 
o|contracted procedure: k2473 
o|contracted procedure: k2477 
o|contracted procedure: k2487 
o|contracted procedure: k2483 
o|contracted procedure: k2493 
o|contracted procedure: k2504 
o|contracted procedure: k2508 
o|contracted procedure: k2511 
o|contracted procedure: k2517 
o|contracted procedure: k2520 
o|contracted procedure: k2540 
o|contracted procedure: k2555 
o|contracted procedure: k2543 
o|contracted procedure: k2562 
o|contracted procedure: k2571 
o|contracted procedure: k2604 
o|contracted procedure: k2619 
o|contracted procedure: k2623 
o|contracted procedure: k2643 
o|contracted procedure: k2627 
o|contracted procedure: k2631 
o|contracted procedure: k2639 
o|contracted procedure: k2615 
o|contracted procedure: k2611 
o|contracted procedure: k2653 
o|contracted procedure: k2716 
o|contracted procedure: k2710 
o|contracted procedure: k2664 
o|contracted procedure: k2673 
o|contracted procedure: k2684 
o|contracted procedure: k2690 
o|contracted procedure: k2693 
o|contracted procedure: k2706 
o|contracted procedure: k2729 
o|contracted procedure: k2733 
o|contracted procedure: k2777 
o|contracted procedure: k2781 
o|contracted procedure: k2743 
o|contracted procedure: k2752 
o|contracted procedure: k2762 
o|contracted procedure: k2770 
o|contracted procedure: k2790 
o|contracted procedure: k2797 
o|contracted procedure: k2807 
o|contracted procedure: k2829 
o|simplifications: ((let . 103)) 
o|removed binding forms: 288 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest142145 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest142145 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest155158 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest155158 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest199202 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest199202 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest199202 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest199202 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest232235 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest232235 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest232235 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest232235 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? delstr-and-flag250 0 
(o x)|known list op on rest arg sublist: ##core#rest-car delstr-and-flag250 0 
(o x)|known list op on rest arg sublist: ##core#rest-length delstr-and-flag250 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest297299 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest297299 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest419421 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest419421 0 
o|inlining procedure: k2480 
o|inlining procedure: k2480 
o|substituted constant variable: r2778 
o|substituted constant variable: r2782 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1272 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1272 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1272 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1272 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1392 1 
(o x)|known list op on rest arg sublist: ##core#rest-car r1392 1 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1392 1 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1392 1 
o|removed binding forms: 4 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1278 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1278 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1278 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1278 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1398 2 
(o x)|known list op on rest arg sublist: ##core#rest-car r1398 2 
(o x)|known list op on rest arg sublist: ##core#rest-null? r1398 2 
(o x)|known list op on rest arg sublist: ##core#rest-cdr r1398 2 
o|removed binding forms: 2 
o|removed binding forms: 4 
o|direct leaf routine/allocation: loop60 0 
o|direct leaf routine/allocation: loop2314 0 
o|direct leaf routine/allocation: loop338 0 
o|converted assignments to bindings: (loop60) 
o|converted assignments to bindings: (loop2314) 
o|converted assignments to bindings: (loop338) 
o|simplifications: ((let . 3)) 
o|customizable procedures: (g592593 foldl585589 loop601 visit556 walk572 doloop542543 step520 loop508 loop494 loop478 doloop471472 loop405 loop388 k1970 collect383 instring334 loop364 loop1306 scan278 loop262 add256 traverse104 loop115 map-loop8097 rev-string-append54) 
o|calls to known targets: 66 
o|identified direct recursive calls: f_877 1 
o|identified direct recursive calls: f_854 1 
o|unused rest argument: rest142145 f_1114 
o|unused rest argument: rest155158 f_1129 
o|unused rest argument: rest199202 f_1266 
o|unused rest argument: rest232235 f_1386 
o|identified direct recursive calls: f_1514 1 
o|identified direct recursive calls: f_1613 1 
o|identified direct recursive calls: f_1598 1 
o|unused rest argument: rest297299 f_1580 
o|identified direct recursive calls: f_1696 1 
o|identified direct recursive calls: f_1932 1 
o|unused rest argument: rest419421 f_2079 
o|identified direct recursive calls: f_2441 1 
o|identified direct recursive calls: f_2535 1 
o|fast box initializations: 20 
o|dropping unused closure argument: f_1022 
o|dropping unused closure argument: f_1685 
*/
/* end of file */
