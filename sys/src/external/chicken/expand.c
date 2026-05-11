/* Generated from expand.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0rc1 (prerelease) (rev bc191a47)
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: expand.scm -optimize-level 2 -include-path . -include-path ./ -inline -ignore-repository -feature chicken-bootstrap -no-warnings -specialize -consult-types-file ./types.db -explicit-use -no-trace -output-file expand.c -no-module-registration
   unit: expand
   uses: data-structures internal library
*/
#include "chicken.h"

static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_data_2dstructures_toplevel)
C_externimport void C_ccall C_data_2dstructures_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_internal_toplevel)
C_externimport void C_ccall C_internal_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[398];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,26),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,108,111,111,107,117,112,32,115,101,41,0,0,0,0,0,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,35),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,109,97,99,114,111,45,97,108,105,97,115,32,118,97,114,32,115,101,41,0,0,0,0,0};
static C_char C_TLS li2[] C_aligned={C_lihdr(0,0,13),40,100,111,108,111,111,112,56,56,52,32,105,41,0,0,0};
static C_char C_TLS li3[] C_aligned={C_lihdr(0,0,8),40,119,97,108,107,32,120,41};
static C_char C_TLS li4[] C_aligned={C_lihdr(0,0,33),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,115,116,114,105,112,45,115,121,110,116,97,120,32,101,120,112,41,0,0,0,0,0,0,0};
static C_char C_TLS li5[] C_aligned={C_lihdr(0,0,23),40,109,97,112,45,108,111,111,112,57,54,57,32,103,57,56,49,32,103,57,56,50,41,0};
static C_char C_TLS li6[] C_aligned={C_lihdr(0,0,28),40,102,111,114,45,101,97,99,104,45,108,111,111,112,57,51,50,32,103,57,51,57,32,103,57,52,48,41,0,0,0,0};
static C_char C_TLS li7[] C_aligned={C_lihdr(0,0,18),40,109,97,112,45,108,111,111,112,57,48,54,32,103,57,49,56,41,0,0,0,0,0,0};
static C_char C_TLS li8[] C_aligned={C_lihdr(0,0,32),40,35,35,115,121,115,35,101,120,116,101,110,100,45,115,101,32,115,101,32,118,97,114,115,32,46,32,114,101,115,116,41};
static C_char C_TLS li9[] C_aligned={C_lihdr(0,0,35),40,35,35,115,121,115,35,101,110,115,117,114,101,45,116,114,97,110,115,102,111,114,109,101,114,32,116,32,46,32,114,101,115,116,41,0,0,0,0,0};
static C_char C_TLS li10[] C_aligned={C_lihdr(0,0,7),40,103,49,48,51,51,41,0};
static C_char C_TLS li11[] C_aligned={C_lihdr(0,0,52),40,35,35,115,121,115,35,101,120,116,101,110,100,45,109,97,99,114,111,45,101,110,118,105,114,111,110,109,101,110,116,32,110,97,109,101,32,115,101,32,116,114,97,110,115,102,111,114,109,101,114,41,0,0,0,0};
static C_char C_TLS li12[] C_aligned={C_lihdr(0,0,25),40,35,35,115,121,115,35,109,97,99,114,111,63,32,115,121,109,32,46,32,114,101,115,116,41,0,0,0,0,0,0,0};
static C_char C_TLS li13[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,109,101,41,0,0,0,0,0,0,0};
static C_char C_TLS li14[] C_aligned={C_lihdr(0,0,28),40,35,35,115,121,115,35,117,110,100,101,102,105,110,101,45,109,97,99,114,111,33,32,110,97,109,101,41,0,0,0,0};
static C_char C_TLS li15[] C_aligned={C_lihdr(0,0,9),40,99,111,112,121,32,112,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li16[] C_aligned={C_lihdr(0,0,7),40,97,54,51,54,56,41,0};
static C_char C_TLS li17[] C_aligned={C_lihdr(0,0,10),40,97,54,51,54,50,32,101,120,41,0,0,0,0,0,0};
static C_char C_TLS li18[] C_aligned={C_lihdr(0,0,14),40,102,95,54,53,48,52,32,105,110,112,117,116,41,0,0};
static C_char C_TLS li19[] C_aligned={C_lihdr(0,0,7),40,97,54,53,48,57,41,0};
static C_char C_TLS li20[] C_aligned={C_lihdr(0,0,7),40,97,54,53,49,52,41,0};
static C_char C_TLS li21[] C_aligned={C_lihdr(0,0,7),40,97,54,53,50,48,41,0};
static C_char C_TLS li22[] C_aligned={C_lihdr(0,0,7),40,97,54,52,54,57,41,0};
static C_char C_TLS li23[] C_aligned={C_lihdr(0,0,7),40,97,54,53,51,52,41,0};
static C_char C_TLS li24[] C_aligned={C_lihdr(0,0,14),40,97,54,53,50,56,32,46,32,97,114,103,115,41,0,0};
static C_char C_TLS li25[] C_aligned={C_lihdr(0,0,7),40,97,54,52,54,51,41,0};
static C_char C_TLS li26[] C_aligned={C_lihdr(0,0,9),40,97,54,51,53,54,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li27[] C_aligned={C_lihdr(0,0,37),40,99,97,108,108,45,104,97,110,100,108,101,114,32,110,97,109,101,32,104,97,110,100,108,101,114,32,101,120,112,32,115,101,32,99,115,41,0,0,0};
static C_char C_TLS li28[] C_aligned={C_lihdr(0,0,22),40,101,120,112,97,110,100,32,104,101,97,100,32,101,120,112,32,109,100,101,102,41,0,0};
static C_char C_TLS li29[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,49,56,50,32,103,49,49,57,52,41,0,0,0,0};
static C_char C_TLS li30[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,49,53,53,32,103,49,49,54,55,41,0,0,0,0};
static C_char C_TLS li31[] C_aligned={C_lihdr(0,0,10),40,103,49,50,49,53,32,99,115,41,0,0,0,0,0,0};
static C_char C_TLS li32[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,101,120,112,41,0,0,0,0,0,0};
static C_char C_TLS li33[] C_aligned={C_lihdr(0,0,28),40,35,35,115,121,115,35,101,120,112,97,110,100,45,48,32,101,120,112,32,100,115,101,32,99,115,63,41,0,0,0,0};
static C_char C_TLS li34[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,101,120,112,97,110,115,105,111,110,45,114,101,115,117,108,116,45,104,111,111,107,32,105,110,112,117,116,32,111,117,116,112,117,116,41,0,0,0,0,0};
static C_char C_TLS li35[] C_aligned={C_lihdr(0,0,7),40,97,54,56,56,50,41,0};
static C_char C_TLS li36[] C_aligned={C_lihdr(0,0,22),40,97,54,56,56,56,32,101,120,112,50,49,50,53,50,32,109,49,50,53,52,41,0,0};
static C_char C_TLS li37[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,101,120,112,41,0,0,0,0,0,0};
static C_char C_TLS li38[] C_aligned={C_lihdr(0,0,34),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,101,120,112,97,110,100,32,101,120,112,32,46,32,114,101,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li39[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li40[] C_aligned={C_lihdr(0,0,35),40,35,35,115,121,115,35,101,120,116,101,110,100,101,100,45,108,97,109,98,100,97,45,108,105,115,116,63,32,108,108,105,115,116,41,0,0,0,0,0};
static C_char C_TLS li41[] C_aligned={C_lihdr(0,0,9),40,101,114,114,32,109,115,103,41,0,0,0,0,0,0,0};
static C_char C_TLS li42[] C_aligned={C_lihdr(0,0,9),40,103,49,51,49,56,32,107,41,0,0,0,0,0,0,0};
static C_char C_TLS li43[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,51,49,50,32,103,49,51,50,52,41,0,0,0,0};
static C_char C_TLS li44[] C_aligned={C_lihdr(0,0,29),40,108,111,111,112,32,109,111,100,101,32,114,101,113,32,111,112,116,32,107,101,121,32,108,108,105,115,116,41,0,0,0};
static C_char C_TLS li45[] C_aligned={C_lihdr(0,0,55),40,35,35,115,121,115,35,101,120,112,97,110,100,45,101,120,116,101,110,100,101,100,45,108,97,109,98,100,97,45,108,105,115,116,32,108,108,105,115,116,48,32,98,111,100,121,32,101,114,114,104,32,115,101,41,0};
static C_char C_TLS li46[] C_aligned={C_lihdr(0,0,26),40,109,97,112,45,108,111,111,112,49,52,52,57,32,103,49,52,54,49,32,103,49,52,54,50,41,0,0,0,0,0,0};
static C_char C_TLS li47[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,52,50,48,32,103,49,52,51,50,41,0,0,0,0};
static C_char C_TLS li48[] C_aligned={C_lihdr(0,0,22),40,97,55,53,56,54,32,118,97,114,115,32,97,114,103,99,32,114,101,115,116,41,0,0};
static C_char C_TLS li49[] C_aligned={C_lihdr(0,0,54),40,35,35,115,121,115,35,101,120,112,97,110,100,45,109,117,108,116,105,112,108,101,45,118,97,108,117,101,115,45,97,115,115,105,103,110,109,101,110,116,32,102,111,114,109,97,108,115,32,101,120,112,114,41,0,0};
static C_char C_TLS li50[] C_aligned={C_lihdr(0,0,11),40,99,111,109,112,32,115,32,105,100,41,0,0,0,0,0};
static C_char C_TLS li51[] C_aligned={C_lihdr(0,0,11),40,114,101,112,101,97,116,32,105,100,41,0,0,0,0,0};
static C_char C_TLS li52[] C_aligned={C_lihdr(0,0,11),40,102,95,55,56,50,55,32,105,100,41,0,0,0,0,0};
static C_char C_TLS li53[] C_aligned={C_lihdr(0,0,14),40,99,111,109,112,45,100,101,102,32,100,101,102,41,0,0};
static C_char C_TLS li54[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,50,32,98,111,100,121,41,0,0,0,0};
static C_char C_TLS li55[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,98,111,100,121,32,101,120,112,115,41};
static C_char C_TLS li56[] C_aligned={C_lihdr(0,0,32),40,109,97,112,45,108,111,111,112,49,54,53,50,32,103,49,54,54,52,32,103,49,54,54,53,32,103,49,54,54,54,41};
static C_char C_TLS li57[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,54,48,52,32,103,49,54,49,54,41,0,0,0,0};
static C_char C_TLS li58[] C_aligned={C_lihdr(0,0,13),40,97,56,51,51,52,32,97,32,95,32,95,41,0,0,0};
static C_char C_TLS li59[] C_aligned={C_lihdr(0,0,23),40,102,111,108,100,108,49,54,50,55,32,103,49,54,50,56,32,103,49,54,50,54,41,0};
static C_char C_TLS li60[] C_aligned={C_lihdr(0,0,29),40,102,95,55,57,49,52,32,118,97,114,115,32,118,97,108,115,32,109,118,97,114,115,32,98,111,100,121,41,0,0,0};
static C_char C_TLS li61[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,55,49,50,32,103,49,55,50,52,41,0,0,0,0};
static C_char C_TLS li62[] C_aligned={C_lihdr(0,0,21),40,108,111,111,112,32,98,111,100,121,32,100,101,102,115,32,100,111,110,101,41,0,0,0};
static C_char C_TLS li63[] C_aligned={C_lihdr(0,0,29),40,102,95,56,51,53,49,32,118,97,114,115,32,118,97,108,115,32,109,118,97,114,115,32,98,111,100,121,41,0,0,0};
static C_char C_TLS li64[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,50,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li65[] C_aligned={C_lihdr(0,0,27),40,108,111,111,112,32,98,111,100,121,32,118,97,114,115,32,118,97,108,115,32,109,118,97,114,115,41,0,0,0,0,0};
static C_char C_TLS li66[] C_aligned={C_lihdr(0,0,13),40,102,95,56,53,48,55,32,98,111,100,121,41,0,0,0};
static C_char C_TLS li67[] C_aligned={C_lihdr(0,0,37),40,35,35,115,121,115,35,99,97,110,111,110,105,99,97,108,105,122,101,45,98,111,100,121,32,98,111,100,121,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li68[] C_aligned={C_lihdr(0,0,7),40,103,49,56,48,57,41,0};
static C_char C_TLS li69[] C_aligned={C_lihdr(0,0,11),40,109,119,97,108,107,32,120,32,112,41,0,0,0,0,0};
static C_char C_TLS li70[] C_aligned={C_lihdr(0,0,46),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,109,97,116,99,104,45,101,120,112,114,101,115,115,105,111,110,32,101,120,112,32,112,97,116,32,118,97,114,115,41,0,0};
static C_char C_TLS li71[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,104,101,97,100,32,98,111,100,121,41};
static C_char C_TLS li72[] C_aligned={C_lihdr(0,0,51),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,101,120,112,97,110,100,45,99,117,114,114,105,101,100,45,100,101,102,105,110,101,32,104,101,97,100,32,98,111,100,121,32,115,101,41,0,0,0,0,0};
static C_char C_TLS li73[] C_aligned={C_lihdr(0,0,36),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,115,121,110,116,97,120,45,101,114,114,111,114,32,46,32,97,114,103,115,41,0,0,0,0};
static C_char C_TLS li74[] C_aligned={C_lihdr(0,0,12),40,111,117,116,115,116,114,32,115,116,114,41,0,0,0,0};
static C_char C_TLS li75[] C_aligned={C_lihdr(0,0,10),40,108,111,111,112,32,108,115,116,41,0,0,0,0,0,0};
static C_char C_TLS li76[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,100,101,102,115,41,0,0,0,0,0};
static C_char C_TLS li77[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,99,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li78[] C_aligned={C_lihdr(0,0,36),40,35,35,115,121,115,35,115,121,110,116,97,120,45,101,114,114,111,114,47,99,111,110,116,101,120,116,32,109,115,103,32,97,114,103,41,0,0,0,0};
static C_char C_TLS li79[] C_aligned={C_lihdr(0,0,13),40,108,112,32,108,115,116,32,112,114,101,118,41,0,0,0};
static C_char C_TLS li80[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,97,115,115,113,47,100,114,111,112,45,98,119,112,33,32,120,32,108,115,116,41,0,0,0};
static C_char C_TLS li81[] C_aligned={C_lihdr(0,0,58),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,114,101,97,100,45,119,105,116,104,45,115,111,117,114,99,101,45,105,110,102,111,45,104,111,111,107,32,99,108,97,115,115,32,100,97,116,97,32,118,97,108,41,0,0,0,0,0,0};
static C_char C_TLS li82[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,114,101,97,100,45,119,105,116,104,45,115,111,117,114,99,101,45,105,110,102,111,32,46,32,114,101,115,116,41,0,0,0};
static C_char C_TLS li83[] C_aligned={C_lihdr(0,0,10),40,103,49,57,52,50,32,112,108,41,0,0,0,0,0,0};
static C_char C_TLS li84[] C_aligned={C_lihdr(0,0,37),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,103,101,116,45,108,105,110,101,45,110,117,109,98,101,114,32,115,101,120,112,41,0,0,0};
static C_char C_TLS li85[] C_aligned={C_lihdr(0,0,9),40,103,49,57,53,56,32,97,41,0,0,0,0,0,0,0};
static C_char C_TLS li86[] C_aligned={C_lihdr(0,0,22),40,35,35,115,121,115,35,103,101,116,45,108,105,110,101,45,50,32,101,120,112,41,0,0};
static C_char C_TLS li87[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,49,57,54,55,32,103,49,57,55,57,41,0,0,0,0};
static C_char C_TLS li88[] C_aligned={C_lihdr(0,0,15),40,97,57,52,49,49,32,107,101,121,32,118,97,108,41,0};
static C_char C_TLS li89[] C_aligned={C_lihdr(0,0,36),40,35,35,115,121,115,35,100,105,115,112,108,97,121,45,108,105,110,101,45,110,117,109,98,101,114,45,100,97,116,97,98,97,115,101,41,0,0,0,0};
static C_char C_TLS li90[] C_aligned={C_lihdr(0,0,9),40,108,111,111,112,32,120,115,41,0,0,0,0,0,0,0};
static C_char C_TLS li91[] C_aligned={C_lihdr(0,0,14),40,109,97,112,117,112,100,97,116,101,32,120,115,41,0,0};
static C_char C_TLS li92[] C_aligned={C_lihdr(0,0,8),40,119,97,108,107,32,120,41};
static C_char C_TLS li93[] C_aligned={C_lihdr(0,0,43),40,35,35,115,121,115,35,117,112,100,97,116,101,45,108,105,110,101,45,110,117,109,98,101,114,45,100,97,116,97,98,97,115,101,33,32,101,120,112,32,108,110,41,0,0,0,0,0};
static C_char C_TLS li94[] C_aligned={C_lihdr(0,0,17),40,116,101,115,116,32,120,32,112,114,101,100,32,109,115,103,41,0,0,0,0,0,0,0};
static C_char C_TLS li95[] C_aligned={C_lihdr(0,0,9),40,101,114,114,32,109,115,103,41,0,0,0,0,0,0,0};
static C_char C_TLS li96[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li97[] C_aligned={C_lihdr(0,0,16),40,108,97,109,98,100,97,45,108,105,115,116,63,32,120,41};
static C_char C_TLS li98[] C_aligned={C_lihdr(0,0,13),40,118,97,114,105,97,98,108,101,63,32,118,41,0,0,0};
static C_char C_TLS li99[] C_aligned={C_lihdr(0,0,6),40,108,111,111,112,41,0,0};
static C_char C_TLS li100[] C_aligned={C_lihdr(0,0,16),40,112,114,111,112,101,114,45,108,105,115,116,63,32,120,41};
static C_char C_TLS li101[] C_aligned={C_lihdr(0,0,16),40,100,111,108,111,111,112,50,48,57,54,32,120,32,110,41};
static C_char C_TLS li102[] C_aligned={C_lihdr(0,0,9),40,97,57,56,56,57,32,121,41,0,0,0,0,0,0,0};
static C_char C_TLS li103[] C_aligned={C_lihdr(0,0,10),40,119,97,108,107,32,120,32,112,41,0,0,0,0,0,0};
static C_char C_TLS li104[] C_aligned={C_lihdr(0,0,38),40,35,35,115,121,115,35,99,104,101,99,107,45,115,121,110,116,97,120,32,105,100,32,101,120,112,32,112,97,116,32,46,32,114,101,115,116,41,0,0};
static C_char C_TLS li105[] C_aligned={C_lihdr(0,0,35),40,105,110,104,101,114,105,116,45,112,97,105,114,45,108,105,110,101,45,110,117,109,98,101,114,115,32,111,108,100,32,110,101,119,41,0,0,0,0,0};
static C_char C_TLS li106[] C_aligned={C_lihdr(0,0,12),40,114,101,110,97,109,101,32,115,121,109,41,0,0,0,0};
static C_char C_TLS li107[] C_aligned={C_lihdr(0,0,16),40,100,111,108,111,111,112,50,49,56,49,32,105,32,102,41};
static C_char C_TLS li108[] C_aligned={C_lihdr(0,0,7),40,103,50,50,50,50,41,0};
static C_char C_TLS li109[] C_aligned={C_lihdr(0,0,7),40,103,50,50,51,49,41,0};
static C_char C_TLS li110[] C_aligned={C_lihdr(0,0,15),40,99,111,109,112,97,114,101,32,115,49,32,115,50,41,0};
static C_char C_TLS li111[] C_aligned={C_lihdr(0,0,16),40,97,115,115,113,45,114,101,118,101,114,115,101,32,108,41};
static C_char C_TLS li112[] C_aligned={C_lihdr(0,0,19),40,109,105,114,114,111,114,45,114,101,110,97,109,101,32,115,121,109,41,0,0,0,0,0};
static C_char C_TLS li113[] C_aligned={C_lihdr(0,0,20),40,97,49,48,48,48,53,32,102,111,114,109,32,115,101,32,100,115,101,41,0,0,0,0};
static C_char C_TLS li114[] C_aligned={C_lihdr(0,0,66),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,109,97,107,101,45,101,114,47,105,114,45,116,114,97,110,115,102,111,114,109,101,114,32,104,97,110,100,108,101,114,32,101,120,112,108,105,99,105,116,45,114,101,110,97,109,105,110,103,63,41,0,0,0,0,0,0};
static C_char C_TLS li115[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,101,114,45,109,97,99,114,111,45,116,114,97,110,115,102,111,114,109,101,114,32,104,97,110,100,108,101,114,41,0,0,0};
static C_char C_TLS li116[] C_aligned={C_lihdr(0,0,45),40,99,104,105,99,107,101,110,46,115,121,110,116,97,120,35,105,114,45,109,97,99,114,111,45,116,114,97,110,115,102,111,114,109,101,114,32,104,97,110,100,108,101,114,41,0,0,0};
static C_char C_TLS li117[] C_aligned={C_lihdr(0,0,59),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,46,115,121,110,116,97,120,45,114,117,108,101,115,35,115,121,110,116,97,120,45,114,117,108,101,115,45,109,105,115,109,97,116,99,104,32,105,110,112,117,116,41,0,0,0,0,0};
static C_char C_TLS li118[] C_aligned={C_lihdr(0,0,16),40,108,111,111,112,32,108,101,110,32,105,110,112,117,116,41};
static C_char C_TLS li119[] C_aligned={C_lihdr(0,0,53),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,46,115,121,110,116,97,120,45,114,117,108,101,115,35,100,114,111,112,45,114,105,103,104,116,32,105,110,112,117,116,32,116,101,109,112,41,0,0,0};
static C_char C_TLS li120[] C_aligned={C_lihdr(0,0,12),40,108,111,111,112,32,105,110,112,117,116,41,0,0,0,0};
static C_char C_TLS li121[] C_aligned={C_lihdr(0,0,53),40,99,104,105,99,107,101,110,46,105,110,116,101,114,110,97,108,46,115,121,110,116,97,120,45,114,117,108,101,115,35,116,97,107,101,45,114,105,103,104,116,32,105,110,112,117,116,32,116,101,109,112,41,0,0,0};
static C_char C_TLS li122[] C_aligned={C_lihdr(0,0,11),40,102,95,49,48,56,51,53,32,120,41,0,0,0,0,0};
static C_char C_TLS li123[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,51,54,50,32,103,51,51,55,52,41,0,0,0,0};
static C_char C_TLS li124[] C_aligned={C_lihdr(0,0,15),40,102,95,49,48,56,52,49,32,114,117,108,101,115,41,0};
static C_char C_TLS li125[] C_aligned={C_lihdr(0,0,10),40,97,49,48,57,55,50,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li126[] C_aligned={C_lihdr(0,0,14),40,102,95,49,48,57,51,53,32,114,117,108,101,41,0,0};
static C_char C_TLS li127[] C_aligned={C_lihdr(0,0,37),40,102,95,49,49,48,48,49,32,105,110,112,117,116,32,112,97,116,116,101,114,110,32,115,101,101,110,45,115,101,103,109,101,110,116,63,41,0,0,0};
static C_char C_TLS li128[] C_aligned={C_lihdr(0,0,23),40,102,95,49,49,49,56,50,32,105,110,112,117,116,32,112,97,116,116,101,114,110,41,0};
static C_char C_TLS li129[] C_aligned={C_lihdr(0,0,10),40,97,49,49,51,54,55,32,120,41,0,0,0,0,0,0};
static C_char C_TLS li130[] C_aligned={C_lihdr(0,0,42),40,102,95,49,49,51,48,57,32,112,97,116,116,101,114,110,32,112,97,116,104,32,109,97,112,105,116,32,115,101,101,110,45,115,101,103,109,101,110,116,63,41,0,0,0,0,0,0};
static C_char C_TLS li131[] C_aligned={C_lihdr(0,0,18),40,100,111,108,111,111,112,51,52,57,54,32,100,32,103,101,110,41,0,0,0,0,0,0};
static C_char C_TLS li132[] C_aligned={C_lihdr(0,0,26),40,102,95,49,49,52,52,57,32,116,101,109,112,108,97,116,101,32,100,105,109,32,101,110,118,41,0,0,0,0,0,0};
static C_char C_TLS li133[] C_aligned={C_lihdr(0,0,40),40,102,95,49,49,54,52,49,32,112,97,116,116,101,114,110,32,100,105,109,32,118,97,114,115,32,115,101,101,110,45,115,101,103,109,101,110,116,63,41};
static C_char C_TLS li134[] C_aligned={C_lihdr(0,0,31),40,102,95,49,49,55,49,56,32,116,101,109,112,108,97,116,101,32,100,105,109,32,101,110,118,32,102,114,101,101,41,0};
static C_char C_TLS li135[] C_aligned={C_lihdr(0,0,25),40,102,95,49,49,56,48,55,32,112,32,115,101,101,110,45,115,101,103,109,101,110,116,63,41,0,0,0,0,0,0,0};
static C_char C_TLS li136[] C_aligned={C_lihdr(0,0,17),40,102,95,49,49,56,51,53,32,112,97,116,116,101,114,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li137[] C_aligned={C_lihdr(0,0,17),40,102,95,49,49,56,53,57,32,112,97,116,116,101,114,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li138[] C_aligned={C_lihdr(0,0,14),40,108,111,111,112,32,112,97,116,116,101,114,110,41,0,0};
static C_char C_TLS li139[] C_aligned={C_lihdr(0,0,17),40,102,95,49,49,56,55,57,32,112,97,116,116,101,114,110,41,0,0,0,0,0,0,0};
static C_char C_TLS li140[] C_aligned={C_lihdr(0,0,16),40,97,49,49,57,52,49,32,101,120,112,32,114,32,99,41};
static C_char C_TLS li141[] C_aligned={C_lihdr(0,0,17),40,97,49,49,57,55,55,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li142[] C_aligned={C_lihdr(0,0,10),40,119,97,108,107,32,120,32,110,41,0,0,0,0,0,0};
static C_char C_TLS li143[] C_aligned={C_lihdr(0,0,11),40,119,97,108,107,49,32,120,32,110,41,0,0,0,0,0};
static C_char C_TLS li144[] C_aligned={C_lihdr(0,0,11),40,103,51,50,50,54,32,101,110,118,41,0,0,0,0,0};
static C_char C_TLS li145[] C_aligned={C_lihdr(0,0,11),40,103,51,50,51,51,32,101,110,118,41,0,0,0,0,0};
static C_char C_TLS li146[] C_aligned={C_lihdr(0,0,12),40,115,105,109,112,108,105,102,121,32,120,41,0,0,0,0};
static C_char C_TLS li147[] C_aligned={C_lihdr(0,0,17),40,97,49,50,48,49,48,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li148[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,49,51,56,32,103,51,49,53,48,41,0,0,0,0};
static C_char C_TLS li149[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,49,48,52,32,103,51,49,49,54,41,0,0,0,0};
static C_char C_TLS li150[] C_aligned={C_lihdr(0,0,17),40,97,49,50,51,48,51,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li151[] C_aligned={C_lihdr(0,0,11),40,101,120,112,97,110,100,32,98,115,41,0,0,0,0,0};
static C_char C_TLS li152[] C_aligned={C_lihdr(0,0,17),40,97,49,50,52,57,57,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li153[] C_aligned={C_lihdr(0,0,7),40,103,51,48,52,53,41,0};
static C_char C_TLS li154[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,51,48,51,57,32,103,51,48,53,49,41,0,0,0,0};
static C_char C_TLS li155[] C_aligned={C_lihdr(0,0,22),40,101,120,112,97,110,100,32,99,108,97,117,115,101,115,32,101,108,115,101,63,41,0,0};
static C_char C_TLS li156[] C_aligned={C_lihdr(0,0,17),40,97,49,50,53,53,48,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li157[] C_aligned={C_lihdr(0,0,22),40,101,120,112,97,110,100,32,99,108,97,117,115,101,115,32,101,108,115,101,63,41,0,0};
static C_char C_TLS li158[] C_aligned={C_lihdr(0,0,17),40,97,49,50,55,56,54,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li159[] C_aligned={C_lihdr(0,0,17),40,97,49,51,49,55,52,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li160[] C_aligned={C_lihdr(0,0,17),40,97,49,51,50,50,54,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li161[] C_aligned={C_lihdr(0,0,14),40,97,49,51,50,54,51,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li162[] C_aligned={C_lihdr(0,0,14),40,97,49,51,51,48,55,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li163[] C_aligned={C_lihdr(0,0,14),40,97,49,51,51,50,57,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li164[] C_aligned={C_lihdr(0,0,14),40,97,49,51,51,53,49,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li165[] C_aligned={C_lihdr(0,0,14),40,97,49,51,51,55,51,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li166[] C_aligned={C_lihdr(0,0,17),40,97,49,51,52,50,53,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li167[] C_aligned={C_lihdr(0,0,11),40,108,111,111,112,32,102,111,114,109,41,0,0,0,0,0};
static C_char C_TLS li168[] C_aligned={C_lihdr(0,0,14),40,97,49,51,52,55,50,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li169[] C_aligned={C_lihdr(0,0,14),40,97,49,51,53,57,57,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li170[] C_aligned={C_lihdr(0,0,14),40,97,49,51,54,49,54,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li171[] C_aligned={C_lihdr(0,0,14),40,97,49,51,54,51,51,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li172[] C_aligned={C_lihdr(0,0,14),40,97,49,51,54,53,48,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li173[] C_aligned={C_lihdr(0,0,14),40,97,49,51,54,54,55,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li174[] C_aligned={C_lihdr(0,0,14),40,97,49,51,54,57,48,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li175[] C_aligned={C_lihdr(0,0,11),40,103,50,54,56,57,32,97,114,103,41,0,0,0,0,0};
static C_char C_TLS li176[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,54,56,51,32,103,50,54,57,53,41,0,0,0,0};
static C_char C_TLS li177[] C_aligned={C_lihdr(0,0,14),40,97,49,51,55,55,52,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li178[] C_aligned={C_lihdr(0,0,26),40,97,49,51,57,52,53,32,103,50,54,53,55,32,103,50,54,53,57,32,103,50,54,54,49,41,0,0,0,0,0,0};
static C_char C_TLS li179[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,54,50,52,32,103,50,54,51,54,41,0,0,0,0};
static C_char C_TLS li180[] C_aligned={C_lihdr(0,0,14),40,97,49,51,57,53,53,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li181[] C_aligned={C_lihdr(0,0,14),40,97,49,52,48,55,56,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li182[] C_aligned={C_lihdr(0,0,14),40,97,49,52,49,48,53,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li183[] C_aligned={C_lihdr(0,0,7),40,101,114,114,32,120,41,0};
static C_char C_TLS li184[] C_aligned={C_lihdr(0,0,9),40,116,101,115,116,32,102,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li185[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,53,51,53,32,103,50,53,52,55,41,0,0,0,0};
static C_char C_TLS li186[] C_aligned={C_lihdr(0,0,12),40,101,120,112,97,110,100,32,99,108,115,41,0,0,0,0};
static C_char C_TLS li187[] C_aligned={C_lihdr(0,0,17),40,97,49,52,50,56,48,32,102,111,114,109,32,114,32,99,41,0,0,0,0,0,0,0};
static C_char C_TLS li188[] C_aligned={C_lihdr(0,0,14),40,97,49,52,53,55,51,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li189[] C_aligned={C_lihdr(0,0,8),40,97,49,52,54,50,51,41};
static C_char C_TLS li190[] C_aligned={C_lihdr(0,0,52),40,97,49,52,54,50,57,32,110,97,109,101,50,52,52,52,32,108,105,98,50,52,52,54,32,115,112,101,99,50,52,52,56,32,118,50,52,53,48,32,115,50,52,53,50,32,105,50,52,53,52,41,0,0,0,0};
static C_char C_TLS li191[] C_aligned={C_lihdr(0,0,9),40,103,50,52,51,48,32,120,41,0,0,0,0,0,0,0};
static C_char C_TLS li192[] C_aligned={C_lihdr(0,0,20),40,109,97,112,45,108,111,111,112,50,52,50,52,32,103,50,52,51,54,41,0,0,0,0};
static C_char C_TLS li193[] C_aligned={C_lihdr(0,0,14),40,97,49,52,54,48,56,32,120,32,114,32,99,41,0,0};
static C_char C_TLS li194[] C_aligned={C_lihdr(0,0,26),40,97,49,52,55,49,57,32,103,50,52,48,53,32,103,50,52,48,55,32,103,50,52,48,57,41,0,0,0,0,0,0};
static C_char C_TLS li195[] C_aligned={C_lihdr(0,0,26),40,97,49,52,55,50,57,32,103,50,51,57,49,32,103,50,51,57,51,32,103,50,51,57,53,41,0,0,0,0,0,0};
static C_char C_TLS li196[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


C_noret_decl(f_10000)
static void C_fcall f_10000(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10006)
static void C_ccall f_10006(C_word c,C_word *av) C_noret;
C_noret_decl(f_10009)
static void C_fcall f_10009(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10016)
static void C_ccall f_10016(C_word c,C_word *av) C_noret;
C_noret_decl(f_10025)
static void C_ccall f_10025(C_word c,C_word *av) C_noret;
C_noret_decl(f_10031)
static void C_ccall f_10031(C_word c,C_word *av) C_noret;
C_noret_decl(f_10056)
static void C_ccall f_10056(C_word c,C_word *av) C_noret;
C_noret_decl(f_10058)
static void C_ccall f_10058(C_word c,C_word *av) C_noret;
C_noret_decl(f_10076)
static void C_ccall f_10076(C_word c,C_word *av) C_noret;
C_noret_decl(f_10080)
static void C_ccall f_10080(C_word c,C_word *av) C_noret;
C_noret_decl(f_10097)
static void C_ccall f_10097(C_word c,C_word *av) C_noret;
C_noret_decl(f_10101)
static void C_ccall f_10101(C_word c,C_word *av) C_noret;
C_noret_decl(f_10127)
static void C_ccall f_10127(C_word c,C_word *av) C_noret;
C_noret_decl(f_10144)
static void C_ccall f_10144(C_word c,C_word *av) C_noret;
C_noret_decl(f_10166)
static void C_ccall f_10166(C_word c,C_word *av) C_noret;
C_noret_decl(f_10203)
static void C_fcall f_10203(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10224)
static void C_ccall f_10224(C_word c,C_word *av) C_noret;
C_noret_decl(f_10255)
static void C_fcall f_10255(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10263)
static void C_fcall f_10263(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10285)
static C_word C_fcall f_10285(C_word t0,C_word t1);
C_noret_decl(f_10300)
static void C_ccall f_10300(C_word c,C_word *av) C_noret;
C_noret_decl(f_10313)
static C_word C_fcall f_10313(C_word t0,C_word t1);
C_noret_decl(f_10328)
static void C_ccall f_10328(C_word c,C_word *av) C_noret;
C_noret_decl(f_10363)
static C_word C_fcall f_10363(C_word t0,C_word t1);
C_noret_decl(f_10388)
static void C_fcall f_10388(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10406)
static void C_ccall f_10406(C_word c,C_word *av) C_noret;
C_noret_decl(f_10410)
static void C_ccall f_10410(C_word c,C_word *av) C_noret;
C_noret_decl(f_10427)
static void C_ccall f_10427(C_word c,C_word *av) C_noret;
C_noret_decl(f_10431)
static void C_ccall f_10431(C_word c,C_word *av) C_noret;
C_noret_decl(f_10520)
static void C_ccall f_10520(C_word c,C_word *av) C_noret;
C_noret_decl(f_10524)
static void C_ccall f_10524(C_word c,C_word *av) C_noret;
C_noret_decl(f_10529)
static void C_ccall f_10529(C_word c,C_word *av) C_noret;
C_noret_decl(f_10535)
static void C_ccall f_10535(C_word c,C_word *av) C_noret;
C_noret_decl(f_10548)
static void C_ccall f_10548(C_word c,C_word *av) C_noret;
C_noret_decl(f_10551)
static void C_ccall f_10551(C_word c,C_word *av) C_noret;
C_noret_decl(f_10555)
static void C_ccall f_10555(C_word c,C_word *av) C_noret;
C_noret_decl(f_10558)
static void C_ccall f_10558(C_word c,C_word *av) C_noret;
C_noret_decl(f_10561)
static void C_ccall f_10561(C_word c,C_word *av) C_noret;
C_noret_decl(f_10565)
static void C_ccall f_10565(C_word c,C_word *av) C_noret;
C_noret_decl(f_10568)
static void C_ccall f_10568(C_word c,C_word *av) C_noret;
C_noret_decl(f_10571)
static void C_ccall f_10571(C_word c,C_word *av) C_noret;
C_noret_decl(f_10574)
static void C_ccall f_10574(C_word c,C_word *av) C_noret;
C_noret_decl(f_10577)
static void C_ccall f_10577(C_word c,C_word *av) C_noret;
C_noret_decl(f_10580)
static void C_ccall f_10580(C_word c,C_word *av) C_noret;
C_noret_decl(f_10583)
static void C_ccall f_10583(C_word c,C_word *av) C_noret;
C_noret_decl(f_10586)
static void C_ccall f_10586(C_word c,C_word *av) C_noret;
C_noret_decl(f_10590)
static void C_ccall f_10590(C_word c,C_word *av) C_noret;
C_noret_decl(f_10594)
static void C_ccall f_10594(C_word c,C_word *av) C_noret;
C_noret_decl(f_10597)
static void C_ccall f_10597(C_word c,C_word *av) C_noret;
C_noret_decl(f_10600)
static void C_ccall f_10600(C_word c,C_word *av) C_noret;
C_noret_decl(f_10603)
static void C_ccall f_10603(C_word c,C_word *av) C_noret;
C_noret_decl(f_10606)
static void C_ccall f_10606(C_word c,C_word *av) C_noret;
C_noret_decl(f_10610)
static void C_ccall f_10610(C_word c,C_word *av) C_noret;
C_noret_decl(f_10614)
static void C_ccall f_10614(C_word c,C_word *av) C_noret;
C_noret_decl(f_10617)
static void C_ccall f_10617(C_word c,C_word *av) C_noret;
C_noret_decl(f_10620)
static void C_ccall f_10620(C_word c,C_word *av) C_noret;
C_noret_decl(f_10623)
static void C_ccall f_10623(C_word c,C_word *av) C_noret;
C_noret_decl(f_10626)
static void C_ccall f_10626(C_word c,C_word *av) C_noret;
C_noret_decl(f_10629)
static void C_ccall f_10629(C_word c,C_word *av) C_noret;
C_noret_decl(f_10632)
static void C_ccall f_10632(C_word c,C_word *av) C_noret;
C_noret_decl(f_10635)
static void C_ccall f_10635(C_word c,C_word *av) C_noret;
C_noret_decl(f_10638)
static void C_ccall f_10638(C_word c,C_word *av) C_noret;
C_noret_decl(f_10641)
static void C_ccall f_10641(C_word c,C_word *av) C_noret;
C_noret_decl(f_10644)
static void C_ccall f_10644(C_word c,C_word *av) C_noret;
C_noret_decl(f_10647)
static void C_ccall f_10647(C_word c,C_word *av) C_noret;
C_noret_decl(f_10650)
static void C_ccall f_10650(C_word c,C_word *av) C_noret;
C_noret_decl(f_10653)
static void C_ccall f_10653(C_word c,C_word *av) C_noret;
C_noret_decl(f_10656)
static void C_ccall f_10656(C_word c,C_word *av) C_noret;
C_noret_decl(f_10658)
static void C_ccall f_10658(C_word c,C_word *av) C_noret;
C_noret_decl(f_10664)
static void C_ccall f_10664(C_word c,C_word *av) C_noret;
C_noret_decl(f_10674)
static void C_fcall f_10674(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_10692)
static void C_ccall f_10692(C_word c,C_word *av) C_noret;
C_noret_decl(f_10700)
static void C_ccall f_10700(C_word c,C_word *av) C_noret;
C_noret_decl(f_10710)
static C_word C_fcall f_10710(C_word t0,C_word t1,C_word t2);
C_noret_decl(f_10737)
static void C_ccall f_10737(C_word c,C_word *av) C_noret;
C_noret_decl(f_10752)
static void C_ccall f_10752(C_word c,C_word *av) C_noret;
C_noret_decl(f_10756)
static void C_ccall f_10756(C_word c,C_word *av) C_noret;
C_noret_decl(f_10761)
static void C_ccall f_10761(C_word c,C_word *av) C_noret;
C_noret_decl(f_10767)
static void C_ccall f_10767(C_word c,C_word *av) C_noret;
C_noret_decl(f_10771)
static void C_ccall f_10771(C_word c,C_word *av) C_noret;
C_noret_decl(f_10775)
static void C_ccall f_10775(C_word c,C_word *av) C_noret;
C_noret_decl(f_10779)
static void C_ccall f_10779(C_word c,C_word *av) C_noret;
C_noret_decl(f_10783)
static void C_ccall f_10783(C_word c,C_word *av) C_noret;
C_noret_decl(f_10787)
static void C_ccall f_10787(C_word c,C_word *av) C_noret;
C_noret_decl(f_10792)
static void C_ccall f_10792(C_word c,C_word *av) C_noret;
C_noret_decl(f_10799)
static void C_ccall f_10799(C_word c,C_word *av) C_noret;
C_noret_decl(f_10804)
static void C_ccall f_10804(C_word c,C_word *av) C_noret;
C_noret_decl(f_10808)
static void C_ccall f_10808(C_word c,C_word *av) C_noret;
C_noret_decl(f_10812)
static void C_ccall f_10812(C_word c,C_word *av) C_noret;
C_noret_decl(f_10816)
static void C_ccall f_10816(C_word c,C_word *av) C_noret;
C_noret_decl(f_10821)
static void C_ccall f_10821(C_word c,C_word *av) C_noret;
C_noret_decl(f_10825)
static void C_ccall f_10825(C_word c,C_word *av) C_noret;
C_noret_decl(f_10829)
static void C_ccall f_10829(C_word c,C_word *av) C_noret;
C_noret_decl(f_10833)
static void C_ccall f_10833(C_word c,C_word *av) C_noret;
C_noret_decl(f_10835)
static void C_ccall f_10835(C_word c,C_word *av) C_noret;
C_noret_decl(f_10841)
static void C_ccall f_10841(C_word c,C_word *av) C_noret;
C_noret_decl(f_10869)
static void C_ccall f_10869(C_word c,C_word *av) C_noret;
C_noret_decl(f_10879)
static void C_ccall f_10879(C_word c,C_word *av) C_noret;
C_noret_decl(f_10893)
static void C_fcall f_10893(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_10918)
static void C_ccall f_10918(C_word c,C_word *av) C_noret;
C_noret_decl(f_10935)
static void C_ccall f_10935(C_word c,C_word *av) C_noret;
C_noret_decl(f_10942)
static void C_fcall f_10942(C_word t0,C_word t1) C_noret;
C_noret_decl(f_10963)
static void C_ccall f_10963(C_word c,C_word *av) C_noret;
C_noret_decl(f_10967)
static void C_ccall f_10967(C_word c,C_word *av) C_noret;
C_noret_decl(f_10971)
static void C_ccall f_10971(C_word c,C_word *av) C_noret;
C_noret_decl(f_10973)
static void C_ccall f_10973(C_word c,C_word *av) C_noret;
C_noret_decl(f_10978)
static void C_ccall f_10978(C_word c,C_word *av) C_noret;
C_noret_decl(f_11001)
static void C_ccall f_11001(C_word c,C_word *av) C_noret;
C_noret_decl(f_11035)
static void C_ccall f_11035(C_word c,C_word *av) C_noret;
C_noret_decl(f_11071)
static void C_ccall f_11071(C_word c,C_word *av) C_noret;
C_noret_decl(f_11075)
static void C_ccall f_11075(C_word c,C_word *av) C_noret;
C_noret_decl(f_11079)
static void C_ccall f_11079(C_word c,C_word *av) C_noret;
C_noret_decl(f_11128)
static void C_ccall f_11128(C_word c,C_word *av) C_noret;
C_noret_decl(f_11136)
static void C_ccall f_11136(C_word c,C_word *av) C_noret;
C_noret_decl(f_11149)
static void C_fcall f_11149(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11182)
static void C_ccall f_11182(C_word c,C_word *av) C_noret;
C_noret_decl(f_11186)
static void C_ccall f_11186(C_word c,C_word *av) C_noret;
C_noret_decl(f_11241)
static void C_ccall f_11241(C_word c,C_word *av) C_noret;
C_noret_decl(f_11265)
static void C_ccall f_11265(C_word c,C_word *av) C_noret;
C_noret_decl(f_11309)
static void C_ccall f_11309(C_word c,C_word *av) C_noret;
C_noret_decl(f_11333)
static void C_ccall f_11333(C_word c,C_word *av) C_noret;
C_noret_decl(f_11339)
static void C_ccall f_11339(C_word c,C_word *av) C_noret;
C_noret_decl(f_11352)
static void C_ccall f_11352(C_word c,C_word *av) C_noret;
C_noret_decl(f_11356)
static void C_ccall f_11356(C_word c,C_word *av) C_noret;
C_noret_decl(f_11368)
static void C_ccall f_11368(C_word c,C_word *av) C_noret;
C_noret_decl(f_11414)
static void C_ccall f_11414(C_word c,C_word *av) C_noret;
C_noret_decl(f_11418)
static void C_ccall f_11418(C_word c,C_word *av) C_noret;
C_noret_decl(f_11443)
static void C_ccall f_11443(C_word c,C_word *av) C_noret;
C_noret_decl(f_11449)
static void C_ccall f_11449(C_word c,C_word *av) C_noret;
C_noret_decl(f_11488)
static void C_ccall f_11488(C_word c,C_word *av) C_noret;
C_noret_decl(f_11491)
static void C_ccall f_11491(C_word c,C_word *av) C_noret;
C_noret_decl(f_11497)
static void C_ccall f_11497(C_word c,C_word *av) C_noret;
C_noret_decl(f_11509)
static void C_ccall f_11509(C_word c,C_word *av) C_noret;
C_noret_decl(f_11512)
static void C_fcall f_11512(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11515)
static void C_ccall f_11515(C_word c,C_word *av) C_noret;
C_noret_decl(f_11528)
static void C_ccall f_11528(C_word c,C_word *av) C_noret;
C_noret_decl(f_11532)
static void C_ccall f_11532(C_word c,C_word *av) C_noret;
C_noret_decl(f_11536)
static void C_ccall f_11536(C_word c,C_word *av) C_noret;
C_noret_decl(f_11538)
static void C_fcall f_11538(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_11559)
static void C_fcall f_11559(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11611)
static void C_ccall f_11611(C_word c,C_word *av) C_noret;
C_noret_decl(f_11615)
static void C_ccall f_11615(C_word c,C_word *av) C_noret;
C_noret_decl(f_11632)
static void C_ccall f_11632(C_word c,C_word *av) C_noret;
C_noret_decl(f_11636)
static void C_ccall f_11636(C_word c,C_word *av) C_noret;
C_noret_decl(f_11641)
static void C_ccall f_11641(C_word c,C_word *av) C_noret;
C_noret_decl(f_11667)
static void C_ccall f_11667(C_word c,C_word *av) C_noret;
C_noret_decl(f_11682)
static void C_ccall f_11682(C_word c,C_word *av) C_noret;
C_noret_decl(f_11701)
static void C_ccall f_11701(C_word c,C_word *av) C_noret;
C_noret_decl(f_11716)
static void C_ccall f_11716(C_word c,C_word *av) C_noret;
C_noret_decl(f_11718)
static void C_ccall f_11718(C_word c,C_word *av) C_noret;
C_noret_decl(f_11760)
static void C_ccall f_11760(C_word c,C_word *av) C_noret;
C_noret_decl(f_11771)
static void C_ccall f_11771(C_word c,C_word *av) C_noret;
C_noret_decl(f_11790)
static void C_ccall f_11790(C_word c,C_word *av) C_noret;
C_noret_decl(f_11805)
static void C_ccall f_11805(C_word c,C_word *av) C_noret;
C_noret_decl(f_11807)
static void C_ccall f_11807(C_word c,C_word *av) C_noret;
C_noret_decl(f_11814)
static void C_ccall f_11814(C_word c,C_word *av) C_noret;
C_noret_decl(f_11835)
static void C_ccall f_11835(C_word c,C_word *av) C_noret;
C_noret_decl(f_11859)
static void C_ccall f_11859(C_word c,C_word *av) C_noret;
C_noret_decl(f_11866)
static void C_ccall f_11866(C_word c,C_word *av) C_noret;
C_noret_decl(f_11873)
static void C_ccall f_11873(C_word c,C_word *av) C_noret;
C_noret_decl(f_11879)
static void C_ccall f_11879(C_word c,C_word *av) C_noret;
C_noret_decl(f_11889)
static void C_fcall f_11889(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_11896)
static void C_ccall f_11896(C_word c,C_word *av) C_noret;
C_noret_decl(f_11917)
static void C_ccall f_11917(C_word c,C_word *av) C_noret;
C_noret_decl(f_11921)
static void C_ccall f_11921(C_word c,C_word *av) C_noret;
C_noret_decl(f_11925)
static void C_ccall f_11925(C_word c,C_word *av) C_noret;
C_noret_decl(f_11928)
static void C_ccall f_11928(C_word c,C_word *av) C_noret;
C_noret_decl(f_11932)
static void C_ccall f_11932(C_word c,C_word *av) C_noret;
C_noret_decl(f_11936)
static void C_ccall f_11936(C_word c,C_word *av) C_noret;
C_noret_decl(f_11940)
static void C_ccall f_11940(C_word c,C_word *av) C_noret;
C_noret_decl(f_11942)
static void C_ccall f_11942(C_word c,C_word *av) C_noret;
C_noret_decl(f_11946)
static void C_ccall f_11946(C_word c,C_word *av) C_noret;
C_noret_decl(f_11954)
static void C_fcall f_11954(C_word t0,C_word t1) C_noret;
C_noret_decl(f_11963)
static void C_ccall f_11963(C_word c,C_word *av) C_noret;
C_noret_decl(f_11976)
static void C_ccall f_11976(C_word c,C_word *av) C_noret;
C_noret_decl(f_11978)
static void C_ccall f_11978(C_word c,C_word *av) C_noret;
C_noret_decl(f_11982)
static void C_ccall f_11982(C_word c,C_word *av) C_noret;
C_noret_decl(f_11989)
static void C_ccall f_11989(C_word c,C_word *av) C_noret;
C_noret_decl(f_12009)
static void C_ccall f_12009(C_word c,C_word *av) C_noret;
C_noret_decl(f_12011)
static void C_ccall f_12011(C_word c,C_word *av) C_noret;
C_noret_decl(f_12015)
static void C_ccall f_12015(C_word c,C_word *av) C_noret;
C_noret_decl(f_12018)
static void C_ccall f_12018(C_word c,C_word *av) C_noret;
C_noret_decl(f_12021)
static void C_ccall f_12021(C_word c,C_word *av) C_noret;
C_noret_decl(f_12023)
static void C_fcall f_12023(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12031)
static void C_ccall f_12031(C_word c,C_word *av) C_noret;
C_noret_decl(f_12033)
static void C_fcall f_12033(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12047)
static void C_ccall f_12047(C_word c,C_word *av) C_noret;
C_noret_decl(f_12051)
static void C_ccall f_12051(C_word c,C_word *av) C_noret;
C_noret_decl(f_12070)
static void C_ccall f_12070(C_word c,C_word *av) C_noret;
C_noret_decl(f_12079)
static void C_ccall f_12079(C_word c,C_word *av) C_noret;
C_noret_decl(f_12093)
static void C_ccall f_12093(C_word c,C_word *av) C_noret;
C_noret_decl(f_12103)
static void C_ccall f_12103(C_word c,C_word *av) C_noret;
C_noret_decl(f_12114)
static void C_ccall f_12114(C_word c,C_word *av) C_noret;
C_noret_decl(f_12124)
static void C_ccall f_12124(C_word c,C_word *av) C_noret;
C_noret_decl(f_12133)
static void C_ccall f_12133(C_word c,C_word *av) C_noret;
C_noret_decl(f_12144)
static void C_ccall f_12144(C_word c,C_word *av) C_noret;
C_noret_decl(f_12155)
static void C_ccall f_12155(C_word c,C_word *av) C_noret;
C_noret_decl(f_12163)
static void C_ccall f_12163(C_word c,C_word *av) C_noret;
C_noret_decl(f_12178)
static void C_ccall f_12178(C_word c,C_word *av) C_noret;
C_noret_decl(f_12182)
static void C_ccall f_12182(C_word c,C_word *av) C_noret;
C_noret_decl(f_12196)
static void C_fcall f_12196(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12200)
static void C_ccall f_12200(C_word c,C_word *av) C_noret;
C_noret_decl(f_12204)
static void C_fcall f_12204(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12226)
static void C_ccall f_12226(C_word c,C_word *av) C_noret;
C_noret_decl(f_12230)
static void C_fcall f_12230(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12273)
static void C_ccall f_12273(C_word c,C_word *av) C_noret;
C_noret_decl(f_12291)
static void C_ccall f_12291(C_word c,C_word *av) C_noret;
C_noret_decl(f_12302)
static void C_ccall f_12302(C_word c,C_word *av) C_noret;
C_noret_decl(f_12304)
static void C_ccall f_12304(C_word c,C_word *av) C_noret;
C_noret_decl(f_12308)
static void C_ccall f_12308(C_word c,C_word *av) C_noret;
C_noret_decl(f_12320)
static void C_ccall f_12320(C_word c,C_word *av) C_noret;
C_noret_decl(f_12348)
static void C_ccall f_12348(C_word c,C_word *av) C_noret;
C_noret_decl(f_12369)
static void C_fcall f_12369(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12410)
static void C_ccall f_12410(C_word c,C_word *av) C_noret;
C_noret_decl(f_12412)
static void C_fcall f_12412(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12422)
static void C_fcall f_12422(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12462)
static void C_fcall f_12462(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12498)
static void C_ccall f_12498(C_word c,C_word *av) C_noret;
C_noret_decl(f_12500)
static void C_ccall f_12500(C_word c,C_word *av) C_noret;
C_noret_decl(f_12504)
static void C_ccall f_12504(C_word c,C_word *av) C_noret;
C_noret_decl(f_12514)
static void C_fcall f_12514(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12539)
static void C_ccall f_12539(C_word c,C_word *av) C_noret;
C_noret_decl(f_12549)
static void C_ccall f_12549(C_word c,C_word *av) C_noret;
C_noret_decl(f_12551)
static void C_ccall f_12551(C_word c,C_word *av) C_noret;
C_noret_decl(f_12555)
static void C_ccall f_12555(C_word c,C_word *av) C_noret;
C_noret_decl(f_12563)
static void C_ccall f_12563(C_word c,C_word *av) C_noret;
C_noret_decl(f_12566)
static void C_ccall f_12566(C_word c,C_word *av) C_noret;
C_noret_decl(f_12569)
static void C_ccall f_12569(C_word c,C_word *av) C_noret;
C_noret_decl(f_12572)
static void C_ccall f_12572(C_word c,C_word *av) C_noret;
C_noret_decl(f_12575)
static void C_ccall f_12575(C_word c,C_word *av) C_noret;
C_noret_decl(f_12586)
static void C_ccall f_12586(C_word c,C_word *av) C_noret;
C_noret_decl(f_12588)
static void C_fcall f_12588(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12602)
static void C_ccall f_12602(C_word c,C_word *av) C_noret;
C_noret_decl(f_12608)
static void C_ccall f_12608(C_word c,C_word *av) C_noret;
C_noret_decl(f_12611)
static void C_ccall f_12611(C_word c,C_word *av) C_noret;
C_noret_decl(f_12615)
static void C_ccall f_12615(C_word c,C_word *av) C_noret;
C_noret_decl(f_12621)
static void C_ccall f_12621(C_word c,C_word *av) C_noret;
C_noret_decl(f_12624)
static void C_ccall f_12624(C_word c,C_word *av) C_noret;
C_noret_decl(f_12639)
static void C_ccall f_12639(C_word c,C_word *av) C_noret;
C_noret_decl(f_12680)
static void C_fcall f_12680(C_word t0,C_word t1) C_noret;
C_noret_decl(f_12684)
static void C_ccall f_12684(C_word c,C_word *av) C_noret;
C_noret_decl(f_12687)
static void C_ccall f_12687(C_word c,C_word *av) C_noret;
C_noret_decl(f_12720)
static C_word C_fcall f_12720(C_word *a,C_word t0,C_word t1);
C_noret_decl(f_12735)
static void C_ccall f_12735(C_word c,C_word *av) C_noret;
C_noret_decl(f_12737)
static void C_fcall f_12737(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_12785)
static void C_ccall f_12785(C_word c,C_word *av) C_noret;
C_noret_decl(f_12787)
static void C_ccall f_12787(C_word c,C_word *av) C_noret;
C_noret_decl(f_12794)
static void C_ccall f_12794(C_word c,C_word *av) C_noret;
C_noret_decl(f_12797)
static void C_ccall f_12797(C_word c,C_word *av) C_noret;
C_noret_decl(f_12800)
static void C_ccall f_12800(C_word c,C_word *av) C_noret;
C_noret_decl(f_12805)
static void C_fcall f_12805(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_12819)
static void C_ccall f_12819(C_word c,C_word *av) C_noret;
C_noret_decl(f_12825)
static void C_ccall f_12825(C_word c,C_word *av) C_noret;
C_noret_decl(f_12828)
static void C_ccall f_12828(C_word c,C_word *av) C_noret;
C_noret_decl(f_12832)
static void C_ccall f_12832(C_word c,C_word *av) C_noret;
C_noret_decl(f_12838)
static void C_ccall f_12838(C_word c,C_word *av) C_noret;
C_noret_decl(f_12841)
static void C_ccall f_12841(C_word c,C_word *av) C_noret;
C_noret_decl(f_12844)
static void C_ccall f_12844(C_word c,C_word *av) C_noret;
C_noret_decl(f_12847)
static void C_ccall f_12847(C_word c,C_word *av) C_noret;
C_noret_decl(f_12851)
static void C_ccall f_12851(C_word c,C_word *av) C_noret;
C_noret_decl(f_12857)
static void C_ccall f_12857(C_word c,C_word *av) C_noret;
C_noret_decl(f_12860)
static void C_ccall f_12860(C_word c,C_word *av) C_noret;
C_noret_decl(f_12863)
static void C_ccall f_12863(C_word c,C_word *av) C_noret;
C_noret_decl(f_12869)
static void C_ccall f_12869(C_word c,C_word *av) C_noret;
C_noret_decl(f_12895)
static void C_ccall f_12895(C_word c,C_word *av) C_noret;
C_noret_decl(f_12923)
static void C_ccall f_12923(C_word c,C_word *av) C_noret;
C_noret_decl(f_12940)
static void C_ccall f_12940(C_word c,C_word *av) C_noret;
C_noret_decl(f_12946)
static void C_ccall f_12946(C_word c,C_word *av) C_noret;
C_noret_decl(f_12949)
static void C_ccall f_12949(C_word c,C_word *av) C_noret;
C_noret_decl(f_12968)
static void C_ccall f_12968(C_word c,C_word *av) C_noret;
C_noret_decl(f_12986)
static void C_ccall f_12986(C_word c,C_word *av) C_noret;
C_noret_decl(f_12989)
static void C_ccall f_12989(C_word c,C_word *av) C_noret;
C_noret_decl(f_13016)
static void C_ccall f_13016(C_word c,C_word *av) C_noret;
C_noret_decl(f_13043)
static void C_ccall f_13043(C_word c,C_word *av) C_noret;
C_noret_decl(f_13111)
static void C_ccall f_13111(C_word c,C_word *av) C_noret;
C_noret_decl(f_13123)
static void C_ccall f_13123(C_word c,C_word *av) C_noret;
C_noret_decl(f_13139)
static void C_ccall f_13139(C_word c,C_word *av) C_noret;
C_noret_decl(f_13173)
static void C_ccall f_13173(C_word c,C_word *av) C_noret;
C_noret_decl(f_13175)
static void C_ccall f_13175(C_word c,C_word *av) C_noret;
C_noret_decl(f_13198)
static void C_ccall f_13198(C_word c,C_word *av) C_noret;
C_noret_decl(f_13217)
static void C_ccall f_13217(C_word c,C_word *av) C_noret;
C_noret_decl(f_13225)
static void C_ccall f_13225(C_word c,C_word *av) C_noret;
C_noret_decl(f_13227)
static void C_ccall f_13227(C_word c,C_word *av) C_noret;
C_noret_decl(f_13258)
static void C_ccall f_13258(C_word c,C_word *av) C_noret;
C_noret_decl(f_13262)
static void C_ccall f_13262(C_word c,C_word *av) C_noret;
C_noret_decl(f_13264)
static void C_ccall f_13264(C_word c,C_word *av) C_noret;
C_noret_decl(f_13268)
static void C_ccall f_13268(C_word c,C_word *av) C_noret;
C_noret_decl(f_13291)
static void C_ccall f_13291(C_word c,C_word *av) C_noret;
C_noret_decl(f_13306)
static void C_ccall f_13306(C_word c,C_word *av) C_noret;
C_noret_decl(f_13308)
static void C_ccall f_13308(C_word c,C_word *av) C_noret;
C_noret_decl(f_13312)
static void C_ccall f_13312(C_word c,C_word *av) C_noret;
C_noret_decl(f_13315)
static void C_ccall f_13315(C_word c,C_word *av) C_noret;
C_noret_decl(f_13328)
static void C_ccall f_13328(C_word c,C_word *av) C_noret;
C_noret_decl(f_13330)
static void C_ccall f_13330(C_word c,C_word *av) C_noret;
C_noret_decl(f_13334)
static void C_ccall f_13334(C_word c,C_word *av) C_noret;
C_noret_decl(f_13337)
static void C_ccall f_13337(C_word c,C_word *av) C_noret;
C_noret_decl(f_13350)
static void C_ccall f_13350(C_word c,C_word *av) C_noret;
C_noret_decl(f_13352)
static void C_ccall f_13352(C_word c,C_word *av) C_noret;
C_noret_decl(f_13356)
static void C_ccall f_13356(C_word c,C_word *av) C_noret;
C_noret_decl(f_13359)
static void C_ccall f_13359(C_word c,C_word *av) C_noret;
C_noret_decl(f_13372)
static void C_ccall f_13372(C_word c,C_word *av) C_noret;
C_noret_decl(f_13374)
static void C_ccall f_13374(C_word c,C_word *av) C_noret;
C_noret_decl(f_13378)
static void C_ccall f_13378(C_word c,C_word *av) C_noret;
C_noret_decl(f_13389)
static void C_ccall f_13389(C_word c,C_word *av) C_noret;
C_noret_decl(f_13399)
static void C_ccall f_13399(C_word c,C_word *av) C_noret;
C_noret_decl(f_13424)
static void C_ccall f_13424(C_word c,C_word *av) C_noret;
C_noret_decl(f_13426)
static void C_ccall f_13426(C_word c,C_word *av) C_noret;
C_noret_decl(f_13430)
static void C_ccall f_13430(C_word c,C_word *av) C_noret;
C_noret_decl(f_13447)
static void C_ccall f_13447(C_word c,C_word *av) C_noret;
C_noret_decl(f_13450)
static void C_ccall f_13450(C_word c,C_word *av) C_noret;
C_noret_decl(f_13456)
static void C_ccall f_13456(C_word c,C_word *av) C_noret;
C_noret_decl(f_13463)
static void C_ccall f_13463(C_word c,C_word *av) C_noret;
C_noret_decl(f_13467)
static void C_ccall f_13467(C_word c,C_word *av) C_noret;
C_noret_decl(f_13471)
static void C_ccall f_13471(C_word c,C_word *av) C_noret;
C_noret_decl(f_13473)
static void C_ccall f_13473(C_word c,C_word *av) C_noret;
C_noret_decl(f_13477)
static void C_ccall f_13477(C_word c,C_word *av) C_noret;
C_noret_decl(f_13482)
static void C_fcall f_13482(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_13497)
static void C_ccall f_13497(C_word c,C_word *av) C_noret;
C_noret_decl(f_13508)
static void C_ccall f_13508(C_word c,C_word *av) C_noret;
C_noret_decl(f_13511)
static void C_ccall f_13511(C_word c,C_word *av) C_noret;
C_noret_decl(f_13533)
static void C_ccall f_13533(C_word c,C_word *av) C_noret;
C_noret_decl(f_13540)
static void C_ccall f_13540(C_word c,C_word *av) C_noret;
C_noret_decl(f_13544)
static void C_ccall f_13544(C_word c,C_word *av) C_noret;
C_noret_decl(f_13553)
static void C_ccall f_13553(C_word c,C_word *av) C_noret;
C_noret_decl(f_13560)
static void C_ccall f_13560(C_word c,C_word *av) C_noret;
C_noret_decl(f_13563)
static void C_ccall f_13563(C_word c,C_word *av) C_noret;
C_noret_decl(f_13598)
static void C_ccall f_13598(C_word c,C_word *av) C_noret;
C_noret_decl(f_13600)
static void C_ccall f_13600(C_word c,C_word *av) C_noret;
C_noret_decl(f_13604)
static void C_ccall f_13604(C_word c,C_word *av) C_noret;
C_noret_decl(f_13615)
static void C_ccall f_13615(C_word c,C_word *av) C_noret;
C_noret_decl(f_13617)
static void C_ccall f_13617(C_word c,C_word *av) C_noret;
C_noret_decl(f_13621)
static void C_ccall f_13621(C_word c,C_word *av) C_noret;
C_noret_decl(f_13632)
static void C_ccall f_13632(C_word c,C_word *av) C_noret;
C_noret_decl(f_13634)
static void C_ccall f_13634(C_word c,C_word *av) C_noret;
C_noret_decl(f_13638)
static void C_ccall f_13638(C_word c,C_word *av) C_noret;
C_noret_decl(f_13649)
static void C_ccall f_13649(C_word c,C_word *av) C_noret;
C_noret_decl(f_13651)
static void C_ccall f_13651(C_word c,C_word *av) C_noret;
C_noret_decl(f_13655)
static void C_ccall f_13655(C_word c,C_word *av) C_noret;
C_noret_decl(f_13666)
static void C_ccall f_13666(C_word c,C_word *av) C_noret;
C_noret_decl(f_13668)
static void C_ccall f_13668(C_word c,C_word *av) C_noret;
C_noret_decl(f_13672)
static void C_ccall f_13672(C_word c,C_word *av) C_noret;
C_noret_decl(f_13675)
static void C_ccall f_13675(C_word c,C_word *av) C_noret;
C_noret_decl(f_13685)
static void C_ccall f_13685(C_word c,C_word *av) C_noret;
C_noret_decl(f_13689)
static void C_ccall f_13689(C_word c,C_word *av) C_noret;
C_noret_decl(f_13691)
static void C_ccall f_13691(C_word c,C_word *av) C_noret;
C_noret_decl(f_13695)
static void C_ccall f_13695(C_word c,C_word *av) C_noret;
C_noret_decl(f_13698)
static void C_ccall f_13698(C_word c,C_word *av) C_noret;
C_noret_decl(f_13701)
static void C_ccall f_13701(C_word c,C_word *av) C_noret;
C_noret_decl(f_13724)
static void C_ccall f_13724(C_word c,C_word *av) C_noret;
C_noret_decl(f_13727)
static void C_ccall f_13727(C_word c,C_word *av) C_noret;
C_noret_decl(f_13773)
static void C_ccall f_13773(C_word c,C_word *av) C_noret;
C_noret_decl(f_13775)
static void C_ccall f_13775(C_word c,C_word *av) C_noret;
C_noret_decl(f_13779)
static void C_ccall f_13779(C_word c,C_word *av) C_noret;
C_noret_decl(f_13782)
static void C_ccall f_13782(C_word c,C_word *av) C_noret;
C_noret_decl(f_13805)
static void C_ccall f_13805(C_word c,C_word *av) C_noret;
C_noret_decl(f_13833)
static void C_ccall f_13833(C_word c,C_word *av) C_noret;
C_noret_decl(f_13838)
static void C_fcall f_13838(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_13845)
static void C_ccall f_13845(C_word c,C_word *av) C_noret;
C_noret_decl(f_13848)
static void C_ccall f_13848(C_word c,C_word *av) C_noret;
C_noret_decl(f_13857)
static void C_ccall f_13857(C_word c,C_word *av) C_noret;
C_noret_decl(f_13902)
static void C_ccall f_13902(C_word c,C_word *av) C_noret;
C_noret_decl(f_13904)
static void C_fcall f_13904(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_13929)
static void C_ccall f_13929(C_word c,C_word *av) C_noret;
C_noret_decl(f_13940)
static void C_ccall f_13940(C_word c,C_word *av) C_noret;
C_noret_decl(f_13944)
static void C_ccall f_13944(C_word c,C_word *av) C_noret;
C_noret_decl(f_13946)
static void C_ccall f_13946(C_word c,C_word *av) C_noret;
C_noret_decl(f_13954)
static void C_ccall f_13954(C_word c,C_word *av) C_noret;
C_noret_decl(f_13956)
static void C_ccall f_13956(C_word c,C_word *av) C_noret;
C_noret_decl(f_13968)
static void C_fcall f_13968(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14020)
static void C_ccall f_14020(C_word c,C_word *av) C_noret;
C_noret_decl(f_14026)
static void C_ccall f_14026(C_word c,C_word *av) C_noret;
C_noret_decl(f_14029)
static void C_ccall f_14029(C_word c,C_word *av) C_noret;
C_noret_decl(f_14032)
static void C_ccall f_14032(C_word c,C_word *av) C_noret;
C_noret_decl(f_14037)
static void C_fcall f_14037(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14062)
static void C_ccall f_14062(C_word c,C_word *av) C_noret;
C_noret_decl(f_14077)
static void C_ccall f_14077(C_word c,C_word *av) C_noret;
C_noret_decl(f_14079)
static void C_ccall f_14079(C_word c,C_word *av) C_noret;
C_noret_decl(f_14083)
static void C_ccall f_14083(C_word c,C_word *av) C_noret;
C_noret_decl(f_14086)
static void C_ccall f_14086(C_word c,C_word *av) C_noret;
C_noret_decl(f_14089)
static void C_ccall f_14089(C_word c,C_word *av) C_noret;
C_noret_decl(f_14096)
static void C_ccall f_14096(C_word c,C_word *av) C_noret;
C_noret_decl(f_14104)
static void C_ccall f_14104(C_word c,C_word *av) C_noret;
C_noret_decl(f_14106)
static void C_ccall f_14106(C_word c,C_word *av) C_noret;
C_noret_decl(f_14110)
static void C_ccall f_14110(C_word c,C_word *av) C_noret;
C_noret_decl(f_14116)
static void C_ccall f_14116(C_word c,C_word *av) C_noret;
C_noret_decl(f_14122)
static void C_fcall f_14122(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14125)
static void C_ccall f_14125(C_word c,C_word *av) C_noret;
C_noret_decl(f_14137)
static void C_ccall f_14137(C_word c,C_word *av) C_noret;
C_noret_decl(f_14140)
static void C_ccall f_14140(C_word c,C_word *av) C_noret;
C_noret_decl(f_14171)
static void C_ccall f_14171(C_word c,C_word *av) C_noret;
C_noret_decl(f_14175)
static void C_ccall f_14175(C_word c,C_word *av) C_noret;
C_noret_decl(f_14178)
static void C_ccall f_14178(C_word c,C_word *av) C_noret;
C_noret_decl(f_14185)
static void C_ccall f_14185(C_word c,C_word *av) C_noret;
C_noret_decl(f_14194)
static void C_ccall f_14194(C_word c,C_word *av) C_noret;
C_noret_decl(f_14219)
static void C_fcall f_14219(C_word t0,C_word t1) C_noret;
C_noret_decl(f_14253)
static void C_ccall f_14253(C_word c,C_word *av) C_noret;
C_noret_decl(f_14267)
static void C_ccall f_14267(C_word c,C_word *av) C_noret;
C_noret_decl(f_14279)
static void C_ccall f_14279(C_word c,C_word *av) C_noret;
C_noret_decl(f_14281)
static void C_ccall f_14281(C_word c,C_word *av) C_noret;
C_noret_decl(f_14287)
static void C_fcall f_14287(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14297)
static void C_fcall f_14297(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14311)
static void C_ccall f_14311(C_word c,C_word *av) C_noret;
C_noret_decl(f_14327)
static void C_ccall f_14327(C_word c,C_word *av) C_noret;
C_noret_decl(f_14351)
static void C_ccall f_14351(C_word c,C_word *av) C_noret;
C_noret_decl(f_14386)
static void C_ccall f_14386(C_word c,C_word *av) C_noret;
C_noret_decl(f_14420)
static void C_ccall f_14420(C_word c,C_word *av) C_noret;
C_noret_decl(f_14442)
static void C_fcall f_14442(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14467)
static void C_ccall f_14467(C_word c,C_word *av) C_noret;
C_noret_decl(f_14469)
static void C_fcall f_14469(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14548)
static void C_ccall f_14548(C_word c,C_word *av) C_noret;
C_noret_decl(f_14560)
static void C_ccall f_14560(C_word c,C_word *av) C_noret;
C_noret_decl(f_14572)
static void C_ccall f_14572(C_word c,C_word *av) C_noret;
C_noret_decl(f_14574)
static void C_ccall f_14574(C_word c,C_word *av) C_noret;
C_noret_decl(f_14578)
static void C_ccall f_14578(C_word c,C_word *av) C_noret;
C_noret_decl(f_14589)
static void C_ccall f_14589(C_word c,C_word *av) C_noret;
C_noret_decl(f_14599)
static void C_ccall f_14599(C_word c,C_word *av) C_noret;
C_noret_decl(f_14607)
static void C_ccall f_14607(C_word c,C_word *av) C_noret;
C_noret_decl(f_14609)
static void C_ccall f_14609(C_word c,C_word *av) C_noret;
C_noret_decl(f_14618)
static void C_fcall f_14618(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14624)
static void C_ccall f_14624(C_word c,C_word *av) C_noret;
C_noret_decl(f_14630)
static void C_ccall f_14630(C_word c,C_word *av) C_noret;
C_noret_decl(f_14634)
static void C_ccall f_14634(C_word c,C_word *av) C_noret;
C_noret_decl(f_14637)
static void C_ccall f_14637(C_word c,C_word *av) C_noret;
C_noret_decl(f_14640)
static void C_ccall f_14640(C_word c,C_word *av) C_noret;
C_noret_decl(f_14671)
static void C_ccall f_14671(C_word c,C_word *av) C_noret;
C_noret_decl(f_14680)
static void C_ccall f_14680(C_word c,C_word *av) C_noret;
C_noret_decl(f_14682)
static void C_fcall f_14682(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_14707)
static void C_ccall f_14707(C_word c,C_word *av) C_noret;
C_noret_decl(f_14718)
static void C_ccall f_14718(C_word c,C_word *av) C_noret;
C_noret_decl(f_14720)
static void C_ccall f_14720(C_word c,C_word *av) C_noret;
C_noret_decl(f_14728)
static void C_ccall f_14728(C_word c,C_word *av) C_noret;
C_noret_decl(f_14730)
static void C_ccall f_14730(C_word c,C_word *av) C_noret;
C_noret_decl(f_4499)
static void C_ccall f_4499(C_word c,C_word *av) C_noret;
C_noret_decl(f_4502)
static void C_ccall f_4502(C_word c,C_word *av) C_noret;
C_noret_decl(f_4505)
static void C_ccall f_4505(C_word c,C_word *av) C_noret;
C_noret_decl(f_5788)
static void C_ccall f_5788(C_word c,C_word *av) C_noret;
C_noret_decl(f_5792)
static void C_ccall f_5792(C_word c,C_word *av) C_noret;
C_noret_decl(f_5794)
static C_word C_fcall f_5794(C_word t0,C_word t1);
C_noret_decl(f_5811)
static void C_fcall f_5811(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5818)
static void C_ccall f_5818(C_word c,C_word *av) C_noret;
C_noret_decl(f_5824)
static void C_ccall f_5824(C_word c,C_word *av) C_noret;
C_noret_decl(f_5858)
static void C_ccall f_5858(C_word c,C_word *av) C_noret;
C_noret_decl(f_5864)
static void C_fcall f_5864(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5880)
static void C_ccall f_5880(C_word c,C_word *av) C_noret;
C_noret_decl(f_5935)
static void C_ccall f_5935(C_word c,C_word *av) C_noret;
C_noret_decl(f_5942)
static void C_ccall f_5942(C_word c,C_word *av) C_noret;
C_noret_decl(f_5960)
static void C_ccall f_5960(C_word c,C_word *av) C_noret;
C_noret_decl(f_5969)
static void C_fcall f_5969(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_5990)
static void C_ccall f_5990(C_word c,C_word *av) C_noret;
C_noret_decl(f_6000)
static void C_ccall f_6000(C_word c,C_word *av) C_noret;
C_noret_decl(f_6004)
static void C_ccall f_6004(C_word c,C_word *av) C_noret;
C_noret_decl(f_6029)
static void C_ccall f_6029(C_word c,C_word *av) C_noret;
C_noret_decl(f_6044)
static void C_ccall f_6044(C_word c,C_word *av) C_noret;
C_noret_decl(f_6046)
static void C_fcall f_6046(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6094)
static void C_fcall f_6094(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_6143)
static void C_fcall f_6143(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6168)
static void C_ccall f_6168(C_word c,C_word *av) C_noret;
C_noret_decl(f_6182)
static void C_ccall f_6182(C_word c,C_word *av) C_noret;
C_noret_decl(f_6191)
static void C_ccall f_6191(C_word c,C_word *av) C_noret;
C_noret_decl(f_6215)
static void C_ccall f_6215(C_word c,C_word *av) C_noret;
C_noret_decl(f_6219)
static void C_ccall f_6219(C_word c,C_word *av) C_noret;
C_noret_decl(f_6222)
static void C_ccall f_6222(C_word c,C_word *av) C_noret;
C_noret_decl(f_6229)
static C_word C_fcall f_6229(C_word t0,C_word t1);
C_noret_decl(f_6247)
static void C_ccall f_6247(C_word c,C_word *av) C_noret;
C_noret_decl(f_6257)
static void C_ccall f_6257(C_word c,C_word *av) C_noret;
C_noret_decl(f_6261)
static void C_ccall f_6261(C_word c,C_word *av) C_noret;
C_noret_decl(f_6283)
static void C_ccall f_6283(C_word c,C_word *av) C_noret;
C_noret_decl(f_6294)
static void C_ccall f_6294(C_word c,C_word *av) C_noret;
C_noret_decl(f_6302)
static void C_ccall f_6302(C_word c,C_word *av) C_noret;
C_noret_decl(f_6306)
static void C_ccall f_6306(C_word c,C_word *av) C_noret;
C_noret_decl(f_6308)
static void C_fcall f_6308(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6331)
static void C_ccall f_6331(C_word c,C_word *av) C_noret;
C_noret_decl(f_6339)
static void C_ccall f_6339(C_word c,C_word *av) C_noret;
C_noret_decl(f_6342)
static void C_fcall f_6342(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_6352)
static void C_ccall f_6352(C_word c,C_word *av) C_noret;
C_noret_decl(f_6357)
static void C_ccall f_6357(C_word c,C_word *av) C_noret;
C_noret_decl(f_6363)
static void C_ccall f_6363(C_word c,C_word *av) C_noret;
C_noret_decl(f_6369)
static void C_ccall f_6369(C_word c,C_word *av) C_noret;
C_noret_decl(f_6391)
static void C_ccall f_6391(C_word c,C_word *av) C_noret;
C_noret_decl(f_6397)
static void C_fcall f_6397(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6414)
static void C_fcall f_6414(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6425)
static void C_ccall f_6425(C_word c,C_word *av) C_noret;
C_noret_decl(f_6464)
static void C_ccall f_6464(C_word c,C_word *av) C_noret;
C_noret_decl(f_6470)
static void C_ccall f_6470(C_word c,C_word *av) C_noret;
C_noret_decl(f_6474)
static void C_ccall f_6474(C_word c,C_word *av) C_noret;
C_noret_decl(f_6477)
static void C_ccall f_6477(C_word c,C_word *av) C_noret;
C_noret_decl(f_6493)
static void C_ccall f_6493(C_word c,C_word *av) C_noret;
C_noret_decl(f_6497)
static void C_ccall f_6497(C_word c,C_word *av) C_noret;
C_noret_decl(f_6504)
static void C_ccall f_6504(C_word c,C_word *av) C_noret;
C_noret_decl(f_6510)
static void C_ccall f_6510(C_word c,C_word *av) C_noret;
C_noret_decl(f_6515)
static void C_ccall f_6515(C_word c,C_word *av) C_noret;
C_noret_decl(f_6521)
static void C_ccall f_6521(C_word c,C_word *av) C_noret;
C_noret_decl(f_6529)
static void C_ccall f_6529(C_word c,C_word *av) C_noret;
C_noret_decl(f_6535)
static void C_ccall f_6535(C_word c,C_word *av) C_noret;
C_noret_decl(f_6541)
static void C_fcall f_6541(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_6567)
static void C_ccall f_6567(C_word c,C_word *av) C_noret;
C_noret_decl(f_6585)
static void C_fcall f_6585(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6609)
static void C_fcall f_6609(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6615)
static void C_fcall f_6615(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6627)
static void C_ccall f_6627(C_word c,C_word *av) C_noret;
C_noret_decl(f_6639)
static void C_ccall f_6639(C_word c,C_word *av) C_noret;
C_noret_decl(f_6664)
static void C_ccall f_6664(C_word c,C_word *av) C_noret;
C_noret_decl(f_6666)
static void C_fcall f_6666(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6729)
static void C_ccall f_6729(C_word c,C_word *av) C_noret;
C_noret_decl(f_6735)
static void C_fcall f_6735(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6773)
static void C_fcall f_6773(C_word t0,C_word t1) C_noret;
C_noret_decl(f_6777)
static void C_fcall f_6777(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6781)
static void C_ccall f_6781(C_word c,C_word *av) C_noret;
C_noret_decl(f_6793)
static void C_ccall f_6793(C_word c,C_word *av) C_noret;
C_noret_decl(f_6832)
static void C_ccall f_6832(C_word c,C_word *av) C_noret;
C_noret_decl(f_6846)
static void C_ccall f_6846(C_word c,C_word *av) C_noret;
C_noret_decl(f_6856)
static void C_ccall f_6856(C_word c,C_word *av) C_noret;
C_noret_decl(f_6859)
static void C_ccall f_6859(C_word c,C_word *av) C_noret;
C_noret_decl(f_6863)
static void C_ccall f_6863(C_word c,C_word *av) C_noret;
C_noret_decl(f_6877)
static void C_fcall f_6877(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6883)
static void C_ccall f_6883(C_word c,C_word *av) C_noret;
C_noret_decl(f_6889)
static void C_ccall f_6889(C_word c,C_word *av) C_noret;
C_noret_decl(f_6925)
static void C_ccall f_6925(C_word c,C_word *av) C_noret;
C_noret_decl(f_6931)
static C_word C_fcall f_6931(C_word t0);
C_noret_decl(f_6972)
static void C_ccall f_6972(C_word c,C_word *av) C_noret;
C_noret_decl(f_6975)
static void C_fcall f_6975(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_6992)
static void C_ccall f_6992(C_word c,C_word *av) C_noret;
C_noret_decl(f_6995)
static void C_ccall f_6995(C_word c,C_word *av) C_noret;
C_noret_decl(f_6998)
static void C_ccall f_6998(C_word c,C_word *av) C_noret;
C_noret_decl(f_7003)
static void C_fcall f_7003(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6) C_noret;
C_noret_decl(f_7017)
static void C_ccall f_7017(C_word c,C_word *av) C_noret;
C_noret_decl(f_7021)
static void C_fcall f_7021(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7033)
static void C_fcall f_7033(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7064)
static void C_ccall f_7064(C_word c,C_word *av) C_noret;
C_noret_decl(f_7089)
static void C_ccall f_7089(C_word c,C_word *av) C_noret;
C_noret_decl(f_7108)
static void C_ccall f_7108(C_word c,C_word *av) C_noret;
C_noret_decl(f_7112)
static void C_ccall f_7112(C_word c,C_word *av) C_noret;
C_noret_decl(f_7161)
static void C_fcall f_7161(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7214)
static void C_ccall f_7214(C_word c,C_word *av) C_noret;
C_noret_decl(f_7218)
static void C_ccall f_7218(C_word c,C_word *av) C_noret;
C_noret_decl(f_7221)
static void C_ccall f_7221(C_word c,C_word *av) C_noret;
C_noret_decl(f_7224)
static void C_ccall f_7224(C_word c,C_word *av) C_noret;
C_noret_decl(f_7226)
static void C_fcall f_7226(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7251)
static void C_ccall f_7251(C_word c,C_word *av) C_noret;
C_noret_decl(f_7265)
static void C_ccall f_7265(C_word c,C_word *av) C_noret;
C_noret_decl(f_7306)
static void C_fcall f_7306(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7319)
static void C_fcall f_7319(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7335)
static void C_ccall f_7335(C_word c,C_word *av) C_noret;
C_noret_decl(f_7356)
static void C_fcall f_7356(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7395)
static void C_fcall f_7395(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7414)
static void C_ccall f_7414(C_word c,C_word *av) C_noret;
C_noret_decl(f_7482)
static void C_fcall f_7482(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7581)
static void C_ccall f_7581(C_word c,C_word *av) C_noret;
C_noret_decl(f_7587)
static void C_ccall f_7587(C_word c,C_word *av) C_noret;
C_noret_decl(f_7591)
static void C_ccall f_7591(C_word c,C_word *av) C_noret;
C_noret_decl(f_7594)
static void C_ccall f_7594(C_word c,C_word *av) C_noret;
C_noret_decl(f_7613)
static void C_ccall f_7613(C_word c,C_word *av) C_noret;
C_noret_decl(f_7617)
static void C_ccall f_7617(C_word c,C_word *av) C_noret;
C_noret_decl(f_7635)
static void C_ccall f_7635(C_word c,C_word *av) C_noret;
C_noret_decl(f_7657)
static void C_fcall f_7657(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7723)
static void C_fcall f_7723(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7748)
static void C_ccall f_7748(C_word c,C_word *av) C_noret;
C_noret_decl(f_7761)
static void C_ccall f_7761(C_word c,C_word *av) C_noret;
C_noret_decl(f_7765)
static void C_ccall f_7765(C_word c,C_word *av) C_noret;
C_noret_decl(f_7776)
static void C_fcall f_7776(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7783)
static void C_fcall f_7783(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7792)
static void C_fcall f_7792(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7812)
static void C_ccall f_7812(C_word c,C_word *av) C_noret;
C_noret_decl(f_7823)
static void C_ccall f_7823(C_word c,C_word *av) C_noret;
C_noret_decl(f_7825)
static void C_fcall f_7825(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7827)
static void C_ccall f_7827(C_word c,C_word *av) C_noret;
C_noret_decl(f_7833)
static void C_fcall f_7833(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7840)
static void C_fcall f_7840(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7849)
static void C_fcall f_7849(C_word t0,C_word t1) C_noret;
C_noret_decl(f_7885)
static void C_ccall f_7885(C_word c,C_word *av) C_noret;
C_noret_decl(f_7896)
static void C_ccall f_7896(C_word c,C_word *av) C_noret;
C_noret_decl(f_7900)
static void C_ccall f_7900(C_word c,C_word *av) C_noret;
C_noret_decl(f_7904)
static void C_ccall f_7904(C_word c,C_word *av) C_noret;
C_noret_decl(f_7908)
static void C_ccall f_7908(C_word c,C_word *av) C_noret;
C_noret_decl(f_7912)
static void C_ccall f_7912(C_word c,C_word *av) C_noret;
C_noret_decl(f_7914)
static void C_ccall f_7914(C_word c,C_word *av) C_noret;
C_noret_decl(f_7926)
static void C_fcall f_7926(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_7940)
static void C_ccall f_7940(C_word c,C_word *av) C_noret;
C_noret_decl(f_7945)
static void C_fcall f_7945(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_7956)
static void C_ccall f_7956(C_word c,C_word *av) C_noret;
C_noret_decl(f_7962)
static void C_ccall f_7962(C_word c,C_word *av) C_noret;
C_noret_decl(f_7976)
static void C_ccall f_7976(C_word c,C_word *av) C_noret;
C_noret_decl(f_7980)
static void C_ccall f_7980(C_word c,C_word *av) C_noret;
C_noret_decl(f_7988)
static void C_ccall f_7988(C_word c,C_word *av) C_noret;
C_noret_decl(f_7995)
static void C_ccall f_7995(C_word c,C_word *av) C_noret;
C_noret_decl(f_8007)
static void C_ccall f_8007(C_word c,C_word *av) C_noret;
C_noret_decl(f_8014)
static void C_ccall f_8014(C_word c,C_word *av) C_noret;
C_noret_decl(f_8018)
static void C_ccall f_8018(C_word c,C_word *av) C_noret;
C_noret_decl(f_8025)
static void C_ccall f_8025(C_word c,C_word *av) C_noret;
C_noret_decl(f_8056)
static void C_ccall f_8056(C_word c,C_word *av) C_noret;
C_noret_decl(f_8085)
static void C_ccall f_8085(C_word c,C_word *av) C_noret;
C_noret_decl(f_8117)
static void C_ccall f_8117(C_word c,C_word *av) C_noret;
C_noret_decl(f_8123)
static void C_ccall f_8123(C_word c,C_word *av) C_noret;
C_noret_decl(f_8129)
static void C_ccall f_8129(C_word c,C_word *av) C_noret;
C_noret_decl(f_8135)
static void C_ccall f_8135(C_word c,C_word *av) C_noret;
C_noret_decl(f_8167)
static void C_ccall f_8167(C_word c,C_word *av) C_noret;
C_noret_decl(f_8170)
static void C_ccall f_8170(C_word c,C_word *av) C_noret;
C_noret_decl(f_8176)
static void C_ccall f_8176(C_word c,C_word *av) C_noret;
C_noret_decl(f_8180)
static void C_ccall f_8180(C_word c,C_word *av) C_noret;
C_noret_decl(f_8202)
static void C_ccall f_8202(C_word c,C_word *av) C_noret;
C_noret_decl(f_8205)
static void C_ccall f_8205(C_word c,C_word *av) C_noret;
C_noret_decl(f_8208)
static void C_ccall f_8208(C_word c,C_word *av) C_noret;
C_noret_decl(f_8211)
static void C_ccall f_8211(C_word c,C_word *av) C_noret;
C_noret_decl(f_8213)
static void C_fcall f_8213(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_8220)
static void C_fcall f_8220(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8246)
static void C_ccall f_8246(C_word c,C_word *av) C_noret;
C_noret_decl(f_8275)
static void C_fcall f_8275(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8309)
static void C_fcall f_8309(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8333)
static void C_ccall f_8333(C_word c,C_word *av) C_noret;
C_noret_decl(f_8335)
static void C_ccall f_8335(C_word c,C_word *av) C_noret;
C_noret_decl(f_8339)
static void C_ccall f_8339(C_word c,C_word *av) C_noret;
C_noret_decl(f_8351)
static void C_ccall f_8351(C_word c,C_word *av) C_noret;
C_noret_decl(f_8359)
static void C_ccall f_8359(C_word c,C_word *av) C_noret;
C_noret_decl(f_8361)
static void C_fcall f_8361(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_8383)
static void C_ccall f_8383(C_word c,C_word *av) C_noret;
C_noret_decl(f_8386)
static void C_ccall f_8386(C_word c,C_word *av) C_noret;
C_noret_decl(f_8388)
static void C_fcall f_8388(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8435)
static void C_ccall f_8435(C_word c,C_word *av) C_noret;
C_noret_decl(f_8439)
static void C_ccall f_8439(C_word c,C_word *av) C_noret;
C_noret_decl(f_8507)
static void C_ccall f_8507(C_word c,C_word *av) C_noret;
C_noret_decl(f_8513)
static void C_fcall f_8513(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5) C_noret;
C_noret_decl(f_8536)
static void C_fcall f_8536(C_word t0,C_word t1) C_noret;
C_noret_decl(f_8551)
static void C_ccall f_8551(C_word c,C_word *av) C_noret;
C_noret_decl(f_8554)
static void C_ccall f_8554(C_word c,C_word *av) C_noret;
C_noret_decl(f_8559)
static void C_fcall f_8559(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_8572)
static void C_ccall f_8572(C_word c,C_word *av) C_noret;
C_noret_decl(f_8575)
static void C_ccall f_8575(C_word c,C_word *av) C_noret;
C_noret_decl(f_8625)
static void C_ccall f_8625(C_word c,C_word *av) C_noret;
C_noret_decl(f_8632)
static void C_ccall f_8632(C_word c,C_word *av) C_noret;
C_noret_decl(f_8639)
static void C_ccall f_8639(C_word c,C_word *av) C_noret;
C_noret_decl(f_8688)
static void C_ccall f_8688(C_word c,C_word *av) C_noret;
C_noret_decl(f_8691)
static void C_ccall f_8691(C_word c,C_word *av) C_noret;
C_noret_decl(f_8700)
static void C_ccall f_8700(C_word c,C_word *av) C_noret;
C_noret_decl(f_8703)
static void C_ccall f_8703(C_word c,C_word *av) C_noret;
C_noret_decl(f_8732)
static void C_ccall f_8732(C_word c,C_word *av) C_noret;
C_noret_decl(f_8739)
static void C_ccall f_8739(C_word c,C_word *av) C_noret;
C_noret_decl(f_8755)
static void C_ccall f_8755(C_word c,C_word *av) C_noret;
C_noret_decl(f_8825)
static void C_ccall f_8825(C_word c,C_word *av) C_noret;
C_noret_decl(f_8828)
static void C_fcall f_8828(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8842)
static C_word C_fcall f_8842(C_word t0,C_word t1);
C_noret_decl(f_8882)
static void C_ccall f_8882(C_word c,C_word *av) C_noret;
C_noret_decl(f_8905)
static void C_ccall f_8905(C_word c,C_word *av) C_noret;
C_noret_decl(f_8907)
static void C_ccall f_8907(C_word c,C_word *av) C_noret;
C_noret_decl(f_8910)
static void C_fcall f_8910(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_8954)
static void C_ccall f_8954(C_word c,C_word *av) C_noret;
C_noret_decl(f_8962)
static void C_ccall f_8962(C_word c,C_word *av) C_noret;
C_noret_decl(f_8970)
static void C_ccall f_8970(C_word c,C_word *av) C_noret;
C_noret_decl(f_8973)
static void C_ccall f_8973(C_word c,C_word *av) C_noret;
C_noret_decl(f_8984)
static void C_ccall f_8984(C_word c,C_word *av) C_noret;
C_noret_decl(f_8989)
static void C_fcall f_8989(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9009)
static void C_ccall f_9009(C_word c,C_word *av) C_noret;
C_noret_decl(f_9013)
static void C_ccall f_9013(C_word c,C_word *av) C_noret;
C_noret_decl(f_9028)
static void C_ccall f_9028(C_word c,C_word *av) C_noret;
C_noret_decl(f_9040)
static void C_ccall f_9040(C_word c,C_word *av) C_noret;
C_noret_decl(f_9042)
static void C_fcall f_9042(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9049)
static void C_ccall f_9049(C_word c,C_word *av) C_noret;
C_noret_decl(f_9056)
static void C_ccall f_9056(C_word c,C_word *av) C_noret;
C_noret_decl(f_9058)
static void C_fcall f_9058(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9068)
static void C_ccall f_9068(C_word c,C_word *av) C_noret;
C_noret_decl(f_9071)
static void C_ccall f_9071(C_word c,C_word *av) C_noret;
C_noret_decl(f_9074)
static void C_ccall f_9074(C_word c,C_word *av) C_noret;
C_noret_decl(f_9077)
static void C_ccall f_9077(C_word c,C_word *av) C_noret;
C_noret_decl(f_9080)
static void C_ccall f_9080(C_word c,C_word *av) C_noret;
C_noret_decl(f_9087)
static void C_ccall f_9087(C_word c,C_word *av) C_noret;
C_noret_decl(f_9094)
static void C_ccall f_9094(C_word c,C_word *av) C_noret;
C_noret_decl(f_9097)
static void C_ccall f_9097(C_word c,C_word *av) C_noret;
C_noret_decl(f_9106)
static void C_ccall f_9106(C_word c,C_word *av) C_noret;
C_noret_decl(f_9109)
static void C_ccall f_9109(C_word c,C_word *av) C_noret;
C_noret_decl(f_9112)
static void C_ccall f_9112(C_word c,C_word *av) C_noret;
C_noret_decl(f_9115)
static void C_ccall f_9115(C_word c,C_word *av) C_noret;
C_noret_decl(f_9118)
static void C_ccall f_9118(C_word c,C_word *av) C_noret;
C_noret_decl(f_9121)
static void C_ccall f_9121(C_word c,C_word *av) C_noret;
C_noret_decl(f_9134)
static void C_ccall f_9134(C_word c,C_word *av) C_noret;
C_noret_decl(f_9138)
static void C_ccall f_9138(C_word c,C_word *av) C_noret;
C_noret_decl(f_9149)
static void C_ccall f_9149(C_word c,C_word *av) C_noret;
C_noret_decl(f_9153)
static void C_ccall f_9153(C_word c,C_word *av) C_noret;
C_noret_decl(f_9155)
static void C_fcall f_9155(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9169)
static void C_ccall f_9169(C_word c,C_word *av) C_noret;
C_noret_decl(f_9173)
static void C_ccall f_9173(C_word c,C_word *av) C_noret;
C_noret_decl(f_9200)
static void C_fcall f_9200(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9206)
static void C_fcall f_9206(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9226)
static void C_fcall f_9226(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9250)
static void C_ccall f_9250(C_word c,C_word *av) C_noret;
C_noret_decl(f_9254)
static void C_ccall f_9254(C_word c,C_word *av) C_noret;
C_noret_decl(f_9260)
static void C_ccall f_9260(C_word c,C_word *av) C_noret;
C_noret_decl(f_9266)
static void C_ccall f_9266(C_word c,C_word *av) C_noret;
C_noret_decl(f_9279)
static void C_ccall f_9279(C_word c,C_word *av) C_noret;
C_noret_decl(f_9301)
static void C_ccall f_9301(C_word c,C_word *av) C_noret;
C_noret_decl(f_9318)
static void C_ccall f_9318(C_word c,C_word *av) C_noret;
C_noret_decl(f_9326)
static void C_ccall f_9326(C_word c,C_word *av) C_noret;
C_noret_decl(f_9346)
static void C_ccall f_9346(C_word c,C_word *av) C_noret;
C_noret_decl(f_9350)
static void C_fcall f_9350(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9354)
static void C_ccall f_9354(C_word c,C_word *av) C_noret;
C_noret_decl(f_9365)
static void C_ccall f_9365(C_word c,C_word *av) C_noret;
C_noret_decl(f_9372)
static void C_ccall f_9372(C_word c,C_word *av) C_noret;
C_noret_decl(f_9375)
static void C_ccall f_9375(C_word c,C_word *av) C_noret;
C_noret_decl(f_9379)
static void C_fcall f_9379(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9406)
static void C_ccall f_9406(C_word c,C_word *av) C_noret;
C_noret_decl(f_9412)
static void C_ccall f_9412(C_word c,C_word *av) C_noret;
C_noret_decl(f_9419)
static void C_ccall f_9419(C_word c,C_word *av) C_noret;
C_noret_decl(f_9422)
static void C_ccall f_9422(C_word c,C_word *av) C_noret;
C_noret_decl(f_9425)
static void C_ccall f_9425(C_word c,C_word *av) C_noret;
C_noret_decl(f_9438)
static void C_ccall f_9438(C_word c,C_word *av) C_noret;
C_noret_decl(f_9440)
static void C_fcall f_9440(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9474)
static void C_ccall f_9474(C_word c,C_word *av) C_noret;
C_noret_decl(f_9477)
static void C_fcall f_9477(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9483)
static void C_fcall f_9483(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9493)
static void C_ccall f_9493(C_word c,C_word *av) C_noret;
C_noret_decl(f_9502)
static void C_fcall f_9502(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9519)
static void C_ccall f_9519(C_word c,C_word *av) C_noret;
C_noret_decl(f_9525)
static void C_ccall f_9525(C_word c,C_word *av) C_noret;
C_noret_decl(f_9556)
static void C_ccall f_9556(C_word c,C_word *av) C_noret;
C_noret_decl(f_9566)
static void C_ccall f_9566(C_word c,C_word *av) C_noret;
C_noret_decl(f_9571)
static void C_fcall f_9571(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4) C_noret;
C_noret_decl(f_9578)
static void C_ccall f_9578(C_word c,C_word *av) C_noret;
C_noret_decl(f_9583)
static void C_fcall f_9583(C_word t0,C_word t1,C_word t2) C_noret;
C_noret_decl(f_9587)
static void C_ccall f_9587(C_word c,C_word *av) C_noret;
C_noret_decl(f_9594)
static void C_ccall f_9594(C_word c,C_word *av) C_noret;
C_noret_decl(f_9601)
static void C_ccall f_9601(C_word c,C_word *av) C_noret;
C_noret_decl(f_9608)
static void C_ccall f_9608(C_word c,C_word *av) C_noret;
C_noret_decl(f_9610)
static void C_ccall f_9610(C_word c,C_word *av) C_noret;
C_noret_decl(f_9614)
static void C_ccall f_9614(C_word c,C_word *av) C_noret;
C_noret_decl(f_9622)
static C_word C_fcall f_9622(C_word t0);
C_noret_decl(f_9655)
static void C_ccall f_9655(C_word c,C_word *av) C_noret;
C_noret_decl(f_9661)
static void C_ccall f_9661(C_word c,C_word *av) C_noret;
C_noret_decl(f_9667)
static C_word C_fcall f_9667(C_word t0);
C_noret_decl(f_9688)
static void C_fcall f_9688(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9693)
static void C_fcall f_9693(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9712)
static void C_fcall f_9712(C_word t0,C_word t1) C_noret;
C_noret_decl(f_9717)
static void C_fcall f_9717(C_word t0,C_word t1,C_word t2,C_word t3) C_noret;
C_noret_decl(f_9736)
static void C_ccall f_9736(C_word c,C_word *av) C_noret;
C_noret_decl(f_9890)
static void C_ccall f_9890(C_word c,C_word *av) C_noret;
C_noret_decl(f_9947)
static void C_ccall f_9947(C_word c,C_word *av) C_noret;
C_noret_decl(C_expand_toplevel)
C_externexport void C_ccall C_expand_toplevel(C_word c,C_word *av) C_noret;

C_noret_decl(trf_10000)
static void C_ccall trf_10000(C_word c,C_word *av) C_noret;
static void C_ccall trf_10000(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10000(t0,t1,t2);}

C_noret_decl(trf_10009)
static void C_ccall trf_10009(C_word c,C_word *av) C_noret;
static void C_ccall trf_10009(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10009(t0,t1,t2);}

C_noret_decl(trf_10203)
static void C_ccall trf_10203(C_word c,C_word *av) C_noret;
static void C_ccall trf_10203(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10203(t0,t1,t2,t3);}

C_noret_decl(trf_10255)
static void C_ccall trf_10255(C_word c,C_word *av) C_noret;
static void C_ccall trf_10255(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10255(t0,t1);}

C_noret_decl(trf_10263)
static void C_ccall trf_10263(C_word c,C_word *av) C_noret;
static void C_ccall trf_10263(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10263(t0,t1);}

C_noret_decl(trf_10388)
static void C_ccall trf_10388(C_word c,C_word *av) C_noret;
static void C_ccall trf_10388(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10388(t0,t1,t2);}

C_noret_decl(trf_10674)
static void C_ccall trf_10674(C_word c,C_word *av) C_noret;
static void C_ccall trf_10674(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_10674(t0,t1,t2,t3);}

C_noret_decl(trf_10893)
static void C_ccall trf_10893(C_word c,C_word *av) C_noret;
static void C_ccall trf_10893(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_10893(t0,t1,t2);}

C_noret_decl(trf_10942)
static void C_ccall trf_10942(C_word c,C_word *av) C_noret;
static void C_ccall trf_10942(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_10942(t0,t1);}

C_noret_decl(trf_11149)
static void C_ccall trf_11149(C_word c,C_word *av) C_noret;
static void C_ccall trf_11149(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11149(t0,t1);}

C_noret_decl(trf_11512)
static void C_ccall trf_11512(C_word c,C_word *av) C_noret;
static void C_ccall trf_11512(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11512(t0,t1);}

C_noret_decl(trf_11538)
static void C_ccall trf_11538(C_word c,C_word *av) C_noret;
static void C_ccall trf_11538(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_11538(t0,t1,t2,t3);}

C_noret_decl(trf_11559)
static void C_ccall trf_11559(C_word c,C_word *av) C_noret;
static void C_ccall trf_11559(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11559(t0,t1);}

C_noret_decl(trf_11889)
static void C_ccall trf_11889(C_word c,C_word *av) C_noret;
static void C_ccall trf_11889(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_11889(t0,t1,t2);}

C_noret_decl(trf_11954)
static void C_ccall trf_11954(C_word c,C_word *av) C_noret;
static void C_ccall trf_11954(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_11954(t0,t1);}

C_noret_decl(trf_12023)
static void C_ccall trf_12023(C_word c,C_word *av) C_noret;
static void C_ccall trf_12023(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12023(t0,t1,t2,t3);}

C_noret_decl(trf_12033)
static void C_ccall trf_12033(C_word c,C_word *av) C_noret;
static void C_ccall trf_12033(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12033(t0,t1,t2,t3);}

C_noret_decl(trf_12196)
static void C_ccall trf_12196(C_word c,C_word *av) C_noret;
static void C_ccall trf_12196(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12196(t0,t1,t2);}

C_noret_decl(trf_12204)
static void C_ccall trf_12204(C_word c,C_word *av) C_noret;
static void C_ccall trf_12204(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12204(t0,t1,t2);}

C_noret_decl(trf_12230)
static void C_ccall trf_12230(C_word c,C_word *av) C_noret;
static void C_ccall trf_12230(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12230(t0,t1,t2);}

C_noret_decl(trf_12369)
static void C_ccall trf_12369(C_word c,C_word *av) C_noret;
static void C_ccall trf_12369(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12369(t0,t1);}

C_noret_decl(trf_12412)
static void C_ccall trf_12412(C_word c,C_word *av) C_noret;
static void C_ccall trf_12412(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12412(t0,t1,t2);}

C_noret_decl(trf_12422)
static void C_ccall trf_12422(C_word c,C_word *av) C_noret;
static void C_ccall trf_12422(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12422(t0,t1);}

C_noret_decl(trf_12462)
static void C_ccall trf_12462(C_word c,C_word *av) C_noret;
static void C_ccall trf_12462(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12462(t0,t1,t2);}

C_noret_decl(trf_12514)
static void C_ccall trf_12514(C_word c,C_word *av) C_noret;
static void C_ccall trf_12514(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12514(t0,t1,t2);}

C_noret_decl(trf_12588)
static void C_ccall trf_12588(C_word c,C_word *av) C_noret;
static void C_ccall trf_12588(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12588(t0,t1,t2,t3);}

C_noret_decl(trf_12680)
static void C_ccall trf_12680(C_word c,C_word *av) C_noret;
static void C_ccall trf_12680(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_12680(t0,t1);}

C_noret_decl(trf_12737)
static void C_ccall trf_12737(C_word c,C_word *av) C_noret;
static void C_ccall trf_12737(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_12737(t0,t1,t2);}

C_noret_decl(trf_12805)
static void C_ccall trf_12805(C_word c,C_word *av) C_noret;
static void C_ccall trf_12805(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_12805(t0,t1,t2,t3);}

C_noret_decl(trf_13482)
static void C_ccall trf_13482(C_word c,C_word *av) C_noret;
static void C_ccall trf_13482(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_13482(t0,t1,t2);}

C_noret_decl(trf_13838)
static void C_ccall trf_13838(C_word c,C_word *av) C_noret;
static void C_ccall trf_13838(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_13838(t0,t1,t2);}

C_noret_decl(trf_13904)
static void C_ccall trf_13904(C_word c,C_word *av) C_noret;
static void C_ccall trf_13904(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_13904(t0,t1,t2);}

C_noret_decl(trf_13968)
static void C_ccall trf_13968(C_word c,C_word *av) C_noret;
static void C_ccall trf_13968(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_13968(t0,t1);}

C_noret_decl(trf_14037)
static void C_ccall trf_14037(C_word c,C_word *av) C_noret;
static void C_ccall trf_14037(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14037(t0,t1,t2);}

C_noret_decl(trf_14122)
static void C_ccall trf_14122(C_word c,C_word *av) C_noret;
static void C_ccall trf_14122(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14122(t0,t1);}

C_noret_decl(trf_14219)
static void C_ccall trf_14219(C_word c,C_word *av) C_noret;
static void C_ccall trf_14219(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_14219(t0,t1);}

C_noret_decl(trf_14287)
static void C_ccall trf_14287(C_word c,C_word *av) C_noret;
static void C_ccall trf_14287(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14287(t0,t1,t2);}

C_noret_decl(trf_14297)
static void C_ccall trf_14297(C_word c,C_word *av) C_noret;
static void C_ccall trf_14297(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14297(t0,t1,t2);}

C_noret_decl(trf_14442)
static void C_ccall trf_14442(C_word c,C_word *av) C_noret;
static void C_ccall trf_14442(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14442(t0,t1,t2);}

C_noret_decl(trf_14469)
static void C_ccall trf_14469(C_word c,C_word *av) C_noret;
static void C_ccall trf_14469(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14469(t0,t1,t2);}

C_noret_decl(trf_14618)
static void C_ccall trf_14618(C_word c,C_word *av) C_noret;
static void C_ccall trf_14618(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14618(t0,t1,t2);}

C_noret_decl(trf_14682)
static void C_ccall trf_14682(C_word c,C_word *av) C_noret;
static void C_ccall trf_14682(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_14682(t0,t1,t2);}

C_noret_decl(trf_5811)
static void C_ccall trf_5811(C_word c,C_word *av) C_noret;
static void C_ccall trf_5811(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5811(t0,t1,t2);}

C_noret_decl(trf_5864)
static void C_ccall trf_5864(C_word c,C_word *av) C_noret;
static void C_ccall trf_5864(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5864(t0,t1,t2);}

C_noret_decl(trf_5969)
static void C_ccall trf_5969(C_word c,C_word *av) C_noret;
static void C_ccall trf_5969(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_5969(t0,t1,t2);}

C_noret_decl(trf_6046)
static void C_ccall trf_6046(C_word c,C_word *av) C_noret;
static void C_ccall trf_6046(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6046(t0,t1,t2,t3);}

C_noret_decl(trf_6094)
static void C_ccall trf_6094(C_word c,C_word *av) C_noret;
static void C_ccall trf_6094(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_6094(t0,t1,t2,t3);}

C_noret_decl(trf_6143)
static void C_ccall trf_6143(C_word c,C_word *av) C_noret;
static void C_ccall trf_6143(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6143(t0,t1,t2);}

C_noret_decl(trf_6308)
static void C_ccall trf_6308(C_word c,C_word *av) C_noret;
static void C_ccall trf_6308(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6308(t0,t1,t2);}

C_noret_decl(trf_6342)
static void C_ccall trf_6342(C_word c,C_word *av) C_noret;
static void C_ccall trf_6342(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_6342(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_6397)
static void C_ccall trf_6397(C_word c,C_word *av) C_noret;
static void C_ccall trf_6397(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6397(t0,t1,t2);}

C_noret_decl(trf_6414)
static void C_ccall trf_6414(C_word c,C_word *av) C_noret;
static void C_ccall trf_6414(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6414(t0,t1);}

C_noret_decl(trf_6541)
static void C_ccall trf_6541(C_word c,C_word *av) C_noret;
static void C_ccall trf_6541(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_6541(t0,t1,t2,t3,t4);}

C_noret_decl(trf_6585)
static void C_ccall trf_6585(C_word c,C_word *av) C_noret;
static void C_ccall trf_6585(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6585(t0,t1,t2);}

C_noret_decl(trf_6609)
static void C_ccall trf_6609(C_word c,C_word *av) C_noret;
static void C_ccall trf_6609(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6609(t0,t1);}

C_noret_decl(trf_6615)
static void C_ccall trf_6615(C_word c,C_word *av) C_noret;
static void C_ccall trf_6615(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6615(t0,t1);}

C_noret_decl(trf_6666)
static void C_ccall trf_6666(C_word c,C_word *av) C_noret;
static void C_ccall trf_6666(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6666(t0,t1,t2);}

C_noret_decl(trf_6735)
static void C_ccall trf_6735(C_word c,C_word *av) C_noret;
static void C_ccall trf_6735(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6735(t0,t1,t2);}

C_noret_decl(trf_6773)
static void C_ccall trf_6773(C_word c,C_word *av) C_noret;
static void C_ccall trf_6773(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_6773(t0,t1);}

C_noret_decl(trf_6777)
static void C_ccall trf_6777(C_word c,C_word *av) C_noret;
static void C_ccall trf_6777(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6777(t0,t1,t2);}

C_noret_decl(trf_6877)
static void C_ccall trf_6877(C_word c,C_word *av) C_noret;
static void C_ccall trf_6877(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6877(t0,t1,t2);}

C_noret_decl(trf_6975)
static void C_ccall trf_6975(C_word c,C_word *av) C_noret;
static void C_ccall trf_6975(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_6975(t0,t1,t2);}

C_noret_decl(trf_7003)
static void C_ccall trf_7003(C_word c,C_word *av) C_noret;
static void C_ccall trf_7003(C_word c,C_word *av){
C_word t0=av[6];
C_word t1=av[5];
C_word t2=av[4];
C_word t3=av[3];
C_word t4=av[2];
C_word t5=av[1];
C_word t6=av[0];
f_7003(t0,t1,t2,t3,t4,t5,t6);}

C_noret_decl(trf_7021)
static void C_ccall trf_7021(C_word c,C_word *av) C_noret;
static void C_ccall trf_7021(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7021(t0,t1);}

C_noret_decl(trf_7033)
static void C_ccall trf_7033(C_word c,C_word *av) C_noret;
static void C_ccall trf_7033(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7033(t0,t1);}

C_noret_decl(trf_7161)
static void C_ccall trf_7161(C_word c,C_word *av) C_noret;
static void C_ccall trf_7161(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7161(t0,t1,t2);}

C_noret_decl(trf_7226)
static void C_ccall trf_7226(C_word c,C_word *av) C_noret;
static void C_ccall trf_7226(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7226(t0,t1,t2);}

C_noret_decl(trf_7306)
static void C_ccall trf_7306(C_word c,C_word *av) C_noret;
static void C_ccall trf_7306(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7306(t0,t1);}

C_noret_decl(trf_7319)
static void C_ccall trf_7319(C_word c,C_word *av) C_noret;
static void C_ccall trf_7319(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7319(t0,t1);}

C_noret_decl(trf_7356)
static void C_ccall trf_7356(C_word c,C_word *av) C_noret;
static void C_ccall trf_7356(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7356(t0,t1);}

C_noret_decl(trf_7395)
static void C_ccall trf_7395(C_word c,C_word *av) C_noret;
static void C_ccall trf_7395(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7395(t0,t1);}

C_noret_decl(trf_7482)
static void C_ccall trf_7482(C_word c,C_word *av) C_noret;
static void C_ccall trf_7482(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7482(t0,t1);}

C_noret_decl(trf_7657)
static void C_ccall trf_7657(C_word c,C_word *av) C_noret;
static void C_ccall trf_7657(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7657(t0,t1,t2,t3);}

C_noret_decl(trf_7723)
static void C_ccall trf_7723(C_word c,C_word *av) C_noret;
static void C_ccall trf_7723(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7723(t0,t1,t2);}

C_noret_decl(trf_7776)
static void C_ccall trf_7776(C_word c,C_word *av) C_noret;
static void C_ccall trf_7776(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7776(t0,t1,t2,t3);}

C_noret_decl(trf_7783)
static void C_ccall trf_7783(C_word c,C_word *av) C_noret;
static void C_ccall trf_7783(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7783(t0,t1);}

C_noret_decl(trf_7792)
static void C_ccall trf_7792(C_word c,C_word *av) C_noret;
static void C_ccall trf_7792(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7792(t0,t1);}

C_noret_decl(trf_7825)
static void C_ccall trf_7825(C_word c,C_word *av) C_noret;
static void C_ccall trf_7825(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7825(t0,t1,t2);}

C_noret_decl(trf_7833)
static void C_ccall trf_7833(C_word c,C_word *av) C_noret;
static void C_ccall trf_7833(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7833(t0,t1,t2);}

C_noret_decl(trf_7840)
static void C_ccall trf_7840(C_word c,C_word *av) C_noret;
static void C_ccall trf_7840(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7840(t0,t1);}

C_noret_decl(trf_7849)
static void C_ccall trf_7849(C_word c,C_word *av) C_noret;
static void C_ccall trf_7849(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_7849(t0,t1);}

C_noret_decl(trf_7926)
static void C_ccall trf_7926(C_word c,C_word *av) C_noret;
static void C_ccall trf_7926(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_7926(t0,t1,t2,t3);}

C_noret_decl(trf_7945)
static void C_ccall trf_7945(C_word c,C_word *av) C_noret;
static void C_ccall trf_7945(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_7945(t0,t1,t2);}

C_noret_decl(trf_8213)
static void C_ccall trf_8213(C_word c,C_word *av) C_noret;
static void C_ccall trf_8213(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_8213(t0,t1,t2,t3,t4);}

C_noret_decl(trf_8220)
static void C_ccall trf_8220(C_word c,C_word *av) C_noret;
static void C_ccall trf_8220(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8220(t0,t1);}

C_noret_decl(trf_8275)
static void C_ccall trf_8275(C_word c,C_word *av) C_noret;
static void C_ccall trf_8275(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8275(t0,t1,t2);}

C_noret_decl(trf_8309)
static void C_ccall trf_8309(C_word c,C_word *av) C_noret;
static void C_ccall trf_8309(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8309(t0,t1,t2,t3);}

C_noret_decl(trf_8361)
static void C_ccall trf_8361(C_word c,C_word *av) C_noret;
static void C_ccall trf_8361(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_8361(t0,t1,t2,t3,t4);}

C_noret_decl(trf_8388)
static void C_ccall trf_8388(C_word c,C_word *av) C_noret;
static void C_ccall trf_8388(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8388(t0,t1,t2);}

C_noret_decl(trf_8513)
static void C_ccall trf_8513(C_word c,C_word *av) C_noret;
static void C_ccall trf_8513(C_word c,C_word *av){
C_word t0=av[5];
C_word t1=av[4];
C_word t2=av[3];
C_word t3=av[2];
C_word t4=av[1];
C_word t5=av[0];
f_8513(t0,t1,t2,t3,t4,t5);}

C_noret_decl(trf_8536)
static void C_ccall trf_8536(C_word c,C_word *av) C_noret;
static void C_ccall trf_8536(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_8536(t0,t1);}

C_noret_decl(trf_8559)
static void C_ccall trf_8559(C_word c,C_word *av) C_noret;
static void C_ccall trf_8559(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8559(t0,t1,t2);}

C_noret_decl(trf_8828)
static void C_ccall trf_8828(C_word c,C_word *av) C_noret;
static void C_ccall trf_8828(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8828(t0,t1,t2,t3);}

C_noret_decl(trf_8910)
static void C_ccall trf_8910(C_word c,C_word *av) C_noret;
static void C_ccall trf_8910(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_8910(t0,t1,t2,t3);}

C_noret_decl(trf_8989)
static void C_ccall trf_8989(C_word c,C_word *av) C_noret;
static void C_ccall trf_8989(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_8989(t0,t1,t2);}

C_noret_decl(trf_9042)
static void C_ccall trf_9042(C_word c,C_word *av) C_noret;
static void C_ccall trf_9042(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9042(t0,t1,t2);}

C_noret_decl(trf_9058)
static void C_ccall trf_9058(C_word c,C_word *av) C_noret;
static void C_ccall trf_9058(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9058(t0,t1,t2);}

C_noret_decl(trf_9155)
static void C_ccall trf_9155(C_word c,C_word *av) C_noret;
static void C_ccall trf_9155(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9155(t0,t1,t2);}

C_noret_decl(trf_9200)
static void C_ccall trf_9200(C_word c,C_word *av) C_noret;
static void C_ccall trf_9200(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9200(t0,t1,t2);}

C_noret_decl(trf_9206)
static void C_ccall trf_9206(C_word c,C_word *av) C_noret;
static void C_ccall trf_9206(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9206(t0,t1,t2,t3);}

C_noret_decl(trf_9226)
static void C_ccall trf_9226(C_word c,C_word *av) C_noret;
static void C_ccall trf_9226(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9226(t0,t1);}

C_noret_decl(trf_9350)
static void C_ccall trf_9350(C_word c,C_word *av) C_noret;
static void C_ccall trf_9350(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9350(t0,t1,t2);}

C_noret_decl(trf_9379)
static void C_ccall trf_9379(C_word c,C_word *av) C_noret;
static void C_ccall trf_9379(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9379(t0,t1,t2);}

C_noret_decl(trf_9440)
static void C_ccall trf_9440(C_word c,C_word *av) C_noret;
static void C_ccall trf_9440(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9440(t0,t1,t2);}

C_noret_decl(trf_9477)
static void C_ccall trf_9477(C_word c,C_word *av) C_noret;
static void C_ccall trf_9477(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9477(t0,t1,t2);}

C_noret_decl(trf_9483)
static void C_ccall trf_9483(C_word c,C_word *av) C_noret;
static void C_ccall trf_9483(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9483(t0,t1,t2);}

C_noret_decl(trf_9502)
static void C_ccall trf_9502(C_word c,C_word *av) C_noret;
static void C_ccall trf_9502(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9502(t0,t1,t2);}

C_noret_decl(trf_9571)
static void C_ccall trf_9571(C_word c,C_word *av) C_noret;
static void C_ccall trf_9571(C_word c,C_word *av){
C_word t0=av[4];
C_word t1=av[3];
C_word t2=av[2];
C_word t3=av[1];
C_word t4=av[0];
f_9571(t0,t1,t2,t3,t4);}

C_noret_decl(trf_9583)
static void C_ccall trf_9583(C_word c,C_word *av) C_noret;
static void C_ccall trf_9583(C_word c,C_word *av){
C_word t0=av[2];
C_word t1=av[1];
C_word t2=av[0];
f_9583(t0,t1,t2);}

C_noret_decl(trf_9688)
static void C_ccall trf_9688(C_word c,C_word *av) C_noret;
static void C_ccall trf_9688(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9688(t0,t1);}

C_noret_decl(trf_9693)
static void C_ccall trf_9693(C_word c,C_word *av) C_noret;
static void C_ccall trf_9693(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9693(t0,t1,t2,t3);}

C_noret_decl(trf_9712)
static void C_ccall trf_9712(C_word c,C_word *av) C_noret;
static void C_ccall trf_9712(C_word c,C_word *av){
C_word t0=av[1];
C_word t1=av[0];
f_9712(t0,t1);}

C_noret_decl(trf_9717)
static void C_ccall trf_9717(C_word c,C_word *av) C_noret;
static void C_ccall trf_9717(C_word c,C_word *av){
C_word t0=av[3];
C_word t1=av[2];
C_word t2=av[1];
C_word t3=av[0];
f_9717(t0,t1,t2,t3);}

/* chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_10000(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,5)))){
C_save_and_reclaim_args((void *)trf_10000,3,t1,t2,t3);}
a=C_alloc(8);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10006,a[2]=t3,a[3]=t2,a[4]=((C_word)li113),tmp=(C_word)a,a+=5,tmp);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_record2(&a,2,lf[26],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10006(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_10006,c,av);}
a=C_alloc(15);
t5=C_SCHEME_END_OF_LIST;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10009,a[2]=((C_word)li105),tmp=(C_word)a,a+=3,tmp);
t8=C_i_listp(t3);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_10056,a[2]=t7,a[3]=t6,a[4]=t3,a[5]=t4,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=t1,a[9]=t2,tmp=(C_word)a,a+=10,tmp);
if(C_truep(t8)){
t10=t9;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t8;
f_10056(2,av2);}}
else{
/* expand.scm:926: ##sys#error */
t10=*((C_word*)lf[27]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[199];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(4,av2);}}}

/* inherit-pair-line-numbers in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_10009(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_10009,3,t1,t2,t3);}
a=C_alloc(10);
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10016,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(t4)){
if(C_truep(C_i_symbolp(t4))){
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10025,a[2]=t3,a[3]=t1,a[4]=t5,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:920: get-line-number */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[157]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[157]+1);
av2[1]=t6;
av2[2]=t2;
tp(3,av2);}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k10014 in inherit-pair-line-numbers in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10016(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10016,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k10023 in inherit-pair-line-numbers in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_10025,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10031,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:921: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[152]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[152]+1);
av2[1]=t2;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=((C_word*)t0)[5];
tp(4,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k10029 in k10023 in inherit-pair-line-numbers in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_10031,c,av);}
a=C_alloc(6);
t2=(C_truep(t1)?t1:C_SCHEME_END_OF_LIST);
if(C_truep(t2)){
if(C_truep(C_i_assq(((C_word*)t0)[2],t2))){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_a_i_cons(&a,2,C_a_i_weak_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[4]),t2);
/* expand.scm:923: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[148]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[148]+1);
av2[1]=((C_word*)t0)[5];
av2[2]=*((C_word*)lf[121]+1);
av2[3]=((C_word*)t0)[6];
av2[4]=t3;
tp(5,av2);}}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10056(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(42,c,4)))){
C_save_and_reclaim((void *)f_10056,c,av);}
a=C_alloc(42);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10058,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word)li106),tmp=(C_word)a,a+=7,tmp));
t11=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10144,a[2]=t5,a[3]=((C_word*)t0)[5],a[4]=((C_word)li110),tmp=(C_word)a,a+=5,tmp));
t12=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10363,a[2]=((C_word)li111),tmp=(C_word)a,a+=3,tmp));
t13=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10388,a[2]=((C_word*)t0)[2],a[3]=t9,a[4]=((C_word*)t0)[4],a[5]=t7,a[6]=((C_word*)t0)[3],a[7]=t3,a[8]=((C_word)li112),tmp=(C_word)a,a+=9,tmp));
if(C_truep(((C_word*)t0)[6])){
/* expand.scm:1017: handler */
t14=((C_word*)t0)[7];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t14;
av2[1]=((C_word*)t0)[8];
av2[2]=((C_word*)t0)[9];
av2[3]=((C_word*)t3)[1];
av2[4]=((C_word*)t5)[1];
((C_proc)C_fast_retrieve_proc(t14))(5,av2);}}
else{
t14=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10520,a[2]=t9,a[3]=((C_word*)t0)[8],tmp=(C_word)a,a+=4,tmp);
t15=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10524,a[2]=((C_word*)t0)[7],a[3]=t14,a[4]=t3,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1023: rename */
t16=((C_word*)t3)[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t16;
av2[1]=t15;
av2[2]=((C_word*)t0)[9];
f_10058(3,av2);}}}

/* rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10058(C_word c,C_word *av){
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
loop:
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
av[0]=t0;
av[1]=t1;
av[2]=t2;
C_save_and_reclaim((void *)f_10058,c,av);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10076,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:929: rename */
t7=t3;
t8=C_u_i_car(t2);
t1=t7;
t2=t8;
c=3;
goto loop;}
else{
if(C_truep(C_i_vectorp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10097,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10101,a[2]=((C_word*)t0)[3],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:931: scheme#vector->list */
t5=*((C_word*)lf[198]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=C_i_symbolp(t2);
if(C_truep(C_i_not(t3))){
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_assq(t2,((C_word*)((C_word*)t0)[4])[1]);
if(C_truep(t4)){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_cdr(t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10127,a[2]=t2,a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:938: macro-alias */
f_5811(t5,t2,((C_word*)t0)[5]);}}}}}

/* k10074 in rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10076(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_10076,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10080,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:929: rename */
t3=((C_word*)((C_word*)t0)[5])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_cdr(((C_word*)t0)[4]);
f_10058(3,av2);}}

/* k10078 in k10074 in rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_10080,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* expand.scm:929: inherit-pair-line-numbers */
f_10009(((C_word*)t0)[4],((C_word*)t0)[5],t2);}

/* k10095 in rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10097(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10097,c,av);}
/* expand.scm:931: scheme#list->vector */
t2=*((C_word*)lf[197]+1);{
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

/* k10099 in rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10101(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10101,c,av);}
/* expand.scm:931: rename */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
f_10058(3,av2);}}

/* k10125 in rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10127(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_10127,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[3])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10144(C_word c,C_word *av){
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
loop:
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
av[0]=t0;
av[1]=t1;
av[2]=t2;
av[3]=t3;
C_save_and_reclaim((void *)f_10144,c,av);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
if(C_truep(C_i_pairp(t3))){
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10166,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:946: compare */
t11=t4;
t12=C_u_i_car(t2);
t13=C_u_i_car(t3);
t1=t11;
t2=t12;
t3=t13;
c=4;
goto loop;}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
if(C_truep(C_i_vectorp(t2))){
if(C_truep(C_i_vectorp(t3))){
t4=C_block_size(t2);
t5=C_block_size(t3);
t6=C_eqp(t4,t5);
if(C_truep(t6)){
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10203,a[2]=t4,a[3]=t8,a[4]=((C_word*)t0)[2],a[5]=t2,a[6]=t3,a[7]=((C_word)li107),tmp=(C_word)a,a+=8,tmp));
t10=((C_word*)t8)[1];
f_10203(t10,t1,C_fix(0),C_SCHEME_TRUE);}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t4=C_i_symbolp(t2);
t5=(C_truep(t4)?C_i_symbolp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_i_getprop(t2,lf[6],C_SCHEME_FALSE);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10255,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t6)){
t8=t7;
f_10255(t8,t6);}
else{
t8=(
/* expand.scm:977: lookup */
  f_5794(t2,((C_word*)t0)[3])
);
t9=t7;
f_10255(t9,(C_truep(t8)?t8:t2));}}
else{
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_eqp(t2,t3);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}}}

/* k10164 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10166(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10166,c,av);}
if(C_truep(t1)){
/* expand.scm:947: compare */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=C_u_i_cdr(((C_word*)t0)[4]);
av2[3]=C_u_i_cdr(((C_word*)t0)[5]);
f_10144(4,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* doloop2181 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_10203(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_10203,4,t0,t1,t2,t3);}
a=C_alloc(5);
t4=C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]);
t5=(C_truep(t4)?t4:C_i_not(t3));
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_fixnum_plus(t2,C_fix(1));
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10224,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:953: compare */
t8=((C_word*)((C_word*)t0)[4])[1];{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=C_i_vector_ref(((C_word*)t0)[5],t2);
av2[3]=C_i_vector_ref(((C_word*)t0)[6],t2);
f_10144(4,av2);}}}

/* k10222 in doloop2181 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10224,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_10203(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k10253 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_10255(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,2)))){
C_save_and_reclaim_args((void *)trf_10255,2,t0,t1);}
a=C_alloc(4);
t2=C_i_getprop(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10263,a[2]=t1,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t2)){
t4=t3;
f_10263(t4,t2);}
else{
t4=(
/* expand.scm:977: lookup */
  f_5794(((C_word*)t0)[2],((C_word*)t0)[4])
);
t5=t3;
f_10263(t5,(C_truep(t4)?t4:((C_word*)t0)[2]));}}

/* k10261 in k10253 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_10263(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_10263,2,t0,t1);}
a=C_alloc(5);
if(C_truep(C_i_symbolp(((C_word*)t0)[2]))){
if(C_truep(C_i_symbolp(t1))){
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[2],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10300,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:965: ##sys#macro-environment */
t3=*((C_word*)lf[17]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
if(C_truep(C_i_symbolp(t1))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10328,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:969: ##sys#macro-environment */
t3=*((C_word*)lf[17]+1);{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_eqp(((C_word*)t0)[2],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}

/* g2222 in k10298 in k10261 in k10253 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_10285(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_eqp(C_i_cdr(t1),((C_word*)t0)[2]));}

/* k10298 in k10261 in k10253 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10300(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10300,c,av);}
a=C_alloc(4);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10285,a[2]=((C_word*)t0)[3],a[3]=((C_word)li108),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:964: g2222 */
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
/* expand.scm:964: g2222 */
  f_10285(t3,t2)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* g2231 in k10326 in k10261 in k10253 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_10313(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_eqp(((C_word*)t0)[2],C_i_cdr(t1)));}

/* k10326 in k10261 in k10253 in compare in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_10328,c,av);}
a=C_alloc(4);
t2=C_i_assq(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10313,a[2]=((C_word*)t0)[3],a[3]=((C_word)li109),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:969: g2231 */
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
/* expand.scm:969: g2231 */
  f_10313(t3,t2)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* assq-reverse in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_10363(C_word t1,C_word t2){
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
t3=C_i_cdar(t2);
t4=C_eqp(t3,t1);
if(C_truep(t4)){
return(C_u_i_car(t2));}
else{
t6=t1;
t7=C_u_i_cdr(t2);
t1=t6;
t2=t7;
goto loop;}}}

/* mirror-rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_10388(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_10388,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10406,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:992: mirror-rename */
t8=t3;
t9=C_u_i_car(t2);
t1=t8;
t2=t9;
goto loop;}
else{
if(C_truep(C_i_vectorp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10427,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10431,a[2]=((C_word*)t0)[3],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:994: scheme#vector->list */
t5=*((C_word*)lf[198]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t3=C_i_symbolp(t2);
if(C_truep(C_i_not(t3))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(
/* expand.scm:997: lookup */
  f_5794(t2,((C_word*)t0)[4])
);
t5=(
/* expand.scm:998: assq-reverse */
  f_10363(t2,((C_word*)((C_word*)t0)[6])[1])
);
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_i_car(t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(C_i_not(t4))){
/* expand.scm:1002: rename */
t6=((C_word*)((C_word*)t0)[7])[1];{
C_word av2[3];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
f_10058(3,av2);}}
else{
if(C_truep(C_i_pairp(t4))){
/* expand.scm:1004: rename */
t6=((C_word*)((C_word*)t0)[7])[1];{
C_word av2[3];
av2[0]=t6;
av2[1]=t1;
av2[2]=t2;
f_10058(3,av2);}}
else{
t6=C_i_getprop(t2,lf[8],C_SCHEME_FALSE);
if(C_truep(t6)){
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
/* expand.scm:1011: rename */
t7=((C_word*)((C_word*)t0)[7])[1];{
C_word av2[3];
av2[0]=t7;
av2[1]=t1;
av2[2]=t2;
f_10058(3,av2);}}}}}}}}}

/* k10404 in mirror-rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_10406,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10410,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:992: mirror-rename */
t3=((C_word*)((C_word*)t0)[5])[1];
f_10388(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k10408 in k10404 in mirror-rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_10410,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
/* expand.scm:991: inherit-pair-line-numbers */
f_10009(((C_word*)t0)[4],((C_word*)t0)[5],t2);}

/* k10425 in mirror-rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10427(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10427,c,av);}
/* expand.scm:994: scheme#list->vector */
t2=*((C_word*)lf[197]+1);{
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

/* k10429 in mirror-rename in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10431(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10431,c,av);}
/* expand.scm:994: mirror-rename */
t2=((C_word*)((C_word*)t0)[2])[1];
f_10388(t2,((C_word*)t0)[3],t1);}

/* k10518 in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10520(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_10520,c,av);}
/* expand.scm:1023: mirror-rename */
t2=((C_word*)((C_word*)t0)[2])[1];
f_10388(t2,((C_word*)t0)[3],t1);}

/* k10522 in k10054 in a10005 in chicken.syntax#make-er/ir-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10524(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10524,c,av);}
/* expand.scm:1023: handler */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)((C_word*)t0)[4])[1];
av2[4]=((C_word*)((C_word*)t0)[5])[1];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* chicken.syntax#er-macro-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10529,c,av);}
/* expand.scm:1025: make-er/ir-transformer */
f_10000(t1,t2,C_SCHEME_TRUE);}

/* chicken.syntax#ir-macro-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10535(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10535,c,av);}
/* expand.scm:1026: make-er/ir-transformer */
f_10000(t1,t2,C_SCHEME_FALSE);}

/* k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10548,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10551,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14718,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14720,a[2]=((C_word)li194),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1055: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10551,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10555,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14607,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14609,a[2]=((C_word)li193),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1063: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10555(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10555,c,av);}
a=C_alloc(9);
t2=C_mutate(&lf[101] /* (set! chicken.syntax#import-definition ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10558,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14572,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14574,a[2]=((C_word)li188),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1085: ##sys#er-transformer */
t6=*((C_word*)lf[202]+1);{
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

/* k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10558(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10558,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10561,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14279,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14281,a[2]=((C_word)li187),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1094: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10561(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10561,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10565,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1146: ##sys#macro-environment */
t3=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10565(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10565,c,av);}
a=C_alloc(9);
t2=C_mutate((C_word*)lf[204]+1 /* (set! ##sys#initial-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10568,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14104,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14106,a[2]=((C_word)li182),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1150: ##sys#er-transformer */
t6=*((C_word*)lf[202]+1);{
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

/* k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10568(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10568,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10571,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14077,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14079,a[2]=((C_word)li181),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1210: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10571(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10571,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10574,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13954,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13956,a[2]=((C_word)li180),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1220: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10574(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10574,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10577,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13944,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13946,a[2]=((C_word)li178),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1239: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10577(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10577,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10580,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13773,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13775,a[2]=((C_word)li177),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1248: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10580(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10580,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10583,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13689,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13691,a[2]=((C_word)li174),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1283: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10583(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_10583,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10586,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13666,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13668,a[2]=((C_word)li173),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1306: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10586,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10590,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1313: ##sys#macro-environment */
t3=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10590(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10590,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[205]+1 /* (set! ##sys#chicken.module-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10594,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1316: ##sys#macro-environment */
t4=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_10594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10594,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10597,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13649,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13651,a[2]=((C_word)li172),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1321: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_10597(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10597,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10600,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13632,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13634,a[2]=((C_word)li171),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1329: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_10600(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10600,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10603,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13615,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13617,a[2]=((C_word)li170),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1337: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in ... */
static void C_ccall f_10603(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10603,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10606,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13598,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13600,a[2]=((C_word)li169),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1345: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in ... */
static void C_ccall f_10606(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10606,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10610,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13471,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13473,a[2]=((C_word)li168),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1354: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in ... */
static void C_ccall f_10610(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10610,c,av);}
a=C_alloc(10);
t2=C_mutate((C_word*)lf[98]+1 /* (set! chicken.syntax#define-definition ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10614,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13424,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13426,a[2]=((C_word)li166),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1382: ##sys#er-transformer */
t6=*((C_word*)lf[202]+1);{
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

/* k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in ... */
static void C_ccall f_10614(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_10614,c,av);}
a=C_alloc(10);
t2=C_mutate((C_word*)lf[99]+1 /* (set! chicken.syntax#define-syntax-definition ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10617,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13372,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13374,a[2]=((C_word)li165),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1396: ##sys#er-transformer */
t6=*((C_word*)lf[202]+1);{
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

/* k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in ... */
static void C_ccall f_10617(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10617,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10620,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13350,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13352,a[2]=((C_word)li164),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1409: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_10620(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10620,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10623,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13328,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13330,a[2]=((C_word)li163),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1418: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_10623(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10623,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10626,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13306,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13308,a[2]=((C_word)li162),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1427: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_10626(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10626,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10629,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13262,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13264,a[2]=((C_word)li161),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1436: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in ... */
static void C_ccall f_10629(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10629,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10632,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13225,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13227,a[2]=((C_word)li160),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1448: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in ... */
static void C_ccall f_10632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10632,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10635,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13173,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13175,a[2]=((C_word)li159),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1462: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in ... */
static void C_ccall f_10635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10635,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10638,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12785,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12787,a[2]=((C_word)li158),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1478: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in ... */
static void C_ccall f_10638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10638,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10641,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12549,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12551,a[2]=((C_word)li156),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1546: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in ... */
static void C_ccall f_10641(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10641,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10644,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12498,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12500,a[2]=((C_word)li152),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1591: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in ... */
static void C_ccall f_10644(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10644,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10647,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12302,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12304,a[2]=((C_word)li150),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1604: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in ... */
static void C_ccall f_10647(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10647,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10650,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12009,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12011,a[2]=((C_word)li147),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1633: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_ccall f_10650(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10650,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10653,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11976,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11978,a[2]=((C_word)li141),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1685: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_10653(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_10653,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10656,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11940,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11942,a[2]=((C_word)li140),tmp=(C_word)a,a+=3,tmp);
/* synrules.scm:46: ##sys#er-transformer */
t5=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_10656(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_10656,c,av);}
a=C_alloc(20);
t2=C_a_i_provide(&a,1,lf[206]);
t3=C_mutate((C_word*)lf[46]+1 /* (set! chicken.internal.syntax-rules#syntax-rules-mismatch ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10658,a[2]=((C_word)li117),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate((C_word*)lf[208]+1 /* (set! chicken.internal.syntax-rules#drop-right ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10664,a[2]=((C_word)li119),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[209]+1 /* (set! chicken.internal.syntax-rules#take-right ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10700,a[2]=((C_word)li121),tmp=(C_word)a,a+=3,tmp));
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11917,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1696: chicken.internal#macro-subset */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[218]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[218]+1);
av2[1]=t6;
av2[2]=((C_word*)t0)[3];
tp(3,av2);}}

/* chicken.internal.syntax-rules#syntax-rules-mismatch in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_10658(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10658,c,av);}
/* synrules.scm:68: ##sys#syntax-error-hook */
t3=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=lf[207];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* chicken.internal.syntax-rules#drop-right in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_10664(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_10664,c,av);}
a=C_alloc(7);
t4=C_i_length(t2);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10674,a[2]=t3,a[3]=t6,a[4]=((C_word)li118),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_10674(t8,t1,t4,t2);}

/* loop in chicken.internal.syntax-rules#drop-right in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_10674(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_10674,4,t0,t1,t2,t3);}
a=C_alloc(4);
if(C_truep(C_fixnum_greaterp(t2,((C_word*)t0)[2]))){
t4=C_i_car(t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10692,a[2]=t1,a[3]=t4,tmp=(C_word)a,a+=4,tmp);
/* synrules.scm:77: loop */
t7=t5;
t8=C_fixnum_difference(t2,C_fix(1));
t9=C_u_i_cdr(t3);
t1=t7;
t2=t8;
t3=t9;
goto loop;}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k10690 in loop in chicken.internal.syntax-rules#drop-right in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_10692(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_10692,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.internal.syntax-rules#take-right in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_10700(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_10700,c,av);}
a=C_alloc(4);
t4=C_i_length(t2);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_10710,a[2]=t3,a[3]=((C_word)li120),tmp=(C_word)a,a+=4,tmp);
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=(
  f_10710(t5,t4,t2)
);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* loop in chicken.internal.syntax-rules#take-right in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static C_word C_fcall f_10710(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;
loop:{}
if(C_truep(C_fixnum_greaterp(t1,((C_word*)t0)[2]))){
t4=C_fixnum_difference(t1,C_fix(1));
t5=C_i_cdr(t2);
t1=t4;
t2=t5;
goto loop;}
else{
return(t2);}}

/* k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_10737(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10737,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[221]);
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,lf[222]);
t5=C_mutate(((C_word *)((C_word*)t0)[5])+1,lf[223]);
t6=C_mutate(((C_word *)((C_word*)t0)[6])+1,lf[224]);
t7=C_mutate(((C_word *)((C_word*)t0)[7])+1,lf[225]);
t8=C_mutate(((C_word *)((C_word*)t0)[8])+1,lf[226]);
t9=C_mutate(((C_word *)((C_word*)t0)[9])+1,lf[227]);
t10=C_mutate(((C_word *)((C_word*)t0)[10])+1,lf[228]);
t11=C_mutate(((C_word *)((C_word*)t0)[11])+1,lf[229]);
t12=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10752,a[2]=((C_word*)t0)[12],a[3]=((C_word*)t0)[13],a[4]=((C_word*)t0)[14],a[5]=((C_word*)t0)[15],a[6]=((C_word*)t0)[16],a[7]=((C_word*)t0)[17],a[8]=((C_word*)t0)[18],a[9]=((C_word*)t0)[19],a[10]=((C_word*)t0)[20],a[11]=((C_word*)t0)[21],a[12]=((C_word*)t0)[22],a[13]=((C_word*)t0)[23],a[14]=((C_word*)t0)[24],a[15]=((C_word*)t0)[25],a[16]=((C_word*)t0)[26],a[17]=((C_word*)t0)[27],a[18]=((C_word*)t0)[28],a[19]=((C_word*)t0)[29],a[20]=((C_word*)t0)[30],a[21]=((C_word*)t0)[31],a[22]=((C_word*)t0)[32],a[23]=((C_word*)t0)[33],a[24]=((C_word*)t0)[34],a[25]=((C_word*)t0)[35],a[26]=((C_word*)t0)[36],a[27]=((C_word*)t0)[37],a[28]=((C_word*)t0)[38],a[29]=((C_word*)t0)[39],a[30]=((C_word*)t0)[4],a[31]=((C_word*)t0)[40],a[32]=((C_word*)t0)[2],a[33]=((C_word*)t0)[41],a[34]=((C_word*)t0)[42],a[35]=((C_word*)t0)[43],a[36]=((C_word*)t0)[44],a[37]=((C_word*)t0)[45],a[38]=((C_word*)t0)[46],a[39]=((C_word*)t0)[3],a[40]=((C_word*)t0)[6],a[41]=((C_word*)t0)[7],a[42]=((C_word*)t0)[47],a[43]=((C_word*)t0)[5],a[44]=((C_word*)t0)[9],a[45]=((C_word*)t0)[10],a[46]=((C_word*)t0)[11],a[47]=((C_word*)t0)[48],a[48]=((C_word*)t0)[49],a[49]=((C_word*)t0)[50],a[50]=((C_word*)t0)[8],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:105: r */
t13=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t13;
av2[1]=t12;
av2[2]=lf[256];
((C_proc)C_fast_retrieve_proc(t13))(3,av2);}}

/* k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_10752(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10752,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10756,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[2],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:106: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[255];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_10756(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10756,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[230]);
t4=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10761,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[13],a[12]=((C_word*)t0)[14],a[13]=((C_word*)t0)[15],a[14]=((C_word*)t0)[16],a[15]=((C_word*)t0)[17],a[16]=((C_word*)t0)[18],a[17]=((C_word*)t0)[19],a[18]=((C_word*)t0)[20],a[19]=((C_word*)t0)[21],a[20]=((C_word*)t0)[22],a[21]=((C_word*)t0)[23],a[22]=((C_word*)t0)[24],a[23]=((C_word*)t0)[25],a[24]=((C_word*)t0)[26],a[25]=((C_word*)t0)[27],a[26]=((C_word*)t0)[28],a[27]=((C_word*)t0)[29],a[28]=((C_word*)t0)[30],a[29]=((C_word*)t0)[2],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[40],a[40]=((C_word*)t0)[41],a[41]=((C_word*)t0)[42],a[42]=((C_word*)t0)[43],a[43]=((C_word*)t0)[44],a[44]=((C_word*)t0)[45],a[45]=((C_word*)t0)[46],a[46]=((C_word*)t0)[47],a[47]=((C_word*)t0)[48],a[48]=((C_word*)t0)[49],a[49]=((C_word*)t0)[3],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:108: r */
t5=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[254];
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_ccall f_10761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10761,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[231]);
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,lf[232]);
t5=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10767,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[12],a[10]=((C_word*)t0)[13],a[11]=((C_word*)t0)[14],a[12]=((C_word*)t0)[15],a[13]=((C_word*)t0)[16],a[14]=((C_word*)t0)[17],a[15]=((C_word*)t0)[18],a[16]=((C_word*)t0)[19],a[17]=((C_word*)t0)[20],a[18]=((C_word*)t0)[21],a[19]=((C_word*)t0)[22],a[20]=((C_word*)t0)[23],a[21]=((C_word*)t0)[24],a[22]=((C_word*)t0)[25],a[23]=((C_word*)t0)[26],a[24]=((C_word*)t0)[27],a[25]=((C_word*)t0)[28],a[26]=((C_word*)t0)[29],a[27]=((C_word*)t0)[30],a[28]=((C_word*)t0)[2],a[29]=((C_word*)t0)[31],a[30]=((C_word*)t0)[32],a[31]=((C_word*)t0)[33],a[32]=((C_word*)t0)[34],a[33]=((C_word*)t0)[35],a[34]=((C_word*)t0)[36],a[35]=((C_word*)t0)[37],a[36]=((C_word*)t0)[38],a[37]=((C_word*)t0)[39],a[38]=((C_word*)t0)[40],a[39]=((C_word*)t0)[3],a[40]=((C_word*)t0)[4],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:111: r */
t6=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[253];
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in ... */
static void C_ccall f_10767(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10767,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10771,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[2],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:112: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[252];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in ... */
static void C_ccall f_10771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10771,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10775,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[40],a[40]=((C_word*)t0)[41],a[41]=((C_word*)t0)[42],a[42]=((C_word*)t0)[43],a[43]=((C_word*)t0)[2],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:113: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[251];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in ... */
static void C_ccall f_10775(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10775,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10779,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[40],a[40]=((C_word*)t0)[41],a[41]=((C_word*)t0)[2],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:114: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[250];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in ... */
static void C_ccall f_10779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10779,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10783,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[2],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:115: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[56];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in ... */
static void C_ccall f_10783(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10783,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10787,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[2],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:116: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[91];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in ... */
static void C_ccall f_10787(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10787,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[233]);
t4=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10792,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[8],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[13],a[12]=((C_word*)t0)[14],a[13]=((C_word*)t0)[15],a[14]=((C_word*)t0)[16],a[15]=((C_word*)t0)[17],a[16]=((C_word*)t0)[18],a[17]=((C_word*)t0)[19],a[18]=((C_word*)t0)[20],a[19]=((C_word*)t0)[21],a[20]=((C_word*)t0)[22],a[21]=((C_word*)t0)[23],a[22]=((C_word*)t0)[24],a[23]=((C_word*)t0)[25],a[24]=((C_word*)t0)[26],a[25]=((C_word*)t0)[27],a[26]=((C_word*)t0)[2],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[3],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:118: r */
t5=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[249];
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in ... */
static void C_ccall f_10792(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10792,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,lf[234]);
t4=C_mutate(((C_word *)((C_word*)t0)[4])+1,lf[235]);
t5=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10799,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[12],a[10]=((C_word*)t0)[13],a[11]=((C_word*)t0)[14],a[12]=((C_word*)t0)[15],a[13]=((C_word*)t0)[16],a[14]=((C_word*)t0)[17],a[15]=((C_word*)t0)[18],a[16]=((C_word*)t0)[19],a[17]=((C_word*)t0)[20],a[18]=((C_word*)t0)[21],a[19]=((C_word*)t0)[22],a[20]=((C_word*)t0)[23],a[21]=((C_word*)t0)[24],a[22]=((C_word*)t0)[25],a[23]=((C_word*)t0)[26],a[24]=((C_word*)t0)[27],a[25]=((C_word*)t0)[28],a[26]=((C_word*)t0)[29],a[27]=((C_word*)t0)[30],a[28]=((C_word*)t0)[31],a[29]=((C_word*)t0)[32],a[30]=((C_word*)t0)[33],a[31]=((C_word*)t0)[34],a[32]=((C_word*)t0)[35],a[33]=((C_word*)t0)[36],a[34]=((C_word*)t0)[37],a[35]=((C_word*)t0)[38],a[36]=((C_word*)t0)[39],a[37]=((C_word*)t0)[40],a[38]=((C_word*)t0)[41],a[39]=((C_word*)t0)[42],a[40]=((C_word*)t0)[43],a[41]=((C_word*)t0)[44],a[42]=((C_word*)t0)[2],a[43]=((C_word*)t0)[45],a[44]=((C_word*)t0)[3],a[45]=((C_word*)t0)[46],a[46]=((C_word*)t0)[4],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:122: r */
t6=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[248];
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in ... */
static void C_ccall f_10799(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10799,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,lf[236]);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10804,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[2],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:124: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[239];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in ... */
static void C_ccall f_10804(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10804,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10808,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[40],a[40]=((C_word*)t0)[41],a[41]=((C_word*)t0)[42],a[42]=((C_word*)t0)[43],a[43]=((C_word*)t0)[44],a[44]=((C_word*)t0)[45],a[45]=((C_word*)t0)[46],a[46]=((C_word*)t0)[47],a[47]=((C_word*)t0)[48],a[48]=((C_word*)t0)[49],a[49]=((C_word*)t0)[50],a[50]=((C_word*)t0)[2],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:125: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[247];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in ... */
static void C_ccall f_10808(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10808,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10812,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[2],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:126: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[246];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in ... */
static void C_ccall f_10812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(56,c,2)))){
C_save_and_reclaim((void *)f_10812,c,av);}
a=C_alloc(56);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10816,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[2],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],a[55]=((C_word*)t0)[55],tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:127: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[245];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in ... */
static void C_ccall f_10816(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(55,c,2)))){
C_save_and_reclaim((void *)f_10816,c,av);}
a=C_alloc(55);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|54,a[1]=(C_word)f_10821,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[2],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],tmp=(C_word)a,a+=55,tmp);
/* synrules.scm:129: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[55];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in k10648 in ... */
static void C_ccall f_10821(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(55,c,2)))){
C_save_and_reclaim((void *)f_10821,c,av);}
a=C_alloc(55);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|54,a[1]=(C_word)f_10825,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],a[17]=((C_word*)t0)[17],a[18]=((C_word*)t0)[18],a[19]=((C_word*)t0)[19],a[20]=((C_word*)t0)[20],a[21]=((C_word*)t0)[21],a[22]=((C_word*)t0)[22],a[23]=((C_word*)t0)[23],a[24]=((C_word*)t0)[24],a[25]=((C_word*)t0)[25],a[26]=((C_word*)t0)[26],a[27]=((C_word*)t0)[27],a[28]=((C_word*)t0)[28],a[29]=((C_word*)t0)[29],a[30]=((C_word*)t0)[30],a[31]=((C_word*)t0)[31],a[32]=((C_word*)t0)[32],a[33]=((C_word*)t0)[33],a[34]=((C_word*)t0)[34],a[35]=((C_word*)t0)[35],a[36]=((C_word*)t0)[36],a[37]=((C_word*)t0)[37],a[38]=((C_word*)t0)[38],a[39]=((C_word*)t0)[39],a[40]=((C_word*)t0)[40],a[41]=((C_word*)t0)[41],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],tmp=(C_word)a,a+=55,tmp);
/* synrules.scm:130: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[209];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in k10651 in ... */
static void C_ccall f_10825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(55,c,2)))){
C_save_and_reclaim((void *)f_10825,c,av);}
a=C_alloc(55);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|54,a[1]=(C_word)f_10829,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[40],a[40]=((C_word*)t0)[41],a[41]=((C_word*)t0)[42],a[42]=((C_word*)t0)[2],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],a[54]=((C_word*)t0)[54],tmp=(C_word)a,a+=55,tmp);
/* synrules.scm:131: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[208];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in a11941 in ... */
static void C_ccall f_10829(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(54,c,2)))){
C_save_and_reclaim((void *)f_10829,c,av);}
a=C_alloc(54);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|53,a[1]=(C_word)f_10833,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[13],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],a[15]=((C_word*)t0)[16],a[16]=((C_word*)t0)[17],a[17]=((C_word*)t0)[18],a[18]=((C_word*)t0)[19],a[19]=((C_word*)t0)[20],a[20]=((C_word*)t0)[21],a[21]=((C_word*)t0)[22],a[22]=((C_word*)t0)[23],a[23]=((C_word*)t0)[24],a[24]=((C_word*)t0)[25],a[25]=((C_word*)t0)[26],a[26]=((C_word*)t0)[27],a[27]=((C_word*)t0)[28],a[28]=((C_word*)t0)[29],a[29]=((C_word*)t0)[30],a[30]=((C_word*)t0)[31],a[31]=((C_word*)t0)[32],a[32]=((C_word*)t0)[33],a[33]=((C_word*)t0)[34],a[34]=((C_word*)t0)[35],a[35]=((C_word*)t0)[36],a[36]=((C_word*)t0)[37],a[37]=((C_word*)t0)[38],a[38]=((C_word*)t0)[39],a[39]=((C_word*)t0)[40],a[40]=((C_word*)t0)[41],a[41]=((C_word*)t0)[2],a[42]=((C_word*)t0)[42],a[43]=((C_word*)t0)[43],a[44]=((C_word*)t0)[44],a[45]=((C_word*)t0)[45],a[46]=((C_word*)t0)[46],a[47]=((C_word*)t0)[47],a[48]=((C_word*)t0)[48],a[49]=((C_word*)t0)[49],a[50]=((C_word*)t0)[50],a[51]=((C_word*)t0)[51],a[52]=((C_word*)t0)[52],a[53]=((C_word*)t0)[53],tmp=(C_word)a,a+=54,tmp);
/* synrules.scm:133: r */
t4=((C_word*)t0)[54];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[46];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in k11944 in ... */
static void C_ccall f_10833(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(122,c,6)))){
C_save_and_reclaim((void *)f_10833,c,av);}
a=C_alloc(122);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10835,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word)li122),tmp=(C_word)a,a+=5,tmp));
t4=C_mutate(((C_word *)((C_word*)t0)[6])+1,(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_10841,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],a[7]=((C_word*)t0)[12],a[8]=((C_word*)t0)[13],a[9]=((C_word*)t0)[14],a[10]=((C_word*)t0)[15],a[11]=((C_word*)t0)[2],a[12]=((C_word*)t0)[16],a[13]=((C_word)li124),tmp=(C_word)a,a+=14,tmp));
t5=C_mutate(((C_word *)((C_word*)t0)[15])+1,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_10935,a[2]=((C_word*)t0)[17],a[3]=((C_word*)t0)[18],a[4]=((C_word*)t0)[19],a[5]=((C_word*)t0)[20],a[6]=((C_word*)t0)[21],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[22],a[9]=((C_word)li126),tmp=(C_word)a,a+=10,tmp));
t6=C_mutate(((C_word *)((C_word*)t0)[22])+1,(*a=C_CLOSURE_TYPE|18,a[1]=(C_word)f_11001,a[2]=((C_word*)t0)[23],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[24],a[6]=((C_word*)t0)[25],a[7]=((C_word*)t0)[26],a[8]=((C_word*)t0)[17],a[9]=((C_word*)t0)[13],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[22],a[12]=((C_word*)t0)[27],a[13]=((C_word*)t0)[28],a[14]=((C_word*)t0)[29],a[15]=((C_word*)t0)[30],a[16]=((C_word*)t0)[31],a[17]=((C_word*)t0)[32],a[18]=((C_word)li127),tmp=(C_word)a,a+=19,tmp));
t7=C_mutate(((C_word *)((C_word*)t0)[24])+1,(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_11182,a[2]=((C_word*)t0)[33],a[3]=((C_word*)t0)[34],a[4]=((C_word*)t0)[35],a[5]=((C_word*)t0)[36],a[6]=((C_word*)t0)[37],a[7]=((C_word*)t0)[38],a[8]=((C_word*)t0)[17],a[9]=((C_word*)t0)[16],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[13],a[12]=((C_word*)t0)[39],a[13]=((C_word*)t0)[10],a[14]=((C_word*)t0)[40],a[15]=((C_word*)t0)[22],a[16]=((C_word*)t0)[27],a[17]=((C_word)li128),tmp=(C_word)a,a+=18,tmp));
t8=C_mutate(((C_word *)((C_word*)t0)[21])+1,(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_11309,a[2]=((C_word*)t0)[23],a[3]=((C_word*)t0)[41],a[4]=((C_word*)t0)[42],a[5]=((C_word*)t0)[21],a[6]=((C_word*)t0)[25],a[7]=((C_word*)t0)[14],a[8]=((C_word*)t0)[43],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[27],a[11]=((C_word*)t0)[29],a[12]=((C_word*)t0)[32],a[13]=((C_word)li130),tmp=(C_word)a,a+=14,tmp));
t9=C_mutate(((C_word *)((C_word*)t0)[19])+1,(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_11449,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[19],a[4]=((C_word*)t0)[44],a[5]=((C_word*)t0)[14],a[6]=((C_word*)t0)[45],a[7]=((C_word*)t0)[46],a[8]=((C_word*)t0)[47],a[9]=((C_word*)t0)[48],a[10]=((C_word*)t0)[49],a[11]=((C_word*)t0)[50],a[12]=((C_word*)t0)[51],a[13]=((C_word)li132),tmp=(C_word)a,a+=14,tmp));
t10=C_mutate(((C_word *)((C_word*)t0)[20])+1,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11641,a[2]=((C_word*)t0)[23],a[3]=((C_word*)t0)[20],a[4]=((C_word*)t0)[32],a[5]=((C_word)li133),tmp=(C_word)a,a+=6,tmp));
t11=C_mutate(((C_word *)((C_word*)t0)[46])+1,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11718,a[2]=((C_word*)t0)[46],a[3]=((C_word*)t0)[51],a[4]=((C_word)li134),tmp=(C_word)a,a+=5,tmp));
t12=C_mutate(((C_word *)((C_word*)t0)[32])+1,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11807,a[2]=((C_word*)t0)[51],a[3]=((C_word)li135),tmp=(C_word)a,a+=4,tmp));
t13=C_mutate(((C_word *)((C_word*)t0)[51])+1,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11835,a[2]=((C_word*)t0)[3],a[3]=((C_word)li136),tmp=(C_word)a,a+=4,tmp));
t14=C_mutate(((C_word *)((C_word*)t0)[47])+1,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11859,a[2]=((C_word*)t0)[47],a[3]=((C_word*)t0)[51],a[4]=((C_word)li137),tmp=(C_word)a,a+=5,tmp));
t15=C_mutate(((C_word *)((C_word*)t0)[44])+1,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11879,a[2]=((C_word*)t0)[3],a[3]=((C_word)li139),tmp=(C_word)a,a+=4,tmp));
/* synrules.scm:345: make-transformer */
t16=((C_word*)((C_word*)t0)[6])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t16;
av2[1]=((C_word*)t0)[52];
av2[2]=((C_word*)t0)[53];
((C_proc)(void*)(*((C_word*)t16+1)))(3,av2);}}

/* f_10835 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_10835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_10835,c,av);}
/* synrules.scm:136: c */
t3=((C_word*)t0)[2];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)((C_word*)t0)[3])[1];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}

/* f_10841 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_10841(C_word c,C_word *av){
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
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(52,c,3)))){
C_save_and_reclaim((void *)f_10841,c,av);}
a=C_alloc(52);
t3=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[4])[1]);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[5])[1],((C_word*)((C_word*)t0)[2])[1]);
t5=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[6])[1],t4);
t6=C_a_i_list(&a,1,t5);
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_10869,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[8],a[4]=t6,a[5]=((C_word*)t0)[9],a[6]=t3,a[7]=t1,tmp=(C_word)a,a+=8,tmp);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=((C_word*)((C_word*)t0)[10])[1];
t13=C_i_check_list_2(t2,lf[16]);
t14=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10879,a[2]=((C_word*)t0)[11],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[12],a[5]=t7,tmp=(C_word)a,a+=6,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_set_block_item(t16,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_10893,a[2]=t10,a[3]=t16,a[4]=t12,a[5]=t11,a[6]=((C_word)li123),tmp=(C_word)a,a+=7,tmp));
t18=((C_word*)t16)[1];
f_10893(t18,t14,t2);}

/* k10867 */
static void C_ccall f_10869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,1)))){
C_save_and_reclaim((void *)f_10869,c,av);}
a=C_alloc(27);
t2=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[2])[1],t1);
t3=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[3])[1],((C_word*)t0)[4],t2);
t4=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[5])[1],((C_word*)t0)[6],t3);
t5=((C_word*)t0)[7];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,2,lf[202],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k10877 */
static void C_ccall f_10879(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_10879,c,av);}
a=C_alloc(15);
t2=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[2])[1],((C_word*)((C_word*)t0)[3])[1]);
t3=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[4])[1],t2);
t4=C_a_i_list(&a,1,t3);
/* synrules.scm:139: ##sys#append */
t5=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[5];
av2[2]=t1;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}

/* map-loop3362 */
static void C_fcall f_10893(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_10893,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10918,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:142: g3368 */
t4=((C_word*)t0)[4];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_slot(t2,C_fix(0));
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k10916 in map-loop3362 */
static void C_ccall f_10918(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_10918,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_10893(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* f_10935 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_10935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,2)))){
C_save_and_reclaim((void *)f_10935,c,av);}
a=C_alloc(11);
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10942,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_pairp(t2))){
t4=C_i_pairp(C_u_i_cdr(t2));
t5=t3;
f_10942(t5,(C_truep(t4)?C_i_nullp(C_i_cddr(t2)):C_SCHEME_FALSE));}
else{
t4=t3;
f_10942(t4,C_SCHEME_FALSE);}}

/* k10940 */
static void C_fcall f_10942(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_10942,2,t0,t1);}
a=C_alloc(11);
if(C_truep(t1)){
t2=C_i_cdar(((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_10978,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=t3,a[7]=((C_word*)t0)[7],a[8]=t2,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* synrules.scm:151: process-match */
t5=((C_word*)((C_word*)t0)[10])[1];{
C_word av2[5];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)((C_word*)t0)[9])[1];
av2[3]=t2;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t5))(5,av2);}}
else{
/* synrules.scm:158: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[237];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k10961 in k10976 in k10940 */
static void C_ccall f_10963(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,5)))){
C_save_and_reclaim((void *)f_10963,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_10967,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_10971,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* synrules.scm:157: meta-variables */
t4=((C_word*)((C_word*)t0)[7])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[8];
av2[3]=C_fix(0);
av2[4]=C_SCHEME_END_OF_LIST;
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t4))(6,av2);}}

/* k10965 in k10961 in k10976 in k10940 */
static void C_ccall f_10967(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_10967,c,av);}
a=C_alloc(15);
t2=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3],t1);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,((C_word*)t0)[5],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10969 in k10961 in k10976 in k10940 */
static void C_ccall f_10971(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_10971,c,av);}
/* synrules.scm:155: process-template */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=C_fix(0);
av2[4]=t1;
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* a10972 in k10976 in k10940 */
static void C_ccall f_10973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_10973,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k10976 in k10940 */
static void C_ccall f_10978(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_10978,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[2])[1],t1);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_10963,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10973,a[2]=((C_word)li125),tmp=(C_word)a,a+=3,tmp);
/* synrules.scm:152: process-pattern */
t5=((C_word*)((C_word*)t0)[9])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=((C_word*)t0)[8];
av2[3]=((C_word*)((C_word*)t0)[10])[1];
av2[4]=t4;
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t5))(6,av2);}}

/* f_11001 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11001(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(24,c,3)))){
C_save_and_reclaim((void *)f_11001,c,av);}
a=C_alloc(24);
if(C_truep(C_i_symbolp(t3))){
if(C_truep(C_i_memq(t3,((C_word*)t0)[2]))){
t5=C_a_i_list(&a,2,lf[238],t3);
t6=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[3])[1],t5);
t7=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],t2,t6);
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,1,t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t5=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_11035,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
/* synrules.scm:167: segment-pattern? */
t6=((C_word*)((C_word*)t0)[17])[1];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
av2[3]=t4;
((C_proc)C_fast_retrieve_proc(t6))(4,av2);}}}

/* k11033 */
static void C_ccall f_11035(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,4)))){
C_save_and_reclaim((void *)f_11035,c,av);}
a=C_alloc(35);
if(C_truep(t1)){
/* synrules.scm:168: process-segment-match */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[5]))){
t2=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[6])[1],((C_word*)t0)[4]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[7])[1],((C_word*)((C_word*)t0)[6])[1]);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11071,a[2]=t4,a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=t3,a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11075,a[2]=t5,a[3]=((C_word*)t0)[10],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[11],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t7=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[12])[1],((C_word*)((C_word*)t0)[6])[1]);
/* synrules.scm:172: process-match */
t8=((C_word*)((C_word*)t0)[11])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t8;
av2[1]=t6;
av2[2]=t7;
av2[3]=C_u_i_car(((C_word*)t0)[5]);
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t8))(5,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[5]))){
t2=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[6])[1],((C_word*)t0)[4]);
t3=C_a_i_list(&a,1,t2);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[13])[1],((C_word*)((C_word*)t0)[6])[1]);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11128,a[2]=t4,a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[9],a[5]=t3,a[6]=((C_word*)t0)[3],tmp=(C_word)a,a+=7,tmp);
t6=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[14])[1],((C_word*)((C_word*)t0)[6])[1]);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11136,a[2]=((C_word*)t0)[11],a[3]=t5,a[4]=t6,tmp=(C_word)a,a+=5,tmp);
/* synrules.scm:178: scheme#vector->list */
t8=*((C_word*)lf[198]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}
else{
t2=C_i_nullp(((C_word*)t0)[5]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11149,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[15],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[16],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t2)){
t4=t3;
f_11149(t4,t2);}
else{
t4=C_booleanp(((C_word*)t0)[5]);
t5=t3;
f_11149(t5,(C_truep(t4)?t4:C_charp(((C_word*)t0)[5])));}}}}}

/* k11069 in k11033 */
static void C_ccall f_11071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_11071,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[3])[1],t2);
t4=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5],t3);
t5=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,1,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k11073 in k11033 */
static void C_ccall f_11075(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_11075,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11079,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[3])[1],((C_word*)((C_word*)t0)[4])[1]);
/* synrules.scm:173: process-match */
t4=((C_word*)((C_word*)t0)[5])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=t3;
av2[3]=C_u_i_cdr(((C_word*)t0)[6]);
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t4))(5,av2);}}

/* k11077 in k11073 in k11033 */
static void C_ccall f_11079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11079,c,av);}
/* synrules.scm:170: ##sys#append */
t2=*((C_word*)lf[73]+1);{
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

/* k11126 in k11033 */
static void C_ccall f_11128(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,1)))){
C_save_and_reclaim((void *)f_11128,c,av);}
a=C_alloc(18);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[3])[1],t2);
t4=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5],t3);
t5=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,1,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k11134 in k11033 */
static void C_ccall f_11136(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11136,c,av);}
/* synrules.scm:177: process-match */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* k11147 in k11033 */
static void C_fcall f_11149(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,1)))){
C_save_and_reclaim_args((void *)trf_11149,2,t0,t1);}
a=C_alloc(18);
if(C_truep(t1)){
t2=C_a_i_list(&a,2,lf[239],((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[3])[1],((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_a_i_list(&a,2,lf[239],((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[6])[1],((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_list(&a,1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* f_11182 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11182(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,4)))){
C_save_and_reclaim((void *)f_11182,c,av);}
a=C_alloc(25);
t4=(*a=C_CLOSURE_TYPE|18,a[1]=(C_word)f_11186,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=t3,a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],a[12]=((C_word*)t0)[10],a[13]=((C_word*)t0)[11],a[14]=((C_word*)t0)[12],a[15]=t1,a[16]=((C_word*)t0)[13],a[17]=((C_word*)t0)[14],a[18]=((C_word*)t0)[15],tmp=(C_word)a,a+=19,tmp);
t5=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[16])[1],((C_word*)((C_word*)t0)[6])[1]);
/* synrules.scm:185: process-match */
t6=((C_word*)((C_word*)t0)[15])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t4;
av2[2]=t5;
av2[3]=C_i_car(t3);
av2[4]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t6))(5,av2);}}

/* k11184 */
static void C_ccall f_11186(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(75,c,4)))){
C_save_and_reclaim((void *)f_11186,c,av);}
a=C_alloc(75);
t2=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]);
t3=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[3]);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[5])[1],t3);
t5=C_a_i_list(&a,1,t4);
t6=C_i_cddr(((C_word*)t0)[6]);
t7=C_i_length(t6);
t8=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[7])[1],((C_word*)((C_word*)t0)[5])[1],t7);
t9=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[8])[1],((C_word*)t0)[3]);
t10=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[5])[1],((C_word*)((C_word*)t0)[5])[1]);
t11=C_a_i_list(&a,2,t9,t10);
t12=C_u_i_cdr(((C_word*)t0)[6]);
t13=C_i_length(C_u_i_cdr(t12));
t14=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[9])[1],((C_word*)((C_word*)t0)[5])[1],t13);
t15=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_11265,a[2]=t14,a[3]=((C_word*)t0)[10],a[4]=((C_word*)t0)[11],a[5]=((C_word*)t0)[12],a[6]=((C_word*)t0)[13],a[7]=((C_word*)t0)[14],a[8]=t11,a[9]=t8,a[10]=t5,a[11]=t2,a[12]=((C_word*)t0)[15],a[13]=((C_word*)t0)[16],a[14]=((C_word*)t0)[8],a[15]=((C_word*)t0)[17],a[16]=((C_word*)t0)[5],a[17]=t1,tmp=(C_word)a,a+=18,tmp);
t16=C_u_i_cdr(((C_word*)t0)[6]);
/* synrules.scm:193: process-match */
t17=((C_word*)((C_word*)t0)[18])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t17;
av2[1]=t15;
av2[2]=((C_word*)((C_word*)t0)[8])[1];
av2[3]=C_u_i_cdr(t16);
av2[4]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t17))(5,av2);}}

/* k11239 in k11263 in k11184 */
static void C_ccall f_11241(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(60,c,1)))){
C_save_and_reclaim((void *)f_11241,c,av);}
a=C_alloc(60);
t2=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[2])[1],t1);
t3=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[3])[1],t2);
t4=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5],t3);
t5=C_a_i_list(&a,4,((C_word*)((C_word*)t0)[6])[1],((C_word*)((C_word*)t0)[7])[1],((C_word*)t0)[8],t4);
t6=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[9],t5);
t7=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[6])[1],((C_word*)t0)[10],t6);
t8=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[11],t7);
t9=((C_word*)t0)[12];{
C_word *av2=av;
av2[0]=t9;
av2[1]=C_a_i_list(&a,1,t8);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k11263 in k11184 */
static void C_ccall f_11265(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(43,c,3)))){
C_save_and_reclaim((void *)f_11265,c,av);}
a=C_alloc(43);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_11241,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=t2,a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],tmp=(C_word)a,a+=13,tmp);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[13])[1],((C_word*)((C_word*)t0)[14])[1]);
t5=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[15])[1],((C_word*)((C_word*)t0)[16])[1],C_fix(-1));
t6=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[7])[1],t4,t5);
t7=C_a_i_list(&a,1,t6);
/* synrules.scm:186: ##sys#append */
t8=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t8;
av2[1]=t3;
av2[2]=((C_word*)t0)[17];
av2[3]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(4,av2);}}

/* f_11309 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11309(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_11309,c,av);}
a=C_alloc(15);
if(C_truep(C_i_symbolp(t2))){
if(C_truep(C_i_memq(t2,((C_word*)t0)[2]))){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11333,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* synrules.scm:205: mapit */
t7=t4;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}}
else{
t6=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_11339,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=t4,a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],a[12]=((C_word*)t0)[9],a[13]=((C_word*)t0)[10],a[14]=((C_word*)t0)[11],tmp=(C_word)a,a+=15,tmp);
/* synrules.scm:206: segment-pattern? */
t7=((C_word*)((C_word*)t0)[12])[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=t5;
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}}

/* k11331 */
static void C_ccall f_11333(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11333,c,av);}
a=C_alloc(9);
t2=C_a_i_list2(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list1(&a,1,t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k11337 */
static void C_ccall f_11339(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(26,c,5)))){
C_save_and_reclaim((void *)f_11339,c,av);}
a=C_alloc(26);
if(C_truep(t1)){
t2=C_i_cddr(((C_word*)t0)[2]);
t3=C_i_length(t2);
t4=C_eqp(t3,C_fix(0));
t5=(C_truep(t4)?((C_word*)t0)[3]:C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[3],t3));
t6=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11352,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],a[6]=t3,a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t7=C_u_i_car(((C_word*)t0)[2]);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11368,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[8],a[4]=t5,a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],a[7]=((C_word)li129),tmp=(C_word)a,a+=8,tmp);
/* synrules.scm:212: process-pattern */
t9=((C_word*)((C_word*)t0)[7])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t9;
av2[1]=t6;
av2[2]=t7;
av2[3]=((C_word*)((C_word*)t0)[9])[1];
av2[4]=t8;
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t9))(6,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11414,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[12],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[13])[1],((C_word*)t0)[3]);
/* synrules.scm:223: process-pattern */
t5=((C_word*)((C_word*)t0)[7])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
av2[4]=((C_word*)t0)[8];
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t5))(6,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11443,a[2]=((C_word*)t0)[14],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[8],tmp=(C_word)a,a+=7,tmp);
/* synrules.scm:226: scheme#vector->list */
t3=*((C_word*)lf[198]+1);{
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
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}}

/* k11350 in k11337 */
static void C_ccall f_11352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,5)))){
C_save_and_reclaim((void *)f_11352,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11356,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_i_cddr(((C_word*)t0)[3]);
t4=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5],((C_word*)t0)[6]);
/* synrules.scm:220: process-pattern */
t5=((C_word*)((C_word*)t0)[7])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
av2[4]=((C_word*)t0)[8];
av2[5]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t5))(6,av2);}}

/* k11354 in k11350 in k11337 */
static void C_ccall f_11356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11356,c,av);}
/* synrules.scm:211: scheme#append */
t2=*((C_word*)lf[15]+1);{
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

/* a11367 in k11337 */
static void C_ccall f_11368(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,2)))){
C_save_and_reclaim((void *)f_11368,c,av);}
a=C_alloc(21);
t3=C_eqp(((C_word*)((C_word*)t0)[2])[1],t2);
if(C_truep(t3)){
/* synrules.scm:215: mapit */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}
else{
t4=C_a_i_list(&a,1,((C_word*)((C_word*)t0)[2])[1]);
t5=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[5])[1],t4,t2);
t6=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[6])[1],t5,((C_word*)t0)[4]);
/* synrules.scm:215: mapit */
t7=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
av2[2]=t6;
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}}

/* k11412 in k11337 */
static void C_ccall f_11414(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_11414,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11418,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t3=C_u_i_cdr(((C_word*)t0)[3]);
t4=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5]);
/* synrules.scm:224: process-pattern */
t5=((C_word*)((C_word*)t0)[6])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
av2[4]=((C_word*)t0)[7];
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t5))(6,av2);}}

/* k11416 in k11412 in k11337 */
static void C_ccall f_11418(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11418,c,av);}
/* synrules.scm:223: scheme#append */
t2=*((C_word*)lf[15]+1);{
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

/* k11441 in k11337 */
static void C_ccall f_11443(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_11443,c,av);}
a=C_alloc(6);
t2=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[2])[1],((C_word*)t0)[3]);
/* synrules.scm:226: process-pattern */
t3=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[5];
av2[2]=t1;
av2[3]=t2;
av2[4]=((C_word*)t0)[6];
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t3))(6,av2);}}

/* f_11449 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11449(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_11449,c,av);}
a=C_alloc(15);
if(C_truep(C_i_symbolp(t2))){
t5=C_i_assq(t2,t4);
if(C_truep(t5)){
t6=C_i_cdr(t5);
if(C_truep(C_fixnum_less_or_equal_p(t6,t3))){
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
/* synrules.scm:238: ##sys#syntax-error-hook */
t7=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
av2[2]=lf[240];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}}
else{
t6=C_a_i_list(&a,2,lf[238],t2);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[2])[1],t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t5=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_11488,a[2]=t3,a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=t4,a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],a[11]=((C_word*)t0)[8],a[12]=((C_word*)t0)[9],a[13]=((C_word*)t0)[10],a[14]=((C_word*)t0)[11],tmp=(C_word)a,a+=15,tmp);
/* synrules.scm:241: segment-template? */
t6=((C_word*)((C_word*)t0)[12])[1];{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}}

/* k11486 */
static void C_ccall f_11488(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_11488,c,av);}
a=C_alloc(11);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_11491,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
/* synrules.scm:242: segment-depth */
t3=((C_word*)((C_word*)t0)[11])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[4]))){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11611,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[12],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* synrules.scm:267: process-template */
t3=((C_word*)((C_word*)t0)[5])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_car(((C_word*)t0)[4]);
av2[3]=((C_word*)t0)[2];
av2[4]=((C_word*)t0)[6];
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[4]))){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11632,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[13],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11636,a[2]=((C_word*)t0)[5],a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:271: scheme#vector->list */
t4=*((C_word*)lf[198]+1);{
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
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[14])[1],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}}

/* k11489 in k11486 */
static void C_ccall f_11491(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_11491,c,av);}
a=C_alloc(12);
t2=C_fixnum_plus(((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_11497,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t1,a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=t2,tmp=(C_word)a,a+=12,tmp);
/* synrules.scm:245: free-meta-variables */
t4=((C_word*)((C_word*)t0)[10])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(((C_word*)t0)[4]);
av2[3]=t2;
av2[4]=((C_word*)t0)[6];
av2[5]=C_SCHEME_END_OF_LIST;
((C_proc)C_fast_retrieve_proc(t4))(6,av2);}}

/* k11495 in k11489 in k11486 */
static void C_ccall f_11497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,4)))){
C_save_and_reclaim((void *)f_11497,c,av);}
a=C_alloc(12);
if(C_truep(C_i_nullp(t1))){
/* synrules.scm:247: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[241];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_11509,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=t1,a[11]=((C_word*)t0)[10],tmp=(C_word)a,a+=12,tmp);
/* synrules.scm:248: process-template */
t3=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_car(((C_word*)t0)[3]);
av2[3]=((C_word*)t0)[11];
av2[4]=((C_word*)t0)[6];
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}}

/* k11507 in k11495 in k11489 in k11486 */
static void C_ccall f_11509(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_11509,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11512,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11559,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[9],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[10]))){
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[10])))){
t4=C_i_symbolp(t1);
t5=t3;
f_11559(t5,(C_truep(t4)?C_eqp(t1,C_u_i_car(((C_word*)t0)[10])):C_SCHEME_FALSE));}
else{
t4=t3;
f_11559(t4,C_SCHEME_FALSE);}}
else{
t4=t3;
f_11559(t4,C_SCHEME_FALSE);}}

/* k11510 in k11507 in k11495 in k11489 in k11486 */
static void C_fcall f_11512(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,0,4)))){
C_save_and_reclaim_args((void *)trf_11512,2,t0,t1);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11515,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11538,a[2]=t4,a[3]=((C_word)li131),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_11538(t6,t2,((C_word*)t0)[8],t1);}

/* k11513 in k11510 in k11507 in k11495 in k11489 in k11486 */
static void C_ccall f_11515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_11515,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_11536,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* synrules.scm:262: segment-tail */
t3=((C_word*)((C_word*)t0)[6])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k11526 in k11534 in k11513 in k11510 in k11507 in k11495 in k11489 in k11486 */
static void C_ccall f_11528(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11528,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[73],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11530 in k11534 in k11513 in k11510 in k11507 in k11495 in k11489 in k11486 */
static void C_ccall f_11532(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11532,c,av);}
/* synrules.scm:264: process-template */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* k11534 in k11513 in k11510 in k11507 in k11495 in k11489 in k11486 */
static void C_ccall f_11536(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_11536,c,av);}
a=C_alloc(10);
if(C_truep(C_i_nullp(t1))){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11528,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11532,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:264: segment-tail */
t4=((C_word*)((C_word*)t0)[7])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[8];
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}}

/* doloop3496 in k11510 in k11507 in k11495 in k11489 in k11486 */
static void C_fcall f_11538(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_11538,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_eqp(t2,C_fix(1));
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_fixnum_difference(t2,C_fix(1));
t6=C_a_i_list(&a,3,lf[242],lf[73],t3);
t8=t1;
t9=t5;
t10=t6;
t1=t8;
t2=t9;
t3=t10;
goto loop;}}

/* k11557 in k11507 in k11495 in k11489 in k11486 */
static void C_fcall f_11559(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,1)))){
C_save_and_reclaim_args((void *)trf_11559,2,t0,t1);}
a=C_alloc(15);
if(C_truep(t1)){
t2=((C_word*)t0)[2];
f_11512(t2,((C_word*)t0)[3]);}
else{
t2=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[4])[1],((C_word*)t0)[5],((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[5]);
t4=((C_word*)t0)[2];
f_11512(t4,C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[6])[1],t3));}}

/* k11609 in k11486 */
static void C_ccall f_11611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_11611,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11615,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* synrules.scm:268: process-template */
t3=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_u_i_cdr(((C_word*)t0)[5]);
av2[3]=((C_word*)t0)[6];
av2[4]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}

/* k11613 in k11609 in k11486 */
static void C_ccall f_11615(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_11615,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,((C_word*)((C_word*)t0)[3])[1],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11630 in k11486 */
static void C_ccall f_11632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_11632,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,((C_word*)((C_word*)t0)[3])[1],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11634 in k11486 */
static void C_ccall f_11636(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11636,c,av);}
/* synrules.scm:271: process-template */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* f_11641 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11641(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_11641,c,av);}
a=C_alloc(7);
if(C_truep(C_i_symbolp(t2))){
if(C_truep(C_i_memq(t2,((C_word*)t0)[2]))){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_a_i_cons(&a,2,t2,t3);
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_cons(&a,2,t6,t4);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11667,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
/* synrules.scm:282: segment-pattern? */
t7=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
av2[3]=t5;
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}}

/* k11665 */
static void C_ccall f_11667(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,5)))){
C_save_and_reclaim((void *)f_11667,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_fixnum_plus(((C_word*)t0)[3],C_fix(1));
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11682,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:284: meta-variables */
t5=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_cddr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[6];
av2[5]=C_SCHEME_TRUE;
((C_proc)C_fast_retrieve_proc(t5))(6,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11701,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:287: meta-variables */
t4=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_u_i_cdr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[6];
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t4))(6,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11716,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[6],tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:289: scheme#vector->list */
t3=*((C_word*)lf[198]+1);{
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
t2=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}}

/* k11680 in k11665 */
static void C_ccall f_11682(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11682,c,av);}
/* synrules.scm:283: meta-variables */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=t1;
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* k11699 in k11665 */
static void C_ccall f_11701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11701,c,av);}
/* synrules.scm:286: meta-variables */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=t1;
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* k11714 in k11665 */
static void C_ccall f_11716(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11716,c,av);}
/* synrules.scm:289: meta-variables */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=C_SCHEME_FALSE;
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* f_11718 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11718(C_word c,C_word *av){
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
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_11718,c,av);}
a=C_alloc(8);
if(C_truep(C_i_symbolp(t2))){
t6=C_i_memq(t2,t5);
if(C_truep(C_i_not(t6))){
t7=C_i_assq(t2,t4);
if(C_truep(t7)){
t8=C_i_cdr(t7);
t9=C_fixnum_greater_or_equal_p(t8,t3);
t10=t1;{
C_word *av2=av;
av2[0]=t10;
av2[1]=(C_truep(t9)?C_a_i_cons(&a,2,t2,t5):t5);
((C_proc)(void*)(*((C_word*)t10+1)))(2,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}
else{
t7=t1;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}
else{
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11760,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=t3,a[6]=t4,a[7]=t5,tmp=(C_word)a,a+=8,tmp);
/* synrules.scm:301: segment-template? */
t7=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}}

/* k11758 */
static void C_ccall f_11760(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,5)))){
C_save_and_reclaim((void *)f_11760,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11771,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* synrules.scm:304: free-meta-variables */
t4=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_cddr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t4))(6,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11790,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* synrules.scm:309: free-meta-variables */
t4=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_u_i_cdr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t4))(6,av2);}}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[2]))){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_11805,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* synrules.scm:312: scheme#vector->list */
t3=*((C_word*)lf[198]+1);{
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
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}}

/* k11769 in k11758 */
static void C_ccall f_11771(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11771,c,av);}
/* synrules.scm:302: free-meta-variables */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=t1;
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* k11788 in k11758 */
static void C_ccall f_11790(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11790,c,av);}
/* synrules.scm:307: free-meta-variables */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=t1;
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* k11803 in k11758 */
static void C_ccall f_11805(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_11805,c,av);}
/* synrules.scm:312: free-meta-variables */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
av2[5]=((C_word*)t0)[6];
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* f_11807 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11807(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11807,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11814,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* synrules.scm:316: segment-template? */
t5=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k11812 */
static void C_ccall f_11814(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_11814,c,av);}
if(C_truep(t1)){
if(C_truep(((C_word*)t0)[2])){
/* synrules.scm:319: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[243];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_i_listp(((C_word*)t0)[4]);
if(C_truep(C_i_not(t2))){
/* synrules.scm:321: ##sys#syntax-error-hook */
t3=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[244];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* f_11835 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11835(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11835,c,av);}
if(C_truep(C_i_pairp(t2))){
if(C_truep(C_i_pairp(C_u_i_cdr(t2)))){
/* synrules.scm:327: ellipsis? */
t3=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
av2[2]=C_i_cadr(t2);
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* f_11859 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_11859,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11866,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* synrules.scm:332: segment-template? */
t4=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* k11864 */
static void C_ccall f_11866(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_11866,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11873,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* synrules.scm:333: segment-depth */
t3=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cdr(((C_word*)t0)[4]);
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fix(0);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k11871 in k11864 */
static void C_ccall f_11873(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11873,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_fixnum_plus(C_fix(1),t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* f_11879 in k10831 in k10827 in k10823 in k10819 in k10814 in k10810 in k10806 in k10802 in k10797 in k10790 in k10785 in k10781 in k10777 in k10773 in k10769 in k10765 in k10759 in k10754 in k10750 in k10735 in k11952 in ... */
static void C_ccall f_11879(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_11879,c,av);}
a=C_alloc(7);
t3=C_i_cdr(t2);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11889,a[2]=t5,a[3]=((C_word*)t0)[2],a[4]=((C_word)li138),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_11889(t7,t1,t3);}

/* loop */
static void C_fcall f_11889(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_11889,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11896,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_pairp(t2))){
/* synrules.scm:341: ellipsis? */
t4=((C_word*)((C_word*)t0)[3])[1];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_u_i_car(t2);
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k11894 in loop */
static void C_ccall f_11896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11896,c,av);}
if(C_truep(t1)){
/* synrules.scm:342: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_11889(t2,((C_word*)t0)[3],C_i_cdr(((C_word*)t0)[4]));}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k11915 in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_11917(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11917,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[18]+1 /* (set! ##sys#scheme-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11921,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11936,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1702: ##sys#macro-environment */
t5=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k11919 in k11915 in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_11921(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_11921,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[92]+1 /* (set! ##sys#default-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11925,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11932,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1704: ##sys#macro-environment */
t5=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k11923 in k11919 in k11915 in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_11925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_11925,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[210]+1 /* (set! ##sys#meta-macro-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_11928,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1708: chicken.platform#register-feature! */
t4=*((C_word*)lf[211]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[212];
av2[3]=lf[213];
av2[4]=lf[214];
av2[5]=lf[215];
((C_proc)(void*)(*((C_word*)t4+1)))(6,av2);}}

/* k11926 in k11923 in k11919 in k11915 in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_11928(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11928,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k11930 in k11919 in k11915 in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_11932(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11932,c,av);}
/* expand.scm:1704: chicken.base#make-parameter */
t2=*((C_word*)lf[216]+1);{
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

/* k11934 in k11915 in k10654 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_11936(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_11936,c,av);}
/* expand.scm:1702: chicken.internal#fixup-macro-environment */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[217]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[217]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k11938 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_11940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11940,c,av);}
/* synrules.scm:43: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[219];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_11942(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_11942,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11946,a[2]=t2,a[3]=t4,a[4]=t1,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:48: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[219];
av2[3]=t2;
av2[4]=lf[259];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_11946(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(20,c,4)))){
C_save_and_reclaim((void *)f_11946,c,av);}
a=C_alloc(20);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_u_i_cdr(((C_word*)t0)[2]);
t6=C_u_i_cdr(t5);
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=lf[220];
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_11954,a[2]=t9,a[3]=t7,a[4]=t4,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_symbolp(((C_word*)t4)[1]))){
t11=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_11963,a[2]=t9,a[3]=t4,a[4]=t7,a[5]=t10,tmp=(C_word)a,a+=6,tmp);
/* synrules.scm:53: ##sys#check-syntax */
t12=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t11;
av2[2]=lf[219];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[258];
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}
else{
t11=t10;
f_11954(t11,C_SCHEME_UNDEFINED);}}

/* k11952 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_11954(C_word t0,C_word t1){
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
C_word t86;
C_word t87;
C_word t88;
C_word t89;
C_word t90;
C_word t91;
C_word t92;
C_word t93;
C_word t94;
C_word t95;
C_word t96;
C_word t97;
C_word t98;
C_word t99;
C_word t100;
C_word t101;
C_word t102;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(152,0,2)))){
C_save_and_reclaim_args((void *)trf_11954,2,t0,t1);}
a=C_alloc(152);
t2=((C_word*)((C_word*)t0)[2])[1];
t3=((C_word*)((C_word*)t0)[3])[1];
t4=((C_word*)((C_word*)t0)[4])[1];
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_SCHEME_UNDEFINED;
t16=(*a=C_VECTOR_TYPE|1,a[1]=t15,tmp=(C_word)a,a+=2,tmp);
t17=C_SCHEME_UNDEFINED;
t18=(*a=C_VECTOR_TYPE|1,a[1]=t17,tmp=(C_word)a,a+=2,tmp);
t19=C_SCHEME_UNDEFINED;
t20=(*a=C_VECTOR_TYPE|1,a[1]=t19,tmp=(C_word)a,a+=2,tmp);
t21=C_SCHEME_UNDEFINED;
t22=(*a=C_VECTOR_TYPE|1,a[1]=t21,tmp=(C_word)a,a+=2,tmp);
t23=C_SCHEME_UNDEFINED;
t24=(*a=C_VECTOR_TYPE|1,a[1]=t23,tmp=(C_word)a,a+=2,tmp);
t25=C_SCHEME_UNDEFINED;
t26=(*a=C_VECTOR_TYPE|1,a[1]=t25,tmp=(C_word)a,a+=2,tmp);
t27=C_SCHEME_UNDEFINED;
t28=(*a=C_VECTOR_TYPE|1,a[1]=t27,tmp=(C_word)a,a+=2,tmp);
t29=C_SCHEME_UNDEFINED;
t30=(*a=C_VECTOR_TYPE|1,a[1]=t29,tmp=(C_word)a,a+=2,tmp);
t31=C_SCHEME_UNDEFINED;
t32=(*a=C_VECTOR_TYPE|1,a[1]=t31,tmp=(C_word)a,a+=2,tmp);
t33=C_SCHEME_UNDEFINED;
t34=(*a=C_VECTOR_TYPE|1,a[1]=t33,tmp=(C_word)a,a+=2,tmp);
t35=C_SCHEME_UNDEFINED;
t36=(*a=C_VECTOR_TYPE|1,a[1]=t35,tmp=(C_word)a,a+=2,tmp);
t37=C_SCHEME_UNDEFINED;
t38=(*a=C_VECTOR_TYPE|1,a[1]=t37,tmp=(C_word)a,a+=2,tmp);
t39=C_SCHEME_UNDEFINED;
t40=(*a=C_VECTOR_TYPE|1,a[1]=t39,tmp=(C_word)a,a+=2,tmp);
t41=C_SCHEME_UNDEFINED;
t42=(*a=C_VECTOR_TYPE|1,a[1]=t41,tmp=(C_word)a,a+=2,tmp);
t43=C_SCHEME_UNDEFINED;
t44=(*a=C_VECTOR_TYPE|1,a[1]=t43,tmp=(C_word)a,a+=2,tmp);
t45=C_SCHEME_UNDEFINED;
t46=(*a=C_VECTOR_TYPE|1,a[1]=t45,tmp=(C_word)a,a+=2,tmp);
t47=C_SCHEME_UNDEFINED;
t48=(*a=C_VECTOR_TYPE|1,a[1]=t47,tmp=(C_word)a,a+=2,tmp);
t49=C_SCHEME_UNDEFINED;
t50=(*a=C_VECTOR_TYPE|1,a[1]=t49,tmp=(C_word)a,a+=2,tmp);
t51=C_SCHEME_UNDEFINED;
t52=(*a=C_VECTOR_TYPE|1,a[1]=t51,tmp=(C_word)a,a+=2,tmp);
t53=C_SCHEME_UNDEFINED;
t54=(*a=C_VECTOR_TYPE|1,a[1]=t53,tmp=(C_word)a,a+=2,tmp);
t55=C_SCHEME_UNDEFINED;
t56=(*a=C_VECTOR_TYPE|1,a[1]=t55,tmp=(C_word)a,a+=2,tmp);
t57=C_SCHEME_UNDEFINED;
t58=(*a=C_VECTOR_TYPE|1,a[1]=t57,tmp=(C_word)a,a+=2,tmp);
t59=C_SCHEME_UNDEFINED;
t60=(*a=C_VECTOR_TYPE|1,a[1]=t59,tmp=(C_word)a,a+=2,tmp);
t61=C_SCHEME_UNDEFINED;
t62=(*a=C_VECTOR_TYPE|1,a[1]=t61,tmp=(C_word)a,a+=2,tmp);
t63=C_SCHEME_UNDEFINED;
t64=(*a=C_VECTOR_TYPE|1,a[1]=t63,tmp=(C_word)a,a+=2,tmp);
t65=C_SCHEME_UNDEFINED;
t66=(*a=C_VECTOR_TYPE|1,a[1]=t65,tmp=(C_word)a,a+=2,tmp);
t67=C_SCHEME_UNDEFINED;
t68=(*a=C_VECTOR_TYPE|1,a[1]=t67,tmp=(C_word)a,a+=2,tmp);
t69=C_SCHEME_UNDEFINED;
t70=(*a=C_VECTOR_TYPE|1,a[1]=t69,tmp=(C_word)a,a+=2,tmp);
t71=C_SCHEME_UNDEFINED;
t72=(*a=C_VECTOR_TYPE|1,a[1]=t71,tmp=(C_word)a,a+=2,tmp);
t73=C_SCHEME_UNDEFINED;
t74=(*a=C_VECTOR_TYPE|1,a[1]=t73,tmp=(C_word)a,a+=2,tmp);
t75=C_SCHEME_UNDEFINED;
t76=(*a=C_VECTOR_TYPE|1,a[1]=t75,tmp=(C_word)a,a+=2,tmp);
t77=C_SCHEME_UNDEFINED;
t78=(*a=C_VECTOR_TYPE|1,a[1]=t77,tmp=(C_word)a,a+=2,tmp);
t79=C_SCHEME_UNDEFINED;
t80=(*a=C_VECTOR_TYPE|1,a[1]=t79,tmp=(C_word)a,a+=2,tmp);
t81=C_SCHEME_UNDEFINED;
t82=(*a=C_VECTOR_TYPE|1,a[1]=t81,tmp=(C_word)a,a+=2,tmp);
t83=C_SCHEME_UNDEFINED;
t84=(*a=C_VECTOR_TYPE|1,a[1]=t83,tmp=(C_word)a,a+=2,tmp);
t85=C_SCHEME_UNDEFINED;
t86=(*a=C_VECTOR_TYPE|1,a[1]=t85,tmp=(C_word)a,a+=2,tmp);
t87=C_SCHEME_UNDEFINED;
t88=(*a=C_VECTOR_TYPE|1,a[1]=t87,tmp=(C_word)a,a+=2,tmp);
t89=C_SCHEME_UNDEFINED;
t90=(*a=C_VECTOR_TYPE|1,a[1]=t89,tmp=(C_word)a,a+=2,tmp);
t91=C_SCHEME_UNDEFINED;
t92=(*a=C_VECTOR_TYPE|1,a[1]=t91,tmp=(C_word)a,a+=2,tmp);
t93=C_SCHEME_UNDEFINED;
t94=(*a=C_VECTOR_TYPE|1,a[1]=t93,tmp=(C_word)a,a+=2,tmp);
t95=C_SCHEME_UNDEFINED;
t96=(*a=C_VECTOR_TYPE|1,a[1]=t95,tmp=(C_word)a,a+=2,tmp);
t97=C_SCHEME_UNDEFINED;
t98=(*a=C_VECTOR_TYPE|1,a[1]=t97,tmp=(C_word)a,a+=2,tmp);
t99=C_SCHEME_UNDEFINED;
t100=(*a=C_VECTOR_TYPE|1,a[1]=t99,tmp=(C_word)a,a+=2,tmp);
t101=(*a=C_CLOSURE_TYPE|55,a[1]=(C_word)f_10737,a[2]=t6,a[3]=t8,a[4]=t10,a[5]=t12,a[6]=t14,a[7]=t16,a[8]=t18,a[9]=t20,a[10]=t22,a[11]=t24,a[12]=t26,a[13]=t28,a[14]=t30,a[15]=t32,a[16]=t34,a[17]=t36,a[18]=t38,a[19]=t40,a[20]=t42,a[21]=t44,a[22]=t46,a[23]=t48,a[24]=t50,a[25]=t52,a[26]=t54,a[27]=t56,a[28]=t58,a[29]=t60,a[30]=t62,a[31]=t64,a[32]=t66,a[33]=t68,a[34]=t70,a[35]=t72,a[36]=t74,a[37]=t76,a[38]=((C_word*)t0)[5],a[39]=t78,a[40]=t80,a[41]=t88,a[42]=t90,a[43]=t86,a[44]=t82,a[45]=t4,a[46]=t84,a[47]=t94,a[48]=t100,a[49]=t92,a[50]=t98,a[51]=t96,a[52]=((C_word*)t0)[6],a[53]=t3,a[54]=((C_word*)t0)[7],a[55]=t2,tmp=(C_word)a,a+=56,tmp);
/* synrules.scm:93: r */
t102=((C_word*)t0)[7];{
C_word av2[3];
av2[0]=t102;
av2[1]=t101;
av2[2]=lf[257];
((C_proc)C_fast_retrieve_proc(t102))(3,av2);}}

/* k11961 in k11944 in a11941 in k10651 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_11963(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_11963,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,((C_word*)((C_word*)t0)[3])[1]);
t3=C_i_car(((C_word*)((C_word*)t0)[4])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t5=C_i_cdr(((C_word*)((C_word*)t0)[4])[1]);
t6=C_mutate(((C_word *)((C_word*)t0)[4])+1,t5);
t7=((C_word*)t0)[5];
f_11954(t7,t6);}

/* k11974 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_11976(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_11976,c,av);}
/* expand.scm:1682: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[260];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a11977 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_11978(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_11978,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_11982,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1687: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[260];
av2[3]=t2;
av2[4]=lf[264];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k11980 in a11977 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_11982(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_11982,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_11989,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1688: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[263];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k11987 in k11980 in a11977 in k10648 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_11989(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,1)))){
C_save_and_reclaim((void *)f_11989,c,av);}
a=C_alloc(30);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,lf[75],C_SCHEME_END_OF_LIST,t2);
t4=C_a_i_list(&a,3,lf[94],t3,lf[261]);
t5=C_a_i_list(&a,2,lf[262],t4);
t6=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,2,t1,t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k12007 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_ccall f_12009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12009,c,av);}
/* expand.scm:1630: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[265];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_ccall f_12011(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_12011,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12015,a[2]=t4,a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1635: r */
t6=t3;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[265];
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_12015(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_12015,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12018,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1636: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[266];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_12018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_12018,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12021,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1637: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[268];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_12021(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(28,c,4)))){
C_save_and_reclaim((void *)f_12021,c,av);}
a=C_alloc(28);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12023,a[2]=t7,a[3]=t5,a[4]=((C_word)li142),tmp=(C_word)a,a+=5,tmp));
t9=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12033,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word)li143),tmp=(C_word)a,a+=8,tmp));
t10=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12196,a[2]=t7,a[3]=((C_word)li146),tmp=(C_word)a,a+=4,tmp));
t11=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12291,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1679: ##sys#check-syntax */
t12=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t12;
av2[1]=t11;
av2[2]=lf[265];
av2[3]=((C_word*)t0)[6];
av2[4]=lf[278];
((C_proc)(void*)(*((C_word*)t12+1)))(5,av2);}}

/* walk in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_12023(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,3)))){
C_save_and_reclaim_args((void *)trf_12023,4,t0,t1,t2,t3);}
a=C_alloc(4);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12031,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1638: walk1 */
t5=((C_word*)((C_word*)t0)[3])[1];
f_12033(t5,t4,t2,t3);}

/* k12029 in walk in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12031(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_12031,c,av);}
/* expand.scm:1638: simplify */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12196(t2,((C_word*)t0)[3],t1);}

/* walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_12033(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_12033,4,t0,t1,t2,t3);}
a=C_alloc(12);
if(C_truep(C_i_vectorp(t2))){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12047,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12051,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1641: scheme#vector->list */
t6=*((C_word*)lf[198]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t4=C_i_pairp(t2);
if(C_truep(C_i_not(t4))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_list(&a,2,lf[74],t2);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=C_u_i_cdr(t2);
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_12070,a[2]=t3,a[3]=t1,a[4]=t6,a[5]=t2,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[4],a[9]=t5,a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[6],tmp=(C_word)a,a+=12,tmp);
/* expand.scm:1646: c */
t8=((C_word*)t0)[6];{
C_word av2[4];
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[3];
av2[3]=t5;
((C_proc)C_fast_retrieve_proc(t8))(4,av2);}}}}

/* k12045 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12047(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_12047,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,lf[226],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12049 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12051(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12051,c,av);}
/* expand.scm:1641: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12023(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4]);}

/* k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12070(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_12070,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=C_eqp(((C_word*)t0)[2],C_fix(0));
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12079,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1648: ##sys#check-syntax */
t4=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[266];
av2[3]=((C_word*)t0)[5];
av2[4]=lf[267];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=C_a_i_list(&a,2,lf[74],((C_word*)t0)[6]);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12093,a[2]=((C_word*)t0)[3],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1651: walk */
t5=((C_word*)((C_word*)t0)[7])[1];
f_12023(t5,t4,((C_word*)t0)[4],C_fixnum_difference(((C_word*)t0)[2],C_fix(1)));}}
else{
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12103,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[10],a[9]=((C_word*)t0)[11],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:1652: c */
t3=((C_word*)t0)[11];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=((C_word*)t0)[9];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k12077 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12079(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12079,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12091 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12093(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12093,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list3(&a,3,lf[230],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12103(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_12103,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=C_a_i_list(&a,2,lf[74],((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12114,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1654: walk */
t4=((C_word*)((C_word*)t0)[4])[1];
f_12023(t4,t3,((C_word*)t0)[5],C_fixnum_plus(((C_word*)t0)[6],C_fix(1)));}
else{
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12124,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[7]))){
/* expand.scm:1655: c */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=C_u_i_car(((C_word*)t0)[7]);
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_12124(2,av2);}}}}

/* k12112 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12114(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12114,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list3(&a,3,lf[230],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12124(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_12124,c,av);}
a=C_alloc(13);
if(C_truep(t1)){
t2=C_eqp(((C_word*)t0)[2],C_fix(0));
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12133,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1657: ##sys#check-syntax */
t4=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[268];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[269];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}
else{
t3=C_a_i_list(&a,2,lf[74],((C_word*)t0)[7]);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12163,a[2]=t3,a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1662: walk */
t5=((C_word*)((C_word*)t0)[5])[1];
f_12023(t5,t4,C_i_cdr(((C_word*)t0)[3]),C_fixnum_difference(((C_word*)t0)[2],C_fix(1)));}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12178,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1665: walk */
t3=((C_word*)((C_word*)t0)[5])[1];
f_12023(t3,t2,((C_word*)t0)[3],((C_word*)t0)[2]);}}

/* k12131 in k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_ccall f_12133(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_12133,c,av);}
a=C_alloc(4);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12144,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1658: walk */
t4=((C_word*)((C_word*)t0)[4])[1];
f_12023(t4,t3,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k12142 in k12131 in k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in ... */
static void C_ccall f_12144(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12144,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[73],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12153 in k12161 in k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in ... */
static void C_ccall f_12155(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12155,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[230],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12161 in k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_ccall f_12163(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_12163,c,av);}
a=C_alloc(13);
t2=C_a_i_list(&a,3,lf[230],((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12155,a[2]=((C_word*)t0)[3],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1663: walk */
t4=((C_word*)((C_word*)t0)[4])[1];
f_12023(t4,t3,((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k12176 in k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_ccall f_12178(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_12178,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12182,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1665: walk */
t3=((C_word*)((C_word*)t0)[3])[1];
f_12023(t3,t2,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k12180 in k12176 in k12122 in k12101 in k12068 in walk1 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in ... */
static void C_ccall f_12182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12182,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[230],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* simplify in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_12196(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,4)))){
C_save_and_reclaim_args((void *)trf_12196,3,t0,t1,t2);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12200,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1667: chicken.syntax#match-expression */
t4=*((C_word*)lf[120]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
av2[3]=lf[276];
av2[4]=lf[277];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k12198 in simplify in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_12200,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12204,a[2]=((C_word*)t0)[2],a[3]=((C_word)li144),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1667: g3226 */
t3=t2;
f_12204(t3,((C_word*)t0)[3],t1);}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12226,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1669: chicken.syntax#match-expression */
t3=*((C_word*)lf[120]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[274];
av2[4]=lf[275];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* g3226 in k12198 in simplify in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_fcall f_12204(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_12204,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_assq(lf[270],t2);
t4=C_i_cdr(t3);
t5=C_a_i_list(&a,2,lf[261],t4);
/* expand.scm:1668: simplify */
t6=((C_word*)((C_word*)t0)[2])[1];
f_12196(t6,t1,t5);}

/* k12224 in k12198 in simplify in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12226(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_12226,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12230,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word)li145),tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1667: g3233 */
t3=t2;
f_12230(t3,((C_word*)t0)[4],t1);}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12273,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1676: chicken.syntax#match-expression */
t3=*((C_word*)lf[120]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[3];
av2[3]=lf[272];
av2[4]=lf[273];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* g3233 in k12224 in k12198 in simplify in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_fcall f_12230(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_12230,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_assq(lf[271],t2);
t4=C_i_length(t3);
if(C_truep(C_fixnum_lessp(t4,C_fix(32)))){
t5=C_i_assq(lf[270],t2);
t6=C_i_cdr(t5);
t7=C_i_cdr(t3);
t8=C_a_i_cons(&a,2,t6,t7);
t9=C_a_i_cons(&a,2,lf[261],t8);
/* expand.scm:1673: simplify */
t10=((C_word*)((C_word*)t0)[2])[1];
f_12196(t10,t1,t9);}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k12271 in k12224 in k12198 in simplify in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12273(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12273,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_i_cdr(C_i_assq(lf[270],t1)):((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12289 in k12019 in k12016 in k12013 in a12010 in k10645 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12291,c,av);}
/* expand.scm:1680: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12023(t2,((C_word*)t0)[3],C_i_cadr(((C_word*)t0)[4]),C_fix(0));}

/* k12300 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in ... */
static void C_ccall f_12302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12302,c,av);}
/* expand.scm:1601: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[279];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in ... */
static void C_ccall f_12304(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12304,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12308,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1606: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[279];
av2[3]=t2;
av2[4]=lf[284];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_ccall f_12308(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12308,c,av);}
a=C_alloc(6);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_u_i_cdr(((C_word*)t0)[2]);
t5=C_u_i_cdr(t4);
t6=C_u_i_cdr(t5);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12320,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=t6,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1610: r */
t8=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[283];
((C_proc)C_fast_retrieve_proc(t8))(3,av2);}}

/* k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_12320(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12320,c,av);}
a=C_alloc(20);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=C_i_check_list_2(((C_word*)t0)[2],lf[16]);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12348,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12462,a[2]=t4,a[3]=t9,a[4]=t5,a[5]=((C_word)li149),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_12462(t11,t7,((C_word*)t0)[2]);}

/* k12346 in k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_12348(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_12348,c,av);}
a=C_alloc(17);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_eqp(t3,C_SCHEME_END_OF_LIST);
t5=(C_truep(t4)?lf[280]:C_a_i_cons(&a,2,lf[103],t3));
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12369,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=t5,a[5]=((C_word*)t0)[4],a[6]=t1,a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
t7=C_eqp(((C_word*)t0)[6],C_SCHEME_END_OF_LIST);
if(C_truep(t7)){
t8=t6;
f_12369(t8,lf[282]);}
else{
t8=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[6]);
t9=t6;
f_12369(t9,C_a_i_cons(&a,2,lf[51],t8));}}

/* k12367 in k12346 in k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_fcall f_12369(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,0,3)))){
C_save_and_reclaim_args((void *)trf_12369,2,t0,t1);}
a=C_alloc(21);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12410,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12412,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li148),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_12412(t10,t6,((C_word*)t0)[7]);}

/* k12408 in k12367 in k12346 in k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12410(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(39,c,1)))){
C_save_and_reclaim((void *)f_12410,c,av);}
a=C_alloc(39);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[54],t2);
t4=C_a_i_list(&a,3,lf[103],((C_word*)t0)[3],t3);
t5=C_a_i_list(&a,4,lf[281],((C_word*)t0)[4],((C_word*)t0)[5],t4);
t6=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,4,lf[51],((C_word*)t0)[2],((C_word*)t0)[7],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* map-loop3138 in k12367 in k12346 in k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_12412(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_12412,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12422,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=C_i_cdr(t4);
t6=C_i_cdr(t5);
t7=C_eqp(t6,C_SCHEME_END_OF_LIST);
if(C_truep(t7)){
t8=C_u_i_car(t4);
t9=t3;
f_12422(t9,C_a_i_cons(&a,2,t8,C_SCHEME_END_OF_LIST));}
else{
t8=C_i_cdr(C_u_i_cdr(t4));
t9=C_i_car(t8);
t10=t3;
f_12422(t10,C_a_i_cons(&a,2,t9,C_SCHEME_END_OF_LIST));}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12420 in map-loop3138 in k12367 in k12346 in k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_fcall f_12422(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_12422,2,t0,t1);}
t2=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t1);
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t4=((C_word*)((C_word*)t0)[3])[1];
f_12412(t4,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* map-loop3104 in k12318 in k12306 in a12303 in k10642 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_fcall f_12462(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_12462,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_i_car(t3);
t5=C_i_car(C_u_i_cdr(t3));
t6=C_a_i_list2(&a,2,t4,t5);
t7=C_a_i_cons(&a,2,t6,C_SCHEME_END_OF_LIST);
t8=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t7);
t9=C_mutate(((C_word *)((C_word*)t0)[2])+1,t7);
t11=t1;
t12=C_slot(t2,C_fix(1));
t1=t11;
t2=t12;
goto loop;}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12496 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in ... */
static void C_ccall f_12498(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12498,c,av);}
/* expand.scm:1588: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[91];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12499 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in ... */
static void C_ccall f_12500(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12500,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12504,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1593: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[91];
av2[3]=t2;
av2[4]=lf[285];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k12502 in a12499 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in ... */
static void C_ccall f_12504(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_12504,c,av);}
a=C_alloc(7);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12514,a[2]=t4,a[3]=t6,a[4]=((C_word)li151),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_12514(t8,((C_word*)t0)[3],t2);}

/* expand in k12502 in a12499 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_fcall f_12514(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_12514,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_eqp(t2,C_SCHEME_END_OF_LIST);
if(C_truep(t3)){
t4=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_a_i_cons(&a,2,lf[51],t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t4=C_i_car(t2);
t5=C_a_i_list(&a,1,t4);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12539,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1599: expand */
t8=t6;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}

/* k12537 in expand in k12502 in a12499 in k10639 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_12539(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12539,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[51],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12547 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in ... */
static void C_ccall f_12549(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12549,c,av);}
/* expand.scm:1543: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[286];
av2[3]=lf[287];
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in ... */
static void C_ccall f_12551(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_12551,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12555,a[2]=t2,a[3]=t1,a[4]=t4,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1548: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[286];
av2[3]=t2;
av2[4]=lf[297];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in ... */
static void C_ccall f_12555(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12555,c,av);}
a=C_alloc(7);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_u_i_cdr(t3);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12563,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t4,a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1551: r */
t6=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[296];
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in ... */
static void C_ccall f_12563(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12563,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12566,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:1552: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[248];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_ccall f_12566(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_12566,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12569,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* expand.scm:1553: r */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[295];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_12569(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_12569,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12572,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:1554: r */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[294];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_12572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_12572,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12575,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:1555: r */
t3=((C_word*)t0)[9];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[254];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_12575(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(25,c,4)))){
C_save_and_reclaim((void *)f_12575,c,av);}
a=C_alloc(25);
t2=C_a_i_list(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12586,a[2]=((C_word*)t0)[4],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12588,a[2]=t6,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=t1,a[9]=((C_word)li155),tmp=(C_word)a,a+=10,tmp));
t8=((C_word*)t6)[1];
f_12588(t8,t4,((C_word*)t0)[9],C_SCHEME_FALSE);}

/* k12584 in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12586(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12586,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[56],((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_fcall f_12588(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,0,4)))){
C_save_and_reclaim_args((void *)trf_12588,4,t0,t1,t2,t3);}
a=C_alloc(13);
t4=C_i_pairp(t2);
if(C_truep(C_i_not(t4))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=lf[288];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=C_u_i_cdr(t2);
t7=(*a=C_CLOSURE_TYPE|12,a[1]=(C_word)f_12602,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t6,a[6]=t5,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[8],tmp=(C_word)a,a+=13,tmp);
/* expand.scm:1562: ##sys#check-syntax */
t8=*((C_word*)lf[55]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[286];
av2[3]=t5;
av2[4]=lf[293];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}}

/* k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12602(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_12602,c,av);}
a=C_alloc(11);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12608,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12615,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1566: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
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
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_12621,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],tmp=(C_word)a,a+=11,tmp);
/* expand.scm:1569: c */
t3=((C_word*)t0)[8];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[12];
av2[3]=C_i_car(((C_word*)t0)[6]);
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k12606 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_12608,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12611,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1567: expand */
t3=((C_word*)((C_word*)t0)[3])[1];
f_12588(t3,t2,((C_word*)t0)[4],C_SCHEME_TRUE);}

/* k12609 in k12606 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12611(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12611,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[289];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12613 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12615(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12615,c,av);}
/* expand.scm:1564: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[290]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[290]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[291];
av2[3]=t1;
tp(4,av2);}}

/* k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12621(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(29,c,3)))){
C_save_and_reclaim((void *)f_12621,c,av);}
a=C_alloc(29);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12624,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1570: expand */
t3=((C_word*)((C_word*)t0)[7])[1];
f_12588(t3,t2,((C_word*)t0)[8],C_SCHEME_TRUE);}
else{
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12720,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[4],a[4]=((C_word)li153),tmp=(C_word)a,a+=5,tmp);
t7=C_u_i_car(((C_word*)t0)[2]);
t8=C_i_check_list_2(t7,lf[16]);
t9=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_12735,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12737,a[2]=t6,a[3]=t4,a[4]=t11,a[5]=t5,a[6]=((C_word)li154),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_12737(t13,t9,t7);}}

/* k12622 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12624(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_12624,c,av);}
a=C_alloc(5);
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[2])))){
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,1,lf[292]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12639,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_i_length(((C_word*)t0)[2]);
t4=C_eqp(t3,C_fix(3));
if(C_truep(t4)){
/* expand.scm:1574: c */
t5=((C_word*)t0)[5];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_i_cadr(((C_word*)t0)[2]);
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_12639(2,av2);}}}}

/* k12637 in k12622 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_ccall f_12639(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_12639,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_caddr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,t2,((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[103],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k12678 in k12733 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_fcall f_12680(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_12680,2,t0,t1);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12684,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1586: expand */
t3=((C_word*)((C_word*)t0)[4])[1];
f_12588(t3,t2,((C_word*)t0)[5],C_SCHEME_FALSE);}

/* k12682 in k12678 in k12733 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in ... */
static void C_ccall f_12684(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_12684,c,av);}
a=C_alloc(12);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,4,lf[281],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12685 in k12733 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in ... */
static void C_ccall f_12687(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_12687,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_caddr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];
f_12680(t3,C_a_i_list(&a,2,t2,((C_word*)t0)[4]));}
else{
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];
f_12680(t3,C_a_i_cons(&a,2,lf[103],t2));}}

/* g3045 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static C_word C_fcall f_12720(C_word *a,C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_stack_overflow_check;{}
t2=C_a_i_list(&a,2,lf[239],t1);
return(C_a_i_list(&a,3,((C_word*)t0)[2],((C_word*)t0)[3],t2));}

/* k12733 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12735(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12735,c,av);}
a=C_alloc(14);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12680,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12687,a[2]=((C_word*)t0)[6],a[3]=t3,a[4]=((C_word*)t0)[7],tmp=(C_word)a,a+=5,tmp);
t5=C_i_length(((C_word*)t0)[6]);
t6=C_eqp(t5,C_fix(3));
if(C_truep(t6)){
/* expand.scm:1583: c */
t7=((C_word*)t0)[8];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t4;
av2[2]=((C_word*)t0)[9];
av2[3]=C_i_cadr(((C_word*)t0)[6]);
((C_proc)C_fast_retrieve_proc(t7))(4,av2);}}
else{
t7=t4;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
f_12687(2,av2);}}}

/* map-loop3039 in k12619 in k12600 in expand in k12573 in k12570 in k12567 in k12564 in k12561 in k12553 in a12550 in k10636 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_fcall f_12737(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,2)))){
C_save_and_reclaim_args((void *)trf_12737,3,t0,t1,t2);}
a=C_alloc(18);
if(C_truep(C_i_pairp(t2))){
t3=(
/* expand.scm:1579: g3045 */
  f_12720(C_a_i(&a,15),((C_word*)t0)[2],C_slot(t2,C_fix(0)))
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

/* k12783 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in ... */
static void C_ccall f_12785(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_12785,c,av);}
/* expand.scm:1475: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[255];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in ... */
static void C_ccall f_12787(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_12787,c,av);}
a=C_alloc(6);
t5=C_i_cdr(t2);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12794,a[2]=t4,a[3]=t3,a[4]=t1,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1481: r */
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[295];
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}

/* k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in ... */
static void C_ccall f_12794(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_12794,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12797,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1482: r */
t3=((C_word*)t0)[3];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[248];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in ... */
static void C_ccall f_12797(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_12797,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_12800,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:1483: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[254];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in ... */
static void C_ccall f_12800(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,4)))){
C_save_and_reclaim((void *)f_12800,c,av);}
a=C_alloc(11);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12805,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word)li157),tmp=(C_word)a,a+=9,tmp));
t5=((C_word*)t3)[1];
f_12805(t5,((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_FALSE);}

/* expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in ... */
static void C_fcall f_12805(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_12805,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
if(C_truep(C_i_not(t4))){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=lf[298];
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
t6=C_u_i_cdr(t2);
t7=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_12819,a[2]=t3,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=t6,a[6]=t5,a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[4],a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],tmp=(C_word)a,a+=12,tmp);
/* expand.scm:1489: ##sys#check-syntax */
t8=*((C_word*)lf[55]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[255];
av2[3]=t5;
av2[4]=lf[306];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}}

/* k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in ... */
static void C_ccall f_12819(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_12819,c,av);}
a=C_alloc(11);
if(C_truep(((C_word*)t0)[2])){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12825,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12832,a[2]=t2,a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1492: chicken.base#open-output-string */
t4=*((C_word*)lf[144]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_12857,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],tmp=(C_word)a,a+=11,tmp);
/* expand.scm:1496: c */
t3=((C_word*)t0)[7];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=C_i_car(((C_word*)t0)[6]);
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}}

/* k12823 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_12825(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_12825,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_12828,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1494: expand */
t3=((C_word*)((C_word*)t0)[3])[1];
f_12805(t3,t2,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k12826 in k12823 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_12828(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_12828,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[299];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12830 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_12832(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_12832,c,av);}
a=C_alloc(6);
t2=C_i_check_port_2(t1,C_fix(2),C_SCHEME_TRUE,lf[300]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12838,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1492: ##sys#print */
t4=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[302];
av2[3]=C_SCHEME_FALSE;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* k12836 in k12830 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_12838(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_12838,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12841,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1492: ##sys#print */
t3=*((C_word*)lf[128]+1);{
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

/* k12839 in k12836 in k12830 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12841(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_12841,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12844,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1492: ##sys#print */
t3=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[301];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k12842 in k12839 in k12836 in k12830 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12844(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12844,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12847,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1492: chicken.base#get-output-string */
t3=*((C_word*)lf[129]+1);{
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

/* k12845 in k12842 in k12839 in k12836 in k12830 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12847(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_12847,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12851,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1493: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[11]+1);{
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

/* k12849 in k12845 in k12842 in k12839 in k12836 in k12830 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_12851(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12851,c,av);}
/* expand.scm:1491: ##sys#warn */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[290]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[290]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in ... */
static void C_ccall f_12857(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_12857,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_12860,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],tmp=(C_word)a,a+=11,tmp);
if(C_truep(t1)){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=t1;
f_12860(2,av2);}}
else{
t3=C_eqp(C_SCHEME_TRUE,C_u_i_car(((C_word*)t0)[2]));
if(C_truep(t3)){
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
f_12860(2,av2);}}
else{
t4=C_i_numberp(C_u_i_car(((C_word*)t0)[2]));
if(C_truep(t4)){
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
f_12860(2,av2);}}
else{
t5=C_charp(C_u_i_car(((C_word*)t0)[2]));
if(C_truep(t5)){
t6=t2;{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
f_12860(2,av2);}}
else{
t6=C_i_stringp(C_u_i_car(((C_word*)t0)[2]));
if(C_truep(t6)){
t7=t2;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
f_12860(2,av2);}}
else{
t7=C_eofp(C_u_i_car(((C_word*)t0)[2]));
if(C_truep(t7)){
t8=t2;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
f_12860(2,av2);}}
else{
t8=C_u_i_car(((C_word*)t0)[2]);
t9=C_bwpp(t8);
if(C_truep(t9)){
t10=t2;{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
f_12860(2,av2);}}
else{
t10=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13111,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[10],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1506: chicken.blob#blob? */
t11=*((C_word*)lf[305]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t11;
av2[1]=t10;
av2[2]=C_u_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t11+1)))(3,av2);}}}}}}}}}

/* k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_12860(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_12860,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12863,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12923,a[2]=((C_word*)t0)[7],a[3]=t2,a[4]=((C_word*)t0)[8],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1511: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_u_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
if(C_truep(C_i_nullp(C_u_i_cdr(((C_word*)t0)[2])))){
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_12940,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[9],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1521: expand */
t4=((C_word*)((C_word*)t0)[7])[1];
f_12805(t4,t3,((C_word*)t0)[8],C_SCHEME_FALSE);}
else{
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_12946,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[6],tmp=(C_word)a,a+=9,tmp);
t3=C_i_length(((C_word*)t0)[2]);
t4=C_eqp(t3,C_fix(3));
if(C_truep(t4)){
/* expand.scm:1523: c */
t5=((C_word*)t0)[4];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_i_cadr(((C_word*)t0)[2]);
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_12946(2,av2);}}}}}

/* k12861 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12863(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_12863,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12869,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
t3=C_i_length(((C_word*)t0)[2]);
t4=C_eqp(t3,C_fix(3));
if(C_truep(t4)){
/* expand.scm:1513: c */
t5=((C_word*)t0)[4];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
av2[3]=C_i_cadr(((C_word*)t0)[2]);
((C_proc)C_fast_retrieve_proc(t5))(4,av2);}}
else{
t5=t2;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_12869(2,av2);}}}

/* k12867 in k12861 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12869(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_12869,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=C_i_caddr(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t2=C_i_cdr(((C_word*)t0)[2]);
if(C_truep(C_i_pairp(t2))){
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,lf[103],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_12895,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1517: c */
t4=((C_word*)t0)[4];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=C_u_i_car(((C_word*)t0)[2]);
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}}}

/* k12893 in k12867 in k12861 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12895(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_12895,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_a_i_list(&a,1,lf[292]):C_u_i_car(((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12921 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12923(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_12923,c,av);}
/* expand.scm:1511: expand */
t2=((C_word*)((C_word*)t0)[2])[1];
f_12805(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* k12938 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_12940,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_12946(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_12946,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12949,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1524: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[296];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_12986,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t3=C_eqp(C_u_i_length(((C_word*)t0)[2]),C_fix(4));
if(C_truep(t3)){
/* expand.scm:1530: c */
t4=((C_word*)t0)[7];{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=((C_word*)t0)[8];
av2[3]=C_i_caddr(((C_word*)t0)[2]);
((C_proc)C_fast_retrieve_proc(t4))(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_12986(2,av2);}}}}

/* k12947 in k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12949(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(21,c,3)))){
C_save_and_reclaim((void *)f_12949,c,av);}
a=C_alloc(21);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,t1,t2);
t4=C_a_i_list(&a,1,t3);
t5=C_i_caddr(((C_word*)t0)[2]);
t6=C_a_i_list(&a,2,t5,t1);
t7=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12968,a[2]=t1,a[3]=t6,a[4]=((C_word*)t0)[3],a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1528: expand */
t8=((C_word*)((C_word*)t0)[4])[1];
f_12805(t8,t7,((C_word*)t0)[5],C_SCHEME_FALSE);}

/* k12966 in k12947 in k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12968(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,c,1)))){
C_save_and_reclaim((void *)f_12968,c,av);}
a=C_alloc(21);
t2=C_a_i_list(&a,4,lf[281],((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,3,lf[51],((C_word*)t0)[5],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k12984 in k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_12986(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_12986,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_12989,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1531: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[296];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
t2=C_i_car(((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_a_i_cons(&a,2,lf[103],t3);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13043,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1541: expand */
t6=((C_word*)((C_word*)t0)[4])[1];
f_12805(t6,t5,((C_word*)t0)[5],C_SCHEME_FALSE);}}

/* k12987 in k12984 in k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_12989(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(34,c,3)))){
C_save_and_reclaim((void *)f_12989,c,av);}
a=C_alloc(34);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,lf[75],C_SCHEME_END_OF_LIST,t2);
t4=C_i_cadr(((C_word*)t0)[2]);
t5=C_a_i_list(&a,3,lf[242],t4,t1);
t6=C_i_cadddr(((C_word*)t0)[2]);
t7=C_a_i_list(&a,3,lf[242],t6,t1);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13016,a[2]=t5,a[3]=t7,a[4]=t1,a[5]=((C_word*)t0)[3],a[6]=t3,tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1538: expand */
t9=((C_word*)((C_word*)t0)[4])[1];
f_12805(t9,t8,((C_word*)t0)[5],C_SCHEME_FALSE);}

/* k13014 in k12987 in k12984 in k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in ... */
static void C_ccall f_13016(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,1)))){
C_save_and_reclaim((void *)f_13016,c,av);}
a=C_alloc(30);
t2=C_a_i_list(&a,4,lf[303],((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=C_a_i_list(&a,3,lf[75],((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[94],((C_word*)t0)[6],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13041 in k12984 in k12944 in k12858 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in ... */
static void C_ccall f_13043(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,1)))){
C_save_and_reclaim((void *)f_13043,c,av);}
a=C_alloc(12);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,4,lf[281],((C_word*)t0)[3],((C_word*)t0)[4],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k13109 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in ... */
static void C_ccall f_13111(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_13111,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_12860(2,av2);}}
else{
t2=C_i_vectorp(C_u_i_car(((C_word*)t0)[3]));
if(C_truep(t2)){
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
f_12860(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13123,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1508: ##sys#srfi-4-vector? */
t4=*((C_word*)lf[304]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_u_i_car(((C_word*)t0)[3]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}}

/* k13121 in k13109 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in ... */
static void C_ccall f_13123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_13123,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_12860(2,av2);}}
else{
if(C_truep(C_i_pairp(C_u_i_car(((C_word*)t0)[3])))){
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13139,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1510: r */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[239];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
f_12860(2,av2);}}}}

/* k13137 in k13121 in k13109 in k12855 in k12817 in expand in k12798 in k12795 in k12792 in a12786 in k10633 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in ... */
static void C_ccall f_13139(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13139,c,av);}
/* expand.scm:1510: c */
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
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* k13171 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in ... */
static void C_ccall f_13173(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13173,c,av);}
/* expand.scm:1459: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[248];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13174 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in ... */
static void C_ccall f_13175(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_13175,c,av);}
a=C_alloc(6);
t5=C_i_cdr(t2);
if(C_truep(C_i_nullp(t5))){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_i_cdr(t5);
t7=C_u_i_car(t5);
if(C_truep(C_i_nullp(t6))){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13198,a[2]=t7,a[3]=t6,a[4]=t1,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1471: r */
t9=t3;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[296];
((C_proc)C_fast_retrieve_proc(t9))(3,av2);}}}}

/* k13196 in a13174 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in ... */
static void C_ccall f_13198(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_13198,c,av);}
a=C_alloc(15);
t2=C_a_i_list(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,1,t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13217,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1473: r */
t5=((C_word*)t0)[5];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[248];
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k13215 in k13196 in a13174 in k10630 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in ... */
static void C_ccall f_13217(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_13217,c,av);}
a=C_alloc(24);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_list(&a,4,lf[281],((C_word*)t0)[3],((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[51],((C_word*)t0)[5],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13223 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in ... */
static void C_ccall f_13225(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13225,c,av);}
/* expand.scm:1445: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[257];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13226 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in ... */
static void C_ccall f_13227(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_13227,c,av);}
a=C_alloc(5);
t5=C_i_cdr(t2);
if(C_truep(C_i_nullp(t5))){
t6=t1;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=C_i_cdr(t5);
t7=C_u_i_car(t5);
if(C_truep(C_i_nullp(t6))){
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t7;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13258,a[2]=t6,a[3]=t1,a[4]=t7,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1457: r */
t9=t3;{
C_word *av2=av;
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[257];
((C_proc)C_fast_retrieve_proc(t9))(3,av2);}}}}

/* k13256 in a13226 in k10627 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in ... */
static void C_ccall f_13258(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_13258,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,4,lf[281],((C_word*)t0)[4],t2,C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13260 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in ... */
static void C_ccall f_13262(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13262,c,av);}
/* expand.scm:1433: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[307];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13263 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in ... */
static void C_ccall f_13264(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13264,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13268,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1438: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[307];
av2[3]=t2;
av2[4]=lf[309];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13266 in a13263 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in ... */
static void C_ccall f_13268(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13268,c,av);}
a=C_alloc(13);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
if(C_truep(C_i_pairp(t2))){
t4=C_u_i_car(t2);
t5=C_a_i_list(&a,2,lf[308],t4);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13291,a[2]=((C_word*)t0)[3],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
t7=C_u_i_cdr(t2);
t8=C_a_i_list(&a,1,t3);
/* expand.scm:1442: ##sys#append */
t9=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t9;
av2[1]=t6;
av2[2]=t7;
av2[3]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(4,av2);}}
else{
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[96],t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k13289 in k13266 in a13263 in k10624 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in ... */
static void C_ccall f_13291(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13291,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k13304 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13306,c,av);}
/* expand.scm:1424: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[310];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13307 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13308(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13308,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13312,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1429: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[310];
av2[3]=t2;
av2[4]=lf[313];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13310 in a13307 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in ... */
static void C_ccall f_13312(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_13312,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13315,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1430: chicken.internal#check-for-multiple-bindings */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[311]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[311]+1);
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[312];
tp(5,av2);}}

/* k13313 in k13310 in a13307 in k10621 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in ... */
static void C_ccall f_13315(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13315,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[107],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13326 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13328(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13328,c,av);}
/* expand.scm:1415: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[314];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13329 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13330(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13330,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13334,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1420: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[314];
av2[3]=t2;
av2[4]=lf[317];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13332 in a13329 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13334(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_13334,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13337,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1421: chicken.internal#check-for-multiple-bindings */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[311]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[311]+1);
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[316];
tp(5,av2);}}

/* k13335 in k13332 in a13329 in k10618 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in ... */
static void C_ccall f_13337(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13337,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[315],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13348 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13350(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13350,c,av);}
/* expand.scm:1406: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[318];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13351 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13352(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13352,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13356,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1411: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[318];
av2[3]=t2;
av2[4]=lf[321];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13354 in a13351 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13356(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_13356,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13359,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1412: chicken.internal#check-for-multiple-bindings */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[311]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[311]+1);
av2[1]=t2;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
av2[3]=((C_word*)t0)[2];
av2[4]=lf[320];
tp(5,av2);}}

/* k13357 in k13354 in a13351 in k10615 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13359,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[319],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13370 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in ... */
static void C_ccall f_13372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13372,c,av);}
/* expand.scm:1393: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[56];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13373 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in ... */
static void C_ccall f_13374(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,4)))){
C_save_and_reclaim((void *)f_13374,c,av);}
a=C_alloc(8);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13378,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t6=C_i_cdr(t2);
t7=C_i_pairp(t6);
t8=(C_truep(t7)?C_i_symbolp(C_i_cadr(t2)):C_SCHEME_FALSE);
if(C_truep(t8)){
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13389,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1399: ##sys#check-syntax */
t10=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[56];
av2[3]=t2;
av2[4]=lf[323];
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}
else{
t9=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13399,a[2]=t5,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1402: ##sys#check-syntax */
t10=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=lf[56];
av2[3]=t2;
av2[4]=lf[325];
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}}

/* k13376 in a13373 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13378(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13378,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[51],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13387 in a13373 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13389(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13389,c,av);}
/* expand.scm:1400: chicken.internal#check-for-multiple-bindings */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[311]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[311]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_caddr(((C_word*)t0)[3]);
av2[3]=((C_word*)t0)[3];
av2[4]=lf[322];
tp(5,av2);}}

/* k13397 in a13373 in k10612 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13399(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13399,c,av);}
/* expand.scm:1403: chicken.internal#check-for-multiple-bindings */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[311]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[311]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=C_i_cadr(((C_word*)t0)[3]);
av2[3]=((C_word*)t0)[3];
av2[4]=lf[324];
tp(5,av2);}}

/* k13422 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in ... */
static void C_ccall f_13424(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13424,c,av);}
/* expand.scm:1379: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[116];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in ... */
static void C_ccall f_13426(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_13426,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13430,a[2]=t2,a[3]=t1,a[4]=t4,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1384: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[116];
av2[3]=t2;
av2[4]=lf[329];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13428 in a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in ... */
static void C_ccall f_13430(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_13430,c,av);}
a=C_alloc(12);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_i_caddr(((C_word*)t0)[2]);
t4=C_i_getprop(t2,lf[6],C_SCHEME_FALSE);
t5=(C_truep(t4)?t4:t2);
t6=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13447,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=t3,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13467,a[2]=t6,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1388: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[328]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[328]+1);
av2[1]=t7;
tp(2,av2);}}

/* k13445 in k13428 in a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13447(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_13447,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13450,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13456,a[2]=t2,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],tmp=(C_word)a,a+=7,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13463,a[2]=((C_word*)t0)[6],a[3]=t3,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1389: r */
t5=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[116];
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k13448 in k13445 in k13428 in a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13450(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_13450,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[326],((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k13454 in k13445 in k13428 in a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13456(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_13456,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
/* expand.scm:430: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[108];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,3,lf[326],((C_word*)t0)[5],((C_word*)t0)[6]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k13461 in k13445 in k13428 in a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13463(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13463,c,av);}
/* expand.scm:1389: c */
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
av2[3]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* k13465 in k13428 in a13425 in k10608 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13467,c,av);}
/* expand.scm:1388: ##sys#register-export */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[327]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[327]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k13469 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in ... */
static void C_ccall f_13471(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13471,c,av);}
/* expand.scm:1351: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[110];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in ... */
static void C_ccall f_13473(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_13473,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13477,a[2]=t2,a[3]=t4,a[4]=t3,a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1356: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[335];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in ... */
static void C_ccall f_13477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_13477,c,av);}
a=C_alloc(9);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13482,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t3,a[6]=((C_word)li167),tmp=(C_word)a,a+=7,tmp));
t5=((C_word*)t3)[1];
f_13482(t5,((C_word*)t0)[5],((C_word*)t0)[2]);}

/* loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in ... */
static void C_fcall f_13482(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_13482,3,t0,t1,t2);}
a=C_alloc(8);
t3=C_i_cadr(t2);
t4=C_u_i_cdr(t2);
t5=C_u_i_cdr(t4);
t6=C_i_pairp(t3);
if(C_truep(C_i_not(t6))){
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13497,a[2]=t3,a[3]=t5,a[4]=t1,a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:1361: ##sys#check-syntax */
t8=*((C_word*)lf[55]+1);{
C_word av2[5];
av2[0]=t8;
av2[1]=t7;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[332];
((C_proc)(void*)(*((C_word*)t8+1)))(5,av2);}}
else{
t7=C_i_car(t3);
if(C_truep(C_i_pairp(t7))){
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13553,a[2]=((C_word*)t0)[5],a[3]=t1,a[4]=t3,a[5]=t5,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1372: ##sys#check-syntax */
t9=*((C_word*)lf[55]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[333];
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}
else{
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13563,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=t5,a[5]=((C_word*)t0)[5],a[6]=t1,tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1375: ##sys#check-syntax */
t9=*((C_word*)lf[55]+1);{
C_word av2[5];
av2[0]=t9;
av2[1]=t8;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[334];
((C_proc)(void*)(*((C_word*)t9+1)))(5,av2);}}}}

/* k13495 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,2)))){
C_save_and_reclaim((void *)f_13497,c,av);}
a=C_alloc(12);
t2=C_i_getprop(((C_word*)t0)[2],lf[6],C_SCHEME_FALSE);
t3=(C_truep(t2)?t2:((C_word*)t0)[2]);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13508,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13544,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1363: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[328]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[328]+1);
av2[1]=t5;
tp(2,av2);}}

/* k13506 in k13495 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13508(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_13508,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13511,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13533,a[2]=t2,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13540,a[2]=((C_word*)t0)[6],a[3]=t3,a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1364: r */
t5=((C_word*)t0)[7];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=lf[110];
((C_proc)C_fast_retrieve_proc(t5))(3,av2);}}

/* k13509 in k13506 in k13495 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13511(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_13511,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,2,lf[330],((C_word*)t0)[2]);
if(C_truep(C_i_pairp(((C_word*)t0)[3]))){
t3=C_u_i_car(((C_word*)t0)[3]);
t4=C_a_i_list(&a,3,lf[96],((C_word*)t0)[2],t3);
t5=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_a_i_list(&a,3,lf[103],t2,t4);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=C_a_i_list(&a,3,lf[96],((C_word*)t0)[2],lf[331]);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[103],t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k13531 in k13506 in k13495 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13533(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13533,c,av);}
if(C_truep(t1)){
/* expand.scm:430: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[108];
av2[3]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_UNDEFINED;
f_13511(2,av2);}}}

/* k13538 in k13506 in k13495 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in ... */
static void C_ccall f_13540(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13540,c,av);}
/* expand.scm:1364: c */
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
av2[3]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t2))(4,av2);}}

/* k13542 in k13495 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13544(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_13544,c,av);}
/* expand.scm:1363: ##sys#register-export */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[327]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[327]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}

/* k13551 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13553(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_13553,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13560,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1373: chicken.syntax#expand-curried-define */
t3=*((C_word*)lf[112]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k13558 in k13551 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in ... */
static void C_ccall f_13560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_13560,c,av);}
/* expand.scm:1373: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_13482(t2,((C_word*)t0)[3],t1);}

/* k13561 in loop in k13475 in a13472 in k10604 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in ... */
static void C_ccall f_13563(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13563,c,av);}
a=C_alloc(15);
t2=C_i_car(((C_word*)t0)[2]);
t3=C_u_i_car(((C_word*)t0)[3]);
t4=C_u_i_cdr(((C_word*)t0)[3]);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[4]);
t6=C_a_i_cons(&a,2,lf[75],t5);
t7=C_a_i_list3(&a,3,t2,t3,t6);
/* expand.scm:1376: loop */
t8=((C_word*)((C_word*)t0)[5])[1];
f_13482(t8,((C_word*)t0)[6],t7);}

/* k13596 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in ... */
static void C_ccall f_13598(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13598,c,av);}
/* expand.scm:1342: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[336];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13599 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in ... */
static void C_ccall f_13600(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13600,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13604,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1347: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[336];
av2[3]=t2;
av2[4]=lf[337];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13602 in a13599 in k10601 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in ... */
static void C_ccall f_13604(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13604,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[103],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13613 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in ... */
static void C_ccall f_13615(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13615,c,av);}
/* expand.scm:1334: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[303];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13616 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in ... */
static void C_ccall f_13617(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13617,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13621,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1339: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[303];
av2[3]=t2;
av2[4]=lf[338];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13619 in a13616 in k10598 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in ... */
static void C_ccall f_13621(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13621,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[281],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13630 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13632,c,av);}
/* expand.scm:1326: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[239];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13633 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13634(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13634,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13638,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1331: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[239];
av2[3]=t2;
av2[4]=lf[339];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13636 in a13633 in k10595 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in ... */
static void C_ccall f_13638(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_13638,c,av);}
a=C_alloc(6);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_list(&a,2,lf[74],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13647 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13649(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13649,c,av);}
/* expand.scm:1318: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[250];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13650 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13651(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13651,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13655,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1323: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[250];
av2[3]=t2;
av2[4]=lf[340];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13653 in a13650 in k10592 in k10588 in k10584 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13655,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[75],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k13664 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13666(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13666,c,av);}
/* expand.scm:1304: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[341];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13667 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13668(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_13668,c,av);}
a=C_alloc(3);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13672,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1308: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[341];
av2[3]=t2;
av2[4]=lf[343];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13670 in a13667 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13672(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_13672,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13675,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1309: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[328]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[328]+1);
av2[1]=t2;
tp(2,av2);}}

/* k13673 in k13670 in a13667 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13675(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_13675,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13685,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1310: ##sys#module-name */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[342]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[342]+1);
av2[1]=t2;
av2[2]=t1;
tp(3,av2);}}
else{
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k13683 in k13673 in k13670 in a13667 in k10581 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13685(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_13685,c,av);}
a=C_alloc(6);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list(&a,2,lf[74],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k13687 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13689(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13689,c,av);}
/* expand.scm:1281: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[344];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13690 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13691(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13691,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13695,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1285: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[344];
av2[3]=t2;
av2[4]=lf[354];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13693 in a13690 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13695(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_13695,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13698,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1286: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[11]+1);{
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

/* k13696 in k13693 in a13690 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13698(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_13698,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13701,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(lf[348],t1);
if(C_truep(t3)){
/* expand.scm:1288: syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[351]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[351]+1);
av2[1]=t2;
av2[2]=lf[344];
av2[3]=lf[353];
tp(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_13701(2,av2);}}}

/* k13699 in k13696 in k13693 in a13690 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13701(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,2)))){
C_save_and_reclaim((void *)f_13701,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,2,lf[74],((C_word*)t0)[2]);
t3=C_a_i_list(&a,2,lf[74],lf[345]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13724,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1295: chicken.syntax#strip-syntax */
t5=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_i_caddr(((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k13722 in k13699 in k13696 in k13693 in a13690 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13724(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(35,c,4)))){
C_save_and_reclaim((void *)f_13724,c,av);}
a=C_alloc(35);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13727,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_eqp(lf[348],t1);
if(C_truep(t3)){
t4=C_a_i_list(&a,2,lf[74],lf[348]);
t5=C_a_i_list(&a,4,lf[346],((C_word*)t0)[2],((C_word*)t0)[3],t4);
t6=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_a_i_list(&a,2,lf[347],t5);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(t1))){
t4=C_a_i_list(&a,2,lf[349],t1);
t5=C_a_i_list(&a,2,lf[74],t4);
t6=C_a_i_list(&a,4,lf[346],((C_word*)t0)[2],((C_word*)t0)[3],t5);
t7=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_a_i_list(&a,2,lf[347],t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
if(C_truep(C_i_listp(t1))){
/* expand.scm:1299: ##sys#validate-exports */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[350]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[350]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=lf[344];
tp(4,av2);}}
else{
/* expand.scm:1301: syntax-error-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[351]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[351]+1);
av2[1]=t2;
av2[2]=lf[344];
av2[3]=lf[352];
av2[4]=C_i_caddr(((C_word*)t0)[5]);
tp(5,av2);}}}}}

/* k13725 in k13722 in k13699 in k13696 in k13693 in a13690 in k10578 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13727(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(24,c,1)))){
C_save_and_reclaim((void *)f_13727,c,av);}
a=C_alloc(24);
t2=C_a_i_list(&a,2,lf[74],t1);
t3=C_a_i_list(&a,4,lf[346],((C_word*)t0)[2],((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[347],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13771 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13773(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13773,c,av);}
/* expand.scm:1246: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[355];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13775(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_13775,c,av);}
a=C_alloc(4);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13779,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1250: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[355];
av2[3]=t2;
av2[4]=lf[364];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13779(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_13779,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_13782,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1251: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[11]+1);{
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

/* k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13782(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_13782,c,av);}
a=C_alloc(7);
t2=C_i_cadr(t1);
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=C_i_caddr(t1);
t6=C_u_i_cdr(t1);
t7=C_u_i_cdr(t6);
t8=C_u_i_cdr(t7);
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13940,a[2]=t3,a[3]=t4,a[4]=t8,a[5]=((C_word*)t0)[2],a[6]=t5,tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1259: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[363]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[363]+1);
av2[1]=t9;
av2[2]=t3;
tp(3,av2);}}

/* k13803 in k13831 in k13900 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13805(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(30,c,1)))){
C_save_and_reclaim((void *)f_13805,c,av);}
a=C_alloc(30);
t2=C_a_i_list(&a,3,lf[359],lf[360],lf[361]);
t3=C_a_i_list(&a,2,lf[362],((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,5,lf[105],t1,C_SCHEME_TRUE,t2,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k13831 in k13900 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13833(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(31,c,2)))){
C_save_and_reclaim((void *)f_13833,c,av);}
a=C_alloc(31);
t2=C_a_i_list(&a,2,lf[74],t1);
t3=C_a_i_list(&a,2,lf[74],((C_word*)t0)[2]);
t4=C_a_i_list(&a,5,lf[358],((C_word*)t0)[3],((C_word*)t0)[4],t2,t3);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13805,a[2]=t4,a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1274: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[363]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[363]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[6];
tp(3,av2);}}

/* g2689 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_13838(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_13838,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13845,a[2]=t1,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1263: ##sys#validate-exports */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[350]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[350]+1);
av2[1]=t4;
av2[2]=C_i_cadr(t2);
av2[3]=lf[355];
tp(4,av2);}}

/* k13843 in g2689 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13845(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_13845,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_13848,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_i_symbolp(((C_word*)t0)[3]);
t4=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_13857,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
if(C_truep(t3)){
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t3;
f_13857(2,av2);}}
else{
if(C_truep(C_i_listp(((C_word*)t0)[3]))){
t5=C_eqp(C_fix(2),C_u_i_length(((C_word*)t0)[3]));
if(C_truep(t5)){
t6=C_i_car(((C_word*)t0)[3]);
if(C_truep(C_i_symbolp(t6))){
/* expand.scm:1268: chicken.internal#valid-library-specifier? */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[357]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[357]+1);
av2[1]=t4;
av2[2]=C_i_cadr(((C_word*)t0)[3]);
tp(3,av2);}}
else{
t7=t4;{
C_word *av2=av;
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
f_13857(2,av2);}}}
else{
t6=t4;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_13857(2,av2);}}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
f_13857(2,av2);}}}}

/* k13846 in k13843 in g2689 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13848(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_13848,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k13855 in k13843 in g2689 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in ... */
static void C_ccall f_13857(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_13857,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
/* expand.scm:1269: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[5];
av2[2]=lf[356];
av2[3]=((C_word*)t0)[6];
av2[4]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}}

/* k13900 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13902(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_13902,c,av);}
a=C_alloc(13);
t2=C_a_i_list(&a,2,lf[74],t1);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13833,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1272: ##sys#validate-exports */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[350]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[350]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[6];
av2[3]=lf[355];
tp(4,av2);}}

/* map-loop2683 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_13904(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_13904,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_13929,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1261: g2689 */
t4=((C_word*)t0)[4];
f_13838(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k13927 in map-loop2683 in k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 in ... */
static void C_ccall f_13929(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_13929,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_13904(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k13938 in k13780 in k13777 in a13774 in k10575 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13940(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(31,c,3)))){
C_save_and_reclaim((void *)f_13940,c,av);}
a=C_alloc(31);
t2=C_a_i_list(&a,2,lf[74],t1);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13838,a[2]=((C_word*)t0)[2],a[3]=((C_word)li175),tmp=(C_word)a,a+=4,tmp);
t8=C_i_check_list_2(((C_word*)t0)[3],lf[16]);
t9=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13902,a[2]=((C_word*)t0)[4],a[3]=t2,a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_13904,a[2]=t5,a[3]=t11,a[4]=t7,a[5]=t6,a[6]=((C_word)li176),tmp=(C_word)a,a+=7,tmp));
t13=((C_word*)t11)[1];
f_13904(t13,t9,((C_word*)t0)[3]);}

/* k13942 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13944(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13944,c,av);}
/* expand.scm:1237: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[365];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13945 in k10572 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13946(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,9)))){
C_save_and_reclaim((void *)f_13946,c,av);}
t5=*((C_word*)lf[366]+1);
/* expand.scm:1240: g2666 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[366]+1));
C_word *av2;
if(c >= 10) {
  av2=av;
} else {
  av2=C_alloc(10);
}
av2[0]=*((C_word*)lf[366]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
av2[5]=*((C_word*)lf[3]+1);
av2[6]=*((C_word*)lf[17]+1);
av2[7]=C_SCHEME_FALSE;
av2[8]=C_SCHEME_TRUE;
av2[9]=lf[365];
tp(10,av2);}}

/* k13952 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_13954,c,av);}
/* expand.scm:1218: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[367];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_13956(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_13956,c,av);}
a=C_alloc(10);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14020,a[2]=t1,a[3]=t7,a[4]=t8,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1231: chicken.syntax#strip-syntax */
t10=*((C_word*)lf[11]+1);{
C_word *av2=av;
av2[0]=t10;
av2[1]=t9;
av2[2]=C_i_cdr(t2);
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}

/* k13966 in map-loop2624 in k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_13968(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_13968,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_i_cadr(((C_word*)t0)[2]);
t4=((C_word*)t0)[3];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,t2,t3);
f_14062(2,av2);}}
else{
/* expand.scm:1229: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
C_word av2[4];
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[370];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}}

/* k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14020(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_14020,c,av);}
a=C_alloc(11);
t2=C_i_check_list_2(t1,lf[16]);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14026,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14037,a[2]=((C_word*)t0)[3],a[3]=t5,a[4]=((C_word*)t0)[4],a[5]=((C_word)li179),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_14037(t7,t3,t1);}

/* k14024 in k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14026(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_14026,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14029,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1232: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[328]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[328]+1);
av2[1]=t2;
tp(2,av2);}}

/* k14027 in k14024 in k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14029(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_14029,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14032,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
/* expand.scm:1234: ##sys#add-to-export/rename-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[369]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[369]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[368];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k14030 in k14027 in k14024 in k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14032(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_14032,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[368];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2624 in k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14037(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_14037,3,t0,t1,t2);}
a=C_alloc(10);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14062,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=C_slot(t2,C_fix(0));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_13968,a[2]=t4,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_i_pairp(t4))){
if(C_truep(C_i_symbolp(C_u_i_car(t4)))){
if(C_truep(C_i_pairp(C_u_i_cdr(t4)))){
t6=C_i_cadr(t4);
if(C_truep(C_i_symbolp(t6))){
t7=C_u_i_cdr(t4);
t8=t5;
f_13968(t8,C_i_nullp(C_u_i_cdr(t7)));}
else{
t7=t5;
f_13968(t7,C_SCHEME_FALSE);}}
else{
t6=t5;
f_13968(t6,C_SCHEME_FALSE);}}
else{
t6=t5;
f_13968(t6,C_SCHEME_FALSE);}}
else{
t6=t5;
f_13968(t6,C_SCHEME_FALSE);}}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[4],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k14060 in map-loop2624 in k14018 in a13955 in k10569 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14062(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_14062,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_14037(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k14075 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14077(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14077,c,av);}
/* expand.scm:1208: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[371];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14078 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14079(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_14079,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14083,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14096,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1212: chicken.syntax#strip-syntax */
t7=*((C_word*)lf[11]+1);{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=C_i_cdr(t2);
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}

/* k14081 in a14078 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14083(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_14083,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14086,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1213: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[328]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[328]+1);
av2[1]=t2;
tp(2,av2);}}

/* k14084 in k14081 in a14078 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14086(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_14086,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14089,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
if(C_truep(t1)){
/* expand.scm:1215: ##sys#add-to-export-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[373]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[373]+1);
av2[1]=t2;
av2[2]=t1;
av2[3]=((C_word*)t0)[3];
tp(4,av2);}}
else{
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=lf[372];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k14087 in k14084 in k14081 in a14078 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14089(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_14089,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=lf[372];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k14094 in a14078 in k10566 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14096(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_14096,c,av);}
/* expand.scm:1212: ##sys#validate-exports */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[350]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[350]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[371];
tp(4,av2);}}

/* k14102 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14104(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14104,c,av);}
/* expand.scm:1148: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[374];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14106(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_14106,c,av);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14110,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1152: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[374];
av2[3]=t2;
av2[4]=lf[381];
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}

/* k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14110(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_14110,c,av);}
a=C_alloc(6);
t2=C_i_length(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14116,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[2],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1154: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[363]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[363]+1);
av2[1]=t3;
av2[2]=C_i_cadr(((C_word*)t0)[2]);
tp(3,av2);}}

/* k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14116(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,2)))){
C_save_and_reclaim((void *)f_14116,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14122,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(((C_word*)t0)[2],C_fix(4)))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14267,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1161: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_caddr(((C_word*)t0)[5]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=t2;
f_14122(t3,C_SCHEME_FALSE);}}

/* k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14122(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,2)))){
C_save_and_reclaim_args((void *)trf_14122,2,t0,t1);}
a=C_alloc(8);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14125,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1162: chicken.syntax#strip-syntax */
t3=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14194,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14253,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1195: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_caddr(((C_word*)t0)[6]);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14125(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_14125,c,av);}
a=C_alloc(13);
t2=C_i_cadddr(t1);
if(C_truep(C_fixnum_greaterp(((C_word*)t0)[2],C_fix(4)))){
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14137,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14171,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14175,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1181: scheme#symbol->string */
t6=*((C_word*)lf[45]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14178,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[3],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1187: ##sys#check-syntax */
t4=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[374];
av2[3]=t1;
av2[4]=lf[380];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}

/* k14135 in k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14137(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_14137,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14140,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1182: r */
t3=((C_word*)t0)[6];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[374];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k14138 in k14135 in k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14140(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(36,c,1)))){
C_save_and_reclaim((void *)f_14140,c,av);}
a=C_alloc(36);
t2=C_i_cddddr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[348],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[3],t3);
t5=C_a_i_cons(&a,2,t1,t4);
t6=C_a_i_list(&a,2,((C_word*)t0)[4],((C_word*)t0)[3]);
t7=C_a_i_list(&a,4,t1,((C_word*)t0)[5],lf[375],t6);
t8=((C_word*)t0)[6];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,3,lf[103],t5,t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}

/* k14169 in k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14171(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_14171,c,av);}
/* expand.scm:1178: scheme#string->symbol */
t2=*((C_word*)lf[376]+1);{
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

/* k14173 in k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14175(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_14175,c,av);}
/* expand.scm:1179: ##sys#string-append */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[377]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[377]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[378];
av2[3]=t1;
tp(4,av2);}}

/* k14176 in k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14178(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_14178,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14185,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1191: chicken.internal#library-id */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[363]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[363]+1);
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[4]);
tp(3,av2);}}

/* k14183 in k14176 in k14123 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14185,c,av);}
/* expand.scm:1189: ##sys#instantiate-functor */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[379]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[379]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
av2[4]=C_u_i_cdr(((C_word*)t0)[4]);
tp(5,av2);}}

/* k14192 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14194(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_14194,c,av);}
a=C_alloc(6);
t2=C_eqp(lf[348],t1);
t3=(C_truep(t2)?C_SCHEME_TRUE:t1);
t4=C_i_cdddr(((C_word*)t0)[2]);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14219,a[2]=t4,a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_pairp(t4))){
t6=C_i_nullp(C_u_i_cdr(t4));
t7=t5;
f_14219(t7,(C_truep(t6)?C_i_stringp(C_u_i_car(t4)):C_SCHEME_FALSE));}
else{
t6=t5;
f_14219(t6,C_SCHEME_FALSE);}}

/* k14217 in k14192 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14219(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(21,0,1)))){
C_save_and_reclaim_args((void *)trf_14219,2,t0,t1);}
a=C_alloc(21);
if(C_truep(t1)){
t2=C_i_car(((C_word*)t0)[2]);
t3=C_a_i_list(&a,3,lf[104],t2,*((C_word*)lf[2]+1));
t4=C_a_i_list(&a,1,t3);
t5=C_a_i_cons(&a,2,((C_word*)t0)[3],t4);
t6=C_a_i_cons(&a,2,((C_word*)t0)[4],t5);
t7=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t7;
av2[1]=C_a_i_cons(&a,2,lf[105],t6);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t2=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[4],t2);
t4=((C_word*)t0)[5];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,lf[105],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k14251 in k14120 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_14253,c,av);}
/* expand.scm:1195: ##sys#validate-exports */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[350]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[350]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[374];
tp(4,av2);}}

/* k14265 in k14114 in k14108 in a14105 in k10563 in k10559 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14267(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_14267,c,av);}
t2=((C_word*)t0)[2];
f_14122(t2,C_eqp(lf[375],t1));}

/* k14277 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14279(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14279,c,av);}
/* expand.scm:1091: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[382];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14281(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_14281,c,av);}
a=C_alloc(22);
t5=C_i_cdr(t2);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14287,a[2]=t5,a[3]=((C_word)li183),tmp=(C_word)a,a+=4,tmp));
t11=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14297,a[2]=t7,a[3]=t9,a[4]=((C_word)li184),tmp=(C_word)a,a+=5,tmp));
t12=C_SCHEME_UNDEFINED;
t13=(*a=C_VECTOR_TYPE|1,a[1]=t12,tmp=(C_word)a,a+=2,tmp);
t14=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14442,a[2]=t5,a[3]=t7,a[4]=t13,a[5]=t9,a[6]=((C_word)li186),tmp=(C_word)a,a+=7,tmp));
t15=((C_word*)t13)[1];
f_14442(t15,t1,t5);}

/* err in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14287(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,4)))){
C_save_and_reclaim_args((void *)trf_14287,3,t0,t1,t2);}
a=C_alloc(3);
t3=C_a_i_cons(&a,2,lf[382],((C_word*)t0)[2]);
/* expand.scm:1098: ##sys#error */
t4=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t4;
av2[1]=t1;
av2[2]=lf[383];
av2[3]=t2;
av2[4]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}

/* test in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14297(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,2)))){
C_save_and_reclaim_args((void *)trf_14297,3,t0,t1,t2);}
a=C_alloc(7);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14311,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1102: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t3=C_i_pairp(t2);
if(C_truep(C_i_not(t3))){
/* expand.scm:1103: err */
t4=((C_word*)((C_word*)t0)[2])[1];
f_14287(t4,t1,t2);}
else{
t4=C_i_car(t2);
t5=C_u_i_cdr(t2);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14327,a[2]=t5,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[2],a[6]=t2,tmp=(C_word)a,a+=7,tmp);
/* expand.scm:1107: chicken.syntax#strip-syntax */
t7=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t7;
av2[1]=t6;
av2[2]=t4;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}}

/* k14309 in test in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14311(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_14311,c,av);}
/* expand.scm:1102: chicken.platform#feature? */
t2=*((C_word*)lf[384]+1);{
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

/* k14325 in test in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14327(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_14327,c,av);}
a=C_alloc(5);
t2=C_eqp(t1,lf[257]);
if(C_truep(t2)){
t3=C_eqp(((C_word*)t0)[2],C_SCHEME_END_OF_LIST);
if(C_truep(t3)){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14351,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1111: test */
t5=((C_word*)((C_word*)t0)[4])[1];
f_14297(t5,t4,C_u_i_car(((C_word*)t0)[2]));}
else{
/* expand.scm:1113: err */
t4=((C_word*)((C_word*)t0)[5])[1];
f_14287(t4,((C_word*)t0)[3],((C_word*)t0)[6]);}}}
else{
t3=C_eqp(t1,lf[248]);
if(C_truep(t3)){
t4=C_eqp(((C_word*)t0)[2],C_SCHEME_END_OF_LIST);
if(C_truep(C_i_not(t4))){
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14386,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:1117: test */
t6=((C_word*)((C_word*)t0)[4])[1];
f_14297(t6,t5,C_u_i_car(((C_word*)t0)[2]));}
else{
/* expand.scm:1119: err */
t5=((C_word*)((C_word*)t0)[5])[1];
f_14287(t5,((C_word*)t0)[3],((C_word*)t0)[6]);}}
else{
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t4=C_eqp(t1,lf[385]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14420,a[2]=((C_word*)t0)[3],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1120: test */
t6=((C_word*)((C_word*)t0)[4])[1];
f_14297(t6,t5,C_i_cadr(((C_word*)t0)[6]));}
else{
/* expand.scm:1121: err */
t5=((C_word*)((C_word*)t0)[5])[1];
f_14287(t5,((C_word*)t0)[3],((C_word*)t0)[6]);}}}}

/* k14349 in k14325 in test in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14351(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_14351,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[257],t2);
/* expand.scm:1112: test */
t4=((C_word*)((C_word*)t0)[3])[1];
f_14297(t4,((C_word*)t0)[4],t3);}
else{
t2=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k14384 in k14325 in test in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_14386,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=C_u_i_cdr(((C_word*)t0)[3]);
t3=C_a_i_cons(&a,2,lf[248],t2);
/* expand.scm:1118: test */
t4=((C_word*)((C_word*)t0)[4])[1];
f_14297(t4,((C_word*)t0)[2],t3);}}

/* k14418 in k14325 in test in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14420(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_14420,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_i_not(t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* expand in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14442(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_14442,3,t0,t1,t2);}
a=C_alloc(16);
t3=C_eqp(t2,C_SCHEME_END_OF_LIST);
if(C_truep(t3)){
t4=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t5=t4;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=((C_word*)t6)[1];
t8=C_i_check_list_2(((C_word*)t0)[2],lf[16]);
t9=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14467,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14469,a[2]=t6,a[3]=t11,a[4]=t7,a[5]=((C_word)li185),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_14469(t13,t9,((C_word*)t0)[2]);}
else{
t4=C_i_pairp(t2);
if(C_truep(C_i_not(t4))){
/* expand.scm:1127: err */
t5=((C_word*)((C_word*)t0)[3])[1];
f_14287(t5,t1,t2);}
else{
t5=C_i_car(t2);
t6=C_u_i_cdr(t2);
t7=C_i_pairp(t5);
if(C_truep(C_i_not(t7))){
/* expand.scm:1132: err */
t8=((C_word*)((C_word*)t0)[3])[1];
f_14287(t8,t1,t5);}
else{
t8=C_i_car(t5);
t9=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_14560,a[2]=t5,a[3]=t1,a[4]=((C_word*)t0)[4],a[5]=t6,a[6]=((C_word*)t0)[5],a[7]=t8,tmp=(C_word)a,a+=8,tmp);
/* expand.scm:1134: chicken.syntax#strip-syntax */
t10=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}}}}

/* k14465 in expand in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14467(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14467,c,av);}{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[27]+1);
av2[3]=lf[386];
av2[4]=t1;
C_apply(5,av2);}}

/* map-loop2535 in expand in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14469(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_14469,3,t0,t1,t2);}
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

/* k14546 in k14558 in expand in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14548(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_14548,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[103],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* expand.scm:1140: expand */
t2=((C_word*)((C_word*)t0)[4])[1];
f_14442(t2,((C_word*)t0)[3],((C_word*)t0)[5]);}}

/* k14558 in expand in a14280 in k10556 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14560(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_14560,c,av);}
a=C_alloc(6);
t2=C_eqp(t1,lf[254]);
if(C_truep(t2)){
t3=C_u_i_cdr(((C_word*)t0)[2]);
t4=C_eqp(t3,C_SCHEME_END_OF_LIST);
t5=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t5;
av2[1]=(C_truep(t4)?lf[387]:C_a_i_cons(&a,2,lf[103],t3));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14548,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1139: test */
t4=((C_word*)((C_word*)t0)[6])[1];
f_14297(t4,t3,((C_word*)t0)[7]);}}

/* k14570 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14572,c,av);}
/* expand.scm:1083: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[388];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14573 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14574(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_14574,c,av);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14578,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14599,a[2]=t2,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1087: r */
t7=t3;{
C_word *av2=av;
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[359];
((C_proc)C_fast_retrieve_proc(t7))(3,av2);}}

/* k14576 in a14573 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14578(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_14578,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14589,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1088: r */
t3=((C_word*)t0)[4];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[359];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k14587 in k14576 in a14573 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14589(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_14589,c,av);}
a=C_alloc(9);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,2,lf[347],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k14597 in a14573 in k10553 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14599(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_14599,c,av);}
a=C_alloc(3);
t2=C_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
/* expand.scm:1087: ##sys#register-meta-expression */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[389]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[389]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=t3;
tp(3,av2);}}

/* k14605 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14607(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14607,c,av);}
/* expand.scm:1061: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[359];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14609(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(22,c,3)))){
C_save_and_reclaim((void *)f_14609,c,av);}
a=C_alloc(22);
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14618,a[2]=t3,a[3]=t4,a[4]=((C_word)li191),tmp=(C_word)a,a+=5,tmp);
t10=C_i_cdr(t2);
t11=C_i_check_list_2(t10,lf[16]);
t12=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14680,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_14682,a[2]=t7,a[3]=t14,a[4]=t9,a[5]=t8,a[6]=((C_word)li192),tmp=(C_word)a,a+=7,tmp));
t16=((C_word*)t14)[1];
f_14682(t16,t12,t10);}

/* g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14618(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,8)))){
C_save_and_reclaim_args((void *)trf_14618,3,t0,t1,t2);}
a=C_alloc(9);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14624,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li189),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14630,a[2]=((C_word)li190),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1067: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a14623 in g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14624(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_14624,c,av);}
/* expand.scm:1067: ##sys#decompose-import */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[390]+1));
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[390]+1);
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
av2[5]=lf[359];
tp(6,av2);}}

/* a14629 in g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14630(C_word c,C_word *av){
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
if(c!=8) C_bad_argc_2(c,8,t0);
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_14630,c,av);}
a=C_alloc(9);
t8=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_14634,a[2]=t3,a[3]=t1,a[4]=t2,a[5]=t4,a[6]=t5,a[7]=t6,a[8]=t7,tmp=(C_word)a,a+=9,tmp);
/* expand.scm:1068: ##sys#current-module */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[328]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[328]+1);
av2[1]=t8;
tp(2,av2);}}

/* k14632 in a14629 in g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14634(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,2)))){
C_save_and_reclaim((void *)f_14634,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_14637,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_14671,a[2]=((C_word*)t0)[4],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:1069: ##sys#module-name */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[342]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[342]+1);
av2[1]=t3;
av2[2]=t1;
tp(3,av2);}}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_14637(2,av2);}}}

/* k14635 in k14632 in a14629 in g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14637(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,10)))){
C_save_and_reclaim((void *)f_14637,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_14640,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_not(((C_word*)t0)[5]))){
/* expand.scm:1073: ##sys#syntax-error-hook */
t3=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[359];
av2[3]=lf[393];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
/* expand.scm:1075: ##sys#import */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[394]+1));
C_word *av2;
if(c >= 11) {
  av2=av;
} else {
  av2=C_alloc(11);
}
av2[0]=*((C_word*)lf[394]+1);
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=((C_word*)t0)[7];
av2[5]=((C_word*)t0)[8];
av2[6]=*((C_word*)lf[3]+1);
av2[7]=*((C_word*)lf[17]+1);
av2[8]=C_SCHEME_FALSE;
av2[9]=C_SCHEME_FALSE;
av2[10]=lf[359];
tp(11,av2);}}}

/* k14638 in k14635 in k14632 in a14629 in g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14640(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_14640,c,av);}
a=C_alloc(9);
t2=C_i_not(((C_word*)t0)[2]);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?lf[391]:C_a_i_list(&a,3,lf[392],((C_word*)t0)[2],((C_word*)t0)[4]));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k14669 in k14632 in a14629 in g2430 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14671(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14671,c,av);}
t2=C_eqp(((C_word*)t0)[2],t1);
if(C_truep(t2)){
/* expand.scm:1070: ##sys#syntax-error-hook */
t3=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=lf[359];
av2[3]=lf[395];
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}
else{
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_UNDEFINED;
f_14637(2,av2);}}}

/* k14678 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14680(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_14680,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[103],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* map-loop2424 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_14682(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_14682,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_14707,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:1066: g2430 */
t4=((C_word*)t0)[4];
f_14618(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k14705 in map-loop2424 in a14608 in k10549 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14707(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_14707,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_14682(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k14716 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14718(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14718,c,av);}
/* expand.scm:1053: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[396];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14719 in k10546 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14720(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,9)))){
C_save_and_reclaim((void *)f_14720,c,av);}
t5=*((C_word*)lf[366]+1);
/* expand.scm:1056: g2414 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[366]+1));
C_word *av2;
if(c >= 10) {
  av2=av;
} else {
  av2=C_alloc(10);
}
av2[0]=*((C_word*)lf[366]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
av2[5]=*((C_word*)lf[4]+1);
av2[6]=*((C_word*)lf[210]+1);
av2[7]=C_SCHEME_TRUE;
av2[8]=C_SCHEME_FALSE;
av2[9]=lf[396];
tp(10,av2);}}

/* k14726 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14728(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_14728,c,av);}
/* expand.scm:1046: ##sys#extend-macro-environment */
t2=*((C_word*)lf[29]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[397];
av2[3]=C_SCHEME_END_OF_LIST;
av2[4]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a14729 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_14730(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(0,c,9)))){
C_save_and_reclaim((void *)f_14730,c,av);}
t5=*((C_word*)lf[366]+1);
/* expand.scm:1049: g2400 */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[366]+1));
C_word *av2;
if(c >= 10) {
  av2=av;
} else {
  av2=C_alloc(10);
}
av2[0]=*((C_word*)lf[366]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
av2[4]=t4;
av2[5]=*((C_word*)lf[3]+1);
av2[6]=*((C_word*)lf[17]+1);
av2[7]=C_SCHEME_FALSE;
av2[8]=C_SCHEME_FALSE;
av2[9]=lf[397];
tp(10,av2);}}

/* k4497 */
static void C_ccall f_4499(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(19,c,2)))){
C_save_and_reclaim((void *)f_4499,c,av);}
a=C_alloc(19);
t2=C_a_i_provide(&a,1,lf[0]);
t3=C_a_i_provide(&a,1,lf[1]);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4502,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t4;
C_library_toplevel(2,av2);}}

/* k4500 in k4497 */
static void C_ccall f_4502(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4502,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4505,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_data_2dstructures_toplevel(2,av2);}}

/* k4503 in k4500 in k4497 */
static void C_ccall f_4505(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_4505,c,av);}
a=C_alloc(3);
t2=C_set_block_item(lf[2] /* ##sys#current-source-filename */,0,C_SCHEME_FALSE);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5788,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:88: chicken.base#make-parameter */
t4=*((C_word*)lf[216]+1);{
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

/* k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5788(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_5788,c,av);}
a=C_alloc(3);
t2=C_mutate((C_word*)lf[3]+1 /* (set! ##sys#current-environment ...) */,t1);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5792,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:89: chicken.base#make-parameter */
t4=*((C_word*)lf[216]+1);{
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

/* k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5792(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,4)))){
C_save_and_reclaim((void *)f_5792,c,av);}
a=C_alloc(15);
t2=C_mutate((C_word*)lf[4]+1 /* (set! ##sys#current-meta-environment ...) */,t1);
t3=C_mutate(&lf[5] /* (set! chicken.syntax#lookup ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5794,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t4=C_mutate(&lf[7] /* (set! chicken.syntax#macro-alias ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5811,a[2]=((C_word)li1),tmp=(C_word)a,a+=3,tmp));
t5=C_mutate((C_word*)lf[11]+1 /* (set! chicken.syntax#strip-syntax ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_5858,a[2]=((C_word)li4),tmp=(C_word)a,a+=3,tmp));
t6=C_mutate((C_word*)lf[13]+1 /* (set! ##sys#extend-se ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6000,a[2]=((C_word)li8),tmp=(C_word)a,a+=3,tmp));
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6182,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:147: chicken.base#make-parameter */
t8=*((C_word*)lf[216]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* chicken.syntax#lookup in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_5794(C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_stack_overflow_check;{}
t3=C_u_i_assq(t1,t2);
if(C_truep(t3)){
return(C_i_cdr(t3));}
else{
t4=C_i_getprop(t1,lf[6],C_SCHEME_FALSE);
return((C_truep(t4)?t4:C_SCHEME_FALSE));}}

/* chicken.syntax#macro-alias in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_5811(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_5811,3,t1,t2,t3);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5818,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:97: chicken.keyword#keyword? */
t5=*((C_word*)lf[10]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}

/* k5816 in chicken.syntax#macro-alias in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5818(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_5818,c,av);}
a=C_alloc(5);
t2=(C_truep(t1)?t1:C_u_i_namespaced_symbolp(((C_word*)t0)[2]));
if(C_truep(t2)){
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5824,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:99: chicken.base#gensym */
t4=*((C_word*)lf[9]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k5822 in k5816 in chicken.syntax#macro-alias in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5824(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,1)))){
C_save_and_reclaim((void *)f_5824,c,av);}
a=C_alloc(16);
t2=(
/* expand.scm:100: lookup */
  f_5794(((C_word*)t0)[2],((C_word*)t0)[3])
);
t3=(C_truep(t2)?t2:((C_word*)t0)[2]);
t4=C_i_getprop(((C_word*)t0)[2],lf[8],C_SCHEME_FALSE);
if(C_truep(t4)){
t5=C_a_i_putprop(&a,3,t1,lf[6],t3);
t6=C_a_i_putprop(&a,3,t1,lf[8],t4);
t7=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
t5=C_a_i_putprop(&a,3,t1,lf[6],t3);
t6=C_a_i_putprop(&a,3,t1,lf[8],((C_word*)t0)[2]);
t7=((C_word*)t0)[4];{
C_word *av2=av;
av2[0]=t7;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5858(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_5858,c,av);}
a=C_alloc(9);
t3=C_SCHEME_END_OF_LIST;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_5864,a[2]=t4,a[3]=t6,a[4]=((C_word)li3),tmp=(C_word)a,a+=5,tmp));
t8=((C_word*)t6)[1];
f_5864(t8,t1,t2);}

/* walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_5864(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5864,3,t0,t1,t2);}
a=C_alloc(6);
t3=C_i_assq(t2,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(t3)){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_i_cdr(t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5880,a[2]=t1,a[3]=t2,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:114: chicken.keyword#keyword? */
t5=*((C_word*)lf[10]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}}

/* k5878 in walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5880(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_5880,c,av);}
a=C_alloc(15);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
t2=C_i_getprop(((C_word*)t0)[3],lf[6],C_SCHEME_FALSE);
t3=C_i_getprop(((C_word*)t0)[3],lf[8],C_SCHEME_FALSE);
if(C_truep(t3)){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
if(C_truep(C_i_not(t2))){
t4=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_pairp(t2);
t5=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t5;
av2[1]=(C_truep(t4)?((C_word*)t0)[3]:t2);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}
else{
if(C_truep(C_i_pairp(((C_word*)t0)[3]))){
t2=C_a_i_cons(&a,2,C_SCHEME_FALSE,C_SCHEME_FALSE);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=C_a_i_cons(&a,2,t3,((C_word*)((C_word*)t0)[4])[1]);
t5=C_mutate(((C_word *)((C_word*)t0)[4])+1,t4);
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5942,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:124: walk */
t7=((C_word*)((C_word*)t0)[5])[1];
f_5864(t7,t6,C_u_i_car(((C_word*)t0)[3]));}
else{
if(C_truep(C_i_vectorp(((C_word*)t0)[3]))){
t2=C_block_size(((C_word*)t0)[3]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_5960,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[2],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:129: scheme#make-vector */
t4=*((C_word*)lf[12]+1);{
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
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}}}}

/* k5933 in k5940 in k5878 in walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5935(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_5935,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],C_fix(1),t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k5940 in k5878 in walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5942(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_5942,c,av);}
a=C_alloc(4);
t2=C_i_setslot(((C_word*)t0)[2],C_fix(0),t1);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_5935,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:125: walk */
t4=((C_word*)((C_word*)t0)[4])[1];
f_5864(t4,t3,C_u_i_cdr(((C_word*)t0)[5]));}

/* k5958 in k5878 in walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5960(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,3)))){
C_save_and_reclaim((void *)f_5960,c,av);}
a=C_alloc(16);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,t2,((C_word*)((C_word*)t0)[3])[1]);
t4=C_mutate(((C_word *)((C_word*)t0)[3])+1,t3);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_5969,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t6,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[2],a[7]=((C_word)li2),tmp=(C_word)a,a+=8,tmp));
t8=((C_word*)t6)[1];
f_5969(t8,((C_word*)t0)[6],C_fix(0));}

/* doloop884 in k5958 in k5878 in walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_5969(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_5969,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_fixnum_greater_or_equal_p(t2,((C_word*)t0)[2]))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_5990,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:133: walk */
t4=((C_word*)((C_word*)t0)[5])[1];
f_5864(t4,t3,C_slot(((C_word*)t0)[6],t2));}}

/* k5988 in doloop884 in k5958 in k5878 in walk in chicken.syntax#strip-syntax in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_5990(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_5990,c,av);}
t2=C_i_setslot(((C_word*)t0)[2],((C_word*)t0)[3],t1);
t3=((C_word*)((C_word*)t0)[4])[1];
f_5969(t3,((C_word*)t0)[5],C_fixnum_plus(((C_word*)t0)[3],C_fix(1)));}

/* ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6000(C_word c,C_word *av){
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
if(c<4) C_bad_min_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_6000,c,av);}
a=C_alloc(18);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6004,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_rest_nullp(c,4))){
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=C_i_check_list_2(t3,lf[16]);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6143,a[2]=t7,a[3]=t11,a[4]=t8,a[5]=((C_word)li7),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_6143(t13,t4,t3);}
else{
t5=t4;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_get_rest_arg(c,4,av,4,t0);
f_6004(2,av2);}}}

/* k6002 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6004(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6004,c,av);}
a=C_alloc(12);
t2=C_i_check_list_2(t1,lf[14]);
t3=C_i_check_list_2(((C_word*)t0)[2],lf[14]);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6029,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6094,a[2]=t6,a[3]=((C_word)li6),tmp=(C_word)a,a+=4,tmp));
t8=((C_word*)t6)[1];
f_6094(t8,t4,t1,((C_word*)t0)[2]);}

/* k6027 in k6002 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6029(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,4)))){
C_save_and_reclaim((void *)f_6029,c,av);}
a=C_alloc(17);
t2=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t3=t2;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=((C_word*)t4)[1];
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6044,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6046,a[2]=t4,a[3]=t8,a[4]=t5,a[5]=((C_word)li5),tmp=(C_word)a,a+=6,tmp));
t10=((C_word*)t8)[1];
f_6046(t10,t6,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k6042 in k6027 in k6002 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6044(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6044,c,av);}
/* expand.scm:142: scheme#append */
t2=*((C_word*)lf[15]+1);{
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

/* map-loop969 in k6027 in k6002 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6046(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_save_and_reclaim_args((void *)trf_6046,4,t0,t1,t2,t3);}
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

/* for-each-loop932 in k6002 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6094(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,0,3)))){
C_save_and_reclaim_args((void *)trf_6094,4,t0,t1,t2,t3);}
a=C_alloc(8);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_i_getprop(t7,lf[8],C_SCHEME_FALSE);
t9=(C_truep(t8)?C_a_i_putprop(&a,3,t6,lf[8],t8):C_a_i_putprop(&a,3,t6,lf[8],t7));
t11=t1;
t12=C_slot(t2,C_fix(1));
t13=C_slot(t3,C_fix(1));
t1=t11;
t2=t12;
t3=t13;
goto loop;}
else{
t6=C_SCHEME_UNDEFINED;
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* map-loop906 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6143(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6143,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6168,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:136: g912 */
t4=*((C_word*)lf[9]+1);{
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

/* k6166 in map-loop906 in ##sys#extend-se in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6168(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6168,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_6143(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6182(C_word c,C_word *av){
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
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(87,c,6)))){
C_save_and_reclaim((void *)f_6182,c,av);}
a=C_alloc(87);
t2=C_mutate((C_word*)lf[17]+1 /* (set! ##sys#macro-environment ...) */,t1);
t3=C_set_block_item(lf[18] /* ##sys#scheme-macro-environment */,0,C_SCHEME_END_OF_LIST);
t4=C_set_block_item(lf[19] /* ##sys#chicken-ffi-macro-environment */,0,C_SCHEME_END_OF_LIST);
t5=C_set_block_item(lf[20] /* ##sys#chicken.condition-macro-environment */,0,C_SCHEME_END_OF_LIST);
t6=C_set_block_item(lf[21] /* ##sys#chicken.time-macro-environment */,0,C_SCHEME_END_OF_LIST);
t7=C_set_block_item(lf[22] /* ##sys#chicken.type-macro-environment */,0,C_SCHEME_END_OF_LIST);
t8=C_set_block_item(lf[23] /* ##sys#chicken.syntax-macro-environment */,0,C_SCHEME_END_OF_LIST);
t9=C_set_block_item(lf[24] /* ##sys#chicken.base-macro-environment */,0,C_SCHEME_END_OF_LIST);
t10=C_mutate((C_word*)lf[25]+1 /* (set! ##sys#ensure-transformer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6191,a[2]=((C_word)li9),tmp=(C_word)a,a+=3,tmp));
t11=C_mutate((C_word*)lf[29]+1 /* (set! ##sys#extend-macro-environment ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6215,a[2]=((C_word)li11),tmp=(C_word)a,a+=3,tmp));
t12=C_mutate((C_word*)lf[30]+1 /* (set! ##sys#macro? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6257,a[2]=((C_word)li12),tmp=(C_word)a,a+=3,tmp));
t13=C_mutate((C_word*)lf[31]+1 /* (set! ##sys#undefine-macro! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6294,a[2]=((C_word)li14),tmp=(C_word)a,a+=3,tmp));
t14=C_mutate((C_word*)lf[32]+1 /* (set! ##sys#expand-0 ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6339,a[2]=((C_word)li33),tmp=(C_word)a,a+=3,tmp));
t15=C_set_block_item(lf[59] /* ##sys#compiler-syntax-hook */,0,C_SCHEME_FALSE);
t16=C_set_block_item(lf[64] /* ##sys#enable-runtime-macros */,0,C_SCHEME_FALSE);
t17=C_mutate((C_word*)lf[41]+1 /* (set! chicken.syntax#expansion-result-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6856,a[2]=((C_word)li34),tmp=(C_word)a,a+=3,tmp));
t18=C_mutate((C_word*)lf[65]+1 /* (set! chicken.syntax#expand ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6859,a[2]=((C_word)li38),tmp=(C_word)a,a+=3,tmp));
t19=C_mutate((C_word*)lf[66]+1 /* (set! ##sys#extended-lambda-list? ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6925,a[2]=((C_word)li40),tmp=(C_word)a,a+=3,tmp));
t20=C_mutate((C_word*)lf[70]+1 /* (set! ##sys#expand-extended-lambda-list ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6972,a[2]=((C_word)li45),tmp=(C_word)a,a+=3,tmp));
t21=C_mutate((C_word*)lf[93]+1 /* (set! ##sys#expand-multiple-values-assignment ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7581,a[2]=((C_word)li49),tmp=(C_word)a,a+=3,tmp));
t22=C_set_block_item(lf[98] /* chicken.syntax#define-definition */,0,C_SCHEME_UNDEFINED);
t23=C_set_block_item(lf[99] /* chicken.syntax#define-syntax-definition */,0,C_SCHEME_UNDEFINED);
t24=C_set_block_item(lf[100] /* chicken.syntax#define-values-definition */,0,C_SCHEME_UNDEFINED);
t25=lf[101] /* chicken.syntax#import-definition */ =C_SCHEME_UNDEFINED;;
t26=C_mutate((C_word*)lf[102]+1 /* (set! ##sys#canonicalize-body ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7761,a[2]=((C_word)li67),tmp=(C_word)a,a+=3,tmp));
t27=C_mutate((C_word*)lf[120]+1 /* (set! chicken.syntax#match-expression ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8825,a[2]=((C_word)li70),tmp=(C_word)a,a+=3,tmp));
t28=C_mutate((C_word*)lf[112]+1 /* (set! chicken.syntax#expand-curried-define ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8907,a[2]=((C_word)li72),tmp=(C_word)a,a+=3,tmp));
t29=C_set_block_item(lf[121] /* ##sys#line-number-database */,0,C_SCHEME_FALSE);
t30=C_set_block_item(lf[122] /* ##sys#syntax-error-culprit */,0,C_SCHEME_FALSE);
t31=C_set_block_item(lf[123] /* ##sys#syntax-context */,0,C_SCHEME_END_OF_LIST);
t32=C_mutate((C_word*)lf[124]+1 /* (set! chicken.syntax#syntax-error ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8962,a[2]=((C_word)li73),tmp=(C_word)a,a+=3,tmp));
t33=C_mutate((C_word*)lf[42]+1 /* (set! ##sys#syntax-error-hook ...) */,*((C_word*)lf[124]+1));
t34=C_mutate((C_word*)lf[127]+1 /* (set! ##sys#syntax-error/context ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8973,a[2]=((C_word)li78),tmp=(C_word)a,a+=3,tmp));
t35=C_mutate(&lf[145] /* (set! chicken.syntax#assq/drop-bwp! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9200,a[2]=((C_word)li80),tmp=(C_word)a,a+=3,tmp));
t36=C_mutate(&lf[146] /* (set! chicken.syntax#read-with-source-info-hook ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9250,a[2]=((C_word)li81),tmp=(C_word)a,a+=3,tmp));
t37=C_mutate((C_word*)lf[153]+1 /* (set! chicken.syntax#read-with-source-info ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9301,a[2]=((C_word)li82),tmp=(C_word)a,a+=3,tmp));
t38=C_mutate((C_word*)lf[157]+1 /* (set! chicken.syntax#get-line-number ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9326,a[2]=((C_word)li84),tmp=(C_word)a,a+=3,tmp));
t39=C_mutate((C_word*)lf[158]+1 /* (set! ##sys#get-line-2 ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9365,a[2]=((C_word)li86),tmp=(C_word)a,a+=3,tmp));
t40=C_mutate((C_word*)lf[159]+1 /* (set! ##sys#display-line-number-database ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9406,a[2]=((C_word)li89),tmp=(C_word)a,a+=3,tmp));
t41=C_mutate((C_word*)lf[164]+1 /* (set! ##sys#update-line-number-database! ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9474,a[2]=((C_word)li93),tmp=(C_word)a,a+=3,tmp));
t42=C_mutate((C_word*)lf[55]+1 /* (set! ##sys#check-syntax ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9556,a[2]=((C_word)li104),tmp=(C_word)a,a+=3,tmp));
t43=C_mutate(&lf[196] /* (set! chicken.syntax#make-er/ir-transformer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10000,a[2]=((C_word)li114),tmp=(C_word)a,a+=3,tmp));
t44=C_mutate((C_word*)lf[200]+1 /* (set! chicken.syntax#er-macro-transformer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10529,a[2]=((C_word)li115),tmp=(C_word)a,a+=3,tmp));
t45=C_mutate((C_word*)lf[201]+1 /* (set! chicken.syntax#ir-macro-transformer ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10535,a[2]=((C_word)li116),tmp=(C_word)a,a+=3,tmp));
t46=C_mutate((C_word*)lf[202]+1 /* (set! ##sys#er-transformer ...) */,*((C_word*)lf[200]+1));
t47=C_mutate((C_word*)lf[203]+1 /* (set! ##sys#ir-transformer ...) */,*((C_word*)lf[201]+1));
t48=C_mutate((C_word*)lf[98]+1 /* (set! chicken.syntax#define-definition ...) */,*((C_word*)lf[98]+1));
t49=C_mutate((C_word*)lf[99]+1 /* (set! chicken.syntax#define-syntax-definition ...) */,*((C_word*)lf[99]+1));
t50=C_mutate((C_word*)lf[100]+1 /* (set! chicken.syntax#define-values-definition ...) */,*((C_word*)lf[100]+1));
t51=C_mutate((C_word*)lf[41]+1 /* (set! chicken.syntax#expansion-result-hook ...) */,*((C_word*)lf[41]+1));
t52=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_10548,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t53=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14728,a[2]=t52,tmp=(C_word)a,a+=3,tmp);
t54=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_14730,a[2]=((C_word)li195),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:1048: ##sys#er-transformer */
t55=*((C_word*)lf[202]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t55;
av2[1]=t53;
av2[2]=t54;
((C_proc)(void*)(*((C_word*)t55+1)))(3,av2);}}

/* ##sys#ensure-transformer in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6191,c,av);}
t3=C_rest_nullp(c,3);
t4=(C_truep(t3)?C_SCHEME_FALSE:C_get_rest_arg(c,3,av,3,t0));
if(C_truep(C_i_structurep(t2,lf[26]))){
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_slot(t2,C_fix(1));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
/* expand.scm:161: ##sys#error */
t5=*((C_word*)lf[27]+1);{
C_word av2[5];
av2[0]=t5;
av2[1]=t1;
av2[2]=t4;
av2[3]=lf[28];
av2[4]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* ##sys#extend-macro-environment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6215(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_6215,c,av);}
a=C_alloc(6);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6219,a[2]=t2,a[3]=t3,a[4]=t1,a[5]=t4,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:164: ##sys#macro-environment */
t6=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}

/* k6217 in ##sys#extend-macro-environment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6219(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6219,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6222,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:165: ##sys#ensure-transformer */
t3=*((C_word*)lf[25]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}

/* k6220 in k6217 in ##sys#extend-macro-environment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6222(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_6222,c,av);}
a=C_alloc(16);
t2=(
/* expand.scm:166: lookup */
  f_5794(((C_word*)t0)[2],((C_word*)t0)[3])
);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6229,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=((C_word)li10),tmp=(C_word)a,a+=5,tmp);
/* expand.scm:166: g1033 */
t4=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
/* expand.scm:166: g1033 */
  f_6229(t3,t2)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t3=C_a_i_list2(&a,2,((C_word*)t0)[4],t1);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6247,a[2]=((C_word*)t0)[5],a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t5=C_a_i_cons(&a,2,((C_word*)t0)[2],t3);
t6=C_a_i_cons(&a,2,t5,((C_word*)t0)[3]);
/* expand.scm:173: ##sys#macro-environment */
t7=*((C_word*)lf[17]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t4;
av2[2]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}}

/* g1033 in k6220 in k6217 in ##sys#extend-macro-environment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_6229(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;{}
t2=C_i_set_car(t1,((C_word*)t0)[2]);
t3=C_i_set_car(C_u_i_cdr(t1),((C_word*)t0)[3]);
return(t1);}

/* k6245 in k6220 in k6217 in ##sys#extend-macro-environment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6247(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6247,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#macro? in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6257(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6257,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6261,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
if(C_truep(C_rest_nullp(c,3))){
/* expand.scm:177: ##sys#current-environment */
t4=*((C_word*)lf[3]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=t3;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_get_rest_arg(c,3,av,3,t0);
f_6261(2,av2);}}}

/* k6259 in ##sys#macro? in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6261(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6261,c,av);}
a=C_alloc(4);
t2=(
/* expand.scm:178: lookup */
  f_5794(((C_word*)t0)[2],t1)
);
t3=C_i_pairp(t2);
if(C_truep(t3)){
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6283,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:180: ##sys#macro-environment */
t5=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k6281 in k6259 in ##sys#macro? in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6283(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6283,c,av);}
t2=(
/* expand.scm:180: lookup */
  f_5794(((C_word*)t0)[2],t1)
);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(C_truep(t2)?C_i_pairp(t2):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* ##sys#undefine-macro! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6294(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6294,c,av);}
a=C_alloc(7);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6302,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6306,a[2]=t2,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:186: ##sys#macro-environment */
t5=*((C_word*)lf[17]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k6300 in ##sys#undefine-macro! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6302(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6302,c,av);}
/* expand.scm:184: ##sys#macro-environment */
t2=*((C_word*)lf[17]+1);{
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

/* k6304 in ##sys#undefine-macro! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6306(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,3)))){
C_save_and_reclaim((void *)f_6306,c,av);}
a=C_alloc(7);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6308,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word)li13),tmp=(C_word)a,a+=5,tmp));
t5=((C_word*)t3)[1];
f_6308(t5,((C_word*)t0)[3],t1);}

/* loop in k6304 in ##sys#undefine-macro! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6308(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6308,3,t0,t1,t2);}
a=C_alloc(4);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_caar(t2);
t4=C_eqp(((C_word*)t0)[2],t3);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_u_i_cdr(t2);
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_u_i_car(t2);
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6331,a[2]=t1,a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:189: loop */
t8=t6;
t9=C_u_i_cdr(t2);
t1=t8;
t2=t9;
goto loop;}}}

/* k6329 in loop in k6304 in ##sys#undefine-macro! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6331(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_6331,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6339(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(22,c,7)))){
C_save_and_reclaim((void *)f_6339,c,av);}
a=C_alloc(22);
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6342,a[2]=t3,a[3]=((C_word)li27),tmp=(C_word)a,a+=4,tmp));
t10=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6541,a[2]=t6,a[3]=((C_word)li28),tmp=(C_word)a,a+=4,tmp));
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6585,a[2]=t3,a[3]=t8,a[4]=t12,a[5]=t6,a[6]=t4,a[7]=((C_word)li32),tmp=(C_word)a,a+=8,tmp));
t14=((C_word*)t12)[1];
f_6585(t14,t1,t2);}

/* call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6342(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_6342,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(12);
t7=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6352,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
t8=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6357,a[2]=t2,a[3]=t4,a[4]=t6,a[5]=t3,a[6]=t5,a[7]=((C_word*)t0)[2],a[8]=((C_word)li26),tmp=(C_word)a,a+=9,tmp);
/* expand.scm:197: scheme#call-with-current-continuation */
t9=*((C_word*)lf[49]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t7;
av2[2]=t8;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}

/* k6350 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6352(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6352,c,av);}
/* g10851086 */
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6357(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_6357,c,av);}
a=C_alloc(15);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6363,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li17),tmp=(C_word)a,a+=5,tmp);
t4=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6464,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t2,a[9]=((C_word)li25),tmp=(C_word)a,a+=10,tmp);
/* expand.scm:197: chicken.condition#with-exception-handler */
t5=*((C_word*)lf[48]+1);{
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

/* a6362 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6363(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_6363,c,av);}
a=C_alloc(5);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6369,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word)li16),tmp=(C_word)a,a+=5,tmp);
/* expand.scm:197: k1082 */
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t3;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}

/* a6368 in a6362 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6369(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_6369,c,av);}
a=C_alloc(11);
t2=C_i_structurep(((C_word*)t0)[2],lf[33]);
t3=(C_truep(t2)?C_i_memq(lf[34],C_slot(((C_word*)t0)[2],C_fix(1))):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=C_slot(((C_word*)t0)[2],C_fix(1));
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6391,a[2]=t4,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t6=C_slot(((C_word*)t0)[2],C_fix(2));
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6397,a[2]=((C_word*)t0)[3],a[3]=t8,a[4]=((C_word)li15),tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_6397(t10,t5,t6);}
else{
/* expand.scm:200: chicken.condition#abort */
t4=*((C_word*)lf[35]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k6389 in a6368 in a6362 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6391(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_6391,c,av);}
a=C_alloc(4);
t2=C_a_i_record3(&a,3,lf[33],((C_word*)t0)[2],t1);
/* expand.scm:200: chicken.condition#abort */
t3=*((C_word*)lf[35]+1);{
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

/* copy in a6368 in a6362 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6397(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_6397,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6414,a[2]=t4,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_i_equalp(lf[40],t3))){
t6=C_i_pairp(t4);
t7=t5;
f_6414(t7,(C_truep(t6)?C_i_stringp(C_u_i_car(t4)):C_SCHEME_FALSE));}
else{
t6=t5;
f_6414(t6,C_SCHEME_FALSE);}}}

/* k6412 in copy in a6368 in a6362 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6414(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,0,5)))){
C_save_and_reclaim_args((void *)trf_6414,2,t0,t1);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6425,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:216: scheme#string-append */
t3=*((C_word*)lf[37]+1);{
C_word av2[6];
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[38];
av2[3]=C_slot(((C_word*)t0)[4],C_fix(1));
av2[4]=lf[39];
av2[5]=C_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
/* expand.scm:222: copy */
t2=((C_word*)((C_word*)t0)[5])[1];
f_6397(t2,((C_word*)t0)[3],((C_word*)t0)[2]);}}

/* k6423 in k6412 in copy in a6368 in a6362 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_6425,c,av);}
a=C_alloc(6);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_cons(&a,2,lf[36],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6464(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_6464,c,av);}
a=C_alloc(13);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6470,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li22),tmp=(C_word)a,a+=9,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6529,a[2]=((C_word*)t0)[8],a[3]=((C_word)li24),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:197: ##sys#call-with-values */{
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

/* a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6470(C_word c,C_word *av){
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
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(31,c,4)))){
C_save_and_reclaim((void *)f_6470,c,av);}
a=C_alloc(31);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6474,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(((C_word*)t0)[3])){
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6504,a[2]=((C_word*)t0)[2],a[3]=((C_word)li18),tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6510,a[2]=t6,a[3]=t4,a[4]=((C_word)li19),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_6515,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word)li20),tmp=(C_word)a,a+=7,tmp);
t9=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6521,a[2]=t4,a[3]=t6,a[4]=((C_word)li21),tmp=(C_word)a,a+=5,tmp);
/* expand.scm:227: ##sys#dynamic-wind */
t10=*((C_word*)lf[47]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t10;
av2[1]=t2;
av2[2]=t7;
av2[3]=t8;
av2[4]=t9;
((C_proc)(void*)(*((C_word*)t10+1)))(5,av2);}}
else{
/* expand.scm:230: handler */
t3=((C_word*)t0)[5];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[6];
av2[4]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t3))(5,av2);}}}

/* k6472 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6474(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6474,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6477,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
t3=C_i_not(((C_word*)t0)[4]);
t4=(C_truep(t3)?C_eqp(((C_word*)t0)[3],t1):C_SCHEME_FALSE);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6493,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6497,a[2]=t5,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:234: scheme#symbol->string */
t7=*((C_word*)lf[45]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t7;
av2[1]=t6;
av2[2]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t7+1)))(3,av2);}}
else{
/* expand.scm:238: expansion-result-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[41]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[41]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t1;
tp(4,av2);}}}

/* k6475 in k6472 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6477(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6477,c,av);}
/* expand.scm:238: expansion-result-hook */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[41]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[41]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
tp(4,av2);}}

/* k6491 in k6472 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6493,c,av);}
/* expand.scm:232: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
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

/* k6495 in k6472 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6497(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6497,c,av);}
/* expand.scm:233: scheme#string-append */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[43];
av2[3]=t1;
av2[4]=lf[44];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* f_6504 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6504(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6504,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* a6509 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6510(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6510,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[46]+1));
t3=C_mutate((C_word*)lf[46]+1 /* (set! chicken.internal.syntax-rules#syntax-rules-mismatch ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a6514 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6515(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6515,c,av);}
/* expand.scm:229: handler */
t2=((C_word*)t0)[2];{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[3];
av2[3]=((C_word*)t0)[4];
av2[4]=((C_word*)t0)[5];
((C_proc)C_fast_retrieve_proc(t2))(5,av2);}}

/* a6520 in a6469 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6521(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6521,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,*((C_word*)lf[46]+1));
t3=C_mutate((C_word*)lf[46]+1 /* (set! chicken.internal.syntax-rules#syntax-rules-mismatch ...) */,((C_word*)((C_word*)t0)[3])[1]);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* a6528 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6529(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +4,c,2)))){
C_save_and_reclaim((void*)f_6529,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+4);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6535,a[2]=t2,a[3]=((C_word)li23),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:197: k1082 */
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

/* a6534 in a6528 in a6463 in a6356 in call-handler in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6535(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6535,c,av);}{
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

/* expand in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6541(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,6)))){
C_save_and_reclaim_args((void *)trf_6541,5,t0,t1,t2,t3,t4);}
a=C_alloc(3);
t5=C_i_listp(t3);
if(C_truep(C_i_not(t5))){
/* expand.scm:250: ##sys#syntax-error-hook */
t6=*((C_word*)lf[42]+1);{
C_word av2[4];
av2[0]=t6;
av2[1]=t1;
av2[2]=lf[50];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(4,av2);}}
else{
if(C_truep(C_i_pairp(t4))){
t6=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6567,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:254: call-handler */
t7=((C_word*)((C_word*)t0)[2])[1];
f_6342(t7,t6,t2,C_i_cadr(t4),t3,C_u_i_car(t4),C_SCHEME_FALSE);}
else{
/* expand.scm:256: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}}

/* k6565 in expand in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6567(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_6567,c,av);}
/* expand.scm:252: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=C_SCHEME_TRUE;
C_values(4,av2);}}

/* loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6585(C_word t0,C_word t1,C_word t2){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,3)))){
C_save_and_reclaim_args((void *)trf_6585,3,t0,t1,t2);}
a=C_alloc(18);
if(C_truep(C_i_pairp(t2))){
t3=C_u_i_car(t2);
t4=C_u_i_cdr(t2);
if(C_truep(C_i_symbolp(t3))){
t5=(
/* expand.scm:262: lookup */
  f_5794(t3,((C_word*)t0)[2])
);
t6=(C_truep(t5)?t5:t3);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6609,a[2]=t1,a[3]=t2,a[4]=t8,a[5]=t4,a[6]=((C_word*)t0)[2],a[7]=((C_word*)t0)[3],a[8]=t3,a[9]=((C_word*)t0)[4],a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[6],tmp=(C_word)a,a+=12,tmp);
if(C_truep(C_i_pairp(((C_word*)t8)[1]))){
t10=t9;
f_6609(t10,C_SCHEME_UNDEFINED);}
else{
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6846,a[2]=t8,a[3]=t9,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:264: ##sys#macro-environment */
t11=*((C_word*)lf[17]+1);{
C_word av2[2];
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}}
else{
/* expand.scm:293: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}
else{
/* expand.scm:294: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}

/* k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6609(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,0,3)))){
C_save_and_reclaim_args((void *)trf_6609,2,t0,t1);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_6615,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],tmp=(C_word)a,a+=12,tmp);
if(C_truep(C_i_pairp(((C_word*)((C_word*)t0)[4])[1]))){
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6832,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:266: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[62]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[62]+1);
av2[1]=t3;
av2[2]=((C_word*)t0)[8];
av2[3]=lf[63];
tp(4,av2);}}
else{
t3=t2;
f_6615(t3,C_SCHEME_FALSE);}}

/* k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6615(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,6)))){
C_save_and_reclaim_args((void *)trf_6615,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
/* expand.scm:267: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}
else{
t2=C_eqp(((C_word*)((C_word*)t0)[4])[1],lf[51]);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6627,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:269: ##sys#check-syntax */
t4=*((C_word*)lf[55]+1);{
C_word av2[7];
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[56];
av2[3]=((C_word*)t0)[5];
av2[4]=lf[58];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6773,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[2],tmp=(C_word)a,a+=9,tmp);
if(C_truep(((C_word*)t0)[11])){
if(C_truep(C_i_symbolp(((C_word*)((C_word*)t0)[4])[1]))){
t4=((C_word*)((C_word*)t0)[4])[1];
t5=t3;
f_6773(t5,C_i_getprop(t4,lf[60],C_SCHEME_FALSE));}
else{
t4=t3;
f_6773(t4,C_SCHEME_FALSE);}}
else{
t4=t3;
f_6773(t4,C_SCHEME_FALSE);}}}}

/* k6625 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6627(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,6)))){
C_save_and_reclaim((void *)f_6627,c,av);}
a=C_alloc(5);
t2=C_i_car(((C_word*)t0)[2]);
if(C_truep(C_i_symbolp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6639,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:272: ##sys#check-syntax */
t4=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=lf[56];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[57];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(7,av2);}}
else{
/* expand.scm:283: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[5];
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}

/* k6637 in k6625 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6639(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6639,c,av);}
a=C_alloc(19);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(t2,lf[16]);
t8=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6729,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6735,a[2]=t5,a[3]=t10,a[4]=t6,a[5]=((C_word)li30),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_6735(t12,t8,t2);}

/* k6662 in k6727 in k6637 in k6625 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6664(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_6664,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[54],t2);
/* expand.scm:274: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=t3;
av2[3]=C_SCHEME_TRUE;
C_values(4,av2);}}

/* map-loop1182 in k6727 in k6637 in k6625 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6666(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6666,3,t0,t1,t2);}
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

/* k6727 in k6637 in k6625 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6729(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(41,c,3)))){
C_save_and_reclaim((void *)f_6729,c,av);}
a=C_alloc(41);
t2=C_i_cddr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t1,t2);
t4=C_a_i_cons(&a,2,lf[52],t3);
t5=C_a_i_list(&a,2,((C_word*)t0)[3],t4);
t6=C_a_i_list(&a,1,t5);
t7=C_a_i_list(&a,3,lf[53],t6,((C_word*)t0)[3]);
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6664,a[2]=t7,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t13=C_SCHEME_UNDEFINED;
t14=(*a=C_VECTOR_TYPE|1,a[1]=t13,tmp=(C_word)a,a+=2,tmp);
t15=C_set_block_item(t14,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6666,a[2]=t10,a[3]=t14,a[4]=t11,a[5]=((C_word)li29),tmp=(C_word)a,a+=6,tmp));
t16=((C_word*)t14)[1];
f_6666(t16,t12,((C_word*)t0)[5]);}

/* map-loop1155 in k6637 in k6625 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6735(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_6735,3,t0,t1,t2);}
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

/* k6771 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6773(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,4)))){
C_save_and_reclaim_args((void *)trf_6773,2,t0,t1);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6777,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word)li31),tmp=(C_word)a,a+=9,tmp);
/* expand.scm:265: g1215 */
t3=t2;
f_6777(t3,((C_word*)t0)[8],t1);}
else{
/* expand.scm:292: expand */
t2=((C_word*)((C_word*)t0)[3])[1];
f_6541(t2,((C_word*)t0)[8],((C_word*)t0)[4],((C_word*)t0)[2],((C_word*)((C_word*)t0)[5])[1]);}}

/* g1215 in k6771 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6777(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,0,6)))){
C_save_and_reclaim_args((void *)trf_6777,3,t0,t1,t2);}
a=C_alloc(8);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_6781,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:286: call-handler */
t4=((C_word*)((C_word*)t0)[7])[1];
f_6342(t4,t3,((C_word*)t0)[4],C_i_car(t2),((C_word*)t0)[2],C_u_i_cdr(t2),C_SCHEME_TRUE);}

/* k6779 in g1215 in k6771 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6781(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_6781,c,av);}
a=C_alloc(5);
t2=C_eqp(t1,((C_word*)t0)[2]);
if(C_truep(t2)){
/* expand.scm:287: expand */
t3=((C_word*)((C_word*)t0)[3])[1];
f_6541(t3,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[2],((C_word*)((C_word*)t0)[6])[1]);}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6793,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[4],a[4]=t1,tmp=(C_word)a,a+=5,tmp);
if(C_truep(*((C_word*)lf[59]+1))){
/* expand.scm:290: ##sys#compiler-syntax-hook */
t4=*((C_word*)lf[59]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)((C_word*)t0)[6])[1];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
/* expand.scm:291: loop */
t4=((C_word*)((C_word*)t0)[7])[1];
f_6585(t4,((C_word*)t0)[4],t1);}}}

/* k6791 in k6779 in g1215 in k6771 in k6613 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6793(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6793,c,av);}
/* expand.scm:291: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_6585(t2,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* k6830 in k6607 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6832(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6832,c,av);}
t2=((C_word*)t0)[2];
f_6615(t2,C_eqp(t1,lf[61]));}

/* k6844 in loop in ##sys#expand-0 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6846(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6846,c,av);}
t2=(
/* expand.scm:264: lookup */
  f_5794(((C_word*)((C_word*)t0)[2])[1],t1)
);
if(C_truep(t2)){
t3=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t4=((C_word*)t0)[3];
f_6609(t4,t3);}
else{
t3=((C_word*)((C_word*)t0)[2])[1];
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t3);
t5=((C_word*)t0)[3];
f_6609(t5,t4);}}

/* chicken.syntax#expansion-result-hook in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6856(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_6856,c,av);}
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* chicken.syntax#expand in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6859(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_6859,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6863,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
/* expand.scm:303: ##sys#current-environment */
t5=*((C_word*)lf[3]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_car(t3);
f_6863(2,av2);}}}

/* k6861 in chicken.syntax#expand in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6863(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_6863,c,av);}
a=C_alloc(8);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6877,a[2]=t1,a[3]=t5,a[4]=t9,a[5]=((C_word)li37),tmp=(C_word)a,a+=6,tmp));
t11=((C_word*)t9)[1];
f_6877(t11,((C_word*)t0)[3],((C_word*)t0)[4]);}

/* loop in k6861 in chicken.syntax#expand in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6877(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,4)))){
C_save_and_reclaim_args((void *)trf_6877,3,t0,t1,t2);}
a=C_alloc(10);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_6883,a[2]=t2,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word)li35),tmp=(C_word)a,a+=6,tmp);
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_6889,a[2]=((C_word*)t0)[4],a[3]=((C_word)li36),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:305: ##sys#call-with-values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
C_call_with_values(4,av2);}}

/* a6882 in loop in k6861 in chicken.syntax#expand in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6883(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_6883,c,av);}
/* expand.scm:305: ##sys#expand-0 */
t2=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=t1;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[3];
av2[4]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* a6888 in loop in k6861 in chicken.syntax#expand in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6889(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_6889,c,av);}
if(C_truep(t3)){
/* expand.scm:307: loop */
t4=((C_word*)((C_word*)t0)[2])[1];
f_6877(t4,t1,t2);}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* ##sys#extended-lambda-list? in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6925(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_6925,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_6931,a[2]=((C_word)li39),tmp=(C_word)a,a+=3,tmp);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
  f_6931(t2)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* loop in ##sys#extended-lambda-list? in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_6931(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_stack_overflow_check;
loop:{}
if(C_truep(C_i_pairp(t1))){
t2=C_slot(t1,C_fix(0));
t3=C_eqp(t2,lf[67]);
if(C_truep(t3)){
if(C_truep(t3)){
return(C_SCHEME_TRUE);}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}
else{
t4=C_eqp(t2,lf[68]);
if(C_truep(t4)){
if(C_truep(t4)){
return(C_SCHEME_TRUE);}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}
else{
t5=C_eqp(t2,lf[69]);
if(C_truep(t5)){
return(C_SCHEME_TRUE);}
else{
t7=C_u_i_cdr(t1);
t1=t7;
goto loop;}}}}
else{
return(C_SCHEME_FALSE);}}

/* ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6972(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_6972,c,av);}
a=C_alloc(18);
t6=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_6975,a[2]=t4,a[3]=t2,a[4]=((C_word)li41),tmp=(C_word)a,a+=5,tmp);
t7=C_SCHEME_FALSE;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_SCHEME_FALSE;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_6992,a[2]=t8,a[3]=t10,a[4]=t3,a[5]=t6,a[6]=t5,a[7]=t1,a[8]=t2,tmp=(C_word)a,a+=9,tmp);
/* expand.scm:338: macro-alias */
f_5811(t11,lf[91],*((C_word*)lf[92]+1));}

/* err in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_6975(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_6975,3,t0,t1,t2);}
/* expand.scm:333: errh */
t3=((C_word*)t0)[2];{
C_word av2[4];
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=((C_word*)t0)[3];
((C_proc)C_fast_retrieve_proc(t3))(4,av2);}}

/* k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6992(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_6992,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_6995,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:340: macro-alias */
f_5811(t2,lf[90],*((C_word*)lf[24]+1));}

/* k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,c,3)))){
C_save_and_reclaim((void *)f_6995,c,av);}
a=C_alloc(11);
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_6998,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
/* expand.scm:341: macro-alias */
f_5811(t2,lf[89],*((C_word*)lf[24]+1));}

/* k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_6998(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,7)))){
C_save_and_reclaim((void *)f_6998,c,av);}
a=C_alloc(14);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7003,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=t3,a[10]=((C_word*)t0)[8],a[11]=((C_word)li44),tmp=(C_word)a,a+=12,tmp));
t5=((C_word*)t3)[1];
f_7003(t5,((C_word*)t0)[9],C_fix(0),C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,((C_word*)t0)[10]);}

/* loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7003(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5,C_word t6){
C_word tmp;
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
if(C_unlikely(!C_demand(C_calculate_demand(15,0,6)))){
C_save_and_reclaim_args((void *)trf_7003,7,t0,t1,t2,t3,t4,t5,t6);}
a=C_alloc(15);
if(C_truep(C_i_nullp(t6))){
t7=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7017,a[2]=t4,a[3]=t1,a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=t5,a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[6],a[10]=((C_word*)t0)[7],tmp=(C_word)a,a+=11,tmp);
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7265,a[2]=t7,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:350: reverse */
t9=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t9;
av2[1]=t8;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}
else{
/* expand.scm:350: reverse */
t8=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t8;
av2[1]=t7;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}}
else{
if(C_truep(C_i_symbolp(t6))){
if(C_truep(C_fixnum_greaterp(t2,C_fix(2)))){
/* expand.scm:378: err */
t7=((C_word*)t0)[8];
f_6975(t7,t1,lf[78]);}
else{
if(C_truep(((C_word*)((C_word*)t0)[3])[1])){
t7=C_mutate(((C_word *)((C_word*)t0)[4])+1,t6);
/* expand.scm:382: loop */
t12=t1;
t13=C_fix(4);
t14=t3;
t15=t4;
t16=C_SCHEME_END_OF_LIST;
t17=C_SCHEME_END_OF_LIST;
t1=t12;
t2=t13;
t3=t14;
t4=t15;
t5=t16;
t6=t17;
goto loop;}
else{
t7=C_mutate(((C_word *)((C_word*)t0)[3])+1,t6);
t8=C_mutate(((C_word *)((C_word*)t0)[4])+1,t6);
/* expand.scm:382: loop */
t12=t1;
t13=C_fix(4);
t14=t3;
t15=t4;
t16=C_SCHEME_END_OF_LIST;
t17=C_SCHEME_END_OF_LIST;
t1=t12;
t2=t13;
t3=t14;
t4=t15;
t5=t16;
t6=t17;
goto loop;}}}
else{
t7=C_i_pairp(t6);
if(C_truep(C_i_not(t7))){
/* expand.scm:384: err */
t8=((C_word*)t0)[8];
f_6975(t8,t1,lf[79]);}
else{
t8=C_i_car(t6);
t9=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7306,a[2]=t8,a[3]=t6,a[4]=t2,a[5]=((C_word*)t0)[9],a[6]=t1,a[7]=t3,a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[4],a[12]=t4,a[13]=t5,tmp=(C_word)a,a+=14,tmp);
if(C_truep(C_i_symbolp(t8))){
t10=C_eqp(C_fix(3),t2);
/* expand.scm:387: lookup */
t11=t9;
f_7306(t11,(C_truep(C_i_not(t10))?(
/* expand.scm:387: lookup */
  f_5794(t8,((C_word*)t0)[10])
):C_SCHEME_FALSE));}
else{
t10=t9;
f_7306(t10,C_SCHEME_FALSE);}}}}}

/* k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7017(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7017,c,av);}
a=C_alloc(28);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_7021,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
if(C_truep(C_i_nullp(((C_word*)t0)[7]))){
t3=t2;
f_7021(t3,((C_word*)t0)[9]);}
else{
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7161,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[5],a[4]=((C_word)li42),tmp=(C_word)a,a+=5,tmp);
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7221,a[2]=((C_word*)t0)[9],a[3]=((C_word*)t0)[10],a[4]=t2,a[5]=t5,a[6]=t7,a[7]=t6,tmp=(C_word)a,a+=8,tmp);
/* expand.scm:362: reverse */
t9=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t9;
av2[1]=t8;
av2[2]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t9+1)))(3,av2);}}}

/* k7019 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7021(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,3)))){
C_save_and_reclaim_args((void *)trf_7021,2,t0,t1);}
a=C_alloc(11);
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
/* expand.scm:349: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=t1;
C_values(4,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7033,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=t1,a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_not(((C_word*)((C_word*)t0)[7])[1]))){
t3=C_i_nullp(((C_word*)t0)[8]);
t4=t2;
f_7033(t4,(C_truep(t3)?C_i_nullp(C_i_cdr(((C_word*)t0)[2])):C_SCHEME_FALSE));}
else{
t3=t2;
f_7033(t3,C_SCHEME_FALSE);}}}

/* k7031 in k7019 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7033(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,2)))){
C_save_and_reclaim_args((void *)trf_7033,2,t0,t1);}
a=C_alloc(12);
if(C_truep(t1)){
t2=C_i_caar(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7064,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:367: scheme#cadar */
t4=*((C_word*)lf[71]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}
else{
t2=C_i_not(((C_word*)((C_word*)t0)[8])[1]);
t3=(C_truep(t2)?C_i_nullp(((C_word*)t0)[9]):C_SCHEME_FALSE);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7089,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:371: reverse */
t5=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t5;
av2[1]=t4;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t5+1)))(3,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7108,a[2]=((C_word*)t0)[5],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[10],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7112,a[2]=((C_word*)t0)[8],a[3]=t4,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:374: reverse */
t6=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}}}

/* k7062 in k7031 in k7019 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7064(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(27,c,3)))){
C_save_and_reclaim((void *)f_7064,c,av);}
a=C_alloc(27);
t2=C_a_i_list(&a,3,((C_word*)t0)[2],((C_word*)((C_word*)t0)[3])[1],t1);
t3=C_a_i_list(&a,2,((C_word*)t0)[4],t2);
t4=C_a_i_list(&a,1,t3);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[5]);
t6=C_a_i_cons(&a,2,lf[51],t5);
t7=C_a_i_list(&a,1,t6);
/* expand.scm:349: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[6];
av2[2]=((C_word*)t0)[7];
av2[3]=t7;
C_values(4,av2);}}

/* k7087 in k7031 in k7019 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7089(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7089,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[3])[1],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
t5=C_a_i_list(&a,1,t4);
/* expand.scm:349: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[6];
av2[3]=t5;
C_values(4,av2);}}

/* k7106 in k7031 in k7019 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7108(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_7108,c,av);}
a=C_alloc(12);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)((C_word*)t0)[3])[1],t2);
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],t3);
t5=C_a_i_list(&a,1,t4);
/* expand.scm:349: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[5];
av2[2]=((C_word*)t0)[6];
av2[3]=t5;
C_values(4,av2);}}

/* k7110 in k7031 in k7019 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7112,c,av);}
a=C_alloc(3);
t2=((C_word*)((C_word*)t0)[2])[1];
if(C_truep(t2)){
t3=C_a_i_list1(&a,1,t2);
/* expand.scm:374: ##sys#append */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t3=((C_word*)((C_word*)t0)[4])[1];
t4=C_a_i_list1(&a,1,t3);
/* expand.scm:374: ##sys#append */
t5=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* g1318 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7161(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_7161,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7214,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t2,a[5]=t1,a[6]=t3,tmp=(C_word)a,a+=7,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7218,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:358: chicken.syntax#strip-syntax */
t6=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}

/* k7212 in g1318 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7214(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(30,c,1)))){
C_save_and_reclaim((void *)f_7214,c,av);}
a=C_alloc(30);
t2=C_a_i_list(&a,2,lf[74],t1);
t3=((C_word*)((C_word*)t0)[2])[1];
t4=(C_truep(t3)?t3:((C_word*)((C_word*)t0)[3])[1]);
if(C_truep(C_i_pairp(C_u_i_cdr(((C_word*)t0)[4])))){
t5=C_u_i_cdr(((C_word*)t0)[4]);
t6=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,t5);
t7=C_a_i_cons(&a,2,lf[75],t6);
t8=C_a_i_list(&a,1,t7);
t9=C_a_i_cons(&a,2,t4,t8);
t10=C_a_i_cons(&a,2,t2,t9);
t11=C_a_i_cons(&a,2,lf[76],t10);
t12=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t12;
av2[1]=C_a_i_list(&a,2,((C_word*)t0)[6],t11);
((C_proc)(void*)(*((C_word*)t12+1)))(2,av2);}}
else{
t5=C_a_i_cons(&a,2,t4,C_SCHEME_END_OF_LIST);
t6=C_a_i_cons(&a,2,t2,t5);
t7=C_a_i_cons(&a,2,lf[76],t6);
t8=((C_word*)t0)[5];{
C_word *av2=av;
av2[0]=t8;
av2[1]=C_a_i_list(&a,2,((C_word*)t0)[6],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k7216 in g1318 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7218(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_7218,c,av);}
/* expand.scm:334: chicken.keyword#string->keyword */
t2=*((C_word*)lf[77]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=C_slot(t1,C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(3,av2);}}

/* k7219 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,3)))){
C_save_and_reclaim((void *)f_7221,c,av);}
a=C_alloc(14);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7224,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7226,a[2]=((C_word*)t0)[5],a[3]=t4,a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word)li43),tmp=(C_word)a,a+=7,tmp));
t6=((C_word*)t4)[1];
f_7226(t6,t2,t1);}

/* k7222 in k7219 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_7224,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],t2);
t4=((C_word*)t0)[4];
f_7021(t4,C_a_i_list(&a,1,t3));}

/* map-loop1312 in k7219 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7226(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7226,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7251,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:355: g1318 */
t4=((C_word*)t0)[4];
f_7161(t4,t3,C_slot(t2,C_fix(0)));}
else{
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_slot(((C_word*)t0)[5],C_fix(1));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k7249 in map-loop1312 in k7219 in k7015 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7251(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7251,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7226(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* k7263 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7265(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_7265,c,av);}
/* expand.scm:350: ##sys#append */
t2=*((C_word*)lf[73]+1);{
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

/* k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7306(C_word t0,C_word t1){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,0,6)))){
C_save_and_reclaim_args((void *)trf_7306,2,t0,t1);}
a=C_alloc(13);
t2=(C_truep(t1)?t1:((C_word*)t0)[2]);
t3=C_u_i_cdr(((C_word*)t0)[3]);
t4=C_eqp(t2,lf[68]);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7319,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=t3,a[7]=((C_word*)t0)[8],tmp=(C_word)a,a+=8,tmp);
if(C_truep(((C_word*)((C_word*)t0)[9])[1])){
t6=t5;
f_7319(t6,C_SCHEME_UNDEFINED);}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7335,a[2]=((C_word*)t0)[9],a[3]=t5,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:391: macro-alias */
f_5811(t6,lf[81],((C_word*)t0)[10]);}}
else{
t5=C_eqp(t2,lf[67]);
if(C_truep(t5)){
if(C_truep(C_fixnum_less_or_equal_p(((C_word*)t0)[4],C_fix(1)))){
t6=C_i_pairp(t3);
t7=(C_truep(t6)?C_i_symbolp(C_u_i_car(t3)):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7356,a[2]=t3,a[3]=((C_word*)t0)[11],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[12],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_not(((C_word*)((C_word*)t0)[9])[1]))){
t9=C_i_car(t3);
t10=C_mutate(((C_word *)((C_word*)t0)[9])+1,t9);
t11=t8;
f_7356(t11,t10);}
else{
t9=t8;
f_7356(t9,C_SCHEME_UNDEFINED);}}
else{
/* expand.scm:402: err */
t8=((C_word*)t0)[8];
f_6975(t8,((C_word*)t0)[6],lf[82]);}}
else{
/* expand.scm:403: err */
t6=((C_word*)t0)[8];
f_6975(t6,((C_word*)t0)[6],lf[83]);}}
else{
t6=C_eqp(t2,lf[69]);
if(C_truep(t6)){
t7=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7395,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[12],a[7]=t3,a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_not(((C_word*)((C_word*)t0)[9])[1]))){
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7414,a[2]=((C_word*)t0)[9],a[3]=t7,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:405: macro-alias */
f_5811(t8,lf[81],((C_word*)t0)[10]);}
else{
t8=t7;
f_7395(t8,C_SCHEME_UNDEFINED);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[2]))){
switch(((C_word*)t0)[4]){
case C_fix(0):
t7=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[7]);
/* expand.scm:412: loop */
t8=((C_word*)((C_word*)t0)[5])[1];
f_7003(t8,((C_word*)t0)[6],C_fix(0),t7,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,t3);
case C_fix(1):
t7=C_a_i_list2(&a,2,((C_word*)t0)[2],C_SCHEME_FALSE);
t8=C_a_i_cons(&a,2,t7,((C_word*)t0)[12]);
/* expand.scm:413: loop */
t9=((C_word*)((C_word*)t0)[5])[1];
f_7003(t9,((C_word*)t0)[6],C_fix(1),((C_word*)t0)[7],t8,C_SCHEME_END_OF_LIST,t3);
case C_fix(2):
/* expand.scm:414: err */
t7=((C_word*)t0)[8];
f_6975(t7,((C_word*)t0)[6],lf[85]);
default:
t7=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t8=C_a_i_cons(&a,2,t7,((C_word*)t0)[13]);
/* expand.scm:415: loop */
t9=((C_word*)((C_word*)t0)[5])[1];
f_7003(t9,((C_word*)t0)[6],C_fix(3),((C_word*)t0)[7],((C_word*)t0)[12],t8,t3);}}
else{
t7=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7482,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[2],a[6]=((C_word*)t0)[12],a[7]=((C_word*)t0)[5],a[8]=((C_word*)t0)[7],a[9]=t3,a[10]=((C_word*)t0)[13],tmp=(C_word)a,a+=11,tmp);
if(C_truep(C_i_listp(((C_word*)t0)[2]))){
t8=C_eqp(C_fix(2),C_u_i_length(((C_word*)t0)[2]));
t9=t7;
f_7482(t9,(C_truep(t8)?C_i_symbolp(C_i_car(((C_word*)t0)[2])):C_SCHEME_FALSE));}
else{
t8=t7;
f_7482(t8,C_SCHEME_FALSE);}}}}}}

/* k7317 in k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7319(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_7319,2,t0,t1);}
t2=C_eqp(((C_word*)t0)[2],C_fix(0));
if(C_truep(t2)){
/* expand.scm:393: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_7003(t3,((C_word*)t0)[4],C_fix(1),((C_word*)t0)[5],C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,((C_word*)t0)[6]);}
else{
/* expand.scm:394: err */
t3=((C_word*)t0)[7];
f_6975(t3,((C_word*)t0)[4],lf[80]);}}

/* k7333 in k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7335(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7335,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_7319(t3,t2);}

/* k7354 in k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7356(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_7356,2,t0,t1);}
t2=C_i_car(((C_word*)t0)[2]);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,t2);
/* expand.scm:401: loop */
t4=((C_word*)((C_word*)t0)[4])[1];
f_7003(t4,((C_word*)t0)[5],C_fix(2),((C_word*)t0)[6],((C_word*)t0)[7],C_SCHEME_END_OF_LIST,C_u_i_cdr(((C_word*)t0)[2]));}

/* k7393 in k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7395(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,6)))){
C_save_and_reclaim_args((void *)trf_7395,2,t0,t1);}
if(C_truep(C_fixnum_less_or_equal_p(((C_word*)t0)[2],C_fix(2)))){
/* expand.scm:407: loop */
t2=((C_word*)((C_word*)t0)[3])[1];
f_7003(t2,((C_word*)t0)[4],C_fix(3),((C_word*)t0)[5],((C_word*)t0)[6],C_SCHEME_END_OF_LIST,((C_word*)t0)[7]);}
else{
/* expand.scm:408: err */
t2=((C_word*)t0)[8];
f_6975(t2,((C_word*)t0)[4],lf[84]);}}

/* k7412 in k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7414(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7414,c,av);}
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=((C_word*)t0)[3];
f_7395(t3,t2);}

/* k7480 in k7304 in loop in k6996 in k6993 in k6990 in ##sys#expand-extended-lambda-list in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7482(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,6)))){
C_save_and_reclaim_args((void *)trf_7482,2,t0,t1);}
a=C_alloc(3);
if(C_truep(t1)){
switch(((C_word*)t0)[2]){
case C_fix(0):
/* expand.scm:418: err */
t2=((C_word*)t0)[3];
f_6975(t2,((C_word*)t0)[4],lf[86]);
case C_fix(1):
t2=C_a_i_cons(&a,2,((C_word*)t0)[5],((C_word*)t0)[6]);
/* expand.scm:419: loop */
t3=((C_word*)((C_word*)t0)[7])[1];
f_7003(t3,((C_word*)t0)[4],C_fix(1),((C_word*)t0)[8],t2,C_SCHEME_END_OF_LIST,((C_word*)t0)[9]);
case C_fix(2):
/* expand.scm:420: err */
t2=((C_word*)t0)[3];
f_6975(t2,((C_word*)t0)[4],lf[87]);
default:
t2=C_a_i_cons(&a,2,((C_word*)t0)[5],((C_word*)t0)[10]);
/* expand.scm:421: loop */
t3=((C_word*)((C_word*)t0)[7])[1];
f_7003(t3,((C_word*)t0)[4],C_fix(3),((C_word*)t0)[8],((C_word*)t0)[6],t2,((C_word*)t0)[9]);}}
else{
/* expand.scm:422: err */
t2=((C_word*)t0)[3];
f_6975(t2,((C_word*)t0)[4],lf[88]);}}

/* ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7581(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,5)))){
C_save_and_reclaim((void *)f_7581,c,av);}
a=C_alloc(5);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7587,a[2]=t3,a[3]=t2,a[4]=((C_word)li48),tmp=(C_word)a,a+=5,tmp);
/* expand.scm:440: ##sys#decompose-lambda-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[97]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[97]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=t4;
tp(4,av2);}}

/* a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7587(C_word c,C_word *av){
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
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(20,c,3)))){
C_save_and_reclaim((void *)f_7587,c,av);}
a=C_alloc(20);
t5=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7591,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=t4,tmp=(C_word)a,a+=7,tmp);
if(C_truep(C_i_symbolp(((C_word*)t0)[3]))){
t6=t5;{
C_word *av2=av;
av2[0]=t6;
av2[1]=C_SCHEME_END_OF_LIST;
f_7591(2,av2);}}
else{
t6=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t7=t6;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=((C_word*)t8)[1];
t10=C_i_check_list_2(((C_word*)t0)[3],lf[16]);
t11=C_SCHEME_UNDEFINED;
t12=(*a=C_VECTOR_TYPE|1,a[1]=t11,tmp=(C_word)a,a+=2,tmp);
t13=C_set_block_item(t12,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7723,a[2]=t8,a[3]=t12,a[4]=t9,a[5]=((C_word)li47),tmp=(C_word)a,a+=6,tmp));
t14=((C_word*)t12)[1];
f_7723(t14,t5,((C_word*)t0)[3]);}}

/* k7589 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7591(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_7591,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_7594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_not(((C_word*)t0)[6]))){
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
f_7594(2,av2);}}
else{
/* expand.scm:444: chicken.base#gensym */
t3=*((C_word*)lf[9]+1);{
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

/* k7592 in k7589 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_7594,c,av);}
a=C_alloc(18);
t2=C_a_i_list(&a,3,lf[75],C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7613,a[2]=((C_word*)t0)[3],a[3]=t2,a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,a[8]=((C_word*)t0)[7],tmp=(C_word)a,a+=9,tmp);
/* expand.scm:448: scheme#append */
t4=*((C_word*)lf[15]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[5];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k7611 in k7592 in k7589 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7613(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(24,c,4)))){
C_save_and_reclaim((void *)f_7613,c,av);}
a=C_alloc(24);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7617,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[16]);
t8=C_i_check_list_2(((C_word*)t0)[5],lf[16]);
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7635,a[2]=((C_word*)t0)[6],a[3]=t2,a[4]=((C_word*)t0)[7],a[5]=((C_word*)t0)[8],tmp=(C_word)a,a+=6,tmp);
t10=C_SCHEME_UNDEFINED;
t11=(*a=C_VECTOR_TYPE|1,a[1]=t10,tmp=(C_word)a,a+=2,tmp);
t12=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7657,a[2]=t5,a[3]=t11,a[4]=t6,a[5]=((C_word)li46),tmp=(C_word)a,a+=6,tmp));
t13=((C_word*)t11)[1];
f_7657(t13,t9,((C_word*)t0)[4],((C_word*)t0)[5]);}

/* k7615 in k7611 in k7592 in k7589 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7617(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,1)))){
C_save_and_reclaim((void *)f_7617,c,av);}
a=C_alloc(15);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=C_a_i_cons(&a,2,lf[75],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,3,lf[94],((C_word*)t0)[4],t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* k7633 in k7611 in k7592 in k7589 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7635(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_7635,c,av);}
a=C_alloc(12);
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
/* expand.scm:445: ##sys#append */
t2=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=lf[95];
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
if(C_truep(C_i_nullp(((C_word*)t0)[4]))){
/* expand.scm:445: ##sys#append */
t2=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}
else{
t2=C_a_i_list(&a,3,lf[96],((C_word*)t0)[5],((C_word*)t0)[4]);
t3=C_a_i_list(&a,1,t2);
/* expand.scm:445: ##sys#append */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[3];
av2[2]=t1;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}}}

/* map-loop1449 in k7611 in k7592 in k7589 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7657(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,0,3)))){
C_save_and_reclaim_args((void *)trf_7657,4,t0,t1,t2,t3);}
a=C_alloc(12);
t4=C_i_pairp(t2);
t5=(C_truep(t4)?C_i_pairp(t3):C_SCHEME_FALSE);
if(C_truep(t5)){
t6=C_slot(t2,C_fix(0));
t7=C_slot(t3,C_fix(0));
t8=C_a_i_list(&a,3,lf[96],t6,t7);
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

/* map-loop1420 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7723(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_7723,3,t0,t1,t2);}
a=C_alloc(6);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7748,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:443: g1426 */
t4=*((C_word*)lf[9]+1);{
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

/* k7746 in map-loop1420 in a7586 in ##sys#expand-multiple-values-assignment in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7748(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_7748,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_7723(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)));}

/* ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7761(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c<3) C_bad_min_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-3)*C_SIZEOF_PAIR +5,c,2)))){
C_save_and_reclaim((void*)f_7761,c,av);}
a=C_alloc((c-3)*C_SIZEOF_PAIR+5);
t3=C_build_rest(&a,c,3,av);
C_word t4;
C_word t5;
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7765,a[2]=t3,a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_nullp(t3))){
/* expand.scm:465: ##sys#current-environment */
t5=*((C_word*)lf[3]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=t4;{
C_word *av2=av;
av2[0]=t5;
av2[1]=C_i_car(t3);
f_7765(2,av2);}}}

/* k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7765(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(41,c,4)))){
C_save_and_reclaim((void *)f_7765,c,av);}
a=C_alloc(41);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
t4=C_i_nullp(t3);
t5=(C_truep(t4)?C_SCHEME_FALSE:C_i_car(t3));
t6=C_i_nullp(t3);
t7=(C_truep(t6)?C_SCHEME_END_OF_LIST:C_i_cdr(t3));
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
t26=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7776,a[2]=t1,a[3]=((C_word)li50),tmp=(C_word)a,a+=4,tmp));
t27=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7825,a[2]=t1,a[3]=((C_word)li53),tmp=(C_word)a,a+=4,tmp));
t28=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_7900,a[2]=t13,a[3]=t15,a[4]=t17,a[5]=t19,a[6]=t21,a[7]=t25,a[8]=t9,a[9]=t1,a[10]=t5,a[11]=t23,a[12]=((C_word*)t0)[3],a[13]=((C_word*)t0)[4],a[14]=t11,tmp=(C_word)a,a+=15,tmp);
/* expand.scm:483: comp-def */
t29=((C_word*)t11)[1];
f_7825(t29,t28,*((C_word*)lf[98]+1));}

/* comp in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7776(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_7776,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=(
/* expand.scm:467: lookup */
  f_5794(t3,((C_word*)t0)[2])
);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7783,a[2]=t2,a[3]=t1,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
if(C_truep(t4)){
t6=t5;
f_7783(t6,t4);}
else{
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7823,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:468: ##sys#macro-environment */
t7=*((C_word*)lf[17]+1);{
C_word av2[2];
av2[0]=t7;
av2[1]=t6;
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}}

/* k7781 in comp in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7783(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_7783,2,t0,t1);}
a=C_alloc(9);
t2=C_i_symbolp(t1);
t3=C_i_not(t2);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7792,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
t5=t4;
f_7792(t5,t3);}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7812,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:470: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[62]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[62]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[63];
tp(4,av2);}}}

/* k7790 in k7781 in comp in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7792(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,1)))){
C_save_and_reclaim_args((void *)trf_7792,2,t0,t1);}
if(C_truep(t1)){
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[3]);
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=(C_truep(t2)?t2:C_eqp(((C_word*)t0)[3],((C_word*)t0)[5]));
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k7810 in k7781 in comp in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7812(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7812,c,av);}
t2=((C_word*)t0)[2];
f_7792(t2,C_i_not(C_eqp(t1,lf[61])));}

/* k7821 in comp in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7823(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7823,c,av);}
/* expand.scm:468: lookup */
t2=((C_word*)t0)[2];
f_7783(t2,(
/* expand.scm:468: lookup */
  f_5794(((C_word*)t0)[3],t1)
));}

/* comp-def in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_7825(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,3)))){
C_save_and_reclaim_args((void *)trf_7825,3,t0,t1,t2);}
a=C_alloc(5);
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7827,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word)li52),tmp=(C_word)a,a+=5,tmp);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* f_7827 in comp-def in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7827(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7827,c,av);}
a=C_alloc(8);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7833,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t4,a[5]=((C_word)li51),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_7833(t6,t1,t2);}

/* repeat */
static void C_fcall f_7833(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,2)))){
C_save_and_reclaim_args((void *)trf_7833,3,t0,t1,t2);}
a=C_alloc(10);
t3=(
/* expand.scm:475: lookup */
  f_5794(t2,((C_word*)t0)[2])
);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_7840,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
t5=t4;
f_7840(t5,t3);}
else{
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7896,a[2]=t4,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:476: ##sys#macro-environment */
t6=*((C_word*)lf[17]+1);{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}

/* k7838 in repeat */
static void C_fcall f_7840(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,3)))){
C_save_and_reclaim_args((void *)trf_7840,2,t0,t1);}
a=C_alloc(10);
t2=C_i_symbolp(t1);
t3=C_i_not(t2);
t4=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_7849,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
if(C_truep(t3)){
t5=t4;
f_7849(t5,t3);}
else{
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7885,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:478: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[62]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[62]+1);
av2[1]=t5;
av2[2]=((C_word*)t0)[4];
av2[3]=lf[63];
tp(4,av2);}}}

/* k7847 in k7838 in repeat */
static void C_fcall f_7849(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,2)))){
C_save_and_reclaim_args((void *)trf_7849,2,t0,t1);}
if(C_truep(t1)){
t2=C_eqp(((C_word*)t0)[2],((C_word*)t0)[3]);
if(C_truep(t2)){
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
if(C_truep(C_i_symbolp(((C_word*)t0)[2]))){
t3=C_eqp(((C_word*)t0)[2],((C_word*)t0)[5]);
if(C_truep(C_i_not(t3))){
/* expand.scm:482: repeat */
t4=((C_word*)((C_word*)t0)[6])[1];
f_7833(t4,((C_word*)t0)[4],((C_word*)t0)[2]);}
else{
t4=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k7883 in k7838 in repeat */
static void C_ccall f_7885(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7885,c,av);}
t2=((C_word*)t0)[2];
f_7849(t2,C_i_not(C_eqp(t1,lf[61])));}

/* k7894 in repeat */
static void C_ccall f_7896(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_7896,c,av);}
/* expand.scm:476: lookup */
t2=((C_word*)t0)[2];
f_7840(t2,(
/* expand.scm:476: lookup */
  f_5794(((C_word*)t0)[3],t1)
));}

/* k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7900(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_7900,c,av);}
a=C_alloc(15);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_7904,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[2],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],tmp=(C_word)a,a+=15,tmp);
/* expand.scm:484: comp-def */
t4=((C_word*)((C_word*)t0)[14])[1];
f_7825(t4,t3,*((C_word*)lf[99]+1));}

/* k7902 in k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7904(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,2)))){
C_save_and_reclaim((void *)f_7904,c,av);}
a=C_alloc(15);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_7908,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[2],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],tmp=(C_word)a,a+=15,tmp);
/* expand.scm:485: comp-def */
t4=((C_word*)((C_word*)t0)[14])[1];
f_7825(t4,t3,*((C_word*)lf[100]+1));}

/* k7906 in k7902 in k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7908(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,2)))){
C_save_and_reclaim((void *)f_7908,c,av);}
a=C_alloc(14);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7912,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[2],a[10]=((C_word*)t0)[10],a[11]=((C_word*)t0)[11],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* expand.scm:486: comp-def */
t4=((C_word*)((C_word*)t0)[14])[1];
f_7825(t4,t3,lf[101]);}

/* k7910 in k7906 in k7902 in k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7912(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(27,c,6)))){
C_save_and_reclaim((void *)f_7912,c,av);}
a=C_alloc(27);
t2=C_mutate(((C_word *)((C_word*)t0)[2])+1,t1);
t3=C_mutate(((C_word *)((C_word*)t0)[3])+1,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_7914,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[7],a[7]=((C_word*)t0)[8],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[10],a[10]=((C_word)li60),tmp=(C_word)a,a+=11,tmp));
t4=C_mutate(((C_word *)((C_word*)t0)[11])+1,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8351,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[8],a[4]=((C_word)li63),tmp=(C_word)a,a+=5,tmp));
t5=C_mutate(((C_word *)((C_word*)t0)[4])+1,(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_8507,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[6],a[4]=((C_word*)t0)[11],a[5]=((C_word*)t0)[7],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[9],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[10],a[10]=((C_word)li66),tmp=(C_word)a,a+=11,tmp));
/* expand.scm:635: expand */
t6=((C_word*)((C_word*)t0)[4])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=((C_word*)t0)[12];
av2[2]=((C_word*)t0)[13];
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* f_7914 in k7910 in k7906 in k7902 in k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_7914(C_word c,C_word *av){
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
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_7914,c,av);}
a=C_alloc(14);
t6=C_i_nullp(t2);
t7=(C_truep(t6)?C_i_nullp(t4):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=C_SCHEME_UNDEFINED;
t9=(*a=C_VECTOR_TYPE|1,a[1]=t8,tmp=(C_word)a,a+=2,tmp);
t10=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_7926,a[2]=t9,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word)li55),tmp=(C_word)a,a+=12,tmp));
t11=((C_word*)t9)[1];
f_7926(t11,t1,t5,C_SCHEME_END_OF_LIST);}
else{
t8=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t9=t8;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=((C_word*)t10)[1];
t12=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8167,a[2]=t1,a[3]=t5,a[4]=t4,a[5]=t3,a[6]=t2,a[7]=t10,a[8]=t11,tmp=(C_word)a,a+=9,tmp);
/* expand.scm:542: scheme#reverse */
t13=*((C_word*)lf[72]+1);{
C_word *av2=av;
av2[0]=t13;
av2[1]=t12;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t13+1)))(3,av2);}}}

/* loop */
static void C_fcall f_7926(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,0,3)))){
C_save_and_reclaim_args((void *)trf_7926,4,t0,t1,t2,t3);}
a=C_alloc(16);
t4=C_i_pairp(t2);
if(C_truep(C_i_not(t4))){
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7940,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:494: scheme#reverse */
t6=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t5=C_SCHEME_UNDEFINED;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_set_block_item(t6,0,(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7945,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=t6,a[8]=((C_word*)t0)[6],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[8],a[11]=((C_word*)t0)[9],a[12]=((C_word*)t0)[10],a[13]=((C_word)li54),tmp=(C_word)a,a+=14,tmp));
t8=((C_word*)t6)[1];
f_7945(t8,t1,t2);}}

/* k7938 in loop */
static void C_ccall f_7940(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7940,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[103],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* loop2 in loop */
static void C_fcall f_7945(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(22,0,3)))){
C_save_and_reclaim_args((void *)trf_7945,3,t0,t1,t2);}
a=C_alloc(22);
t3=C_i_car(t2);
t4=C_u_i_cdr(t2);
t5=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_7956,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t1,a[6]=t4,a[7]=((C_word*)t0)[4],a[8]=t2,a[9]=((C_word*)t0)[5],a[10]=((C_word*)t0)[6],a[11]=((C_word*)t0)[7],a[12]=((C_word*)t0)[8],a[13]=((C_word*)t0)[9],tmp=(C_word)a,a+=14,tmp);
if(C_truep(C_i_pairp(t3))){
t6=C_u_i_car(t3);
if(C_truep(C_i_symbolp(t6))){
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8117,a[2]=t5,a[3]=((C_word*)t0)[5],a[4]=t6,a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[11],a[7]=((C_word*)t0)[12],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:501: comp */
t8=((C_word*)((C_word*)t0)[6])[1];
f_7776(t8,t7,lf[103],t6);}
else{
t7=t5;{
C_word av2[2];
av2[0]=t7;
av2[1]=C_SCHEME_FALSE;
f_7956(2,av2);}}}
else{
t6=t5;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_SCHEME_FALSE;
f_7956(2,av2);}}}

/* k7954 in loop2 in loop */
static void C_ccall f_7956(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,4)))){
C_save_and_reclaim((void *)f_7956,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7962,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* expand.scm:507: comp-import */
t3=((C_word*)((C_word*)t0)[9])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_car(((C_word*)t0)[2]);
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_7995,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[10],a[6]=((C_word*)t0)[3],a[7]=((C_word*)t0)[4],a[8]=((C_word*)t0)[11],tmp=(C_word)a,a+=9,tmp);
/* expand.scm:512: ##sys#expand-0 */
t3=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[2];
av2[3]=((C_word*)t0)[12];
av2[4]=((C_word*)t0)[13];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}}

/* k7960 in k7954 in loop2 in loop */
static void C_ccall f_7962(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,3)))){
C_save_and_reclaim((void *)f_7962,c,av);}
a=C_alloc(8);
if(C_truep(t1)){
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],((C_word*)t0)[3]);
/* expand.scm:508: loop */
t3=((C_word*)((C_word*)t0)[4])[1];
f_7926(t3,((C_word*)t0)[5],((C_word*)t0)[6],t2);}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_7976,a[2]=((C_word*)t0)[5],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_7980,a[2]=t2,a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[8],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:511: scheme#reverse */
t4=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k7974 in k7960 in k7954 in loop2 in loop */
static void C_ccall f_7976(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_7976,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[103],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k7978 in k7960 in k7954 in loop2 in loop */
static void C_ccall f_7980(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_7980,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_7988,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:511: expand */
t3=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}

/* k7986 in k7978 in k7960 in k7954 in loop2 in loop */
static void C_ccall f_7988(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,3)))){
C_save_and_reclaim((void *)f_7988,c,av);}
a=C_alloc(3);
t2=C_a_i_list1(&a,1,t1);
/* expand.scm:511: ##sys#append */
t3=*((C_word*)lf[73]+1);{
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

/* k7993 in k7954 in loop2 in loop */
static void C_ccall f_7995(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_7995,c,av);}
a=C_alloc(13);
t2=C_eqp(((C_word*)t0)[2],t1);
if(C_truep(t2)){
t3=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8007,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_pairp(((C_word*)t0)[2]))){
if(C_truep(C_i_symbolp(C_u_i_car(((C_word*)t0)[2])))){
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8085,a[2]=t3,a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[2],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:519: comp */
t5=((C_word*)((C_word*)t0)[5])[1];
f_7776(t5,t4,lf[105],C_u_i_car(((C_word*)t0)[2]));}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_8007(2,av2);}}}
else{
t4=t3;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
f_8007(2,av2);}}}
else{
t3=C_a_i_cons(&a,2,t1,((C_word*)t0)[4]);
/* expand.scm:529: loop2 */
t4=((C_word*)((C_word*)t0)[8])[1];
f_7945(t4,((C_word*)t0)[3],t3);}}

/* k8005 in k7993 in k7954 in loop2 in loop */
static void C_ccall f_8007(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_8007,c,av);}
a=C_alloc(9);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8014,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8018,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=t2,a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:522: scheme#reverse */
t4=*((C_word*)lf[72]+1);{
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
t2=C_a_i_cons(&a,2,((C_word*)t0)[4],((C_word*)t0)[6]);
/* expand.scm:528: loop */
t3=((C_word*)((C_word*)t0)[7])[1];
f_7926(t3,((C_word*)t0)[2],((C_word*)t0)[3],t2);}}

/* k8012 in k8005 in k7993 in k7954 in loop2 in loop */
static void C_ccall f_8014(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_8014,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,lf[103],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k8016 in k8005 in k7993 in k7954 in loop2 in loop */
static void C_ccall f_8018(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_8018,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8025,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:523: comp */
t3=((C_word*)((C_word*)t0)[5])[1];
f_7776(t3,t2,lf[105],C_i_car(((C_word*)t0)[3]));}

/* k8023 in k8016 in k8005 in k7993 in k7954 in loop2 in loop */
static void C_ccall f_8025(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_8025,c,av);}
a=C_alloc(12);
if(C_truep(t1)){
if(C_truep(C_i_nullp(((C_word*)t0)[2]))){
t2=C_a_i_list(&a,1,((C_word*)t0)[3]);
/* expand.scm:521: ##sys#append */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t2=C_a_i_cons(&a,2,C_SCHEME_END_OF_LIST,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[51],t2);
t4=C_a_i_list(&a,2,((C_word*)t0)[3],t3);
/* expand.scm:521: ##sys#append */
t5=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}
else{
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8056,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],tmp=(C_word)a,a+=4,tmp);
t3=C_u_i_cdr(((C_word*)t0)[3]);
t4=C_a_i_list(&a,1,((C_word*)t0)[2]);
/* expand.scm:527: ##sys#append */
t5=*((C_word*)lf[73]+1);{
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
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k8054 in k8023 in k8016 in k8005 in k7993 in k7954 in loop2 in loop */
static void C_ccall f_8056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_8056,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,lf[104],t1);
t3=C_a_i_list(&a,1,t2);
/* expand.scm:521: ##sys#append */
t4=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[3];
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}

/* k8083 in k7993 in k7954 in loop2 in loop */
static void C_ccall f_8085(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8085,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_8007(2,av2);}}
else{
/* expand.scm:520: comp */
t2=((C_word*)((C_word*)t0)[3])[1];
f_7776(t2,((C_word*)t0)[2],lf[104],C_u_i_car(((C_word*)t0)[4]));}}

/* k8115 in loop2 in loop */
static void C_ccall f_8117(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_8117,c,av);}
a=C_alloc(7);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_7956(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8123,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:502: comp-define */
t3=((C_word*)((C_word*)t0)[7])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k8121 in k8115 in loop2 in loop */
static void C_ccall f_8123(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_8123,c,av);}
a=C_alloc(6);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_7956(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8129,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:503: comp-define-values */
t3=((C_word*)((C_word*)t0)[6])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k8127 in k8121 in k8115 in loop2 in loop */
static void C_ccall f_8129(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_8129,c,av);}
a=C_alloc(5);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_7956(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8135,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:504: comp-define-syntax */
t3=((C_word*)((C_word*)t0)[5])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k8133 in k8127 in k8121 in k8115 in loop2 in loop */
static void C_ccall f_8135(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8135,c,av);}
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
f_7956(2,av2);}}
else{
/* expand.scm:505: comp-import */
t2=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=((C_word*)t0)[4];
((C_proc)C_fast_retrieve_proc(t2))(3,av2);}}}

/* k8165 */
static void C_ccall f_8167(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8167,c,av);}
a=C_alloc(15);
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8170,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8309,a[2]=t4,a[3]=((C_word)li59),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_8309(t6,t2,t1,C_SCHEME_END_OF_LIST);}

/* k8168 in k8165 */
static void C_ccall f_8170(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(15,c,3)))){
C_save_and_reclaim((void *)f_8170,c,av);}
a=C_alloc(15);
t2=C_i_check_list_2(t1,lf[16]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8176,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8275,a[2]=((C_word*)t0)[7],a[3]=t5,a[4]=((C_word*)t0)[8],a[5]=((C_word)li57),tmp=(C_word)a,a+=6,tmp));
t7=((C_word*)t5)[1];
f_8275(t7,t3,t1);}

/* k8174 in k8168 in k8165 */
static void C_ccall f_8176(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(17,c,2)))){
C_save_and_reclaim((void *)f_8176,c,av);}
a=C_alloc(17);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8180,a[2]=t1,a[3]=((C_word*)t0)[2],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8202,a[2]=t2,a[3]=((C_word*)t0)[3],a[4]=t5,a[5]=t6,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:550: scheme#reverse */
t8=*((C_word*)lf[72]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t8;
av2[1]=t7;
av2[2]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t8+1)))(3,av2);}}

/* k8178 in k8174 in k8168 in k8165 */
static void C_ccall f_8180(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,1)))){
C_save_and_reclaim((void *)f_8180,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,((C_word*)t0)[2],t1);
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_a_i_cons(&a,2,lf[51],t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* k8200 in k8174 in k8168 in k8165 */
static void C_ccall f_8202(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_8202,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8205,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=t1,a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:551: scheme#reverse */
t3=*((C_word*)lf[72]+1);{
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

/* k8203 in k8200 in k8174 in k8168 in k8165 */
static void C_ccall f_8205(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_8205,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8208,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=t1,tmp=(C_word)a,a+=8,tmp);
/* expand.scm:552: scheme#reverse */
t3=*((C_word*)lf[72]+1);{
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

/* k8206 in k8203 in k8200 in k8174 in k8168 in k8165 */
static void C_ccall f_8208(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_8208,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8211,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8213,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=((C_word*)t0)[5],a[5]=((C_word)li56),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_8213(t6,t2,((C_word*)t0)[6],((C_word*)t0)[7],t1);}

/* k8209 in k8206 in k8203 in k8200 in k8174 in k8168 in k8165 */
static void C_ccall f_8211(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8211,c,av);}
/* expand.scm:534: ##sys#append */
t2=*((C_word*)lf[73]+1);{
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

/* map-loop1652 in k8206 in k8203 in k8200 in k8174 in k8168 in k8165 */
static void C_fcall f_8213(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_8213,5,t0,t1,t2,t3,t4);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8220,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=t2,a[6]=t3,a[7]=t4,a[8]=((C_word*)t0)[4],tmp=(C_word)a,a+=9,tmp);
if(C_truep(C_i_pairp(t2))){
t6=C_i_pairp(t3);
t7=t5;
f_8220(t7,(C_truep(t6)?C_i_pairp(t4):C_SCHEME_FALSE));}
else{
t6=t5;
f_8220(t6,C_SCHEME_FALSE);}}

/* k8218 in map-loop1652 in k8206 in k8203 in k8200 in k8174 in k8168 in k8165 */
static void C_fcall f_8220(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,0,3)))){
C_save_and_reclaim_args((void *)trf_8220,2,t0,t1);}
a=C_alloc(17);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8246,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
t3=C_slot(((C_word*)t0)[5],C_fix(0));
t4=C_slot(((C_word*)t0)[6],C_fix(0));
if(C_truep(C_slot(((C_word*)t0)[7],C_fix(0)))){
/* expand.scm:548: ##sys#expand-multiple-values-assignment */
t5=*((C_word*)lf[93]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t2;
av2[2]=t3;
av2[3]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
t5=C_i_car(t3);
t6=t2;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_a_i_list(&a,3,lf[96],t5,t4);
f_8246(2,av2);}}}
else{
t2=((C_word*)t0)[4];{
C_word av2[2];
av2[0]=t2;
av2[1]=C_slot(((C_word*)t0)[8],C_fix(1));
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k8244 in k8218 in map-loop1652 in k8206 in k8203 in k8200 in k8174 in k8168 in k8165 */
static void C_ccall f_8246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8246,c,av);}
a=C_alloc(3);
t2=C_a_i_cons(&a,2,t1,C_SCHEME_END_OF_LIST);
t3=C_i_setslot(((C_word*)((C_word*)t0)[2])[1],C_fix(1),t2);
t4=C_mutate(((C_word *)((C_word*)t0)[2])+1,t2);
t5=((C_word*)((C_word*)t0)[3])[1];
f_8213(t5,((C_word*)t0)[4],C_slot(((C_word*)t0)[5],C_fix(1)),C_slot(((C_word*)t0)[6],C_fix(1)),C_slot(((C_word*)t0)[7],C_fix(1)));}

/* map-loop1604 in k8168 in k8165 */
static void C_fcall f_8275(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8275,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_pairp(t2))){
t3=C_slot(t2,C_fix(0));
t4=C_a_i_list(&a,2,t3,lf[106]);
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

/* foldl1627 in k8165 */
static void C_fcall f_8309(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,5)))){
C_save_and_reclaim_args((void *)trf_8309,4,t0,t1,t2,t3);}
a=C_alloc(12);
if(C_truep(C_i_pairp(t2))){
t4=C_slot(t2,C_fix(1));
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8339,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
t6=C_slot(t2,C_fix(0));
t7=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8333,a[2]=t5,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t8=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8335,a[2]=((C_word)li58),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:539: ##sys#decompose-lambda-list */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[97]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[97]+1);
av2[1]=t7;
av2[2]=t6;
av2[3]=t8;
tp(4,av2);}}
else{
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k8331 in foldl1627 in k8165 */
static void C_ccall f_8333(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8333,c,av);}
/* expand.scm:539: ##sys#append */
t2=*((C_word*)lf[73]+1);{
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

/* a8334 in foldl1627 in k8165 */
static void C_ccall f_8335(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8335,c,av);}
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}

/* k8337 in foldl1627 in k8165 */
static void C_ccall f_8339(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8339,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_8309(t2,((C_word*)t0)[3],((C_word*)t0)[4],t1);}

/* f_8351 in k7910 in k7906 in k7902 in k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8351(C_word c,C_word *av){
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
if(c!=6) C_bad_argc_2(c,6,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_8351,c,av);}
a=C_alloc(14);
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8359,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=t3,a[6]=t4,tmp=(C_word)a,a+=7,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8361,a[2]=t8,a[3]=((C_word*)t0)[3],a[4]=((C_word)li62),tmp=(C_word)a,a+=5,tmp));
t10=((C_word*)t8)[1];
f_8361(t10,t6,t5,C_SCHEME_END_OF_LIST,C_SCHEME_FALSE);}

/* k8357 */
static void C_ccall f_8359(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_8359,c,av);}
/* expand.scm:557: fini */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=t1;
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* loop */
static void C_fcall f_8361(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_8361,5,t0,t1,t2,t3,t4);}
a=C_alloc(11);
if(C_truep(t4)){
t5=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t6=t5;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=((C_word*)t7)[1];
t9=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8383,a[2]=t2,a[3]=t1,a[4]=t7,a[5]=t8,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:561: scheme#reverse */
t10=*((C_word*)lf[72]+1);{
C_word av2[3];
av2[0]=t10;
av2[1]=t9;
av2[2]=t3;
((C_proc)(void*)(*((C_word*)t10+1)))(3,av2);}}
else{
t5=C_i_pairp(t2);
if(C_truep(C_i_not(t5))){
/* expand.scm:562: loop */
t12=t1;
t13=t2;
t14=t3;
t15=C_SCHEME_TRUE;
t1=t12;
t2=t13;
t3=t14;
t4=t15;
goto loop;}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8435,a[2]=t2,a[3]=t3,a[4]=((C_word*)t0)[2],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
t7=C_i_car(t2);
if(C_truep(C_i_listp(t7))){
t8=C_i_length(C_u_i_car(t2));
if(C_truep(C_fixnum_greater_or_equal_p(C_fix(3),t8))){
t9=C_i_caar(t2);
if(C_truep(C_i_symbolp(t9))){
t10=C_u_i_car(t2);
/* expand.scm:566: comp-define-syntax */
t11=((C_word*)((C_word*)t0)[3])[1];{
C_word av2[3];
av2[0]=t11;
av2[1]=t6;
av2[2]=C_u_i_car(t10);
((C_proc)C_fast_retrieve_proc(t11))(3,av2);}}
else{
t10=t6;{
C_word av2[2];
av2[0]=t10;
av2[1]=C_SCHEME_FALSE;
f_8435(2,av2);}}}
else{
t9=t6;{
C_word av2[2];
av2[0]=t9;
av2[1]=C_SCHEME_FALSE;
f_8435(2,av2);}}}
else{
t8=t6;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_SCHEME_FALSE;
f_8435(2,av2);}}}}}

/* k8381 in loop */
static void C_ccall f_8383(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8383,c,av);}
a=C_alloc(12);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8386,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8388,a[2]=((C_word*)t0)[4],a[3]=t4,a[4]=((C_word*)t0)[5],a[5]=((C_word)li61),tmp=(C_word)a,a+=6,tmp));
t6=((C_word*)t4)[1];
f_8388(t6,t2,t1);}

/* k8384 in k8381 in loop */
static void C_ccall f_8386(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_8386,c,av);}
a=C_alloc(9);
t2=C_a_i_cons(&a,2,t1,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,lf[107],t2);
t4=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_a_i_list(&a,1,t3);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* map-loop1712 in k8381 in loop */
static void C_fcall f_8388(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_8388,3,t0,t1,t2);}
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

/* k8433 in loop */
static void C_ccall f_8435(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(10,c,4)))){
C_save_and_reclaim((void *)f_8435,c,av);}
a=C_alloc(10);
if(C_truep(t1)){
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8439,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],tmp=(C_word)a,a+=7,tmp);
t4=C_i_car(t2);
t5=C_i_cadr(t2);
t6=C_eqp(t4,t5);
if(C_truep(t6)){
/* expand.scm:430: ##sys#syntax-error-hook */
t7=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=lf[108];
av2[3]=t2;
((C_proc)(void*)(*((C_word*)t7+1)))(4,av2);}}
else{
t7=C_u_i_cdr(((C_word*)t0)[2]);
t8=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
/* expand.scm:572: loop */
t9=((C_word*)((C_word*)t0)[4])[1];
f_8361(t9,((C_word*)t0)[5],t7,t8,C_SCHEME_FALSE);}}
else{
/* expand.scm:573: loop */
t2=((C_word*)((C_word*)t0)[4])[1];
f_8361(t2,((C_word*)t0)[5],((C_word*)t0)[2],((C_word*)t0)[3],C_SCHEME_TRUE);}}

/* k8437 in k8433 in loop */
static void C_ccall f_8439(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_8439,c,av);}
a=C_alloc(3);
t2=C_u_i_cdr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,((C_word*)t0)[3],((C_word*)t0)[4]);
/* expand.scm:572: loop */
t4=((C_word*)((C_word*)t0)[5])[1];
f_8361(t4,((C_word*)t0)[6],t2,t3,C_SCHEME_FALSE);}

/* f_8507 in k7910 in k7906 in k7902 in k7898 in k7763 in ##sys#canonicalize-body in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8507(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(14,c,6)))){
C_save_and_reclaim((void *)f_8507,c,av);}
a=C_alloc(14);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|11,a[1]=(C_word)f_8513,a[2]=((C_word*)t0)[2],a[3]=t4,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[9],a[11]=((C_word)li65),tmp=(C_word)a,a+=12,tmp));
t6=((C_word*)t4)[1];
f_8513(t6,t1,t2,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST,C_SCHEME_END_OF_LIST);}

/* loop */
static void C_fcall f_8513(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4,C_word t5){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,0,5)))){
C_save_and_reclaim_args((void *)trf_8513,6,t0,t1,t2,t3,t4,t5);}
a=C_alloc(18);
t6=C_i_pairp(t2);
if(C_truep(C_i_not(t6))){
/* expand.scm:582: fini */
t7=((C_word*)((C_word*)t0)[2])[1];{
C_word av2[6];
av2[0]=t7;
av2[1]=t1;
av2[2]=t3;
av2[3]=t4;
av2[4]=t5;
av2[5]=t2;
((C_proc)C_fast_retrieve_proc(t7))(6,av2);}}
else{
t7=C_i_car(t2);
t8=C_u_i_cdr(t2);
t9=C_i_pairp(t7);
t10=(C_truep(t9)?C_u_i_car(t7):C_SCHEME_FALSE);
t11=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_8536,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t3,a[5]=t4,a[6]=t5,a[7]=t2,a[8]=((C_word*)t0)[3],a[9]=t8,a[10]=((C_word*)t0)[4],a[11]=t7,a[12]=((C_word*)t0)[5],a[13]=((C_word*)t0)[6],a[14]=((C_word*)t0)[7],a[15]=((C_word*)t0)[8],a[16]=((C_word*)t0)[9],a[17]=((C_word*)t0)[10],tmp=(C_word)a,a+=18,tmp);
if(C_truep(t10)){
t12=C_i_symbolp(t10);
t13=t11;
f_8536(t13,(C_truep(t12)?t10:C_SCHEME_FALSE));}
else{
t12=t11;
f_8536(t12,C_SCHEME_FALSE);}}}

/* k8534 in loop */
static void C_fcall f_8536(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(18,0,5)))){
C_save_and_reclaim_args((void *)trf_8536,2,t0,t1);}
a=C_alloc(18);
t2=C_i_symbolp(t1);
if(C_truep(C_i_not(t2))){
/* expand.scm:588: fini */
t3=((C_word*)((C_word*)t0)[2])[1];{
C_word av2[6];
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t3))(6,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|17,a[1]=(C_word)f_8551,a[2]=((C_word*)t0)[4],a[3]=((C_word*)t0)[5],a[4]=((C_word*)t0)[6],a[5]=((C_word*)t0)[8],a[6]=((C_word*)t0)[9],a[7]=((C_word*)t0)[10],a[8]=((C_word*)t0)[3],a[9]=((C_word*)t0)[11],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[7],a[12]=t1,a[13]=((C_word*)t0)[2],a[14]=((C_word*)t0)[13],a[15]=((C_word*)t0)[14],a[16]=((C_word*)t0)[15],a[17]=((C_word*)t0)[16],tmp=(C_word)a,a+=18,tmp);
/* expand.scm:590: comp-define */
t4=((C_word*)((C_word*)t0)[17])[1];{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=t1;
((C_proc)C_fast_retrieve_proc(t4))(3,av2);}}}

/* k8549 in k8534 in loop */
static void C_ccall f_8551(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(17,c,6)))){
C_save_and_reclaim((void *)f_8551,c,av);}
a=C_alloc(17);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8554,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:591: ##sys#check-syntax */
t3=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[110];
av2[3]=((C_word*)t0)[9];
av2[4]=lf[115];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|16,a[1]=(C_word)f_8688,a[2]=((C_word*)t0)[10],a[3]=((C_word*)t0)[8],a[4]=((C_word*)t0)[2],a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[11],a[8]=((C_word*)t0)[9],a[9]=((C_word*)t0)[7],a[10]=((C_word*)t0)[5],a[11]=((C_word*)t0)[6],a[12]=((C_word*)t0)[12],a[13]=((C_word*)t0)[13],a[14]=((C_word*)t0)[14],a[15]=((C_word*)t0)[15],a[16]=((C_word*)t0)[16],tmp=(C_word)a,a+=17,tmp);
/* expand.scm:617: comp-define-syntax */
t3=((C_word*)((C_word*)t0)[17])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[12];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k8552 in k8549 in k8534 in loop */
static void C_ccall f_8554(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,c,3)))){
C_save_and_reclaim((void *)f_8554,c,av);}
a=C_alloc(12);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8559,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=t3,a[9]=((C_word)li64),tmp=(C_word)a,a+=10,tmp));
t5=((C_word*)t3)[1];
f_8559(t5,((C_word*)t0)[8],((C_word*)t0)[9]);}

/* loop2 in k8552 in k8549 in k8534 in loop */
static void C_fcall f_8559(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,0,6)))){
C_save_and_reclaim_args((void *)trf_8559,3,t0,t1,t2);}
a=C_alloc(10);
t3=C_i_cadr(t2);
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
t5=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8572,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=t1,a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:595: ##sys#check-syntax */
t6=*((C_word*)lf[55]+1);{
C_word av2[7];
av2[0]=t6;
av2[1]=t5;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[111];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t6+1)))(7,av2);}}
else{
t5=C_i_car(t3);
if(C_truep(C_i_pairp(t5))){
t6=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8625,a[2]=((C_word*)t0)[8],a[3]=t1,a[4]=t3,a[5]=t2,a[6]=((C_word*)t0)[7],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:605: ##sys#check-syntax */
t7=*((C_word*)lf[55]+1);{
C_word av2[7];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[113];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t7+1)))(7,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8639,a[2]=t3,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=t1,a[9]=((C_word*)t0)[6],tmp=(C_word)a,a+=10,tmp);
/* expand.scm:610: ##sys#check-syntax */
t7=*((C_word*)lf[55]+1);{
C_word av2[7];
av2[0]=t7;
av2[1]=t6;
av2[2]=lf[110];
av2[3]=t2;
av2[4]=lf[114];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[7];
((C_proc)(void*)(*((C_word*)t7+1)))(7,av2);}}}}

/* k8570 in loop2 in k8552 in k8549 in k8534 in loop */
static void C_ccall f_8572(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,3)))){
C_save_and_reclaim((void *)f_8572,c,av);}
a=C_alloc(10);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_8575,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[9],tmp=(C_word)a,a+=10,tmp);
t3=C_eqp(C_u_i_car(((C_word*)t0)[4]),((C_word*)t0)[2]);
if(C_truep(t3)){
/* expand.scm:430: ##sys#syntax-error-hook */
t4=*((C_word*)lf[42]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t4;
av2[1]=t2;
av2[2]=lf[108];
av2[3]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=t2;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_UNDEFINED;
f_8575(2,av2);}}}

/* k8573 in k8570 in loop2 in k8552 in k8549 in k8534 in loop */
static void C_ccall f_8575(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(12,c,5)))){
C_save_and_reclaim((void *)f_8575,c,av);}
a=C_alloc(12);
t2=C_a_i_list1(&a,1,((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
t4=C_i_cddr(((C_word*)t0)[4]);
if(C_truep(C_i_pairp(t4))){
t5=C_i_caddr(((C_word*)t0)[4]);
t6=C_a_i_cons(&a,2,t5,((C_word*)t0)[5]);
t7=C_a_i_cons(&a,2,C_SCHEME_FALSE,((C_word*)t0)[6]);
/* expand.scm:598: loop */
t8=((C_word*)((C_word*)t0)[7])[1];
f_8513(t8,((C_word*)t0)[8],((C_word*)t0)[9],t3,t6,t7);}
else{
t5=C_a_i_cons(&a,2,lf[109],((C_word*)t0)[5]);
t6=C_a_i_cons(&a,2,C_SCHEME_FALSE,((C_word*)t0)[6]);
/* expand.scm:598: loop */
t7=((C_word*)((C_word*)t0)[7])[1];
f_8513(t7,((C_word*)t0)[8],((C_word*)t0)[9],t3,t5,t6);}}

/* k8623 in loop2 in k8552 in k8549 in k8534 in loop */
static void C_ccall f_8625(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,4)))){
C_save_and_reclaim((void *)f_8625,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8632,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:608: chicken.syntax#expand-curried-define */
t3=*((C_word*)lf[112]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[4];
av2[3]=C_i_cddr(((C_word*)t0)[5]);
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k8630 in k8623 in loop2 in k8552 in k8549 in k8534 in loop */
static void C_ccall f_8632(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_8632,c,av);}
/* expand.scm:607: loop2 */
t2=((C_word*)((C_word*)t0)[2])[1];
f_8559(t2,((C_word*)t0)[3],t1);}

/* k8637 in loop2 in k8552 in k8549 in k8534 in loop */
static void C_ccall f_8639(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,5)))){
C_save_and_reclaim((void *)f_8639,c,av);}
a=C_alloc(18);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=C_a_i_list1(&a,1,t2);
t4=C_a_i_cons(&a,2,t3,((C_word*)t0)[3]);
t5=C_u_i_cdr(((C_word*)t0)[2]);
t6=C_i_cddr(((C_word*)t0)[4]);
t7=C_a_i_cons(&a,2,t5,t6);
t8=C_a_i_cons(&a,2,lf[75],t7);
t9=C_a_i_cons(&a,2,t8,((C_word*)t0)[5]);
t10=C_a_i_cons(&a,2,C_SCHEME_FALSE,((C_word*)t0)[6]);
/* expand.scm:613: loop */
t11=((C_word*)((C_word*)t0)[7])[1];
f_8513(t11,((C_word*)t0)[8],((C_word*)t0)[9],t4,t9,t10);}

/* k8686 in k8549 in k8534 in loop */
static void C_ccall f_8688(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(15,c,5)))){
C_save_and_reclaim((void *)f_8688,c,av);}
a=C_alloc(15);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_8691,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:618: ##sys#check-syntax */
t3=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[116];
av2[3]=((C_word*)t0)[8];
av2[4]=lf[117];
av2[5]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t3+1)))(6,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|14,a[1]=(C_word)f_8700,a[2]=((C_word*)t0)[8],a[3]=((C_word*)t0)[4],a[4]=((C_word*)t0)[5],a[5]=((C_word*)t0)[6],a[6]=((C_word*)t0)[10],a[7]=((C_word*)t0)[3],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[9],a[10]=((C_word*)t0)[12],a[11]=((C_word*)t0)[13],a[12]=((C_word*)t0)[7],a[13]=((C_word*)t0)[14],a[14]=((C_word*)t0)[15],tmp=(C_word)a,a+=15,tmp);
/* expand.scm:620: comp-define-values */
t3=((C_word*)((C_word*)t0)[16])[1];{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=((C_word*)t0)[12];
((C_proc)C_fast_retrieve_proc(t3))(3,av2);}}}

/* k8689 in k8686 in k8549 in k8534 in loop */
static void C_ccall f_8691(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_8691,c,av);}
/* expand.scm:619: fini/syntax */
t2=((C_word*)((C_word*)t0)[2])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[7];
((C_proc)C_fast_retrieve_proc(t2))(6,av2);}}

/* k8698 in k8686 in k8549 in k8534 in loop */
static void C_ccall f_8700(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,6)))){
C_save_and_reclaim((void *)f_8700,c,av);}
a=C_alloc(14);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_8703,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],a[8]=((C_word*)t0)[8],tmp=(C_word)a,a+=9,tmp);
/* expand.scm:622: ##sys#check-syntax */
t3=*((C_word*)lf[55]+1);{
C_word *av2;
if(c >= 7) {
  av2=av;
} else {
  av2=C_alloc(7);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[118];
av2[3]=((C_word*)t0)[2];
av2[4]=lf[119];
av2[5]=C_SCHEME_FALSE;
av2[6]=((C_word*)t0)[9];
((C_proc)(void*)(*((C_word*)t3+1)))(7,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|13,a[1]=(C_word)f_8732,a[2]=((C_word*)t0)[6],a[3]=((C_word*)t0)[7],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[2],a[8]=((C_word*)t0)[8],a[9]=((C_word*)t0)[10],a[10]=((C_word*)t0)[11],a[11]=((C_word*)t0)[12],a[12]=((C_word*)t0)[9],a[13]=((C_word*)t0)[13],tmp=(C_word)a,a+=14,tmp);
/* expand.scm:624: comp */
t3=((C_word*)((C_word*)t0)[14])[1];
f_7776(t3,t2,lf[103],((C_word*)t0)[10]);}}

/* k8701 in k8698 in k8686 in k8549 in k8534 in loop */
static void C_ccall f_8703(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,5)))){
C_save_and_reclaim((void *)f_8703,c,av);}
a=C_alloc(9);
t2=C_i_cadr(((C_word*)t0)[2]);
t3=C_a_i_cons(&a,2,t2,((C_word*)t0)[3]);
t4=C_i_caddr(((C_word*)t0)[2]);
t5=C_a_i_cons(&a,2,t4,((C_word*)t0)[4]);
t6=C_a_i_cons(&a,2,C_SCHEME_TRUE,((C_word*)t0)[5]);
/* expand.scm:623: loop */
t7=((C_word*)((C_word*)t0)[6])[1];
f_8513(t7,((C_word*)t0)[7],((C_word*)t0)[8],t3,t5,t6);}

/* k8730 in k8698 in k8686 in k8549 in k8534 in loop */
static void C_ccall f_8732(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(14,c,5)))){
C_save_and_reclaim((void *)f_8732,c,av);}
a=C_alloc(14);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_8739,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:625: ##sys#append */
t3=*((C_word*)lf[73]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=C_i_cdr(((C_word*)t0)[7]);
av2[3]=((C_word*)t0)[8];
((C_proc)(void*)(*((C_word*)t3+1)))(4,av2);}}
else{
t2=C_a_i_list1(&a,1,((C_word*)t0)[9]);
if(C_truep(C_i_member(t2,((C_word*)t0)[4]))){
/* expand.scm:630: fini */
t3=((C_word*)((C_word*)t0)[10])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=((C_word*)t0)[5];
av2[4]=((C_word*)t0)[6];
av2[5]=((C_word*)t0)[11];
((C_proc)C_fast_retrieve_proc(t3))(6,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_8755,a[2]=((C_word*)t0)[7],a[3]=((C_word*)t0)[10],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[11],a[9]=((C_word*)t0)[8],a[10]=((C_word*)t0)[2],tmp=(C_word)a,a+=11,tmp);
/* expand.scm:631: ##sys#expand-0 */
t4=*((C_word*)lf[32]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=((C_word*)t0)[7];
av2[3]=((C_word*)t0)[12];
av2[4]=((C_word*)t0)[13];
((C_proc)(void*)(*((C_word*)t4+1)))(5,av2);}}}}

/* k8737 in k8730 in k8698 in k8686 in k8549 in k8534 in loop */
static void C_ccall f_8739(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_8739,c,av);}
/* expand.scm:625: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_8513(t2,((C_word*)t0)[3],t1,((C_word*)t0)[4],((C_word*)t0)[5],((C_word*)t0)[6]);}

/* k8753 in k8730 in k8698 in k8686 in k8549 in k8534 in loop */
static void C_ccall f_8755(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,5)))){
C_save_and_reclaim((void *)f_8755,c,av);}
a=C_alloc(3);
t2=C_eqp(((C_word*)t0)[2],t1);
if(C_truep(t2)){
/* expand.scm:633: fini */
t3=((C_word*)((C_word*)t0)[3])[1];{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t3;
av2[1]=((C_word*)t0)[4];
av2[2]=((C_word*)t0)[5];
av2[3]=((C_word*)t0)[6];
av2[4]=((C_word*)t0)[7];
av2[5]=((C_word*)t0)[8];
((C_proc)C_fast_retrieve_proc(t3))(6,av2);}}
else{
t3=C_a_i_cons(&a,2,t1,((C_word*)t0)[9]);
/* expand.scm:634: loop */
t4=((C_word*)((C_word*)t0)[10])[1];
f_8513(t4,((C_word*)t0)[4],t3,((C_word*)t0)[5],((C_word*)t0)[6],((C_word*)t0)[7]);}}

/* chicken.syntax#match-expression in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8825(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(14,c,4)))){
C_save_and_reclaim((void *)f_8825,c,av);}
a=C_alloc(14);
t5=C_SCHEME_END_OF_LIST;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8828,a[2]=t6,a[3]=t4,a[4]=t8,a[5]=((C_word)li69),tmp=(C_word)a,a+=6,tmp));
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8905,a[2]=t6,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:655: mwalk */
t11=((C_word*)t8)[1];
f_8828(t11,t10,t2,t3);}

/* mwalk in chicken.syntax#match-expression in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_8828(C_word t0,C_word t1,C_word t2,C_word t3){
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
loop:
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_8828,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
t5=C_i_assq(t3,((C_word*)((C_word*)t0)[2])[1]);
if(C_truep(t5)){
t6=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8842,a[2]=t2,a[3]=((C_word)li68),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:646: g1809 */
t7=t1;{
C_word av2[2];
av2[0]=t7;
av2[1]=(
/* expand.scm:646: g1809 */
  f_8842(t6,t5)
);
((C_proc)(void*)(*((C_word*)t7+1)))(2,av2);}}
else{
if(C_truep(C_i_memq(t3,((C_word*)t0)[3]))){
t6=C_a_i_cons(&a,2,t3,t2);
t7=C_a_i_cons(&a,2,t6,((C_word*)((C_word*)t0)[2])[1]);
t8=C_mutate(((C_word *)((C_word*)t0)[2])+1,t7);
t9=t1;{
C_word av2[2];
av2[0]=t9;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}
else{
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_eqp(t2,t3);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}}
else{
if(C_truep(C_i_pairp(t2))){
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_8882,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:652: mwalk */
t10=t5;
t11=C_u_i_car(t2);
t12=C_i_car(t3);
t1=t10;
t2=t11;
t3=t12;
goto loop;}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}}

/* g1809 in mwalk in chicken.syntax#match-expression in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_8842(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_stack_overflow_check;{}
return(C_i_equalp(((C_word*)t0)[2],C_i_cdr(t1)));}

/* k8880 in mwalk in chicken.syntax#match-expression in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8882(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_8882,c,av);}
if(C_truep(t1)){
/* expand.scm:653: mwalk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_8828(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_u_i_cdr(((C_word*)t0)[5]));}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* k8903 in chicken.syntax#match-expression in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8905(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_8905,c,av);}
if(C_truep(t1)){
t2=((C_word*)((C_word*)t0)[2])[1];
t3=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* chicken.syntax#expand-curried-define in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8907(C_word c,C_word *av){
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
C_word *a;
if(c!=5) C_bad_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand(13,c,4)))){
C_save_and_reclaim((void *)f_8907,c,av);}
a=C_alloc(13);
t5=C_SCHEME_FALSE;
t6=(*a=C_VECTOR_TYPE|1,a[1]=t5,tmp=(C_word)a,a+=2,tmp);
t7=C_SCHEME_UNDEFINED;
t8=(*a=C_VECTOR_TYPE|1,a[1]=t7,tmp=(C_word)a,a+=2,tmp);
t9=C_set_block_item(t8,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_8910,a[2]=t6,a[3]=t8,a[4]=((C_word)li71),tmp=(C_word)a,a+=5,tmp));
t10=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8954,a[2]=t1,a[3]=t6,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:669: loop */
t11=((C_word*)t8)[1];
f_8910(t11,t10,t2,t3);}

/* loop in chicken.syntax#expand-curried-define in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_8910(C_word t0,C_word t1,C_word t2,C_word t3){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,0,3)))){
C_save_and_reclaim_args((void *)trf_8910,4,t0,t1,t2,t3);}
a=C_alloc(9);
t4=C_i_car(t2);
if(C_truep(C_i_symbolp(t4))){
t5=C_mutate(((C_word *)((C_word*)t0)[2])+1,C_u_i_car(t2));
t6=C_u_i_cdr(t2);
t7=C_a_i_cons(&a,2,t6,t3);
t8=t1;{
C_word av2[2];
av2[0]=t8;
av2[1]=C_a_i_cons(&a,2,lf[75],t7);
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}
else{
t5=C_u_i_car(t2);
t6=C_u_i_cdr(t2);
t7=C_a_i_cons(&a,2,t6,t3);
t8=C_a_i_cons(&a,2,lf[75],t7);
t9=C_a_i_list(&a,1,t8);
/* expand.scm:668: loop */
t11=t1;
t12=t5;
t13=t9;
t1=t11;
t2=t12;
t3=t13;
goto loop;}}

/* k8952 in chicken.syntax#expand-curried-define in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8954(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,1)))){
C_save_and_reclaim((void *)f_8954,c,av);}
a=C_alloc(9);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_list3(&a,3,lf[110],((C_word*)((C_word*)t0)[3])[1],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* chicken.syntax#syntax-error in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8962(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand((c-2)*C_SIZEOF_PAIR +3,c,2)))){
C_save_and_reclaim((void*)f_8962,c,av);}
a=C_alloc((c-2)*C_SIZEOF_PAIR+3);
t2=C_build_rest(&a,c,2,av);
C_word t3;
C_word t4;
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8970,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:684: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
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

/* k8968 in chicken.syntax#syntax-error in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8970(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_8970,c,av);}{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=0;
av2[1]=((C_word*)t0)[2];
av2[2]=*((C_word*)lf[125]+1);
av2[3]=lf[126];
av2[4]=t1;
C_apply(5,av2);}}

/* ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8973(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4;
C_word t5;
C_word *a;
if(c!=4) C_bad_argc_2(c,4,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_8973,c,av);}
a=C_alloc(5);
if(C_truep(C_i_nullp(*((C_word*)lf[123]+1)))){
/* expand.scm:697: ##sys#syntax-error-hook */
t4=*((C_word*)lf[42]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t1;
av2[2]=t2;
av2[3]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9040,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:698: chicken.base#open-output-string */
t5=*((C_word*)lf[144]+1);{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k8982 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_8984(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_8984,c,av);}
a=C_alloc(6);
t2=(C_truep(t1)?t1:C_SCHEME_END_OF_LIST);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_8989,a[2]=t4,a[3]=((C_word)li76),tmp=(C_word)a,a+=4,tmp));
t6=((C_word*)t4)[1];
f_8989(t6,((C_word*)t0)[2],t2);}

/* loop in k8982 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_8989(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_8989,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=C_i_caar(t2);
t4=C_eqp(lf[142],t3);
if(C_truep(t4)){
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9009,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:694: scheme#cadar */
t6=*((C_word*)lf[71]+1);{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
/* expand.scm:695: loop */
t7=t1;
t8=C_u_i_cdr(t2);
t1=t7;
t2=t8;
goto loop;}}}

/* k9007 in loop in k8982 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9009(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9009,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9013,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:694: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_8989(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k9011 in k9007 in loop in k8982 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9013(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,1)))){
C_save_and_reclaim((void *)f_9013,c,av);}
a=C_alloc(3);
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_a_i_cons(&a,2,((C_word*)t0)[3],t1);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9026 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9028(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9028,c,av);}
/* expand.scm:691: ##sys#get */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[62]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[62]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
av2[3]=lf[143];
tp(4,av2);}}

/* k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9040(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(18,c,3)))){
C_save_and_reclaim((void *)f_9040,c,av);}
a=C_alloc(18);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9042,a[2]=t1,a[3]=((C_word)li74),tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9049,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9058,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=t5,a[7]=((C_word)li77),tmp=(C_word)a,a+=8,tmp));
t7=((C_word*)t5)[1];
f_9058(t7,t3,*((C_word*)lf[123]+1));}

/* outstr in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9042(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,4)))){
C_save_and_reclaim_args((void *)trf_9042,3,t0,t1,t2);}
/* expand.scm:700: ##sys#print */
t3=*((C_word*)lf[128]+1);{
C_word av2[5];
av2[0]=t3;
av2[1]=t1;
av2[2]=t2;
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[2];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k9047 in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9049(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9049,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9056,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
/* expand.scm:735: chicken.base#get-output-string */
t3=*((C_word*)lf[129]+1);{
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

/* k9054 in k9047 in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9056(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9056,c,av);}
/* expand.scm:735: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
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

/* loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9058(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,0,2)))){
C_save_and_reclaim_args((void *)trf_9058,3,t0,t1,t2);}
a=C_alloc(9);
if(C_truep(C_i_nullp(t2))){
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9068,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:703: outstr */
t4=((C_word*)t0)[2];
f_9042(t4,t3,((C_word*)t0)[5]);}
else{
t3=(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9094,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=t2,tmp=(C_word)a,a+=9,tmp);
/* expand.scm:710: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k9066 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9068(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,2)))){
C_save_and_reclaim((void *)f_9068,c,av);}
a=C_alloc(6);
t2=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9071,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:704: outstr */
t3=((C_word*)t0)[2];
f_9042(t3,t2,lf[132]);}

/* k9069 in k9066 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9071(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_9071,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9074,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:705: ##sys#print */
t3=*((C_word*)lf[128]+1);{
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

/* k9072 in k9069 in k9066 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9074(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_9074,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9077,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:706: outstr */
t3=((C_word*)t0)[2];
f_9042(t3,t2,lf[131]);}

/* k9075 in k9072 in k9069 in k9066 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9077(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9077,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9080,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9087,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:707: chicken.syntax#strip-syntax */
t4=*((C_word*)lf[11]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(*((C_word*)lf[123]+1));
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k9078 in k9075 in k9072 in k9069 in k9066 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9080(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9080,c,av);}
/* expand.scm:708: outstr */
t2=((C_word*)t0)[2];
f_9042(t2,((C_word*)t0)[3],lf[130]);}

/* k9085 in k9075 in k9072 in k9069 in k9066 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9087(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9087,c,av);}
/* expand.scm:707: ##sys#print */
t2=*((C_word*)lf[128]+1);{
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

/* k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9094(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(16,c,2)))){
C_save_and_reclaim((void *)f_9094,c,av);}
a=C_alloc(16);
t2=(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9097,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t1,a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word*)t0)[8],tmp=(C_word)a,a+=10,tmp);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_8984,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9028,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:691: chicken.syntax#strip-syntax */
t5=*((C_word*)lf[11]+1);{
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

/* k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9097(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9097,c,av);}
a=C_alloc(8);
if(C_truep(C_i_pairp(t1))){
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9106,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:713: outstr */
t3=((C_word*)t0)[2];
f_9042(t3,t2,((C_word*)t0)[7]);}
else{
/* expand.scm:734: loop */
t2=((C_word*)((C_word*)t0)[8])[1];
f_9058(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[9]));}}

/* k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9106(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(8,c,2)))){
C_save_and_reclaim((void *)f_9106,c,av);}
a=C_alloc(8);
t2=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9109,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],a[7]=((C_word*)t0)[7],tmp=(C_word)a,a+=8,tmp);
/* expand.scm:714: outstr */
t3=((C_word*)t0)[3];
f_9042(t3,t2,lf[141]);}

/* k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9109(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,4)))){
C_save_and_reclaim((void *)f_9109,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9112,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:715: ##sys#print */
t3=*((C_word*)lf[128]+1);{
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

/* k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9112(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,c,2)))){
C_save_and_reclaim((void *)f_9112,c,av);}
a=C_alloc(7);
t2=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9115,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=((C_word*)t0)[5],a[6]=((C_word*)t0)[6],tmp=(C_word)a,a+=7,tmp);
/* expand.scm:716: outstr */
t3=((C_word*)t0)[3];
f_9042(t3,t2,lf[140]);}

/* k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9115(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_9115,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9118,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:717: ##sys#print */
t3=*((C_word*)lf[128]+1);{
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
av2[4]=((C_word*)t0)[6];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9118(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,2)))){
C_save_and_reclaim((void *)f_9118,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9121,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:718: outstr */
t3=((C_word*)t0)[3];
f_9042(t3,t2,lf[139]);}

/* k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9121(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9121,c,av);}
a=C_alloc(13);
t2=C_i_length(((C_word*)t0)[2]);
t3=C_eqp(C_fix(1),t2);
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9134,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9138,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:723: scheme#symbol->string */
t6=*((C_word*)lf[45]+1);{
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=C_i_car(((C_word*)t0)[2]);
((C_proc)(void*)(*((C_word*)t6+1)))(3,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9149,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
t5=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9153,a[2]=t4,tmp=(C_word)a,a+=3,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9155,a[2]=t7,a[3]=((C_word)li75),tmp=(C_word)a,a+=4,tmp));
t9=((C_word*)t7)[1];
f_9155(t9,t5,((C_word*)t0)[2]);}}

/* k9132 in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9134(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9134,c,av);}
/* expand.scm:720: outstr */
t2=((C_word*)t0)[2];
f_9042(t2,((C_word*)t0)[3],t1);}

/* k9136 in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9138(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9138,c,av);}
/* expand.scm:721: scheme#string-append */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[133];
av2[3]=t1;
av2[4]=lf[134];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k9147 in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9149(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9149,c,av);}
/* expand.scm:725: outstr */
t2=((C_word*)t0)[2];
f_9042(t2,((C_word*)t0)[3],t1);}

/* k9151 in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9153(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9153,c,av);}
/* expand.scm:726: scheme#string-append */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[135];
av2[3]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(4,av2);}}

/* loop in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9155(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9155,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_nullp(t2))){
t3=t1;{
C_word av2[2];
av2[0]=t3;
av2[1]=lf[136];
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9169,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:732: scheme#symbol->string */
t4=*((C_word*)lf[45]+1);{
C_word av2[3];
av2[0]=t4;
av2[1]=t3;
av2[2]=C_i_car(t2);
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}}

/* k9167 in loop in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9169(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9169,c,av);}
a=C_alloc(4);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9173,a[2]=((C_word*)t0)[2],a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:733: loop */
t3=((C_word*)((C_word*)t0)[3])[1];
f_9155(t3,t2,C_u_i_cdr(((C_word*)t0)[4]));}

/* k9171 in k9167 in loop in k9119 in k9116 in k9113 in k9110 in k9107 in k9104 in k9095 in k9092 in loop in k9038 in ##sys#syntax-error/context in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9173(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_9173,c,av);}
/* expand.scm:731: scheme#string-append */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[137];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[138];
av2[5]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* chicken.syntax#assq/drop-bwp! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9200(C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,4)))){
C_save_and_reclaim_args((void *)trf_9200,3,t1,t2,t3);}
a=C_alloc(7);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9206,a[2]=t2,a[3]=t5,a[4]=((C_word)li79),tmp=(C_word)a,a+=5,tmp));
t7=((C_word*)t5)[1];
f_9206(t7,t1,t3,C_SCHEME_FALSE);}

/* lp in chicken.syntax#assq/drop-bwp! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9206(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9206,4,t0,t1,t2,t3);}
a=C_alloc(6);
if(C_truep(C_i_nullp(t2))){
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}
else{
t4=C_i_caar(t2);
t5=C_eqp(((C_word*)t0)[2],t4);
if(C_truep(t5)){
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=C_u_i_car(t2);
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9226,a[2]=t3,a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=t1,tmp=(C_word)a,a+=6,tmp);
if(C_truep(t3)){
t7=C_u_i_car(t2);
t8=t6;
f_9226(t8,C_bwpp(C_u_i_car(t7)));}
else{
t7=t6;
f_9226(t7,C_SCHEME_FALSE);}}}}

/* k9224 in lp in chicken.syntax#assq/drop-bwp! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9226(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_9226,2,t0,t1);}
if(C_truep(t1)){
t2=C_i_set_cdr(((C_word*)t0)[2],C_u_i_cdr(((C_word*)t0)[3]));
/* expand.scm:750: lp */
t3=((C_word*)((C_word*)t0)[4])[1];
f_9206(t3,((C_word*)t0)[5],C_u_i_cdr(((C_word*)t0)[3]),((C_word*)t0)[2]);}
else{
/* expand.scm:751: lp */
t2=((C_word*)((C_word*)t0)[4])[1];
f_9206(t2,((C_word*)t0)[5],C_u_i_cdr(((C_word*)t0)[3]),((C_word*)t0)[3]);}}

/* chicken.syntax#read-with-source-info-hook in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9250(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_9250,c,av);}
a=C_alloc(9);
t5=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9254,a[2]=t1,a[3]=t3,tmp=(C_word)a,a+=4,tmp);
t6=C_eqp(lf[147],t2);
t7=(C_truep(t6)?C_i_symbolp(C_i_car(t3)):C_SCHEME_FALSE);
if(C_truep(t7)){
t8=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9260,a[2]=t3,a[3]=t5,a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:755: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[152]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[152]+1);
av2[1]=t8;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=C_i_car(t3);
tp(4,av2);}}
else{
t8=t1;{
C_word *av2=av;
av2[0]=t8;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t8+1)))(2,av2);}}}

/* k9252 in chicken.syntax#read-with-source-info-hook in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9254(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9254,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* k9258 in chicken.syntax#read-with-source-info-hook in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9260(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,3)))){
C_save_and_reclaim((void *)f_9260,c,av);}
a=C_alloc(6);
t2=(C_truep(t1)?t1:C_SCHEME_END_OF_LIST);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9266,a[2]=((C_word*)t0)[2],a[3]=t2,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:756: assq/drop-bwp! */
f_9200(t3,C_u_i_car(((C_word*)t0)[2]),t2);}

/* k9264 in k9258 in chicken.syntax#read-with-source-info-hook in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9266(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_9266,c,av);}
a=C_alloc(6);
t2=C_u_i_car(((C_word*)t0)[2]);
t3=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9279,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],a[5]=t2,tmp=(C_word)a,a+=6,tmp);
t4=*((C_word*)lf[2]+1);
if(C_truep(*((C_word*)lf[2]+1))){
t5=*((C_word*)lf[2]+1);
t6=*((C_word*)lf[2]+1);
/* expand.scm:761: chicken.string#conc */
t7=*((C_word*)lf[149]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t7;
av2[1]=t3;
av2[2]=*((C_word*)lf[2]+1);
av2[3]=lf[150];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t7+1)))(5,av2);}}
else{
/* expand.scm:761: chicken.string#conc */
t5=*((C_word*)lf[149]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t5;
av2[1]=t3;
av2[2]=lf[151];
av2[3]=lf[150];
av2[4]=((C_word*)t0)[5];
((C_proc)(void*)(*((C_word*)t5+1)))(5,av2);}}}

/* k9277 in k9264 in k9258 in chicken.syntax#read-with-source-info-hook in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9279(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,4)))){
C_save_and_reclaim((void *)f_9279,c,av);}
a=C_alloc(6);
t2=C_a_i_cons(&a,2,C_a_i_weak_cons(&a,2,((C_word*)t0)[2],t1),((C_word*)t0)[3]);
/* expand.scm:757: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[148]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[148]+1);
av2[1]=((C_word*)t0)[4];
av2[2]=*((C_word*)lf[121]+1);
av2[3]=((C_word*)t0)[5];
av2[4]=t2;
tp(5,av2);}}

/* chicken.syntax#read-with-source-info in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9301(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_9301,c,av);}
a=C_alloc(4);
t2=C_rest_nullp(c,2);
t3=(C_truep(t2)?*((C_word*)lf[154]+1):C_get_rest_arg(c,2,av,2,t0));
if(C_truep(*((C_word*)lf[121]+1))){
t4=C_i_check_port_2(t3,C_fix(1),C_SCHEME_TRUE,lf[155]);
/* expand.scm:772: ##sys#read */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[156]+1);
av2[1]=t1;
av2[2]=t3;
av2[3]=lf[146];
tp(4,av2);}}
else{
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9318,a[2]=t3,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:770: scheme#make-vector */
t5=*((C_word*)lf[12]+1);{
C_word av2[4];
av2[0]=t5;
av2[1]=t4;
av2[2]=C_fix(997);
av2[3]=C_SCHEME_END_OF_LIST;
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}}

/* k9316 in chicken.syntax#read-with-source-info in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9318(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9318,c,av);}
t2=C_mutate((C_word*)lf[121]+1 /* (set! ##sys#line-number-database ...) */,t1);
t3=C_i_check_port_2(((C_word*)t0)[2],C_fix(1),C_SCHEME_TRUE,lf[155]);
/* expand.scm:772: ##sys#read */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[156]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[156]+1);
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[2];
av2[3]=lf[146];
tp(4,av2);}}

/* chicken.syntax#get-line-number in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9326(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_9326,c,av);}
a=C_alloc(4);
if(C_truep(*((C_word*)lf[121]+1))){
if(C_truep(C_i_pairp(t2))){
t3=C_u_i_car(t2);
if(C_truep(C_i_symbolp(t3))){
t4=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9346,a[2]=t2,a[3]=t1,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:780: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[152]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[152]+1);
av2[1]=t4;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=t3;
tp(4,av2);}}
else{
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}
else{
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* k9344 in chicken.syntax#get-line-number in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9346(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_9346,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9350,a[2]=((C_word*)t0)[2],a[3]=((C_word)li83),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:780: g1942 */
t3=t2;
f_9350(t3,((C_word*)t0)[3],t1);}
else{
t2=((C_word*)t0)[3];{
C_word *av2=av;
av2[0]=t2;
av2[1]=C_SCHEME_FALSE;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}}

/* g1942 in k9344 in chicken.syntax#get-line-number in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9350(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,0,3)))){
C_save_and_reclaim_args((void *)trf_9350,3,t0,t1,t2);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9354,a[2]=t1,tmp=(C_word)a,a+=3,tmp);
/* expand.scm:782: assq/drop-bwp! */
f_9200(t3,((C_word*)t0)[2],t2);}

/* k9352 in g1942 in k9344 in chicken.syntax#get-line-number in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9354(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9354,c,av);}
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=(C_truep(t1)?C_i_cdr(t1):C_SCHEME_FALSE);
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}

/* ##sys#get-line-2 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9365(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_9365,c,av);}
a=C_alloc(5);
t3=C_i_car(t2);
t4=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9372,a[2]=t1,a[3]=t3,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:789: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[152]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[152]+1);
av2[1]=t4;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=t3;
tp(4,av2);}}

/* k9370 in ##sys#get-line-2 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9372(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,3)))){
C_save_and_reclaim((void *)f_9372,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9375,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],tmp=(C_word)a,a+=5,tmp);
if(C_truep(t1)){
/* expand.scm:790: assq/drop-bwp! */
f_9200(t2,((C_word*)t0)[4],C_i_cdr(t1));}
else{
t3=t2;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_SCHEME_FALSE;
f_9375(2,av2);}}}

/* k9373 in k9370 in ##sys#get-line-2 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9375(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(4,c,3)))){
C_save_and_reclaim((void *)f_9375,c,av);}
a=C_alloc(4);
if(C_truep(t1)){
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9379,a[2]=((C_word*)t0)[2],a[3]=((C_word)li85),tmp=(C_word)a,a+=4,tmp);
/* expand.scm:790: g1958 */
t3=t2;
f_9379(t3,((C_word*)t0)[3],t1);}
else{
/* expand.scm:792: scheme#values */{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=0;
av2[1]=((C_word*)t0)[3];
av2[2]=((C_word*)t0)[4];
av2[3]=C_SCHEME_FALSE;
C_values(4,av2);}}}

/* g1958 in k9373 in k9370 in ##sys#get-line-2 in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9379(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,0,3)))){
C_save_and_reclaim_args((void *)trf_9379,3,t0,t1,t2);}
/* expand.scm:791: scheme#values */{
C_word av2[4];
av2[0]=0;
av2[1]=t1;
av2[2]=C_i_car(((C_word*)t0)[2]);
av2[3]=C_i_cdr(t2);
C_values(4,av2);}}

/* ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9406(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(c!=2) C_bad_argc_2(c,2,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_9406,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9412,a[2]=((C_word)li88),tmp=(C_word)a,a+=3,tmp);
/* expand.scm:795: chicken.internal#hash-table-for-each */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[163]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[163]+1);
av2[1]=t1;
av2[2]=t2;
av2[3]=*((C_word*)lf[121]+1);
tp(4,av2);}}

/* a9411 in ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9412(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_9412,c,av);}
a=C_alloc(5);
if(C_truep(t3)){
t4=*((C_word*)lf[160]+1);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9419,a[2]=t1,a[3]=t4,a[4]=t3,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:799: ##sys#print */
t6=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
av2[3]=C_SCHEME_TRUE;
av2[4]=*((C_word*)lf[160]+1);
((C_proc)(void*)(*((C_word*)t6+1)))(5,av2);}}
else{
t4=C_SCHEME_UNDEFINED;
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}

/* k9417 in a9411 in ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9419(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,c,4)))){
C_save_and_reclaim((void *)f_9419,c,av);}
a=C_alloc(5);
t2=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9422,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:800: ##sys#print */
t3=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t3;
av2[1]=t2;
av2[2]=lf[162];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t3+1)))(5,av2);}}

/* k9420 in k9417 in a9411 in ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9422(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9422,c,av);}
a=C_alloc(21);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9425,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t3=C_a_i_cons(&a,2,C_SCHEME_UNDEFINED,C_SCHEME_END_OF_LIST);
t4=t3;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=((C_word*)t5)[1];
t7=C_i_check_list_2(((C_word*)t0)[4],lf[16]);
t8=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9438,a[2]=t2,a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
t9=C_SCHEME_UNDEFINED;
t10=(*a=C_VECTOR_TYPE|1,a[1]=t9,tmp=(C_word)a,a+=2,tmp);
t11=C_set_block_item(t10,0,(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9440,a[2]=t5,a[3]=t10,a[4]=t6,a[5]=((C_word)li87),tmp=(C_word)a,a+=6,tmp));
t12=((C_word*)t10)[1];
f_9440(t12,t8,((C_word*)t0)[4]);}

/* k9423 in k9420 in k9417 in a9411 in ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9425(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9425,c,av);}
/* expand.scm:802: ##sys#print */
t2=*((C_word*)lf[128]+1);{
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[161];
av2[3]=C_SCHEME_FALSE;
av2[4]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(5,av2);}}

/* k9436 in k9420 in k9417 in a9411 in ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9438(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,4)))){
C_save_and_reclaim((void *)f_9438,c,av);}
/* expand.scm:801: ##sys#print */
t2=*((C_word*)lf[128]+1);{
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

/* map-loop1967 in k9420 in k9417 in a9411 in ##sys#display-line-number-database in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9440(C_word t0,C_word t1,C_word t2){
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
C_save_and_reclaim_args((void *)trf_9440,3,t0,t1,t2);}
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

/* ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9474(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(13,c,3)))){
C_save_and_reclaim((void *)f_9474,c,av);}
a=C_alloc(13);
t4=C_SCHEME_UNDEFINED;
t5=(*a=C_VECTOR_TYPE|1,a[1]=t4,tmp=(C_word)a,a+=2,tmp);
t6=C_SCHEME_UNDEFINED;
t7=(*a=C_VECTOR_TYPE|1,a[1]=t6,tmp=(C_word)a,a+=2,tmp);
t8=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9477,a[2]=t7,a[3]=((C_word)li91),tmp=(C_word)a,a+=4,tmp));
t9=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9502,a[2]=t5,a[3]=t3,a[4]=((C_word)li92),tmp=(C_word)a,a+=5,tmp));
/* expand.scm:822: walk */
t10=((C_word*)t7)[1];
f_9502(t10,t1,t2);}

/* mapupdate in ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9477(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_9477,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_SCHEME_UNDEFINED;
t4=(*a=C_VECTOR_TYPE|1,a[1]=t3,tmp=(C_word)a,a+=2,tmp);
t5=C_set_block_item(t4,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9483,a[2]=t4,a[3]=((C_word*)t0)[2],a[4]=((C_word)li90),tmp=(C_word)a,a+=5,tmp));
t6=((C_word*)t4)[1];
f_9483(t6,t1,t2);}

/* loop in mapupdate in ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9483(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9483,3,t0,t1,t2);}
a=C_alloc(5);
if(C_truep(C_i_pairp(t2))){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9493,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:811: walk */
t4=((C_word*)((C_word*)t0)[3])[1];
f_9502(t4,t3,C_u_i_car(t2));}
else{
t3=C_SCHEME_UNDEFINED;
t4=t1;{
C_word av2[2];
av2[0]=t4;
av2[1]=t3;
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9491 in loop in mapupdate in ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9493(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9493,c,av);}
/* expand.scm:812: loop */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9483(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* walk in ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9502(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word t8;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(7,0,3)))){
C_save_and_reclaim_args((void *)trf_9502,3,t0,t1,t2);}
a=C_alloc(7);
t3=C_i_pairp(t2);
t4=C_i_not(t3);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=t4;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_i_car(t2);
if(C_truep(C_i_symbolp(t5))){
t6=C_u_i_car(t2);
t7=(*a=C_CLOSURE_TYPE|6,a[1]=(C_word)f_9519,a[2]=((C_word*)t0)[2],a[3]=t1,a[4]=t2,a[5]=((C_word*)t0)[3],a[6]=t6,tmp=(C_word)a,a+=7,tmp);
/* expand.scm:817: chicken.internal#hash-table-ref */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[152]+1));
C_word av2[4];
av2[0]=*((C_word*)lf[152]+1);
av2[1]=t7;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=t6;
tp(4,av2);}}
else{
/* expand.scm:821: mapupdate */
t6=((C_word*)((C_word*)t0)[2])[1];
f_9477(t6,t1,t2);}}}

/* k9517 in walk in ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9519(C_word c,C_word *av){
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
C_save_and_reclaim((void *)f_9519,c,av);}
a=C_alloc(11);
t2=(C_truep(t1)?t1:C_SCHEME_END_OF_LIST);
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9525,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
if(C_truep(C_i_assq(((C_word*)t0)[4],t2))){
/* expand.scm:820: mapupdate */
t4=((C_word*)((C_word*)t0)[2])[1];
f_9477(t4,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}
else{
t4=C_a_i_cons(&a,2,((C_word*)t0)[4],((C_word*)t0)[5]);
t5=C_a_i_cons(&a,2,t4,t2);
/* expand.scm:819: chicken.internal#hash-table-set! */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[148]+1));
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[148]+1);
av2[1]=t3;
av2[2]=*((C_word*)lf[121]+1);
av2[3]=((C_word*)t0)[6];
av2[4]=t5;
tp(5,av2);}}}

/* k9523 in k9517 in walk in ##sys#update-line-number-database! in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9525(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9525,c,av);}
/* expand.scm:820: mapupdate */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9477(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]));}

/* ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9556(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5;
C_word *a;
if(c<5) C_bad_min_argc_2(c,5,t0);
if(C_unlikely(!C_demand(C_calculate_demand((c-5)*C_SIZEOF_PAIR +8,c,2)))){
C_save_and_reclaim((void*)f_9556,c,av);}
a=C_alloc((c-5)*C_SIZEOF_PAIR+8);
t5=C_build_rest(&a,c,5,av);
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word t10;
C_word t11;
t6=C_rest_nullp(c,5);
t7=(C_truep(t6)?C_SCHEME_FALSE:C_get_rest_arg(c,5,av,5,t0));
t8=C_rest_nullp(c,5);
t9=(C_truep(t8)?C_SCHEME_END_OF_LIST:C_i_cdr(t5));
t10=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9566,a[2]=t9,a[3]=t3,a[4]=t2,a[5]=t1,a[6]=t4,a[7]=t7,tmp=(C_word)a,a+=8,tmp);
if(C_truep(C_i_nullp(t9))){
/* expand.scm:828: ##sys#current-environment */
t11=*((C_word*)lf[3]+1);{
C_word *av2=av;
av2[0]=t11;
av2[1]=t10;
((C_proc)(void*)(*((C_word*)t11+1)))(2,av2);}}
else{
t11=t10;{
C_word *av2=av;
av2[0]=t11;
av2[1]=C_i_car(t9);
f_9566(2,av2);}}}

/* k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9566(C_word c,C_word *av){
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
if(C_unlikely(!C_demand(C_calculate_demand(39,c,5)))){
C_save_and_reclaim((void *)f_9566,c,av);}
a=C_alloc(39);
t2=C_i_nullp(((C_word*)t0)[2]);
t3=(C_truep(t2)?C_SCHEME_END_OF_LIST:C_i_cdr(((C_word*)t0)[2]));
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
t14=C_set_block_item(t5,0,(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9571,a[2]=t7,a[3]=((C_word)li94),tmp=(C_word)a,a+=4,tmp));
t15=C_set_block_item(t7,0,(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9583,a[2]=((C_word*)t0)[3],a[3]=((C_word*)t0)[4],a[4]=((C_word)li95),tmp=(C_word)a,a+=5,tmp));
t16=C_set_block_item(t9,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9610,a[2]=((C_word)li97),tmp=(C_word)a,a+=3,tmp));
t17=C_set_block_item(t11,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9655,a[2]=((C_word)li98),tmp=(C_word)a,a+=3,tmp));
t18=C_set_block_item(t13,0,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9661,a[2]=((C_word)li100),tmp=(C_word)a,a+=3,tmp));
t19=(*a=C_CLOSURE_TYPE|10,a[1]=(C_word)f_9688,a[2]=t7,a[3]=t5,a[4]=t11,a[5]=t13,a[6]=t9,a[7]=t1,a[8]=((C_word*)t0)[5],a[9]=((C_word*)t0)[3],a[10]=((C_word*)t0)[6],tmp=(C_word)a,a+=11,tmp);
if(C_truep(((C_word*)t0)[7])){
t20=C_mutate((C_word*)lf[122]+1 /* (set! ##sys#syntax-error-culprit ...) */,((C_word*)t0)[7]);
t21=t19;
f_9688(t21,t20);}
else{
t20=t19;
f_9688(t20,C_SCHEME_UNDEFINED);}}

/* test in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9571(C_word t0,C_word t1,C_word t2,C_word t3,C_word t4){
C_word tmp;
C_word t5;
C_word t6;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(5,0,2)))){
C_save_and_reclaim_args((void *)trf_9571,5,t0,t1,t2,t3,t4);}
a=C_alloc(5);
t5=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9578,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t4,tmp=(C_word)a,a+=5,tmp);
/* expand.scm:831: pred */
t6=t3;{
C_word av2[3];
av2[0]=t6;
av2[1]=t5;
av2[2]=t2;
((C_proc)C_fast_retrieve_proc(t6))(3,av2);}}

/* k9576 in test in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9578(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_9578,c,av);}
if(C_truep(t1)){
t2=C_SCHEME_UNDEFINED;
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=t2;
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}
else{
/* expand.scm:831: err */
t2=((C_word*)((C_word*)t0)[3])[1];
f_9583(t2,((C_word*)t0)[2],((C_word*)t0)[4]);}}

/* err in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9583(C_word t0,C_word t1,C_word t2){
C_word tmp;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,2)))){
C_save_and_reclaim_args((void *)trf_9583,3,t0,t1,t2);}
a=C_alloc(6);
t3=*((C_word*)lf[122]+1);
t4=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9587,a[2]=t1,a[3]=((C_word*)t0)[2],a[4]=t2,a[5]=((C_word*)t0)[3],tmp=(C_word)a,a+=6,tmp);
/* expand.scm:835: get-line-number */
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[157]+1));
C_word av2[3];
av2[0]=*((C_word*)lf[157]+1);
av2[1]=t4;
av2[2]=*((C_word*)lf[122]+1);
tp(3,av2);}}

/* k9585 in err in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9587(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,2)))){
C_save_and_reclaim((void *)f_9587,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9594,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],tmp=(C_word)a,a+=4,tmp);
if(C_truep(t1)){
t3=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9601,a[2]=t2,a[3]=t1,a[4]=((C_word*)t0)[4],tmp=(C_word)a,a+=5,tmp);
/* expand.scm:838: scheme#symbol->string */
t4=*((C_word*)lf[45]+1);{
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
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9608,a[2]=t2,a[3]=((C_word*)t0)[4],tmp=(C_word)a,a+=4,tmp);
/* expand.scm:839: scheme#symbol->string */
t4=*((C_word*)lf[45]+1);{
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

/* k9592 in k9585 in err in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9594(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9594,c,av);}
/* expand.scm:836: ##sys#syntax-error-hook */
t2=*((C_word*)lf[42]+1);{
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

/* k9599 in k9585 in err in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9601(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,7)))){
C_save_and_reclaim((void *)f_9601,c,av);}
/* expand.scm:838: scheme#string-append */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 8) {
  av2=av;
} else {
  av2=C_alloc(8);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[165];
av2[3]=((C_word*)t0)[3];
av2[4]=lf[166];
av2[5]=t1;
av2[6]=lf[167];
av2[7]=((C_word*)t0)[4];
((C_proc)(void*)(*((C_word*)t2+1)))(8,av2);}}

/* k9606 in k9585 in err in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9608(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_9608,c,av);}
/* expand.scm:839: scheme#string-append */
t2=*((C_word*)lf[37]+1);{
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
av2[2]=lf[168];
av2[3]=t1;
av2[4]=lf[169];
av2[5]=((C_word*)t0)[3];
((C_proc)(void*)(*((C_word*)t2+1)))(6,av2);}}

/* lambda-list? in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9610(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(4,c,2)))){
C_save_and_reclaim((void *)f_9610,c,av);}
a=C_alloc(4);
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_9614,a[2]=t1,a[3]=t2,tmp=(C_word)a,a+=4,tmp);
/* expand.scm:843: ##sys#extended-lambda-list? */
t4=*((C_word*)lf[66]+1);{
C_word *av2=av;
av2[0]=t4;
av2[1]=t3;
av2[2]=t2;
((C_proc)(void*)(*((C_word*)t4+1)))(3,av2);}}

/* k9612 in lambda-list? in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9614(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9614,c,av);}
a=C_alloc(3);
if(C_truep(t1)){
t2=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t2;
av2[1]=t1;
((C_proc)(void*)(*((C_word*)t2+1)))(2,av2);}}
else{
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9622,a[2]=((C_word)li96),tmp=(C_word)a,a+=3,tmp);
t3=((C_word*)t0)[2];{
C_word *av2=av;
av2[0]=t3;
av2[1]=(
  f_9622(((C_word*)t0)[3])
);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}}

/* loop in k9612 in lambda-list? in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_9622(C_word t1){
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
t3=C_i_symbolp(t1);
if(C_truep(t3)){
return(t3);}
else{
if(C_truep(C_i_pairp(t1))){
t4=C_u_i_car(t1);
if(C_truep(C_i_symbolp(t4))){
t6=C_u_i_cdr(t1);
t1=t6;
goto loop;}
else{
return(C_SCHEME_FALSE);}}
else{
return(C_SCHEME_FALSE);}}}}

/* variable? in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9655(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9655,c,av);}
t3=t1;{
C_word *av2=av;
av2[0]=t3;
av2[1]=C_i_symbolp(t2);
((C_proc)(void*)(*((C_word*)t3+1)))(2,av2);}}

/* proper-list? in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9661(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_9661,c,av);}
a=C_alloc(3);
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_9667,a[2]=((C_word)li99),tmp=(C_word)a,a+=3,tmp);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(
  f_9667(t2)
);
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}

/* loop in proper-list? in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static C_word C_fcall f_9667(C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_stack_overflow_check;
loop:{}
t2=C_eqp(t1,C_SCHEME_END_OF_LIST);
if(C_truep(t2)){
return(t2);}
else{
if(C_truep(C_i_pairp(t1))){
t4=C_u_i_cdr(t1);
t1=t4;
goto loop;}
else{
return(C_SCHEME_FALSE);}}}

/* k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9688(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(12,0,4)))){
C_save_and_reclaim_args((void *)trf_9688,2,t0,t1);}
a=C_alloc(12);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|9,a[1]=(C_word)f_9693,a[2]=((C_word*)t0)[2],a[3]=t3,a[4]=((C_word*)t0)[3],a[5]=((C_word*)t0)[4],a[6]=((C_word*)t0)[5],a[7]=((C_word*)t0)[6],a[8]=((C_word*)t0)[7],a[9]=((C_word)li103),tmp=(C_word)a,a+=10,tmp));
t5=((C_word*)t3)[1];
f_9693(t5,((C_word*)t0)[8],((C_word*)t0)[9],((C_word*)t0)[10]);}

/* walk in k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9693(C_word t0,C_word t1,C_word t2,C_word t3){
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
C_word *a;
loop:
if(C_unlikely(!C_demand(C_calculate_demand(8,0,4)))){
C_save_and_reclaim_args((void *)trf_9693,4,t0,t1,t2,t3);}
a=C_alloc(8);
if(C_truep(C_i_vectorp(t3))){
t4=C_i_vector_ref(t3,C_fix(0));
t5=C_block_size(t3);
t6=C_fixnum_greaterp(t5,C_fix(1));
t7=(C_truep(t6)?C_i_vector_ref(t3,C_fix(1)):C_fix(0));
t8=(*a=C_CLOSURE_TYPE|7,a[1]=(C_word)f_9712,a[2]=t7,a[3]=((C_word*)t0)[2],a[4]=((C_word*)t0)[3],a[5]=t4,a[6]=t1,a[7]=t2,tmp=(C_word)a,a+=8,tmp);
t9=C_eqp(t5,C_fix(1));
if(C_truep(t9)){
t10=t8;
f_9712(t10,C_fix(1));}
else{
t10=C_fixnum_greaterp(t5,C_fix(2));
t11=t8;
f_9712(t11,(C_truep(t10)?C_i_vector_ref(t3,C_fix(2)):C_fix(99999)));}}
else{
if(C_truep(C_immp(t3))){
t4=C_eqp(t3,t2);
if(C_truep(C_i_not(t4))){
/* expand.scm:884: err */
t5=((C_word*)((C_word*)t0)[2])[1];
f_9583(t5,t1,lf[173]);}
else{
t5=C_SCHEME_UNDEFINED;
t6=t1;{
C_word av2[2];
av2[0]=t6;
av2[1]=t5;
((C_proc)(void*)(*((C_word*)t6+1)))(2,av2);}}}
else{
if(C_truep(C_i_symbolp(t3))){
t4=C_eqp(t3,lf[174]);
if(C_truep(t4)){
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_TRUE;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t5=C_eqp(t3,lf[175]);
if(C_truep(t5)){
/* expand.scm:888: test */
t6=((C_word*)((C_word*)t0)[4])[1];
f_9571(t6,t1,t2,*((C_word*)lf[176]+1),lf[177]);}
else{
t6=C_eqp(t3,lf[178]);
if(C_truep(t6)){
/* expand.scm:889: test */
t7=((C_word*)((C_word*)t0)[4])[1];
f_9571(t7,t1,t2,((C_word*)((C_word*)t0)[5])[1],lf[179]);}
else{
t7=C_eqp(t3,lf[180]);
if(C_truep(t7)){
/* expand.scm:890: test */
t8=((C_word*)((C_word*)t0)[4])[1];
f_9571(t8,t1,t2,*((C_word*)lf[181]+1),lf[182]);}
else{
t8=C_eqp(t3,lf[183]);
if(C_truep(t8)){
/* expand.scm:891: test */
t9=((C_word*)((C_word*)t0)[4])[1];
f_9571(t9,t1,t2,((C_word*)((C_word*)t0)[6])[1],lf[184]);}
else{
t9=C_eqp(t3,lf[185]);
if(C_truep(t9)){
/* expand.scm:892: test */
t10=((C_word*)((C_word*)t0)[4])[1];
f_9571(t10,t1,t2,*((C_word*)lf[186]+1),lf[187]);}
else{
t10=C_eqp(t3,lf[188]);
if(C_truep(t10)){
/* expand.scm:893: test */
t11=((C_word*)((C_word*)t0)[4])[1];
f_9571(t11,t1,t2,*((C_word*)lf[189]+1),lf[190]);}
else{
t11=C_eqp(t3,lf[191]);
if(C_truep(t11)){
/* expand.scm:894: test */
t12=((C_word*)((C_word*)t0)[4])[1];
f_9571(t12,t1,t2,((C_word*)((C_word*)t0)[7])[1],lf[192]);}
else{
t12=(*a=C_CLOSURE_TYPE|4,a[1]=(C_word)f_9890,a[2]=((C_word*)t0)[8],a[3]=t3,a[4]=((C_word)li102),tmp=(C_word)a,a+=5,tmp);
/* expand.scm:896: test */
t13=((C_word*)((C_word*)t0)[4])[1];
f_9571(t13,t1,t2,t12,lf[193]);}}}}}}}}}
else{
t4=C_i_pairp(t3);
if(C_truep(C_i_not(t4))){
/* expand.scm:903: err */
t5=((C_word*)((C_word*)t0)[2])[1];
f_9583(t5,t1,lf[194]);}
else{
t5=C_i_pairp(t2);
if(C_truep(C_i_not(t5))){
/* expand.scm:904: err */
t6=((C_word*)((C_word*)t0)[2])[1];
f_9583(t6,t1,lf[195]);}
else{
t6=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9947,a[2]=((C_word*)t0)[3],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
/* expand.scm:906: walk */
t14=t6;
t15=C_i_car(t2);
t16=C_i_car(t3);
t1=t14;
t2=t15;
t3=t16;
goto loop;}}}}}}

/* k9710 in walk in k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9712(C_word t0,C_word t1){
C_word tmp;
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(11,0,4)))){
C_save_and_reclaim_args((void *)trf_9712,2,t0,t1);}
a=C_alloc(11);
t2=C_SCHEME_UNDEFINED;
t3=(*a=C_VECTOR_TYPE|1,a[1]=t2,tmp=(C_word)a,a+=2,tmp);
t4=C_set_block_item(t3,0,(*a=C_CLOSURE_TYPE|8,a[1]=(C_word)f_9717,a[2]=((C_word*)t0)[2],a[3]=((C_word*)t0)[3],a[4]=t3,a[5]=t1,a[6]=((C_word*)t0)[4],a[7]=((C_word*)t0)[5],a[8]=((C_word)li101),tmp=(C_word)a,a+=9,tmp));
t5=((C_word*)t3)[1];
f_9717(t5,((C_word*)t0)[6],((C_word*)t0)[7],C_fix(0));}

/* doloop2096 in k9710 in walk in k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_fcall f_9717(C_word t0,C_word t1,C_word t2,C_word t3){
C_word tmp;
C_word t4;
C_word t5;
C_word t6;
C_word t7;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(6,0,3)))){
C_save_and_reclaim_args((void *)trf_9717,4,t0,t1,t2,t3);}
a=C_alloc(6);
t4=C_eqp(t2,C_SCHEME_END_OF_LIST);
if(C_truep(t4)){
if(C_truep(C_fixnum_lessp(t3,((C_word*)t0)[2]))){
/* expand.scm:877: err */
t5=((C_word*)((C_word*)t0)[3])[1];
f_9583(t5,t1,lf[170]);}
else{
t5=t1;{
C_word av2[2];
av2[0]=t5;
av2[1]=C_SCHEME_UNDEFINED;
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}}
else{
t5=(*a=C_CLOSURE_TYPE|5,a[1]=(C_word)f_9736,a[2]=((C_word*)t0)[4],a[3]=t1,a[4]=t2,a[5]=t3,tmp=(C_word)a,a+=6,tmp);
if(C_truep(C_fixnum_greater_or_equal_p(t3,((C_word*)t0)[5]))){
/* expand.scm:879: err */
t6=((C_word*)((C_word*)t0)[3])[1];
f_9583(t6,t5,lf[171]);}
else{
t6=C_i_pairp(t2);
if(C_truep(C_i_not(t6))){
/* expand.scm:881: err */
t7=((C_word*)((C_word*)t0)[3])[1];
f_9583(t7,t5,lf[172]);}
else{
/* expand.scm:882: walk */
t7=((C_word*)((C_word*)t0)[6])[1];
f_9693(t7,t5,C_i_car(t2),((C_word*)t0)[7]);}}}}

/* k9734 in doloop2096 in k9710 in walk in k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9736(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9736,c,av);}
t2=((C_word*)((C_word*)t0)[2])[1];
f_9717(t2,((C_word*)t0)[3],C_i_cdr(((C_word*)t0)[4]),C_fixnum_plus(((C_word*)t0)[5],C_fix(1)));}

/* a9889 in walk in k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9890(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3;
C_word t4;
C_word t5;
C_word *a;
if(c!=3) C_bad_argc_2(c,3,t0);
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_9890,c,av);}
if(C_truep(C_i_symbolp(t2))){
t3=(
/* expand.scm:899: lookup */
  f_5794(t2,((C_word*)t0)[2])
);
t4=C_i_symbolp(t3);
t5=t1;{
C_word *av2=av;
av2[0]=t5;
av2[1]=(C_truep(t4)?C_eqp(t3,((C_word*)t0)[3]):C_eqp(t2,((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t5+1)))(2,av2);}}
else{
t3=C_i_symbolp(C_SCHEME_FALSE);
t4=t1;{
C_word *av2=av;
av2[0]=t4;
av2[1]=(C_truep(t3)?C_eqp(C_SCHEME_FALSE,((C_word*)t0)[3]):C_eqp(t2,((C_word*)t0)[3]));
((C_proc)(void*)(*((C_word*)t4+1)))(2,av2);}}}

/* k9945 in walk in k9686 in k9564 in ##sys#check-syntax in k6180 in k5790 in k5786 in k4503 in k4500 in k4497 */
static void C_ccall f_9947(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,3)))){
C_save_and_reclaim((void *)f_9947,c,av);}
/* expand.scm:907: walk */
t2=((C_word*)((C_word*)t0)[2])[1];
f_9693(t2,((C_word*)t0)[3],C_u_i_cdr(((C_word*)t0)[4]),C_u_i_cdr(((C_word*)t0)[5]));}

/* toplevel */
static C_TLS int toplevel_initialized=0;

void C_ccall C_expand_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("expand"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_expand_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(3400))){
C_save(t1);
C_rereclaim2(3400*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,398);
lf[0]=C_h_intern(&lf[0],6, C_text("expand"));
lf[1]=C_h_intern(&lf[1],15, C_text("chicken.syntax#"));
lf[2]=C_h_intern(&lf[2],29, C_text("##sys#current-source-filename"));
lf[3]=C_h_intern(&lf[3],25, C_text("##sys#current-environment"));
lf[4]=C_h_intern(&lf[4],30, C_text("##sys#current-meta-environment"));
lf[6]=C_h_intern(&lf[6],18, C_text("##core#macro-alias"));
lf[8]=C_h_intern(&lf[8],16, C_text("##core#real-name"));
lf[9]=C_h_intern(&lf[9],19, C_text("chicken.base#gensym"));
lf[10]=C_h_intern(&lf[10],24, C_text("chicken.keyword#keyword\077"));
lf[11]=C_h_intern(&lf[11],27, C_text("chicken.syntax#strip-syntax"));
lf[12]=C_h_intern(&lf[12],18, C_text("scheme#make-vector"));
lf[13]=C_h_intern(&lf[13],15, C_text("##sys#extend-se"));
lf[14]=C_h_intern(&lf[14],8, C_text("for-each"));
lf[15]=C_h_intern(&lf[15],13, C_text("scheme#append"));
lf[16]=C_h_intern(&lf[16],3, C_text("map"));
lf[17]=C_h_intern(&lf[17],23, C_text("##sys#macro-environment"));
lf[18]=C_h_intern(&lf[18],30, C_text("##sys#scheme-macro-environment"));
lf[19]=C_h_intern(&lf[19],35, C_text("##sys#chicken-ffi-macro-environment"));
lf[20]=C_h_intern(&lf[20],41, C_text("##sys#chicken.condition-macro-environment"));
lf[21]=C_h_intern(&lf[21],36, C_text("##sys#chicken.time-macro-environment"));
lf[22]=C_h_intern(&lf[22],36, C_text("##sys#chicken.type-macro-environment"));
lf[23]=C_h_intern(&lf[23],38, C_text("##sys#chicken.syntax-macro-environment"));
lf[24]=C_h_intern(&lf[24],36, C_text("##sys#chicken.base-macro-environment"));
lf[25]=C_h_intern(&lf[25],24, C_text("##sys#ensure-transformer"));
lf[26]=C_h_intern(&lf[26],11, C_text("transformer"));
lf[27]=C_h_intern(&lf[27],11, C_text("##sys#error"));
lf[28]=C_decode_literal(C_heaptop,C_text("\376B\000\000$expected syntax-transformer, but got"));
lf[29]=C_h_intern(&lf[29],30, C_text("##sys#extend-macro-environment"));
lf[30]=C_h_intern(&lf[30],12, C_text("##sys#macro\077"));
lf[31]=C_h_intern(&lf[31],21, C_text("##sys#undefine-macro!"));
lf[32]=C_h_intern(&lf[32],14, C_text("##sys#expand-0"));
lf[33]=C_h_intern(&lf[33],9, C_text("condition"));
lf[34]=C_h_intern(&lf[34],3, C_text("exn"));
lf[35]=C_h_intern(&lf[35],23, C_text("chicken.condition#abort"));
lf[36]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001exn\376\001\000\000\007\001message"));
lf[37]=C_h_intern(&lf[37],20, C_text("scheme#string-append"));
lf[38]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025during expansion of ("));
lf[39]=C_decode_literal(C_heaptop,C_text("\376B\000\000\010 ...) - "));
lf[40]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\003\001exn\376\001\000\000\007\001message"));
lf[41]=C_h_intern(&lf[41],36, C_text("chicken.syntax#expansion-result-hook"));
lf[42]=C_h_intern(&lf[42],23, C_text("##sys#syntax-error-hook"));
lf[43]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030syntax transformer for `"));
lf[44]=C_decode_literal(C_heaptop,C_text("\376B\000\000@\047 returns original form, which would result in endless expansion"));
lf[45]=C_h_intern(&lf[45],21, C_text("scheme#symbol->string"));
lf[46]=C_h_intern(&lf[46],51, C_text("chicken.internal.syntax-rules#syntax-rules-mismatch"));
lf[47]=C_h_intern(&lf[47],18, C_text("##sys#dynamic-wind"));
lf[48]=C_h_intern(&lf[48],40, C_text("chicken.condition#with-exception-handler"));
lf[49]=C_h_intern(&lf[49],37, C_text("scheme#call-with-current-continuation"));
lf[50]=C_decode_literal(C_heaptop,C_text("\376B\000\000\034invalid syntax in macro form"));
lf[51]=C_h_intern(&lf[51],10, C_text("##core#let"));
lf[52]=C_h_intern(&lf[52],18, C_text("##core#loop-lambda"));
lf[53]=C_h_intern(&lf[53],14, C_text("##core#letrec\052"));
lf[54]=C_h_intern(&lf[54],10, C_text("##core#app"));
lf[55]=C_h_intern(&lf[55],18, C_text("##sys#check-syntax"));
lf[56]=C_h_intern(&lf[56],3, C_text("let"));
lf[57]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[58]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\002"));
lf[59]=C_h_intern(&lf[59],26, C_text("##sys#compiler-syntax-hook"));
lf[60]=C_h_intern(&lf[60],26, C_text("##compiler#compiler-syntax"));
lf[61]=C_h_intern(&lf[61],5, C_text("value"));
lf[62]=C_h_intern(&lf[62],9, C_text("##sys#get"));
lf[63]=C_h_intern(&lf[63],14, C_text("##sys#override"));
lf[64]=C_h_intern(&lf[64],27, C_text("##sys#enable-runtime-macros"));
lf[65]=C_h_intern(&lf[65],21, C_text("chicken.syntax#expand"));
lf[66]=C_h_intern(&lf[66],27, C_text("##sys#extended-lambda-list\077"));
lf[67]=C_h_intern(&lf[67],6, C_text("#!rest"));
lf[68]=C_h_intern(&lf[68],10, C_text("#!optional"));
lf[69]=C_h_intern(&lf[69],5, C_text("#!key"));
lf[70]=C_h_intern(&lf[70],33, C_text("##sys#expand-extended-lambda-list"));
lf[71]=C_h_intern(&lf[71],12, C_text("scheme#cadar"));
lf[72]=C_h_intern(&lf[72],14, C_text("scheme#reverse"));
lf[73]=C_h_intern(&lf[73],12, C_text("##sys#append"));
lf[74]=C_h_intern(&lf[74],12, C_text("##core#quote"));
lf[75]=C_h_intern(&lf[75],13, C_text("##core#lambda"));
lf[76]=C_h_intern(&lf[76],17, C_text("##sys#get-keyword"));
lf[77]=C_h_intern(&lf[77],31, C_text("chicken.keyword#string->keyword"));
lf[78]=C_decode_literal(C_heaptop,C_text("\376B\000\000+rest argument list specified more than once"));
lf[79]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032invalid lambda list syntax"));
lf[80]=C_decode_literal(C_heaptop,C_text("\376B\000\000-`#!optional\047 argument marker in wrong context"));
lf[81]=C_h_intern(&lf[81],4, C_text("rest"));
lf[82]=C_decode_literal(C_heaptop,C_text("\376B\000\000#invalid syntax of `#!rest\047 argument"));
lf[83]=C_decode_literal(C_heaptop,C_text("\376B\000\000)`#!rest\047 argument marker in wrong context"));
lf[84]=C_decode_literal(C_heaptop,C_text("\376B\000\000(`#!key\047 argument marker in wrong context"));
lf[85]=C_decode_literal(C_heaptop,C_text("\376B\000\0000invalid lambda list syntax after `#!rest\047 marker"));
lf[86]=C_decode_literal(C_heaptop,C_text("\376B\000\000 invalid required argument syntax"));
lf[87]=C_decode_literal(C_heaptop,C_text("\376B\000\0000invalid lambda list syntax after `#!rest\047 marker"));
lf[88]=C_decode_literal(C_heaptop,C_text("\376B\000\000\032invalid lambda list syntax"));
lf[89]=C_h_intern(&lf[89],14, C_text("let-optionals\052"));
lf[90]=C_h_intern(&lf[90],8, C_text("optional"));
lf[91]=C_h_intern(&lf[91],4, C_text("let\052"));
lf[92]=C_h_intern(&lf[92],31, C_text("##sys#default-macro-environment"));
lf[93]=C_h_intern(&lf[93],39, C_text("##sys#expand-multiple-values-assignment"));
lf[94]=C_h_intern(&lf[94],22, C_text("##sys#call-with-values"));
lf[95]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016\376\377\016"));
lf[96]=C_h_intern(&lf[96],11, C_text("##core#set!"));
lf[97]=C_h_intern(&lf[97],27, C_text("##sys#decompose-lambda-list"));
lf[98]=C_h_intern(&lf[98],32, C_text("chicken.syntax#define-definition"));
lf[99]=C_h_intern(&lf[99],39, C_text("chicken.syntax#define-syntax-definition"));
lf[100]=C_h_intern(&lf[100],39, C_text("chicken.syntax#define-values-definition"));
lf[102]=C_h_intern(&lf[102],23, C_text("##sys#canonicalize-body"));
lf[103]=C_h_intern(&lf[103],12, C_text("##core#begin"));
lf[104]=C_h_intern(&lf[104],14, C_text("##core#include"));
lf[105]=C_h_intern(&lf[105],13, C_text("##core#module"));
lf[106]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[107]=C_h_intern(&lf[107],20, C_text("##core#letrec-syntax"));
lf[108]=C_decode_literal(C_heaptop,C_text("\376B\000\000,redefinition of currently used defining form"));
lf[109]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[110]=C_h_intern(&lf[110],6, C_text("define"));
lf[111]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[112]=C_h_intern(&lf[112],36, C_text("chicken.syntax#expand-curried-define"));
lf[113]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\013\001lambda-list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[114]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\001\000\000\013\001lambda-list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[115]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[116]=C_h_intern(&lf[116],13, C_text("define-syntax"));
lf[117]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[118]=C_h_intern(&lf[118],13, C_text("define-values"));
lf[119]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[120]=C_h_intern(&lf[120],31, C_text("chicken.syntax#match-expression"));
lf[121]=C_h_intern(&lf[121],26, C_text("##sys#line-number-database"));
lf[122]=C_h_intern(&lf[122],26, C_text("##sys#syntax-error-culprit"));
lf[123]=C_h_intern(&lf[123],20, C_text("##sys#syntax-context"));
lf[124]=C_h_intern(&lf[124],27, C_text("chicken.syntax#syntax-error"));
lf[125]=C_h_intern(&lf[125],17, C_text("##sys#signal-hook"));
lf[126]=C_h_intern_kw(&lf[126],12, C_text("syntax-error"));
lf[127]=C_h_intern(&lf[127],26, C_text("##sys#syntax-error/context"));
lf[128]=C_h_intern(&lf[128],11, C_text("##sys#print"));
lf[129]=C_h_intern(&lf[129],30, C_text("chicken.base#get-output-string"));
lf[130]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006 ...)\047"));
lf[131]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025\012inside expression `("));
lf[132]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[133]=C_decode_literal(C_heaptop,C_text("\376B\000\000\027  Suggesting: `(import "));
lf[134]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002)\047"));
lf[135]=C_decode_literal(C_heaptop,C_text("\376B\000\000\025  Suggesting one of:\012"));
lf[136]=C_decode_literal(C_heaptop,C_text("\376B\000\000\000"));
lf[137]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017\012      (import "));
lf[138]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002)\047"));
lf[139]=C_decode_literal(C_heaptop,C_text("\376B\000\000# ...)\047 without importing it first.\012"));
lf[140]=C_decode_literal(C_heaptop,C_text("\376B\000\000-\012\012  Perhaps you intended to use the syntax `("));
lf[141]=C_decode_literal(C_heaptop,C_text("\376B\000\000\002: "));
lf[142]=C_h_intern(&lf[142],6, C_text("syntax"));
lf[143]=C_h_intern(&lf[143],9, C_text("##core#db"));
lf[144]=C_h_intern(&lf[144],31, C_text("chicken.base#open-output-string"));
lf[147]=C_h_intern(&lf[147],9, C_text("list-info"));
lf[148]=C_h_intern(&lf[148],32, C_text("chicken.internal#hash-table-set!"));
lf[149]=C_h_intern(&lf[149],19, C_text("chicken.string#conc"));
lf[150]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001:"));
lf[151]=C_decode_literal(C_heaptop,C_text("\376B\000\000\007<stdin>"));
lf[152]=C_h_intern(&lf[152],31, C_text("chicken.internal#hash-table-ref"));
lf[153]=C_h_intern(&lf[153],36, C_text("chicken.syntax#read-with-source-info"));
lf[154]=C_h_intern(&lf[154],20, C_text("##sys#standard-input"));
lf[155]=C_h_intern(&lf[155],21, C_text("read-with-source-info"));
lf[156]=C_h_intern(&lf[156],10, C_text("##sys#read"));
lf[157]=C_h_intern(&lf[157],30, C_text("chicken.syntax#get-line-number"));
lf[158]=C_h_intern(&lf[158],16, C_text("##sys#get-line-2"));
lf[159]=C_h_intern(&lf[159],34, C_text("##sys#display-line-number-database"));
lf[160]=C_h_intern(&lf[160],21, C_text("##sys#standard-output"));
lf[161]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001\012"));
lf[162]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001 "));
lf[163]=C_h_intern(&lf[163],36, C_text("chicken.internal#hash-table-for-each"));
lf[164]=C_h_intern(&lf[164],34, C_text("##sys#update-line-number-database!"));
lf[165]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001("));
lf[166]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006) in `"));
lf[167]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004\047 - "));
lf[168]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004in `"));
lf[169]=C_decode_literal(C_heaptop,C_text("\376B\000\000\004\047 - "));
lf[170]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024not enough arguments"));
lf[171]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022too many arguments"));
lf[172]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021not a proper list"));
lf[173]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021unexpected object"));
lf[174]=C_h_intern(&lf[174],1, C_text("_"));
lf[175]=C_h_intern(&lf[175],4, C_text("pair"));
lf[176]=C_h_intern(&lf[176],12, C_text("scheme#pair\077"));
lf[177]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015pair expected"));
lf[178]=C_h_intern(&lf[178],8, C_text("variable"));
lf[179]=C_decode_literal(C_heaptop,C_text("\376B\000\000\023identifier expected"));
lf[180]=C_h_intern(&lf[180],6, C_text("symbol"));
lf[181]=C_h_intern(&lf[181],14, C_text("scheme#symbol\077"));
lf[182]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017symbol expected"));
lf[183]=C_h_intern(&lf[183],4, C_text("list"));
lf[184]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024proper list expected"));
lf[185]=C_h_intern(&lf[185],6, C_text("number"));
lf[186]=C_h_intern(&lf[186],14, C_text("scheme#number\077"));
lf[187]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017number expected"));
lf[188]=C_h_intern(&lf[188],6, C_text("string"));
lf[189]=C_h_intern(&lf[189],14, C_text("scheme#string\077"));
lf[190]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017string expected"));
lf[191]=C_h_intern(&lf[191],11, C_text("lambda-list"));
lf[192]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024lambda-list expected"));
lf[193]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017missing keyword"));
lf[194]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017incomplete form"));
lf[195]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015pair expected"));
lf[197]=C_h_intern(&lf[197],19, C_text("scheme#list->vector"));
lf[198]=C_h_intern(&lf[198],19, C_text("scheme#vector->list"));
lf[199]=C_decode_literal(C_heaptop,C_text("\376B\000\000\033(expand.scm:926) not a list"));
lf[200]=C_h_intern(&lf[200],35, C_text("chicken.syntax#er-macro-transformer"));
lf[201]=C_h_intern(&lf[201],35, C_text("chicken.syntax#ir-macro-transformer"));
lf[202]=C_h_intern(&lf[202],20, C_text("##sys#er-transformer"));
lf[203]=C_h_intern(&lf[203],20, C_text("##sys#ir-transformer"));
lf[204]=C_h_intern(&lf[204],31, C_text("##sys#initial-macro-environment"));
lf[205]=C_h_intern(&lf[205],38, C_text("##sys#chicken.module-macro-environment"));
lf[206]=C_h_intern(&lf[206],30, C_text("chicken.internal.syntax-rules#"));
lf[207]=C_decode_literal(C_heaptop,C_text("\376B\000\000\024no rule matches form"));
lf[208]=C_h_intern(&lf[208],40, C_text("chicken.internal.syntax-rules#drop-right"));
lf[209]=C_h_intern(&lf[209],40, C_text("chicken.internal.syntax-rules#take-right"));
lf[210]=C_h_intern(&lf[210],28, C_text("##sys#meta-macro-environment"));
lf[211]=C_h_intern(&lf[211],34, C_text("chicken.platform#register-feature!"));
lf[212]=C_h_intern(&lf[212],6, C_text("srfi-0"));
lf[213]=C_h_intern(&lf[213],7, C_text("srfi-46"));
lf[214]=C_h_intern(&lf[214],7, C_text("srfi-61"));
lf[215]=C_h_intern(&lf[215],7, C_text("srfi-87"));
lf[216]=C_h_intern(&lf[216],27, C_text("chicken.base#make-parameter"));
lf[217]=C_h_intern(&lf[217],40, C_text("chicken.internal#fixup-macro-environment"));
lf[218]=C_h_intern(&lf[218],29, C_text("chicken.internal#macro-subset"));
lf[219]=C_h_intern(&lf[219],12, C_text("syntax-rules"));
lf[220]=C_h_intern(&lf[220],3, C_text("..."));
lf[221]=C_h_intern(&lf[221],9, C_text("##sys#car"));
lf[222]=C_h_intern(&lf[222],9, C_text("##sys#cdr"));
lf[223]=C_h_intern(&lf[223],12, C_text("##sys#length"));
lf[224]=C_h_intern(&lf[224],13, C_text("##sys#vector\077"));
lf[225]=C_h_intern(&lf[225],18, C_text("##sys#vector->list"));
lf[226]=C_h_intern(&lf[226],18, C_text("##sys#list->vector"));
lf[227]=C_h_intern(&lf[227],8, C_text("##sys#>="));
lf[228]=C_h_intern(&lf[228],7, C_text("##sys#="));
lf[229]=C_h_intern(&lf[229],7, C_text("##sys#+"));
lf[230]=C_h_intern(&lf[230],10, C_text("##sys#cons"));
lf[231]=C_h_intern(&lf[231],9, C_text("##sys#eq\077"));
lf[232]=C_h_intern(&lf[232],12, C_text("##sys#equal\077"));
lf[233]=C_h_intern(&lf[233],11, C_text("##sys#list\077"));
lf[234]=C_h_intern(&lf[234],9, C_text("##sys#map"));
lf[235]=C_h_intern(&lf[235],11, C_text("##sys#map-n"));
lf[236]=C_h_intern(&lf[236],11, C_text("##sys#pair\077"));
lf[237]=C_decode_literal(C_heaptop,C_text("\376B\000\000\026ill-formed syntax rule"));
lf[238]=C_h_intern(&lf[238],13, C_text("##core#syntax"));
lf[239]=C_h_intern(&lf[239],5, C_text("quote"));
lf[240]=C_decode_literal(C_heaptop,C_text("\376B\000\000,template dimension error (too few ellipses\077)"));
lf[241]=C_decode_literal(C_heaptop,C_text("\376B\000\000\021too many ellipses"));
lf[242]=C_h_intern(&lf[242],11, C_text("##sys#apply"));
lf[243]=C_decode_literal(C_heaptop,C_text("\376B\000\000%Only one segment per level is allowed"));
lf[244]=C_decode_literal(C_heaptop,C_text("\376B\000\000\047Cannot combine dotted tail and ellipsis"));
lf[245]=C_h_intern(&lf[245],4, C_text("temp"));
lf[246]=C_h_intern(&lf[246],4, C_text("tail"));
lf[247]=C_h_intern(&lf[247],6, C_text("rename"));
lf[248]=C_h_intern(&lf[248],2, C_text("or"));
lf[249]=C_h_intern(&lf[249],4, C_text("loop"));
lf[250]=C_h_intern(&lf[250],6, C_text("lambda"));
lf[251]=C_h_intern(&lf[251],3, C_text("len"));
lf[252]=C_h_intern(&lf[252],1, C_text("l"));
lf[253]=C_h_intern(&lf[253],5, C_text("input"));
lf[254]=C_h_intern(&lf[254],4, C_text("else"));
lf[255]=C_h_intern(&lf[255],4, C_text("cond"));
lf[256]=C_h_intern(&lf[256],7, C_text("compare"));
lf[257]=C_h_intern(&lf[257],3, C_text("and"));
lf[258]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\004\001list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[259]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\002"));
lf[260]=C_h_intern(&lf[260],5, C_text("delay"));
lf[261]=C_h_intern(&lf[261],10, C_text("##sys#list"));
lf[262]=C_h_intern(&lf[262],18, C_text("##sys#make-promise"));
lf[263]=C_h_intern(&lf[263],11, C_text("delay-force"));
lf[264]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[265]=C_h_intern(&lf[265],10, C_text("quasiquote"));
lf[266]=C_h_intern(&lf[266],7, C_text("unquote"));
lf[267]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[268]=C_h_intern(&lf[268],16, C_text("unquote-splicing"));
lf[269]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[270]=C_h_intern(&lf[270],1, C_text("a"));
lf[271]=C_h_intern(&lf[271],1, C_text("b"));
lf[272]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\014\001##sys#append\376\003\000\000\002\376\001\000\000\001\001a\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001##core#quote\376\003\000\000\002\376\377\016\376\377\016\376\377\016"));
lf[273]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001a\376\377\016"));
lf[274]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001##sys#cons\376\003\000\000\002\376\001\000\000\001\001a\376\003\000\000\002\376\003\000\000\002\376\001\000\000\012\001##sys#list\376\001\000\000\001\001b\376\377\016"));
lf[275]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001a\376\003\000\000\002\376\001\000\000\001\001b\376\377\016"));
lf[276]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\012\001##sys#cons\376\003\000\000\002\376\001\000\000\001\001a\376\003\000\000\002\376\003\000\000\002\376\001\000\000\014\001##core#quote\376\003\000\000\002\376\377\016\376\377\016\376\377\016"));
lf[277]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001a\376\377\016"));
lf[278]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[279]=C_h_intern(&lf[279],2, C_text("do"));
lf[280]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[281]=C_h_intern(&lf[281],9, C_text("##core#if"));
lf[282]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[283]=C_h_intern(&lf[283],6, C_text("doloop"));
lf[284]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\001\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000"
"\000\001\001_\376\377\001\000\000\000\001"));
lf[285]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[286]=C_h_intern(&lf[286],4, C_text("case"));
lf[287]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\003\000\000\002\376\001\000\000\004\001eqv\077\376\001\000\000\013\001scheme#eqv\077\376\377\016"));
lf[288]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[289]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\014\001##core#begin\376\377\016"));
lf[290]=C_h_intern(&lf[290],10, C_text("##sys#warn"));
lf[291]=C_decode_literal(C_heaptop,C_text("\376B\000\000(clause following `else\047 clause in `case\047"));
lf[292]=C_h_intern(&lf[292],16, C_text("##core#undefined"));
lf[293]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[294]=C_h_intern(&lf[294],4, C_text("eqv\077"));
lf[295]=C_h_intern(&lf[295],2, C_text("=>"));
lf[296]=C_h_intern(&lf[296],3, C_text("tmp"));
lf[297]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[298]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[299]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\014\001##core#begin\376\377\016"));
lf[300]=C_h_intern(&lf[300],7, C_text("sprintf"));
lf[301]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022\047 clause in `cond\047"));
lf[302]=C_decode_literal(C_heaptop,C_text("\376B\000\000\022clause following `"));
lf[303]=C_h_intern(&lf[303],2, C_text("if"));
lf[304]=C_h_intern(&lf[304],20, C_text("##sys#srfi-4-vector\077"));
lf[305]=C_h_intern(&lf[305],18, C_text("chicken.blob#blob\077"));
lf[306]=C_decode_literal(C_heaptop,C_text("\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[307]=C_h_intern(&lf[307],4, C_text("set!"));
lf[308]=C_h_intern(&lf[308],12, C_text("##sys#setter"));
lf[309]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[310]=C_h_intern(&lf[310],13, C_text("letrec-syntax"));
lf[311]=C_h_intern(&lf[311],44, C_text("chicken.internal#check-for-multiple-bindings"));
lf[312]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015letrec-syntax"));
lf[313]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[314]=C_h_intern(&lf[314],10, C_text("let-syntax"));
lf[315]=C_h_intern(&lf[315],17, C_text("##core#let-syntax"));
lf[316]=C_decode_literal(C_heaptop,C_text("\376B\000\000\012let-syntax"));
lf[317]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[318]=C_h_intern(&lf[318],6, C_text("letrec"));
lf[319]=C_h_intern(&lf[319],13, C_text("##core#letrec"));
lf[320]=C_decode_literal(C_heaptop,C_text("\376B\000\000\006letrec"));
lf[321]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[322]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003let"));
lf[323]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000"
"\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[324]=C_decode_literal(C_heaptop,C_text("\376B\000\000\003let"));
lf[325]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\000\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000"
"\000\001"));
lf[326]=C_h_intern(&lf[326],20, C_text("##core#define-syntax"));
lf[327]=C_h_intern(&lf[327],21, C_text("##sys#register-export"));
lf[328]=C_h_intern(&lf[328],20, C_text("##sys#current-module"));
lf[329]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[330]=C_h_intern(&lf[330],33, C_text("##core#ensure-toplevel-definition"));
lf[331]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[332]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\000\000\000\003\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\001\000\000\000\001"));
lf[333]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\001\000\000\013\001lambda-list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[334]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\010\001variable\376\001\000\000\013\001lambda-list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[335]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[336]=C_h_intern(&lf[336],5, C_text("begin"));
lf[337]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[338]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\001\376\001\000\000\001\001_"));
lf[339]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[340]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\013\001lambda-list\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\001"));
lf[341]=C_h_intern(&lf[341],14, C_text("current-module"));
lf[342]=C_h_intern(&lf[342],17, C_text("##sys#module-name"));
lf[343]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[344]=C_h_intern(&lf[344],16, C_text("define-interface"));
lf[345]=C_h_intern(&lf[345],16, C_text("##core#interface"));
lf[346]=C_h_intern(&lf[346],18, C_text("##sys#put/restore!"));
lf[347]=C_h_intern(&lf[347],26, C_text("##core#elaborationtimeonly"));
lf[348]=C_h_intern(&lf[348],1, C_text("\052"));
lf[349]=C_h_intern_kw(&lf[349],9, C_text("interface"));
lf[350]=C_h_intern(&lf[350],22, C_text("##sys#validate-exports"));
lf[351]=C_h_intern(&lf[351],17, C_text("syntax-error-hook"));
lf[352]=C_decode_literal(C_heaptop,C_text("\376B\000\000\017invalid exports"));
lf[353]=C_decode_literal(C_heaptop,C_text("\376B\000\000-`\052\047 is not allowed as a name for an interface"));
lf[354]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\010\001variable\376\003\000\000\002\376\001\000\000\001\001_\376\377\016"));
lf[355]=C_h_intern(&lf[355],7, C_text("functor"));
lf[356]=C_decode_literal(C_heaptop,C_text("\376B\000\000\030invalid functor argument"));
lf[357]=C_h_intern(&lf[357],41, C_text("chicken.internal#valid-library-specifier\077"));
lf[358]=C_h_intern(&lf[358],22, C_text("##sys#register-functor"));
lf[359]=C_h_intern(&lf[359],6, C_text("import"));
lf[360]=C_h_intern(&lf[360],6, C_text("scheme"));
lf[361]=C_h_intern(&lf[361],14, C_text("chicken.syntax"));
lf[362]=C_h_intern(&lf[362],16, C_text("begin-for-syntax"));
lf[363]=C_h_intern(&lf[363],27, C_text("chicken.internal#library-id"));
lf[364]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\377\016\376\377\001\000\000\000\000\376\003\000\000\002\376\001\000\000\001\001_"
"\376\001\000\000\001\001_"));
lf[365]=C_h_intern(&lf[365],8, C_text("reexport"));
lf[366]=C_h_intern(&lf[366],19, C_text("##sys#expand-import"));
lf[367]=C_h_intern(&lf[367],13, C_text("export/rename"));
lf[368]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[369]=C_h_intern(&lf[369],31, C_text("##sys#add-to-export/rename-list"));
lf[370]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042invalid item in export rename list"));
lf[371]=C_h_intern(&lf[371],6, C_text("export"));
lf[372]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[373]=C_h_intern(&lf[373],24, C_text("##sys#add-to-export-list"));
lf[374]=C_h_intern(&lf[374],6, C_text("module"));
lf[375]=C_h_intern(&lf[375],1, C_text("="));
lf[376]=C_h_intern(&lf[376],21, C_text("scheme#string->symbol"));
lf[377]=C_h_intern(&lf[377],19, C_text("##sys#string-append"));
lf[378]=C_decode_literal(C_heaptop,C_text("\376B\000\000\001_"));
lf[379]=C_h_intern(&lf[379],25, C_text("##sys#instantiate-functor"));
lf[380]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000\376\377\016"));
lf[381]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\003\000\000\002\376\001\000\000\001\001_\376\000\000\000\002\376\001\000\000\001\001_\376\377\001\000\000\000\000"));
lf[382]=C_h_intern(&lf[382],11, C_text("cond-expand"));
lf[383]=C_decode_literal(C_heaptop,C_text("\376B\000\000\042syntax error in `cond-expand\047 form"));
lf[384]=C_h_intern(&lf[384],25, C_text("chicken.platform#feature\077"));
lf[385]=C_h_intern(&lf[385],3, C_text("not"));
lf[386]=C_decode_literal(C_heaptop,C_text("\376B\000\000(no matching clause in `cond-expand\047 form"));
lf[387]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[388]=C_h_intern(&lf[388],17, C_text("import-for-syntax"));
lf[389]=C_h_intern(&lf[389],30, C_text("##sys#register-meta-expression"));
lf[390]=C_h_intern(&lf[390],22, C_text("##sys#decompose-import"));
lf[391]=C_decode_literal(C_heaptop,C_text("\376\003\000\000\002\376\001\000\000\020\001##core#undefined\376\377\016"));
lf[392]=C_h_intern(&lf[392],14, C_text("##core#require"));
lf[393]=C_decode_literal(C_heaptop,C_text("\376B\000\000#cannot import from undefined module"));
lf[394]=C_h_intern(&lf[394],12, C_text("##sys#import"));
lf[395]=C_decode_literal(C_heaptop,C_text("\376B\000\0001cannot import from module currently being defined"));
lf[396]=C_h_intern(&lf[396],24, C_text("import-syntax-for-syntax"));
lf[397]=C_h_intern(&lf[397],13, C_text("import-syntax"));
C_register_lf2(lf,398,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_4499,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_internal_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[735] = {
{C_text("f_10000:expand_2escm"),(void*)f_10000},
{C_text("f_10006:expand_2escm"),(void*)f_10006},
{C_text("f_10009:expand_2escm"),(void*)f_10009},
{C_text("f_10016:expand_2escm"),(void*)f_10016},
{C_text("f_10025:expand_2escm"),(void*)f_10025},
{C_text("f_10031:expand_2escm"),(void*)f_10031},
{C_text("f_10056:expand_2escm"),(void*)f_10056},
{C_text("f_10058:expand_2escm"),(void*)f_10058},
{C_text("f_10076:expand_2escm"),(void*)f_10076},
{C_text("f_10080:expand_2escm"),(void*)f_10080},
{C_text("f_10097:expand_2escm"),(void*)f_10097},
{C_text("f_10101:expand_2escm"),(void*)f_10101},
{C_text("f_10127:expand_2escm"),(void*)f_10127},
{C_text("f_10144:expand_2escm"),(void*)f_10144},
{C_text("f_10166:expand_2escm"),(void*)f_10166},
{C_text("f_10203:expand_2escm"),(void*)f_10203},
{C_text("f_10224:expand_2escm"),(void*)f_10224},
{C_text("f_10255:expand_2escm"),(void*)f_10255},
{C_text("f_10263:expand_2escm"),(void*)f_10263},
{C_text("f_10285:expand_2escm"),(void*)f_10285},
{C_text("f_10300:expand_2escm"),(void*)f_10300},
{C_text("f_10313:expand_2escm"),(void*)f_10313},
{C_text("f_10328:expand_2escm"),(void*)f_10328},
{C_text("f_10363:expand_2escm"),(void*)f_10363},
{C_text("f_10388:expand_2escm"),(void*)f_10388},
{C_text("f_10406:expand_2escm"),(void*)f_10406},
{C_text("f_10410:expand_2escm"),(void*)f_10410},
{C_text("f_10427:expand_2escm"),(void*)f_10427},
{C_text("f_10431:expand_2escm"),(void*)f_10431},
{C_text("f_10520:expand_2escm"),(void*)f_10520},
{C_text("f_10524:expand_2escm"),(void*)f_10524},
{C_text("f_10529:expand_2escm"),(void*)f_10529},
{C_text("f_10535:expand_2escm"),(void*)f_10535},
{C_text("f_10548:expand_2escm"),(void*)f_10548},
{C_text("f_10551:expand_2escm"),(void*)f_10551},
{C_text("f_10555:expand_2escm"),(void*)f_10555},
{C_text("f_10558:expand_2escm"),(void*)f_10558},
{C_text("f_10561:expand_2escm"),(void*)f_10561},
{C_text("f_10565:expand_2escm"),(void*)f_10565},
{C_text("f_10568:expand_2escm"),(void*)f_10568},
{C_text("f_10571:expand_2escm"),(void*)f_10571},
{C_text("f_10574:expand_2escm"),(void*)f_10574},
{C_text("f_10577:expand_2escm"),(void*)f_10577},
{C_text("f_10580:expand_2escm"),(void*)f_10580},
{C_text("f_10583:expand_2escm"),(void*)f_10583},
{C_text("f_10586:expand_2escm"),(void*)f_10586},
{C_text("f_10590:expand_2escm"),(void*)f_10590},
{C_text("f_10594:expand_2escm"),(void*)f_10594},
{C_text("f_10597:expand_2escm"),(void*)f_10597},
{C_text("f_10600:expand_2escm"),(void*)f_10600},
{C_text("f_10603:expand_2escm"),(void*)f_10603},
{C_text("f_10606:expand_2escm"),(void*)f_10606},
{C_text("f_10610:expand_2escm"),(void*)f_10610},
{C_text("f_10614:expand_2escm"),(void*)f_10614},
{C_text("f_10617:expand_2escm"),(void*)f_10617},
{C_text("f_10620:expand_2escm"),(void*)f_10620},
{C_text("f_10623:expand_2escm"),(void*)f_10623},
{C_text("f_10626:expand_2escm"),(void*)f_10626},
{C_text("f_10629:expand_2escm"),(void*)f_10629},
{C_text("f_10632:expand_2escm"),(void*)f_10632},
{C_text("f_10635:expand_2escm"),(void*)f_10635},
{C_text("f_10638:expand_2escm"),(void*)f_10638},
{C_text("f_10641:expand_2escm"),(void*)f_10641},
{C_text("f_10644:expand_2escm"),(void*)f_10644},
{C_text("f_10647:expand_2escm"),(void*)f_10647},
{C_text("f_10650:expand_2escm"),(void*)f_10650},
{C_text("f_10653:expand_2escm"),(void*)f_10653},
{C_text("f_10656:expand_2escm"),(void*)f_10656},
{C_text("f_10658:expand_2escm"),(void*)f_10658},
{C_text("f_10664:expand_2escm"),(void*)f_10664},
{C_text("f_10674:expand_2escm"),(void*)f_10674},
{C_text("f_10692:expand_2escm"),(void*)f_10692},
{C_text("f_10700:expand_2escm"),(void*)f_10700},
{C_text("f_10710:expand_2escm"),(void*)f_10710},
{C_text("f_10737:expand_2escm"),(void*)f_10737},
{C_text("f_10752:expand_2escm"),(void*)f_10752},
{C_text("f_10756:expand_2escm"),(void*)f_10756},
{C_text("f_10761:expand_2escm"),(void*)f_10761},
{C_text("f_10767:expand_2escm"),(void*)f_10767},
{C_text("f_10771:expand_2escm"),(void*)f_10771},
{C_text("f_10775:expand_2escm"),(void*)f_10775},
{C_text("f_10779:expand_2escm"),(void*)f_10779},
{C_text("f_10783:expand_2escm"),(void*)f_10783},
{C_text("f_10787:expand_2escm"),(void*)f_10787},
{C_text("f_10792:expand_2escm"),(void*)f_10792},
{C_text("f_10799:expand_2escm"),(void*)f_10799},
{C_text("f_10804:expand_2escm"),(void*)f_10804},
{C_text("f_10808:expand_2escm"),(void*)f_10808},
{C_text("f_10812:expand_2escm"),(void*)f_10812},
{C_text("f_10816:expand_2escm"),(void*)f_10816},
{C_text("f_10821:expand_2escm"),(void*)f_10821},
{C_text("f_10825:expand_2escm"),(void*)f_10825},
{C_text("f_10829:expand_2escm"),(void*)f_10829},
{C_text("f_10833:expand_2escm"),(void*)f_10833},
{C_text("f_10835:expand_2escm"),(void*)f_10835},
{C_text("f_10841:expand_2escm"),(void*)f_10841},
{C_text("f_10869:expand_2escm"),(void*)f_10869},
{C_text("f_10879:expand_2escm"),(void*)f_10879},
{C_text("f_10893:expand_2escm"),(void*)f_10893},
{C_text("f_10918:expand_2escm"),(void*)f_10918},
{C_text("f_10935:expand_2escm"),(void*)f_10935},
{C_text("f_10942:expand_2escm"),(void*)f_10942},
{C_text("f_10963:expand_2escm"),(void*)f_10963},
{C_text("f_10967:expand_2escm"),(void*)f_10967},
{C_text("f_10971:expand_2escm"),(void*)f_10971},
{C_text("f_10973:expand_2escm"),(void*)f_10973},
{C_text("f_10978:expand_2escm"),(void*)f_10978},
{C_text("f_11001:expand_2escm"),(void*)f_11001},
{C_text("f_11035:expand_2escm"),(void*)f_11035},
{C_text("f_11071:expand_2escm"),(void*)f_11071},
{C_text("f_11075:expand_2escm"),(void*)f_11075},
{C_text("f_11079:expand_2escm"),(void*)f_11079},
{C_text("f_11128:expand_2escm"),(void*)f_11128},
{C_text("f_11136:expand_2escm"),(void*)f_11136},
{C_text("f_11149:expand_2escm"),(void*)f_11149},
{C_text("f_11182:expand_2escm"),(void*)f_11182},
{C_text("f_11186:expand_2escm"),(void*)f_11186},
{C_text("f_11241:expand_2escm"),(void*)f_11241},
{C_text("f_11265:expand_2escm"),(void*)f_11265},
{C_text("f_11309:expand_2escm"),(void*)f_11309},
{C_text("f_11333:expand_2escm"),(void*)f_11333},
{C_text("f_11339:expand_2escm"),(void*)f_11339},
{C_text("f_11352:expand_2escm"),(void*)f_11352},
{C_text("f_11356:expand_2escm"),(void*)f_11356},
{C_text("f_11368:expand_2escm"),(void*)f_11368},
{C_text("f_11414:expand_2escm"),(void*)f_11414},
{C_text("f_11418:expand_2escm"),(void*)f_11418},
{C_text("f_11443:expand_2escm"),(void*)f_11443},
{C_text("f_11449:expand_2escm"),(void*)f_11449},
{C_text("f_11488:expand_2escm"),(void*)f_11488},
{C_text("f_11491:expand_2escm"),(void*)f_11491},
{C_text("f_11497:expand_2escm"),(void*)f_11497},
{C_text("f_11509:expand_2escm"),(void*)f_11509},
{C_text("f_11512:expand_2escm"),(void*)f_11512},
{C_text("f_11515:expand_2escm"),(void*)f_11515},
{C_text("f_11528:expand_2escm"),(void*)f_11528},
{C_text("f_11532:expand_2escm"),(void*)f_11532},
{C_text("f_11536:expand_2escm"),(void*)f_11536},
{C_text("f_11538:expand_2escm"),(void*)f_11538},
{C_text("f_11559:expand_2escm"),(void*)f_11559},
{C_text("f_11611:expand_2escm"),(void*)f_11611},
{C_text("f_11615:expand_2escm"),(void*)f_11615},
{C_text("f_11632:expand_2escm"),(void*)f_11632},
{C_text("f_11636:expand_2escm"),(void*)f_11636},
{C_text("f_11641:expand_2escm"),(void*)f_11641},
{C_text("f_11667:expand_2escm"),(void*)f_11667},
{C_text("f_11682:expand_2escm"),(void*)f_11682},
{C_text("f_11701:expand_2escm"),(void*)f_11701},
{C_text("f_11716:expand_2escm"),(void*)f_11716},
{C_text("f_11718:expand_2escm"),(void*)f_11718},
{C_text("f_11760:expand_2escm"),(void*)f_11760},
{C_text("f_11771:expand_2escm"),(void*)f_11771},
{C_text("f_11790:expand_2escm"),(void*)f_11790},
{C_text("f_11805:expand_2escm"),(void*)f_11805},
{C_text("f_11807:expand_2escm"),(void*)f_11807},
{C_text("f_11814:expand_2escm"),(void*)f_11814},
{C_text("f_11835:expand_2escm"),(void*)f_11835},
{C_text("f_11859:expand_2escm"),(void*)f_11859},
{C_text("f_11866:expand_2escm"),(void*)f_11866},
{C_text("f_11873:expand_2escm"),(void*)f_11873},
{C_text("f_11879:expand_2escm"),(void*)f_11879},
{C_text("f_11889:expand_2escm"),(void*)f_11889},
{C_text("f_11896:expand_2escm"),(void*)f_11896},
{C_text("f_11917:expand_2escm"),(void*)f_11917},
{C_text("f_11921:expand_2escm"),(void*)f_11921},
{C_text("f_11925:expand_2escm"),(void*)f_11925},
{C_text("f_11928:expand_2escm"),(void*)f_11928},
{C_text("f_11932:expand_2escm"),(void*)f_11932},
{C_text("f_11936:expand_2escm"),(void*)f_11936},
{C_text("f_11940:expand_2escm"),(void*)f_11940},
{C_text("f_11942:expand_2escm"),(void*)f_11942},
{C_text("f_11946:expand_2escm"),(void*)f_11946},
{C_text("f_11954:expand_2escm"),(void*)f_11954},
{C_text("f_11963:expand_2escm"),(void*)f_11963},
{C_text("f_11976:expand_2escm"),(void*)f_11976},
{C_text("f_11978:expand_2escm"),(void*)f_11978},
{C_text("f_11982:expand_2escm"),(void*)f_11982},
{C_text("f_11989:expand_2escm"),(void*)f_11989},
{C_text("f_12009:expand_2escm"),(void*)f_12009},
{C_text("f_12011:expand_2escm"),(void*)f_12011},
{C_text("f_12015:expand_2escm"),(void*)f_12015},
{C_text("f_12018:expand_2escm"),(void*)f_12018},
{C_text("f_12021:expand_2escm"),(void*)f_12021},
{C_text("f_12023:expand_2escm"),(void*)f_12023},
{C_text("f_12031:expand_2escm"),(void*)f_12031},
{C_text("f_12033:expand_2escm"),(void*)f_12033},
{C_text("f_12047:expand_2escm"),(void*)f_12047},
{C_text("f_12051:expand_2escm"),(void*)f_12051},
{C_text("f_12070:expand_2escm"),(void*)f_12070},
{C_text("f_12079:expand_2escm"),(void*)f_12079},
{C_text("f_12093:expand_2escm"),(void*)f_12093},
{C_text("f_12103:expand_2escm"),(void*)f_12103},
{C_text("f_12114:expand_2escm"),(void*)f_12114},
{C_text("f_12124:expand_2escm"),(void*)f_12124},
{C_text("f_12133:expand_2escm"),(void*)f_12133},
{C_text("f_12144:expand_2escm"),(void*)f_12144},
{C_text("f_12155:expand_2escm"),(void*)f_12155},
{C_text("f_12163:expand_2escm"),(void*)f_12163},
{C_text("f_12178:expand_2escm"),(void*)f_12178},
{C_text("f_12182:expand_2escm"),(void*)f_12182},
{C_text("f_12196:expand_2escm"),(void*)f_12196},
{C_text("f_12200:expand_2escm"),(void*)f_12200},
{C_text("f_12204:expand_2escm"),(void*)f_12204},
{C_text("f_12226:expand_2escm"),(void*)f_12226},
{C_text("f_12230:expand_2escm"),(void*)f_12230},
{C_text("f_12273:expand_2escm"),(void*)f_12273},
{C_text("f_12291:expand_2escm"),(void*)f_12291},
{C_text("f_12302:expand_2escm"),(void*)f_12302},
{C_text("f_12304:expand_2escm"),(void*)f_12304},
{C_text("f_12308:expand_2escm"),(void*)f_12308},
{C_text("f_12320:expand_2escm"),(void*)f_12320},
{C_text("f_12348:expand_2escm"),(void*)f_12348},
{C_text("f_12369:expand_2escm"),(void*)f_12369},
{C_text("f_12410:expand_2escm"),(void*)f_12410},
{C_text("f_12412:expand_2escm"),(void*)f_12412},
{C_text("f_12422:expand_2escm"),(void*)f_12422},
{C_text("f_12462:expand_2escm"),(void*)f_12462},
{C_text("f_12498:expand_2escm"),(void*)f_12498},
{C_text("f_12500:expand_2escm"),(void*)f_12500},
{C_text("f_12504:expand_2escm"),(void*)f_12504},
{C_text("f_12514:expand_2escm"),(void*)f_12514},
{C_text("f_12539:expand_2escm"),(void*)f_12539},
{C_text("f_12549:expand_2escm"),(void*)f_12549},
{C_text("f_12551:expand_2escm"),(void*)f_12551},
{C_text("f_12555:expand_2escm"),(void*)f_12555},
{C_text("f_12563:expand_2escm"),(void*)f_12563},
{C_text("f_12566:expand_2escm"),(void*)f_12566},
{C_text("f_12569:expand_2escm"),(void*)f_12569},
{C_text("f_12572:expand_2escm"),(void*)f_12572},
{C_text("f_12575:expand_2escm"),(void*)f_12575},
{C_text("f_12586:expand_2escm"),(void*)f_12586},
{C_text("f_12588:expand_2escm"),(void*)f_12588},
{C_text("f_12602:expand_2escm"),(void*)f_12602},
{C_text("f_12608:expand_2escm"),(void*)f_12608},
{C_text("f_12611:expand_2escm"),(void*)f_12611},
{C_text("f_12615:expand_2escm"),(void*)f_12615},
{C_text("f_12621:expand_2escm"),(void*)f_12621},
{C_text("f_12624:expand_2escm"),(void*)f_12624},
{C_text("f_12639:expand_2escm"),(void*)f_12639},
{C_text("f_12680:expand_2escm"),(void*)f_12680},
{C_text("f_12684:expand_2escm"),(void*)f_12684},
{C_text("f_12687:expand_2escm"),(void*)f_12687},
{C_text("f_12720:expand_2escm"),(void*)f_12720},
{C_text("f_12735:expand_2escm"),(void*)f_12735},
{C_text("f_12737:expand_2escm"),(void*)f_12737},
{C_text("f_12785:expand_2escm"),(void*)f_12785},
{C_text("f_12787:expand_2escm"),(void*)f_12787},
{C_text("f_12794:expand_2escm"),(void*)f_12794},
{C_text("f_12797:expand_2escm"),(void*)f_12797},
{C_text("f_12800:expand_2escm"),(void*)f_12800},
{C_text("f_12805:expand_2escm"),(void*)f_12805},
{C_text("f_12819:expand_2escm"),(void*)f_12819},
{C_text("f_12825:expand_2escm"),(void*)f_12825},
{C_text("f_12828:expand_2escm"),(void*)f_12828},
{C_text("f_12832:expand_2escm"),(void*)f_12832},
{C_text("f_12838:expand_2escm"),(void*)f_12838},
{C_text("f_12841:expand_2escm"),(void*)f_12841},
{C_text("f_12844:expand_2escm"),(void*)f_12844},
{C_text("f_12847:expand_2escm"),(void*)f_12847},
{C_text("f_12851:expand_2escm"),(void*)f_12851},
{C_text("f_12857:expand_2escm"),(void*)f_12857},
{C_text("f_12860:expand_2escm"),(void*)f_12860},
{C_text("f_12863:expand_2escm"),(void*)f_12863},
{C_text("f_12869:expand_2escm"),(void*)f_12869},
{C_text("f_12895:expand_2escm"),(void*)f_12895},
{C_text("f_12923:expand_2escm"),(void*)f_12923},
{C_text("f_12940:expand_2escm"),(void*)f_12940},
{C_text("f_12946:expand_2escm"),(void*)f_12946},
{C_text("f_12949:expand_2escm"),(void*)f_12949},
{C_text("f_12968:expand_2escm"),(void*)f_12968},
{C_text("f_12986:expand_2escm"),(void*)f_12986},
{C_text("f_12989:expand_2escm"),(void*)f_12989},
{C_text("f_13016:expand_2escm"),(void*)f_13016},
{C_text("f_13043:expand_2escm"),(void*)f_13043},
{C_text("f_13111:expand_2escm"),(void*)f_13111},
{C_text("f_13123:expand_2escm"),(void*)f_13123},
{C_text("f_13139:expand_2escm"),(void*)f_13139},
{C_text("f_13173:expand_2escm"),(void*)f_13173},
{C_text("f_13175:expand_2escm"),(void*)f_13175},
{C_text("f_13198:expand_2escm"),(void*)f_13198},
{C_text("f_13217:expand_2escm"),(void*)f_13217},
{C_text("f_13225:expand_2escm"),(void*)f_13225},
{C_text("f_13227:expand_2escm"),(void*)f_13227},
{C_text("f_13258:expand_2escm"),(void*)f_13258},
{C_text("f_13262:expand_2escm"),(void*)f_13262},
{C_text("f_13264:expand_2escm"),(void*)f_13264},
{C_text("f_13268:expand_2escm"),(void*)f_13268},
{C_text("f_13291:expand_2escm"),(void*)f_13291},
{C_text("f_13306:expand_2escm"),(void*)f_13306},
{C_text("f_13308:expand_2escm"),(void*)f_13308},
{C_text("f_13312:expand_2escm"),(void*)f_13312},
{C_text("f_13315:expand_2escm"),(void*)f_13315},
{C_text("f_13328:expand_2escm"),(void*)f_13328},
{C_text("f_13330:expand_2escm"),(void*)f_13330},
{C_text("f_13334:expand_2escm"),(void*)f_13334},
{C_text("f_13337:expand_2escm"),(void*)f_13337},
{C_text("f_13350:expand_2escm"),(void*)f_13350},
{C_text("f_13352:expand_2escm"),(void*)f_13352},
{C_text("f_13356:expand_2escm"),(void*)f_13356},
{C_text("f_13359:expand_2escm"),(void*)f_13359},
{C_text("f_13372:expand_2escm"),(void*)f_13372},
{C_text("f_13374:expand_2escm"),(void*)f_13374},
{C_text("f_13378:expand_2escm"),(void*)f_13378},
{C_text("f_13389:expand_2escm"),(void*)f_13389},
{C_text("f_13399:expand_2escm"),(void*)f_13399},
{C_text("f_13424:expand_2escm"),(void*)f_13424},
{C_text("f_13426:expand_2escm"),(void*)f_13426},
{C_text("f_13430:expand_2escm"),(void*)f_13430},
{C_text("f_13447:expand_2escm"),(void*)f_13447},
{C_text("f_13450:expand_2escm"),(void*)f_13450},
{C_text("f_13456:expand_2escm"),(void*)f_13456},
{C_text("f_13463:expand_2escm"),(void*)f_13463},
{C_text("f_13467:expand_2escm"),(void*)f_13467},
{C_text("f_13471:expand_2escm"),(void*)f_13471},
{C_text("f_13473:expand_2escm"),(void*)f_13473},
{C_text("f_13477:expand_2escm"),(void*)f_13477},
{C_text("f_13482:expand_2escm"),(void*)f_13482},
{C_text("f_13497:expand_2escm"),(void*)f_13497},
{C_text("f_13508:expand_2escm"),(void*)f_13508},
{C_text("f_13511:expand_2escm"),(void*)f_13511},
{C_text("f_13533:expand_2escm"),(void*)f_13533},
{C_text("f_13540:expand_2escm"),(void*)f_13540},
{C_text("f_13544:expand_2escm"),(void*)f_13544},
{C_text("f_13553:expand_2escm"),(void*)f_13553},
{C_text("f_13560:expand_2escm"),(void*)f_13560},
{C_text("f_13563:expand_2escm"),(void*)f_13563},
{C_text("f_13598:expand_2escm"),(void*)f_13598},
{C_text("f_13600:expand_2escm"),(void*)f_13600},
{C_text("f_13604:expand_2escm"),(void*)f_13604},
{C_text("f_13615:expand_2escm"),(void*)f_13615},
{C_text("f_13617:expand_2escm"),(void*)f_13617},
{C_text("f_13621:expand_2escm"),(void*)f_13621},
{C_text("f_13632:expand_2escm"),(void*)f_13632},
{C_text("f_13634:expand_2escm"),(void*)f_13634},
{C_text("f_13638:expand_2escm"),(void*)f_13638},
{C_text("f_13649:expand_2escm"),(void*)f_13649},
{C_text("f_13651:expand_2escm"),(void*)f_13651},
{C_text("f_13655:expand_2escm"),(void*)f_13655},
{C_text("f_13666:expand_2escm"),(void*)f_13666},
{C_text("f_13668:expand_2escm"),(void*)f_13668},
{C_text("f_13672:expand_2escm"),(void*)f_13672},
{C_text("f_13675:expand_2escm"),(void*)f_13675},
{C_text("f_13685:expand_2escm"),(void*)f_13685},
{C_text("f_13689:expand_2escm"),(void*)f_13689},
{C_text("f_13691:expand_2escm"),(void*)f_13691},
{C_text("f_13695:expand_2escm"),(void*)f_13695},
{C_text("f_13698:expand_2escm"),(void*)f_13698},
{C_text("f_13701:expand_2escm"),(void*)f_13701},
{C_text("f_13724:expand_2escm"),(void*)f_13724},
{C_text("f_13727:expand_2escm"),(void*)f_13727},
{C_text("f_13773:expand_2escm"),(void*)f_13773},
{C_text("f_13775:expand_2escm"),(void*)f_13775},
{C_text("f_13779:expand_2escm"),(void*)f_13779},
{C_text("f_13782:expand_2escm"),(void*)f_13782},
{C_text("f_13805:expand_2escm"),(void*)f_13805},
{C_text("f_13833:expand_2escm"),(void*)f_13833},
{C_text("f_13838:expand_2escm"),(void*)f_13838},
{C_text("f_13845:expand_2escm"),(void*)f_13845},
{C_text("f_13848:expand_2escm"),(void*)f_13848},
{C_text("f_13857:expand_2escm"),(void*)f_13857},
{C_text("f_13902:expand_2escm"),(void*)f_13902},
{C_text("f_13904:expand_2escm"),(void*)f_13904},
{C_text("f_13929:expand_2escm"),(void*)f_13929},
{C_text("f_13940:expand_2escm"),(void*)f_13940},
{C_text("f_13944:expand_2escm"),(void*)f_13944},
{C_text("f_13946:expand_2escm"),(void*)f_13946},
{C_text("f_13954:expand_2escm"),(void*)f_13954},
{C_text("f_13956:expand_2escm"),(void*)f_13956},
{C_text("f_13968:expand_2escm"),(void*)f_13968},
{C_text("f_14020:expand_2escm"),(void*)f_14020},
{C_text("f_14026:expand_2escm"),(void*)f_14026},
{C_text("f_14029:expand_2escm"),(void*)f_14029},
{C_text("f_14032:expand_2escm"),(void*)f_14032},
{C_text("f_14037:expand_2escm"),(void*)f_14037},
{C_text("f_14062:expand_2escm"),(void*)f_14062},
{C_text("f_14077:expand_2escm"),(void*)f_14077},
{C_text("f_14079:expand_2escm"),(void*)f_14079},
{C_text("f_14083:expand_2escm"),(void*)f_14083},
{C_text("f_14086:expand_2escm"),(void*)f_14086},
{C_text("f_14089:expand_2escm"),(void*)f_14089},
{C_text("f_14096:expand_2escm"),(void*)f_14096},
{C_text("f_14104:expand_2escm"),(void*)f_14104},
{C_text("f_14106:expand_2escm"),(void*)f_14106},
{C_text("f_14110:expand_2escm"),(void*)f_14110},
{C_text("f_14116:expand_2escm"),(void*)f_14116},
{C_text("f_14122:expand_2escm"),(void*)f_14122},
{C_text("f_14125:expand_2escm"),(void*)f_14125},
{C_text("f_14137:expand_2escm"),(void*)f_14137},
{C_text("f_14140:expand_2escm"),(void*)f_14140},
{C_text("f_14171:expand_2escm"),(void*)f_14171},
{C_text("f_14175:expand_2escm"),(void*)f_14175},
{C_text("f_14178:expand_2escm"),(void*)f_14178},
{C_text("f_14185:expand_2escm"),(void*)f_14185},
{C_text("f_14194:expand_2escm"),(void*)f_14194},
{C_text("f_14219:expand_2escm"),(void*)f_14219},
{C_text("f_14253:expand_2escm"),(void*)f_14253},
{C_text("f_14267:expand_2escm"),(void*)f_14267},
{C_text("f_14279:expand_2escm"),(void*)f_14279},
{C_text("f_14281:expand_2escm"),(void*)f_14281},
{C_text("f_14287:expand_2escm"),(void*)f_14287},
{C_text("f_14297:expand_2escm"),(void*)f_14297},
{C_text("f_14311:expand_2escm"),(void*)f_14311},
{C_text("f_14327:expand_2escm"),(void*)f_14327},
{C_text("f_14351:expand_2escm"),(void*)f_14351},
{C_text("f_14386:expand_2escm"),(void*)f_14386},
{C_text("f_14420:expand_2escm"),(void*)f_14420},
{C_text("f_14442:expand_2escm"),(void*)f_14442},
{C_text("f_14467:expand_2escm"),(void*)f_14467},
{C_text("f_14469:expand_2escm"),(void*)f_14469},
{C_text("f_14548:expand_2escm"),(void*)f_14548},
{C_text("f_14560:expand_2escm"),(void*)f_14560},
{C_text("f_14572:expand_2escm"),(void*)f_14572},
{C_text("f_14574:expand_2escm"),(void*)f_14574},
{C_text("f_14578:expand_2escm"),(void*)f_14578},
{C_text("f_14589:expand_2escm"),(void*)f_14589},
{C_text("f_14599:expand_2escm"),(void*)f_14599},
{C_text("f_14607:expand_2escm"),(void*)f_14607},
{C_text("f_14609:expand_2escm"),(void*)f_14609},
{C_text("f_14618:expand_2escm"),(void*)f_14618},
{C_text("f_14624:expand_2escm"),(void*)f_14624},
{C_text("f_14630:expand_2escm"),(void*)f_14630},
{C_text("f_14634:expand_2escm"),(void*)f_14634},
{C_text("f_14637:expand_2escm"),(void*)f_14637},
{C_text("f_14640:expand_2escm"),(void*)f_14640},
{C_text("f_14671:expand_2escm"),(void*)f_14671},
{C_text("f_14680:expand_2escm"),(void*)f_14680},
{C_text("f_14682:expand_2escm"),(void*)f_14682},
{C_text("f_14707:expand_2escm"),(void*)f_14707},
{C_text("f_14718:expand_2escm"),(void*)f_14718},
{C_text("f_14720:expand_2escm"),(void*)f_14720},
{C_text("f_14728:expand_2escm"),(void*)f_14728},
{C_text("f_14730:expand_2escm"),(void*)f_14730},
{C_text("f_4499:expand_2escm"),(void*)f_4499},
{C_text("f_4502:expand_2escm"),(void*)f_4502},
{C_text("f_4505:expand_2escm"),(void*)f_4505},
{C_text("f_5788:expand_2escm"),(void*)f_5788},
{C_text("f_5792:expand_2escm"),(void*)f_5792},
{C_text("f_5794:expand_2escm"),(void*)f_5794},
{C_text("f_5811:expand_2escm"),(void*)f_5811},
{C_text("f_5818:expand_2escm"),(void*)f_5818},
{C_text("f_5824:expand_2escm"),(void*)f_5824},
{C_text("f_5858:expand_2escm"),(void*)f_5858},
{C_text("f_5864:expand_2escm"),(void*)f_5864},
{C_text("f_5880:expand_2escm"),(void*)f_5880},
{C_text("f_5935:expand_2escm"),(void*)f_5935},
{C_text("f_5942:expand_2escm"),(void*)f_5942},
{C_text("f_5960:expand_2escm"),(void*)f_5960},
{C_text("f_5969:expand_2escm"),(void*)f_5969},
{C_text("f_5990:expand_2escm"),(void*)f_5990},
{C_text("f_6000:expand_2escm"),(void*)f_6000},
{C_text("f_6004:expand_2escm"),(void*)f_6004},
{C_text("f_6029:expand_2escm"),(void*)f_6029},
{C_text("f_6044:expand_2escm"),(void*)f_6044},
{C_text("f_6046:expand_2escm"),(void*)f_6046},
{C_text("f_6094:expand_2escm"),(void*)f_6094},
{C_text("f_6143:expand_2escm"),(void*)f_6143},
{C_text("f_6168:expand_2escm"),(void*)f_6168},
{C_text("f_6182:expand_2escm"),(void*)f_6182},
{C_text("f_6191:expand_2escm"),(void*)f_6191},
{C_text("f_6215:expand_2escm"),(void*)f_6215},
{C_text("f_6219:expand_2escm"),(void*)f_6219},
{C_text("f_6222:expand_2escm"),(void*)f_6222},
{C_text("f_6229:expand_2escm"),(void*)f_6229},
{C_text("f_6247:expand_2escm"),(void*)f_6247},
{C_text("f_6257:expand_2escm"),(void*)f_6257},
{C_text("f_6261:expand_2escm"),(void*)f_6261},
{C_text("f_6283:expand_2escm"),(void*)f_6283},
{C_text("f_6294:expand_2escm"),(void*)f_6294},
{C_text("f_6302:expand_2escm"),(void*)f_6302},
{C_text("f_6306:expand_2escm"),(void*)f_6306},
{C_text("f_6308:expand_2escm"),(void*)f_6308},
{C_text("f_6331:expand_2escm"),(void*)f_6331},
{C_text("f_6339:expand_2escm"),(void*)f_6339},
{C_text("f_6342:expand_2escm"),(void*)f_6342},
{C_text("f_6352:expand_2escm"),(void*)f_6352},
{C_text("f_6357:expand_2escm"),(void*)f_6357},
{C_text("f_6363:expand_2escm"),(void*)f_6363},
{C_text("f_6369:expand_2escm"),(void*)f_6369},
{C_text("f_6391:expand_2escm"),(void*)f_6391},
{C_text("f_6397:expand_2escm"),(void*)f_6397},
{C_text("f_6414:expand_2escm"),(void*)f_6414},
{C_text("f_6425:expand_2escm"),(void*)f_6425},
{C_text("f_6464:expand_2escm"),(void*)f_6464},
{C_text("f_6470:expand_2escm"),(void*)f_6470},
{C_text("f_6474:expand_2escm"),(void*)f_6474},
{C_text("f_6477:expand_2escm"),(void*)f_6477},
{C_text("f_6493:expand_2escm"),(void*)f_6493},
{C_text("f_6497:expand_2escm"),(void*)f_6497},
{C_text("f_6504:expand_2escm"),(void*)f_6504},
{C_text("f_6510:expand_2escm"),(void*)f_6510},
{C_text("f_6515:expand_2escm"),(void*)f_6515},
{C_text("f_6521:expand_2escm"),(void*)f_6521},
{C_text("f_6529:expand_2escm"),(void*)f_6529},
{C_text("f_6535:expand_2escm"),(void*)f_6535},
{C_text("f_6541:expand_2escm"),(void*)f_6541},
{C_text("f_6567:expand_2escm"),(void*)f_6567},
{C_text("f_6585:expand_2escm"),(void*)f_6585},
{C_text("f_6609:expand_2escm"),(void*)f_6609},
{C_text("f_6615:expand_2escm"),(void*)f_6615},
{C_text("f_6627:expand_2escm"),(void*)f_6627},
{C_text("f_6639:expand_2escm"),(void*)f_6639},
{C_text("f_6664:expand_2escm"),(void*)f_6664},
{C_text("f_6666:expand_2escm"),(void*)f_6666},
{C_text("f_6729:expand_2escm"),(void*)f_6729},
{C_text("f_6735:expand_2escm"),(void*)f_6735},
{C_text("f_6773:expand_2escm"),(void*)f_6773},
{C_text("f_6777:expand_2escm"),(void*)f_6777},
{C_text("f_6781:expand_2escm"),(void*)f_6781},
{C_text("f_6793:expand_2escm"),(void*)f_6793},
{C_text("f_6832:expand_2escm"),(void*)f_6832},
{C_text("f_6846:expand_2escm"),(void*)f_6846},
{C_text("f_6856:expand_2escm"),(void*)f_6856},
{C_text("f_6859:expand_2escm"),(void*)f_6859},
{C_text("f_6863:expand_2escm"),(void*)f_6863},
{C_text("f_6877:expand_2escm"),(void*)f_6877},
{C_text("f_6883:expand_2escm"),(void*)f_6883},
{C_text("f_6889:expand_2escm"),(void*)f_6889},
{C_text("f_6925:expand_2escm"),(void*)f_6925},
{C_text("f_6931:expand_2escm"),(void*)f_6931},
{C_text("f_6972:expand_2escm"),(void*)f_6972},
{C_text("f_6975:expand_2escm"),(void*)f_6975},
{C_text("f_6992:expand_2escm"),(void*)f_6992},
{C_text("f_6995:expand_2escm"),(void*)f_6995},
{C_text("f_6998:expand_2escm"),(void*)f_6998},
{C_text("f_7003:expand_2escm"),(void*)f_7003},
{C_text("f_7017:expand_2escm"),(void*)f_7017},
{C_text("f_7021:expand_2escm"),(void*)f_7021},
{C_text("f_7033:expand_2escm"),(void*)f_7033},
{C_text("f_7064:expand_2escm"),(void*)f_7064},
{C_text("f_7089:expand_2escm"),(void*)f_7089},
{C_text("f_7108:expand_2escm"),(void*)f_7108},
{C_text("f_7112:expand_2escm"),(void*)f_7112},
{C_text("f_7161:expand_2escm"),(void*)f_7161},
{C_text("f_7214:expand_2escm"),(void*)f_7214},
{C_text("f_7218:expand_2escm"),(void*)f_7218},
{C_text("f_7221:expand_2escm"),(void*)f_7221},
{C_text("f_7224:expand_2escm"),(void*)f_7224},
{C_text("f_7226:expand_2escm"),(void*)f_7226},
{C_text("f_7251:expand_2escm"),(void*)f_7251},
{C_text("f_7265:expand_2escm"),(void*)f_7265},
{C_text("f_7306:expand_2escm"),(void*)f_7306},
{C_text("f_7319:expand_2escm"),(void*)f_7319},
{C_text("f_7335:expand_2escm"),(void*)f_7335},
{C_text("f_7356:expand_2escm"),(void*)f_7356},
{C_text("f_7395:expand_2escm"),(void*)f_7395},
{C_text("f_7414:expand_2escm"),(void*)f_7414},
{C_text("f_7482:expand_2escm"),(void*)f_7482},
{C_text("f_7581:expand_2escm"),(void*)f_7581},
{C_text("f_7587:expand_2escm"),(void*)f_7587},
{C_text("f_7591:expand_2escm"),(void*)f_7591},
{C_text("f_7594:expand_2escm"),(void*)f_7594},
{C_text("f_7613:expand_2escm"),(void*)f_7613},
{C_text("f_7617:expand_2escm"),(void*)f_7617},
{C_text("f_7635:expand_2escm"),(void*)f_7635},
{C_text("f_7657:expand_2escm"),(void*)f_7657},
{C_text("f_7723:expand_2escm"),(void*)f_7723},
{C_text("f_7748:expand_2escm"),(void*)f_7748},
{C_text("f_7761:expand_2escm"),(void*)f_7761},
{C_text("f_7765:expand_2escm"),(void*)f_7765},
{C_text("f_7776:expand_2escm"),(void*)f_7776},
{C_text("f_7783:expand_2escm"),(void*)f_7783},
{C_text("f_7792:expand_2escm"),(void*)f_7792},
{C_text("f_7812:expand_2escm"),(void*)f_7812},
{C_text("f_7823:expand_2escm"),(void*)f_7823},
{C_text("f_7825:expand_2escm"),(void*)f_7825},
{C_text("f_7827:expand_2escm"),(void*)f_7827},
{C_text("f_7833:expand_2escm"),(void*)f_7833},
{C_text("f_7840:expand_2escm"),(void*)f_7840},
{C_text("f_7849:expand_2escm"),(void*)f_7849},
{C_text("f_7885:expand_2escm"),(void*)f_7885},
{C_text("f_7896:expand_2escm"),(void*)f_7896},
{C_text("f_7900:expand_2escm"),(void*)f_7900},
{C_text("f_7904:expand_2escm"),(void*)f_7904},
{C_text("f_7908:expand_2escm"),(void*)f_7908},
{C_text("f_7912:expand_2escm"),(void*)f_7912},
{C_text("f_7914:expand_2escm"),(void*)f_7914},
{C_text("f_7926:expand_2escm"),(void*)f_7926},
{C_text("f_7940:expand_2escm"),(void*)f_7940},
{C_text("f_7945:expand_2escm"),(void*)f_7945},
{C_text("f_7956:expand_2escm"),(void*)f_7956},
{C_text("f_7962:expand_2escm"),(void*)f_7962},
{C_text("f_7976:expand_2escm"),(void*)f_7976},
{C_text("f_7980:expand_2escm"),(void*)f_7980},
{C_text("f_7988:expand_2escm"),(void*)f_7988},
{C_text("f_7995:expand_2escm"),(void*)f_7995},
{C_text("f_8007:expand_2escm"),(void*)f_8007},
{C_text("f_8014:expand_2escm"),(void*)f_8014},
{C_text("f_8018:expand_2escm"),(void*)f_8018},
{C_text("f_8025:expand_2escm"),(void*)f_8025},
{C_text("f_8056:expand_2escm"),(void*)f_8056},
{C_text("f_8085:expand_2escm"),(void*)f_8085},
{C_text("f_8117:expand_2escm"),(void*)f_8117},
{C_text("f_8123:expand_2escm"),(void*)f_8123},
{C_text("f_8129:expand_2escm"),(void*)f_8129},
{C_text("f_8135:expand_2escm"),(void*)f_8135},
{C_text("f_8167:expand_2escm"),(void*)f_8167},
{C_text("f_8170:expand_2escm"),(void*)f_8170},
{C_text("f_8176:expand_2escm"),(void*)f_8176},
{C_text("f_8180:expand_2escm"),(void*)f_8180},
{C_text("f_8202:expand_2escm"),(void*)f_8202},
{C_text("f_8205:expand_2escm"),(void*)f_8205},
{C_text("f_8208:expand_2escm"),(void*)f_8208},
{C_text("f_8211:expand_2escm"),(void*)f_8211},
{C_text("f_8213:expand_2escm"),(void*)f_8213},
{C_text("f_8220:expand_2escm"),(void*)f_8220},
{C_text("f_8246:expand_2escm"),(void*)f_8246},
{C_text("f_8275:expand_2escm"),(void*)f_8275},
{C_text("f_8309:expand_2escm"),(void*)f_8309},
{C_text("f_8333:expand_2escm"),(void*)f_8333},
{C_text("f_8335:expand_2escm"),(void*)f_8335},
{C_text("f_8339:expand_2escm"),(void*)f_8339},
{C_text("f_8351:expand_2escm"),(void*)f_8351},
{C_text("f_8359:expand_2escm"),(void*)f_8359},
{C_text("f_8361:expand_2escm"),(void*)f_8361},
{C_text("f_8383:expand_2escm"),(void*)f_8383},
{C_text("f_8386:expand_2escm"),(void*)f_8386},
{C_text("f_8388:expand_2escm"),(void*)f_8388},
{C_text("f_8435:expand_2escm"),(void*)f_8435},
{C_text("f_8439:expand_2escm"),(void*)f_8439},
{C_text("f_8507:expand_2escm"),(void*)f_8507},
{C_text("f_8513:expand_2escm"),(void*)f_8513},
{C_text("f_8536:expand_2escm"),(void*)f_8536},
{C_text("f_8551:expand_2escm"),(void*)f_8551},
{C_text("f_8554:expand_2escm"),(void*)f_8554},
{C_text("f_8559:expand_2escm"),(void*)f_8559},
{C_text("f_8572:expand_2escm"),(void*)f_8572},
{C_text("f_8575:expand_2escm"),(void*)f_8575},
{C_text("f_8625:expand_2escm"),(void*)f_8625},
{C_text("f_8632:expand_2escm"),(void*)f_8632},
{C_text("f_8639:expand_2escm"),(void*)f_8639},
{C_text("f_8688:expand_2escm"),(void*)f_8688},
{C_text("f_8691:expand_2escm"),(void*)f_8691},
{C_text("f_8700:expand_2escm"),(void*)f_8700},
{C_text("f_8703:expand_2escm"),(void*)f_8703},
{C_text("f_8732:expand_2escm"),(void*)f_8732},
{C_text("f_8739:expand_2escm"),(void*)f_8739},
{C_text("f_8755:expand_2escm"),(void*)f_8755},
{C_text("f_8825:expand_2escm"),(void*)f_8825},
{C_text("f_8828:expand_2escm"),(void*)f_8828},
{C_text("f_8842:expand_2escm"),(void*)f_8842},
{C_text("f_8882:expand_2escm"),(void*)f_8882},
{C_text("f_8905:expand_2escm"),(void*)f_8905},
{C_text("f_8907:expand_2escm"),(void*)f_8907},
{C_text("f_8910:expand_2escm"),(void*)f_8910},
{C_text("f_8954:expand_2escm"),(void*)f_8954},
{C_text("f_8962:expand_2escm"),(void*)f_8962},
{C_text("f_8970:expand_2escm"),(void*)f_8970},
{C_text("f_8973:expand_2escm"),(void*)f_8973},
{C_text("f_8984:expand_2escm"),(void*)f_8984},
{C_text("f_8989:expand_2escm"),(void*)f_8989},
{C_text("f_9009:expand_2escm"),(void*)f_9009},
{C_text("f_9013:expand_2escm"),(void*)f_9013},
{C_text("f_9028:expand_2escm"),(void*)f_9028},
{C_text("f_9040:expand_2escm"),(void*)f_9040},
{C_text("f_9042:expand_2escm"),(void*)f_9042},
{C_text("f_9049:expand_2escm"),(void*)f_9049},
{C_text("f_9056:expand_2escm"),(void*)f_9056},
{C_text("f_9058:expand_2escm"),(void*)f_9058},
{C_text("f_9068:expand_2escm"),(void*)f_9068},
{C_text("f_9071:expand_2escm"),(void*)f_9071},
{C_text("f_9074:expand_2escm"),(void*)f_9074},
{C_text("f_9077:expand_2escm"),(void*)f_9077},
{C_text("f_9080:expand_2escm"),(void*)f_9080},
{C_text("f_9087:expand_2escm"),(void*)f_9087},
{C_text("f_9094:expand_2escm"),(void*)f_9094},
{C_text("f_9097:expand_2escm"),(void*)f_9097},
{C_text("f_9106:expand_2escm"),(void*)f_9106},
{C_text("f_9109:expand_2escm"),(void*)f_9109},
{C_text("f_9112:expand_2escm"),(void*)f_9112},
{C_text("f_9115:expand_2escm"),(void*)f_9115},
{C_text("f_9118:expand_2escm"),(void*)f_9118},
{C_text("f_9121:expand_2escm"),(void*)f_9121},
{C_text("f_9134:expand_2escm"),(void*)f_9134},
{C_text("f_9138:expand_2escm"),(void*)f_9138},
{C_text("f_9149:expand_2escm"),(void*)f_9149},
{C_text("f_9153:expand_2escm"),(void*)f_9153},
{C_text("f_9155:expand_2escm"),(void*)f_9155},
{C_text("f_9169:expand_2escm"),(void*)f_9169},
{C_text("f_9173:expand_2escm"),(void*)f_9173},
{C_text("f_9200:expand_2escm"),(void*)f_9200},
{C_text("f_9206:expand_2escm"),(void*)f_9206},
{C_text("f_9226:expand_2escm"),(void*)f_9226},
{C_text("f_9250:expand_2escm"),(void*)f_9250},
{C_text("f_9254:expand_2escm"),(void*)f_9254},
{C_text("f_9260:expand_2escm"),(void*)f_9260},
{C_text("f_9266:expand_2escm"),(void*)f_9266},
{C_text("f_9279:expand_2escm"),(void*)f_9279},
{C_text("f_9301:expand_2escm"),(void*)f_9301},
{C_text("f_9318:expand_2escm"),(void*)f_9318},
{C_text("f_9326:expand_2escm"),(void*)f_9326},
{C_text("f_9346:expand_2escm"),(void*)f_9346},
{C_text("f_9350:expand_2escm"),(void*)f_9350},
{C_text("f_9354:expand_2escm"),(void*)f_9354},
{C_text("f_9365:expand_2escm"),(void*)f_9365},
{C_text("f_9372:expand_2escm"),(void*)f_9372},
{C_text("f_9375:expand_2escm"),(void*)f_9375},
{C_text("f_9379:expand_2escm"),(void*)f_9379},
{C_text("f_9406:expand_2escm"),(void*)f_9406},
{C_text("f_9412:expand_2escm"),(void*)f_9412},
{C_text("f_9419:expand_2escm"),(void*)f_9419},
{C_text("f_9422:expand_2escm"),(void*)f_9422},
{C_text("f_9425:expand_2escm"),(void*)f_9425},
{C_text("f_9438:expand_2escm"),(void*)f_9438},
{C_text("f_9440:expand_2escm"),(void*)f_9440},
{C_text("f_9474:expand_2escm"),(void*)f_9474},
{C_text("f_9477:expand_2escm"),(void*)f_9477},
{C_text("f_9483:expand_2escm"),(void*)f_9483},
{C_text("f_9493:expand_2escm"),(void*)f_9493},
{C_text("f_9502:expand_2escm"),(void*)f_9502},
{C_text("f_9519:expand_2escm"),(void*)f_9519},
{C_text("f_9525:expand_2escm"),(void*)f_9525},
{C_text("f_9556:expand_2escm"),(void*)f_9556},
{C_text("f_9566:expand_2escm"),(void*)f_9566},
{C_text("f_9571:expand_2escm"),(void*)f_9571},
{C_text("f_9578:expand_2escm"),(void*)f_9578},
{C_text("f_9583:expand_2escm"),(void*)f_9583},
{C_text("f_9587:expand_2escm"),(void*)f_9587},
{C_text("f_9594:expand_2escm"),(void*)f_9594},
{C_text("f_9601:expand_2escm"),(void*)f_9601},
{C_text("f_9608:expand_2escm"),(void*)f_9608},
{C_text("f_9610:expand_2escm"),(void*)f_9610},
{C_text("f_9614:expand_2escm"),(void*)f_9614},
{C_text("f_9622:expand_2escm"),(void*)f_9622},
{C_text("f_9655:expand_2escm"),(void*)f_9655},
{C_text("f_9661:expand_2escm"),(void*)f_9661},
{C_text("f_9667:expand_2escm"),(void*)f_9667},
{C_text("f_9688:expand_2escm"),(void*)f_9688},
{C_text("f_9693:expand_2escm"),(void*)f_9693},
{C_text("f_9712:expand_2escm"),(void*)f_9712},
{C_text("f_9717:expand_2escm"),(void*)f_9717},
{C_text("f_9736:expand_2escm"),(void*)f_9736},
{C_text("f_9890:expand_2escm"),(void*)f_9890},
{C_text("f_9947:expand_2escm"),(void*)f_9947},
{C_text("toplevel:expand_2escm"),(void*)C_expand_toplevel},
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
o|hiding unexported module binding: chicken.syntax#d 
o|hiding unexported module binding: chicken.syntax#define-alias 
o|hiding unexported module binding: chicken.syntax#partition 
o|hiding unexported module binding: chicken.syntax#span 
o|hiding unexported module binding: chicken.syntax#take 
o|hiding unexported module binding: chicken.syntax#drop 
o|hiding unexported module binding: chicken.syntax#split-at 
o|hiding unexported module binding: chicken.syntax#append-map 
o|hiding unexported module binding: chicken.syntax#every 
o|hiding unexported module binding: chicken.syntax#any 
o|hiding unexported module binding: chicken.syntax#cons* 
o|hiding unexported module binding: chicken.syntax#concatenate 
o|hiding unexported module binding: chicken.syntax#delete 
o|hiding unexported module binding: chicken.syntax#first 
o|hiding unexported module binding: chicken.syntax#second 
o|hiding unexported module binding: chicken.syntax#third 
o|hiding unexported module binding: chicken.syntax#fourth 
o|hiding unexported module binding: chicken.syntax#fifth 
o|hiding unexported module binding: chicken.syntax#delete-duplicates 
o|hiding unexported module binding: chicken.syntax#alist-cons 
o|hiding unexported module binding: chicken.syntax#filter 
o|hiding unexported module binding: chicken.syntax#filter-map 
o|hiding unexported module binding: chicken.syntax#remove 
o|hiding unexported module binding: chicken.syntax#unzip1 
o|hiding unexported module binding: chicken.syntax#last 
o|hiding unexported module binding: chicken.syntax#list-index 
o|hiding unexported module binding: chicken.syntax#lset-adjoin/eq? 
o|hiding unexported module binding: chicken.syntax#lset-difference/eq? 
o|hiding unexported module binding: chicken.syntax#lset-union/eq? 
o|hiding unexported module binding: chicken.syntax#lset-intersection/eq? 
o|hiding unexported module binding: chicken.syntax#list-tabulate 
o|hiding unexported module binding: chicken.syntax#lset<=/eq? 
o|hiding unexported module binding: chicken.syntax#lset=/eq? 
o|hiding unexported module binding: chicken.syntax#length+ 
o|hiding unexported module binding: chicken.syntax#find 
o|hiding unexported module binding: chicken.syntax#find-tail 
o|hiding unexported module binding: chicken.syntax#iota 
o|hiding unexported module binding: chicken.syntax#make-list 
o|hiding unexported module binding: chicken.syntax#posq 
o|hiding unexported module binding: chicken.syntax#posv 
o|hiding unexported module binding: chicken.syntax#d 
o|hiding unexported module binding: chicken.syntax#map-se 
o|hiding unexported module binding: chicken.syntax#dd 
o|hiding unexported module binding: chicken.syntax#dm 
o|hiding unexported module binding: chicken.syntax#dx 
o|hiding unexported module binding: chicken.syntax#lookup 
o|hiding unexported module binding: chicken.syntax#macro-alias 
o|hiding unexported module binding: chicken.syntax#expansion-result-hook 
o|hiding unexported module binding: chicken.syntax#defjam-error 
o|hiding unexported module binding: chicken.syntax#define-definition 
o|hiding unexported module binding: chicken.syntax#define-syntax-definition 
o|hiding unexported module binding: chicken.syntax#define-values-definition 
o|hiding unexported module binding: chicken.syntax#import-definition 
o|hiding unexported module binding: chicken.syntax#alist-weak-cons 
o|hiding unexported module binding: chicken.syntax#assq/drop-bwp! 
o|hiding unexported module binding: chicken.syntax#read-with-source-info-hook 
o|hiding unexported module binding: chicken.syntax#make-er/ir-transformer 
o|hiding unexported module binding: chicken.internal.syntax-rules#process-syntax-rules 
S|applied compiler syntax:
S|  chicken.format#sprintf		1
S|  ##sys#map		5
S|  scheme#for-each		1
S|  chicken.base#foldl		4
S|  scheme#map		17
S|  chicken.base#foldr		3
o|eliminated procedure checks: 591 
o|eliminated procedure checks: 1 
o|eliminated procedure checks: 1 
o|specializations:
o|  1 (scheme#zero? integer)
o|  1 (##sys#check-output-port * * *)
o|  1 (scheme#= fixnum fixnum)
o|  2 (scheme#cdddr (pair * (pair * pair)))
o|  7 (scheme#cddr (pair * pair))
o|  2 (scheme#vector-length vector)
o|  8 (scheme#eqv? (or eof null fixnum char boolean symbol keyword) *)
o|  1 (scheme#current-output-port)
o|  1 (##sys#check-input-port * * *)
o|  2 (scheme#caar (pair pair *))
o|  1 (scheme#>= fixnum fixnum)
o|  3 (scheme#length list)
o|  15 (scheme#eqv? * (or eof null fixnum char boolean symbol keyword))
o|  1 (scheme#set-cdr! pair *)
o|  1 (scheme#set-car! pair *)
o|  1 (scheme#eqv? * *)
o|  13 (##sys#check-list (or pair list) *)
o|  99 (scheme#cdr pair)
o|  73 (scheme#car pair)
(o e)|safe calls: 1491 
(o e)|assignments to immediate values: 8 
o|safe globals: (##sys#current-source-filename chicken.syntax#posv chicken.syntax#posq chicken.syntax#make-list chicken.syntax#iota chicken.syntax#find-tail chicken.syntax#find chicken.syntax#length+ chicken.syntax#lset=/eq? chicken.syntax#lset<=/eq? chicken.syntax#list-tabulate chicken.syntax#lset-intersection/eq? chicken.syntax#lset-union/eq? chicken.syntax#lset-difference/eq? chicken.syntax#lset-adjoin/eq? chicken.syntax#list-index chicken.syntax#last chicken.syntax#unzip1 chicken.syntax#remove chicken.syntax#filter-map chicken.syntax#filter chicken.syntax#alist-cons chicken.syntax#delete-duplicates chicken.syntax#fifth chicken.syntax#fourth chicken.syntax#third chicken.syntax#second chicken.syntax#first chicken.syntax#delete chicken.syntax#concatenate chicken.syntax#cons* chicken.syntax#any chicken.syntax#every chicken.syntax#append-map chicken.syntax#split-at chicken.syntax#drop chicken.syntax#take chicken.syntax#span chicken.syntax#partition) 
o|removed side-effect free assignment to unused variable: chicken.syntax#partition 
o|removed side-effect free assignment to unused variable: chicken.syntax#span 
o|removed side-effect free assignment to unused variable: chicken.syntax#drop 
o|removed side-effect free assignment to unused variable: chicken.syntax#split-at 
o|removed side-effect free assignment to unused variable: chicken.syntax#append-map 
o|inlining procedure: k4887 
o|inlining procedure: k4887 
o|inlining procedure: k4918 
o|inlining procedure: k4918 
o|removed side-effect free assignment to unused variable: chicken.syntax#cons* 
o|removed side-effect free assignment to unused variable: chicken.syntax#concatenate 
o|removed side-effect free assignment to unused variable: chicken.syntax#first 
o|removed side-effect free assignment to unused variable: chicken.syntax#second 
o|removed side-effect free assignment to unused variable: chicken.syntax#third 
o|removed side-effect free assignment to unused variable: chicken.syntax#fourth 
o|removed side-effect free assignment to unused variable: chicken.syntax#fifth 
o|removed side-effect free assignment to unused variable: chicken.syntax#delete-duplicates 
o|inlining procedure: k5135 
o|inlining procedure: k5135 
o|inlining procedure: k5127 
o|inlining procedure: k5127 
o|removed side-effect free assignment to unused variable: chicken.syntax#filter-map 
o|removed side-effect free assignment to unused variable: chicken.syntax#remove 
o|removed side-effect free assignment to unused variable: chicken.syntax#unzip1 
o|removed side-effect free assignment to unused variable: chicken.syntax#last 
o|removed side-effect free assignment to unused variable: chicken.syntax#list-index 
o|removed side-effect free assignment to unused variable: chicken.syntax#lset-adjoin/eq? 
o|removed side-effect free assignment to unused variable: chicken.syntax#lset-difference/eq? 
o|removed side-effect free assignment to unused variable: chicken.syntax#lset-union/eq? 
o|removed side-effect free assignment to unused variable: chicken.syntax#lset-intersection/eq? 
o|inlining procedure: k5526 
o|inlining procedure: k5526 
o|removed side-effect free assignment to unused variable: chicken.syntax#lset<=/eq? 
o|removed side-effect free assignment to unused variable: chicken.syntax#lset=/eq? 
o|removed side-effect free assignment to unused variable: chicken.syntax#length+ 
o|removed side-effect free assignment to unused variable: chicken.syntax#find 
o|removed side-effect free assignment to unused variable: chicken.syntax#find-tail 
o|removed side-effect free assignment to unused variable: chicken.syntax#iota 
o|removed side-effect free assignment to unused variable: chicken.syntax#make-list 
o|removed side-effect free assignment to unused variable: chicken.syntax#posq 
o|removed side-effect free assignment to unused variable: chicken.syntax#posv 
o|inlining procedure: k5796 
o|inlining procedure: k5796 
o|contracted procedure: "(expand.scm:93) g810811" 
o|inlining procedure: k5813 
o|inlining procedure: k5813 
o|contracted procedure: "(expand.scm:103) g843844" 
o|contracted procedure: "(expand.scm:102) g838839" 
o|contracted procedure: "(expand.scm:101) g832833" 
o|contracted procedure: "(expand.scm:97) g820821" 
o|inlining procedure: k5869 
o|inlining procedure: k5869 
o|inlining procedure: k5881 
o|inlining procedure: k5900 
o|inlining procedure: k5900 
o|contracted procedure: "(expand.scm:117) g874875" 
o|contracted procedure: "(expand.scm:116) g863864" 
o|inlining procedure: k5881 
o|inlining procedure: k5949 
o|inlining procedure: k5971 
o|inlining procedure: k5971 
o|inlining procedure: k5949 
o|inlining procedure: k6048 
o|contracted procedure: "(expand.scm:142) g975985" 
o|inlining procedure: k6048 
o|inlining procedure: k6096 
o|contracted procedure: "(expand.scm:137) g933941" 
o|contracted procedure: "(expand.scm:140) g951952" 
o|contracted procedure: "(expand.scm:139) g947948" 
o|inlining procedure: k6096 
o|inlining procedure: k6145 
o|inlining procedure: k6145 
o|inlining procedure: k6196 
o|inlining procedure: k6196 
o|inlining procedure: k6226 
o|inlining procedure: k6226 
o|inlining procedure: k6268 
o|inlining procedure: k6268 
o|inlining procedure: k6310 
o|inlining procedure: k6310 
o|inlining procedure: k6375 
o|inlining procedure: k6399 
o|inlining procedure: k6399 
o|inlining procedure: k6442 
o|inlining procedure: k6442 
o|inlining procedure: k6375 
o|inlining procedure: k6546 
o|inlining procedure: k6546 
o|inlining procedure: k6587 
o|inlining procedure: k6610 
o|inlining procedure: k6610 
o|inlining procedure: k6631 
o|inlining procedure: k6668 
o|inlining procedure: k6668 
o|inlining procedure: k6737 
o|contracted procedure: "(expand.scm:279) g11611170" 
o|inlining procedure: k6737 
o|inlining procedure: k6631 
o|inlining procedure: k6782 
o|inlining procedure: k6782 
o|inlining procedure: k6774 
o|inlining procedure: k6774 
o|inlining procedure: k6812 
o|contracted procedure: "(expand.scm:284) g12111212" 
o|inlining procedure: k6812 
o|inlining procedure: k6840 
o|inlining procedure: k6840 
o|inlining procedure: k6587 
o|inlining procedure: k6891 
o|inlining procedure: k6891 
o|inlining procedure: k6933 
o|inlining procedure: k6959 
o|inlining procedure: k6959 
o|substituted constant variable: a6966 
o|substituted constant variable: a6968 
o|substituted constant variable: a6970 
o|inlining procedure: k6933 
o|inlining procedure: k7005 
o|inlining procedure: k7022 
o|inlining procedure: k7022 
o|substituted constant variable: %let1295 
o|inlining procedure: k7065 
o|inlining procedure: k7065 
o|inlining procedure: k7118 
o|inlining procedure: k7118 
o|inlining procedure: k7130 
o|inlining procedure: k7130 
o|inlining procedure: k7190 
o|substituted constant variable: %lambda1292 
o|inlining procedure: k7190 
o|contracted procedure: "(expand.scm:358) ->keyword1286" 
o|inlining procedure: k7228 
o|inlining procedure: k7228 
o|inlining procedure: k7005 
o|inlining procedure: k7275 
o|inlining procedure: k7275 
o|inlining procedure: k7292 
o|inlining procedure: k7292 
o|inlining procedure: k7320 
o|inlining procedure: k7320 
o|inlining procedure: k7336 
o|inlining procedure: k7348 
o|inlining procedure: k7348 
o|inlining procedure: k7336 
o|inlining procedure: k7396 
o|inlining procedure: k7396 
o|inlining procedure: k7415 
o|inlining procedure: k7434 
o|inlining procedure: k7434 
o|substituted constant variable: a7472 
o|substituted constant variable: a7474 
o|substituted constant variable: a7476 
o|inlining procedure: k7415 
o|inlining procedure: k7483 
o|inlining procedure: k7483 
o|inlining procedure: k7505 
o|inlining procedure: k7505 
o|substituted constant variable: a7522 
o|substituted constant variable: a7524 
o|substituted constant variable: a7526 
o|inlining procedure: k7533 
o|inlining procedure: k7533 
o|substituted constant variable: a7549 
o|substituted constant variable: a7551 
o|substituted constant variable: a7553 
o|inlining procedure: k7557 
o|inlining procedure: k7557 
o|inlining procedure: k7637 
o|inlining procedure: k7637 
o|inlining procedure: k7659 
o|contracted procedure: "(expand.scm:449) g14551465" 
o|inlining procedure: k7659 
o|inlining procedure: k7725 
o|inlining procedure: k7725 
o|inlining procedure: k7784 
o|inlining procedure: k7784 
o|inlining procedure: k7841 
o|inlining procedure: k7856 
o|inlining procedure: k7856 
o|inlining procedure: k7841 
o|inlining procedure: k7916 
o|inlining procedure: k7928 
o|inlining procedure: k7928 
o|inlining procedure: k7951 
o|inlining procedure: k7951 
o|inlining procedure: k8002 
o|inlining procedure: k8020 
o|inlining procedure: k8020 
o|inlining procedure: k8002 
o|inlining procedure: k8077 
o|inlining procedure: k8077 
o|inlining procedure: k8109 
o|inlining procedure: k8124 
o|inlining procedure: k8124 
o|inlining procedure: k8136 
o|inlining procedure: k8136 
o|inlining procedure: k8109 
o|inlining procedure: k7916 
o|inlining procedure: k8215 
o|contracted procedure: "(expand.scm:543) g16581669" 
o|inlining procedure: k8187 
o|inlining procedure: k8187 
o|inlining procedure: k8215 
o|inlining procedure: k8265 
o|inlining procedure: k8265 
o|inlining procedure: k8277 
o|contracted procedure: "(expand.scm:535) g16101619" 
o|inlining procedure: k8277 
o|inlining procedure: k8311 
o|contracted procedure: "(expand.scm:538) g16341635" 
o|inlining procedure: k8311 
o|substituted constant variable: g16261629 
o|inlining procedure: k8363 
o|inlining procedure: k8390 
o|inlining procedure: k8390 
o|inlining procedure: k8363 
o|inlining procedure: k8430 
o|inlining procedure: "(expand.scm:571) chicken.syntax#defjam-error" 
o|inlining procedure: k8430 
o|inlining procedure: k8469 
o|inlining procedure: k8469 
o|substituted constant variable: a8491 
o|inlining procedure: k8518 
o|inlining procedure: k8518 
o|inlining procedure: k8546 
o|inlining procedure: k8564 
o|inlining procedure: k8592 
o|inlining procedure: k8592 
o|inlining procedure: "(expand.scm:597) chicken.syntax#defjam-error" 
o|inlining procedure: k8564 
o|inlining procedure: k8546 
o|inlining procedure: k8695 
o|inlining procedure: k8695 
o|inlining procedure: k8744 
o|inlining procedure: k8744 
o|inlining procedure: k8780 
o|inlining procedure: k8780 
o|inlining procedure: k8830 
o|inlining procedure: k8854 
o|inlining procedure: k8854 
o|inlining procedure: k8830 
o|inlining procedure: k8877 
o|inlining procedure: k8877 
o|inlining procedure: k8900 
o|inlining procedure: k8900 
o|inlining procedure: k8912 
o|inlining procedure: k8912 
o|inlining procedure: k9029 
o|inlining procedure: k9029 
o|inlining procedure: k9060 
o|inlining procedure: k9060 
o|inlining procedure: k9122 
o|inlining procedure: k9122 
o|inlining procedure: k9157 
o|inlining procedure: k9157 
o|contracted procedure: "(expand.scm:711) syntax-imports1841" 
o|inlining procedure: k8991 
o|inlining procedure: k8991 
o|inlining procedure: k9208 
o|inlining procedure: k9208 
o|inlining procedure: k9221 
o|inlining procedure: k9221 
o|inlining procedure: k9252 
o|inlining procedure: "(expand.scm:760) chicken.syntax#alist-weak-cons" 
o|propagated global variable: tmp19121914 ##sys#current-source-filename 
o|inlining procedure: k9281 
o|propagated global variable: tmp19121914 ##sys#current-source-filename 
o|inlining procedure: k9281 
o|inlining procedure: k9252 
o|substituted constant variable: a9310 
o|substituted constant variable: a9311 
o|inlining procedure: k9328 
o|inlining procedure: k9338 
o|inlining procedure: k9355 
o|inlining procedure: k9355 
o|inlining procedure: k9338 
o|inlining procedure: k9328 
o|inlining procedure: k9376 
o|inlining procedure: k9376 
o|inlining procedure: k9414 
o|inlining procedure: k9442 
o|inlining procedure: k9442 
o|propagated global variable: port1964 ##sys#standard-output 
o|inlining procedure: k9414 
o|inlining procedure: k9485 
o|inlining procedure: k9485 
o|inlining procedure: k9507 
o|inlining procedure: k9507 
o|contracted procedure: "(expand.scm:819) chicken.syntax#alist-cons" 
o|inlining procedure: k9573 
o|inlining procedure: k9573 
o|inlining procedure: k9592 
o|inlining procedure: k9592 
o|propagated global variable: sexp2048 ##sys#syntax-error-culprit 
o|inlining procedure: k9615 
o|inlining procedure: k9615 
o|inlining procedure: k9627 
o|inlining procedure: k9627 
o|inlining procedure: k9636 
o|inlining procedure: k9636 
o|inlining procedure: k9672 
o|inlining procedure: k9672 
o|inlining procedure: k9695 
o|inlining procedure: k9719 
o|inlining procedure: k9719 
o|inlining procedure: k9754 
o|inlining procedure: k9754 
o|inlining procedure: k9777 
o|inlining procedure: k9777 
o|inlining procedure: k9695 
o|inlining procedure: k9798 
o|inlining procedure: k9798 
o|inlining procedure: k9811 
o|inlining procedure: k9823 
o|inlining procedure: k9823 
o|inlining procedure: k9841 
o|inlining procedure: k9841 
o|inlining procedure: k9859 
o|inlining procedure: k9859 
o|inlining procedure: k9877 
o|inlining procedure: k9877 
o|inlining procedure: k9899 
o|inlining procedure: k9899 
o|substituted constant variable: a9912 
o|substituted constant variable: a9914 
o|substituted constant variable: a9916 
o|substituted constant variable: a9918 
o|substituted constant variable: a9920 
o|substituted constant variable: a9922 
o|substituted constant variable: a9924 
o|substituted constant variable: a9926 
o|inlining procedure: k9811 
o|inlining procedure: k9936 
o|inlining procedure: k9936 
o|inlining procedure: k10014 
o|inlining procedure: k10026 
o|inlining procedure: k10038 
o|inlining procedure: k10038 
o|inlining procedure: "(expand.scm:924) chicken.syntax#alist-weak-cons" 
o|inlining procedure: k10026 
o|inlining procedure: k10014 
o|inlining procedure: k10060 
o|inlining procedure: k10060 
o|inlining procedure: k10102 
o|inlining procedure: k10102 
o|contracted procedure: "(expand.scm:928) g21582159" 
o|inlining procedure: k10146 
o|inlining procedure: k10161 
o|inlining procedure: k10161 
o|inlining procedure: k10146 
o|inlining procedure: k10184 
o|inlining procedure: k10205 
o|inlining procedure: k10205 
o|inlining procedure: k10184 
o|inlining procedure: k10242 
o|inlining procedure: k10270 
o|inlining procedure: k10270 
o|inlining procedure: k10301 
o|inlining procedure: k10301 
o|inlining procedure: k10335 
o|inlining procedure: k10335 
o|removed unused parameter to known procedure: n2237 "(expand.scm:961) lookup22148" 
o|contracted procedure: "(expand.scm:960) g22052206" 
o|inlining procedure: k10341 
o|inlining procedure: k10341 
o|removed unused parameter to known procedure: n2237 "(expand.scm:958) lookup22148" 
o|contracted procedure: "(expand.scm:957) g21952196" 
o|inlining procedure: k10242 
o|removed unused formal parameters: (n2237) 
o|inlining procedure: k10365 
o|inlining procedure: k10365 
o|inlining procedure: k10390 
o|inlining procedure: k10390 
o|inlining procedure: k10432 
o|inlining procedure: k10432 
o|contracted procedure: "(expand.scm:998) g22622263" 
o|inlining procedure: k10458 
o|inlining procedure: k10458 
o|inlining procedure: k10487 
o|contracted procedure: "(expand.scm:998) g22792280" 
o|inlining procedure: k10487 
o|contracted procedure: "(expand.scm:1005) g22752276" 
o|inlining procedure: k10508 
o|inlining procedure: k10508 
o|inlining procedure: k10676 
o|inlining procedure: k10676 
o|inlining procedure: k10712 
o|inlining procedure: k10712 
o|contracted procedure: "(synrules.scm:57) chicken.internal.syntax-rules#process-syntax-rules" 
o|removed side-effect free assignment to unused variable: %vector-length3307 
o|removed side-effect free assignment to unused variable: %vector-ref3308 
o|removed side-effect free assignment to unused variable: %null?3330 
o|removed side-effect free assignment to unused variable: %or3331 
o|removed side-effect free assignment to unused variable: %syntax-error3337 
o|inlining procedure: k10895 
o|inlining procedure: k10895 
o|inlining procedure: k10937 
o|inlining procedure: k10937 
o|inlining procedure: k10985 
o|inlining procedure: k10985 
o|inlining procedure: k11003 
o|inlining procedure: k11003 
o|inlining procedure: k11039 
o|inlining procedure: k11039 
o|inlining procedure: k11141 
o|inlining procedure: k11141 
o|inlining procedure: k11175 
o|inlining procedure: k11175 
o|inlining procedure: k11311 
o|inlining procedure: k11311 
o|inlining procedure: k11374 
o|inlining procedure: k11374 
o|inlining procedure: k11402 
o|inlining procedure: k11402 
o|inlining procedure: k11451 
o|inlining procedure: k11463 
o|inlining procedure: k11463 
o|inlining procedure: k11451 
o|inlining procedure: k11498 
o|inlining procedure: k11498 
o|substituted constant variable: %append3300 
o|inlining procedure: k11540 
o|inlining procedure: k11540 
o|substituted constant variable: %apply3301 
o|substituted constant variable: %append3300 
o|inlining procedure: k11574 
o|inlining procedure: k11574 
o|inlining procedure: k11599 
o|inlining procedure: k11599 
o|inlining procedure: k11643 
o|inlining procedure: k11643 
o|inlining procedure: k11687 
o|inlining procedure: k11687 
o|inlining procedure: k11720 
o|inlining procedure: k11741 
o|inlining procedure: k11741 
o|inlining procedure: k11720 
o|inlining procedure: k11776 
o|inlining procedure: k11776 
o|inlining procedure: k11809 
o|inlining procedure: k11821 
o|inlining procedure: k11821 
o|inlining procedure: k11809 
o|inlining procedure: k11837 
o|inlining procedure: k11837 
o|inlining procedure: k11861 
o|inlining procedure: k11861 
o|inlining procedure: k11891 
o|inlining procedure: k11891 
o|inlining procedure: k12035 
o|inlining procedure: k12035 
o|inlining procedure: k12065 
o|inlining procedure: k12065 
o|inlining procedure: k12119 
o|inlining procedure: k12119 
o|inlining procedure: k12201 
o|inlining procedure: k12201 
o|inlining procedure: k12235 
o|inlining procedure: k12235 
o|inlining procedure: k12274 
o|contracted procedure: "(expand.scm:1667) g32413242" 
o|inlining procedure: k12274 
o|inlining procedure: k12414 
o|contracted procedure: "(expand.scm:1624) g31443153" 
o|inlining procedure: k12384 
o|inlining procedure: k12384 
o|inlining procedure: k12414 
o|inlining procedure: k12464 
o|contracted procedure: "(expand.scm:1613) g31103119" 
o|inlining procedure: k12464 
o|inlining procedure: k12516 
o|inlining procedure: k12516 
o|inlining procedure: k12590 
o|inlining procedure: k12590 
o|inlining procedure: k12616 
o|inlining procedure: k12634 
o|inlining procedure: k12634 
o|inlining procedure: k12616 
o|inlining procedure: k12739 
o|inlining procedure: k12739 
o|inlining procedure: k12807 
o|inlining procedure: k12807 
o|substituted constant variable: a12834 
o|substituted constant variable: a12835 
o|inlining procedure: k12852 
o|inlining procedure: k12879 
o|inlining procedure: k12879 
o|inlining procedure: k12852 
o|inlining procedure: k12941 
o|inlining procedure: k12941 
o|inlining procedure: k13077 
o|inlining procedure: k13077 
o|inlining procedure: k13089 
o|inlining procedure: k13089 
o|inlining procedure: k13101 
o|inlining procedure: k13101 
o|inlining procedure: k13112 
o|inlining procedure: k13112 
o|inlining procedure: k13124 
o|inlining procedure: k13124 
o|inlining procedure: k13180 
o|inlining procedure: k13180 
o|inlining procedure: k13232 
o|inlining procedure: k13232 
o|inlining procedure: k13275 
o|inlining procedure: k13275 
o|inlining procedure: "(expand.scm:1390) chicken.syntax#defjam-error" 
o|contracted procedure: "(expand.scm:1387) g28212822" 
o|inlining procedure: k13489 
o|inlining procedure: k13524 
o|inlining procedure: k13524 
o|inlining procedure: "(expand.scm:1365) chicken.syntax#defjam-error" 
o|contracted procedure: "(expand.scm:1362) g27922793" 
o|inlining procedure: k13489 
o|inlining procedure: k13676 
o|inlining procedure: k13676 
o|inlining procedure: k13725 
o|inlining procedure: k13725 
o|inlining procedure: k13740 
o|inlining procedure: k13740 
o|inlining procedure: k13846 
o|inlining procedure: k13846 
o|inlining procedure: k13861 
o|inlining procedure: k13873 
o|inlining procedure: k13873 
o|substituted constant variable: a13890 
o|inlining procedure: k13861 
o|inlining procedure: k13906 
o|inlining procedure: k13906 
o|propagated global variable: g26662667 ##sys#expand-import 
o|inlining procedure: k14030 
o|inlining procedure: k14030 
o|inlining procedure: k14039 
o|contracted procedure: "(expand.scm:1222) g26302639" 
o|inlining procedure: k13963 
o|inlining procedure: k13963 
o|inlining procedure: k13986 
o|inlining procedure: k13998 
o|inlining procedure: k13998 
o|inlining procedure: k13986 
o|inlining procedure: k14039 
o|inlining procedure: k14087 
o|inlining procedure: k14087 
o|inlining procedure: k14117 
o|inlining procedure: k14117 
o|inlining procedure: k14214 
o|inlining procedure: k14214 
o|inlining procedure: k14234 
o|inlining procedure: k14234 
o|inlining procedure: k14299 
o|inlining procedure: k14299 
o|inlining procedure: k14328 
o|inlining procedure: k14340 
o|inlining procedure: k14340 
o|inlining procedure: k14328 
o|inlining procedure: k14372 
o|inlining procedure: k14387 
o|inlining procedure: k14387 
o|inlining procedure: k14372 
o|inlining procedure: k14408 
o|inlining procedure: k14408 
o|substituted constant variable: a14429 
o|substituted constant variable: a14431 
o|substituted constant variable: a14433 
o|inlining procedure: k14444 
o|inlining procedure: k14471 
o|contracted procedure: "(expand.scm:1126) g25412550" 
o|inlining procedure: k14471 
o|inlining procedure: k14444 
o|inlining procedure: k14515 
o|inlining procedure: k14515 
o|inlining procedure: k14534 
o|inlining procedure: k14534 
o|inlining procedure: k14543 
o|inlining procedure: k14543 
o|inlining procedure: k14641 
o|inlining procedure: k14641 
o|inlining procedure: k14684 
o|inlining procedure: k14684 
o|propagated global variable: g24142415 ##sys#expand-import 
o|propagated global variable: g24002401 ##sys#expand-import 
o|replaced variables: 2564 
o|removed binding forms: 554 
o|removed side-effect free assignment to unused variable: chicken.syntax#every 
o|removed side-effect free assignment to unused variable: chicken.syntax#any 
o|removed side-effect free assignment to unused variable: chicken.syntax#filter 
o|removed side-effect free assignment to unused variable: chicken.syntax#list-tabulate 
o|substituted constant variable: prop813 
o|removed call to pure procedure with unused result: "(expand.scm:104) chicken.base#void" 
o|substituted constant variable: prop846 
o|substituted constant variable: prop841 
o|substituted constant variable: prop835 
o|substituted constant variable: prop877 
o|substituted constant variable: prop866 
o|substituted constant variable: prop954 
o|inlining procedure: k6018 
o|inlining procedure: k6018 
o|substituted constant variable: prop950 
o|substituted constant variable: r631114771 
o|substituted constant variable: r640014775 
o|substituted constant variable: r644314778 
o|removed call to pure procedure with unused result: "(expand.scm:237) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:196) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:195) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:240) chicken.base#void" 
o|inlining procedure: k6791 
o|substituted constant variable: prop1214 
o|substituted constant variable: r681314797 
o|substituted constant variable: r693414808 
o|substituted constant variable: r713114821 
o|substituted constant variable: r719114824 
o|substituted constant variable: r719114824 
o|substituted constant variable: r753414850 
o|substituted constant variable: r755814852 
o|converted assignments to bindings: (err1285) 
o|removed side-effect free assignment to unused variable: chicken.syntax#defjam-error 
o|substituted constant variable: r763814853 
o|substituted constant variable: r763814853 
o|inlining procedure: k7637 
o|substituted constant variable: r778514862 
o|substituted constant variable: r785714865 
o|substituted constant variable: r784214866 
o|substituted constant variable: r807814879 
o|substituted constant variable: r811014885 
o|removed call to pure procedure with unused result: "(expand.scm:554) chicken.base#void" 
o|substituted constant variable: r826614892 
o|substituted constant variable: r847014909 
o|substituted constant variable: r859314916 
o|substituted constant variable: r859314916 
o|substituted constant variable: r878114930 
o|removed call to pure procedure with unused result: "(expand.scm:580) chicken.base#void" 
o|substituted constant variable: r885514932 
o|substituted constant variable: r887814936 
o|substituted constant variable: r890114938 
o|substituted constant variable: r915814947 
o|substituted constant variable: r899214949 
o|converted assignments to bindings: (outstr1854) 
o|removed side-effect free assignment to unused variable: chicken.syntax#alist-weak-cons 
o|substituted constant variable: r920914951 
o|propagated global variable: r928214964 ##sys#current-source-filename 
o|substituted constant variable: r928214966 
o|substituted constant variable: r928214966 
o|substituted constant variable: r935614973 
o|substituted constant variable: r933914974 
o|substituted constant variable: r932914975 
o|substituted constant variable: r963714997 
o|substituted constant variable: r977815006 
o|inlining procedure: k10014 
o|inlining procedure: k10014 
o|inlining procedure: k10014 
o|substituted constant variable: r1002715038 
o|inlining procedure: k10014 
o|removed call to pure procedure with unused result: "(expand.scm:935) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:939) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|inlining procedure: k10146 
o|substituted constant variable: r1016215052 
o|inlining procedure: k10146 
o|inlining procedure: k10146 
o|inlining procedure: k10146 
o|substituted constant variable: r1018515062 
o|inlining procedure: k10146 
o|inlining procedure: k10146 
o|substituted constant variable: prop2208 
o|substituted constant variable: prop2198 
o|removed call to pure procedure with unused result: "(expand.scm:978) chicken.base#void" 
o|substituted constant variable: r1036615073 
o|removed call to pure procedure with unused result: "(expand.scm:1000) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:1002) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:1004) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:1007) chicken.base#void" 
o|removed call to pure procedure with unused result: "(expand.scm:1012) chicken.base#void" 
o|substituted constant variable: prop2278 
o|converted assignments to bindings: (inherit-pair-line-numbers2131) 
o|substituted constant variable: r1067715086 
o|removed side-effect free assignment to unused variable: %append3300 
o|removed side-effect free assignment to unused variable: %apply3301 
o|substituted constant variable: r1098615094 
o|substituted constant variable: r1157515120 
o|substituted constant variable: r1174215129 
o|substituted constant variable: r1182215135 
o|substituted constant variable: r1181015136 
o|substituted constant variable: r1183815138 
o|substituted constant variable: r1186215140 
o|substituted constant variable: r1259115163 
o|substituted constant variable: r1280815171 
o|substituted constant variable: r1318115189 
o|substituted constant variable: r1323315191 
o|inlining procedure: k13448 
o|substituted constant variable: prop2824 
o|substituted constant variable: r1352515203 
o|substituted constant variable: r1352515203 
o|substituted constant variable: prop2795 
o|substituted constant variable: r1367715212 
o|substituted constant variable: r1372615213 
o|substituted constant variable: r1372615213 
o|substituted constant variable: r1387415231 
o|substituted constant variable: r1386215232 
o|substituted constant variable: r1399915244 
o|substituted constant variable: r1398715245 
o|substituted constant variable: r1423515258 
o|substituted constant variable: r1437315268 
o|substituted constant variable: r1453515277 
o|substituted constant variable: r1464215281 
o|simplifications: ((let . 3)) 
o|replaced variables: 198 
o|removed binding forms: 2079 
o|inlining procedure: k5804 
o|contracted procedure: k5849 
o|substituted constant variable: prop95415299 
o|substituted constant variable: prop95415305 
o|contracted procedure: k6344 
o|contracted procedure: k6347 
o|contracted procedure: k6478 
o|contracted procedure: k6543 
o|inlining procedure: k6948 
o|inlining procedure: k6948 
o|inlining procedure: k7284 
o|inlining procedure: k7284 
o|contracted procedure: k8149 
o|contracted procedure: k8515 
o|propagated global variable: r928214964 ##sys#current-source-filename 
o|inlining procedure: k9306 
o|inlining procedure: k9306 
o|inlining procedure: k9523 
o|contracted procedure: k10116 
o|contracted procedure: k10128 
o|contracted procedure: k10149 
o|substituted constant variable: r1014715436 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|substituted constant variable: r1014715441 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|substituted constant variable: r1014715450 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|substituted constant variable: r1014715455 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|substituted constant variable: r1014715460 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|substituted constant variable: r1014715465 
o|removed call to pure procedure with unused result: "(expand.scm:974) chicken.base#void" 
o|contracted procedure: k10359 
o|contracted procedure: k10449 
o|contracted procedure: k10464 
o|contracted procedure: k10476 
o|contracted procedure: k10492 
o|contracted procedure: k10501 
o|inlining procedure: k11729 
o|inlining procedure: k11729 
o|inlining procedure: k12435 
o|inlining procedure: k14659 
o|replaced variables: 8 
o|removed binding forms: 281 
o|contracted procedure: k5833 
o|contracted procedure: k5841 
o|contracted procedure: k5846 
o|contracted procedure: k5889 
o|contracted procedure: k5894 
o|contracted procedure: k6009 
o|inlining procedure: k6475 
o|substituted constant variable: r763815353 
o|contracted procedure: k1014915440 
o|contracted procedure: k1014915445 
o|contracted procedure: k1014915454 
o|contracted procedure: k1014915459 
o|contracted procedure: k10250 
o|contracted procedure: k10258 
o|contracted procedure: k1014915464 
o|contracted procedure: k1014915469 
o|inlining procedure: "(expand.scm:961) lookup22148" 
o|inlining procedure: "(expand.scm:958) lookup22148" 
o|contracted procedure: k10484 
o|substituted constant variable: r1173015626 
o|substituted constant variable: r1173015627 
o|contracted procedure: k13439 
o|contracted procedure: k13500 
o|substituted constant variable: r1466015653 
o|replaced variables: 3 
o|removed binding forms: 58 
o|removed conditional forms: 3 
o|inlining procedure: k5836 
o|inlining procedure: k5836 
o|removed side-effect free assignment to unused variable: lookup22148 
o|replaced variables: 15 
o|removed binding forms: 17 
o|inlining procedure: k10332 
o|inlining procedure: k10338 
o|replaced variables: 4 
o|removed binding forms: 12 
o|removed binding forms: 4 
o|simplifications: ((let . 90) (if . 56) (##core#call . 1140)) 
o|  call simplifications:
o|    scheme#cdddr
o|    scheme#cddddr
o|    scheme#number?
o|    scheme#eof-object?
o|    scheme#cadddr	2
o|    chicken.fixnum#fx-	2
o|    scheme#>=
o|    scheme#+	3
o|    scheme#=
o|    scheme#<=
o|    scheme#boolean?
o|    scheme#char?	2
o|    scheme#>	2
o|    scheme#-	3
o|    scheme#cdar	2
o|    ##sys#immediate?
o|    scheme#vector-ref	5
o|    chicken.fixnum#fx<	2
o|    scheme#set-cdr!
o|    chicken.fixnum#fx=	7
o|    scheme#apply
o|    scheme#memq	5
o|    scheme#member
o|    scheme#caddr	16
o|    scheme#length	13
o|    chicken.fixnum#fx<=	2
o|    chicken.fixnum#fx>	4
o|    scheme#cddr	10
o|    ##sys#list	179
o|    ##sys#cons	86
o|    scheme#list?	7
o|    scheme#cadr	37
o|    scheme#values	11
o|    ##sys#call-with-values	3
o|    ##sys#apply	2
o|    scheme#memv
o|    scheme#equal?	2
o|    scheme#string?	3
o|    ##sys#make-structure	2
o|    scheme#caar	6
o|    scheme#eq?	78
o|    scheme#list	16
o|    scheme#set-car!	2
o|    ##sys#structure?	2
o|    scheme#null?	49
o|    scheme#car	76
o|    ##sys#check-list	16
o|    scheme#assq	13
o|    scheme#symbol?	50
o|    scheme#vector?	13
o|    ##sys#size	4
o|    chicken.fixnum#fx>=	5
o|    ##sys#slot	79
o|    chicken.fixnum#fx+	4
o|    scheme#cons	91
o|    ##sys#setslot	22
o|    scheme#not	43
o|    scheme#pair?	94
o|    scheme#cdr	52
o|contracted procedure: k5819 
o|contracted procedure: k5828 
o|contracted procedure: k5866 
o|contracted procedure: k5884 
o|contracted procedure: k5903 
o|contracted procedure: k5909 
o|contracted procedure: k5915 
o|contracted procedure: k5918 
o|contracted procedure: k5946 
o|contracted procedure: k5922 
o|contracted procedure: k5925 
o|contracted procedure: k5928 
o|contracted procedure: k5952 
o|contracted procedure: k5955 
o|contracted procedure: k5996 
o|contracted procedure: k5962 
o|contracted procedure: k5974 
o|contracted procedure: k5977 
o|contracted procedure: k5984 
o|contracted procedure: k5992 
o|contracted procedure: k6021 
o|contracted procedure: k6024 
o|contracted procedure: k6034 
o|contracted procedure: k6087 
o|contracted procedure: k6051 
o|contracted procedure: k6077 
o|contracted procedure: k6081 
o|contracted procedure: k6073 
o|contracted procedure: k6054 
o|contracted procedure: k6057 
o|contracted procedure: k6065 
o|contracted procedure: k6069 
o|contracted procedure: k6124 
o|contracted procedure: k6099 
o|contracted procedure: k6117 
o|contracted procedure: k6121 
o|contracted procedure: k6102 
o|contracted procedure: k6109 
o|contracted procedure: k6113 
o|contracted procedure: k6130 
o|contracted procedure: k6133 
o|contracted procedure: k6136 
o|contracted procedure: k6148 
o|contracted procedure: k6151 
o|contracted procedure: k6154 
o|contracted procedure: k6162 
o|contracted procedure: k6170 
o|contracted procedure: k6208 
o|contracted procedure: k6193 
o|contracted procedure: k6199 
o|contracted procedure: k6231 
o|contracted procedure: k6234 
o|contracted procedure: k6242 
o|contracted procedure: k6253 
o|contracted procedure: k6249 
o|contracted procedure: k6265 
o|contracted procedure: k6284 
o|contracted procedure: k6313 
o|contracted procedure: k6335 
o|contracted procedure: k6319 
o|contracted procedure: k6385 
o|contracted procedure: k6375 
o|contracted procedure: k6393 
o|contracted procedure: k6402 
o|contracted procedure: k6405 
o|contracted procedure: k6419 
o|contracted procedure: k6429 
o|contracted procedure: k6433 
o|contracted procedure: k6439 
o|contracted procedure: k6445 
o|contracted procedure: k6453 
o|contracted procedure: k6460 
o|contracted procedure: k6498 
o|contracted procedure: k6484 
o|contracted procedure: k6578 
o|contracted procedure: k6549 
o|contracted procedure: k6558 
o|contracted procedure: k6569 
o|contracted procedure: k6590 
o|contracted procedure: k6598 
o|contracted procedure: k6604 
o|contracted procedure: k6622 
o|contracted procedure: k6628 
o|contracted procedure: k6634 
o|contracted procedure: k6640 
o|contracted procedure: k6716 
o|contracted procedure: k6724 
o|contracted procedure: k6731 
o|contracted procedure: k6712 
o|contracted procedure: k6708 
o|contracted procedure: k6704 
o|contracted procedure: k6700 
o|contracted procedure: k6655 
o|contracted procedure: k6659 
o|contracted procedure: k6651 
o|contracted procedure: k6647 
o|contracted procedure: k6671 
o|contracted procedure: k6693 
o|contracted procedure: k6689 
o|contracted procedure: k6674 
o|contracted procedure: k6677 
o|contracted procedure: k6685 
o|contracted procedure: k6740 
o|contracted procedure: k6762 
o|contracted procedure: k6758 
o|contracted procedure: k6743 
o|contracted procedure: k6746 
o|contracted procedure: k6754 
o|contracted procedure: k6785 
o|contracted procedure: k6801 
o|contracted procedure: k6815 
o|contracted procedure: k6823 
o|contracted procedure: k6833 
o|contracted procedure: k6909 
o|contracted procedure: k6864 
o|contracted procedure: k6903 
o|contracted procedure: k6867 
o|contracted procedure: k6897 
o|contracted procedure: k6870 
o|contracted procedure: k6915 
o|contracted procedure: k6936 
o|contracted procedure: k6939 
o|contracted procedure: k6945 
o|contracted procedure: k6956 
o|contracted procedure: k6948 
o|contracted procedure: k7008 
o|contracted procedure: k7025 
o|contracted procedure: k7054 
o|contracted procedure: k7058 
o|contracted procedure: k7050 
o|contracted procedure: k7046 
o|contracted procedure: k7042 
o|contracted procedure: k7038 
o|inlining procedure: k7022 
o|contracted procedure: k7121 
o|contracted procedure: k7068 
o|contracted procedure: k7083 
o|contracted procedure: k7079 
o|contracted procedure: k7075 
o|inlining procedure: k7022 
o|contracted procedure: k7102 
o|contracted procedure: k7098 
o|contracted procedure: k7094 
o|inlining procedure: k7022 
o|inlining procedure: k7114 
o|inlining procedure: k7114 
o|contracted procedure: k7127 
o|contracted procedure: k7133 
o|contracted procedure: k7140 
o|contracted procedure: k7143 
o|contracted procedure: k7158 
o|contracted procedure: k7163 
o|contracted procedure: k7178 
o|contracted procedure: k7174 
o|contracted procedure: k7170 
o|contracted procedure: k7186 
o|contracted procedure: k7193 
o|contracted procedure: k7204 
o|contracted procedure: k7200 
o|contracted procedure: k7190 
o|contracted procedure: k6987 
o|contracted procedure: k7154 
o|contracted procedure: k7150 
o|contracted procedure: k7231 
o|contracted procedure: k7234 
o|contracted procedure: k7237 
o|contracted procedure: k7245 
o|contracted procedure: k7253 
o|contracted procedure: k7272 
o|contracted procedure: k7278 
o|contracted procedure: k7571 
o|contracted procedure: k7295 
o|contracted procedure: k7301 
o|contracted procedure: k7307 
o|contracted procedure: k7314 
o|contracted procedure: k7323 
o|contracted procedure: k7339 
o|contracted procedure: k7345 
o|contracted procedure: k7376 
o|contracted procedure: k7351 
o|contracted procedure: k7358 
o|contracted procedure: k7366 
o|contracted procedure: k7370 
o|contracted procedure: k7390 
o|contracted procedure: k7399 
o|contracted procedure: k7408 
o|contracted procedure: k7418 
o|contracted procedure: k7424 
o|contracted procedure: k7431 
o|contracted procedure: k7437 
o|contracted procedure: k7448 
o|contracted procedure: k7444 
o|contracted procedure: k7454 
o|contracted procedure: k7468 
o|contracted procedure: k7464 
o|contracted procedure: k7486 
o|contracted procedure: k7495 
o|contracted procedure: k7502 
o|contracted procedure: k7508 
o|contracted procedure: k7518 
o|contracted procedure: k7530 
o|contracted procedure: k7536 
o|contracted procedure: k7543 
o|contracted procedure: k7554 
o|contracted procedure: k7567 
o|contracted procedure: k7560 
o|contracted procedure: k7599 
o|contracted procedure: k7607 
o|contracted procedure: k7603 
o|contracted procedure: k7619 
o|contracted procedure: k7627 
o|contracted procedure: k7630 
o|contracted procedure: k7640 
o|contracted procedure: k7646 
o|contracted procedure: k7653 
o|contracted procedure: k7637 
o|contracted procedure: k7698 
o|contracted procedure: k7662 
o|contracted procedure: k7688 
o|contracted procedure: k7692 
o|contracted procedure: k7684 
o|contracted procedure: k7665 
o|contracted procedure: k7668 
o|contracted procedure: k7676 
o|contracted procedure: k7680 
o|contracted procedure: k7704 
o|contracted procedure: k7710 
o|contracted procedure: k7713 
o|contracted procedure: k7716 
o|contracted procedure: k7728 
o|contracted procedure: k7731 
o|contracted procedure: k7734 
o|contracted procedure: k7742 
o|contracted procedure: k7750 
o|contracted procedure: k8809 
o|contracted procedure: k7766 
o|contracted procedure: k8803 
o|contracted procedure: k7769 
o|contracted procedure: k8797 
o|contracted procedure: k7772 
o|contracted procedure: k7814 
o|contracted procedure: k7787 
o|contracted procedure: k7793 
o|contracted procedure: k7806 
o|contracted procedure: k7887 
o|contracted procedure: k7844 
o|contracted procedure: k7850 
o|contracted procedure: k7859 
o|contracted procedure: k7872 
o|contracted procedure: k7865 
o|contracted procedure: k7879 
o|contracted procedure: k8344 
o|contracted procedure: k7919 
o|contracted procedure: k8143 
o|contracted procedure: k7931 
o|contracted procedure: k7947 
o|contracted procedure: k7967 
o|contracted procedure: k7982 
o|contracted procedure: k7990 
o|contracted procedure: k7999 
o|contracted procedure: k8029 
o|inlining procedure: k8020 
o|contracted procedure: k8043 
o|contracted procedure: k8039 
o|inlining procedure: k8020 
o|contracted procedure: k8050 
o|inlining procedure: k8020 
o|contracted procedure: k8060 
o|contracted procedure: k8064 
o|contracted procedure: k8071 
o|contracted procedure: k8074 
o|contracted procedure: k8080 
o|contracted procedure: k8102 
o|contracted procedure: k8105 
o|contracted procedure: k8112 
o|contracted procedure: k8157 
o|contracted procedure: k8171 
o|contracted procedure: k8153 
o|contracted procedure: k8182 
o|contracted procedure: k8221 
o|contracted procedure: k8224 
o|contracted procedure: k8232 
o|contracted procedure: k8236 
o|contracted procedure: k8240 
o|contracted procedure: k8248 
o|contracted procedure: k8252 
o|contracted procedure: k8256 
o|contracted procedure: k8197 
o|contracted procedure: k8262 
o|contracted procedure: k8268 
o|contracted procedure: k8280 
o|contracted procedure: k8302 
o|contracted procedure: k8298 
o|contracted procedure: k8283 
o|contracted procedure: k8286 
o|contracted procedure: k8294 
o|contracted procedure: k8314 
o|contracted procedure: k8321 
o|contracted procedure: k8341 
o|contracted procedure: k8378 
o|contracted procedure: k8374 
o|contracted procedure: k8370 
o|contracted procedure: k8393 
o|contracted procedure: k8415 
o|contracted procedure: k8411 
o|contracted procedure: k8396 
o|contracted procedure: k8399 
o|contracted procedure: k8407 
o|contracted procedure: k8503 
o|contracted procedure: k8424 
o|contracted procedure: k8446 
o|contracted procedure: k8456 
o|contracted procedure: k8460 
o|contracted procedure: k8449 
o|contracted procedure: k8499 
o|contracted procedure: k8466 
o|contracted procedure: k8493 
o|contracted procedure: k8472 
o|contracted procedure: k8488 
o|contracted procedure: k8478 
o|contracted procedure: k8791 
o|contracted procedure: k8521 
o|contracted procedure: k8527 
o|contracted procedure: k8786 
o|contracted procedure: k8531 
o|contracted procedure: k8777 
o|contracted procedure: k8540 
o|contracted procedure: k8561 
o|contracted procedure: k8680 
o|contracted procedure: k8567 
o|contracted procedure: k8606 
o|contracted procedure: k8580 
o|contracted procedure: k8588 
o|contracted procedure: k8602 
o|contracted procedure: k8595 
o|contracted procedure: k8592 
o|contracted procedure: k8609 
o|contracted procedure: k8676 
o|contracted procedure: k8620 
o|contracted procedure: k8634 
o|contracted procedure: k8670 
o|contracted procedure: k8644 
o|contracted procedure: k8666 
o|contracted procedure: k8660 
o|contracted procedure: k8656 
o|contracted procedure: k8648 
o|contracted procedure: k8652 
o|contracted procedure: k8724 
o|contracted procedure: k8708 
o|contracted procedure: k8720 
o|contracted procedure: k8712 
o|contracted procedure: k8716 
o|contracted procedure: k8741 
o|contracted procedure: k8773 
o|contracted procedure: k8747 
o|contracted procedure: k8759 
o|contracted procedure: k8769 
o|contracted procedure: k8783 
o|contracted procedure: k8815 
o|contracted procedure: k8897 
o|contracted procedure: k8833 
o|contracted procedure: k8836 
o|contracted procedure: k8848 
o|contracted procedure: k8857 
o|contracted procedure: k8865 
o|contracted procedure: k8861 
o|contracted procedure: k8874 
o|contracted procedure: k8893 
o|contracted procedure: k8949 
o|contracted procedure: k8915 
o|contracted procedure: k8924 
o|contracted procedure: k8943 
o|contracted procedure: k8939 
o|contracted procedure: k8935 
o|contracted procedure: k9032 
o|contracted procedure: k9063 
o|contracted procedure: k9089 
o|contracted procedure: k9101 
o|contracted procedure: k9181 
o|contracted procedure: k9125 
o|contracted procedure: k9140 
o|contracted procedure: k9160 
o|contracted procedure: k9177 
o|contracted procedure: k8985 
o|contracted procedure: k8994 
o|contracted procedure: k9022 
o|contracted procedure: k9000 
o|contracted procedure: k9190 
o|contracted procedure: k9211 
o|contracted procedure: k9246 
o|contracted procedure: k9217 
o|contracted procedure: k9227 
o|contracted procedure: k9261 
o|contracted procedure: k9273 
o|contracted procedure: k9287 
o|contracted procedure: k9290 
o|contracted procedure: k9297 
o|contracted procedure: k9319 
o|contracted procedure: k9303 
o|contracted procedure: k9334 
o|contracted procedure: k9341 
o|contracted procedure: k9367 
o|contracted procedure: k9385 
o|contracted procedure: k9389 
o|contracted procedure: k9402 
o|contracted procedure: k9430 
o|contracted procedure: k9433 
o|contracted procedure: k9445 
o|contracted procedure: k9467 
o|contracted procedure: k9463 
o|contracted procedure: k9448 
o|contracted procedure: k9451 
o|contracted procedure: k9459 
o|contracted procedure: k9488 
o|contracted procedure: k9549 
o|contracted procedure: k9504 
o|contracted procedure: k9545 
o|contracted procedure: k9513 
o|contracted procedure: k9520 
o|contracted procedure: k9531 
o|contracted procedure: k5112 
o|contracted procedure: k9538 
o|contracted procedure: k9993 
o|contracted procedure: k9558 
o|contracted procedure: k9987 
o|contracted procedure: k9561 
o|contracted procedure: k9972 
o|contracted procedure: k9567 
o|contracted procedure: k9624 
o|contracted procedure: k9630 
o|contracted procedure: k9639 
o|contracted procedure: k9646 
o|contracted procedure: k9669 
o|contracted procedure: k9678 
o|contracted procedure: k9698 
o|contracted procedure: k9701 
o|contracted procedure: k9704 
o|contracted procedure: k9786 
o|contracted procedure: k9707 
o|contracted procedure: k9722 
o|contracted procedure: k9728 
o|contracted procedure: k9741 
o|contracted procedure: k9745 
o|contracted procedure: k9748 
o|contracted procedure: k9771 
o|contracted procedure: k9757 
o|contracted procedure: k9767 
o|contracted procedure: k9774 
o|contracted procedure: k9780 
o|contracted procedure: k9795 
o|contracted procedure: k9808 
o|contracted procedure: k9801 
o|contracted procedure: k9814 
o|contracted procedure: k9820 
o|contracted procedure: k9826 
o|contracted procedure: k9835 
o|contracted procedure: k9844 
o|contracted procedure: k9853 
o|contracted procedure: k9862 
o|contracted procedure: k9871 
o|contracted procedure: k9880 
o|contracted procedure: k9902 
o|contracted procedure: k9905 
o|contracted procedure: k9968 
o|contracted procedure: k9930 
o|contracted procedure: k9964 
o|contracted procedure: k9939 
o|contracted procedure: k9956 
o|contracted procedure: k9960 
o|contracted procedure: k9978 
o|contracted procedure: k10011 
o|contracted procedure: k10017 
o|contracted procedure: k10032 
o|contracted procedure: k10041 
o|contracted procedure: k10048 
o|contracted procedure: k10051 
o|contracted procedure: k10063 
o|contracted procedure: k10070 
o|contracted procedure: k10088 
o|contracted procedure: k10140 
o|contracted procedure: k10105 
o|contracted procedure: k10108 
o|contracted procedure: k10136 
o|contracted procedure: k10132 
o|contracted procedure: k10152 
o|contracted procedure: k10158 
o|contracted procedure: k10181 
o|contracted procedure: k10187 
o|contracted procedure: k10190 
o|contracted procedure: k10237 
o|contracted procedure: k10196 
o|contracted procedure: k10208 
o|contracted procedure: k10211 
o|contracted procedure: k10218 
o|contracted procedure: k10226 
o|contracted procedure: k10230 
o|contracted procedure: k10347 
o|contracted procedure: k10245 
o|contracted procedure: k10267 
o|contracted procedure: k10273 
o|contracted procedure: k10279 
o|contracted procedure: k10291 
o|contracted procedure: k10304 
o|contracted procedure: k10307 
o|contracted procedure: k10319 
o|contracted procedure: k10368 
o|contracted procedure: k10384 
o|contracted procedure: k10374 
o|contracted procedure: k10393 
o|contracted procedure: k10400 
o|contracted procedure: k10418 
o|contracted procedure: k10505 
o|contracted procedure: k10435 
o|contracted procedure: k10461 
o|contracted procedure: k10473 
o|contracted procedure: k10670 
o|contracted procedure: k10679 
o|contracted procedure: k10686 
o|contracted procedure: k10694 
o|contracted procedure: k10706 
o|contracted procedure: k10715 
o|contracted procedure: k10722 
o|contracted procedure: k10726 
o|contracted procedure: k11947 
o|contracted procedure: k10851 
o|contracted procedure: k10931 
o|contracted procedure: k10927 
o|contracted procedure: k10859 
o|contracted procedure: k10863 
o|contracted procedure: k10855 
o|contracted procedure: k10847 
o|contracted procedure: k10871 
o|contracted procedure: k10874 
o|contracted procedure: k10889 
o|contracted procedure: k10885 
o|contracted procedure: k10881 
o|contracted procedure: k10898 
o|contracted procedure: k10901 
o|contracted procedure: k10904 
o|contracted procedure: k10912 
o|contracted procedure: k10920 
o|contracted procedure: k10943 
o|contracted procedure: k10946 
o|contracted procedure: k10953 
o|contracted procedure: k10957 
o|contracted procedure: k10982 
o|contracted procedure: k10988 
o|contracted procedure: k10995 
o|contracted procedure: k11006 
o|contracted procedure: k11012 
o|contracted procedure: k11027 
o|contracted procedure: k11023 
o|contracted procedure: k11019 
o|contracted procedure: k11042 
o|contracted procedure: k11093 
o|contracted procedure: k11053 
o|contracted procedure: k11065 
o|contracted procedure: k11061 
o|contracted procedure: k11057 
o|contracted procedure: k11049 
o|contracted procedure: k11081 
o|contracted procedure: k11087 
o|contracted procedure: k11099 
o|contracted procedure: k11138 
o|contracted procedure: k11110 
o|contracted procedure: k11122 
o|contracted procedure: k11118 
o|contracted procedure: k11114 
o|contracted procedure: k11106 
o|contracted procedure: k11130 
o|contracted procedure: k11144 
o|contracted procedure: k11158 
o|contracted procedure: k11154 
o|contracted procedure: k11169 
o|contracted procedure: k11165 
o|contracted procedure: k11172 
o|contracted procedure: k11195 
o|contracted procedure: k11297 
o|contracted procedure: k11293 
o|contracted procedure: k11203 
o|contracted procedure: k11289 
o|contracted procedure: k11285 
o|contracted procedure: k11211 
o|contracted procedure: k11277 
o|contracted procedure: k11281 
o|contracted procedure: k11219 
o|contracted procedure: k11270 
o|contracted procedure: k11259 
o|contracted procedure: k11227 
o|contracted procedure: k11235 
o|contracted procedure: k11231 
o|contracted procedure: k11223 
o|contracted procedure: k11215 
o|contracted procedure: k11207 
o|contracted procedure: k11199 
o|contracted procedure: k11191 
o|contracted procedure: k11251 
o|contracted procedure: k11255 
o|contracted procedure: k11247 
o|contracted procedure: k11243 
o|contracted procedure: k11301 
o|contracted procedure: k11305 
o|contracted procedure: k11314 
o|contracted procedure: k11320 
o|contracted procedure: k11327 
o|contracted procedure: k11399 
o|contracted procedure: k11340 
o|contracted procedure: k11391 
o|contracted procedure: k11343 
o|contracted procedure: k11358 
o|contracted procedure: k11362 
o|contracted procedure: k11377 
o|contracted procedure: k11388 
o|contracted procedure: k11384 
o|contracted procedure: k11374 
o|contracted procedure: k11405 
o|contracted procedure: k11422 
o|contracted procedure: k11428 
o|contracted procedure: k11434 
o|contracted procedure: k11445 
o|contracted procedure: k11454 
o|contracted procedure: k11457 
o|contracted procedure: k11473 
o|contracted procedure: k11466 
o|contracted procedure: k11480 
o|contracted procedure: k11492 
o|contracted procedure: k11501 
o|contracted procedure: k11519 
o|contracted procedure: k11543 
o|substituted constant variable: g16332 
o|contracted procedure: k11550 
o|contracted procedure: k11554 
o|contracted procedure: k11568 
o|contracted procedure: k11564 
o|contracted procedure: k11571 
o|contracted procedure: k11577 
o|contracted procedure: k11583 
o|contracted procedure: k11596 
o|contracted procedure: k11602 
o|contracted procedure: k11623 
o|contracted procedure: k11646 
o|contracted procedure: k11652 
o|contracted procedure: k11659 
o|contracted procedure: k11672 
o|contracted procedure: k11676 
o|contracted procedure: k11684 
o|contracted procedure: k11690 
o|contracted procedure: k11707 
o|contracted procedure: k11723 
o|contracted procedure: k11752 
o|contracted procedure: k11735 
o|contracted procedure: k11738 
o|contracted procedure: k11748 
o|contracted procedure: k11729 
o|contracted procedure: k11765 
o|contracted procedure: k11773 
o|contracted procedure: k11779 
o|contracted procedure: k11796 
o|contracted procedure: k11831 
o|contracted procedure: k11824 
o|contracted procedure: k11840 
o|contracted procedure: k11846 
o|contracted procedure: k11853 
o|contracted procedure: k11875 
o|contracted procedure: k11885 
o|contracted procedure: k11901 
o|contracted procedure: k11904 
o|contracted procedure: k11958 
o|contracted procedure: k11966 
o|contracted procedure: k11970 
o|contracted procedure: k12003 
o|contracted procedure: k11999 
o|contracted procedure: k11995 
o|contracted procedure: k11991 
o|contracted procedure: k12038 
o|contracted procedure: k12192 
o|contracted procedure: k12055 
o|contracted procedure: k12061 
o|contracted procedure: k12074 
o|contracted procedure: k12087 
o|contracted procedure: k12095 
o|contracted procedure: k12108 
o|contracted procedure: k12116 
o|contracted procedure: k12128 
o|contracted procedure: k12138 
o|contracted procedure: k12157 
o|contracted procedure: k12149 
o|contracted procedure: k12165 
o|contracted procedure: k12169 
o|contracted procedure: k12183 
o|contracted procedure: k12218 
o|contracted procedure: k12214 
o|contracted procedure: k12210 
o|contracted procedure: k12232 
o|contracted procedure: k12265 
o|contracted procedure: k12238 
o|contracted procedure: k12261 
o|contracted procedure: k12253 
o|contracted procedure: k12257 
o|contracted procedure: k12249 
o|contracted procedure: k12245 
o|contracted procedure: k12283 
o|contracted procedure: k12296 
o|contracted procedure: k12309 
o|contracted procedure: k12312 
o|contracted procedure: k12325 
o|contracted procedure: k12343 
o|contracted procedure: k12354 
o|contracted procedure: k12455 
o|contracted procedure: k12359 
o|contracted procedure: k12379 
o|contracted procedure: k12375 
o|contracted procedure: k12371 
o|contracted procedure: k12363 
o|contracted procedure: k12350 
o|contracted procedure: k12417 
o|contracted procedure: k12423 
o|contracted procedure: k12431 
o|contracted procedure: k12439 
o|contracted procedure: k12405 
o|contracted procedure: k12401 
o|contracted procedure: k12387 
o|contracted procedure: k12395 
o|contracted procedure: k12435 
o|contracted procedure: k12445 
o|contracted procedure: k12452 
o|contracted procedure: k12467 
o|contracted procedure: k12489 
o|contracted procedure: k12334 
o|contracted procedure: k12338 
o|contracted procedure: k12485 
o|contracted procedure: k12470 
o|contracted procedure: k12473 
o|contracted procedure: k12481 
o|contracted procedure: k12505 
o|contracted procedure: k12519 
o|contracted procedure: k12526 
o|contracted procedure: k12543 
o|contracted procedure: k12533 
o|contracted procedure: k12556 
o|contracted procedure: k12779 
o|contracted procedure: k12580 
o|contracted procedure: k12775 
o|contracted procedure: k12593 
o|contracted procedure: k12596 
o|contracted procedure: k12628 
o|contracted procedure: k12644 
o|contracted procedure: k12651 
o|contracted procedure: k12665 
o|contracted procedure: k12654 
o|contracted procedure: k12661 
o|contracted procedure: k12717 
o|contracted procedure: k12726 
o|contracted procedure: k12730 
o|contracted procedure: k12674 
o|contracted procedure: k12692 
o|contracted procedure: k12699 
o|contracted procedure: k12713 
o|contracted procedure: k12702 
o|contracted procedure: k12709 
o|contracted procedure: k12742 
o|contracted procedure: k12745 
o|contracted procedure: k12748 
o|contracted procedure: k12756 
o|contracted procedure: k12764 
o|contracted procedure: k12771 
o|contracted procedure: k12789 
o|contracted procedure: k13167 
o|contracted procedure: k12810 
o|contracted procedure: k12813 
o|contracted procedure: k12874 
o|contracted procedure: k12903 
o|contracted procedure: k12882 
o|contracted procedure: k12917 
o|contracted procedure: k12906 
o|contracted procedure: k12913 
o|contracted procedure: k12929 
o|contracted procedure: k12978 
o|contracted procedure: k12974 
o|contracted procedure: k12954 
o|contracted procedure: k12970 
o|contracted procedure: k12962 
o|contracted procedure: k12958 
o|contracted procedure: k13026 
o|contracted procedure: k12994 
o|contracted procedure: k13022 
o|contracted procedure: k13006 
o|contracted procedure: k13018 
o|contracted procedure: k13010 
o|contracted procedure: k13002 
o|contracted procedure: k12998 
o|contracted procedure: k13033 
o|contracted procedure: k13037 
o|contracted procedure: k13046 
o|contracted procedure: k13053 
o|contracted procedure: k13069 
o|contracted procedure: k13058 
o|contracted procedure: k13065 
o|contracted procedure: k13074 
o|contracted procedure: k13080 
o|contracted procedure: k13086 
o|contracted procedure: k13092 
o|contracted procedure: k13098 
o|contracted procedure: k13115 
o|contracted procedure: k13130 
o|contracted procedure: k13141 
o|contracted procedure: k13163 
o|contracted procedure: k13177 
o|contracted procedure: k13183 
o|contracted procedure: k13186 
o|contracted procedure: k13193 
o|contracted procedure: k13219 
o|contracted procedure: k13203 
o|contracted procedure: k13211 
o|contracted procedure: k13207 
o|contracted procedure: k13229 
o|contracted procedure: k13235 
o|contracted procedure: k13238 
o|contracted procedure: k13245 
o|contracted procedure: k13252 
o|contracted procedure: k13269 
o|contracted procedure: k13272 
o|contracted procedure: k13278 
o|contracted procedure: k13285 
o|contracted procedure: k13295 
o|contracted procedure: k13322 
o|contracted procedure: k13344 
o|contracted procedure: k13366 
o|contracted procedure: k13394 
o|contracted procedure: k13404 
o|contracted procedure: k13418 
o|contracted procedure: k13407 
o|contracted procedure: k13414 
o|contracted procedure: k13431 
o|contracted procedure: k13434 
o|contracted procedure: k13442 
o|contracted procedure: k13484 
o|contracted procedure: k13592 
o|contracted procedure: k13492 
o|contracted procedure: k13503 
o|contracted procedure: k13516 
o|contracted procedure: k13527 
o|inlining procedure: k13520 
o|inlining procedure: k13520 
o|contracted procedure: k13588 
o|contracted procedure: k13548 
o|contracted procedure: k13572 
o|contracted procedure: k13582 
o|contracted procedure: k13578 
o|contracted procedure: k13568 
o|contracted procedure: k13609 
o|contracted procedure: k13626 
o|contracted procedure: k13643 
o|contracted procedure: k13660 
o|contracted procedure: k13710 
o|contracted procedure: k13714 
o|contracted procedure: k13706 
o|contracted procedure: k13728 
o|contracted procedure: k13734 
o|inlining procedure: k13725 
o|contracted procedure: k13743 
o|contracted procedure: k13753 
o|contracted procedure: k13757 
o|contracted procedure: k13760 
o|contracted procedure: k13767 
o|contracted procedure: k13783 
o|contracted procedure: k13786 
o|contracted procedure: k13790 
o|contracted procedure: k13815 
o|contracted procedure: k13835 
o|contracted procedure: k13840 
o|contracted procedure: k13852 
o|contracted procedure: k13864 
o|contracted procedure: k13870 
o|contracted procedure: k13887 
o|contracted procedure: k13876 
o|contracted procedure: k13883 
o|contracted procedure: k13894 
o|contracted procedure: k13897 
o|contracted procedure: k13819 
o|contracted procedure: k13823 
o|contracted procedure: k13827 
o|contracted procedure: k13796 
o|contracted procedure: k13807 
o|contracted procedure: k13811 
o|contracted procedure: k13909 
o|contracted procedure: k13912 
o|contracted procedure: k13915 
o|contracted procedure: k13923 
o|contracted procedure: k13931 
o|contracted procedure: k13958 
o|contracted procedure: k14021 
o|contracted procedure: k14042 
o|contracted procedure: k14045 
o|contracted procedure: k14048 
o|contracted procedure: k14056 
o|contracted procedure: k14064 
o|contracted procedure: k13973 
o|contracted procedure: k13977 
o|contracted procedure: k13983 
o|contracted procedure: k13989 
o|contracted procedure: k13995 
o|contracted procedure: k14011 
o|contracted procedure: k14001 
o|contracted procedure: k14071 
o|contracted procedure: k14098 
o|contracted procedure: k14111 
o|contracted procedure: k14126 
o|contracted procedure: k14132 
o|contracted procedure: k14165 
o|contracted procedure: k14161 
o|contracted procedure: k14157 
o|contracted procedure: k14145 
o|contracted procedure: k14153 
o|contracted procedure: k14149 
o|contracted procedure: k14189 
o|contracted procedure: k14199 
o|contracted procedure: k14247 
o|contracted procedure: k14207 
o|contracted procedure: k14211 
o|contracted procedure: k14228 
o|contracted procedure: k14224 
o|contracted procedure: k14214 
o|contracted procedure: k14231 
o|contracted procedure: k14237 
o|contracted procedure: k14255 
o|contracted procedure: k14258 
o|contracted procedure: k14269 
o|contracted procedure: k14273 
o|contracted procedure: k14283 
o|contracted procedure: k14293 
o|contracted procedure: k14302 
o|contracted procedure: k14435 
o|contracted procedure: k14315 
o|contracted procedure: k14321 
o|contracted procedure: k14331 
o|contracted procedure: k14334 
o|contracted procedure: k14343 
o|contracted procedure: k14356 
o|contracted procedure: k14369 
o|contracted procedure: k14405 
o|contracted procedure: k14375 
o|contracted procedure: k14381 
o|contracted procedure: k14394 
o|contracted procedure: k14411 
o|contracted procedure: k14422 
o|contracted procedure: k14447 
o|contracted procedure: k14454 
o|contracted procedure: k14462 
o|contracted procedure: k14474 
o|contracted procedure: k14496 
o|contracted procedure: k14492 
o|contracted procedure: k14477 
o|contracted procedure: k14480 
o|contracted procedure: k14488 
o|contracted procedure: k14566 
o|contracted procedure: k14505 
o|contracted procedure: k14511 
o|contracted procedure: k14562 
o|contracted procedure: k14518 
o|contracted procedure: k14524 
o|contracted procedure: k14530 
o|contracted procedure: k14537 
o|contracted procedure: k14583 
o|contracted procedure: k14601 
o|contracted procedure: k14593 
o|contracted procedure: k14615 
o|contracted procedure: k14644 
o|contracted procedure: k14650 
o|contracted procedure: k14659 
o|contracted procedure: k14672 
o|contracted procedure: k14675 
o|contracted procedure: k14687 
o|contracted procedure: k14690 
o|contracted procedure: k14693 
o|contracted procedure: k14701 
o|contracted procedure: k14709 
o|simplifications: ((if . 7) (let . 311)) 
o|replaced variables: 9 
o|removed binding forms: 965 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest895898 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest895898 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest10131015 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest10131015 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest10441046 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest10441046 0 
o|contracted procedure: k6378 
o|inlining procedure: k7182 
o|inlining procedure: k7182 
o|inlining procedure: k8437 
o|inlining procedure: k8584 
o|inlining procedure: k8584 
o|contracted procedure: k9255 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest19211922 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest19211922 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest20242028 0 
(o x)|known list op on rest arg sublist: ##core#rest-car rest20242028 0 
(o x)|known list op on rest arg sublist: ##core#rest-null? rest20242028 0 
(o x)|known list op on rest arg sublist: ##core#rest-cdr rest20242028 0 
o|inlining procedure: k9892 
o|inlining procedure: k11894 
o|contracted procedure: k13384 
o|inlining procedure: k13718 
o|inlining procedure: k13718 
o|inlining procedure: k13718 
o|inlining procedure: k14203 
o|inlining procedure: k14203 
o|removed binding forms: 17 
o|substituted constant variable: r989316575 
o|substituted constant variable: r989316575 
o|substituted constant variable: r1189516589 
o|removed binding forms: 5 
o|removed conditional forms: 1 
o|removed binding forms: 2 
o|direct leaf routine/allocation: chicken.syntax#lookup 0 
o|direct leaf routine/allocation: g10331034 0 
o|direct leaf routine/allocation: loop1263 0 
o|direct leaf routine/allocation: g18091810 0 
o|direct leaf routine/allocation: loop2054 0 
o|direct leaf routine/allocation: loop2071 0 
o|direct leaf routine/allocation: g22222223 0 
o|direct leaf routine/allocation: g22312232 0 
o|direct leaf routine/allocation: assq-reverse2149 0 
o|direct leaf routine/allocation: loop3286 0 
o|direct leaf routine/allocation: g30453054 15 
o|contracted procedure: "(expand.scm:100) k5825" 
o|contracted procedure: "(expand.scm:166) k6223" 
o|contracted procedure: "(expand.scm:178) k6262" 
o|contracted procedure: "(expand.scm:180) k6271" 
o|contracted procedure: "(expand.scm:262) k6601" 
o|contracted procedure: "(expand.scm:264) k6837" 
o|converted assignments to bindings: (loop1263) 
o|contracted procedure: "(expand.scm:467) k7778" 
o|contracted procedure: "(expand.scm:475) k7835" 
o|converted assignments to bindings: (loop2054) 
o|converted assignments to bindings: (loop2071) 
o|contracted procedure: "(expand.scm:899) k9892" 
o|contracted procedure: "(expand.scm:977) k10332" 
o|contracted procedure: "(expand.scm:977) k10338" 
o|contracted procedure: "(expand.scm:997) k10438" 
o|contracted procedure: "(expand.scm:998) k10441" 
o|converted assignments to bindings: (loop3286) 
o|contracted procedure: "(expand.scm:1579) k12760" 
o|simplifications: ((if . 1) (let . 4)) 
o|removed binding forms: 14 
o|customizable procedures: (g24302439 map-loop24242476 expand2527 map-loop25352553 test2498 err2497 k14120 k14217 k13966 map-loop26242646 g26892698 map-loop26832710 loop2780 expand2908 map-loop30393060 k12678 expand3008 expand3082 map-loop31043122 k12367 k12420 map-loop31383156 g32333234 g32263227 walk3170 walk13171 simplify3172 k11952 loop3547 k11557 k11510 doloop34963497 k11147 k10940 map-loop33623379 loop3275 chicken.syntax#make-er/ir-transformer mirror-rename2150 k10253 k10261 doloop21812182 inherit-pair-line-numbers2131 k9686 test2039 k9710 walk2081 doloop20962097 err2040 mapupdate1997 walk1998 loop2000 map-loop19671984 g19581959 g19421943 chicken.syntax#assq/drop-bwp! k9224 lp1893 loop1843 loop1856 loop1873 outstr1854 loop1820 mwalk1796 comp-def1512 k8534 loop21760 loop1743 loop1699 map-loop17121729 foldl16271631 map-loop16041643 k8218 map-loop16521679 loop21559 comp1511 loop1556 k7838 k7847 repeat1535 k7781 k7790 map-loop14201437 map-loop14491473 k7304 k7480 k7393 k7354 chicken.syntax#macro-alias k7317 loop1296 err1285 g13181327 map-loop13121340 k7019 k7031 loop1250 k6607 k6613 k6771 g12151216 loop1127 expand1072 map-loop11551173 map-loop11821199 call-handler1071 k6412 copy1090 loop1060 map-loop906923 for-each-loop932959 map-loop969990 doloop884885 walk854) 
o|calls to known targets: 372 
o|identified direct recursive calls: f_6046 1 
o|identified direct recursive calls: f_6094 1 
o|unused rest argument: rest895898 f_6000 
o|unused rest argument: rest10131015 f_6191 
o|unused rest argument: rest10441046 f_6257 
o|identified direct recursive calls: f_6308 1 
o|identified direct recursive calls: f_6666 1 
o|identified direct recursive calls: f_6735 1 
o|identified direct recursive calls: f_6931 3 
o|identified direct recursive calls: f_7003 2 
o|identified direct recursive calls: f_7657 1 
o|identified direct recursive calls: f_8275 1 
o|identified direct recursive calls: f_8388 1 
o|identified direct recursive calls: f_8361 1 
o|identified direct recursive calls: f_8828 1 
o|identified direct recursive calls: f_8910 1 
o|identified direct recursive calls: f_8989 1 
o|unused rest argument: rest19211922 f_9301 
o|identified direct recursive calls: f_9440 1 
o|identified direct recursive calls: f_9622 1 
o|identified direct recursive calls: f_9667 1 
o|identified direct recursive calls: f_9693 1 
o|identified direct recursive calls: f_10058 1 
o|identified direct recursive calls: f_10144 1 
o|identified direct recursive calls: f_10363 1 
o|identified direct recursive calls: f_10388 1 
o|identified direct recursive calls: f_10674 1 
o|identified direct recursive calls: f_10710 1 
o|identified direct recursive calls: f_11538 1 
o|identified direct recursive calls: f_12462 1 
o|identified direct recursive calls: f_12514 1 
o|identified direct recursive calls: f_12737 1 
o|identified direct recursive calls: f_14469 1 
o|fast box initializations: 72 
o|fast global references: 29 
o|fast global assignments: 7 
o|dropping unused closure argument: f_10000 
o|dropping unused closure argument: f_10009 
o|dropping unused closure argument: f_10363 
o|dropping unused closure argument: f_5794 
o|dropping unused closure argument: f_5811 
o|dropping unused closure argument: f_6931 
o|dropping unused closure argument: f_9200 
o|dropping unused closure argument: f_9622 
o|dropping unused closure argument: f_9667 
*/
/* end of file */
